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

#include "../../../../include/cxx/game_function/d2gfx/d2gfx_draw_cel_context.hpp"

#include "../../../../include/cxx/default_game_library.hpp"
#include "../../../../include/cxx/game_version.hpp"
#include "../../../asm_x86_macro.h"
#include "../../backend/game_address_table.hpp"
#include "../../backend/game_function/stdcall_function.hpp"

namespace d2::d2gfx {
namespace {

static const mapi::GameAddress& GetGameAdress() {
  static const mapi::GameAddress game_address = mapi::LoadGameAddress(
      ::mapi::DefaultLibrary::kD2GFX,
      "DrawCelContext"
  );

  return game_address;
}

} // namespace

bool DrawCelContext(
    CelContext* cel_context,
    int position_x,
    int position_y,
    unsigned int bgrt_color,
    DrawEffect draw_effect,
    mapi::Undefined* unknown_06__set_to_nullptr
) {
  GameVersion running_game_version = GetRunningGameVersionId();

  if (running_game_version <= GameVersion::k1_10) {
    return static_cast<bool>(
        DrawCelContext_1_00(
            reinterpret_cast<CelContext_1_00*>(cel_context),
            position_x,
            position_y,
            bgrt_color,
            ToGameValue_1_00(draw_effect),
            unknown_06__set_to_nullptr
        )
    );
  } else if (running_game_version == GameVersion::k1_12A) {
    return static_cast<bool>(
        DrawCelContext_1_12A(
            reinterpret_cast<CelContext_1_12A*>(cel_context),
            position_x,
            position_y,
            bgrt_color,
            ToGameValue_1_00(draw_effect),
            unknown_06__set_to_nullptr
        )
    );
  } else /* if (running_game_version >= GameVersion::k1_13ABeta) */ {
    return static_cast<bool>(
        DrawCelContext_1_13C(
            reinterpret_cast<CelContext_1_13C*>(cel_context),
            position_x,
            position_y,
            bgrt_color,
            ToGameValue_1_00(draw_effect),
            unknown_06__set_to_nullptr
        )
    );
  }
}

mapi::bool32 DrawCelContext_1_00(
    CelContext_1_00* cel_context,
    std::int32_t position_x,
    std::int32_t position_y,
    std::uint32_t bgrt_color,
    DrawEffect_1_00 draw_effect,
    mapi::Undefined* unknown_06__set_to_nullptr
) {
  return reinterpret_cast<mapi::bool32>(
      mapi::CallStdcallFunction(
          GetGameAdress().raw_address(),
          cel_context,
          position_x,
          position_y,
          bgrt_color,
          draw_effect,
          unknown_06__set_to_nullptr
      )
  );
}

mapi::bool32 DrawCelContext_1_12A(
    CelContext_1_12A* cel_context,
    std::int32_t position_x,
    std::int32_t position_y,
    std::uint32_t bgrt_color,
    DrawEffect_1_00 draw_effect,
    mapi::Undefined* unknown_06__set_to_nullptr
) {
  return reinterpret_cast<mapi::bool32>(
      mapi::CallStdcallFunction(
          GetGameAdress().raw_address(),
          cel_context,
          position_x,
          position_y,
          bgrt_color,
          draw_effect,
          unknown_06__set_to_nullptr
      )
  );
}

mapi::bool32 DrawCelContext_1_13C(
    CelContext_1_13C* cel_context,
    std::int32_t position_x,
    std::int32_t position_y,
    std::uint32_t bgrt_color,
    DrawEffect_1_00 draw_effect,
    mapi::Undefined* unknown_06__set_to_nullptr
) {
  return reinterpret_cast<mapi::bool32>(
      mapi::CallStdcallFunction(
          GetGameAdress().raw_address(),
          cel_context,
          position_x,
          position_y,
          bgrt_color,
          draw_effect,
          unknown_06__set_to_nullptr
      )
  );
}

} // namespace d2::d2gfx
