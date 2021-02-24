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

#include "../../../../include/cxx/game_struct/d2_unicode_char/d2_unicode_char_view.hpp"

#include <array>

#include "../../../../include/cxx/game_function/d2lang/d2lang_unicode_unicode_to_utf8.hpp"

/**
 * Latest supported version: 1.14D
 */

namespace d2 {

UnicodeChar_View::UnicodeChar_View(const UnicodeChar* uch) noexcept :
    uch_(CreateVariant(uch)) {
}

::std::u8string UnicodeChar_View::ToUtf8Char() const {
  return ::std::visit(
      [](const auto& actual_uch) {
        using UnicodeChar_T = std::remove_pointer_t<
            std::remove_reference_t<decltype(actual_uch)>
        >;

        std::array<char8_t, 5> temp_uch;

        d2lang::Unicode_UnicodeToUtf8(
            temp_uch.data(),
            reinterpret_cast<const UnicodeChar*>(&actual_uch),
            2
        );

        return std::u8string(temp_uch.data());
      },
      this->uch_
  );
}

UnicodeChar_View::ViewVariant UnicodeChar_View::CreateVariant(
    const UnicodeChar* uch
) {
  return reinterpret_cast<const UnicodeChar_1_00*>(uch);
}

} // namespace d2
