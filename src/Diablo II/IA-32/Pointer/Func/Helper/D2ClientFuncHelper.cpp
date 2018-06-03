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

#define SGD2MAPI_DIABLOII_IA_32_POINTER_FUNC_HELPER_D2CLIENTFUNCHELPER_H_INCLUDE_
#include "D2ClientFuncHelper.h"
#undef SGD2MAPI_DIABLOII_IA_32_POINTER_FUNC_HELPER_D2CLIENTFUNCHELPER_H_INCLUDE_

#include <unordered_map>

#define SGD2MAPI_DIABLOII_IA_32_POINTER_FUNC_HELPER_D2CLIENTFUNCSTUBS_H_INCLUDE_
#include "D2ClientFuncStubs.h"
#undef SGD2MAPI_DIABLOII_IA_32_POINTER_FUNC_HELPER_D2CLIENTFUNCSTUBS_H_INCLUDE_
#include "../../../../GameLibrary.h"
#include "../../../../Pointer.h"
#include "../../../../Version.h"

namespace slashgaming::diabloii::func {

void D2Client_Unknown_001_1_11() {
    static const auto func =
            reinterpret_cast<decltype(D2Client_Unknown_001_1_11)*>(
        Pointer(GameLibraries::kD2Client, {
            { GameVersion::k1_11, { PointerType::kOffset, 0x875B0 } },
            { GameVersion::k1_12A, { PointerType::kOffset, 0x7AB00 } },
            { GameVersion::k1_13C, { PointerType::kOffset, 0x42850 } },
            { GameVersion::k1_13D, { PointerType::kOffset, 0x43870 } },
        }).address());

    func();
}

void __fastcall D2Client_DrawRectFrame_1_00(const RECT* rect_ptr) {
    static const auto func =
            reinterpret_cast<decltype(D2Client_DrawRectFrame_1_00)*>(
        Pointer(GameLibraries::kD2Client, {
            { GameVersion::k1_00, { PointerType::kOffset, 0x93D50 } },
            { GameVersion::k1_10, { PointerType::kOffset, 0x81790 } },
            { GameVersion::kLod1_14A, { PointerType::kOffset, 0x61C60 } },
            { GameVersion::kLod1_14B, { PointerType::kOffset, 0x4E450 } },
        }).address());

    func(rect_ptr);
}

void __stdcall D2Client_DrawRectFrame_1_11(const RECT* rect_ptr) {
    static const auto func =
        Pointer(GameLibraries::kD2Client, {
            { GameVersion::k1_11, { PointerType::kOffset, 0x9DDF0 } },
            { GameVersion::k1_13C, { PointerType::kOffset, 0xBE4C0 } },
        }).address();

    D2Client_DrawRectFrame_1_11_Stub(func, rect_ptr);
}

int8_t D2Client_GetDifficulty_1_00() {
    static const auto func =
            reinterpret_cast<decltype(D2Client_GetDifficulty_1_00)*>(
        Pointer(GameLibraries::kD2Client, {
            { GameVersion::k1_00, { PointerType::kOffset, 0x12E30 } },
            { GameVersion::k1_13C, { PointerType::kOffset, 0x41930 } },
            { GameVersion::kLod1_14B, { PointerType::kOffset, 0x49240 } },
        }).address());

    return func();
}

int D2Client_GetMouseX_1_00() {
    static const auto func =
            reinterpret_cast<decltype(D2Client_GetMouseX_1_00)*>(
        Pointer(GameLibraries::kD2Client, {
            { GameVersion::k1_00, { PointerType::kOffset, 0xCA6D0 } },
            { GameVersion::k1_13C, { PointerType::kOffset, 0x15FB0 } },
        }).address());

    return func();
}

int D2Client_GetMouseY_1_00() {
    static const auto func =
            reinterpret_cast<decltype(D2Client_GetMouseY_1_00)*>(
        Pointer(GameLibraries::kD2Client, {
            { GameVersion::k1_00, { PointerType::kOffset, 0xCA6F0 } },
            { GameVersion::k1_13C, { PointerType::kOffset, 0x15FA0 } },
        }).address());

    return func();
}

void __fastcall D2Client_SetDifficulty_1_00(int8_t raw_value) {
    static const auto func =
            reinterpret_cast<decltype(D2Client_SetDifficulty_1_00)*>(
        Pointer(GameLibraries::kD2Client, {
            { GameVersion::k1_00, { PointerType::kOffset, 0x12E10 } },
            { GameVersion::k1_13C, { PointerType::kOffset, 0x41990 } },
            { GameVersion::k1_13C, { PointerType::kOffset, 0x491E0 } },
        }).address());

    return func(raw_value);
}

} // namespace slashgaming::diabloii::func

#endif // defined(__i386__) || defined(_M_IX86) || defined(_X86_)
