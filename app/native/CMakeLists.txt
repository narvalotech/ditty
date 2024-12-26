cmake_minimum_required(VERSION 3.16)

set(RAYLIB_DIR ${CMAKE_SOURCE_DIR}/vendor/raylib)

add_executable(native main.c)

target_include_directories(native PRIVATE
    ${RAYLIB_DIR}/include)

target_link_libraries(native
    ${RAYLIB_DIR}/lib/libraylib.a)

target_link_libraries(native m pthread dl rt)
target_compile_definitions(native PRIVATE GRAPHICS_API_OPENGL_33)