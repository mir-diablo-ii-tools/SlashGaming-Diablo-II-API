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

#include "../../../../include/cxx/game_struct/d2_cel_file.hpp"

#include "d2_cel_file_impl.hpp"

namespace d2 {

CelFile_ConstWrapper::CelFile_ConstWrapper(
    const CelFile* ptr
) noexcept :
    ptr_(ptr) {
}

CelFile_ConstWrapper::CelFile_ConstWrapper(
    const CelFile_ConstWrapper& other
) = default;

CelFile_ConstWrapper::CelFile_ConstWrapper(
    CelFile_ConstWrapper&& other
) noexcept = default;

CelFile_ConstWrapper::~CelFile_ConstWrapper() = default;

CelFile_ConstWrapper& CelFile_ConstWrapper::operator=(
    const CelFile_ConstWrapper& other
) = default;

CelFile_ConstWrapper& CelFile_ConstWrapper::operator=(
    CelFile_ConstWrapper&& other
) noexcept = default;

const CelFile* CelFile_ConstWrapper::Get() const noexcept {
  return this->ptr_;
}

unsigned int CelFile_ConstWrapper::GetVersion() const noexcept {
  auto actual_cel_file = reinterpret_cast<const CelFile_1_00*>(this->Get());

  return actual_cel_file->version;
}

unsigned int CelFile_ConstWrapper::GetNumDirections() const noexcept {
  auto actual_cel_file = reinterpret_cast<const CelFile_1_00*>(this->Get());

  return actual_cel_file->num_directions;
}

unsigned int CelFile_ConstWrapper::GetNumFrames() const noexcept {
  auto actual_cel_file = reinterpret_cast<const CelFile_1_00*>(this->Get());

  return actual_cel_file->num_frames;
}

} // namespace d2
