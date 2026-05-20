/**
  ******************************************************************************
  * @file    stm32h7xx_hal_timebase_tim.c
  * @brief   HAL time base based on the hardware TIM.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/*******************************************************************************
 * Includes                                                                    *
 ******************************************************************************/
/* System Includes */
#include <stdint.h>

/* Project Includes */

/* Hardware Includes */
#include "stm32g0xx_hal.h"
#include "stm32g0xx_hal_tim.h"

/*******************************************************************************
 * Private Definitions                                                         *
 ******************************************************************************/

/*******************************************************************************
 * Private Macros                                                              *
 ******************************************************************************/

/*******************************************************************************
 * Private Variables                                                           *
 ******************************************************************************/
TIM_HandleTypeDef htim6 = {
    .Instance = TIM6,
    .Init = {
        .Period = (1000000U / 1000U) - 1U,  // [(TIM6CLK/1000) - 1]. to have a (1/1000) s time base
        .Prescaler = 0,                     // This will be updated in HAL_InitTick() function
        .ClockDivision = 0,
        .CounterMode = TIM_COUNTERMODE_UP,
        .AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE
    }
};

/*******************************************************************************
 * Function Declaration                                                        *
 ******************************************************************************/

/*******************************************************************************
 * Function Definition                                                         *
 ******************************************************************************/

/**
 * @brief  This function configures the TIM6 as a time base source.
 *         The time source is configured  to have 1ms time base with a dedicated
 *         Tick interrupt priority.
 * @note   This function is called  automatically at the beginning of program after
 *         reset by HAL_Init() or at any time when clock is configured, by HAL_RCC_ClockConfig().
 * @param  TickPriority: Tick interrupt priority.
 * @retval HAL status
 */
HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority)
{
    RCC_ClkInitTypeDef clkconfig;
    uint32_t uwTimclock;
    uint32_t uwAPB1Prescaler;
    uint32_t uwPrescalerValue;
    uint32_t pFLatency;

    /* Configure the TIM6 IRQ priority */
    HAL_NVIC_SetPriority(TIM6_DAC_LPTIM1_IRQn, TickPriority, 0U);
    HAL_NVIC_EnableIRQ(TIM6_DAC_LPTIM1_IRQn);

    /* Enable TIM6 clock */
    __HAL_RCC_TIM6_CLK_ENABLE();

    /* Get clock configuration */
    HAL_RCC_GetClockConfig(&clkconfig, &pFLatency);

    /* Get APB1 prescaler */
    uwAPB1Prescaler = clkconfig.APB1CLKDivider;

    /* Compute TIM6 clock */
    if (uwAPB1Prescaler == RCC_HCLK_DIV1)
    {
        uwTimclock = HAL_RCC_GetPCLK1Freq();
    }
    else
    {
        uwTimclock = 2UL * HAL_RCC_GetPCLK1Freq();
    }

    /* Compute the prescaler value to have TIM6 counter clock equal to 1 MHz */
    uwPrescalerValue = (uint32_t)((uwTimclock / 1000000UL) - 1UL);

    htim6.Init.Prescaler = uwPrescalerValue;

    if (HAL_TIM_Base_Init(&htim6) == HAL_OK)
    {
        /* Start the TIM time base generation in interrupt mode */
        return HAL_TIM_Base_Start_IT(&htim6);
    }

    return HAL_ERROR;
}

void HAL_SuspendTick(void)
{
    __HAL_TIM_DISABLE_IT(&htim6, TIM_IT_UPDATE);
}

void HAL_ResumeTick(void)
{
    __HAL_TIM_ENABLE_IT(&htim6, TIM_IT_UPDATE);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM6)
    {
        HAL_IncTick();
    }
}
