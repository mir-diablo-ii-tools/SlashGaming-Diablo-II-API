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

#ifndef SGD2MAPI_DIABLOII_CONSTANT_D2TEXTFONT_H_
#define SGD2MAPI_DIABLOII_CONSTANT_D2TEXTFONT_H_

namespace slashgaming::diabloii::constant {

/**
 * The different text fonts used to display custom text in Diablo II.
 */
enum class D2TextFonts {
    kDiabloSmall = 0,
    kDiabloMedium = 1,
    kDiabloHeaderBig = 2,
    kDiabloHeaderMedium = 3,
    kDiabloHeaderSmall = 4,
    kDiabloInvertedSmall = 5,
    kDiabloInvertedMedium = 6,
    kNormalSmall = 7,
    kNormalMedium = 8,
    kNormalMediumBold = 9,
    kNormalBigBold = 10,
    kWideSmall = 11,
    kWideMedium = 12
};

/**
 * A wrapper class to represent the D2TextFonts constant in a version and
 * architecture agnostic way.
 */
class ExD2TextFont {
public:
    /**
     * Creates an instance of ExD2TextFont, resolving the value of the constant
     * to an integer based on the running game version and architecture.
     */
    explicit ExD2TextFont(enum D2TextFonts text_font);

    explicit ExD2TextFont(const ExD2TextFont& base_constant) = default;
    explicit ExD2TextFont(ExD2TextFont&& base_constant) = default;

    ExD2TextFont& operator=(const ExD2TextFont& rhs) = default;
    ExD2TextFont& operator=(ExD2TextFont&& rhs) = default;

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
    enum D2TextFonts text_font() const;

private:
    enum D2TextFonts text_font_;
    int value_;

    static int ResolveValue(enum D2TextFonts text_font);
};

} // namespace slashgaming::diabloii::constant

#endif // SGD2MAPI_DIABLOII_CONSTANT_D2TEXTFONT_H_
