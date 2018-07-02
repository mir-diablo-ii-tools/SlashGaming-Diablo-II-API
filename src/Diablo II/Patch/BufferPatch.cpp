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

#include "BufferPatch.h"

#include <cstdint>
#include <cstring>
#include <vector>

#include "BasePatch.h"
#include "../Pointer.h"

namespace slashgaming::diabloii::patch {

BufferPatch::BufferPatch(const Pointer& pointer, const int8_t buffer[],
        size_t patch_size) :
        BasePatch(pointer, patch_size),
        buffer_(buffer, buffer + patch_size) {
}

BufferPatch::BufferPatch(const Pointer& pointer,
        const std::vector<int8_t>& buffer) :
        BufferPatch(pointer, buffer, buffer.size()) {
}

BufferPatch::BufferPatch(const Pointer& pointer,
        const std::vector<int8_t>& buffer, size_t patch_size) :
        BasePatch(pointer, patch_size), buffer_(buffer) {
}

void BufferPatch::Apply() {
    if (is_patch_applied()) {
        return;
    }

    intptr_t address = pointer().address();

    // If the address is -1, then the patch should not be applied.
    if (address == -1) {
        BasePatch::Apply();
        return;
    }

    // Replace the game bytes with the bytes in the buffer.
    std::memmove(reinterpret_cast<void*>(address), buffer().data(),
            buffer().size() * sizeof(int8_t));

    // Set applied to true.
    BasePatch::Apply();
}

const std::vector<int8_t>& BufferPatch::buffer() const {
    return buffer_;
}

} // namespace slashgaming::diabloii::patch
