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

#define MAPP_ZUI_ACTTUNECONFIRMFUNC_C
#define _ZUI_INTERNAL_INSIDE_ //NOTE: for ZUI internal


//-------------------------------------------------------------------------------------------------
// Include Files
//-------------------------------------------------------------------------------------------------
#include "Board.h"
#include "datatype.h"
#include "MsCommon.h"
#include "apiXC.h"
#include "apiXC_Adc.h"
#include "MApp_GlobalSettingSt.h"
#include "MApp_ZUI_Main.h"
#include "MApp_ZUI_APIcommon.h"
#include "MApp_ZUI_APIstrings.h"
#include "MApp_ZUI_APIwindow.h"
#include "ZUI_tables_h.inl"
#include "MApp_ZUI_APIgdi.h"
#include "MApp_ZUI_APIcontrols.h"
#include "MApp_ZUI_ACTmainpage.h"
#include "MApp_ZUI_ACTeffect.h"
#include "MApp_ZUI_APIdraw.h"
#include "MApp_ZUI_ACTglobal.h"
#include "OSDcp_String_EnumIndex.h"
#include "ZUI_exefunc.h"

#include "MApp_GlobalFunction.h"
#include "MApp_UiMenuDef.h"
#include "MApp_RestoreToDefault.h"
#include "MApp_ChannelChange.h"
#if ENABLE_DVBC
#include "MApp_Scan.h"
#endif
#if 0//ENABLE_T_C_COMBO
#include "MApp_ZUI_ACTcadtvmanualtuning.h"
#endif
////////////////////////////////////////////////////
//NOTE: when we are selecting country, don't modify the real one!!
static EN_OSD_COUNTRY_SETTING _eTuningCountry;
extern EN_OSD_TUNE_TYPE_SETTING eTuneType;

#if ENABLE_AUTOTEST
extern BOOLEAN g_bAutobuildDebug;
extern U16 tempcheck2;
// 7
U16 Country =0;

#endif

// the country list for installation and auto tuning
ST_OSD_SELECTION_STRING_MAPPING_LIST _ZUI_TBLSEG stAutoTuningCountryList[] =
{
#if ENABLE_EWS
    {OSD_COUNTRY_INDONESIA, en_str_Indonesia},
    {OSD_COUNTRY_MALAYSIA, en_str_Malaysia},
#endif
    {OSD_COUNTRY_AUSTRALIA, en_str_Australia},
    {OSD_COUNTRY_AUSTRIA, en_str_Austria},
    {OSD_COUNTRY_BELGIUM, en_str_Belgium},
    {OSD_COUNTRY_BULGARIA, en_str_Bulgaria},
    {OSD_COUNTRY_CROATIA, en_str_Croatia},
    {OSD_COUNTRY_CZECH, en_str_Czech},
    {OSD_COUNTRY_DENMARK, en_str_Denmark},
    {OSD_COUNTRY_FINLAND, en_str_Finland},
    {OSD_COUNTRY_FRANCE, en_str_France},
    {OSD_COUNTRY_GERMANY, en_str_Germany},
    {OSD_COUNTRY_GREECE, en_str_Greece},
    {OSD_COUNTRY_HUNGARY, en_str_Hungary},
    {OSD_COUNTRY_ITALY, en_str_Italy},
    {OSD_COUNTRY_IRELAND, en_str_Ireland},
    {OSD_COUNTRY_LUXEMBOURG, en_str_Luxembourg},
    {OSD_COUNTRY_NETHERLANDS, en_str_Netherlands},
    {OSD_COUNTRY_NORWAY, en_str_Norway},
    {OSD_COUNTRY_POLAND, en_str_Poland},
    {OSD_COUNTRY_PORTUGAL, en_str_Portugal},
    {OSD_COUNTRY_RUMANIA, en_str_Rumania},
    {OSD_COUNTRY_RUSSIA, en_str_Russian},
    {OSD_COUNTRY_SERBIA, en_str_Serbia},
    {OSD_COUNTRY_SLOVENIA, en_str_Slovenia},
    {OSD_COUNTRY_SPAIN, en_str_Spain},
    {OSD_COUNTRY_SWEDEN, en_str_Sweden},
    {OSD_COUNTRY_SWITZERLAND, en_str_Switzerland},
    {OSD_COUNTRY_UK, en_str_UK},
    {OSD_COUNTRY_UNITED_ARAB_EMIRATES, en_str_United_Arab_Emirates},
    {OSD_COUNTRY_NEWZEALAND, en_str_NewZealand},
    {OSD_COUNTRY_CHINA, en_str_China},
    {OSD_COUNTRY_ESTONIA, en_str_Estonia},
    {OSD_COUNTRY_TURKEY, en_str_Turkey},
    {OSD_COUNTRY_MOROCCO, en_str_Morocco},
    {OSD_COUNTRY_TUNIS, en_str_Tunis},
    {OSD_COUNTRY_ALGERIA, en_str_Algeria},
    {OSD_COUNTRY_EGYPT, en_str_Egypt},
    {OSD_COUNTRY_SOUTH_AFRICA, en_str_South_Africa},
    {OSD_COUNTRY_ISRAEL, en_str_Israel},
    {OSD_COUNTRY_IRAN, en_str_Iran},
    {OSD_COUNTRY_SLOVAKIA, en_str_Slovak},
    {OSD_COUNTRY_THAILAND, en_str_Thailand},
#if (ENABLE_DVB_TAIWAN_APP)
    {OSD_COUNTRY_TAIWAN, en_str_Taiwan},
#endif
#if (ENABLE_SBTVD_BRAZIL_APP)
    {OSD_COUNTRY_BRAZIL, en_str_Brazil},
#endif
};

BOOLEAN MApp_ZUI_ACT_ExecuteTuningConfirmDialogAction(U16 act)
{
    switch(act)
    {
        case EN_EXE_CLOSE_TUNING_CONFIRM:
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_TUNE_CONFIRM, SW_HIDE);

          #if 0//ENABLE_T_C_COMBO
            extern EN_DVB_TYPE MApp_DVBType_GetCurrentType(void);
            if(MApp_DVBType_GetCurrentType() == EN_DVB_T_TYPE)
            {
                MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_DVB_SELECT_MENU, SW_SHOW);
                MApp_ZUI_API_SetFocus(HWND_SELECTED_DVBT_BG);
            }
            else
                MApp_ZUI_ACT_ShowDVBCScanPage();

          #else
            MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_CHANNEL);
            MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_CHANNEL_AUTOTUNE);
          #endif
            //MApp_ZUI_API_PostMessage(HWND_MENU_DLG_TUNE_CONFIRM, MSG_EFFECT_ROLLUP, 0);
            return TRUE;

    #if 0//ENABLE_T_C_COMBO
        case EN_EXE_CLOSE_DVB_SELECT:
            MApp_ZUI_API_ShowWindow(HWND_MENU_DLG_DVB_SELECT_MENU, SW_HIDE);
            MApp_ZUI_ACT_ShowMainMenuBackground(HWND_MENU_BOTTOM_BALL_FOCUS_CHANNEL);
            MApp_ZUI_API_ShowWindow(HWND_MENU_CHANNEL_PAGE, SW_SHOW);
            MApp_ZUI_API_SetFocus(HWND_MENU_CHANNEL_AUTOTUNE);
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
            return TRUE;
    #endif

        /*case EN_EXE_DEC_TEMP_COUNTRY:
        case EN_EXE_INC_TEMP_COUNTRY:
            //from case MAPP_UIMENUFUNC_ADJUSTE2COUNTRY:
            _eTuningCountry = (EN_OSD_COUNTRY_SETTING)MApp_ZUI_ACT_DecIncValue_Cycle(
                act==EN_EXE_INC_TEMP_COUNTRY,
                _eTuningCountry, OSD_COUNTRY_AUSTRALIA, OSD_COUNTRY_NUMS-1, 1);

            MApp_ZUI_API_InvalidateWindow(HWND_MENU_DLG_TUNE_CONFIRM_COUNTRY_GRID);
            return TRUE;*/
        case EN_EXE_DEC_TUNE_TYPE:
        case EN_EXE_INC_TUNE_TYPE:
            //from case MAPP_UIMENUFUNC_ADJUSTE2COUNTRY:
            #if ENABLE_SBTVD_BRAZIL_APP
               /*
               eTuneType = (EN_OSD_TUNE_TYPE_SETTING)MApp_ZUI_ACT_DecIncValue_Cycle(
                    act==EN_EXE_INC_TUNE_TYPE,
                    eTuneType, OSD_TUNE_TYPE_AIR_PLUS_CABLE, OSD_TUNE_TYPE_NUMS-1, 1);
                */
                eTuneType = OSD_TUNE_TYPE_DTV_PLUS_ATV;
            #else
              #if 0//ENABLE_T_C_COMBO
                if(MApp_DVBType_GetCurrentType() == EN_DVB_C_TYPE)
                {
                    if(OSD_DVBC_TYPE_NETWOEKSCAN == MApp_DVBC_SCAN_GetCurrentType())
                    {
                        eTuneType = (EN_OSD_TUNE_TYPE_SETTING)OSD_TUNE_TYPE_DTV_ONLY;
                    }
                    else
                    {
                        eTuneType = (EN_OSD_TUNE_TYPE_SETTING)MApp_ZUI_ACT_DecIncValue_Cycle(
                        act==EN_EXE_INC_TUNE_TYPE,
                        eTuneType, OSD_TUNE_TYPE_DTV_PLUS_ATV, OSD_TUNE_TYPE_NUMS-1, 1);
                    }
                }
                else
              #endif
              #if (ENABLE_ATSC == DISABLE)
                {
                    eTuneType = (EN_OSD_TUNE_TYPE_SETTING)MApp_ZUI_ACT_DecIncValue_Cycle(
                    act==EN_EXE_INC_TUNE_TYPE,
                    eTuneType, OSD_TUNE_TYPE_DTV_PLUS_ATV, OSD_TUNE_TYPE_NUMS-1, 1);
                }
              #endif

            #endif

            MApp_ZUI_API_InvalidateWindow(HWND_MENU_DLG_TUNE_CONFIRM_TUNE_TYPE_OPTION);
            return TRUE;

        default:
            ZUI_DBG_FAIL(printf("[ZUI]CLOCKACT\n"));
            ABORT();
    }

    return FALSE;
}

///////////////////////////////////////////////////////////////////////////////
LPTSTR MApp_ZUI_ACT_GetTuningConfirmDynamicText(HWND hwnd)
{
    U16 u16TempID = Empty;

    switch(hwnd)
    {
        case HWND_MENU_DLG_TUNE_CONFIRM_TUNE_TYPE_OPTION:
            switch(eTuneType)
            {
            #if ENABLE_SBTVD_BRAZIL_APP
                case OSD_TUNE_TYPE_DTV_PLUS_ATV:
                    u16TempID = en_str_Air_plus_Cable;
                    break;
                default :
                    u16TempID = en_str_Air_plus_Cable;
                    break;
            #else
                case OSD_TUNE_TYPE_DTV_PLUS_ATV:
                    u16TempID = en_str_DTV_plus_ATV;
                    break;
                case OSD_TUNE_TYPE_DTV_ONLY:
                    u16TempID = en_str_DTV;
                    break;
                case OSD_TUNE_TYPE_ATV_ONLY:
                    u16TempID = en_str_ATV;
                    break;

              #if ENABLE_DVBC
                /*case OSD_TUNE_TYPE_CADTV_ONLY:
                    u16TempID = en_str_CADTV;
                    break;*/
              #endif

                default :
                    u16TempID = en_str_DTV_plus_ATV;
                    break;
            #endif
            }
            break;
    }

    if (u16TempID != Empty)
        return MApp_ZUI_API_GetString(u16TempID);

    return 0; //for empty string....
}

EN_OSD_COUNTRY_SETTING MApp_ZUI_ACT_GetTuningCountry(void)
{
    return _eTuningCountry;
}

void MApp_ZUI_ACT_SetTuningCountry(EN_OSD_COUNTRY_SETTING TuningCountry)
{
    _eTuningCountry = TuningCountry;
}

void MApp_ZUI_ACT_SetTuningCountryIndex(U8 u8Index)
{
    if (stAutoTuningCountryList[u8Index].u16SelectionItem >= OSD_COUNTRY_NUMS)
    {
        MS_DEBUG_MSG(printf("Set Country Overflow: %u\n", (U16)stAutoTuningCountryList[u8Index].u16SelectionItem));
        _eTuningCountry = DEFAULT_TUNING_COUNTRY;
    }
    else
    {
        _eTuningCountry = (EN_OSD_COUNTRY_SETTING)stAutoTuningCountryList[u8Index].u16SelectionItem;
    }
    MApp_ZUI_API_InvalidateWindow(HWND_MENU_DLG_TUNE_CONFIRM);
}

U8 MApp_ZUI_ACT_GetTuningCountryIndexMax(void)
{

   return (U8)(sizeof(stAutoTuningCountryList)/sizeof(stAutoTuningCountryList[0])) - 1;
}

U8 MApp_ZUI_ACT_GetTuningCountryIndex(void)
{
    U8 u8Index = 0;
    for (u8Index = 0; u8Index <= MApp_ZUI_ACT_GetTuningCountryIndexMax(); u8Index++)
    {
        if (_eTuningCountry == (EN_OSD_COUNTRY_SETTING)stAutoTuningCountryList[u8Index].u16SelectionItem)
        {
            return u8Index;
        }
    }
    return 0;
}

U16 MApp_ZUI_ACT_GetCountryStringID(EN_OSD_COUNTRY_SETTING country)
{
    U16 u16TempID = Empty;
    U8 u8Index = 0;
    for (u8Index = 0; u8Index <= MApp_ZUI_ACT_GetTuningCountryIndexMax(); u8Index++)
    {
        if (country == (EN_OSD_COUNTRY_SETTING)stAutoTuningCountryList[u8Index].u16SelectionItem)
        {
            u16TempID = stAutoTuningCountryList[u8Index].u16StringIndex;
        }
    }

  #if ENABLE_AUTOTEST
    if(g_bAutobuildDebug)
    {
        switch(tempcheck2)
        {
            case HWND_MENU_OPTION_COUNTRY_OPTION:
                if(Country != u16TempID)
                {
                    printf("73_Country\n");
                }
                Country = u16TempID;
                break;
            default:

                break;
        }
    }
  #endif
    return u16TempID;
}

LPTSTR MApp_ZUI_ACT_GetCountryStringByIndex(U8 u8Index)
{
    U16 u16TempID = Empty;
    if (u8Index > MApp_ZUI_ACT_GetTuningCountryIndexMax())
    {
        return 0;   //exceed country list count
    }

    u16TempID = stAutoTuningCountryList[u8Index].u16StringIndex;
    if (u16TempID != Empty)
        return MApp_ZUI_API_GetString(u16TempID);

    return 0; //for empty string....
}


#undef MAPP_ZUI_ACTTUNECONFIRMFUNC_C

