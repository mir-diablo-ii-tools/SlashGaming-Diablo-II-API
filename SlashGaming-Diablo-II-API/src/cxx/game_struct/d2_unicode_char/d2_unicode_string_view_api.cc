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

#include "../../../../include/cxx/game_struct/d2_unicode_char/d2_unicode_string_view_api.hpp"

#include "../../../../include/cxx/game_func/d2lang_func.hpp"
#include "../../../../include/cxx/game_func/d2win_func.hpp"
#include "../../../../include/cxx/game_version.hpp"
#include "d2_unicode_char_impl.hpp"

namespace d2 {
namespace {

using unistring_view_1_00 = std::basic_string_view<UnicodeChar_1_00>;
using unique_ptr_1_00 = std::unique_ptr<unistring_view_1_00>;

} // namespace

UnicodeStringView_API::UnicodeStringView_API() noexcept
    : view_(std::make_unique<unistring_view_1_00>()) {
}

UnicodeStringView_API::UnicodeStringView_API(
    const UnicodeStringView_API& other
) noexcept
    : UnicodeStringView_API(other.data(), other.length()) {
}

UnicodeStringView_API::UnicodeStringView_API(
    UnicodeStringView_API&& other
) noexcept = default;

UnicodeStringView_API::UnicodeStringView_API(
    const value_type* s,
    size_type count
) : view_(
        std::make_unique<unistring_view_1_00>(
            reinterpret_cast<const UnicodeChar_1_00*>(s), count
        )
    ) {
}

UnicodeStringView_API::UnicodeStringView_API(const value_type* s)
  : view_(
        std::make_unique<unistring_view_1_00>(
            reinterpret_cast<const UnicodeChar_1_00*>(s)
        )
    ) {
}

UnicodeStringView_API::UnicodeStringView_API(unistring_view_1_00&& ptr)
    : view_(std::make_unique<unistring_view_1_00>(std::move(ptr))) {
}

UnicodeStringView_API::~UnicodeStringView_API() noexcept = default;

UnicodeStringView_API& UnicodeStringView_API::operator=(
    const UnicodeStringView_API& view
) noexcept {
  *this = UnicodeStringView_API(view);

  return *this;
}

UnicodeStringView_API& UnicodeStringView_API::operator=(
    UnicodeStringView_API&& other
) noexcept = default;

UnicodeStringView_API::const_reference UnicodeStringView_API::operator[](
    size_type pos
) const {
  auto& actual_this = std::get<unique_ptr_1_00>(this->view_);

  return reinterpret_cast<const_reference>((*actual_this.get())[pos]);
}

UnicodeStringView_API::const_reference
UnicodeStringView_API::at(size_type pos) const {
  auto& actual_this = std::get<unique_ptr_1_00>(this->view_);

  return reinterpret_cast<const_reference>(actual_this->at(pos));
}

UnicodeStringView_API::const_reference UnicodeStringView_API::back() const {
  auto& actual_this = std::get<unique_ptr_1_00>(this->view_);

  return reinterpret_cast<const_reference>(actual_this->back());
}

UnicodeStringView_API::size_type UnicodeStringView_API::copy(
    value_type* dest,
    size_type count
) const {
  auto& actual_this = std::get<unique_ptr_1_00>(this->view_);

  auto* actual_dest = reinterpret_cast<UnicodeChar_1_00*>(dest);

  return actual_this->copy(actual_dest, count);
}

int UnicodeStringView_API::compare(UnicodeStringView_API v) const noexcept {
  auto& actual_this = std::get<unique_ptr_1_00>(this->view_);
  auto& actual_v = std::get<unique_ptr_1_00>(v.view_);

  return actual_this->compare(*actual_v);
}

int UnicodeStringView_API::compare(
    size_type pos1,
    size_type count1,
    UnicodeStringView_API v
) const {
  auto& actual_this = std::get<unique_ptr_1_00>(this->view_);
  auto& actual_v = std::get<unique_ptr_1_00>(v.view_);

  return actual_this->compare(pos1, count1, *actual_v);
}

int UnicodeStringView_API::compare(
    size_type pos1,
    size_type count1,
    UnicodeStringView_API v,
    size_type pos2,
    size_type count2
) const {
  auto& actual_this = std::get<unique_ptr_1_00>(this->view_);
  auto& actual_v = std::get<unique_ptr_1_00>(v.view_);

  return actual_this->compare(pos1, count1, *actual_v, pos2, count2);
}

int UnicodeStringView_API::compare(const value_type* s) const {
  auto& actual_this = std::get<unique_ptr_1_00>(this->view_);
  auto* actual_s = reinterpret_cast<const UnicodeChar_1_00*>(s);

  return actual_this->compare(actual_s);
}

int UnicodeStringView_API::compare(
    size_type pos1,
    size_type count1,
    const value_type* s
) const {
  auto& actual_this = std::get<unique_ptr_1_00>(this->view_);
  auto* actual_s = reinterpret_cast<const UnicodeChar_1_00*>(s);

  return actual_this->compare(pos1, count1, actual_s);
}

int UnicodeStringView_API::compare(
    size_type pos1,
    size_type count1,
    const value_type* s,
    size_type count2
) const {
  auto& actual_this = std::get<unique_ptr_1_00>(this->view_);
  auto* actual_s = reinterpret_cast<const UnicodeChar_1_00*>(s);

  return actual_this->compare(pos1, count1, actual_s, count2);
}

UnicodeStringView_API::size_type UnicodeStringView_API::copy(
    value_type* dest,
    size_type count,
    size_type pos
) const {
  auto& actual_this = std::get<unique_ptr_1_00>(this->view_);
  auto* actual_dest = reinterpret_cast<UnicodeChar_1_00*>(dest);

  return actual_this->copy(actual_dest, count, pos);
}

void UnicodeStringView_API::Draw(int position_x, int position_y) const {
  DrawTextOptions options;
  options.position_x_behavior = DrawPositionXBehavior::kLeft;
  options.text_color = TextColor::kWhite;

  this->Draw(position_x, position_y, options);
}

void UnicodeStringView_API::Draw(
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
  }

  d2win::DrawUnicodeText(
      this->data(),
      adjusted_position_x,
      position_y,
      options.text_color,
      false
  );
}

bool UnicodeStringView_API::empty() const noexcept {
  auto& actual_this = std::get<unique_ptr_1_00>(this->view_);

  return actual_this->empty();
}

UnicodeStringView_API::const_reference UnicodeStringView_API::front() const {
  auto& actual_this = std::get<unique_ptr_1_00>(this->view_);

  return reinterpret_cast<const_reference>(actual_this->front());
}

UnicodeStringView_API UnicodeStringView_API::substr() const {
  auto& actual_this = std::get<unique_ptr_1_00>(this->view_);

  return UnicodeStringView_API(std::move(actual_this->substr()));
}

UnicodeStringView_API UnicodeStringView_API::substr(size_type pos) const {
  auto& actual_this = std::get<unique_ptr_1_00>(this->view_);

  return UnicodeStringView_API(std::move(actual_this->substr(pos)));
}

UnicodeStringView_API UnicodeStringView_API::substr(
    size_type pos,
    size_type count
) const {
  auto& actual_this = std::get<unique_ptr_1_00>(this->view_);

  return UnicodeStringView_API(std::move(actual_this->substr(pos, count)));
}

UnicodeStringView_API::const_pointer
UnicodeStringView_API::data() const noexcept {
  auto& actual_this = std::get<unique_ptr_1_00>(this->view_);

  return reinterpret_cast<const_pointer>(actual_this->data());
}

UnicodeStringView_API::size_type
UnicodeStringView_API::length() const noexcept {
  auto& actual = std::get<unique_ptr_1_00>(this->view_);

  return actual->length();
}

UnicodeStringView_API::size_type
UnicodeStringView_API::size() const noexcept {
  auto& actual = std::get<unique_ptr_1_00>(this->view_);

  return actual->size();
}

} // namespace d2
