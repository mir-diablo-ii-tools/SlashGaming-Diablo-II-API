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

#ifndef SGD2MAPI_C_GAME_CONSTANT_D2_TEXT_FONT_H_
#define SGD2MAPI_C_GAME_CONSTANT_D2_TEXT_FONT_H_

#include "../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

enum D2_TextFont {
  TEXT_FONT_FORMAL_8,
  TEXT_FONT_EXOCET_16,
  TEXT_FONT_DIABLO_MENU_30,
  TEXT_FONT_DIABLO_MENU_42,
  TEXT_FONT_FORMAL_10,
  TEXT_FONT_FORMAL_12,
  TEXT_FONT_FORMAL_6,
  TEXT_FONT_DIABLO_MENU_24,
  TEXT_FONT_FORMAL_WIDE_11,
  TEXT_FONT_EXOCET_BLACK_10,
  TEXT_FONT_EXOCET_BLACK_9,
  TEXT_FONT_EXOCET_8,

  // TEXT_FONT_FORMAL_6 (same as 6) = 12

  TEXT_FONT_FORMAL_11 = 13
};

DLLEXPORT int D2_TextFont_ToGameValue(int id);

DLLEXPORT int D2_TextFont_ToAPIValue(int value);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#include "../../dllexport_undefine.inc"
#endif // SGD2MAPI_C_GAME_CONSTANT_D2_TEXT_FONT_H_
