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

#include "../../../../include/cxx/game_struct/d2_unicode_char.hpp"

#include "d2_unicode_char_impl.hpp"
#include "../../../../include/cxx/game_func/d2lang/d2lang_unicode_strncpy.hpp"
#include "../../../../include/cxx/game_func/d2lang/d2lang_unicode_strncmp.hpp"

namespace d2 {

void UnicodeChar_Traits::assign(char_type& r, const char_type& a) noexcept {
  UnicodeChar_1_00& actual_r = reinterpret_cast<UnicodeChar_1_00&>(r);
  const UnicodeChar_1_00& actual_a = reinterpret_cast<const UnicodeChar_1_00&>(a);

  actual_r.ch = actual_a.ch;
}

UnicodeChar_Traits::char_type* UnicodeChar_Traits::assign(
    char_type* p,
    std::size_t count,
    const char_type& a
) {
  auto* actual_p = reinterpret_cast<UnicodeChar_1_00*>(p);
  auto& actual_a = reinterpret_cast<const UnicodeChar_1_00&>(a);


  std::fill_n(actual_p, count, actual_a);

  return p;
}

bool UnicodeChar_Traits::eq(const char_type& a, const char_type& b) {
  auto& actual_a = reinterpret_cast<const UnicodeChar_1_00&>(a);
  auto& actual_b = reinterpret_cast<const UnicodeChar_1_00&>(b);

  return actual_a.ch == actual_b.ch;
}

bool UnicodeChar_Traits::lt(const char_type& a, const char_type& b) {
  auto& actual_a = reinterpret_cast<const UnicodeChar_1_00&>(a);
  auto& actual_b = reinterpret_cast<const UnicodeChar_1_00&>(b);

  return actual_a.ch < actual_b.ch;
}

UnicodeChar_Traits::char_type* UnicodeChar_Traits::move(
    char_type* dest,
    const char_type* src,
    std::size_t count
) {
  auto* actual_dest = reinterpret_cast<UnicodeChar_1_00*>(dest);
  auto* actual_src = reinterpret_cast<const UnicodeChar_1_00*>(src);

  if (actual_dest < actual_src) {
    std::copy(actual_src, &actual_src[count], actual_dest);
  } else if (actual_dest > actual_src) {
    std::copy_backward(actual_src, &actual_src[count], actual_dest);
  }

  return dest;
}

UnicodeChar_Traits::char_type* UnicodeChar_Traits::copy(
    char_type* dest,
    const char_type* src,
    std::size_t count
) {
  auto* actual_dest = reinterpret_cast<UnicodeChar_1_00*>(dest);
  auto* actual_src = reinterpret_cast<const UnicodeChar_1_00*>(src);

  std::copy(actual_src, &actual_src[count], actual_dest);

  return dest;
}

int UnicodeChar_Traits::compare(
    const char_type* s1,
    const char_type* s2,
    std::size_t count
) {
  return std::memcmp(s1, s2, count);
}

const UnicodeChar_Traits::char_type* UnicodeChar_Traits::find(
    const char_type* p,
    std::size_t count,
    const char_type& ch
) {
  auto* actual_p = reinterpret_cast<const UnicodeChar_1_00*>(p);
  auto& actual_ch = reinterpret_cast<const UnicodeChar_1_00&>(ch);

  for (std::size_t i = 0; i < count; i += 1) {
    if (actual_p[i].ch == actual_ch.ch) {
      return reinterpret_cast<const UnicodeChar*>(&actual_p[i]);
    }
  }

  return nullptr;
}

} // namespace d2
