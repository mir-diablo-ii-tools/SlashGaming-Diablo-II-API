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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_UNICODE_CHAR_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_UNICODE_CHAR_HPP_

#include <string>
#include <string_view>
#include <memory>

#include "../../dllexport_define.inc"

namespace d2 {

/*
 * Due to the nature of how this API must be implemented (information hiding
 * being necessary to prevent user-created errors), all string APIs cannot be
 * derived from the dtandard library's.
 */

struct UnicodeChar;

class DLLEXPORT UnicodeChar_Wrapper {
 public:
  UnicodeChar_Wrapper() = delete;

  UnicodeChar_Wrapper(const UnicodeChar_Wrapper& other);
  UnicodeChar_Wrapper(UnicodeChar_Wrapper&& other) noexcept;

  virtual ~UnicodeChar_Wrapper();

  UnicodeChar_Wrapper& operator=(const UnicodeChar_Wrapper& other);
  UnicodeChar_Wrapper& operator=(UnicodeChar_Wrapper&& other) noexcept;

  static UnicodeChar_Wrapper FromPointer(UnicodeChar* ptr);
  static const UnicodeChar_Wrapper FromPointer(const UnicodeChar* ptr);

  UnicodeChar* Get() noexcept;
  const UnicodeChar* Get() const noexcept;

  void SetChar(char16_t ch) noexcept;
  void SetChar(const UnicodeChar_Wrapper& ch) noexcept;

 private:
  UnicodeChar* ptr_;

  UnicodeChar_Wrapper(UnicodeChar* ptr) noexcept;
  UnicodeChar_Wrapper(const UnicodeChar* ptr) noexcept;
};

class DLLEXPORT UnicodeChar_Traits {
 public:
  using char_type = UnicodeChar;

  static void assign(char_type& r, const char_type& a) noexcept;
  static char_type* assign(char_type* p, std::size_t count, const char_type& a);
  static bool eq(const char_type& a, const char_type& b);
  static bool lt(const char_type& a, const char_type& b);
  static char_type* move(char_type* dest, const char_type* src, std::size_t count);
  static char_type* copy(char_type* dest, const char_type* src, std::size_t count);
  static int compare(const char_type* s1, const char_type* s2, std::size_t count);
  static const UnicodeChar_Traits::char_type* find(
      const char_type* p,
      std::size_t count,
      const char_type& ch
  );
};

class DLLEXPORT UnicodeString_API {
 public:
  using char_type = UnicodeChar;
  using size_type = int;
  using reference = char_type&;
  using const_reference = const char_type&;
  using pointer = char_type*;
  using const_pointer = const char_type*;

  UnicodeString_API();
  UnicodeString_API(size_type size, const char_type& ch);
  UnicodeString_API(const UnicodeString_API& str);
  UnicodeString_API(const UnicodeString_API& str, size_type pos);
  UnicodeString_API(
      const UnicodeString_API& str,
      size_type pos,
      size_type count
  );
  UnicodeString_API(const char_type* str);
  UnicodeString_API(const char_type* str, size_type count);
  UnicodeString_API(UnicodeString_API&& str) noexcept;

  virtual ~UnicodeString_API();

  UnicodeString_API& operator=(const UnicodeString_API& str);
  UnicodeString_API& operator=(UnicodeString_API&& other) noexcept;
  UnicodeString_API& operator=(const char_type* str);
  UnicodeString_API& operator=(const char_type& str);

  UnicodeString_API& operator+=(const UnicodeString_API& str);
  UnicodeString_API& operator+=(const char_type& ch);
  UnicodeString_API& operator+=(const char_type* str);

  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;

  static UnicodeString_API FromU8String(std::u8string_view src);

  std::u8string ToU8String() const;

  UnicodeString_API& append(size_type count, const char_type& ch);
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
  UnicodeString_API& append(const char_type* str);
  UnicodeString_API& append(const char_type* str, size_type count);

  reference at(size_type pos);
  const_reference at(size_type pos) const;

  char_type& back();
  const char_type& back() const;

  void clear() noexcept;

  size_type copy(
      char_type* dest,
      size_type count
  ) const;
  size_type copy(
      char_type* dest,
      size_type count,
      size_type pos
  ) const;

  [[nodiscard]]
  bool empty() const noexcept;

  char_type& front();
  const char_type& front() const;

  void pop_back();

  void push_back(const char_type& ch);

  void resize(size_type count);
  void resize(size_type count, const char_type& ch);

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
  UnicodeChar* data_;
  size_type capacity_;
  size_type length_;

  static void TerminateString(char_type* str, size_type pos);
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
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_UNICODE_CHAR_HPP_
