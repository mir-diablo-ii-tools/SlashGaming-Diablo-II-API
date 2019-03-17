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

#ifndef SGD2MAPI_C_GAME_VERSION_H_
#define SGD2MAPI_C_GAME_VERSION_H_

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include "../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * The Diablo II game versions supported and recognized.
 */
enum D2_GameVersion {
  VERSION_1_00, VERSION_1_01, VERSION_1_02, VERSION_1_03, VERSION_1_04B_C,
  VERSION_1_05, VERSION_1_05B, VERSION_1_06, VERSION_1_06B, VERSION_1_07_BETA,
  VERSION_1_07, VERSION_1_08, VERSION_1_09, VERSION_1_09B, VERSION_1_09D,
  VERSION_1_10_BETA, VERSION_1_10S_BETA, VERSION_1_10, VERSION_1_11,
  VERSION_1_11B, VERSION_1_12A, VERSION_1_13A_BETA, VERSION_1_13C,
  VERSION_1_13D,

  CLASSIC_1_14A, LOD_1_14A, CLASSIC_1_14B, LOD_1_14B, CLASSIC_1_14C,
  LOD_1_14C, CLASSIC_1_14D, LOD_1_14D,
};

/**
 * Copies the UTF-8 encoded string associated with the specified game version
 * into the specified destination buffer.
 */
DLLEXPORT char*
D2_GetGameVersionName(
    char dest[],
    int game_version_id
);

/**
 * Returns the number of bytes needed to copy the UTF-8 encoded string
 * associated with the specified game version.
 */
DLLEXPORT size_t
D2_GetGameVersionNameSize(
    int game_version_id
);

/**
 * Returns the identifier of the running game version.
 */
DLLEXPORT int
D2_GetRunningGameVersionId(
    void
);

/**
 * Copies the UTF-8 encoded string associated with the running game version
 * into the specified destination buffer.
 */
DLLEXPORT char*
D2_GetRunningGameVersionName(
    char dest[]
);

/**
 * Returns the number of bytes needed to copy the UTF-8 encoded string
 * associated with the running game version.
 */
DLLEXPORT size_t
D2_GetRunningGameVersionNameSize(
    void
);

/**
 * Returns whether the Diablo II game version is at least 1.14.
 */
DLLEXPORT bool
D2_IsGameVersionAtLeast1_14(
    int game_version_id
);

/**
 * Returns whether the running game version is at least 1.14.
 */
DLLEXPORT bool
D2_IsRunningGameVersionAtLeast1_14(
    void
);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#include "../dllexport_undefine.inc"
#endif // SGD2MAPI_C_GAME_VERSION_H_
