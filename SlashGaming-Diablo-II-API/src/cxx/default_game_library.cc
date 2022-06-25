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

#include "../../include/cxx/default_game_library.hpp"

#include <cstddef>
#include <array>

#include <mdc/error/exit_on_error.hpp>
#include <mdc/wchar_t/filew.h>
#include "../../include/cxx/file/file_version_info.hpp"
#include "../../include/cxx/game_executable.hpp"
#include "../../include/cxx/game_version.hpp"

namespace d2 {
namespace default_library {
namespace {

// DefaultLibrary enumerations are sequential, which is required for
// the array lookup to work. If this assumption is violated (which is
// unlikely for the foreseeable future), then a different approach
// will be required.

static constexpr ::std::size_t kFileVersionInfoTableCount =
    static_cast<::std::size_t>(DefaultLibrary::kStorm) + 1;

using FileVersionInfoTable = ::std::array<
    ::mapi::FileVersionInfo,
    kFileVersionInfoTableCount
>;

using FileVersionInfoInitTable = ::std::array<
    bool,
    kFileVersionInfoTableCount
>;

static FileVersionInfoTable file_version_info_table;
static FileVersionInfoInitTable file_version_info_init_table({ 0 });

static const ::mapi::FileVersionInfo& GetLibraryFileVersionInfo(
    DefaultLibrary library
) {
  ::std::size_t table_index = static_cast<::std::size_t>(library);

  if (!file_version_info_init_table[table_index]) {
    const wchar_t* library_path = GetPathWithoutRedirect(library);

    file_version_info_table[table_index].ReadFile(library_path);
    file_version_info_init_table[table_index] = true;
  }

  return file_version_info_table[table_index];
}

} // namespace

const wchar_t* GetPathWithoutRedirect(
    DefaultLibrary library
) {
  switch (library) {
    case DefaultLibrary::kBNClient: {
      return L"BNClient.dll";
    }

    case DefaultLibrary::kD2CMP: {
      return L"D2CMP.dll";
    }

    case DefaultLibrary::kD2Client: {
      return L"D2Client.dll";
    }

    case DefaultLibrary::kD2Common: {
      return L"D2Common.dll";
    }

    case DefaultLibrary::kD2DDraw: {
      return L"D2DDraw.dll";
    }

    case DefaultLibrary::kD2Direct3D: {
      return L"D2Direct3D.dll";
    }

    case DefaultLibrary::kD2Game: {
      return L"D2Game.dll";
    }

    case DefaultLibrary::kD2GDI: {
      return L"D2GDI.dll";
    }

    case DefaultLibrary::kD2GFX: {
      return L"D2GFX.dll";
    }

    case DefaultLibrary::kD2Glide: {
      return L"D2Glide.dll";
    }

    case DefaultLibrary::kD2Lang: {
      return L"D2Lang.dll";
    }

    case DefaultLibrary::kD2Launch: {
      return L"D2Launch.dll";
    }

    case DefaultLibrary::kD2MCPClient: {
      return L"D2MCPClient.dll";
    }

    case DefaultLibrary::kD2Multi: {
      return L"D2Multi.dll";
    }

    case DefaultLibrary::kD2Net: {
      return L"D2Net.dll";
    }

    case DefaultLibrary::kD2Server: {
      return L"D2Server.dll";
    }

    case DefaultLibrary::kD2Sound: {
      return L"D2Sound.dll";
    }

    case DefaultLibrary::kD2Win: {
      return L"D2Win.dll";
    }

    case DefaultLibrary::kFog: {
      return L"Fog.dll";
    }

    case DefaultLibrary::kStorm: {
      return L"Storm.dll";
    }

    default: {
      ::mdc::error::ExitOnConstantMappingError(
          __FILEW__,
          __LINE__,
          static_cast<int>(library)
      );

      return L"";
    }
  }
}

const wchar_t* GetPathWithRedirect(
    DefaultLibrary library
) {
  // Redirect if the game version is 1.14 or higher.
  if (::d2::game_version::IsRunningAtLeast1_14()) {
    return ::mapi::game_executable::GetPath();
  }

  return GetPathWithoutRedirect(library);
}

const wchar_t* QueryFileVersionInfoStringWithRedirect(
    DefaultLibrary library,
    const wchar_t* sub_block
) {
  if (game_version::IsRunningAtLeast1_14()) {
    return ::mapi::game_executable::QueryFileVersionInfoString(sub_block);
  }

  return QueryFileVersionInfoStringWithoutRedirect(library, sub_block);
}

const wchar_t* QueryFileVersionInfoStringWithoutRedirect(
    DefaultLibrary library,
    const wchar_t* sub_block
) {
  const ::mapi::FileVersionInfo& file_version_info =
      GetLibraryFileVersionInfo(library);

  return file_version_info.QueryFileVersionInfoString(sub_block);
}

const DWORD* QueryFileVersionInfoVarWithRedirect(
    DefaultLibrary library,
    const wchar_t* sub_block,
    ::std::size_t* count
) {
  if (game_version::IsRunningAtLeast1_14()) {
    return ::mapi::game_executable::QueryFileVersionInfoVar(sub_block, count);
  }

  return QueryFileVersionInfoVarWithoutRedirect(library, sub_block, count);
}

const DWORD* QueryFileVersionInfoVarWithoutRedirect(
    DefaultLibrary library,
    const wchar_t* sub_block,
    ::std::size_t* count
) {
  const ::mapi::FileVersionInfo& file_version_info =
      GetLibraryFileVersionInfo(library);

  return file_version_info.QueryFileVersionInfoVar(sub_block, count);
}

const VS_FIXEDFILEINFO& QueryFixedFileInfoWithRedirect(
    DefaultLibrary library
) {
  if (game_version::IsRunningAtLeast1_14()) {
    return ::mapi::game_executable::QueryFixedFileInfo();
  }

  return QueryFixedFileInfoWithoutRedirect(library);
}

const VS_FIXEDFILEINFO& QueryFixedFileInfoWithoutRedirect(
    DefaultLibrary library
) {
  const ::mapi::FileVersionInfo& file_version_info =
      GetLibraryFileVersionInfo(library);

  return file_version_info.QueryFixedFileInfo();
}

} // namespace default_library
} // namespace d2
