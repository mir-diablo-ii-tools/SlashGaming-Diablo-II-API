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

#ifndef SGD2MAPI_GAME_PATCH_GAME_NOP_PATCH_HPP_
#define SGD2MAPI_GAME_PATCH_GAME_NOP_PATCH_HPP_

#include <stdlib.h>

#include "../game_address.hpp"
#include "game_patch_base.hpp"

#ifdef __cplusplus
#include <cstdlib>
#include <memory>
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

class DLLEXPORT GameNopPatch
    : public GamePatchBase {
 public:
  /**
   * Creates a new instance of GameNopPatch, filling the patch buffer with as
   * many no-op instructions that can fit in a patch buffer of the specified
   * size.
   */
  GameNopPatch(
      const GameAddress& game_address,
      std::size_t patch_size
  );

  /**
   * Creates a new instance of GameNopPatch, filling the patch buffer with as
   * many no-op instructions that can fit in a patch buffer of the specified
   * size.
   */
  GameNopPatch(
      GameAddress&& game_address,
      std::size_t patch_size
  );

  GameNopPatch(
      const GameNopPatch&
  );

  GameNopPatch(
      GameNopPatch&&
  ) noexcept;

  ~GameNopPatch(
      void
  ) override;

  GameNopPatch&
  operator=(
      const GameNopPatch&
  );

  GameNopPatch&
  operator=(
      GameNopPatch&&
  ) noexcept;

  GameNopPatch*
  Clone(
      void
  ) const override;

  GameNopPatch*
  MoveToClone(
      void
  ) override;
};

} // namespace sgd2mapi
#endif // __cplusplus

/**
 * C Interface
 */

#if !defined(__cplusplus) || defined(SGD2MAPI_DLLEXPORT)
struct SGD2MAPI_GameNopPatch;

#ifdef __cplusplus
struct SGD2MAPI_GameNopPatch {
  std::shared_ptr<sgd2mapi::GameNopPatch> actual_ptr;
};

extern "C" {
#endif // __cplusplus

/**
 * Creates a new GameNopPatch. The patch buffer is filled with no-op
 * instructions to fill at most the specified number of bytes.
 */
DLLEXPORT struct SGD2MAPI_GameNopPatch*
SGD2MAPI_GameNopPatch_Create(
    const struct SGD2MAPI_GameAddress* c_game_address,
    size_t patch_size
);

/**
 * Creates a new GameNopPatch, upcasted to a GamePatchBase. The patch buffer
 * is filled with no-op instructions to fill at most the specified number of
 * bytes.
 */
DLLEXPORT struct SGD2MAPI_GamePatchBase*
SGD2MAPI_GameNopPatch_CreateAsGamePatchBase(
    const struct SGD2MAPI_GameAddress* c_game_address,
    size_t patch_size
);

/**
 * Creates a new GameNopPatch, upcasted to a GamePatchInterface. The patch
 * buffer is filled with no-op instructions to fill at most the specified
 * number of bytes.
 */
DLLEXPORT struct SGD2MAPI_GamePatchInterface*
SGD2MAPI_GameNopPatch_CreateAsGamePatchInterface(
    const struct SGD2MAPI_GameAddress* c_game_address,
    size_t patch_size
);

/**
 * Frees the memory used by the specified game patch.
 */
DLLEXPORT void SGD2MAPI_GameNopPatch_Destroy(
    struct SGD2MAPI_GameNopPatch* c_game_nop_patch
);

/**
 * Creates an upcast of the specified game patch to a GamePatchBase.
 */
DLLEXPORT struct SGD2MAPI_GamePatchBase*
SGD2MAPI_GameNopPatch_UpcastToGamePatchBase(
    struct SGD2MAPI_GameNopPatch* c_game_nop_patch
);

/**
 * Creates an upcast of the specified game patch to a
 * GamePatchBase and destroys the specified game patch.
 */
DLLEXPORT struct SGD2MAPI_GamePatchBase*
SGD2MAPI_GameNopPatch_UpcastToGamePatchBaseThenDestroy(
    struct SGD2MAPI_GameNopPatch* c_game_nop_patch
);

/**
 * Creates an upcast of the specified game patch to a GamePatchInterface.
 */
DLLEXPORT struct SGD2MAPI_GamePatchInterface*
SGD2MAPI_GameNopPatch_UpcastToGamePatchInterface(
    struct SGD2MAPI_GameNopPatch* c_game_nop_patch
);

/**
 * Creates an upcast of the specified game patch to a GamePatchInterface and
 * destroys the specified game patch.
 */
DLLEXPORT struct SGD2MAPI_GamePatchInterface*
SGD2MAPI_GameNopPatch_UpcastToGamePatchInterfaceThenDestroy(
    struct SGD2MAPI_GameNopPatch* c_game_nop_patch
);

/**
 * Applies the game patch by replacing the bytes at its target address with the
 * bytes stored in its buffer.
 */
DLLEXPORT void
SGD2MAPI_GameNopPatch_Apply(
    struct SGD2MAPI_GameNopPatch* c_game_nop_patch
);

/**
 * Removes the effects of the game patch by restoring the original state of the
 * bytes at its target address.
 */
DLLEXPORT void
SGD2MAPI_GameNopPatch_Remove(
    struct SGD2MAPI_GameNopPatch* c_game_nop_patch
);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !defined(__cplusplus) || defined(SGD2MAPI_DLLEXPORT)

#undef DLLEXPORT
#endif // SGD2MAPI_GAME_PATCH_GAME_NOP_PATCH_HPP_
