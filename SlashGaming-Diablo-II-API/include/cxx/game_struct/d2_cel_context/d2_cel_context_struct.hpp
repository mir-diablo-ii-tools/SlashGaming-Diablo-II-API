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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_CONTEXT_D2_CEL_CONTEXT_STRUCT_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_CONTEXT_D2_CEL_CONTEXT_STRUCT_HPP_

#include <cstddef>
#include <cstdint>
#include <type_traits>
#include <variant>

#include "../../game_undefined.hpp"
#include "../d2_cel_file/d2_cel_file_struct.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

struct CelContext;

#pragma pack(push, 1)

/* sizeof: 0x48 */ struct CelContext_1_00 {
  /* 0x00 */ mapi::UndefinedByte unknown_0x00[0x04 - 0x00];
  /* 0x04 */ CelFile_1_00* cel_file;
  /* 0x08 */ std::uint32_t frame;
  /* 0x0C */ std::uint32_t direction;
  /* 0x10 */ mapi::UndefinedByte unknown_0x10[0x48 - 0x10];
};

static_assert(std::is_standard_layout_v<CelContext_1_00>);
static_assert(std::is_trivial_v<CelContext_1_00>);
static_assert(sizeof(CelContext_1_00) == 0x48);
static_assert(offsetof(CelContext_1_00, cel_file) == 0x04);
static_assert(offsetof(CelContext_1_00, frame) == 0x08);
static_assert(offsetof(CelContext_1_00, direction) == 0x0C);

/* sizeof: 0x48 */ struct CelContext_1_12A {
  /* 0x00 */ mapi::UndefinedByte unknown_0x00[0x38 - 0x00];
  /* 0x38 */ std::uint32_t direction;
  /* 0x3C */ CelFile_1_00* cel_file;
  /* 0x40 */ std::uint32_t frame;
  /* 0x44 */ mapi::UndefinedByte unknown_0x44[0x48 - 0x44];
};

static_assert(std::is_standard_layout_v<CelContext_1_12A>);
static_assert(std::is_trivial_v<CelContext_1_12A>);
static_assert(sizeof(CelContext_1_12A) == 0x48);
static_assert(offsetof(CelContext_1_12A, cel_file) == 0x3C);
static_assert(offsetof(CelContext_1_12A, frame) == 0x40);
static_assert(offsetof(CelContext_1_12A, direction) == 0x38);

/* sizeof: 0x48 */ struct CelContext_1_13C {
  /* 0x00 */ std::uint32_t frame;
  /* 0x04 */ mapi::UndefinedByte unknown_0x04[0x34 - 0x04];
  /* 0x34 */ CelFile_1_00* cel_file;
  /* 0x38 */ mapi::UndefinedByte unknown_0x38[0x40 - 0x38];
  /* 0x40 */ std::uint32_t direction;
  /* 0x44 */ mapi::UndefinedByte unknown_0x44[0x48 - 0x44];
};

static_assert(std::is_standard_layout_v<CelContext_1_13C>);
static_assert(std::is_trivial_v<CelContext_1_13C>);
static_assert(sizeof(CelContext_1_13C) == 0x48);
static_assert(offsetof(CelContext_1_13C, cel_file) == 0x34);
static_assert(offsetof(CelContext_1_13C, frame) == 0x00);
static_assert(offsetof(CelContext_1_13C, direction) == 0x40);

#pragma pack(pop)

/**
 * STL DLL interface
 */

DLL_TEMPL_EXTERN template class DLLEXPORT std::variant<
    CelContext_1_00,
    CelContext_1_12A,
    CelContext_1_13C
>;

DLL_TEMPL_EXTERN template class DLLEXPORT std::variant<
    CelContext_1_00*,
    CelContext_1_12A*,
    CelContext_1_13C*
>;

DLL_TEMPL_EXTERN template class DLLEXPORT std::variant<
    const CelContext_1_00*,
    const CelContext_1_12A*,
    const CelContext_1_13C*
>;

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_CONTEXT_D2_CEL_CONTEXT_STRUCT_HPP_
