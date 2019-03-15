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

#ifndef SGD2MAPI_C_GAME_ADDRESS_GAME_OFFSET_H_
#define SGD2MAPI_C_GAME_ADDRESS_GAME_OFFSET_H_

#include "../../dllexport_define.inc"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

struct SGD2MAPI_GameAddress;

/**
 * Initializes a GameAddress. The base library is specified using its ID. The
 * game address locator is specified as the offset from the module base
 * address to the target address.
 */
DLLEXPORT void
SGD2MAPI_GameAddress_InitFromLibraryIdAndOffset(
    struct SGD2MAPI_GameAddress* game_address,
    int library_id,
    intptr_t offset
);

/**
 * Initializes a GameAddress. The base library is specified using its name,
 * encoded in UTF-8. The game address locator is specified as the offset from
 * the module base address to the target address.
 */
DLLEXPORT void
SGD2MAPI_GameAddress_InitFromLibraryPathAndOffset(
    struct SGD2MAPI_GameAddress* game_address,
    const char library_path[],
    intptr_t offset
);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#include "../../dllexport_undefine.inc"
#endif // SGD2MAPI_C_GAME_ADDRESS_GAME_OFFSET_H_
