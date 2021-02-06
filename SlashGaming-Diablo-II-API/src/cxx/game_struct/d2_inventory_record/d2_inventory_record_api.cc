/**
 * SlashGaming Diablo II Modding API for C++
 * Copyright (C) 2018-2021  Mir Drualga
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

#include "../../../../include/cxx/game_struct/d2_inventory_record/d2_inventory_record_api.hpp"

#include <algorithm>
#include <type_traits>

#include "../../../../include/cxx/game_struct/d2_equipment_layout/d2_equipment_layout_wrapper.hpp"
#include "../../../../include/cxx/game_struct/d2_grid_layout/d2_grid_layout_wrapper.hpp"
#include "../../../../include/cxx/game_struct/d2_positional_rectangle/d2_positional_rectangle_wrapper.hpp"
#include "../../../../include/cxx/game_version.hpp"

namespace d2 {

InventoryRecord_Api::InventoryRecord_Api(
    PositionalRectangle_View position,
    GridLayout_View grid_layout,
    EquipmentLayout_View equipment_slots
) : inventory_record_(
        CreateVariant(position.Get(), grid_layout.Get(), equipment_slots.Get())
    ) {
}

InventoryRecord_Api::InventoryRecord_Api(
    const InventoryRecord_Api& other
) = default;

InventoryRecord_Api::InventoryRecord_Api(
    InventoryRecord_Api&& other
) noexcept = default;

InventoryRecord_Api::~InventoryRecord_Api() = default;

InventoryRecord_Api& InventoryRecord_Api::operator=(
    const InventoryRecord_Api& other
) = default;

InventoryRecord_Api& InventoryRecord_Api::operator=(
    InventoryRecord_Api&& other
) noexcept = default;

InventoryRecord_Api::operator InventoryRecord_View() const noexcept {
  return InventoryRecord_View(this->Get());
}

InventoryRecord_Api::operator InventoryRecord_Wrapper() noexcept {
  return InventoryRecord_Wrapper(this->Get());
}

InventoryRecord* InventoryRecord_Api::Get() noexcept {
  const auto* const_this = this;

  return const_cast<InventoryRecord*>(const_this->Get());
}

const InventoryRecord* InventoryRecord_Api::Get() const noexcept {
  return std::visit(
      [](auto& actual_inventory_record) {
        return reinterpret_cast<const InventoryRecord*>(
            &actual_inventory_record
        );
      },
      this->inventory_record_
  );
}

PositionalRectangle_View InventoryRecord_Api::GetPosition() const noexcept {
  InventoryRecord_View view(this->Get());

  return view.GetPosition();
}

PositionalRectangle_Wrapper InventoryRecord_Api::GetPosition() noexcept {
  InventoryRecord_Wrapper wrapper(this->Get());

  return wrapper.GetPosition();
}

GridLayout_View InventoryRecord_Api::GetGridLayout() const noexcept {
  InventoryRecord_View view(this->Get());

  return view.GetGridLayout();
}

GridLayout_Wrapper InventoryRecord_Api::GetGridLayout() noexcept {
  InventoryRecord_Wrapper wrapper(this->Get());

  return wrapper.GetGridLayout();
}

EquipmentLayout_View
InventoryRecord_Api::GetEquipmentSlots() const noexcept {
  InventoryRecord_View view(this->Get());

  return view.GetEquipmentSlots();
}

EquipmentLayout_Wrapper InventoryRecord_Api::GetEquipmentSlots() noexcept {
  InventoryRecord_Wrapper wrapper(this->Get());

  return wrapper.GetEquipmentSlots();
}

InventoryRecord_Api::ApiVariant InventoryRecord_Api::CreateVariant(
    const PositionalRectangle* position,
    const GridLayout* grid_layout,
    const EquipmentLayout* equipment_slots
) {
  ApiVariant inventory_record;

  inventory_record = InventoryRecord_1_00();

  std::visit(
      [=](auto& actual_inventory_record) {
        using InventoryRecord_T = std::remove_reference_t<
            decltype(actual_inventory_record)
        >;
        using PositionalRectangle_T = std::remove_pointer_t<
            decltype(InventoryRecord_T::position)
        >;
        using GridLayout_T = std::remove_pointer_t<
            decltype(InventoryRecord_T::grid_layout)
        >;
        using EquipmentLayout_T = std::remove_extent_t<
            decltype(InventoryRecord_T::equipment_slots)
        >;
        using EquipmentSlots_A = decltype(InventoryRecord_T::equipment_slots);

        constexpr std::size_t kNumEquipmentSlots =
            std::extent_v<EquipmentSlots_A>;

        const PositionalRectangle_T* actual_src_positional_rectangle =
            reinterpret_cast<const PositionalRectangle_T*>(position);
        const GridLayout_T* actual_src_grid_layout =
            reinterpret_cast<const GridLayout_T*>(grid_layout);
        const EquipmentLayout_T* actual_src_equipment_slots =
            reinterpret_cast<const EquipmentLayout_T*>(equipment_slots);

        actual_inventory_record.position = *actual_src_positional_rectangle;
        actual_inventory_record.grid_layout = *actual_src_grid_layout;

        std::copy_n(
            actual_src_equipment_slots,
            kNumEquipmentSlots,
            actual_inventory_record.equipment_slots
        );
      },
      inventory_record
  );

  return inventory_record;
}

} // namespace d2
