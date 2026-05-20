# Linker options
target_link_options(${PROJECT_NAME} PRIVATE
    -T${LINKER_SCRIPT}
    --specs=nano.specs
    -Wl,-Map=${CMAKE_BINARY_DIR}/${PROJECT_NAME}.map
    -Wl,--gc-sections
)

target_compile_options(${PROJECT_NAME} PRIVATE
    -DUSE_HAL_DRIVER
    -DDEBUG
    -DSTM32
    -DSTM32G0
    -DSTM32G0B1xx
)
