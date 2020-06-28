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

#include "../../../../include/cxx/game_struct/d2_inventory_record/d2_inventory_record_wrapper.hpp"

#include "../../../../include/cxx/game_struct/d2_equipment_layout/d2_equipment_layout_wrapper.hpp"
#include "../../../../include/cxx/game_struct/d2_grid_layout/d2_grid_layout_wrapper.hpp"
#include "../../../../include/cxx/game_struct/d2_positional_rectangle/d2_positional_rectangle_wrapper.hpp"

namespace d2 {

InventoryRecord_Wrapper::InventoryRecord_Wrapper(
    InventoryRecord* inventory_record
) noexcept :
    inventory_record_([inventory_record]() {
      return reinterpret_cast<InventoryRecord_1_00*>(
          inventory_record
      );
    }()) {
}

InventoryRecord_Wrapper::InventoryRecord_Wrapper(
    const InventoryRecord_Wrapper& other
) noexcept = default;

InventoryRecord_Wrapper::InventoryRecord_Wrapper(
    InventoryRecord_Wrapper&& other
) noexcept = default;

InventoryRecord_Wrapper::~InventoryRecord_Wrapper() noexcept = default;

InventoryRecord_Wrapper& InventoryRecord_Wrapper::operator=(
    const InventoryRecord_Wrapper& other
) noexcept = default;

InventoryRecord_Wrapper& InventoryRecord_Wrapper::operator=(
    InventoryRecord_Wrapper&& other
) noexcept = default;

InventoryRecord_Wrapper::operator InventoryRecord_View() const noexcept {
  return InventoryRecord_View(this->Get());
}

InventoryRecord_View InventoryRecord_Wrapper::operator[](
    std::size_t index
) const noexcept {
  InventoryRecord_View view(this->Get());

  return view[index];
}

InventoryRecord_Wrapper InventoryRecord_Wrapper::operator[](
    std::size_t index
) noexcept {
  const auto* const_this = this;

  return const_cast<InventoryRecord*>((*const_this)[index].Get());
}

InventoryRecord* InventoryRecord_Wrapper::Get() noexcept {
  const auto* const_this = this;

  return const_cast<InventoryRecord*>(const_this->Get());
}

const InventoryRecord* InventoryRecord_Wrapper::Get() const noexcept {
  return std::visit(
      [](auto& actual_inventory_record) {
        return reinterpret_cast<const InventoryRecord*>(actual_inventory_record);
      },
      this->inventory_record_
  );
}

void InventoryRecord_Wrapper::Assign(InventoryRecord_View src) noexcept {
  std::visit(
      [&src](auto& actual_dest) {
        using Dest_T = decltype(actual_dest);
        using ActualSrc_T = const std::remove_pointer_t<
            std::remove_reference_t<Dest_T>
        >*;

        const auto* actual_src = reinterpret_cast<ActualSrc_T>(src.Get());

        *actual_dest = *actual_src;
      },
      this->inventory_record_
  );
}

PositionalRectangle* InventoryRecord_Wrapper::GetPosition() noexcept {
  const auto* const_this = this;

  return const_cast<PositionalRectangle*>(const_this->GetPosition());
}

const PositionalRectangle*
InventoryRecord_Wrapper::GetPosition() const noexcept {
  InventoryRecord_View view(this->Get());

  return view.GetPosition();
}

GridLayout* InventoryRecord_Wrapper::GetGridLayout() noexcept {
  const auto* const_this = this;

  return const_cast<GridLayout*>(const_this->GetGridLayout());
}

const GridLayout* InventoryRecord_Wrapper::GetGridLayout() const noexcept {
  InventoryRecord_View view(this->Get());

  return view.GetGridLayout();
}

EquipmentLayout* InventoryRecord_Wrapper::GetEquipmentSlots() noexcept {
  const auto* const_this = this;

  return const_cast<EquipmentLayout*>(const_this->GetEquipmentSlots());
}

const EquipmentLayout*
InventoryRecord_Wrapper::GetEquipmentSlots() const noexcept {
  InventoryRecord_View view(this->Get());

  return view.GetEquipmentSlots();
}

} // namespace d2
