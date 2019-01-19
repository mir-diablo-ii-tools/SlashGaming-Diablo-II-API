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

#include <cstdlib>
#include <memory>
#include <sstream>
#include <string>
#include <string_view>

#include <boost/bimap.hpp>
#include <fmt/format.h>
#include <fmt/printf.h>
#include "../include/game_library.h"

namespace sgd2mapi {
namespace {

using GameVersionAndFileVersionBimapType = boost::bimap<
    enum GameVersion,
    std::string_view
>;

using GameVersionAndStringBimapType = boost::bimap<
    enum GameVersion,
    std::string_view
>;

constexpr std::wstring_view kFunctionFailErrorFormat =
    L"File: %s, Line: %d \n"
    L"The function %s failed with error code %x.";

const GameVersionAndFileVersionBimapType&
GetGameVersionAndFileVersionBimap(
    void
) {
  static const std::array<
      GameVersionAndFileVersionBimapType::value_type,
      29
  > version_array = {{
        // TODO(Mir Drualga): 1.00 & 1.01 have the same version #, but use
        // completely different DLLs
        { GameVersion::k1_00, u8"1.0.0.1" },
        { GameVersion::k1_02, u8"1.0.2.0" },
        { GameVersion::k1_03, u8"1.0.3.0" },
        { GameVersion::k1_04, u8"1.0.4.0" },
        // 1.04B and 1.04C use the same DLLs
        { GameVersion::k1_04B, u8"1.0.4.1" },
        { GameVersion::k1_04C, u8"1.0.4.2" },
        { GameVersion::k1_05, u8"1.0.5.0" },
        { GameVersion::k1_05B, u8"1.0.5.1" },
        // TODO(Mir Drualga): 1.06 & 1.06B have the same version #, but use
        // completely different DLLs
        { GameVersion::k1_06, u8"1.0.6.0" },
        // TODO(Mir Drualga): 1.07 Beta & 1.07 have the same version #, but use
        // completely different DLLs
        { GameVersion::k1_07, u8"1.0.7.0" },
        { GameVersion::k1_08, u8"1.0.8.28" },
        { GameVersion::k1_09, u8"1.0.9.19" },
        { GameVersion::k1_09B, u8"1.0.9.20" },
        { GameVersion::k1_09C, u8"1.0.9.21" },
        { GameVersion::k1_09D, u8"1.0.9.22" },
        { GameVersion::k1_09E, u8"1.0.9.23" },
        { GameVersion::k1_10Beta, u8"1.0.10.9" },
        { GameVersion::k1_10SBeta, u8"1.0.10.10" },
        { GameVersion::k1_10, u8"1.0.10.39" },
        { GameVersion::k1_11, u8"1.0.11.45" },
        { GameVersion::k1_11B, u8"1.0.11.46" },
        { GameVersion::k1_12A, u8"1.0.12.49" },
        { GameVersion::k1_13ABeta, u8"1.0.13.55" },
        { GameVersion::k1_13C, u8"1.0.13.60" },
        { GameVersion::k1_13D, u8"1.0.13.64" },
        { GameVersion::kLod1_14A, u8"1.14.0.64" },
        { GameVersion::kLod1_14B, u8"1.14.1.68" },
        { GameVersion::kLod1_14C, u8"1.14.2.70" },
        { GameVersion::kLod1_14D, u8"1.14.3.71" }
  }};

  static const GameVersionAndFileVersionBimapType
      game_version_and_file_version_bimap(
          version_array.cbegin(),
          version_array.cend()
      );

  return game_version_and_file_version_bimap;
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

std::string ExtractFileVersionString(
    const std::filesystem::path& file_path
) noexcept {
  // All the code for this function originated from StackOverflow user
  // crashmstr. Some parts were refactored for clarity.
  std::wstring file_path_text_wide = file_path.wstring();

  // Check version size.
  DWORD version_handle;
  DWORD file_version_info_size = GetFileVersionInfoSizeW(
      file_path_text_wide.data(),
      &version_handle
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
      version_handle,
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
  std::ostringstream stringStream;

  stringStream << ((version_info->dwFileVersionMS >> 16) & 0xFFFF) << u8".";
  stringStream << ((version_info->dwFileVersionMS >> 0) & 0xFFFF) << u8".";
  stringStream << ((version_info->dwFileVersionLS >> 16) & 0xFFFF) << u8".";
  stringStream << ((version_info->dwFileVersionLS >> 0) & 0xFFFF);

  return stringStream.str();
}

enum GameVersion
GetGameVersionByFileVersion(
    std::string_view version_string
) {
  const auto& game_versions_by_file_version =
      GetGameVersionAndFileVersionBimap().right;

  try {
    return game_versions_by_file_version.at(version_string);
  } catch(const std::out_of_range& e) {
    constexpr std::wstring_view kErrorFormatMessage =
        L"File: %s, Line %d \n"
        L"Could not determine the game version from the file version: %s.";

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
DetermineRunningGameVersion(
    void
) noexcept {
  // TODO(Mir Drualga): Figure out how to get versions 1.06(B) and 1.14+
  // classic detection.
  std::string game_version_string = ExtractFileVersionString(
      GetGameExecutable()
  );

  enum GameVersion game_version = GetGameVersionByFileVersion(
      game_version_string
  );

  return game_version;
}

/**
 * A singleton class that detects the game version on runtime and stores this
 * information.
 */
class RunningGameVersion {
 public:
  RunningGameVersion(
      const RunningGameVersion&
  ) = delete;

  RunningGameVersion(
      RunningGameVersion&&
  ) = delete;

  RunningGameVersion&
  operator=(
      const RunningGameVersion&
  ) = delete;

  RunningGameVersion&
  operator=(
      RunningGameVersion&&
  ) = delete;

  /**
   * Returns the singleton instance of RunningGameVersion.
   */
  static RunningGameVersion&
  GetInstance(
      void
  ) noexcept {
    static RunningGameVersion instance;
    return instance;
  }

  /**
   * Returns the running game's version.
   */
  constexpr enum GameVersion
  game_version_id(
      void
  ) const noexcept {
    return game_version_id_;
  }

  constexpr std::string_view
  game_version_name(
      void
  ) const noexcept {
    return game_version_name_;
  }

 private:
  enum GameVersion game_version_id_;
  std::string_view game_version_name_;

  RunningGameVersion(
      void
  ) noexcept
    : game_version_id_(DetermineRunningGameVersion()),
      game_version_name_(GetGameVersionName(game_version_id())) {
  }
};

} // namespace

enum GameVersion
GetGameVersionId(
    std::string_view game_version_name
) noexcept {
  try {
    return GetGameVersionAndStringBimap().right.at(game_version_name);
  } catch (const std::out_of_range& e) {
    constexpr std::wstring_view kErrorFormatMessage =
        L"File: %s \n"
        L"Line: %d \n"
        L"Could not determine the game version ID from the version name: %s.";

    std::wstring full_message = fmt::sprintf(
        kErrorFormatMessage,
        fmt::to_wstring(__FILE__),
        __LINE__,
        fmt::to_wstring(game_version_name)
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

std::string_view
GetGameVersionName(
    enum GameVersion game_version
) noexcept {
  try {
    return GetGameVersionAndStringBimap().left.at(game_version);
  } catch (const std::out_of_range& e) {
    constexpr std::wstring_view kErrorFormatMessage =
        L"File: %s \n"
        L"Line: %d \n"
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
) noexcept {
  return RunningGameVersion::GetInstance().game_version_id();
}

std::string_view
GetRunningGameVersionName(
    void
) noexcept {
  return RunningGameVersion::GetInstance().game_version_name();
}

bool
IsGameVersionAtLeast1_14(
    enum GameVersion game_version
) noexcept {
  return !(game_version >= GameVersion::k1_00
               && game_version <= GameVersion::k1_13D);
}

bool
IsRunningGameVersionAtLeast1_14(
    void
) noexcept {
  return IsGameVersionAtLeast1_14(
      RunningGameVersion::GetInstance().game_version_id()
  );
}

} // namespace sgd2mapi

/**
 * C Interface
 */

const char*
SGD2MAPI_GetGameVersionName(
    enum SGD2MAPI_GameVersion game_version
) {
  return sgd2mapi::GetGameVersionName(
      static_cast<sgd2mapi::GameVersion>(game_version)
  ).data();
}

enum SGD2MAPI_GameVersion
SGD2MAPI_GetGameVersionId(
    const char* game_version_name
) {
  return static_cast<enum SGD2MAPI_GameVersion>(
      sgd2mapi::GetGameVersionId(game_version_name)
  );
}

enum SGD2MAPI_GameVersion
SGD2MAPI_GetRunningGameVersionId(
    void
) {
  return static_cast<enum SGD2MAPI_GameVersion>(
      sgd2mapi::GetRunningGameVersionId()
  );
}

const char*
SGD2MAPI_GetRunningGameVersionName(
    void
) {
  return sgd2mapi::GetRunningGameVersionName().data();
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
