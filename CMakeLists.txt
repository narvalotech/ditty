cmake_minimum_required(VERSION 3.16)

set(PLATFORM "pico" CACHE STRING "Target platform (HW version or native)")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(${PLATFORM} STREQUAL "pico")
    # Ugly AF.
    include(${CMAKE_SOURCE_DIR}/vendor/pico-sdk/pico_sdk_init.cmake)
endif()

project(ditty)

if(${PLATFORM} STREQUAL "pico")
    pico_sdk_init()
    add_subdirectory(app/pico)
else()
    add_subdirectory(app/native)
endif()
