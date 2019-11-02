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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_UNICODE_STRING_API_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_UNICODE_STRING_API_HPP_

#include <memory>
#include <string>
#include <string_view>
#include <variant>

#include "../helper/d2_draw_options.hpp"
#include "d2_unicode_char.hpp"
#include "d2_unicode_string_view_api.hpp"

#include "../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT UnicodeString_API {
 public:
  using value_type = UnicodeChar;
  using size_type = int;
  using reference = value_type&;
  using const_reference = const value_type&;
  using pointer = value_type*;
  using const_pointer = const value_type*;

  UnicodeString_API();
  UnicodeString_API(size_type size, const value_type& ch);
  UnicodeString_API(const UnicodeString_API& str);
  UnicodeString_API(const UnicodeString_API& str, size_type pos);
  UnicodeString_API(
      const UnicodeString_API& str,
      size_type pos,
      size_type count
  );
  UnicodeString_API(const value_type* str);
  UnicodeString_API(const value_type* str, size_type count);
  UnicodeString_API(UnicodeString_API&& str) noexcept;

  ~UnicodeString_API();

  UnicodeString_API& operator=(const UnicodeString_API& str);
  UnicodeString_API& operator=(UnicodeString_API&& other) noexcept;
  UnicodeString_API& operator=(const value_type* str);
  UnicodeString_API& operator=(const value_type& str);

  UnicodeString_API& operator+=(const UnicodeString_API& str);
  UnicodeString_API& operator+=(const value_type& ch);
  UnicodeString_API& operator+=(const value_type* str);

  operator UnicodeStringView_API() const noexcept;

  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;

  static UnicodeString_API FromU8String(std::u8string_view src);

  std::u8string ToU8String() const;

  UnicodeString_API& append(size_type count, const value_type& ch);
  UnicodeString_API& append(const UnicodeString_API& str);
  UnicodeString_API& append(
      const UnicodeString_API& str,
      size_type pos
  );
  UnicodeString_API& append(
      const UnicodeString_API& str,
      size_type pos,
      size_type count
  );
  UnicodeString_API& append(const value_type* str);
  UnicodeString_API& append(const value_type* str, size_type count);

  reference at(size_type pos);
  const_reference at(size_type pos) const;

  value_type& back();
  const value_type& back() const;

  void clear() noexcept;

  size_type copy(
      value_type* dest,
      size_type count
  ) const;
  size_type copy(
      value_type* dest,
      size_type count,
      size_type pos
  ) const;

  void Draw(int position_x, int position_y) const;
  void Draw(int position_x, int position_y, const DrawTextOptions& options) const;

  [[nodiscard]]
  bool empty() const noexcept;

  bool ends_with(UnicodeStringView_API x) const noexcept;
  bool ends_with(const value_type& x) const noexcept;
  bool ends_with(const value_type* x) const;

  value_type& front();
  const value_type& front() const;

  void pop_back();

  void push_back(const value_type& ch);

  void resize(size_type count);
  void resize(size_type count, const value_type& ch);

  void shrink_to_fit();

  bool starts_with(UnicodeStringView_API x) const noexcept;
  bool starts_with(const value_type& x) const noexcept;
  bool starts_with(const value_type* x) const;

  UnicodeString_API substr() const;
  UnicodeString_API substr(size_type pos) const;
  UnicodeString_API substr(size_type pos, size_type count) const;

  void swap(UnicodeString_API& other);

  UnicodeChar* data() noexcept;
  const UnicodeChar* data() const noexcept;

  size_type capacity() const noexcept;
  const UnicodeChar* c_str() const noexcept;
  size_type size() const noexcept;
  size_type length() const noexcept;

 private:
  std::variant<
      std::unique_ptr<std::basic_string<UnicodeChar_1_00>>
  > str_;

  UnicodeString_API(std::basic_string<UnicodeChar_1_00>&& str);
};

UnicodeString_API operator+(
    const UnicodeString_API& lhs,
    const UnicodeString_API& rhs
);
UnicodeString_API operator+(
    const UnicodeString_API& lhs,
    const UnicodeChar* rhs
);
UnicodeString_API operator+(
    const UnicodeString_API& lhs,
    const UnicodeChar& rhs
);
UnicodeString_API operator+(
    const UnicodeChar* lhs,
    const UnicodeString_API& rhs
);
UnicodeString_API operator+(
    const UnicodeChar& lhs,
    const UnicodeString_API& rhs
);
UnicodeString_API operator+(
    UnicodeString_API&& lhs,
    UnicodeString_API&& rhs
);
UnicodeString_API operator+(
    UnicodeString_API&& lhs,
    const UnicodeString_API& rhs
);
UnicodeString_API operator+(
    UnicodeString_API&& lhs,
    const UnicodeChar* rhs
);
UnicodeString_API operator+(
    UnicodeString_API&& lhs,
    const UnicodeChar& rhs
);
UnicodeString_API operator+(
    const UnicodeString_API& lhs,
    UnicodeString_API&& rhs
);
UnicodeString_API operator+(
    const UnicodeChar* lhs,
    UnicodeString_API&& rhs
);
UnicodeString_API operator+(
    const UnicodeChar& lhs,
    UnicodeString_API&& rhs
);

} // namespace d2

#include "../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_UNICODE_STRING_API_HPP_
