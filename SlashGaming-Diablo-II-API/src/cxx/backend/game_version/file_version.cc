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

#include "file_version.hpp"

#include "../error_handling.hpp"

namespace mapi {

FileVersion::FileVersion(
    const std::filesystem::path& file_path
) : FileVersion(std::filesystem::path(file_path)) {
}

FileVersion::FileVersion(
    std::filesystem::path&& file_path
) : file_path_(std::move(file_path)),
    version_(FileVersion::ReadFileVersion(file_path_)) {
}

FileVersion::FileVersion(
    const std::filesystem::path& file_path,
    const VersionType& version
) : FileVersion(
        std::filesystem::path(file_path),
        VersionType(version)
    ) {
}

FileVersion::FileVersion(
    std::filesystem::path&& file_path,
    VersionType&& version
) : file_path_(std::move(file_path)),
    version_(std::move(version)) {
}

FileVersion::FileVersion(const FileVersion& file_version) = default;

FileVersion::FileVersion(FileVersion&& file_version) noexcept = default;

FileVersion::~FileVersion() = default;

FileVersion& FileVersion::operator=(
    const FileVersion& file_version
) = default;

FileVersion& FileVersion::operator=(
    FileVersion&& file_version
) noexcept = default;

FileVersion::VersionType FileVersion::ReadFileVersion(
    const std::filesystem::path& file_path
) {
  // All the code for this function originated from StackOverflow user
  // crashmstr. Some parts were refactored for clarity.
  const wchar_t* file_path_text_cstr = file_path.c_str();

  // Check version size.
  DWORD ignored;
  DWORD file_version_info_size = GetFileVersionInfoSizeW(
      file_path_text_cstr,
      &ignored
  );

  if (file_version_info_size == 0) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"GetFileVersionInfoSizeW",
        GetLastError(),
        __FILEW__,
        __LINE__
    );
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
    ExitOnWindowsFunctionFailureWithLastError(
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
    ExitOnWindowsFunctionFailureWithLastError(
        L"VerQueryValueW",
        GetLastError(),
        __FILEW__,
        __LINE__
    );
  }

  // Doesn't matter if you are on 32 bit or 64 bit,
  // DWORD is always 32 bits, so first two revision numbers
  // come from dwFileVersionMS, last two come from dwFileVersionLS
  return VersionType(
      (version_info->dwFileVersionMS >> 16) & 0xFFFF,
      (version_info->dwFileVersionMS >> 0) & 0xFFFF,
      (version_info->dwFileVersionLS >> 16) & 0xFFFF,
      (version_info->dwFileVersionLS >> 0) & 0xFFFF
  );
}

const FileVersion::VersionType& FileVersion::version() const noexcept {
  return this->version_;
}

} // namespace mapi

std::size_t std::hash<mapi::FileVersion>::operator()(
    const mapi::FileVersion& file_version
) const {
  std::hash<DWORD> dword_hasher;

  std::tuple actual_version = file_version.version();

  DWORD sum = std::get<0>(actual_version);
  sum += std::get<1>(actual_version) * sizeof(CHAR_BIT);
  sum += std::get<2>(actual_version) * sizeof(CHAR_BIT * 2);
  sum += std::get<3>(actual_version) * sizeof(CHAR_BIT * 3);

  return dword_hasher(sum);
}
