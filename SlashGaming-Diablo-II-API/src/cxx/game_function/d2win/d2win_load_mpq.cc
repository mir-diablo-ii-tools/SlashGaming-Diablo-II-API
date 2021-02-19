/**
 * SlashGaming Diablo II Modding API for C++
 * Copyright (C) 2018-2021  Mir Drualga
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

#include "../../../../include/cxx/game_function/d2win/d2win_load_mpq.hpp"

#include "../../../../include/cxx/default_game_library.hpp"
#include "../../../../include/cxx/game_version.hpp"
#include "../../../asm_x86_macro.h"
#include "../../backend/game_address_table.hpp"
#include "../../backend/game_function/fastcall_function.hpp"

namespace d2::d2win {
namespace {

static const mapi::GameAddress& GetGameAddress() {
  static const mapi::GameAddress game_address = mapi::LoadGameAddress(
      ::d2::DefaultLibrary::kD2Win,
      "LoadMpq"
  );

  return game_address;
}

__declspec(naked) static MpqArchiveHandle_1_00* __cdecl
LoadMpq_1_11_Shim(
    std::intptr_t func_ptr,
    const char* dll_file_name,
    const char* mpq_file_name,
    const char* mpq_name,
    mapi::bool32 is_set_error_on_drive_query_fail,
    void* (*on_fail_callback)(void),
    std::int32_t priority
) {
  ASM_X86(push ebp);
  ASM_X86(mov ebp, esp);

  ASM_X86(push ecx);
  ASM_X86(push edx);

  ASM_X86(mov eax, dword ptr [ebp + 32])
  ASM_X86(push dword ptr [ebp + 28]);
  ASM_X86(push dword ptr [ebp + 24]);
  ASM_X86(push dword ptr [ebp + 20]);
  ASM_X86(push dword ptr [ebp + 16]);
  ASM_X86(push dword ptr [ebp + 12]);
  ASM_X86(call dword ptr [ebp + 8]);

  ASM_X86(pop edx);
  ASM_X86(pop ecx);

  ASM_X86(leave);
  ASM_X86(ret);
}

} // namespace

MpqArchiveHandle* LoadMpq(
    const char* mpq_file_name,
    bool is_set_err_on_drive_query_fail,
    void* (*on_fail_callback)(void),
    int priority
) {
  d2::GameVersion running_game_version = ::d2::game_version::GetRunning();

  if (running_game_version <= d2::GameVersion::k1_02) {
    return reinterpret_cast<MpqArchiveHandle*>(
        LoadMpq_1_00(
            "SGD2MAPI",
            mpq_file_name,
            "SGD2MAPI",
            nullptr,
            on_fail_callback
        )
    );
  } else if (running_game_version >= d2::GameVersion::k1_03
      && running_game_version <= d2::GameVersion::k1_06B) {
    return reinterpret_cast<MpqArchiveHandle*>(
        LoadMpq_1_03(
            "SGD2MAPI",
            mpq_file_name,
            "SGD2MAPI",
            nullptr,
            is_set_err_on_drive_query_fail,
            on_fail_callback
        )
    );
  } else if (running_game_version >= d2::GameVersion::k1_07
      && running_game_version <= d2::GameVersion::k1_10) {
    return reinterpret_cast<MpqArchiveHandle*>(
        LoadMpq_1_07(
            "SGD2MAPI",
            mpq_file_name,
            "SGD2MAPI",
            nullptr,
            is_set_err_on_drive_query_fail,
            on_fail_callback,
            priority
        )
    );
  } else if (running_game_version >= d2::GameVersion::k1_11
      && running_game_version <= d2::GameVersion::k1_13D) {
    return reinterpret_cast<MpqArchiveHandle*>(
        LoadMpq_1_11(
            "SGD2MAPI",
            mpq_file_name,
            "SGD2MAPI",
            is_set_err_on_drive_query_fail,
            on_fail_callback,
            priority
        )
    );
  } else /* if (running_game_version >= d2::GameVersion::kClassic1_14A) */ {
    return reinterpret_cast<MpqArchiveHandle*>(
        LoadMpq_1_14A(
            mpq_file_name,
            is_set_err_on_drive_query_fail,
            on_fail_callback,
            priority
        )
    );
  }
}

MpqArchiveHandle_1_00* LoadMpq_1_00(
    const char* dll_file_name,
    const char* mpq_file_name,
    const char* mpq_name,
    void* unused_04__set_to_nullptr,
    void* (*on_fail_callback)()
) {
  return reinterpret_cast<MpqArchiveHandle_1_00*>(
      mapi::CallFastcallFunction(
          GetGameAddress().raw_address(),
          dll_file_name,
          mpq_file_name,
          mpq_name,
          unused_04__set_to_nullptr,
          on_fail_callback
      )
  );
}

MpqArchiveHandle_1_00* LoadMpq_1_03(
    const char* dll_file_name,
    const char* mpq_file_name,
    const char* mpq_name,
    void* unused_04__set_to_nullptr,
    mapi::bool32 is_set_err_on_drive_query_fail,
    void* (*on_fail_callback)()
) {
  return reinterpret_cast<MpqArchiveHandle_1_00*>(
      mapi::CallFastcallFunction(
          GetGameAddress().raw_address(),
          dll_file_name,
          mpq_file_name,
          mpq_name,
          unused_04__set_to_nullptr,
          is_set_err_on_drive_query_fail,
          on_fail_callback
      )
  );
}

MpqArchiveHandle_1_00* LoadMpq_1_07(
    const char* dll_file_name,
    const char* mpq_file_name,
    const char* mpq_name,
    void* unused_04__set_to_nullptr,
    mapi::bool32 is_set_err_on_drive_query_fail,
    void* (*on_fail_callback)(),
    std::int32_t priority
) {
  return reinterpret_cast<MpqArchiveHandle_1_00*>(
      mapi::CallFastcallFunction(
          GetGameAddress().raw_address(),
          dll_file_name,
          mpq_file_name,
          mpq_name,
          unused_04__set_to_nullptr,
          is_set_err_on_drive_query_fail,
          on_fail_callback,
          priority
      )
  );
}

MpqArchiveHandle_1_00* LoadMpq_1_11(
    const char* dll_file_name,
    const char* mpq_file_name,
    const char* mpq_name,
    mapi::bool32 is_set_err_on_drive_query_fail,
    void* (*on_fail_callback)(),
    std::int32_t priority
) {
  return LoadMpq_1_11_Shim(
      GetGameAddress().raw_address(),
      dll_file_name,
      mpq_file_name,
      mpq_name,
      is_set_err_on_drive_query_fail,
      on_fail_callback,
      priority
  );
}

MpqArchiveHandle_1_00* LoadMpq_1_14A(
    const char* mpq_file_name,
    mapi::bool32 is_set_err_on_drive_query_fail,
    void* (*on_fail_callback)(),
    std::int32_t priority
) {
  return reinterpret_cast<MpqArchiveHandle_1_00*>(
      mapi::CallFastcallFunction(
          GetGameAddress().raw_address(),
          mpq_file_name,
          is_set_err_on_drive_query_fail,
          on_fail_callback,
          priority
      )
  );
}

} // namespace d2::d2win
