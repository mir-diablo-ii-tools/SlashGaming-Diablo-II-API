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

#include "../../../../include/cxx/game_function/d2cmp/d2cmp_get_cel_from_cel_context.hpp"

#include <cstdint>

#include "../../../../include/cxx/default_game_library.hpp"
#include "../../../../include/cxx/game_version.hpp"
#include "../../../asm_x86_macro.h"
#include "../../backend/game_address_table.hpp"
#include "../../backend/game_function/stdcall_function.hpp"

namespace d2::d2cmp {
namespace {

static const mapi::GameAddress& GetGameAddress() {
  static const mapi::GameAddress game_address = mapi::LoadGameAddress(
      ::d2::DefaultLibrary::kD2CMP,
      "GetCelFromCelContext"
  );

  return game_address;
}

} // namespace

Cel* GetCelFromCelContext(CelContext* cel_context) {
  GameVersion running_game_version = GetRunningGameVersionId();

  if (running_game_version <= GameVersion::k1_10) {
    auto* actual_cel_context = reinterpret_cast<CelContext_1_00*>(
        cel_context
    );

    return reinterpret_cast<Cel*>(
        GetCelFromCelContext_1_00(actual_cel_context)
    );
  } else if (running_game_version == GameVersion::k1_12A) {
    auto* actual_cel_context = reinterpret_cast<CelContext_1_12A*>(
        cel_context
    );

    return reinterpret_cast<Cel*>(
        GetCelFromCelContext_1_12A(actual_cel_context)
    );
  } else /* if (running_game_version >= GameVersion::k1_13C
      && running_game_version <= GameVersion::kLod1_14D) */ {
    auto* actual_cel_context = reinterpret_cast<CelContext_1_13C*>(
        cel_context
    );

    return reinterpret_cast<Cel*>(
        GetCelFromCelContext_1_13C(actual_cel_context)
    );
  }
}

Cel_1_00* GetCelFromCelContext_1_00(
    CelContext_1_00* cel_context
) {
  return reinterpret_cast<Cel_1_00*>(
      mapi::CallStdcallFunction(
          GetGameAddress().raw_address(),
          cel_context
      )
  );
}

Cel_1_00* GetCelFromCelContext_1_12A(
    CelContext_1_12A* cel_context
) {
  return reinterpret_cast<Cel_1_00*>(
      mapi::CallStdcallFunction(
          GetGameAddress().raw_address(),
          cel_context
      )
  );
}

Cel_1_00* GetCelFromCelContext_1_13C(
    CelContext_1_13C* cel_context
) {
  return reinterpret_cast<Cel_1_00*>(
      mapi::CallStdcallFunction(
          GetGameAddress().raw_address(),
          cel_context
      )
  );
}

} // namespace d2::d2cmp
