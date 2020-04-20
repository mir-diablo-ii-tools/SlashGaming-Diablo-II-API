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

#include "../../../../include/cxx/game_struct/d2_cel/d2_cel_view.hpp"

namespace d2 {

Cel_View::Cel_View(const Cel* cel) noexcept :
    cel_(cel) {
}

Cel_View::Cel_View(const Cel_View& other) noexcept = default;

Cel_View::Cel_View(Cel_View&& other) noexcept = default;

Cel_View::~Cel_View() noexcept = default;

Cel_View& Cel_View::operator=(const Cel_View& other) noexcept = default;

Cel_View& Cel_View::operator=(Cel_View&& other) noexcept = default;

Cel_View Cel_View::operator[](std::size_t index) const noexcept {
  const auto* actual_cel = reinterpret_cast<const Cel_1_00*>(this->Get());

  return reinterpret_cast<const Cel*>(&actual_cel[index]);
}

const Cel* Cel_View::Get() const noexcept {
  return this->cel_;
}

int Cel_View::GetHeight() const noexcept {
  auto* actual_cel = reinterpret_cast<const Cel_1_00*>(this->Get());

  return actual_cel->height;
}

int Cel_View::GetOffsetX() const noexcept {
  auto* actual_cel = reinterpret_cast<const Cel_1_00*>(this->Get());

  return actual_cel->offset_x;
}

int Cel_View::GetOffsetY() const noexcept {
  auto* actual_cel = reinterpret_cast<const Cel_1_00*>(this->Get());

  return actual_cel->offset_y;
}

int Cel_View::GetWidth() const noexcept {
  auto* actual_cel = reinterpret_cast<const Cel_1_00*>(this->Get());

  return actual_cel->width;
}

} // namespace d2
