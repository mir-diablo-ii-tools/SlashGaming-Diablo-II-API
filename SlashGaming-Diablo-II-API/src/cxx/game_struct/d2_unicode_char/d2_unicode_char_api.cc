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

#include "../../../../include/cxx/game_struct/d2_unicode_char/d2_unicode_char_api.hpp"

#include <array>

#include "../../../../include/cxx/game_function/d2lang/d2lang_unicode_tolower.hpp"
#include "../../../../include/cxx/game_function/d2lang/d2lang_unicode_toupper.hpp"

namespace d2 {

UnicodeChar_Api::UnicodeChar_Api() :
    uch_([](){
      UnicodeChar_1_00 uch;
      uch.ch = 0;

      return uch;
    }()) {
}

UnicodeChar_Api::UnicodeChar_Api(const UnicodeChar& uch) :
    uch_([&uch](){
      return reinterpret_cast<const UnicodeChar_1_00&>(uch);
    }()) {
}

UnicodeChar_Api UnicodeChar_Api::FromUtf8Char(
    std::u8string_view ch
) noexcept {
  UnicodeChar_Api uch;

  uch.SetUtf8Char(ch);

  return uch;
}

UnicodeChar_Api UnicodeChar_Api::ToLower() const {
  auto actual_to_lower_uch = std::visit(
      [](const auto& actual_uch) {
        using UnicodeChar_T = std::remove_const_t<
            std::remove_pointer_t<
                std::remove_reference_t<decltype(actual_uch)>
            >
        >;

        UnicodeChar_T to_lower_uch;

        d2lang::Unicode_tolower(
            reinterpret_cast<const UnicodeChar*>(&actual_uch),
            reinterpret_cast<UnicodeChar*>(&to_lower_uch)
        );

        return to_lower_uch;
      },
      this->uch_
  );

  return reinterpret_cast<UnicodeChar&>(actual_to_lower_uch);
}

UnicodeChar_Api UnicodeChar_Api::ToUpper() const {
  auto actual_to_upper_uch = std::visit(
      [](const auto& actual_uch) {
        using UnicodeChar_T = std::remove_const_t<
            std::remove_pointer_t<
                std::remove_reference_t<decltype(actual_uch)>
            >
        >;

        UnicodeChar_T to_upper_uch;

        d2lang::Unicode_toupper(
            reinterpret_cast<const UnicodeChar*>(&actual_uch),
            reinterpret_cast<UnicodeChar*>(&to_upper_uch)
        );

        return to_upper_uch;
      },
      this->uch_
  );

  return reinterpret_cast<UnicodeChar&>(actual_to_upper_uch);
}

::std::u8string UnicodeChar_Api::ToUtf8Char() const {
  UnicodeChar_View view(this->Get());

  return view.ToUtf8Char();
}

void UnicodeChar_Api::SetAsciiChar(char ch) noexcept {
  UnicodeChar_Wrapper wrapper(this->Get());

  wrapper.SetAsciiChar(ch);
}

void UnicodeChar_Api::SetUtf8Char(std::u8string_view ch) noexcept {
  UnicodeChar_Wrapper wrapper(this->Get());

  wrapper.SetUtf8Char(ch);
}

} // namespace d2
