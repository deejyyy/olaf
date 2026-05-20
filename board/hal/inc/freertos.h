/**
  ******************************************************************************
  * @file           : freertos.h
  * @brief          : Header for freertos.c file.
  *                   This file contains the common defines of the FreeRTOS module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 Henny Penny.
  * All rights reserved.
  *
  ******************************************************************************
  */

#ifndef PLATFORM_BSP_INC_FREERTOS_H_
#define PLATFORM_BSP_INC_FREERTOS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
 * Includes                                                                    *
 ******************************************************************************/

/*******************************************************************************
 * Private Definitions                                                         *
 ******************************************************************************/

/*******************************************************************************
 * Public Macros                                                               *
 ******************************************************************************/
#define STACK_SIZE_TASK_DEFAULT (1536 * 4)
#define STACK_SIZE_TASK_SMALL   (512 * 4)
#define STACK_SIZE_TASK_MEDIUM  (1024 * 4)
#define STACK_SIZE_TASK_LARGE   (2048 * 4)

#define PRIORITY_TASK_NONE      osPriorityNone
#define PRIORITY_TASK_IDLE      osPriorityIdle
#define PRIORITY_TASK_LOW       osPriorityLow
#define PRIORITY_TASK_NORMAL    osPriorityNormal
#define PRIORITY_TASK_HIGH      osPriorityHigh

/*******************************************************************************
 * Private Variables                                                           *
 ******************************************************************************/

/*******************************************************************************
 * Function Declaration                                                        *
 ******************************************************************************/
/**
 * @brief Initialize the FreeRTOS kernel.
 */
void freertos_init(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif  // PLATFORM_BSP_INC_FREERTOS_H_
