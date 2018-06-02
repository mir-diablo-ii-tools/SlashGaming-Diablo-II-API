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

#if defined(__i386__) || defined(_M_IX86) || defined(_X86_)

#define SGD2MAPI_DIABLOII_IA_32_POINTER_FUNC_HELPER_D2WINFUNCHELPER_H_INCLUDE_
#include "D2WinFuncHelper.h"
#undef SGD2MAPI_DIABLOII_IA_32_POINTER_FUNC_HELPER_D2WINFUNCHELPER_H_INCLUDE_

#include "../../../../GameLibrary.h"
#include "../../../../Pointer.h"
#include "../../../../Version.h"

namespace slashgaming::diabloii::func {

void __fastcall D2Win_DrawText_1_00(const wchar_t* text, int x, int y,
        int color, bool has_indent) {
    static const auto func = reinterpret_cast<decltype(D2Win_DrawText_1_00)*>(
        Pointer(GameLibraries::kD2Win, {
            { GameVersion::k1_00, { PointerType::kOrdinal, 10110 } },
            { GameVersion::k1_13C, { PointerType::kOrdinal, 10150 } },
            { GameVersion::k1_13D, { PointerType::kOrdinal, 10076 } },
            { GameVersion::kLod1_14B, { PointerType::kOffset, 0xFFB70 } },
        }).address());

    func(text, x, y, color, has_indent);
}

void __fastcall D2Win_GetTextSize_1_00(const wchar_t* text, int* text_width_ptr,
        int* text_height_ptr) {
    static const auto func =
            reinterpret_cast<decltype(D2Win_GetTextSize_1_00)*>(
        Pointer(GameLibraries::kD2Win, {
            { GameVersion::k1_00, { PointerType::kOrdinal, 10124 } },
            { GameVersion::k1_13C, { PointerType::kOrdinal, 10177 } },
            { GameVersion::k1_13D, { PointerType::kOrdinal, 10179 } },
        }).address());

    func(text, text_width_ptr, text_height_ptr);
}

} // namespace slashgaming::diabloii::func

#endif // defined(__i386__) || defined(_M_IX86) || defined(_X86_)
