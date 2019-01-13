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

#ifndef SGD2MAPI_GAME_ADDRESS_LOCATOR_GAME_OFFSET_H_
#define SGD2MAPI_GAME_ADDRESS_LOCATOR_GAME_OFFSET_H_

#include <stdint.h>

#include "game_address_locator_interface.h"

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

#ifdef __cplusplus
namespace sgd2mapi {

/**
 * A game address locator that uses an offset value to specify a location in
 * game memory.
 */
class DLLEXPORT GameOffset : public GameAddressLocatorInterface {
 public:
  /**
   * Creates a new instance of GameOffset.
   */
  explicit GameOffset(std::intptr_t offset) noexcept;

  GameOffset(const GameOffset&) noexcept;
  GameOffset(GameOffset&&) noexcept;

  ~GameOffset() noexcept override;

  GameOffset& operator=(const GameOffset&) noexcept;
  GameOffset& operator=(GameOffset&&) noexcept;

  std::intptr_t ResolveGameAddress(std::intptr_t base_address)
      const noexcept override;

  /**
   * Returns the offset of this game locator.
   */
  std::intptr_t offset() const noexcept;

 private:
  std::intptr_t offset_;
};

} // namespace sgd2mapi
#endif // __cplusplus

/**
 * C Interface
 */

#if !defined(__cplusplus) || defined(SGD2MAPI_DLLEXPORT)
struct SGD2MAPI_GameOffset;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * Creates a new GameOffset, upcasted to a GameAddressLocatorInterface.
 */
DLLEXPORT struct SGD2MAPI_GameAddressLocatorInterface*
SGD2MAPI_GameOffset_CreateAsGameAddressLocatorInterface(
    intptr_t offset
);

/**
 * Creates a new GameOffset.
 */
DLLEXPORT struct SGD2MAPI_GameOffset*
SGD2MAPI_GameOffset_Create(
    intptr_t offset
);

/**
 * Frees the memory used by the specified game locator.
 */
DLLEXPORT void
SGD2MAPI_GameOffset_Destroy(
    struct SGD2MAPI_GameOffset* c_game_offset
);

/**
 * Creates an upcast of the specified game locator to a
 * GameAddressLocatorInterface.
 */
DLLEXPORT struct SGD2MAPI_GameAddressLocatorInterface*
SGD2MAPI_GameOffset_UpcastToGameAddressLocatorInterface(
    const struct SGD2MAPI_GameOffset* c_game_offset
);

/**
 * Creates an upcast of the specified game locator to a
 * GameAddressLocatorInterface and destroys the specified game locator.
 */
DLLEXPORT struct SGD2MAPI_GameAddressLocatorInterface*
SGD2MAPI_GameOffset_UpcastToGameAddressLocatorInterfaceThenDestroy(
    struct SGD2MAPI_GameOffset* c_game_offset
);

/**
 * Returns the offset value of the game locator.
 */
DLLEXPORT intptr_t
SGD2MAPI_GameOffset_GetOffset(
    const struct SGD2MAPI_GameOffset* c_game_offset
);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !defined(__cplusplus) || defined(SGD2MAPI_DLLEXPORT)

#undef DLLEXPORT
#endif // SGD2MAPI_GAME_ADDRESS_LOCATOR_GAME_OFFSET_H_
