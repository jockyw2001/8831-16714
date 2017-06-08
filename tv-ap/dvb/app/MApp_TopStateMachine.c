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

#define MAPP_TOPSTATEMACHINE_C
/******************************************************************************/
/*                            Header Files                                    */
/******************************************************************************/
#include "Board.h"
#include "datatype.h"
#include "MsCommon.h"
#include "debug.h"
#include "apiXC.h"
#include "apiXC_Adc.h"
#include "msAPI_ATVSystem.h"
#include "msAPI_MailBox.h"
#include "MApp_Main.h"
#include "MApp_TopStateMachine.h"
#include "MApp_GlobalFunction.h"
#include "MApp_GlobalSettingSt.h"
#include "MApp_ChannelChange.h"
#include "MApp_ATV_Scan.h"
#include "MApp_TV.h"
#include "MApp_AnalogInputs.h"
#include "MApp_SignalMonitor.h"
#include "MApp_Standby.h"
#include "MApp_Scan.h"
#include "MApp_ZUI_ACTcoexistWin.h"

#if (ENABLE_DTV_EPG)
#include "mapp_epgdb_public.h"
#endif

#include "MApp_UiMenuDef.h"
#include "MApp_ZUI_Main.h"
#include "ZUI_tables_h.inl"
#include "MApp_Menu_Main.h"
#include "MApp_Install_Main.h"
#if ENABLE_DVBC
#include "MApp_CADTV_ManualTuning_Main.h"
#include "GPIO.h"
#endif
#include "MApp_DTV_ManualTuning_Main.h"
#include "MApp_ATV_ManualTuning_Main.h"
#include "MApp_InputSource_Main.h"
#if ENABLE_OAD
#include "MApp_OAD.h"
#endif
#if ENABLE_DMP
#include "MApp_DMP_Main.h"
#include "MApp_APEngine.h"
#include "mapp_mplayer.h"
#endif
#include "MApp_OSDPage_Main.h"

#if ENABLE_SUBTITLE
#include "MApp_Subtitle.h"
#endif


#if(ENABLE_PVR ==1)
    #include "MApp_PVR_Main.h"
    #include "MApp_PVR.h"
#endif

#if MHEG5_ENABLE
#include "MApp_MHEG5_Main.h"
#endif
#include "MApp_APEngine.h"
#include "MApp_UiEpg.h"

#include "msAPI_DTVSystem.h"
#if (CHANNEL_SCAN_AUTO_TEST)
#include "drvUartDebug.h"
#include "drvAUDIO.h"
#include "mapp_demux.h"
#include "msAPI_FreqTableDTV.h"
#include "MApp_Subtitle.h"
//ZUI_TODO: #include "MApp_UiMenuStr.h"
//ZUI_TODO: #include "MApp_UiMenuFunc.h"
#endif

#if (ENABLE_USB)
#include "MApp_USBDownload.h"
#endif

#if ENABLE_CI
#include "MApp_CIMMI.h"
#include "msAPI_CI.h"
#endif

#if (ENABLE_TTX)
#include "msAPI_TTX.h"
#include "mapp_ttx.h"
#endif
#include "MApp_MultiTasks.h"


#include "MApp_APEngine.h"
#include "msAPI_APEngine.h"
#include "MApp_InputSource.h"
#if ((BRAZIL_CC )|| (ATSC_CC == ATV_CC) || ENABLE_ATSC)
#include "mapp_closedcaption.h"
#endif

#if (ENABLE_DTV_EPG)
#include "MApp_EpgTimer.h"
#endif
#include "msAPI_FreqTableDTV.h"
#include "MApp_SaveData.h"

#ifdef CHIP_S7LD
#include "drvMIU.h"
#endif
#if NTV_FUNCTION_ENABLE
#include "MApp_ChList_Main.h"
#endif

#if (ENABLE_MHL == ENABLE)
#include "Mhl.h"
#include "msAPI_Timer.h"
U32 gU32MHLOSDTime=0;
bool bMHLOSDFlag=0;
#endif

#if(ENABLE_ATSC)
#include "MApp_Scan_ATSC.h"
#endif

#if ENABLE_ATSC_TTS
#include "MApp_TTSControlHandler.h"
#endif

#if (ENABLE_DTV_EPG && DTG_FREEVIEW_STANDBY)
    extern BOOLEAN MApp_FreeView_Standby_Switch(void);
#endif

/*****************************************************************************/
/*                                 Macro                                     */
/*****************************************************************************/
#if USER_DEBUG && BUILD_SYSDEBUG
extern void userdebug(void);
#define USERDBG(x)   x
#else
#define USERDBG(x)
#endif

#if SYSTEM_DEBUG && BUILD_SYSDEBUG
extern void sysdebug(void);
#define SYSDBG(x)   x
#else
#define SYSDBG(x)
#endif

#if ENABLE_MSTV_UART_DEBUG
#define UART_DEBUG()    if (msAPI_UART_DecodeCommand()) { msAPI_Timer_ResetWDT(); continue;}// stop main loop for debug
#else
#define UART_DEBUG()
#endif

#if (CHANNEL_SCAN_AUTO_TEST)
#define CHSCANTEST_MSG(x)    x

extern ScanAutoTestData g_ScanAutoTestData;
extern ScanAutoTestAU   g_ScanAutoTestAU;
extern U8               g_u8ScanAutoTestCmd;
extern U8               g_u8ScanAutoTestKey;
extern U8               g_u8TopStateChkCase;
extern U8               g_u8AUDbgCmd;
extern U8               PrnStrBuf[128];
/*#if ENABLE_S2
extern U16              u8RFCh;
#else
extern U8                u8RFCh;
#endif*/

extern void MApp_TV_ProcessUserInput(void);

#else
#define CHSCANTEST_MSG(x)
#endif
extern EN_OSD_TUNE_TYPE_SETTING eTuneType;
#if NTV_FUNCTION_ENABLE
extern EN_CHLIST_MODE _eChannelListMode;
#endif

/********************************************************************************/
/*                                Static                                        */
/********************************************************************************/
#if ENABLE_S2
EN_TOP_STATE enTopState;
#else
static EN_TOP_STATE enTopState;
#endif
static EN_TOP_STATE enTopStateBeforeScan;

#define DEBUG_TOP_STATE_MSG(x)       //  x

#if (CHANNEL_SCAN_AUTO_TEST)
static void _MApp_ScanAutoTest(void);
#endif

#if SYSTEM_DEBUG
static EN_TOP_STATE previousTopState = (EN_TOP_STATE)0xFF;
#endif

#if ENABLE_CEC
extern BOOLEAN bDuringChannelChange;
#endif
#if(ENABLE_S2)
extern EN_RET MApp_DishSetup_Main(void);
#endif

/********************************************************************************/
/*                                Function                                       */
/********************************************************************************/
void MApp_TopStateMachine(void)
{
#if ENABLE_ATSC_TTS
    static EN_TOP_STATE s_enLastTopState = STATE_TOP_APENGINE;
#endif

    #if STATE_PRINT
    if (u8KeyCode != KEY_NULL)
    {
        printf("\nMS:0x%x \n", enTopState);
    }
    #endif

    SYSDBG(sysdebug());

    MApp_PreProcessUserInput();

    MApp_UiMenu_ARCDiscWin_State();

    #if SYSTEM_DEBUG
    if ( enTopState != previousTopState )
    {
        printf("enTopState=%u\n", (U16)enTopState);
        previousTopState=enTopState;
    }
    #endif

    #if (CHANNEL_SCAN_AUTO_TEST)
    _MApp_ScanAutoTest();
    #endif

    #if ENABLE_CEC
    bDuringChannelChange = 0;
    #endif

#if ENABLE_ATSC_TTS
    if(( enTopState != s_enLastTopState ) && (enTopState != STATE_TOP_TTS))
    {
        printf("Top1: %u --> %u\n", s_enLastTopState, enTopState);
        s_enLastTopState = enTopState;
    }
#endif

    switch ( enTopState )
    {
#if ENABLE_ATSC_TTS
        case STATE_TOP_TTS:
        {
            switch (MApp_TTSControlHandler_Main())
            {
                case EXIT_TTS_EXIT:
                {
                    if (IsDTVInUse() || IsATVInUse())
                    {
                        if ((HWND_MENU_CHANNEL_AUTO_SCAN_ATSC == MApp_ZUI_API_GetFocus()) && (MApp_ZUI_GetActiveOSD() == E_OSD_MAIN_MENU))
                            enTopState = STATE_TOP_MENU;
                        else
                        {
                            if (s_enLastTopState != STATE_TOP_TTS)
                                enTopState = s_enLastTopState;
                            else
                                enTopState = STATE_TOP_TV;
                        }
                    }
                    else
                    {
                        enTopState = s_enLastTopState;
                    }
                }
                break;

                default:
                    enTopState = STATE_TOP_TTS;
                break;
            }
        }
        break;
#endif

        case STATE_TOP_TTX:
            DEBUG_TOP_STATE_MSG(printf("STATE_TOP_TTX\r\n "));

            // mheg_process is moved to multitask now.
            break;

        case STATE_TOP_ANALOG_SHOW_BANNER:
            DEBUG_TOP_STATE_MSG(printf("STATE_TOP_ANALOG_SHOW_BANNER\r\n "));

            switch(MApp_ChannelChange_ShowAnalogBanner())
            {
                case EXIT_CLOSE:
                    enTopState = STATE_TOP_DIGITALINPUTS;
                    break;

                default:
                    break;
            }
            break;

    #if ((BRAZIL_CC )|| (ATSC_CC == ATV_CC) || ENABLE_ATSC)
        case STATE_TOP_CLOSEDCAPTION:
            if(enCCFontStatus == CC_FONT_LOAD)
            {
                switch(MApp_ClosedCaption_Main())
                {
                    // If user press any key
                  #if ENABLE_ATSC
                    case EXIT_CLOSEDCAPTION_DONE:
                  #else
                    case EXIT_CLOSE:
                    case EXIT_CLOSEDCAPTION_NULL:
                    case EXIT_CLOSEDCAPTION_DONE:
                  #endif
                        enTopState = STATE_TOP_DIGITALINPUTS;//STATE_TOP_TV;
                    break;

                    default:
                        break;
                }
            }
            else
            {
                enCCFontStatus = CC_FONT_UNLOAD_SPEEDUP;
            }

            break;
    #endif


        case STATE_TOP_CHANNELCHANGE:
            #if ENABLE_CEC
            bDuringChannelChange = 1;
            #endif
            DEBUG_TOP_STATE_MSG(printf("STATE_TOP_CHANNELCHANGE\r\n"));

            switch(MApp_ChannelChange())
            {
                case EXIT_CLOSE:
                   #if (ENABLE_DTV_EPG && ENABLE_DVB)
                    MApp_Epg_SrvPriorityHandler(msAPI_CM_GetCurrentPosition(msAPI_CM_GetCurrentServiceType()));
                   #endif
                   #if ENABLE_CEC
                    bDuringChannelChange = 0;
                   #endif
                   enTopState = STATE_TOP_DIGITALINPUTS;
                    //MApp_ChannelChange_CheckBlockChannelPW();
                    break;

                default:
                    break;
            }
            break;


    #if(ENABLE_ATSC)
        case STATE_TOP_SCAN:
            switch (MApp_Scan())
            {
                case EXIT_SCAN_DONE:
                    u8ManualScanStatus = FALSE;
                  #ifdef AUTOSCAN_RETURN_MENU
                    if (bAutoScan_Return_Menu != TRUE)
                  #endif
                        MApp_ZUI_ACT_ShutdownOSD();
                    enTopState = STATE_TOP_CHANNELCHANGE;
                    break;

                case EXIT_SCAN_TRAN_STANDBY:
                    u8ManualScanStatus = FALSE;
                    enTopState = STATE_TOP_STDBY;
                    break;

                case EXIT_SCAN_TRAN_TV:
                    // the scan is triggered by stream change.
                    // but current program is not changed.
                    // no need to change channel
                    u8ManualScanStatus = FALSE;
                    enTopState = STATE_TOP_TV;
                    break;

                default:
                    break;
            }
            break;
    #endif

    #if ENABLE_DVB //ENABLE_DTV
        case STATE_TOP_DTV_SCAN:
          DEBUG_TOP_STATE_MSG(printf("STATE_TOP_DTV_SCAN\r\n"));
          #if ENABLE_SBTVD_BRAZIL_APP
            msAPI_ATV_SetCurrentAntenna(ANT_AIR);
          #endif
#if ENABLE_OAD
            if(bShowOadScanPage == TRUE)
            {
                switch ( MApp_OAD_Scan(&u8OADpercentage) )
                {
                    case EXIT_GOTO_CHANNELCHANGE:
                        enTopState = STATE_TOP_CHANNELCHANGE;
                        break;
                    default:
                        break;
                }
                break;
            }
            else
#endif
            {
            switch ( MApp_DTV_Scan() )
            {
                case EXIT_GOTO_PREVIOUS:
                    enTopState = enTopStateBeforeScan;  //for not closing tuing page immediately when tuining completely
                    //enTopState = STATE_TOP_MENU;
              break;

                case EXIT_GOTO_CHANNELCHANGE:
                    enTopState = STATE_TOP_CHANNELCHANGE;
                    break;

                case EXIT_GOTO_TV:
				#if ENABLE_S2
					if(IsS2InUse())
					{
						enTopStateBeforeScan = STATE_TOP_CHANNELCHANGE;
					}
				#endif
                    enTopState = enTopStateBeforeScan;
                    //enTopState = STATE_TOP_DIGITALINPUTS;
                    break;

                case EXIT_GOTO_STANDBY:
                    enTopState = STATE_TOP_STANDBY;
                    break;
              #if ENABLE_SBTVD_BRAZIL_APP
                case EXIT_GOTO_ATVSCAN:
                    enTopState = STATE_TOP_ATV_SCAN;
                    break;
              #endif
#if 0 //NTV_FUNCTION_ENABLE  //wait to do
                    case EXIT_GOTO_NTV_LIST:
                    {
                    //set FavoriteNetwork is 0 for defalut;
                        //msAPI_CM_Set_FavoriteNetwork(0);
                        //MApp_ZUI_ACT_ExecuteChannelListAction(EN_EXE_CLOSE_CURRENT_OSD);
                        //msAPI_CM_ArrangeDataManager(TRUE);
                        MApp_OSDPage_SetOSDPage(E_OSD_CHANNEL_LIST);
                        MApp_ChannelList_SetMode(MODE_NETWORK_CHLIST_TV);
                        enTopState = STATE_TOP_OSDPAGE;
                    }
                    break;
#endif

                default:
                    break;
            }
            break;
            }
    #endif // #if ENABLE_DTV

#if (ENABLE_UPDATE_MULTIPLEX_VIA_NIT)
        case STATE_TOP_SCAN_NEW_MUX:
            switch ( MApp_DTV_Scan_Update_Mux() )
            {
                case EXIT_GOTO_PREVIOUS:
                    enTopState = enTopStateBeforeScan;
                    break;
                case EXIT_GOTO_CHANNELCHANGE:
                    enTopState = STATE_TOP_CHANNELCHANGE;
                    break;
                case EXIT_GOTO_WAIT:
                    enTopState = STATE_TOP_DIGITALINPUTS;
                    break;
                case EXIT_GOTO_STANDBY:
                    enTopState = STATE_TOP_STANDBY;
                    break;
                case EXIT_GOTO_DTVSCAN:
                    enTopState = STATE_TOP_DTV_SCAN;
                default:
                    break;
            }
            break;
#endif

        case STATE_TOP_ATV_SCAN:
#if ENABLE_SBTVD_BRAZIL_APP
            msAPI_ATV_SetCurrentAntenna(ANT_AIR);
#endif
            switch(MApp_ATV_Scan())
            {
                case EXIT_GOTO_STANDBY:
                    enTopState = STATE_TOP_STANDBY;
                    break;

                case EXIT_GOTO_CHANNELCHANGE:
                    enTopState = STATE_TOP_CHANNELCHANGE;
                    break;

                case EXIT_GOTO_TV:
                    enTopState = STATE_TOP_DIGITALINPUTS;
                    break;

                case EXIT_GOTO_PREVIOUS:
                    enTopState = enTopStateBeforeScan;  //for not closing tuing page immediately when tuining completely
                    //enTopState = STATE_TOP_MENU;
                    break;

            #if ENABLE_DVB //ENABLE_DTV
                case EXIT_GOTO_DTVSCAN:
                    enTopState =STATE_TOP_DTV_SCAN;
                    MApp_ATV_Scan_State_Init();
                    MApp_Scan_State_Init();
                    break;
            #endif

            #if ENABLE_SBTVD_BRAZIL_APP
                case EXIT_GOTO_CATVSCAN:
                    enTopState = STATE_TOP_CATV_SCAN;
                    break;
            #endif
                default:
                    break;
            }
            break;

    #if ENABLE_SBTVD_BRAZIL_APP
        case STATE_TOP_CATV_SCAN:
            msAPI_ATV_SetCurrentAntenna(ANT_CATV);
            switch(MApp_ATV_Scan())
            {
                case EXIT_GOTO_STANDBY:
                    enTopState = STATE_TOP_STANDBY;
                    break;

                case EXIT_GOTO_CHANNELCHANGE:
                    enTopState = STATE_TOP_CHANNELCHANGE;
                    break;

                case EXIT_GOTO_TV:
                    enTopState = STATE_TOP_DIGITALINPUTS;
                    break;

                case EXIT_GOTO_PREVIOUS:
                    enTopState = enTopStateBeforeScan;  //for not closing tuing page immediately when tuining completely
                    //enTopState = STATE_TOP_MENU;
                    break;
            #if ENABLE_DTV
                case EXIT_GOTO_DTVSCAN:
                    enTopState =STATE_TOP_DTV_SCAN;
                    MApp_ATV_Scan_State_Init();
                    MApp_Scan_State_Init();
                    break;
            #endif
                default:
                    break;
            }
            break;
        #endif // #if ENABLE_SBTVD_BRAZIL_APP

        case STATE_TOP_DIGITALINPUTS:
        {
          #if 0   // Disable temporary to avoid hang up problem after power on for S2.
            MApp_USB_Download_Monitor();
          #endif
          DEBUG_TOP_STATE_MSG(printf("STATE_TOP_DIGITALINPUTS\r\n"));
            switch(MApp_TV())
            {
                case EXIT_GOTO_USB:
                    enTopState = STATE_TOP_USB_DOWNLOAD;
                    break;

            #if ENABLE_OAD
                case EXIT_GOTO_OAD:
                    enTopState = STATE_TOP_OAD;
                    break;
            #endif

               case EXIT_GOTO_MENU:
                    enTopState = STATE_TOP_MENU;
                    break;

                case EXIT_GOTO_INSTALLGUIDE:
                    enTopState = STATE_TOP_INSTALLGUIDE;
                    break;

                case EXIT_GOTO_STANDBY:
		    //printf("\nRay: STATE_TOP_DIGITALINPUTS to STATE_TOP_STANDBY");		//Ray DBG 2017.06.05
                    enTopState = STATE_TOP_STANDBY;
                    break;

                case EXIT_GOTO_CHANNELCHANGE:
                    enTopState = STATE_TOP_CHANNELCHANGE;
                    break;

            #if ((BRAZIL_CC )|| (ATSC_CC == ATV_CC) || ENABLE_ATSC)
                case EXIT_GOTO_CLOSEDCAPTION:
                    enTopState = STATE_TOP_CLOSEDCAPTION;
                    break;
            #endif

            #if ( ENABLE_SUBTITLE&&(SUBTITLE_WITH_OSD == FALSE) )
                case EXIT_GOTO_SUBTITLE:
                    enTopState = STATE_TOP_SUBTITLE;
                    break;
            #endif

                case EXIT_GOTO_EPG:
                    enTopState = STATE_TOP_EPG;
                    break;

                case EXIT_GOTO_INPUTSOURCE:
                    enTopState = STATE_TOP_INPUTSOURCE;
                    break;

                case EXIT_GOTO_OSDPAGE:
                    enTopState = STATE_TOP_OSDPAGE;
                    break;

            #if ( ENABLE_DVB_TAIWAN_APP || ENABLE_SBTVD_BRAZIL_APP || (TV_SYSTEM == TV_NTSC) )
                case EXIT_GOTO_SCAN:
                    enTopStateBeforeScan = STATE_TOP_DIGITALINPUTS;
                    enTopState = STATE_TOP_ATV_SCAN;
                    MApp_ATV_Scan_State_Init();
                    break;
            #endif

            #if ENABLE_CI
                case EXIT_GOTO_MMI:
                    //if(IsAnyTVSourceInUse()||IsAVInUse())
                    enTopState = STATE_TOP_MMI;
                    break;
            #endif

            #if ENABLE_DMP
                case EXIT_GOTO_DMP:
                    enTopState = STATE_TOP_DMP;
                    break;
            #endif

            #if (ENABLE_UPDATE_MULTIPLEX_VIA_NIT)
                case EXIT_GOTO_SCAN_NEW_MUX:
                    enTopStateBeforeScan = STATE_TOP_DIGITALINPUTS;
                    enTopState = STATE_TOP_SCAN_NEW_MUX;
                    MApp_DTV_Scan_Update_Mux_State_Init();
                    break;
            #endif

            #if ENABLE_ATSC
                case EXIT_GOTO_ATSC_SCAN:
                    enTopState = STATE_TOP_SCAN;
                    break;
            #endif
                default:
                    break;
            }
            break;
        }

        case STATE_TOP_MENU:
        {
            DEBUG_TOP_STATE_MSG(printf("STATE_TOP_MENU\r\n"));
            switch(MApp_Menu_Main())
            {
                case EXIT_CLOSE:
                {
                    if(IsAnyTVSourceInUse())
                    {
#if ENABLE_ATSC
                        enTopState = STATE_TOP_CHANNELCHANGE;
#else
                        enTopState = STATE_TOP_DIGITALINPUTS;
#endif
                    }
                    else
                    {
                        enTopState = STATE_TOP_DIGITALINPUTS;
                    }
                }
                break;

                case EXIT_GOTO_STANDBY:
                    enTopState = STATE_TOP_STANDBY;
                    break;

                case EXIT_GOTO_SCAN:
                {
                    enTopStateBeforeScan = STATE_TOP_MENU;

            #if (!ENABLE_DVBC_PLUS_DTMB_CHINA_APP)
                #if ENABLE_T_C_COMBO
                    if(IsDVBCInUse())//TODO need add DVB-C case
                    {
                        stGenSetting.stScanMenuSetting.u8DVBCTvConnectionType=EN_DVB_C_TYPE;
                        msAPI_CM_ResetAllProgram();
                        MApp_SaveScanMenuSetting();
                        msAPI_Tuner_SwitchSource((EN_DVB_TYPE)stGenSetting.stScanMenuSetting.u8DVBCTvConnectionType, TRUE);
                    }
                    else if(IsDVBTInUse())
                    {
                        stGenSetting.stScanMenuSetting.u8DVBCTvConnectionType=EN_DVB_T_TYPE;
                        MApp_SaveScanMenuSetting();
                        msAPI_Tuner_SwitchSource((EN_DVB_TYPE)stGenSetting.stScanMenuSetting.u8DVBCTvConnectionType, TRUE);
                    }
                    MApp_DVBType_SetPrevType((EN_DVB_TYPE)stGenSetting.stScanMenuSetting.u8DVBCTvConnectionType);
                  //#elif  DVB_T_C_DIFF_DB
                    //if(IsDVBCInUse())
                     //{
                     //   msAPI_CM_ResetAllProgram();
                     //   stGenSetting.stScanMenuSetting.u8DVBCTvConnectionType=EN_DVB_T_TYPE;
                     //   MApp_SaveScanMenuSetting();
                     //   msAPI_Tuner_SwitchSource((EN_DVB_TYPE)stGenSetting.stScanMenuSetting.u8DVBCTvConnectionType, TRUE);
                    //}
                 // #endif

                #endif // #if (!ENABLE_DVBC_PLUS_DTMB_CHINA_APP)
            #endif

                    if(stGenSetting.stScanMenuSetting.u8ScanType == SCAN_TYPE_AUTO)
                    {
                        // reset ATV CM and DTV CM
                    #if ( ENABLE_DVB_TAIWAN_APP || ENABLE_SBTVD_BRAZIL_APP )
                        if(msAPI_ATV_GetCurrentAntenna() == ANT_AIR)
                        {
                            msAPI_ATV_ResetChannelData(E_CHRESET_AIR);
                            msAPI_CM_ResetAllProgram();
                          #if (ENABLE_UPDATE_MULTIPLEX_VIA_NIT)
                            MApp_SI_ResetNetwork();
                          #endif
                        }
                        else
                        {
                            msAPI_ATV_ResetChannelData(E_CHRESET_CATV);
                        }
                    #elif ( TV_SYSTEM == TV_NTSC )
                        if(msAPI_ATV_GetCurrentAntenna() == ANT_AIR)
                        {
                            msAPI_ATV_ResetChannelData(E_CHRESET_AIR);
                          #if (ENABLE_UPDATE_MULTIPLEX_VIA_NIT)
                            MApp_SI_ResetNetwork();
                          #endif
                        }
                        else
                        {
                            msAPI_ATV_ResetChannelData(E_CHRESET_CATV);
                        }
                    #else
                      #if ENABLE_DTV
                      if(eTuneType==OSD_TUNE_TYPE_DTV_PLUS_ATV || eTuneType==OSD_TUNE_TYPE_ATV_ONLY)
                      {
                          msAPI_ATV_ResetChannelData();
                      }
                      #else
                        if(eTuneType==OSD_TUNE_TYPE_ATV_ONLY)
                            msAPI_ATV_ResetChannelData();
                      #endif
                      #if ENABLE_DTV
                        if(eTuneType==OSD_TUNE_TYPE_DTV_PLUS_ATV || eTuneType==OSD_TUNE_TYPE_DTV_ONLY)
                        {
						#if ENABLE_T_C_CHANNEL_MIX
							msAPI_CM_RemoveDTVProgramOfAntenna();
						#else
						#if ENABLE_OAD
							if(bShowOadScanPage == FALSE)
						#endif
							{
								msAPI_CM_ResetAllProgram();
							}
						#endif
                        }
                      #endif // #if ENABLE_DTV

                      #if (ENABLE_UPDATE_MULTIPLEX_VIA_NIT)
                        MApp_SI_ResetNetwork();
                      #endif
                    #endif

                    #if ENABLE_SBTVD_BRAZIL_APP
                        enTopState = STATE_TOP_DTV_SCAN;
                    #else
                    #if ENABLE_DVB

                        if(eTuneType == OSD_TUNE_TYPE_DTV_ONLY )
                        {
                            enTopState = STATE_TOP_DTV_SCAN;
                        }
                        else
                    #endif
                        {
                            enTopState = STATE_TOP_ATV_SCAN;
                        }
                    #endif

                    #if ENABLE_TTX_ACI
                        MApp_TTX_InitACI();
                    #endif
                    }
                #if ENABLE_DVBC
                    else if(stGenSetting.stScanMenuSetting.u8ScanType == SCAN_TYPE_NETWORK)
                    {
                        //eTuneType must == OSD_TUNE_TYPE_CADTV_ONLY
                        msAPI_CM_ResetAllProgram();
                        enTopState = STATE_TOP_DTV_SCAN;
                    }
                #endif
                    else
                    {
                        if(IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
                        {
                            enTopState = STATE_TOP_ATV_SCAN;
                        }
                        #if ENABLE_DVB
                        else
                        {
                            enTopState = STATE_TOP_DTV_SCAN;
                        }
                        #endif
                    }
                    MApp_ATV_Scan_State_Init();
                    MApp_Scan_State_Init();
                    break;
                }
            #if (ENABLE_DTV_EPG)
                case EXIT_GOTO_EPG:
                    enTopState = STATE_TOP_EPG;
                    break;
            #endif  //#if (ENABLE_DTV_EPG)

            #if (ENABLE_DTMB || ENABLE_DVBT || ENABLE_DVBC || ENABLE_ISDBT)
                case EXIT_GOTO_DTV_MANUALTUNING:
                    g_CurSignalStrength = 0;
                    enTopState = STATE_TOP_DTV_MANUAL_TUNING;
                    break;
            #endif

                case EXIT_GOTO_ATV_MANUALTUNING:
                    enTopState = STATE_TOP_ATV_MANUAL_TUNING;
                    break;

                case EXIT_GOTO_CHANNELCHANGE:
                    enTopState = STATE_TOP_CHANNELCHANGE;
                    break;

            #if ENABLE_CI
                case EXIT_GOTO_MMI:
                    enTopState = STATE_TOP_MMI;
                    break;
            #endif

            #if ENABLE_DMP
                case EXIT_GOTO_DMP:
                    enTopState = STATE_TOP_DMP;
                    break;
            #endif


            #ifdef ENABLE_KTV
                case EXIT_GOTO_KTV:
                    enTopState = STATE_TOP_KTV;
                    break;
            #endif

            #if(ENABLE_PVR ==1)
                case EXIT_GOTO_PVR_CHECK_FS:
                    enPvrState = STATE_PVR_CHECK_FS_INIT;
                    enTopState = STATE_TOP_PVR;
                    break;
            #endif

            #if ENABLE_DVBC
                 case EXIT_GOTO_CADTV_MANUALTUNING:
                    enTopState = STATE_TOP_CADTV_MANUAL_TUNING;
                    break;
            #endif

                case EXIT_GOTO_OSDPAGE:
                    enTopState = STATE_TOP_OSDPAGE;
                    break;

                case EXIT_GOTO_INPUTSOURCE:
                    enTopState = STATE_TOP_INPUTSOURCE;
                    break;

                case EXIT_GOTO_VOLUME:				//Ray VOL 2017.03.09: Exit STATE_TOP_MENU and enter into STATE_TOP_DIGITALINPUTS, which can process volume up/down
		    enTopState = STATE_TOP_DIGITALINPUTS;
	            MApp_ZUI_ACT_StartupOSD(E_OSD_AUDIO_VOLUME);	//Ray VOL 2017.03.09: Show volume page
	            //MApp_TV_ProcessAudioVolumeKey(KEY_VOLUME_PLUS);
	            MApp_AnalogInputs_ResetTimer(MAIN_WINDOW);
		    break;

                case EXIT_GOTO_INFO:
                    enTopState = STATE_TOP_ANALOG_SHOW_BANNER;
                    break;

			#if(ENABLE_S2)
                case EXIT_GOTO_DISHSETUP:
                    enTopState = STATE_TOP_DISHSETUP;
                    printf("EXIT_GOTO_DISHSETUP \r\n");
                    break;
			#endif

            #if ENABLE_ATSC
                case EXIT_GOTO_ATSC_SCAN:
                    enTopState = STATE_TOP_SCAN;
                    break;
            #endif

                default:
                    break;
            }
            break;
        }

	#if (ENABLE_S2)
       case STATE_TOP_DISHSETUP:
 			switch(MApp_DishSetup_Main())
            {
                case EXIT_GOTO_INPUTSOURCE:
                    enTopState = STATE_TOP_INPUTSOURCE;
                    break;
                case EXIT_CLOSE:
                    enTopState = STATE_TOP_DIGITALINPUTS;
                    break;

                case EXIT_GOTO_STANDBY:

                    enTopState = STATE_TOP_STANDBY;
                    break;

                case EXIT_GOTO_MENU:
                     enTopState = STATE_TOP_MENU;
			break;

                case EXIT_GOTO_DTVSCAN:
                     enTopState = STATE_TOP_DTV_SCAN;
			break;

                default:
                    break;
            }
            break;
	#endif// #if (ENABLE_S2)

#if(ENABLE_PVR ==1)
        case STATE_TOP_PVR:
            DEBUG_TOP_STATE_MSG(printf("STATE_TOP_PVR\r\n"));

            switch(MApp_PVR_Main())
            {
                case EXIT_CLOSE:
                    enTopState = STATE_TOP_DIGITALINPUTS;
                    break;

                case EXIT_GOTO_STANDBY:
                    enTopState = STATE_TOP_STANDBY;
                    break;

                case EXIT_GOTO_MENU:
                    enTopState = STATE_TOP_MENU;
                    break;

                default:
                    break;
            }
            break;
#endif

        case STATE_TOP_INSTALLGUIDE:
            DEBUG_TOP_STATE_MSG(printf("STATE_TOP_INSTALLGUIDE\r\n"));

            switch(MApp_InstallGuide_Main())
            {
                case EXIT_CLOSE:
                    enTopState = STATE_TOP_DIGITALINPUTS;
                break;

                case EXIT_GOTO_STANDBY:
                    enTopState = STATE_TOP_STANDBY;
                    break;

                case EXIT_GOTO_SCAN:
                    enTopStateBeforeScan = STATE_TOP_DIGITALINPUTS;
#if ENABLE_SBTVD_BRAZIL_APP
        #if ENABLE_DTV
                    enTopState = STATE_TOP_DTV_SCAN;
        #else
                    enTopState = STATE_TOP_ATV_SCAN;
        #endif
#else
                    enTopState = STATE_TOP_ATV_SCAN;
#if ENABLE_TTX_ACI
                    MApp_TTX_InitACI();
#endif
                    MApp_ATV_Scan_State_Init();
#endif
                    MApp_Scan_State_Init();
                    break;

                case EXIT_GOTO_EPG:
                    enTopState = STATE_TOP_EPG;
                    break;

                case EXIT_GOTO_CHANNELCHANGE:
                    enTopState = STATE_TOP_CHANNELCHANGE;
                    break;

            #if ENABLE_ATSC
                case EXIT_GOTO_ATSC_SCAN:
                    enTopState = STATE_TOP_SCAN;
                    break;
            #endif

                default:
                    break;

            }
            break;
#if (ENABLE_DTMB || ENABLE_DVBT || ENABLE_DVBC || ENABLE_ISDBT)
        case STATE_TOP_DTV_MANUAL_TUNING:
            switch(MApp_DTV_ManualTuning_Main())
            {
                case EXIT_CLOSE:
                    enTopState = STATE_TOP_DIGITALINPUTS;
                    break;

                case EXIT_GOTO_STANDBY:
                    enTopState = STATE_TOP_STANDBY;
                    break;

                case EXIT_GOTO_MENU:
                    enTopState = STATE_TOP_MENU;
                    break;

                case EXIT_GOTO_DTVSCAN:
#if 0//ENABLE_T_C_COMBO
                    msAPI_CM_ResetAllProgram();
#endif
                    enTopState = STATE_TOP_DTV_SCAN;
                    enTopStateBeforeScan = STATE_TOP_DTV_MANUAL_TUNING;

                    MApp_Scan_State_Init();
                    break;

#if 0 //NTV_FUNCTION_ENABLE // wait to do
                case EXIT_GOTO_NTV_LIST:
                {
                    //set FavoriteNetwork is 0 for defalut;
                    //msAPI_CM_Set_FavoriteNetwork(0);
                    //MApp_ZUI_ACT_ExecuteChannelListAction(EN_EXE_CLOSE_CURRENT_OSD);
                    //msAPI_CM_ArrangeDataManager(TRUE);
                    //MApp_ZUI_ACT_StartupOSD(E_OSD_CHANNEL_LIST);
                    MApp_OSDPage_SetOSDPage(E_OSD_CHANNEL_LIST);
                    MApp_ChannelList_SetMode(MODE_NETWORK_CHLIST_TV);
                    enTopState = STATE_TOP_OSDPAGE;
                }
                break;
#endif

                default:
                    break;


            }
            break;
#endif// #if ENABLE_DTV

        case STATE_TOP_ATV_MANUAL_TUNING:
            switch(MApp_ATV_ManualTuning_Main())
            {
                case EXIT_CLOSE:
                    enTopState = STATE_TOP_DIGITALINPUTS;
                    break;

                case EXIT_GOTO_STANDBY:
                    enTopState = STATE_TOP_STANDBY;
                    break;

                case EXIT_GOTO_MENU:
                    enTopState = STATE_TOP_MENU;
                    break;

                case EXIT_GOTO_ATVSCAN:
                    enTopState = STATE_TOP_ATV_SCAN;
                    enTopStateBeforeScan = STATE_TOP_ATV_MANUAL_TUNING;

                    MApp_Scan_State_Init();
                    break;

                default:
                    break;

            }
            break;
#if ENABLE_DTV
#if ENABLE_DVBC
        case STATE_TOP_CADTV_MANUAL_TUNING:
            switch(MApp_CADTV_ManualTuning_Main())
            {
                case EXIT_CLOSE:
                    enTopState = STATE_TOP_DIGITALINPUTS;
                    break;

                case EXIT_GOTO_STANDBY:
                    enTopState = STATE_TOP_STANDBY;
                    break;

                case EXIT_GOTO_MENU:
                    enTopState = STATE_TOP_MENU;
                    break;

                //case EXIT_GOTO_CADTV_MANUALTUNING:
                    //printf("\n Isaac  EXIT_GOTO_CADTV_MANUALTUNING \n");
                    //g_CurSignalStrength = 0;
                    //enTopState = STATE_TOP_CADTV_MANUAL_TUNING;

                    //break;
                case EXIT_GOTO_SCAN:

//#if ENABLE_T_C_COMBO
                    msAPI_CM_ResetAllProgram();
//#endif

                case EXIT_GOTO_CADTV_MANUALTUNING://CADTV manu tuning no need reset CM database
                    enTopState = STATE_TOP_DTV_SCAN;
                    enTopStateBeforeScan = STATE_TOP_CADTV_MANUAL_TUNING;
                    MApp_Scan_State_Init();
                    break;

                default:
                    break;
            }
            break;
#endif
#endif

        case STATE_TOP_INPUTSOURCE:
            DEBUG_TOP_STATE_MSG(printf("STATE_TOP_INPUTSOURCE\r\n "));

            switch(MApp_InputSource_Main())
            {
                case EXIT_CLOSE:
                    if(IsAnyTVSourceInUse())
                    {
                        enTopState = STATE_TOP_DIGITALINPUTS;
                    }
                #if ENABLE_DMP
                  #ifdef AP_COWORK
                    else if(MApp_APEngine_CheckAPStatus())
                    {
                            MApp_APEngine_Resume();

                        MApp_APEngine_RestoreGWIN();

                        enTopState = STATE_TOP_APENGINE;
                        MApp_APEngine_ClearRetVal();
                    }
                  #endif
                #endif
                    else
                    {
                        enTopState = STATE_TOP_DIGITALINPUTS;
                    }
                break;

                case EXIT_GOTO_STANDBY:
                    enTopState = STATE_TOP_STANDBY;
                    break;

#if ENABLE_DMP
                case EXIT_GOTO_DMP:
                    enTopState = STATE_TOP_DMP;
                    break;
#endif

#ifdef ENABLE_KTV
                case EXIT_GOTO_KTV:
                enTopState = STATE_TOP_KTV;
                break;
#endif

                case EXIT_GOTO_OSDPAGE:
                    enTopState = STATE_TOP_OSDPAGE;
                    break;

                case EXIT_GOTO_MENU:
                    enTopState = STATE_TOP_MENU;
                    break;

                case EXIT_GOTO_INFO:
                    enTopState = STATE_TOP_ANALOG_SHOW_BANNER;
                    break;

#ifdef ENABLE_YOUTUBE
                case EXIT_GOTO_YOUTUBE:
                    enTopState = STATE_TOP_APENGINE;
                    MApp_APEngine_ClearRetVal();
                    if(MApp_APEngine_CheckAPStatus() && (MApp_APEngine_GetnowBIN() == BIN_ID_CODE_AEON_YOUTUBE))
                    {
                        MApp_APEngine_Resume();

                        MApp_APEngine_RestoreGWIN();
                    }
                    else
                    {
                        MApp_APEngine_Start();
                        MApp_APEngine_RegisterByID(BIN_ID_CODE_AEON_YOUTUBE, FULL_HANDLE, ((BEON_MEM_MEMORY_TYPE & MIU1) ? (BEON_MEM_ADR | MIU_INTERVAL) : ( BEON_MEM_ADR)), BEON_MEM_LEN);
                        //msAPI_APEngine_AppRunByBinID(BIN_ID_CODE_AEON_YOUTUBE, ((BEON_MEM_MEMORY_TYPE & MIU1) ? (BEON_MEM_ADR | MIU_INTERVAL) : ( BEON_MEM_ADR)), BEON_MEM_LEN);
                    }
                    break;
#endif

#ifdef ENABLE_RSS
                case EXIT_GOTO_RSS:
                    enTopState = STATE_TOP_APENGINE;
                    MApp_APEngine_ClearRetVal();
                    if(MApp_APEngine_CheckAPStatus() && (MApp_APEngine_GetnowBIN() == BIN_ID_CODE_AEON_RSS))
                    {
                        MApp_APEngine_Resume();

                        MApp_APEngine_RestoreGWIN();

                    }
                    else
                    {
                        MApp_APEngine_Start();

                        MApp_APEngine_RegisterByID(BIN_ID_CODE_AEON_RSS, FULL_HANDLE, ((BEON_MEM_MEMORY_TYPE & MIU1) ? (BEON_MEM_ADR | MIU_INTERVAL) : ( BEON_MEM_ADR)), BEON_MEM_LEN);
                    }
                break;
#endif
                #ifdef ENABLE_GAME
                case EXIT_GOTO_GAME:
                    {
                        enTopState = STATE_TOP_APGAME;
                    }
                    break;
                #endif
#ifdef ENABLE_EXTENSION
                case EXIT_GOTO_EXTENSION:
                    {
                    }
                break;
#endif
                default:
                    break;
            }
            break;

#if ((ENABLE_ATSC)||(ENABLE_DTV_EPG))
        case STATE_TOP_EPG:
            switch(MApp_Epg_Main())
            {
                case EXIT_CLOSE:
                    enTopState = STATE_TOP_DIGITALINPUTS;
                    break;

                case EXIT_GOTO_MENU:
                    enTopState = STATE_TOP_MENU;
                    break;

                case EXIT_GOTO_STANDBY:
                    enTopState = STATE_TOP_STANDBY;
                    break;
                default:
                    break;

            }
            break;
#endif            
        case STATE_TOP_OSDPAGE:
          DEBUG_TOP_STATE_MSG(printf("STATE_TOP_OSDPAGE\r\n "));
          #if 0//NTV_FUNCTION_ENABLE //wait to do
            if(_eChannelListMode == MODE_NETWORK_CHLIST_TV)
            {
                MApp_SI_Disable_Auto_Update(TRUE);
            }
          #endif

            switch (MApp_OSDPage_Main())
            {
                case EXIT_CLOSE:
                    enTopState = STATE_TOP_DIGITALINPUTS;
                    break;

                case EXIT_GOTO_CHANNELCHANGE:
                    enTopState = STATE_TOP_CHANNELCHANGE;
                    break;

                case EXIT_GOTO_MENU:
                    enTopState = STATE_TOP_MENU;
                    break;

            
            #if ((ENABLE_ATSC)||(ENABLE_DTV_EPG))            
                case EXIT_GOTO_EPG:
                    enTopState = STATE_TOP_EPG;
                    break;
            #endif  //#if (ENABLE_DTV_EPG)

                case EXIT_GOTO_INPUTSOURCE:
                    enTopState = STATE_TOP_INPUTSOURCE;
                    break;

                case EXIT_GOTO_STANDBY:
                    enTopState = STATE_TOP_STANDBY;
                    break;
            #if ENABLE_DMP
                case EXIT_GOTO_DMP:
                    enTopState = STATE_TOP_DMP;
                    break;
            #endif
            #ifdef ENABLE_KTV
                case EXIT_GOTO_KTV:
                    enTopState = STATE_TOP_KTV;
                    break;
            #endif
                default:
                    break;
            }
            break;

    #if (ENABLE_USB)
        case STATE_TOP_USB_DOWNLOAD:
            /*
            switch(MApp_USB_Download_Main())
            {
                    case EXIT_USB_DOWNLOAD_TRAN_REBOOT:

                    break;
                    case EXIT_USB_DOWNLOAD_WAIT:
                    break;
                    case EXIT_USB_DOWNLOAD_CANCEL:
                        enTopState = STATE_TOP_DIGITALINPUTS;
                    break;

            }*/
            break;
    #endif

    #if ENABLE_OAD
       case STATE_TOP_OAD:
            switch (MApp_OAD_AppMain())
            {
                case EXIT_CLOSE:
                    enTopState = STATE_TOP_DIGITALINPUTS;
                    break;

                default:
                    break;
            }
        break;
    #endif

        case STATE_TOP_STANDBY:
            DEBUG_TOP_STATE_MSG(printf("STATE_TOP_STANDBY\r\n "));
            //printf("STATE_TOP_STANDBY\r\n ");		//Ray DBG 2017.06.05
            stGenSetting.stMiscSetting.bDCOnOff = EN_POWER_DC_OFF;

        #if ENABLE_DVBC
            if( IsDVBCInUse()
             && MApp_Scan_DVBC_QuickInstall_GetProcessedFlag()
              )
            {
								#ifdef #ifdef sNewAudioMuteStyle
								msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, 0, 0);
								#else            	
                MUTE_On();
                #endif
                MApi_PNL_SetBackLight(DISABLE);
                if (IsAnyTVSourceInUse())
                    MApp_ChannelChange_DisableChannel(TRUE, MAIN_WINDOW);
                else
                    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_PERMANENT_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);

                MApp_ZUI_ACT_ShutdownOSD();
                MApi_PNL_En(FALSE);

                MW_AUD_SetSoundMute(SOUND_MUTE_SPDIF, E_MUTE_ON);
                if (TRUE == MApp_Scan_DVBC_QuickInstall_ChList())
                {
                    MW_AUD_SetSoundMute(SOUND_MUTE_SPDIF, E_MUTE_OFF);
                    MApi_PNL_En(TRUE);
                    if (IsAnyTVSourceInUse())
                        MApp_ChannelChange_EnableChannel(MAIN_WINDOW);
                    else
                        msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_PERMANENT_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);

                    MApi_PNL_SetBackLight(ENABLE);
										#ifdef sNewAudioMuteStyle
										msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, stGenSetting.g_SoundSetting.Volume, 0);
										#else
										MUTE_Off();
										#endif
                    enTopState = STATE_TOP_DIGITALINPUTS;
                    u8KeyCode = KEY_NULL;
                    break;
                }
            }
        #endif // #if ENABLE_DVBC

        #if (ENABLE_DTV_EPG && DTG_FREEVIEW_STANDBY)
		#if(ENABLE_S2)
			if ( IsDTVInUse() || IsS2InUse())
		#else
            if(IsDTVInUse())
		#endif
            {
                if(MApp_FreeView_Standby_Switch())
                {
                    enTopState = STATE_TOP_DIGITALINPUTS;
                    u8KeyCode = KEY_NULL;
                    break;
                }
            }
        #endif

        #if ENABLE_OAD
            if(OSD_COUNTRY_SETTING != OSD_COUNTRY_NEWZEALAND)
            {
                if(IsDTVInUse()&& MApp_OAD_IsUserSelectOn())
                {
                    if((msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO)+ msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO)+msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO))>0)
                    {
                        if(FALSE == MApp_OAD_IsStandbyOffCheck())
                        {
                            MApp_OAD_Set_StandbyOffCheck(TRUE);
                            MApp_SI_Force_PMT_Parse();
                            MApp_SI_Force_NIT_Parse();
                            enTopState = STATE_TOP_DIGITALINPUTS;
                            u8KeyCode = KEY_NULL;
                        }
                        else
                        {
                            MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_STOP);
                        }
                        break;
                    }
                }
            }
        #endif // #if ENABLE_OAD

        #if 1
						#ifdef sUseSimplePowerShutDown
						enTopState = STATE_TOP_DIGITALINPUTS;			//Ray DPW 2017.06.05: Just go back to Digit input state in order to receive key
						/*
						if(sFlagSimPowerShutDown&0x10)
						{
						    printf("\nRay: STATE_TOP_STANDBY to STATE_TOP_DIGITALINPUTS");	//Ray DBG 2017.06.05
							enTopState = STATE_TOP_DIGITALINPUTS;
						}
						*/
						#endif	        
            MApp_Standby_Init();
        #else
            switch(MApp_Standby())
            {
                case EXIT_STANDBY_TRAN_CHANNELCHANGE:
                    if(IsAnyTVSourceInUse())
                    {
                        enTopState = STATE_TOP_CHANNELCHANGE;
                    }
                    else
                        enTopState = STATE_TOP_ANALOGINPUTS;
                    break;

                case EXIT_STANDBY_EXIT:
                    if(IsAnyTVSourceInUse())
                        enTopState = STATE_TOP_CHANNELCHANGE;
                    else
                    {
                        //enTopState = STATE_TOP_ANALOGINPUTS;
                        enTopState = STATE_TOP_ANALOG_SHOW_BANNER;
                    }
                    break;
            }
        #endif
            break;

    #if ( ENABLE_SUBTITLE&&(SUBTITLE_WITH_OSD == FALSE) )
        case STATE_TOP_SUBTITLE:
            DEBUG_TOP_STATE_MSG(printf("STATE_TOP_SUBTITLE\r\n "));
            enTopState = STATE_TOP_DIGITALINPUTS;
            switch(MApp_Subtitle_Main())
            {
                case EXIT_SUBTITLE_DECODING:
                    enTopState = STATE_TOP_SUBTITLE;
                    break;

                case EXIT_CLOSE:
                    enTopState = STATE_TOP_DIGITALINPUTS;
                    break;

                default:
                    enTopState = STATE_TOP_DIGITALINPUTS;
                    break;
            }
        #if (MHEG5_ENABLE && MHEG5_WITH_SUBTITLE)
            if (//( bIsBlocked == FALSE || bStopMonitorBlock == TRUE)
                    //&& IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(eWindow))
                    //&&
                    (msAPI_MHEG5_checkGoBackMHEG5()== FALSE))
            {
                // TODO...remove this! subtitle should co exist with dsmcc downloading
                MApp_TV_MHEG_Loading_Monitor();
            }
        #endif
            break;
    #endif //#ifdef SUBTITLE

#if ENABLE_CI
        case STATE_TOP_MMI:
            DEBUG_TOP_STATE_MSG(printf("STATE_TOP_MMI\r\n "));
            switch(MApp_CIMMI_Main())
            {
                case EXIT_CLOSE:
                    enTopState = STATE_TOP_DIGITALINPUTS;
                    break;
                case EXIT_GOTO_STANDBY:
                    enTopState = STATE_TOP_STANDBY;
                    break;
                default:
                    break;
            }
            break;
#endif

#if ENABLE_DMP
        case STATE_TOP_DMP:
            DEBUG_TOP_STATE_MSG(printf("STATE_TOP_DMP\r\n "));
            switch(MApp_DMP_Main())
            {
                case EXIT_MPLAYER_TRAN_MENU:
                    enTopState = STATE_TOP_MENU;
                    break;
                case EXIT_MPLAYER_TRAN_INPUTSOURCE:
                    enTopState = STATE_TOP_INPUTSOURCE;
                    break;
                case EXIT_MPLAYER_EXIT:
                    if(IsAnyTVSourceInUse())
                    {
                        #if 0
                        #if ENABLE_PVR
                        if(IsDTVInUse())
                        {
                            MApp_PVR_SetDiskDriveIndex(msAPI_PVRFS_GetDriveIndex()); //co-buffer issue, need to re-init buffer setting
                        }
                        #endif
                        #endif
                        enTopState = STATE_TOP_CHANNELCHANGE;
                    }
                    else
                    {
                        enTopState = STATE_TOP_DIGITALINPUTS;
                    }
                    break;

                case EXIT_MPLAYER_TRAN_STANDBY:
                    enTopState = STATE_TOP_STANDBY;
                    break;

                    default:
                        break;
            }
            break;
#endif// #if ENABLE_DMP

#if ENABLE_DMP
#ifdef AP_COWORK
        case STATE_TOP_APENGINE:
            DEBUG_TOP_STATE_MSG(printf("STATE_TOP_APENGINE\r\n "));
            #if 1
            switch( MApp_APEngine_CheckRetVal() )
            {
                case EXIT_GOTO_INPUTSOURCE:
                    enTopState = STATE_TOP_INPUTSOURCE;
                break;

                case EXIT_APENGINE_EXIT:
                    enTopState = STATE_TOP_INPUTSOURCE;
                break;

                case EXIT_GOTO_DMP:
                    enTopState = STATE_TOP_DMP;
                    break;

                case EXIT_GOTO_STANDBY:
                    enTopState = STATE_TOP_STANDBY;
                    break;

                default:
                    break;
            }
            #else
            switch ( MApp_APEngine_Process() )
            {
                case EXIT_APENGINE_EXIT:
                    enTopState = STATE_TOP_INPUTSOURCE;
                    break;
                default:
                    break;
            }
            #endif
            break;
#endif// #ifdef AP_COWORK
#endif


#ifdef ENABLE_KTV
        case STATE_TOP_KTV:
            switch(MApp_KTV_Main())
            {
                case EXIT_KTV_TRAN_MENU:
                    enTopState = STATE_TOP_MENU;
                    break;
                case EXIT_GOTO_INPUTSOURCE:
                    enTopState = STATE_TOP_INPUTSOURCE;
                    break;
                case EXIT_CLOSE:
                    enTopState = STATE_TOP_DIGITALINPUTS;
                    break;

                case EXIT_GOTO_STANDBY:
                    enTopState = STATE_TOP_STANDBY;
                    break;

                default:
                    break;
            }
            break;
#endif

#ifdef ENABLE_GAME
            case STATE_TOP_APGAME:
            {
                extern EN_RET MApp_Game_Browse_Main(void);
                switch((U8)MApp_Game_Browse_Main())
                 {
                     case EXIT_CLOSE:
                        MApp_InputSource_RestoreSource();
                    #if ENABLE_DMP
                        if(UI_INPUT_SOURCE_TYPE==UI_INPUT_SOURCE_DMP)
                        {
                            enTopState = STATE_TOP_DMP;
                        }
                        else
                    #endif
                        {
                            enTopState = STATE_TOP_DIGITALINPUTS;
                        }
                        break;

                     case EXIT_GOTO_STANDBY:
                         enTopState = STATE_TOP_STANDBY;
                         break;
                }
            }
            break;
#endif

        default:
            DEBUG_STATE(printf("\nMSerr:%bx ", enTopState));
            enTopState = STATE_TOP_DIGITALINPUTS;
            break;
    }

#if ENABLE_ATSC_TTS
    if(( enTopState != s_enLastTopState ) && (enTopState != STATE_TOP_TTS))
    {
        printf("Top2: %u --> %u\n", s_enLastTopState, enTopState);
        s_enLastTopState = enTopState;
    }
#endif

    #if (CHANNEL_SCAN_AUTO_TEST)
    if ( g_ScanAutoTestData.u2State == 2 )
    {
        DEBUG_STATE(printf("SCAN: Leave!\n"));
        CHSCANTEST_MSG(printf("SCAN: Stop Scan!\n"));
        g_ScanAutoTestData.u2State = 0;
        g_ScanAutoTestData.u12ChNum = 0;
        g_ScanAutoTestData.u16DTVProgNum = msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
        g_ScanAutoTestData.u16ATVProgNum = msAPI_CM_CountProgram(E_SERVICETYPE_ATV, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
        g_ScanAutoTestData.u16AudioProgNum = msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
    }
    #endif

    //2007/11/29: ZUI is a inter-state GUI service,
    //            so we don't have a specified state for it!
//    MApp_ZUI_MainTask();
#if (ENABLE_MHL == ENABLE)
        if(!msAPI_MHL_IsCbusConnected())
        {
            MApp_ZUI_MainTask();
            gU32MHLOSDTime = msAPI_Timer_GetTime0();
            bMHLOSDFlag=0;
        }
        else
        {
            if(bMHLOSDFlag==1)
                MApp_ZUI_MainTask();

            if(msAPI_Timer_DiffTimeFromNow(gU32MHLOSDTime)>2000 && bMHLOSDFlag==0)
            {
                MApp_ZUI_MainTask();
                bMHLOSDFlag=1;
            }
        }
#else
        MApp_ZUI_MainTask();
#endif

#if ENABLE_ATSC_TTS
    if (MApp_TTSControlIsOn())
    {
      if ((enTopState != STATE_TOP_SCAN) && (enTopState != STATE_TOP_CHANNELCHANGE))
       {
           enTopState = STATE_TOP_TTS;
       }

    }
#endif
}

EN_TOP_STATE MApp_TopStateMachine_GetTopState(void)
{
    return enTopState;
}

char* MApp_TopStateMachine_GetTopStateName(void)
{
    char* cTopStateName[] =
    {
        "CHANNELCHANGE",
        "DTV_SCAN",
        "ATV_SCAN",

    #if ENABLE_SBTVD_BRAZIL_APP
        "CATV_SCAN",
    #endif

        "DIGITALINPUTS",
        "MENU",
        "INSTALLGUIDE",
        "DTV_MANUAL_TUNING",
        "ATV_MANUAL_TUNING",
        "INPUTSOURCE",
        "STANDBY",
        "TTX",
        "ANALOG_SHOW_BANNER",

    #if (ENABLE_DTV_EPG)
        "EPG",
    #endif

        "OSDPAGE",
        "USB_DOWNLOAD",

    #if ENABLE_OAD
        "OAD",
    #endif

    #if (ENABLE_SUBTITLE)
        "SUBTITLE",
    #endif

    #if ENABLE_CI
        "MMI",
    #endif

        "DMP",

    #if ENABLE_DMP
        "APENGINE",
    #endif

    #ifdef ENABLE_BT
        "BT",
    #endif

    #ifdef ENABLE_KTV
        "KTV",
    #endif

    #ifdef ENABLE_GAME
        "APGAME",
    #endif

    #if(ENABLE_PVR ==1)
        "PVR",
    #endif

    #if ENABLE_DVBC
        "CADTV_MANUAL_TUNING",
    #endif

    #if ((BRAZIL_CC )|| (ATSC_CC == ATV_CC) || ENABLE_ATSC)
        "CLOSEDCAPTION",
    #endif

    #if (ENABLE_UPDATE_MULTIPLEX_VIA_NIT)
        "SCAN_NEW_MUX",
    #endif
    };
    return cTopStateName[enTopState];
}

void MApp_TopStateMachine_SetTopState_2(EN_TOP_STATE enSetTopState)
{
    enTopState = enSetTopState;
}

#if (CHANNEL_SCAN_AUTO_TEST)
//transfer 2bytes character to be 1byte character
U8* _Mapp_TransToPrintfStr(U8* pdest, U8* psrc)
{
    U8* pu8Str = pdest;
    U8* ptemp = psrc;

    *pu8Str = '\0';
    while(*(++ptemp) != 0)
    {
        *pu8Str++ = *ptemp++;
    }
    *pu8Str = '\0';

    return pdest;
}

U8 _Mapp_MAP2NUMKey(U8 no)
{
    U8 u8rtnKey;

    switch(no)
    {
    case 0:
        u8rtnKey = KEY_0;
        break;
    case 1:
        u8rtnKey = KEY_1;
        break;
    case 2:
        u8rtnKey = KEY_2;
        break;
    case 3:
        u8rtnKey = KEY_3;
        break;
    case 4:
        u8rtnKey = KEY_4;
        break;
    case 5:
        u8rtnKey = KEY_5;
        break;
    case 6:
        u8rtnKey = KEY_6;
        break;
    case 7:
        u8rtnKey = KEY_7;
        break;
    case 8:
        u8rtnKey = KEY_8;
        break;
    case 9:
        u8rtnKey = KEY_9;
        break;
    default:
        u8rtnKey = no;
        break;
    }

    return u8rtnKey;
}

void _MApp_ScanAutoTest(void)
{
    U16 i, k;
    U8  j;
    MS_TP_SETTING stTpSetting;
    U8 u8Data[2] = {0};

    MEMBER_SERVICETYPE bServiceType;
    AUD_INFO stAudioStreamInfo;

    if ((g_ScanAutoTestData.u2State == 0) && (g_ScanAutoTestData.fCommand == 1))
    {
        //printf("====enTopState %d enUiMainMenuState %d\n", enTopState, enUiMainMenuState);
        u16ScanDtvChNum=0;
        u16ScanRadioChNum=0;
        #if NORDIG_FUNC //for Nordig Spec v2.0
        u16ScanDataChNum = 0;
        #endif
        u8ScanPercentageNum=0;
        //u8RFCh=0;
        MApp_Scan_Set_CurRFChannel(0);
        stGenSetting.stScanMenuSetting.u8ScanType = SCAN_TYPE_AUTO;
        enTopState = STATE_TOP_MENU;
        // temply remove
        //enUiMainMenuState = STATE_UIMENU_GOTO_SCAN;
        g_ScanAutoTestData.u2State = 1;
    }

    if(g_u8ScanAutoTestCmd & SCAN_AUTOTEST_CMD_POLL)
    {
        // temply remove
        //CHSCANTEST_MSG(printf("SCAN: %u %bu\n", MApp_UiMenuFunc_GetU16DynamicNumber(EN_DNUM_GetenA1_ScanPerCentNumber), 100));
        g_u8ScanAutoTestCmd &= ~SCAN_AUTOTEST_CMD_POLL;
    }
    else if(g_u8ScanAutoTestCmd & SCAN_AUTOTEST_CMD_DUMP_ONE_CH_INFO)
    {
        i = g_ScanAutoTestData.u12ChNum;
        if(i >= g_ScanAutoTestData.u16DTVProgNum)
        {
            i -= g_ScanAutoTestData.u16DTVProgNum;
            bServiceType = E_SERVICETYPE_RADIO;
        }
        else
            bServiceType = E_SERVICETYPE_DTV;

        j = msAPI_CM_GetPhysicalChannelNumber(bServiceType, i);
        msAPI_DFT_GetTSSetting(j, &stTpSetting);
        for(u8Data[0] = 0; u8Data[0] < MAX_AUD_LANG_NUM ; u8Data[0]++)
        {
            msAPI_CM_GetAudioStreamInfo(bServiceType, i, &stAudioStreamInfo, u8Data[0]);
            if(stAudioStreamInfo.aISOLangInfo[0].bISOLangIndex == SI_LANGUAGE_UNKNOWN)
                break;
        }
        CHSCANTEST_MSG(printf("SCAN: CH %u %bu 0x%04x %bu %lu %bu %bu %bu %bu\n",
                g_ScanAutoTestData.u12ChNum,
                j,
                msAPI_CM_GetLogicalChannelNumber(bServiceType,i),
                0,
                stTpSetting.u32Frequency,
                0,
                stTpSetting.enBandWidth,
                u8Data[0],
                1
                ));
        if(u8Data[0] > 0)
        {
            for(u8Data[1] = 0; u8Data[1] < u8Data[0]; u8Data[1]++)
        {
                msAPI_CM_GetAudioStreamInfo(bServiceType, i, &stAudioStreamInfo, u8Data[1]);
                //if(u8Data[1] == 0) CHSCANTEST_MSG(printf("SCAN: LANG"));
               //     CHSCANTEST_MSG(printf(" %bu", stAudioStreamInfo.ToBeRemoved_u8AudLangCodeIdx));
        }
            if(u8Data[1] > 0) CHSCANTEST_MSG(printf("\n"));
        }

        g_u8ScanAutoTestCmd &= ~SCAN_AUTOTEST_CMD_DUMP_ONE_CH_INFO;

    }
    else if(g_u8ScanAutoTestCmd & SCAN_AUTOTEST_CMD_DUMP_ONE_CH_INFO2)
    {
        #if 0  // temply remove
        BYTE sName[120];
        bServiceType = msAPI_CM_GetCurrentServiceType();
        i = msAPI_CM_GetCurrentPosition(bServiceType);
        MApp_UiMenu_GetServiceNameToUCS2(bServiceType, i, (WORD*)sName, KEEP_CONTROL_CODE_NONE);
        Mapp_Main_TransToPrintfStr(PrnStrBuf, sName);
        u8Data[0] = MApp_Dmx_Check_Descriptor(TAG_SED);
        u8Data[0] = MApp_Dmx_Check_Descriptor(TAG_EED);
#if (ENABLE_TTX && ENABLE_SUBTITLE)
        CHSCANTEST_MSG(printf("SCAN: INFO %u,%bu,%bu,%bu,%bu\n",
                (i + 1),
                (U8)msAPI_TTX_TurnOnTTSource(),
                u8Data[0],
                u8Data[1],
                (u8SubtitleMenuNum > 0)));
#endif
        CHSCANTEST_MSG(printf("SCAN: AU %u,%bu\n", g_SrcInfo.u16H_CapSize, 0/*msAPI_AUD_GetCurrentSoundMode()*/));
        u8Data[0] = msAPI_CM_GetProgramAttribute(bServiceType, i, E_ATTRIBUTE_IS_SCRAMBLED);
        CHSCANTEST_MSG(printf("SCAN: NA %s,%bu\n", PrnStrBuf, u8Data[0]));
        Mapp_Main_TransToPrintfStr(PrnStrBuf, MApp_UiMenu_String(INFO_EVENTTITLETEXT));
        CHSCANTEST_MSG(printf("SCAN: EN %s\n", PrnStrBuf));
        #endif
        g_u8ScanAutoTestCmd &= ~SCAN_AUTOTEST_CMD_DUMP_ONE_CH_INFO2;
    }
    else if(g_u8ScanAutoTestCmd & SCAN_AUTOTEST_CMD_PLUSCHANGE_ONE_CH)
    {
        if(u8KeyCode == KEY_NULL)
        {
            //CHSCANTEST_MSG(printf("SCAN: CH change\n"));
            u8KeyCode = KEY_CHANNEL_PLUS;
            MApp_TV_ProcessUserInput();
            g_u8ScanAutoTestCmd &= ~SCAN_AUTOTEST_CMD_PLUSCHANGE_ONE_CH;
        }
    }
    else if(g_u8ScanAutoTestCmd & SCAN_AUTOTEST_CMD_SETKEY)
    {
        if(u8KeyCode == KEY_NULL)
        {
            u8KeyCode = _Mapp_MAP2NUMKey(g_u8ScanAutoTestKey);
            MApp_TV_ProcessUserInput();
            g_u8ScanAutoTestCmd &= ~SCAN_AUTOTEST_CMD_SETKEY;
        }
    }

    if(g_u8ScanAutoTestCmd & SCAN_AUTOTEST_CMD_CHK_MAINSTATE)
    {
        switch(g_u8TopStateChkCase)
        {
            case 0: //STATE_TOP_CHANNELCHANGE
                u8Data[0] = (enTopState == STATE_TOP_CHANNELCHANGE);
                break;
            case 1: //STATE_TOP_SCAN
                u8Data[0] = ((enTopState == STATE_TOP_DTV_SCAN) || (enTopState == STATE_TOP_DTV_SCAN)
                               /* || (enUiMainMenuState == STATE_UIMENU_GOTO_SCAN)*/);  // temply remove
                break;
            default:
                break;

        }
        if(u8Data[0])
            //CHSCANTEST_MSG(printf("SCAN: Check Ready %bu %bu %bu\n", u8Data[0], enTopState, enUiMainMenuState));
            CHSCANTEST_MSG(printf("SCAN: Check Ready %bu %bu\n", u8Data[0], enTopState));
        else
            //CHSCANTEST_MSG(printf("SCAN: Check Error %bu %bu %bu\n", u8Data[0], enTopState, enUiMainMenuState));
            CHSCANTEST_MSG(printf("SCAN: Check Error %bu %bu\n", u8Data[0], enTopState));

        g_u8ScanAutoTestCmd &= ~SCAN_AUTOTEST_CMD_CHK_MAINSTATE;
    }
    else if(g_u8ScanAutoTestCmd & SCAN_AUTOTEST_CMD_DUMP_MAINSTATE)
    {
        //CHSCANTEST_MSG(printf("SCAN: enTopState %bu,%bu\n", enTopState, enUiMainMenuState));
        CHSCANTEST_MSG(printf("SCAN: enTopState %bu\n", enTopState));
        g_u8ScanAutoTestCmd &= ~SCAN_AUTOTEST_CMD_DUMP_MAINSTATE;
    }

    if(g_u8AUDbgCmd & AUDIO_DEBUG_CMD_RWREG)
    {
        i = 0x2d00 + g_ScanAutoTestAU.u8RegStartAddr;
        j = g_ScanAutoTestAU.u8WriteData;
        k = g_ScanAutoTestAU.u8ReadBytes;
        if(g_ScanAutoTestAU.u8ReadBytes == 0)
            MDrv_AUDIO_DecWriteByte(i, j);                      // if have any problem, please contact with AudioTeam Cathy
        j = MDrv_AUDIO_DecReadByte(i);    //read for checking   //if have any problem, please contact with AudioTeam Cathy
        CHSCANTEST_MSG(printf("Audio: Set BK9 0x%04x 0x%02bx\n",i, j));
        if(k > 0)
            CHSCANTEST_MSG(printf("Audio: Data 0x"));
        while(k > 0)
        {
            j = MDrv_AUDIO_DecReadByte(i);                      //if have any problem, please contact with AudioTeam Cathy
            CHSCANTEST_MSG(printf("%02bx", j));
            i += 2;
            k--;
        }
        CHSCANTEST_MSG(printf("\n\n"));
        g_u8AUDbgCmd &= ~AUDIO_DEBUG_CMD_RWREG;
    }
}
#endif


#undef MAPP_TOPSTATEMACHINE_C

