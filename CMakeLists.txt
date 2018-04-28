cmake_minimum_required(VERSION 2.6)
project(SlashGaming-Diablo-II-Modding-API)

set(_src_root_path "${SlashGaming-Diablo-II-Modding-API_SOURCE_DIR}/src")
file(
    GLOB_RECURSE _source_list 
    LIST_DIRECTORIES false
    "${_src_root_path}/*.c*"
    "${_src_root_path}/*.h*"
)

ADD_LIBRARY (SlashGaming-Diablo-II-Modding-API SHARED ${_source_list})

foreach(_source IN ITEMS ${_source_list})
    get_filename_component(_source_path "${_source}" PATH)
    file(RELATIVE_PATH _source_path_rel "${_src_root_path}" "${_source_path}")
    string(REPLACE "/" "\\" _group_path "${_source_path_rel}")
    source_group("${_group_path}" FILES "${_source}")
endforeach()
