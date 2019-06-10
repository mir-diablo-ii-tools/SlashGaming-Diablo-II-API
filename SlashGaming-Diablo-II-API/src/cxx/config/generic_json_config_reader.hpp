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

#ifndef SGD2MAPI_CXX_CONFIG_GENERIC_JSON_CONFIG_READER_HPP_
#define SGD2MAPI_CXX_CONFIG_GENERIC_JSON_CONFIG_READER_HPP_

#include <cstdint>
#include <filesystem>
#include <initializer_list>
#include <map>
#include <set>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace mapi {

template<typename JsonDocument, typename JsonValue>
class GenericConfigReader {
 public:
  GenericConfigReader() = delete;

  explicit GenericConfigReader(
      const std::filesystem::path& config_file_path
  );

  explicit GenericConfigReader(
      std::filesystem::path&& config_file_path
  );

  bool Read();

  bool Write(int indent);

  template <typename ...Args>
  bool GetBool(
      bool default_value,
      std::string_view first_key,
      Args... additional_keys
  );

  template <typename ...Args>
  void SetBool(
      bool value,
      std::string_view first_key,
      Args... additional_keys
  );

  template <typename ...Args>
  int GetInt(
      int default_value,
      std::string_view first_key,
      Args... additional_keys
  );

  template <typename ...Args>
  std::int32_t GetInt32(
      std::int32_t default_value,
      std::string_view first_key,
      Args... additional_keys
  );

  template <typename ...Args>
  std::int64_t GetInt64(
      std::int64_t default_value,
      std::string_view first_key,
      Args... additional_keys
  );

  template <typename ...Args>
  long GetLong(
      long default_value,
      std::string_view first_key,
      Args... additional_keys
  );

  template <typename ...Args>
  long long GetLongLong(
      long long default_value,
      std::string_view first_key,
      Args... additional_keys
  );

  template <typename ...Args>
  std::filesystem::path GetPath(
      const std::filesystem::path& default_value,
      std::string_view first_key,
      Args... additional_keys
  );

  template <typename ...Args>
  std::filesystem::path GetPath(
      std::string&& default_value,
      std::string_view first_key,
      Args... additional_keys
  );

  template <typename ...Args, typename T>
  std::set<T> GetSet(
      const std::set<T>& default_value,
      std::string_view first_key,
      Args... additional_keys
  );

  template <typename ...Args, typename T>
  std::set<T> GetSet(
      std::set<T>&& default_value,
      std::string_view first_key,
      Args... additional_keys
  );

  template <typename ...Args>
  std::string GetString(
      std::string_view default_value,
      std::string_view first_key,
      Args... additional_keys
  );

  template <typename ...Args>
  std::string GetString(
      std::string&& default_value,
      std::string_view first_key,
      Args... additional_keys
  );

  template <typename ...Args>
  const std::string& GetStringRef(
      std::string_view default_value,
      std::string_view first_key,
      Args... additional_keys
  );

  template <typename ...Args>
  const std::string& GetStringRef(
      std::string&& default_value,
      std::string_view first_key,
      Args... additional_keys
  );

  template <typename ...Args>
  unsigned int GetUnsignedInt(
      unsigned int default_value,
      std::string_view first_key,
      Args... additional_keys
  );

  template <typename ...Args>
  std::uint32_t GetUnsignedInt32(
      std::uint32_t default_value,
      std::string_view first_key,
      Args... additional_keys
  );

  template <typename ...Args>
  std::uint64_t GetUnsignedInt64(
      std::uint64_t default_value,
      std::string_view first_key,
      Args... additional_keys
  );

  template <typename ...Args>
  unsigned long GetUnsignedLong(
      unsigned long default_value,
      std::string_view first_key,
      Args... additional_keys
  );

  template <typename ...Args>
  unsigned long long GetUnsignedLongLong(
      unsigned long long default_value,
      std::string_view first_key,
      Args... additional_keys
  );

  template <typename ...Args, typename T>
  std::unordered_set<T> GetUnorderedSet(
      const std::unordered_set<T>& default_value,
      std::string_view first_key,
      Args... additional_keys
  );

  template <typename ...Args, typename T>
  std::unordered_set<T> GetUnorderedSet(
      std::unordered_set<T>&& default_value,
      std::string_view first_key,
      Args... additional_keys
  );

  template <typename ...Args, typename T>
  std::vector<T> GetVector(
      const std::vector<T>& default_value,
      std::string_view first_key,
      Args... additional_keys
  );

  template <typename ...Args, typename T>
  std::vector<T> GetVector(
      std::vector<T>&& default_value,
      std::string_view first_key,
      Args... additional_keys
  );

  const std::filesystem::path& config_file_path() const noexcept {
    return this->config_file_path_;
  }

  const JsonDocument& json_document() const noexcept {
    return this->json_document_;
  }

 private:
  std::filesystem::path config_file_path_;
  JsonDocument json_document_;

  JsonValue& GetEntryRef(
      JsonDocument& document,
      std::string_view current_key,
      const std::vector<std::string_view>& additional_keys,
      JsonValue default_value
  );
};

} // namespace mapi

#endif // SGD2MAPI_CXX_CONFIG_GENERIC_JSON_CONFIG_READER_HPP_
