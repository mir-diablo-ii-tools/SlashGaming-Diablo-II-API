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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_CONTEXT_D2_CEL_CONTEXT_IMPL_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_CONTEXT_D2_CEL_CONTEXT_IMPL_HPP_

#include "../../../../include/cxx/game_struct/d2_cel_context.hpp"

#include "../d2_cel_file/d2_cel_file_impl.hpp"
#include "../../../../include/cxx/game_undefined.hpp"

namespace d2 {

#pragma pack(push, 1)

/* sizeof: 0x48 */ struct CelContext_1_00 {
  /* 0x00 */ mapi::UndefinedByte unknown_0x00;
  /* 0x04 */ CelFile* cel_file; // TODO (Mir Drualga): Replace with 1.00 implementation.
  /* 0x08 */ std::int32_t frame;
  /* 0x0C */ std::int32_t direction;
  /* 0x10 */ mapi::UndefinedByte unknown_0x10[0x48 - 0x10];
};

/* sizeof: 0x48 */ struct CelContext_1_12A {
  /* 0x00 */ mapi::UndefinedByte unknown_0x00[0x38 - 0x00];
  /* 0x38 */ std::int32_t direction;
  /* 0x3C */ CelFile* cel_file; // TODO (Mir Drualga): Replace with 1.12A implementation.
  /* 0x40 */ std::int32_t frames;
  /* 0x44 */ mapi::UndefinedByte unknown_0x44[0x48 - 0x44];
};

/* sizeof: 0x48 */ struct CelContext_1_13C {
  /* 0x00 */ std::int32_t frame;
  /* 0x04 */ mapi::UndefinedByte unknown_0x04[0x34 - 0x04];
  /* 0x34 */ CelFile* cel_file;  // TODO (Mir Drualga): Replace with 1.13C implementation.
  /* 0x38 */ mapi::UndefinedByte unknown_0x38[0x40 - 0x38];
  /* 0x40 */ std::int32_t direction;
  /* 0x44 */ mapi::UndefinedByte unknown_0x44[0x48 - 0x44];
};

#pragma pack(pop)

CelContext* CreateCelContext(
    CelFile* cel_file,
    int direction,
    int frame
);
CelContext* CreateCelContextArray(std::size_t count);
void DestroyCelContext(CelContext* cel_context);

} // namespace d2

#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_CONTEXT_D2_CEL_CONTEXT_IMPL_HPP_
