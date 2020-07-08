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

#include "../../../../include/cxx/game_struct/d2_cel.hpp"

namespace d2 {

Cel_Api::Cel_Api(const Cel_Api& other) {
  // TODO (Mir Drualga): Implement this function when a viable constructor is
  // available.
}

Cel_Api::Cel_Api(Cel_Api&& other) noexcept = default;

Cel_Api::~Cel_Api() = default;

Cel_Api& Cel_Api::operator=(const Cel_Api& other) {
  *this = Cel_Api(other);

  return *this;
}

Cel_Api& Cel_Api::operator=(Cel_Api&& other) noexcept = default;

Cel_Api::operator Cel_View() const noexcept {
  return Cel_View(this->Get());
}

Cel_Api::operator Cel_Wrapper() noexcept {
  return Cel_Wrapper(this->Get());
}

Cel* Cel_Api::Get() noexcept {
  const auto* const_this = this;

  return const_cast<Cel*>(const_this->Get());
}

const Cel* Cel_Api::Get() const noexcept {
  return std::visit(
      [](const auto& actual_mpq_archive) {
        return reinterpret_cast<const Cel*>(actual_mpq_archive);
      },
      this->cel_
  );
}

int Cel_Api::GetHeight() const noexcept {
  Cel_View view(this->Get());

  return view.GetHeight();
}

void Cel_Api::SetHeight(int height) noexcept {
  Cel_Wrapper wrapper(this->Get());

  wrapper.SetHeight(height);
}

int Cel_Api::GetOffsetX() const noexcept {
  Cel_View view(this->Get());

  return view.GetOffsetX();
}

void Cel_Api::SetOffsetX(int offset_x) noexcept {
  Cel_Wrapper wrapper(this->Get());

  wrapper.SetOffsetX(offset_x);
}

int Cel_Api::GetOffsetY() const noexcept {
  Cel_View view(this->Get());

  return view.GetOffsetY();
}

void Cel_Api::SetOffsetY(int offset_y) noexcept {
  Cel_Wrapper wrapper(this->Get());

  wrapper.SetOffsetY(offset_y);
}

int Cel_Api::GetWidth() const noexcept {
  Cel_View view(this->Get());

  return view.GetWidth();
}

void Cel_Api::SetWidth(int width) noexcept {
  Cel_Wrapper wrapper(this->Get());

  wrapper.SetWidth(width);
}

} // namespace d2
