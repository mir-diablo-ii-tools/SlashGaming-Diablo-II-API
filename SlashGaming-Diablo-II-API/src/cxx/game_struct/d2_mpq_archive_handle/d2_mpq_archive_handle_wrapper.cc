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

#include "../../../../include/cxx/game_struct/d2_mpq_archive_handle/d2_mpq_archive_handle_wrapper.hpp"

#include "d2_mpq_archive_handle_impl.hpp"

namespace d2 {

MPQArchiveHandle_Wrapper::MPQArchiveHandle_Wrapper(
    MPQArchiveHandle* ptr
) noexcept :
    ptr_(ptr) {
}

MPQArchiveHandle_Wrapper::MPQArchiveHandle_Wrapper(
    const MPQArchiveHandle_Wrapper& other
) noexcept = default;

MPQArchiveHandle_Wrapper::MPQArchiveHandle_Wrapper(
    MPQArchiveHandle_Wrapper&& other
) noexcept = default;

MPQArchiveHandle_Wrapper::~MPQArchiveHandle_Wrapper() noexcept = default;

MPQArchiveHandle_Wrapper& MPQArchiveHandle_Wrapper::operator=(
    const MPQArchiveHandle_Wrapper& other
) noexcept = default;

MPQArchiveHandle_Wrapper& MPQArchiveHandle_Wrapper::operator=(
    MPQArchiveHandle_Wrapper&& other
) noexcept = default;

MPQArchiveHandle_Wrapper::operator MPQArchiveHandle_View() const noexcept {
  return MPQArchiveHandle_View(this->Get());
}

MPQArchiveHandle* MPQArchiveHandle_Wrapper::Get() noexcept {
  const auto* const_this = this;

  return const_cast<MPQArchiveHandle*>(const_this->Get());
}

const MPQArchiveHandle* MPQArchiveHandle_Wrapper::Get() const noexcept {
  return this->ptr_;
}

MPQArchive* MPQArchiveHandle_Wrapper::GetMPQArchive() noexcept {
  const auto* const_this = this;

  return const_cast<MPQArchive*>(const_this->GetMPQArchive());
}

const MPQArchive* MPQArchiveHandle_Wrapper::GetMPQArchive() const noexcept {
  MPQArchiveHandle_View view(*this);

  return view.GetMPQArchive();
}

void MPQArchiveHandle_Wrapper::SetMPQArchive(
    MPQArchive* mpq_archive
) noexcept {
  auto* actual_mpq_archive_handle = reinterpret_cast<MPQArchiveHandle_1_00*>(
      this->Get()
  );

  auto* actual_mpq_archive = reinterpret_cast<MPQArchive_1_00*>(mpq_archive);

  actual_mpq_archive_handle->mpq_archive = actual_mpq_archive;
}

char* MPQArchiveHandle_Wrapper::GetMPQArchivePath() noexcept {
  const auto* const_this = this;

  return const_cast<char*>(const_this->GetMPQArchivePath());
}

const char* MPQArchiveHandle_Wrapper::GetMPQArchivePath() const noexcept {
  MPQArchiveHandle_View view(*this);

  return view.GetMPQArchivePath();
}

} // namespace d2
