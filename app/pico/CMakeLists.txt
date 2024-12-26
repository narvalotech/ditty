cmake_minimum_required(VERSION 3.16)

pico_sdk_init()

add_executable(pico main.c)

# Link with the pico stdlib
target_link_libraries(pico pico_stdlib)

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(pico)

# Enable USB serial
pico_enable_stdio_usb(pico 1)
pico_enable_stdio_uart(pico 0)