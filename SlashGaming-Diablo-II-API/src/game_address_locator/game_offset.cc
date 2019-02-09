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

#include "../../include/game_address_locator/game_offset.h"

#include <cstdint>
#include <memory>
#include <utility>

#include "../../include/game_address_locator/game_address_locator_interface.h"

namespace sgd2mapi {

GameOffset::GameOffset(
    std::intptr_t offset
)
    : offset_(offset) {
}

GameOffset::GameOffset(
    const GameOffset&
) = default;

GameOffset::GameOffset(
    GameOffset&&
) noexcept = default;

GameOffset::~GameOffset(
    void
) = default;

GameOffset&
GameOffset::operator=(
    const GameOffset&
) = default;

GameOffset&
GameOffset::operator=(
    GameOffset&&
) noexcept = default;

GameOffset*
GameOffset::Clone(
    void
) const {
  return new GameOffset(*this);
}

GameOffset*
GameOffset::MoveToClone(
    void
) {
  return new GameOffset(
      std::move(this->offset_)
  );
}

std::intptr_t
GameOffset::ResolveGameAddress(
    std::intptr_t base_address
) const {
  return base_address + offset();
}

std::intptr_t
GameOffset::offset(
    void
) const noexcept {
  return offset_;
}

} // namespace sgd2mapi

/**
 * C Interface
 */

struct SGD2MAPI_GameOffset*
SGD2MAPI_GameOffset_Create(
    std::intptr_t offset
) {
  struct SGD2MAPI_GameOffset* c_game_offset = new SGD2MAPI_GameOffset;
  c_game_offset->actual_ptr =
      std::make_shared<sgd2mapi::GameOffset>(
          offset
      );

  return c_game_offset;
}

struct SGD2MAPI_GameAddressLocatorInterface*
SGD2MAPI_GameOffset_CreateAsGameAddressLocatorInterface(
    std::intptr_t offset
) {
  struct SGD2MAPI_GameAddressLocatorInterface*
      c_game_address_locator_interface =
          new SGD2MAPI_GameAddressLocatorInterface;

  c_game_address_locator_interface->actual_ptr =
      std::make_shared<sgd2mapi::GameOffset>(
          offset
      );

  return c_game_address_locator_interface;
}

void
SGD2MAPI_GameOffset_Destroy(
    struct SGD2MAPI_GameOffset* c_game_offset
) {
  delete c_game_offset;
}

struct SGD2MAPI_GameAddressLocatorInterface*
SGD2MAPI_GameOffset_UpcastToGameAddressLocatorInterface(
    struct SGD2MAPI_GameOffset* c_game_offset
) {
  struct SGD2MAPI_GameAddressLocatorInterface*
      c_game_address_locator_interface =
          new SGD2MAPI_GameAddressLocatorInterface;
  c_game_address_locator_interface->actual_ptr = c_game_offset->actual_ptr;

  return c_game_address_locator_interface;
}

struct SGD2MAPI_GameAddressLocatorInterface*
SGD2MAPI_GameOffset_UpcastToGameAddressLocatorInterfaceThenDestroy(
    struct SGD2MAPI_GameOffset* c_game_offset
) {
  struct SGD2MAPI_GameAddressLocatorInterface*
      c_game_address_locator_interface =
          new SGD2MAPI_GameAddressLocatorInterface;

  SGD2MAPI_GameOffset_Destroy(c_game_offset);

  return c_game_address_locator_interface;
}

std::intptr_t
SGD2MAPI_GameOffset_GetOffset(
    const struct SGD2MAPI_GameOffset* c_game_offset
) {
  return c_game_offset->actual_ptr->offset();
}
