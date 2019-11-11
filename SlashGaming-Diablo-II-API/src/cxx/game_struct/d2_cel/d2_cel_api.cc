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

#include "../../../../include/cxx/game_struct/d2_cel.hpp"

#include "d2_cel_impl.hpp"
#include "../../../../include/cxx/game_version.hpp"

namespace d2 {
namespace {

using unique_ptr_1_00 = std::unique_ptr<Cel_1_00[]>;

using CelVariant = std::variant<
    unique_ptr_1_00
>;

} // namespace

Cel_API::Cel_API(const Cel_API& other) {
  // TODO (Mir Drualga): Implement this function when a viable constructor is
  // available.
}

Cel_API::Cel_API(Cel_API&& other) noexcept = default;

Cel_API::~Cel_API() = default;

Cel_API& Cel_API::operator=(const Cel_API& other) {
  *this = Cel_API(other);

  return *this;
}

Cel_API& Cel_API::operator=(Cel_API&& other) noexcept = default;

Cel_API::operator Cel_View() const noexcept {
  return Cel_View(this->Get());
}

Cel_API::operator Cel_Wrapper() noexcept {
  return Cel_Wrapper(this->Get());
}

Cel* Cel_API::Get() noexcept {
  Cel_Wrapper wrapper(*this);

  return wrapper.Get();
}

const Cel* Cel_API::Get() const noexcept {
  Cel_View view(*this);

  return view.Get();
}

int Cel_API::GetHeight() const noexcept {
  Cel_View view(*this);

  return view.GetHeight();
}

int Cel_API::GetOffsetX() const noexcept {
  Cel_View view(*this);

  return view.GetOffsetX();
}

int Cel_API::GetOffsetY() const noexcept {
  Cel_View view(*this);

  return view.GetOffsetY();
}

int Cel_API::GetWidth() const noexcept {
  Cel_View view(*this);

  return view.GetWidth();
}

void Cel_API::SetHeight(int value) noexcept {
  Cel_Wrapper wrapper(*this);

  wrapper.SetHeight(value);
}

void Cel_API::SetOffsetX(int value) noexcept {
  Cel_Wrapper wrapper(*this);

  wrapper.SetOffsetX(value);
}

void Cel_API::SetOffsetY(int value) noexcept {
  Cel_Wrapper wrapper(*this);

  wrapper.SetOffsetY(value);
}

void Cel_API::SetWidth(int value) noexcept {
  Cel_Wrapper wrapper(*this);

  wrapper.SetWidth(value);
}

} // namespace d2
