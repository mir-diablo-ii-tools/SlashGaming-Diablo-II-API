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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_POSITIONAL_RECTANGLE_D2_POSITIONAL_RECTANGLE_ARRAY_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_POSITIONAL_RECTANGLE_D2_POSITIONAL_RECTANGLE_ARRAY_HPP_

#include <cstddef>
#include <memory>
#include <variant>

#include "d2_positional_rectangle_struct.hpp"
#include "d2_positional_rectangle_view.hpp"
#include "d2_positional_rectangle_wrapper.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT PositionalRectangle_Array {
 public:
  using unique_array_1_00 = std::unique_ptr<PositionalRectangle_1_00[]>;
  using array_variant = std::variant<unique_array_1_00>;

  PositionalRectangle_Array() = delete;
  PositionalRectangle_Array(std::size_t count);

  PositionalRectangle_Array(const PositionalRectangle_Array& other) = delete;
  PositionalRectangle_Array(PositionalRectangle_Array&& other) noexcept;

  ~PositionalRectangle_Array();

  PositionalRectangle_Array& operator=(
      const PositionalRectangle_Array& other
  ) = delete;

  PositionalRectangle_Array& operator=(
      PositionalRectangle_Array&& other
  ) noexcept;

  PositionalRectangle_View operator[](std::size_t index) const noexcept;
  PositionalRectangle_Wrapper operator[](std::size_t index) noexcept;

  operator PositionalRectangle_View() const noexcept;
  operator PositionalRectangle_Wrapper() noexcept;

  PositionalRectangle* Get() noexcept;
  const PositionalRectangle* Get() const noexcept;

  void Assign(PositionalRectangle_View view, std::size_t count);

 private:
  array_variant positional_rectangles_;

  static array_variant CreateVariant(std::size_t count);
};

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_POSITIONAL_RECTANGLE_D2_POSITIONAL_RECTANGLE_ARRAY_HPP_
