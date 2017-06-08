#define  _DRV_INIT_C_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Board.h"
#include "sysinfo.h"
#include "hwreg.h"

#include "MsTypes.h"
#include "drvBDMA.h"
#include "SysInit.h"
#include "drvMIU.h"


void MDrv_Chip_Initial( void )
{

#ifdef ENABLE_MINI_DUMP
    MsOS_EnableInterrupt(E_INT_FIQ_WDT);

    MDrv_Sys_SetWatchDogTimer( 10 );  //set 10 second
    MDrv_Sys_EnableWatchDog();

    MsOS_EnableInterrupt(E_INT_IRQ_MIU);
    MDrv_WriteRegBit(MIU_PROTECT_LOG_CLEAR, 0, 1<<1);
#else
    MDrv_Sys_SetWatchDogTimer( 10 );  //set 10 second
    MDrv_Sys_EnableWatchDog();
#endif
    MDrv_BDMA_Init(MIU_INTERVAL);
    MDrv_MIU_SetIOMapBase();
}

