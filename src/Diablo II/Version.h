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

#ifndef SGD2MAPI_DIABLOII_VERSION_H_
#define SGD2MAPI_DIABLOII_VERSION_H_

namespace slashgaming::diabloii::version {

enum class GameVersion : int {
    kInvalid,

    kClassic1_00, kClassic1_01, kClassic1_02, kClassic1_03, kClassic1_04,
    kClassic1_04B, kClassic1_04C, kClassic1_05, kClassic1_05B, kClassic1_06,
    kClassic1_06B, kClassic1_07, kClassic1_08, kClassic1_09, kClassic1_09B,
    kClassic1_09C, kClassic1_09D, kClassic1_10Beta, kClassic1_10BetaS,
    kClassic1_10, kClassic1_11, kClassic1_11B, kClassic1_12, kClassic1_13C,
    kClassic1_13D, kClassic1_14A, kClassic1_14B, kClassic1_14C, kClassic1_14D,

    kLod1_07, kLod1_08, kLod1_09, kLod1_09B, kLod1_09C, kLod1_09D,
    kLod1_10Beta, kLod1_10BetaS, kLod1_10, kLod1_11, kLod1_11B, kLod1_12,
    kLod1_13C, kLod1_13D, kLod1_14A, kLod1_14B, kLod1_14C, kLod1_14D
};

} // namespace slashgaming::diabloii::version

#endif // SGD2MAPI_DIABLOII_VERSION_H_
