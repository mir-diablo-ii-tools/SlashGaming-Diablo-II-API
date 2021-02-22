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

#include "../../../../include/cxx/game_struct/d2_equipment_layout/d2_equipment_layout_api.hpp"

#include "../../../../include/cxx/game_struct/d2_positional_rectangle/d2_positional_rectangle_wrapper.hpp"
#include "../../../../include/cxx/game_version.hpp"

namespace d2 {

EquipmentLayout_Api::EquipmentLayout_Api(
    PositionalRectangle_View position,
    unsigned char width,
    unsigned char height
) : equipment_layout_(CreateVariant(position.Get(), width, height)) {
}

EquipmentLayout_Api::ApiVariant EquipmentLayout_Api::CreateVariant(
    const PositionalRectangle* position,
    unsigned char width,
    unsigned char height
) {
  ApiVariant equipment_layout;

  equipment_layout = EquipmentLayout_1_00();

  std::visit(
      [position, width, height](auto& actual_equipment_layout) {
        using EquipmentLayout_T = std::remove_reference_t<
            decltype(actual_equipment_layout)
        >;
        using PositionalRectangle_T = decltype(EquipmentLayout_T::position);

        const PositionalRectangle_T* actual_src_position =
            reinterpret_cast<const PositionalRectangle_T*>(position);

        actual_equipment_layout.position = *actual_src_position;
        actual_equipment_layout.width = width;
        actual_equipment_layout.height = height;
      },
      equipment_layout
  );

  return equipment_layout;
}

} // namespace d2
