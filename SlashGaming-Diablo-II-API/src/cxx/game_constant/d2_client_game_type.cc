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

#include "../../../include/cxx/game_constant/d2_client_game_type.hpp"

#include <unordered_map>

#include "../../../include/cxx/game_version.hpp"

namespace d2 {
namespace {

static const std::unordered_map<ClientGameType, ClientGameType_1_00> kTo1_00 = {
    { ClientGameType::kSinglePlayer, ClientGameType_1_00::kSinglePlayer },
    { ClientGameType::kBattleNetJoin, ClientGameType_1_00::kBattleNetJoin },
    { ClientGameType::kOpenBattleNetHostOrLanHost, ClientGameType_1_00::kOpenBattleNetHostOrLanHost },
    { ClientGameType::kOpenBattleNetJoinOrLanJoin, ClientGameType_1_00::kOpenBattleNetJoinOrLanJoin },
};

static const std::unordered_map<ClientGameType_1_00, ClientGameType> kFrom1_00 = {
    { ClientGameType_1_00::kSinglePlayer, ClientGameType::kSinglePlayer },
    { ClientGameType_1_00::kBattleNetJoin, ClientGameType::kBattleNetJoin },
    { ClientGameType_1_00::kOpenBattleNetHostOrLanHost, ClientGameType::kOpenBattleNetHostOrLanHost },
    { ClientGameType_1_00::kOpenBattleNetJoinOrLanJoin, ClientGameType::kOpenBattleNetJoinOrLanJoin },
};

static const std::unordered_map<ClientGameType, ClientGameType_1_07> kTo1_07 = {
    { ClientGameType::kSinglePlayer, ClientGameType_1_07::kSinglePlayer },
    { ClientGameType::kBattleNetJoin, ClientGameType_1_07::kBattleNetJoin },
    { ClientGameType::kOpenBattleNetHost, ClientGameType_1_07::kOpenBattleNetHost },
    { ClientGameType::kOpenBattleNetJoin, ClientGameType_1_07::kOpenBattleNetJoin },
    { ClientGameType::kLanHost, ClientGameType_1_07::kLanHost },
    { ClientGameType::kLanJoin, ClientGameType_1_07::kLanJoin },
};

static const std::unordered_map<ClientGameType_1_07, ClientGameType> kFrom1_07 = {
    { ClientGameType_1_07::kSinglePlayer, ClientGameType::kSinglePlayer },
    { ClientGameType_1_07::kBattleNetJoin, ClientGameType::kBattleNetJoin },
    { ClientGameType_1_07::kOpenBattleNetHost, ClientGameType::kOpenBattleNetHost },
    { ClientGameType_1_07::kOpenBattleNetJoin, ClientGameType::kOpenBattleNetJoin },
    { ClientGameType_1_07::kLanHost, ClientGameType::kLanHost },
    { ClientGameType_1_07::kLanJoin, ClientGameType::kLanJoin },
};

} // namespace

int ToGameValue(ClientGameType api_value) {
  GameVersion running_game_version = GetRunningGameVersionId();

  if (running_game_version < GameVersion::k1_09D) {
    return static_cast<int>(ToGameValue_1_00(api_value));
  } else {
    return static_cast<int>(ToGameValue_1_07(api_value));
  }
}

ClientGameType_1_00 ToGameValue_1_00(ClientGameType api_value) {
  return kTo1_00.at(api_value);
}

ClientGameType_1_07 ToGameValue_1_07(ClientGameType api_value) {
  return kTo1_07.at(api_value);
}

ClientGameType ToApiValue(int game_value) {
  GameVersion running_game_version = GetRunningGameVersionId();

  if (running_game_version < GameVersion::k1_06B) {
    return ToApiValue_1_00(static_cast<ClientGameType_1_00>(game_value));
  } else {
    return ToApiValue_1_07(static_cast<ClientGameType_1_07>(game_value));
  }
}

ClientGameType ToApiValue_1_00(ClientGameType_1_00 game_value) {
  return kFrom1_00.at(game_value);
}

ClientGameType ToApiValue_1_07(ClientGameType_1_07 game_value) {
  return kFrom1_07.at(game_value);
}

} // namespace d2
