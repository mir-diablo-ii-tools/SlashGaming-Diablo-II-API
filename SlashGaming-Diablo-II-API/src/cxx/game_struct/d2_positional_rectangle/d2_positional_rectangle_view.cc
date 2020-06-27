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

#include "../../../../include/cxx/game_struct/d2_positional_rectangle/d2_positional_rectangle_view.hpp"

namespace d2 {

PositionalRectangle_View::PositionalRectangle_View(
    const PositionalRectangle* positional_rectangle
) noexcept :
    positional_rectangle_([positional_rectangle]() {
      return reinterpret_cast<const PositionalRectangle_1_00*>(
          positional_rectangle
      );
    }()) {
}

PositionalRectangle_View::PositionalRectangle_View(
    const PositionalRectangle_View& other
) noexcept = default;

PositionalRectangle_View::PositionalRectangle_View(
    PositionalRectangle_View&& other
) noexcept = default;

PositionalRectangle_View::~PositionalRectangle_View() noexcept = default;

PositionalRectangle_View& PositionalRectangle_View::operator=(
    const PositionalRectangle_View& other
) noexcept = default;

PositionalRectangle_View& PositionalRectangle_View::operator=(
    PositionalRectangle_View&& other
) noexcept = default;

PositionalRectangle_View PositionalRectangle_View::operator[](
    std::size_t index
) const noexcept {
  return std::visit(
      [index](const auto& actual_positional_rectangle) {
        return reinterpret_cast<const PositionalRectangle*>(
            &actual_positional_rectangle[index]
        );
      },
      this->positional_rectangle_
  );
}

const PositionalRectangle* PositionalRectangle_View::Get() const noexcept {
  return std::visit(
      [](const auto& actual_positional_rectangle) {
        return reinterpret_cast<const PositionalRectangle*>(
            actual_positional_rectangle
        );
      },
      this->positional_rectangle_
  );
}

int PositionalRectangle_View::GetLeft() const noexcept {
  return std::visit(
      [](const auto& actual_positional_rectangle) {
        return actual_positional_rectangle->left;
      },
      this->positional_rectangle_
  );
}

int PositionalRectangle_View::GetRight() const noexcept {
  return std::visit(
      [](const auto& actual_positional_rectangle) {
        return actual_positional_rectangle->right;
      },
      this->positional_rectangle_
  );
}

int PositionalRectangle_View::GetTop() const noexcept {
  return std::visit(
      [](const auto& actual_positional_rectangle) {
        return actual_positional_rectangle->top;
      },
      this->positional_rectangle_
  );
}

int PositionalRectangle_View::GetBottom() const noexcept {
  return std::visit(
      [](const auto& actual_positional_rectangle) {
        return actual_positional_rectangle->bottom;
      },
      this->positional_rectangle_
  );
}

} // namespace d2
