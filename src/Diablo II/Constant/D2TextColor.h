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

#ifndef SGD2MAPI_DIABLOII_CONSTANT_D2TEXTCOLOR_H_
#define SGD2MAPI_DIABLOII_CONSTANT_D2TEXTCOLOR_H_

namespace slashgaming::diabloii::constant {

/**
 * The different colors used to display text in Diablo II.
 */
enum class D2TextColor {
    kBlack = 0,
    kBlue = 1,
    kCorrupted = 2,
    kVomit = kCorrupted,
    kDarkGold = 3,
    kGold = 4,
    kDarkGreen = 5,
    kDarkerGreen = 6,
    kLightGreen = 7,
    kDarkGrey = 8,
    kLightGrey = 9,
    kMetallic = 10,
    kOrange = 11,
    kPurple = 12,
    kLightRed = 13,
    kDarkRed = 14,
    kBrightWhite = 15,
    kWhite = 16,
    kYellow = 17,
};

/**
 * Returns the resolved raw integer value of the constant, based on the running
 * game version and architecture.
 */
int ResolveD2TextColorToValue(enum D2TextColor text_color);

/**
 * Returns the resolved constant that is associated with the specified integer,
 * based on the running game version and architecture.
 */
enum D2TextColor ResolveValueToD2TextColor(int raw_value);

} // namespace slashgaming::diabloii::constant

#endif // SGD2MAPI_DIABLOII_CONSTANT_D2TEXTCOLOR_H_
