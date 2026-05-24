/*******************************************************************************
* Finite State Machine Header File
* Copyright (c) 2026 Deej. All rights reserved.
*******************************************************************************/

#ifndef FSM_H
#define FSM_H

/*******************************************************************************
 * Includes                                                                    *
 ******************************************************************************/
/* System Includes */
#include <stdint.h>

/* Project Includes */

/* Hardware Includes */

/*******************************************************************************
 * Public Macros                                                               *
 ******************************************************************************/

/*******************************************************************************
 * Public Variables                                                            *
 ******************************************************************************/

/*******************************************************************************
 * Public Data Types                                                           *
 ******************************************************************************/
typedef struct
{
    void *pData; // Pointer to any additional data needed by the FSM
} tFsmContext;

typedef enum
{
    FSM_SYSTEM_MANAGER_ID,
    FSM_MAX_ID
} eFsmId;

typedef void (*pOperation)(void *pContext);

typedef struct
{
    uint32_t currentState; // Current state of the FSM
    // void (*entry)(void *pContext); // Function pointer for FSM initialization
    // void (*exit)(void *pContext); // Function pointer
    pOperation entry; // Function pointer for FSM initialization
    pOperation exit; // Function pointer for FSM cleanup
} tFsm;


/*******************************************************************************
 * Public Function Declaration                                                 *
 ******************************************************************************/

/*******************************************************************************
 * Public Function Definition                                                  *
 ******************************************************************************/

/*******************************************************************************
 * Public Function Definition                                                   *
 ******************************************************************************/

// Update these for your board if LED is on a different GPIO.

void fsm_registerChildFsm( tFsm *pFsmArray, eFsmId fsmId, uint8_t arraySize );
void fsm_transitionState( void *pContext, eFsmId fsmId, uint32_t newState );

#endif // FSM_H
