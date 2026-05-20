/*******************************************************************************
* BSP HAL GPIO Source File
* Copyright (c) 2026 Deej. All rights reserved.
*******************************************************************************/

/*******************************************************************************
 * Includes                                                                    *
 ******************************************************************************/
/* Project Includes */
#include "bsp_hal_config_gpio.h"

/* Hardware Includes */
#include "stm32g0xx_hal.h"

/*******************************************************************************
 * Public Macros                                                               *
 ******************************************************************************/

/*******************************************************************************
 * Private Variables                                                           *
 ******************************************************************************/

/*******************************************************************************
 * Private Function Declaration                                                *
 ******************************************************************************/

/*******************************************************************************
 * Private Function Definition                                                 *
 ******************************************************************************/

/*******************************************************************************
 * Public Function Definition                                                  *
 ******************************************************************************/

GPIO_InitTypeDef gpio_init = {
    .Pin = GPIO_PIN_5,
    .Mode = GPIO_MODE_OUTPUT_PP,
    .Pull = GPIO_PULLUP,
    .Speed = GPIO_SPEED_FREQ_HIGH,
};

void bspHalConfigGpio_init( void )
{
    /* Enable the GPIO Clock */
    /* -1- Enable GPIO Clock (to be able to program the configuration registers) */
    __HAL_RCC_GPIOA_CLK_ENABLE();
    // GPIO_InitStruct.Pin = GPIO_PIN_5;
    // GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    // GPIO_InitStruct.Pull  = GPIO_PULLUP;
    // GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    // HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // /* -2- Configure IO in output push-pull mode to drive external LEDs */
    HAL_GPIO_Init(GPIOA, &gpio_init);
}

