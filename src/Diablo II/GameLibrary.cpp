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

#include "GameLibrary.h"

#include <windows.h>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>

#include "../Common/Common.h"
#include "Version.h"

namespace slashgaming::diabloii::gamelibrary {
namespace {

/**
 * Returns whether the game library specified had been merged into Game.exe in
 * versions 1.14 and above.
 */
bool IsGameLibraryRedirected(enum GameLibraries game_library);

/**
 * Returns the file name associated with the specified GameLibraries value. If
 * the library specified is not known, then the function returns the "Invalid"
 * string.
 */
std::string GetFileNameFromGameLibrary(enum GameLibraries game_library);

} // namespace

HMODULE GetGameLibraryBaseAddress(enum GameLibraries game_library) {
    std::string file_name = GetFileNameFromGameLibraryWithRedirect(
            game_library);
    return GetGameLibraryBaseAddress(file_name);
}

HMODULE GetGameLibraryBaseAddress(std::string_view file_name) {
    std::wstring wide_file_name = common::ConvertAnsiToUnicode(file_name);
    HMODULE dll_address = GetModuleHandleW(wide_file_name.data());

    if (dll_address == nullptr) {
        dll_address = LoadLibraryW(wide_file_name.data());
    }
    return dll_address;
}

std::string GetFileNameFromGameLibraryWithRedirect(
        enum GameLibraries game_library) {
    if (version::IsGameVersionAtLeast1_14() &&
            IsGameLibraryRedirected(game_library)) {
        game_library = GameLibraries::kGame;
    }

    return GetFileNameFromGameLibrary(game_library);
}

namespace {

bool IsGameLibraryRedirected(enum GameLibraries game_library) {
    static const std::unordered_set<enum GameLibraries>
            redirected_game_libraries = {
        GameLibraries::kBinkW32, GameLibraries::kD2Client,
        GameLibraries::kD2CMP, GameLibraries::kD2Common,
        GameLibraries::kD2DDraw, GameLibraries::kD2Direct3D,
        GameLibraries::kD2Game, GameLibraries::kD2GDI,
        GameLibraries::kD2GFX, GameLibraries::kD2Glide,
        GameLibraries::kD2Lang, GameLibraries::kD2Launch,
        GameLibraries::kD2MCPClient, GameLibraries::kD2Multi,
        GameLibraries::kD2Net, GameLibraries::kD2Sound,
        GameLibraries::kD2Win, GameLibraries::kFog,
        GameLibraries::kStorm
    };

    return (redirected_game_libraries.count(game_library) == 1);
}

std::string GetFileNameFromGameLibrary(enum GameLibraries game_library) {
    static const std::unordered_map<enum GameLibraries, std::string_view>
            file_name_by_game_library = {
        { GameLibraries::kBinkW32, "Binkw32.dll" },
        { GameLibraries::kBNClient, "BnClient.dll" },
        { GameLibraries::kD2Client, "D2Client.dll" },
        { GameLibraries::kD2CMP, "D2CMP.dll" },
        { GameLibraries::kD2Common, "D2Common.dll" },
        { GameLibraries::kD2DDraw, "D2DDraw.dll" },
        { GameLibraries::kD2Direct3D, "D2Direct3D.dll" },
        { GameLibraries::kD2Game, "D2Game.dll" },
        { GameLibraries::kD2GDI, "D2Gdi.dll" },
        { GameLibraries::kD2GFX, "D2Gfx.dll" },
        { GameLibraries::kD2Glide, "D2Glide.dll" },
        { GameLibraries::kD2Lang, "D2Lang.dll" },
        { GameLibraries::kD2Launch, "D2Launch.dll" },
        { GameLibraries::kD2MCPClient, "D2MCPClient.dll" },
        { GameLibraries::kD2Multi, "D2Multi.dll" },
        { GameLibraries::kD2Net, "D2Net.dll" },
        { GameLibraries::kD2Sound, "D2Sound.dll" },
        { GameLibraries::kD2Win, "D2Win.dll" },
        { GameLibraries::kFog, "Fog.dll" },
        { GameLibraries::kGame, "Game.exe" },
        { GameLibraries::kGlide3X, "glide3x.dll" },
        { GameLibraries::kIJL11, "Ijl11.dll" },
        { GameLibraries::kSmackW32, "SmackW32.dll" },
        { GameLibraries::kStorm, "Storm.dll" }
    };

    auto find_result = file_name_by_game_library.find(game_library);
    return (find_result != file_name_by_game_library.cend())
            ? find_result->second.data()
            : "Invalid";
}

} // namespace
} // namespace slashgaming::diabloii::gamelibrary
