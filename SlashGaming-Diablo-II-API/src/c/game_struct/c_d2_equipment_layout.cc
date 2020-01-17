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

#include "../../../include/c/game_struct/d2_equipment_layout.h"

#include <cstdint>

#include "../../../include/cxx/game_struct/d2_equipment_layout.hpp"
#include "../../cxx/game_struct/d2_equipment_layout/d2_equipment_layout_impl.hpp"

D2_EquipmentLayout* D2_EquipmentLayout_CreateWithLayout(
    const D2_PositionalRectangle* position,
    int_least8_t width,
    int_least8_t height
) {
  const auto* actual_position =
      reinterpret_cast<const d2::PositionalRectangle*>(position);

  auto* actual_equipment_layout = d2::CreateEquipmentLayout(
      actual_position,
      width,
      height
  );

  return reinterpret_cast<D2_EquipmentLayout*>(actual_equipment_layout);
}

void D2_EquipmentLayout_Destroy(
    D2_EquipmentLayout* equipment_layout
) {
  auto* actual_equipment_layout =
      reinterpret_cast<d2::EquipmentLayout*>(equipment_layout);

  d2::DestroyEquipmentLayout(actual_equipment_layout);
}

D2_PositionalRectangle* D2_EquipmentLayout_GetPosition(
    D2_EquipmentLayout* equipment_layout
) {
  auto* actual_equipment_layout =
      reinterpret_cast<d2::EquipmentLayout*>(equipment_layout);

  d2::EquipmentLayout_Wrapper wrapper(actual_equipment_layout);

  return reinterpret_cast<D2_PositionalRectangle*>(wrapper.GetPosition());
}

const D2_PositionalRectangle* D2_EquipmentLayout_GetConstPosition(
    const D2_EquipmentLayout* equipment_layout
) {
  const auto* actual_equipment_layout =
      reinterpret_cast<const d2::EquipmentLayout*>(equipment_layout);

  d2::EquipmentLayout_View view(actual_equipment_layout);

  return reinterpret_cast<const D2_PositionalRectangle*>(
      view.GetPosition()
  );
}

std::uint_least8_t D2_EquipmentLayout_GetWidth(
    const D2_EquipmentLayout* equipment_layout
){
  const auto* actual_equipment_layout =
      reinterpret_cast<const d2::EquipmentLayout*>(equipment_layout);

  d2::EquipmentLayout_View view(actual_equipment_layout);

  return view.GetWidth();
}

void D2_EquipmentLayout_SetWidth(
    D2_EquipmentLayout* equipment_layout,
    std::uint_least8_t value
) {
  auto* actual_equipment_layout = reinterpret_cast<d2::EquipmentLayout*>(
      equipment_layout
  );

  d2::EquipmentLayout_Wrapper wrapper(actual_equipment_layout);

  return wrapper.SetWidth(value);
}

std::uint_least8_t D2_EquipmentLayout_GetHeight(
    const D2_EquipmentLayout* equipment_layout
){
  const auto* actual_equipment_layout =
      reinterpret_cast<const d2::EquipmentLayout*>(equipment_layout);

  d2::EquipmentLayout_View view(actual_equipment_layout);

  return view.GetHeight();
}

void D2_EquipmentLayout_SetHeight(
    D2_EquipmentLayout* equipment_layout,
    std::uint_least8_t value
) {
  auto* actual_equipment_layout = reinterpret_cast<d2::EquipmentLayout*>(
      equipment_layout
  );

  d2::EquipmentLayout_Wrapper wrapper(actual_equipment_layout);

  return wrapper.SetHeight(value);
}
