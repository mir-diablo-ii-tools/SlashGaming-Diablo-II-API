/**
 * SlashGaming Diablo II Modding API for C++
 * Copyright (C) 2018-2021  Mir Drualga
 *
 * This file is part of SlashGaming Diablo II Modding API for C++.
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
 *  it with any Graphics Device Interface (GDI), DirectDraw, Direct3D,
 *  Glide, OpenGL, or Rave wrapper (or modified versions of those
 *  libraries), containing parts not covered by a compatible license, the
 *  licensors of this Program grant you additional permission to convey the
 *  resulting work.
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any library (or a modified version of that library) that links
 *  to Diablo II (or a modified version of that game and its libraries),
 *  containing parts not covered by a compatible license, the licensors of
 *  this Program grant you additional permission to convey the resulting
 *  work.
 */

#include "game_address_table_reader.hpp"

#include <windows.h>
#include <cstdint>
#include <charconv>
#include <filesystem>
#include <fstream>
#include <memory>
#include <regex>
#include <string>
#include <string_view>

#include <mdc/error/exit_on_error.h>
#include <mdc/wchar_t/wide_decoding.h>
#include <mdc/wchar_t/filew.h>
#include "../../../../include/cxx/game_version.hpp"
#include "../game_library.hpp"
#include "game_address_locator/game_address_locator.hpp"
#include "game_address_locator/game_decorated_name_locator.hpp"
#include "game_address_locator/game_offset_locator.hpp"
#include "game_address_locator/game_ordinal_locator.hpp"

namespace mapi {
namespace {

constexpr std::string_view kLocatorTypeKey = "Locator Type";
constexpr std::string_view kLocatorValueKey = "Locator Value";

constexpr std::string_view kLocatorTypeOffset = "Offset";
constexpr std::string_view kLocatorTypeOrdinal = "Ordinal";
constexpr std::string_view kLocatorTypeDecoratedName = "Decorated Name";
constexpr std::string_view kLocatorTypeNA = "N/A";

std::unique_ptr<IGameAddressLocator> ResolveLocator(
    const std::filesystem::path& library_path,
    std::string_view address_name,
    std::string_view locator_type,
    std::string_view locator_value
) {
  if (locator_type == kLocatorTypeOffset) {
    int offset = std::stoi(locator_value.data(), 0, 16);

    return std::make_unique<GameOffsetLocator>(library_path, offset);
  } else if (locator_type == kLocatorTypeOrdinal) {
    int ordinal;
    std::from_chars(
        locator_value.data(),
        locator_value.data() + locator_value.length(),
        ordinal
    );

    return std::make_unique<GameOrdinalLocator>(library_path, ordinal);
  } else if (locator_type == kLocatorTypeDecoratedName) {
    return std::make_unique<GameDecoratedNameLocator>(
        library_path,
        locator_value.data()
    );
  } else if (locator_type == kLocatorTypeNA) {
    return std::make_unique<GameOffsetLocator>(library_path, 0);
  }

  // Should never occur!
  auto address_name_wide = std::make_unique<wchar_t[]>(
      Mdc_Wide_DecodeUtf8Length(address_name.data()) + 1
  );

  Mdc_Wide_DecodeUtf8(address_name_wide.get(), address_name.data());

  auto locator_type_wide = std::make_unique<wchar_t[]>(
      Mdc_Wide_DecodeUtf8Length(locator_type.data()) + 1
  );

  Mdc_Wide_DecodeUtf8(locator_type_wide.get(), locator_type.data());

  auto locator_value_wide = std::make_unique<wchar_t[]>(
      Mdc_Wide_DecodeUtf8Length(locator_value.data()) + 1
  );

  Mdc_Wide_DecodeUtf8(locator_value_wide.get(), locator_value.data());

  Mdc_Error_ExitOnGeneralError(
      L"Error",
      L"Unknown locator type specified. \n"
          L"\n"
          L"Library Path: %ls \n"
          L"Address Name: %ls \n"
          L"Locator Type: %ls \n"
          L"Locator Value: %ls",
      __FILEW__,
      __LINE__,
      library_path.c_str(),
      address_name_wide.get(),
      locator_type_wide.get(),
      locator_value_wide.get()
  );

  return nullptr;
}

} // namespace

GameAddressTable ReadTsvTableFile(
    const std::filesystem::path& table_file_path
) {
  static const std::regex kLineRegex(
      "(.*?)\t(.*?)\t(.*?)\t([^\t]*)(.*)",
      std::regex_constants::ECMAScript | std::regex::icase
  );

  // Open the file and check for it to be valid.
  if (!std::filesystem::exists(table_file_path)) {
    Mdc_Error_ExitOnGeneralError(
        L"Error",
        L"The file %ls does not exist.",
        __FILEW__,
        __LINE__,
        table_file_path.c_str()
    );

    return GameAddressTable();
  }

  std::ifstream address_table_file_stream(table_file_path);

  if (!address_table_file_stream) {
    Mdc_Error_ExitOnGeneralError(
        L"Error",
        L"The address table in %ls could not be opened.",
        __FILEW__,
        __LINE__,
        table_file_path.c_str()
    );

    return GameAddressTable();
  }

  // Discard the header line, because it's for humans.
  address_table_file_stream.ignore(
      std::numeric_limits<std::streamsize>::max(),
      '\n'
  );

  GameAddressTable address_table;

  // Read each line.
  for (std::string line; std::getline(address_table_file_stream, line); ) {
    std::smatch matches;
    if (!std::regex_match(line.cbegin(), line.cend(), matches, kLineRegex)) {
      continue;
    }

    // Pull the column data.
    const std::string& library_path_text = matches[1];
    const std::string& address_name = matches[2];
    const std::string& locator_type = matches[3];
    const std::string& locator_value = matches[4];

    std::filesystem::path library_path = std::filesystem::path(
        library_path_text
    );

    std::unique_ptr<IGameAddressLocator> resolved_game_address_locator =
        ResolveLocator(
            library_path,
            address_name,
            locator_type,
            locator_value
        );

    if (!address_table.contains(library_path)) {
      address_table.insert_or_assign(library_path, GameAddressTable::mapped_type());
    }

    GameAddressTable::mapped_type& library_entries = address_table.at(library_path);
    library_entries.insert_or_assign(
        address_name,
        std::move(resolved_game_address_locator)
    );
  }

  return address_table;
}

} // namespace mapi
