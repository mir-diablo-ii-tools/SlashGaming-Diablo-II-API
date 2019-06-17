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

#include "../../../include/c/game_struct/d2_unicode_char.h"

#include "../../../include/cxx/game_struct/d2_unicode_char.hpp"
#include "../../cxx/game_struct/d2_unicode_char/d2_unicode_char_impl.hpp"

struct D2_UnicodeChar* D2_UnicodeChar_CreateDefault() {
  return D2_UnicodeChar_CreateWithChar('\0');
}

struct D2_UnicodeChar* D2_UnicodeChar_CreateWithChar(unsigned short ch) {
  return reinterpret_cast<D2_UnicodeChar*>(d2::CreateUnicodeChar(ch));
}

struct D2_UnicodeChar* D2_UnicodeChar_CreateArray(std::size_t count) {
  return reinterpret_cast<D2_UnicodeChar*>(d2::CreateUnicodeCharArray(count));
}

void D2_UnicodeChar_Destroy(struct D2_UnicodeChar* ptr) {
  d2::DestroyUnicodeChar(reinterpret_cast<d2::UnicodeChar*>(ptr));
}

unsigned short D2_UnicodeChar_GetChar(const struct D2_UnicodeChar* ptr) {
  auto actual_ptr = reinterpret_cast<const d2::UnicodeChar*>(ptr);

  return d2::UnicodeChar_ConstWrapper(actual_ptr).GetChar();
}

void D2_UnicodeChar_SetChar(struct D2_UnicodeChar* ptr, unsigned short ch) {
  auto actual_ptr = reinterpret_cast<d2::UnicodeChar*>(ptr);

  return d2::UnicodeChar_Wrapper(actual_ptr).SetChar(ch);
}
