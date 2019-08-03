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

#include "../../../include/c/game_struct/d2_cel_file.h"

#include "../../../include/cxx/game_struct/d2_cel_file.hpp"

unsigned int D2_CelFile_GetVersion(const D2_CelFile* cel_file) {
  auto actual_cel_file = reinterpret_cast<const d2::CelFile*>(cel_file);

  d2::CelFile_ConstWrapper cel_file_wrapper(actual_cel_file);
  return cel_file_wrapper.version();
}

void D2_CelFile_SetVersion(D2_CelFile* cel_file, unsigned int value) {
  auto actual_cel_file = reinterpret_cast<d2::CelFile*>(cel_file);

  d2::CelFile_Wrapper cel_file_wrapper(actual_cel_file);
  cel_file_wrapper.version(value);
}

unsigned int D2_CelFile_GetNumDirections(const D2_CelFile* cel_file) {
  auto actual_cel_file = reinterpret_cast<const d2::CelFile*>(cel_file);

  d2::CelFile_ConstWrapper cel_file_wrapper(actual_cel_file);
  return cel_file_wrapper.num_directions();
}

void D2_CelFile_SetNumDirections(D2_CelFile* cel_file, unsigned int value) {
  auto actual_cel_file = reinterpret_cast<d2::CelFile*>(cel_file);

  d2::CelFile_Wrapper cel_file_wrapper(actual_cel_file);
  cel_file_wrapper.num_directions(value);
}

unsigned int D2_CelFile_GetNumFrames(const D2_CelFile* cel_file) {
  auto actual_cel_file = reinterpret_cast<const d2::CelFile*>(cel_file);

  d2::CelFile_ConstWrapper cel_file_wrapper(actual_cel_file);
  return cel_file_wrapper.num_frames();
}

void D2_CelFile_SetNumFrames(D2_CelFile* cel_file, unsigned int value) {
  auto actual_cel_file = reinterpret_cast<d2::CelFile*>(cel_file);

  d2::CelFile_Wrapper cel_file_wrapper(actual_cel_file);
  cel_file_wrapper.num_frames(value);
}
