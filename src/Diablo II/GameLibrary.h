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

#ifndef SGD2MAPI_DIABLOII_GAMELIBRARY_H_
#define SGD2MAPI_DIABLOII_GAMELIBRARY_H_

#include <windows.h>
#include <cstdint>
#include <string>
#include <string_view>

namespace slashgaming::diabloii::gamelibrary {

/**
 * The game libraries that are used by Diablo II.
 */
enum class GameLibraries : int {
    kBinkW32, kBNClient, kD2Client, kD2CMP, kD2Common, kD2DDraw,
    kD2Direct3D, kD2Game, kD2GDI, kD2GFX, kD2Glide, kD2Lang, kD2Launch,
    kD2MCPClient, kD2Multi, kD2Net, kD2Sound, kD2Win, kFog, kGame, kGlide3X,
    kIJL11, kSmackW32, kStorm
};

/**
 * Gets the base address of the module with the specified file name.
 */
uintptr_t GetGameLibraryBaseAddress(std::string_view file_name);

/**
 * Gets the base address of the module associated with the specified game
 * library. In the case where the game version is 1.14 or greater, the base
 * address of Game.exe is returned if that game library is merged into Game.exe.
 */
uintptr_t GetGameLibraryBaseAddress(enum GameLibraries game_library);

/**
 * Returns the file name associated with the specified GameLibraries value. If
 * the game version is 1.14 or greater, then Game.exe is used if the library is
 * merged into the executable. If the library specified is not known, then the
 * function returns the "Invalid" string.
 */
std::string GetFileNameFromGameLibraryWithRedirect(
        enum GameLibraries game_library);

} // namespace

#endif // SGD2MAPI_DIABLOII_GAMELIBRARY_H_
