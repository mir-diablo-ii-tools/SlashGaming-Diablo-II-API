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

#include "../../../include/c/game_patch/game_back_branch_patch.h"

#include <cstddef>
#include <algorithm>
#include <memory>

#include "../../../include/c/game_address.h"
#include "../../../include/c/game_patch.h"
#include "../../cxx/game_patch/game_back_branch_patch_buffer.hpp"

void MAPI_GamePatch_InitGameBackBranchPatch(
    MAPI_GamePatch* game_patch,
    const MAPI_GameAddress* game_address,
    int branch_opcode,
    void (*func_ptr)(void),
    size_t patch_size
) {
  game_patch->game_address = *game_address;
  game_patch->is_patch_applied = false;
  game_patch->patch_size = patch_size;

  // Create the patch buffer.
  std::unique_ptr patch_buffer = MAPI_CreateGameBackBranchPatchBuffer(
      *game_address,
      branch_opcode,
      func_ptr,
      patch_size
  );

  // Create the old buffer.
  std::unique_ptr old_buffer =
      std::make_unique<std::uint8_t[]>(patch_size);

  std::copy_n(
      reinterpret_cast<std::uint8_t*>(game_address->raw_address),
      patch_size,
      old_buffer.get()
  );

  game_patch->patch_buffer = patch_buffer.release();
  game_patch->old_buffer = old_buffer.release();
}
