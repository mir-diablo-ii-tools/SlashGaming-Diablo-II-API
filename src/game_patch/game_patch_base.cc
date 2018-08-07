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

#include "game_patch_base.h"

#include <cstdint>
#include <cstdlib>
#include <cstring>

#include "../game_address.h"

namespace sgd2mapi {

GamePatchBase::GamePatchBase(
    const GameAddress& game_address,
    size_t patch_size) noexcept
    : game_address_(game_address),
      patch_size_(patch_size),
      old_bytes_(game_address.address(),
                 game_address.address() + patch_size) {
}

GamePatchBase::GamePatchBase(const GamePatchBase&) = default;

GamePatchBase::GamePatchBase(GamePatchBase&&) = default;

GamePatchBase::~GamePatchBase() noexcept {
  Remove();
}

void GamePatchBase::Apply() noexcept {
  is_patch_applied_ = true;
}

void GamePatchBase::Remove() noexcept {
  if (!is_patch_applied()) {
    return;
  }

  // Restore the old state of the destination.
  std::intptr_t address = game_address().address();
  std::memcpy(reinterpret_cast<void*>(address),
              old_bytes_.data(),
              patch_size());
  is_patch_applied_ = false;
}

const GameAddress& GamePatchBase::game_address() const noexcept {
  return game_address_;
}

bool GamePatchBase::is_patch_applied() const noexcept {
  return is_patch_applied_;
}

std::size_t GamePatchBase::patch_size() const noexcept {
  return patch_size_;
}

} // namespace sgd2mapi
