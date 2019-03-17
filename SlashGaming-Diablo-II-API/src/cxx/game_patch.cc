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

#include "../../include/cxx/game_patch.hpp"

#include <utility>

#include "architecture_opcode.hpp"
#include "../../include/cxx/game_address.hpp"
#include "game_patch/game_branch_patch_buffer.hpp"

namespace sgd2mapi {

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

GamePatch GamePatch::ToBranchPatch(
    const GameAddress& game_address,
    enum BranchType branch_type,
    void (*func_ptr)(void),
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

GamePatch GamePatch::ToBranchPatch(
    GameAddress&& game_address,
    enum BranchType branch_type,
    void (*func_ptr)(void),
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

GamePatch GamePatch::ToBufferPatch(
    const GameAddress& game_address,
    const std::uint8_t patch_buffer[],
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

GamePatch GamePatch::ToBufferPatch(
    GameAddress&& game_address,
    const std::uint8_t patch_buffer[],
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

GamePatch GamePatch::ToBufferPatch(
    const GameAddress& game_address,
    const std::vector<std::uint8_t>& patch_buffer
) {
  return GamePatch(
      game_address,
      patch_buffer
  );
}

GamePatch GamePatch::ToBufferPatch(
    GameAddress&& game_address,
    const std::vector<std::uint8_t>& patch_buffer
) {
  return GamePatch(
      std::move(game_address),
      patch_buffer
  );
}

GamePatch GamePatch::ToBufferPatch(
    const GameAddress& game_address,
    std::vector<std::uint8_t>&& patch_buffer
) {
  return GamePatch(
      game_address,
      std::move(patch_buffer)
  );
}

GamePatch GamePatch::ToBufferPatch(
    GameAddress&& game_address,
    std::vector<std::uint8_t>&& patch_buffer
) {
  return GamePatch(
      std::move(game_address),
      std::move(patch_buffer)
  );
}

GamePatch GamePatch::ToNopPatch(
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

GamePatch GamePatch::ToNopPatch(
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

} // namespace sgd2mapi
