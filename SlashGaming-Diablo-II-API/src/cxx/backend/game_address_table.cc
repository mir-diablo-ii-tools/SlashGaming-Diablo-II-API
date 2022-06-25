/**
 * SlashGaming Diablo II Modding API for C++
 * Copyright (C) 2018-2022  Mir Drualga
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

#include "game_address_table.hpp"

#include <cstddef>
#include <algorithm>
#include <array>
#include <string>

#include <mdc/error/exit_on_error.hpp>
#include <mdc/wchar_t/filew.h>
#include <mdc/wchar_t/wide_decoding.hpp>
#include "game_address_table/game_address_table_impl.hpp"

namespace mapi {
namespace {

static constexpr std::size_t kAddressNameWideCapacity = 1024;

static ::std::array<wchar_t, kAddressNameWideCapacity> address_name_wide;

static const GameAddressTable& GetGameAddressTable() {
  static GameAddressTable game_address_table = LoadGameAddressTable();

  return game_address_table;
}

} // namespace

GameAddress LoadGameAddress(
    ::d2::DefaultLibrary library,
    const char* address_name
) {
  const GameAddressTable& game_address_table = GetGameAddressTable();

  const GameAddressTableEntry* table = game_address_table.first;
  std::size_t table_count = game_address_table.second;

  ::std::pair search_range = ::std::equal_range(
      &table[0],
      &table[table_count],
      ::std::make_tuple(library, address_name),
      GameAddressTableEntryCompareKey()
  );

  if (search_range.first == &table[table_count]
      || search_range.first == search_range.second) {
    std::size_t address_name_wide_length = ::mdc::wide::DecodeAsciiLength(
        address_name
    );

    const wchar_t* address_name_wide_ptr;

    if (address_name_wide_length >= kAddressNameWideCapacity) {
      address_name_wide_ptr = L"**Name is longer than character limit**";
    } else {
      address_name_wide_ptr = ::mdc::wide::DecodeAscii(
          address_name_wide.data(),
          address_name
      );
    }

    ::mdc::error::ExitOnGeneralError(
        L"Error",
        L"Could not locate address named \"%ls\" for library with value %d.",
        __FILEW__,
        __LINE__,
        address_name_wide_ptr,
        static_cast<int>(library)
    );

    return GameAddress::FromOffset(static_cast<d2::DefaultLibrary>(-1), 0);
  }

  return search_range.first->second.LocateGameAddress();
}

} // namespace mapi
