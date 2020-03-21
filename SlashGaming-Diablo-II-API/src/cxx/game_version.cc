/**
 * SlashGaming Diablo II Modding API for C++
 * Copyright (C) 2018-2020  Mir Drualga
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

#include "../../include/cxx/game_version.hpp"

#include <windows.h>
#include <cstdint>
#include <cstdlib>
#include <algorithm>
#include <filesystem>
#include <string>
#include <string_view>
#include <unordered_map>

#include <fmt/format.h>
#include "../../include/cxx/game_address.hpp"
#include "../wide_macro.h"
#include "backend/encoding.hpp"
#include "backend/error_handling.hpp"

namespace d2 {
namespace {

struct GameDataInfo {
  std::ptrdiff_t offset_value;
  std::filesystem::path library_path;
  GameVersion matching_version;
  GameVersion non_matching_version;
  std::vector<std::uint8_t> expected_values;
};

static const std::unordered_map<
    std::u8string_view, GameVersion
> kGameVersionsByFileVersions = {
    // 1.00 & 1.01 have the same version #, but use completely different
    // DLLs.
    { u8"1.0.0.1", GameVersion::k1_01 },
    { u8"1.0.2.0", GameVersion::k1_02 },
    { u8"1.0.3.0", GameVersion::k1_03 },
    // 1.04B and 1.04C use the same DLLs.
    { u8"1.0.4.1", GameVersion::k1_04B_C },
    { u8"1.0.4.2", GameVersion::k1_04B_C },
    { u8"1.0.5.0", GameVersion::k1_05 },
    { u8"1.0.5.1", GameVersion::k1_05B },
    // 1.06 & 1.06B have the same version #, but use completely different
    // DLLs.
    { u8"1.0.6.0", GameVersion::k1_06 },
    // 1.07 Beta & 1.07 have the same version #, but use completely
    // different DLLs.
    { u8"1.0.7.0", GameVersion::k1_07 },
    { u8"1.0.8.28", GameVersion::k1_08 },
    { u8"1.0.9.19", GameVersion::k1_09 },
    { u8"1.0.9.20", GameVersion::k1_09B },
    { u8"1.0.9.22", GameVersion::k1_09D },
    { u8"1.0.10.9", GameVersion::k1_10Beta },
    { u8"1.0.10.10", GameVersion::k1_10SBeta },
    { u8"1.0.10.39", GameVersion::k1_10 },
    { u8"1.0.11.45", GameVersion::k1_11 },
    { u8"1.0.11.46", GameVersion::k1_11B },
    { u8"1.0.12.49", GameVersion::k1_12A },
    { u8"1.0.13.55", GameVersion::k1_13ABeta },
    { u8"1.0.13.60", GameVersion::k1_13C },
    { u8"1.0.13.64", GameVersion::k1_13D },
    { u8"1.14.0.64", GameVersion::kLod1_14A },
    { u8"1.14.1.68", GameVersion::kLod1_14B },
    { u8"1.14.2.70", GameVersion::kLod1_14C },
    { u8"1.14.3.71", GameVersion::kLod1_14D },
};

static const std::unordered_map<
    GameVersion, std::u8string_view
> kGameVersionNamesByGameVersionIds = {
    { GameVersion::k1_00, u8"1.00" },
    { GameVersion::k1_01, u8"1.01" },
    { GameVersion::k1_02, u8"1.02" },
    { GameVersion::k1_03, u8"1.03" },
    // 1.04B and 1.04C use the same DLLs.
    { GameVersion::k1_04B_C, u8"1.04B/C" },
    { GameVersion::k1_05, u8"1.05" },
    { GameVersion::k1_05B, u8"1.05B" },
    { GameVersion::k1_06, u8"1.06" },
    { GameVersion::k1_06B, u8"1.06B" },
    { GameVersion::k1_07Beta, u8"1.07 Beta" },
    { GameVersion::k1_07, u8"1.07" },
    { GameVersion::k1_08, u8"1.08" },
    { GameVersion::k1_09, u8"1.09" },
    { GameVersion::k1_09B, u8"1.09B" },
    { GameVersion::k1_09D, u8"1.09D" },
    { GameVersion::k1_10Beta, u8"1.10 Beta" },
    { GameVersion::k1_10SBeta, u8"1.10S Beta" },
    { GameVersion::k1_10, u8"1.10" },
    { GameVersion::k1_11, u8"1.11" },
    { GameVersion::k1_11B, u8"1.11B" },
    { GameVersion::k1_12A, u8"1.12A" },
    { GameVersion::k1_13ABeta, u8"1.13A Beta" },
    { GameVersion::k1_13C, u8"1.13C" },
    { GameVersion::k1_13D, u8"1.13D" },
    { GameVersion::kClassic1_14A, u8"Classic 1.14A" },
    { GameVersion::kLod1_14A, u8"LoD 1.14A" },
    { GameVersion::kClassic1_14B, u8"Classic 1.14B" },
    { GameVersion::kLod1_14B, u8"LoD 1.14B" },
    { GameVersion::kClassic1_14C, u8"Classic 1.14C" },
    { GameVersion::kLod1_14C, u8"LoD 1.14C" },
    { GameVersion::kClassic1_14D, u8"Classic 1.14D" },
    { GameVersion::kLod1_14D, u8"LoD 1.14D" },
};

static const std::unordered_map<
    GameVersion, GameDataInfo
> kGameDataInfoByGameVersion = {
    {
        GameVersion::k1_01, {
            0xF0,
            "D2Client.dll",
            GameVersion::k1_00,
            GameVersion::k1_01,
            { 0xF0 }
        }
    }, {
        GameVersion::k1_06, {
            0xE8,
            "D2Client.dll",
            GameVersion::k1_06,
            GameVersion::k1_06B,
            { 0x3F }
        }
    }, {
        GameVersion::k1_07, {
            0x3C,
            "D2Client.dll",
            GameVersion::k1_07Beta,
            GameVersion::k1_07,
            { 0xF0 }
        }
    }, {
        GameVersion::kLod1_14A, {
            0x120,
            "Game.exe",
            GameVersion::kClassic1_14A,
            GameVersion::kLod1_14A,
            { 0x38 }
        }
    }, {
        GameVersion::kLod1_14B, {
            0x110,
            "Game.exe",
            GameVersion::kClassic1_14B,
            GameVersion::kLod1_14B,
            { 0xAE }
        }
    }, {
        GameVersion::kLod1_14C, {
            0x110,
            "Game.exe",
            GameVersion::kClassic1_14C,
            GameVersion::kLod1_14C,
            { 0x52 }
        }
    }, {
        GameVersion::kLod1_14C, {
            0x128,
            "Game.exe",
            GameVersion::kClassic1_14D,
            GameVersion::kLod1_14D,
            { 0xC4 }
        }
    },
};

std::u8string ExtractFileVersionString(
    const std::filesystem::path& file_path
) {
  // All the code for this function originated from StackOverflow user
  // crashmstr. Some parts were refactored for clarity.
  std::wstring file_path_text_wide = file_path.wstring();

  // Check version size.
  DWORD ignored;
  DWORD file_version_info_size = GetFileVersionInfoSizeW(
      file_path_text_wide.data(),
      &ignored
  );

  if (file_version_info_size == 0) {
    mapi::ExitOnWindowsFunctionFailureWithLastError(
        L"GetFileVersionInfoSizeW",
        GetLastError(),
        __FILEW__,
        __LINE__
    );
  }

  // Get the file version info.
  auto file_version_info = std::make_unique<wchar_t[]>(file_version_info_size);
  BOOL is_get_file_version_info_success = GetFileVersionInfoW(
      file_path_text_wide.data(),
      ignored,
      file_version_info_size,
      file_version_info.get()
  );

  if (!is_get_file_version_info_success) {
    mapi::ExitOnWindowsFunctionFailureWithLastError(
        L"GetFileVersionInfoW",
        GetLastError(),
        __FILEW__,
        __LINE__
    );
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
    mapi::ExitOnWindowsFunctionFailureWithLastError(
        L"VerQueryValueW",
        GetLastError(),
        __FILEW__,
        __LINE__
    );
  }

  // Doesn't matter if you are on 32 bit or 64 bit,
  // DWORD is always 32 bits, so first two revision numbers
  // come from dwFileVersionMS, last two come from dwFileVersionLS
  return fmt::format(
      u8"{}.{}.{}.{}",
      (version_info->dwFileVersionMS >> 16) & 0xFFFF,
      (version_info->dwFileVersionMS >> 0) & 0xFFFF,
      (version_info->dwFileVersionLS >> 16) & 0xFFFF,
      (version_info->dwFileVersionLS >> 0) & 0xFFFF
  );
}

static GameVersion DetermineGameVersionByFileVersion(
    std::u8string_view version_string
) {
  try {
    return kGameVersionsByFileVersions.at(version_string);
  } catch(const std::out_of_range& e) {
    std::wstring version_wide_string = mapi::ConvertUtf8ToWide(
        version_string,
        __FILEW__,
        __LINE__
    );

    constexpr std::wstring_view kErrorFormatMessage = L"Could not determine "
        L"the game version from the file version: \"{}\"";

    std::wstring full_message = fmt::format(
        kErrorFormatMessage,
        version_wide_string
    );

    mapi::ExitOnGeneralFailure(
        full_message,
        L"Failed to Determine Game Version",
        __FILEW__,
        __LINE__
    );
  }
}

static GameVersion DetermineGameVersionByGameData(
    GameVersion game_version
) {
  if (!kGameDataInfoByGameVersion.contains(game_version)) {
    return game_version;
  }

  const GameDataInfo& game_data_info = kGameDataInfoByGameVersion.at(
      game_version
  );

  mapi::GameAddress game_address = mapi::GameAddress::FromOffset(
      game_data_info.library_path,
      game_data_info.offset_value
  );

  std::intptr_t raw_address = game_address.raw_address();

  bool is_range_equal = std::equal(
      game_data_info.expected_values.cbegin(),
      game_data_info.expected_values.cend(),
      reinterpret_cast<const BYTE*>(raw_address)
  );

  if (is_range_equal) {
    return game_data_info.matching_version;
  } else {
    return game_data_info.non_matching_version;
  }
}

static GameVersion DetermineRunningGameVersion() {
  std::u8string game_version_string = ExtractFileVersionString(
      mapi::GetGameExecutablePath()
  );

  // Perform first stage game version detection using the executable file
  // name.
  GameVersion game_version = DetermineGameVersionByFileVersion(
      game_version_string
  );

  // Perform second stage game version detection by checking the bytes of game
  // libraries.
  game_version = DetermineGameVersionByGameData(game_version);

  return game_version;
}

} // namespace

std::u8string_view GetGameVersionName(GameVersion game_version) {
  try {
    return kGameVersionNamesByGameVersionIds.at(game_version);
  } catch (const std::out_of_range& e) {
    constexpr std::wstring_view kErrorFormatMessage =
        L"Could not determine the game version name from the game version ID: "
        L"{}.";

    std::wstring full_message = fmt::format(
        kErrorFormatMessage,
        static_cast<int>(game_version)
    );

    mapi::ExitOnGeneralFailure(
        full_message,
        L"Failed to Determine Game Version ID",
        __FILEW__,
        __LINE__
    );
  }
}

GameVersion GetRunningGameVersionId() {
  static GameVersion running_game_version_id = DetermineRunningGameVersion();

  return running_game_version_id;
}

std::u8string_view GetRunningGameVersionName() {
  static std::u8string_view running_game_version_name = GetGameVersionName(
      GetRunningGameVersionId()
  );
  return running_game_version_name;
}

bool IsGameVersionAtLeast1_14(GameVersion game_version) {
  return !(game_version >= GameVersion::k1_00
      && game_version <= GameVersion::k1_13D);
}

bool IsRunningGameVersionAtLeast1_14() {
  return IsGameVersionAtLeast1_14(GetRunningGameVersionId());
}

} // namespace d2
