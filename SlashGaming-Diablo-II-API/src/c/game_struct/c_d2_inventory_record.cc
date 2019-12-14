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

#include "../../../include/c/game_struct/d2_inventory_record.h"

#include <cstdint>

#include "../../../include/cxx/game_struct/d2_inventory_record.hpp"
#include "../../cxx/game_struct/d2_inventory_record/d2_inventory_record_impl.hpp"

D2_InventoryRecord* D2_InventoryRecord_CreateWithRecord(
    const D2_PositionalRectangle* position,
    const D2_GridLayout* grid_layout,
    const D2_EquipmentLayout* equipment_slots
) {
  const auto* actual_position =
      reinterpret_cast<const d2::PositionalRectangle*>(position);
  const auto* actual_grid_layout =
      reinterpret_cast<const d2::GridLayout*>(grid_layout);
  const auto* actual_equipment_slots =
      reinterpret_cast<const d2::EquipmentLayout*>(equipment_slots);

  auto* actual_inventory_record = d2::CreateInventoryRecord(
      actual_position,
      actual_grid_layout,
      actual_equipment_slots
  );

  return reinterpret_cast<D2_InventoryRecord*>(actual_inventory_record);
}

void D2_InventoryRecord_Destroy(
    D2_InventoryRecord* inventory_record
) {
  auto* actual_inventory_record =
      reinterpret_cast<d2::InventoryRecord*>(inventory_record);

  d2::DestroyInventoryRecord(actual_inventory_record);
}

D2_InventoryRecord* D2_InventoryRecord_GetAt(
    D2_InventoryRecord* inventory_record,
    std::size_t index
) {
  d2::InventoryRecord_Wrapper inventory_record_wrapper(
      reinterpret_cast<d2::InventoryRecord*>(inventory_record)
  );

  return reinterpret_cast<D2_InventoryRecord*>(
      inventory_record_wrapper[index].Get()
  );
}

const D2_InventoryRecord* D2_BeltRecord_GetConstAt(
    const D2_InventoryRecord* inventory_record,
    std::size_t index
) {
  d2::InventoryRecord_View inventory_record_view(
      reinterpret_cast<const d2::InventoryRecord*>(inventory_record)
  );

  return reinterpret_cast<const D2_InventoryRecord*>(
      inventory_record_view[index].Get()
  );
}

void D2_InventoryRecord_Copy(
    D2_InventoryRecord* dest,
    const D2_InventoryRecord* src
) {
  auto* actual_dest = reinterpret_cast<d2::InventoryRecord*>(dest);
  const auto* actual_src = reinterpret_cast<const d2::InventoryRecord*>(src);

  d2::InventoryRecord_Wrapper dest_wrapper(actual_dest);
  dest_wrapper.Copy(actual_src);
}

D2_EquipmentLayout* D2_InventoryRecord_GetEquipmentSlot(
    D2_InventoryRecord* inventory_record,
    size_t index
) {
  auto* actual_inventory_record = reinterpret_cast<d2::InventoryRecord*>(
      inventory_record
  );

  d2::InventoryRecord_Wrapper wrapper(actual_inventory_record);

  return reinterpret_cast<D2_EquipmentLayout*>(
      wrapper.GetEquipmentSlot(index)
  );
}

const D2_EquipmentLayout*
D2_InventoryRecord_GetConstEquipmentSlot(
    const D2_InventoryRecord* inventory_record,
    size_t index
) {
  auto* actual_inventory_record =
      reinterpret_cast<const d2::InventoryRecord*>(inventory_record);

  d2::InventoryRecord_View view(actual_inventory_record);

  return reinterpret_cast<const D2_EquipmentLayout*>(
      view.GetEquipmentSlot(index)
  );
}

D2_PositionalRectangle* D2_InventoryRecord_GetPosition(
    D2_InventoryRecord* inventory_record
) {
  auto* actual_inventory_record = reinterpret_cast<d2::InventoryRecord*>(
      inventory_record
  );

  d2::InventoryRecord_Wrapper wrapper(actual_inventory_record);

  return reinterpret_cast<D2_PositionalRectangle*>(wrapper.GetPosition());
}

const D2_PositionalRectangle* D2_InventoryRecord_GetConstPosition(
    const D2_InventoryRecord* inventory_record
) {
  auto* actual_inventory_record =
      reinterpret_cast<const d2::InventoryRecord*>(inventory_record);

  d2::InventoryRecord_View view(actual_inventory_record);

  return reinterpret_cast<const D2_PositionalRectangle*>(view.GetPosition());
}

D2_GridLayout* D2_InventoryRecord_GetGridLayout(
    D2_InventoryRecord* inventory_record
) {
  auto* actual_inventory_record = reinterpret_cast<d2::InventoryRecord*>(
      inventory_record
  );

  d2::InventoryRecord_Wrapper wrapper(actual_inventory_record);

  return reinterpret_cast<D2_GridLayout*>(wrapper.GetGridLayout());
}

const D2_GridLayout* D2_InventoryRecord_GetConstGridLayout(
    const D2_InventoryRecord* inventory_record
) {
  auto* actual_inventory_record =
      reinterpret_cast<const d2::InventoryRecord*>(inventory_record);

  d2::InventoryRecord_View view(actual_inventory_record);

  return reinterpret_cast<const D2_GridLayout*>(view.GetGridLayout());
}

D2_EquipmentLayout* D2_InventoryRecord_GetEquipmentSlots(
    D2_InventoryRecord* inventory_record
) {
  auto* actual_inventory_record = reinterpret_cast<d2::InventoryRecord*>(
      inventory_record
  );

  d2::InventoryRecord_Wrapper wrapper(actual_inventory_record);

  return reinterpret_cast<D2_EquipmentLayout*>(wrapper.GetEquipmentSlots());
}

const D2_EquipmentLayout*
D2_InventoryRecord_GetConstEquipmentSlots(
    const D2_InventoryRecord* inventory_record
) {
  auto* actual_inventory_record =
      reinterpret_cast<const d2::InventoryRecord*>(inventory_record);

  d2::InventoryRecord_View view(actual_inventory_record);

  return reinterpret_cast<const D2_EquipmentLayout*>(view.GetEquipmentSlots());
}
