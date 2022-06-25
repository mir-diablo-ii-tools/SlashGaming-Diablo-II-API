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

#include "../../../include/cxx/helper/rgba_32bit_color.hpp"

namespace mapi {

Rgba32BitColor::Rgba32BitColor() noexcept :
    Rgba32BitColor(0xFF, 0xFF, 0xFF, 0xFF) {
}

Rgba32BitColor::Rgba32BitColor(
    std::uint8_t red,
    std::uint8_t green,
    std::uint8_t blue,
    std::uint8_t alpha
) noexcept :
    red_(red),
    green_(green),
    blue_(blue),
    alpha_(alpha) {
}

Rgba32BitColor Rgba32BitColor::FromRgba(std::uint32_t color) {
  std::uint8_t red = (color >> (3 * 8)) & 0xFF;
  std::uint8_t green = (color >> (2 * 8)) & 0xFF;
  std::uint8_t blue = (color >> (1 * 8)) & 0xFF;
  std::uint8_t alpha = (color >> (0 * 8)) & 0xFF;

  return Rgba32BitColor(red, green, blue, alpha);
}

Rgba32BitColor Rgba32BitColor::FromBgra(std::uint32_t color) {
  std::uint8_t red = (color >> (1 * 8)) & 0xFF;
  std::uint8_t green = (color >> (2 * 8)) & 0xFF;
  std::uint8_t blue = (color >> (3 * 8)) & 0xFF;
  std::uint8_t alpha = (color >> (0 * 8)) & 0xFF;

  return Rgba32BitColor(red, green, blue, alpha);
}

Rgba32BitColor Rgba32BitColor::FromArgb(std::uint32_t color) {
  std::uint8_t red = (color >> (2 * 8)) & 0xFF;
  std::uint8_t green = (color >> (1 * 8)) & 0xFF;
  std::uint8_t blue = (color >> (0 * 8)) & 0xFF;
  std::uint8_t alpha = (color >> (3 * 8)) & 0xFF;

  return Rgba32BitColor(red, green, blue, alpha);
}

Rgba32BitColor Rgba32BitColor::FromAbgr(std::uint32_t color) {
  std::uint8_t red = (color >> (0 * 8)) & 0xFF;
  std::uint8_t green = (color >> (1 * 8)) & 0xFF;
  std::uint8_t blue = (color >> (2 * 8)) & 0xFF;
  std::uint8_t alpha = (color >> (3 * 8)) & 0xFF;

  return Rgba32BitColor(red, green, blue, alpha);
}

std::uint32_t Rgba32BitColor::ToRgba() const {
  std::uint32_t color = 0;

  color |= this->red() << (3 * 8);
  color |= this->green() << (2 * 8);
  color |= this->blue() << (1 * 8);
  color |= this->alpha() << (0 * 8);

  return color;
}

std::uint32_t Rgba32BitColor::ToBgra() const {
  std::uint32_t color = 0;

  color |= this->red() << (1 * 8);
  color |= this->green() << (2 * 8);
  color |= this->blue() << (3 * 8);
  color |= this->alpha() << (0 * 8);

  return color;
}

std::uint32_t Rgba32BitColor::ToArgb() const {
  std::uint32_t color = 0;

  color |= this->red() << (2 * 8);
  color |= this->green() << (1 * 8);
  color |= this->blue() << (0 * 8);
  color |= this->alpha() << (3 * 8);

  return color;
}

std::uint32_t Rgba32BitColor::ToAbgr() const {
  std::uint32_t color = 0;

  color |= this->red() << (0 * 8);
  color |= this->green() << (1 * 8);
  color |= this->blue() << (2 * 8);
  color |= this->alpha() << (3 * 8);

  return color;
}


std::uint8_t Rgba32BitColor::red() const noexcept {
  return this->red_;
}

std::uint8_t Rgba32BitColor::green() const noexcept {
  return this->green_;
}

std::uint8_t Rgba32BitColor::blue() const noexcept {
  return this->blue_;
}

std::uint8_t Rgba32BitColor::alpha() const noexcept {
  return this->alpha_;
}

} // namespace mapi
