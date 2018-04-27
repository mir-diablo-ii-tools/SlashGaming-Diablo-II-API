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

namespace slashgaming::diabloii::gamelibrary {
namespace {

/**
 * Returns the file name associated with the specified GameLibraries value. If
 * the library specified is not known, then the function returns the "Invalid"
 * string.
 */
std::string GetFileNameFromGameLibrary(enum GameLibraries game_library);

} // namespace

HMODULE GetGameLibraryBaseAddress(enum GameLibraries game_library) {
    std::string file_name = GetFileNameFromGameLibrary(game_library);
    return GetGameLibraryBaseAddress(file_name);
}

HMODULE GetGameLibraryBaseAddress(std::string_view file_name) {
    return 0;
}

namespace {

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
