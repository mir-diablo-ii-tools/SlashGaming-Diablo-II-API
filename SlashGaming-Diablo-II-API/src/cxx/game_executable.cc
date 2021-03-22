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

#include "../../include/cxx/game_executable.hpp"

#include <windows.h>

#include <memory>

#include "backend/d2se/d2se_file_signature.hpp"

namespace mapi::game_executable {
namespace {

static std::filesystem::path InitGameExecutablePath() {
  DWORD path_len;
  size_t capacity;
  size_t new_capacity = MAX_PATH;
  std::unique_ptr<wchar_t[]> path_buffer;

  do {
    capacity = new_capacity;
    path_buffer = std::make_unique<wchar_t[]>(capacity);
    path_len = GetModuleFileNameW(nullptr, path_buffer.get(), capacity);

    new_capacity *= 2;
  } while (path_len >= capacity - 1);

  return path_buffer.get();
}

} // namespace

const std::filesystem::path& GetPath() {
  static std::filesystem::path kGameExecutablePath = InitGameExecutablePath();

  return kGameExecutablePath;
}

bool IsD2se() {
  return d2se::file_signature::IsFileD2seExecutable(
      GetPath()
  );
}

} // namespace mapi::game_executable
