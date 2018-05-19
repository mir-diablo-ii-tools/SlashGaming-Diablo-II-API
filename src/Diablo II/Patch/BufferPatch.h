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

#ifndef SGD2MAPI_DIABLOII_PATCH_BUFFERPATCH_H_
#define SGD2MAPI_DIABLOII_PATCH_BUFFERPATCH_H_

#include <cstdint>
#include <vector>

#include "BasePatch.h"
#include "../Pointer.h"

#ifdef SGD2MAPI_DLLEXPORT
#define DLLEXPORT __declspec(dllexport)
#else
#ifdef SGD2MAPI_DLLIMPORT
#define DLLEXPORT __declspec(dllimport)
#else
#define DLLEXPORT
#endif
#endif

namespace slashgaming::diabloii::patch {

/**
 * A patch that replaces the destination address with the bytes stored in a
 * buffer.
 */
class DLLEXPORT BufferPatch : public BasePatch {
public:
    /**
     * Creates an instance of BufferPatch.
     */
    BufferPatch(const Pointer& pointer, const int8_t buffer[],
            size_t patch_size);

    /**
     * Creates an instance of BufferPatch.
     */
    BufferPatch(const Pointer& pointer, const std::vector<int8_t>& buffer);

    /**
     * Creates an instance of BufferPatch.
     */
    BufferPatch(const Pointer& pointer, const std::vector<int8_t>& buffer,
            size_t patch_size);

    explicit BufferPatch(const BufferPatch& base_patch) = default;
    BufferPatch& operator=(const BufferPatch& rhs) = default;

    explicit BufferPatch(BufferPatch&& base_patch) = default;
    BufferPatch& operator=(BufferPatch&& rhs) = default;

    virtual void Apply() override;

    /**
     * Returns a const reference to the buffer that stores the replacement
     * bytes.
     */
    const std::vector<int8_t>& get_buffer() const;

private:
    const std::vector<int8_t> buffer_;
};

} // namespace slashgaming::diabloii::patch

#undef DLLEXPORT

#endif // SGD2MAPI_DIABLOII_PATCH_BUFFERPATCH_H_
