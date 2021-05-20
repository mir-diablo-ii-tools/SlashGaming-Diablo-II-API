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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_CONTEXT_API_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_CONTEXT_API_HPP_

#include <variant>

#include "../../../../include/cxx/helper/d2_draw_options.hpp"
#include "../d2_cel/d2_cel_struct.hpp"
#include "../d2_cel_file/d2_cel_file_view.hpp"
#include "../d2_cel_file/d2_cel_file_wrapper.hpp"
#include "d2_cel_context_struct.hpp"
#include "d2_cel_context_view.hpp"
#include "d2_cel_context_wrapper.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT CelContext_Api {
 public:
  using ApiVariant = std::variant<
      CelContext_1_00,
      CelContext_1_12A,
      CelContext_1_13C
  >;

  CelContext_Api() = delete;

  CelContext_Api(
      CelFile_Wrapper cel_file,
      unsigned int direction,
      unsigned int frame
  );

  constexpr CelContext_Api(
      const CelContext_Api& other
  ) = default;

  constexpr CelContext_Api(
      CelContext_Api&& other
  ) noexcept = default;

  ~CelContext_Api() = default;

  constexpr CelContext_Api& operator=(
      const CelContext_Api& other
  ) = default;

  constexpr CelContext_Api& operator=(
      CelContext_Api&& other
  ) noexcept = default;

  constexpr operator CelContext_View() const noexcept {
    return ::std::visit(
        [](const auto& actual_cel_context) {
          return CelContext_View(&actual_cel_context);
        },
        this->cel_context_
    );
  }

  constexpr operator CelContext_Wrapper() noexcept {
    return ::std::visit(
        [](auto& actual_cel_context) {
          return CelContext_Wrapper(&actual_cel_context);
        },
        this->cel_context_
    );
  }

  constexpr CelContext* Get() noexcept {
    const auto* const_this = this;

    return const_cast<CelContext*>(const_this->Get());
  }

  constexpr const CelContext* Get() const noexcept {
    return std::visit(
        [](const auto& actual_cel_context) {
          return reinterpret_cast<const CelContext*>(&actual_cel_context);
        },
        this->cel_context_
    );
  }

  constexpr void AssignMembers(CelContext_View src) {
    CelContext_Wrapper dest_wrapper(*this);

    dest_wrapper.AssignMembers(src);
  }

  bool DrawFrame(int position_x, int position_y);

  bool DrawFrame(
      int position_x,
      int position_y,
      const DrawCelFileFrameOptions& frame_options
  );

  Cel* GetCel();

  constexpr CelFile_View GetCelFile() const noexcept {
    CelContext_View view(*this);

    return view.GetCelFile();
  }

  constexpr CelFile_Wrapper GetCelFile() noexcept {
    CelContext_Wrapper wrapper(*this);

    return wrapper.GetCelFile();
  }

  constexpr void SetCelFile(CelFile_Wrapper cel_file) noexcept {
    CelContext_Wrapper wrapper(*this);

    wrapper.SetCelFile(cel_file);
  }

  constexpr unsigned int GetDirectionIndex() const noexcept {
    CelContext_View view(*this);

    return view.GetDirectionIndex();
  }

  constexpr void SetDirectionIndex(unsigned int direction_index) noexcept {
    CelContext_Wrapper wrapper(*this);

    wrapper.SetDirectionIndex(direction_index);
  }

  constexpr unsigned int GetFrameIndex() const noexcept {
    CelContext_View view(*this);

    return view.GetFrameIndex();
  }

  constexpr void SetFrameIndex(unsigned int frame_index) noexcept {
    CelContext_Wrapper wrapper(*this);

    wrapper.SetFrameIndex(frame_index);
  }

 private:
  ApiVariant cel_context_;

  static ApiVariant CreateVariant(
      CelFile* cel_file,
      unsigned int direction_index,
      unsigned int frame_index
  );
};

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_CONTEXT_API_HPP_
