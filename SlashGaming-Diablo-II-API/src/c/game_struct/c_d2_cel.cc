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

#include "../../../include/c/game_struct/d2_cel.h"

#include "../../../include/cxx/game_struct/d2_cel.hpp"

int D2_Cel_GetHeight(const D2_Cel* cel) {
  auto actual_cel = reinterpret_cast<const d2::Cel*>(cel);

  d2::Cel_ConstWrapper cel_wrapper(actual_cel);
  return cel_wrapper.GetHeight();
}

void D2_Cel_SetHeight(D2_Cel* cel, int value) {
  auto actual_cel = reinterpret_cast<d2::Cel*>(cel);

  d2::Cel_Wrapper cel_wrapper(actual_cel);
  return cel_wrapper.SetHeight(value);
}

int D2_Cel_GetOffsetX(const D2_Cel* cel) {
  auto actual_cel = reinterpret_cast<const d2::Cel*>(cel);

  d2::Cel_ConstWrapper cel_wrapper(actual_cel);
  return cel_wrapper.GetOffsetX();
}

void D2_Cel_SetOffsetX(D2_Cel* cel, int value) {
  auto actual_cel = reinterpret_cast<d2::Cel*>(cel);

  d2::Cel_Wrapper cel_wrapper(actual_cel);
  return cel_wrapper.SetOffsetX(value);
}

int D2_Cel_GetOffsetY(const D2_Cel* cel) {
  auto actual_cel = reinterpret_cast<const d2::Cel*>(cel);

  d2::Cel_ConstWrapper cel_wrapper(actual_cel);
  return cel_wrapper.GetOffsetY();
}

void D2_Cel_SetOffsetY(D2_Cel* cel, int value) {
  auto actual_cel = reinterpret_cast<d2::Cel*>(cel);

  d2::Cel_Wrapper cel_wrapper(actual_cel);
  return cel_wrapper.SetOffsetY(value);
}

int D2_Cel_GetWidth(const D2_Cel* cel) {
  auto actual_cel = reinterpret_cast<const d2::Cel*>(cel);

  d2::Cel_ConstWrapper cel_wrapper(actual_cel);
  return cel_wrapper.GetWidth();
}

void D2_Cel_SetWidth(D2_Cel* cel, int value) {
  auto actual_cel = reinterpret_cast<d2::Cel*>(cel);

  d2::Cel_Wrapper cel_wrapper(actual_cel);
  return cel_wrapper.SetWidth(value);
}