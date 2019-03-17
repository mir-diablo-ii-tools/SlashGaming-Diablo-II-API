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

#include "../../../include/cxx/game_address/game_decorated_name_address.hpp"

#include <windows.h>
#include <cstdint>
#include <string>
#include <string_view>

#include <fmt/format.h>
#include <fmt/printf.h>
#include "../game_library.hpp"

namespace sgd2mapi {
namespace {

std::intptr_t ResolveGameAddress(
    const std::filesystem::path& default_library_path,
    std::string_view decorated_name
) {
  const GameLibrary& game_library = GetGameLibrary(default_library_path);

  FARPROC raw_address = GetProcAddress(
      reinterpret_cast<HMODULE>(game_library.base_address()),
      decorated_name.data()
  );

  if (raw_address == nullptr) {
    std::wstring error_message = fmt::sprintf(
        L"The data or function with the name %s could not be found.",
        fmt::to_wstring(decorated_name)
    );

    MessageBoxW(
        nullptr,
        error_message.data(),
        L"Failed to Locate Address",
        MB_OK | MB_ICONERROR
    );
    std::exit(0);
  }

  return reinterpret_cast<std::intptr_t>(raw_address);
}

std::intptr_t ResolveGameAddress(
    enum DefaultLibrary default_library,
    std::string_view decorated_name
) {
  const std::filesystem::path& default_library_path =
      GetDefaultLibraryPathWithRedirect(default_library);

  return ResolveGameAddress(default_library_path, decorated_name);
}

} // namespace

GameDecoratedNameAddress::GameDecoratedNameAddress(
    enum DefaultLibrary default_library,
    std::string_view decorated_name
) : GameAddressBase(
        ResolveGameAddress(default_library, decorated_name)
    ) {
}

GameDecoratedNameAddress::GameDecoratedNameAddress(
    const std::filesystem::path& default_library_path,
    std::string_view decorated_name
) : GameAddressBase(
        ResolveGameAddress(default_library_path, decorated_name)
    ) {
}

GameDecoratedNameAddress::~GameDecoratedNameAddress(void) noexcept = default;

} // namespace sgd2mapi
