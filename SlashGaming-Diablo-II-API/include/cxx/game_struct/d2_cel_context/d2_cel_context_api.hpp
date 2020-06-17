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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_CONTEXT_API_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_CONTEXT_API_HPP_

#include <memory>
#include <variant>

#include "../../../../include/cxx/helper/d2_draw_options.hpp"
#include "../d2_cel/d2_cel_struct.hpp"
#include "../d2_cel_file/d2_cel_file_struct.hpp"
#include "d2_cel_context_struct.hpp"
#include "d2_cel_context_view.hpp"
#include "d2_cel_context_wrapper.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT CelContext_Api {
 public:
  CelContext_Api() = delete;
  CelContext_Api(
      CelFile* cel_file,
      unsigned int direction,
      unsigned int frame
  );

  CelContext_Api(const CelContext_Api& other);
  CelContext_Api(CelContext_Api&& other) noexcept;

  ~CelContext_Api();

  CelContext_Api& operator=(const CelContext_Api& other);
  CelContext_Api& operator=(CelContext_Api&& other) noexcept;

  operator CelContext_View() const noexcept;
  operator CelContext_Wrapper() noexcept;

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
  unsigned int GetDirection() const noexcept;
  unsigned int GetFrame() const noexcept;

  void SetCelFile(CelFile* cel_file) noexcept;
  void SetDirection(unsigned int direction) noexcept;
  void SetFrame(unsigned int frame) noexcept;

 private:
  using unique_ptr_1_00 = std::unique_ptr<CelContext_1_00>;
  using unique_ptr_1_12A = std::unique_ptr<CelContext_1_12A>;
  using unique_ptr_1_13C = std::unique_ptr<CelContext_1_13C>;

  using ptr_variant = std::variant<
      unique_ptr_1_00,
      unique_ptr_1_12A,
      unique_ptr_1_13C
  >;

  ptr_variant cel_context_;

  static ptr_variant CreateVariant(
      CelFile* cel_file,
      unsigned int direction,
      unsigned int frame
  );
};

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_CONTEXT_API_HPP_
