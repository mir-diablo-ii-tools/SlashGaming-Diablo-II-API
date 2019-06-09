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

#include "config_parser.hpp"

#include <filesystem>
#include <fstream>
#include <string>
#include <string_view>

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/prettywriter.h>

namespace mapi {
namespace {

constexpr std::string_view kGlobalEntryKey = u8"!!!Globals!!!";
constexpr std::string_view kConfigTabWidthKey = u8"Config Tab Width";
constexpr int kDefaultConfigTabWidthValue = 4;

constexpr std::string_view kMainEntryKey = u8"SlashGaming Diablo II Modding API";

constexpr std::string_view kMetaDataKey = u8"!!!Metadata (Do not modify)!!!";

// Note that this signifies the last version where the config formatting and
// entries were updated. These values do not need to change with respect to API
// file version!
constexpr std::string_view kMajorVersionAKey = u8"Major Version A";
constexpr int kMajorVersionAValue = 0;
constexpr std::string_view kMajorVersionBKey = u8"Major Version B";
constexpr int kMajorVersionBValue = 1;
constexpr std::string_view kMinorVersionAKey = u8"Minor Version A";
constexpr int kMinorVersionAValue = 0;
constexpr std::string_view kMinorVersionBKey = u8"Minor Version B";
constexpr int kMinorVersionBValue = 0;

constexpr std::string_view kAddressTableDirectoryPathKey =
    u8"Address Table Directory Path";
constexpr std::string_view kDefaultAddressTableDirectory = u8"Address Table";

const std::filesystem::path& GetConfigPath() {
  static std::filesystem::path kConfigPath = u8"SlashGaming-Config.json";
  return kConfigPath;
}

void CreateEmptyConfig(
    const std::filesystem::path& config_file_path
) {
  std::ofstream config_stream(config_file_path);
  config_stream << u8"{}" << std::endl;
}

bool AddMissingConfigEntries(
    const std::filesystem::path& config_file_path
) {
  rapidjson::Document config;

  // Read in the JSON.
  if (std::ifstream config_stream(config_file_path);
      config_stream) {
    rapidjson::IStreamWrapper config_reader(config_stream);
    config.ParseStream(config_reader);
  } else {
    return false;
  }

  // Get the global entry.
  if (!config.HasMember(kGlobalEntryKey.data())
      || !config[kGlobalEntryKey.data()].IsObject()) {
    config.AddMember(
        rapidjson::StringRef(kGlobalEntryKey.data()),
        rapidjson::Value(rapidjson::kObjectType),
        config.GetAllocator()
    );
  }

  auto& global_entry = config[kGlobalEntryKey.data()];

  // Get the main entry.
  if (!config.HasMember(kMainEntryKey.data())
      || !config[kMainEntryKey.data()].IsObject()) {
    config.AddMember(
        rapidjson::StringRef(kMainEntryKey.data()),
        rapidjson::Value(rapidjson::kObjectType),
        config.GetAllocator()
    );
  }

  auto& main_entry = config[kMainEntryKey.data()];

  // Get the metadata entry.
  if (!main_entry.HasMember(kMetaDataKey.data())
      || !main_entry[kMetaDataKey.data()].IsObject()) {
    main_entry.AddMember(
        rapidjson::StringRef(kMetaDataKey.data()),
        rapidjson::Value(rapidjson::kObjectType),
        config.GetAllocator()
    );
  }

  auto& metadata_entry = main_entry[kMetaDataKey.data()];

  // Check that the actual config version is less than or equal to the expected
  // config version. If the actual is larger, then do not add any new entries.
  // If there are any breaking config changes, then the program will most
  // likely crash.
  if (!metadata_entry.HasMember(kMajorVersionAKey.data())
      || !metadata_entry[kMajorVersionAKey.data()].IsInt()
      || metadata_entry[kMajorVersionAKey.data()].GetInt() < kMajorVersionAValue) {
    metadata_entry.AddMember(
        rapidjson::StringRef(kMajorVersionAKey.data()),
        rapidjson::Value(kMajorVersionAValue),
        config.GetAllocator()
    );
    metadata_entry.AddMember(
        rapidjson::StringRef(kMajorVersionBKey.data()),
        rapidjson::Value(0),
        config.GetAllocator()
    );
    metadata_entry.AddMember(
        rapidjson::StringRef(kMinorVersionAKey.data()),
        rapidjson::Value(0),
        config.GetAllocator()
    );
    metadata_entry.AddMember(
        rapidjson::StringRef(kMinorVersionBKey.data()),
        rapidjson::Value(0),
        config.GetAllocator()
    );
  } else if (metadata_entry[kMajorVersionAKey.data()].GetInt() > kMajorVersionAValue) {
    return true;
  }

  if (!metadata_entry.HasMember(kMajorVersionBKey.data())
      || !metadata_entry[kMajorVersionBKey.data()].IsInt()
      || metadata_entry[kMajorVersionBKey.data()].GetInt() < kMajorVersionBValue) {
    metadata_entry.AddMember(
        rapidjson::StringRef(kMajorVersionBKey.data()),
        rapidjson::Value(kMajorVersionBValue),
        config.GetAllocator()
    );
    metadata_entry.AddMember(
        rapidjson::StringRef(kMinorVersionAKey.data()),
        rapidjson::Value(0),
        config.GetAllocator()
    );
    metadata_entry.AddMember(
        rapidjson::StringRef(kMinorVersionBKey.data()),
        rapidjson::Value(0),
        config.GetAllocator()
    );
  } else if (metadata_entry[kMajorVersionBKey.data()].GetInt() > kMajorVersionBValue) {
    return true;
  }

  if (!metadata_entry.HasMember(kMinorVersionAKey.data())
      || !metadata_entry[kMinorVersionAKey.data()].IsInt()
      || metadata_entry[kMinorVersionAKey.data()].GetInt() < kMinorVersionAValue) {
    metadata_entry.AddMember(
        rapidjson::StringRef(kMinorVersionAKey.data()),
        rapidjson::Value(kMinorVersionAValue),
        config.GetAllocator()
    );
    metadata_entry.AddMember(
        rapidjson::StringRef(kMinorVersionBKey.data()),
        rapidjson::Value(0),
        config.GetAllocator()
    );
  } else if (metadata_entry[kMinorVersionAKey.data()].GetInt() > kMinorVersionAValue) {
    return true;
  }

  if (!metadata_entry.HasMember(kMinorVersionBKey.data())
      || !metadata_entry[kMinorVersionBKey.data()].IsInt()
      || metadata_entry[kMinorVersionBKey.data()].GetInt() < kMinorVersionBValue) {
    metadata_entry.AddMember(
        rapidjson::StringRef(kMinorVersionBKey.data()),
        rapidjson::Value(kMinorVersionBValue),
        config.GetAllocator()
    );
  } else if (metadata_entry[kMinorVersionBKey.data()].GetInt() > kMinorVersionBValue) {
    return true;
  }

  // The user's config version is less or equal, so add defaults if missing.
  if (!global_entry.HasMember(kConfigTabWidthKey.data())
      || !global_entry[kConfigTabWidthKey.data()].IsInt()
      || global_entry[kConfigTabWidthKey.data()].GetInt() < 0) {
    global_entry.AddMember(
        rapidjson::StringRef(kConfigTabWidthKey.data()),
        rapidjson::Value(kDefaultConfigTabWidthValue),
        config.GetAllocator()
    );
  }

  if (!main_entry.HasMember(kAddressTableDirectoryPathKey.data())
      || !main_entry[kAddressTableDirectoryPathKey.data()].IsString()) {
    main_entry.AddMember(
        rapidjson::StringRef(kAddressTableDirectoryPathKey.data()),
        rapidjson::StringRef(kDefaultAddressTableDirectory.data()),
        config.GetAllocator()
    );
  }

  // Write to the config file any new default values.
  if (std::ofstream config_stream(config_file_path);
      config_stream) {
    rapidjson::OStreamWrapper config_writer(config_stream);
    rapidjson::PrettyWriter pretty_config_writer(config_writer);
    pretty_config_writer.SetIndent(' ', global_entry[kConfigTabWidthKey.data()].GetInt());

    config.Accept(pretty_config_writer);
  } else {
    return false;
  }

  return true;
}

rapidjson::Document ParseConfig(
    const std::filesystem::path& config_file_path
) {
  // Create the config file if it doesn't exist.
  if (!std::filesystem::exists(config_file_path)) {
    CreateEmptyConfig(config_file_path);
  }

  // Read the config file for processing, if all other conditions are good.
  bool is_missing_entry_added = AddMissingConfigEntries(config_file_path);
  if (!is_missing_entry_added) {
    return {};
  }

  // Parse the config.
  rapidjson::Document config;
  if (std::ifstream config_stream(config_file_path);
      config_stream) {
    rapidjson::IStreamWrapper config_reader(config_stream);
    config.ParseStream(config_reader);
  }

  return config;
}

rapidjson::Document& GetConfig() {
  static rapidjson::Document config = ParseConfig(GetConfigPath());
  return config;
}

std::filesystem::path
ParseAddressTableDirectoryPath() {
  rapidjson::Document& config = GetConfig();
  auto& address_table_path_raw_value =
      config[kMainEntryKey.data()][kAddressTableDirectoryPathKey.data()];

  if (!address_table_path_raw_value.IsString()) {
    address_table_path_raw_value.SetString(
        rapidjson::StringRef(kDefaultAddressTableDirectory.data())
    );
  }

  std::filesystem::path address_table_directory_path =
      address_table_path_raw_value.GetString();

  return address_table_directory_path;
}

} // namespace

const std::filesystem::path&
GetAddressTableDirectoryPath() {
  static std::filesystem::path address_table_path(
      ParseAddressTableDirectoryPath()
  );
  return address_table_path;
}

} // namespace mapi
