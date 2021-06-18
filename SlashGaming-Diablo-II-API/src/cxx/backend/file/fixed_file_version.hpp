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

#ifndef SGD2MAPI_CXX_BACKEND_FILE_FIXED_FILE_VERSION_HPP_
#define SGD2MAPI_CXX_BACKEND_FILE_FIXED_FILE_VERSION_HPP_

#include <windows.h>

#include <climits>
#include <cstdint>
#include <compare>

namespace mapi {

struct FixedFileVersion {
  WORD major_high;
  WORD major_low;
  WORD minor_high;
  WORD minor_low;

  constexpr FixedFileVersion(
      WORD major_high,
      WORD major_low,
      WORD minor_high,
      WORD minor_low
  ) noexcept
      : major_high(major_high),
        major_low(major_low),
        minor_high(minor_high),
        minor_low(minor_low) {
  }

  friend constexpr ::std::strong_ordering operator<=>(
      const FixedFileVersion& fixed_file_version1,
      const FixedFileVersion& fixed_file_version2
  ) noexcept = default;

  constexpr ::std::uint_least64_t ToValue() const noexcept {
    ::std::uint_least64_t major_high_64 = this->major_high & 0xFFFF;
    ::std::uint_least64_t major_low_64 = this->major_low & 0xFFFF;
    ::std::uint_least64_t minor_high_64 = this->minor_high & 0xFFFF;
    ::std::uint_least64_t minor_low_64 = this->minor_low & 0xFFFF;

    return (major_high_64 << (sizeof(WORD) * CHAR_BIT * 3))
        | (major_low_64 << (sizeof(WORD) * CHAR_BIT * 2))
        | (minor_high_64 << (sizeof(WORD) * CHAR_BIT * 1))
        | minor_low_64;
  }
};

} // namespace mapi

#endif // SGD2MAPI_CXX_BACKEND_FILE_FIXED_FILE_VERSION_HPP_
