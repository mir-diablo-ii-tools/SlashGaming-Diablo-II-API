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

#include "game_branch_patch_buffer.hpp"

#include <windows.h>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include <fmt/printf.h>
#include "../../../include/c/game_address.h"
#include "../../../include/c/game_patch/game_branch_patch.h"
#include "../architecture_opcode.hpp"
#include "../../../include/cxx/game_address.hpp"
#include "../../../include/cxx/game_patch.hpp"

namespace mapi {
namespace {

void InitGameBranchPatchBuffer(
    std::uint8_t* game_patch_buffer,
    std::intptr_t raw_target_address,
    std::uint8_t opcode_value,
    std::intptr_t func_ptr,
    std::size_t patch_size
) {
  // Check that the patch size is large enough to allow the insertion of the
  // branch call.
  if (patch_size < sizeof(func_ptr) + sizeof(std::uint8_t)) {
    std::wstring error_message = fmt::sprintf(
        L"The patch size specified at address %X is too small to perform a "
        L"branch patch.",
        raw_target_address
    );

    MessageBoxW(
        nullptr,
        error_message.data(),
        L"Failed to Patch Game",
        MB_OK | MB_ICONERROR
    );
    std::exit(0);
  }

  // Fill the buffer with NOPs.
  std::fill_n(
      game_patch_buffer,
      patch_size,
      static_cast<std::uint8_t>(mapi::OpCode::kNop)
  );

  // Set the first byte in the buffer to the branch operation opcode byte.
  game_patch_buffer[0] = static_cast<std::uint8_t>(opcode_value);

  // Set the next bytes to the address of the inserted function.
  std::intptr_t func_buffer = func_ptr
      - raw_target_address
      - sizeof(std::int8_t)
      - sizeof(func_ptr);

  for (std::size_t i = 0; i < sizeof(func_buffer); i += 1) {
    game_patch_buffer[i + 1] = (func_buffer >> (i * (sizeof(game_patch_buffer[0]) * 8))) & 0xFF;
  }
}

} // namespace

std::vector<std::uint8_t>
CreateGameBranchPatchBuffer(
    const GameAddress& game_address,
    BranchType branch_type,
    void (*func_ptr)(),
    std::size_t patch_size
) {
  std::vector<std::uint8_t> branch_patch_buffer(patch_size);

  mapi::OpCode actual_branch_type = ToOpcode(branch_type);

  InitGameBranchPatchBuffer(
      branch_patch_buffer.data(),
      game_address.raw_address(),
      static_cast<std::uint8_t>(actual_branch_type),
      reinterpret_cast<std::intptr_t>(func_ptr),
      patch_size
  );

  return branch_patch_buffer;
}

} // namespace mapi

std::unique_ptr<std::uint8_t[]> MAPI_CreateGameBranchPatchBuffer(
    const MAPI_GameAddress& game_address,
    int branch_type_id,
    void (*func_ptr)(),
    std::size_t patch_size
) {
  std::unique_ptr branch_patch_buffer =
      std::make_unique<std::uint8_t[]>(patch_size);

  mapi::OpCode actual_branch_type = MAPI_ToOpcode(branch_type_id);

  mapi::InitGameBranchPatchBuffer(
      branch_patch_buffer.get(),
      game_address.raw_address,
      static_cast<std::uint8_t>(actual_branch_type),
      reinterpret_cast<std::intptr_t>(func_ptr),
      patch_size
  );

  return branch_patch_buffer;
}
