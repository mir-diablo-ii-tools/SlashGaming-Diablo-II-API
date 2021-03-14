/**
 * SlashGaming Diablo II Modding API for C++
 * Copyright (C) 2018-2021  Mir Drualga
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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_UNICODE_CHAR_D2_UNICODE_STRING_API_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_UNICODE_CHAR_D2_UNICODE_STRING_API_HPP_

#include <memory>
#include <string>
#include <string_view>
#include <variant>

#include "../../helper/d2_draw_options.hpp"
#include "d2_unicode_char_struct.hpp"
#include "d2_unicode_string_view_api.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT UnicodeString_Api {
 public:
  using value_type = UnicodeChar;
  using size_type = int;
  using reference = value_type&;
  using const_reference = const value_type&;
  using pointer = value_type*;
  using const_pointer = const value_type*;

  static const size_type npos = -1;

  UnicodeString_Api();
  UnicodeString_Api(size_type size, const value_type& ch);
  UnicodeString_Api(const UnicodeString_Api& str);
  UnicodeString_Api(const UnicodeString_Api& str, size_type pos);
  UnicodeString_Api(
      const UnicodeString_Api& str,
      size_type pos,
      size_type count
  );
  UnicodeString_Api(const value_type* str);
  UnicodeString_Api(const value_type* str, size_type count);
  UnicodeString_Api(UnicodeString_Api&& str) noexcept;

  ~UnicodeString_Api();

  UnicodeString_Api& operator=(const UnicodeString_Api& str);
  UnicodeString_Api& operator=(UnicodeString_Api&& other) noexcept;
  UnicodeString_Api& operator=(const value_type* str);
  UnicodeString_Api& operator=(const value_type& str);

  UnicodeString_Api& operator+=(const UnicodeString_Api& str);
  UnicodeString_Api& operator+=(const value_type& ch);
  UnicodeString_Api& operator+=(const value_type* str);

  operator UnicodeStringView_Api() const noexcept;

  /**
   * Element access
   */

  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;

  reference at(size_type pos);
  const_reference at(size_type pos) const;

  value_type& front();
  const value_type& front() const;

  value_type& back();
  const value_type& back() const;

  value_type* data() noexcept;
  const value_type* data() const noexcept;

  const value_type* c_str() const noexcept;

  /**
   * Capacity
   */

  [[nodiscard]] bool empty() const noexcept;
  size_type size() const noexcept;
  size_type length() const noexcept;
  size_type max_size() const noexcept;
  void reserve(size_type new_cap);
  size_type capacity() const noexcept;
  void shrink_to_fit();

  /**
   * Operations
   */

  UnicodeString_Api& assign(size_type count, const value_type& ch);
  UnicodeString_Api& assign(const UnicodeString_Api& str);
  UnicodeString_Api& assign(
      const UnicodeString_Api& str,
      size_type pos,
      size_type count = npos
  );
  UnicodeString_Api& assign(UnicodeString_Api&& str) noexcept;
  UnicodeString_Api& assign(const value_type* s, size_type count);
  UnicodeString_Api& assign(const value_type* s);

  void clear() noexcept;

  UnicodeString_Api& insert(
      size_type index,
      size_type count,
      const value_type& ch
  );
  UnicodeString_Api& insert(
      size_type index,
      const value_type* ch
  );
  UnicodeString_Api& insert(
      size_type index,
      const value_type* ch,
      size_type count
  );
  UnicodeString_Api& insert(
      size_type index,
      const UnicodeString_Api& str,
      size_type index_str,
      size_type count = npos
  );

  UnicodeString_Api& erase(
      size_type index = 0,
      size_type count = npos
  );

  void push_back(const value_type& ch);
  void pop_back();

  UnicodeString_Api& append(size_type count, const value_type& ch);
  UnicodeString_Api& append(const UnicodeString_Api& str);
  UnicodeString_Api& append(
      const UnicodeString_Api& str,
      size_type pos
  );
  UnicodeString_Api& append(
      const UnicodeString_Api& str,
      size_type pos,
      size_type count
  );
  UnicodeString_Api& append(const value_type* str);
  UnicodeString_Api& append(const value_type* str, size_type count);

  int compare(const UnicodeString_Api& str) const noexcept;
  int compare(
      size_type pos1,
      size_type count1,
      const UnicodeString_Api& str
  ) const;
  int compare(
      size_type pos1,
      size_type count1,
      const UnicodeString_Api& str,
      size_type pos2,
      size_type count2 = npos
  ) const;
  int compare(const value_type* s) const;
  int compare(size_type pos1, size_type count1, const value_type* s) const;
  int compare(
      size_type pos1,
      size_type count1,
      const value_type* s,
      size_type count2
  ) const;

  bool starts_with(UnicodeStringView_Api sv) const noexcept;
  bool starts_with(const value_type& c) const noexcept;
  bool starts_with(const value_type* s) const;

  bool ends_with(UnicodeStringView_Api sv) const noexcept;
  bool ends_with(const value_type& c) const noexcept;
  bool ends_with(const value_type* s) const;

  UnicodeString_Api substr() const;
  UnicodeString_Api substr(size_type pos) const;
  UnicodeString_Api substr(size_type pos, size_type count) const;

  size_type copy(
      value_type* dest,
      size_type count,
      size_type pos = 0
  ) const;

  void resize(size_type count);
  void resize(size_type count, const value_type& ch);

  void swap(UnicodeString_Api& other);

  /**
   * Extended Diablo II functions
   */

  void Draw(int position_x, int position_y) const;
  void Draw(int position_x, int position_y, const DrawTextOptions& options) const;

  static UnicodeString_Api FromUtf8String(std::u8string_view src);

  std::u8string ToUtf8String() const;

 private:
  using ApiVariant = std::variant<
      std::basic_string<UnicodeChar_1_00>
  >;

  ApiVariant str_;

  UnicodeString_Api(ApiVariant&& str);
};

DLLEXPORT UnicodeString_Api operator+(
    const UnicodeString_Api& lhs,
    const UnicodeString_Api& rhs
);
DLLEXPORT UnicodeString_Api operator+(
    const UnicodeString_Api& lhs,
    const UnicodeChar* rhs
);
DLLEXPORT UnicodeString_Api operator+(
    const UnicodeString_Api& lhs,
    const UnicodeChar& rhs
);
DLLEXPORT UnicodeString_Api operator+(
    const UnicodeChar* lhs,
    const UnicodeString_Api& rhs
);
DLLEXPORT UnicodeString_Api operator+(
    const UnicodeChar& lhs,
    const UnicodeString_Api& rhs
);
DLLEXPORT UnicodeString_Api operator+(
    UnicodeString_Api&& lhs,
    UnicodeString_Api&& rhs
);
DLLEXPORT UnicodeString_Api operator+(
    UnicodeString_Api&& lhs,
    const UnicodeString_Api& rhs
);
DLLEXPORT UnicodeString_Api operator+(
    UnicodeString_Api&& lhs,
    const UnicodeChar* rhs
);
DLLEXPORT UnicodeString_Api operator+(
    UnicodeString_Api&& lhs,
    const UnicodeChar& rhs
);
DLLEXPORT UnicodeString_Api operator+(
    const UnicodeString_Api& lhs,
    UnicodeString_Api&& rhs
);
DLLEXPORT UnicodeString_Api operator+(
    const UnicodeChar* lhs,
    UnicodeString_Api&& rhs
);
DLLEXPORT UnicodeString_Api operator+(
    const UnicodeChar& lhs,
    UnicodeString_Api&& rhs
);

DLLEXPORT bool operator==(
    const UnicodeString_Api& lhs,
    const UnicodeString_Api& rhs
) noexcept;

DLLEXPORT bool operator==(
    const UnicodeString_Api& lhs,
    const UnicodeChar* rhs
) noexcept;

DLLEXPORT std::strong_ordering operator<=>(
    const UnicodeString_Api& lhs,
    const UnicodeString_Api& rhs
) noexcept;

DLLEXPORT std::strong_ordering operator<=>(
    const UnicodeString_Api& lhs,
    const UnicodeChar* rhs
) noexcept;

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_UNICODE_CHAR_D2_UNICODE_STRING_API_HPP_
