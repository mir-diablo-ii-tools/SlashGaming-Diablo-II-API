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

#ifndef SGD2MAPI_CXX_GAME_PATCH_GAME_BRANCH_PATCH_HPP_
#define SGD2MAPI_CXX_GAME_PATCH_GAME_BRANCH_PATCH_HPP_

#include <cstdint>
#include <cstdlib>
#include <vector>

#include "../game_address.hpp"
#include "game_patch_base.hpp"

#include "../../dllexport_define.inc"

namespace sgd2mapi {

/**
 * The branch types that are used to call an inserted function. A call saves
 * some state defined by the architecture, with the purpose of returning to the
 * calling function. A jump does not save any state information.
 */
enum class BranchType {
  kCall,
  kJump,
};

/**
 * A patch that replaces the first bytes with a branch to a function, then
 * replaces the rest of the bytes with no-op instructions.
 */
class DLLEXPORT GameBranchPatch
    : public GamePatchBase {
 public:
  /**
   * Creates a new instance of GameBranchPatch.
   */
  template<typename T, typename... Args>
  GameBranchPatch(
      const GameAddress& game_address,
      enum BranchType branch_type,
      T func(Args...),
      std::size_t patch_size
  )
      : GameBranchPatch(
            game_address,
            branch_type,
            reinterpret_cast<std::intptr_t>(func),
            patch_size
        ) {
  }

  /**
   * Creates a new instance of GameBranchPatch.
   */
  template<typename T, typename... Args>
  GameBranchPatch(
      GameAddress&& game_address,
      enum BranchType branch_type,
      T func(Args...),
      std::size_t patch_size
  )
      : GameBranchPatch(
            std::move(game_address),
            branch_type,
            reinterpret_cast<std::intptr_t>(func),
            patch_size
        ) {
  }

  GameBranchPatch(
      const GameBranchPatch&
  );

  GameBranchPatch(
      GameBranchPatch&&
  ) noexcept;

  ~GameBranchPatch(
      void
  ) override;

  GameBranchPatch&
  operator=(
      const GameBranchPatch&
  );

  GameBranchPatch&
  operator=(
      GameBranchPatch&&
  ) noexcept;

  /**
   * Returns the branch opcode used for calling the inserted function.
   */
  enum BranchType
  branch_type(
      void
  ) const noexcept;

  /**
   * Returns the pointer to the inserted function.
   */
  std::intptr_t
  func_ptr(
      void
  ) const noexcept;

  GameBranchPatch*
  Clone(
      void
  ) const override;

  GameBranchPatch*
  MoveToClone(
      void
  ) override;

 private:
  GameBranchPatch(
      const GameAddress& game_address,
      enum BranchType branch_type,
      std::intptr_t func_ptr,
      std::size_t patch_size
  );

  GameBranchPatch(
      GameAddress&& game_address,
      enum BranchType branch_type,
      std::intptr_t func_ptr,
      std::size_t patch_size
  );

  enum BranchType branch_type_;
  std::intptr_t func_ptr_;
};

} // namespace sgd2mapi

#include "../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_PATCH_GAME_BRANCH_PATCH_HPP_
