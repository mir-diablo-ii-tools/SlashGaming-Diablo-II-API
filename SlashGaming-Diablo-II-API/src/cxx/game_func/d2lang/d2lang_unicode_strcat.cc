/**
 * SlashGaming Diablo II Modding API
 * Copyright (C) 2018-2019  Mir Drualga
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

#include "../../../../include/cxx/game_func/d2lang/d2lang_unicode_strcat.hpp"

#include <cstdint>

#include "../../../asm_x86_macro.h"
#include "../../../cxx/game_address_table.hpp"
#include "../../../../include/cxx/game_version.hpp"

namespace d2::d2lang {
namespace {

__declspec(naked) UnicodeChar* __cdecl
D2Lang_Unicode_strcat_1_00(
    std::intptr_t func_ptr,
    UnicodeChar* dest,
    const UnicodeChar* src
) {
  ASM_X86(push ebp);
  ASM_X86(mov ebp, esp);

  ASM_X86(push ecx);
  ASM_X86(push edx);

  ASM_X86(mov edx, dword ptr [ebp + 16]);
  ASM_X86(mov ecx, dword ptr [ebp + 12]);
  ASM_X86(call dword ptr [ebp + 8]);

  ASM_X86(pop edx);
  ASM_X86(pop ecx);

  ASM_X86(leave);
  ASM_X86(ret);
}

std::intptr_t D2Lang_Unicode_strcat() {
  static std::intptr_t ptr = mapi::GetGameAddress(__func__)
      .raw_address();

  return ptr;
}

} // namespace

UnicodeChar* Unicode_strcat(
    UnicodeChar* dest,
    const UnicodeChar* src
) {
  std::intptr_t ptr = D2Lang_Unicode_strcat();

  return D2Lang_Unicode_strcat_1_00(ptr, dest, src);
}

} // namespace d2::d2lang
