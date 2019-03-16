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

#include "../../include/c/game_version.h"

#include <stdbool.h>
#include <stddef.h>
#include <algorithm>

#include "../../include/c/game_bool.h"
#include "../../include/cxx/game_version.hpp"

char*
SGD2MAPI_GetGameVersionName(
    char dest[],
    int game_version_id
) {
  sgd2mapi::GameVersion actual_game_version_id =
      static_cast<sgd2mapi::GameVersion>(game_version_id);

  std::string_view game_version_name = sgd2mapi::GetGameVersionName(
      actual_game_version_id
  );

  std::copy(
      game_version_name.cbegin(),
      game_version_name.cend(),
      dest
  );

  return dest;
}

size_t
SGD2MAPI_GetGameVersionNameSize(
    int game_version_id
) {
  sgd2mapi::GameVersion actual_game_version_id =
      static_cast<sgd2mapi::GameVersion>(game_version_id);

  std::string_view game_version_name = sgd2mapi::GetGameVersionName(
      actual_game_version_id
  );

  return game_version_name.size() + 1;
}

int
SGD2MAPI_GetRunningGameVersionId(
    void
) {
  return static_cast<enum SGD2MAPI_GameVersion>(
      sgd2mapi::GetRunningGameVersionId()
  );
}

char*
SGD2MAPI_GetRunningGameVersionName(
    char dest[]
) {
  std::string_view game_version_name =
      sgd2mapi::GetRunningGameVersionName();

  std::copy(
      game_version_name.cbegin(),
      game_version_name.cend(),
      dest
  );

  return dest;
}

size_t
SGD2MAPI_GetRunningGameVersionNameSize(
    void
) {
  std::string_view game_version_name =
      sgd2mapi::GetRunningGameVersionName();

  return game_version_name.size() + 1;
}

bool
SGD2MAPI_IsGameVersionAtLeast1_14(
    int game_version_id
) {
  return sgd2mapi::IsGameVersionAtLeast1_14(
      static_cast<sgd2mapi::GameVersion>(game_version_id)
  );
}

bool
SGD2MAPI_IsRunningGameVersionAtLeast1_14(
    void
) {
  return sgd2mapi::IsRunningGameVersionAtLeast1_14();
}
