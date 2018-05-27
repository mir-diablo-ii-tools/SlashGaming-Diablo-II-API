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

#include "../../Pointer/D2ClientVar.h"

#include <cstdint>
#include <unordered_map>

#include "../../GameLibrary.h"
#include "../../Pointer.h"
#include "../../Version.h"

#define ESCAPE_PARENTHESIS(...) { __VA_ARGS__ }

#define VARPTR(name, type, offset_map) \
type* D2Client_##name() { \
    static const Pointer pointer(GameLibraries::kD2Client, \
            ESCAPE_PARENTHESIS offset_map); \
    static type* var_ptr = reinterpret_cast<type*>(pointer.address()); \
    return var_ptr; \
}

namespace slashgaming::diabloii::var {

VARPTR(ScreenSizeX, int, (
    { GameVersion::k1_07, { PointerType::kOffset, 0xDE0E4 } },
    { GameVersion::k1_13C, { PointerType::kOffset, 0xDBC48 } },
    { GameVersion::k1_13D, { PointerType::kOffset, 0xF7034 } },
));

VARPTR(ScreenSizeY, int, (
    { GameVersion::k1_07, { PointerType::kOffset, 0xDE0E8 } },
    { GameVersion::k1_13C, { PointerType::kOffset, 0xDBC4C } },
    { GameVersion::k1_13D, { PointerType::kOffset, 0xF7038 } },
));

} // namespace slashgaming::diabloii::var

#undef VARPTR

#undef ESCAPE_PARENTHESIS

#endif // defined(__i386__) || defined(_M_IX86) || defined(_X86_)
