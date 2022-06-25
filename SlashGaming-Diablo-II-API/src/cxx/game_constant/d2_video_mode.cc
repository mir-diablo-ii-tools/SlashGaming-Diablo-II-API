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

/**
 * Latest supported version: 1.14D
 */

#include "../../../include/cxx/game_constant/d2_video_mode.hpp"

#include <cstdint>

#include <mdc/error/exit_on_error.hpp>
#include <mdc/wchar_t/filew.h>

namespace d2::video_mode {

int ToGameValue(VideoMode api_value) {
  return static_cast<int>(ToGameValue_1_00(api_value));
}

VideoMode_1_00 ToGameValue_1_00(VideoMode api_value) {
  switch (api_value) {
    case VideoMode::kGdi: {
      return VideoMode_1_00::kGdi;
    }

    case VideoMode::kSoftware: {
      return VideoMode_1_00::kSoftware;
    }

    case VideoMode::kDirectDraw: {
      return VideoMode_1_00::kDirectDraw;
    }

    case VideoMode::kGlide: {
      return VideoMode_1_00::kGlide;
    }

    case VideoMode::kOpenGl: {
      return VideoMode_1_00::kOpenGl;
    }

    case VideoMode::kDirect3D: {
      return VideoMode_1_00::kDirect3D;
    }

    case VideoMode::kRave: {
      return VideoMode_1_00::kRave;
    }

    default: {
      ::mdc::error::ExitOnConstantMappingError(
          __FILEW__,
          __LINE__,
          static_cast<int>(api_value)
      );

      return static_cast<VideoMode_1_00>(-1);
    }
  }
}

VideoMode ToApiValue(int game_value) {
  return ToApiValue_1_00(static_cast<VideoMode_1_00>(game_value));
}

VideoMode ToApiValue_1_00(VideoMode_1_00 game_value) {
  switch (game_value) {
    case VideoMode_1_00::kGdi: {
      return VideoMode::kGdi;
    }

    case VideoMode_1_00::kSoftware: {
      return VideoMode::kSoftware;
    }

    case VideoMode_1_00::kDirectDraw: {
      return VideoMode::kDirectDraw;
    }

    case VideoMode_1_00::kGlide: {
      return VideoMode::kGlide;
    }

    case VideoMode_1_00::kOpenGl: {
      return VideoMode::kOpenGl;
    }

    case VideoMode_1_00::kDirect3D: {
      return VideoMode::kDirect3D;
    }

    case VideoMode_1_00::kRave: {
      return VideoMode::kRave;
    }

    default: {
      ::mdc::error::ExitOnConstantMappingError(
          __FILEW__,
          __LINE__,
          static_cast<int>(game_value)
      );

      return static_cast<VideoMode>(-1);
    }
  }
}

} // namespace d2::video_mode
