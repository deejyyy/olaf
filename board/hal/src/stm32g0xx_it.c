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

#include "main.h"
#include "bsp_hal_config_gpio.h"
#include "stm32g0xx_it.h"

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
void EXTI_RegisterCallback( uint16_t gpioPin, tInterruptCb callback );
static tInterruptCb exti_callback_list[BSP_HAL_CONFIG_GPIO_MAX] = { 0 };

/* External variables --------------------------------------------------------*/
extern TIM_HandleTypeDef htim6;
static int8_t map_pin_to_index( uint16_t gpioPin );


/******************************************************************************/
/*           Cortex-M0+ Processor Interruption and Exception Handlers          */
/******************************************************************************/
static int8_t map_pin_to_index( uint16_t gpioPin )
{
    uint8_t pos = 0;

    while( pos < BSP_HAL_CONFIG_GPIO_MAX )
    {
        if( ( gpioPin >> pos ) & 1 )
        {
            return pos;
        }

        pos++;
    }

    return -1;
}

void HAL_GPIO_EXTI_Callback( uint16_t gpioPin )
{
    uint8_t pos = map_pin_to_index(gpioPin);
    if( pos >= 0 ) {
        exti_callback_list[pos]();
    }
}


void EXTI_RegisterCallback( uint16_t gpioPin, tInterruptCb callback )
{
    if( NULL != callback )
    {
        uint8_t pos = map_pin_to_index( gpioPin );
        if (pos >= 0) {
            exti_callback_list[pos] = callback;
        }
    }
}

void EXTI0_1_IRQHandler(void)
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
