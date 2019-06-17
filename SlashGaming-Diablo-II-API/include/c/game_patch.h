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

#ifndef SGMAPI_C_GAME_PATCH_H_
#define SGMAPI_C_GAME_PATCH_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "game_address.h"
#include "game_patch/game_back_branch_patch.h"
#include "game_patch/game_branch_patch.h"
#include "game_patch/game_buffer_patch.h"
#include "game_patch/game_nop_patch.h"

#include "../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

struct MAPI_GamePatch {
  struct MAPI_GameAddress game_address;
  bool is_patch_applied;
  uint8_t* patch_buffer;
  uint8_t* old_buffer;
  size_t patch_size;
};

/**
 * Deinitializes the specified game patch.
 */
DLLEXPORT void MAPI_GamePatch_Deinit(
  struct MAPI_GamePatch* game_patch
);

/**
 * Applies the game patch by replacing the bytes at its target address with the
 * bytes stored in its buffer.
 */
DLLEXPORT void MAPI_GamePatch_Apply(
  struct MAPI_GamePatch* game_patch
);

/**
 * Removes the effects of the game patch by restoring the original state of the
 * bytes at its target address.
 */
DLLEXPORT void MAPI_GamePatch_Remove(
  struct MAPI_GamePatch* game_patch
);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#include "../dllexport_undefine.inc"
#endif // SGMAPI_C_GAME_PATCH_H_
