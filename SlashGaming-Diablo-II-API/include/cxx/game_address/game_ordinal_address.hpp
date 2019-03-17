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

#ifndef SGD2MAPI_CXX_GAME_ADDRESS_GAME_ORDINAL_ADDRESS_HPP_
#define SGD2MAPI_CXX_GAME_ADDRESS_GAME_ORDINAL_ADDRESS_HPP_

#include <cstdint>
#include <filesystem>

#include "../default_game_library.hpp"
#include "game_address_base.hpp"

#include "../../dllexport_define.inc"

namespace sgd2mapi {

class DLLEXPORT GameOrdinalAddress : public GameAddressBase {
 public:
  GameOrdinalAddress(
      enum DefaultLibrary default_library,
      int ordinal
  );

  GameOrdinalAddress(
      const std::filesystem::path& default_library_path,
      int ordinal
  );

  ~GameOrdinalAddress(void) noexcept override;
};

}

#include "../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_ADDRESS_GAME_ORDINAL_ADDRESS_HPP_
