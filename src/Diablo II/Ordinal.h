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

#ifndef SGD2MAPI_DIABLOII_ORDINAL_H_
#define SGD2MAPI_DIABLOII_ORDINAL_H_

#include <cstdint>
#include <string_view>
#include <unordered_map>

#include "GameLibrary.h"
#include "Offset.h"
#include "Version.h"

#ifdef SGD2MAPI_DLLEXPORT
#define DLLEXPORT __declspec(dllexport)
#else
#ifdef SGD2MAPI_DLLIMPORT
#define DLLEXPORT __declspec(dllimport)
#else
#define DLLEXPORT
#endif
#endif

namespace slashgaming::diabloii {

/**
 * A type that stores ordinals and is able to retrieve the correct ordinal for
 * the running game version.
 */
class DLLEXPORT Ordinal : public Offset {
    /**
     * Creates an instance of Ordinal by specifying the game library associated
     * with the specified map of ordinal values. The map contains a mapping of
     * the game versions to the ordinal values.
     */
    Ordinal(gamelibrary::GameLibraries game_library,
            const std::unordered_map<enum version::GameVersion,
                    uintptr_t>& ordinals_by_game_versions);

    /**
     * Creates an instance of Ordinal by specifying the file name of the library
     * associated with the specified map of ordinal values. The map contains a
     * mapping of the game versions to the ordinal values.
     */
    Ordinal(std::string_view library_file_name,
            const std::unordered_map<enum version::GameVersion,
                    uintptr_t>& ordinals_by_game_versions);

    explicit Ordinal(const Ordinal& offset) = default;
    Ordinal& operator=(const Ordinal& rhs) = default;

    explicit Ordinal(Ordinal&& offset) = default;
    Ordinal& operator=(Ordinal&& rhs) = default;

    /**
     * Calculates and returns the target address of the offset by adding the
     * offset associated with the running game version to the base address of
     * the offset's library.
     */
    virtual uintptr_t CalculateAddress() const override;
};

} // namespace slashgaming::diabloii

#undef DLLEXPORT

#endif // SGD2MAPI_DIABLOII_ORDINAL_H_
