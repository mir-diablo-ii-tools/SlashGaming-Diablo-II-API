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

#include "../../../Pointer/Func/D2ClientFunc.h"

#include <cstdint>
#include <unordered_map>

#include "../../../Constants.h"
#define SGD2MAPI_DIABLOII_IA_32_POINTER_FUNC_HELPER_D2CLIENTFUNCHELPER_H_INCLUDE_
#include "Helper/D2ClientFuncHelper.h"
#undef SGD2MAPI_DIABLOII_IA_32_POINTER_FUNC_HELPER_D2CLIENTFUNCHELPER_H_INCLUDE_
#include "../../../GameLibrary.h"
#include "../../../Pointer.h"
#include "../../../Structs.h"
#include "../../../Version.h"

namespace slashgaming::diabloii::func {

void D2Client_Unknown_001() {
    D2Client_Unknown_001_1_11();
}

void D2Client_DrawRectFrame(RECT* rect_ptr) {
    int running_version_value = static_cast<int>(GetGameVersion());
    if (running_version_value >= static_cast<int>(GameVersion::k1_11) &&
            running_version_value <= static_cast<int>(GameVersion::k1_13D)) {
        D2Client_DrawRectFrame_1_11(rect_ptr);
    } else {
        D2Client_DrawRectFrame_1_00(rect_ptr);
    }
}

enum constant::D2Difficulty D2Client_GetDifficulty() {
    int raw_value = D2Client_GetDifficulty_1_00();
    return constant::ResolveValueToD2Difficulty(raw_value);
}

int D2Client_GetMouseX() {
    return D2Client_GetMouseX_1_00();
}

int D2Client_GetMouseY() {
    return D2Client_GetMouseY_1_00();
}

struct D2UnitAny* D2Client_GetPlayerUnit() {
    return D2Client_GetPlayerUnit_1_00();
}

void D2Client_SetDifficulty(enum constant::D2Difficulty difficulty) {
    int raw_value = constant::ResolveD2DifficultyToValue(difficulty);
    D2Client_SetDifficulty_1_00(raw_value);
}

} // namespace slashgaming::diabloii::func

#endif // defined(__i386__) || defined(_M_IX86) || defined(_X86_)
