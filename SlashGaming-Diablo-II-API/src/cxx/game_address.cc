/**
 * SlashGaming Diablo II Modding API for C++
 * Copyright (C) 2018-2022  Mir Drualga
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

#include "../../include/cxx/game_address.hpp"

#include <windows.h>

#include <cstdint>
#include <array>

#include <mdc/error/exit_on_error.hpp>
#include <mdc/wchar_t/filew.h>
#include <mdc/wchar_t/wide_decoding.hpp>
#include "backend/game_library.hpp"

namespace mapi {

GameAddress GameAddress::FromExportedName(
    ::d2::DefaultLibrary library,
    const char* exported_name
) {
  const wchar_t* path = ::d2::default_library::GetPathWithRedirect(library);

  return FromExportedName(path, exported_name);
}

GameAddress GameAddress::FromExportedName(
    const wchar_t* path,
    const char* exported_name
) {
  static constexpr std::size_t kExportedNameWideCapacity = 1024;

  static std::array<wchar_t, kExportedNameWideCapacity> exported_name_wide;

  const GameLibrary& game_library = GameLibrary::GetGameLibrary(path);

  FARPROC raw_address = GetProcAddress(
      reinterpret_cast<HMODULE>(game_library.base_address()),
      exported_name
  );

  if (raw_address == nullptr) {
    std::size_t exported_name_wide_length = ::mdc::wide::DecodeAsciiLength(
        exported_name
    );

    const wchar_t* exported_name_wide_ptr;

    if (exported_name_wide_length >= kExportedNameWideCapacity) {
      exported_name_wide_ptr = L"**Name is longer than character limit**";
    } else {
      exported_name_wide_ptr = ::mdc::wide::DecodeAscii(
          exported_name_wide.data(),
          exported_name
      );
    }

    ::mdc::error::ExitOnGeneralError(
        L"Error",
        L"%ls failed with error code 0x%X. Could not locate exported "
            L"name %ls from the path %ls.",
        __FILEW__,
        __LINE__,
        L"GetProcAddress",
        GetLastError(),
        exported_name_wide_ptr,
        path
    );

    return GameAddress(0);
  }

  return GameAddress(reinterpret_cast<std::intptr_t>(raw_address));
}

GameAddress GameAddress::FromOffset(
    d2::DefaultLibrary library,
    std::ptrdiff_t offset
) {
  const wchar_t* path = ::d2::default_library::GetPathWithRedirect(library);

  return FromOffset(path, offset);
}

GameAddress GameAddress::FromOffset(
    const wchar_t* path,
    std::ptrdiff_t offset
) {
  const GameLibrary& game_library = GameLibrary::GetGameLibrary(path);

  return GameAddress(game_library.base_address() + offset);
}

GameAddress GameAddress::FromOrdinal(
    d2::DefaultLibrary library,
    std::int16_t ordinal
) {
  const wchar_t* path = ::d2::default_library::GetPathWithRedirect(library);

  return FromOrdinal(path, ordinal);
}

GameAddress GameAddress::FromOrdinal(
    const wchar_t* path,
    std::int16_t ordinal
) {
  const GameLibrary& game_library = GameLibrary::GetGameLibrary(path);

  FARPROC func_address = GetProcAddress(
      reinterpret_cast<HMODULE>(game_library.base_address()),
      reinterpret_cast<const char*>(ordinal)
  );

  if (func_address == nullptr) {
    ::mdc::error::ExitOnGeneralError(
        L"Error",
        L"%ls failed with error code 0x%X. Could not locate "
            L"exported ordinal %hd from the path %ls.",
        __FILEW__,
        __LINE__,
        L"GetProcAddress",
        GetLastError(),
        ordinal,
        path
    );

    return GameAddress(0);
  }

  return GameAddress(reinterpret_cast<std::intptr_t>(func_address));
}

} // namespace mapi
