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

#include "game_address_table.hpp"

#include <windows.h>
#include <cstdint>
#include <filesystem>
#include <stdexcept>
#include <string>
#include <string_view>
#include <unordered_map>

#include <fmt/format.h>
#include <fmt/printf.h>
#include <nlohmann/json.hpp>

#include "config_parser.hpp"
#include "../include/game_address_locator.hpp"
#include "game_address_table_reader.hpp"
#include "../include/default_game_library.hpp"
#include "game_library.hpp"
#include "../include/game_version.hpp"

namespace sgd2mapi {
namespace {

const std::filesystem::path&
GetTableFilePath(
    void
) {
  const std::filesystem::path& address_table_directory =
      GetAddressTableDirectoryPath();
  std::string_view running_game_version_name =
      GetRunningGameVersionName();

  std::filesystem::path table_file_path(address_table_directory);
  table_file_path /= running_game_version_name;
  table_file_path += u8".txt";

  return table_file_path;
}

const std::unordered_map<std::string, GameAddress>&
GetAddressTable(
    void
) {
  static std::unordered_map<
      std::string,
      GameAddress
  > game_address_table(
      ReadTsvTableFile(GetTableFilePath())
  );

  return game_address_table;
}

} // namespace

const GameAddress&
GetGameAddress(
    std::string_view address_name
) {
  try {
    return GetAddressTable().at(address_name.data());
  } catch (const std::out_of_range& e) {
    constexpr std::wstring_view kErrorFormatMessage =
        L"File: %s \n"
        L"Line: %d \n"
        L"Address not defined for %s.";

    std::wstring full_message = fmt::sprintf(
        kErrorFormatMessage,
        fmt::to_wstring(__FILE__),
        __LINE__,
        fmt::to_wstring(address_name)
    );

    MessageBoxW(
        nullptr,
        full_message.data(),
        L"Address Not Defined",
        MB_OK | MB_ICONERROR
    );

    std::exit(0);
  }
}

std::intptr_t
GetRawAddress(
    std::string_view address_name
) {
  return GetGameAddress(address_name).raw_address();
}

} // namespace sgd2mapi
