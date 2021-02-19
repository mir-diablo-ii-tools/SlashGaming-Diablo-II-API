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

/**
 * Latest supported version: 1.14D
 */

#include "../../../../include/cxx/game_function/d2lang/d2lang_unicode_strncmp.hpp"

#include "../../../../include/cxx/default_game_library.hpp"
#include "../../../../include/cxx/game_version.hpp"
#include "../../../asm_x86_macro.h"
#include "../../backend/game_address_table.hpp"
#include "../../backend/game_function/fastcall_function.hpp"

namespace d2::d2lang {
namespace {

static const mapi::GameAddress& GetGameAddress() {
  static const mapi::GameAddress game_address = mapi::LoadGameAddress(
      ::d2::DefaultLibrary::kD2Lang,
      "Unicode_strncmp"
  );

  return game_address;
}

/**
 * This function did not exist in 1.00. It has been reconstructed to behave
 * exactly like in 1.10+.
 */
static int Unicode_strncmp_1_00_Impl(
    const UnicodeChar_1_00* str1,
    const UnicodeChar_1_00* str2,
    std::size_t count
) {
  for (std::size_t i = 0; i < count; i += 1) {
    int diff = str1[i].ch - str2[i].ch;

    if (diff != 0) {
      return diff;
    }

    if (str1[i].ch == u'\0') {
      return 0;
    }
  }

  return 0;
}

static std::int32_t Unicode_strncmp_1_10(
    const UnicodeChar_1_00* str1,
    const UnicodeChar_1_00* str2,
    std::size_t count
) {
  return reinterpret_cast<std::int32_t>(
      mapi::CallFastcallFunction(
          GetGameAddress().raw_address(),
          str1,
          str2,
          count
      )
  );
}

} // namespace

int Unicode_strncmp(
    const UnicodeChar* str1,
    const UnicodeChar* str2,
    std::size_t count
) {
  GameVersion running_game_version = GetRunningGameVersionId();

  if (running_game_version <= GameVersion::k1_09D) {
    return Unicode_strncmp_1_00_Impl(
        reinterpret_cast<const UnicodeChar_1_00*>(str1),
        reinterpret_cast<const UnicodeChar_1_00*>(str2),
        count
    );
  } else /* if (running_game_version >= GameVersion::k1_10) */ {
    return Unicode_strncmp_1_10(
        reinterpret_cast<const UnicodeChar_1_00*>(str1),
        reinterpret_cast<const UnicodeChar_1_00*>(str2),
        count
    );
  }
}

std::int32_t Unicode_strncmp_1_00(
    const UnicodeChar_1_00* str1,
    const UnicodeChar_1_00* str2,
    std::uint32_t count
) {
  return reinterpret_cast<std::int32_t>(
      mapi::CallFastcallFunction(
          GetGameAddress().raw_address(),
          str1,
          str2,
          count
      )
  );
}

} // namespace d2::d2lang
