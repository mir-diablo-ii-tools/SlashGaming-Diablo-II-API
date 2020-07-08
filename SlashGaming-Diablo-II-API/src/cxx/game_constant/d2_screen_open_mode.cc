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

#include "../../../include/cxx/game_constant/d2_screen_open_mode.hpp"

#include <unordered_map>

namespace d2 {
namespace {

static const std::unordered_map<ScreenOpenMode, ScreenOpenMode_1_07> kTo1_07 = {
    { ScreenOpenMode::kNone, ScreenOpenMode_1_07::kNone },
    { ScreenOpenMode::kRight, ScreenOpenMode_1_07::kRight },
    { ScreenOpenMode::kLeft, ScreenOpenMode_1_07::kLeft },
    { ScreenOpenMode::kBoth, ScreenOpenMode_1_07::kBoth },
};

static const std::unordered_map<ScreenOpenMode_1_07, ScreenOpenMode> kFrom1_07 = {
    { ScreenOpenMode_1_07::kNone, ScreenOpenMode::kNone },
    { ScreenOpenMode_1_07::kRight, ScreenOpenMode::kRight },
    { ScreenOpenMode_1_07::kLeft, ScreenOpenMode::kLeft },
    { ScreenOpenMode_1_07::kBoth, ScreenOpenMode::kBoth },
};

} // namespace

int ToGameValue(ScreenOpenMode api_value) {
  return static_cast<int>(ToGameValue_1_07(api_value));
}

ScreenOpenMode_1_07 ToGameValue_1_07(ScreenOpenMode api_value) {
  return kTo1_07.at(api_value);
}

template <>
ScreenOpenMode ToApiValue<ScreenOpenMode>(int game_value) {
  return ToApiValue_1_07(static_cast<ScreenOpenMode_1_07>(game_value));
}

ScreenOpenMode ToApiValue_1_07(ScreenOpenMode_1_07 game_value) {
  return kFrom1_07.at(game_value);
}

} // namespace d2
