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

#include "../../../include/c/game_struct/d2_grid_layout.h"

#include <cstdint>

#include "../../../include/cxx/game_struct/d2_grid_layout.hpp"
#include "../../cxx/game_struct/d2_grid_layout/d2_grid_layout_impl.hpp"

D2_GridLayout* D2_GridLayout_CreateWithLayout(
    int_least8_t num_columns,
    int_least8_t num_rows,
    const D2_PositionalRectangle* position,
    int_least8_t width,
    int_least8_t height
) {
  const auto* actual_position =
      reinterpret_cast<const d2::PositionalRectangle*>(position);

  auto* actual_grid_layout = d2::CreateGridLayout(
      num_columns,
      num_rows,
      actual_position,
      width,
      height
  );

  return reinterpret_cast<D2_GridLayout*>(actual_grid_layout);
}

void D2_GridLayout_Destroy(
    D2_GridLayout* grid_layout
) {
  auto* actual_grid_layout = reinterpret_cast<d2::GridLayout*>(grid_layout);

  d2::DestroyGridLayout(actual_grid_layout);
}

std::uint_least8_t D2_GridLayout_GetNumColumns(
    const D2_GridLayout* grid_layout
) {
  const auto* actual_grid_layout =
      reinterpret_cast<const d2::GridLayout*>(grid_layout);

  d2::GridLayout_View view(actual_grid_layout);

  return view.GetNumColumns();
}

void D2_GridLayout_SetNumColumns(
    D2_GridLayout* grid_layout,
    std::uint_least8_t value
) {
  auto* actual_grid_layout = reinterpret_cast<d2::GridLayout*>(
      grid_layout
  );

  d2::GridLayout_Wrapper wrapper(actual_grid_layout);

  return wrapper.SetNumColumns(value);
}

std::uint_least8_t D2_GridLayout_GetNumRows(
    const D2_GridLayout* grid_layout
) {
  const auto* actual_grid_layout =
      reinterpret_cast<const d2::GridLayout*>(grid_layout);

  d2::GridLayout_View view(actual_grid_layout);

  return view.GetNumRows();
}

void D2_GridLayout_SetNumRows(
    D2_GridLayout* grid_layout,
    std::uint_least8_t value
) {
  auto* actual_grid_layout = reinterpret_cast<d2::GridLayout*>(
      grid_layout
  );

  d2::GridLayout_Wrapper wrapper(actual_grid_layout);

  return wrapper.SetNumRows(value);
}

D2_PositionalRectangle* D2_GridLayout_GetPosition(
    D2_GridLayout* grid_layout
) {
  auto* actual_grid_layout = reinterpret_cast<d2::GridLayout*>(grid_layout);

  d2::GridLayout_Wrapper wrapper(actual_grid_layout);

  return reinterpret_cast<D2_PositionalRectangle*>(wrapper.GetPosition());
}

const D2_PositionalRectangle* D2_GridLayout_GetConstPosition(
    const D2_GridLayout* grid_layout
) {
  const auto* actual_grid_layout =
      reinterpret_cast<const d2::GridLayout*>(grid_layout);

  d2::GridLayout_View view(actual_grid_layout);

  return reinterpret_cast<const D2_PositionalRectangle*>(
      view.GetPosition()
  );
}

std::uint_least8_t D2_GridLayout_GetWidth(
    const D2_GridLayout* grid_layout
){
  const auto* actual_grid_layout =
      reinterpret_cast<const d2::GridLayout*>(grid_layout);

  d2::GridLayout_View view(actual_grid_layout);

  return view.GetWidth();
}

void D2_GridLayout_SetWidth(
    D2_GridLayout* grid_layout,
    std::uint_least8_t value
) {
  auto* actual_grid_layout = reinterpret_cast<d2::GridLayout*>(
      grid_layout
  );

  d2::GridLayout_Wrapper wrapper(actual_grid_layout);

  return wrapper.SetWidth(value);
}

std::uint_least8_t D2_GridLayout_GetHeight(
    const D2_GridLayout* grid_layout
){
  const auto* actual_grid_layout =
      reinterpret_cast<const d2::GridLayout*>(grid_layout);

  d2::GridLayout_View view(actual_grid_layout);

  return view.GetHeight();
}

void D2_GridLayout_SetHeight(
    D2_GridLayout* grid_layout,
    std::uint_least8_t value
) {
  auto* actual_grid_layout = reinterpret_cast<d2::GridLayout*>(
      grid_layout
  );

  d2::GridLayout_Wrapper wrapper(actual_grid_layout);

  return wrapper.SetHeight(value);
}
