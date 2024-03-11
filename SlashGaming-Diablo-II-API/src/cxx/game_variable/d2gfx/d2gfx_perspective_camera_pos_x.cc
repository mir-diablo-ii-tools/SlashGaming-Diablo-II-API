/**
 * SlashGaming Diablo II Modding API for C++
 * Copyright (C) 2018-2022  Mir Drualga
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

#include "../../../../include/cxx/game_variable/d2gfx/d2gfx_perspective_camera_pos_x.hpp"

#include "../../../../include/cxx/default_game_library.hpp"
#include "../../backend/game_address_table.hpp"

namespace d2::d2gfx {
namespace {

static const mapi::GameAddress& GetGameAddress() {
  static const mapi::GameAddress game_address = mapi::LoadGameAddress(
      ::d2::DefaultLibrary::kD2GFX,
      "PerspectiveCameraPosX"
  );

  return game_address;
}

} // namespace

std::uint32_t GetPerspectiveCameraPosX() {
  return GetPerspectiveCameraPosX_1_00();
}

std::uint32_t GetPerspectiveCameraPosX_1_00() {
  std::intptr_t raw_address = GetGameAddress().raw_address();
  return *reinterpret_cast<std::uint32_t*>(raw_address);
}

void SetPerspectiveCameraPosX(std::uint32_t x) {
  SetPerspectiveCameraPosX_1_00(x);
}

void SetPerspectiveCameraPosX_1_00(std::uint32_t x) {
  std::intptr_t raw_address = GetGameAddress().raw_address();
  *reinterpret_cast<std::uint32_t*>(raw_address) = x;
}

} // namespace d2::d2gfx
