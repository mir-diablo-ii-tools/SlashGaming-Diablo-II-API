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

#ifndef SGD2MAPI_DIABLOII_POINTER_FUNC_D2WINFUNC_H_
#define SGD2MAPI_DIABLOII_POINTER_FUNC_D2WINFUNC_H_

#include "../../Constants.h"

#ifdef SGD2MAPI_DLLEXPORT
#define DLLEXPORT __declspec(dllexport)
#elif defined(SGD2MAPI_DLLIMPORT)
#define DLLEXPORT __declspec(dllimport)
#else
#define DLLEXPORT
#endif

namespace slashgaming::diabloii::func {

extern "C" {
    /**
     * Draws the specified colored text to the display, at the position
     * specified. Indentation may be applied if specified.
     */
    DLLEXPORT void D2Win_DrawText(const wchar_t* text, int x, int y,
            enum constant::D2TextColor color, bool has_indent);

    /**
     * Determines the amount of pixel space needed to display to specified text,
     * storing the width and height values at the specified output pointers.
     */
    DLLEXPORT void D2Win_GetTextSize(const wchar_t* text,
            int* text_width_out_ptr, int* text_height_out_ptr);

    /**
     * Sets the currently active font for displaying custom text to the one
     * specified in the parameters.
     */
    DLLEXPORT void D2Win_SetTextFont(enum constant::D2TextFont text_font);
}

} // namespace slashgaming::diabloii::func

#undef DLLEXPORT
#endif // SGD2MAPI_DIABLOII_POINTER_FUNC_D2WINFUNC_H_
