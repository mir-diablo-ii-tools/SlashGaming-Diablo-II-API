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

#include "../../../../include/cxx/game_struct/d2_positional_rectangle/d2_positional_rectangle_wrapper.hpp"

namespace d2 {

PositionalRectangle_Wrapper::PositionalRectangle_Wrapper(
    PositionalRectangle* positional_rectangle
) noexcept :
    positional_rectangle_(CreateVariant(positional_rectangle)) {
}

PositionalRectangle_Wrapper::PositionalRectangle_Wrapper(
    const PositionalRectangle_Wrapper& other
) noexcept = default;

PositionalRectangle_Wrapper::PositionalRectangle_Wrapper(
    PositionalRectangle_Wrapper&& other
) noexcept = default;

PositionalRectangle_Wrapper::
~PositionalRectangle_Wrapper() noexcept = default;

PositionalRectangle_Wrapper& PositionalRectangle_Wrapper::operator=(
    const PositionalRectangle_Wrapper& other
) noexcept = default;

PositionalRectangle_Wrapper& PositionalRectangle_Wrapper::operator=(
    PositionalRectangle_Wrapper&& other
) noexcept = default;

PositionalRectangle_View PositionalRectangle_Wrapper::operator[](
    std::size_t index
) const noexcept {
  PositionalRectangle_View view(this->Get());

  return view[index];
}

PositionalRectangle_Wrapper PositionalRectangle_Wrapper::operator[](
    std::size_t index
) noexcept {
  const auto* const_this = this;

  return const_cast<PositionalRectangle*>((*const_this)[index].Get());
}

PositionalRectangle_Wrapper::operator
PositionalRectangle_View() const noexcept {
  return this->Get();
}

PositionalRectangle* PositionalRectangle_Wrapper::Get() noexcept {
  const auto* const_this = this;

  return const_cast<PositionalRectangle*>(const_this->Get());
}

const PositionalRectangle* PositionalRectangle_Wrapper::Get() const noexcept {
  return std::visit(
      [](const auto& actual_positional_rectangle) {
        return reinterpret_cast<const PositionalRectangle*>(
            actual_positional_rectangle
        );
      },
      this->positional_rectangle_
  );
}

void PositionalRectangle_Wrapper::Assign(
    PositionalRectangle_View src
) noexcept {
  std::visit(
      [&src](auto& actual_dest) {
        using Dest_T = decltype(actual_dest);
        using ActualSrc_T = const std::remove_pointer_t<
            std::remove_reference_t<Dest_T>
        >*;

        const auto* actual_src = reinterpret_cast<ActualSrc_T>(src.Get());

        *actual_dest = *actual_src;
      },
      this->positional_rectangle_
  );
}

int PositionalRectangle_Wrapper::GetLeft() const noexcept {
  PositionalRectangle_View view(this->Get());

  return view.GetLeft();
}

void PositionalRectangle_Wrapper::SetLeft(int left) noexcept {
  std::visit(
      [left](auto& actual_positional_rectangle) {
        actual_positional_rectangle->left = left;
      },
      this->positional_rectangle_
  );
}

int PositionalRectangle_Wrapper::GetRight() const noexcept {
  PositionalRectangle_View view(this->Get());

  return view.GetRight();
}

void PositionalRectangle_Wrapper::SetRight(int right) noexcept {
  std::visit(
      [right](auto& actual_positional_rectangle) {
        actual_positional_rectangle->right = right;
      },
      this->positional_rectangle_
  );
}

int PositionalRectangle_Wrapper::GetTop() const noexcept {
  PositionalRectangle_View view(this->Get());

  return view.GetTop();
}

void PositionalRectangle_Wrapper::SetTop(int top) noexcept {
  std::visit(
      [top](auto& actual_positional_rectangle) {
        actual_positional_rectangle->top = top;
      },
      this->positional_rectangle_
  );
}

int PositionalRectangle_Wrapper::GetBottom() const noexcept {
  PositionalRectangle_View view(this->Get());

  return view.GetBottom();
}

void PositionalRectangle_Wrapper::SetBottom(int bottom) noexcept {
  std::visit(
      [bottom](auto& actual_positional_rectangle) {
        actual_positional_rectangle->bottom = bottom;
      },
      this->positional_rectangle_
  );
}

PositionalRectangle_Wrapper::WrapperVariant
PositionalRectangle_Wrapper::CreateVariant(
    PositionalRectangle* positional_rectangle
) {
  return reinterpret_cast<PositionalRectangle_1_00*>(
      positional_rectangle
  );
}

} // namespace d2
