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

#include "../../include/c/game_address.h"

#include <string_view>
#include <utility>

#include "../../include/cxx/game_address.hpp"

namespace {

struct SGD2MAPI_GameAddress*
SGD2MAPI_GameAddress_LocateFromDecoratedName(
    const std::filesystem::path& library_path,
    std::string_view decorated_name
) {
  sgd2mapi::GameDecoratedName actual_game_decorated_name =
      sgd2mapi::GameDecoratedName(decorated_name);

  sgd2mapi::GameAddress actual_game_address(
      library_path,
      std::move(actual_game_decorated_name)
  );

  return reinterpret_cast<struct SGD2MAPI_GameAddress*>(
      actual_game_address.raw_address()
  );
}

struct SGD2MAPI_GameAddress*
SGD2MAPI_GameAddress_LocateFromDecoratedName(
    std::filesystem::path&& library_path,
    std::string_view decorated_name
) {
  sgd2mapi::GameDecoratedName actual_game_decorated_name =
      sgd2mapi::GameDecoratedName(decorated_name);

  sgd2mapi::GameAddress actual_game_address(
      std::move(library_path),
      std::move(actual_game_decorated_name)
  );

  return reinterpret_cast<struct SGD2MAPI_GameAddress*>(
      actual_game_address.raw_address()
  );
}

struct SGD2MAPI_GameAddress*
SGD2MAPI_GameAddress_LocateFromOffset(
    const std::filesystem::path& library_path,
    intptr_t offset
) {
  sgd2mapi::GameOffset actual_game_offset = sgd2mapi::GameOffset(offset);

  sgd2mapi::GameAddress actual_game_address(
      library_path,
      std::move(actual_game_offset)
  );

  return reinterpret_cast<struct SGD2MAPI_GameAddress*>(
      actual_game_address.raw_address()
  );
}

struct SGD2MAPI_GameAddress*
SGD2MAPI_GameAddress_LocateFromOffset(
    std::filesystem::path&& library_path,
    intptr_t offset
) {
  sgd2mapi::GameOffset actual_game_offset = sgd2mapi::GameOffset(offset);

  sgd2mapi::GameAddress actual_game_address(
      std::move(library_path),
      std::move(actual_game_offset)
  );

  return reinterpret_cast<struct SGD2MAPI_GameAddress*>(
      actual_game_address.raw_address()
  );
}

struct SGD2MAPI_GameAddress*
SGD2MAPI_GameAddress_LocateFromOrdinal(
    const std::filesystem::path& library_path,
    int ordinal
) {
  sgd2mapi::GameOrdinal actual_game_ordinal = sgd2mapi::GameOrdinal(ordinal);

  sgd2mapi::GameAddress actual_game_address(
      library_path,
      std::move(actual_game_ordinal)
  );

  return reinterpret_cast<struct SGD2MAPI_GameAddress*>(
      actual_game_address.raw_address()
  );
}

struct SGD2MAPI_GameAddress*
SGD2MAPI_GameAddress_LocateFromOrdinal(
    std::filesystem::path&& library_path,
    int ordinal
) {
  sgd2mapi::GameOrdinal actual_game_ordinal = sgd2mapi::GameOrdinal(ordinal);

  sgd2mapi::GameAddress actual_game_address(
      std::move(library_path),
      std::move(actual_game_ordinal)
  );

  return reinterpret_cast<struct SGD2MAPI_GameAddress*>(
      actual_game_address.raw_address()
  );
}

} // namespace

struct SGD2MAPI_GameAddress*
SGD2MAPI_GameAddress_LocateFromLibraryIdAndDecoratedName(
    int library_id,
    const char decorated_name[]
) {
  sgd2mapi::DefaultLibrary actual_default_library =
      static_cast<sgd2mapi::DefaultLibrary>(library_id);

  const std::filesystem::path& actual_library_path =
      sgd2mapi::GetDefaultLibraryPathWithRedirect(actual_default_library);

  return SGD2MAPI_GameAddress_LocateFromDecoratedName(
      actual_library_path,
      decorated_name
  );
}

struct SGD2MAPI_GameAddress*
SGD2MAPI_GameAddress_LocateFromLibraryPathAndDecoratedName(
    const char library_path[],
    const char decorated_name[]
) {
  return SGD2MAPI_GameAddress_LocateFromDecoratedName(
      library_path,
      decorated_name
  );
}

struct SGD2MAPI_GameAddress*
SGD2MAPI_GameAddress_LocateFromLibraryIdAndOffset(
    int library_id,
    intptr_t offset
) {
  sgd2mapi::DefaultLibrary actual_default_library =
      static_cast<sgd2mapi::DefaultLibrary>(library_id);

  const std::filesystem::path& actual_library_path =
      sgd2mapi::GetDefaultLibraryPathWithRedirect(actual_default_library);

  return SGD2MAPI_GameAddress_LocateFromOffset(
      actual_library_path,
      offset
  );
}

struct SGD2MAPI_GameAddress*
SGD2MAPI_GameAddress_LocateFromLibraryPathAndOffset(
    const char library_path[],
    intptr_t offset
) {
  return SGD2MAPI_GameAddress_LocateFromOffset(
      library_path,
      offset
  );
}

struct SGD2MAPI_GameAddress*
SGD2MAPI_GameAddress_LocateFromLibraryIdOrdinal(
    int library_id,
    int ordinal
) {
  sgd2mapi::DefaultLibrary actual_default_library =
      static_cast<sgd2mapi::DefaultLibrary>(library_id);

  const std::filesystem::path& actual_library_path =
      sgd2mapi::GetDefaultLibraryPathWithRedirect(actual_default_library);

  return SGD2MAPI_GameAddress_LocateFromOrdinal(
      actual_library_path,
      ordinal
  );
}

struct SGD2MAPI_GameAddress*
SGD2MAPI_GameAddress_LocateFromLibraryPathAndOrdinal(
    const char library_path[],
    int ordinal
) {
  return SGD2MAPI_GameAddress_LocateFromOrdinal(
      library_path,
      ordinal
  );
}
