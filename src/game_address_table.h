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

#ifndef SGD2MAPI_GAME_ADDRESS_TABLE_H_
#define SGD2MAPI_GAME_ADDRESS_TABLE_H_

#include <cstdint>
#include <string>
#include <string_view>
#include <unordered_map>

#include "../include/game_address.h"

namespace sgd2mapi {

class GameAddressTable {
 public:
  GameAddressTable(const GameAddressTable&) = delete;
  GameAddressTable(GameAddressTable&&) = delete;

  GameAddressTable& operator=(const GameAddressTable&) = delete;
  GameAddressTable& operator=(GameAddressTable&&) = delete;

  static std::intptr_t GetAddress(std::string_view address_name);

 private:
  std::unordered_map<std::string, std::intptr_t> address_table_;

  explicit GameAddressTable(std::string_view table_path);
  static const GameAddressTable& GetInstance();
};

} // namespace sgd2mapi

#endif // SGD2MAPI_GAME_ADDRESS_TABLE_H_
