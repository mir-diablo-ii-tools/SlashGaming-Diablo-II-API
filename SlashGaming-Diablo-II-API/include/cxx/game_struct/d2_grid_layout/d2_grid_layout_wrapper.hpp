/**
 * SlashGaming Diablo II Modding API for C++
 * Copyright (C) 2018-2022  Mir Drualga
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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_GRID_LAYOUT_D2_GRID_LAYOUT_WRAPPER_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_GRID_LAYOUT_D2_GRID_LAYOUT_WRAPPER_HPP_

#include <cstddef>
#include <variant>

#include "../d2_positional_rectangle/d2_positional_rectangle_view.hpp"
#include "../d2_positional_rectangle/d2_positional_rectangle_wrapper.hpp"
#include "d2_grid_layout_struct.hpp"
#include "d2_grid_layout_view.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT GridLayout_Wrapper {
 public:
  using WrapperVariant = std::variant<GridLayout_1_00*>;

  GridLayout_Wrapper() = delete;

  GridLayout_Wrapper(GridLayout* grid_layout) noexcept;

  constexpr GridLayout_Wrapper(WrapperVariant grid_layout) noexcept
      : grid_layout_(::std::move(grid_layout)) {
  }

  constexpr GridLayout_Wrapper(
      const GridLayout_Wrapper& other
  ) noexcept = default;

  constexpr GridLayout_Wrapper(
      GridLayout_Wrapper&& other
  ) noexcept = default;

  ~GridLayout_Wrapper() noexcept = default;

  constexpr GridLayout_Wrapper& operator=(
      const GridLayout_Wrapper& other
  ) noexcept = default;

  constexpr GridLayout_Wrapper& operator=(
      GridLayout_Wrapper&& other
  ) noexcept = default;

  constexpr GridLayout_View operator[](
      std::size_t index
  ) const noexcept {
    GridLayout_View view(*this);

    return view[index];
  }

  constexpr GridLayout_Wrapper operator[](
      std::size_t index
  ) noexcept {
    return ::std::visit(
        [index](auto& actual_grid_layout) {
          return GridLayout_Wrapper(&actual_grid_layout[index]);
        },
        this->grid_layout_
    );
  }

  constexpr operator GridLayout_View() const noexcept {
    return ::std::visit(
        [](const auto& actual_grid_layout) {
          return GridLayout_View(actual_grid_layout);
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
          return reinterpret_cast<const GridLayout*>(actual_grid_layout);
        },
        this->grid_layout_
    );
  }

  constexpr void AssignMembers(GridLayout_View src) noexcept {
    std::visit(
        [&src](auto& actual_dest) {
          using Dest_T = decltype(actual_dest);
          using ActualSrc_T = const std::remove_pointer_t<
              std::remove_reference_t<Dest_T>
          >*;

          const auto* actual_src = reinterpret_cast<ActualSrc_T>(src.Get());

          *actual_dest = *actual_src;
        },
        this->grid_layout_
    );
  }

  constexpr unsigned char GetNumColumns() const noexcept {
    GridLayout_View view(*this);

    return view.GetNumColumns();
  }

  constexpr void SetNumColumns(unsigned char num_columns) noexcept {
    std::visit(
        [num_columns](auto& actual_positional_rectangle) {
          actual_positional_rectangle->num_columns = num_columns;
        },
        this->grid_layout_
    );
  }

  constexpr unsigned char GetNumRows() const noexcept {
    GridLayout_View view(*this);

    return view.GetNumRows();
  }

  constexpr void SetNumRows(unsigned char num_rows) noexcept {
    std::visit(
        [num_rows](auto& actual_positional_rectangle) {
          actual_positional_rectangle->num_rows = num_rows;
        },
        this->grid_layout_
    );
  }

  constexpr PositionalRectangle_View GetPosition() const noexcept {
    GridLayout_View view(*this);

    return view.GetPosition();
  }

  constexpr PositionalRectangle_Wrapper GetPosition() noexcept {
    return ::std::visit(
        [](auto& actual_grid_layout) {
          return PositionalRectangle_Wrapper(
              &actual_grid_layout->position
          );
        },
        this->grid_layout_
    );
  }

  constexpr unsigned char GetWidth() const noexcept {
    GridLayout_View view(*this);

    return view.GetWidth();
  }

  constexpr void SetWidth(unsigned char width) noexcept {
    std::visit(
        [width](auto& actual_positional_rectangle) {
          actual_positional_rectangle->width = width;
        },
        this->grid_layout_
    );
  }

  constexpr unsigned char GetHeight() const noexcept {
    GridLayout_View view(*this);

    return view.GetHeight();
  }

  constexpr void SetHeight(unsigned char height) noexcept {
    std::visit(
        [height](auto& actual_positional_rectangle) {
          actual_positional_rectangle->height = height;
        },
        this->grid_layout_
    );
  }

 private:
  WrapperVariant grid_layout_;

  static WrapperVariant CreateVariant(GridLayout* grid_layout);
};

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_GRID_LAYOUT_D2_GRID_LAYOUT_WRAPPER_HPP_
