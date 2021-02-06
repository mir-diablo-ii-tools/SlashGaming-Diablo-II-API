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

#include <stdexcept>
#include <string>
#include <string_view>
#include <unordered_map>

#include <fmt/format.h>
#include "backend/error_handling.hpp"
#include "../../include/cxx/game_executable.hpp"
#include "../../include/cxx/game_version.hpp"
#include "../wide_macro.h"

namespace mapi {
namespace {

const std::unordered_map<
    DefaultLibrary,
    std::filesystem::path
>& GetPathsByDefaultLibraries() {
  static const std::unordered_map<
      DefaultLibrary,
      std::filesystem::path
  > kPathsByDefaultLibraries = {
      { DefaultLibrary::kBNClient, "BNClient.dll" },
      { DefaultLibrary::kD2Client, "D2Client.dll" },
      { DefaultLibrary::kD2CMP, "D2CMP.dll" },
      { DefaultLibrary::kD2Common, "D2Common.dll" },
      { DefaultLibrary::kD2DDraw, "D2DDraw.dll" },
      { DefaultLibrary::kD2Direct3D, "D2Direct3D.dll" },
      { DefaultLibrary::kD2Game, "D2Game.dll" },
      { DefaultLibrary::kD2GDI, "D2GDI.dll" },
      { DefaultLibrary::kD2GFX, "D2GFX.dll" },
      { DefaultLibrary::kD2Glide, "D2Glide.dll" },
      { DefaultLibrary::kD2Lang, "D2Lang.dll" },
      { DefaultLibrary::kD2Launch, "D2Launch.dll" },
      { DefaultLibrary::kD2MCPClient, "D2MCPClient.dll" },
      { DefaultLibrary::kD2Multi, "D2Multi.dll" },
      { DefaultLibrary::kD2Net, "D2Net.dll" },
      { DefaultLibrary::kD2Server, "D2Server.dll" },
      { DefaultLibrary::kD2Sound, "D2Sound.dll" },
      { DefaultLibrary::kD2Win, "D2Win.dll" },
      { DefaultLibrary::kFog, "Fog.dll" },
      { DefaultLibrary::kStorm, "Storm.dll" },
  };

  return kPathsByDefaultLibraries;
}

} // namespace

const std::filesystem::path& GetDefaultLibraryPathWithoutRedirect(
    DefaultLibrary library
) {
  try {
    return GetPathsByDefaultLibraries().at(library);
  } catch (const std::out_of_range& e) {
    constexpr std::wstring_view kErrorFormatMessage = L"Could not determine "
        L"the game library path from the library ID: {}.";

    std::wstring message = fmt::format(
        kErrorFormatMessage,
        static_cast<int>(library)
    );

    ExitOnGeneralFailure(
        message,
        L"Failed to Determine Game Library Path",
        __FILEW__,
        __LINE__
    );
  }
}

const std::filesystem::path& GetDefaultLibraryPathWithRedirect(
    DefaultLibrary library
) {
  // Redirect if the game version is 1.14 or higher.
  if (d2::IsRunningGameVersionAtLeast1_14()) {
    return game_executable::GetPath();
  }

  return GetDefaultLibraryPathWithoutRedirect(library);
}

} // namespace mapi
