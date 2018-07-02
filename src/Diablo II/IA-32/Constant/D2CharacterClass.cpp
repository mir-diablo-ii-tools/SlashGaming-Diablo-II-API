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

#include "../../Constant/D2CharacterClass.h"

namespace slashgaming::diabloii::constant {
namespace {

constexpr int ResolveD2CharacterClassToValue_1_00(
        enum D2CharacterClass character_class) {
    switch (character_class) {
        case D2CharacterClass::kAmazon: {
            return 0;
        }

        case D2CharacterClass::kBarbarian: {
            return 4;
        }

        case D2CharacterClass::kNecromancer: {
            return 2;
        }

        case D2CharacterClass::kPaladin: {
            return 3;
        }

        case D2CharacterClass::kSorceress: {
            return 1;
        }

        case D2CharacterClass::kAssassin: {
            return 6;
        }

        case D2CharacterClass::kDruid: {
            return 5;
        }
    }

    // Should never happen.
    return -1;
}

constexpr enum D2CharacterClass ResolveValueToD2CharacterClass_1_00(
        int raw_value) {
    switch (raw_value) {
        case 0: {
            return D2CharacterClass::kAmazon;
        }

        case 1: {
            return D2CharacterClass::kSorceress;
        }

        case 2: {
            return D2CharacterClass::kNecromancer;
        }

        case 3: {
            return D2CharacterClass::kPaladin;
        }

        case 4: {
            return D2CharacterClass::kBarbarian;
        }

        case 5: {
            return D2CharacterClass::kDruid;
        }

        case 6: {
            return D2CharacterClass::kAssassin;
        }
    }

    // Should never happen.
    return static_cast<enum D2CharacterClass>(-1);
}

} // namespace

int ResolveD2CharacterClassToValue(enum D2CharacterClass character_class) {
    return ResolveD2CharacterClassToValue_1_00(character_class);
}

enum D2CharacterClass ResolveValueToD2CharacterClass(int raw_value) {
    return ResolveValueToD2CharacterClass_1_00(raw_value);
}

} // namespace slashgaming::diabloii::constant

#endif // defined(__i386__) || defined(_M_IX86) || defined(_X86_)
