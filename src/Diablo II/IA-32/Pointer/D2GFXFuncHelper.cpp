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

#define SGD2MAPI_DIABLOII_IA_32_POINTER_D2GFXFUNCHELPER_H_INCLUDE_
#include "D2GFXFuncHelper.h"
#undef SGD2MAPI_DIABLOII_IA_32_POINTER_D2GFXFUNCHELPER_H_INCLUDE_

#include "../../GameLibrary.h"
#include "../../Pointer.h"
#include "../../Version.h"

namespace slashgaming::diabloii::func {

void __stdcall D2GFX_DrawLine_1_00(int x1, int y1, int x2, int y2,
        unsigned int color, unsigned int unknown) {
    static const auto func = reinterpret_cast<decltype(D2GFX_DrawLine_1_00)*>(
        Pointer(GameLibraries::kD2GFX, {
            { GameVersion::k1_00, { PointerType::kOrdinal, 10061 } },
            { GameVersion::k1_03, { PointerType::kOrdinal, 10061 } },
            { GameVersion::k1_04B, { PointerType::kOrdinal, 10061 } },
            { GameVersion::k1_05B, { PointerType::kOrdinal, 10061 } },
            { GameVersion::k1_07, { PointerType::kOrdinal, 10057 } },
            { GameVersion::k1_13C, { PointerType::kOrdinal, 10010 } },
            { GameVersion::k1_13D, { PointerType::kOrdinal, 10013 } },
            { GameVersion::kClassic1_14A, { PointerType::kOffset, 0x2BEED0 } },
            { GameVersion::kLod1_14A, { PointerType::kOffset, 0x2BD720 } },
            { GameVersion::kClassic1_14B, { PointerType::kOffset, 0xE6C50 } },
            { GameVersion::kLod1_14B, { PointerType::kOffset, 0xF3990 } },
            { GameVersion::kClassic1_14C, { PointerType::kOffset, 0xE6C50 } },
            { GameVersion::kLod1_14C, { PointerType::kOffset, 0xF3990 } },
            { GameVersion::kClassic1_14D, { PointerType::kOffset, 0xE9370 } },
            { GameVersion::kLod1_14D, { PointerType::kOffset, 0xF6380 } },
        }).address());

    func(x1, y1, x2, y2, color, unknown);
}

void __stdcall D2GFX_DrawRectangle_1_00(int x1, int y1, int x2, int y2,
        unsigned int color, unsigned int fill_alpha) {
    static const auto func =
            reinterpret_cast<decltype(D2GFX_DrawRectangle_1_00)*>(
        Pointer(GameLibraries::kD2GFX, {
            { GameVersion::k1_00, { PointerType::kOrdinal, 10059 } },
            { GameVersion::k1_13C, { PointerType::kOrdinal, 10014 } },
            { GameVersion::k1_13D, { PointerType::kOrdinal, 10028 } },
        }).address());

    func(x1, y1, x2, y2, color, fill_alpha);
}

} // slashgaming::diabloii::func

#endif // defined(__i386__) || defined(_M_IX86) || defined(_X86_)
