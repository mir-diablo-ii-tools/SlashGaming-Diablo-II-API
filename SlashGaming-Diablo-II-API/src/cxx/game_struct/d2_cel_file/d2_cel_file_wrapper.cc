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

#include "../../../../include/cxx/game_struct/d2_cel_file/d2_cel_file_wrapper.hpp"

#include <windows.h>
#include <vector>

#include "../../../../include/cxx/game_struct/d2_cel_context/d2_cel_context_api.hpp"
#include "../../../../include/cxx/game_func/d2gfx/d2gfx_draw_cel_context.hpp"
#include "d2_cel_file_impl.hpp"

namespace d2 {

CelFile_Wrapper::CelFile_Wrapper(
    CelFile* ptr
) noexcept :
    ptr_(ptr) {
}

CelFile_Wrapper::CelFile_Wrapper(
    const CelFile_Wrapper& other
) noexcept = default;

CelFile_Wrapper::CelFile_Wrapper(
    CelFile_Wrapper&& other
) noexcept = default;

CelFile_Wrapper::~CelFile_Wrapper() noexcept = default;

CelFile_Wrapper& CelFile_Wrapper::operator=(
    const CelFile_Wrapper& other
) noexcept = default;

CelFile_Wrapper& CelFile_Wrapper::operator=(
    CelFile_Wrapper&& other
) noexcept = default;

CelFile_Wrapper::operator CelFile_View() const noexcept {
  return CelFile_View(this->Get());
}

CelFile* CelFile_Wrapper::Get() noexcept {
  const auto* const_this = this;

  return const_cast<CelFile*>(const_this->Get());
}

const CelFile* CelFile_Wrapper::Get() const noexcept {
  return this->ptr_;
}

bool CelFile_Wrapper::DrawFrame(
    int position_x,
    int position_y,
    unsigned int direction,
    unsigned int frame
) {
  DrawCelFileFrameOptions draw_cel_file_frame_options;
  draw_cel_file_frame_options.color = mapi::RGBA32BitColor();
  draw_cel_file_frame_options.draw_effect = DrawEffect::kNone;
  draw_cel_file_frame_options.position_x_behavior =
      DrawPositionXBehavior::kLeft;
  draw_cel_file_frame_options.position_y_behavior =
      DrawPositionYBehavior::kBottom;

  return this->DrawFrame(
      position_x,
      position_y,
      direction,
      frame,
      draw_cel_file_frame_options
  );
}

bool CelFile_Wrapper::DrawFrame(
    int position_x,
    int position_y,
    unsigned int direction,
    unsigned int frame,
    const DrawCelFileFrameOptions& frame_options
) {
  CelContext_API cel_context(this->Get(), direction, frame);

  return cel_context.DrawFrame(
      position_x,
      position_y,
      frame_options
  );
}

bool CelFile_Wrapper::DrawAllFrames(
    int position_x,
    int position_y,
    unsigned int columns,
    unsigned int rows
) {
  DrawAllCelFileFramesOptions all_frames_options;
  all_frames_options.color = mapi::RGBA32BitColor();
  all_frames_options.draw_effect = DrawEffect::kNone;
  all_frames_options.cel_file_direction = 0;
  all_frames_options.position_x_behavior = DrawPositionXBehavior::kLeft;
  all_frames_options.position_y_behavior = DrawPositionYBehavior::kBottom;

  return this->DrawAllFrames(
      position_x,
      position_y,
      columns,
      rows,
      all_frames_options
  );
}

bool CelFile_Wrapper::DrawAllFrames(
    int position_x,
    int position_y,
    unsigned int columns,
    unsigned int rows,
    const DrawAllCelFileFramesOptions& all_frames_options
) {
  // Look into the related Cels and determine the width and height.
  std::vector<Cel_View> cel_views;
  for (unsigned int current_row = 0; current_row < rows; current_row += 1) {
    for (unsigned int current_column = 0; current_column < columns; current_column += 1) {
      unsigned int current_frame = current_column + (current_row * columns);

      cel_views.push_back(this->GetCel(all_frames_options.cel_file_direction, current_frame));
    }
  }

  int cels_total_width = 0;
  for (unsigned int current_column = 0; current_column < columns; current_column += 1) {
    cels_total_width += cel_views.at(current_column).GetWidth();
  }

  int cels_total_height = 0;
  for (unsigned int current_row = 0; current_row < rows; current_row += 1) {
    cels_total_height += cel_views.at(current_row * columns).GetHeight();
  }

  // Determine starting positions.
  int starting_position_x = position_x;
  switch (all_frames_options.position_x_behavior) {
    case DrawPositionXBehavior::kLeft: {
      break;
    }

    case DrawPositionXBehavior::kCenter: {
      starting_position_x -= cels_total_width / 2;
      break;
    }

    case DrawPositionXBehavior::kRight: {
      starting_position_x -= cels_total_width;
      break;
    }

    default: {
      MessageBoxW(
          nullptr,
          L"Invalid value used for DrawPositionXBehavior.",
          L"Invalid Value",
          MB_OK | MB_ICONERROR
      );

      throw std::exception("Invalid value used for DrawPositionXBehavior.");
    }
  }

  int starting_position_y = position_y;
  switch (all_frames_options.position_y_behavior) {
    case DrawPositionYBehavior::kTop: {
      break;
    }

    case DrawPositionYBehavior::kCenter: {
      starting_position_y -= (cels_total_height / 2);
      break;
    }

    case DrawPositionYBehavior::kBottom: {
      starting_position_y -= cels_total_height;
      break;
    }

    default: {
      MessageBoxW(
          nullptr,
          L"Invalid value used for DrawPositionYBehavior.",
          L"Invalid Value",
          MB_OK | MB_ICONERROR
      );

      throw std::exception("Invalid value used for DrawPositionYBehavior.");
    }
  }

  // Draw the cels, from left to right, top to bottom.
  DrawCelFileFrameOptions frame_options;
  frame_options.color = all_frames_options.color;
  frame_options.draw_effect = all_frames_options.draw_effect;
  frame_options.position_x_behavior = DrawPositionXBehavior::kLeft;
  frame_options.position_y_behavior = DrawPositionYBehavior::kTop;

  int current_covered_height = 0;
  for (unsigned int current_row = 0; current_row < rows; current_row += 1) {
    int current_covered_width = 0;

    for (unsigned int current_column = 0; current_column < columns; current_column += 1) {
      unsigned int current_frame = current_column + (current_row * columns);

      CelContext_API cel_context(this->Get(), all_frames_options.cel_file_direction, current_frame);
      cel_context.DrawFrame(
          starting_position_x + current_covered_width,
          starting_position_y + current_covered_height,
          frame_options
      );

      current_covered_width += cel_views.at(current_frame).GetWidth();
    }

    current_covered_height += cel_views.at(current_row * columns).GetHeight();
  }
}

Cel* CelFile_Wrapper::GetCel(unsigned int direction, unsigned int frame) {
  CelContext_API cel_context(this->Get(), direction, frame);

  return cel_context.GetCel();
}

unsigned int CelFile_Wrapper::GetVersion() const noexcept {
  CelFile_View view(*this);

  return view.GetVersion();
}

void CelFile_Wrapper::SetVersion(unsigned int value) noexcept {
  auto actual_cel_file = reinterpret_cast<CelFile_1_00*>(this->Get());

  actual_cel_file->version = value;
}

unsigned int CelFile_Wrapper::GetNumDirections() const noexcept {
  CelFile_View view(*this);

  return view.GetNumDirections();
}

void CelFile_Wrapper::SetNumDirections(unsigned int value) noexcept {
  auto actual_cel_file = reinterpret_cast<CelFile_1_00*>(this->Get());

  actual_cel_file->num_directions = value;
}

unsigned int CelFile_Wrapper::GetNumFrames() const noexcept {
  CelFile_View view(*this);

  return view.GetNumFrames();
}

void CelFile_Wrapper::SetNumFrames(unsigned int value) noexcept {
  auto actual_cel_file = reinterpret_cast<CelFile_1_00*>(this->Get());

  actual_cel_file->num_frames = value;
}

} // namespace d2
