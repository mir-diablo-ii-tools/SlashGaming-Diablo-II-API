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

#ifndef SGD2MAPI_CXX_HELPER_RGBA_32BIT_COLOR_HPP_
#define SGD2MAPI_CXX_HELPER_RGBA_32BIT_COLOR_HPP_

#include <cstdint>

#include "../../dllexport_define.inc"

namespace mapi {

class DLLEXPORT RGBA32BitColor {
 public:
  RGBA32BitColor() = delete;

  static RGBA32BitColor From24BitColor(
      std::uint8_t red,
      std::uint8_t green,
      std::uint8_t blue,
      std::uint8_t alpha
  );

  static RGBA32BitColor FromRGBA(std::uint32_t color);
  static RGBA32BitColor FromBGRA(std::uint32_t color);
  static RGBA32BitColor FromARGB(std::uint32_t color);
  static RGBA32BitColor FromABGR(std::uint32_t color);

  std::uint32_t ToRGBA() const;
  std::uint32_t ToBGRA() const;
  std::uint32_t ToARGB() const;
  std::uint32_t ToABGR() const;

  std::uint8_t red() const noexcept;
  std::uint8_t green() const noexcept;
  std::uint8_t blue() const noexcept;
  std::uint8_t alpha() const noexcept;

 private:
  RGBA32BitColor(
      std::uint8_t red,
      std::uint8_t green,
      std::uint8_t blue,
      std::uint8_t alpha
  ) noexcept;

  std::uint8_t red_;
  std::uint8_t green_;
  std::uint8_t blue_;
  std::uint8_t alpha_;
};

} // namespace mapi

#include "../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_HELPER_RGBA_32BIT_COLOR_HPP_
