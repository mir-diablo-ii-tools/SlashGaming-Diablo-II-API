/**
 * SlashGaming Diablo II Modding API
 * Copyright (C) 2018-2019  Mir Drualga
 *
 * This file is part of SlashGaming Diablo II Modding API.
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

#include <cstdint>

#include "d2_unicode_char_impl.hpp"
#include "../../../../include/cxx/game_func/d2lang/d2lang_unicode_unicodeToUtf8.hpp"

/**
 * Latest supported version: 1.14D
 */

namespace d2 {

UnicodeChar_View::UnicodeChar_View(
    const UnicodeChar& uch
) noexcept :
    uch_(&uch) {
}

UnicodeChar_View::UnicodeChar_View(
    const UnicodeChar_View& other
) noexcept = default;

UnicodeChar_View::UnicodeChar_View(
    UnicodeChar_View&& other
) noexcept = default;

UnicodeChar_View::~UnicodeChar_View() noexcept = default;

UnicodeChar_View& UnicodeChar_View::operator=(
    const UnicodeChar_View& other
) noexcept = default;

UnicodeChar_View& UnicodeChar_View::operator=(
    UnicodeChar_View&& other
) noexcept = default;

const UnicodeChar& UnicodeChar_View::Get() const noexcept {
  return *this->uch_;
}

std::u8string UnicodeChar_View::ToU8String() const {
  char8_t str[4];
  d2lang::Unicode_unicodeToUtf8(str, &this->Get(), 1);

  return str;
}

} // namespace d2
