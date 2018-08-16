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

#include "game_address.h"

#include <windows.h>
#include <cstdlib>
#include <memory>
#include <stdexcept>
#include <string_view>
#include <unordered_map>

#include <boost/format.hpp>
#include "game_address_locator.h"
#include "game_library.h"
#include "game_library_table.h"
#include "game_version.h"

namespace sgd2mapi {

namespace {

std::intptr_t ResolveGameAddress(
    std::string_view library_path,
    const std::unordered_map<
        enum GameVersion,
        std::shared_ptr<GameAddressLocatorInterface>
    >& address_locators) noexcept {
  enum GameVersion current_version =
      RunningGameVersion::GetInstance().game_version();

  const GameLibrary& address_library =
      GameLibraryTable::GetInstance().GetGameLibrary(library_path);

  std::intptr_t resolved_address;

  try {
    const auto& running_address_locator =
        address_locators.at(current_version);

    std::intptr_t base_address = address_library.base_address();

    resolved_address =
        running_address_locator->ResolveGameAddress(base_address);
  } catch (std::out_of_range&) {
    std::wstring error_message = (boost::wformat(
        L"Game address not defined for the game version: %s. The game will "
        L"nowexit.") % RunningGameVersion::GetVersionName(
                           RunningGameVersion::GetInstance().game_version()
                       ).data()).str();
    MessageBoxW(nullptr,
                error_message.data(),
                L"Error: Missing Game Address",
                MB_OK | MB_ICONERROR);
    std::exit(EXIT_FAILURE);
  }

  return resolved_address;
}

} // namespace

GameAddress::GameAddress(
    std::string_view library_path,
    const std::unordered_map<
        enum GameVersion,
        std::shared_ptr<GameAddressLocatorInterface>
    >& address_locators) noexcept
    : address_(ResolveGameAddress(library_path, address_locators)) {
}

GameAddress::GameAddress(
    enum DefaultLibrary library,
    const std::unordered_map<
        enum GameVersion,
        std::shared_ptr<GameAddressLocatorInterface>
    >& address_locators) noexcept
    : GameAddress(GameLibrary::GetLibraryPathWithRedirect(library),
                  address_locators) {
}

GameAddress::GameAddress(const GameAddress&) noexcept = default;

GameAddress::GameAddress(GameAddress&&) noexcept = default;

GameAddress& GameAddress::operator=(const GameAddress&) noexcept = default;

GameAddress& GameAddress::operator=(GameAddress&&) noexcept = default;

std::intptr_t GameAddress::address() const noexcept {
  return address_;
}

} // namespace sgd2mapi
