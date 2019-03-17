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

#include "../../../include/c/game_address/game_ordinal.h"

#include <filesystem>

#include "../../../include/c/game_address.h"
#include "../../../include/cxx/game_address.hpp"

namespace {

void SGD2MAPI_GameAddress_InitFromOrdinal(
    struct SGD2MAPI_GameAddress* game_address,
    const std::filesystem::path& library_path,
    int ordinal
) {
  sgd2mapi::GameAddress actual_game_address =
      sgd2mapi::GameAddress::FromOrdinal(
          library_path,
          ordinal
      );

  game_address->raw_address = actual_game_address.raw_address();
}

} // namespace

void SGD2MAPI_GameAddress_InitFromLibraryIdAndOrdinal(
    struct SGD2MAPI_GameAddress* game_address,
    int library_id,
    int ordinal
) {
  sgd2mapi::DefaultLibrary actual_default_library =
      static_cast<sgd2mapi::DefaultLibrary>(library_id);

  const std::filesystem::path& actual_library_path =
      sgd2mapi::GetDefaultLibraryPathWithRedirect(actual_default_library);

  SGD2MAPI_GameAddress_InitFromOrdinal(
      game_address,
      actual_library_path,
      ordinal
  );
}

void SGD2MAPI_GameAddress_InitFromLibraryPathAndOrdinal(
    struct SGD2MAPI_GameAddress* game_address,
    const char library_path[],
    int ordinal
) {
  SGD2MAPI_GameAddress_InitFromOrdinal(
      game_address,
      library_path,
      ordinal
  );
}
