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

#include "file_signature.hpp"

#include <fstream>
#include <utility>

namespace mapi {

FileSignature::FileSignature(
    const std::filesystem::path& file_path,
    std::ptrdiff_t offset,
    const std::vector<std::uint8_t>& signature
) : FileSignature(
        std::filesystem::path(file_path),
        offset,
        std::vector(signature)
    ) {
}

FileSignature::FileSignature(
    std::filesystem::path&& file_path,
    std::ptrdiff_t offset,
    std::vector<std::uint8_t>&& signature
) noexcept
  : file_path_(std::move(file_path)),
    offset_(offset),
    signature_(std::move(signature)) {
}

FileSignature::FileSignature(
    const std::filesystem::path& file_path,
    std::ptrdiff_t offset,
    std::size_t count
) : FileSignature(
        std::filesystem::path(file_path),
        offset,
        count
    ) {
}

FileSignature::FileSignature(
    std::filesystem::path&& file_path,
    std::ptrdiff_t offset,
    std::size_t count
) : file_path_(std::move(file_path)),
    offset_(offset) {
  std::ifstream file_stream(
      this->file_path_,
      std::ios_base::in | std::ios_base::binary
  );

  file_stream.seekg(this->offset_);

  std::vector<char> raw_signature(count);
  file_stream.read(raw_signature.data(), count);

  this->signature_ = std::vector<std::uint8_t>(
      raw_signature.cbegin(),
      raw_signature.cend()
  );
}

FileSignature::FileSignature(
    const FileSignature& file_signature
) = default;

FileSignature::FileSignature(
    FileSignature&& file_signature
) noexcept = default;

FileSignature::~FileSignature() = default;

FileSignature& FileSignature::operator=(
    const FileSignature& file_signature
) = default;

FileSignature& FileSignature::operator=(
    FileSignature&& file_signature
) noexcept = default;

FileSignature FileSignature::ReadActual() const {
  return FileSignature(
      this->file_path_,
      this->offset_,
      this->signature_.size()
  );
}

} // namespace mapi
