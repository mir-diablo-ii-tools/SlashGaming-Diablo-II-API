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

#include "../../../include/c/game_struct/d2_belt_record.h"

#include <cstdint>

#include "../../../include/cxx/game_struct/d2_belt_record.hpp"
#include "../../cxx/game_struct/d2_belt_record/d2_belt_record_impl.hpp"
#include "../../../include/cxx/game_undefined.hpp"

D2_BeltRecord* D2_BeltRecord_CreateWithRecord(
    MAPI_Undefined* reserved_00__set_to_nullptr,
    uint_least8_t num_slots,
    const D2_PositionalRectangle* slot_positions
) {
  auto* actual_reserved_00__set_to_nullptr =
      reinterpret_cast<mapi::Undefined*>(reserved_00__set_to_nullptr);
  const auto* actual_slot_positions =
      reinterpret_cast<const d2::PositionalRectangle*>(slot_positions);

  auto* actual_belt_record = d2::CreateBeltRecord(
      actual_reserved_00__set_to_nullptr,
      num_slots,
      actual_slot_positions
  );

  return reinterpret_cast<D2_BeltRecord*>(actual_belt_record);
}

void D2_BeltRecord_Destroy(
    D2_BeltRecord* belt_record
) {
  auto* actual_belt_record =
      reinterpret_cast<d2::BeltRecord*>(belt_record);

  d2::DestroyBeltRecord(actual_belt_record);
}

D2_BeltRecord* D2_BeltRecord_GetAt(
    D2_BeltRecord* belt_record,
    std::size_t index
) {
  d2::BeltRecord_Wrapper belt_record_wrapper(
      reinterpret_cast<d2::BeltRecord*>(belt_record)
  );

  return reinterpret_cast<D2_BeltRecord*>(
      belt_record_wrapper[index].Get()
  );
}

const D2_BeltRecord* D2_BeltRecord_GetConstAt(
    const D2_BeltRecord* belt_record,
    std::size_t index
) {
  d2::BeltRecord_View belt_record_view(
      reinterpret_cast<const d2::BeltRecord*>(belt_record)
  );

  return reinterpret_cast<const D2_BeltRecord*>(
      belt_record_view[index].Get()
  );
}

void D2_BeltRecord_Copy(
    D2_BeltRecord* dest,
    const D2_BeltRecord* src
) {
  auto* actual_dest = reinterpret_cast<d2::BeltRecord*>(dest);
  const auto* actual_src = reinterpret_cast<const d2::BeltRecord*>(src);

  d2::BeltRecord_Wrapper dest_wrapper(actual_dest);
  dest_wrapper.Copy(actual_src);
}

D2_PositionalRectangle* D2_BeltRecord_GetSlotPosition(
    D2_BeltRecord* belt_record,
    size_t index
) {
  auto* actual_belt_record = reinterpret_cast<d2::BeltRecord*>(
      belt_record
  );

  d2::BeltRecord_Wrapper wrapper(actual_belt_record);

  return reinterpret_cast<D2_PositionalRectangle*>(
      wrapper.GetSlotPosition(index)
  );
}

const D2_PositionalRectangle* D2_BeltRecord_GetConstSlotPosition(
    const D2_BeltRecord* belt_record,
    size_t index
) {
  const auto* actual_belt_record = reinterpret_cast<const d2::BeltRecord*>(
      belt_record
  );

  d2::BeltRecord_View view(actual_belt_record);

  return reinterpret_cast<const D2_PositionalRectangle*>(
      view.GetSlotPosition(index)
  );
}

std::int_least8_t D2_BeltRecord_GetNumSlots(
    D2_BeltRecord* belt_record
) {
  const auto* actual_belt_record = reinterpret_cast<const d2::BeltRecord*>(
      belt_record
  );

  d2::BeltRecord_View view(actual_belt_record);

  return view.GetNumSlots();
}

void D2_BeltRecord_SetNumSlots(
    D2_BeltRecord* belt_record,
    std::int_least8_t value
) {
  auto* actual_belt_record = reinterpret_cast<d2::BeltRecord*>(
      belt_record
  );

  d2::BeltRecord_Wrapper wrapper(actual_belt_record);

  wrapper.SetNumSlots(value);
}

D2_PositionalRectangle* D2_BeltRecord_GetSlotPositions(
    D2_BeltRecord* belt_record
) {
  auto* actual_belt_record = reinterpret_cast<d2::BeltRecord*>(
      belt_record
  );

  d2::BeltRecord_Wrapper wrapper(actual_belt_record);

  return reinterpret_cast<D2_PositionalRectangle*>(
      wrapper.GetSlotPositions()
  );
}

const D2_PositionalRectangle* D2_BeltRecord_GetConstSlotPositions(
    const D2_BeltRecord* belt_record
) {
  const auto* actual_belt_record = reinterpret_cast<const d2::BeltRecord*>(
      belt_record
  );

  d2::BeltRecord_View view(actual_belt_record);

  return reinterpret_cast<const D2_PositionalRectangle*>(
      view.GetSlotPositions()
  );
}
