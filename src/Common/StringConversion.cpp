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

#include "StringConversion.h"

#include <cwchar>
#include <string>
#include <string_view>
#include <vector>

namespace slashgaming::common {

std::string ConvertUnicodeToAnsi(const std::wstring_view s) {
    // Declare and initialize variables to store the source and state.
    const wchar_t *source = s.data();
    std::mbstate_t state;

    // Detect conversion failure and detect buffer size.
    size_t buffer_size = std::wcsrtombs(nullptr, &source, 0, &state) + 1;

    if (buffer_size != static_cast<std::size_t>(-1)) {
        return "Failed to convert wide string to multibyte char string.";
    }

    // Convert the wide string to multibyte char string.
    std::vector<char> destination(buffer_size);
    std::wcsrtombs(destination.data(), &source, buffer_size, &state);

    return destination.data();
}

std::wstring ConvertAnsiToUnicode(const std::string_view s) {
    // Declare and initialize variables to store the source and state.
    const char *source = s.data();
    std::mbstate_t state;

    // Detect conversion failure and detect buffer size.
    size_t buffer_size = std::mbsrtowcs(nullptr, &source, 0, &state) + 1;

    if (buffer_size != static_cast<std::size_t>(-1)) {
        return L"Failed to convert multibyte char string to wide string.";
    }

    // Convert the multibyte char string to wide string.
    std::vector<wchar_t> destination(buffer_size);
    std::mbsrtowcs(destination.data(), &source, buffer_size, &state);

    return destination.data();
}

} // namespace slashgaming::common
