/**
 * SlashGaming Diablo II Modding API for C++
 * Copyright (C) 2018-2022  Mir Drualga
 *
 * This file is part of SlashGaming Diablo II Modding API for C++.
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
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with Diablo II (or a modified version of that game and its
 *  libraries), containing parts covered by the terms of Blizzard End User
 *  License Agreement, the licensors of this Program grant you additional
 *  permission to convey the resulting work. This additional permission is
 *  also extended to any combination of expansions, mods, and remasters of
 *  the game.
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any Graphics Device Interface (GDI), DirectDraw, Direct3D,
 *  Glide, OpenGL, or Rave wrapper (or modified versions of those
 *  libraries), containing parts not covered by a compatible license, the
 *  licensors of this Program grant you additional permission to convey the
 *  resulting work.
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any library (or a modified version of that library) that links
 *  to Diablo II (or a modified version of that game and its libraries),
 *  containing parts not covered by a compatible license, the licensors of
 *  this Program grant you additional permission to convey the resulting
 *  work.
 */

#ifndef SGD2MAPI_CXX_BACKEND_GAME_ADDRESS_TABLE_GAME_ADDRESS_TABLE_DEFINE_HPP_
#define SGD2MAPI_CXX_BACKEND_GAME_ADDRESS_TABLE_GAME_ADDRESS_TABLE_DEFINE_HPP_

#include <tuple>

#include "../../../../include/cxx/default_game_library.hpp"
#include "game_address_locator/game_address_locator.hpp"
#include "game_address_locator/game_exported_name_locator.hpp"
#include "game_address_locator/game_ordinal_locator.hpp"
#include "game_address_locator/game_ordinal_locator.hpp"
#include "game_address_table_impl.hpp"

#define MAPI_GAME_ADDRESS_TABLE_1_00 {\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kBNClient, "GatewayDomainName"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kBNClient, 0x21D90)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kBNClient, "GatewayIpV4Address"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kBNClient, 0x21EB8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2CMP, "CloseCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2CMP, 10032)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2CMP, "GetCelFromCelContext"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2CMP, 10036)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "DifficultyLevel"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x12EDDC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "DrawCenteredUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x10EB)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GameType"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x12EDE0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralDisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x1681A4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralDisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x1681A8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralPlayAreaCameraShiftX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x1348AC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IngameMousePositionX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11AFF8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IngameMousePositionY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11AFFC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsAutomapOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x143664)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsGameMenuOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x143660)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsHelpScreenOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x1436C0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsNewSkillButtonPressed"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x13DDF8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsNewStatsButtonPressed"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x13DDF4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalBeltRecord"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10605)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalBeltSlotPosition"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10606)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalEquipmentSlotLayout"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10604)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalInventoryGridLayout"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10603)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalInventoryPosition"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10602)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalBeltsTxt"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0xA923C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalInventoryTxt"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0xA92B0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalInventoryTxtRecordsCount"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0xA92AC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "BitBlockHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x194E4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "BitBlockWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x190DC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "CelDisplayLeft"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x19C3C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "CelDisplayRight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x19C38)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x190D0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x190D8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Direct3D, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Direct3D, 0x26930)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Direct3D, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Direct3D, 0x26674)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "BitBlockHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xB840)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "BitBlockWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xB434)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "CelDisplayLeft"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xBF80)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "CelDisplayRight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xBF7C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "DrawCelContext"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2GFX, 10076)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "DrawRectangle"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2GFX, 10059)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "IsWindowedMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x2A94C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "ResolutionMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x2A950)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "VideoMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x2A948)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "WindowHandle"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x2A954)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Glide, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Glide, 0x1DE04)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Glide, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Glide, 0x1DD44)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "GetStringByIndex"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Lang, 10004)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "UnicodeChar_Compare"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1019)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "UnicodeChar_Copy"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1136)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "UnicodeChar_CreateWithNoArgs"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x10CD)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "UnicodeChar_CreateWithValue"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x113B)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "UnicodeChar_IsAlpha"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x103C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "UnicodeChar_IsNewLine"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1073)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "UnicodeChar_IsPipe"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1087)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "UnicodeChar_IsWhitespace"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1032)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "UnicodeString_CompareIgnoreCase"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x100A)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "UnicodeString_FindChar"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x101E)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "UnicodeString_Format"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1046)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "UnicodeString_NCompareIgnoreCase"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1091)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_AsciiToUnicode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1122)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_UnicodeToUtf8"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1069)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_Utf8ToUnicode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1118)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcat"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x10B4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcmp"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1050)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcpy"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x10D7)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strlen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1055)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strncat"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x10C8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strncpy"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x114A)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_tolower"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1014)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_toupper"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1154)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "UnloadSysMap"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x104B)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "DrawUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10110)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetPopupUnicodeTextWidthAndHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10124)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetUnicodeTextDrawWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10114)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetUnicodeTextNDrawWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10115)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "LoadCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10035)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "LoadMpq"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x1458A)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "MainMenuMousePositionX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x72A90)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "MainMenuMousePositionY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x72A94)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "SetPopUpUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10122)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "SetUnicodeTextFont"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10120)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "UnloadCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10037)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "UnloadMpq"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x14729)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kFog, "AllocClientMemory"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kFog, 10033)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kFog, "FreeClientMemory"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kFog, 10034)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kStorm, "SFileCloseArchive"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kStorm, 252)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kStorm, "SFileOpenArchive"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kStorm, 266)) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_1_01 {::mapi::GameAddressTableEntry( \
    ::std::tuple( \
        static_cast<::d2::DefaultLibrary>(-1), \
        "" \
    ), \
    ::mapi::GameAddressLocator( \
        ::mapi::GameOffsetLocator( \
            static_cast<::d2::DefaultLibrary>(-1), \
            0 \
        ) \
    ) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_1_02 {::mapi::GameAddressTableEntry( \
    ::std::tuple( \
        static_cast<::d2::DefaultLibrary>(-1), \
        "" \
    ), \
    ::mapi::GameAddressLocator( \
        ::mapi::GameOffsetLocator( \
            static_cast<::d2::DefaultLibrary>(-1), \
            0 \
        ) \
    ) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_1_03 {\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kBNClient, "GatewayDomainName"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kBNClient, 0x21DE0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kBNClient, "GatewayIpV4Address"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kBNClient, 0x21F08)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2CMP, "CloseCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2CMP, 10032)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2CMP, "GetCelFromCelContext"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2CMP, 10036)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "DifficultyLevel"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x12EAC4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "DrawCenteredUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x10E6)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GameType"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x12EAC8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralDisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x1680AC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralDisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x1680B0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralPlayAreaCameraShiftX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x134594)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IngameMousePositionX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11ACA0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IngameMousePositionY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11ACA4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsAutomapOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x143534)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsGameMenuOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x143530)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsHelpScreenOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x143590)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsNewSkillButtonPressed"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x13DB30)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsNewStatsButtonPressed"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x13DB2C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalBeltRecord"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10605)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalBeltSlotPosition"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10606)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalEquipmentSlotLayout"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10604)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalInventoryGridLayout"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10603)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalInventoryPosition"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10602)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalBeltsTxt"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0xAB9F4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalInventoryTxt"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0xABA68)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalInventoryTxtRecordsCount"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0xABA64)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "BitBlockHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x194E4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "BitBlockWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x190DC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "CelDisplayLeft"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x19C3C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "CelDisplayRight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x19C38)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x190D0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x190D8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Direct3D, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Direct3D, 0x26930)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Direct3D, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Direct3D, 0x26674)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "BitBlockHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xB840)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "BitBlockWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xB434)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "CelDisplayLeft"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xBF80)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "CelDisplayRight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xBF7C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "DrawCelContext"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2GFX, 10076)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "DrawRectangle"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2GFX, 10059)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "IsWindowedMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x2A98C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "ResolutionMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x2A990)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "VideoMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x2A988)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "WindowHandle"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x2A994)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Glide, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Glide, 0x1DDC4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Glide, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Glide, 0x1DD04)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "GetStringByIndex"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Lang, 10004)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_AsciiToUnicode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x109B)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_UnicodeToUtf8"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1069)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_Utf8ToUnicode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1118)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcat"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x10B4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcmp"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1050)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcpy"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x10D7)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strlen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1055)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strncat"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x10C8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strncpy"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x114A)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_tolower"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1014)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_toupper"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1154)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "DrawUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10110)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetPopupUnicodeTextWidthAndHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10124)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetUnicodeTextDrawWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10114)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetUnicodeTextNDrawWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10115)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "LoadCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10035)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "LoadMpq"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x146FA)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "MainMenuMousePositionX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x72A98)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "MainMenuMousePositionY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x72A9C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "SetPopUpUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10122)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "SetUnicodeTextFont"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10120)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "UnloadCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10037)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "UnloadMpq"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x148A7)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kFog, "AllocClientMemory"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kFog, 10033)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kFog, "FreeClientMemory"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kFog, 10034)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kStorm, "SFileCloseArchive"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kStorm, 252)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kStorm, "SFileOpenArchive"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kStorm, 266)) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_1_04B_AND_C {::mapi::GameAddressTableEntry( \
    ::std::tuple( \
        static_cast<::d2::DefaultLibrary>(-1), \
        "" \
    ), \
    ::mapi::GameAddressLocator( \
        ::mapi::GameOffsetLocator( \
            static_cast<::d2::DefaultLibrary>(-1), \
            0 \
        ) \
    ) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_1_05 {::mapi::GameAddressTableEntry( \
    ::std::tuple( \
        static_cast<::d2::DefaultLibrary>(-1), \
        "" \
    ), \
    ::mapi::GameAddressLocator( \
        ::mapi::GameOffsetLocator( \
            static_cast<::d2::DefaultLibrary>(-1), \
            0 \
        ) \
    ) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_1_05B {\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kBNClient, "GatewayDomainName"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kBNClient, 0x18138)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kBNClient, "GatewayIpV4Address"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kBNClient, 0x18260)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2CMP, "CloseCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2CMP, 10032)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2CMP, "GetCelFromCelContext"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2CMP, 10036)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "DifficultyLevel"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xE3024)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "DrawCenteredUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x21ED0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GameType"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xE3028)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralDisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xFB594)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralDisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xFB598)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralPlayAreaCameraShiftX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xE7B4C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IngameMousePositionX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xD19A8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IngameMousePositionY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xD19AC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsAutomapOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xF4D9C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsGameMenuOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xF4D98)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsHelpScreenOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xF4DF8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsNewSkillButtonPressed"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xF01F8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsNewStatsButtonPressed"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xF01F4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalBeltRecord"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10605)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalBeltSlotPosition"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10606)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalEquipmentSlotLayout"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10604)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalInventoryGridLayout"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10603)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalInventoryPosition"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10602)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalBeltsTxt"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0x85E70)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalInventoryTxt"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0x85EE0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalInventoryTxtRecordsCount"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0x85EDC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "BitBlockHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x11B0C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "BitBlockWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x11704)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "CelDisplayLeft"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x11F6C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "CelDisplayRight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x11F68)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x116F8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x11700)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Direct3D, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Direct3D, 0x1A708)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Direct3D, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Direct3D, 0x1A44C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "BitBlockHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xB3C8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "BitBlockWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xAFBC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "CelDisplayLeft"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xB8EC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "CelDisplayRight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xB8E8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "DrawCelContext"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2GFX, 10076)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "DrawRectangle"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2GFX, 10059)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "IsWindowedMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x1D05C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "ResolutionMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x1D060)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "VideoMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x1D058)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "WindowHandle"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x1D064)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Glide, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Glide, 0x153AC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Glide, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Glide, 0x152EC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "GetStringByIndex"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Lang, 10004)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_AsciiToUnicode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1AC0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_UnicodeToUtf8"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x2530)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_Utf8ToUnicode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x23F0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcat"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x13A0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcmp"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1210)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcpy"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1470)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strlen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1490)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strncat"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x13D0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strncpy"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1420)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_tolower"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x10E0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_toupper"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x10B0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "DrawUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10110)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetPopupUnicodeTextWidthAndHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10124)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetUnicodeTextDrawWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10114)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetUnicodeTextNDrawWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10115)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "LoadCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10035)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "LoadMpq"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x10595)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "MainMenuMousePositionX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x5BCB8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "MainMenuMousePositionY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x5BCBC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "SetPopUpUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10122)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "SetUnicodeTextFont"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10120)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "UnloadCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10037)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "UnloadMpq"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x10742)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kFog, "AllocClientMemory"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kFog, 10033)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kFog, "FreeClientMemory"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kFog, 10034)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kStorm, "SFileCloseArchive"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kStorm, 252)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kStorm, "SFileOpenArchive"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kStorm, 266)) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_1_06 {::mapi::GameAddressTableEntry( \
    ::std::tuple( \
        static_cast<::d2::DefaultLibrary>(-1), \
        "" \
    ), \
    ::mapi::GameAddressLocator( \
        ::mapi::GameOffsetLocator( \
            static_cast<::d2::DefaultLibrary>(-1), \
            0 \
        ) \
    ) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_1_06B {::mapi::GameAddressTableEntry( \
    ::std::tuple( \
        static_cast<::d2::DefaultLibrary>(-1), \
        "" \
    ), \
    ::mapi::GameAddressLocator( \
        ::mapi::GameOffsetLocator( \
            static_cast<::d2::DefaultLibrary>(-1), \
            0 \
        ) \
    ) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_1_07_BETA {::mapi::GameAddressTableEntry( \
    ::std::tuple( \
        static_cast<::d2::DefaultLibrary>(-1), \
        "" \
    ), \
    ::mapi::GameAddressLocator( \
        ::mapi::GameOffsetLocator( \
            static_cast<::d2::DefaultLibrary>(-1), \
            0 \
        ) \
    ) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_1_07 {::mapi::GameAddressTableEntry( \
    ::std::tuple( \
        static_cast<::d2::DefaultLibrary>(-1), \
        "" \
    ), \
    ::mapi::GameAddressLocator( \
        ::mapi::GameOffsetLocator( \
            static_cast<::d2::DefaultLibrary>(-1), \
            0 \
        ) \
    ) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_1_08 {::mapi::GameAddressTableEntry( \
    ::std::tuple( \
        static_cast<::d2::DefaultLibrary>(-1), \
        "" \
    ), \
    ::mapi::GameAddressLocator( \
        ::mapi::GameOffsetLocator( \
            static_cast<::d2::DefaultLibrary>(-1), \
            0 \
        ) \
    ) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_1_09 {::mapi::GameAddressTableEntry( \
    ::std::tuple( \
        static_cast<::d2::DefaultLibrary>(-1), \
        "" \
    ), \
    ::mapi::GameAddressLocator( \
        ::mapi::GameOffsetLocator( \
            static_cast<::d2::DefaultLibrary>(-1), \
            0 \
        ) \
    ) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_1_09B {::mapi::GameAddressTableEntry( \
    ::std::tuple( \
        static_cast<::d2::DefaultLibrary>(-1), \
        "" \
    ), \
    ::mapi::GameAddressLocator( \
        ::mapi::GameOffsetLocator( \
            static_cast<::d2::DefaultLibrary>(-1), \
            0 \
        ) \
    ) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_1_09D {\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kBNClient, "GatewayDomainName"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kBNClient, 0x1CB38)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kBNClient, "GatewayIpV4Address"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kBNClient, 0x1CC60)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2CMP, "CloseCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2CMP, 10032)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2CMP, "GetCelFromCelContext"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2CMP, 10036)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "DifficultyLevel"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x110BBC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "DrawCenteredUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x29760)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GameType"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x110BC0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralDisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xD40E0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralDisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xD40DC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralPlayAreaCameraShiftX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x115C14)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IngameMousePositionX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x12B168)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IngameMousePositionY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x12B16C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "InventoryArrangeMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x103978)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsAutomapOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x1248DC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsGameMenuOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x1248D8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsHelpScreenOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x124938)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsNewSkillButtonPressed"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11FE88)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsNewStatsButtonPressed"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11FE84)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "ScreenOpenMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x115C10)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "ScreenShiftX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x124954)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "ScreenShiftY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x124958)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalBeltRecord"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10638)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalBeltSlotPosition"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10639)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalEquipmentSlotLayout"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10637)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalInventoryGridLayout"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10636)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalInventoryPosition"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10635)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalBeltsTxt"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0xA1B94)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalInventoryTxt"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0xA1D38)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalInventoryTxtRecordsCount"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0xA1D34)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "BitBlockHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x11B7C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "BitBlockWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x11774)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "CelDisplayLeft"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x11FDC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "CelDisplayRight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x11FD8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x11768)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x11770)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Direct3D, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Direct3D, 0x1B708)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Direct3D, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Direct3D, 0x1B44C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "BitBlockHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xC448)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "BitBlockWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xC03C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "CelDisplayLeft"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xC96C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "CelDisplayRight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xC968)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "DrawCelContext"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2GFX, 10072)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "DrawRectangle"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2GFX, 10055)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "IsWindowedMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x1D20C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "ResolutionMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x1D210)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "VideoMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x1D208)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "WindowHandle"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x1D214)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Glide, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Glide, 0x153CC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Glide, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Glide, 0x1530C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "GetStringByIndex"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Lang, 10004)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_AsciiToUnicode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1B10)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_UnicodeToUtf8"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x2BE0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_Utf8ToUnicode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x2AA0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcat"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x13A0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcmp"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1210)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcpy"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1470)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strlen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1490)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strncat"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x13D0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strncpy"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1420)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_tolower"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x10E0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_toupper"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x10B0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "DrawUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10117)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetPopupUnicodeTextWidthAndHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10131)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetUnicodeTextDrawWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10121)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetUnicodeTextNDrawWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10122)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "LoadCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10039)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "LoadMpq"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x142FB)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "MainMenuMousePositionX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x618A0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "MainMenuMousePositionY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x618A4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "SetPopUpUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10129)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "SetUnicodeTextFont"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10127)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "UnloadCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10041)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "UnloadMpq"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x144A6)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kFog, "AllocClientMemory"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kFog, 10042)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kFog, "FreeClientMemory"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kFog, 10043)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kStorm, "SFileCloseArchive"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kStorm, 252)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kStorm, "SFileOpenArchive"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kStorm, 266)) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_1_10_BETA {::mapi::GameAddressTableEntry( \
    ::std::tuple( \
        static_cast<::d2::DefaultLibrary>(-1), \
        "" \
    ), \
    ::mapi::GameAddressLocator( \
        ::mapi::GameOffsetLocator( \
            static_cast<::d2::DefaultLibrary>(-1), \
            0 \
        ) \
    ) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_1_10S_BETA {::mapi::GameAddressTableEntry( \
    ::std::tuple( \
        static_cast<::d2::DefaultLibrary>(-1), \
        "" \
    ), \
    ::mapi::GameAddressLocator( \
        ::mapi::GameOffsetLocator( \
            static_cast<::d2::DefaultLibrary>(-1), \
            0 \
        ) \
    ) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_1_10 {\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kBNClient, "GatewayDomainName"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kBNClient, 0x1CE30)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kBNClient, "GatewayIpV4Address"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kBNClient, 0x1CF58)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2CMP, "CloseCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2CMP, 10032)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2CMP, "GetCelFromCelContext"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2CMP, 10036)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "DifficultyLevel"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x10795C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "DrawCenteredUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x2FCD0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GameType"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x107960)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralDisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xD40F0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralDisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xD40EC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralPlayAreaCameraShiftX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x10B9C8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IngameMousePositionX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x121AE4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IngameMousePositionY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x121AE8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "InventoryArrangeMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xFA708)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsAutomapOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11A6D0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsGameMenuOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11A6CC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsHelpScreenOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11A72C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsNewSkillButtonPressed"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x115BC0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsNewStatsButtonPressed"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x115BBC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "ScreenOpenMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x10B9C4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "ScreenShiftX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11A748)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "ScreenShiftY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11A74C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalBeltRecord"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10638)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalBeltSlotPosition"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10639)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalEquipmentSlotLayout"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10637)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalInventoryGridLayout"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10636)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalInventoryPosition"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10635)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalBeltsTxt"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0xA9604)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalInventoryTxt"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0xAA2D8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalInventoryTxtRecordsCount"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0xAA2D4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "BitBlockHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x11BBC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "BitBlockWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x117B4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "CelDisplayLeft"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x1201C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "CelDisplayRight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x12018)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x117A8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x117B0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Direct3D, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Direct3D, 0x1A7AC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Direct3D, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Direct3D, 0x1A4F0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "BitBlockHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xC48C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "BitBlockWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xC07C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "CelDisplayLeft"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xC9B4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "CelDisplayRight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xC9B0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "DrawCelContext"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2GFX, 10072)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "DrawRectangle"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2GFX, 10055)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "IsWindowedMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x1D268)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "ResolutionMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x1D26C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "VideoMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x1D264)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "WindowHandle"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x1D270)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Glide, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Glide, 0x15468)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Glide, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Glide, 0x153AC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "GetStringByIndex"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Lang, 10004)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_AsciiToUnicode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1BD0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_UnicodeToUtf8"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x2B60)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_Utf8ToUnicode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x2A40)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcat"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x13F0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcmp"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1210)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcpy"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x14A0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strlen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x14C0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strncat"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1420)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strncmp"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1250)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strncpy"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1460)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_tolower"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x10E0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_toupper"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x10B0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "DrawUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10117)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetPopupUnicodeTextWidthAndHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10131)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetUnicodeTextDrawWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10121)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetUnicodeTextNDrawWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10122)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "LoadCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10039)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "LoadMpq"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x12399)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "MainMenuMousePositionX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x5E234)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "MainMenuMousePositionY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x5E238)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "SetPopUpUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10129)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "SetUnicodeTextFont"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10127)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "UnloadCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10041)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "UnloadMpq"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x12548)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kFog, "AllocClientMemory"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kFog, 10042)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kFog, "FreeClientMemory"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kFog, 10043)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kStorm, "SFileCloseArchive"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kStorm, 252)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kStorm, "SFileOpenArchive"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kStorm, 266)) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_1_11 {::mapi::GameAddressTableEntry( \
    ::std::tuple( \
        static_cast<::d2::DefaultLibrary>(-1), \
        "" \
    ), \
    ::mapi::GameAddressLocator( \
        ::mapi::GameOffsetLocator( \
            static_cast<::d2::DefaultLibrary>(-1), \
            0 \
        ) \
    ) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_1_11B {::mapi::GameAddressTableEntry( \
    ::std::tuple( \
        static_cast<::d2::DefaultLibrary>(-1), \
        "" \
    ), \
    ::mapi::GameAddressLocator( \
        ::mapi::GameOffsetLocator( \
            static_cast<::d2::DefaultLibrary>(-1), \
            0 \
        ) \
    ) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_1_12A {\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kBNClient, "GatewayDomainName"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kBNClient, 0x1F1B8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kBNClient, "GatewayIpV4Address"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kBNClient, 0x1F2B8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2CMP, "CloseCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2CMP, 10106)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2CMP, "GetCelFromCelContext"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2CMP, 10038)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "DifficultyLevel"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11BFF4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "DrawCenteredUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x6A8C0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GameType"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11BFF8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralDisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xDC6E4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralDisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xDC6E0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralPlayAreaCameraShiftX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11C1D4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IngameMousePositionX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x101638)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IngameMousePositionY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x101634)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "InventoryArrangeMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11B980)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsAutomapOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x102B80)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsGameMenuOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x102B7C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsHelpScreenOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x102BDC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsNewSkillButtonPressed"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11C348)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsNewStatsButtonPressed"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11C344)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "ScreenOpenMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11C1D0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "ScreenShiftX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11BD28)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "ScreenShiftY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11BD2C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalBeltRecord"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10225)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalBeltSlotPosition"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10110)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalEquipmentSlotLayout"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10030)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalInventoryGridLayout"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10654)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalInventoryPosition"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10279)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalBeltsTxt"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0xA0750)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalInventoryTxt"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0xA13F8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalInventoryTxtRecordsCount"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0xA13F4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "BitBlockHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0xFDD8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "BitBlockWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0xFDC8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "CelDisplayLeft"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0xFEE4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "CelDisplayRight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0xFEE8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0xFDCC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0xFDD4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Direct3D, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Direct3D, 0x196F4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Direct3D, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Direct3D, 0x19264)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "BitBlockHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xCA98)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "BitBlockWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xCA88)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "CelDisplayLeft"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xC040)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "CelDisplayRight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xC044)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "DrawCelContext"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2GFX, 10024)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "DrawRectangle"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2GFX, 10062)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "IsWindowedMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x1D450)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "ResolutionMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x1D454)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "VideoMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x1D44C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "WindowHandle"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x1D458)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Glide, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Glide, 0x16E8C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Glide, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Glide, 0x16DF0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "GetStringByIndex"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Lang, 10005)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_AsciiToUnicode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0xAF10)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_UnicodeToUtf8"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x8BB0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_Utf8ToUnicode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x8A00)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcat"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0xA610)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcmp"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0xA830)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcpy"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0xA5F0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strlen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0xA6E0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strncat"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0xA750)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strncmp"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0xA7E0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strncpy"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0xA700)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_tolower"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x10C0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_toupper"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x10A0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "DrawUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10001)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetPopupUnicodeTextWidthAndHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10096)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetUnicodeTextDrawWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10132)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetUnicodeTextNDrawWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10041)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "LoadCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10186)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "LoadMpq"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x7E40)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "MainMenuMousePositionX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x5C700)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "MainMenuMousePositionY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x5C704)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "SetPopUpUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10031)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "SetUnicodeTextFont"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10010)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "UnloadCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10130)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "UnloadMpq"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x78D0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kFog, "AllocClientMemory"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kFog, 10042)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kFog, "FreeClientMemory"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kFog, 10043)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kStorm, "SFileCloseArchive"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kStorm, 252)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kStorm, "SFileOpenArchive"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kStorm, 266)) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_1_13A_BETA {::mapi::GameAddressTableEntry( \
    ::std::tuple( \
        static_cast<::d2::DefaultLibrary>(-1), \
        "" \
    ), \
    ::mapi::GameAddressLocator( \
        ::mapi::GameOffsetLocator( \
            static_cast<::d2::DefaultLibrary>(-1), \
            0 \
        ) \
    ) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_1_13C {\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kBNClient, "GatewayDomainName"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kBNClient, 0x1F200)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kBNClient, "GatewayIpV4Address"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kBNClient, 0x1F300)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2CMP, "CloseCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2CMP, 10065)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2CMP, "GetCelFromCelContext"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2CMP, 10021)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "DifficultyLevel"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11C390)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "DrawCenteredUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xBC4E0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GameType"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11C394)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralDisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xDBC4C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralDisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xDBC48)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralPlayAreaCameraShiftX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11C418)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IngameMousePositionX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11B828)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IngameMousePositionY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11B824)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "InventoryArrangeMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11B99C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsAutomapOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xFADA8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsGameMenuOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xFADA4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsHelpScreenOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xFAE04)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsNewSkillButtonPressed"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11C30C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsNewStatsButtonPressed"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11C308)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "ScreenOpenMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11C414)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "ScreenShiftX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11B9A0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "ScreenShiftY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11B9A4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalBeltRecord"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10991)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalBeltSlotPosition"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10333)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalEquipmentSlotLayout"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10701)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalInventoryGridLayout"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10760)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalInventoryPosition"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 11012)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalBeltsTxt"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0xA13DC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalInventoryTxt"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0x9FA5C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalInventoryTxtRecordsCount"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0x9FA58)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "BitBlockHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x101D8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "BitBlockWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x101C8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "CelDisplayLeft"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x101E8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "CelDisplayRight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x101EC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x101CC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x101D4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Direct3D, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Direct3D, 0x1AFD4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Direct3D, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Direct3D, 0x1AB44)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "BitBlockHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xCA90)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "BitBlockWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xCA80)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "CelDisplayLeft"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xCA98)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "CelDisplayRight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xCA9C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "DrawCelContext"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2GFX, 10041)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "DrawRectangle"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2GFX, 10014)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "IsWindowedMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x1125C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "ResolutionMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x11260)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "VideoMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x11258)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "WindowHandle"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x11264)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Glide, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Glide, 0x15B04)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Glide, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Glide, 0x15A68)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "GetStringByIndex"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Lang, 10003)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_AsciiToUnicode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x8320)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_UnicodeToUtf8"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x8E80)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_Utf8ToUnicode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x8CD0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcat"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0xAFE0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcmp"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0xB200)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcpy"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0xAFC0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strlen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0xB0B0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strncat"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0xB120)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strncmp"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0xB1B0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strncpy"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0xB0D0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_tolower"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x10C0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_toupper"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x10A0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "DrawUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10150)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetPopupUnicodeTextWidthAndHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10177)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetUnicodeTextDrawWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10028)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetUnicodeTextNDrawWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10055)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "LoadCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10111)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "LoadMpq"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x7E60)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "MainMenuMousePositionX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x21488)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "MainMenuMousePositionY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x2148C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "SetPopUpUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10085)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "SetUnicodeTextFont"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10184)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "UnloadCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10126)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "UnloadMpq"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x78F0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kFog, "AllocClientMemory"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kFog, 10042)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kFog, "FreeClientMemory"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kFog, 10043)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kStorm, "SFileCloseArchive"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kStorm, 252)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kStorm, "SFileOpenArchive"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kStorm, 266)) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_1_13D {\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kBNClient, "GatewayDomainName"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kBNClient, 0x1EDF8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kBNClient, "GatewayIpV4Address"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kBNClient, 0x1EEF8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2CMP, "CloseCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2CMP, 10020)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2CMP, "GetCelFromCelContext"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2CMP, 10035)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "DifficultyLevel"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11D1D8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "DrawCenteredUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xBEC80)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GameType"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11D1DC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralDisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xF7038)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralDisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xF7034)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralPlayAreaCameraShiftX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11D074)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IngameMousePositionX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11C950)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IngameMousePositionY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11C94C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "InventoryArrangeMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11D2B4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsAutomapOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11C8B8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsGameMenuOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11C8B4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsHelpScreenOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11C914)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsNewSkillButtonPressed"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11D31C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsNewStatsButtonPressed"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11D318)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "ScreenOpenMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11D070)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "ScreenShiftX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11D354)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "ScreenShiftY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x11D358)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalBeltRecord"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10370)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalBeltSlotPosition"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10689)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalEquipmentSlotLayout"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10441)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalInventoryGridLayout"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10964)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalInventoryPosition"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Common, 10770)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalBeltsTxt"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0xA4BA0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalInventoryTxt"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0xA4CAC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalInventoryTxtRecordsCount"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0xA4CA8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "BitBlockHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x100E8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "BitBlockWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x100D8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "CelDisplayLeft"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0xF380)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "CelDisplayRight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0xF384)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x100DC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x100E4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Direct3D, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Direct3D, 0x32DFC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Direct3D, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Direct3D, 0x3296C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "BitBlockHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xC980)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "BitBlockWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xC970)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "CelDisplayLeft"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xCA94)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "CelDisplayRight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0xCA98)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "DrawCelContext"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2GFX, 10042)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "DrawRectangle"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2GFX, 10028)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "IsWindowedMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x14A3C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "ResolutionMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x14A40)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "VideoMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x14A38)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "WindowHandle"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x14A44)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Glide, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Glide, 0x15B14)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Glide, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Glide, 0x15A78)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "GetStringByIndex"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Lang, 10004)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_AsciiToUnicode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x82E0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_UnicodeToUtf8"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0xB6D0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_Utf8ToUnicode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0xB520)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcat"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x8B90)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcmp"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0xB200)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcpy"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0xAFC0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strlen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x8C60)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strncat"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0xB120)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strncmp"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x8D60)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strncpy"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0xB0D0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_tolower"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x10C0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_toupper"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x10A0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "DrawUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10076)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetPopupUnicodeTextWidthAndHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10179)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetUnicodeTextDrawWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10150)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetUnicodeTextNDrawWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10148)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "LoadCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10023)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "LoadMpq"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x7E50)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "MainMenuMousePositionX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x8DB1C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "MainMenuMousePositionY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x8DB20)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "SetPopUpUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10137)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "SetUnicodeTextFont"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10047)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "UnloadCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kD2Win, 10189)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "UnloadMpq"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x78E0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kFog, "AllocClientMemory"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kFog, 10042)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kFog, "FreeClientMemory"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kFog, 10043)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kStorm, "SFileCloseArchive"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kStorm, 252)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kStorm, "SFileOpenArchive"), \
    ::mapi::GameAddressLocator(::mapi::GameOrdinalLocator(::d2::DefaultLibrary::kStorm, 266)) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_CLASSIC_1_14A {::mapi::GameAddressTableEntry( \
    ::std::tuple( \
        static_cast<::d2::DefaultLibrary>(-1), \
        "" \
    ), \
    ::mapi::GameAddressLocator( \
        ::mapi::GameOffsetLocator( \
            static_cast<::d2::DefaultLibrary>(-1), \
            0 \
        ) \
    ) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_LOD_1_14A {::mapi::GameAddressTableEntry( \
    ::std::tuple( \
        static_cast<::d2::DefaultLibrary>(-1), \
        "" \
    ), \
    ::mapi::GameAddressLocator( \
        ::mapi::GameOffsetLocator( \
            static_cast<::d2::DefaultLibrary>(-1), \
            0 \
        ) \
    ) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_CLASSIC_1_14B {::mapi::GameAddressTableEntry( \
    ::std::tuple( \
        static_cast<::d2::DefaultLibrary>(-1), \
        "" \
    ), \
    ::mapi::GameAddressLocator( \
        ::mapi::GameOffsetLocator( \
            static_cast<::d2::DefaultLibrary>(-1), \
            0 \
        ) \
    ) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_LOD_1_14B {::mapi::GameAddressTableEntry( \
    ::std::tuple( \
        static_cast<::d2::DefaultLibrary>(-1), \
        "" \
    ), \
    ::mapi::GameAddressLocator( \
        ::mapi::GameOffsetLocator( \
            static_cast<::d2::DefaultLibrary>(-1), \
            0 \
        ) \
    ) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_CLASSIC_1_14C {::mapi::GameAddressTableEntry( \
    ::std::tuple( \
        static_cast<::d2::DefaultLibrary>(-1), \
        "" \
    ), \
    ::mapi::GameAddressLocator( \
        ::mapi::GameOffsetLocator( \
            static_cast<::d2::DefaultLibrary>(-1), \
            0 \
        ) \
    ) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_LOD_1_14C {\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kBNClient, "GatewayDomainName"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kBNClient, 0x478970)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kBNClient, "GatewayIpV4Address"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kBNClient, 0x478A70)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2CMP, "CloseCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2CMP, 0x200820)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2CMP, "GetCelFromCelContext"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2CMP, 0x200620)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "DifficultyLevel"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x397694)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "DrawCenteredUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xA3750)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GameType"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x397698)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralDisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x30FF4C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralDisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x30FF48)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralPlayAreaCameraShiftX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x39C29C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IngameMousePositionX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x39DB38)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IngameMousePositionY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x39DB34)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "InventoryArrangeMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x39C2A0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsAutomapOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x399870)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsGameMenuOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x39986C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsHelpScreenOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x3998CC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsNewSkillButtonPressed"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x3B7370)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsNewStatsButtonPressed"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x3B736C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "ScreenOpenMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x39C298)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "ScreenShiftX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x3998E0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "ScreenShiftY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x3998E4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalBeltRecord"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0x262F70)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalBeltSlotPosition"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0x262FD0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalEquipmentSlotLayout"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0x25E370)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalInventoryGridLayout"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0x25E2F0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalInventoryPosition"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0x25E280)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalBeltsTxt"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0x564480)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalInventoryTxt"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0x56447C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalInventoryTxtRecordsCount"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0x564478)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "BitBlockHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x3C01C4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "BitBlockWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x3C01C0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "CelDisplayLeft"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x478324)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "CelDisplayRight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x478328)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x4782DC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x4782E0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Direct3D, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Direct3D, 0x3C01C4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Direct3D, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Direct3D, 0x3C01C0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "BitBlockHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0x3C01C4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "BitBlockWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0x3C01C0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "CelDisplayLeft"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0x5810F0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "CelDisplayRight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0x5810F4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "DrawCelContext"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0xF3AA0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "DrawRectangle"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0xF3910)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "IsWindowedMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x3BFD3C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "ResolutionMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x3BFD40)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "VideoMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x3BFD38)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "WindowHandle"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x3BFD44)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Glide, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Glide, 0x3C01C4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Glide, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Glide, 0x3C01C0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "GetStringByIndex"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x121EE0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_AsciiToUnicode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x124450)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_UnicodeToUtf8"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x123940)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_Utf8ToUnicode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x123890)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcat"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x123C50)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcmp"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x123A40)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcpy"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x123D30)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strlen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x123D50)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strncat"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x123C90)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strncmp"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x123A90)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strncpy"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x123CE0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_tolower"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0xADD70)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_toupper"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x29E40)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "DrawUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0xFFB70)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetPopupUnicodeTextWidthAndHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0xFFD80)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetUnicodeTextDrawWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0xFF010)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetUnicodeTextNDrawWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0xFEFD0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "LoadCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0xF7F80)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "LoadMpq"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x114FF7)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "MainMenuMousePositionX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x3CC62C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "MainMenuMousePositionY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x3CC630)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "SetPopUpUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0xFFAD0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "SetUnicodeTextFont"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x100750)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "UnloadCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0xF80B0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "UnloadMpq"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x115071)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kFog, "AllocClientMemory"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kFog, 0x6B90)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kFog, "FreeClientMemory"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kFog, 0x6BD0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kStorm, "SFileCloseArchive"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kStorm, 0x15210)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kStorm, "SFileOpenArchive"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kStorm, 0x17200)) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_CLASSIC_1_14D {::mapi::GameAddressTableEntry( \
    ::std::tuple( \
        static_cast<::d2::DefaultLibrary>(-1), \
        "" \
    ), \
    ::mapi::GameAddressLocator( \
        ::mapi::GameOffsetLocator( \
            static_cast<::d2::DefaultLibrary>(-1), \
            0 \
        ) \
    ) \
),} 
#define MAPI_GAME_ADDRESS_TABLE_LOD_1_14D {\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kBNClient, "GatewayDomainName"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kBNClient, 0x4818E8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kBNClient, "GatewayIpV4Address"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kBNClient, 0x4819E8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2CMP, "CloseCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2CMP, 0x201A50)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2CMP, "GetCelFromCelContext"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2CMP, 0x201840)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "DifficultyLevel"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x3A060C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "DrawCenteredUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0xA7080)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GameType"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x3A0610)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralDisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x311470)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralDisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x31146C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "GeneralPlayAreaCameraShiftX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x3A5214)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IngameMousePositionX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x3A6AB0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IngameMousePositionY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x3A6AAC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "InventoryArrangeMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x3A5218)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsAutomapOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x3A27E8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsGameMenuOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x3A27E4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsHelpScreenOpen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x3A2844)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsNewSkillButtonPressed"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x3C02E8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "IsNewStatsButtonPressed"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x3C02E4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "ScreenOpenMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x3A5210)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "ScreenShiftX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x3A2858)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Client, "ScreenShiftY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Client, 0x3A285C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalBeltRecord"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0x260CB0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalBeltSlotPosition"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0x260D10)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalEquipmentSlotLayout"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0x25C270)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalInventoryGridLayout"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0x25C1F0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GetGlobalInventoryPosition"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0x25C180)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalBeltsTxt"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0x56D4F8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalInventoryTxt"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0x56D4F4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Common, "GlobalInventoryTxtRecordsCount"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Common, 0x56D4F0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "BitBlockHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x3C913C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "BitBlockWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x3C9138)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "CelDisplayLeft"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x48129C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "CelDisplayRight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x4812A0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x481254)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2DDraw, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2DDraw, 0x481258)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Direct3D, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Direct3D, 0x3C913C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Direct3D, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Direct3D, 0x3C9138)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "BitBlockHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0x3C913C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "BitBlockWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0x3C9138)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "CelDisplayLeft"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0x58A168)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GDI, "CelDisplayRight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GDI, 0x58A16C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "DrawCelContext"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0xF6480)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "DrawRectangle"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0xF6300)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "IsWindowedMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x3C8CB4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "ResolutionMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x3C8CB8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "VideoMode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x3C8CB0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2GFX, "WindowHandle"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2GFX, 0x3C8CBC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Glide, "DisplayHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Glide, 0x3C913C)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Glide, "DisplayWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Glide, 0x3C9138)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "GetStringByIndex"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x124A30)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_AsciiToUnicode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x126F20)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_UnicodeToUtf8"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1263E0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_Utf8ToUnicode"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x126320)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcat"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x126700)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcmp"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1264F0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strcpy"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x1267E0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strlen"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x126800)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strncat"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x126740)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strncmp"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x126540)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_strncpy"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x126790)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_tolower"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0xB15F3)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Lang, "Unicode_toupper"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Lang, 0x2E650)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "DrawUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x102320)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetPopupUnicodeTextWidthAndHeight"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x102520)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetUnicodeTextDrawWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x101820)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "GetUnicodeTextNDrawWidth"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x1017D0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "LoadCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0xFA9B0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "LoadMpq"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x117332)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "MainMenuMousePositionX"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x3D55A4)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "MainMenuMousePositionY"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x3D55A8)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "SetPopUpUnicodeText"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x102280)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "SetUnicodeTextFont"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x102EF0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "UnloadCelFile"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0xFAAE0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kD2Win, "UnloadMpq"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kD2Win, 0x1173AC)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kFog, "AllocClientMemory"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kFog, 0xB380)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kFog, "FreeClientMemory"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kFog, 0xB3C0)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kStorm, "SFileCloseArchive"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kStorm, 0x19A80)) \
),\
::mapi::GameAddressTableEntry( \
    ::std::tuple(::d2::DefaultLibrary::kStorm, "SFileOpenArchive"), \
    ::mapi::GameAddressLocator(::mapi::GameOffsetLocator(::d2::DefaultLibrary::kStorm, 0x1BA60)) \
),} 

#endif // SGD2MAPI_CXX_BACKEND_GAME_ADDRESS_TABLE_GAME_ADDRESS_TABLE_DEFINE_HPP_
