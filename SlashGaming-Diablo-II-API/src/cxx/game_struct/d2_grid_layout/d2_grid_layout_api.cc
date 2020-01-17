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

#include "../../../../include/cxx/game_struct/d2_grid_layout/d2_grid_layout_api.hpp"

#include "d2_grid_layout_impl.hpp"
#include "../../../../include/cxx/game_struct/d2_positional_rectangle/d2_positional_rectangle_wrapper.hpp"
#include "../../../../include/cxx/game_version.hpp"

namespace d2 {
namespace {

using unique_ptr_1_00 = std::unique_ptr<GridLayout_1_00>;

using GridLayoutVariant = std::variant<
    unique_ptr_1_00
>;

GridLayoutVariant CreateVariant(
    std::int_least8_t num_columns,
    std::int_least8_t num_rows,
    PositionalRectangle_View position,
    std::int_least8_t width,
    std::int_least8_t height
) {
  GridLayout* grid_layout = CreateGridLayout(
      num_columns,
      num_rows,
      position.Get(),
      width,
      height
  );

  return unique_ptr_1_00(
      reinterpret_cast<GridLayout_1_00*>(grid_layout)
  );
}

} // namespace

GridLayout_API::GridLayout_API(
    std::int_least8_t num_columns,
    std::int_least8_t num_rows,
    PositionalRectangle_View position,
    std::int_least8_t width,
    std::int_least8_t height
) : grid_layout_(
        CreateVariant(num_columns, num_rows, position, width, height)
    ) {
}

GridLayout_API::GridLayout_API(
    const GridLayout_API& other
) : GridLayout_API(
        other.GetNumColumns(),
        other.GetNumRows(),
        other.GetPosition(),
        other.GetWidth(),
        other.GetHeight()
    ) {
}

GridLayout_API::GridLayout_API(
    GridLayout_API&& other
) noexcept = default;

GridLayout_API::~GridLayout_API() = default;

GridLayout_API& GridLayout_API::operator=(
    const GridLayout_API& other
) {
  *this = GridLayout_API(
      other.GetNumColumns(),
      other.GetNumRows(),
      other.GetPosition(),
      other.GetWidth(),
      other.GetHeight()
  );

  return *this;
}

GridLayout_API& GridLayout_API::operator=(
    GridLayout_API&& other
) noexcept = default;

GridLayout_API::operator GridLayout_View() const noexcept {
  return GridLayout_View(this->Get());
}

GridLayout_API::operator GridLayout_Wrapper() noexcept {
  return GridLayout_Wrapper(this->Get());
}

GridLayout* GridLayout_API::Get() noexcept {
  const auto* const_this = this;

  return const_cast<GridLayout*>(const_this->Get());
}

const GridLayout* GridLayout_API::Get() const noexcept {
  auto& actual_grid_layout =
      std::get<unique_ptr_1_00>(this->grid_layout_);

  return reinterpret_cast<const GridLayout*>(actual_grid_layout.get());
}

void GridLayout_API::Copy(GridLayout_View src) noexcept {
  GridLayout_Wrapper wrapper(this->Get());

  wrapper.Copy(src);
}

std::uint_least8_t GridLayout_API::GetNumColumns() const noexcept {
  GridLayout_View view(this->Get());

  return view.GetNumColumns();
}

void GridLayout_API::SetNumColumns(std::uint_least8_t value) noexcept {
  GridLayout_Wrapper wrapper(this->Get());

  wrapper.SetNumColumns(value);
}

std::uint_least8_t GridLayout_API::GetNumRows() const noexcept {
  GridLayout_View view(this->Get());

  return view.GetNumRows();
}

void GridLayout_API::SetNumRows(std::uint_least8_t value) noexcept {
  GridLayout_Wrapper wrapper(this->Get());

  wrapper.SetNumRows(value);
}

PositionalRectangle* GridLayout_API::GetPosition() noexcept {
  GridLayout_Wrapper wrapper(this->Get());

  return wrapper.GetPosition();
}

const PositionalRectangle* GridLayout_API::GetPosition() const noexcept {
  GridLayout_View view(this->Get());

  return view.GetPosition();
}

std::uint_least8_t GridLayout_API::GetWidth() const noexcept {
  GridLayout_View view(this->Get());

  return view.GetWidth();
}

void GridLayout_API::SetWidth(std::uint_least8_t value) noexcept {
  GridLayout_Wrapper wrapper(this->Get());

  wrapper.SetWidth(value);
}

std::uint_least8_t GridLayout_API::GetHeight() const noexcept {
  GridLayout_View view(this->Get());

  return view.GetHeight();
}

void GridLayout_API::SetHeight(std::uint_least8_t value) noexcept {
  GridLayout_Wrapper wrapper(this->Get());

  wrapper.SetHeight(value);
}

GridLayout* CreateGridLayout(
    std::int_least8_t num_columns,
    std::int_least8_t num_rows,
    const PositionalRectangle* position,
    std::int_least8_t width,
    std::int_least8_t height
) {
  GridLayout* grid_layout;

  grid_layout = reinterpret_cast<GridLayout*>(new GridLayout_1_00());

  // Set all the values of the struct.
  GridLayout_Wrapper wrapper(grid_layout);
  wrapper.SetNumColumns(num_columns);
  wrapper.SetNumRows(num_rows);

  PositionalRectangle_Wrapper position_wrapper(wrapper.GetPosition());
  position_wrapper.Copy(position);

  wrapper.SetWidth(width);
  wrapper.SetHeight(height);

  return grid_layout;
}

void DestroyGridLayout(GridLayout* grid_layout) {
  d2::GameVersion running_game_version = d2::GetRunningGameVersionId();

  auto* actual_grid_layout = reinterpret_cast<GridLayout_1_00*>(grid_layout);

  delete actual_grid_layout;
}

} // namespace d2
