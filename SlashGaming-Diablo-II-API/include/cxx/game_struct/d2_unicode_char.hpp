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

#include <memory>

#include "../../dllexport_define.inc"

namespace d2 {

struct UnicodeChar;

class DLLEXPORT UnicodeChar_ConstWrapper {
 public:
  UnicodeChar_ConstWrapper() = delete;
  UnicodeChar_ConstWrapper(const UnicodeChar* ptr) noexcept;

  UnicodeChar_ConstWrapper(const UnicodeChar_ConstWrapper& other);
  UnicodeChar_ConstWrapper(UnicodeChar_ConstWrapper&& other) noexcept;

  virtual ~UnicodeChar_ConstWrapper();

  UnicodeChar_ConstWrapper& operator=(const UnicodeChar_ConstWrapper& other);
  UnicodeChar_ConstWrapper& operator=(UnicodeChar_ConstWrapper&& other) noexcept;

  operator unsigned short() const noexcept;

  const UnicodeChar* Get() const noexcept;

  unsigned short GetChar() const noexcept;

 private:
  const UnicodeChar* ptr_;
};

class DLLEXPORT UnicodeChar_Wrapper : public UnicodeChar_ConstWrapper {
 public:
  UnicodeChar_Wrapper() = delete;
  UnicodeChar_Wrapper(UnicodeChar* ptr) noexcept;

  UnicodeChar_Wrapper(const UnicodeChar_Wrapper& other);
  UnicodeChar_Wrapper(UnicodeChar_Wrapper&& other) noexcept;

  ~UnicodeChar_Wrapper() override;

  UnicodeChar_Wrapper& operator=(const UnicodeChar_Wrapper& other);
  UnicodeChar_Wrapper& operator=(UnicodeChar_Wrapper&& other) noexcept;

  UnicodeChar* Get() noexcept;

  void SetChar(unsigned short ch) noexcept;

 private:
  UnicodeChar* ptr_;
};

class DLLEXPORT UnicodeChar_API : public UnicodeChar_Wrapper {
 public:
  UnicodeChar_API();
  UnicodeChar_API(unsigned short ch);

  UnicodeChar_API(const UnicodeChar_API& other);
  UnicodeChar_API(UnicodeChar_API&& other) noexcept;

  ~UnicodeChar_API() override;

  UnicodeChar_API& operator=(const UnicodeChar_API& other);
  UnicodeChar_API& operator=(UnicodeChar_API&& other) noexcept;
};

// Do not derive from std::char_traits because of non-conformance with
// return types.
class DLLEXPORT UnicodeCharTraits {
  static int length(const UnicodeChar* str);
};

// Do not derive from std::basic_string, for same reasons as
// UnicodeCharTraits.
class DLLEXPORT UnicodeString {
  using traits_type = UnicodeCharTraits;
  using value_type = UnicodeChar;
  using size_type = int;
  using reference = value_type&;
  using const_reference = const value_type&;

 public:
  size_type length() const noexcept;
  size_type size() const noexcept;

 private:
  UnicodeString::size_type length_;
};

} // namespace d2

#include "../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_UNICODE_CHAR_HPP_
