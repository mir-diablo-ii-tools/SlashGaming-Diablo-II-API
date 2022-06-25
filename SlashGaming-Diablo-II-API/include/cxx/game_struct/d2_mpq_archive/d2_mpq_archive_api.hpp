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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_MPQ_ARCHIVE_D2_MPQ_ARCHIVE_API_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_MPQ_ARCHIVE_D2_MPQ_ARCHIVE_API_HPP_

#include <variant>

#include "../../game_undefined.hpp"
#include "d2_mpq_archive_struct.hpp"
#include "d2_mpq_archive_view.hpp"
#include "d2_mpq_archive_wrapper.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT MpqArchive_Api {
 public:
  MpqArchive_Api() = delete;

  // TODO (Mir Drualga): Undelete when MpqArchive_1_00 is implemented.
  MpqArchive_Api(const MpqArchive_Api& other) = delete;
  MpqArchive_Api(MpqArchive_Api&& other) noexcept;

  ~MpqArchive_Api();

  // TODO (Mir Drualga): Undelete when MpqArchive_1_00 is implemented.
  MpqArchive_Api& operator=(const MpqArchive_Api& other) = delete;
  MpqArchive_Api& operator=(MpqArchive_Api&& other) noexcept;

  operator MpqArchive_View() const noexcept;
  operator MpqArchive_Wrapper() noexcept;

  constexpr MpqArchive* Get() noexcept {
    const auto* const_this = this;

    return const_cast<MpqArchive*>(const_this->Get());
  }

  constexpr const MpqArchive* Get() const noexcept {
    return std::visit(
        [](const auto& actual_mpq_archive) {
          return reinterpret_cast<const MpqArchive*>(&actual_mpq_archive);
        },
        this->mpq_archive_
    );
  }

 private:
  // TODO (Mir Drualga): Change to std::variant<MpqArchive_1_00> when
  // MpqArchive_1_00 is implemented.
  using ApiVariant = std::variant<mapi::Undefined*>;

  ApiVariant mpq_archive_;
};

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_MPQ_ARCHIVE_D2_MPQ_ARCHIVE_API_HPP_
