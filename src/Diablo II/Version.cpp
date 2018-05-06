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
#include <memory>
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>

#include "../Common/Common.h"

namespace slashgaming::diabloii {
namespace {

constexpr const char *kGameExecutable = "Game.exe";
std::string ExtractFileVersionString(std::string_view file_name);
enum GameVersion GetGameVersionByFileVersion(std::string_view file_version);

} // namespace

enum GameVersion GetGameVersion() {
    // TODO(Mir Drualga): Figure out how to get version number without using
    // file version. This is important for classic D2 client compatibility!
    static std::string game_version_string = ExtractFileVersionString(
            kGameExecutable);
    static enum GameVersion game_version = GetGameVersionByFileVersion(
            game_version_string);

    return game_version;
}

bool IsGameVersionAtLeast1_14() {
    static const std::unordered_set<enum GameVersion> versions_at_least_1_14 = {
        GameVersion::kClassic1_14A, GameVersion::kClassic1_14B,
        GameVersion::kClassic1_14C, GameVersion::kClassic1_14D,

        GameVersion::kLod1_14A, GameVersion::kLod1_14B,
        GameVersion::kLod1_14C, GameVersion::kLod1_14D
    };

    return (versions_at_least_1_14.count(GetGameVersion()) == 1);
}

namespace {

std::string ExtractFileVersionString(std::string_view file_name) {
    // All the code for this function originated from StackOverflow user
    // crashmstr. Some parts were refactored for clarity.

    DWORD version_handle;

    // Check version size.
    std::wstring file_name_wide = common::ConvertAnsiToUnicode(file_name);
    DWORD version_size = GetFileVersionInfoSizeW(file_name_wide.data(),
            &version_handle);
    common::AssertOrTerminateWithMessage(
            (version_size != 0),
            "Error",
            "GetFileVersionInfo failed.");

    // Get the file version info.
    auto version_data = std::make_unique<wchar_t[]>(version_size);
    common::AssertOrTerminateWithMessage(
            GetFileVersionInfoW(file_name_wide.data(),
                    version_handle, version_size, version_data.get()),
            "Error",
            "GetFileVersionInfo failed.");

    // Gather all of the information into the specified buffer, then check
    // version info signature.
    UINT version_info_size;
    VS_FIXEDFILEINFO* version_info = nullptr;
    common::AssertOrTerminateWithMessage(
            VerQueryValueW(version_data.get(), L"\\", (LPVOID*)&version_info,
                    &version_info_size) || version_info_size <= 0 ||
                    version_info->dwSignature != 0xfeef04bd,
            "Error",
            "VerQueryValueW failed.");

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

enum GameVersion GetGameVersionByFileVersion(std::string_view version_string) {
        static const std::unordered_map<std::string_view, enum GameVersion>
                game_versions_by_file_version = {
            { "1.0.7.0", GameVersion::kLod1_07 },
            { "1.0.8.28", GameVersion::kLod1_08 },
            { "1.0.9.19", GameVersion::kLod1_09 },
            { "1.0.9.20", GameVersion::kLod1_09B },
            { "1.0.9.21", GameVersion::kLod1_09C },
            { "1.0.9.22", GameVersion::kLod1_09D },
            { "1.0.10.39", GameVersion::kLod1_10 },
            { "1.0.11.45", GameVersion::kLod1_11 },
            { "1.0.11.46", GameVersion::kLod1_11B },
            { "1.0.12.49", GameVersion::kLod1_12 },
            { "1.0.13.60", GameVersion::kLod1_13C },
            { "1.0.13.64", GameVersion::kLod1_13D },
            { "1.14.0.64", GameVersion::kLod1_14A },
            { "1.14.1.68", GameVersion::kLod1_14B },
            { "1.14.2.70", GameVersion::kLod1_14C },
            { "1.14.3.71", GameVersion::kLod1_14D }
        };

        auto found_version_pair = game_versions_by_file_version.find(
                version_string);

        common::AssertOrTerminateWithMessage(
            (found_version_pair != game_versions_by_file_version.cend()),
            "Error",
            "Unknown game version detected.");

        return found_version_pair->second;
    }

} // namespace

} // namespace slashgaming::diabloii::version
