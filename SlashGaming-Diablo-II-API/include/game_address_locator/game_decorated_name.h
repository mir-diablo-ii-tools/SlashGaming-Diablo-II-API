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

#ifndef SGD2MAPI_GAME_ADDRESS_LOCATOR_GAME_DECORATED_NAME_H_
#define SGD2MAPI_GAME_ADDRESS_LOCATOR_GAME_DECORATED_NAME_H_

#include "game_address_locator_interface.h"

#ifdef __cplusplus
#include <cstdint>
#include <string>
#include <string_view>
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

class DLLEXPORT GameDecoratedName : public GameAddressLocatorInterface {
 public:
  explicit GameDecoratedName(std::string_view decorated_name);

  GameDecoratedName(const GameDecoratedName&);
  GameDecoratedName(GameDecoratedName&&) noexcept;

  ~GameDecoratedName() override;

  GameDecoratedName& operator=(const GameDecoratedName&);
  GameDecoratedName& operator=(GameDecoratedName&&) noexcept;

  std::intptr_t ResolveGameAddress(std::intptr_t base_address)
      const noexcept override;

  std::string_view decorated_name() const;

 private:
  std::string decorated_name_;
};

} // namespace sgd2mapi
#endif // __cplusplus

/**
 * C Interface
 */

#if !defined(__cplusplus) || defined(SGD2MAPI_DLLEXPORT)
struct SGD2MAPI_GameDecoratedName;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

DLLEXPORT struct SGD2MAPI_GameDecoratedName*
SGD2MAPI_GameDecoratedName_Create(
    const char decorated_name[]
);

DLLEXPORT struct SGD2MAPI_GameAddressLocatorInterface*
SGD2MAPI_GameDecoratedName_CreateAsGameAddressLocatorInterface(
    const char decorated_name[]
);

DLLEXPORT void
SGD2MAPI_GameDecoratedName_Destroy(
    struct SGD2MAPI_GameDecoratedName* c_game_decorated_name
);

DLLEXPORT struct SGD2MAPI_GameAddressLocatorInterface*
SGD2MAPI_GameDecoratedName_UpcastToGameAddressLocatorInterface(
    const struct SGD2MAPI_GameDecoratedName* c_game_decorated_name
);

DLLEXPORT struct SGD2MAPI_GameAddressLocatorInterface*
SGD2MAPI_GameDecoratedName_UpcastToGameAddressLocatorInterfaceThenDestroy(
    struct SGD2MAPI_GameDecoratedName* c_game_decorated_name
);

DLLEXPORT const char*
SGD2MAPI_GameDecoratedName_GetDecoratedName(
    const struct SGD2MAPI_GameDecoratedName* c_game_decorated_name
);


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !defined(__cplusplus) || defined(SGD2MAPI_DLLEXPORT)

#undef DLLEXPORT
#endif // SGD2MAPI_GAME_ADDRESS_LOCATOR_GAME_DECORATED_NAME_H_
