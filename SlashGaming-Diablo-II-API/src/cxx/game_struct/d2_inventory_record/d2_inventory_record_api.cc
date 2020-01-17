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

#include "../../../../include/cxx/game_struct/d2_inventory_record/d2_inventory_record_api.hpp"

#include "d2_inventory_record_impl.hpp"
#include "../../../../include/cxx/game_struct/d2_equipment_layout/d2_equipment_layout_wrapper.hpp"
#include "../../../../include/cxx/game_struct/d2_grid_layout/d2_grid_layout_wrapper.hpp"
#include "../../../../include/cxx/game_struct/d2_positional_rectangle/d2_positional_rectangle_wrapper.hpp"
#include "../../../../include/cxx/game_version.hpp"

namespace d2 {
namespace {

using unique_ptr_1_00 = std::unique_ptr<InventoryRecord_1_00>;

using InventoryRecordVariant = std::variant<
    unique_ptr_1_00
>;

InventoryRecordVariant CreateVariant(
    PositionalRectangle_View position,
    GridLayout_View grid_layout,
    const EquipmentLayout* equipment_slots
) {
  InventoryRecord* inventory_record = CreateInventoryRecord(
      position.Get(),
      grid_layout.Get(),
      equipment_slots
  );

  return unique_ptr_1_00(
      reinterpret_cast<InventoryRecord_1_00*>(inventory_record)
  );
}

} // namespace

InventoryRecord_API::InventoryRecord_API(
    PositionalRectangle_View position,
    GridLayout_View grid_layout,
    const EquipmentLayout* equipment_slots
) : inventory_record_(
        CreateVariant(position, grid_layout, equipment_slots)
    ) {
}

InventoryRecord_API::InventoryRecord_API(
    const InventoryRecord_API& other
) : InventoryRecord_API(
        other.GetPosition(),
        other.GetGridLayout(),
        other.GetEquipmentSlots()
    ) {
}

InventoryRecord_API::InventoryRecord_API(
    InventoryRecord_API&& other
) noexcept = default;

InventoryRecord_API::~InventoryRecord_API() = default;

InventoryRecord_API& InventoryRecord_API::operator=(
    const InventoryRecord_API& other
) {
  *this = InventoryRecord_API(
      other.GetPosition(),
      other.GetGridLayout(),
      other.GetEquipmentSlots()
  );

  return *this;
}

InventoryRecord_API& InventoryRecord_API::operator=(
    InventoryRecord_API&& other
) noexcept = default;

InventoryRecord_API::operator InventoryRecord_View() const noexcept {
  return InventoryRecord_View(this->Get());
}

InventoryRecord_API::operator InventoryRecord_Wrapper() noexcept {
  return InventoryRecord_Wrapper(this->Get());
}

InventoryRecord* InventoryRecord_API::Get() noexcept {
  const auto* const_this = this;

  return const_cast<InventoryRecord*>(const_this->Get());
}

const InventoryRecord* InventoryRecord_API::Get() const noexcept {
  auto& actual_inventory_record =
      std::get<unique_ptr_1_00>(this->inventory_record_);

  return reinterpret_cast<const InventoryRecord*>(actual_inventory_record.get());
}

PositionalRectangle* InventoryRecord_API::GetPosition() noexcept {
  InventoryRecord_Wrapper wrapper(this->Get());

  return wrapper.GetPosition();
}

const PositionalRectangle* InventoryRecord_API::GetPosition() const noexcept {
  InventoryRecord_View view(this->Get());

  return view.GetPosition();
}

GridLayout* InventoryRecord_API::GetGridLayout() noexcept {
  InventoryRecord_Wrapper wrapper(this->Get());

  return wrapper.GetGridLayout();
}

const GridLayout* InventoryRecord_API::GetGridLayout() const noexcept {
  InventoryRecord_View view(this->Get());

  return view.GetGridLayout();
}

EquipmentLayout* InventoryRecord_API::GetEquipmentSlots() noexcept {
  InventoryRecord_Wrapper wrapper(this->Get());

  return wrapper.GetEquipmentSlots();
}

const EquipmentLayout*
InventoryRecord_API::GetEquipmentSlots() const noexcept {
  InventoryRecord_View view(this->Get());

  return view.GetEquipmentSlots();
}

EquipmentLayout* InventoryRecord_API::GetEquipmentSlot(
    std::size_t index
) noexcept {
  InventoryRecord_Wrapper wrapper(this->Get());

  return wrapper.GetEquipmentSlot(index);
}

const EquipmentLayout* InventoryRecord_API::GetEquipmentSlot(
    std::size_t index
) const noexcept {
  InventoryRecord_View view(this->Get());

  return view.GetEquipmentSlot(index);
}

InventoryRecord* CreateInventoryRecord(
    const PositionalRectangle* position,
    const GridLayout* grid_layout,
    const EquipmentLayout* equipment_slots
) {
  InventoryRecord* inventory_record;
  std::size_t num_equipment_slots;

  inventory_record = reinterpret_cast<InventoryRecord*>(new InventoryRecord_1_00());
  num_equipment_slots = sizeof(InventoryRecord_1_00::equipment_slots)
      / sizeof(InventoryRecord_1_00::equipment_slots[0]);

  // Set all the values of the struct.
  InventoryRecord_Wrapper wrapper(inventory_record);

  PositionalRectangle_Wrapper position_wrapper(wrapper.GetPosition());
  position_wrapper.Copy(position);

  GridLayout_Wrapper grid_layout_wrapper(wrapper.GetGridLayout());
  grid_layout_wrapper.Copy(grid_layout);

  std::copy_n(
      reinterpret_cast<const EquipmentLayout_1_00*>(equipment_slots),
      num_equipment_slots,
      reinterpret_cast<EquipmentLayout_1_00*>(wrapper.GetEquipmentSlots())
  );

  return inventory_record;
}

void DestroyInventoryRecord(InventoryRecord* inventory_record) {
  d2::GameVersion running_game_version = d2::GetRunningGameVersionId();

  auto* actual_inventory_record =
      reinterpret_cast<InventoryRecord_1_00*>(inventory_record);

  delete actual_inventory_record;
}

} // namespace d2
