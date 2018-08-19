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

#include "../../include/game_address_locator/game_offset.h"

#include <cstdint>

namespace sgd2mapi {

GameOffset::GameOffset(std::intptr_t offset) noexcept
    : offset_(offset) {
}

GameOffset::GameOffset(const GameOffset&) noexcept = default;
GameOffset::GameOffset(GameOffset&&) noexcept = default;

GameOffset::~GameOffset() noexcept = default;

GameOffset& GameOffset::operator=(const GameOffset&) noexcept = default;
GameOffset& GameOffset::operator=(GameOffset&&) noexcept = default;

std::intptr_t GameOffset::ResolveGameAddress(std::intptr_t base_address)
    const noexcept {
  return base_address + offset();
}

std::intptr_t GameOffset::offset() const noexcept {
  return offset_;
}

} // namespace sgd2mapi

/**
 * C Interface
 */

struct SGD2MAPI_GameOffset {
  sgd2mapi::GameOffset* game_offset;
};

void sgd2mapi_game_offset_create(
    struct SGD2MAPI_GameOffset* game_offset,
    std::intptr_t offset
) {
  game_offset->game_offset = new sgd2mapi::GameOffset(offset);
}

void sgd2mapi_game_offset_destroy(
    struct SGD2MAPI_GameOffset* game_offset
) {
  delete game_offset->game_offset;
}

std::intptr_t sgd2mapi_game_offset_get_offset(
    const struct SGD2MAPI_GameOffset* game_offset
) {
  return game_offset->game_offset->offset();
}
