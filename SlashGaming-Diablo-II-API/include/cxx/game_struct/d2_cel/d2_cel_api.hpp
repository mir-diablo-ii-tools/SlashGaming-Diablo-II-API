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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_D2_CEL_API_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_D2_CEL_API_HPP_

#include <variant>

#include "d2_cel_struct.hpp"
#include "d2_cel_view.hpp"
#include "d2_cel_wrapper.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT Cel_Api {
 public:
  Cel_Api() = delete;

  Cel_Api(const Cel_Api& other);
  Cel_Api(Cel_Api&& other) noexcept;

  ~Cel_Api();

  Cel_Api& operator=(const Cel_Api& other);
  Cel_Api& operator=(Cel_Api&& other) noexcept;

  operator Cel_View() const noexcept;
  operator Cel_Wrapper() noexcept;

  Cel* Get() noexcept;
  const Cel* Get() const noexcept;

  int GetHeight() const noexcept;
  void SetHeight(int height) noexcept;

  int GetOffsetX() const noexcept;
  void SetOffsetX(int offset_x) noexcept;

  int GetOffsetY() const noexcept;
  void SetOffsetY(int offset_y) noexcept;

  int GetWidth() const noexcept;
  void SetWidth(int width) noexcept;

 private:
  using ApiVariant = std::variant<Cel_1_00*>;

  ApiVariant cel_;
};

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_D2_CEL_API_HPP_
