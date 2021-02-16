/**
 * SlashGaming Diablo II Modding API for C++
 * Copyright (C) 2018-2021  Mir Drualga
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

#include "../../../include/cxx/game_patch.hpp"

#include <mdc/error/exit_on_error.hpp>
#include <mdc/wchar_t/filew.h>
#include "../backend/architecture_opcode.hpp"

namespace mapi {

GamePatch GamePatch::MakeGameBackBranchPatch(
    const GameAddress& game_address,
    BranchType branch_type,
    void (*func_ptr)(),
    std::size_t patch_size
) {
  return GamePatch::MakeGameBackBranchPatch(
      GameAddress(game_address),
      branch_type,
      func_ptr,
      patch_size
  );
}

GamePatch GamePatch::MakeGameBackBranchPatch(
    GameAddress&& game_address,
    BranchType branch_type,
    void (*func_ptr)(),
    std::size_t patch_size
) {
  // Fill the buffer with NOPs.
  std::vector<std::uint8_t> branch_patch_buffer(
      patch_size,
      static_cast<std::uint8_t>(OpCode::kNop)
  );

  // Check that the patch size is large enough to allow the insertion of the
  // branch call.
  if (patch_size < kBranchPatchMinSize) {
    ::mdc::error::ExitOnGeneralError(
        L"Error",
        L"The specified back branch patch at 0x%X requires a minimum "
            L"size of %u bytes. The size specified is %u.",
        __FILEW__,
        __LINE__,
        game_address.raw_address(),
        kBranchPatchMinSize,
        patch_size
    );

    return GamePatch(
        GameAddress::FromOffset(L"", 0),
        {}
    );
  }

  // Set the (last - sizeof(func_ptr)) byte in the buffer to the branch
  // operation opcode byte.
  std::size_t back_branch_start = patch_size
      - (sizeof(func_ptr) + sizeof(std::uint8_t));

  OpCode branch_opcode_value = ToOpcode(branch_type);

  branch_patch_buffer.at(back_branch_start) =
      static_cast<std::uint8_t>(branch_opcode_value);

  // Set the next bytes to the address of the inserted function.
  std::intptr_t func_buffer = reinterpret_cast<std::intptr_t>(func_ptr)
      - game_address.raw_address()
      - patch_size;

  for (std::size_t i = 0; i < sizeof(func_buffer); i += 1) {
    branch_patch_buffer.at(i + (back_branch_start + 1)) =
        (func_buffer >> (i * (sizeof(branch_patch_buffer.at(0)) * 8))) & 0xFF;
  }

  return GamePatch(
      std::move(game_address),
      std::move(branch_patch_buffer)
  );
}

} // namespace mapi
