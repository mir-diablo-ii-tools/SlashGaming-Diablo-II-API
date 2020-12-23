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

/**
 * Latest supported version: 1.14D
 */

#include "../../../../include/cxx/game_variable/d2client/d2client_ingame_mouse_position_x.hpp"

#include <cstdint>

#include "../../../../include/cxx/default_game_library.hpp"
#include "../../backend/game_address_table.hpp"

namespace d2::d2client {
namespace {

static const mapi::GameAddress& GetGameAddress() {
  static const mapi::GameAddress game_address = mapi::LoadGameAddress(
      ::mapi::DefaultLibrary::kD2Client,
      "IngameMousePositionX"
  );

  return game_address;
}

} // namespace

int GetIngameMousePositionX() {
  return GetIngameMousePositionX_1_00();
}

std::int32_t GetIngameMousePositionX_1_00() {
  std::intptr_t raw_address = GetGameAddress().raw_address();
  return *reinterpret_cast<std::int32_t*>(raw_address);
}

void SetIngameMousePositionX(int mouse_position_x) {
  SetIngameMousePositionX_1_00(mouse_position_x);
}

void SetIngameMousePositionX_1_00(std::int32_t mouse_position_x) {
  std::intptr_t raw_address = GetGameAddress().raw_address();
  *reinterpret_cast<std::int32_t*>(raw_address) = mouse_position_x;
}

} // namespace d2::d2client
