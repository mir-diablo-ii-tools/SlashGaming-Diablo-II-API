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

#ifndef SGD2MAPI_DIABLOII_POINTER_H_
#define SGD2MAPI_DIABLOII_POINTER_H_

#include <windows.h>
#include <cstdint>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>

#include "GameLibrary.h"
#include "Version.h"

#ifdef SGD2MAPI_DLLEXPORT
#define DLLEXPORT __declspec(dllexport)
#elif defined(SGD2MAPI_DLLIMPORT)
#define DLLEXPORT __declspec(dllimport)
#else
#define DLLEXPORT
#endif

namespace slashgaming::diabloii {

enum PointerType {
    kOffset,
    kOrdinal
};

class DLLEXPORT Pointer {
public:
    /**
     * Creates an instance of Pointer by specifying the game library associated
     * with the specified map of offset values. The map contains a mapping of
     * the game versions to the offset values.
     *
     * Calculates and returns the target address of this pointer. If there is no
     * offset for that game version, then the function returns -1.
     */
    Pointer(enum GameLibraries game_library,
            const std::unordered_map<enum GameVersion,
                    std::pair<enum PointerType,
                            intptr_t>>& offsets_by_game_versions);

    /**
     * Creates an instance of Pointer by specifying the file name of the library
     * associated with the specified map of offset values. The map contains a
     * mapping of the game versions to the offset values.
     *
     * Calculates and returns the target address of this pointer. If there is no
     * offset for that game version, then the function returns -1.
     */
    Pointer(std::string_view library_file_name,
            const std::unordered_map<enum GameVersion,
                    std::pair<enum PointerType,
                            intptr_t>>& offsets_by_game_versions);

    explicit Pointer(const Pointer& pointer) = default;
    Pointer& operator=(const Pointer& rhs) = default;

    explicit Pointer(Pointer&& pointer) = default;
    Pointer& operator=(Pointer&& rhs) = default;

    /**
     * Returns the file name of this pointer's library.
     */
    std::string library_file_name() const;

    /**
     * Return the address of this pointer.
     */
    intptr_t address() const;

private:
    std::string library_file_name_;
    intptr_t address_;
};

} // namespace slashgaming::diabloii

#undef DLLEXPORT

#endif // SGD2MAPI_DIABLOII_POINTER_H_
