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

#include "../../../../include/cxx/game_struct/d2_equipment_layout/d2_equipment_layout_api.hpp"

#include "../../../../include/cxx/game_struct/d2_positional_rectangle/d2_positional_rectangle_wrapper.hpp"
#include "../../../../include/cxx/game_version.hpp"

namespace d2 {
namespace {

template <typename EquipmentLayout_T>
static std::unique_ptr<EquipmentLayout_T> CreatePtr(
    const PositionalRectangle* position,
    unsigned char width,
    unsigned char height
) {
  using PositionalRectangle_T =
      std::remove_pointer_t<decltype(EquipmentLayout_T::position)>;

  const PositionalRectangle_T* actual_positional_rectangle =
      reinterpret_cast<const PositionalRectangle_T*>(position);

  std::unique_ptr equipment_layout = std::make_unique<EquipmentLayout_T>();

  equipment_layout->position = *actual_positional_rectangle;
  equipment_layout->width = width;
  equipment_layout->height = height;

  return equipment_layout;
}

} // namespace

EquipmentLayout_Api::EquipmentLayout_Api(
    PositionalRectangle_View position, unsigned char width, unsigned char height
) : equipment_layout_(
        CreateVariant(position.Get(), width, height)
    ) {
}

EquipmentLayout_Api::EquipmentLayout_Api(
    const EquipmentLayout_Api& other
) : EquipmentLayout_Api(
        other.GetPosition(),
        other.GetWidth(),
        other.GetHeight()
    ) {
}

EquipmentLayout_Api::EquipmentLayout_Api(
    EquipmentLayout_Api&& other
) noexcept = default;

EquipmentLayout_Api::~EquipmentLayout_Api() = default;

EquipmentLayout_Api& EquipmentLayout_Api::operator=(
    const EquipmentLayout_Api& other
) {
  *this = EquipmentLayout_Api(
      other.GetPosition(),
      other.GetWidth(),
      other.GetHeight()
  );

  return *this;
}

EquipmentLayout_Api& EquipmentLayout_Api::operator=(
    EquipmentLayout_Api&& other
) noexcept = default;

EquipmentLayout_Api::operator EquipmentLayout_View() const noexcept {
  return EquipmentLayout_View(this->Get());
}

EquipmentLayout_Api::operator EquipmentLayout_Wrapper() noexcept {
  return EquipmentLayout_Wrapper(this->Get());
}

EquipmentLayout* EquipmentLayout_Api::Get() noexcept {
  const auto* const_this = this;

  return const_cast<EquipmentLayout*>(const_this->Get());
}

const EquipmentLayout* EquipmentLayout_Api::Get() const noexcept {
  auto& actual_equipment_layout =
      std::get<unique_ptr_1_00>(this->equipment_layout_);

  return reinterpret_cast<const EquipmentLayout*>(actual_equipment_layout.get());
}

void EquipmentLayout_Api::Assign(EquipmentLayout_View src) noexcept {
  EquipmentLayout_Wrapper wrapper(this->Get());

  wrapper.Assign(src);
}

PositionalRectangle* EquipmentLayout_Api::GetPosition() noexcept {
  EquipmentLayout_Wrapper wrapper(this->Get());

  return wrapper.GetPosition();
}

const PositionalRectangle* EquipmentLayout_Api::GetPosition() const noexcept {
  EquipmentLayout_View view(this->Get());

  return view.GetPosition();
}

unsigned char EquipmentLayout_Api::GetWidth() const noexcept {
  EquipmentLayout_View view(this->Get());

  return view.GetWidth();
}

void EquipmentLayout_Api::SetWidth(unsigned char width) noexcept {
  EquipmentLayout_Wrapper wrapper(this->Get());

  wrapper.SetWidth(width);
}

unsigned char EquipmentLayout_Api::GetHeight() const noexcept {
  EquipmentLayout_View view(this->Get());

  return view.GetHeight();
}

void EquipmentLayout_Api::SetHeight(unsigned char height) noexcept {
  EquipmentLayout_Wrapper wrapper(this->Get());

  wrapper.SetHeight(height);
}

EquipmentLayout_Api::ptr_variant EquipmentLayout_Api::CreateVariant(
    const PositionalRectangle* position,
    unsigned char width,
    unsigned char height
) {
  return CreatePtr<EquipmentLayout_1_00>(
      position,
      width,
      height
  );
}

} // namespace d2
