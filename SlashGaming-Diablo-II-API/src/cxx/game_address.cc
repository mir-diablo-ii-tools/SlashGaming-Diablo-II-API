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

#include "../../include/cxx/game_address.hpp"

#include <windows.h>
#include <cstdint>
#include <filesystem>
#include <string>
#include <string_view>

#include <fmt/format.h>
#include "../../include/cxx/default_game_library.hpp"
#include "../wide_macro.h"
#include "backend/encoding.hpp"
#include "backend/error_handling.hpp"
#include "backend/game_library.hpp"

namespace mapi {

GameAddress::GameAddress(
    std::intptr_t raw_address
) noexcept
    : raw_address_(raw_address) {
}

std::intptr_t GameAddress::raw_address() const noexcept {
  return raw_address_;
}

GameAddress GameAddress::FromDecoratedName(
    DefaultLibrary default_library,
    std::string_view decorated_name
) {
  const std::filesystem::path& default_library_path =
      GetDefaultLibraryPathWithRedirect(default_library);

  return FromDecoratedName(default_library_path, decorated_name);
}

GameAddress GameAddress::FromDecoratedName(
    const std::filesystem::path& library_path,
    std::string_view decorated_name
) {
  const GameLibrary& game_library = GameLibrary::GetGameLibrary(library_path);

  FARPROC raw_address = GetProcAddress(
      reinterpret_cast<HMODULE>(game_library.base_address()),
      decorated_name.data()
  );

  if (raw_address == nullptr) {
    constexpr std::wstring_view kErrorFormatMessage =
        L"The data or function with the name {} could not be found.";

    std::wstring wide_decorated_name = ConvertMultiByteUtf8ToWide(
        decorated_name,
        __FILEW__,
        __LINE__
    );

    std::wstring full_message = fmt::format(
        kErrorFormatMessage,
        wide_decorated_name
    );

    ExitOnGeneralFailure(
        full_message,
        L"Failed to Locate Address",
        __FILEW__,
        __LINE__
    );
  }

  return GameAddress(reinterpret_cast<std::intptr_t>(raw_address));
}

GameAddress GameAddress::FromOffset(
    DefaultLibrary default_library,
    std::ptrdiff_t offset
) {
  const std::filesystem::path& game_library_path =
      GetDefaultLibraryPathWithRedirect(default_library);

  return FromOffset(game_library_path, offset);
}

GameAddress GameAddress::FromOffset(
    const std::filesystem::path& library_path,
    std::ptrdiff_t offset
) {
  const GameLibrary& game_library = GameLibrary::GetGameLibrary(library_path);

  return GameAddress(game_library.base_address() + offset);
}

GameAddress GameAddress::FromOrdinal(
    DefaultLibrary default_library,
    std::int16_t ordinal
) {
  const std::filesystem::path& game_library_path =
      GetDefaultLibraryPathWithRedirect(default_library);

  return FromOrdinal(game_library_path, ordinal);
}

GameAddress GameAddress::FromOrdinal(
    const std::filesystem::path& library_path,
    std::int16_t ordinal
) {
  const GameLibrary& game_library = GameLibrary::GetGameLibrary(library_path);

  FARPROC func_address = GetProcAddress(
      reinterpret_cast<HMODULE>(game_library.base_address()),
      reinterpret_cast<const char*>(ordinal)
  );

  if (func_address == nullptr) {
    constexpr std::wstring_view kErrorFormatMessage =
        L"The data or function with the ordinal {} from {} could not be "
        L"found.";

    std::wstring full_message = fmt::format(
        kErrorFormatMessage,
        ordinal,
        game_library.file_path().wstring()
    );

    ExitOnGeneralFailure(
        full_message,
        L"Failed to Locate Address",
        __FILEW__,
        __LINE__
    );
  }

  return GameAddress(reinterpret_cast<std::intptr_t>(func_address));
}

} // namespace mapi
