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

#include "../../../../include/cxx/game_struct/d2_positional_rectangle/d2_positional_rectangle_api.hpp"

#include "../../../../include/cxx/game_version.hpp"

namespace d2 {

PositionalRectangle_Api::PositionalRectangle_Api() :
    PositionalRectangle_Api(0, 0, 0, 0) {
}

PositionalRectangle_Api::PositionalRectangle_Api(
    int left,
    int right,
    int top,
    int bottom
) : positional_rectangle_(CreateVariant(left, right, top, bottom)) {
}

PositionalRectangle_Api::PositionalRectangle_Api(
    const PositionalRectangle_Api& other
) = default;

PositionalRectangle_Api::PositionalRectangle_Api(
    PositionalRectangle_Api&& other
) noexcept = default;

PositionalRectangle_Api::~PositionalRectangle_Api() = default;

PositionalRectangle_Api& PositionalRectangle_Api::operator=(
    const PositionalRectangle_Api& other
) = default;

PositionalRectangle_Api& PositionalRectangle_Api::operator=(
    PositionalRectangle_Api&& other
) noexcept = default;

PositionalRectangle_Api::operator PositionalRectangle_View() const noexcept {
  return PositionalRectangle_View(this->Get());
}

PositionalRectangle_Api::operator PositionalRectangle_Wrapper() noexcept {
  return PositionalRectangle_Wrapper(this->Get());
}

PositionalRectangle* PositionalRectangle_Api::Get() noexcept {
  const auto* const_this = this;

  return const_cast<PositionalRectangle*>(const_this->Get());
}

const PositionalRectangle* PositionalRectangle_Api::Get() const noexcept {
  return std::visit(
      [](const auto& actual_positional_rectangle) {
        return reinterpret_cast<const PositionalRectangle*>(
            &actual_positional_rectangle
        );
      },
      this->positional_rectangle_
  );
}

void PositionalRectangle_Api::Assign(PositionalRectangle_View src) noexcept {
  PositionalRectangle_Wrapper wrapper(this->Get());

  wrapper.Assign(src);
}

int PositionalRectangle_Api::GetLeft() const noexcept {
  PositionalRectangle_View view(this->Get());

  return view.GetLeft();
}

void PositionalRectangle_Api::SetLeft(int left) noexcept {
  PositionalRectangle_Wrapper wrapper(this->Get());

  return wrapper.SetLeft(left);
}

int PositionalRectangle_Api::GetRight() const noexcept {
  PositionalRectangle_View view(this->Get());

  return view.GetRight();
}

void PositionalRectangle_Api::SetRight(int right) noexcept {
  PositionalRectangle_Wrapper wrapper(this->Get());

  return wrapper.SetRight(right);
}

int PositionalRectangle_Api::GetTop() const noexcept {
  PositionalRectangle_View view(this->Get());

  return view.GetTop();
}

void PositionalRectangle_Api::SetTop(int top) noexcept {
  PositionalRectangle_Wrapper wrapper(this->Get());

  return wrapper.SetTop(top);
}

int PositionalRectangle_Api::GetBottom() const noexcept {
  PositionalRectangle_View view(this->Get());

  return view.GetBottom();
}

void PositionalRectangle_Api::SetBottom(int bottom) noexcept {
  PositionalRectangle_Wrapper wrapper(this->Get());

  return wrapper.SetBottom(bottom);
}

PositionalRectangle_Api::ApiVariant PositionalRectangle_Api::CreateVariant(
    int left,
    int right,
    int top,
    int bottom
) {
  ApiVariant positional_rectangle;

  positional_rectangle = PositionalRectangle_1_00();

  std::visit(
      [left, right, top, bottom](auto& actual_positional_rectangle) {
        actual_positional_rectangle.left = left;
        actual_positional_rectangle.right = right;
        actual_positional_rectangle.top = top;
        actual_positional_rectangle.bottom = bottom;
      },
      positional_rectangle
  );

  return positional_rectangle;
}

} // namespace d2
