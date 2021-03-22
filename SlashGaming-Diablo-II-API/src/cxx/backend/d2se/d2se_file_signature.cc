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

#include "d2se_file_signature.hpp"

#include <array>

#include "../game_file/file_signature.hpp"

namespace mapi::d2se::file_signature {
namespace {

static constexpr const ::std::array<
    FileSignature,
    1
> kD2SESignatureSortedSet = {{
    {
        FileSignature{{
            0x50, 0x45, 0x00, 0x00, 0x4C, 0x01, 0x05, 0x00,
            0x5F, 0xDC, 0xB5, 0x4D, 0x00, 0x00, 0x00, 0x00,
            
            0x00, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x0F, 0x01,
            0x0B, 0x01, 0x02, 0x32, 0x00, 0x08, 0x01, 0x00,
            
            0x00, 0x8A, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x40, 0x3C, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00,
            
            0x00, 0x20, 0x01, 0x00, 0x00, 0x00, 0x40, 0x00,
            0x00, 0x10, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00,
        }}
    }
}};

// If this assertion compiles but produces a linter error, ignore it.
static_assert(
    ::std::is_sorted(
        kD2SESignatureSortedSet.cbegin(),
        kD2SESignatureSortedSet.cend()
    )
);

} // namespace

bool IsFileD2seExecutable(const ::std::filesystem::path& path) {
  FileSignature game_executable_file_signature = FileSignature::ReadFile(
      path
  );

  return ::std::binary_search(
      kD2SESignatureSortedSet.cbegin(),
      kD2SESignatureSortedSet.cend(),
      game_executable_file_signature
  );
}

} // namespace mapi::d2se::file_signature
