/**
 * SlashGaming Diablo II Modding API
 * Copyright (C) 2018  SlashGaming Community
 *
 * This file is part of SlashGaming Diablo II Modding API.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as published
 *  by the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Additional permissions under GNU Affero General Public License version 3
 *  section 7
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with Diablo II (or a modified version of that game and its
 *  libraries), containing parts covered by the terms of Blizzard End User
 *  License Agreement, the licensors of this Program grant you additional
 *  permission to convey the resulting work. This additional permission is
 *  also extended to any combination of expansions, mods, and remasters of
 *  the game, provided that the game or its libraries do not link to this
 *  Program.
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any Glide wrapper (or a modified version of that library),
 *  containing parts not covered by a compatible license, provided that the
 *  wrapper does not link to this Program, the licensors of this Program
 *  grant you additional permission to convey the resulting work.
 */

#include "game_address_table.h"

#include <cstdint>
#include <fstream>
#include <string>
#include <string_view>
#include <unordered_map>

#include <boost/filesystem.hpp>
#include <nlohmann/json.hpp>

#include "config_parser.h"
#include "game_library.h"
#include "game_library_table.h"
#include "game_address_locator/game_offset.h"
#include "game_address_locator/game_ordinal.h"
#include "game_version.h"

namespace sgd2mapi::address {

namespace {

using Locator = std::unordered_map<std::string, nlohmann::json>;
using LocatorByVersion = std::unordered_map<std::string, Locator>;

constexpr std::string_view kLocatorTypeKey = "Locator Type";
constexpr std::string_view kLocatorValueKey = "Locator Value";

constexpr std::string_view kLocatorTypeOffset = "Offset";
constexpr std::string_view kLocatorTypeOrdinal = "Ordinal";

std::unordered_map<std::string, std::intptr_t> ReadTableFile() noexcept {
  config::ConfigParser& config_parser = config::ConfigParser::GetInstance();

  // Read the address table into JSON.
  nlohmann::json address_table_json;
  if (std::ifstream address_table_file(
          config_parser.address_table_path().data());
      address_table_file.good()) {
    address_table_json = nlohmann::json::parse(address_table_file);
  }

  // Parse the JSON into the address table.
  std::unordered_map<std::string, std::intptr_t> address_table;

  std::string version_name =
      version::RunningGameVersion::GetInstance().game_version_id();
  for (const auto& library_items : address_table_json.items()) {
    const std::string library_name = library_items.key();
    const std::string library_path = library_name + ".dll";
    const library::GameLibrary& game_library =
        library::GameLibraryTable::GetInstance().GetGameLibrary(library_path);

    for (const auto& item : library_items.value().items()) {
      std::string game_address_name = item.key();

      // Determine the full game address name.
      std::string full_game_address_name = library_name
                                           + "_"
                                           + game_address_name;

      // Determine the destination game address.
      LocatorByVersion locator_by_version = item.value();
      Locator locator = locator_by_version.at(version_name);

      std::string locator_type = locator.at(kLocatorTypeKey.data());
      std::intptr_t locator_value = locator.at(kLocatorValueKey.data());

      std::intptr_t final_game_address;
      if (locator_type == kLocatorTypeOffset) {
        final_game_address =
            address::GameOffset(locator_value)
                    .ResolveGameAddress(game_library.base_address());
      } else if (locator_type == kLocatorTypeOrdinal) {
        final_game_address =
            address::GameOrdinal(locator_value)
                    .ResolveGameAddress(game_library.base_address());
      }

      address_table.insert_or_assign(full_game_address_name,
                                     final_game_address);
    }
  }

  return address_table;
}

} // namespace

GameAddressTable::GameAddressTable(std::string_view table_path)
  : address_table_(ReadTableFile()) {
}

const GameAddressTable& GameAddressTable::GetInstance() noexcept {
  static GameAddressTable instance(
      config::ConfigParser::GetInstance().address_table_path()
  );
  return instance;
}

std::intptr_t GameAddressTable::GetAddress(
    std::string_view address_name) noexcept {
  return GetInstance().address_table_.at(address_name.data());
}

} // namespace sgd2mapi::address
