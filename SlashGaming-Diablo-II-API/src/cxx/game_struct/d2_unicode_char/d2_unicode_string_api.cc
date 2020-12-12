/**
 * SlashGaming Diablo II Modding API for C++
 * Copyright (C) 2018-2020  Mir Drualga
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

#include "../../../../include/cxx/game_struct/d2_unicode_char/d2_unicode_string_api.hpp"

#include <string>

#include "../../../../include/cxx/game_function/d2lang_function.hpp"
#include "../../../../include/cxx/game_version.hpp"

namespace d2 {
namespace {

using UnicodeString_1_00 = std::basic_string<UnicodeChar_1_00>;

extern template std::basic_string_view<UnicodeChar_1_00>;

} // namespace


UnicodeString_Api::UnicodeString_Api() :
    str_([]() {
      return ApiVariant(UnicodeString_1_00());
    }()) {
}

UnicodeString_Api::UnicodeString_Api(
    size_type count,
    const value_type& ch
) : str_([count, &ch]() {
      const UnicodeChar_1_00& actual_ch =
          reinterpret_cast<const UnicodeChar_1_00&>(ch);

      return UnicodeString_1_00(count, actual_ch);
    }()) {
}

UnicodeString_Api::UnicodeString_Api(const UnicodeString_Api& str) :
    str_(str.str_) {
}

UnicodeString_Api::UnicodeString_Api(
    const UnicodeString_Api& str,
    size_type pos
) : str_([&str, pos]() {
      return std::visit(
          [pos](const auto& actual_str) {
            using UnicodeString_T = std::remove_const_t<
                std::remove_reference_t<decltype(actual_str)>
            >;

            return UnicodeString_T(actual_str, pos);
          },
          str.str_
      );
    }()) {
}

UnicodeString_Api::UnicodeString_Api(
    const UnicodeString_Api& str,
    size_type pos,
    size_type count
) : str_([&str, pos, count]() {
      return std::visit(
          [pos, count](const auto& actual_str) {
            using UnicodeString_T = std::remove_const_t<
                std::remove_reference_t<decltype(actual_str)>
            >;

            return UnicodeString_T(actual_str, pos, count);
          },
          str.str_
      );
    }()) {
}

UnicodeString_Api::UnicodeString_Api(
    const value_type* str
) : str_([str]() {
      const UnicodeChar_1_00* actual_src_str =
          reinterpret_cast<const UnicodeChar_1_00*>(str);

      return UnicodeString_1_00(actual_src_str);
    }()) {
}

UnicodeString_Api::UnicodeString_Api(
    const value_type* str,
    size_type count
) : str_([str, count]() {
      const UnicodeChar_1_00* actual_src_str =
          reinterpret_cast<const UnicodeChar_1_00*>(str);

      return UnicodeString_1_00(actual_src_str, count);
    }()) {
}

UnicodeString_Api::UnicodeString_Api(
    UnicodeString_Api&& str
) noexcept = default;

UnicodeString_Api::UnicodeString_Api(ApiVariant&& str) :
    str_(std::move(str)) {
}

UnicodeString_Api::~UnicodeString_Api() = default;

UnicodeString_Api& UnicodeString_Api::operator=(
    const UnicodeString_Api& str
) = default;

UnicodeString_Api& UnicodeString_Api::operator=(
    UnicodeString_Api&& str
) noexcept = default;

UnicodeString_Api& UnicodeString_Api::operator=(
    const value_type* str
) {
  *this = UnicodeString_Api(str);
  return *this;
}

UnicodeString_Api& UnicodeString_Api::operator=(
    const value_type& ch
) {
  *this = UnicodeString_Api(1, ch);
  return *this;
}

UnicodeString_Api& UnicodeString_Api::operator+=(
    const UnicodeString_Api& str
) {
  return this->append(str);
}

UnicodeString_Api& UnicodeString_Api::operator+=(const value_type& ch) {
  return this->append(1, ch);
}

UnicodeString_Api& UnicodeString_Api::operator+=(const value_type* str) {
  return this->append(str);
}

UnicodeString_Api::operator UnicodeStringView_Api() const noexcept {
  return std::visit(
      [](const auto& actual_src_str) {
        return UnicodeStringView_Api(
            reinterpret_cast<const_pointer>(actual_src_str.data()),
            actual_src_str.length()
        );
      },
      this->str_
  );
}

UnicodeString_Api::reference UnicodeString_Api::operator[](
    size_type pos
) {
  auto* actual_pointer = std::visit(
      [pos](auto& actual_str) {
        return &actual_str[pos];
      },
      this->str_
  );

  return *reinterpret_cast<pointer>(actual_pointer);
}

UnicodeString_Api::const_reference UnicodeString_Api::operator[](
    size_type pos
) const {
  const auto* actual_pointer = std::visit(
      [pos](const auto& actual_str) {
        return &actual_str[pos];
      },
      this->str_
  );

  return *reinterpret_cast<const_pointer>(actual_pointer);
}

UnicodeString_Api::reference UnicodeString_Api::at(
    size_type pos
) {
  return *std::visit(
      [pos](auto& actual_str) {
        return reinterpret_cast<pointer>(&actual_str.at(pos));
      },
      this->str_
  );
}

UnicodeString_Api::const_reference UnicodeString_Api::at(
    size_type pos
) const {
  return *std::visit(
      [pos](const auto& actual_str) {
        return reinterpret_cast<const_pointer>(&actual_str.at(pos));
      },
      this->str_
  );
}

UnicodeString_Api::value_type& UnicodeString_Api::front() {
  return *std::visit(
      [](auto& actual_str) {
        return reinterpret_cast<pointer>(&actual_str.front());
      },
      this->str_
  );
}

const UnicodeString_Api::value_type& UnicodeString_Api::front() const {
  return *std::visit(
      [](const auto& actual_str) {
        return reinterpret_cast<const_pointer>(&actual_str.front());
      },
      this->str_
  );
}

UnicodeString_Api::value_type& UnicodeString_Api::back() {
  return *std::visit(
      [](auto& actual_str) {
        return reinterpret_cast<pointer>(&actual_str.back());
      },
      this->str_
  );
}

const UnicodeString_Api::value_type& UnicodeString_Api::back() const {
  return *std::visit(
      [](const auto& actual_str) {
        return reinterpret_cast<const_pointer>(&actual_str.back());
      },
      this->str_
  );
}

UnicodeString_Api::value_type* UnicodeString_Api::data() noexcept {
  return std::visit(
      [](auto& actual_str) {
        return reinterpret_cast<value_type*>(actual_str.data());
      },
      this->str_
  );
}

const UnicodeString_Api::value_type*
UnicodeString_Api::data() const noexcept {
  return std::visit(
      [](const auto& actual_str) {
        return reinterpret_cast<const value_type*>(actual_str.data());
      },
      this->str_
  );
}

const UnicodeString_Api::value_type*
UnicodeString_Api::c_str() const noexcept {
  return std::visit(
      [](const auto& actual_str) {
        return reinterpret_cast<const value_type*>(actual_str.c_str());
      },
      this->str_
  );
}

bool UnicodeString_Api::empty() const noexcept {
  return std::visit(
      [](const auto& actual_str) {
        return actual_str.empty();
      },
      this->str_
  );
}

UnicodeString_Api::size_type UnicodeString_Api::size() const noexcept {
  return std::visit(
      [](const auto& actual_str) {
        return actual_str.size();
      },
      this->str_
  );
}

UnicodeString_Api::size_type UnicodeString_Api::length() const noexcept {
  return std::visit(
      [](const auto& actual_str) {
        return actual_str.length();
      },
      this->str_
  );
}

UnicodeString_Api::size_type UnicodeString_Api::max_size() const noexcept {
  return std::visit(
      [](const auto& actual_str) {
        return actual_str.max_size();
      },
      this->str_
  );
}

void UnicodeString_Api::reserve(size_type new_cap) {
  std::visit(
      [new_cap](auto& actual_str) {
        actual_str.reserve(new_cap);
      },
      this->str_
  );
}

UnicodeString_Api::size_type UnicodeString_Api::capacity() const noexcept {
  return std::visit(
      [](const auto& actual_str) {
        return actual_str.capacity();
      },
      this->str_
  );
}

void UnicodeString_Api::shrink_to_fit() {
  std::visit(
      [](auto& actual_str) {
        actual_str.shrink_to_fit();
      },
      this->str_
  );
}


/**
 * Operations
 */

UnicodeString_Api& UnicodeString_Api::assign(
    size_type count,
    const value_type& ch
) {
  std::visit(
      [count, &ch](auto& actual_dest_str) {
        using UnicodeString_T = std::remove_reference_t<
            decltype(actual_dest_str)
        >;
        using UnicodeChar_T = typename UnicodeString_T::value_type;

        const UnicodeChar_T& actual_ch =
            reinterpret_cast<const UnicodeChar_T&>(ch);

        actual_dest_str.assign(count, actual_ch);
      },
      this->str_
  );

  return *this;
}

UnicodeString_Api& UnicodeString_Api::assign(const UnicodeString_Api& str) {
  std::visit(
      [&str](auto& actual_dest_str) {
        using UnicodeString_T = std::remove_reference_t<
            decltype(actual_dest_str)
        >;
        using UnicodeChar_T = typename UnicodeString_T::value_type;

        const UnicodeString_T& actual_src_str =
            std::get<UnicodeString_T>(str.str_);

        actual_dest_str.assign(actual_src_str);
      },
      this->str_
  );

  return *this;
}

UnicodeString_Api& UnicodeString_Api::assign(
    const UnicodeString_Api& str,
    size_type pos,
    size_type count
) {
  std::visit(
      [&str, pos, count](auto& actual_dest_str) {
        using UnicodeString_T = std::remove_reference_t<
            decltype(actual_dest_str)
        >;
        using UnicodeChar_T = typename UnicodeString_T::value_type;

        const UnicodeString_T& actual_src_str =
            std::get<UnicodeString_T>(str.str_);

        actual_dest_str.assign(actual_src_str, pos, count);
      },
      this->str_
  );

  return *this;
}

UnicodeString_Api& UnicodeString_Api::assign(
    UnicodeString_Api&& str
) noexcept {
  *this = std::move(str);

  return *this;
}

UnicodeString_Api& UnicodeString_Api::assign(
    const value_type* s,
    size_type count
) {
  std::visit(
      [s, count](auto& actual_dest_str) {
        using UnicodeString_T = std::remove_reference_t<
            decltype(actual_dest_str)
        >;
        using UnicodeChar_T = typename UnicodeString_T::value_type;

        const UnicodeChar_T* actual_src_s =
            reinterpret_cast<const UnicodeChar_T*>(s);

        actual_dest_str.assign(actual_src_s, count);
      },
      this->str_
  );

  return *this;
}

UnicodeString_Api& UnicodeString_Api::assign(const value_type* s) {
  std::visit(
      [s](auto& actual_dest_str) {
        using UnicodeString_T = std::remove_reference_t<
            decltype(actual_dest_str)
        >;
        using UnicodeChar_T = typename UnicodeString_T::value_type;

        const UnicodeChar_T* actual_src_s =
            reinterpret_cast<const UnicodeChar_T*>(s);

        actual_dest_str.assign(actual_src_s);
      },
      this->str_
  );

  return *this;
}

void UnicodeString_Api::clear() noexcept {
  std::visit(
      [](auto& actual_str) {
        actual_str.clear();
      },
      this->str_
  );
}

UnicodeString_Api& UnicodeString_Api::insert(
    size_type index,
    size_type count,
    const value_type& ch
) {
  std::visit(
      [index, count, &ch](auto& actual_dest_str) {
        using UnicodeString_T = std::remove_reference_t<
            decltype(actual_dest_str)
        >;
        using UnicodeChar_T = typename UnicodeString_T::value_type;

        const UnicodeChar_T& actual_ch =
            reinterpret_cast<const UnicodeChar_T&>(ch);

        actual_dest_str.insert(index, count, actual_ch);
      },
      this->str_
  );

  return *this;
}

UnicodeString_Api& UnicodeString_Api::insert(
    size_type index,
    const value_type* ch
) {
  std::visit(
      [index, ch](auto& actual_dest_str) {
        using UnicodeString_T = std::remove_reference_t<
            decltype(actual_dest_str)
        >;
        using UnicodeChar_T = typename UnicodeString_T::value_type;

        const UnicodeChar_T* actual_src_ch =
            reinterpret_cast<const UnicodeChar_T*>(ch);

        actual_dest_str.insert(index, actual_src_ch);
      },
      this->str_
  );

  return *this;
}

UnicodeString_Api& UnicodeString_Api::insert(
    size_type index,
    const value_type* ch,
    size_type count
){
  std::visit(
      [index, ch, count](auto& actual_dest_str) {
        using UnicodeString_T = std::remove_reference_t<
            decltype(actual_dest_str)
        >;
        using UnicodeChar_T = typename UnicodeString_T::value_type;

        const UnicodeChar_T* actual_src_ch =
            reinterpret_cast<const UnicodeChar_T*>(ch);

        actual_dest_str.insert(index, actual_src_ch, count);
      },
      this->str_
  );

  return *this;
}

UnicodeString_Api& UnicodeString_Api::insert(
    size_type index,
    const UnicodeString_Api& str,
    size_type index_str,
    size_type count
) {
  std::visit(
      [index, &str, index_str, count](auto& actual_dest_str) {
        using UnicodeString_T = std::remove_reference_t<
            decltype(actual_dest_str)
        >;
        using UnicodeChar_T = typename UnicodeString_T::value_type;

        const UnicodeString_T& actual_src_str =
            std::get<UnicodeString_T>(str.str_);

        actual_dest_str.insert(index, actual_src_str, index_str, count);
      },
      this->str_
  );

  return *this;
}

UnicodeString_Api& UnicodeString_Api::erase(
    size_type index,
    size_type count
) {
  std::visit(
      [index, count](auto& actual_str) {
        actual_str.erase(index, count);
      },
      this->str_
  );

  return *this;
}

void UnicodeString_Api::push_back(const value_type& ch) {
  std::visit(
      [&ch](auto& actual_str) {
        using UnicodeString_T = std::remove_reference_t<
            decltype(actual_str)
        >;
        using UnicodeChar_T = typename UnicodeString_T::value_type;

        const UnicodeChar_T& actual_ch =
            reinterpret_cast<const UnicodeChar_T&>(ch);

        actual_str.push_back(actual_ch);
      },
      this->str_
  );
}

void UnicodeString_Api::pop_back() {
  return std::visit(
      [](auto& actual_str) {
        actual_str.pop_back();
      },
      this->str_
  );
}

UnicodeString_Api& UnicodeString_Api::append(
    size_type count,
    const value_type& ch
) {
  std::visit(
      [count, &ch](auto& actual_dest_str) {
        using UnicodeString_T = std::remove_reference_t<
            decltype(actual_dest_str)
        >;
        using UnicodeChar_T = typename UnicodeString_T::value_type;

        const auto& actual_ch = reinterpret_cast<const UnicodeChar_T&>(ch);

        actual_dest_str.append(count, actual_ch);
      },
      this->str_
  );

  return *this;
}

UnicodeString_Api& UnicodeString_Api::append(const UnicodeString_Api& str) {
  std::visit(
      [&str](auto& actual_dest_str) {
        using UnicodeString_T = std::remove_reference_t<
            decltype(actual_dest_str)
        >;

        const auto& actual_src_str = std::get<UnicodeString_T>(str.str_);

        actual_dest_str.append(actual_src_str);
      },
      this->str_
  );

  return *this;
}

UnicodeString_Api& UnicodeString_Api::append(
    const UnicodeString_Api& str,
    size_type pos
) {
  std::visit(
      [&str, pos](auto& actual_dest_str) {
        using UnicodeString_T = std::remove_reference_t<
            decltype(actual_dest_str)
        >;

        const auto& actual_src_str = std::get<UnicodeString_T>(str.str_);

        actual_dest_str.append(actual_src_str, pos);
      },
      this->str_
  );

  return *this;
}

UnicodeString_Api& UnicodeString_Api::append(
    const UnicodeString_Api& str,
    size_type pos,
    size_type count
) {
  std::visit(
      [&str, pos, count](auto& actual_dest_str) {
        using UnicodeString_T = std::remove_reference_t<
            decltype(actual_dest_str)
        >;

        const auto& actual_src_str = std::get<UnicodeString_T>(str.str_);

        actual_dest_str.append(actual_src_str, pos, count);
      },
      this->str_
  );

  return *this;
}

UnicodeString_Api& UnicodeString_Api::append(const value_type* str) {
  std::visit(
      [str](auto& actual_dest_str) {
        using UnicodeString_T = std::remove_reference_t<
            decltype(actual_dest_str)
        >;
        using UnicodeChar_T = typename UnicodeString_T::value_type;

        const auto* actual_src_str = reinterpret_cast<const UnicodeChar_T*>(str);

        actual_dest_str.append(actual_src_str);
      },
      this->str_
  );

  return *this;
}

UnicodeString_Api& UnicodeString_Api::append(
    const value_type* str,
    size_type count
) {
  std::visit(
      [str, count](auto& actual_dest_str) {
        using UnicodeString_T = std::remove_reference_t<
            decltype(actual_dest_str)
        >;
        using UnicodeChar_T = typename UnicodeString_T::value_type;

        const auto* actual_src_str = reinterpret_cast<const UnicodeChar_T*>(str);

        actual_dest_str.append(actual_src_str, count);
      },
      this->str_
  );

  return *this;
}

int UnicodeString_Api::compare(const UnicodeString_Api& str) const noexcept {
  return std::visit(
      [&str](const auto& actual_str1) {
        using UnicodeString_T = std::remove_const_t<
            std::remove_reference_t<decltype(actual_str1)>
        >;

        const UnicodeString_T& actual_str2 =
            std::get<UnicodeString_T>(str.str_);

        return actual_str1.compare(actual_str2);
      },
      this->str_
  );
}

int UnicodeString_Api::compare(
    size_type pos1,
    size_type count1,
    const UnicodeString_Api& str
) const {
  return std::visit(
      [pos1, count1, &str](const auto& actual_str1) {
        using UnicodeString_T = std::remove_const_t<
            std::remove_reference_t<decltype(actual_str1)>
        >;

        const UnicodeString_T& actual_str2 =
            std::get<UnicodeString_T>(str.str_);

        return actual_str1.compare(pos1, count1, actual_str2);
      },
      this->str_
  );
}

int UnicodeString_Api::compare(
    size_type pos1,
    size_type count1,
    const UnicodeString_Api& str,
    size_type pos2,
    size_type count2
) const {
  return std::visit(
      [pos1, count1, &str, pos2, count2](const auto& actual_str1) {
        using UnicodeString_T = std::remove_const_t<
            std::remove_reference_t<decltype(actual_str1)>
        >;

        const UnicodeString_T& actual_str2 =
            std::get<UnicodeString_T>(str.str_);

        return actual_str1.compare(pos1, count1, actual_str2, pos2, count2);
      },
      this->str_
  );
}

int UnicodeString_Api::compare(const value_type* s) const {
  return std::visit(
      [s](const auto& actual_str) {
        using UnicodeString_T = std::remove_const_t<
            std::remove_reference_t<decltype(actual_str)>
        >;
        using UnicodeChar_T = typename UnicodeString_T::value_type;

        const UnicodeChar_T* actual_s =
            reinterpret_cast<const UnicodeChar_T*>(s);

        return actual_str.compare(actual_s);
      },
      this->str_
  );
}

int UnicodeString_Api::compare(
    size_type pos1,
    size_type count1,
    const value_type* s
) const {
  return std::visit(
      [pos1, count1, s](const auto& actual_str) {
        using UnicodeString_T = std::remove_const_t<
            std::remove_reference_t<decltype(actual_str)>
        >;
        using UnicodeChar_T = typename UnicodeString_T::value_type;

        const UnicodeChar_T* actual_s =
            reinterpret_cast<const UnicodeChar_T*>(s);

        return actual_str.compare(pos1, count1, actual_s);
      },
      this->str_
  );
}

int UnicodeString_Api::compare(
    size_type pos1,
    size_type count1,
    const value_type* s,
    size_type count2
) const {
  return std::visit(
      [pos1, count1, s, count2](const auto& actual_str) {
        using UnicodeString_T = std::remove_const_t<
            std::remove_reference_t<decltype(actual_str)>
        >;
        using UnicodeChar_T = typename UnicodeString_T::value_type;

        const UnicodeChar_T* actual_s =
            reinterpret_cast<const UnicodeChar_T*>(s);

        return actual_str.compare(pos1, count1, actual_s, count2);
      },
      this->str_
  );
}

bool UnicodeString_Api::starts_with(UnicodeStringView_Api sv) const noexcept {
  return std::visit(
      [&sv](const auto& actual_str) {
        using UnicodeString_T = std::remove_reference_t<
            decltype(actual_str)
        >;
        using UnicodeChar_T = typename UnicodeString_T::value_type;
        using UnicodeStringView_T = std::basic_string_view<UnicodeChar_T>;

        UnicodeStringView_T actual_sv_data = reinterpret_cast<const UnicodeChar_T*>(sv.data());

        return actual_str.starts_with(actual_sv_data);
      },
      this->str_
  );
}

bool UnicodeString_Api::starts_with(const value_type& c) const noexcept {
  return std::visit(
      [&c](const auto& actual_str) {
        using UnicodeString_T = std::remove_reference_t<
            decltype(actual_str)
        >;
        using UnicodeChar_T = typename UnicodeString_T::value_type;

        const UnicodeChar_T& actual_c =
            reinterpret_cast<const UnicodeChar_T&>(c);

        return actual_str.starts_with(actual_c);
      },
      this->str_
  );
}

bool UnicodeString_Api::starts_with(const value_type* s) const {
  return std::visit(
      [s](const auto& actual_str) {
        using UnicodeString_T = std::remove_reference_t<
            decltype(actual_str)
        >;
        using UnicodeChar_T = typename UnicodeString_T::value_type;

        const UnicodeChar_T* actual_s =
            reinterpret_cast<const UnicodeChar_T*>(s);

        return actual_str.ends_with(actual_s);
      },
      this->str_
  );
}

bool UnicodeString_Api::ends_with(UnicodeStringView_Api sv) const noexcept {
  return std::visit(
      [&sv](const auto& actual_str) {
        using UnicodeString_T = std::remove_reference_t<
            decltype(actual_str)
        >;
        using UnicodeChar_T = typename UnicodeString_T::value_type;
        using UnicodeStringView_T = std::basic_string_view<UnicodeChar_T>;

        UnicodeStringView_T actual_sv_data = reinterpret_cast<const UnicodeChar_T*>(sv.data());

        return actual_str.ends_with(actual_sv_data);
      },
      this->str_
  );
}

bool UnicodeString_Api::ends_with(const value_type& c) const noexcept {
  return std::visit(
      [&c](const auto& actual_str) {
        using UnicodeString_T = std::remove_reference_t<
            decltype(actual_str)
        >;
        using UnicodeChar_T = typename UnicodeString_T::value_type;

        const UnicodeChar_T& actual_c =
            reinterpret_cast<const UnicodeChar_T&>(c);

        return actual_str.ends_with(actual_c);
      },
      this->str_
  );
}

bool UnicodeString_Api::ends_with(const value_type* s) const {
  return std::visit(
      [s](const auto& actual_str) {
        using UnicodeString_T = std::remove_reference_t<
            decltype(actual_str)
        >;
        using UnicodeChar_T = typename UnicodeString_T::value_type;

        const UnicodeChar_T* actual_s =
            reinterpret_cast<const UnicodeChar_T*>(s);

        return actual_str.ends_with(actual_s);
      },
      this->str_
  );
}

UnicodeString_Api UnicodeString_Api::substr() const {
  return UnicodeString_Api(
      std::visit(
          [](const auto& actual_str) {
            return actual_str.substr();
          },
          this->str_
      )
  );
}

UnicodeString_Api UnicodeString_Api::substr(size_type pos) const {
  return UnicodeString_Api(
      std::visit(
          [pos](const auto& actual_str) {
            return actual_str.substr(pos);
          },
          this->str_
      )
  );
}

UnicodeString_Api UnicodeString_Api::substr(
    size_type pos,
    size_type count
) const {
  return UnicodeString_Api(
      std::visit(
          [pos, count](const auto& actual_str) {
            return actual_str.substr(pos, count);
          },
          this->str_
      )
  );
}

UnicodeString_Api::size_type UnicodeString_Api::copy(
    value_type* dest,
    size_type count,
    size_type pos
) const {
  return std::visit(
      [dest, count, pos](const auto& actual_src_str) {
        using UnicodeString_T = std::remove_reference_t<
            decltype(actual_src_str)
        >;
        using UnicodeChar_T = typename UnicodeString_T::value_type;

        UnicodeChar_T* actual_dest = reinterpret_cast<UnicodeChar_T*>(dest);

        return actual_src_str.copy(actual_dest, count, pos);
      },
      this->str_
  );
}

void UnicodeString_Api::resize(size_type count) {
  std::visit(
      [count](auto& actual_str) {
        actual_str.resize(count);
      },
      this->str_
  );
}

void UnicodeString_Api::resize(size_type count, const value_type& ch) {
  std::visit(
      [count, &ch](auto& actual_str) {
        using UnicodeString_T = std::remove_reference_t<
            decltype(actual_str)
        >;
        using UnicodeChar_T = typename UnicodeString_T::value_type;

        const UnicodeChar_T& actual_ch =
            reinterpret_cast<const UnicodeChar_T&>(ch);

        actual_str.resize(count, actual_ch);
      },
      this->str_
  );
}

void UnicodeString_Api::swap(UnicodeString_Api& str) {
  return std::visit(
      [&str](auto& actual_str1) {
        using UnicodeString_T = std::remove_reference_t<
            decltype(actual_str1)
        >;

        UnicodeString_T actual_str2 = std::get<UnicodeString_T>(str.str_);

        actual_str1.swap(actual_str2);
      },
      this->str_
  );
}

void UnicodeString_Api::Draw(int position_x, int position_y) const {
  UnicodeStringView_Api string_view(this->data());

  string_view.Draw(position_x, position_y);
}

void UnicodeString_Api::Draw(
    int position_x,
    int position_y,
    const DrawTextOptions& options
) const {
  UnicodeStringView_Api string_view(this->data());

  string_view.Draw(position_x, position_y, options);
}

UnicodeString_Api UnicodeString_Api::FromUtf8String(
    std::u8string_view src
) {
  std::unique_ptr actual_temp_dest = 
      std::make_unique<UnicodeChar_1_00[]>(src.length() + 1);
  UnicodeChar* converted_temp_dest =
      reinterpret_cast<UnicodeChar*>(actual_temp_dest.get());

  d2lang::Unicode_Utf8ToUnicode(
      converted_temp_dest,
      src.data(),
      std::numeric_limits<int>::max()
  );

  return converted_temp_dest;
}

std::u8string UnicodeString_Api::ToUtf8String() const {
  std::unique_ptr dest = std::make_unique<char8_t[]>(this->length() * 4);
  d2lang::Unicode_UnicodeToUtf8(
      dest.get(),
      this->data(),
      std::numeric_limits<int>::max()
  );

  return dest.get();
}

UnicodeString_Api operator+(
    const UnicodeString_Api& lhs,
    const UnicodeString_Api& rhs
) {
  UnicodeString_Api cat(lhs);
  cat += rhs;

  return cat;
}

UnicodeString_Api operator+(
    const UnicodeString_Api& lhs,
    const UnicodeChar* rhs
) {
  UnicodeString_Api cat(lhs);
  cat += rhs;

  return cat;
}

UnicodeString_Api operator+(
    const UnicodeString_Api& lhs,
    const UnicodeChar& rhs
) {
  UnicodeString_Api cat(lhs);
  cat += rhs;

  return cat;
}

UnicodeString_Api operator+(
    const UnicodeChar* lhs,
    const UnicodeString_Api& rhs
) {
  UnicodeString_Api cat(rhs);
  cat += lhs;

  return cat;
}

UnicodeString_Api operator+(
    const UnicodeChar& lhs,
    const UnicodeString_Api& rhs
) {
  UnicodeString_Api cat(rhs);
  cat += lhs;

  return cat;
}

UnicodeString_Api operator+(
    UnicodeString_Api&& lhs,
    UnicodeString_Api&& rhs
) {
  if (lhs.capacity() >= rhs.capacity()) {
    UnicodeString_Api cat(std::move(lhs));
    cat += rhs;

    return cat;
  } else {
    UnicodeString_Api cat(std::move(rhs));
    cat += lhs;

    return cat;
  }
}

UnicodeString_Api operator+(
    UnicodeString_Api&& lhs,
    const UnicodeString_Api& rhs
) {
  UnicodeString_Api cat(std::move(lhs));
  cat += rhs;

  return cat;
}

UnicodeString_Api operator+(
    UnicodeString_Api&& lhs,
    const UnicodeChar* rhs
) {
  UnicodeString_Api cat(std::move(lhs));
  cat += rhs;

  return cat;
}

UnicodeString_Api operator+(
    UnicodeString_Api&& lhs,
    const UnicodeChar& rhs
) {
  UnicodeString_Api cat(std::move(lhs));
  cat += rhs;

  return cat;
}

UnicodeString_Api operator+(
    const UnicodeString_Api& lhs,
    UnicodeString_Api&& rhs
) {
  UnicodeString_Api cat(std::move(rhs));
  cat += lhs;

  return cat;
}

UnicodeString_Api operator+(
    const UnicodeChar* lhs,
    UnicodeString_Api&& rhs
) {
  UnicodeString_Api cat(std::move(rhs));
  cat += lhs;

  return cat;
}

UnicodeString_Api operator+(
    const UnicodeChar& lhs,
    UnicodeString_Api&& rhs
) {
  UnicodeString_Api cat(std::move(rhs));
  cat += lhs;

  return cat;
}

bool operator==(
    const UnicodeString_Api& lhs,
    const UnicodeString_Api& rhs
) noexcept {
  int compare_result = lhs.compare(rhs);

  return compare_result == 0;
}

bool operator==(
    const UnicodeString_Api& lhs,
    const UnicodeChar* rhs
) noexcept {
  int compare_result = lhs.compare(rhs);

  return compare_result == 0;
}

std::strong_ordering operator<=>(
    const UnicodeString_Api& lhs,
    const UnicodeString_Api& rhs
) noexcept {
  int compare_result = lhs.compare(rhs);

  return compare_result <=> 0;
}

std::strong_ordering operator<=>(
    const UnicodeString_Api& lhs,
    const UnicodeChar* rhs
) noexcept {
  int compare_result = lhs.compare(rhs);

  return compare_result <=> 0;
}

} // namespace d2
