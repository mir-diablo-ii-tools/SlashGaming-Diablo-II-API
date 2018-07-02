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

#if defined(__i386__) || defined(_M_IX86) || defined(_X86_)

#include "../../Constant/D2TextFont.h"

namespace slashgaming::diabloii::constant {
namespace {

constexpr int ResolveD2TextFontToValue_1_00(enum D2TextFont text_color) {
    switch (text_color) {
        case D2TextFont::kDiabloSmall: {
            return 11;
        }

        case D2TextFont::kDiabloMedium: {
            return 1;
        }

        case D2TextFont::kDiabloHeaderSmall: {
            return 7;
        }

        case D2TextFont::kDiabloHeaderMedium: {
            return 2;
        }

        case D2TextFont::kDiabloHeaderBig: {
            return 3;
        }

        case D2TextFont::kDiabloInvertedSmall: {
            return 10;
        }

        case D2TextFont::kDiabloInvertedMedium: {
            return 9;
        }

        case D2TextFont::kNormalSmall: {
            return 6;
        }

        case D2TextFont::kNormalMedium: {
            return 4;
        }

        case D2TextFont::kNormalMediumBold: {
            return 13;
        }

        case D2TextFont::kNormalBigBold: {
            return 5;
        }

        case D2TextFont::kWideSmall: {
            // Also has the value 12.
            return 0;
        }

        case D2TextFont::kWideMedium: {
            return 8;
        }
    }

    // Should never happen.
    return -1;
}

} // namespace

int ResolveD2TextFontToValue(enum D2TextFont text_font) {
    return ResolveD2TextFontToValue_1_00(text_font);
}

} // namespace slashgaming::diabloii::constant

#endif // defined(__i386__) || defined(_M_IX86) || defined(_X86_)
