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
#include <memory>
#include <optional>
#include <string>

#include <boost/bimap.hpp>
#include <boost/nowide/convert.hpp>
#include <boost/filesystem.hpp>
#include <boost/format.hpp>
#include "../include/game_version.h"

namespace sgd2mapi {
namespace {

using DefaultLibraryAndLibraryPathBimap = boost::bimap<
    enum DefaultLibrary,
    boost::filesystem::path
>;

/**
 * The executable used to run the game.
 */
const boost::filesystem::path kGameExecutable = "Game.exe";

const DefaultLibraryAndLibraryPathBimap&
GetDefaultLibraryAndLibraryPathBimap(
    void
) {
  static const std::array<
      DefaultLibraryAndLibraryPathBimap::value_type, 20
  > library_array = {{
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
      { DefaultLibrary::kStorm, "Storm.dll" }
  }};

  static const DefaultLibraryAndLibraryPathBimap
      default_library_and_library_path(
          library_array.cbegin(),
          library_array.cend()
      );

  return default_library_and_library_path;
}

std::optional<std::intptr_t>
GetLibraryBaseAddress(
    const boost::filesystem::path& library_path
) noexcept {
  std::wstring library_path_text_wide = library_path.wstring();

  HMODULE base_address = LoadLibraryW(library_path_text_wide.data());
  if (base_address == nullptr) {
    return std::nullopt;
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
    const boost::filesystem::path& library_path
)
    : library_path_(library_path) {
  auto base_address = GetLibraryBaseAddress(library_path);
  if (!base_address.has_value()) {
    std::wstring error_message = (boost::wformat(
        L"Module base address detection for %s failed.")
        % library_path).str();
    MessageBoxW(
        nullptr,
        error_message.data(),
        L"Module Failed to Load",
        MB_OK | MB_ICONERROR
    );
    std::exit(EXIT_FAILURE);
  }

  base_address_ = base_address.value();
}

GameLibrary::GameLibrary(
    const GameLibrary&
) = default;

GameLibrary::GameLibrary(
    GameLibrary&&
) noexcept = default;

GameLibrary::~GameLibrary(
    void
) noexcept {
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

const boost::filesystem::path&
GameLibrary::GetLibraryPathWithRedirect(
    enum DefaultLibrary library
) noexcept {
  // Redirect if the game version is 1.14 or higher.
  if (IsGameVersionAtLeast1_14(GetRunningGameVersionId())) {
    return kGameExecutable;
  }

  return GetDefaultLibraryAndLibraryPathBimap().left.at(library);
}

std::intptr_t
GameLibrary::base_address(
    void
) const noexcept {
  return base_address_;
}

const boost::filesystem::path&
GameLibrary::library_path(
    void
) const noexcept {
  return library_path_;
}

const boost::filesystem::path&
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
