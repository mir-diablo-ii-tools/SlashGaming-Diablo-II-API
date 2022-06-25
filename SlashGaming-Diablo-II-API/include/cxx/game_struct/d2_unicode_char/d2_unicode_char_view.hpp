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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_UNICODE_CHAR_D2_UNICODE_CHAR_VIEW_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_UNICODE_CHAR_D2_UNICODE_CHAR_VIEW_HPP_

#include <string>
#include <string_view>
#include <variant>

#include "d2_unicode_char_struct.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT UnicodeChar_View {
 public:
  using ViewVariant = ::std::variant<
      const UnicodeChar_1_00*
  >;

  UnicodeChar_View() = delete;

  UnicodeChar_View(const UnicodeChar* uch) noexcept;

  constexpr explicit UnicodeChar_View(
      ViewVariant uch
  ) noexcept
      : uch_(::std::move(uch)) {
  }

  constexpr UnicodeChar_View(
      const UnicodeChar_View& other
  ) noexcept = default;

  constexpr UnicodeChar_View(
      UnicodeChar_View&& other
  ) noexcept = default;

  ~UnicodeChar_View() noexcept = default;

  constexpr UnicodeChar_View& operator=(
      const UnicodeChar_View& other
  ) noexcept = default;

  constexpr UnicodeChar_View& operator=(
      UnicodeChar_View&& other
  ) noexcept = default;

  constexpr const UnicodeChar* Get() const noexcept {
    return ::std::visit(
        [](const auto& actual_uch) {
          return reinterpret_cast<const UnicodeChar*>(actual_uch);
        },
        this->uch_
    );
  }

  constexpr int GetChar() const noexcept {
    return ::std::visit(
        [](const auto& actual_uch) {
          return actual_uch->ch;
        },
        this->uch_
    );
  }

  ::std::u8string ToUtf8Char() const;

 private:
  ViewVariant uch_;

  static ViewVariant CreateVariant(const UnicodeChar* uch);
};

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_UNICODE_CHAR_D2_UNICODE_CHAR_VIEW_HPP_
