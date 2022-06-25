/**
 * SlashGaming Diablo II Modding API for C++
 * Copyright (C) 2018-2022  Mir Drualga
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

  constexpr UnicodeStringView_Api(
      const UnicodeStringView_Api& other
  ) noexcept = default;

  UnicodeStringView_Api(const value_type* s, size_type count);

  UnicodeStringView_Api(const value_type* s);

  ~UnicodeStringView_Api() noexcept = default;

  constexpr UnicodeStringView_Api& operator=(
      const UnicodeStringView_Api& view
  ) noexcept = default;

  friend bool operator==(
      UnicodeStringView_Api lhs,
      UnicodeStringView_Api rhs
  ) noexcept {
    return lhs.compare(rhs) == 0;
  }

  friend std::strong_ordering operator<=>(
      UnicodeStringView_Api lhs,
      UnicodeStringView_Api rhs
  ) noexcept {
    int compare_result = lhs.compare(rhs);

    return compare_result <=> 0;
  }

  /**
   * Element access
   */

  constexpr const_reference operator[](
      size_type pos
  ) const {
    const auto* actual_pointer = std::visit(
        [pos](const auto& actual_view) {
          return reinterpret_cast<const_pointer>(
              &actual_view[pos]
          );
        },
        this->view_
    );

    return *actual_pointer;
  }

  constexpr const_reference at(size_type pos) const {
    return *std::visit(
        [pos](const auto& actual_view) {
          return reinterpret_cast<const_pointer>(&actual_view.at(pos));
        },
        this->view_
    );
  }

  constexpr const_reference front() const {
    return *std::visit(
        [](auto& actual_view) {
          return reinterpret_cast<const_pointer>(&actual_view.front());
        },
        this->view_
    );
  }

  constexpr const_reference back() const {
    return *std::visit(
        [](const auto& actual_view) {
          return reinterpret_cast<const_pointer>(&actual_view.back());
        },
        this->view_
    );
  }

  constexpr const_pointer data() const noexcept {
    return std::visit(
        [](const auto& actual_view) {
          return reinterpret_cast<const_pointer>(actual_view.data());
        },
        this->view_
    );
  }

  /**
   * Capacity
   */

  constexpr size_type size() const noexcept {
    return std::visit(
        [](const auto& actual_view) {
          return actual_view.size();
        },
        this->view_
    );
  }

  constexpr size_type length() const noexcept {
    return std::visit(
        [](const auto& actual_view) {
          return actual_view.length();
        },
        this->view_
    );
  }

  constexpr size_type max_size() const noexcept {
    return std::visit(
        [](const auto& actual_view) {
          return actual_view.max_size();
        },
        this->view_
    );
  }

  [[nodiscard]] constexpr bool empty() const noexcept {
    return std::visit(
        [](const auto& actual_view) {
          return actual_view.empty();
        },
        this->view_
    );
  }

  /**
   * Modifiers
   */

  constexpr void remove_prefix(size_type n) {
    std::visit(
        [n](auto& actual_view) {
          return actual_view.remove_prefix(n);
        },
        this->view_
    );
  }

  constexpr void remove_suffix(size_type n) {
    std::visit(
        [n](auto& actual_view) {
          return actual_view.remove_suffix(n);
        },
        this->view_
    );
  }

  constexpr void swap(UnicodeStringView_Api& v) noexcept {
    std::visit(
        [&v](auto& actual_view) {
          using UnicodeStringView_T = std::remove_reference_t<
              decltype(actual_view)
          >;

          UnicodeStringView_T& actual_v =
              std::get<UnicodeStringView_T>(v.view_);

          return actual_view.swap(actual_v);
        },
        this->view_
    );
  }

  /**
   * Operations
   */

  constexpr size_type copy(
      value_type* dest,
      size_type count,
      size_type pos = 0
  ) const {
    return std::visit(
        [dest, count, pos](const auto& actual_src_view) {
          using UnicodeStringView_T = std::remove_reference_t<
              decltype(actual_src_view)
          >;
          using UnicodeChar_T = typename UnicodeStringView_T::value_type;

          UnicodeChar_T* actual_dest = reinterpret_cast<UnicodeChar_T*>(dest);

          return actual_src_view.copy(actual_dest, count, pos);
        },
        this->view_
    );
  }

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

  constexpr int compare(const value_type* s) const {
    return std::visit(
        [s](const auto& actual_src_view) {
          using UnicodeStringView_T = std::remove_const_t<
              std::remove_reference_t<decltype(actual_src_view)>
          >;
          using UnicodeChar_T = typename UnicodeStringView_T::value_type;

          const UnicodeChar_T* actual_s =
              reinterpret_cast<const UnicodeChar_T*>(s);

          return actual_src_view.compare(actual_s);
        },
        this->view_
    );
  }

  constexpr int compare(
      size_type pos1,
      size_type count1,
      const value_type* s
  ) const {
    return std::visit(
        [pos1, count1, s](const auto& actual_src_view) {
          using UnicodeStringView_T = std::remove_const_t<
              std::remove_reference_t<decltype(actual_src_view)>
          >;
          using UnicodeChar_T = typename UnicodeStringView_T::value_type;

          const UnicodeChar_T* actual_s =
              reinterpret_cast<const UnicodeChar_T*>(s);

          return actual_src_view.compare(pos1, count1, actual_s);
        },
        this->view_
    );
  }

  constexpr int compare(
      size_type pos1,
      size_type count1,
      const value_type* s,
      size_type count2
  ) const {
    return std::visit(
        [pos1, count1, s, count2](const auto& actual_src_view) {
          using UnicodeStringView_T = std::remove_const_t<
              std::remove_reference_t<decltype(actual_src_view)>
          >;
          using UnicodeChar_T = typename UnicodeStringView_T::value_type;

          const UnicodeChar_T* actual_s =
              reinterpret_cast<const UnicodeChar_T*>(s);

          return actual_src_view.compare(pos1, count1, actual_s, count2);
        },
        this->view_
    );
  }

  bool starts_with(UnicodeStringView_Api sv) const noexcept;

  constexpr bool starts_with(const value_type& c) const noexcept {
    return std::visit(
        [&c](const auto& actual_str_view) {
          using UnicodeStringView_T = std::remove_reference_t<
              decltype(actual_str_view)
          >;
          using UnicodeChar_T = typename UnicodeStringView_T::value_type;

          const UnicodeChar_T& actual_c =
              reinterpret_cast<const UnicodeChar_T&>(c);

          return actual_str_view.starts_with(actual_c);
        },
        this->view_
    );
  }

  constexpr bool starts_with(const value_type* s) const {
    return std::visit(
        [s](const auto& actual_view) {
          using UnicodeStringView_T = std::remove_reference_t<
              decltype(actual_view)
          >;
          using UnicodeChar_T = typename UnicodeStringView_T::value_type;

          const UnicodeChar_T* actual_s =
              reinterpret_cast<const UnicodeChar_T*>(s);

          return actual_view.starts_with(actual_s);
        },
        this->view_
    );
  }

  bool ends_with(UnicodeStringView_Api sv) const noexcept;

  constexpr bool ends_with(const value_type& c) const noexcept {
    return std::visit(
        [&c](const auto& actual_str_view) {
          using UnicodeStringView_T = std::remove_reference_t<
              decltype(actual_str_view)
          >;
          using UnicodeChar_T = typename UnicodeStringView_T::value_type;

          const UnicodeChar_T& actual_c =
              reinterpret_cast<const UnicodeChar_T&>(c);

          return actual_str_view.ends_with(actual_c);
        },
        this->view_
    );
  }

  constexpr bool ends_with(const value_type* s) const {
    return std::visit(
        [s](const auto& actual_view) {
          using UnicodeStringView_T = std::remove_reference_t<
              decltype(actual_view)
          >;
          using UnicodeChar_T = typename UnicodeStringView_T::value_type;

          const UnicodeChar_T* actual_s =
              reinterpret_cast<const UnicodeChar_T*>(s);

          return actual_view.ends_with(actual_s);
        },
        this->view_
    );
  }

  /**
   * Search
   */

  size_type find(
      UnicodeStringView_Api v,
      size_type pos = 0
  ) const noexcept;

  constexpr size_type find(
      value_type& ch,
      size_type pos = 0
  ) const noexcept {
    return std::visit(
        [&ch, pos](const auto& actual_view) {
          using UnicodeStringView_T = std::remove_const_t<
              std::remove_reference_t<decltype(actual_view)>
          >;
          using UnicodeChar_T = typename UnicodeStringView_T::value_type;

          UnicodeChar_T& actual_ch =
              reinterpret_cast<UnicodeChar_T&>(ch);

          return actual_view.find(actual_ch, pos);
        },
        this->view_
    );
  }

  constexpr size_type find(
      const value_type* s,
      size_type pos,
      size_type count
  ) const {
    return std::visit(
        [s, pos, count](const auto& actual_view) {
          using UnicodeStringView_T = std::remove_const_t<
              std::remove_reference_t<decltype(actual_view)>
          >;
          using UnicodeChar_T = typename UnicodeStringView_T::value_type;

          const UnicodeChar_T* actual_s =
              reinterpret_cast<const UnicodeChar_T*>(s);

          return actual_view.find(actual_s, pos, count);
        },
        this->view_
    );
  }

  constexpr size_type find(
      const value_type* s,
      size_type pos
  ) const {
    return std::visit(
        [s, pos](const auto& actual_view) {
          using UnicodeStringView_T = std::remove_const_t<
              std::remove_reference_t<decltype(actual_view)>
          >;
          using UnicodeChar_T = typename UnicodeStringView_T::value_type;

          const UnicodeChar_T* actual_s =
              reinterpret_cast<const UnicodeChar_T*>(s);

          return actual_view.find(actual_s, pos);
        },
        this->view_
    );
  }

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

  constexpr explicit UnicodeStringView_Api(
      ApiVariant view
  ) noexcept
      : view_(::std::move(view)) {
  }
};

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_UNICODE_CHAR_D2_UNICODE_STRING_VIEW_API_HPP_
