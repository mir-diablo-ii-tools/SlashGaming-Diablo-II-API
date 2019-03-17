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

#include "../../../include/cxx/game_patch/game_buffer_patch.hpp"

#include <windows.h>
#include <cstdint>
#include <cstdlib>
#include <utility>
#include <vector>

#include "../../../include/cxx/game_patch/game_patch_base.hpp"

namespace sgd2mapi {

GameBufferPatch::GameBufferPatch(
    const GameAddress& game_address,
    const std::uint8_t buffer[],
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

GameBufferPatch::GameBufferPatch(
    const GameBufferPatch&
) = default;

GameBufferPatch::GameBufferPatch(
    GameBufferPatch&&
) noexcept = default;

GameBufferPatch::~GameBufferPatch(
    void
) = default;

GameBufferPatch&
GameBufferPatch::operator=(
    const GameBufferPatch&
) = default;

GameBufferPatch&
GameBufferPatch::operator=(
    GameBufferPatch&&
) noexcept = default;

GameBufferPatch*
GameBufferPatch::Clone(
    void
) const {
  return new GameBufferPatch(*this);
}

GameBufferPatch*
GameBufferPatch::MoveToClone(
    void
) {
  return new GameBufferPatch(
      std::move(this->game_address()),
      std::move(this->patch_buffer())
  );
}

} // namespace sgd2mapi
