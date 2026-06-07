/*******************************************************************************
* Button Control Source File
* Copyright (c) 2026 Deej. All rights reserved.
*******************************************************************************/

/*******************************************************************************
 * Includes                                                                    *
 ******************************************************************************/
#include <stdint.h>

/* Project Includes */
#include "button_control.h"
#include "led_control.h"

/* Hardware Includes */
#include "bsp_hal_config_gpio.h"
#include "stm32g0xx_it.h"
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
static void buttonInterruptHandler( void );
static void configureButton( void );

/*******************************************************************************
 * Private Function Definition                                                 *
 ******************************************************************************/
static void configureButton( void )
{
    EXTI_RegisterCallback( BSP_HAL_CONFIG_GPIO_PIN_BUTTON, buttonInterruptHandler );

    for( uint32_t count = 0; count < 5; count++ )
    {
        ledControl_toggle();
        osDelay( 250 );
    }
}

static void buttonInterruptHandler( void )
{
    // Handle button press event here
    ledControl_toggle();
}
/*******************************************************************************
 * Public Function Definition                                                  *
 ******************************************************************************/
void buttonControl_task( void *pArgument )
{
    // ledControl_init();
    configureButton();
    while ( 1 )
    {
        osDelay( 100 );
    }
}
