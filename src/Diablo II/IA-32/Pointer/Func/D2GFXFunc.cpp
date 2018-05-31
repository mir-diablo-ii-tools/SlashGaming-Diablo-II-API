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

#include "../../../Pointer/Func/D2GFXFunc.h"

#include <cstdint>

#define SGD2MAPI_DIABLOII_IA_32_POINTER_FUNC_HELPER_D2GFXFUNCHELPER_H_INCLUDE_
#include "Helper/D2GFXFuncHelper.h"
#undef SGD2MAPI_DIABLOII_IA_32_POINTER_FUNC_HELPER_D2GFXFUNCHELPER_H_INCLUDE_
#include "../../../Constants.h"
#include "../../../GameLibrary.h"
#include "../../../Pointer.h"
#include "../../../Version.h"

namespace slashgaming::diabloii::func {

void D2GFX_DrawLine(int x1, int y1, int x2, int y2, unsigned int color,
        unsigned int unknown) {
    D2GFX_DrawLine_1_00(x1, y1, x2, y2, color, unknown);
}

void D2GFX_DrawRectangle(int x1, int y1, int x2, int y2, unsigned int color,
        enum constant::D2FillAlphas fill_alpha) {
    constant::ExD2FillAlpha ex_fill_alpha(fill_alpha);
    D2GFX_DrawRectangle_Ex(x1, y1, x2, y2, color, &ex_fill_alpha);
}

void D2GFX_DrawRectangle_Ex(int x1, int y1, int x2, int y2, unsigned int color,
        const constant::ExD2FillAlpha* fill_alpha_ptr) {
    D2GFX_DrawRectangle_1_00(x1, y1, x2, y2, color, fill_alpha_ptr->value());
}

} // namespace slashgaming::diabloii::func

#endif // defined(__i386__) || defined(_M_IX86) || defined(_X86_)
