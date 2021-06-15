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

#ifndef SGD2MAPI_CXX_GAME_VERSION_HPP_
#define SGD2MAPI_CXX_GAME_VERSION_HPP_

#include "../dllexport_define.inc"

namespace d2 {

/**
 * The Diablo II game versions supported and recognized.
 */
enum class GameVersion {
  kBeta1_02, kBeta1_02StressTest,

  k1_00, k1_01, k1_02, k1_03, k1_04B_C, k1_05, k1_05B, k1_06, k1_06B,
  k1_07Beta, k1_07, k1_08, k1_09, k1_09B, k1_09D, k1_10Beta, k1_10SBeta,
  k1_10, k1_11, k1_11B, k1_12A, k1_13ABeta, k1_13C, k1_13D,

  kClassic1_14A, kLod1_14A, kClassic1_14B, kLod1_14B, kClassic1_14C, kLod1_14C,
  kClassic1_14D, kLod1_14D,
};

namespace game_version {

/**
 * Returns the UTF-8 encoded null-terminated string associated with
 * the specified game version.
 */
DLLEXPORT const char* GetName(GameVersion game_version);

/**
 * Returns the UTF-8 encoded null-terminated string associated with
 * the specified game version.
 */
DLLEXPORT const char8_t* GetNameUtf8(GameVersion game_version);

/**
 * Returns the identifier of the running game version.
 */
DLLEXPORT GameVersion GetRunning();

/**
 * Returns the UTF-8 encoded null-terminated string associated with the
 * running game version.
 */
DLLEXPORT const char* GetRunningName();

/**
 * Returns the UTF-8 encoded null-terminated string associated with the
 * running game version.
 */
DLLEXPORT const char8_t* GetRunningNameUtf8();

/**
 * Returns whether the specified game version is at least 1.14.
 */
DLLEXPORT bool IsAtLeast1_14(GameVersion game_version);

/**
 * Returns whether the running game version is at least 1.14.
 */
DLLEXPORT bool IsRunningAtLeast1_14();

} // namespace game_version

} // namespace d2

#include "../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_VERSION_HPP_
