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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_FILE_D2_CEL_FILE_WRAPPER_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_FILE_D2_CEL_FILE_WRAPPER_HPP_

#include <cstddef>
#include <variant>

#include "../../helper/d2_draw_options.hpp"
#include "../d2_cel/d2_cel_struct.hpp"
#include "d2_cel_file_struct.hpp"
#include "d2_cel_file_view.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT CelFile_Wrapper {
 public:
  CelFile_Wrapper() = delete;
  CelFile_Wrapper(CelFile* cel_file) noexcept;

  CelFile_Wrapper(const CelFile_Wrapper& other) noexcept;
  CelFile_Wrapper(CelFile_Wrapper&& other) noexcept;

  ~CelFile_Wrapper() noexcept;

  CelFile_Wrapper& operator=(const CelFile_Wrapper& other) noexcept;
  CelFile_Wrapper& operator=(CelFile_Wrapper&& other) noexcept;

  CelFile_View operator[](std::size_t index) const noexcept;
  CelFile_Wrapper operator[](std::size_t index) noexcept;

  operator CelFile_View() const noexcept;

  CelFile* Get() noexcept;
  const CelFile* Get() const noexcept;

  bool DrawFrame(
      int position_x,
      int position_y,
      unsigned int direction,
      unsigned int frame
  );

  bool DrawFrame(
      int position_x,
      int position_y,
      unsigned int direction,
      unsigned int frame,
      const DrawCelFileFrameOptions& frame_options
  );

  bool DrawAllFrames(
      int position_x,
      int position_y,
      unsigned int columns,
      unsigned int rows
  );

  bool DrawAllFrames(
      int position_x,
      int position_y,
      unsigned int columns,
      unsigned int rows,
      const DrawAllCelFileFramesOptions& all_frames_options
  );

  Cel* GetCel(unsigned int direction, unsigned int frame);

  unsigned int GetVersion() const noexcept;
  void SetVersion(unsigned int version) noexcept;

  unsigned int GetNumDirections() const noexcept;
  void SetNumDirections(unsigned int num_directions) noexcept;

  unsigned int GetNumFrames() const noexcept;
  void SetNumFrames(unsigned int num_frames) noexcept;

 private:
  using WrapperVariant = std::variant<CelFile_1_00*>;

  WrapperVariant cel_file_;
};

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_FILE_D2_CEL_FILE_WRAPPER_HPP_
