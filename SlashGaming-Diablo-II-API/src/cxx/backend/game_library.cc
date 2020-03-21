/**
 * SlashGaming Diablo II Modding API for C++
 * Copyright (C) 2018-2020  Mir Drualga
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
#include <cstdint>
#include <filesystem>
#include <map>
#include <stdexcept>
#include <string>
#include <string_view>

#include <fmt/format.h>
#include "error_handling.hpp"
#include "../../wide_macro.h"

namespace mapi {

std::map<std::filesystem::path, GameLibrary> GameLibrary::libraries_by_paths;

GameLibrary::GameLibrary(
  const std::filesystem::path& file_path
)
    : file_path_(file_path),
      base_address_(this->LoadGameLibraryBaseAddress(this->file_path())) {
}

GameLibrary::GameLibrary(
    std::filesystem::path&& file_path
)
    : file_path_(std::move(file_path)),
      base_address_(this->LoadGameLibraryBaseAddress(this->file_path())) {
}

GameLibrary::GameLibrary(const GameLibrary& rhs)
    : file_path_(rhs.file_path_),
      base_address_(this->LoadGameLibraryBaseAddress(this->file_path())) {
};

GameLibrary::GameLibrary(GameLibrary&& rhs) noexcept
    : file_path_(std::move(rhs.file_path_)),
      base_address_(std::move(rhs.base_address_)) {
  rhs.base_address_ = reinterpret_cast<std::intptr_t>(nullptr);
};

GameLibrary::~GameLibrary() {
  HMODULE module_handle = reinterpret_cast<HMODULE>(this->base_address());

  if (module_handle != nullptr) {
    FreeLibrary(module_handle);
  }
}

GameLibrary& GameLibrary::operator=(const GameLibrary& rhs) {
  if (this == &rhs) {
    return *this;
  }

  this->file_path_ = rhs.file_path();
  this->base_address_ = this->LoadGameLibraryBaseAddress(this->file_path());

  return *this;
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
  if (!libraries_by_paths.contains(file_path)) {
    libraries_by_paths.insert_or_assign(
        file_path,
        GameLibrary(file_path)
    );
  }

  try {
    return libraries_by_paths.at(file_path);
  } catch (const std::out_of_range& e) {
    std::wstring full_message = fmt::format(
        L"Could not determine the game library from the file path: {}.",
        file_path.wstring().data()
    );

    ExitOnGeneralFailure(
        full_message,
        L"Failed to Determine Game Library",
        __FILEW__,
        __LINE__
    );
  }
}

std::intptr_t GameLibrary::base_address() const noexcept {
  return base_address_;
}

const std::filesystem::path& GameLibrary::file_path() const noexcept {
  return file_path_;
}

std::intptr_t GameLibrary::LoadGameLibraryBaseAddress(
    const std::filesystem::path& file_path
) {
  std::wstring file_path_text_wide = file_path.wstring();
  HMODULE base_address = LoadLibraryW(file_path_text_wide.data());

  if (base_address == nullptr) {
    ExitOnWindowsFunctionFailureWithLastError(
        L"LoadLibraryW",
        GetLastError(),
        __FILEW__,
        __LINE__
    );
  }

  return reinterpret_cast<std::intptr_t>(base_address);
}

} // namespace mapi
