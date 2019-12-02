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

#include "../../../../include/cxx/game_struct/d2_positional_rectangle/d2_positional_rectangle_api.hpp"

#include "d2_positional_rectangle_impl.hpp"
#include "../../../../include/cxx/game_struct/d2_positional_rectangle/d2_positional_rectangle_wrapper.hpp"
#include "../../../../include/cxx/game_version.hpp"

namespace d2 {
namespace {

using unique_ptr_1_00 = std::unique_ptr<PositionalRectangle_1_00>;

using PositionalRectangleVariant = std::variant<
    unique_ptr_1_00
>;

PositionalRectangleVariant CreateVariant(
    int left,
    int right,
    int top,
    int bottom
) {
  PositionalRectangle* positional_rectangle = CreatePositionalRectangle(
      left,
      right,
      top,
      bottom
  );

  return unique_ptr_1_00(
      reinterpret_cast<PositionalRectangle_1_00*>(positional_rectangle)
  );
}

} // namespace

PositionalRectangle_API::PositionalRectangle_API(
    int left,
    int right,
    int top,
    int bottom
) : positional_rectangle_(
        CreateVariant(left, right, top, bottom)
    ) {
}

PositionalRectangle_API::PositionalRectangle_API(
    const PositionalRectangle_API& other
) : PositionalRectangle_API(
        other.GetLeft(),
        other.GetRight(),
        other.GetTop(),
        other.GetBottom()
    ) {
}

PositionalRectangle_API::PositionalRectangle_API(
    PositionalRectangle_API&& other
) noexcept = default;

PositionalRectangle_API::~PositionalRectangle_API() = default;

PositionalRectangle_API& PositionalRectangle_API::operator=(
    const PositionalRectangle_API& other
) {
  *this = PositionalRectangle_API(
      other.GetLeft(),
      other.GetRight(),
      other.GetTop(),
      other.GetBottom()
  );

  return *this;
}

PositionalRectangle_API& PositionalRectangle_API::operator=(
    PositionalRectangle_API&& other
) noexcept = default;

PositionalRectangle_API::operator PositionalRectangle_View() const noexcept {
  return PositionalRectangle_View(this->Get());
}

const PositionalRectangle* PositionalRectangle_API::Get() const noexcept {
  auto& actual_positional_rectangle =
      std::get<unique_ptr_1_00>(this->positional_rectangle_);

  return reinterpret_cast<const PositionalRectangle*>(actual_positional_rectangle.get());
}

int PositionalRectangle_API::GetLeft() const noexcept {
  PositionalRectangle_View view(this->Get());

  return view.GetLeft();
}

int PositionalRectangle_API::GetRight() const noexcept {
  PositionalRectangle_View view(this->Get());

  return view.GetRight();
}

int PositionalRectangle_API::GetTop() const noexcept {
  PositionalRectangle_View view(this->Get());

  return view.GetTop();
}

int PositionalRectangle_API::GetBottom() const noexcept {
  PositionalRectangle_View view(this->Get());

  return view.GetBottom();
}

PositionalRectangle* CreatePositionalRectangle(
    int left,
    int right,
    int top,
    int bottom
) {
  PositionalRectangle* positional_rectangle;

  positional_rectangle = reinterpret_cast<PositionalRectangle*>(
      new PositionalRectangle_1_00()
  );

  PositionalRectangle_Wrapper wrapper(positional_rectangle);
  wrapper.SetLeft(left);
  wrapper.SetRight(right);
  wrapper.SetTop(top);
  wrapper.SetBottom(bottom);

  return wrapper.Get();
}

void DestroyPositionalRectangle(PositionalRectangle* positional_rectangle) {
  d2::GameVersion running_game_version = d2::GetRunningGameVersionId();

  delete positional_rectangle;
}

} // namespace d2
