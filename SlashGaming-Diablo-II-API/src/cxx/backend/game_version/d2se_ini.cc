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

#include "d2se_ini.hpp"

#include <windows.h>

#include <algorithm>
#include <array>

#include <mdc/wchar_t/filew.h>
#include <mdc/error/exit_on_error.hpp>

namespace mapi::intern {
namespace {

using VersionStringTableEntry = ::std::pair<
    ::std::wstring_view,
    ::d2::GameVersion
>;

struct VersionStringEntryTableCompareKey {
  constexpr bool operator()(
      const VersionStringTableEntry& entry1,
      const VersionStringTableEntry& entry2
  ) const noexcept {
    return entry1.first < entry2.first;
  }

  constexpr bool operator()(
      const VersionStringTableEntry::first_type& key,
      const VersionStringTableEntry& entry
  ) const noexcept {
    return key < entry.first;
  }

  constexpr bool operator()(
      const VersionStringTableEntry& entry,
      const VersionStringTableEntry::first_type& key
  ) const noexcept {
    return entry.first < key;
  }
};

static constexpr ::std::wstring_view kSectionName = L"Protected";
static constexpr ::std::wstring_view kKeyName = L"D2Core";
static constexpr ::std::wstring_view kFileName = L"./D2SE_SETUP.ini";

static constexpr ::std::array<
    VersionStringTableEntry,
    8
> kVersionStringTable = {{
    { L"1.07", ::d2::GameVersion::k1_07 },
    { L"1.08", ::d2::GameVersion::k1_08 },
    { L"1.09b", ::d2::GameVersion::k1_09B },
    { L"1.09d", ::d2::GameVersion::k1_09D },
    { L"1.10f", ::d2::GameVersion::k1_10 },
    { L"1.11b", ::d2::GameVersion::k1_11B },
    { L"1.12a", ::d2::GameVersion::k1_12A },
    { L"1.13c", ::d2::GameVersion::k1_13C }
}};

// If this assertion compiles but produces a linter error, ignore it.
static_assert(
    std::is_sorted(
        kVersionStringTable.cbegin(),
        kVersionStringTable.cend(),
        VersionStringEntryTableCompareKey()
    )
);

// The capacity needs to be increased manually depending on the table's key.
constexpr ::std::size_t kVersionStringCapacity = 7;

// If this assertion compiles but produces a linter error, ignore it.
static_assert(
    ::std::all_of(
        kVersionStringTable.cbegin(),
        kVersionStringTable.cend(),
        [&](const auto& entry) {
          return entry.first.length() < (kVersionStringCapacity - 1);
        }
    )
);

} // namespace

::d2::GameVersion D2SEIni::GetGameVersion() {
  ::std::wstring version_str = ReadVersionString();

  return SearchTable(version_str);
}

::std::wstring D2SEIni::ReadVersionString() {
  ::std::array<wchar_t, kVersionStringCapacity> version_c_str;

  DWORD get_private_profile_string_result = GetPrivateProfileStringW(
      kSectionName.data(),
      kKeyName.data(),
      L"",
      version_c_str.data(),
      kVersionStringCapacity,
      kFileName.data()
  );

  if (get_private_profile_string_result == kVersionStringCapacity - 1) {
    ::mdc::error::ExitOnGeneralError(
        L"Error",
        L"D2SE.ini Diablo II version string is invalid.",
        __FILEW__,
        __LINE__
    );

    return L"";
  }

  return version_c_str.data();
}

::d2::GameVersion D2SEIni::SearchTable(
    ::std::wstring_view version_str
) {
  ::std::pair search_range = ::std::equal_range(
      kVersionStringTable.cbegin(),
      kVersionStringTable.cend(),
      version_str,
      VersionStringEntryTableCompareKey()
  );

  if (search_range.first == kVersionStringTable.cend()
      || search_range.first == search_range.second) {
    ::mdc::error::ExitOnGeneralError(
        L"Error",
        L"Unknown D2SE.ini Diablo II version string %s.",
        __FILEW__,
        __LINE__,
        version_str.data()
    );

    return static_cast<::d2::GameVersion>(-1);
  }

  return search_range.first->second;
}

} // namespace mapi::intern
