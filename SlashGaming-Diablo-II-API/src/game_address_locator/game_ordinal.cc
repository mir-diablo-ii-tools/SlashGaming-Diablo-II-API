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

#include "../../include/game_address_locator/game_ordinal.h"

#include <windows.h>
#include <cstdint>
#include <cstdlib>
#include <memory>
#include <string>

#include <fmt/format.h>
#include <fmt/printf.h>
#include "../../include/game_address_locator/game_address_locator_interface.h"

#include "c/game_address_locator_interface.h"
#include "c/game_ordinal.h"

namespace sgd2mapi {

GameOrdinal::GameOrdinal(
    int ordinal
)
    : ordinal_(ordinal) {
  if ((ordinal & 0xFFFF) != ordinal) {
    std::wstring error_message = fmt::sprintf(
        L"Invalid ordinal value %d. The leftmost four bytes of an ordinal must"
        L"be zero.",
        ordinal
    );
    MessageBoxW(
        nullptr,
        error_message.data(),
        L"Invalid Ordinal Value",
        MB_OK | MB_ICONERROR
    );
    std::exit(0);
  }
}

GameOrdinal::GameOrdinal(
    const GameOrdinal&
) = default;

GameOrdinal::GameOrdinal(
    GameOrdinal&&
) noexcept = default;

GameOrdinal::~GameOrdinal(
    void
) = default;

GameOrdinal&
GameOrdinal::operator=(
    const GameOrdinal&
) = default;

GameOrdinal&
GameOrdinal::operator=(
    GameOrdinal&&
) noexcept = default;

GameAddressLocatorInterface*
GameOrdinal::Clone(
    void
) const {
  return new GameOrdinal(*this);
}

std::intptr_t
GameOrdinal::ResolveGameAddress(
    std::intptr_t base_address
) const {
  HMODULE library_handle = reinterpret_cast<HMODULE>(base_address);
  const CHAR* func_ordinal = reinterpret_cast<const CHAR*>(ordinal());

  FARPROC func_address = GetProcAddress(library_handle, func_ordinal);

  if (func_address == nullptr) {
    std::wstring error_message = fmt::sprintf(
        L"The data or function with the ordinal %d could not be found.",
        ordinal()
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

int
GameOrdinal::ordinal(
    void
) const noexcept {
  return ordinal_;
}

} // namespace sgd2mapi

/**
 * C Interface
 */

struct SGD2MAPI_GameOrdinal*
SGD2MAPI_GameOrdinal_Create(
    int ordinal
) {
  struct SGD2MAPI_GameOrdinal* c_game_ordinal = new SGD2MAPI_GameOrdinal;
  c_game_ordinal->actual_ptr =
      std::make_shared<sgd2mapi::GameOrdinal>(ordinal);

  return c_game_ordinal;
}

struct SGD2MAPI_GameAddressLocatorInterface*
SGD2MAPI_GameOrdinal_CreateAsGameAddressLocatorInterface(
    int ordinal
) {
  struct SGD2MAPI_GameAddressLocatorInterface*
      c_game_address_locator_interface =
          new SGD2MAPI_GameAddressLocatorInterface;

  c_game_address_locator_interface->actual_ptr =
      std::make_shared<sgd2mapi::GameOrdinal>(ordinal);

  return c_game_address_locator_interface;
}

void
SGD2MAPI_GameOrdinal_Destroy(
    struct SGD2MAPI_GameOrdinal* c_game_ordinal
) {
  delete c_game_ordinal;
}

struct SGD2MAPI_GameAddressLocatorInterface*
SGD2MAPI_GameOrdinal_UpcastToGameAddressLocatorInterface(
    const struct SGD2MAPI_GameOrdinal* c_game_ordinal
) {
  struct SGD2MAPI_GameAddressLocatorInterface*
      c_game_address_locator_interface =
          new SGD2MAPI_GameAddressLocatorInterface;

  c_game_address_locator_interface->actual_ptr =
      c_game_ordinal->actual_ptr;

  return c_game_address_locator_interface;
}

struct SGD2MAPI_GameAddressLocatorInterface*
SGD2MAPI_GameOrdinal_UpcastToGameAddressLocatorInterfaceThenDestroy(
    struct SGD2MAPI_GameOrdinal* c_game_ordinal
) {
  struct SGD2MAPI_GameAddressLocatorInterface*
      c_game_address_locator_interface =
          SGD2MAPI_GameOrdinal_UpcastToGameAddressLocatorInterface(
              c_game_ordinal
          );

  SGD2MAPI_GameOrdinal_Destroy(c_game_ordinal);

  return c_game_address_locator_interface;
}

int
SGD2MAPI_GameOrdinal_GetOrdinal(
    const struct SGD2MAPI_GameOrdinal* c_game_ordinal
) {
  return c_game_ordinal->actual_ptr->ordinal();
}
