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

#include "../../Constant/D2TextColor.h"

namespace slashgaming::diabloii::constant {
namespace {

constexpr int ResolveD2TextColorToValue_1_00(enum D2TextColors text_color) {
    switch (text_color) {
        case D2TextColors::kBlue: {
            return 3;
        }

        case D2TextColors::kBlack: {
            // Also has the value 19.
            return 6;
        }

        case D2TextColors::kCorrupted: {
            return 16;
        }

        case D2TextColors::kDarkGold: {
            return 4;
        }

        case D2TextColors::kGold: {
            return 7;
        }

        case D2TextColors::kDarkGreen: {
            return 12;
        }

        case D2TextColors::kDarkerGreen: {
            return 10;
        }

        case D2TextColors::kLightGreen: {
            return 2;
        }

        case D2TextColors::kDarkGrey: {
            return 5;
        }

        case D2TextColors::kLightGrey: {
            return 15;
        }

        case D2TextColors::kMetallic: {
            return 14;
        }

        case D2TextColors::kOrange: {
            return 8;
        }

        case D2TextColors::kPurple: {
            return 11;
        }

        case D2TextColors::kLightRed: {
            return 1;
        }

        case D2TextColors::kDarkRed: {
            return 18;
        }

        case D2TextColors::kBrightWhite: {
            return 17;
        }

        case D2TextColors::kWhite: {
            // Also has the values 13 and 20.
            return 0;
        }

        case D2TextColors::kYellow: {
            return 9;
        }
    }

    // Should never happen.
    return -1;
}

} // namespace

int ResolveD2TextColorToValue(enum D2TextColors text_color) {
    return ResolveD2TextColorToValue_1_00(text_color);
}

} // namespace slashgaming::diabloii::constant

#endif // defined(__i386__) || defined(_M_IX86) || defined(_X86_)
