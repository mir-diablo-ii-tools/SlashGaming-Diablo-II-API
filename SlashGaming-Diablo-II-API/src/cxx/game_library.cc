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

#include "game_library.hpp"

#include <windows.h>
#include <cstdint>
#include <filesystem>
#include <map>
#include <stdexcept>
#include <string>
#include <string_view>

#include <fmt/format.h>
#include <fmt/printf.h>
#include "../../include/cxx/default_game_library.hpp"
#include "../wide_macro.h"

namespace mapi {
namespace {

constexpr std::wstring_view kFunctionFailErrorFormat =
    L"File: %s \n"
    L"Line: %d \n"
    L"The function %s failed with error code %x.";

std::intptr_t
GetLibraryBaseAddress(
    const std::filesystem::path& library_path
) {
  std::wstring library_path_text_wide = library_path.wstring();

  HMODULE base_address = LoadLibraryW(library_path_text_wide.data());
  if (base_address == nullptr) {
    std::wstring full_message = fmt::sprintf(
        kFunctionFailErrorFormat,
        __FILEW__,
        __LINE__,
        L"LoadLibraryW",
        GetLastError()
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

std::map<std::filesystem::path, GameLibrary>&
GetLibrariesByPaths(
    void
) {
  static std::map<std::filesystem::path, GameLibrary> libraries_by_paths;
  return libraries_by_paths;
}

} // namespace

GameLibrary::GameLibrary(
    enum DefaultLibrary library
)
    : GameLibrary(GetDefaultLibraryPathWithRedirect(library)) {
}

GameLibrary::GameLibrary(
  const std::filesystem::path& library_path
)
    : library_path_(library_path),
      base_address_(GetLibraryBaseAddress(library_path)) {
}

GameLibrary::GameLibrary(
    std::filesystem::path&& library_path
)
    : library_path_(std::move(library_path)),
      base_address_(GetLibraryBaseAddress(library_path_)) {
}

GameLibrary::GameLibrary(
    const GameLibrary& rhs
)
    : library_path_(rhs.library_path_),
      base_address_(GetLibraryBaseAddress(library_path_)) {
};

GameLibrary::GameLibrary(
    GameLibrary&& rhs
)
    : library_path_(std::move(rhs.library_path_)),
      base_address_(GetLibraryBaseAddress(library_path_)) {
};

GameLibrary::~GameLibrary(
    void
) {
  FreeLibrary(reinterpret_cast<HMODULE>(base_address()));
}

GameLibrary&
GameLibrary::operator=(
    const GameLibrary& rhs
) {
  if (this == &rhs) {
    return *this;
  }

  this->library_path_ = rhs.library_path_;
  this->base_address_ = GetLibraryBaseAddress(library_path_);

  return *this;
}

GameLibrary&
GameLibrary::operator=(
    GameLibrary&& rhs
) {
  if (this == &rhs) {
    return *this;
  }

  this->library_path_ = std::move(rhs.library_path_);
  this->base_address_ = GetLibraryBaseAddress(this->library_path());

  return *this;
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

const GameLibrary&
GetGameLibrary(
    const std::filesystem::path& library_path
) {
  std::map<std::filesystem::path, GameLibrary>& libraries_by_paths =
      GetLibrariesByPaths();

  if (libraries_by_paths.count(library_path) == 0) {
    libraries_by_paths.insert_or_assign(
        library_path,
        GameLibrary(library_path)
    );
  }

  try {
    return GetLibrariesByPaths().at(library_path);
  } catch (const std::out_of_range& e) {
    constexpr std::wstring_view kErrorFormatMessage =
        L"File: %s \n"
        L"Line: %d \n"
        L"Could not determine the game library from the file path: %s.";

    std::wstring full_message = fmt::sprintf(
        kErrorFormatMessage,
        __FILEW__,
        __LINE__,
        library_path
    );

    MessageBoxW(
        nullptr,
        full_message.data(),
        L"Failed to Determine Game Library",
        MB_OK | MB_ICONERROR
    );

    std::exit(0);
  }
}

const GameLibrary&
GetGameLibrary(
    enum DefaultLibrary library
) {
  const std::filesystem::path& library_path =
      GetDefaultLibraryPathWithRedirect(
          library
      );
  return GetGameLibrary(library_path);
}

} // namespace mapi
