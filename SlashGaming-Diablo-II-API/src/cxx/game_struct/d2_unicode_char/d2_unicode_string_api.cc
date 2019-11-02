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

#include <memory>
#include <string>

#include "../../../../include/cxx/game_func/d2lang_func.hpp"
#include "../../../../include/cxx/game_version.hpp"
#include "d2_unicode_char_impl.hpp"
#include "../../../../include/cxx/game_struct/d2_unicode_char_traits_api.hpp"

namespace d2 {
namespace {

using unistring_1_00 = std::basic_string<UnicodeChar_1_00>;
using unique_ptr_1_00 = std::unique_ptr<unistring_1_00>;

extern template std::basic_string_view<UnicodeChar_1_00>;

} // namespace


UnicodeString_API::UnicodeString_API() :
    str_(std::make_unique<unistring_1_00>()) {
}

UnicodeString_API::UnicodeString_API(
    size_type count,
    const value_type& ch
) : str_(
        std::make_unique<unistring_1_00>(
            count, reinterpret_cast<const UnicodeChar_1_00&>(ch)
        )
    ) {
}

UnicodeString_API::UnicodeString_API(const UnicodeString_API& str) :
    str_(
        std::make_unique<unistring_1_00>(
            reinterpret_cast<const UnicodeChar_1_00*>(str.data())
        )
    ) {
}

UnicodeString_API::UnicodeString_API(
    const UnicodeString_API& str,
    size_type pos
) : str_(
        std::make_unique<unistring_1_00>(
            reinterpret_cast<const UnicodeChar_1_00*>(str.data()), pos
        )
    ) {
}

UnicodeString_API::UnicodeString_API(
    const UnicodeString_API& str,
    size_type pos,
    size_type count
) : str_(
        std::make_unique<unistring_1_00>(
            reinterpret_cast<const UnicodeChar_1_00*>(str.data()), pos, count
        )
    ) {
}

UnicodeString_API::UnicodeString_API(
    const value_type* str
) : str_(
        std::make_unique<unistring_1_00>(
            reinterpret_cast<const UnicodeChar_1_00*>(str)
        )
    ) {
}

UnicodeString_API::UnicodeString_API(
    const value_type* str,
    size_type count
) : str_(
        std::make_unique<unistring_1_00>(
            reinterpret_cast<const UnicodeChar_1_00*>(str), count
        )
    ) {
}

UnicodeString_API::UnicodeString_API(
    UnicodeString_API&& str
) noexcept = default;

UnicodeString_API::UnicodeString_API(unistring_1_00&& str) :
    str_(std::make_unique<unistring_1_00>(std::move(str))) {
}

UnicodeString_API::~UnicodeString_API() = default;

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
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);
  auto& actual_ref = (*actual_this)[pos];

  return reinterpret_cast<reference>(actual_ref);
}

UnicodeString_API::const_reference UnicodeString_API::operator[](
    size_type pos
) const {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);
  auto& actual_ref = (*actual_this)[pos];

  return reinterpret_cast<const_reference>(actual_ref);
}

UnicodeString_API::operator UnicodeStringView_API() const noexcept {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);

  return UnicodeStringView_API(
      reinterpret_cast<const UnicodeChar*>(actual_this->data()),
      actual_this->length()
  );
}

UnicodeString_API UnicodeString_API::FromU8String(
    std::u8string_view src
) {
  std::unique_ptr actual_temp_dest = 
      std::make_unique<UnicodeChar_1_00[]>(src.length());
  UnicodeChar* converted_temp_dest =
      reinterpret_cast<UnicodeChar*>(actual_temp_dest.get());

  d2lang::Unicode_utf8ToUnicode(
      converted_temp_dest,
      src.data(),
      std::numeric_limits<int>::max()
  );

  return converted_temp_dest;
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
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);

  actual_this->append(
      count,
      reinterpret_cast<const UnicodeChar_1_00&>(ch)
  );

  return *this;
}

UnicodeString_API& UnicodeString_API::append(const UnicodeString_API& str) {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);
  auto& actual_str = std::get<unique_ptr_1_00>(str.str_);

  actual_this->append(
      *actual_str.get()
  );

  return *this;
}

UnicodeString_API& UnicodeString_API::append(
    const UnicodeString_API& str,
    size_type pos
) {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);
  auto& actual_str = std::get<unique_ptr_1_00>(str.str_);

  actual_this->append(*actual_str.get(), pos);

  return *this;
}

UnicodeString_API& UnicodeString_API::append(
    const UnicodeString_API& str,
    size_type pos,
    size_type count
) {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);
  auto& actual_str = std::get<unique_ptr_1_00>(str.str_);

  actual_this->append(*actual_str.get(), pos, count);

  return *this;
}

UnicodeString_API& UnicodeString_API::append(const value_type* str) {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);
  auto* actual_str = reinterpret_cast<const UnicodeChar_1_00*>(str);

  actual_this->append(actual_str);

  return *this;
}

UnicodeString_API& UnicodeString_API::append(
    const value_type* str,
    size_type count
) {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);
  auto* actual_str = reinterpret_cast<const UnicodeChar_1_00*>(str);

  actual_this->append(actual_str, count);

  return *this;
}

UnicodeString_API::reference UnicodeString_API::at(
    size_type pos
) {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);

  return reinterpret_cast<reference>(actual_this->at(pos));
}

UnicodeString_API::const_reference UnicodeString_API::at(
    size_type pos
) const {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);

  return reinterpret_cast<const_reference>(actual_this->at(pos));
}

UnicodeString_API::value_type& UnicodeString_API::back() {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);

  return reinterpret_cast<value_type&>(actual_this->back());
}

const UnicodeString_API::value_type& UnicodeString_API::back() const {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);

  return reinterpret_cast<const value_type&>(actual_this->back());
}

void UnicodeString_API::clear() noexcept {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);
  actual_this->clear();
}

UnicodeString_API::size_type UnicodeString_API::copy(
    value_type* dest,
    size_type count
) const {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);
  auto* actual_dest = reinterpret_cast<UnicodeChar_1_00*>(dest);

  return actual_this->copy(actual_dest, count);
}

UnicodeString_API::size_type UnicodeString_API::copy(
    value_type* dest,
    size_type count,
    size_type pos
) const {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);
  auto* actual_dest = reinterpret_cast<UnicodeChar_1_00*>(dest);

  return actual_this->copy(actual_dest, count, pos);
}

void UnicodeString_API::Draw(int position_x, int position_y) const {
  UnicodeStringView_API(*this).Draw(position_x, position_y);
}

void UnicodeString_API::Draw(
    int position_x,
    int position_y,
    const DrawTextOptions& options
) const {
  UnicodeStringView_API(*this).Draw(position_x, position_y, options);
}

bool UnicodeString_API::empty() const noexcept {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);

  return actual_this->empty();
}

bool UnicodeString_API::ends_with(UnicodeStringView_API x) const noexcept {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);

  return actual_this->ends_with(
      reinterpret_cast<const UnicodeChar_1_00*>(x.data())
  );
}

bool UnicodeString_API::ends_with(const value_type& x) const noexcept {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);
  auto& actual_x = reinterpret_cast<const UnicodeChar_1_00&>(x);

  return actual_this->ends_with(actual_x);
}

bool UnicodeString_API::ends_with(const value_type* x) const {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);
  auto* actual_x = reinterpret_cast<const UnicodeChar_1_00*>(x);

  return actual_this->ends_with(actual_x);
}

UnicodeString_API::value_type& UnicodeString_API::front() {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);

  return reinterpret_cast<value_type&>(actual_this->front());
}

const UnicodeString_API::value_type& UnicodeString_API::front() const {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);

  return reinterpret_cast<const value_type&>(actual_this->front());
}

void UnicodeString_API::pop_back() {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);
  actual_this->pop_back();
}

void UnicodeString_API::push_back(const value_type& ch) {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);

  actual_this->push_back(reinterpret_cast<const UnicodeChar_1_00&>(ch));
}

void UnicodeString_API::resize(size_type count) {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);
  actual_this->resize(count);
}

void UnicodeString_API::resize(size_type count, const value_type& ch) {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);
  actual_this->resize(count, reinterpret_cast<const UnicodeChar_1_00&>(ch));
}

void UnicodeString_API::shrink_to_fit() {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);
  actual_this->shrink_to_fit();
}

bool UnicodeString_API::starts_with(UnicodeStringView_API x) const noexcept {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);

  return actual_this->starts_with(
      reinterpret_cast<const UnicodeChar_1_00*>(x.data())
  );
}

bool UnicodeString_API::starts_with(const value_type& x) const noexcept {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);
  auto& actual_x = reinterpret_cast<const UnicodeChar_1_00&>(x);

  return actual_this->starts_with(actual_x);
}

bool UnicodeString_API::starts_with(const value_type* x) const {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);
  auto* actual_x = reinterpret_cast<const UnicodeChar_1_00*>(x);

  return actual_this->starts_with(actual_x);
}

UnicodeString_API UnicodeString_API::substr() const {
  return *this;
}

UnicodeString_API UnicodeString_API::substr(size_type pos) const {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);
  auto actual_sub = actual_this->substr(pos);

  return UnicodeString_API(std::move(actual_sub));
}

UnicodeString_API UnicodeString_API::substr(
    size_type pos,
    size_type count
) const {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);
  auto actual_sub = actual_this->substr(pos, count);

  return UnicodeString_API(std::move(actual_sub));
}

void UnicodeString_API::swap(UnicodeString_API& str) {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);
  auto& actual_str = std::get<unique_ptr_1_00>(str.str_);

  actual_this->swap(*actual_str.get());
}

UnicodeString_API::size_type UnicodeString_API::capacity() const noexcept {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);

  return actual_this->capacity();
}

const UnicodeString_API::value_type*
UnicodeString_API::c_str() const noexcept {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);

  return reinterpret_cast<const value_type*>(actual_this->c_str());
}

UnicodeString_API::value_type* UnicodeString_API::data() noexcept {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);

  return reinterpret_cast<value_type*>(actual_this->data());
}

const UnicodeString_API::value_type*
UnicodeString_API::data() const noexcept {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);

  return reinterpret_cast<const value_type*>(actual_this->data());
}

UnicodeString_API::size_type UnicodeString_API::length() const noexcept {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);

  return actual_this->length();
}

UnicodeString_API::size_type UnicodeString_API::size() const noexcept {
  auto& actual_this = std::get<unique_ptr_1_00>(this->str_);

  return actual_this->size();
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
