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

#include "../../../include/cxx/game_constant/d2_video_mode.hpp"

#include <cstdint>
#include <unordered_map>

#include "../../../include/cxx/game_constant/d2_constant_template.hpp"

namespace d2 {
namespace {

static const std::unordered_map<VideoMode, VideoMode_1_00> kTo1_00 = {
    { VideoMode::kGDI, VideoMode_1_00::kGDI },
    { VideoMode::kSoftware, VideoMode_1_00::kSoftware },
    { VideoMode::kDirectDraw, VideoMode_1_00::kDirectDraw },
    { VideoMode::kGlide, VideoMode_1_00::kGlide },
    { VideoMode::kOpenGL, VideoMode_1_00::kOpenGL },
    { VideoMode::kDirect3D, VideoMode_1_00::kDirect3D },
    { VideoMode::kRave, VideoMode_1_00::kRave },
};

static const std::unordered_map<VideoMode_1_00, VideoMode> kFrom1_00 = {
    { VideoMode_1_00::kGDI, VideoMode::kGDI },
    { VideoMode_1_00::kSoftware, VideoMode::kSoftware },
    { VideoMode_1_00::kDirectDraw, VideoMode::kDirectDraw },
    { VideoMode_1_00::kGlide, VideoMode::kGlide },
    { VideoMode_1_00::kOpenGL, VideoMode::kOpenGL },
    { VideoMode_1_00::kDirect3D, VideoMode::kDirect3D },
    { VideoMode_1_00::kRave, VideoMode::kRave },
};

} // namespace

int ToGameValue(VideoMode api_value) {
  return static_cast<int>(ToGameValue_1_00(api_value));
}

VideoMode_1_00 ToGameValue_1_00(VideoMode api_value) {
  return kTo1_00.at(api_value);
}

template <>
VideoMode ToApiValue<VideoMode>(int game_value) {
  return ToApiValue_1_00(static_cast<VideoMode_1_00>(game_value));
}

VideoMode ToApiValue_1_00(VideoMode_1_00 game_value) {
  return kFrom1_00.at(game_value);
}

} // namespace d2
