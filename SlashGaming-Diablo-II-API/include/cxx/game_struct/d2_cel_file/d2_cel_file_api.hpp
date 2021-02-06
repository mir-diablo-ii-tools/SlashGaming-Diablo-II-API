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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_FILE_D2_CEL_FILE_API_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_FILE_D2_CEL_FILE_API_HPP_

#include <string_view>
#include <variant>

#include "../../helper/d2_draw_options.hpp"
#include "../d2_cel/d2_cel_struct.hpp"
#include "d2_cel_file_struct.hpp"
#include "d2_cel_file_view.hpp"
#include "d2_cel_file_wrapper.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT CelFile_Api {
 public:
  CelFile_Api();
  CelFile_Api(
      std::string_view cel_file_path,
      bool is_dcc_else_dc6
  );

  CelFile_Api(const CelFile_Api& other) = delete;
  CelFile_Api(CelFile_Api&& other) noexcept;

  ~CelFile_Api();

  CelFile_Api& operator=(const CelFile_Api& other) = delete;
  CelFile_Api& operator=(CelFile_Api&& other) noexcept;

  operator CelFile_View() const noexcept;

  const CelFile* Get() const noexcept;

  void Close();

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

  Cel_View GetCel(unsigned int direction, unsigned int frame);

  bool IsOpen() const;

  void Open(
    std::string_view cel_file_path,
    bool is_dcc_else_dc6
  );

  unsigned int GetVersion() const noexcept;
  unsigned int GetNumDirections() const noexcept;
  unsigned int GetNumFrames() const noexcept;

 private:
  using ApiVariant = std::variant<CelFile_1_00*>;

  ApiVariant cel_file_;
  bool is_open_;

  static ApiVariant CreateVariant(
      std::string_view cel_file_path,
      bool is_dcc_else_dc6
  );

  /* Underscore Suffix to resolve overload issue. */
  CelFile* Get_() noexcept;
};

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_FILE_D2_CEL_FILE_API_HPP_
