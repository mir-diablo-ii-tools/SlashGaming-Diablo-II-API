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

#ifndef SGD2MAPI_CXX_GAME_PATCH_GAME_PATCH_INTERFACE_HPP_
#define SGD2MAPI_CXX_GAME_PATCH_GAME_PATCH_INTERFACE_HPP_

#include "../../dllexport_define.inc"

namespace sgd2mapi {

class DLLEXPORT GamePatchInterface {
 public:
  virtual
  ~GamePatchInterface(
      void
  );

  /**
   * Clones this game patch and returns a pointer to the clone.
   */
  virtual GamePatchInterface*
  Clone(
      void
  ) const = 0;

  /**
   * Destructively moves all data into a clone and returns a pointer to the
   * clone.
   */
  virtual GamePatchInterface*
  MoveToClone(
      void
  ) = 0;

  /**
   * Applies the patch by replacing the values at its target address with the
   * values stored in its buffer. Does nothing if the patch is applied.
   */
  virtual void
  Apply(
      void
  ) = 0;

  /**
   * Removes the effects of the patch by restoring the patched entries to their
   * original values. Does nothing if the patch is not been applied.
   */
  virtual void
  Remove(
      void
  ) = 0;
};

} // namespace sgd2mapi

#include "../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_PATCH_GAME_PATCH_INTERFACE_HPP_
