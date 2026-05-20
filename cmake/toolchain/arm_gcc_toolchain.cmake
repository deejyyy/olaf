set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR cortex-m0plus)

set(CMAKE_OBJCOPY "arm-none-eabi-objcopy")
set(CMAKE_OBJDUMP "arm-none-eabi-objdump")
set(CMAKE_SIZE "arm-none-eabi-size")

set(CMAKE_C_COMPILER "arm-none-eabi-gcc")
set(CMAKE_CXX_COMPILER "arm-none-eabi-g++")
set(CMAKE_ASM_COMPILER "arm-none-eabi-gcc")

set(CMAKE_C_COMPILER_WORKS 1 CACHE INTERNAL "")
set(CMAKE_CXX_COMPILER_WORKS 1 CACHE INTERNAL "")

set(ARCHITECTURE_FLAGS "-mcpu=cortex-m0plus -mfloat-abi=soft -mthumb")

# Set these as cache variables to ensure they're used during compiler detection
set(CMAKE_ASM_FLAGS_INIT        "${ARCHITECTURE_FLAGS}" CACHE STRING "Initial ASM flags")
set(CMAKE_C_FLAGS_INIT          "${ARCHITECTURE_FLAGS}" CACHE STRING "Initial C flags")
set(CMAKE_CXX_FLAGS_INIT        "${ARCHITECTURE_FLAGS}" CACHE STRING "Initial CXX flags")
set(CMAKE_EXE_LINKER_FLAGS_INIT "${ARCHITECTURE_FLAGS}" CACHE STRING "Initial Linker flags")
