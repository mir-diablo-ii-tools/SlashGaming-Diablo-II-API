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

#include "../../../../include/cxx/game_struct/d2_mpq_archive_handle/d2_mpq_archive_handle_api.hpp"

#include "../../../../include/cxx/game_function/d2win_function.hpp"
#include "../../../../include/cxx/game_version.hpp"

namespace d2 {

MpqArchiveHandle_Api::MpqArchiveHandle_Api() :
    mpq_archive_handle_(nullptr),
    is_open_(false) {
}

MpqArchiveHandle_Api::MpqArchiveHandle_Api(
    std::string_view mpq_archive_path,
    bool is_set_error_on_drive_query_fail,
    int priority
) : MpqArchiveHandle_Api(
        mpq_archive_path,
        is_set_error_on_drive_query_fail,
        nullptr,
        priority
    ) {
}

MpqArchiveHandle_Api::MpqArchiveHandle_Api(
    std::string_view mpq_archive_path,
    bool is_set_error_on_drive_query_fail,
    void* (*on_fail_callback)(),
    int priority
) : mpq_archive_handle_(nullptr),
    is_open_(false) {
  this->Open(
      mpq_archive_path,
      is_set_error_on_drive_query_fail,
      on_fail_callback,
      priority
  );
}

MpqArchiveHandle_Api::MpqArchiveHandle_Api(
    MpqArchiveHandle_Api&& other
) noexcept :
    mpq_archive_handle_(std::move(other.mpq_archive_handle_)),
    is_open_(std::move(other.is_open_)) {
  other.mpq_archive_handle_ = nullptr;
  other.is_open_ = false;
}

MpqArchiveHandle_Api::~MpqArchiveHandle_Api() {
  this->Close();
}

MpqArchiveHandle_Api& MpqArchiveHandle_Api::operator=(
    MpqArchiveHandle_Api&& other
) noexcept {
  this->mpq_archive_handle_ = std::move(other.mpq_archive_handle_);
  this->is_open_ = std::move(other.is_open_);

  other.mpq_archive_handle_ = nullptr;
  other.is_open_ = false;

  return *this;
}

MpqArchiveHandle_Api::operator MpqArchiveHandle_View() const noexcept {
  return MpqArchiveHandle_View(this->Get());
}

MpqArchiveHandle* MpqArchiveHandle_Api::Get() noexcept {
  const auto* const_this = this;

  return const_cast<MpqArchiveHandle*>(const_this->Get());
}

const MpqArchiveHandle* MpqArchiveHandle_Api::Get() const noexcept {
  return std::visit(
      [](const auto& actual_mpq_archive_handle) {
        return reinterpret_cast<const MpqArchiveHandle*>(
            actual_mpq_archive_handle
        );
      },
      this->mpq_archive_handle_
  );
}

void MpqArchiveHandle_Api::Close() {
  if (!this->IsOpen()) {
    return;
  }

  d2win::UnloadMpq(this->Get());
  this->mpq_archive_handle_ = nullptr;
  this->is_open_ = false;
}

bool MpqArchiveHandle_Api::IsOpen() const {
  return this->is_open_;
}

void MpqArchiveHandle_Api::Open(
    std::string_view mpq_archive_path,
    bool is_set_error_on_drive_query_fail,
    int priority
) {
  this->Open(
      mpq_archive_path,
      is_set_error_on_drive_query_fail,
      nullptr,
      priority
  );
}

void MpqArchiveHandle_Api::Open(
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

  this->is_open_ = (this->Get() != nullptr);
}

MpqArchive_View MpqArchiveHandle_Api::GetMpqArchive() const noexcept {
  MpqArchiveHandle_View view(this->Get());

  return view.GetMpqArchive();
}

const char* MpqArchiveHandle_Api::GetMpqArchivePath() const noexcept {
  MpqArchiveHandle_View view(this->Get());

  return view.GetMpqArchivePath();
}

MpqArchiveHandle_Api::ApiVariant MpqArchiveHandle_Api::CreateVariant(
    std::string_view mpq_archive_path,
    bool is_set_error_on_drive_query_fail,
    void* (*on_fail_callback)(),
    int priority
) {
  MpqArchiveHandle* mpq_archive_handle = d2win::LoadMpq(
      mpq_archive_path.data(),
      is_set_error_on_drive_query_fail,
      on_fail_callback,
      priority
  );

  GameVersion running_game_version = ::d2::game_version::GetRunning();

  return reinterpret_cast<MpqArchiveHandle_1_00*>(mpq_archive_handle);
}

} // namespace d2
