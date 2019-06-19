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

#include "../../../../include/cxx/game_func/d2win/d2win_unload_mpq.hpp"

#include <cstdint>

#include "../../../asm_x86_macro.h"
#include "../../../cxx/game_address_table.hpp"
#include "../../../../include/cxx/game_struct/d2_mpq_archive_handle.hpp"
#include "../../../../include/cxx/game_func/fog_func.hpp"
#include "../../../../include/cxx/game_version.hpp"
#include "../../../../include/cxx/game_func/storm_func.hpp"

namespace d2::d2win {
namespace {

__declspec(naked) void __cdecl
D2Win_UnloadMPQ_1_00(
    std::intptr_t func_ptr,
    MPQArchiveHandle* mpq_archive_handle
) {
  ASM_X86(push ebp);
  ASM_X86(mov ebp, esp);

  ASM_X86(push ecx);
  ASM_X86(push edx);

  ASM_X86(mov ecx, [ebp + 12]);
  ASM_X86(call dword ptr [ebp + 8]);

  ASM_X86(pop edx);
  ASM_X86(pop ecx);

  ASM_X86(leave);
  ASM_X86(ret);
}

void D2Win_UnloadMPQ_1_11(MPQArchiveHandle* mpq_archive_handle) {
  MPQArchiveHandle_Wrapper mpq_archive_handle_wrapper(mpq_archive_handle);

  MPQArchive* mpq_archive = mpq_archive_handle_wrapper.GetMPQArchive();

  if (mpq_archive != nullptr) {
    storm::SFileCloseArchive(mpq_archive);
  }

  fog::FreeClientMemory(mpq_archive_handle, __FILE__, __LINE__, 0);
}

std::intptr_t D2Win_UnloadMPQ() {
  static std::intptr_t ptr = mapi::GetGameAddress(__func__)
      .raw_address();

  return ptr;
}

} // namespace

void UnloadMPQ(
    MPQArchiveHandle* mpq_archive_handle
) {
  std::intptr_t ptr = D2Win_UnloadMPQ();

  d2::GameVersion running_game_version = d2::GetRunningGameVersionId();

  if ((running_game_version >= d2::GameVersion::k1_00
      && running_game_version <= d2::GameVersion::k1_10)
      || (running_game_version >= d2::GameVersion::kClassic1_14A
        && running_game_version <= d2::GameVersion::kLod1_14D)) {
    D2Win_UnloadMPQ_1_00(
        ptr,
        mpq_archive_handle
    );
  } else if (running_game_version >= d2::GameVersion::k1_11
      && running_game_version <= d2::GameVersion::k1_13D) {
    D2Win_UnloadMPQ_1_11(mpq_archive_handle);
  }
}

} // namespace d2::d2win
