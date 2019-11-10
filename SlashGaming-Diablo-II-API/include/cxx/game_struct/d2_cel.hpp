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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_HPP_

#include "../../dllexport_define.inc"

namespace d2 {

struct Cel;

class DLLEXPORT Cel_View {
 public:
  Cel_View() = delete;
  Cel_View(const Cel* ptr) noexcept;

  Cel_View(const Cel_View& other);
  Cel_View(Cel_View&& other) noexcept;

  virtual ~Cel_View();

  Cel_View& operator=(const Cel_View& other);
  Cel_View& operator=(Cel_View&& other) noexcept;

  const Cel* Get() const noexcept;

  int GetHeight() const noexcept;
  int GetOffsetX() const noexcept;
  int GetOffsetY() const noexcept;
  int GetWidth() const noexcept;

 private:
  const Cel* ptr_;
};

class DLLEXPORT Cel_Wrapper : public Cel_View {
 public:
  Cel_Wrapper() = delete;
  Cel_Wrapper(Cel* ptr) noexcept;

  Cel_Wrapper(const Cel_Wrapper& other);
  Cel_Wrapper(Cel_Wrapper&& other) noexcept;

  ~Cel_Wrapper() override;

  Cel_Wrapper& operator=(
      const Cel_Wrapper& other
  );
  Cel_Wrapper& operator=(Cel_Wrapper&& other) noexcept;

  Cel* Get() noexcept;
  const Cel* Get() const noexcept;

  void SetHeight(int value) noexcept;
  void SetOffsetX(int value) noexcept;
  void SetOffsetY(int value) noexcept;
  void SetWidth(int value) noexcept;

 private:
  Cel* ptr_;
};

class DLLEXPORT Cel_API : public Cel_Wrapper {
 public:
  Cel_API() = delete;

  Cel_API(const Cel_API& other);
  Cel_API(Cel_API&& other) noexcept;

  ~Cel_API() override;

  Cel_API& operator=(const Cel_API& other);
  Cel_API& operator=(Cel_API&& other) noexcept;
};

} // namespace d2

#include "../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_HPP_
