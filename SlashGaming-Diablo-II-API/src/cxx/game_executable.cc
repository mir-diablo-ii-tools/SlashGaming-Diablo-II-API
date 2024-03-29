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

#include "../../include/cxx/game_executable.hpp"

#include <windows.h>

#include <memory>
#include <string>

#include <mdc/wchar_t/filew.h>
#include <mdc/error/exit_on_error.hpp>
#include "../../include/cxx/file/file_version_info.hpp"
#include "backend/d2se/d2se_file_signature.hpp"

namespace mapi::game_executable {
namespace {

static ::std::wstring InitGameExecutablePath() {
  DWORD path_len;
  size_t capacity;
  size_t new_capacity = MAX_PATH;
  std::unique_ptr<wchar_t[]> path_buffer;

  do {
    capacity = new_capacity;
    path_buffer = std::make_unique<wchar_t[]>(capacity);
    path_len = GetModuleFileNameW(nullptr, path_buffer.get(), capacity);

    new_capacity *= 2;
  } while (path_len >= capacity - 1);

  return path_buffer.get();
}

static const FileVersionInfo& GetGameExecutableFileVersionInfo() {
  static FileVersionInfo file_version_info(GetPath());

  return file_version_info;
}

} // namespace

const wchar_t* GetPath() {
  static ::std::wstring kGameExecutablePath = InitGameExecutablePath();

  return kGameExecutablePath.c_str();
}

bool IsD2se() {
  static bool is_d2se =
      ::d2::d2se::intern::file_signature::IsFileD2seExecutable(
          GetPath()
      );

  return is_d2se;
}

const wchar_t* QueryFileVersionInfoString(
    const wchar_t* sub_block
) {
  const ::mapi::FileVersionInfo& file_version_info =
      GetGameExecutableFileVersionInfo();

  return file_version_info.QueryFileVersionInfoString(sub_block);
}

const DWORD* QueryFileVersionInfoVar(
    const wchar_t* sub_block,
    ::std::size_t* count
) {
  const ::mapi::FileVersionInfo& file_version_info =
      GetGameExecutableFileVersionInfo();

  return file_version_info.QueryFileVersionInfoVar(sub_block, count);
}

const VS_FIXEDFILEINFO& QueryFixedFileInfo() {
  const ::mapi::FileVersionInfo& file_version_info =
      GetGameExecutableFileVersionInfo();

  return file_version_info.QueryFixedFileInfo();
}

} // namespace mapi::game_executable
