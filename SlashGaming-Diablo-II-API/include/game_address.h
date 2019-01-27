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

#ifndef SGD2MAPI_GAME_ADDRESS_H_
#define SGD2MAPI_GAME_ADDRESS_H_

#include <stdint.h>

#include "game_address_locator.h"
#include "default_game_library.h"
#include "game_version.h"

#ifdef __cplusplus
#include <cstdint>
#include <filesystem>
#include <memory>
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
      const std::filesystem::path& library_path,
      const GameAddressLocatorInterface& address_locator
  );

  /**
   * Create a new instance of GameAddress, specifying the library path and a
   * game address locator.
   */
  GameAddress(
      std::filesystem::path&& library_path,
      const GameAddressLocatorInterface& address_locator
  );

  /**
   * Create a new instance of GameAddress, specifying the library path and a
   * game address locator.
   */
  GameAddress(
      const std::filesystem::path& library_path,
      std::shared_ptr<GameAddressLocatorInterface> address_locator
  );

  /**
   * Create a new instance of GameAddress, specifying the library path and a
   * game address locator.
   */
  GameAddress(
      std::filesystem::path&& library_path,
      std::shared_ptr<GameAddressLocatorInterface> address_locator
  );

  /**
   * Create a new instance of GameAddress, specifying the library ID and a
   * game address locator.
   */
  GameAddress(
      enum DefaultLibrary library,
      const GameAddressLocatorInterface& address_locator
  );

  /**
   * Create a new instance of GameAddress, specifying the library ID and a
   * game address locator.
   */
  GameAddress(
      enum DefaultLibrary library,
      std::shared_ptr<GameAddressLocatorInterface> address_locator
  );

  /**
   * Create a new instance of GameAddress, specifying the library path and a
   * version to game address locator map.
   */
  GameAddress(
      const std::filesystem::path& library_path,
      const std::unordered_map<
          enum GameVersion,
          std::shared_ptr<GameAddressLocatorInterface>
      >& address_locators
  );

  /**
   * Create a new instance of GameAddress, specifying the library path and a
   * version to game address locator map.
   */
  GameAddress(
      std::filesystem::path&& library_path,
      const std::unordered_map<
          enum GameVersion,
          std::shared_ptr<GameAddressLocatorInterface>
      >& address_locators
  );

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
  );

  GameAddress(
      const GameAddress&
  );

  GameAddress(
      GameAddress&&
  ) noexcept;

  virtual
  ~GameAddress(
      void
  );

  GameAddress&
  operator=(
      const GameAddress&
  );

  GameAddress&
  operator=(
      GameAddress&&
  ) noexcept;

  /**
   * Returns the library path of this GameAddress.
   */
  const std::filesystem::path&
  library_path(
      void
  ) const noexcept;

  /**
   * Returns the address locator of this GameAddress.
   */
  const std::shared_ptr<GameAddressLocatorInterface>&
  address_locator(
      void
  ) const noexcept;

  /**
   * Returns the address of this GameAddress.
   */
  std::intptr_t
  raw_address(
      void
  ) const noexcept;

 private:
  std::filesystem::path library_path_;
  std::shared_ptr<GameAddressLocatorInterface> address_locator_;
  std::intptr_t raw_address_;
};

} // namespace sgd2mapi
#endif // __cplusplus

/**
 * C Interface
 */

#if !defined(__cplusplus) || defined(SGD2MAPI_DLLEXPORT)
struct SGD2MAPI_GameAddress;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * Creates a new GameAddress. The base library is specified using its name,
 * encoded in UTF-8. The game address locators are specified as an array of
 * pointers to GameAddressLocators.
 */
DLLEXPORT struct SGD2MAPI_GameAddress*
SGD2MAPI_GameAddress_CreateAsGameAddressFromLibraryPath(
    const char library_path[],
    const struct SGD2MAPI_GameAddressLocatorInterface*
        game_address_locator_interfaces[]
);

/**
 * Creates a new GameAddress. The base library is specified using its ID.
 * The game address locators are specified as an array of pointers to
 * GameAddressLocators.
 */
DLLEXPORT struct SGD2MAPI_GameAddress*
SGD2MAPI_GameAddress_CreateAsGameAddressFromLibraryId(
    enum SGD2MAPI_DefaultLibrary c_library_id,
    const struct SGD2MAPI_GameAddressLocatorInterface*
        c_game_address_locator_interfaces[]
);

/**
 * Create a new GameAddress. The base library is specified using its ID or its
 * name. The game address locators are specified as an array of pointers to
 * GameAddressLocators.
 */
#define SGD2MAPI_GameAddress_Create( \
    library, \
    c_game_address_locator_interfaces \
) _Generic( \
    (library), \
    char*: \
        SGD2MAPI_GameAddress_CreateAsGameAddressFromLibraryPath, \
    int: \
        SGD2MAPI_GameAddress_CreateAsGameAddressFromLibraryId \
)(dest, library, game_address_locator_interfaces)

/**
 * Frees the memory used by the specified game address.
 */
DLLEXPORT void
SGD2MAPI_GameAddress_Destroy(
    struct SGD2MAPI_GameAddress* c_game_address
);

/**
 * Returns the address value of the game address.
 */
DLLEXPORT intptr_t
SGD2MAPI_GameAddress_GetRawAddress(
    const struct SGD2MAPI_GameAddress* c_game_address
);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !defined(__cplusplus) || defined(SGD2MAPI_DLLEXPORT)

#undef DLLEXPORT
#endif // SGD2MAPI_GAME_ADDRESS_H_
