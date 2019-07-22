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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_CONTEXT_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_CONTEXT_HPP_

#include <filesystem>

#include "d2_cel_file.hpp"

#include "../../dllexport_define.inc"

namespace d2 {

struct CelContext;

class DLLEXPORT CelContext_ConstWrapper {
 public:
  CelContext_ConstWrapper() = delete;
  CelContext_ConstWrapper(const CelContext* ptr) noexcept;

  CelContext_ConstWrapper(const CelContext_ConstWrapper& other);
  CelContext_ConstWrapper(CelContext_ConstWrapper&& other) noexcept;

  virtual ~CelContext_ConstWrapper();

  CelContext_ConstWrapper& operator=(const CelContext_ConstWrapper& other);
  CelContext_ConstWrapper& operator=(
      CelContext_ConstWrapper&& other
  ) noexcept;

  const CelContext* Get() const noexcept;

 private:
  const CelContext* ptr_;
};

class DLLEXPORT CelContext_Wrapper : public CelContext_ConstWrapper {
 public:
  CelContext_Wrapper() = delete;
  CelContext_Wrapper(CelContext* ptr) noexcept;

  CelContext_Wrapper(const CelContext_Wrapper& other);
  CelContext_Wrapper(CelContext_Wrapper&& other) noexcept;

  ~CelContext_Wrapper() override;

  CelContext_Wrapper& operator=(const CelContext_Wrapper& other);
  CelContext_Wrapper& operator=(CelContext_Wrapper&& other) noexcept;

  CelContext* Get() noexcept;

 private:
  CelContext* ptr_;
};

class DLLEXPORT CelContext_API : public CelContext_Wrapper {
 public:
  CelContext_API() = delete;
  CelContext_API(
      CelFile* cel_file,
      int direction,
      int frame
  );

  CelContext_API(const CelContext_API& other);
  CelContext_API(CelContext_API&& other) noexcept;

  ~CelContext_API() override;

  CelContext_API& operator=(const CelContext_API& other);
  CelContext_API& operator=(CelContext_API&& other) noexcept;
};

} // namespace d2

#include "../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_CONTEXT_HPP_
