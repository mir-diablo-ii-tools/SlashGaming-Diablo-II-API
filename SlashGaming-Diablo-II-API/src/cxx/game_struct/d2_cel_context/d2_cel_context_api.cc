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

#include "../../../../include/cxx/game_struct/d2_cel_context.hpp"

#include <filesystem>

#include "d2_cel_context_impl.hpp"
#include "../../../../include/cxx/game_func/d2win_func.hpp"
#include "../../../../include/cxx/game_version.hpp"

namespace d2 {

CelContext_API::CelContext_API(
    CelFile* cel_file,
    int direction,
    int frame
) : CelContext_Wrapper(
        CreateCelContext(cel_file, direction, frame)
    ) {
}

CelContext_API::CelContext_API(const CelContext_API& other) = default;

CelContext_API::CelContext_API(CelContext_API&& other) noexcept = default;

CelContext_API::~CelContext_API() {
}

CelContext_API& CelContext_API::operator=(
    const CelContext_API& other
) = default;

CelContext_API& CelContext_API::operator=(
    CelContext_API&& other
) noexcept = default;

CelContext* CreateCelContext(
    CelFile* cel_file,
    int direction,
    int frame
) {
  d2::GameVersion running_game_version = d2::GetRunningGameVersionId();

  if (running_game_version >= d2::GameVersion::k1_00
      && running_game_version <= d2::GameVersion::k1_10) {
    CelContext_1_00* cel_context = new CelContext_1_00[1];

    cel_context->cel_file = cel_file;
    cel_context->direction = direction;
    cel_context->frame = frame;

    return reinterpret_cast<CelContext*>(cel_context);
  } else if (running_game_version == GameVersion::k1_12A) {
    CelContext_1_12A* cel_context = new CelContext_1_12A[1];

    cel_context->cel_file = cel_file;
    cel_context->direction = direction;
    cel_context->frame = frame;

    return reinterpret_cast<CelContext*>(cel_context);
  } else if (running_game_version >= GameVersion::k1_13C
      && running_game_version <= GameVersion::kLod1_14D) {
    CelContext_1_13C* cel_context = new CelContext_1_13C[1];

    cel_context->cel_file = cel_file;
    cel_context->direction = direction;
    cel_context->frame = frame;

    return reinterpret_cast<CelContext*>(cel_context);
  }
}

CelContext* CreateCelContextArray(std::size_t count) {
  d2::GameVersion running_game_version = d2::GetRunningGameVersionId();

  if (running_game_version >= d2::GameVersion::k1_00
      && running_game_version <= d2::GameVersion::k1_09D) {
    CelContext_1_00* cel_context_array = new CelContext_1_00[count];
    return reinterpret_cast<CelContext*>(cel_context_array);
  } else if (running_game_version == GameVersion::k1_12A) {
    CelContext_1_12A* cel_context_array = new CelContext_1_12A[count];
    return reinterpret_cast<CelContext*>(cel_context_array);
  } else if (running_game_version >= GameVersion::k1_13C
      && running_game_version <= GameVersion::kLod1_14D) {
    CelContext_1_13C* cel_context_array = new CelContext_1_13C[count];
    return reinterpret_cast<CelContext*>(cel_context_array);
  }
}

void DestroyCelContext(CelContext* cel_context) {
  d2::GameVersion running_game_version = d2::GetRunningGameVersionId();

  if (running_game_version >= d2::GameVersion::k1_00
      && running_game_version <= d2::GameVersion::k1_09D) {
    delete[] reinterpret_cast<CelContext_1_00*>(cel_context);
  } else if (running_game_version == GameVersion::k1_12A) {
    delete[] reinterpret_cast<CelContext_1_12A*>(cel_context);
  } else if (running_game_version >= GameVersion::k1_13C
      && running_game_version <= GameVersion::kLod1_14D) {
    delete[] reinterpret_cast<CelContext_1_13C*>(cel_context);
  }
}

} // namespace d2
