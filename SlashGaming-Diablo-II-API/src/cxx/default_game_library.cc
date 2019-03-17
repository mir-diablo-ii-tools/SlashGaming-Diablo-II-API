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
 *  it with any Glide wrapper (or a modified version of that library),
 *  containing parts not covered by a compatible license, the licensors of
 *  this Program grant you additional permission to convey the resulting
 *  work.
 */

#include "../../include/cxx/default_game_library.hpp"

#include <windows.h>
#include <cstdint>
#include <cstdlib>
#include <algorithm>
#include <filesystem>
#include <string>
#include <unordered_map>

#include <fmt/format.h>
#include <fmt/printf.h>
#include "../../include/cxx/game_version.hpp"

namespace mapi {
namespace {

using PathsByDefaultLibrariesMap = std::unordered_map<
    enum DefaultLibrary,
    std::filesystem::path
>;

const PathsByDefaultLibrariesMap&
GetPathsByDefaultLibraryMap(void) {
  static const PathsByDefaultLibrariesMap
  paths_by_default_libraries = {
      { DefaultLibrary::kBNClient, u8"BNClient.dll" },
      { DefaultLibrary::kD2Client, u8"D2Client.dll" },
      { DefaultLibrary::kD2CMP, u8"D2CMP.dll" },
      { DefaultLibrary::kD2Common, u8"D2Common.dll" },
      { DefaultLibrary::kD2DDraw, u8"D2DDraw.dll" },
      { DefaultLibrary::kD2Direct3D, u8"D2Direct3D.dll" },
      { DefaultLibrary::kD2Game, u8"D2Game.dll" },
      { DefaultLibrary::kD2GDI, u8"D2GDI.dll" },
      { DefaultLibrary::kD2GFX, u8"D2GFX.dll" },
      { DefaultLibrary::kD2Glide, u8"D2Glide.dll" },
      { DefaultLibrary::kD2Lang, u8"D2Lang.dll" },
      { DefaultLibrary::kD2Launch, u8"D2Launch.dll" },
      { DefaultLibrary::kD2MCPClient, u8"D2MCPClient.dll" },
      { DefaultLibrary::kD2Multi, u8"D2Multi.dll" },
      { DefaultLibrary::kD2Net, u8"D2Net.dll" },
      { DefaultLibrary::kD2Server, u8"D2Server.dll" },
      { DefaultLibrary::kD2Sound, u8"D2Sound.dll" },
      { DefaultLibrary::kD2Win, u8"D2Win.dll" },
      { DefaultLibrary::kFog, u8"Fog.dll" },
      { DefaultLibrary::kStorm, u8"Storm.dll" }
  };

  return paths_by_default_libraries;
}

} // namespace

const std::filesystem::path&
GetGameExecutablePath(void) {
  static const std::filesystem::path kGameExecutable = u8"Game.exe";

  return kGameExecutable;
}

const std::filesystem::path&
GetDefaultLibraryPathWithRedirect(
    enum DefaultLibrary library
) {
  // Redirect if the game version is 1.14 or higher.
  if (d2::IsRunningGameVersionAtLeast1_14()) {
    return GetGameExecutablePath();
  }

  try {
    return GetPathsByDefaultLibraryMap().at(library);
  } catch (const std::out_of_range& e) {
    constexpr std::wstring_view kErrorFormatMessage =
        L"File: %s \n"
        L"Line: %d \n"
        L"Could not determine the game library path from the library ID: %s.";

    std::wstring full_message = fmt::sprintf(
        kErrorFormatMessage,
        fmt::to_wstring(__FILE__),
        __LINE__,
        static_cast<int>(library)
    );

    MessageBoxW(
        nullptr,
        full_message.data(),
        L"Failed to Determine Game Library Path",
        MB_OK | MB_ICONERROR
    );

    std::exit(0);
  }
}

} // namespace mapi
