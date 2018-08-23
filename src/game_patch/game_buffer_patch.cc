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

#include "../../include/game_patch/game_buffer_patch.h"

#include <windows.h>
#include <cstdint>
#include <cstdlib>
#include <utility>
#include <vector>

#include "../c_interface/game_address.h"
#include "c_interface/game_buffer_patch.h"
#include "c_interface/game_patch_base.h"
#include "../../include/game_patch/game_patch_base.h"

namespace sgd2mapi {

GameBufferPatch::GameBufferPatch(
    const GameAddress& game_address,
    const std::uint8_t* buffer,
    std::size_t patch_size
)
    : GamePatchBase(
          game_address,
          std::vector<std::uint8_t>(buffer, buffer + patch_size)
      ) {
}

GameBufferPatch::GameBufferPatch(
    const GameAddress& game_address,
    const std::vector<std::uint8_t>& buffer
)
    : GamePatchBase(game_address, buffer) {
}

GameBufferPatch::GameBufferPatch(
    GameAddress&& game_address,
    const std::vector<std::uint8_t>& buffer
)
    : GamePatchBase(std::move(game_address), buffer) {
}

GameBufferPatch::GameBufferPatch(
    const GameAddress& game_address,
    std::vector<std::uint8_t>&& buffer
)
    : GamePatchBase(game_address, std::move(buffer)) {
}

GameBufferPatch::GameBufferPatch(
    GameAddress&& game_address,
    std::vector<std::uint8_t>&& buffer
)
    : GamePatchBase(std::move(game_address), std::move(buffer)) {
}

GameBufferPatch::GameBufferPatch(const GameBufferPatch&) = default;

GameBufferPatch::GameBufferPatch(GameBufferPatch&&) noexcept = default;

GameBufferPatch::~GameBufferPatch() = default;

GameBufferPatch& GameBufferPatch::operator=(const GameBufferPatch&)
    = default;

GameBufferPatch& GameBufferPatch::operator=(GameBufferPatch&&)
    noexcept = default;

} // namespace sgd2mapi

/**
 * C Interface
 */

void sgd2mapi_game_buffer_patch_create_as_game_buffer_patch(
    struct SGD2MAPI_GameBufferPatch* dest,
    const struct SGD2MAPI_GameAddress* game_address,
    const std::uint8_t buffer[],
    std::size_t patch_size
) {
  dest->game_buffer_patch = new sgd2mapi::GameBufferPatch(
      *(game_address->game_address),
      buffer,
      patch_size
  );
}

void sgd2mapi_game_buffer_patch_create_as_game_patch_base(
    struct SGD2MAPI_GamePatchBase* dest,
    const struct SGD2MAPI_GameAddress* game_address,
    const std::uint8_t buffer[],
    std::size_t patch_size
) {
  struct SGD2MAPI_GameBufferPatch game_buffer_patch;
  sgd2mapi_game_buffer_patch_create_as_game_buffer_patch(
      &game_buffer_patch,
      game_address,
      buffer,
      patch_size
  );

  sgd2mapi_game_buffer_patch_upcast_to_game_patch_base(
      dest,
      &game_buffer_patch
  );
}

void sgd2mapi_game_buffer_patch_destroy(
    struct SGD2MAPI_GameBufferPatch* game_buffer_patch
) {
  delete game_buffer_patch->game_buffer_patch;
}

void sgd2mapi_game_buffer_patch_upcast_to_game_patch_base(
    struct SGD2MAPI_GamePatchBase* dest,
    const struct SGD2MAPI_GameBufferPatch* game_buffer_patch
) {
  dest->game_patch_base = game_buffer_patch->game_buffer_patch;
}

void sgd2mapi_game_buffer_patch_apply(
    struct SGD2MAPI_GameBufferPatch* game_buffer_patch
) {
  game_buffer_patch->game_buffer_patch->Apply();
}

void sgd2mapi_game_buffer_patch_remove(
    struct SGD2MAPI_GameBufferPatch* game_buffer_patch
) {
  game_buffer_patch->game_buffer_patch->Remove();
}
