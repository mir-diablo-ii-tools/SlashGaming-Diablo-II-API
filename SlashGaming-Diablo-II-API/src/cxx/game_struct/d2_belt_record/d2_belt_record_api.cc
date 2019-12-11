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

#include "../../../../include/cxx/game_struct/d2_belt_record/d2_belt_record_api.hpp"

#include "d2_belt_record_impl.hpp"
#include "../../../../include/cxx/game_struct/d2_positional_rectangle/d2_positional_rectangle_wrapper.hpp"
#include "../../../../include/cxx/game_version.hpp"

namespace d2 {
namespace {

using unique_ptr_1_00 = std::unique_ptr<BeltRecord_1_00>;

using BeltRecordVariant = std::variant<
    unique_ptr_1_00
>;

BeltRecordVariant CreateVariant(
    mapi::Undefined* reserved_00__set_to_nullptr,
    std::int_least8_t num_slots,
    const PositionalRectangle* slot_positions
) {
  BeltRecord* belt_record = CreateBeltRecord(
      nullptr,
      num_slots,
      slot_positions
  );

  return unique_ptr_1_00(
      reinterpret_cast<BeltRecord_1_00*>(belt_record)
  );
}

} // namespace

BeltRecord_API::BeltRecord_API(
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

BeltRecord_API::BeltRecord_API(
    const BeltRecord_API& other
) : BeltRecord_API(
        nullptr,
        other.GetNumSlots(),
        other.GetSlotPositions()
    ) {
}

BeltRecord_API::BeltRecord_API(
    BeltRecord_API&& other
) noexcept = default;

BeltRecord_API::~BeltRecord_API() = default;

BeltRecord_API& BeltRecord_API::operator=(
    const BeltRecord_API& other
) {
  *this = BeltRecord_API(
      nullptr,
      other.GetNumSlots(),
      other.GetSlotPositions()
  );

  return *this;
}

BeltRecord_API& BeltRecord_API::operator=(
    BeltRecord_API&& other
) noexcept = default;

BeltRecord_API::operator BeltRecord_View() const noexcept {
  return BeltRecord_View(this->Get());
}

BeltRecord_API::operator BeltRecord_Wrapper() noexcept {
  return BeltRecord_Wrapper(this->Get());
}

BeltRecord* BeltRecord_API::Get() noexcept {
  const auto* const_this = this;

  return const_cast<BeltRecord*>(const_this->Get());
}

const BeltRecord* BeltRecord_API::Get() const noexcept {
  auto& actual_belt_record =
      std::get<unique_ptr_1_00>(this->belt_record_);

  return reinterpret_cast<const BeltRecord*>(actual_belt_record.get());
}

void BeltRecord_API::Copy(BeltRecord_View src) noexcept {
  BeltRecord_Wrapper wrapper(this->Get());

  wrapper.Copy(src);
}

PositionalRectangle* BeltRecord_API::GetSlotPosition(
    std::size_t index
) noexcept {
  BeltRecord_Wrapper wrapper(this->Get());

  return wrapper.GetSlotPosition(index);
}

const PositionalRectangle* BeltRecord_API::GetSlotPosition(
    std::size_t index
) const noexcept {
  BeltRecord_View view(this->Get());

  return view.GetSlotPosition(index);
}

std::uint_least8_t BeltRecord_API::GetNumSlots() const noexcept {
  BeltRecord_View view(this->Get());

  return view.GetNumSlots();
}

void BeltRecord_API::SetNumSlots(std::int_least8_t value) noexcept {
  BeltRecord_Wrapper wrapper(this->Get());

  return wrapper.SetNumSlots(value);
}

PositionalRectangle* BeltRecord_API::GetSlotPositions() noexcept {
  BeltRecord_Wrapper wrapper(this->Get());

  return wrapper.GetSlotPositions();
}

const PositionalRectangle* BeltRecord_API::GetSlotPositions() const noexcept {
  BeltRecord_View view(this->Get());

  return view.GetSlotPositions();
}

BeltRecord* CreateBeltRecord(
    mapi::Undefined* reserved_00__set_to_nullptr,
    std::uint_least8_t num_slots,
    const PositionalRectangle* slot_positions
) {
  BeltRecord* belt_record;
  std::size_t total_num_slots_positions;

  auto* actual_belt_record = new BeltRecord_1_00();
  actual_belt_record->unknown_0x00 = nullptr;

  belt_record = reinterpret_cast<BeltRecord*>(actual_belt_record);
  total_num_slots_positions = sizeof(BeltRecord_1_00::slot_positions)
      / sizeof(BeltRecord_1_00::slot_positions[0]);

  // Set all the values of the struct.
  BeltRecord_Wrapper wrapper(belt_record);

  wrapper.SetNumSlots(num_slots);

  std::copy_n(
      reinterpret_cast<const BeltRecord_1_00*>(slot_positions),
      total_num_slots_positions,
      reinterpret_cast<BeltRecord_1_00*>(wrapper.GetSlotPositions())
  );

  return belt_record;
}

void DestroyBeltRecord(BeltRecord* belt_record) {
  d2::GameVersion running_game_version = d2::GetRunningGameVersionId();

  auto* actual_belt_record =
      reinterpret_cast<BeltRecord_1_00*>(belt_record);

  delete actual_belt_record;
}

} // namespace d2
