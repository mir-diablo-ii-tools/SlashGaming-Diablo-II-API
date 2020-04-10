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

#ifndef SGD2MAPI_CXX_GAME_FUNCTION_D2COMMON_D2COMMON_GET_GLOBAL_BELT_RECORD_HPP_
#define SGD2MAPI_CXX_GAME_FUNCTION_D2COMMON_D2COMMON_GET_GLOBAL_BELT_RECORD_HPP_

#include <cstdint>

#include "../../../d2api_version.h"
#include "../../game_struct/d2_belt_record/d2_belt_record_struct.hpp"

#include "../../../dllexport_define.inc"

namespace d2::d2common {

DLLEXPORT void GetGlobalBeltRecord(
    unsigned int belt_record_index,
    unsigned int inventory_arrange_mode,
    BeltRecord* out_belt_record
);

DLLEXPORT void GetGlobalBeltRecord_1_00(
    std::uint32_t belt_record_index,
    BeltRecord_1_00* out_belt_record
);

DLLEXPORT void GetGlobalBeltRecord_1_07(
    std::uint32_t belt_record_index,
    std::uint32_t inventory_arrange_mode,
    BeltRecord_1_00* out_belt_record
);

} // namespace d2::d2common

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_FUNCTION_D2COMMON_D2COMMON_GET_GLOBAL_BELT_RECORD_HPP_
