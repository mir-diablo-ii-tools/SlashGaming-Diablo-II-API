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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_UNICODE_STRING_VIEW_API_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_UNICODE_STRING_VIEW_API_HPP_

#include <string_view>
#include <memory>
#include <variant>

#include "../helper/d2_draw_options.hpp"
#include "d2_unicode_char.hpp"

#include "../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT UnicodeStringView_API {
 public:
  using value_type = UnicodeChar;
  using size_type = int;
  using reference = value_type&;
  using const_reference = const value_type&;
  using pointer = value_type*;
  using const_pointer = const value_type*;

  UnicodeStringView_API() noexcept;
  UnicodeStringView_API(const UnicodeStringView_API& other) noexcept;
  UnicodeStringView_API(UnicodeStringView_API&& other) noexcept;
  UnicodeStringView_API(const value_type* s, size_type count);
  UnicodeStringView_API(const value_type* s);

  ~UnicodeStringView_API() noexcept;

  UnicodeStringView_API& operator=(
      const UnicodeStringView_API& view
  ) noexcept;

  UnicodeStringView_API& operator=(
      UnicodeStringView_API&& view
  ) noexcept;

  const_reference operator[](size_type pos) const;

  const_reference at(size_type pos) const;

  const_reference back() const;

  int compare(UnicodeStringView_API v) const noexcept;
  int compare(
      size_type pos1,
      size_type count1,
      UnicodeStringView_API v
  ) const;
  int compare(
      size_type pos1,
      size_type count1,
      UnicodeStringView_API v,
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

  size_type copy(value_type* dest, size_type count) const;
  size_type copy(value_type* dest, size_type count, size_type pos) const;

  void Draw(int position_x, int position_y) const;
  void Draw(int position_x, int position_y, const DrawTextOptions& options) const;

  [[nodiscard]]
  bool empty() const noexcept;

  const_reference front() const;

  UnicodeStringView_API substr() const;
  UnicodeStringView_API substr(size_type pos) const;
  UnicodeStringView_API substr(size_type pos, size_type count) const;

  const_pointer data() const noexcept;
  size_type length() const noexcept;
  size_type size() const noexcept;

 private:
  std::variant<
    std::unique_ptr<std::basic_string_view<UnicodeChar_1_00>>
  > view_;

  explicit UnicodeStringView_API(
      std::basic_string_view<UnicodeChar_1_00>&& ptr
  );
};

} // namespace d2

#include "../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_UNICODE_STRING_VIEW_API_HPP_
