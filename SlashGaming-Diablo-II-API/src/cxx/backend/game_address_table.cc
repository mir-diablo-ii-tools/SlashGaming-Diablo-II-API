/**
 * SlashGaming Diablo II Modding API for C++
 * Copyright (C) 2018-2020  Mir Drualga
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

#include "game_address_table.hpp"

#include <filesystem>
#include <stdexcept>
#include <string>
#include <string_view>

#include <fmt/format.h>
#include "../../wide_macro.h"
#include "encoding.hpp"
#include "error_handling.hpp"
#include "game_address_table/game_address_table_impl.hpp"

namespace mapi {
namespace {

[[noreturn]] void ExitOnAddressNotDefined(
    const std::filesystem::path& library_path,
    std::string_view address_name,
    std::wstring_view source_code_file_path,
    int source_code_line
) {
  constexpr std::wstring_view kErrorFormatMessage =
        L"Address not defined for library: {}, address name: {}.";

  std::wstring address_name_wide = ConvertMultiByteUtf8ToWide(
      address_name,
      source_code_file_path,
      source_code_line
  );

  std::wstring full_message = fmt::format(
      kErrorFormatMessage,
      library_path.wstring(),
      address_name_wide
  );

  ExitOnGeneralFailure(
      full_message,
      L"Address Not Defined",
      source_code_file_path,
      source_code_line
  );
}

const GameAddressTable& GetGameAddressTable() {
  static GameAddressTable game_address_table = LoadGameAddressTable();

  return game_address_table;
}

} // namespace

GameAddress LoadGameAddress(
    DefaultLibrary library_id,
    std::string_view address_name
) {
  const std::filesystem::path& library_path =
      GetDefaultLibraryPathWithoutRedirect(library_id);

  try {
    const std::unique_ptr<IGameAddressLocator>& locator =
        GetGameAddressTable().at(library_path).at(address_name.data());

    return locator->LocateGameAddress();
  } catch (const std::out_of_range& e) {
    ExitOnAddressNotDefined(library_path, address_name, __FILEW__, __LINE__);
  }
}

GameAddress LoadGameAddress(
    const std::filesystem::path& library_path,
    std::string_view address_name
) {
  try {
    const std::unique_ptr<IGameAddressLocator>& locator =
        GetGameAddressTable().at(library_path).at(address_name.data());

    return locator->LocateGameAddress();
  } catch (const std::out_of_range& e) {
    ExitOnAddressNotDefined(library_path, address_name, __FILEW__, __LINE__);
  }
}

} // namespace mapi
