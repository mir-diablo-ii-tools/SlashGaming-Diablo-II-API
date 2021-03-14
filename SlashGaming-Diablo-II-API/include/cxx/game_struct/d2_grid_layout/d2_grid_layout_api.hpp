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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_GRID_LAYOUT_D2_GRID_LAYOUT_API_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_GRID_LAYOUT_D2_GRID_LAYOUT_API_HPP_

#include <variant>

#include "../d2_positional_rectangle/d2_positional_rectangle_view.hpp"
#include "../d2_positional_rectangle/d2_positional_rectangle_wrapper.hpp"
#include "../d2_positional_rectangle/d2_positional_rectangle_struct.hpp"
#include "d2_grid_layout_struct.hpp"
#include "d2_grid_layout_view.hpp"
#include "d2_grid_layout_wrapper.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT GridLayout_Api {
 public:
  using ApiVariant = std::variant<GridLayout_1_00>;

  GridLayout_Api() = delete;
  GridLayout_Api(
      unsigned char num_columns,
      unsigned char num_rows,
      PositionalRectangle_View position,
      unsigned char width,
      unsigned char height
  );

  constexpr GridLayout_Api(
      const GridLayout_Api& other
  ) = default;

  constexpr GridLayout_Api(
      GridLayout_Api&& other
  ) noexcept = default;

  ~GridLayout_Api() noexcept = default;

  constexpr GridLayout_Api& operator=(
      const GridLayout_Api& other
  ) = default;

  constexpr GridLayout_Api& operator=(
      GridLayout_Api&& other
  ) noexcept = default;

  constexpr operator GridLayout_View() const noexcept {
    return ::std::visit(
        [](const auto& actual_grid_layout) {
          return GridLayout_View(&actual_grid_layout);
        },
        this->grid_layout_
    );
  }

  constexpr operator GridLayout_Wrapper() noexcept {
    return ::std::visit(
        [](auto& actual_grid_layout) {
          return GridLayout_Wrapper(&actual_grid_layout);
        },
        this->grid_layout_
    );
  }

  constexpr GridLayout* Get() noexcept {
    const auto* const_this = this;

    return const_cast<GridLayout*>(const_this->Get());
  }

  constexpr const GridLayout* Get() const noexcept {
    return std::visit(
        [](const auto& actual_grid_layout) {
          return reinterpret_cast<const GridLayout*>(
              &actual_grid_layout
          );
        },
        this->grid_layout_
    );
  }

  constexpr void AssignMembers(GridLayout_View src) noexcept {
    GridLayout_Wrapper wrapper(*this);

    wrapper.AssignMembers(src);
  }

  constexpr unsigned char GetNumColumns() const noexcept {
    GridLayout_View view(*this);

    return view.GetNumColumns();
  }

  constexpr void SetNumColumns(unsigned char num_columns) noexcept {
    GridLayout_Wrapper wrapper(*this);

    wrapper.SetNumColumns(num_columns);
  }

  constexpr unsigned char GetNumRows() const noexcept {
    GridLayout_View view(*this);

    return view.GetNumRows();
  }

  constexpr void SetNumRows(unsigned char num_rows) noexcept {
    GridLayout_Wrapper wrapper(*this);

    wrapper.SetNumRows(num_rows);
  }

  constexpr PositionalRectangle_View GetPosition() const noexcept {
    GridLayout_View view(*this);

    return view.GetPosition();
  }

  constexpr PositionalRectangle_Wrapper GetPosition() noexcept {
    GridLayout_Wrapper wrapper(*this);

    return wrapper.GetPosition();
  }

  constexpr unsigned char GetWidth() const noexcept {
    GridLayout_View view(*this);

    return view.GetWidth();
  }

  constexpr void SetWidth(unsigned char width) noexcept {
    GridLayout_Wrapper wrapper(*this);

    wrapper.SetWidth(width);
  }

  constexpr unsigned char GetHeight() const noexcept {
    GridLayout_View view(*this);

    return view.GetHeight();
  }

  constexpr void SetHeight(unsigned char height) noexcept {
    GridLayout_Wrapper wrapper(*this);

    wrapper.SetHeight(height);
  }

 private:
  ApiVariant grid_layout_;

  static ApiVariant CreateVariant(
      unsigned char num_columns,
      unsigned char num_rows,
      const PositionalRectangle* position,
      unsigned char width,
      unsigned char height
  );
};

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_GRID_LAYOUT_D2_GRID_LAYOUT_API_HPP_
