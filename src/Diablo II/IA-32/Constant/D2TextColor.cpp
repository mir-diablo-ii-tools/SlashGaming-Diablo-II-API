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

constexpr int ResolveD2TextColorToValue_1_00(enum D2TextColor text_color) {
    switch (text_color) {
        case D2TextColor::kBlue: {
            return 3;
        }

        case D2TextColor::kBlack: {
            // Also has the value 19.
            return 6;
        }

        case D2TextColor::kCorrupted: {
            return 16;
        }

        case D2TextColor::kDarkGold: {
            return 4;
        }

        case D2TextColor::kGold: {
            return 7;
        }

        case D2TextColor::kDarkGreen: {
            return 12;
        }

        case D2TextColor::kDarkerGreen: {
            return 10;
        }

        case D2TextColor::kLightGreen: {
            return 2;
        }

        case D2TextColor::kDarkGrey: {
            return 5;
        }

        case D2TextColor::kLightGrey: {
            return 15;
        }

        case D2TextColor::kMetallic: {
            return 14;
        }

        case D2TextColor::kOrange: {
            return 8;
        }

        case D2TextColor::kPurple: {
            return 11;
        }

        case D2TextColor::kLightRed: {
            return 1;
        }

        case D2TextColor::kDarkRed: {
            return 18;
        }

        case D2TextColor::kBrightWhite: {
            return 17;
        }

        case D2TextColor::kWhite: {
            // Also has the values 13 and 20.
            return 0;
        }

        case D2TextColor::kYellow: {
            return 9;
        }
    }

    // Should never happen.
    return -1;
}

} // namespace

int ResolveD2TextColorToValue(enum D2TextColor text_color) {
    return ResolveD2TextColorToValue_1_00(text_color);
}

} // namespace slashgaming::diabloii::constant

#endif // defined(__i386__) || defined(_M_IX86) || defined(_X86_)
