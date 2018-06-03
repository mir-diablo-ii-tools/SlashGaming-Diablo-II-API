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

#include "../../Constant/D2Difficulty.h"

namespace slashgaming::diabloii::constant {
namespace {

constexpr int ResolveValue_1_00(enum D2Difficulties difficulty) {
    switch (difficulty) {
        case D2Difficulties::kNormal: {
            return 0;
        }

        case D2Difficulties::kNightmare: {
            return 1;
        }

        case D2Difficulties::kHell: {
            return 2;
        }
    }

    // Should never happen.
    return -1;
}

} // namespace

ExD2Difficulty::ExD2Difficulty(enum D2Difficulties difficulty) :
        difficulty_(difficulty), value_(ResolveValue(difficulty)) {
}

int ExD2Difficulty::ResolveValue(enum D2Difficulties difficulty) {
    return ResolveValue_1_00(difficulty);
}

int ExD2Difficulty::value() const {
    return value_;
}

enum D2Difficulties ExD2Difficulty::difficulty() const {
    return difficulty_;
}

} // namespace slashgaming::diabloii::constant

#endif // defined(__i386__) || defined(_M_IX86) || defined(_X86_)
