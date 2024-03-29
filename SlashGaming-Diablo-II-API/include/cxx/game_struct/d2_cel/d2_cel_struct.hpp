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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_D2_CEL_STRUCT_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_D2_CEL_STRUCT_HPP_

#include <cstddef>
#include <cstdint>
#include <type_traits>
#include <variant>

#include "../../game_undefined.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

/**
 * Generic struct declaration
 */

struct Cel;

/**
 * Version-specific struct definitions
 */

#pragma pack(push, 1)

// TODO (Mir Drualga): Figure out the size.
/* sizeof: 0x?? */ struct Cel_1_00 {
  /* 0x00 */ mapi::UndefinedByte unknown_0x00[0x04 - 0x00];
  /* 0x04 */ std::int32_t width;
  /* 0x08 */ std::int32_t height;
  /* 0x0C */ std::int32_t offset_x;
  /* 0x10 */ std::int32_t offset_y;
};

static_assert(std::is_standard_layout_v<Cel_1_00>);
static_assert(std::is_trivial_v<Cel_1_00>);
static_assert(sizeof(Cel_1_00) >= 0x14);
static_assert(offsetof(Cel_1_00, width) == 0x04);
static_assert(offsetof(Cel_1_00, height) == 0x08);
static_assert(offsetof(Cel_1_00, offset_x) == 0x0C);
static_assert(offsetof(Cel_1_00, offset_y) == 0x10);

#pragma pack(pop)

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_D2_CEL_STRUCT_HPP_
