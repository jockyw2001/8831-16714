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
// (¡§MStar Confidential Information¡¨) by the recipient.
// Any unauthorized act including without limitation unauthorized disclosure,
// copying, use, reproduction, sale, distribution, modification, disassembling,
// reverse engineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
////////////////////////////////////////////////////////////////////////////////

#define MAPP_ZUI_ACTMAINPAGE_C
#define _ZUI_INTERNAL_INSIDE_ //NOTE: for ZUI internal

#ifdef MSOS_TYPE_LINUX
#include <unistd.h>
#endif

//-------------------------------------------------------------------------------------------------
// Include Files
//-------------------------------------------------------------------------------------------------
#include "Board.h"
#include "datatype.h"
#include "MsCommon.h"

#include "MApp_GlobalSettingSt.h"
#include "msAPI_Global.h"
#include "MApp_ZUI_Main.h"
#include "MApp_ZUI_APIcommon.h"
#include "MApp_ZUI_APIstrings.h"
#include "MApp_ZUI_APIwindow.h"
#include "ZUI_tables_h.inl"
#include "MApp_ZUI_APIgdi.h"
#include "MApp_ZUI_APIcontrols.h"
#include "MApp_ZUI_ACTmainpage.h"
#include "MApp_ZUI_ACTeffect.h"
#include "MApp_ZUI_ACTglobal.h"
#include "MApp_ZUI_ACTaudlang.h"
#include "MApp_ZUI_APIdraw.h"
#include "MApp_ZUI_ACTglobal.h"
#include "MApp_ZUI_APIcomponent.h"
#include "OSDcp_String_EnumIndex.h"
#include "OSDcp_Bitmap_EnumIndex.h"
#include "ZUI_exefunc.h"

#include "MApp_Menu_Main.h"

#include "MApp_GlobalFunction.h"
#include "MApp_UiMenuDef.h"
#include "MApp_ZUI_ACTmenufunc.h"
#include "MApp_ZUI_ACTsetclockfunc.h"
#include "MApp_ZUI_ACTnetconfig.h"
#include "MApp_ZUI_ACTtuneconfirmfunc.h"
#include "MApp_ZUI_ACTmenudlgfunc.h"
#include "MApp_ZUI_ACTsublang.h"

#if (ENABLE_ATSC)
#include "MApp_ChannelProc_ATSC.h"
#include "MApp_Scan_ATSC.h"
#include "MApp_VChip.h"
#include "MApp_DataBase_CH.h"
#include "MApp_UiMenuFunc_ATSC.h"
#include "MApp_TV.h"
#include "MApp_TopStateMachine.h"
#include "MApp_Psip.h"
#endif

#if (ENABLE_DTV)
#include "mapp_demux.h"
#if ENABLE_OAD
#include "MApp_OAD.h"
#endif
#endif
#include "MApp_ChannelChange.h"
#include "msAPI_OSD.h"
#include <stdio.h>
#include <string.h>
#include "MApp_PrEdit_Main.h"
#include "MApp_OSDPage_Main.h"

#if ENABLE_CI
#include "msAPI_CI.h"
#endif

#include "MApp_InputSource.h"
#include "MApp_ZUI_ACTinputsource.h"
#include "MApp_ZUI_APIalphatables.h"
#include "MApp_ZUI_APIstyletables.h"
#include "MApp_UiPvr.h"
#include "msAPI_OCP.h"
#include "MApp_Font.h"
#if ENABLE_DMP
#include "MApp_DMP_Main.h"
#endif

#if ENABLE_DVBC
#include "MApp_ZUI_ACTcadtvmanualtuning.h"
#include "MApp_CADTV_Proc.h"
#include "MApp_Scan.h"
#endif


#if (ENABLE_EWS)
#include "MApp_EWS.h"
#endif


#if (ENABLE_DTV)
#include "MApp_MultiTasks.h"
#endif

#if (ENABLE_MFC_6M20)
#include "drvUrsaMFC.h"
#include "drvUrsaMFCAPI.h"
#include "mapp_swupdate.h"
#endif
#if (ENABLE_CI_PLUS)
#include "MApp_CIMMI.h"
#endif
#if ENABLE_MFC_6M30
#include "drvUrsa6M30.h"
#endif

#if (ENABLE_PIP)
#include "MApp_PIP.h"
#endif

#if (ENABLE_CEC)
#include "msAPI_CEC.h"
#endif

#include "drvIPAUTH.h"

#if MHEG5_ENABLE
#include "msAPI_DrvInit.h"
#include "msAPI_MHEG5.h"
#include "MApp_MHEG5_Main.h"
#endif

//****MENU_FUNC
#include "MApp_MenuFunc.h"
#include "msAPI_Timer.h"
//#if (ENABLE_EWS)
//#include "mapp_si.h"
//#endif

#include "MApp_ZUI_EventNotify.h"
#include "MApp_Func_Mainpage.h"
#if ENABLE_ATSC_TTS
#include "MApp_TTSControlHandler.h"
#endif
#include "MApp_NoOperate_AutoSleep.h"

#include "MApp_Standby.h"			//Ray DPW 2017.06.05: To access sFlagSimPowerShutDown

extern unsigned char code Customer_hash[];
extern unsigned char Customer_info[];
/////////////////////////////////////////////////////////////////////
extern U8 PicAutoColorGainResult;			//Ray VGA 2017.05.25

#if (ENABLE_DVB_TAIWAN_APP)
extern EN_ANT_TYPE msAPI_ATV_GetCurrentAntenna(void);
#endif
#if (ENABLE_EWS)

extern BOOLEAN bEWS_Vaild;
extern BOOLEAN bNeedShowEWS;
extern BOOLEAN bFROM_ChannelMenu;


extern U8 u8Temp_EWS_Num1 ;
extern U8 u8Temp_EWS_Num2 ;
extern U8 u8Temp_EWS_Num3 ;
extern U8 u8Temp_EWS_Num4 ;
extern U8 u8Temp_EWS_Num5 ;

#endif

#if ENABLE_ATSC_TTS
U8 u8Verbosity = 0;
U8 u8RateSupport = 0;
U8 u8Pitch = 0;
#endif

extern EN_MENU_STATE enMainMenuState;

static EN_MENU_STATE _enTargetMenuState;

COMMON_DLG_MODE _eCommonDlgMode, _ePrevCommonDlgMode;

COMMON_SINGLELIST_MODE _eCommonSingleMode;

//replaced by focus checkpoint: HWND            _hwndCommonDlgPrevFocus;
HWND            _hwndCommonDlgTargetFocus;

extern EN_OSD_TUNE_TYPE_SETTING eTuneType;
extern U16 _MApp_ZUI_ACT_PasswordConvertToSystemFormat(U16 password);
extern void _MApp_ZUI_API_ConvertComponentToDynamic(DRAWCOMPONENT comp, U16 u16CompIndex, void * pDraw);

extern BOOLEAN _MApp_ZUI_API_AllocateVarData(void);
extern LPTSTR MApp_ZUI_ACT_GetAppDynamicText(HWND hwnd);
extern void MApp_ZUI_SwUpdate_ProgressBar(U8 percent);

#if NTV_FUNCTION_ENABLE
extern U8 MApp_ZUI_ACT_Install_GetTuningMenuCountryIndex(void);
#endif
#if ENABLE_T_C_COMBO
extern EN_DVB_TYPE MApp_DVBType_GetCurrentType(void);
extern BOOL bIsDVBCScan;
#endif

ST_OSD_SELECTION_STRING_MAPPING_LIST _ZUI_TBLSEG _app_items[] =
{
#if ENABLE_DMP
{
      UI_INPUT_SOURCE_DMP,
      en_str_DMP
},
#endif

#if 0//def ENABLE_GYM
{
          UI_INPUT_SOURCE_GYM,
          en_str_GYM
},
#endif

{ //The last item, to prevent there is no app in the list.
          UI_INPUT_SOURCE_NONE,
          en_str_dashdash
},
};
ST_OSD_SELECTION_STRING_MAPPING_LIST _ZUI_TBLSEG stTimezoneList[] =
{
#if ENABLE_SBTVD_BRAZIL_APP
    {TIMEZONE_AM_WEST, en_str_TimeZone_Text_G90},
    {TIMEZONE_ACRE, en_str_Acre},
    {TIMEZONE_M_GROSSO, en_str_Mdot_Grosso},
    {TIMEZONE_NORTH, en_str_North},
    {TIMEZONE_BRASILIA, en_str_Brasilia},
    {TIMEZONE_NORTHEAST, en_str_Northeast},
    {TIMEZONE_F_NORONHA, en_str_Fdot_Noronha},
#else
    {TIMEZONE_CANARY, en_str_TimeZone_Text_G00},
    {TIMEZONE_LISBON, en_str_TimeZone_Text_G01},
    {TIMEZONE_LONDON, en_str_TimeZone_Text_G02},
    {TIMEZONE_RABAT, en_str_TimeZone_Text_G03},
    {TIMEZONE_AMSTERDAM, en_str_TimeZone_Text_G10},
    {TIMEZONE_BEOGRAD, en_str_TimeZone_Text_G11},
    {TIMEZONE_BERLIN, en_str_TimeZone_Text_G12},
    {TIMEZONE_BRUSSELS, en_str_TimeZone_Text_G20},
    {TIMEZONE_BUDAPEST, en_str_TimeZone_Text_G21},
    {TIMEZONE_COPENHAGEN, en_str_TimeZone_Text_G22},
    {TIMEZONE_LIUBLJANA, en_str_TimeZone_Text_G30},
    {TIMEZONE_LUXEMBOURG, en_str_TimeZone_Text_G31},
    {TIMEZONE_MADRID, en_str_TimeZone_Text_G32},
    {TIMEZONE_OSLO, en_str_TimeZone_Text_G40},
    {TIMEZONE_PARIS, en_str_TimeZone_Text_G41},
    {TIMEZONE_PRAGUE, en_str_TimeZone_Text_G42},
    {TIMEZONE_BRATISLAVA, en_str_TimeZone_Text_G43},
    {TIMEZONE_BERN, en_str_TimeZone_Text_G44},
    {TIMEZONE_ROME, en_str_TimeZone_Text_G50},
    {TIMEZONE_STOCKHOLM, en_str_TimeZone_Text_G51},
    {TIMEZONE_WARSAW, en_str_TimeZone_Text_G52},
    {TIMEZONE_VIENNA, en_str_TimeZone_Text_G60},
    {TIMEZONE_ZAGREB, en_str_TimeZone_Text_G61},
    {TIMEZONE_TUNIS, en_str_TimeZone_Text_G13},
    {TIMEZONE_ALGIERS, en_str_TimeZone_Text_G14},
    {TIMEZONE_ATHENS, en_str_TimeZone_Text_G62},
    {TIMEZONE_BUCURESTI, en_str_TimeZone_Text_G70},
    {TIMEZONE_HELSINKI, en_str_TimeZone_Text_G71},
    {TIMEZONE_SOFIA, en_str_TimeZone_Text_G72},
    {TIMEZONE_CAIRO, en_str_TimeZone_Text_G73},
    {TIMEZONE_CAPE_TOWN, en_str_TimeZone_Text_G74},
    {TIMEZONE_JERUSSLEM, en_str_TimeZone_Text_G75},
    {TIMEZONE_TURKEY, en_str_TimeZone_Text_G76},
    {TIMEZONE_MOSCOW, en_str_TimeZone_Text_G80},
    {TIMEZONE_TEHERAN, en_str_TimeZone_Text_G78},
    {TIMEZONE_ABU_DHABI, en_str_TimeZone_Text_G79},
    {TIMEZONE_WA, en_str_TimeZone_Text_G85},
    {TIMEZONE_BEIJING, en_str_TimeZone_Text_G97},
    {TIMEZONE_SA, en_str_TimeZone_Text_G84},
    {TIMEZONE_NT, en_str_TimeZone_Text_G87},
    {TIMEZONE_NSW, en_str_TimeZone_Text_G81},
    {TIMEZONE_VIC, en_str_TimeZone_Text_G82},
    {TIMEZONE_QLD, en_str_TimeZone_Text_G83},
    {TIMEZONE_TAS, en_str_TimeZone_Text_G86},
    {TIMEZONE_NZST, en_str_TimeZone_Text_G88},
    {TIMEZONE_AZORES, en_str_TimeZone_Text_G89},
#endif
};

static HWND _ZUI_TBLSEG page_hide_ball[][1] =
{
			#ifdef sTriviewOSDStyle 	//Close Icon Page
        //{ HWND_MENU_BOTTOM_BALL_FOCUS_CHANNEL},
        { HWND_MENU_BOTTOM_BALL_FOCUS_PICTURE},
        { HWND_MENU_BOTTOM_BALL_FOCUS_SOUND},
        { HWND_MENU_BOTTOM_BALL_FOCUS_OPTION},
        //{ HWND_MENU_BOTTOM_BALL_FOCUS_APP},		//Ray DMP 2017.04.19: Disable APP icon so user cannot access DMP directly
        //{ HWND_MENU_BOTTOM_BALL_FOCUS_TIME},
    		//#if ENABLE_DTV
        //{ HWND_MENU_BOTTOM_BALL_FOCUS_LOCK},
    		//#endif        	
			#else
        { HWND_MENU_BOTTOM_BALL_FOCUS_CHANNEL},
        { HWND_MENU_BOTTOM_BALL_FOCUS_PICTURE},
        { HWND_MENU_BOTTOM_BALL_FOCUS_SOUND},
        { HWND_MENU_BOTTOM_BALL_FOCUS_OPTION},
        { HWND_MENU_BOTTOM_BALL_FOCUS_TIME},
    		#if ENABLE_DTV
        { HWND_MENU_BOTTOM_BALL_FOCUS_LOCK},
    		#endif
        { HWND_MENU_BOTTOM_BALL_FOCUS_APP},
      #endif  
};

#if ENABLE_CEC
extern U8* u8HDMI_CEC_DevicesName[10];
extern HWND _ZUI_TBLSEG hdmi_cec_UI_list[] ;
#endif
extern void MApp_ZUI_ACT_SetTuningCountryIndex(U8 u8Index);
extern U8 MApp_ZUI_ACT_GetTuningCountryIndexMax(void);
extern U8 MApp_ZUI_ACT_GetTuningCountryIndex(void);
extern LPTSTR MApp_ZUI_ACT_GetCountryStringByIndex(U8 u8Index);


U16 TopIconAlpha[2][2];  //for save dynamic Alpha//save hwnd and Alpha

#if (ENABLE_ATSC)
#if ENABLE_ATSC_MENU_UI

static const HWND _MenuRRTAdjPageHwndList[]=
{
    HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM0,
    HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM1,
    HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM2,
    HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM3,
    HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM4,
    HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM5,
    HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM6,
    HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM7,
    HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM8,
    HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM9
};

static const HWND _MenuRRTDimensionHwndList[]=
{
    HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM0,
    HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM1,
    HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM2,
    HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM3,
    HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM4,
    HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM5,
    HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM6,
    HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM7,
    HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM8,
    HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM9,
};

BOOLEAN MApp_ZUI_ACT_MainMenuCurDimRRTIsAllRating(U8 u8CurDimension)
{
    U8 u8Temp;
    for(u8Temp=0; u8Temp<stGenSettingVchipRegion5.stRegin5Dimension[u8CurDimension].u8Values_Defined; u8Temp++)
    {
        if((0x01<<u8Temp & stGenSettingVchipRegion5.stRegin5Dimension[u8CurDimension].u32CurrentOption)==0)
        {
            return FALSE;
        }
    }
    return TRUE;
}

#if ENABLE_VCHIP_ALL_AS_AGEBASED
void MApp_ZUI_ACT_TV_Rating_Disable_BG(void)
{
     // TV-Y
    if (stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_Y & VCHIP_TVRATING_ALL)
    {
        MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVY_ALL_BG, FALSE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVY7_ALL_BG, FALSE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVG_ALL_BG, FALSE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_ALL_BG, FALSE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_ALL_BG, FALSE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_ALL_BG, FALSE);
    }
    else if (stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_Y7 & VCHIP_TVRATING_ALL)
    {
        MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVY7_ALL_BG, FALSE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVG_ALL_BG, FALSE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_ALL_BG, FALSE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_ALL_BG, FALSE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_ALL_BG, FALSE);
    }

    // TV-G
    if (stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_G & VCHIP_TVRATING_ALL)
    {
        MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVG_ALL_BG, FALSE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_ALL_BG, FALSE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_ALL_BG, FALSE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_ALL_BG, FALSE);
    }
    else
    {
        if (stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_PG & VCHIP_TVRATING_ALL)
        {
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_ALL_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_ALL_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_ALL_BG, FALSE);
        }
        else if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_14 & VCHIP_TVRATING_ALL)
        {
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_ALL_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_ALL_BG, FALSE);
        }
        else if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_MA & VCHIP_TVRATING_ALL)
        {
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_ALL_BG, FALSE);
        }
    }

     // TVRating FV
     if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_Y7 & VCHIP_TVRATING_FV)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVY7_FV_BG, FALSE);
     }

     // TVRating V
     if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_PG & VCHIP_TVRATING_V)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_V_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_V_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_V_BG, FALSE);
     }
     else if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_14 & VCHIP_TVRATING_V)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_V_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_V_BG, FALSE);
     }
     else if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_MA & VCHIP_TVRATING_V)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_V_BG, FALSE);
     }

     // TVRating S
     if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_PG & VCHIP_TVRATING_S)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_S_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_S_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_S_BG, FALSE);
     }
     else if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_14 & VCHIP_TVRATING_S)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_S_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_S_BG, FALSE);
     }
     else if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_MA & VCHIP_TVRATING_S)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_S_BG, FALSE);
     }

     // TVRating L
     if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_PG & VCHIP_TVRATING_L)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_L_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_L_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_L_BG, FALSE);
     }
     else if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_14 & VCHIP_TVRATING_L)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_L_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_L_BG, FALSE);
     }
     else if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_MA & VCHIP_TVRATING_L)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_L_BG, FALSE);
     }

     // TVRating D
     if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_PG & VCHIP_TVRATING_D)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_D_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_D_BG, FALSE);
     }
     else if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_14 & VCHIP_TVRATING_D)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_D_BG, FALSE);
     }
}
#else
void MApp_ZUI_ACT_TV_Rating_Disable_BG(void)
{
     // TV-NONE
     if (stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_NONE & VCHIP_TVRATING_ALL)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV_NONE_ALL_BG, FALSE);
     }

     // TV-Y & TV-Y7
     if (stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_Y & VCHIP_TVRATING_ALL)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVY_ALL_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVY7_ALL_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVY7_FV_BG, FALSE);
     }
     else if (stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_Y7 & VCHIP_TVRATING_ALL)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVY7_ALL_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVY7_FV_BG, FALSE);
     }
     else if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_Y7 & VCHIP_TVRATING_FV)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVY7_FV_BG, FALSE);
     }

     // TV-G
     if (stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_G & VCHIP_TVRATING_ALL)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVG_ALL_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_ALL_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_ALL_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_ALL_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_V_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_V_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_V_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_S_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_S_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_S_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_L_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_L_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_L_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_D_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_D_BG, FALSE);
     }
     else
     {
        if (stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_PG & VCHIP_TVRATING_ALL)
        {
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_ALL_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_ALL_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_ALL_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_V_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_V_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_V_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_S_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_S_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_S_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_L_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_L_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_L_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_D_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_D_BG, FALSE);
        }
        else if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_14 & VCHIP_TVRATING_ALL)
        {
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_ALL_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_ALL_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_V_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_V_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_S_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_S_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_L_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_L_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_D_BG, FALSE);
        }
        else if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_MA & VCHIP_TVRATING_ALL)
        {
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_ALL_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_V_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_S_BG, FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_L_BG, FALSE);
        }
     }

     // TVRating V
     if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_PG & VCHIP_TVRATING_V)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_V_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_V_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_V_BG, FALSE);
     }
     else if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_14 & VCHIP_TVRATING_V)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_V_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_V_BG, FALSE);
     }
     else if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_MA & VCHIP_TVRATING_V)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_V_BG, FALSE);
     }

     // TVRating S
     if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_PG & VCHIP_TVRATING_S)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_S_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_S_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_S_BG, FALSE);
     }
     else if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_14 & VCHIP_TVRATING_S)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_S_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_S_BG, FALSE);
     }
     else if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_MA & VCHIP_TVRATING_S)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_S_BG, FALSE);
     }

     // TVRating L
     if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_PG & VCHIP_TVRATING_L)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_L_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_L_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_L_BG, FALSE);
     }
     else if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_14 & VCHIP_TVRATING_L)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_L_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_L_BG, FALSE);
     }
     else if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_14 & VCHIP_TVRATING_D)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_D_BG, FALSE);
     }

     // TVRating D
     if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_PG & VCHIP_TVRATING_D)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_D_BG, FALSE);
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_D_BG, FALSE);
     }
     else if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_MA & VCHIP_TVRATING_L)
     {
         MApp_ZUI_API_EnableWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_L_BG, FALSE);
     }
}
#endif
#endif
#endif

U16 MApp_ZUI_ACT_GetAppItemString(int APPindex)
{
    U8 app_num = COUNTOF(_app_items);

    //prevent no app in list
    if(APPindex == 0 && (_app_items[0].u16SelectionItem == (U16)UI_INPUT_SOURCE_NONE))
    {
        return _app_items[APPindex].u16StringIndex;
    }

    if(APPindex >= app_num - 1)
    {
        return Empty;
    }
    else
    {
        return _app_items[APPindex].u16StringIndex;
    }
}

E_UI_INPUT_SOURCE MApp_ZUI_ACT_GetAppItemSource(int APPindex)
{
       U8 app_num = COUNTOF(_app_items);
       if(APPindex >= app_num - 1)
       {
           return UI_INPUT_SOURCE_NUM;
       }
       else
       {
           return (E_UI_INPUT_SOURCE)_app_items[APPindex].u16SelectionItem;
       }
}
U8 MApp_ZUI_ACT_GetTimezoneMaxIndex(void)
{
    return (U8)(sizeof(stTimezoneList)/sizeof(stTimezoneList[0]))-1;
}
void MApp_ZUI_ACT_SetTimezoneIndex(U8 u8Index)
{
    if (u8Index > MApp_ZUI_ACT_GetTimezoneMaxIndex())
    {
        u8Index = 0;
    }
    MApp_MenuFunc_Setup_TimezoneIndex_Adjust((U8)stTimezoneList[u8Index].u16SelectionItem);

    MApp_ZUI_API_InvalidateWindow(HWND_MENU_TIME_TIMEZONE_PAGE);
    MApp_ZUI_API_InvalidateWindow(HWND_MENU_TIME_SET_CLOCK_OPTION);
}
U8 MApp_ZUI_ACT_GetTimezoneIndex(void)
{
    U8 u8Index = 0;
    for (u8Index = 0; u8Index <= MApp_ZUI_ACT_GetTimezoneMaxIndex(); u8Index++)
    {
        if (MApp_MenuFunc_Setup_TimezoneIndex_Get() == stTimezoneList[u8Index].u16SelectionItem)
        {
            return u8Index;
        }
    }
    return 0;
}
U16 MApp_ZUI_ACT_GetTimezoneStringID(EN_MENU_TIMEZONE timezone)
{
    U8 u8Index = 0;
    for (u8Index = 0; u8Index <= MApp_ZUI_ACT_GetTimezoneMaxIndex(); u8Index++)
    {
        if (timezone == (EN_MENU_TIMEZONE)stTimezoneList[u8Index].u16SelectionItem)
        {
            return stTimezoneList[u8Index].u16StringIndex;
        }
    }
    return Empty;
}
LPTSTR MApp_ZUI_ACT_GetTimezoneStringByIndex(U8 u8Index)
{
    if (u8Index > MApp_ZUI_ACT_GetTimezoneMaxIndex())
    {
        return MApp_ZUI_API_GetString(Empty);
    }

    return MApp_ZUI_API_GetString(stTimezoneList[u8Index].u16StringIndex);
}

U8 MApp_ZUI_ACT_GetOsdLanguageIndex(void)
{
    return GET_OSD_MENU_LANGUAGE_DTG();
}

U8 MApp_ZUI_ACT_GetAudioLanguageIndex(void)
{
    return GET_AUDIO_MENU_LANGUAGE_DTG();
}


U8 MApp_ZUI_ACT_GetSubLanguageIndex(void)
{
    return GET_SUB_MENU_LANGUAGE_DTG();
}

void MApp_ZUI_ACT_SetOsdLanguageIndex(U8 u8Index)
{
    SET_OSD_MENU_LANGUAGE((EN_LANGUAGE)u8Index);
    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_OPTION_OSDLANG_PAGE);
}

void MApp_ZUI_ACT_SetAudioLanguageIndex(U8 u8Index)
{
    SET_AUDIO_MENU_LANGUAGE((EN_LANGUAGE)u8Index);
    MApp_ZUI_API_InvalidateWindow(HWND_MENU_OPTION_AUDIOLANG_PAGE);
}

void MApp_ZUI_ACT_SetSubLanguageIndex(U8 u8Index)
{
    SET_SUB_MENU_LANGUAGE((EN_LANGUAGE)u8Index);
    MApp_ZUI_API_InvalidateWindow(HWND_MENU_OPTION_SUBLANG_PAGE);
}

LPTSTR MApp_ZUI_ACT_GetMenuLanguageStringByIndex(U8 u8Index)
{
    U16 u16TempID = Empty;

    if(u8Index <= LANGUAGE_MENU_MAX)
    {
        u16TempID = _MApp_ZUI_ACT_GetLanguageStringID((EN_LANGUAGE)u8Index, FALSE);
        if (u16TempID != Empty)
            return MApp_ZUI_API_GetString(u16TempID);
    }
    return 0; //for empty string....
}

LPTSTR MApp_ZUI_ACT_GetSubtitleLanguageStringByIndex(U8 u8Index)
{
    U16 u16TempID = Empty;
    if(OSD_COUNTRY_SETTING == E_NEWZEALAND)
    {
        if(u8Index <= LANGUAGE_SUBTITLE_MAX_NZ)
        {
            u16TempID = _MApp_ZUI_ACT_GetLanguageStringID((EN_LANGUAGE)u8Index, FALSE);
            if (u16TempID != Empty)
                 return MApp_ZUI_API_GetString(u16TempID);
        }
    }
    else
    {
        if(u8Index <= LANGUAGE_SUBTITLE_MAX_EU)
        {
            u16TempID = _MApp_ZUI_ACT_GetLanguageStringID((EN_LANGUAGE)u8Index, FALSE);
            if (u16TempID != Empty)
                 return MApp_ZUI_API_GetString(u16TempID);
        }
    }
    return 0; //for empty string....
}


LPTSTR MApp_ZUI_ACT_GetLanguageStringByIndex(U8 u8Index)
{
    U16 u16TempID = Empty;
    if(OSD_COUNTRY_SETTING == E_NEWZEALAND)
    {
        if(u8Index <= LANGUAGE_AUDIO_MAX_NZ)
        {
            u16TempID = _MApp_ZUI_ACT_GetLanguageStringID((EN_LANGUAGE)u8Index, FALSE);
            if (u16TempID != Empty)
                 return MApp_ZUI_API_GetString(u16TempID);
        }
    }
    else
    {
        if(u8Index <= LANGUAGE_AUDIO_MAX_EU)
        {
            u16TempID = _MApp_ZUI_ACT_GetLanguageStringID((EN_LANGUAGE)u8Index, FALSE);
            if (u16TempID != Empty)
                 return MApp_ZUI_API_GetString(u16TempID);
        }
    }
    return 0; //for empty string....
}



///////////////////////////////////////////////////////////////////////////////
///  public  MApp_ZUI_ACT_ShowMainMenuBackgroundNoFocusIcon
///  Show main menu background without showing focus icon
///
///Ray OSD 2017.03.07
///////////////////////////////////////////////////////////////////////////////
void MApp_ZUI_ACT_ShowMainMenuBackgroundNoFocusIcon(void)
{
  MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_SHOW);
  //Hide unused menu icons
  MApp_ZUI_API_ShowWindow(HWND_MENU_BOTTOM_BALL_NORMAL_CHANNEL, SW_HIDE);
  MApp_ZUI_API_ShowWindow(HWND_MENU_BOTTOM_BALL_FOCUS_CHANNEL, SW_HIDE);
  MApp_ZUI_API_ShowWindow(HWND_MENU_BOTTOM_BALL_NORMAL_TIME, SW_HIDE);
  MApp_ZUI_API_ShowWindow(HWND_MENU_BOTTOM_BALL_FOCUS_TIME, SW_HIDE);
  MApp_ZUI_API_ShowWindow(HWND_MENU_BOTTOM_BALL_NORMAL_LOCK, SW_HIDE);
  MApp_ZUI_API_ShowWindow(HWND_MENU_BOTTOM_BALL_FOCUS_LOCK, SW_HIDE);
  MApp_ZUI_API_ShowWindow(HWND_MENU_BOTTOM_BALL_NORMAL_LOCK, SW_HIDE);
  MApp_ZUI_API_ShowWindow(HWND_MENU_BOTTOM_BALL_FOCUS_LOCK, SW_HIDE);
  ////Ray DMP 2017.04.26: Hidden App icon
  MApp_ZUI_API_ShowWindow(HWND_MENU_BOTTOM_BALL_NORMAL_APP, SW_HIDE);
  MApp_ZUI_API_ShowWindow(HWND_MENU_BOTTOM_BALL_FOCUS_APP, SW_HIDE);
  ////
  U8 i;
  for (i=0; i<COUNTOF(page_hide_ball); i++)
  {
     //Ray OSD 2017.03.07: Disable showing focus title icon.  It is shown by MApp_ZUI_API_CheckShowFocusTitleIcon instead
     MApp_ZUI_API_ShowWindow(page_hide_ball[i][0], SW_HIDE);

  }


}




void MApp_ZUI_ACT_ShowMainMenuBackground(HWND hwnd)
{
    MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_SHOW);
    #ifdef sTriviewOSDStyle	//Close Icon Page
  	  MApp_ZUI_API_ShowWindow(HWND_MENU_BOTTOM_BALL_NORMAL_CHANNEL, SW_HIDE);
    	MApp_ZUI_API_ShowWindow(HWND_MENU_BOTTOM_BALL_FOCUS_CHANNEL, SW_HIDE);
  	  MApp_ZUI_API_ShowWindow(HWND_MENU_BOTTOM_BALL_NORMAL_TIME, SW_HIDE);
    	MApp_ZUI_API_ShowWindow(HWND_MENU_BOTTOM_BALL_FOCUS_TIME, SW_HIDE);    	            
  	  MApp_ZUI_API_ShowWindow(HWND_MENU_BOTTOM_BALL_NORMAL_LOCK, SW_HIDE);
    	MApp_ZUI_API_ShowWindow(HWND_MENU_BOTTOM_BALL_FOCUS_LOCK, SW_HIDE);
    	//Ray DMP 2017.04.20: Disable display of APP icon so user cannot access DMP directly
    	MApp_ZUI_API_ShowWindow(HWND_MENU_BOTTOM_BALL_NORMAL_APP, SW_HIDE);
    	MApp_ZUI_API_ShowWindow(HWND_MENU_BOTTOM_BALL_FOCUS_APP, SW_HIDE);
    #else
	 		#if (ENABLE_DTV == 0)
  	  MApp_ZUI_API_ShowWindow(HWND_MENU_BOTTOM_BALL_NORMAL_LOCK, SW_HIDE);
    	MApp_ZUI_API_ShowWindow(HWND_MENU_BOTTOM_BALL_FOCUS_LOCK, SW_HIDE);
 			#endif
 		#endif

    U8 i;
    for (i=0; i<COUNTOF(page_hide_ball); i++)
    {
         if (hwnd == page_hide_ball[i][0])
         {
             MApp_ZUI_API_ShowWindow(page_hide_ball[i][0], SW_SHOW);
         }
         else
         {
              MApp_ZUI_API_ShowWindow(page_hide_ball[i][0], SW_HIDE);
         }
    }
}

#if (ENABLE_ATSC)
static void _MApp_ZUI_ACT_MainMenu_Indicate_Signal_Status(void)
{
    if (IsAtscInUse())
    {
        MApp_UiMenu_CheckTVSignal(DTV_SIGNAL);
        switch(enDTVSignalStatus)
        {
            case DTV_SIGNAL_NONE:
                MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_DTV_SIGNAL_QLITY_BAR_BAD,FALSE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_DTV_SIGNAL_QLITY_BAR_NORMAL,FALSE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_DTV_SIGNAL_QLITY_BAR_GOOD,FALSE);
                break;
            case DTV_SIGNAL_BAD:
                MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_DTV_SIGNAL_QLITY_BAR_BAD,TRUE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_DTV_SIGNAL_QLITY_BAR_NORMAL,FALSE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_DTV_SIGNAL_QLITY_BAR_GOOD,FALSE);
                break;
            case DTV_SIGNAL_NORMAL:
                MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_DTV_SIGNAL_QLITY_BAR_BAD,FALSE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_DTV_SIGNAL_QLITY_BAR_NORMAL,TRUE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_DTV_SIGNAL_QLITY_BAR_GOOD,FALSE);
                break;
            case DTV_SIGNAL_GOOD:
                MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_DTV_SIGNAL_QLITY_BAR_BAD,FALSE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_DTV_SIGNAL_QLITY_BAR_NORMAL,FALSE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_DTV_SIGNAL_QLITY_BAR_GOOD,TRUE);
                break;
            default:
                break;
        }

        if(stChSetting.u16MainListSrvNum > 0)
        {
            MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_DTV_SIGNAL_TEXT,TRUE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_DTV_SIGNAL_QULITY_TEXT, TRUE);
        }
        else
        {
            MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_DTV_SIGNAL_TEXT,FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_DTV_SIGNAL_QLITY_BAR_BAD,FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_DTV_SIGNAL_QLITY_BAR_NORMAL,FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_DTV_SIGNAL_QLITY_BAR_GOOD,FALSE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_DTV_SIGNAL_QULITY_TEXT,FALSE);
        }
    }
    else
    {
        MApp_UiMenu_CheckTVSignal(ATV_SIGNAL);
        MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_DTV_SIGNAL_TEXT,FALSE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_DTV_SIGNAL_QLITY_BAR_BAD,FALSE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_DTV_SIGNAL_QLITY_BAR_NORMAL,FALSE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_DTV_SIGNAL_QLITY_BAR_GOOD,FALSE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_DTV_SIGNAL_QULITY_TEXT,FALSE);
    }
}

static void _MApp_ZUI_ACT_InitializeMainMenu(void)
{
    //Initialize Main Menu Page
    if ((stChSetting.u16MainListSrvNum != 0)&&(stChSetting.u16TotalHideSrvNum < stChSetting.u16MainListSrvNum))
    {
        MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_FAVORITE, TRUE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_SHOW_HIDE, TRUE);
    }
    else if((stChSetting.u16MainListSrvNum != 0)&&(stChSetting.u16TotalHideSrvNum >= stChSetting.u16MainListSrvNum))
    {
        MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_FAVORITE,FALSE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_SHOW_HIDE, TRUE);
    }
    else
    {
        MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_FAVORITE, FALSE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_SHOW_HIDE, FALSE);
    }
#if 0
    if ( (stChSetting.u16MainListSrvNum != 0)&&(stChSetting.u16MainListSrvNum-stChSetting.u16TotalHideSrvNum>0) )
    {
        MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_CHANNEL_NO, TRUE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_CHANNEL_LABEL, TRUE);
    }
    else
    {
        MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_CHANNEL_NO, FALSE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_CHANNEL_LABEL, FALSE);
    }

#endif
    if(stGenSetting.g_SysSetting.fTimeAutoSync == TIME_AUTO_SYNC_ON)
    {
        MApp_ZUI_API_EnableWindow(HWND_MENU_TIME_SET_CLOCK,FALSE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_TIME_DST,FALSE);
    }
    else
    {
        MApp_ZUI_API_EnableWindow(HWND_MENU_TIME_SET_CLOCK, TRUE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_TIME_DST, TRUE);
    }
#if 0
    if(stGenSetting.g_SysSetting.enUIInputSourceType == UI_INPUT_SOURCE_DTV)
    {
        MApp_ZUI_API_EnableWindow(HWND_MENU_SOUND_MTS,FALSE);
    }
    else
    {
        MApp_ZUI_API_EnableWindow(HWND_MENU_SOUND_MTS, TRUE);
    }

#endif
    _MApp_ZUI_ACT_MainMenu_Indicate_Signal_Status();
#if 0
    g_u16Password = 0;
    g_u8PasswordCount = 0;
    g_u8PasswordPosition = 0;
#endif
    if(IsAtscInUse())
    {
        MApp_ZUI_API_EnableWindow(HWND_MENU_TIME_AUTO_SYNC,TRUE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_TIME_AUTO_SYNC_OPTION,TRUE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_TIME_AUTO_SYNC_TEXT,TRUE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_SOUND_MTS,FALSE);
    }
#if 0
    MApp_ZUI_API_SetTimer(HWND_MENU_BACKGROUND, 0, (U16)(MApp_UiMenuFunc_GetOsdTimeOut()));
    MApp_ZUI_API_SetTimer(HWND_MENU_MASK_BACKGROUND, 0, (U16)(MApp_UiMenuFunc_GetOsdTimeOut()));
#endif
}

#endif

#if ENABLE_DVBC
void MApp_ZUI_ACT_ShowDVBCScanPage(void)
{
    if(MApp_DVBC_SCAN_GetCurrentType() == OSD_DVBC_TYPE_FULL)
    {
        eTuneType = (EN_OSD_TUNE_TYPE_SETTING)OSD_TUNE_TYPE_DTV_PLUS_ATV;
        g_enScanType= SCAN_TYPE_AUTO;
    }
    else
    {
        eTuneType = (EN_OSD_TUNE_TYPE_SETTING)OSD_TUNE_TYPE_DTV_ONLY;
        g_enScanType= SCAN_TYPE_NETWORK;
    }
    MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_CLOSE, E_ZUI_STATE_TERMINATE);
    _enTargetMenuState = STATE_MENU_GOTO_CADTV_MANUALTUNING;
    bIsDVBCScan = TRUE;
    MApp_OSDPage_SetOSDPage(E_OSD_CADTV_MANUAL_TUNING);
}
#endif

///////////////////////////////////////////////////////////////////////////////
///  private  MApp_ZUI_ACT_AppShowMainMenu
///  [OSD page handler] provide for showing MENU application
///
///  @return no return value
///
///  @author MStarSemi @date 2007/1/25
///////////////////////////////////////////////////////////////////////////////
void MApp_ZUI_ACT_AppShowMainMenu()
{
    HWND wnd;
    RECT rect;
    E_OSD_ID osd_id = E_OSD_MAIN_MENU;

    g_GUI_WindowList = GetWindowListOfOsdTable(osd_id);
    g_GUI_WinDrawStyleList = GetWindowStyleOfOsdTable(osd_id);
    g_GUI_WindowPositionList = GetWindowPositionOfOsdTable(osd_id);
#if ZUI_ENABLE_ALPHATABLE
    g_GUI_WinAlphaDataList = GetWindowAlphaDataOfOsdTable(osd_id);
#endif
    HWND_MAX = GetWndMaxOfOsdTable(osd_id);
    OSDPAGE_BLENDING_ENABLE = IsBlendingEnabledOfOsdTable(osd_id);
    OSDPAGE_BLENDING_VALUE = GetBlendingValueOfOsdTable(osd_id);
    _enTargetMenuState = STATE_MENU_INIT;

    g_mainpage_common = EN_COMMON_INVALID;

    if (!_MApp_ZUI_API_AllocateVarData())
    {
        ZUI_DBG_FAIL(printf("[ZUI]ALLOC\n"));
        ABORT();
        return;
    }

    RECT_SET(rect,
        ZUI_MAIN_MENU_XSTART, ZUI_MAIN_MENU_YSTART,
        ZUI_MAIN_MENU_WIDTH, ZUI_MAIN_MENU_HEIGHT);

    if (!MApp_ZUI_API_InitGDI(&rect))
    {
        ZUI_DBG_FAIL(printf("[ZUI]GDIINIT\n"));
        ABORT();
        return;
    }

    #if ENABLE_PVR
#if (CHIP_FAMILY_TYPE != CHIP_FAMILY_S7L && CHIP_FAMILY_TYPE!=CHIP_FAMILY_EULER)
    MApp_ZUI_API_EnableFullScreenRelease(FALSE);  // Add to reduce the PVR write gap time related with main menu operation 20100721EL
#endif
    #endif

    #if (DTV_USE_FBL)
    {
        //disable de-blocking when enter Main Menu
        //for single MIU + FBL only
    #if(ENABLE_S2)
        if((IsDTVInUse() || IsS2InUse())&& MApi_XC_IsCurrentFrameBufferLessMode())
    #else
        if( IsDTVInUse() && MApi_XC_IsCurrentFrameBufferLessMode() )
    #endif
        {
            MApi_VDEC_DisableDeblocking(TRUE); //means disable deblocking, so that VDEC would need less bandwidth
            //printf("\n disable de-blocking \n");
        }
    }
    #endif

    for (wnd = 0; wnd < HWND_MAX; wnd++)
    {
        //printf("create msg: %lu\n", (U32)wnd);
        MApp_ZUI_API_SendMessage(wnd, MSG_CREATE, 0);
    }

#if(ENABLE_ATSC)
    _MApp_ZUI_ACT_InitializeMainMenu();
#endif

    MApp_ZUI_API_ShowWindow(HWND_MAINFRAME, SW_HIDE);
#if (ENABLE_DTV==0)
    MApp_ZUI_API_ShowWindow(HWND_MENU_BOTTOM_BALL_NORMAL_LOCK, SW_HIDE);
    MApp_ZUI_API_ShowWindow(HWND_MENU_BOTTOM_BALL_FOCUS_LOCK, SW_HIDE);
#endif


    switch(_enReturnMenuItem)
    {
    #if ENABLE_DTV
    case STATE_RETURN_PROGRAM_BLOCK:
        MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_PAGE, SW_SHOW);
        MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_LOCK);
        MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_LOCK_PAGE_LIST, HWND_MENU_LOCK_BLOCK_PROGRAM);
        break;
    #endif

    case STATE_RETURN_DTV_MANUAL_TUNING:
        MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_CHANNEL);
        MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE, SW_SHOW);
        MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_CHANNEL_PAGE_LIST, HWND_MENU_CHANNEL_DTV_MAN_TUNE);
        break;

    case STATE_RETURN_ATV_MANUAL_TUNING:
        MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_CHANNEL);
        MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE, SW_SHOW);
        MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_CHANNEL_PAGE_LIST, HWND_MENU_CHANNEL_ATV_MAN_TUNE);
        break;

    case STATE_RETURN_CADTV_MANUAL_TUNING:
#if ENABLE_T_C_COMBO
        if(bIsDVBCScan == TRUE)
            MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_TUNING_CONFIRM);
        else
        {
            MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_CHANNEL);
            MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE, SW_SHOW);
            MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_CHANNEL_PAGE_LIST, HWND_MENU_CHANNEL_CADTV_MAN_TUNE);
        }
#else
        MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_CHANNEL);
        MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE, SW_SHOW);
        MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_CHANNEL_PAGE_LIST, HWND_MENU_CHANNEL_CADTV_MAN_TUNE);
#endif
        break;

#if 0//ENABLE_T_C_COMBO
    case STATE_RETURN_DVBC_SCAN_TUNING:
        MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_DVB_SELECT_MENU, SW_SHOW);
        if(MApp_DVBType_GetCurrentType() == EN_DVB_C_TYPE)
            MApp_ZUI_API_SetFocus(HWND_SELECTED_DVBC_BG);
        else
            MApp_ZUI_API_SetFocus(HWND_SELECTED_DVBT_BG);
        break;
#endif

    case STATE_RETURN_PROGRAM_EDIT:
        MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_CHANNEL);
        MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE, SW_SHOW);
        MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_CHANNEL_PAGE_LIST, HWND_MENU_CHANNEL_PROGRAM_EDIT);
        break;

    case STATE_RETURN_PVR_FILE_SYS:
        MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_OPTION);
        MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_SHOW);
        MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_OPTION_PAGE_LIST, HWND_MENU_OPTION_PVR_FILE_SYSTEM);
        break;

    case STATE_RETUNR_INSTALL_GUIDE:
        break;

#if ENABLE_ATSC_INSTALLGUIDE
    case STATE_RETURN_SETUP_WIZARD:
        MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_SHOW);
        MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_OPTION);
        MApp_ZUI_API_SetFocus(HWND_MENU_OPTION_SETUPWIZARD);
        break;
#endif

    case STATE_RETURN_NULL:
    default:
    		#ifdef MSD8220_ReferCodeBase
            /*MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_CHANNEL);
            if(IsDTVInUse()||IsATVInUse())
            {
                //MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_CHANNEL);
                //MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE, SW_SHOW);
                //MApp_ZUI_API_SetFocus(HWND_MENU_CHANNEL_ANTENNA);
            }
            else if(IsStorageInUse())
            {
                //MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_APP);
                //MApp_ZUI_API_ShowWindow(HWND_MENU_APP_PAGE, SW_SHOW);
                //MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_APP_PAGE_LIST,HWND_MENU_APP_MENU_ITEM_01);
            }
            else
            {*/
                MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_PICTURE);
                MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_PAGE, SW_SHOW);
                MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_PICTURE_PAGE_LIST,HWND_MENU_PICTURE_TITLE);	//Ray OSD 2017.02.28: Change Picture title as first item to be focus
                //MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_PICTURE_PAGE_LIST,HWND_MENU_PICTURE_PICMODE);
            //}
            break;    		
    		#else
        {
            MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_CHANNEL);
            MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE, SW_SHOW);
            MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_CHANNEL_PAGE_LIST, HWND_MENU_CHANNEL_AUTOTUNE);
            //MApp_ZUI_API_SendMessage(HWND_MENU_CHANNEL_PAGE_LIST, MSG_USER, HWND_MENU_CHANNEL_AUTOTUNE);
        }
        #endif
    }
    _enReturnMenuItem = STATE_RETURN_NULL;
    MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_OPEN, E_ZUI_STATE_RUNNING);

}

//Ray OSD 2017.06.01: Press IR OSD Next key and go to next menu page
void MApp_ZUI_ACT_MainPageOSDNextKey(void)
{
  HWND hwnd;
  hwnd = MApp_ZUI_API_GetFocus();

  switch(hwnd)
  {
	//Ray OSD 2017.06.01: Go to Option menu and set focus on to option icon
	case HWND_MENU_PICTURE_TITLE:
	case HWND_MENU_PICTURE_INPUTSOURCE:
	case HWND_MENU_PICTURE_PICMODE:
	case HWND_MENU_PICTURE_COLOR_TEMP:
	case HWND_MENU_PICTURE_ASPECT_RATIO:
	case HWND_MENU_PICTURE_NOISE_REDUCTION:
	case HWND_MENU_PICTURE_MPEG_NOISE_REDUCTION:
	case HWND_MENU_PICTURE_PC_ADJUST:
	case HWND_MENU_PICTURE_3DNR:
	case HWND_MENU_PICTURE_BACKLIGHT:
	case HWND_MENU_PICTURE_DLC:
	case HWND_MENU_PICTURE_COLRANGE:
	case HWND_MENU_PICTURE_PIP:
#if(SENSOR_CHIP!=NOT_SUPPORT_LIGHT_SENSOR)
	case HWND_MENU_PICTURE_LS:
#endif
	case HWND_MENU_PICTURE_VGA_SETUP:
	    MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_PAGE, SW_HIDE);
	    MApp_ZUI_ACT_ShowMainMenuBackgroundNoFocusIcon();
	    MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_SHOW);
	    MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_OPTION);
	    MApp_ZUI_API_SetFocus(HWND_MENU_OPTION_TITLE);
	    break;

	//Ray OSD 2017.06.01: Go to picture menu and set focus on to picture icon
	case HWND_MENU_SOUND_TITLE:
	case HWND_MENU_SOUND_VOLUME:
	case HWND_MENU_SOUND_SNDMODE:
	case HWND_MENU_SOUND_BALANCE:
	case HWND_MENU_SOUND_AUTO_VOLUME:
	case HWND_MENU_SOUND_EQUALIZER:
	case HWND_MENU_SOUND_SURROUND:
	case HWND_MENU_SOUND_DBX_TOTAL_SONICS:
	case HWND_MENU_SOUND_DBX_TOTAL_VOLUME:
	case HWND_MENU_SOUND_DBX_TOTAL_SURROUND:
	case HWND_MENU_SOUND_AD_SWITCH:
	case HWND_MENU_SOUND_SPDIF_MODE:
	case HWND_MENU_SOUND_AUDIO_DELAY:
	case HWND_MENU_SOUND_AUDIO_ONLY:
	case HWND_MENU_SOUND_AVC:
	case HWND_MENU_SOUND_TV_SPEAKER:
	    MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_PAGE, SW_HIDE);
	    MApp_ZUI_ACT_ShowMainMenuBackgroundNoFocusIcon();
	    MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_PAGE, SW_SHOW);
	    MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_PICTURE);
	    MApp_ZUI_API_SetFocus(HWND_MENU_PICTURE_TITLE);
	    break;


	 //Ray OSD 2017.06.01: Go to audio menu and set focus on to audio icon
	 case HWND_MENU_OPTION_TITLE:
	 case HWND_MENU_OPTION_OSD_LANG:
	 case HWND_MENU_SOUND_MTS:
	 case HWND_MENU_SOUND_VIDEO_DESCRIPTION:
	 case HWND_MENU_SOUND_AUDIO_LANGUAGE:
	 case HWND_MENU_OPTION_AUDIO_LANG:
	 case HWND_MENU_OPTION_SUBTITLE_LANG:
	 case HWND_MENU_OPTION_HARD_HEARING:
	 case HWND_MENU_OPTION_COUNTRY:
	 case HWND_MENU_OPTION_PVR_FILE_SYSTEM:
	 case HWND_MENU_OPTION_RSS:
	 case HWND_MENU_OPTION_EXTENSION:
	 case HWND_MENU_OPTION_CAPTION:
	 case HWND_MENU_OPTION_CLOSED_CAPTION:
	 case HWND_MENU_OPTION_SETUPWIZARD:
	 case HWND_MENU_OPTION_FACTORY_RESET:
	 case HWND_MENU_OPTION_IMG_ORIENT:
	 case HWND_MENU_OPTION_HDMI_CEC:
	 case HWND_MENU_OPTION_HDMI_ARC:
	 case HWND_MENU_OPTION_OSD_EFFECT:
	 case HWND_MENU_OPTION_DIVX:
	 case HWND_MENU_OPTION_CC_MODE:
	 case HWND_MENU_OPTION_CC_OPTION:
	 case HWND_MENU_OPTION_COLOR_RANGE:
	 case HWND_MENU_OPTION_3D_TYPE:
	 case HWND_MENU_OPTION_3D_TO_2D:
	 case HWND_MENU_OPTION_3D_DETECT:
	 case HWND_MENU_OPTION_3D_LR:
	 case HWND_MENU_OPTION_3D_HSHIFT:
	 case HWND_MENU_OPTION_3D_VIEW_POINT:
	 case HWND_MENU_OPTION_MFC:
	 case HWND_MENU_OPTION_6M30_MIRROR:
	 case HWND_MENU_OPTION_6M30_VERSION:
	 case HWND_MENU_OPTION_EPOP:
	 case HWND_MENU_OPTION_EDID_SWITCH:
	 case HWND_MENU_OPTION_TRANSPARENT:
	 case HWND_MENU_OPTION_SCART_IN:
	 case HWND_MENU_OPTION_TTS:
	 case HWND_MENU_OPTION_SW_USB_UPGRADE:
	 case HWND_MENU_OPTION_AUTO_SEEK:
	 case HWND_MENU_OPTION_FAILOVER:
	 case HWND_MENU_OPTION_DEFAULT_POWER:
	 case HWND_MENU_OPTION_BL_SETUP:
	    MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_HIDE);
	    MApp_ZUI_ACT_ShowMainMenuBackgroundNoFocusIcon();
	    MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_PAGE, SW_SHOW);
	    MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_SOUND);
	    MApp_ZUI_API_SetFocus(HWND_MENU_SOUND_TITLE);
	    break;

	 default:
	   break;

  }
}


//Ray OSD 2017.06.01: Press IR OSD Back key and go to previous menu page
void MApp_ZUI_ACT_MainPageOSDBackKey(void)
{
  HWND hwnd;
  hwnd = MApp_ZUI_API_GetFocus();

  switch(hwnd)
  {
	//Ray OSD 2017.06.01: Go to Audio menu and set focus on to audio icon
	case HWND_MENU_PICTURE_TITLE:
	case HWND_MENU_PICTURE_INPUTSOURCE:
	case HWND_MENU_PICTURE_PICMODE:
	case HWND_MENU_PICTURE_COLOR_TEMP:
	case HWND_MENU_PICTURE_ASPECT_RATIO:
	case HWND_MENU_PICTURE_NOISE_REDUCTION:
	case HWND_MENU_PICTURE_MPEG_NOISE_REDUCTION:
	case HWND_MENU_PICTURE_PC_ADJUST:
	case HWND_MENU_PICTURE_3DNR:
	case HWND_MENU_PICTURE_BACKLIGHT:
	case HWND_MENU_PICTURE_DLC:
	case HWND_MENU_PICTURE_COLRANGE:
	case HWND_MENU_PICTURE_PIP:
#if(SENSOR_CHIP!=NOT_SUPPORT_LIGHT_SENSOR)
	case HWND_MENU_PICTURE_LS:
#endif
	case HWND_MENU_PICTURE_VGA_SETUP:
	    MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_PAGE, SW_HIDE);
	    MApp_ZUI_ACT_ShowMainMenuBackgroundNoFocusIcon();
	    MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_PAGE, SW_SHOW);
	    MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_SOUND);
	    MApp_ZUI_API_SetFocus(HWND_MENU_SOUND_TITLE);
	    break;

	//Ray OSD 2017.06.01: Go to setup menu and set focus on to setup icon
	case HWND_MENU_SOUND_TITLE:
	case HWND_MENU_SOUND_VOLUME:
	case HWND_MENU_SOUND_SNDMODE:
	case HWND_MENU_SOUND_BALANCE:
	case HWND_MENU_SOUND_AUTO_VOLUME:
	case HWND_MENU_SOUND_EQUALIZER:
	case HWND_MENU_SOUND_SURROUND:
	case HWND_MENU_SOUND_DBX_TOTAL_SONICS:
	case HWND_MENU_SOUND_DBX_TOTAL_VOLUME:
	case HWND_MENU_SOUND_DBX_TOTAL_SURROUND:
	case HWND_MENU_SOUND_AD_SWITCH:
	case HWND_MENU_SOUND_SPDIF_MODE:
	case HWND_MENU_SOUND_AUDIO_DELAY:
	case HWND_MENU_SOUND_AUDIO_ONLY:
	case HWND_MENU_SOUND_AVC:
	case HWND_MENU_SOUND_TV_SPEAKER:
	    MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_PAGE, SW_HIDE);
	    MApp_ZUI_ACT_ShowMainMenuBackgroundNoFocusIcon();
	    MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_SHOW);
	    MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_OPTION);
	    MApp_ZUI_API_SetFocus(HWND_MENU_OPTION_TITLE);
	    break;


	 //Ray OSD 2017.06.01: Go to picture menu and set focus on to picture icon
	 case HWND_MENU_OPTION_TITLE:
	 case HWND_MENU_OPTION_OSD_LANG:
	 case HWND_MENU_SOUND_MTS:
	 case HWND_MENU_SOUND_VIDEO_DESCRIPTION:
	 case HWND_MENU_SOUND_AUDIO_LANGUAGE:
	 case HWND_MENU_OPTION_AUDIO_LANG:
	 case HWND_MENU_OPTION_SUBTITLE_LANG:
	 case HWND_MENU_OPTION_HARD_HEARING:
	 case HWND_MENU_OPTION_COUNTRY:
	 case HWND_MENU_OPTION_PVR_FILE_SYSTEM:
	 case HWND_MENU_OPTION_RSS:
	 case HWND_MENU_OPTION_EXTENSION:
	 case HWND_MENU_OPTION_CAPTION:
	 case HWND_MENU_OPTION_CLOSED_CAPTION:
	 case HWND_MENU_OPTION_SETUPWIZARD:
	 case HWND_MENU_OPTION_FACTORY_RESET:
	 case HWND_MENU_OPTION_IMG_ORIENT:
	 case HWND_MENU_OPTION_HDMI_CEC:
	 case HWND_MENU_OPTION_HDMI_ARC:
	 case HWND_MENU_OPTION_OSD_EFFECT:
	 case HWND_MENU_OPTION_DIVX:
	 case HWND_MENU_OPTION_CC_MODE:
	 case HWND_MENU_OPTION_CC_OPTION:
	 case HWND_MENU_OPTION_COLOR_RANGE:
	 case HWND_MENU_OPTION_3D_TYPE:
	 case HWND_MENU_OPTION_3D_TO_2D:
	 case HWND_MENU_OPTION_3D_DETECT:
	 case HWND_MENU_OPTION_3D_LR:
	 case HWND_MENU_OPTION_3D_HSHIFT:
	 case HWND_MENU_OPTION_3D_VIEW_POINT:
	 case HWND_MENU_OPTION_MFC:
	 case HWND_MENU_OPTION_6M30_MIRROR:
	 case HWND_MENU_OPTION_6M30_VERSION:
	 case HWND_MENU_OPTION_EPOP:
	 case HWND_MENU_OPTION_EDID_SWITCH:
	 case HWND_MENU_OPTION_TRANSPARENT:
	 case HWND_MENU_OPTION_SCART_IN:
	 case HWND_MENU_OPTION_TTS:
	 case HWND_MENU_OPTION_SW_USB_UPGRADE:
	 case HWND_MENU_OPTION_AUTO_SEEK:
	 case HWND_MENU_OPTION_FAILOVER:
	 case HWND_MENU_OPTION_DEFAULT_POWER:
	 case HWND_MENU_OPTION_BL_SETUP:
	    MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_HIDE);
	    MApp_ZUI_ACT_ShowMainMenuBackgroundNoFocusIcon();
	    MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_PAGE, SW_SHOW);
	    MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_PICTURE);
	    MApp_ZUI_API_SetFocus(HWND_MENU_PICTURE_TITLE);
	    break;

	 default:
	   break;

  }

}



void MApp_ZUI_ACT_MainPageMenuKey(void)
{
#if ENABLE_ATSC_MENU_UI
    HWND hwnd;
    hwnd = MApp_ZUI_API_GetFocus();
    //U32 U32ShowFlag;
    
    printf("MingYuan MApp_ZUI_ACT_MainPageMenuKey = %d \n",hwnd);	//Ray DBG 2017.02.28
    
    switch(hwnd)
    {
	//Ray OSD 2017.06.01: Pressing MENU key in Picture menu item will set focus on to picture icon
	case HWND_MENU_PICTURE_INPUTSOURCE:		//Ray SRC 2017.03.08: Add input source menu item here
  	case HWND_MENU_PICTURE_PICMODE:
	case HWND_MENU_PICTURE_COLOR_TEMP:
	case HWND_MENU_PICTURE_ASPECT_RATIO:
	case HWND_MENU_PICTURE_NOISE_REDUCTION:
	case HWND_MENU_PICTURE_MPEG_NOISE_REDUCTION:
	case HWND_MENU_PICTURE_PC_ADJUST:
	case HWND_MENU_PICTURE_3DNR:
	case HWND_MENU_PICTURE_BACKLIGHT:
	case HWND_MENU_PICTURE_DLC:
	case HWND_MENU_PICTURE_COLRANGE:
	case HWND_MENU_PICTURE_PIP:
				  #if(SENSOR_CHIP!=NOT_SUPPORT_LIGHT_SENSOR)
	case HWND_MENU_PICTURE_LS:
				  #endif
	case HWND_MENU_PICTURE_VGA_SETUP:		//Ray VGA 2017.04.12
	    MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_PICTURE);
	    MApp_ZUI_API_SetFocus(HWND_MENU_PICTURE_TITLE);
	    break;

	//Ray OSD 2017.06.01: Pressing MENU key in Sound menu item will set focus on to sound title icon
        case HWND_MENU_SOUND_VOLUME:			//Ray VOL 2017.03.10: Add sound volume
        case HWND_MENU_SOUND_SNDMODE:                                                     
        case HWND_MENU_SOUND_BALANCE:                                                      
        case HWND_MENU_SOUND_AUTO_VOLUME:                                               
        case HWND_MENU_SOUND_EQUALIZER:                                                   
        case HWND_MENU_SOUND_SURROUND:                                                     
        case HWND_MENU_SOUND_DBX_TOTAL_SONICS:                                
        case HWND_MENU_SOUND_DBX_TOTAL_VOLUME:                                     
        case HWND_MENU_SOUND_DBX_TOTAL_SURROUND:                                
        case HWND_MENU_SOUND_AD_SWITCH:                                                
        case HWND_MENU_SOUND_SPDIF_MODE:                                                
        case HWND_MENU_SOUND_AUDIO_DELAY:                                           
        case HWND_MENU_SOUND_AUDIO_ONLY:                                               
        case HWND_MENU_SOUND_AVC:                                                              
        case HWND_MENU_SOUND_TV_SPEAKER:
	    MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_SOUND);
	    MApp_ZUI_API_SetFocus(HWND_MENU_SOUND_TITLE);
	    break;


	//Ray OSD 2017.06.01: Pressing MENU key in Setup menu item will set focus on to setup title icon
        case HWND_MENU_OPTION_OSD_LANG:
       case HWND_MENU_SOUND_MTS:
       case HWND_MENU_SOUND_VIDEO_DESCRIPTION:
       case HWND_MENU_SOUND_AUDIO_LANGUAGE:
       case HWND_MENU_OPTION_AUDIO_LANG:
       case HWND_MENU_OPTION_SUBTITLE_LANG:
       case HWND_MENU_OPTION_HARD_HEARING:
       case HWND_MENU_OPTION_COUNTRY:
       case HWND_MENU_OPTION_PVR_FILE_SYSTEM:
       case HWND_MENU_OPTION_RSS:
       case HWND_MENU_OPTION_EXTENSION:
       case HWND_MENU_OPTION_CAPTION:
       case HWND_MENU_OPTION_CLOSED_CAPTION:
       case HWND_MENU_OPTION_SETUPWIZARD:
       case HWND_MENU_OPTION_FACTORY_RESET:
       case HWND_MENU_OPTION_IMG_ORIENT:		//Ray ORI 2017.05.05: Add image orientation to exit menu
       case HWND_MENU_OPTION_HDMI_CEC:
       case HWND_MENU_OPTION_HDMI_ARC:
       case HWND_MENU_OPTION_OSD_EFFECT:
       case HWND_MENU_OPTION_DIVX:
       case HWND_MENU_OPTION_CC_MODE:
       case HWND_MENU_OPTION_CC_OPTION:
       case HWND_MENU_OPTION_COLOR_RANGE:
       case HWND_MENU_OPTION_3D_TYPE:
       case HWND_MENU_OPTION_3D_TO_2D:
       case HWND_MENU_OPTION_3D_DETECT:
       case HWND_MENU_OPTION_3D_LR:
       case HWND_MENU_OPTION_3D_HSHIFT:
       case HWND_MENU_OPTION_3D_VIEW_POINT:
       case HWND_MENU_OPTION_MFC:
       case HWND_MENU_OPTION_6M30_MIRROR:
       case HWND_MENU_OPTION_6M30_VERSION:
       case HWND_MENU_OPTION_EPOP:
       case HWND_MENU_OPTION_EDID_SWITCH:
       case HWND_MENU_OPTION_TRANSPARENT:
       case HWND_MENU_OPTION_SCART_IN:
       case HWND_MENU_OPTION_TTS:
       case HWND_MENU_OPTION_SW_USB_UPGRADE:
       case HWND_MENU_OPTION_AUTO_SEEK:			//Ray ASS 2017.03.01
       case HWND_MENU_OPTION_FAILOVER:			//Ray DMP 2017.04.12
       case HWND_MENU_OPTION_DEFAULT_POWER:		//Ray DPW 2017.05.29
       case HWND_MENU_OPTION_BL_SETUP:			//Ray BKL 2017.04.26
	    MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_OPTION);
	    MApp_ZUI_API_SetFocus(HWND_MENU_OPTION_TITLE);
	    break;

    	#ifdef sTriviewKeypadStyle
    	//----------------------------
	case HWND_MENU_PICTURE_TITLE:			//Ray OSD 2017.02.28: Add picture title


        //----------------------------
        case HWND_MENU_SOUND_TITLE:			//Ray OSD 2017.02.28: Add sound title to exit menu

        //----------------------------
        case HWND_MENU_TIME_SET_CLOCK:                                                   
        case HWND_MENU_TIME_SET_OFFTIME:                                                
        case HWND_MENU_TIME_SET_ONTIME:                                                    
        case HWND_MENU_TIME_SET_SLEEP_TIMER:                                        
        case HWND_MENU_TIME_SET_AUTO_SLEEP:                                           
        case HWND_MENU_TIME_DST:                                                                
        case HWND_MENU_TIME_TIME_FORMAT:                                                 
        case HWND_MENU_TIME_AUTO_SYNC:                                                    
        case HWND_MENU_TIME_SET_TIMEZONE:                                              
        //----------------------------
        case HWND_MENU_OPTION_TITLE:			//Ray OSD 2017.05.05: Add option title to exit menu

        //----------------------------                       
        case HWND_MENU_LOCK_SYSTEM:                                                         
        case HWND_MENU_LOCK_SET_PASSWORD:                                                
        case HWND_MENU_LOCK_BLOCK_PROGRAM:                                              
        case HWND_MENU_LOCK_PARENTAL_GUIDANCE:                                   
        case HWND_MENU_LOCK_ENTER_PASSWORD:                                            
        case HWND_MENU_LOCK_MAINSUBPAGE_ITEM_SYSTEMLOCK:                 
        case HWND_MENU_LOCK_MAINSUBPAGE_ITEM_INPUTBLOCK:                  
        case HWND_MENU_LOCK_MAINSUBPAGE_ITEM_US:                                 
        case HWND_MENU_LOCK_MAINSUBPAGE_ITEM_CANADA:                           
        case HWND_MENU_LOCK_MAINSUBPAGE_ITEM_RRTSETTING:                
        case HWND_MENU_LOCK_MAINSUBPAGE_ITEM_RESETRRT:                     
        case HWND_MENU_LOCK_MAINSUBPAGE_ITEM_UNRATED:                                                    
        case HWND_MENU_APP_DMP:                     
        //----------------------------
    				MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_CLOSE_CURRENT_OSD);
            break;    		
    		#endif
#if 0
        case HWND_MENU_SOUND_AUDIO_OPTION_ADVANCE_LIST:
        case HWND_MENU_SOUND_AUDIO_OPTION_SUBPAGE:
        case HWND_MENU_SOUND_AUDIO_OPTION_TITLE:
        case HWND_MENU_SOUND_AUDIO_OPTION_ACCESSIBILITY:
        case HWND_MENU_SOUND_AUDIO_OPTION_LANGUAGE:
        case HWND_MENU_SOUND_PRIMARY_PARAMETER:
            MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_AUDIO_OPTION_SUBPAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_SHOW);
            MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_SOUND);
            MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_SOUND_AUDIO_OPTION);
            break;
#endif

        case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR1:
        case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR2:
        case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR3:
        case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR4:
        case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR5:
        case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR6:
        case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR7:
#if ATSC_READY
            MApp_UiMenuFunc_ProNameEdit_Save();
#endif
            MApp_ZUI_API_ShowWindow(MApp_ZUI_API_GetParent(hwnd), SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE_LIST, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_CHANNEL_CHANNEL_LABEL);
            break;


        default:
            break;

    }
#endif

    if (MApp_ZUI_API_IsSuccessor(HWND_MENU_DLG_COMMON, MApp_ZUI_API_GetFocus())) //input password
    {
        switch(_eCommonDlgMode)
        {
        case EN_COMMON_DLG_MODE_INPUT_PASSWORD:
        case EN_COMMON_DLG_MODE_SCAN_INPUT_PASSWORD:
        case EN_COMMON_DLG_MODE_DTV_TUNING_INPUT_PASSWORD:
        case EN_COMMON_DLG_MODE_ATV_TUNING_INPUT_PASSWORD:
        case EN_COMMON_DLG_MODE_FACTORY_RESET_INPUT_PASSWORD:
        case EN_COMMON_DLG_MODE_ENTER_MENU_LOCK_PAGE_INPUT_PASSWORD:
            MApp_ZUI_ACT_ExecuteMenuCommonDialogAction(EN_EXE_CLOSE_INPUT_PASSWORD_DLG);
            break; // // Added it by coverity_0528
        case EN_COMMON_DLG_MODE_FACTORY_RESET_CONFIRM:
            MApp_ZUI_ACT_ExecuteMenuCommonDialogAction(EN_EXE_CLOSE_FACTORY_RESET_CONFIRM_DLG);
            break;
        case EN_COMMON_DLG_MODE_USB_UPDATE_CONFIRM:
            MApp_ZUI_ACT_ExecuteMenuCommonDialogAction(EN_EXE_CLOSE_CURRENT_OSD);
            break;
         default:
            break;
        }
    }
#if (ENABLE_ATSC)
#if ENABLE_ATSC_MENU_UI
    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_OPTION_CLOSEDCAPTION_PAGE, MApp_ZUI_API_GetFocus()))
    {
        MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_CLOSEDCAPTION_PAGE, SW_HIDE);
        MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_SHOW);
        MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_OPTION);
        MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_SHOW);
        MApp_ZUI_API_SetFocus(HWND_MENU_OPTION_CLOSED_CAPTION);
    }
    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_OPTION_CCOPTION_PAGE, MApp_ZUI_API_GetFocus()))
    {
        MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_CCOPTION_PAGE, SW_HIDE);
        MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
        MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_CLOSEDCAPTION_PAGE, SW_SHOW);
        MApp_ZUI_API_SetFocus(HWND_MENU_OPTION_CLOSEDCAPTION_ITEM_OPTION);
        MApp_UiMenu_DeleteCCPreviewWin();
    }

#if ENABLE_ATSC_MAIN_MENU_CHANNEL_PAGE
    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_CHANNEL_AUTO_TUNING_PAGE, MApp_ZUI_API_GetFocus()))
    {
        MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_AUTO_TUNING_PAGE, SW_HIDE);
        MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_SHOW);
        MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_TITLE, SW_SHOW);
        MApp_ZUI_API_ShowWindow(HWND_MENU_ICON_CHANNEL, SW_SHOW);
        MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_CHANNEL);
        MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE_LIST, SW_SHOW);
        MApp_ZUI_API_SetFocus(HWND_MENU_CHANNEL_AUTO_SCAN_ATSC);
    }


    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_CHANNEL_LIST_PAGE, MApp_ZUI_API_GetFocus()))
    {
        if(IS_HIDE_CH_ATSC(MApp_ChanProc_GetCurProgIndex()))
        {
            MApp_Dmx_DisableTableMonitor_ATSC();
            MApp_ChanProc_IncProgIndex(MAIN_LIST, 1, TRUE);
            MApp_ChanProc_RefreshChannelBuffer(MAIN_LIST);
            bChListKeyPress = TRUE;
            u32ChListKeyPressStartTime = msAPI_Timer_GetTime0();
        }
        MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_LIST_PAGE, SW_HIDE);
        MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_SHOW);
        MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_CHANNEL);
        MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE, SW_SHOW);
        if(bChannelListType == 0)
        {
            MApp_ZUI_API_SetFocus(HWND_MENU_CHANNEL_FAVORITE);
        }
        else
        {
            MApp_ZUI_API_SetFocus(HWND_MENU_CHANNEL_SHOW_HIDE);
        }

    }
#endif//ENABLE_ATSC_MAIN_MENU_CHANNEL_PAGE

#if ENABLE_ATSC_MAIN_MENU_PICTURE_PAGE

    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_PICTURE_ADJUST_BACKLIGHT_PAGE_LIST,MApp_ZUI_API_GetFocus()))
    {
        MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_ADJUST_BACKLIGHT_PAGE, SW_HIDE);
        MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
        MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_SHOW);
        MApp_ZUI_ACT_ShowMainMenuBackgroundNoFocusIcon();				//Ray OSD 2017.03.07: Disable show focus icon after exit backlight page
        //MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_PICTURE);
        MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_PAGE, SW_SHOW);
        MApp_ZUI_API_SetFocus(HWND_MENU_PICTURE_BACKLIGHT);
    }
#endif//ENABLE_ATSC_MAIN_MENU_PICTURE_PAGE
#if ENABLE_ATSC_MAIN_MENU_SOUND_PAGE
    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_SOUND_MODE_PAGE,MApp_ZUI_API_GetFocus()))
    {
        MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_MODE_PAGE, SW_HIDE);
        MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
        MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_SHOW);
        MApp_ZUI_ACT_ShowMainMenuBackgroundNoFocusIcon();				//Ray OSD 2017.03.07: Disable show focus icon after exit sound mode page
        //MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_SOUND);
        MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_PAGE, SW_SHOW);
        MApp_ZUI_API_SetFocus(HWND_MENU_SOUND_SNDMODE);

    }
    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_SOUND_EQ_ADVANCE_SUBPAGE_ITEMS,MApp_ZUI_API_GetFocus()))
    {
        MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_EQ_ADVANCE_SUBPAGE_ITEMS, SW_HIDE);
        MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
        MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_SHOW);
        MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_SOUND);
        MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_PAGE, SW_SHOW);
        MApp_ZUI_API_SetFocus(HWND_MENU_SOUND_EQUALIZER);
    }
#endif//ENABLE_ATSC_MAIN_MENU_SOUND_PAGE
#if ENABLE_ATSC_MENU_LOCK_UI
    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_LOCK_INPUTBLOCKSUBPAGE, MApp_ZUI_API_GetFocus()))
    {
        MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_INPUTBLOCKSUBPAGE, SW_HIDE);
        MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
        MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_SHOW);
        MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_LOCK);
        MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_PAGE_LIST, SW_SHOW);
        MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_TITLE, SW_SHOW);
        MApp_ZUI_API_ShowWindow(HWND_MENU_ICON_LOCK, SW_SHOW);
        MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_MAINSUBPAGE_ITEM_INPUTBLOCK);
    }
    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_LOCK_USSUBPAGE, MApp_ZUI_API_GetFocus()))
    {
        MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_USSUBPAGE, SW_HIDE);
        MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
        MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_SHOW);
        MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_LOCK);
        MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_PAGE_LIST, SW_SHOW);
        MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_TITLE, SW_SHOW);
        MApp_ZUI_API_ShowWindow(HWND_MENU_ICON_LOCK, SW_SHOW);
        MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_MAINSUBPAGE_ITEM_US);
    }
    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_LOCK_CANADASUBPAGE, MApp_ZUI_API_GetFocus()))
    {
        MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_CANADASUBPAGE, SW_HIDE);
        MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
        MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_SHOW);
        MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_LOCK);
        MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_PAGE_LIST, SW_SHOW);
        MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_TITLE, SW_SHOW);
        MApp_ZUI_API_ShowWindow(HWND_MENU_ICON_LOCK, SW_SHOW);
        MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_MAINSUBPAGE_ITEM_CANADA);
    }
    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE, MApp_ZUI_API_GetFocus()))
    {
        MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE, SW_HIDE);
        MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
        MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_SHOW);
        MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_LOCK);
        MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_PAGE_LIST, SW_SHOW);
        MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_TITLE, SW_SHOW);
        MApp_ZUI_API_ShowWindow(HWND_MENU_ICON_LOCK, SW_SHOW);
        MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_MAINSUBPAGE_ITEM_RRTSETTING);
    }
    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_LOCK_VCHIPSUBPAGE, MApp_ZUI_API_GetFocus()))
    {
        MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_VCHIPSUBPAGE, SW_HIDE);
        if(g_vchipPageType == EN_VCHIP_MPAA)
        {
            MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_USSUBPAGE, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_USSUBPAGE_ITEM_MPAA);
        }
        else if(g_vchipPageType == EN_VCHIP_CANADAENG)
        {
            MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_CANADASUBPAGE, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_CANADASUBPAGE_ITEM_ENG);
        }
        else if(g_vchipPageType == EN_VCHIP_CANADAFRE)
        {
            MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_CANADASUBPAGE, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_CANADASUBPAGE_ITEM_FRE);
        }
    }
    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_LOCK_TVRATINGSUBPAGE, MApp_ZUI_API_GetFocus()))
    {
        MApp_ZUI_API_ShowWindow(MApp_ZUI_API_GetParent(hwnd), SW_HIDE);
        //MApp_ZUI_API_ShowWindow(HWND_MENU_BACKGROUND, SW_HIDE);
        MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_USSUBPAGE, SW_SHOW);
        MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_USSUBPAGE_ITEM_TV);
    }
    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_LOCK_RRTADJUSTSUBPAGE, MApp_ZUI_API_GetFocus()))
    {
        MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_RRTADJUSTSUBPAGE, SW_HIDE);
        MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE, SW_SHOW);
        MApp_ZUI_API_SetFocus(_MApp_ZUI_ACT_RRTDimensionIdMapToWindow(g_u8CurrentRRT_Dimension));
    }
#endif
#endif//ENABLE_ATSC_MENU_UI

#endif
#if 0//ENABLE_T_C_COMBO
    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_DLG_DVB_SELECT_MENU, MApp_ZUI_API_GetFocus()))
    {
        MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_DVB_SELECT_MENU, SW_HIDE);
        MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_CHANNEL);
        MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE, SW_SHOW);
        MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_CHANNEL_PAGE_LIST, HWND_MENU_CHANNEL_AUTOTUNE);
        if(IsDTVInUse())
        {
            MApp_DVBType_SetCurrentType(MApp_DVBType_GetPrevType());
            switch (MApp_DVBType_GetPrevType())
            {
                case EN_DVB_T_TYPE:
                {
                    if(msAPI_Tuner_GetDspStatus() != 0x01)//1: DVBT, 2:DVBC, 3:ATSC, 0xff: Null
                    {
                        MApp_ChannelChange_DisableChannel(TRUE,MAIN_WINDOW);
                        msAPI_Tuner_SwitchSource((EN_DVB_TYPE)stGenSetting.stScanMenuSetting.u8DVBCTvConnectionType, TRUE);
                        MApp_ChannelChange_EnableChannel(MAIN_WINDOW);
                        //Cancel Freeze
                        if(MApp_IsImageFrozen())
                        {
                            MApp_SetImageFrozen(FALSE);
                            MApi_XC_FreezeImg(FALSE, MAIN_WINDOW);
                        }
                    }
                    break;
               }
                case EN_DVB_C_TYPE:
                {
                    if(msAPI_Tuner_GetDspStatus() != 0x02)//1: DVBT, 2:DVBC, 3:ATSC, 0xff: Null
                    {
                        MApp_ChannelChange_DisableChannel(TRUE,MAIN_WINDOW);
                        msAPI_Tuner_SwitchSource((EN_DVB_TYPE)stGenSetting.stScanMenuSetting.u8DVBCTvConnectionType, TRUE);
                        MApp_ChannelChange_EnableChannel(MAIN_WINDOW);
                        //Cancel Freeze
                        if(MApp_IsImageFrozen())
                        {
                            MApp_SetImageFrozen(FALSE);
                            MApi_XC_FreezeImg(FALSE, MAIN_WINDOW);
                        }
                    }
                    break;
               }

               default:
                break;
            }
        }
    }
#endif
#if (NTV_FUNCTION_ENABLE)
    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_DLG_DVBT_BANDWIDTH_SELECT_MENU, MApp_ZUI_API_GetFocus()))
    {
        MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_DVBT_BANDWIDTH_SELECT_MENU, SW_HIDE);
        MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_TUNING_CONFIRM);
        _eCommonSingleMode = EN_COMMON_SINGLELIST_INVALID;
    }
#endif
    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_DLG_SIGNAL_INFORMAT, MApp_ZUI_API_GetFocus()))
    {
        MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_SIGNAL_INFORMAT, SW_HIDE);
        MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_CHANNEL);
        MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE, SW_SHOW);
        MApp_ZUI_API_SetFocus(HWND_MENU_CHANNEL_SIGNAL_INFORMAT);
    }
    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_DLG_TUNE_CONFIRM, MApp_ZUI_API_GetFocus()))
    {
        if(MApp_ZUI_API_IsSuccessor(HWND_MENU_DLG_TUNE_CONFIRM_COUNTRY_GRID, MApp_ZUI_API_GetFocus()))
        {
            #if ENABLE_DTV
            MApp_ZUI_API_SetFocus(HWND_MENU_DLG_TUNE_CONFIRM_TUNE_TYPE);
            #else
            MApp_ZUI_ACT_ExecuteTuningConfirmDialogAction(EN_EXE_CLOSE_TUNING_CONFIRM);
            #endif
        }
        else
        {
        #if 0//ENABLE_T_C_COMBO
        if(MApp_DVBType_GetCurrentType() == EN_DVB_C_TYPE)
        {
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_ACT_ShowDVBCScanPage();
        }
        else
        {       //DVBT
            _eCommonSingleMode = EN_COMMON_SINGLELIST_DVB_SELECT;
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_TUNE_CONFIRM, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_DVB_SELECT_MENU, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_SELECTED_DVBT_BG);
        }
            MApp_ZUI_ACT_ExecuteTuningConfirmDialogAction(EN_EXE_CLOSE_TUNING_CONFIRM);
        #else
            MApp_ZUI_ACT_ExecuteTuningConfirmDialogAction(EN_EXE_CLOSE_TUNING_CONFIRM);
        #endif
        }
    }
    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_PCMODE_PAGE, MApp_ZUI_API_GetFocus()))
    {
        MApp_ZUI_API_ShowWindow(HWND_MENU_PCMODE_PAGE, SW_HIDE);
        //MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_SHOW);
        MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_PAGE, SW_SHOW);		//Ray VGA 2017.04.12: Go back to Setup (picture) page
        MApp_ZUI_ACT_ShowMainMenuBackgroundNoFocusIcon();			//Ray VGA 2017.03.10: Disable show focus icon after exit sound mode page
        //MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_PICTURE);
        MApp_ZUI_API_SetFocus(HWND_MENU_PICTURE_VGA_SETUP);			//Ray VGA 2017.04.12: Set focus on VGA setup menu item in picture menu
        //MApp_ZUI_API_SetFocus(HWND_MENU_PICTURE_PC_ADJUST);
    }
#if (ENABLE_PIP)
     else if(IsPIPSupported() && MApp_ZUI_API_IsSuccessor(HWND_MENU_PIP_PAGE, MApp_ZUI_API_GetFocus()))
    {
        MApp_ZUI_API_ShowWindow(HWND_MENU_PIP_PAGE, SW_HIDE);
        MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_PAGE, SW_SHOW);
        MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_PICTURE);
        MApp_ZUI_API_SetFocus(HWND_MENU_PICTURE_PIP);
    }
#endif
    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_COMMON_ADJ_PAGE, MApp_ZUI_API_GetFocus()))
    {

        MApp_ZUI_API_ShowWindow(HWND_MENU_COMMON_ADJ_PAGE, SW_HIDE);
        MApp_ZUI_API_EnableWindow(HWND_MENU_COMMON_ADJ_ITEM1 ,ENABLE);

        if(g_mainpage_common == EN_COMMON_PICTURE_MODE_PAGE)
        {
            MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_PAGE, SW_SHOW);
            MApp_ZUI_ACT_ShowMainMenuBackgroundNoFocusIcon();					//Ray OSD 2017.03.07: Disable show focus icon after exit common adjust page
            //MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_PICTURE);
            MApp_ZUI_API_SetFocus(HWND_MENU_PICTURE_PICMODE);
        }
        else if(g_mainpage_common == EN_COMMON_PICTURE_COLOR_PAGE)
        {
            //Ray CTP 2017.05.19: In color temp page, adj item 2~4 are disabled in all modes except user mode.  So we need to enable them when leaving color temp page
            MApp_ZUI_API_EnableWindow(HWND_MENU_COMMON_ADJ_ITEM2 ,ENABLE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_COMMON_ADJ_ITEM3 ,ENABLE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_COMMON_ADJ_ITEM4 ,ENABLE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_PAGE, SW_SHOW);
            MApp_ZUI_ACT_ShowMainMenuBackgroundNoFocusIcon();					//Ray OSD 2017.03.07: Disable show focus icon after exit common adjust page
            //MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_PICTURE);
            MApp_ZUI_API_SetFocus(HWND_MENU_PICTURE_COLOR_TEMP);
        }
        else if(g_mainpage_common == EN_COMMON_SOUND_BALANCE_PAGE)
        {
            MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_PAGE, SW_SHOW);
            MApp_ZUI_ACT_ShowMainMenuBackgroundNoFocusIcon();					//Ray OSD 2017.03.07: Disable show focus icon after exit common adjust page
            //MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_SOUND);
            MApp_ZUI_API_SetFocus(HWND_MENU_SOUND_BALANCE);
        }
        else if(g_mainpage_common == EN_COMMON_BKL_SETUP_PAGE)					//Ray BKL 2017.04.25: After exit backlight setup page, go back to option menu
        {
            MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_SHOW);
            MApp_ZUI_ACT_ShowMainMenuBackgroundNoFocusIcon();
            MApp_ZUI_API_SetFocus(HWND_MENU_OPTION_BL_SETUP);
        }
        else if(g_mainpage_common == EN_COMMON_SOUND_SWITCH_PAGE)
        {
            MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_PAGE, SW_SHOW);
            MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_SOUND);
            MApp_ZUI_API_SetFocus(HWND_MENU_SOUND_AD_SWITCH);
        }
        else if(g_mainpage_common == EN_COMMON_SOUND_AUDIO_DELAY_PAGE)
        {
            MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_PAGE, SW_SHOW);
            MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_SOUND);
            MApp_ZUI_API_SetFocus(HWND_MENU_SOUND_AUDIO_DELAY);
        }
        else if(g_mainpage_common == EN_COMMON_OFFTIMER_PAGE)
        {
            MApp_ZUI_API_ShowWindow(HWND_MENU_TIME_PAGE, SW_SHOW);
            MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_TIME);
            MApp_ZUI_API_SetFocus(HWND_MENU_TIME_SET_OFFTIME);
            MApp_ZUI_ACT_ExecuteSetOffTimeDialogAction(EN_EXE_CLOSE_SET_OFFTIME);
        }
        else if(g_mainpage_common == EN_COMMON_ONTIMER_PAGE)
        {
            MApp_ZUI_API_ShowWindow(HWND_MENU_TIME_PAGE, SW_SHOW);
            MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_TIME);
            MApp_ZUI_API_SetFocus(HWND_MENU_TIME_SET_ONTIME);
            MApp_ZUI_ACT_ExecuteSetOffTimeDialogAction(EN_EXE_CLOSE_SET_ONTIME);

        }
        else if(g_mainpage_common == EN_COMMON_TIME_CLOCK_PAGE)
        {
            MApp_ZUI_API_ShowWindow(HWND_MENU_TIME_PAGE, SW_SHOW);
            MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_TIME);
            MApp_ZUI_API_SetFocus(HWND_MENU_TIME_SET_ONTIME);
            MApp_ZUI_ACT_ExecuteSetOffTimeDialogAction(EN_EXE_CLOSE_SET_CLOCK);
        }
#if (ENABLE_MFC_6M20 || ENABLE_MFC_6M30)
        else if(g_mainpage_common == EN_COMMON_SET_MFC_PAGE)
        {
            MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_SHOW);
            MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_OPTION);
            MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_OPTION_PAGE_LIST, HWND_MENU_OPTION_MFC);
        }
#endif
#if ENABLE_ATSC_TTS
        else if(g_mainpage_common == EN_COMMON_OPTION_TTS_PAGE)
        {
            MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_SHOW);
            MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_OPTION);
            MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_OPTION_PAGE_LIST, HWND_MENU_OPTION_TTS);
        }
#endif
    }
  #if ENABLE_DTV
    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_OPTION_AUDIOLANG_PAGE, MApp_ZUI_API_GetFocus()))
    {
        if(MApp_ZUI_API_GetFocus() == HWND_MENU_OPTION_AUDIOLANG_PRIMARY)
        {
            MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_AUDIOLANG_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_SHOW);
            MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_OPTION);
            MApp_ZUI_API_SetFocus(HWND_MENU_OPTION_AUDIO_LANG);
        }
        else
        {
            MApp_ZUI_API_SetFocus(HWND_MENU_OPTION_AUDIOLANG_PRIMARY);
        }
    }
  #endif
    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_OPTION_SUBLANG_PAGE, MApp_ZUI_API_GetFocus()))
    {
        if(MApp_ZUI_API_GetFocus() == HWND_MENU_OPTION_SUBLANG_PRIMARY)
        {
            MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_SUBLANG_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_SHOW);
            MApp_ZUI_ACT_ShowMainMenuBackgroundNoFocusIcon();					//Ray OSD 2017.03.07: Disable show focus icon after exit adjust page
            //MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_OPTION);
            MApp_ZUI_API_SetFocus(HWND_MENU_OPTION_SUBTITLE_LANG);
        }
        else
        {
            MApp_ZUI_API_SetFocus(HWND_MENU_OPTION_SUBLANG_PRIMARY);
        }
    }
    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_OPTION_OSDLANG_PAGE, MApp_ZUI_API_GetFocus()))
    {
        MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_OSDLANG_PAGE, SW_HIDE);
        MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_SHOW);
        MApp_ZUI_ACT_ShowMainMenuBackgroundNoFocusIcon();					//Ray OSD 2017.03.07: Disable show focus icon after exit adjust page
       // MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_OPTION);
        MApp_ZUI_API_SetFocus(HWND_MENU_OPTION_OSD_LANG);
    }
    // anvi cec
    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_HDMI_CEC_PAGE, MApp_ZUI_API_GetFocus()))
    {
       // printf("\n    [%s,%d] \n",__FILE__,__LINE__);
        MApp_ZUI_API_ShowWindow(HWND_MENU_HDMI_CEC_PAGE, SW_HIDE);
        MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_SHOW);
        MApp_ZUI_ACT_ShowMainMenuBackgroundNoFocusIcon();					//Ray OSD 2017.03.07: Disable show focus icon after exit adjust page
        //MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_OPTION);
        MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_OPTION_PAGE_LIST, HWND_MENU_OPTION_HDMI_CEC);

    }

    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_HDMI_CEC_DEVICE_LIST_PAGE, MApp_ZUI_API_GetFocus()))
    {
        //printf("\n    [%s,%d] \n",__FILE__,__LINE__);
        MApp_ZUI_API_ShowWindow(HWND_MENU_HDMI_CEC_DEVICE_LIST_PAGE, SW_HIDE);
        MApp_ZUI_API_ShowWindow(HWND_MENU_HDMI_CEC_PAGE, SW_SHOW);
     MApp_ZUI_API_SetFocus(HWND_MENU_HDMI_CEC_DEVICE_LIST);

  //      MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_OPTION);
   //     MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_HDMI_CEC_PAGE_LIST, HWND_MENU_HDMI_CEC_DEVICE_LIST);
    }
 #if 0//ENABLE_MFC_6M30
   else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_OPTION_MFC_PAGE, MApp_ZUI_API_GetFocus()))
   {
        MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_MFC_PAGE, SW_HIDE);
        MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_SHOW);
        MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_OPTION);
        MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_OPTION_PAGE_LIST, HWND_MENU_OPTION_MFC);
   }
#endif
    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_SINGLELIST_COMMON_PAGE, MApp_ZUI_API_GetFocus()))
    {
        MApp_ZUI_API_ShowWindow(HWND_MENU_SINGLELIST_COMMON_PAGE, SW_HIDE);
        switch(_eCommonSingleMode)
        {
            case EN_COMMON_SINGLELIST_ASPECT_RATIO:
               MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_PAGE, SW_SHOW);
               MApp_ZUI_ACT_ShowMainMenuBackgroundNoFocusIcon();				//Ray OSD 2017.03.07: Disable show focus icon after exit adjust page
               //MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_PICTURE);
               if(MApp_ZUI_API_IsWindowVisible(HWND_MENU_ALERT_WINDOW))
               {
                   MApp_ZUI_API_ShowWindow(HWND_MENU_ALERT_WINDOW, SW_HIDE);
               }
               MApp_ZUI_API_SetFocus(HWND_MENU_PICTURE_ASPECT_RATIO);
               break;
            case EN_COMMON_SINGLELIST_NOISE_REDUCTION:
               MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_PAGE, SW_SHOW);
               MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_PICTURE);
               MApp_ZUI_API_SetFocus(HWND_MENU_PICTURE_NOISE_REDUCTION);
               break;
            case EN_COMMON_SINGLELIST_MPEG_NOISE_REDUCTION:
               MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_PAGE, SW_SHOW);
               MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_PICTURE);
               MApp_ZUI_API_SetFocus(HWND_MENU_PICTURE_MPEG_NOISE_REDUCTION);
               break;
            case EN_COMMON_SINGLELIST_SURROUND_SOUND:
               MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_PAGE, SW_SHOW);
               MApp_ZUI_ACT_ShowMainMenuBackgroundNoFocusIcon();				//Ray OSD 2017.03.07: Disable show focus icon after exit adjust page
               //MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_SOUND);
               MApp_ZUI_API_SetFocus(HWND_MENU_SOUND_SURROUND);
               break;
            case EN_COMMON_SINGLELIST_TV_SPEAKER:
               MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_PAGE, SW_SHOW);
               MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_SOUND);
               MApp_ZUI_API_SetFocus(HWND_MENU_SOUND_TV_SPEAKER);
               break;
            case EN_COMMON_SINGLELIST_SLEEP_TIMER:
               MApp_ZUI_API_ShowWindow(HWND_MENU_TIME_PAGE, SW_SHOW);
               MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_TIME);
               MApp_ZUI_API_SetFocus(HWND_MENU_TIME_SET_SLEEP_TIMER);
               break;
            case EN_COMMON_SINGLELIST_AUTOSLEEP_TIMER:
                MApp_ZUI_API_ShowWindow(HWND_MENU_TIME_PAGE, SW_SHOW);
                MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_TIME);
                MApp_ZUI_API_SetFocus(HWND_MENU_TIME_SET_AUTO_SLEEP);
                break;
            case EN_COMMON_SINGLELIST_PARENTAL_GUIDANCE:
               MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_PAGE, SW_SHOW);
               MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_LOCK);
               MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_PARENTAL_GUIDANCE);
               break;

        #if  (ATSC_CC == ATV_CC)
            case EN_COMMON_SINGLELIST_CC_OPTION:
                MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_SHOW);
                MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_OPTION);
                MApp_ZUI_API_SetFocus(HWND_MENU_OPTION_CC_OPTION);
                break;
        #endif
        #if ENABLE_3D_PROCESS
            case EN_COMMON_SINGLELIST_3D_TYPE:
                MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_SHOW);
                MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_OPTION);
                MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_OPTION_PAGE_LIST, HWND_MENU_OPTION_3D_TYPE);
                break;
        #endif

        #if(ENABLE_SCART_SVIDEO)
            case EN_COMMON_SINGLELIST_SCART_IN:
                MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_SHOW);
                MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_OPTION);
                //MApp_ZUI_API_SetFocus(HWND_MENU_OPTION_SCART_IN);
                MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_OPTION_PAGE_LIST, HWND_MENU_OPTION_SCART_IN);
                break;
        #endif

        #if (ENABLE_ATSC)
            case EN_COMMON_SINGLELIST_MTS:
               MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_SHOW);
               MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_OPTION);
            #if ENABLE_ATSC_MENU_UI
               MApp_ZUI_API_SetFocus(HWND_MENU_SOUND_MTS);
            #endif
               break;
            case EN_COMMON_SINGLELIST_OSD_TIMEZONE:
                //printf("[ms] Exit ATSC time zone\n");
                MApp_ZUI_API_ShowWindow(HWND_MENU_TIME_PAGE, SW_SHOW);
                MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_TIME);
                MApp_ZUI_API_SetFocus(HWND_MENU_TIME_SET_TIMEZONE);
                break;
            case EN_COMMON_SINGLELIST_MENU_LANGUAGE:
                MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_SHOW);
                MApp_ZUI_ACT_ShowMainMenuBackgroundNoFocusIcon();				//Ray OSD 2017.03.07: Disable show focus icon after exit adjust page
                //MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_OPTION);
                MApp_ZUI_API_SetFocus(HWND_MENU_OPTION_OSD_LANG);
                break;
        #endif
            default:
               break;
        }
        _eCommonSingleMode = EN_COMMON_SINGLELIST_INVALID;
    }
  #if ENABLE_DTV
    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_TIME_TIMEZONE_PAGE, MApp_ZUI_API_GetFocus()))
    {
        MApp_ZUI_API_ShowWindow(HWND_MENU_TIME_TIMEZONE_PAGE, SW_HIDE);
        MApp_ZUI_API_ShowWindow(HWND_MENU_TIME_PAGE, SW_SHOW);
        MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_TIME);
        MApp_ZUI_API_SetFocus(HWND_MENU_TIME_SET_TIMEZONE);
    }
  #endif
}

typedef struct _MENU_KEY2BTN_STRUCT
{
    VIRTUAL_KEY_CODE key;
    HWND hwnd;
} MENU_KEY2BTN_STRUCT;

///////////////////////////////////////////////////////////////////////////////
///  private  MApp_ZUI_ACT_HandleMainPageKey
///  [OSD page handler] global key handler for MENU application
///
///  @param [in]       key VIRTUAL_KEY_CODE      key code
///
///  @return BOOLEAN    true for accept, false for ignore
///
///  @author MStarSemi @date 2007/1/25
///////////////////////////////////////////////////////////////////////////////
BOOLEAN MApp_ZUI_ACT_HandleMainPageKey(VIRTUAL_KEY_CODE key)
{
    //note: this function will be called in running state

    //reset timer if any key
    MApp_ZUI_API_ResetTimer(HWND_MENU_MASK_BACKGROUND, 0);
    //printf("MingYuan MApp_ZUI_ACT_HandleMainPageKey %d\n",MApp_ZUI_API_GetFocus());
   //only show click animation in page items, not for dialogs...
    if (MApp_ZUI_API_IsSuccessor(HWND_MENU_CHANNEL_PAGE_LIST, MApp_ZUI_API_GetFocus()) ||
        MApp_ZUI_API_IsSuccessor(HWND_MENU_SOUND_PAGE_LIST, MApp_ZUI_API_GetFocus()) ||
        MApp_ZUI_API_IsSuccessor(HWND_MENU_PICTURE_PAGE_LIST, MApp_ZUI_API_GetFocus()) ||
        MApp_ZUI_API_IsSuccessor(HWND_MENU_TIME_PAGE_LIST, MApp_ZUI_API_GetFocus()) ||
        MApp_ZUI_API_IsSuccessor(HWND_MENU_LOCK_PAGE_LIST, MApp_ZUI_API_GetFocus()) ||
        MApp_ZUI_API_IsSuccessor(HWND_MENU_OPTION_PAGE_LIST, MApp_ZUI_API_GetFocus()) ||
        MApp_ZUI_API_IsSuccessor(HWND_MENU_APP_PAGE_LIST, MApp_ZUI_API_GetFocus()) ||
        #if (ENABLE_PIP)
        (IsPIPSupported() && MApp_ZUI_API_IsSuccessor(HWND_MENU_PIP_PAGE_LIST, MApp_ZUI_API_GetFocus())) ||
        #endif
        MApp_ZUI_API_IsSuccessor(HWND_MENU_PCMODE_PAGE_LIST, MApp_ZUI_API_GetFocus()) )
    {
    #if 0
        static  MENU_KEY2BTN_STRUCT _ZUI_TBLSEG _key2btn[] =
        {
            {VK_MENU, HWND_MENU_BOTTOM_HALF_MENU_BG},
            {VK_SELECT, HWND_MENU_BOTTOM_HALF_OK_BG},
            {VK_EXIT, HWND_MENU_BOTTOM_HALF_EXIT_BG},
            {VK_UP, HWND_MENU_BOTTOM_HALF_UP_ARROW},
            {VK_DOWN, HWND_MENU_BOTTOM_HALF_DOWN_ARROW},
            {VK_LEFT, HWND_MENU_BOTTOM_HALF_LEFT_ARROW},
            {VK_RIGHT, HWND_MENU_BOTTOM_HALF_RIGHT_ARROW},
        };
        U8 i;

        for (i = 0; i < COUNTOF(_key2btn); i++)
        {
            if (_key2btn[i].key == key)
            {
                MApp_ZUI_API_SetTimer(_key2btn[i].hwnd, 0, BUTTONANICLICK_PERIOD);
                MApp_ZUI_API_InvalidateWindow(_key2btn[i].hwnd);
                break;
            }
        }
    #endif
    }
    //MENU_DLG_COMMON
    else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_DLG_PASSWORD_PANE0, MApp_ZUI_API_GetFocus()) ||
            MApp_ZUI_API_IsSuccessor(HWND_MENU_DLG_PASSWORD_PANE1, MApp_ZUI_API_GetFocus()) ||
            MApp_ZUI_API_IsSuccessor(HWND_MENU_DLG_PASSWORD_PANE1, MApp_ZUI_API_GetFocus())
            )
    {
        static  MENU_KEY2BTN_STRUCT _ZUI_TBLSEG _PicAdjkey2btn[] =
        {
            {VK_LEFT, HWND_MENU_DLG_COMMON_BTN_OK},
            {VK_RIGHT, HWND_MENU_DLG_COMMON_BTN_CANCEL},
        };
        U8 i;

        for (i = 0; i < COUNTOF(_PicAdjkey2btn); i++)
        {
            if (_PicAdjkey2btn[i].key == key)
            {
                MApp_ZUI_API_SetTimer(_PicAdjkey2btn[i].hwnd, 0, BUTTONANICLICK_PERIOD);
                MApp_ZUI_API_InvalidateWindow(_PicAdjkey2btn[i].hwnd);
                break;
            }
        }
    }
    else if(HWND_MENU_DLG_COMMON_BAR == MApp_ZUI_API_GetFocus())
    {
        static  MENU_KEY2BTN_STRUCT _ZUI_TBLSEG _PicAdjkey2btn[] =
        {
            {VK_RIGHT, HWND_MENU_DLG_COMMON_BTN_YES},	//MingYuan Yes No Change
            {VK_LEFT, HWND_MENU_DLG_COMMON_BTN_NO},
        };
        U8 i;

        for (i = 0; i < COUNTOF(_PicAdjkey2btn); i++)
        {
            if (_PicAdjkey2btn[i].key == key)
            {
                MApp_ZUI_API_SetTimer(_PicAdjkey2btn[i].hwnd, 0, BUTTONANICLICK_PERIOD);
                MApp_ZUI_API_InvalidateWindow(_PicAdjkey2btn[i].hwnd);
                break;
            }
        }
    }

    switch(key)
    {
     		#ifdef sTriviewKeypadStyle
	  case VK_SELECT:
	    MApp_ZUI_ACT_MainPageMenuKey();		//Ray OSD 2017.03.06: MENU key also acts as exit key.
           return TRUE;
        		
     		#else     	
        case VK_MENU:       
            MApp_ZUI_ACT_MainPageMenuKey();
            return TRUE;
        #endif     
     		#ifdef sTriviewKeypadStyle
         case VK_EXIT:
            MApp_ZUI_ACT_MainPageMenuKey();
            return TRUE;       		
     		#else               
        case VK_EXIT:
            MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_CLOSE_CURRENT_OSD);
            return TRUE;
        #endif 
        case VK_POWER:
            printf("\nRay: main menu go to power saving state");
            MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_POWEROFF);
            return TRUE;

        case VK_OSD_NEXT:				//Ray OSD 2017.06.01: OSD Next key to next menu page
	    MApp_ZUI_ACT_MainPageOSDNextKey();
	    return TRUE;

        case VK_OSD_BACK:				//Ray OSD 2017.06.01: OSD Back key to previous menu page
	    MApp_ZUI_ACT_MainPageOSDBackKey();
	    return TRUE;

        case VK_MTS:
            if(!IsStorageInUse())
            {
                #if ENABLE_DTV
                MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_AUDIO_LANG);
                #endif
            }
            return TRUE;

        case VK_INPUT_SOURCE:
            MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_SHOW_SOURCE_BANNER);
            return TRUE;

        case VK_CHANNEL_LIST:
        #if ENABLE_S2
            if(IsATVInUse()||IsDTVInUse()||IsS2InUse())
        #else
            if(!IsStorageInUse())
        #endif
            {
                MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_CHANNEL_LIST);
            }
            return TRUE;

        case VK_CHANNEL_FAV_LIST:
        #if ENABLE_S2
           if(IsATVInUse()||IsDTVInUse()||IsS2InUse())
        #else
            if(!IsStorageInUse())
        #endif
            {
                MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_FAVORITE_LIST);
            }
            return TRUE;

        #if ENABLE_DTV
        case VK_EPG:
        {
            #if NORDIG_FUNC //for Nordig Spec v2.0
                U16 u16TotalProNum = msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
            #else
                U16 u16TotalProNum = msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
            #endif

            if(!IsStorageInUse()
                #if (ENABLE_PIP)
                && (MApp_Get_PIPMode() == EN_PIP_MODE_OFF)
                #endif
                &&(u16TotalProNum && (IsDTVInUse()
            #if ENABLE_S2
                ||IsS2InUse()
            #endif
                ))
                )
            {
                MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_EPG_SHOW_PROGRAMMEGUIDE_TIME_PAGE);
                return TRUE;
            }
            break;
        }
        #endif

        case VK_INFO:
            if(!IsStorageInUse())
            {
                MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_SHOW_BRIEF_CH_INFO);
            }
            return TRUE;


        default:
            break;

    }
    return FALSE;
}

///////////////////////////////////////////////////////////////////////////////
///  private  MApp_ZUI_ACT_TerminateMainMenu
///  [OSD page handler] terminate MENU application
///
///  @return no return value
///
///  @author MStarSemi @date 2007/1/25
///////////////////////////////////////////////////////////////////////////////
void MApp_ZUI_ACT_TerminateMainMenu(void)
{
    ZUI_MSG(printf("[]term:enMainMenuState=%u, _enTargetMenuState=%u\n", enMainMenuState, _enTargetMenuState);)

#if (ENABLE_ATSC)
    if(IS_HIDE_CH_ATSC(MApp_ChanProc_GetCurProgIndex()))
    {
        MApp_Dmx_DisableTableMonitor_ATSC();
        MApp_ChanProc_IncProgIndex(MAIN_LIST, 1, TRUE);
        MApp_ChanProc_RefreshChannelBuffer(MAIN_LIST);
        bChListKeyPress = TRUE;
        u32ChListKeyPressStartTime = msAPI_Timer_GetTime0();
    }
    MApp_UiMenu_DeleteCCPreviewWin();
#endif

    // Check valid?
#if ( ENABLE_DMP )
    if( (STATE_MENU_GOTO_DMP == _enTargetMenuState)&&(!IsStorageInUse()) )
    {
        MS_DEBUG_MSG(printf("!!Error at %u:%s\n", __LINE__, __FILE__));
        enMainMenuState = STATE_MENU_INIT;
    }
    else
#endif
    {
        enMainMenuState = _enTargetMenuState;
    }
}

void _MApp_ZUI_ACT_OpenCommonDialog(COMMON_DLG_MODE dlg)
{
    //note: please set previous focus and target focus before calling this function...
    MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON, SW_HIDE); //in order to invoke MSG_NOTIFY_SHOW event...
    _eCommonDlgMode = dlg;
    MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON, SW_SHOW);

    switch(dlg)
    {
    #if (ENABLE_ATSC)
        case EN_COMMON_DLG_MODE_RESETRRT_CONFIRM:
            MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_C_SETPW, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE0, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE1, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE2, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE0, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE1, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE2, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_LOADANIMATION, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_LOADANIMATION_BG, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_YES, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_NO, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_DONE, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_PANE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_YES, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_NO, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_DLG_COMMON_BAR);
            break;
    #endif
        case EN_COMMON_DLG_MODE_USB_UPDATE_CONFIRM:
        case EN_COMMON_DLG_MODE_FACTORY_RESET_CONFIRM:
            //a dialog with "yes" and "no" buttons
            if(dlg == EN_COMMON_DLG_MODE_USB_UPDATE_CONFIRM)
            {
            	 #ifdef sSoftwareUpdateInOptionPage
            	 MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_HIDE);
            	 #else
               MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE, SW_HIDE);
               #endif
               //printf("MingYuan EN_COMMON_DLG_MODE_USB_UPDATE_CONFIRM \n");
            }
            else
            {
               MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_HIDE);
            }
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_C_SETPW, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE0, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE1, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE2, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE0, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE1, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE2, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_LOADANIMATION, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_LOADANIMATION_BG, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_YES, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_NO, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_DONE, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_PANE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_YES, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_NO, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_DLG_COMMON_BAR);
            break;

        case EN_COMMON_DLG_MODE_DEACTIVATION:
        case EN_COMMON_DLG_MODE_DEACTIVATION_CONFIRM:
            //a dialog with "[Yes]" and "[No]" buttons
            MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_C_SETPW, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE0, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE1, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE2, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE0, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE1, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE2, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_LOADANIMATION, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_LOADANIMATION_BG, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_PANE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BAR, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_R, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_C, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_L, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_NEW_BG_L, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_NEW_BG_C, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_NEW_BG_R, SW_SHOW);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_DONE, SW_HIDE);

            MApp_ZUI_API_SetFocus(HWND_MENU_DLG_COMMON_BTN_DIVX_YES);
            break;

        case EN_COMMON_DLG_MODE_DIVX:
            //a dialog with "[Done]" button
            MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_C_SETPW, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE0, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE1, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE2, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE0, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE1, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE2, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_LOADANIMATION, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_LOADANIMATION_BG, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_PANE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BAR, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_R, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_C, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_L, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_NEW_BG_L, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_NEW_BG_C, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_NEW_BG_R, SW_SHOW);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_YES, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_NO, SW_HIDE);

            MApp_ZUI_API_SetFocus(HWND_MENU_DLG_COMMON_BTN_DIVX_DONE);
            break;

        case EN_COMMON_DLG_MODE_FACTORY_RESET:
            //a dialog with no button
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE0, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE1, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE2, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE0, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE1, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE2, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_PANE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BAR, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_R, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_C, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_L, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_C_SETPW, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_NEW_BG_L, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_NEW_BG_C, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_NEW_BG_R, SW_SHOW);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_YES, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_NO, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_DONE, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_LOADANIMATION, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_LOADANIMATION_BG, SW_SHOW);
            break;

        case EN_COMMON_DLG_MODE_WRONG_PASSWORD:
            //a dialog with "ok" button
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE0, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE1, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_INPUT1_TEXT, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE2, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE0, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE1, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE2, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_LOADANIMATION, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_LOADANIMATION_BG, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_YES, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_NO, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_DONE, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_PANE, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_YES, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_NO, SW_HIDE);
            MApp_ZUI_API_SetFocus(HWND_MENU_DLG_PASSWORD_INPUT1_1);
            break;

        case EN_COMMON_DLG_MODE_MISMATCH_PASSWORD:
            //a dialog with "ok" button
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_C, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_C_SETPW, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_YES, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_NO, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE0, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_LOADANIMATION, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_LOADANIMATION_BG, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE1, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE2, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_YES, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_NO, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_DONE, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE1, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_DLG_PASSWORD_INPUT1_1);
            break;

        case EN_COMMON_DLG_MODE_SET_PASSWORD:
            //a dialog with "cancel" button
            MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_TEXT1, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_TEXT5, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_C, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_C_SETPW, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE0, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE1, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE2, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE0, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE1, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE2, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_LOADANIMATION, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_LOADANIMATION_BG, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_YES, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_NO, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_DONE, SW_HIDE);

            MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT0_TEXT, ENABLE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT0_1, ENABLE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT0_2, ENABLE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT0_3, ENABLE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT0_4, ENABLE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT1_TEXT, DISABLE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT1_1, DISABLE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT1_2, DISABLE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT1_3, DISABLE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT1_4, DISABLE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT2_TEXT, DISABLE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT2_1, DISABLE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT2_1, DISABLE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT2_2, DISABLE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT2_3, DISABLE);
            MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT2_4, DISABLE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_PANE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_CANCEL, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_OK, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_DLG_PASSWORD_INPUT0_1);
            PasswordInput0=PasswordInput1=PasswordInput2=0;
            break;

        case EN_COMMON_DLG_MODE_INPUT_PASSWORD:
        case EN_COMMON_DLG_MODE_SCAN_INPUT_PASSWORD:
        case EN_COMMON_DLG_MODE_DTV_TUNING_INPUT_PASSWORD:
        case EN_COMMON_DLG_MODE_ATV_TUNING_INPUT_PASSWORD:
        case EN_COMMON_DLG_MODE_FACTORY_RESET_INPUT_PASSWORD:
        case EN_COMMON_DLG_MODE_ENTER_MENU_LOCK_PAGE_INPUT_PASSWORD:
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_LOADANIMATION, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_LOADANIMATION_BG, SW_HIDE);
            switch(dlg)
            {
                case EN_COMMON_DLG_MODE_SCAN_INPUT_PASSWORD:
                case EN_COMMON_DLG_MODE_DTV_TUNING_INPUT_PASSWORD:
                case EN_COMMON_DLG_MODE_ATV_TUNING_INPUT_PASSWORD:
                    MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE, SW_HIDE);
                    break;
                case EN_COMMON_DLG_MODE_FACTORY_RESET_INPUT_PASSWORD:
                    MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_HIDE);
                    break;
                case EN_COMMON_DLG_MODE_ENTER_MENU_LOCK_PAGE_INPUT_PASSWORD:
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_PAGE, SW_HIDE);
                    break;
                default:
                    break;
            }

            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE0, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE2, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE0, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE1, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE2, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_YES, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_NO, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_DONE, SW_HIDE);

            //note: don't show "new" text
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_INPUT1_TEXT, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_PANE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_OK, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_CANCEL, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_DLG_PASSWORD_INPUT1_1);
            PasswordInput1=PasswordInput2=0;
            break;

        case EN_COMMON_DLG_MODE_USB_NOT_DETECTED:
        case EN_COMMON_DLG_MODE_SW_FILE_NOT_DETECTED:
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            #ifdef sSoftwareUpdateInOptionPage
            MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_HIDE);
          	#else            
            MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE, SW_HIDE);
            #endif
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE0, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE1, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE2, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE0, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE1, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE2, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_LOADANIMATION, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_LOADANIMATION_BG, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_PANE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BAR, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_R, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_C, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_L, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_C_SETPW, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_NEW_BG_L, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_NEW_BG_C, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_NEW_BG_R, SW_SHOW);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_YES, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_NO, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_DONE, SW_HIDE);
            break;

     case EN_COMMON_DLG_MODE_CI_NO_MODULE:
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE0, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE1, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE2, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE0, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE1, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE2, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_LOADANIMATION, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_LOADANIMATION_BG, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_PANE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BAR, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_R, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_C, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_L, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_C_SETPW, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_NEW_BG_L, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_NEW_BG_C, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_NEW_BG_R, SW_SHOW);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_YES, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_NO, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_DONE, SW_HIDE);
            break;

        case EN_COMMON_DLG_MODE_USB_UPGRADING:
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE0, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE1, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE2, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE0, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE1, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE2, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_LOADANIMATION, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_LOADANIMATION_BG, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_PANE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BAR, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_R, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_C, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_L, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BG_C_SETPW, SW_HIDE);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_NEW_BG_L, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_NEW_BG_C, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_NEW_BG_R, SW_SHOW);

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_YES, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_NO, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_BTN_DIVX_DONE, SW_HIDE);
            break;

        default:
            ZUI_DBG_FAIL(printf("[ZUI]COMDLGOP\n"));
            ABORT();
            break;
    }
}

extern void _MApp_ZUI_ACT_CheckTimeInfo(void);
#if ENABLE_DRM
BOOLEAN MApp_VDPlayer_CheckAndGenDRMData(void);
BOOLEAN MApp_VDPlayer_Deactivate(void);
#endif
#if (ENABLE_DVB_TAIWAN_APP)
extern void MApp_ATV_ChangeAntennaType(EN_ANT_TYPE enAntennaType);
#endif
///////////////////////////////////////////////////////////////////////////////
///  private  MApp_ZUI_ACT_ExecuteMainMenuAction
///  [OSD page handler] execute a specific action in MENU application
///
///  @param [in]       act U16      action ID
///
///  @return BOOLEAN     true for accept, false for ignore
///
///  @author MStarSemi @date 2007/1/25
///////////////////////////////////////////////////////////////////////////////
#if (ENABLE_ATSC)
void MApp_InvalidateUI_CompareRating(void)
{
    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_VCHIPSUBPAGE_LIST);
    fVChipPassWordEntered = FALSE;
    MApp_UiMenuFunc_VChip_CompareRating();
}
#endif

#ifdef SetLanguageIssue
void MApp_ZUI_ACT_AppUpdateLanguageSelMenu(void)
{
  _eCommonSingleMode = EN_COMMON_SINGLELIST_MENU_LANGUAGE;
  MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
  MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_HIDE);
  MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
  MApp_ZUI_API_ShowWindow(HWND_MENU_SINGLELIST_COMMON_PAGE, SW_SHOW);
  switch(MENU_LANGUAGE)
  {
      case LANGUAGE_ENGLISH:
          MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM1);
          //printf("HWND_MENU_SINGLELIST_ITEM1 \n");
          break;
      case LANGUAGE_FRENCH:
          MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM2);
          //printf("HWND_MENU_SINGLELIST_ITEM2 \n");
          break;
      case LANGUAGE_SPANISH:
          MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM3);
          //printf("HWND_MENU_SINGLELIST_ITEM3 \n");
          break;
      #ifdef sTriviewSupportOSDLanguage
      case LANGUAGE_GERMAN:
          MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM4);
          //printf("HWND_MENU_SINGLELIST_ITEM4 \n");
          break;                
      case LANGUAGE_ITALIAN:
          MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM5);
          //printf("HWND_MENU_SINGLELIST_ITEM5 \n");
          break;                
      case LANGUAGE_PORTUGUESE:
          MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM6);
          //printf("HWND_MENU_SINGLELIST_ITEM6 \n");
          break;                
      case LANGUAGE_RUSSIAN:			    
          MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM7);
          //printf("HWND_MENU_SINGLELIST_ITEM7 \n");
          break;                
      case LANGUAGE_CHINESE:
          MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM8);
          //printf("HWND_MENU_SINGLELIST_ITEM8 \n");
          break;                
      #endif    
      default:
          break;
  }
}
#endif

BOOLEAN MApp_ZUI_ACT_ExecuteMainMenuAction(U16 act)
{
#if (ENABLE_ATSC)
  #if ENABLE_ATSC_MENU_UI
    U16 u16Temp;
    U16 u16Temp2;
    U8  u8Temp;
  #endif
#endif       
    switch(act)
    {
    #if (ENABLE_ATSC)
      #if ENABLE_ATSC_MENU_UI

        case EN_EXE_REPAINT_AUTOTUNING_PROGRESS:
            MApp_ZUI_API_ResetTimer(HWND_MENU_MASK_BACKGROUND, 0);
            MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_CHANNEL_AUTO_SCAN_RESULT_SUB_PAGE_ITEM);
            break;

        case EN_EXE_GOTO_SUBPAGE:
        {
            HWND hwnd;
            hwnd = MApp_ZUI_API_GetFocus();
            //U32 U32ShowFlag;
            switch(hwnd)
            {
            #if ENABLE_ATSC_TTS
                case HWND_MENU_OPTION_TTS:
                    g_mainpage_common = EN_COMMON_OPTION_TTS_PAGE;
                    MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);

                    MApp_ZUI_API_ShowWindow(HWND_MENU_COMMON_ADJ_PAGE, SW_SHOW);
                    MApp_ZUI_API_SetFocus(HWND_MENU_COMMON_ADJ_ITEM1);
                break;
            #endif

            #if ENABLE_ATSC_MAIN_MENU_CHANNEL_PAGE
                case HWND_MENU_CHANNEL_AUTO_SCAN_ATSC:
                    MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
                  #if (ENABLE_ATSC_TTS)
                    MApp_TTSControlSetInputText(MApp_ZUI_API_GetString(en_str_Are_you_sure_to_Auto_Scan), MApp_UiMenu_u16Strlen(MApp_ZUI_API_GetString(en_str_Are_you_sure_to_Auto_Scan)));
                    MApp_TTSControlSetOn(TRUE);
                  #endif
                    MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_AUTO_TUNING_PAGE, SW_SHOW);
                    MApp_ZUI_API_SetFocus(HWND_MENU_CHANNEL_AUTO_TUNING_BG_TEXT);
                    break;


                case HWND_MENU_CHANNEL_SHOW_HIDE:
                case HWND_MENU_CHANNEL_FAVORITE:
                    if(hwnd == HWND_MENU_CHANNEL_FAVORITE)
                    {
                        bChannelListType = FALSE;
                    }
                    else
                    {
                        bChannelListType = TRUE;
                    }
                    MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_LIST_PAGE, SW_SHOW);
                    u16Temp = MApp_ChanProc_GetCurProgIndex();
                    u16Temp2 = MApp_ChanProc_CalculateCurPageBaseIdx( u16Temp, MAX_NUM_OF_SRV_ITEM );
                    MApp_ZUI_API_SetFocus(_MApp_ZUI_ACT_MenuChannelListIdMapToWindow((U8)(u16Temp - u16Temp2)));
                    break;


                case HWND_MENU_CHANNEL_CHANNEL_LABEL:
                  #if ATSC_READY
                    MApp_UiMenuFunc_ProNameEditInit();
                  #endif
                    MApp_ZUI_API_ShowWindow(MApp_ZUI_API_GetParent(hwnd), SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_LABEL_EDIT_PAGE, SW_SHOW);
                    MApp_ZUI_API_SetFocus(HWND_MENU_CHANNEL_LABEL_EDIT_CHAR1);
                    break;
            #endif//ENABLE_ATSC_MAIN_MENU_CHANNEL_PAGE


            #if ENABLE_ATSC_MAIN_MENU_PICTURE_PAGE
                case HWND_MENU_PICTURE_3DNR:
                {
                    MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_PAGE, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_SINGLELIST_COMMON_PAGE, SW_SHOW);

                #if ATSC_READY
                    _eCommonSingleMode = EN_COMMON_SINGLELIST_3DNR;

                  #ifdef ENABLE_3DNR_OPTION_BY_SOURCE
                    switch(CURRENT_3DNR_OPTION)
                    {
                        case 1:
                            MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM2);
                            break;
                        case 2:
                            MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM3);
                            break;
                        case 3:
                            MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM4);
                            break;
                        case 4:
                            MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM5);
                            break;
                        default:// 0:off
                            MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM1);
                            break;
                    }
                  #else
                    if (IsVgaInUse())
                    {
                        MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM1);
                    }
                    else
                    {
                        switch(stGenSetting.g_SysSetting.Option3DNR)
                        {
                            case E_XC_PQ_3D_NR_LOW:
                                MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM2);
                                break;
                            case E_XC_PQ_3D_NR_MID:
                                MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM3);
                                break;
                            case E_XC_PQ_3D_NR_HIGH:
                                MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM4);
                                break;
                            case E_XC_PQ_3D_NR_AUTO:
                                MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM5);
                                break;
                            default:// 0:off
                                MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM1);
                                break;
                        }
                    }
                #endif // #ifdef ENABLE_3DNR_OPTION_BY_SOURCE
                #else//ATSC_READY

                    MApp_ZUI_API_SetFocus(HWND_MENU_SINGLELIST_ITEM1);
                #endif //ATSC_READY
                }//case HWND_MENU_PICTURE_3DN
                break;//case HWND_MENU_PICTURE_3DNR


                case HWND_MENU_PICTURE_BACKLIGHT:
                    MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_PAGE, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_ADJUST_BACKLIGHT_PAGE, SW_SHOW);
                    MApp_ZUI_API_SetFocus(HWND_MENU_PICTURE_ADJUST_BACKLIGHT_SUB);
                    break;
            #endif//ENABLE_ATSC_MAIN_MENU_PICTURE_PAGE


            #if ENABLE_ATSC_MAIN_MENU_SOUND_PAGE

                case HWND_MENU_SOUND_EQUALIZER:
                    MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_PAGE, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_EQ_ADVANCE_SUBPAGE_ITEMS, SW_SHOW);
                    if(stGenSetting.g_SoundSetting.SoundMode==SOUND_MODE_USER)
                    {
                        MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_EQ_ADVANCE_SUBPAGE_ITEMS_UP_ARROW,SW_SHOW);
                        MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_EQ_ADVANCE_SUBPAGE_ITEMS_DOWN_ARROW,SW_SHOW);
                    }
                    else
                    {
                        MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_EQ_ADVANCE_SUBPAGE_ITEMS_UP_ARROW,SW_HIDE);
                        MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_EQ_ADVANCE_SUBPAGE_ITEMS_DOWN_ARROW,SW_HIDE);
                    }
                    MApp_ZUI_API_SetFocus(HWND_MENU_SOUND_EQ_EQUALIZER);
                    break;

                case HWND_MENU_SOUND_MTS:
                    {
                        MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
                        MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_HIDE);
                        MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
                        MApp_ZUI_API_ShowWindow(HWND_MENU_SINGLELIST_COMMON_PAGE, SW_SHOW);
                        _eCommonSingleMode = EN_COMMON_SINGLELIST_MTS;
                        if(IsATVInUse() || IsAtscInUse())
                        {
                            switch(stGenSetting.g_SoundSetting.Mts)
                            {
                                case SOUND_MTS_MONO:
                                MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM1);
                                break;
                                case SOUND_MTS_STEREO:
                                MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM2);
                                break;
                                case SOUND_MTS_SAP:
                                MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM3);
                                break;
                                default:
                                MApp_ZUI_API_SetFocus(HWND_MENU_SINGLELIST_TITLE);
                                break;
                            }
                        }
                    }
                    break;

              #if 0
                case HWND_MENU_SOUND_AUDIO_OPTION:
                    MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_AUDIO_OPTION_SUBPAGE, SW_SHOW);
                    MApp_ZUI_API_SetFocus(HWND_MENU_SOUND_AUDIO_OPTION_ACCESSIBILITY);
                    break;
              #endif

            #endif//ENABLE_ATSC_MAIN_MENU_SOUND_PAGE


            #if ENABLE_ATSC_MENU_LOCK_UI
                case HWND_MENU_LOCK_MAINSUBPAGE_ITEM_INPUTBLOCK:
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_PAGE, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_INPUTBLOCKSUBPAGE, SW_SHOW);
                    MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_INPUTBLOCKSUBPAGE_ITEM_TV);
                    break;

                case HWND_MENU_LOCK_MAINSUBPAGE_ITEM_US:
                    MApp_ZUI_API_ShowWindow(MApp_ZUI_API_GetParent(hwnd), SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_PAGE, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_USSUBPAGE, SW_SHOW);
                    MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_USSUBPAGE_ITEM_TV);
                    break;

                case HWND_MENU_LOCK_MAINSUBPAGE_ITEM_CANADA:
                    MApp_ZUI_API_ShowWindow(MApp_ZUI_API_GetParent(hwnd), SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_PAGE, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_CANADASUBPAGE, SW_SHOW);
                    MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_CANADASUBPAGE_ITEM_ENG);
                    break;

                case HWND_MENU_LOCK_MAINSUBPAGE_ITEM_RRTSETTING:
                    g_u8CurrentRRT_Dimension = 0;
                    g_u8CurrentRRT_1stDimension_Item = 0;
                    MApp_ZUI_API_ShowWindow(MApp_ZUI_API_GetParent(hwnd), SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_PAGE, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE, SW_SHOW);
                    MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM0);
                    break;

                case HWND_MENU_LOCK_MAINSUBPAGE_ITEM_RESETRRT:
                    //MApp_ZUI_API_ShowWindow(MApp_ZUI_API_GetParent(hwnd), SW_HIDE);
                    _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_RESETRRT_CONFIRM);
                    break;
                case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM0:
                case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM1:
                case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM2:
                case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM3:
                case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM4:
                case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM5:
                case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM6:
                case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM7:
                case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM8:
                case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM9:
                    g_u8CurrentRRT_Dimension = _MApp_ZUI_ACT_RRTDimensionWindowMapToIndex(hwnd);
                    g_u8CurrentRRT_Option = 0;
                    g_u8CurrentRRT_1stOption = 0;
                    if (!MApp_VChip_GetCurVChipBlockStatus())
                    {
                        if ( (g_stVChipRatingInfo.u8DimVal0 && g_u8CurrentRRT_Dimension == 0) ||
                             (g_stVChipRatingInfo.u8DimVal1 && g_u8CurrentRRT_Dimension == 1) ||
                             (g_stVChipRatingInfo.u8DimVal2 && g_u8CurrentRRT_Dimension == 2) ||
                             (g_stVChipRatingInfo.u8DimVal3 && g_u8CurrentRRT_Dimension == 3) ||
                             (g_stVChipRatingInfo.u8DimVal4 && g_u8CurrentRRT_Dimension == 4) ||
                             (g_stVChipRatingInfo.u8DimVal5 && g_u8CurrentRRT_Dimension == 5) ||
                             (g_stVChipRatingInfo.u8DimVal6 && g_u8CurrentRRT_Dimension == 6) ||
                             (g_stVChipRatingInfo.u8DimVal7 && g_u8CurrentRRT_Dimension == 7) ||
                             (g_stVChipRatingInfo.u8DimVal8 && g_u8CurrentRRT_Dimension == 8) ||
                             (g_stVChipRatingInfo.u8DimVal9 && g_u8CurrentRRT_Dimension == 9)
                    #if (ENABLE_MAX_RRT_DIMENSION_NUMBER)
                        ||   (g_stVChipRatingInfo.u8DimVal10 && g_u8CurrentRRT_Dimension == 10) ||
                             (g_stVChipRatingInfo.u8DimVal11 && g_u8CurrentRRT_Dimension == 11) ||
                             (g_stVChipRatingInfo.u8DimVal12 && g_u8CurrentRRT_Dimension == 12) ||
                             (g_stVChipRatingInfo.u8DimVal13 && g_u8CurrentRRT_Dimension == 13) ||
                             (g_stVChipRatingInfo.u8DimVal14 && g_u8CurrentRRT_Dimension == 14) ||
                             (g_stVChipRatingInfo.u8DimVal15 && g_u8CurrentRRT_Dimension == 15) ||
                             (g_stVChipRatingInfo.u8DimVal16 && g_u8CurrentRRT_Dimension == 16) ||
                             (g_stVChipRatingInfo.u8DimVal17 && g_u8CurrentRRT_Dimension == 17) ||
                             (g_stVChipRatingInfo.u8DimVal18 && g_u8CurrentRRT_Dimension == 18) ||
                             (g_stVChipRatingInfo.u8DimVal19 && g_u8CurrentRRT_Dimension == 19) ||
                             (g_stVChipRatingInfo.u8DimVal20 && g_u8CurrentRRT_Dimension == 20) ||
                             (g_stVChipRatingInfo.u8DimVal21 && g_u8CurrentRRT_Dimension == 21) ||
                             (g_stVChipRatingInfo.u8DimVal22 && g_u8CurrentRRT_Dimension == 22) ||
                             (g_stVChipRatingInfo.u8DimVal23 && g_u8CurrentRRT_Dimension == 23) ||
                             (g_stVChipRatingInfo.u8DimVal24 && g_u8CurrentRRT_Dimension == 24) ||
                             (g_stVChipRatingInfo.u8DimVal25 && g_u8CurrentRRT_Dimension == 25) ||
                             (g_stVChipRatingInfo.u8DimVal26 && g_u8CurrentRRT_Dimension == 26) ||
                             (g_stVChipRatingInfo.u8DimVal27 && g_u8CurrentRRT_Dimension == 27) ||
                             (g_stVChipRatingInfo.u8DimVal28 && g_u8CurrentRRT_Dimension == 28) ||
                             (g_stVChipRatingInfo.u8DimVal29 && g_u8CurrentRRT_Dimension == 29) ||
                             (g_stVChipRatingInfo.u8DimVal30 && g_u8CurrentRRT_Dimension == 30) ||
                             (g_stVChipRatingInfo.u8DimVal31 && g_u8CurrentRRT_Dimension == 31) ||
                             (g_stVChipRatingInfo.u8DimVal32 && g_u8CurrentRRT_Dimension == 32) ||
                             (g_stVChipRatingInfo.u8DimVal33 && g_u8CurrentRRT_Dimension == 33) ||
                             (g_stVChipRatingInfo.u8DimVal34 && g_u8CurrentRRT_Dimension == 34) ||
                             (g_stVChipRatingInfo.u8DimVal35 && g_u8CurrentRRT_Dimension == 35) ||
                             (g_stVChipRatingInfo.u8DimVal36 && g_u8CurrentRRT_Dimension == 36) ||
                             (g_stVChipRatingInfo.u8DimVal37 && g_u8CurrentRRT_Dimension == 37) ||
                             (g_stVChipRatingInfo.u8DimVal38 && g_u8CurrentRRT_Dimension == 38) ||
                             (g_stVChipRatingInfo.u8DimVal39 && g_u8CurrentRRT_Dimension == 39) ||
                             (g_stVChipRatingInfo.u8DimVal40 && g_u8CurrentRRT_Dimension == 40)
                    #endif
                        )
                        {
                            //fVChipPassWordEntered = FALSE;
                            memset(&g_stVChipRatingInfo, 0, sizeof(g_stVChipRatingInfo));
                        }
                    }
                    MApp_ZUI_API_ShowWindow(MApp_ZUI_API_GetParent(hwnd), SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_RRTADJUSTSUBPAGE, SW_SHOW);
                    MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM0);
                    break;
            #endif//ENABLE_ATSC_MENU_LOCK_UI


            #if ENABLE_ATSC_MENU_OPTION_UI
                case HWND_MENU_OPTION_TRANSPARENT:
                {
                #if ATSC_READY
                    _eCommonSingleMode = EN_COMMON_SINGLELIST_TRANSPARENT;
                #endif
                    MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_SINGLELIST_COMMON_PAGE, SW_SHOW);
                #if ATSC_READY
                    switch(stGenSetting.g_SysSetting.Transparency)
                    {
                        case TRANSPARENCY_100_PERCENTAGE_VALUE:
                            MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM5);
                            break;
                        case TRANSPARENCY_75_PERCENTAGE_VALUE:
                            MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM4);
                            break;
                        case TRANSPARENCY_50_PERCENTAGE_VALUE:
                            MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM3);
                            break;
                        case TRANSPARENCY_25_PERCENTAGE_VALUE:
                            MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM2);
                            break;
                        default:
                            MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM1);
                            break;
                    }
                #endif
                }
                    break;


                case HWND_MENU_OPTION_SETUPWIZARD:
                    MApp_ZUI_ACT_ShutdownOSD();
                    //enUiMainMenuState = STATE_UIMENU_INIT;        // Eden Menu State
                    enMainMenuState = STATE_MENU_INIT;                // Chakra3 Menu State
                    stGenSetting.g_SysSetting.fFinishWizardMode = FALSE;
                    MApp_TV_ResetTvState();
                    MApp_TopStateMachine_SetTopState(STATE_TOP_DIGITALINPUTS);
                    break;

            #endif//ENABLE_ATSC_MENU_OPTION_UI

            #if ENABLE_ATSC_MENU_LOCK_UI
                case HWND_MENU_LOCK_USSUBPAGE_ITEM_TV:
                    MApp_ZUI_API_ShowWindow(MApp_ZUI_API_GetParent(hwnd), SW_HIDE);
                    //MApp_ZUI_API_ShowWindow(HWND_MENU_BACKGROUND, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_TVRATINGSUBPAGE, SW_SHOW);
                    MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV_NONE_ALL);
                    MApp_ZUI_ACT_TV_Rating_Disable_BG();
                    if ( (g_stVChipRatingInfo.RatingType == VCHIP_RATING_TYPE_TV) &&
                        (!MApp_VChip_GetCurVChipBlockStatus()) )
                    {
                        //fVChipPassWordEntered = FALSE;
                        memset(&g_stVChipRatingInfo, 0, sizeof(g_stVChipRatingInfo));
                        g_stVChipRatingInfo.u8EIA608Data1 = BIT6;

                    }
                    break;
                case HWND_MENU_LOCK_USSUBPAGE_ITEM_MPAA:
                    g_vchipPageType = EN_VCHIP_MPAA;
                    if ( (g_stVChipRatingInfo.RatingType == VCHIP_RATING_TYPE_MPAA) &&
                        (!MApp_VChip_GetCurVChipBlockStatus()) )
                    {
                        //fVChipPassWordEntered = FALSE;
                        memset(&g_stVChipRatingInfo, 0, sizeof(g_stVChipRatingInfo));
                        g_stVChipRatingInfo.u8EIA608Data1 = BIT6;
                    }
                    MApp_ZUI_API_ShowWindow(MApp_ZUI_API_GetParent(hwnd), SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_VCHIPSUBPAGE, SW_SHOW);
                    MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_VCHIPSUBPAGE_ITEM1);
                    break;
                case HWND_MENU_LOCK_CANADASUBPAGE_ITEM_ENG:
                    g_vchipPageType = EN_VCHIP_CANADAENG;

                    if ( (g_stVChipRatingInfo.RatingType == VCHIP_RATING_TYPE_CANADA_ENG) &&
                        (!MApp_VChip_GetCurVChipBlockStatus()))
                    {
                        //fVChipPassWordEntered = FALSE;
                        memset(&g_stVChipRatingInfo, 0, sizeof(g_stVChipRatingInfo));
                        g_stVChipRatingInfo.u8EIA608Data1 = BIT6;
                    }
                    MApp_ZUI_API_ShowWindow(MApp_ZUI_API_GetParent(hwnd), SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_VCHIPSUBPAGE, SW_SHOW);
                    MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_VCHIPSUBPAGE_ITEM1);
                    break;
                case HWND_MENU_LOCK_CANADASUBPAGE_ITEM_FRE:
                    g_vchipPageType = EN_VCHIP_CANADAFRE;

                    if ( (g_stVChipRatingInfo.RatingType == VCHIP_RATING_TYPE_CANADA_FRE) &&
                        (!MApp_VChip_GetCurVChipBlockStatus()) )
                    {
                        //fVChipPassWordEntered = FALSE;
                        memset(&g_stVChipRatingInfo, 0, sizeof(g_stVChipRatingInfo));
                        g_stVChipRatingInfo.u8EIA608Data1 = BIT6;
                    }
                    MApp_ZUI_API_ShowWindow(MApp_ZUI_API_GetParent(hwnd), SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_VCHIPSUBPAGE, SW_SHOW);
                    MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_VCHIPSUBPAGE_ITEM1);
                    break;
            #endif

                default:
                break;
            } // switch(hwnd)
            break;
        } //         case EN_EXE_GOTO_SUBPAGE:


        case EN_EXE_GOTO_PARENTPAGE:
        {
            HWND hwnd;
            hwnd = MApp_ZUI_API_GetFocus();

            switch(hwnd)
            {
            #if ENABLE_ATSC_MAIN_MENU_CHANNEL_PAGE
                case HWND_MENU_CHANNEL_AUTO_TUNING_NO:
                case HWND_MENU_CHANNEL_AUTO_TUNING_YES:
                case HWND_MENU_CHANNEL_AUTO_TUNING_BG_TEXT:
                    MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_AUTO_TUNING_PAGE, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_TITLE, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_ICON_CHANNEL, SW_SHOW);
                    MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_CHANNEL);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE_LIST, SW_SHOW);
                    MApp_ZUI_API_SetFocus(HWND_MENU_CHANNEL_AUTO_SCAN_ATSC);
                    break;
            #endif//ENABLE_ATSC_MAIN_MENU_CHANNEL_PAGE

            #if ENABLE_ATSC_MENU_LOCK_UI
                case HWND_MENU_LOCK_INPUTBLOCKSUBPAGE_ITEM_TV:
                case HWND_MENU_LOCK_INPUTBLOCKSUBPAGE_ITEM_AV:
                case HWND_MENU_LOCK_INPUTBLOCKSUBPAGE_ITEM_SVIDEO:
                case HWND_MENU_LOCK_INPUTBLOCKSUBPAGE_ITEM_COMPONENT:
                case HWND_MENU_LOCK_INPUTBLOCKSUBPAGE_ITEM_HDMI:
                case HWND_MENU_LOCK_INPUTBLOCKSUBPAGE_ITEM_PC:
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_INPUTBLOCKSUBPAGE, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_SHOW);
                    MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_LOCK);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_TITLE, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_ICON_LOCK,SW_SHOW);
                    //MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_MAINSUBPAGE, SW_SHOW);
                    MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_MAINSUBPAGE_ITEM_INPUTBLOCK);
                    break;
                case HWND_MENU_LOCK_USSUBPAGE_ITEM_TV:
                case HWND_MENU_LOCK_USSUBPAGE_ITEM_MPAA:
                    MApp_ZUI_API_ShowWindow(MApp_ZUI_API_GetParent(hwnd), SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_SHOW);
                    MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_LOCK);
                    //MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_MAINSUBPAGE, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_TITLE, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_ICON_LOCK,SW_SHOW);
                    MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_MAINSUBPAGE_ITEM_US);
                    break;
                case HWND_MENU_LOCK_CANADASUBPAGE_ITEM_ENG:
                case HWND_MENU_LOCK_CANADASUBPAGE_ITEM_FRE:
                    MApp_ZUI_API_ShowWindow(MApp_ZUI_API_GetParent(hwnd), SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_SHOW);
                    MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_LOCK);
                    //MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_MAINSUBPAGE, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_TITLE, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_ICON_LOCK,SW_SHOW);
                    MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_MAINSUBPAGE_ITEM_CANADA);
                    break;
                case HWND_MENU_LOCK_VCHIPSUBPAGE_ITEM1:
                case HWND_MENU_LOCK_VCHIPSUBPAGE_ITEM2:
                case HWND_MENU_LOCK_VCHIPSUBPAGE_ITEM3:
                case HWND_MENU_LOCK_VCHIPSUBPAGE_ITEM4:
                case HWND_MENU_LOCK_VCHIPSUBPAGE_ITEM5:
                case HWND_MENU_LOCK_VCHIPSUBPAGE_ITEM6:
                case HWND_MENU_LOCK_VCHIPSUBPAGE_ITEM7:
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_VCHIPSUBPAGE, SW_HIDE);
                    if(g_vchipPageType == EN_VCHIP_MPAA)
                    {
                        MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_USSUBPAGE, SW_SHOW);
                        MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_USSUBPAGE_ITEM_MPAA);
                    }
                    else if(g_vchipPageType == EN_VCHIP_CANADAENG)
                    {
                        MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_CANADASUBPAGE, SW_SHOW);
                        MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_CANADASUBPAGE_ITEM_ENG);
                    }
                    else if(g_vchipPageType == EN_VCHIP_CANADAFRE)
                    {
                        MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_CANADASUBPAGE, SW_SHOW);
                        MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_CANADASUBPAGE_ITEM_FRE);
                    }
                    break;
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVY_ALL:
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVY7_ALL:
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVG_ALL:
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_ALL:
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_ALL:
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_ALL:
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVY7_FV:
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_V:
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_V:
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_V:
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_S:
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_S:
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_S:
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_L:
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_L:
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_L:
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_D:
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_D:
                    MApp_ZUI_API_ShowWindow(MApp_ZUI_API_GetParent(hwnd), SW_HIDE);
                    //MApp_ZUI_API_ShowWindow(HWND_MENU_BACKGROUND, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_USSUBPAGE, SW_SHOW);
                    MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_USSUBPAGE_ITEM_TV);
                    break;
                case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM0:
                case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM1:
                case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM2:
                case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM3:
                case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM4:
                case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM5:
                case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM6:
                case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM7:
                case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM8:
                case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM9:
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_TITLE, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_ICON_LOCK, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_SHOW);
                    MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_LOCK);
                    //MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_MAINSUBPAGE, SW_SHOW);
                    MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_MAINSUBPAGE_ITEM_RRTSETTING);
                    break;
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM0:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM1:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM2:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM3:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM4:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM5:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM6:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM7:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM8:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM9:
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_RRTADJUSTSUBPAGE, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE, SW_SHOW);
                    MApp_ZUI_API_SetFocus(_MApp_ZUI_ACT_RRTDimensionIdMapToWindow(g_u8CurrentRRT_Dimension));
                    break;
            #endif

                default:
                    //
                    break;
            }

            break;
        } // case EN_EXE_GOTO_PARENTPAGE:


        case EN_EXE_FUNCTION:
        {
            HWND hwnd;
            hwnd = MApp_ZUI_API_GetFocus();
            switch(hwnd)
            {
            #if ENABLE_ATSC_MAIN_MENU_CHANNEL_PAGE

                case HWND_MENU_LOCK_VCHIPSUBPAGE_ITEM1:
                    if(g_vchipPageType == EN_VCHIP_MPAA)
                    {
                        if(stGenSetting.g_VChipSetting.u8VChipMPAAItem & VCHIP_MPAARATING_G)
                            stGenSetting.g_VChipSetting.u8VChipMPAAItem &= EXCLUDE_MPAA_G;
                        else
                            stGenSetting.g_VChipSetting.u8VChipMPAAItem |= INCLUDE_MPAA_G;
                    }
                    else if(g_vchipPageType == EN_VCHIP_CANADAENG)
                    {
                       if((stGenSetting.g_VChipSetting.u8VChipCEItem > VCHIP_ENGRATING_C)||
                            (stGenSetting.g_VChipSetting.u8VChipCEItem == VCHIP_ENGRATING_EXEMPT))
                            stGenSetting.g_VChipSetting.u8VChipCEItem = VCHIP_ENGRATING_C;
                       else
                            stGenSetting.g_VChipSetting.u8VChipCEItem = VCHIP_ENGRATING_C8Plus;

                    }
                    else
                    {
                        if((stGenSetting.g_VChipSetting.u8VChipCFItem > VCHIP_FRERATING_G)||
                        (stGenSetting.g_VChipSetting.u8VChipCFItem == VCHIP_FRERATING_EXEMPT))
                            stGenSetting.g_VChipSetting.u8VChipCFItem = VCHIP_FRERATING_G;
                        else
                            stGenSetting.g_VChipSetting.u8VChipCFItem = VCHIP_FRERATING_8ansPlus;
                    }
                    MApp_InvalidateUI_CompareRating();
                    break;

                case HWND_MENU_LOCK_VCHIPSUBPAGE_ITEM2:
                    if(g_vchipPageType == EN_VCHIP_MPAA)
                    {
                        if(stGenSetting.g_VChipSetting.u8VChipMPAAItem & VCHIP_MPAARATING_PG)
                            stGenSetting.g_VChipSetting.u8VChipMPAAItem &= EXCLUDE_MPAA_PG;
                        else
                            stGenSetting.g_VChipSetting.u8VChipMPAAItem |= INCLUDE_MPAA_PG;
                    }
                    else if(g_vchipPageType == EN_VCHIP_CANADAENG)
                    {
                       if((stGenSetting.g_VChipSetting.u8VChipCEItem > VCHIP_ENGRATING_C8Plus)||
                            (stGenSetting.g_VChipSetting.u8VChipCEItem == VCHIP_ENGRATING_EXEMPT))
                            stGenSetting.g_VChipSetting.u8VChipCEItem = VCHIP_ENGRATING_C8Plus;
                       else
                            stGenSetting.g_VChipSetting.u8VChipCEItem = VCHIP_ENGRATING_G;
                    }
                    else
                    {
                        if((stGenSetting.g_VChipSetting.u8VChipCFItem > VCHIP_FRERATING_8ansPlus)||
                        (stGenSetting.g_VChipSetting.u8VChipCFItem == VCHIP_FRERATING_EXEMPT))
                            stGenSetting.g_VChipSetting.u8VChipCFItem = VCHIP_FRERATING_8ansPlus;
                        else
                            stGenSetting.g_VChipSetting.u8VChipCFItem = VCHIP_FRERATING_13ansPlus;
                    }
                    MApp_InvalidateUI_CompareRating();
                    break;
                case HWND_MENU_LOCK_VCHIPSUBPAGE_ITEM3:
                    if(g_vchipPageType == EN_VCHIP_MPAA)
                    {
                        if(stGenSetting.g_VChipSetting.u8VChipMPAAItem & VCHIP_MPAARATING_PG_13)
                            stGenSetting.g_VChipSetting.u8VChipMPAAItem &= EXCLUDE_MPAA_PG_13;
                        else
                            stGenSetting.g_VChipSetting.u8VChipMPAAItem |= INCLUDE_MPAA_PG_13;
                    }
                    else if(g_vchipPageType == EN_VCHIP_CANADAENG)
                    {
                       if((stGenSetting.g_VChipSetting.u8VChipCEItem > VCHIP_ENGRATING_G)||
                            (stGenSetting.g_VChipSetting.u8VChipCEItem == VCHIP_ENGRATING_EXEMPT))
                            stGenSetting.g_VChipSetting.u8VChipCEItem = VCHIP_ENGRATING_G;
                       else
                            stGenSetting.g_VChipSetting.u8VChipCEItem = VCHIP_ENGRATING_PG;
                    }
                    else
                    {
                        if((stGenSetting.g_VChipSetting.u8VChipCFItem > VCHIP_FRERATING_13ansPlus)||
                        (stGenSetting.g_VChipSetting.u8VChipCFItem == VCHIP_FRERATING_EXEMPT))
                            stGenSetting.g_VChipSetting.u8VChipCFItem = VCHIP_FRERATING_13ansPlus;
                        else
                            stGenSetting.g_VChipSetting.u8VChipCFItem = VCHIP_FRERATING_16ansPlus;
                    }
                    MApp_InvalidateUI_CompareRating();
                    break;
                case HWND_MENU_LOCK_VCHIPSUBPAGE_ITEM4:
                    if(g_vchipPageType == EN_VCHIP_MPAA)
                    {
                        if(stGenSetting.g_VChipSetting.u8VChipMPAAItem & VCHIP_MPAARATING_R)
                            stGenSetting.g_VChipSetting.u8VChipMPAAItem &= EXCLUDE_MPAA_R;
                        else
                            stGenSetting.g_VChipSetting.u8VChipMPAAItem |= INCLUDE_MPAA_R;
                    }
                    else if(g_vchipPageType == EN_VCHIP_CANADAENG)
                    {
                       if((stGenSetting.g_VChipSetting.u8VChipCEItem > VCHIP_ENGRATING_PG)||
                            (stGenSetting.g_VChipSetting.u8VChipCEItem == VCHIP_ENGRATING_EXEMPT))
                            stGenSetting.g_VChipSetting.u8VChipCEItem = VCHIP_ENGRATING_PG;
                       else
                            stGenSetting.g_VChipSetting.u8VChipCEItem = VCHIP_ENGRATING_14Plus;
                    }
                    else
                    {
                        if((stGenSetting.g_VChipSetting.u8VChipCFItem > VCHIP_FRERATING_16ansPlus)||
                        (stGenSetting.g_VChipSetting.u8VChipCFItem == VCHIP_FRERATING_EXEMPT))
                            stGenSetting.g_VChipSetting.u8VChipCFItem = VCHIP_FRERATING_16ansPlus;
                        else
                            stGenSetting.g_VChipSetting.u8VChipCFItem = VCHIP_FRERATING_18ansPlus;
                    }
                    MApp_InvalidateUI_CompareRating();
                    break;
                case HWND_MENU_LOCK_VCHIPSUBPAGE_ITEM5:
                    if(g_vchipPageType == EN_VCHIP_MPAA)
                    {
                        if(stGenSetting.g_VChipSetting.u8VChipMPAAItem & VCHIP_MPAARATING_NC_17)
                            stGenSetting.g_VChipSetting.u8VChipMPAAItem &= EXCLUDE_MPAA_NC_17;
                        else
                            stGenSetting.g_VChipSetting.u8VChipMPAAItem |= INCLUDE_MPAA_NC_17;
                    }
                    else if(g_vchipPageType == EN_VCHIP_CANADAENG)
                    {
                       if((stGenSetting.g_VChipSetting.u8VChipCEItem > VCHIP_ENGRATING_14Plus)||
                            (stGenSetting.g_VChipSetting.u8VChipCEItem == VCHIP_ENGRATING_EXEMPT))
                            stGenSetting.g_VChipSetting.u8VChipCEItem = VCHIP_ENGRATING_14Plus;
                       else
                            stGenSetting.g_VChipSetting.u8VChipCEItem = VCHIP_ENGRATING_18Plus;
                    }
                    else
                    {
                        if(stGenSetting.g_VChipSetting.u8VChipCFItem == VCHIP_FRERATING_EXEMPT)
                            stGenSetting.g_VChipSetting.u8VChipCFItem = VCHIP_FRERATING_18ansPlus;
                        else
                            stGenSetting.g_VChipSetting.u8VChipCFItem = VCHIP_FRERATING_EXEMPT;
                    }
                    MApp_InvalidateUI_CompareRating();
                    break;
                case HWND_MENU_LOCK_VCHIPSUBPAGE_ITEM6:
                    if(g_vchipPageType == EN_VCHIP_MPAA)
                    {
                        if(stGenSetting.g_VChipSetting.u8VChipMPAAItem & VCHIP_MPAARATING_X)
                            stGenSetting.g_VChipSetting.u8VChipMPAAItem &= EXCLUDE_MPAA_X;
                        else
                            stGenSetting.g_VChipSetting.u8VChipMPAAItem |= INCLUDE_MPAA_X;
                    }
                    else
                    {
                        if(stGenSetting.g_VChipSetting.u8VChipCEItem == VCHIP_ENGRATING_EXEMPT)
                            stGenSetting.g_VChipSetting.u8VChipCEItem = VCHIP_ENGRATING_18Plus;
                        else
                            stGenSetting.g_VChipSetting.u8VChipCEItem = VCHIP_ENGRATING_EXEMPT;
                    }
                    MApp_InvalidateUI_CompareRating();
                    break;
                case HWND_MENU_LOCK_VCHIPSUBPAGE_ITEM7:
                    if(stGenSetting.g_VChipSetting.u8VChipMPAAItem & VCHIP_MPAARATING_NOT_RATED)
                        stGenSetting.g_VChipSetting.u8VChipMPAAItem &= ~VCHIP_MPAARATING_NOT_RATED;
                    else
                        stGenSetting.g_VChipSetting.u8VChipMPAAItem |= VCHIP_MPAARATING_NOT_RATED;
                    MApp_InvalidateUI_CompareRating();
                    break;
                case HWND_MENU_CHANNEL_AUTO_TUNING_BG_TEXT:
                    MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_AUTO_TUNING_PAGE, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(MApp_ZUI_API_GetParent(hwnd), SW_HIDE);
                  #if (ENABLE_ATSC_TTS)
                    MApp_TTSControlSetInputText(MApp_ZUI_API_GetString(en_str_Auto_Scan), MApp_UiMenu_u16Strlen(MApp_ZUI_API_GetString(en_str_Auto_Scan)));
                    MApp_TTSControlSetOn(TRUE);
                  #endif
                    MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_AUTO_SCAN_RESULT_SUB_PAGE_ITEM, SW_SHOW);
                    enMainMenuState = STATE_MENU_GOTO_SCAN;
                    MApp_Scan_ATSC_SetAutoScan();
                    break;

                case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR1:
                case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR2:
                case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR3:
                case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR4:
                case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR5:
                case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR6:
                case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR7:
                  #if ATSC_READY
                    MApp_UiMenuFunc_ProNameEdit_Save();
                    MApp_ZUI_API_ShowWindow(MApp_ZUI_API_GetParent(hwnd), SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE_LIST, SW_SHOW);
                    MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_CHANNEL);
                    MApp_ZUI_API_SetFocus(HWND_MENU_CHANNEL_CHANNEL_LABEL);
                  #endif
                    break;
            #endif//ENABLE_ATSC_MAIN_MENU_CHANNEL_PAGE

            #if ENABLE_ATSC_MENU_LOCK_UI
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV_NONE_ALL:
                    MApp_UiMenuFunc_SetVChip_TVRating_TV_NONE_ALL();
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_TVRATINGSUBPAGE);
                    break;
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVY_ALL:
                    MApp_UiMenuFunc_SetVChip_TVRating_TV_Y_ALL();
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_TVRATINGSUBPAGE);
                    break;
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVY7_ALL:
                    MApp_UiMenuFunc_SetVChip_TVRating_TV_Y7_ALL();
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_TVRATINGSUBPAGE);
                    break;
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVG_ALL:
                    MApp_UiMenuFunc_SetVChip_TVRating_TV_G_ALL();
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_TVRATINGSUBPAGE);
                    break;
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_ALL:
                    MApp_UiMenuFunc_SetVChip_TVRating_TV_PG_ALL();
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_TVRATINGSUBPAGE);
                    break;
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_ALL:
                    MApp_UiMenuFunc_SetVChip_TVRating_TV_14_ALL();
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_TVRATINGSUBPAGE);
                    break;
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_ALL:
                    MApp_UiMenuFunc_SetVChip_TVRating_TV_MA_ALL();
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_TVRATINGSUBPAGE);
                    break;
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVY7_FV:
                    MApp_UiMenuFunc_SetVChip_TVRating_TV_Y7_FV();
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_TVRATINGSUBPAGE);
                    break;
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_V:
                    MApp_UiMenuFunc_SetVChip_TVRating_TV_PG_V();
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_TVRATINGSUBPAGE);
                    break;
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_V:
                    MApp_UiMenuFunc_SetVChip_TVRating_TV_14_V();
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_TVRATINGSUBPAGE);
                    break;
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_V:
                    MApp_UiMenuFunc_SetVChip_TVRating_TV_MA_V();
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_TVRATINGSUBPAGE);
                    break;
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_S:
                    MApp_UiMenuFunc_SetVChip_TVRating_TV_PG_S();
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_TVRATINGSUBPAGE);
                    break;
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_S:
                    MApp_UiMenuFunc_SetVChip_TVRating_TV_14_S();
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_TVRATINGSUBPAGE);
                    break;
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_S:
                    MApp_UiMenuFunc_SetVChip_TVRating_TV_MA_S();
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_TVRATINGSUBPAGE);
                    break;
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_L:
                    MApp_UiMenuFunc_SetVChip_TVRating_TV_PG_L();
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_TVRATINGSUBPAGE);
                    break;
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_L:
                    MApp_UiMenuFunc_SetVChip_TVRating_TV_14_L();
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_TVRATINGSUBPAGE);
                    break;
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_L:
                    MApp_UiMenuFunc_SetVChip_TVRating_TV_MA_L();
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_TVRATINGSUBPAGE);
                    break;
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_D:
                    MApp_UiMenuFunc_SetVChip_TVRating_TV_PG_D();
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_TVRATINGSUBPAGE);
                    break;
                case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_D:
                    MApp_UiMenuFunc_SetVChip_TVRating_TV_14_D();
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_TVRATINGSUBPAGE);
                    break;

            #endif
                default:
                    break;
            }
        }
        break;


    #if ENABLE_ATSC_MAIN_MENU_CHANNEL_PAGE
       case EN_EXE_CHLIST_UP:
          #if (ENABLE_CHCHANGETIME)
            printf("[Channel change time begin]\n");
            gbKeyPress = TRUE;
            gU32ChChangeTime = msAPI_Timer_GetTime0();
          #endif
            u16Temp = MApp_ChanProc_GetCurProgIndex();
            u16Temp = MApp_ChanProc_CalculateCurPageBaseIdx( u16Temp, MAX_NUM_OF_SRV_ITEM );//pre-page base
            MApp_ChannelChange_DisableChannel(TRUE,MAIN_WINDOW);
            if(bChannelListType == FALSE)//favorite list
            {
                MApp_ChanProc_DecProgIndex(MAIN_LIST, 1, TRUE);
            }
            else
            {
                MApp_ChanProc_DecProgIndex(MAIN_LIST, 1, FALSE);
            }
            MApp_ChanProc_RefreshChannelBuffer(MAIN_LIST);

            if(IS_HIDE_CH_ATSC(MApp_ChanProc_GetCurProgIndex()))
            {
                bChListKeyPress = FALSE;
            }
            else
            {
                bChListKeyPress = TRUE;
                u32ChListKeyPressStartTime = msAPI_Timer_GetTime0();
            }

            if(u16Temp != MApp_ChanProc_CalculateCurPageBaseIdx( MApp_ChanProc_GetCurProgIndex(), MAX_NUM_OF_SRV_ITEM ))
            {
                GUI_ENUM_DYNAMIC_LIST_STATE state = EN_DL_STATE_HIDDEN;
                {
                    HWND child, last_succ;
                    last_succ = MApp_ZUI_API_GetLastSuccessor(HWND_MENU_CHANNEL_LIST_ITEMS);
                    for (child = HWND_MENU_CHANNEL_LIST_ITEMS+1; child <= last_succ; child++)
                    {
                        state = MApp_ZUI_ACT_QueryDynamicListItemStatus(child);
                        if (state == EN_DL_STATE_HIDDEN)
                        {
                            MApp_ZUI_API_ShowWindow(child,SW_HIDE);
                        }
                        else if(state == EN_DL_STATE_DISABLED)
                        {
                            MApp_ZUI_API_EnableWindow(child,FALSE);
                            MApp_ZUI_API_ShowWindow(child,SW_SHOW);
                        }
                        else
                        {
                            MApp_ZUI_API_EnableWindow(child,TRUE);
                            MApp_ZUI_API_ShowWindow(child,SW_SHOW);
                        }
                    }

                }
                u16Temp = MApp_ChanProc_GetCurProgIndex();
                u16Temp2 = MApp_ChanProc_CalculateCurPageBaseIdx( u16Temp, MAX_NUM_OF_SRV_ITEM );
                MApp_ZUI_API_SetFocus(_MApp_ZUI_ACT_MenuChannelListIdMapToWindow((U8)(u16Temp - u16Temp2)));
            }
            else
            {
                MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_CHANNEL_LIST_ITEMS);
                u8Temp = (U8)((MApp_ChanProc_GetCurProgIndex()-1)%MAX_NUM_OF_SRV_ITEM);
                MApp_ZUI_API_SetFocus(_MenuChannelListHwndList[u8Temp]);
            }
            break;
        #endif//ENABLE_ATSC_MAIN_MENU_CHANNEL_PAGE


    #if ENABLE_ATSC_MAIN_MENU_CHANNEL_PAGE
        case EN_EXE_CHLIST_DOWN:
          #if (ENABLE_CHCHANGETIME)
            printf("[Channel change time begin]\n");
            gbKeyPress = TRUE;
            gU32ChChangeTime = msAPI_Timer_GetTime0();
          #endif
            u16Temp = MApp_ChanProc_GetCurProgIndex();
            u16Temp = MApp_ChanProc_CalculateCurPageBaseIdx( u16Temp, MAX_NUM_OF_SRV_ITEM );//pre-page base
            MApp_ChannelChange_DisableChannel(TRUE,MAIN_WINDOW);
            if(bChannelListType == FALSE)//favorite list
            {
                MApp_ChanProc_IncProgIndex(MAIN_LIST, 1, TRUE);
            }
            else
            {
                MApp_ChanProc_IncProgIndex(MAIN_LIST, 1, FALSE);
            }
            MApp_ChanProc_RefreshChannelBuffer(MAIN_LIST);
            if(IS_HIDE_CH_ATSC(MApp_ChanProc_GetCurProgIndex()))
            {
                bChListKeyPress = FALSE;
            }
            else
            {
                bChListKeyPress = TRUE;
                u32ChListKeyPressStartTime = msAPI_Timer_GetTime0();
            }
            if(u16Temp != MApp_ChanProc_CalculateCurPageBaseIdx( MApp_ChanProc_GetCurProgIndex(), MAX_NUM_OF_SRV_ITEM ))
            {
                GUI_ENUM_DYNAMIC_LIST_STATE state = EN_DL_STATE_HIDDEN;
                {
                    HWND child, last_succ;
                    last_succ = MApp_ZUI_API_GetLastSuccessor(HWND_MENU_CHANNEL_LIST_ITEMS);
                    for (child = HWND_MENU_CHANNEL_LIST_ITEMS+1; child <= last_succ; child++)
                    {
                        state = MApp_ZUI_ACT_QueryDynamicListItemStatus(child);
                        if (state == EN_DL_STATE_HIDDEN)
                        {
                            MApp_ZUI_API_ShowWindow(child,SW_HIDE);
                        }
                        else if(state == EN_DL_STATE_DISABLED)
                        {
                            MApp_ZUI_API_EnableWindow(child,FALSE);
                            MApp_ZUI_API_ShowWindow(child,SW_SHOW);
                        }
                        else
                        {
                            MApp_ZUI_API_EnableWindow(child,TRUE);
                            MApp_ZUI_API_ShowWindow(child,SW_SHOW);
                        }
                    }

                }
                u16Temp = MApp_ChanProc_GetCurProgIndex();
                u16Temp2 = MApp_ChanProc_CalculateCurPageBaseIdx( u16Temp, MAX_NUM_OF_SRV_ITEM );
                MApp_ZUI_API_SetFocus(_MApp_ZUI_ACT_MenuChannelListIdMapToWindow((U8)(u16Temp - u16Temp2)));
            }
            else
            {
                MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_CHANNEL_LIST_ITEMS);
                u8Temp = (U8)((MApp_ChanProc_GetCurProgIndex()-1)%MAX_NUM_OF_SRV_ITEM);
                MApp_ZUI_API_SetFocus(_MenuChannelListHwndList[u8Temp]);
            }
    #endif//ENABLE_ATSC_MAIN_MENU_CHANNEL_PAGE
            break;


    #if ENABLE_ATSC_MAIN_MENU_CHANNEL_PAGE
        case EN_EXE_CHLIST_PAGE_DOWN:
            u16Temp = MApp_ChanProc_GetCurProgIndex();
            MApp_ChannelChange_DisableChannel(TRUE, MAIN_WINDOW);
            if(bChannelListType == FALSE)//favorite list
            {
                MApp_ChanProc_IncProgIndex(MAIN_LIST, MAX_NUM_OF_SRV_ITEM, TRUE);
            }
            else
            {
                MApp_ChanProc_IncProgIndex(MAIN_LIST, MAX_NUM_OF_SRV_ITEM, FALSE);
            }
            MApp_ChanProc_RefreshChannelBuffer(MAIN_LIST);
            if(IS_HIDE_CH_ATSC(MApp_ChanProc_GetCurProgIndex()))
            {
                bChListKeyPress = FALSE;
            }
            else
            {
                bChListKeyPress = TRUE;
                u32ChListKeyPressStartTime = msAPI_Timer_GetTime0();
            }
            MApp_ZUI_CTL_DynamicListRefreshContent(HWND_MENU_CHANNEL_LIST_ITEMS);

            u16Temp = MApp_ChanProc_GetCurProgIndex();
            //printf("CurProgIndex = %d\n",u16Temp);
            if(u16Temp % MAX_NUM_OF_SRV_ITEM == 0)
                MApp_ZUI_API_SetFocus(_MenuChannelListHwndList[MAX_NUM_OF_SRV_ITEM-1]);
            else
                MApp_ZUI_API_SetFocus(_MenuChannelListHwndList[(u16Temp%MAX_NUM_OF_SRV_ITEM)-1]);
        #endif//ENABLE_ATSC_MAIN_MENU_CHANNEL_PAGE
            break;


    #if ENABLE_ATSC_MAIN_MENU_CHANNEL_PAGE
        case EN_EXE_CHLIST_PAGE_UP:
            u16Temp = MApp_ChanProc_GetCurProgIndex();
            MApp_ChannelChange_DisableChannel(TRUE,MAIN_WINDOW);
            if(bChannelListType == FALSE)//favorite list
            {
                MApp_ChanProc_DecProgIndex(MAIN_LIST, MAX_NUM_OF_SRV_ITEM, TRUE);

            }
            else
            {
                MApp_ChanProc_DecProgIndex(MAIN_LIST, MAX_NUM_OF_SRV_ITEM, FALSE);
            }
            MApp_ChanProc_RefreshChannelBuffer(MAIN_LIST);
            if(IS_HIDE_CH_ATSC(MApp_ChanProc_GetCurProgIndex()))
            {
                bChListKeyPress = FALSE;
            }
            else
            {
                bChListKeyPress = TRUE;
                u32ChListKeyPressStartTime = msAPI_Timer_GetTime0();
            }

            MApp_ZUI_CTL_DynamicListRefreshContent(HWND_MENU_CHANNEL_LIST_ITEMS);
            u16Temp = MApp_ChanProc_GetCurProgIndex();
            if(u16Temp % MAX_NUM_OF_SRV_ITEM == 0)
                MApp_ZUI_API_SetFocus(_MenuChannelListHwndList[MAX_NUM_OF_SRV_ITEM-1]);
            else
                MApp_ZUI_API_SetFocus(_MenuChannelListHwndList[(u16Temp%MAX_NUM_OF_SRV_ITEM)-1]);
        #endif//ENABLE_ATSC_MAIN_MENU_CHANNEL_PAGE
            break;


#if ENABLE_ATSC_MAIN_MENU_CHANNEL_PAGE
        case EN_EXE_CHLIST_SELECT:
            //printf("EN_EXE_CHLIST_SELECT\n");

            if(bChannelListType == 0) //favorite list
                MApp_FuncExec_Mainpage(EN_FUNC_MAINPAFE_SET_FAV_CH_ATSC, NULL, NULL) ;
            else
                MApp_FuncExec_Mainpage(EN_FUNC_MAINPAGE_SET_HIDE_CH_ATSC, NULL, NULL) ;
            fUpdateDataBase = TRUE;
            MApp_ZUI_API_InvalidateAllSuccessors(MApp_ZUI_API_GetFocus());
#endif//ENABLE_ATSC_MAIN_MENU_CHANNEL_PAGE
            break;


        case EN_EXE_MAINMENU_DTV_SIGNAL_REFLASH:
            if (MApp_ZUI_API_IsWindowVisible(HWND_MENU_CHANNEL_DTV_SIGNAL))
            {
                _MApp_ZUI_ACT_MainMenu_Indicate_Signal_Status();
                MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_CHANNEL_DTV_SIGNAL);
            }
            break;

        case EN_EXE_INC_VALUE:
        {
            HWND hwnd;
            hwnd = MApp_ZUI_API_GetFocus();
            //U32 U32ShowFlag;

            switch(hwnd)
            {
            #if ENABLE_ATSC_MAIN_MENU_CHANNEL_PAGE
                case HWND_MENU_CHANNEL_ANTENNA:
                {
                    MApp_UiMenuFunc_AdjChannelAntenna(TRUE);
                    if ((stChSetting.u16MainListSrvNum != 0)&&(stChSetting.u16TotalHideSrvNum < stChSetting.u16MainListSrvNum))
                    {
                        MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_FAVORITE, TRUE);
                        MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_SHOW_HIDE, TRUE);
                    }
                    else if((stChSetting.u16MainListSrvNum != 0)&&(stChSetting.u16TotalHideSrvNum >= stChSetting.u16MainListSrvNum))
                    {
                        MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_FAVORITE,FALSE);
                        MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_SHOW_HIDE, TRUE);
                    }
                    else
                    {
                        MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_FAVORITE, FALSE);
                        MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_SHOW_HIDE, FALSE);
                    }

                    if ( (stChSetting.u16MainListSrvNum != 0)&&(stChSetting.u16MainListSrvNum-stChSetting.u16TotalHideSrvNum>0) )
                    {
                        MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_CHANNEL_NO, TRUE);
                        MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_CHANNEL_LABEL, TRUE);
                    }
                    else
                    {
                        MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_CHANNEL_NO, FALSE);
                        MApp_ZUI_API_EnableWindow(HWND_MENU_CHANNEL_CHANNEL_LABEL, FALSE);
                    }
                }
                break;

                case HWND_MENU_CHANNEL_CHANNEL_NO:
                  #if ATSC_READY
                    MApp_UiMenuFunc_AdjChannelNO(TRUE);
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_CHANNEL_CHANNEL_LABEL);
                  #endif
                    break;

                case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR1:
                  #if ATSC_READY
                    MApp_UiMenuFunc_ProNameEdit_AdjustChar(TRUE,0);
                  #endif
                    break;
                case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR2:
                  #if ATSC_READY
                    MApp_UiMenuFunc_ProNameEdit_AdjustChar(TRUE,1);
                  #endif
                    break;
                case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR3:
                  #if ATSC_READY
                    MApp_UiMenuFunc_ProNameEdit_AdjustChar(TRUE,2);
                  #endif
                    break;
                case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR4:
                  #if ATSC_READY
                    MApp_UiMenuFunc_ProNameEdit_AdjustChar(TRUE,3);
                  #endif
                    break;
                case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR5:
                  #if ATSC_READY
                    MApp_UiMenuFunc_ProNameEdit_AdjustChar(TRUE,4);
                  #endif
                    break;
                case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR6:
                  #if ATSC_READY
                    MApp_UiMenuFunc_ProNameEdit_AdjustChar(TRUE,5);
                  #endif
                    break;
                case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR7:
                  #if ATSC_READY
                    MApp_UiMenuFunc_ProNameEdit_AdjustChar(TRUE,6);
                  #endif
                    break;

            #endif//ENABLE_ATSC_MAIN_MENU_CHANNEL_PAGE

            #if ENABLE_ATSC_MAIN_MENU_PICTURE_PAGE
                case HWND_MENU_PICTURE_DLC:
                  #if ATSC_READY
                    MApp_UiMenuFunc_AdjustDLC(TRUE);
                  #endif
                    break;
                case HWND_MENU_PICTURE_ADJUST_BACKLIGHT_SUB:
                  //#if ATSC_READY
                    MApp_UiMenuFunc_AdjustBacklightPWM(TRUE);
                  //#endif
                    break;
                case HWND_MENU_PICTURE_COLRANGE:
                    MApp_ZUI_ACT_ExecuteMenuItemAction(EN_EXE_COLOR_RANGE_SETTING);
                    break;
            #endif//ENABLE_ATSC_MAIN_MENU_PICTURE_PAGE
						#if(SENSOR_CHIP!=NOT_SUPPORT_LIGHT_SENSOR)
                case HWND_MENU_PICTURE_LS:
                    MApp_ZUI_ACT_ExecuteMenuItemAction(EN_EXE_LIGHT_SENSOR_SETTING);
                    break;						
						#endif

            #if ENABLE_ATSC_MAIN_MENU_SOUND_PAGE
                case HWND_MENU_SOUND_EQ_EQUALIZER:
                MApp_UiMenuFunc_AdjAudioMode(TRUE);
                if(stGenSetting.g_SoundSetting.SoundMode==SOUND_MODE_USER)
                {
                    MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_EQ_ADVANCE_SUBPAGE_ITEMS_UP_ARROW,SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_EQ_ADVANCE_SUBPAGE_ITEMS_DOWN_ARROW,SW_SHOW);
                }
                else
                {
                    MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_EQ_ADVANCE_SUBPAGE_ITEMS_UP_ARROW,SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_EQ_ADVANCE_SUBPAGE_ITEMS_DOWN_ARROW,SW_HIDE);
                }
                MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_SOUND_EQ_ADVANCE_SUBPAGE_ITEMS);
                MApp_ZUI_CTL_DynamicListRefreshContent(HWND_MENU_SOUND_EQ_ADVANCE_LIST);
                break;

            #if 0
                case HWND_MENU_SOUND_DIGITAL_AUDIO_SELECTION:
                {
                    MApp_UiMenuFunc_AdjustDigitalAudioSelect(FALSE);
                }
                break;
            #endif

                case HWND_MENU_SOUND_AUDIO_ONLY:
                {
                #if ENABLE_ATSC
                    MApp_UiMenuFunc_AdjustAudioOnly(TRUE);
                #endif
                }
                break;

                case HWND_MENU_SOUND_AVC:
                {
                    MApp_UiMenuFunc_AdjustAVC(TRUE);
                    MApp_ZUI_API_InvalidateWindow(HWND_MENU_SOUND_AVC_OPTION);
                }
                break;


                case HWND_MENU_SOUND_EQ_ADVANCE_150HZ:
                    MApp_UiMenuFunc_AdjustAudio150Hz(TRUE);
                    break;
                case HWND_MENU_SOUND_EQ_ADVANCE_500HZ:
                    MApp_UiMenuFunc_AdjustAudio500Hz(TRUE);
                    break;
                case HWND_MENU_SOUND_EQ_ADVANCE_1000HZ:
                    MApp_UiMenuFunc_AdjustAudio1000Hz(TRUE);
                    break;
                case HWND_MENU_SOUND_EQ_ADVANCE_2000HZ:
                    MApp_UiMenuFunc_AdjustAudio2000Hz(TRUE);
                    break;
                case HWND_MENU_SOUND_EQ_ADVANCE_4000HZ:
                    MApp_UiMenuFunc_AdjustAudio4000Hz(TRUE);
                    break;
                case HWND_MENU_SOUND_EQ_ADVANCE_BALANCE:
                    MApp_UiMenuFunc_AdjustAudioBalance(TRUE);
                    break;

                case HWND_MENU_SOUND_AUDIO_OPTION_ACCESSIBILITY:
                    MApp_UiMenuFunc_AdjustAccessibility(TRUE);
                    break;

                case HWND_MENU_SOUND_VIDEO_DESCRIPTION:
                    MApp_UiMenuFunc_SelectVideoDescription();
                    break;

                case HWND_MENU_SOUND_AUDIO_OPTION_LANGUAGE:
                case HWND_MENU_SOUND_AUDIO_LANGUAGE:
                    MApp_UiMenuFunc_AdjustAudioLanguage(TRUE);
                    break;

                case HWND_MENU_SOUND_PRIMARY_PARAMETER:
                    MApp_UiMenuFunc_AdjustPrimartAudioPmt(TRUE);
                    break;

            #endif//ENABLE_ATSC_MAIN_MENU_SOUND_PAGE
            //end case EN_INC_VALUE

            #if ENABLE_ATSC_MAIN_MENU_TIME_PAGE
                case HWND_MENU_TIME_DST:
                    MApp_UiMenuFunc_AdjTimeDST(TRUE);
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_TIME_SET_CLOCK);
                    break;


                case HWND_MENU_TIME_TIME_FORMAT:
                    MApp_UiMenuFunc_AdjTimeFormat();
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_TIME_SET_CLOCK);
                    break;


                case HWND_MENU_TIME_AUTO_SYNC:
                    MApp_UiMenuFunc_AdjTimeAutoSync(TRUE);
                    if(stGenSetting.g_SysSetting.fTimeAutoSync == TIME_AUTO_SYNC_ON)
                    {
                        MApp_ZUI_API_EnableWindow(HWND_MENU_TIME_SET_CLOCK,FALSE);
                        MApp_ZUI_API_EnableWindow(HWND_MENU_TIME_DST,FALSE);
                    }
                    else
                    {
                        MApp_ZUI_API_EnableWindow(HWND_MENU_TIME_SET_CLOCK, TRUE);
                        MApp_ZUI_API_EnableWindow(HWND_MENU_TIME_DST, TRUE);
                    }
                    break;
            #endif//ENABLE_ATSC_MAIN_MENU_TIME_PAGE

            #if ENABLE_ATSC_MENU_LOCK_UI
              #if ENABLE_INPUT_LOCK
                case HWND_MENU_LOCK_INPUTBLOCKSUBPAGE_ITEM_TV:
                    MApp_UiMenuFunc_AdjustInputLockTV();
                    break;
                case HWND_MENU_LOCK_INPUTBLOCKSUBPAGE_ITEM_AV:
                    MApp_UiMenuFunc_AdjustInputLockAV();
                    break;
                case HWND_MENU_LOCK_INPUTBLOCKSUBPAGE_ITEM_SVIDEO:
                    MApp_UiMenuFunc_AdjustInputLockSV();
                    break;
                case HWND_MENU_LOCK_INPUTBLOCKSUBPAGE_ITEM_COMPONENT:
                    MApp_UiMenuFunc_AdjustInputLockYPbPr();
                    break;
                case HWND_MENU_LOCK_INPUTBLOCKSUBPAGE_ITEM_HDMI:
                    MApp_UiMenuFunc_AdjustInputLockHDMI();
                    break;
                case HWND_MENU_LOCK_INPUTBLOCKSUBPAGE_ITEM_PC:
                    MApp_UiMenuFunc_AdjustInputLockPC();
                    break;
              #endif

                case HWND_MENU_LOCK_MAINSUBPAGE_ITEM_SYSTEMLOCK:
                    MApp_UiMenuFunc_AdjSystemLockMode();
                    //MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_MAINSUBPAGE, SW_HIDE);
                    //MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_MAINSUBPAGE, SW_SHOW);
                    MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_MAINSUBPAGE_ITEM_SYSTEMLOCK);
                    //MApp_ZUI_CTL_DynamicListRefreshContent(HWND_MENU_LOCK_MAINSUBPAGE);
                    break;
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM0:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM1:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM2:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM3:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM4:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM5:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM6:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM7:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM8:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM9:
                {
                    U8 u8tmp;
                    // Get current hwnd
                    for(u8tmp=0; u8tmp<MAX_NUM_OF_RRT_ITEM; u8tmp++)
                    {
                        if(hwnd==_MenuRRTAdjPageHwndList[u8tmp])
                        {
                            break;
                        }
                    }
                    if(g_u8CurrentRRT_1stOption+u8tmp==0)
                    {
                        // ALL
                        switch(MApp_ZUI_ACT_MainMenuCurDimRRTIsAllRating(g_u8CurrentRRT_Dimension))
                        {
                            default:
                            case TRUE:
                                // Set all false
                                stGenSettingVchipRegion5.stRegin5Dimension[g_u8CurrentRRT_Dimension].u32CurrentOption = 0;
                                break;
                            case FALSE:
                                // Set all true
                                stGenSettingVchipRegion5.stRegin5Dimension[g_u8CurrentRRT_Dimension].u32CurrentOption |= 0x3FFF;
                                break;
                        }
                        MApp_UiMenuFunc_VChip_CompareRating();
                        MApp_UiMenuFunc_SaveCurrentRegion5Ratings();
                        MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_RRTADJUSTSUBPAGE);
                    }
                    else if(g_u8CurrentRRT_1stOption+u8tmp+1>RRT_ITEM_NUM_IN_CUR_DIM)
                    {
                        // Exceed list number
                        break;
                    }
                    else
                    {
                        MApp_UiMenuFunc_VChip_CompareRating();
                        MApp_UiMenuFunc_ToggleRRT_DimensionValues(g_u8CurrentRRT_1stOption+u8tmp);// -1: ALL
                        MApp_UiMenuFunc_SaveCurrentRegion5Ratings();
                        MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_RRTADJUSTSUBPAGE);
                    }
                }
                break;

                case HWND_MENU_LOCK_MAINSUBPAGE_ITEM_UNRATED:
                    MApp_UiMenuFunc_AdjUnRatedLockMode();
                    //MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_MAINSUBPAGE, SW_HIDE);
                    //MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_MAINSUBPAGE_ITEM_SYSTEMLOCK, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_MAINSUBPAGE_ITEM_INPUTBLOCK, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_MAINSUBPAGE_ITEM_US, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_MAINSUBPAGE_ITEM_CANADA, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_MAINSUBPAGE_ITEM_RESETRRT, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_MAINSUBPAGE_ITEM_RRTSETTING, SW_HIDE);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_MAINSUBPAGE_ITEM_UNRATED, SW_HIDE);
                    //MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_MAINSUBPAGE, SW_SHOW);
                    //MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_MAINSUBPAGE_ITEM_SYSTEMLOCK, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_MAINSUBPAGE_ITEM_INPUTBLOCK, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_MAINSUBPAGE_ITEM_US, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_MAINSUBPAGE_ITEM_CANADA, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_MAINSUBPAGE_ITEM_RESETRRT, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_MAINSUBPAGE_ITEM_RRTSETTING, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_MAINSUBPAGE_ITEM_UNRATED, SW_SHOW);

                    MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_MAINSUBPAGE_ITEM_UNRATED);
                    //MApp_ZUI_CTL_DynamicListRefreshContent(HWND_MENU_LOCK_MAINSUBPAGE);
                    break;
            #endif

                case HWND_MENU_OPTION_CCOPTION_ITEM_FONTSTYLE:
                    MApp_UiMenuFunc_AdjustCCFontStyle(TRUE);
                    break;
                case HWND_MENU_OPTION_CCOPTION_ITEM_FONTSIZE:
                    MApp_UiMenuFunc_AdjustCCFontSize(TRUE);
                    break;
                case HWND_MENU_OPTION_CCOPTION_ITEM_FONTEDGESTYLE:
                    MApp_UiMenuFunc_AdjustCCFontEdgeStyle(TRUE);
                    break;
                case HWND_MENU_OPTION_CCOPTION_ITEM_FONTEDGECOLOR:
                    MApp_UiMenuFunc_AdjustCCFontEdgeColor(TRUE);
                    break;
                case HWND_MENU_OPTION_CCOPTION_ITEM_FGCOLOR:
                    MApp_UiMenuFunc_AdjustCCFGColor(TRUE);
                    break;
                case HWND_MENU_OPTION_CCOPTION_ITEM_BGCOLOR:
                    MApp_UiMenuFunc_AdjustCCBGColor(TRUE);
                    break;
                case HWND_MENU_OPTION_CCOPTION_ITEM_FGOPACITY:
                    MApp_UiMenuFunc_AdjustCCFGOpacity(TRUE);
                    break;
                case HWND_MENU_OPTION_CCOPTION_ITEM_BGOPACITY:
                    MApp_UiMenuFunc_AdjustCCBGOpacity(TRUE);
                    break;
                case HWND_MENU_OPTION_CCOPTION_ITEM_WINDOWCOLOR:
                    MApp_UiMenuFunc_AdjustCCWindowColor(TRUE);
                    break;
                case HWND_MENU_OPTION_CCOPTION_ITEM_WINDOWOPACITY:
                    MApp_UiMenuFunc_AdjustCCWindowOpacity(TRUE);
                    break;
                default:
                    break;
            }
            MApp_ZUI_API_InvalidateAllSuccessors(hwnd);
            return TRUE;
        }//case EN_EXE_INC_VALUE
                break;


        case EN_EXE_DEC_VALUE:
        {
            HWND hwnd;
            hwnd = MApp_ZUI_API_GetFocus();
            switch(hwnd)
            {
            #if ENABLE_ATSC_MAIN_MENU_CHANNEL_PAGE

                case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR1:
                  #if ATSC_READY
                    MApp_UiMenuFunc_ProNameEdit_AdjustChar(FALSE,0);
                  #endif
                    break;

                case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR2:
                  #if ATSC_READY
                    MApp_UiMenuFunc_ProNameEdit_AdjustChar(FALSE,1);
                  #endif
                    break;

                case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR3:
                  #if ATSC_READY
                    MApp_UiMenuFunc_ProNameEdit_AdjustChar(FALSE,2);
                  #endif
                    break;

                case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR4:
                  #if ATSC_READY
                    MApp_UiMenuFunc_ProNameEdit_AdjustChar(FALSE,3);
                  #endif
                    break;

                case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR5:
                  #if ATSC_READY
                    MApp_UiMenuFunc_ProNameEdit_AdjustChar(FALSE,4);
                  #endif
                    break;

                case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR6:
                  #if ATSC_READY
                    MApp_UiMenuFunc_ProNameEdit_AdjustChar(FALSE,5);
                  #endif
                    break;

                case HWND_MENU_CHANNEL_LABEL_EDIT_CHAR7:
                  #if ATSC_READY
                    MApp_UiMenuFunc_ProNameEdit_AdjustChar(FALSE,6);
                  #endif
                    break;

            #endif//ENABLE_ATSC_MAIN_MENU_CHANNEL_PAGE
	
        #if ENABLE_ATSC_MAIN_MENU_PICTURE_PAGE
            case HWND_MENU_PICTURE_ADJUST_BACKLIGHT_SUB:
              //#if ATSC_READY
                MApp_UiMenuFunc_AdjustBacklightPWM(FALSE);
              //#endif
                break;
        #endif//ENABLE_ATSC_MAIN_MENU_PICTURE_PAGE
        #if ENABLE_ATSC_MAIN_MENU_SOUND_PAGE
                case HWND_MENU_SOUND_EQ_EQUALIZER:
                    MApp_UiMenuFunc_AdjAudioMode(FALSE);
                    if(stGenSetting.g_SoundSetting.SoundMode==SOUND_MODE_USER)
                    {
                        MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_EQ_ADVANCE_SUBPAGE_ITEMS_UP_ARROW,SW_SHOW);
                        MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_EQ_ADVANCE_SUBPAGE_ITEMS_DOWN_ARROW,SW_SHOW);
                    }
                    else
                    {
                        MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_EQ_ADVANCE_SUBPAGE_ITEMS_UP_ARROW,SW_HIDE);
                        MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_EQ_ADVANCE_SUBPAGE_ITEMS_DOWN_ARROW,SW_HIDE);
                    }
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_SOUND_EQ_ADVANCE_SUBPAGE_ITEMS);
                    MApp_ZUI_CTL_DynamicListRefreshContent(HWND_MENU_SOUND_EQ_ADVANCE_LIST);
                    break;
                case HWND_MENU_SOUND_EQ_ADVANCE_150HZ:
                    MApp_UiMenuFunc_AdjustAudio150Hz(FALSE);
                    break;
                case HWND_MENU_SOUND_EQ_ADVANCE_500HZ:
                    MApp_UiMenuFunc_AdjustAudio500Hz(FALSE);
                    break;
                case HWND_MENU_SOUND_EQ_ADVANCE_1000HZ:
                    MApp_UiMenuFunc_AdjustAudio1000Hz(FALSE);
                    break;
                case HWND_MENU_SOUND_EQ_ADVANCE_2000HZ:
                    MApp_UiMenuFunc_AdjustAudio2000Hz(FALSE);
                    break;
                case HWND_MENU_SOUND_EQ_ADVANCE_4000HZ:
                    MApp_UiMenuFunc_AdjustAudio4000Hz(FALSE);
                    break;
                case HWND_MENU_SOUND_EQ_ADVANCE_BALANCE:
                    MApp_UiMenuFunc_AdjustAudioBalance(FALSE);
                    break;

#if 0
                case HWND_MENU_SOUND_AUDIO_OPTION_ACCESSIBILITY:
                {
                    MApp_UiMenuFunc_AdjustAccessibility(FALSE);
                    if(stGenSetting.g_SoundSetting.enSoundDigitalSelect != SOUND_AUDIO_DIGITAL_DEFAULT)
                    {
                        U8 u8PreAudSel = g_u8AudLangSelected;
                        u16AudioPID = MApp_SetPreferAudioSoundTrackPIDNew();

                        if(u8PreAudSel != g_u8AudLangSelected)
                        {
                            MApp_Aud_SetMtsMode();
                        }
                    }
                }
                break;

                case HWND_MENU_SOUND_AUDIO_OPTION_LANGUAGE:
                    MApp_UiMenuFunc_AdjustAudioLanguage(FALSE);
                    if(stGenSetting.g_SoundSetting.enSoundDigitalSelect != SOUND_AUDIO_DIGITAL_DEFAULT)
                    {
                        U8 u8PreAudSel = g_u8AudLangSelected;
                        u16AudioPID = MApp_SetPreferAudioSoundTrackPIDNew();

                        if(u8PreAudSel != g_u8AudLangSelected)
                        {
                            MApp_Aud_SetMtsMode();
                        }
                    }

                    break;

                case HWND_MENU_SOUND_PRIMARY_PARAMETER:
                    MApp_UiMenuFunc_AdjustPrimartAudioPmt(FALSE);
                    if(stGenSetting.g_SoundSetting.enSoundDigitalSelect != SOUND_AUDIO_DIGITAL_DEFAULT)
                    {
                        U8 u8PreAudSel = g_u8AudLangSelected;
                        u16AudioPID = MApp_SetPreferAudioSoundTrackPIDNew();

                        if(u8PreAudSel != g_u8AudLangSelected)
                        {
                            MApp_Aud_SetMtsMode();
                        }
                    }

                    break;
#endif

#endif//ENABLE_ATSC_MAIN_MENU_SOUND_PAGE


#if ENABLE_ATSC_MENU_LOCK_UI
#if ENABLE_INPUT_LOCK
                case HWND_MENU_LOCK_INPUTBLOCKSUBPAGE_ITEM_TV:
                    MApp_UiMenuFunc_AdjustInputLockTV();
                    break;
                case HWND_MENU_LOCK_INPUTBLOCKSUBPAGE_ITEM_AV:
                    MApp_UiMenuFunc_AdjustInputLockAV();
                    break;
                case HWND_MENU_LOCK_INPUTBLOCKSUBPAGE_ITEM_SVIDEO:
                    MApp_UiMenuFunc_AdjustInputLockSV();
                    break;
                case HWND_MENU_LOCK_INPUTBLOCKSUBPAGE_ITEM_COMPONENT:
                    MApp_UiMenuFunc_AdjustInputLockYPbPr();
                    break;
                case HWND_MENU_LOCK_INPUTBLOCKSUBPAGE_ITEM_HDMI:
                    MApp_UiMenuFunc_AdjustInputLockHDMI();
                    break;
                case HWND_MENU_LOCK_INPUTBLOCKSUBPAGE_ITEM_PC:
                    MApp_UiMenuFunc_AdjustInputLockPC();
                    break;
#endif
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM0:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM1:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM2:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM3:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM4:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM5:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM6:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM7:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM8:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM9:
                {
                    U8 u8tmp;
                    // Get current hwnd
                    for(u8tmp=0; u8tmp<MAX_NUM_OF_RRT_ITEM; u8tmp++)
                    {
                        if(hwnd==_MenuRRTAdjPageHwndList[u8tmp])
                        {
                            break;
                        }
                    }
                    if(g_u8CurrentRRT_1stOption+u8tmp==0)
                    {
                        // ALL
                        switch(MApp_ZUI_ACT_MainMenuCurDimRRTIsAllRating(g_u8CurrentRRT_Dimension))
                        {
                            default:
                            case TRUE:
                                // Set all false
                                stGenSettingVchipRegion5.stRegin5Dimension[g_u8CurrentRRT_Dimension].u32CurrentOption = 0;
                                break;
                            case FALSE:
                                // Set all true
                                stGenSettingVchipRegion5.stRegin5Dimension[g_u8CurrentRRT_Dimension].u32CurrentOption |= 0x3FFF;
                                break;
                        }
                        MApp_UiMenuFunc_VChip_CompareRating(); //Mantis 950923 fixed
                        MApp_UiMenuFunc_SaveCurrentRegion5Ratings();
                        MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_RRTADJUSTSUBPAGE);
                    }
                    else if(g_u8CurrentRRT_1stOption+u8tmp+1>RRT_ITEM_NUM_IN_CUR_DIM)
                    {
                        // Exceed list number
                        break;
                    }
                    else
                    {
                        MApp_UiMenuFunc_VChip_CompareRating();//Mantis 950923 fixed
                        MApp_UiMenuFunc_ToggleRRT_DimensionValues(g_u8CurrentRRT_1stOption+u8tmp);// -1: ALL
                        MApp_UiMenuFunc_SaveCurrentRegion5Ratings();
                        MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_RRTADJUSTSUBPAGE);
                    }
                }
                break;
#endif
#if (ENABLE_ATSC)
                case HWND_MENU_OPTION_CCOPTION_ITEM_FONTSTYLE:
                    MApp_UiMenuFunc_AdjustCCFontStyle(FALSE);
                    break;
                case HWND_MENU_OPTION_CCOPTION_ITEM_FONTSIZE:
                    MApp_UiMenuFunc_AdjustCCFontSize(FALSE);
                    break;
                case HWND_MENU_OPTION_CCOPTION_ITEM_FONTEDGESTYLE:
                    MApp_UiMenuFunc_AdjustCCFontEdgeStyle(FALSE);
                    break;
                case HWND_MENU_OPTION_CCOPTION_ITEM_FONTEDGECOLOR:
                    MApp_UiMenuFunc_AdjustCCFontEdgeColor(FALSE);
                    break;
                case HWND_MENU_OPTION_CCOPTION_ITEM_FGCOLOR:
                    MApp_UiMenuFunc_AdjustCCFGColor(FALSE);
                    break;
                case HWND_MENU_OPTION_CCOPTION_ITEM_BGCOLOR:
                    MApp_UiMenuFunc_AdjustCCBGColor(FALSE);
                    break;
                case HWND_MENU_OPTION_CCOPTION_ITEM_FGOPACITY:
                    MApp_UiMenuFunc_AdjustCCFGOpacity(FALSE);
                    break;
                case HWND_MENU_OPTION_CCOPTION_ITEM_BGOPACITY:
                    MApp_UiMenuFunc_AdjustCCBGOpacity(FALSE);
                    break;
                case HWND_MENU_OPTION_CCOPTION_ITEM_WINDOWCOLOR:
                    MApp_UiMenuFunc_AdjustCCWindowColor(FALSE);
                    break;
                case HWND_MENU_OPTION_CCOPTION_ITEM_WINDOWOPACITY:
                    MApp_UiMenuFunc_AdjustCCWindowOpacity(FALSE);
                    break;
#endif
                default:
                    //
                    break;
            }
            MApp_ZUI_API_InvalidateAllSuccessors(hwnd);
            return TRUE;
        }//case EN_EXE_DEC_VALUE
                break;

            case EN_EXE_RRT_DIMENSION_UP:
                {
                    HWND hwnd;
                    hwnd = MApp_ZUI_API_GetFocus();

                    switch(hwnd)
                    {
                        case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM0:
                            {
                                if(g_u8CurrentRRT_1stDimension_Item==0)
                                {
                                    // Current page is the 1st page
                                    if(TOTAL_DIM_ITEM_NUM<=MAX_NUM_OF_DIM_ITEM)
                                    {
                                        // The Dimension number is eight or less
                                        // Set current idx to the last item
                                        g_u8CurrentRRT_Dimension = TOTAL_DIM_ITEM_NUM - 1;
                                        // No need to change the 1st item idx
                                        // Move cursor to the last item
                                        MApp_ZUI_API_SetFocus(_MenuRRTDimensionHwndList[g_u8CurrentRRT_Dimension]);
                                    }
                                    else
                                    {
                                        // The Dimension number is nine or more
                                        // Update the current and the 1st item idx
                                        g_u8CurrentRRT_Dimension = TOTAL_DIM_ITEM_NUM - 1;
                                        g_u8CurrentRRT_1stDimension_Item = TOTAL_DIM_ITEM_NUM - MAX_NUM_OF_DIM_ITEM;
                                        // Refresh the list
                                        MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE);
                                        // Move cursor to the last item
                                        MApp_ZUI_API_SetFocus(_MenuRRTDimensionHwndList[MAX_NUM_OF_DIM_ITEM-1]);
                                    }
                                }
                                else
                                {
                                    // There exist item above
                                    // Update current and the 1st item idx
                                    g_u8CurrentRRT_Dimension--;
                                    g_u8CurrentRRT_1stDimension_Item--;
                                    // Refresh the list
                                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE);
                                    // No need to move the cursor
                                }
                            }
                            break;
                        case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM1:
                        case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM2:
                        case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM3:
                        case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM4:
                        case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM5:
                        case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM6:
                        case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM7:
                        case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM8:
                        case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM9:
                            {
                                U8 u8tmp;
                                // Get current hwnd
                                for(u8tmp=0; u8tmp<MAX_NUM_OF_DIM_ITEM; u8tmp++)
                                {
                                    if(hwnd==_MenuRRTDimensionHwndList[u8tmp])
                                    {
                                        break;
                                    }
                                }
                                g_u8CurrentRRT_Dimension--;
                                // No need to refresh the list
                                // Move cursor to the previous item
                                MApp_ZUI_API_SetFocus(_MenuRRTDimensionHwndList[u8tmp-1]);
                            }
                            break;

                        default:
                            break;
                    }
                }

                break;

            case EN_EXE_RRT_DIMENSION_DOWN:
                {
                    HWND hwnd;
                    hwnd = MApp_ZUI_API_GetFocus();
                    switch(hwnd)
                    {
                        case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM0:
                        case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM1:
                        case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM2:
                        case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM3:
                        case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM4:
                        case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM5:
                        case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM6:
                        case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM7:
                        case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM8:
                            {
                                if(g_u8CurrentRRT_Dimension+1<TOTAL_DIM_ITEM_NUM)
                                {
                                    // There exist item below
                                    U8 u8tmp;
                                    // Get current hwnd
                                    for(u8tmp=0; u8tmp<MAX_NUM_OF_DIM_ITEM; u8tmp++)
                                    {
                                        if(hwnd==_MenuRRTDimensionHwndList[u8tmp])
                                        {
                                            break;
                                        }
                                    }
                                    // Update current item idx
                                    g_u8CurrentRRT_Dimension++;
                                    // No need to change the 1st item idx
                                    // No need to refresh the list
                                    // Move cursor to the next item
                                    if ((u8tmp+1) < (U8)sizeof(_MenuRRTDimensionHwndList))
                                       MApp_ZUI_API_SetFocus(_MenuRRTDimensionHwndList[u8tmp+1]);
                                }
                                else
                                {
                                    // There is no item below, move cursor to the 1st item
                                    // Update the current and the 1st item idx
                                    g_u8CurrentRRT_Dimension = 0;
                                    g_u8CurrentRRT_1stDimension_Item = 0;
                                    // No need to refresh the list, should be in the 1st page now
                                    // Move cursor to the 1st item
                                    MApp_ZUI_API_SetFocus(_MenuRRTDimensionHwndList[0]);
                                }
                            }
                            break;
                        case HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE_ITEM9:
                            {
                                if(g_u8CurrentRRT_Dimension+1<TOTAL_DIM_ITEM_NUM)
                                {
                                    // The DIM list has nine or more and the MAX item has NOT been selected.
                                    // Update current and the 1st item idx
                                    g_u8CurrentRRT_Dimension++;
                                    g_u8CurrentRRT_1stDimension_Item++;
                                    // No need to move the cursor
                                }
                                else
                                {
                                    // The DIM list has nine or more and the MAX item has been selected.
                                    // Update current and the 1st item idx
                                    g_u8CurrentRRT_Dimension = 0;
                                    g_u8CurrentRRT_1stDimension_Item = 0;
                                    // Move cursor to the 1st item
                                    MApp_ZUI_API_SetFocus(_MenuRRTDimensionHwndList[0]);
                                }
                                // Refresh the list
                                MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_RRTDIMENTIONSUBPAGE);
                            }
                            break;
                        default:
                            break;

                    }
                }
                break;

        case EN_EXE_RRTADJUST_UP:
            {
                    HWND hwnd;
                printf("EN_EXE_RRTADJUST_UP\n");
                    hwnd = MApp_ZUI_API_GetFocus();
                    switch(hwnd)
                    {
                        case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM0:
                        {
                            printf("HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM0\n");
                            if(g_u8CurrentRRT_1stOption==0)
                            {
                                // Current page is the 1st page
                                printf("RRT_ITEM_NUM_IN_CUR_DIM = %d\n", RRT_ITEM_NUM_IN_CUR_DIM);
                                if(RRT_ITEM_NUM_IN_CUR_DIM <= MAX_NUM_OF_RRT_ITEM)
                                {
                                    // The RRT items in current dimension are 10 or less
                                    // Set current idx to the last item
                                    g_u8CurrentRRT_Option = RRT_ITEM_NUM_IN_CUR_DIM - 1;
                                    // No need to change 1st item idx
                                    // Move cursor to the last item in this(1st) page
                                    MApp_ZUI_API_SetFocus(_MenuRRTAdjPageHwndList[g_u8CurrentRRT_Option]);
                                }
                                else
                                {
                                    // The RRT iems in current dimension are nine or more
                                    // Update the current and the 1st item idx
                                    g_u8CurrentRRT_Option = RRT_ITEM_NUM_IN_CUR_DIM - 1;
                                    g_u8CurrentRRT_1stOption = RRT_ITEM_NUM_IN_CUR_DIM - MAX_NUM_OF_RRT_ITEM;
                                    // Refresh the list
                                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_RRTADJUSTSUBPAGE_LIST);
                                    // Move cursor to the last item
                                    MApp_ZUI_API_SetFocus(_MenuRRTAdjPageHwndList[MAX_NUM_OF_RRT_ITEM-1]);
                                }
                            }
                            else
                            {
                                // There exist item above
                                // Update current and 1st item idx
                                g_u8CurrentRRT_Option--;
                                g_u8CurrentRRT_1stOption--;
                                // Refresh the list
                                MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_RRTADJUSTSUBPAGE_LIST);
                                // No need to move the cursor
                            }
                            break;
                        }


                        case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM1:
                        case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM2:
                        case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM3:
                        case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM4:
                        case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM5:
                        case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM6:
                        case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM7:
                        case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM8:
                        case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM9:
                        {
                            U8 u8tmp;
                            printf("HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM1~9\n");
                            // Get current hwnd
                            for(u8tmp=0; u8tmp<MAX_NUM_OF_RRT_ITEM; u8tmp++)
                            {
                                if(hwnd==_MenuRRTAdjPageHwndList[u8tmp])
                                {
                                    break;
                                }
                            }
                            g_u8CurrentRRT_Option--;
                            // No need to refresh the list
                            // Move cursor to the previous item
                            MApp_ZUI_API_SetFocus(_MenuRRTAdjPageHwndList[u8tmp-1]);

                            break;
                        }


                        default:
                            break;
                    }
                }
            break;

        case EN_EXE_RRTADJUST_DOWN:
        {
                        HWND hwnd;
            hwnd = MApp_ZUI_API_GetFocus();
            switch(hwnd)
            {
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM0:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM1:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM2:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM3:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM4:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM5:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM6:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM7:
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM8:
                    {
                        if(g_u8CurrentRRT_Option+1<RRT_ITEM_NUM_IN_CUR_DIM)
                        {
                            // There is item exists in the row below, select the next row
                            U8 u8tmp;
                            // Get current hwnd
                            for(u8tmp=0; u8tmp<MAX_NUM_OF_RRT_ITEM; u8tmp++)
                            {
                                if(hwnd==_MenuRRTAdjPageHwndList[u8tmp])
                                {
                                    break;
                                }
                            }
                            // Update current item idx
                            g_u8CurrentRRT_Option++;
                            // 1st item idx no need to change
                            // No need to refresh current list
                            // Move cursor to the next item
                            MApp_ZUI_API_SetFocus(_MenuRRTAdjPageHwndList[u8tmp+1]);
                        }
                        else
                        {
                            // There is no item below, move cursor to the 1st item
                            // Update the current and the 1st item idx
                            g_u8CurrentRRT_Option = 0;
                            g_u8CurrentRRT_1stOption = 0;
                            // No need to refresh current list
                            // Move cursor to the 1st item
                            MApp_ZUI_API_SetFocus(_MenuRRTAdjPageHwndList[0]);
                        }
                    }
                    break;
                case HWND_MENU_LOCK_RRTADJUSTSUBPAGE_ITEM9:
                    {
                        if(g_u8CurrentRRT_Option+1 < RRT_ITEM_NUM_IN_CUR_DIM)
                        {
                            // The RRT list items in current dimension are nine or more and the MAX item has NOT been selected.
                            // Set the current and 1st item idx
                            g_u8CurrentRRT_Option++;
                            g_u8CurrentRRT_1stOption++;
                            // No need to move the cursor
                        }
                        else
                        {
                            // The RRT list items in current dimension are nine or more and the MAX item has been selected.
                            // Set the current and 1st item idx
                            g_u8CurrentRRT_Option = 0;
                            g_u8CurrentRRT_1stOption = 0;
                            // Move cursor to the 1st item
                            MApp_ZUI_API_SetFocus(_MenuRRTAdjPageHwndList[0]);
                        }
                        // Refresh the list
                        MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_LOCK_RRTADJUSTSUBPAGE_LIST);
                    }
                    break;
                default:
                    break;
            }
        }
            break;

      #endif//ENABLE_ATSC_MENU_UI
    #endif

        case EN_EXE_DISPLAY_CEC_DEVICE_LIST:
        {
            if (MApp_ZUI_API_IsWindowVisible(HWND_MENU_HDMI_CEC_DEVICE_LIST_PAGE))
            {
                CEC_ZUI_DEBUG(printf("\n >> EN_EXE_DISPLAY_CEC_DEVICE_LIST \n"));
                {
                    MApp_ZUI_ACT_InitMainMenuCECDeviceList();
                    MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_HDMI_CEC_DEVICE_LIST_PAGE, SW_SHOW);
                    MApp_ZUI_API_ShowWindow(HWND_MENU_HDMI_CEC_DEVICE_SEARCHING, SW_HIDE);
                    MApp_ZUI_API_SetFocus(hdmi_cec_UI_list[0]);
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_HDMI_CEC_DEVICE_LIST_PAGE);
                }
            }
        }
        break;

        case EN_EXE_GOTO_ASPECT_RATIO_PAGE:
            _eCommonSingleMode = EN_COMMON_SINGLELIST_ASPECT_RATIO;
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            //MApp_ZUI_API_ShowWindow(HWND_MENU_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_SINGLELIST_COMMON_PAGE, SW_SHOW);
            switch(ST_VIDEO.eAspectRatio)
            {
              //Ray ART 2017.05.23: There are only Fill screen, 4:3, 16:9 and 1:1 in aspect ratio menu
              case EN_AspectRatio_JustScan:		//Fill Screen
              default:
                  MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM1);
                  break;
              case EN_AspectRatio_4X3:
                  MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM2);
                  break;
              case EN_AspectRatio_16X9:
                  MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM3);
                  break;
              case EN_AspectRatio_Point_to_Point:	//1:1
                  MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM4);
                  break;

              //Ray ART 2017.05.23: Comment original code by #if 0
#if 0
            	//#if(sSupportJustScan)
                case EN_AspectRatio_Original:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM1);
                    break;
                case EN_AspectRatio_4X3:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM2);
                    break;
                case EN_AspectRatio_16X9:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM3);
                    break;
                /*case EN_AspectRatio_14X9:
                   MApp_ZUI_API_SetFocus(HWND_MENU_SINGLELIST_ITEM4);
                   break;*/
                case EN_AspectRatio_Zoom1:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM5);
                    break;
                case EN_AspectRatio_Zoom2:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM6);
                    break;
                case EN_AspectRatio_JustScan:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM7);
                    break;
                case EN_AspectRatio_Panorama:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM8);
                    break;
                case EN_AspectRatio_Point_to_Point:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM9);
                    break;
                default:
                    MApp_ZUI_API_SetFocus(HWND_MENU_SINGLELIST_ITEM1);
                    break;            	
#endif			//Ray ART 2017.05.23: End of comment original code by #if 0

            	/*#else
                case EN_AspectRatio_Original:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM1);
                    break;
                case EN_AspectRatio_4X3:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM2);
                    break;
                case EN_AspectRatio_16X9:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM3);
                    break;
                //case EN_AspectRatio_14X9:
                //   MApp_ZUI_API_SetFocus(HWND_MENU_SINGLELIST_ITEM4);
                //   break;
                case EN_AspectRatio_Zoom1:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM5);
                    break;
                case EN_AspectRatio_Zoom2:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM6);
                    break;
                //case EN_AspectRatio_JustScan:
                //    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM7);
                //    break;
                case EN_AspectRatio_Panorama:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM7);
                    break;
                case EN_AspectRatio_Point_to_Point:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM8);
                    break;
                default:
                    MApp_ZUI_API_SetFocus(HWND_MENU_SINGLELIST_ITEM1);
                    break;
              #endif*/      
            }
            return 0;

        #if(ENABLE_SCART_SVIDEO)
        case EN_EXE_GOTO_SCART_IN_PAGE:
             _eCommonSingleMode = EN_COMMON_SINGLELIST_SCART_IN;
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            //MApp_ZUI_API_ShowWindow(HWND_MENU_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_SINGLELIST_COMMON_PAGE, SW_SHOW);
            switch(stGenSetting.g_SysSetting.fSCARTInputSel)
            {
                case EN_SCART_SEL_AV:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM1);
                    break;

                case EN_SCART_SEL_SV:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM2);
                    break;

                default:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM1);
                    break;
            }
            return 0;
        #endif

        case EN_EXE_GOTO_NOISE_REDUCTION_PAGE:
            _eCommonSingleMode = EN_COMMON_SINGLELIST_NOISE_REDUCTION;
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            //MApp_ZUI_API_ShowWindow(HWND_MENU_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_SINGLELIST_COMMON_PAGE, SW_SHOW);
            switch(MApp_MenuFunc_Video_NOISE_REDUCTION_Get())
            {
                case MS_NR_OFF:
                   MApp_ZUI_API_SetFocus(HWND_MENU_SINGLELIST_ITEM1);
                   break;
                case MS_NR_LOW:
                   MApp_ZUI_API_SetFocus(HWND_MENU_SINGLELIST_ITEM2);
                   break;
                case MS_NR_MIDDLE:
                   MApp_ZUI_API_SetFocus(HWND_MENU_SINGLELIST_ITEM3);
                   break;
                case MS_NR_HIGH:
                   MApp_ZUI_API_SetFocus(HWND_MENU_SINGLELIST_ITEM4);
                   break;
                case MS_NR_DEFAULT:
                   MApp_ZUI_API_SetFocus(HWND_MENU_SINGLELIST_ITEM5);
                   break;
                default:
                   MApp_ZUI_API_SetFocus(HWND_MENU_SINGLELIST_ITEM1);
                   break;
            }
            return 0;

        case EN_EXE_GOTO_MPEG_NOISE_REDUCTION_PAGE:
            _eCommonSingleMode = EN_COMMON_SINGLELIST_MPEG_NOISE_REDUCTION;
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            //MApp_ZUI_API_ShowWindow(HWND_MENU_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_SINGLELIST_COMMON_PAGE, SW_SHOW);
            switch(MApp_MenuFunc_Get_MPEG_NOISE_REDUCTION_Setting())
            {
                case MS_MPEG_NR_OFF:
                   MApp_ZUI_API_SetFocus(HWND_MENU_SINGLELIST_ITEM1);
                   break;
                case MS_MPEG_NR_LOW:
                   MApp_ZUI_API_SetFocus(HWND_MENU_SINGLELIST_ITEM2);
                   break;
                case MS_MPEG_NR_MIDDLE:
                   MApp_ZUI_API_SetFocus(HWND_MENU_SINGLELIST_ITEM3);
                   break;
                case MS_MPEG_NR_HIGH:
                   MApp_ZUI_API_SetFocus(HWND_MENU_SINGLELIST_ITEM4);
                   break;
                case MS_MPEG_NR_DEFAULT:
                   MApp_ZUI_API_SetFocus(HWND_MENU_SINGLELIST_ITEM5);
                   break;
                default:
                   MApp_ZUI_API_SetFocus(HWND_MENU_SINGLELIST_ITEM1);
                   break;
            }
            return 0;

        case EN_EXE_GOTO_SURROUND_SOUND_PAGE:
            _eCommonSingleMode = EN_COMMON_SINGLELIST_SURROUND_SOUND;
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            //MApp_ZUI_API_ShowWindow(HWND_MENU_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_SINGLELIST_COMMON_PAGE, SW_SHOW);
            switch(stGenSetting.g_SoundSetting.SurroundSoundMode & SURROUND_SYSTEM_TYPE_MASK)
            {
                case SURROUND_SYSTEM_OFF:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM1);
                   break;
                #if (ENABLE_AUDIO_SURROUND_BBE  == ENABLE )
                case SURROUND_SYSTEM_BBE:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM2);
                   break;
                #endif

                #if (ENABLE_AUDIO_SURROUND_SRS  == ENABLE )
                case SURROUND_SYSTEM_SRS:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM3);
                   break;
                #endif

                #if (ENABLE_AUDIO_SURROUND_VDS  == ENABLE )
                case SURROUND_SYSTEM_VDS:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM4);
                   break;
                #endif

                #if (ENABLE_AUDIO_SURROUND_VSPK == ENABLE )
                case SURROUND_SYSTEM_VSPK:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM5);
                   break;
                #endif

                case SURROUND_SYSTEM_SURROUNDMAX:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM6);
                   break;
                #if (ENABLE_AUDIO_SURROUND_DBX  == ENABLE )
                   case SURROUND_SYSTEM_DBX:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM7);
                   break;
                #endif

                default:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM1);
                   break;
            }
            return 0;

        case EN_EXE_GOTO_TV_SPEAKER_SOUND_PAGE:
            _eCommonSingleMode = EN_COMMON_SINGLELIST_TV_SPEAKER;
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            //MApp_ZUI_API_ShowWindow(HWND_MENU_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_SINGLELIST_COMMON_PAGE, SW_SHOW);
            switch(stGenSetting.g_SoundSetting.TVspeakerMode)
            {
                default:
                case TVspeaker_Mode_IntSpeaker:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM1);
                   break;
                case TVspeaker_Mode_ExtAmp:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM2);
                   break;
            }
            return 0;

        case EN_EXE_GOTO_SLEEP_TIMER_PAGE:
            _eCommonSingleMode = EN_COMMON_SINGLELIST_SLEEP_TIMER;
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            //MApp_ZUI_API_ShowWindow(HWND_MENU_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TIME_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_SINGLELIST_COMMON_PAGE, SW_SHOW);
            switch(MApp_Sleep_GetCurrentSleepState())
            {
                case STATE_SLEEP_OFF:
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM1);
                   break;
                case STATE_SLEEP_10MIN:
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM2);
                   break;
                case STATE_SLEEP_20MIN:
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM3);
                   break;
                case STATE_SLEEP_30MIN:
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM4);
                   break;
                case STATE_SLEEP_60MIN:
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM5);
                   break;
                case STATE_SLEEP_90MIN:
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM6);
                   break;
                case STATE_SLEEP_120MIN:
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM7);
                   break;
                case STATE_SLEEP_180MIN:
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM8);
                   break;
                case STATE_SLEEP_240MIN:
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM9);
                   break;

                default:
                   MApp_ZUI_API_SetFocus(HWND_MENU_SINGLELIST_ITEM1);
                   break;
            }
            return 0;

        case EN_EXE_GOTO_AUTOSLEEP_TIMER_PAGE:
            _eCommonSingleMode = EN_COMMON_SINGLELIST_AUTOSLEEP_TIMER;
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            //MApp_ZUI_API_ShowWindow(HWND_MENU_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TIME_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_SINGLELIST_COMMON_PAGE, SW_SHOW);

        #if( ENABLE_NO_OPERATE_AUTO_SLEEP )
            switch(MApp_NoOperateAutoSleep_Get_AutoSleepTime())
            {
               case STATE_AUTOSLEEP_NEVER:
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM1);
                   break;

               case STATE_AUTOSLEEP_4HOUR:
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM2);
                   break;

               case STATE_AUTOSLEEP_6HOUR:
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM3);
                   break;

               case STATE_AUTOSLEEP_8HOUR:
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM4);
                   break;

               default:
                   MApp_ZUI_API_SetFocus(HWND_MENU_SINGLELIST_ITEM1);
                   break;
            }
        #endif
            return 0;

        case EN_EXE_GOTO_PARENTAL_GUIDANCE_PAGE:
            _eCommonSingleMode = EN_COMMON_SINGLELIST_PARENTAL_GUIDANCE;
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            //MApp_ZUI_API_ShowWindow(HWND_MENU_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_SINGLELIST_COMMON_PAGE, SW_SHOW);
            if (stGenSetting.g_BlockSysSetting.u8ParentalControl <= EN_F4_ParentalControl_Off)
            {
                MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM1);
                return 0;
            }

            switch(stGenSetting.g_BlockSysSetting.u8ParentalControl)
            {
                case 4:
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM2);
                   break;
                case 5:
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM3);
                   break;
                case 6:
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM4);
                   break;
                case 7:
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM5);
                   break;
                case 8:
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM6);
                   break;
                case 9:
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM7);
                   break;
                case 10:
                #if ENABLE_SBTVD_BRAZIL_APP
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM2);
                #else
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM8);
                #endif
                   break;
                case 11:
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM9);
                   break;
                case 12:
                #if ENABLE_SBTVD_BRAZIL_APP
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM3);
                #else
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM10);
                #endif
                   break;
                case 13:
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM11);
                   break;
                case 14:
                #if ENABLE_SBTVD_BRAZIL_APP
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM4);
                #else
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM12);
                #endif
                   break;
                case 15:
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM13);
                   break;
                case 16:
                #if ENABLE_SBTVD_BRAZIL_APP
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM5);
                #else
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM14);
                #endif
                   break;
                case 17:
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM15);
                   break;
                case 18:
                #if ENABLE_SBTVD_BRAZIL_APP
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM6);
                #else
                   MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM16);
                #endif
                   break;

                default:
                   MApp_ZUI_API_SetFocus(HWND_MENU_SINGLELIST_ITEM1);
                   break;
            }
            return 0;

        case EN_EXE_EXECUTE_APP:
            {
            		//printf("MingYuan enTopState = %d \n",MApp_TopStateMachine_GetTopState());
            		//printf("MingYuan enMainMenuState = %d \n",enMainMenuState);
            		//printf("MingYuan MApp_ZUI_GetActiveOSD() = %d \n",MApp_ZUI_GetActiveOSD());
            		//printf("MingYuan MApp_ZUI_API_GetFocus() = %d \n",MApp_ZUI_API_GetFocus());
            		
                HWND hwnd;
                hwnd = MApp_ZUI_API_GetFocus();
                printf("\nRay EXECUTE APP focus:%d",hwnd);	//Ray DBG 2017.03.01
                if ( hwnd == HWND_INVALID )
                    return FALSE;

            		//printf("MingYuan hwnd = %d \n",hwnd);
            		
            #if ENABLE_PVR
                if ( IsDTVInUse() )
                {
                    if(MApp_PVR_IsRecording())
                    {
                        MS_DEBUG_MSG(printf("\r\n PVR is recording...."));
                        if( MApp_PVR_IsPlaybacking())
                            MApp_UiPvr_PlaybackStop();

                        if( MApp_PVR_IsRecording() )
                            MApp_UiPvr_RecordStop();
                        #if 0
                        //Can add one message page at this place
                        MApp_ZUI_API_ShowWindow(HWND_PVR_APP_CHANGE_CHECK_PANE, SW_SHOW);
                        MApp_ZUI_API_SetFocus(HWND_PVR_APP_CHANGE_CHECK_TXT_2);
                        #endif

                    }
                }
            #endif // ENABLE_PVR

                MApp_ZUI_ACT_ExecuteInputSourceAction(EN_EXE_SWITCH_INPUTSOURCE);
                MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_CLOSE, E_ZUI_STATE_TERMINATE);
                switch(MApp_ZUI_API_GetFocus())
                {
                  #if ENABLE_DMP
                   case HWND_MENU_APP_DMP:
                        MS_DEBUG_MSG(printf("APP [DMP]\n"));
                        printf("\nAPP [DMP]\n");		//Ray DBG 2017.03.01
                        _enTargetMenuState = STATE_MENU_GOTO_DMP;
                        MApp_OSDPage_SetOSDPage(E_OSD_DMP);
                        break;
                  #endif

#if 0
                  #ifdef ENABLE_BT
                       case en_str_BT:
                                _enTargetMenuState = STATE_MENU_GOTO_BT;
                                break;
                  #endif
                  #ifdef ENABLE_YOUTUBE
                       case en_str_YOUTUBE:
                                _enTargetMenuState = STATE_MENU_GOTO_YOUTUBE;
                                break;
                  #endif
                  #ifdef ENABLE_RSS
                       case en_str_RSS:
                                _enTargetMenuState = STATE_MENU_GOTO_RSS;
                                break;
                  #endif
           //       #ifdef ENABLE_NETFLIX
           //            case en_str_Netflix:
           //                     _enTargetMenuState = STATE_MENU_GOTO_NETFLIX;
           //                     break;
           //       #endif
                       case en_str_GYM:
                                break;
                  #ifdef ENABLE_KTV
                       case en_str_KTV:
                                _enTargetMenuState = STATE_MENU_GOTO_KTV;
                                break;
                  #endif
                       case en_str_Plug_In:
                                break;
                  #ifdef ENABLE_GAME
                       case en_str_Game:
                                _enTargetMenuState = STATE_MENU_GOTO_GAME;
                                break;
                  #endif
                  #ifdef ENABLE_EXTENSION
                       case en_str_EXTENSION:
                                _enTargetMenuState = STATE_MENU_GOTO_EXTENSION;
                                break;
                  #endif
#endif
                    default:
                        break;
                }

                #if 0 //enable this if you want to hide main menu
                MApp_ZUI_API_ShowWindow(HWND_MENU_APP_PAGE, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_MENU_BACKGROUND, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
                #endif
            }
            return TRUE;

        case EN_EXE_GOTO_MAIN_MENU:
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_SHOW);
            //MApp_ZUI_API_ShowWindow(HWND_MENU_PAGE_INDICATOR_UP, SW_HIDE);
            //MApp_ZUI_API_SetFocus(HWND_MENU_TOP_ICON_CHANNEL);
            MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE, SW_SHOW);
            return TRUE;

        case EN_EXE_GOTO_BLOCK_PROGRAM:
            MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_CLOSE, E_ZUI_STATE_TERMINATE);
            MApp_ProgramEdit_SetMode(MODE_PREDIT_BLOCK);
            _enTargetMenuState = STATE_MENU_GOTO_OSDPAGE;
            MApp_OSDPage_SetOSDPage(E_OSD_PROGRAM_EDIT);
            return TRUE;

        case EN_EXE_GOTO_PROGRAMEDIT:
            MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_CLOSE, E_ZUI_STATE_TERMINATE);
            MApp_ProgramEdit_SetMode(MODE_PREDIT_NORMAL);
            _enTargetMenuState = STATE_MENU_GOTO_OSDPAGE;
            MApp_OSDPage_SetOSDPage(E_OSD_PROGRAM_EDIT);
            return TRUE;

        case EN_EXE_CLOSE_CURRENT_OSD:
            //printf("MingYuan MainPage EN_EXE_CLOSE_CURRENT_OSD \n");
            if (MApp_ZUI_API_IsSuccessor(HWND_MENU_DLG_TUNE_CONFIRM, MApp_ZUI_API_GetFocus()))
            {
                MApp_ZUI_ACT_ExecuteTuningConfirmDialogAction(EN_EXE_CLOSE_TUNING_CONFIRM);
                //printf("MingYuan MainPage MApp_ZUI_ACT_ExecuteTuningConfirmDialogAction(EN_EXE_CLOSE_TUNING_CONFIRM) \n");
            }
            else if (MApp_ZUI_API_IsSuccessor(HWND_MENU_DLG_COMMON, MApp_ZUI_API_GetFocus()))
            {
                MApp_ZUI_ACT_ExecuteMenuCommonDialogAction(EN_EXE_CLOSE_CURRENT_OSD);
                //printf("MingYuan MainPage MApp_ZUI_ACT_ExecuteMenuCommonDialogAction(EN_EXE_CLOSE_CURRENT_OSD) \n");
            }
            else if (MApp_ZUI_API_IsSuccessor(HWND_MENU_COMMON_ADJ_PAGE, MApp_ZUI_API_GetFocus()))
            {
                if(g_mainpage_common == EN_COMMON_OFFTIMER_PAGE)
                {
                    MApp_ZUI_ACT_ExecuteSetOffTimeDialogAction(EN_EXE_CLOSE_SET_OFFTIME);
                    //printf("MingYuan MainPage MApp_ZUI_ACT_ExecuteSetOffTimeDialogAction(EN_EXE_CLOSE_SET_OFFTIME) \n");
                }
                else if(g_mainpage_common == EN_COMMON_ONTIMER_PAGE)
                {
                    MApp_ZUI_ACT_ExecuteSetOnTimeDialogAction(EN_EXE_CLOSE_SET_ONTIME);
                    //printf("MingYuan MainPage MApp_ZUI_ACT_ExecuteSetOffTimeDialogAction(EN_EXE_CLOSE_SET_OFFTIME) \n");
                }    
                MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_CLOSE, E_ZUI_STATE_TERMINATE);
								_enTargetMenuState = STATE_MENU_CLEAN_UP;								
            }
            //else if (MApp_ZUI_API_IsSuccessor(HWND_MENU_TIME_ONTIME_PAGE, MApp_ZUI_API_GetFocus()))
           //     MApp_ZUI_ACT_ExecuteSetOnTimeDialogAction(EN_EXE_CLOSE_SET_ONTIME);
#if 0//ENABLE_T_C_COMBO
            else if(MApp_ZUI_API_IsSuccessor(HWND_MENU_DLG_DVB_SELECT_MENU, MApp_ZUI_API_GetFocus()))
                MApp_ZUI_ACT_ExecuteTuningConfirmDialogAction(EN_EXE_CLOSE_DVB_SELECT);
#endif
            else
            {
            		//printf("MingYuan MainPage MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_CLOSE, E_ZUI_STATE_TERMINATE) \n");
                MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_CLOSE, E_ZUI_STATE_TERMINATE);
                #if ENABLE_DMP
                //printf("%d %d\n",UI_INPUT_SOURCE_TYPE, MApp_DMP_GetDMPStat());
                if(UI_INPUT_SOURCE_DMP == UI_INPUT_SOURCE_TYPE
                &&(( MApp_DMP_GetDMPStat() == DMP_STATE_RETURN_FROM_MENU)
                     ||( MApp_DMP_GetDMPStat() == DMP_STATE_GOTO_PREV_SRC)))
                {
                    _enTargetMenuState = STATE_MENU_GOTO_DMP;
                }
                else
                #endif
                           _enTargetMenuState = STATE_MENU_CLEAN_UP;
            }
            return TRUE;

        case EN_EXE_POWEROFF:
            MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_CLOSE, E_ZUI_STATE_TERMINATE);
            _enTargetMenuState = STATE_MENU_GOTO_STANDBY;
            return TRUE;

        case EN_EXE_GOTO_ATV_TUNING_INPUT_PASSWORD_DLG:
            if(MApp_FuncExec_Mainpage(EN_FUNC_MAINPAGE_GET_SYS_BLOCK_MODE, NULL, NULL) == EN_FUNC_MAINPAGE_STATUS_TRUE)
            {
                MApp_ZUI_API_StoreFocusCheckpoint();
                _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_ATV_TUNING_INPUT_PASSWORD);
            }
            else
            {
                MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_ATV_TUNING);
            }
            return TRUE;

        case EN_EXE_GOTO_ATV_TUNING:
            if(MApp_FuncExec_Mainpage(EN_FUNC_MAINPAGE_CHECK_BLOCK_PASSWORD, (void *)&PasswordInput1, NULL))
            {
                // password wrong
                _ePrevCommonDlgMode = EN_COMMON_DLG_MODE_ATV_TUNING_INPUT_PASSWORD;
                _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_WRONG_PASSWORD);
            }
            else
            {
                MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_CLOSE, E_ZUI_STATE_TERMINATE);
                _enTargetMenuState = STATE_MENU_GOTO_ATV_MANUALTUNING;
            }
            return TRUE;

    #if ENABLE_DVBC
        case EN_EXE_GOTO_CADTV_TUNING_INPUT_PASSWORD_DLG:
        case EN_EXE_GOTO_CADTV_TUNING:
            MApp_FuncExec_Mainpage(EN_FUNC_MAINPAGE_SET_CADTV_TUNING, NULL, NULL);
        #if 0//ENABLE_T_C_COMBO
            bIsDVBCScan = FALSE;
        #endif
            MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_CLOSE, E_ZUI_STATE_TERMINATE);
             _enTargetMenuState = STATE_MENU_GOTO_CADTV_MANUALTUNING;
            break;
    #endif

    #if (ENABLE_DVB_TAIWAN_APP)
        case EN_EXE_SWITCH_ANTENNA_TYPE:
            if(ANT_CATV == msAPI_ATV_GetCurrentAntenna())
            {
                MApp_ATV_ChangeAntennaType(ANT_AIR);
            }
            else
            {
                MApp_ATV_ChangeAntennaType(ANT_CATV);
            }
            MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_CHANNEL_ANTENNA);
            return TRUE;
    #endif

    #if ENABLE_S2
    #if ENABLE_GOTO_DISH_SETUP_INPUT_PASSWORD
        case EN_EXE_GOTO_DISH_SETUP_INPUT_PASSWORD_DLG:
            MApp_ZUI_API_StoreFocusCheckpoint();
            _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_DISH_SETUP_INPUT_PASSWORD);
            return TRUE;
    #endif

        case EN_EXE_ENTER_DISHSETUP_KEY:
            printf("EN_EXE_ENTER_DISHSETUP_KEY start \r\n");
        #if ENABLE_GOTO_DISH_SETUP_INPUT_PASSWORD
            if( _MApp_ZUI_ACT_PasswordConvertToSystemFormat(PasswordInput1) !=
                MApp_MenuFunc_Setup_BlockSysPassWord_Get() &&
                (_MApp_ZUI_ACT_PasswordConvertToSystemFormat(PasswordInput1)  != SUPER_PASSWORD))////s2 bug 012
            {
                // password wrong
                _ePrevCommonDlgMode = EN_COMMON_DLG_MODE_DISH_SETUP_INPUT_PASSWORD;
                _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_WRONG_PASSWORD);
            }
            else
        #endif
            {
                MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_CLOSE, E_ZUI_STATE_TERMINATE);
                _enTargetMenuState = STATE_MENU_GOTO_DISHSETUP;
                printf("EN_EXE_ENTER_DISHSETUP_KEY end \r\n");
            }
            return TRUE;
    #endif

        case EN_EXE_GOTO_DTV_TUNING_INPUT_PASSWORD_DLG:
            if(MApp_FuncExec_Mainpage(EN_FUNC_MAINPAGE_GET_SYS_BLOCK_MODE, NULL, NULL) == EN_FUNC_MAINPAGE_STATUS_TRUE)
            {
                MApp_ZUI_API_StoreFocusCheckpoint();
                _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_DTV_TUNING_INPUT_PASSWORD);

            }
            else
            {
                MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_DTV_TUNING);
            }
            return TRUE;

#if(ENABLE_PVR ==1)
        case EN_EXE_GOTO_PVR_CHECK_FS:
        #if (ENABLE_UI_3D_PROCESS)
            MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_CLOSE, E_ZUI_STATE_TERMINATE);
        #else
            MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_PAGE_EXIT, E_ZUI_STATE_TERMINATE);
        #endif
            _enTargetMenuState = STATE_MENU_GOTO_PVR_CHECK_FS;
            MApp_UiPvr_CheckFS_Initial();
            return TRUE;
#endif

        case EN_EXE_GOTO_DTV_TUNING:
            MApp_FuncExec_Mainpage(EN_FUNC_MAINPAGE_SET_DTV_TUNING, NULL, NULL);
            if(MApp_FuncExec_Mainpage(EN_FUNC_MAINPAGE_CHECK_BLOCK_PASSWORD, (void *)&PasswordInput1, NULL))
            {
                // password wrong
                _ePrevCommonDlgMode = EN_COMMON_DLG_MODE_DTV_TUNING_INPUT_PASSWORD;
                _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_WRONG_PASSWORD);
            }
            else
            {
                MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_CLOSE, E_ZUI_STATE_TERMINATE);
                _enTargetMenuState = STATE_MENU_GOTO_DTV_MANUALTUNING;
            }
            return TRUE;

        case EN_EXE_GOTO_CHANNEL_SIGNAL_INFORMAT:
            {
            #if ENABLE_DTV
                WORD ModulMode = 0;
            #endif

                MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_SIGNAL_INFORMAT, SW_SHOW);
                MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
                //MApp_ZUI_API_ShowWindow(HWND_MENU_BACKGROUND, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
                MApp_ZUI_API_SetFocus(HWND_MENU_DLG_SIGNAL_INFORMAT_TITLE_TXT);

              #if ENABLE_DTV
                if (!msAPI_Tuner_GetSignalModulMode(&ModulMode))
              #endif
                    MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_SIGNAL_INFORMAT_MODULATION, SW_HIDE);
            }
            return TRUE;

        case EN_EXE_UPDATE_SIGNAL_INFORMAT:
        #if(ENABLE_S2)
            if(IsDTVInUse() || IsS2InUse())
        #else
            if(IsDTVInUse())
        #endif
            {
                static U16 u16SignalRedrawlop = 0;

                if(u16SignalRedrawlop)
                {
                    u16SignalRedrawlop--;
                    return TRUE;
                }
                u16SignalRedrawlop = 2000;

                if(MApp_ZUI_API_IsSuccessor(HWND_MENU_DLG_SIGNAL_INFORMAT, MApp_ZUI_API_GetFocus()))
                {
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_DLG_SIGNAL_INFORMAT_NETWORK_NAME);
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_DLG_SIGNAL_INFORMAT_MODULATION_NAME);

                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_DLG_SIGNAL_INFORMAT_QUALITY_PERCENT_VAL);
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_DLG_SIGNAL_INFORMAT_STRENGTH_PERCENT_VAL);
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_DLG_SIGNAL_INFORMAT_QUALITY_INDEX_STRING);
                    MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_DLG_SIGNAL_INFORMAT_STRENGTH_INDEX_STRING);
                }
            }
            return TRUE;


        case EN_EXE_GOTO_CI_INFORMATION:
    #if ENABLE_CI
             if(!msAPI_CI_CardDetect())
             {
                MApp_ZUI_API_StoreFocusCheckpoint();
                _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_CI_NO_MODULE);
                MApp_ZUI_API_SetTimer(HWND_MENU_DLG_COMMON,0,6000);
                return TRUE;
            }

            _MApp_ZUI_ACT_CheckTimeInfo();
            msAPI_CI_MMIEnterMenu();
            MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_CLOSE, E_ZUI_STATE_TERMINATE);
            _enTargetMenuState = STATE_MENU_GOTO_CIMMI;
    #endif
            return TRUE;  

        case EN_EXE_GOTO_INPUTSOURCE_PAGE:			//Ray SRC 2017.03.08: Add execution of displaying input source page when press RIGHT key in input source menu item
	     MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_SHOW_SOURCE_BANNER);
	     return TRUE;


        case EN_EXE_GOTO_PICTURE_MODE_PAGE:
            g_mainpage_common = EN_COMMON_PICTURE_MODE_PAGE;
            ST_VIDEO.ePicture = PICTURE_USER;					//Ray OSD 2017.05.17: Force to use user mode in picture setting page
            MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_PAGE, SW_HIDE);
            //MApp_ZUI_API_ShowWindow(HWND_MENU_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_COMMON_ADJ_PAGE, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_COMMON_ADJ_ITEM2);			//Ray OSD 2017.05.17: Change to focus first item in picture setting, instead of focus on picture mode title
            //MApp_ZUI_API_SetFocus(HWND_MENU_COMMON_ADJ_ITEM1);
            return TRUE;

        //Ray BKL 2017.04.25: Go to display backlight setup page
        case EN_EXE_GOTO_BKL_SETUP_PAGE:
            g_mainpage_common = EN_COMMON_BKL_SETUP_PAGE;

            MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_COMMON_ADJ_PAGE, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_COMMON_ADJ_ITEM2);			//Focus to item2 which is first menu subitem.  item1 is title
            return TRUE;

#if 0
        case EN_EXE_RETURN_PICTURE_COLOR_PAGE:
        {
            HWND _hwnd = MApp_ZUI_API_GetFocus();
            MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_ADJUST, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_COLOR_PAGE, SW_SHOW);
            switch(_hwnd)
            {
                case HWND_MENU_PIC_ADJ_TEMP_RED:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_PICTURE_COLOR_PAGE_LIST, HWND_MENU_PICCOLOR_COLOR_RED);
                    break;
                case HWND_MENU_PIC_ADJ_TEMP_GREEN:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_PICTURE_COLOR_PAGE_LIST, HWND_MENU_PICCOLOR_COLOR_GREEN);
                    break;
                case HWND_MENU_PIC_ADJ_TEMP_BLUE:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_PICTURE_COLOR_PAGE_LIST, HWND_MENU_PICCOLOR_COLOR_BLUE);
                    break;
                default:
                    break;
            }
        }
            return TRUE;

        case EN_EXE_RETURN_PICTURE_MODE_PAGE:
        {
            HWND hwnd = MApp_ZUI_API_GetFocus();
            MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_ADJUST, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_COMMON_ADJ_PAGE, SW_SHOW);
            switch(hwnd)
            {
                case HWND_MENU_PIC_ADJ_CONTRAST:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_COMMON_ADJ_PAGE_LIST, HWND_MENU_COMMON_ADJ_ITEM2);
                    break;
                case HWND_MENU_PIC_ADJ_BRIGHTNESS:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_COMMON_ADJ_PAGE_LIST, HWND_MENU_COMMON_ADJ_ITEM3);
                    break;
                case HWND_MENU_PIC_ADJ_COLOR:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_COMMON_ADJ_PAGE_LIST, HWND_MENU_COMMON_ADJ_ITEM4);
                    break;
                case HWND_MENU_PIC_ADJ_SHARPNESS:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_COMMON_ADJ_PAGE_LIST, HWND_MENU_COMMON_ADJ_ITEM5);
                    break;
                case HWND_MENU_PIC_ADJ_TINT:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_COMMON_ADJ_PAGE_LIST, HWND_MENU_COMMON_ADJ_ITEM6);
                    break;
                default:
                    break;
            }
        }
            return TRUE;
#endif
        case EN_EXE_GOTO_PICTURE_COLOR_PAGE:
            g_mainpage_common = EN_COMMON_PICTURE_COLOR_PAGE;
            MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_COMMON_ADJ_PAGE, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_COMMON_ADJ_ITEM1);

            return TRUE;

        case EN_EXE_GOTO_VOLUME_PAGE:						//Ray VOL 2017.03.08: Pressing RIGHT key in volume menu item goes to volume page
	    MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_SHOW_VOLUME_INFO);
	    //MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_PAGE, SW_HIDE);
            //MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            //MApp_ZUI_ACT_ShutdownOSD();
            //MApp_ZUI_ACT_StartupOSD(E_OSD_AUDIO_VOLUME);
            //MApp_TV_ProcessAudioVolumeKey(u8KeyCode);
            //MApp_AnalogInputs_ResetTimer(MAIN_WINDOW);
            return TRUE;

        case EN_EXE_GOTO_SOUND_MODE_PAGE:
            MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_MODE_PAGE, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_SNDMODE_SNDMODE);
            return TRUE;

        case EN_EXE_GOTO_SOUND_BALANCE_PAGE:
            g_mainpage_common = EN_COMMON_SOUND_BALANCE_PAGE;

            MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_COMMON_ADJ_PAGE, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_COMMON_ADJ_ITEM2);
            return TRUE;

        case EN_EXE_GOTO_SOUND_SPDIF_AUDIODELAY_PAGE:
            g_mainpage_common = EN_COMMON_SOUND_AUDIO_DELAY_PAGE;
            //printf("Enter OSD delay page \r\n");
            MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_COMMON_ADJ_PAGE, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_COMMON_ADJ_ITEM2);
            return TRUE;
/*
        case EN_EXE_GOTO_SOUND_EQ_PAGE:
            MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_PAGE, SW_HIDE);
            //MApp_ZUI_API_ShowWindow(HWND_MENU_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_EQ_PAGE, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_SNDEQ_120_HZ);
            return TRUE;
*/
    #if  (ATSC_CC == ATV_CC)
        case EN_EXE_GOTO_OPTION_CC_OPTION_PAGE:
            _eCommonSingleMode = EN_COMMON_SINGLELIST_CC_OPTION;
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_SINGLELIST_COMMON_PAGE, SW_SHOW);
            switch(DB_CC_SETTING.enATVCaptionType)
            {
                case ATV_CAPTION_TYPE_OFF:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM1);
                    break;
                case ATV_CAPTION_TYPE_CC1:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM2);
                    break;
                case ATV_CAPTION_TYPE_CC2:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM3);
                    break;
                case ATV_CAPTION_TYPE_CC3:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM4);
                    break;
                case ATV_CAPTION_TYPE_CC4:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM5);
                    break;
                case ATV_CAPTION_TYPE_TEXT1:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM6);
                    break;
                case ATV_CAPTION_TYPE_TEXT2:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM7);
                    break;
                case ATV_CAPTION_TYPE_TEXT3:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM8);
                    break;
                case ATV_CAPTION_TYPE_TEXT4:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM9);
                    break;
                default:
                    MApp_ZUI_API_SetFocus(HWND_MENU_SINGLELIST_ITEM1);
                    break;
            }
            return TRUE;
    #endif // #if  (ATSC_CC == ATV_CC)
#if ENABLE_ATSC_MENU_UI
#if 1//ATSC_READY
        case EN_EXE_GOTO_OPTION_CLOSED_CAPTION_PAGE:
            MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_CLOSEDCAPTION_PAGE, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_OPTION_CLOSEDCAPTION_ITEM_CCMODE);
            if(IsDTVInUse())
            {
                MApp_ZUI_API_EnableWindow(HWND_MENU_OPTION_CLOSEDCAPTION_ITEM_ADVANCESELECTION, TRUE);
                if(stGenSetting.g_CaptionSetting.u8CaptionServiceModeDTV == CAPTIONMENU_SERVICE_OFF)
                {
                    MApp_ZUI_API_EnableWindow(HWND_MENU_OPTION_CLOSEDCAPTION_ITEM_OPTION,FALSE);
                }
                else
                {
                    MApp_ZUI_API_EnableWindow(HWND_MENU_OPTION_CLOSEDCAPTION_ITEM_OPTION, TRUE);
                }
            }
            else
            {
                MApp_ZUI_API_EnableWindow(HWND_MENU_OPTION_CLOSEDCAPTION_ITEM_ADVANCESELECTION, FALSE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_OPTION_CLOSEDCAPTION_ITEM_OPTION, FALSE);
            }
            break;
#endif
#endif
        case EN_EXE_GOTO_SOUND_SWITCH_PAGE:
            g_mainpage_common = EN_COMMON_SOUND_SWITCH_PAGE;
            MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_PAGE, SW_HIDE);
            //MApp_ZUI_API_ShowWindow(HWND_MENU_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            //MApp_ZUI_API_ShowWindow(HWND_MENU_SOUND_SWITCH_PAGE, SW_SHOW);
            //MApp_ZUI_API_SetFocus(HWND_MENU_SOUND_SWITCH_AD_SWITCH);
            MApp_ZUI_API_ShowWindow(HWND_MENU_COMMON_ADJ_PAGE, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_COMMON_ADJ_ITEM1);

            return TRUE;

        case EN_EXE_GOTO_PC_ADJUST:
            MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_PCMODE_PAGE, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_PCMODE_AUTO_ADJUST);
            return TRUE;

        case EN_EXE_GOTO_VGA_SETUP:					//Ray VGA 2017.03.10: Press RIGHT key to enter into VGA setup menu
	    PicAutoColorGainResult = 2;					//Ray VGA 2017.05.25: Preset auto color result as "Not done any color gain process"
            MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_PAGE, SW_HIDE);	//Ray VGA 2017.04.12: VGA is changed to Picture menu
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_PCMODE_PAGE, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_PCMODE_HPOS);		//Ray VGA 2017.04.13: First item is changed to HPOS
            //MApp_ZUI_API_SetFocus(HWND_MENU_PCMODE_AUTO_ADJUST);
            return TRUE;

        #if (ENABLE_PIP)
        case EN_EXE_GOTO_PIP:
            if(IsPIPSupported())
            {
                MApp_ZUI_API_ShowWindow(HWND_MENU_PICTURE_PAGE, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
                MApp_ZUI_API_ShowWindow(HWND_MENU_PIP_PAGE, SW_SHOW);
                MApp_ZUI_API_SetFocus(HWND_MENU_PIP_PIPMODE);
                return TRUE;
            }
            return FALSE;
        #endif

    #if (ENABLE_OAD)//wait to do
        case EN_EXE_GOTO_OAD_SCAN:
            eTuneType = OSD_TUNE_TYPE_DTV_ONLY;
            bShowOadScanPage = TRUE;
            MApp_OAD_Set_OadScanCheck();
            MApp_ZUI_ACT_SetTuningCountry(OSD_COUNTRY_SETTING);
    #endif

        case EN_EXE_GOTO_AUTO_TUNING:
            {
                if(MApp_FuncExec_Mainpage(EN_FUNC_MAINPAGE_CHECK_BLOCK_PASSWORD, (void *)&PasswordInput1, NULL))
                {
                    // password wrong
                    _ePrevCommonDlgMode = EN_COMMON_DLG_MODE_SCAN_INPUT_PASSWORD;
                    _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_WRONG_PASSWORD);
                }
                else
                {

                #if (ENABLE_EWS)
                if((MApp_ZUI_ACT_GetTuningCountry() == E_INDONESIA) && bNeedShowEWS)
                    {

                        MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_INPUT_EWS_LOCATION);
                        return TRUE;
                    }
                    bNeedShowEWS =FALSE;

                #endif
                #if NTV_FUNCTION_ENABLE
                    if((MApp_ZUI_ACT_GetTuningCountry() == E_NORWAY) && (_eCommonSingleMode != EN_COMMON_SINGLELIST_BANDWIDTH_SELECT))
                    {
                        MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_BANDWIDTH_SELECT);
                    }
                    else
                #endif
                    {
                        MApp_FuncExec_Mainpage(EN_FUNC_MAINPAGE_SET_AUTO_TUNING, NULL, NULL);
                        MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_CLOSE, E_ZUI_STATE_TERMINATE);
                        _enTargetMenuState = STATE_MENU_GOTO_SCAN;
                    }
                }
                return TRUE;
            }
        //anvi cec
        case EN_EXE_GOTO_OPTION_HDMI_CEC_PAGE:
        {
            MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_HDMI_CEC_PAGE, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_HDMI_CEC_HDMI);
            return TRUE;
        }

        case EN_EXE_SW_USB_UPDATE:
            MApp_FuncExec_Mainpage(EN_FUNC_MAINPAGE_USB_UPDATE, NULL, MApp_ZUI_SwUpdate_ProgressBar);
            break;


        case EN_EXE_GOTO_DVB_SELECT_INPUT_PASSWORD_DLG:
            MApi_AUTH_Process(Customer_info,Customer_hash);
            if(MDrv_AUTH_IPCheck(IPAUTH_CONTROL_XC_DVBC) == TRUE )
            {
            #if ENABLE_T_C_COMBO
                if(MApp_FuncExec_Mainpage(EN_FUNC_MAINPAGE_GET_SYS_BLOCK_MODE, NULL, NULL) == EN_FUNC_MAINPAGE_STATUS_TRUE)
                {
                    MApp_ZUI_API_StoreFocusCheckpoint();
                    _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_SCAN_INPUT_PASSWORD);
                }
                else
                {
                    if(MApp_FuncExec_Mainpage(EN_FUNC_MAINPAGE_CHECK_BLOCK_PASSWORD, (void *)&PasswordInput1, NULL))
                    {
                            // password wrong
                            _ePrevCommonDlgMode = EN_COMMON_DLG_MODE_SCAN_INPUT_PASSWORD;
                            _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_WRONG_PASSWORD);
                    }
                    else
                    {
                        if (IsDVBTInUse() || IsDTMBInUse())
                        {
                            MApp_DVBType_SetCurrentType(EN_DVB_T_TYPE);
                        }
                        else if (IsDVBCInUse())
                        {
                            MApp_DVBType_SetCurrentType(EN_DVB_C_TYPE);
                        }
                        else if (IsATVInUse())
                        {
                            switch (SYS_DEFAULT_DTV_UI_INPUTSOURCE)
                            {
                                case UI_INPUT_SOURCE_DVBT:
                                case UI_INPUT_SOURCE_DTMB:
                                    MApp_DVBType_SetCurrentType(EN_DVB_T_TYPE);
                                    break;
                                case UI_INPUT_SOURCE_DVBC:
                                    MApp_DVBType_SetCurrentType(EN_DVB_C_TYPE);
                                    break;
                                default:
                                    MApp_DVBType_SetCurrentType(EN_DVB_T_TYPE);
                                    break;
                            }
                        }
                        MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_SCAN_INPUT_PASSWORD_DLG);
                    }
                }
            #elif ENABLE_DVBC
                MApp_DVBType_SetCurrentType(EN_DVB_C_TYPE);
                MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_SCAN_INPUT_PASSWORD_DLG);
            #else
                MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_SCAN_INPUT_PASSWORD_DLG);
            #endif
            }
            else
            {
                MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_SCAN_INPUT_PASSWORD_DLG);
            }
            return TRUE;


        case EN_EXE_GOTO_SCAN_INPUT_PASSWORD_DLG:
            //printf("\r\n EN_EXE_GOTO_SCAN_INPUT_PASSWORD_DLG\n");
        #if (ENABLE_CI_PLUS)
            MApp_CI_ExitCiOperatorProfile();
        #endif
        #if 0//(DTV_SYSTEM_SEL != DTV_SYSTEM_DVBT_Plus_DVBC)
            if(MApp_FuncExec_Mainpage(EN_FUNC_MAINPAGE_GET_SYS_BLOCK_MODE, NULL, NULL) == EN_FUNC_MAINPAGE_STATUS_TRUE)
            {
                MApp_ZUI_API_StoreFocusCheckpoint();
                MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_DVB_SELECT_MENU, SW_HIDE);
                _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_SCAN_INPUT_PASSWORD);
            }
            else
        #endif
            {
            #if(ENABLE_ATV_CHINA_APP)    //china will not use country adjust option
                MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_AUTO_TUNING);
            #elif (ENABLE_SBTVD_BRAZIL_APP)
                eTuneType = (EN_OSD_TUNE_TYPE_SETTING)OSD_TUNE_TYPE_DTV_PLUS_ATV;
                MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_AUTO_TUNING);
            #else
            
              #if ENABLE_ATSC
                eTuneType = (EN_OSD_TUNE_TYPE_SETTING)OSD_TUNE_TYPE_DTV_ONLY;
              #elif ENABLE_DVB // 0990526: [SQC][Melody_242C][1st_ATV][ATV] Auto Tuning
                eTuneType = (EN_OSD_TUNE_TYPE_SETTING)OSD_TUNE_TYPE_DTV_PLUS_ATV;
              #else
                eTuneType = (EN_OSD_TUNE_TYPE_SETTING)OSD_TUNE_TYPE_ATV_ONLY;
              #endif

              #if ENABLE_T_C_COMBO
                if(MApp_DVBType_GetCurrentType() == EN_DVB_T_TYPE)
                    MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_TUNING_CONFIRM);
                else
                    MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_DVBC_SCAN_PAGE);
              #else
                MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_TUNING_CONFIRM);
              #endif // #if ENABLE_T_C_COMBO
            #endif
            }
            return TRUE;

    #if 0//ENABLE_T_C_COMBO
        case EN_EXE_GOTO_DVB_SELECT:
            //printf("Exe MianMenu::> EN_EXE_GOTO_DVB_SELECT\n");
            _eCommonSingleMode = EN_COMMON_SINGLELIST_DVB_SELECT;
            if(MApp_FuncExec_Mainpage(EN_FUNC_MAINPAGE_CHECK_BLOCK_PASSWORD, (void *)&PasswordInput1, NULL))
            {
                    // password wrong
                    _ePrevCommonDlgMode = EN_COMMON_DLG_MODE_SCAN_INPUT_PASSWORD;
                    _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_WRONG_PASSWORD);
            }
            else
            {
                MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
                MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_DVB_SELECT_MENU, SW_SHOW);
                eTuneType = (EN_OSD_TUNE_TYPE_SETTING)OSD_TUNE_TYPE_DTV_PLUS_ATV;
                switch(stGenSetting.stScanMenuSetting.u8DVBCTvConnectionType)
                {
                    case EN_DVB_T_TYPE:
                        MApp_ZUI_API_SetFocus(HWND_SELECTED_DVBT_BG);
                        break;
                    case EN_DVB_C_TYPE:
                        MApp_ZUI_API_SetFocus(HWND_SELECTED_DVBC_BG);
                        break;
                    default:
                        MApp_ZUI_API_SetFocus(HWND_SELECTED_DVBT_BG);
                        break;
                }
            }
            return TRUE;
    #endif // #if ENABLE_T_C_COMBO

    #if ENABLE_T_C_COMBO

        case EN_EXE_GOTO_DVBC_SCAN_PAGE :
            //printf("Exe MianMenu::> EN_EXE_GOTO_DVBC_SCAN_PAGE\n");
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_ACT_ShowDVBCScanPage();
            return TRUE;
    #endif // #if ENABLE_T_C_COMBO

    #if (NTV_FUNCTION_ENABLE)
        case EN_EXE_GOTO_BANDWIDTH_SELECT:
            //printf("Exe MianMenu::> EN_EXE_GOTO_BANDWIDTH_SELECT\n");
            _eCommonSingleMode = EN_COMMON_SINGLELIST_BANDWIDTH_SELECT;
            {
                MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_TUNE_CONFIRM, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
                MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_DVBT_BANDWIDTH_SELECT_MENU, SW_SHOW);
                switch(stGenSetting.stScanMenuSetting.u8BandWidth)
                {
                    case E_RF_CH_BAND_7MHz:
                        MApp_ZUI_API_SetFocus(HWND_SELECTED_BANDWIDTH_7M_BG);
                        break;
                    case E_RF_CH_BAND_8MHz:
                        MApp_ZUI_API_SetFocus(HWND_SELECTED_BANDWIDTH_8M_BG);
                        break;
                    default:
                        MApp_ZUI_API_SetFocus(HWND_SELECTED_BANDWIDTH_7M_BG);
                        break;
                }
            }
            return TRUE;
    #endif

#if (ENABLE_EWS)
        case EN_EXE_ENTER_EWS_LOCAL_KEY:
            {
                //MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_DVB_SELECT_MENU, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_TUNE_CONFIRM, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
                MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_INPUT_EWS_LOCATION_COMMON, SW_SHOW);
                //MApp_EWS_SetMsgCancelFlag(FALSE); //cancel EWS
                u8Temp_EWS_Num1 = stGenSetting.stMiscSetting.u8EWSLocationCode[0] ;
                u8Temp_EWS_Num2 = stGenSetting.stMiscSetting.u8EWSLocationCode[1] ;
                u8Temp_EWS_Num3 = stGenSetting.stMiscSetting.u8EWSLocationCode[2] ;
                u8Temp_EWS_Num4 = stGenSetting.stMiscSetting.u8EWSLocationCode[3] ;
                u8Temp_EWS_Num5 = stGenSetting.stMiscSetting.u8EWSLocationCode[4] ;
                bFROM_ChannelMenu =TRUE;

                MApp_ZUI_API_SetFocus(HWND_MENU_DLG_INPUT_EWS_LOCATION_PASSWORD_INPUT0_TEXT_1);
            }
            return TRUE;



        case EN_EXE_GOTO_INPUT_EWS_LOCATION:
        {

            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_DVB_SELECT_MENU, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_TUNE_CONFIRM, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_INPUT_EWS_LOCATION_COMMON, SW_SHOW);
           // MApp_EWS_SetMsgCancelFlag(FALSE); //cancel EWS


            u8Temp_EWS_Num1 = stGenSetting.stMiscSetting.u8EWSLocationCode[0] ;
            u8Temp_EWS_Num2 = stGenSetting.stMiscSetting.u8EWSLocationCode[1] ;
            u8Temp_EWS_Num3 = stGenSetting.stMiscSetting.u8EWSLocationCode[2] ;
            u8Temp_EWS_Num4 = stGenSetting.stMiscSetting.u8EWSLocationCode[3] ;
            u8Temp_EWS_Num5 = stGenSetting.stMiscSetting.u8EWSLocationCode[4] ;
            bFROM_ChannelMenu =FALSE;
            MApp_ZUI_API_SetFocus(HWND_MENU_DLG_INPUT_EWS_LOCATION_PASSWORD_INPUT0_TEXT_1);
        }
        return TRUE;

        case EN_EXE_INPUT_EWS_NUM_KEY0:
        case EN_EXE_INPUT_EWS_NUM_KEY1:
        case EN_EXE_INPUT_EWS_NUM_KEY2:
        case EN_EXE_INPUT_EWS_NUM_KEY3:
        case EN_EXE_INPUT_EWS_NUM_KEY4:
        case EN_EXE_INPUT_EWS_NUM_KEY5:
        case EN_EXE_INPUT_EWS_NUM_KEY6:
        case EN_EXE_INPUT_EWS_NUM_KEY7:
        case EN_EXE_INPUT_EWS_NUM_KEY8:
        case EN_EXE_INPUT_EWS_NUM_KEY9:
        {
            U16 u16Number= act - EN_EXE_INPUT_EWS_NUM_KEY0;
            switch(MApp_ZUI_API_GetFocus())
            {
                case HWND_MENU_DLG_INPUT_EWS_LOCATION_PASSWORD_INPUT0_TEXT_1:
                    u8Temp_EWS_Num1 = u16Number;
                    MApp_ZUI_API_SetFocus(HWND_MENU_DLG_INPUT_EWS_LOCATION_PASSWORD_INPUT0_TEXT_2);
                    break;

                case HWND_MENU_DLG_INPUT_EWS_LOCATION_PASSWORD_INPUT0_TEXT_2:
                    u8Temp_EWS_Num2 = u16Number;
                    MApp_ZUI_API_SetFocus(HWND_MENU_DLG_INPUT_EWS_LOCATION_PASSWORD_INPUT0_TEXT_3);
                break;

                case HWND_MENU_DLG_INPUT_EWS_LOCATION_PASSWORD_INPUT0_TEXT_3:
                    u8Temp_EWS_Num3 = u16Number;
                    MApp_ZUI_API_SetFocus(HWND_MENU_DLG_INPUT_EWS_LOCATION_PASSWORD_INPUT0_TEXT_4);
                break;

                case HWND_MENU_DLG_INPUT_EWS_LOCATION_PASSWORD_INPUT0_TEXT_4:
                    u8Temp_EWS_Num4 = u16Number;
                    MApp_ZUI_API_SetFocus(HWND_MENU_DLG_INPUT_EWS_LOCATION_PASSWORD_INPUT0_TEXT_5);
                break;

                case HWND_MENU_DLG_INPUT_EWS_LOCATION_PASSWORD_INPUT0_TEXT_5:
                    u8Temp_EWS_Num5 = u16Number;
                    MApp_ZUI_API_SetFocus(HWND_MENU_DLG_INPUT_EWS_LOCATION_COMMON_BTN_YES);
                break;
                default:
                break;

            }
            MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_DLG_INPUT_EWS_LOCATION_CODE_PANE0);

        }
        return TRUE;

        case EN_EXE_INPUT_EWS_EWS_CANEL:
            u8Temp_EWS_Num1 = stGenSetting.stMiscSetting.u8EWSLocationCode[0] ;
            u8Temp_EWS_Num2 = stGenSetting.stMiscSetting.u8EWSLocationCode[1] ;
            u8Temp_EWS_Num3 = stGenSetting.stMiscSetting.u8EWSLocationCode[2] ;
            u8Temp_EWS_Num4 = stGenSetting.stMiscSetting.u8EWSLocationCode[3] ;
            u8Temp_EWS_Num5 = stGenSetting.stMiscSetting.u8EWSLocationCode[4] ;
            MApp_ZUI_API_InvalidateAllSuccessors(HWND_MENU_DLG_INPUT_EWS_LOCATION_CODE_PANE0);
            MApp_ZUI_API_SetFocus(HWND_MENU_DLG_INPUT_EWS_LOCATION_PASSWORD_INPUT0_TEXT_1);

        return TRUE;

        case EN_EXE_INPUT_EWS_EWS_DONE:
            bNeedShowEWS =FALSE;
            stGenSetting.stMiscSetting.u8EWSLocationCode[0] = u8Temp_EWS_Num1;
            stGenSetting.stMiscSetting.u8EWSLocationCode[1] = u8Temp_EWS_Num2;
            stGenSetting.stMiscSetting.u8EWSLocationCode[2] = u8Temp_EWS_Num3;
            stGenSetting.stMiscSetting.u8EWSLocationCode[3] = u8Temp_EWS_Num4;
            stGenSetting.stMiscSetting.u8EWSLocationCode[4] = u8Temp_EWS_Num5;

            MApp_SI_SetLocationCode(stGenSetting.stMiscSetting.u8EWSLocationCode);

            MApp_EWS_SetMsgCancelFlag(FALSE); //cancel EWS
            if(bFROM_ChannelMenu)
            {
                bFROM_ChannelMenu =FALSE;
                MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_CLOSE_CURRENT_OSD);
            }
            else
                MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_AUTO_TUNING);
            return TRUE;
#endif

        case EN_EXE_GOTO_TUNING_CONFIRM:
            if(MApp_FuncExec_Mainpage(EN_FUNC_MAINPAGE_CHECK_BLOCK_PASSWORD, (void *)&PasswordInput1, NULL))
            {
                    // password wrong
                    _ePrevCommonDlgMode = EN_COMMON_DLG_MODE_SCAN_INPUT_PASSWORD;
                    _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_WRONG_PASSWORD);
            }
            else
            {
                MApp_ZUI_ACT_SetTuningCountry(OSD_COUNTRY_SETTING); //initial temp country

            #if 0//ENABLE_T_C_COMBO
                if(MApp_DVBType_GetCurrentType() == EN_DVB_T_TYPE)
                    MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_DVB_SELECT_MENU, SW_HIDE);
            #else
                MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            #endif
                MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
                MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_TUNE_CONFIRM, SW_SHOW);
                MApp_ZUI_CTL_Grid_SetIndex(HWND_MENU_DLG_TUNE_CONFIRM_COUNTRY_GRID, MApp_ZUI_ACT_GetTuningCountryIndex, MApp_ZUI_ACT_SetTuningCountryIndex, 0, MApp_ZUI_ACT_GetTuningCountryIndexMax());
                MApp_ZUI_CTL_Grid_SetFnGetTextByIndex(HWND_MENU_DLG_TUNE_CONFIRM_COUNTRY_GRID, MApp_ZUI_ACT_GetCountryStringByIndex);

            #if ENABLE_SBTVD_BRAZIL_APP
                MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_TUNE_CONFIRM_COUNTRY_GRID, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_TUNE_CONFIRM_TUNE_TYPE, SW_HIDE);
                MApp_ZUI_API_SetFocus(HWND_MENU_DLG_TUNE_CONFIRM);
            #else
                MApp_ZUI_API_SetFocus(HWND_MENU_DLG_TUNE_CONFIRM_TUNE_TYPE);
            #endif

            #if (ENABLE_DTV == 0)
                MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_TUNE_CONFIRM_TUNE_TYPE, SW_HIDE);
                MApp_ZUI_API_SetFocus(HWND_MENU_DLG_TUNE_CONFIRM_COUNTRY_GRID);
            #endif

#if (ENABLE_EWS)
            bNeedShowEWS =TRUE;
#endif
            }
            return TRUE;


        case EN_EXE_GOTO_MENU_LOCK_PAGE:
          #if ENABLE_DTV
            if(/*stGenSetting.g_BlockSysSetting.u8BlockSysLockMode==1 &&*/
                _MApp_ZUI_ACT_PasswordConvertToSystemFormat(PasswordInput1) !=
                MApp_MenuFunc_Setup_BlockSysPassWord_Get())
            {
                    // password wrong
                    _ePrevCommonDlgMode = EN_COMMON_DLG_MODE_ENTER_MENU_LOCK_PAGE_INPUT_PASSWORD;
                    _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_WRONG_PASSWORD);
            }
            else
            {
                MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_PAGE, SW_SHOW);
                MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_LOCK);
                MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
                MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_SYSTEM);
            }
          #endif // #if ENABLE_DTV
            return TRUE;

        case EN_EXE_GOTO_SET_CLOCK:
            g_mainpage_common = EN_COMMON_TIME_CLOCK_PAGE;
            MApp_Sleep_SetOffTime(FALSE);  //disable off timer
            MApp_ZUI_API_ShowWindow(HWND_MENU_TIME_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            //MApp_ZUI_API_ShowWindow(HWND_MENU_TIME_CLOCK_PAGE, SW_SHOW);
            //MApp_ZUI_API_SetFocus(HWND_MENU_TIME_CLOCK_DAY);
            MApp_ZUI_API_ShowWindow(HWND_MENU_COMMON_ADJ_PAGE, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_COMMON_ADJ_ITEM2);

            MApp_ZUI_ACT_ResetTimeMenuTenKey();//init ten key input value
            //MApp_ZUI_API_PostMessage(HWND_MENU_TIME_CLOCK_PAGE, MSG_EFFECT_SPREADOUT, 0);
            return TRUE;


        case EN_EXE_GOTO_SET_OFF_TIMER:
            g_mainpage_common = EN_COMMON_OFFTIMER_PAGE;
            MApp_Sleep_SetOffTime(FALSE); //disable off timer

            MApp_ZUI_API_ShowWindow(HWND_MENU_TIME_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            //MApp_ZUI_API_ShowWindow(HWND_MENU_TIME_OFFTIME_PAGE, SW_SHOW);
            //MApp_ZUI_API_SetFocus(HWND_MENU_TIME_OFFTIME);
            MApp_ZUI_API_ShowWindow(HWND_MENU_COMMON_ADJ_PAGE, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_COMMON_ADJ_ITEM1);
            /*
            if (stGenSetting.g_Time.cOffTimerFlag == EN_Time_OffTimer_Off)
            {
                MApp_ZUI_API_EnableWindow(HWND_MENU_TIME_OFFTIME_HOUR, DISABLE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_TIME_OFFTIME_MINUTE, DISABLE);
            }
            else
            {
                MApp_ZUI_API_EnableWindow(HWND_MENU_TIME_OFFTIME_PAGE, ENABLE);
            }
*/
            MApp_ZUI_ACT_ResetTimeMenuTenKey();//init ten key input value
            return TRUE;


        case EN_EXE_GOTO_SET_ON_TIMER:
            g_mainpage_common = EN_COMMON_ONTIMER_PAGE;
            MApp_ZUI_API_ShowWindow(HWND_MENU_TIME_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            //MApp_ZUI_API_ShowWindow(HWND_MENU_TIME_ONTIME_PAGE, SW_SHOW);
            //MApp_ZUI_API_SetFocus(HWND_MENU_TIME_ONTIME_REPEAT);
            MApp_ZUI_API_ShowWindow(HWND_MENU_COMMON_ADJ_PAGE, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_COMMON_ADJ_ITEM1);

            /*if(stGenSetting.g_Time.cOnTimerSourceFlag == EN_Time_OnTimer_Source_RADIO  //Thomas 20150714 to do
                #if (ENABLE_ATSC)
                || stGenSetting.g_Time.cOnTimerSourceFlag == EN_Time_OnTimer_Source_TV
                #else
                || stGenSetting.g_Time.cOnTimerSourceFlag == EN_Time_OnTimer_Source_DTV
                #endif
            #if ENABLE_S2
                || stGenSetting.g_Time.cOnTimerSourceFlag == EN_Time_OnTimer_Source_DVBS2
            #endif
                #if NORDIG_FUNC //for Nordig Spec v2.0
                || stGenSetting.g_Time.cOnTimerSourceFlag == EN_Time_OnTimer_Source_DATA
                #endif
                #if (!ENABLE_ATSC)
                || stGenSetting.g_Time.cOnTimerSourceFlag == EN_Time_OnTimer_Source_ATV
                #endif
                )
            {
                MApp_ZUI_API_EnableWindow(HWND_MENU_TIME_ONTIME_CHANNEL, TRUE);
            }
            else
            {
                MApp_ZUI_API_EnableWindow(HWND_MENU_TIME_ONTIME_CHANNEL, FALSE);
            }
            if(stGenSetting.g_Time.cOnTimerFlag==EN_Time_OnTimer_Off)
            {
                MApp_ZUI_API_EnableWindow(HWND_MENU_TIME_ONTIME_HOUR, DISABLE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_TIME_ONTIME_MINUTE, DISABLE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_TIME_ONTIME_SOURCE, DISABLE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_TIME_ONTIME_CHANNEL, DISABLE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_TIME_ONTIME_VOLUME, DISABLE);
            }
            else
            {
                MApp_ZUI_API_EnableWindow(HWND_MENU_TIME_ONTIME_PAGE, ENABLE);
            }
*/
            MApp_ZUI_ACT_ResetTimeMenuTenKey();//init ten key input value
            return TRUE;


        case EN_EXE_GOTO_AUDIOLANG_PAGE:
            MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_AUDIOLANG_PAGE, SW_SHOW);
            if(OSD_COUNTRY_SETTING == E_NEWZEALAND)
            {
                MApp_ZUI_CTL_Grid_SetIndex(HWND_MENU_OPTION_AUDIOLANG_GRID, MApp_ZUI_ACT_GetAudioLanguageIndex, MApp_ZUI_ACT_SetAudioLanguageIndex, LANGUAGE_CZECH, LANGUAGE_AUDIO_MAX_NZ);
            }
            else
            {
                MApp_ZUI_CTL_Grid_SetIndex(HWND_MENU_OPTION_AUDIOLANG_GRID, MApp_ZUI_ACT_GetAudioLanguageIndex, MApp_ZUI_ACT_SetAudioLanguageIndex, LANGUAGE_CZECH, LANGUAGE_AUDIO_MAX_EU);
            }
            MApp_ZUI_CTL_Grid_SetFnGetTextByIndex(HWND_MENU_OPTION_AUDIOLANG_GRID, MApp_ZUI_ACT_GetLanguageStringByIndex);
            MApp_ZUI_API_SetFocus(HWND_MENU_OPTION_AUDIOLANG_PRIMARY);
            return TRUE;


        case EN_EXE_GOTO_SET_AUDIO_LAN:
            if(OSD_COUNTRY_SETTING == E_NEWZEALAND)
            {
                MApp_ZUI_CTL_Grid_SetIndex(HWND_MENU_OPTION_AUDIOLANG_GRID, MApp_ZUI_ACT_GetAudioLanguageIndex, MApp_ZUI_ACT_SetAudioLanguageIndex, LANGUAGE_CZECH, LANGUAGE_AUDIO_MAX_NZ);
            }
            else
            {
                MApp_ZUI_CTL_Grid_SetIndex(HWND_MENU_OPTION_AUDIOLANG_GRID, MApp_ZUI_ACT_GetAudioLanguageIndex, MApp_ZUI_ACT_SetAudioLanguageIndex, LANGUAGE_CZECH, LANGUAGE_AUDIO_MAX_EU);
            }
            MApp_ZUI_CTL_Grid_SetFnGetTextByIndex(HWND_MENU_OPTION_AUDIOLANG_GRID, MApp_ZUI_ACT_GetLanguageStringByIndex);
            MApp_ZUI_API_SetFocus(HWND_MENU_OPTION_AUDIOLANG_GRID);
            return TRUE;


        case EN_EXE_GOTO_SUBLANG_PAGE:
            MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_SUBLANG_PAGE, SW_SHOW);
            if(OSD_COUNTRY_SETTING == E_NEWZEALAND)
            {
                MApp_ZUI_CTL_Grid_SetIndex(HWND_MENU_OPTION_SUBLANG_GRID, MApp_ZUI_ACT_GetSubLanguageIndex, MApp_ZUI_ACT_SetSubLanguageIndex, LANGUAGE_CZECH, LANGUAGE_SUBTITLE_MAX_NZ);
            }
            else
            {
                MApp_ZUI_CTL_Grid_SetIndex(HWND_MENU_OPTION_SUBLANG_GRID, MApp_ZUI_ACT_GetSubLanguageIndex, MApp_ZUI_ACT_SetSubLanguageIndex, LANGUAGE_CZECH, LANGUAGE_SUBTITLE_MAX_EU);
            }
            MApp_ZUI_CTL_Grid_SetFnGetTextByIndex(HWND_MENU_OPTION_SUBLANG_GRID, MApp_ZUI_ACT_GetSubtitleLanguageStringByIndex);
            MApp_ZUI_API_SetFocus(HWND_MENU_OPTION_SUBLANG_PRIMARY);
            return TRUE;


        case EN_EXE_GOTO_SET_SUBTITLE_LAN:
            if(OSD_COUNTRY_SETTING == E_NEWZEALAND)
            {
                MApp_ZUI_CTL_Grid_SetIndex(HWND_MENU_OPTION_SUBLANG_GRID, MApp_ZUI_ACT_GetSubLanguageIndex, MApp_ZUI_ACT_SetSubLanguageIndex, LANGUAGE_CZECH, LANGUAGE_SUBTITLE_MAX_NZ);
            }
            else
            {
                MApp_ZUI_CTL_Grid_SetIndex(HWND_MENU_OPTION_SUBLANG_GRID, MApp_ZUI_ACT_GetSubLanguageIndex, MApp_ZUI_ACT_SetSubLanguageIndex, LANGUAGE_CZECH, LANGUAGE_SUBTITLE_MAX_EU);
            }
            MApp_ZUI_CTL_Grid_SetFnGetTextByIndex(HWND_MENU_OPTION_SUBLANG_GRID, MApp_ZUI_ACT_GetSubtitleLanguageStringByIndex);
            MApp_ZUI_API_SetFocus(HWND_MENU_OPTION_SUBLANG_GRID);
            return TRUE;


        case EN_EXE_GOTO_SET_OSD_LAN:
            MApp_ZUI_CTL_Grid_SetIndex(HWND_MENU_OPTION_OSDLANG_GRID, MApp_ZUI_ACT_GetOsdLanguageIndex, MApp_ZUI_ACT_SetOsdLanguageIndex, LANGUAGE_MENU_MIN, LANGUAGE_MENU_MAX);
             MApp_ZUI_CTL_Grid_SetFnGetTextByIndex(HWND_MENU_OPTION_OSDLANG_GRID, MApp_ZUI_ACT_GetMenuLanguageStringByIndex);
        #if(ENABLE_DTMB)
            if(IsDTMBInUse())
            {
                MApp_Dmx_EIT_Init_ChangeLanguage();
            }
        #endif
            MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_OSDLANG_PAGE, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_OPTION_OSDLANG_GRID);
            return TRUE;
    #if(ENABLE_ATSC)
        case EN_EXE_GOTO_SET_OSD_LAN_ATSC:
        		#ifdef SetLanguageIssue
						MApp_ZUI_ACT_AppUpdateLanguageSelMenu();
  					/*switch(MENU_LANGUAGE)
  					{
  					    case LANGUAGE_ENGLISH:
  					        MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM1);
  					        break;
  					    case LANGUAGE_FRENCH:
  					        MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM2);
  					        break;
  					    case LANGUAGE_SPANISH:
  					        MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM3);
  					        break;
  					    #ifdef sTriviewSupportOSDLanguage
                case LANGUAGE_GERMAN:
  					        MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM4);
  					        break;                
                case LANGUAGE_ITALIAN:
  					        MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM5);
  					        break;                
                case LANGUAGE_PORTUGUESE:
  					        MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM6);
  					        break;                
                case LANGUAGE_RUSSIAN:			    
  					        MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM7);
  					        break;                
  					    case LANGUAGE_CHINESE:
  					        MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM8);
  					        break;                
  					    #endif    
  					    default:
  					        break;
  					}*/						
						#else
            _eCommonSingleMode = EN_COMMON_SINGLELIST_MENU_LANGUAGE;
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
            MApp_ZUI_API_ShowWindow(HWND_MENU_SINGLELIST_COMMON_PAGE, SW_SHOW);
            switch(MENU_LANGUAGE)
            {
                case LANGUAGE_ENGLISH:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM1);
                    break;
                case LANGUAGE_FRENCH:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM2);
                    break;
                case LANGUAGE_SPANISH:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM3);
                    break;
                #ifdef sTriviewSupportOSDLanguage
                case LANGUAGE_GERMAN:
  					        MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM4);
  					        break;                
                case LANGUAGE_ITALIAN:
  					        MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM5);
  					        break;                
                case LANGUAGE_PORTUGUESE:
  					        MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM6);
  					        break;                
                case LANGUAGE_RUSSIAN:			    
  					        MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM7);
  					        break;                   
                case LANGUAGE_CHINESE:
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM8);
                    break;                
                #endif    
                default:
                    break;
            }
            #endif
            return TRUE;
    #endif
        case EN_EXE_GOTO_SET_TIMEZONE:

            MApp_ZUI_CTL_Grid_SetIndex(HWND_MENU_TIME_TIMEZONE_GRID, MApp_ZUI_ACT_GetTimezoneIndex, MApp_ZUI_ACT_SetTimezoneIndex, 0, MApp_ZUI_ACT_GetTimezoneMaxIndex());
            MApp_ZUI_CTL_Grid_SetFnGetTextByIndex(HWND_MENU_TIME_TIMEZONE_GRID, MApp_ZUI_ACT_GetTimezoneStringByIndex);

            MApp_ZUI_API_ShowWindow(HWND_MENU_TIME_PAGE, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
            MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
#if (ENABLE_ATSC)
            if (IsAtscInUse() || IsATVInUse())
            {
                //printf("[ms] Entering ATSC time zone\n");
                _eCommonSingleMode = EN_COMMON_SINGLELIST_OSD_TIMEZONE;
                MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_MENU_TIME_PAGE, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
                MApp_ZUI_API_ShowWindow(HWND_MENU_SINGLELIST_COMMON_PAGE, SW_SHOW);
                switch(stGenSetting.g_SysSetting.u8TimeZone)
                {
                     case TIME_ZONE_ATLANTIC:
                     MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM1);
                     break;
                     case TIME_ZONE_EASTERN:
                     MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM2);
                     break;
                     case TIME_ZONE_CENTRAL:
                     MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM3);
                     break;
                     case TIME_ZONE_MOUNTAIN:
                     MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM4);
                     break;
                     case TIME_ZONE_PACIFIC:
                     MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM5);
                     break;
                     case TIME_ZONE_ALASKA:
                     MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM6);
                     break;
                     case TIME_ZONE_HAWAII:
                     MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM7);
                     break;
                     default:
                     break;
                  }
            }
            else
#endif

            {
                //printf("[ms] Entering DVB time zone\n");
                MApp_ZUI_API_ShowWindow(HWND_MENU_TIME_TIMEZONE_PAGE, SW_SHOW);
                MApp_ZUI_API_SetFocus(HWND_MENU_TIME_TIMEZONE_GRID);
            }
            return TRUE;

        case EN_EXE_SET_AUTOTUNING_COUNTRY:
            MApp_ZUI_CTL_Grid_SetIndex(HWND_MENU_DLG_TUNE_CONFIRM_COUNTRY_GRID, MApp_ZUI_ACT_GetTuningCountryIndex, MApp_ZUI_ACT_SetTuningCountryIndex, 0, MApp_ZUI_ACT_GetTuningCountryIndexMax());
            MApp_ZUI_CTL_Grid_SetFnGetTextByIndex(HWND_MENU_DLG_TUNE_CONFIRM_COUNTRY_GRID, MApp_ZUI_ACT_GetCountryStringByIndex);
            MApp_ZUI_API_SetFocus(HWND_MENU_DLG_TUNE_CONFIRM_COUNTRY_GRID);
            return TRUE;

        case EN_EXE_PASS_PASSWORD:
        {
             switch(_ePrevCommonDlgMode)
             {
                case EN_COMMON_DLG_MODE_FACTORY_RESET_INPUT_PASSWORD:
                    MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_FACTORY_RESET_CONFIRM_DLG);
                    break;

                case EN_COMMON_DLG_MODE_ATV_TUNING_INPUT_PASSWORD:
                    MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_ATV_TUNING);
                    break;

                case EN_COMMON_DLG_MODE_DTV_TUNING_INPUT_PASSWORD:
                    MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_DTV_TUNING);
                    break;

                case EN_COMMON_DLG_MODE_SCAN_INPUT_PASSWORD:
                  #if (ENABLE_ATV_CHINA_APP||ENABLE_SBTVD_BRAZIL_APP)//china will not use country adjust option
                    MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_AUTO_TUNING);
                  #else
                    MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_TUNING_CONFIRM);
                  #endif
                break;

                case EN_COMMON_DLG_MODE_ENTER_MENU_LOCK_PAGE_INPUT_PASSWORD:
                    MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_MENU_LOCK_PAGE);
                    break;

                default:
                    return 0;
             }
             break;
        }
        return TRUE;


        case EN_EXE_GOTO_CONFIRM_FACTORY_RESET:
            if(MApp_FuncExec_Mainpage(EN_FUNC_MAINPAGE_GET_SYS_BLOCK_MODE, NULL, NULL) == EN_FUNC_MAINPAGE_STATUS_TRUE)
            {
                MApp_ZUI_API_StoreFocusCheckpoint();
                _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_FACTORY_RESET_INPUT_PASSWORD);

            }
            else
            {
                MApp_ZUI_API_StoreFocusCheckpoint();
                MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_FACTORY_RESET_CONFIRM_DLG);
            }
            return TRUE;


        case EN_EXE_GOTO_FACTORY_RESET_CONFIRM_DLG:
            if(MApp_FuncExec_Mainpage(EN_FUNC_MAINPAGE_CHECK_BLOCK_PASSWORD, (void *)&PasswordInput1, NULL))
            {
                // password wrong
                _ePrevCommonDlgMode = EN_COMMON_DLG_MODE_FACTORY_RESET_INPUT_PASSWORD;
                _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_WRONG_PASSWORD);
            }
            else
            {
                //store previous focus...
                //_hwndCommonDlgPrevFocus = MApp_ZUI_API_GetFocus();
                _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_FACTORY_RESET_CONFIRM);
            }
            return TRUE;

        case EN_EXE_GOTO_CONFIRM_DIVX:
            MApp_ZUI_API_StoreFocusCheckpoint();

            //put drm divx here
            MS_DEBUG_MSG(printf("put drm divx code here!\n"));

            MApp_MenuFunc_Setup_DIVXConfirm();

        #if ENABLE_DRM
            if((MApp_MenuFunc_Setup_IsDRMActivatedStatus_Get() == 0) && (MApp_MenuFunc_Setup_IsDRMDeActivatedStatus_Get() == 0))
            {
            _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_DIVX);
            }
            else if (MApp_MenuFunc_Setup_IsDRMActivatedStatus_Get() == 1)
            {
               _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_DEACTIVATION_CONFIRM);
            }
            else if (MApp_MenuFunc_Setup_IsDRMDeActivatedStatus_Get() == 1)
            {
               _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_DEACTIVATION);
            }
        #endif

            return TRUE;

        case EN_EXE_GOTO_CONFIRM_DEACTIVATION:
            MApp_ZUI_API_StoreFocusCheckpoint();
            _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_DEACTIVATION_CONFIRM);
            return TRUE;

    #if ENABLE_3D_PROCESS
        case EN_EXE_GOTO_SET_3D_TYPE:
            {
                _eCommonSingleMode = EN_COMMON_SINGLELIST_3D_TYPE;
                MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_MENU_TRANSPARENT_BG, SW_SHOW);
                MApp_ZUI_API_ShowWindow(HWND_MENU_SINGLELIST_COMMON_PAGE, SW_SHOW);
                switch(MApp_MenuFunc_Setup_3DType_Get())
                {
                    case EN_3D_BYPASS:
                       MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM1);
                       break;
                    case EN_3D_FRAME_PACKING:
                       MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM2);
                       break;
                    case EN_3D_SIDE_BY_SIDE:
                       MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM3);
                       break;
                    case EN_3D_TOP_BOTTOM:
                       MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM4);
                       break;
                    case EN_3D_LINE_ALTERNATIVE:
                       MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM5);
                       break;
                    case EN_3D_FRAME_ALTERNATIVE:
                       MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM6);
                       break;
                    case EN_3D_2DConvertTo3D:
                       MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_SINGLELIST_COMMON_PAGE_LIST, HWND_MENU_SINGLELIST_ITEM7);
                       break;
                    default:
                       MApp_ZUI_API_SetFocus(HWND_MENU_SINGLELIST_ITEM1);
                       break;
                }
            }
        break;
    #endif


        case EN_EXE_GOTO_COMMON_DLG_YES:
            //store previous focus...
            if(_eCommonDlgMode == EN_COMMON_DLG_MODE_FACTORY_RESET_CONFIRM)
            {
                MApp_ZUI_API_StoreFocusCheckpoint();
                _enTargetMenuState = STATE_MENU_INIT;
                _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_FACTORY_RESET);
            }
        #if ENABLE_ATSC_MENU_UI
            else if(_eCommonDlgMode == EN_COMMON_DLG_MODE_RESETRRT_CONFIRM)
            {
                MApp_UiMenuFunc_ResetRatingTable();
                MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_MENU_MASK_BACKGROUND,SW_SHOW);
                MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_LOCK);
                MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_TITLE,SW_SHOW);
                MApp_ZUI_API_ShowWindow(HWND_MENU_ICON_LOCK,SW_SHOW);
                MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_PAGE_LIST, SW_SHOW);
                MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_SYSTEM);
            }
        #endif
            else if(_eCommonDlgMode == EN_COMMON_DLG_MODE_DEACTIVATION_CONFIRM)
            {
                //put drm deactivation here
                MS_DEBUG_MSG(printf("put drm deactivation code here!\n"));
                MApp_MenuFunc_Setup_DRMDeactive();
                _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_DEACTIVATION);


            }
            else if(_eCommonDlgMode == EN_COMMON_DLG_MODE_DIVX)
            {
                MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_SHOW);
                MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_OPTION);
                //MApp_ZUI_API_RestoreFocusCheckpoint();
                MApp_ZUI_ACT_ExecuteMenuCommonDialogAction(EN_EXE_CLOSE_CURRENT_OSD);
                MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_OPTION_PAGE_LIST, HWND_MENU_OPTION_DIVX);
            }
            else if(_eCommonDlgMode == EN_COMMON_DLG_MODE_DEACTIVATION )
            {
                MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_SHOW);
                MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_OPTION);
                MApp_ZUI_API_RestoreFocusCheckpoint();
                _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_DIVX);
            }           
            else
            {
    							#if (!BLOADER)
    							/*
    							*  Disable Some HW Engines for Downloading
    							*/
    							{
    							    MS_VE_Output_Ctrl OutputCtrl;
    							    // disable VE
    							    OutputCtrl.bEnable = FALSE;
    							    msAPI_VE_SetOutputCtrl(&OutputCtrl);
											#if HW_AUTO_NO_SIGNAL
    							    if (IsYPbPrInUse()|| IsVgaInUse()||IsHDMIInUse())
    							    {
    							        MApi_XC_EnableIPAutoNoSignal(DISABLE, MAIN_WINDOW);
    							    }
											#endif
    							    // disable DNR buffer
    							    MApi_XC_DisableInputSource(TRUE, MAIN_WINDOW);
    							    //MW_AUD_SetSoundMute(SOUND_MUTE_ALL, E_MUTE_ON);
    							
    							    if(IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW))||IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
    							    {
    							        MApp_ChannelChange_DisableChannel(TRUE,MAIN_WINDOW);
    							    }
    							    else
    							    {
    							        MApp_ChannelChange_DisableAV(MAIN_WINDOW);
    							    }
    							
    							    // disable vd
    							    msAPI_AVD_Exit();
    							}
    							#endif           	
                _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_USB_UPGRADING);
                MApp_ZUI_API_SetTimer(HWND_MENU_DLG_COMMON,0,100);
            }
            return TRUE;


        case EN_EXE_GOTO_COMMON_DLG_NO:
            switch(_eCommonDlgMode)
            {
            #if ENABLE_ATSC_MENU_UI
                case EN_COMMON_DLG_MODE_RESETRRT_CONFIRM:
                    MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_PAGE, SW_SHOW);
                    MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_LOCK);
                    MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_MAINSUBPAGE_ITEM_RESETRRT);
                    break;
            #endif
                case EN_COMMON_DLG_MODE_FACTORY_RESET_CONFIRM:
                    MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_SHOW);
                    MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_OPTION);
                    MApp_ZUI_API_RestoreFocusCheckpoint();
                    break;
                case EN_COMMON_DLG_MODE_USB_UPDATE_CONFIRM:
                		#ifdef sSoftwareUpdateInOptionPage
                    MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_SHOW);
                    MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_OPTION);
                    MApp_ZUI_API_SetFocus(HWND_MENU_OPTION_SW_USB_UPGRADE);      
                		#else
                    MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE, SW_SHOW);
                    MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_CHANNEL);
                    MApp_ZUI_API_SetFocus(HWND_MENU_CHANNEL_SW_USB_UPGRADE);
                    #endif
                    break;
                case EN_COMMON_DLG_MODE_DIVX:
                case EN_COMMON_DLG_MODE_DEACTIVATION:
                case EN_COMMON_DLG_MODE_DEACTIVATION_CONFIRM:
                    MApp_ZUI_API_ShowWindow(HWND_MENU_OPTION_PAGE, SW_SHOW);
                    MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_OPTION);
                    //MApp_ZUI_API_RestoreFocusCheckpoint();
                    MApp_ZUI_CTL_DynamicListSetItemFocus(HWND_MENU_OPTION_PAGE_LIST, HWND_MENU_OPTION_DIVX);
                    break;

                default:
                    break;
            }
            MApp_ZUI_ACT_ExecuteMenuCommonDialogAction(EN_EXE_CLOSE_CURRENT_OSD);
            return TRUE;


        case EN_EXE_GOTO_WRONG_PASSWORD_DLG:
            //store previous focus...
            //_hwndCommonDlgPrevFocus = MApp_ZUI_API_GetFocus();
            MApp_ZUI_API_StoreFocusCheckpoint();
            _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_WRONG_PASSWORD);
            return TRUE;

        case EN_EXE_GOTO_MISMATCH_PASSWORD_DLG:
            //store previous focus...
            //_hwndCommonDlgPrevFocus = MApp_ZUI_API_GetFocus();
            MApp_ZUI_API_StoreFocusCheckpoint();
            _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_MISMATCH_PASSWORD);
            return TRUE;

        case EN_EXE_GOTO_SET_PASSWORD_DLG:
            //store previous focus...
            //_hwndCommonDlgPrevFocus = MApp_ZUI_API_GetFocus();
            MApp_ZUI_API_StoreFocusCheckpoint();
            _hwndCommonDlgTargetFocus = MApp_ZUI_API_GetFocus();
            _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_SET_PASSWORD);
            return TRUE;

        case EN_EXE_ENTER_MENU_LOCK_PAGE:
            MApp_ZUI_API_StoreFocusCheckpoint();
            _hwndCommonDlgTargetFocus = HWND_MENU_LOCK_SYSTEM;
            MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_PAGE, SW_HIDE);
            _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_ENTER_MENU_LOCK_PAGE_INPUT_PASSWORD);
            return TRUE;

        case EN_EXE_GOTO_INPUT_PASSWORD_DLG:
            //store previous focus...
            //_hwndCommonDlgPrevFocus = MApp_ZUI_API_GetFocus();
            MApp_ZUI_API_StoreFocusCheckpoint();

          #if 0
            if (stGenSetting.g_BlockSysSetting.u8BlockSysLockMode != 0)
            {
                _hwndCommonDlgTargetFocus = HWND_MENU_LOCK_SYSTEM;
                _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_INPUT_PASSWORD);
            }
            else
            {
                 _hwndCommonDlgTargetFocus = HWND_MENU_LOCK_SYSTEM;
                 MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_SYSTEM);
            }
          #else
            _hwndCommonDlgTargetFocus = HWND_MENU_LOCK_SYSTEM;
            MApp_ZUI_API_SetFocus(HWND_MENU_LOCK_SYSTEM);
          #endif

            return TRUE;


        case EN_EXE_CHECK_INPUT_PASSWORD:
            _eCommonDlgMode = EN_COMMON_DLG_MODE_INVALID;
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON, SW_HIDE);

            if (_MApp_ZUI_ACT_PasswordConvertToSystemFormat(PasswordInput1) ==
                MApp_MenuFunc_Setup_BlockSysPassWord_Get())
            {
                //password correct
                MApp_ZUI_API_SetFocus(_hwndCommonDlgTargetFocus);
            }
            else
            {
                //password wrong...
                _ePrevCommonDlgMode = EN_COMMON_DLG_MODE_INPUT_PASSWORD;
                _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_WRONG_PASSWORD);
            }
            return TRUE;

        case EN_EXE_CHECK_SET_PASSWORD_CHECKOLDPW:
            if((_MApp_ZUI_ACT_PasswordConvertToSystemFormat(PasswordInput0) ==
                MApp_MenuFunc_Setup_BlockSysPassWord_Get()) && PasswordInput1 == 0)
            {
                PasswordInput0 = 0;
                MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_TEXT5, SW_HIDE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT1_TEXT,ENABLE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT1_1, ENABLE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT1_2, ENABLE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT1_3, ENABLE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT1_4, ENABLE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT2_TEXT,ENABLE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT2_1, ENABLE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT2_1, ENABLE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT2_2, ENABLE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT2_3, ENABLE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT2_4, ENABLE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT0_TEXT,DISABLE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT0_1, DISABLE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT0_2, DISABLE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT0_3, DISABLE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_INPUT0_4, DISABLE);
                MApp_ZUI_API_EnableWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE0, DISABLE);
                MApp_ZUI_API_SetFocus(HWND_MENU_DLG_PASSWORD_INPUT1_1);
            }
            else
            {
                MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON_TEXT5, SW_SHOW);
                MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PRESSED_PANE0, SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_PASSWORD_PANE0, SW_SHOW);
                MApp_ZUI_API_SetFocus(HWND_MENU_DLG_PASSWORD_INPUT0_1);
            }
            return TRUE;

        case EN_EXE_CHECK_SET_PASSWORD:
            _eCommonDlgMode = EN_COMMON_DLG_MODE_INVALID;
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_COMMON, SW_HIDE);
            if (PasswordInput1 == PasswordInput2)
            {
                //password match
                MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_LOCK);
                MApp_ZUI_API_ShowWindow(HWND_MENU_LOCK_PAGE, SW_SHOW);
                MApp_ZUI_API_SetFocus(_hwndCommonDlgTargetFocus);

                //apply change...
                MApp_MenuFunc_Setup_BlockSysPassWord_Set(_MApp_ZUI_ACT_PasswordConvertToSystemFormat(PasswordInput1));
            }
            else
            {
                //password not match...
                _MApp_ZUI_ACT_OpenCommonDialog(EN_COMMON_DLG_MODE_MISMATCH_PASSWORD);
            }
            return TRUE;

        case EN_EXE_GOTO_AUDIO_LANG:
            MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_CLOSE, E_ZUI_STATE_TERMINATE);
            _enTargetMenuState = STATE_MENU_GOTO_OSDPAGE;
            MApp_OSDPage_SetOSDPage(E_OSD_AUDIO_LANGUAGE);
            return TRUE;

        case EN_EXE_SHOW_SOURCE_BANNER:
            MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_CLOSE, E_ZUI_STATE_TERMINATE);
            _enTargetMenuState = STATE_MENU_GOTO_INPUT_SOURCE;
            return TRUE;

        case EN_EXE_SHOW_VOLUME_INFO:				//Ray VOL 2017.03.09: Prepare to go to display volume info page
            MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_CLOSE, E_ZUI_STATE_TERMINATE);
            _enTargetMenuState = STATE_MENU_GOTO_VOLUME_INFO;
            return TRUE;

        case EN_EXE_GOTO_CHANNEL_LIST:
            MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_CLOSE, E_ZUI_STATE_TERMINATE);
            _enTargetMenuState = STATE_MENU_GOTO_CHANNEL_LIST;
            return TRUE;

        case EN_EXE_GOTO_FAVORITE_LIST:
             MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_CLOSE, E_ZUI_STATE_TERMINATE);
            _enTargetMenuState = STATE_MENU_GOTO_FAVORITE_LIST;
            return TRUE;

        case EN_EXE_EPG_SHOW_PROGRAMMEGUIDE_TIME_PAGE:
             MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_CLOSE, E_ZUI_STATE_TERMINATE);
            _enTargetMenuState = STATE_MENU_GOTO_EPG;
            return TRUE;

        case EN_EXE_SHOW_BRIEF_CH_INFO:
        //printf("EN_EXE_SHOW_BRIEF_CH_INFO start \r\n");
             MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_CLOSE, E_ZUI_STATE_TERMINATE);
            _enTargetMenuState = STATE_MENU_GOTO_INFO;
            //printf("EN_EXE_SHOW_BRIEF_CH_INFO end \r\n");
            return TRUE;

        case EN_EXE_EFFECT_POPUP:
            MApp_ZUI_API_PostMessage(MApp_ZUI_API_GetFocus(), MSG_EFFECT_POPUP, (WPARAM)NULL);
            return TRUE;

        case EN_EXE_EFFECT_SLIDEITEM:
            {
                HWND srchWnd = MApp_ZUI_API_GetFocus();
                MApp_ZUI_API_PostMessage(MApp_ZUI_API_GetFocus(), MSG_EFFECT_SLIDEITEM, srchWnd);
                return TRUE;
            }

        case EN_EXE_EFFECT_FLIPPAGE_LEFT:
        case EN_EXE_EFFECT_FLIPPAGE_RIGHT:
            {
                static HWND hwndTop[] =
                {
                	#ifdef sTriviewOSDStyle 	//Close Icon Page
                    //HWND_MENU_CHANNEL_PAGE,
                    HWND_MENU_PICTURE_PAGE,
		    HWND_MENU_OPTION_PAGE,		//Ray OSD 2017.04.19: Change option page as next page to picture page
                    HWND_MENU_SOUND_PAGE,
                    //HWND_MENU_APP_PAGE,  		//Ray DMP 2017.04.19: Disable APP page and user cannot access media player
                    //HWND_MENU_TIME_PAGE,
                		//#if ENABLE_DTV
                    //HWND_MENU_LOCK_PAGE,
                		//#endif                                  	
                	#else
                    HWND_MENU_CHANNEL_PAGE,
                    HWND_MENU_PICTURE_PAGE,
                    HWND_MENU_SOUND_PAGE,
                    HWND_MENU_TIME_PAGE,
                    HWND_MENU_OPTION_PAGE,
                		#if ENABLE_DTV
                    HWND_MENU_LOCK_PAGE,
                		#endif
                    HWND_MENU_APP_PAGE,
                  #endif  
                };

                HWND hwndFocus = MApp_ZUI_API_GetFocus();
                //printf("\nRay: Flippage current focus %d",hwndFocus);		//Ray DBG 2017.03.01
                HWND hwndEffect = hwndFocus;
                HWND hwndNext = HWND_INVALID;
                EN_FLIPPAGE dir = EN_FLIPPAGE_NONE;
                while ( (hwndEffect=MApp_ZUI_API_GetParent(hwndEffect)) != HWND_MAINFRAME )
                {
                    if ( MApp_ZUI_API_GetWindowProcId(hwndEffect) == EN_ZUI_FLIPPAGE_WINPROC )
                        break;
                }
                if ( hwndEffect == HWND_MAINFRAME )
                    return TRUE;

                U32 u32Data = MApp_ZUI_API_GetWindowData(hwndEffect);
                //printf("\nRay: WinData current focus %d",u32Data);		//Ray DBG 2017.03.01
                if ( u32Data == 0 )
                    return TRUE;

                U32 i;
                for (i=0; i<COUNTOF(hwndTop); i++)
                {
                    if ( hwndTop[i] == hwndEffect )
                        break;
                }
                if ( i >= COUNTOF(hwndTop) )
                    return TRUE;

                if (act == EN_EXE_EFFECT_FLIPPAGE_LEFT)
                {
                    if ( i < 1 )
                        i = COUNTOF(hwndTop) - 1;
                #if ENABLE_DTV
                    #if !ENABLE_ATSC_MENU_UI
                    else if((hwndTop[i]==HWND_MENU_APP_PAGE)&&(!IsDTVInUse()))
                        i-=2;
                    #endif
                #endif
                    else
                        i--;
                    hwndNext = hwndTop[i];
                    dir = EN_FLIPPAGE_LEFT;
                }
                else if (act == EN_EXE_EFFECT_FLIPPAGE_RIGHT)
                {
                    if ( i+1 >= COUNTOF(hwndTop) )
                        i = 0;
                #if ENABLE_DTV
                    #if !ENABLE_ATSC_MENU_UI
                    else if((hwndTop[i]==HWND_MENU_OPTION_PAGE)&&(!IsDTVInUse()))
                        i+=2;
                    #endif
                #endif
                    else
                        i++;
                    hwndNext = hwndTop[i];
                    dir = EN_FLIPPAGE_RIGHT;
                }

                HWND child, last_succ; //2008/4/12: get last successor once
                //HWND listwn = hwndNext+2;
                HWND listwn = hwndNext+1;	//Ray OSD 2017.03.01: Since we move the title down below page list.  So page list become next item (+1) to the MENU_XXXX_PAGE
                last_succ = MApp_ZUI_API_GetLastSuccessor(listwn);	//Ray OSD 2017.03.01: Read last item of menu. it read _GUI_WindowPositionList_Zui_Main_Menu auto-generated list 2nd item
                for (child = listwn+1; child <= last_succ; child++)	//Ray OSD 2017.03.01: Find out the 1st menu item which is EN_DL_STATE_NORMAL (non hidden item)
                {
                    if (MApp_ZUI_API_GetParent(child) != listwn)	//Ray OSD 2017.03.01: Read parent of menu (eg:HWND_MENU_PICTURE_PAGE). it read _GUI_WindowPositionList_Zui_Main_Menu auto-generated list 1st item
                        continue;

                    if (MApp_ZUI_ACT_QueryDynamicListItemStatus(child) != EN_DL_STATE_NORMAL)
                        continue;
                    else
                        break;
                }

                GUI_DATA_FLIPPAGE *windata = (GUI_DATA_FLIPPAGE *) u32Data;
                windata->pVarData->hwndCurrent = hwndEffect;
                windata->pVarData->hwndNext = hwndNext;
                //printf("\nRay: Flippage next page %d",hwndNext);		//Ray DBG 2017.03.01
/*
                if(windata->pVarData->hwndNext == HWND_MENU_LOCK_PAGE)
                {   // if focus on HWND_MENU_LOCK_PAGE, set focus on HWND_MENU_LOCK_TITLE
                    // Press Enter to invoke input password dialog and to input password to use HWND_MENU_LOCK_PAGE's functions.
                    child = windata->pVarData->hwndNext +1;
                }
*/
             #if ENABLE_DTV
                if(windata->pVarData->hwndNext == HWND_MENU_LOCK_PAGE)
                    MApp_MenuFunc_Setup_BlockSysEnterLockPage_Set(0);
             #endif
                if(child == last_succ)
                    windata->pVarData->hwndNextFocus = windata->pVarData->hwndNext+3;
                else
                    windata->pVarData->hwndNextFocus = child;
                windata->pVarData->dir = dir;
                //printf("\nRay: Flippage Send Message: next focus %d, last_succ %d",child,last_succ);		//Ray DBG 2017.03.01
                //MApp_ZUI_API_PostMessage(windata->pVarData->hwndCurrent, MSG_EFFECT, 0);
                MApp_ZUI_API_SendMessage(windata->pVarData->hwndCurrent, MSG_EFFECT, 0);	//Ray OSD 2017.03.01: MSG_EFFCT will be received by MApp_ZUI_ACT_FlipPageWinProc. It will set focus of windata->pVarData->hwndNextFocus
                MApp_ZUI_API_InvalidateWindow(HWND_MENU_MAIN_BOTTON_INFO_BAR);
                return TRUE;
            }

#if  0//NTV_FUNCTION_ENABLE//TODO
        case EN_EXE_CLEAR_CHLIST_BTN_YES:
            MApp_ChannelChange_DisableChannel(TRUE, MAIN_WINDOW);
            msAPI_CM_ResetAllProgram();
            MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_DTV_TUNING);
            return TRUE;
        case EN_EXE_CLEAR_CHLIST_BTN_NO:
            MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_GOTO_DTV_TUNING);
            return TRUE;
#endif

        default:
            //if (MApp_ZUI_API_IsWindowVisible(HWND_MENU_TIME_CLOCK_PAGE))
             //   return MApp_ZUI_ACT_ExecuteSetClockDialogAction(act);
            //if (MApp_ZUI_API_IsWindowVisible(HWND_MENU_TIME_OFFTIME_PAGE))
            //    return MApp_ZUI_ACT_ExecuteSetOffTimeDialogAction(act);
//            if (MApp_ZUI_API_IsWindowVisible(HWND_MENU_TIME_ONTIME_PAGE))
//                return MApp_ZUI_ACT_ExecuteSetOnTimeDialogAction(act);
            if (MApp_ZUI_API_IsWindowVisible(HWND_MENU_OPTION_AUDIOLANG_PAGE))
                return MApp_ZUI_ACT_ExecuteSetAudLangDialogAction(act);
        #if ENABLE_SUBTITLE
            if (MApp_ZUI_API_IsWindowVisible(HWND_MENU_OPTION_SUBLANG_PAGE))
                return MApp_ZUI_ACT_ExecuteSetSubLangDialogAction(act);
        #endif
            if (MApp_ZUI_API_IsWindowVisible(HWND_MENU_DLG_TUNE_CONFIRM))
                return MApp_ZUI_ACT_ExecuteTuningConfirmDialogAction(act);
            if (MApp_ZUI_API_IsWindowVisible(HWND_MENU_DLG_COMMON))
                return MApp_ZUI_ACT_ExecuteMenuCommonDialogAction(act);
            return MApp_ZUI_ACT_ExecuteMenuItemAction(act);

    }
    return FALSE;
}


///////////////////////////////////////////////////////////////////////////////
///  private  MApp_ZUI_ACT_GetMainMenuDynamicText
///  [OSD page handler] dynamic text content provider in MENU application
///
///  @param [in]       hwnd HWND     window handle we are processing
///
///  @return LPCTSTR     string content
///
///  @author MStarSemi @date 2007/1/25
///////////////////////////////////////////////////////////////////////////////
LPTSTR MApp_ZUI_ACT_GetMainMenuDynamicText(HWND hwnd)
{
  //  if (MApp_ZUI_API_IsSuccessor(HWND_MENU_TIME_CLOCK_PAGE, hwnd))
   //     return MApp_ZUI_ACT_GetSetClockDynamicText(hwnd);

  //  if (MApp_ZUI_API_IsSuccessor(HWND_MENU_TIME_OFFTIME_PAGE, hwnd))
   //     return MApp_ZUI_ACT_GetSetOffTimeDynamicText(hwnd);

   // if (MApp_ZUI_API_IsSuccessor(HWND_MENU_TIME_ONTIME_PAGE, hwnd))
    //    return MApp_ZUI_ACT_GetSetOnTimeDynamicText(hwnd);

    if (MApp_ZUI_API_IsSuccessor(HWND_MENU_OPTION_AUDIOLANG_PRIMARY, hwnd))
        return MApp_ZUI_ACT_GetSetAudLangDynamicText(hwnd);
#if ENABLE_SUBTITLE
    if (MApp_ZUI_API_IsSuccessor(HWND_MENU_OPTION_SUBLANG_PRIMARY, hwnd))
        return MApp_ZUI_ACT_GetSetSubLangDynamicText(hwnd);
#endif
    if (MApp_ZUI_API_IsSuccessor(HWND_MENU_DLG_TUNE_CONFIRM_TUNE_TYPE, hwnd))
        return MApp_ZUI_ACT_GetTuningConfirmDynamicText(hwnd);

    if (MApp_ZUI_API_IsSuccessor(HWND_MENU_DLG_TUNE_CONFIRM_COUNTRY_GRID, hwnd))
        return MApp_ZUI_CTL_GridGetDynamicText(HWND_MENU_DLG_TUNE_CONFIRM_COUNTRY_GRID, hwnd);

    if (MApp_ZUI_API_IsSuccessor(HWND_MENU_DLG_COMMON, hwnd))
        return MApp_ZUI_ACT_GetMenuCommonDynamicText(hwnd);

    if (MApp_ZUI_API_IsSuccessor(HWND_MENU_OPTION_OSDLANG_GRID, hwnd))
        return MApp_ZUI_CTL_GridGetDynamicText(HWND_MENU_OPTION_OSDLANG_GRID, hwnd);

    if (MApp_ZUI_API_IsSuccessor(HWND_MENU_OPTION_AUDIOLANG_GRID, hwnd))
        return MApp_ZUI_CTL_GridGetDynamicText(HWND_MENU_OPTION_AUDIOLANG_GRID, hwnd);

    if (MApp_ZUI_API_IsSuccessor(HWND_MENU_OPTION_SUBLANG_GRID, hwnd))
        return MApp_ZUI_CTL_GridGetDynamicText(HWND_MENU_OPTION_SUBLANG_GRID, hwnd);

    if (MApp_ZUI_API_IsSuccessor(HWND_MENU_TIME_TIMEZONE_GRID, hwnd))
        return MApp_ZUI_CTL_GridGetDynamicText(HWND_MENU_TIME_TIMEZONE_GRID, hwnd);

    if (MApp_ZUI_API_IsSuccessor(HWND_MENU_SINGLELIST_COMMON_PAGE, hwnd))
        return MApp_ZUI_ACT_GetSingleListDynamicText(hwnd);

    return MApp_ZUI_ACT_GetMenuItemDynamicText(hwnd);
}

///////////////////////////////////////////////////////////////////////////////
///  private  MApp_ZUI_ACT_GetMainMenuDynamicBitmap
///  [OSD page handler] dynamic bitmap content provider in MENU application
///
///  @param [in]       hwnd HWND     window handle we are processing
///
///  @return U16     bitmap index
///
///  @author MStarSemi @date 2007/1/25
///////////////////////////////////////////////////////////////////////////////

U16 MApp_ZUI_ACT_GetMainMenuDynamicBitmap(HWND hwnd, DRAWSTYLE_TYPE ds_type)
{
    ds_type = ds_type;
    switch(hwnd)
    {
    #if ( UI_SKIN_SEL == UI_SKIN_1920X1080X565 \
            || UI_SKIN_SEL == UI_SKIN_1366X768X565\
            || UI_SKIN_SEL == UI_SKIN_1366X768X4444\
            || UI_SKIN_SEL == UI_SKIN_1366X768X8888\
            || UI_SKIN_SEL == UI_SKIN_960X540X565\
            )
      #if ENABLE_ATSC_MENU_UI
        case HWND_MENU_CHANNEL_LIST_ITEM0_FAV:
        case HWND_MENU_CHANNEL_LIST_ITEM1_FAV:
        case HWND_MENU_CHANNEL_LIST_ITEM2_FAV:
        case HWND_MENU_CHANNEL_LIST_ITEM3_FAV:
        case HWND_MENU_CHANNEL_LIST_ITEM4_FAV:
        case HWND_MENU_CHANNEL_LIST_ITEM5_FAV:
        case HWND_MENU_CHANNEL_LIST_ITEM6_FAV:
        case HWND_MENU_CHANNEL_LIST_ITEM7_FAV:
        case HWND_MENU_CHANNEL_LIST_ITEM8_FAV:
        case HWND_MENU_CHANNEL_LIST_ITEM9_FAV:
        {
            U16 u16Value;
            u16Value = MApp_ChanProc_GetCurProgIndex();
            u16Value = MApp_ChanProc_CalculateCurPageBaseIdx( u16Value, MAX_NUM_OF_SRV_ITEM );
            u16Value += _MApp_ZUI_ACT_MenuChannelListWindowMapToIndex(hwnd);
            if(IS_FAV_CH_ATSC(u16Value))
            {
                if(ds_type == DS_NORMAL)
                    return E_BMP_IDLE_IMG_ICON_FAVORITE_UNFOCUS;
                else if(ds_type == DS_FOCUS)
                    return E_BMP_IDLE_IMG_ICON_FAVORITE_FOCUS;
            }
        }
            break;
        case HWND_MENU_CHANNEL_LIST_ITEM0_HIDE:
        case HWND_MENU_CHANNEL_LIST_ITEM1_HIDE:
        case HWND_MENU_CHANNEL_LIST_ITEM2_HIDE:
        case HWND_MENU_CHANNEL_LIST_ITEM3_HIDE:
        case HWND_MENU_CHANNEL_LIST_ITEM4_HIDE:
        case HWND_MENU_CHANNEL_LIST_ITEM5_HIDE:
        case HWND_MENU_CHANNEL_LIST_ITEM6_HIDE:
        case HWND_MENU_CHANNEL_LIST_ITEM7_HIDE:
        case HWND_MENU_CHANNEL_LIST_ITEM8_HIDE:
        case HWND_MENU_CHANNEL_LIST_ITEM9_HIDE:
        {
            U16 u16Value;
            u16Value = MApp_ChanProc_GetCurProgIndex();
            u16Value = MApp_ChanProc_CalculateCurPageBaseIdx( u16Value, MAX_NUM_OF_SRV_ITEM );
            u16Value += _MApp_ZUI_ACT_MenuChannelListWindowMapToIndex(hwnd);
            if(IS_HIDE_CH_ATSC(u16Value))
            {
                if(ds_type == DS_FOCUS)
                    return E_BMP_ICON_CHANNEL_SKIP_SEL;
                else
                    return E_BMP_ICON_CHANNEL_SKIP_UNSEL;
            }
        }
            break;

        case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV_NONE_ALL_BMP:
            if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_NONE & VCHIP_TVRATING_ALL)
            {
                if(MApp_ZUI_API_GetFocus()==HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV_NONE_ALL)
                    return E_BMP_tv_rating_all_focus_lock;
                else
                    return E_BMP_tv_rating_all_unfocus_lock;
            }
            break;

        case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVY_ALL_BMP:
            if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_Y & VCHIP_TVRATING_ALL)
            {
                if(MApp_ZUI_API_GetFocus()==HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVY_ALL)
                    return E_BMP_tv_rating_all_focus_lock;
                else
                    return E_BMP_tv_rating_all_unfocus_lock;
            }
            break;
        case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVY7_ALL_BMP:
            if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_Y7 & VCHIP_TVRATING_ALL)
            {
                if(MApp_ZUI_API_GetFocus()==HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVY7_ALL)
                    return E_BMP_tv_rating_all_focus_lock;
                else
                    return E_BMP_tv_rating_all_unfocus_lock;
            }
            break;
        case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVG_ALL_BMP:
            if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_G & VCHIP_TVRATING_ALL)
            {
                if(MApp_ZUI_API_GetFocus()==HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVG_ALL)
                    return E_BMP_tv_rating_all_focus_lock;
                else
                    return E_BMP_tv_rating_all_unfocus_lock;
            }
            break;
        case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_ALL_BMP:
            if((stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_PG & VCHIP_TVRATING_ALL)
        #if (!ENABLE_VCHIP_ALL_AS_AGEBASED)
                ||((stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_PG & VCHIP_TVRATING_V)
                && (stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_PG & VCHIP_TVRATING_S)
                && (stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_PG & VCHIP_TVRATING_L)
                && (stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_PG & VCHIP_TVRATING_D))
        #endif
                )
            {
                if(MApp_ZUI_API_GetFocus()==HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_ALL)
                    return E_BMP_tv_rating_all_focus_lock;
                else
                    return E_BMP_tv_rating_all_unfocus_lock;
            }
            break;
        case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_ALL_BMP:
            if((stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_14 & VCHIP_TVRATING_ALL)
        #if (!ENABLE_VCHIP_ALL_AS_AGEBASED)
                ||((stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_14 & VCHIP_TVRATING_V)
                && (stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_14 & VCHIP_TVRATING_S)
                && (stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_14 & VCHIP_TVRATING_L)
                && (stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_14 & VCHIP_TVRATING_D))
        #endif
        )
            {
                if(MApp_ZUI_API_GetFocus()==HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_ALL)
                    return E_BMP_tv_rating_all_focus_lock;
                else
                    return E_BMP_tv_rating_all_unfocus_lock;
            }
            break;
        case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_ALL_BMP:
            if((stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_MA & VCHIP_TVRATING_ALL)
          #if (!ENABLE_VCHIP_ALL_AS_AGEBASED)
                ||((stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_MA & VCHIP_TVRATING_V)
                && (stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_MA & VCHIP_TVRATING_S)
                && (stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_MA & VCHIP_TVRATING_L))
          #endif
          )
            {
                if(MApp_ZUI_API_GetFocus()==HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_ALL)
                    return E_BMP_tv_rating_all_focus_lock;
                else
                    return E_BMP_tv_rating_all_unfocus_lock;
            }
            break;
        case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVY7_FV_BMP:
            if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_Y7 & VCHIP_TVRATING_FV)
            {
                if(MApp_ZUI_API_GetFocus()==HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVY7_FV)
                    return E_BMP_tv_rating_fv_focus_lock;
                else
                    return E_BMP_tv_rating_fv_unfocus_lock;
            }
            break;
        case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_V_BMP:
            if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_PG & VCHIP_TVRATING_V)
            {
                if(MApp_ZUI_API_GetFocus()==HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_V)
                    return E_BMP_tv_rating_v_focus_lock;
                else
                    return E_BMP_tv_rating_v_unfocus_lock;
            }
            break;
        case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_V_BMP:
            if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_14 & VCHIP_TVRATING_V)
            {
                if(MApp_ZUI_API_GetFocus()==HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_V)
                    return E_BMP_tv_rating_v_focus_lock;
                else
                    return E_BMP_tv_rating_v_unfocus_lock;
            }
            break;
        case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_V_BMP:
            if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_MA & VCHIP_TVRATING_V)
            {
                if(MApp_ZUI_API_GetFocus()==HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_V)
                    return E_BMP_tv_rating_v_focus_lock;
                else
                    return E_BMP_tv_rating_v_unfocus_lock;
            }
            break;
        case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_S_BMP:
            if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_PG & VCHIP_TVRATING_S)
            {
                if(MApp_ZUI_API_GetFocus()==HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_S)
                    return E_BMP_tv_rating_s_focus_lock;
                else
                    return E_BMP_tv_rating_s_unfocus_lock;
            }
            break;
        case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_S_BMP:
            if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_14 & VCHIP_TVRATING_S)
            {
                if(MApp_ZUI_API_GetFocus()==HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_S)
                    return E_BMP_tv_rating_s_focus_lock;
                else
                    return E_BMP_tv_rating_s_unfocus_lock;
            }
            break;
        case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_S_BMP:
            if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_MA & VCHIP_TVRATING_S)
            {
                if(MApp_ZUI_API_GetFocus()==HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_S)
                    return E_BMP_tv_rating_s_focus_lock;
                else
                    return E_BMP_tv_rating_s_unfocus_lock;
            }
            break;
        case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_L_BMP:
            if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_PG & VCHIP_TVRATING_L)
            {
                if(MApp_ZUI_API_GetFocus()==HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_L)
                    return E_BMP_tv_rating_l_focus_lock;
                else
                    return E_BMP_tv_rating_l_unfocus_lock;
            }
            break;
        case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_L_BMP:
            if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_14 & VCHIP_TVRATING_L)
            {
                if(MApp_ZUI_API_GetFocus()==HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_L)
                    return E_BMP_tv_rating_l_focus_lock;
                else
                    return E_BMP_tv_rating_l_unfocus_lock;
            }
            break;
        case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_L_BMP:
            if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_MA & VCHIP_TVRATING_L)
            {
                if(MApp_ZUI_API_GetFocus()==HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVMA_L)
                    return E_BMP_tv_rating_l_focus_lock;
                else
                    return E_BMP_tv_rating_l_unfocus_lock;
            }
            break;
        case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_D_BMP:
            if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_PG & VCHIP_TVRATING_D)
            {
                if(MApp_ZUI_API_GetFocus()==HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TVPG_D)
                    return E_BMP_tv_rating_d_focus_lock;
                else
                    return E_BMP_tv_rating_d_unfocus_lock;
            }
            break;
        case HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_D_BMP:
            if(stGenSetting.g_VChipSetting.stVChipTVItem.Item_TV_14 & VCHIP_TVRATING_D)
            {
                if(MApp_ZUI_API_GetFocus()==HWND_MENU_LOCK_TVRATINGSUBPAGE_ITEM_TV14_D)
                    return E_BMP_tv_rating_d_focus_lock;
                else
                    return E_BMP_tv_rating_d_unfocus_lock;
            }
            break;
      #endif
    #endif
        default:
            //
            break;

    }
    return 0xFFFF; //for empty bitmap....
}

/////////////////////////////////////////////////////////
// Customize Window Procedures

///////////////////////////////////////////////////////////////////////////////
///  global  MApp_ZUI_ACT_ButtonAniClickWinProc
///  [MENU application customization] right bottom key icon animation
///
///  @param [in]       hwnd HWND     window handle we are processing
///  @param [in]       msg PMSG     message type
///
///  @return S32 message execute result
///
///  @author MStarSemi @date 2007/1/25
///////////////////////////////////////////////////////////////////////////////
S32 MApp_ZUI_ACT_ButtonAniClickWinProc(HWND hwnd, PMSG msg)
{
    switch(msg->message)
    {
        case MSG_PAINT:
            {
                //if a timer registered, then paint as pressing (focus state)
                if (MApp_ZUI_API_IsExistTimer(hwnd, 0))
                {
                    PAINT_PARAM * param = (PAINT_PARAM *)msg->wParam;
                    param->bIsFocus = TRUE;
                    DEFAULTWINPROC(hwnd, msg);
                    param->bIsFocus = FALSE;
                    return 0;
                }
            }
            break;

        case MSG_TIMER:
            {
                //if the time is up, kill the timer and then repaint again!
                MApp_ZUI_API_KillTimer(hwnd, 0);
                MApp_ZUI_API_InvalidateWindow(hwnd);
            }
            break;
        default:
            break;


    }

    return DEFAULTWINPROC(hwnd, msg);
}


///////////////////////////////////////////////////////////////////////////////
///  global  MApp_ZUI_ACT_ButtonAniClickChildWinProc
///  [MENU application customization] right bottom key icon animation (apply "focus" state if parent is button animation click
///
///  @param [in]       hwnd HWND     window handle we are processing
///  @param [in]       msg PMSG     message type
///
///  @return S32 message execute result
///
///  @author MStarSemi @date 2007/1/25
///////////////////////////////////////////////////////////////////////////////
S32 MApp_ZUI_ACT_ButtonAniClickChildWinProc(HWND hwnd, PMSG msg)
{
    switch(msg->message)
    {
        case MSG_PAINT:
            {
                HWND parent = MApp_ZUI_API_GetParent(hwnd);
                //if a timer registered, then paint as pressing (focus state)
                if (MApp_ZUI_API_IsExistTimer(parent, 0))
                {
                    PAINT_PARAM * param = (PAINT_PARAM *)msg->wParam;
                    param->bIsFocus = TRUE;
                    DEFAULTWINPROC(hwnd, msg);
                    param->bIsFocus = FALSE;
                    return 0;
                }
            }
            break;
        default:
            break;

    }

    return DEFAULTWINPROC(hwnd, msg);
}

S32 MApp_ZUI_ACT_Mainpage_DynamicListWinProc(HWND hWnd, PMSG pMsg)
{
    GUI_DATA_DYNAMIC_LIST * windata = (GUI_DATA_DYNAMIC_LIST*) GETWNDDATA(hWnd);

    //no dynamic list setting data...
    if (windata == 0 || windata->pVarData == 0)
        return DEFAULTWINPROC(hWnd, pMsg);

    switch (pMsg->message)
    {
        case MSG_NOTIFY_SHOW:
        case MSG_USER:
        case MSG_NOTIFY_KEYDOWN:
        case MSG_NOTIFY_HIDE:
            {
                MApp_ZUI_CTL_DynamicListWinProc(hWnd, pMsg);

                HWND child, last_succ, first, second;
                RECT rect_first, rect_second;
                last_succ = MApp_ZUI_API_GetLastSuccessor(hWnd);
                for (child = hWnd+1; child <= last_succ; child++)
                {
                    if ( hWnd != MApp_ZUI_API_GetParent(child) ) continue;
                    if ( FALSE == MApp_ZUI_API_IsWindowVisible(child) ) continue;
                    if ( MApp_ZUI_API_CountChildren(child) < 2 ) continue;
                    first = child + 1;
                    second = child + 2;
                    MApp_ZUI_API_GetWindowRect(first, &rect_first);
                    U16 u16TextIndex = _MApp_ZUI_API_FindFirstComponentIndex(first, DS_NORMAL, CP_TEXT_OUT);
                    DRAW_TEXT_OUT draw;
                    _MApp_ZUI_API_ConvertComponentToDynamic(CP_TEXT_OUT, u16TextIndex, &draw);
                    OSDClrBtn clrBtn;
                    LPTSTR pstr = MApp_ZUI_API_GetString(draw.StringID);
                    clrBtn.bStringIndexWidth = CHAR_IDX_2BYTE;
                    clrBtn.Fontfmt.flag = draw.flag;
                    clrBtn.Fontfmt.ifont_gap = draw.u8dis;
                    U16 u16Width = msAPI_OSD_GetStrWidth(Font[draw.eSystemFont].fHandle, (U8*)pstr, &clrBtn);
                    MApp_ZUI_API_GetWindowRect(second, &rect_second);
                    rect_second.left = rect_first.left + u16Width + 10 ;
                    MApp_ZUI_API_MoveWindow(second, &rect_second);
                }
            }
            return 0;

        default:
            break;
    }

    return MApp_ZUI_CTL_DynamicListWinProc(hWnd, pMsg);
}

COMMON_SINGLELIST_MODE MApp_ZUI_ACT_GetSingleListMode(void)
{
    return _eCommonSingleMode;
}

void _MApp_ZUI_ACT_CombineSleepTimerString(LPTSTR str, U32 TIMER)
{
    U32 u32SleepTime = TIMER;
    U8 u8SleepDigits = MApp_GetNoOfDigit(u32SleepTime);
    __MApp_UlongToString(u32SleepTime, str, u8SleepDigits);
    MApp_ZUI_API_LoadString(en_str_min, str + u8SleepDigits);
}

LPTSTR MApp_ZUI_ACT_GetSingleListDynamicText(HWND hwnd)
{
    U16 u16TempID = Empty;

    switch(hwnd)
    {
        case HWND_MENU_SINGLELIST_TITLE_OPTION:
            switch(_eCommonSingleMode)
            {
            #if ENABLE_ATSC_MENU_UI
                case EN_COMMON_SINGLELIST_MTS:
                    u16TempID = en_str_MTS;
                    break;
            #endif
                case EN_COMMON_SINGLELIST_ASPECT_RATIO:
                    u16TempID = en_str_Aspect_Ratio;
                    break;
                case EN_COMMON_SINGLELIST_NOISE_REDUCTION:
                    u16TempID = en_str_Noise_Reduction;
                    break;
                case EN_COMMON_SINGLELIST_MPEG_NOISE_REDUCTION:
                    u16TempID = en_str_MPEG_Noise_Reduction;
                    break;
                case EN_COMMON_SINGLELIST_SURROUND_SOUND:
                    u16TempID = en_str_Surround_Sound;
                    break;
                case EN_COMMON_SINGLELIST_TV_SPEAKER:
                    u16TempID = en_str_TV_Speaker;
                    break;
                case EN_COMMON_SINGLELIST_SLEEP_TIMER:
                    u16TempID = en_str_Sleep_Timer;
                    break;
                case EN_COMMON_SINGLELIST_AUTOSLEEP_TIMER:
                    u16TempID = en_str_Auto_Sleep_Timer;
                    break;
                case EN_COMMON_SINGLELIST_PARENTAL_GUIDANCE:
                    u16TempID = en_str_Parental_Guidance;
                    break;

            #if (ATSC_CC == ATV_CC)
                case EN_COMMON_SINGLELIST_CC_OPTION:
                    u16TempID = en_str_Caption;
                    break;
            #endif

            #if ENABLE_3D_PROCESS
                case EN_COMMON_SINGLELIST_3D_TYPE:
                    u16TempID = en_str_3D_Type;
                    break;
            #endif

            #if(ENABLE_SCART_SVIDEO)
                case EN_COMMON_SINGLELIST_SCART_IN:
                    u16TempID = en_str_Scart_In;
                    break;
            #endif

            #if ENABLE_ATSC_MENU_UI
                case EN_COMMON_SINGLELIST_OSD_TIMEZONE:
                    u16TempID = en_str_Time_Zone;
                break;
                case EN_COMMON_SINGLELIST_MENU_LANGUAGE:
                    u16TempID = en_str_Menu_Language;
                    break;
            #endif

                default:
                    break;
            }
            break;

        case HWND_MENU_SINGLELIST_ITEM1_OPTION:
            switch(_eCommonSingleMode)
            {
            #if ENABLE_ATSC_MENU_UI
                case EN_COMMON_SINGLELIST_MTS:
                    u16TempID = en_str_Mono;
                    break;
            #endif
                case EN_COMMON_SINGLELIST_ASPECT_RATIO:
		    u16TempID = en_str_Fill_Screen;		//Ray ART 2017.05.23: 1st item is Fill Screen in aspect ratio menu
                    //u16TempID = en_str_Auto;
                    break;
                case EN_COMMON_SINGLELIST_NOISE_REDUCTION:
                    u16TempID = en_str_Off;
                    break;
                case EN_COMMON_SINGLELIST_MPEG_NOISE_REDUCTION:
                    u16TempID = en_str_Off;
                    break;
                case EN_COMMON_SINGLELIST_SURROUND_SOUND:
                    u16TempID = en_str_Off;
                    break;
                case EN_COMMON_SINGLELIST_TV_SPEAKER:
                    u16TempID = en_str_TV_Speaker;
                    break;
                case EN_COMMON_SINGLELIST_SLEEP_TIMER:
                    u16TempID = en_str_Off;
                    break;
                case EN_COMMON_SINGLELIST_AUTOSLEEP_TIMER:
                    u16TempID = en_str_Nerver;
                    break;
                case EN_COMMON_SINGLELIST_PARENTAL_GUIDANCE:
                    u16TempID = en_str_Off;
                    break;

            #if (ATSC_CC == ATV_CC)
                case EN_COMMON_SINGLELIST_CC_OPTION:
                    u16TempID = en_str_Off;
                    break;
            #endif

            #if ENABLE_3D_PROCESS
                case EN_COMMON_SINGLELIST_3D_TYPE:
                    u16TempID = en_str_2D;
                    break;
            #endif

            #if(ENABLE_SCART_SVIDEO)
                case EN_COMMON_SINGLELIST_SCART_IN:
                    u16TempID = en_str_AV;
                    break;
            #endif
            #if ENABLE_ATSC_MENU_UI
                case EN_COMMON_SINGLELIST_OSD_TIMEZONE:
                    u16TempID = en_str_Atlantic;
                break;
                case EN_COMMON_SINGLELIST_MENU_LANGUAGE:
                    u16TempID = en_str_English;
                    break;
            #endif
                default:
                    break;
            }
            break;
        case HWND_MENU_SINGLELIST_ITEM2_OPTION:
             switch(_eCommonSingleMode)
            {
            #if ENABLE_ATSC_MENU_UI
                case EN_COMMON_SINGLELIST_MTS:
                    u16TempID = en_str_Stereo;
                    break;
            #endif
                case EN_COMMON_SINGLELIST_ASPECT_RATIO:
                    u16TempID = en_str_4colon3;
                    break;
                case EN_COMMON_SINGLELIST_NOISE_REDUCTION:
                    u16TempID = en_str_Low;
                    break;
                case EN_COMMON_SINGLELIST_MPEG_NOISE_REDUCTION:
                    u16TempID = en_str_Low;
                    break;
            #if (ENABLE_AUDIO_SURROUND_BBE == ENABLE )
                case EN_COMMON_SINGLELIST_SURROUND_SOUND:
                    u16TempID = en_str_BBE;
                    break;
            #endif


                case EN_COMMON_SINGLELIST_TV_SPEAKER:
                    u16TempID = en_str_External_Amp;
                    break;
                case EN_COMMON_SINGLELIST_SLEEP_TIMER:
                    _MApp_ZUI_ACT_CombineSleepTimerString(CHAR_BUFFER, 10);
                    return CHAR_BUFFER;
                case EN_COMMON_SINGLELIST_AUTOSLEEP_TIMER:
                    u16TempID = en_str_4Hours;
                    break;
                case EN_COMMON_SINGLELIST_PARENTAL_GUIDANCE:
                  #if ENABLE_SBTVD_BRAZIL_APP
                    return MApp_ZUI_API_GetU16String(EN_F4_LockSystem_Min+2);
                  #else
                    return MApp_ZUI_API_GetU16String(EN_F4_LockSystem_Min+1);
                  #endif

            #if (ATSC_CC == ATV_CC)
                case EN_COMMON_SINGLELIST_CC_OPTION:
                    u16TempID = en_str_CC_1;
                    break;
            #endif

            #if ENABLE_3D_PROCESS
                case EN_COMMON_SINGLELIST_3D_TYPE:
                    u16TempID = en_str_Frame_packing;
                    break;
            #endif

            #if(ENABLE_SCART_SVIDEO)
                case EN_COMMON_SINGLELIST_SCART_IN:
                    u16TempID = en_str_SdashVideo;
                    break;
            #endif

            #if ENABLE_ATSC_MENU_UI
                case EN_COMMON_SINGLELIST_OSD_TIMEZONE:
                    u16TempID = en_str_Eastern;
                break;
                case EN_COMMON_SINGLELIST_MENU_LANGUAGE:
                    u16TempID = en_str_French;
                    break;
            #endif
                default:
                    break;
            }
            break;
        case HWND_MENU_SINGLELIST_ITEM3_OPTION:
             switch(_eCommonSingleMode)
            {
            #if ENABLE_ATSC_MENU_UI
                case EN_COMMON_SINGLELIST_MTS:
                    u16TempID = en_str_SAP;
                    break;
            #endif
                case EN_COMMON_SINGLELIST_ASPECT_RATIO:
                    u16TempID = en_str_16colon9;
                    break;
                case EN_COMMON_SINGLELIST_NOISE_REDUCTION:
                    u16TempID = en_str_Middle;
                    break;
                case EN_COMMON_SINGLELIST_MPEG_NOISE_REDUCTION:
                    u16TempID = en_str_Middle;
                    break;

            #if (ENABLE_AUDIO_SURROUND_SRS == ENABLE )
                case EN_COMMON_SINGLELIST_SURROUND_SOUND:
                    u16TempID = en_str_SRS_TruSurround_XT;
                    break;
            #endif

                case EN_COMMON_SINGLELIST_SLEEP_TIMER:
                    _MApp_ZUI_ACT_CombineSleepTimerString(CHAR_BUFFER, 20);
                    return CHAR_BUFFER;

                case EN_COMMON_SINGLELIST_AUTOSLEEP_TIMER:
                    u16TempID = en_str_6Hours;
                    break;

                case EN_COMMON_SINGLELIST_PARENTAL_GUIDANCE:
                  #if ENABLE_SBTVD_BRAZIL_APP
                    return MApp_ZUI_API_GetU16String(EN_F4_LockSystem_Min+4);
                  #else
                    return MApp_ZUI_API_GetU16String(EN_F4_LockSystem_Min+2);
                  #endif

            #if (ATSC_CC == ATV_CC)
                case EN_COMMON_SINGLELIST_CC_OPTION:
                    u16TempID = en_str_CC_2;
                    break;
            #endif

            #if ENABLE_3D_PROCESS
                case EN_COMMON_SINGLELIST_3D_TYPE:
                    u16TempID = en_str_side_by_side;
                    break;
            #endif

            #if ENABLE_ATSC_MENU_UI
                case EN_COMMON_SINGLELIST_OSD_TIMEZONE:
                    u16TempID = en_str_Central;
                break;
                case EN_COMMON_SINGLELIST_MENU_LANGUAGE:
                    u16TempID = en_str_Spanish;
                    break;
            #endif
                default:
                    break;
            }
            break;
        case HWND_MENU_SINGLELIST_ITEM4_OPTION:
             switch(_eCommonSingleMode)
            {
                case EN_COMMON_SINGLELIST_ASPECT_RATIO:
		    u16TempID = en_str_1colon1;			//Ray ART 2017.05.23: Change to 1:1
                    //u16TempID = en_str_14colon9;
                    break;
                case EN_COMMON_SINGLELIST_NOISE_REDUCTION:
                    u16TempID = en_str_High;
                    break;
                case EN_COMMON_SINGLELIST_MPEG_NOISE_REDUCTION:
                    u16TempID = en_str_High;
                    break;
            #if (ENABLE_AUDIO_SURROUND_VDS  == ENABLE )
                case EN_COMMON_SINGLELIST_SURROUND_SOUND:
                    u16TempID = en_str_Dolby_Virtual;
                    break;
            #endif

                case EN_COMMON_SINGLELIST_SLEEP_TIMER:
                    _MApp_ZUI_ACT_CombineSleepTimerString(CHAR_BUFFER, 30);
                    return CHAR_BUFFER;

                case EN_COMMON_SINGLELIST_AUTOSLEEP_TIMER:
                    u16TempID = en_str_8Hours;
                    break;

                case EN_COMMON_SINGLELIST_PARENTAL_GUIDANCE:
                  #if ENABLE_SBTVD_BRAZIL_APP
                    return MApp_ZUI_API_GetU16String(EN_F4_LockSystem_Min+6);
                  #else
                    return MApp_ZUI_API_GetU16String(EN_F4_LockSystem_Min+3);
                  #endif

            #if (ATSC_CC == ATV_CC)
                case EN_COMMON_SINGLELIST_CC_OPTION:
                    u16TempID = en_str_CC_3;
                    break;
            #endif

            #if ENABLE_3D_PROCESS
                case EN_COMMON_SINGLELIST_3D_TYPE:
                    u16TempID = en_str_top_bottom;
                    break;
            #endif

            #if ENABLE_ATSC_MENU_UI
                case EN_COMMON_SINGLELIST_OSD_TIMEZONE:
                    u16TempID = en_str_Mountain;
                break;
                #ifdef sTriviewSupportOSDLanguage
                case EN_COMMON_SINGLELIST_MENU_LANGUAGE:
                    u16TempID = en_str_Germany;
                    break;                
                #endif    
            #endif
                default:
                    break;
            }
            break;
        case HWND_MENU_SINGLELIST_ITEM5_OPTION:
             switch(_eCommonSingleMode)
            {
                case EN_COMMON_SINGLELIST_ASPECT_RATIO:
                    u16TempID = en_str_Zoom1;
                    break;

                case EN_COMMON_SINGLELIST_NOISE_REDUCTION:
                    u16TempID = en_str_Default;
                    break;
                case EN_COMMON_SINGLELIST_MPEG_NOISE_REDUCTION:
                    u16TempID = en_str_Default;
                    break;
            #if (ENABLE_AUDIO_SURROUND_VSPK  == ENABLE )
                case EN_COMMON_SINGLELIST_SURROUND_SOUND:
                    u16TempID = en_str_Dolby_VS;
                    break;
            #endif


                case EN_COMMON_SINGLELIST_SLEEP_TIMER:
                    _MApp_ZUI_ACT_CombineSleepTimerString(CHAR_BUFFER, 60);
                    return CHAR_BUFFER;

                case EN_COMMON_SINGLELIST_PARENTAL_GUIDANCE:
                  #if ENABLE_SBTVD_BRAZIL_APP
                    return MApp_ZUI_API_GetU16String(EN_F4_LockSystem_Min+8);
                  #else
                    return MApp_ZUI_API_GetU16String(EN_F4_LockSystem_Min+4);
                  #endif

            #if (ATSC_CC == ATV_CC)
                case EN_COMMON_SINGLELIST_CC_OPTION:
                    u16TempID = en_str_CC_4;
                    break;
            #endif

            #if ENABLE_3D_PROCESS
                case EN_COMMON_SINGLELIST_3D_TYPE:
                    u16TempID = en_str_line_by_line;
                    break;
            #endif

            #if ENABLE_ATSC_MENU_UI
                case EN_COMMON_SINGLELIST_OSD_TIMEZONE:
                    u16TempID = en_str_Pacific;
                break;
                #ifdef sTriviewSupportOSDLanguage
                case EN_COMMON_SINGLELIST_MENU_LANGUAGE:
                    u16TempID = en_str_Italy;
                    break;                
                #endif                   
            #endif
                default:
                    break;
            }
            break;
        case HWND_MENU_SINGLELIST_ITEM6_OPTION:
             switch(_eCommonSingleMode)
            {
               //Ray ART 2017.05.23: Disable Zoom2
               /*
                case EN_COMMON_SINGLELIST_ASPECT_RATIO:
                    u16TempID = en_str_Zoom2;
                    break;
		*/
                case EN_COMMON_SINGLELIST_NOISE_REDUCTION:
                    u16TempID = en_str_Default;
                    break;

                case EN_COMMON_SINGLELIST_MPEG_NOISE_REDUCTION:
                    u16TempID = en_str_Default;
                    break;

                case EN_COMMON_SINGLELIST_SURROUND_SOUND:
                    u16TempID = en_str_Surround;
                    break;

                case EN_COMMON_SINGLELIST_SLEEP_TIMER:
                    _MApp_ZUI_ACT_CombineSleepTimerString(CHAR_BUFFER, 90);
                    return CHAR_BUFFER;

                case EN_COMMON_SINGLELIST_PARENTAL_GUIDANCE:
                  #if ENABLE_SBTVD_BRAZIL_APP
                    return MApp_ZUI_API_GetU16String(EN_F4_LockSystem_Min+10);
                  #else
                    return MApp_ZUI_API_GetU16String(EN_F4_LockSystem_Min+5);
                  #endif

            #if (ATSC_CC == ATV_CC)
                case EN_COMMON_SINGLELIST_CC_OPTION:
                    u16TempID = en_str_Text_1;
                    break;
            #endif

            #if ENABLE_3D_PROCESS
                case EN_COMMON_SINGLELIST_3D_TYPE:
                    u16TempID = en_str_Frame_alternative;
                    break;
            #endif

            #if ENABLE_ATSC_MENU_UI
                case EN_COMMON_SINGLELIST_OSD_TIMEZONE:
                    u16TempID = en_str_Alaska;
                break;
                #ifdef sTriviewSupportOSDLanguage
                case EN_COMMON_SINGLELIST_MENU_LANGUAGE:
                    u16TempID = en_str_Portuguese;
                    break;                
                #endif                  
            #endif
                default:
                    break;
            }
            break;

        case HWND_MENU_SINGLELIST_ITEM7_OPTION:
             switch(_eCommonSingleMode)
            {
               //Ray ART 2017.05.23: Disable Just Scan
               /*
                case EN_COMMON_SINGLELIST_ASPECT_RATIO:
                    u16TempID = en_str_Just_Scan;
                    break;
                */
                case EN_COMMON_SINGLELIST_SLEEP_TIMER:
                    _MApp_ZUI_ACT_CombineSleepTimerString(CHAR_BUFFER, 120);
                    return CHAR_BUFFER;
                case EN_COMMON_SINGLELIST_PARENTAL_GUIDANCE:
                    return MApp_ZUI_API_GetU16String(EN_F4_LockSystem_Min+6);

            #if (ATSC_CC == ATV_CC)
                case EN_COMMON_SINGLELIST_CC_OPTION:
                    u16TempID = en_str_Text_2;
                    break;
            #endif

            #if ENABLE_3D_PROCESS
                case EN_COMMON_SINGLELIST_3D_TYPE:
                    u16TempID = en_str_2D_to_3D;
                    break;
            #endif

            #if (ENABLE_AUDIO_SURROUND_DBX == ENABLE )
                case EN_COMMON_SINGLELIST_SURROUND_SOUND:
                    u16TempID = en_str_DBX;
                    break;
            #endif

            #if ENABLE_ATSC_MENU_UI
                case EN_COMMON_SINGLELIST_OSD_TIMEZONE:
                    u16TempID = en_str_Hawaii;
                break;
                #ifdef sTriviewSupportOSDLanguage
                case EN_COMMON_SINGLELIST_MENU_LANGUAGE:
                    u16TempID = en_str_Russian;
                    break;                
                #endif                 
            #endif
                default:
                    break;
            }
            break;
        case HWND_MENU_SINGLELIST_ITEM8_OPTION:
             switch(_eCommonSingleMode)
            {
               //Ray ART 2017.05.23: Disable Panorama
                /*
                case EN_COMMON_SINGLELIST_ASPECT_RATIO:
                    u16TempID = en_str_Panorama;
                    break;
                */
                case EN_COMMON_SINGLELIST_SLEEP_TIMER:
                    _MApp_ZUI_ACT_CombineSleepTimerString(CHAR_BUFFER, 180);
                    return CHAR_BUFFER;
                case EN_COMMON_SINGLELIST_PARENTAL_GUIDANCE:
                    return MApp_ZUI_API_GetU16String(EN_F4_LockSystem_Min+7);

            #if  (ATSC_CC == ATV_CC)
                case EN_COMMON_SINGLELIST_CC_OPTION:
                    u16TempID = en_str_Text_3;
                    break;
            #endif
                #ifdef sTriviewSupportOSDLanguage
                case EN_COMMON_SINGLELIST_MENU_LANGUAGE:
                    u16TempID = en_str_Chinese;
                    break;                
                #endif  
                default:
                    break;
            }
            break;
        case HWND_MENU_SINGLELIST_ITEM9_OPTION:
             switch(_eCommonSingleMode)
            {
                case EN_COMMON_SINGLELIST_SLEEP_TIMER:
                    _MApp_ZUI_ACT_CombineSleepTimerString(CHAR_BUFFER, 240);
                    return CHAR_BUFFER;
                case EN_COMMON_SINGLELIST_PARENTAL_GUIDANCE:
                    return MApp_ZUI_API_GetU16String(EN_F4_LockSystem_Min+8);

        #if  (ATSC_CC == ATV_CC)
                case EN_COMMON_SINGLELIST_CC_OPTION:
                    u16TempID = en_str_Text_4;
                    break;
        #endif
                    //Ray ART 2017.05.23: Disable Point to Point
                    /*
                case EN_COMMON_SINGLELIST_ASPECT_RATIO:
                    u16TempID = en_str_PointToPoint;
                    break;
                    */
                default:
                    break;
            }
            break;
        case HWND_MENU_SINGLELIST_ITEM10_OPTION:
             switch(_eCommonSingleMode)
            {
                case EN_COMMON_SINGLELIST_PARENTAL_GUIDANCE:
                    return MApp_ZUI_API_GetU16String(EN_F4_LockSystem_Min+9);
                default:
                    break;
            }
            break;
        case HWND_MENU_SINGLELIST_ITEM11_OPTION:
             switch(_eCommonSingleMode)
            {
                case EN_COMMON_SINGLELIST_PARENTAL_GUIDANCE:
                    return MApp_ZUI_API_GetU16String(EN_F4_LockSystem_Min+10);;
                default:
                    break;
            }
            break;
        case HWND_MENU_SINGLELIST_ITEM12_OPTION:
             switch(_eCommonSingleMode)
            {
                case EN_COMMON_SINGLELIST_PARENTAL_GUIDANCE:
                    return MApp_ZUI_API_GetU16String(EN_F4_LockSystem_Min+11);;
                default:
                    break;
            }
            break;
        case HWND_MENU_SINGLELIST_ITEM13_OPTION:
             switch(_eCommonSingleMode)
            {
                case EN_COMMON_SINGLELIST_PARENTAL_GUIDANCE:
                    return MApp_ZUI_API_GetU16String(EN_F4_LockSystem_Min+12);
                default:
                    break;
            }
            break;
        case HWND_MENU_SINGLELIST_ITEM14_OPTION:
             switch(_eCommonSingleMode)
            {
                case EN_COMMON_SINGLELIST_PARENTAL_GUIDANCE:
                    return MApp_ZUI_API_GetU16String(EN_F4_LockSystem_Min+13);
                default:
                    break;
            }
            break;
        case HWND_MENU_SINGLELIST_ITEM15_OPTION:
             switch(_eCommonSingleMode)
            {
                case EN_COMMON_SINGLELIST_PARENTAL_GUIDANCE:
                    return MApp_ZUI_API_GetU16String(EN_F4_LockSystem_Min+14);
                default:
                    break;
            }
            break;
        case HWND_MENU_SINGLELIST_ITEM16_OPTION:
             switch(_eCommonSingleMode)
            {
                case EN_COMMON_SINGLELIST_PARENTAL_GUIDANCE:
                    return MApp_ZUI_API_GetU16String(EN_F4_LockSystem_Min+15);
                default:
                    break;
            }
            break;
        default:
            break;
    }

    if (u16TempID != Empty)
        return MApp_ZUI_API_GetString(u16TempID);
    return 0; //for empty string....
}




#if ENABLE_SUBTITLE
BOOLEAN MApp_ZUI_ACT_ExecuteSetSubLangDialogAction(U16 act)
{
    switch(act)
    {
        case EN_EXE_SUBLANG_SET:
            MApp_MenuFunc_Setup_SubLanguage_Toggle();
            MApp_ZUI_API_InvalidateWindow(HWND_MENU_OPTION_SUBLANG_PRIMARY_OPTION);
            return true;

                  default:
             ZUI_DBG_FAIL(printf("[ZUI]SetSubtitleLangACT\n"));
             ABORT();
    }
    return FALSE;
}

LPTSTR MApp_ZUI_ACT_GetSetSubLangDynamicText(HWND hwnd)
{
    U16 u16TempID = Empty;

    switch(hwnd)
    {
        case HWND_MENU_OPTION_SUBLANG_PRIMARY_OPTION:
         {
            if(!MApp_MenuFunc_Setup_SubLanguage_Get())
                u16TempID=en_str_Primary;
            else
                u16TempID=en_str_Secondary;
            break;
         }
    }

   if (u16TempID != Empty)
             return MApp_ZUI_API_GetString(u16TempID);

   return 0; //for empty string....
}
#endif
void  MApp_ZUI_ACT_SetTargetMenuState(EN_MENU_STATE MenuState)
{
    _enTargetMenuState=MenuState;
}
#undef MAPP_ZUI_ACTMAINPAGE_C

S32 MApp_ZUI_ACT_UpDateCECDeviceWinProc(HWND hwnd, PMSG msg)
{
    switch (msg->message)
    {
        case MSG_TIMER:
            CEC_ZUI_DEBUG(printf("\n >> MApp_UPDATE_CEC_DEVICE_WINPROC \n"));
            MApp_ZUI_ACT_ExecuteMainMenuAction(EN_EXE_DISPLAY_CEC_DEVICE_LIST);
            MApp_ZUI_API_KillTimer (HWND_MENU_HDMI_CEC_DEVICE_SEARCHING, 0);
            break;

        default:
            break;
    }
    return DEFAULTWINPROC(hwnd, msg);
}

BOOLEAN MApp_ZUI_ACT_InitMainMenuCECDeviceList(void)
{
    U8 i= 0, j= 0;

    CEC_ZUI_DEBUG(printf("\n >> MApp_ZUI_ACT_InitMainMenuCECDeviceList \n"));

    if ( msAPI_CEC_GetDeviceTotalNum() > 0 )
    {
        CEC_ZUI_DEBUG(printf(" Index  Device  PhyAddr  Name \n"));
    }
    else
    {
        CEC_ZUI_DEBUG(printf(" No CEC device \n"));
        return FALSE;
    }

    g_stMenuCecDeviceList.u8CECDeviceNum = 0;

    msAPI_CEC_GetDeviceInfo(); //get all existed devices information (name, LA, PA)

    // Bubble Sort for order
    {
        bool swapped = true;
        MsCEC_DEVICELA enDeviceLATemp;
        WORD wPhyAddr;
        MS_U8 au8CecDeviceName[MAX_CEC_DEVICE_OSD_NAME];

        while (swapped)
        {
            swapped = false;
            j++;

            for (i = 0; i < (g_stMenuCecDeviceList.u8CECDeviceNum - j); i++)
            {
                if (g_stMenuCecDeviceList.wPhyAddr[i] > g_stMenuCecDeviceList.wPhyAddr[i + 1])
                {
                    enDeviceLATemp = g_stMenuCecDeviceList.aenDeviceLA[i];
                    g_stMenuCecDeviceList.aenDeviceLA[i] = g_stMenuCecDeviceList.aenDeviceLA[i + 1];
                    g_stMenuCecDeviceList.aenDeviceLA[i + 1] = enDeviceLATemp;

                    wPhyAddr = g_stMenuCecDeviceList.wPhyAddr[i];
                    g_stMenuCecDeviceList.wPhyAddr[i] = g_stMenuCecDeviceList.wPhyAddr[i + 1];
                    g_stMenuCecDeviceList.wPhyAddr[i + 1] = wPhyAddr;

                    memcpy(au8CecDeviceName, g_stMenuCecDeviceList.au8CecDeviceName[i], sizeof(g_stMenuCecDeviceList.au8CecDeviceName[i]));
                    memcpy(g_stMenuCecDeviceList.au8CecDeviceName[i], g_stMenuCecDeviceList.au8CecDeviceName[i + 1], sizeof(g_stMenuCecDeviceList.au8CecDeviceName[i + 1]));
                    memcpy(g_stMenuCecDeviceList.au8CecDeviceName[i + 1], au8CecDeviceName, sizeof(au8CecDeviceName));

                    swapped = true;
                }
            }
        }
    }


  #if CEC_ZUI_DEBUG_

    if ( g_stMenuCecDeviceList.u8CECDeviceNum > 0 )
    {
        ;//printf(" ----------------------------------- \n");
    }

    for (i=0; i<g_stMenuCecDeviceList.u8CECDeviceNum; i++)
    {
        //printf(" au8CecDeviceName = %s \n", g_stMenuCecDeviceList.au8CecDeviceName[i]);
        //printf(" aenDeviceLA = %u\n", g_stMenuCecDeviceList.aenDeviceLA[i]);
        //printf(" wPhyAddr = 0x%x \n", g_stMenuCecDeviceList.wPhyAddr[i]);
        ;
    }

    if ( g_stMenuCecDeviceList.u8CECDeviceNum > 0 )
    {
        ;//printf(" ----------------------------------- \n");
    }

    for(i=0; i<g_stMenuCecDeviceList.u8CECDeviceNum; i++)
    {
        ;//printf("Device %u PA: %u, LA: %u\n", i, g_stMenuCecDeviceList.wPhyAddr[i], g_stMenuCecDeviceList.aenDeviceLA[i]);
    }
    for(i=0; i<g_stMenuCecDeviceList.u8CECDeviceNum; i++)
    {
        ;//printf("= Device No.%u: %s =\n", i, g_stMenuCecDeviceList.au8CecDeviceName[i]);
    }
  #endif

    if ( g_stMenuCecDeviceList.u8CECDeviceNum > 0 )
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

BOOLEAN MApp_UiMainpage_Notify(MAINPAGE_NOTIFY_TYPE enMainpageNotify, U16 para1, U16 para2)
{
    BOOLEAN bResult = FALSE;
    para1 = para1;
    para2 = para2;
    switch (enMainpageNotify)
    {
        case EN_MAINPAGE_NOTIFY_STORE_FOCUS:
            MApp_ZUI_API_StoreFocusCheckpoint();
            break;

        case EN_MAINPAGE_NOTIFY_COMMON_DLG:
            {
                COMMON_DLG_MODE enDLG;
                switch(para1)
                {
                    case EN_NOTIFY_DLG_MODE_FACTORY_RESET:
                        enDLG = EN_COMMON_DLG_MODE_FACTORY_RESET;
                        break;
                    case EN_NOTIFY_DLG_MODE_FACTORY_RESET_CONFIRM:
                        enDLG = EN_COMMON_DLG_MODE_FACTORY_RESET_CONFIRM;
                        break;
                    case EN_NOTIFY_DLG_MODE_DIVX:
                        enDLG = EN_COMMON_DLG_MODE_DIVX;
                        break;
                    case EN_NOTIFY_DLG_MODE_DEACTIVATION:
                        enDLG = EN_COMMON_DLG_MODE_DEACTIVATION;
                        break;
                    case EN_NOTIFY_DLG_MODE_DEACTIVATION_CONFIRM:
                        enDLG = EN_COMMON_DLG_MODE_DEACTIVATION_CONFIRM;
                        break;
                    case EN_NOTIFY_DLG_MODE_SCAN_INPUT_PASSWORD:
                        enDLG = EN_COMMON_DLG_MODE_SCAN_INPUT_PASSWORD;
                        break;
                    case EN_NOTIFY_DLG_MODE_DTV_TUNING_INPUT_PASSWORD:
                        enDLG = EN_COMMON_DLG_MODE_DTV_TUNING_INPUT_PASSWORD;
                        break;
                    case EN_NOTIFY_DLG_MODE_ATV_TUNING_INPUT_PASSWORD:
                        enDLG = EN_COMMON_DLG_MODE_ATV_TUNING_INPUT_PASSWORD;
                        break;
                    case EN_NOTIFY_DLG_MODE_FACTORY_RESET_INPUT_PASSWORD:
                        enDLG = EN_COMMON_DLG_MODE_FACTORY_RESET_INPUT_PASSWORD;
                        break;
                    case EN_NOTIFY_DLG_MODE_DESIGN_RESET_INPUT_PASSWORD:
                        enDLG = EN_COMMON_DLG_MODE_DESIGN_RESET_INPUT_PASSWORD;
                        break;
                    case EN_NOTIFY_DLG_MODE_WRONG_PASSWORD:
                        enDLG = EN_COMMON_DLG_MODE_WRONG_PASSWORD;
                        break;
                    case EN_NOTIFY_DLG_MODE_MISMATCH_PASSWORD:
                        enDLG = EN_COMMON_DLG_MODE_MISMATCH_PASSWORD;
                        break;
                    case EN_NOTIFY_DLG_MODE_INPUT_PASSWORD:
                        enDLG = EN_COMMON_DLG_MODE_INPUT_PASSWORD;
                        break;
                    case EN_NOTIFY_DLG_MODE_SET_PASSWORD:
                        enDLG = EN_COMMON_DLG_MODE_SET_PASSWORD;
                        break;
                    case EN_NOTIFY_DLG_MODE_USB_NOT_DETECTED:
                        enDLG = EN_COMMON_DLG_MODE_USB_NOT_DETECTED;
                        break;
                    case EN_NOTIFY_DLG_MODE_CI_NO_MODULE:
                        enDLG = EN_COMMON_DLG_MODE_CI_NO_MODULE;
                        break;
                    case EN_NOTIFY_DLG_MODE_SW_FILE_NOT_DETECTED:
                        enDLG = EN_COMMON_DLG_MODE_SW_FILE_NOT_DETECTED;
                        break;
                    case EN_NOTIFY_DLG_MODE_USB_UPDATE_CONFIRM:
                        enDLG = EN_COMMON_DLG_MODE_USB_UPDATE_CONFIRM;
                        break;
                    case EN_NOTIFY_DLG_MODE_USB_UPGRADING:
                        enDLG = EN_COMMON_DLG_MODE_USB_UPGRADING;
                        break;
                    case EN_NOTIFY_DLG_MODE_ENTER_MENU_LOCK_PAGE_INPUT_PASSWORD:
                        enDLG = EN_COMMON_DLG_MODE_ENTER_MENU_LOCK_PAGE_INPUT_PASSWORD;
                        break;
                #if (ENABLE_ATSC)
                    case EN_NOTIFY_DLG_MODE_RESETRRT_CONFIRM:
                        enDLG = EN_COMMON_DLG_MODE_RESETRRT_CONFIRM;
                        break;
                #endif

                    default:
                        return bResult;
                }
                _MApp_ZUI_ACT_OpenCommonDialog(enDLG);
                if (para2 > 0)
                    MApp_ZUI_API_SetTimer(HWND_MENU_DLG_COMMON, 0, para2);
            }
            break;

        case EN_MAINPAGE_NOTIFY_GET_TUNNING_COUNTRY:
            return (U32)MApp_ZUI_ACT_GetTuningCountry();

        default:
            break;
    }
    return bResult;
}


