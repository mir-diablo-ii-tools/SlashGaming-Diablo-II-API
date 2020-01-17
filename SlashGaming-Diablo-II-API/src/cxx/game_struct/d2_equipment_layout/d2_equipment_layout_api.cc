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

#include "../../../../include/cxx/game_struct/d2_equipment_layout/d2_equipment_layout_api.hpp"

#include "d2_equipment_layout_impl.hpp"
#include "../../../../include/cxx/game_struct/d2_positional_rectangle/d2_positional_rectangle_wrapper.hpp"
#include "../../../../include/cxx/game_version.hpp"

namespace d2 {
namespace {

using unique_ptr_1_00 = std::unique_ptr<EquipmentLayout_1_00>;

using EquipmentLayoutVariant = std::variant<
    unique_ptr_1_00
>;

EquipmentLayoutVariant CreateVariant(
    PositionalRectangle_View position,
    std::int_least8_t width,
    std::int_least8_t height
) {
  EquipmentLayout* equipment_layout = CreateEquipmentLayout(
      position.Get(),
      width,
      height
  );

  return unique_ptr_1_00(
      reinterpret_cast<EquipmentLayout_1_00*>(equipment_layout)
  );
}

} // namespace

EquipmentLayout_API::EquipmentLayout_API(
    PositionalRectangle_View position,
    std::int_least8_t width,
    std::int_least8_t height
) : equipment_layout_(
        CreateVariant(position, width, height)
    ) {
}

EquipmentLayout_API::EquipmentLayout_API(
    const EquipmentLayout_API& other
) : EquipmentLayout_API(
        other.GetPosition(),
        other.GetWidth(),
        other.GetHeight()
    ) {
}

EquipmentLayout_API::EquipmentLayout_API(
    EquipmentLayout_API&& other
) noexcept = default;

EquipmentLayout_API::~EquipmentLayout_API() = default;

EquipmentLayout_API& EquipmentLayout_API::operator=(
    const EquipmentLayout_API& other
) {
  *this = EquipmentLayout_API(
      other.GetPosition(),
      other.GetWidth(),
      other.GetHeight()
  );

  return *this;
}

EquipmentLayout_API& EquipmentLayout_API::operator=(
    EquipmentLayout_API&& other
) noexcept = default;

EquipmentLayout_API::operator EquipmentLayout_View() const noexcept {
  return EquipmentLayout_View(this->Get());
}

EquipmentLayout_API::operator EquipmentLayout_Wrapper() noexcept {
  return EquipmentLayout_Wrapper(this->Get());
}

EquipmentLayout* EquipmentLayout_API::Get() noexcept {
  const auto* const_this = this;

  return const_cast<EquipmentLayout*>(const_this->Get());
}

const EquipmentLayout* EquipmentLayout_API::Get() const noexcept {
  auto& actual_equipment_layout =
      std::get<unique_ptr_1_00>(this->equipment_layout_);

  return reinterpret_cast<const EquipmentLayout*>(actual_equipment_layout.get());
}

void EquipmentLayout_API::Copy(EquipmentLayout_View src) noexcept {
  EquipmentLayout_Wrapper wrapper(this->Get());

  wrapper.Copy(src);
}

PositionalRectangle* EquipmentLayout_API::GetPosition() noexcept {
  EquipmentLayout_Wrapper wrapper(this->Get());

  return wrapper.GetPosition();
}

const PositionalRectangle* EquipmentLayout_API::GetPosition() const noexcept {
  EquipmentLayout_View view(this->Get());

  return view.GetPosition();
}

std::uint_least8_t EquipmentLayout_API::GetWidth() const noexcept {
  EquipmentLayout_View view(this->Get());

  return view.GetWidth();
}

void EquipmentLayout_API::SetWidth(std::uint_least8_t value) noexcept {
  EquipmentLayout_Wrapper wrapper(this->Get());

  wrapper.SetWidth(value);
}

std::uint_least8_t EquipmentLayout_API::GetHeight() const noexcept {
  EquipmentLayout_View view(this->Get());

  return view.GetHeight();
}

void EquipmentLayout_API::SetHeight(std::uint_least8_t value) noexcept {
  EquipmentLayout_Wrapper wrapper(this->Get());

  wrapper.SetHeight(value);
}

EquipmentLayout* CreateEquipmentLayout(
    const PositionalRectangle* position,
    std::int_least8_t width,
    std::int_least8_t height
) {
  EquipmentLayout* equipment_layout;

  equipment_layout = reinterpret_cast<EquipmentLayout*>(new EquipmentLayout_1_00());

  // Set all the values of the struct.
  EquipmentLayout_Wrapper wrapper(equipment_layout);

  PositionalRectangle_Wrapper position_wrapper(wrapper.GetPosition());
  position_wrapper.Copy(position);

  wrapper.SetWidth(width);
  wrapper.SetHeight(height);

  return equipment_layout;
}

void DestroyEquipmentLayout(EquipmentLayout* equipment_layout) {
  d2::GameVersion running_game_version = d2::GetRunningGameVersionId();

  auto* actual_equipment_layout =
      reinterpret_cast<EquipmentLayout_1_00*>(equipment_layout);

  delete actual_equipment_layout;
}

} // namespace d2
