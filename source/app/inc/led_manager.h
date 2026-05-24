/*******************************************************************************
* LED Control Header File
* Copyright (c) 2026 Deej. All rights reserved.
*******************************************************************************/

#ifndef LED_CONTROL_H
#define LED_CONTROL_H

/*******************************************************************************
 * Includes                                                                    *
 ******************************************************************************/

#include "stm32g0xx_hal.h"

/*******************************************************************************
 * Public Function Declaration                                                 *
 ******************************************************************************/

void ledManager_init( void );
void ledManager_on( void );
void ledManager_off( void );
void ledManager_toggle( void );
void ledManager_task( void *argument );
// void ledManager_task( tLedManagerContext *pContext );

#endif // LED_CONTROL_H
