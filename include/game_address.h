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

#ifndef SGD2MAPI_GAME_ADDRESS_H_
#define SGD2MAPI_GAME_ADDRESS_H_

#include <stdint.h>

#include "game_address_locator.h"
#include "game_library.h"
#include "game_version.h"

#ifdef __cplusplus
#include <cstdint>
#include <memory>
#include <string_view>
#include <unordered_map>
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
 * A class containing a location in the game memory.
 */
class DLLEXPORT GameAddress {
 public:
  /**
   * Create a new instance of GameAddress, specifying the library path and a
   * game address locator.
   */
  GameAddress(
      std::string_view library_path,
      const GameAddressLocatorInterface& address_locator
  ) noexcept;

  /**
   * Create a new instance of GameAddress, specifying the library ID and a
   * game address locator.
   */
  GameAddress(
      enum DefaultLibrary library,
      const GameAddressLocatorInterface& address_locator
  ) noexcept;

  /**
   * Create a new instance of GameAddress, specifying the library path and a
   * version to game address locator map.
   */
  GameAddress(
      std::string_view library_path,
      const std::unordered_map<
          enum GameVersion,
          std::shared_ptr<GameAddressLocatorInterface>
      >& address_locators
  ) noexcept;

  /**
   * Create a new instance of GameAddress, specifying the library ID and a
   * game address locator.
   */
  GameAddress(
      enum DefaultLibrary library,
      const std::unordered_map<
          enum GameVersion,
          std::shared_ptr<GameAddressLocatorInterface>
      >& address_locators
  ) noexcept;

  GameAddress(const GameAddress&) noexcept;
  GameAddress(GameAddress&&) noexcept;

  GameAddress& operator=(const GameAddress&) noexcept;
  GameAddress& operator=(GameAddress&&) noexcept;

  /**
   * Returns the address of this GameAddress.
   */
  std::intptr_t address() const noexcept;

 private:
  std::intptr_t address_;
};

} // namespace sgd2mapi
#endif // __cplusplus

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

struct SGD2MAPI_GameAddress;

DLLEXPORT void SGD2MAPI_GameAddress_CreateAsGameAddressFromLibraryPath(
    struct SGD2MAPI_GameAddress* dest,
    const char* library_path,
    const struct SGD2MAPI_GameAddressLocatorInterface**
        game_address_locator_interfaces
);

DLLEXPORT void SGD2MAPI_GameAddress_CreateAsGameAddressFromLibraryId(
    struct SGD2MAPI_GameAddress* dest,
    enum SGD2MAPI_DefaultLibrary library_id,
    const struct SGD2MAPI_GameAddressLocatorInterface**
        game_address_locator_interfaces
);

/**
 * Initializes the value of the specified destination with a new GameAddress
 * using the specified parameters. The library can be either a library ID or
 * the null-terminated string name of the library. The game address locator
 * array is a pointer to a one-dimensional array of pointers to
 * GameAddressLocator objects.
 */
#define SGD2MAPI_GameAddress_Create( \
    dest, \
    library, \
    game_address_locator_interfaces \
) _Generic( \
    (library), \
    char*: \
        SGD2MAPI_GameAddress_CreateAsGameAddressFromLibraryPath, \
    struct SGD2MAPI_GameAddressLocatorInterface*: \
        SGD2MAPI_GameAddress_CreateAsGameAddressFromLibraryId \
)(dest, library, game_address_locator_interfaces)

/**
 * Frees the memory used by the specified game address.
 */
DLLEXPORT void SGD2MAPI_GameAddress_Destroy(
    struct SGD2MAPI_GameAddress* game_address
);

/**
 * Returns the address value of the game address.
 */
DLLEXPORT intptr_t SGD2MAPI_GameAddress_GetAddress(
    const struct SGD2MAPI_GameAddress* game_address
);

#ifdef __cplusplus
}
#endif // __cplusplus

#undef DLLEXPORT
#endif // SGD2MAPI_GAME_ADDRESS_H_
