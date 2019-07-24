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

#ifndef SGD2MAPI_CXX_GAME_CONSTANT_D2_TEXT_FONT_HPP_
#define SGD2MAPI_CXX_GAME_CONSTANT_D2_TEXT_FONT_HPP_

#include <cstddef>

#include "d2_constant.hpp"

#include "../../dllexport_define.inc"

namespace d2 {

enum class TextFont {
  kFormal_8,
  kExocet_16,
  kDiabloMenu_30,
  kDiabloMenu_42,
  kFormal_10,
  kFormal_12,
  kFormal_6,
  kDiabloMenu_24,
  kFormalWide_11,
  kExocetBlack_10,
  kExocetBlack_9,
  kExocet_8,

  // kFormal_6 (same as 6) = 12

  kFormal_11 = 13
};

extern template DLLEXPORT
int ToGameValue(
    TextFont id
);

extern template DLLEXPORT
TextFont ToAPIValue(
    int value
);

} // namespace d2

#include "../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_CONSTANT_D2_TEXT_FONT_HPP_
