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
typedef struct
{
    GPIO_TypeDef *port;
    GPIO_InitTypeDef config;
} tGpioConfig;

/*******************************************************************************
 * Private Types                                                               *
 ******************************************************************************/

tGpioConfig gpio_configs[BSP_HAL_CONFIG_GPIO_MAX] = {
    [BSP_HAL_CONFIG_GPIO_LED] = {
        .port = BSP_HAL_CONFIG_GPIO_PORT_LED,
        .config =
        {
            .Pin = BSP_HAL_CONFIG_GPIO_PIN_LED,
            .Mode = GPIO_MODE_OUTPUT_PP,
            .Pull = GPIO_PULLUP,
            .Speed = GPIO_SPEED_FREQ_HIGH,
        },
    },
    [BSP_HAL_CONFIG_GPIO_BUTTON] = {
        .port = BSP_HAL_CONFIG_GPIO_PORT_BUTTON,
        .config =
        {
            .Pin = BSP_HAL_CONFIG_GPIO_PIN_BUTTON,
            .Mode = GPIO_MODE_INPUT,
            .Pull = GPIO_PULLUP,
        },
    },
};

/*******************************************************************************
 * Private Function Declaration                                                *
 ******************************************************************************/
static void configureGpio( void );

/*******************************************************************************
 * Private Function Definition                                                 *
 ******************************************************************************/
static void configureGpio( void )
{
    /* Enable the GPIO Clock */
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();

    // /* -2- Configure IO in output push-pull mode to drive external LEDs */
    for( eGpioIds id = 0; id < BSP_HAL_CONFIG_GPIO_MAX; id++)
    {
        HAL_GPIO_Init(gpio_configs[id].port, &gpio_configs[id].config);
    }

    // Enable and set EXTI line 4_15 Interrupt
    HAL_NVIC_SetPriority(EXTI4_15_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);
}

/*******************************************************************************
 * Public Function Definition                                                  *
 ******************************************************************************/
void bspHalConfigGpio_init( void )
{
    configureGpio();
}
