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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_FILE_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_FILE_HPP_

#include <filesystem>

#include "../../dllexport_define.inc"

namespace d2 {

struct CelFile;

class DLLEXPORT CelFile_ConstWrapper {
 public:
  CelFile_ConstWrapper() = delete;
  CelFile_ConstWrapper(const CelFile* ptr) noexcept;

  CelFile_ConstWrapper(const CelFile_ConstWrapper& other);
  CelFile_ConstWrapper(CelFile_ConstWrapper&& other) noexcept;

  virtual ~CelFile_ConstWrapper();

  CelFile_ConstWrapper& operator=(
      const CelFile_ConstWrapper& other
  );
  CelFile_ConstWrapper& operator=(
      CelFile_ConstWrapper&& other
  ) noexcept;

  const CelFile* Get() const noexcept;

 private:
  const CelFile* ptr_;
};

class DLLEXPORT CelFile_Wrapper : public CelFile_ConstWrapper {
 public:
  CelFile_Wrapper() = delete;
  CelFile_Wrapper(CelFile* ptr) noexcept;

  CelFile_Wrapper(const CelFile_Wrapper& other);
  CelFile_Wrapper(CelFile_Wrapper&& other) noexcept;

  ~CelFile_Wrapper() override;

  CelFile_Wrapper& operator=(
      const CelFile_Wrapper& other
  );
  CelFile_Wrapper& operator=(
      CelFile_Wrapper&& other
  ) noexcept;

  CelFile* Get() noexcept;

 private:
  CelFile* ptr_;
};

class DLLEXPORT CelFile_API : public CelFile_Wrapper {
 public:
  CelFile_API() = delete;
  CelFile_API(const std::filesystem::path& cel_file_path);

  CelFile_API(const CelFile_ConstWrapper& other);
  CelFile_API(CelFile_ConstWrapper&& other) noexcept;

  ~CelFile_API() override;

  CelFile_API& operator=(
      const CelFile_API& other
  );
  CelFile_API& operator=(
      CelFile_API&& other
  ) noexcept;
};

} // namespace d2

#include "../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_FILE_HPP_
