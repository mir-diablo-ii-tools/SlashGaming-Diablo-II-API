/**
 * SlashGaming Diablo II Modding API
 * Copyright (C) 2018  SlashGaming Community
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
 *  the game, provided that the game or its libraries do not link to this
 *  Program.
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any Glide wrapper (or a modified version of that library),
 *  containing parts not covered by a compatible license, provided that the
 *  wrapper does not link to this Program, the licensors of this Program
 *  grant you additional permission to convey the resulting work.
 */

#ifndef SGD2MAPI_GAME_VERSION_H_
#define SGD2MAPI_GAME_VERSION_H_

#if defined(SGD2MAPI_DLLEXPORT)
#define DLLEXPORT __declspec(dllexport)
#elif defined(SGD2MAPI_DLLIMPORT)
#define DLLEXPORT __declspec(dllimport)
#else
#define DLLEXPORT
#endif

namespace sgd2mapi::version {

/**
 * The Diablo II game versions supported and recognized.
 */
enum class GameVersion : int {
  k1_00, k1_01, k1_02, k1_03, k1_04, k1_04B, k1_04C = k1_04B, k1_05,
  k1_05B, k1_06, k1_06B, k1_07, k1_08, k1_09, k1_09B, k1_09C, k1_09D, k1_09E,
  k1_10, k1_10Beta, k1_10SBeta, k1_11, k1_11B, k1_12A, k1_13ABeta, k1_13C,
  k1_13D,

  kClassic1_14A, kClassic1_14B, kClassic1_14C, kClassic1_14D,
  kLod1_14A, kLod1_14B, kLod1_14C, kLod1_14D,
};

/**
 * A singleton class that detects the game version on runtime and stores this
 * information.
 */
class RunningGameVersion {
public:
  RunningGameVersion(const RunningGameVersion&) = delete;
  void operator=(const RunningGameVersion&) = delete;

  /**
   * Returns the singleton instance of RunningGameVersion.
   */
  static const RunningGameVersion& GetInstance() noexcept;

  /**
   * Returns whether the Diablo II game version is at least 1.14.
   */
  constexpr bool IsGameVersionAtLeast1_14(
      enum GameVersion game_version) const noexcept {
    return !(game_version >= GameVersion::k1_00
             && game_version <= GameVersion::k1_13D);
  }

  /**
   * Returns the running game's version.
   */
  constexpr GameVersion game_version() const noexcept {
    return game_version_;
  }

private:
  enum GameVersion game_version_;

  RunningGameVersion() noexcept;
};

} // namespace sgd2mapi::version

#undef DLLEXPORT
#endif // SGD2MAPI_GAME_VERSION_H_
