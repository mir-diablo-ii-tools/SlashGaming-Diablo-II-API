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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_UNICODE_CHAR_D2_UNICODE_STRING_VIEW_API_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_UNICODE_CHAR_D2_UNICODE_STRING_VIEW_API_HPP_

#include <compare>
#include <string_view>
#include <memory>
#include <variant>

#include "../../helper/d2_draw_options.hpp"
#include "d2_unicode_char_struct.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT UnicodeStringView_Api {
 public:
  using value_type = UnicodeChar;
  using size_type = int;
  using reference = value_type&;
  using const_reference = const value_type&;
  using pointer = value_type*;
  using const_pointer = const value_type*;

  static constexpr size_type npos = size_type(-1);

  UnicodeStringView_Api() noexcept;
  UnicodeStringView_Api(const UnicodeStringView_Api& other) noexcept;
  UnicodeStringView_Api(UnicodeStringView_Api&& other) noexcept;
  UnicodeStringView_Api(const value_type* s, size_type count);
  UnicodeStringView_Api(const value_type* s);

  ~UnicodeStringView_Api() noexcept;

  UnicodeStringView_Api& operator=(
      const UnicodeStringView_Api& view
  ) noexcept;

  UnicodeStringView_Api& operator=(
      UnicodeStringView_Api&& view
  ) noexcept;

  /**
   * Element access
   */

  const_reference operator[](size_type pos) const;

  const_reference at(size_type pos) const;
  const_reference front() const;
  const_reference back() const;
  const_pointer data() const noexcept;

  /**
   * Capacity
   */

  size_type size() const noexcept;
  size_type length() const noexcept;
  size_type max_size() const noexcept;
  [[nodiscard]] bool empty() const noexcept;

  /**
   * Modifiers
   */

  void remove_prefix(size_type n);
  void remove_suffix(size_type n);
  void swap(UnicodeStringView_Api& v) noexcept;

  /**
   * Operations
   */

  size_type copy(value_type* dest, size_type count) const;
  size_type copy(value_type* dest, size_type count, size_type pos) const;

  UnicodeStringView_Api substr() const;
  UnicodeStringView_Api substr(size_type pos) const;
  UnicodeStringView_Api substr(size_type pos, size_type count) const;

  int compare(UnicodeStringView_Api v) const noexcept;
  int compare(
      size_type pos1,
      size_type count1,
      UnicodeStringView_Api v
  ) const;
  int compare(
      size_type pos1,
      size_type count1,
      UnicodeStringView_Api v,
      size_type pos2,
      size_type count2
  ) const;
  int compare(const value_type* s) const;
  int compare(
      size_type pos1,
      size_type count1,
      const value_type* s
  ) const;
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

  /**
   * Search
   */

  size_type find(UnicodeStringView_Api v, size_type pos = 0) const noexcept;
  size_type find(value_type& ch, size_type pos = 0) const noexcept;
  size_type find(const value_type* s, size_type pos, size_type count) const;
  size_type find(const value_type* s, size_type pos = 0) const;

  /**
   * Extended Diablo II functions
   */

  void Draw(int position_x, int position_y) const;
  void Draw(int position_x, int position_y, const DrawTextOptions& options) const;

 private:
  using ApiVariant = std::variant<
      std::basic_string_view<UnicodeChar_1_00>
  >;

  ApiVariant view_;

  explicit UnicodeStringView_Api(
      ApiVariant&& ptr
  );
};

DLLEXPORT bool operator==(
    UnicodeStringView_Api lhs,
    UnicodeStringView_Api rhs
) noexcept;

DLLEXPORT std::strong_ordering operator<=>(
    UnicodeStringView_Api lhs,
    UnicodeStringView_Api rhs
) noexcept;

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_UNICODE_CHAR_D2_UNICODE_STRING_VIEW_API_HPP_
