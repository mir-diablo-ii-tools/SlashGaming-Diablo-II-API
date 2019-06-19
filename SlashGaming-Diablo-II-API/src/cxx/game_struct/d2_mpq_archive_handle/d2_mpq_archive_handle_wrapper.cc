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

#include "../../../../include/cxx/game_struct/d2_mpq_archive_handle.hpp"

#include "d2_mpq_archive_handle_impl.hpp"

namespace d2 {

MPQArchiveHandle_Wrapper::MPQArchiveHandle_Wrapper(
    MPQArchiveHandle* ptr
) noexcept :
    MPQArchiveHandle_ConstWrapper(ptr),
    ptr_(ptr) {
}

MPQArchiveHandle_Wrapper::MPQArchiveHandle_Wrapper(
    const MPQArchiveHandle_Wrapper& other
) = default;

MPQArchiveHandle_Wrapper::MPQArchiveHandle_Wrapper(
    MPQArchiveHandle_Wrapper&& other
) noexcept = default;

MPQArchiveHandle_Wrapper::~MPQArchiveHandle_Wrapper() = default;

MPQArchiveHandle_Wrapper& MPQArchiveHandle_Wrapper::operator=(
    const MPQArchiveHandle_Wrapper& other
) = default;

MPQArchiveHandle_Wrapper& MPQArchiveHandle_Wrapper::operator=(
    MPQArchiveHandle_Wrapper&& other
) noexcept = default;

MPQArchiveHandle* MPQArchiveHandle_Wrapper::Get() noexcept {
  return this->ptr_;
}

MPQArchive* MPQArchiveHandle_Wrapper::GetMPQArchive() noexcept {
  auto actual_ptr = reinterpret_cast<MPQArchiveHandle_1_00*>(
      this->Get()
  );

  return reinterpret_cast<MPQArchive*>(actual_ptr->mpq_archive);
}

char* MPQArchiveHandle_Wrapper::GetMPQArchivePath() noexcept {
  auto actual_ptr = reinterpret_cast<MPQArchiveHandle_1_00*>(
      this->Get()
  );

  return actual_ptr->mpq_archive_path;
}

} // namespace d2
