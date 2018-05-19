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

#define SGD2MAPI_DIABLOII_POINTER_D2CLIENTFUNC_H_INCLUDE_
#include "D2ClientFuncHelper.h"
#undef SGD2MAPI_DIABLOII_POINTER_D2CLIENTFUNC_H_INCLUDE_

#include <unordered_map>

#include "../../GameLibrary.h"
#include "../../Pointer.h"
#include "../../Version.h"

namespace slashgaming::diabloii::func {

void __stdcall D2GFX_DrawLine_1_13C(int x1, int y1, int x2, int y2,
        unsigned int color, unsigned int unknown) {
    static const auto func =
            reinterpret_cast<decltype(D2GFX_DrawLine_1_13C)*>(
                Pointer(GameLibraries::kD2Client, {
                    { GameVersion::k1_13C, { PointerType::kOrdinal, 10010 } },
                    { GameVersion::k1_13D, { PointerType::kOrdinal, 10013 } }
                }).get_address());

    func(x1, y1, x2, y2, color, unknown);
}

} // namespace slashgaming::diabloii::func

#endif // defined(__i386__) || defined(_M_IX86) || defined(_X86_)
