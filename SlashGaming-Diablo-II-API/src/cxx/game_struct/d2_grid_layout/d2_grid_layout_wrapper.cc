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

#include "../../../../include/cxx/game_struct/d2_grid_layout/d2_grid_layout_wrapper.hpp"

#include "d2_grid_layout_impl.hpp"

namespace d2 {

GridLayout_Wrapper::GridLayout_Wrapper(
    GridLayout* ptr
) noexcept :
    ptr_(ptr) {
}

GridLayout_Wrapper::GridLayout_Wrapper(
    const GridLayout_Wrapper& other
) noexcept = default;

GridLayout_Wrapper::GridLayout_Wrapper(
    GridLayout_Wrapper&& other
) noexcept = default;

GridLayout_Wrapper::~GridLayout_Wrapper() noexcept = default;

GridLayout_Wrapper& GridLayout_Wrapper::operator=(
    const GridLayout_Wrapper& other
) noexcept = default;

GridLayout_Wrapper& GridLayout_Wrapper::operator=(
    GridLayout_Wrapper&& other
) noexcept = default;

GridLayout_Wrapper::operator GridLayout_View() const noexcept {
  return GridLayout_View(this->Get());
}

GridLayout* GridLayout_Wrapper::Get() noexcept {
  const auto* const_this = this;

  return const_cast<GridLayout*>(const_this->Get());
}

const GridLayout* GridLayout_Wrapper::Get() const noexcept {
  return this->ptr_;
}

std::uint_least8_t GridLayout_Wrapper::GetNumColumns() const noexcept {
  GridLayout_View view(this->Get());

  return view.GetNumColumns();
}

void GridLayout_Wrapper::SetNumColumns(std::uint_least8_t value) noexcept {
  auto* actual_ptr = reinterpret_cast<GridLayout_1_00*>(this->Get());

  actual_ptr->num_columns = value;
}

std::uint_least8_t GridLayout_Wrapper::GetNumRows() const noexcept {
  GridLayout_View view(this->Get());

  return view.GetNumRows();
}

void GridLayout_Wrapper::SetNumRows(std::uint_least8_t value) noexcept {
  auto* actual_ptr = reinterpret_cast<GridLayout_1_00*>(this->Get());

  actual_ptr->num_rows = value;
}

PositionalRectangle* GridLayout_Wrapper::GetPosition() noexcept {
  const auto* const_this = this;

  return const_cast<PositionalRectangle*>(const_this->GetPosition());
}

const PositionalRectangle* GridLayout_Wrapper::GetPosition() const noexcept {
  GridLayout_View view(this->Get());

  return view.GetPosition();
}

std::uint_least8_t GridLayout_Wrapper::GetWidth() const noexcept {
  GridLayout_View view(this->Get());

  return view.GetWidth();
}

void GridLayout_Wrapper::SetWidth(std::uint_least8_t value) noexcept {
  auto* actual_ptr = reinterpret_cast<GridLayout_1_00*>(this->Get());

  actual_ptr->width = value;
}

std::uint_least8_t GridLayout_Wrapper::GetHeight() const noexcept {
  GridLayout_View view(this->Get());

  return view.GetHeight();
}

void GridLayout_Wrapper::SetHeight(std::uint_least8_t value) noexcept {
  auto* actual_ptr = reinterpret_cast<GridLayout_1_00*>(this->Get());

  actual_ptr->height = value;
}

} // namespace d2
