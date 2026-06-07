/*******************************************************************************
* LED Control Source File
* Copyright (c) 2026 Deej. All rights reserved.
*******************************************************************************/

/*******************************************************************************
 * Includes                                                                    *
 ******************************************************************************/
#include <stdint.h>

/* Project Includes */
#include "led_control.h"

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
void ledControl_init( void )
{
	HAL_GPIO_WritePin( GPIOA, GPIO_PIN_5, GPIO_PIN_RESET );
}

void ledControl_on( void )
{
	HAL_GPIO_WritePin( GPIOA, GPIO_PIN_5, GPIO_PIN_SET );
}

void ledControl_off( void )
{
	HAL_GPIO_WritePin( GPIOA, GPIO_PIN_5, GPIO_PIN_RESET );
}

void ledControl_toggle( void )
{
	HAL_GPIO_TogglePin( GPIOA, GPIO_PIN_5 );
}

void ledControl_task( void *argument )
{
	uint32_t ledTime_ms = *((uint32_t *)argument);
	while ( 1 )
	{
		ledControl_toggle();
		osDelay( ledTime_ms );
	}
}
