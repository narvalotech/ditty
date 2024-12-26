cmake_minimum_required(VERSION 3.16)

set(PLATFORM "pico" CACHE STRING "Target platform (HW version or native)")

if(${PLATFORM} STREQUAL "pico")
    include(vendor/pico-sdk/pico_sdk_init.cmake)
endif()

project(ditty)

if(${PLATFORM} STREQUAL "pico")
    pico_sdk_init()
endif()

add_executable(${PROJECT_NAME} app/main.c)

if(${PLATFORM} STREQUAL "pico")
    include(cmake/pico.cmake)
endif()
