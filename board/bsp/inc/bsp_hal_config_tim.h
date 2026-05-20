/**
  ******************************************************************************
  * @file    bsp_hal_config_tim.h
  * @brief   This file contains all the function prototypes for
  *          the tim.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef PLATFORM_BSP_INC_HAL_CONFIG_TIM_H_
#define PLATFORM_BSP_INC_HAL_CONFIG_TIM_H_

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Includes                                                                    *
 ******************************************************************************/
#include "stm32g0xx_hal.h"

/*******************************************************************************
 * Private Definitions                                                         *
 ******************************************************************************/

/*******************************************************************************
 * Private Macros                                                              *
 ******************************************************************************/

/*******************************************************************************
 * Private Variables                                                           *
 ******************************************************************************/
extern TIM_HandleTypeDef htim6;

/*******************************************************************************
 * Function Declaration                                                         *
 ******************************************************************************/
/**
 * @brief TIM6 Initialization Function
 */
void MX_TIM6_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* PLATFORM_BSP_INC_HAL_CONFIG_TIM_H_ */

