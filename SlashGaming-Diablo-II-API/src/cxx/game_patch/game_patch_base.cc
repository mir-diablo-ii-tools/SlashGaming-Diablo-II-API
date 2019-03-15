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

#include "../../../include/cxx/game_patch/game_patch_base.hpp"

#include <windows.h>
#include <cstdint>
#include <cstdlib>
#include <utility>
#include <vector>

#include "../../../include/cxx/game_address.hpp"

namespace sgd2mapi {

GamePatchBase::GamePatchBase(
    const GameAddress& game_address,
    const std::vector<std::uint8_t>& patch_buffer
)
    : game_address_(game_address),
      is_patch_applied_(false),
      old_bytes_(
          reinterpret_cast<std::uint8_t*>(game_address.raw_address()),
          reinterpret_cast<std::uint8_t*>(
              game_address.raw_address()
              + patch_buffer.size()
          )
      ),
      patch_buffer_(patch_buffer) {
}

GamePatchBase::GamePatchBase(
    GameAddress&& game_address,
    const std::vector<std::uint8_t>& patch_buffer
)
    : game_address_(std::move(game_address)),
      is_patch_applied_(false),
      old_bytes_(
          reinterpret_cast<std::uint8_t*>(game_address_.raw_address()),
          reinterpret_cast<std::uint8_t*>(
              game_address_.raw_address()
              + patch_buffer.size()
          )
      ),
      patch_buffer_(patch_buffer) {
}

GamePatchBase::GamePatchBase(
    const GameAddress& game_address,
    std::vector<std::uint8_t>&& patch_buffer
)
    : game_address_(game_address),
      is_patch_applied_(false),
      old_bytes_(
          reinterpret_cast<std::uint8_t*>(game_address.raw_address()),
          reinterpret_cast<std::uint8_t*>(
              game_address.raw_address()
              + patch_buffer.size()
          )
      ),
      patch_buffer_(std::move(patch_buffer)) {
}

GamePatchBase::GamePatchBase(
    GameAddress&& game_address,
    std::vector<std::uint8_t>&& patch_buffer
)
    : game_address_(std::move(game_address)),
      is_patch_applied_(false),
      old_bytes_(
          reinterpret_cast<std::uint8_t*>(game_address_.raw_address()),
          reinterpret_cast<std::uint8_t*>(
              game_address_.raw_address()
              + patch_buffer.size()
          )
      ),
      patch_buffer_(std::move(patch_buffer)) {
}

GamePatchBase::GamePatchBase(
    const GamePatchBase&
) = default;

GamePatchBase::GamePatchBase(
    GamePatchBase&&
) noexcept = default;

GamePatchBase::~GamePatchBase(
    void
) {
  Remove();
}

GamePatchBase&
GamePatchBase::operator=(
    const GamePatchBase&
) = default;

GamePatchBase&
GamePatchBase::operator=(
    GamePatchBase&&
) noexcept = default;

void
GamePatchBase::Apply(
    void
) {
  if (is_patch_applied()) {
    return;
  }

  // Replace the data at the destination with the values in the patch buffer.
  std::intptr_t address = game_address().raw_address();
  WriteProcessMemory(
      GetCurrentProcess(),
      reinterpret_cast<void*>(address),
      patch_buffer().data(),
      patch_buffer().size(),
      nullptr
  );

  is_patch_applied_ = true;
}

void
GamePatchBase::Remove(
    void
) {
  if (!is_patch_applied()) {
    return;
  }

  // Restore the old state of the destination.
  std::intptr_t address = game_address().raw_address();
  WriteProcessMemory(
      GetCurrentProcess(),
      reinterpret_cast<void*>(address),
      old_bytes_.data(),
      old_bytes_.size(),
      nullptr
  );
  is_patch_applied_ = false;
}

const GameAddress&
GamePatchBase::game_address(
    void
) const noexcept {
  return game_address_;
}

bool
GamePatchBase::is_patch_applied(
    void
) const noexcept {
  return is_patch_applied_;
}

const std::vector<std::uint8_t>&
GamePatchBase::patch_buffer(
    void
) const noexcept {
  return patch_buffer_;
}

const std::vector<std::uint8_t>&
GamePatchBase::old_bytes(
    void
) const noexcept {
  return old_bytes_;
}

std::size_t
GamePatchBase::patch_size(
    void
) const noexcept {
  return patch_buffer().size();
}

} // namespace sgd2mapi

/**
 * C Interface
 */

void
SGD2MAPI_GamePatchBase_Destroy(
    struct SGD2MAPI_GamePatchBase* c_game_patch_base
) {
  delete c_game_patch_base;
}

struct SGD2MAPI_GamePatchInterface*
SGD2MAPI_GamePatchBase_UpcastToGamePatchInterface(
    struct SGD2MAPI_GamePatchBase* c_game_patch_base
) {
  struct SGD2MAPI_GamePatchInterface* c_game_patch_interface =
      new SGD2MAPI_GamePatchInterface;

  c_game_patch_interface->actual_ptr = c_game_patch_base->actual_ptr;

  return c_game_patch_interface;
}

struct SGD2MAPI_GamePatchInterface*
SGD2MAPI_GamePatchBase_UpcastToGamePatchInterfaceThenDestroy(
    struct SGD2MAPI_GamePatchBase* c_game_patch_base
) {
  struct SGD2MAPI_GamePatchInterface* c_game_patch_interface =
      SGD2MAPI_GamePatchBase_UpcastToGamePatchInterface(
          c_game_patch_base
      );

  SGD2MAPI_GamePatchBase_Destroy(c_game_patch_base);

  return c_game_patch_interface;
}

void
SGD2MAPI_GamePatchBase_Apply(
    struct SGD2MAPI_GamePatchBase* c_game_patch_base
) {
  c_game_patch_base->actual_ptr->Apply();
}

void
SGD2MAPI_GamePatchBase_Remove(
    struct SGD2MAPI_GamePatchBase* c_game_patch_base
) {
  c_game_patch_base->actual_ptr->Remove();
}
