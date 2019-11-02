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

#include "../../../../include/cxx/game_struct/d2_unicode_char_traits_api.hpp"

#include <string>

#include "d2_unicode_char_impl.hpp"
#include "../../../../include/cxx/game_func/d2lang/d2lang_unicode_strncpy.hpp"
#include "../../../../include/cxx/game_func/d2lang/d2lang_unicode_strncmp.hpp"

namespace d2 {
namespace {

using unichar_traits_1_00 = std::char_traits<UnicodeChar_1_00>;

} // namespace

void UnicodeChar_Traits::assign(value_type& r, const value_type& a) noexcept {
  UnicodeChar_1_00& actual_r = reinterpret_cast<UnicodeChar_1_00&>(r);
  const UnicodeChar_1_00& actual_a = reinterpret_cast<const UnicodeChar_1_00&>(a);

  unichar_traits_1_00::assign(actual_r, actual_a);
}

UnicodeChar_Traits::value_type* UnicodeChar_Traits::assign(
    value_type* p,
    std::size_t count,
    const value_type& a
) {
  auto* actual_p = reinterpret_cast<UnicodeChar_1_00*>(p);
  auto& actual_a = reinterpret_cast<const UnicodeChar_1_00&>(a);

  unichar_traits_1_00::assign(actual_p, count, actual_a);

  return p;
}

bool UnicodeChar_Traits::eq(const value_type& a, const value_type& b) {
  auto& actual_a = reinterpret_cast<const UnicodeChar_1_00&>(a);
  auto& actual_b = reinterpret_cast<const UnicodeChar_1_00&>(b);

  return unichar_traits_1_00::eq(actual_a, actual_b);
}

bool UnicodeChar_Traits::lt(const value_type& a, const value_type& b) {
  auto& actual_a = reinterpret_cast<const UnicodeChar_1_00&>(a);
  auto& actual_b = reinterpret_cast<const UnicodeChar_1_00&>(b);

  return unichar_traits_1_00::lt(actual_a, actual_b);
}

UnicodeChar_Traits::value_type* UnicodeChar_Traits::move(
    value_type* dest,
    const value_type* src,
    std::size_t count
) {
  auto* actual_dest = reinterpret_cast<UnicodeChar_1_00*>(dest);
  auto* actual_src = reinterpret_cast<const UnicodeChar_1_00*>(src);

  unichar_traits_1_00::move(actual_dest, actual_src, count);

  return dest;
}

UnicodeChar_Traits::value_type* UnicodeChar_Traits::copy(
    value_type* dest,
    const value_type* src,
    std::size_t count
) {
  auto* actual_dest = reinterpret_cast<UnicodeChar_1_00*>(dest);
  auto* actual_src = reinterpret_cast<const UnicodeChar_1_00*>(src);

  unichar_traits_1_00::copy(actual_dest, actual_src, count);

  return dest;
}

int UnicodeChar_Traits::compare(
    const value_type* s1,
    const value_type* s2,
    std::size_t count
) {
  auto* actual_s1 = reinterpret_cast<const UnicodeChar_1_00*>(s1);
  auto* actual_s2 = reinterpret_cast<const UnicodeChar_1_00*>(s2);

  return unichar_traits_1_00::compare(actual_s1, actual_s2, count);
}

const UnicodeChar_Traits::value_type* UnicodeChar_Traits::find(
    const value_type* p,
    std::size_t count,
    const value_type& ch
) {
  auto* actual_p = reinterpret_cast<const UnicodeChar_1_00*>(p);
  auto& actual_ch = reinterpret_cast<const UnicodeChar_1_00&>(ch);

  auto* actual_result = unichar_traits_1_00::find(
      actual_p,
      count,
      actual_ch
  );

  return reinterpret_cast<const value_type*>(actual_result);
}

} // namespace d2
