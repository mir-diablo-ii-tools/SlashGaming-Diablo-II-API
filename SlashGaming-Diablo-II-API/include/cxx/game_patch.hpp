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

#ifndef SGD2MAPI_CXX_GAME_PATCH_HPP_
#define SGD2MAPI_CXX_GAME_PATCH_HPP_

#include <cstdint>
#include <vector>

#include "game_address.hpp"

#include "../dllexport_define.inc"

namespace mapi {

/**
 * The branch types that are used to call an inserted function. A call saves
 * some state defined by the architecture, with the purpose of returning to the
 * calling function. A jump does not save any state information.
 */
enum class BranchType {
  kCall,
  kJump,
};

class DLLEXPORT GamePatch {
 public:
  void Apply(void);

  void Remove(void);

  static GamePatch MakeBranchPatch(
      const GameAddress& game_address,
      enum BranchType branch_type,
      void (*func_ptr)(void),
      std::size_t patch_size
  );

  static GamePatch MakeBranchPatch(
      GameAddress&& game_address,
      enum BranchType branch_type,
      void (*func_ptr)(void),
      std::size_t patch_size
  );

  static GamePatch MakeBufferPatch(
      const GameAddress& game_address,
      const std::uint8_t patch_buffer[],
      std::size_t patch_size
  );

  static GamePatch MakeBufferPatch(
      GameAddress&& game_address,
      const std::uint8_t patch_buffer[],
      std::size_t patch_size
  );

  static GamePatch MakeBufferPatch(
      const GameAddress& game_address,
      const std::vector<std::uint8_t>& patch_buffer
  );

  static GamePatch MakeBufferPatch(
      GameAddress&& game_address,
      const std::vector<std::uint8_t>& patch_buffer
  );

  static GamePatch MakeBufferPatch(
      const GameAddress& game_address,
      std::vector<std::uint8_t>&& patch_buffer
  );

  static GamePatch MakeBufferPatch(
      GameAddress&& game_address,
      std::vector<std::uint8_t>&& patch_buffer
  );

  static GamePatch MakeNopPatch(
      const GameAddress& game_address,
      std::size_t patch_size
  );

  static GamePatch MakeNopPatch(
      GameAddress&& game_address,
      std::size_t patch_size
  );

 private:
  GamePatch(
      const GameAddress& game_address,
      const std::vector<std::uint8_t>& patch_buffer
  );

  GamePatch(
      GameAddress&& game_address,
      const std::vector<std::uint8_t>& patch_buffer
  );

  GamePatch(
      const GameAddress& game_address,
      std::vector<std::uint8_t>&& patch_buffer
  );

  GamePatch(
      GameAddress&& game_address,
      std::vector<std::uint8_t>&& patch_buffer
  );

  GameAddress game_address_;
  bool is_patch_applied_;
  std::vector<std::uint8_t> patch_buffer_;
  std::vector<std::uint8_t> unpatched_buffer_;
};

} // namespace mapi

#include "../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_PATCH_HPP_
