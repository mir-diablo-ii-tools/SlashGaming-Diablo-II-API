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

/**
 * Latest supported version: 1.14D
 */

#include "../../../../include/cxx/game_data/d2client/d2client_game_type.hpp"

#include <cstdint>

#include "../../../cxx/game_address_table.hpp"
#include "../../../../include/cxx/game_version.hpp"

namespace d2::d2client {
namespace {

std::intptr_t D2Client_GameType() {
  static std::intptr_t ptr = mapi::GetGameAddress(__func__)
      .raw_address();

  return ptr;
}

} // namespace

ClientGameType GetGameType_ApiValue() {
  return ToAPIValue<ClientGameType>(GetGameType_GameValue());
}

void SetGameType_ApiValue(ClientGameType value) {
  SetGameType_GameValue(ToGameValue(value));
}

int GetGameType_GameValue() {
  std::intptr_t ptr = D2Client_GameType();
  int value;

  std::int32_t* converted_ptr = reinterpret_cast<std::int32_t*>(ptr);
  value = *converted_ptr;

  return value;
}

void SetGameType_GameValue(int value) {
  std::intptr_t ptr = D2Client_GameType();

  std::int32_t* converted_ptr = reinterpret_cast<std::int32_t*>(ptr);
  *converted_ptr = value;
}

} // namespace d2::d2client
