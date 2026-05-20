# CMake file for library and platform configuration

target_include_directories(${PROJECT_NAME} PUBLIC
    # Drivers
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/CMSIS/Include"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/CMSIS/Device/ST/STM32G0xx/Include"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/CMSIS/Device/ST/STM32G0xx/Include/Legacy"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/STM32G0xx_HAL_Driver/Inc"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/STM32G0xx_HAL_Driver/Inc/Legacy"
    # Middlewares
)

target_sources(${PROJECT_NAME} PRIVATE
    "${CMAKE_SOURCE_DIR}/board/startup/startup_stm32g0b1xx.S"
    # Drivers
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_cortex.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_flash.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_flash_ex.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_gpio.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_pwr.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_pwr_ex.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_rcc.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_rcc_ex.c"
    # Middlewares
)
