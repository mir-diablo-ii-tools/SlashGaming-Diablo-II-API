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

#ifndef SGD2MAPI_GAME_PATCH_GAME_PATCH_INTERFACE_H_
#define SGD2MAPI_GAME_PATCH_GAME_PATCH_INTERFACE_H_

#include <stdbool.h>

#include "../game_address.h"

#ifdef __cplusplus
#include <cstdint>
#include <vector>
#endif // __cplusplus

#if defined(SGD2MAPI_DLLEXPORT)
#define DLLEXPORT __declspec(dllexport)
#elif defined(SGD2MAPI_DLLIMPORT)
#define DLLEXPORT __declspec(dllimport)
#else
#define DLLEXPORT
#endif

struct SGD2MAPI_GamePatchInterface;

#ifdef __cplusplus
struct DLLEXPORT SGD2MAPI_GamePatchInterface {
 public:
  virtual
  ~SGD2MAPI_GamePatchInterface(
      void
  );

  virtual SGD2MAPI_GamePatchInterface*
  Clone(
      void
  ) const = 0;

  virtual SGD2MAPI_GamePatchInterface*
  MoveToClone(
      void
  ) = 0;

  /**
   * Applies the patch by replacing the bytes at its target address with the
   * bytes stored in its buffer.
   */
  virtual void
  Apply(
      void
  ) = 0;

  /**
   * Removes the effects of the patch by restoring the patched entries to their
   * original values.
   */
  virtual void
  Remove(
      void
  ) = 0;

  /**
   * Returns the game address used by this patch.
   */
  virtual const sgd2mapi::GameAddress&
  game_address(
      void
  ) const noexcept = 0;

  /**
   * Returns whether or not the patch has been applied.
   */
  virtual bool
  is_patch_applied(
      void
  ) const noexcept = 0;

  /**
   * Returns the buffer storing the patch data.
   */
  virtual const std::vector<std::uint8_t>&
  patch_buffer(
      void
  ) const noexcept = 0;

  /**
   * Returns the buffer storing the original data before patching.
   */
  virtual const std::vector<std::uint8_t>&
  old_bytes(
      void
  ) const noexcept = 0;

  /**
   * Returns the number of bytes needed to apply this patch.
   */
  virtual std::size_t
  patch_size(
      void
  ) const noexcept = 0;
};
#endif // __cplusplus

/**
 * C Interface
 */

#if !defined(__cplusplus) || defined(SGD2MAPI_DLLEXPORT)

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

struct SGD2MAPI_GamePatchInterface*
SGD2MAPI_GamePatchInterface_Clone(
    const struct SGD2MAPI_GamePatchInterface* c_game_patch
);

struct SGD2MAPI_GamePatchInterface*
SGD2MAPI_GamePatchInterface_MoveToClone(
    struct SGD2MAPI_GamePatchInterface* c_game_patch
);

void
SGD2MAPI_GamePatchInterface_Apply(
    struct SGD2MAPI_GamePatchInterface* c_game_patch
);

void
SGD2MAPI_GamePatchInterface_Remove(
    struct SGD2MAPI_GamePatchInterface* c_game_patch
);

bool
SGD2MAPI_GamePatchInterface_IsPatchApplied(
    const struct SGD2MAPI_GamePatchInterface* c_game_patch
);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !defined(__cplusplus) || defined(SGD2MAPI_DLLEXPORT)

#undef DLLEXPORT
#endif // SGD2MAPI_GAME_PATCH_GAME_PATCH_INTERFACE_H_
