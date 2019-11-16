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

#include "../../../../include/cxx/game_struct/d2_unicode_char/d2_unicode_char_wrapper.hpp"

#include <cstdint>

#include "d2_unicode_char_impl.hpp"
#include "../../../../include/cxx/game_func/d2lang/d2lang_unicode_unicodeToUtf8.hpp"
#include "../../../../include/cxx/game_func/d2lang/d2lang_unicode_utf8ToUnicode.hpp"

/**
 * Latest supported version: 1.14D
 */

namespace d2 {

UnicodeChar_Wrapper::UnicodeChar_Wrapper(
    UnicodeChar& uch
) noexcept :
    uch_(&uch) {
}

UnicodeChar_Wrapper::UnicodeChar_Wrapper(
    const UnicodeChar_Wrapper& other
) noexcept = default;

UnicodeChar_Wrapper::UnicodeChar_Wrapper(
    UnicodeChar_Wrapper&& other
) noexcept = default;

UnicodeChar_Wrapper::~UnicodeChar_Wrapper() noexcept = default;

UnicodeChar_Wrapper& UnicodeChar_Wrapper::operator=(
    const UnicodeChar_Wrapper& other
) noexcept = default;

UnicodeChar_Wrapper& UnicodeChar_Wrapper::operator=(
    UnicodeChar_Wrapper&& other
) noexcept = default;

UnicodeChar_Wrapper::operator UnicodeChar_View() const noexcept {
  return UnicodeChar_View(*this->uch_);
}

UnicodeChar& UnicodeChar_Wrapper::Get() noexcept {
  const auto* const_this = this;

  return const_cast<UnicodeChar&>(const_this->Get());
}

const UnicodeChar& UnicodeChar_Wrapper::Get() const noexcept {
  UnicodeChar_View view(*this);

  return view.Get();
}

std::u8string UnicodeChar_Wrapper::ToU8String() const {
  UnicodeChar_View view(*this);

  return view.ToU8String();
}

void UnicodeChar_Wrapper::SetChar(const UnicodeChar& src) noexcept {
  auto actual_ptr = reinterpret_cast<UnicodeChar_1_00&>(this->Get());
  auto actual_src = reinterpret_cast<const UnicodeChar_1_00&>(src);

  actual_ptr.ch = actual_src.ch;
}

void UnicodeChar_Wrapper::SetChar(std::u8string_view view) {
  UnicodeChar_1_00 temp_ch;
  auto* converted_temp_ch = reinterpret_cast<UnicodeChar*>(&temp_ch);

  d2lang::Unicode_utf8ToUnicode(converted_temp_ch, view.data(), 1);

  this->SetChar(*converted_temp_ch);
}

} // namespace d2
