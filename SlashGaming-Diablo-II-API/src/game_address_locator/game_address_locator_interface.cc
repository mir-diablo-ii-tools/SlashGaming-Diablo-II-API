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

#include "../../include/game_address_locator/game_address_locator_interface.h"

#include <cstdint>

namespace sgd2mapi {

GameAddressLocatorInterface::~GameAddressLocatorInterface(
    void
) = default;

} // namespace sgd2mapi

SGD2MAPI_GameAddressLocatorInterface::~SGD2MAPI_GameAddressLocatorInterface(
    void
) = default;

/**
 * C Interface
 */

void
SGD2MAPI_GameAddressLocatorInterface_Destroy(
    struct SGD2MAPI_GameAddressLocatorInterface*
        c_game_address_locator_interface
) {
  delete c_game_address_locator_interface;
}

struct SGD2MAPI_GameAddressLocatorInterface*
SGD2MAPI_GameAddressLocatorInterface_Clone(
    const struct SGD2MAPI_GameAddressLocatorInterface*
        c_game_address_locator_interface
) {
  return c_game_address_locator_interface->Clone();
}

std::intptr_t
SGD2MAPI_GameAddressLocatorInterface_ResolveGameAddress(
    const struct SGD2MAPI_GameAddressLocatorInterface*
        c_game_address_locator_interface,
    std::intptr_t base_address
) {
  return c_game_address_locator_interface->ResolveGameAddress(base_address);
}
