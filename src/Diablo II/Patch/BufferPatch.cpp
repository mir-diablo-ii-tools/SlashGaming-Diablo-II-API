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

#include "BufferPatch.h"

#include <cstdint>
#include <vector>

#include "BasePatch.h"
#include "../Offset.h"

namespace slashgaming::diabloii::patch {

BufferPatch::BufferPatch(const Offset& offset, const int8_t buffer[],
        size_t patch_size) :
        BasePatch(offset, patch_size),
        buffer_(buffer, buffer + patch_size) {
}

BufferPatch::BufferPatch(const Offset& offset, const std::vector<int8_t>& buffer) :
        BufferPatch(offset, buffer, buffer.size()) {
}

BufferPatch::BufferPatch(const Offset& offset, const std::vector<int8_t>& buffer,
        size_t patch_size) :
        BasePatch(offset, patch_size), buffer_(buffer) {
}

const std::vector<int8_t>& BufferPatch::get_buffer() const {
    return buffer_;
}

} // namespace slashgaming::diabloii::patch
