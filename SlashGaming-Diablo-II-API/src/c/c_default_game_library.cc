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

#include "../../include/c/default_game_library.h"

#include <stddef.h>
#include <algorithm>
#include <filesystem>
#include <string>

#include "../../include/cxx/default_game_library.hpp"

char*
SGD2MAPI_GetGameExecutablePath(
  char dest[]
) {
  std::string game_executable_path_text =
      sgd2mapi::GetGameExecutablePath().u8string();

  std::copy(
      game_executable_path_text.cbegin(),
      game_executable_path_text.cend(),
      dest
  );

  return dest;
}

size_t
SGD2MAPI_GetGameExecutablePathSize(
    void
) {
  return sgd2mapi::GetGameExecutablePath().u8string().size() + 1;
}

char*
GetDefaultLibraryPathWithRedirect(
    char dest[],
    int library_id
) {
  enum sgd2mapi::DefaultLibrary actual_default_library =
      static_cast<sgd2mapi::DefaultLibrary>(library_id);

  const std::filesystem::path& default_library_path =
      sgd2mapi::GetDefaultLibraryPathWithRedirect(actual_default_library);

  std::string default_library_path_text =
      default_library_path.u8string();

  std::copy(
      default_library_path_text.cbegin(),
      default_library_path_text.cend(),
      dest
  );

  return dest;
}

size_t
GetDefaultLibraryPathWithRedirectSize(
    int library_id
) {
  enum sgd2mapi::DefaultLibrary actual_default_library =
      static_cast<sgd2mapi::DefaultLibrary>(library_id);

  const std::filesystem::path& default_library_path =
      sgd2mapi::GetDefaultLibraryPathWithRedirect(actual_default_library);

  return default_library_path.u8string().size() + 1;
}
