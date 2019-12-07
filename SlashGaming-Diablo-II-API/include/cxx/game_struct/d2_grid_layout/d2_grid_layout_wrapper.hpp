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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_GRID_LAYOUT_D2_GRID_LAYOUT_WRAPPER_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_GRID_LAYOUT_D2_GRID_LAYOUT_WRAPPER_HPP_

#include <cstdint>

#include "d2_grid_layout_struct.hpp"
#include "d2_grid_layout_view.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT GridLayout_Wrapper {
 public:
  GridLayout_Wrapper() = delete;
  GridLayout_Wrapper(GridLayout* ptr) noexcept;

  GridLayout_Wrapper(const GridLayout_Wrapper& other) noexcept;
  GridLayout_Wrapper(GridLayout_Wrapper&& other) noexcept;

  ~GridLayout_Wrapper() noexcept;

  GridLayout_Wrapper& operator=(
      const GridLayout_Wrapper& other
  ) noexcept;
  GridLayout_Wrapper& operator=(
      GridLayout_Wrapper&& other
  ) noexcept;

  operator GridLayout_View() const noexcept;

  GridLayout* Get() noexcept;
  const GridLayout* Get() const noexcept;

  std::uint_least8_t GetNumColumns() const noexcept;
  void SetNumColumns(std::uint_least8_t value) noexcept;

  std::uint_least8_t GetNumRows() const noexcept;
  void SetNumRows(std::uint_least8_t value) noexcept;

  PositionalRectangle* GetPosition() noexcept;
  const PositionalRectangle* GetPosition() const noexcept;

  std::uint_least8_t GetWidth() const noexcept;
  void SetWidth(std::uint_least8_t value) noexcept;

  std::uint_least8_t GetHeight() const noexcept;
  void SetHeight(std::uint_least8_t value) noexcept;

 private:
  GridLayout* ptr_;
};

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_GRID_LAYOUT_D2_GRID_LAYOUT_WRAPPER_HPP_
