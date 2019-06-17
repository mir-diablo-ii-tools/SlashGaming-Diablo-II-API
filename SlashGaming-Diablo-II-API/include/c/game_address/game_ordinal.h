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

#ifndef SGMAPI_C_GAME_ADDRESS_GAME_ORDINAL_H_
#define SGMAPI_C_GAME_ADDRESS_GAME_ORDINAL_H_

#include <stdint.h>

#include "../game_address.h"

#include "../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * Initializes a GameAddress. The base library is specified using its ID. The
 * game address locator is specified as the address's ordinal value.
 */
DLLEXPORT void MAPI_GameAddress_InitFromLibraryIdAndOrdinal(
    struct MAPI_GameAddress* game_address,
    int library_id,
    int16_t ordinal
);

/**
 * Initializes a GameAddress. The base library is specified using its path,
 * encoded in UTF-8. The game address locator is specified as the address's
 * ordinal value.
 */
DLLEXPORT void MAPI_GameAddress_InitFromLibraryPathAndOrdinal(
    struct MAPI_GameAddress* game_address,
    const char* library_path,
    int16_t ordinal
);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#include "../../dllexport_undefine.inc"
#endif // SGMAPI_C_GAME_ADDRESS_GAME_ORDINAL_H_
