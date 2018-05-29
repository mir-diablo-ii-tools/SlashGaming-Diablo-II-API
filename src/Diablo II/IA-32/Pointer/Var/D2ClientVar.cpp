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

#include "../../../Pointer/Var/D2ClientVar.h"

#include <cstdint>
#include <unordered_map>

#include "../../../GameLibrary.h"
#include "../../../Pointer.h"
#include "../../../Version.h"

#define ESCAPE_PARENTHESIS(...) { __VA_ARGS__ }

#define VARPTR(name, type, offset_map) \
type* D2Client_##name() { \
    static const Pointer pointer(GameLibraries::kD2Client, \
            ESCAPE_PARENTHESIS offset_map); \
    static type* var_ptr = reinterpret_cast<type*>(pointer.address()); \
    return var_ptr; \
}

namespace slashgaming::diabloii::var {

VARPTR(PanelOffsetX, int, (
    { GameVersion::k1_07, { PointerType::kOffset, 0x12D7FC } },
    { GameVersion::k1_08, { PointerType::kOffset, 0x122B3C } },
    { GameVersion::k1_09D, { PointerType::kOffset, 0x124954 } },
    { GameVersion::k1_10, { PointerType::kOffset, 0x11A748 } },
    { GameVersion::k1_11, { PointerType::kOffset, 0x11BD24 } },
    { GameVersion::k1_11B, { PointerType::kOffset, 0x11BEF8 } },
    { GameVersion::k1_12A, { PointerType::kOffset, 0x11BD28 } },
    { GameVersion::k1_13C, { PointerType::kOffset, 0x11B9A0 } },
    { GameVersion::k1_13D, { PointerType::kOffset, 0x11D354 } },
    { GameVersion::kLod1_14A, { PointerType::kOffset, 0x442F58 } },
    { GameVersion::kLod1_14B, { PointerType::kOffset, 0x39A8E0 } },
    { GameVersion::kLod1_14C, { PointerType::kOffset, 0x3998E0 } },
    { GameVersion::kLod1_14D, { PointerType::kOffset, 0x3A2858 } },
));

VARPTR(PanelOffsetY, int, (
    { GameVersion::k1_07, { PointerType::kOffset, 0x12D800 } },
    { GameVersion::k1_08, { PointerType::kOffset, 0x122B40 } },
    { GameVersion::k1_09D, { PointerType::kOffset, 0x124958 } },
    { GameVersion::k1_10, { PointerType::kOffset, 0x11A74C } },
    { GameVersion::k1_11, { PointerType::kOffset, 0x11BD28 } },
    { GameVersion::k1_11B, { PointerType::kOffset, 0x11BEFC } },
    { GameVersion::k1_12A, { PointerType::kOffset, 0x11BD2C } },
    { GameVersion::k1_13C, { PointerType::kOffset, 0x11B9A4 } },
    { GameVersion::k1_13D, { PointerType::kOffset, 0x11D358 } },
    { GameVersion::kLod1_14A, { PointerType::kOffset, 0x442F5C } },
    { GameVersion::kLod1_14B, { PointerType::kOffset, 0x39A8E4 } },
    { GameVersion::kLod1_14C, { PointerType::kOffset, 0x3998E4 } },
    { GameVersion::kLod1_14D, { PointerType::kOffset, 0x3A285C } },
));

VARPTR(ScreenSizeX, int, (
    { GameVersion::k1_07, { PointerType::kOffset, 0xDE0E4 } },
    { GameVersion::k1_12A, { PointerType::kOffset, 0xDC6E0 } },
    { GameVersion::k1_13C, { PointerType::kOffset, 0xDBC48 } },
    { GameVersion::k1_13D, { PointerType::kOffset, 0xF7034 } },
));

VARPTR(ScreenSizeY, int, (
    { GameVersion::k1_07, { PointerType::kOffset, 0xDE0E8 } },
    { GameVersion::k1_12A, { PointerType::kOffset, 0xDC6E4 } },
    { GameVersion::k1_13C, { PointerType::kOffset, 0xDBC4C } },
    { GameVersion::k1_13D, { PointerType::kOffset, 0xF7038 } },
));

VARPTR(MouseX, int, (
    { GameVersion::k1_00, { PointerType::kOffset, 0x11AFF8 } },
    { GameVersion::k1_12A, { PointerType::kOffset, 0x101638 } },
    { GameVersion::k1_13C, { PointerType::kOffset, 0x11B828 } },
    { GameVersion::k1_13D, { PointerType::kOffset, 0x11C950 } },
));

VARPTR(MouseY, int, (
    { GameVersion::k1_00, { PointerType::kOffset, 0x11AFFC } },
    { GameVersion::k1_12A, { PointerType::kOffset, 0x101634 } },
    { GameVersion::k1_13C, { PointerType::kOffset, 0x11B824 } },
    { GameVersion::k1_13D, { PointerType::kOffset, 0x11C94C } },
));

} // namespace slashgaming::diabloii::var

#undef VARPTR

#undef ESCAPE_PARENTHESIS

#endif // defined(__i386__) || defined(_M_IX86) || defined(_X86_)
