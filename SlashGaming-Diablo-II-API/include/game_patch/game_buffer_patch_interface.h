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

#ifndef SGD2MAPI_GAME_PATCH_GAME_BUFFER_PATCH_INTERFACE_H_
#define SGD2MAPI_GAME_PATCH_GAME_BUFFER_PATCH_INTERFACE_H_

struct SGD2MAPI_GameBufferPatchInterface;

/**
 * Applies the game patch by replacing the bytes at its target address
 * with the bytes stored in its buffer.
 */
DLLEXPORT void
SGD2MAPI_GameBufferPatch_Apply(
    struct SGD2MAPI_GameBufferPatch* c_game_buffer_patch
);

/**
 * Removes the effects of the game patch by restoring the original state of the
 * bytes at its target address.
 */
DLLEXPORT void
SGD2MAPI_GameBufferPatch_Remove(
    struct SGD2MAPI_GameBufferPatch* c_game_buffer_patch
);

#endif // SGD2MAPI_GAME_PATCH_GAME_BUFFER_PATCH_INTERFACE_H_
