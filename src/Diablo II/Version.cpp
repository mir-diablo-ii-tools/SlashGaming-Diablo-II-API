/**
 * SlashGaming Diablo II Modding API
 * Copyright (C) 2018  SlashGaming Community
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
 */

#include "Version.h"

#include <windows.h>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

#include "../Common/Common.h"

namespace slashgaming::diabloii::version {
namespace {

constexpr const char *kGameExecutable = "Game.exe";
std::string ExtractFileVersionString(std::string_view file_name);

} // namespace

enum GameVersion GetGameVersion() {
    static std::string game_version_string = ExtractFileVersionString(
            kGameExecutable);
    static enum GameVersion game_version = GameVersion::kInvalid;
    return game_version;
}

namespace {

std::string ExtractFileVersionString(std::string_view file_name) {
    // All the code for this function originated from StackOverflow user
    // crashmstr.

    DWORD version_handle;

    // Check version size.
    std::wstring file_path_wide = common::ConvertAnsiToUnicode(file_name);
    DWORD version_size = GetFileVersionInfoSizeW(file_path_wide.data(),
            &version_handle);
    if (version_size == 0) {
        return "GetFileVersionInfoSize failed.";
    }

    // Get the file version info.
    std::vector<wchar_t> version_data(version_size);
    if (!GetFileVersionInfoW(file_path_wide.data(), version_handle,
            version_size, version_data.data())) {
        return "GetFileVersionInfo failed.";
    }

    // Gather all of the information into the specified buffer.
    UINT version_info_size;
    VS_FIXEDFILEINFO* version_info = nullptr;
    if (!VerQueryValueW(version_data.data(), L"\\", (LPVOID*)&version_info,
            &version_info_size)) {
        return "VerQueryValueW failed.";
    }

    // Check version info signature.
    if (version_info_size <= 0 || version_info->dwSignature != 0xfeef04bd) {
        return "VerQueryValueW failed.";
    }

    // Doesn't matter if you are on 32 bit or 64 bit,
    // DWORD is always 32 bits, so first two revision numbers
    // come from dwFileVersionMS, last two come from dwFileVersionLS
    std::ostringstream stringStream;

    stringStream << ((version_info->dwFileVersionMS >> 16) & 0xffff) << ".";
    stringStream << ((version_info->dwFileVersionMS >> 0) & 0xffff) << ".";
    stringStream << ((version_info->dwFileVersionLS >> 16) & 0xffff) << ".";
    stringStream << ((version_info->dwFileVersionLS >> 0) & 0xffff);

    return stringStream.str();
}

} // namespace

} // namespace slashgaming::diabloii::version
