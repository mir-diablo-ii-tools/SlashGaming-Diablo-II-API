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

#include "../../../include/cxx/helper/d2_determine_video_mode.hpp"

#include <windows.h>

#include <cstddef>
#include <string_view>

#include <mdc/error/exit_on_error.hpp>
#include <mdc/wchar_t/filew.h>
#include "../../../include/cxx/game_executable.hpp"
#include "../backend/game_version/file_signature.hpp"

namespace d2 {
namespace {

static constexpr ::std::wstring_view kD2SEIniFileName = L"./D2SE_SETUP.ini";
static constexpr ::std::wstring_view kD2SESectionName = L"USERSETTINGS";
static constexpr ::std::wstring_view kD2SERendererKeyName = L"Renderer";
static constexpr ::std::wstring_view kD2SEWindowModeKeyName = L"WindowMode";

static VideoMode_1_00 GetVideoModeFromRegValue_1_00(DWORD reg_value) {
  switch (reg_value) {
    case 0: {
      return VideoMode_1_00::kDirectDraw;
    }

    case 1: {
      return VideoMode_1_00::kDirect3D;
    }

    case 3: {
      return VideoMode_1_00::kGlide;
    }

    case 4: {
      return VideoMode_1_00::kGdi;
    }

    default: {
      return VideoMode_1_00::kDirectDraw;
    }
  }
}

static VideoMode_1_00 GetCommandLineVideoMode() {
  VideoMode_1_00 video_mode = VideoMode_1_00::kDirectDraw;

  ::std::wstring_view command_line = GetCommandLineW();

  if (command_line.find(L"-3dfx") != ::std::wstring_view::npos) {
    video_mode = VideoMode_1_00::kGlide;
  } else if (command_line.find(L"-w") != ::std::wstring_view::npos) {
    video_mode = VideoMode_1_00::kGdi;
  } else if (command_line.find(L"-d3d") != ::std::wstring_view::npos) {
    video_mode = VideoMode_1_00::kDirect3D;
  }

  return video_mode;
}

static VideoMode_1_00 GetRegistryVideoMode() {
  HKEY query_key_result;

  LSTATUS reg_open_key_status = RegOpenKeyExW(
      HKEY_CURRENT_USER,
      L"SOFTWARE\\Blizzard Entertainment\\Diablo II\\VideoConfig",
      0,
      KEY_QUERY_VALUE,
      &query_key_result
  );

  if (reg_open_key_status != ERROR_SUCCESS) {
    reg_open_key_status = RegOpenKeyExW(
        HKEY_LOCAL_MACHINE,
        L"SOFTWARE\\Blizzard Entertainment\\Diablo II\\VideoConfig",
        0,
        KEY_QUERY_VALUE,
        &query_key_result
    );

    if (reg_open_key_status != ERROR_SUCCESS) {
      return VideoMode_1_00::kDirectDraw;
    }
  }

  DWORD render_value;
  DWORD render_value_size = sizeof(render_value);

  LSTATUS reg_query_value_status = RegQueryValueExW(
      query_key_result,
      L"Render",
      nullptr,
      nullptr,
      reinterpret_cast<LPBYTE>(&render_value),
      &render_value_size
  );

  RegCloseKey(query_key_result);

  return GetVideoModeFromRegValue_1_00(render_value);
}

static VideoMode GetD2SEVideoMode() {
  int renderer_value = GetPrivateProfileIntW(
      kD2SESectionName.data(),
      kD2SERendererKeyName.data(),
      -1,
      kD2SEIniFileName.data()
  );

  switch (renderer_value) {
    case 0: {
      int window_mode_value = GetPrivateProfileIntW(
          kD2SESectionName.data(),
          kD2SEWindowModeKeyName.data(),
          -1,
          kD2SEIniFileName.data()
      );

      return (window_mode_value == 1)
          ? ::d2::VideoMode::kGdi
          : ::d2::VideoMode::kDirectDraw;
    }

    case 1: {
      return ::d2::VideoMode::kDirect3D;
    }

    case 3: {
      return ::d2::VideoMode::kGlide;
    }

    default: {
      ::mdc::error::ExitOnConstantMappingError(
          __FILEW__,
          __LINE__,
          renderer_value
      );

      return static_cast<::d2::VideoMode>(-1);
    }
  }
}

} // namespace

VideoMode DetermineVideoMode() {
  ::std::wstring_view executable_raw_path =
      ::mapi::game_executable::GetPath().c_str();

  if (::mapi::intern::FileSignature::IsD2SE(executable_raw_path)) {
    return GetD2SEVideoMode();
  }

  return ToApiValue_1_00(DetermineVideoMode_1_00());
}

VideoMode_1_00 DetermineVideoMode_1_00() {
  VideoMode_1_00 command_line_video_mode = GetCommandLineVideoMode();

  if (command_line_video_mode != VideoMode_1_00::kDirectDraw) {
    return command_line_video_mode;
  }

  VideoMode_1_00 reg_video_mode = GetRegistryVideoMode();
  return reg_video_mode;
}

} // namespace d2
