cmake_minimum_required(VERSION 3.13)

# Set the below line if the Pico SDK is not in your system path
#set(PICO_SDK_PATH "/home/stephen/Documents/picodev/pico/pico-sdk")
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(mavlink_periph C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_FLAGS  "${CMAKE_CXX_FLAGS} -Wno-address-of-packed-member")

pico_sdk_init()

add_executable(mavlink_periph
        main.c
        )

# STDIO on USB or UART?
pico_enable_stdio_uart(mavlink_periph 0)
pico_enable_stdio_usb(mavlink_periph 1)

# pull in common dependencies
target_link_libraries(mavlink_periph pico_stdlib hardware_adc)

# create map/bin/hex file etc.
pico_add_extra_outputs(mavlink_periph)

