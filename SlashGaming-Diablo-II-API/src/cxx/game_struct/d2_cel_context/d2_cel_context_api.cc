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

#include "../../../../include/cxx/game_struct/d2_cel_context/d2_cel_context_api.hpp"

#include "../../../../include/cxx/game_version.hpp"

namespace d2 {

CelContext_Api::CelContext_Api(
    CelFile_Wrapper cel_file,
    unsigned int direction,
    unsigned int frame
) : cel_context_(CreateVariant(cel_file.Get(), direction, frame)) {
}

CelContext_Api::CelContext_Api(const CelContext_Api& other) = default;

CelContext_Api::CelContext_Api(CelContext_Api&& other) noexcept = default;

CelContext_Api::~CelContext_Api() = default;

CelContext_Api& CelContext_Api::operator=(
    const CelContext_Api& other
) = default;

CelContext_Api& CelContext_Api::operator=(
    CelContext_Api&& other
) noexcept = default;

CelContext_Api::operator CelContext_View() const noexcept {
  return CelContext_View(this->Get());
}

CelContext_Api::operator CelContext_Wrapper() noexcept {
  return CelContext_Wrapper(this->Get());
}

CelContext* CelContext_Api::Get() noexcept {
  const auto* const_this = this;

  return const_cast<CelContext*>(const_this->Get());
}

const CelContext* CelContext_Api::Get() const noexcept {
  return std::visit(
      [](const auto& actual_cel_context) {
        return reinterpret_cast<const CelContext*>(&actual_cel_context);
      },
      this->cel_context_
  );
}

void CelContext_Api::Assign(CelContext_View src) {
  CelContext_Wrapper dest_wrapper(this->Get());

  dest_wrapper.Assign(src);
}

bool CelContext_Api::DrawFrame(int position_x, int position_y) {
  CelContext_Wrapper wrapper(this->Get());

  return wrapper.DrawFrame(position_x, position_y);
}

bool CelContext_Api::DrawFrame(
    int position_x,
    int position_y,
    const DrawCelFileFrameOptions& frame_options
) {
  CelContext_Wrapper wrapper(this->Get());

  return wrapper.DrawFrame(position_x, position_y, frame_options);
}

Cel* CelContext_Api::GetCel() {
  CelContext_Wrapper wrapper(this->Get());

  return wrapper.GetCel();
}

CelFile_View CelContext_Api::GetCelFile() const noexcept {
  CelContext_View view(this->Get());

  return view.GetCelFile();
}

CelFile_Wrapper CelContext_Api::GetCelFile() noexcept {
  CelContext_Wrapper wrapper(this->Get());

  return wrapper.GetCelFile();
}

void CelContext_Api::SetCelFile(CelFile_Wrapper cel_file) noexcept {
  CelContext_Wrapper wrapper(this->Get());

  wrapper.SetCelFile(cel_file);
}

unsigned int CelContext_Api::GetDirection() const noexcept {
  CelContext_View view(this->Get());

  return view.GetDirection();
}

void CelContext_Api::SetDirection(unsigned int direction) noexcept {
  CelContext_Wrapper wrapper(this->Get());

  wrapper.SetDirection(direction);
}

unsigned int CelContext_Api::GetFrame() const noexcept {
  CelContext_View view(this->Get());

  return view.GetFrame();
}

void CelContext_Api::SetFrame(unsigned int frame) noexcept {
  CelContext_Wrapper wrapper(this->Get());

  wrapper.SetFrame(frame);
}

CelContext_Api::ApiVariant CelContext_Api::CreateVariant(
    CelFile* cel_file,
    unsigned int direction,
    unsigned int frame
) {
  ApiVariant cel_context;

  GameVersion running_game_version = GetRunningGameVersionId();

  if (running_game_version <= d2::GameVersion::k1_10) {
    cel_context = CelContext_1_00();
  } else if (running_game_version == GameVersion::k1_12A) {
    cel_context = CelContext_1_12A();
  } else /* if (running_game_version >= GameVersion::k1_13ABeta) */ {
    cel_context = CelContext_1_13C();
  }

  std::visit(
      [cel_file, direction, frame](auto& actual_cel_context) {
        using CelContext_T = std::remove_reference_t<
            decltype(actual_cel_context)
        >;
        using CelFile_T = std::remove_pointer_t<
            decltype(CelContext_T::cel_file)
        >;

        actual_cel_context.cel_file =
            reinterpret_cast<CelFile_T*>(cel_file);
        actual_cel_context.direction = direction;
        actual_cel_context.frame = frame;
      },
      cel_context
  );

  return cel_context;
}

} // namespace d2
