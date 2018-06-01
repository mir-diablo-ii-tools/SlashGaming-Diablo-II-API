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

#ifndef SGD2MAPI_DIABLOII_IA_32_POINTER_FUNC_HELPER_D2WINFUNCHELPER_H_INCLUDE_
#error This file should only be included by the API implementation.
#endif // SGD2MAPI_DIABLOII_IA_32_POINTER_FUNC_D2WINFUNCHELPER_H_INCLUDE_

#ifndef SGD2MAPI_DIABLOII_IA_32_POINTER_FUNC_HELPER_D2WINFUNCHELPER_H_
#define SGD2MAPI_DIABLOII_IA_32_POINTER_FUNC_HELPER_D2WINFUNCHELPER_H_

#include "../../../../Constants.h"
#include "../../../../GameLibrary.h"
#include "../../../../Pointer.h"
#include "../../../../Version.h"

namespace slashgaming::diabloii::func {

void __fastcall D2Win_DrawText_1_00(const wchar_t* text, int x, int y,
        int color, bool has_indent);

void __fastcall D2Win_GetTextSize_1_00(const wchar_t* text, int* text_width_ptr,
        int* file_num_ptr);

} // namespace slashgaming::diabloii::func

#endif // SGD2MAPI_DIABLOII_IA_32_POINTER_FUNC_D2WINFUNCHELPER_H_
#endif // defined(__i386__) || defined(_M_IX86) || defined(_X86_)
