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

#include "../../../../include/cxx/game_struct/d2_grid_layout/d2_grid_layout_view.hpp"

namespace d2 {

GridLayout_View::GridLayout_View(const GridLayout* grid_layout) noexcept :
    grid_layout_([grid_layout]() {
      return reinterpret_cast<const GridLayout_1_00*>(grid_layout);
    }()) {
}

GridLayout_View::GridLayout_View(
    const GridLayout_View& other
) noexcept = default;

GridLayout_View::GridLayout_View(
    GridLayout_View&& other
) noexcept = default;

GridLayout_View::~GridLayout_View() noexcept = default;

GridLayout_View& GridLayout_View::operator=(
    const GridLayout_View& other
) noexcept = default;

GridLayout_View& GridLayout_View::operator=(
    GridLayout_View&& other
) noexcept = default;

GridLayout_View GridLayout_View::operator[](
    std::size_t index
) const noexcept {
  return std::visit(
      [index](const auto& actual_grid_layout) {
        return reinterpret_cast<const GridLayout*>(
            &actual_grid_layout[index]
        );
      },
      this->grid_layout_
  );
}

const GridLayout* GridLayout_View::Get() const noexcept {
  return std::visit(
      [](const auto& actual_grid_layout) {
        return reinterpret_cast<const GridLayout*>(actual_grid_layout);
      },
      this->grid_layout_
  );
}

unsigned char GridLayout_View::GetNumColumns() const noexcept {
  return std::visit(
      [](const auto& actual_grid_layout) {
        return actual_grid_layout->num_columns;
      },
      this->grid_layout_
  );
}

unsigned char GridLayout_View::GetNumRows() const noexcept {
  return std::visit(
      [](const auto& actual_grid_layout) {
        return actual_grid_layout->num_rows;
      },
      this->grid_layout_
  );
}

const PositionalRectangle* GridLayout_View::GetPosition() const noexcept {
  return std::visit(
      [](const auto& actual_grid_layout) {
        return reinterpret_cast<const PositionalRectangle*>(
            &actual_grid_layout->position
        );
      },
      this->grid_layout_
  );
}

unsigned char GridLayout_View::GetWidth() const noexcept {
  return std::visit(
      [](const auto& actual_grid_layout) {
        return actual_grid_layout->width;
      },
      this->grid_layout_
  );
}

unsigned char GridLayout_View::GetHeight() const noexcept {
  return std::visit(
      [](const auto& actual_grid_layout) {
        return actual_grid_layout->height;
      },
      this->grid_layout_
  );
}

} // namespace d2
