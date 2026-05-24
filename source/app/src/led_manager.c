/*******************************************************************************
* LED Control Source File
* Copyright (c) 2026 Deej. All rights reserved.
*******************************************************************************/

/*******************************************************************************
 * Includes                                                                    *
 ******************************************************************************/
#include <stdint.h>

/* Project Includes */
#include "led_manager.h"

/* Hardware Includes */
#include "stm32g0xx_hal.h"
#include "cmsis_os2.h"

/*******************************************************************************
 * Private Macros                                                              *
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

void ledManager_init( void )
{
	HAL_GPIO_WritePin( GPIOA, GPIO_PIN_5, GPIO_PIN_RESET );
}

void ledManager_on( void )
{
	HAL_GPIO_WritePin( GPIOA, GPIO_PIN_5, GPIO_PIN_SET );
}

void ledManager_off( void )
{
	HAL_GPIO_WritePin( GPIOA, GPIO_PIN_5, GPIO_PIN_RESET );
}

void ledManager_toggle( void )
{
	HAL_GPIO_TogglePin( GPIOA, GPIO_PIN_5 );
}

void ledManager_task( void *argument )
{
	uint32_t ledTime_ms = *((uint32_t *)argument);
	while ( 1 )
	{
		ledManager_toggle();
		osDelay(ledTime_ms);
	}
}
