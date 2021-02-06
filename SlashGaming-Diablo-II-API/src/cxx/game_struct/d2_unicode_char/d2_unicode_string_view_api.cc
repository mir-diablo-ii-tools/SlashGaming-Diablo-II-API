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

#include "../../../../include/cxx/game_struct/d2_unicode_char/d2_unicode_string_view_api.hpp"

#include <windows.h>
#include <stdexcept>

#include <fmt/format.h>
#include "../../../../include/cxx/game_function/d2lang_function.hpp"
#include "../../../../include/cxx/game_function/d2win_function.hpp"
#include "../../../../include/cxx/game_version.hpp"

namespace d2 {
namespace {

using UnicodeStringView_1_00 = std::basic_string_view<UnicodeChar_1_00>;

} // namespace

UnicodeStringView_Api::UnicodeStringView_Api() noexcept :
    view_([]() {
      return UnicodeStringView_1_00();
    }()) {
}

UnicodeStringView_Api::UnicodeStringView_Api(
    const UnicodeStringView_Api& other
) noexcept :
    UnicodeStringView_Api(other.data(), other.length()) {
}

UnicodeStringView_Api::UnicodeStringView_Api(
    UnicodeStringView_Api&& other
) noexcept = default;

UnicodeStringView_Api::UnicodeStringView_Api(
    const value_type* s,
    size_type count
) : view_([s, count]() {
      const UnicodeChar_1_00* actual_s =
          reinterpret_cast<const UnicodeChar_1_00*>(s);

      return UnicodeStringView_1_00(actual_s, count);
    }()) {
}

UnicodeStringView_Api::UnicodeStringView_Api(const value_type* s)
  : view_([s]() {
      const UnicodeChar_1_00* actual_s =
          reinterpret_cast<const UnicodeChar_1_00*>(s);

      return UnicodeStringView_1_00(actual_s);
    }()) {
}

UnicodeStringView_Api::UnicodeStringView_Api(ApiVariant&& ptr)
    : view_(std::move(ptr)) {
}

UnicodeStringView_Api::~UnicodeStringView_Api() noexcept = default;

UnicodeStringView_Api& UnicodeStringView_Api::operator=(
    const UnicodeStringView_Api& view
) noexcept {
  *this = UnicodeStringView_Api(view);

  return *this;
}

UnicodeStringView_Api& UnicodeStringView_Api::operator=(
    UnicodeStringView_Api&& other
) noexcept = default;

UnicodeStringView_Api::const_reference UnicodeStringView_Api::operator[](
    size_type pos
) const {
  const auto* actual_pointer = std::visit(
      [pos](const auto& actual_view) {
        return &actual_view[pos];
      },
      this->view_
  );

  return *reinterpret_cast<const_pointer>(actual_pointer);
}

UnicodeStringView_Api::const_reference
UnicodeStringView_Api::at(size_type pos) const {
  return *std::visit(
      [pos](const auto& actual_view) {
        return reinterpret_cast<const_pointer>(&actual_view.at(pos));
      },
      this->view_
  );
}

UnicodeStringView_Api::const_reference UnicodeStringView_Api::front() const {
  return *std::visit(
      [](auto& actual_view) {
        return reinterpret_cast<const_pointer>(&actual_view.front());
      },
      this->view_
  );
}

UnicodeStringView_Api::const_reference UnicodeStringView_Api::back() const {
  return *std::visit(
      [](const auto& actual_view) {
        return reinterpret_cast<const_pointer>(&actual_view.back());
      },
      this->view_
  );
}

UnicodeStringView_Api::const_pointer
UnicodeStringView_Api::data() const noexcept {
  return std::visit(
      [](const auto& actual_view) {
        return reinterpret_cast<const_pointer>(actual_view.data());
      },
      this->view_
  );
}

UnicodeStringView_Api::size_type
UnicodeStringView_Api::size() const noexcept {
  return std::visit(
      [](const auto& actual_view) {
        return actual_view.size();
      },
      this->view_
  );
}

UnicodeStringView_Api::size_type
UnicodeStringView_Api::length() const noexcept {
  return std::visit(
      [](const auto& actual_view) {
        return actual_view.length();
      },
      this->view_
  );
}

UnicodeStringView_Api::size_type
UnicodeStringView_Api::max_size() const noexcept {
  return std::visit(
      [](const auto& actual_view) {
        return actual_view.max_size();
      },
      this->view_
  );
}

bool UnicodeStringView_Api::empty() const noexcept {
  return std::visit(
      [](const auto& actual_view) {
        return actual_view.empty();
      },
      this->view_
  );
}

void UnicodeStringView_Api::remove_prefix(size_type n) {
  std::visit(
      [n](auto& actual_view) {
        return actual_view.remove_prefix(n);
      },
      this->view_
  );
}

void UnicodeStringView_Api::remove_suffix(size_type n) {
  std::visit(
      [n](auto& actual_view) {
        return actual_view.remove_suffix(n);
      },
      this->view_
  );
}

void UnicodeStringView_Api::swap(UnicodeStringView_Api& v) noexcept {
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

UnicodeStringView_Api::size_type UnicodeStringView_Api::copy(
    value_type* dest,
    size_type count
) const {
  return std::visit(
      [dest, count](const auto& actual_src_view) {
        using UnicodeStringView_T = std::remove_reference_t<
            decltype(actual_src_view)
        >;
        using UnicodeChar_T = typename UnicodeStringView_T::value_type;

        UnicodeChar_T* actual_dest = reinterpret_cast<UnicodeChar_T*>(dest);

        return actual_src_view.copy(actual_dest, count);
      },
      this->view_
  );
}

UnicodeStringView_Api::size_type UnicodeStringView_Api::copy(
    value_type* dest,
    size_type count,
    size_type pos
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

UnicodeStringView_Api UnicodeStringView_Api::substr() const {
  return UnicodeStringView_Api(
      std::visit(
          [](const auto& actual_view) {
            return actual_view.substr();
          },
          this->view_
      )
  );
}

UnicodeStringView_Api UnicodeStringView_Api::substr(size_type pos) const {
  return UnicodeStringView_Api(
      std::visit(
          [pos](const auto& actual_view) {
            return actual_view.substr(pos);
          },
          this->view_
      )
  );
}

UnicodeStringView_Api UnicodeStringView_Api::substr(
    size_type pos,
    size_type count
) const {
  return UnicodeStringView_Api(
      std::visit(
          [pos, count](const auto& actual_view) {
            return actual_view.substr(pos, count);
          },
          this->view_
      )
  );
}

int UnicodeStringView_Api::compare(UnicodeStringView_Api v) const noexcept {
  return std::visit(
      [&v](const auto& actual_src_view) {
        using UnicodeStringView_T = std::remove_const_t<
            std::remove_reference_t<decltype(actual_src_view)>
        >;

        UnicodeStringView_T actual_v = std::get<UnicodeStringView_T>(v.view_);

        return actual_src_view.compare(actual_v);
      },
      this->view_
  );
}

int UnicodeStringView_Api::compare(
    size_type pos1,
    size_type count1,
    UnicodeStringView_Api v
) const {
  return std::visit(
      [pos1, count1, &v](const auto& actual_src_view) {
        using UnicodeStringView_T = std::remove_const_t<
            std::remove_reference_t<decltype(actual_src_view)>
        >;

        UnicodeStringView_T actual_v = std::get<UnicodeStringView_T>(v.view_);

        return actual_src_view.compare(pos1, count1, actual_v);
      },
      this->view_
  );
}

int UnicodeStringView_Api::compare(
    size_type pos1,
    size_type count1,
    UnicodeStringView_Api v,
    size_type pos2,
    size_type count2
) const {
  return std::visit(
      [pos1, count1, &v, pos2, count2](const auto& actual_src_view) {
        using UnicodeStringView_T = std::remove_const_t<
            std::remove_reference_t<decltype(actual_src_view)>
        >;

        UnicodeStringView_T actual_v = std::get<UnicodeStringView_T>(v.view_);

        return actual_src_view.compare(pos1, count1, actual_v, pos2, count2);
      },
      this->view_
  );
}

int UnicodeStringView_Api::compare(const value_type* s) const {
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

int UnicodeStringView_Api::compare(
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

int UnicodeStringView_Api::compare(
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

bool UnicodeStringView_Api::starts_with(UnicodeStringView_Api sv) const noexcept {
  return std::visit(
      [&sv](const auto& actual_view) {
        using UnicodeStringView_T = std::remove_const_t<
            std::remove_reference_t<decltype(actual_view)>
        >;

        UnicodeStringView_T actual_sv_data =
            std::get<UnicodeStringView_T>(sv.view_);

        return actual_view.starts_with(actual_sv_data);
      },
      this->view_
  );
}

bool UnicodeStringView_Api::starts_with(const value_type& c) const noexcept {
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

bool UnicodeStringView_Api::starts_with(const value_type* s) const {
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

bool UnicodeStringView_Api::ends_with(UnicodeStringView_Api sv) const noexcept {
  return std::visit(
      [&sv](const auto& actual_view) {
        using UnicodeStringView_T = std::remove_const_t<
            std::remove_reference_t<decltype(actual_view)>
        >;

        UnicodeStringView_T actual_sv_data =
            std::get<UnicodeStringView_T>(sv.view_);

        return actual_view.ends_with(actual_sv_data);
      },
      this->view_
  );
}

bool UnicodeStringView_Api::ends_with(const value_type& c) const noexcept {
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

bool UnicodeStringView_Api::ends_with(const value_type* s) const {
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

UnicodeStringView_Api::size_type UnicodeStringView_Api::find(
    UnicodeStringView_Api v,
    size_type pos
) const noexcept {
  return std::visit(
      [&v, pos](const auto& actual_view) {
        using UnicodeStringView_T = std::remove_const_t<
            std::remove_reference_t<decltype(actual_view)>
        >;
        using UnicodeChar_T = typename UnicodeStringView_T::value_type;

        UnicodeStringView_T& actual_v =
            std::get<UnicodeStringView_T>(v.view_);

        return actual_view.find(actual_v, pos);
      },
      this->view_
  );
}

UnicodeStringView_Api::size_type UnicodeStringView_Api::find(
    value_type& ch,
    size_type pos
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

UnicodeStringView_Api::size_type UnicodeStringView_Api::find(
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

UnicodeStringView_Api::size_type UnicodeStringView_Api::find(
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

void UnicodeStringView_Api::Draw(int position_x, int position_y) const {
  DrawTextOptions options;
  options.position_x_behavior = DrawPositionXBehavior::kLeft;
  options.text_color = TextColor::kWhite;

  this->Draw(position_x, position_y, options);
}

void UnicodeStringView_Api::Draw(
    int position_x,
    int position_y,
    const DrawTextOptions& options
) const {
  int draw_width = d2win::GetUnicodeTextNDrawWidth(
      this->data(),
      this->length()
  );

  int adjusted_position_x;
  switch (options.position_x_behavior) {
    case DrawPositionXBehavior::kLeft: {
      adjusted_position_x = position_x;
      break;
    }

    case DrawPositionXBehavior::kCenter: {
      adjusted_position_x = position_x - (draw_width / 2);
      break;
    }

    case DrawPositionXBehavior::kRight: {
      adjusted_position_x = position_x - draw_width;
      break;
    }

    default: {
      constexpr std::wstring_view kErrorFormatMessage =
          L"File: {} \n"
          L"Line: {} \n"
          L"\n"
          L"Invalid value for DrawPositionXBehavior: "
          L"{}.";

      std::wstring full_message = fmt::format(
          kErrorFormatMessage,
          __FILEW__,
          __LINE__,
          static_cast<int>(options.position_x_behavior)
      );

      MessageBoxW(
          nullptr,
          full_message.data(),
          L"Invalid Value",
          MB_OK | MB_ICONERROR
      );

      std::exit(0);
    }
  }

  d2win::DrawUnicodeText(
      this->data(),
      adjusted_position_x,
      position_y,
      options.text_color,
      false
  );
}

bool operator==(
    UnicodeStringView_Api lhs,
    UnicodeStringView_Api rhs
) noexcept {
  return lhs.compare(rhs) == 0;
}

std::strong_ordering operator<=>(
    UnicodeStringView_Api lhs,
    UnicodeStringView_Api rhs
) noexcept {
  int compare_result = lhs.compare(rhs);

  return compare_result <=> 0;
}

} // namespace d2
