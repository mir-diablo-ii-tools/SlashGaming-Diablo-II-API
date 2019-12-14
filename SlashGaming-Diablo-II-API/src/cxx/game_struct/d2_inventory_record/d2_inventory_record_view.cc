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

#include "../../../../include/cxx/game_struct/d2_inventory_record/d2_inventory_record_view.hpp"

#include "d2_inventory_record_impl.hpp"

namespace d2 {

InventoryRecord_View::InventoryRecord_View(
    const InventoryRecord* ptr
) noexcept :
    ptr_(ptr) {
}

InventoryRecord_View::InventoryRecord_View(
    const InventoryRecord_View& other
) noexcept = default;

InventoryRecord_View::InventoryRecord_View(
    InventoryRecord_View&& other
) noexcept = default;

InventoryRecord_View::~InventoryRecord_View() noexcept = default;

InventoryRecord_View& InventoryRecord_View::operator=(
    const InventoryRecord_View& other
) noexcept = default;

InventoryRecord_View& InventoryRecord_View::operator=(
    InventoryRecord_View&& other
) noexcept = default;

InventoryRecord_View InventoryRecord_View::operator[](
    std::size_t index
) const noexcept {
  const auto* actual_ptr =
      reinterpret_cast<const InventoryRecord_1_00*>(this->Get());

  return reinterpret_cast<const InventoryRecord*>(&actual_ptr[index]);
}

const InventoryRecord* InventoryRecord_View::Get() const noexcept {
  return this->ptr_;
}

const PositionalRectangle*
InventoryRecord_View::GetPosition() const noexcept {
  const auto* actual_ptr =
      reinterpret_cast<const InventoryRecord_1_00*>(this->Get());

  return reinterpret_cast<const PositionalRectangle*>(&actual_ptr->position);
}

const GridLayout* InventoryRecord_View::GetGridLayout() const noexcept {
  const auto* actual_ptr =
      reinterpret_cast<const InventoryRecord_1_00*>(this->Get());

  return reinterpret_cast<const GridLayout*>(&actual_ptr->grid_layout);
}

const EquipmentLayout*
InventoryRecord_View::GetEquipmentSlots() const noexcept {
  const auto* actual_ptr =
      reinterpret_cast<const InventoryRecord_1_00*>(this->Get());

  return reinterpret_cast<const EquipmentLayout*>(
      &actual_ptr->equipment_slots
  );
}

const EquipmentLayout* InventoryRecord_View::GetEquipmentSlot(
    std::size_t index
) const noexcept {
  const auto* actual_ptr =
      reinterpret_cast<const InventoryRecord_1_00*>(this->Get());

  return reinterpret_cast<const EquipmentLayout*>(
      &actual_ptr->equipment_slots[index]
  );
}

} // namespace d2
