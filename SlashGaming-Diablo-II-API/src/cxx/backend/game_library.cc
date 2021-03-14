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

#include "game_library.hpp"

#include <windows.h>
#include <cassert>

#include <mdc/error/exit_on_error.hpp>
#include <mdc/wchar_t/filew.h>

namespace mapi {

GameLibrary::GameLibrary(
  std::filesystem::path file_path
)
    : file_path_(std::move(file_path)),
      base_address_(this->LoadGameLibraryBaseAddress(this->file_path())) {
}

GameLibrary::GameLibrary(GameLibrary&& rhs) noexcept
    : file_path_(std::move(rhs.file_path_)),
      base_address_(std::move(rhs.base_address_)) {
  rhs.base_address_ = reinterpret_cast<std::intptr_t>(nullptr);
};

GameLibrary::~GameLibrary() {
  HMODULE module_handle = reinterpret_cast<HMODULE>(this->base_address());

  if (module_handle != nullptr) {
    BOOL is_free_library_success = FreeLibrary(module_handle);

    if (!is_free_library_success) {
      ::mdc::error::ExitOnWindowsFunctionError(
          __FILEW__,
          __LINE__,
          L"FreeLibrary",
          GetLastError()
      );
    }
  }

  this->base_address_ = reinterpret_cast<std::intptr_t>(nullptr);
}

GameLibrary& GameLibrary::operator=(GameLibrary&& rhs) noexcept {
  if (this == &rhs) {
    return *this;
  }

  this->file_path_ = std::move(rhs.file_path_);
  this->base_address_ = std::move(rhs.base_address_);

  rhs.base_address_ = reinterpret_cast<std::intptr_t>(nullptr);

  return *this;
}

const GameLibrary& GameLibrary::GetGameLibrary(
    const std::filesystem::path& file_path
) {
  if (!GetLibrariesByPaths().contains(file_path)) {
    GetLibrariesByPaths().insert(
        std::pair(file_path, GameLibrary(file_path))
    );
  }

  assert(GetLibrariesByPaths().contains(file_path));

  return GetLibrariesByPaths().at(file_path);
}

std::map<std::filesystem::path, GameLibrary>&
GameLibrary::GetLibrariesByPaths() {
  static std::map<std::filesystem::path, GameLibrary> libraries_by_paths;

  return libraries_by_paths;
}

std::intptr_t GameLibrary::LoadGameLibraryBaseAddress(
    const std::filesystem::path& file_path
) {
  HMODULE base_address = LoadLibraryW(file_path.c_str());

  if (base_address == nullptr) {
    ::mdc::error::ExitOnWindowsFunctionError(
        __FILEW__,
        __LINE__,
        L"LoadLibraryW",
        GetLastError()
    );

    return 0;
  }

  return reinterpret_cast<std::intptr_t>(base_address);
}

} // namespace mapi
