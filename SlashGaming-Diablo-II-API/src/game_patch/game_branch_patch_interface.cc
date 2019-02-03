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

#include "../../include/game_patch/game_branch_patch_interface.h"

#include <cstdint>

void
SGD2MAPI_GameBranchPatchInterface_Destroy(
    struct SGD2MAPI_GameBranchPatchInterface* c_game_branch_patch
) {
  delete c_game_branch_patch;
}

struct SGD2MAPI_GamePatchInterface*
SGD2MAPI_GameBranchPatchInterface_Clone(
    const struct SGD2MAPI_GameBranchPatchInterface* c_game_branch_patch
) {
  return c_game_branch_patch->Clone();
}

struct SGD2MAPI_GamePatchInterface*
SGD2MAPI_GameBranchPatchInterface_MoveToClone(
    struct SGD2MAPI_GameBranchPatchInterface* c_game_branch_patch
) {
  return c_game_branch_patch->MoveToClone();
}

void
SGD2MAPI_GameBranchPatchInterface_Apply(
    struct SGD2MAPI_GameBranchPatchInterface* c_game_branch_patch
) {
  c_game_branch_patch->Apply();
}

void
SGD2MAPI_GameBranchPatchInterface_Remove(
    struct SGD2MAPI_GameBranchPatchInterface* c_game_branch_patch
) {
  c_game_branch_patch->Remove();
}

bool
SGD2MAPI_GameBranchPatchInterface_IsPatchApplied(
    const struct SGD2MAPI_GameBranchPatchInterface* c_game_branch_patch
) {
  return c_game_branch_patch->is_patch_applied();
}

/**
 * Returns the branch opcode of the game branch patch.
 */
enum SGD2MAPI_BranchType
SGD2MAPI_GameBranchPatchInterface_GetBranchType(
    const struct SGD2MAPI_GameBranchPatchInterface* c_game_branch_patch
) {
  return static_cast<enum SGD2MAPI_BranchType>(
      c_game_branch_patch->branch_type()
  );
}

/**
 * Returns the pointer to the inserted function of the game branch patch.
 */
std::intptr_t
SGD2MAPI_GameBranchPatchInterface_GetFuncPtr(
    const struct SGD2MAPI_GameBranchPatchInterface* c_game_branch_patch
) {
  return c_game_branch_patch->func_ptr();
}
