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

#include "game_interception_patch.h"

#include <windows.h>
#include <cstdint>
#include <cstdlib>
#include <utility>
#include <vector>

#include <boost/format.hpp>
#include <frozen/unordered_map.h>
#include "../game_address.h"
#include "game_patch_base.h"

namespace sgd2mapi {

namespace {

#if defined(__i386__)
enum class OpCode : std::uint8_t {
  kCall = 0xE8,
  kJump = 0xE9,
  kNop = 0x90
};

constexpr frozen::unordered_map kOpCodeByBranchType =
  frozen::make_unordered_map<enum BranchType, enum OpCode>({
      {BranchType::kCall, OpCode::kCall},
      {BranchType::kJump, OpCode::kJump}
  });

std::vector<std::uint8_t> CreateReplaceBuffer(
    enum BranchType branch_type,
    const GameAddress& game_address,
    std::size_t patch_size) {

  // Check that the patch size is large enough to allow the interception.
  if (patch_size < sizeof(std::intptr_t) + 1) {
    std::wstring error_message = (boost::wformat(
        L"The patch size specified at address %X is too small to perform an "
        L"interception patch."
    ) % game_address.address()).str();

    MessageBoxW(nullptr,
                error_message.data(),
                L"Failed to Patch Game",
                MB_OK | MB_ICONERROR);
    std::exit(EXIT_FAILURE);
  }

  // Create a buffer full of NOPs.
  std::vector<std::uint8_t> buffer(
      patch_size,
      static_cast<std::uint8_t>(OpCode::kNop));

  // Set the first byte in the buffer to the branch operation opcode byte.
  buffer[0] = static_cast<std::uint8_t>(kOpCodeByBranchType.at(branch_type));

  // Set the next bytes to the address of the interception function.
  std::intptr_t address_buffer = game_address.address();
  for (std::size_t i = 0; i < sizeof(address_buffer); i += 1) {
    buffer[i + 1] = (address_buffer >> (i * (sizeof(buffer[0]) * 8))) & 0xFF;
  }

  return buffer;
}
#endif

} // namespace

GameInterceptionPatch::GameInterceptionPatch(
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

GameInterceptionPatch::GameInterceptionPatch(
    GameAddress&& game_address,
    enum BranchType branch_type,
    std::intptr_t func_ptr,
    std::size_t patch_size)
    : GamePatchBase(
          std::move(game_address),
          CreateReplaceBuffer(branch_type, game_address, patch_size)),
      branch_type_(branch_type),
      func_ptr_(func_ptr) {
}

GameInterceptionPatch::GameInterceptionPatch(const GameInterceptionPatch&)
    = default;

GameInterceptionPatch::GameInterceptionPatch(GameInterceptionPatch&&)
    noexcept = default;

GameInterceptionPatch::~GameInterceptionPatch() = default;

GameInterceptionPatch& GameInterceptionPatch::operator=(
    const GameInterceptionPatch&) = default;

GameInterceptionPatch& GameInterceptionPatch::operator=(
    GameInterceptionPatch&&) noexcept = default;

enum BranchType GameInterceptionPatch::branch_type() const noexcept {
  return branch_type_;
}

std::intptr_t GameInterceptionPatch::func_ptr() const noexcept {
  return func_ptr_;
}

} // namespace sgd2mapi
