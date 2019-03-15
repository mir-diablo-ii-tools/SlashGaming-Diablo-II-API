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

#include "../../include/game_address_locator/game_decorated_name.hpp"

#include <windows.h>
#include <cstdint>
#include <cstdlib>
#include <memory>
#include <string>
#include <string_view>
#include <utility>

#include <fmt/format.h>
#include <fmt/printf.h>

namespace sgd2mapi {

GameDecoratedName::GameDecoratedName(
    const char decorated_name[]
)
    : decorated_name_(decorated_name) {
}

GameDecoratedName::GameDecoratedName(
    const std::string& decorated_name
)
    : decorated_name_(decorated_name) {
}

GameDecoratedName::GameDecoratedName(
    std::string&& decorated_name
)
    : decorated_name_(std::move(decorated_name)) {
}

GameDecoratedName::GameDecoratedName(
    std::string_view decorated_name
)
    : decorated_name_(decorated_name.data()) {
}

GameDecoratedName::GameDecoratedName(
    const GameDecoratedName&
) = default;

GameDecoratedName::GameDecoratedName(
    GameDecoratedName&&
) noexcept = default;

GameDecoratedName::~GameDecoratedName(
    void
) = default;

GameDecoratedName&
GameDecoratedName::operator=(
    const GameDecoratedName&
) = default;

GameDecoratedName&
GameDecoratedName::operator=(
    GameDecoratedName&&
) noexcept = default;

GameDecoratedName*
GameDecoratedName::Clone(
    void
) const {
  return new GameDecoratedName(*this);
}

GameDecoratedName*
GameDecoratedName::MoveToClone(
    void
) {
  return new GameDecoratedName(
      std::move(this->decorated_name_)
  );
}

std::intptr_t
GameDecoratedName::ResolveGameAddress(
    std::intptr_t base_address
) const {
  HMODULE library_handle = reinterpret_cast<HMODULE>(base_address);
  const CHAR* c_decorated_name = decorated_name().data();

  FARPROC func_address = GetProcAddress(library_handle, c_decorated_name);

  if (func_address == nullptr) {
    std::wstring error_message = fmt::sprintf(
        L"The data or function with the name %s could not be found.",
        fmt::to_wstring(decorated_name())
    );

    MessageBoxW(
        nullptr,
        error_message.data(),
        L"Failed to Locate Address",
        MB_OK | MB_ICONERROR
    );
    std::exit(0);
  }

  return reinterpret_cast<std::intptr_t>(func_address);
}

const std::string&
GameDecoratedName::decorated_name(
    void
) const noexcept {
  return decorated_name_;
}

} // namespace sgd2mapi

/**
 * C Interface
 */

struct SGD2MAPI_GameDecoratedName*
SGD2MAPI_GameDecoratedName_Create(
    const char decorated_name[]
) {
  struct SGD2MAPI_GameDecoratedName* c_game_decorated_name =
      new SGD2MAPI_GameDecoratedName;

  c_game_decorated_name->actual_ptr =
      std::make_shared<sgd2mapi::GameDecoratedName>(
          decorated_name
      );

  return c_game_decorated_name;
}

struct SGD2MAPI_GameAddressLocatorInterface*
SGD2MAPI_GameDecoratedName_CreateAsGameAddressLocatorInterface(
    const char decorated_name[]
) {
  struct SGD2MAPI_GameAddressLocatorInterface*
      c_game_address_locator_interface =
          new SGD2MAPI_GameAddressLocatorInterface;

  c_game_address_locator_interface->actual_ptr =
      std::make_shared<sgd2mapi::GameDecoratedName>(
          decorated_name
      );

  return c_game_address_locator_interface;
}

void
SGD2MAPI_GameDecoratedName_Destroy(
    struct SGD2MAPI_GameDecoratedName* c_game_decorated_name
) {
  delete c_game_decorated_name;
}

struct SGD2MAPI_GameAddressLocatorInterface*
SGD2MAPI_GameDecoratedName_UpcastToGameAddressLocatorInterface(
    struct SGD2MAPI_GameDecoratedName* c_game_decorated_name
) {
  struct SGD2MAPI_GameAddressLocatorInterface*
      c_game_address_locator_interface =
          new SGD2MAPI_GameAddressLocatorInterface;

  c_game_address_locator_interface->actual_ptr =
      c_game_decorated_name->actual_ptr;

  return c_game_address_locator_interface;
}

struct SGD2MAPI_GameAddressLocatorInterface*
SGD2MAPI_GameDecoratedName_UpcastToGameAddressLocatorInterfaceThenDestroy(
    struct SGD2MAPI_GameDecoratedName* c_game_decorated_name
) {
  struct SGD2MAPI_GameAddressLocatorInterface*
      c_game_address_locator_interface =
          SGD2MAPI_GameDecoratedName_UpcastToGameAddressLocatorInterface(
              c_game_decorated_name
          );

  SGD2MAPI_GameDecoratedName_Destroy(c_game_decorated_name);

  return c_game_address_locator_interface;
}

const char*
SGD2MAPI_GameDecoratedName_GetDecoratedName(
    const struct SGD2MAPI_GameDecoratedName* c_game_decorated_name
) {
  return c_game_decorated_name->actual_ptr->decorated_name().data();
}
