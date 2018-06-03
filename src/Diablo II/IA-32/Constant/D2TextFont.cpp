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

#if defined(__i386__) || defined(_M_IX86) || defined(_X86_)

#include "../../Constant/D2TextFont.h"

namespace slashgaming::diabloii::constant {
namespace {

constexpr int ResolveValue_1_00(enum D2TextFonts text_color) {
    switch (text_color) {
        case D2TextFonts::kDiabloSmall: {
            return 11;
        }

        case D2TextFonts::kDiabloMedium: {
            return 1;
        }

        case D2TextFonts::kDiabloHeaderSmall: {
            return 7;
        }

        case D2TextFonts::kDiabloHeaderMedium: {
            return 2;
        }

        case D2TextFonts::kDiabloHeaderBig: {
            return 3;
        }

        case D2TextFonts::kDiabloInvertedSmall: {
            return 10;
        }

        case D2TextFonts::kDiabloInvertedMedium: {
            return 9;
        }

        case D2TextFonts::kNormalSmall: {
            return 6;
        }

        case D2TextFonts::kNormalMedium: {
            return 4;
        }

        case D2TextFonts::kNormalMediumBold: {
            return 13;
        }

        case D2TextFonts::kNormalBigBold: {
            return 5;
        }

        case D2TextFonts::kWideSmall: {
            // Also has the value 12.
            return 0;
        }

        case D2TextFonts::kWideMedium: {
            return 8;
        }
    }

    // Should never happen.
    return -1;
}

} // namespace

ExD2TextFont::ExD2TextFont(enum D2TextFonts text_font) :
        text_font_(text_font), value_(ResolveValue(text_font)) {
}

int ExD2TextFont::ResolveValue(enum D2TextFonts text_font) {
    return ResolveValue_1_00(text_font);
}

int ExD2TextFont::value() const {
    return value_;
}

enum D2TextFonts ExD2TextFont::text_font() const {
    return text_font_;
}

} // namespace slashgaming::diabloii::constant

#endif // defined(__i386__) || defined(_M_IX86) || defined(_X86_)
