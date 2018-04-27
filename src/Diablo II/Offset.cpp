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

#include "Offset.h"

#include <cstdint>
#include <string>
#include <string_view>
#include <unordered_map>

namespace slashgaming::diabloii {

Offset::Offset(gamelibrary::GameLibraries game_library,
            const std::unordered_map<version::GameVersion,
                    uintptr_t>& offsets_by_game_versions) :
        Offset(gamelibrary::GetFileNameFromGameLibraryWithRedirect(
                        game_library),
                offsets_by_game_versions){
}

Offset::Offset(std::string_view library_file_name,
            const std::unordered_map<version::GameVersion,
                    uintptr_t>& offsets_by_game_versions) :
        library_file_name_(library_file_name),
        offsets_by_game_versions_(offsets_by_game_versions) {
}

uintptr_t Offset::CalculateAddress() const {
    return 0;
}

uintptr_t Offset::GetRunningGameOffset() const {
    version::GameVersion game_version = version::GetGameVersion();
    auto found_offset_pair = offsets_by_game_versions_.find(game_version);

    return (found_offset_pair != offsets_by_game_versions_.cend())
            ? found_offset_pair->second
            : static_cast<uintptr_t>(-1);
}

std::string Offset::get_library_file_name() const {
    return library_file_name_;
}

} // namespace slashgaming::diabloii
