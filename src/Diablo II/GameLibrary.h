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

#ifndef SGD2MAPI_DIABLOII_GAMELIBRARY_H_
#define SGD2MAPI_DIABLOII_GAMELIBRARY_H_

#include <windows.h>
#include <cstdint>
#include <string>
#include <string_view>

namespace slashgaming::diabloii {

/**
 * The executable used to run the game.
 */
constexpr std::string_view kGameExecutable = "Game.exe";

/**
 * The game libraries that are used by Diablo II.
 */
enum class GameLibraries : int {
    kBNClient, kD2Client, kD2CMP, kD2Common, kD2DDraw, kD2Direct3D, kD2Game,
    kD2GDI, kD2GFX, kD2Glide, kD2Lang, kD2Launch, kD2MCPClient, kD2Multi,
    kD2Net, kD2Sound, kD2Win, kFog, kStorm,

    kBinkW32, kGlide3X, kIJL11, kSmackW32,
};

/**
 * Gets the base address of the module with the specified file name.
 */
intptr_t GetGameLibraryBaseAddress(std::string_view file_name);

/**
 * Gets the base address of the module associated with the specified game
 * library. In the case where the game version is 1.14 or greater, the base
 * address of Game.exe is returned if that game library is merged into Game.exe.
 */
intptr_t GetGameLibraryBaseAddress(enum GameLibraries game_library);

/**
 * Returns the file name associated with the specified GameLibraries value. If
 * the game version is 1.14 or greater, then Game.exe is used if the library is
 * merged into the executable. If the library specified is not known, then the
 * function returns the "Invalid" string.
 */
std::string GetFileNameFromGameLibraryWithRedirect(
        enum GameLibraries game_library);

} // namespace slashgaming::diabloii::gamelibrary

#endif // SGD2MAPI_DIABLOII_GAMELIBRARY_H_
