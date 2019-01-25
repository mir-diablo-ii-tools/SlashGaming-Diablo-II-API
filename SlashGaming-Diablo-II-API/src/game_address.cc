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

#include "../include/game_address.h"

#include <windows.h>
#include <filesystem>
#include <cstdlib>
#include <memory>
#include <stdexcept>
#include <unordered_map>

#include <fmt/format.h>
#include <fmt/printf.h>
#include "../include/game_address_locator.h"
#include "../include/game_library.h"
#include "game_library_table.h"
#include "../include/game_version.h"

#include "c/game_address.h"
#include "game_address_locator/c/game_address_locator_interface.h"

namespace sgd2mapi {
namespace {

std::intptr_t
ResolveRawAddress(
    const std::filesystem::path& library_path,
    const GameAddressLocatorInterface& address_locator
) {

  // Figure out which game library is specified.
  const GameLibrary& address_library = GetGameLibrary(library_path);

  // Calculate the resolved address
  std::intptr_t base_address = address_library.base_address();
  std::intptr_t resolved_address =
      address_locator.ResolveGameAddress(base_address);

  return resolved_address;
}

std::shared_ptr<GameAddressLocatorInterface>
ResolveGameAddressLocator(
    const std::filesystem::path& library_path,
    const std::unordered_map<
        enum GameVersion,
        std::shared_ptr<GameAddressLocatorInterface>
    >& address_locators
) {
  enum GameVersion current_version = GetRunningGameVersionId();

  const GameLibrary& address_library = GetGameLibrary(library_path);

  try {
    return address_locators.at(current_version);
  } catch (const std::out_of_range& e) {
    constexpr std::wstring_view kErrorFormatMessage =
        L"File: %s \n"
        L"Line: %d \n"
        L"Could not determine the game address.";

    std::wstring full_message = fmt::sprintf(
        kErrorFormatMessage,
        fmt::to_wstring(__FILE__),
        __LINE__,
        library_path
    );

    MessageBoxW(
        nullptr,
        full_message.data(),
        L"Failed to Determine Game Address",
        MB_OK | MB_ICONERROR
    );

    std::exit(0);
  }
}

} // namespace

GameAddress::GameAddress(
    const std::filesystem::path& library_path,
    const GameAddressLocatorInterface& address_locator
)
    : GameAddress(
          library_path,
          std::shared_ptr<GameAddressLocatorInterface>(
              address_locator.Clone()
          )
      ) {
}

GameAddress::GameAddress(
    std::filesystem::path&& library_path,
    const GameAddressLocatorInterface& address_locator
)
    : GameAddress(
          std::move(library_path),
          std::shared_ptr<GameAddressLocatorInterface>(
              address_locator.Clone()
          )
      ) {
}

GameAddress::GameAddress(
    const std::filesystem::path& library_path,
    std::shared_ptr<GameAddressLocatorInterface> address_locator
)
    : library_path_(library_path),
      address_locator_(std::move(address_locator)),
      raw_address_(ResolveRawAddress(library_path_, *address_locator_)) {
}

GameAddress::GameAddress(
    std::filesystem::path&& library_path,
    std::shared_ptr<GameAddressLocatorInterface> address_locator
)
    : library_path_(std::move(library_path)),
      address_locator_(std::move(address_locator)),
      raw_address_(ResolveRawAddress(library_path_, *address_locator_)) {
}

GameAddress::GameAddress(
    enum DefaultLibrary library,
    const GameAddressLocatorInterface& address_locator
)
    : GameAddress(
          GetLibraryPathWithRedirect(library),
          address_locator
      ) {
}

GameAddress::GameAddress(
    enum DefaultLibrary library,
    std::shared_ptr<GameAddressLocatorInterface> address_locator
)
    : GameAddress(
          GetLibraryPathWithRedirect(library),
          std::move(address_locator)
      ) {
}

GameAddress::GameAddress(
    const std::filesystem::path& library_path,
    const std::unordered_map<
        enum GameVersion,
        std::shared_ptr<GameAddressLocatorInterface>
    >& address_locators
)
    : GameAddress(
          library_path,
          ResolveGameAddressLocator(
              library_path,
              address_locators
          )
      ) {
}

GameAddress::GameAddress(
    std::filesystem::path&& library_path,
    const std::unordered_map<
        enum GameVersion,
        std::shared_ptr<GameAddressLocatorInterface>
    >& address_locators
)
    : GameAddress(
          std::move(library_path),
          ResolveGameAddressLocator(
              library_path,
              address_locators
          )
      ) {
}

GameAddress::GameAddress(
    enum DefaultLibrary library,
    const std::unordered_map<
        enum GameVersion,
        std::shared_ptr<GameAddressLocatorInterface>
    >& address_locators
)
    : GameAddress(
          GetLibraryPathWithRedirect(library),
          address_locators
      ) {
}

GameAddress::GameAddress(
    const GameAddress&
) = default;

GameAddress::GameAddress(
    GameAddress&&
) noexcept = default;

GameAddress&
GameAddress::operator=(
    const GameAddress&
) = default;

GameAddress&
GameAddress::operator=(
    GameAddress&&
) noexcept = default;

const std::filesystem::path&
GameAddress::library_path(
    void
) const noexcept {
  return library_path_;
}

const std::shared_ptr<GameAddressLocatorInterface>&
GameAddress::address_locator(
    void
) const noexcept {
  return address_locator_;
}

std::intptr_t
GameAddress::raw_address(
    void
) const noexcept {
  return raw_address_;
}

} // namespace sgd2mapi

struct SGD2MAPI_GameAddress*
SGD2MAPI_GameAddress_CreateAsGameAddressFromLibraryPath(
    const char library_path[],
    const struct SGD2MAPI_GameAddressLocatorInterface*
        c_game_address_locator_interfaces[]
) {
  // Pull the game address locator corresponding to the running game version.
  int game_version_value =
      static_cast<int>(sgd2mapi::GetRunningGameVersionId());
  const struct SGD2MAPI_GameAddressLocatorInterface*
      running_game_address_locator_interface =
          c_game_address_locator_interfaces[game_version_value];

  const sgd2mapi::GameAddressLocatorInterface*
      actual_game_address_locator_interface =
          running_game_address_locator_interface->actual_ptr.get();

  // Create a new game address and return it.
  struct SGD2MAPI_GameAddress* c_game_address =
      new SGD2MAPI_GameAddress;
  c_game_address->actual_ptr =
      std::make_shared<sgd2mapi::GameAddress>(
          library_path,
          *actual_game_address_locator_interface
      );

  return c_game_address;
}

struct SGD2MAPI_GameAddress*
SGD2MAPI_GameAddress_CreateAsGameAddressFromLibraryId(
    enum SGD2MAPI_DefaultLibrary c_library_id,
    const struct SGD2MAPI_GameAddressLocatorInterface*
        c_game_address_locator_interfaces[]
) {
  // Pull the game address locator corresponding to the running game version.
  int game_version_value = static_cast<int>(
      sgd2mapi::GetRunningGameVersionId()
  );

  const struct SGD2MAPI_GameAddressLocatorInterface*
      running_game_address_locator_interface =
          c_game_address_locator_interfaces[game_version_value];

  enum sgd2mapi::DefaultLibrary actual_library_id =
      static_cast<enum sgd2mapi::DefaultLibrary>(c_library_id);

  const sgd2mapi::GameAddressLocatorInterface*
      actual_game_address_locator_interface =
          running_game_address_locator_interface->actual_ptr.get();

  SGD2MAPI_GameAddress* c_game_address =
      new SGD2MAPI_GameAddress;

  c_game_address->actual_ptr = std::make_shared<sgd2mapi::GameAddress>(
      actual_library_id,
      *actual_game_address_locator_interface
  );

  return c_game_address;
}

void
SGD2MAPI_GameAddress_Destroy(
    struct SGD2MAPI_GameAddress* c_game_address
) {
  delete c_game_address;
}

std::intptr_t
SGD2MAPI_GameAddress_GetRawAddress(
    const struct SGD2MAPI_GameAddress* c_game_address
) {
  return c_game_address->actual_ptr->raw_address();
}
