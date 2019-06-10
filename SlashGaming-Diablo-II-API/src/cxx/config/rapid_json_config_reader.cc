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

#include "rapid_json_config_reader.hpp"

#include <cstdarg>
#include <fstream>
#include <string_view>

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/prettywriter.h>

namespace mapi {
namespace {

bool CreateEmptyConfig(
    const std::filesystem::path& config_file_path
) {
  std::ofstream config_stream(config_file_path);

  if (!config_stream) {
    return false;
  }

  config_stream << u8"{}" << std::endl;
  return true;
}

rapidjson::Value& GetObjectEntryRef(
    rapidjson::Value& object,
    rapidjson::MemoryPoolAllocator<>& allocator,
    std::string_view current_key,
    std::vector<std::string_view> additional_keys,
    rapidjson::Value default_value
) {
  // Check for the existence of the key-value and add if needed.
  if (!object.HasMember(current_key.data())) {
    rapidjson::Value current_value = (additional_keys.size() == 0)
        ? std::move(default_value)
        : rapidjson::Value(rapidjson::kObjectType);

    object.AddMember(
        rapidjson::Value(current_key.data(), allocator),
        std::move(current_value),
        allocator
    );
  }

  // If this is the destination key, then return the value.
  rapidjson::Value& entry = object[current_key.data()];

  if (additional_keys.size() == 0) {
    return entry;
  }

  // Otherwise, recurse one level down.
  std::vector<std::string_view> remaining_keys(
      std::make_move_iterator(additional_keys.begin() + 1),
      std::make_move_iterator(additional_keys.end())
  );

  return GetObjectEntryRef(
      entry,
      allocator,
      additional_keys.front(),
      std::move(remaining_keys),
      std::move(default_value)
  );
}

} // namespace

rapidjson::Value& RapidJsonConfigReader::GetEntryRef(
    rapidjson::Document& document,
    std::string_view current_key,
    const std::vector<std::string_view>& additional_keys,
    rapidjson::Value default_value
) {
  return GetObjectEntryRef(
      document,
      document.GetAllocator(),
      current_key,
      additional_keys,
      std::move(default_value)
  );
}

template <>
RapidJsonConfigReader::GenericConfigReader(
    const std::filesystem::path& config_file_path
) : config_file_path_(config_file_path) {
  Read();
}

template <>
RapidJsonConfigReader::GenericConfigReader(
    std::filesystem::path&& config_file_path
) : config_file_path_(std::move(config_file_path)) {
}

template <>
bool RapidJsonConfigReader::Read() {
  // Create the config file if it doesn't exist.
  if (!std::filesystem::exists(this->config_file_path())) {
    CreateEmptyConfig(this->config_file_path());
  }

  // Parse the config.
  if (std::ifstream config_stream(this->config_file_path());
      config_stream) {
    rapidjson::IStreamWrapper config_stream_wrapper(config_stream);
    this->json_document_.ParseStream(config_stream_wrapper);
  } else {
    return false;
  }

  return true;
}

template <>
bool RapidJsonConfigReader::Write(int indent) {
  // Write to the config file any new default values.
  if (std::ofstream config_stream(this->config_file_path());
      config_stream) {
    rapidjson::OStreamWrapper config_stream_wrapper(config_stream);
    rapidjson::PrettyWriter pretty_config_writer(config_stream_wrapper);
    pretty_config_writer.SetIndent(' ', indent);

    this->json_document().Accept(pretty_config_writer);
  } else {
    return false;
  }
}

} // namespace mapi
