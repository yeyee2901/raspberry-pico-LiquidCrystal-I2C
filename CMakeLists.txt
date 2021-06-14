# REQUIREMENT
# 1. Install cmake, gcc-arm-none-eabi, build-essentials
# 2. Configure cmake tools di vs-code (extensions - configure environment
#					add $PICO_SDK_PATH ke new kit)
# 3. Instruksi lebih detail lihat pdf "Getting Started With Raspberry Pi Pico"

cmake_minimum_required( VERSION 3.12 )

# INCLUDE THE SDK - HARUS SEBELUM project declaration
# - Linux/MacOS/Unix: $PICO_SDK_PATH seharusnya terdefinisi di .bashrc
# - Windows: PICO_SDK_PATH harus di set sebagai environment variable
# jika masih tidak bisa, pakai path manual (absolute path)
include(
    "./pico_sdk_import.cmake" 
)

project( LCD_i2c )

# INIT harus SETELAH project declaration
# yang dilakukan oleh init adalah import semua source SDK
# agar dapat dideteksi autocomplete & saat compile time
pico_sdk_init()

# PROJECT CONFIG
include_directories(./inc)
file(GLOB SOURCES "./src/*.c")
add_executable( ${CMAKE_PROJECT_NAME} ${SOURCES} )


# LINK LIBRARY (yang diperlukan)
target_link_libraries( ${CMAKE_PROJECT_NAME}
	pico_stdlib
	pico_multicore
	hardware_i2c
)

# GENERATE UF2 (uf2 mirip .hex file, akan di upload ke pico)
pico_add_extra_outputs( ${CMAKE_PROJECT_NAME} )

# STDIO (pilihan hanya salah satu! USB-CDC atau UART)
# jika tidak diperlukan bisa di disable
pico_enable_stdio_usb( ${CMAKE_PROJECT_NAME} 1 )
pico_enable_stdio_uart( ${CMAKE_PROJECT_NAME} 0 )
