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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_FILE_D2_CEL_FILE_VIEW_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_FILE_D2_CEL_FILE_VIEW_HPP_

#include <cstddef>
#include <variant>

#include "d2_cel_file_struct.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

class DLLEXPORT CelFile_View {
 public:
  using ViewVariant = std::variant<const CelFile_1_00*>;

  CelFile_View() = delete;

  CelFile_View(const CelFile* cel_file) noexcept;

  constexpr explicit CelFile_View(ViewVariant cel_file) noexcept
      : cel_file_(::std::move(cel_file)) {
  }

  constexpr CelFile_View(
      const CelFile_View& other
  ) noexcept = default;

  constexpr CelFile_View(
      CelFile_View&& other
  ) noexcept = default;

  ~CelFile_View() noexcept = default;

  constexpr CelFile_View& operator=(
      const CelFile_View& other
  ) noexcept = default;

  constexpr CelFile_View& operator=(
      CelFile_View&& other
  ) noexcept = default;

  constexpr CelFile_View operator[](
      std::size_t index
  ) const noexcept {
    return ::std::visit(
        [index](const auto& actual_cel_file) {
          return CelFile_View(
              &actual_cel_file[index]
          );
        },
        this->cel_file_
    );
  }

  constexpr const CelFile* Get() const noexcept {
    return std::visit(
        [](const auto& actual_cel_file) {
          return reinterpret_cast<const CelFile*>(actual_cel_file);
        },
        this->cel_file_
    );
  }

  constexpr unsigned int GetVersion() const noexcept {
    return std::visit(
        [](const auto& actual_cel_file) {
          return actual_cel_file->version;
        },
        this->cel_file_
    );
  }

  constexpr unsigned int GetNumDirections() const noexcept {
    return std::visit(
        [](const auto& actual_cel_file) {
          return actual_cel_file->num_directions;
        },
        this->cel_file_
    );
  }

  constexpr unsigned int GetNumFrames() const noexcept {
    return std::visit(
        [](const auto& actual_cel_file) {
          return actual_cel_file->num_frames;
        },
        this->cel_file_
    );
  }

 private:
  ViewVariant cel_file_;

  static ViewVariant CreateVariant(const CelFile* cel_file);
};

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_FILE_D2_CEL_FILE_VIEW_HPP_
