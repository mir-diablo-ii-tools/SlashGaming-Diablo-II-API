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

#include "../../../../include/cxx/game_struct/d2_positional_rectangle/d2_positional_rectangle_array.hpp"

namespace d2 {

PositionalRectangle_Array::PositionalRectangle_Array(std::size_t count)
    : positional_rectangles_(CreateVariant(count)) {
}

PositionalRectangle_Array::PositionalRectangle_Array(
    PositionalRectangle_Array&& other
) noexcept = default;

PositionalRectangle_Array::~PositionalRectangle_Array() = default;

PositionalRectangle_Array& PositionalRectangle_Array::operator=(
    PositionalRectangle_Array&& other
) noexcept = default;

PositionalRectangle_View PositionalRectangle_Array::operator[](
    std::size_t index
) const noexcept {
  PositionalRectangle_View view(this->Get());

  return view[index];
}

PositionalRectangle_Wrapper PositionalRectangle_Array::operator[](
    std::size_t index
) noexcept {
  PositionalRectangle_Wrapper wrapper(this->Get());

  return wrapper[index];
}

PositionalRectangle* PositionalRectangle_Array::Get() noexcept {
  const auto* const_this = this;

  return const_cast<PositionalRectangle*>(const_this->Get());
}

const PositionalRectangle* PositionalRectangle_Array::Get() const noexcept {
  auto& actual_positional_rectangles =
      std::get<unique_array_1_00>(this->positional_rectangles_);

  return reinterpret_cast<const PositionalRectangle*>(
      actual_positional_rectangles.get()
  );
}

void PositionalRectangle_Array::Assign(
    PositionalRectangle_View src,
    std::size_t count
) {
  std::copy_n(
      reinterpret_cast<const PositionalRectangle_1_00*>(src.Get()),
      count,
      reinterpret_cast<PositionalRectangle_1_00*>(this->Get())
  );
}

PositionalRectangle_Array::array_variant
PositionalRectangle_Array::CreateVariant(std::size_t count) {
  return std::make_unique<PositionalRectangle_1_00[]>(count);
}

} // namespace d2
