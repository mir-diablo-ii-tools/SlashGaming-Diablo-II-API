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

#ifndef SGD2MAPI_DIABLOII_PATCH_BASEPATCH_H_
#define SGD2MAPI_DIABLOII_PATCH_BASEPATCH_H_

#include <cstdint>
#include <vector>

#include "../Pointer.h"

#ifdef SGD2MAPI_DLLEXPORT
#define DLLEXPORT __declspec(dllexport)
#elif defined(SGD2MAPI_DLLIMPORT)
#define DLLEXPORT __declspec(dllimport)
#else
#define DLLEXPORT
#endif

namespace slashgaming::diabloii::patch {

/**
 * The base patch used to implement more specific patches.
 */
class DLLEXPORT BasePatch {
public:
    /**
     * Applies the patch to the game.
     */
    virtual void Apply();

    /**
     * Restores the values that have been patched to their original values.
     */
    virtual void Remove();

    /**
     * Returns the pointer used by this patch.
     */
    const Pointer& get_pointer() const;

    /**
     * Returns the number of bytes needed to apply this patch.
     */
    size_t get_patch_size() const;

    /**
     * Returns whether or not the patch has been applied.
     */
    bool is_patch_applied() const;

protected:
    /**
     * Initializes the offset and patch size of this patch.
     */
    BasePatch(const Pointer& pointer, size_t patch_size);
    explicit BasePatch(const BasePatch& base_patch) = default;
    BasePatch& operator=(const BasePatch& rhs) = default;

    explicit BasePatch(BasePatch&& base_patch) = default;
    BasePatch& operator=(BasePatch&& rhs) = default;

    ~BasePatch();

private:
    const Pointer pointer_;
    const size_t patch_size_;

    bool is_patch_applied_;
    std::vector<int8_t> old_bytes_;
};

} // namespace slashgaming::diabloii::patch

#undef DLLEXPORT

#endif // SGD2MAPI_DIABLOII_PATCH_BASEPATCH_H_
