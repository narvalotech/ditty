cmake_minimum_required(VERSION 3.16)

# Generate a corresponding .c for each XBM file in the current directory. Then
# add the list to a header for the application.

function(gen_image_c imgname)
    configure_file(img.c.in ${imgname}.c @ONLY)
endfunction()

file(GLOB xbms "*.xbm")

foreach(file ${xbms})
    get_filename_component(image_name ${file} NAME_WE)
    list(APPEND image_list ${image_name})
endforeach()

foreach(image ${image_list})
    gen_image_c(${image})
    list(APPEND image_c_list ${image}.c)
    list(APPEND image_list_init "img_${image}")
endforeach()

# Append the list of generated image objects to a public header
string(REPLACE ";" ", " image_list_init "${image_list_init}")
set(image_h_list ${image_list_init})
configure_file(images.h.in images/images.h @ONLY)

message(STATUS "Generated images: ${image_list_init}")

add_library(images
    ${image_c_list}
)

target_link_libraries(images ngl)

target_include_directories(images PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(images PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR})
