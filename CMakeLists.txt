# SlashGaming Diablo II Modding API
# Copyright (C) 2018-2021  Mir Drualga
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as published
# by the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# Additional permissions under GNU Affero General Public License version 3
# section 7
#
# If you modify this Program, or any covered work, by linking or combining
# it with Diablo II (or a modified version of that game and its
# libraries), containing parts covered by the terms of Blizzard End User
# License Agreement, the licensors of this Program grant you additional
# permission to convey the resulting work. This additional permission is
# also extended to any combination of expansions, mods, and remasters of
# the game.
#
# If you modify this Program, or any covered work, by linking or combining
# it with any Graphics Device Interface (GDI), DirectDraw, Direct3D,
# Glide, OpenGL, or Rave wrapper (or modified versions of those
# libraries), containing parts not covered by a compatible license, the
# licensors of this Program grant you additional permission to convey the
# resulting work.
#
# If you modify this Program, or any covered work, by linking or combining
# it with any library (or a modified version of that library) that links
# to Diablo II (or a modified version of that game and its libraries),
# containing parts not covered by a compatible license, the licensors of
# this Program grant you additional permission to convey the resulting
# work.

cmake_minimum_required(VERSION 3.11)

# Name of the project, also is the name of the file
project(SGD2MAPI)

# Define requirements for C
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Define requirements for C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# External dependencies
add_subdirectory(external)

# Enable NASM
set(CMAKE_ASM_NASM_OBJECT_FORMAT win32)
enable_language(ASM_NASM)

# Remove MinGW compiled binary "lib" prefix
if (MINGW)
    set(CMAKE_IMPORT_LIBRARY_PREFIX "")
    set(CMAKE_SHARED_LIBRARY_PREFIX "")
    set(CMAKE_STATIC_LIBRARY_PREFIX "")
endif (MINGW)

# List all of the source files here
set(PROJECT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SlashGaming-Diablo-II-API")

set(RESOURCE_FILES
    "${PROJECT_DIR}/resource/resource.rc"
)

set(SOURCE_FILES
    ${RESOURCE_FILES}

    "${PROJECT_DIR}/src/cxx/backend/game_address_table/game_address_locator/game_offset_locator.cc"
    "${PROJECT_DIR}/src/cxx/backend/game_address_table/game_address_locator/game_ordinal_locator.cc"
    "${PROJECT_DIR}/src/cxx/backend/game_function/esi_function.cc"
    "${PROJECT_DIR}/src/cxx/backend/game_function/fastcall_function.cc"
    "${PROJECT_DIR}/src/cxx/backend/game_function/stdcall_function.cc"
    "${PROJECT_DIR}/src/cxx/backend/game_function/thiscall_function.cc"
    "${PROJECT_DIR}/src/cxx/backend/architecture_opcode.cc"
    "${PROJECT_DIR}/src/cxx/backend/game_address_table.cc"
    "${PROJECT_DIR}/src/cxx/backend/game_library.cc"
    "${PROJECT_DIR}/src/cxx/game_constant/d2_client_game_type.cc"
    "${PROJECT_DIR}/src/cxx/game_constant/d2_difficulty_level.cc"
    "${PROJECT_DIR}/src/cxx/game_constant/d2_draw_effect.cc"
    "${PROJECT_DIR}/src/cxx/game_constant/d2_screen_open_mode.cc"
    "${PROJECT_DIR}/src/cxx/game_constant/d2_text_color.cc"
    "${PROJECT_DIR}/src/cxx/game_constant/d2_text_font.cc"
    "${PROJECT_DIR}/src/cxx/game_constant/d2_video_mode.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2client/d2client_draw_centered_unicode_text.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2cmp/d2cmp_get_cel_from_cel_context.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2common/d2common_get_global_belt_record.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2common/d2common_get_global_belt_slot_position.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2common/d2common_get_global_equipment_slot_layout.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2common/d2common_get_global_inventory_grid_layout.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2common/d2common_get_global_inventory_position.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2gfx/d2gfx_draw_cel_context.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2gfx/d2gfx_draw_rectangle.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2lang/d2lang_get_string_by_index.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2lang/d2lang_unicode_ascii_to_unicode.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2lang/d2lang_unicode_strcat.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2lang/d2lang_unicode_strcmp.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2lang/d2lang_unicode_strcpy.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2lang/d2lang_unicode_strlen.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2lang/d2lang_unicode_strncat.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2lang/d2lang_unicode_strncmp.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2lang/d2lang_unicode_strncpy.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2lang/d2lang_unicode_tolower.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2lang/d2lang_unicode_toupper.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2lang/d2lang_unicode_unicode_to_utf8.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2lang/d2lang_unicode_utf8_to_unicode.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2win/d2win_draw_unicode_text.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2win/d2win_get_pop_up_unicode_text_width_and_height.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2win/d2win_get_unicode_text_draw_width.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2win/d2win_get_unicode_text_n_draw_width.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2win/d2win_load_cel_file.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2win/d2win_load_mpq.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2win/d2win_set_pop_up_unicode_text.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2win/d2win_set_unicode_text_font.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2win/d2win_unload_cel_file.cc"
    "${PROJECT_DIR}/src/cxx/game_function/d2win/d2win_unload_mpq.cc"
    "${PROJECT_DIR}/src/cxx/game_function/fog/fog_alloc_client_memory.cc"
    "${PROJECT_DIR}/src/cxx/game_function/fog/fog_free_client_memory.cc"
    "${PROJECT_DIR}/src/cxx/game_function/storm/storm_s_file_close_archive.cc"
    "${PROJECT_DIR}/src/cxx/game_function/storm/storm_s_file_open_archive.cc"
    "${PROJECT_DIR}/src/cxx/game_patch/game_back_branch_patch.cc"
    "${PROJECT_DIR}/src/cxx/game_patch/game_branch_patch.cc"
    "${PROJECT_DIR}/src/cxx/game_patch/game_buffer_patch.cc"
    "${PROJECT_DIR}/src/cxx/game_patch/game_nop_patch.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_belt_record/d2_belt_record_api.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_belt_record/d2_belt_record_struct.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_belt_record/d2_belt_record_view.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_belt_record/d2_belt_record_wrapper.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_cel/d2_cel_api.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_cel/d2_cel_struct.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_cel/d2_cel_view.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_cel/d2_cel_wrapper.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_cel_context/d2_cel_context_api.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_cel_context/d2_cel_context_struct.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_cel_context/d2_cel_context_view.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_cel_context/d2_cel_context_wrapper.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_cel_file/d2_cel_file_api.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_cel_file/d2_cel_file_struct.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_cel_file/d2_cel_file_view.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_cel_file/d2_cel_file_wrapper.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_equipment_layout/d2_equipment_layout_api.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_equipment_layout/d2_equipment_layout_struct.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_equipment_layout/d2_equipment_layout_view.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_equipment_layout/d2_equipment_layout_wrapper.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_grid_layout/d2_grid_layout_api.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_grid_layout/d2_grid_layout_struct.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_grid_layout/d2_grid_layout_view.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_grid_layout/d2_grid_layout_wrapper.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_inventory_record/d2_inventory_record_api.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_inventory_record/d2_inventory_record_struct.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_inventory_record/d2_inventory_record_view.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_inventory_record/d2_inventory_record_wrapper.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_mpq_archive/d2_mpq_archive_api.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_mpq_archive/d2_mpq_archive_struct.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_mpq_archive/d2_mpq_archive_view.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_mpq_archive/d2_mpq_archive_wrapper.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_mpq_archive_handle/d2_mpq_archive_handle_api.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_mpq_archive_handle/d2_mpq_archive_handle_struct.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_mpq_archive_handle/d2_mpq_archive_handle_view.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_mpq_archive_handle/d2_mpq_archive_handle_wrapper.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_positional_rectangle/d2_positional_rectangle_api.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_positional_rectangle/d2_positional_rectangle_struct.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_positional_rectangle/d2_positional_rectangle_view.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_positional_rectangle/d2_positional_rectangle_wrapper.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_unicode_char/d2_unicode_char_api.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_unicode_char/d2_unicode_char_struct.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_unicode_char/d2_unicode_char_view.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_unicode_char/d2_unicode_char_wrapper.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_unicode_char/d2_unicode_string_api.cc"
    "${PROJECT_DIR}/src/cxx/game_struct/d2_unicode_char/d2_unicode_string_view_api.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/bnclient/bnclient_gateway_domain_name.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/bnclient/bnclient_gateway_ip_v4_address.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2client/d2client_difficulty_level.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2client/d2client_game_type.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2client/d2client_general_display_height.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2client/d2client_general_display_width.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2client/d2client_general_play_area_camera_shift_x.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2client/d2client_ingame_mouse_position_x.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2client/d2client_ingame_mouse_position_y.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2client/d2client_inventory_arrange_mode.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2client/d2client_is_automap_open.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2client/d2client_is_game_menu_open.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2client/d2client_is_help_screen_open.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2client/d2client_is_new_skill_button_pressed.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2client/d2client_is_new_stats_button_pressed.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2client/d2client_screen_open_mode.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2client/d2client_screen_shift_x.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2client/d2client_screen_shift_y.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2common/d2common_global_belts_txt.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2common/d2common_global_inventory_txt.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2common/d2common_global_inventory_txt_records_count.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2ddraw/d2ddraw_bit_block_height.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2ddraw/d2ddraw_bit_block_width.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2ddraw/d2ddraw_cel_display_left.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2ddraw/d2ddraw_cel_display_right.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2ddraw/d2ddraw_display_height.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2ddraw/d2ddraw_display_width.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2direct3d/d2direct3d_display_height.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2direct3d/d2direct3d_display_width.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2gdi/d2gdi_bit_block_height.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2gdi/d2gdi_bit_block_width.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2gdi/d2gdi_cel_display_left.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2gdi/d2gdi_cel_display_right.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2gfx/d2gfx_is_windowed_mode.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2gfx/d2gfx_resolution_mode.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2gfx/d2gfx_video_mode.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2gfx/d2gfx_window_handle.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2glide/d2glide_display_height.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2glide/d2glide_display_width.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2win/d2win_menu_main_mouse_position_x.cc"
    "${PROJECT_DIR}/src/cxx/game_variable/d2win/d2win_menu_main_mouse_position_y.cc"
    "${PROJECT_DIR}/src/cxx/helper/d2_determine_video_mode.cc"
    "${PROJECT_DIR}/src/cxx/helper/rgba_32bit_color.cc"
    "${PROJECT_DIR}/src/cxx/default_game_library.cc"
    "${PROJECT_DIR}/src/cxx/game_address.cc"
    "${PROJECT_DIR}/src/cxx/game_executable.cc"
    "${PROJECT_DIR}/src/cxx/game_patch.cc"
    "${PROJECT_DIR}/src/cxx/game_version.cc"
    "${PROJECT_DIR}/src/dll_main.cc"
    "${PROJECT_DIR}/src/cxx/backend/game_address_table/game_address_table_impl.cc"
    "${PROJECT_DIR}/src/cxx/backend/game_address_table/game_address_locator/game_address_locator.cc"
    "${PROJECT_DIR}/src/cxx/backend/game_address_table/game_address_locator/game_exported_name_locator.cc"
    "${PROJECT_DIR}/src/cxx/backend/d2se/d2se_ini.cc"
    "${PROJECT_DIR}/src/cxx/backend/game_version/game_version_file_signature.cc"
    "${PROJECT_DIR}/src/cxx/backend/d2se/d2se_file_signature.cc"
    "${PROJECT_DIR}/src/cxx/backend/d2se/d2se_game_version.cc"
    "${PROJECT_DIR}/src/cxx/file/file_version_info.cc"
    "${PROJECT_DIR}/src/cxx/backend/file/fixed_file_version.cc"
    "${PROJECT_DIR}/src/cxx/backend/game_version/game_version_file_version.cc"
    "${PROJECT_DIR}/src/cxx/file/file_pe_signature.cc"
)

# Output static LIB
add_library(lib${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_include_directories(lib${PROJECT_NAME} PUBLIC "${PROJECT_DIR}/include")

target_link_libraries(lib${PROJECT_NAME} PUBLIC libMDCc libMDCcpp98 shlwapi version)
add_dependencies(lib${PROJECT_NAME} libMDCc libMDCcpp98)

# Output DLL
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

target_compile_definitions(${PROJECT_NAME} PRIVATE SGD2MAPI_DLLEXPORT)
target_compile_definitions(${PROJECT_NAME} INTERFACE SGD2MAPI_DLLIMPORT)

target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_DIR}/include")

target_link_libraries(${PROJECT_NAME} PUBLIC libMDCc libMDCcpp98 shlwapi version)
add_dependencies(${PROJECT_NAME} libMDCc libMDCcpp98)

# MSVC options
if (MSVC)
    target_compile_definitions(${PROJECT_NAME} PRIVATE _CRT_SECURE_NO_WARNINGS)
endif (MSVC)

# MinGW options
if (MINGW)
    target_compile_options(${PROJECT_NAME} PRIVATE "-std=c++20")
endif (MINGW)

# Project source listing
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

install(TARGETS ${PROJECT_NAME} lib${PROJECT_NAME})

