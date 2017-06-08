#include "cpptest.h"

/** 
 * This file contains auto-generated stub definitions.
 *
 * Available C++test API functions (see C++test Users Guide for details):
 *     void CppTest_Assert(bool test, const char * message)
 *     void CppTest_Break()
 *     const char* CppTest_GetCurrentTestCaseName()
 *     const char* CppTest_GetCurrentTestSuiteName()
 *     bool CppTest_IsCurrentTestCase(const char* testCaseName)
 */

/** 
 * Header files where the stubbed functions are originally declared.
 * Verify #include directives and add any additional header files as necessary.
 */
#include <stdlib.h>
#include <string.h>
#include "DemoFineTune.h"
#include "MApp_Audio.h"
#include "MApp_AutoTest.h"
#include "MApp_CIMMI.h"
#include "MApp_ChannelChange.h"
#include "MApp_GlobalSettingSt.h"
#include "MApp_GlobalSettingSt_Common.h"
#include "MApp_GlobalVar.h"
#include "MApp_MVDMode.h"
#include "MApp_MultiTasks.h"
#include "MApp_SignalMonitor.h"
#include "MApp_Sleep.h"
#include "MApp_Subtitle.h"
#include "MApp_TV.h"
#include "MApp_UiPvr.h"
#include "MApp_ZUI_ACTcoexistWin.h"
#include "MApp_ZUI_ACTepg.h"
#include "SysInit.h"
#include "apiAUDIO.h"
#include "apiXC.h"
#include "apiXC_Adc.h"
#include "apiXC_Sys.h"
#include "drvISR.h"
#include "drvTVEncoder.h"
#include "drvUartDebug.h"
#include "drvXC_HDMI_if.h"
#include "drvpower_if.h"
#include "mapp_mplayer.h"
#include "mapp_mplayer_subtitle.h"
#include "mapp_videoplayer.h"
#include "msAPI_CI.h"
#include "msAPI_FSEnv.h"
#include "msAPI_Flash.h"
#include "msAPI_Global.h"
#include "msAPI_MHEG5.h"
#include "msAPI_PVR.h"
#include "msAPI_Thai_Shaping.h"
#include "msIR.h"
#include "mstar_debug.h"
#include "mw_debug.h"
#include "stdio.h"

/** Auto-generated stub definition for function: void MApi_SC_ForceFreerun(MS_BOOL) */
EXTERN_C_LINKAGE void MApi_SC_ForceFreerun (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_SC_ForceFreerun (MS_BOOL bEnable)
{
}

/** Auto-generated stub definition for function: void MApi_SC_SetFreerunVFreq(E_VFREQ_SEL) */
EXTERN_C_LINKAGE void MApi_SC_SetFreerunVFreq (E_VFREQ_SEL VFreq) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_SC_SetFreerunVFreq (E_VFREQ_SEL VFreq)
{
}

/** Auto-generated stub definition for function: Audio_MP3_LAYER MApi_AUDIO_GetLayer(void) */
EXTERN_C_LINKAGE Audio_MP3_LAYER MApi_AUDIO_GetLayer () ;
EXTERN_C_LINKAGE Audio_MP3_LAYER CppTest_Stub_MApi_AUDIO_GetLayer (void)
{
    return Audio_MP3_LAYER_RESERVED;
}

/** Auto-generated stub definition for function: U16 MApp_MPlayer_SearchSubtitleTag(U32) */
EXTERN_C_LINKAGE U16 MApp_MPlayer_SearchSubtitleTag (U32 u32Time) ;
EXTERN_C_LINKAGE U16 CppTest_Stub_MApp_MPlayer_SearchSubtitleTag (U32 u32Time)
{
    return (unsigned short)0;
}

/** Auto-generated stub definition for function: MS_BOOL MApi_XC_ADC_IsCVBSOutEnabled(E_DEST_TYPE) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_ADC_IsCVBSOutEnabled (E_DEST_TYPE enOutputType) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_ADC_IsCVBSOutEnabled (E_DEST_TYPE enOutputType)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: MS_BOOL MDrv_VE_IsBlackScreenEnabled(void) */
EXTERN_C_LINKAGE MS_BOOL MDrv_VE_IsBlackScreenEnabled () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_VE_IsBlackScreenEnabled (void)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void msAPI_CI_SetDetectEnable(BOOLEAN) */
EXTERN_C_LINKAGE void msAPI_CI_SetDetectEnable (BOOLEAN bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_SetDetectEnable (BOOLEAN bEnable)
{
}

/** Auto-generated stub definition for function: AUDIO_DSP_CODE_TYPE MApi_AUDIO_ReadDspCodeType(void) */
EXTERN_C_LINKAGE AUDIO_DSP_CODE_TYPE MApi_AUDIO_ReadDspCodeType () ;
EXTERN_C_LINKAGE AUDIO_DSP_CODE_TYPE CppTest_Stub_MApi_AUDIO_ReadDspCodeType (void)
{
    return AU_DVB_STANDARD_INVALID;
}
