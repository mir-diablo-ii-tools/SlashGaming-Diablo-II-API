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
 *  it with any Glide wrapper (or a modified version of that library),
 *  containing parts not covered by a compatible license, the licensors of
 *  this Program grant you additional permission to convey the resulting
 *  work.
 */

#include "../../../include/cxx/game_struct/d2_unicode_char.hpp"

#include <cstdint>

#include "d2_unicode_char_impl.hpp"

/**
 * Latest supported version: 1.14D
 */

namespace d2 {

UnicodeChar_Wrapper::UnicodeChar_Wrapper(
    UnicodeChar* ptr
) noexcept :
    UnicodeChar_ConstWrapper(ptr),
    ptr_(ptr) {
}

UnicodeChar_Wrapper::~UnicodeChar_Wrapper() = default;

UnicodeChar_Wrapper::operator UnicodeChar*() const noexcept {
  return this->Get();
}

UnicodeChar* UnicodeChar_Wrapper::Get() const noexcept {
  return this->ptr_;
}

void UnicodeChar_Wrapper::SetChar(unsigned short ch) noexcept {
  UnicodeChar* ptr = this->Get();

  auto actual_ptr = reinterpret_cast<UnicodeChar_1_00*>(ptr);
  actual_ptr->ch = ch;
}

} // namespace d2
