//<MStar Software>
//******************************************************************************
// MStar Software
// Copyright (c) 2010 - 2012 MStar Semiconductor, Inc. All rights reserved.
// All software, firmware and related documentation herein ("MStar Software") are
// intellectual property of MStar Semiconductor, Inc. ("MStar") and protected by
// law, including, but not limited to, copyright law and international treaties.
// Any use, modification, reproduction, retransmission, or republication of all
// or part of MStar Software is expressly prohibited, unless prior written
// permission has been granted by MStar.
//
// By accessing, browsing and/or using MStar Software, you acknowledge that you
// have read, understood, and agree, to be bound by below terms ("Terms") and to
// comply with all applicable laws and regulations:
//
// 1. MStar shall retain any and all right, ownership and interest to MStar
//    Software and any modification/derivatives thereof.
//    No right, ownership, or interest to MStar Software and any
//    modification/derivatives thereof is transferred to you under Terms.
//
// 2. You understand that MStar Software might include, incorporate or be
//    supplied together with third party`s software and the use of MStar
//    Software may require additional licenses from third parties.
//    Therefore, you hereby agree it is your sole responsibility to separately
//    obtain any and all third party right and license necessary for your use of
//    such third party`s software.
//
// 3. MStar Software and any modification/derivatives thereof shall be deemed as
//    MStar`s confidential information and you agree to keep MStar`s
//    confidential information in strictest confidence and not disclose to any
//    third party.
//
// 4. MStar Software is provided on an "AS IS" basis without warranties of any
//    kind. Any warranties are hereby expressly disclaimed by MStar, including
//    without limitation, any warranties of merchantability, non-infringement of
//    intellectual property rights, fitness for a particular purpose, error free
//    and in conformity with any international standard.  You agree to waive any
//    claim against MStar for any loss, damage, cost or expense that you may
//    incur related to your use of MStar Software.
//    In no event shall MStar be liable for any direct, indirect, incidental or
//    consequential damages, including without limitation, lost of profit or
//    revenues, lost or damage of data, and unauthorized system use.
//    You agree that this Section 4 shall still apply without being affected
//    even if MStar Software has been modified by MStar in accordance with your
//    request or instruction for your use, except otherwise agreed by both
//    parties in writing.
//
// 5. If requested, MStar may from time to time provide technical supports or
//    services in relation with MStar Software to you for your use of
//    MStar Software in conjunction with your or your customer`s product
//    ("Services").
//    You understand and agree that, except otherwise agreed by both parties in
//    writing, Services are provided on an "AS IS" basis and the warranty
//    disclaimer set forth in Section 4 above shall apply.
//
// 6. Nothing contained herein shall be construed as by implication, estoppels
//    or otherwise:
//    (a) conferring any license or right to use MStar name, trademark, service
//        mark, symbol or any other identification;
//    (b) obligating MStar or any of its affiliates to furnish any person,
//        including without limitation, you and your customers, any assistance
//        of any kind whatsoever, or any information; or
//    (c) conferring any license or right under any intellectual property right.
//
// 7. These terms shall be governed by and construed in accordance with the laws
//    of Taiwan, R.O.C., excluding its conflict of law rules.
//    Any and all dispute arising out hereof or related hereto shall be finally
//    settled by arbitration referred to the Chinese Arbitration Association,
//    Taipei in accordance with the ROC Arbitration Law and the Arbitration
//    Rules of the Association by three (3) arbitrators appointed in accordance
//    with the said Rules.
//    The place of arbitration shall be in Taipei, Taiwan and the language shall
//    be English.
//    The arbitration award shall be final and binding to both parties.
//
//******************************************************************************
//<MStar Software>
////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2006-2009 MStar Semiconductor, Inc.
// All rights reserved.
//
// Unless otherwise stipulated in writing, any and all information contained
// herein regardless in any format shall remain the sole proprietary of
// MStar Semiconductor Inc. and be kept in strict confidence
// (��MStar Confidential Information��) by the recipient.
// Any unauthorized act including without limitation unauthorized disclosure,
// copying, use, reproduction, sale, distribution, modification, disassembling,
// reverse engineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
////////////////////////////////////////////////////////////////////////////////

#define MAPP_ZUI_ACTHOTKEY_C
#define _ZUI_INTERNAL_INSIDE_ //NOTE: for ZUI internal


//-------------------------------------------------------------------------------------------------
// Include Files
//-------------------------------------------------------------------------------------------------
// Common Definition
#include "Board.h"
#include "datatype.h"
#include "MsCommon.h"
#include "apiXC.h"
#include "apiXC_Adc.h"
#include "MApp_GlobalSettingSt.h"

#include "msAPI_Video.h"

#include "MApp_ZUI_Main.h"
#include "MApp_ZUI_APIcommon.h"
#include "MApp_ZUI_APIstrings.h"
#include "MApp_ZUI_APIwindow.h"
#include "ZUI_tables_h.inl"
#include "MApp_ZUI_APIgdi.h"
#include "MApp_ZUI_APIcontrols.h"
#include "MApp_ZUI_ACTeffect.h"
#include "MApp_ZUI_ACTglobal.h"
#include "OSDcp_String_EnumIndex.h"
#include "ZUI_exefunc.h"

#include "MApp_ZUI_ACThotkey.h"
#include "MApp_UiMenuDef.h"
#include "MApp_SaveData.h"
#include "MApp_Sleep.h"
#include "MApp_GlobalFunction.h"
#include "MApp_Scaler.h"
#include "MApp_XC_PQ.h"
#include "msAPI_audio.h"
#include "MApp_MVDMode.h"
#include "MApp_TopStateMachine.h"
#include "MApp_ZUI_ACTmenufunc.h"
#if MHEG5_ENABLE
#include "MApp_MHEG5_Main.h"
#endif
#include "msAPI_Timer.h"
#include "MApp_PCMode.h"
#include "apiXC.h"
#include "MApp_XC_PQ.h"
#include "MApp_InputSource.h"
#include "MApp_Audio.h"
#if ENABLE_TTX
#include "mapp_ttx.h"
#endif
#if (MWE_FUNCTION)
#include "apiXC_Ace.h"
#endif
#include "drvPQ.h"
#include "apiXC_Sys.h"

//#if ENABLE_T_C_COMBO
#include "MApp_Scan.h"
//#endif
#if (((ENABLE_SBTVD_BRAZIL_APP)&&(BRAZIL_CC))||(ATSC_CC == ATV_CC))
#include "mapp_closedcaption.h"
#endif
#if (NTV_FUNCTION_ENABLE)
#include "msAPI_FreqTableDTV.h"
#endif
#if (ENABLE_PIP)
#include "MApp_ChannelChange.h"
#endif

#if (ENABLE_PIP)
#include "MApp_PIP.h"
#include "mapp_mplayer.h"
#endif

#if (ENABLE_ATSC)
#include "MApp_UiMenuFunc_ATSC.h"
#endif

#if ENABLE_ATSC_TTS
#include "Utl.h"
#include "MApp_TTSControlHandler.h"
#endif
/////////////////////////////////////////////////////////////////////


typedef enum _HOTKEY_MODE
{
    EN_HOTKEY_MODE_INVALID,
    EN_HOTKEY_MODE_SLEEP,
    EN_HOTKEY_MODE_PICTURE,
    EN_HOTKEY_MODE_AUDIO,
    EN_HOTKEY_MODE_SCALE,
    EN_HOTKEY_MODE_ATV_MTS,
    EN_HOTKEY_MODE_FREEZE,
    EN_HOTKEY_MODE_CC,
    EN_HOTKEY_MODE_PIP,
    EN_HOTKEY_MODE_VOLUME,		//Ray HKY 2017.09.27: Add volume hot key mode
    EN_HOTKEY_MODE_BRIGHTNESS,		//Ray HKY 2017.09.27: Add brightness hot key mode
    EN_HOTKEY_MODE_INPUT,		//Ray HKY 2017.10.17: Input source hot key mode
    EN_HOTKEY_MODE_BACKLIGHT,		//Ray HKY 2017.10.17: backlight hot key mode
    EN_HOTKEY_MODE_CONTRAST,		//Ray HKY 2017.10.17: contrast hot key mode
    EN_HOTKEY_MODE_SATURATION,		//Ray HKY 2017.10.17: saturation hot key mode
    EN_HOTKEY_MODE_HUE,			//Ray HKY 2017.10.17: hue hot key mode
    EN_HOTKEY_MODE_SHARPNESS,		//Ray HKY 2017.10.17: sharpness hot key mode
    EN_HOTKEY_MODE_ASPECT_RATIO,	//Ray HKY 2017.10.17: aspect ratio hot key mode
} HOTKEY_MODE;

static HOTKEY_MODE _eHotkeyMode;
extern AUDIOMODE_TYPE   m_eAudioMode;


extern BOOLEAN _MApp_ZUI_API_AllocateVarData(void);

//Ray HKY 2017.09.28: External function for hot key function control
extern BYTE g_ucSerialAcknowledge;
extern void dv_Serial_Volume_Para1(BYTE *ucCmdPara);
extern void dv_Serial_Contrast_Para1(BYTE *uartCmd);
extern void dv_Serial_Brightness_Para0(BYTE uartCmd);
extern void dv_Serial_Source_Para0(BYTE uartCmd);
extern void dv_Serial_BackLightControl_Para0(BYTE uartCmd);
extern void dv_Serial_ColorSat_Para0(BYTE uartCmd);
extern void dv_Serial_Hue_Para0(BYTE uartCmd);
extern void dv_Serial_Sharpness_Para0(BYTE uartCmd);
extern void dv_Serial_ScaleMode_Para0(BYTE uartCmd);

extern U16 MApp_ZUI_GetCurrentInputSourceStringID(E_UI_INPUT_SOURCE src);
extern U16 _MApp_ZUI_ACT_GetAspectRatioStringID(void);

#if ENABLE_DTV
extern void Mapp_DTV_ProcessMTS(void);
#endif


HOTKEY_TYPE eHotKeyType = HotKeyTypeNone;  //Ray HKY 2017.10.20: variable storing currnet hot key type in either 1 (-ve/+ve) or 2 (up/down)


//Ray HKY 2017.10.20: Function to set hot key type in either 1 (-ve/+ve) or 2 (up/down) or none
//Input: type of hotkey: HotKeyTypeNone, HotKeyType1 or HotKeyType2
void MApp_ZUI_ACT_SetHotKeyType(HOTKEY_TYPE type)
{
  eHotKeyType = type;
}

//Ray HKY 2017.10.20: Function to get hot key type in either 1 (-ve/+ve) or 2 (up/down) or none
//Output: type of hotkey: HotKeyTypeNone, HotKeyType1 or HotKeyType2
HOTKEY_TYPE MApp_ZUI_ACT_GetHotKeyType(void)
{
  return eHotKeyType;
}


void MApp_ZUI_ACT_AppShowHotkeyOption(void)
{
    HWND wnd;
    RECT rect;
    E_OSD_ID osd_id = E_OSD_HOTKEY_OPTION;

    g_GUI_WindowList = GetWindowListOfOsdTable(osd_id);
    g_GUI_WinDrawStyleList = GetWindowStyleOfOsdTable(osd_id);
    g_GUI_WindowPositionList = GetWindowPositionOfOsdTable(osd_id);
#if ZUI_ENABLE_ALPHATABLE
    g_GUI_WinAlphaDataList = GetWindowAlphaDataOfOsdTable(osd_id);
#endif
    HWND_MAX = GetWndMaxOfOsdTable(osd_id);
    OSDPAGE_BLENDING_ENABLE = IsBlendingEnabledOfOsdTable(osd_id);
    OSDPAGE_BLENDING_VALUE = GetBlendingValueOfOsdTable(osd_id);

    if (!_MApp_ZUI_API_AllocateVarData())
    {
        ZUI_DBG_FAIL(printf("[ZUI]ALLOC\n"));
        ABORT();
        return;
    }

    RECT_SET(rect,
        ZUI_HOTKEY_OPTION_XSTART, ZUI_HOTKEY_OPTION_YSTART,
        ZUI_HOTKEY_OPTION_WIDTH, ZUI_HOTKEY_OPTION_HEIGHT);

    if (!MApp_ZUI_API_InitGDI(&rect))
    {
        ZUI_DBG_FAIL(printf("[ZUI]GDIINIT\n"));
        ABORT();
        return;
    }

    for (wnd = 0; wnd < HWND_MAX; wnd++)
    {
        //printf("create msg: %lu\n", (U32)wnd);
        MApp_ZUI_API_SendMessage(wnd, MSG_CREATE, 0);
    }

    MApp_ZUI_API_ShowWindow(HWND_MAINFRAME, SW_SHOW);
    _eHotkeyMode = EN_HOTKEY_MODE_INVALID;

    //MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_PAGE_SHOWUP, E_ZUI_STATE_RUNNING);

}


//////////////////////////////////////////////////////////
// Key Handler

BOOLEAN MApp_ZUI_ACT_HandleHotkeyOptionKey(VIRTUAL_KEY_CODE key)
{
    //note: don't do anything here! keys will be handled in state machines
    //      moved to MApp_TV_ProcessAudioVolumeKey()
    UNUSED(key);
    ZUI_DBG_FAIL(printf("[ZUI]IDLEKEY\n"));
    //ABORT();
    return FALSE;
}

void MApp_ZUI_ACT_TerminateHotkeyOption(void)
{
    ZUI_MSG(printf("[]term:hotkey\n");)
    MApp_ZUI_ACT_SetHotKeyType(HotKeyTypeNone);		//Ray HKY 2017.10.20: Denote it's now no more hot key
    //enHotkeyOptionState = _enTargetHotkeyOptionState;

}
#if (ENABLE_3D_PROCESS)
extern void _MApp_ZUI_ACT_DecInc_3D_AspectRatio_Cycle(BOOLEAN bInc);
#endif
extern void _MApp_ZUI_ACT_DecIncAspectRatio_Cycle(BOOLEAN bInc);

void _MApp_ZUI_ACT_DecIncSleepTimer_Cycle(BOOLEAN bInc)
{
    //from case MAPP_UIMENUFUNC_ADJTIMESLEEP:
    stLMGenSetting.stMD.enD4_SleepTimer = MApp_Sleep_GetCurrentSleepState();
    stLMGenSetting.stMD.enD4_SleepTimer = (EN_SLEEP_TIME_STATE)MApp_ZUI_ACT_DecIncValue_Cycle(
        bInc,
        stLMGenSetting.stMD.enD4_SleepTimer,
        STATE_SLEEP_OFF, STATE_SLEEP_TOTAL-1, 1);
    enSleepTimeState=(EN_SLEEP_TIME_STATE)(U8)stLMGenSetting.stMD.enD4_SleepTimer;
    MApp_Sleep_SetCurrentSleepTime(enSleepTimeState);
}

//Ray HKY 2017.10.17: increase/decrease hot key value calling RS-232 Para1 routine based on hot key mode _eHotkeyMode
//Input: bInc =1 for increase, = 0 or decrease
void _MApp_ZUI_ACT_DecIncDVHotKeyPara1(BOOLEAN bInc)
{
  BYTE uartCmd[]={'A','+'};
  BYTE ackBackup;

  if(bInc==0){
      uartCmd[1]='-';
  }

  ackBackup = g_ucSerialAcknowledge;		//backup ack uart cmd status
  g_ucSerialAcknowledge = FALSE;		//No tx of cmd to uart
  switch(_eHotkeyMode){
    case EN_HOTKEY_MODE_VOLUME:
      dv_Serial_Volume_Para1(uartCmd);
      break;
    case EN_HOTKEY_MODE_CONTRAST:
      dv_Serial_Contrast_Para1(uartCmd);
      break;
    default:
      break;
  }

  g_ucSerialAcknowledge = ackBackup;

}


//Ray HKY 2017.10.17: increase/decrease hot key value calling RS-232 Para0 routine based on hot key mode _eHotkeyMode
//Input: bInc =1 for increase, = 0 or decrease
void _MApp_ZUI_ACT_DecIncDVHotKeyPara0(BOOLEAN bInc)
{
  BYTE uartCmd='+';
  BYTE ackBackup;

  if(bInc==0){
      uartCmd='-';
  }

  ackBackup = g_ucSerialAcknowledge;		//backup ack uart cmd status
  g_ucSerialAcknowledge = FALSE;		//No tx of cmd to uart

  switch(_eHotkeyMode){
    case EN_HOTKEY_MODE_BRIGHTNESS:
      dv_Serial_Brightness_Para0(uartCmd);
      break;
    case EN_HOTKEY_MODE_INPUT:
      dv_Serial_Source_Para0(uartCmd);
      break;
    case EN_HOTKEY_MODE_BACKLIGHT:
      dv_Serial_BackLightControl_Para0(uartCmd);
      break;
    case EN_HOTKEY_MODE_SATURATION:
      dv_Serial_ColorSat_Para0(uartCmd);
      break;
    case EN_HOTKEY_MODE_HUE:
      dv_Serial_Hue_Para0(uartCmd);
      break;
    case EN_HOTKEY_MODE_SHARPNESS:
      dv_Serial_Sharpness_Para0(uartCmd);
      break;
    case EN_HOTKEY_MODE_ASPECT_RATIO:
      dv_Serial_ScaleMode_Para0(uartCmd);
      break;
    default:
      break;

  }

  g_ucSerialAcknowledge = ackBackup;		//Restore ack uart cmd status

}


//Ray HKY 2017.10.17: increase/decrease aspect ratio hot key value calling RS-232 routine
//Input: bInc =1 for increase, = 0 or decrease
void _MApp_ZUI_ACT_DecIncDVApectRatioHotKey(BOOLEAN bInc)
{
  EN_MENU_AspectRatio apsectRatioCmd[]={EN_AspectRatio_JustScan,EN_AspectRatio_4X3,EN_AspectRatio_16X9,EN_AspectRatio_Point_to_Point};		//This is aspect ratio sequence in OSD
  BYTE ucARatioIndex;

  //Get current select aspect ratio index
  for(ucARatioIndex=0;ucARatioIndex<4;ucARatioIndex++){
      if(apsectRatioCmd[ucARatioIndex]==ST_VIDEO.eAspectRatio){
	  break;
      }
  }

  //Go to previous/next aspect ratio item
  ST_VIDEO.eAspectRatio = apsectRatioCmd[MApp_ZUI_ACT_DecIncValue_Cycle(bInc,(U16)ucARatioIndex, 0, 3, 1)];
  MApp_Scaler_Setting_SetVDScale( ST_VIDEO.eAspectRatio , MAIN_WINDOW );		//adjust new aspect ratio

}


//Ray HKY 2017.10.17: Set hot key mode, show OSD Hot key title, level ball and value generic routine
//Input: hotkey: HotKey_Input, HotKey_Backlight,......
void _MApp_ZUI_ACT_ShowOSDHotKeyTitleLevel(HOT_KEY hotkey)
{
  BYTE showTitle = TRUE;
  BYTE showText = FALSE;		//For input and aspect ratio, we show text

      switch(hotkey){
	case HotKey_Input:
	  _eHotkeyMode = EN_HOTKEY_MODE_INPUT;
	  showTitle = FALSE;			//Input source hot key doesn't show level but show text
	  showText = TRUE;
	   break;
	case HotKey_Backlight:
	  _eHotkeyMode = EN_HOTKEY_MODE_BACKLIGHT;
	   break;
	case HotKey_Contrast:
	  _eHotkeyMode = EN_HOTKEY_MODE_CONTRAST;
	   break;
	case HotKey_Brightness:
	  _eHotkeyMode = EN_HOTKEY_MODE_BRIGHTNESS;
	   break;
	case HotKey_Saturation:
	  _eHotkeyMode = EN_HOTKEY_MODE_SATURATION;
	   break;
	case HotKey_Sharpness:
	  _eHotkeyMode = EN_HOTKEY_MODE_SHARPNESS;
	   break;
	case HotKey_Hue:
	  _eHotkeyMode = EN_HOTKEY_MODE_HUE;
	   break;
	case HotKey_AspectRatio:
	  _eHotkeyMode = EN_HOTKEY_MODE_ASPECT_RATIO;
	  showTitle = FALSE;			//aspect ratio hot key doesn't show level but show text
	  showText = TRUE;
	   break;
	case HotKey_Volume:
	  _eHotkeyMode = EN_HOTKEY_MODE_VOLUME;
	   break;
	case HotKey_NoFunction:
	default:
	  _eHotkeyMode = EN_HOTKEY_MODE_INVALID;
	  showTitle = FALSE;			//doesn't show OSD
	   break;
      }

      //Display hot key level only if it has
      if(showTitle==TRUE){
	MApp_ZUI_API_ShowWindow(HWND_MAINFRAME, SW_HIDE);
	MApp_ZUI_API_ShowWindow(HWND_HOTKEY_LEVEL_PANE, SW_SHOW);
	MApp_ZUI_API_InvalidateWindow(HWND_HOTKEY_LEVEL_TITLE_TEXT);	//Display title
	MApp_ZUI_API_InvalidateWindow(HWND_HOTKEY_LEVEL_BAR);		//Display level ball
	MApp_ZUI_API_SetFocus(HWND_HOTKEY_LEVEL_VALUE_TEXT);		//Display level value
      }

      //Display hot key text only if it has
      if(showText==TRUE){
	MApp_ZUI_API_ShowWindow(HWND_MAINFRAME, SW_HIDE);
	MApp_ZUI_API_ShowWindow(HWND_HOTKEY_TEXT_PANE, SW_SHOW);
	MApp_ZUI_API_InvalidateWindow(HWND_HOTKEY_TEXT_PANE_TEXT);	//Display text
      }

}

#if 0//ENABLE_T_C_COMBO
void _MApp_ZUI_ACT_DecIncDVBType_Cycle(void)
{
    EN_DVB_TYPE CurrentDVBSeletType;
    if(MApp_DVBType_GetCurrentType() == EN_DVB_T_TYPE)
    {
        CurrentDVBSeletType = EN_DVB_C_TYPE;
        MApp_ZUI_API_SetFocus(HWND_SELECTED_DVBC_BG);
    }
    else
    {
        CurrentDVBSeletType = EN_DVB_T_TYPE;
        MApp_ZUI_API_SetFocus(HWND_SELECTED_DVBT_BG);
     }
    printf("setCurrentType = %d\n", CurrentDVBSeletType);
    MApp_DVBType_SetCurrentType(CurrentDVBSeletType);
}
#endif

#if (NTV_FUNCTION_ENABLE)
void _MApp_ZUI_ACT_DecIncBandWidthType_Cycle(void)
{
	if(stGenSetting.stScanMenuSetting.u8BandWidth == E_RF_CH_BAND_8MHz)
	{
	   stGenSetting.stScanMenuSetting.u8BandWidth = E_RF_CH_BAND_7MHz;
	   MApp_ZUI_API_SetFocus(HWND_SELECTED_BANDWIDTH_7M_BG);
	}
	else if(stGenSetting.stScanMenuSetting.u8BandWidth == E_RF_CH_BAND_7MHz)
	{
	   stGenSetting.stScanMenuSetting.u8BandWidth = E_RF_CH_BAND_8MHz;
	   MApp_ZUI_API_SetFocus(HWND_SELECTED_BANDWIDTH_8M_BG);
	}
	msAPI_DFT_SetBandwidth(stGenSetting.stScanMenuSetting.u8BandWidth);
}
#endif

static void _MApp_ZUI_ACT_ExecuteZoomAction(U16 act)
{
    switch(act)
    {
        case EN_EXE_ZOOM_ARROW_UP:
            if(MApi_XC_IsCurrentFrameBufferLessMode())
            {
                break; //Bright@20080911 if Frame buffer less enable no action.
            }

            MApp_Scaler_IncUpZoomfactor(1);
            MApp_Scaler_IncDownZoomfactor(1);
            //printf("ZOOM-UP: %u\n", (U16)stSystemInfo[MAIN_WINDOW].enAspectRatio);
            #if MHEG5_ENABLE
            MApp_MHEG5_SetGraphARCInfo(SENDARC_ARC_CHANGE,stSystemInfo[MAIN_WINDOW].enAspectRatio);
            #endif
            MApp_Scaler_SetWindow(NULL, NULL, NULL,
                                           stSystemInfo[MAIN_WINDOW].enAspectRatio, SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), MAIN_WINDOW);
            break;

        case EN_EXE_ZOOM_ARROW_DOWN:
            if(MApi_XC_IsCurrentFrameBufferLessMode())
            {
                break; //Bright@20080911 if Frame buffer less enable no action.
            }

            MApp_Scaler_IncUpZoomfactor(-1);
            MApp_Scaler_IncDownZoomfactor(-1);
            //printf("ZOOM-DOWN: %u\n", (U16)stSystemInfo[MAIN_WINDOW].enAspectRatio);
            #if MHEG5_ENABLE
            MApp_MHEG5_SetGraphARCInfo(SENDARC_ARC_CHANGE,stSystemInfo[MAIN_WINDOW].enAspectRatio);
            #endif
            MApp_Scaler_SetWindow(NULL, NULL, NULL,
                                       stSystemInfo[MAIN_WINDOW].enAspectRatio, SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), MAIN_WINDOW);
            break;

        case EN_EXE_ZOOM_ARROW_RIGHT:
            if(MApi_XC_IsCurrentFrameBufferLessMode())
            {
                break; //Bright@20080911 if Frame buffer less enable no action.
            }

            MApp_Scaler_IncLeftZoomfactor(1);
            MApp_Scaler_IncRightZoomfactor(1);
            //printf("ZOOM-RIGHT: %u\n", (U16)stSystemInfo[MAIN_WINDOW].enAspectRatio);
            #if MHEG5_ENABLE
            MApp_MHEG5_SetGraphARCInfo(SENDARC_ARC_CHANGE,stSystemInfo[MAIN_WINDOW].enAspectRatio);
            #endif
            MApp_Scaler_SetWindow(NULL, NULL, NULL,
                                       stSystemInfo[MAIN_WINDOW].enAspectRatio, SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), MAIN_WINDOW);
            break;

        case EN_EXE_ZOOM_ARROW_LEFT:
            if(MApi_XC_IsCurrentFrameBufferLessMode())
            {
                break; //Bright@20080911 if Frame buffer less enable no action.
            }

            MApp_Scaler_IncLeftZoomfactor(-1);
            MApp_Scaler_IncRightZoomfactor(-1);
            //printf("ZOOM-LEFT: %u\n", (U16)stSystemInfo[MAIN_WINDOW].enAspectRatio);
            #if MHEG5_ENABLE
            MApp_MHEG5_SetGraphARCInfo(SENDARC_ARC_CHANGE,stSystemInfo[MAIN_WINDOW].enAspectRatio);
            #endif
            MApp_Scaler_SetWindow(NULL, NULL, NULL,
                                       stSystemInfo[MAIN_WINDOW].enAspectRatio, SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), MAIN_WINDOW);
            break;

        case EN_EXE_INC_SCALE_HOTKEY_OPTION:

            if(MApi_XC_IsCurrentFrameBufferLessMode())
            {
                break;
            }

        #if 0//ENABLE_3D_PROCESS
            if(MApi_XC_Get_3D_Output_Mode() != E_XC_3D_OUTPUT_MODE_NONE)
            {
                printf("%s,%d\r\n",__FUNCTION__,__LINE__);
                _MApp_ZUI_ACT_DecInc_3D_AspectRatio_Cycle(TRUE);
            }
            else
        #endif
                _MApp_ZUI_ACT_DecIncAspectRatio_Cycle(TRUE);
            break;

        case EN_EXE_DEC_SCALE_HOTKEY_OPTION:

        #if 0//ENABLE_3D_PROCESS
            if(MApi_XC_Get_3D_Output_Mode() != E_XC_3D_OUTPUT_MODE_NONE)
            {
                printf("%s,%d\r\n",__FUNCTION__,__LINE__);
                _MApp_ZUI_ACT_DecInc_3D_AspectRatio_Cycle(FALSE);
            }
            else
        #endif
        	{
				_MApp_ZUI_ACT_DecIncAspectRatio_Cycle(FALSE);
			}
            break;

        //from case MIA_DSC_KEY_ARC4X3:
        //from case MIA_DSC_KEY_ARC16X9:
        //from case MIA_DSC_KEY_ARCZOOM:
        case EN_EXE_SET_DSC_KEY_ARC4X3:
            ST_VIDEO.eAspectRatio = EN_AspectRatio_4X3;
            MApp_Scaler_Setting_SetVDScale(ST_VIDEO.eAspectRatio, MAIN_WINDOW);
            break;

        case EN_EXE_SET_DSC_KEY_ARC16X9:
            ST_VIDEO.eAspectRatio = EN_AspectRatio_16X9;
            MApp_Scaler_Setting_SetVDScale(ST_VIDEO.eAspectRatio, MAIN_WINDOW);
            break;

        case EN_EXE_SET_DSC_KEY_ARCZOOM:
            ST_VIDEO.eAspectRatio = EN_AspectRatio_Zoom1;
            MApp_Scaler_Setting_SetVDScale(ST_VIDEO.eAspectRatio, MAIN_WINDOW);
            break;
    }
}

BOOLEAN MApp_ZUI_ACT_ExecuteHotkeyOptionAction(U16 act)
{

    switch(act)
    {
        case EN_EXE_CLOSE_CURRENT_OSD:
        case EN_EXE_POWEROFF:
            MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_CLOSE, E_ZUI_STATE_TERMINATE);
            return TRUE;

        case EN_EXE_RESET_AUTO_CLOSE_TIMER:
            //reset timer if any key
            MApp_ZUI_API_ResetTimer(HWND_HOTKEY_BG, 0);
            return FALSE;

        case EN_EXE_DEC_SLEEP_HOTKEY_OPTION:
        case EN_EXE_INC_SLEEP_HOTKEY_OPTION:
            {
                if (_eHotkeyMode != EN_HOTKEY_MODE_SLEEP) //do nothing if not sleep mode...
                    return TRUE;
#if ENABLE_ATSC_TTS
                MApp_TTSControlSetInputText(MApp_ZUI_API_GetString(en_str_Auto_Sleep), MApp_UiMenu_u16Strlen(MApp_ZUI_API_GetString(en_str_Auto_Sleep)));
#endif
                _MApp_ZUI_ACT_DecIncSleepTimer_Cycle(
                    act==EN_EXE_INC_SLEEP_HOTKEY_OPTION);
                MApp_ZUI_API_InvalidateWindow(HWND_HOTKEY_SLEEP_TIMER_TEXT);
            }
            return TRUE;

        case EN_EXE_SHOW_SLEEP_HOTKEY:
            if (_eHotkeyMode != EN_HOTKEY_MODE_SLEEP)
            {
#if ENABLE_ATSC_TTS
                MApp_TTSControlSetInputText(MApp_ZUI_API_GetString(en_str_Auto_Sleep), MApp_UiMenu_u16Strlen(MApp_ZUI_API_GetString(en_str_Auto_Sleep)));
#endif
                _eHotkeyMode = EN_HOTKEY_MODE_SLEEP;
                MApp_ZUI_API_ShowWindow(HWND_MAINFRAME, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_HOTKEY_BG, SW_SHOW);
                MApp_ZUI_API_ShowWindow(HWND_HOTKEY_SLEEP_TIMER, SW_SHOW);
                MApp_ZUI_API_SetFocus(HWND_HOTKEY_SLEEP_TIMER_TEXT);
            }
            return TRUE;

        ////Ray HKY 2017.10.18:Hot key 1 exe action to update hot key 1 OSD
        case EN_EXE_SHOW_DV_HOTKEY_1:
	    _MApp_ZUI_ACT_ShowOSDHotKeyTitleLevel(GET_HOTKEY_1());
            return TRUE;
        ////

	////Ray HKY 2017.10.18:Hot key 2 exe action to update hot key 2 OSD
	case EN_EXE_SHOW_DV_HOTKEY_2:
	    _MApp_ZUI_ACT_ShowOSDHotKeyTitleLevel(GET_HOTKEY_2());
	    return TRUE;
	////


        ////Ray HKY 2017.10.17: change to increase/decrease digital view hot key
        case EN_EXE_DEC_DV_HOTKEY_OPTION:
        case EN_EXE_INC_DV_HOTKEY_OPTION:
            {
                switch(_eHotkeyMode){
                  //Ray HKY 2017.10.18: Volume and contrast calls RS-232 Para1 routine to change value.  So we group them together
                  case EN_HOTKEY_MODE_VOLUME:
                  case EN_HOTKEY_MODE_CONTRAST:
                    _MApp_ZUI_ACT_DecIncDVHotKeyPara1(act==EN_EXE_INC_DV_HOTKEY_OPTION);	//Inc/Dec value
                    MApp_ZUI_API_InvalidateWindow(HWND_HOTKEY_LEVEL_BAR);			//Update level ball
                    MApp_ZUI_API_InvalidateWindow(HWND_HOTKEY_LEVEL_VALUE_TEXT);		//Update level
                    break;
                  //Ray HKY 2017.10.18: For other hot keys, they calls RS-232 Para0 routine to change value
                  case EN_HOTKEY_MODE_BRIGHTNESS:
                  case EN_HOTKEY_MODE_BACKLIGHT:
                  case EN_HOTKEY_MODE_SATURATION:
                  case EN_HOTKEY_MODE_HUE:
                  case EN_HOTKEY_MODE_SHARPNESS:
                    _MApp_ZUI_ACT_DecIncDVHotKeyPara0(act==EN_EXE_INC_DV_HOTKEY_OPTION);	//Inc/Dec value
                    MApp_ZUI_API_InvalidateWindow(HWND_HOTKEY_LEVEL_BAR);			//Update level ball
                    MApp_ZUI_API_InvalidateWindow(HWND_HOTKEY_LEVEL_VALUE_TEXT);		//Update level
                    break;
                  //Ray HKY 2017.10.18: For Input and aspect ratio key, there is OSD update of text
                  case EN_HOTKEY_MODE_INPUT:
                    _MApp_ZUI_ACT_DecIncDVHotKeyPara0(act==EN_EXE_INC_DV_HOTKEY_OPTION);	//Inc/Dec value
                    MApp_ZUI_API_InvalidateWindow(HWND_HOTKEY_TEXT_PANE_TEXT);		//Update text
                    break;
                  case EN_HOTKEY_MODE_ASPECT_RATIO:
                    _MApp_ZUI_ACT_DecIncDVApectRatioHotKey(act==EN_EXE_INC_DV_HOTKEY_OPTION);
                    MApp_ZUI_API_InvalidateWindow(HWND_HOTKEY_TEXT_PANE_TEXT);		//Update text
                    break;
                  default:
                    return TRUE;		//Do nothing if it's not DV hot key
                    break;
                }


            }
            return TRUE;
        ////



        case EN_EXE_DEC_ATV_MTS_HOTKEY_OPTION:
        case EN_EXE_INC_ATV_MTS_HOTKEY_OPTION:
            {
                if (_eHotkeyMode != EN_HOTKEY_MODE_ATV_MTS) //do nothing if not mts mode...
                    return TRUE;
#if ENABLE_ATSC
                if(MApp_AUDIO_IsSifSoundModeExist(SOUND_MTS_STEREO)||MApp_AUDIO_IsSifSoundModeExist(SOUND_MTS_SAP) || MApp_AUDIO_IsSifSoundModeExist(SOUND_MTS_MONO))
                {
                    stGenSetting.g_SoundSetting.Mts =
                    (EN_SOUND_MTS_TYPE)MApp_UiMenuFunc_DecIncValue_Cycle(TRUE, stGenSetting.g_SoundSetting.Mts, SOUND_MTS_MONO, SOUND_MTS_NUM-1, 1);

                    MApp_Aud_GetNextAvailableMtsMode(FALSE);
                    MApp_Aud_SetMtsMode();
                }
#else
                msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_INTERNAL_4_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                msAPI_Timer_Delayms(DELAY_FOR_ENTERING_MUTE);
                msAPI_AUD_AdjustAudioFactor(E_ADJUST_CHANGE_AUDIOMODE, 0, 0);
                msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_INTERNAL_4_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
#endif
                MApp_ZUI_API_InvalidateWindow(HWND_HOTKEY_MTS_TEXT);
            }
            return TRUE;

        case EN_EXE_SHOW_ATV_MTS_HOTKEY:
            #if ENABLE_DTV
            if (IsDTVInUse())
            {
                Mapp_DTV_ProcessMTS();
            }
            else
            #endif
            if (_eHotkeyMode != EN_HOTKEY_MODE_ATV_MTS)
            {
                _eHotkeyMode = EN_HOTKEY_MODE_ATV_MTS;
                MApp_ZUI_API_ShowWindow(HWND_MAINFRAME, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_HOTKEY_BG, SW_SHOW);
                MApp_ZUI_API_ShowWindow(HWND_HOTKEY_MTS, SW_SHOW);
                MApp_ZUI_API_SetFocus(HWND_HOTKEY_MTS_TEXT);
            }
            return TRUE;

        case EN_EXE_DEC_PICTURE_HOTKEY_OPTION:
        case EN_EXE_INC_PICTURE_HOTKEY_OPTION:
            {
                if (_eHotkeyMode != EN_HOTKEY_MODE_PICTURE) //do nothing if not picture mode...
                    return TRUE;

                ST_VIDEO.ePicture = (EN_MS_PICTURE) MApp_ZUI_ACT_DecIncValue_Cycle(
                    act==EN_EXE_INC_PICTURE_HOTKEY_OPTION,
                    ST_VIDEO.ePicture, PICTURE_MIN, PICTURE_NUMS-1, 1);
                MApp_Picture_Setting_SetColor(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), MAIN_WINDOW); //MApp_SetPictureMode(MAIN_WINDOW, TRUE);

                MApp_ZUI_API_InvalidateWindow(HWND_HOTKEY_PICTURE_MODE_TEXT);
            }
            return TRUE;

        case EN_EXE_SHOW_PICTURE_HOTKEY:
            if (_eHotkeyMode != EN_HOTKEY_MODE_PICTURE)
            {
                _eHotkeyMode = EN_HOTKEY_MODE_PICTURE;
                MApp_ZUI_API_ShowWindow(HWND_MAINFRAME, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_HOTKEY_BG, SW_SHOW);
                MApp_ZUI_API_ShowWindow(HWND_HOTKEY_PICTURE_MODE, SW_SHOW);
                MApp_ZUI_API_SetFocus(HWND_HOTKEY_PICTURE_MODE_TEXT);
            }
            return TRUE;

        #if (ENABLE_PIP)
        case EN_EXE_DEC_PIP_HOTKEY_OPTION:
        case EN_EXE_INC_PIP_HOTKEY_OPTION:
            if(IsPIPSupported())
            {
                U8 u8PipModeCount = 0 ;
                EN_PIP_MODE enPIPMode = stGenSetting.g_stPipSetting.enPipMode;
                u8PipModeCount = 0;
                do
                {
                    enPIPMode=(EN_PIP_MODE) MApp_ZUI_ACT_DecIncValue_Cycle(
                                act==EN_EXE_INC_PIP_HOTKEY_OPTION,
                                enPIPMode, EN_PIP_MODE_OFF, EN_PIP_MODE_MAX, 1);
                     u8PipModeCount ++;

                }
                while((!MApp_Check_PIPMode_Supported(enPIPMode)) || u8PipModeCount <= (EN_PIP_MODE_MAX+1));

                MApp_Set_PIPMode(enPIPMode,NULL,NULL);
                MApp_ZUI_API_InvalidateWindow(HWND_HOTKEY_PIP_MODE_TEXT);
                return TRUE;
            }
            return TRUE;

        case EN_EXE_SHOW_PIP_HOTKEY:
            if (_eHotkeyMode != EN_HOTKEY_MODE_PIP)
            {
                _eHotkeyMode = EN_HOTKEY_MODE_PIP;
                MApp_ZUI_API_ShowWindow(HWND_MAINFRAME, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_HOTKEY_BG, SW_SHOW);
                MApp_ZUI_API_ShowWindow(HWND_HOTKEY_PIP_MODE, SW_SHOW);
                MApp_ZUI_API_SetFocus(HWND_HOTKEY_PIP_MODE_TEXT);
            }
            return TRUE;
        #endif

        case EN_EXE_DEC_AUDIO_HOTKEY_OPTION:
        case EN_EXE_INC_AUDIO_HOTKEY_OPTION:
            {
                if (_eHotkeyMode != EN_HOTKEY_MODE_AUDIO) //do nothing if not sund mode...
                    return TRUE;
#if ENABLE_ATSC_TTS
                MApp_TTSControlSetInputText(MApp_ZUI_API_GetString(en_str_Audio), MApp_UiMenu_u16Strlen(MApp_ZUI_API_GetString(en_str_Audio)));
#endif
                stGenSetting.g_SoundSetting.SoundMode =
                   (EN_SOUND_MODE) MApp_ZUI_ACT_DecIncValue_Cycle(
                        act==EN_EXE_INC_AUDIO_HOTKEY_OPTION,
                        stGenSetting.g_SoundSetting.SoundMode,
                        EN_SoundMode_Standard, EN_SoundMode_Num-1, 1);
           #if (SOUNDMODE == SOUNDMODE_EQ)
                MApi_AUDIO_EnableEQ(TRUE);
                MApi_AUDIO_SetEq(E_EQUALIZER_BAND_1, stGenSetting.g_SoundSetting.astSoundModeSetting[stGenSetting.g_SoundSetting.SoundMode].u8120HZ);
                MApi_AUDIO_SetEq(E_EQUALIZER_BAND_2, stGenSetting.g_SoundSetting.astSoundModeSetting[stGenSetting.g_SoundSetting.SoundMode].u8200HZ);
                MApi_AUDIO_SetEq(E_EQUALIZER_BAND_3, stGenSetting.g_SoundSetting.astSoundModeSetting[stGenSetting.g_SoundSetting.SoundMode].u8500HZ);
                MApi_AUDIO_SetEq(E_EQUALIZER_BAND_4, stGenSetting.g_SoundSetting.astSoundModeSetting[stGenSetting.g_SoundSetting.SoundMode].u8_1_dot_2_KHZ);
                MApi_AUDIO_SetEq(E_EQUALIZER_BAND_5, stGenSetting.g_SoundSetting.astSoundModeSetting[stGenSetting.g_SoundSetting.SoundMode].u8_3KHZ);
           #else
			    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_MOMENT_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
			    MApp_Audio_AdjustSoundMode();
			    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_MOMENT_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
		   #endif
                MApp_ZUI_API_InvalidateWindow(HWND_HOTKEY_SOUND_MODE_TEXT);
            }
            return TRUE;

        case EN_EXE_SHOW_AUDIO_HOTKEY:
            if (_eHotkeyMode != EN_HOTKEY_MODE_AUDIO)
            {
#if ENABLE_ATSC_TTS
                MApp_TTSControlSetInputText(MApp_ZUI_API_GetString(en_str_Audio), MApp_UiMenu_u16Strlen(MApp_ZUI_API_GetString(en_str_Audio)));
#endif
                _eHotkeyMode = EN_HOTKEY_MODE_AUDIO;
                MApp_ZUI_API_ShowWindow(HWND_MAINFRAME, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_HOTKEY_BG, SW_SHOW);
                MApp_ZUI_API_ShowWindow(HWND_HOTKEY_SOUND_MODE, SW_SHOW);
                MApp_ZUI_API_SetFocus(HWND_HOTKEY_SOUND_MODE_TEXT);
            }
            return TRUE;

        case EN_EXE_DEC_SCALE_HOTKEY_OPTION:
        case EN_EXE_INC_SCALE_HOTKEY_OPTION:
        case EN_EXE_SET_DSC_KEY_ARC4X3:
        case EN_EXE_SET_DSC_KEY_ARC16X9:
        case EN_EXE_SET_DSC_KEY_ARCZOOM:
            #if (ENABLE_PIP)
            if((MApp_Get_PIPMode() == EN_PIP_MODE_POP)||(MApp_Get_PIPMode() == EN_PIP_MODE_POP_FULL))
                return TRUE;
            #endif

            if (_eHotkeyMode != EN_HOTKEY_MODE_SCALE) //do nothing if not sleep mode...
                return TRUE;
#if ENABLE_ATSC_TTS
                MApp_TTSControlSetInputText(MApp_ZUI_API_GetString(en_str_Zoom), MApp_UiMenu_u16Strlen(MApp_ZUI_API_GetString(en_str_Zoom)));
#endif
#if 0//(MHEG5_ENABLE) //from MApp_MHEG5_Main.c
            if (MApp_TopStateMachine_GetTopState()==STATE_TOP_TTX)
            {
                g_MHEG5Video.bARCChange = TRUE;
            }
#endif       //from MApp_MHEG5_Main.c

            _MApp_ZUI_ACT_ExecuteZoomAction(act);

#if 0//(MHEG5_ENABLE) //from MApp_MHEG5_Main.c
            if (MApp_TopStateMachine_GetTopState()==STATE_TOP_TTX)
            {
                g_MHEG5Video.bARCChange = FALSE;
            }
#endif       //from MApp_MHEG5_Main.c


            MApp_ZUI_API_InvalidateWindow(HWND_HOTKEY_ZOOM_TEXT);
            return TRUE;

        case EN_EXE_ZOOM_ARROW_RIGHT:
        case EN_EXE_ZOOM_ARROW_LEFT:

            if (_eHotkeyMode != EN_HOTKEY_MODE_SCALE) //do nothing if not sleep mode...
                return TRUE;

#if 0//(MHEG5_ENABLE) //from MApp_MHEG5_Main.c
            if (MApp_TopStateMachine_GetTopState()==STATE_TOP_TTX)
            {
                g_MHEG5Video.bARCAdj_H = TRUE;
            }
#endif       //from MApp_MHEG5_Main.c

            _MApp_ZUI_ACT_ExecuteZoomAction(act);

#if 0//(MHEG5_ENABLE) //from MApp_MHEG5_Main.c
            if (MApp_TopStateMachine_GetTopState()==STATE_TOP_TTX)
            {
                msAPI_MHEG5_SetGraphARCInfoDefault(SENDARC_ARC_CHANGE,stSystemInfo.enAspectRatio);
                g_MHEG5Video.bARCAdj_H = FALSE;
            }
#endif       //from MApp_MHEG5_Main.c

            MApp_ZUI_API_InvalidateWindow(HWND_HOTKEY_ZOOM_TEXT);
            return TRUE;

        case EN_EXE_ZOOM_ARROW_UP:
        case EN_EXE_ZOOM_ARROW_DOWN:

            if (_eHotkeyMode != EN_HOTKEY_MODE_SCALE) //do nothing if not sleep mode...
                return TRUE;

#if (MHEG5_ENABLE) //from MApp_MHEG5_Main.c
            if (MApp_TopStateMachine_GetTopState()==STATE_TOP_TTX)
            {
                g_MHEG5Video.bARCAdj_V = TRUE;
            }
#endif       //from MApp_MHEG5_Main.c

            _MApp_ZUI_ACT_ExecuteZoomAction(act);

#if (MHEG5_ENABLE) //from MApp_MHEG5_Main.c
            if (MApp_TopStateMachine_GetTopState()==STATE_TOP_TTX)
            {
                MApp_MHEG5_SetGraphARCInfo(SENDARC_ARC_CHANGE,stSystemInfo[MAIN_WINDOW].enAspectRatio);
                g_MHEG5Video.bARCAdj_V = FALSE;
            }
#endif       //from MApp_MHEG5_Main.c

            MApp_ZUI_API_InvalidateWindow(HWND_HOTKEY_ZOOM_TEXT);
            return TRUE;

        case EN_EXE_SHOW_SCALE_HOTKEY:
            if (_eHotkeyMode != EN_HOTKEY_MODE_SCALE)
            {
#if ENABLE_ATSC_TTS
                MApp_TTSControlSetInputText(MApp_ZUI_API_GetString(en_str_Zoom), MApp_UiMenu_u16Strlen(MApp_ZUI_API_GetString(en_str_Zoom)));
#endif
                _eHotkeyMode = EN_HOTKEY_MODE_SCALE;
                MApp_ZUI_API_ShowWindow(HWND_MAINFRAME, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_HOTKEY_BG, SW_SHOW);
                MApp_ZUI_API_ShowWindow(HWND_HOTKEY_ZOOM, SW_SHOW);
                MApp_ZUI_API_SetFocus(HWND_HOTKEY_ZOOM_TEXT);
            }
            return TRUE;

        case EN_EXE_ONOFF_FREEZE_HOTKEY_OPTION:
            if (_eHotkeyMode != EN_HOTKEY_MODE_FREEZE) //do nothing if not free mode...
                return TRUE;

            if (MApp_IsImageFrozen())
            {
                MApp_SetImageFrozen(FALSE);
            }
            else
            {
                MApp_SetImageFrozen(TRUE);
            }


           	MApi_XC_WaitInputVSync(3, 100, MAIN_WINDOW);

            MApi_XC_FreezeImg(MApp_IsImageFrozen(), MAIN_WINDOW);

            MApp_ZUI_API_InvalidateWindow(HWND_HOTKEY_FREEZE_TEXT);
            return TRUE;

        case EN_EXE_SHOW_FREEZE_HOTKEY:
            if (_eHotkeyMode != EN_HOTKEY_MODE_FREEZE)
            {
                _eHotkeyMode = EN_HOTKEY_MODE_FREEZE;
                MApp_ZUI_API_ShowWindow(HWND_MAINFRAME, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_HOTKEY_BG, SW_SHOW);
                MApp_ZUI_API_ShowWindow(HWND_HOTKEY_FREEZE, SW_SHOW);
                MApp_ZUI_API_SetFocus(HWND_HOTKEY_FREEZE_TEXT);
            }
            return TRUE;

#if (ENABLE_ATSC)
        case EN_EXE_INC_CC_HOTKEY_OPTION:
            if (IsAtscInUse() || IsATVInUse() || IsAVInUse())
            {
                if (_eHotkeyMode != EN_HOTKEY_MODE_CC) //do nothing if not CCD...
                    return TRUE;

                MApp_UiMenuFunc_AdjustCCMode(TRUE);

                if (MApp_UiMenuFunc_GetCCModeValue() == CAPTIONMENU_MODE_OFF
                    && MApp_CC_GetInfo(CC_SELECTOR_STATUS_CODE) == STATE_CAPTION_PARSER)
                {
                    MApp_CC_StopParser();

                #if 0 // Need check
                    MApp_Dmx_PES_Stop();
                #endif
                }
                MApp_ZUI_API_InvalidateWindow(HWND_HOTKEY_CC_TEXT);
            }
            else
                return TRUE;
            break;
        case EN_EXE_SHOW_CC_HOTKEY:
            if (IsAtscInUse() || IsATVInUse() || IsAVInUse())
            {
                if (_eHotkeyMode != EN_HOTKEY_MODE_CC)
                {
                    _eHotkeyMode = EN_HOTKEY_MODE_CC;
                    MApp_ZUI_API_ShowWindow(HWND_MAINFRAME, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_HOTKEY_BG, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_HOTKEY_CC, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_HOTKEY_CC_TEXT, SW_SHOW);
                    MApp_ZUI_API_SetFocus(HWND_HOTKEY_CC_TEXT);
                }
            }
            else
            {
                MApp_ZUI_API_ShowWindow(HWND_MAINFRAME, SW_HIDE);
                return TRUE;
            }
            break;
#endif

#if BRAZIL_CC//ENABLE_SBTVD_BRAZIL_APP
    case EN_EXE_INC_CC_HOTKEY_OPTION:
        if (IsATVInUse() || IsAVInUse()  || IsSVInUse() || IsDTVInUse())
        {
        if (_eHotkeyMode != EN_HOTKEY_MODE_CC) //do nothing if not CCD...
            return TRUE;

        if(IsDTVInUse())
        {
            DB_CC_SETTING.enDTVCaptionType=
            (EN_DTV_CAPTION_TYPE) MApp_ZUI_ACT_DecIncValue_Cycle(
                act==EN_EXE_INC_CC_HOTKEY_OPTION,
                DB_CC_SETTING.enDTVCaptionType, DTV_CAPTION_OFF, DTV_CAPTION_ON, 1);

            if (DB_CC_SETTING.enDTVCaptionType == DTV_CAPTION_OFF
                && MApp_CC_GetInfo(CC_SELECTOR_STATUS_CODE) == STATE_CAPTION_PARSER)
            {
                MApp_CC_StopParser();
                MApp_Dmx_PES_Stop();
            }
        }
        else if (IsATVInUse() || IsAVInUse()  || IsSVInUse() )
        {
            DB_CC_SETTING.enATVCaptionType=
            (EN_ATV_CAPTION_TYPE) MApp_ZUI_ACT_DecIncValue_Cycle(
                act==EN_EXE_INC_CC_HOTKEY_OPTION,
                DB_CC_SETTING.enATVCaptionType, ATV_CAPTION_TYPE_OFF, ATV_CAPTION_TYPE_NUM-1, 1);

            if (DB_CC_SETTING.enATVCaptionType == ATV_CAPTION_TYPE_OFF
                && MApp_CC_GetInfo(CC_SELECTOR_STATUS_CODE) == STATE_CAPTION_PARSER)
            {
                MApp_CC_StopParser();
                MApp_Dmx_PES_Stop();
            }
        }
        #if (ENABLE_ISDBT)
        MApp_ZUI_API_InvalidateWindow(HWND_HOTKEY_CC_TEXT);
        #endif
        }
        return TRUE;

    case EN_EXE_SHOW_CC_HOTKEY:
        if (IsATVInUse() || IsAVInUse()  || IsSVInUse() || IsDTVInUse())
        {
        if (_eHotkeyMode != EN_HOTKEY_MODE_CC)
        {
            _eHotkeyMode = EN_HOTKEY_MODE_CC;
            MApp_ZUI_API_ShowWindow(HWND_MAINFRAME, SW_HIDE);
            #if (ENABLE_ISDBT)
            MApp_ZUI_API_ShowWindow(HWND_HOTKEY_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_HOTKEY_CC, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_HOTKEY_CC_TEXT, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_HOTKEY_CC_TEXT);
            #endif
        }
        }
        return TRUE;
#endif


    }
    return FALSE;
}

void _MApp_ZUI_ACT_GetSleepTimerString(LPTSTR str)
{
    if(MApp_Sleep_GetCurrentSleepState() == STATE_SLEEP_OFF)
    {
        MApp_ZUI_API_LoadString(en_str_Off, str);
    }
    else
    {
        U32 u32SleepTime = MApp_Sleep_GetSleepTimeRemainTime();
        U8 u8SleepDigits = MApp_GetNoOfDigit(u32SleepTime);
        __MApp_UlongToString(u32SleepTime, str, u8SleepDigits);
        MApp_ZUI_API_LoadString(en_str_min, str + u8SleepDigits);
    }
}

static LPTSTR _MApp_ZUI_ACT_GeHotkeySleepDynamicText(void)
{
    _MApp_ZUI_ACT_GetSleepTimerString(CHAR_BUFFER);

    return CHAR_BUFFER;
}


//Ray HKY 2017.09.27: Get hot key title text
static LPTSTR _MApp_ZUI_ACT_GeHotkeyTitleDynamicText(void)
{
  //Check the current hot key mode and display corresponding value on level text
  switch(_eHotkeyMode){
    case EN_HOTKEY_MODE_VOLUME:
      return MApp_ZUI_API_GetString(en_str_Volume);
      break;
    case EN_HOTKEY_MODE_BRIGHTNESS:
      return MApp_ZUI_API_GetString(en_str_Brightness);
      break;
    //Ray HKY 2017.10.17: Add hot key modes string except input, since input source doesn't shown any OSD hot key menu
    case EN_HOTKEY_MODE_BACKLIGHT:
      return MApp_ZUI_API_GetString(en_str_Backlight);
      break;
    case EN_HOTKEY_MODE_CONTRAST:
      return MApp_ZUI_API_GetString(en_str_Contrast);
      break;
    case EN_HOTKEY_MODE_SATURATION:
      return MApp_ZUI_API_GetString(en_str_Color);
      break;
    case EN_HOTKEY_MODE_HUE:
      return MApp_ZUI_API_GetString(en_str_Tint);
      break;
    case EN_HOTKEY_MODE_SHARPNESS:
      return MApp_ZUI_API_GetString(en_str_Sharpness);
      break;
    case EN_HOTKEY_MODE_ASPECT_RATIO:
      return MApp_ZUI_API_GetString(en_str_Aspect_Ratio);
      break;
    default:
      return NULL;
  }
}


//Ray HKY 2017.09.27: Get dynamic value for hot key to show level ball
S16 MApp_ZUI_ACT_GetHotkeyOptionDynamicValue(void)
{
  S16 value = 0;

  //Check the current hot key mode and Get corresponding value
  switch(_eHotkeyMode){
    case EN_HOTKEY_MODE_VOLUME:
      value = stGenSetting.g_SoundSetting.Volume ;
      break;
    case EN_HOTKEY_MODE_BRIGHTNESS:
      value = ST_PICTURE.u8Brightness ;
      break;
    case EN_HOTKEY_MODE_BACKLIGHT:
      value = stGenSetting.u8Backlight;
      break;
    case EN_HOTKEY_MODE_CONTRAST:
      value = ST_PICTURE.u8Contrast;
      break;
    case EN_HOTKEY_MODE_SATURATION:
      value = ST_PICTURE.u8Saturation;
      break;
    case EN_HOTKEY_MODE_HUE:
      value = ST_PICTURE.u8Hue;
      break;
    case EN_HOTKEY_MODE_SHARPNESS:
      value = ST_PICTURE.u8Sharpness;
      break;
    default:
      break;
  }

  return value;
}


//Ray HKY 2017.09.27: Get level value for hot key
static LPTSTR _MApp_ZUI_ACT_GeHotkeyLevelValueDynamicText(void)
{
    return MApp_ZUI_API_GetU16String(MApp_ZUI_ACT_GetHotkeyOptionDynamicValue());
}


//Ray HKY 2017.10.20: Get text for input source/aspect ratio hot key
static LPTSTR _MApp_ZUI_ACT_GetHotKeyTextDynamicText(void)
{
  //Check the current hot key mode and Get corresponding text
  if(_eHotkeyMode==EN_HOTKEY_MODE_INPUT){
      return MApp_ZUI_API_GetString(MApp_ZUI_GetCurrentInputSourceStringID(UI_INPUT_SOURCE_TYPE));
  }
  if(_eHotkeyMode==EN_HOTKEY_MODE_ASPECT_RATIO){
      return MApp_ZUI_API_GetString(_MApp_ZUI_ACT_GetAspectRatioStringID());

  }

  return 0; //for empty string
}


static LPTSTR _MApp_ZUI_ACT_GeHotkeyFreezeDynamicText(void)
{
    LPTSTR str = CHAR_BUFFER;

    MApp_ZUI_API_LoadString(en_str_Freeze, str);
    str += MApp_ZUI_API_Strlen(str);
    *str++ = CHAR_SPACE;
    *str++ = CHAR_COLON;
    *str++ = CHAR_SPACE;

    if (MApp_IsImageFrozen())
        MApp_ZUI_API_LoadString(en_str_On, str);
    else
        MApp_ZUI_API_LoadString(en_str_Off, str);

    return CHAR_BUFFER;
}

#if !ENABLE_ATSC
static U16 _MApp_ZUI_ACT_GetATVMTSStringID(void)
{
    U16 u16TempID = Empty;
    //from case HOTKEYMTSTEXT:
    switch(m_eAudioMode)
    {
        case E_AUDIOMODE_INVALID:
        break;

        case E_AUDIOMODE_MONO:
            u16TempID=en_str_Mono;
            break;

        case E_AUDIOMODE_FORCED_MONO:
            u16TempID=en_str_Mono;
            break;

        case E_AUDIOMODE_G_STEREO:
            u16TempID=en_str_Stereo;
            break;

        case E_AUDIOMODE_K_STEREO:
            u16TempID=en_str_Stereo;
            break;

        case E_AUDIOMODE_MONO_SAP:
        case E_AUDIOMODE_STEREO_SAP:
            u16TempID=en_str_SAP;
            break;

        case E_AUDIOMODE_DUAL_A:
            u16TempID=en_str_DUAL_I;
            break;

        case E_AUDIOMODE_DUAL_B:
            u16TempID=en_str_DUAL_II;
            break;

        case E_AUDIOMODE_DUAL_AB:
            u16TempID=en_str_DUAL_IplusII;
            break;

        case E_AUDIOMODE_NICAM_MONO:
            u16TempID=en_str_NICAM_MONO;
            break;

        case E_AUDIOMODE_NICAM_STEREO:
            u16TempID=en_str_NICAM_STEREO;
            break;
        break;

        case E_AUDIOMODE_NICAM_DUAL_A:
            u16TempID=en_str_NICAM_DUAL_I;
            break;

        case E_AUDIOMODE_NICAM_DUAL_B:
            u16TempID=en_str_NICAM_DUAL_II;
            break;

        case E_AUDIOMODE_NICAM_DUAL_AB:
            u16TempID=en_str_NICAM_DUAL_IplusII;
            break;

        case E_AUDIOMODE_HIDEV_MONO:
            u16TempID=en_str_HIDEV_MONO;
            break;

        case E_AUDIOMODE_LEFT_LEFT:
            u16TempID=en_str_L_plus_L;
            break;

        case E_AUDIOMODE_RIGHT_RIGHT:
            u16TempID=en_str_R_plus_R;
            break;

        case E_AUDIOMODE_LEFT_RIGHT:
            u16TempID=en_str_L_plus_R;
            break;
        default:
            break;


    }
    return u16TempID;
}
#endif
extern U16 _MApp_ZUI_ACT_GetPictureModeStringID(void);
extern U16 _MApp_ZUI_ACT_GetAudioModeStringID(void);
extern U16 _MApp_ZUI_ACT_GetAspectRatioStringID(void);

LPTSTR MApp_ZUI_ACT_GetHotkeyOptionDynamicText(HWND hwnd)
{
    U16 u16TempID = Empty;
    switch(hwnd)
    {
        case HWND_HOTKEY_CC_TEXT:
        {
        switch(_eHotkeyMode)
            {
            #if (ENABLE_ATSC)
                case EN_HOTKEY_MODE_CC:
                    if (IsAtscInUse() || IsATVInUse() || IsAVInUse())
                    {
                        switch(MApp_UiMenuFunc_GetCCModeValue())
                        {
                            case CAPTIONMENU_MODE_OFF:
                                u16TempID = en_str_CC_Off;
                                break;

                            case CAPTIONMENU_MODE_ON:
                                u16TempID = en_str_CC_On;
                                break;
                            #if (PARSING_CC_WHENMUTE)
                            case CAPTIONMENU_MODE_CC_WHEN_MUTE:
                                u16TempID = en_str_CC_On_Mute;
                                break;
                            #endif
                        }
                    }
                break;
            #endif

             #if BRAZIL_CC//ENABLE_SBTVD_BRAZIL_APP
                case EN_HOTKEY_MODE_CC:
                    if(IsDTVInUse())
                    {
                            LPTSTR str = CHAR_BUFFER;
                            MApp_ZUI_API_LoadString(en_str_Caption, str);
                            str += MApp_ZUI_API_Strlen(str);
                            *str++ = CHAR_SPACE;
                            *str++ = CHAR_COLON;
                            *str++ = CHAR_SPACE;
                        if(DB_CC_SETTING.enDTVCaptionType == DTV_CAPTION_ON)
                        {
                            MApp_ZUI_API_LoadString(en_str_On,str);
                        }
                        else
                        {
                            MApp_ZUI_API_LoadString(en_str_Off,str);
                        }
                            return CHAR_BUFFER;
                    }
                    else
                    {
                            LPTSTR str = CHAR_BUFFER;
                            MApp_ZUI_API_LoadString(en_str_Caption, str);
                            str += MApp_ZUI_API_Strlen(str);
                            *str++ = CHAR_SPACE;
                            *str++ = CHAR_COLON;
                            *str++ = CHAR_SPACE;
                       if(DB_CC_SETTING.enATVCaptionType == ATV_CAPTION_TYPE_CC1)
                       {
                            MApp_ZUI_API_LoadString(en_str_CC_1,str);

                       }
                       else if(DB_CC_SETTING.enATVCaptionType == ATV_CAPTION_TYPE_CC2)
                       {
                            MApp_ZUI_API_LoadString(en_str_CC_2,str);

                       }
                       else if(DB_CC_SETTING.enATVCaptionType == ATV_CAPTION_TYPE_CC3)
                       {
                            MApp_ZUI_API_LoadString(en_str_CC_3,str);

                       }
                       else if(DB_CC_SETTING.enATVCaptionType == ATV_CAPTION_TYPE_CC4)
                       {
                            MApp_ZUI_API_LoadString(en_str_CC_4,str);

                       }
                       else if(DB_CC_SETTING.enATVCaptionType == ATV_CAPTION_TYPE_TEXT1)
                       {
                            MApp_ZUI_API_LoadString(en_str_Text_1,str);

                       }
                       else if(DB_CC_SETTING.enATVCaptionType == ATV_CAPTION_TYPE_TEXT2)
                       {
                            MApp_ZUI_API_LoadString(en_str_Text_2,str);

                       }
                       else if(DB_CC_SETTING.enATVCaptionType == ATV_CAPTION_TYPE_TEXT3)
                       {
                            MApp_ZUI_API_LoadString(en_str_Text_3,str);

                       }
                       else if(DB_CC_SETTING.enATVCaptionType == ATV_CAPTION_TYPE_TEXT4)
                       {
                            MApp_ZUI_API_LoadString(en_str_Text_4,str);

                       }
                       else
                       {
                          DB_CC_SETTING.enATVCaptionType = ATV_CAPTION_TYPE_OFF;
                          MApp_ZUI_API_LoadString(en_str_Off,str);

                       }
                          return CHAR_BUFFER;

                    }

             #endif

            default:
                break;
            }
        }
            break;
        case HWND_HOTKEY_PICTURE_MODE_TEXT:
            u16TempID = _MApp_ZUI_ACT_GetPictureModeStringID();
#if ENABLE_ATSC_TTS
            MApp_TTSControlSetInputText(MApp_ZUI_API_GetString(u16TempID), MApp_UiMenu_u16Strlen(MApp_ZUI_API_GetString(u16TempID)));
            MApp_TTSControlSetOn(TRUE);
#endif
            break;

        case HWND_HOTKEY_SOUND_MODE_TEXT:
            u16TempID = _MApp_ZUI_ACT_GetAudioModeStringID();
#if ENABLE_ATSC_TTS
            MApp_TTSControlSetInputText(MApp_ZUI_API_GetString(u16TempID), MApp_UiMenu_u16Strlen(MApp_ZUI_API_GetString(u16TempID)));
            MApp_TTSControlSetOn(TRUE);
#endif
            break;

        case HWND_HOTKEY_ZOOM_TEXT:
            u16TempID = _MApp_ZUI_ACT_GetAspectRatioStringID();
#if ENABLE_ATSC_TTS
            MApp_TTSControlSetInputText(MApp_ZUI_API_GetString(u16TempID), MApp_UiMenu_u16Strlen(MApp_ZUI_API_GetString(u16TempID)));
            MApp_TTSControlSetOn(TRUE);
#endif
            break;

        case HWND_HOTKEY_SLEEP_TIMER_TEXT:
            return _MApp_ZUI_ACT_GeHotkeySleepDynamicText();

	//Ray HKY 2017.09.27: Show hot key title text
	case HWND_HOTKEY_LEVEL_TITLE_TEXT:
	  return _MApp_ZUI_ACT_GeHotkeyTitleDynamicText();

        //Ray HKY 2017.09.27: Show hot key level value
        case HWND_HOTKEY_LEVEL_VALUE_TEXT:
          return _MApp_ZUI_ACT_GeHotkeyLevelValueDynamicText();

	//Ray HKY 2017.10.20: Show hot key text value
	case HWND_HOTKEY_TEXT_PANE_TEXT:
	  return _MApp_ZUI_ACT_GetHotKeyTextDynamicText();


        case HWND_HOTKEY_MTS_TEXT:
			#if ENABLE_ATSC
			MApp_ZUI_API_LoadString(en_str_MTS, CHAR_BUFFER);
			switch(g_u8AudLangSelected)
			{
				case SOUND_MTS_MONO:
					u16TempID = en_str_Mono;
					break;
				case SOUND_MTS_STEREO:
					u16TempID = en_str_Stereo;
					break;
				case SOUND_MTS_SAP:
					u16TempID = en_str_SAP;
					break;
				default:
					//
					break;
			}
			return MApp_ZUI_API_GetString(u16TempID);
			#else
            u16TempID = _MApp_ZUI_ACT_GetATVMTSStringID();
			#endif
            break;

        case HWND_HOTKEY_FREEZE_TEXT:
            return _MApp_ZUI_ACT_GeHotkeyFreezeDynamicText();

        #if (ENABLE_PIP)
        case HWND_HOTKEY_PIP_MODE_TEXT:
            if(IsPIPSupported())
            {
                switch(MApp_Get_PIPMode())
                {
                   default:
                   case EN_PIP_MODE_PIP:
                        u16TempID = en_str_PIP;
                        break;
                   case EN_PIP_MODE_POP_FULL:
                        u16TempID = en_str_POP_FULL;
                        break;
                   case EN_PIP_MODE_POP:
                        u16TempID = en_str_POP;
                        break;
                   case EN_PIP_MODE_OFF:
                        u16TempID = en_str_Off;
                        break;
                }
            }
            break;
        #endif
        default:
            break;

    }

    if (u16TempID != Empty)
        return MApp_ZUI_API_GetString(u16TempID);
    return 0; //for empty string....
}

#undef MAPP_ZUI_ACTHOTKEY_C
