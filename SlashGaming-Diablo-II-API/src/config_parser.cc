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
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with Diablo II (or a modified version of that game and its
 *  libraries), containing parts covered by the terms of Blizzard End User
 *  License Agreement, the licensors of this Program grant you additional
 *  permission to convey the resulting work. This additional permission is
 *  also extended to any combination of expansions, mods, and remasters of
 *  the game, provided that the game or its libraries do not link to this
 *  Program.
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any Glide wrapper (or a modified version of that library),
 *  containing parts not covered by a compatible license, provided that the
 *  wrapper does not link to this Program, the licensors of this Program
 *  grant you additional permission to convey the resulting work.
 */

#include "config_parser.h"

#include <string>
#include <string_view>

#include <boost/filesystem.hpp>
#include <nlohmann/json.hpp>

namespace sgd2mapi {

namespace {

constexpr std::string_view kMainEntryKey = "SGD2MAPI";

constexpr std::string_view kMetaDataKey = "!!!Metadata (Do not modify)!!!";

// Note that this signifies the last version where the config formatting and
// entries were updated. These values do not need to change with respect to API
// file version!
constexpr std::string_view kMajorVersionAKey = "Major Version A";
constexpr int kMajorVersionAValue = 0;
constexpr std::string_view kMajorVersionBKey = "Major Version B";
constexpr int kMajorVersionBValue = 1;
constexpr std::string_view kMinorVersionAKey = "Minor Version A";
constexpr int kMinorVersionAValue = 0;
constexpr std::string_view kMinorVersionBKey = "Minor Version B";
constexpr int kMinorVersionBValue = 0;

constexpr std::string_view kAddressTablePathKey =
    "Address Table Directory Path";
constexpr std::string_view kDefaultAddressTableDirectory = "Address Table";

void AddMissingConfigEntries(nlohmann::json& config_json) noexcept {
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
  if (auto& entry = main_entry[kAddressTablePathKey.data()];
      !entry.is_string()) {
    entry = kDefaultAddressTableDirectory;
  }
}

nlohmann::json ParseConfig(
    const boost::filesystem::path& config_path
) noexcept {
  // Create the config file if it doesn't exist.
  if (!boost::filesystem::exists(config_path)) {
    boost::filesystem::ofstream config_file(config_path);
    config_file << "{}" << std::endl;
  }

  // Read the config file, if read permissions are enabled, for processing.
  nlohmann::json config_json;

  if (boost::filesystem::ifstream config_file(config_path);
      config_file.good()) {
    config_json = nlohmann::json::parse(config_file);
  }

  AddMissingConfigEntries(config_json);

  // Write to the config file any new default values.
  if (boost::filesystem::ofstream config_file(config_path);
      config_file.good()) {
    config_file << config_json << std::endl;
  }

  return config_json.at(kMainEntryKey.data());
}

} // namespace

ConfigParser::ConfigParser(
    const boost::filesystem::path& config_path
) noexcept
    : config_path_(config_path) {
  nlohmann::json main_entry = ParseConfig(config_path);
  address_table_path_ =
      main_entry.at(kAddressTablePathKey.data()).get<std::string>();
}

ConfigParser& ConfigParser::GetInstance() noexcept {
  static ConfigParser instance(kConfigPath.data());
  return instance;
}

const boost::filesystem::path&
ConfigParser::address_table_path() const noexcept {
  return address_table_path_;
}

const boost::filesystem::path&
ConfigParser::config_path() const noexcept {
  return config_path_;
}

} // namespace sgd2mapi
