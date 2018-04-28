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

#ifndef SGD2MAPI_DIABLOII_PATCH_INTERCEPTIONPATCH_H_
#define SGD2MAPI_DIABLOII_PATCH_INTERCEPTIONPATCH_H_

#include <functional>

#include "BasePatch.h"
#include "../../Common/Common.h"
#include "../Offset.h"

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

// TODO(Mir Drualga): Figure out a way to specify an opcode in an
// architecture-independent way.

/**
 * Opcodes used by this patch.
 */
enum class OpCodes : uint8_t {
    kCall = 0xE8,
    kJmp = 0xE9,
    kNop = 0x90
};

/**
 * A patch that replaces the first bytes with a function call, then replaces
 * the rest of the specified range of bytes with no-op instructions.
 */
class DLLEXPORT InterceptionPatch : public BasePatch {
public:
    /**
     * Creates an instance of InterceptionPatch.
     */
    template <class T>
    InterceptionPatch(OpCodes opcode, const Offset& offset,
            std::function<T> func, size_t patch_size) :
            BasePatch(offset, patch_size), func_ptr_(func.target()) {
        // Patch size needs to at least 5 bytes, otherwise the patch fails.
        common::AssertOrTerminateWithMessage(
                (patch_size < (sizeof(func_ptr_) + 1)),
                "Error: Invalid Patch Size",
                "The InterceptionPatch requires at least a patch size of "
                        "a function pointer and a single opcode.");
    }

    explicit InterceptionPatch(const InterceptionPatch& base_patch) = default;
    InterceptionPatch& operator=(const InterceptionPatch& rhs) = default;

    explicit InterceptionPatch(InterceptionPatch&& base_patch) = default;
    InterceptionPatch& operator=(InterceptionPatch&& rhs) = default;

    /**
     * Returns the function pointer of the interception function.
     */
    uintptr_t get_func_ptr() const;

private:
    uintptr_t func_ptr_;
};

} // namespace slashgaming::diabloii::patch

#undef DLLEXPORT

#endif // SGD2MAPI_DIABLOII_PATCH_INTERCEPTIONPATCH_H_
