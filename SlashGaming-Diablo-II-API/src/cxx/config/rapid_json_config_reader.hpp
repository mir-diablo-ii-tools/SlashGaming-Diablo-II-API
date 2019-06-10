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

#ifndef SGD2MAPI_CXX_CONFIG_RAPID_JSON_CONFIG_READER_HPP_
#define SGD2MAPI_CXX_CONFIG_RAPID_JSON_CONFIG_READER_HPP_

#include <rapidjson/document.h>

#include "generic_json_config_reader.hpp"

namespace mapi {

using RapidJsonConfigReader = GenericConfigReader<rapidjson::Document,  rapidjson::Value>;

template <>
template <typename ...Args>
bool RapidJsonConfigReader::GetBool(
    bool default_value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      default_value
  );

  if (!entry.IsBool()) {
    entry.SetBool(default_value);
  }

  return entry.GetBool();
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetBool(
    bool value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      value
  );

  entry.SetBool(value);
}

template <>
template <typename ...Args>
int RapidJsonConfigReader::GetInt(
    int default_value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      default_value
  );

  if (!entry.IsInt()) {
    entry.SetInt(default_value);
  }

  return entry.GetInt();
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetInt(
    int value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      value
  );

  entry.SetInt(value);
}

template <>
template <typename ...Args>
std::int32_t RapidJsonConfigReader::GetInt32(
    std::int32_t default_value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      default_value
  );

  if (!entry.IsInt()) {
    entry.SetInt(default_value);
  }

  return entry.GetInt();
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetInt32(
    std::int32_t value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      value
  );

  entry.SetInt(value);
}

template <>
template <typename ...Args>
std::int64_t RapidJsonConfigReader::GetInt64(
    std::int64_t default_value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      default_value
  );

  if (!entry.IsInt64()) {
    entry.SetInt64(default_value);
  }

  return entry.GetInt64();
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetInt64(
    std::int64_t value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      value
  );

  entry.SetInt64(value);
}

template <>
template <typename ...Args>
long RapidJsonConfigReader::GetLong(
    long default_value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      default_value
  );

  if (!entry.IsInt()) {
    entry.SetInt(default_value);
  }

  return entry.GetInt();
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetLong(
    long value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      value
  );

  entry.SetInt(value);
}

template <>
template <typename ...Args>
long long RapidJsonConfigReader::GetLongLong(
    long long default_value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      default_value
  );

  if (!entry.IsInt64()) {
    entry.SetInt64(default_value);
  }

  return entry.GetInt64();
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetLongLong(
    long long value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      value
  );

  entry.SetInt64(value);
}

template <>
template <typename ...Args>
std::filesystem::path RapidJsonConfigReader::GetPath(
    const std::filesystem::path& default_value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      default_value
  );

  if (!entry.IsString()) {
    entry.SetString(
        default_value,
        this->json_document().GetAllocator()
    );
  }

  return entry.GetString();
}

template <>
template <typename ...Args>
std::filesystem::path RapidJsonConfigReader::GetPath(
    std::string&& default_value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      std::move(default_value)
  );

  if (!entry.IsString()) {
    entry.SetString(
        default_value.data(),
        this->json_document().GetAllocator()
    );
  }

  return entry.GetString();
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetPath(
    const std::filesystem::path& value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      value
  );

  entry.SetString(
      value.u8string(),
      this->json_document().GetAllocator()
  );
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetPath(
    std::string&& value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      value
  );

  entry.SetString(
      std::move(value),
      this->json_document().GetAllocator()
  );
}

template <>
template <typename ...Args, typename T>
std::queue<T> RapidJsonConfigReader::GetQueue(
    const std::queue<T>& default_value,
    std::string_view first_key,
    Args... additional_keys
) {
  // TODO
}

template <>
template <typename ...Args, typename T>
std::queue<T> RapidJsonConfigReader::GetQueue(
    std::queue<T>&& default_value,
    std::string_view first_key,
    Args... additional_keys
) {
  // TODO
}

template <>
template <typename ...Args, typename T>
std::queue<T> RapidJsonConfigReader::SetQueue(
    const std::queue<T>& value,
    std::string_view first_key,
    Args... additional_keys
) {
  // TODO
}

template <>
template <typename ...Args, typename T>
std::queue<T> RapidJsonConfigReader::SetQueue(
    std::queue<T>&& value,
    std::string_view first_key,
    Args... additional_keys
) {
  // TODO
}

template <>
template <typename ...Args, typename T>
std::set<T> RapidJsonConfigReader::GetSet(
    const std::set<T>& default_value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      std::move(default_value)
  );

  if (!entry.IsArray()) {
    entry.SetArray();

    for (const T& value : default_value) {
      entry.PushBack(
          value,
          this->json_document().GetAllocator()
      );
    }
  }

  std::set<T> return_value = entry.GetArray();

  return return_value;
}

template <>
template <typename ...Args, typename T>
std::set<T> RapidJsonConfigReader::GetSet(
    std::set<T>&& default_value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      std::move(default_value)
  );

  if (!entry.IsArray()) {
    entry.SetArray();

    for (const T& value : default_value) {
      entry.PushBack(
          value,
          this->json_document().GetAllocator()
      );
    }
  }

  std::set<T> return_value = entry.GetArray();

  return return_value;
}

template <>
template <typename ...Args, typename T>
void RapidJsonConfigReader::SetSet(
    const std::set<T>& value,
    std::string_view first_key,
    Args... additional_keys
) {
  // TODO
}

template <>
template <typename ...Args, typename T>
void RapidJsonConfigReader::SetSet(
    std::set<T>&& value,
    std::string_view first_key,
    Args... additional_keys
) {
  // TODO
}

template <>
template <typename ...Args>
std::string RapidJsonConfigReader::GetString(
    std::string_view default_value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      default_value.data()
  );

  if (!entry.IsString()) {
    entry.SetString(
        default_value.data(),
        this->json_document().GetAllocator()
    );
  }

  return entry.GetString();
}

template <>
template <typename ...Args>
std::string RapidJsonConfigReader::GetString(
    std::string&& default_value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      default_value.data()
  );

  if (!entry.IsString()) {
    entry.SetString(
        default_value.data(),
        this->json_document().GetAllocator()
    );
  }

  return entry.GetString();
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetString(
    std::string_view value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      value
  );

  entry.SetString(
      value,
      this->json_document().GetAllocator()
  );
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetString(
    std::string&& value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      value
  );

  entry.SetString(
      std::move(value),
      this->json_document().GetAllocator()
  );
}

template <>
template <typename ...Args>
const std::string& RapidJsonConfigReader::GetStringRef(
    std::string_view default_value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      default_value.data()
  );

  if (!entry.IsString()) {
    entry.SetString(
        default_value.data(),
        this->json_document().GetAllocator()
    );
  }

  return entry.GetStringRef();
}

template <>
template <typename ...Args>
const std::string& RapidJsonConfigReader::GetStringRef(
    std::string&& default_value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      default_value.data()
  );

  if (!entry.IsString()) {
    entry.SetString(
        default_value.data(),
        this->json_document().GetAllocator()
    );
  }

  return entry.GetStringRef();
}

template <>
template <typename ...Args>
unsigned int RapidJsonConfigReader::GetUnsignedInt(
    unsigned int default_value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      default_value
  );

  if (!entry.IsUint()) {
    entry.SetUint(default_value);
  }

  return entry.GetUint();
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetUnsignedInt(
    unsigned int value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      value
  );

  entry.SetUint(value);
}

template <>
template <typename ...Args>
std::uint32_t RapidJsonConfigReader::GetUnsignedInt32(
    std::uint32_t default_value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      default_value
  );

  if (!entry.IsUint()) {
    entry.SetUint(default_value);
  }

  return entry.GetUint();
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetUnsignedInt32(
    std::uint32_t value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      value
  );

  entry.SetUint(value);
}

template <>
template <typename ...Args>
std::uint64_t RapidJsonConfigReader::GetUnsignedInt64(
    std::uint64_t default_value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      default_value
  );

  if (!entry.IsUint64()) {
    entry.SetUint64(default_value);
  }

  return entry.GetUint64();
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetUnsignedInt64(
    std::uint64_t value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      value
  );

  entry.SetUint64(value);
}

template <>
template <typename ...Args>
unsigned long RapidJsonConfigReader::GetUnsignedLong(
    unsigned long default_value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      default_value.data()
  );

  if (!entry.IsUint()) {
    entry.SetUint(default_value);
  }

  return entry.GetUint();
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetUnsignedLong(
    unsigned long value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      value
  );

  entry.SetUint(value);
}

template <>
template <typename ...Args>
unsigned long long RapidJsonConfigReader::GetUnsignedLongLong(
    unsigned long long default_value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      default_value
  );

  if (!entry.IsUint64()) {
    entry.SetUint64(default_value);
  }

  return entry.GetUint64();
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetUnsignedLongLong(
    unsigned long long value,
    std::string_view first_key,
    Args... additional_keys
) {
  auto& entry = GetEntryRef(
      this->json_document(),
      first_key,
      additional_keys,
      value
  );

  entry.SetUint64(value);
}

template <>
template <typename ...Args, typename T>
std::unordered_set<T> RapidJsonConfigReader::GetUnorderedSet(
    const std::unordered_set<T>& default_value,
    std::string_view first_key,
    Args... additional_keys
) {
  // TODO
}

template <>
template <typename ...Args, typename T>
std::unordered_set<T> RapidJsonConfigReader::GetUnorderedSet(
    std::unordered_set<T>&& default_value,
    std::string_view first_key,
    Args... additional_keys
) {
  // TODO
}

template <>
template <typename ...Args, typename T>
void RapidJsonConfigReader::SetUnorderedSet(
    const std::unordered_set<T>& value,
    std::string_view first_key,
    Args... additional_keys
) {
  // TODO
}

template <>
template <typename ...Args, typename T>
void RapidJsonConfigReader::SetUnorderedSet(
    std::unordered_set<T>&& value,
    std::string_view first_key,
    Args... additional_keys
) {
  // TODO
}

template <>
template <typename ...Args, typename T>
std::vector<T> RapidJsonConfigReader::GetVector(
    const std::vector<T>& default_value,
    std::string_view first_key,
    Args... additional_keys
) {
  // TODO
}

template <>
template <typename ...Args, typename T>
std::vector<T> RapidJsonConfigReader::GetVector(
    std::vector<T>&& default_value,
    std::string_view first_key,
    Args... additional_keys
) {
  // TODO
}

template <>
template <typename ...Args, typename T>
void RapidJsonConfigReader::SetVector(
    const std::vector<T>& value,
    std::string_view first_key,
    Args... additional_keys
) {
  // TODO
}

template <>
template <typename ...Args, typename T>
void RapidJsonConfigReader::SetVector(
    std::vector<T>&& value,
    std::string_view first_key,
    Args... additional_keys
) {
  // TODO
}

} // namespace mapi

#endif // SGD2MAPI_CXX_CONFIG_RAPID_JSON_CONFIG_READER_HPP_
