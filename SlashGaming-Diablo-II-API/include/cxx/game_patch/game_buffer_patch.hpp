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

#ifndef SGD2MAPI_CXX_GAME_PATCH_GAME_BUFFER_PATCH_HPP_
#define SGD2MAPI_CXX_GAME_PATCH_GAME_BUFFER_PATCH_HPP_

#include <cstdint>
#include <cstdlib>
#include <vector>

#include "../game_address.hpp"
#include "game_patch_base.hpp"

#include "../../dllexport_define.inc"

namespace sgd2mapi {

/**
 * A patch that replaces the bytes at a destination address with 8-bit bytes
 * stored in a buffer.
 */
class DLLEXPORT GameBufferPatch
    : public GamePatchBase {
 public:
  /**
   * Creates an instance of GameBufferPatch, specifying the patch buffer with
   * an array of 8-bit bytes.
   */
  GameBufferPatch(
      const GameAddress& game_address,
      const std::uint8_t buffer[],
      std::size_t patch_size
  );

  /**
   * Creates an instance of GameBufferPatch, specifying the patch buffer with a
   * vector of 8-bit bytes.
   */
  GameBufferPatch(
      const GameAddress& game_address,
      const std::vector<std::uint8_t>& buffer
  );

  /**
   * Creates an instance of GameBufferPatch, specifying the patch buffer with a
   * vector of 8-bit bytes.
   */
  GameBufferPatch(
      GameAddress&& game_address,
      const std::vector<std::uint8_t>& buffer
  );

  /**
   * Creates an instance of GameBufferPatch, specifying the patch buffer with a
   * vector of 8-bit bytes.
   */
  GameBufferPatch(
      const GameAddress& game_address,
      std::vector<std::uint8_t>&& buffer
  );

  /**
   * Creates an instance of GameBufferPatch, specifying the patch buffer with a
   * vector of 8-bit bytes.
   */
  GameBufferPatch(
      GameAddress&& game_address,
      std::vector<std::uint8_t>&& buffer
  );

  GameBufferPatch(
      const GameBufferPatch&
  );

  GameBufferPatch(
      GameBufferPatch&&
  ) noexcept;

  ~GameBufferPatch(
      void
  ) override;

  GameBufferPatch&
  operator=(
      const GameBufferPatch&
  );

  GameBufferPatch&
  operator=(
      GameBufferPatch&&
  ) noexcept;

  GameBufferPatch*
  Clone(
      void
  ) const override;

  GameBufferPatch*
  MoveToClone(
      void
  ) override;
};

} // namespace sgd2mapi

#include "../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_PATCH_GAME_BUFFER_PATCH_HPP_
