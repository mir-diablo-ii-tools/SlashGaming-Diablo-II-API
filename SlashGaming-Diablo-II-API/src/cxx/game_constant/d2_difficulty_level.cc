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

#include "../../../include/cxx/game_constant/d2_difficulty_level.hpp"

#include <mdc/error/exit_on_error.hpp>
#include <mdc/wchar_t/filew.h>

namespace d2::difficulty_level {

int ToGameValue(DifficultyLevel api_value) {
  return static_cast<int>(ToGameValue_1_00(api_value));
}

DifficultyLevel_1_00 ToGameValue_1_00(DifficultyLevel api_value) {
  switch (api_value) {
    case DifficultyLevel::kNormal: {
      return DifficultyLevel_1_00::kNormal;
    }

    case DifficultyLevel::kNightmare: {
      return DifficultyLevel_1_00::kNightmare;
    }

    case DifficultyLevel::kHell: {
      return DifficultyLevel_1_00::kHell;
    }

    default: {
      ::mdc::error::ExitOnConstantMappingError(
          __FILEW__,
          __LINE__,
          static_cast<int>(api_value)
      );

      return static_cast<DifficultyLevel_1_00>(-1);
    }
  }
}

DifficultyLevel ToApiValue(int game_value) {
  return ToApiValue_1_00(static_cast<DifficultyLevel_1_00>(game_value));
}

DifficultyLevel ToApiValue_1_00(DifficultyLevel_1_00 game_value) {
  switch (game_value) {
    case DifficultyLevel_1_00::kNormal: {
      return DifficultyLevel::kNormal;
    }

    case DifficultyLevel_1_00::kNightmare: {
      return DifficultyLevel::kNightmare;
    }

    case DifficultyLevel_1_00::kHell: {
      return DifficultyLevel::kHell;
    }

    default: {
      ::mdc::error::ExitOnConstantMappingError(
          __FILEW__,
          __LINE__,
          static_cast<int>(game_value)
      );

      return static_cast<DifficultyLevel>(-1);
    }
  }
}

} // namespace d2::difficulty_level
