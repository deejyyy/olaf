target_sources(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/stm32g0xx_hal_msp.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/stm32g0xx_it.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/stm32g0xx_nucleo.c"
    # "${CMAKE_CURRENT_SOURCE_DIR}/syscalls.c"
    # "${CMAKE_CURRENT_SOURCE_DIR}/sysmem.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/system_stm32g0xx.c"
)