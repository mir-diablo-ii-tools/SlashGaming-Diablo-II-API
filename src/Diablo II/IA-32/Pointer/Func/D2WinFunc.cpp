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

#include "../../../Pointer/Func/D2WinFunc.h"

#define SGD2MAPI_DIABLOII_IA_32_POINTER_FUNC_HELPER_D2WINFUNCHELPER_H_INCLUDE_
#include "Helper/D2WinFuncHelper.h"
#undef SGD2MAPI_DIABLOII_IA_32_POINTER_FUNC_HELPER_D2WINFUNCHELPER_H_INCLUDE_
#include "../../../Constants.h"
#include "../../../GameLibrary.h"
#include "../../../Pointer.h"
#include "../../../Version.h"

namespace slashgaming::diabloii::func {

void D2Win_DrawText(const wchar_t* text, int x, int y,
        enum constant::D2TextColors color, bool has_indent) {
    int raw_value = constant::ResolveD2TextColorToValue(color);
    D2Win_DrawText_1_00(text, x, y, raw_value, has_indent);
}

void D2Win_GetTextSize(const wchar_t* text, int* text_width_ptr,
        int* text_height_ptr) {
    D2Win_GetTextSize_1_00(text, text_width_ptr, text_height_ptr);
}

void D2Win_SetTextFont(enum constant::D2TextFonts text_font) {
    int raw_value = constant::ResolveD2TextFontToValue(text_font);
    D2Win_SetTextFont_1_00(raw_value);
}

} // namespace slashgaming::diabloii::func

#endif // defined(__i386__) || defined(_M_IX86) || defined(_X86_)
