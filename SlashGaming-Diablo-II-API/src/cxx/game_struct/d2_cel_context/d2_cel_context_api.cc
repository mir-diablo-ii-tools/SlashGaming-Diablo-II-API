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

#include "../../../../include/cxx/game_struct/d2_cel_context/d2_cel_context_api.hpp"

#include <filesystem>

#include "d2_cel_context_impl.hpp"
#include "../../../../include/cxx/game_func/d2win_func.hpp"
#include "../../../../include/cxx/game_version.hpp"

namespace d2 {
namespace {

using unique_ptr_1_00 = std::unique_ptr<CelContext_1_00[]>;
using unique_ptr_1_12A = std::unique_ptr<CelContext_1_12A[]>;
using unique_ptr_1_13C = std::unique_ptr<CelContext_1_13C[]>;

using CelContextVariant = std::variant<
    unique_ptr_1_00,
    unique_ptr_1_12A,
    unique_ptr_1_13C
>;

CelContextVariant CreateVariant(
    CelFile* cel_file,
    unsigned int direction,
    unsigned int frame
) {
  CelContext* cel_context = CreateCelContext(cel_file, direction, frame);

  d2::GameVersion running_game_version = d2::GetRunningGameVersionId();

  if (running_game_version >= d2::GameVersion::k1_00
      && running_game_version <= d2::GameVersion::k1_09D) {
    return unique_ptr_1_00(reinterpret_cast<CelContext_1_00*>(cel_context));
  } else if (running_game_version == GameVersion::k1_12A) {
    return unique_ptr_1_12A(reinterpret_cast<CelContext_1_12A*>(cel_context));
  } else /* if (running_game_version >= GameVersion::k1_13C
      && running_game_version <= GameVersion::kLod1_14D) */ {
    return unique_ptr_1_13C(reinterpret_cast<CelContext_1_13C*>(cel_context));
  }
}

} // namespace

CelContext_API::CelContext_API(
    CelFile* cel_file,
    unsigned int direction,
    unsigned int frame
) : cel_context_(
        CreateVariant(cel_file, direction, frame)
    ) {
}

CelContext_API::CelContext_API(const CelContext_API& other) :
    CelContext_API(
        const_cast<CelFile*>(other.GetCelFile()),
        other.GetDirection(),
        other.GetFrame()
    ) {
}

CelContext_API::CelContext_API(CelContext_API&& other) noexcept = default;

CelContext_API::~CelContext_API() = default;

CelContext_API& CelContext_API::operator=(
    const CelContext_API& other
) {
  *this = CelContext_API(other);
  return *this;
}

CelContext_API& CelContext_API::operator=(
    CelContext_API&& other
) noexcept = default;

CelContext_API::operator CelContext_View() const noexcept {
  return CelContext_View(this->Get());
}

CelContext_API::operator CelContext_Wrapper() noexcept {
  return CelContext_Wrapper(this->Get());
}

CelContext* CelContext_API::Get() noexcept {
  const auto* const_this = this;

  return const_cast<CelContext*>(const_this->Get());
}

const CelContext* CelContext_API::Get() const noexcept {
  d2::GameVersion running_game_version = d2::GetRunningGameVersionId();

  if (running_game_version >= d2::GameVersion::k1_00
      && running_game_version <= d2::GameVersion::k1_10) {
    auto& cel_context = std::get<unique_ptr_1_00>(this->cel_context_);

    return reinterpret_cast<CelContext*>(cel_context.get());
  } else if (running_game_version == GameVersion::k1_12A) {
    auto& cel_context = std::get<unique_ptr_1_12A>(this->cel_context_);

    return reinterpret_cast<CelContext*>(cel_context.get());
  } else /* if (running_game_version >= GameVersion::k1_13C
      && running_game_version <= GameVersion::kLod1_14D) */ {
    auto& cel_context = std::get<unique_ptr_1_13C>(this->cel_context_);

    return reinterpret_cast<CelContext*>(cel_context.get());
  }

  return nullptr;
}

bool CelContext_API::DrawFrame(int position_x, int position_y) {
  CelContext_Wrapper wrapper(*this);

  return wrapper.DrawFrame(position_x, position_y);
}

bool CelContext_API::DrawFrame(
    int position_x,
    int position_y,
    const DrawCelFileFrameOptions& frame_options
) {
  CelContext_Wrapper wrapper(*this);

  return wrapper.DrawFrame(position_x, position_y, frame_options);
}

Cel* CelContext_API::GetCel() {
  CelContext_Wrapper wrapper(*this);

  return wrapper.GetCel();
}

CelFile* CelContext_API::GetCelFile() noexcept {
  CelContext_Wrapper wrapper(*this);

  return wrapper.GetCelFile();
}

const CelFile* CelContext_API::GetCelFile() const noexcept {
  CelContext_View view(*this);

  return view.GetCelFile();
}

unsigned int CelContext_API::GetDirection() const noexcept {
  CelContext_View view(*this);

  return view.GetDirection();
}

unsigned int CelContext_API::GetFrame() const noexcept {
  CelContext_View view(*this);

  return view.GetFrame();
}

void CelContext_API::SetCelFile(CelFile* cel_file) noexcept {
  CelContext_Wrapper wrapper(*this);

  wrapper.SetCelFile(cel_file);
}

void CelContext_API::SetDirection(unsigned int direction) noexcept {
  CelContext_Wrapper wrapper(*this);

  wrapper.SetDirection(direction);
}

void CelContext_API::SetFrame(unsigned int frame) noexcept {
  CelContext_Wrapper wrapper(*this);

  wrapper.SetFrame(frame);
}

CelContext* CreateCelContext(
    CelFile* cel_file,
    unsigned int direction,
    unsigned int frame
) {
  d2::GameVersion running_game_version = d2::GetRunningGameVersionId();

  if (running_game_version >= d2::GameVersion::k1_00
      && running_game_version <= d2::GameVersion::k1_10) {
    std::unique_ptr cel_context = std::make_unique<CelContext_1_00[]>(1);

    cel_context[0].cel_file = reinterpret_cast<CelFile_1_00*>(cel_file);
    cel_context[0].direction = direction;
    cel_context[0].frame = frame;

    return reinterpret_cast<CelContext*>(cel_context.release());
  } else if (running_game_version == GameVersion::k1_12A) {
    std::unique_ptr cel_context = std::make_unique<CelContext_1_12A[]>(1);

    cel_context[0].cel_file = reinterpret_cast<CelFile_1_00*>(cel_file);
    cel_context[0].direction = direction;
    cel_context[0].frame = frame;

    return reinterpret_cast<CelContext*>(cel_context.release());
  } else /* if (running_game_version >= GameVersion::k1_13C
      && running_game_version <= GameVersion::kLod1_14D) */ {
    std::unique_ptr cel_context = std::make_unique<CelContext_1_13C[]>(1);

    cel_context[0].cel_file = reinterpret_cast<CelFile_1_00*>(cel_file);
    cel_context[0].direction = direction;
    cel_context[0].frame = frame;

    return reinterpret_cast<CelContext*>(cel_context.release());
  }
}

CelContext* CreateCelContextArray(std::size_t count) {
  d2::GameVersion running_game_version = d2::GetRunningGameVersionId();

  if (running_game_version >= d2::GameVersion::k1_00
      && running_game_version <= d2::GameVersion::k1_09D) {
    std::unique_ptr cel_context_array =
        std::make_unique<CelContext_1_00[]>(count);
    return reinterpret_cast<CelContext*>(cel_context_array.release());
  } else if (running_game_version == GameVersion::k1_12A) {
    std::unique_ptr cel_context_array =
        std::make_unique<CelContext_1_12A[]>(count);
    return reinterpret_cast<CelContext*>(cel_context_array.release());
  } else /* if (running_game_version >= GameVersion::k1_13C
      && running_game_version <= GameVersion::kLod1_14D) */ {
    std::unique_ptr cel_context_array =
        std::make_unique<CelContext_1_13C[]>(count);
    return reinterpret_cast<CelContext*>(cel_context_array.release());
  }
}

void DestroyCelContext(CelContext* cel_context) {
  d2::GameVersion running_game_version = d2::GetRunningGameVersionId();

  if (running_game_version >= d2::GameVersion::k1_00
      && running_game_version <= d2::GameVersion::k1_09D) {
    delete[] reinterpret_cast<CelContext_1_00*>(cel_context);
  } else if (running_game_version == GameVersion::k1_12A) {
    delete[] reinterpret_cast<CelContext_1_12A*>(cel_context);
  } else /* if (running_game_version >= GameVersion::k1_13C
      && running_game_version <= GameVersion::kLod1_14D) */ {
    delete[] reinterpret_cast<CelContext_1_13C*>(cel_context);
  }
}

} // namespace d2
