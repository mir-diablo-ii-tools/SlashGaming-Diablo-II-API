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

#include "Pointer.h"

#include <windows.h>
#include <cstdint>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>

#include "GameLibrary.h"
#include "Version.h"

namespace slashgaming::diabloii {

Pointer::Pointer(enum GameLibraries game_library,
            const std::unordered_map<enum GameVersion,
                    std::pair<enum PointerType,
                            intptr_t>>& offsets_by_game_versions) :
        Pointer(GetFileNameFromGameLibraryWithRedirect(game_library),
                offsets_by_game_versions) {
}

Pointer::Pointer(std::string_view library_file_name,
            const std::unordered_map<enum GameVersion,
                    std::pair<enum PointerType,
                            intptr_t>>& offsets_by_game_versions) :
        library_file_name_(library_file_name) {
    enum GameVersion current_game_version = GetGameVersion();
    auto version_pair = offsets_by_game_versions.find(current_game_version);

    if (version_pair == offsets_by_game_versions.cend()) {
        address_ = -1;
        return;
    }

    auto offset_pair = version_pair->second;
    intptr_t base_address = GetGameLibraryBaseAddress(library_file_name_);
    switch (offset_pair.first) {
        case PointerType::kOffset: {
            address_ = base_address + offset_pair.second;
            break;
        }

        case PointerType::kOrdinal: {
            address_ = reinterpret_cast<intptr_t>(GetProcAddress(
                reinterpret_cast<HMODULE>(base_address),
                reinterpret_cast<LPSTR>(offset_pair.second)));
            break;
        }
    }
}

intptr_t Pointer::address() const {
    return address_;
}

std::string Pointer::library_file_name() const {
    return library_file_name_;
}

} // namespace slashgaming::diabloii
