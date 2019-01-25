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

#include "../include/game_library.h"

#include <windows.h>
#include <cstdint>
#include <cstdlib>
#include <filesystem>
#include <memory>
#include <string>

#include <boost/bimap.hpp>
#include <fmt/format.h>
#include <fmt/printf.h>
#include "../include/game_version.h"

namespace sgd2mapi {
namespace {

using DefaultLibraryAndLibraryPathBimap = boost::bimap<
    enum DefaultLibrary,
    std::filesystem::path
>;

constexpr std::wstring_view kFunctionFailErrorFormat =
    L"File: %s \n"
    L"Line: %d \n"
    L"The function %s failed with error code %x.";

/**
 * The executable used to run the game.
 */
const std::filesystem::path kGameExecutable = u8"Game.exe";

const DefaultLibraryAndLibraryPathBimap&
GetDefaultLibraryAndLibraryPathBimap(
    void
) {
  static const std::array<
      DefaultLibraryAndLibraryPathBimap::value_type, 20
  > library_array = {{
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
  }};

  static const DefaultLibraryAndLibraryPathBimap
      default_library_and_library_path(
          library_array.cbegin(),
          library_array.cend()
      );

  return default_library_and_library_path;
}

std::intptr_t
GetLibraryBaseAddress(
    const std::filesystem::path& library_path
) {
  std::wstring library_path_text_wide = library_path.wstring();

  HMODULE base_address = LoadLibraryW(library_path_text_wide.data());
  if (base_address == nullptr) {
    std::wstring full_message = fmt::sprintf(
        kFunctionFailErrorFormat,
        fmt::to_wstring(__FILE__),
        __LINE__,
        L"LoadLibraryW"
    );

    MessageBoxW(
        nullptr,
        full_message.data(),
        L"LoadLibraryW Failed",
        MB_OK | MB_ICONERROR
    );

    std::exit(0);
  }

  return reinterpret_cast<std::intptr_t>(base_address);
}

} // namespace

GameLibrary::GameLibrary(
    enum DefaultLibrary library
)
    : GameLibrary(GetLibraryPathWithRedirect(library)) {
}

GameLibrary::GameLibrary(
    const std::filesystem::path& library_path
)
    : library_path_(library_path),
      base_address_(GetLibraryBaseAddress(library_path)) {
}

GameLibrary::GameLibrary(
    const GameLibrary&
) = default;

GameLibrary::GameLibrary(
    GameLibrary&&
) noexcept = default;

GameLibrary::~GameLibrary(
    void
) {
  FreeLibrary(reinterpret_cast<HMODULE>(base_address()));
}

GameLibrary&
GameLibrary::operator=(
    const GameLibrary&
) = default;

GameLibrary&
GameLibrary::operator=(
    GameLibrary&&
) noexcept = default;

const std::filesystem::path&
GameLibrary::GetLibraryPathWithRedirect(
    enum DefaultLibrary library
) {
  // Redirect if the game version is 1.14 or higher.
  if (IsGameVersionAtLeast1_14(GetRunningGameVersionId())) {
    return GetGameExecutable();
  }

  try {
    return GetDefaultLibraryAndLibraryPathBimap().left.at(library);
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

std::intptr_t
GameLibrary::base_address(
    void
) const noexcept {
  return base_address_;
}

const std::filesystem::path&
GameLibrary::library_path(
    void
) const noexcept {
  return library_path_;
}

const std::filesystem::path&
GetGameExecutable(
    void
) {
  return kGameExecutable;
}

} // namespace sgd2mapi

const char*
SGD2MAPI_GetGameExecutable(
    void
) {
  return sgd2mapi::GetGameExecutable().string().data();
}
