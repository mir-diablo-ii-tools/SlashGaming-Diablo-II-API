/**
 * SlashGaming Diablo II Modding API
 * Copyright (C) 2018  SlashGaming Community
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
 *  the game, provided that the game or its libraries do not link to this
 *  Program.
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any Glide wrapper (or a modified version of that library),
 *  containing parts not covered by a compatible license, provided that the
 *  wrapper does not link to this Program, the licensors of this Program
 *  grant you additional permission to convey the resulting work.
 */

#include "../include/game_library.h"

#include <windows.h>
#include <cstdint>
#include <cstdlib>
#include <memory>
#include <optional>
#include <string>
#include <string_view>

#include <boost/nowide/convert.hpp>
#include <boost/format.hpp>
#include <frozen/string.h>
#include <frozen/unordered_map.h>
#include "../include/game_version.h"

namespace sgd2mapi {

namespace {

constexpr const auto kDefaultLibraryPathById =
    frozen::make_unordered_map<enum DefaultLibrary, frozen::string>({
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
    });

std::optional<std::intptr_t> GetLibraryBaseAddress(
    std::string_view library_path) noexcept {
  std::wstring library_path_wide;
  try {
    library_path_wide = boost::nowide::widen(library_path.data());
  } catch (boost::locale::conv::conversion_error&) {
    return std::nullopt;
  }

  HMODULE base_address = LoadLibraryW(library_path_wide.data());
  if (base_address == nullptr) {
    return std::nullopt;
  }

  return reinterpret_cast<std::intptr_t>(base_address);
}

} // namespace

GameLibrary::GameLibrary(enum DefaultLibrary library)
    : GameLibrary(GetLibraryPathWithRedirect(library)) {
}

GameLibrary::GameLibrary(std::string_view library_path)
    : library_path_(library_path) {
  auto base_address = GetLibraryBaseAddress(library_path);
  if (!base_address.has_value()) {
    std::wstring error_message = (boost::wformat(
        L"Module base address detection for %s failed.")
        % library_path.data()).str();
    MessageBoxW(nullptr,
                error_message.data(),
                L"Module Failed to Load",
                MB_OK | MB_ICONERROR);
    std::exit(EXIT_FAILURE);
  }

  base_address_ = base_address.value();
}

GameLibrary::GameLibrary(const GameLibrary&) = default;

GameLibrary::GameLibrary(GameLibrary&&) noexcept = default;

GameLibrary::~GameLibrary() noexcept {
  FreeLibrary(reinterpret_cast<HMODULE>(base_address()));
}

GameLibrary& GameLibrary::operator=(const GameLibrary&) = default;

GameLibrary& GameLibrary::operator=(GameLibrary&&) noexcept = default;

std::string_view GameLibrary::GetLibraryPathWithRedirect(
    enum DefaultLibrary library) noexcept {
  if (IsGameVersionAtLeast1_14(GetRunningGameVersionId())) {
    return kGameExecutable.data();
  }

  return kDefaultLibraryPathById.at(library).data();
}

std::intptr_t GameLibrary::base_address() const noexcept {
  return base_address_;
}

std::string_view GameLibrary::library_path() const noexcept {
  return library_path_;
}

} // namespace sgd2mapi
