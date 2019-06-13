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

#include <utility>

#include <rapidjson/document.h>
#include "generic_json_config_reader.hpp"

namespace mapi {

using RapidJsonConfigReader = GenericConfigReader<rapidjson::Document, rapidjson::Value, rapidjson::Value>;

extern RapidJsonConfigReader;

/* Functions for Generic Types */

template <>
template <typename ...Args>
bool RapidJsonConfigReader::ContainsKey(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  std::vector<std::string_view> additional_keys_vector = {
      additional_keys...
  };

  return this->HasEntryRef(
      this->json_document(),
      first_key,
      additional_keys_vector
  );
}

template <>
template <typename ...Args>
const RapidJsonConfigReader::JsonValue&
RapidJsonConfigReader::GetValueRef(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  std::vector<std::string_view> additional_keys_vector = {
      additional_keys...
  };

  return this->GetEntryRef(
      this->json_document_,
      first_key,
      additional_keys_vector
  );
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetValue(
    RapidJsonConfigReader::JsonValue value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  std::vector<std::string_view> additional_keys_vector = {
      additional_keys...
  };

  SetEntryRef(
      std::move(value),
      this->json_document_,
      first_key,
      additional_keys_vector
  );
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetDeepValue(
    RapidJsonConfigReader::JsonValue value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  std::vector<std::string_view> additional_keys_vector = {
      additional_keys...
  };

  SetDeepEntryRef(
      std::move(value),
      this->json_document_,
      first_key,
      additional_keys_vector
  );
}

/* Functions for bool */

template <>
template <typename ...Args>
bool RapidJsonConfigReader::GetBool(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  const rapidjson::Value& value_ref = this->GetValueRef(
      first_key,
      additional_keys...
  );

  return value_ref.GetBool();
}

template <>
template <typename ...Args>
bool RapidJsonConfigReader::GetBoolOrDefault(
    bool default_value,
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->HasBool(first_key, additional_keys...)) {
    return default_value;
  }

  return this->GetBool(first_key, additional_keys...);
}

template <>
template <typename ...Args>
bool RapidJsonConfigReader::HasBool(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->ContainsKey(first_key, additional_keys...)) {
    return false;
  }

  const rapidjson::Value& value_ref = this->GetValueRef(
      first_key,
      additional_keys...
  );

  return value_ref.IsBool();
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetBool(
    bool value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetEntry(
      rapidjson::Value(value),
      first_key,
      additional_keys...
  );
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetDeepBool(
    bool value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetDeepValueRef(
      rapidjson::Value(value),
      first_key,
      additional_keys...
  );
}

/* Functions for int */

template <>
template <typename ...Args>
int RapidJsonConfigReader::GetInt(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  const rapidjson::Value& value_ref = this->GetValueRef(
      first_key,
      additional_keys...
  );

  return value_ref.GetInt();
}

template <>
template <typename ...Args>
int RapidJsonConfigReader::GetIntOrDefault(
    int default_value,
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->HasInt(first_key, additional_keys...)) {
    return default_value;
  }

  return this->GetInt(first_key, additional_keys...);
}

template <>
template <typename ...Args>
bool RapidJsonConfigReader::HasInt(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->ContainsKey(first_key, additional_keys...)) {
    return false;
  }

  const rapidjson::Value& value_ref = this->GetValueRef(
      first_key,
      additional_keys...
  );

  return value_ref.IsInt();
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetInt(
    int value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetValue(
      rapidjson::Value(value),
      first_key,
      additional_keys...
  );
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetDeepInt(
    int value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetDeepValue(
      rapidjson::Value(value),
      first_key,
      additional_keys...
  );
}

/* Functions for std::int32_t */

template <>
template <typename ...Args>
std::int32_t RapidJsonConfigReader::GetInt32(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  const rapidjson::Value& value_ref = this->GetValueRef(
      first_key,
      additional_keys...
  );

  return value_ref.GetInt();
}

template <>
template <typename ...Args>
std::int32_t RapidJsonConfigReader::GetInt32OrDefault(
    std::int32_t default_value,
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->HasInt32(first_key, additional_keys...)) {
    return default_value;
  }

  return this->GetInt32(first_key, additional_keys...);
}

template <>
template <typename ...Args>
bool RapidJsonConfigReader::HasInt32(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->ContainsKey(first_key, additional_keys...)) {
    return false;
  }

  const rapidjson::Value& value_ref = this->GetValueRef(
      first_key,
      additional_keys...
  );

  return value_ref.IsInt();
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetInt32(
    std::int32_t value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetValue(
      value,
      first_key,
      additional_keys...
  );
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetDeepInt32(
    std::int32_t value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetDeepValue(
      rapidjson::Value(value),
      first_key,
      additional_keys...
  );
}

/* Functions for std::int64_t */

template <>
template <typename ...Args>
std::int64_t RapidJsonConfigReader::GetInt64(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  const rapidjson::Value& value_ref = this->GetValueRef(
      first_key,
      additional_keys...
  );

  return value_ref.GetInt64();
}

template <>
template <typename ...Args>
std::int64_t RapidJsonConfigReader::GetInt64OrDefault(
    std::int64_t default_value,
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->HasInt64(first_key, additional_keys...)) {
    return default_value;
  }

  return this->GetInt64(first_key, additional_keys...);
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetInt64(
    std::int64_t value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetValue(
      rapidjson::Value(value),
      first_key,
      additional_keys...
  );
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetDeepInt64(
    std::int64_t value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetDeepValue(
      rapidjson::Value(value),
      first_key,
      additional_keys...
  );
}

/* Functions for long */

template <>
template <typename ...Args>
long RapidJsonConfigReader::GetLong(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  const rapidjson::Value& value_ref = this->GetValueRef(
      first_key,
      additional_keys...
  );

  return value_ref.GetInt();
}

template <>
template <typename ...Args>
long RapidJsonConfigReader::GetLongOrDefault(
    long default_value,
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->HasLong(first_key, additional_keys...)) {
    return default_value;
  }

  return this->GetLong(first_key, additional_keys...);
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetLong(
    long value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetValue(
      rapidjson::Value(value),
      first_key,
      additional_keys...
  );
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetDeepLong(
    long value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetDeepValue(
      rapidjson::Value(value),
      first_key,
      additional_keys...
  );
}

/* Functions for long long */

template <>
template <typename ...Args>
long long RapidJsonConfigReader::GetLongLong(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  const rapidjson::Value& value_ref = this->GetValueRef(
      first_key,
      additional_keys...
  );

  return value_ref.GetInt64();
}

template <>
template <typename ...Args>
long long RapidJsonConfigReader::GetLongLongOrDefault(
    long long default_value,
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->HasLongLong(first_key, additional_keys...)) {
    return default_value;
  }

  return this->GetLongLong(first_key, additional_keys...);
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetLongLong(
    long long value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetValue(
      rapidjson::Value(value),
      first_key,
      additional_keys...
  );
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetDeepLongLong(
    long long value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetDeepValue(
      rapidjson::Value(value),
      first_key,
      additional_keys...
  );
}

/* Functions for std::filesystem::path */

template <>
template <typename ...Args>
std::filesystem::path RapidJsonConfigReader::GetPath(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  std::string value = this->GetString(
      first_key,
      additional_keys...
  );

  return std::filesystem::u8path(std::move(value));
}

template <>
template <typename ...Args>
std::filesystem::path RapidJsonConfigReader::GetPathOrDefault(
    const std::filesystem::path& default_value,
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->HasPath(first_key, additional_keys)) {
    return default_value;
  }

  return this->GetPath(first_key, additional_keys...);
}

template <>
template <typename ...Args>
std::filesystem::path RapidJsonConfigReader::GetPathOrDefault(
    std::filesystem::path&& default_value,
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->HasPath(first_key, additional_keys...)) {
    return std::move(default_value);
  }

  return this->GetPath(first_key, additional_keys...);
}

template <>
template <typename ...Args>
bool RapidJsonConfigReader::HasPath(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  return this->HasString(
      first_key,
      additional_keys...
  );
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetPath(
    const std::filesystem::path& value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetString(
      value.u8string(),
      first_key,
      additional_keys...
  );
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetDeepPath(
    const std::filesystem::path& value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetDeepString(
      value.u8string(),
      first_key,
      additional_keys
  );
}

/* Functions for std::queue */

template <>
template <typename T, typename ...Args>
std::queue<T> RapidJsonConfigReader::GetQueue(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  // TODO
}

template <>
template <typename T, typename ...Args>
std::queue<T> RapidJsonConfigReader::GetQueueOrDefault(
    const std::queue<T>& default_value,
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->HasQueue(first_key, additional_keys)) {
    return default_value;
  }

  return this->GetQueue(first_key, additional_keys...);
}

template <>
template <typename T, typename ...Args>
std::queue<T> RapidJsonConfigReader::GetQueueOrDefault(
    std::queue<T>&& default_value,
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->HasQueue(first_key, additional_keys...)) {
    return std::move(default_value);
  }

  return this->GetQueue(first_key, additional_keys...);
}

template <>
template <typename ...Args>
bool RapidJsonConfigReader::HasQueue(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->ContainsKey(first_key, additional_keys...)) {
    return false;
  }

  const rapidjson::Value& value_ref = this->GetValueRef(
      first_key,
      additional_keys...
  );

  return value_ref.IsArray();
}

template <>
template <typename T, typename ...Args>
std::queue<T> RapidJsonConfigReader::SetQueue(
    const std::queue<T>& value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  // TODO
}

template <>
template <typename T, typename ...Args>
std::queue<T> RapidJsonConfigReader::SetQueue(
    std::queue<T>&& value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  // TODO
}

template <>
template <typename T, typename ...Args>
std::queue<T> RapidJsonConfigReader::SetDeepQueue(
    const std::queue<T>& value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  // TODO
}

template <>
template <typename T, typename ...Args>
std::queue<T> RapidJsonConfigReader::SetDeepQueue(
    std::queue<T>&& value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  // TODO
}

/* Functions for std::set */

template <>
template <typename T, typename ...Args>
std::set<T> RapidJsonConfigReader::GetSet(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  // TODO
}

template <>
template <typename T, typename ...Args>
std::set<T> RapidJsonConfigReader::GetSetOrDefault(
    const std::set<T>& default_value,
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->HasSet(first_key, additional_keys...)) {
    return default_value;
  }

  return this->GetSet(first_key, additional_keys...);
}

template <>
template <typename T, typename ...Args>
std::set<T> RapidJsonConfigReader::GetSetOrDefault(
    std::set<T>&& default_value,
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->HasSet(first_key, additional_keys...)) {
    return std::move(default_value);
  }

  return this->GetSet(first_key, additional_keys...);
}

template <>
template <typename ...Args>
bool RapidJsonConfigReader::HasSet(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->ContainsKey(first_key, additional_keys...)) {
    return false;
  }

  const rapidjson::Value& value_ref = this->GetValueRef(
      first_key,
      additional_keys...
  );

  return value_ref.IsArray();
}

template <>
template <typename T, typename ...Args>
void RapidJsonConfigReader::SetSet(
    const std::set<T>& value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  // TODO
}

template <>
template <typename T, typename ...Args>
void RapidJsonConfigReader::SetSet(
    std::set<T>&& value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  // TODO
}

/* Functions for std::string */

template <>
template <typename ...Args>
std::string RapidJsonConfigReader::GetString(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  const rapidjson::Value& value_ref = this->GetValueRef(
      first_key,
      additional_keys...
  );

  return value_ref.GetString();
}

template <>
template <typename ...Args>
std::string RapidJsonConfigReader::GetStringOrDefault(
    const std::string& default_value,
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->HasString(first_key, additional_keys...)) {
    return default_value;
  }

  return this->GetString(first_key, additional_keys...);
}

template <>
template <typename ...Args>
std::string RapidJsonConfigReader::GetStringOrDefault(
    std::string&& default_value,
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->HasString(first_key, additional_keys...)) {
    return std::move(default_value);
  }

  return this->GetString(first_key, additional_keys...);
}

template <>
template <typename ...Args>
bool RapidJsonConfigReader::HasString(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->ContainsKey(first_key, additional_keys...)) {
    return false;
  }

  const rapidjson::Value& value_ref = this->GetValueRef(
      first_key,
      additional_keys...
  );

  return value_ref.GetString();
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetString(
    const std::string& value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetValue(
      rapidjson::Value(value.data(), this->json_document_.GetAllocator()),
      first_key,
      additional_keys...
  );
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetString(
    std::string&& value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetValue(
      rapidjson::Value(value.data(), this->json_document_.GetAllocator()),
      first_key,
      additional_keys...
  );
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetDeepString(
    const std::string& value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetDeepValue(
      rapidjson::Value(value.data(), this->json_document_.GetAllocator()),
      first_key,
      additional_keys...
  );
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetDeepString(
    std::string&& value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetDeepValue(
      rapidjson::Value(value.data(), this->json_document_.GetAllocator()),
      first_key,
      additional_keys...
  );
}

/* Functions for unsigned int */

template <>
template <typename ...Args>
unsigned int RapidJsonConfigReader::GetUnsignedInt(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  const rapidjson::Value& value_ref = this->GetValueRef(
      first_key,
      additional_keys...
  );

  return value_ref.GetUint();
}

template <>
template <typename ...Args>
unsigned int RapidJsonConfigReader::GetUnsignedIntOrDefault(
    unsigned int default_value,
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->HasUnsignedInt(first_key, additional_keys...)) {
    return default_value;
  }

  return this->GetUnsignedInt(first_key, additional_keys...);
}

template <>
template <typename ...Args>
bool RapidJsonConfigReader::HasUnsignedInt(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->ContainsKey(first_key, additional_keys...)) {
    return false;
  }

  const rapidjson::Value& value_ref = this->GetValueRef(
      first_key,
      additional_keys...
  );

  return value_ref.IsUint();
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetUnsignedInt(
    unsigned int value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetValue(
      rapidjson::Value(value),
      first_key,
      additional_keys...
  );
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetDeepUnsignedInt(
    unsigned int value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetDeepValue(
      rapidjson::Value(value),
      first_key,
      additional_keys...
  );
}

/* Functions for std::uint32_t */

template <>
template <typename ...Args>
std::uint32_t RapidJsonConfigReader::GetUnsignedInt32(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  const rapidjson::Value& value_ref = this->GetValueRef(
      first_key,
      additional_keys...
  );

  return value_ref.GetUint();
}

template <>
template <typename ...Args>
std::uint32_t RapidJsonConfigReader::GetUnsignedInt32OrDefault(
    std::uint32_t default_value,
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->HasUnsignedInt32(first_key, additional_keys...)) {
    return default_value;
  }

  return this->GetUnsignedInt32(first_key, additional_keys...);
}

template <>
template <typename ...Args>
bool RapidJsonConfigReader::HasUnsignedInt32(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->ContainsKey(first_key, additional_keys...)) {
    return false;
  }

  const rapidjson::Value& value_ref = this->GetValueRef(
      first_key,
      additional_keys...
  );

  return value_ref.IsUint();
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetUnsignedInt32(
    std::uint32_t value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetValue(
      rapidjson::Value(value),
      first_key,
      additional_keys...
  );
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetDeepUnsignedInt32(
    std::uint32_t value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetDeepValue(
      rapidjson::Value(value),
      first_key,
      additional_keys...
  );
}

/* Functions for std::uint64_t */

template <>
template <typename ...Args>
std::uint64_t RapidJsonConfigReader::GetUnsignedInt64(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  const rapidjson::Value& value_ref = this->GetValueRef(
      first_key,
      additional_keys...
  );

  return value_ref.GetInt64();
}

template <>
template <typename ...Args>
std::uint64_t RapidJsonConfigReader::GetUnsignedInt64OrDefault(
    std::uint64_t default_value,
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->HasUnsignedInt64(first_key, additional_keys...)) {
    return default_value;
  }

  return this->GetUnsignedInt64(first_key, additional_keys...);
}

template <>
template <typename ...Args>
bool RapidJsonConfigReader::HasUnsignedInt64(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->ContainsKey(first_key, additional_keys...)) {
    return false;
  }

  const rapidjson::Value& value_ref = this->GetValueRef(
      first_key,
      additional_keys...
  );

  return value_ref.IsUint64();
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetUnsignedInt64(
    std::uint64_t value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetValue(
      rapidjson::Value(value),
      first_key,
      additional_keys...
  );
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetDeepUnsignedInt64(
    std::uint64_t value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetDeepValue(
      rapidjson::Value(value),
      first_key,
      additional_keys...
  );
}

/* Functions for unsigned long */

template <>
template <typename ...Args>
unsigned long RapidJsonConfigReader::GetUnsignedLong(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  const rapidjson::Value& value_ref = this->GetValueRef(
      first_key,
      additional_keys...
  );

  return value_ref.GetUint();
}

template <>
template <typename ...Args>
unsigned long RapidJsonConfigReader::GetUnsignedLongOrDefault(
    unsigned long default_value,
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->HasUnsignedLong(first_key, additional_keys...)) {
    return default_value;
  }

  return this->GetUnsignedLong(first_key, additional_keys...);
}

template <>
template <typename ...Args>
bool RapidJsonConfigReader::HasUnsignedLong(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->ContainsKey(first_key, additional_keys...)) {
    return false;
  }

  const rapidjson::Value& value_ref = this->GetValueRef(
      first_key,
      additional_keys...
  );

  return value_ref.IsUint();
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetUnsignedLong(
    unsigned long value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetValue(
      rapidjson::Value(value),
      first_key,
      additional_keys...
  );
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetDeepUnsignedLong(
    unsigned long value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetDeepValue(
      rapidjson::Value(value),
      first_key,
      additional_keys...
  );
}

/* Functions for unsigned long long */

template <>
template <typename ...Args>
unsigned long long RapidJsonConfigReader::GetUnsignedLongLong(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  const rapidjson::Value& value_ref = this->GetValueRef(
      first_key,
      additional_keys...
  );

  return value_ref.GetUint64();
}

template <>
template <typename ...Args>
unsigned long long RapidJsonConfigReader::GetUnsignedLongLongOrDefault(
    unsigned long long default_value,
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->HasUnsignedLongLong(first_key, additional_keys...)) {
    return default_value;
  }

  return this->GetUnsignedLongLong(first_key, additional_keys);
}

template <>
template <typename ...Args>
bool RapidJsonConfigReader::HasUnsignedLongLong(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->ContainsKey(first_key, additional_keys...)) {
    return false;
  }

  const rapidjson::Value& value_ref = this->GetValueRef(
      first_key,
      additional_keys...
  );

  return value_ref.IsUint64();
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetUnsignedLongLong(
    unsigned long long value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetValue(
      rapidjson::Value(value),
      first_key,
      additional_keys...
  );
}

template <>
template <typename ...Args>
void RapidJsonConfigReader::SetDeepUnsignedLongLong(
    unsigned long long value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  this->SetDeepValue(
      rapidjson::Value(value),
      first_key,
      additional_keys...
  );
}

/* Functions for std::unordered_set */

template <>
template <typename T, typename ...Args>
std::unordered_set<T> RapidJsonConfigReader::GetUnorderedSet(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  // TODO
}

template <>
template <typename T, typename ...Args>
std::unordered_set<T> RapidJsonConfigReader::GetUnorderedSetOrDefault(
    const std::unordered_set<T>& default_value,
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->HasUnorderedSet(first_key, additional_keys...)) {
    return default_value;
  }

  return this->GetUnorderedSet(first_key, additional_keys...);
}

template <>
template <typename T, typename ...Args>
std::unordered_set<T> RapidJsonConfigReader::GetUnorderedSetOrDefault(
    std::unordered_set<T>&& default_value,
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->HasUnorderedSet(first_key, additional_keys...)) {
    return std::move(default_value);
  }

  return this->GetUnorderedSet(first_key, additional_keys...);
}

template <>
template <typename ...Args>
bool RapidJsonConfigReader::HasUnorderedSet(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->ContainsKey(first_key, additional_keys...)) {
    return false;
  }

  const rapidjson::Value& value_ref = this->GetValueRef(
      first_key,
      additional_keys...
  );

  return value_ref.IsArray();
}

template <>
template <typename T, typename ...Args>
void RapidJsonConfigReader::SetUnorderedSet(
    const std::unordered_set<T>& value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  // TODO
}

template <>
template <typename T, typename ...Args>
void RapidJsonConfigReader::SetUnorderedSet(
    std::unordered_set<T>&& value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  // TODO
}

template <>
template <typename T, typename ...Args>
void RapidJsonConfigReader::SetDeepUnorderedSet(
    const std::unordered_set<T>& value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  // TODO
}

template <>
template <typename T, typename ...Args>
void RapidJsonConfigReader::SetDeepUnorderedSet(
    std::unordered_set<T>&& value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  // TODO
}

/* Functions of std::vector */

template <>
template <typename T, typename ...Args>
std::vector<T> RapidJsonConfigReader::GetVector(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  // TODO
}

template <>
template <typename T, typename ...Args>
std::vector<T> RapidJsonConfigReader::GetVectorOrDefault(
    const std::vector<T>& default_value,
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->ContainsKey(first_key, additional_keys...)) {
    return default_value;
  }

  return this->GetVector(first_key, additional_keys...);
}

template <>
template <typename T, typename ...Args>
std::vector<T> RapidJsonConfigReader::GetVectorOrDefault(
    std::vector<T>&& default_value,
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->ContainsKey(first_key, additional_keys...)) {
    return std::move(default_value);
  }

  return this->GetVector(first_key, additional_keys...);
}

template <>
template <typename ...Args>
bool RapidJsonConfigReader::HasVector(
    std::string_view first_key,
    const Args&... additional_keys
) const {
  if (!this->ContainsKey(first_key, additional_keys...)) {
    return false;
  }

  const rapidjson::Value& value_ref = this->GetValueRef(
      first_key,
      additional_keys...
  );

  return value_ref.IsArray();
}

template <>
template <typename T, typename ...Args>
void RapidJsonConfigReader::SetVector(
    const std::vector<T>& value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  // TODO
}

template <>
template <typename T, typename ...Args>
void RapidJsonConfigReader::SetVector(
    std::vector<T>&& value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  // TODO
}

template <>
template <typename T, typename ...Args>
void RapidJsonConfigReader::SetDeepVector(
    const std::vector<T>& value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  // TODO
}

template <>
template <typename T, typename ...Args>
void RapidJsonConfigReader::SetDeepVector(
    std::vector<T>&& value,
    std::string_view first_key,
    const Args&... additional_keys
) {
  // TODO
}

} // namespace mapi

#endif // SGD2MAPI_CXX_CONFIG_RAPID_JSON_CONFIG_READER_HPP_
