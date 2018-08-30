/**
 * SlashGaming Diablo II Modding API
 * Copyright (C) 2018  SlashGaming Community
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
 *  the game, provided that the game or its libraries do not link to this
 *  Program.
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any Glide wrapper (or a modified version of that library),
 *  containing parts not covered by a compatible license, provided that the
 *  wrapper does not link to this Program, the licensors of this Program
 *  grant you additional permission to convey the resulting work.
 */

#ifndef SGD2MAPI_GAME_PATCH_GAME_NOP_PATCH_H_
#define SGD2MAPI_GAME_PATCH_GAME_NOP_PATCH_H_

#include <stdlib.h>

#include "../game_address.h"
#include "game_patch_base.h"

#ifdef __cplusplus
#include <cstdlib>
#endif // __cplusplus

#if defined(SGD2MAPI_DLLEXPORT)
#define DLLEXPORT __declspec(dllexport)
#elif defined(SGD2MAPI_DLLIMPORT)
#define DLLEXPORT __declspec(dllimport)
#else
#define DLLEXPORT
#endif

#ifdef __cplusplus
namespace sgd2mapi {

class DLLEXPORT GameNopPatch : public GamePatchBase {
 public:
  GameNopPatch(
      const GameAddress& game_address,
      std::size_t patch_size
  );

  GameNopPatch(
      GameAddress&& game_address,
      std::size_t patch_size
  );

  ~GameNopPatch() override;
};

} // namespace sgd2mapi
#endif // __cplusplus

/**
 * C Interface
 */

struct SGD2MAPI_GameNopPatch;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

DLLEXPORT void sgd2mapi_game_nop_patch_create_as_game_nop_patch(
    struct SGD2MAPI_GameNopPatch* dest,
    const struct SGD2MAPI_GameAddress* game_address,
    size_t patch_size
);

DLLEXPORT void sgd2mapi_game_nop_patch_create_as_game_patch_base(
    struct SGD2MAPI_GamePatchBase* dest,
    const struct SGD2MAPI_GameAddress* game_address,
    size_t patch_size
);

/**
 * Initializes the specified destination with a new GameNopPatch, filling the
 * patch buffer with as many no-op instructions that can fit in a patch buffer
 * of the specified size.
 */
#define sgd2mapi_game_nop_patch_create( \
    dest \
) _Generic( \
    (dest), \
    struct SGD2MAPI_GameNopPatch*: \
        sgd2mapi_game_nop_patch_create_as_game_nop_patch, \
    struct SGD2MAPI_GamePatchBase*: \
        sgd2mapi_game_nop_patch_create_as_game_patch_base \
)(dest)

/**
 * Frees the memory used by the specified game patch.
 */
DLLEXPORT void sgd2mapi_game_nop_patch_destroy(
    struct SGD2MAPI_GameNopPatch* game_nop_patch
);

DLLEXPORT void sgd2mapi_game_nop_patch_upcast_to_game_patch_base(
    struct SGD2MAPI_GamePatchBase* dest,
    const struct SGD2MAPI_GameNopPatch* src
);

/**
 * Upcasts the game patch to a parent type, into the destination.
 */
#define sgd2mapi_game_nop_patch_upcast( \
    dest, \
    src \
) _Generic( \
    (dest), \
    struct SGD2MAPI_GamePatchBase*: \
        sgd2mapi_game_nop_patch_upcast_to_game_patch_base \
)(dest, src)

/**
 * Applies the game patch by replacing the bytes at its target address with the
 * bytes stored in its buffer.
 */
DLLEXPORT void sgd2mapi_game_nop_patch_apply(
    struct SGD2MAPI_GameNopPatch* game_nop_patch
);

/**
 * Removes the effects of the game patch by restoring the original state of the
 * bytes at its target address.
 */
DLLEXPORT void sgd2mapi_game_nop_patch_remove(
    struct SGD2MAPI_GameNopPatch* game_nop_patch
);

#ifdef __cplusplus
}
#endif // __cplusplus

#undef DLLEXPORT
#endif // SGD2MAPI_GAME_PATCH_GAME_NOP_PATCH_H_
