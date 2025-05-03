cmake_minimum_required(VERSION 3.16)

add_subdirectory(images)
add_subdirectory(lib)

add_executable(native
    main.c
)

target_include_directories(native PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(native PRIVATE -Werror)

target_link_libraries(native images ngl)