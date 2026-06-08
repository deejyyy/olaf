/*******************************************************************************
* Button Control Header File
* Copyright (c) 2026 Deej. All rights reserved.
*******************************************************************************/

#ifndef BUTTON_CONTROL_H
#define BUTTON_CONTROL_H

/*******************************************************************************
 * Includes                                                                    *
 ******************************************************************************/

/*******************************************************************************
 * Public Types                                                                *
 ******************************************************************************/
typedef enum
{
    BUTTON_PRESS_TYPE_INVALID,
    BUTTON_PRESS_TYPE_SHORT,
    BUTTON_PRESS_TYPE_LONG,
    BUTTON_PRESS_TYPE_MAX
} tButtonPressType;

/*******************************************************************************
 * Public Function Declaration                                                 *
 ******************************************************************************/
void buttonControl_task( void *pArgument );

#endif // BUTTON_CONTROL_H
