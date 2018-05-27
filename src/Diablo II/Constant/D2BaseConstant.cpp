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

#include "D2BaseConstant.h"

#include <cstdint>

namespace slashgaming::diabloii::constant {

D2BaseConstant::operator int() {
    if (!is_initialized()) {
        value_ = ResolveValue();
        is_initialized_ = true;
    }
    return get_value();
}

int D2BaseConstant::get_value() const {
    return value_;
}

bool D2BaseConstant::is_initialized() const {
    return is_initialized_;
}

} // namespace slashgaming::diabloii::constant
