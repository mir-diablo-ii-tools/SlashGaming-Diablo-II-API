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

#ifndef SGD2MAPI_GAME_ADDRESS_LOCATOR_GAME_ADDRESS_LOCATOR_INTERFACE_H_
#define SGD2MAPI_GAME_ADDRESS_LOCATOR_GAME_ADDRESS_LOCATOR_INTERFACE_H_

#ifdef __cplusplus
#include <cstdint>
#include <memory>
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
 * An interface for game address locator implementations that specify a
 * location in game memory.
 */
class DLLEXPORT GameAddressLocatorInterface {
 public:
  virtual
  ~GameAddressLocatorInterface(
      void
  );

  /**
   * Clones this game address locator and returns a pointer to the clone.
   */
  virtual GameAddressLocatorInterface*
  Clone(
      void
  ) const = 0;

  /**
   * Destructively moves all data into a clone and returns a pointer to the
   * clone.
   */
  virtual GameAddressLocatorInterface*
  MoveToClone(
      void
  ) = 0;

  /**
   * Resolves the destination game address, using the provided library base
   * address.
   */
  virtual std::intptr_t
  ResolveGameAddress(
      std::intptr_t base_address
  ) const = 0;
};

} // namespace sgd2mapi
#endif // __cplusplus

/**
 * C Interface
 */

#if !defined(__cplusplus) || defined(SGD2MAPI_DLLEXPORT)
struct SGD2MAPI_GameAddressLocatorInterface;

#ifdef __cplusplus
struct SGD2MAPI_GameAddressLocatorInterface {
  std::shared_ptr<sgd2mapi::GameAddressLocatorInterface> actual_ptr;
};

extern "C" {
#endif // __cplusplus

/**
 * Frees the memory used by the specified game address locator.
 */
DLLEXPORT void
SGD2MAPI_GameAddressLocatorInterface_Destroy(
    struct SGD2MAPI_GameAddressLocatorInterface*
        c_game_address_locator_interface
);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !defined(__cplusplus) || defined(SGD2MAPI_DLLEXPORT)

#undef DLLEXPORT
#endif // SGD2MAPI_GAME_ADDRESS_LOCATOR_GAME_ADDRESS_LOCATOR_INTERFACE_H_
