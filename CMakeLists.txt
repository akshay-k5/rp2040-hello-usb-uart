cmake_minimum_required(VERSION 3.13)

# Include the SDK
include(pico_sdk_import.cmake)

project(hello_uart_usb C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(hello_uart_usb
    hello_uart_usb.c
)

# Link necessary libraries
target_link_libraries(hello_uart_usb
    pico_stdlib
)

# Create map/bin/hex/uf2 file
pico_add_extra_outputs(hello_uart_usb)

# Enable both USB and UART stdio
# By enabling both, printf will send data to both interfaces.
pico_enable_stdio_usb(hello_uart_usb 1)
pico_enable_stdio_uart(hello_uart_usb 1)
