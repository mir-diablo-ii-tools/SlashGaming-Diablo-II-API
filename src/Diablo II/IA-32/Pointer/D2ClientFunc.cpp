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

#include "../../Pointer/D2ClientFunc.h"

#include <cstdint>
#include <unordered_map>

#include "../../GameLibrary.h"
#include "../../Pointer.h"
#include "../../Version.h"

namespace slashgaming::diabloii::func {

// D2Client_ExitGame() Start
namespace {

void D2Client_Unknown_001_Lod_1_11();

extern "C" {
    void __stdcall D2Client_Unknown_001_Lod_1_11_Stub(uintptr_t func_ptr);
}

} // namespace

void D2Client_Unknown_001() {
    D2Client_Unknown_001_Lod_1_11();
}

namespace {

void D2Client_Unknown_001_Lod_1_11() {
    static const Pointer pointer(GameLibraries::kD2Client, {
        { GameVersion::k1_11, { PointerType::kOffset, 0x875B0 } },
        { GameVersion::k1_12A, { PointerType::kOffset, 0x7AB00 } },
        { GameVersion::k1_13C, { PointerType::kOffset, 0x42850 } },
        { GameVersion::k1_13D, { PointerType::kOffset, 0x43870 } }
    });

    uintptr_t func_ptr = pointer.get_address();
    D2Client_Unknown_001_Lod_1_11_Stub(func_ptr);
}

} // namespace
// D2Client_ExitGame() End

} // namespace slashgaming::diabloii::func

#endif // defined(__i386__) || defined(_M_IX86) || defined(_X86_)
