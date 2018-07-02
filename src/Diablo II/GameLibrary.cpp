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
 *
 *  Additional permissions under GNU Affero General Public License version 3
 *  section 7
 *
 *  If you modify this Program, or any covered work, by linking or combining it
 *  with Diablo II (or a modified version of that library), containing parts
 *  covered by the terms of Blizzard End User License Agreement, the licensors
 *  of this Program grant you additional permission to convey the resulting
 *  work.
 *
 *  If you modify this Program, or any covered work, by declaring a custom
 *  version of an existing Diablo II data structure with members ordered
 *  differently from any official version of the game, then such declarations
 *  are exempt from the terms of GNU Affero General Public License version 3
 *  section 6.
 */

#include "GameLibrary.h"

#include <windows.h>
#include <cstdint>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>

#include "../Common/Common.h"
#include "Version.h"

namespace slashgaming::diabloii {
namespace {

/**
 * Returns whether the game library specified had been merged into Game.exe in
 * versions 1.14 and above.
 */
constexpr bool IsGameLibraryRedirected(enum GameLibraries game_library);

/**
 * Returns the file name associated with the specified GameLibraries value. If
 * the library specified is not known, then the function returns the "Invalid"
 * string.
 */
std::string GetFileNameFromGameLibrary(enum GameLibraries game_library);

} // namespace

intptr_t GetGameLibraryBaseAddress(enum GameLibraries game_library) {
    std::string file_name = GetFileNameFromGameLibraryWithRedirect(
            game_library);
    return GetGameLibraryBaseAddress(file_name);
}

intptr_t GetGameLibraryBaseAddress(std::string_view file_name) {
    std::wstring wide_file_name = common::ConvertAnsiToUnicode(file_name);
    HMODULE dll_address = GetModuleHandleW(wide_file_name.data());

    if (dll_address == nullptr) {
        dll_address = LoadLibraryW(wide_file_name.data());
    }
    return reinterpret_cast<intptr_t>(dll_address);
}

std::string GetFileNameFromGameLibraryWithRedirect(
        enum GameLibraries game_library) {
    if (IsGameVersionAtLeast1_14(GetGameVersion()) &&
            IsGameLibraryRedirected(game_library)) {
        return kGameExecutable.data();
    }

    return GetFileNameFromGameLibrary(game_library);
}

namespace {

constexpr bool IsGameLibraryRedirected(enum GameLibraries game_library) {
    int game_library_value = static_cast<int>(game_library);

    return (game_library_value >= static_cast<int>(GameLibraries::kBNClient) &&
            game_library_value <= static_cast<int>(GameLibraries::kStorm));
}

std::string GetFileNameFromGameLibrary(enum GameLibraries game_library) {
    switch (game_library) {
        case GameLibraries::kBinkW32: {
            return "Binkw32.dll";
        }

        case GameLibraries::kBNClient: {
            return "BnClient.dll";
        }

        case GameLibraries::kD2Client: {
            return "D2Client.dll";
        }

        case GameLibraries::kD2CMP: {
            return "D2CMP.dll";
        }

        case GameLibraries::kD2Common: {
            return "D2Common.dll";
        }

        case GameLibraries::kD2DDraw: {
            return "D2DDraw.dll";
        }

        case GameLibraries::kD2Direct3D: {
            return "D2Direct3D.dll";
        }

        case GameLibraries::kD2Game: {
            return "D2Game.dll";
        }

        case GameLibraries::kD2GDI: {
            return "D2Gdi.dll";
        }

        case GameLibraries::kD2GFX: {
            return "D2Gfx.dll";
        }

        case GameLibraries::kD2Glide: {
            return "D2Glide.dll";
        }

        case GameLibraries::kD2Lang: {
            return "D2Lang.dll";
        }

        case GameLibraries::kD2Launch: {
            return "D2Launch.dll";
        }

        case GameLibraries::kD2MCPClient: {
            return "D2MCPClient.dll";
        }

        case GameLibraries::kD2Multi: {
            return "D2Multi.dll";
        }

        case GameLibraries::kD2Net: {
            return "D2Net.dll";
        }

        case GameLibraries::kD2Sound: {
            return "D2Sound.dll";
        }

        case GameLibraries::kD2Win: {
            return "D2Win.dll";
        }

        case GameLibraries::kFog: {
            return "Fog.dll";
        }

        case GameLibraries::kGlide3X: {
            return "glide3x.dll";
        }

        case GameLibraries::kIJL11: {
            return "Ijl11.dll";
        }

        case GameLibraries::kSmackW32: {
            return "SmackW32.dll";
        }

        case GameLibraries::kStorm: {
            return "Storm.dll";
        }
    }

    common::AssertOrTerminateWithMessage(false, "Error",
            "Unknown game library.");

    return "Unreachable";
}

} // namespace
} // namespace slashgaming::diabloii::gamelibrary
