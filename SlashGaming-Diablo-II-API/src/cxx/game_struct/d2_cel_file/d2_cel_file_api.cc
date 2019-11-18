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

#include "../../../../include/cxx/game_struct/d2_cel_file/d2_cel_file_api.hpp"

#include "../../../../include/cxx/game_func/d2win_func.hpp"

namespace d2 {
namespace {

using CelFileVariant = std::variant<
    CelFile_1_00*
>;

CelFileVariant CreateVariant(
    std::string_view cel_file_path,
    bool is_dcc_else_dc6
) {
  CelFile* cel_file = d2win::LoadCelFile(
      cel_file_path.data(),
      is_dcc_else_dc6
  );

  return reinterpret_cast<CelFile_1_00*>(cel_file);
}

} // namespace

CelFile_API::CelFile_API() :
    cel_file_(nullptr),
    is_open_(false) {
}

CelFile_API::CelFile_API(
    std::string_view cel_file_path,
    bool is_dcc_else_dc6
) : cel_file_(nullptr),
    is_open_(false) {
  this->Open(cel_file_path, is_dcc_else_dc6);
}

CelFile_API::CelFile_API(CelFile_API&& other) noexcept :
    cel_file_(other.cel_file_),
    is_open_(other.is_open_) {
  other.cel_file_ = nullptr;
  other.is_open_ = false;
}

CelFile_API::~CelFile_API() {
  Close();
}

CelFile_API& CelFile_API::operator=(CelFile_API&& other) noexcept = default;

CelFile_API::operator CelFile_View() const noexcept {
  return CelFile_View(this->Get());
}

const CelFile* CelFile_API::Get() const noexcept {
  auto* actual_cel_file = std::get<CelFile_1_00*>(this->cel_file_);

  return reinterpret_cast<CelFile*>(actual_cel_file);
}

void CelFile_API::Close() {
  if (this->IsOpen()) {
    d2win::UnloadCelFile(const_cast<CelFile*>(this->Get()));
    this->is_open_ = false;
  }
}

bool CelFile_API::DrawFrame(
    int position_x,
    int position_y,
    unsigned int direction,
    unsigned int frame
) {
  CelFile_Wrapper wrapper(const_cast<CelFile*>(this->Get()));

  return wrapper.DrawFrame(
      position_x,
      position_y,
      direction,
      frame
  );
}

bool CelFile_API::DrawFrame(
    int position_x,
    int position_y,
    unsigned int direction,
    unsigned int frame,
    const DrawCelFileFrameOptions& frame_options
) {
  CelFile_Wrapper wrapper(const_cast<CelFile*>(this->Get()));

  return wrapper.DrawFrame(
      position_x,
      position_y,
      direction,
      frame,
      frame_options
  );
}

bool CelFile_API::DrawAllFrames(
    int position_x,
    int position_y,
    unsigned int columns,
    unsigned int rows
) {
  CelFile_Wrapper wrapper(const_cast<CelFile*>(this->Get()));

  return wrapper.DrawAllFrames(
      position_x,
      position_y,
      columns,
      rows
  );
}

bool CelFile_API::DrawAllFrames(
    int position_x,
    int position_y,
    unsigned int columns,
    unsigned int rows,
    const DrawAllCelFileFramesOptions& all_frames_options
) {
  CelFile_Wrapper wrapper(const_cast<CelFile*>(this->Get()));

  return wrapper.DrawAllFrames(
      position_x,
      position_y,
      columns,
      rows,
      all_frames_options
  );
}

const Cel* CelFile_API::GetCel(unsigned int direction, unsigned int frame) {
  CelFile_Wrapper wrapper(const_cast<CelFile*>(this->Get()));

  return wrapper.GetCel(direction, frame);
}

bool CelFile_API::IsOpen() const {
  return this->is_open_;
}

void CelFile_API::Open(
    std::string_view cel_file_path,
    bool is_dcc_else_dc6
) {
  this->Close();

  this->cel_file_ = CreateVariant(
      cel_file_path,
      is_dcc_else_dc6
  );

  this->is_open_ = (this->Get() != nullptr);
}

unsigned int CelFile_API::GetVersion() const noexcept {
  CelFile_View view(*this);

  return view.GetVersion();
}

unsigned int CelFile_API::GetNumDirections() const noexcept {
  CelFile_View view(*this);

  return view.GetNumDirections();
}

unsigned int CelFile_API::GetNumFrames() const noexcept {
  CelFile_View view(*this);

  return view.GetNumFrames();
}

} // namespace d2
