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

#include "../../../include/cxx/game_patch/game_nop_patch.hpp"

#include <cstdlib>
#include <memory>
#include <utility>
#include <vector>

#include "../architecture_opcode.hpp"
#include "../../../include/cxx/game_address.hpp"
#include "../../../include/cxx/game_patch/game_patch_base.hpp"

namespace sgd2mapi {

GameNopPatch::GameNopPatch(
    const GameAddress& game_address,
    std::size_t patch_size
)
    : GamePatchBase(
          game_address,
          std::vector<std::uint8_t>(
              patch_size,
              static_cast<std::uint8_t>(OpCode::kNop)
          )
      ) {
}

GameNopPatch::GameNopPatch(
    GameAddress&& game_address,
    std::size_t patch_size
)
    : GamePatchBase(
          std::move(game_address),
          std::vector<std::uint8_t>(
              patch_size,
              static_cast<std::uint8_t>(OpCode::kNop)
          )
      ) {
}

GameNopPatch::GameNopPatch(
    const GameNopPatch&
) = default;

GameNopPatch::GameNopPatch(
    GameNopPatch&&
) noexcept = default;

GameNopPatch::~GameNopPatch(
    void
) = default;

GameNopPatch&
GameNopPatch::operator=(
    const GameNopPatch&
) = default;

GameNopPatch&
GameNopPatch::operator=(
    GameNopPatch&&
) noexcept = default;

GameNopPatch*
GameNopPatch::Clone(
    void
) const {
  return new GameNopPatch(*this);
}

GameNopPatch*
GameNopPatch::MoveToClone(
    void
) {
  return new GameNopPatch(
      std::move(this->game_address()),
      std::move(this->patch_size())
  );
}

} // namespace sgd2mapi
