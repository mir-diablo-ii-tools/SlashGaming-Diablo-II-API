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

#include <mdc/wchar_t/filew.h>
#include <mdc/error/exit_on_error.hpp>
#include "../../../../include/cxx/game_executable.hpp"
#include "../file/fixed_file_version.hpp"

namespace d2::intern {
namespace {

static GameVersion SearchTable(
    const ::mapi::FixedFileVersion& fixed_file_version
) {
  switch (fixed_file_version.ToValue()) {
    case ::mapi::FixedFileVersion(1, 0, 0, 1).ToValue(): {
      return GameVersion::k1_01;
    }

    case ::mapi::FixedFileVersion(1, 0, 2, 0).ToValue(): {
      return GameVersion::k1_02;
    }

    case ::mapi::FixedFileVersion(1, 0, 3, 0).ToValue(): {
      return GameVersion::k1_03;
    }

    // 1.04B and 1.04C use the same DLLs.
    case ::mapi::FixedFileVersion(1, 0, 4, 1).ToValue(): {
      return GameVersion::k1_04B_C;
    }

    case ::mapi::FixedFileVersion(1, 0, 4, 2).ToValue(): {
      return GameVersion::k1_04B_C;
    }

    case ::mapi::FixedFileVersion(1, 0, 5, 0).ToValue(): {
      return GameVersion::k1_05;
    }

    case ::mapi::FixedFileVersion(1, 0, 5, 1).ToValue(): {
      return GameVersion::k1_05B;
    }

    // 1.06 & 1.06B have the same version #, but use completely
    // different DLLs.
    case ::mapi::FixedFileVersion(1, 0, 6, 0).ToValue(): {
      return GameVersion::k1_06B;
    }

    // 1.07 Beta & 1.07 have the same version #, but use completely
    // different DLLs.
    case ::mapi::FixedFileVersion(1, 0, 7, 0).ToValue(): {
      return GameVersion::k1_07;
    }

    case ::mapi::FixedFileVersion(1, 0, 8, 28).ToValue(): {
      return GameVersion::k1_08;
    }

    case ::mapi::FixedFileVersion(1, 0, 9, 19).ToValue(): {
      return GameVersion::k1_09;
    }

    case ::mapi::FixedFileVersion(1, 0, 9, 20).ToValue(): {
      return GameVersion::k1_09B;
    }

    case ::mapi::FixedFileVersion(1, 0, 9, 22).ToValue(): {
      return GameVersion::k1_09D;
    }

    case ::mapi::FixedFileVersion(1, 0, 10, 9).ToValue(): {
      return GameVersion::k1_10Beta;
    }

    case ::mapi::FixedFileVersion(1, 0, 10, 10).ToValue(): {
      return GameVersion::k1_10SBeta;
    }

    case ::mapi::FixedFileVersion(1, 0, 10, 39).ToValue(): {
      return GameVersion::k1_10;
    }

    case ::mapi::FixedFileVersion(1, 0, 11, 45).ToValue(): {
      return GameVersion::k1_11;
    }

    case ::mapi::FixedFileVersion(1, 0, 11, 46).ToValue(): {
      return GameVersion::k1_11B;
    }

    case ::mapi::FixedFileVersion(1, 0, 12, 49).ToValue(): {
      return GameVersion::k1_12A;
    }

    case ::mapi::FixedFileVersion(1, 0, 13, 55).ToValue(): {
      return GameVersion::k1_13ABeta;
    }

    case ::mapi::FixedFileVersion(1, 0, 13, 60).ToValue(): {
      return GameVersion::k1_13C;
    }

    case ::mapi::FixedFileVersion(1, 0, 13, 64).ToValue(): {
      return GameVersion::k1_13D;
    }

    case ::mapi::FixedFileVersion(1, 14, 0, 64).ToValue(): {
      return GameVersion::kLod1_14A;
    }

    case ::mapi::FixedFileVersion(1, 14, 1, 68).ToValue(): {
      return GameVersion::kLod1_14B;
    }

    case ::mapi::FixedFileVersion(1, 14, 2, 70).ToValue(): {
      return GameVersion::kLod1_14C;
    }

    case ::mapi::FixedFileVersion(1, 14, 3, 71).ToValue(): {
      return GameVersion::kLod1_14D;
    }

    default: {
      ::mdc::error::ExitOnGeneralError(
          L"Error",
          L"Could not map the file version %u.%u.%u.%u to a known "
              L"game version.",
          __FILEW__,
          __LINE__,
          fixed_file_version.major_high,
          fixed_file_version.major_low,
          fixed_file_version.minor_high,
          fixed_file_version.minor_low
      );

      return static_cast<d2::GameVersion>(-1);
    }
  }
}

} // namespace

GameVersion GuessGameVersion() {
  const VS_FIXEDFILEINFO& fixed_file_info =
      ::mapi::game_executable::QueryFixedFileInfo();

  ::mapi::FixedFileVersion fixed_file_version(
      HIWORD(fixed_file_info.dwFileVersionMS),
      LOWORD(fixed_file_info.dwFileVersionMS),
      HIWORD(fixed_file_info.dwFileVersionLS),
      LOWORD(fixed_file_info.dwFileVersionLS)
  );

  return SearchTable(fixed_file_version);
}

} // namespace d2::intern
