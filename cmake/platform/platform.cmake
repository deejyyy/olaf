# CMake file for library and platform configuration

target_include_directories(${PROJECT_NAME} PUBLIC
    # Drivers
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/CMSIS/Include"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/CMSIS/Device/ST/STM32G0xx/Include"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/CMSIS/Device/ST/STM32G0xx/Include/Legacy"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/STM32G0xx_HAL_Driver/Inc"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/STM32G0xx_HAL_Driver/Inc/Legacy"
    # Middlewares
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Middlewares/Third_Party/FreeRTOS/Source/include"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0"
)

target_sources(${PROJECT_NAME} PRIVATE
    "${CMAKE_SOURCE_DIR}/board/startup/startup_stm32g0b1xx.S"
    # Drivers
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_cortex.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_dma.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_dma_ex.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_flash.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_flash_ex.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_gpio.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_pwr.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_pwr_ex.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_rcc.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_rcc_ex.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_tim.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_tim_ex.c"
    # Middlewares
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Middlewares/Third_Party/FreeRTOS/Source/event_groups.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Middlewares/Third_Party/FreeRTOS/Source/list.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Middlewares/Third_Party/FreeRTOS/Source/queue.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Middlewares/Third_Party/FreeRTOS/Source/tasks.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Middlewares/Third_Party/FreeRTOS/Source/timers.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os2.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0/port.c"
    "${CMAKE_SOURCE_DIR}/lib/stm32cubeg0/Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.c"
)
