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

#ifndef SGD2MAPI_GAME_VERSION_H_
#define SGD2MAPI_GAME_VERSION_H_

#include <stdbool.h>

#ifdef __cplusplus
#include <string_view>
#endif // __cplusplus

#if defined(SGD2MAPI_DLLEXPORT)
#define DLLEXPORT __declspec(dllexport)
#elif defined(SGD2MAPI_DLLIMPORT)
#define DLLEXPORT __declspec(dllimport)
#else
#define DLLEXPORT
#endif

#ifdef __cplusplus
namespace sgd2mapi {

/**
 * The Diablo II game versions supported and recognized.
 */
enum class GameVersion;

/**
 * Returns the identifier of the game version associated with the specified
 * string.
 */
DLLEXPORT enum GameVersion GetGameVersionId(std::string_view game_version_name)
    noexcept;

/**
 * Returns a view to the string associated with the specified game version.
 */
DLLEXPORT std::string_view GetGameVersionName(enum GameVersion game_version)
    noexcept;

/**
 * Returns the identifier of the running game version.
 */
DLLEXPORT enum GameVersion GetRunningGameVersionId() noexcept;

/**
 * Returns a view to the string associated with the running game version.
 */
DLLEXPORT std::string_view GetRunningGameVersionName() noexcept;

/**
 * Returns whether the specified game version is at least 1.14.
 */
DLLEXPORT bool IsGameVersionAtLeast1_14(enum GameVersion game_version)
    noexcept;

/**
 * Returns whether the running game version is at least 1.14.
 */
DLLEXPORT bool IsRunningGameVersionAtLeast1_14() noexcept;

} // namespace sgd2mapi
#endif // __cplusplus

/**
 * C Interface
 */

/**
 * The Diablo II game versions supported and recognized. Disabled if compiling
 * as C++ code.
 */
enum SGD2MAPI_GameVersion
#ifdef __cplusplus
{};

enum class sgd2mapi::GameVersion
#endif // __cplusplus
{
  k1_00, k1_01, k1_02, k1_03, k1_04, k1_04B, k1_04C = k1_04B, k1_05,
  k1_05B, k1_06, k1_06B, k1_07Beta, k1_07, k1_08, k1_09, k1_09B, k1_09C,
  k1_09D, k1_09E, k1_10, k1_10Beta, k1_10SBeta, k1_11, k1_11B, k1_12A,
  k1_13ABeta, k1_13C, k1_13D,

  kClassic1_14A, kLod1_14A, kClassic1_14B, kLod1_14B, kClassic1_14C, kLod1_14C,
  kClassic1_14D, kLod1_14D,
};

#if !defined(__cplusplus) || defined(SGD2MAPI_DLLEXPORT)

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * Returns a view to the string associated with the specified game version.
 */
DLLEXPORT const char* SGD2MAPI_GetGameVersionName(
    enum SGD2MAPI_GameVersion game_version
);

/**
 * Returns the identifier of the game version associated with the specified
 * string.
 */
DLLEXPORT enum SGD2MAPI_GameVersion SGD2MAPI_GetGameVersionId(
    const char* game_version_name
);

/**
 * Returns the identifier of the running game version.
 */
DLLEXPORT enum SGD2MAPI_GameVersion SGD2MAPI_GetRunningGameVersionId();

/**
 * Returns a view to the string associated with the running game version.
 */
DLLEXPORT const char* SGD2MAPI_GetRunningGameVersionName();

/**
 * Returns whether the Diablo II game version is at least 1.14.
 */
DLLEXPORT bool SGD2MAPI_IsGameVersionAtLeast1_14(
    enum SGD2MAPI_GameVersion game_version
);

/**
 * Returns whether the running game version is at least 1.14.
 */
DLLEXPORT bool SGD2MAPI_IsRunningGameVersionAtLeast1_14();

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !defined(__cplusplus) || defined(SGD2MAPI_DLLEXPORT)

#undef DLLEXPORT
#endif // SGD2MAPI_GAME_VERSION_H_
