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

#include "../../Constant/D2FillAlpha.h"

namespace slashgaming::diabloii::constant {
namespace {

constexpr int ResolveD2FillAlphaToValue_1_00(enum D2FillAlphas fill_alpha) {
    switch (fill_alpha) {
        case D2FillAlphas::k50PercentOpaque: {
            return 0;
        }

        case D2FillAlphas::k75PercentOpaque: {
            return 1;
        }

        case D2FillAlphas::k90PercentOpaque: {
            return 2;
        }

        case D2FillAlphas::k0PercentOpaque: {
            return 3;
        }

        case D2FillAlphas::k100PercentBlack: {
            return 4;
        }

        case D2FillAlphas::k100PercentOpaque: {
            return 5;
        }

        case D2FillAlphas::k90PercentBlack: {
            return 6;
        }
    }

    // Should never happen.
    return -1;
}

} // namespace

int ResolveD2FillAlphaToValue(enum D2FillAlphas fill_alpha) {
    return ResolveD2FillAlphaToValue_1_00(fill_alpha);
}

} // namespace slashgaming::diabloii::constant

#endif // defined(__i386__) || defined(_M_IX86) || defined(_X86_)
