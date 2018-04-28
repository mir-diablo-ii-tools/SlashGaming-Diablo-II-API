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
 */

#include "D2ClientVar.h"

#include <cstdint>
#include <unordered_map>

#include "../GameLibrary.h"
#include "../Offset.h"
#include "../Version.h"

#define ESCAPE_PARENTHESIS(...) { __VA_ARGS__ }

#define VARPTR(name, type, offset_map) \
type* D2Client_##name() { \
    static const Offset offset(GameLibraries::kD2Client, \
        ESCAPE_PARENTHESIS offset_map); \
    static type* var_ptr = reinterpret_cast<type*>(offset.CalculateAddress()); \
    return var_ptr; \
}

namespace slashgaming::diabloii::var {

VARPTR(ScreenSizeX, int, (
    { GameVersion::kLod1_13C, 0xDBC48 },
    { GameVersion::kLod1_13D, 0xF7034 },
));

VARPTR(ScreenSizeY, int, (
    { GameVersion::kLod1_13C, 0xDBC4C },
    { GameVersion::kLod1_13D, 0xF7038 },
));

} // namespace slashgaming::diabloii::var

#undef VARPTR

#undef ESCAPE_PARENTHESIS
