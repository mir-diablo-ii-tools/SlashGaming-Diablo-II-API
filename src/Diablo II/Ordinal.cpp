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

#include "Ordinal.h"

#include <windows.h>
#include <cstdint>
#include <string_view>
#include <unordered_map>

#include "GameLibrary.h"
#include "Offset.h"
#include "Version.h"

namespace slashgaming::diabloii {

Ordinal::Ordinal(enum GameLibraries game_library,
        const std::unordered_map<enum GameVersion,
                intptr_t>& ordinals_by_game_versions) :
            Ordinal(GetFileNameFromGameLibraryWithRedirect(game_library),
                ordinals_by_game_versions){
}

Ordinal::Ordinal(std::string_view library_file_name,
            const std::unordered_map<enum GameVersion,
                    intptr_t>& ordinals_by_game_versions) :
        Offset(library_file_name, ordinals_by_game_versions) {
}

intptr_t Ordinal::CalculateAddress() const {
    intptr_t base_address = GetGameLibraryBaseAddress(get_library_file_name());
    intptr_t ordinal = GetRunningGameOffset();

    FARPROC address = GetProcAddress(reinterpret_cast<HMODULE>(base_address),
            reinterpret_cast<LPSTR>(ordinal));

    return reinterpret_cast<intptr_t>(address);
}

} // namespace slashgaming::diabloii
