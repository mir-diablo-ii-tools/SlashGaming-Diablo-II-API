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

#include "D2ClientFunc.h"

#include <cstdint>
#include <unordered_map>

#include "../GameLibrary.h"
#include "../Offset.h"
#include "../Version.h"

#define SWAP_EAX_WITH_ARG \
    "pop eax \n" \
    "xchg eax, [esp] \n"

#define SWAP_EBX_WITH_ARG \
    "pop ebx \n" \
    "xchg ebx, [esp] \n"

#define SWAP_ECX_WITH_ARG \
    "pop ecx \n" \
    "xchg ecx, [esp] \n"

#define SWAP_EDX_WITH_ARG \
    "pop edx \n" \
    "xchg edx, [esp] \n"

#define SWAP_ESI_WITH_ARG \
    "pop esi \n" \
    "xchg esi, [esp] \n"

#define SWAP_EDI_WITH_ARG \
    "pop edi \n" \
    "xchg edi, [esp] \n"

#define SWAP_EBP_WITH_ARG \
    "pop ebp \n" \
    "xchg ebp, [esp] \n"

namespace slashgaming::diabloii::func {

// D2Client_ExitGame() Start
namespace {

void D2Client_ExitGame_Lod_1_13C();
extern "C" void __stdcall D2Client_ExitGame_Lod_1_13C_Stub(uintptr_t func_ptr);

} // namespace

void D2Client_ExitGame() {
    D2Client_ExitGame_Lod_1_13C();
}

namespace {

void D2Client_ExitGame_Lod_1_13C() {
    static const Offset offset(GameLibraries::kD2Client, {
        { GameVersion::kLod1_13C, 0x42850 },
        { GameVersion::kLod1_13D, 0x43870 }
    });

    uintptr_t func_ptr = offset.CalculateAddress();
    D2Client_ExitGame_Lod_1_13C_Stub(func_ptr);
}

asm(".intel_syntax \n"
"_D2Client_ExitGame_Lod_1_13C_Stub@4: \n"
SWAP_EAX_WITH_ARG
"    call eax \n"
"    ret \n"
".att_syntax");

} // namespace
// D2Client_ExitGame() End

} // namespace slashgaming::diabloii::func

#undef SWAP_EAX_WITH_ARG
#undef SWAP_EBX_WITH_ARG
#undef SWAP_ECX_WITH_ARG
#undef SWAP_EDX_WITH_ARG
#undef SWAP_ESI_WITH_ARG
#undef SWAP_EDI_WITH_ARG
#undef SWAP_EBP_WITH_ARG
