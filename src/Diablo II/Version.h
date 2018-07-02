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

#ifndef SGD2MAPI_DIABLOII_VERSION_H_
#define SGD2MAPI_DIABLOII_VERSION_H_

#ifdef SGD2MAPI_DLLEXPORT
#define DLLEXPORT __declspec(dllexport)
#elif defined(SGD2MAPI_DLLIMPORT)
#define DLLEXPORT __declspec(dllimport)
#else
#define DLLEXPORT
#endif

namespace slashgaming::diabloii {

/**
 * The Diablo II game versions supported and recognized.
 */
enum class GameVersion : int {
    kInvalid,

    k1_00, k1_01, k1_02, k1_03, k1_04, k1_04B, k1_04C = k1_04B, k1_05,
    k1_05B, k1_06, k1_06B, k1_07, k1_08, k1_09, k1_09B, k1_09C, k1_09D, k1_09E,
    k1_10, k1_10Beta, k1_10SBeta, k1_11, k1_11B, k1_12A, k1_13ABeta, k1_13C,
    k1_13D,

    kClassic1_14A, kClassic1_14B, kClassic1_14C, kClassic1_14D,
    kLod1_14A, kLod1_14B, kLod1_14C, kLod1_14D,
};

/**
 * Returns the Diablo II game version that is determined at runtime.
 */
DLLEXPORT enum GameVersion GetGameVersion();

/**
 * Returns whether the Diablo II game version is at least 1.14.
 */
DLLEXPORT constexpr bool IsGameVersionAtLeast1_14(
        enum GameVersion game_version) {
    int game_version_value = static_cast<int>(game_version);
    return !(game_version_value >= static_cast<int>(GameVersion::k1_00) &&
            game_version_value <= static_cast<int>(GameVersion::k1_13D));
}

} // namespace slashgaming::diabloii::version

#undef DLLEXPORT

#endif // SGD2MAPI_DIABLOII_VERSION_H_
