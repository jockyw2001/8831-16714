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
// (MStar Confidential Information) by the recipient.
// Any unauthorized act including without limitation unauthorized disclosure,
// copying, use, reproduction, sale, distribution, modification, disassembling,
// reverse engineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
////////////////////////////////////////////////////////////////////////////////

#define MAPP_CHANNEL_CHANGEGE_C
////////////////////////////////////////////////////////////////////////////////
/// @file MApp_ChannelChange.c
/// @author MStar Semiconductor Inc.
/// @brief Channel Change control for APP layer
////////////////////////////////////////////////////////////////////////////////

//******************************************************************************
//                    Header Files
//*****************************************************************************
#include <string.h>
#include <stdio.h>

#include "Board.h"

#include "datatype.h"
#include "debug.h"

#include "msAPI_Timer.h"
#include "msAPI_audio.h"
#include "msAPI_Video.h"
#include "msAPI_VD.h"
#include "msAPI_MIU.h"
#include "mapi_cc_monitor.h"
#include "msAPI_Tuner.h"
#if ENABLE_ATSC
#include "msAPI_Tuner_ATSC.h"
#endif
#include "apiXC.h"
#include "apiXC_Adc.h"
#include "apiXC_Sys.h"
#include "MApp_SaveData.h"
#include "MApp_Exit.h"
#include "MApp_GlobalSettingSt.h"
#include "MApp_GlobalVar.h"
#include "MApp_GlobalVar_ATSC.h"
#include "MApp_GlobalFunction.h"
#include "MApp_Audio.h"
#include "MApp_InputSource.h"
#include "MApp_MVDMode.h"
#include "MApp_ChannelProc_ATSC.h"
#include "MApp_DataBase_ATSC.h"
#include "MApp_ChannelChange.h"
#include "MApp_SignalMonitor.h"
#include "MApp_Psip.h"
#include "mapp_closedcaption.h"
#include "MApp_VChip.h"

#if 0
#include "MApp_Key.h"
#include "MApp_Scan_ATSC.h"
#include "MApp_ChannelChange_ATSC.h"
#include "MApp_PCMode.h"
//#include "MApp_UiMenu.h"
#include "MApp_Scaler.h"
#include "MApp_XC_PQ.h"
#include "MApp_TV.h"
#include "drvAUDIO.h"
//#include "MApp_Picture_Setting.h"
#include "MApp_VDMode.h"
#if (FRONTEND_IF_DEMODE_TYPE  == MSTAR_INTERN_VIF)
#include "IF_Demodulator.h"
#include "msAPI_Scan_ATSC.h"
#endif

#if (ENABLE_AUDIO_ONLY_CUSTOMERMODE == 1)
#include "MApp_UiMenuFunc.h"
#endif

#if MCU_AEON_ENABLE
#include "drvCPU.h"
#endif

#include "MApp_ZUI_Main.h"
#include "ZUI_tables_h.inl"
#include "MApp_ZUI_ACTchannelinfo.h"
#include "ZUI_exefunc.h"
#endif

#if ENABLE_DLC
#include "apiXC_Dlc.h"
#endif

extern U32 g_u32StreamTime;
extern THR_TBL_TYPE code AuSifInitThreshold[];
extern MS_U8 bPreviousSoundMode, bCurrentSoundMode;

//==============================================================================
/*                     Macro                    */
//==============================================================================
#ifndef ENABLE_ATV_CHANNEL_CHANGE_FINETUNING
#define ENABLE_ATV_CHANNEL_CHANGE_FINETUNING    ENABLE
#endif

#define CHANNELCHANGE_DBINFO(y) //y
#define ENABLE_CH_CHANGE_TIMER_DEBUG    0

/*********************************************************************************/
//                     Local
/*********************************************************************************/
U8 fEnableCCWhenMuteFunc;

static U8 u8CurrentPsyNumber;
static U8 u8PrevPsyNumber;

#if 0
static EN_CHANNELCHANGE_STATE enChannelChangeState = STATE_CHANNELCHANGE_INIT;
static EN_RET enChannelChangeRetVal;
static U32 u32ChannelChangeTimer;


#if (ENABLE_CH_CHANGE_TIMER_DEBUG == 1)
U32 g_u32ChannelChangeTimer1, g_u32ChannelChangeTimer2,g_u32ChannelChangeTimer3, g_u32ChannelChangeTimer4,
    g_u32ChannelChangeTimer5;
void Debug_ChannelChangeTimer(void)
{
    g_u32ChannelChangeTimer5 = msAPI_Timer_GetTime0();

    pstVirtualCh = MApp_ChanProc_GetCurChannelPointer();

    printf("\nCH change to %u-%u\n", pstVirtualCh->stVirtualChNum.major_num, pstVirtualCh->stVirtualChNum.minor_num);
    printf("disable ch S~E = %lu\n", (g_u32ChannelChangeTimer2 - g_u32ChannelChangeTimer1));
    printf("disable ch E ~ enable ch S = %lu\n", (g_u32ChannelChangeTimer3 - g_u32ChannelChangeTimer2));
    printf("enable ch S~E = %lu\n", (g_u32ChannelChangeTimer4 - g_u32ChannelChangeTimer3));
    printf("enable ch E ~ enable scaler = %lu\n", (g_u32ChannelChangeTimer5 - g_u32ChannelChangeTimer4));
    printf("total time =  %lu\n", (g_u32ChannelChangeTimer5 - g_u32ChannelChangeTimer1));
}
#endif
/*********************************************************************************/
/*                  Functions                        */
/*********************************************************************************/
static void Mapp_ChannelChange_ProcessUserInput ( void )
{
    switch ( u8KeyCode )
    {
        case KEY_CHANNEL_PLUS:
            MApp_ChannelChange_DisableChannel();

            if (enChannelChangeState == STATE_CHANNELCHANGE_DISPLAY)
            {
                MApp_ChanProc_IncProgIndex(MAIN_LIST, 1, TRUE);
                MApp_ChanProc_RefreshChannelBuffer(MAIN_LIST);
                enChannelChangeState = STATE_CHANNELCHANGE_SHOWINFO;
            }
            else
            {

                MApp_ChanProc_IncProgIndex(MAIN_LIST, 1, TRUE);
                MApp_ChanProc_RefreshChannelBuffer(MAIN_LIST);

                if ( enChannelChangeState != STATE_CHANNELCHANGE_INIT )
                    enChannelChangeState = STATE_CHANNELCHANGE_SHOWINFO;
            }

#if ENABLE_ATV_CHANNEL_CHANGE_FINETUNING
            MApp_ChannelChange_EnableChannel();
#endif

            u8KeyCode = KEY_NULL;
            break;

        case KEY_CHANNEL_MINUS:
            MApp_ChannelChange_DisableChannel();

            if (enChannelChangeState == STATE_CHANNELCHANGE_DISPLAY)
            {
                MApp_ChanProc_DecProgIndex(MAIN_LIST, 1, TRUE);
                MApp_ChanProc_RefreshChannelBuffer(MAIN_LIST);
                enChannelChangeState = STATE_CHANNELCHANGE_SHOWINFO;
            }
            else
            {

                MApp_ChanProc_DecProgIndex(MAIN_LIST, 1, TRUE);
                MApp_ChanProc_RefreshChannelBuffer(MAIN_LIST);

                if ( enChannelChangeState != STATE_CHANNELCHANGE_INIT )
                    enChannelChangeState = STATE_CHANNELCHANGE_SHOWINFO;
            }

#if ENABLE_ATV_CHANNEL_CHANGE_FINETUNING
            MApp_ChannelChange_EnableChannel();
#endif

            u8KeyCode = KEY_NULL;
            break;

        case KEY_CHANNEL_RETURN:

            MApp_ChannelChange_DisableChannel();
            MApp_ChanProc_ChRtnProgIndex();
            MApp_ChanProc_RefreshChannelBuffer(MAIN_LIST);

            if ( enChannelChangeState != STATE_CHANNELCHANGE_INIT )
                enChannelChangeState = STATE_CHANNELCHANGE_SHOWINFO;

#if ENABLE_ATV_CHANNEL_CHANGE_FINETUNING
            MApp_ChannelChange_EnableChannel();
#endif

            u8KeyCode = KEY_NULL;
            break;

        case KEY_NULL:
            break;

        default:
            break;
    }
}
#endif

/*********************************************************************************/
/*********************************************************************************/
void MApp_ChannelChange_DisableChannel_ATSC ( void ) ///*U8 u8ChanBufIdx*/ ) //for change channel
{
    //VDEC_Status vdecStatus;
    //memset(&vdecStatus, 0, sizeof(VDEC_Status));
    //MS_BOOL bRet = MApi_VDEC_GetStatus(&vdecStatus);
    CHANNELCHANGE_DBINFO( printf("%s()\n", __FUNCTION__); );

    if ( !fEnableSignalCheck )
    {
        return;
    }

    //printf("===> [%s] Line=%d\n",__FUNCTION__, __LINE__);

    #if (ENABLE_CH_CHANGE_TIMER_DEBUG == 1)
    g_u32ChannelChangeTimer1 = msAPI_Timer_GetTime0();
    #endif

    MApp_ChannelChange_DisableAV(MAIN_WINDOW);

#if (ENABLE_CHCHANGETIME)
    printf(">>>[DisableAV_Done]=[%d]\r\n",msAPI_Timer_DiffTimeFromNow(gU32ChChangeTime));
#endif

    if ( IsDTVInUse() )
    {
        /* Use for from DTV scramble to ATV protect */
        //msAPI_AUD_SetPaser(MSAPI_AUD_PASER_STOP);

        //pstVirtualCh = &astChannelBuf[u8ChanBufIdx].stSrvInfo;

        //if(pstVirtualCh->astSoundTrack[g_u8AudLangSelected].u16AudioPid /*< MSAPI_DMX_INVALID_PID*/)
        {
            /* stop audio decoder */
            MApi_AUDIO_SetCommand( (En_DVB_decCmdType)MSAPI_AUD_STOP );
          #if (ENABLE_ATSC_AD_FUNC)
            if(stGenSetting.g_SoundSetting.bEnableAD)
                MApi_AUDIO_SetCommand(MSAPI_AUD_DVB2_DECCMD_STOP);
          #endif

            /* stop audio filter */
            msAPI_DMX_Stop( u8AudFid );
        }

        //if(pstVirtualCh->u16VideoPid /*< MSAPI_DMX_INVALID_PID*/)
        {
            /* yym@2013-4-16 */
            /* When changing channel from AudioOnly to Normal, it will not stop MVDParser, so CC driver will not be init. */
            //if(bRet == TRUE && vdecStatus.bInit == TRUE)
            {
                CC_SourceFuns.StopMVDParser();
                // Stop CC parser
                CC_SourceFuns.Stop708Parsing();
            }

            /* stop video filter */
            msAPI_DMX_Stop( u8VidFid );

            /* stop video decoder */
            msAPI_VID_Command( MSAPI_VID_STOP );

            /*stop VOP*/
            MDrv_MVOP_Enable(FALSE);
        }

        //if(pstVirtualCh->u16PcrPid /*< MSAPI_DMX_INVALID_PID*/)
        {
            /* stop pcr filter */
            msAPI_DMX_Stop( u8PcrFid );
        }
        MApp_Dmx_DisableTableMonitor_ATSC();
    }
    else
    {
        /* stop audio decoder */
        MApi_AUDIO_SIF_SendCmd(MSAPI_AUD_SIF_CMD_SET_STOP, NULL, NULL);
    }

    fSignalLockStatus = FE_NOT_LOCK;
    fEnableSignalCheck = FALSE;

    #if (ENABLE_CH_CHANGE_TIMER_DEBUG == 1)
    g_u32ChannelChangeTimer2 = msAPI_Timer_GetTime0();
    #endif

#if (ENABLE_CHCHANGETIME)
    printf(">>>[Disable CH done]=[%d]\r\n",msAPI_Timer_DiffTimeFromNow(gU32ChChangeTime));
#endif

}
/*********************************************************************************/
void MApp_ChannelChange_EnableChannel_ATSC (void)
{
//    BIT fNotDisplayNineLatticeOnePagePrograms;
#if 0//(NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
    MS_RF_CHANNEL_new RfCh;
#endif
    DMX_FILTER_STATUS eDMX_FILTER_STATUS = DMX_FILTER_STATUS_OK;

    CHANNELCHANGE_DBINFO( printf("%s()\n", __FUNCTION__); );


    #if (ENABLE_CH_CHANGE_TIMER_DEBUG == 1)
    g_u32ChannelChangeTimer3 = msAPI_Timer_GetTime0();
    #endif

    if ( ( fEnableSignalCheck )
    #ifndef CHANNEL_HIDE_AS_SKIP_ONLY
        || ( stChSetting.u16TotalHideSrvNum == stChSetting.u16MainListSrvNum )
    #endif
    )
    {
        return;
    }

#if (ENABLE_CHCHANGETIME)
     printf(">>>[Start_EnableCH]=[%d]\r\n",msAPI_Timer_DiffTimeFromNow(gU32ChChangeTime));
#endif

    /* Reset ACC Existing Scheme */
    msAPI_CC_Reset();

    u8CurrentPsyNumber = PHY_CH_IDX(MApp_ChanProc_GetCurProgIndex());
    //printf("===> [%s] Line=%d, Mod=%bx, RF = %d\n",__FUNCTION__, __LINE__, (U8)pstVirtualCh->stTPSetting.fModulation, u8CurrentPsyNumber);
    //printf("MApp_ChanProc_GetCurProgIndex()=%u, u8CurrentPsyNumber=%u\n", MApp_ChanProc_GetCurProgIndex(), u8CurrentPsyNumber );
    if(u8PrevPsyNumber != u8CurrentPsyNumber)
    {
        g_u32StreamTime = 0; // reset stream time info
        u8PrevPsyNumber = u8CurrentPsyNumber;
    }
    g_u8AudLangSelected = 0;

    //printf("MApp_ChanProc_GetCurMainListProgIndex()=%u\n", MApp_ChanProc_GetCurMainListProgIndex() );
    //printf("VIR_CH_IDX(MApp_ChanProc_GetCurMainListProgIndex())=%u\n", VIR_CH_IDX(MApp_ChanProc_GetCurMainListProgIndex()) );

    pstVirtualCh = MApp_ChanProc_GetChannelPointer(VIR_CH_IDX(MApp_ChanProc_GetCurMainListProgIndex()));

    //printf("pstVirtualCh.fModulation=%u\n", pstVirtualCh->stTPSetting.fModulation);

    MS_TP_SETTING_ATSC stTPSettingAtscTmp;
    MApp_ChanProc_Get_TPSetting(pstVirtualCh, &stTPSettingAtscTmp);

    MApp_VChip_Init();
    msAPI_CC_VchipRateReset();
    fVChipPassWordEntered = FALSE;

    MApp_SignalCheck_Init();
    fEnableSignalCheck = TRUE;

#if 1
    //printf("stTPSettingAtscTmp.fModulation=%u\n", stTPSettingAtscTmp.fModulation);
    if( stTPSettingAtscTmp.fModulation == DEMOD_ATSC_MODE_NTSC )
#elif (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
    MApp_ChanProc_GetRfChannelPointer(pstVirtualCh, &RfCh);
    if ( RfCh.stTPSetting.fModulation == DEMOD_ATSC_MODE_NTSC )
#else
    if ( pstVirtualCh->stTPSetting.fModulation == DEMOD_ATSC_MODE_NTSC)
#endif
    {
        printf("Cur Ch is ATV\n");
        if ( SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW) != INPUT_SOURCE_TV )
        {
            UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_ATV;
            MApp_InputSource_SwitchSource( UI_INPUT_SOURCE_ATV, MAIN_WINDOW );
        }
        else
        {
            //UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_ATV;
            //msAPI_AVD_Parameter_Initial();
        }

        /* tune to new TP, if TP change */
    #if 1
        msAPI_Tuner_Tune2RfCh_ATSC( &stTPSettingAtscTmp );
    #elif (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
        msAPI_Tuner_Tune2RfCh_ATSC( &RfCh.stTPSetting );
        MApp_DB_SaveRfChannel(pstVirtualCh->u8RfNum, &RfCh);
    #else
        msAPI_Tuner_Tune2RfCh_ATSC( &pstVirtualCh->stTPSetting );
    #endif

#if ENABLE_ATV_CHANNEL_CHANGE_FINETUNING
        msAPI_AVD_SetVideoStandard(msAPI_AVD_GetVideoStandard());
        msAPI_AVD_ForceVideoStandard(msAPI_AVD_GetVideoStandard());
        msAPI_AVD_SetChannelChange();
            //msAPI_AVD_WaitForVideoSyncLock();
#if (ENABLE_CHCHANGETIME)
            printf(">>>[Wait VD Sync lock done]=[%d]\r\n",msAPI_Timer_DiffTimeFromNow(gU32ChChangeTime));
#endif
#endif

        #if ((TV_SYSTEM == TV_NTSC) && (AUDIO_SYSTEM_SEL == AUDIO_SYSTEM_A2))
        MApi_AUDIO_SIF_SendCmd(MSAPI_AUD_SIF_STANDARD_RESET, NULL, NULL);
        MApi_AUDIO_SIF_SetStandard( E_AUDIOSTANDARD_M_A2);
        MApi_AUDIO_SIF_SetPALType(AU_SIF_PAL_A2);
        #else
        MApi_AUDIO_SIF_SetStandard( E_AUDIOSTANDARD_M_BTSC );
        #endif
    // Set BTSC Threshold
//#if  (AUDIO_SYSTEM_SEL == AUDIO_SYSTEM_BTSC)
        MApi_AUDIO_SIF_SetThreshold(AuSifInitThreshold);
//#endif
        /* start audio decoder */
        MApi_AUDIO_SIF_SendCmd(MSAPI_AUD_SIF_CMD_SET_PLAY, NULL, NULL);

        //MApi_AUDIO_SPDIF_SetMode(MSAPI_AUD_SPDIF_PCM);
        #if ( MTS_MONITOR_BY_HOUSEKEEPING)
        MApp_Aud_EnablePollingStereo();

        // check MTS before umute...
        bCurrentSoundMode = MApi_AUDIO_SIF_GetSoundMode();
        if ( MApp_AUDIO_IsSifSoundModeExist( stGenSetting.g_SoundSetting.Mts ) )
        {
                g_u8AudLangSelected = stGenSetting.g_SoundSetting.Mts;
                MApi_AUDIO_SIF_SetSoundMode(MApp_SoundMtsSifSoundModeTrans(g_u8AudLangSelected));
                bPreviousSoundMode = bCurrentSoundMode;
        }
        else if( MApp_AUDIO_IsSifSoundModeExist( SOUND_MTS_STEREO ) )
        {
                g_u8AudLangSelected = SOUND_MTS_STEREO;
                MApi_AUDIO_SIF_SetSoundMode(MApp_SoundMtsSifSoundModeTrans(g_u8AudLangSelected));
                bPreviousSoundMode = bCurrentSoundMode;
        }
        #else
         // check MTS before umute...
        bCurrentSoundMode = MApi_AUDIO_SIF_GetSoundMode();

        if ( MApp_AUDIO_IsSifSoundModeExist( stGenSetting.g_SoundSetting.Mts ) )
        {
        g_u8AudLangSelected = stGenSetting.g_SoundSetting.Mts;
        }
        else if( MApp_AUDIO_IsSifSoundModeExist( SOUND_MTS_STEREO ) )
        {
                g_u8AudLangSelected = SOUND_MTS_STEREO;
        }
        else
        {
               //  g_u8AudLangSelected=SOUND_MTS_MONO;
                  g_u8AudLangSelected = stGenSetting.g_SoundSetting.Mts;
        }
        //printf(">>>>>>>enable channel bCurrentSoundMode=%d>>>>>>>\n",bCurrentSoundMode);
        //printf(">>>>>>>enable channel MTS=%d>>>>>>>\n",g_u8AudLangSelected);
       // printf(">>>>>>>enable channel SetSoundMode=%d>>>>>>>\n",MApp_SoundMtsSifSoundModeTrans( g_u8AudLangSelected));
        MApi_AUDIO_SIF_SetSoundMode(MApp_SoundMtsSifSoundModeTrans(g_u8AudLangSelected));
        bPreviousSoundMode = bCurrentSoundMode;
        stGenSetting.g_SoundSetting.Mts=(EN_SOUND_MTS_TYPE)g_u8AudLangSelected;
        #endif
        MApp_ChannelChange_EnableAV();
#if (ENABLE_CHCHANGETIME)
        printf(">>>[EnableAV_Done]=[%d]\r\n",msAPI_Timer_DiffTimeFromNow(gU32ChChangeTime));
#endif

    }
    else
    {
        printf("Cur Ch is DTV\n");

        #if ENABLE_DMXMONITOR
        if (fReInitDemux == TRUE)
        {
            printf("MApi_DMX_Init() !! \n");
            MApp_Dmx_CloseAllFilters_ATSC();
            MApi_DMX_Init();
            fReInitDemux = FALSE;
        }
        #endif

        /* enable table monitor should be before than TP change */
        MApp_Dmx_EnableTableMonitor_ATSC();

        if ( SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW) != INPUT_SOURCE_DTV )
        {
            UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_ATSC;
            MApp_InputSource_SwitchSource( UI_INPUT_SOURCE_TYPE, MAIN_WINDOW );
        }

        /* tune to new TP, if TP change */
    #if 1
        msAPI_Tuner_Tune2RfCh_ATSC( &stTPSettingAtscTmp );
    #elif (NEW_VIRTUAL_CHANNEL_STRUCTURE == ENABLE)
        msAPI_Tuner_Tune2RfCh_ATSC( &RfCh.stTPSetting );
        MApp_DB_SaveRfChannel(pstVirtualCh->u8RfNum, &RfCh);
    #else
        msAPI_Tuner_Tune2RfCh_ATSC(&pstVirtualCh->stTPSetting);
    #endif

/* remove later, old pattern patch
        if( pstVirtualCh->u16VCTStatus )
        {
            if( pstVirtualCh->stTPSetting.fModulation  == DEMOD_MODE_8VSB )
            {
                if (msAPI_Demodulator_Get_Lock(DEMOD_MODE_8VSB)== FALSE)
                    return;
            }
            else
            {
                if (msAPI_Demodulator_Get_Lock(DEMOD_MODE_256QAM)== FALSE)
                    return;
            }

            MApp_ReScan_Init();
            MApp_Dmx_GetScanTables();
            MApp_Scan_Check_IsSame_VirtualChannel();
        }
*/

        MApp_Dmx_PMT_ChChange();

        //printf("pstVirtualCh->u16PcrPid=%u\n", pstVirtualCh->u16PcrPid);
        if ( pstVirtualCh->u16PcrPid /*< MSAPI_DMX_INVALID_PID*/ )
        {
            //printf("u8PcrFid=%u\n", u8PcrFid);

            /* set pcr PID & start filter */
            eDMX_FILTER_STATUS = msAPI_DMX_StartFilter( pstVirtualCh->u16PcrPid, MSAPI_DMX_FILTER_TYPE_PCR, &u8PcrFid );
            //printf("eDMX_FILTER_STATUS=%u\n", eDMX_FILTER_STATUS);

            //printf("u8PcrFid=%u\n", u8PcrFid);
        }
        else if( pstVirtualCh_VCT->u16PcrPid )
        {
             msAPI_DMX_StartFilter( pstVirtualCh_VCT->u16PcrPid, MSAPI_DMX_FILTER_TYPE_PCR, &u8PcrFid );
        }

        //Remapping Audio language
        MApp_ReMapAudioLanguage();

        //if(stGenSetting.g_SoundSetting.enSoundDigitalSelect == SOUND_AUDIO_DIGITAL_DEFAULT)
        if(stGenSetting.g_SoundSetting.enVideoDescription == EN_VIDEO_DESCRIPTION_ITEM_OFF)
            u16AudioPID = MApp_SetPreferAudioSoundTrackPIDNew();
        else
            u16AudioPID = MApp_SetPreferAudioSoundTrackPID(0);

        if ( u16AudioPID /*< MSAPI_DMX_INVALID_PID*/ )
        {
            U16 enTempStreamType;

            //printf("u16AudioPID=%u\n", u16AudioPID);
            //printf("u8AudFid=%u\n", u8AudFid);
            /* set audio PID & start filter */
            eDMX_FILTER_STATUS = msAPI_DMX_StartFilter( u16AudioPID, MSAPI_DMX_FILTER_TYPE_AUDIO, &u8AudFid );
            //printf("eDMX_FILTER_STATUS=%u\n", eDMX_FILTER_STATUS);
            //printf("u8AudFid=%u\n", u8AudFid);

            enTempStreamType = MApp_GetAudioStreamType();
            /* set decoder system and reload firmware code */
           MApi_AUDIO_SetCommand( (En_DVB_decCmdType)MSAPI_AUD_STOP );

            if(enTempStreamType == AUD_STREAM_TYPE_MPEG)
            {
                MApi_AUDIO_SetSystem(MSAPI_AUD_DVB_MPEG);
            }
            else if(enTempStreamType == AUD_STREAM_TYPE_AAC)
                MApi_AUDIO_SetSystem(MSAPI_AUD_DVB_AAC);
            else
                MApi_AUDIO_SetSystem(MSAPI_AUD_DVB_AC3);

            //msAPI_Timer_Delayms(150); // to make sure it's ready.....

            if ( enTempStreamType == AUD_STREAM_TYPE_AC3 || enTempStreamType == AUD_STREAM_TYPE_AAC)
            {
               #if (ENABLE_UI_SPDIF_SETTING==ENABLE)
                if(stGenSetting.g_SysSetting.fSPDIFMODE == 0)
                {
                        MApi_AUDIO_SPDIF_SetMode(MSAPI_AUD_SPDIF_PCM);
                }
                else
                {
                        MApi_AUDIO_SPDIF_SetMode(MSAPI_AUD_SPDIF_NONPCM);
                }
               #else
                    MApi_AUDIO_SPDIF_SetMode(MSAPI_AUD_SPDIF_NONPCM);
               #endif
            }
            else
            {
                MApi_AUDIO_SPDIF_SetMode(MSAPI_AUD_SPDIF_PCM);
            }
        #if (ENABLE_ATSC_AD_FUNC)
            if ((MApp_ChanProc_GetCurChannelPointer()->u8AudLangNum > 1) && (stGenSetting.g_SoundSetting.bEnableAD))
            {
                U16 u16AudioPID2;
                if(g_u8AudLangSelected == 0)
                {
                    u16AudioPID2 = astgSoundTrack[1].u16AudioPid;
                }
                else
                {
                    u16AudioPID2 = astgSoundTrack[0].u16AudioPid;
                }
                msAPI_DMX_StartFilter(u16AudioPID2, MSAPI_DMX_FILTER_TYPE_AUDIO2, &u8AudFid2);

                if(enTempStreamType == AUD_STREAM_TYPE_MPEG)
                {
                    MApi_AUDIO_SetSystem(MSAPI_AUD_DVB2_MPEG);
                }
                else if(enTempStreamType == AUD_STREAM_TYPE_AAC)
                {
                    MApi_AUDIO_SetSystem(MSAPI_AUD_DVB2_AAC);
                }
                else
                {
                    MApi_AUDIO_SetSystem(MSAPI_AUD_DVB2_AC3);
                }
            }

            //MApi_AUDIO_SetCommand( (En_DVB_decCmdType)MSAPI_AUD_PLAY );
        #endif



            /* re-sync audio decoder */
            //MApi_AUDIO_SetCommand(MSAPI_AUD_RESYNC);

            /* Use for from DTV scramble to ATV protect */
            //msAPI_AUD_SetPaser(MSAPI_AUD_PASER_PLAY);

            /* start audio decoder */
            MApi_AUDIO_SetCommand( (En_DVB_decCmdType)MSAPI_AUD_PLAY );

          #if (ENABLE_ATSC_AD_FUNC)
            if((MApp_ChanProc_GetCurChannelPointer()->u8AudLangNum > 1) && (stGenSetting.g_SoundSetting.bEnableAD))
                MApi_AUDIO_SetCommand(MSAPI_AUD_DVB2_DECCMD_PLAY);
          #endif


          #if (ENABLE_AUDIOBYPASS)
            if (astgSoundTrack[g_u8AudLangSelected].u8AudAc3Bsmod == 0x02)// u16AudioPID /*< MSAPI_DMX_INVALID_PID*/ )
            {
                //Remapping Audio language
                //MApp_ReMapAudioLanguage();

                u16AudioPID = MApp_SetPreferAudioSoundTrackPID(1);
                /* stop audio decoder */
                MApi_AUDIO_SetCommand( (En_DVB_decCmdType)MSAPI_AUD_STOP );
                /* stop audio filter */
                msAPI_DMX_Stop( u8AudFid );

                /* set audio PID & start filter */
                msAPI_DMX_StartFilter( u16AudioPID, MSAPI_DMX_FILTER_TYPE_AUDIO, &u8AudFid );
                /* set decoder system and reload firmware code */
                MApi_AUDIO_SetCommand( (En_DVB_decCmdType)MSAPI_AUD_STOP );
                /* start audio decoder */
                MApi_AUDIO_SetCommand( (En_DVB_decCmdType)MSAPI_AUD_PLAY );
            }
          #endif
        }

    #if ENABLE_SOUNDTRACK_CHECKER_NEW
        start_decode_audio_time = 0;
        unchecked_audio_track_num = MApp_ChanProc_GetCurChannelPointer()->u8AudLangNum;
        unchecked_audio_track_num *= 3;
        //u8AudioCheckLoop =  0;
        u8AudioType =  0;
        bFlagTrackChecker = 0;

    #else

        start_decode_audio_time = msAPI_Timer_GetTime0();
        unchecked_audio_track_num = ++(MApp_ChanProc_GetCurChannelPointer()->u8AudLangNum);
        unchecked_audio_track_num <<= 1;
        u8AudioType =  0;
    #endif

        if ( pstVirtualCh->u16VideoPid /*< MSAPI_DMX_INVALID_PID*/ )
        {
            /* set video PID & start filter */
            msAPI_DMX_StartFilter( pstVirtualCh->u16VideoPid, MSAPI_DMX_FILTER_TYPE_VIDEO, &u8VidFid );

          #if (ENABLE_H265) // need check
            if (pstVirtualCh->stVirtualChNum.u8VideoStreamType == VIDEO_STREAM_TYPE_H265)
            {
                msAPI_VID_SetMappingAVCParameter(E_VDEC_CODEC_TYPE_HEVC);
            }
          #endif

        #if (MEMORY_MAP > MMAP_32MB)
            if (pstVirtualCh->stVirtualChNum.u8VideoStreamType == VIDEO_STREAM_TYPE_H264)
            {
                msAPI_VID_SetMappingAVCParameter(E_VDEC_CODEC_TYPE_H264);
            }
        #endif

        #if((MEMORY_MAP == MMAP_32MB) && (ENABLE_32M_H264 == ENABLE))
            if (pstVirtualCh->stVirtualChNum.u8VideoStreamType == VIDEO_STREAM_TYPE_H264)
            {
                msAPI_VID_SetMappingAVCParameter(E_VDEC_CODEC_TYPE_H264);
            }
        #endif

            if ((pstVirtualCh->stVirtualChNum.u8VideoStreamType == VIDEO_STREAM_TYPE_MPEG1)||(pstVirtualCh->stVirtualChNum.u8VideoStreamType == VIDEO_STREAM_TYPE_MPEG2)||(pstVirtualCh->stVirtualChNum.u8VideoStreamType == VIDEO_STREAM_TYPE_OPTION_MPEG2))
                msAPI_VID_SetMappingAVCParameter(E_VDEC_CODEC_TYPE_MPEG2);

            VDEC_Status vdecStatus;
            memset(&vdecStatus, 0, sizeof(VDEC_Status));
            MApi_VDEC_GetStatus(&vdecStatus);
            if(vdecStatus.bInit)
                msAPI_VID_Command( MSAPI_VID_STOP );

            //msAPI_VID_SetVdecFrameMode(TRUE);
            msAPI_VID_Init(FALSE, E_VDEC_SRC_MODE_DTV);
        #if (ENABLE_VDEC_AVSYNC_REPEAT)
            MApi_VDEC_SetControl(VDEC_USER_CMD_AVSYNC_REPEAT_TH, 0xFF);  //restore setting
        #endif

            /* start video decoder */
            msAPI_VID_Command( MSAPI_VID_PLAY );
            MDrv_MVOP_Enable ( TRUE );
            if ( !u16AudioPID )
            {
                //msAPI_VID_MVDCommand( MSAPI_VID_FREERUN );
                msAPI_VID_Command( MSAPI_VID_FREERUN );
            }
        }


    #if (STORE_RD_CH_ENABLE == 1)
        pstVirtualCh=MApp_ChanProc_GetChannelPointer(VIR_CH_IDX(MApp_ChanProc_GetCurMainListProgIndex()));
        if(pstVirtualCh->u16VideoPid!=0)
        {
            fEnableMvdTimingMonitor=TRUE;
            if(pstVirtualCh->astSoundTrack[0].u16AudioPid != 0)
            {
                MApi_AUDIO_SetCommand(MSAPI_AUD_DVB_DECCMD_AVSYNC);
            }
        }
        else
        {
            fEnableMvdTimingMonitor=FALSE;
            if(pstVirtualCh->astSoundTrack[0].u16AudioPid != 0)
            {
                MApi_AUDIO_SetCommand(MSAPI_AUD_DVB_DECCMD_FREE_RUN);
            }
        }
    #endif //(STORE_RD_CH_ENABLE == 1)


        // for channel change, caption mode must change back to 708
        if ( stGenSetting.g_CaptionSetting.u8CCMode == CAPTIONMENU_MODE_ON )
        {
            if (stGenSetting.g_CaptionSetting.u8CaptionServiceModeDTV!=CAPTIONMENU_SERVICE_OFF)
               stGenSetting.g_CaptionSetting.u8CaptionServiceMode = stGenSetting.g_CaptionSetting.u8CaptionServiceModeDTV;
            else
               stGenSetting.g_CaptionSetting.u8CaptionServiceMode = stGenSetting.g_CaptionSetting.u8CaptionServiceModeATV;
         }
      #if (PARSING_CC_WHENMUTE)
        else if (stGenSetting.g_CaptionSetting.u8CCMode == CAPTIONMENU_MODE_CC_WHEN_MUTE)
        {
               fEnableCCWhenMuteFunc = FALSE;
               stGenSetting.g_CaptionSetting.u8CaptionServiceMode = CS_OFF;
               MApp_ClosedCaption_GetUserCmd();
               if (MApp_Aud_GetMuteStatus())
               {
                    fEnableCCWhenMuteFunc = TRUE;
                    fEnableClosedCaptionFunc = TRUE;
               }
       }
      #endif

        MApp_ClosedCaption_Set_ProgramChange();
        if (stGenSetting.g_CaptionSetting.u8CCMode != CAPTIONMENU_MODE_CC_WHEN_MUTE)
            MApp_ClosedCaption_GetUserCmd();

        //For display AV simultaneously.
        MApp_VID_VariableInit();

        // move unmute here to avoid POP noise
        if( pstVirtualCh->astSoundTrack[0].u16AudioPid != 0 )
        {
            MApp_Aud_SetPathUnMute();
            //MApi_AUDIO_SPDIF_SetMute(FALSE);
        }
    }

    /* init VChip */
    //if( fNotDisplayNineLatticeOnePagePrograms )
    {
        MApp_VChip_Init();
        MApp_CC_Initialize();
        fVChipPassWordEntered = FALSE;
    }


#if CUSTOMER_FOR_UI_CC_708_608_APPEARING
    /* Reset ACC Existing Scheme */
    msAPI_CC_CCInfoInit();
    // Stop CC parser
    MApp_ClosedCaption_Parser_Stop();
    MApp_ClosedCaption_Parser_Init();
#endif


    bEpgEventSorted = FALSE;
    MApp_SignalMonitor_Init();
    fEnableSignalCheck = TRUE;
  #if (ENABLE_MAX_RRT_DIMENSION_NUMBER == 0)
    u8LastPatItemNo = 0;
  #endif

    MApp_ChanProc_SaveLastWatched();

  #if (ENABLE_CH_CHANGE_TIMER_DEBUG == 1)
    g_u32ChannelChangeTimer4 = msAPI_Timer_GetTime0();
  #endif

  #if (ENABLE_AUDIO_ONLY_FULL_FEATURE == 1)
    if( (IsDTVInUse())
        &&(pstVirtualCh->u16VideoPid==0)
        && (pstVirtualCh->astSoundTrack[0].u16AudioPid !=0))
    {
        DBG_AUDIOONLY(printf("\r\ng_bRadioChannel=TRUE");)
        g_bRadioChannel = TRUE;
        MApp_StartAudioOnlyMonitor();
    }
    else
    {
        DBG_AUDIOONLY(printf("\r\ng_bRadioChannel=FALSE");)
        g_bRadioChannel = FALSE;
        MApp_StopAudioOnlyMonitor();
    }
    //enAudioOnly  = AUDIO_ONLY_OFF;//for cus01x display,
  #elif (ENABLE_AUDIO_ONLY_CUSTOMERMODE == 1)
    //MApp_UiMenuFunc_SetAudioOnlyItem();
  #endif


    if( /*(IsDTVInUse())*/
        (IsAtscInUse())
        &&((pstVirtualCh->u16VideoPid==0) || (pstVirtualCh->u16ScrambleChStatus && SCRAMBLE_VIDEO))
        && (pstVirtualCh->astSoundTrack[0].u16AudioPid !=0))
    {
        if(!MApp_Aud_GetMuteStatus())
        {
            msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYSYNC_MUTEOFF, E_AUDIOMUTESOURCE_ATV);
            MApi_AUDIO_SPDIF_SetMute(FALSE);
        }
        msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_PERMANENT_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
    }

#if ENABLE_PVR
    g_u16Current_PCRPID = pstVirtualCh->u16PcrPid ;
    g_u16Current_PVR_VideoPID = pstVirtualCh->u16VideoPid;
    g_u16Current_PVR_AudioPID = pstVirtualCh->astSoundTrack[0].u16AudioPid;
    g_wCurrent_AudioType = pstVirtualCh->astSoundTrack[0].u16AudStreamType;
  //  g_eCurrent_PVR_VideoType = g_eCodecType;
    g_u16Current_AudioDescriptorPID = pstVirtualCh->astSoundTrack[0].u16AudioPid;;
#endif
}

/************************************************************************************/
/************************************************************************************/
#if 0
EN_RET MApp_ChannelChange ( void )
{
    enChannelChangeRetVal = EXIT_CHANNELCHANGE_NULL;

    Mapp_ChannelChange_ProcessUserInput();

  #if STATE_PRINT
    if ( u8KeyCode != 0xFF )
    {
        printf( "CC:%bx ", enChannelChangeState );
    }
  #endif

    switch ( enChannelChangeState )
    {
        case STATE_CHANNELCHANGE_INIT:
            CHANNELCHANGE_DBINFO( printf( "STATE_CHANNELCHANGE_INIT\n" ) );

            if ( MApp_ChanProc_GetNumOfServices( MAIN_LIST ) && !fTableVersionChanged)
            {
                MApp_ChanProc_RefreshChannelBuffer(MAIN_LIST);
                #ifdef AUTOSCAN_RETURN_MENU
                if(bAutoScan_Return_Menu == TRUE)
                {
                    enChannelChangeState = STATE_CHANNELCHANGE_DISPLAY;
                    u32ChannelChangeTimer = msAPI_Timer_GetTime0();
                }
                else
                #endif
                {
                    enChannelChangeState = STATE_CHANNELCHANGE_SHOWINFO;
                }
            }
            else if ( stChSetting.u16TotalHideSrvNum == stChSetting.u16MainListSrvNum ) // all CH been hideen
            {
                enChannelChangeRetVal = EXIT_CHANNELCHANGE_DONE;
            }
            else //no database
            {
                enChannelChangeRetVal = EXIT_CHANNELCHANGE_DONE;
            }

        //if display info exist in the screen then to change channel,the display info should be disappear first!
            if ((MApp_ZUI_ACT_IsChInfoMode(TYPE_CHANNEL_INFO)) || (MApp_ZUI_ACT_IsChInfoMode(TYPE_CHANNEL_ETT)))
            {
                MApp_ZUI_ACT_ShutdownOSD();
            }

            break;

        case STATE_CHANNELCHANGE_SHOWINFO:
            CHANNELCHANGE_DBINFO( printf( "STATE_CHANNELCHANGE_SHOWINFO\n" ) );

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
                MApp_ZUI_ACT_StartupOSD(E_OSD_CHANNEL_INFO);
            }
            enChannelChangeState = STATE_CHANNELCHANGE_DISPLAY;//STATE_CHANNELCHANGE_WAITKEY;
            u32ChannelChangeTimer = msAPI_Timer_GetTime0();
            break;

        case STATE_CHANNELCHANGE_DISPLAY:
          #if ENABLE_ATV_CHANNEL_CHANGE_FINETUNING
            if(!fEnableSignalCheck)
                MApp_SetChChangeState(TRUE);
          #endif
            if (msAPI_Timer_DiffTimeFromNow(u32ChannelChangeTimer ) > 50) //unit = ms
            {
                CHANNELCHANGE_DBINFO( printf( "STATE_CHANNELCHANGE_DISPLAY\n" ) );
                MApp_ChannelChange_EnableChannel();
                enChannelChangeRetVal = EXIT_CHANNELCHANGE_DONE;
                enChannelChangeState = STATE_CHANNELCHANGE_INIT;
                msAPI_AVD_CheckStdDetStableReset();
            }

            break;
    }

    return enChannelChangeRetVal;
}
#endif

/*********************************************************************************/

void MApp_ChannelChange_ChangeProgramList ( EN_ANT_TYPE enAntennaType )
{
    MApp_ChannelChange_DisableChannel(TRUE, MAIN_WINDOW);

    //store stChSetting to RamDisk
    MApp_DB_ATSC_SaveCurChSetting();

    MApp_DB_ATSC_InitBaseAddr( enAntennaType );

    //get stChSetting from 64K database
    MApp_DB_ATSC_LoadCurChSetting();

   if(stGenSetting.g_SysSetting.u16MainListLastWatched[ANT_TYPE] >stChSetting.u16MainListSrvNum ||stGenSetting.g_SysSetting.u16MainListLastWatched[ANT_TYPE] == 0)
      stGenSetting.g_SysSetting.u16MainListLastWatched[ANT_TYPE] = 1;

    MApp_ChanProc_ResetAllIndex(stGenSetting.g_SysSetting.u16MainListLastWatched[ANT_TYPE]);
    if(MApp_ChanProc_RefreshChannelBuffer(MAIN_LIST))
    {
        MApp_ChannelChange_EnableChannel_ATSC();
    }

}




//------------------------------------------------------------------------------

#undef  MAPP_CHANNEL_CHANGEGE_C

