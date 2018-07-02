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
 *  If you modify this Program, or any covered work, by linking or combining it
 *  with Diablo II (or a modified version of that library), containing parts
 *  covered by the terms of Blizzard End User License Agreement, the licensors
 *  of this Program grant you additional permission to convey the resulting
 *  work.
 *
 *  If you modify this Program, or any covered work, by declaring a custom
 *  version of an existing Diablo II data structure with members ordered
 *  differently from any official version of the game, then such declarations
 *  are exempt from the terms of GNU Affero General Public License version 3
 *  section 6.
 */

#include "StringConversion.h"

#include <cwchar>
#include <memory>
#include <string>
#include <string_view>

#include "ErrorReport.h"

namespace slashgaming::common {

std::string ConvertUnicodeToAnsi(const std::wstring_view s) {
    // Declare and initialize variables to store the source and state.
    const wchar_t *source = s.data();
    std::mbstate_t state;

    // Detect conversion failure and detect buffer size.
    size_t buffer_size = std::wcsrtombs(nullptr, &source, 0, &state) + 1;

    AssertOrTerminateWithMessage((buffer_size != static_cast<std::size_t>(-1)),
            "Error",
            "Failed to convert wide string to multibyte char string.");

    // Convert the wide string to multibyte char string.
    auto destination = std::make_unique<char[]>(buffer_size);
    std::wcsrtombs(destination.get(), &source, buffer_size, &state);

    return destination.get();
}

std::wstring ConvertAnsiToUnicode(const std::string_view s) {
    // Declare and initialize variables to store the source and state.
    const char *source = s.data();
    std::mbstate_t state;

    // Detect conversion failure and detect buffer size.
    size_t buffer_size = std::mbsrtowcs(nullptr, &source, 0, &state) + 1;

    AssertOrTerminateWithMessage((buffer_size != static_cast<std::size_t>(-1)),
            "Error",
            "Failed to convert multibyte char string to wide string.");

    // Convert the multibyte char string to wide string.
    auto destination = std::make_unique<wchar_t[]>(buffer_size);
    std::mbsrtowcs(destination.get(), &source, buffer_size, &state);

    return destination.get();
}

} // namespace slashgaming::common
