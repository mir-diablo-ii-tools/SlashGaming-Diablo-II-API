/**
 * SlashGaming Diablo II Modding API for C++
 * Copyright (C) 2018-2022  Mir Drualga
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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_CONTEXT_D2_CEL_CONTEXT_VIEW_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_CONTEXT_D2_CEL_CONTEXT_VIEW_HPP_

#include <cstddef>
#include <variant>

#include "../d2_cel_file/d2_cel_file_view.hpp"
#include "d2_cel_context_struct.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT CelContext_View {
 public:
  using ViewVariant = ::std::variant<
      const CelContext_1_00*,
      const CelContext_1_12A*,
      const CelContext_1_13C*
  >;

  CelContext_View() = delete;

  CelContext_View(const CelContext* cel_context) noexcept;

  constexpr explicit CelContext_View(ViewVariant cel_context) noexcept
      : cel_context_(::std::move(cel_context)) {
  }

  constexpr CelContext_View(
      const CelContext_View& other
  ) noexcept = default;

  constexpr CelContext_View(
      CelContext_View&& other
  ) noexcept = default;

  ~CelContext_View() noexcept = default;

  constexpr CelContext_View& operator=(
      const CelContext_View& other
  ) noexcept = default;

  constexpr CelContext_View& operator=(
      CelContext_View&& other
  ) noexcept = default;

  constexpr CelContext_View operator[](
      std::size_t index
  ) const noexcept {
    return std::visit(
        [index](const auto& actual_cel_context) {
          return CelContext_View(
              &actual_cel_context[index]
          );
        },
        this->cel_context_
    );
  }

  constexpr const CelContext* Get() const noexcept {
    return std::visit(
        [](const auto& actual_cel_context) {
          return reinterpret_cast<const CelContext*>(actual_cel_context);
        },
        this->cel_context_
    );
  };

  constexpr CelFile_View GetCelFile() const noexcept {
    return std::visit(
        [](const auto& actual_cel_context) {
          return CelFile_View(
              actual_cel_context->cel_file
          );
        },
        this->cel_context_
    );
  }

  constexpr unsigned int GetDirectionIndex() const noexcept {
    return std::visit(
        [](const auto& actual_cel_context) {
          return actual_cel_context->direction_index;
        },
        this->cel_context_
    );
  }

  constexpr unsigned int GetFrameIndex() const noexcept {
    return std::visit(
        [](const auto& actual_cel_context) {
          return actual_cel_context->frame_index;
        },
        this->cel_context_
    );
  }

 private:
  ViewVariant cel_context_;

  static ViewVariant CreateVariant(const CelContext* cel_context);
};

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_CONTEXT_D2_CEL_CONTEXT_VIEW_HPP_
