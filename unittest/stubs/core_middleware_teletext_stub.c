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
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "stdio.h"
#include "datatype.h"
#include "MsOS.h"
#include "apiXC.h"
#include "apiXC_Sys.h"
#include "debug.h"
#include "drvAVD.h"
#include "msAPI_FreqTableCommon.h"
#include "msAPI_TTX.h"
#include "mapp_ttx.h"


extern MS_TELETEXT_INFO gstTtxInfo;
MS_TELETEXT_INFO CppTest_Variable_Auto_Stub_gstTtxInfo = {0};

/** Auto-generated stub definition for variable: U32 g_u32MonitorTTXClockTimer */
EXTERN_C_LINKAGE_START
extern U32 g_u32MonitorTTXClockTimer;
U32 CppTest_Variable_Auto_Stub_g_u32MonitorTTXClockTimer = 0UL;
EXTERN_C_LINKAGE_END


/** Auto-generated stub definition for function: BOOLEAN MApp_TTX_IsChInfoOn(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_TTX_IsChInfoOn () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_TTX_IsChInfoOn (void) 
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void msAPI_TTX_VBIAcquireEnable(U8) */
EXTERN_C_LINKAGE void msAPI_TTX_VBIAcquireEnable (U8 enable) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_msAPI_TTX_VBIAcquireEnable (U8 enable) 
{
}

/** Auto-generated stub definition for function: void _SubmitPalette(void) */
EXTERN_C_LINKAGE void _SubmitPalette () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub__SubmitPalette (void) 
{
}

/** Auto-generated stub definition for function: void msAPI_TTX_ResetAcquisition(void) */
EXTERN_C_LINKAGE void msAPI_TTX_ResetAcquisition () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_msAPI_TTX_ResetAcquisition (void) 
{
}

/** Auto-generated stub definition for function: void MApp_TTX_SetRP_Video_TTX(BOOLEAN bIsVideoTTX) */
EXTERN_C_LINKAGE void MApp_TTX_SetRP_Video_TTX(BOOLEAN bIsVideoTTX) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_TTX_SetRP_Video_TTX(BOOLEAN bIsVideoTTX)
{
}

/** Auto-generated stub definition for function: BOOLEAN MApp_TTX_IsTeletextOn(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_TTX_IsTeletextOn () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_TTX_IsTeletextOn (void) 
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MApp_TTX_VBIDataProcessor(void) */
EXTERN_C_LINKAGE void MApp_TTX_VBIDataProcessor () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_TTX_VBIDataProcessor (void) 
{
}

/** Auto-generated stub definition for function: void MApp_TTX_SetSubtitlePage(U16, U16) */
EXTERN_C_LINKAGE void MApp_TTX_SetSubtitlePage (U16 mag, U16 page) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_TTX_SetSubtitlePage (U16 mag, U16 page) 
{
}

/** Auto-generated stub definition for function: void msAPI_TTX_Stop(void) */
EXTERN_C_LINKAGE void msAPI_TTX_Stop () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_msAPI_TTX_Stop (void) 
{
}

/** Auto-generated stub definition for function: U16 MApp_TTX_GetDefaultTTX_PID(void) */
EXTERN_C_LINKAGE U16 MApp_TTX_GetDefaultTTX_PID () ;
EXTERN_C_LINKAGE U16 CppTest_Auto_Stub_MApp_TTX_GetDefaultTTX_PID (void) 
{
    return (unsigned short)0;
}

/** Auto-generated stub definition for function: void MApp_TTX_SetDefaultTTX_PID(U16) */
EXTERN_C_LINKAGE void MApp_TTX_SetDefaultTTX_PID (U16 pid) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_TTX_SetDefaultTTX_PID (U16 pid) 
{
}

/** Auto-generated stub definition for function: BOOLEAN msAPI_TTX_InitSystem(void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_TTX_InitSystem () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_msAPI_TTX_InitSystem (void) 
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void msAPI_TTX_Run(void) */
EXTERN_C_LINKAGE void msAPI_TTX_Run () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_msAPI_TTX_Run (void) 
{
}

/** Auto-generated stub definition for function: U_INT8 MApp_TTX_GetSubtitlesAvailable(void) */
EXTERN_C_LINKAGE U_INT8 MApp_TTX_GetSubtitlesAvailable () ;
EXTERN_C_LINKAGE U_INT8 CppTest_Auto_Stub_MApp_TTX_GetSubtitlesAvailable (void) 
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MApp_TTX_EnableScan(U_INT8) */
EXTERN_C_LINKAGE void MApp_TTX_EnableScan (U_INT8 on) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_TTX_EnableScan (U_INT8 on) 
{
}

/** Auto-generated stub definition for function: U8 msAPI_TTX_Get_VBIAcquireEnableStatus(void) */
EXTERN_C_LINKAGE U8 msAPI_TTX_Get_VBIAcquireEnableStatus () ;
EXTERN_C_LINKAGE U8 CppTest_Auto_Stub_msAPI_TTX_Get_VBIAcquireEnableStatus (void) 
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MApp_TTX_NotifyPMTTTXInfoChanged(void) */
EXTERN_C_LINKAGE void MApp_TTX_NotifyPMTTTXInfoChanged () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_TTX_NotifyPMTTTXInfoChanged (void) 
{
}

/** Auto-generated stub definition for function: MS_U16 msAPI_TTX_ReadWssWord(void) */
EXTERN_C_LINKAGE MS_U16 msAPI_TTX_ReadWssWord () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Auto_Stub_msAPI_TTX_ReadWssWord (void) 
{
    return (unsigned short)0;
}

/** Auto-generated stub definition for function: void MApp_TTX_SetSubtitleTTX_PID(U16) */
EXTERN_C_LINKAGE void MApp_TTX_SetSubtitleTTX_PID (U16 pid) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_TTX_SetSubtitleTTX_PID (U16 pid) 
{
}

/** Auto-generated stub definition for function: void MApp_TTX_Decoder_Process(void) */
EXTERN_C_LINKAGE void MApp_TTX_Decoder_Process () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_TTX_Decoder_Process (void) 
{
}

/** Auto-generated stub definition for function: void msAPI_TTX_SetVideoStandard(AVD_VideoStandardType) */
EXTERN_C_LINKAGE void msAPI_TTX_SetVideoStandard (AVD_VideoStandardType ucVideoSystem) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_msAPI_TTX_SetVideoStandard (AVD_VideoStandardType ucVideoSystem) 
{
}

/** Auto-generated stub definition for function: void MApp_TTX_SetChInfoOnOff(BOOLEAN) */
EXTERN_C_LINKAGE void MApp_TTX_SetChInfoOnOff (BOOLEAN val) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_TTX_SetChInfoOnOff (BOOLEAN val) 
{
}

/** Auto-generated stub definition for function: void msAPI_TTX_OnOffVBISlicer(U8) */
EXTERN_C_LINKAGE void msAPI_TTX_OnOffVBISlicer (U8 on) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_msAPI_TTX_OnOffVBISlicer (U8 on) 
{
}

/** Auto-generated stub definition for function: void MApp_TTX_SetDTV_TTXSystem(U16, BOOLEAN) */
EXTERN_C_LINKAGE void MApp_TTX_SetDTV_TTXSystem (U16 pid, BOOLEAN bExitPVR) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_TTX_SetDTV_TTXSystem (U16 pid, BOOLEAN bExitPVR) 
{
}

/** Auto-generated stub definition for function: U32 msAPI_TTX_GetVBI_BufferSize(void) */
EXTERN_C_LINKAGE U32 msAPI_TTX_GetVBI_BufferSize () ;
EXTERN_C_LINKAGE U32 CppTest_Auto_Stub_msAPI_TTX_GetVBI_BufferSize (void) 
{
    return 0UL;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_TTX_IsTeletextOffSuddenly(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_TTX_IsTeletextOffSuddenly () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_TTX_IsTeletextOffSuddenly (void) 
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MApp_TTX_InitVBITeletext(void) */
EXTERN_C_LINKAGE void MApp_TTX_InitVBITeletext () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_TTX_InitVBITeletext (void) 
{
}

/** Auto-generated stub definition for function: void msAPI_TTX_CollectPackets(void) */
EXTERN_C_LINKAGE void msAPI_TTX_CollectPackets () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_msAPI_TTX_CollectPackets (void) 
{
}

/** Auto-generated stub definition for function: EN_TELETEXT_MODE MApp_TTX_GetControlMode(void) */
EXTERN_C_LINKAGE EN_TELETEXT_MODE MApp_TTX_GetControlMode () ;
EXTERN_C_LINKAGE EN_TELETEXT_MODE CppTest_Auto_Stub_MApp_TTX_GetControlMode (void) 
{
    return TTX_MODE_NORMAL;
}

/** Auto-generated stub definition for function: FUNCTION_RESULT MApp_TTX_TeletextCommand(TELETEXT_COMMAND) */
EXTERN_C_LINKAGE FUNCTION_RESULT MApp_TTX_TeletextCommand (TELETEXT_COMMAND eCommand) ;
EXTERN_C_LINKAGE FUNCTION_RESULT CppTest_Auto_Stub_MApp_TTX_TeletextCommand (TELETEXT_COMMAND eCommand) 
{
    return E_RESULT_SUCCESS;
}

/** Auto-generated stub definition for function: MS_U8 msAPI_TTX_GetWssStatus(void) */
EXTERN_C_LINKAGE MS_U8 msAPI_TTX_GetWssStatus () ;
EXTERN_C_LINKAGE MS_U8 CppTest_Auto_Stub_msAPI_TTX_GetWssStatus (void) 
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MApp_TTX_Reset_TTX_Info(void) */
EXTERN_C_LINKAGE void MApp_TTX_Reset_TTX_Info () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_TTX_Reset_TTX_Info (void) 
{
}

/** Auto-generated stub definition for function: void msAPI_TTX_SetTTXFid(U_INT8) */
EXTERN_C_LINKAGE void msAPI_TTX_SetTTXFid (U_INT8 u8DTVTTXFid) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_msAPI_TTX_SetTTXFid (U_INT8 u8DTVTTXFid) 
{
}

/** Auto-generated stub definition for function: void MApp_TTX_Reflesh(void) */
EXTERN_C_LINKAGE void MApp_TTX_Reflesh () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_TTX_Reflesh (void) 
{
}

/** Auto-generated stub definition for function: BOOLEAN msAPI_TTX_GetStationNameFromTeletext(BYTE *, BYTE, BYTE *) */
EXTERN_C_LINKAGE BOOLEAN msAPI_TTX_GetStationNameFromTeletext (BYTE * sStationName, BYTE bArraySize, BYTE * pcPriority) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_msAPI_TTX_GetStationNameFromTeletext (BYTE * sStationName, BYTE bArraySize, BYTE * pcPriority) 
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: BOOLEAN msAPI_TTX_CheckTTXSignal(void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_TTX_CheckTTXSignal () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_msAPI_TTX_CheckTTXSignal (void) 
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MApp_TTX_ClockMode_Monitor(void) */
EXTERN_C_LINKAGE void MApp_TTX_ClockMode_Monitor () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_TTX_ClockMode_Monitor (void) 
{
}

/** Auto-generated stub definition for function: BOOLEAN msAPI_TTX_CheckTTXClockSignal(void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_TTX_CheckTTXClockSignal () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_msAPI_TTX_CheckTTXClockSignal (void) 
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: FUNCTION_RESULT MApp_TTX_SetCountry(MEMBER_COUNTRY) */
EXTERN_C_LINKAGE FUNCTION_RESULT MApp_TTX_SetCountry (MEMBER_COUNTRY eCountry) ;
EXTERN_C_LINKAGE FUNCTION_RESULT CppTest_Auto_Stub_MApp_TTX_SetCountry (MEMBER_COUNTRY eCountry) 
{
    return E_RESULT_SUCCESS;
}

/** Auto-generated stub definition for function: void msAPI_TTX_SetSource(U8) */
EXTERN_C_LINKAGE void msAPI_TTX_SetSource (U8 source) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_msAPI_TTX_SetSource (U8 source) 
{
}

/** Auto-generated stub definition for function: U32 msAPI_TTX_GetVBIStartAddress(void) */
EXTERN_C_LINKAGE U32 msAPI_TTX_GetVBIStartAddress () ;
EXTERN_C_LINKAGE U32 CppTest_Auto_Stub_msAPI_TTX_GetVBIStartAddress (void) 
{
    return 0UL;
}
