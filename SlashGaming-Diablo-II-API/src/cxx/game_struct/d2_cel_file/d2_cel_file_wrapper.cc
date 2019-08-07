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

#include "../../../../include/cxx/game_struct/d2_cel_file.hpp"

#include "../../../../include/cxx/game_struct/d2_cel_context.hpp"
#include "../../../../include/cxx/game_func/d2gfx/d2gfx_draw_cel_context.hpp"
#include "d2_cel_file_impl.hpp"

namespace d2 {

CelFile_Wrapper::CelFile_Wrapper(
    CelFile* ptr
) noexcept :
    CelFile_ConstWrapper(ptr),
    ptr_(ptr) {
}

CelFile_Wrapper::CelFile_Wrapper(
    const CelFile_Wrapper& other
) = default;

CelFile_Wrapper::CelFile_Wrapper(
    CelFile_Wrapper&& other
) noexcept = default;

CelFile_Wrapper::~CelFile_Wrapper() = default;

CelFile_Wrapper& CelFile_Wrapper::operator=(
    const CelFile_Wrapper& other
) = default;

CelFile_Wrapper& CelFile_Wrapper::operator=(
    CelFile_Wrapper&& other
) noexcept = default;

CelFile* CelFile_Wrapper::Get() noexcept {
  return this->ptr_;
}

const CelFile* CelFile_Wrapper::Get() const noexcept {
  return CelFile_ConstWrapper::Get();
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
  all_frames_options.direction_order =
      DrawAllFramesDirectionOrder::kHorizontalThenVertical;
  all_frames_options.cel_file_direction = 0;
  all_frames_options.horizontal_direction =
      DrawHorizontalDirection::kLeftToRight;
  all_frames_options.vertical_direction =
      DrawVerticalDirection::kTopToBottom;

  DrawCelFileFrameOptions& frame_options = all_frames_options.frame_options;
  frame_options.color = mapi::RGBA32BitColor();
  frame_options.draw_effect = DrawEffect::kNone;
  frame_options.position_x_behavior = DrawPositionXBehavior::kLeft;
  frame_options.position_y_behavior = DrawPositionYBehavior::kBottom;

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
  switch (all_frames_options.direction_order) {
    case DrawAllFramesDirectionOrder::kHorizontalThenVertical: {
      return DrawHorizontalThenVertical(
          position_x,
          position_y,
          columns,
          rows,
          all_frames_options
      );
    }

    case DrawAllFramesDirectionOrder::kVerticalThenHorizontal: {
      return DrawVerticalThenHorizontal(
          position_x,
          position_y,
          columns,
          rows,
          all_frames_options
      );
    }
  }
}

Cel* CelFile_Wrapper::GetCel(unsigned int direction, unsigned int frame) {
  CelContext_API cel_context(this->Get(), direction, frame);
  return cel_context.GetCel();
}

void CelFile_Wrapper::SetVersion(unsigned int value) noexcept {
  auto actual_cel_file = reinterpret_cast<CelFile_1_00*>(this->Get());

  actual_cel_file->version = value;
}

void CelFile_Wrapper::SetNumDirections(unsigned int value) noexcept {
  auto actual_cel_file = reinterpret_cast<CelFile_1_00*>(this->Get());

  actual_cel_file->num_directions = value;
}

void CelFile_Wrapper::SetNumFrames(unsigned int value) noexcept {
  auto actual_cel_file = reinterpret_cast<CelFile_1_00*>(this->Get());

  actual_cel_file->num_frames = value;
}

bool CelFile_Wrapper::DrawHorizontalThenVertical(
    int position_x,
    int position_y,
    unsigned int columns,
    unsigned int rows,
    const DrawAllCelFileFramesOptions& all_frames_options
) {
  bool final_result;

  int direction_factor;
  switch (all_frames_options.vertical_direction) {
    case DrawVerticalDirection::kTopToBottom: {
      direction_factor = 1;
      break;
    }

    case DrawVerticalDirection::kBottomToTop: {
      direction_factor = -1;
      break;
    }
  }

  int frame_position_y = position_y;
  for (int i = 0; i < rows; i += 1) {
    unsigned int current_frame = i * columns;

    final_result &= this->DrawRowOfFrames(
        position_x,
        frame_position_y,
        columns,
        current_frame,
        all_frames_options.cel_file_direction,
        all_frames_options.frame_options,
        all_frames_options.horizontal_direction
    );

    Cel_ConstWrapper current_cel(
        this->GetCel(all_frames_options.cel_file_direction, current_frame)
    );
    frame_position_y += (current_cel.GetHeight() * direction_factor);
  }

  return final_result;
}

bool CelFile_Wrapper::DrawVerticalThenHorizontal(
    int position_x,
    int position_y,
    unsigned int columns,
    unsigned int rows,
    const DrawAllCelFileFramesOptions& all_frames_options
) {
  bool final_result;

  int direction_factor;
  switch (all_frames_options.horizontal_direction) {
    case DrawHorizontalDirection::kLeftToRight: {
      direction_factor = 1;
      break;
    }

    case DrawHorizontalDirection::kRightToLeft: {
      direction_factor = -1;
      break;
    }
  }

  int frame_position_x = position_x;
  for (int i = 0; i < columns; i += 1) {
    unsigned int current_frame = i * rows;

    final_result &= this->DrawColumnOfFrames(
        frame_position_x,
        position_y,
        rows,
        current_frame,
        all_frames_options.cel_file_direction,
        all_frames_options.frame_options,
        all_frames_options.vertical_direction
    );

    Cel_ConstWrapper current_cel(
        this->GetCel(all_frames_options.cel_file_direction, current_frame)
    );
    frame_position_x += (current_cel.GetWidth() * direction_factor);
  }

  return final_result;
}

bool CelFile_Wrapper::DrawRowOfFrames(
    int position_x,
    int position_y,
    unsigned int columns,
    unsigned int first_frame,
    unsigned int direction,
    const DrawCelFileFrameOptions& frame_options,
    DrawHorizontalDirection horizontal_direction
) {
  bool final_result;

  int direction_factor;
  switch (horizontal_direction) {
    case DrawHorizontalDirection::kLeftToRight: {
      direction_factor = 1;
      break;
    }

    case DrawHorizontalDirection::kRightToLeft: {
      direction_factor = -1;
      break;
    }
  }

  int frame_position_x = position_x;
  for (int i = 0; i < columns; i += 1) {
    unsigned int current_frame = i + first_frame;

    final_result &= this->DrawFrame(
        frame_position_x,
        position_y,
        direction,
        current_frame,
        frame_options
    );

    Cel_ConstWrapper current_cel(this->GetCel(direction, current_frame));
    frame_position_x += (current_cel.GetWidth() * direction_factor);
  }

  return final_result;
}

bool CelFile_Wrapper::DrawColumnOfFrames(
    int position_x,
    int position_y,
    unsigned int rows,
    unsigned int first_frame,
    unsigned int direction,
    const DrawCelFileFrameOptions& frame_options,
    DrawVerticalDirection vertical_direction
) {
  bool final_result;

  int direction_factor;
  switch (vertical_direction) {
    case DrawVerticalDirection::kTopToBottom: {
      direction_factor = 1;
      break;
    }

    case DrawVerticalDirection::kBottomToTop: {
      direction_factor = -1;
      break;
    }
  }

  int frame_position_y = position_y;
  for (int i = 0; i < rows; i += 1) {
    unsigned int current_frame = i + first_frame;

    final_result &= this->DrawFrame(
        position_x,
        frame_position_y,
        direction,
        current_frame,
        frame_options
    );

    Cel_ConstWrapper current_cel(this->GetCel(direction, current_frame));
    frame_position_y += (current_cel.GetHeight() * direction_factor);
  }

  return final_result;
}

} // namespace d2
