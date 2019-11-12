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

#include "../../../../include/cxx/game_struct/d2_mpq_archive/d2_mpq_archive_wrapper.hpp"

namespace d2 {

MPQArchive_Wrapper::MPQArchive_Wrapper(MPQArchive* ptr) noexcept :
    ptr_(ptr) {
}

MPQArchive_Wrapper::MPQArchive_Wrapper(
    const MPQArchive_Wrapper& other
) noexcept = default;

MPQArchive_Wrapper::MPQArchive_Wrapper(
    MPQArchive_Wrapper&& other
) noexcept = default;

MPQArchive_Wrapper::~MPQArchive_Wrapper() noexcept = default;

MPQArchive_Wrapper& MPQArchive_Wrapper::operator=(
    const MPQArchive_Wrapper& other
) noexcept = default;

MPQArchive_Wrapper& MPQArchive_Wrapper::operator=(
    MPQArchive_Wrapper&& other
) noexcept = default;

MPQArchive_Wrapper::operator MPQArchive_View() const noexcept {
  return MPQArchive_View(this->ptr_);
}

MPQArchive* MPQArchive_Wrapper::Get() noexcept {
  const auto* const_this = this;

  return const_cast<MPQArchive*>(const_this->Get());
}


const MPQArchive* MPQArchive_Wrapper::Get() const noexcept {
  MPQArchive_View view(*this);

  return view.Get();
}

} // namespace d2
