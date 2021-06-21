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

#include "../../../include/cxx/game_constant/d2_screen_open_mode.hpp"

#include <mdc/error/exit_on_error.hpp>
#include <mdc/wchar_t/filew.h>

namespace d2::screen_open_mode {

int ToGameValue(ScreenOpenMode api_value) {
  return static_cast<int>(ToGameValue_1_07(api_value));
}

ScreenOpenMode_1_07 ToGameValue_1_07(ScreenOpenMode api_value) {
  switch (api_value) {
    case ScreenOpenMode::kNone: {
      return ScreenOpenMode_1_07::kNone;
    }

    case ScreenOpenMode::kRight: {
      return ScreenOpenMode_1_07::kRight;
    }

    case ScreenOpenMode::kLeft: {
      return ScreenOpenMode_1_07::kLeft;
    }

    case ScreenOpenMode::kBoth: {
      return ScreenOpenMode_1_07::kBoth;
    }

    default: {
      ::mdc::error::ExitOnConstantMappingError(
          __FILEW__,
          __LINE__,
          static_cast<int>(api_value)
      );

      return static_cast<ScreenOpenMode_1_07>(-1);
    }
  }
}

ScreenOpenMode ToApiValue(int game_value) {
  return ToApiValue_1_07(static_cast<ScreenOpenMode_1_07>(game_value));
}

ScreenOpenMode ToApiValue_1_07(ScreenOpenMode_1_07 game_value) {
  switch (game_value) {
    case ScreenOpenMode_1_07::kNone: {
      return ScreenOpenMode::kNone;
    }

    case ScreenOpenMode_1_07::kRight: {
      return ScreenOpenMode::kRight;
    }

    case ScreenOpenMode_1_07::kLeft: {
      return ScreenOpenMode::kLeft;
    }

    case ScreenOpenMode_1_07::kBoth: {
      return ScreenOpenMode::kBoth;
    }

    default: {
      ::mdc::error::ExitOnConstantMappingError(
          __FILEW__,
          __LINE__,
          static_cast<int>(game_value)
      );

      return static_cast<ScreenOpenMode>(-1);
    }
  }
}

} // namespace d2::screen_open_mode
