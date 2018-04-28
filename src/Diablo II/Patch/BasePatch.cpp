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

#include "BasePatch.h"

#include <windows.h>
#include <cstdint>
#include <cstring>

#include "../Offset.h"

namespace slashgaming::diabloii::patch {

BasePatch::BasePatch(const Offset& offset, size_t patch_size) :
        offset_(offset), patch_size_(patch_size), old_bytes_(patch_size) {
    // Copy the old bytes of data for later restoring.
    uintptr_t address = offset_.CalculateAddress();
    std::memmove(old_bytes_.data(), reinterpret_cast<const void*>(address),
            patch_size_);
}

BasePatch::~BasePatch() {
    if (!is_patch_applied()) {
        return;
    }

    Remove();
}

void BasePatch::Apply() {
    is_patch_applied_ = true;
}

void BasePatch::Remove() {
    if (!is_patch_applied()) {
        return;
    }

    // Restore the old bytes of data.
    uintptr_t address = offset_.CalculateAddress();
    std::memmove(reinterpret_cast<void*>(address), old_bytes_.data(),
            patch_size_);

    is_patch_applied_ = false;
}

const Offset& BasePatch::get_offset() const {
    return offset_;
}

size_t BasePatch::get_patch_size() const {
    return patch_size_;
}

bool BasePatch::is_patch_applied() const {
    return is_patch_applied_;
}

} // namespace slashgaming::diabloii::patch
