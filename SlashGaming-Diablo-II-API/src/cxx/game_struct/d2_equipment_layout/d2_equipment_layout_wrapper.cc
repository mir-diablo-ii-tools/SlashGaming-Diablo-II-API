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

#include "../../../../include/cxx/game_struct/d2_equipment_layout/d2_equipment_layout_wrapper.hpp"

namespace d2 {

EquipmentLayout_Wrapper::EquipmentLayout_Wrapper(
    EquipmentLayout* equipment_layout
) noexcept :
    equipment_layout_(equipment_layout) {
}

EquipmentLayout_Wrapper::EquipmentLayout_Wrapper(
    const EquipmentLayout_Wrapper& other
) noexcept = default;

EquipmentLayout_Wrapper::EquipmentLayout_Wrapper(
    EquipmentLayout_Wrapper&& other
) noexcept = default;

EquipmentLayout_Wrapper::~EquipmentLayout_Wrapper() noexcept = default;

EquipmentLayout_Wrapper& EquipmentLayout_Wrapper::operator=(
    const EquipmentLayout_Wrapper& other
) noexcept = default;

EquipmentLayout_Wrapper& EquipmentLayout_Wrapper::operator=(
    EquipmentLayout_Wrapper&& other
) noexcept = default;

EquipmentLayout_Wrapper::operator EquipmentLayout_View() const noexcept {
  return EquipmentLayout_View(this->Get());
}

EquipmentLayout_View EquipmentLayout_Wrapper::operator[](
    std::size_t index
) const noexcept {
  EquipmentLayout_View view(this->Get());

  return view[index];
}

EquipmentLayout_Wrapper EquipmentLayout_Wrapper::operator[](
    std::size_t index
) noexcept {
  const auto* const_this = this;

  return const_cast<EquipmentLayout*>((*const_this)[index].Get());
}

EquipmentLayout* EquipmentLayout_Wrapper::Get() noexcept {
  const auto* const_this = this;

  return const_cast<EquipmentLayout*>(const_this->Get());
}

const EquipmentLayout* EquipmentLayout_Wrapper::Get() const noexcept {
  return this->equipment_layout_;
}

void EquipmentLayout_Wrapper::Assign(EquipmentLayout_View src) noexcept {
  EquipmentLayout_1_00* actual_dest =
      reinterpret_cast<EquipmentLayout_1_00*>(this->Get());
  const EquipmentLayout_1_00* actual_src =
      reinterpret_cast<const EquipmentLayout_1_00*>(src.Get());

  *actual_dest = *actual_src;
}

PositionalRectangle* EquipmentLayout_Wrapper::GetPosition() noexcept {
  const auto* const_this = this;

  return const_cast<PositionalRectangle*>(const_this->GetPosition());
}

const PositionalRectangle* EquipmentLayout_Wrapper::GetPosition() const noexcept {
  EquipmentLayout_View view(this->Get());

  return view.GetPosition();
}

unsigned char EquipmentLayout_Wrapper::GetWidth() const noexcept {
  EquipmentLayout_View view(this->Get());

  return view.GetWidth();
}

void EquipmentLayout_Wrapper::SetWidth(unsigned char width) noexcept {
  auto* actual_ptr = reinterpret_cast<EquipmentLayout_1_00*>(this->Get());

  actual_ptr->width = width;
}

unsigned char EquipmentLayout_Wrapper::GetHeight() const noexcept {
  EquipmentLayout_View view(this->Get());

  return view.GetHeight();
}

void EquipmentLayout_Wrapper::SetHeight(unsigned char height) noexcept {
  auto* actual_ptr = reinterpret_cast<EquipmentLayout_1_00*>(this->Get());

  actual_ptr->height = height;
}

} // namespace d2
