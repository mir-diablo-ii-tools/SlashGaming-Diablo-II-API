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
 *  it with any Glide wrapper (or a modified version of that library),
 *  containing parts not covered by a compatible license, the licensors of
 *  this Program grant you additional permission to convey the resulting
 *  work.
 */

#include "../../include/game_patch/game_branch_patch.h"

#include <windows.h>
#include <cstdint>
#include <cstdlib>
#include <memory>
#include <utility>
#include <vector>

#include <fmt/format.h>
#include <fmt/printf.h>
#include "../architecture_opcode.h"
#include "../../include/game_address.h"
#include "../../include/game_patch/game_patch_base.h"

#include "../c/game_address.h"
#include "c/game_branch_patch.h"
#include "c/game_patch_base.h"

namespace sgd2mapi {

namespace {

using BranchTypeAndOpcodeMapType = std::unordered_map<
    enum BranchType,
    enum OpCode
>;

#if defined(__i386__) || defined(_M_IX86)
const BranchTypeAndOpcodeMapType&
GetOpCodeByBranchTypeMap(
    void
) {
  static const BranchTypeAndOpcodeMapType op_code_by_branch_type = {
      { BranchType::kCall, OpCode::kCall },
      { BranchType::kJump, OpCode::kJump }
  };

  return op_code_by_branch_type;
}

std::vector<std::uint8_t>
CreateReplaceBuffer(
    enum BranchType branch_type,
    std::intptr_t func_ptr,
    const GameAddress& game_address,
    std::size_t patch_size
) {

  // Check that the patch size is large enough to allow the insertion of the
  // branch call.
  if (patch_size < sizeof(std::intptr_t) + 1) {
    std::wstring error_message = fmt::sprintf(
        L"The patch size specified at address %X is too small to perform a "
        L"branch patch.",
        game_address.address()
    );

    MessageBoxW(
        nullptr,
        error_message.data(),
        L"Failed to Patch Game",
        MB_OK | MB_ICONERROR
    );
    std::exit(0);
  }

  // Create a buffer full of NOPs.
  std::vector<std::uint8_t> buffer(
      patch_size,
      static_cast<std::uint8_t>(OpCode::kNop)
  );

  // Set the first byte in the buffer to the branch operation opcode byte.
  enum OpCode op_code = GetOpCodeByBranchTypeMap().at(branch_type);
  buffer[0] = static_cast<std::uint8_t>(op_code);

  // Set the next bytes to the address of the inserted function.
  std::intptr_t func_buffer = func_ptr
      - game_address.address()
      - sizeof(std::int8_t)
      - sizeof(func_ptr);

  for (std::size_t i = 0; i < sizeof(func_buffer); i += 1) {
    buffer[i + 1] = (func_buffer >> (i * (sizeof(buffer[0]) * 8))) & 0xFF;
  }

  return buffer;
}
#endif

} // namespace

GameBranchPatch::GameBranchPatch(
    const GameAddress& game_address,
    enum BranchType branch_type,
    std::intptr_t func_ptr,
    std::size_t patch_size
)
    : GamePatchBase(
          game_address,
          CreateReplaceBuffer(branch_type, func_ptr, game_address, patch_size)),
      branch_type_(branch_type),
      func_ptr_(func_ptr) {
}

GameBranchPatch::GameBranchPatch(
    GameAddress&& game_address,
    enum BranchType branch_type,
    std::intptr_t func_ptr,
    std::size_t patch_size
)
    : GamePatchBase(
          std::move(game_address),
          CreateReplaceBuffer(branch_type, func_ptr, game_address, patch_size)
      ),
      branch_type_(branch_type),
      func_ptr_(func_ptr) {
}

GameBranchPatch::GameBranchPatch(
    const GameBranchPatch&
) = default;

GameBranchPatch::GameBranchPatch(
    GameBranchPatch&&
) noexcept = default;

GameBranchPatch::~GameBranchPatch(
    void
) = default;

GameBranchPatch&
GameBranchPatch::operator=(
    const GameBranchPatch&
) = default;

GameBranchPatch&
GameBranchPatch::operator=(
    GameBranchPatch&&
) noexcept = default;

enum BranchType
GameBranchPatch::branch_type(
    void
) const noexcept {
  return branch_type_;
}

std::intptr_t
GameBranchPatch::func_ptr(
    void
) const noexcept {
  return func_ptr_;
}

} // namespace sgd2mapi

/**
 * C Interface
 */

struct SGD2MAPI_GameBranchPatch*
SGD2MAPI_GameBranchPatch_Create(
    const struct SGD2MAPI_GameAddress* c_game_address,
    enum SGD2MAPI_BranchType c_branch_type,
    void* func(),
    std::size_t patch_size
) {
  struct SGD2MAPI_GameBranchPatch* c_game_branch_patch =
      new SGD2MAPI_GameBranchPatch;

  enum sgd2mapi::BranchType actual_branch_type =
      static_cast<sgd2mapi::BranchType>(c_branch_type);

  const sgd2mapi::GameAddress* actual_game_address =
      c_game_address->actual_ptr.get();

  c_game_branch_patch->actual_ptr =
      std::make_shared<sgd2mapi::GameBranchPatch>(
          *(actual_game_address),
          actual_branch_type,
          func,
          patch_size
      );

  return c_game_branch_patch;
}

struct SGD2MAPI_GamePatchBase*
SGD2MAPI_GameBranchPatch_CreateAsGamePatchBase(
    const struct SGD2MAPI_GameAddress* c_game_address,
    enum SGD2MAPI_BranchType c_branch_type,
    void* func(),
    std::size_t patch_size
) {
  struct SGD2MAPI_GamePatchBase* c_game_patch_base =
      new SGD2MAPI_GamePatchBase;

  enum sgd2mapi::BranchType actual_branch_type =
      static_cast<sgd2mapi::BranchType>(c_branch_type);

  const sgd2mapi::GameAddress* actual_game_address =
      c_game_address->actual_ptr.get();

  c_game_patch_base->actual_ptr =
      std::make_shared<sgd2mapi::GameBranchPatch>(
          *(actual_game_address),
          actual_branch_type,
          func,
          patch_size
      );

  return c_game_patch_base;
}

void
SGD2MAPI_GameBranchPatch_Destroy(
    struct SGD2MAPI_GameBranchPatch* c_game_branch_patch
) {
  delete c_game_branch_patch;
}

struct SGD2MAPI_GamePatchBase*
SGD2MAPI_GameBranchPatch_UpcastToGamePatchBase(
    const struct SGD2MAPI_GameBranchPatch* c_game_branch_patch
) {
  struct SGD2MAPI_GamePatchBase* c_game_patch_base =
      new SGD2MAPI_GamePatchBase;

  c_game_patch_base->actual_ptr = c_game_branch_patch->actual_ptr;

  return c_game_patch_base;
}

struct SGD2MAPI_GamePatchBase*
SGD2MAPI_GameBranchPatch_UpcastToGamePatchBaseThenDestroy(
    struct SGD2MAPI_GameBranchPatch* c_game_branch_patch
) {
  struct SGD2MAPI_GamePatchBase* c_game_patch_base =
      SGD2MAPI_GameBranchPatch_UpcastToGamePatchBase(
          c_game_branch_patch
      );

  SGD2MAPI_GameBranchPatch_Destroy(c_game_branch_patch);

  return c_game_patch_base;
}

void
SGD2MAPI_GameBranchPatch_Apply(
    struct SGD2MAPI_GameBranchPatch* game_branch_patch
) {
  game_branch_patch->actual_ptr->Apply();
}

void
SGD2MAPI_GameBranchPatch_Remove(
    struct SGD2MAPI_GameBranchPatch* game_branch_patch
) {
  game_branch_patch->actual_ptr->Remove();
}
