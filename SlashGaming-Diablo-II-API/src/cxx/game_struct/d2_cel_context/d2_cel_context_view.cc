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

#include "../../../../include/cxx/game_struct/d2_cel_context.hpp"

#include "../../../../include/cxx/game_version.hpp"

namespace d2 {

CelContext_View::CelContext_View(
    const CelContext* cel_context
) noexcept : cel_context_(CreateVariant(cel_context)) {
}

CelContext_View::CelContext_View(
    const CelContext_View& other
) noexcept = default;

CelContext_View::CelContext_View(
    CelContext_View&& other
) noexcept = default;

CelContext_View::~CelContext_View() noexcept = default;

CelContext_View& CelContext_View::operator=(
    const CelContext_View& other
) noexcept = default;

CelContext_View& CelContext_View::operator=(
    CelContext_View&& other
) noexcept = default;

CelContext_View CelContext_View::operator[](std::size_t index) const noexcept {
  return std::visit(
      [index](const auto& actual_cel_context) {
        return reinterpret_cast<const CelContext*>(
            &actual_cel_context[index]
        );
      },
      this->cel_context_
  );
}

const CelContext* CelContext_View::Get() const noexcept {
  return std::visit(
      [](const auto& actual_cel_context) {
        return reinterpret_cast<const CelContext*>(actual_cel_context);
      },
      this->cel_context_
  );
}

CelFile_View CelContext_View::GetCelFile() const noexcept {
  return std::visit(
      [](const auto& actual_cel_context) {
        return reinterpret_cast<const CelFile*>(
            actual_cel_context->cel_file
        );
      },
      this->cel_context_
  );
}

unsigned int CelContext_View::GetDirection() const noexcept {
  return std::visit(
      [](const auto& actual_cel_context) {
        return actual_cel_context->direction;
      },
      this->cel_context_
  );
}

unsigned int CelContext_View::GetFrame() const noexcept {
  return std::visit(
      [](const auto& actual_cel_context) {
        return actual_cel_context->frame;
      },
      this->cel_context_
  );
}

CelContext_View::ViewVariant CelContext_View::CreateVariant(
    const CelContext* cel_context
) {
  GameVersion running_game_version = ::d2::game_version::GetRunning();

  if (running_game_version <= GameVersion::k1_10) {
    return reinterpret_cast<const CelContext_1_00*>(cel_context);
  } else if (running_game_version == GameVersion::k1_12A) {
    return reinterpret_cast<const CelContext_1_12A*>(cel_context);
  } else /* if (running_game_version >= GameVersion::k1_13ABeta) */ {
    return reinterpret_cast<const CelContext_1_13C*>(cel_context);
  }
}

} // namespace d2
