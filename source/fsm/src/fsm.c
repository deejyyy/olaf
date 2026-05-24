/*******************************************************************************
* Finite State Machine Source File
* Copyright (c) 2026 Deej. All rights reserved.
*******************************************************************************/

/*******************************************************************************
 * Includes                                                                    *
 ******************************************************************************/
/* System Includes */
#include <stdint.h>
#include <stdlib.h>

/* Project Includes */
#include "fsm.h"

/* Hardware Includes */

/*******************************************************************************
 * Private Macros                                                              *
 ******************************************************************************/

/*******************************************************************************
 * Private Data Types                                                          *
 ******************************************************************************/

/*******************************************************************************
 * Private Variables                                                           *
 ******************************************************************************/
tFsm *m_main_fsm[FSM_MAX_ID] = { 0 };

/*******************************************************************************
 * Private Function Declaration                                                *
 ******************************************************************************/

/*******************************************************************************
 * Private Function Definition                                                 *
 ******************************************************************************/

/*******************************************************************************
 * Public Function Definition                                                  *
 ******************************************************************************/
void fsm_init( void )
{
    for( uint8_t id = 0; id < FSM_MAX_ID; id++ )
    {
        m_main_fsm[id] = NULL;
    }
}

void fsm_transitionState( void *pContext, eFsmId fsmId, uint32_t newState )
{
    if ( NULL != pContext )
    {
        uint32_t currentState = m_main_fsm[fsmId]->currentState;
        m_main_fsm[fsmId]->exit( pContext ); // Call the exit function of the current state
        m_main_fsm[fsmId]->currentState = newState; // Update the current state to the new state
        m_main_fsm[fsmId]->entry( pContext ); // Call the entry function of the new state
    }
    else
    {
        return;
    }
}

void fsm_registerChildFsm( tFsm *pFsmArray, eFsmId fsmId, uint8_t arraySize )
{
    if( ( NULL != pFsmArray ) &&
        ( FSM_MAX_ID >= fsmId ) &&
        ( NULL == m_main_fsm[fsmId] ) )
    {
        for( uint8_t id = 0; id < arraySize; id++ )
        {
            m_main_fsm[fsmId]->currentState = 0;
            m_main_fsm[fsmId]->entry = pFsmArray[id].entry;
            m_main_fsm[fsmId]->exit = pFsmArray[id].exit;
        }
    }
    else
    {
        // Do nothing
        // TODO: Raise error
    }
}
