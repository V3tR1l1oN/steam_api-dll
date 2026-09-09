cmake_minimum_required(VERSION 3.15)
project(steam_api VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT WIN32)
    message(FATAL_ERROR "This project targets Windows (x86) only")
endif()

set(SOURCES
    src/core/steam_api.cpp
    src/core/exports.cpp
    src/core/proxy.cpp
    src/core/diag_log.cpp
    src/core/dummy_funcs.cpp
    src/core/dummy_code.cpp
    src/core/large_dummy.cpp
    src/core/text_padding.cpp
    src/core/rdata_padding.cpp
    src/vgui/vgui_stubs.cpp
    src/interfaces/steam_user.cpp
    src/interfaces/steam_friends.cpp
    src/interfaces/steam_networking.cpp
    src/interfaces/steam_matchmaking.cpp
    src/interfaces/steam_userstats.cpp
    src/interfaces/steam_utils.cpp
    src/interfaces/steam_apps.cpp
    src/interfaces/steam_music.cpp
    src/interfaces/sdk_guard.cpp
)

# Ресурс для точного соответствия размеру оригинальной DLL
set(RESOURCES src/core/padding.rc)
set_source_files_properties(src/core/padding.rc PROPERTIES LANGUAGE RC)

add_library(steam_api SHARED ${SOURCES} ${RESOURCES})

target_include_directories(steam_api PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_definitions(steam_api PRIVATE
    WIN32_LEAN_AND_MEAN
    NOMINMAX
    _CRT_SECURE_NO_WARNINGS
    STEAM_API_EXPORTS
)

if(MSVC)
    target_compile_options(steam_api PRIVATE /W0 /Zc:threadSafeInit-)
    set_property(TARGET steam_api PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    target_link_options(steam_api PRIVATE /DEF:${CMAKE_CURRENT_SOURCE_DIR}/src/core/exports.def /GUARD:NO /MAP:${CMAKE_CURRENT_BINARY_DIR}/steam_api.map)
    set_target_properties(steam_api PROPERTIES OUTPUT_NAME "steam_api")
endif()

target_link_libraries(steam_api PRIVATE ws2_32)
