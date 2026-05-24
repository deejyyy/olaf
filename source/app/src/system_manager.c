/*******************************************************************************
* LED Control Source File
* Copyright (c) 2026 Deej. All rights reserved.
*******************************************************************************/

/*******************************************************************************
 * Includes                                                                    *
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>

/* Project Includes */
#include "fsm.h"
#include "system_manager.h"

/* Hardware Includes */
#include "cmsis_os2.h"

/*******************************************************************************
 * Private Macros                                                              *
 ******************************************************************************/

/*******************************************************************************
 * Private Data Types                                                          *
 ******************************************************************************/
typedef struct
{
    uint32_t test; // Placeholder for system uptime tracking
    bool isInitialized; // Flag to indicate if the FSM has been initialized
    void *data; // Pointer to any additional data needed by the FSM
} tSystemManagerContext; // Placeholder for any context data needed by the FSM

tSystemManagerContext pSystemManagerContext =
{
    .isInitialized = false, // Initialize initialization flag to false
    .test = 0 // Placeholder for system uptime tracking
};

/*******************************************************************************
 * Private Function Declaration                                                *
 ******************************************************************************/
void systemManager_initEntry( void *pContext );
void systemManager_initExit( void *pContext );

void systemManager_activeEntry( void *pContext );
void systemManager_activeExit( void *pContext );

void systemManager_errorEntry( void *pContext );
void systemManager_errorExit( void *pContext );

/*******************************************************************************
 * Private Variables                                                           *
 ******************************************************************************/
tFsm m_systemManager_fsm[SYSTEM_MANAGER_STATE_MAX] = {
    [SYSTEM_MANAGER_STATE_INIT] =
    {
        .entry = systemManager_initEntry, // Placeholder for FSM initialization function
        .exit = systemManager_initExit   // Placeholder for FSM cleanup function
    },
    [SYSTEM_MANAGER_STATE_ACTIVE] =
    {
        .entry = systemManager_activeEntry, // Placeholder for FSM initialization function
        .exit = systemManager_activeExit   // Placeholder for FSM cleanup function
    },
    [SYSTEM_MANAGER_STATE_ERROR] =
    {
        .entry = systemManager_errorEntry, // Placeholder for FSM initialization function
        .exit = systemManager_errorExit   // Placeholder for FSM cleanup function
    }
};

#define SYSTEM_MANAGER_FSM_SIZE ( sizeof( m_systemManager_fsm ) / sizeof( m_systemManager_fsm[0] ) )

/*******************************************************************************
 * Private Function Definition                                                 *
 ******************************************************************************/
void systemManager_initEntry( void *pContext )
{
    // Initialize the FSM context and set the initial state
    // static tSystemManagerContext systemManagerContext;
    // fsm_init(&systemManagerContext, FSM_STATE_OFF);
    // tSystemManager_init.context = &systemManagerContext;
    fsm_transitionState( pContext, FSM_SYSTEM_MANAGER_ID, SYSTEM_MANAGER_STATE_ACTIVE );
}

void systemManager_initExit( void *pContext )
{
    // Placeholder for cleanup code when exiting the FSM
}

void systemManager_activeEntry( void *pContext )
{
    fsm_transitionState( pContext, FSM_SYSTEM_MANAGER_ID, SYSTEM_MANAGER_STATE_ERROR );
}

void systemManager_activeExit( void *pContext )
{
    // Placeholder for code to execute when exiting the ACTIVE state
}

void systemManager_errorEntry( void *pContext )
{
    fsm_transitionState( pContext, FSM_SYSTEM_MANAGER_ID, SYSTEM_MANAGER_STATE_INIT );
}
void systemManager_errorExit( void *pContext )
{
    // Placeholder for code to execute when exiting the ERROR state
}

/*******************************************************************************
 * Public Function Definition                                                  *
 ******************************************************************************/
void systemManager_handler( void *pContext )
{
    fsm_registerChildFsm( m_systemManager_fsm, FSM_SYSTEM_MANAGER_ID, SYSTEM_MANAGER_FSM_SIZE );

    while ( true )
    {
        // Implement FSM state handling logic here
        // For example, you can check the current state and perform actions accordingly

        // Example:
        // tSystemManagerContext *context = (tSystemManagerContext *)systemManager_fsm.context;
        // switch (context->currentState)
        // {
        //     case FSM_STATE_OFF:
        //         // Handle OFF state
        //         break;
        //     case FSM_STATE_INIT:
        //         // Handle INIT state
        //         break;
        //     case FSM_STATE_ACTIVE:
        //         // Handle ACTIVE state
        //         break;
        //     case FSM_STATE_ERROR:
        //         // Handle ERROR state
        //         break;
        //     default:
        //         break;
        // }

        osDelay( 100 ); // Delay to prevent tight loop, adjust as needed
    }
}