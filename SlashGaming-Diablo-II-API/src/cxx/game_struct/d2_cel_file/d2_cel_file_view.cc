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

#include "../../../../include/cxx/game_struct/d2_cel_file/d2_cel_file_view.hpp"

namespace d2 {

CelFile_View::CelFile_View(
    const CelFile* cel_file
) noexcept :
    cel_file_(cel_file) {
}

CelFile_View::CelFile_View(
    const CelFile_View& other
) noexcept = default;

CelFile_View::CelFile_View(
    CelFile_View&& other
) noexcept = default;

CelFile_View::~CelFile_View() noexcept = default;

CelFile_View& CelFile_View::operator=(
    const CelFile_View& other
) noexcept = default;

CelFile_View& CelFile_View::operator=(
    CelFile_View&& other
) noexcept = default;

const CelFile* CelFile_View::Get() const noexcept {
  return this->cel_file_;
}

unsigned int CelFile_View::GetVersion() const noexcept {
  auto actual_cel_file = reinterpret_cast<const CelFile_1_00*>(this->Get());

  return actual_cel_file->version;
}

unsigned int CelFile_View::GetNumDirections() const noexcept {
  auto actual_cel_file = reinterpret_cast<const CelFile_1_00*>(this->Get());

  return actual_cel_file->num_directions;
}

unsigned int CelFile_View::GetNumFrames() const noexcept {
  auto actual_cel_file = reinterpret_cast<const CelFile_1_00*>(this->Get());

  return actual_cel_file->num_frames;
}

} // namespace d2
