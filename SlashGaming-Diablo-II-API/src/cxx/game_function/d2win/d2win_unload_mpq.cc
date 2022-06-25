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

/**
 * Latest supported version: 1.14D
 */

#include "../../../../include/cxx/game_function/d2win/d2win_unload_mpq.hpp"

#include "../../../../include/cxx/default_game_library.hpp"
#include "../../../../include/cxx/game_version.hpp"
#include "../../../asm_x86_macro.h"
#include "../../backend/game_address_table.hpp"
#include "../../backend/game_function/esi_function.hpp"
#include "../../backend/game_function/fastcall_function.hpp"

namespace d2::d2win {
namespace {

static const mapi::GameAddress& GetGameAddress() {
  static const mapi::GameAddress game_address = mapi::LoadGameAddress(
      ::d2::DefaultLibrary::kD2Win,
      "UnloadMpq"
  );

  return game_address;
}

} // namespace

void UnloadMpq(
    MpqArchiveHandle* mpq_archive_handle
) {
  UnloadMpq_1_00(
      reinterpret_cast<MpqArchiveHandle_1_00*>(mpq_archive_handle)
  );
}

void UnloadMpq_1_00(MpqArchiveHandle_1_00* mpq_archive_handle) {
  GameVersion running_game_version = ::d2::game_version::GetRunning();

  if (running_game_version <= GameVersion::k1_10
      || running_game_version >= GameVersion::kClassic1_14A) {
    mapi::CallFastcallFunction(
        GetGameAddress().raw_address(),
        mpq_archive_handle
    );
  } else if (running_game_version >= GameVersion::k1_11
      && running_game_version <= GameVersion::k1_13D) {
    mapi::CallEsiFunction(
        GetGameAddress().raw_address(),
        mpq_archive_handle
    );
  }
}

} // namespace d2::d2win
