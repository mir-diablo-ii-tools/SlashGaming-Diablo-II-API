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

#include "../../../include/c/game_address/game_decorated_name.h"

#include <filesystem>
#include <string_view>

#include "../../../include/c/game_address.h"
#include "../../../include/cxx/game_address.hpp"

namespace {

void MAPI_GameAddress_InitFromDecoratedName(
    struct MAPI_GameAddress* game_address,
    const std::filesystem::path& library_path,
    std::string_view decorated_name
) {
  mapi::GameAddress actual_game_address =
      mapi::GameAddress::FromDecoratedName(
          library_path,
          decorated_name
      );

  game_address->raw_address = actual_game_address.raw_address();
}

} // namespace

void MAPI_GameAddress_InitFromLibraryIdAndDecoratedName(
    struct MAPI_GameAddress* game_address,
    int library_id,
    const char decorated_name[]
) {
  mapi::DefaultLibrary actual_default_library =
      static_cast<mapi::DefaultLibrary>(library_id);

  const std::filesystem::path& actual_library_path =
      mapi::GetDefaultLibraryPathWithRedirect(actual_default_library);

  MAPI_GameAddress_InitFromDecoratedName(
      game_address,
      actual_library_path,
      decorated_name
  );
}

void MAPI_GameAddress_InitFromLibraryPathAndDecoratedName(
    struct MAPI_GameAddress* game_address,
    const char library_path[],
    const char decorated_name[]
) {
  MAPI_GameAddress_InitFromDecoratedName(
      game_address,
      library_path,
      decorated_name
  );
}
