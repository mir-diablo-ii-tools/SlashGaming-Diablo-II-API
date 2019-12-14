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

#include "../../../../include/cxx/game_func/d2common/d2common_get_inventory_position.hpp"

#include <windows.h>
#include <cstdint>

#include "../../../asm_x86_macro.h"
#include "../../../cxx/game_address_table.hpp"
#include "../../../../include/cxx/game_version.hpp"

namespace d2::d2common {
namespace {

__declspec(naked) void __cdecl
D2Common_GetInventoryPosition_1_00(
    std::intptr_t func_ptr,
    std::uint32_t inventory_record_index,
    PositionalRectangle* out_position
) {
  ASM_X86(push ebp);
  ASM_X86(mov ebp, esp);

  ASM_X86(push eax);
  ASM_X86(push ecx);
  ASM_X86(push edx);

  ASM_X86(push dword ptr [ebp + 16]);
  ASM_X86(push dword ptr [ebp + 12]);
  ASM_X86(call dword ptr [ebp + 8]);

  ASM_X86(pop edx);
  ASM_X86(pop ecx);
  ASM_X86(pop eax);

  ASM_X86(leave);
  ASM_X86(ret);
}

__declspec(naked) void __cdecl
D2Common_GetInventoryPosition_1_09D(
    std::intptr_t func_ptr,
    std::uint32_t inventory_record_index,
    std::uint32_t inventory_arrange_mode,
    PositionalRectangle* out_position
) {
  ASM_X86(push ebp);
  ASM_X86(mov ebp, esp);

  ASM_X86(push eax);
  ASM_X86(push ecx);
  ASM_X86(push edx);

  ASM_X86(push dword ptr [ebp + 20]);
  ASM_X86(push dword ptr [ebp + 16]);
  ASM_X86(push dword ptr [ebp + 12]);
  ASM_X86(call dword ptr [ebp + 8]);

  ASM_X86(pop edx);
  ASM_X86(pop ecx);
  ASM_X86(pop eax);

  ASM_X86(leave);
  ASM_X86(ret);
}

std::intptr_t D2Common_GetInventoryPosition() {
  static std::intptr_t ptr = mapi::GetGameAddress(__func__)
      .raw_address();

  return ptr;
}

} // namespace

void GetInventoryPosition(
    unsigned int inventory_record_index,
    unsigned int inventory_arrange_mode,
    PositionalRectangle* out_position
) {
  std::intptr_t func_ptr = D2Common_GetInventoryPosition();

  GameVersion running_game_version = d2::GetRunningGameVersionId();
  if (running_game_version <= GameVersion::k1_06B) {
    D2Common_GetInventoryPosition_1_00(
        func_ptr,
        inventory_record_index,
        out_position
    );
  } else {
    D2Common_GetInventoryPosition_1_09D(
        func_ptr,
        inventory_record_index,
        inventory_arrange_mode,
        out_position
    );
  }
}

} // namespace d2::d2common
