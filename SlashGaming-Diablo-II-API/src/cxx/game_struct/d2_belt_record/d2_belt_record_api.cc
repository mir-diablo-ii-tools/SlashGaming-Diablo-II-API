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

#include "../../../../include/cxx/game_struct/d2_belt_record/d2_belt_record_api.hpp"

#include <algorithm>
#include <type_traits>

#include "../../../../include/cxx/game_struct/d2_positional_rectangle/d2_positional_rectangle_wrapper.hpp"
#include "../../../../include/cxx/game_version.hpp"

namespace d2 {
namespace {

template <typename BeltRecord_T>
static std::unique_ptr<BeltRecord_T> CreatePtr(
    mapi::Undefined* reserved_00__set_to_nullptr,
    std::int_least8_t num_slots,
    const PositionalRectangle* slot_positions
) {
  using SlotPosition_T = decltype(BeltRecord_T::slot_positions);

  std::unique_ptr belt_record = std::make_unique<BeltRecord_T>();

  belt_record->unknown_0x00 = reserved_00__set_to_nullptr;
  belt_record->num_slots = num_slots;

  std::copy_n(
      reinterpret_cast<
          const std::remove_extent_t<SlotPosition_T>*
      >(slot_positions),
      std::extent_v<SlotPosition_T>,
      belt_record->slot_positions
  );

  return belt_record;
}

} // namespace

BeltRecord_Api::BeltRecord_Api(
    mapi::Undefined* reserved_00__set_to_nullptr,
    std::uint_least8_t num_slots,
    const PositionalRectangle* slot_positions
) : belt_record_(
        CreateVariant(
            reserved_00__set_to_nullptr,
            num_slots,
            slot_positions
        )
    ) {
}

BeltRecord_Api::BeltRecord_Api(
    const BeltRecord_Api& other
) : BeltRecord_Api(
        nullptr,
        other.GetNumSlots(),
        other.GetSlotPositions()
    ) {
}

BeltRecord_Api::BeltRecord_Api(BeltRecord_Api&& other) noexcept = default;

BeltRecord_Api::~BeltRecord_Api() = default;

BeltRecord_Api& BeltRecord_Api::operator=(const BeltRecord_Api& other) {
  *this = BeltRecord_Api(
      nullptr,
      other.GetNumSlots(),
      other.GetSlotPositions()
  );

  return *this;
}

BeltRecord_Api& BeltRecord_Api::operator=(
    BeltRecord_Api&& other
) noexcept = default;

BeltRecord_Api::operator BeltRecord_View() const noexcept {
  return BeltRecord_View(this->Get());
}

BeltRecord_Api::operator BeltRecord_Wrapper() noexcept {
  return BeltRecord_Wrapper(this->Get());
}

BeltRecord* BeltRecord_Api::Get() noexcept {
  const auto* const_this = this;

  return const_cast<BeltRecord*>(const_this->Get());
}

const BeltRecord* BeltRecord_Api::Get() const noexcept {
  auto& actual_belt_record =
      std::get<unique_ptr_1_00>(this->belt_record_);

  return reinterpret_cast<const BeltRecord*>(actual_belt_record.get());
}

void BeltRecord_Api::Assign(BeltRecord_View src) noexcept {
  BeltRecord_Wrapper wrapper(this->Get());

  wrapper.Assign(src);
}

std::uint_least8_t BeltRecord_Api::GetNumSlots() const noexcept {
  BeltRecord_View view(this->Get());

  return view.GetNumSlots();
}

void BeltRecord_Api::SetNumSlots(std::int_least8_t num_slots) noexcept {
  BeltRecord_Wrapper wrapper(this->Get());

  return wrapper.SetNumSlots(num_slots);
}

PositionalRectangle* BeltRecord_Api::GetSlotPositions() noexcept {
  BeltRecord_Wrapper wrapper(this->Get());

  return wrapper.GetSlotPositions();
}

const PositionalRectangle* BeltRecord_Api::GetSlotPositions() const noexcept {
  BeltRecord_View view(this->Get());

  return view.GetSlotPositions();
}

BeltRecord_Api::ptr_variant BeltRecord_Api::CreateVariant(
    mapi::Undefined* reserved_00__set_to_nullptr,
    std::int_least8_t num_slots,
    const PositionalRectangle* slot_positions
) {
  return CreatePtr<BeltRecord_1_00>(
      nullptr,
      num_slots,
      slot_positions
  );
}

} // namespace d2
