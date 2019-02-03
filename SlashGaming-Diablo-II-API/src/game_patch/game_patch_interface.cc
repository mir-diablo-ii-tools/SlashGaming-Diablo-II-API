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

#include "../../include/game_patch/game_patch_interface.h"

SGD2MAPI_GamePatchInterface::~SGD2MAPI_GamePatchInterface(
    void
) = default;

struct SGD2MAPI_GamePatchInterface*
SGD2MAPI_GamePatchInterface_Clone(
    const struct SGD2MAPI_GamePatchInterface* c_game_patch
) {
  return c_game_patch->Clone();
}

struct SGD2MAPI_GamePatchInterface*
SGD2MAPI_GamePatchInterface_MoveToClone(
    struct SGD2MAPI_GamePatchInterface* c_game_patch
) {
  return c_game_patch->MoveToClone();
}

void
SGD2MAPI_GamePatchInterface_Apply(
    struct SGD2MAPI_GamePatchInterface* c_game_patch
) {
  c_game_patch->Apply();
}

void
SGD2MAPI_GamePatchInterface_Remove(
    struct SGD2MAPI_GamePatchInterface* c_game_patch
) {
  c_game_patch->Remove();
}

bool
SGD2MAPI_GamePatchInterface_IsPatchApplied(
    const struct SGD2MAPI_GamePatchInterface* c_game_patch
) {
  return c_game_patch->is_patch_applied();
}
