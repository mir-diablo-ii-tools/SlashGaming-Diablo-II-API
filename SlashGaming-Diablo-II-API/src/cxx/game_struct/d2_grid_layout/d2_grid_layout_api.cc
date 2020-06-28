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

#include "../../../../include/cxx/game_struct/d2_grid_layout/d2_grid_layout_api.hpp"

#include "../../../../include/cxx/game_struct/d2_positional_rectangle/d2_positional_rectangle_wrapper.hpp"
#include "../../../../include/cxx/game_version.hpp"

namespace d2 {
namespace {

template <typename GridLayout_T>
static std::unique_ptr<GridLayout_T> CreatePtr(
    unsigned char num_columns,
    unsigned char num_rows,
    const PositionalRectangle* position,
    unsigned char width,
    unsigned char height
) {
  using PositionalRectangle_T = decltype(GridLayout_T::position);

  std::unique_ptr grid_layout = std::make_unique<GridLayout_T>();

  grid_layout->num_columns = num_columns;
  grid_layout->num_rows = num_rows;

  grid_layout->position =
      *reinterpret_cast<const PositionalRectangle_T*>(position);

  grid_layout->width = width;
  grid_layout->height = height;

  return grid_layout;
}

} // namespace

GridLayout_Api::GridLayout_Api(
    unsigned char num_columns,
    unsigned char num_rows,
    PositionalRectangle_View position,
    unsigned char width,
    unsigned char height
) : grid_layout_([=]() {
      ApiVariant grid_layout;

      grid_layout = GridLayout_1_00();

      std::visit(
          [=](auto& actual_grid_layout) {
            actual_grid_layout.num_columns = num_columns;
            actual_grid_layout.num_rows = num_rows;

            PositionalRectangle_Wrapper position_wrapper(
                reinterpret_cast<PositionalRectangle*>(
                    &actual_grid_layout.position
                )
            );
            position_wrapper.Assign(position);

            actual_grid_layout.width = width;
            actual_grid_layout.height = height;
          },
          grid_layout
      );

      return grid_layout;
    }()) {
}

GridLayout_Api::GridLayout_Api(
    const GridLayout_Api& other
) = default;

GridLayout_Api::GridLayout_Api(GridLayout_Api&& other) noexcept = default;

GridLayout_Api::~GridLayout_Api() = default;

GridLayout_Api& GridLayout_Api::operator=(
    const GridLayout_Api& other
) = default;

GridLayout_Api& GridLayout_Api::operator=(
    GridLayout_Api&& other
) noexcept = default;

GridLayout_Api::operator GridLayout_View() const noexcept {
  return GridLayout_View(this->Get());
}

GridLayout_Api::operator GridLayout_Wrapper() noexcept {
  return GridLayout_Wrapper(this->Get());
}

GridLayout* GridLayout_Api::Get() noexcept {
  return std::visit(
      [](auto& actual_grid_layout) {
        return reinterpret_cast<GridLayout*>(
            &actual_grid_layout
        );
      },
      this->grid_layout_
  );
}

const GridLayout* GridLayout_Api::Get() const noexcept {
  return std::visit(
      [](const auto& actual_grid_layout) {
        return reinterpret_cast<const GridLayout*>(
            &actual_grid_layout
        );
      },
      this->grid_layout_
  );
}

void GridLayout_Api::Assign(GridLayout_View src) noexcept {
  GridLayout_Wrapper wrapper(this->Get());

  wrapper.Assign(src);
}

unsigned char GridLayout_Api::GetNumColumns() const noexcept {
  GridLayout_View view(this->Get());

  return view.GetNumColumns();
}

void GridLayout_Api::SetNumColumns(unsigned char num_columns) noexcept {
  GridLayout_Wrapper wrapper(this->Get());

  wrapper.SetNumColumns(num_columns);
}

unsigned char GridLayout_Api::GetNumRows() const noexcept {
  GridLayout_View view(this->Get());

  return view.GetNumRows();
}

void GridLayout_Api::SetNumRows(unsigned char num_rows) noexcept {
  GridLayout_Wrapper wrapper(this->Get());

  wrapper.SetNumRows(num_rows);
}

PositionalRectangle* GridLayout_Api::GetPosition() noexcept {
  GridLayout_Wrapper wrapper(this->Get());

  return wrapper.GetPosition();
}

const PositionalRectangle* GridLayout_Api::GetPosition() const noexcept {
  GridLayout_View view(this->Get());

  return view.GetPosition();
}

unsigned char GridLayout_Api::GetWidth() const noexcept {
  GridLayout_View view(this->Get());

  return view.GetWidth();
}

void GridLayout_Api::SetWidth(unsigned char width) noexcept {
  GridLayout_Wrapper wrapper(this->Get());

  wrapper.SetWidth(width);
}

unsigned char GridLayout_Api::GetHeight() const noexcept {
  GridLayout_View view(this->Get());

  return view.GetHeight();
}

void GridLayout_Api::SetHeight(unsigned char height) noexcept {
  GridLayout_Wrapper wrapper(this->Get());

  wrapper.SetHeight(height);
}

} // namespace d2
