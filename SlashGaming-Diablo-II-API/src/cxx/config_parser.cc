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
 *  it with any Glide wrapper (or a modified version of that library),
 *  containing parts not covered by a compatible license, the licensors of
 *  this Program grant you additional permission to convey the resulting
 *  work.
 */

#include "config_parser.hpp"

#include <filesystem>
#include <fstream>
#include <iomanip>
#include <string>
#include <string_view>

#include <nlohmann/json.hpp>

namespace mapi {
namespace {

constexpr std::string_view kGlobalEntryKey = u8"!!!Globals!!!";
constexpr std::string_view kConfigTabWidthKey = u8"Config Tab Width";
constexpr int kDefaultConfigTabWidthValue = 4;

constexpr std::string_view kMainEntryKey = u8"SGD2MAPI";

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

const std::filesystem::path&
GetConfigPath(void) {
  static std::filesystem::path kConfigPath = u8"SlashGaming-Config.json";
  return kConfigPath;
}

void AddMissingConfigEntries(
    nlohmann::json& config_json
) {
  auto& global_entry = config_json[kGlobalEntryKey.data()];
  if (!global_entry.is_object()) {
    global_entry = {};
  }

  auto& main_entry = config_json[kMainEntryKey.data()];
  if (!main_entry.is_object()) {
    main_entry = {};
  }

  auto& metadata_entry = main_entry[kMetaDataKey.data()];
  if (!metadata_entry.is_object()) {
    metadata_entry = {};
  }

  // Check that the actual config version is less than or equal to the expected
  // config version. If the actual is larger, then do not add any new entries.
  // If there are any breaking config changes, then the program will most
  // likely crash.
  auto& major_version_a = metadata_entry[kMajorVersionAKey.data()];
  auto& major_version_b = metadata_entry[kMajorVersionBKey.data()];
  auto& minor_version_a = metadata_entry[kMinorVersionAKey.data()];
  auto& minor_version_b = metadata_entry[kMinorVersionBKey.data()];

  if (!major_version_a.is_number() || major_version_a < kMajorVersionAValue) {
    major_version_a = kMajorVersionAValue;
    major_version_b = kMajorVersionBValue;
    minor_version_a = kMinorVersionAValue;
    minor_version_b = kMinorVersionBValue;
  } else if (major_version_a > kMajorVersionAValue) {
    return;
  }

  if (!major_version_b.is_number() || major_version_b < kMajorVersionBValue) {
    major_version_b = kMajorVersionBValue;
    minor_version_a = kMinorVersionAValue;
    minor_version_b = kMinorVersionBValue;
  } else if (major_version_b > kMajorVersionBValue) {
    return;
  }

  if (!minor_version_a.is_number() || minor_version_a < kMinorVersionAValue) {
    minor_version_a = kMinorVersionAValue;
    minor_version_b = kMinorVersionBValue;
  } else if (minor_version_a > kMinorVersionAValue) {
    return;
  }

  if (!minor_version_b.is_number() || minor_version_b < kMinorVersionBValue) {
    minor_version_b = kMinorVersionBValue;
  } else if (minor_version_b > kMinorVersionBValue) {
    return;
  }

  // Add missing values.

  if (auto& entry = global_entry[kConfigTabWidthKey.data()];
      !entry.is_number()) {
    entry = kDefaultConfigTabWidthValue;
  }

  if (auto& entry = main_entry[kAddressTableDirectoryPathKey.data()];
      !entry.is_string()) {
    entry = kDefaultAddressTableDirectory;
  }
}

nlohmann::json
ParseConfig(
    const std::filesystem::path& config_path
) {
  // Create the config file if it doesn't exist.
  if (!std::filesystem::exists(config_path)) {
    std::ofstream config_file(config_path);
    config_file << u8"{}" << std::endl;
  }

  // Read the config file for processing, if all other conditions are good.
  nlohmann::json config_json;

  if (std::ifstream config_file(config_path);
      config_file) {
    config_json = nlohmann::json::parse(config_file);
  }

  AddMissingConfigEntries(config_json);

  // Write to the config file any new default values.
  if (std::ofstream config_file(config_path);
      config_file) {
    int tab_width =
        config_json[kGlobalEntryKey.data()][kConfigTabWidthKey.data()];

    config_file << std::setw(tab_width)
        << config_json
        << std::endl;
  }

  return config_json;
}

nlohmann::json&
GetConfig(void) {
  static nlohmann::json config = ParseConfig(
      GetConfigPath()
  );
  return config;
}

std::filesystem::path
ParseAddressTableDirectoryPath(void) {
  nlohmann::json& config = GetConfig();
  auto& address_table_path_raw_value =
      config[kMainEntryKey.data()][kAddressTableDirectoryPathKey.data()];

  if (!address_table_path_raw_value.is_string()) {
    address_table_path_raw_value = kDefaultAddressTableDirectory.data();
  }

  std::filesystem::path address_table_directory_path =
      address_table_path_raw_value.get<std::string>();

  return address_table_directory_path;
}

} // namespace

const std::filesystem::path&
GetAddressTableDirectoryPath(void) {
  static std::filesystem::path address_table_path(
      ParseAddressTableDirectoryPath()
  );
  return address_table_path;
}

} // namespace mapi
