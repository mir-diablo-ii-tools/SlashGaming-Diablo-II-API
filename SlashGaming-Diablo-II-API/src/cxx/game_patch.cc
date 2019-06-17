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
 *  it with any Graphics Device Interface (GDI), DirectDraw, Direct3D,
 *  Glide, OpenGL, or Rave wrapper (or modified versions of those
 *  libraries), containing parts not covered by a compatible license, the
 *  licensors of this Program grant you additional permission to convey the
 *  resulting work.
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any library (or a modified version of that library) that links
 *  to Diablo II (or a modified version of that game and its libraries),
 *  containing parts not covered by a compatible license, the licensors of
 *  this Program grant you additional permission to convey the resulting
 *  work.
 */

#include "../../include/cxx/game_patch.hpp"

#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>

#include "../../include/c/game_patch.h"
#include "architecture_opcode.hpp"
#include "../../include/cxx/game_address.hpp"
#include "game_patch/game_back_branch_patch_buffer.hpp"
#include "game_patch/game_branch_patch_buffer.hpp"

namespace mapi {

GamePatch::GamePatch(
    const GameAddress& game_address,
    const std::vector<std::uint8_t>& patch_buffer
) : game_address_(game_address),
    is_patch_applied_(false),
    patch_buffer_(patch_buffer),
    unpatched_buffer_(
        reinterpret_cast<std::uint8_t*>(game_address.raw_address()),
        reinterpret_cast<std::uint8_t*>(
            game_address.raw_address() + patch_buffer.size()
        )
    ) {
}

GamePatch::GamePatch(
    GameAddress&& game_address,
    const std::vector<std::uint8_t>& patch_buffer
) : game_address_(std::move(game_address)),
    is_patch_applied_(false),
    patch_buffer_(patch_buffer),
    unpatched_buffer_(
        reinterpret_cast<std::uint8_t*>(game_address.raw_address()),
        reinterpret_cast<std::uint8_t*>(
            game_address.raw_address() + patch_buffer.size()
        )
    ) {
}

GamePatch::GamePatch(
    const GameAddress& game_address,
    std::vector<std::uint8_t>&& patch_buffer
) : game_address_(game_address),
    is_patch_applied_(false),
    patch_buffer_(std::move(patch_buffer)),
    unpatched_buffer_(
        reinterpret_cast<std::uint8_t*>(game_address.raw_address()),
        reinterpret_cast<std::uint8_t*>(
            game_address.raw_address() + patch_buffer.size()
        )
    ) {
}

GamePatch::GamePatch(
    GameAddress&& game_address,
    std::vector<std::uint8_t>&& patch_buffer
) : game_address_(std::move(game_address)),
    is_patch_applied_(false),
    patch_buffer_(std::move(patch_buffer)),
    unpatched_buffer_(
        reinterpret_cast<std::uint8_t*>(game_address.raw_address()),
        reinterpret_cast<std::uint8_t*>(
            game_address.raw_address() + patch_buffer.size()
        )
    ) {
}

void GamePatch::Apply() {
  MAPI_GamePatch c_game_patch;
  c_game_patch.patch_size = patch_buffer_.size();
  c_game_patch.game_address.raw_address = game_address_.raw_address();
  c_game_patch.is_patch_applied = is_patch_applied_;
  c_game_patch.old_buffer = unpatched_buffer_.data();
  c_game_patch.patch_buffer = patch_buffer_.data();

  MAPI_GamePatch_Apply(&c_game_patch);

  is_patch_applied_ = c_game_patch.is_patch_applied;
}

void GamePatch::Remove() {
  MAPI_GamePatch c_game_patch;
  c_game_patch.patch_size = patch_buffer_.size();
  c_game_patch.game_address.raw_address = game_address_.raw_address();
  c_game_patch.is_patch_applied = is_patch_applied_;
  c_game_patch.old_buffer = unpatched_buffer_.data();
  c_game_patch.patch_buffer = patch_buffer_.data();

  MAPI_GamePatch_Remove(&c_game_patch);

  is_patch_applied_ = c_game_patch.is_patch_applied;
}

GamePatch GamePatch::MakeGameBackBranchPatch(
    const GameAddress& game_address,
    BranchType branch_type,
    void (*func_ptr)(),
    std::size_t patch_size
) {
  std::vector<std::uint8_t> patch_buffer = CreateGameBackBranchPatchBuffer(
      game_address,
      branch_type,
      func_ptr,
      patch_size
  );

  return GamePatch(
      game_address,
      std::move(patch_buffer)
  );
}

GamePatch GamePatch::MakeGameBackBranchPatch(
    GameAddress&& game_address,
    BranchType branch_type,
    void (*func_ptr)(),
    std::size_t patch_size
) {
  std::vector<std::uint8_t> patch_buffer = CreateGameBackBranchPatchBuffer(
      game_address,
      branch_type,
      func_ptr,
      patch_size
  );

  return GamePatch(
      std::move(game_address),
      std::move(patch_buffer)
  );
}

GamePatch GamePatch::MakeGameBranchPatch(
    const GameAddress& game_address,
    BranchType branch_type,
    void (*func_ptr)(),
    std::size_t patch_size
) {
  std::vector<std::uint8_t> patch_buffer = CreateGameBranchPatchBuffer(
      game_address,
      branch_type,
      func_ptr,
      patch_size
  );

  return GamePatch(
      game_address,
      std::move(patch_buffer)
  );
}

GamePatch GamePatch::MakeGameBranchPatch(
    GameAddress&& game_address,
    BranchType branch_type,
    void (*func_ptr)(),
    std::size_t patch_size
) {
  std::vector<std::uint8_t> patch_buffer = CreateGameBranchPatchBuffer(
      game_address,
      branch_type,
      func_ptr,
      patch_size
  );

  return GamePatch(
      std::move(game_address),
      std::move(patch_buffer)
  );
}

GamePatch GamePatch::MakeGameBufferPatch(
    const GameAddress& game_address,
    const std::uint8_t* patch_buffer,
    std::size_t patch_size
) {
  std::vector<std::uint8_t> patch_buffer_vector(
      patch_buffer,
      patch_buffer + patch_size
  );

  return GamePatch(
      game_address,
      std::move(patch_buffer_vector)
  );
}

GamePatch GamePatch::MakeGameBufferPatch(
    GameAddress&& game_address,
    const std::uint8_t* patch_buffer,
    std::size_t patch_size
) {
  std::vector<std::uint8_t> patch_buffer_vector(
      patch_buffer,
      patch_buffer + patch_size
  );

  return GamePatch(
      std::move(game_address),
      std::move(patch_buffer_vector)
  );
}

GamePatch GamePatch::MakeGameNopPatch(
    const GameAddress& game_address,
    std::size_t patch_size
) {
  std::vector<std::uint8_t> patch_buffer(
      patch_size,
      static_cast<std::uint8_t>(OpCode::kNop)
  );

  return GamePatch(
      game_address,
      std::move(patch_buffer)
  );
}

GamePatch GamePatch::MakeGameNopPatch(
    GameAddress&& game_address,
    std::size_t patch_size
) {
  std::vector<std::uint8_t> patch_buffer(
      patch_size,
      static_cast<std::uint8_t>(OpCode::kNop)
  );

  return GamePatch(
      std::move(game_address),
      std::move(patch_buffer)
  );
}

} // namespace mapi
