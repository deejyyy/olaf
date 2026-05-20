/*******************************************************************
* HAL TIM Configuration Source File
* Copyright (c) 2026 Embedded Systems Inc. All rights reserved.
*******************************************************************/

/*******************************************************************************
 * Includes                                                                    *
 ******************************************************************************/
/* System Includes */

/* Project Includes */
#include "main.h"
#include "bsp_hal_config_tim.h"
#include "stm32g0b1xx.h"

/* Hardware Includes */

/*******************************************************************************
 * Private Definitions                                                         *
 ******************************************************************************/

/*******************************************************************************
 * Private Macros                                                              *
 ******************************************************************************/
#define HAL_CONFIG_TIM_PRESCALER_TIM_6  (0x3F)          // 63
#define HAL_CONFIG_TIM_PERIOD_TIM_6     (0x3E7)         // 999

/*******************************************************************************
 * Private Types                                                               *
 ******************************************************************************/

/*******************************************************************************
 * Private Variables                                                           *
 ******************************************************************************/
TIM_HandleTypeDef htim6 = {
    .Instance = TIM6,
    .Init = {
        .Prescaler = HAL_CONFIG_TIM_PRESCALER_TIM_6,
        .CounterMode = TIM_COUNTERMODE_UP,
        .Period = HAL_CONFIG_TIM_PERIOD_TIM_6,
        .AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE
    }
};

/*******************************************************************************
 * Function Declaration                                                        *
 ******************************************************************************/

/*******************************************************************************
 * Function Definition                                                         *
 ******************************************************************************/
void MX_TIM6_Init(void) {
    TIM_MasterConfigTypeDef sMasterConfig = { 0 };

    if (HAL_OK != HAL_TIM_Base_Init(&htim6)) {
        Error_Handler();
    }

    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;

    if (HAL_OK != HAL_TIMEx_MasterConfigSynchronization(&htim6, &sMasterConfig)) {
        Error_Handler();
    }

    // Start the TIM6 base generation in interrupt mode
    if (HAL_OK != HAL_TIM_Base_Start_IT(&htim6)) {
        Error_Handler();
    }
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* tim_baseHandle) {
    if (TIM6 == tim_baseHandle->Instance) {
        /* TIM6 clock enable */
        __HAL_RCC_TIM6_CLK_ENABLE();
        /* TIM6 interrupt Init */
        HAL_NVIC_SetPriority(TIM6_DAC_LPTIM1_IRQn, 3, 0);
        HAL_NVIC_EnableIRQ(TIM6_DAC_LPTIM1_IRQn);
    } else {
        // Do nothing
    }
}

void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef* tim_baseHandle) {
    if (TIM6 == tim_baseHandle->Instance) {
        /* Peripheral clock disable */
        __HAL_RCC_TIM6_CLK_DISABLE();
        /* TIM6 interrupt Deinit */
        HAL_NVIC_DisableIRQ(TIM6_DAC_LPTIM1_IRQn);
    } else {
        // Do nothing
    }
}
