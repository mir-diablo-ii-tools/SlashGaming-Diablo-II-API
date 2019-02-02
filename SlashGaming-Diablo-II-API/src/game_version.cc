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

#include "../include/game_version.h"

#include <windows.h>
#include <cstdint>
#include <cstdlib>
#include <algorithm>
#include <filesystem>
#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>

#include <boost/bimap.hpp>
#include <fmt/format.h>
#include <fmt/printf.h>
#include "../include/default_game_library.h"
#include "../include/game_address.h"

namespace sgd2mapi {
namespace {

using GameVersionAndStringBimapType = boost::bimap<
    enum GameVersion,
    std::string_view
>;

constexpr std::wstring_view kFunctionFailErrorFormat =
    L"File: %s \n"
    L"Line: %d \n"
    L"\n"
    L"The function %s failed with error code %x.";

const std::unordered_map<
    std::string_view,
    enum GameVersion
>&
GetGameVersionByFileVersion(
    void
) {
  static const std::unordered_map<
      std::string_view,
      enum GameVersion
  > game_version_by_file_version = {
        // 1.00 & 1.01 have the same version #, but use completely different
        // DLLs.
        { u8"1.0.0.1", GameVersion::k1_01 },
        { u8"1.0.2.0", GameVersion::k1_02 },
        { u8"1.0.3.0", GameVersion::k1_03 },
        { u8"1.0.4.0", GameVersion::k1_04 },
        // 1.04B and 1.04C use the same DLLs.
        { u8"1.0.4.1", GameVersion::k1_04B },
        { u8"1.0.4.2", GameVersion::k1_04C },
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
        { u8"1.0.9.21", GameVersion::k1_09C },
        { u8"1.0.9.22", GameVersion::k1_09D },
        { u8"1.0.9.23", GameVersion::k1_09E },
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
        { u8"1.14.3.71", GameVersion::kLod1_14D }
  };

  return game_version_by_file_version;
}

const GameVersionAndStringBimapType&
GetGameVersionAndStringBimap(
    void
) {
  static const std::array<
      GameVersionAndStringBimapType::value_type,
      36
  > version_array = {{
        { GameVersion::k1_00, u8"1.00" },
        { GameVersion::k1_01, u8"1.01" },
        { GameVersion::k1_02, u8"1.02" },
        { GameVersion::k1_03, u8"1.03" },
        { GameVersion::k1_04, u8"1.04" },
        // 1.04B and 1.04C use the same DLLs.
        { GameVersion::k1_04B, u8"1.04B" },
        { GameVersion::k1_04C, u8"1.04C" },
        { GameVersion::k1_05, u8"1.05" },
        { GameVersion::k1_05B, u8"1.05B" },
        { GameVersion::k1_06, u8"1.06" },
        { GameVersion::k1_06B, u8"1.06B" },
        { GameVersion::k1_07Beta, u8"1.07 Beta" },
        { GameVersion::k1_07, u8"1.07" },
        { GameVersion::k1_08, u8"1.08" },
        { GameVersion::k1_09, u8"1.09" },
        { GameVersion::k1_09B, u8"1.09B" },
        { GameVersion::k1_09C, u8"1.09C" },
        { GameVersion::k1_09D, u8"1.09D" },
        { GameVersion::k1_09E, u8"1.09E" },
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
        { GameVersion::kLod1_14D, u8"LoD 1.14D" }
  }};

  static const GameVersionAndStringBimapType game_version_and_string_bimap(
      version_array.cbegin(),
      version_array.cend()
  );

  return game_version_and_string_bimap;
}

std::string
ExtractFileVersionString(
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
    std::wstring full_message = fmt::sprintf(
        kFunctionFailErrorFormat.data(),
        fmt::to_wstring(__FILE__),
        __LINE__,
        L"GetFileVersionInfoSizeW",
        GetLastError()
    );

    MessageBoxW(
        nullptr,
        full_message.data(),
        L"GetFileVersionInfoSizeW Failed",
        MB_OK | MB_ICONERROR
    );

    std::exit(0);
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
    std::wstring full_message = fmt::sprintf(
        kFunctionFailErrorFormat,
        fmt::to_wstring(__FILE__),
        __LINE__,
        L"GetFileVersionInfoW",
        GetLastError()
    );

    MessageBoxW(
        nullptr,
        full_message.data(),
        L"GetFileVersionInfoW Failed",
        MB_OK | MB_ICONERROR
    );

    std::exit(0);
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
    std::wstring full_message = fmt::sprintf(
        kFunctionFailErrorFormat,
        fmt::to_wstring(__FILE__),
        __LINE__,
        L"VerQueryValueW",
        GetLastError()
    );

    MessageBoxW(
        nullptr,
        full_message.data(),
        L"VerQueryValueW Failed",
        MB_OK | MB_ICONERROR
    );

    std::exit(0);
  }

  // Doesn't matter if you are on 32 bit or 64 bit,
  // DWORD is always 32 bits, so first two revision numbers
  // come from dwFileVersionMS, last two come from dwFileVersionLS
  return fmt::sprintf(
      u8"%d.%d.%d.%d",
      (version_info->dwFileVersionMS >> 16) & 0xFFFF,
      (version_info->dwFileVersionMS >> 0) & 0xFFFF,
      (version_info->dwFileVersionLS >> 16) & 0xFFFF,
      (version_info->dwFileVersionLS >> 0) & 0xFFFF
  );
}

enum GameVersion
GetGameVersionByFileVersion(
    std::string_view version_string
) {
  const auto& game_versions_by_file_version =
      GetGameVersionByFileVersion();

  try {
    return game_versions_by_file_version.at(version_string);
  } catch(const std::out_of_range& e) {
    constexpr std::wstring_view kErrorFormatMessage =
        L"File: %s \n"
        L"Line: %d \n"
        L"\n"
        L"Could not determine the game version from the file version:"
        L"\"%s\".";

    std::wstring full_message = fmt::sprintf(
        kErrorFormatMessage,
        fmt::to_wstring(__FILE__),
        __LINE__,
        fmt::to_wstring(version_string)
    );

    MessageBoxW(
        nullptr,
        full_message.data(),
        L"Failed to Determine Game Version",
        MB_OK | MB_ICONERROR
    );

    std::exit(0);
  }
}

enum GameVersion
GetGameVersionByLibraryData(
    enum GameVersion game_version
) {
  // When detecting game address, we need to specify the library as a path and
  // not with the enum. The enum requires knowledge of the current game
  // version, and if this function is called, we know that the game version is
  // not yet known.

  std::vector<BYTE> expected_values;
  std::filesystem::path library_path;
  std::intptr_t offset_value;
  enum GameVersion matching_version;
  enum GameVersion non_matching_version;

  switch (game_version) {
    case GameVersion::k1_01: {
      expected_values = {
          0xA0, 0xDC, 0xED, 0x12, 0x10, 0xC3
      };

      library_path = u8"D2Client.dll";
      offset_value = 0x12E30;
      matching_version = GameVersion::k1_00;
      non_matching_version = GameVersion::k1_01;

      break;
    }

    case GameVersion::k1_06: {
      expected_values = {
          0xA0, 0x24, 0x30, 0xC4, 0x6F, 0xC3
      };

      library_path = u8"D2Client.dll",
      offset_value = 0x9B80;
      matching_version = GameVersion::k1_06;
      non_matching_version = GameVersion::k1_06B;

      break;
    }

    case GameVersion::k1_07: {
      expected_values = {
          0xA0, 0x54, 0x4C, 0x11, 0x10, 0xC3
      };

      library_path = u8"D2Client.dll";
      offset_value = 0xB2B0;
      matching_version = GameVersion::k1_07Beta;
      non_matching_version = GameVersion::k1_07;

      break;
    }

    case GameVersion::kLod1_14A: {
      expected_values = {
          0xA0, 0xCC, 0xE1, 0x82, 0x00, 0xC3
      };

      library_path = u8"Game.exe";
      offset_value = 0x52360;
      matching_version = GameVersion::kClassic1_14A;
      non_matching_version = GameVersion::kLod1_14A;

      break;
    }

    case GameVersion::kLod1_14B: {
      expected_values = {
          0xA0, 0x4C, 0x6C, 0x79, 0x00, 0xC3
      };

      library_path = u8"Game.exe";
      offset_value = 0x3ADF0;
      matching_version = GameVersion::kClassic1_14B;
      non_matching_version = GameVersion::kLod1_14B;

      break;
    }

    case GameVersion::kLod1_14C: {
      expected_values = {
          0xA0, 0x4C, 0x5C, 0x79, 0x00, 0xC3
      };

      library_path = u8"Game.exe";
      offset_value = 0x3ADF0;
      matching_version = GameVersion::kClassic1_14C;
      non_matching_version = GameVersion::kLod1_14C;

      break;
    }

   case GameVersion::kLod1_14D: {
      expected_values = {
          0xA0, 0xC4, 0xEB, 0x79, 0x00, 0xC3
      };

      library_path = u8"Game.exe";
      offset_value = 0x3F4F0;
      matching_version = GameVersion::kClassic1_14D;
      non_matching_version = GameVersion::kLod1_14D;

      break;
    }

    default: {
      return game_version;
    }
  }

  GameAddress game_address(
      std::move(library_path),
      GameOffset(offset_value)
  );

  std::intptr_t raw_address = game_address.raw_address();

  bool is_range_equal = std::equal(
      expected_values.cbegin(),
      expected_values.cend(),
      reinterpret_cast<const BYTE*>(raw_address)
  );

  if (is_range_equal) {
    return matching_version;
  } else {
    return non_matching_version;
  }
}

enum GameVersion
DetermineRunningGameVersion(
    void
) {
  // TODO(Mir Drualga): Figure out how to get versions 1.06(B) and 1.14+
  // classic detection.
  std::string game_version_string = ExtractFileVersionString(
      GetGameExecutablePath()
  );

  // Perform first stage game version detection using the executable file
  // name.
  enum GameVersion game_version = GetGameVersionByFileVersion(
      game_version_string
  );

  // Perform second stage game version detection by checking the bytes of game
  // libraries.
  game_version = GetGameVersionByLibraryData(game_version);

  return game_version;
}

} // namespace

std::string_view
GetGameVersionName(
    enum GameVersion game_version
) {
  try {
    return GetGameVersionAndStringBimap().left.at(game_version);
  } catch (const std::out_of_range& e) {
    constexpr std::wstring_view kErrorFormatMessage =
        L"File: %s \n"
        L"Line: %d \n"
        L"\n"
        L"Could not determine the game version name from the game version ID: "
        L"%d.";

    std::wstring full_message = fmt::sprintf(
        kErrorFormatMessage,
        fmt::to_wstring(__FILE__),
        __LINE__,
        static_cast<int>(game_version)
    );

    MessageBoxW(
        nullptr,
        full_message.data(),
        L"Failed to Determine Game Version ID",
        MB_OK | MB_ICONERROR
    );

    std::exit(0);
  }
}

enum GameVersion
GetRunningGameVersionId(
    void
) {
  static enum GameVersion running_game_version_id =
      DetermineRunningGameVersion();
  return running_game_version_id;
}

std::string_view
GetRunningGameVersionName(
    void
) {
  static std::string_view running_game_version_name = GetGameVersionName(
      GetRunningGameVersionId()
  );
  return running_game_version_name;
}

bool
IsGameVersionAtLeast1_14(
    enum GameVersion game_version
) {
  return !(game_version >= GameVersion::k1_00
               && game_version <= GameVersion::k1_13D);
}

bool
IsRunningGameVersionAtLeast1_14(
    void
) {
  return IsGameVersionAtLeast1_14(
      GetRunningGameVersionId()
  );
}

} // namespace sgd2mapi

/**
 * C Interface
 */

char*
SGD2MAPI_GetGameVersionName(
    char dest[],
    enum SGD2MAPI_GameVersion game_version
) {
  sgd2mapi::GameVersion actual_game_version_id =
      static_cast<sgd2mapi::GameVersion>(game_version);

  std::string_view game_version_name = sgd2mapi::GetGameVersionName(
      actual_game_version_id
  );

  std::copy(
      game_version_name.cbegin(),
      game_version_name.cend(),
      dest
  );

  return dest;
}

std::size_t
SGD2MAPI_GetGameVersionNameSize(
    enum SGD2MAPI_GameVersion game_version
) {
  sgd2mapi::GameVersion actual_game_version_id =
    static_cast<sgd2mapi::GameVersion>(game_version);

  std::string_view game_version_name = sgd2mapi::GetGameVersionName(
    actual_game_version_id
  );

  return game_version_name.size() + 1;
}

enum SGD2MAPI_GameVersion
SGD2MAPI_GetRunningGameVersionId(
    void
) {
  return static_cast<enum SGD2MAPI_GameVersion>(
      sgd2mapi::GetRunningGameVersionId()
  );
}

char*
SGD2MAPI_GetRunningGameVersionName(
    char dest[]
) {
  std::string_view game_version_name =
      sgd2mapi::GetRunningGameVersionName();

  std::copy(
      game_version_name.cbegin(),
      game_version_name.cend(),
      dest
  );

  return dest;
}

std::size_t
SGD2MAPI_GetRunningGameVersionNameSize(
    void
) {
  std::string_view game_version_name =
      sgd2mapi::GetRunningGameVersionName();

  return game_version_name.size() + 1;
}

bool
SGD2MAPI_IsGameVersionAtLeast1_14(
    enum SGD2MAPI_GameVersion game_version
) {
  return sgd2mapi::IsGameVersionAtLeast1_14(
      static_cast<sgd2mapi::GameVersion>(game_version)
  );
}

bool
SGD2MAPI_IsRunningGameVersionAtLeast1_14(
    void
) {
  return sgd2mapi::IsRunningGameVersionAtLeast1_14();
}
