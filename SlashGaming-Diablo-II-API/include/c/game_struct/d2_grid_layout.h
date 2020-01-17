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

#ifndef SGD2MAPI_C_GAME_STRUCT_D2_GRID_LAYOUT_H_
#define SGD2MAPI_C_GAME_STRUCT_D2_GRID_LAYOUT_H_

#include <stddef.h>
#include <stdint.h>

#include "d2_positional_rectangle.h"

#include "../../dllexport_define.inc"

struct D2_GridLayout;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

DLLEXPORT struct D2_GridLayout* D2_GridLayout_CreateWithLayout(
    int_least8_t num_columns,
    int_least8_t num_rows,
    const struct D2_PositionalRectangle* position,
    int_least8_t width,
    int_least8_t height
);

DLLEXPORT void D2_GridLayout_Destroy(
    struct D2_GridLayout* grid_layout
);

DLLEXPORT uint_least8_t D2_GridLayout_GetNumColumns(
    const struct D2_GridLayout* grid_layout
);

DLLEXPORT void D2_GridLayout_SetNumColumns(
    struct D2_GridLayout* grid_layout,
    uint_least8_t value
);

DLLEXPORT uint_least8_t D2_GridLayout_GetNumRows(
    const struct D2_GridLayout* grid_layout
);

DLLEXPORT void D2_GridLayout_SetNumRows(
    struct D2_GridLayout* grid_layout,
    uint_least8_t value
);

DLLEXPORT struct D2_PositionalRectangle* D2_GridLayout_GetPosition(
    struct D2_GridLayout* grid_layout
);

DLLEXPORT const struct D2_PositionalRectangle* D2_GridLayout_GetConstPosition(
    const struct D2_GridLayout* grid_layout
);

DLLEXPORT uint_least8_t D2_GridLayout_GetWidth(
    const struct D2_GridLayout* grid_layout
);

DLLEXPORT void D2_GridLayout_SetWidth(
    struct D2_GridLayout* grid_layout,
    uint_least8_t value
);

DLLEXPORT uint_least8_t D2_GridLayout_GetHeight(
    const struct D2_GridLayout* grid_layout
);

DLLEXPORT void D2_GridLayout_SetHeight(
    struct D2_GridLayout* grid_layout,
    uint_least8_t value
);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#include "../../dllexport_undefine.inc"
#endif // SGD2MAPI_C_GAME_STRUCT_D2_GRID_LAYOUT_H_
