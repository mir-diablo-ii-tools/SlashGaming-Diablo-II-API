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

#ifndef SGD2MAPI_C_GAME_CONSTANT_D2_TEXT_COLOR_H_
#define SGD2MAPI_C_GAME_CONSTANT_D2_TEXT_COLOR_H_

#include "../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

enum D2_TextColor {
  TEXT_COLOR_WHITE,
  TEXT_COLOR_RED,
  TEXT_COLOR_GREEN,
  TEXT_COLOR_BLUE,
  TEXT_COLOR_GOLD,
  TEXT_COLOR_DARK_GREY,
  TEXT_COLOR_BLACK,
  TEXT_COLOR_TAN,
  TEXT_COLOR_ORANGE,
  TEXT_COLOR_YELLOW,
  TEXT_COLOR_DARKER_GREEN,
  TEXT_COLOR_PURPLE,
  TEXT_COLOR_DARK_GREEN,

  // TEXT_COLOR_WHITE (same as 1) = 13,
  // TEXT_COLOR_BLACK (same as 6),

  TEXT_COLOR_METALLIC = 15,
  TEXT_COLOR_LIGHT_GREY,
  TEXT_COLOR_CORRUPT,
  TEXT_COLOR_BRIGHT_WHITE,
  TEXT_COLOR_DARK_RED,
  TEXT_COLOR_BROWN
};

DLLEXPORT int D2_TextColor_ToGameValue(int id);

DLLEXPORT int D2_TextColor_ToAPIValue(int value);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#include "../../dllexport_undefine.inc"
#endif // SGD2MAPI_C_GAME_CONSTANT_D2_TEXT_COLOR_H_
