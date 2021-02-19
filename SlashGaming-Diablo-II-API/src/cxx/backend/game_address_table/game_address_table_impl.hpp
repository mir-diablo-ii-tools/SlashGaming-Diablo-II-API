/**
 * SlashGaming Diablo II Modding API for C++
 * Copyright (C) 2018-2021  Mir Drualga
 *
 * This file is part of SlashGaming Diablo II Modding API for C++.
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
 *  it with any Graphics Device Interface (GDI), DirectDraw, Direct3D,
 *  Glide, OpenGL, or Rave wrapper (or modified versions of those
 *  libraries), containing parts not covered by a compatible license, the
 *  licensors of this Program grant you additional permission to convey the
 *  resulting work.
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any library (or a modified version of that library) that links
 *  to Diablo II (or a modified version of that game and its libraries),
 *  containing parts not covered by a compatible license, the licensors of
 *  this Program grant you additional permission to convey the resulting
 *  work.
 */

#ifndef SGMAPI_CXX_BACKEND_GAME_ADDRESS_TABLE_GAME_ADDRESS_TABLE_IMPL_HPP_
#define SGMAPI_CXX_BACKEND_GAME_ADDRESS_TABLE_GAME_ADDRESS_TABLE_IMPL_HPP_

#include <string_view>
#include <utility>
#include <variant>
#include <tuple>

#include "../../../../include/cxx/default_game_library.hpp"
#include "game_address_locator/game_address_locator.hpp"

namespace mapi {

struct GameAddressTableEntry {
  constexpr GameAddressTableEntry(
      DefaultLibrary library,
      ::std::string_view address_name,
      GameAddressLocator address_locator
  ) noexcept
      : library(library),
        address_name(address_name),
        address_locator(std::move(address_locator)) {
  }

  DefaultLibrary library;
  ::std::string_view address_name;
  GameAddressLocator address_locator;
};

struct GameAddressTableEntryCompareKey {
  constexpr bool operator()(
      const GameAddressTableEntry& entry1,
      const GameAddressTableEntry& entry2
  ) const noexcept {
    if (entry1.library < entry2.library) {
      return true;
    } else if (entry1.library > entry2.library) {
      return false;
    }

    return entry1.address_name < entry2.address_name;
  }

  constexpr bool operator()(
      const ::std::tuple<DefaultLibrary, ::std::string_view>& key,
      const GameAddressTableEntry& entry
  ) const noexcept {
    if (::std::get<0>(key) < entry.library) {
      return true;
    } else if (::std::get<0>(key) > entry.library) {
      return false;
    }

    return ::std::get<1>(key) < entry.address_name;
  }

  constexpr bool operator()(
      const GameAddressTableEntry& entry,
      const ::std::tuple<DefaultLibrary, ::std::string_view>& key
  ) const noexcept {
    if (entry.library < ::std::get<0>(key)) {
      return true;
    } else if (entry.library > ::std::get<0>(key)) {
      return false;
    }

    return entry.address_name < ::std::get<1>(key);
  }
};

using GameAddressTable = ::std::pair<
    const GameAddressTableEntry*,
    std::size_t
>;

GameAddressTable LoadGameAddressTable();

} // namespace mapi

#endif // SGMAPI_CXX_BACKEND_GAME_ADDRESS_TABLE_GAME_ADDRESS_TABLE_IMPL_HPP_
