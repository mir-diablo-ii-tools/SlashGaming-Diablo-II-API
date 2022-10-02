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

#include "../../../../include/cxx/game_struct/d2_cel_context/d2_cel_context_wrapper.hpp"

#include "../../../../include/cxx/game_function/d2cmp/d2cmp_get_cel_from_cel_context.hpp"
#include "../../../../include/cxx/game_function/d2gfx/d2gfx_draw_cel_context.hpp"
#include "../../../../include/cxx/game_struct/d2_cel/d2_cel_view.hpp"
#include "../../../../include/cxx/game_version.hpp"

namespace d2 {

CelContext_Wrapper::CelContext_Wrapper(
    CelContext* cel_context
) noexcept : cel_context_(CreateVariant(cel_context)) {
}

bool CelContext_Wrapper::DrawFrame(int position_x, int position_y) {
  DrawCelFileFrameOptions frame_options;
  frame_options.color = mapi::Rgba32BitColor();
  frame_options.draw_effect = DrawEffect::kNone;
  frame_options.position_x_behavior = DrawPositionXBehavior::kLeft;
  frame_options.position_y_behavior = DrawPositionYBehavior::kBottom;

  return this->DrawFrame(
      position_x,
      position_y,
      frame_options
  );
}

bool CelContext_Wrapper::DrawFrame(
    int position_x,
    int position_y,
    const DrawCelFileFrameOptions& frame_options
) {
  Cel_View cel_view(this->GetCel());

  // Adjust the position_x to match the desired option.
  int actual_position_x = position_x;

  switch (frame_options.position_x_behavior) {
    case DrawPositionXBehavior::kLeft: {
      break;
    }

    case DrawPositionXBehavior::kCenter: {
      actual_position_x -= (cel_view.GetWidth() / 2);
      break;
    }

    case DrawPositionXBehavior::kRight: {
      actual_position_x -= cel_view.GetWidth();
      break;
    }
  }

  // Adjust the position_y to match the desired option.
  int actual_position_y = position_y;

  switch (frame_options.position_y_behavior) {
    case DrawPositionYBehavior::kTop: {
      actual_position_y += cel_view.GetHeight();
      break;
    }

    case DrawPositionYBehavior::kCenter: {
      actual_position_y += (cel_view.GetHeight() / 2);
      break;
    }

    case DrawPositionYBehavior::kBottom: {
      break;
    }
  }

  return d2gfx::DrawCelContext(
      this->Get(),
      actual_position_x,
      actual_position_y,
      frame_options.color.ToBgra(),
      frame_options.draw_effect,
      nullptr
  );
}

Cel* CelContext_Wrapper::GetCel() {
  return d2::d2cmp::GetCelFromCelContext(this->Get());
}

CelContext_Wrapper::WrapperVariant CelContext_Wrapper::CreateVariant(
    CelContext* cel_context
) {
  GameVersion running_game_version = ::d2::game_version::GetRunning();

  if (running_game_version <= GameVersion::k1_10) {
    return reinterpret_cast<CelContext_1_00*>(cel_context);
  } else if (running_game_version == GameVersion::k1_12A) {
    return reinterpret_cast<CelContext_1_12A*>(cel_context);
  } else /* if (running_game_version >= GameVersion::k1_13ABeta) */ {
    return reinterpret_cast<CelContext_1_13C*>(cel_context);
  }
}

} // namespace d2
