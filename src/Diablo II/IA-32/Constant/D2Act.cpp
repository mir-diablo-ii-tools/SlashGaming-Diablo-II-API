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

#include "../../Constant/D2Act.h"

namespace slashgaming::diabloii::constant {
namespace {

constexpr int ResolveD2ActToValue_1_00(enum D2Act act) {
    switch (act) {
        case D2Act::kAct1: {
            return 0;
        }

        case D2Act::kAct2: {
            return 1;
        }

        case D2Act::kAct3: {
            return 2;
        }

        case D2Act::kAct4: {
            return 3;
        }

        case D2Act::kAct5: {
            return 4;
        }
    }

    // Should never happen.
    return -1;
}

constexpr enum D2Act ResolveValueToD2Act_1_00(int raw_value) {
    switch (raw_value) {
        case 0: {
            return D2Act::kAct1;
        }

        case 1: {
            return D2Act::kAct2;
        }

        case 2: {
            return D2Act::kAct3;
        }

        case 3: {
            return D2Act::kAct4;
        }

        case 4: {
            return D2Act::kAct5;
        }
    }

    // Should never happen.
    return static_cast<enum D2Act>(-1);
}

} // namespace

int ResolveD2DifficultyToValue(enum D2Act act) {
    return ResolveD2ActToValue_1_00(act);
}

enum D2Act ResolveValueToD2Act(int raw_value) {
    return ResolveValueToD2Act_1_00(raw_value);
}

} // namespace slashgaming::diabloii::constant

#endif // defined(__i386__) || defined(_M_IX86) || defined(_X86_)
