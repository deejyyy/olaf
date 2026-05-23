cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME olaf_app)

project(${PROJECT_NAME}
    VERSION 1.0
    DESCRIPTION "An application for the OLAF project"
    LANGUAGES C CXX ASM
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} "source/main.c")

# if(CFG_BUILD_TYPE STREQUAL "DEBUG_ENABLED")
#     target_compile_definitions(${PROJECT_NAME} PRIVATE DEBUG_ENABLED)
#     message(STATUS "Debugging enabled")
# elseif(CFG_BUILD_TYPE STREQUAL "DEBUG_DISABLED")
#     message(STATUS "Debugging disabled")
# else()
#     message(FATAL_ERROR "Unknown build type: ${CFG_BUILD_TYPE}. Use DEBUG_ENABLED or DEBUG_DISABLED.")
# endif()

set(FETCHCONTENT_BASE_DIR "${CMAKE_SOURCE_DIR}/build/custom_deps")

include(FetchContent)

FetchContent_Declare(
    stm32cubeg0_populate
    GIT_REPOSITORY  git@github.com:STMicroelectronics/STM32CubeG0.git
    GIT_TAG         master
    SOURCE_DIR      ${CMAKE_CURRENT_SOURCE_DIR}/lib/stm32cubeg0
)

FetchContent_MakeAvailable(stm32cubeg0_populate)

include(cmake/platform/platform.cmake)
include(cmake/compile_options/compile_options_stm32g0xx.cmake)

add_subdirectory(board/bsp)
add_subdirectory(board/hal)
add_subdirectory(source)

# Post-build command to generate HEX file from ELF
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${PROJECT_NAME}> $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.hex
    COMMENT "Generating HEX file from ELF..."
)
