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

#include "../../../include/cxx/game_constant/d2_text_color.hpp"

#include <unordered_map>

namespace d2 {
namespace {

static const std::unordered_map<TextColor, TextColor_1_00> kTo1_00 = {
    { TextColor::kWhite, TextColor_1_00::kWhite },
    { TextColor::kRed, TextColor_1_00::kRed },
    { TextColor::kGreen, TextColor_1_00::kGreen },
    { TextColor::kBlue, TextColor_1_00::kBlue },
    { TextColor::kGold, TextColor_1_00::kGold },
    { TextColor::kDarkGrey, TextColor_1_00::kDarkGrey },
    { TextColor::kBlack, TextColor_1_00::kBlack },
    { TextColor::kTan, TextColor_1_00::kTan },
    { TextColor::kOrange, TextColor_1_00::kOrange },
    { TextColor::kYellow, TextColor_1_00::kYellow },
    { TextColor::kDarkerGreen, TextColor_1_00::kDarkerGreen },
    { TextColor::kPurple, TextColor_1_00::kPurple },
    { TextColor::kDarkGreen, TextColor_1_00::kDarkGreen },
    { TextColor::kMetallic, TextColor_1_00::kMetallic },
    { TextColor::kLightGrey, TextColor_1_00::kLightGrey },
    { TextColor::kCorrupt, TextColor_1_00::kCorrupt },
    { TextColor::kBrightWhite, TextColor_1_00::kBrightWhite },
    { TextColor::kDarkRed, TextColor_1_00::kDarkRed },
    { TextColor::kBrown, TextColor_1_00::kBrown },
};

static const std::unordered_map<TextColor_1_00, TextColor> kFrom1_00 = {
    { TextColor_1_00::kWhite, TextColor::kWhite },
    { TextColor_1_00::kRed, TextColor::kRed },
    { TextColor_1_00::kGreen, TextColor::kGreen },
    { TextColor_1_00::kBlue, TextColor::kBlue },
    { TextColor_1_00::kGold, TextColor::kGold },
    { TextColor_1_00::kDarkGrey, TextColor::kDarkGrey },
    { TextColor_1_00::kBlack, TextColor::kBlack },
    { TextColor_1_00::kTan, TextColor::kTan },
    { TextColor_1_00::kOrange, TextColor::kOrange },
    { TextColor_1_00::kYellow, TextColor::kYellow },
    { TextColor_1_00::kDarkerGreen, TextColor::kDarkerGreen },
    { TextColor_1_00::kPurple, TextColor::kPurple },
    { TextColor_1_00::kDarkGreen, TextColor::kDarkGreen },
    { TextColor_1_00::kMetallic, TextColor::kMetallic },
    { TextColor_1_00::kLightGrey, TextColor::kLightGrey },
    { TextColor_1_00::kCorrupt, TextColor::kCorrupt },
    { TextColor_1_00::kBrightWhite, TextColor::kBrightWhite },
    { TextColor_1_00::kDarkRed, TextColor::kDarkRed },
    { TextColor_1_00::kBrown, TextColor::kBrown },
};

}

int ToGameValue(TextColor api_value) {
  return static_cast<int>(ToGameValue_1_00(api_value));
}

TextColor_1_00 ToGameValue_1_00(TextColor api_value) {
  return kTo1_00.at(api_value);
}

template <>
TextColor ToApiValue<TextColor>(int game_value) {
  return ToApiValue_1_00(static_cast<TextColor_1_00>(game_value));
}

TextColor ToApiValue_1_00(TextColor_1_00 game_value) {
  return kFrom1_00.at(game_value);
}

} // namespace d2
