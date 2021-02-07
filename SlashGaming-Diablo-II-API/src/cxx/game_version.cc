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

#include "../../include/cxx/game_version.hpp"

#include <windows.h>
#include <cstdint>
#include <filesystem>
#include <map>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>

#include <fmt/format.h>
#include "../../include/cxx/game_address.hpp"
#include "../../include/cxx/game_executable.hpp"
#include "../wide_macro.h"
#include "backend/encoding.hpp"
#include "backend/error_handling.hpp"
#include "backend/game_version/file_signature.hpp"
#include "backend/game_version/file_version.hpp"

namespace d2 {
namespace {

static const std::unordered_map<
    GameVersion,
    std::map<mapi::FileSignature, GameVersion>
>& GetFileSignaturesByGameVersions() {
  static const std::unordered_map<
      GameVersion,
      std::map<mapi::FileSignature, GameVersion>
  > kFileSignaturesByGameVersions = {
      {
          GameVersion::k1_01,
          {
              {
                  mapi::FileSignature(
                      L"storm.dll",
                      0xF0,
                      { 0x79, 0xBD, 0x20, 0x39 }
                  ),
                  GameVersion::kBeta1_02
              },
              {
                  mapi::FileSignature(
                      L"storm.dll",
                      0xF0,
                      { 0xB7, 0x70, 0xD0, 0x38 }
                  ),
                  GameVersion::kBeta1_02StressTest
              },
              {
                  mapi::FileSignature(
                      L"storm.dll",
                      0xF0,
                      { 0xBC, 0xC7, 0x2E, 0x39 }
                  ),
                  GameVersion::k1_00
              },
              {
                  mapi::FileSignature(
                      L"storm.dll",
                      0xF0,
                      { 0x25, 0x47, 0x52, 0x39 }
                  ),
                  GameVersion::k1_01
              },
          }
      },
      {
          GameVersion::k1_06B,
          {
              {
                  mapi::FileSignature(
                      L"storm.dll",
                      0xF0,
                      { 0x43, 0x0C, 0xD6, 0x3A }
                  ),
                  GameVersion::k1_06
              },
              {
                  mapi::FileSignature(
                      L"storm.dll",
                      0xF0,
                      { 0xC1, 0x7B, 0xE0, 0x3A }
                  ),
                  GameVersion::k1_06B
              },
          }
      },
      {
          GameVersion::k1_07,
          {
              {
                  mapi::FileSignature(
                      L"storm.dll",
                      0xF0,
                      { 0x32, 0xA6, 0xDC, 0x3A }
                  ),
                  GameVersion::k1_07Beta
              },
              {
                  mapi::FileSignature(
                      L"storm.dll",
                      0xF0,
                      { 0xB5, 0x92, 0xF5, 0x3A }
                  ),
                  GameVersion::k1_07
              },
          }
      },
      {
          GameVersion::kLod1_14A,
          {
              {
                  mapi::FileSignature(
                      mapi::game_executable::GetPath(),
                      0x120,
                      { 0x38, 0x81, 0xD4, 0x56 }
                  ),
                  GameVersion::kClassic1_14A
              },
              {
                  mapi::FileSignature(
                      mapi::game_executable::GetPath(),
                      0x120,
                      { 0x34, 0x81, 0xD4, 0x56 }
                  ),
                  GameVersion::kLod1_14A
              },
          }
      },
      {
          GameVersion::kLod1_14B,
          {
              {
                  mapi::FileSignature(
                      mapi::game_executable::GetPath(),
                      0x110,
                      { 0xAE, 0x78, 0xFC, 0x56 }
                  ),
                  GameVersion::kClassic1_14B
              },
              {
                  mapi::FileSignature(
                      mapi::game_executable::GetPath(),
                      0x110,
                      { 0xA8, 0x78, 0xFC, 0x56 }
                  ),
                  GameVersion::kLod1_14B
              },
          }
      },
      {
          GameVersion::kLod1_14C,
          {
              {
                  mapi::FileSignature(
                      mapi::game_executable::GetPath(),
                      0x110,
                      { 0x52, 0xDF, 0x2C, 0x57 }
                  ),
                  GameVersion::kClassic1_14C
              },
              {
                  mapi::FileSignature(
                      mapi::game_executable::GetPath(),
                      0x110,
                      { 0x4D, 0xDF, 0x2C, 0x57 }
                  ),
                  GameVersion::kLod1_14C
              },
          }
      },
      {
          GameVersion::kLod1_14D,
          {
              {
                  mapi::FileSignature(
                      mapi::game_executable::GetPath(),
                      0x140,
                      { 0x00, 0x50, 0x0A, 0x00 }
                  ),
                  GameVersion::kClassic1_14D
              },
              {
                  mapi::FileSignature(
                      mapi::game_executable::GetPath(),
                      0x140,
                      { 0x00, 0x60, 0x0A, 0x00 }
                  ),
                  GameVersion::kLod1_14D
              },
          }
      },
  };

  return kFileSignaturesByGameVersions;
}

static GameVersion DetermineGameVersionByGameData(
    GameVersion game_version
) {
  if (!GetFileSignaturesByGameVersions().contains(game_version)) {
    return game_version;
  }

  const std::map<
      mapi::FileSignature,
      GameVersion
  >& file_signature_map = GetFileSignaturesByGameVersions().at(game_version);

  mapi::FileSignature actual_file_signature =
      file_signature_map.cbegin()->first.ReadActual();

  if (!file_signature_map.contains(actual_file_signature)) {
    return game_version;
  }

  return file_signature_map.at(actual_file_signature);
}

static GameVersion DetermineRunningGameVersion() {
  mapi::FileVersion file_version = mapi::FileVersion::ReadFileVersion(
      mapi::game_executable::GetPath()
  );

  // Perform first stage game version detection using the executable file
  // name.
  GameVersion game_version = mapi::FileVersion::GuessGameVersion(file_version);

  // Perform second stage game version detection by checking the bytes of game
  // libraries.
  game_version = DetermineGameVersionByGameData(game_version);

  return game_version;
}

} // namespace

std::u8string_view GetGameVersionName(GameVersion game_version) {
  switch (game_version) {
    case GameVersion::k1_00: {
      return u8"1.00";
    }

    case GameVersion::k1_01: {
      return u8"1.01";
    }

    case GameVersion::k1_02: {
      return u8"1.02";
    }

    case GameVersion::k1_03: {
      return u8"1.03";
    }

    // 1.04B and 1.04C use the same DLLs.
    case GameVersion::k1_04B_C: {
      return u8"1.04B/C";
    }

    case GameVersion::k1_05: {
      return u8"1.05";
    }

    case GameVersion::k1_05B: {
      return u8"1.05B";
    }

    case GameVersion::k1_06: {
      return u8"1.06";
    }

    case GameVersion::k1_06B: {
      return u8"1.06B";
    }

    case GameVersion::k1_07Beta: {
      return u8"1.07 Beta";
    }

    case GameVersion::k1_07: {
      return u8"1.07";
    }

    case GameVersion::k1_08: {
      return u8"1.08";
    }

    case GameVersion::k1_09: {
      return u8"1.09";
    }

    case GameVersion::k1_09B: {
      return u8"1.09B";
    }

    case GameVersion::k1_09D: {
      return u8"1.09D";
    }

    case GameVersion::k1_10Beta: {
      return u8"1.10 Beta";
    }

    case GameVersion::k1_10SBeta: {
      return u8"1.10S Beta";
    }

    case GameVersion::k1_10: {
      return u8"1.10";
    }

    case GameVersion::k1_11: {
      return u8"1.11";
    }

    case GameVersion::k1_11B: {
      return u8"1.11B";
    }

    case GameVersion::k1_12A: {
      return u8"1.12A";
    }

    case GameVersion::k1_13ABeta: {
      return u8"1.13A Beta";
    }

    case GameVersion::k1_13C: {
      return u8"1.13C";
    }

    case GameVersion::k1_13D: {
      return u8"1.13D";
    }

    case GameVersion::kClassic1_14A: {
      return u8"Classic 1.14A";
    }

    case GameVersion::kLod1_14A: {
      return u8"LoD 1.14A";
    }

    case GameVersion::kClassic1_14B: {
      return u8"Classic 1.14B";
    }

    case GameVersion::kLod1_14B: {
      return u8"LoD 1.14B";
    }

    case GameVersion::kClassic1_14C: {
      return u8"Classic 1.14C";
    }

    case GameVersion::kLod1_14C: {
      return u8"LoD 1.14C";
    }

    case GameVersion::kClassic1_14D: {
      return u8"Classic 1.14D";
    }

    case GameVersion::kLod1_14D: {
      return u8"LoD 1.14D";
    }

    default: {
      constexpr std::wstring_view kErrorFormatMessage =
          L"Could not determine the game version name from the game "
              L"version ID: {}.";

      std::wstring full_message = fmt::format(
          kErrorFormatMessage,
          static_cast<int>(game_version)
      );

      mapi::ExitOnGeneralFailure(
          full_message,
          L"Failed to Determine Game Version ID",
          __FILEW__,
          __LINE__
      );
    }
  }
}

GameVersion GetRunningGameVersionId() {
  static GameVersion running_game_version_id = DetermineRunningGameVersion();

  return running_game_version_id;
}

std::u8string_view GetRunningGameVersionName() {
  static std::u8string_view running_game_version_name = GetGameVersionName(
      GetRunningGameVersionId()
  );
  return running_game_version_name;
}

bool IsGameVersionAtLeast1_14(GameVersion game_version) {
  return !(game_version >= GameVersion::kBeta1_02
      && game_version <= GameVersion::k1_13D);
}

bool IsRunningGameVersionAtLeast1_14() {
  return IsGameVersionAtLeast1_14(GetRunningGameVersionId());
}

} // namespace d2
