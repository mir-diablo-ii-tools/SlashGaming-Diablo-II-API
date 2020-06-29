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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_CONTEXT_D2_CEL_CONTEXT_WRAPPER_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_CONTEXT_D2_CEL_CONTEXT_WRAPPER_HPP_

#include <cstddef>
#include <type_traits>

#include "../../helper/d2_draw_options.hpp"
#include "../d2_cel/d2_cel_struct.hpp"
#include "../d2_cel_file/d2_cel_file_struct.hpp"
#include "d2_cel_context_struct.hpp"
#include "d2_cel_context_view.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT CelContext_Wrapper {
 public:
  CelContext_Wrapper() = delete;
  CelContext_Wrapper(CelContext* cel_context) noexcept;

  CelContext_Wrapper(const CelContext_Wrapper& other) noexcept;
  CelContext_Wrapper(CelContext_Wrapper&& other) noexcept;

  ~CelContext_Wrapper() noexcept;

  CelContext_Wrapper& operator=(const CelContext_Wrapper& other) noexcept;
  CelContext_Wrapper& operator=(CelContext_Wrapper&& other) noexcept;

  CelContext_View operator[](std::size_t index) const noexcept;
  CelContext_Wrapper operator[](std::size_t index) noexcept;

  operator CelContext_View() const noexcept;

  CelContext* Get() noexcept;
  const CelContext* Get() const noexcept;

  void Assign(CelContext_View src);

  bool DrawFrame(int position_x, int position_y);

  bool DrawFrame(
      int position_x,
      int position_y,
      const DrawCelFileFrameOptions& frame_options
  );

  Cel* GetCel();

  CelFile* GetCelFile() noexcept;
  const CelFile* GetCelFile() const noexcept;
  void SetCelFile(CelFile* cel_file) noexcept;

  unsigned int GetDirection() const noexcept;
  void SetDirection(unsigned int direction) noexcept;

  unsigned int GetFrame() const noexcept;
  void SetFrame(unsigned int frame) noexcept;

 private:
  using WrapperVariant = std::variant<
      CelContext_1_00*,
      CelContext_1_12A*,
      CelContext_1_13C*
  >;

  WrapperVariant cel_context_;

  static WrapperVariant CreateVariant(CelContext* cel_context);
};

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_CONTEXT_D2_CEL_CONTEXT_WRAPPER_HPP_
