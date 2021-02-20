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

#include "../../../include/cxx/game_constant/d2_text_color.hpp"

#include <mdc/error/exit_on_error.hpp>
#include <mdc/wchar_t/filew.h>

namespace d2 {

int ToGameValue(TextColor api_value) {
  return static_cast<int>(ToGameValue_1_00(api_value));
}

TextColor_1_00 ToGameValue_1_00(TextColor api_value) {
  switch (api_value) {
    case TextColor::kWhite: {
      return TextColor_1_00::kWhite;
    }

    case TextColor::kRed: {
      return TextColor_1_00::kRed;
    }

    case TextColor::kGreen: {
      return TextColor_1_00::kGreen;
    }

    case TextColor::kBlue: {
      return TextColor_1_00::kBlue;
    }

    case TextColor::kGold: {
      return TextColor_1_00::kGold;
    }

    case TextColor::kDarkGrey: {
      return TextColor_1_00::kDarkGrey;
    }

    case TextColor::kBlack: {
      return TextColor_1_00::kBlack;
    }

    case TextColor::kTan: {
      return TextColor_1_00::kTan;
    }

    case TextColor::kOrange: {
      return TextColor_1_00::kOrange;
    }

    case TextColor::kYellow: {
      return TextColor_1_00::kYellow;
    }

    case TextColor::kDarkerGreen: {
      return TextColor_1_00::kDarkerGreen;
    }

    case TextColor::kPurple: {
      return TextColor_1_00::kPurple;
    }

    case TextColor::kDarkGreen: {
      return TextColor_1_00::kDarkGreen;
    }

    case TextColor::kMetallic: {
      return TextColor_1_00::kMetallic;
    }

    case TextColor::kLightGrey: {
      return TextColor_1_00::kLightGrey;
    }

    case TextColor::kCorrupt: {
      return TextColor_1_00::kCorrupt;
    }

    case TextColor::kBrightWhite: {
      return TextColor_1_00::kBrightWhite;
    }

    case TextColor::kDarkRed: {
      return TextColor_1_00::kDarkRed;
    }

    case TextColor::kBrown: {
      return TextColor_1_00::kBrown;
    }

    default: {
      ::mdc::error::ExitOnConstantMappingError(
          __FILEW__,
          __LINE__,
          static_cast<int>(api_value)
      );

      return static_cast<TextColor_1_00>(-1);
    }
  }
}

template <>
TextColor ToApiValue<TextColor>(int game_value) {
  return ToApiValue_1_00(static_cast<TextColor_1_00>(game_value));
}

TextColor ToApiValue_1_00(TextColor_1_00 game_value) {
  switch (game_value) {
    case TextColor_1_00::kWhite: {
      return TextColor::kWhite;
    }

    case TextColor_1_00::kRed: {
      return TextColor::kRed;
    }

    case TextColor_1_00::kGreen: {
      return TextColor::kGreen;
    }

    case TextColor_1_00::kBlue: {
      return TextColor::kBlue;
    }

    case TextColor_1_00::kGold: {
      return TextColor::kGold;
    }

    case TextColor_1_00::kDarkGrey: {
      return TextColor::kDarkGrey;
    }

    case TextColor_1_00::kBlack: {
      return TextColor::kBlack;
    }

    case TextColor_1_00::kTan: {
      return TextColor::kTan;
    }

    case TextColor_1_00::kOrange: {
      return TextColor::kOrange;
    }

    case TextColor_1_00::kYellow: {
      return TextColor::kYellow;
    }

    case TextColor_1_00::kDarkerGreen: {
      return TextColor::kDarkerGreen;
    }

    case TextColor_1_00::kPurple: {
      return TextColor::kPurple;
    }

    case TextColor_1_00::kDarkGreen: {
      return TextColor::kDarkGreen;
    }

    case TextColor_1_00::kMetallic: {
      return TextColor::kMetallic;
    }

    case TextColor_1_00::kLightGrey: {
      return TextColor::kLightGrey;
    }

    case TextColor_1_00::kCorrupt: {
      return TextColor::kCorrupt;
    }

    case TextColor_1_00::kBrightWhite: {
      return TextColor::kBrightWhite;
    }

    case TextColor_1_00::kDarkRed: {
      return TextColor::kDarkRed;
    }

    case TextColor_1_00::kBrown: {
      return TextColor::kBrown;
    }

    default: {
      ::mdc::error::ExitOnConstantMappingError(
          __FILEW__,
          __LINE__,
          static_cast<int>(game_value)
      );

      return static_cast<TextColor>(-1);
    }
  }
}

} // namespace d2
