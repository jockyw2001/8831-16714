#include "cpptest.h"
/*
 * tv-ap_dvb_app_stub.c
 *
 *  Created on: 27 Dec 2013
 *      Author: muters
 */

#include "Board.h"                  //For pvr select
#include "sysinfo.h"                //For record/playback buffer

#include "debug.h"

#if ENABLE_PVR

//api
#include "msAPI_Timer.h"            //For timer
#include "msAPI_DTVSystem.h"        //For audio info
#include "msAPI_PVR.h"              //For pvr
#include "msAPI_Player.h"           //For player
#include "msAPI_PVRFileSystem.h"
#include "msAPI_audio.h"
//ap
#ifdef PVR_8051
#include "mapp_demux.h"             //For demux
#else
#include "MApp_GlobalVar.h"         //For demux
#endif
#include "mapp_si.h"                //For SI
#ifdef S3PLUS
#include "MApp_MHEG5_Main.h"        //For MHEG5
#endif
#include "MApp_ChannelChange.h"     //For channel change
#include "MApp_TimeShift.h"         //For itself
#include "MApp_MassStorage.h"       //For USB detection

#include "MApp_AVSync.h"

//ui <--better not be here
#ifdef PVR_8051
#ifdef S3PLUS
#include "MApp_UiMenuFunc.h"
#endif
#include "MApp_UiMenu.h"
#else
#include "MApp_UiMenuDef.h"
#endif
#include "MApp_UiPvr.h"
#include "MApp_ZUI_ACTpvr.h"

#if ((BRAZIL_CC )|| (ATSC_CC == ATV_CC))
#include "mapp_closedcaption.h"
#endif


#ifdef PVR_8051
#ifdef SUBTITLE                     //For subtitle define compatibility
#define ENABLE_SUBTITLE             1
#define ENABLE_SBTVD_BRAZIL_APP     0
#else
#define ENABLE_SUBTITLE             0
#define ENABLE_SBTVD_BRAZIL_APP     0
#endif
#endif
#if OBA2
#include <string.h>
#endif


EXTERN_C_LINKAGE U32 MApp_TimeShift_GetRecordValidPeriodSec(void);
EXTERN_C_LINKAGE U32 CppTest_Stub_MApp_TimeShift_GetRecordValidPeriodSec(void)
{
	if( CppTest_IsCurrentTestCase("TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetPlaybackTimeSec_else") )
	{
		return 0;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetPlaybackTimeSec_if") )
	{
		return 50;
	}

	return 0;
}



#endif//ENABLE_PVR
