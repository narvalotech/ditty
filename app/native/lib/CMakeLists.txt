cmake_minimum_required(VERSION 3.16)

# Generate a corresponding .c for each XBM file in the current directory. Then
# add the list to a header for the application.

set(RAYLIB_DIR ${CMAKE_SOURCE_DIR}/vendor/raylib)

add_library(ngl
        ngl.c
)

target_include_directories(ngl PRIVATE
    ${RAYLIB_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(ngl PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(ngl
    ${RAYLIB_DIR}/lib/libraylib.a)

target_compile_definitions(ngl PRIVATE GRAPHICS_API_OPENGL_33)
target_compile_options(ngl PRIVATE -Werror)
target_link_libraries(ngl m pthread dl rt)
