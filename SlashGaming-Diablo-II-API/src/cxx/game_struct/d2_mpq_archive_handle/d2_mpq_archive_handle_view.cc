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

#include "../../../../include/cxx/game_struct/d2_mpq_archive_handle/d2_mpq_archive_handle_view.hpp"

namespace d2 {

MpqArchiveHandle_View::MpqArchiveHandle_View(
    const MpqArchiveHandle* mpq_archive_handle
) noexcept : mpq_archive_handle_(CreateVariant(mpq_archive_handle)) {
}

MpqArchiveHandle_View::MpqArchiveHandle_View(
    const MpqArchiveHandle_View& other
) noexcept = default;

MpqArchiveHandle_View::MpqArchiveHandle_View(
    MpqArchiveHandle_View&& other
) noexcept = default;

MpqArchiveHandle_View::~MpqArchiveHandle_View() noexcept = default;

MpqArchiveHandle_View& MpqArchiveHandle_View::operator=(
    const MpqArchiveHandle_View& other
) noexcept = default;

MpqArchiveHandle_View& MpqArchiveHandle_View::operator=(
    MpqArchiveHandle_View&& other
) noexcept = default;

MpqArchiveHandle_View MpqArchiveHandle_View::operator[](
    std::size_t index
) const noexcept {
  return std::visit(
      [index](const auto& actual_mpq_archive_handle) {
        return reinterpret_cast<const MpqArchiveHandle*>(
            &actual_mpq_archive_handle[index]
        );
      },
      this->mpq_archive_handle_
  );
}

const MpqArchiveHandle*
MpqArchiveHandle_View::Get() const noexcept {
  return std::visit(
      [](const auto& actual_positional_rectangle) {
        return reinterpret_cast<const MpqArchiveHandle*>(
            actual_positional_rectangle
        );
      },
      this->mpq_archive_handle_
  );
}

const MpqArchive*
MpqArchiveHandle_View::GetMpqArchive() const noexcept {
  return std::visit(
      [](const auto& actual_mpq_archive_handle) {
        return reinterpret_cast<const MpqArchive*>(
            actual_mpq_archive_handle->mpq_archive
        );
      },
      this->mpq_archive_handle_
  );
}

const char*
MpqArchiveHandle_View::GetMpqArchivePath() const noexcept {
  return std::visit(
      [](const auto& actual_mpq_archive_handle) {
        return actual_mpq_archive_handle->mpq_archive_path;
      },
      this->mpq_archive_handle_
  );
}

MpqArchiveHandle_View::ViewVariant MpqArchiveHandle_View::CreateVariant(
    const MpqArchiveHandle* mpq_archive_handle
) {
  return reinterpret_cast<const MpqArchiveHandle_1_00*>(mpq_archive_handle);
}

} // namespace d2
