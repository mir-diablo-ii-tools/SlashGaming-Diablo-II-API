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

#include "../../include/c/game_patch.h"

#include <windows.h>

#include "../../include/cxx/game_patch.hpp"

void MAPI_GamePatch_Deinit(
    MAPI_GamePatch* game_patch
) {
  MAPI_GamePatch_Remove(game_patch);

  delete game_patch->old_buffer;
  delete game_patch->patch_buffer;
}

void MAPI_GamePatch_Apply(
    MAPI_GamePatch* game_patch
) {
  if (game_patch->is_patch_applied) {
    return;
  }

  intptr_t raw_address = game_patch->game_address.raw_address;

  // Replace the data at the destination with the values in the patch buffer.
  WriteProcessMemory(
      GetCurrentProcess(),
      reinterpret_cast<void*>(raw_address),
      game_patch->patch_buffer,
      game_patch->patch_size,
      nullptr
  );

  game_patch->is_patch_applied = true;
}

void MAPI_GamePatch_Remove(
    MAPI_GamePatch* game_patch
) {
  if (!game_patch->is_patch_applied) {
    return;
  }

  intptr_t raw_address = game_patch->game_address.raw_address;

  // Restore the old state of the destination.
  WriteProcessMemory(
      GetCurrentProcess(),
      reinterpret_cast<void*>(raw_address),
      game_patch->old_buffer,
      game_patch->patch_size,
      nullptr
  );

  game_patch->is_patch_applied = false;
}
