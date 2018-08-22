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

#ifndef SGD2MAPI_GAME_PATCH_GAME_INTERCEPTION_PATCH_H_
#define SGD2MAPI_GAME_PATCH_GAME_INTERCEPTION_PATCH_H_

#include <stdlib.h>

#include "../game_address.h"
#include "game_patch_base.h"

#ifdef __cplusplus
#include <cstdint>
#include <cstdlib>
#include <functional>
#include <vector>
#endif // __cplusplus

#if defined(SGD2MAPI_DLLEXPORT)
#define DLLEXPORT __declspec(dllexport)
#elif defined(SGD2MAPI_DLLIMPORT)
#define DLLEXPORT __declspec(dllimport)
#else
#define DLLEXPORT
#endif

#ifdef __cplusplus
namespace sgd2mapi {

/**
 * The branch types that are used to call the specified interception function.
 * A call saves some state defined by the architecture, with the purpose of
 * returning to the calling function. A jump does not save any state
 * information.
 */
enum class BranchType;

/**
 * A patch that replaces the first bytes with a function call, then replaces
 * the rest of the bytes with no-op instructions.
 */
class DLLEXPORT GameInterceptionPatch : public GamePatchBase {
 public:
  template<typename T>
  GameInterceptionPatch(
      const GameAddress& game_address,
      enum BranchType branch_type,
      std::function<T> func,
      std::size_t patch_size)
  : GameInterceptionPatch(
        game_address,
        branch_type,
        reinterpret_cast<std::intptr_t>(
            func.template target<void(*)(void*)>()
        ),
        patch_size
    ) {
  }

  template<typename T>
  GameInterceptionPatch(
      GameAddress&& game_address,
      enum BranchType branch_type,
      std::function<T> func,
      std::size_t patch_size)
  : GameInterceptionPatch(
        std::move(game_address),
        branch_type,
        reinterpret_cast<std::intptr_t>(
            func.template target<void(*)(void*)>()
        ),
        patch_size
    ) {
  }

  GameInterceptionPatch(const GameInterceptionPatch&);

  GameInterceptionPatch(GameInterceptionPatch&&) noexcept;

  ~GameInterceptionPatch() override;

  GameInterceptionPatch& operator=(const GameInterceptionPatch&);

  GameInterceptionPatch& operator=(GameInterceptionPatch&&) noexcept;

  /**
   * Returns the branch opcode used for calling the interception function.
   */
  enum BranchType branch_type() const noexcept;

  /**
   * Returns the pointer to the interception function.
   */
  std::intptr_t func_ptr() const noexcept;

 private:
  GameInterceptionPatch(const GameAddress& game_address,
                        enum BranchType branch_type,
                        std::intptr_t func_ptr,
                        std::size_t patch_size);

  GameInterceptionPatch(GameAddress&& game_address,
                        enum BranchType branch_type,
                        std::intptr_t func_ptr,
                        std::size_t patch_size);

  enum BranchType branch_type_;
  std::intptr_t func_ptr_;
};

} // namespace sgd2mapi
#endif // __cplusplus

/**
 * C Interface
 */

struct SGD2MAPI_GameInterceptionPatch;

/**
 * The branch types that are used to call the specified interception function.
 * A call saves some state defined by the architecture, with the purpose of
 * returning to the calling function. A jump does not save any state
 * information.
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

DLLEXPORT
void sgd2mapi_game_interception_patch_create_as_game_interception_patch(
    struct SGD2MAPI_GameInterceptionPatch* dest,
    const struct SGD2MAPI_GameAddress* game_address,
    enum SGD2MAPI_BranchType branch_type,
    void* func(),
    size_t patch_size
);

DLLEXPORT void sgd2mapi_game_interception_patch_create_as_game_patch_base(
    struct SGD2MAPI_GamePatchBase* dest,
    const struct SGD2MAPI_GameAddress* game_address,
    enum SGD2MAPI_BranchType branch_type,
    void* func(),
    size_t patch_size
);

/**
 * Initializes the value of the specified destination with a new
 * GameInterceptionPatch using the specified parameters.
 */
#define sgd2mapi_game_interception_patch_create( \
    dest, \
    game_address, \
    branch_type, \
    func, \
    patch_size \
) _Generic( \
    (dest), \
    struct SGD2MAPI_GameInterceptionPatch*: \
        sgd2mapi_game_interception_patch_create_as_game_interception_patch, \
    struct SGD2MAPI_GamePatchBase*: \
        sgd2mapi_game_interception_patch_create_as_game_patch_base \
)(dest, game_address, branch_type, func, patch_size)

DLLEXPORT void sgd2mapi_game_interception_patch_destroy(
    struct SGD2MAPI_GameInterceptionPatch* game_interception_patch
);

DLLEXPORT void sgd2mapi_game_interception_patch_downcast_to_game_patch_base(
    struct SGD2MAPI_GamePatchBase* dest,
    const struct SGD2MAPI_GameInterceptionPatch* game_interception_patch
);

#define sgd2mapi_game_interception_patch_downcast( \
    dest, \
    game_interception_patch \
) _Generic( \
    (dest), \
    struct SGD2MAPI_GamePatchBase*: \
        sgd2mapi_game_interception_patch_downcast_to_game_patch_base \
)(dest, game_interception_patch)

#ifdef __cplusplus
}
#endif // __cplusplus

#undef DLLEXPORT
#endif // SGD2MAPI_GAME_PATCH_GAME_INTERCEPTION_PATCH_H_
