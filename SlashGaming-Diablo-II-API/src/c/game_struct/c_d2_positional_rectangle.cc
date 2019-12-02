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

#include "../../../include/c/game_struct/d2_positional_rectangle.h"

#include "../../../include/cxx/game_struct/d2_positional_rectangle.hpp"
#include "../../cxx/game_struct/d2_positional_rectangle/d2_positional_rectangle_impl.hpp"

D2_PositionalRectangle* D2_PositionalRectangle_CreateWithPositions(
    int left,
    int right,
    int top,
    int bottom
) {
  auto* cxx_result = d2::CreatePositionalRectangle(
      left,
      right,
      top,
      bottom
  );

  return reinterpret_cast<D2_PositionalRectangle*>(cxx_result);
}

void D2_PositionalRectangle_Destroy(
    D2_PositionalRectangle* positional_rectangle
) {
  auto* cxx_positional_rectangle =
      reinterpret_cast<d2::PositionalRectangle*>(positional_rectangle);
  d2::DestroyPositionalRectangle(cxx_positional_rectangle);
}

int D2_PositionalRectangle_GetLeft(
    const D2_PositionalRectangle* positional_rectangle
) {
  const auto* cxx_positional_rectangle =
      reinterpret_cast<const d2::PositionalRectangle*>(positional_rectangle);

  d2::PositionalRectangle_View view(cxx_positional_rectangle);

  return view.GetLeft();
}

void D2_PositionalRectangle_SetLeft(
    D2_PositionalRectangle* positional_rectangle,
    int value
) {
  auto* cxx_positional_rectangle =
      reinterpret_cast<d2::PositionalRectangle*>(positional_rectangle);

  d2::PositionalRectangle_Wrapper wrapper(cxx_positional_rectangle);

  wrapper.SetLeft(value);
}

int D2_PositionalRectangle_GetRight(
    const D2_PositionalRectangle* positional_rectangle
) {
  const auto* cxx_positional_rectangle =
      reinterpret_cast<const d2::PositionalRectangle*>(positional_rectangle);

  d2::PositionalRectangle_View view(cxx_positional_rectangle);

  return view.GetRight();
}

void D2_PositionalRectangle_SetRight(
    D2_PositionalRectangle* positional_rectangle,
    int value
) {
  auto* cxx_positional_rectangle =
      reinterpret_cast<d2::PositionalRectangle*>(positional_rectangle);

  d2::PositionalRectangle_Wrapper wrapper(cxx_positional_rectangle);

  wrapper.SetRight(value);
}

int D2_PositionalRectangle_GetTop(
    const D2_PositionalRectangle* positional_rectangle
) {
  const auto* cxx_positional_rectangle =
      reinterpret_cast<const d2::PositionalRectangle*>(positional_rectangle);

  d2::PositionalRectangle_View view(cxx_positional_rectangle);

  return view.GetTop();
}

void D2_PositionalRectangle_SetTop(
    D2_PositionalRectangle* positional_rectangle,
    int value
) {
  auto* cxx_positional_rectangle =
      reinterpret_cast<d2::PositionalRectangle*>(positional_rectangle);

  d2::PositionalRectangle_Wrapper wrapper(cxx_positional_rectangle);

  wrapper.SetTop(value);
}

int D2_PositionalRectangle_GetBottom(
    const struct D2_PositionalRectangle* positional_rectangle
) {
  const auto* cxx_positional_rectangle =
      reinterpret_cast<const d2::PositionalRectangle*>(positional_rectangle);

  d2::PositionalRectangle_View view(cxx_positional_rectangle);

  return view.GetBottom();
}

void D2_PositionalRectangle_SetBottom(
    struct D2_PositionalRectangle* positional_rectangle,
    int value
) {
  auto* cxx_positional_rectangle =
      reinterpret_cast<d2::PositionalRectangle*>(positional_rectangle);

  d2::PositionalRectangle_Wrapper wrapper(cxx_positional_rectangle);

  wrapper.SetBottom(value);
}
