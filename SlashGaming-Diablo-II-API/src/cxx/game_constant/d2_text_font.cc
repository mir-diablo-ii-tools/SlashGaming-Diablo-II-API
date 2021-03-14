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

#include "../../../include/cxx/game_constant/d2_text_font.hpp"

#include <cstdint>

#include <mdc/error/exit_on_error.hpp>
#include <mdc/wchar_t/filew.h>
#include "../../../include/cxx/game_constant/d2_constant_template.hpp"

namespace d2 {

int ToGameValue(TextFont api_value) {
  return static_cast<int>(ToGameValue_1_00(api_value));
}

TextFont_1_00 ToGameValue_1_00(TextFont api_value) {
  switch (api_value) {
    case TextFont::kDiabloMenu_24: {
      return TextFont_1_00::kDiabloMenu_24;
    }

    case TextFont::kDiabloMenu_30: {
      return TextFont_1_00::kDiabloMenu_30;
    }

    case TextFont::kDiabloMenu_42: {
      return TextFont_1_00::kDiabloMenu_42;
    }

    case TextFont::kExocet_8: {
      return TextFont_1_00::kExocet_8;
    }

    case TextFont::kExocet_16: {
      return TextFont_1_00::kExocet_16;
    }

    case TextFont::kExocetBlack_9: {
      return TextFont_1_00::kExocetBlack_9;
    }

    case TextFont::kExocetBlack_10: {
      return TextFont_1_00::kExocetBlack_10;
    }

    case TextFont::kFormal_6: {
      return TextFont_1_00::kFormal_6;
    }

    case TextFont::kFormal_8: {
      return TextFont_1_00::kFormal_8;
    }

    case TextFont::kFormal_10: {
      return TextFont_1_00::kFormal_10;
    }

    case TextFont::kFormal_11: {
      return TextFont_1_00::kFormal_11;
    }

    case TextFont::kFormal_12: {
      return TextFont_1_00::kFormal_12;
    }

    case TextFont::kFormalWide_11: {
      return TextFont_1_00::kFormalWide_11;
    }

    default: {
      ::mdc::error::ExitOnConstantMappingError(
          __FILEW__,
          __LINE__,
          static_cast<int>(api_value)
      );

      return static_cast<TextFont_1_00>(-1);
    }
  }
}

template <>
TextFont ToApiValue<TextFont>(int game_value) {
  return ToApiValue_1_00(static_cast<TextFont_1_00>(game_value));
}

TextFont ToApiValue_1_00(TextFont_1_00 game_value) {
  switch (game_value) {
    case TextFont_1_00::kDiabloMenu_24: {
      return TextFont::kDiabloMenu_24;
    }

    case TextFont_1_00::kDiabloMenu_30: {
      return TextFont::kDiabloMenu_30;
    }

    case TextFont_1_00::kDiabloMenu_42: {
      return TextFont::kDiabloMenu_42;
    }

    case TextFont_1_00::kExocet_8: {
      return TextFont::kExocet_8;
    }

    case TextFont_1_00::kExocet_16: {
      return TextFont::kExocet_16;
    }

    case TextFont_1_00::kExocetBlack_9: {
      return TextFont::kExocetBlack_9;
    }

    case TextFont_1_00::kExocetBlack_10: {
      return TextFont::kExocetBlack_10;
    }

    case TextFont_1_00::kFormal_6: {
      return TextFont::kFormal_6;
    }

    case static_cast<TextFont_1_00>(12): {
      return TextFont::kFormal_6;
    }

    case TextFont_1_00::kFormal_8: {
      return TextFont::kFormal_8;
    }

    case TextFont_1_00::kFormal_10: {
      return TextFont::kFormal_10;
    }

    case TextFont_1_00::kFormal_11: {
      return TextFont::kFormal_11;
    }

    case TextFont_1_00::kFormal_12: {
      return TextFont::kFormal_12;
    }

    case TextFont_1_00::kFormalWide_11: {
      return TextFont::kFormalWide_11;
    }

    default: {
      ::mdc::error::ExitOnConstantMappingError(
          __FILEW__,
          __LINE__,
          static_cast<int>(game_value)
      );

      return static_cast<TextFont>(-1);
    }
  }
}

} // namespace d2
