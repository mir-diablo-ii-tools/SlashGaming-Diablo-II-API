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

#include "../../../../include/cxx/game_struct/d2_unicode_string_view_api.hpp"

#include <algorithm>
#include <stdexcept>

#include "../../../../include/cxx/game_func/d2lang_func.hpp"
#include "../../../../include/cxx/game_version.hpp"
#include "d2_unicode_char_impl.hpp"
#include "../../../../include/cxx/game_struct/d2_unicode_char_traits_api.hpp"

namespace d2 {

UnicodeStringView_API::UnicodeStringView_API() noexcept :
    data_(nullptr),
    length_(0) {
}

UnicodeStringView_API::UnicodeStringView_API(
    const UnicodeStringView_API& other
) noexcept = default;

UnicodeStringView_API::UnicodeStringView_API(
    const value_type* s,
    size_type count
) : data_(s),
    length_(count) {
}

UnicodeStringView_API::UnicodeStringView_API(const value_type* s)
    : UnicodeStringView_API(s, d2lang::Unicode_strlen(s)) {
}

UnicodeStringView_API::~UnicodeStringView_API() noexcept = default;

UnicodeStringView_API& UnicodeStringView_API::operator=(
    const UnicodeStringView_API& view
) noexcept = default;

UnicodeStringView_API::const_reference UnicodeStringView_API::operator[](
    size_type pos
) const {
  auto* actual_data = reinterpret_cast<const UnicodeChar_1_00*>(this->data());
  auto& adjusted_data = actual_data[pos];

  return reinterpret_cast<const_reference>(adjusted_data);
}

UnicodeStringView_API::const_reference
UnicodeStringView_API::at(size_type pos) const {
  if (pos >= this->length()) {
    throw std::out_of_range("UnicodeStringView_API::at");
  }

  return (*this)[pos];
}

UnicodeStringView_API::const_reference UnicodeStringView_API::back() const {
  return (*this)[this->length() - 1];
}

UnicodeStringView_API::size_type UnicodeStringView_API::copy(
    value_type* dest,
    size_type count
) const {
  return this->copy(dest, count, 0);
}

int UnicodeStringView_API::compare(UnicodeStringView_API v) const noexcept {
  return this->compare(0, this->length(), v);
}

int UnicodeStringView_API::compare(
    size_type pos1,
    size_type count1,
    UnicodeStringView_API v
) const {
  return this->compare(
    pos1,
    count1,
    std::move(v),
    0,
    v.length()
  );
}

int UnicodeStringView_API::compare(
    size_type pos1,
    size_type count1,
    UnicodeStringView_API v,
    size_type pos2,
    size_type count2
) const {
  if (pos1 >= this->length()) {
    throw std::out_of_range("UnicodeStringView_API::compare");
  }

  if (pos2 >= v.length()) {
    throw std::out_of_range("UnicodeStringView_API::compare");
  }

  size_type compare_count = std::min(count1, count2);

  // Perform basic compare between the two substrings.
  int first_compare_result = UnicodeChar_Traits::compare(
      this->data(),
      v.data(),
      compare_count
  );

  // If there is a difference, return the value.
  if (first_compare_result != 0) {
    return first_compare_result;
  }

  // If they are the same, return the difference of the counts.
  return count1 - count2;
}

int UnicodeStringView_API::compare(const value_type* s) const {
  return this->compare(UnicodeStringView_API(s));
}

int UnicodeStringView_API::compare(
    size_type pos1,
    size_type count1,
    const value_type* s
) const {
  return this->compare(pos1, count1, UnicodeStringView_API(s));
}

int UnicodeStringView_API::compare(
    size_type pos1,
    size_type count1,
    const value_type* s,
    size_type count2
) const {
  return this->compare(
      pos1,
      count1,
      UnicodeStringView_API(s, count2),
      0,
      count2
  );
}

UnicodeStringView_API::size_type UnicodeStringView_API::copy(
    value_type* dest,
    size_type count,
    size_type pos
) const {
  if (pos >= this->length()) {
    throw std::out_of_range("UnicodeStringView_API::copy");
  }

  size_type actual_count = std::min(this->length() - pos, count);

  UnicodeChar_Traits::move(dest, &(*this)[pos], actual_count);

  return actual_count;
}

bool UnicodeStringView_API::empty() const noexcept {
  return this->length() == 0;
}

UnicodeStringView_API::const_reference UnicodeStringView_API::front() const {
  return (*this)[0];
}

UnicodeStringView_API UnicodeStringView_API::substr() const {
  return this->substr(0);
}

UnicodeStringView_API UnicodeStringView_API::substr(size_type pos) const {
  return this->substr(pos, this->length() - pos);
}

UnicodeStringView_API UnicodeStringView_API::substr(
    size_type pos,
    size_type count
) const {
  size_type corrected_count = std::min(count, this->length() - pos);

  return UnicodeStringView_API(
      &(*this)[pos],
      corrected_count
  );
}

UnicodeStringView_API::const_pointer
UnicodeStringView_API::data() const noexcept {
  return this->data_;
}

UnicodeStringView_API::size_type
UnicodeStringView_API::length() const noexcept {
  return this->length_;
}

UnicodeStringView_API::size_type
UnicodeStringView_API::size() const noexcept {
  return this->length();
}

} // namespace d2
