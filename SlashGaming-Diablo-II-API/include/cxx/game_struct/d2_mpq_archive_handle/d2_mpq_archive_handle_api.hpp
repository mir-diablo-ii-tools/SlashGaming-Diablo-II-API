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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_MPQ_ARCHIVE_HANDLE_D2_MPQ_ARCHIVE_HANDLE_API_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_MPQ_ARCHIVE_HANDLE_D2_MPQ_ARCHIVE_HANDLE_API_HPP_

#include <string_view>
#include <variant>

#include "d2_mpq_archive_handle_struct.hpp"
#include "d2_mpq_archive_handle_view.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT MpqArchiveHandle_Api {
 public:
  MpqArchiveHandle_Api();

  MpqArchiveHandle_Api(
      std::string_view mpq_archive_path,
      bool is_set_error_on_drive_query_fail,
      int priority
  );

  MpqArchiveHandle_Api(
      std::string_view mpq_archive_path,
      bool is_set_error_on_drive_query_fail,
      void* (*on_fail_callback)(),
      int priority
  );

  MpqArchiveHandle_Api(const MpqArchiveHandle_Api& other) = delete;
  MpqArchiveHandle_Api(MpqArchiveHandle_Api&& other) noexcept;

  ~MpqArchiveHandle_Api();

  MpqArchiveHandle_Api& operator=(const MpqArchiveHandle_Api& other) = delete;
  MpqArchiveHandle_Api& operator=(MpqArchiveHandle_Api&& other) noexcept;

  operator MpqArchiveHandle_View() const noexcept;

  const MpqArchiveHandle* Get() const noexcept;

  void Close();

  bool IsOpen() const;

  void Open(
      std::string_view mpq_archive_path,
      bool is_set_error_on_drive_query_fail,
      int priority
  );
  void Open(
      std::string_view mpq_archive_path,
      bool is_set_error_on_drive_query_fail,
      void* (*on_fail_callback)(),
      int priority
  );

  const MpqArchive* GetMpqArchive() const noexcept;
  const char* GetMpqArchivePath() const noexcept;

 private:
  using ApiVariant = std::variant<MpqArchiveHandle_1_00*>;

  ApiVariant mpq_archive_handle_;

  bool is_open_;

  static ApiVariant CreateVariant(
      std::string_view mpq_archive_path,
      bool is_set_error_on_drive_query_fail,
      void* (*on_fail_callback)(),
      int priority
  );

  MpqArchiveHandle* Get() noexcept;
};

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_MPQ_ARCHIVE_HANDLE_D2_MPQ_ARCHIVE_HANDLE_API_HPP_
