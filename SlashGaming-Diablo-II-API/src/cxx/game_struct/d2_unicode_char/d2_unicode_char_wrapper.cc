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

#include "../../../../include/cxx/game_struct/d2_unicode_char/d2_unicode_char_wrapper.hpp"

#include <array>

#include "../../../../include/cxx/game_function/d2lang/d2lang_unicode_ascii_to_unicode.hpp"
#include "../../../../include/cxx/game_function/d2lang/d2lang_unicode_unicode_to_utf8.hpp"
#include "../../../../include/cxx/game_function/d2lang/d2lang_unicode_utf8_to_unicode.hpp"

/**
 * Latest supported version: 1.14D
 */

namespace d2 {

UnicodeChar_Wrapper::UnicodeChar_Wrapper(
    UnicodeChar* uch
) noexcept : uch_(CreateVariant(uch)) {
}

::std::u8string UnicodeChar_Wrapper::ToUtf8Char() const {
  UnicodeChar_View view(*this);

  return view.ToUtf8Char();
}

void UnicodeChar_Wrapper::SetAsciiChar(char ch) noexcept {
  std::visit(
      [ch](const auto& actual_uch) {
        using UnicodeChar_T = std::remove_const_t<
            std::remove_pointer_t<
                std::remove_reference_t<decltype(actual_uch)>
            >
        >;

        std::array<UnicodeChar_T, 2> uch_dest;
        std::array<char, 2> ch_src = { ch, '\0' };

        d2lang::Unicode_AsciiToUnicode(
            reinterpret_cast<UnicodeChar*>(uch_dest.data()),
            ch_src.data(),
            2
        );

        actual_uch->ch = uch_dest.at(0).ch;
      },
      this->uch_
  );
}

void UnicodeChar_Wrapper::SetUtf8Char(::std::u8string_view ch) {
  std::visit(
      [&ch](auto& actual_uch) {
        using UnicodeChar_T = std::remove_pointer_t<
            std::remove_reference_t<decltype(actual_uch)>
        >;

        std::array<UnicodeChar_T, 2> temp_uch;

        d2lang::Unicode_Utf8ToUnicode(
            reinterpret_cast<UnicodeChar*>(temp_uch.data()),
            ch.data(),
            2
        );

        actual_uch->ch = temp_uch.at(0).ch;
      },
      this->uch_
  );
}

UnicodeChar_Wrapper::WrapperVariant UnicodeChar_Wrapper::CreateVariant(
    UnicodeChar* uch
) {
  return reinterpret_cast<UnicodeChar_1_00*>(uch);
}

} // namespace d2
