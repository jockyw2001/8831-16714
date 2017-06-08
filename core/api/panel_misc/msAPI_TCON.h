#ifndef _MSAPI_TCON_H_
#define _MSAPI_TCON_H_


#include "Board.h"

#include "Panel.h"


#if( ENABLE_TCON_2014 )

BOOL msAPI_TCON_Init(void);

BOOL msAPI_TCON_LoadTable(BOOL bIs3D);

#endif

/***************************************************************************************/
#endif // #ifndef _MDRV_MFC_TCON_H_

