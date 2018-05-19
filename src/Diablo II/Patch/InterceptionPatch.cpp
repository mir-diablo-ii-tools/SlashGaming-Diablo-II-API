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

    intptr_t address = get_pointer().get_address();

    // If the address is -1, then the patch should not be applied.
    if (address == -1) {
        BasePatch::Apply();
        return;
    }

    // Fill the container with no-op.
    std::vector<uint8_t> replace_buffer(get_patch_size(),
            static_cast<uint8_t>(OpCodes::kNop));

    // Replace the first byte with the opcode.
    replace_buffer.at(0) = static_cast<uint8_t>(get_opcode());

    // Replace the next bytes with the function pointer.
    uintptr_t func_ptr = get_func_ptr();
    std::memmove(&replace_buffer.at(1), &func_ptr, sizeof(func_ptr));

    // Replace the game bytes with the bytes in the buffer.
    std::memmove(reinterpret_cast<void*>(address), replace_buffer.data(),
            sizeof(func_ptr));

    // Set applied to true.
    BasePatch::Apply();
}

OpCodes InterceptionPatch::get_opcode() const {
    return opcode_;
}

uintptr_t InterceptionPatch::get_func_ptr() const {
    return func_ptr_;
}

} // namespace slashgaming::diabloii::patch
