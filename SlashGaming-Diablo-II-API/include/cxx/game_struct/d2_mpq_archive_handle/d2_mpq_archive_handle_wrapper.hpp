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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_MPQ_ARCHIVE_HANDLE_D2_MPQ_ARCHIVE_HANDLE_WRAPPER_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_MPQ_ARCHIVE_HANDLE_D2_MPQ_ARCHIVE_HANDLE_WRAPPER_HPP_

#include <cstddef>
#include <variant>

#include "../d2_mpq_archive/d2_mpq_archive_view.hpp"
#include "../d2_mpq_archive/d2_mpq_archive_wrapper.hpp"
#include "d2_mpq_archive_handle_struct.hpp"
#include "d2_mpq_archive_handle_view.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT MpqArchiveHandle_Wrapper {
 public:
  MpqArchiveHandle_Wrapper() = delete;
  MpqArchiveHandle_Wrapper(MpqArchiveHandle* mpq_archive_handle) noexcept;

  MpqArchiveHandle_Wrapper(const MpqArchiveHandle_Wrapper& other) noexcept;
  MpqArchiveHandle_Wrapper(MpqArchiveHandle_Wrapper&& other) noexcept;

  ~MpqArchiveHandle_Wrapper() noexcept;

  MpqArchiveHandle_Wrapper& operator=(
      const MpqArchiveHandle_Wrapper& other
  ) noexcept;

  MpqArchiveHandle_Wrapper& operator=(
      MpqArchiveHandle_Wrapper&& other
  ) noexcept;

  MpqArchiveHandle_View operator[](std::size_t index) const noexcept;
  MpqArchiveHandle_Wrapper operator[](std::size_t index) noexcept;

  operator MpqArchiveHandle_View() const noexcept;

  MpqArchiveHandle* Get() noexcept;
  const MpqArchiveHandle* Get() const noexcept;

  MpqArchive_View GetMpqArchive() const noexcept;
  MpqArchive_Wrapper GetMpqArchive() noexcept;

  void SetMpqArchive(MpqArchive_Wrapper mpq_archive) noexcept;

  char* GetMpqArchivePath() noexcept;
  const char* GetMpqArchivePath() const noexcept;

 private:
  using WrapperVariant = std::variant<MpqArchiveHandle_1_00*>;

  WrapperVariant mpq_archive_handle_;

  static WrapperVariant CreateVariant(MpqArchiveHandle* mpq_archive_handle);
};

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_MPQ_ARCHIVE_HANDLE_D2_MPQ_ARCHIVE_HANDLE_WRAPPER_HPP_
