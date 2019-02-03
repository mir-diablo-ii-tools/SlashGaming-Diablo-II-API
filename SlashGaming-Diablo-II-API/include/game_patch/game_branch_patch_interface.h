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

#ifndef SGD2MAPI_GAME_PATCH_GAME_BRANCH_PATCH_INTERFACE_H_
#define SGD2MAPI_GAME_PATCH_GAME_BRANCH_PATCH_INTERFACE_H_

#include <stdint.h>

#include "game_patch_interface.h"

#ifdef __cplusplus
#include <cstdint>
#endif // __cplusplus

#if defined(SGD2MAPI_DLLEXPORT)
#define DLLEXPORT __declspec(dllexport)
#elif defined(SGD2MAPI_DLLIMPORT)
#define DLLEXPORT __declspec(dllimport)
#else
#define DLLEXPORT
#endif

namespace sgd2mapi {

/**
 * The branch types that are used to call an inserted function. A call saves
 * some state defined by the architecture, with the purpose of returning to the
 * calling function. A jump does not save any state information.
 */
enum class BranchType;

} // namespace sgd2mapi

struct SGD2MAPI_GameBranchPatchInterface;

#ifdef __cplusplus
struct DLLEXPORT SGD2MAPI_GameBranchPatchInterface
    : public virtual SGD2MAPI_GamePatchInterface {
 public:
  /**
   * Returns the branch opcode used for calling the inserted function.
   */
  virtual enum sgd2mapi::BranchType
  branch_type(
      void
  ) const noexcept = 0;

  /**
   * Returns the pointer to the inserted function.
   */
  virtual std::intptr_t
  func_ptr(
      void
  ) const noexcept = 0;
};
#endif // __cplusplus

/**
 * C Interface
 */

/**
 * The branch types that are used to call an inserted function. A call saves
 * some state defined by the architecture, with the purpose of returning to the
 * calling function. A jump does not save any state information. Disabled if
 * compiling as C++ code.
 */
enum SGD2MAPI_BranchType
#ifdef __cplusplus
{};

enum class sgd2mapi::BranchType
#endif // __cplusplus
{
  kCall,
  kJump,
};

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

DLLEXPORT void
SGD2MAPI_GameBranchPatchInterface_Destroy(
    struct SGD2MAPI_GameBranchPatchInterface* c_game_branch_patch
);

DLLEXPORT struct SGD2MAPI_GamePatchInterface*
SGD2MAPI_GameBranchPatchInterface_Clone(
    const struct SGD2MAPI_GameBranchPatchInterface* c_game_branch_patch
);

DLLEXPORT struct SGD2MAPI_GamePatchInterface*
SGD2MAPI_GameBranchPatchInterface_MoveToClone(
    struct SGD2MAPI_GameBranchPatchInterface* c_game_branch_patch
);

DLLEXPORT void
SGD2MAPI_GameBranchPatchInterface_Apply(
    struct SGD2MAPI_GameBranchPatchInterface* c_game_branch_patch
);

DLLEXPORT void
SGD2MAPI_GameBranchPatchInterface_Remove(
    struct SGD2MAPI_GameBranchPatchInterface* c_game_branch_patch
);

DLLEXPORT bool
SGD2MAPI_GameBranchPatchInterface_IsPatchApplied(
    const struct SGD2MAPI_GameBranchPatchInterface* c_game_branch_patch
);

/**
 * Returns the branch opcode of the game branch patch.
 */
DLLEXPORT enum SGD2MAPI_BranchType
SGD2MAPI_GameBranchPatchInterface_GetBranchType(
    const struct SGD2MAPI_GameBranchPatchInterface* c_game_branch_patch
);

/**
 * Returns the pointer to the inserted function of the game branch patch.
 */
DLLEXPORT intptr_t
SGD2MAPI_GameBranchPatchInterface_GetFuncPtr(
    const struct SGD2MAPI_GameBranchPatchInterface* c_game_branch_patch
);

#ifdef __cplusplus
}
#endif // __cplusplus

#undef DLLEXPORT
#endif // SGD2MAPI_GAME_PATCH_GAME_BRANCH_PATCH_INTERFACE_H_
