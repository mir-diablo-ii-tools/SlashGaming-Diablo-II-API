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

#include "../../../../include/cxx/game_struct/d2_mpq_archive_handle/d2_mpq_archive_handle_wrapper.hpp"

namespace d2 {

MpqArchiveHandle_Wrapper::MpqArchiveHandle_Wrapper(
    MpqArchiveHandle* mpq_archive_handle
) noexcept : mpq_archive_handle_(CreateVariant(mpq_archive_handle)) {
}

MpqArchiveHandle_Wrapper::MpqArchiveHandle_Wrapper(
    const MpqArchiveHandle_Wrapper& other
) noexcept = default;

MpqArchiveHandle_Wrapper::MpqArchiveHandle_Wrapper(
    MpqArchiveHandle_Wrapper&& other
) noexcept = default;

MpqArchiveHandle_Wrapper::~MpqArchiveHandle_Wrapper() noexcept = default;

MpqArchiveHandle_Wrapper& MpqArchiveHandle_Wrapper::operator=(
    const MpqArchiveHandle_Wrapper& other
) noexcept = default;

MpqArchiveHandle_Wrapper& MpqArchiveHandle_Wrapper::operator=(
    MpqArchiveHandle_Wrapper&& other
) noexcept = default;

MpqArchiveHandle_View MpqArchiveHandle_Wrapper::operator[](
    std::size_t index
) const noexcept {
  MpqArchiveHandle_View view(this->Get());

  return view[index];
}

MpqArchiveHandle_Wrapper MpqArchiveHandle_Wrapper::operator[](
    std::size_t index
) noexcept {
  const auto* const_this = this;

  return const_cast<MpqArchiveHandle*>((*const_this)[index].Get());
}

MpqArchiveHandle_Wrapper::operator MpqArchiveHandle_View() const noexcept {
  return MpqArchiveHandle_View(this->Get());
}

MpqArchiveHandle* MpqArchiveHandle_Wrapper::Get() noexcept {
  const auto* const_this = this;

  return const_cast<MpqArchiveHandle*>(const_this->Get());
}

const MpqArchiveHandle* MpqArchiveHandle_Wrapper::Get() const noexcept {
  return std::visit(
      [](auto& actual_mpq_archive_handle) {
        return reinterpret_cast<const MpqArchiveHandle*>(
            actual_mpq_archive_handle
        );
      },
      this->mpq_archive_handle_
  );
}

MpqArchive* MpqArchiveHandle_Wrapper::GetMpqArchive() noexcept {
  const auto* const_this = this;

  return const_cast<MpqArchive*>(const_this->GetMpqArchive());
}

const MpqArchive* MpqArchiveHandle_Wrapper::GetMpqArchive() const noexcept {
  MpqArchiveHandle_View view(this->Get());

  return view.GetMpqArchive();
}

void MpqArchiveHandle_Wrapper::SetMpqArchive(
    MpqArchive* mpq_archive
) noexcept {
  std::visit(
      [mpq_archive](auto& actual_mpq_archive_handle) {
        using MpqArchiveHandle_T = std::remove_pointer_t<
            std::remove_reference_t<decltype(actual_mpq_archive_handle)>
        >;
        using MpqArchive_T = std::remove_pointer_t<
            decltype(MpqArchiveHandle_T::mpq_archive)
        >;

        actual_mpq_archive_handle->mpq_archive =
            reinterpret_cast<MpqArchive_T*>(mpq_archive);
      },
      this->mpq_archive_handle_
  );
}

char* MpqArchiveHandle_Wrapper::GetMpqArchivePath() noexcept {
  const auto* const_this = this;

  return const_cast<char*>(const_this->GetMpqArchivePath());
}

const char* MpqArchiveHandle_Wrapper::GetMpqArchivePath() const noexcept {
  MpqArchiveHandle_View view(this->Get());

  return view.GetMpqArchivePath();
}

MpqArchiveHandle_Wrapper::WrapperVariant
MpqArchiveHandle_Wrapper::CreateVariant(
    MpqArchiveHandle* mpq_archive_handle
) {
  return reinterpret_cast<MpqArchiveHandle_1_00*>(mpq_archive_handle);
}

} // namespace d2
