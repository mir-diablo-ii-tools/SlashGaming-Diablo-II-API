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

#include "../../../include/c/game_struct/d2_cel_context.h"

#include "../../../include/cxx/game_struct/d2_cel_context.hpp"
#include "../../cxx/game_struct/d2_cel_context/d2_cel_context_impl.hpp"

D2_CelContext* D2_CelContext_Create(
    D2_CelFile* cel_file,
    unsigned int direction,
    unsigned int frame
) {
  auto actual_cel_file = reinterpret_cast<d2::CelFile*>(cel_file);

  auto actual_result = d2::CreateCelContext(
      actual_cel_file,
      direction,
      frame
  );

  return reinterpret_cast<D2_CelContext*>(actual_result);
}

void D2_CelContext_Destroy(D2_CelContext* cel_context) {
  auto actual_cel_context = reinterpret_cast<d2::CelContext*>(cel_context);
  d2::DestroyCelContext(actual_cel_context);
}

D2_CelFile* D2_CelContext_GetCelFile(D2_CelContext* cel_context) {
  auto actual_cel_context = reinterpret_cast<d2::CelContext*>(
      cel_context
  );

  d2::CelContext_Wrapper cel_context_wrapper(actual_cel_context);

  return reinterpret_cast<D2_CelFile*>(
      cel_context_wrapper.GetCelFile()
  );
}

const D2_CelFile* D2_CelContext_GetConstCelFile(
    const D2_CelContext* cel_context
) {
  auto actual_cel_context = reinterpret_cast<const d2::CelContext*>(
      cel_context
  );

  d2::CelContext_ConstWrapper cel_context_wrapper(actual_cel_context);

  return reinterpret_cast<const D2_CelFile*>(
      cel_context_wrapper.GetCelFile()
  );
}

void D2_CelContext_SetCelFile(
    D2_CelContext* cel_context,
    D2_CelFile* cel_file
) {
  auto actual_cel_context = reinterpret_cast<d2::CelContext*>(cel_context);
  auto actual_cel_file = reinterpret_cast<d2::CelFile*>(cel_file);

  d2::CelContext_Wrapper cel_context_wrapper(actual_cel_context);
  cel_context_wrapper.SetCelFile(actual_cel_file);
}

unsigned int D2_CelContext_GetDirection(const D2_CelContext* cel_context) {
  auto actual_cel_context = reinterpret_cast<const d2::CelContext*>(
      cel_context
  );

  d2::CelContext_ConstWrapper cel_context_wrapper(actual_cel_context);

  return cel_context_wrapper.GetDirection();
}

void D2_CelContext_SetDirection(
    D2_CelContext* cel_context,
    unsigned int direction
) {
  auto actual_cel_context = reinterpret_cast<d2::CelContext*>(
      cel_context
  );

  d2::CelContext_Wrapper cel_context_wrapper(actual_cel_context);
  cel_context_wrapper.SetDirection(direction);
}

unsigned int D2_CelContext_GetFrame(const D2_CelContext* cel_context) {
  auto actual_cel_context = reinterpret_cast<const d2::CelContext*>(
      cel_context
  );

  d2::CelContext_ConstWrapper cel_context_wrapper(actual_cel_context);

  return cel_context_wrapper.GetFrame();
}

void D2_CelContext_SetFrame(D2_CelContext* cel_context, unsigned int frame) {
  auto actual_cel_context = reinterpret_cast<d2::CelContext*>(
      cel_context
  );

  d2::CelContext_Wrapper cel_context_wrapper(actual_cel_context);
  cel_context_wrapper.SetFrame(frame);
}
