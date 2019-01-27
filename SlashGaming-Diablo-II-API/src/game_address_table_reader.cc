/**
 * SlashGaming Diablo II Modding API
 * Copyright (C) 2018-2019  Mir Drualga
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
 *  the game.
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any Glide wrapper (or a modified version of that library),
 *  containing parts not covered by a compatible license, the licensors of
 *  this Program grant you additional permission to convey the resulting
 *  work.
 */

#include "game_address_table_reader.h"

#include <windows.h>
#include <cstdint>
#include <cstdlib>
#include <charconv>
#include <filesystem>
#include <fstream>
#include <memory>
#include <regex>
#include <string>
#include <string_view>
#include <unordered_map>

#include <fmt/printf.h>
#include "../include/game_address.h"
#include "../include/game_address_locator.h"
#include "../include/default_game_library.h"
#include "game_library_table.h"
#include "../include/game_version.h"

namespace sgd2mapi {

namespace {

constexpr std::string_view kLocatorTypeKey = u8"Locator Type";
constexpr std::string_view kLocatorValueKey = u8"Locator Value";

constexpr std::string_view kLocatorTypeOffset = u8"Offset";
constexpr std::string_view kLocatorTypeOrdinal = u8"Ordinal";
constexpr std::string_view kLocatorTypeDecoratedName = u8"Decorated Name";

std::shared_ptr<GameAddressLocatorInterface>
ResolveLocator(
    std::string_view locator_type,
    std::string_view locator_value
) {
  std::shared_ptr<GameAddressLocatorInterface> game_address_locator;

  if (locator_type == kLocatorTypeOffset) {
    int offset = std::stoi(locator_value.data(), 0, 16);
    game_address_locator = std::make_unique<GameOffset>(offset);
  } else if (locator_type == kLocatorTypeOrdinal) {
    int ordinal;
    std::from_chars(
        locator_value.data(),
        locator_value.data() + locator_value.length(),
        ordinal
    );

    game_address_locator = std::make_unique<GameOrdinal>(ordinal);
  } else if (locator_type == kLocatorTypeDecoratedName) {
    game_address_locator = std::make_unique<GameDecoratedName>(locator_value);
  }

  return game_address_locator;
}

GameAddress
ResolveAddress(
    std::string_view library_name,
    std::string_view address_name,
    std::string_view locator_type,
    std::string_view locator_value
) {
  std::string library_file_name = library_name.data();
  library_file_name += u8".dll";

  const GameLibrary& game_library = GetGameLibrary(library_file_name);
  std::intptr_t game_library_base_address = game_library.base_address();

  std::shared_ptr<
      GameAddressLocatorInterface
  > address_locator = ResolveLocator(
      locator_type,
      locator_value
  );

  return GameAddress(
      game_library.library_path(),
      std::move(address_locator)
  );
}

} // namespace

std::unordered_map<std::string, GameAddress>
ReadTsvTableFile(
    const std::filesystem::path& table_file_path
) {
  static const std::regex kLineRegex(
      u8"(.*?)\t(.*?)\t(.*?)\t([^\t]*)(.*)",
      std::regex_constants::ECMAScript | std::regex::icase
  );

  // Open the file and check for it to be valid.
  if (!std::filesystem::exists(table_file_path)) {
    std::wstring error_message = fmt::sprintf(
        L"The file %s does not exist.",
        table_file_path
    );

    MessageBoxW(
        nullptr,
        error_message.data(),
        L"Could Not Locate Address Table",
        MB_OK | MB_ICONERROR
    );

    std::exit(0);
  }

  std::ifstream address_table_file_stream(
      table_file_path
  );

  if (!address_table_file_stream) {
    std::wstring error_message = fmt::sprintf(
        L"The address table could not be opened.",
        table_file_path
    );

    MessageBoxW(
        nullptr,
        error_message.data(),
        L"Could Not Open Address Table",
        MB_OK | MB_ICONERROR
    );
    std::exit(0);
  }

  // Discard the header line, because it's for humans.
  address_table_file_stream.ignore(
      std::numeric_limits<std::streamsize>::max(),
      '\n'
  );

  std::unordered_map<std::string, GameAddress> address_table;

  // Read each line.
  for (std::string line; std::getline(address_table_file_stream, line); ) {
    std::smatch matches;
    if (!std::regex_match(line.cbegin(), line.cend(), matches, kLineRegex)) {
      continue;
    }

    // Pull the column data.
    const std::string& library_name = matches[1];
    const std::string& address_name = matches[2];
    const std::string& locator_type = matches[3];
    const std::string& locator_value = matches[4];

    GameAddress resolved_game_address = ResolveAddress(
        library_name,
        address_name,
        locator_type,
        locator_value
    );

    std::string full_address_name = library_name + u8"_" + address_name;

    address_table.insert_or_assign(
        std::move(full_address_name),
        resolved_game_address
    );
  }

  return address_table;
}

} // namespace sgd2mapi
