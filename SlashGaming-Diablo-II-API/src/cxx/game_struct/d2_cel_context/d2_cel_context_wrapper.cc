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

#include "d2_cel_context_impl.hpp"
#include "../../../../include/cxx/game_version.hpp"

namespace d2 {

CelContext_Wrapper::CelContext_Wrapper(
    CelContext* ptr
) noexcept :
    CelContext_ConstWrapper(ptr),
    ptr_(ptr) {
}

CelContext_Wrapper::CelContext_Wrapper(
    const CelContext_Wrapper& other
) = default;

CelContext_Wrapper::CelContext_Wrapper(
    CelContext_Wrapper&& other
) noexcept = default;

CelContext_Wrapper::~CelContext_Wrapper() = default;

CelContext_Wrapper& CelContext_Wrapper::operator=(
    const CelContext_Wrapper& other
) = default;

CelContext_Wrapper& CelContext_Wrapper::operator=(
    CelContext_Wrapper&& other
) noexcept = default;

CelContext* CelContext_Wrapper::Get() noexcept {
  return this->ptr_;
}

const CelContext* CelContext_Wrapper::Get() const noexcept {
  return CelContext_ConstWrapper::Get();
}

const CelFile* CelContext_Wrapper::GetCelFile() const noexcept {
  return CelContext_ConstWrapper::GetCelFile();
}

CelFile* CelContext_Wrapper::GetCelFile() noexcept {
  CelContext* cel_context = this->Get();
  GameVersion running_game_version = GetRunningGameVersionId();

  if (running_game_version >= GameVersion::k1_00
      && running_game_version <= GameVersion::k1_10) {
    auto actual_cel_context = reinterpret_cast<CelContext_1_00*>(
        cel_context
    );
    return reinterpret_cast<CelFile*>(actual_cel_context->cel_file);
  } else if (running_game_version == GameVersion::k1_12A) {
    auto actual_cel_context = reinterpret_cast<CelContext_1_12A*>(
        cel_context
    );
    return reinterpret_cast<CelFile*>(actual_cel_context->cel_file);
  } else if (running_game_version >= GameVersion::k1_13C
      && running_game_version <= GameVersion::kLod1_14D) {
    auto actual_cel_context = reinterpret_cast<CelContext_1_13C*>(
        cel_context
    );
    return reinterpret_cast<CelFile*>(actual_cel_context->cel_file);
  }
}

void CelContext_Wrapper::SetCelFile(CelFile* cel_file) noexcept {
  CelContext* cel_context = this->Get();
  GameVersion running_game_version = GetRunningGameVersionId();

  auto actual_cel_file = reinterpret_cast<CelFile_1_00*>(cel_file);

  if (running_game_version >= GameVersion::k1_00
      && running_game_version <= GameVersion::k1_10) {
    auto actual_cel_context = reinterpret_cast<CelContext_1_00*>(
        cel_context
    );
    actual_cel_context->cel_file = actual_cel_file;
  } else if (running_game_version == GameVersion::k1_12A) {
    auto actual_cel_context = reinterpret_cast<CelContext_1_12A*>(
        cel_context
    );
    actual_cel_context->cel_file = actual_cel_file;
  } else if (running_game_version >= GameVersion::k1_13C
      && running_game_version <= GameVersion::kLod1_14D) {
    auto actual_cel_context = reinterpret_cast<CelContext_1_13C*>(
        cel_context
    );
    actual_cel_context->cel_file = actual_cel_file;
  }
}

void CelContext_Wrapper::SetDirection(unsigned int direction) noexcept {
  CelContext* cel_context = this->Get();
  GameVersion running_game_version = GetRunningGameVersionId();

  if (running_game_version >= GameVersion::k1_00
      && running_game_version <= GameVersion::k1_10) {
    auto actual_cel_context = reinterpret_cast<CelContext_1_00*>(
        cel_context
    );
    actual_cel_context->direction = direction;
  } else if (running_game_version == GameVersion::k1_12A) {
    auto actual_cel_context = reinterpret_cast<CelContext_1_12A*>(
        cel_context
    );
    actual_cel_context->direction = direction;
  } else if (running_game_version >= GameVersion::k1_13C
      && running_game_version <= GameVersion::kLod1_14D) {
    auto actual_cel_context = reinterpret_cast<CelContext_1_13C*>(
        cel_context
    );
    actual_cel_context->direction = direction;
  }
}

void CelContext_Wrapper::SetFrame(unsigned int frame) noexcept {
  CelContext* cel_context = this->Get();
  GameVersion running_game_version = GetRunningGameVersionId();

  if (running_game_version >= GameVersion::k1_00
      && running_game_version <= GameVersion::k1_10) {
    auto actual_cel_context = reinterpret_cast<CelContext_1_00*>(
        cel_context
    );
    actual_cel_context->frame = frame;
  } else if (running_game_version == GameVersion::k1_12A) {
    auto actual_cel_context = reinterpret_cast<CelContext_1_12A*>(
        cel_context
    );
    actual_cel_context->frame = frame;
  } else if (running_game_version >= GameVersion::k1_13C
      && running_game_version <= GameVersion::kLod1_14D) {
    auto actual_cel_context = reinterpret_cast<CelContext_1_13C*>(
        cel_context
    );
    actual_cel_context->frame = frame;
  }
}

} // namespace d2
