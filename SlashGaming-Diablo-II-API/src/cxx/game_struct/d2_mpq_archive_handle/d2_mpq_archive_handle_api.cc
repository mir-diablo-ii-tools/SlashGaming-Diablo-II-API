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

#include "../../../../include/cxx/game_struct/d2_mpq_archive_handle/d2_mpq_archive_handle_api.hpp"

#include "d2_mpq_archive_handle_impl.hpp"
#include "../../../../include/cxx/game_func/d2win_func.hpp"
#include "../../../../include/cxx/game_version.hpp"

namespace d2 {
namespace {

using MPQArchiveHandleVariant = std::variant<
    MPQArchiveHandle_1_00*
>;

MPQArchiveHandleVariant CreateVariant(
    std::string_view mpq_archive_path,
    bool is_set_error_on_drive_query_fail,
    void* (*on_fail_callback)(),
    int priority
) {
  MPQArchiveHandle* mpq_archive_handle = d2win::LoadMPQ(
      mpq_archive_path.data(),
      is_set_error_on_drive_query_fail,
      on_fail_callback,
      priority
  );

  d2::GameVersion running_game_version = d2::GetRunningGameVersionId();

  return reinterpret_cast<MPQArchiveHandle_1_00*>(mpq_archive_handle);
}

} // namespace

MPQArchiveHandle_API::MPQArchiveHandle_API() :
    mpq_archive_handle_(nullptr),
    is_open_(false) {
}

MPQArchiveHandle_API::MPQArchiveHandle_API(
    std::string_view mpq_archive_path,
    bool is_set_error_on_drive_query_fail,
    int priority
) : MPQArchiveHandle_API(
        mpq_archive_path,
        is_set_error_on_drive_query_fail,
        nullptr,
        priority
    ) {
}

MPQArchiveHandle_API::MPQArchiveHandle_API(
    std::string_view mpq_archive_path,
    bool is_set_error_on_drive_query_fail,
    void* (*on_fail_callback)(),
    int priority
) {
  Open(
      mpq_archive_path,
      is_set_error_on_drive_query_fail,
      on_fail_callback,
      priority
  );
}

MPQArchiveHandle_API::MPQArchiveHandle_API(
    MPQArchiveHandle_API&& other
) noexcept = default;

MPQArchiveHandle_API::~MPQArchiveHandle_API() {
  Close();
}

MPQArchiveHandle_API& MPQArchiveHandle_API::operator=(
    MPQArchiveHandle_API&& other
) noexcept = default;

MPQArchiveHandle_API::operator MPQArchiveHandle_View() const noexcept {
  return MPQArchiveHandle_View(this->Get());
}

const MPQArchiveHandle* MPQArchiveHandle_API::Get() const noexcept {
  auto* mpq_archive_handle =
      std::get<MPQArchiveHandle_1_00*>(this->mpq_archive_handle_);

  return reinterpret_cast<const MPQArchiveHandle*>(mpq_archive_handle);
}

void MPQArchiveHandle_API::Close() {
  if (this->IsOpen()) {
    d2win::UnloadMPQ(const_cast<MPQArchiveHandle*>(this->Get()));
    this->is_open_ = false;
  }
}

bool MPQArchiveHandle_API::IsOpen() const {
  return this->is_open_;
}

void MPQArchiveHandle_API::Open(
    std::string_view mpq_archive_path,
    bool is_set_error_on_drive_query_fail,
    int priority
) {
  Open(
      mpq_archive_path,
      is_set_error_on_drive_query_fail,
      nullptr,
      priority
  );
}

void MPQArchiveHandle_API::Open(
    std::string_view mpq_archive_path,
    bool is_set_error_on_drive_query_fail,
    void* (*on_fail_callback)(),
    int priority
) {
  this->Close();

  this->mpq_archive_handle_ = CreateVariant(
      mpq_archive_path,
      is_set_error_on_drive_query_fail,
      on_fail_callback,
      priority
  );

  this->is_open_ = true;
}

const MPQArchive* MPQArchiveHandle_API::GetMPQArchive() const noexcept {
  MPQArchiveHandle_View view(*this);

  return view.GetMPQArchive();
}

const char* MPQArchiveHandle_API::GetMPQArchivePath() const noexcept {
  MPQArchiveHandle_View view(*this);

  return view.GetMPQArchivePath();
}

} // namespace d2
