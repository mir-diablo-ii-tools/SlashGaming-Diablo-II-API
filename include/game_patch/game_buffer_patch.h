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

#ifndef SGD2MAPI_GAME_PATCH_GAME_BUFFER_PATCH_H_
#define SGD2MAPI_GAME_PATCH_GAME_BUFFER_PATCH_H_

#include <stdint.h>
#include <stdlib.h>

#include "../game_address.h"
#include "game_patch_base.h"

#ifdef __cplusplus
#include <cstdint>
#include <cstdlib>
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
 * A patch that replaces the destination address with the bytes stored in a
 * buffer.
 */
class DLLEXPORT GameBufferPatch : public GamePatchBase {
 public:
  /**
   * Creates an instance of BufferPatch.
   */
  GameBufferPatch(
      const GameAddress& game_address,
      const std::uint8_t* buffer,
      std::size_t patch_size);

  /**
   * Creates an instance of BufferPatch.
   */
  GameBufferPatch(
      const GameAddress& game_address,
      const std::vector<std::uint8_t>& buffer);

  /**
   * Creates an instance of BufferPatch.
   */
  GameBufferPatch(
      GameAddress&& game_address,
      const std::vector<std::uint8_t>& buffer);

  /**
   * Creates an instance of BufferPatch.
   */
  GameBufferPatch(
      const GameAddress& game_address,
      std::vector<std::uint8_t>&& buffer);

  /**
   * Creates an instance of BufferPatch.
   */
  GameBufferPatch(
      GameAddress&& game_address,
      std::vector<std::uint8_t>&& buffer);

  GameBufferPatch(const GameBufferPatch&);

  GameBufferPatch(GameBufferPatch&&) noexcept;

  ~GameBufferPatch() override;

  GameBufferPatch& operator=(const GameBufferPatch&);

  GameBufferPatch& operator=(GameBufferPatch&&) noexcept;
};

} // namespace sgd2mapi
#endif // __cplusplus

struct SGD2MAPI_GameBufferPatch;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

DLLEXPORT void sgd2mapi_game_buffer_patch_create_as_game_buffer_patch(
    struct SGD2MAPI_GameBufferPatch* dest,
    const struct SGD2MAPI_GameAddress* game_address,
    const uint8_t buffer[],
    size_t patch_size
);

DLLEXPORT void sgd2mapi_game_buffer_patch_create_as_game_patch_base(
    struct SGD2MAPI_GamePatchBase* dest,
    const struct SGD2MAPI_GameAddress* game_address,
    const uint8_t buffer[],
    size_t patch_size
);

/**
 * Initializes the value of the specified destination with a new
 * GameBufferPatch using the specified parameters.
 */
#define sgd2mapi_game_buffer_patch_create( \
    dest, \
    game_address, \
    buffer, \
    patch_size \
) _Generic( \
    (dest), \
    struct SGD2MAPI_GameBufferPatch*: \
        sgd2mapi_game_buffer_patch_create_as_game_buffer_patch, \
    struct SGD2MAPI_GamePatchBase*: \
        sgd2mapi_game_buffer_patch_create_as_game_patch_base \
)(dest, game_address, buffer, patch_size)

DLLEXPORT void sgd2mapi_game_buffer_patch_destroy(
    struct SGD2MAPI_GameBufferPatch* game_buffer_patch
);

DLLEXPORT void sgd2mapi_game_buffer_patch_downcast_to_game_patch_base(
    struct SGD2MAPI_GamePatchBase* dest,
    const struct SGD2MAPI_GameBufferPatch* game_buffer_patch
);

#define sgd2mapi_game_buffer_patch_downcast( \
    dest, \
    game_buffer_patch \
) _Generic( \
    (dest), \
    struct SGD2MAPI_GamePatchBase*: \
        sgd2mapi_game_buffer_patch_downcast_to_game_patch_base \
)(dest, game_buffer_patch)

#ifdef __cplusplus
}
#endif // __cplusplus

#undef DLLEXPORT
#endif // SGD2MAPI_GAME_PATCH_GAME_BUFFER_PATCH_H_
