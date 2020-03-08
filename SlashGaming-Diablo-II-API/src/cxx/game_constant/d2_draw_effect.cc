/**
 * SlashGaming Diablo II Modding API
 * Copyright (C) 2018-2019  Mir Drualga
 *
 * This file is part of SlashGaming Diablo II Modding API.
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

#include <unordered_map>

namespace d2 {
namespace {

static const std::unordered_map<DrawEffect, DrawEffect_1_00> kTo1_00 = {
    { DrawEffect::kOneFourthOpaque, DrawEffect_1_00::kOneFourthOpaque },
    { DrawEffect::kHalfOpaque, DrawEffect_1_00::kHalfOpaque },
    { DrawEffect::kThreeFourthsOpaque, DrawEffect_1_00::kThreeFourthsOpaque },
    { DrawEffect::kUnknown03, DrawEffect_1_00::kUnknown03 },
    { DrawEffect::kUnknown04, DrawEffect_1_00::kUnknown04 },
    { DrawEffect::kNone, DrawEffect_1_00::kNone },
    { DrawEffect::kUnknown06, DrawEffect_1_00::kUnknown06 },
    { DrawEffect::kUnknown07, DrawEffect_1_00::kUnknown07 },
};

static const std::unordered_map<DrawEffect_1_00, DrawEffect> kFrom1_00 = {
    { DrawEffect_1_00::kOneFourthOpaque, DrawEffect::kOneFourthOpaque },
    { DrawEffect_1_00::kHalfOpaque, DrawEffect::kHalfOpaque },
    { DrawEffect_1_00::kThreeFourthsOpaque, DrawEffect::kThreeFourthsOpaque },
    { DrawEffect_1_00::kUnknown03, DrawEffect::kUnknown03 },
    { DrawEffect_1_00::kUnknown04, DrawEffect::kUnknown04 },
    { DrawEffect_1_00::kNone, DrawEffect::kNone },
    { DrawEffect_1_00::kUnknown06, DrawEffect::kUnknown06 },
    { DrawEffect_1_00::kUnknown07, DrawEffect::kUnknown07 },
};

} // namespace

int ToGameValue(DrawEffect api_value) {
  return static_cast<int>(ToGameValue_1_00(api_value));
}

DrawEffect_1_00 ToGameValue_1_00(DrawEffect api_value) {
  return kTo1_00.at(api_value);
}

DrawEffect ToApiValue(int game_value) {
  return ToApiValue_1_00(static_cast<DrawEffect_1_00>(game_value));
}

DrawEffect ToApiValue_1_00(DrawEffect_1_00 game_value) {
  return kFrom1_00.at(game_value);
}

} // namespace d2
