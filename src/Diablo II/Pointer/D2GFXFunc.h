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

#ifndef SGD2MAPI_DIABLOII_POINTER_D2GFXFUNC_H_
#define SGD2MAPI_DIABLOII_POINTER_D2GFXFUNC_H_

#define SGD2MAPI_DIABLOII_POINTER_D2GFXFUNC_H_INCLUDE_
#if defined(__i386__) || defined(_M_IX86) || defined(_X86_)
#include "../IA-32/Pointer/D2GFXFuncHelper.h"
#endif
#undef SGD2MAPI_DIABLOII_POINTER_D2GFXFUNC_H_INCLUDE_

#ifdef SGD2MAPI_DLLEXPORT
#define DLLEXPORT __declspec(dllexport)
#else
#ifdef SGD2MAPI_DLLIMPORT
#define DLLEXPORT __declspec(dllimport)
#else
#define DLLEXPORT
#endif
#endif

namespace slashgaming::diabloii::func {

extern "C" {
    DLLEXPORT void D2GFX_DrawLine(int x1, int y1, int x2, int y2,
            unsigned int color, unsigned int unknown);

    DLLEXPORT void D2GFX_DrawRectangle(int x1, int y1, int x2, int y2,
            unsigned int color, unsigned int trans);
}

} // namespace slashgaming::diabloii::func

#undef DLLEXPORT

#endif // SGD2MAPI_DIABLOII_POINTER_D2GFXFUNC_H_
