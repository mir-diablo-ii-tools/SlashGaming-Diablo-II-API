/**
 * SlashGaming Diablo II Modding API for C++
 * Copyright (C) 2018-2020  Mir Drualga
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

#ifndef SGMAPI_CXX_GAME_UNDEFINED_HPP_
#define SGMAPI_CXX_GAME_UNDEFINED_HPP_

#include <cstdint>
#include <variant>

#include "../dllexport_define.inc"

namespace mapi {

/**
 * A type used for struct definitions where the type of a pointer
 * member is not yet documented. It is intentionally unimplemented to
 * so that an assignment requires explicit casting.
 */
struct Undefined;

/**
 * A type that occupies a single byte of space. Used to explicitly
 * document that a type is not yet known and that space should be
 * reserved for proper struct alignment.
 */
using UndefinedByte = std::uint8_t;

/**
 * STL DLL interface
 */

DLL_TEMPL_EXTERN template class DLLEXPORT std::variant<UndefinedByte>;
DLL_TEMPL_EXTERN template class DLLEXPORT std::variant<UndefinedByte*>;
DLL_TEMPL_EXTERN template class DLLEXPORT std::variant<Undefined*>;
DLL_TEMPL_EXTERN template class DLLEXPORT std::variant<const Undefined*>;

} // namespace mapi

#include "../dllexport_undefine.inc"
#endif // SGMAPI_CXX_GAME_UNDEFINED_HPP_
