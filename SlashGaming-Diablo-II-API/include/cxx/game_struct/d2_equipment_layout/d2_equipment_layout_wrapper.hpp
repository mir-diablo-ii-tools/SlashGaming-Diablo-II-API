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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_EQUIPMENT_LAYOUT_D2_EQUIPMENT_LAYOUT_WRAPPER_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_EQUIPMENT_LAYOUT_D2_EQUIPMENT_LAYOUT_WRAPPER_HPP_

#include <cstddef>
#include <variant>

#include "../d2_positional_rectangle/d2_positional_rectangle_view.hpp"
#include "../d2_positional_rectangle/d2_positional_rectangle_wrapper.hpp"
#include "d2_equipment_layout_struct.hpp"
#include "d2_equipment_layout_view.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT EquipmentLayout_Wrapper {
 public:
  using WrapperVariant = ::std::variant<EquipmentLayout_1_00*>;

  EquipmentLayout_Wrapper() = delete;

  EquipmentLayout_Wrapper(EquipmentLayout* equipment_layout) noexcept;

  constexpr explicit EquipmentLayout_Wrapper(
      WrapperVariant equipment_layout
  ) noexcept
      : equipment_layout_(::std::move(equipment_layout)) {
  }

  constexpr EquipmentLayout_Wrapper(
      const EquipmentLayout_Wrapper& other
  ) noexcept = default;

  constexpr EquipmentLayout_Wrapper(
      EquipmentLayout_Wrapper&& other
  ) noexcept = default;

  ~EquipmentLayout_Wrapper() noexcept = default;

  constexpr EquipmentLayout_Wrapper& operator=(
      const EquipmentLayout_Wrapper& other
  ) noexcept = default;

  constexpr EquipmentLayout_Wrapper& operator=(
      EquipmentLayout_Wrapper&& other
  ) noexcept = default;

  constexpr EquipmentLayout_View operator[](
      std::size_t index
  ) const noexcept {
    EquipmentLayout_View view(*this);

    return view[index];
  }

  constexpr EquipmentLayout_Wrapper operator[](
      std::size_t index
  ) noexcept {
    return ::std::visit(
        [index](const auto& actual_equipment_layout) {
          return EquipmentLayout_Wrapper(
              &actual_equipment_layout[index]
          );
        },
        this->equipment_layout_
    );
  }

  constexpr operator EquipmentLayout_View() const noexcept {
    return ::std::visit(
        [](const auto& equipment_layout) {
          return EquipmentLayout_View(equipment_layout);
        },
        this->equipment_layout_
    );
  }

  constexpr EquipmentLayout* Get() noexcept {
    const auto* const_this = this;

    return const_cast<EquipmentLayout*>(const_this->Get());
  }

  constexpr const EquipmentLayout* Get() const noexcept {
    return std::visit(
        [](const auto& actual_equipment_layout) {
          return reinterpret_cast<const EquipmentLayout*>(
              actual_equipment_layout
          );
        },
        this->equipment_layout_
    );
  }

  constexpr void AssignMembers(EquipmentLayout_View src) noexcept {
    std::visit(
        [&src](auto& actual_dest) {
          using Dest_T = decltype(actual_dest);
          using ActualSrc_T = const std::remove_pointer_t<
              std::remove_reference_t<Dest_T>
          >*;

          const auto* actual_src = reinterpret_cast<ActualSrc_T>(src.Get());

          *actual_dest = *actual_src;
        },
        this->equipment_layout_
    );
  }

  constexpr PositionalRectangle_View GetPosition() const noexcept {
    EquipmentLayout_View view(*this);

    return view.GetPosition();
  }

  constexpr PositionalRectangle_Wrapper GetPosition() noexcept {
    return ::std::visit(
        [](auto& actual_equipment_layout) {
          return PositionalRectangle_Wrapper(
              &actual_equipment_layout->position
          );
        },
        this->equipment_layout_
    );
  }

  constexpr unsigned char GetWidth() const noexcept {
    EquipmentLayout_View view(*this);

    return view.GetWidth();
  }

  constexpr void SetWidth(unsigned char width) noexcept {
    std::visit(
        [width](auto& actual_equipment_layout) {
          actual_equipment_layout->width = width;
        },
        this->equipment_layout_
    );
  }

  constexpr unsigned char GetHeight() const noexcept {
    EquipmentLayout_View view(this->Get());

    return view.GetHeight();
  }

  constexpr void SetHeight(unsigned char height) noexcept {
    std::visit(
        [height](auto& actual_equipment_layout) {
          actual_equipment_layout->height = height;
        },
        this->equipment_layout_
    );
  }

 private:
  WrapperVariant equipment_layout_;

  static WrapperVariant CreateVariant(EquipmentLayout* equipment_layout);
};

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_EQUIPMENT_LAYOUT_D2_EQUIPMENT_LAYOUT_WRAPPER_HPP_
