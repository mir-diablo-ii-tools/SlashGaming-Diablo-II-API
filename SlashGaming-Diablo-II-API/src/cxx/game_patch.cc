/**
 * SlashGaming Diablo II Modding API for C++
 * Copyright (C) 2018-2020  Mir Drualga
 *
 * This file is part of SlashGaming Diablo II Modding API for C++.
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

#include <windows.h>
#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>

#include <fmt/format.h>
#include "../../include/cxx/game_address.hpp"
#include "backend/architecture_opcode.hpp"
#include "backend/error_handling.hpp"

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

GamePatch::GamePatch(GamePatch&& game_patch) noexcept = default;

GamePatch::~GamePatch() = default;

GamePatch& GamePatch::operator=(GamePatch&& game_patch) noexcept = default;

void GamePatch::Apply() {
  if (this->is_patch_applied()) {
    return;
  }

  std::intptr_t raw_address = this->game_address().raw_address();

  // Restore the old state of the destination.
  BOOL write_success = WriteProcessMemory(
      GetCurrentProcess(),
      (void*) raw_address,
      this->patch_buffer().data(),
      this->patch_buffer().size(),
      nullptr
  );

  if (!write_success) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"WriteProcessMemory",
        GetLastError(),
        __FILEW__,
        __LINE__
    );
  }

  this->is_patch_applied_ = true;
}

void GamePatch::Remove() {
  if (!this->is_patch_applied()) {
    return;
  }

  std::intptr_t raw_address = this->game_address().raw_address();

  // Restore the old state of the destination.
  BOOL write_success = WriteProcessMemory(
      GetCurrentProcess(),
      (void*) raw_address,
      this->unpatched_buffer().data(),
      this->unpatched_buffer().size(),
      nullptr
  );

  if (!write_success) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"WriteProcessMemory",
        GetLastError(),
        __FILEW__,
        __LINE__
    );
  }

  this->is_patch_applied_ = false;
}

const GameAddress& GamePatch::game_address() const noexcept {
  return this->game_address_;
}

bool GamePatch::is_patch_applied() const noexcept {
  return this->is_patch_applied_;
}

const std::vector<std::uint8_t>& GamePatch::patch_buffer() const noexcept {
  return this->patch_buffer_;
}

const std::vector<std::uint8_t>&
GamePatch::unpatched_buffer() const noexcept {
  return this->unpatched_buffer_;
}

} // namespace mapi
