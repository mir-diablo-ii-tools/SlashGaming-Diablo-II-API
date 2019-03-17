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

#include "../../../include/cxx/game_address/game_ordinal_address.hpp"

#include <windows.h>
#include <cstdint>
#include <string>

#include <fmt/format.h>
#include <fmt/printf.h>
#include "../../../include/cxx/default_game_library.hpp"
#include "../../../include/cxx/game_address/game_address_base.hpp"
#include "../game_library.hpp"

namespace sgd2mapi {
namespace {

std::intptr_t ResolveGameAddress(
    const std::filesystem::path& default_library_path,
    int ordinal
) {
  // Check that the upper 2 bytes are zero.
  if ((ordinal & 0xFFFF) != ordinal) {
    std::wstring error_message = fmt::sprintf(
        L"Invalid ordinal value %d. The leftmost four bytes of an ordinal must"
        L"be zero.",
        ordinal
    );
    MessageBoxW(
        nullptr,
        error_message.data(),
        L"Invalid Ordinal Value",
        MB_OK | MB_ICONERROR
    );
    std::exit(0);
  }

  const GameLibrary& game_library = GetGameLibrary(default_library_path);

  FARPROC func_address = GetProcAddress(
      reinterpret_cast<HMODULE>(game_library.base_address()),
      reinterpret_cast<const CHAR*>(ordinal)
  );

  if (func_address == nullptr) {
    std::wstring error_message = fmt::sprintf(
        L"The data or function with the ordinal %d could not be found.",
        ordinal
    );

    MessageBoxW(
        nullptr,
        error_message.data(),
        L"Failed to Locate Address",
        MB_OK | MB_ICONERROR
    );
    std::exit(0);
  }

  return reinterpret_cast<std::intptr_t>(func_address);
}

std::intptr_t ResolveGameAddress(
    enum DefaultLibrary default_library,
    int ordinal
) {
  const std::filesystem::path& game_library_path =
      GetDefaultLibraryPathWithRedirect(default_library);

  return ResolveGameAddress(game_library_path, ordinal);
}

} // namespace

GameOrdinalAddress::GameOrdinalAddress(
    enum DefaultLibrary default_library,
    int ordinal
) : GameAddressBase(
        ResolveGameAddress(default_library, ordinal)
    ) {
}

GameOrdinalAddress::GameOrdinalAddress(
    const std::filesystem::path& default_library_path,
    int ordinal
) : GameAddressBase(
        ResolveGameAddress(default_library_path, ordinal)
    ) {
}

GameOrdinalAddress::~GameOrdinalAddress(void) noexcept = default;

}