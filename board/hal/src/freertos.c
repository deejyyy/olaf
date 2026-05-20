/*******************************************************************
* FreeRTOS Application
* Copyright (c) 2026 Henny Penny. All rights reserved.
*******************************************************************/

/*******************************************************************************
 * Includes                                                                    *
 ******************************************************************************/
/* System Includes */

/* Project Includes */
#include "freertos.h"
#include "led_control.h"

/* Hardware Includes */
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "bsp_hal_config_gpio.h"
#include "task.h"
#include "cmsis_os2.h"

/*******************************************************************************
 * Private Macros                                                              *
 ******************************************************************************/

/*******************************************************************************
 * Private Variables                                                           *
 ******************************************************************************/
osThreadId_t ledControlTaskHandle;

const osThreadAttr_t ledControlTask_attributes = {
    .name = "ledControlTask",
    .stack_size = STACK_SIZE_TASK_DEFAULT,
    .priority = (osPriority_t)PRIORITY_TASK_NORMAL,
};

uint32_t ledTime_ms = 1000;

/*******************************************************************************
 * Private Function Declaration                                                *
 ******************************************************************************/

/*******************************************************************************
 * Private Function Definition                                                 *
 ******************************************************************************/

/*******************************************************************************
 * Public Function Definition                                                  *
 ******************************************************************************/
void freertos_init(void) {
    ledControlTaskHandle = osThreadNew(ledControl_task, &ledTime_ms, &ledControlTask_attributes);
}
