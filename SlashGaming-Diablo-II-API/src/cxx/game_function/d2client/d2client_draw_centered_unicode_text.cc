/**
 * SlashGaming Diablo II Modding API for C++
 * Copyright (C) 2018-2020  Mir Drualga
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

/**
 * Latest supported version: 1.14D
 */

#include "../../../../include/cxx/game_function/d2client/d2client_draw_centered_unicode_text.hpp"

#include "../../../../include/cxx/game_version.hpp"
#include "../../../asm_x86_macro.h"
#include "../../backend/game_address_table.hpp"
#include "../../backend/game_library.hpp"

namespace d2::d2client {
namespace {

__declspec(naked) void __cdecl
D2Client_DrawCenteredUnicodeText_1_00(
    std::intptr_t func_ptr,
    std::int32_t left,
    std::int32_t position_y,
    const UnicodeChar* text,
    std::int32_t right,
    std::int32_t text_color
) {
  ASM_X86(push ebp);
  ASM_X86(mov ebp, esp);

  ASM_X86(push eax);
  ASM_X86(push ecx);
  ASM_X86(push edx);

  ASM_X86(push dword ptr [ebp + 28]);
  ASM_X86(push dword ptr [ebp + 24]);
  ASM_X86(push dword ptr [ebp + 20]);
  ASM_X86(mov edx, [ebp + 16]);
  ASM_X86(mov ecx, [ebp + 12]);
  ASM_X86(call dword ptr [ebp + 8]);

  ASM_X86(pop edx);
  ASM_X86(pop ecx);
  ASM_X86(pop eax);

  ASM_X86(leave);
  ASM_X86(ret);
}

__declspec(naked) static void __cdecl
D2Client_DrawCenteredUnicodeText_1_12A(
    std::intptr_t func_ptr,
    std::int32_t left,
    std::int32_t position_y,
    const UnicodeChar* text,
    std::int32_t right,
    std::int32_t text_color
) {
  ASM_X86(push ebp);
  ASM_X86(mov ebp, esp);

  ASM_X86(push eax);
  ASM_X86(push ecx);
  ASM_X86(push edx);
  ASM_X86(push ebx);

  ASM_X86(push dword ptr [ebp + 28]);
  ASM_X86(mov eax, [ebp + 24]);
  ASM_X86(mov ebx, [ebp + 20]);
  ASM_X86(push dword ptr [ebp + 16]);
  ASM_X86(mov ecx, [ebp + 12]);
  ASM_X86(call dword ptr [ebp + 8]);

  ASM_X86(pop ebx);
  ASM_X86(pop edx);
  ASM_X86(pop ecx);
  ASM_X86(pop eax);

  ASM_X86(leave);
  ASM_X86(ret);
}

std::intptr_t D2Client_DrawCenteredUnicodeText() {
  static std::intptr_t ptr = mapi::GetGameAddress(
      "D2Client.dll",
      "DrawCenteredUnicodeText"
  ).raw_address();

  return ptr;
}

} // namespace

void DrawCenteredUnicodeText(
    int left,
    int position_y,
    const UnicodeChar* text,
    int right,
    TextColor text_color
) {
  std::intptr_t func_ptr = D2Client_DrawCenteredUnicodeText();

  int text_color_game_value = ToGameValue(text_color);

  GameVersion running_game_version = GetRunningGameVersionId();

  if (running_game_version >= GameVersion::k1_11
      && running_game_version <= GameVersion::k1_13D) {
    D2Client_DrawCenteredUnicodeText_1_12A(
        func_ptr,
        left,
        position_y,
        text,
        right,
        text_color_game_value
    );
  } else {
    D2Client_DrawCenteredUnicodeText_1_00(
        func_ptr,
        left,
        position_y,
        text,
        right,
        text_color_game_value
    );
  }
}

} // namespace d2::d2client
