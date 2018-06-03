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

#ifdef SGD2MAPI_DLLEXPORT
#define DLLEXPORT __declspec(dllexport)
#elif defined(SGD2MAPI_DLLIMPORT)
#define DLLEXPORT __declspec(dllimport)
#else
#define DLLEXPORT
#endif

namespace slashgaming::diabloii::constant {

/**
 * The different colors used to display text in Diablo II.
 */
enum class D2TextColors {
    kBlack = 0,
    kBlue = 1,
    kCorrupted = 2,
    kVomit = kCorrupted = 3,
    kDarkGold = 4,
    kGold = 5,
    kDarkGreen = 6,
    kDarkerGreen = 7,
    kLightGreen = 8,
    kDarkGrey = 9,
    kLightGrey = 10,
    kMetallic = 11,
    kOrange = 12,
    kPurple = 13,
    kLightRed = 14,
    kDarkRed = 15,
    kBrightWhite = 16,
    kWhite = 17,
    kYellow = 18,
};

/**
 * A wrapper class to represent the D2TextColor constant in a version and
 * architecture agnostic way.
 */
class DLLEXPORT ExD2TextColor {
public:
    /**
     * Creates an instance of ExD2TextColor, resolving the value of the constant
     * to an integer based on the running game version and architecture.
     */
    explicit ExD2TextColor(enum D2TextColors text_color);

    explicit ExD2TextColor(const ExD2TextColor& base_constant) = default;
    explicit ExD2TextColor(ExD2TextColor&& base_constant) = default;

    ExD2TextColor& operator=(const ExD2TextColor& rhs) = default;
    ExD2TextColor& operator=(ExD2TextColor&& rhs) = default;

    /**
     * Returns the resolved value that corresponds to this instance of the
     * constant.
     */
    int value() const;

    /**
     * Returns the value of the constant that corresponds to this instance of
     * the constant. The underlying value of returned does not necessarily
     * correspond to that used in the game. Use value() for that purpose.
     */
    enum D2TextColors text_color() const;

private:
    enum D2TextColors text_color_;
    int value_;

    static int ResolveValue(enum D2TextColors text_color);
};

} // namespace slashgaming::diabloii::constant

#undef DLLEXPORT
#endif // SGD2MAPI_DIABLOII_CONSTANT_D2TEXTCOLOR_H_
