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

#ifndef SGMAPI_CXX_GAME_PATCH_HPP_
#define SGMAPI_CXX_GAME_PATCH_HPP_

#include <cstdint>
#include <vector>

#include "game_address.hpp"
#include "game_branch_type.hpp"

#include "../dllexport_define.inc"

namespace mapi {

/**
 * A game patch that is capable of replacing values in memory with
 * user-specified values and restoring the original state of the values in
 * memory.
 */
class DLLEXPORT GamePatch {
 public:
  /**
   * Applies the patch by replacing the values at its target address with the
   * values stored in its buffer. Does nothing if the patch is applied.
   */
  void Apply();

  /**
   * Removes the effects of the patch by restoring the patched entries to their
   * original values. Does nothing if the patch is not applied.
   */
  void Remove();

  /**
   * Make an instance of a back branch patch. The patch replaces the last
   * bytes with a branch to a user-specified function, then replaces the
   * remaining front bytes with no-op instructions.
   */
  static GamePatch MakeGameBackBranchPatch(
      const GameAddress& game_address,
      BranchType branch_type,
      void (*func_ptr)(),
      std::size_t patch_size
  );

  /**
   * Make an instance of a back branch patch. The patch replaces the last
   * bytes with a branch to a user-specified function, then replaces the
   * remaining front bytes with no-op instructions.
   */
  static GamePatch MakeGameBackBranchPatch(
      GameAddress&& game_address,
      BranchType branch_type,
      void (*func_ptr)(),
      std::size_t patch_size
  );

  /**
   * Make an instance of a branch patch. The patch replaces the first bytes
   * with a branch to a user-specified function, then replaces the rest of the
   * bytes with no-op instructions.
   */
  static GamePatch MakeGameBranchPatch(
      const GameAddress& game_address,
      BranchType branch_type,
      void (*func_ptr)(),
      std::size_t patch_size
  );

  /**
   * Make an instance of a branch patch. The patch replaces the first bytes
   * with a branch to a user-specified function, then replaces the rest of the
   * bytes with no-op instructions.
   */
  static GamePatch MakeGameBranchPatch(
      GameAddress&& game_address,
      BranchType branch_type,
      void (*func_ptr)(),
      std::size_t patch_size
  );

  /**
   * Makes an instance of a buffer patch, specifying the patch buffer using an
   * array of 8-bit bytes.
   */
  static GamePatch MakeGameBufferPatch(
      const GameAddress& game_address,
      const std::uint8_t* patch_buffer,
      std::size_t patch_size
  );

  /**
   * Makes an instance of a buffer patch, specifying the patch buffer using an
   * array of 8-bit bytes.
   */
  static GamePatch MakeGameBufferPatch(
      GameAddress&& game_address,
      const std::uint8_t* patch_buffer,
      std::size_t patch_size
  );

  /**
   * Makes an instance of a buffer patch, specifying the patch buffer using an
   * iterator of 8-bit bytes.
   */
  template <typename Iter>
  static GamePatch MakeGameBufferPatch(
      const GameAddress& game_address,
      Iter first,
      Iter last
  ) {
    static_assert (std::is_same<Iter::value_type, std::uint8_t>::value
        || std::is_same<Iter::value_type, std::int8_t>::value);

    return GamePatch(game_address, std::vector<std::uint8_t>(first, last));
  }

  /**
   * Makes an instance of a buffer patch, specifying the patch buffer using an
   * iterator of 8-bit bytes.
   */
  template <typename Iter>
  static GamePatch MakeGameBufferPatch(
      GameAddress&& game_address,
      Iter first,
      Iter last
  ) {
    static_assert (std::is_same<Iter::value_type, std::uint8_t>::value
        || std::is_same<Iter::value_type, std::int8_t>::value);

    return GamePatch(
        std::move(game_address),
        std::vector<std::uint8_t>(first, last)
    );
  }

  /**
   * Makes an instance of a NOP patch, filling the patch buffer with as
   * many no-op instructions that can fit in a patch buffer of the specified
   * size.
   */
  static GamePatch MakeGameNopPatch(
      const GameAddress& game_address,
      std::size_t patch_size
  );

  /**
   * Makes an instance of a NOP patch, filling the patch buffer with as
   * many no-op instructions that can fit in a patch buffer of the specified
   * size.
   */
  static GamePatch MakeGameNopPatch(
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

  const GameAddress& game_address() const noexcept;
  bool is_patch_applied() const noexcept;
  const std::vector<std::uint8_t>& patch_buffer() const noexcept;
  const std::vector<std::uint8_t>& unpatched_buffer() const noexcept;

  GameAddress game_address_;
  bool is_patch_applied_;
  std::vector<std::uint8_t> patch_buffer_;
  std::vector<std::uint8_t> unpatched_buffer_;
};

} // namespace mapi

#include "../dllexport_undefine.inc"
#endif // SGMAPI_CXX_GAME_PATCH_HPP_
