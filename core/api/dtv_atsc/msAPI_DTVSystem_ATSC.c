
#include "Board.h"

#if( ENABLE_ATSC )

#include "Utl.h"


#include "msAPI_DTVSystem_ATSC.h"

//==================================================

StuDtvAtscInfo g_stDtvAtscInfo;

// todo: rename
//MS_U8 fEnableSignalCheck;


void msAPI_DTVSystem_ATSC_Init(void)
{
    memset( &(g_stDtvAtscInfo), 0, sizeof(StuDtvAtscInfo) );

}

#endif

