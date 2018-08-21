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

class DLLEXPORT GameAddress {
 public:
  explicit GameAddress(std::intptr_t address) noexcept;

  GameAddress(std::string_view library_path,
              const GameAddressLocatorInterface& address_locator) noexcept;

  GameAddress(enum DefaultLibrary library,
              const GameAddressLocatorInterface& address_locator) noexcept;

  GameAddress(std::string_view library_path,
              const std::unordered_map<
                  enum GameVersion,
                  std::shared_ptr<GameAddressLocatorInterface>
              >& address_locators) noexcept;

  GameAddress(enum DefaultLibrary library,
              const std::unordered_map<
                  enum GameVersion,
                  std::shared_ptr<GameAddressLocatorInterface>
              >& address_locators) noexcept;

  GameAddress(const GameAddress&) noexcept;
  GameAddress(GameAddress&&) noexcept;

  GameAddress& operator=(const GameAddress&) noexcept;
  GameAddress& operator=(GameAddress&&) noexcept;

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

DLLEXPORT void sgd2mapi_game_address_create_from_library_path(
    struct SGD2MAPI_GameAddress* dest,
    const char* library_path,
    const struct SGD2MAPI_GameAddressLocatorInterface* game_address_locators[]
);

DLLEXPORT void sgd2mapi_game_address_create_from_library_id(
    struct SGD2MAPI_GameAddress* dest,
    enum SGD2MAPI_DefaultLibrary library_id,
    const struct SGD2MAPI_GameAddressLocatorInterface* game_address_locators[]
);

/**
 * Initializes the value of the specified destination with a new GameAddress
 * using the specified parameters. The library can be either a library ID or
 * the null-terminated string name of the library. The game address locator
 * array is a pointer to a one-dimensional array of pointers to
 * GameAddressLocator objects.
 */
#define sgd2mapi_game_address_create( \
    dest, \
    library, \
    game_address_locators\
) _Generic( \
    (library), \
    char*: \
        sgd2mapi_game_address_create_from_library_path \
    struct SGD2MAPI_GameAddressLocatorInterface*: \
        sgd2mapi_game_address_create_from_library_id \
)(dest, library, game_address_locators)

DLLEXPORT void sgd2mapi_game_address_destroy(
    struct SGD2MAPI_GameAddress* game_address
);

DLLEXPORT intptr_t sgd2mapi_game_address_get_address(
    const struct SGD2MAPI_GameAddress* game_address
);

#ifdef __cplusplus
}
#endif // __cplusplus

#undef DLLEXPORT
#endif // SGD2MAPI_GAME_ADDRESS_H_
