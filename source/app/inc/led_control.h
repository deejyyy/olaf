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

// Update these for your board if LED is on a different GPIO.

void ledControl_init(void);
void ledControl_on(void);
void ledControl_off(void);
void ledControl_toggle(void);
void ledControl_task(void *argument);

#endif // LED_CONTROL_H
