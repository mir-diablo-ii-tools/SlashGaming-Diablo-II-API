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

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_MPQ_ARCHIVE_HANDLE_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_MPQ_ARCHIVE_HANDLE_HPP_

#include <filesystem>
#include <memory>

#include "d2_mpq_archive.hpp"

#include "../../dllexport_define.inc"

namespace d2 {

struct MPQArchiveHandle;

class DLLEXPORT MPQArchiveHandle_ConstWrapper {
 public:
  MPQArchiveHandle_ConstWrapper() = delete;
  MPQArchiveHandle_ConstWrapper(const MPQArchiveHandle* ptr) noexcept;

  MPQArchiveHandle_ConstWrapper(const MPQArchiveHandle_ConstWrapper& other);
  MPQArchiveHandle_ConstWrapper(
      MPQArchiveHandle_ConstWrapper&& other
  ) noexcept;

  virtual ~MPQArchiveHandle_ConstWrapper();

  MPQArchiveHandle_ConstWrapper& operator=(
      const MPQArchiveHandle_ConstWrapper& other
  );
  MPQArchiveHandle_ConstWrapper& operator=(
      MPQArchiveHandle_ConstWrapper&& other
  ) noexcept;

  operator const MPQArchiveHandle*() const noexcept;

  const MPQArchiveHandle* Get() const noexcept;

  const MPQArchive* GetMPQArchive() const noexcept;
  const char* GetMPQArchivePath() const noexcept;

 private:
  const MPQArchiveHandle* ptr_;
};

class DLLEXPORT MPQArchiveHandle_Wrapper :
    public MPQArchiveHandle_ConstWrapper {
 public:
  MPQArchiveHandle_Wrapper() = delete;
  MPQArchiveHandle_Wrapper(MPQArchiveHandle* ptr) noexcept;

  MPQArchiveHandle_Wrapper(const MPQArchiveHandle_Wrapper& other);
  MPQArchiveHandle_Wrapper(MPQArchiveHandle_Wrapper&& other) noexcept;

  ~MPQArchiveHandle_Wrapper() override;

  MPQArchiveHandle_Wrapper& operator=(const MPQArchiveHandle_Wrapper& other);
  MPQArchiveHandle_Wrapper& operator=(
      MPQArchiveHandle_Wrapper&& other
  ) noexcept;

  operator MPQArchiveHandle*() noexcept;

  MPQArchiveHandle* Get() noexcept;

  MPQArchive* GetMPQArchive() noexcept;
  char* GetMPQArchivePath() noexcept;

 private:
  MPQArchiveHandle* ptr_;
};

class DLLEXPORT MPQArchiveHandle_API : public MPQArchiveHandle_Wrapper {
 public:
  MPQArchiveHandle_API(
      const std::filesystem::path& mpq_archive_path,
      bool is_set_error_on_fail,
      int priority
  );

  MPQArchiveHandle_API(
      const std::filesystem::path& mpq_archive_path,
      bool is_set_error_on_fail,
      void* (*on_fail_callback)(),
      int priority
  );

  MPQArchiveHandle_API(const MPQArchiveHandle_API& other);
  MPQArchiveHandle_API(MPQArchiveHandle_API&& other) noexcept;

  ~MPQArchiveHandle_API() override;

  MPQArchiveHandle_API& operator=(const MPQArchiveHandle_API& other);
  MPQArchiveHandle_API& operator=(MPQArchiveHandle_API&& other) noexcept;
};

} // namespace d2

#include "../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_MPQ_ARCHIVE_HANDLE_HPP_
