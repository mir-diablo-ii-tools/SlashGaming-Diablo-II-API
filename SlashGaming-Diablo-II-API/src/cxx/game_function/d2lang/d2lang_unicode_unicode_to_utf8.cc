/**
 * SlashGaming Diablo II Modding API for C++
 * Copyright (C) 2018-2020  Mir Drualga
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

/**
 * Latest supported version: 1.14D
 */

#include "../../../../include/cxx/game_function/d2lang/d2lang_unicode_unicode_to_utf8.hpp"

#include "../../../../include/cxx/game_version.hpp"
#include "../../../asm_x86_macro.h"
#include "../../backend/game_address_table.hpp"
#include "../../backend/game_function/fastcall_function.hpp"

namespace d2::d2lang {
namespace {

static const mapi::GameAddress& GetGameAddress() {
  static const mapi::GameAddress& game_address = mapi::GetGameAddress(
      "D2Lang.dll",
      "Unicode_UnicodeToUtf8"
  );

  return game_address;
}

} // namespace

char8_t* Unicode_unicodeToUtf8(
    char8_t* dest,
    const UnicodeChar* src,
    int count_with_null_term
) {
  return Unicode_UnicodeToUtf8_1_00(
      dest,
      reinterpret_cast<const UnicodeChar_1_00*>(src),
      count_with_null_term
  );
}

char8_t* Unicode_UnicodeToUtf8_1_00(
    char8_t* dest,
    const UnicodeChar_1_00* src,
    std::int32_t count_with_null_term
) {
  return reinterpret_cast<char8_t*>(
      GetGameAddress().raw_address(),
      dest,
      src,
      count_with_null_term
  );
}

} // namespace d2::d2lang
