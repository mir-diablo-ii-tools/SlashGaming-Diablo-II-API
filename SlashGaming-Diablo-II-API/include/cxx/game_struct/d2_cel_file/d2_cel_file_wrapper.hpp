/**
 * SlashGaming Diablo II Modding API for C++
 * Copyright (C) 2018-2022  Mir Drualga
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
#include "../d2_cel/d2_cel_wrapper.hpp"
#include "d2_cel_file_struct.hpp"
#include "d2_cel_file_view.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT CelFile_Wrapper {
 public:
  using WrapperVariant = std::variant<CelFile_1_00*>;

  CelFile_Wrapper() = delete;

  CelFile_Wrapper(CelFile* cel_file) noexcept;

  constexpr explicit CelFile_Wrapper(WrapperVariant cel_file) noexcept
      : cel_file_(::std::move(cel_file)) {
  }

  constexpr CelFile_Wrapper(
      const CelFile_Wrapper& other
  ) noexcept = default;

  constexpr CelFile_Wrapper(
      CelFile_Wrapper&& other
  ) noexcept = default;

  ~CelFile_Wrapper() noexcept = default;

  constexpr CelFile_Wrapper& operator=(
      const CelFile_Wrapper& other
  ) noexcept = default;

  constexpr CelFile_Wrapper& operator=(
      CelFile_Wrapper&& other
  ) noexcept = default;

  constexpr CelFile_View operator[](
      std::size_t index
  ) const noexcept {
    CelFile_View view(this->Get());

    return view[index];
  }

  constexpr CelFile_Wrapper operator[](
      std::size_t index
  ) noexcept {
    return ::std::visit(
        [index](auto& actual_cel_file) {
          return CelFile_Wrapper(
              &actual_cel_file[index]
          );
        },
        this->cel_file_
    );
  }

  constexpr operator CelFile_View() const noexcept {
    return ::std::visit(
        [](const auto& actual_cel_file) {
          return CelFile_View(actual_cel_file);
        },
        this->cel_file_
    );
  }

  constexpr CelFile* Get() noexcept {
    const auto* const_this = this;

    return const_cast<CelFile*>(const_this->Get());
  }

  constexpr const CelFile* Get() const noexcept {
    return std::visit(
        [](const auto& actual_cel_file) {
          return reinterpret_cast<const CelFile*>(
              actual_cel_file
          );
        },
        this->cel_file_
    );
  }

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

  Cel_Wrapper GetCel(unsigned int direction, unsigned int frame);

  constexpr unsigned int GetVersion() const noexcept {
    CelFile_View view(*this);

    return view.GetVersion();
  }

  constexpr void SetVersion(unsigned int version) noexcept {
    std::visit(
        [version](auto& actual_cel_file) {
          actual_cel_file->version = version;
        },
        this->cel_file_
    );
  }

  constexpr unsigned int GetNumDirections() const noexcept {
    CelFile_View view(*this);

    return view.GetNumDirections();
  }

  constexpr void SetNumDirections(unsigned int num_directions) noexcept {
    std::visit(
        [num_directions](auto& actual_cel_file) {
          actual_cel_file->num_directions = num_directions;
        },
        this->cel_file_
    );
  }

  constexpr unsigned int GetNumFrames() const noexcept {
    CelFile_View view(*this);

    return view.GetNumFrames();
  }

  constexpr void SetNumFrames(unsigned int num_frames) noexcept {
    std::visit(
        [num_frames](auto& actual_cel_file) {
          actual_cel_file->num_frames = num_frames;
        },
        this->cel_file_
    );
  }

 private:
  WrapperVariant cel_file_;

  static WrapperVariant CreateVariant(CelFile* cel_file);
};

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_FILE_D2_CEL_FILE_WRAPPER_HPP_
