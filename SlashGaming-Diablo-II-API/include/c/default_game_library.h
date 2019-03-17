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

#ifndef SGD2MAPI_C_DEFAULT_GAME_LIBRARY_H_
#define SGD2MAPI_C_DEFAULT_GAME_LIBRARY_H_

#include <stddef.h>

#include "../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * The default libraries that are used by Diablo II.
 */
enum D2_DefaultLibrary {
  LIBRARY_BNCLIENT, LIBRARY_D2CLIENT, LIBRARY_D2CMP, LIBRARY_D2COMMON,
  LIBRARY_D2DDRAW, LIBRARY_D2DIRECT3D, LIBRARY_D2GAME, LIBRARY_D2GDI,
  LIBRARY_D2GFX, LIBRARY_D2GLIDE, LIBRARY_D2LANG, LIBRARY_D2LAUNCH,
  LIBRARY_D2MCPCLIENT, LIBRARY_D2MULTI, LIBRARY_D2NET, LIBRARY_D2SERVER,
  LIBRARY_D2SOUND, LIBRARY_D2WIN, LIBRARY_FOG, LIBRARY_STORM,
};

DLLEXPORT char* MAPI_GetGameExecutablePath(
    char dest[]
);

DLLEXPORT size_t MAPI_GetGameExecutablePathSize(void);

DLLEXPORT char* MAPI_GetDefaultLibraryPathWithRedirect(
    char dest[],
    int library_id
);

DLLEXPORT size_t MAPI_GetDefaultLibraryPathWithRedirectSize(
    int library_id
);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#include "../dllexport_undefine.inc"

#endif // SGD2MAPI_C_DEFAULT_GAME_LIBRARY_H_
