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

template class D2BaseConstant<int8_t>;
template class D2BaseConstant<uint8_t>;

template class D2BaseConstant<int16_t>;
template class D2BaseConstant<uint16_t>;

template class D2BaseConstant<int32_t>;
template class D2BaseConstant<uint32_t>;

template class D2BaseConstant<int64_t>;
template class D2BaseConstant<uint64_t>;

template<typename T>
D2BaseConstant<T>::operator T() {
    if (!is_initialized()) {
        value_ = ResolveValue();
        is_initialized_ = true;
    }
    return get_value();
}

template<typename T>
T D2BaseConstant<T>::get_value() const {
    return value_;
}

template<typename T>
bool D2BaseConstant<T>::is_initialized() const {
    return is_initialized_;
}

} // namespace slashgaming::diabloii::constant
