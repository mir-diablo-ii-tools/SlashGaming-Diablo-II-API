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

#ifndef SGD2MAPI_CXX_GAME_CONSTANT_D2_SCREEN_OPEN_MODE_HPP_
#define SGD2MAPI_CXX_GAME_CONSTANT_D2_SCREEN_OPEN_MODE_HPP_

#include <cstdint>

#include "../../d2api_version.h"

#include "../../dllexport_define.inc"

namespace d2 {

/**
 * Generic enum definitions
 */

enum class ScreenOpenMode {
  kNone,
  kRight,
  kLeft,
  kBoth
};

/**
 * Version-specific enum definitions
 */

enum class ScreenOpenMode_1_07 : std::uint32_t {
  kNone,
  kRight,
  kLeft,
  kBoth
};

/**
 * Function declarations
 */

namespace screen_open_mode {

DLLEXPORT int ToGameValue(ScreenOpenMode api_value);

DLLEXPORT ScreenOpenMode_1_07 ToGameValue_1_07(ScreenOpenMode api_value);

DLLEXPORT ScreenOpenMode ToApiValue(int game_value);

DLLEXPORT ScreenOpenMode ToApiValue_1_07(ScreenOpenMode_1_07 game_value);

/**
 * SGD2MAPI98 Compatability
 */

namespace api {

using enum ScreenOpenMode;

} // namespace api

namespace v1_07 {

using enum ScreenOpenMode_1_07;

} // namespace v1_07

} // namespace screen_open_mode

} // namespace d2

#include "../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_CONSTANT_D2_SCREEN_OPEN_MODE_HPP_
