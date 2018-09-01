/**
 * SlashGaming Diablo II Modding API
 * Copyright (C) 2018  SlashGaming Community
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
 *  the game, provided that the game or its libraries do not link to this
 *  Program.
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any Glide wrapper (or a modified version of that library),
 *  containing parts not covered by a compatible license, provided that the
 *  wrapper does not link to this Program, the licensors of this Program
 *  grant you additional permission to convey the resulting work.
 */

#include "../../include/game_patch/game_branch_patch.h"

#include <windows.h>
#include <cstdint>
#include <cstdlib>
#include <utility>
#include <vector>

#include <boost/format.hpp>
#include <frozen/unordered_map.h>
#include "../architecture_opcode.h"
#include "../c_interface/game_address.h"
#include "../../include/game_address.h"
#include "c_interface/game_branch_patch.h"
#include "c_interface/game_patch_base.h"
#include "../../include/game_patch/game_patch_base.h"

namespace sgd2mapi {

namespace {

#if defined(__i386__)
constexpr frozen::unordered_map kOpCodeByBranchType =
    frozen::make_unordered_map<enum BranchType, enum OpCode>({
        {BranchType::kCall, OpCode::kCall},
        {BranchType::kJump, OpCode::kJump}
    });

std::vector<std::uint8_t> CreateReplaceBuffer(
    enum BranchType branch_type,
    const GameAddress& game_address,
    std::size_t patch_size
) {

  // Check that the patch size is large enough to allow the insertion of the
  // branch call.
  if (patch_size < sizeof(std::intptr_t) + 1) {
    std::wstring error_message = (boost::wformat(
        L"The patch size specified at address %X is too small to perform a "
        L"branch patch."
    ) % game_address.address()).str();

    MessageBoxW(
        nullptr,
        error_message.data(),
        L"Failed to Patch Game",
        MB_OK | MB_ICONERROR
    );
    std::exit(EXIT_FAILURE);
  }

  // Create a buffer full of NOPs.
  std::vector<std::uint8_t> buffer(
      patch_size,
      static_cast<std::uint8_t>(OpCode::kNop)
  );

  // Set the first byte in the buffer to the branch operation opcode byte.
  buffer[0] = static_cast<std::uint8_t>(kOpCodeByBranchType.at(branch_type));

  // Set the next bytes to the address of the inserted function.
  std::intptr_t address_buffer = game_address.address();
  for (std::size_t i = 0; i < sizeof(address_buffer); i += 1) {
    buffer[i + 1] = (address_buffer >> (i * (sizeof(buffer[0]) * 8))) & 0xFF;
  }

  return buffer;
}
#endif

} // namespace

GameBranchPatch::GameBranchPatch(
    const GameAddress& game_address,
    enum BranchType branch_type,
    std::intptr_t func_ptr,
    std::size_t patch_size)
    : GamePatchBase(
          game_address,
          CreateReplaceBuffer(branch_type, game_address, patch_size)),
      branch_type_(branch_type),
      func_ptr_(func_ptr) {
}

GameBranchPatch::GameBranchPatch(
    GameAddress&& game_address,
    enum BranchType branch_type,
    std::intptr_t func_ptr,
    std::size_t patch_size)
    : GamePatchBase(
          std::move(game_address),
          CreateReplaceBuffer(branch_type, game_address, patch_size)
      ),
      branch_type_(branch_type),
      func_ptr_(func_ptr) {
}

GameBranchPatch::GameBranchPatch(const GameBranchPatch&) = default;

GameBranchPatch::GameBranchPatch(GameBranchPatch&&) noexcept = default;

GameBranchPatch::~GameBranchPatch() = default;

GameBranchPatch& GameBranchPatch::operator=(const GameBranchPatch&) = default;

GameBranchPatch& GameBranchPatch::operator=(
    GameBranchPatch&&
) noexcept = default;

enum BranchType GameBranchPatch::branch_type() const noexcept {
  return branch_type_;
}

std::intptr_t GameBranchPatch::func_ptr() const noexcept {
  return func_ptr_;
}

} // namespace sgd2mapi

/**
 * C Interface
 */

void sgd2mapi_game_branch_patch_create_as_game_branch_patch(
    struct SGD2MAPI_GameBranchPatch* dest,
    const struct SGD2MAPI_GameAddress* game_address,
    enum SGD2MAPI_BranchType branch_type,
    void* func(),
    std::size_t patch_size
) {
  enum sgd2mapi::BranchType converted_branch_type =
      static_cast<sgd2mapi::BranchType>(branch_type);

  dest->game_branch_patch = new sgd2mapi::GameBranchPatch(
      *(game_address->game_address),
      converted_branch_type,
      func,
      patch_size
  );
}

void sgd2mapi_game_branch_patch_create_as_game_patch_base(
    struct SGD2MAPI_GamePatchBase* dest,
    const struct SGD2MAPI_GameAddress* game_address,
    enum SGD2MAPI_BranchType branch_type,
    void* func(),
    std::size_t patch_size
) {
  struct SGD2MAPI_GameBranchPatch game_branch_patch;
  sgd2mapi_game_branch_patch_create_as_game_branch_patch(
      &game_branch_patch,
      game_address,
      branch_type,
      func,
      patch_size
  );

  sgd2mapi_game_branch_patch_upcast_to_game_patch_base(
      dest,
      &game_branch_patch
  );
}

void sgd2mapi_game_branch_patch_destroy(
    struct SGD2MAPI_GameBranchPatch* game_branch_patch
) {
  delete game_branch_patch->game_branch_patch;
}

void sgd2mapi_game_branch_patch_upcast_to_game_patch_base(
    struct SGD2MAPI_GamePatchBase* dest,
    const struct SGD2MAPI_GameBranchPatch* game_branch_patch
) {
  dest->game_patch_base = game_branch_patch->game_branch_patch;
}

void sgd2mapi_game_branch_patch_apply(
    struct SGD2MAPI_GameBranchPatch* game_branch_patch
) {
  game_branch_patch->game_branch_patch->Apply();
}

void sgd2mapi_game_branch_patch_remove(
    struct SGD2MAPI_GameBranchPatch* game_branch_patch
) {
  game_branch_patch->game_branch_patch->Remove();
}
