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
 *  it with any Glide wrapper (or a modified version of that library),
 *  containing parts not covered by a compatible license, the licensors of
 *  this Program grant you additional permission to convey the resulting
 *  work.
 */

#ifndef SGD2MAPI_CXX_GAME_ADDRESS_HPP_
#define SGD2MAPI_CXX_GAME_ADDRESS_HPP_

#include <cstdint>
#include <filesystem>

#include "default_game_library.hpp"

#include "../dllexport_define.inc"

namespace sgd2mapi {

class DLLEXPORT GameAddress {
 public:
  std::intptr_t raw_address(void) const noexcept;

  /**
   * Returns a new instance of GameDecoratedNameAddress using a string encoded
   * in 7-bit ASCII.
   */
  static GameAddress FromDecoratedName(
      enum DefaultLibrary default_library,
      std::string_view decorated_name
  );

  /**
   * Returns a new instance of GameDecoratedNameAddress using a string encoded
   * in 7-bit ASCII.
   */
  static GameAddress FromDecoratedName(
      const std::filesystem::path& library_path,
      std::string_view decorated_name
  );

  /**
   * Returns a game address that uses an offset value to specify a location in
   * game memory.
   */
  static GameAddress FromOffset(
      enum DefaultLibrary default_library,
      std::intptr_t offset
  );

  /**
   * Returns a game address that uses an offset value to specify a location in
   * game memory.
   */
  static GameAddress FromOffset(
      const std::filesystem::path& library_path,
      std::intptr_t offset
  );

  /**
   * Returns a game address that uses an ordinal value to specify a location
   * in game memory.
   */
  static GameAddress FromOrdinal(
      enum DefaultLibrary default_library,
      std::intptr_t ordinal
  );

  /**
   * Returns a game address that uses an ordinal value to specify a location
   * in game memory.
   */
  static GameAddress FromOrdinal(
      const std::filesystem::path& library_path,
      std::intptr_t ordinal
  );

 private:
  explicit GameAddress(std::intptr_t raw_address);

  std::intptr_t raw_address_;
};

} // namespace sgd2mapi

#include "../dllexport_undefine.inc"

#endif // SGD2MAPI_CXX_GAME_ADDRESS_HPP_
