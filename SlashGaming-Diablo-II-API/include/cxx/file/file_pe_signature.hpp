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

#ifndef SGMAPI_CXX_FILE_FILE_PE_SIGNATURE_HPP_
#define SGMAPI_CXX_FILE_FILE_PE_SIGNATURE_HPP_

#include <cstddef>
#include <cstdint>

#include <array>
#include <compare>
#include <fstream>
#include <utility>

#include "../../dllexport_define.inc"

namespace mapi {

template <::std::size_t Count>
class FilePeSignature {
 public:
  using SignatureType = ::std::array<::std::uint8_t, Count>;

  static constexpr ::std::size_t kSignatureCount = Count;

  static constexpr ::std::size_t kSignatureSize =
      kSignatureCount * sizeof(SignatureType::value_type);

  constexpr FilePeSignature() noexcept
      : signature_() {
  }

  explicit constexpr FilePeSignature(SignatureType signature) noexcept
      : signature_(::std::move(signature)) {
  }

  friend constexpr ::std::strong_ordering operator<=>(
      const FilePeSignature& lhs,
      const FilePeSignature& rhs
  ) noexcept = default;

  static FilePeSignature ReadFile(const wchar_t* path) {
    std::basic_ifstream<SignatureType::value_type> file_stream(
        path,
        std::ios_base::in | std::ios_base::binary
    );

    // Grab the pointer to the PE header.
    file_stream.seekg(0x3C);

    ::std::intptr_t pe_header_pointer;
    file_stream.read(
        reinterpret_cast<::std::uint8_t*>(&pe_header_pointer),
        sizeof(pe_header_pointer)
    );

    // Read the PE header.
    file_stream.seekg(pe_header_pointer);

    FilePeSignature file_pe_signature;
    file_stream.read(file_pe_signature.signature_.data(), kSignatureSize);

    return file_pe_signature;
  }

 private:
  SignatureType signature_;
};

} // namespace

#include "../../dllexport_undefine.inc"
#endif // SGMAPI_CXX_FILE_FILE_PE_SIGNATURE_HPP_
