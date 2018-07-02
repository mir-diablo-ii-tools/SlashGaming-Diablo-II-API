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

#include "InterceptionPatch.h"

#include <cstdint>
#include <cstring>
#include <vector>

#include "BasePatch.h"

namespace slashgaming::diabloii::patch {

void InterceptionPatch::Apply() {
    if (is_patch_applied()) {
        return;
    }

    intptr_t address = pointer().address();

    // If the address is -1, then the patch should not be applied.
    if (address == -1) {
        BasePatch::Apply();
        return;
    }

    // Fill the container with no-op.
    std::vector<uint8_t> replace_buffer(patch_size(),
            static_cast<uint8_t>(OpCodes::kNop));

    // Replace the first byte with the opcode.
    replace_buffer.at(0) = static_cast<uint8_t>(opcode());

    // Replace the next bytes with the function pointer.
    uintptr_t temp_func_ptr = func_ptr();
    std::memmove(&replace_buffer.at(1), &temp_func_ptr, sizeof(temp_func_ptr));

    // Replace the game bytes with the bytes in the buffer.
    std::memmove(reinterpret_cast<void*>(address), replace_buffer.data(),
            sizeof(temp_func_ptr));

    // Set applied to true.
    BasePatch::Apply();
}

OpCodes InterceptionPatch::opcode() const {
    return opcode_;
}

uintptr_t InterceptionPatch::func_ptr() const {
    return func_ptr_;
}

} // namespace slashgaming::diabloii::patch
