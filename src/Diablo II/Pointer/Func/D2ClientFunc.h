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

#ifndef SGD2MAPI_DIABLOII_POINTER_FUNC_D2CLIENTFUNC_H_
#define SGD2MAPI_DIABLOII_POINTER_FUNC_D2CLIENTFUNC_H_

#include <windows.h>
#include <cstdint>

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
    DLLEXPORT void D2Client_DrawRectFrame(RECT* rect_ptr);
    DLLEXPORT enum constant::D2Difficulty D2Client_GetDifficulty();
    DLLEXPORT int D2Client_GetMouseX();
    DLLEXPORT int D2Client_GetMouseY();
    DLLEXPORT void D2Client_SetDifficulty(
            enum constant::D2Difficulty difficulty);
}

} // namespace slashgaming::diabloii::func

#undef DLLEXPORT

#endif // SGD2MAPI_DIABLOII_POINTER_FUNC_D2CLIENTFUNC_H_
