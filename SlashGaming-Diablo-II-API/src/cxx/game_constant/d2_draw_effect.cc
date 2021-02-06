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

#include "../../../include/cxx/game_constant/d2_draw_effect.hpp"

#include <cassert>

namespace d2 {

int ToGameValue(DrawEffect api_value) {
  return static_cast<int>(ToGameValue_1_00(api_value));
}

DrawEffect_1_00 ToGameValue_1_00(DrawEffect api_value) {
  switch (api_value) {
    case DrawEffect::kOneFourthOpaque: {
      return DrawEffect_1_00::kOneFourthOpaque;
    }

    case DrawEffect::kHalfOpaque: {
      return DrawEffect_1_00::kHalfOpaque;
    }

    case DrawEffect::kThreeFourthsOpaque: {
      return DrawEffect_1_00::kThreeFourthsOpaque;
    }

    case DrawEffect::kUnknown03: {
      return DrawEffect_1_00::kUnknown03;
    }

    case DrawEffect::kUnknown04: {
      return DrawEffect_1_00::kUnknown04;
    }

    case DrawEffect::kNone: {
      return DrawEffect_1_00::kNone;
    }

    case DrawEffect::kUnknown06: {
      return DrawEffect_1_00::kUnknown06;
    }

    case DrawEffect::kUnknown07: {
      return DrawEffect_1_00::kUnknown07;
    }

    default: {
      assert(false);
      return static_cast<DrawEffect_1_00>(-1);
    }
  }
}

template <>
DrawEffect ToApiValue<DrawEffect>(int game_value) {
  return ToApiValue_1_00(static_cast<DrawEffect_1_00>(game_value));
}

DrawEffect ToApiValue_1_00(DrawEffect_1_00 game_value) {
  switch (game_value) {
    case DrawEffect_1_00::kOneFourthOpaque: {
      return DrawEffect::kOneFourthOpaque;
    }

    case DrawEffect_1_00::kHalfOpaque: {
      return DrawEffect::kHalfOpaque;
    }

    case DrawEffect_1_00::kThreeFourthsOpaque: {
      return DrawEffect::kThreeFourthsOpaque;
    }

    case DrawEffect_1_00::kUnknown03: {
      return DrawEffect::kUnknown03;
    }

    case DrawEffect_1_00::kUnknown04: {
      return DrawEffect::kUnknown04;
    }

    case DrawEffect_1_00::kNone: {
      return DrawEffect::kNone;
    }

    case DrawEffect_1_00::kUnknown06: {
      return DrawEffect::kUnknown06;
    }

    case DrawEffect_1_00::kUnknown07: {
      return DrawEffect::kUnknown07;
    }

    default: {
      assert(false);
      return static_cast<DrawEffect>(-1);
    }
  }
}

} // namespace d2
