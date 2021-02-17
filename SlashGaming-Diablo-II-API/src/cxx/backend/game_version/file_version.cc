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

#include "file_version.hpp"

#include <algorithm>
#include <array>
#include <utility>

#include <mdc/error/exit_on_error.hpp>
#include <mdc/wchar_t/filew.h>

namespace mapi::internal {
namespace {

using FileVersionTableEntry = std::pair<FileVersion, d2::GameVersion>;

struct FileVersionTableEntryCompareKey {
  constexpr bool operator()(
      const FileVersionTableEntry& entry1,
      const FileVersionTableEntry& entry2
  ) const noexcept {
    return entry1.first < entry2.first;
  }

  constexpr bool operator()(
      const FileVersionTableEntry& entry,
      const FileVersion& file_version
  ) const noexcept {
    return entry.first < file_version;
  }

  constexpr bool operator()(
      const FileVersion& file_version,
      const FileVersionTableEntry& entry
  ) const noexcept {
    return file_version < entry.first;
  }
};

static constexpr const std::array<
    FileVersionTableEntry,
    26
> kFileVersionSortedTable = {{
    { FileVersion(1, 0, 0, 1), d2::GameVersion::k1_01 },
    { FileVersion(1, 0, 2, 0), d2::GameVersion::k1_02 },
    { FileVersion(1, 0, 3, 0), d2::GameVersion::k1_03 },

    // 1.04B and 1.04C use the same DLLs.
    { FileVersion(1, 0, 4, 1), d2::GameVersion::k1_04B_C },
    { FileVersion(1, 0, 4, 2), d2::GameVersion::k1_04B_C },
    { FileVersion(1, 0, 5, 0), d2::GameVersion::k1_05 },
    { FileVersion(1, 0, 5, 1), d2::GameVersion::k1_05B },

    // 1.06 & 1.06B have the same version #, but use completely
    // different DLLs.
    { FileVersion(1, 0, 6, 0), d2::GameVersion::k1_06B },

    // 1.07 Beta & 1.07 have the same version #, but use completely
    // different DLLs.
    { FileVersion(1, 0, 7, 0), d2::GameVersion::k1_07 },
    { FileVersion(1, 0, 8, 28), d2::GameVersion::k1_08 },
    { FileVersion(1, 0, 9, 19), d2::GameVersion::k1_09 },
    { FileVersion(1, 0, 9, 20), d2::GameVersion::k1_09B },
    { FileVersion(1, 0, 9, 22), d2::GameVersion::k1_09D },
    { FileVersion(1, 0, 10, 9), d2::GameVersion::k1_10Beta },
    { FileVersion(1, 0, 10, 10), d2::GameVersion::k1_10SBeta },
    { FileVersion(1, 0, 10, 39), d2::GameVersion::k1_10 },
    { FileVersion(1, 0, 11, 45), d2::GameVersion::k1_11 },
    { FileVersion(1, 0, 11, 46), d2::GameVersion::k1_11B },
    { FileVersion(1, 0, 12, 49), d2::GameVersion::k1_12A },
    { FileVersion(1, 0, 13, 55), d2::GameVersion::k1_13ABeta },
    { FileVersion(1, 0, 13, 60), d2::GameVersion::k1_13C },
    { FileVersion(1, 0, 13, 64), d2::GameVersion::k1_13D },

    { FileVersion(1, 0, 14, 64), d2::GameVersion::kLod1_14A },
    { FileVersion(1, 0, 14, 68), d2::GameVersion::kLod1_14B },
    { FileVersion(1, 0, 14, 70), d2::GameVersion::kLod1_14C },
    { FileVersion(1, 0, 14, 71), d2::GameVersion::kLod1_14D },
}};

// If this assertion compiles but produces a linter error, ignore it.
static_assert(
    std::is_sorted(
        kFileVersionSortedTable.cbegin(),
        kFileVersionSortedTable.cend(),
        FileVersionTableEntryCompareKey()
    )
);

} // namespace

d2::GameVersion FileVersion::GuessGameVersion(
    std::wstring_view raw_path
) {
  FileVersion file_version = ReadFileVersion(raw_path);

  return SearchTable(file_version);
}

FileVersion FileVersion::ReadFileVersion(
    std::wstring_view raw_path
) {
  // All the code for this function originated from StackOverflow user
  // crashmstr. Some parts were refactored for clarity.
  const wchar_t* file_path_text_cstr = raw_path.data();

  // Check version size.
  DWORD ignored;
  DWORD file_version_info_size = GetFileVersionInfoSizeW(
      file_path_text_cstr,
      &ignored
  );

  if (file_version_info_size == 0) {
    ::mdc::error::ExitOnWindowsFunctionError(
        __FILEW__,
        __LINE__,
        L"GetFileVersionInfoSizeW",
        GetLastError()
    );

    return FileVersion(0, 0, 0, 0);
  }

  // Get the file version info.
  auto file_version_info = std::make_unique<wchar_t[]>(file_version_info_size);
  BOOL is_get_file_version_info_success = GetFileVersionInfoW(
      file_path_text_cstr,
      ignored,
      file_version_info_size,
      file_version_info.get()
  );

  if (!is_get_file_version_info_success) {
    ::mdc::error::ExitOnWindowsFunctionError(
        __FILEW__,
        __LINE__,
        L"GetFileVersionInfoW",
        GetLastError()
    );

    return FileVersion(0, 0, 0, 0);
  }

  // Gather all of the information into the specified buffer, then check
  // version info signature.
  UINT version_info_size;
  VS_FIXEDFILEINFO* version_info;

  BOOL is_ver_query_value_success = VerQueryValueW(
      file_version_info.get(),
      L"\\",
      reinterpret_cast<LPVOID*>(&version_info),
      &version_info_size
  );

  if (!is_ver_query_value_success) {
    ::mdc::error::ExitOnWindowsFunctionError(
        __FILEW__,
        __LINE__,
        L"VerQueryValueW",
        GetLastError()
    );

    return FileVersion(0, 0, 0, 0);
  }

  // Doesn't matter if you are on 32 bit or 64 bit,
  // DWORD is always 32 bits, so first two revision numbers
  // come from dwFileVersionMS, last two come from dwFileVersionLS
  return FileVersion(
      (version_info->dwFileVersionMS >> 16) & 0xFFFF,
      (version_info->dwFileVersionMS >> 0) & 0xFFFF,
      (version_info->dwFileVersionLS >> 16) & 0xFFFF,
      (version_info->dwFileVersionLS >> 0) & 0xFFFF
  );
}

d2::GameVersion FileVersion::SearchTable(
    const FileVersion& file_version
) {
  std::pair search_range = std::equal_range(
      kFileVersionSortedTable.cbegin(),
      kFileVersionSortedTable.cend(),
      file_version,
      FileVersionTableEntryCompareKey()
  );

  if (search_range.first == kFileVersionSortedTable.cend()) {
    ::mdc::error::ExitOnGeneralError(
        L"Error",
        L"Could not map the file version %d.%d.%d.%d to a known game"
            L"version.",
        __FILEW__,
        __LINE__,
        std::get<0>(file_version.version()),
        std::get<1>(file_version.version()),
        std::get<2>(file_version.version()),
        std::get<3>(file_version.version())
    );

    return static_cast<d2::GameVersion>(-1);
  }

  return search_range.first->second;
}

} // namespace mapi::internal
