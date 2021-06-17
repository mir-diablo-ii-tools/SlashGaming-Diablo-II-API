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

#include "game_version_file_version.hpp"

#include <windows.h>

#include <algorithm>
#include <array>
#include <utility>

#include <mdc/wchar_t/filew.h>
#include <mdc/error/exit_on_error.hpp>
#include "../../../../include/cxx/game_executable.hpp"
#include "../file/fixed_file_version.hpp"

namespace d2::intern {
namespace {

using FileVersionTableEntry = ::std::pair<
    ::mapi::FixedFileVersion,
    ::d2::GameVersion
>;

struct FileVersionTableEntryCompareKey {
  constexpr bool operator()(
      const FileVersionTableEntry& entry1,
      const FileVersionTableEntry& entry2
  ) const noexcept {
    return entry1.first < entry2.first;
  }

  constexpr bool operator()(
      const FileVersionTableEntry& entry,
      const FileVersionTableEntry::first_type& file_version
  ) const noexcept {
    return entry.first < file_version;
  }

  constexpr bool operator()(
      const FileVersionTableEntry::first_type& file_version,
      const FileVersionTableEntry& entry
  ) const noexcept {
    return file_version < entry.first;
  }
};

static constexpr const ::std::array kFileVersionSortedTable =
    ::std::to_array<FileVersionTableEntry>({
        { ::mapi::FixedFileVersion(1, 0, 0, 1), GameVersion::k1_01 },
        { ::mapi::FixedFileVersion(1, 0, 2, 0), GameVersion::k1_02 },
        { ::mapi::FixedFileVersion(1, 0, 3, 0), GameVersion::k1_03 },

        // 1.04B and 1.04C use the same DLLs.
        { ::mapi::FixedFileVersion(1, 0, 4, 1), GameVersion::k1_04B_C },
        { ::mapi::FixedFileVersion(1, 0, 4, 2), GameVersion::k1_04B_C },
        { ::mapi::FixedFileVersion(1, 0, 5, 0), GameVersion::k1_05 },
        { ::mapi::FixedFileVersion(1, 0, 5, 1), GameVersion::k1_05B },

        // 1.06 & 1.06B have the same version #, but use completely
        // different DLLs.
        { ::mapi::FixedFileVersion(1, 0, 6, 0), GameVersion::k1_06B },

        // 1.07 Beta & 1.07 have the same version #, but use completely
        // different DLLs.
        { ::mapi::FixedFileVersion(1, 0, 7, 0), GameVersion::k1_07 },
        { ::mapi::FixedFileVersion(1, 0, 8, 28), GameVersion::k1_08 },
        { ::mapi::FixedFileVersion(1, 0, 9, 19), GameVersion::k1_09 },
        { ::mapi::FixedFileVersion(1, 0, 9, 20), GameVersion::k1_09B },
        { ::mapi::FixedFileVersion(1, 0, 9, 22), GameVersion::k1_09D },
        { ::mapi::FixedFileVersion(1, 0, 10, 9), GameVersion::k1_10Beta },
        { ::mapi::FixedFileVersion(1, 0, 10, 10), GameVersion::k1_10SBeta },
        { ::mapi::FixedFileVersion(1, 0, 10, 39), GameVersion::k1_10 },
        { ::mapi::FixedFileVersion(1, 0, 11, 45), GameVersion::k1_11 },
        { ::mapi::FixedFileVersion(1, 0, 11, 46), GameVersion::k1_11B },
        { ::mapi::FixedFileVersion(1, 0, 12, 49), GameVersion::k1_12A },
        { ::mapi::FixedFileVersion(1, 0, 13, 55), GameVersion::k1_13ABeta },
        { ::mapi::FixedFileVersion(1, 0, 13, 60), GameVersion::k1_13C },
        { ::mapi::FixedFileVersion(1, 0, 13, 64), GameVersion::k1_13D },

        { ::mapi::FixedFileVersion(1, 14, 0, 64), GameVersion::kLod1_14A },
        { ::mapi::FixedFileVersion(1, 14, 1, 68), GameVersion::kLod1_14B },
        { ::mapi::FixedFileVersion(1, 14, 2, 70), GameVersion::kLod1_14C },
        { ::mapi::FixedFileVersion(1, 14, 3, 71), GameVersion::kLod1_14D },
    });

// If this assertion compiles but produces a linter error, ignore it.
static_assert(
    ::std::ranges::is_sorted(
        kFileVersionSortedTable,
        FileVersionTableEntryCompareKey()
    )
);

static GameVersion SearchTable(
    const ::mapi::FixedFileVersion& fixed_file_version
) {
  ::std::pair search_range = ::std::equal_range(
      kFileVersionSortedTable.cbegin(),
      kFileVersionSortedTable.cend(),
      fixed_file_version,
      FileVersionTableEntryCompareKey()
  );

  if (search_range.first == kFileVersionSortedTable.cend()
      || search_range.first == search_range.second) {
    ::mdc::error::ExitOnGeneralError(
        L"Error",
        L"Could not map the file version %u.%u.%u.%u to a known game"
            L"version.",
        __FILEW__,
        __LINE__,
        fixed_file_version.major_high,
        fixed_file_version.major_low,
        fixed_file_version.minor_high,
        fixed_file_version.minor_low
    );

    return static_cast<d2::GameVersion>(-1);
  }

  return search_range.first->second;
}

} // namespace

GameVersion GuessGameVersion() {
  const VS_FIXEDFILEINFO& fixed_file_info =
      ::mapi::game_executable::QueryFixedFileInfo();

  ::mapi::FixedFileVersion fixed_file_version(
      fixed_file_info.dwFileVersionMS >> (sizeof(WORD) * CHAR_BIT),
      fixed_file_info.dwFileVersionMS & 0xFFFF,
      fixed_file_info.dwFileVersionLS >> (sizeof(WORD) * CHAR_BIT),
      fixed_file_info.dwFileVersionLS & 0xFFFF
  );

  return SearchTable(fixed_file_version);
}

} // namespace d2::intern
