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
 *
 *  Additional permissions under GNU Affero General Public License version 3
 *  section 7
 *
 *  If you modify this Program, or any covered work, by linking or combining it
 *  with Diablo II (or a modified version of that library), containing parts
 *  covered by the terms of Blizzard End User License Agreement, the licensors
 *  of this Program grant you additional permission to convey the resulting
 *  work.
 *
 *  If you modify this Program, or any covered work, by declaring a custom
 *  version of an existing Diablo II data structure with members ordered
 *  differently from any official version of the game, then such declarations
 *  are exempt from the terms of GNU Affero General Public License version 3
 *  section 6.
 */

#ifndef SGD2MAPI_DIABLOII_POINTER_VAR_D2CLIENTVAR_H_
#define SGD2MAPI_DIABLOII_POINTER_VAR_D2CLIENTVAR_H_

#ifdef SGD2MAPI_DLLEXPORT
#define DLLEXPORT __declspec(dllexport)
#elif defined(SGD2MAPI_DLLIMPORT)
#define DLLEXPORT __declspec(dllimport)
#else
#define DLLEXPORT
#endif

namespace slashgaming::diabloii::var {

extern "C" {
    DLLEXPORT int* D2Client_PanelOffsetX();
    DLLEXPORT int* D2Client_PanelOffsetY();
    DLLEXPORT int* D2Client_ScreenSizeX();
    DLLEXPORT int* D2Client_ScreenSizeY();
    DLLEXPORT int* D2Client_MouseX();
    DLLEXPORT int* D2Client_MouseY();
}

} // namespace slashgaming::diabloii::var

#undef DLLEXPORT

#endif // SGD2MAPI_DIABLOII_POINTER_VAR_D2CLIENTVAR_H_
