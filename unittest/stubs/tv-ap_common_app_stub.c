#include "cpptest.h"

/**
 * This file contains user stub definitions.
 *
 * To create a user stub:
 * 1. Open stub template list:
 *    - Eclipse IDE: type 'stub' and press <Ctrl> <Space>
 *    - Microsoft Visual Studio IDE: use context menu C++test->Insert Snippet...
 * 2. Choose the stub template from the list.
 * 3. #include the header file where the function you want to stub is originally
 *    declared as well as any supporting header files as necessary.
 * 4. Fill out the stub signature to match that of the original function,
 *    while keeping the CppTest_Stub prefix when it applies.
 *    Note: for C++ operators, use appropriate stub names - e.g.:
 *        CppTest_Stub_operator_new    for operator new
 *        CppTest_Stub_operator_delete for operator delete
 *        CppTest_Stub_operator_plus   for operator +
 *    Refer to C++test User's Guide for a complete list of stub names for operators.
 * 5. Fill out the body of the stub according to intent.
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
#include "MsTypes.h"
#include "datatype.h"
#include "drvXC_IOPort.h"
#include "apiXC.h"
#include "apiXC_Adc.h"
#include "MApp_PCMode.h"
#include "MApp_Font.h"
#include "msAPI_FreqTableCommon.h"
#include "mapp_si_if.h"
#include "MApp_GlobalSettingSt.h"
#include "MApp_Scan.h"
#include "msAPI_DTVSystem.h"
/** User stub definition for function: MS_U16 MApp_PCMode_Get_HResolution(SCALER_WIN, MS_BOOL) */
EXTERN_C_LINKAGE MS_U16 MApp_PCMode_Get_HResolution (SCALER_WIN eWindow, MS_BOOL IsYpbprOrVga) ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApp_PCMode_Get_HResolution (SCALER_WIN eWindow, MS_BOOL IsYpbprOrVga)
{
    if( CppTest_IsCurrentTestCase("TestSuite_MApp_Scaler_test__MApp_Scaler_ProgAnalogWin_YPbPr_2x") )
    {
        return 720; // 480i - H resolution = 720
    }

    return (unsigned short)0;
}

/** User stub definition for function: PCMODE_SyncStatus MApp_PCMode_GetCurrentState(SCALER_WIN) */
EXTERN_C_LINKAGE PCMODE_SyncStatus MApp_PCMode_GetCurrentState (SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE PCMODE_SyncStatus CppTest_Stub_MApp_PCMode_GetCurrentState (SCALER_WIN eWindow)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_else_if1"))
	{
		return E_PCMODE_STABLE_UN_SUPPORT_MODE;
	}
	else if( CppTest_IsCurrentTestCase("TestSuite_MApp_GlobalFunction_test_MApp_IsSrcHasSignal_true") ||
				CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_UNSUPPORT_MODE")
			)
	{
		return E_PCMODE_STABLE_SUPPORT_MODE;
	}
	else if( CppTest_IsCurrentTestCase("TestSuite_MApp_GlobalFunction_test_MApp_IsSrcHasSignal_false") )
	{
		return E_PCMODE_UNSTABLE;
	}
	else
	{
		return E_PCMODE_NOSYNC;
	}
}

/** User stub definition for function: void MApp_PCMode_Reset(SCALER_WIN) */
EXTERN_C_LINKAGE void MApp_PCMode_Reset (SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_PCMode_Reset (SCALER_WIN eWindow)
{
}

/** User stub definition for function: void MApp_PC_MainWin_Handler(INPUT_SOURCE_TYPE_t, BOOLEAN) */
EXTERN_C_LINKAGE void MApp_PC_MainWin_Handler (INPUT_SOURCE_TYPE_t src, BOOLEAN bRealTimeMonitorOnly) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_PC_MainWin_Handler (INPUT_SOURCE_TYPE_t src, BOOLEAN bRealTimeMonitorOnly)
{
}

/** User stub definition for function: void MApp_PC_SubWin_Handler(INPUT_SOURCE_TYPE_t, BOOLEAN) */
EXTERN_C_LINKAGE void MApp_PC_SubWin_Handler (INPUT_SOURCE_TYPE_t src, BOOLEAN bRealTimeMonitorOnly) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_PC_SubWin_Handler (INPUT_SOURCE_TYPE_t src, BOOLEAN bRealTimeMonitorOnly)
{
}

/** User stub definition for function: void MApp_LoadFont_SetVecFontInfo(LOADFONT_STRUCT *, U8, U8) */
EXTERN_C_LINKAGE void MApp_LoadFont_SetVecFontInfo (LOADFONT_STRUCT * strfont, U8 u8Begin, U8 u8End) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_LoadFont_SetVecFontInfo (LOADFONT_STRUCT * strfont, U8 u8Begin, U8 u8End)
{
}

/** User stub definition for function: void MAPP_PCMode_PIP_ChangeAudioSource2HDMI(SCALER_WIN) */
EXTERN_C_LINKAGE void MAPP_PCMode_PIP_ChangeAudioSource2HDMI (SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MAPP_PCMode_PIP_ChangeAudioSource2HDMI (SCALER_WIN eWindow)
{
}

/** User stub definition for function: void MApp_PCMode_SaveModeRamSetting(SCALER_WIN) */
EXTERN_C_LINKAGE void MApp_PCMode_SaveModeRamSetting (SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_PCMode_SaveModeRamSetting (SCALER_WIN eWindow)
{
}

/** User stub definition for function: MS_U16 MApp_PCMode_Get_VResolution(SCALER_WIN, MS_BOOL) */
EXTERN_C_LINKAGE MS_U16 MApp_PCMode_Get_VResolution (SCALER_WIN eWindow, MS_BOOL IsYpbprOrVga) ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApp_PCMode_Get_VResolution (SCALER_WIN eWindow, MS_BOOL IsYpbprOrVga)
{
    return (unsigned short)0;
}

/** User stub definition for function: BOOLEAN MApp_PCMode_IsAspectRatioWide(INPUT_SOURCE_TYPE_t) */
EXTERN_C_LINKAGE BOOLEAN MApp_PCMode_IsAspectRatioWide (INPUT_SOURCE_TYPE_t enInputSourceType) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_PCMode_IsAspectRatioWide (INPUT_SOURCE_TYPE_t enInputSourceType)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U8 MApp_PCMode_Get_Mode_Idx(SCALER_WIN) */
EXTERN_C_LINKAGE MS_U8 MApp_PCMode_Get_Mode_Idx (SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApp_PCMode_Get_Mode_Idx (SCALER_WIN eWindow)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN MApp_RGB_Setting_Auto(XC_Auto_CalibrationType, SCALER_WIN) */
EXTERN_C_LINKAGE BOOLEAN MApp_RGB_Setting_Auto (XC_Auto_CalibrationType type, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_RGB_Setting_Auto (XC_Auto_CalibrationType type, SCALER_WIN eWindow)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN MApp_YPbPr_Setting_Auto(XC_Auto_CalibrationType, SCALER_WIN) */
EXTERN_C_LINKAGE BOOLEAN MApp_YPbPr_Setting_Auto (XC_Auto_CalibrationType type, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_YPbPr_Setting_Auto (XC_Auto_CalibrationType type, SCALER_WIN eWindow)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN MApp_PCMode_Enable_SelfAuto(BOOLEAN, SCALER_WIN) */
EXTERN_C_LINKAGE BOOLEAN MApp_PCMode_Enable_SelfAuto (BOOLEAN EnableAuto, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_PCMode_Enable_SelfAuto (BOOLEAN EnableAuto, SCALER_WIN eWindow)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApp_PCMode_RunSelfAuto(SCALER_WIN) */
EXTERN_C_LINKAGE void MApp_PCMode_RunSelfAuto (SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_PCMode_RunSelfAuto (SCALER_WIN eWindow)
{
}

/** User stub definition for function: void msAPI_CM_GetCountry(void) */
EXTERN_C_LINKAGE MEMBER_COUNTRY msAPI_CM_GetCountry (void) ;
EXTERN_C_LINKAGE MEMBER_COUNTRY CppTest_Stub_msAPI_CM_GetCountry (void)
{
	if( CppTest_IsCurrentTestCase("TestSuit_MApp_Scan_test_MApp_DTV_Scan_Init_COUNTRY_NORWAY") )
	{
		return E_NORWAY;
	}

}

/** User stub definition for function: BOOLEAN msAPI_SI_IsSpecificCountry(EN_SI_COUNTRY_SETTING eCountry, E_SI_SPECIFIC_COUNTRY eSpecificCountry) */
EXTERN_C_LINKAGE BOOLEAN msAPI_SI_IsSpecificCountry(EN_SI_COUNTRY_SETTING eCountry, E_SI_SPECIFIC_COUNTRY eSpecificCountry) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_SI_IsSpecificCountry(EN_SI_COUNTRY_SETTING eCountry, E_SI_SPECIFIC_COUNTRY eSpecificCountry)
{
	if( CppTest_IsCurrentTestCase("TestSuit_MApp_Scan_test_MApp_DTV_Scan_End_step1") )
	{
		return TRUE;
	}
}

/** User stub definition for function: EN_LOSS_SIGNAL_STATE MApp_GetOSDCountrySetting(void) */
EXTERN_C_LINKAGE EN_LOSS_SIGNAL_STATE MApp_DTV_Scan_GetLossSignalState(void);
EXTERN_C_LINKAGE EN_LOSS_SIGNAL_STATE CppTest_Stub_MApp_DTV_Scan_GetLossSignalState(void)
{
	if( CppTest_IsCurrentTestCase("TestSuit_MApp_Scan_test_MApp_Scan_AddOneDTVPchVchs_logic1") )
	{
        return LOSS_SIGNAL_RETUNE;
	}
}

/** User stub definition for function: WORD msAPI_CM_GetService_ID(MEMBER_SERVICETYPE bServiceType, WORD wPosition) */
EXTERN_C_LINKAGE WORD msAPI_CM_GetService_ID(MEMBER_SERVICETYPE bServiceType, WORD wPosition);
EXTERN_C_LINKAGE WORD CppTest_Stub_msAPI_CM_GetService_ID(MEMBER_SERVICETYPE bServiceType, WORD wPosition)
{
	if( CppTest_IsCurrentTestCase("TestSuit_MApp_Scan_test_MApp_Scan_AddOneDTVPchVchs_logic1") )
	{
		return 0;
	}
}

/** User stub definition for function: WORD msAPI_CM_GetON_ID(MEMBER_SERVICETYPE bServiceType, WORD wPosition) */
EXTERN_C_LINKAGE WORD msAPI_CM_GetON_ID(MEMBER_SERVICETYPE bServiceType, WORD wPosition);
EXTERN_C_LINKAGE WORD CppTest_Stub_msAPI_CM_GetON_ID(MEMBER_SERVICETYPE bServiceType, WORD wPosition)
{
	if( CppTest_IsCurrentTestCase("TestSuit_MApp_Scan_test_MApp_Scan_AddOneDTVPchVchs_logic1") )
	{
		return 0;
	}
}


/** User stub definition for function: BOOLEAN msAPI_SI_AddProgramIDTable(SI_DTVPROGRAMID *pstDtvIDTable, BYTE *u8IDIdex) */
EXTERN_C_LINKAGE BOOLEAN msAPI_SI_AddProgramIDTable(SI_DTVPROGRAMID *pstDtvIDTable, WORD *u8IDIdex);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_SI_AddProgramIDTable(SI_DTVPROGRAMID *pstDtvIDTable, BYTE *u8IDIdex)
{
	if( CppTest_IsCurrentTestCase("TestSuit_MApp_Scan_test_MApp_Scan_AddOneDTVPchVchs_logic0") ||
	    CppTest_IsCurrentTestCase("TestSuit_MApp_Scan_test_MApp_Scan_AddOneDTVPchVchs_logic1") )
	{
		return 0;
	}
}


