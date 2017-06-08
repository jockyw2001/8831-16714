////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2006-2009 MStar Semiconductor, Inc.
// All rights reserved.
//
// Unless otherwise stipulated in writing, any and all information contained
// herein regardless in any format shall remain the sole proprietary of
// MStar Semiconductor Inc. and be kept in strict confidence
// (¡§MStar Confidential Information¡¨) by the recipient.
// Any unauthorized act including without limitation unauthorized disclosure,
// copying, use, reproduction, sale, distribution, modification, disassembling,
// reverse engineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
////////////////////////////////////////////////////////////////////////////////

#define MAPP_TV_C

/******************************************************************************/
/*                            Header Files                                    */
/******************************************************************************/
#include <string.h>
#include <stdio.h>

#include "Board.h"

#include "datatype.h"

#include "debug.h"

// Common Definition
#include "msAPI_audio.h"
#include "msAPI_Timer.h"
#include "msAPI_OSD.h"
#include "msAPI_VD.h"
#include "apiGOP.h"
#include "apiXC.h"
#include "apiXC_Adc.h"
#include "apiXC_Ace.h"
#include "apiXC_PCMonitor.h"
#include "apiXC_Sys.h"
#include "MApp_GlobalSettingSt.h"
#if (ENABLE_PVR)
#include "MApp_TimeShift.h"
#endif
#if (ENABLE_SUBTITLE)
#include "MApp_Subtitle.h"
#endif

#if ENABLE_TTX
#include "msAPI_TTX.h"
#include "mapp_ttx.h"
#endif
#include "msAPI_ATVSystem.h"
#include "msAPI_DTVSystem.h"
#include "msAPI_ChProc.h"
#include "msAPI_Bootloader.h"

#if MHEG5_ENABLE
#include "msAPI_MHEG5.h"
#include "msAPI_IR.h"
#endif

#include "msIR.h"

#include "msAPI_Video.h"

#if(ENABLE_TEST_PATTERN)
#include "msAPI_TestPattern.h"
#endif


#include "MApp_Exit.h"
#include "MApp_GlobalVar.h"
#include "MApp_GlobalFunction.h"
#include "MApp_Key.h"
#include "MApp_IR.h"
#include "MApp_Audio.h"
#include "MApp_MultiTasks.h"


#include "MApp_DataBase.h"
#include "MApp_Scan.h"
#include "MApp_ChannelList.h"
#include "MApp_Bitmap.h"
#include "MApp_Font.h"
#include "MApp_TV.h"
#include "MApp_InputSource.h"
#include "MApp_SignalMonitor.h"
#include "MApp_ChannelChange.h"
#include "MApp_Logo.h"
#include "MApp_MVDMode.h"
#include "MApp_Sleep.h"
#include "MApp_Scaler.h"
#include "MApp_VDMode.h"
#include "MApp_BlockSys.h"
#include "MApp_PCMode.h"
#include "MApp_UiMenuDef.h"
#include "MApp_ZUI_Main.h"
#include "ZUI_tables_h.inl"
#include "ZUI_exefunc.h"
#include "MApp_ChList_Main.h"
#include "MApp_OSDPage_Main.h"
#include "MApp_SaveData.h"
#include "MApp_AnalogInputs.h"
#include "MApp_USBDownload.h"
#include "MApp_ATVProc.h"
#include "MApp_Main.h"
#include "MApp_TopStateMachine.h"
#include "msAPI_DrvInit.h"
#include "MApp_ZUI_ACTchannelinfo.h"

#if ENABLE_ATSC
#include "MApp_GlobalVar_ATSC.h"
#include "MApp_Psip.h"
#include "MApp_VChip.h"
#include "MApp_ChannelProc_ATSC.h"
#include "MApp_ZUI_ACTmainpage.h"
//#include "MApp_Exit.h"
#endif

#if ENABLE_ATSC_TTS
#include "MApp_TTSControlHandler.h"
#include "ZUI_tables_h.inl"
#include "ZUI_strings_enum.h"
#include "OSDcp_String_EnumIndex.h"
#include "MApp_GlobalFunction.h"
#include "MApp_ZUI_APIstrings.h"
#endif

#if MHEG5_ENABLE
#include "MApp_MHEG5_Main.h"
#include "mapp_mheg5.h"
#endif

#include "GPIO.h"
#include "drvpower_if.h"

#if ENABLE_CI
#include "msAPI_CI.h"
#include "MApp_CIMMI.h"
#endif

#if ENABLE_OAD
#include "MApp_OAD.h"
#endif

#if (ENABLE_PVR)
#include "MApp_UiPvr.h"
#endif

#if(CHAKRA3_AUTO_TEST)
#include "MApp_AutoTest.h"
#endif

#if (ENABLE_PIP)
#include "MApp_PIP.h"
#endif


#if ((BRAZIL_CC )|| (ATSC_CC == ATV_CC))
#include "mapp_closedcaption.h"
#endif

#include "MApp_EpgTimer.h"
#if (ENABLE_EPG_MUX)
#include "msAPI_FreqTableDTV.h"
#endif
#if(ENABLE_OSD_SUBTITLE_EXCLUSIVE == ENABLE || ENABLE_EASMONITOR == ENABLE)
#include "MApp_ZUI_ACTcoexistWin.h"
#endif

#include "MApp_ParentalRating.h"

#if (NO_SIGNAL_AUTO_SHUTDOWN )
#include "MApp_NoSignal_AutoSleep.h"
#endif

#include "MApp_ZUI_ACTchannelinfo_ATSC.h"

#include "MApp_ZUI_Main.h"


extern BOOLEAN MApp_UiMenuFunc_SelectSubtileLang(void);
extern BOOLEAN g_bQuietlyTune;

extern U8   u8InfoScrollLineCount;
extern U8   u8InfoScrollLineCount_Pre;
extern U8   u8IsBriefChInfo;

#if (ENABLE_PVR)
extern BOOLEAN MApp_ZUI_ACT_PVR_Check_Switch_Channel(MEMBER_SERVICETYPE NewCMType, U16 u16NewPos);
#endif
#if ENABLE_DTV_EPG //ENABLE_DTV
extern void MApp_ZUI_EpgTimerCountDown(void);
extern BOOLEAN MApp_TV_ProcessEpgCountDownKey(U8 key);
#endif
extern void MApp_AnalogInputs_ProcessUserInput(void);
extern void MApp_AnalogInputs_MonitorWindows(SCALER_WIN eWindow);
//#if (ENABLE_PIP)
extern BOOLEAN MApp_ZUI_ACT_ExecuteMenuItemAction(U16 act);
//#endif
#if ENABLE_E_POP
extern void MApp_ZUi_ACT_EpopHander(void);
#endif
#if ENABLE_AUTOTEST
extern BOOLEAN g_bAutobuildDebug;
#endif
#if ENABLE_EPGTIMER_RECORDER_TURNOFFPANEL
extern BOOLEAN     g_bTimerTypeRecord;
extern BOOLEAN     g_bTimerActiveStandbyMode;
#endif
#if ENABLE_CI_PLUS
extern BOOLEAN        g_bTimeTypeOpRefresh;
#endif

#if ENABLE_S2//ENABLE_QSORT_SERVICE
extern U8 g_u8ShowChannelList;
#endif

#if (BRAZIL_CC == 1)
#include "mapi_cc_brazil_decode.h"
#endif
extern void _SubmitPalette(void);
/******************************************************************************/
/*                              Macro                                         */
/******************************************************************************/
#define TV_DBINFO(y)                //y
#if (ENABLE_ATSC)
#define SAVR_DBG(y)                 //y
#endif

#if (ENABLE_EXTERN_DTV_MAX_MINOR_NO)
#define MAX_DIGITKEY_NUM         5
#else
#define MAX_DIGITKEY_NUM         4
#endif

#define TV_MODE_WINDOW_MONITOR_PERIOD        2000 //ms
#define TV_MODE_WINDOW_MONITOR_PERIOD_NOSINGAL    50//ms
#define DEBUG_OBAMA_TV 0
/******************************************************************************/
/*                               Local                                        */
/******************************************************************************/

EN_RET enTVRetVal;
EN_TV_STATE enTVState = STATE_TV_INIT;
static U32 u32TVModeWinTimer;

#if ENABLE_DTV
static U8 u8TVNoSignalCount=0;
static U8 u8DTVNoSignalCount=0;
static U8 u8InvalidServiceCount=0;
#endif

BOOLEAN bCheckBlockPW = FALSE;
BOOLEAN bCheckParentalPW = FALSE;
BOOLEAN bStopMonitorBlock=FALSE;
#if (ENABLE_UPDATE_MULTIPLEX_VIA_NIT)
BOOLEAN _bCheckAlternative = FALSE;
#endif

#if ENABLE_SBTVD_BRAZIL_APP
#if (BRAZIL_CC)
typedef struct
{
    S32 s32X_offset;
    S32 s32Y_offset;
}stCaptionWindowSetting;
static stCaptionWindowSetting stCCWinSet;
#endif
#endif

#if (ENABLE_EASMONITOR)
static BOOLEAN bIsChangeCH = FALSE;
static MS_EAS_INFO stEAS_info;
static MS_VIRTUAL_CHANNEL_NUM stOriginalChNum;
static BOOLEAN bShowEASUIFlag = FALSE;
static BOOLEAN bIsEASExitUI= FALSE;
#endif

/*******************************************************************************/
/*                               Functions                                     */
/*******************************************************************************/
#if (ENABLE_UPDATE_MULTIPLEX_VIA_NIT)
static void _MApp_TV_CheckNetworkChange(void);
static void _MApp_TV_LossSignal_CheckOriginalRF(void);
#endif
#if (DTG_FREEVIEW_STANDBY)
static BOOLEAN FreeView_Standby = FALSE;
//for DTG v1.6 test case #2.7
//only turn off LCD
#ifdef PVR_8051
#define MApi_PNL_En(x)
//#else
//    extern void mvideo_sc_setpanel_onoff(BOOLEAN bPanelOn);
#endif
BOOLEAN MApp_FreeView_Standby(void)
{
    //printf("MApp_FreeView_Standby\n");
    if (MApp_EpgUI_GetNumOfTimers() >0)
    {
				#ifdef sNewAudioMuteStyle
				msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, 0, 0);
				#else    	
        MUTE_On();
        #endif
        MApi_PNL_SetBackLight(DISABLE);
        /*
                #if (INPUT_HDMI_VIDEO_COUNT > 0)
                    msAPI_Scaler_HDMI_PowerOff( );
                #endif
        */
        //      MApp_ZUI_ACT_ShutdownOSD();//ZUI: MApp_UiMenu2_DeleteALLOSDWindow();


        MApi_PNL_En(FALSE);
        /*
        #if ENABLE_PVR
        if((MApp_MassStorage_DeviceConnectionDetect() & MS_USB_CONNECTED) ||
          (MApp_MassStorage_DeviceConnectionDetect() & MS_USB2_CONNECTED))
            {
                msAPI_BKFS_FlashCopy(BKF_FLASHCOPY_DRAM2FLASH, EVENTDB_SDRAM_ADR, EVENTDB_SDRAM_LEN+EPGEXTDB_SDRAM_LEN, (U16*)msAPI_BKFS_GetEPGFileName(), msAPI_BKFS_GetEPGFileLength());
            }
        #endif

        */
        FreeView_Standby = TRUE;
        return TRUE;
    }
    else
        return FALSE;
}

void MApp_FreeView_PowerOn(void)
{
    //printf("MApp_FreeView_PowerOn\n");

    printf("%s, %d\n", __FUNCTION__, __LINE__);
    MApi_PNL_En(TRUE);
    MApi_PNL_SetBackLight(ENABLE);
    /*
            #if (INPUT_HDMI_VIDEO_COUNT > 0)
                msAPI_Scaler_InitHDMi( );
            #endif
    */

		#ifdef sNewAudioMuteStyle
		msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, stGenSetting.g_SoundSetting.Volume, 0);
		#else
		MUTE_Off();
		#endif

    FreeView_Standby = FALSE;
}

BOOLEAN MApp_FreeView_Standby_Switch(void)
{
    if (FreeView_Standby)
    {
        MApp_FreeView_PowerOn();
        return TRUE;
    }
    else
    {
        return MApp_FreeView_Standby();
    }
}

BOOLEAN MApp_FreeView_Is_Standby(void)
{
    return FreeView_Standby;
}
#endif //#if (DTG_FREEVIEW_STANDBY)

#if ENABLE_OAD
void MApp_OAD_PanelPowerOn(void)
{
    if(MApp_OAD_IsUserSelectOn())
    {
        MApi_PNL_En(TRUE);
        MApi_PNL_SetBackLight(ENABLE);
				#ifdef sNewAudioMuteStyle
				msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, stGenSetting.g_SoundSetting.Volume, 0);
				#else
				MUTE_Off();
				#endif
    }

}
void MApp_OAD_PanelPowerOff(void)
{
    if(MApp_OAD_IsUserSelectOn())
    {
				#ifdef sNewAudioMuteStyle
				msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, 0, 0);
				#else    	
        MUTE_On();
        #endif
        MApi_PNL_SetBackLight(DISABLE);
        msAPI_Timer_Delayms(20);
        MApi_PNL_En(FALSE);
    }
}
#endif

#if 0 //ZUI: unused ENABLE_OAD
static void MApp_TV_Monitor_UpdateOAD(void)
{
    if ( u8fEnableOAD )
    {
        u8fEnableOAD = 0;

        //ZUI_TODO: MApp_UiMenu_ExecuteKeyEvent(MIA_OAD_MENU);
    }
}
#endif //ENABLE_OAD



/*****************************************************************************/
void MApp_TV_SaveSelectSubtileLang(void)
{
    /*
        U8  i;
        for ( i = 0; i < SUBTITLE_DEFAULT_LANGUAGE_NUM; i++ )
        {
            if ( memcmp( SubtitleServices[u8SubtitleItemSelIdx - 1].StringCodes, subtile_LanguageCode[i].subtitleStringCode, 3 ) == 0 )
            {
                stGenSetting.g_SysSetting.Last_Select_HotKey_SubtitleLanguage = i;
            }
        }
        switch(stGenSetting.g_SysSetting.Last_Select_HotKey_SubtitleLanguage)
        {
            case SUBTITLE_DEFAULT_LANGUAGE_CZECH_2:
                stGenSetting.g_SysSetting.Last_Select_HotKey_SubtitleLanguage=SUBTITLE_DEFAULT_LANGUAGE_CZECH;
            break;
            case SUBTITLE_DEFAULT_LANGUAGE_GERMAN_2:
                stGenSetting.g_SysSetting.Last_Select_HotKey_SubtitleLanguage=SUBTITLE_DEFAULT_LANGUAGE_GERMAN;
            break;
            case SUBTITLE_DEFAULT_LANGUAGE_GREEK_2:
                stGenSetting.g_SysSetting.Last_Select_HotKey_SubtitleLanguage=SUBTITLE_DEFAULT_LANGUAGE_GREEK;
            break;
            case SUBTITLE_DEFAULT_LANGUAGE_FRENCH_2:
                stGenSetting.g_SysSetting.Last_Select_HotKey_SubtitleLanguage=SUBTITLE_DEFAULT_LANGUAGE_FRENCH;
            break;
            case SUBTITLE_DEFAULT_LANGUAGE_CROATIAN_2:
                stGenSetting.g_SysSetting.Last_Select_HotKey_SubtitleLanguage=SUBTITLE_DEFAULT_LANGUAGE_CROATIAN;
            break;
            case SUBTITLE_DEFAULT_LANGUAGE_DUTCH_2:
                stGenSetting.g_SysSetting.Last_Select_HotKey_SubtitleLanguage=SUBTITLE_DEFAULT_LANGUAGE_DUTCH;
            break;
            case SUBTITLE_DEFAULT_LANGUAGE_ROMANIAN_2:
                stGenSetting.g_SysSetting.Last_Select_HotKey_SubtitleLanguage=SUBTITLE_DEFAULT_LANGUAGE_ROMANIAN;
            break;
            case SUBTITLE_DEFAULT_LANGUAGE_GAEILC_2:
                stGenSetting.g_SysSetting.Last_Select_HotKey_SubtitleLanguage=SUBTITLE_DEFAULT_LANGUAGE_GAEILC;
            break;
            case SUBTITLE_DEFAULT_LANGUAGE_WELSH_2:
                stGenSetting.g_SysSetting.Last_Select_HotKey_SubtitleLanguage=SUBTITLE_DEFAULT_LANGUAGE_WELSH;
            break;
            case SUBTITLE_DEFAULT_LANGUAGE_GAEILC_3:
                stGenSetting.g_SysSetting.Last_Select_HotKey_SubtitleLanguage=SUBTITLE_DEFAULT_LANGUAGE_GAEILC;
            break;
            default:
                break;

        }
    */
}

#if (ENABLE_SUBTITLE)
//------------------
BOOLEAN MApp_TV_SelectSubtileLang(void)
{
    AUD_INFO aAudioStreamInfo;
    U8 u8SubtitleMenuIdx;
    VDEC_DispInfo _stVidInfo;
    BOOLEAN bIsHDType = FALSE;

    EN_LANGUAGE enPreferLangIdxArray[] = {
        SUBTITLE_DEFAULT_LANGUAGE_1,
        SUBTITLE_DEFAULT_LANGUAGE_2,
        LAST_SECLECT_AUDIO_LANGUAGE,
        LANGUAGE_ENGLISH,
        LANGUAGE_UND,
        LANGUAGE_QAA};

    EN_LANGUAGE enNZPreferLangIdxArray[] = {
        SUBTITLE_DEFAULT_LANGUAGE_1,
        SUBTITLE_DEFAULT_LANGUAGE_2,
        LAST_SECLECT_AUDIO_LANGUAGE,
        LANGUAGE_ENGLISH,
        LANGUAGE_UND,
        LANGUAGE_QAA};

    if(OSD_COUNTRY_SETTING == OSD_COUNTRY_NEWZEALAND)
    {
        msAPI_CM_GetAudioStreamInfo(msAPI_CM_GetCurrentServiceType(), msAPI_CM_GetCurrentPosition(msAPI_CM_GetCurrentServiceType()), &aAudioStreamInfo, g_u8AudLangSelected);
        if(LAST_SECLECT_AUDIO_LANGUAGE != MApp_GetLanguageBySILanguage((EN_SI_LANGUAGE)aAudioStreamInfo.aISOLangInfo[0].bISOLangIndex))
        {
            if(OSD_COUNTRY_SETTING == OSD_COUNTRY_NEWZEALAND)
            {
                enNZPreferLangIdxArray[2] = MApp_GetLanguageBySILanguage((EN_SI_LANGUAGE)aAudioStreamInfo.aISOLangInfo[0].bISOLangIndex);
            }
            else
            {
                enPreferLangIdxArray[2] = MApp_GetLanguageBySILanguage((EN_SI_LANGUAGE)aAudioStreamInfo.aISOLangInfo[0].bISOLangIndex);
            }
        }
    }

    // Check video is SD or HD
    if(msAPI_VID_GetVidInfo(&_stVidInfo))
    {
        if(_stVidInfo.u16HorSize > 720 || _stVidInfo.u16VerSize > 576)
        {
            bIsHDType = TRUE;
        }
    }
#if (ENABLE_CI_PLUS)
    if(TRUE == MApp_CI_IsOpMode())
    {
        U8 au8IsoLang[3];
        EN_LANGUAGE eLangcode = LANGUAGE_UND;
        if(TRUE == MApp_CI_GetOpIso639LangCodeByCicamId(MApp_CI_GetCurrentOpCicamId(), au8IsoLang))
        {
            eLangcode = MApp_GetLanguageBySILanguage(msAPI_SI_GetLanguageByISO639LangCode(au8IsoLang));
        }
        if(eLangcode == SUBTITLE_DEFAULT_LANGUAGE_1)
        {
            enPreferLangIdxArray[1] = LANGUAGE_UND;
            enPreferLangIdxArray[2] = LANGUAGE_QAA;
            enPreferLangIdxArray[3] = SUBTITLE_DEFAULT_LANGUAGE_2;
            enPreferLangIdxArray[4] = LANGUAGE_ENGLISH;
        }
        else
        {
            enPreferLangIdxArray[2] = LANGUAGE_UND;
            enPreferLangIdxArray[3] = LANGUAGE_QAA;
            enPreferLangIdxArray[4] = LANGUAGE_ENGLISH;
        }
    }
#endif
    if(OSD_COUNTRY_SETTING == OSD_COUNTRY_NEWZEALAND)
    {
        if(FALSE == MApp_Subtitle_SearchSubtitleLangPriority(enNZPreferLangIdxArray, (sizeof(enNZPreferLangIdxArray)/sizeof(EN_LANGUAGE)), stGenSetting.g_SysSetting.fHardOfHearing, bIsHDType,&u8SubtitleMenuIdx))
        {
            return FALSE;
        }
    }
    else
    {
        if(FALSE == MApp_Subtitle_SearchSubtitleLangPriority(enPreferLangIdxArray, (sizeof(enPreferLangIdxArray)/sizeof(EN_LANGUAGE)), stGenSetting.g_SysSetting.fHardOfHearing, bIsHDType,&u8SubtitleMenuIdx))
        {
            return FALSE;
        }
    }
#if ((CHIP_FAMILY_MILAN == CHIP_FAMILY_TYPE)||\
    (CHIP_FAMILY_MULAN == CHIP_FAMILY_TYPE))
    u8preSubtitleMenuIdx = u8SubtitleItemSelIdx - 1;
#endif
    u8SubtitleItemSelIdx = u8SubtitleMenuIdx+1;

    LAST_SECLECT_LANGUAGE = MApp_GetLanguageBySILanguage(msAPI_SI_GetLanguageByISO639LangCode( (U8 *)SubtitleMenu[u8SubtitleMenuIdx].StringCodes) );

    //printf("u8SubtitleMenuIdx=%d\n", u8SubtitleMenuIdx);
    //printf("LAST_SECLECT_LANGUAGE = %d\n", LAST_SECLECT_LANGUAGE);

    if ( MApp_Subtitle_Select_Language(u8SubtitleMenuIdx) == TRUE)
    {
        return TRUE;
    }
    else
    {
        if (MApp_Subtitle_IsTTXSubtitle(u8SubtitleMenuIdx) &&
            stGenSetting.g_SysSetting.fEnableSubTitle)
        {
            if(stGenSetting.g_SysSetting.fEnableTTXSubTitle == FALSE)
                    stGenSetting.g_SysSetting.fEnableTTXSubTitle = TRUE;
        }
        else if(stGenSetting.g_SysSetting.fEnableTTXSubTitle)
                stGenSetting.g_SysSetting.fEnableTTXSubTitle = FALSE;

        return FALSE;
    }
}



BOOLEAN MApp_TV_SearchLastSubtileLang(void)
{

    if (stGenSetting.g_SysSetting.fEnableSubTitle == FALSE)
    {
        u8SubtitleItemSelIdx = 0;
        return TRUE;
    }
    //printf("\nLAST_SECLECT_LANGUAGE=%bu\n",LAST_SECLECT_LANGUAGE);
    if (UI_Hotkey_Subtitle == FALSE && stGenSetting.g_SysSetting.fEnableTTXSubTitle == FALSE)
    {
        MApp_TV_SelectSubtileLang();   //ZUI: MApp_UiMenuFunc_SaveSelectSubtileLang();
    }

    return TRUE;

}
#else
#define MApp_TV_SelectSubtileLang()
#define MApp_TV_SearchLastSubtileLang()
#endif

/*****************************************************************************/
U16 MApp_TV_NumWinVerifyInputValue(U16 u16Value)
{
    U16 u16Ordinal;
#if ENABLE_DVB
    U16 u16Start, u16DtvCount, u16RadioCount;
#endif
#if NORDIG_FUNC //for Nordig Spec v2.0
    U16 u16DataCount;
    U16 u16OrdinalDtv,u16OrdinalRadio,u16OrdinalData;
#endif
    MEMBER_SERVICETYPE eServiceType;

#if ENABLE_DVB
#if ENABLE_SBTVD_BRAZIL_CM_APP
    if (u16Value > 0x100)
#else
#if(ENABLE_PIP)
    if (IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW))
        ||(IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW))&& (MApp_Get_PIPMode() != EN_PIP_MODE_OFF)))
#else
    if (IsDTVInUse())
#endif
#endif
    {
        if (msAPI_CM_GetCurrentServiceType()== E_SERVICETYPE_DTV)
        {
            eServiceType = E_SERVICETYPE_DTV;
        }
#if NORDIG_FUNC //for Nordig Spec v2.0
        else if (msAPI_CM_GetCurrentServiceType()== E_SERVICETYPE_DATA)
        {
            eServiceType = E_SERVICETYPE_DATA;
        }
#endif
        else  //E_SERVICETYPE_Radio
        {
            eServiceType = E_SERVICETYPE_RADIO;
        }
    }
    else
#endif
    {
        eServiceType = E_SERVICETYPE_ATV;
    }

    u16Ordinal = msAPI_CHPROC_CM_GetMatchedOrdinals(eServiceType, u16Value);

#if ENABLE_DVB
#if ENABLE_SBTVD_BRAZIL_CM_APP
    if (u16Value > 0x100)
#else
  #if(ENABLE_PIP)
    if (IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW))
        ||(IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW))&& (MApp_Get_PIPMode() != EN_PIP_MODE_OFF)))
  #else
    if (IsDTVInUse())
  #endif
#endif
    {
        u16DtvCount = msAPI_CHPROC_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO);
        u16RadioCount = msAPI_CHPROC_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO);

#if NORDIG_FUNC //for Nordig Spec v2.0
        u16DataCount = msAPI_CHPROC_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO);
#endif
        if (u16Ordinal != INVALID_ORDINAL)
        {
            if (eServiceType == E_SERVICETYPE_DTV)
                u16Start=0;
#if NORDIG_FUNC //for Nordig Spec v2.0
            else if (eServiceType == E_SERVICETYPE_RADIO)
                u16Start = u16DtvCount;
            else
                u16Start = u16DtvCount + u16RadioCount;
#else
            else
                u16Start=u16DtvCount;
#endif
            if (msAPI_CM_GetProgramAttribute(eServiceType,u16Ordinal-u16Start,E_ATTRIBUTE_IS_VISIBLE) == FALSE && msAPI_CM_GetProgramAttribute(eServiceType,u16Ordinal-u16Start,E_ATTRIBUTE_IS_NUMERIC_SELECTION) == FALSE)
                u16Ordinal=INVALID_ORDINAL;
        }
        if (u16Ordinal == INVALID_ORDINAL)
        {
            if (eServiceType == E_SERVICETYPE_DTV)
            {
#if NORDIG_FUNC //for Nordig Spec v2.0
                u16OrdinalRadio = INVALID_ORDINAL;
                u16OrdinalData    = INVALID_ORDINAL;
                if (u16RadioCount>0)
                {
                    eServiceType = E_SERVICETYPE_RADIO;
                    u16Start=u16DtvCount;
                    u16OrdinalRadio = msAPI_CHPROC_CM_GetMatchedOrdinals(eServiceType, u16Value);
                }
                if(u16DataCount > 0)
                {
                    eServiceType = E_SERVICETYPE_DATA;
                    u16Start=u16DtvCount+u16RadioCount;
                    u16OrdinalData = msAPI_CHPROC_CM_GetMatchedOrdinals(eServiceType, u16Value);
                }

                if(u16OrdinalRadio!=INVALID_ORDINAL)
                {
                    eServiceType = E_SERVICETYPE_RADIO;
                    u16Ordinal = u16OrdinalRadio;
                    u16Start=u16DtvCount;
                    if (msAPI_CM_GetProgramAttribute(eServiceType,u16Ordinal-u16Start,E_ATTRIBUTE_IS_VISIBLE) == FALSE && msAPI_CM_GetProgramAttribute(eServiceType,u16Ordinal-u16Start,E_ATTRIBUTE_IS_NUMERIC_SELECTION) == FALSE)
                        u16Ordinal=INVALID_ORDINAL;
                }
                else if(u16OrdinalData!=INVALID_ORDINAL)
                {
                    eServiceType = E_SERVICETYPE_DATA;
                    u16Ordinal = u16OrdinalData;
                    u16Start=u16DtvCount+u16RadioCount;
                    if (msAPI_CM_GetProgramAttribute(eServiceType,u16Ordinal-u16Start,E_ATTRIBUTE_IS_VISIBLE) == FALSE && msAPI_CM_GetProgramAttribute(eServiceType,u16Ordinal-u16Start,E_ATTRIBUTE_IS_NUMERIC_SELECTION) == FALSE)
                        u16Ordinal=INVALID_ORDINAL;
                }
                else
                {
                    eServiceType = E_SERVICETYPE_DTV;
                    u16Start=0;
                }
#else
                if(u16RadioCount>0)
                {
                    eServiceType = E_SERVICETYPE_RADIO;
                    u16Start=u16DtvCount;
                }
                else
                {
                    eServiceType = E_SERVICETYPE_DTV;
                    u16Start=0;
                }
#endif
            }
#if NORDIG_FUNC //for Nordig Spec v2.0
            else if (eServiceType == E_SERVICETYPE_DATA)
            {
                u16OrdinalDtv= INVALID_ORDINAL;
                u16OrdinalRadio    = INVALID_ORDINAL;
                if (u16DtvCount>0)
                {
                    eServiceType = E_SERVICETYPE_DTV;
                    u16Start=0;
                    u16OrdinalDtv = msAPI_CHPROC_CM_GetMatchedOrdinals(eServiceType, u16Value);
                }
                if(u16RadioCount > 0)
                {
                    eServiceType = E_SERVICETYPE_RADIO;
                    u16Start=u16DtvCount;
                    u16OrdinalRadio = msAPI_CHPROC_CM_GetMatchedOrdinals(eServiceType, u16Value);
                }

                if(u16OrdinalDtv!=INVALID_ORDINAL)
                {
                    eServiceType = E_SERVICETYPE_DTV;
                    u16Ordinal = u16OrdinalDtv;
                    u16Start=0;
                    if (msAPI_CM_GetProgramAttribute(eServiceType,u16Ordinal-u16Start,E_ATTRIBUTE_IS_VISIBLE) == FALSE && msAPI_CM_GetProgramAttribute(eServiceType,u16Ordinal-u16Start,E_ATTRIBUTE_IS_NUMERIC_SELECTION) == FALSE)
                        u16Ordinal=INVALID_ORDINAL;
                }
                else if(u16OrdinalRadio!=INVALID_ORDINAL)
                {
                    eServiceType = E_SERVICETYPE_RADIO;
                    u16Ordinal = u16OrdinalRadio;
                    u16Start=u16DtvCount;
                    if (msAPI_CM_GetProgramAttribute(eServiceType,u16Ordinal-u16Start,E_ATTRIBUTE_IS_VISIBLE) == FALSE && msAPI_CM_GetProgramAttribute(eServiceType,u16Ordinal-u16Start,E_ATTRIBUTE_IS_NUMERIC_SELECTION) == FALSE)
                        u16Ordinal=INVALID_ORDINAL;
                }
                else
                {
                    eServiceType = E_SERVICETYPE_DATA;
                    u16Start=u16DtvCount+u16RadioCount;
                }
            }
#endif
            else
            {
#if NORDIG_FUNC //for Nordig Spec v2.0
                u16OrdinalData = INVALID_ORDINAL;
                u16OrdinalDtv    = INVALID_ORDINAL;
                if (u16DataCount>0)
                {
                    eServiceType = E_SERVICETYPE_DATA;
                    u16Start=u16DtvCount+u16RadioCount;
                    u16OrdinalData = msAPI_CHPROC_CM_GetMatchedOrdinals(eServiceType, u16Value);
                }
                if(u16DtvCount > 0)
                {
                    eServiceType = E_SERVICETYPE_DTV;
                    u16Start=0;
                    u16OrdinalDtv = msAPI_CHPROC_CM_GetMatchedOrdinals(eServiceType, u16Value);
                }

                if(u16OrdinalData!=INVALID_ORDINAL)
                {
                    eServiceType = E_SERVICETYPE_DATA;
                    u16Start=u16DtvCount+u16RadioCount;
                    u16Ordinal = u16OrdinalData;
                    if (msAPI_CM_GetProgramAttribute(eServiceType,u16Ordinal-u16Start,E_ATTRIBUTE_IS_VISIBLE) == FALSE && msAPI_CM_GetProgramAttribute(eServiceType,u16Ordinal-u16Start,E_ATTRIBUTE_IS_NUMERIC_SELECTION) == FALSE)
                        u16Ordinal=INVALID_ORDINAL;
                }
                else if(u16OrdinalDtv!=INVALID_ORDINAL)
                {
                    eServiceType = E_SERVICETYPE_DTV;
                    u16Start=0;
                    u16Ordinal = u16OrdinalDtv;
                    if (msAPI_CM_GetProgramAttribute(eServiceType,u16Ordinal-u16Start,E_ATTRIBUTE_IS_VISIBLE) == FALSE && msAPI_CM_GetProgramAttribute(eServiceType,u16Ordinal-u16Start,E_ATTRIBUTE_IS_NUMERIC_SELECTION) == FALSE)
                        u16Ordinal=INVALID_ORDINAL;
                }
                else
                {
                    eServiceType = E_SERVICETYPE_RADIO;
                    u16Start=u16DtvCount;
                }
#else
                if(u16DtvCount>0)
                {
                eServiceType = E_SERVICETYPE_DTV;
                u16Start=0;
                }
                else
                {
                    eServiceType = E_SERVICETYPE_RADIO;
                    u16Start=u16DtvCount;
                }
#endif
            }
#if NORDIG_FUNC //for Nordig Spec v2.0
#else
            u16Ordinal = msAPI_CHPROC_CM_GetMatchedOrdinals(eServiceType, u16Value);
            if (u16Ordinal != INVALID_ORDINAL)
            {
                if (msAPI_CM_GetProgramAttribute(eServiceType,u16Ordinal-u16Start,E_ATTRIBUTE_IS_VISIBLE) == FALSE && msAPI_CM_GetProgramAttribute(eServiceType,u16Ordinal-u16Start,E_ATTRIBUTE_IS_NUMERIC_SELECTION) == FALSE)
                    u16Ordinal=INVALID_ORDINAL;
            }
#endif
        }

    }
#endif

    return u16Ordinal;
}
/*****************************************************************************/
#if ENABLE_SBTVD_BRAZIL_APP
U16 MApp_TV_SBTVD_DigitKeyVerifyInputValue(U8 u8MajorValue, U8 u8MinorValue)
{
    U16 u16Ordinal;
    LOGICAL_CHANNEL_NUMBER LCN;
#if ENABLE_SBTVD_BRAZIL_CM_APP
    U16 u16MatchOridinal = 0;
    MEMBER_SERVICETYPE bNextServiceType;
#endif

    MEMBER_SERVICETYPE bServiceType = msAPI_CM_GetCurrentServiceType();
    LCN.stLCN.bPhysicalChannel = (BYTE)u8MajorValue;
    LCN.stLCN.bVirtualChannel = (BYTE)u8MinorValue;

#if ENABLE_SBTVD_BRAZIL_CM_APP
    bNextServiceType = msAPI_CHPROC_CM_GetServiceTypeByLCN_Brazil(LCN.wLCN,(WORD*)&u16MatchOridinal);
    if (bNextServiceType == E_SERVICETYPE_DTV)
#else
#if(ENABLE_PIP)
    if (IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW))
        ||(IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW))&& (MApp_Get_PIPMode() != EN_PIP_MODE_OFF)))
#else
#if(ENABLE_S2)
    if ( IsDTVInUse() || IsS2InUse())
#else
    if (IsDTVInUse())
#endif
#endif
#endif
    {
        if (u8MinorValue ==0)
        {
            if (TRUE == msAPI_CM_GetFirstPositionInMajorNum(bServiceType, (BYTE)u8MajorValue, &u16Ordinal))
            {
            }
            else
            {
                u16Ordinal = INVALID_ORDINAL;
            }
        }
        else
        {
            u16Ordinal = MApp_TV_NumWinVerifyInputValue((U16)LCN.wLCN);
        }
    }
    else
    {
        u16Ordinal = MApp_TV_NumWinVerifyInputValue((WORD)u8MajorValue);
    }

    return u16Ordinal;
}
#endif

void MApp_TV_NumWinProcDigitKey(U8 bKeyValue)
{
    U8 u8TmpIdleDigitCount = MApp_Get_IdleDigitCount();
    U16 u16TmpIdleInputValue = MApp_Get_IdleInputValue();

    if (MApp_ZUI_GetActiveOSD() != E_OSD_TENKEY_NUMBER)
    {
        MApp_ZUI_ACT_StartupOSD(E_OSD_TENKEY_NUMBER);

        u16TmpIdleInputValue =0 ;
        u8TmpIdleDigitCount =0 ;

    #if ENABLE_SBTVD_BRAZIL_APP
        u8IdleMajorValue = 0;
        u8IdleMinorValue = 0;
        enLCNTypeVerified = MAJOR_CH_NUM;
    #endif

    #if ( ENABLE_DVB_TAIWAN_APP || ENABLE_SBTVD_BRAZIL_APP || (TV_SYSTEM == TV_NTSC) )
        msAPI_ATV_SetDirectTuneFlag(TRUE);
    #endif
    }
    u32NumChannChangeTimer = msAPI_Timer_GetTime0();

    /* set max num of key */
#if (ENABLE_SBTVD_BRAZIL_APP==0)
  #if ENABLE_DTV
    if ( IS_NORDIC_COUNTRY(OSD_COUNTRY_SETTING) )
    {
        u8MaxDigiKeyNum = 4;
    }
    else
  #endif
    if (IS_COUNTRY_ONLY_ATV(OSD_COUNTRY_SETTING))
#else
    if (IS_COUNTRY_ONLY_ATV(OSD_COUNTRY_SETTING))
#endif
    {
        u8MaxDigiKeyNum = 2;
    }
    else
    {
    #if ( ENABLE_DVB_TAIWAN_APP)
        #if(ENABLE_PIP)
        if (IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW))
        ||(IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW))&& (MApp_Get_PIPMode() != EN_PIP_MODE_OFF)))
        #else
        if (IsATVInUse())
        #endif
        {
            if (msAPI_ATV_GetCurrentAntenna() == ANT_AIR)
                u8MaxDigiKeyNum = 2;
            else
                u8MaxDigiKeyNum = 3;
        }
        else
    #endif
            u8MaxDigiKeyNum = 3;
    }
#if (ENABLE_S2)
    if(IsS2InUse())
    {
        u8MaxDigiKeyNum = 4;
    }
#endif
    /* set max num of key */

#if ENABLE_SBTVD_BRAZIL_APP
    if (bKeyValue == KEY_DASH)
    {
        if (enLCNTypeVerified==MAJOR_CH_NUM)
        {
            if (u8IdleMajorValue == 0)
            {
                #if(ENABLE_PIP)
                if (IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW))
                ||(IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW))&& (MApp_Get_PIPMode() != EN_PIP_MODE_OFF)))
                #else
                if (IsATVInUse())
                #endif
                {
                    u8IdleMajorValue = (msAPI_ATV_GetCurrentProgramNumber()+1);
                }
                else
                {
                    U16 u16Pos=0, u16LCN;
                    MEMBER_SERVICETYPE bServiceType;
                    LOGICAL_CHANNEL_NUMBER LCN1;
                    bServiceType = msAPI_CM_GetCurrentServiceType();
                    u16Pos = msAPI_CM_GetCurrentPosition(bServiceType);
                    u16LCN = msAPI_CM_GetLogicalChannelNumber(bServiceType, u16Pos);
                    LCN1.wLCN = (WORD)u16LCN;
                    u8IdleMajorValue = (U8)LCN1.stLCN.bPhysicalChannel;
                }
            }

            u16TmpIdleInputValue =0 ;
            u8TmpIdleDigitCount =0 ;
            enLCNTypeVerified = MINOR_CH_NUM;
        }
        else //MINOR_CH_NUM
        {
            MApp_ZUI_ACT_ShutdownOSD();
        #if ( ENABLE_DVB_TAIWAN_APP || ENABLE_SBTVD_BRAZIL_APP || (TV_SYSTEM == TV_NTSC) )
            msAPI_ATV_SetDirectTuneFlag(FALSE);
        #endif
            return;
        }
    }
    else //KEY_0 ~ KEY_9
    {
        u8TmpIdleDigitCount++;
        if (u8TmpIdleDigitCount >= (msAPI_ATV_GetCurrentAntenna()==ANT_AIR? 3:4))
        {
            MApp_ZUI_ACT_ShutdownOSD();
        #if ( ENABLE_DVB_TAIWAN_APP || ENABLE_SBTVD_BRAZIL_APP || (TV_SYSTEM == TV_NTSC) )
            msAPI_ATV_SetDirectTuneFlag(FALSE);
        #endif
            return;
        }
        else
        {
            u16TmpIdleInputValue = u16TmpIdleInputValue * 10 + (bKeyValue - KEY_0);

            if (enLCNTypeVerified == MAJOR_CH_NUM)
            {
                u8IdleMajorValue = u16TmpIdleInputValue;

                if (u8IdleMajorValue == 0)
                    u8TmpIdleDigitCount =0 ;
            }
            else
            {
                u8IdleMinorValue = u16TmpIdleInputValue;
            }
        }
    }

#else
    if (u16TmpIdleInputValue == 0)
    {
        u16TmpIdleInputValue = (bKeyValue - KEY_0);
        u8TmpIdleDigitCount = 1;
    }
    else if ( u8TmpIdleDigitCount<=u8MaxDigiKeyNum )
    {
        u16TmpIdleInputValue = u16TmpIdleInputValue * 10 + (bKeyValue - KEY_0);
        u8TmpIdleDigitCount++;
    }
    else
    {
        u8TmpIdleDigitCount = u16TmpIdleInputValue = 0;
    #if ( ENABLE_DVB_TAIWAN_APP || ENABLE_SBTVD_BRAZIL_APP || (TV_SYSTEM == TV_NTSC) )
        msAPI_ATV_SetDirectTuneFlag(FALSE);
    #endif
        return;
    }

#endif //#if ENABLE_SBTVD_BRAZIL_APP

    MApp_Set_IdleDigitCount(u8TmpIdleDigitCount);
    MApp_Set_IdleInputValue(u16TmpIdleInputValue);
    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_REPAINT_ALL);
    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_RESET_AUTO_CLOSE_TIMER);

    if (u8TmpIdleDigitCount >= u8MaxDigiKeyNum)
    {
        U16 u16Ordinal;

    #if ENABLE_SBTVD_BRAZIL_APP
        u16Ordinal = MApp_TV_SBTVD_DigitKeyVerifyInputValue(u8IdleMajorValue, u8IdleMinorValue);
    #else
        u16Ordinal = MApp_TV_NumWinVerifyInputValue(u16TmpIdleInputValue);
    #endif

        if (u16Ordinal != INVALID_ORDINAL /*&& u16Ordinal != msAPI_CHPROC_CM_GetCurrentOrdinal(E_SERVICETYPE_UNITED_TV, E_PROGACESS_INCLUDE_VISIBLE_ONLY)*/)
        {

        #if ENABLE_PVR
            if (MApp_ZUI_ACT_PVR_Check_Switch_Channel(msAPI_CM_GetCurrentServiceType(), u16Ordinal) == FALSE)
            {
            #if ( ENABLE_DVB_TAIWAN_APP || ENABLE_SBTVD_BRAZIL_APP || (TV_SYSTEM == TV_NTSC) )
                msAPI_ATV_SetDirectTuneFlag(FALSE);
            #endif
                return;
            }
        #endif

            _MApp_ChannelList_ChannelChange(u16Ordinal, SERVICE_TYPE_TV, TRUE, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO);

        #if ( ENABLE_DVB_TAIWAN_APP && (ENABLE_SBTVD_BRAZIL_APP == 0))
            #if(ENABLE_PIP)
            if ((IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW))
            ||(IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW))&& (MApp_Get_PIPMode() != EN_PIP_MODE_OFF)))
            &&(msAPI_ATV_IsProgramSearched(msAPI_ATV_GetCurrentProgramNumber())==FALSE))
            #else
            if (IsATVInUse() && (msAPI_ATV_IsProgramSearched(msAPI_ATV_GetCurrentProgramNumber())==FALSE))
            #endif
            {
                MS_SCANMENU_SETTING *pstScanMenuSetting = NULL;

                MApp_GetGenSetting(EN_GENSETTING_CLASS_SCANMENU,  (void *)&pstScanMenuSetting);
                pstScanMenuSetting->u8ScanType = SCAN_TYPE_MANUAL;
                pstScanMenuSetting->u8ATVManScanType=ATV_MAN_SCAN_TYPE_ONECH;
                pstScanMenuSetting->u8ATVManScanDir=ATV_MAN_SCAN_UP;
                enTVRetVal = EXIT_GOTO_SCAN;
            }
        #endif
        }

    #if ( ENABLE_DVB_TAIWAN_APP || ENABLE_SBTVD_BRAZIL_APP || (TV_SYSTEM == TV_NTSC) )
        msAPI_ATV_SetDirectTuneFlag(FALSE);
    #endif
     //Cancel Freeze
            if (MApp_IsImageFrozen())
            {
                MApp_SetImageFrozen(FALSE);
                MApi_XC_FreezeImg(FALSE, MAIN_WINDOW);
            }

            MApp_ZUI_ACT_Startup_ChannelInfo_OSD();
            MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_BRIEF_CH_INFO);
            //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_TV_BANNER);
        return;
    }
}

/*****************************************************************************/
void MApp_TV_Force2MonitorIdleModeWindows(void)
{
    u32TVModeWinTimer -= TV_MODE_WINDOW_MONITOR_PERIOD;
}

/*****************************************************************************/
void MApp_TV_Initial_IdleCount(void)
{
    u32TVModeWinTimer = msAPI_Timer_GetTime0();
}

#if (MHEG5_ENABLE)
BOOLEAN MApp_TV_MHEG_Loading_Monitor(void)
{
    BOOLEAN ret=FALSE;
#if (1)//(MEMORY_MAP == MMAP_64MB)//mheg5/subtitle co-buffer
#if (ENABLE_SUBTITLE)
    #if CIPLUS_MHEG_1_3
    if (msAPI_MHEG5_GoMHEGWhenSubtitleOn() == 0)
    #endif
    {
        if((stGenSetting.g_SysSetting.fEnableSubTitle == TRUE)&& (u8SubtitleMenuNum != 0))
        {
            return FALSE;
        }
    }
#endif
#endif
#ifdef ROM_FILE
    //if(AeonNeedLoadCode)
    msAPI_MHEG5_Bean_Init();
#endif

    if ( enCheckMHEGLoadingStatus != EN_MHEG5_WAIT //&&
            //!AeonNeedLoadCode &&
            /*MApp_ZUI_GetActiveOSD() == E_OSD_EMPTY*/) //ZUI: ( enCurTVWin == DISP_WIN_NONEOSD ) )
    {
        MApp_TV_DSMCC_Trigger_Monitor();

    #if CIPLUS_MHEG
        #if CIMHEG_DBG
        printf("MApp_TV_MHEG_Loading_Monitor - msAPI_IsCIMHEGRun %d\n", msAPI_IsCIMHEGRun());
        #endif

        if (msAPI_IsCIMHEGRun()==E_MHEG_CI_TRIGGER)
        {
            //exit subtitle
            MApp_Subtitle_Exit();

            // send request start
            msAPI_MHEG5_SendCIMHEGRequestStart();

            // change status as running
            msAPI_MHEG5_SetCIMHEGRun(E_MHEG_CI_RUNNING);

            MApp_MHEG5_DsmccTime_Update();

            enCheckMHEGLoadingStatus = EN_MHEG5_WAIT;
        }
        else
    #endif
        if (MApp_MHEG5_CheckMHEG5Status() == SI_MHEG5_DATA_ONLY)
        {
            ret = TRUE;

            if (g_bQuietlyTune==TRUE)
            {
                // reset quietly tune to false
                g_bQuietlyTune = FALSE;
            }
            else
            {
                MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_LOADING_MHEG5_MSGBOX);
          MS_VE_Output_Ctrl OutputCtrl;
           // disable VE
                OutputCtrl.bEnable = FALSE;
                msAPI_VE_SetOutputCtrl(&OutputCtrl);
                //MW_AUD_SetSoundMute(SOUND_MUTE_ALL, E_MUTE_ON);
            }

            // before auto-boot ready, use timer
            MApp_MHEG5_DsmccTime_Update();

            u32MonitorOsdTimer = msAPI_Timer_GetTime0();
            enCheckMHEGLoadingStatus = EN_MHEG5_WAIT;
        }
#if (ENABLE_SUBTITLE && (MHEG5_WITH_SUBTITLE==0))
        else if (MApp_SI_CheckMHEG5Status() == SI_MHEG5_WITH_VIDEO &&
            (((stGenSetting.g_SysSetting.fEnableSubTitle == false) || (u8SubtitleMenuNum == 0))
            #if CIPLUS_MHEG_1_3
            || (msAPI_MHEG5_GoMHEGWhenSubtitleOn() == 2) // if ssm == 0 or 2, go mheg process regardless subtitle
            #endif
            ))/*subtitle off or subtitle on but no subtitle*/
#else
        else if (MApp_SI_CheckMHEG5Status() == SI_MHEG5_WITH_VIDEO)
#endif
        {
            MApp_MHEG5_DsmccTime_Update();
            enCheckMHEGLoadingStatus = EN_MHEG5_WAIT;
        }
    }
    return ret;
}
void MApp_TV_DSMCC_Trigger_Monitor(void)
{
#if (1)//(MEMORY_MAP == MMAP_64MB)//mheg5/subtitle co-buffer
#if (ENABLE_SUBTITLE)
#if CIPLUS_MHEG_1_3
    if (msAPI_MHEG5_GoMHEGWhenSubtitleOn() == 0)
#endif
    {
        if((stGenSetting.g_SysSetting.fEnableSubTitle == TRUE)&& (u8SubtitleMenuNum != 0))
        {
            return;
        }
    }
#endif
#endif
#if ENABLE_PVR
    if (MApp_PVR_IsPlaybacking() || (MApp_PVR_StateMachineGet() == E_PVR_STATE_TIMESHIFT))
        return;
#endif
    if (msAPI_MHEG5_GetBinStatus()  && (enCheckMHEGLoadingStatus == EN_MHEG5_MONITOR) && (MApp_SI_Get_PMT_PID() != MSAPI_DMX_INVALID_PID))
    {
        enCheckMHEGLoadingStatus=EN_MHEG5_RUNNING;
        msAPI_MHEG5_TriggerDsmcc(MApp_SI_Get_PMT_PID());
        MApp_MHEG5_DsmccTime_Reset();
    }
}
#endif

EN_TV_STATE MApp_TV_GetState(void)
{
    return enTVState;
}

static void MApp_TV_Monitor(SCALER_WIN eWindow)
{
    U16 u16TotalProNum;

#if(ENABLE_TEST_PATTERN)
    if(msAPI_TestPattern_Get_Status() ==TRUE)
        return;
#endif


#if ENABLE_DVB
  #if NORDIG_FUNC //for Nordig Spec v2.0
    u16TotalProNum = msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
  #else
    u16TotalProNum = msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
  #endif
#else // #if ENABLE_DTV
    u16TotalProNum = 0;
#endif // #if ENABLE_DTV


#if(NO_SIGNAL_AUTO_SHUTDOWN)
    MApp_NoSignalAutoSleep_Task();
#endif

#if (ENABLE_UPDATE_MULTIPLEX_VIA_NIT)
#if (LOSS_SIGNAL_ALTERNATIVE_ENABLE)
    if(OSD_COUNTRY_SETTING == OSD_COUNTRY_NORWAY)
    {
        MApp_TV_CheckLossSignal30Days();
        if (LOSS_SIGNAL_CONFIRM_MSG == MApp_DTV_Scan_GetLossSignalState())
        {
            enTVState = STATE_TV_INIT;
            enTVRetVal = EXIT_GOTO_SCAN_NEW_MUX;
        }
    }
#endif
#endif
    MApp_CheckBlockProgramme();

  #if (MHEG5_ENABLE)
    if (( bIsBlocked == FALSE || bStopMonitorBlock == TRUE)
            && IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(eWindow))
            && (msAPI_MHEG5_checkGoBackMHEG5()== FALSE)
            && (msAPI_IsCIMHEGRun() == E_MHEG_CI_TRIGGER || enFrotEndLockStatus == FRONTEND_LOCK)
            && (u16TotalProNum > 0))
    {
        // TODO...remove this! subtitle should co exist with dsmcc downloading
        MApp_TV_MHEG_Loading_Monitor();
    }
   #endif



    if (MApp_ZUI_GetActiveOSD() == E_OSD_TENKEY_NUMBER) //ZUI: enCurTVWin == DISP_WIN_TENKEY_NUMBER)
    {
        //monitor number window
        if ((u32NumChannChangeTimer > 0) && msAPI_Timer_DiffTimeFromNow(u32NumChannChangeTimer) > 3000) //unit = ms
        {
            U16 u16Ordinal;
          if(MApp_Get_IdleDigitCount() > u8MaxDigiKeyNum)
            return;
          #if ENABLE_SBTVD_BRAZIL_APP
            u16Ordinal = MApp_TV_SBTVD_DigitKeyVerifyInputValue(u8IdleMajorValue, u8IdleMinorValue);
          #else
            u16Ordinal = MApp_TV_NumWinVerifyInputValue(u16IdleInputValue);
          #endif

            if (u16Ordinal != INVALID_ORDINAL /*&& u16Ordinal != msAPI_CHPROC_CM_GetCurrentOrdinal(E_SERVICETYPE_UNITED_TV, E_PROGACESS_INCLUDE_VISIBLE_ONLY)*/)
            {
              #ifdef ENABLE_SELECT_NONESEARCH_CH
                printf("\r\n [1] Exist ch: u16ChannelReturn_Num1=%u",u16ChannelReturn_Num1);
                printf("\r\n [1] Exist ch: u16ChannelReturn_Num2=%u",u16ChannelReturn_Num2);
                u16ChannelReturn_Num2=u16ChannelReturn_Num1;
                u16ChannelReturn_Num1=IVALID_TV_RETURN_NUM;
             #endif

              #if ENABLE_PVR
                if (MApp_ZUI_ACT_PVR_Check_Switch_Channel(msAPI_CM_GetCurrentServiceType(), u16Ordinal) == FALSE)
                {
                    return;
                }
              #endif

                _MApp_ChannelList_ChannelChange(u16Ordinal, SERVICE_TYPE_TV, TRUE, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO);

                //Brazil also need this feature
              #if ( ENABLE_DVB_TAIWAN_APP && (ENABLE_SBTVD_BRAZIL_APP == 0))
                if (IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(eWindow)) && (msAPI_ATV_IsProgramSearched(msAPI_ATV_GetCurrentProgramNumber())==FALSE))
                {
                    stGenSetting.stScanMenuSetting.u8ScanType = SCAN_TYPE_MANUAL;
                    stGenSetting.stScanMenuSetting.u8ATVManScanType=ATV_MAN_SCAN_TYPE_ONECH;
                    stGenSetting.stScanMenuSetting.u8ATVManScanDir=ATV_MAN_SCAN_UP;
                    enTVRetVal = EXIT_GOTO_SCAN;
                }
              #endif
                MApp_ZUI_ACT_ShutdownOSD();
            }
            else
            {
         #ifdef ENABLE_SELECT_NONESEARCH_CH
                if(u16IdleInputValue>=msAPI_ATV_GetChannelMin()&&u16IdleInputValue<=msAPI_ATV_GetChannelMax())
                {
                    u16ChannelReturn_Num2=u16ChannelReturn_Num1;
                    u16ChannelReturn_Num1=u16IdleInputValue;
                    printf("\r\n ATV ch: u16ChannelReturn_Num1=%u",u16ChannelReturn_Num1);
                    printf("\r\n ATV ch: u16ChannelReturn_Num2=%u",u16ChannelReturn_Num2);

                    dmSetLastWatchedOrdinal();
         #endif
                    if (IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(eWindow)))
                    {
                        dmSetLastWatchedOrdinal();
                        if ( IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(eWindow)))
                        {
                            MApp_ChannelChange_DisableAV(eWindow);
                        }
                        msAPI_CHPROC_CM_SetCurrentOrdinal(E_SERVICETYPE_ATV, u16IdleInputValue-2, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO);
                    }

                #if (ENABLE_SBTVD_BRAZIL_APP)
                    if (IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))//@@-- DTV channel  change to unsearch ATV channel, show disable channel,otherwise ATV will no audio.
                    {
                        UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_ATV;
                    #if ENABLE_SBTVD_BRAZIL_APP
                        MApp_ChannelChange_DisableChannel(TRUE,MAIN_WINDOW);
                    #endif
                        MApp_InputSource_SwitchSource(UI_INPUT_SOURCE_TYPE, MAIN_WINDOW);
                        dmSetLastWatchedOrdinal();
                        msAPI_CHPROC_CM_SetCurrentOrdinal(E_SERVICETYPE_ATV, u16IdleInputValue-2, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO);
                    }
                #endif

       #ifdef ENABLE_SELECT_NONESEARCH_CH
                }
       #endif
            }

          #if ( ENABLE_DVB_TAIWAN_APP || ENABLE_SBTVD_BRAZIL_APP || (TV_SYSTEM == TV_NTSC) )
            msAPI_ATV_SetDirectTuneFlag(FALSE);
          #endif

            //Cancel Freeze
            if (g_bIsImageFrozen)
            {
                g_bIsImageFrozen = FALSE;
                MApi_XC_FreezeImg(g_bIsImageFrozen, MAIN_WINDOW);
            }

            MApp_ZUI_ACT_Startup_ChannelInfo_OSD();
            MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_BRIEF_CH_INFO);
            //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_TV_BANNER);
        }
    }

    //printf("CI:%bx %bx\n", bStartMHEG5, msAPI_MHEG5_checkGoBackMHEG5());
#if(ENABLE_OSD_SUBTITLE_EXCLUSIVE == ENABLE)
   #if (ENABLE_SUBTITLE)
        if((MApp_ZUI_GetActiveOSD()==E_OSD_EMPTY)&&MApp_UiMenu_GetCoexistWin_State())
        {
            MApp_Subtitle_SetShowStatus(TRUE);
        }
    #endif
#endif

#if  ENABLE_SBTVD_BRAZIL_APP
      #if (BRAZIL_CC)
       if ((msAPI_Timer_DiffTimeFromNow(u32TVModeWinTimer) > TV_MODE_WINDOW_MONITOR_PERIOD_NOSINGAL) )
       {
            if ((IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(eWindow)) && DB_CC_SETTING.enDTVCaptionType == DTV_CAPTION_ON)
                ||(IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(eWindow)) && DB_CC_SETTING.enATVCaptionType != ATV_CAPTION_TYPE_OFF))
            {
                if(!((MApp_PVR_IsPlaybacking() || MApp_PVR_IsRecording())
                    &&(ENABLE_TIMESHIT==DISABLE)))
                {
                    enTVState = STATE_TV_INIT;
                    enTVRetVal = EXIT_GOTO_CLOSEDCAPTION;
                }
            }
       }
      #endif
#endif // #if  ENABLE_SBTVD_BRAZIL_APP
    if ((msAPI_Timer_DiffTimeFromNow(u32TVModeWinTimer) > TV_MODE_WINDOW_MONITOR_PERIOD_NOSINGAL) //unit = ms
      #if ENABLE_PVR
        && (!MApp_PVR_IsPlaybacking() && !MApp_PVR_IsRecording())
      #endif
       )
    {
      #if ENABLE_DTV
        static U8 _u8DtvNoSingalMsgCount = 1; //base on TV_MODE_WINDOW_MONITOR_PERIOD_NOSINGAL
      #endif

    #if (ATSC_CC == ATV_CC)
        if((enTVState == STATE_TV_WAIT)&& (IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(eWindow)) && DB_CC_SETTING.enATVCaptionType != ATV_CAPTION_TYPE_OFF))
        {
            enTVState = STATE_TV_INIT;
            enTVRetVal = EXIT_GOTO_CLOSEDCAPTION;
        }

       if  ( IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(eWindow))
          && DB_CC_SETTING.enATVCaptionType != ATV_CAPTION_TYPE_OFF
          && (SYS_SCREEN_SAVER_TYPE(eWindow)==EN_SCREENSAVER_NULL) )
      {
          if (MApp_CC_GetInfo(CC_SELECTOR_STATUS_CODE) != STATE_CAPTION_PARSER)
          {
              U32 u32Err;
              u32Err = MApp_CC_CtrlParser(CC_SELECTOR_MODE, CC_MODE_ATV);
              u32Err = MApp_CC_CtrlParser(CC_SELECTOR_SERVICE, (EN_CLOSEDCAPTION_SERVICE)DB_CC_SETTING.enATVCaptionType);
              u32Err = MApp_CC_CtrlParser(CC_SELECTOR_RESET_TO_DEFAULT, ENABLE);
        #ifdef HER_BRAZIL
                u32Err = MApp_CC_CtrlParser(CC_SELECTOR_AXIS_XPOS, 0xA4);        // horizontal offset
                u32Err = MApp_CC_CtrlParser(CC_SELECTOR_AXIS_YPOS, 0x74);        // vertical offset
        #endif

              u32Err = MApp_CC_StartParser();
          }
      }
    #endif // #ifdef NTSC_CC_ON_DVB

    #if ENABLE_DTV
        if (IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(eWindow)) && (SYS_SCREEN_SAVER_TYPE(eWindow)==EN_SCREENSAVER_NULL) && (_u8DtvNoSingalMsgCount>0))
        {
            _u8DtvNoSingalMsgCount--;
            u32TVModeWinTimer = msAPI_Timer_GetTime0();
            return;
        }
        else if (IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(eWindow)))//add IsDTVInUse() because if ATV has no signal this block will set SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) from EN_SCREENSAVER_NOSYNC_VD to EN_SCREENSAVER_NOSIGNAL which will cause MApp_TV_ScreenSaverClear fail when ATV gets signal later
        {
            _u8DtvNoSingalMsgCount = 1;
            if ((/*(enFrotEndLockStatus == FRONTEND_UNKNOWN) || */(enFrotEndLockStatus == FRONTEND_UNLOCK))
                &&( SYS_SCREEN_SAVER_TYPE(eWindow) != EN_SCREENSAVER_NOSIGNAL))
            {
                u8TVNoSignalCount++;
                u8InvalidServiceCount=0;
                if ((SYS_INPUT_SOURCE_TYPE(eWindow) == INPUT_SOURCE_DTV)&&(u8TVNoSignalCount>80))
                {
                    u8TVNoSignalCount=0;
                    SYS_SCREEN_SAVER_TYPE(eWindow) = EN_SCREENSAVER_NOSIGNAL;
                }
                #if (ENABLE_PIP)
                if (MApp_Get_PIPMode() != EN_PIP_MODE_OFF)
                {
                    if ( SYS_SCREEN_SAVER_TYPE(SUB_WINDOW) == EN_SCREENSAVER_NOSIGNAL || SYS_SCREEN_SAVER_TYPE(SUB_WINDOW) == EN_SCREENSAVER_NOSYNC || SYS_SCREEN_SAVER_TYPE(SUB_WINDOW) == EN_SCREENSAVER_NOSYNC_VD)
                    {
                        //  power saving TO DO : wait for API from ken.chang
                    }
                }
                #endif
                if (MApp_ZUI_GetActiveOSD() == E_OSD_SCREEN_SAVER)
                {
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_REPAINT_ALL);
                }
            }

            else//show NO CI MODULE when unplug signal line and re-plug
            {
            #if (defined SUPPORT_MPEG2_SD_ONLY || (defined AUSTRALIA && (MEMORY_MAP <= MMAP_64MB)))
                if  (enFrotEndLockStatus == FRONTEND_LOCK && msAPI_VID_GetCodecType() != E_VDEC_CODEC_TYPE_MPEG2)
                {
                    SYS_SCREEN_SAVER_TYPE(eWindow) = EN_SCREENSAVER_UNSUPPORT_MODE;
                }
            #endif

                u8TVNoSignalCount=0;
                u8DTVNoSignalCount=0;
                if (MApp_Scramble_GetCurStatus()
                  #if ENABLE_CI
                    && (!msAPI_CI_CardDetect())
                    //&& (enCurTVWin == DISP_WIN_NONEOSD)
                  #endif
                   )
                {
                    //enTVState = STATE_TV_INIT;
                  #if MHEG5_ENABLE
                    if ((msAPI_MHEG5_IsRunning() == 0)
                        && ((msAPI_MHEG5_checkGoBackMHEG5()==false)
                          #if ENABLE_SUBTITLE
                            || (stGenSetting.g_SysSetting.fEnableSubTitle && u8SubtitleMenuNum != 0)
                          #endif
                        )
                       )
                  #endif
                    {
                        if(MApp_ParentalControl_GetBlockStatus())
                        {
                            if(FALSE==bCheckParentalPW)
                            {
                                MApp_ChannelChange_CheckBlockChannelPW();
                                bCheckParentalPW= TRUE;
                            }
                            else
                            {
                                if (SYS_INPUT_SOURCE_TYPE(eWindow) == INPUT_SOURCE_DTV)
                                {
                                    SYS_SCREEN_SAVER_TYPE(eWindow) = EN_SCREENSAVER_BLOCKRATING;
                                }
                            }
                        }
                        else if (SYS_INPUT_SOURCE_TYPE(eWindow) == INPUT_SOURCE_DTV)
                        {
                            SYS_SCREEN_SAVER_TYPE(eWindow) = EN_SCREENSAVER_SCRAMBLE;
                        }
                    }
                    //ZUI: MApp_UiMenu_ExecuteKeyEvent(MIA_SCRAMBLE_CHANNEL_MSG_BOX);
                }
            }
        }

        if (IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(eWindow))
            && (u16TotalProNum == 0)
            && (MApp_ZUI_GetActiveOSD() == E_OSD_EMPTY || MApp_ZUI_GetActiveOSD()==E_OSD_SCREEN_SAVER)
          #if ENABLE_CI
            && (msAPI_CI_GetCIMessageType() != EN_CIMSG_LOAD_NONE)
            && (msAPI_CI_GetCIMessageType() != EN_CIMSG_DISPLAY)
            && (msAPI_CI_GetCIMessageType() != EN_CIMSG_NOMODULE_DISPLAY)
          #endif
           )
        {
            // no show program
            TV_DBINFO(printf("IDLE>> no show program !!\n"));
            enTVState = STATE_TV_INIT;

            if (SYS_INPUT_SOURCE_TYPE(eWindow) == INPUT_SOURCE_DTV)
            {
                SYS_SCREEN_SAVER_TYPE(eWindow) = EN_SCREENSAVER_NO_SHOW_PROGRAM;
          #if 0
                msAPI_Scaler_SetCVBSMute(ENABLE, E_VE_MUTE_BLOCK,SYS_INPUT_SOURCE_TYPE(eWindow),OUTPUT_CVBS1);
                #if (INPUT_SCART_VIDEO_COUNT >= 2)
                msAPI_Scaler_SetCVBSMute(ENABLE, E_VE_MUTE_BLOCK,SYS_INPUT_SOURCE_TYPE(eWindow),OUTPUT_CVBS2);
                #endif
          #endif
            }
        }
        else if (IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(eWindow))
                 && (MApp_GetSignalStatus() == SIGNAL_UNLOCK)
                 && (MApp_ZUI_GetActiveOSD()==E_OSD_EMPTY || MApp_ZUI_GetActiveOSD()==E_OSD_SCREEN_SAVER)
              #if ENABLE_CI
                 && (msAPI_Timer_DiffTimeFromNow( u32CardStatusChangedTimer ) > 5000)
                 && (!msAPI_CI_CardDetect()|| EN_CI_APP_TYPE_CA == msAPI_CI_GetAppType())
                 && (msAPI_CI_GetCIMessageType() != EN_CIMSG_LOAD_NONE)
                 && (msAPI_CI_GetCIMessageType() != EN_CIMSG_DISPLAY)
                 && (msAPI_CI_GetCIMessageType() != EN_CIMSG_NOMODULE_DISPLAY)
              #endif
                )
        {
        #if(ENABLE_API_DTV_SYSTEM)
            MEMBER_SERVICETYPE bServiceType = msAPI_CM_GetCurrentServiceType();
            U16 u16CurPosition = msAPI_CM_GetCurrentPosition(bServiceType);
        #endif

            if (/*enFrotEndLockStatus == FRONTEND_UNKNOWN || */enFrotEndLockStatus == FRONTEND_UNLOCK)
            {
                TV_DBINFO(printf("IDLE_WIN>> no signal\n"));
                //ZUI: MApp_UiMenu_ExecuteKeyEvent(MIA_NO_SIGNAL_MSG_BOX);
                u8DTVNoSignalCount++;
                if ((SYS_INPUT_SOURCE_TYPE(eWindow) == INPUT_SOURCE_DTV)&&(u8DTVNoSignalCount>100))
                {
                    u8DTVNoSignalCount=0;
                    SYS_SCREEN_SAVER_TYPE(eWindow) = EN_SCREENSAVER_NOSIGNAL;
                }
            }
            else
            {
                if ((!MApp_TV_IsProgramRunning()))
                {
                    if (SYS_INPUT_SOURCE_TYPE(eWindow) == INPUT_SOURCE_DTV)
                    {
                        SYS_SCREEN_SAVER_TYPE(eWindow) = EN_SCREENSAVER_NOT_RUNNING2;
                    }
                }
            #if(ENABLE_API_DTV_SYSTEM)
                else if (msAPI_CM_GetProgramAttribute(bServiceType, u16CurPosition, E_ATTRIBUTE_IS_SERVICE_ID_ONLY))
                {
                    TV_DBINFO(printf("IDLE_WIN>> service id only\n"));
                    if (SYS_INPUT_SOURCE_TYPE(eWindow) == INPUT_SOURCE_DTV)
                    {
                        SYS_SCREEN_SAVER_TYPE(eWindow) = EN_SCREENSAVER_NOT_RUNNING1;
                    }

                }
            #endif
                else if (MApp_Scramble_GetCurStatus()
                      #if ENABLE_CI
                         && !msAPI_CI_CardDetect()
                         //&& (enCurTVWin == DISP_WIN_NONEOSD)
                      #endif
                        )
                {
                    //enTVState = STATE_TV_INIT;
                  #if MHEG5_ENABLE
                    if ((msAPI_MHEG5_IsRunning() == FALSE)
                        && ((msAPI_MHEG5_checkGoBackMHEG5() == FALSE)
                      #if ENABLE_SUBTITLE
                            || (stGenSetting.g_SysSetting.fEnableSubTitle && u8SubtitleMenuNum != 0)
                      #endif
                           )
                       )
                  #endif
                    {
                        if (SYS_INPUT_SOURCE_TYPE(eWindow) == INPUT_SOURCE_DTV)
                        {
                            SYS_SCREEN_SAVER_TYPE(eWindow) = EN_SCREENSAVER_SCRAMBLE;
                        }
                    }
                    //ZUI: MApp_UiMenu_ExecuteKeyEvent(MIA_SCRAMBLE_CHANNEL_MSG_BOX);
                }
              #if ENABLE_CI
                else if (MApp_Scramble_GetCurStatus() && msAPI_CI_CardDetect())
                {
                    if(MApp_ParentalControl_GetBlockStatus())
                    {
                        if(FALSE==bCheckParentalPW)
                        {
                            MApp_ChannelChange_CheckBlockChannelPW();
                            bCheckParentalPW= TRUE;
                        }
                        else
                        {
                            if (SYS_INPUT_SOURCE_TYPE(eWindow) == INPUT_SOURCE_DTV)
                            {
                                SYS_SCREEN_SAVER_TYPE(eWindow) = EN_SCREENSAVER_BLOCKRATING;
                            }
                        }
                    }
                    else if (SYS_INPUT_SOURCE_TYPE(eWindow) == INPUT_SOURCE_DTV)
                    {
                        SYS_SCREEN_SAVER_TYPE(eWindow) = EN_SCREENSAVER_SCRAMBLED_PROGRAM;
                    }

                    //#else
                    //enTVState = STATE_TV_INIT;
                    //SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) = EN_SCREENSAVER_SCRAMBLED_PROGRAM;
                    //ZUI: MApp_UiMenu_ExecuteKeyEvent(MIA_SCRAMBLED_PROGRAM_SHOWN_MSG_BOX);
                    //#endif
                }
              #endif
            #if(ENABLE_DVB)
                else if (IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(eWindow))
                    && (MApp_TV_IsProgramRunning())
                    && (msAPI_CM_GetCurrentServiceType() == E_SERVICETYPE_DTV)
                    && (MApp_SI_Get_PSISIVersion(E_VER_PMT) != INVALID_VERSION_NUM)
                    && (enMVDVideoStatus != MVD_GOOD_VIDEO)
                    && (MApi_VDEC_IsIFrameFound() != E_VDEC_OK)
                    && (!MApi_AUDIO_IsMadLock())
                    )
                {
                    if (SYS_INPUT_SOURCE_TYPE(eWindow) == INPUT_SOURCE_DTV)
                    {
                        SYS_SCREEN_SAVER_TYPE(eWindow) = EN_SCREENSAVER_UNSUPPORT_MODE;
                    }
                }
            #endif
                else
                {
                    TV_DBINFO(printf("IDLE_WIN>> no signal\n"));
                    if (SYS_INPUT_SOURCE_TYPE(eWindow) == INPUT_SOURCE_DTV)
                    {
                        SYS_SCREEN_SAVER_TYPE(eWindow) = EN_SCREENSAVER_NOSIGNAL;
                    }
                    //#else
                    //SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) = EN_SCREENSAVER_NOSIGNAL;
                    //ZUI: MApp_UiMenu_ExecuteKeyEvent(MIA_NO_SIGNAL_MSG_BOX);
                    //#endif
                }
            }

            // mvd reset & play for weak signal hang
            //
            // remove patch code for weak signal because the video will delay to display (over 15 second) in flowing DTG channel change test
            // Audio_tests_Layer_2_112-224kbps.mpg\ V700+112kbps and Bars+192kbps Audio_tests_Layer_2_256-384kbps.mpg\ Flowers+256kbps
            //
            //msAPI_Scaler_SetBlueScreen(ENABLE, E_XC_FREE_RUN_COLOR_BLACK, DEFAULT_SCREEN_UNMUTE_TIME, MAIN_WINDOW);
            //msAPI_VID_MVDCommand( MSAPI_VID_RESET );
            //msAPI_VID_MVDCommand( MSAPI_VID_PLAY);
        }
        else if ((enFrotEndLockStatus == FRONTEND_LOCK)
            && (!MApp_TV_IsProgramRunning())
                 && ( SYS_SCREEN_SAVER_TYPE(eWindow) != EN_SCREENSAVER_NULL)
                 && (SYS_SCREEN_SAVER_TYPE(eWindow) != EN_SCREENSAVER_NOT_RUNNING2)
                 && (SYS_SCREEN_SAVER_TYPE(eWindow) != EN_SCREENSAVER_NOT_RUNNING1)
                )
        {
            if (SYS_INPUT_SOURCE_TYPE(eWindow) == INPUT_SOURCE_DTV)
            {
                SYS_SCREEN_SAVER_TYPE(eWindow) = EN_SCREENSAVER_NULL;
            }

          #if (ENABLE_PIP)
            if((MApp_Get_PIPMode() != EN_PIP_MODE_OFF)
                &&(SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW)==EN_SCREENSAVER_NULL)
                &&(SYS_SCREEN_SAVER_TYPE(SUB_WINDOW)==EN_SCREENSAVER_NULL))
            {
                MApp_ZUI_ACT_ShutdownOSD();
            }
            else if (MApp_Get_PIPMode() == EN_PIP_MODE_OFF)
          #endif
            {
                MApp_ZUI_ACT_ShutdownOSD();
            }
            //#else
            //SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) = EN_SCREENSAVER_NULL;
            //ZUI: MApp_UiMenu_ExecuteKeyEvent(MIA_NO_SIGNAL_MSG_BOX);
            //#endif
        }
    #if(ENABLE_DVB)
        else if ( MApp_TV_IsInvalidService() && IsDVBInUse() ) // Fix Mantis 0969998
        {
            TV_DBINFO(printf("IDLE_WIN>> Invalide Service....u8InvalidServiceCount=%d\n",u8InvalidServiceCount));
            u8InvalidServiceCount++;
            if ((SYS_INPUT_SOURCE_TYPE(eWindow) == INPUT_SOURCE_DTV)&&(u8InvalidServiceCount>100))
            {
                u8InvalidServiceCount=0;
                TV_DBINFO(printf("Invalide Service_WIN>>\n"));
                SYS_SCREEN_SAVER_TYPE(eWindow) = EN_SCREENSAVER_INVALID_SERVICE;
            }
        }
    #endif
        else if (bIsBlocked
                 && (SYS_SCREEN_SAVER_TYPE(eWindow)==EN_SCREENSAVER_NULL) //ZUI: (enCurTVWin == DISP_WIN_NONEOSD)
                 &&(FALSE ==bStopMonitorBlock)
                 &&(stGenSetting.g_BlockSysSetting.u8BlockSysLockMode == 1))
        {
            if (FALSE == bCheckBlockPW)
            {
                MApp_ChannelChange_CheckBlockChannelPW();
                bCheckBlockPW= TRUE;
            }
            else
            {
                if (SYS_INPUT_SOURCE_TYPE(eWindow) == INPUT_SOURCE_DTV)
                {
                    SYS_SCREEN_SAVER_TYPE(eWindow) = EN_SCREENSAVER_LOCKED_PROGRAM;
                }
                //#else
                //SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) = EN_SCREENSAVER_LOCKED_PROGRAM;
                //#endif
            }
        }
        else if (MApp_ParentalControl_GetBlockStatus()&& MApp_Get_MonitorParental()==TRUE
                 && (SYS_SCREEN_SAVER_TYPE(eWindow)==EN_SCREENSAVER_NULL)) //ZUI: (enCurTVWin == DISP_WIN_NONEOSD)
        {

            if (FALSE==bCheckParentalPW)
            {
                MApp_ChannelChange_CheckBlockChannelPW();
                bCheckParentalPW= TRUE;
            }
            else
            {
                if (SYS_INPUT_SOURCE_TYPE(eWindow) == INPUT_SOURCE_DTV)
                {
                    SYS_SCREEN_SAVER_TYPE(eWindow) = EN_SCREENSAVER_BLOCKRATING;
                }
                //#else
                //SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) = EN_SCREENSAVER_BLOCKRATING;
                //#endif
            }
        }
        else if (!MApp_ParentalControl_GetBlockStatus()
                 && MApp_Get_MonitorParental()==TRUE
                 && bCheckParentalPW == TRUE
                 && (MApp_ZUI_GetActiveOSD() == E_OSD_MESSAGE_BOX
                 || (MApp_ZUI_GetActiveOSD()== E_OSD_SCREEN_SAVER && SYS_SCREEN_SAVER_TYPE(eWindow) == EN_SCREENSAVER_BLOCKRATING)))
        {
            if(MApp_ZUI_GetActiveOSD()==E_OSD_SCREEN_SAVER && SYS_SCREEN_SAVER_TYPE(eWindow) == EN_SCREENSAVER_BLOCKRATING)
            {
                SYS_SCREEN_SAVER_TYPE(eWindow) = EN_SCREENSAVER_NULL;
            }
            MApp_ZUI_ACT_ShutdownOSD();
            bCheckParentalPW = FALSE;
            MS_DEBUG_MSG(printf("EN_SCREENSAVER_BLOCKRATING: Someting need to do??\n"));
        }
    #if( ENABLE_DVB )
        else if (IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(eWindow))
                 && (MApp_TV_IsProgramRunning())
                 && (msAPI_CM_GetCurrentServiceType() == E_SERVICETYPE_RADIO)
                 && (SYS_SCREEN_SAVER_TYPE(eWindow)==EN_SCREENSAVER_NULL)
                 && (MApp_SI_Get_PSISIVersion(E_VER_PMT)!=INVALID_VERSION_NUM)
                 //&& (MApp_SI_CheckMHEG5Status()!=SI_MHEG5_DATA_ONLY)
                 && (enMVDVideoStatus != MVD_GOOD_VIDEO)
                 && (MApi_AUDIO_IsMadLock())
                )
        {
            if (SYS_INPUT_SOURCE_TYPE(eWindow) == INPUT_SOURCE_DTV)
            {
                SYS_SCREEN_SAVER_TYPE(eWindow) = EN_SCREENSAVER_AUDIOONLY;
            }
        }
    #endif
    #if (ENABLE_SBTVD_BRAZIL_APP)
      #if (BRAZIL_CC)
        else if (IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(eWindow))
                 //&& DB_CC_SETTING.enDTVCaptionType == DTV_CAPTION_ON
                 && SYS_SCREEN_SAVER_TYPE(eWindow)==EN_SCREENSAVER_NULL
                 /*&& MApp_ZUI_GetActiveOSD()==E_OSD_EMPTY*/)
        {
            U32 u32Err;
            U16 u16CCPid =MApp_SI_Get_CC_PID();

            #if BRAZIL_PVR_CC
            if (MApp_PVR_IsPVRStatePlaybacking())
                u16CCPid = MApp_PVR_Playback_GetCCPID();
            #endif
            if (u16CCPid != MSAPI_DMX_INVALID_PID)
            {
                if(!MApp_PVR_IsPVRStatePlaybacking()||MApp_PVR_IsPlaybacking())
                {
                    if (*MApp_Dmx_GetFid(EN_PES_FID) == MSAPI_DMX_INVALID_FLT_ID)
                    {
                        MApp_ClosedCaption_Open_Filter(u16CCPid);

                    }
                    else if(MApp_IsCCFileIn()!=MApp_PVR_IsPVRStatePlaybacking())
                    {
                        u32Err = MApp_CC_StopParser();
                        MApp_Dmx_PES_Stop();
                        MApp_ClosedCaption_Open_Filter(u16CCPid);
                    }

                    if (*MApp_Dmx_GetFid(EN_PES_FID) !=MSAPI_DMX_INVALID_FLT_ID)
                    {
                        if (MApp_CC_GetInfo(CC_SELECTOR_STATUS_CODE) != STATE_CAPTION_PARSER)
                        {
                            stCCWinSet.s32X_offset = 0;
                            stCCWinSet.s32Y_offset = 0;
                            u32Err = MApp_CC_CtrlParser(CC_SELECTOR_MODE, CC_MODE_DTV);
                            u32Err = MApp_CC_CtrlParser(CC_SELECTOR_SERVICE, CC_SERVICE_SERVICE1);
                            u32Err = MApp_CC_CtrlParser(CC_SELECTOR_AXIS_X_OFFSET, (U32)&stCCWinSet.s32X_offset);        // horizontal offset
                            u32Err = MApp_CC_CtrlParser(CC_SELECTOR_AXIS_Y_OFFSET, (U32)&stCCWinSet.s32Y_offset);        // vertical offset
                            u32Err = MApp_CC_StartParser();
                        }
                    }
                }
            }
            else if (*MApp_Dmx_GetFid(EN_PES_FID) != MSAPI_DMX_INVALID_FLT_ID)
            {
                u32Err = MApp_CC_StopParser();
                MApp_Dmx_PES_Stop();
            }

        }
        else if (IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(eWindow))
                 && DB_CC_SETTING.enATVCaptionType != ATV_CAPTION_TYPE_OFF
                 && SYS_SCREEN_SAVER_TYPE(eWindow)==EN_SCREENSAVER_NULL
                 && MApp_ZUI_GetActiveOSD()==E_OSD_EMPTY)
        {
            if (MApp_CC_GetInfo(CC_SELECTOR_STATUS_CODE) != STATE_CAPTION_PARSER)
            {
                U32 u32Err;
                u32Err = MApp_CC_CtrlParser(CC_SELECTOR_MODE, CC_MODE_ATV);
                u32Err = MApp_CC_CtrlParser(CC_SELECTOR_SERVICE, (EN_CLOSEDCAPTION_SERVICE)DB_CC_SETTING.enATVCaptionType);
                u32Err = MApp_CC_CtrlParser(CC_SELECTOR_RESET_TO_DEFAULT, ENABLE);
                u32Err = MApp_CC_CtrlParser(CC_SELECTOR_608_SCROLL_STEP, FALSE);
                u32Err = MApp_CC_CtrlParser(CC_SELECTOR_608_TIMEOUT_TEXT, 16000);
        #ifdef HER_BRAZIL
                u32Err = MApp_CC_CtrlParser(CC_SELECTOR_AXIS_XPOS, 0xA4);        // horizontal offset
                u32Err = MApp_CC_CtrlParser(CC_SELECTOR_AXIS_YPOS, 0x74);        // vertical offset
        #endif
                u32Err = MApp_CC_StartParser();
            }
        }
      #endif // #if (BRAZIL_CC)
    #else
      #if ENABLE_SUBTITLE
        else if ( IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(eWindow))
                  && (stGenSetting.g_SysSetting.fEnableSubTitle == TRUE)
                  && (u8SubtitleMenuNum != 0)
                #if 0//CIPLUS_MHEG_1_3
                    && (msAPI_MHEG5_GoMHEGWhenSubtitleOn() !=2)// 0)
                #endif
                #if ENABLE_TTX
                  && !MApp_TTX_IsChInfoOn()
                #endif
                #if (SUBTITLE_WITH_OSD == FALSE )
                  && (SYS_SCREEN_SAVER_TYPE(eWindow)==EN_SCREENSAVER_NULL)
                #endif
                  && (MApp_ParentalControl_GetBlockStatus() == 0)
                  && msAPI_CM_GetVideoPID(msAPI_CM_GetCurrentServiceType(),msAPI_CM_GetCurrentPosition(msAPI_CM_GetCurrentServiceType())) != MSAPI_DMX_INVALID_PID)
        {

          #if ENABLE_CI
            if ( ( !msAPI_CI_CardDetect()) || ( msAPI_CI_CardDetect()&& (msAPI_CI_GetCardState() == EN_MODULE_READY) ) )
          #endif
            if(MApp_ZUI_GetActiveOSD() != E_OSD_TENKEY_NUMBER )
            {
                //no press hotkey, first search default lang
              #if ENABLE_TTX
                if (UI_Hotkey_Subtitle)
                {
                    if ((u8SubtitleMenuNum == gu8TTXSubtitleServiceNum) && (stGenSetting.g_SysSetting.fEnableTTXSubTitle == FALSE))
                    {
                        UI_Hotkey_Subtitle=FALSE;
                    }
                    if (gu8TTXSubtitleServiceNum == 0 && (stGenSetting.g_SysSetting.fEnableTTXSubTitle == TRUE))
                    {
                        UI_Hotkey_Subtitle=FALSE;
                    }
                }
              #endif

                if (UI_Hotkey_Subtitle == FALSE)
                {
                    if (MApp_TV_SelectSubtileLang()==TRUE)
                    {
                    #if PVR_AND_TTX_DIFF_WITH_MHEG5
                        MApp_TTX_TurnTTXOnOff(FALSE);
                    #endif
                        enTVState = STATE_TV_INIT;
                      #if ( SUBTITLE_WITH_OSD == FALSE )
                        enTVRetVal = EXIT_GOTO_SUBTITLE;
                      #endif
                    }
                    else
                    {
                      #if ENABLE_TTX
                        U8 Magazine, Page;
                        U16 u16Pid;
                    #if(ENABLE_S2)
                        if ((IsDTVInUse()||IsS2InUse())&&MApp_TTX_GetControlMode()==TTX_MODE_NORMAL
                    #else
                        if (IsDTVInUse()&&MApp_TTX_GetControlMode()==TTX_MODE_NORMAL
                    #endif
                          #if (ENABLE_PIP)
                            && (MApp_Get_PIPMode() == EN_PIP_MODE_OFF)
                          #endif
                           )
                        {
                            if (stGenSetting.g_SysSetting.fEnableTTXSubTitle && !MApp_TTX_IsChInfoOn()&&(!bIsBlocked || (bIsBlocked && bStopMonitorBlock))&&(enTVRetVal != EXIT_GOTO_INPUTSOURCE))
                            {
                                if (MApp_TTX_Subtitle_GetDefaultLang(LAST_SECLECT_LANGUAGE/*GET_OSD_MENU_LANGUAGE()*/, &Magazine, &Page, &u16Pid))
                                {
                                #if PVR_AND_TTX_DIFF_WITH_MHEG5
                                    MApp_TTX_TurnTTXOnOff(TRUE);
                                #endif
                                    MApp_TTX_SetSubtitleTTX_PID(u16Pid);
                                    MApp_TTX_SetSubtitlePage(((U16)Magazine<<8) | Page, 0xFFFF);
                                    MApp_TTX_TeletextCommand(TTX_SUBTITLE_TTX_ON);
                                }
                            }
                        }
                      #endif
                    }
                }
                else
                {
                  #if ENABLE_TTX
                    if (stGenSetting.g_SysSetting.fEnableTTXSubTitle
                        && !MApp_TTX_IsChInfoOn()
                      #if(ENABLE_OSD_SUBTITLE_EXCLUSIVE == ENABLE)
                        &&MApp_Subtitle_GetShowStatus()
                      #endif
                        )
                    {
                    #if(ENABLE_S2)
                        if ((IsDTVInUse()||IsS2InUse())&&MApp_TTX_GetControlMode()==TTX_MODE_NORMAL
                    #else
                        if (IsDTVInUse()&&MApp_TTX_GetControlMode()==TTX_MODE_NORMAL
                    #endif
                          #if (ENABLE_PIP)
                            && ((MApp_Get_PIPMode() == EN_PIP_MODE_OFF))
                          #endif
                           &&(!bIsBlocked||(bIsBlocked && bStopMonitorBlock))&&(enTVRetVal != EXIT_GOTO_INPUTSOURCE))
                        {
                            MApp_TTX_TeletextCommand(TTX_SUBTITLE_TTX_ON);
                        }
                    }
                    else
                  #endif
                    {
                    #if PVR_AND_TTX_DIFF_WITH_MHEG5
                        MApp_TTX_TurnTTXOnOff(FALSE);
                    #endif
                        enTVState = STATE_TV_INIT;
                      #if (SUBTITLE_WITH_OSD == FALSE)
                        enTVRetVal = EXIT_GOTO_SUBTITLE;
                      #endif
                    }
                }
            }
        }
      #endif //ENABLE_SUBTITLE
    #endif //ENABLE_SBTVD_BRAZIL_APP
    #endif //ENABLE_DTV

      #if MHEG5_ENABLE
        if(msAPI_MHEG5_IsMHEGDraw())
        {
            if (SYS_INPUT_SOURCE_TYPE(eWindow) == INPUT_SOURCE_DTV
                && SYS_SCREEN_SAVER_TYPE(eWindow) != EN_SCREENSAVER_NULL)
            {
                SYS_SCREEN_SAVER_TYPE(eWindow) = EN_SCREENSAVER_NULL;
            }
        }
      #endif

        if (SYS_SCREEN_SAVER_TYPE(eWindow) != EN_SCREENSAVER_NULL
            && ( (MApp_ZUI_GetActiveOSD() ==E_OSD_EMPTY )
#if ENABLE_E_POP
            ||   (MApp_ZUI_GetActiveOSD() == E_OSD_EPOP )
#endif
                 )
           )
        {
        #if ENABLE_SBTVD_BRAZIL_APP
          #if (BRAZIL_CC)
            if (MApp_CC_GetInfo(CC_SELECTOR_STATUS_CODE) == STATE_CAPTION_PARSER)
            {
                MApp_CC_StopParser();
                MApp_Dmx_PES_Stop();
            }
          #endif
        #endif

        #if (ATSC_CC == ATV_CC)
            if (MApp_CC_GetInfo(CC_SELECTOR_STATUS_CODE) == STATE_CAPTION_PARSER)
            {
                MApp_CC_StopParser();
            }
        #endif
#if(ENABLE_OSD_SUBTITLE_EXCLUSIVE == ENABLE)
        #if (ENABLE_SUBTITLE)
                    if (( MApp_Subtitle_GetStatus() == STATE_SUBTITLE_DECODING)
                        #if(ENABLE_TTX)
                        ||(MApp_TTX_IsTeletextOn()&&stGenSetting.g_SysSetting.fEnableTTXSubTitle)
                      #endif
                        )
                    {
                        MApp_Subtitle_SetShowStatus(FALSE);
                    }
        #endif
#endif

            if(IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(eWindow))
             #if ENABLE_PVR
                &&((!MApp_PVR_IsPlaybacking())&&(!MApp_PVR_IsRecording()))
             #endif
              )
            {
                MApp_ZUI_ACT_StartupOSD(E_OSD_SCREEN_SAVER);
            }
            else if(IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(eWindow)))
            {
                SYS_SCREEN_SAVER_TYPE(eWindow) = EN_SCREENSAVER_NULL;
            #if 0//( CHAKRA3_AUTO_TEST )
                if (g_AT_bChangeSource)    //for no signal
                {
                    MApp_AT_SendEvent( E_AT_EVENT_CHANGE_SOURCE_NO_SIGNAL, (void*)msAPI_Timer_GetTime0());
                }
            #endif
            }
        }

        //==========================================================================
        //MHEG5 Booting monitor.
        //==========================================================================
    #if (MHEG5_ENABLE)
        if (MApp_MHEG5_DsmccTime_Get() > 0//&&MApp_IsSrcHasSignal(MAIN_WINDOW)
      #if (ENABLE_PIP)
        && ((MApp_Get_PIPMode() == EN_PIP_MODE_OFF))
      #endif
        )
        {
            MApp_MHEG5_BootingMonitor();
        }
        else if ((enFrotEndLockStatus == FRONTEND_LOCK)
                 && (msAPI_MHEG5_checkGoBackMHEG5() == TRUE)
                 /*&& (MApp_ZUI_GetActiveOSD()==E_OSD_EMPTY)*/ //ZUI: (enCurTVWin==DISP_WIN_NONEOSD)
               #if ENABLE_SUBTITLE
                 && ((stGenSetting.g_SysSetting.fEnableSubTitle == false || (u8SubtitleMenuNum == 0))
                 #if CIPLUS_MHEG_1_3
                 || (msAPI_MHEG5_GoMHEGWhenSubtitleOn() !=0)//= 2)
                 #endif
                 )
               #endif
               #if ENABLE_PVR
                 && (!MApp_PVR_IsPlaybacking())
               #endif
               #if (ENABLE_PIP)
                 && ((MApp_Get_PIPMode() == EN_PIP_MODE_OFF))
                #endif
                )
        {
            // No channel change, just go back MHEG5 directly, no need to trigger DSMCC again
            if ((MApp_SI_CheckMHEG5Status() == SI_MHEG5_WITH_VIDEO)
                 || (MApp_SI_CheckMHEG5Status() == SI_MHEG5_DATA_ONLY))
            {
                if (MApp_MHEG5_CheckGoMHEG5Process()==FALSE
                    #if ENABLE_PVR
                    && (!MApp_PVR_IsPlaybacking())
                    #endif
                    #if (ENABLE_PIP) //Do not allow entering MHEG5 when PIP mode is ON
                    && ((MApp_Get_PIPMode() == EN_PIP_MODE_OFF))
                    #endif
                )
                {
                    MApp_MHEG5_SetGoMHEG5Process(TRUE);
                }
            }
            msAPI_MHEG5_SetGoBackMHEG5(false);
        }
    #endif
        //==========================================================================
        //==========================================================================

        u32TVModeWinTimer = msAPI_Timer_GetTime0();
    }
  #if ENABLE_PVR
    else if ((msAPI_Timer_DiffTimeFromNow(u32TVModeWinTimer) > TV_MODE_WINDOW_MONITOR_PERIOD_NOSINGAL) //unit = ms
             && (MApp_PVR_IsPlaybacking() && MApp_PVR_IsRecording()))
    {
      #if ENABLE_TTX

        if (!stGenSetting.g_SysSetting.fEnableTTXSubTitle)
        {
            return ;
        }

        if (UI_Hotkey_Subtitle)
        {
            if ((u8SubtitleMenuNum == gu8TTXSubtitleServiceNum)  && (stGenSetting.g_SysSetting.fEnableTTXSubTitle == FALSE))
            {
                UI_Hotkey_Subtitle=FALSE;
            }

            if ((gu8TTXSubtitleServiceNum == 0) && (stGenSetting.g_SysSetting.fEnableTTXSubTitle == TRUE))
            {
                UI_Hotkey_Subtitle=FALSE;
            }
        }
      #endif

        if (UI_Hotkey_Subtitle == FALSE)
        {
        #if (ENABLE_SUBTITLE)
            if (MApp_TV_SelectSubtileLang()==TRUE)
            {
                enTVState = STATE_TV_INIT;
              #if (SUBTITLE_WITH_OSD == FALSE)
                enTVRetVal = EXIT_GOTO_SUBTITLE;
              #endif
            }
            else
         #endif
            {
              #if ENABLE_DTV
              #if ENABLE_TTX
                U8 Magazine, Page;
                U16 u16Pid;

                if (IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(eWindow))&&MApp_TTX_GetControlMode()==TTX_MODE_NORMAL
                  #if (ENABLE_PIP)
                    && ((MApp_Get_PIPMode() == EN_PIP_MODE_OFF))
                  #endif
                   &&(!bIsBlocked||(bIsBlocked && bStopMonitorBlock))
                   && enTVRetVal != EXIT_GOTO_MENU&&(enTVRetVal != EXIT_GOTO_INPUTSOURCE) &&
                   stGenSetting.g_SysSetting.fEnableTTXSubTitle)
                {
                    if (MApp_TTX_Subtitle_GetDefaultLang(LAST_SECLECT_LANGUAGE/*GET_OSD_MENU_LANGUAGE()*/, &Magazine, &Page, &u16Pid))
                    {
                    #if PVR_AND_TTX_DIFF_WITH_MHEG5
                        MApp_TTX_TurnTTXOnOff(TRUE);
                    #endif
                        MApp_TTX_SetSubtitleTTX_PID(u16Pid);
                        MApp_TTX_SetSubtitlePage(((U16)Magazine<<8) | Page, 0xFFFF);
                        MApp_TTX_TeletextCommand(TTX_SUBTITLE_TTX_ON);
                    }
                }
              #endif
              #endif
            }
        }
        else
        {
        #if ENABLE_DTV
          #if ENABLE_TTX
            if (stGenSetting.g_SysSetting.fEnableTTXSubTitle && !MApp_TTX_IsChInfoOn() )
            {
                if (IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(eWindow))&&MApp_TTX_GetControlMode()==TTX_MODE_NORMAL
                  #if (ENABLE_PIP)
                    && ((MApp_Get_PIPMode() == EN_PIP_MODE_OFF))
                  #endif
                   &&(!bIsBlocked||(bIsBlocked && bStopMonitorBlock))
                   &&  enTVRetVal != EXIT_GOTO_MENU&&(enTVRetVal != EXIT_GOTO_INPUTSOURCE))
                {
                    MApp_TTX_TeletextCommand(TTX_SUBTITLE_TTX_ON);
                }
            }
            else
          #endif
        #endif
            {
                enTVState = STATE_TV_INIT;
              #if ( SUBTITLE_WITH_OSD == FALSE )
                enTVRetVal = EXIT_GOTO_SUBTITLE;
              #endif
            }

        }
    }
  #endif

#if ENABLE_E_POP
        MApp_ZUi_ACT_EpopHander();
#endif
}

#if ENABLE_ATSC
static U16 u16InputValue;

void MApp_TV_Init_NumWinProcDigitKey(void)
{
    u16InputValue = 0;
    u8IdleDigitCount = 0;
    memset(&stVirtualChNum, 0, sizeof(stVirtualChNum));
#if (ONE_PART_CHNO==ENABLE)
    stVirtualChNum.minor_num = INVALID_MINOR_NUMBER;
    stVirtualChNum.fIsOnePartChNum = 1;
#else
    stVirtualChNum.minor_num=INVALID_MINOR_NUMBER;
#endif
    enVirChType2bVerified = MAJOR_CH_NUM;
}

void MApp_TV_NumWinProcDigitKey_ATSC(U8 bKeyValue)
{
    if (MApp_ZUI_GetActiveOSD() != E_OSD_TENKEY_NUMBER)
    {
        MApp_TV_Init_NumWinProcDigitKey();
        MApp_ZUI_ACT_StartupOSD(E_OSD_TENKEY_NUMBER);
    }
    u32NumChannChangeTimer = msAPI_Timer_GetTime0();

    if(bKeyValue == KEY_DASH)
    {
#if ENABLE_ATSC_TTS
        MApp_TTSControlSetInputText(MApp_ZUI_API_GetString(en_str_channel_dash), MApp_UiMenu_u16Strlen(MApp_ZUI_API_GetString(en_str_channel_dash)));
        MApp_TTSControlSetOn(TRUE);
#endif
        if(enVirChType2bVerified==MAJOR_CH_NUM && MApp_ChanProc_GetCurProgIndex()!=INVALID_SERVICE_IDX)
        {
            if(u8IdleDigitCount == 0)
            {
                //set to current major number if there is no any major number input
                stVirtualChNum.major_num = MApp_ChanProc_GetCurChannelPointer()->stVirtualChNum.major_num;
                u8IdleDigitCount = MApp_GetNoOfDigit( (U32)stVirtualChNum.major_num);
            }

            u8MajorNumDigitCount = u8IdleDigitCount;
            u16InputValue = 0;
            u8IdleDigitCount = 0;
            enVirChType2bVerified = MINOR_CH_NUM;
        }
        else //MINOR_CH_NUM
        {
            //invalid input value
           MApp_ZUI_ACT_ShutdownOSD();
        }
    }
    else //KEY_0 ~ KEY_9
    {
#if ENABLE_ATSC_TTS
        MApp_UlongToString((bKeyValue - KEY_0), au8Section, 1);
        U16 *pU16Str = malloc(sizeof(au8Section));
        if (pU16Str != NULL)
        {
            MApp_U8StringToU16String(au8Section, pU16Str, sizeof(au8Section));
            MApp_TTSControlSetInputText(pU16Str, sizeof(au8Section));
            MApp_TTSControlSetOn(TRUE);
            free(pU16Str);
        }
#endif
        u8IdleDigitCount++;
        if(u8IdleDigitCount > MAX_DIGITKEY_NUM)
        {
           MApp_ZUI_ACT_ShutdownOSD();
        }
        else
        {
            u16InputValue = u16InputValue * 10 + (bKeyValue - KEY_0);

            if(enVirChType2bVerified == MAJOR_CH_NUM)
                stVirtualChNum.major_num = u16InputValue;
            else
                stVirtualChNum.minor_num = u16InputValue;
        }
    }
    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_REPAINT_ALL);
    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_RESET_AUTO_CLOSE_TIMER);
}

void MApp_TV_ChannelChangeProc(MS_VIRTUAL_CHANNEL_NUM *pstVirtualChNum, EN_ANT_TYPE enAntennaType)
{
    U16 u16ProgIndex;
    MS_U8 fGoToScan, fValidChNum;

    fValidChNum = TRUE;
    fGoToScan = TRUE;
    //check major number, Air: 2 ~ 69, CATV: 1 ~ 135
    if((pstVirtualChNum->minor_num == 0)||(pstVirtualChNum->minor_num == INVALID_MINOR_NUMBER))
    {
        if(enAntennaType == ANT_AIR)
        {
            if(pstVirtualChNum->major_num<2 || pstVirtualChNum->major_num>69)
                fValidChNum = FALSE;
        }
        else
        {
            if(pstVirtualChNum->major_num<1 || pstVirtualChNum->major_num>135)
            {
                #if (ONE_PART_CHNO==ENABLE)
                fGoToScan = FALSE;
                if(pstVirtualChNum->major_num==0)
                    fValidChNum = FALSE;
                #else
                fValidChNum = FALSE;
                #endif
            }
        }
    }
    else
    {
        //check major number, 1 ~ 1023
        if(pstVirtualChNum->major_num < MIN_MAJOR_NO || pstVirtualChNum->major_num > MAX_MAJOR_NO)
            fValidChNum = FALSE;

        //check minor number, 0 ~ 1023
        if(pstVirtualChNum->minor_num>MAX_MINOR_NO)
            fValidChNum = FALSE;

        fGoToScan = FALSE;
    }

    enTVRetVal = EXIT_GOTO_CHANNELCHANGE;

    //channel number within valid range, go to find program from main list
    if(fValidChNum == TRUE)
    {
        u16ProgIndex = MApp_ChanProc_GetProgIdxByVirChNum(pstVirtualChNum);

        if(u16ProgIndex == INVALID_SERVICE_IDX || stChSetting.astVirtualChInfo[VIR_CHINFO_IDX(u16ProgIndex)].fIsDirCh) //go to manual scan
        {
            if(fGoToScan)
            {
                // enDirecTuneType = DIRECT_TUNE_GOTO_SCAN;
                u8ManualScanStatus = TRUE;
                enTVRetVal = EXIT_GOTO_ATSC_SCAN;
            }
        }
        else if(u16ProgIndex != MApp_ChanProc_GetCurProgIndex()) //go to channel change
        {
            MApp_ChannelChange_DisableChannel(TRUE, MAIN_WINDOW);
            MApp_ChanProc_SetMainListProgIndex(u16ProgIndex);
            MApp_ChanProc_RefreshChannelBuffer(MAIN_LIST);
            MApp_ChannelChange_EnableChannel( MAIN_WINDOW);

            enChannelInfoPageType = TYPE_CHANNEL_BANNER;
            MApp_ZUI_ACT_Startup_ChannelInfo_OSD();
            enTVRetVal = EXIT_NULL;
        }
    }
    enTVState = STATE_TV_INIT;
}

void MApp_TV_MonitorIdleMdoeWindows(void)
{
#if ATSC_READY //ENABLE_INPUT_LOCK
    if ( (g_bInputBlocked)
        && (E_OSD_EMPTY == MApp_ZUI_GetActiveOSD() || EN_MSGBOX_MODE_INPUT_BLOCK != MApp_ZUI_ACT_GetMessageBoxMode())
        && (stGenSetting.g_VChipSetting.u8VChipLockMode)
        && (MApp_Sleep_GetSleepTimerCountDownStatus() == FALSE)
       )
    {
    #if 1//def LOCK_USE_BLACK_VIDEO
        //MApp_MuteAvByLock(E_SCREEN_MUTE_INPUT, TRUE);
        MApp_MuteAvByLock(E_SCREEN_MUTE_BY_UI, TRUE);
    #else
        MApp_MuteAvByLock(TRUE);
    #endif
        // input block
        TV_DBINFO(printf("MSGBOX>> input block\n"));
        MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
        MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_MSGBOX_MODE_INPUT_BLOCK);
        return;
    }
#endif

   // if ((MApp_ZUI_GetActiveOSD() == E_OSD_EMPTY) && g_bInputBlocked)
    //{
    //    MApp_ChannelChange_CheckBlockChannelPW();
    //    return;
    //}

    if(bChListKeyPress && (!g_bInputBlocked))
    {
       if(msAPI_Timer_DiffTimeFromNow(u32ChListKeyPressStartTime) > 300)
        {
            bChListKeyPress = FALSE;
            u32ChListKeyPressStartTime = 0;
            MApp_ChannelChange_EnableChannel(MAIN_WINDOW);
        }
    }

#if ATSC_READY
    if (MApp_Sleep_GetSleepTimerCountDownStatus())
    {
        TV_DBINFO(printf("MSGBOX>>TV show count down\n"));

        if(MApp_ZUI_GetActiveOSD()==E_OSD_MESSAGE_BOX)
        {
             MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_MSGBOX_MODE_SLEEP_COUNTDOWN);
        }
        else
        {
            MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
            MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_MSGBOX_MODE_SLEEP_COUNTDOWN);
        }
    }
    else if(enDirecTuneType != DIRECT_TUNE_NULL)
    {
            if(enDirecTuneType == DIRECT_TUNE_GOTO_SCAN)
            {
                u8ManualScanStatus = TRUE;
                enIdleRetVal = EXIT_TV_TRAN_SCAN;
                enTVState = STATE_TV_INIT;
            }

            else if(enDirecTuneType == DIRECT_TUNE_GOTO_CHANNEL_CHANGE)
            {
                enIdleRetVal = EXIT_TV_TRAN_CHANNELCHANGE;
                enTVState = STATE_TV_INIT;
                #if (ENABLE_AUDIO_ONLY_FULL_FEATURE == 1)
                MApp_DisableAudioOnlyMode();
                MApp_StopAudioOnlyMonitor();
                #endif
             }

            enDirecTuneType = DIRECT_TUNE_NULL;
    }
    else if(E_OSD_MESSAGE_BOX == MApp_ZUI_GetActiveOSD() && EN_MSGBOX_MODE_SLEEP_COUNTDOWN == MApp_ZUI_ACT_GetMessageBoxMode())
    {
        MApp_ZUI_ACT_ShutdownOSD();
    }
    else
#endif
    if (MApp_ZUI_GetActiveOSD() == E_OSD_TENKEY_NUMBER) //ZUI: enCurTVWin == DISP_WIN_TENKEY_NUMBER)
    {
        //monitor number window
        if ((u32NumChannChangeTimer > 0) && msAPI_Timer_DiffTimeFromNow(u32NumChannChangeTimer) > 3000) //unit = ms
        {
            MApp_TV_ChannelChangeProc(&stVirtualChNum, (EN_ANT_TYPE)ANT_TYPE);
            return;
        }
    }
    else if (E_OSD_SCREEN_SAVER == MApp_ZUI_GetActiveOSD() && SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) == EN_SCREENSAVER_NOSIGNAL)
    {
        if ((IsATVInUse() && msAPI_AVD_IsSyncLocked()) || (IsDTVInUse() && MApp_GetSignalLockStatus()) )
        {
            MApp_ZUI_ACT_ShutdownOSD();
            SAVR_DBG(printf("\r\n--->MSG NULL"));
            SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) = EN_SCREENSAVER_NULL;
        }
    }
    else if(((E_OSD_SCREEN_SAVER == MApp_ZUI_GetActiveOSD())&&(SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) == EN_SCREENSAVER_BLOCKRATING))
        //||(E_OSD_MESSAGE_BOX == MApp_ZUI_GetActiveOSD())
        )
    {
        if (MApp_VChip_GetCurVChipBlockStatus())
        {
            if (MApp_VChip_GetRatingUpdateStatus())
            {
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_REPAINT_ALL);
            }
            SAVR_DBG(printf("\r\n--->MSG RATING"));
            SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) = EN_SCREENSAVER_BLOCKRATING;
        }
        else if (MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_QUERY_IS_POWER_OFF_COUNTDOWN_MSG_BOX))
        {
            MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_REPAINT_ALL);
        }
    #if ENABLE_ATSC
        else if(g_bInputBlocked && (SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) == EN_SCREENSAVER_NULL))
        {

        }
    #endif
        else
        {
            MApp_ZUI_ACT_ShutdownOSD();
        }

        if ( ((IsDTVInUse() && (!MApp_GetSignalLockStatus()) ) ||(IsATVInUse() && (!msAPI_AVD_IsSyncLocked()) ))
            && (MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_QUERY_IS_POWER_OFF_COUNTDOWN_MSG_BOX) == FALSE)
            )
        {
            // no signal
            TV_DBINFO(printf("MSGBOX>> no signal\n"));
            SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) = EN_SCREENSAVER_NOSIGNAL;
            MApp_ZUI_ACT_StartupOSD(E_OSD_SCREEN_SAVER);
            //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_MSGBOX_MODE_NO_SIGNAL);
            SAVR_DBG(printf("\r\n--->MSG NOSIGNAL"));
        }

    }
    else if (E_OSD_SCREEN_SAVER == MApp_ZUI_GetActiveOSD() && SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) == EN_SCREENSAVER_AUDIOONLY)
    {
        if (IsDTVInUse() && (!MApp_GetSignalLockStatus()) )
        {
            SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) = EN_SCREENSAVER_NOSIGNAL;
            MApp_ZUI_ACT_StartupOSD(E_OSD_SCREEN_SAVER);
            //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_MSGBOX_MODE_NO_SIGNAL);
            SAVR_DBG(printf("\r\n--->MSG NOSIGNAL"));
        }
    }
#if ATSC_READY
    else if (E_OSD_SCREEN_SAVER == MApp_ZUI_GetActiveOSD() && EN_MSGBOX_MODE_UNSUPPORT_MODE == MApp_ZUI_ACT_GetMessageBoxMode())
    {
        if(MApp_PCMode_GetCurrentState(MAIN_WINDOW) == E_PCMODE_STABLE_SUPPORT_MODE)  //(!g_bUnsupportMode)
        {
            MApp_ZUI_ACT_ShutdownOSD();
        }
        else if(MApp_PCMode_GetCurrentState(MAIN_WINDOW) == E_PCMODE_NOSYNC)     //(msAPI_Scaler_SyncLossFlag() && g_bInputTimingStable)
        {
            MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_MSGBOX_MODE_NO_SIGNAL);
        }
    }
#endif
    else if(E_OSD_MESSAGE_BOX == MApp_ZUI_GetActiveOSD() && MApp_ZUI_API_IsWindowVisible(HWND_MSGBOX_PASSWORD_PANE))
    {
        if(!MApp_ChanProc_GetNumOfServices(MAIN_LIST) && (IsDTVInUse() || IsATVInUse()))
        {
            // no database
            TV_DBINFO(printf("MSGBOX>> no database\n"));
            SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) = EN_SCREENSAVER_NODATABASE;
            MApp_ZUI_ACT_StartupOSD(E_OSD_SCREEN_SAVER);
            //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_MSGBOX_MODE_NO_DATABASE);
            SAVR_DBG(printf("\r\n--->MSG NODATA"));
        }
        #ifndef CHANNEL_HIDE_AS_SKIP_ONLY
        else if ((stChSetting.u16TotalHideSrvNum == stChSetting.u16MainListSrvNum) && (IsDTVInUse() || IsATVInUse()))
        {
            // no show program
            TV_DBINFO(printf("MSGBOX>> no show program\n"));
            SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) = EN_SCREENSAVER_NO_SHOW_PROGRAM;
            MApp_ZUI_ACT_StartupOSD(E_OSD_SCREEN_SAVER);
            //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_MSGBOX_MODE_NO_SHOW_PROGRAM);
            SAVR_DBG(printf("\r\n--->MSG NOSHOW"));
        }
        #endif
        else if( (IsDTVInUse() && (!MApp_GetSignalLockStatus()) ) ||
                (IsATVInUse() && (!msAPI_AVD_IsSyncLocked()) ))
        {
            // no signal
            if(msAPI_Timer_DiffTimeFromNow(u32TVModeWinTimer) > TV_MODE_WINDOW_MONITOR_PERIOD) //unit = ms
            {
                if(!IS_HIDE_CH_ATSC(MApp_ChanProc_GetCurProgIndex()))
                {
                    TV_DBINFO(printf("MSGBOX>> no signal\n"));
                    SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) = EN_SCREENSAVER_NOSIGNAL;
                    MApp_ZUI_ACT_StartupOSD(E_OSD_SCREEN_SAVER);
                    //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_MSGBOX_MODE_NO_SIGNAL);
                    SAVR_DBG(printf("\r\n--->MSG NOSIGNAL"));
                }
            }
        }

    }
    else if(E_OSD_EMPTY == MApp_ZUI_GetActiveOSD())
    {
        if(!MApp_ChanProc_GetNumOfServices(MAIN_LIST) && (IsDTVInUse() || IsATVInUse()))
        {
            // no database
            TV_DBINFO(printf("MSGBOX>> no database\n"));
            SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) = EN_SCREENSAVER_NODATABASE;
            MApp_ZUI_ACT_StartupOSD(E_OSD_SCREEN_SAVER);
            //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_MSGBOX_MODE_NO_DATABASE);
            SAVR_DBG(printf("\r\n--->MSG NODATA"));
        }
        #ifndef CHANNEL_HIDE_AS_SKIP_ONLY
        else if ((stChSetting.u16TotalHideSrvNum == stChSetting.u16MainListSrvNum) && (IsDTVInUse() || IsATVInUse()))
        {
            // no show program
            TV_DBINFO(printf("MSGBOX>> no show program\n"));
            SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) = EN_SCREENSAVER_NO_SHOW_PROGRAM;
            MApp_ZUI_ACT_StartupOSD(E_OSD_SCREEN_SAVER);
            //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_MSGBOX_MODE_NO_SHOW_PROGRAM);
            SAVR_DBG(printf("\r\n--->MSG NOSHOW"));
        }
        #endif
        else if( (IsDTVInUse() && (!MApp_GetSignalLockStatus()) ) ||
                (IsATVInUse() && (!msAPI_AVD_IsSyncLocked()) ))
        {
            // no signal
            if(msAPI_Timer_DiffTimeFromNow(u32TVModeWinTimer) > TV_MODE_WINDOW_MONITOR_PERIOD) //unit = ms
            {
                if(!IS_HIDE_CH_ATSC(MApp_ChanProc_GetCurProgIndex()))
                {
                    TV_DBINFO(printf("MSGBOX>> no signal\n"));
                    SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) = EN_SCREENSAVER_NOSIGNAL;
                    MApp_ZUI_ACT_StartupOSD(E_OSD_SCREEN_SAVER);
                    //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_MSGBOX_MODE_NO_SIGNAL);
                    SAVR_DBG(printf("\r\n--->MSG NOSIGNAL"));
                }
            }
        }
        else if ( g_bInputBlocked)
        {
            MApp_ChannelChange_CheckBlockChannelPW();
        }
        else if(MApp_VChip_GetCurVChipBlockStatus())
        {
            // parental blocked
            TV_DBINFO(printf("MSGBOX>> parental blocked\n"));
            MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
            MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_MSGBOX_MODE_PARENTAL_BLOCK);
            SAVR_DBG(printf("\r\n--->MSG RATING"));
            SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) = EN_SCREENSAVER_BLOCKRATING;
        }
        else if( (IsDTVInUse())
                &&((MApp_ChanProc_GetCurChannelPointer()->u16VideoPid==0) /*|| (MApp_ChanProc_GetCurChannelPointer()->u16ScrambleChStatus && SCRAMBLE_VIDEO)*/)
                && (MApp_ChanProc_GetCurChannelPointer()->astSoundTrack[0].u16AudioPid !=0))
        {
            // radio channel

            TV_DBINFO(printf("MSGBOX>> radio channel\n"));
            SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) = EN_SCREENSAVER_AUDIOONLY;
            MApp_ZUI_ACT_StartupOSD(E_OSD_SCREEN_SAVER);
            //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_MSGBOX_MODE_RADIO_CHANNEL);
            SAVR_DBG(printf("\r\n--->MSG AUDONLY"));

            if(!MApp_Aud_GetMuteStatus())
            {
                TV_DBINFO(printf("Audio>> radio channel Audio ON\n"));
                msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYSYNC_MUTEOFF, E_AUDIOMUTESOURCE_ATV);
                msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_PERMANENT_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                MApi_AUDIO_SPDIF_SetMute(FALSE);
            }
        }
        else if(fEnableClosedCaptionFunc /*&& MApp_UiMenuFunc_IsCCEnable()*/)
        {
            #if ATSC_READY
            #if (ENABLE_AUDIO_ONLY_CUSTOMERMODE == 1)
            if ((g_AudioOnly == AUDIO_ONLY_ON) && (!fEnableAudioOnlyFunc))//for cus01x
            {
               ;
            }
            else
            #endif
            #endif
            {
                enTVRetVal = EXIT_GOTO_CLOSEDCAPTION;
                enTVState = STATE_TV_INIT;
            }

        }
        else if ( (IsDTVInUse() && (MApp_GetSignalLockStatus()) ) ||
                (IsATVInUse() && (msAPI_AVD_IsSyncLocked()) ))
        {
            if(SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) != EN_SCREENSAVER_NULL)
            {
                SAVR_DBG(printf("\r\n--->MSG NULL !"));
                SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) = EN_SCREENSAVER_NULL;
            }
            u32TVModeWinTimer = msAPI_Timer_GetTime0();
        }
    }

}
#endif

/******************************************************************************/
// Teletext key handler
#if ENABLE_TTX

extern U32 g_u32MonitorTTXClockTimer;

static BOOL MApp_TTX_Idle_ProcessUserInput(void)
{
    BOOL isNeedHandledByUserInput = FALSE;

    if (MApp_TTX_GetControlMode()!= TTX_MODE_NORMAL)
    {
        if (u8KeyCode == KEY_CLOCK && MApp_TTX_GetControlMode()==TTX_MODE_CLOCK)
        {
            u8KeyCode = KEY_NULL;
        }

        if (u8KeyCode != KEY_NULL)
        {
            if (MApp_TTX_GetControlMode()==TTX_MODE_SUBTITLE)
            {
                switch (u8KeyCode)
                {
                        #if (ENABLE_PIP)
                    case KEY_PIP:
                        if (IsPIPSupported())
                        {
                            MApp_TTX_TeletextCommand(TTX_TV);
                            MApp_ZUI_ACT_ExecuteMenuItemAction(EN_EXE_INC_PIPMODE);
                        }
                        u8KeyCode = KEY_NULL;
                        break;
                        #endif

                    #if 0
                    case KEY_INFO:
                    case KEY_SELECT:
                        MApp_TTX_TeletextCommand(TTX_TV);
                        MApp_TTX_SetChInfoOnOff(TRUE);
                        break;
                    #endif

                    case KEY_VOLUME_PLUS:
                    case KEY_VOLUME_MINUS:
                    {
                        MApp_ZUI_ACT_StartupOSD(E_OSD_AUDIO_VOLUME);
                        MApp_TV_ProcessAudioVolumeKey(u8KeyCode);
                        u8KeyCode = KEY_NULL;
                        break;
                    }
                    case KEY_SUBTITLE:
                    #if(ENABLE_S2)
                        if (IsDTVInUse()||IsS2InUse())
                    #else
                        if (IsDTVInUse())
                    #endif
                        {
                            //MApp_TTX_TeletextCommand(TTX_TV);
                            isNeedHandledByUserInput = TRUE;
                        }
                        else
                        {
                                #if (ENABLE_PIP)
                                if ((MApp_Get_PIPMode() == EN_PIP_MODE_OFF))
                                #endif
                                {

                                    MApp_TTX_TeletextCommand(TTX_SUBTITLE_NAVIGATION_MODE);  //open the next subtitle
                                }
                            u8KeyCode = KEY_NULL;
                        }
                        break;
                    case KEY_EXIT:
                        {
                            if(IsATVInUse() || IsAVInUse())
                            {
                                MApp_TTX_TeletextCommand(TTX_TV);
                            }
                            u8KeyCode = KEY_NULL;
                        }
                        break;
                    case KEY_TTX:
                    case KEY_CLOCK:
                        MApp_TTX_TeletextCommand(TTX_TV);
                        break;
                    case KEY_RED:
                    case KEY_GREEN:
                    case KEY_YELLOW:
                    case KEY_BLUE:
                    case KEY_BACK:
                    case KEY_UP:
                    case KEY_DOWN:
                    case KEY_LEFT:
                    case KEY_RIGHT:
                    case KEY_UPDATE:
                    case DSC_KEY_MULTI_PIP:
                    case KEY_TIME:
                    case KEY_HOLD:
                    case KEY_REVEAL:
                    case KEY_SIZE:
                    case KEY_TTX_MODE:
                    {
                        if (!IsAnyTVSourceInUse())
                        {
                            u8KeyCode = KEY_NULL;
                            break;
                        }
                        //TVSource go to default
                    }
                    default:
                    {
                        isNeedHandledByUserInput = TRUE;
                        break;
                    }
                }

            }
            else
            {
                MApp_TTX_TeletextCommand(TTX_TV);
                u8KeyCode = KEY_NULL;
            }
        }
    }
    else
    {
        switch (u8KeyCode)
        {
                // add Key in TTX mode
            case KEY_POWER:
                MApp_TTX_TeletextCommand(TTX_TV);
                enTVState = STATE_TV_INIT;
                enTVRetVal = EXIT_GOTO_STANDBY;
                u8KeyCode = KEY_NULL;
                break;

                // add Key in TTX mode
            case KEY_VOLUME_PLUS:
                if ( stGenSetting.g_SoundSetting.Volume < MAX_NUM_OF_VOL_LEVEL )
                {
                    stGenSetting.g_SoundSetting.Volume++;
                    msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, stGenSetting.g_SoundSetting.Volume, 0);
                }
                msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYUSER_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                break;

                // add Key in TTX mode
            case KEY_VOLUME_MINUS:
                if ( stGenSetting.g_SoundSetting.Volume > 0 )
                {
                    stGenSetting.g_SoundSetting.Volume--;
                    msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, stGenSetting.g_SoundSetting.Volume, 0);
                }
                msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYUSER_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                break;
//ZUI_TODO: #if(0)
                // add key in TTX mode
            case KEY_MUTE:
            {
                BOOLEAN bIsAudioMuted;
                bIsAudioMuted = msAPI_AUD_IsAudioMutedByUser();
                if (bIsAudioMuted == FALSE)
                    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYUSER_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                else
                    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYUSER_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
            }
            break;
//ZUI_TODO: #endif
            case KEY_1:
            case KEY_2:
            case KEY_3:
            case KEY_4:
            case KEY_5:
            case KEY_6:
            case KEY_7:
            case KEY_8:
            case KEY_9:
            case KEY_0:
                MApp_TTX_TeletextCommand((TELETEXT_COMMAND)(u8KeyCode - KEY_0));
                break;
            case KEY_TTX:
                MApp_TTX_TeletextCommand(TTX_TEXT);
                break;
            case KEY_EXIT:
            case KEY_INPUT_SOURCE:
                 MApp_TTX_TeletextCommand(TTX_TV);
                //ZUI_TODO: g_u8MenuPageIndex = MENU_ROOT;
                break;

        #if ENABLE_TTX_ACI
            case KEY_UP:    // when multi-package, users can use key-up, key-down, and key-ok, to select what they want
                MApp_TTX_TeletextCommand(TTX_UP);
                break;

            case KEY_DOWN:  // when multi-package, users can use key-up, key-down, and key-ok, to select what they want
                MApp_TTX_TeletextCommand(TTX_DOWN);
                break;

            case KEY_SELECT:    // when multi-package, users can use key-up, key-down, and key-ok, to select what they want
                MApp_TTX_TeletextCommand(TTX_OK);
                break;
        #endif

            case KEY_PAGE_UP:
                MApp_TTX_TeletextCommand(TTX_PAGE_UP);
                break;

            case KEY_PAGE_DOWN:
                MApp_TTX_TeletextCommand(TTX_PAGE_DOWN);
                break;

            case KEY_LEFT:
                MApp_TTX_TeletextCommand(TTX_PAGE_LEFT);
                break;

            case KEY_RIGHT:
                MApp_TTX_TeletextCommand(TTX_PAGE_RIGHT);
                break;

            case KEY_RED:
                MApp_TTX_TeletextCommand(TTX_RED);
                break;

            case KEY_GREEN:
                MApp_TTX_TeletextCommand(TTX_GREEN);
                break;

            case KEY_YELLOW:
                MApp_TTX_TeletextCommand(TTX_YELLOW);
                break;

            case KEY_BLUE:
                MApp_TTX_TeletextCommand(TTX_CYAN);
                break;

            case KEY_SIZE:
                MApp_TTX_TeletextCommand(TTX_SIZE);
                break;

            case KEY_MIX:
                MApp_TTX_TeletextCommand(TTX_MIX);
                break;

            case KEY_INDEX:
                MApp_TTX_TeletextCommand(TTX_INDEX);
                break;

            case KEY_HOLD:
                MApp_TTX_TeletextCommand(TTX_HOLD);
                break;

            case KEY_UPDATE:
                MApp_TTX_TeletextCommand(TTX_UPDATE);
                break;

            case KEY_REVEAL:
                MApp_TTX_TeletextCommand(TTX_REVEAL);
                break;

            case KEY_CHANNEL_LIST: // list
                MApp_TTX_TeletextCommand(TTX_LIST);
                break;

            case KEY_SUBTITLE:
                MApp_TTX_TeletextCommand(TTX_SUBPAGE);
                break;

        #if (ENABLE_PIP)
            case KEY_PIP:
                if (IsPIPSupported())
                {
                    MApp_TTX_TeletextCommand(TTX_TV);
                    MApp_ZUI_ACT_ExecuteMenuItemAction(EN_EXE_INC_PIPMODE);
                }
                break;
        #endif

            default:
                break;
        }

        u8KeyCode = KEY_NULL;
    }

    return isNeedHandledByUserInput;
}
#endif  // ENABLE_TTX

/******************************************************************************/

typedef struct
{
    U8 u8Key;
    EN_OSD_WNDEXEACTION_ENUM action;
} KEYEVENT_IDLE;

static BOOLEAN _MApp_TV_ProcessKeyEventIdleTable(U8 key, KEYEVENT_IDLE * keyevent)
{
    BOOLEAN handled = FALSE;
    while (keyevent->u8Key != KEY_NULL)
    {
        if (keyevent->u8Key == key)
        {
            handled = MApp_ZUI_ACT_ExecuteWndAction(keyevent->action);
            //we can allow multiple actions... depend on the last one action..
        }
        keyevent++;
    }
    return handled;
}

/******************************************************************************/

BOOLEAN MApp_TV_ProcessAudioVolumeKey(U8 key)
{
    static  KEYEVENT_IDLE code _key_event[] =
    {
        { KEY_COUNTDOWN_EXIT_TT_SUBTITLE, EN_EXE_CLOSE_CURRENT_OSD },
        { KEY_EPGTIMER_COUNTDOWN, EN_EXE_CLOSE_CURRENT_OSD },
        { KEY_EXIT, EN_EXE_CLOSE_CURRENT_OSD },
        { KEY_POWER, EN_EXE_POWEROFF },
        { KEY_SELECT, EN_EXE_CLOSE_CURRENT_OSD},
        { KEY_VOLUME_PLUS, EN_EXE_INC_AUDIO_VOLUME },
        { KEY_VOLUME_MINUS, EN_EXE_DEC_AUDIO_VOLUME },
        { KEY_NULL, EN_EXE_ACTION_NULL },
    };

    if (key == KEY_NULL)
        return TRUE;

    //reset timer if any key
    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_RESET_AUTO_CLOSE_TIMER);

    return _MApp_TV_ProcessKeyEventIdleTable(key,(KEYEVENT_IDLE *) _key_event);

}

/******************************************************************************/

BOOLEAN MApp_TV_ProcessHotkeyOptionKey(U8 key)
{
    static KEYEVENT_IDLE code _key_event[] =
    {
        { KEY_COUNTDOWN_EXIT_TT_SUBTITLE, EN_EXE_CLOSE_CURRENT_OSD },
        { KEY_EPGTIMER_COUNTDOWN, EN_EXE_CLOSE_CURRENT_OSD },
        { KEY_EXIT, EN_EXE_CLOSE_CURRENT_OSD },
        { KEY_POWER, EN_EXE_POWEROFF },
        { KEY_SELECT, EN_EXE_CLOSE_CURRENT_OSD},
        { KEY_SLEEP, EN_EXE_INC_SLEEP_HOTKEY_OPTION},
        { KEY_SLEEP, EN_EXE_SHOW_SLEEP_HOTKEY}, //after inc action
        { KEY_LEFT, EN_EXE_DEC_SLEEP_HOTKEY_OPTION},
        { KEY_RIGHT, EN_EXE_INC_SLEEP_HOTKEY_OPTION},
        { KEY_REVEAL, EN_EXE_INC_PICTURE_HOTKEY_OPTION},
        { KEY_REVEAL, EN_EXE_SHOW_PICTURE_HOTKEY}, //after inc action
        { KEY_LEFT, EN_EXE_DEC_PICTURE_HOTKEY_OPTION},
        { KEY_RIGHT, EN_EXE_INC_PICTURE_HOTKEY_OPTION},
        #ifdef sAddIRPictureKey
        { KEY_PICTURE, EN_EXE_INC_PICTURE_HOTKEY_OPTION},
        { KEY_PICTURE, EN_EXE_SHOW_PICTURE_HOTKEY}, //after inc action        
        { KEY_LEFT, EN_EXE_DEC_PICTURE_HOTKEY_OPTION},
        { KEY_RIGHT, EN_EXE_INC_PICTURE_HOTKEY_OPTION},        
        #else
        { KEY_PICTURE, EN_EXE_INC_PIP_HOTKEY_OPTION},
        { KEY_PICTURE, EN_EXE_SHOW_PIP_HOTKEY}, //after inc action
        { KEY_LEFT, EN_EXE_DEC_PIP_HOTKEY_OPTION},
        { KEY_RIGHT, EN_EXE_INC_PIP_HOTKEY_OPTION},        
        #endif
        { KEY_AUDIO, EN_EXE_INC_AUDIO_HOTKEY_OPTION},
        { KEY_AUDIO, EN_EXE_SHOW_AUDIO_HOTKEY}, //after inc action
        { KEY_LEFT, EN_EXE_DEC_AUDIO_HOTKEY_OPTION},
        { KEY_RIGHT, EN_EXE_INC_AUDIO_HOTKEY_OPTION},
        { KEY_ZOOM, EN_EXE_INC_SCALE_HOTKEY_OPTION},
        { KEY_ZOOM, EN_EXE_SHOW_SCALE_HOTKEY}, //after inc action
        { KEY_LEFT, EN_EXE_ZOOM_ARROW_LEFT}, //EN_EXE_DEC_SCALE_HOTKEY_OPTION},
        { KEY_RIGHT, EN_EXE_ZOOM_ARROW_RIGHT}, //EN_EXE_INC_SCALE_HOTKEY_OPTION},
        { KEY_UP, EN_EXE_ZOOM_ARROW_UP},
        { KEY_DOWN, EN_EXE_ZOOM_ARROW_DOWN},
        { DSC_KEY_ARC16X9, EN_EXE_SET_DSC_KEY_ARC16X9},
        { DSC_KEY_ARC4X3, EN_EXE_SET_DSC_KEY_ARC4X3},
        { DSC_KEY_ARCZOOM, EN_EXE_SET_DSC_KEY_ARCZOOM},
        { KEY_MTS, EN_EXE_INC_ATV_MTS_HOTKEY_OPTION},
        { KEY_MTS, EN_EXE_SHOW_ATV_MTS_HOTKEY},
        { KEY_LEFT, EN_EXE_DEC_ATV_MTS_HOTKEY_OPTION},
        { KEY_RIGHT, EN_EXE_INC_ATV_MTS_HOTKEY_OPTION},
        { KEY_FREEZE, EN_EXE_ONOFF_FREEZE_HOTKEY_OPTION},
        { KEY_FREEZE, EN_EXE_SHOW_FREEZE_HOTKEY}, //after inc action
        { KEY_CC, EN_EXE_INC_CC_HOTKEY_OPTION},
        { KEY_CC, EN_EXE_SHOW_CC_HOTKEY}, //after inc action
        { KEY_NULL, EN_EXE_ACTION_NULL },
    };

    if (key == KEY_NULL)
        return TRUE;

    //reset timer if any key
    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_RESET_AUTO_CLOSE_TIMER);

    return _MApp_TV_ProcessKeyEventIdleTable(key, (KEYEVENT_IDLE *)_key_event);
}


/******************************************************************************/

BOOLEAN MApp_TV_ProcessMessageBoxKey(U8 key)
{
    static KEYEVENT_IDLE code _key_event[] =
    {
        { KEY_COUNTDOWN_EXIT_TT_SUBTITLE, EN_EXE_CLOSE_CURRENT_OSD },
        { KEY_EPGTIMER_COUNTDOWN, EN_EXE_CLOSE_CURRENT_OSD },
        { KEY_EXIT, EN_EXE_CLOSE_CURRENT_OSD },
        { KEY_POWER, EN_EXE_POWEROFF },
        { KEY_SELECT, EN_EXE_CLOSE_CURRENT_OSD},
        { KEY_NULL, EN_EXE_ACTION_NULL },
    };

    if (key == KEY_NULL)
        return TRUE;

    //reset timer if any key
    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_RESET_AUTO_CLOSE_TIMER);

    //note: special case: for count down dialog
    if (MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_QUERY_IS_POWER_OFF_COUNTDOWN_MSG_BOX))
    {
        if (enIndicateTimerSource == TS_TYPE_SLEEPTIMER)
        {
            //any key is close and reset sleep....
            key = KEY_EXIT;

            MApp_Sleep_SetCurrentSleepTime(STATE_SLEEP_OFF);
            enIndicateTimerSource = TS_TYPE_NONE;
        }
        else if (enIndicateTimerSource  ==TS_TYPE_OFFTIMER )
        {
            if (key != KEY_POWER) //turn off directly
            {
                MApp_Sleep_TransitOffTime();
                key = KEY_SELECT; //for close window by any key
            }
        }
    }
    else if ( (key >= KEY_0 && key <= KEY_9) || key == KEY_SELECT
              || key == KEY_UP || key == KEY_DOWN
              || key == KEY_LEFT || key == KEY_RIGHT)
    {
        MApp_ZUI_ProcessKey(key);
        return TRUE;
    }

    return _MApp_TV_ProcessKeyEventIdleTable(key, (KEYEVENT_IDLE *)_key_event);

}


/******************************************************************************/

BOOLEAN MApp_TV_ProcessChannelInfoKey(U8 key)
{
    static  KEYEVENT_IDLE code _key_event[] =
    {
        { KEY_COUNTDOWN_EXIT_TT_SUBTITLE, EN_EXE_CLOSE_CURRENT_OSD },
        { KEY_EPGTIMER_COUNTDOWN, EN_EXE_CLOSE_CURRENT_OSD },
        { KEY_INFO, EN_EXE_CLOSE_CURRENT_OSD },
        { KEY_EXIT, EN_EXE_CLOSE_CURRENT_OSD },
        { KEY_POWER, EN_EXE_POWEROFF },
        { KEY_SELECT, EN_EXE_CLOSE_CURRENT_OSD},
        { KEY_NULL, EN_EXE_ACTION_NULL },
    };

    if (key == KEY_NULL)
        return TRUE;

    if ((u8IsBriefChInfo == TRUE)&&((key == KEY_UP)||(key == KEY_DOWN)||(key == KEY_LEFT)||(key == KEY_RIGHT)))
        return TRUE;

    //reset timer if any key
    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_RESET_AUTO_CLOSE_TIMER);

    switch (key)
    {
        case KEY_UP:
        #if(ENABLE_S2)
            if ( IsDTVInUse() || IsS2InUse())
        #else
            if (IsDTVInUse())
        #endif
            {
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_REPAINT_CH_INFO_SCROLL);
            }
            return TRUE;

        case KEY_DOWN:
        #if(ENABLE_S2)
            if ( IsDTVInUse() || IsS2InUse())
        #else
            if (IsDTVInUse())
        #endif
            {
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_REPAINT_CH_INFO_SCROLL);
            }
            return TRUE;

        case KEY_LEFT:
        #if(ENABLE_S2)
            if ( IsDTVInUse() || IsS2InUse())
        #else
            if (IsDTVInUse())
        #endif
            {
                bNextEvent = FALSE;
                u8InfoScrollLineCount = 0;
                u8InfoScrollLineCount_Pre = 0;
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_REPAINT_CH_INFO);
            }
            return TRUE;

        case KEY_RIGHT:
        #if(ENABLE_S2)
            if ( IsDTVInUse() || IsS2InUse())
        #else
            if (IsDTVInUse())
        #endif
            {
                bNextEvent = TRUE;
                u8InfoScrollLineCount = 0;
                u8InfoScrollLineCount_Pre = 0;
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_REPAINT_CH_INFO);
            }
            return TRUE;
    }

    return _MApp_TV_ProcessKeyEventIdleTable(key, (KEYEVENT_IDLE *)_key_event);
}

/******************************************************************************/
/*
BOOLEAN MApp_TV_ProcessEPGKey(U8 key)
{
    static  KEYEVENT_IDLE code _key_event[] =
    {
        { KEY_COUNTDOWN_EXIT_TT_SUBTITLE, EN_EXE_CLOSE_CURRENT_OSD },
        { KEY_EPGTIMER_COUNTDOWN, EN_EXE_EPG_TIMER_COUNTDOWN_UPDATE },
        { KEY_INFO, EN_EXE_CLOSE_CURRENT_OSD },
        { KEY_EXIT, EN_EXE_CLOSE_CURRENT_OSD },
        { KEY_POWER, EN_EXE_POWEROFF },
        { KEY_SELECT, EN_EXE_CLOSE_CURRENT_OSD},
        { KEY_LEFT, EN_EXE_NAV_KEY_LEFT},
        { KEY_RIGHT, EN_EXE_NAV_KEY_RIGHT},
        { KEY_NULL, EN_EXE_ACTION_NULL },
    };

    if (key == KEY_NULL)
        return TRUE;

    //reset timer if any key
    //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_RESET_AUTO_CLOSE_TIMER);

    switch(key)
    {
        case KEY_SELECT:
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_EPG_TIMER_COUNTDOWN_BTN);
            return TRUE;
    }

    return _MApp_TV_ProcessKeyEventIdleTable(key, (KEYEVENT_IDLE *)_key_event);
}
*/
/******************************************************************************/

#if (BRAZIL_CC == 1) && (CC_TESTING_SOURCE != 0)
static U8 u8TestCC=0;
#endif
void MApp_TV_ProcessUserInput(void)
{
    U16 u16TotalProNum;
#if ENABLE_DTV
    #if NORDIG_FUNC //for Nordig Spec v2.0
        u16TotalProNum = msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
    #else
        u16TotalProNum = msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
    #endif
#else
    u16TotalProNum=0;
#endif
#if (DTG_FREEVIEW_STANDBY)
    if (FreeView_Standby) //only Power key can process in Freeview standby mode
    {
        if (u8KeyCode != KEY_POWER)
        {
            u8KeyCode = KEY_NULL;
        }
    }
#endif

#if ENABLE_EPGTIMER_RECORDER_TURNOFFPANEL
    if(MApp_GetActiveStandbyMode())
    {
        if (u8KeyCode != KEY_POWER)
        {
            u8KeyCode = KEY_NULL;
        }
    }
#endif

  #if ENABLE_CI
    #if ENABLE_CI_PLUS
    if(TRUE == msAPI_CI_CU_GetState())
    {
        u8KeyCode = KEY_NULL;
    }
    #endif
    if ( msAPI_CI_GetCIMessageType() == EN_CIMSG_LOAD_NONE )
    {
        switch ( u8KeyCode )
        {
            case KEY_POWER:
            case DSC_KEY_PWROFF:
            case KEY_VOLUME_PLUS:
            case KEY_VOLUME_MINUS:
                break;
            default:
                u8KeyCode = KEY_NULL;
                break;
        }
    }
  #endif
    //2007/12/14: in some osd, we don't switch to other state, but we direct key event to ZUI
    //2008/3/27: handle keys here! don't handle these keys in MApp_ZUI_ACTxxx.c
    switch ( MApp_ZUI_GetActiveOSD()  )
    {
        case E_OSD_HOTKEY_OPTION:
        		#ifdef sAddIRPictureKey
                if (MApp_TV_ProcessHotkeyOptionKey(u8KeyCode))
                    u8KeyCode = KEY_NULL;        		
        		#else
            if(u8KeyCode == KEY_PICTURE
                #if (ENABLE_PIP)
                && (!IsPIPSupported())
                #endif
                )     //PIP hotkey
            {
                u8KeyCode = KEY_NULL;
            }
            else
            {
                if (MApp_TV_ProcessHotkeyOptionKey(u8KeyCode))
                    u8KeyCode = KEY_NULL;
            }
            #endif
            break;
        case E_OSD_AUDIO_VOLUME:
            if (MApp_TV_ProcessAudioVolumeKey(u8KeyCode))
                u8KeyCode = KEY_NULL;
            break;
        case E_OSD_MESSAGE_BOX:
            if (MApp_TV_ProcessMessageBoxKey(u8KeyCode))
            {//if u8KeyCode == KEY_POWER, it has return FALSE
                u8KeyCode = KEY_NULL;
            }
            break;
        case E_OSD_CHANNEL_INFO:
            if (MApp_TV_ProcessChannelInfoKey(u8KeyCode))
                u8KeyCode = KEY_NULL;
            break;
      #if (ENABLE_DTV_EPG && ENABLE_DVB) //ENABLE_DTV
        case E_OSD_EPG:
            if (MApp_TV_ProcessEpgCountDownKey(u8KeyCode))
                u8KeyCode = KEY_NULL;
            break;
      #endif
            /*
                    case E_OSD_EPG:
                        if (MApp_TV_ProcessEPGKey(u8KeyCode))
                            u8KeyCode = KEY_NULL;
                        break;
                        */
        default:
            break;
    }

  #if ENABLE_PVR
#if(ENABLE_S2)
    if (IsDTVInUse()||IsS2InUse())
#else
    if (IsDTVInUse())
#endif
    {
        if ((bIsBlocked == FALSE) || (bStopMonitorBlock == TRUE))   //cannot operate PVR in block program
        {
            switch (MApp_UiPvr_KeyProcessor())
            {
                case EN_PVR_KEYRTN_NONE:
                    //Do nothing
                    break;

                case EN_PVR_KEYRTN_PROCESSED:
                    u8KeyCode = KEY_NULL;
                    break;

                case EN_PVR_KEYRTN_TO_FILE_BROWSWER:
                    u8KeyCode = KEY_NULL;
                    enTVState = STATE_TV_INIT;
                    enTVRetVal = EXIT_GOTO_OSDPAGE;
                    MApp_OSDPage_SetOSDPage(E_OSD_PVR_BROWSER);
                    break;
            }
        }
    }
  #endif


#if ENABLE_TTX
  if((u8KeyCode!=KEY_INFO)&&(u8KeyCode!=KEY_SELECT)&&(u8KeyCode!=KEY_MENU)&&(u8KeyCode!=KEY_NULL))
     MApp_TTX_SetChInfoOnOff(FALSE);
#endif
#if ENABLE_S2//ENABLE_QSORT_SERVICE
    if(g_u8ShowChannelList == 1)
    {
        g_u8ShowChannelList = 0;
        u8KeyCode = KEY_CHANNEL_LIST;
    }
#endif
#if ENABLE_OAD
    if(OSD_COUNTRY_SETTING == OSD_COUNTRY_NORWAY)
    {
        if(MApp_OAD_IsPowerOnCheck() || MApp_OAD_IsScheduleOnCheck() || MApp_OAD_IsStandbyOffCheck())
        {
            if((u8KeyCode != KEY_POWER) || (u8KeyCode != DSC_KEY_PWROFF))
            {
                u8KeyCode = KEY_NULL;
            }
        }
    }
#endif
    switch ( u8KeyCode )
    {
        case KEY_RIGHT:
        case KEY_LEFT:
            if (IsAnyTVSourceInUse())
            {
              #ifndef PVR_8051
                MApp_ZUI_ProcessKey(u8KeyCode);
              #endif
            }
            u8KeyCode = KEY_NULL;
            break;

    #if FOR_BENCH_CODE
        case KEY_GREEN:
            MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
            MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_PING_MSGBOX);
            u8KeyCode = KEY_NULL;
        break;
    #endif

        case KEY_RED:
            if (IsAnyTVSourceInUse())
            {
              #if MHEG5_ENABLE
              #if (MHEG5_WITH_SUBTITLE==0 && CIPLUS_MHEG_1_3 == 0)
              #if ENABLE_MHEG_MSG
                // MHEG5 can't co-exist with Subtitle
              #if ENABLE_SUBTITLE
                // show XX spec, when subtitle up, user need turn off subtitle
                if ((MApp_SI_CheckMHEG5Status() != SI_MHEG5_DISABLE)
                        &&
                        ( ((u8SubtitleMenuNum > 0)&&(stGenSetting.g_SysSetting.fEnableSubTitle == TRUE)))
                   )
                {

                    MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_MHEG5_SUBTITLE_MSGBOX);
                }
              #endif
              #endif
              #endif
              #else
              #if ENABLE_SUBTITLE
                if ( ((u8SubtitleMenuNum > 0)&&(stGenSetting.g_SysSetting.fEnableSubTitle == TRUE)))
                {
                		#if(sShowNotAvailableMsg)
                    MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_FUNC_NOT_AVAIL_MSGBOX);
                    #endif
                }
              #endif
              #endif  // End of MHEG5_ENABLE
            }
            u8KeyCode = KEY_NULL;
            break;

    #if ENABLE_SUBTITLE
        case KEY_SUBTITLE:
            // Subtitle UI
        #if ENABLE_DTV
         #if(ENABLE_S2)
          #if(ENABLE_ATSC)
            if (IsS2InUse())
          #else
            if (IsDTVInUse()||IsS2InUse())
          #endif
         #else
            if ( IsDTVInUse() )
         #endif
            {
                {
                    enTVState = STATE_TV_INIT;
                    enTVRetVal = EXIT_GOTO_OSDPAGE;
                    MApp_OSDPage_SetOSDPage(E_OSD_SUBTITLE_LANGUAGE);
                }
            }
            else if ( IsATVInUse() )
        #else
            if ( IsATVInUse() )
        #endif
            {
            #if ENABLE_TTX
                if (MApp_TTX_GetSubtitlesAvailable()
                        #if (ENABLE_PIP)
                        && (MApp_Get_PIPMode() == EN_PIP_MODE_OFF)
                        #endif
                   )
                {

                    //The initial state enter subtitle page mode
                    MApp_TTX_TeletextCommand(TTX_SUBTITLE_NAVIGATION_MODE);
                }
                else
            #endif
                {
                    MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_NO_TTX_SUBTITLE_MSGBOX);
                }
            }
            else//for sources other than DTV/ATV
            {
            #if ENABLE_TTX
                if (  MApp_TTX_GetSubtitlesAvailable()
                  #if (ENABLE_PIP)
                   && (MApp_Get_PIPMode() == EN_PIP_MODE_OFF)
                  #endif
                   )
                {
                    //The initial state enter subtitle page mode

                    MApp_TTX_TeletextCommand(TTX_SUBTITLE_NAVIGATION_MODE);
                }
                else
                {
                    MApp_AnalogInputs_DeleteWin();
                    /*/ZUI:
                    enAnalogInputsState = STATE_ANALOGINPUTS_INIT;
                    enAnalogInputsRetVal = EXIT_ANALOGINPUTS_TRAN_MENU;
                    enUiMainMenuState = STATE_UIMENU_WAIT;

                    enMenuFlowState=FS_WAIT_MENU;
                    enCurTVWin=DISP_WIN_HKEY_PICTURE;
                    g_u8MenuPageIndex = MENU_NO_TTX_SUBTITLE_MSG;
                    g_u8MenuMainItemIndex = 0;
                    g_u8MsgPageIndex= g_u8MenuPageIndex;
                    MApp_UiMenu_ShowHotkeyMenu();
                    */
                    MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_NO_TTX_SUBTITLE_MSGBOX);
                }
            #endif
            }
            u8KeyCode = KEY_NULL;

          #if ENABLE_AUTOTEST
            if (g_bAutobuildDebug)
            {
                printf("91_KEY_SUBCODE\n");
            }
          #endif
            break;
    #endif // #if ENABLE_SUBTITLE

        case KEY_DISABLE_KEYPAD:
            if (IsAnyTVSourceInUse())
            {
                MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_KEY_LOCK_MSGBOX);
            }
            u8KeyCode = KEY_NULL;
            break;

        case KEY_POWER:
        case DSC_KEY_PWROFF:
          #if ENABLE_EPGTIMER_RECORDER_TURNOFFPANEL
            if (  g_bTimerTypeRecord
              #if ENABLE_CI_PLUS
               || g_bTimeTypeOpRefresh
              #endif
            )
            {
                MApp_SetActiveStandbyMode((MApp_GetActiveStandbyMode() == TRUE) ? FALSE : TRUE);
                u8KeyCode = KEY_NULL;
            }
            else
          #endif
            {
            #if ENABLE_OAD
                if (MApp_OAD_IsUserSelectOn() && MApp_OAD_GetSignalForStandby() && (OSD_COUNTRY_SETTING == OSD_COUNTRY_NEWZEALAND))
                {
                    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_INTERNAL_3_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                    MApi_PNL_SetBackLight(DISABLE);
                    MApp_SaveGenSetting();
                #if(!BLOADER)
                    MApp_ZUI_ACT_StartupOSD(E_OSD_OAD);
                #endif
                    MApp_OAD_StandbyUpdate();
                    enTVRetVal = EXIT_GOTO_OAD;
                    u8KeyCode = KEY_NULL;
                }
                else
            #endif
                {
		      enTVState = STATE_TV_INIT;
		      enTVRetVal = EXIT_GOTO_STANDBY;
		      u8KeyCode = KEY_NULL;
                }
#if ENABLE_ATSC_TTS
                MApp_TTSControlSetInputText(MApp_ZUI_API_GetString(en_str_Power), MApp_UiMenu_u16Strlen(MApp_ZUI_API_GetString(en_str_Power)));
                MApp_TTSControlSetInputText(MApp_ZUI_API_GetString(en_str_Off), MApp_UiMenu_u16Strlen(MApp_ZUI_API_GetString(en_str_Off)));
                MApp_TTSControlSetOn(TRUE);
#endif
            }
            break;

        case KEY_MENU:
#if ENABLE_ATSC_TTS
            MApp_TTSControlSetInputText(MApp_ZUI_API_GetString(en_str_Main_Menu_Open), MApp_UiMenu_u16Strlen(MApp_ZUI_API_GetString(en_str_Main_Menu_Open)));
            MApp_TTSControlSetOn(TRUE);
#endif
            enTVState = STATE_TV_INIT;
            enTVRetVal = EXIT_GOTO_MENU;
            u8KeyCode = KEY_NULL;
          #if ENABLE_AUTOTEST
            if (g_bAutobuildDebug)
            {
                printf("91_KEY_MENU\n");
            }
          #endif
            break;

        case KEY_CHANNEL_PLUS:
        case KEY_CHANNEL_MINUS:
          #if ENABLE_ATSC
            if(IsATVInUse() || IsAtscInUse())
            {
                if( ( E_OSD_CHANNEL_LIST == MApp_ZUI_GetActiveOSD()) )
                {
                    u8KeyCode = KEY_NULL;
                    break;
                }
                else if(MApp_ChanProc_GetNumOfServices(MAIN_LIST))
                {
                    #if (ENABLE_CHCHANGETIME)
                    printf("[Channel change time begin]\n");
                    gbKeyPress = TRUE;
                    gU32ChChangeTime = msAPI_Timer_GetTime0();
                    #endif
                    if((MApp_ZUI_GetActive_ChannelInfo_OSD()) && (u8IdleDigitCount != 0))
                        MApp_ZUI_ACT_ShutdownOSD();

                    MApp_ChannelChange_DisableChannel(TRUE, MAIN_WINDOW);

                #if (ENABLE_ATV_CHANNEL_CHANGE_FINETUNING)
                    if(u8KeyCode == KEY_CHANNEL_PLUS)
                    {
                        MApp_ChanProc_IncProgIndex(MAIN_LIST, 1, TRUE);
                    }
                    else
                    {
                        MApp_ChanProc_DecProgIndex(MAIN_LIST, 1, TRUE);
                    }
                    MApp_ChanProc_RefreshChannelBuffer(MAIN_LIST);

                //if display info exist in the screen then to change channel,the display info should be disappear first!
                    if ((MApp_ZUI_ACT_IsChInfoMode(TYPE_CHANNEL_INFO)) || (MApp_ZUI_ACT_IsChInfoMode(TYPE_CHANNEL_ETT)))
                    {
                        MApp_ZUI_ACT_ShutdownOSD();
                    }


                    if (MApp_ZUI_ACT_IsChInfoMode(TYPE_CHANNEL_BANNER))
                    {
                    #if (ENABLE_MESSAGE_BOX_DISPLAY_TIMING)
                        //MApp_ZUI_ACT_ExecuteChannelInfoAction(EN_EXE_CHINFO_BANNER_PROG_TIMIMG_RESET);
                        MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_CHINFO_BANNER_PROG_TIMIMG_RESET);
                    #else
                        MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_CHINFO_BANNER_RESET);
                    #endif
                    }

                    if (u8KeyCode != KEY_INFO)
                    {
                        enChannelInfoPageType = TYPE_CHANNEL_BANNER;
                        MApp_ZUI_ACT_Startup_ChannelInfo_OSD();;
                    }

                    MApp_ZUI_ACT_Startup_ChannelInfo_OSD();
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_BRIEF_CH_INFO);

                    MApp_ChannelChange_EnableChannel(MAIN_WINDOW);
                    msAPI_AVD_CheckStdDetStableReset();

                  #if ENABLE_ATV_CHANNEL_CHANGE_FINETUNING
                    MApp_SetChChangeState(TRUE);
                  #endif
                    u8KeyCode = KEY_NULL;
                #else
                    enTVState = STATE_TV_INIT;
                    enTVRetVal = EXIT_GOTO_CHANNELCHANGE;
                #endif
                }
            }
            else
          #endif // #if ENABLE_ATSC

          #if ENABLE_DTV
          #if ENABLE_PIP
          if (IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW))
             ||(IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW)) && (MApp_Get_PIPMode() != EN_PIP_MODE_OFF)))
          #else
        #if(ENABLE_S2)
            if ( IsDTVInUse() || IsS2InUse())
        #else
          if ( IsDTVInUse() )
          #endif
          #endif
            {
                if (u16TotalProNum)
                {
                  #if ENABLE_PVR
                    MEMBER_SERVICETYPE bServiceType,bNewServiceType;
                    WORD wNewProgramPosition;
                  #if ENABLE_SBTVD_BRAZIL_CM_APP
                    U16 u16CurOridinal,u16NextOridinal;
                  #endif

                    bNewServiceType = bServiceType = msAPI_CM_GetCurrentServiceType();

                  #if ENABLE_SBTVD_BRAZIL_CM_APP
                    u16CurOridinal = msAPI_CHPROC_CM_GetCurrentOrdinal(E_SERVICETYPE_UNITED_TV,E_PROGACESS_INCLUDE_VISIBLE_ONLY);
                    if (u8KeyCode ==KEY_CHANNEL_PLUS)
                    {
                        u16NextOridinal = msAPI_CHPROC_CM_GetNextOrdinal(E_SERVICETYPE_UNITED_TV,u16CurOridinal,FALSE);
                    }
                    else
                    {
                        u16NextOridinal = msAPI_CHPROC_CM_GetPrevOrdinal(E_SERVICETYPE_UNITED_TV,u16CurOridinal,FALSE);
                    }
                    msAPI_CHPROC_CM_GetOrdinal_SerType_Position_Brazil(u16NextOridinal,&bNewServiceType,&wNewProgramPosition);
                    wNewProgramPosition = u16NextOridinal;
                  #else
                    if (u8KeyCode ==KEY_CHANNEL_PLUS)
                    {
                        wNewProgramPosition = msAPI_CM_GetNextProgramPosition(bServiceType, msAPI_CM_GetCurrentPosition(bServiceType), FALSE, E_ALL_LIST,&bNewServiceType);
                    }
                    else
                    {
                        wNewProgramPosition = msAPI_CM_GetPrevProgramPosition(bServiceType, msAPI_CM_GetCurrentPosition(bServiceType), FALSE, E_ALL_LIST, &bNewServiceType);
                    }
                  #endif

                    if (MApp_ZUI_ACT_PVR_Check_Switch_Channel(bNewServiceType, wNewProgramPosition) == FALSE)
                    {
                        u8KeyCode = KEY_NULL;
                        break;
                    }

                    #if ENABLE_CI
                    {
                        U8 CIEvt=msAPI_CI_MMICheckEvent();
                        if( (CI_EVENT_MMI_CLOSE == CIEvt)||(CI_EVENT_MMI_MENU == CIEvt)
                            ||(CI_EVENT_MMI_ENQ== CIEvt)||(CI_EVENT_MMI_LIST== CIEvt))
                        {
                            msAPI_CI_MMIDoneEvent(CIEvt);
                        }
                    }
                    #endif
                  #endif
                    enTVState = STATE_TV_INIT;
                    enTVRetVal = EXIT_GOTO_CHANNELCHANGE;
                }
                else
                {
                    u8KeyCode = KEY_NULL;
                }

            }
            else
          #endif
            #if ENABLE_PIP
            if (IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW))
                ||(IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW))&& (MApp_Get_PIPMode() != EN_PIP_MODE_OFF)))
            #else
            if ( IsATVInUse() )
            #endif
            {
                enTVState = STATE_TV_INIT;
                enTVRetVal = EXIT_GOTO_CHANNELCHANGE;
            }
            else
                u8KeyCode = KEY_NULL;

            //Cancel Freeze
            if(g_bIsImageFrozen)
            {
                g_bIsImageFrozen = FALSE;
                MApi_XC_FreezeImg(g_bIsImageFrozen, MAIN_WINDOW);
            }

          #if ENABLE_AUTOTEST
            if (g_bAutobuildDebug)
            {
                switch (u8KeyCode)
                {
                    case KEY_CHANNEL_PLUS:
                        printf("91_KEY_CHANNEL_PLUS\n");
                        break;
                    case KEY_CHANNEL_MINUS:
                        printf("91_KEY_CHANNEL_MINUS\n");
                        break;
                    default:
                        break;
                }
            }
          #endif
            break;

        case KEY_EXIT:
            u8KeyCode = KEY_NULL;
            break;

        case KEY_INFO:
#if ENABLE_ATSC_TTS
            MApp_TTSControlSetInputText(MApp_ZUI_API_GetString(en_str_Info), MApp_UiMenu_u16Strlen(MApp_ZUI_API_GetString(en_str_Info)));
            MApp_TTSControlSetOn(TRUE);
#endif
          #if(ENABLE_ATSC)
            if(IsAtscInUse()||IsATVInUse())
            {
                if(MApp_ChanProc_GetNumOfServices(MAIN_LIST))
                {
                    //if(E_OSD_EMPTY == MApp_ZUI_GetActiveOSD())
                    if(!MApp_ZUI_GetActive_ChannelInfo_OSD())
                    {
                        enChannelInfoPageType = TYPE_CHANNEL_INFO;
                        MApp_ZUI_ACT_Startup_ChannelInfo_OSD();
                        if(IsS2InUse())
                        {
                            MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_BRIEF_CH_INFO);
                        }
                    #if ENABLE_ATSC_TTS
                        if (IsDTVInUse())
                        {
                            MApp_TTSControlSetOn(TRUE);
                        }
                    #endif
                        TV_DBINFO(printf("TV keyinfo\n"));
                    }
                    else //if (E_OSD_CHANNEL_INFO == MApp_ZUI_GetActiveOSD())
                    {
                    #ifndef CHANNEL_INFOR_DISPLAY
                        if(IsDTVInUse() && MApp_ZUI_ACT_IsChInfoMode(TYPE_CHANNEL_INFO))
                        {
                            enChannelInfoPageType = TYPE_CHANNEL_ETT;
                            MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_CHINFO_ETT_INFO_SHOW);
                        }
                        else    //close OSD
                    #endif
                        {
                            MApp_ZUI_ACT_ShutdownOSD();
                            enChannelInfoPageType = TYPE_CHANNEL_BANNER;
                        }
                    }
                    u8KeyCode = KEY_NULL;
                }
            }
            else
          #endif // #if(ENABLE_ATSC)

          #if ENABLE_DTV
           #if  (ENABLE_S2)
            if (IsDTVInUse()||IsS2InUse())
           #else
            if (IsDTVInUse())
           #endif
            {
                bNextEvent = FALSE;
                u8InfoScrollLineCount = 0;
                u8InfoScrollLineCount_Pre = 0;
                MApp_ZUI_ACT_Startup_ChannelInfo_OSD();
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_EXTENDED_CH_INFO);
                //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_TV_BANNER);

                u8KeyCode = KEY_NULL;
            }
            else
          #endif // #if ENABLE_DTV

            if (IsATVInUse()) // Analog TV
            {
                u8KeyCode = KEY_SELECT;  // Show the brief info
            }
            else
            {
                MApp_ZUI_ACT_Startup_ChannelInfo_OSD();
                //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_BRIEF_CH_INFO);
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_SOURCE_BANNER);

                MApp_AnalogInputs_ResetTimer(MAIN_WINDOW);
                #if (ENABLE_PIP)
                if(MApp_Get_PIPMode() != EN_PIP_MODE_OFF)
                {
                    MApp_AnalogInputs_ResetTimer(SUB_WINDOW);
                }
                #endif
                u8KeyCode = KEY_NULL;
            }

          #if ENABLE_AUTOTEST
            if (g_bAutobuildDebug)
            {
                printf("91_KEY_INFO\n");
            }
          #endif
            break;

        case KEY_SELECT:
            if (MApp_ZUI_GetActiveOSD() == E_OSD_TENKEY_NUMBER)
            {
            #if ENABLE_ATSC
                if(IsAtscInUse()||IsATVInUse())
                {
                    MApp_TV_ChannelChangeProc(&stVirtualChNum, (EN_ANT_TYPE)ANT_TYPE);
                    u8KeyCode = KEY_NULL;
                    break;
                }
            #endif
                U16 u16Ordinal;
              #if ENABLE_SBTVD_BRAZIL_APP
                u16Ordinal = MApp_TV_SBTVD_DigitKeyVerifyInputValue(u8IdleMajorValue, u8IdleMinorValue);
              #else
                u16Ordinal = MApp_TV_NumWinVerifyInputValue(u16IdleInputValue);
              #endif
                if (u16Ordinal != INVALID_ORDINAL)
                {
                 #ifdef ENABLE_SELECT_NONESEARCH_CH
                    printf("\r\n [2] Exist ch: u16ChannelReturn_Num1=%u",u16ChannelReturn_Num1);
                    printf("\r\n [2] Exist ch: u16ChannelReturn_Num2=%u",u16ChannelReturn_Num2);
                    u16ChannelReturn_Num2=u16ChannelReturn_Num1;
                    u16ChannelReturn_Num1=IVALID_TV_RETURN_NUM;
                 #endif

                  #if ENABLE_PVR
                    if (MApp_ZUI_ACT_PVR_Check_Switch_Channel(msAPI_CM_GetCurrentServiceType(), u16Ordinal) == FALSE)
                    {
                        u8KeyCode = KEY_NULL;
                        break;
                    }
                  #endif

                    _MApp_ChannelList_ChannelChange(u16Ordinal, SERVICE_TYPE_TV, TRUE, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO);

                    MApp_ZUI_ACT_ShutdownOSD();

                  #if ( ENABLE_DVB_TAIWAN_APP || ENABLE_SBTVD_BRAZIL_APP )
                    msAPI_ATV_SetDirectTuneFlag(FALSE);
                  #endif

                    //Cancel Freeze
                    if (g_bIsImageFrozen)
                    {
                        g_bIsImageFrozen = FALSE;
                        MApi_XC_FreezeImg(g_bIsImageFrozen, MAIN_WINDOW);
                    }

                  #if ( ENABLE_DVB_TAIWAN_APP && (ENABLE_SBTVD_BRAZIL_APP == 0))
                    if (IsATVInUse() && (msAPI_ATV_IsProgramSearched(msAPI_ATV_GetCurrentProgramNumber())==FALSE))
                    {
                        stGenSetting.stScanMenuSetting.u8ScanType = SCAN_TYPE_MANUAL;
                        stGenSetting.stScanMenuSetting.u8ATVManScanType=ATV_MAN_SCAN_TYPE_ONECH;
                        stGenSetting.stScanMenuSetting.u8ATVManScanDir=ATV_MAN_SCAN_UP;
                        enTVRetVal = EXIT_GOTO_SCAN;
                    }
                  #endif

                }
             #ifdef ENABLE_SELECT_NONESEARCH_CH
                else
                {
                    if(u16IdleInputValue>=msAPI_ATV_GetChannelMin()&&u16IdleInputValue<=msAPI_ATV_GetChannelMax())
                    {
                        printf("\r\n u16IdleInputValue=%u",u16IdleInputValue);
                        u16ChannelReturn_Num2=u16ChannelReturn_Num1;
                        u16ChannelReturn_Num1=u16IdleInputValue;
                        printf("\r\n ATV ch: u16ChannelReturn_Num1=%u",u16ChannelReturn_Num1);
                        printf("\r\n ATV ch: u16ChannelReturn_Num2=%u",u16ChannelReturn_Num2);
                        if (IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
                        {
                            dmSetLastWatchedOrdinal();
                            if ( IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
                            {
                                MApp_ChannelChange_DisableAV(MAIN_WINDOW);
                            }
                            msAPI_CHPROC_CM_SetCurrentOrdinal(E_SERVICETYPE_ATV, u16IdleInputValue-2, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO);
                            msAPI_Scaler_SetBlueScreen( DISABLE, E_XC_FREE_RUN_COLOR_BLACK, DEFAULT_SCREEN_UNMUTE_TIME, MAIN_WINDOW);
                        }
                        if (IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
                        {
                            UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_ATV;
                         #if ENABLE_SBTVD_BRAZIL_APP
                            MApp_ChannelChange_DisableChannel(TRUE,MAIN_WINDOW);
                         #endif
                            MApp_InputSource_SwitchSource(UI_INPUT_SOURCE_TYPE, MAIN_WINDOW);
                            dmSetLastWatchedOrdinal();
                            msAPI_CHPROC_CM_SetCurrentOrdinal(E_SERVICETYPE_ATV, u16IdleInputValue-2, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO);
                        }
                     }
                }
             #endif
                MApp_ZUI_ACT_Startup_ChannelInfo_OSD();
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_BRIEF_CH_INFO);
                //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_TV_BANNER);
            }
          #if ENABLE_PVR
          #ifndef PVR_8051
            else if (MApp_ZUI_GetActiveOSD() == E_OSD_PVR)
            {
                MApp_ZUI_ProcessKey(u8KeyCode);
            }
          #endif
          #endif
        #if ENABLE_ATSC
            else if (MApp_ZUI_GetActiveOSD() == E_OSD_SCREEN_SAVER && SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) == EN_SCREENSAVER_BLOCKRATING)
            {
                MApp_ChannelChange_CheckBlockChannelPW();
            }
            else if ((MApp_ZUI_GetActiveOSD() == E_OSD_EMPTY) && g_bInputBlocked)
            {
                MApp_ChannelChange_CheckBlockChannelPW();
            }
        #endif
            else if (IsAnyTVSourceInUse())
            {
                MApp_ZUI_ACT_ShutdownOSD();

                MApp_ZUI_ACT_Startup_ChannelInfo_OSD();
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_BRIEF_CH_INFO);
                //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_TV_BANNER);
            }
            else//non DTV/ATV sources
            {
                MApp_ZUI_ACT_Startup_ChannelInfo_OSD();
                //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_BRIEF_CH_INFO);
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_SOURCE_BANNER);

                MApp_AnalogInputs_ResetTimer(MAIN_WINDOW);
                #if (ENABLE_PIP)
                if(MApp_Get_PIPMode() != EN_PIP_MODE_OFF)
                {
                    MApp_AnalogInputs_ResetTimer(SUB_WINDOW);
                }
                #endif
            }
            u8KeyCode = KEY_NULL;
            break;
        #if(IR_TYPE_SEL==IR_TYPE_TRIVIEW_STD)
        case KEY_USB:
            //printf("MingYuan USB Key MApp_TV_ProcessUserInput \n");
            u8KeyCode = KEY_NULL;
          	break;
        #endif
        case KEY_MUTE:
        case KEY_VOLUME_PLUS:
        case KEY_VOLUME_MINUS:
        {
            MApp_ZUI_ACT_StartupOSD(E_OSD_AUDIO_VOLUME);
#if ENABLE_ATSC_TTS
            enTVState = STATE_TV_WAIT;
            enTVRetVal = EXIT_TV_GOTO_TTS;
            MApp_TTSControlSetOn(TRUE);
#endif
            MApp_TV_ProcessAudioVolumeKey(u8KeyCode);
            MApp_AnalogInputs_ResetTimer(MAIN_WINDOW);
            #if (ENABLE_PIP)
            if(MApp_Get_PIPMode() != EN_PIP_MODE_OFF)
            {
                MApp_AnalogInputs_ResetTimer(SUB_WINDOW);
            }
            #endif
        }
      #if ENABLE_AUTOTEST
        if (g_bAutobuildDebug)
        {
            switch (u8KeyCode)
            {
                case KEY_VOLUME_PLUS:
                    printf("91_KEY_VOLUME_PLUS\n");
                    break;
                case KEY_VOLUME_MINUS:
                    printf("91_KEY_VOLUME_MINUS\n");
                    break;
                default:
                    break;
            }
        }
      #endif
        u8KeyCode = KEY_NULL;
        break;

        case KEY_COUNTDOWN_EXIT_TT_SUBTITLE:
            if (MApp_ZUI_GetActiveOSD() != E_OSD_MESSAGE_BOX ||
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_QUERY_IS_POWER_OFF_COUNTDOWN_MSG_BOX) == FALSE)
            {
                MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_POWER_OFF_COUNTDOWN_MSG_BOX);
            }
            u8KeyCode = KEY_NULL;
            break;

      #if ENABLE_DTV_EPG //ENABLE_DTV
        case KEY_EPGTIMER_COUNTDOWN:
            #if ENABLE_DVB
            MApp_ZUI_EpgTimerCountDown();
            #endif
            u8KeyCode = KEY_NULL;
            break;
      #endif
        case KEY_1:
        case KEY_2:
        case KEY_3:
        case KEY_4:
        case KEY_5:
        case KEY_6:
        case KEY_7:
        case KEY_8:
        case KEY_9:
        case KEY_0:
      #if  (ENABLE_ATSC || ENABLE_SBTVD_BRAZIL_APP)
        case KEY_DASH:
      #endif
         #if(ENABLE_PIP)
            if (IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW))
                ||(IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW)) && (MApp_Get_PIPMode() != EN_PIP_MODE_OFF))
                ||IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW))
                ||(IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW))&& (MApp_Get_PIPMode() != EN_PIP_MODE_OFF)))
          #else
            if (IsAnyTVSourceInUse())
          #endif
            {
                #if ENABLE_ATSC
                if(IsAtscInUse()||IsATVInUse())
                {
                        MApp_TV_NumWinProcDigitKey_ATSC(u8KeyCode);
                }
                else
                #endif
                {
                    MApp_TV_NumWinProcDigitKey(u8KeyCode);
                }
            }
            else
            {
            		#if(sShowNotAvailableMsg)
                MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_FUNC_NOT_AVAIL_MSGBOX);
                #endif
            }
            #if ENABLE_AUTOTEST
            if (g_bAutobuildDebug)
            {
                printf("91_KEY_NUM\n");
            }
            #endif
            u8KeyCode = KEY_NULL;
            break;

        case KEY_CHANNEL_RETURN:
#if ENABLE_ATSC_TTS
            MApp_TTSControlSetTextAndSay(MApp_ZUI_API_GetString(en_str_Channel), MApp_UiMenu_u16Strlen(MApp_ZUI_API_GetString(en_str_Channel)));
            MApp_TTSControlSetTextAndSay(MApp_ZUI_API_GetString(en_str_Return), MApp_UiMenu_u16Strlen(MApp_ZUI_API_GetString(en_str_Return)));
#endif
#if ENABLE_ATSC
            if(IsAtscInUse()||IsATVInUse())
            {
                if(MApp_ChanProc_GetNumOfServices(MAIN_LIST))
                {
                    MApp_ChannelChange_DisableChannel(TRUE, MAIN_WINDOW);
                    MApp_ChanProc_ChRtnProgIndex();
                    MApp_ChanProc_RefreshChannelBuffer(MAIN_LIST);

                    MApp_ZUI_ACT_Startup_ChannelInfo_OSD();
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_BRIEF_CH_INFO);

                    MApp_ChannelChange_EnableChannel(MAIN_WINDOW);
                    msAPI_AVD_CheckStdDetStableReset();

                    enTVState = STATE_TV_INIT;
                    enTVRetVal = EXIT_GOTO_CHANNELCHANGE;
                }
            }
            else
#endif
            if (IsAnyTVSourceInUse())
            {
                U16 u16PreOrdinal;
                U16 u16CurOrdinal;
              #ifdef ENABLE_SELECT_NONESEARCH_CH
                U16 ReturnNumTemp;
              #endif

              #if ( ENABLE_DVB_TAIWAN_APP || ENABLE_SBTVD_BRAZIL_APP )
                msAPI_ATV_SetDirectTuneFlag(TRUE);
              #endif

                u16PreOrdinal = dmGetLastWatchOrdinal();
                u16CurOrdinal = msAPI_CHPROC_CM_GetCurrentOrdinal(E_SERVICETYPE_UNITED_TV, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
          #ifdef ENABLE_SELECT_NONESEARCH_CH
                printf("\n u16PreOrdinal: 0x%x, u16CurOrdinal:0x%x,u16ChannelReturn_Num2:0x%x \n",u16PreOrdinal,u16CurOrdinal,u16ChannelReturn_Num2);
            if(u16ChannelReturn_Num2==IVALID_TV_RETURN_NUM)
                {
          #endif
                    if ((u16PreOrdinal == INVALID_ORDINAL) || (u16PreOrdinal == u16CurOrdinal))
                    {
                    //do nothing
                }
                else
                {
                  #if (ENABLE_PVR)
                    if (MApp_ZUI_ACT_PVR_Check_Switch_Channel(msAPI_CM_GetCurrentServiceType(), u16PreOrdinal) == FALSE)
                    {
                        u8KeyCode = KEY_NULL;
                        break;
                    }
                  #endif

                    #if ENABLE_CI
                    {
                        U8 CIEvt=msAPI_CI_MMICheckEvent();
                        if( (CI_EVENT_MMI_CLOSE == CIEvt)||(CI_EVENT_MMI_MENU == CIEvt)
                            ||(CI_EVENT_MMI_ENQ== CIEvt)||(CI_EVENT_MMI_LIST== CIEvt))
                        {
                            msAPI_CI_MMIDoneEvent(CIEvt);
                        }
                    }
                    #endif

                    _MApp_ChannelList_ChannelChange(u16PreOrdinal, E_SERVICETYPE_UNITED_TV, TRUE, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
                }
        #ifdef ENABLE_SELECT_NONESEARCH_CH
             }
            else
            {
                u16IdleInputValue=u16ChannelReturn_Num2;
                printf("\r\n ----u16IdleInputValue=%u",u16IdleInputValue);
                if(msAPI_CHPROC_CM_GetCurrentOrdinal(E_SERVICETYPE_UNITED_TV, E_PROGACESS_INCLUDE_VISIBLE_ONLY)!=INVALID_ORDINAL)
                    dmSetLastWatchedOrdinal();

               msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_MOMENT_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);

                if(IsATVInUse())
                    msAPI_CHPROC_CM_SetCurrentOrdinal(E_SERVICETYPE_ATV, u16IdleInputValue-2, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO);
                else
                {
                    UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_ATV;
                 #if ENABLE_SBTVD_BRAZIL_APP
                    MApp_ChannelChange_DisableChannel(TRUE,MAIN_WINDOW);
                 #endif
                    MApp_InputSource_SwitchSource( UI_INPUT_SOURCE_TYPE, MAIN_WINDOW );
                   // MApp_InputSource_ChangeInputSource(MAIN_WINDOW);
                    msAPI_CHPROC_CM_SetCurrentOrdinal(E_SERVICETYPE_ATV, u16IdleInputValue-2, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO);
                }

               msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_MOMENT_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
            }
            ReturnNumTemp=u16ChannelReturn_Num2;
            u16ChannelReturn_Num2=u16ChannelReturn_Num1;
            u16ChannelReturn_Num1=ReturnNumTemp;

            printf("\r\n Swap after _Num1=%u",u16ChannelReturn_Num1);
            printf("\r\n Swap after _Num2=%u",u16ChannelReturn_Num2);
          #endif
               #if ( ENABLE_DVB_TAIWAN_APP || ENABLE_SBTVD_BRAZIL_APP )
                msAPI_ATV_SetDirectTuneFlag(FALSE);
              #endif

                if (MApp_ZUI_GetActive_ChannelInfo_OSD())
                {
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_REPAINT_CH_BANNER);
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_REPAINT_CH_INFO);
                }
                else
                {
                    MApp_ZUI_ACT_Startup_ChannelInfo_OSD();
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_BRIEF_CH_INFO);
                    //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_TV_BANNER);
                }


            }
            else
            {
            		#if(sShowNotAvailableMsg)
                MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_FUNC_NOT_AVAIL_MSGBOX);
                #endif
            }
            #if ENABLE_AUTOTEST
            if(g_bAutobuildDebug)
            {
                printf("91_KEY_RETURN\n");
            }
            #endif
            u8KeyCode = KEY_NULL;
            break;
        case KEY_CHANNEL_LIST:
            if (IsAnyTVSourceInUse())
            {
              #if MHEG5_ENABLE
                MApp_ChannelPosition_Restore();
              #endif
                enTVState = STATE_TV_INIT;
                enTVRetVal = EXIT_GOTO_OSDPAGE;
                MApp_OSDPage_SetOSDPage(E_OSD_CHANNEL_LIST);
                MApp_ChannelList_SetMode(MODE_CHLIST_TV);
            }
            u8KeyCode = KEY_NULL;
          #if ENABLE_AUTOTEST
            if (g_bAutobuildDebug)
            {
                printf("91_KEY_LIST\n");
            }
          #endif
            break;

        case KEY_CHANNEL_FAV_LIST:
            if (IsAnyTVSourceInUse())
            {
              #if MHEG5_ENABLE
                MApp_ChannelPosition_Restore();
              #endif
                enTVState = STATE_TV_INIT;
                enTVRetVal = EXIT_GOTO_OSDPAGE;
                MApp_OSDPage_SetOSDPage(E_OSD_CHANNEL_LIST);
                MApp_ChannelList_SetMode(MODE_CHLIST_TV_FAV);
            }
            else
            {
            		#if(sShowNotAvailableMsg)
                MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_FUNC_NOT_AVAIL_MSGBOX);
                #endif
            }
            u8KeyCode = KEY_NULL;
            break;

        case KEY_INPUT_SOURCE:
            enTVState = STATE_TV_INIT;
            enTVRetVal = EXIT_GOTO_INPUTSOURCE;
            u8KeyCode = KEY_NULL;
            break;

            // Use Green key as TV hotkey tempory for testing
            // Will change to XX TV key when key map ready
        case KEY_TV_RADIO:
        {
          #if ENABLE_DVB
            MEMBER_SERVICETYPE u8NextType;
            if( IsDVBInUse() )
            {
                if (msAPI_CM_GetCurrentServiceType() == E_SERVICETYPE_DTV)
                    u8NextType = E_SERVICETYPE_RADIO;
                else
                    u8NextType = E_SERVICETYPE_DTV;

                if (msAPI_CM_CountProgram( u8NextType, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO )>0)
                {
                    if ( IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)) )
                        MApp_ChannelChange_DisableChannel(TRUE,MAIN_WINDOW);
                    #if (ENABLE_PIP)
                    if (MApp_Get_PIPMode() != EN_PIP_MODE_OFF)
                    {
                        if ( IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW)) )
                            MApp_ChannelChange_DisableChannel(TRUE,SUB_WINDOW);
                    }
                    #endif

                    if (msAPI_CM_GetCurrentServiceType()== E_SERVICETYPE_DTV)
                        msAPI_CM_SetCurrentServiceType(E_SERVICETYPE_RADIO);
                    else
                        msAPI_CM_SetCurrentServiceType(E_SERVICETYPE_DTV);

                    enTVState = STATE_TV_INIT;
                    enTVRetVal = EXIT_GOTO_CHANNELCHANGE;
                }
            }
          #endif
            u8KeyCode = KEY_NULL;
        }
        break;

        // source switching hotkeys
        // PIP/POP Concept: these hotkeys are working on main window, if sub window source is not
        //                    compatible with main window source, sub window sould be closed.
        case KEY_DTV:
            #if 0
        #if( ENABLE_DTV )
            if (!IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
            {
                #if (ENABLE_PIP)
                if(MApp_Get_PIPMode() != EN_PIP_MODE_OFF)
                {
                    MApp_ClosePIPSubWindowSource();
                }
                #endif
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_DTV;
                MApp_InputSource_ChangeInputSource(MAIN_WINDOW);
                MApp_ChannelChange_VariableInit();
                MApp_TopStateMachine_SetTopState(STATE_TOP_CHANNELCHANGE);

            }
            else
            {
                MApp_ZUI_ACT_Startup_ChannelInfo_OSD();
                if (IsAnyTVSourceInUse())
                {
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_BRIEF_CH_INFO);
                    //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_TV_BANNER);
                }
                else
                {
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_SOURCE_BANNER);
                }
            }
        #endif
        #endif
            u8KeyCode = KEY_NULL;
            break;

    #if ENABLE_S2
        case KEY_TEST_DVBS2:
            Test_Dvbs2 = TRUE;
        case KEY_DVBS2:
            if (!IsS2InUse())
            {
            #if (ENABLE_PIP)
            		#ifdef sMingYuanPIP_Test
                if (MApp_Get_PIPMode() != EN_PIP_MODE_OFF)
                #else
                if (IsPIPEnable())
                #endif
                {
                    //Close subwindow and set compatible source type to sub win
                    if(stGenSetting.g_stPipSetting.enPipSoundSrc==EN_PIP_SOUND_SRC_SUB)
                    {
                        stGenSetting.g_stPipSetting.enPipSoundSrc=EN_PIP_SOUND_SRC_MAIN;
                        MApp_InputSource_PIP_ChangeAudioSource(MAIN_WINDOW);
                    }
                    UI_SUB_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_NONE;
                    MApp_InputSource_ChangeInputSource(SUB_WINDOW);
                    stGenSetting.g_stPipSetting.enPipMode = EN_PIP_MODE_OFF;
                    UI_SUB_INPUT_SOURCE_TYPE = MApp_InputSource_GetUIInputSourceType(MApp_InputSource_PIP_Get1stCompatibleSrc(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)));
                }
            #endif
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_S2;
                MApp_InputSource_ChangeInputSource(MAIN_WINDOW);
                MApp_ChannelChange_VariableInit();
                MApp_TopStateMachine_SetTopState(STATE_TOP_CHANNELCHANGE);
            }
            else
            {
                MApp_ZUI_ACT_Startup_ChannelInfo_OSD();
                if (IsAnyTVSourceInUse())
                {
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_BRIEF_CH_INFO);
                    //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_TV_BANNER);
                }
                else
                {
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_SOURCE_BANNER);
                }
            }
            if (u8KeyCode == KEY_TEST_DVBS2)
            {
                if (msAPI_CM_Test_SetOneProgram())
                {
                    u8KeyCode = KEY_NULL;
                    break;
                }
            }
            u8KeyCode = KEY_NULL;
            break;
        #endif

        case KEY_TV:
            if (!IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
            {
                #if (ENABLE_PIP)
                if(MApp_Get_PIPMode() != EN_PIP_MODE_OFF)
                {
                    MApp_ClosePIPSubWindowSource();
                }
                #endif
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_ATV;
                MApp_InputSource_ChangeInputSource(MAIN_WINDOW);
                MApp_ChannelChange_VariableInit();
                MApp_TopStateMachine_SetTopState(STATE_TOP_CHANNELCHANGE);
            }
            else
            {
                MApp_ZUI_ACT_Startup_ChannelInfo_OSD();
                if (IsAnyTVSourceInUse())
                {
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_BRIEF_CH_INFO);
                    //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_TV_BANNER);
                }
                else
                {
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_SOURCE_BANNER);
                }
            }
            u8KeyCode = KEY_NULL;
            break;
        case KEY_PC:
            if (!IsSrcTypeVga(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
            {
                #if (ENABLE_PIP)
                if(MApp_Get_PIPMode() != EN_PIP_MODE_OFF)
                {
                    MApp_ClosePIPSubWindowSource();
                }
                #endif
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_RGB;
                MApp_InputSource_ChangeInputSource(MAIN_WINDOW);
                MApp_ChannelChange_VariableInit();
                MApp_TopStateMachine_SetTopState(STATE_TOP_ANALOG_SHOW_BANNER);
            }
            else
            {
                MApp_ZUI_ACT_Startup_ChannelInfo_OSD();
                if (IsAnyTVSourceInUse())
                {
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_BRIEF_CH_INFO);
                    //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_TV_BANNER);
                }
                else
                {
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_SOURCE_BANNER);
                }
            }
            u8KeyCode = KEY_NULL;
            break;
      #if (INPUT_YPBPR_VIDEO_COUNT > 0)
        case KEY_COMPONENT:
            if (!IsSrcTypeYPbPr(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
            {
                #if (ENABLE_PIP)
                if(MApp_Get_PIPMode() != EN_PIP_MODE_OFF)
                {
                    MApp_ClosePIPSubWindowSource();
                }
                #endif
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_COMPONENT;
                MApp_InputSource_ChangeInputSource(MAIN_WINDOW);

                MApp_ChannelChange_VariableInit();
                MApp_TopStateMachine_SetTopState(STATE_TOP_ANALOG_SHOW_BANNER);
            }
            else
            {
                MApp_ZUI_ACT_Startup_ChannelInfo_OSD();
                if (IsAnyTVSourceInUse())
                {
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_BRIEF_CH_INFO);
                    //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_TV_BANNER);
                }
                else
                {
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_SOURCE_BANNER);
                }
            }
            u8KeyCode = KEY_NULL;
            break;
      #endif
      #if (INPUT_HDMI_VIDEO_COUNT > 0)
        case KEY_HDMI:
            if (!IsSrcTypeHDMI(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
            {
                #if (ENABLE_PIP)
                if(MApp_Get_PIPMode() != EN_PIP_MODE_OFF)
                {
                    MApp_ClosePIPSubWindowSource();
                }
                #endif
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_HDMI;
                MApp_InputSource_ChangeInputSource(MAIN_WINDOW);

                MApp_ChannelChange_VariableInit();
                MApp_TopStateMachine_SetTopState(STATE_TOP_ANALOG_SHOW_BANNER);
            }
            else
          #if (INPUT_HDMI_VIDEO_COUNT >= 2)
            {
                #if (ENABLE_PIP)
                if(MApp_Get_PIPMode() != EN_PIP_MODE_OFF)
                {
                    MApp_ClosePIPSubWindowSource();
                }
                #endif
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_HDMI2;
                MApp_InputSource_ChangeInputSource(MAIN_WINDOW);

                MApp_ChannelChange_VariableInit();
                MApp_TopStateMachine_SetTopState(STATE_TOP_ANALOG_SHOW_BANNER);
            }
          #else
            {
                MApp_ZUI_ACT_Startup_ChannelInfo_OSD();
                if (IsAnyTVSourceInUse())
                {
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_BRIEF_CH_INFO);
                    //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_TV_BANNER);
                }
                else
                {
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_SOURCE_BANNER);
                }
            }
          #endif
            u8KeyCode = KEY_NULL;
            break;
      #endif
      #if (INPUT_SCART_VIDEO_COUNT > 0)
        case KEY_SCART:
            if (!IsSrcTypeScart(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
            {
                #if (ENABLE_PIP)
                if(MApp_Get_PIPMode() != EN_PIP_MODE_OFF)
                {
                    MApp_ClosePIPSubWindowSource();
                }
                #endif
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_SCART;
                MApp_InputSource_ChangeInputSource(MAIN_WINDOW);

                MApp_ChannelChange_VariableInit();
                MApp_TopStateMachine_SetTopState(STATE_TOP_ANALOG_SHOW_BANNER);
            }
            else
            {
                MApp_ZUI_ACT_Startup_ChannelInfo_OSD();
                if (IsAnyTVSourceInUse())
                {
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_BRIEF_CH_INFO);
                    //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_TV_BANNER);
                }
                else
                {
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_SOURCE_BANNER);
                }
            }
            u8KeyCode = KEY_NULL;
            break;
      #endif
      #if (INPUT_AV_VIDEO_COUNT > 0)
        case KEY_AV:
            if (!IsSrcTypeAV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
            {
                #if (ENABLE_PIP)
                if(MApp_Get_PIPMode() != EN_PIP_MODE_OFF)
                {
                    MApp_ClosePIPSubWindowSource();
                }
                #endif
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_AV;
                MApp_InputSource_ChangeInputSource(MAIN_WINDOW);

                MApp_ChannelChange_VariableInit();
                MApp_TopStateMachine_SetTopState(STATE_TOP_ANALOG_SHOW_BANNER);
            }
            else
            {
                MApp_ZUI_ACT_Startup_ChannelInfo_OSD();
                if (IsAnyTVSourceInUse())
                {
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_BRIEF_CH_INFO);
                    //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_TV_BANNER);
                }
                else
                {
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_SOURCE_BANNER);
                }
            }
            u8KeyCode = KEY_NULL;
            break;
      #endif
      #if (INPUT_SV_VIDEO_COUNT > 0)
        case KEY_SV:
            if (!IsSrcTypeSV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
            {
                #if (ENABLE_PIP)
                if(MApp_Get_PIPMode() != EN_PIP_MODE_OFF)
                {
                    MApp_ClosePIPSubWindowSource();
                }
                #endif
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_SVIDEO;
                MApp_InputSource_ChangeInputSource(MAIN_WINDOW);

                MApp_ChannelChange_VariableInit();
                MApp_TopStateMachine_SetTopState(STATE_TOP_ANALOG_SHOW_BANNER);
            }
            else
            {
                MApp_ZUI_ACT_Startup_ChannelInfo_OSD();
                if (IsAnyTVSourceInUse())
                {
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_BRIEF_CH_INFO);
                    //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_TV_BANNER);
                }
                else
                {
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_SOURCE_BANNER);
                }
            }
            u8KeyCode = KEY_NULL;
            break;
            ///////////////////////////////////////////
      #endif
        case KEY_TV_INPUT:
            enTVState = STATE_TV_INIT;
            enTVRetVal = EXIT_GOTO_MENU;
            break;

        // change it on 20090819
        /*
        case KEY_NULL:
            if (IsAnyTVSourceInUse())
                MApp_TV_Monitor();
            if(IsSrcTypeAnalog(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)) || IsSrcTypeHDMI(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)) || IsSrcTypeAV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)) || IsSrcTypeSV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)) || IsSrcTypeScart(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
                    MApp_AnalogInputs_MonitorWindows(MAIN_WINDOW);
            if((MApp_Get_PIPMode() != EN_PIP_MODE_OFF) && (IsSrcTypeAnalog(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW)) || IsSrcTypeHDMI(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW)) || IsSrcTypeAV(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW)) || IsSrcTypeSV(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW)) || IsSrcTypeScart(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW))))
                    MApp_AnalogInputs_MonitorWindows(SUB_WINDOW);
            break;
        */


        //For Sleep Timer
        case KEY_SLEEP:
            if (MApp_ZUI_GetActiveOSD() != E_OSD_HOTKEY_OPTION)
            {
                MApp_ZUI_ACT_StartupOSD(E_OSD_HOTKEY_OPTION);
            }
            else
            {
                MApp_TV_ProcessHotkeyOptionKey(u8KeyCode);
            }
            MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_SLEEP_HOTKEY);
            u32TVModeWinTimer = msAPI_Timer_GetTime0();
            MApp_AnalogInputs_ResetTimer(MAIN_WINDOW);
            #if (ENABLE_PIP)
            if(MApp_Get_PIPMode() != EN_PIP_MODE_OFF)
            {
                MApp_AnalogInputs_ResetTimer(SUB_WINDOW);
            }
            #endif
            u8KeyCode = KEY_NULL;
          #if ENABLE_AUTOTEST
            if (g_bAutobuildDebug)
            {
                printf("91_KEY_SLEEP\n");
            }
          #endif
            break;
#if (BRAZIL_CC == 1) && (CC_TESTING_SOURCE != 0)
        case KEY_YELLOW:
            printf("received yellow key....\n");
            u8KeyCode = KEY_NULL;
            u8TestCC = 1;
            break;

        case KEY_BLUE:
            printf("received blue key....\n");
            u8TestCC = 2;
            u8KeyCode = KEY_NULL;
            break;
#endif
#if ENCODE_AUDIO_AP
        case KEY_YELLOW:
            {
//#if ENCODE_AUDIO_AP
                extern U8 g_test_encode;
                if(g_test_encode == 0x01)
                {
                    printf("\n\nStop encode test ...\n");
                    MApi_AUDIO_SetEncCommand(AU_DVB_ENCCMD_STOP);
                    g_test_encode = 0x02;
                }
                else
                {
                    printf("\n\nStart encode test ...\n");
                    MApi_AUDIO_SetEncCommand(AU_DVB_ENCCMD_START);
                    g_test_encode = 0x01;
                }
//#endif
                u8KeyCode = KEY_NULL;
            }
            break;
#endif

      #ifdef AP_COWORK
        case KEY_BLUE:
/*
          #if ENABLE_SUBTITLE
            if ( ((u8SubtitleMenuNum > 0)&&(stGenSetting.g_SysSetting.fEnableSubTitle == TRUE)))
            {
                MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_FUNC_NOT_AVAIL_MSGBOX);
            }
            else
          #endif
            {
                if (MApp_APEngine_CheckAPStatus()>>1)
                {
                    printf("\nCOWORK RUNS ALREADY\n");
                }
                else
                {
                    MApp_APEngine_Start();
                    MApp_APEngine_SetAPCowork(TRUE);
                  #ifdef ENABLE_RSS
                    MApp_APEngine_RegisterByID(BIN_ID_CODE_AEON_RSS, FULL_HANDLE, ((BEON_MEM_MEMORY_TYPE & MIU1) ? (BEON_MEM_ADR | MIU_INTERVAL) : ( BEON_MEM_ADR)), BEON_MEM_LEN);
                    //msAPI_APEngine_AppRunByBinID(BIN_ID_CODE_AEON_RSS, ((BEON_MEM_MEMORY_TYPE & MIU1) ? (BEON_MEM_ADR | MIU_INTERVAL) : ( BEON_MEM_ADR)), BEON_MEM_LEN);
                  #endif
                }
            }
*/
            u8KeyCode = KEY_NULL;

            break;
      #endif

        case KEY_PICTURE:
        		#ifdef sAddIRPictureKey
            if (MApp_ZUI_GetActiveOSD() != E_OSD_HOTKEY_OPTION)
            {
                MApp_ZUI_ACT_StartupOSD(E_OSD_HOTKEY_OPTION);
            }
            MApp_TV_ProcessHotkeyOptionKey(u8KeyCode);

            u32TVModeWinTimer = msAPI_Timer_GetTime0();
            MApp_AnalogInputs_ResetTimer(MAIN_WINDOW);
            u8KeyCode = KEY_NULL;        		
        		#else
            #if (ENABLE_PIP)
            if(IsPIPSupported())
            {
                if (MApp_ZUI_GetActiveOSD() != E_OSD_HOTKEY_OPTION)
                {
                    MApp_ZUI_ACT_StartupOSD(E_OSD_HOTKEY_OPTION);
                }
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_PIP_HOTKEY);
                MApp_TV_ProcessHotkeyOptionKey(u8KeyCode);

                u32TVModeWinTimer = msAPI_Timer_GetTime0();
                MApp_AnalogInputs_ResetTimer(MAIN_WINDOW);
                if(MApp_Get_PIPMode() != EN_PIP_MODE_OFF)
                {
                    MApp_AnalogInputs_ResetTimer(SUB_WINDOW);
                }
            }
            #endif
            #endif
          #if ENABLE_AUTOTEST
            if (g_bAutobuildDebug)
            {
                printf("91_KEY_PIP\n");
            }
          #endif
            u8KeyCode = KEY_NULL;
            break;

        case KEY_REVEAL:
            if (MApp_ZUI_GetActiveOSD() != E_OSD_HOTKEY_OPTION)
            {
                MApp_ZUI_ACT_StartupOSD(E_OSD_HOTKEY_OPTION);
            }

            MApp_TV_ProcessHotkeyOptionKey(u8KeyCode);

            u32TVModeWinTimer = msAPI_Timer_GetTime0();
            MApp_AnalogInputs_ResetTimer(MAIN_WINDOW);
          #if (ENABLE_PIP)
            if(MApp_Get_PIPMode() != EN_PIP_MODE_OFF)
            {
                MApp_AnalogInputs_ResetTimer(SUB_WINDOW);
            }
          #endif

          #if ENABLE_AUTOTEST
            if (g_bAutobuildDebug)
            {
                printf("91_KEY_REVEAL\n");
            }
          #endif
            u8KeyCode = KEY_NULL;

            break;

        case KEY_AUDIO:
            if (MApp_ZUI_GetActiveOSD() != E_OSD_HOTKEY_OPTION)
            {
                MApp_ZUI_ACT_StartupOSD(E_OSD_HOTKEY_OPTION);
            }
            MApp_TV_ProcessHotkeyOptionKey(u8KeyCode);

            u32TVModeWinTimer = msAPI_Timer_GetTime0();
            MApp_AnalogInputs_ResetTimer(MAIN_WINDOW);
            #if (ENABLE_PIP)
            if(MApp_Get_PIPMode() != EN_PIP_MODE_OFF)
            {
                MApp_AnalogInputs_ResetTimer(SUB_WINDOW);
            }
            #endif

            u8KeyCode = KEY_NULL;
          #if ENABLE_AUTOTEST
            if(g_bAutobuildDebug)
            {
                printf("91_KEY_AUDIO\n");
            }
          #endif
            break;

        case KEY_FREEZE:
            if (MApp_ZUI_GetActiveOSD() != E_OSD_HOTKEY_OPTION) //ZUI: if(enCurTVWin != DISP_WIN_HKEY_FREEZE)
            {
                MApp_ZUI_ACT_StartupOSD(E_OSD_HOTKEY_OPTION);
            }
            MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_FREEZE_HOTKEY);
            msAPI_Timer_Delayms(5);//wait for sync statble to freeze on off
            MApp_TV_ProcessHotkeyOptionKey(u8KeyCode);

            u32TVModeWinTimer = msAPI_Timer_GetTime0();
            MApp_AnalogInputs_ResetTimer(MAIN_WINDOW);
            #if (ENABLE_PIP)
            if(MApp_Get_PIPMode() != EN_PIP_MODE_OFF)
            {
                MApp_AnalogInputs_ResetTimer(SUB_WINDOW);
            }
            #endif
            u8KeyCode = KEY_NULL;
            break;
#if (ENABLE_SBTVD_BRAZIL_APP || (ATSC_CC == DTV_CC))
    case KEY_CC:
    if (IsATVInUse() || IsAVInUse()  || IsSVInUse() || IsDTVInUse())
    {
        if (MApp_ZUI_GetActiveOSD()!=E_OSD_HOTKEY_OPTION) //ZUI: if (enCurTVWin != DISP_WIN_HKEY_FREEZE) // only display current setting to Hotkey window
        {
            MApp_AnalogInputs_DeleteWin();
            MApp_ZUI_ACT_StartupOSD(E_OSD_HOTKEY_OPTION);
        }

        //MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_CC_HOTKEY);
        MApp_TV_ProcessHotkeyOptionKey(u8KeyCode);
        MApp_AnalogInputs_ResetTimer(SUB_WINDOW);
    }
    u8KeyCode = KEY_NULL;
    break;
#endif
        case KEY_ZOOM:
        case DSC_KEY_ARC4X3://add DiscreteIR
        case DSC_KEY_ARC16X9:
        case DSC_KEY_ARCZOOM:
            #if ENABLE_3D_PROCESS
            if(MApi_XC_Get_3D_Output_Mode() != E_XC_3D_OUTPUT_MODE_NONE)
            {
                u8KeyCode = KEY_NULL;
                break;
            }
            #endif
            #if (ENABLE_PIP)
            if((MApp_Get_PIPMode() == EN_PIP_MODE_OFF) || ((MApp_Get_PIPMode() != EN_PIP_MODE_POP)&&(MApp_Get_PIPMode() != EN_PIP_MODE_POP_FULL)))
            #endif
            {
                if (MApp_ZUI_GetActiveOSD() != E_OSD_HOTKEY_OPTION) //ZUI: enCurTVWin != DISP_WIN_HKEY_ZOOM)
                {
                    MApp_ZUI_ACT_StartupOSD(E_OSD_HOTKEY_OPTION);
                }
                MApp_TV_ProcessHotkeyOptionKey(u8KeyCode);

                u32TVModeWinTimer = msAPI_Timer_GetTime0();
                MApp_AnalogInputs_ResetTimer(MAIN_WINDOW);
                #if (ENABLE_PIP)
                if(MApp_Get_PIPMode() != EN_PIP_MODE_OFF)
                {
                    MApp_AnalogInputs_ResetTimer(SUB_WINDOW);
                }
                #endif
              #if ENABLE_AUTOTEST
                if(g_bAutobuildDebug)
                {
                    printf("91_KEY_ZOOM\n");
                }
              #endif
            }
            u8KeyCode = KEY_NULL;
            break;

        case KEY_MTS:
            //  if ( ( IsDTVInUse() && (MApp_ChannelChange_DetectSignalStatus(UI_INPUT_SOURCE_DTV)==STATE_DETECT_SIGNAL_OK) && (enFrotEndLockStatus!=FRONTEND_UNKNOWN) ) ||
            //     ( IsATVInUse() && (MApp_ChannelChange_DetectSignalStatus(UI_INPUT_SOURCE_ATV)==STATE_DETECT_SIGNAL_OK) && (enFrotEndLockStatus!=FRONTEND_UNKNOWN) ) )
        {
#if ENABLE_ATSC_TTS
            MApp_TTSControlSetInputText(MApp_ZUI_API_GetString(en_str_MTS), MApp_UiMenu_u16Strlen(MApp_ZUI_API_GetString(en_str_MTS)));
            MApp_TTSControlSetOn(TRUE);
#endif
          #if ENABLE_DTV
            if (IsDTVInUse()) //ZUI: if (enCurTVWin != DISP_WIN_HKEY_MTS)
            {
                //ZUI: enCurTVWin = DISP_WIN_HKEY_MTS;
                enTVState = STATE_TV_INIT;
                enTVRetVal = EXIT_GOTO_OSDPAGE;
                MApp_OSDPage_SetOSDPage(E_OSD_AUDIO_LANGUAGE);
            }
            else if (IsATVInUse())
          #else
                 if (IsATVInUse())
          #endif
            {
                MApp_ZUI_ACT_StartupOSD(E_OSD_HOTKEY_OPTION);
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_ATV_MTS_HOTKEY);
                MApp_TV_ProcessHotkeyOptionKey(u8KeyCode);

            }
            else
            {
            		#if(sShowNotAvailableMsg)
                MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_FUNC_NOT_AVAIL_MSGBOX);
                #endif
            }

            u32TVModeWinTimer = msAPI_Timer_GetTime0();
        }
        u8KeyCode = KEY_NULL;
      #if ENABLE_AUTOTEST
        if (g_bAutobuildDebug)
        {
            printf("91_KEY_MTS\n");
        }
      #endif
        break;

      #if ENABLE_TTX
        case KEY_CLOCK:
            // prevent to display TIME window when press TIME key ( no teletext channel )
            if (msAPI_TTX_CheckTTXSignal()==TRUE && msAPI_TTX_CheckTTXClockSignal()
                    #if (ENABLE_PIP)
                    && (MApp_Get_PIPMode() == EN_PIP_MODE_OFF)
                    #endif
               )
            {
            #if PVR_AND_TTX_DIFF_WITH_MHEG5
                if(IsDTVInUse() && !MApp_TTX_CanBeTurnedOn())
                {
                    ;
                }
                else
            #endif
                {
                    MApp_TTX_TeletextCommand(TTX_CLOCK);
                }
                u8KeyCode = KEY_NULL;
                g_u32MonitorTTXClockTimer = msAPI_Timer_GetTime0();
            }
            if ( u8KeyCode != KEY_NULL )
            {
                u8KeyCode = KEY_NULL;
            }
            break;
      #endif

        case KEY_TTX:
#if ENABLE_TTX
    #if(ENABLE_ATSC)
        #if (ENABLE_S2)
            if (IsS2InUse())
            {
                #if 0//ENABLE_PVR
                if (MApp_PVR_IsPlaybacking())
                {
                    return;
                }
                #endif

                //printf("------------- (PIP Mode = 0x%x)\n", (U16)stGenSetting.g_stPipSetting.enPipMode);
                if ( MApp_TTX_GetDefaultTTX_PID() != MSAPI_DMX_INVALID_PID
                     &&msAPI_TTX_CheckTTXSignal()
                 #if PVR_AND_TTX_DIFF_WITH_MHEG5
                     &&MApp_TTX_CanBeTurnedOn()
                 #endif
                 #if (ENABLE_PIP)
                     && (MApp_Get_PIPMode() == EN_PIP_MODE_OFF)
                 #endif
                   )
                {
                    MApi_GOP_GWIN_SetForceWrite(TRUE);
                    _SubmitPalette();
                    MApi_GOP_GWIN_SetForceWrite(FALSE);
                    MApp_TTX_TeletextCommand(TTX_TEXT);
                }
                else
                {
                    MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_NO_TELETEXT_MSGBOX);
                    //ZUI: #endif
                }

            #if ENABLE_MHEG_MSG
             #if (MHEG5_ENABLE && (MHEG5_WITH_SUBTITLE==0) && CIPLUS_MHEG_1_3 == 0)
              #if ENABLE_SUBTITLE
                {
                    //show XX spec, when subtitle up, user need turn off subtitle
                    if ((MApp_SI_CheckMHEG5Status() != SI_MHEG5_DISABLE)
                            &&
                            ( ((u8SubtitleMenuNum > 0)&&(stGenSetting.g_SysSetting.fEnableSubTitle == TRUE)))
                       )
                    {
                        MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
                        MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_MHEG5_SUBTITLE_MSGBOX);
                    }
                }
              #endif // #if ENABLE_SUBTITLE
             #endif // #if (MHEG5_ENABLE && (MHEG5_WITH_SUBTITLE==0))
            #endif // #if ENABLE_MHEG_MSG
            }
            else
        #endif
            {
                MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_NO_TELETEXT_MSGBOX);
            }
    #else
            // teletext
            if ( IsATVInUse() )
            {
                if ( TRUE == msAPI_TTX_CheckTTXSignal()
                        #if (ENABLE_PIP)
                        && (MApp_Get_PIPMode() == EN_PIP_MODE_OFF)
                        #endif
                   )
                {
                    MApi_GOP_GWIN_SetForceWrite(TRUE);
                    _SubmitPalette();
                    MApi_GOP_GWIN_SetForceWrite(FALSE);
                    MApp_TTX_TeletextCommand(TTX_TEXT);
                }
                else
                {

                    MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_NO_TELETEXT_MSGBOX);
                }

            }
        #if ENABLE_DTV
        #if(ENABLE_S2)
            else if (IsDTVInUse()||IsS2InUse())
        #else
            else if ( IsDTVInUse() )
        #endif
            {
                #if 0//ENABLE_PVR
                if (MApp_PVR_IsPlaybacking())
                {
                    return;
                }
                #endif

                //printf("------------- (PIP Mode = 0x%x)\n", (U16)stGenSetting.g_stPipSetting.enPipMode);
                if ( MApp_TTX_GetDefaultTTX_PID() != MSAPI_DMX_INVALID_PID
                     &&msAPI_TTX_CheckTTXSignal()
                 #if PVR_AND_TTX_DIFF_WITH_MHEG5
                     &&MApp_TTX_CanBeTurnedOn()
                 #endif
                 #if (ENABLE_PIP)
                     && (MApp_Get_PIPMode() == EN_PIP_MODE_OFF)
                 #endif
                   )
                {
                    MApi_GOP_GWIN_SetForceWrite(TRUE);
                    _SubmitPalette();
                    MApi_GOP_GWIN_SetForceWrite(FALSE);
                    MApp_TTX_TeletextCommand(TTX_TEXT);
                }
                else
                {
                    MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_NO_TELETEXT_MSGBOX);
                    //ZUI: #endif
                }

            #if ENABLE_MHEG_MSG
             #if (MHEG5_ENABLE && (MHEG5_WITH_SUBTITLE==0) && CIPLUS_MHEG_1_3 == 0)
              #if ENABLE_SUBTITLE
                {
                    //show XX spec, when subtitle up, user need turn off subtitle
                    if ((MApp_SI_CheckMHEG5Status() != SI_MHEG5_DISABLE)
                            &&
                            ( ((u8SubtitleMenuNum > 0)&&(stGenSetting.g_SysSetting.fEnableSubTitle == TRUE)))
                       )
                    {
                        MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
                        MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_MHEG5_SUBTITLE_MSGBOX);
                    }
                }
              #endif // #if ENABLE_SUBTITLE
             #endif // #if (MHEG5_ENABLE && (MHEG5_WITH_SUBTITLE==0))
            #endif // #if ENABLE_MHEG_MSG
            }
        #endif // ENABLE_DTV
            else if (IsVgaInUse() || IsHDMIInUse())
            {
                //ZUI: #if SHOW_NOT_AVAILABLE_WARNING_MESSAGE
                //ZUI:MApp_UiMenu_Show_Warning_Message_Dialog(MENU_FUNCTION_NOT_AVAILABLE_MSG);
                #if(sShowNotAvailableMsg)
                MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_FUNC_NOT_AVAIL_MSGBOX);
                #endif
                //ZUI: #endif
            }
            else
            {
              #if ENABLE_TTX
                if ( TRUE == msAPI_TTX_CheckTTXSignal()
                        #if (ENABLE_PIP)
                        && (MApp_Get_PIPMode() == EN_PIP_MODE_OFF)
                        #endif
                   )
                {
                    MApp_TTX_TeletextCommand(TTX_TEXT);
                }
                else
              #endif
                {

                    MApp_AnalogInputs_DeleteWin();
                    //ZUI: enAnalogInputsState = STATE_ANALOGINPUTS_INIT;
                    //ZUI: enAnalogInputsRetVal = EXIT_GOTO_MENU;
                    //ZUI: enUiMainMenuState = STATE_UIMENU_WAIT;

                    //ZUI: enMenuFlowState=FS_WAIT_MENU;
                    //ZUI: enCurTVWin=DISP_WIN_HKEY_PICTURE;
                    //ZUI: g_u8MenuPageIndex = MENU_NO_TTX_MSG;
                    //ZUI: g_u8MenuMainItemIndex = 0;
                    //ZUI: g_u8MsgPageIndex= g_u8MenuPageIndex;
                    //ZUI: MApp_UiMenu_ShowHotkeyMenu();
                    MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_NO_TELETEXT_MSGBOX);
                }
            }
    #endif
#endif //ENABLE_TTX
            u8KeyCode = KEY_NULL;
            break;

              case KEY_EPG:
#if ENABLE_ATSC_TTS
                  MApp_TTSControlSetInputText(MApp_ZUI_API_GetString(en_str_EPG), MApp_UiMenu_u16Strlen(MApp_ZUI_API_GetString(en_str_EPG)));
                  MApp_TTSControlSetOn(TRUE);
#endif
        #if (ENABLE_ATSC)
              if (IsAtscInUse() || IsATVInUse())
              {
                  U8 SrvNum = MApp_ChanProc_GetNumOfServices(MAIN_LIST);
                  printf("User press EPG key, current SrvNum=%d\n", SrvNum);
                  if(SrvNum)
                  {
                          enTVState = STATE_TV_INIT;
                          enTVRetVal =EXIT_GOTO_EPG;
                  }
                  else
                  {
                  		#if(sShowNotAvailableMsg)
                      MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
                      MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_FUNC_NOT_AVAIL_MSGBOX);
                      #endif
                  }
                  u8KeyCode = KEY_NULL;
                  break;
              }
        #endif


      #if (ENABLE_DTV_EPG)
            if (u16TotalProNum && (IsDTVInUse()
		#if ENABLE_S2
			||IsS2InUse()
		#endif
			))
            {
                if (IS_EPG_DISABLE_COUNTRY(OSD_COUNTRY_SETTING))
                {
                #if ENABLE_MHEG_MSG
                    #if (MHEG5_ENABLE && (MHEG5_WITH_SUBTITLE==0) && CIPLUS_MHEG_1_3 == 0)
                        #if ENABLE_SUBTITLE
                        {
                            //show XX spec, when subtitle up, user need turn off subtitle
                            if ((MApp_SI_CheckMHEG5Status() != SI_MHEG5_DISABLE)&&
                                    ( ((u8SubtitleMenuNum > 0)&&(stGenSetting.g_SysSetting.fEnableSubTitle == TRUE))))
                            {
                                MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
                                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_MHEG5_SUBTITLE_MSGBOX);
                            }
                        }
                        #endif // #if ENABLE_SUBTITLE
                    #endif // #if (MHEG5_ENABLE && (MHEG5_WITH_SUBTITLE==0))
                #endif // #if ENABLE_MHEG_MSG
                }
              #if MHEG5_ENABLE
                MApp_ChannelPosition_Restore();
              #endif
                #if (ENABLE_PIP)
                if (IsPIPSupported())
                {
                    if (MApp_Get_PIPMode() == EN_PIP_MODE_OFF)
                    {
                        enTVState = STATE_TV_INIT;
                        enTVRetVal =EXIT_GOTO_EPG;
                    }
                    else
                    {
                        //PIP behavior: Do not go to EPG if PIP is enabled.
                        //Do nothing here.
                    }
                }
                else
                #endif
                {
                    enTVState = STATE_TV_INIT;
                    enTVRetVal =EXIT_GOTO_EPG;
                }
            }
            else
            {
            		#if(sShowNotAvailableMsg)
                MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_FUNC_NOT_AVAIL_MSGBOX);
                #endif
            }
            u8KeyCode = KEY_NULL;
            break;
      #endif  //#if (ENABLE_DTV_EPG)
      #if (ENABLE_PIP)
        case KEY_PIP:
            //printf("- KEY_PIP\n");
            if (IsPIPSupported())
            {
                if (MApp_ZUI_GetActiveOSD() == E_OSD_SCREEN_SAVER)
                {
                    SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) = EN_SCREENSAVER_NULL;
                    SYS_SCREEN_SAVER_TYPE(SUB_WINDOW) = EN_SCREENSAVER_NULL;
                    MApp_ZUI_ACT_ShutdownOSD();
                }
                MApp_ZUI_ACT_ExecuteMenuItemAction(EN_EXE_INC_PIPMODE);
            }
            u8KeyCode = KEY_NULL;
            break;
      #endif

        default:
            u8KeyCode = KEY_NULL;
            break;

    }
#if (BRAZIL_CC == 1) && (CC_TESTING_SOURCE != 0)
    if(u8TestCC == 1)
    {
        enTVRetVal = EXIT_GOTO_CLOSEDCAPTION;
    }
    else if(u8TestCC == 2)
    {
        u8TestCC = 0;
        MApp_CC_StopParser();
        enTVRetVal = EXIT_GOTO_MENU;
        u8KeyCode = KEY_NULL;
    }
#endif
    //refine here
 #ifdef AP_COWORK
  #if AP_WITH_OSD
    if ( g_bPassTV )
    {
        g_bPassTV = !g_bPassTV;
    }
  #endif
 #endif
}

#if ENABLE_DTV
void Mapp_DTV_ProcessMTS(void)
{
    //ZUI: enCurTVWin = DISP_WIN_HKEY_MTS;
    enTVState = STATE_TV_INIT;
    enTVRetVal = EXIT_GOTO_OSDPAGE;
    MApp_OSDPage_SetOSDPage(E_OSD_AUDIO_LANGUAGE);

    u32TVModeWinTimer = msAPI_Timer_GetTime0();
    u8KeyCode = KEY_NULL;
}
#endif

/******************************************************************************/
static void MApp_TV_Init(void)
{
    enTVState = STATE_TV_WAIT;
}

#if (ENABLE_EASMONITOR)
/*****************************************************************************/
void MAPP_TV_ProcessEAS(void)
{
    if (MApp_Dmx_EAS_GetStatus(&stEAS_info))
    {
        MS_VIRTUAL_CHANNEL *pstCurVirtualCh;

	if(u8KeyCode !=KEY_NULL)
	{
	    u8KeyCode =KEY_NULL;
	}

	if((bIsEASExitUI == FALSE)&&(E_OSD_EMPTY != MApp_ZUI_GetActiveOSD()))
	{
		bIsEASExitUI =TRUE;
		u8KeyCode = KEY_EXIT;
	}
        pstCurVirtualCh = MApp_ChanProc_GetChannelPointer(VIR_CH_IDX(MApp_ChanProc_GetCurMainListProgIndex()));
        if(((pstCurVirtualCh->stVirtualChNum.major_num != stEAS_info.u16MajorNum)
            || (pstCurVirtualCh->stVirtualChNum.minor_num != stEAS_info.u16MinorNum))
            &&(((MApp_TopStateMachine_GetTopState() == STATE_TOP_DIGITALINPUTS)&&(enTVState ==STATE_TV_WAIT ))
            ||(MApp_TopStateMachine_GetTopState() == STATE_TOP_CLOSEDCAPTION)))
        {
            if (!bIsChangeCH)
            {
                stOriginalChNum.major_num = pstCurVirtualCh->stVirtualChNum.major_num;
                stOriginalChNum.minor_num = pstCurVirtualCh->stVirtualChNum.minor_num;
                bIsChangeCH = TRUE;
            }
            stVirtualChNum.major_num = stEAS_info.u16MajorNum;
            stVirtualChNum.minor_num = stEAS_info.u16MinorNum;
            MApp_TV_ChannelChangeProc(&stVirtualChNum, (EN_ANT_TYPE)ANT_TYPE);
            MApp_ChannelChange_EnableChannel(MAIN_WINDOW);
            if (!MApp_ZUI_GetActive_ChannelInfo_OSD())
            {
                MApp_ZUI_ACT_ShutdownOSD();
                MApp_ZUI_ACT_Startup_ChannelInfo_OSD();
            }
            MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_BRIEF_CH_INFO);
            MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_TV_BANNER);
        }

        if ((stEAS_info.u16AlertTextLength > 0)
            &&(MApp_TopStateMachine_GetTopState() == STATE_TOP_DIGITALINPUTS)
            &&(enTVState ==STATE_TV_WAIT ))
        {
        	if(bShowEASUIFlag == FALSE)
    		{
    			MApp_UiMenu_EASWin_Show(stEAS_info.au8AlertText);
			bShowEASUIFlag = TRUE;
    		}
		MApp_UiMenu_EASWin_Update();
        }
    }
    else
    {
	 MApp_UiMenu_EASWin_Hide();
        bShowEASUIFlag = FALSE;
	 bIsEASExitUI = FALSE;

        if(bIsChangeCH)
        {
            MS_VIRTUAL_CHANNEL *pstCurVirtualCh;
            pstCurVirtualCh = MApp_ChanProc_GetChannelPointer(VIR_CH_IDX(MApp_ChanProc_GetCurMainListProgIndex()));
            if((pstCurVirtualCh->stVirtualChNum.major_num == stEAS_info.u16MajorNum)
                && (pstCurVirtualCh->stVirtualChNum.minor_num == stEAS_info.u16MinorNum))
            {
                MApp_TV_ChannelChangeProc(&stOriginalChNum, (EN_ANT_TYPE)ANT_TYPE);
                MApp_ChannelChange_EnableChannel(MAIN_WINDOW);
                if (!MApp_ZUI_GetActive_ChannelInfo_OSD())
                {
                    MApp_ZUI_ACT_ShutdownOSD();
                    MApp_ZUI_ACT_Startup_ChannelInfo_OSD();
                }
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_BRIEF_CH_INFO);
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_TV_BANNER);
            }
            bIsChangeCH = FALSE;
        }
    }
}
/*****************************************************************************/
#endif

/******************************************************************************/
void MApp_TV_ExitAndGotoMenuState(void)
{
    enTVState = STATE_TV_INIT;
}

/******************************************************************************/
#if ENABLE_CI
void MApp_TV_ClearCIFlag(void)
{
#if MHEG5_ENABLE
    if (msAPI_MHEG5_checkGoBackMHEG5()==false)
    {
        enCheckMHEGLoadingStatus = EN_MHEG5_MONITOR;
    }
#endif
}
#endif

/******************************************************************************/

EN_RET MApp_TV(void)
{
    enTVRetVal = EXIT_NULL;

    #if STATE_PRINT
    if (u8KeyCode != 0xFF)
    {
        printf("\r\nenTVState:%d", enTVState);
    }
    #endif

    switch ( enTVState )
    {
        case STATE_TV_INIT:
        #if ENABLE_ATSC_INSTALLGUIDE
          #if ENABLE_WIZARD_MODE
            if ( !stGenSetting.g_SysSetting.fFinishWizardMode )
            {
                if(E_OSD_INSTALL_GUIDE_ATSC != MApp_ZUI_GetActiveOSD())
                {
                    MApp_ZUI_ACT_StartupOSD(E_OSD_INSTALL_GUIDE_ATSC);
                }
                MApp_ZUI_ProcessKey(u8KeyCode);

            #ifdef INSIGNIA_INSTALL_GUIDE_MENU_NEW_STYLE
                if( u8KeyCode == KEY_POWER )
                {
                    enTVState = STATE_TV_INIT;
                    enIdleRetVal = EXIT_TV_TRAN_STANDBY;
                }
            #endif

                u8KeyCode = KEY_NULL;
                return enTVRetVal;
            }
          #endif
        #endif
            MApp_TV_Init();
            if(IsSrcTypeAnalog(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)) || IsSrcTypeHDMI(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)) \
                || IsSrcTypeAV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)) || IsSrcTypeSV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)) || IsSrcTypeScart(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
            {
                MApp_AnalogInputs_Init(MAIN_WINDOW);
            }
            #if (ENABLE_PIP)
            if(IsPIPSupported()&& (MApp_Get_PIPMode() != EN_PIP_MODE_OFF)&&(IsSrcTypeAnalog(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW)) || IsSrcTypeHDMI(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW)) \
                || IsSrcTypeAV(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW)) || IsSrcTypeSV(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW)) || IsSrcTypeScart(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW))))
            {
                MApp_AnalogInputs_Init(SUB_WINDOW);
            }
            #endif
            //refine here

        #ifdef AP_COWORK
          #if AP_WITH_OSD
            if ( g_bGoBack_AP )
            {
                MApp_APEngine_SetGoback();
            }
          #endif
        #endif
            break;

        case STATE_TV_WAIT:
        #if ENABLE_TTX
            if ( MApp_TTX_IsTeletextOn() == TRUE
                #if(ENABLE_PVR)
                &&!((g_PvrMenuPageType == MENU_PVR_TIME_SHIFT) && (MApp_TimeShift_Playback_StateMachineGet() == E_TIMESHIFT_PLAYBACK_STATE_PAUSE))
                #endif
                )
            {
                if(MApp_TTX_Idle_ProcessUserInput())
                    goto PROCESS_USER_INPUT;
            #if ENABLE_CI
                if(msAPI_CI_MMICheckEvent() == CI_EVENT_MMI_ENQ || msAPI_CI_MMICheckEvent() == CI_EVENT_MMI_MENU || msAPI_CI_MMICheckEvent() == CI_EVENT_MMI_LIST)
                {
                    MApp_TTX_TeletextCommand(TTX_TV);
                }
            #endif
            }
            else
        #endif
            {

    #if ENABLE_TTX
        PROCESS_USER_INPUT:
    #endif

                if ( u8KeyCode == KEY_NULL  && ( IsDTVInUse() || IsS2InUse()) )
                {
                #if ENABLE_CI
                    switch (msAPI_CI_MMICheckEvent())
                    {
                            //case CI_EVENT_MMI_ENQ:
                            //case CI_EVENT_MMI_MENU:
                            //case CI_EVENT_MMI_LIST:
                            //enTVState = STATE_TV_INIT;
                            //enTVRetVal = EXIT_GOTO_MMI;
                            //break;

                        case CI_EVENT_NONE:
                            break;

                        default:
                            if(MApp_ParentalControl_GetBlockStatus())
                            {
                                break;
                            }
                            else
                            {
                                enTVState = STATE_TV_INIT;
                                enTVRetVal = EXIT_GOTO_MMI;
                                break;
                            }
                    }
                #endif
                }

                // normal tv case (i.e. not process mheg) or not mheg with osd case (for example STATE_TOP_MENU or STATE_TOP_EPG) -> process key here
                // otherwise, key will be processed in mheg, not here.
                    //MHEG5 or AP_COWORK, let keys pass here

                // change it on 20090819
                if (u8KeyCode == KEY_NULL)
                {
                #if ENABLE_ATSC
                    if(IsAtscInUse()||IsATVInUse()||IsAVInUse())
                    {
                        MApp_TV_MonitorIdleMdoeWindows();
                        MApp_NoSignalAutoSleep_Task();
                    }
                    else if (IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
                #else
                    if(IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW))||IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
                #endif
                    {
                        MApp_TV_Monitor(MAIN_WINDOW);
                    }
                #if (ENABLE_PIP)
                    else if((MApp_Get_PIPMode() != EN_PIP_MODE_OFF)&&(IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW))||IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW))))
                    {
                        MApp_TV_Monitor(SUB_WINDOW);
                    }
                #endif

                    if(IsSrcTypeAnalog(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)) || IsSrcTypeHDMI(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)) || IsSrcTypeAV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)) || IsSrcTypeSV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)) || IsSrcTypeScart(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
                    {
                        MApp_AnalogInputs_MonitorWindows(MAIN_WINDOW);
                    }

                #if (ENABLE_PIP)
                    if((MApp_Get_PIPMode() != EN_PIP_MODE_OFF) && (IsSrcTypeAnalog(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW)) || IsSrcTypeHDMI(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW)) || IsSrcTypeAV(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW)) || IsSrcTypeSV(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW)) || IsSrcTypeScart(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW))))
                    {
                        MApp_AnalogInputs_MonitorWindows(SUB_WINDOW);
                    }
                #endif
                }

            #if ENABLE_ATSC
                if (!fTableVersionChanged)
                {
                        if (IsAtscInUse() || IsATVInUse())
                        {
                            if(MApp_ZUI_GetActiveOSD() != E_OSD_MESSAGE_BOX)
                            {
                                MApp_ZUI_ProcessKey(u8KeyCode);
                            }
                        }
                        MApp_TV_ProcessUserInput();
                }
                else
                {
                    if(MApp_ChanProc_GetCurProgIndex() == INVALID_SERVICE_IDX)
                    {
                        fTableVersionChanged = FALSE;
                        u8KeyCode = KEY_CHANNEL_RETURN;
                        break;
                    }

                    MApp_Dmx_DisableTableMonitor_ATSC();
                    stVirtualChNum.major_num = stChSetting.astMainList[MApp_ChanProc_GetCurProgIndex()].u8PhysicalChIdx;

                    u8ManualScanStatus = TRUE;//test by samuel

                    enTVState = STATE_TV_INIT;
                    enTVRetVal = EXIT_GOTO_ATSC_SCAN;
                    u8KeyCode = KEY_NULL;

                    if(E_OSD_CHANNEL_LIST == MApp_ZUI_GetActiveOSD())
                    {
                        MApp_ZUI_ACT_ShutdownOSD();
                    }
                    break;
                }
            #endif // #if ENABLE_ATSC

            #if MHEG5_ENABLE
                if ( ( (MApp_MHEG5_CheckGoMHEG5Process()==FALSE)    // not process mheg
                     || (msAPI_MHEG5_checkGoBackMHEG5())
                     || (IS_EPG_DISABLE_COUNTRY(OSD_COUNTRY_SETTING))
                     || (IS_NOT_MHEG5_COUNTRY(OSD_COUNTRY_SETTING)) )
                  #if ENABLE_SUBTITLE
                   ||( (stGenSetting.g_SysSetting.fEnableSubTitle == TRUE) && u8SubtitleMenuNum
                    #if CIPLUS_MHEG_1_3
                     &&(msAPI_MHEG5_GoMHEGWhenSubtitleOn() == 0)
                    #endif
                        )
                  #endif
                   )  // process mheg, but the mheg5 state is STATE_TOP_MENU / STATE_TOP_EPG (i.e. MHEG_WITH_OSD case)
            #endif // #if MHEG5_ENABLE
                {
                #ifdef AP_COWORK
                    if(MApp_APEngine_KeyBypass())
                #endif
                    {
                    #if (!ENABLE_ATSC)
                        MApp_TV_ProcessUserInput();
                    #endif
                    }
                }

            #if ENABLE_OAD
                if (MApp_OAD_IsDownloadAvailable()&&MApp_OAD_IsUserSelectOn())
                {
                    enTVRetVal = EXIT_GOTO_OAD;
                    if((OSD_COUNTRY_SETTING == OSD_COUNTRY_NEWZEALAND)
                        && (MApp_OAD_GetSignalForStandby() == TRUE))
                    {
                        //MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_DSI_INIT); //cyber
                        MApp_OAD_SetAppState(EN_OAD_APP_STATE_YES);
                    }
                    else
                    {
                        MApp_OAD_SetAppState(EN_OAD_APP_STATE_INIT) ;
                    }
                }
            #endif

            #if (ENABLE_UPDATE_MULTIPLEX_VIA_NIT)
                _MApp_TV_LossSignal_CheckOriginalRF();
                _MApp_TV_CheckNetworkChange();
            #endif
            }
            break;

        default:
            break;
    }

    return enTVRetVal;
}

/******************************************************************************/
/* unused function:
EN_DISP_WINDOW_TYPE MApp_TV_GetCurTVWin(void)
{
   return enCurTVWin;
}
*/

//////////////////////////////////////////////////////////
//ZUI: moved from MApp_UiMenu2.c

BOOLEAN MApp_TV_ScreenSaverClear(SCALER_WIN eWindow)
{
    if ((SYS_SCREEN_SAVER_TYPE(eWindow) == EN_SCREENSAVER_NOSIGNAL) && \
            (IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(eWindow)) && (MApp_GetSignalStatus() == SIGNAL_LOCK || MApp_GetSignalStatus() == SIGNAL_UNKNOWN)))
    {
        return TRUE;
    }
    else if ((SYS_SCREEN_SAVER_TYPE(eWindow) == EN_SCREENSAVER_UNSUPPORT_MODE) && (IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(eWindow)) && !MApi_XC_IsBlackVideoEnable(eWindow)))
    {
        return TRUE;
    }
#if ENABLE_DVB
    else if ((SYS_SCREEN_SAVER_TYPE(eWindow) == EN_SCREENSAVER_NODATABASE) && ((msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY)+msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY))!=0))
    {
        return TRUE;
    }
    else if ((SYS_SCREEN_SAVER_TYPE(eWindow) == EN_SCREENSAVER_AUDIOONLY) && (msAPI_CM_GetCurrentServiceType() != E_SERVICETYPE_RADIO))
    {
        return TRUE;
    }
    else if ((SYS_SCREEN_SAVER_TYPE(eWindow) == EN_SCREENSAVER_SCRAMBLE) && (!MApp_Scramble_GetCurStatus()))
    {
        return TRUE;
    }
    else if ((SYS_SCREEN_SAVER_TYPE(eWindow) == EN_SCREENSAVER_SCRAMBLED_PROGRAM) && (!MApp_Scramble_GetCurStatus()))
    {
        return TRUE;
    }
    else if ((SYS_SCREEN_SAVER_TYPE(eWindow) == EN_SCREENSAVER_NOT_RUNNING1)
             && (FALSE==msAPI_CM_GetProgramAttribute(msAPI_CM_GetCurrentServiceType(), msAPI_CM_GetCurrentPosition(msAPI_CM_GetCurrentServiceType()), E_ATTRIBUTE_IS_SERVICE_ID_ONLY)) )
    {
        return TRUE;
    }
    else if ((SYS_SCREEN_SAVER_TYPE(eWindow) == EN_SCREENSAVER_NOT_RUNNING2)
             && (MApp_TV_IsProgramRunning()))
    {
        return TRUE;
    }
  #if (ENABLE_DTV_EPG)
    else if ((SYS_SCREEN_SAVER_TYPE(eWindow) == EN_SCREENSAVER_BLOCKRATING) && (MApp_ParentalControl_GetBlockStatus() == 0))
    {
        return TRUE;
    }
  #endif
#endif
#if ENABLE_PVR
    else if (MApp_PVR_IsPlaybacking())
    {
        return TRUE;
    }
#endif

    if(IsSrcTypeAnalog(SYS_INPUT_SOURCE_TYPE(eWindow))||IsSrcTypeHDMI(SYS_INPUT_SOURCE_TYPE(eWindow)))
    {
        if ((SYS_SCREEN_SAVER_TYPE(eWindow)==EN_SCREENSAVER_NOCABLE))
        {
            return TRUE;
        }
        else if ((SYS_SCREEN_SAVER_TYPE(eWindow)==EN_SCREENSAVER_NOSYNC) && (!MApi_XC_PCMonitor_SyncLoss(eWindow)))
        {
            return TRUE;
        }
        else if ((SYS_SCREEN_SAVER_TYPE(eWindow)==EN_SCREENSAVER_UNSUPPORT_MODE) /*&& printf("%s-%d: query PC mode state\n", __FILE__, __LINE__ )*/ && (MApp_PCMode_GetCurrentState(MAIN_WINDOW) == E_PCMODE_STABLE_SUPPORT_MODE))
        {
            return TRUE;
        }
    }
    else
    {
        if ((SYS_SCREEN_SAVER_TYPE(eWindow)==EN_SCREENSAVER_NOSYNC_VD) && (IsVDHasSignal()==TRUE))
        {
            return TRUE;
        }
        else if ((SYS_SCREEN_SAVER_TYPE(eWindow)==EN_SCREENSAVER_NO_SHOW_PROGRAM) && IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(eWindow)))
        {
            return TRUE;
        }
        else if ((SYS_SCREEN_SAVER_TYPE(eWindow)==EN_SCREENSAVER_NO_SHOW_PROGRAM) && (IsVDHasSignal()==TRUE))
        {
            return TRUE;
        }
    }
    return FALSE;
}

#if ENABLE_DVB
// To fix Mantis 969998.
// If this TV program demod is locked, but it is no video PID and no audio, we will show a "Invalid service".
BOOLEAN MApp_TV_IsInvalidService(void)
{
      if (
      #if MHEG5_ENABLE
          (!msAPI_MHEG5_IsMHEGDraw()) &&
      #endif
          (msAPI_CM_GetVideoPID(msAPI_CM_GetCurrentServiceType(),msAPI_CM_GetCurrentPosition(msAPI_CM_GetCurrentServiceType())) == MSAPI_DMX_INVALID_PID) &&
          (!MApi_AUDIO_IsMadLock())
         )
          return TRUE;
      else
      {
          u8InvalidServiceCount=0;
          return FALSE;
      }
}
#endif

BOOLEAN MApp_TV_IsProgramRunning(void)
{
#if ENABLE_DVB
    BOOLEAN bRepacement,bRunning;
    bRunning = MApp_SI_Is_Running(&bRepacement);
    if ((bRepacement == FALSE))// && !(IS_DTG_COUNTRY(OSD_COUNTRY_SETTING) ||IS_NORDIC_COUNTRY(OSD_COUNTRY_SETTING)))
    {
        if ((enMVDVideoStatus == MVD_GOOD_VIDEO) || MApi_AUDIO_IsMadLock())
        {
            return TRUE;
        }
    }
    return bRunning;
#else
    return TRUE;
#endif
}
#if (ENABLE_UPDATE_MULTIPLEX_VIA_NIT)
static void _MApp_TV_CheckNetworkChange(void)
{
    if(msAPI_SI_IsSpecificCountry(MApp_GetSICountry(OSD_COUNTRY_SETTING),SI_SUPPORT_NETWORK_UPDATE_SPECIFIC_COUNTRY)
        || msAPI_SI_IsSpecificCountry(MApp_GetSICountry(OSD_COUNTRY_SETTING),SI_SUPPORT_DVB_C_NETWORK_UPDATE_SPECIFIC_COUNTRY))
    {
    #if(ENABLE_S2)
        if ((IsDTVInUse()||IsS2InUse()) && (u8KeyCode == KEY_NULL))
    #else
        if (IsDTVInUse() && (u8KeyCode == KEY_NULL))
    #endif
        {
            BOOLEAN bMuxAdd,bMuxRemove,bCellRemove,bFreqChange;
            MApp_SI_Is_NetworkChange(&bMuxAdd, &bMuxRemove,&bCellRemove,&bFreqChange);
            //if(bMuxAdd||bMuxRemove)printf("bMuxAdd..%d %d\n",bMuxAdd,bMuxRemove);
            if(msAPI_SI_IsSpecificCountry(MApp_GetSICountry(OSD_COUNTRY_SETTING),SI_SUPPORT_DVB_C_NETWORK_UPDATE_SPECIFIC_COUNTRY))
            {
                if(bMuxRemove && (bMuxAdd == FALSE))
                {
                    return;//no need message
                }
            }
            if(bMuxAdd || bMuxRemove || bCellRemove||(bFreqChange && MApp_SI_GetCheckFreqChange()))
            {
                MApp_DTV_Scan_Set_UpdateMethod(bMuxAdd,bMuxRemove,bCellRemove,bFreqChange);
                if(MApp_SI_GetCheckFreqChange()==TRUE)
                {
                    MApp_SI_SetCheckFreqChange(FALSE);
                }
                enTVState = STATE_TV_INIT;
                enTVRetVal = EXIT_GOTO_SCAN_NEW_MUX;//EXIT_TV_TRAN_TT;
            }
        }
    }
}
static void _MApp_TV_LossSignal_CheckOriginalRF(void)
{
    BYTE cRFCh;
#if(ENABLE_S2)
    if((IsDTVInUse()||IsS2InUse()) && (u8KeyCode == KEY_NULL) && (OSD_COUNTRY_SETTING == OSD_COUNTRY_NORWAY))
#else
    if(IsDTVInUse() && (u8KeyCode == KEY_NULL) && (OSD_COUNTRY_SETTING == OSD_COUNTRY_NORWAY))
#endif
    {
        if(_bCheckAlternative)
        {
            _bCheckAlternative = FALSE;

            cRFCh = msAPI_CM_GetOriginalRFnumber(msAPI_CM_GetCurrentServiceType(),msAPI_CM_GetCurrentPosition(msAPI_CM_GetCurrentServiceType()));

            if(cRFCh != INVALID_PHYSICAL_CHANNEL_NUMBER)
            {
                enTVState = STATE_TV_INIT;
                enTVRetVal = EXIT_GOTO_SCAN_NEW_MUX;//EXIT_TV_TRAN_TT;
                MApp_DTV_Scan_SetLossSignalState(LOSS_SIGNAL_RETURN_ORIGINAL_RF);
            }
        }
    }
}
void MApp_TV_SetCheckAlternativeFlag(BOOLEAN bFlag)
{
#if(ENABLE_S2)
    if ((IsDTVInUse()||IsS2InUse()) && (OSD_COUNTRY_SETTING == OSD_COUNTRY_NORWAY))
#else
    if (IsDTVInUse() && (OSD_COUNTRY_SETTING == OSD_COUNTRY_NORWAY))
#endif
    {
        _bCheckAlternative = bFlag;
    }
}
BOOLEAN MApp_TV_GetCheckAlternativeFlag(void)
{
     return _bCheckAlternative;
}
BOOLEAN MApp_TV_CheckLossSignal30Days(void)
{
    U32 u32AlternativeTime,u32seconds;
    BYTE cOriginal_RF, cRFCh;
    MEMBER_SERVICETYPE eCurServiceType;
    WORD wCurPosition;
    BYTE cIndex;

#if(ENABLE_S2)
    if((OSD_COUNTRY_SETTING == OSD_COUNTRY_NORWAY) && (IsDTVInUse()||IsS2InUse()) && (MApp_SI_IS_GotTDTOrTOT()==TRUE))
#else
    if((OSD_COUNTRY_SETTING == OSD_COUNTRY_NORWAY) && IsDTVInUse() && (MApp_SI_IS_GotTDTOrTOT()==TRUE))
#endif
    {
        eCurServiceType = msAPI_CM_GetCurrentServiceType();
        wCurPosition = msAPI_CM_GetCurrentPosition(eCurServiceType);
        u32seconds = msAPI_Timer_GetSystemTime();
        cOriginal_RF = msAPI_CM_GetOriginalRFnumber(eCurServiceType, wCurPosition);
        cRFCh =  msAPI_CM_GetPhysicalChannelNumber(eCurServiceType,wCurPosition);
        cIndex = msAPI_CM_Get_RFChannelIndex(cRFCh);
        u32AlternativeTime = msAPI_CM_GetIDTable(cIndex,(BYTE *)&u32AlternativeTime, E_DATA_ALTERNATIVE_TIME);
        if(cOriginal_RF != INVALID_PHYSICAL_CHANNEL_NUMBER && u32AlternativeTime == 0 && u32seconds != 0)
        {
            msAPI_CM_SetIDTable(cIndex,(BYTE *)&u32seconds, E_DATA_ALTERNATIVE_TIME);
            return FALSE;
        }
        if(u32seconds > (u32AlternativeTime+SECONDS_PER_30DAYS))
        {
            msAPI_CM_ResetOriginalRFnumber(eCurServiceType, wCurPosition);
            msAPI_CM_ResetAlternativeTime(eCurServiceType, wCurPosition);
            return TRUE;
        }
    }
    return FALSE;
}
#endif

BOOLEAN MApp_Get_CheckParentalPWStatus(void)
{
    return bCheckParentalPW;
}
void MApp_Set_CheckParentalPWStatus(BOOLEAN bStatus)
{
    bCheckParentalPW = bStatus;
}

#if ENABLE_EPGTIMER_RECORDER_TURNOFFPANEL
void MApp_SetActiveStandbyMode(BOOL bActive)
{
    if(bActive)
    {
    #if ENABLE_OAD
        if(!MApp_OAD_IsScheduleOnCheck())
    #endif
        {
            g_bTimerActiveStandbyMode = TRUE;
        }
        msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_INTERNAL_3_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
        msAPI_Timer_Delayms(20);
				#ifdef sNewAudioMuteStyle
				msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, 0, 0);
				#else        
        MUTE_On();
        #endif
        MApi_PNL_SetBackLight(DISABLE);
        MApi_PNL_En(FALSE);
    }
    else
    {
        g_bTimerActiveStandbyMode = FALSE;
        MApi_PNL_En(TRUE);
        MApi_PNL_SetBackLight(ENABLE);
        msAPI_Timer_Delayms(20);
        msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_INTERNAL_3_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
				#ifdef sNewAudioMuteStyle
				msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, stGenSetting.g_SoundSetting.Volume, 0);
				#else
				MUTE_Off();
				#endif
    }
}

BOOLEAN MApp_GetActiveStandbyMode(void)
{
    if(g_bTimerTypeRecord
#if ENABLE_CI_PLUS
    || g_bTimeTypeOpRefresh
#endif
    )
    {
        return g_bTimerActiveStandbyMode;
    }
    else
    {
        return FALSE;
    }
}
#endif

void MApp_Set_IdleInputValue(U16 u16NewInputVal)
{
    u16IdleInputValue = u16NewInputVal;
}

U16 MApp_Get_IdleInputValue(void)
{
    return u16IdleInputValue;
}

void MApp_Set_IdleDigitCount(U8 u8NewCount)
{
    u8IdleDigitCount = u8NewCount;
}

U8 MApp_Get_IdleDigitCount(void)
{
    return u8IdleDigitCount;
}

#if (ENABLE_ATSC)
#if ENABLE_ATSC_INSTALLGUIDE
void MApp_TV_ResetTvState( void )
{
    enTVState = STATE_TV_INIT;
}

void MApp_TV_ExecuteAutoScan( void )
{
    enTVRetVal = EXIT_GOTO_MENU;
}
#endif
#endif

#undef MAPP_TV_C

