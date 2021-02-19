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

#include "../../include/cxx/default_game_library.hpp"

#include <algorithm>
#include <array>
#include <utility>

#include <mdc/error/exit_on_error.hpp>
#include <mdc/wchar_t/filew.h>
#include "../../include/cxx/game_executable.hpp"
#include "../../include/cxx/game_version.hpp"

namespace d2::default_library {
namespace {

using DefaultLibraryPathTableEntry = ::std::pair<
    DefaultLibrary,
    std::filesystem::path
>;

struct DefaultLibraryPathTableEntryCompareKey {
  constexpr bool operator()(
      const DefaultLibraryPathTableEntry& entry1,
      const DefaultLibraryPathTableEntry& entry2
  ) const noexcept {
    return entry1.first < entry2.first;
  }

  constexpr bool operator()(
      DefaultLibrary library,
      const DefaultLibraryPathTableEntry& entry
  ) const noexcept {
    return library < entry.first;
  }

  constexpr bool operator()(
      const DefaultLibraryPathTableEntry& entry,
      DefaultLibrary library
  ) const noexcept {
    return entry.first < library;
  }
};

static const std::filesystem::path&
SearchDefaultLibraryPath(DefaultLibrary library) {
  static const std::array<
      DefaultLibraryPathTableEntry,
      20
  > kDefaultLibraryPathTable = {{
      { DefaultLibrary::kBNClient, L"BNClient.dll" },
      { DefaultLibrary::kD2CMP, L"D2CMP.dll" },
      { DefaultLibrary::kD2Client, L"D2Client.dll" },
      { DefaultLibrary::kD2Common, L"D2Common.dll" },
      { DefaultLibrary::kD2DDraw, L"D2DDraw.dll" },
      { DefaultLibrary::kD2Direct3D, L"D2Direct3D.dll" },
      { DefaultLibrary::kD2Game, L"D2Game.dll" },
      { DefaultLibrary::kD2GDI, L"D2GDI.dll" },
      { DefaultLibrary::kD2GFX, L"D2GFX.dll" },
      { DefaultLibrary::kD2Glide, L"D2Glide.dll" },
      { DefaultLibrary::kD2Lang, L"D2Lang.dll" },
      { DefaultLibrary::kD2Launch, L"D2Launch.dll" },
      { DefaultLibrary::kD2MCPClient, L"D2MCPClient.dll" },
      { DefaultLibrary::kD2Multi, L"D2Multi.dll" },
      { DefaultLibrary::kD2Net, L"D2Net.dll" },
      { DefaultLibrary::kD2Server, L"D2Server.dll" },
      { DefaultLibrary::kD2Sound, L"D2Sound.dll" },
      { DefaultLibrary::kD2Win, L"D2Win.dll" },
      { DefaultLibrary::kFog, L"Fog.dll" },
      { DefaultLibrary::kStorm, L"Storm.dll" },
  }};

  ::std::pair search_range = ::std::equal_range(
      kDefaultLibraryPathTable.cbegin(),
      kDefaultLibraryPathTable.cend(),
      library,
      DefaultLibraryPathTableEntryCompareKey()
  );

  if (search_range.first == kDefaultLibraryPathTable.cend()) {
    ::mdc::error::ExitOnConstantMappingError(
        __FILEW__,
        __LINE__,
        static_cast<int>(library)
    );

    return "";
  }

  return search_range.first->second;
}

} // namespace

const std::filesystem::path& GetPathWithoutRedirect(
    DefaultLibrary library
) {
  return SearchDefaultLibraryPath(library);
}

const std::filesystem::path& GetPathWithRedirect(
    DefaultLibrary library
) {
  // Redirect if the game version is 1.14 or higher.
  if (::d2::game_version::IsRunningAtLeast1_14()) {
    return ::mapi::game_executable::GetPath();
  }

  return GetPathWithoutRedirect(library);
}

} // namespace d2::default_library
