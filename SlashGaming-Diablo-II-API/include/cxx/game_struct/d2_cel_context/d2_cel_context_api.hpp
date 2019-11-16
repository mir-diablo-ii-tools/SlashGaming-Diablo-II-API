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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_CONTEXT_API_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_CONTEXT_API_HPP_

#include <memory>
#include <variant>

#include "../d2_cel.hpp"
#include "d2_cel_context_wrapper.hpp"
#include "../d2_cel_file.hpp"
#include "../../game_constant/d2_draw_effect.hpp"
#include "../../../../include/cxx/helper/d2_draw_options.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

struct CelContext;
struct CelContext_1_00;
struct CelContext_1_12A;
struct CelContext_1_13C;

class DLLEXPORT CelContext_API {
 public:
  CelContext_API() = delete;
  CelContext_API(
      CelFile* cel_file,
      unsigned int direction,
      unsigned int frame
  );

  CelContext_API(const CelContext_API& other);
  CelContext_API(CelContext_API&& other) noexcept;

  ~CelContext_API();

  CelContext_API& operator=(const CelContext_API& other);
  CelContext_API& operator=(CelContext_API&& other) noexcept;

  operator CelContext_View() const noexcept;
  operator CelContext_Wrapper() noexcept;

  CelContext* Get() noexcept;
  const CelContext* Get() const noexcept;

  bool DrawFrame(int position_x, int position_y);

  bool DrawFrame(
      int position_x,
      int position_y,
      const DrawCelFileFrameOptions& frame_options
  );

  Cel* GetCel();

  CelFile* GetCelFile() noexcept;
  const CelFile* GetCelFile() const noexcept;
  unsigned int GetDirection() const noexcept;
  unsigned int GetFrame() const noexcept;

  void SetCelFile(CelFile* cel_file) noexcept;
  void SetDirection(unsigned int direction) noexcept;
  void SetFrame(unsigned int frame) noexcept;

 private:
  std::variant<
      std::unique_ptr<CelContext_1_00[]>,
      std::unique_ptr<CelContext_1_12A[]>,
      std::unique_ptr<CelContext_1_13C[]>
  > cel_context_;
};

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_CONTEXT_API_HPP_
