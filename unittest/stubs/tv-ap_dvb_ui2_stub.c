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
/*
 * tv-ap_dvb_ui2_stub.c
 *
 *  Created on: Aug 23, 2013
 *      Author: muters
 */


#include "MApp_ZUI_APIcommon.h"
#include "MApp_ZUI_Main.h"
#include "MApp_ZUI_ACTeffect.h"

#include "MApp_ZUI_APIwindow.h"
#include "MApp_ZUI_APItables.h"


#include "IOUtil.h"
#include "drvMFC.h"
#include "mw_debug.h"
#include "MApp_ZUI_CTLdynalist.h"
#include "MApp_DTV_ManualTuning_Main.h"
#include "MApp_ATV_ManualTuning_Main.h"
#include "MApp_CADTV_ManualTuning_Main.h"
#include "MApp_ZUI_ACTatvmanualtuning.h"
#include "MApp_ZUI_ACTdtvmanualtuning.h"
#include "MApp_ZUI_ACTcadtvmanualtuning.h"
#include "MApp_UiPvr.h"
#include "MApp_InputSource_Main.h"
#include "MApp_ZUI_ACTepg.h"
#include "MApp_ZUI_ACTglobal.h"
#include "MApp_ZUI_ACTinputsource.h"
#include "MApp_ZUI_ACTinstall.h"
#include "MApp_ZUI_ACTmainpage.h"
#include "MApp_ZUI_ACTpvr.h"
#include "MApp_ZUI_ACTpvrBrowser.h"
#include "MApp_PVR_Main.h"
#include "MApp_Menu_Main.h"

#include "MApp_ZUI_ACTaudiovolume.h"
#include "MApp_ZUI_ACTaudlang.h"
#include "MApp_ZUI_ACTautotuning.h"
#include "MApp_ZUI_ACTchannelinfo.h"
#include "MApp_ZUI_ACTchlist.h"
#include "MApp_ZUI_ACTcoexistWin.h"
#include "MApp_ZUI_ACToad.h"

#define _ZUI_INTERNAL_INSIDE_   //for include MApp_ZUI_APIcomponent.h
#include "MApp_ZUI_APIcomponent.h"
#include "MApp_UiMenuDef.h"



/** Auto-generated stub definition for variable: WORD g_CurSignalStrength */
EXTERN_C_LINKAGE_START
extern WORD g_CurSignalStrength;
extern WORD CppTest_Variable_Auto_Stub_g_CurSignalStrength = (unsigned short)0;
extern SORT_TYPE g_PVRBrowerSort=0;
extern U16 g_PvrBrowser_TotalItem=0;
extern U16 g_PvrBrowser_PageStartItem=0;
extern U16 g_u16DiskSpeed=0;
extern U8  g_PvrBrowser_FocusItem=0;
extern U8  g_u8PVRActiveDisk=0;
extern U8  g_u8PVRActiveDevice=0;
extern U8  g_u8MenuMainItemIndex=0;
extern U8  u8InfoScrollLineCount=0;
extern U8  _u8InfoScrollLineCount=0;
extern U8  u8CoexistWinType=0;
extern U8  u8IsBriefChInfo=0;
extern U8  u8InfoScrollLineCount_Pre=0;

extern PvrMenuPageType  g_PvrMenuPageType=0;
extern EN_PVR_MENU_STATE enPvrState=0;
extern EN_PVR_RECORDER_STATUS    g_PVR_RecordStatus=0;
extern COMMON_DLG_MODE _eCommonDlgMode=0;
extern EN_MENU_RETURN_ITEM _enReturnMenuItem=0;
extern EN_MENU_STATE enMainMenuState=0;
extern EN_PVR_CHECK_FILE_SYSTEM_STATUS g_PVRCheckFSStatus=0;
extern EN_PVR_CHECK_FILE_SYSTEM_MODE   g_PVRCheckFSMode=0;

extern E_OSD_ID _eActiveOSD;
E_OSD_ID CppTest_Variable_Auto_Stub__eActiveOSD = 0;
extern EN_OSD_TUNE_TYPE_SETTING eTuneType;
EN_OSD_TUNE_TYPE_SETTING CppTest_Variable_Auto_Stub_eTuneType = 0;

EXTERN_C_LINKAGE_END

/** Auto-generated stub definition for variable: U16 Audio_L */
EXTERN_C_LINKAGE_START
extern U16 Audio_L;
U16 CppTest_Variable_Auto_Stub_Audio_L = (unsigned short)0;
EXTERN_C_LINKAGE_END

/** Auto-generated stub definition for variable: U16 OSD_L */
EXTERN_C_LINKAGE_START
extern U16 OSD_L;
U16 CppTest_Variable_Auto_Stub_OSD_L = (unsigned short)0;
EXTERN_C_LINKAGE_END

/** Auto-generated stub definition for variable: U16  u16StringBuffer[1024] */
EXTERN_C_LINKAGE_START
extern U16  u16StringBuffer[1024];
U16  CppTest_Variable_Auto_Stub_u16StringBuffer[1024] = {(unsigned short)0, (unsigned short)0, (unsigned short)0, (unsigned short)0, (unsigned short)0, (unsigned short)0, (unsigned short)0, (unsigned short)0, (unsigned short)0, (unsigned short)0, (unsigned short)0, (unsigned short)0, (unsigned short)0, (unsigned short)0, (unsigned short)0, (unsigned short)0, (unsigned short)0, (unsigned short)0, (unsigned short)0, (unsigned short)0};
EXTERN_C_LINKAGE_END

/** Auto-generated stub definition for variable: U16 OffTime */
EXTERN_C_LINKAGE_START
extern U16 OffTime;
U16 CppTest_Variable_Auto_Stub_OffTime = (unsigned short)0;
EXTERN_C_LINKAGE_END

extern ZUI_STATE _eZUIState;
ZUI_STATE CppTest_Variable_Auto_Stub__eZUIState = E_ZUI_STATE_UNKNOW;

extern EN_SCREENSAVER_TYPE enCurScreenSaver[2];
EN_SCREENSAVER_TYPE CppTest_Variable_Auto_Stub_enCurScreenSaver[2] = {0, 0};

extern EN_MONITOR_MHEG5_STATE enCheckMHEGLoadingStatus;
EN_MONITOR_MHEG5_STATE CppTest_Variable_Auto_Stub_enCheckMHEGLoadingStatus=0;

extern L_MENU_GENSETTING stLMGenSetting;
//L_MENU_GENSETTING CppTest_Variable_Auto_Stub_stLMGenSetting = (L_MENU_GENSETTING *)0;
L_MENU_GENSETTING CppTest_Variable_Auto_Stub_stLMGenSetting = {0, 0, 0};

/** Auto-generated stub definition for variable: BOOLEAN bExitMheg5AsScartInserted */
EXTERN_C_LINKAGE_START
extern BOOLEAN bExitMheg5AsScartInserted;
BOOLEAN CppTest_Variable_Auto_Stub_bExitMheg5AsScartInserted = (unsigned char)0;
EXTERN_C_LINKAGE_END


/** Auto-generated stub definition for variable: U32 u32MonitorDiagnosticsSnrTimer */
EXTERN_C_LINKAGE_START
extern U32 u32MonitorDiagnosticsSnrTimer;
U32 CppTest_Variable_Auto_Stub_u32MonitorDiagnosticsSnrTimer = 0UL;
EXTERN_C_LINKAGE_END


/** Auto-generated stub definition for variable: BOOLEAN UI_Hotkey_Subtitle */
EXTERN_C_LINKAGE_START
extern BOOLEAN UI_Hotkey_Subtitle;
BOOLEAN CppTest_Variable_Auto_Stub_UI_Hotkey_Subtitle = (unsigned char)0;
EXTERN_C_LINKAGE_END

/** Auto-generated stub definition for variable: U8 g_u8LRAudioMode */
EXTERN_C_LINKAGE_START
extern U8 g_u8LRAudioMode;
U8 CppTest_Variable_Auto_Stub_g_u8LRAudioMode = (unsigned char)0;
EXTERN_C_LINKAGE_END

/** Auto-generated stub definition for variable: U32 u32MonitorOsdTimer */
EXTERN_C_LINKAGE_START
extern U32 u32MonitorOsdTimer;
U32 CppTest_Variable_Auto_Stub_u32MonitorOsdTimer = 0UL;
EXTERN_C_LINKAGE_END

/** Auto-generated stub definition for variable: U32 u32InfoOSD_Duration */
EXTERN_C_LINKAGE_START
extern U32 u32InfoOSD_Duration;
U32 CppTest_Variable_Auto_Stub_u32InfoOSD_Duration = 0UL;
EXTERN_C_LINKAGE_END

/** Auto-generated stub definition for variable: U8 u8SubtitleItemSelIdx */
EXTERN_C_LINKAGE_START
extern U8 u8SubtitleItemSelIdx;
U8 CppTest_Variable_Auto_Stub_u8SubtitleItemSelIdx = (unsigned char)0;
EXTERN_C_LINKAGE_END


EXTERN_C_LINKAGE_START
extern DRAW_BITMAP _ZUI_TBLSEG _Zui_Bitmap_List[];
DRAW_BITMAP _ZUI_TBLSEG CppTest_Variable_Auto_Stub__Zui_Bitmap_List[] = {0};
extern DRAW_FILL_RECT _ZUI_TBLSEG _Zui_FillRect_List[];
DRAW_FILL_RECT _ZUI_TBLSEG CppTest_Variable_Auto_Stub__Zui_FillRect_List[] = {0};
extern DRAW_TEXT_OUT _ZUI_TBLSEG _Zui_TextOut_List[];
DRAW_TEXT_OUT _ZUI_TBLSEG CppTest_Variable_Auto_Stub__Zui_TextOut_List[] = {0};
extern DRAW_RECT _ZUI_TBLSEG _Zui_Rect_List[];
DRAW_RECT _ZUI_TBLSEG CppTest_Variable_Auto_Stub__Zui_Rect_List[] = {0};
extern DRAW_RECT_BORDER _ZUI_TBLSEG _Zui_RectBorder_List[];
DRAW_RECT_BORDER _ZUI_TBLSEG CppTest_Variable_Auto_Stub__Zui_RectBorder_List[] = {0};
extern OSDPAGETABLE code OsdTables[];
OSDPAGETABLE code CppTest_Variable_Auto_Stub_OsdTables[] = {0};
extern OSDPAGE_TRANSEFF_TABLE code OsdTransEffTables[];
OSDPAGE_TRANSEFF_TABLE code CppTest_Variable_Auto_Stub_OsdTransEffTables[] = {0};
extern OSDPAGEWNDDRAWSTYLETABLE code OsdDrawStyleTables[];
OSDPAGEWNDDRAWSTYLETABLE code CppTest_Variable_Auto_Stub_OsdDrawStyleTables[] = {0};
extern OSDPAGEWNDPOSTABLE code OsdWndPosTables[];
OSDPAGEWNDPOSTABLE code CppTest_Variable_Auto_Stub_OsdWndPosTables[] = {0};

EXTERN_C_LINKAGE_END

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_ExecuteDtvManualTuningAction(U16) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_ExecuteDtvManualTuningAction (U16 act) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_ExecuteDtvManualTuningAction (U16 act)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_DtvManualTuningWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_DtvManualTuningWinProc (HWND hwnd, PMSG msg) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_DtvManualTuningWinProc (HWND hwnd, PMSG msg)
{
    return 0L;
}

/** Auto-generated stub definition for function: EN_RET MApp_DTV_ManualTuning_Main(void) */
EXTERN_C_LINKAGE EN_RET MApp_DTV_ManualTuning_Main () ;
EXTERN_C_LINKAGE EN_RET CppTest_Auto_Stub_MApp_DTV_ManualTuning_Main (void)
{
    return EXIT_NULL;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_AppShowAtvManualTuning(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_AppShowAtvManualTuning () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_AppShowAtvManualTuning (void)
{
}

/** Auto-generated stub definition for function: LPTSTR MApp_ZUI_ACT_GetAtvManualTuningDynamicText(HWND) */
EXTERN_C_LINKAGE LPTSTR MApp_ZUI_ACT_GetAtvManualTuningDynamicText (HWND hwnd) ;
EXTERN_C_LINKAGE LPTSTR CppTest_Auto_Stub_MApp_ZUI_ACT_GetAtvManualTuningDynamicText (HWND hwnd)
{
    return (LPTSTR)0;
}

/** Auto-generated stub definition for function: EN_RET MApp_ATV_ManualTuning_Main(void) */
EXTERN_C_LINKAGE EN_RET MApp_ATV_ManualTuning_Main (void) ;
EXTERN_C_LINKAGE EN_RET CppTest_Auto_Stub_MApp_ATV_ManualTuning_Main (void)
{
    return EXIT_NULL;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_ExecuteAtvManualTuningAction(U16) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_ExecuteAtvManualTuningAction (U16 act) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_ExecuteAtvManualTuningAction (U16 act)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_TerminateDtvManualTuning(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_TerminateDtvManualTuning () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_TerminateDtvManualTuning (void)
{
}


/** Auto-generated stub definition for function: S16 MApp_ZUI_ACT_GetDtvManualTuningDynamicValue(HWND) */
EXTERN_C_LINKAGE S16 MApp_ZUI_ACT_GetDtvManualTuningDynamicValue (HWND hwnd) ;
EXTERN_C_LINKAGE S16 CppTest_Auto_Stub_MApp_ZUI_ACT_GetDtvManualTuningDynamicValue (HWND hwnd)
{
    return (short)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_TerminateAtvManualTuning(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_TerminateAtvManualTuning () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_TerminateAtvManualTuning (void)
{
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_AtvManualTuningWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_AtvManualTuningWinProc (HWND hwnd, PMSG msg) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_AtvManualTuningWinProc (HWND hwnd, PMSG msg)
{
    return 0L;
}


/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_HandleDtvManualTuningKey(VIRTUAL_KEY_CODE) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_HandleDtvManualTuningKey (VIRTUAL_KEY_CODE key) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_HandleDtvManualTuningKey (VIRTUAL_KEY_CODE key)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_AppShowDtvManualTuning(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_AppShowDtvManualTuning () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_AppShowDtvManualTuning (void)
{
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_HandleAtvManualTuningKey(VIRTUAL_KEY_CODE) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_HandleAtvManualTuningKey (VIRTUAL_KEY_CODE key) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_HandleAtvManualTuningKey (VIRTUAL_KEY_CODE key)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: GUI_ENUM_DYNAMIC_LIST_STATE MApp_ZUI_ACT_QueryAtvManualTuningStatus(HWND) */
EXTERN_C_LINKAGE GUI_ENUM_DYNAMIC_LIST_STATE MApp_ZUI_ACT_QueryAtvManualTuningStatus (HWND hwnd) ;
EXTERN_C_LINKAGE GUI_ENUM_DYNAMIC_LIST_STATE CppTest_Auto_Stub_MApp_ZUI_ACT_QueryAtvManualTuningStatus (HWND hwnd)
{
    return EN_DL_STATE_HIDDEN;
}

/** Auto-generated stub definition for function: LPTSTR MApp_ZUI_ACT_GetDtvManualTuningDynamicText(HWND) */
EXTERN_C_LINKAGE LPTSTR MApp_ZUI_ACT_GetDtvManualTuningDynamicText (HWND hwnd) ;
EXTERN_C_LINKAGE LPTSTR CppTest_Auto_Stub_MApp_ZUI_ACT_GetDtvManualTuningDynamicText (HWND hwnd)
{
    return (LPTSTR)0;
}

/** Auto-generated stub definition for function: void MApp_UiPvr_VirtualKeyProcessor(HWND) */
EXTERN_C_LINKAGE void MApp_UiPvr_VirtualKeyProcessor (HWND current) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_UiPvr_VirtualKeyProcessor (HWND current)
{
}

/** Auto-generated stub definition for function: EN_PVR_KEY_INPUT_RETURN MApp_UiPvr_KeyProcessor(void) */
EXTERN_C_LINKAGE EN_PVR_KEY_INPUT_RETURN MApp_UiPvr_KeyProcessor () ;
EXTERN_C_LINKAGE EN_PVR_KEY_INPUT_RETURN CppTest_Auto_Stub_MApp_UiPvr_KeyProcessor (void)
{
    return EN_PVR_KEYRTN_NONE;
}

/** Auto-generated stub definition for function: U8 MApp_UiPvr_PlaybackGetPlaybackPercentage(void) */
EXTERN_C_LINKAGE U8 MApp_UiPvr_PlaybackGetPlaybackPercentage () ;
EXTERN_C_LINKAGE U8 CppTest_Auto_Stub_MApp_UiPvr_PlaybackGetPlaybackPercentage (void)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MApp_UiPvr_CheckFS_StartCheckAll(void) */
EXTERN_C_LINKAGE void MApp_UiPvr_CheckFS_StartCheckAll () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_UiPvr_CheckFS_StartCheckAll (void)
{
}


/** Auto-generated stub definition for function: void MApp_UiPvr_RecordStop(void) */
EXTERN_C_LINKAGE void MApp_UiPvr_RecordStop () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_UiPvr_RecordStop (void)
{
}

/** Auto-generated stub definition for function: U8 MApp_UiPvr_TimeShiftGetPlaybackPercentage(void) */
EXTERN_C_LINKAGE U8 MApp_UiPvr_TimeShiftGetPlaybackPercentage () ;
EXTERN_C_LINKAGE U8 CppTest_Auto_Stub_MApp_UiPvr_TimeShiftGetPlaybackPercentage (void)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: U8 MApp_UiPvr_CheckFS_GetCheckBulkPercent(void) */
EXTERN_C_LINKAGE U8 MApp_UiPvr_CheckFS_GetCheckBulkPercent () ;
EXTERN_C_LINKAGE U8 CppTest_Auto_Stub_MApp_UiPvr_CheckFS_GetCheckBulkPercent (void)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: MEMBER_SERVICETYPE MApp_UiPvr_Browser_GetPlayingServiceType(void) */
EXTERN_C_LINKAGE MEMBER_SERVICETYPE MApp_UiPvr_Browser_GetPlayingServiceType () ;
EXTERN_C_LINKAGE MEMBER_SERVICETYPE CppTest_Auto_Stub_MApp_UiPvr_Browser_GetPlayingServiceType (void)
{
    return E_SERVICETYPE_ATV;
}

/** Auto-generated stub definition for function: void MApp_UiPvr_CheckFS_StartFormat(void) */
EXTERN_C_LINKAGE void MApp_UiPvr_CheckFS_StartFormat () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_UiPvr_CheckFS_StartFormat (void)
{
}

/** Auto-generated stub definition for function: BOOLEAN MApp_UiPvr_IsRecordingExceedMaxTime(U8) */
EXTERN_C_LINKAGE BOOLEAN MApp_UiPvr_IsRecordingExceedMaxTime (U8 RecorPath) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_UiPvr_IsRecordingExceedMaxTime (U8 RecorPath)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MApp_UiPvr_Browser_UpdateRecordingAttr(void) */
EXTERN_C_LINKAGE void MApp_UiPvr_Browser_UpdateRecordingAttr () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_UiPvr_Browser_UpdateRecordingAttr (void)
{
}

/** Auto-generated stub definition for function: void MApp_UiPvr_PlaybackStop(void) */
EXTERN_C_LINKAGE void MApp_UiPvr_PlaybackStop () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_UiPvr_PlaybackStop (void)
{
}

/** Auto-generated stub definition for function: BOOLEAN MApp_UiPvr_Browser_KeyProcessor(U8) */
EXTERN_C_LINKAGE BOOLEAN MApp_UiPvr_Browser_KeyProcessor (U8 KeyCode) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_UiPvr_Browser_KeyProcessor (U8 KeyCode)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: EN_INPUTSOURCE_STATE MApp_InputSource_GetState(void) */
EXTERN_C_LINKAGE EN_INPUTSOURCE_STATE MApp_InputSource_GetState () ;
EXTERN_C_LINKAGE EN_INPUTSOURCE_STATE CppTest_Auto_Stub_MApp_InputSource_GetState (void)
{
    return STATE_INPUTSOURCE_INIT;
}

/** Auto-generated stub definition for function: void MApp_UiPvr_CheckFS_Confirm_CreatePartition(void) */
EXTERN_C_LINKAGE void MApp_UiPvr_CheckFS_Confirm_CreatePartition () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_UiPvr_CheckFS_Confirm_CreatePartition (void)
{
}

/** Auto-generated stub definition for function: void MApp_UiPvr_Init(void) */
EXTERN_C_LINKAGE void MApp_UiPvr_Init () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_UiPvr_Init (void)
{
}

/** Auto-generated stub definition for function: void MApp_UiPvr_CheckFS_Confirm_Formating(void) */
EXTERN_C_LINKAGE void MApp_UiPvr_CheckFS_Confirm_Formating () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_UiPvr_CheckFS_Confirm_Formating (void)
{
}

/** Auto-generated stub definition for function: EN_MENU_STATE MApp_Menu_Main_GetState(void) */
EXTERN_C_LINKAGE EN_MENU_STATE MApp_Menu_Main_GetState () ;
EXTERN_C_LINKAGE EN_MENU_STATE CppTest_Auto_Stub_MApp_Menu_Main_GetState (void)
{
    return STATE_MENU_INIT;
}

/** Auto-generated stub definition for function: EN_RET MApp_Menu_Main(void) */
EXTERN_C_LINKAGE EN_RET MApp_Menu_Main () ;
EXTERN_C_LINKAGE EN_RET CppTest_Auto_Stub_MApp_Menu_Main (void)
{
    return EXIT_NULL;
}

/** Auto-generated stub definition for function: void MApp_UiPvr_CheckFS_Initial(void) */
EXTERN_C_LINKAGE void MApp_UiPvr_CheckFS_Initial () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_UiPvr_CheckFS_Initial (void)
{
}

/** Auto-generated stub definition for function: EN_RET MApp_InstallGuide_Main(void) */
EXTERN_C_LINKAGE EN_RET MApp_InstallGuide_Main () ;
EXTERN_C_LINKAGE EN_RET CppTest_Auto_Stub_MApp_InstallGuide_Main (void)
{
    return EXIT_NULL;
}

/** Auto-generated stub definition for function: void MApp_UiPvr_Browser_DeInit(void) */
EXTERN_C_LINKAGE void MApp_UiPvr_Browser_DeInit () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_UiPvr_Browser_DeInit (void)
{
}

/** Auto-generated stub definition for function: void MApp_UiPvr_Browser_Init(void) */
EXTERN_C_LINKAGE void MApp_UiPvr_Browser_Init () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_UiPvr_Browser_Init (void)
{
}

/** Auto-generated stub definition for function: void MApp_UiPvr_CheckFS_FlowControl(void) */
EXTERN_C_LINKAGE void MApp_UiPvr_CheckFS_FlowControl () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_UiPvr_CheckFS_FlowControl (void)
{
}

/** Auto-generated stub definition for function: EN_RET MApp_InputSource_Main(void) */
EXTERN_C_LINKAGE EN_RET MApp_InputSource_Main () ;
EXTERN_C_LINKAGE EN_RET CppTest_Auto_Stub_MApp_InputSource_Main (void)
{
    return EXIT_NULL;
}

/** Auto-generated stub definition for function: U8 MApp_UiPvr_TimeShiftGetRecordPercentage(void) */
EXTERN_C_LINKAGE U8 MApp_UiPvr_TimeShiftGetRecordPercentage () ;
EXTERN_C_LINKAGE U8 CppTest_Auto_Stub_MApp_UiPvr_TimeShiftGetRecordPercentage (void)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: enPvrABLoopState MApp_UiPvr_GetABLoop_Status(void) */
EXTERN_C_LINKAGE enPvrABLoopState MApp_UiPvr_GetABLoop_Status () ;
EXTERN_C_LINKAGE enPvrABLoopState CppTest_Auto_Stub_MApp_UiPvr_GetABLoop_Status (void)
{
    return E_ABLOOP_NONE;
}

/** Auto-generated stub definition for function: EN_RET MApp_Epg_Main(void) */
EXTERN_C_LINKAGE EN_RET MApp_Epg_Main () ;
EXTERN_C_LINKAGE EN_RET CppTest_Auto_Stub_MApp_Epg_Main (void)
{
    return EXIT_NULL;
}

/** Auto-generated stub definition for function: void MApp_UiPvr_CheckFS_SelectActiveDisk(void) */
EXTERN_C_LINKAGE void MApp_UiPvr_CheckFS_SelectActiveDisk () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_UiPvr_CheckFS_SelectActiveDisk (void)
{
}

/** Auto-generated stub definition for function: void MApp_UiPvr_UIMonitor(void) */
EXTERN_C_LINKAGE void MApp_UiPvr_UIMonitor () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_UiPvr_UIMonitor (void)
{
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_ButtonAniClickWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_ButtonAniClickWinProc (HWND _MT_var1070, PMSG _MT_var1071) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_ButtonAniClickWinProc (HWND _MT_var156, PMSG _MT_var157)
{
    return 0L;
}

/** Auto-generated stub definition for function: COMMON_SINGLELIST_MODE MApp_ZUI_ACT_GetSingleListMode(void) */
EXTERN_C_LINKAGE COMMON_SINGLELIST_MODE MApp_ZUI_ACT_GetSingleListMode () ;
EXTERN_C_LINKAGE COMMON_SINGLELIST_MODE CppTest_Auto_Stub_MApp_ZUI_ACT_GetSingleListMode (void)
{
    return EN_COMMON_SINGLELIST_INVALID;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_TerminateInputSource(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_TerminateInputSource () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_TerminateInputSource (void)
{
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_EpgTimeItemEventWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_EpgTimeItemEventWinProc (HWND _MT_var1182, PMSG _MT_var1183) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_EpgTimeItemEventWinProc (HWND _MT_var468, PMSG _MT_var469)
{
    return 0L;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_TerminateEpg(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_TerminateEpg () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_TerminateEpg (void)
{
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_HandleInputSourceKey(VIRTUAL_KEY_CODE) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_HandleInputSourceKey (VIRTUAL_KEY_CODE key) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_HandleInputSourceKey (VIRTUAL_KEY_CODE key)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_PvrWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_PvrWinProc (HWND hwnd, PMSG msg) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_PvrWinProc (HWND hwnd, PMSG msg)
{
    return 0L;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_SetOptionListMode(COMMON_OPTIONLIST_MODE) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_SetOptionListMode (COMMON_OPTIONLIST_MODE mode) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_SetOptionListMode (COMMON_OPTIONLIST_MODE mode)
{
}

/** Auto-generated stub definition for function: LPTSTR MApp_ZUI_ACT_GetInstallGuideDynamicText(HWND) */
EXTERN_C_LINKAGE LPTSTR MApp_ZUI_ACT_GetInstallGuideDynamicText (HWND hwnd) ;
EXTERN_C_LINKAGE LPTSTR CppTest_Auto_Stub_MApp_ZUI_ACT_GetInstallGuideDynamicText (HWND hwnd)
{
    return (LPTSTR)0;
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_EpgChannelItemWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_EpgChannelItemWinProc (HWND _MT_var1178, PMSG _MT_var1179) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_EpgChannelItemWinProc (HWND _MT_var476, PMSG _MT_var477)
{
    return 0L;
}

/** Auto-generated stub definition for function: S16 MApp_ZUI_ACT_GetPvrDynamicValue(HWND) */
EXTERN_C_LINKAGE S16 MApp_ZUI_ACT_GetPvrDynamicValue (HWND hwnd) ;
EXTERN_C_LINKAGE S16 CppTest_Auto_Stub_MApp_ZUI_ACT_GetPvrDynamicValue (HWND hwnd)
{
    return (short)0;
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_UpDateCECDeviceWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_UpDateCECDeviceWinProc (HWND hwnd, PMSG msg) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_UpDateCECDeviceWinProc (HWND hwnd, PMSG msg)
{
    return 0L;
}

/** Auto-generated stub definition for function: LPTSTR MApp_ZUI_ACT_GetMainMenuDynamicText(HWND) */
EXTERN_C_LINKAGE LPTSTR MApp_ZUI_ACT_GetMainMenuDynamicText (HWND hwnd) ;
EXTERN_C_LINKAGE LPTSTR CppTest_Auto_Stub_MApp_ZUI_ACT_GetMainMenuDynamicText (HWND hwnd)
{
    return (LPTSTR)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_AppShowMainMenu(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_AppShowMainMenu () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_AppShowMainMenu (void)
{
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_ExecutePvrBrowserAction(U16) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_ExecutePvrBrowserAction (U16 act) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_ExecutePvrBrowserAction (U16 act)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: U16 MApp_ZUI_ACT_GetPvrBrowserDynamicBitmap(HWND, DRAWSTYLE_TYPE) */
EXTERN_C_LINKAGE U16 MApp_ZUI_ACT_GetPvrBrowserDynamicBitmap (HWND hwnd, DRAWSTYLE_TYPE ds_type) ;
EXTERN_C_LINKAGE U16 CppTest_Auto_Stub_MApp_ZUI_ACT_GetPvrBrowserDynamicBitmap (HWND hwnd, DRAWSTYLE_TYPE ds_type)
{
    return (unsigned short)0;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_HandleInstallGuideKey(VIRTUAL_KEY_CODE) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_HandleInstallGuideKey (VIRTUAL_KEY_CODE key) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_HandleInstallGuideKey (VIRTUAL_KEY_CODE key)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_EpgTimerSaveDialogWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_EpgTimerSaveDialogWinProc (HWND _MT_var1190, PMSG _MT_var1191) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_EpgTimerSaveDialogWinProc (HWND _MT_var564, PMSG _MT_var565)
{
    return 0L;
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_EpgTitleWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_EpgTitleWinProc (HWND _MT_var1176, PMSG _MT_var1177) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_EpgTitleWinProc (HWND _MT_var452, PMSG _MT_var453)
{
    return 0L;
}

/** Auto-generated stub definition for function: U16 MApp_ZUI_ACT_GetAppItemString(int) */
EXTERN_C_LINKAGE U16 MApp_ZUI_ACT_GetAppItemString (int APP) ;
EXTERN_C_LINKAGE U16 CppTest_Auto_Stub_MApp_ZUI_ACT_GetAppItemString (int APP)
{
    return (unsigned short)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_PVR_OpenUI(PvrMenuPageType) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_PVR_OpenUI (PvrMenuPageType newMenuPageIdx) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_PVR_OpenUI (PvrMenuPageType newMenuPageIdx)
{
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_PvrBrowserWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_PvrBrowserWinProc (HWND hwnd, PMSG msg) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_PvrBrowserWinProc (HWND hwnd, PMSG msg)
{
    return 0L;
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_EpgTimeItemWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_EpgTimeItemWinProc (HWND _MT_var1180, PMSG _MT_var1181) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_EpgTimeItemWinProc (HWND _MT_var460, PMSG _MT_var461)
{
    return 0L;
}

/** Auto-generated stub definition for function: S16 MApp_ZUI_ACT_GetPvrBrowserDynamicValue(HWND) */
EXTERN_C_LINKAGE S16 MApp_ZUI_ACT_GetPvrBrowserDynamicValue (HWND hwnd) ;
EXTERN_C_LINKAGE S16 CppTest_Auto_Stub_MApp_ZUI_ACT_GetPvrBrowserDynamicValue (HWND hwnd)
{
    return (short)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_TerminatePvrBrowser(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_TerminatePvrBrowser () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_TerminatePvrBrowser (void)
{
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_InstallGuideWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_InstallGuideWinProc (HWND _MT_var1157, PMSG _MT_var1158) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_InstallGuideWinProc (HWND _MT_var612, PMSG _MT_var613)
{
    return 0L;
}

/** Auto-generated stub definition for function: COMMON_OPTIONLIST_MODE MApp_ZUI_ACT_GetOptionListMode(void) */
EXTERN_C_LINKAGE COMMON_OPTIONLIST_MODE MApp_ZUI_ACT_GetOptionListMode () ;
EXTERN_C_LINKAGE COMMON_OPTIONLIST_MODE CppTest_Auto_Stub_MApp_ZUI_ACT_GetOptionListMode (void)
{
    return EN_COMMON_OPTIONLIST_INVALID;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_ExecuteInstallGuideAction(U16) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_ExecuteInstallGuideAction (U16 act) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_ExecuteInstallGuideAction (U16 act)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_CheckPvrBypassKey(U8) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_CheckPvrBypassKey (U8 checkedKey) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_CheckPvrBypassKey (U8 checkedKey)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: GUI_ENUM_DYNAMIC_LIST_STATE MApp_ZUI_ACT_QueryInputSourceItemStatus(HWND) */
EXTERN_C_LINKAGE GUI_ENUM_DYNAMIC_LIST_STATE MApp_ZUI_ACT_QueryInputSourceItemStatus (HWND hwnd) ;
EXTERN_C_LINKAGE GUI_ENUM_DYNAMIC_LIST_STATE CppTest_Auto_Stub_MApp_ZUI_ACT_QueryInputSourceItemStatus (HWND hwnd)
{
    return EN_DL_STATE_HIDDEN;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_HandleEpgKey(VIRTUAL_KEY_CODE) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_HandleEpgKey (VIRTUAL_KEY_CODE key) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_HandleEpgKey (VIRTUAL_KEY_CODE key)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: U16 MApp_ZUI_ACT_GetInputSourceDynamicBitmap(HWND, DRAWSTYLE_TYPE) */
EXTERN_C_LINKAGE U16 MApp_ZUI_ACT_GetInputSourceDynamicBitmap (HWND hwnd, DRAWSTYLE_TYPE ds_type) ;
EXTERN_C_LINKAGE U16 CppTest_Auto_Stub_MApp_ZUI_ACT_GetInputSourceDynamicBitmap (HWND hwnd, DRAWSTYLE_TYPE ds_type)
{
    return (unsigned short)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_TerminateMainMenu(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_TerminateMainMenu () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_TerminateMainMenu (void)
{
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_EpgTimerListItemWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_EpgTimerListItemWinProc (HWND _MT_var1188, PMSG _MT_var1189) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_EpgTimerListItemWinProc (HWND _MT_var556, PMSG _MT_var557)
{
    return 0L;
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_InputSourceWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_InputSourceWinProc (HWND _MT_var1142, PMSG _MT_var1143) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_InputSourceWinProc (HWND _MT_var140, PMSG _MT_var141)
{
    return 0L;
}

/** Auto-generated stub definition for function: LPTSTR MApp_ZUI_ACT_GetInputSourceDynamicText(HWND) */
EXTERN_C_LINKAGE LPTSTR MApp_ZUI_ACT_GetInputSourceDynamicText (HWND hwnd) ;
EXTERN_C_LINKAGE LPTSTR CppTest_Auto_Stub_MApp_ZUI_ACT_GetInputSourceDynamicText (HWND hwnd)
{
    return (LPTSTR)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_TerminateInstallGuide(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_TerminateInstallGuide () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_TerminateInstallGuide (void)
{
}

/** Auto-generated stub definition for function: S16 MApp_ZUI_ACT_GetPvrDynamicValue_2(HWND) */
EXTERN_C_LINKAGE S16 MApp_ZUI_ACT_GetPvrDynamicValue_2 (HWND hwnd) ;
EXTERN_C_LINKAGE S16 CppTest_Auto_Stub_MApp_ZUI_ACT_GetPvrDynamicValue_2 (HWND hwnd)
{
    return (short)0;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_HandlePvrKey(VIRTUAL_KEY_CODE) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_HandlePvrKey (VIRTUAL_KEY_CODE key) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_HandlePvrKey (VIRTUAL_KEY_CODE key)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_TV_ProcessEpgCountDownKey(U8) */
EXTERN_C_LINKAGE BOOLEAN MApp_TV_ProcessEpgCountDownKey (U8 key) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_TV_ProcessEpgCountDownKey (U8 key)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void _MApp_ZUI_ACT_OpenCommonDialog(COMMON_DLG_MODE) */
EXTERN_C_LINKAGE void _MApp_ZUI_ACT_OpenCommonDialog (COMMON_DLG_MODE dlg) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub__MApp_ZUI_ACT_OpenCommonDialog (COMMON_DLG_MODE dlg)
{
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_RecordPageActive(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_RecordPageActive () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_RecordPageActive (void)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: U8 MApp_ZUI_ACT_EPGGetDescInfoPageNum(void) */
EXTERN_C_LINKAGE U8 MApp_ZUI_ACT_EPGGetDescInfoPageNum () ;
EXTERN_C_LINKAGE U8 CppTest_Auto_Stub_MApp_ZUI_ACT_EPGGetDescInfoPageNum (void)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: LPTSTR MApp_ZUI_ACT_GetPvrBrowserDynamicText(HWND) */
EXTERN_C_LINKAGE LPTSTR MApp_ZUI_ACT_GetPvrBrowserDynamicText (HWND hwnd) ;
EXTERN_C_LINKAGE LPTSTR CppTest_Auto_Stub_MApp_ZUI_ACT_GetPvrBrowserDynamicText (HWND hwnd)
{
    return (LPTSTR)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_AppShowPVR(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_AppShowPVR () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_AppShowPVR (void)
{
}

/** Auto-generated stub definition for function: MEMBER_SERVICETYPE MApp_EpgUI_Func_Get_CurFocusSrvType(void) */
EXTERN_C_LINKAGE MEMBER_SERVICETYPE MApp_EpgUI_Func_Get_CurFocusSrvType () ;
EXTERN_C_LINKAGE MEMBER_SERVICETYPE CppTest_Auto_Stub_MApp_EpgUI_Func_Get_CurFocusSrvType (void)
{
    return E_SERVICETYPE_ATV;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_AppShowInstallGuide(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_AppShowInstallGuide () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_AppShowInstallGuide (void)
{
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_ButtonAniClickChildWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_ButtonAniClickChildWinProc (HWND _MT_var1072, PMSG _MT_var1073) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_ButtonAniClickChildWinProc (HWND _MT_var164, PMSG _MT_var165)
{
    return 0L;
}

/** Auto-generated stub definition for function: U16 MApp_EpgUI_Func_Get_CurFocusSrvPos(void) */
EXTERN_C_LINKAGE U16 MApp_EpgUI_Func_Get_CurFocusSrvPos () ;
EXTERN_C_LINKAGE U16 CppTest_Auto_Stub_MApp_EpgUI_Func_Get_CurFocusSrvPos (void)
{
    return (unsigned short)0;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_PVR_Check_Switch_Channel(MEMBER_SERVICETYPE, U16) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_PVR_Check_Switch_Channel (MEMBER_SERVICETYPE NewCMType, U16 u16NewPos) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_PVR_Check_Switch_Channel (MEMBER_SERVICETYPE NewCMType, U16 u16NewPos)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_ExecutePvrAction(U16) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_ExecutePvrAction (U16 act) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_ExecutePvrAction (U16 act)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_EpgChannelItemEventWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_EpgChannelItemEventWinProc (HWND _MT_var1184, PMSG _MT_var1185) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_EpgChannelItemEventWinProc (HWND _MT_var484, PMSG _MT_var485)
{
    return 0L;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_ShowMainMenuBackground(HWND) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_ShowMainMenuBackground (HWND hwnd) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_ShowMainMenuBackground (HWND hwnd)
{
}

/** Auto-generated stub definition for function: U16 MApp_ZUI_ACT_GetEpgDynamicBitmap(HWND, DRAWSTYLE_TYPE) */
EXTERN_C_LINKAGE U16 MApp_ZUI_ACT_GetEpgDynamicBitmap (HWND hwnd, DRAWSTYLE_TYPE ds_type) ;
EXTERN_C_LINKAGE U16 CppTest_Auto_Stub_MApp_ZUI_ACT_GetEpgDynamicBitmap (HWND hwnd, DRAWSTYLE_TYPE ds_type)
{
    return (unsigned short)0;
}

/** Auto-generated stub definition for function: GUI_ENUM_DYNAMIC_LIST_STATE MApp_ZUI_ACT_QueryPvrFileSysStatus(HWND) */
EXTERN_C_LINKAGE GUI_ENUM_DYNAMIC_LIST_STATE MApp_ZUI_ACT_QueryPvrFileSysStatus (HWND hwnd) ;
EXTERN_C_LINKAGE GUI_ENUM_DYNAMIC_LIST_STATE CppTest_Auto_Stub_MApp_ZUI_ACT_QueryPvrFileSysStatus (HWND hwnd)
{
    return EN_DL_STATE_HIDDEN;
}

/** Auto-generated stub definition for function: LPTSTR MApp_ZUI_ACT_GetEpgDynamicText(HWND) */
EXTERN_C_LINKAGE LPTSTR MApp_ZUI_ACT_GetEpgDynamicText (HWND hwnd) ;
EXTERN_C_LINKAGE LPTSTR CppTest_Auto_Stub_MApp_ZUI_ACT_GetEpgDynamicText (HWND hwnd)
{
    return (LPTSTR)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_AppShowPvrBrowser(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_AppShowPvrBrowser () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_AppShowPvrBrowser (void)
{
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_HandleMainPageKey(VIRTUAL_KEY_CODE) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_HandleMainPageKey (VIRTUAL_KEY_CODE key) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_HandleMainPageKey (VIRTUAL_KEY_CODE key)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: LPTSTR MApp_ZUI_ACT_GetPvrDynamicText(HWND) */
EXTERN_C_LINKAGE LPTSTR MApp_ZUI_ACT_GetPvrDynamicText (HWND hwnd) ;
EXTERN_C_LINKAGE LPTSTR CppTest_Auto_Stub_MApp_ZUI_ACT_GetPvrDynamicText (HWND hwnd)
{
    return (LPTSTR)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_EpgTimerCountDown(void) */
EXTERN_C_LINKAGE void MApp_ZUI_EpgTimerCountDown () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_EpgTimerCountDown (void)
{
}

/** Auto-generated stub definition for function: U16 MApp_EpgUI_Func_Get_CurFocusEvtIdx(void) */
EXTERN_C_LINKAGE U16 MApp_EpgUI_Func_Get_CurFocusEvtIdx () ;
EXTERN_C_LINKAGE U16 CppTest_Auto_Stub_MApp_EpgUI_Func_Get_CurFocusEvtIdx (void)
{
    return (unsigned short)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_TerminatePVR(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_TerminatePVR () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_TerminatePVR (void)
{
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_ExecuteEpgAction(U16) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_ExecuteEpgAction (U16 act) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_ExecuteEpgAction (U16 act)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_Mainpage_DynamicListWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_Mainpage_DynamicListWinProc (HWND hWnd, PMSG pMsg) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_Mainpage_DynamicListWinProc (HWND hWnd, PMSG pMsg)
{
    return 0L;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_HandlePvrBrowserKey(VIRTUAL_KEY_CODE) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_HandlePvrBrowserKey (VIRTUAL_KEY_CODE key) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_HandlePvrBrowserKey (VIRTUAL_KEY_CODE key)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_SetTargetMenuState(EN_MENU_STATE) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_SetTargetMenuState (EN_MENU_STATE MenuState) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_SetTargetMenuState (EN_MENU_STATE MenuState)
{
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_AppShowInputSource(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_AppShowInputSource () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_AppShowInputSource (void)
{
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_AppShowEpg(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_AppShowEpg () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_AppShowEpg (void)
{
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_ExecuteInputSourceAction(U16) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_ExecuteInputSourceAction (U16 act) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_ExecuteInputSourceAction (U16 act)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_EpgUpdateAllTimeItemWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_EpgUpdateAllTimeItemWinProc (HWND _MT_var1186, PMSG _MT_var1187) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_EpgUpdateAllTimeItemWinProc (HWND _MT_var492, PMSG _MT_var493)
{
    return 0L;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACTcoexistWin_RestoreGwin(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACTcoexistWin_RestoreGwin () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACTcoexistWin_RestoreGwin (void)
{
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_ExecuteAudioVolumeAction(U16) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_ExecuteAudioVolumeAction (U16 act) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_ExecuteAudioVolumeAction (U16 act)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: LPTSTR MApp_ZUI_ACT_GetOADDynamicText(HWND) */
EXTERN_C_LINKAGE LPTSTR MApp_ZUI_ACT_GetOADDynamicText (HWND hwnd) ;
EXTERN_C_LINKAGE LPTSTR CppTest_Auto_Stub_MApp_ZUI_ACT_GetOADDynamicText (HWND hwnd)
{
    return (LPTSTR)0;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_ExecuteChannelListAction(U16) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_ExecuteChannelListAction (U16 act) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_ExecuteChannelListAction (U16 act)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_HandleAutoTuningKey(VIRTUAL_KEY_CODE) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_HandleAutoTuningKey (VIRTUAL_KEY_CODE key) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_HandleAutoTuningKey (VIRTUAL_KEY_CODE key)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_UiMenu_IsCountDownWinShow(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_UiMenu_IsCountDownWinShow () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_UiMenu_IsCountDownWinShow (void)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: U16 MApp_ZUI_ACT_GetChannelInfoDynamicBitmap(HWND, DRAWSTYLE_TYPE) */
EXTERN_C_LINKAGE U16 MApp_ZUI_ACT_GetChannelInfoDynamicBitmap (HWND hwnd, DRAWSTYLE_TYPE ds_type) ;
EXTERN_C_LINKAGE U16 CppTest_Auto_Stub_MApp_ZUI_ACT_GetChannelInfoDynamicBitmap (HWND hwnd, DRAWSTYLE_TYPE ds_type)
{
    return (unsigned short)0;
}

/** Auto-generated stub definition for function: void MApi_XC_SetGammaOnOff(MS_BOOL) */
EXTERN_C_LINKAGE void MApi_XC_SetGammaOnOff (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApi_XC_SetGammaOnOff (MS_BOOL bEnable)
{
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_TerminateAudioLanguage(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_TerminateAudioLanguage () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_TerminateAudioLanguage (void)
{
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_HandleChannelListKey(VIRTUAL_KEY_CODE) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_HandleChannelListKey (VIRTUAL_KEY_CODE key) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_HandleChannelListKey (VIRTUAL_KEY_CODE key)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_AppShowOAD(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_AppShowOAD () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_AppShowOAD (void)
{
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACTcoexist_Create(U8, U16, U16, U16, U16) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACTcoexist_Create (U8 x, U16 win_x, U16 win_y, U16 win_w, U16 win_h) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACTcoexist_Create (U8 x, U16 win_x, U16 win_y, U16 win_w, U16 win_h)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: LPTSTR MApp_ZUI_ACT_GetChannelInfoDynamicText(HWND) */
EXTERN_C_LINKAGE LPTSTR MApp_ZUI_ACT_GetChannelInfoDynamicText (HWND hwnd) ;
EXTERN_C_LINKAGE LPTSTR CppTest_Auto_Stub_MApp_ZUI_ACT_GetChannelInfoDynamicText (HWND hwnd)
{
    return (LPTSTR)0;
}

/** Auto-generated stub definition for function: OSD_COLOR MApp_ZUI_ACT_GetChannelListDynamicColor(HWND, DRAWSTYLE_TYPE, OSD_COLOR) */
EXTERN_C_LINKAGE OSD_COLOR MApp_ZUI_ACT_GetChannelListDynamicColor (HWND hwnd, DRAWSTYLE_TYPE type, OSD_COLOR colorOriginal) ;
EXTERN_C_LINKAGE OSD_COLOR CppTest_Auto_Stub_MApp_ZUI_ACT_GetChannelListDynamicColor (HWND hwnd, DRAWSTYLE_TYPE type, OSD_COLOR colorOriginal)
{
    return 0UL;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_AppShowAutoTuning(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_AppShowAutoTuning () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_AppShowAutoTuning (void)
{
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_HandleAudioLanguageKey(VIRTUAL_KEY_CODE) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_HandleAudioLanguageKey (VIRTUAL_KEY_CODE key) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_HandleAudioLanguageKey (VIRTUAL_KEY_CODE key)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MApp_UiMenu_ARCDiscWin_State(void) */
EXTERN_C_LINKAGE void MApp_UiMenu_ARCDiscWin_State () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_UiMenu_ARCDiscWin_State (void)
{
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACTcoexist_Delete(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACTcoexist_Delete () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACTcoexist_Delete (void)
{
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_TerminateChannelInfo(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_TerminateChannelInfo () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_TerminateChannelInfo (void)
{
}

/** Auto-generated stub definition for function: LPTSTR MApp_ZUI_ACT_GetAudioVolumeDynamicText(HWND) */
EXTERN_C_LINKAGE LPTSTR MApp_ZUI_ACT_GetAudioVolumeDynamicText (HWND hwnd) ;
EXTERN_C_LINKAGE LPTSTR CppTest_Auto_Stub_MApp_ZUI_ACT_GetAudioVolumeDynamicText (HWND hwnd)
{
    return (LPTSTR)0;
}

/** Auto-generated stub definition for function: void MApp_UiMenu_CountDownWin_Create(void) */
EXTERN_C_LINKAGE void MApp_UiMenu_CountDownWin_Create () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_UiMenu_CountDownWin_Create (void)
{
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_ShowUpgradeUI(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_ShowUpgradeUI () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_ShowUpgradeUI (void)
{
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_AppShowChannelList(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_AppShowChannelList () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_AppShowChannelList (void)
{
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_AutoTuningSkipDTVWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_AutoTuningSkipDTVWinProc (HWND hWnd, PMSG pMsg) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_AutoTuningSkipDTVWinProc (HWND hWnd, PMSG pMsg)
{
    return 0L;
}

/** Auto-generated stub definition for function: LPTSTR MApp_ZUI_ACT_GetAudioLanguageDynamicText(HWND) */
EXTERN_C_LINKAGE LPTSTR MApp_ZUI_ACT_GetAudioLanguageDynamicText (HWND hwnd) ;
EXTERN_C_LINKAGE LPTSTR CppTest_Auto_Stub_MApp_ZUI_ACT_GetAudioLanguageDynamicText (HWND hwnd)
{
    return (LPTSTR)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_TerminateAutoTuning(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_TerminateAutoTuning () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_TerminateAutoTuning (void)
{
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACTcoexistWin_Init(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACTcoexistWin_Init () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACTcoexistWin_Init (void)
{
}

/** Auto-generated stub definition for function: U16 MApp_ZUI_ACT_GetChannelListDynamicBitmap(HWND, DRAWSTYLE_TYPE) */
EXTERN_C_LINKAGE U16 MApp_ZUI_ACT_GetChannelListDynamicBitmap (HWND hwnd, DRAWSTYLE_TYPE ds_type) ;
EXTERN_C_LINKAGE U16 CppTest_Auto_Stub_MApp_ZUI_ACT_GetChannelListDynamicBitmap (HWND hwnd, DRAWSTYLE_TYPE ds_type)
{
    return (unsigned short)0;
}

/** Auto-generated stub definition for function: void MApp_UiMenu_ARCDeviceStatusWin_Hide(void) */
EXTERN_C_LINKAGE void MApp_UiMenu_ARCDeviceStatusWin_Hide () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_UiMenu_ARCDeviceStatusWin_Hide (void)
{
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_ExecuteChannelInfoAction(U16) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_ExecuteChannelInfoAction (U16 act) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_ExecuteChannelInfoAction (U16 act)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_TerminateOAD(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_TerminateOAD () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_TerminateOAD (void)
{
}

/** Auto-generated stub definition for function: void MApp_fpGOP_CB(MS_U32, void *) */
EXTERN_C_LINKAGE void MApp_fpGOP_CB (MS_U32 u32EventID, void * reserved0) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_fpGOP_CB (MS_U32 u32EventID, void * reserved0)
{
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_HandleOADKey(VIRTUAL_KEY_CODE) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_HandleOADKey (VIRTUAL_KEY_CODE key) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_HandleOADKey (VIRTUAL_KEY_CODE key)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MApi_PNL_SetLPLLTypeExt(APIPNL_LINK_EXT_TYPE) */
EXTERN_C_LINKAGE void MApi_PNL_SetLPLLTypeExt (APIPNL_LINK_EXT_TYPE eLPLL_TypeExt) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApi_PNL_SetLPLLTypeExt (APIPNL_LINK_EXT_TYPE eLPLL_TypeExt)
{
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_ResetInfoTimer(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_ResetInfoTimer () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_ResetInfoTimer (void)
{
}

/** Auto-generated stub definition for function: void MApp_UiMenu_MuteWin_Show(void) */
EXTERN_C_LINKAGE void MApp_UiMenu_MuteWin_Show () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_UiMenu_MuteWin_Show (void)
{
}

/** Auto-generated stub definition for function: S16 MApp_ZUI_ACT_GetAutoTuningDynamicValue(HWND) */
EXTERN_C_LINKAGE S16 MApp_ZUI_ACT_GetAutoTuningDynamicValue (HWND hwnd) ;
EXTERN_C_LINKAGE S16 CppTest_Auto_Stub_MApp_ZUI_ACT_GetAutoTuningDynamicValue (HWND hwnd)
{
    return (short)0;
}

/** Auto-generated stub definition for function: void MApp_UiMenu_ARCDeviceStatusWin_Show(BOOLEAN) */
EXTERN_C_LINKAGE void MApp_UiMenu_ARCDeviceStatusWin_Show (BOOLEAN IsConnect) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_UiMenu_ARCDeviceStatusWin_Show (BOOLEAN IsConnect)
{
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACTcoexist_Enable(BOOLEAN) */
EXTERN_C_LINKAGE void MApp_ZUI_ACTcoexist_Enable (BOOLEAN bEnable) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACTcoexist_Enable (BOOLEAN bEnable)
{
}

/** Auto-generated stub definition for function: void MApp_UiMenu_CountDownWin_Draw(void) */
EXTERN_C_LINKAGE void MApp_UiMenu_CountDownWin_Draw () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_UiMenu_CountDownWin_Draw (void)
{
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_AppShowAudioLanguage(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_AppShowAudioLanguage () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_AppShowAudioLanguage (void)
{
}

/** Auto-generated stub definition for function: U16 MApp_ZUI_ACT_GetAudioLanguageDynamicBitmap(HWND, DRAWSTYLE_TYPE) */
EXTERN_C_LINKAGE U16 MApp_ZUI_ACT_GetAudioLanguageDynamicBitmap (HWND hwnd, DRAWSTYLE_TYPE ds_type) ;
EXTERN_C_LINKAGE U16 CppTest_Auto_Stub_MApp_ZUI_ACT_GetAudioLanguageDynamicBitmap (HWND hwnd, DRAWSTYLE_TYPE ds_type)
{
    return (unsigned short)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_TerminateChannelList(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_TerminateChannelList () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_TerminateChannelList (void)
{
}

/** Auto-generated stub definition for function: S16 MApp_ZUI_ACT_GetAudioVolumeDynamicValue(HWND) */
EXTERN_C_LINKAGE S16 MApp_ZUI_ACT_GetAudioVolumeDynamicValue (HWND hwnd) ;
EXTERN_C_LINKAGE S16 CppTest_Auto_Stub_MApp_ZUI_ACT_GetAudioVolumeDynamicValue (HWND hwnd)
{
    return (short)0;
}

/** Auto-generated stub definition for function: void MApp_KeyProc_Mute(void) */
EXTERN_C_LINKAGE void MApp_KeyProc_Mute () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_KeyProc_Mute (void)
{
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_AutoTuningSkipATVWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_AutoTuningSkipATVWinProc (HWND hWnd, PMSG pMsg) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_AutoTuningSkipATVWinProc (HWND hWnd, PMSG pMsg)
{
    return 0L;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_AppShowAudioVolume(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_AppShowAudioVolume () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_AppShowAudioVolume (void)
{
}

/** Auto-generated stub definition for function: S16 MApp_ZUI_ACT_GetChannelInfoDynamicValue(HWND) */
EXTERN_C_LINKAGE S16 MApp_ZUI_ACT_GetChannelInfoDynamicValue (HWND hwnd) ;
EXTERN_C_LINKAGE S16 CppTest_Auto_Stub_MApp_ZUI_ACT_GetChannelInfoDynamicValue (HWND hwnd)
{
    return (short)0;
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_ChannelInfoRootWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_ChannelInfoRootWinProc (HWND _MT_var1086, PMSG _MT_var1087) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_ChannelInfoRootWinProc (HWND _MT_var340, PMSG _MT_var341)
{
    return 0L;
}

/** Auto-generated stub definition for function: void MApp_ZUI_OADSwUpdate_ProgressBar(U8) */
EXTERN_C_LINKAGE void MApp_ZUI_OADSwUpdate_ProgressBar (U8 percent) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_OADSwUpdate_ProgressBar (U8 percent)
{
}

/** Auto-generated stub definition for function: void MApp_ARC_KeyProc_Mute(void) */
EXTERN_C_LINKAGE void MApp_ARC_KeyProc_Mute () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ARC_KeyProc_Mute (void)
{
}

/** Auto-generated stub definition for function: MS_BOOL MApi_PNL_TCONMAP_DumpTable(MS_U8 *, MS_U8) */
EXTERN_C_LINKAGE MS_BOOL MApi_PNL_TCONMAP_DumpTable (MS_U8 * pTCONTable, MS_U8 u8Tcontype) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Auto_Stub_MApi_PNL_TCONMAP_DumpTable (MS_U8 * pTCONTable, MS_U8 u8Tcontype)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MApp_UiMenu_MuteWin_Hide(void) */
EXTERN_C_LINKAGE void MApp_UiMenu_MuteWin_Hide () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_UiMenu_MuteWin_Hide (void)
{
}

/** Auto-generated stub definition for function: LPTSTR MApp_ZUI_ACT_GetChannelListDynamicText(HWND) */
EXTERN_C_LINKAGE LPTSTR MApp_ZUI_ACT_GetChannelListDynamicText (HWND hwnd) ;
EXTERN_C_LINKAGE LPTSTR CppTest_Auto_Stub_MApp_ZUI_ACT_GetChannelListDynamicText (HWND hwnd)
{
    return (LPTSTR)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_TerminateAudioVolume(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_TerminateAudioVolume () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_TerminateAudioVolume (void)
{
}

/** Auto-generated stub definition for function: LPTSTR MApp_ZUI_ACT_GetAutoTuningDynamicText(HWND) */
EXTERN_C_LINKAGE LPTSTR MApp_ZUI_ACT_GetAutoTuningDynamicText (HWND hwnd) ;
EXTERN_C_LINKAGE LPTSTR CppTest_Auto_Stub_MApp_ZUI_ACT_GetAutoTuningDynamicText (HWND hwnd)
{
    return (LPTSTR)0;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_HandleChannelInfoKey(VIRTUAL_KEY_CODE) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_HandleChannelInfoKey (VIRTUAL_KEY_CODE key) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_HandleChannelInfoKey (VIRTUAL_KEY_CODE key)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MApi_PNL_TCON_Init(void) */
EXTERN_C_LINKAGE void MApi_PNL_TCON_Init () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApi_PNL_TCON_Init (void)
{
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACTcoexistWin_SwitchGwin(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACTcoexistWin_SwitchGwin () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACTcoexistWin_SwitchGwin (void)
{
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_ExecuteOADAction(U16) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_ExecuteOADAction (U16 act) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_ExecuteOADAction (U16 act)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_ExecuteAutoTuningAction(U16) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_ExecuteAutoTuningAction (U16 act) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_ExecuteAutoTuningAction (U16 act)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_ExecuteAudioLanguageAction(U16) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_ExecuteAudioLanguageAction (U16 act) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_ExecuteAudioLanguageAction (U16 act)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_AppShowChannelInfo(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_AppShowChannelInfo () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_AppShowChannelInfo (void)
{
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_HandleAudioVolumeKey(VIRTUAL_KEY_CODE) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_HandleAudioVolumeKey (VIRTUAL_KEY_CODE key) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_HandleAudioVolumeKey (VIRTUAL_KEY_CODE key)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void _MApp_ZUI_ACT_LoadMonthString(U8, LPTSTR) */
EXTERN_C_LINKAGE void _MApp_ZUI_ACT_LoadMonthString (U8 month, LPTSTR str) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub__MApp_ZUI_ACT_LoadMonthString (U8 month, LPTSTR str)
{
}

/** Auto-generated stub definition for function: U16 MApp_ZUI_ACT_GetDynamicBitmap(HWND, DRAWSTYLE_TYPE) */
EXTERN_C_LINKAGE U16 MApp_ZUI_ACT_GetDynamicBitmap (HWND hwnd, DRAWSTYLE_TYPE type) ;
EXTERN_C_LINKAGE U16 CppTest_Auto_Stub_MApp_ZUI_ACT_GetDynamicBitmap (HWND hwnd, DRAWSTYLE_TYPE type)
{
    return (unsigned short)0;
}

/** Auto-generated stub definition for function: OSD_COLOR MApp_ZUI_ACT_GetDynamicColor(HWND, DRAWSTYLE_TYPE, OSD_COLOR) */
EXTERN_C_LINKAGE OSD_COLOR MApp_ZUI_ACT_GetDynamicColor (HWND hwnd, DRAWSTYLE_TYPE type, OSD_COLOR colorOriginal) ;
EXTERN_C_LINKAGE OSD_COLOR CppTest_Auto_Stub_MApp_ZUI_ACT_GetDynamicColor (HWND hwnd, DRAWSTYLE_TYPE type, OSD_COLOR colorOriginal)
{
    return 0UL;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_StartupOSD(U32) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_StartupOSD (U32 id) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_StartupOSD (U32 id)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_HandleGlobalKey(VIRTUAL_KEY_CODE) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_HandleGlobalKey (VIRTUAL_KEY_CODE key) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_HandleGlobalKey (VIRTUAL_KEY_CODE key)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_ExecuteMenuItemAction(U16) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_ExecuteMenuItemAction (U16 act) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_ExecuteMenuItemAction (U16 act)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: GUI_ENUM_DYNAMIC_LIST_STATE MApp_ZUI_ACT_QueryDynamicListItemStatus(HWND) */
EXTERN_C_LINKAGE GUI_ENUM_DYNAMIC_LIST_STATE MApp_ZUI_ACT_QueryDynamicListItemStatus (HWND hwnd) ;
EXTERN_C_LINKAGE GUI_ENUM_DYNAMIC_LIST_STATE CppTest_Auto_Stub_MApp_ZUI_ACT_QueryDynamicListItemStatus (HWND hwnd)
{
    return EN_DL_STATE_HIDDEN;
}

/** Auto-generated stub definition for function: S16 MApp_ZUI_ACT_GetDynamicValue_2(HWND) */
EXTERN_C_LINKAGE S16 MApp_ZUI_ACT_GetDynamicValue_2 (HWND hwnd) ;
EXTERN_C_LINKAGE S16 CppTest_Auto_Stub_MApp_ZUI_ACT_GetDynamicValue_2 (HWND hwnd)
{
    return (short)0;
}

/** Auto-generated stub definition for function: VIRTUAL_KEY_CODE _MApp_ZUI_ACT_MapToVirtualKeyCode(U8) */
EXTERN_C_LINKAGE VIRTUAL_KEY_CODE _MApp_ZUI_ACT_MapToVirtualKeyCode (U8 IR_key_code) ;
EXTERN_C_LINKAGE VIRTUAL_KEY_CODE CppTest_Auto_Stub__MApp_ZUI_ACT_MapToVirtualKeyCode (U8 IR_key_code)
{
    return VK_NULL;
}

/** Auto-generated stub definition for function: U16 MApp_ZUI_ACT_DecIncValue_Cycle(BOOLEAN, U16, U16, U16, U8) */
EXTERN_C_LINKAGE U16 MApp_ZUI_ACT_DecIncValue_Cycle (BOOLEAN bInc, U16 u16Value, U16 u16MinValue, U16 u16MaxValue, U8 u8Step) ;
EXTERN_C_LINKAGE U16 CppTest_Auto_Stub_MApp_ZUI_ACT_DecIncValue_Cycle (BOOLEAN bInc, U16 u16Value, U16 u16MinValue, U16 u16MaxValue, U8 u8Step)
{
    return (unsigned short)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_ShutdownOSD(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_ShutdownOSD () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_ShutdownOSD (void)
{
}

/** Auto-generated stub definition for function: void MApp_ZUI_SwUpdate_ProgressBar(MS_U8) */
EXTERN_C_LINKAGE void MApp_ZUI_SwUpdate_ProgressBar (MS_U8 percent) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_SwUpdate_ProgressBar (MS_U8 percent)
{
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_OPRefreshQueryUI(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_OPRefreshQueryUI () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_OPRefreshQueryUI (void)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_Exception_MultiTask(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_Exception_MultiTask () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_Exception_MultiTask (void)
{
}

/** Auto-generated stub definition for function: LPTSTR MApp_ZUI_ACT_GetDynamicText(HWND) */
EXTERN_C_LINKAGE LPTSTR MApp_ZUI_ACT_GetDynamicText (HWND hwnd) ;
EXTERN_C_LINKAGE LPTSTR CppTest_Auto_Stub_MApp_ZUI_ACT_GetDynamicText (HWND hwnd)
{
    return (LPTSTR)0;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_PostMessageFilter(U8, MESSAGE_ENUM) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_PostMessageFilter (U8 u8WinProcID, MESSAGE_ENUM msg) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_PostMessageFilter (U8 u8WinProcID, MESSAGE_ENUM msg)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: S16 MApp_ZUI_ACT_GetDynamicValue(HWND) */
EXTERN_C_LINKAGE S16 MApp_ZUI_ACT_GetDynamicValue (HWND hwnd) ;
EXTERN_C_LINKAGE S16 CppTest_Auto_Stub_MApp_ZUI_ACT_GetDynamicValue (HWND hwnd)
{
    return (short)0;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_ExecuteMessageBoxAction(U16) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_ExecuteMessageBoxAction (U16 act) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_ExecuteMessageBoxAction (U16 act)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_ExecuteWndAction(U16) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_ExecuteWndAction (U16 act) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_ExecuteWndAction (U16 act)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_ExecuteWndProc(U8, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_ExecuteWndProc (U8 u8WinProcID, PMSG msg) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_ExecuteWndProc (U8 u8WinProcID, PMSG msg)
{
    return 0L;
}

/** Auto-generated stub definition for function: U32 MApp_ZUI_GetActiveOSD(void) */
EXTERN_C_LINKAGE U32 MApp_ZUI_GetActiveOSD () ;
EXTERN_C_LINKAGE U32 CppTest_Auto_Stub_MApp_ZUI_GetActiveOSD (void)
{
    return 0UL;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ProcessKey(U8) */
EXTERN_C_LINKAGE void MApp_ZUI_ProcessKey (U8 u8IRKey) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ProcessKey (U8 u8IRKey)
{
}

/** Auto-generated stub definition for function: ZUI_RET MApp_ZUI_MainTask(void) */
EXTERN_C_LINKAGE ZUI_RET MApp_ZUI_MainTask () ;
EXTERN_C_LINKAGE ZUI_RET CppTest_Auto_Stub_MApp_ZUI_MainTask (void)
{
    return RET_ZUI_RUNNING;
}

/** Auto-generated stub definition for function: EN_OSD_COUNTRY_SETTING MApp_ZUI_ACT_GetTuningCountry(void) */
EXTERN_C_LINKAGE EN_OSD_COUNTRY_SETTING MApp_ZUI_ACT_GetTuningCountry () ;
EXTERN_C_LINKAGE EN_OSD_COUNTRY_SETTING CppTest_Auto_Stub_MApp_ZUI_ACT_GetTuningCountry (void)
{
    return OSD_COUNTRY_AUSTRALIA;
}

/** Auto-generated stub definition for function: void OSDcp_readbin_string_ptr(U8, U16, U16 *) */
EXTERN_C_LINKAGE void OSDcp_readbin_string_ptr (U8 language, U16 id, U16 * pu16stringbuffer) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_OSDcp_readbin_string_ptr (U8 language, U16 id, U16 * pu16stringbuffer)
{
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_Init(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_Init () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_Init (void)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_SetTuningCountry(EN_OSD_COUNTRY_SETTING) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_SetTuningCountry (EN_OSD_COUNTRY_SETTING TuningCountry) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_SetTuningCountry (EN_OSD_COUNTRY_SETTING TuningCountry)
{
}

/** Auto-generated stub definition for function: ZUI_STATE MApp_ZUI_GetState(void) */
EXTERN_C_LINKAGE ZUI_STATE MApp_ZUI_GetState () ;
EXTERN_C_LINKAGE ZUI_STATE CppTest_Auto_Stub_MApp_ZUI_GetState (void)
{
    return E_ZUI_STATE_UNKNOW;
}

