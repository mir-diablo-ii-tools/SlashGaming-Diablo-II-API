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

#include "../../../include/cxx/file/file_version_info.hpp"

#include <mdc/wchar_t/filew.h>
#include <mdc/error/exit_on_error.hpp>

namespace mapi {

FileVersionInfo::FileVersionInfo(const wchar_t* path)
    : file_version_info_size_(InitFileVersionInfoSize(path)),
      file_version_info_(InitFileVersionInfo(path, file_version_info_size_)) {
}

void FileVersionInfo::ReadFile(const wchar_t* path) {
  this->file_version_info_size_ = InitFileVersionInfoSize(path);
  this->file_version_info_ = InitFileVersionInfo(
      path,
      this->file_version_info_size_
  );
}

const wchar_t* FileVersionInfo::QueryFileVersionInfoString(
    const wchar_t* sub_block
) const {
  wchar_t* str;
  UINT len;

  BOOL is_ver_query_value_success = VerQueryValueW(
      this->file_version_info_.get(),
      sub_block,
      reinterpret_cast<void**>(&str),
      &len
  );

  if (!is_ver_query_value_success) {
    ::mdc::error::ExitOnWindowsFunctionError(
        __FILEW__,
        __LINE__,
        L"VerQueryValueW",
        GetLastError()
    );

    return L"";
  }

  return str;
}

const DWORD* FileVersionInfo::QueryFileVersionInfoVar(
    const wchar_t* sub_block,
    ::std::size_t* count
) const {
  DWORD* var;
  UINT len;

  BOOL is_ver_query_value_success = VerQueryValueW(
      this->file_version_info_.get(),
      sub_block,
      reinterpret_cast<void**>(&var),
      &len
  );

  if (!is_ver_query_value_success) {
    ::mdc::error::ExitOnWindowsFunctionError(
        __FILEW__,
        __LINE__,
        L"VerQueryValueW",
        GetLastError()
    );

    return nullptr;
  }

  *count = len / sizeof(var[0]);

  return var;
}

const VS_FIXEDFILEINFO& FileVersionInfo::QueryFixedFileInfo() const {
  VS_FIXEDFILEINFO* fixed_file_info;
  UINT len;

  BOOL is_ver_query_value_success = VerQueryValueW(
      this->file_version_info_.get(),
      L"\\",
      reinterpret_cast<void**>(&fixed_file_info),
      &len
  );

  if (!is_ver_query_value_success) {
    ::mdc::error::ExitOnWindowsFunctionError(
        __FILEW__,
        __LINE__,
        L"VerQueryValueW",
        GetLastError()
    );

    return *fixed_file_info;
  }

  return *fixed_file_info;
}

::std::size_t FileVersionInfo::InitFileVersionInfoSize(
    const wchar_t* path
) {
  DWORD ignored;

  DWORD file_version_info_size = GetFileVersionInfoSizeW(path, &ignored);

  if (file_version_info_size == 0) {
    ::mdc::error::ExitOnWindowsFunctionError(
        __FILEW__,
        __LINE__,
        L"GetFileVersionInfoSizeW",
        GetLastError()
    );

    return 0;
  }

  return file_version_info_size;
}

::std::unique_ptr<unsigned char[]> FileVersionInfo::InitFileVersionInfo(
    const wchar_t* path,
    ::std::size_t file_version_info_size
) {
  DWORD ignored;

  ::std::unique_ptr file_version_info = ::std::make_unique<unsigned char[]>(
      file_version_info_size
  );

  BOOL is_get_file_version_info_success = GetFileVersionInfoW(
      path,
      ignored = 0,
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

    return nullptr;
  }

  return file_version_info;
}

} // namespace mapi
