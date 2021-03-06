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
//
#define MAPP_SCAN_ATSC_C
////////////////////////////////////////////////////////////////////////////////
/// @file MApp_Scan_A.c
/// @author MStar Semiconductor Inc.
/// @brief Scan flow for APP layer
////////////////////////////////////////////////////////////////////////////////

//******************************************************************************
//                    Header Files
//******************************************************************************
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "Board.h"
#include "datatype.h"
#include "debug.h"
#include "msAPI_Global.h"
#include "apiDMX.h"
#include "msAPI_Memory.h"
#include "msAPI_MIU.h"
#include "msAPI_Timer.h"
#include "msAPI_OSD.h"
#include "msAPI_Tuner_ATSC.h"
#include "msAPI_Scan_ATSC.h"
#include "msAPI_VD.h"
#include "MApp_GlobalVar.h"
#include "MApp_Exit.h"
#include "MApp_Key.h"
#include "MApp_Psip.h"
#include "MApp_DataBase_ATSC.h"
#include "MApp_DataBase_CH.h"
#include "MApp_ScanMenu_ATSC.h"
#include "MApp_Scan.h"
#include "MApp_ChannelProc_ATSC.h"
#include "MApp_SignalMonitor.h"
#include "MApp_VDMode.h"
#include "MApp_ChannelChange.h"
#include "MApp_InputSource.h"
#include "MApp_DataBase_Gen.h"
#include "MApp_TV.h"
//NeedCheck
//#include "MApp_UiMenu.h"
#include "RF_Tuner_ATSC.h"
#include "MApp_ZUI_Main.h"
#include "MApp_ZUI_ACTglobal.h"
#include "ZUI_tables_h.inl"
#include "ZUI_exefunc.h"
#include "MApp_SaveData.h"
#include "msAPI_Video.h"
#include "MApp_GlobalFunction.h"
#include "msAPI_demux.h"
#include "msAPI_Demod_ATSC.h"
#include "mapi_cc_monitor.h"
#include "msAPI_VD.h"

#if(FRONTEND_IF_DEMODE_TYPE == MSTAR_INTERN_VIF)
#include "IF_Demodulator.h"
#endif
#if (CHANNEL_SCAN_AUTO_TEST)
#include "drvuart.h"
#include "Mapp_Main.h"

EN_TOP_STATE           g_enTopStateSave;
extern ScanAutoTestData g_ScanAutoTestData;
#endif

#if(CHAKRA3_AUTO_TEST)
#include "MApp_AutoTest.h"
#endif


#if (FRONTEND_TUNER_TYPE == NXP_TDA18275A_TUNER)
extern void TDA18275A_SetAGCsLoopOff(U8 u8Data);
BOOL g_bIsChScanning;
#endif

//********************************************************************************
//                     Macro
//********************************************************************************
#define SCAN_DBINFO_ATSC(y)         //y
#define NEW_SCAN_ATSC_DBG(y)        //y

#define ZigZag_Center_Point 0
#define ZigZag_Reft_Point   1

#if VIF_SCOPE_1M
#define ZigZag_Right_Point  2
#else
#define ZigZag_Right_Point  4
#endif

#define DESCRAMBLE_COUNT 30 // unit=10ms, 300ms
#define DESCRAMBLE_AC3_SYNCWORD_NUMBER 5
#define DESCRAMBLE_VIDEO_IFRAME_COUNT 5


//*************************************************************************
//          Enums
//*************************************************************************


//********************************************************************************
//                     Local
//********************************************************************************
static EN_SCAN_STATE enAtscSCanState = STATE_SCAN_INIT;
static EN_RET enAtscScanRetVal;
#if (ENABLE_PAT_TIMEOUT_NOSIGNAL)

static BOOLEAN f_PrevPatTimeOut = FALSE;
#endif
EN_TUNE2RF_SUB_STATE enAtscTune2RfSubState = VSB_SCAN_STATE;

static U8 u8RFCh=0, u8MaxRFCh=69;

EN_SCAN_CHANNEL_TYPE enScanChannelType = SCAN_ALL_CHANNEL;
static U16 u16NumOfVirCh2bShifted;
static U16 u16CurTsId, u16CurProgramNumber, u16PreTsId, u16PreProgramNumber;
static U8 u8CurPhyChIdx, u8CurVirChInfoIdx, u8PrePhyChIdx, u8PreVirChInfoIdx;
static U16 u16NumOfSrvAdd=0;
U16 u16NumOfNTSCSrvAdd=0;
U8 u8NumOfTimeOutProg=0;
#if (ASSIGN_NTSC_PROGRAM_AS_DEFAULT_CH == ENABLE)
U16 u16NumOfNoSignalNTSCSrvAdd=0;
static BOOLEAN fAddEmptyNTSCProg=FALSE;
#endif
#if (CHANNEL_ADD_AND_MERGE_FUNC==ENABLE)
U16 Auto_Scan_Add_CH_flag=0;
#endif

#if ENABLE_NEW_QAM_SCAN
static U8 Cable_Sys_Lock = CABLE_SYSTEM_STD;
static U8 u8FreqLockEver = 0;
#endif


BOOLEAN fScanTypeIsAuto = DISABLE;

static MS_VIRTUAL_CHANNEL *origPstSrvInfo;
static MS_VIRTUAL_CHANNEL stVirtualCh;

static MS_TP_SETTING_ATSC stTPSetting;
static MS_U8 fScanType;
static MS_U8 fChangeChannel;
static MS_U8 fSaveScrambleChannel;

static MS_VIRTUAL_CHANNEL_INFO *l_pastVirtualChInfo;
static MS_VIRTUAL_CHANNEL pstLastVirtualCh;
#if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
static MS_RF_CHANNEL_new stRfCh;
//static MS_RF_CHANNEL_new *pstLastRfCh;
#endif

static BOOLEAN bQamScan = TRUE;
static BOOLEAN bPidChang;
static MS_U8 u8LastScPatNum;

static void MApp_Scan_ProcessUserInput(void)
{
    switch(u8KeyCode)
    {
        case KEY_POWER:
                enAtscSCanState = STATE_SCAN_GOTO_STANDBY;
            break;
        case KEY_MENU:
                enAtscSCanState = STATE_SCAN_SCAN_END;

            break;
        case KEY_EXIT:
                enAtscSCanState = STATE_SCAN_SCAN_END;
            break;
        default:
            break;
    }
    u8KeyCode = KEY_NULL;
}

/*****************************************************************************/
BOOLEAN MApp_Scan_Init(void)
{
    SCAN_DBINFO_ATSC(printf(">> MApp_Scan_Init. ANT_TYPE=%u\n", ANT_TYPE));
    msAPI_SCAN_Init();


    //pastPATItem = (MS_PAT_ITEM_ATSC *) msAPI_Memory_Allocate(sizeof(MS_PAT_ITEM_ATSC) * MAX_VC_PER_PHYSICAL, BUF_ID_ATSC);
    pastVirtualCh = (MS_VIRTUAL_CHANNEL *) msAPI_Memory_Allocate(sizeof(MS_VIRTUAL_CHANNEL) * MAX_VC_PER_PHYSICAL,BUF_ID_ATSC);
    pastVirtualCh_VCT = (MS_VIRTUAL_VCT_CHANNEL *) msAPI_Memory_Allocate(sizeof(MS_VIRTUAL_VCT_CHANNEL) * MAX_VC_PER_PHYSICAL,BUF_ID_ATSC);
    pastVirtualChInfo = (MS_VIRTUAL_CHANNEL_INFO *) msAPI_Memory_Allocate(sizeof(MS_VIRTUAL_CHANNEL_INFO) * MAX_VC_PER_PHYSICAL,BUF_ID_ATSC);

#if ENABLE_NEW_QAM_SCAN
    Cable_Sys_Lock = CABLE_SYSTEM_STD;
    u8FreqLockEver = 0;
#endif

#if CHAKRA3_AUTO_TEST
    if(g_AT_enDTVManualTuningState == E_AUTO_TEST_TUNING_WAIT_START)
        g_AT_enDTVManualTuningState = E_AUTO_TEST_TUNING_START;
    else if(g_AT_enATVManualTuningState == E_AUTO_TEST_TUNING_WAIT_START)
        g_AT_enATVManualTuningState = E_AUTO_TEST_TUNING_START;
    else if(g_AT_enDTVAutoTuningState == E_AUTO_TEST_TUNING_WAIT_START)
        g_AT_enDTVAutoTuningState = E_AUTO_TEST_TUNING_START;
    else if(g_AT_enATVAutoTuningState == E_AUTO_TEST_TUNING_WAIT_START)
        g_AT_enATVAutoTuningState = E_AUTO_TEST_TUNING_START;
#endif

    /* check error condition ====================================================== */
    if (  pastVirtualCh == NULL
       || pastVirtualCh_VCT == NULL
       || pastVirtualChInfo ==NULL)
    {
        __ASSERT(0);
        printf("MApp_Scan_Init>> memory allocate fail!! \r\n");
        return FALSE;
    }

    //SCAN_DBINFO_ATSC(msAPI_Memory_Status());
    fSaveScrambleChannel = FALSE;
    origPstSrvInfo = NULL;
    /* release all filter =============================================*/
    if (fTableVersionChanged)
    {
        fEnableSignalCheck = FALSE;
        MApp_Dmx_DisableTableMonitor_ATSC();

        origPstSrvInfo = (MS_VIRTUAL_CHANNEL *) msAPI_Memory_Allocate(sizeof(MS_VIRTUAL_CHANNEL),BUF_ID_ATSC);
        if (origPstSrvInfo != NULL)
        {
            memcpy(origPstSrvInfo, pstVirtualCh, sizeof(MS_VIRTUAL_CHANNEL));
        }
        else
        {
            __ASSERT(0);
            return FALSE;
        }
    }
    else
    {
        MApp_ChannelChange_DisableChannel_ATSC();
        MApp_Dmx_CloseAllFilters_ATSC();
      #if ENABLE_DMXMONITOR
        if (fReInitDemux == TRUE)
        {
            printf("SCAN: MApi_DMX_Init() !! \n");
            MApi_DMX_Init();
            fReInitDemux = FALSE;
        }
      #endif
    }

    if(u8ManualScanStatus == TRUE)
    {
        //u8ManualScanStatus = FALSE;
        fScanType = MANUAL_SCAN;
    }
    else
        fScanType = stGenSetting.stScanMenuSetting.u8ScanType;

    SCAN_DBINFO_ATSC( printf("fScanType=%u\n", fScanType); );

    /* initial variables ==============================================*/
    if(fScanType == AUTO_SCAN)
    {
        fScanTypeIsAuto = ENABLE;
        if(ANT_TYPE == ANT_AIR)
        {
            u8RFCh = CHAN_AIR_MIN - 1;
            u8MaxRFCh = CHAN_AIR_MAX;
        }
        else
        {
            u8RFCh = CHAN_CATV_MIN - 1;
            u8MaxRFCh = CHAN_CATV_MAX;
        }

        /* erase stChSetting */
      #if (CHANNEL_ADD_AND_MERGE_FUNC==ENABLE)
        if(Auto_Scan_Add_CH_flag==0)
        {
            u16NumOfVirCh2bShifted=0;
            memset(&stChSetting, 0, sizeof(MS_CHANNEL_SETTING) - sizeof(stChSetting.U32DatabaseMagicCodeEndExt) - sizeof(stChSetting.U32DatabaseMagicCodeEnd));
        }
      #else
        memset(&stChSetting, 0, sizeof(MS_CHANNEL_SETTING) - sizeof(stChSetting.U32DatabaseMagicCodeEndExt) - sizeof(stChSetting.U32DatabaseMagicCodeEnd));
      #endif
    }
    else //MANUAL_SCAN
    {
      #if (CHANNEL_ADD_AND_MERGE_FUNC==ENABLE)
        Auto_Scan_Add_CH_flag=0;
      #endif

        if(u8ManualScanStatus == TRUE)
            u8RFCh = stVirtualChNum.major_num; //direct tune to selected RF channel
        else
            u8RFCh = stGenSetting.stScanMenuSetting.u8RFChannelNumber;

        if(ANT_TYPE == ANT_AIR)
            u8MaxRFCh = CHAN_AIR_MAX;
        else
            u8MaxRFCh = CHAN_CATV_MAX;

        /* shift astVirtualChInfo[] from current astPhysicalCh[u8RFCh+1].u16VirChInfoStartIdx */
        if(u8RFCh < u8MaxRFCh)
        {
            u16NumOfVirCh2bShifted = (stChSetting.u16MainListSrvNum+1) - stChSetting.astPhysicalCh[u8RFCh+1].u16VirChInfoStartIdx;


            if(u8ManualScanStatus == TRUE)
            {
                u8PrePhyChIdx          = PHY_CH_IDX(MApp_ChanProc_GetCurProgIndex());
                u8PreVirChInfoIdx      = stChSetting.astMainList[MApp_ChanProc_GetCurProgIndex()].u8VirChInfoIdx;
            }
            else
            {
              #if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
                MS_RF_CHANNEL_new   RfCh_info;
                memset(&RfCh_info, 0x00, sizeof(MS_RF_CHANNEL_new));
                MApp_ChanProc_GetRfChannelPointer(MApp_ChanProc_GetCurChannelPointer(), &RfCh_info);
                u16CurTsId             = RfCh_info.u16TsId;
              #else
                u16CurTsId             = MApp_ChanProc_GetCurChannelPointer()->u16TsId;
              #endif

                u16CurProgramNumber    = MApp_ChanProc_GetCurChannelPointer()->u16ProgramNumber;
                u8CurPhyChIdx          = PHY_CH_IDX(MApp_ChanProc_GetCurProgIndex());
                u8PrePhyChIdx          = PHY_CH_IDX(MApp_ChanProc_GetPreProgIndex());

                if(u8PrePhyChIdx==u8CurPhyChIdx)
                {
                    // use astChannelBuf[0].stSrvInfo as temp buffer to get previous virtual channel
                    MApp_ChanProc_GetSingleVirtualChannel(&g_stPreVirtualCh, MApp_ChanProc_GetPreProgIndex());

                  #if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
                    MApp_ChanProc_GetRfChannelPointer(&g_stPreVirtualCh, &RfCh_info);
                    u16PreTsId          = RfCh_info.u16TsId;
                  #else
                    u16PreTsId          = g_stPreVirtualCh.u16TsId;
                  #endif
                    u16PreProgramNumber = g_stPreVirtualCh.u16ProgramNumber;
                }
                else
                {
                    u8PreVirChInfoIdx   = stChSetting.astMainList[MApp_ChanProc_GetPreProgIndex()].u8VirChInfoIdx;
                }
            }

            if (u16NumOfVirCh2bShifted)
            {
                pastVirtualChInfo_2 = (MS_VIRTUAL_CHANNEL_INFO *)msAPI_Memory_Allocate(sizeof(MS_VIRTUAL_CHANNEL_INFO) * u16NumOfVirCh2bShifted, BUF_ID_ATSC);
                if (pastVirtualChInfo_2 != NULL)
                {
                    memcpy((U8*)(pastVirtualChInfo_2),
                    (U8*)(&stChSetting.astVirtualChInfo[stChSetting.astPhysicalCh[u8RFCh+1].u16VirChInfoStartIdx]),
                    sizeof(MS_VIRTUAL_CHANNEL_INFO)*u16NumOfVirCh2bShifted);
                }
                else
                {
                    __ASSERT(0);
                    return FALSE;
                }
            }
            else
            {
                pastVirtualChInfo_2 = NULL;
            }
        }
    }

    MApp_ChanProc_RefreshVirChInfoStartIdx();

    u16NumOfSrvAdd = 0;
    u16NumOfNTSCSrvAdd = 0;

#if (ASSIGN_NTSC_PROGRAM_AS_DEFAULT_CH == ENABLE)
    u16NumOfNoSignalNTSCSrvAdd = 0;
#endif

    /* force change input source to ATV and power on demodulator and set tri-state on
       to scan ATV and DTV in the same time */
    if (fTableVersionChanged != TRUE)
    {   // scan is initiated by use
        //Refine: It should pass INPUT_SOURCE_TV to MApp_InputSource_SwitchSource()
        //          it will set SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW) automatically.
        //SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW) = INPUT_SOURCE_TV;
	printf("\nRay:MApp_Scan_Init\n");		//Ray DBG 2017.03.14
        MApp_InputSource_SwitchSource(UI_INPUT_SOURCE_ATV, MAIN_WINDOW);
        msAPI_Tuner_PowerOnOff_ATSC(ENABLE);
    }

    fChangeChannel = TRUE;
    return TRUE;
}

void  MApp_VCT_Init(void)
{
    pastVirtualCh_VCT = (MS_VIRTUAL_VCT_CHANNEL *) msAPI_Memory_Allocate(sizeof(MS_VIRTUAL_VCT_CHANNEL),BUF_ID_ATSC );

      /* check error condition ====================================================== */
    if( pastVirtualCh_VCT ==NULL  )
    {
        SCAN_DBINFO_ATSC(printf("MApp_Scan_Init>> memory allocate fail!! \r\n"));
    }

    pstVirtualCh_VCT =  pastVirtualCh_VCT;

    memset(pstVirtualCh_VCT, 0x00, sizeof(MS_VIRTUAL_VCT_CHANNEL));

    MSAPI_MEMORY_FREE(pastVirtualCh_VCT,BUF_ID_ATSC);
}

#if 0
BOOLEAN MApp_Scan_Check_IsSame_VirtualChannel(void)
{
    U8 u8Loop,Status;


    Status=TRUE;

    if(origPstSrvInfo == NULL)
    {
        goto END;
    }

    for (u8Loop = 0; u8Loop < u8TotalTableItem; u8Loop++)
    {

        if (pastVirtualCh[u8Loop].u16ProgramNumber != origPstSrvInfo->u16ProgramNumber)
        {
            continue;
        }


        if (pastVirtualCh[u8Loop].u8VctVersion != origPstSrvInfo->u8VctVersion)
        {
            continue;
        }


        if (pastVirtualCh[u8Loop].u16SourceId != origPstSrvInfo->u16SourceId)
        {
            continue;
        }

        if (pastVirtualCh[u8Loop].u8PmtVersion != origPstSrvInfo->u8PmtVersion)
        {
            continue;
        }

        pstVirtualCh_VCT = &pastVirtualCh_VCT[u8Loop];

        pstVirtualCh_VCT->u16VideoPid = pastVirtualCh_VCT[u8Loop].u16VideoPid;


        Status=FALSE;
        goto END;
    }
    fTableVersionChanged = 1;

END:

       /* memory MSAPI_MEMORY_FREE =============================================== */
    MSAPI_MEMORY_FREE(pastVirtualChInfo,BUF_ID_ATSC);
    MSAPI_MEMORY_FREE(origPstSrvInfo,BUF_ID_ATSC);
    MSAPI_MEMORY_FREE(pastVirtualCh,BUF_ID_ATSC);
    MSAPI_MEMORY_FREE(pastVirtualCh_VCT,BUF_ID_ATSC);

    return Status;
}
#endif

BOOLEAN MApp_Scan_Check_VirtualChannel_Change(U8 *u8VirIdx)
{
    U8 u8Loop;

    if(origPstSrvInfo == NULL)
    {
        *u8VirIdx = 0;
        return TRUE;
    }

    for (u8Loop = 0; u8Loop < pstPhysicalCh->u8NumOfVirCh; u8Loop++)
    {
        MApp_ChanProc_GetSingleVirtualChannel(&stVirtualCh, l_pastVirtualChInfo[u8Loop].u16VirChIdx);

      #if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
        if (stVirtualCh.u8RfNum != origPstSrvInfo->u8RfNum)
        {
            continue;
        }
      #else
        if (stVirtualCh.u16TsId != origPstSrvInfo->u16TsId)
        {
            continue;
        }
      #endif

        if (stVirtualCh.u16ProgramNumber != origPstSrvInfo->u16ProgramNumber)
        {
            continue;
        }

        if (stVirtualCh.fIsScrambleCh != origPstSrvInfo->fIsScrambleCh)
        {
            continue;
        }

        if (stVirtualCh.u16PcrPid != origPstSrvInfo->u16PcrPid)
        {
            continue;
        }

        if (stVirtualCh.u16VideoPid != origPstSrvInfo->u16VideoPid)
        {
            continue;
        }

        if (stVirtualCh.astSoundTrack[stVirtualCh.u8AudLangNum].u16AudioPid != origPstSrvInfo->astSoundTrack[origPstSrvInfo->u8AudLangNum].u16AudioPid)
        {
            continue;
        }

        if (stVirtualCh.u8AudLangNum != origPstSrvInfo->u8AudLangNum)
        {
            continue;
        }

        if (memcmp(stVirtualCh.astSoundTrack, origPstSrvInfo->astSoundTrack, sizeof(MS_SOUND_TRACK_ATSC) * origPstSrvInfo->u8AudLangNum))
        {
            continue;
        }

        *u8VirIdx = u8Loop;
        return FALSE;
    }

    *u8VirIdx = 0;
    return TRUE;
}

/*****************************************************************************/
void MApp_Scan_End(void)
{
    U8 u8Loop;
    MS_U8 fFindCur, fFindPre;
    SCAN_DBINFO_ATSC(printf("MApp_Scan_End.\n"));
#if ENABLE_ATV_CHANNEL_CHANGE_FINETUNING
    MApp_SetChChangeState(FALSE);
#endif

#if (ASSIGN_NTSC_PROGRAM_AS_DEFAULT_CH == ENABLE)
    if(fScanType == AUTO_SCAN)
    {
        U8 Cable_Sys_Found;

    #if (SEARCH_CABLE_ATV_DTV_TOGETHER == DISABLE)
        if(enAtscTune2RfSubState != NTSC_SCAN_STATE)
            u8RFCh = (ANT_TYPE==ANT_AIR) ? CHAN_AIR_MIN : CHAN_CATV_MIN;
    #endif

        while(1)
        {
            if(u8RFCh > u8MaxRFCh)
                break;

            /* init u16VirChInfoStartIdx of current astPhysicalCh[u8RFCh] */
            pstPhysicalCh = &stChSetting.astPhysicalCh[u8RFCh];
            pstPhysicalCh->u16VirChInfoStartIdx = stChSetting.astPhysicalCh[u8RFCh-1].u16VirChInfoStartIdx + stChSetting.astPhysicalCh[u8RFCh-1].u8NumOfVirCh;
            l_pastVirtualChInfo = &stChSetting.astVirtualChInfo[pstPhysicalCh->u16VirChInfoStartIdx];

            if(stGenSetting.stScanMenuSetting.u8CableSystem==CABLE_SYSTEM_AUTO)
            {
                Cable_Sys_Found = CABLE_SYSTEM_STD;
            }
            else
            {
                Cable_Sys_Found = stGenSetting.stScanMenuSetting.u8CableSystem;
            }
            MApp_ScanMenu_GetTPSetting(u8RFCh, &stTPSetting, Cable_Sys_Found);

             /* store this RF directly if FE not lock */
            if(pstPhysicalCh->u8NumOfVirCh==0)
            {
                u16NumOfVirCh2bShifted = (u16NumOfSrvAdd+1) - stChSetting.astPhysicalCh[u8RFCh+1].u16VirChInfoStartIdx;
                MSAPI_MEMORY_FREE(pastVirtualChInfo_2,BUF_ID_ATSC);
                if(u16NumOfVirCh2bShifted)
                {
                    pastVirtualChInfo_2 = (MS_VIRTUAL_CHANNEL_INFO *)msAPI_Memory_Allocate(sizeof(MS_VIRTUAL_CHANNEL_INFO) * u16NumOfVirCh2bShifted, BUF_ID_ATSC);
                    if (pastVirtualChInfo_2 == NULL)
                    {
                        __ASSERT(0);
                        enAtscSCanState = STATE_SCAN_SCAN_END;
                        break;
                    }
                    memcpy((U8*)(pastVirtualChInfo_2),
                           (U8*)(&stChSetting.astVirtualChInfo[stChSetting.astPhysicalCh[u8RFCh+1].u16VirChInfoStartIdx]),
                           sizeof(MS_VIRTUAL_CHANNEL_INFO)*u16NumOfVirCh2bShifted);

                }
                else
                {
                    pastVirtualChInfo_2 = NULL;
                }

                pstPhysicalCh = &stChSetting.astPhysicalCh[u8RFCh];
                pstPhysicalCh->u16VirChInfoStartIdx = stChSetting.astPhysicalCh[u8RFCh-1].u16VirChInfoStartIdx + stChSetting.astPhysicalCh[u8RFCh-1].u8NumOfVirCh;
                l_pastVirtualChInfo = &stChSetting.astVirtualChInfo[pstPhysicalCh->u16VirChInfoStartIdx];

                /* store front end setting */
                memset(pastVirtualCh, 0x00, sizeof(MS_VIRTUAL_CHANNEL));
                memset(l_pastVirtualChInfo, 0x00, sizeof(MS_VIRTUAL_CHANNEL_INFO));
                l_pastVirtualChInfo->fIsHideCh = TRUE;

              #if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
                pastRfCh.stTPSetting.u16Frequency = stTPSetting.u16Frequency;
                pastRfCh.stTPSetting.fModulation = DEMOD_ATSC_MODE_NTSC;
                pastVirtualCh[0].u8RfNum = u8RFCh;
                pastVirtualCh[0].stVirtualChNum.u8AirCable = (U8)ANT_TYPE;
              #else
                pastVirtualCh[0].stTPSetting.u16Frequency = stTPSetting.u16Frequency;
                pastVirtualCh[0].stTPSetting.fModulation = DEMOD_ATSC_MODE_NTSC;
              #endif

                pastVirtualCh[0].stVirtualChNum.major_num = u8RFCh;
                pastVirtualCh[0].stVirtualChNum.minor_num = 0;

                if(MApp_Scan_AddSrv2DB(pstPhysicalCh, l_pastVirtualChInfo, pastVirtualCh, (EN_ANT_TYPE)ANT_TYPE))
                {
                    u16NumOfNoSignalNTSCSrvAdd ++;

                    if(fScanType == AUTO_SCAN)
                    {
                        for(u8Loop=u8RFCh+1; u8Loop<=u8MaxRFCh; u8Loop++)
                        {
                            stChSetting.astPhysicalCh[u8Loop].u16VirChInfoStartIdx = stChSetting.astPhysicalCh[u8Loop-1].u16VirChInfoStartIdx + stChSetting.astPhysicalCh[u8Loop-1].u8NumOfVirCh;
                        }

                        if(u16NumOfVirCh2bShifted)
                        {
                            memcpy((U8*)(&stChSetting.astVirtualChInfo[stChSetting.astPhysicalCh[u8RFCh+1].u16VirChInfoStartIdx]),
                                   (U8*)(pastVirtualChInfo_2),
                                   sizeof(MS_VIRTUAL_CHANNEL_INFO)*u16NumOfVirCh2bShifted);

                            MSAPI_MEMORY_FREE(pastVirtualChInfo_2,BUF_ID_ATSC);
                            u16NumOfVirCh2bShifted = 0;
                        }
                    }

                }

                if((fScanType == AUTO_SCAN) && u16NumOfVirCh2bShifted)
                {
                    MSAPI_MEMORY_FREE(pastVirtualChInfo_2,BUF_ID_ATSC);
                    u16NumOfVirCh2bShifted = 0;
                }
            }

            u8RFCh++;
        }
    }
#endif

    /* memory MSAPI_MEMORY_FREE =============================================== */
    MSAPI_MEMORY_FREE(pastVirtualChInfo,BUF_ID_ATSC);
    MSAPI_MEMORY_FREE(pastVirtualCh_VCT,BUF_ID_ATSC);//Max20120515 fix scan memory leak issue of pastVirtualCh_VCT

    //msAPI_Tuner_InitCurrentTPSetting_ATSC();
    stMGT.version_number = INVALID_VERSION_NUM;
    MApp_EpgDB_Reset();

    stChSetting.u16MainListSrvNum = MApp_ChanProc_CalculateTotalSrvNum(stChSetting.astPhysicalCh, (EN_ANT_TYPE)ANT_TYPE);
    SCAN_DBINFO_ATSC(printf("1,Total Air service # found = %u \r\n", stChSetting.u16MainListSrvNum));
    printf("*** [SCAN_END] Total service # found = %u \r\n", stChSetting.u16MainListSrvNum);

    fScanTypeIsAuto = DISABLE;
    /* update astPhysicalCh[] and astVirtualChInfo[] from u8RFCh+1 by MANUAL_SCAN */
    if(/*fScanType==MANUAL_SCAN &&*/ u8RFCh<u8MaxRFCh)
    {
        for(u8Loop=u8RFCh+1; u8Loop<=u8MaxRFCh; u8Loop++)
        {
            stChSetting.astPhysicalCh[u8Loop].u16VirChInfoStartIdx = stChSetting.astPhysicalCh[u8Loop-1].u16VirChInfoStartIdx + stChSetting.astPhysicalCh[u8Loop-1].u8NumOfVirCh;
        }

        if(fScanType==MANUAL_SCAN && u16NumOfVirCh2bShifted)
        {
            memcpy((U8*)(&stChSetting.astVirtualChInfo[stChSetting.astPhysicalCh[u8RFCh+1].u16VirChInfoStartIdx]),
                (U8*)(pastVirtualChInfo_2),
                sizeof(MS_VIRTUAL_CHANNEL_INFO)*u16NumOfVirCh2bShifted);

            MSAPI_MEMORY_FREE(pastVirtualChInfo_2,BUF_ID_ATSC);
        }
    }

    /* init. main list */
    memset(stChSetting.astMainList, 0, sizeof(stChSetting.astMainList));

    /* create main list, index starts from 1 */
    if(stChSetting.u16MainListSrvNum)
    {
        if (stGenSetting.g_SysSetting.fFinishWizardMode == FALSE)
        {
            stGenSetting.g_SysSetting.fFinishWizardMode = TRUE;
        }

        MApp_ChanProc_CreateMainList(stChSetting.astPhysicalCh, &stChSetting.astMainList[1], (EN_ANT_TYPE)ANT_TYPE);

        if(fScanType == MANUAL_SCAN && pstPhysicalCh->u8NumOfVirCh > 0)
        {
            fFindCur = fFindPre = FALSE;
            if(u8ManualScanStatus)
            {
                u8CurPhyChIdx = u8RFCh;
                fChangeChannel = MApp_Scan_Check_VirtualChannel_Change(&u8CurVirChInfoIdx);
                fFindPre = TRUE;
                if ((fChangeChannel == FALSE) && bPidChang)
                {
                    fChangeChannel = 1;
                }
            }
            else
            {
                u8CurVirChInfoIdx = 0;
                for(iu8Loop_i=0; iu8Loop_i<pstPhysicalCh->u8NumOfVirCh; iu8Loop_i++)
                {
                    // search current program

                  #if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
                    MS_RF_CHANNEL_new   rfCh_info;
                    memset(&rfCh_info, 0x00, sizeof(MS_RF_CHANNEL_new));
                    // search current program
                    MApp_ChanProc_GetRfChannelPointer(&pastVirtualCh[iu8Loop_i], &rfCh_info);
                    if(rfCh_info.u16TsId == u16CurTsId && pastVirtualCh[iu8Loop_i].u16ProgramNumber == u16CurProgramNumber)
                  #else
                    // search current program
                    if(pastVirtualCh[iu8Loop_i].u16TsId == u16CurTsId && pastVirtualCh[iu8Loop_i].u16ProgramNumber == u16CurProgramNumber)
                  #endif
                    {
                        u8CurVirChInfoIdx=iu8Loop_i;
                        fFindCur=TRUE;
                    }
                    // search previous program
                    if(u8PrePhyChIdx==u8CurPhyChIdx)
                    {
                      #if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
                        if(rfCh_info.u16TsId == u16PreTsId && pastVirtualCh[iu8Loop_i].u16ProgramNumber == u16PreProgramNumber)
                      #else
                        if(pastVirtualCh[iu8Loop_i].u16TsId == u16PreTsId && pastVirtualCh[iu8Loop_i].u16ProgramNumber == u16PreProgramNumber)
                      #endif
                        {
                            u8PreVirChInfoIdx=iu8Loop_i;
                            fFindPre=TRUE;
                        }
                    }
                    else
                    {
                        fFindPre=TRUE;
                    }

                    if(fFindCur&&fFindPre)
                    {
                        break;
                    }
                }

                if(!fFindPre)
                {
                    u8PreVirChInfoIdx = u8CurVirChInfoIdx;
                }
            }

            MApp_ChanProc_ResetProgIdxByVirChIdx(u8PrePhyChIdx, u8PreVirChInfoIdx, u8CurPhyChIdx, u8CurVirChInfoIdx);
        }
        else
        {
            for (iu16Loop_i = 1; iu16Loop_i <= stChSetting.u16MainListSrvNum; iu16Loop_i++)
            {
                if (!IS_HIDE_CH_ATSC(iu16Loop_i))
                    break;
            }

            // all channels are hiden.....
            if (iu16Loop_i-1 == stChSetting.u16MainListSrvNum)
                iu16Loop_i = 1;

            MApp_ChanProc_ResetAllIndex(iu16Loop_i);
        }
    }
    else
    {
        MApp_ChanProc_ResetAllIndex(INVALID_SERVICE_IDX);
    }

#ifdef INSIGNIA_INSTALL_GUIDE_MENU_NEW_STYLE
    if ( stGenSetting.g_SysSetting.fFinishWizardMode == FALSE)
    {
        stGenSetting.g_SysSetting.fFinishWizardMode = TRUE;
    }
#endif

    /* memory MSAPI_MEMORY_FREE =============================================== */
    MSAPI_MEMORY_FREE(pastVirtualCh,BUF_ID_ATSC);

    if (origPstSrvInfo)
    {
        MSAPI_MEMORY_FREE(origPstSrvInfo,BUF_ID_ATSC);
    }

    MApp_ChanProc_RefreshChannelBuffer(MAIN_LIST);

  #ifdef ENABLE_ATV_DEF_STEREO_AFT_AUTOSCAN
    if ( (fScanType == AUTO_SCAN)
       &&(enScanChannelType != SCAN_DIGITAL_CHANNEL) )
        stGenSetting.g_SoundSetting.Mts = SOUND_MTS_STEREO;
  #endif

  #ifdef MAINLISTSRV_ANALOGCH_NUM
    stChSetting.u16MainListAnalogCHNum = MApp_ChanProc_CalculateAnalogSrvNum(stChSetting.astPhysicalCh, ANT_TYPE);
  #endif

    {
        MS_VIRTUAL_CHANNEL *pVirtualCh;
        pVirtualCh = MApp_ChanProc_GetChannelPointer(VIR_CH_IDX(MApp_ChanProc_GetCurMainListProgIndex()));

    #if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
        MS_RF_CHANNEL_new pRfCh;
        MApp_ChanProc_GetRfChannelPointer(pVirtualCh, &pRfCh);
        if( pRfCh.stTPSetting.fModulation == DEMOD_ATSC_MODE_NTSC )
    #else
        if ( pVirtualCh->stTPSetting.fModulation == DEMOD_ATSC_MODE_NTSC )
    #endif
        {
            //printf("\r\n Scan end and goto ATV!\n");
          #if (FRONTEND_IF_DEMODE_TYPE  == MSTAR_INTERN_VIF)
            // ATV mode
            msAPI_AVD_SetVideoSource( E_INPUT_SOURCE_ATV );  // vd mcu code should be loaded before vif initial
            EXT_RF_AGC_ON();
            MDrv_IFDM_Init();
            MDrv_IFDM_SetIF(IF_FREQ_MN);
            MDrv_IFDM_SetVifIfFreq(TUNER_IF_FREQ_KHz);
            msAPI_IFDM_SetVIF_Notch();
          #endif
        }
        else
        {
            //printf("\r\n Scan end and goto DTV!\n");
        }
    }

    u8RFCh=0;
    u16NumOfSrvAdd=0;
    u16NumOfNTSCSrvAdd=0;
    enAtscTune2RfSubState=VSB_SCAN_STATE;
#if (ASSIGN_NTSC_PROGRAM_AS_DEFAULT_CH == ENABLE)
    u16NumOfNoSignalNTSCSrvAdd = 0;
#endif

    // Save variable to ramdisk
    MApp_DB_ATSC_SaveChSetting(&stChSetting);


    //PRINT_CURRENT_LINE();
#if(CHAKRA3_AUTO_TEST)
    if(u8ManualScanStatus)
    {
        MApp_AT_SendEvent(E_AT_EVENT_ATV_MANUAL_SCAN_FINISH, NULL);
      #if(ENABLE_DTV)
        MApp_AT_SendEvent(E_AT_EVENT_DTV_MANUAL_SCAN_FINISH, NULL);
      #endif
    }
    else
    {
        MApp_AT_SendEvent(E_AT_EVENT_ATV_AUTO_SCAN_FINISH, NULL);
      #if(ENABLE_DTV)
        MApp_AT_SendEvent(E_AT_EVENT_DTV_AUTO_SCAN_FINISH, NULL);
      #endif

    }
#endif
}

void  MApp_ReScan_Init(void)
{
    origPstSrvInfo = (MS_VIRTUAL_CHANNEL *) msAPI_Memory_Allocate(sizeof(MS_VIRTUAL_CHANNEL),BUF_ID_ATSC);
    pastVirtualCh = (MS_VIRTUAL_CHANNEL *) msAPI_Memory_Allocate(sizeof(MS_VIRTUAL_CHANNEL) * MAX_VC_PER_PHYSICAL,BUF_ID_ATSC);
    pastVirtualCh_VCT = (MS_VIRTUAL_VCT_CHANNEL *) msAPI_Memory_Allocate(sizeof(MS_VIRTUAL_VCT_CHANNEL)* MAX_VC_PER_PHYSICAL,BUF_ID_ATSC );
    pastVirtualChInfo = (MS_VIRTUAL_CHANNEL_INFO *) msAPI_Memory_Allocate(sizeof(MS_VIRTUAL_CHANNEL_INFO) * MAX_VC_PER_PHYSICAL,BUF_ID_ATSC);

      /* check error condition ====================================================== */
    if (  pastVirtualCh == NULL
       || pastVirtualCh_VCT ==NULL
       || pastVirtualChInfo ==NULL
       || origPstSrvInfo ==NULL )
    {
        printf("MApp_Scan_Init>> memory allocate fail!! \r\n");
    }

    memcpy(origPstSrvInfo, pstVirtualCh, sizeof(MS_VIRTUAL_CHANNEL));
}

/*****************************************************************************/
static BOOLEAN MApp_Scan_CheckServiceInfo(MS_VIRTUAL_CHANNEL *pstVirtualCh_func, MS_VIRTUAL_VCT_CHANNEL *p_stVirtualCh_VCT, U8 u8CurPatSrvItem)
{
    MSAPI_DMX_SCRAMBLING_SOURCE enScmbSource = MSAPI_DMX_SCRAMBLING_SOURCE_NONE;
    int i=0;
    VDEC_Status vdecStatus;

    U32  IFrameCount = 0;
    U16 u16VideoPid, u16AudioPid;
#if ONE_PART_CHNO
    U16 u16OnePartVchNum;
#endif

#if (STORE_CH_TYPE != FTA_AND_HIDE_SCRAMBLE)
    u8CurPatSrvItem=u8CurPatSrvItem;        //avoid warning
#endif

/* remove later, old pattern patch
    pstVirtualCh_func->u16VCTStatus = 0;
*/
     SCAN_DBINFO_ATSC(printf("\n[MApp_Scan_CheckServiceInfo]  ch[%d-%d] ; Vdpid=%x, %x ; Aupid=%x, %x\r\n", pstVirtualCh_func->stVirtualChNum.major_num, pstVirtualCh_func->stVirtualChNum.minor_num,
                   pstVirtualCh_func->u16VideoPid, p_stVirtualCh_VCT->u16VideoPid,
                   pstVirtualCh_func->astSoundTrack[0].u16AudioPid, p_stVirtualCh_VCT->astSoundTrack[0].u16AudioPid));

    if ( (pstVirtualCh_func->u16VideoPid == 0)
      #if (STORE_RD_CH_ENABLE == 1)
       && (pstVirtualCh_func->astSoundTrack[0].u16AudioPid == 0)
       && (p_stVirtualCh_VCT->astSoundTrack[0].u16AudioPid == 0)
      #endif
        )
    {
        return FALSE;
    }

  #if( WATCH_DOG == ENABLE )    //(WDT_SWITCH)
    msAPI_Timer_ResetWDT();
  #endif

    if (pstVirtualCh_func->fIsScrambleCh )
    {
        pstVirtualCh_func->u16ScrambleChStatus  |=  (SCRAMBLE_VIDEO |SCRAMBLE_AUDIO);
    }
    else
    {
        enScmbSource = MSAPI_DMX_SCRAMBLING_SOURCE_NONE;
        //video
        if(pstVirtualCh_func->u16VideoPid)
        {
            u16VideoPid = pstVirtualCh_func->u16VideoPid;
        }
        else
        {
            u16VideoPid = p_stVirtualCh_VCT->u16VideoPid;
        }
        //Audio
        if(pstVirtualCh_func->astSoundTrack[0].u16AudioPid)
        {
            u16AudioPid = pstVirtualCh_func->astSoundTrack[0].u16AudioPid;
        }
        else
        {
            u16AudioPid = p_stVirtualCh_VCT->astSoundTrack[0].u16AudioPid;
        }

        enScmbSource = msAPI_DMX_ScramblingGet(u16VideoPid, u16AudioPid, 500, ENABLE);
        if ( (enScmbSource & MSAPI_DMX_SCRAMBLING_SOURCE_TS_VIDEO)
            || (enScmbSource & MSAPI_DMX_SCRAMBLING_SOURCE_PES_VIDEO))
        {
            pstVirtualCh_func->u16ScrambleChStatus  |=  SCRAMBLE_VIDEO;
        }

        if ( (enScmbSource & MSAPI_DMX_SCRAMBLING_SOURCE_TS_AUDIO)
            || (enScmbSource & MSAPI_DMX_SCRAMBLING_SOURCE_PES_AUDIO))
        {
            pstVirtualCh_func->u16ScrambleChStatus  |=  SCRAMBLE_AUDIO;
        }
        if (enScmbSource == MSAPI_DMX_SCRAMBLING_SOURCE_TIMEOUT)
        {
            u8NumOfTimeOutProg++;
        }

/*
        if(pstVirtualCh_func->u16VideoPid || p_stVirtualCh_VCT->u16VideoPid)
        {
            if (enScmbSource == MSAPI_DMX_SCRAMBLING_SOURCE_NONE)
            {
                //if(pstVirtualCh_func->fIsScrambleCh == 0)
                //{
                //    pstVirtualCh_func->fIsScrambleCh = FALSE;
                    pstVirtualCh_func->u16ScrambleChStatus &= ~( SCRAMBLE_VIDEO | SCRAMBLE_AUDIO );
                //}
            }

            if( (pstVirtualCh_func->astSoundTrack[0].u16AudioPid==0) && (p_stVirtualCh_VCT->astSoundTrack[0].u16AudioPid==0))
            {
                pstVirtualCh_func->u16ScrambleChStatus |= SCRAMBLE_AUDIO;
            }
        }
        else
        {
            //if ( enAudioScmbType == MSAPI_DMX_SCRAMBLING_FREE )
            //{
            //    if(pstVirtualCh_func->fIsScrambleCh == 0)
            //    {
            //        pstVirtualCh_func->fIsScrambleCh = FALSE;
            //    }
            //}
            pstVirtualCh_func->u16ScrambleChStatus |= SCRAMBLE_VIDEO;
        }
*/
    }
    if((pstVirtualCh_func->u16ScrambleChStatus & (SCRAMBLE_VIDEO |SCRAMBLE_AUDIO)) == (SCRAMBLE_VIDEO | SCRAMBLE_AUDIO))
    {
        pstVirtualCh_func->fIsScrambleCh = TRUE ;
        if(fScanType == MANUAL_SCAN && u8ManualScanStatus)
        {
            bPidChang = TRUE;
            u8LastScPatNum = u8CurPatSrvItem;
        }

        memset(&vdecStatus, 0, sizeof(VDEC_Status));
        //stop cc parse
        if(MApi_VDEC_GetStatus(&vdecStatus) == TRUE && vdecStatus.bInit == TRUE)
        {
            CC_SourceFuns.StopMVDParser();
            // Stop CC parser
            CC_SourceFuns.Stop708Parsing();
        }
    }
    else
    {
        //if (TSP Video scramble and audio pid = 0) or (TSP Audio scramble and video pid =0) --> pstVirtualCh_func->fIsScrambleCh = TRUE
        if( (enScmbSource & MSAPI_DMX_SCRAMBLING_SOURCE_TS_VIDEO)
            || (enScmbSource & MSAPI_DMX_SCRAMBLING_SOURCE_PES_VIDEO))
        {
            if( (pstVirtualCh_func->astSoundTrack[0].u16AudioPid==0) && (p_stVirtualCh_VCT->astSoundTrack[0].u16AudioPid==0))
            {
                pstVirtualCh_func->fIsScrambleCh = TRUE;
            }
        }
        else if( (enScmbSource & MSAPI_DMX_SCRAMBLING_SOURCE_TS_AUDIO) || (enScmbSource & MSAPI_DMX_SCRAMBLING_SOURCE_PES_AUDIO))
        {
            if((pstVirtualCh_func->u16VideoPid ==0) &&( p_stVirtualCh_VCT->u16VideoPid==0))
            {
                pstVirtualCh_func->fIsScrambleCh = TRUE;
            }
        }
    }

    //check vaild data of video and audio
    if(pstVirtualCh_func->fIsScrambleCh == TRUE )
    {
        if ( pstVirtualCh_func->u16VideoPid ||p_stVirtualCh_VCT->u16VideoPid  )
        {
            /* stop video decoder */
            //msAPI_VID_Command( MSAPI_VID_STOP );
            //msAPI_VID_Command( MSAPI_VID_RESET );

            if( pstVirtualCh_func->u16VideoPid )
            {
                msAPI_DMX_StartFilter( pstVirtualCh_func->u16VideoPid, MSAPI_DMX_FILTER_TYPE_VIDEO, &u8VidFid );
            }
            else
            {
                msAPI_DMX_StartFilter( p_stVirtualCh_VCT->u16VideoPid, MSAPI_DMX_FILTER_TYPE_VIDEO, &u8VidFid );
            }

            memset(&vdecStatus, 0, sizeof(VDEC_Status));
            MApi_VDEC_GetStatus(&vdecStatus);
            if(((pstVirtualCh->stVirtualChNum.u8VideoStreamType != VIDEO_STREAM_TYPE_H264) && (msAPI_VID_GetCodecType() == E_VDEC_CODEC_TYPE_H264))
                || (pstVirtualCh->stVirtualChNum.u8VideoStreamType == VIDEO_STREAM_TYPE_H264 && msAPI_VID_GetCodecType() == E_VDEC_CODEC_TYPE_MPEG2)
                || (msAPI_VID_GetCodecType() == E_VDEC_CODEC_TYPE_NONE)
                || (vdecStatus.bInit == 0) ||(fTableVersionChanged)
                )
            {
#if (MEMORY_MAP > MMAP_32MB)
                if (pstVirtualCh->stVirtualChNum.u8VideoStreamType == VIDEO_STREAM_TYPE_H264)
                {
                    msAPI_VID_SetMappingAVCParameter(E_VDEC_CODEC_TYPE_H264);
                }
                else
#elif((MEMORY_MAP == MMAP_32MB) && (ENABLE_32M_H264 == ENABLE))
                if (pstVirtualCh->stVirtualChNum.u8VideoStreamType == VIDEO_STREAM_TYPE_H264)
                {
                    msAPI_VID_SetMappingAVCParameter(E_VDEC_CODEC_TYPE_H264);
                }
                else
#endif
                    msAPI_VID_SetMappingAVCParameter(E_VDEC_CODEC_TYPE_MPEG2);
                    if((vdecStatus.bInit)||(fTableVersionChanged))
                    {
                        msAPI_VID_Command( MSAPI_VID_STOP );
                    }
                    //not use in CK3, form CK2_ATSC
                    //msAPI_VID_SetVdecFrameMode(TRUE);
                    msAPI_VID_Init(FALSE, E_VDEC_SRC_MODE_DTV);
                    /* start video decoder */
                    msAPI_VID_Command( MSAPI_VID_PLAY );
            }
            IFrameCount = MApi_VDEC_GetFrameCnt();
        }

        //Remapping Audio language
        MApp_ReMapAudioLanguage();
        u16AudioPID = MApp_SetPreferAudioSoundTrackPID(0);
        if ( u16AudioPID )
        {
            MApi_AUDIO_SetCommand( (En_DVB_decCmdType)MSAPI_AUD_STOP );

            /* set audio PID & start filter */
            msAPI_DMX_StartFilter( u16AudioPID, MSAPI_DMX_FILTER_TYPE_AUDIO, &u8AudFid );
            if(MApp_GetAudioStreamType()==AUD_STREAM_TYPE_MPEG)
            {
                MApi_AUDIO_SetSystem(MSAPI_AUD_DVB_MPEG);
            }
            else
            {
                MApi_AUDIO_SetSystem(MSAPI_AUD_DVB_AC3);
            }
            /* start audio decoder */
            MApi_AUDIO_SetCommand( (En_DVB_decCmdType)MSAPI_AUD_PLAY );
        }

        //check vaild data of video
        if ( pstVirtualCh_func->u16VideoPid ||p_stVirtualCh_VCT->u16VideoPid  )
        {
            for(i=0 ; i<DESCRAMBLE_COUNT ; i++)
            {
                msAPI_Timer_Delayms(10);
                if (MApi_VDEC_CheckDispInfoRdy() == E_VDEC_OK)
                {
                    if(MApi_VDEC_GetFrameCnt() >= (U32)(IFrameCount + (U8)DESCRAMBLE_VIDEO_IFRAME_COUNT))
                    {
                        pstVirtualCh_func->u16ScrambleChStatus  &=  ~SCRAMBLE_VIDEO;
                        SCAN_DBINFO_ATSC(printf("VDEC not Scrambled\r\n"));
                        break;
                    }
                }
            }
            //msAPI_VID_Command( MSAPI_VID_STOP );
            msAPI_DMX_Stop( u8VidFid );
        }

        //check vaild data of audio
        if ( u16AudioPID )
        {
            for(i=0 ; i<DESCRAMBLE_COUNT ; i++)
            {
                msAPI_Timer_Delayms(10);
                if(MApp_GetAudioStreamType() == AUD_STREAM_TYPE_AC3)
                {
                #if (AUDIO_CPU_IS_R2)
                    if (MApi_AUDIO_GetAC3PInfo(Audio_AC3P_infoType_SyncwordFound_Count) > DESCRAMBLE_AC3_SYNCWORD_NUMBER)
                #else
                    if (MApi_AUDIO_GetAC3Info(Audio_AC3_infoType_SyncwordFound_Count) > DESCRAMBLE_AC3_SYNCWORD_NUMBER)
                #endif
                    //SZ needs to search channel for broke audio only stream
                    //but these stream have many error frames cause it can't lock with 300ms
                    //it needs quick method to decide the channel
                    //so we choose to use sync word to judge, but some scramble audio only channel may not abandon
                    {
                        SCAN_DBINFO_ATSC(printf("AC3 not Scrambled\r\n"));
                        pstVirtualCh_func->u16ScrambleChStatus  &=  ~SCRAMBLE_AUDIO;
                        break;
                    }
                }
                else
                {
                    if (msAPI_AUD_DECODER_GetMAD_LOCK())
                    {
                        SCAN_DBINFO_ATSC(printf("MPEG audio not Scrambled\r\n"));
                        pstVirtualCh_func->u16ScrambleChStatus  &=  ~SCRAMBLE_AUDIO;
                        break;
                    }
                }
            }

            /* stop audio decoder */
            MApi_AUDIO_SetCommand( (En_DVB_decCmdType)MSAPI_AUD_STOP );
            /* stop audio filter */
            msAPI_DMX_Stop( u8AudFid );
        }

        if( ( pstVirtualCh_func->u16ScrambleChStatus  &  (SCRAMBLE_VIDEO | SCRAMBLE_AUDIO)) !=  (SCRAMBLE_VIDEO | SCRAMBLE_AUDIO))
        {
            pstVirtualCh_func->fIsScrambleCh = FALSE ;
        }

        if( (pstVirtualCh_func->u16ScrambleChStatus  & (SCRAMBLE_VIDEO)) &&
            ( (pstVirtualCh_func->astSoundTrack[0].u16AudioPid==0) && (p_stVirtualCh_VCT->astSoundTrack[0].u16AudioPid==0)))
        {
                pstVirtualCh_func->fIsScrambleCh = TRUE;
                //Video scrambe and audio  pid = 0 -->  pstVirtualCh_func->fIsScrambleCh = TRUE ;
        }

        if((pstVirtualCh_func->u16ScrambleChStatus  & (SCRAMBLE_AUDIO))&&
            ((pstVirtualCh_func->u16VideoPid ==0) &&( p_stVirtualCh_VCT->u16VideoPid==0)))
        {
                pstVirtualCh_func->fIsScrambleCh = TRUE;
        }


    }


/* remove later, old pattern patch
    if( pstVirtualCh_func->u16ScrambleChStatus  &  SCRAMBLE_AUDIO)
    {
        pstVirtualCh_func->u16VCTStatus = 0;
    }
    else
    {
        if(pstVirtualCh_func->astSoundTrack[0].u16AudioPid == 0 &&  p_stVirtualCh_VCT->astSoundTrack[0].u16AudioPid )
            pstVirtualCh_func->u16VCTStatus = 1;
    }

    if( !(pstVirtualCh_func->u16ScrambleChStatus  &  SCRAMBLE_VIDEO) )
    {
        if( !pstVirtualCh_func->u16VideoPid  &&  p_stVirtualCh_VCT->u16VideoPid)
            pstVirtualCh_func->u16VCTStatus = 1;
    }
*/

    //if( fScanType == AUTO_SCAN )
    {
        //check scramble flag
        if(pstVirtualCh_func->fIsScrambleCh == TRUE /*&& stGenSetting.stScanMenuSetting.u8ScanServiceType == FTA*/)
        {
#if (STORE_CH_TYPE == FTA_AND_HIDE_SCRAMBLE)
            pastVirtualChInfo[u8CurPatSrvItem].fIsHideCh = TRUE;
#else
            printf("Skip Scrambled Channel!\r\n");
            return FALSE;
#endif
        }
    }

#if ONE_PART_CHNO
    if ( ANT_TYPE == ANT_CATV )
    {
        //check cable one-part channel number
        if ((pstVirtualCh_func->stVirtualChNum.major_num & 0x3F0) == 0x3F0)
        {
            u16OnePartVchNum = ((pstVirtualCh_func->stVirtualChNum.major_num & 0x000F) << 10) + pstVirtualCh_func->stVirtualChNum.minor_num;
            if (u16OnePartVchNum)
            {
                pstVirtualCh_func->stVirtualChNum.major_num  = u16OnePartVchNum;
                pstVirtualCh_func->stVirtualChNum.minor_num =  INVALID_MINOR_NUMBER; //0;
                pstVirtualCh_func->stVirtualChNum.fIsOnePartChNum = TRUE;
            }
            else
            {
                pstVirtualCh_func->stVirtualChNum.major_num = u8RFCh;
                pstVirtualCh_func->stVirtualChNum.minor_num = pstVirtualCh_func->u16ProgramNumber;
            }
        }
    }
    /* // Mantis 0950196 fixed
    else if ( ANT_TYPE == ANT_AIR) // Change one-part channel number : CH1008 -> u8RFCh
    {
        //check air one-part channel number
        if ((pstVirtualCh_func->stVirtualChNum.major_num & 0x3F0) == 0x3F0)
        {
            u16OnePartVchNum = ((pstVirtualCh_func->stVirtualChNum.major_num & 0x000F) << 10) + pstVirtualCh_func->stVirtualChNum.minor_num;
            if (u16OnePartVchNum)
            {
                pstVirtualCh_func->stVirtualChNum.major_num  = u16OnePartVchNum;
                pstVirtualCh_func->stVirtualChNum.minor_num =  INVALID_MINOR_NUMBER; //0;
                pstVirtualCh_func->stVirtualChNum.fIsOnePartChNum = TRUE;
            }
            else
            {
                pstVirtualCh_func->stVirtualChNum.major_num = u8RFCh;
                pstVirtualCh_func->stVirtualChNum.minor_num = pstVirtualCh_func->u16ProgramNumber;
            }
        }
    }*/
#endif
    return TRUE;
}

/*****************************************************************************/
BOOLEAN MApp_Scan_AddSrv2DB(MS_PHYSICAL_CHANNEL *pstPhysicalCh_func, MS_VIRTUAL_CHANNEL_INFO *pstVirtualChInfo, MS_VIRTUAL_CHANNEL *pstVirtualCh_func, EN_ANT_TYPE enAntennaType)
{
    iu16Buffer_i = (enAntennaType == ANT_AIR) ? MAX_NUM_OF_AIR_VIR_CH : MAX_NUM_OF_CATV_VIR_CH;

    /* find free virtual channel index, starts from 1 */
    if(fScanType == AUTO_SCAN)
    {
#if (CHANNEL_ADD_AND_MERGE_FUNC==ENABLE)
    if(Auto_Scan_Add_CH_flag==1)
    {
        for(iu16Loop_i = 1; iu16Loop_i <= iu16Buffer_i; iu16Loop_i++)
        {
            if((stChSetting.au8VirChTbl[iu16Loop_i/8] & (1<<(iu16Loop_i%8))) == 0)
                break;
        }
    }
    else
    {
        iu16Loop_i = u16NumOfSrvAdd+ 1;
    }
#else
        iu16Loop_i = u16NumOfSrvAdd + 1;
#endif
    }
    else //MANUAL_SCAN
    {
        for(iu16Loop_i = 1; iu16Loop_i <= iu16Buffer_i; iu16Loop_i++)
        {
            if((stChSetting.au8VirChTbl[iu16Loop_i/8] & (1<<(iu16Loop_i%8))) == 0)
            {
                break;
            }
        }
    }

    SCAN_DBINFO_ATSC( printf("iu16Loop_i=%u, iu16Buffer_i=%u\n", iu16Loop_i, iu16Buffer_i); );

    /* add new service to database*/
    if(iu16Loop_i <= iu16Buffer_i)
    {
        stChSetting.au8VirChTbl[iu16Loop_i/8] |= (1<<(iu16Loop_i%8));
        pstVirtualChInfo->u16VirChIdx = iu16Loop_i;

        SCAN_DBINFO_ATSC(printf("AddSrv2DB>> [Physical %d->%d] u16VirChInfoIdx %u u16VirChIdx %u \r\n", u8RFCh, pstPhysicalCh_func->u8NumOfVirCh, (U16)(pstPhysicalCh_func->u16VirChInfoStartIdx + pstPhysicalCh_func->u8NumOfVirCh), (U16)(stChSetting.astVirtualChInfo[pstPhysicalCh_func->u16VirChInfoStartIdx + pstPhysicalCh_func->u8NumOfVirCh].u16VirChIdx)));
        SCAN_DBINFO_ATSC(printf("AddSrv2DB>> %u-%u name=%s\n", pstVirtualCh_func->stVirtualChNum.major_num, pstVirtualCh_func->stVirtualChNum.minor_num, pstVirtualCh_func->acServiceName));

        pstPhysicalCh_func->u8NumOfVirCh++;
        MApp_DB_ATSC_SaveVirChannel(iu16Loop_i, pstVirtualCh_func);

        u16NumOfSrvAdd++;

        return TRUE;
    }
    else
    {
        printf("Warring>> databse full! \r\n");
        return FALSE; //database full
    }
}

/*****************************************************************************/
BOOLEAN MApp_Scan_AddDirTuneCh(U16 u16Frequency)
{
    /* store front end setting */
    memset(pastVirtualCh, 0x00, sizeof(MS_VIRTUAL_CHANNEL));
    memset(l_pastVirtualChInfo, 0x00, sizeof(MS_VIRTUAL_CHANNEL_INFO));
#if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
    pastRfCh.stTPSetting.u16Frequency = (U16)u16Frequency;;
    pastRfCh.stTPSetting.fModulation = DEMOD_ATSC_MODE_NTSC;
    pastVirtualCh[0].u8RfNum = u8RFCh;
#else
    pastVirtualCh[0].stTPSetting.u16Frequency = (U16)u16Frequency;
    pastVirtualCh[0].stTPSetting.fModulation = DEMOD_ATSC_MODE_NTSC;
#endif
    pastVirtualCh[0].stVirtualChNum.major_num = u8RFCh;
    pastVirtualCh[0].stVirtualChNum.minor_num = 0;

    if(MApp_Scan_AddSrv2DB(pstPhysicalCh, l_pastVirtualChInfo, pastVirtualCh, (EN_ANT_TYPE)ANT_TYPE))
    {
        stChSetting.u16MainListSrvNum++;
        stChSetting.u16TotalDirTuneSrvNum++;
        stChSetting.u16TotalHideSrvNum++;
        stChSetting.astMainList[stChSetting.u16MainListSrvNum].u8PhysicalChIdx = u8RFCh;
        stChSetting.astMainList[stChSetting.u16MainListSrvNum].u8VirChInfoIdx = 0;
        #ifdef ADD_DIR_TUNE_CH_SHOW
        SET_HIDE_CH_ATSC(stChSetting.u16MainListSrvNum, FALSE);
        #else
        SET_HIDE_CH_ATSC(stChSetting.u16MainListSrvNum, TRUE);
        #endif
        SET_DIR_CH_ATSC(stChSetting.u16MainListSrvNum, TRUE);
        SET_FAV_CH_ATSC(stChSetting.u16MainListSrvNum, FALSE);
#if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
        MApp_DB_SaveRfChannel(pastVirtualCh->u8RfNum, &pastRfCh);
#endif

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void MApp_Scan_EraseCurCh(void)
{
    U8 u8Loop;
    U16 VirChIdx;

    /* erase database */
    for(u8Loop = 0; u8Loop < pstPhysicalCh->u8NumOfVirCh; u8Loop++)
    {
        VirChIdx = l_pastVirtualChInfo[u8Loop].u16VirChIdx;
        stChSetting.au8VirChTbl[VirChIdx / 8] &= ~(1 << (VirChIdx % 8));

        /* keep channel editting flag for same program */
        MApp_ChanProc_GetSingleVirtualChannel(&stVirtualCh, VirChIdx);
#if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
        MApp_ChanProc_GetRfChannelPointer(&stVirtualCh, &stRfCh);
#endif

        for(iu8Loop_i = 0; iu8Loop_i < u8TotalTableItem; iu8Loop_i++)
        {
#if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
            if(pastRfCh.u16TsId == stRfCh.u16TsId &&
#else
            if(pastVirtualCh[iu8Loop_i].u16TsId == stVirtualCh.u16TsId &&
#endif
               pastVirtualCh[iu8Loop_i].u16ProgramNumber == stVirtualCh.u16ProgramNumber)
            {
                memcpy(&pastVirtualChInfo[iu8Loop_i], &l_pastVirtualChInfo[u8Loop], sizeof(MS_VIRTUAL_CHANNEL_INFO));
            }
        }
    }
    pstPhysicalCh->u8NumOfVirCh = 0;
}

/*****************************************************************************/
#define VD_LOCK_LOOP         21//31
#define VD_LOCK_THRESHOLD    10//21//4
#define VD_UNLOCK_THRESHOLD   ( VD_LOCK_LOOP-VD_LOCK_THRESHOLD)
#define VD_RDY_LOOP           200
BOOLEAN MApp_Scan_GetVDLockStatus(void)
{

    U8     u8Loop, u8LockCount;
    U16   VD_Status;

    u8LockCount = 0;
    //msAPI_Timer_Delayms(100);
    for( u8Loop=1 ; u8Loop < VD_RDY_LOOP; ++u8Loop)
    {
        msAPI_Tuner_Wait(5);
        VD_Status = msAPI_AVD_GetStatus();

        if(( VD_Status & (VD_STATUS_RDY|VD_BURST_ON|VD_SYNC_LOCKED) ) == (VD_STATUS_RDY|VD_BURST_ON|VD_SYNC_LOCKED) )
         {
            if ( u8LockCount++ > 5)
            {
                //printf("u8Loop=%bx\r\n",u8Loop);
                u8Loop = VD_RDY_LOOP;
            }
        }
    }
    msAPI_Tuner_Wait(200);

    u8LockCount=0;

    for( u8Loop=1 ; u8Loop < VD_LOCK_LOOP; ++u8Loop)
    {
        msAPI_Tuner_Wait(20);
        VD_Status = msAPI_AVD_GetStatus();

        if(VD_Status & VD_VSYNC_50HZ )
        {
            return FALSE;
        }
        if((( VD_Status & (VD_HSYNC_LOCKED|VD_SYNC_LOCKED|VD_FSC_TYPE|VD_BURST_ON|VD_PAL_SWITCH) ) == (VD_HSYNC_LOCKED|VD_SYNC_LOCKED | VD_BURST_ON | VD_FSC_3579)) ||
                                    (( VD_Status & (VD_HSYNC_LOCKED|VD_SYNC_LOCKED |VD_BURST_ON) ) == (VD_HSYNC_LOCKED|VD_SYNC_LOCKED)))
            u8LockCount++;

        if(u8LockCount >= VD_LOCK_THRESHOLD)
            return TRUE;
        else if ( u8Loop-u8LockCount > VD_UNLOCK_THRESHOLD )
        {
            return FALSE;
        }

    }
       return FALSE;
}

BOOLEAN MApp_Scan_CheckIRCHRC(U8* u8CableSys)
{
    if(ANT_TYPE == ANT_CATV &&
       stGenSetting.stScanMenuSetting.u8CableSystem == CABLE_SYSTEM_AUTO
      )
    {
        if(*u8CableSys!=CABLE_SYSTEM_HRC)
        {
            if((u8RFCh==5)||(u8RFCh==6))
            {
                if(*u8CableSys==CABLE_SYSTEM_IRC)
                    *u8CableSys=CABLE_SYSTEM_HRC;
                else
                    *u8CableSys=CABLE_SYSTEM_IRC;
            }
            else
            {
                *u8CableSys=CABLE_SYSTEM_HRC;
            }
             //printf("(%d)MApp_ScanMenu_GetTPSetting\n", __LINE__);
             MApp_ScanMenu_GetTPSetting(u8RFCh, &stTPSetting,*u8CableSys);
             return TRUE;
        }
    }
    return FALSE;
}

/*****************************************************************************/
EN_RET MApp_Scan(void)
{
    U8 u8Loop;

    static U8 Cable_Sys_Found;
    EN_SCAN_RESULT enCurStatus = UNLOCK;
    bIsScanNSTCState = 0;
    enAtscScanRetVal = EXIT_SCAN_NULL;

    if(E_OSD_EMPTY != MApp_ZUI_GetActiveOSD())
    {
        MApp_Scan_ProcessUserInput();
    }

#if (CHANNEL_SCAN_AUTO_TEST)
    if((g_ScanAutoTestData.u2State == 1) && (g_ScanAutoTestData.fCommand == 0))
    {
        SCAN_DBINFO_ATSC(printf("SCAN: Change state to END.\r\n"));
        enAtscSCanState = STATE_SCAN_SCAN_END;
    }
#endif

    switch(enAtscSCanState)
    {
        case STATE_SCAN_INIT:
        {
          MApp_ZUI_API_KillTimer(HWND_MENU_MASK_BACKGROUND, 0);
          #if (FRONTEND_TUNER_TYPE == NXP_TDA18275A_TUNER)
            g_bIsChScanning = TRUE;
          #endif

            if(fScanType == AUTO_SCAN)
            {
               SCAN_DBINFO_ATSC(printf("\n[Debug Auto %s scan start]\n", (ANT_TYPE==ANT_AIR) ? "Air" : "Cable"));
            }
            else
            {
               SCAN_DBINFO_ATSC(printf("\n[Debug Manual %s scan start] \n", (ANT_TYPE==ANT_AIR) ? "Air" : "Cable"));
            }

            gU32TVScanTotalTime= msAPI_Timer_GetTime0();
            TVSCAN_STEP_SETUP();

          #if (CHANNEL_SCAN_AUTO_TEST)
            // Save the original settings;
            if (g_ScanAutoTestData.u2State == 1)
            {
                g_ScanAutoTestData.fScanTypeSave = fScanType;
                g_ScanAutoTestData.f8AntennaSave = stGenSetting.stScanMenuSetting.u8Antenna;
                g_ScanAutoTestData.u2CableSystemSave = stGenSetting.stScanMenuSetting.u8CableSystem;
                fScanType = stGenSetting.stScanMenuSetting.u8ScanType = AUTO_SCAN;
                stGenSetting.stScanMenuSetting.u8Antenna = g_ScanAutoTestData.f8Antenna;
                stGenSetting.stScanMenuSetting.u8CableSystem = g_ScanAutoTestData.u2CableSystem;
                SCAN_DBINFO_ATSC(printf("SCAN: Before MApp_Scan_Init.\r\n"));
            }
          #endif

          #if ENABLE_OFFLINE_SIGNAL_DETECTION
            MApp_OffLineInit();
          #endif

            (printf("\n <<<<<<< STATE_SCAN_INIT >>>>>>> \r\n"));

            //Ben++ not to enable sound mute while version changed 2011/11/03
            if (!fTableVersionChanged)
            {
                msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE,E_AUDIO_INTERNAL_2_MUTEON,E_AUDIOMUTESOURCE_ACTIVESOURCE);
            }

            //msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE,E_AUDIO_INTERNAL_2_MUTEON,E_AUDIOMUTESOURCE_ACTIVESOURCE);
            if (MApp_Scan_Init() == TRUE)
            {
                enAtscSCanState = STATE_SCAN_GET_TPSETTINGS;
            }
            else
            {
                enAtscSCanState = STATE_SCAN_SCAN_END;  /* allocate memory failure, maybe need to display warning msg. here */
            }

          #if (SEARCH_CABLE_ATV_DTV_TOGETHER == DISABLE)
            if ( enScanChannelType != SCAN_ANALOG_CHANNEL || fScanType == MANUAL_SCAN)
            {
                enAtscTune2RfSubState = (ANT_TYPE==ANT_AIR) ? VSB_SCAN_STATE : QAM_SCAN_STATE;
            }
            else
            {
                enAtscTune2RfSubState = NTSC_SCAN_STATE;
            }
            SCAN_DBINFO_ATSC(printf("enAtscTune2RfSubState %d\n",enAtscTune2RfSubState));
          #endif

          #if ENABLE_TVSCANSTEPTIME
            printf("STATE_SCAN_INIT =%ld ms\n", msAPI_Timer_DiffTimeFromNow(gU32TVScanStepTime));
          #endif

            break;
        } // end of case STATE_SCAN_INIT:
        //======================================================================


        case STATE_SCAN_GET_TPSETTINGS:
        {
            SCAN_DBINFO_ATSC(printf("\n <<<<<<< STATE_SCAN_GET_TPSETTINGS >>>>>>> \r\n"));
            TVSCAN_STEP_SETUP();

            MApp_ZUI_ProcessKey(u8KeyCode);
            u8KeyCode = KEY_NULL;

        #if (SEARCH_CABLE_ATV_DTV_TOGETHER == ENABLE)
          #if SEARCH_DTV_ATV_TOGETHER_DTV_FIRST
            enAtscTune2RfSubState = (ANT_TYPE==ANT_AIR) ? VSB_SCAN_STATE : QAM_SCAN_STATE;
          #else
            enAtscTune2RfSubState = NTSC_SCAN_STATE;
          #endif
        #endif

        #if (ASSIGN_NTSC_PROGRAM_AS_DEFAULT_CH == ENABLE)
            fAddEmptyNTSCProg = FALSE;
        #endif

            msAPI_SCAN_Init();

            if(fScanType == AUTO_SCAN)
            {
                if(u8RFCh < u8MaxRFCh)
                {
                    u8RFCh++;

                  #if (CHANNEL_SCAN_AUTO_TEST)
                    if(g_ScanAutoTestData.u2State == 1)
                    {
                        SCAN_DBINFO_ATSC(printf("SCAN: u8RFCh=%d\n", u8RFCh));
                    }
                  #endif

                  #if (CHANNEL_ADD_AND_MERGE_FUNC==ENABLE)
                    if(Auto_Scan_Add_CH_flag==1)
                    {
                        enAtscSCanState = STATE_SCAN_DB_PREPROCESS;
                    }
                    else
                  #endif
                    {
                        enAtscSCanState = STATE_SCAN_TUNE_TO_RF_CH;
                    }

                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_REPAINT_AUTOTUNING_PROGRESS);
                }
                else
                {
                  #if SEARCH_DTV_ATV_TOGETHER_DTV_FIRST
                    if (( enScanChannelType == SCAN_ALL_CHANNEL) && (enAtscTune2RfSubState !=( (ANT_TYPE==ANT_AIR) ? VSB_SCAN_STATE : QAM_SCAN_STATE)))
                    {
                       enAtscTune2RfSubState =( (ANT_TYPE==ANT_AIR) ? VSB_SCAN_STATE : QAM_SCAN_STATE);
                        if(ANT_TYPE == ANT_AIR)
                            u8RFCh = CHAN_AIR_MIN-1;
                        else
                            u8RFCh = CHAN_CATV_MIN-1;
                    }
                  #else
                    if (( enScanChannelType == SCAN_ALL_CHANNEL) && (enAtscTune2RfSubState != NTSC_SCAN_STATE))
                    {
                        enAtscTune2RfSubState=NTSC_SCAN_STATE;
                        if(ANT_TYPE == ANT_AIR)
                            u8RFCh = CHAN_AIR_MIN-1;
                        else
                            u8RFCh = CHAN_CATV_MIN-1;
                    }
                  #endif
                    else
                    {
                        enAtscSCanState = STATE_SCAN_SCAN_END;
                    }
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_REPAINT_AUTOTUNING_PROGRESS);
                }
            }
            else // MANUAL_SCAN
            {
                if (fTableVersionChanged)
                {
                    pstVirtualCh = MApp_ChanProc_GetCurChannelPointer();

                  #if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
                    MS_RF_CHANNEL_new RfCh;
                    memset(&RfCh, 0x00, sizeof(MS_RF_CHANNEL_new));
                    MApp_ChanProc_GetRfChannelPointer(pstVirtualCh, &RfCh);
                    memcpy(&stTPSetting, &(RfCh.stTPSetting), sizeof(MS_TP_SETTING_ATSC));
                  #else
                    memcpy(&stTPSetting, &(pstVirtualCh->stTPSetting), sizeof(MS_TP_SETTING_ATSC));
                  #endif

                    memcpy(&(pstLastVirtualCh), (pstVirtualCh), sizeof(MS_VIRTUAL_CHANNEL));
                    enAtscSCanState = STATE_SCAN_GET_TABLE;
                }
                else
                {
                    enAtscSCanState = STATE_SCAN_TUNE_TO_RF_CH;
                }
            }

          #if (CHANNEL_ADD_AND_MERGE_FUNC==ENABLE)
            if((enAtscSCanState != STATE_SCAN_SCAN_END)&&(enAtscSCanState != STATE_SCAN_DB_PREPROCESS))
          #else
            if(enAtscSCanState != STATE_SCAN_SCAN_END)
          #endif
            {
                /* init u16VirChInfoStartIdx of current astPhysicalCh[u8RFCh] */
                pstPhysicalCh = &stChSetting.astPhysicalCh[u8RFCh];
                pstPhysicalCh->u16VirChInfoStartIdx = stChSetting.astPhysicalCh[u8RFCh-1].u16VirChInfoStartIdx + stChSetting.astPhysicalCh[u8RFCh-1].u8NumOfVirCh;
                l_pastVirtualChInfo = &stChSetting.astVirtualChInfo[pstPhysicalCh->u16VirChInfoStartIdx];
                if(enAtscSCanState==STATE_SCAN_TUNE_TO_RF_CH)
                {
                    if(stGenSetting.stScanMenuSetting.u8CableSystem==CABLE_SYSTEM_AUTO)
                    {
                        Cable_Sys_Found = CABLE_SYSTEM_STD;
                    }
                    else
                    {
                        Cable_Sys_Found=stGenSetting.stScanMenuSetting.u8CableSystem;
                    }

                   MApp_ScanMenu_GetTPSetting(u8RFCh, &stTPSetting,Cable_Sys_Found);
                    SCAN_DBINFO_ATSC(printf("[Get Current Scan Channel Num=%d]\n", u8RFCh));
                    SCAN_DBINFO_ATSC(printf("[Get Current Scan Channel Freq=%d]\n", stTPSetting.u16Frequency*FREQ_STEP));
                    SCAN_DBINFO_ATSC(printf("[Get Current Scan Channel fModulation=%d]\n", stTPSetting.fModulation));
                }

            }

          #if ENABLE_TVSCANSTEPTIME
            SCAN_DBINFO_ATSC(printf("STATE_SCAN_GET_TPSETTINGS =%ld ms\n", msAPI_Timer_DiffTimeFromNow(gU32TVScanStepTime)));
          #endif

            break;
        } // end of case STATE_SCAN_GET_TPSETTINGS:
        //======================================================================


    #if (CHANNEL_ADD_AND_MERGE_FUNC == ENABLE)
        case STATE_SCAN_DB_PREPROCESS:
        {
            SCAN_DBINFO_ATSC(printf("STATE_SCAN_DB_PREPROCESS>> \r\n"));

            if(stChSetting.astPhysicalCh[u8RFCh].u8NumOfVirCh==0)//u8RFCh not in the DB
            {
                if(u8RFCh < u8MaxRFCh)
                {
                    u16NumOfVirCh2bShifted = (stChSetting.u16MainListSrvNum+1) - stChSetting.astPhysicalCh[u8RFCh+1].u16VirChInfoStartIdx;
                    u8PrePhyChIdx          = PHY_CH_IDX(MApp_ChanProc_GetCurProgIndex());
                    u8PreVirChInfoIdx      = stChSetting.astMainList[MApp_ChanProc_GetCurProgIndex()].u8VirChInfoIdx;

                    //msAPI_Memory_Free(pastVirtualChInfo_2);
                    MSAPI_MEMORY_FREE(pastVirtualChInfo_2,BUF_ID_ATSC);
                    if(u16NumOfVirCh2bShifted)
                    {
                        //pastVirtualChInfo_2 = (MS_VIRTUAL_CHANNEL_INFO *)msAPI_Memory_Allocate(sizeof(MS_VIRTUAL_CHANNEL_INFO) * u16NumOfVirCh2bShifted);
                        pastVirtualChInfo_2 = (MS_VIRTUAL_CHANNEL_INFO *)msAPI_Memory_Allocate(sizeof(MS_VIRTUAL_CHANNEL_INFO) * u16NumOfVirCh2bShifted, BUF_ID_ATSC);
                        if (pastVirtualChInfo_2 == NULL)
                        {
                            __ASSERT(0);
                            enAtscSCanState = STATE_SCAN_SCAN_END;
                            break;
                        }
                        memcpy((U8*)(pastVirtualChInfo_2),
                               (U8*)(&stChSetting.astVirtualChInfo[stChSetting.astPhysicalCh[u8RFCh+1].u16VirChInfoStartIdx]),
                               sizeof(MS_VIRTUAL_CHANNEL_INFO)*u16NumOfVirCh2bShifted);
                    }
                    else
                    {
                        pastVirtualChInfo_2 = NULL;
                    }
                }

                enAtscSCanState = STATE_SCAN_TUNE_TO_RF_CH;
                /* init u16VirChInfoStartIdx of current astPhysicalCh[u8RFCh] */
                pstPhysicalCh = &stChSetting.astPhysicalCh[u8RFCh];
                pstPhysicalCh->u16VirChInfoStartIdx = stChSetting.astPhysicalCh[u8RFCh-1].u16VirChInfoStartIdx + stChSetting.astPhysicalCh[u8RFCh-1].u8NumOfVirCh;
                l_pastVirtualChInfo = &stChSetting.astVirtualChInfo[pstPhysicalCh->u16VirChInfoStartIdx];

                if(stGenSetting.stScanMenuSetting.u8CableSystem==CABLE_SYSTEM_AUTO)
                {
                    Cable_Sys_Found = CABLE_SYSTEM_STD;
                }
                else
                {
                    Cable_Sys_Found = stGenSetting.stScanMenuSetting.u8CableSystem;
                }
                MApp_ScanMenu_GetTPSetting(u8RFCh, &stTPSetting,Cable_Sys_Found);
            }
            else
            {
                enAtscSCanState=STATE_SCAN_GET_TPSETTINGS;
            }

            break;
        } // end of case STATE_SCAN_DB_PREPROCESS:
        //======================================================================
    #endif // #if (CHANNEL_ADD_AND_MERGE_FUNC == ENABLE)


        case STATE_SCAN_TUNE_TO_RF_CH:
        {
            //SCAN_DBINFO_ATSC(printf("STATE_SCAN_TUNE_TO_RF_CH --- >> u8RFCh %d\n", u8RFCh));

          #if (SEARCH_CABLE_ATV_DTV_TOGETHER == ENABLE)
            if(enScanChannelType == SCAN_DIGITAL_CHANNEL)
            {
                enAtscTune2RfSubState = (ANT_TYPE==ANT_AIR) ? VSB_SCAN_STATE : QAM_SCAN_STATE;
            }
          #endif

            if(enAtscTune2RfSubState == NTSC_SCAN_STATE)
            {
              #if 0//(ENABLE_TVSCAN_DEBUGINFO)
                printf("enAtscTune2RfSubState --- >> NTSC_SCAN_STATE\n");
              #endif
                bIsScanNSTCState = 1;
                TVSCAN_STEP_SETUP();

                msAPI_AVD_SetHsyncDetectionForTuning(TRUE);
                enCurStatus = msAPI_NTSC_Scan(&stTPSetting, u8RFCh, (EN_SCAN_ANT_TYPE)ANT_TYPE);
                msAPI_AVD_SetHsyncDetectionForTuning(FALSE);

              #if 0//ENABLE_TVSCANSTEPTIME
                printf("msAPI_NTSC_Scan total=%ld ms\n", msAPI_Timer_DiffTimeFromNow(gU32TVScanStepTime));
              #endif

                if (UNLOCK==enCurStatus)
                {
                  #if (SEARCH_CABLE_ATV_DTV_TOGETHER == ENABLE)
                    if ( enScanChannelType == SCAN_ANALOG_CHANNEL )
                    {
                        enAtscSCanState = STATE_SCAN_GET_TPSETTINGS;
                    }
                    else
                    {
                       #if SEARCH_DTV_ATV_TOGETHER_DTV_FIRST
                        enAtscSCanState = STATE_SCAN_GET_TPSETTINGS;
                       #else
                        enAtscTune2RfSubState = (ANT_TYPE==ANT_AIR) ? VSB_SCAN_STATE : QAM_SCAN_STATE;
                       #endif
                    }
                  #else
                    enAtscSCanState = STATE_SCAN_GET_TPSETTINGS;
                  #endif
                }
                else if (LOCK==enCurStatus)
                {
                    enAtscSCanState = STATE_SCAN_CHECK_VD_LOCK_STATUS;
                }
                else
                {
                    break;
                }
            }
            else if(enAtscTune2RfSubState==VSB_SCAN_STATE)
            {
              #if 0//(ENABLE_TVSCAN_DEBUGINFO)
                printf("enAtscTune2RfSubState --- >> VSB_SCAN_STATE\n");
              #endif

                bIsScanNSTCState = 0;
                TVSCAN_STEP_SETUP();

                enCurStatus = msAPI_VSB_Scan(&stTPSetting);

              #if 0//ENABLE_TVSCANSTEPTIME
                printf("msAPI_VSB_Scan total =%ld ms\n", msAPI_Timer_DiffTimeFromNow(gU32TVScanStepTime));
              #endif

                if (UNLOCK == enCurStatus)
                {
                  #if (!SEARCH_DTV_ATV_TOGETHER_DTV_FIRST)
                    if(fScanType == AUTO_SCAN)
                     {
                        enAtscSCanState = STATE_SCAN_GET_TPSETTINGS;
                     }
                    else
                     {
                        enAtscTune2RfSubState = NTSC_SCAN_STATE;
                     }
                  #endif

                #if (SEARCH_CABLE_ATV_DTV_TOGETHER == ENABLE)
                 #if SEARCH_DTV_ATV_TOGETHER_DTV_FIRST
                  #if (CHANNEL_ADD_AND_MERGE_FUNC==ENABLE)
                    if(Auto_Scan_Add_CH_flag)
                    {
                        enAtscSCanState = STATE_SCAN_GET_TPSETTINGS;
                    }
                    else
                  #endif
                    {
                        enAtscTune2RfSubState=NTSC_SCAN_STATE;
                    }
                  #else
                    {
                        enAtscSCanState = STATE_SCAN_GET_TPSETTINGS;
                    }
                  #endif
                #endif
                }
                else if (LOCK==enCurStatus)
                {
                    enAtscSCanState = STATE_SCAN_GET_TABLE;
                }
                else
                {
                    break;
                }
            }
            else    //enAtscTune2RfSubState=QAM_SCAN_STATE
            {
              #if 0//(ENABLE_TVSCAN_DEBUGINFO)
                printf("enAtscTune2RfSubState --- >> QAM_SCAN_STATE\n");
              #endif

                bIsScanNSTCState = 0;
                if(bQamScan)
                {
                    TVSCAN_STEP_SETUP();
                  #if ENABLE_NEW_QAM_SCAN
                    if (u8FreqLockEver ==0)
                    {
                        enCurStatus = msAPI_QAM_Scan(&stTPSetting);
                    }
                    else
                    {
                        MapChanToFreq(u8RFCh, &stTPSetting, Cable_Sys_Lock);
                        enCurStatus = msAPI_QAM_Scan(&stTPSetting);
                    }
                  #else
                    enCurStatus = msAPI_QAM_Scan(&stTPSetting);
                  #endif

                  #if 0//ENABLE_TVSCANSTEPTIME
                    printf("msAPI_QAM_Scan total=%ld ms\n", msAPI_Timer_DiffTimeFromNow(gU32TVScanStepTime));
                  #endif

                    if (UNLOCK==enCurStatus)
                    {
                        bQamScan = FALSE;
                    }
                    else if (LOCK==enCurStatus)
                    {
                        enAtscSCanState = STATE_SCAN_GET_TABLE;
                    #if ENABLE_NEW_QAM_SCAN
                        if(u8FreqLockEver == 0)
                        {
                            if(u8RFCh>=7)//can't identify STD and IRC before ch7
                            {
                                MS_TP_SETTING_ATSC stTPSettingTemp;
                                MApp_ScanMenu_GetTPSetting(u8RFCh, &stTPSettingTemp, CABLE_SYSTEM_STD);
                                if(stTPSettingTemp.u16Frequency == stTPSetting.u16Frequency)
                                {
                                    Cable_Sys_Lock = CABLE_SYSTEM_STD;
                                    //Cable_Sys_Lock
                                    u8FreqLockEver = 1;
                                }
                                else
                                {
                                    MApp_ScanMenu_GetTPSetting(u8RFCh, &stTPSettingTemp, CABLE_SYSTEM_HRC);
                                    if(stTPSettingTemp.u16Frequency == stTPSetting.u16Frequency)
                                    {
                                        Cable_Sys_Lock = CABLE_SYSTEM_HRC;
                                        u8FreqLockEver = 1;
                                    }
                                    MApp_ScanMenu_GetTPSetting(u8RFCh, &stTPSettingTemp, CABLE_SYSTEM_IRC);
                                    if(stTPSettingTemp.u16Frequency == stTPSetting.u16Frequency)
                                    {
                                        Cable_Sys_Lock = CABLE_SYSTEM_IRC;
                                        u8FreqLockEver = 1;
                                    }
                                }

                            }
                            else//HRC
                            {
                                MS_TP_SETTING_ATSC stTPSettingTemp;
                                MApp_ScanMenu_GetTPSetting(u8RFCh, &stTPSettingTemp, CABLE_SYSTEM_HRC);
                                if(stTPSettingTemp.u16Frequency == stTPSetting.u16Frequency)
                                {
                                    Cable_Sys_Lock = CABLE_SYSTEM_HRC;
                                    u8FreqLockEver = 1;
                                }
                            }
                        }
                    #endif // #if ENABLE_NEW_QAM_SCAN
                        //check STD/HRC/IRC
                    }
                    else
                    {
                       break;
                    }
                }

            #if ENABLE_8VSBSCAN_IN_CABLE
                if(!bQamScan)
                {
                    enCurStatus=msAPI_VSB_Scan(&stTPSetting);

                    if (LOCK = =enCurStatus)
                    {
                        bQamScan = TRUE;
                        enAtscSCanState = STATE_SCAN_GET_TABLE;
                    }
                }
            #endif

                if (UNLOCK == enCurStatus)
                {
                    bQamScan = TRUE;
                    enAtscSCanState = STATE_SCAN_GET_TPSETTINGS;
                    if(stGenSetting.stScanMenuSetting.u8CableSystem == CABLE_SYSTEM_AUTO)
                    {
                      #if ENABLE_NEW_QAM_SCAN
                        if (u8FreqLockEver != 0)
                        {
                          #if SEARCH_DTV_ATV_TOGETHER_DTV_FIRST
                            MApp_ScanMenu_GetTPSetting(u8RFCh, &stTPSetting,CABLE_SYSTEM_STD);
                            enAtscTune2RfSubState=NTSC_SCAN_STATE;
                            enAtscSCanState = STATE_SCAN_TUNE_TO_RF_CH;
                          #endif
                        }
                        else
                      #endif
                        {
                            if (MApp_Scan_CheckIRCHRC(&Cable_Sys_Found))
                            {
                                enAtscSCanState = STATE_SCAN_TUNE_TO_RF_CH;
                               #if (SEARCH_CABLE_ATV_DTV_TOGETHER == DISABLE)
                                enAtscTune2RfSubState = QAM_SCAN_STATE;
                               #endif

                                bInitDemod = TRUE;
                            }
                          #if SEARCH_DTV_ATV_TOGETHER_DTV_FIRST
                            else
                            {
                                MApp_ScanMenu_GetTPSetting(u8RFCh, &stTPSetting,CABLE_SYSTEM_STD);
                                enAtscTune2RfSubState=NTSC_SCAN_STATE;
                                enAtscSCanState = STATE_SCAN_TUNE_TO_RF_CH;
                            }
                          #endif
                        }
/*
                      #if ENABLE_NEW_QAM_SCAN
                        if(u8FreqLockEver == 0)
                      #endif
                        {
                            if(MApp_Scan_CheckIRCHRC(&Cable_Sys_Found))
                            {
                                enAtscSCanState = STATE_SCAN_TUNE_TO_RF_CH;
                               #if (SEARCH_CABLE_ATV_DTV_TOGETHER == DISABLE)
                                enAtscTune2RfSubState = QAM_SCAN_STATE;
                               #endif

                                bInitDemod = TRUE;
                            }
                          #if SEARCH_DTV_ATV_TOGETHER_DTV_FIRST
                            else
                            {
                                MApp_ScanMenu_GetTPSetting(u8RFCh, &stTPSetting,CABLE_SYSTEM_STD);
                                enAtscTune2RfSubState=NTSC_SCAN_STATE;
                                enAtscSCanState = STATE_SCAN_TUNE_TO_RF_CH;
                            }
                          #endif
                        }
                      #if ENABLE_NEW_QAM_SCAN
                        else
                        {
                          #if SEARCH_DTV_ATV_TOGETHER_DTV_FIRST
                            MApp_ScanMenu_GetTPSetting(u8RFCh, &stTPSetting,CABLE_SYSTEM_STD);
                            enAtscTune2RfSubState=NTSC_SCAN_STATE;
                            enAtscSCanState = STATE_SCAN_TUNE_TO_RF_CH;
                          #endif
                        }
                      #endif
*/
                    }
                }
            }

            if(enAtscSCanState == STATE_SCAN_GET_TPSETTINGS)
            {
                if(fScanType == AUTO_SCAN)
                {
                #if (CHANNEL_ADD_AND_MERGE_FUNC==ENABLE)
                    if(Auto_Scan_Add_CH_flag==1)
                    {
                        enAtscSCanState = STATE_SCAN_RELEASE_BUF;//STATE_SCAN_GET_NO_DB_CH;
                    }
                #endif

                #if (ASSIGN_NTSC_PROGRAM_AS_DEFAULT_CH == ENABLE)
                    if ( (pstPhysicalCh->u8NumOfVirCh==0)
                      #if (SEARCH_CABLE_ATV_DTV_TOGETHER == DISABLE)
                       && (enAtscTune2RfSubState == NTSC_SCAN_STATE)
                      #endif
                       )
                    {
                        fAddEmptyNTSCProg = TRUE;
                        enAtscSCanState = STATE_SCAN_CHECK_VD_LOCK_STATUS;
                    }
                #endif
                }
                else if(fScanType == MANUAL_SCAN)
                {
                    enAtscSCanState = STATE_SCAN_SCAN_END;
                    /* store this RF directly if FE not lock by direct tune function */
                    if(u8ManualScanStatus && pstPhysicalCh->u8NumOfVirCh==0)
                    {
                        MApp_Scan_AddDirTuneCh(stTPSetting.u16Frequency);
                    }
                }
            }

            break;
        } // end of case STATE_SCAN_TUNE_TO_RF_CH:
        //======================================================================


        case STATE_SCAN_CHECK_VD_LOCK_STATUS:
        {
            SCAN_DBINFO_ATSC(printf("STATE_SCAN_CHECK_VD_LOCK_STATUS>> \r\n"));
            TVSCAN_STEP_SETUP();

          #if  (SCAN_NTSC_SIGNAL_ONLY==ENABLE)
            if (  ((pstPhysicalCh->u8NumOfVirCh == 0) /*(msAPI_VD_CheckIsTVSys()==VD_525_LINE)*/) // remove it for only NTSC  scan flow
              #if (ASSIGN_NTSC_PROGRAM_AS_DEFAULT_CH == ENABLE)
               || (fAddEmptyNTSCProg == TRUE)
              #endif
               )
          #else
            if (pstPhysicalCh->u8NumOfVirCh==0)
          #endif
            {
                if ((fScanType == AUTO_SCAN) && (u8RFCh < u8MaxRFCh))
                {
                    u16NumOfVirCh2bShifted = (u16NumOfSrvAdd+1) - stChSetting.astPhysicalCh[u8RFCh+1].u16VirChInfoStartIdx;
                    MSAPI_MEMORY_FREE(pastVirtualChInfo_2,BUF_ID_ATSC);
                    if(u16NumOfVirCh2bShifted)
                    {
                        pastVirtualChInfo_2 = (MS_VIRTUAL_CHANNEL_INFO *)msAPI_Memory_Allocate(sizeof(MS_VIRTUAL_CHANNEL_INFO) * u16NumOfVirCh2bShifted, BUF_ID_ATSC);
                        if (pastVirtualChInfo_2 == NULL)
                        {
                            __ASSERT(0);
                            enAtscSCanState = STATE_SCAN_SCAN_END;
                            break;
                        }
                        memcpy((U8*)(pastVirtualChInfo_2),
                               (U8*)(&stChSetting.astVirtualChInfo[stChSetting.astPhysicalCh[u8RFCh+1].u16VirChInfoStartIdx]),
                               sizeof(MS_VIRTUAL_CHANNEL_INFO)*u16NumOfVirCh2bShifted);
                    }
                    else
                    {
                        pastVirtualChInfo_2 = NULL;
                    }

                    pstPhysicalCh = &stChSetting.astPhysicalCh[u8RFCh];
                    pstPhysicalCh->u16VirChInfoStartIdx = stChSetting.astPhysicalCh[u8RFCh-1].u16VirChInfoStartIdx + stChSetting.astPhysicalCh[u8RFCh-1].u8NumOfVirCh;
                    l_pastVirtualChInfo = &stChSetting.astVirtualChInfo[pstPhysicalCh->u16VirChInfoStartIdx];
                }

                /* store front end setting */
                memset(pastVirtualCh, 0x00, sizeof(MS_VIRTUAL_CHANNEL));
                memset(l_pastVirtualChInfo, 0x00, sizeof(MS_VIRTUAL_CHANNEL_INFO));

            #if (ASSIGN_NTSC_PROGRAM_AS_DEFAULT_CH == ENABLE)
                if (fAddEmptyNTSCProg == TRUE)
                {
                    l_pastVirtualChInfo->fIsHideCh = TRUE;
                }
            #endif

            #if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
                pastRfCh.stTPSetting.u16Frequency = stTPSetting.u16Frequency;
                pastRfCh.stTPSetting.fModulation = DEMOD_ATSC_MODE_NTSC;
                pastVirtualCh[0].u8RfNum = u8RFCh;
            #else
                pastVirtualCh[0].stTPSetting.u16Frequency = stTPSetting.u16Frequency;
                pastVirtualCh[0].stTPSetting.fModulation = DEMOD_ATSC_MODE_NTSC;
            #endif

                pastVirtualCh[0].stVirtualChNum.major_num = u8RFCh;
                pastVirtualCh[0].stVirtualChNum.minor_num = 0;

            #if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
                MApp_DB_SaveRfChannel((U16) u8RFCh, &pastRfCh);
            #endif

                SCAN_DBINFO_ATSC(printf("[Save ATV Channel:Num-Frq: %d -%x,Major-Minor: %d-%d]\n",
                            u8RFCh, stTPSetting.u16Frequency,
                            (U8)pastVirtualCh[0].stVirtualChNum.major_num,
                            (U8)pastVirtualCh[0].stVirtualChNum.minor_num));

                if(MApp_Scan_AddSrv2DB(pstPhysicalCh, l_pastVirtualChInfo, pastVirtualCh, (EN_ANT_TYPE)ANT_TYPE))
                {
                  #if (ASSIGN_NTSC_PROGRAM_AS_DEFAULT_CH == ENABLE)
                    if(fAddEmptyNTSCProg == TRUE)
                   {
                       u16NumOfNoSignalNTSCSrvAdd ++;
                   }
                   else
                  #endif
                    {
                        u16NumOfNTSCSrvAdd++;
                    }

                    if(fScanType == AUTO_SCAN)
                    {
                      #if (CHANNEL_ADD_AND_MERGE_FUNC==ENABLE)
                        if(Auto_Scan_Add_CH_flag==1)
                        {
                           enAtscSCanState = STATE_SCAN_RELEASE_BUF;
                        }
                        else
                        {
                           enAtscSCanState = STATE_SCAN_GET_TPSETTINGS;
                        }
                      #else
                        enAtscSCanState = STATE_SCAN_GET_TPSETTINGS;
                      #endif
                    }
                    else
                    {
                        enAtscSCanState = STATE_SCAN_SCAN_END;
                    }

                    if(fScanType == AUTO_SCAN)
                    {
                        for(u8Loop=u8RFCh+1; u8Loop<=u8MaxRFCh; u8Loop++)
                        {
                            stChSetting.astPhysicalCh[u8Loop].u16VirChInfoStartIdx = stChSetting.astPhysicalCh[u8Loop-1].u16VirChInfoStartIdx + stChSetting.astPhysicalCh[u8Loop-1].u8NumOfVirCh;
                        }

                        if(u16NumOfVirCh2bShifted)
                        {
                            memcpy((U8*)(&stChSetting.astVirtualChInfo[stChSetting.astPhysicalCh[u8RFCh+1].u16VirChInfoStartIdx]),
                                   (U8*)(pastVirtualChInfo_2),
                                   sizeof(MS_VIRTUAL_CHANNEL_INFO)*u16NumOfVirCh2bShifted);

                            MSAPI_MEMORY_FREE(pastVirtualChInfo_2,BUF_ID_ATSC);
                            u16NumOfVirCh2bShifted = 0;
                        }
                    }

                }
                else
                {
                     enAtscSCanState = STATE_SCAN_SCAN_END; //database full
                }

              #if (CHANNEL_SCAN_AUTO_TEST)
                if(g_ScanAutoTestData.u2State == 1)
                {
                    g_ScanAutoTestData.u12ChFoundNum++;
                    SCAN_DBINFO_ATSC(printf("SCAN: Find NTSC.\r\n"));
                    if(g_ScanAutoTestData.u12ChFoundNum == g_ScanAutoTestData.u12ChNum)
                    {
                        g_ScanAutoTestData.fCommand = 0;
                    }
                }
              #endif

                if ( (fScanType == AUTO_SCAN) && u16NumOfVirCh2bShifted )
                {
                    MSAPI_MEMORY_FREE(pastVirtualChInfo_2,BUF_ID_ATSC);
                    u16NumOfVirCh2bShifted = 0;
                }
            }
            else
            {
                /* store this RF directly if VD not lock by direct tune function */
                if (E_OSD_EMPTY == MApp_ZUI_GetActiveOSD() && pstPhysicalCh->u8NumOfVirCh==0)
                {
                    MApp_Scan_AddDirTuneCh(stTPSetting.u16Frequency);
                }

                if(fScanType == AUTO_SCAN)
                {
                  #if (CHANNEL_ADD_AND_MERGE_FUNC==ENABLE)
                    if(Auto_Scan_Add_CH_flag==1)
                    {
                        enAtscSCanState = STATE_SCAN_RELEASE_BUF;
                    }
                    else
                    {
                        enAtscSCanState = STATE_SCAN_GET_TPSETTINGS;
                    }
                  #else
                    enAtscSCanState = STATE_SCAN_GET_TPSETTINGS;
                  #endif
                }
                else
                {
                    enAtscSCanState = STATE_SCAN_SCAN_END;
                }
            }

        #if ENABLE_TVSCANSTEPTIME
           printf("STATE_SCAN_CHECK_VD_LOCK_STATUS =%ld ms\n", msAPI_Timer_DiffTimeFromNow(gU32TVScanStepTime));
        #endif

            break;
        } // end of case STATE_SCAN_CHECK_VD_LOCK_STATUS:
        //======================================================================


        case STATE_SCAN_GET_TABLE:
        {
            SCAN_DBINFO_ATSC(printf("STATE_SCAN_GET_TABLE>> \r\n"));
            TVSCAN_STEP_SETUP();

            //disable AVD and comb filter
            msAPI_AVD_Exit();

            if(fScanType == AUTO_SCAN)
            {
            #if (CHANNEL_ADD_AND_MERGE_FUNC==ENABLE)
                if(Auto_Scan_Add_CH_flag==1)
                {
                    enAtscSCanState = STATE_SCAN_RELEASE_BUF;
                }
                else
                {
                   enAtscSCanState = STATE_SCAN_GET_TPSETTINGS;
                }
            #else
              #if 0//SEARCH_DTV_ATV_TOGETHER_DTV_FIRST
                if(bQamScan)
                {
                    MApp_ScanMenu_GetTPSetting(u8RFCh, &stTPSetting, CABLE_SYSTEM_STD);
                }
                enAtscTune2RfSubState = NTSC_SCAN_STATE;
                enAtscSCanState = STATE_SCAN_TUNE_TO_RF_CH;
              #else
                enAtscSCanState = STATE_SCAN_GET_TPSETTINGS;
              #endif
            #endif
            }
            else
            {
                enAtscSCanState = STATE_SCAN_SCAN_END;
            }

          #if TS_THROUGH_LVDS
            enAtscSCanState = STATE_SCAN_SCAN_END;
          #endif

            if (MApp_Dmx_GetScanTables_ATSC() == EN_PARSER_NO_ERROR)
            {
              #if (CHANNEL_SCAN_AUTO_TEST)
                if(g_ScanAutoTestData.u2State == 1)
                {
                    SCAN_DBINFO_ATSC(printf("SCAN: Find ATSC.\r\n"));
                    g_ScanAutoTestData.u12ChFoundNum++;
                    if(g_ScanAutoTestData.u12ChFoundNum == g_ScanAutoTestData.u12ChNum)
                    {
                        g_ScanAutoTestData.fCommand = 0;
                    }
                }
              #endif

                BOOL bEraseCurCh = (fScanType == MANUAL_SCAN) ? TRUE : FALSE;

                bPidChang = 0;
                u8LastScPatNum=0;
                u8NumOfTimeOutProg = 0;

              #if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
                /* store front end setting */
                pastRfCh.stTPSetting.u16Frequency = stTPSetting.u16Frequency;
                pastRfCh.stTPSetting.fModulation = stTPSetting.fModulation;
                pastRfCh.stTPSetting.fSpectrum = stTPSetting.fSpectrum;
              #if (ENABLE_MAX_RRT_DIMENSION_NUMBER)
                pastRfCh.u8NumOfPatItem = u8NumOfPatItem;
              #endif
                MApp_DB_SaveRfChannel((U16)u8RFCh, &pastRfCh);
              #endif

                for(u8Loop = 0; u8Loop < u8TotalTableItem; u8Loop++)
                {
                    /* use pastShortVirtualCh and pastVirtualCh in sram directly */
                    pstVirtualCh = &pastVirtualCh[u8Loop];
                    pstVirtualCh_VCT = &pastVirtualCh_VCT[u8Loop];

                    if (MApp_Scan_CheckServiceInfo(pstVirtualCh,pastVirtualCh_VCT,u8Loop) == FALSE)
                    {
                        SCAN_DBINFO_ATSC(printf("MApp_Scan_CheckServiceInfo %d fail (Null Service)!\r\n", u8Loop));

                        pstVirtualCh->bScrambleCH = TRUE;

                        if (fSaveScrambleChannel==FALSE)
                        {
                            if ( (pstVirtualCh->u16VideoPid != 0)
                              #if (STORE_RD_CH_ENABLE == 1)
                               &&(pstVirtualCh->astSoundTrack[0].u16AudioPid != 0 )
                               &&(pastVirtualCh_VCT->astSoundTrack[0].u16AudioPid != 0)
                              #endif
                                )
                            {
                                fSaveScrambleChannel = TRUE;
                                memcpy(&(pstLastVirtualCh), (pstVirtualCh), sizeof(MS_VIRTUAL_CHANNEL));
                              #if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
                                // Error: pstLastRfCh is null pointer
                                //pstLastRfCh->stTPSetting.u16Frequency = stTPSetting.u16Frequency;
                                //pstLastRfCh->stTPSetting.fModulation = stTPSetting.fModulation;
                                //pstLastRfCh->stTPSetting.fSpectrum = stTPSetting.fSpectrum;
                              #else
                                pstLastVirtualCh.stTPSetting.u16Frequency = stTPSetting.u16Frequency;
                                pstLastVirtualCh.stTPSetting.fModulation = stTPSetting.fModulation;
                                pstLastVirtualCh.stTPSetting.fSpectrum = stTPSetting.fSpectrum;
                              #endif

                                /* if VCT not received, set minor number = program number */
                                if(pstVirtualCh->stVirtualChNum.major_num == 0)
                                {
                                    pstLastVirtualCh.stVirtualChNum.major_num = u8RFCh;
                                  #if (ENABLE_EXTERN_DTV_MAX_MINOR_NO)
                                    pstLastVirtualCh.stVirtualChNum.minor_num = pastPATItem[u8Loop].u16BuildChNumber;
                                  #else
                                    //Ben.Luo add to display four digit minor number 20110930
                                    pstLastVirtualCh.stVirtualChNum.minor_num = pstVirtualCh->u16ProgramNumber;
                                  #endif

                                  #if(ENABLE_NONDUPLICATE_PROGRAM_NAME == ENABLE)
                                    pstLastVirtualCh.stVirtualChNum.fIsNoVctCh = TRUE;
                                  #endif
                                }
                            }
                            //save one scramble channel for temp using
                        }
                        continue;
                    }

                    if(bEraseCurCh)
                    {
                        bEraseCurCh = FALSE;
                        MApp_Scan_EraseCurCh();
                    }
                    pstVirtualCh->bScrambleCH = FALSE;

                    if ( (pstVirtualCh->u8ServiceType == 0)
                       && ( (pstVirtualCh->u16VideoPid == 0x00)
                          ||(pastVirtualCh->u16VideoPid == 0x01)
                          ||(pstVirtualCh->u8AudLangNum > 0) )
                       )
                    {
                        pstVirtualCh->u8ServiceType = EN_PSIP_SERVICE_DTV;
                    }

                    //Skip service type not DTV and Audio only.
                    /*
                    if((pstVirtualCh->u8ServiceType != EN_PSIP_SERVICE_DTV) &&
                       (pstVirtualCh->u8ServiceType != EN_PSIP_SERVICE_AUDIO))
                       continue;
                    */

                    /* store front end setting */
                #if (NEW_VIRTUAL_CHANNEL_STRUCTURE == DISABLE)
                    pstVirtualCh->stTPSetting.u16Frequency = stTPSetting.u16Frequency;
                    pstVirtualCh->stTPSetting.fModulation = stTPSetting.fModulation;
                    pstVirtualCh->stTPSetting.fSpectrum = stTPSetting.fSpectrum;
                #endif

                    /* if VCT not received, set minor number = program number */
                    if(pstVirtualCh->stVirtualChNum.major_num == 0)
                    {
                        pstVirtualCh->stVirtualChNum.major_num = u8RFCh;

                      #if (ENABLE_EXTERN_DTV_MAX_MINOR_NO)
                        pstVirtualCh->stVirtualChNum.minor_num = pastPATItem[u8Loop].u16BuildChNumber;
                      #else
                        //Ben.Luo add to display four digit minor number 20110930
                        pstVirtualCh->stVirtualChNum.minor_num = pstVirtualCh->u16ProgramNumber;
                      #endif

                      #if(ENABLE_NONDUPLICATE_PROGRAM_NAME == ENABLE)
                        pstVirtualCh->stVirtualChNum.fIsNoVctCh = TRUE;
                      #endif
                    }

                #if ENABLE_NONDUPLICATE_PROGRAM_NAME
                    if (!fTableVersionChanged)
                    {
                        MS_VIRTUAL_CHANNEL stVirtualCh_temp;
                        U16 u16DBIdx, u16DBChNum;

                        if(fScanType == AUTO_SCAN)
                            u16DBChNum = u16NumOfSrvAdd;
                        else
                            u16DBChNum = stChSetting.u16MainListSrvNum;

                        u16DBChNum += u8TotalTableItem;
                        for (u16DBIdx =1; u16DBIdx<u16DBChNum+1; u16DBIdx++)
                        {
                            MApp_ChanProc_GetSingleChannel(&stVirtualCh_temp, u16DBIdx);

                            //Check duplicate channel.
                            if ( (stVirtualCh_temp.stVirtualChNum.major_num == pstVirtualCh->stVirtualChNum.major_num) &&
                                (stVirtualCh_temp.stVirtualChNum.minor_num == pstVirtualCh->stVirtualChNum.minor_num) )
                            {
                                U16 u16TempSrvIdx = 1,u16SrvFoundIdx=0;
                                U16 u16MajorNum=0,u16MinorNum=0;

                                //minor number + 1 to compare again from start of DB.
                                if(TRUE == pstVirtualCh->stVirtualChNum.fIsNoVctCh)
                                    pstVirtualCh->stVirtualChNum.minor_num += 1;
                                else if(TRUE == stVirtualCh_temp.stVirtualChNum.fIsNoVctCh)
                                    stVirtualCh_temp.stVirtualChNum.minor_num += 1;

                                u16MajorNum = stVirtualCh_temp.stVirtualChNum.major_num;
                                u16MinorNum = stVirtualCh_temp.stVirtualChNum.minor_num;

                                SCAN_DBINFO_ATSC(printf("\nScan %d Major-Minor: %d-%d",
                                    (U8) u8RFCh,
                                    (U8)pstVirtualCh->stVirtualChNum.major_num,
                                    (U8)pstVirtualCh->stVirtualChNum.minor_num));

                                do
                                {
                                    MApp_ChanProc_GetSingleChannel(&stVirtualCh_temp, u16TempSrvIdx);

                                    if( (stVirtualCh_temp.stVirtualChNum.major_num == u16MajorNum)
                                        &&(stVirtualCh_temp.stVirtualChNum.minor_num == u16MinorNum)
                                        &&(u16SrvFoundIdx != u16TempSrvIdx))
                                    {
                                        if(TRUE == pstVirtualCh->stVirtualChNum.fIsNoVctCh)
                                        {
                                            pstVirtualCh->stVirtualChNum.minor_num += 1;
                                            pstVirtualCh->stVirtualChNum.major_num = u16MajorNum;
                                            u16MinorNum = pstVirtualCh->stVirtualChNum.minor_num ;
                                        }
                                        else if(TRUE == stVirtualCh_temp.stVirtualChNum.fIsNoVctCh)
                                        {
                                            stVirtualCh_temp.stVirtualChNum.minor_num += 1;
                                            stVirtualCh_temp.stVirtualChNum.major_num = u16MajorNum;
                                            u16MinorNum = stVirtualCh_temp.stVirtualChNum.minor_num ;
                                            //if same channel is stored in DB overwrite it.
                                            MApp_DB_ATSC_SaveVirChannel(u16TempSrvIdx, &stVirtualCh_temp);
                                        }
                                        u16SrvFoundIdx = u16TempSrvIdx;
                                        u16TempSrvIdx = 0;
                                    }
                                }while(++u16TempSrvIdx < u16DBChNum+1);
                                break;
                            }
                        }
                    }
                #endif

                #if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
                    pstVirtualCh->u8RfNum = u8RFCh;
                #endif

                    SCAN_DBINFO_ATSC(printf("[Save DTV Channel: num-freq:%d-%x ,Major-Minor: %d-%d]\n",
                        (U8) u8RFCh, stTPSetting.u16Frequency,
                        (U8)pstVirtualCh->stVirtualChNum.major_num,
                        (U8)pstVirtualCh->stVirtualChNum.minor_num));

                    memcpy(&l_pastVirtualChInfo[pstPhysicalCh->u8NumOfVirCh], &pastVirtualChInfo[u8Loop], sizeof(MS_VIRTUAL_CHANNEL_INFO));

                #if (ENABLE_MAX_RRT_DIMENSION_NUMBER == 1)
                  #if (NEW_VIRTUAL_CHANNEL_STRUCTURE == DISABLE)
                    pstVirtualCh->u8NumOfPatItem = u8NumOfPatItem;
                  #endif
                #endif
                    if(MApp_Scan_AddSrv2DB(pstPhysicalCh, &l_pastVirtualChInfo[pstPhysicalCh->u8NumOfVirCh], pstVirtualCh, (EN_ANT_TYPE)ANT_TYPE) == FALSE)
                    {
                        enAtscSCanState = STATE_SCAN_SCAN_END; //database full
                        break;
                    }
                }

                if ( (fScanType==MANUAL_SCAN) && (pstPhysicalCh->u8NumOfVirCh==0))
                {
                  #if ( ENABLE_ADD_FAKECHANNEL_WITH_NO_SERVICES)
                    // no virtual channels, so add a fake channel
                    if (fTableVersionChanged)
                    {
                        if(bEraseCurCh)
                        {
                            MApp_Scan_EraseCurCh();
                        }

                        //stay at last DTV channel and update specfic table info
                      #if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
                        MS_RF_CHANNEL_new RfCh;
                        MApp_ChanProc_GetRfChannelPointer(pstVirtualCh,&RfCh);
                        RfCh.u16TsId = pastRfCh.u16TsId;
                        RfCh.u8PatVersion = pastRfCh.u8PatVersion;
                        RfCh.u8PmtVersion = pastRfCh.u8PmtVersion;
                        RfCh.u8VctVersion = pastRfCh.u8VctVersion;
                        MApp_DB_SaveRfChannel(u8RFCh, &RfCh);
                      #else
                        pstLastVirtualCh.u16TsId = pstVirtualCh->u16TsId;
                        pstLastVirtualCh.u8PatVersion = pstVirtualCh->u8PatVersion;
                        pstLastVirtualCh.u8PmtVersion = pstVirtualCh->u8PmtVersion;
                        pstLastVirtualCh.u8VctVersion = pstVirtualCh->u8VctVersion;
                      #endif

                        pstLastVirtualCh.u16ProgramNumber = pstVirtualCh->u16ProgramNumber;
                        pstLastVirtualCh.u16PmtPid = pstVirtualCh->u16PmtPid;
                        pstLastVirtualCh.u16VideoPid = pstVirtualCh->u16VideoPid;
                        pstVirtualCh->bScrambleCH = TRUE;
                        MApp_Scan_AddSrv2DB(pstPhysicalCh, &l_pastVirtualChInfo[pstPhysicalCh->u8NumOfVirCh], &(pstLastVirtualCh), (EN_ANT_TYPE)ANT_TYPE);
                    }
                    else
                  #endif
                    {
                        MApp_Scan_AddDirTuneCh(stTPSetting.u16Frequency);
                    }
                }

                if (fScanType == MANUAL_SCAN && MApp_ChanProc_GetCurMainListProgIndex() != INVALID_SERVICE_IDX)
                {
                    MApp_ChanProc_GetSingleChannel(&g_stVirtualCh, VIR_CH_IDX(MApp_ChanProc_GetCurMainListProgIndex()));
                }
            }
            else
            {
                 /* store this RF directly if DEMUX not lock by direct tune function */
                if(E_OSD_EMPTY==MApp_ZUI_GetActiveOSD() && pstPhysicalCh->u8NumOfVirCh==0)
                {
                    MApp_Scan_AddDirTuneCh(stTPSetting.u16Frequency);
                }
            }

          #if ENABLE_TVSCANSTEPTIME
            printf("STATE_SCAN_GET_TABLE =%ld ms\n", msAPI_Timer_DiffTimeFromNow(gU32TVScanStepTime));
          #endif

            break;
        } // end of case STATE_SCAN_GET_TABLE:
        //======================================================================


    #if (CHANNEL_ADD_AND_MERGE_FUNC == ENABLE)
        case STATE_SCAN_RELEASE_BUF:
        {
            if (Auto_Scan_Add_CH_flag==1)
            {
                stChSetting.u16MainListSrvNum = MApp_ChanProc_CalculateTotalSrvNum(stChSetting.astPhysicalCh, (EN_ANT_TYPE)ANT_TYPE);
                SCAN_DBINFO_ATSC(printf("2,Total Air service # found = %u \r\n", stChSetting.u16MainListSrvNum));
                /* update astPhysicalCh[] and astVirtualChInfo[] from u8RFCh+1 by MANUAL_SCAN */
                if(/*fScanType==MANUAL_SCAN &&*/ u8RFCh<u8MaxRFCh)
                {
                    for(u8Loop=u8RFCh+1; u8Loop<=u8MaxRFCh; u8Loop++)
                    {
                        stChSetting.astPhysicalCh[u8Loop].u16VirChInfoStartIdx = stChSetting.astPhysicalCh[u8Loop-1].u16VirChInfoStartIdx + stChSetting.astPhysicalCh[u8Loop-1].u8NumOfVirCh;
                    }

                    if(u16NumOfVirCh2bShifted)
                    {
                        memcpy((U8*)(&stChSetting.astVirtualChInfo[stChSetting.astPhysicalCh[u8RFCh+1].u16VirChInfoStartIdx]),
                               (U8*)(pastVirtualChInfo_2),
                               sizeof(MS_VIRTUAL_CHANNEL_INFO)*u16NumOfVirCh2bShifted);

                        //msAPI_Memory_Free(pastVirtualChInfo_2);
                        MSAPI_MEMORY_FREE(pastVirtualChInfo_2,BUF_ID_ATSC);
                    }
                    u16NumOfVirCh2bShifted=0;
                }
            }

            enAtscSCanState=STATE_SCAN_GET_TPSETTINGS;

            break;
        } // end of case STATE_SCAN_RELEASE_BUF:
        //======================================================================
    #endif // #if (CHANNEL_ADD_AND_MERGE_FUNC == ENABLE)



        case STATE_SCAN_SCAN_END:
        {
           SCAN_DBINFO_ATSC(printf("STATE_SCAN_SCAN_END>> \r\n"));
           MApp_ZUI_API_SetTimer(HWND_MENU_MASK_BACKGROUND, 0, MENU_TIME_OUT_MS);
           TVSCAN_STEP_SETUP();
          #if (FRONTEND_TUNER_TYPE == NXP_TDA18275A_TUNER)
            TDA18275A_SetAGCsLoopOff(0x00);
            g_bIsChScanning = FALSE;
          #endif

            bQamScan=TRUE;

          #if (CHANNEL_SCAN_AUTO_TEST)
            if(g_ScanAutoTestData.u2State == 1)
            {
                g_ScanAutoTestData.u16SrvFoundNum = u16NumOfSrvAdd;
            }
          #endif

            MApp_Scan_End();

            /* If manual scan or digit key channel change, save database at MApp_TV_Init() and MApp_AnalogInputs_Init().
               Else(auto scan), save database here immediately. */
            // If use EEPROM as database storage, it is faster, so save here.
          #if 0//(!ENABLE_EE_DB)
            if( u8ManualScanStatus )
            { // Direct tune
                fUpdateDataBase = TRUE;
            }
            else
            { // Auto tune
                //MApp_DB_CH_SaveData_RightNow();
                //MApp_DB_GEN_SaveData_RightNow();
            }
          #endif

            // In scan ,  some GenSetting are changed
            MApp_DB_GEN_Set_DataChanged(TRUE);

            fEnableSignalCheck = TRUE;
            if (fChangeChannel)
            {
                enAtscScanRetVal = EXIT_SCAN_DONE;
                MApp_ChannelChange_DisableChannel_ATSC();

              #if (ENABLE_PAT_TIMEOUT_NOSIGNAL)
                f_PrevPatTimeOut = FALSE;
              #endif
            }
            else
            {
              #if (ENABLE_PAT_TIMEOUT_NOSIGNAL)
                if(MApp_Dmx_CheckPATTimeout())
                {
                    f_PrevPatTimeOut = TRUE;
                }

                if((f_PrevPatTimeOut == TRUE)&&(!MApp_Dmx_CheckPATTimeout()))
                {
                    f_PrevPatTimeOut = FALSE;
                    fEnableSignalCheck = FALSE;
                    MApp_ChannelChange_EnableChannel_ATSC();
                }
                else
              #endif
                    MApp_Dmx_EnableTableMonitor_ATSC();

                enAtscScanRetVal = EXIT_SCAN_TRAN_TV;
            }

            msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE,E_AUDIO_INTERNAL_2_MUTEOFF,E_AUDIOMUTESOURCE_ACTIVESOURCE);
            //if((!fTableVersionChanged)&&(IsDTVInUse()))
            //{
            //    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE,E_AUDIO_BYUSER_MUTEOFF,E_AUDIOMUTESOURCE_ACTIVESOURCE);
            //}

            enAtscSCanState = STATE_SCAN_INIT;
            if((u8NumOfTimeOutProg == u8TotalTableItem) && (u8TotalTableItem !=0))
            {
                fTableVersionChanged = TRUE;
            }
            else
            {
                fTableVersionChanged = FALSE;
                fTableAudioStreamTypeChange = FALSE;
            }

          #if (CHANNEL_SCAN_AUTO_TEST)
            if(g_ScanAutoTestData.u2State == 1)
            {
                SCAN_DBINFO_ATSC(printf("SCAN: STATE_SCAN_SCAN_END.\r\n"));
//                g_ScanAutoTestData.u12ChNum = 0;
                // restore the original settings;
                g_ScanAutoTestData.fCommand = 0;
                g_ScanAutoTestData.u2State = 2;
                fScanType = stGenSetting.stScanMenuSetting.u8ScanType = g_ScanAutoTestData.fScanTypeSave;
                stGenSetting.stScanMenuSetting.u8Antenna = g_ScanAutoTestData.f8AntennaSave;
                stGenSetting.stScanMenuSetting.u8CableSystem = g_ScanAutoTestData.u2CableSystemSave;
            }
          #endif

          #if ENABLE_TVSCANSTEPTIME
           printf("STATE_SCAN_SCAN_END =%ld ms\n", msAPI_Timer_DiffTimeFromNow(gU32TVScanStepTime));
          #endif

            break;
        } // end of case STATE_SCAN_SCAN_END:
        //======================================================================


        case STATE_SCAN_GOTO_STANDBY:
        {
            SCAN_DBINFO_ATSC(printf("STATE_SCAN_GOTO_STANDBY>> \r\n"));

          #if (FRONTEND_TUNER_TYPE == NXP_TDA18275A_TUNER)
            TDA18275A_SetAGCsLoopOff(0x00);
          #endif

            MApp_Scan_End();

            msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE,E_AUDIO_BYSYNC_MUTEOFF,E_AUDIOMUTESOURCE_ACTIVESOURCE);

            enAtscScanRetVal = EXIT_SCAN_TRAN_STANDBY;
            enAtscSCanState = STATE_SCAN_INIT;

            break;
        } // end of case STATE_SCAN_GOTO_STANDBY:
        //======================================================================


        default:
            break;
    }

    if ( (enAtscScanRetVal==EXIT_SCAN_DONE)
       ||(enAtscScanRetVal==EXIT_SCAN_TRAN_STANDBY)
       ||(enAtscScanRetVal==EXIT_SCAN_TRAN_TV) )
    {
        if (fScanType == AUTO_SCAN)
        {
            SCAN_DBINFO_ATSC(printf("[Debug Auto %s scan end time] = %ld Min.%dSec\n", (ANT_TYPE==ANT_AIR) ? "Air" : "Cable",msAPI_Timer_DiffTimeFromNow(gU32TVScanTotalTime)/1000/60,msAPI_Timer_DiffTimeFromNow(gU32TVScanTotalTime)/1000%60));
        }
        else
        {
            SCAN_DBINFO_ATSC(printf("[Debug Manual %s scan end time] = %ld Min.%dSec\n", (ANT_TYPE==ANT_AIR) ? "Air" : "Cable",msAPI_Timer_DiffTimeFromNow(gU32TVScanTotalTime)/1000/60,msAPI_Timer_DiffTimeFromNow(gU32TVScanTotalTime)/1000%60));
        }
    }
    return enAtscScanRetVal;
}


void MApp_Get_ZigZag_Freq(U16 *pu16ZigZagFreq, U8 u8ZigZag_Point, MS_VIRTUAL_CHANNEL *CurVirtual_Ch)
{
    U8 u8Cur_RF_Ch;
    U16 u16ORG_FREQ;
    //Backup Org frequency
#if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
    MS_RF_CHANNEL_new pCurRf_Ch;
    MApp_ChanProc_GetRfChannelPointer(CurVirtual_Ch, &pCurRf_Ch);
    //Backup Org frequency
    u16ORG_FREQ = pCurRf_Ch.stTPSetting.u16Frequency;

    //Get the Frequency by RFCh & Cable System
    u8Cur_RF_Ch = CurVirtual_Ch->stVirtualChNum.major_num; //RF_CH_IDX(MApp_ChanProc_GetCurMainListProgIndex());
    if ((pCurRf_Ch.stTPSetting.fModulation==DEMOD_ATSC_MODE_256QAM)||(pCurRf_Ch.stTPSetting.fModulation==DEMOD_ATSC_MODE_64QAM))
    {
        if (u8ZigZag_Point < (CABLE_SYSTEM_TYPE_NUM - 1))    //total number of cable system are three
            MapChanToFreq(u8Cur_RF_Ch, &pCurRf_Ch.stTPSetting, stGenSetting.stScanMenuSetting.u8CableSystem);
    }
    else
    {
        MapChanToFreq(u8Cur_RF_Ch, &pCurRf_Ch.stTPSetting, stGenSetting.stScanMenuSetting.u8CableSystem);
        pCurRf_Ch.stTPSetting.u16Frequency+=msAPI_ScanGetFreqByZigZagPoint((EN_DEMOD_ATSC_MODE)pCurRf_Ch.stTPSetting.fModulation,u8ZigZag_Point,u8Cur_RF_Ch);
    }
    *pu16ZigZagFreq = pCurRf_Ch.stTPSetting.u16Frequency;
    pCurRf_Ch.stTPSetting.u16Frequency = u16ORG_FREQ;

#else
    u16ORG_FREQ = CurVirtual_Ch->stTPSetting.u16Frequency;

    //Get the Frequency by RFCh & Cable System
    u8Cur_RF_Ch = PHY_CH_IDX(MApp_ChanProc_GetCurMainListProgIndex());


    if( (CurVirtual_Ch->stTPSetting.fModulation==DEMOD_ATSC_MODE_256QAM)
      ||(CurVirtual_Ch->stTPSetting.fModulation==DEMOD_ATSC_MODE_64QAM))
    {
        if (u8ZigZag_Point < (CABLE_SYSTEM_TYPE_NUM - 1))    //total number of cable system are three
            MapChanToFreq(u8Cur_RF_Ch, &CurVirtual_Ch->stTPSetting, u8ZigZag_Point);
    }
    else
    {
        MapChanToFreq(u8Cur_RF_Ch, &CurVirtual_Ch->stTPSetting, ZigZag_Center_Point);
        CurVirtual_Ch->stTPSetting.u16Frequency+=msAPI_ScanGetFreqByZigZagPoint((EN_DEMOD_ATSC_MODE)CurVirtual_Ch->stTPSetting.fModulation,u8ZigZag_Point,u8Cur_RF_Ch);
    }
    *pu16ZigZagFreq = CurVirtual_Ch->stTPSetting.u16Frequency;
    CurVirtual_Ch->stTPSetting.u16Frequency = u16ORG_FREQ;
#endif
    NEW_SCAN_ATSC_DBG(printf("MApp_Get_ZigZag_Freq= %ld\n", (U32) ((*pu16ZigZagFreq)*FREQ_STEP)););
}

U8 MApp_Check_FE_Status(MS_VIRTUAL_CHANNEL *pVIRTUAL_CHANNEL)
{
    static U8 u8ZigZagPosition = ZigZag_Center_Point;
    U16 u16SetFrequency,u16Init_Freq;
    S16 s16FinalFreqOffset;
    U8 CurRFCh;

#if TS_FROM_PLAYCARD
    return FE_LOCK;
#endif

#if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
    MS_RF_CHANNEL_new pRf_Ch;
    MApp_ChanProc_GetRfChannelPointer(pVIRTUAL_CHANNEL, &pRf_Ch);
    if ((pRf_Ch.stTPSetting.fModulation) == DEMOD_ATSC_MODE_NTSC)
#else
    //u8ZigZagPosition = ZigZag_Center_Point;
    if ((pVIRTUAL_CHANNEL->stTPSetting.fModulation) == DEMOD_ATSC_MODE_NTSC)
#endif
    {
        if ( msAPI_AVD_IsSyncLocked())   //Check VD Lock first
        {
           //Tracking
#if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
            if(TRUE==msAPI_NTSC_Check_Lock(&pRf_Ch.stTPSetting))
#else
            if(TRUE==msAPI_NTSC_Check_Lock(&pVIRTUAL_CHANNEL->stTPSetting))
#endif
            {
                MApp_Get_ZigZag_Freq(&u16Init_Freq, ZigZag_Center_Point, pVIRTUAL_CHANNEL);
#if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
                s16FinalFreqOffset = pRf_Ch.stTPSetting.u16Frequency - u16Init_Freq;
#else
                s16FinalFreqOffset = pVIRTUAL_CHANNEL->stTPSetting.u16Frequency - u16Init_Freq;
#endif
                CurRFCh = PHY_CH_IDX(MApp_ChanProc_GetCurMainListProgIndex());
                if(msAPI_InNTSC_FreqOffset_Range(s16FinalFreqOffset,CurRFCh))
                {
                    u8ZigZagPosition = ZigZag_Center_Point;
                    return FE_LOCK;
                }
            }
            MApp_Get_ZigZag_Freq(&u16SetFrequency, u8ZigZagPosition, pVIRTUAL_CHANNEL);
            msAPI_Tuner_SetFreq(u16SetFrequency, DEMOD_ATSC_MODE_NTSC);
#if(PATCH_FOR_V_RANGE)
            MApp_VD_RangeReset();
#endif
#if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
            pRf_Ch.stTPSetting.u16Frequency=u16SetFrequency;
            //MApp_ChanProc_SetRfChannelPointer(pVIRTUAL_CHANNEL, &pRf_Ch);
            MApp_DB_ATSC_SaveRfChannel(pVIRTUAL_CHANNEL->u8RfNum, &pRf_Ch);
#else
            pVIRTUAL_CHANNEL->stTPSetting.u16Frequency=u16SetFrequency;
#endif

            NEW_SCAN_ATSC_DBG(printf("Fail, VD_HSYNC_LOCK, But frequency out of spec.\r\n"););
        }
        else
        {
            MApp_Get_ZigZag_Freq(&u16SetFrequency, u8ZigZagPosition, pVIRTUAL_CHANNEL);
            msAPI_Tuner_SetFreq(u16SetFrequency, DEMOD_ATSC_MODE_NTSC);
#if(PATCH_FOR_V_RANGE)
            MApp_VD_RangeReset();
#endif
        #if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
            pRf_Ch.stTPSetting.u16Frequency=u16SetFrequency;
            //MApp_ChanProc_SetRfChannelPointer(pVIRTUAL_CHANNEL, &pRf_Ch);
            MApp_DB_ATSC_SaveRfChannel(pVIRTUAL_CHANNEL->u8RfNum, &pRf_Ch);
        #else
            pVIRTUAL_CHANNEL->stTPSetting.u16Frequency=u16SetFrequency;
        #endif
        }
    }
    else
    {
    #if (FRONTEND_DEMOD_ATSC_TYPE == LG_3303_DEMODE)
#if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
        if (msAPI_Demodulator_Get_Lock_ATSC((EN_DEMOD_ATSC_MODE)pRf_Ch.stTPSetting.fModulation) == TRUE)
#else
        if (msAPI_Demodulator_Get_Lock_ATSC((EN_DEMOD_ATSC_MODE)pVIRTUAL_CHANNEL->stTPSetting.fModulation) == TRUE)
#endif
        {
            u8ZigZagPosition = ZigZag_Center_Point;
            return FE_LOCK;
        }
        #if (ENABLE_DTV_ZIGZAG)
        else
        {
            msAPI_Demodulator_Reset_ATSC();
            MApp_Get_ZigZag_Freq(&u16SetFrequency, u8ZigZagPosition, pVIRTUAL_CHANNEL);
#if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
            msAPI_Tuner_SetFreq(u16SetFrequency, (EN_DEMOD_ATSC_MODE)pRf_Ch.stTPSetting.fModulation);
            msAPI_Demodulator_Init((EN_DEMOD_ATSC_MODE)pRf_Ch.stTPSetting.fModulation, (EN_DEMOD_ATSC_SPECTRUM_MODE)pRf_Ch.stTPSetting.fSpectrum);

#else
            msAPI_Tuner_SetFreq(u16SetFrequency, (EN_DEMOD_ATSC_MODE)pVIRTUAL_CHANNEL->stTPSetting.fModulation);
            msAPI_Demodulator_Init((EN_DEMOD_ATSC_MODE)pVIRTUAL_CHANNEL->stTPSetting.fModulation, (EN_DEMOD_ATSC_SPECTRUM_MODE)pVIRTUAL_CHANNEL->stTPSetting.fSpectrum);
#endif

        }
        #endif
    #elif (FRONTEND_DEMOD_ATSC_TYPE==SAMSUNG_S5H1409_DEMODE || FRONTEND_DEMOD_ATSC_TYPE==SAMSUNG_S5H1410_DEMODE || FRONTEND_DEMOD_ATSC_TYPE==MSTAR_MSB1501_DEMODE || FRONTEND_DEMOD_ATSC_TYPE == EMBEDDED_ATSC_DEMOD)
#if (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
        if (msAPI_Demodulator_Get_Lock_ATSC((EN_DEMOD_ATSC_MODE)pRf_Ch.stTPSetting.fModulation) == TRUE)
#else
        if (msAPI_Demodulator_Get_Lock_ATSC((EN_DEMOD_ATSC_MODE)pVIRTUAL_CHANNEL->stTPSetting.fModulation) == TRUE)
#endif
        {
            u8ZigZagPosition = ZigZag_Center_Point;
            return FE_LOCK;
        }
    #endif
    }

    u8ZigZagPosition++;
    if (u8ZigZagPosition > ZigZag_Right_Point)
    {
        u8ZigZagPosition = ZigZag_Center_Point;
    }

    return FE_NOT_LOCK;
}

U8 MApp_Scan_ATSC_GetCurRfCh(void)
{
    return u8RFCh;
}

U16 MApp_Scan_ATSC_GetSrvAdded(void)
{
    return u16NumOfSrvAdd;
}

EN_SCAN_CHANNEL_TYPE MApp_Scan_ATSC_GetScanChannelType(void)
{
    return enScanChannelType;
}
U16 MApp_Scan_ATSC_GetScanCHFound(void)
{
#if (ASSIGN_NTSC_PROGRAM_AS_DEFAULT_CH == ENABLE)
    return (u16NumOfSrvAdd-u16NumOfNoSignalNTSCSrvAdd);
#else
    return u16NumOfSrvAdd;
#endif
}
U16 MApp_Scan_ATSC_GetScanAnalogCHFound(void)
{
    return u16NumOfNTSCSrvAdd;
}
U16 MApp_Scan_ATSC_GetScanDigitalCHFound(void)
{
#if (ASSIGN_NTSC_PROGRAM_AS_DEFAULT_CH == ENABLE)
    return (u16NumOfSrvAdd-u16NumOfNoSignalNTSCSrvAdd-u16NumOfNTSCSrvAdd);
#else
    return (u16NumOfSrvAdd-u16NumOfNTSCSrvAdd);
#endif
}

EN_TUNE2RF_SUB_STATE MApp_Scan_ATSC_GetScanSubState(void)
{
    return enAtscTune2RfSubState;
}

U16 MApp_Scan_ATSC_GetScanPercentageValue(void)
{
    U16 u16temp_data;
#if (SEARCH_CABLE_ATV_DTV_TOGETHER == DISABLE)
    if( enScanChannelType == SCAN_ALL_CHANNEL )
    {
        u16temp_data = u8RFCh;

        if( enAtscTune2RfSubState == NTSC_SCAN_STATE )
            u16temp_data = ((u16temp_data+u8MaxRFCh) * 100)/(u8MaxRFCh*2);
        else
            u16temp_data = (u16temp_data * 100)/(u8MaxRFCh*2);
    }
    else
#endif
    {
        u16temp_data = u8RFCh;
        u16temp_data = (u16temp_data * 100)/u8MaxRFCh;

        if (u16temp_data>100)
            u16temp_data = 100;
    }
    return u16temp_data;
}

BOOLEAN MApp_Scan_ATSC_SetAutoScan(void)
{
    stGenSetting.stScanMenuSetting.u8ScanType=AUTO_SCAN;
    enScanChannelType = SCAN_ALL_CHANNEL;
    return TRUE;
}


/*****************************************************************************/
#undef MAPP_SCAN_ATSC_C

