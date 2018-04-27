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

#ifndef SGD2MAPI_COMMON_STRINGCONVERSION_H_
#define SGD2MAPI_COMMON_STRINGCONVERSION_H_

#include <string>
#include <string_view>

namespace slashgaming::common {

/**
 * Converts a wide string into a multibyte char string and returns it.
 */
std::string ConvertUnicodeToAnsi(const std::wstring_view s);

/**
 * Converts a multibyte char string into a wide string and returns it.
 */
std::wstring ConvertAnsiToUnicode(const std::string_view s);

} // namespace slashgaming::common

#endif // SGD2MAPI_COMMON_STRINGCONVERSION_H_
