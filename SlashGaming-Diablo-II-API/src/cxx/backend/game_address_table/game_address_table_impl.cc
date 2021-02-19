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

#include "game_address_table_impl.hpp"

#include <algorithm>
#include <array>
#include <string_view>

#include "../../../../include/cxx/game_version.hpp"
#include "game_address_locator/game_address_locator.hpp"
#include "game_address_locator/game_decorated_name_locator.hpp"
#include "game_address_locator/game_offset_locator.hpp"
#include "game_address_locator/game_ordinal_locator.hpp"
#include "game_address_table_define.hpp"

namespace mapi {
namespace {

static constexpr const std::array kGameAddressTable_1_00 =
    MAPI_GAME_ADDRESS_TABLE_1_00;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_1_00.cbegin(),
        kGameAddressTable_1_00.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_1_01 =
    MAPI_GAME_ADDRESS_TABLE_1_01;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_1_01.cbegin(),
        kGameAddressTable_1_01.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_1_02 =
    MAPI_GAME_ADDRESS_TABLE_1_02;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_1_02.cbegin(),
        kGameAddressTable_1_02.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_1_03 =
    MAPI_GAME_ADDRESS_TABLE_1_03;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_1_03.cbegin(),
        kGameAddressTable_1_03.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_1_04B_C =
    MAPI_GAME_ADDRESS_TABLE_1_04B_AND_C;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_1_04B_C.cbegin(),
        kGameAddressTable_1_04B_C.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_1_05 =
    MAPI_GAME_ADDRESS_TABLE_1_05;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_1_05.cbegin(),
        kGameAddressTable_1_05.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_1_05B =
    MAPI_GAME_ADDRESS_TABLE_1_05B;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_1_05B.cbegin(),
        kGameAddressTable_1_05B.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_1_06 =
    MAPI_GAME_ADDRESS_TABLE_1_06;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_1_06.cbegin(),
        kGameAddressTable_1_06.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_1_06B =
    MAPI_GAME_ADDRESS_TABLE_1_06B;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_1_06B.cbegin(),
        kGameAddressTable_1_06B.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_1_07Beta =
    MAPI_GAME_ADDRESS_TABLE_1_07_BETA;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_1_07Beta.cbegin(),
        kGameAddressTable_1_07Beta.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_1_07 =
    MAPI_GAME_ADDRESS_TABLE_1_07;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_1_07.cbegin(),
        kGameAddressTable_1_07.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_1_08 =
    MAPI_GAME_ADDRESS_TABLE_1_08;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_1_08.cbegin(),
        kGameAddressTable_1_08.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_1_09 =
    MAPI_GAME_ADDRESS_TABLE_1_09;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_1_09.cbegin(),
        kGameAddressTable_1_09.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_1_09B =
    MAPI_GAME_ADDRESS_TABLE_1_09B;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_1_09B.cbegin(),
        kGameAddressTable_1_09B.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_1_09D =
    MAPI_GAME_ADDRESS_TABLE_1_09D;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_1_09D.cbegin(),
        kGameAddressTable_1_09D.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_1_10Beta =
    MAPI_GAME_ADDRESS_TABLE_1_10_BETA;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_1_10Beta.cbegin(),
        kGameAddressTable_1_10Beta.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_1_10SBeta =
    MAPI_GAME_ADDRESS_TABLE_1_10S_BETA;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_1_10SBeta.cbegin(),
        kGameAddressTable_1_10SBeta.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_1_10 =
    MAPI_GAME_ADDRESS_TABLE_1_10;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_1_10.cbegin(),
        kGameAddressTable_1_10.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_1_11 =
    MAPI_GAME_ADDRESS_TABLE_1_11;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_1_11.cbegin(),
        kGameAddressTable_1_11.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_1_11B =
    MAPI_GAME_ADDRESS_TABLE_1_11B;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_1_11B.cbegin(),
        kGameAddressTable_1_11B.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_1_12A =
    MAPI_GAME_ADDRESS_TABLE_1_12A;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_1_12A.cbegin(),
        kGameAddressTable_1_12A.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_1_13ABeta =
    MAPI_GAME_ADDRESS_TABLE_1_13A_BETA;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_1_13ABeta.cbegin(),
        kGameAddressTable_1_13ABeta.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_1_13C =
    MAPI_GAME_ADDRESS_TABLE_1_13C;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_1_13C.cbegin(),
        kGameAddressTable_1_13C.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_1_13D =
    MAPI_GAME_ADDRESS_TABLE_1_13D;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_1_13D.cbegin(),
        kGameAddressTable_1_13D.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_Classic1_14A =
    MAPI_GAME_ADDRESS_TABLE_CLASSIC_1_14A;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_Classic1_14A.cbegin(),
        kGameAddressTable_Classic1_14A.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_Lod1_14A =
    MAPI_GAME_ADDRESS_TABLE_LOD_1_14A;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_Lod1_14A.cbegin(),
        kGameAddressTable_Lod1_14A.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_Classic1_14B =
    MAPI_GAME_ADDRESS_TABLE_CLASSIC_1_14B;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_Classic1_14B.cbegin(),
        kGameAddressTable_Classic1_14B.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_Lod1_14B =
    MAPI_GAME_ADDRESS_TABLE_LOD_1_14B;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_Lod1_14B.cbegin(),
        kGameAddressTable_Lod1_14B.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_Classic1_14C =
    MAPI_GAME_ADDRESS_TABLE_CLASSIC_1_14C;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_Classic1_14C.cbegin(),
        kGameAddressTable_Classic1_14C.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_Lod1_14C =
    MAPI_GAME_ADDRESS_TABLE_LOD_1_14C;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_Lod1_14C.cbegin(),
        kGameAddressTable_Lod1_14C.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_Classic1_14D =
    MAPI_GAME_ADDRESS_TABLE_CLASSIC_1_14D;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_Classic1_14D.cbegin(),
        kGameAddressTable_Classic1_14D.cend(),
        GameAddressTableEntryCompareKey()
    )
);

static constexpr const std::array kGameAddressTable_Lod1_14D =
    MAPI_GAME_ADDRESS_TABLE_LOD_1_14D;

static_assert(
    ::std::is_sorted(
        kGameAddressTable_Lod1_14D.cbegin(),
        kGameAddressTable_Lod1_14D.cend(),
        GameAddressTableEntryCompareKey()
    )
);

} // namespace

GameAddressTable LoadGameAddressTable() {
  switch (d2::GetRunningGameVersionId()) {
    case d2::GameVersion::k1_00: {
      return ::std::pair(
          kGameAddressTable_1_00.data(),
          kGameAddressTable_1_00.size()
      );
    }

    case d2::GameVersion::k1_01: {
      return ::std::pair(
          kGameAddressTable_1_01.data(),
          kGameAddressTable_1_01.size()
      );
    }

    case d2::GameVersion::k1_02: {
      return ::std::pair(
          kGameAddressTable_1_02.data(),
          kGameAddressTable_1_02.size()
      );
    }

    case d2::GameVersion::k1_03: {
      return ::std::pair(
          kGameAddressTable_1_03.data(),
          kGameAddressTable_1_03.size()
      );
    }

    case d2::GameVersion::k1_04B_C: {
      return ::std::pair(
          kGameAddressTable_1_04B_C.data(),
          kGameAddressTable_1_04B_C.size()
      );
    }

    case d2::GameVersion::k1_05: {
      return ::std::pair(
          kGameAddressTable_1_05.data(),
          kGameAddressTable_1_05.size()
      );
    }

    case d2::GameVersion::k1_05B: {
      return ::std::pair(
          kGameAddressTable_1_05B.data(),
          kGameAddressTable_1_05B.size()
      );
    }

    case d2::GameVersion::k1_06: {
      return ::std::pair(
          kGameAddressTable_1_06.data(),
          kGameAddressTable_1_06.size()
      );
    }

    case d2::GameVersion::k1_06B: {
      return ::std::pair(
          kGameAddressTable_1_06B.data(),
          kGameAddressTable_1_06B.size()
      );
    }

    case d2::GameVersion::k1_07Beta: {
      return ::std::pair(
          kGameAddressTable_1_07Beta.data(),
          kGameAddressTable_1_07Beta.size()
      );
    }

    case d2::GameVersion::k1_07: {
      return ::std::pair(
          kGameAddressTable_1_07.data(),
          kGameAddressTable_1_07.size()
      );
    }

    case d2::GameVersion::k1_08: {
      return ::std::pair(
          kGameAddressTable_1_08.data(),
          kGameAddressTable_1_08.size()
      );
    }

    case d2::GameVersion::k1_09: {
      return ::std::pair(
          kGameAddressTable_1_09.data(),
          kGameAddressTable_1_09.size()
      );
    }

    case d2::GameVersion::k1_09B: {
      return ::std::pair(
          kGameAddressTable_1_09B.data(),
          kGameAddressTable_1_09B.size()
      );
    }

    case d2::GameVersion::k1_09D: {
      return ::std::pair(
          kGameAddressTable_1_09D.data(),
          kGameAddressTable_1_09D.size()
      );
    }

    case d2::GameVersion::k1_10Beta: {
      return ::std::pair(
          kGameAddressTable_1_10Beta.data(),
          kGameAddressTable_1_10Beta.size()
      );
    }

    case d2::GameVersion::k1_10SBeta: {
      return ::std::pair(
          kGameAddressTable_1_10SBeta.data(),
          kGameAddressTable_1_10SBeta.size()
      );
    }

    case d2::GameVersion::k1_10: {
      return ::std::pair(
          kGameAddressTable_1_10.data(),
          kGameAddressTable_1_10.size()
      );
    }

    case d2::GameVersion::k1_11: {
      return ::std::pair(
          kGameAddressTable_1_11.data(),
          kGameAddressTable_1_11.size()
      );
    }

    case d2::GameVersion::k1_11B: {
      return ::std::pair(
          kGameAddressTable_1_11B.data(),
          kGameAddressTable_1_11B.size()
      );
    }

    case d2::GameVersion::k1_12A: {
      return ::std::pair(
          kGameAddressTable_1_12A.data(),
          kGameAddressTable_1_12A.size()
      );
    }

    case d2::GameVersion::k1_13ABeta: {
      return ::std::pair(
          kGameAddressTable_1_13ABeta.data(),
          kGameAddressTable_1_13ABeta.size()
      );
    }

    case d2::GameVersion::k1_13C: {
      return ::std::pair(
          kGameAddressTable_1_13C.data(),
          kGameAddressTable_1_13C.size()
      );
    }

    case d2::GameVersion::k1_13D: {
      return ::std::pair(
          kGameAddressTable_1_13D.data(),
          kGameAddressTable_1_13D.size()
      );
    }

    case d2::GameVersion::kClassic1_14A: {
      return ::std::pair(
          kGameAddressTable_Classic1_14A.data(),
          kGameAddressTable_Classic1_14A.size()
      );
    }

    case d2::GameVersion::kLod1_14A: {
      return ::std::pair(
          kGameAddressTable_Lod1_14A.data(),
          kGameAddressTable_Lod1_14A.size()
      );
    }

    case d2::GameVersion::kClassic1_14B: {
      return ::std::pair(
          kGameAddressTable_Classic1_14B.data(),
          kGameAddressTable_Classic1_14B.size()
      );
    }

    case d2::GameVersion::kLod1_14B: {
      return ::std::pair(
          kGameAddressTable_Lod1_14B.data(),
          kGameAddressTable_Lod1_14B.size()
      );
    }

    case d2::GameVersion::kClassic1_14C: {
      return ::std::pair(
          kGameAddressTable_Classic1_14C.data(),
          kGameAddressTable_Classic1_14C.size()
      );
    }

    case d2::GameVersion::kLod1_14C: {
      return ::std::pair(
          kGameAddressTable_Lod1_14C.data(),
          kGameAddressTable_Lod1_14C.size()
      );
    }

    case d2::GameVersion::kClassic1_14D: {
      return ::std::pair(
          kGameAddressTable_Classic1_14D.data(),
          kGameAddressTable_Classic1_14D.size()
      );
    }

    case d2::GameVersion::kLod1_14D: {
      return ::std::pair(
          kGameAddressTable_Lod1_14D.data(),
          kGameAddressTable_Lod1_14D.size()
      );
    }
  }
}

} // namespace mapi
