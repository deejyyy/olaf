/*******************************************************************************
* Button Control Source File
* Copyright (c) 2026 Deej. All rights reserved.
*******************************************************************************/

/*******************************************************************************
 * Includes                                                                    *
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>

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
static void buttonInterruptHandler( tButtonPressType pressType );
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

static void buttonInterruptHandler( tButtonPressType pressType )
{
    // Do nothing
    switch ( pressType )
    {
        case BUTTON_PRESS_TYPE_SHORT:
        {
            ledControl_toggle();
            osDelay( 1000 );
            ledControl_toggle();
            osDelay( 1000 );
            ledControl_toggle();
        }
        break;
        case BUTTON_PRESS_TYPE_LONG:
        {
            // Do nothing for now
            ledControl_toggle();
            osDelay( 500 );
            ledControl_toggle();
            osDelay( 500 );
            ledControl_toggle();
            osDelay( 500 );
            ledControl_toggle();
            osDelay( 500 );
        }
        break;
        default:
        {
            // Invalid press type, ignore
        }
        break;
    }
}
/*******************************************************************************
 * Public Function Definition                                                  *
 ******************************************************************************/
void buttonControl_task( void *pArgument )
{
    configureButton();
    while ( 1 )
    {
        osDelay( 10 );
        // if ( g_button_pressed )
        // {
        //     ledControl_toggle();
        //     g_button_pressed = false;
        // }
    }

}
