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

#include "../../../../include/cxx/game_struct/d2_unicode_string_api.hpp"

#include <algorithm>
#include <stdexcept>

#include "../../../../include/cxx/game_func/d2lang_func.hpp"
#include "../../../../include/cxx/game_version.hpp"
#include "d2_unicode_char_impl.hpp"
#include "../../../../include/cxx/game_struct/d2_unicode_char_traits_api.hpp"

namespace d2 {
namespace {

std::int_least32_t GetUnicodeCharValue(const UnicodeChar& str) {
  return reinterpret_cast<const UnicodeChar_1_00&>(str).ch;
}

} // namespace


UnicodeString_API::UnicodeString_API() :
    data_(CreateUnicodeChar(u'\0')),
    length_(0),
    capacity_(1) {
}

UnicodeString_API::UnicodeString_API(
    size_type count,
    const value_type& ch
) : data_(CreateUnicodeCharArray(count + 1)),
    length_(
        (GetUnicodeCharValue(ch) == '\0')
            ? 0
            : (count + 1)
    ),
    capacity_(count + 1) {
  UnicodeChar_Traits::assign(this->data(), count, ch);
  TerminateString(this->data(), this->length());
}

UnicodeString_API::UnicodeString_API(const UnicodeString_API& str)
    : UnicodeString_API(str, 0) {
}

UnicodeString_API::UnicodeString_API(
    const UnicodeString_API& str,
    size_type pos
) : UnicodeString_API(str, pos, str.length() - pos) {
}

UnicodeString_API::UnicodeString_API(
    const UnicodeString_API& str,
    size_type pos,
    size_type count
) : data_(CreateUnicodeCharArray(std::min(count, str.length() - pos))),
    length_(std::min(count, str.length() - pos)),
    capacity_(this->length() + 1) {
  UnicodeChar_Traits::move(this->data(), &str[pos], this->length());
  TerminateString(this->data(), this->length());
}

UnicodeString_API::UnicodeString_API(
    const value_type* str
) : UnicodeString_API(str, d2lang::Unicode_strlen(str)) {
}

UnicodeString_API::UnicodeString_API(
    const value_type* str,
    size_type count
) : length_(std::min(count, d2lang::Unicode_strlen(str))),
    capacity_(this->length() + 1) {
  data_ = CreateUnicodeCharArray(this->length() + 1);

  UnicodeChar_Traits::move(this->data(), str, this->length());
  TerminateString(this->data(), this->length());
}

UnicodeString_API::UnicodeString_API(
    UnicodeString_API&& str
) noexcept = default;

UnicodeString_API::~UnicodeString_API() {
  DestroyUnicodeChar(this->data());
}

UnicodeString_API& UnicodeString_API::operator=(
    const UnicodeString_API& str
) {
  *this = UnicodeString_API(str);
  return *this;
}

UnicodeString_API& UnicodeString_API::operator=(
    UnicodeString_API&& str
) noexcept = default;

UnicodeString_API& UnicodeString_API::operator=(
    const value_type* str
) {
  *this = UnicodeString_API(str);
  return *this;
}

UnicodeString_API& UnicodeString_API::operator=(
    const value_type& ch
) {
  *this = UnicodeString_API(1, ch);
  return *this;
}

UnicodeString_API& UnicodeString_API::operator+=(
    const UnicodeString_API& str
) {
  return this->append(str);
}

UnicodeString_API& UnicodeString_API::operator+=(const value_type& ch) {
  return this->append(1, ch);
}

UnicodeString_API& UnicodeString_API::operator+=(const value_type* str) {
  return this->append(str);
}

UnicodeString_API::reference UnicodeString_API::operator[](
    size_type pos
) {
  auto* actual_ptr = reinterpret_cast<UnicodeChar_1_00*>(this->data());
  auto& adjusted_ref = actual_ptr[pos];

  return reinterpret_cast<reference>(adjusted_ref);
}

UnicodeString_API::const_reference UnicodeString_API::operator[](
    size_type pos
) const {
  auto actual_ptr = reinterpret_cast<const UnicodeChar_1_00*>(this->data());
  auto& adjusted_ref = actual_ptr[pos];

  return reinterpret_cast<const_reference>(adjusted_ref);
}

UnicodeString_API UnicodeString_API::FromU8String(
    std::u8string_view src
) {
  UnicodeString_API null_term_ch;
  UnicodeString_API dest(src.length(), *null_term_ch.data());
  d2lang::Unicode_utf8ToUnicode(
      dest.data(),
      src.data(),
      std::numeric_limits<int>::max()
  );

  dest.length_ = d2lang::Unicode_strlen(dest.data());

  return dest;
}

std::u8string UnicodeString_API::ToU8String() const {
  std::unique_ptr dest = std::make_unique<char8_t[]>(this->length() * 4);
  d2lang::Unicode_unicodeToUtf8(
      dest.get(),
      this->data(),
      std::numeric_limits<int>::max()
  );

  return dest.get();
}

UnicodeString_API& UnicodeString_API::append(
    size_type count,
    const value_type& ch
) {
  size_type old_length = this->length();
  size_type old_capacity = this->capacity();
  size_type new_capacity = this->capacity();
  this->length_ += count;

  // Repeatedly resize until the data can fit.
  while (this->length() >= new_capacity) {
    new_capacity *= 2;
  }

  this->resize(new_capacity, ch);

  UnicodeChar_Traits::assign(
      &(*this)[old_length],
      old_length - old_capacity,
      ch
  );
  return *this;
}

UnicodeString_API& UnicodeString_API::append(const UnicodeString_API& str) {
  return this->append(str, 0);
}

UnicodeString_API& UnicodeString_API::append(
    const UnicodeString_API& str,
    size_type pos
) {
  return this->append(str, pos, str.length() - pos);
}

UnicodeString_API& UnicodeString_API::append(
    const UnicodeString_API& str,
    size_type pos,
    size_type count
) {
  return this->append(&str[pos], count);
}

UnicodeString_API& UnicodeString_API::append(const value_type* str) {
  return this->append(str, d2lang::Unicode_strlen(str));
}

UnicodeString_API& UnicodeString_API::append(
    const value_type* str,
    size_type count
) {
  size_type old_length = this->length();
  size_type old_capacity = this->capacity();
  size_type str_count = std::min(count, d2lang::Unicode_strlen(str));
  this->length_ += str_count;

  // If the capacity needs resizing.
  if (this->capacity() <= this->length()) {
    size_type new_capacity = this->capacity();
    while (new_capacity <= this->length()) {
      new_capacity *= 2;
    }

    this->resize(new_capacity);
  }

  UnicodeChar_Traits::move(
      &(*this)[this->length()],
      str,
      str_count
  );

  return *this;
}

UnicodeString_API::reference UnicodeString_API::at(
    size_type pos
) {
  if (pos >= this->length()) {
    throw std::out_of_range("UnicodeString_API::at");
  }

  auto* actual_ptr = reinterpret_cast<UnicodeChar_1_00*>(this->data());
  auto* adjusted_converted_ptr =
      reinterpret_cast<UnicodeChar*>(&actual_ptr[pos]);

  return *adjusted_converted_ptr;
}

UnicodeString_API::const_reference UnicodeString_API::at(
    size_type pos
) const {
  if (pos >= this->length()) {
    throw std::out_of_range("UnicodeString_API::at");
  }

  auto* actual_ptr = reinterpret_cast<const UnicodeChar_1_00*>(this->data());
  auto* adjusted_converted_ptr =
      reinterpret_cast<const UnicodeChar*>(&actual_ptr[pos]);

  return *adjusted_converted_ptr;
}

UnicodeString_API::value_type& UnicodeString_API::back() {
  return (*this)[this->length() - 1];
}

const UnicodeString_API::value_type& UnicodeString_API::back() const {
  return (*this)[this->length() - 1];
}

void UnicodeString_API::clear() noexcept {
  TerminateString(this->data(), 0);
  this->length_ = 0;
}

UnicodeString_API::size_type UnicodeString_API::copy(
    value_type* dest,
    size_type count
) const {
  return this->copy(dest, count, 0);
}

UnicodeString_API::size_type UnicodeString_API::copy(
    value_type* dest,
    size_type count,
    size_type pos
) const {
  if (pos > this->length()) {
    throw std::out_of_range("UnicodeString_API::copy");
  }

  size_type actual_count = std::min(this->length() - pos, count);

  UnicodeChar_Traits::move(dest, &(*this)[pos], actual_count);

  return actual_count;
}

bool UnicodeString_API::empty() const noexcept {
  return this->length() == 0;
}

UnicodeString_API::value_type& UnicodeString_API::front() {
  return (*this)[0];
}

const UnicodeString_API::value_type& UnicodeString_API::front() const {
  return (*this)[0];
}

void UnicodeString_API::pop_back() {
  TerminateString(this->data(), this->length() - 1);
  this->length_ -= 1;
}

void UnicodeString_API::push_back(const value_type& ch) {
  this->append(1, ch);
}

void UnicodeString_API::resize(size_type count) {
  UnicodeString_API null_term_ch;
  this->resize(count, *null_term_ch.data());
}

void UnicodeString_API::resize(size_type count, const value_type& ch) {
  // If count is the same as length, do nothing.
  if (count == this->length()) {
    return;
  }

  // If count is less than length, terminate the string at the select
  // position.
  if (count < this->length()) {
    this->length_ = count;
    TerminateString(this->data(), count);
    return;
  }

  // If count is greater than length...
  // If capacity is too small, resize the capacity.
  if (count >= this->capacity()) {
    UnicodeString_API temp(count, ch);
    UnicodeChar_Traits::copy(temp.data(), this->data(), this->length());
    TerminateString(temp.data(), this->length());

    *this = std::move(temp);

    return;
  }

  // If capacity is large enough, then append characters.
  UnicodeChar_Traits::assign(
      &(*this)[this->length()],
      count - this->length(),
      ch
  );

  this->length_ = (reinterpret_cast<const UnicodeChar_1_00&>(ch).ch == u'\0')
      ? this->length()
      : count;

  TerminateString(this->data(), this->length());
}

UnicodeString_API UnicodeString_API::substr() const {
  return this->substr(0);
}

UnicodeString_API UnicodeString_API::substr(size_type pos) const {
  return this->substr(pos, this->length() - pos);
}

UnicodeString_API UnicodeString_API::substr(
    size_type pos,
    size_type count
) const {
  return UnicodeString_API(*this, pos, count);
}

void UnicodeString_API::swap(UnicodeString_API& str) {
  auto* temp_data = this->data();
  this->data_ = str.data();
  str.data_ = temp_data;

  auto temp_length = this->length();
  this->length_ = str.length();
  str.length_ = temp_length;

  auto temp_capacity = this->capacity();
  this->capacity_ = str.capacity();
  str.capacity_ = temp_capacity;
}

UnicodeString_API::size_type UnicodeString_API::capacity() const noexcept {
  return this->capacity_;
}

const UnicodeChar* UnicodeString_API::c_str() const noexcept {
  return this->data();
}

UnicodeChar* UnicodeString_API::data() noexcept {
  return this->data_;
}

const UnicodeChar* UnicodeString_API::data() const noexcept {
  return this->data_;
}

UnicodeString_API::size_type UnicodeString_API::length() const noexcept {
  return this->length_;
}

UnicodeString_API::size_type UnicodeString_API::size() const noexcept {
  return this->length();
}

void UnicodeString_API::TerminateString(value_type* str, size_type pos) {
  auto* actual_str = reinterpret_cast<UnicodeChar_1_00*>(str);

  actual_str[pos].ch = u'\0';
}

UnicodeString_API operator+(
    const UnicodeString_API& lhs,
    const UnicodeString_API& rhs
) {
  UnicodeString_API cat(lhs);
  cat += rhs;

  return cat;
}

UnicodeString_API operator+(
    const UnicodeString_API& lhs,
    const UnicodeChar* rhs
) {
  UnicodeString_API cat(lhs);
  cat += rhs;

  return cat;
}

UnicodeString_API operator+(
    const UnicodeString_API& lhs,
    const UnicodeChar& rhs
) {
  UnicodeString_API cat(lhs);
  cat += rhs;

  return cat;
}

UnicodeString_API operator+(
    const UnicodeChar* lhs,
    const UnicodeString_API& rhs
) {
  UnicodeString_API cat(rhs);
  cat += lhs;

  return cat;
}

UnicodeString_API operator+(
    const UnicodeChar& lhs,
    const UnicodeString_API& rhs
) {
  UnicodeString_API cat(rhs);
  cat += lhs;

  return cat;
}

UnicodeString_API operator+(
    UnicodeString_API&& lhs,
    UnicodeString_API&& rhs
) {
  if (lhs.capacity() >= rhs.capacity()) {
    UnicodeString_API cat(std::move(lhs));
    cat += rhs;

    return cat;
  } else {
    UnicodeString_API cat(std::move(rhs));
    cat += lhs;

    return cat;
  }
}

UnicodeString_API operator+(
    UnicodeString_API&& lhs,
    const UnicodeString_API& rhs
) {
  UnicodeString_API cat(std::move(lhs));
  cat += rhs;

  return cat;
}

UnicodeString_API operator+(
    UnicodeString_API&& lhs,
    const UnicodeChar* rhs
) {
  UnicodeString_API cat(std::move(lhs));
  cat += rhs;

  return cat;
}

UnicodeString_API operator+(
    UnicodeString_API&& lhs,
    const UnicodeChar& rhs
) {
  UnicodeString_API cat(std::move(lhs));
  cat += rhs;

  return cat;
}

UnicodeString_API operator+(
    const UnicodeString_API& lhs,
    UnicodeString_API&& rhs
) {
  UnicodeString_API cat(std::move(rhs));
  cat += lhs;

  return cat;
}

UnicodeString_API operator+(
    const UnicodeChar* lhs,
    UnicodeString_API&& rhs
) {
  UnicodeString_API cat(std::move(rhs));
  cat += lhs;

  return cat;
}

UnicodeString_API operator+(
    const UnicodeChar& lhs,
    UnicodeString_API&& rhs
) {
  UnicodeString_API cat(std::move(rhs));
  cat += lhs;

  return cat;
}

UnicodeChar* CreateUnicodeChar(char16_t ch) {
  UnicodeChar_1_00* ptr = new UnicodeChar_1_00[1];
  ptr->ch = ch;

  return reinterpret_cast<UnicodeChar*>(ptr);
}

UnicodeChar* CreateUnicodeCharArray(std::size_t count) {
  UnicodeChar_1_00* ptr = new UnicodeChar_1_00[count];
  return reinterpret_cast<UnicodeChar*>(ptr);
}

void DestroyUnicodeChar(UnicodeChar* ptr) {
  UnicodeChar_1_00* actual_ptr = reinterpret_cast<UnicodeChar_1_00*>(ptr);
  delete[] actual_ptr;
}

} // namespace d2
