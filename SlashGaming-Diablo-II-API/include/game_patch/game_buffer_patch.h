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

#ifndef SGD2MAPI_GAME_PATCH_GAME_BUFFER_PATCH_H_
#define SGD2MAPI_GAME_PATCH_GAME_BUFFER_PATCH_H_

#include <stdint.h>
#include <stdlib.h>

#include "../game_address.h"
#include "game_patch_base.h"

#ifdef __cplusplus
#include <cstdint>
#include <cstdlib>
#include <memory>
#include <vector>
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

/**
 * A patch that replaces the bytes at a destination address with 8-bit bytes
 * stored in a buffer.
 */
class DLLEXPORT GameBufferPatch
    : public GamePatchBase {
 public:
  /**
   * Creates an instance of GameBufferPatch, specifying the patch buffer with
   * an array of 8-bit bytes.
   */
  GameBufferPatch(
      const GameAddress& game_address,
      const std::uint8_t buffer[],
      std::size_t patch_size
  );

  /**
   * Creates an instance of GameBufferPatch, specifying the patch buffer with a
   * vector of 8-bit bytes.
   */
  GameBufferPatch(
      const GameAddress& game_address,
      const std::vector<std::uint8_t>& buffer
  );

  /**
   * Creates an instance of GameBufferPatch, specifying the patch buffer with a
   * vector of 8-bit bytes.
   */
  GameBufferPatch(
      GameAddress&& game_address,
      const std::vector<std::uint8_t>& buffer
  );

  /**
   * Creates an instance of GameBufferPatch, specifying the patch buffer with a
   * vector of 8-bit bytes.
   */
  GameBufferPatch(
      const GameAddress& game_address,
      std::vector<std::uint8_t>&& buffer
  );

  /**
   * Creates an instance of GameBufferPatch, specifying the patch buffer with a
   * vector of 8-bit bytes.
   */
  GameBufferPatch(
      GameAddress&& game_address,
      std::vector<std::uint8_t>&& buffer
  );

  GameBufferPatch(
      const GameBufferPatch&
  );

  GameBufferPatch(
      GameBufferPatch&&
  ) noexcept;

  ~GameBufferPatch(
      void
  ) override;

  GameBufferPatch&
  operator=(
      const GameBufferPatch&
  );

  GameBufferPatch&
  operator=(
      GameBufferPatch&&
  ) noexcept;
};

} // namespace sgd2mapi
#endif // __cplusplus

/**
 * C Interface
 */

#if !defined(__cplusplus) || defined(SGD2MAPI_DLLEXPORT)
struct SGD2MAPI_GameBufferPatch;

#ifdef __cplusplus
struct SGD2MAPI_GameBufferPatch {
  std::shared_ptr<sgd2mapi::GameBufferPatch> actual_ptr;
};

extern "C" {
#endif // __cplusplus

/**
 * Creates a new GameNopPatch. The patch buffer is specified as an array
 * of 8-bit integrals.
 */
DLLEXPORT struct SGD2MAPI_GameBufferPatch*
SGD2MAPI_GameBufferPatch_Create(
    const struct SGD2MAPI_GameAddress* c_game_address,
    const uint8_t buffer[],
    size_t patch_size
);

/**
 * Creates a new GameNopPatch, upcasted to a GamePatchBase. The patch buffer is
 * specified as an array of 8-bit integrals.
 */
DLLEXPORT struct SGD2MAPI_GamePatchBase*
SGD2MAPI_GameBufferPatch_CreateAsGamePatchBase(
    const struct SGD2MAPI_GameAddress* c_game_address,
    const uint8_t buffer[],
    size_t patch_size
);

/**
 * Frees the memory used by the specified game patch.
 */
DLLEXPORT void SGD2MAPI_GameBufferPatch_Destroy(
    struct SGD2MAPI_GameBufferPatch* c_game_buffer_patch
);

/**
 * Creates an upcast of the specified game patch to a
 * GamePatchBase.
 */
DLLEXPORT struct SGD2MAPI_GamePatchBase*
SGD2MAPI_GameBufferPatch_UpcastToGamePatchBase(
    struct SGD2MAPI_GameBufferPatch* c_game_buffer_patch
);

/**
 * Creates an upcast of the specified game patch to a
 * GamePatchBase and destroys the specified game patch.
 */
DLLEXPORT struct SGD2MAPI_GamePatchBase*
SGD2MAPI_GameBufferPatch_UpcastToGamePatchBaseThenDestroy(
    struct SGD2MAPI_GameBufferPatch* c_game_buffer_patch
);

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

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !defined(__cplusplus) || defined(SGD2MAPI_DLLEXPORT)

#undef DLLEXPORT
#endif // SGD2MAPI_GAME_PATCH_GAME_BUFFER_PATCH_H_
