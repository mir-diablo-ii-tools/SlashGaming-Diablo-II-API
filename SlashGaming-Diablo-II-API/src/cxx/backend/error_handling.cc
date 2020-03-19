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

#include "error_handling.hpp"

#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <cwchar>
#include <memory>

namespace mapi {
namespace {

static constexpr std::wstring_view kFunctionFailErrorFormat =
    L"File: %s \n"
    L"Line: %d \n"
    L"\n"
    L"The function %s failed with error code %X.";

static constexpr std::wstring_view kGeneralFailErrorFormat =
    L"File: %s \n"
    L"Line: %d \n"
    L"\n"
    L"%s";

} // namespace

void ExitOnGeneralFailure(
    std::wstring_view message,
    std::wstring_view caption,
    std::wstring_view file_name,
    int line
) {
#ifndef NDEBUG
  std::size_t full_message_size = kGeneralFailErrorFormat.length()
      + message.length()
      + file_name.length()
      + static_cast<int>(std::log10(line));

  std::unique_ptr full_message = std::make_unique<wchar_t[]>(
      full_message_size
  );

  std::swprintf(
      full_message.get(),
      full_message_size,
      kGeneralFailErrorFormat.data(),
      file_name.data(),
      line,
      message.data()
  );

  MessageBoxW(
      NULL,
      full_message.get(),
      caption.data(),
      MB_OK | MB_ICONERROR
  );
#endif // NDEBUG

  std::exit(EXIT_FAILURE);
}

void ExitOnWindowsFunctionFailureWithLastError(
    std::wstring_view function_name,
    DWORD last_error,
    std::wstring_view file_name,
    int line
){
#ifndef NDEBUG
  // Build the message string.
  std::size_t full_message_size = kGeneralFailErrorFormat.length()
      + function_name.length()
      + file_name.length()
      + static_cast<std::size_t>(std::log10(line))
      + static_cast<std::size_t>(std::log10(last_error));

  std::unique_ptr full_message = std::make_unique<wchar_t[]>(
      full_message_size
  );

  std::swprintf(
      full_message.get(),
      full_message_size,
      kFunctionFailErrorFormat.data(),
      file_name.data(),
      line,
      function_name.data(),
      last_error
  );

  // Build the caption string.
  std::size_t full_caption_size = std::wstring_view(L"%s Failed").length()
      + function_name.length();

  std::unique_ptr full_caption = std::make_unique<wchar_t[]>(
      full_caption_size
  );

  std::swprintf(
      full_caption.get(),
      full_caption_size,
      L"%s Failed",
      function_name.data()
  );

  MessageBoxW(
      NULL,
      full_message.get(),
      full_caption.get(),
      MB_OK | MB_ICONERROR
  );
#endif // NDEBUG

  std::exit(EXIT_FAILURE);
}

} // namespace mapi
