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

#if defined(__i386__) || defined(_M_IX86) || defined(_X86_)

#include "../../../Pointer/Var/D2WinVar.h"

#include <cstdint>
#include <unordered_map>

#include "../../../GameLibrary.h"
#include "../../../Pointer.h"
#include "../../../Version.h"

#define ESCAPE_PARENTHESIS(...) { __VA_ARGS__ }

#define VARPTR(name, type, offset_map) \
type* D2Win_##name() { \
    static const Pointer pointer(GameLibraries::kD2Win, \
            ESCAPE_PARENTHESIS offset_map); \
    static type* var_ptr = reinterpret_cast<type*>(pointer.address()); \
    return var_ptr; \
}

namespace slashgaming::diabloii::var {

VARPTR(MouseX, int, (
    { GameVersion::k1_00, { PointerType::kOffset, 0x72A90 } },
    { GameVersion::k1_13C, { PointerType::kOffset, 0x21488 } },
    { GameVersion::k1_13D, { PointerType::kOffset, 0x8DB1C } },
));

VARPTR(MouseY, int, (
    { GameVersion::k1_00, { PointerType::kOffset, 0x72A94 } },
    { GameVersion::k1_13C, { PointerType::kOffset, 0x2148C } },
    { GameVersion::k1_13D, { PointerType::kOffset, 0x8DB20 } },
));

} // namespace slashgaming::diabloii::var

#undef VARPTR

#undef ESCAPE_PARENTHESIS

#endif // defined(__i386__) || defined(_M_IX86) || defined(_X86_)
