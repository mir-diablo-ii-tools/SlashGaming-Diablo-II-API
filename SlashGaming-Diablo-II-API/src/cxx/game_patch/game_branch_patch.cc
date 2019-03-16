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

#include "../../../include/cxx/game_patch/game_branch_patch.hpp"

#include <windows.h>
#include <cstdint>
#include <cstdlib>
#include <memory>
#include <utility>
#include <vector>

#include <fmt/format.h>
#include <fmt/printf.h>
#include "../architecture_opcode.hpp"
#include "../../../include/cxx/game_address.hpp"
#include "game_branch_patch_buffer.hpp"
#include "../../../include/cxx/game_patch/game_patch_base.hpp"

namespace sgd2mapi {

GameBranchPatch::GameBranchPatch(
    const GameAddress& game_address,
    enum BranchType branch_type,
    std::intptr_t func_ptr,
    std::size_t patch_size
)
    : GamePatchBase(
          game_address,
          CreateBranchPatchBuffer(
              game_address,
              branch_type,
              func_ptr,
              patch_size
          )
      ),
      branch_type_(branch_type),
      func_ptr_(func_ptr) {
}

GameBranchPatch::GameBranchPatch(
    GameAddress&& game_address,
    enum BranchType branch_type,
    std::intptr_t func_ptr,
    std::size_t patch_size
)
    : GamePatchBase(
          std::move(game_address),
          CreateBranchPatchBuffer(
              game_address,
              branch_type,
              func_ptr,
              patch_size
          )
      ),
      branch_type_(branch_type),
      func_ptr_(func_ptr) {
}

GameBranchPatch::GameBranchPatch(
    const GameBranchPatch&
) = default;

GameBranchPatch::GameBranchPatch(
    GameBranchPatch&&
) noexcept = default;

GameBranchPatch::~GameBranchPatch(
    void
) = default;

GameBranchPatch&
GameBranchPatch::operator=(
    const GameBranchPatch&
) = default;

GameBranchPatch&
GameBranchPatch::operator=(
    GameBranchPatch&&
) noexcept = default;

enum BranchType
GameBranchPatch::branch_type(
    void
) const noexcept {
  return branch_type_;
}

std::intptr_t
GameBranchPatch::func_ptr(
    void
) const noexcept {
  return func_ptr_;
}

GameBranchPatch*
GameBranchPatch::Clone(
    void
) const {
  return new GameBranchPatch(*this);
}

GameBranchPatch*
GameBranchPatch::MoveToClone(
    void
) {
  return new GameBranchPatch(
      std::move(this->game_address()),
      std::move(this->branch_type_),
      std::move(this->func_ptr_),
      std::move(this->patch_size())
  );
}

} // namespace sgd2mapi
