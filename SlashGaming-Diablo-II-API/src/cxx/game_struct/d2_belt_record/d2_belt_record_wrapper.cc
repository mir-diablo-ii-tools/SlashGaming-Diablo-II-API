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

#include "../../../../include/cxx/game_struct/d2_belt_record/d2_belt_record_wrapper.hpp"

#include <algorithm>

#include "d2_belt_record_impl.hpp"
#include "../../../../include/cxx/game_struct/d2_positional_rectangle/d2_positional_rectangle_wrapper.hpp"

namespace d2 {

BeltRecord_Wrapper::BeltRecord_Wrapper(
    BeltRecord* ptr
) noexcept :
    ptr_(ptr) {
}

BeltRecord_Wrapper::BeltRecord_Wrapper(
    const BeltRecord_Wrapper& other
) noexcept = default;

BeltRecord_Wrapper::BeltRecord_Wrapper(
    BeltRecord_Wrapper&& other
) noexcept = default;

BeltRecord_Wrapper::~BeltRecord_Wrapper() noexcept = default;

BeltRecord_Wrapper& BeltRecord_Wrapper::operator=(
    const BeltRecord_Wrapper& other
) noexcept = default;

BeltRecord_Wrapper& BeltRecord_Wrapper::operator=(
    BeltRecord_Wrapper&& other
) noexcept = default;

BeltRecord_Wrapper::operator BeltRecord_View() const noexcept {
  return BeltRecord_View(this->Get());
}

BeltRecord* BeltRecord_Wrapper::Get() noexcept {
  const auto* const_this = this;

  return const_cast<BeltRecord*>(const_this->Get());
}

const BeltRecord* BeltRecord_Wrapper::Get() const noexcept {
  return this->ptr_;
}

void BeltRecord_Wrapper::Copy(BeltRecord_View src) noexcept {
  this->SetNumSlots(src.GetNumSlots());

  std::size_t num_equipment_slots =
      sizeof(BeltRecord_1_00::slot_positions)
          / sizeof(BeltRecord_1_00::slot_positions[0]);

  std::copy_n(
      reinterpret_cast<const BeltRecord_1_00*>(src.GetSlotPositions()),
      num_equipment_slots,
      reinterpret_cast<BeltRecord_1_00*>(this->GetSlotPositions())
  );
}

PositionalRectangle* BeltRecord_Wrapper::GetSlotPosition(
    std::size_t index
) noexcept {
  const auto* const_this = this;

  return const_cast<PositionalRectangle*>(
      const_this->GetSlotPosition(index)
  );
}

const PositionalRectangle* BeltRecord_Wrapper::GetSlotPosition(
    std::size_t index
) const noexcept {
  BeltRecord_View view(this->Get());

  return view.GetSlotPosition(index);
}

std::uint_least8_t BeltRecord_Wrapper::GetNumSlots() const noexcept {
  BeltRecord_View view(this->Get());

  return view.GetNumSlots();
}

void BeltRecord_Wrapper::SetNumSlots(std::uint_least8_t value) noexcept {
  auto* actual_ptr = reinterpret_cast<BeltRecord_1_00*>(this->Get());

  actual_ptr->num_slots = value;
}

PositionalRectangle* BeltRecord_Wrapper::GetSlotPositions() noexcept {
  const auto* const_this = this;

  return const_cast<PositionalRectangle*>(const_this->GetSlotPositions());
}

const PositionalRectangle* BeltRecord_Wrapper::GetSlotPositions() const noexcept {
  BeltRecord_View view(this->Get());

  return view.GetSlotPositions();
}

} // namespace d2
