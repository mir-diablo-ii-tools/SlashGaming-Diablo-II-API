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

#include "../../../include/cxx/game_constant/d2_text_font.hpp"

#include <cstdint>
#include <unordered_map>

#include "../../../include/cxx/game_constant/d2_constant_template.hpp"

namespace d2 {
namespace {

static const std::unordered_map<TextFont, TextFont_1_00> kTo1_00 = {
    { TextFont::kDiabloMenu_24, TextFont_1_00::kDiabloMenu_24 },
    { TextFont::kDiabloMenu_30, TextFont_1_00::kDiabloMenu_30 },
    { TextFont::kDiabloMenu_42, TextFont_1_00::kDiabloMenu_42 },

    { TextFont::kExocet_8, TextFont_1_00::kExocet_8 },
    { TextFont::kExocet_16, TextFont_1_00::kExocet_16 },

    { TextFont::kExocetBlack_9, TextFont_1_00::kExocetBlack_9 },
    { TextFont::kExocetBlack_10, TextFont_1_00::kExocetBlack_10 },

    { TextFont::kFormal_6, TextFont_1_00::kFormal_6 },
    { TextFont::kFormal_8, TextFont_1_00::kFormal_8 },
    { TextFont::kFormal_10, TextFont_1_00::kFormal_10 },
    { TextFont::kFormal_11, TextFont_1_00::kFormal_11 },
    { TextFont::kFormal_12, TextFont_1_00::kFormal_12 },

    { TextFont::kFormalWide_11, TextFont_1_00::kFormalWide_11 },
};

static const std::unordered_map<TextFont_1_00, TextFont> kFrom1_00 = {
    { TextFont_1_00::kDiabloMenu_24, TextFont::kDiabloMenu_24 },
    { TextFont_1_00::kDiabloMenu_30, TextFont::kDiabloMenu_30 },
    { TextFont_1_00::kDiabloMenu_42, TextFont::kDiabloMenu_42 },

    { TextFont_1_00::kExocet_8, TextFont::kExocet_8 },
    { TextFont_1_00::kExocet_16, TextFont::kExocet_16 },

    { TextFont_1_00::kExocetBlack_9, TextFont::kExocetBlack_9 },
    { TextFont_1_00::kExocetBlack_10, TextFont::kExocetBlack_10 },

    { TextFont_1_00::kFormal_6, TextFont::kFormal_6 },
    { static_cast<TextFont_1_00>(12), TextFont::kFormal_6 },
    { TextFont_1_00::kFormal_8, TextFont::kFormal_8 },
    { TextFont_1_00::kFormal_10, TextFont::kFormal_10 },
    { TextFont_1_00::kFormal_11, TextFont::kFormal_11 },
    { TextFont_1_00::kFormal_12, TextFont::kFormal_12 },

    { TextFont_1_00::kFormalWide_11, TextFont::kFormalWide_11 },
};

} // namespace

int ToGameValue(TextFont api_value) {
  return static_cast<int>(ToGameValue_1_00(api_value));
}

TextFont_1_00 ToGameValue_1_00(TextFont api_value) {
  return kTo1_00.at(api_value);
}

template <>
TextFont ToApiValue<TextFont>(int game_value) {
  return ToApiValue_1_00(static_cast<TextFont_1_00>(game_value));
}

TextFont ToApiValue_1_00(TextFont_1_00 game_value) {
  return kFrom1_00.at(game_value);
}

} // namespace d2
