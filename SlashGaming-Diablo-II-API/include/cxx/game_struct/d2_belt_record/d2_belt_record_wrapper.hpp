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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_BELT_RECORD_D2_BELT_RECORD_WRAPPER_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_BELT_RECORD_D2_BELT_RECORD_WRAPPER_HPP_

#include <cstddef>
#include <cstdint>

#include "../d2_positional_rectangle/d2_positional_rectangle_struct.hpp"
#include "d2_belt_record_struct.hpp"
#include "d2_belt_record_view.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT BeltRecord_Wrapper {
 public:
  BeltRecord_Wrapper() = delete;
  BeltRecord_Wrapper(BeltRecord* belt_record) noexcept;

  BeltRecord_Wrapper(const BeltRecord_Wrapper& other) noexcept;
  BeltRecord_Wrapper(BeltRecord_Wrapper&& other) noexcept;

  ~BeltRecord_Wrapper() noexcept;

  BeltRecord_Wrapper& operator=(const BeltRecord_Wrapper& other) noexcept;
  BeltRecord_Wrapper& operator=(BeltRecord_Wrapper&& other) noexcept;

  BeltRecord_View operator[](std::size_t index) const noexcept;
  BeltRecord_Wrapper operator[](std::size_t index) noexcept;

  operator BeltRecord_View() const noexcept;

  BeltRecord* Get() noexcept;
  const BeltRecord* Get() const noexcept;

  void Assign(BeltRecord_View src) noexcept;

  unsigned char GetNumSlots() const noexcept;
  void SetNumSlots(unsigned char num_slots) noexcept;

  PositionalRectangle* GetSlotPositions() noexcept;
  const PositionalRectangle* GetSlotPositions() const noexcept;

 private:
  BeltRecord* belt_record_;
};

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_BELT_RECORD_D2_BELT_RECORD_WRAPPER_HPP_
