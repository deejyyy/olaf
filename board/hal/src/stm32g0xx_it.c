/**
  ******************************************************************************
  * @file    GPIO/GPIO_IOToggle/Src/stm32g0xx_it.c
  * @author  MCD Application Team
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

#include "stm32g0xx_it.h"
#include "main.h"
#include "bsp_hal_config_gpio.h"
#include "button_control.h"

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

static volatile uint32_t g_button_last_ms = 0;
static uint32_t g_button_current_ms = 0;
static volatile uint8_t g_button_pressed = 0;

/* Private macro -------------------------------------------------------------*/
#define BUTTON_POSITION_INVALID 0xFF
#define MAX_GPIO_NUM 16

#define SHORT_PRESS_MS  50U
#define LONG_PRESS_MS   2000U

/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
void EXTI_RegisterCallback( uint16_t gpioPin, tInterruptCb callback );
static tInterruptCb exti_callback_list[MAX_GPIO_NUM] = { 0 };

/* External variables --------------------------------------------------------*/
extern TIM_HandleTypeDef htim6;
static int8_t map_pin_to_index( uint16_t gpioPin );


/******************************************************************************/
/*           Cortex-M0+ Processor Interruption and Exception Handlers          */
/******************************************************************************/
static int8_t map_pin_to_index( uint16_t gpioPin )
{
    int8_t pos = -1;

    while( pos < MAX_GPIO_NUM )
    {
        if( ( gpioPin >> pos ) & 1 )
        {
            return pos;
        }

        pos++;
    }

    return pos;
}

void HAL_GPIO_EXTI_Rising_Callback( uint16_t gpioPin )
{
    int8_t pos = map_pin_to_index( gpioPin );

    if( pos < MAX_GPIO_NUM )
    {
        g_button_current_ms = HAL_GetTick();
        g_button_last_ms = g_button_current_ms;
    }
}

void HAL_GPIO_EXTI_Falling_Callback( uint16_t gpioPin )
{
    int8_t pos = map_pin_to_index( gpioPin );

    if( pos < MAX_GPIO_NUM )
    {
        g_button_current_ms = HAL_GetTick();
        uint32_t elapsedTime = g_button_current_ms - g_button_last_ms;

        tButtonPressType pressType = BUTTON_PRESS_TYPE_INVALID;

        if ( SHORT_PRESS_MS > elapsedTime )
        {
            if( ( SHORT_PRESS_MS < elapsedTime ) && ( LONG_PRESS_MS > elapsedTime ) )
            {
                pressType = BUTTON_PRESS_TYPE_SHORT;
            }
            else if( elapsedTime >= LONG_PRESS_MS )
            {
                pressType = BUTTON_PRESS_TYPE_LONG;
            }
            else
            {
                // Invalid press type, ignore
            }

            exti_callback_list[pos]( pressType );
        }
    }
}

void HAL_GPIO_EXTI_Callback( uint16_t gpioPin )
{
    int8_t pos = map_pin_to_index( gpioPin );

    if( pos < MAX_GPIO_NUM )
    {
        g_button_current_ms = HAL_GetTick();
        GPIO_PinState state = HAL_GPIO_ReadPin( BSP_HAL_CONFIG_GPIO_PORT_BUTTON, BSP_HAL_CONFIG_GPIO_PIN_BUTTON );

        if ( state == GPIO_PIN_SET )
        {
            // button pressed
            g_button_last_ms = g_button_current_ms;
        }
        else
        {
            // button released
            uint32_t elapsedTime = g_button_current_ms - g_button_last_ms;

            if ( SHORT_PRESS_MS > elapsedTime )
            {
                tButtonPressType pressType = BUTTON_PRESS_TYPE_INVALID;
                if( ( SHORT_PRESS_MS < elapsedTime ) && ( LONG_PRESS_MS > elapsedTime ) )
                {
                    pressType = BUTTON_PRESS_TYPE_SHORT;
                }
                else if( elapsedTime >= LONG_PRESS_MS )
                {
                    pressType = BUTTON_PRESS_TYPE_LONG;
                }
                else
                {
                    // Invalid press type, ignore
                }

                exti_callback_list[pos]( pressType );
            }
        }
    }
}

void EXTI_RegisterCallback( uint16_t gpioPin, tInterruptCb callback )
{
    if( NULL != callback )
    {
        int8_t pos = map_pin_to_index( gpioPin );
        if ( pos < MAX_GPIO_NUM )
        {
            exti_callback_list[pos] = callback;
        }
    }
}

void EXTI4_15_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler( BSP_HAL_CONFIG_GPIO_PIN_BUTTON );
}

/******************************************************************************/
/* STM32G0xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32g0xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles TIM6 global interrupt.
  */
void TIM6_DAC_LPTIM1_IRQHandler(void)
{
    HAL_TIM_IRQHandler( &htim6 );
}
