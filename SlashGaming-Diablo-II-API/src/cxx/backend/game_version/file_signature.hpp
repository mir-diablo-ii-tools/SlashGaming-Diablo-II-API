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

#ifndef SGMAPI_CXX_BACKEND_GAME_VERSION_FILE_SIGNATURE_HPP_
#define SGMAPI_CXX_BACKEND_GAME_VERSION_FILE_SIGNATURE_HPP_

#include <cstddef>
#include <cstdint>
#include <compare>
#include <filesystem>
#include <vector>

namespace mapi {

class FileSignature {
 public:
  FileSignature(
      const std::filesystem::path& file_path,
      std::ptrdiff_t offset,
      const std::vector<std::uint8_t>& signature
  );

  FileSignature(
      std::filesystem::path&& file_path,
      std::ptrdiff_t offset,
      std::vector<std::uint8_t>&& signature
  ) noexcept;

  FileSignature(
      const std::filesystem::path& file_path,
      std::ptrdiff_t offset,
      std::size_t count
  );

  FileSignature(
      std::filesystem::path&& file_path,
      std::ptrdiff_t offset,
      std::size_t count
  );

  FileSignature(const FileSignature& file_signature);
  FileSignature(FileSignature&& file_signature) noexcept;

  ~FileSignature();

  FileSignature& operator=(const FileSignature& file_signature);
  FileSignature& operator=(FileSignature&& file_signature) noexcept;

  friend bool operator==(
      const FileSignature& lhs,
      const FileSignature& rhs
  ) = default;

  friend std::strong_ordering operator<=>(
      const FileSignature& lhs,
      const FileSignature& rhs
  ) = default;

  FileSignature ReadActual() const;

 private:
  std::filesystem::path file_path_;
  std::ptrdiff_t offset_;
  std::vector<std::uint8_t> signature_;
};

} // namespace mapi

#endif // SGMAPI_CXX_BACKEND_GAME_VERSION_FILE_SIGNATURE_HPP_
