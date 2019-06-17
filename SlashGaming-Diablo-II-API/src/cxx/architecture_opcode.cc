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

#include "architecture_opcode.hpp"

#include <unordered_map>

#include "../../include/c/game_branch_type.h"
#include "../../include/cxx/game_branch_type.hpp"

namespace mapi {

OpCode ToOpcode(BranchType branch_type) {
  using BranchTypeAndOpcodeMapType = std::unordered_map<
      BranchType,
      OpCode
  >;

  static const BranchTypeAndOpcodeMapType op_codes_by_branch_types = {
      { BranchType::kCall, OpCode::kCall },
      { BranchType::kJump, OpCode::kJump }
  };

  return op_codes_by_branch_types.at(branch_type);
}

} // namespace mapi


mapi::OpCode MAPI_ToOpcode(int branch_type) {
  using MAPI_BranchTypeAndOpcodeMapType = std::unordered_map<
      int,
      mapi::OpCode
  >;

  static const MAPI_BranchTypeAndOpcodeMapType op_codes_by_branch_types = {
      { MAPI_BranchType::BRANCH_CALL, mapi::OpCode::kCall },
      { MAPI_BranchType::BRANCH_JUMP, mapi::OpCode::kJump },
  };

  return op_codes_by_branch_types.at(branch_type);
}
