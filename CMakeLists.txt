cmake_minimum_required(VERSION 3.14)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
project(ultrasound)
pico_sdk_init()
if (TARGET tinyusb_device)
    add_executable(main main.c)
    add_library(uss uss.c uss.h)
    target_link_libraries(uss pico_stdlib)
    target_link_libraries(main uss)

    pico_add_extra_outputs(main)
    
    pico_enable_stdio_usb(main 1)

    elseif(PICO_ON_DEVICE)
        message(WARNING "not building because TinyUSB submodule is not initialized in the SDK")
endif()