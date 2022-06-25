/**
 * SlashGaming Diablo II Modding API for C++
 * Copyright (C) 2018-2022  Mir Drualga
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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_MPQ_ARCHIVE_D2_MPQ_ARCHIVE_WRAPPER_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_MPQ_ARCHIVE_D2_MPQ_ARCHIVE_WRAPPER_HPP_

#include <cstddef>
#include <variant>

#include "d2_mpq_archive_struct.hpp"
#include "d2_mpq_archive_view.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT MpqArchive_Wrapper {
 public:
  using WrapperVariant = std::variant<MpqArchive_1_00*>;

  MpqArchive_Wrapper() = delete;

  MpqArchive_Wrapper(MpqArchive* mpq_archive) noexcept;

  constexpr explicit MpqArchive_Wrapper(
      WrapperVariant mpq_archive
  ) noexcept
      : mpq_archive_(::std::move(mpq_archive)) {
  }

  constexpr MpqArchive_Wrapper(
      const MpqArchive_Wrapper& other
  ) noexcept = default;

  constexpr MpqArchive_Wrapper(
      MpqArchive_Wrapper&& other
  ) noexcept = default;

  ~MpqArchive_Wrapper() noexcept = default;

  constexpr MpqArchive_Wrapper& operator=(
      const MpqArchive_Wrapper& other
  ) noexcept = default;

  constexpr MpqArchive_Wrapper& operator=(
      MpqArchive_Wrapper&& other
  ) noexcept = default;

  // TODO (Mir Drualga): Undelete these operator[] when
  // MpqArchive_1_00 is implemented.
  MpqArchive_View operator[](std::size_t index) const noexcept = delete;
  MpqArchive_Wrapper operator[](std::size_t index) noexcept = delete;

  constexpr operator MpqArchive_View() const noexcept {
    return ::std::visit(
        [](const auto& actual_mpq_archive) {
          return MpqArchive_View(actual_mpq_archive);
        },
        this->mpq_archive_
    );
  }

  constexpr MpqArchive* Get() noexcept {
    const auto* const_this = this;

    return const_cast<MpqArchive*>(const_this->Get());
  }

  constexpr const MpqArchive* Get() const noexcept {
    return std::visit(
        [](const auto& actual_mpq_archive) {
          return reinterpret_cast<const MpqArchive*>(actual_mpq_archive);
        },
        this->mpq_archive_
    );
  }

 private:
  WrapperVariant mpq_archive_;

  static WrapperVariant CreateVariant(MpqArchive* mpq_archive);
};

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_MPQ_ARCHIVE_D2_MPQ_ARCHIVE_WRAPPER_HPP_
