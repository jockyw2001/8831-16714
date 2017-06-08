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

////////////////////////////////////////////////////////////////////////////////
//  [Doxygen]
/// @file msapi_audio.h
/// @brief API for Audio Control
/// @author MStar Semiconductor, Inc.
//
////////////////////////////////////////////////////////////////////////////////

#define _MSAPI_AUDIO_C_
#include <math.h>
#include "Board.h"
#include "debug.h"
#include "msAPI_audio.h"
#include "msAPI_Global.h"
#include "apiAUDIO.h"
#include "drvAUDIO.h"
#include "drvAUDIO_if.h"
#include "msAPI_MIU.h"
#include "BinInfo.h"
#include "msAPI_DrvInit.h"
#include "msAPI_Timer.h"
#include "drvISR.h"
#include "drvMIU.h"
#include "msAPI_Tuning.h"
#include "msAPI_VD.h"
#include "MApp_Audio.h"
#include "MsCommon.h"
#include "MsIRQ.h"
#include "MsOS.h"
#include "MApp_GlobalSettingSt.h"
#include "Utl.h"

#if( ENABLE_AUDIO_DEC_R2_BIN_COMPRESS )
#include "ms_decompress.h"
#endif

#if (ENABLE_SBTVD_BRAZIL_APP)
    #define  SIF_IS_PAL_SYSTEM      0
#elif (TV_SYSTEM == TV_PAL)
    #define  SIF_IS_PAL_SYSTEM      1
#elif (TV_SYSTEM == TV_NTSC)
    #if (AUDIO_SYSTEM_SEL == AUDIO_SYSTEM_BTSC)
        #define  SIF_IS_PAL_SYSTEM      0
    #elif (AUDIO_SYSTEM_SEL == AUDIO_SYSTEM_A2)
        #define  SIF_IS_PAL_SYSTEM      1
    #endif
#endif



#if (DIGITAL_I2S_SELECT != AUDIO_I2S_NONE)
#include "Audio_amplifier.h"
#endif
#define DEBUG_AUDIO    //0xFF

#if (ENABLE_DMP)
#include "GPIO.h"
#endif

#if SCART_ALWAYS_OUTPUT_ATV
#include "MApp_GlobalVar.h"
#endif

#ifdef DEBUG_AUDIO
    #define debugAudioPrint(a,b)    debugPrint(a,b)
#else
    #define debugAudioPrint(a,b)
#endif

#define  AUDIO_API_TRACE(msg)    //msg     //This is used for audio API function Trace

#define IsVideoStandard60Hz(s)        ( ( ((s)==E_VIDEOSTANDARD_NTSC_M) || \
                                        ((s)==E_VIDEOSTANDARD_NTSC_44) || \
                                        ((s)==E_VIDEOSTANDARD_PAL_M) || \
                                        ((s)==E_VIDEOSTANDARD_PAL_60) )? TRUE : FALSE )

#define IsVideoStandard50Hz(s)        ( ( ((s)==E_VIDEOSTANDARD_PAL_BGHI) || \
                                        ((s)==E_VIDEOSTANDARD_SECAM) || \
                                        ((s)==E_VIDEOSTANDARD_PAL_N) )? TRUE : FALSE )


#define AUD_DEBUG(msg) //msg

//-------------------------------------------------------------------------
// Extern
//-------------------------------------------------------------------------
extern MS_U8          gu8MADEncodeDone;
extern THR_TBL_TYPE code     AuSifInitThreshold[];
MS_U8                 g_A2ModeInvalidCnt=0;

#if (ENABLE_SBTVD_BRAZIL_APP)
BOOLEAN bForceCheckAudioMode=FALSE;
#endif
//-------------------------------------------------------------------------
// Local
//-------------------------------------------------------------------------
static BOOLEANS m_BOOLEANS_1;
#define m_bIsAudioModeChanged                   m_BOOLEANS_1.bBOOL_0
#define m_bPermanentAudioMute                   m_BOOLEANS_1.bBOOL_1
#define m_bMomentAudioMute                      m_BOOLEANS_1.bBOOL_2
#define m_bByUserAudioMute                      m_BOOLEANS_1.bBOOL_3
#define m_bBySyncAudioMute                      m_BOOLEANS_1.bBOOL_4
#define m_bByVChipAudioMute                     m_BOOLEANS_1.bBOOL_5
#define m_bByBlockAudioMute                     m_BOOLEANS_1.bBOOL_6
#define m_bInternal1AudioMute                   m_BOOLEANS_1.bBOOL_7

static BOOLEANS m_BOOLEANS_2;
#define m_bInternal2AudioMute                   m_BOOLEANS_2.bBOOL_0
#define m_bInternal3AudioMute                   m_BOOLEANS_2.bBOOL_1
#define m_bInternal4AudioMute                   m_BOOLEANS_2.bBOOL_2
#define m_bByDuringLimitedTimeAudioMute         m_BOOLEANS_2.bBOOL_3
//#define m_bIsRealtimeAudioDetectionEnabled    m_BOOLEANS_2.bBOOL_4
#define m_bIsSRSWOWEnabled                      m_BOOLEANS_2.bBOOL_5
#define m_bMHEGApMute                           m_BOOLEANS_2.bBOOL_6    // MHEG AP Mute - for MHEG use only
#define m_bCIAudioMute                          m_BOOLEANS_2.bBOOL_7

#if ENABLE_ATSC_TTS
static BOOLEANS m_BOOLEANS_3;
#define m_bTTSBackgroundAudioMute               m_BOOLEANS_3.bBOOL_0
#endif

static BOOL m_bMuteByHdmiAvMute = 0;
static BOOL m_bMuteByUiFunc = 0;


#define DTV_MPEG_DECOUNCE   10

MS_U8                       u8DebounceCnt = 0;
AUDIOSTATUS                 m_eAudioStatus;
AUDIOMODE_TYPE              m_eAudioMode;
MS_U16                      m_wAudioDownCountTimer;
MS_U16                      m_wAtvAudioCheckCount;
AUDIOSTANDARD_TYPE          m_eAudioStandard;
AUDIO_DSP_SYSTEM            m_eAudioDSPSystem;
AUDIOSOURCE_TYPE            m_eAudioSource;
En_DVB_soundModeType_       m_Audio_currSoundMode;

static MS_U8                m_cAudioVolumePercentage;
static MS_U32               m_dwStartedTimeOfMute;
static MS_U16               m_wLimitedTimeOfMute;
static MS_U32               m_previous_wLimitedTimeOfMute ;

#if (MTS_NICAM_UNSTABLE)
MS_U16                      g_NICAMEnable = 1;
MS_U8                       g_CarrierStableCnt = 0;
#endif

#if (ENABLE_CHANNEL_CHANGE_MUTE_ON_OFF_DELAY)
static MS_BOOL              m_bByPassDelay;
#endif


static void SetAudioMuteDuringLimitedTime(WORD w1ms, AUDIOMUTESOURCE_TYPE eAudioMuteSource);
static void SetAudioMute(AUDIOMUTETYPE eAudioMuteType, AUDIOMUTESOURCE_TYPE eAudioMuteSource);
#ifndef ATSC_SYSTEM

static void CheckAudioStandard(void);
#if (ENABLE_SBTVD_BRAZIL_APP==0)
static void CheckATVAudioMode(void);
#endif
#endif
#if ENABLE_EWS
extern BOOL bEwsAudioMuteControl;
#endif
void msAPI_AUD_MPEG_Monitor(void)   // this function is used for DTV mpeg layer monitor due to DTV SI layer can't recognize mpeg layer correctly
{
    if(false == MApi_AUDIO_GetCommAudioInfo(Audio_Comm_infoType_Is_Decoder_In_R2))
    {
        if((m_eAudioDSPSystem == E_AUDIO_DSP_MPEG))
        {
            Audio_MP3_LAYER eLayer = MApi_AUDIO_GetLayer();
            if((eLayer != Audio_MP3_LAYER_NOT_DETERMINE_YET)&&(eLayer != Audio_MP3_LAYER_RESERVED))
            {
                AUDIO_DSP_CODE_TYPE eDspType = MApi_AUDIO_ReadDspCodeType();

                if((eLayer == Audio_MP3_LAYER_3)&&(eDspType != AU_DVB_STANDARD_MP3))
                {
                    if(u8DebounceCnt < DTV_MPEG_DECOUNCE)
                    {
                        printf("mpeg layer mismtch, correct:  mp3, but current dsp code is mp2   (%d)=== \r\n", u8DebounceCnt);
                        u8DebounceCnt++;
                    }
                    else
                    {
                        u8DebounceCnt = 0;
                        printf("audio print:  audio codec setting incorrect, reload to mp3 in monitor === \r\n");
                        MApi_AUDIO_SetCommand(MSAPI_AUD_DVB_DECCMD_STOP);
                        MApi_AUDIO_SetSystem(MSAPI_AUD_DVB_MP3);
                        MApi_AUDIO_SetCommand(MSAPI_AUD_DVB_DECCMD_PLAY);
                    }
                }
                else if(((eLayer == Audio_MP3_LAYER_1)||(eLayer == Audio_MP3_LAYER_2))&&(eDspType != AU_DVB_STANDARD_MPEG))
                {
                    if(u8DebounceCnt < DTV_MPEG_DECOUNCE)
                    {
                        printf("mpeg layer mismtch, correct:  mpeg, but current dsp code is mp3 (%d)=== \r\n", u8DebounceCnt);
                        u8DebounceCnt++;
                    }
                    else
                    {
                        u8DebounceCnt = 0;
                        printf("audio codec setting incorrect, reload to mpeg in monitor === \r\n");
                        MApi_AUDIO_SetCommand(MSAPI_AUD_DVB_DECCMD_STOP);
                        MApi_AUDIO_SetSystem(MSAPI_AUD_DVB_MPEG);
                        MApi_AUDIO_SetCommand(MSAPI_AUD_DVB_DECCMD_PLAY);
                    }
                }
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
///
///         AUDIO_SYSTEM RELATIONAL API FUNCTION
///
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
/// Adjust audio by specific factor
/// @param eFactor  \b IN adjust factor
/// @param wParam1  \b param1
/// @param wParam2  \b param2
/******************************************************************************/
//Refine power on sequence for earphone & DAC pop noise issue
void msAPI_AUD_PreInitAudio(void)
{
#if ( (CHIP_FAMILY_TYPE == CHIP_FAMILY_EMERALD)     \
    ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MILAN)       \
    ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_NUGGET)      \
    ||(FIXED_POWER_ON_EARPHONE_POP == ENABLE) )

    AUDIO_API_TRACE(printf("\r\n@@@ ===msAPI_AUD_PreInitAudio===@@@"));
    MApi_AUDIO_WritePreInitTable();
    MApi_AUDIO_SetAC3PInfo(Audio_AC3P_DTV_AVSYNC_OFFSET, 0x2DB4, 0);

#endif

    return;
}

/******************************************************************************/
/// API for Audio::

/******************************************************************************/
/// API for Audio::
/// Initial Audio system. Involve this function during the initial time.
/******************************************************************************/
void msAPI_AUD_InitAudioSystem(THR_TBL_TYPE code *ThrTbl)
{
    AUDIO_INIT_INFO SystemInfo;
    AUDIO_OUT_INFO OutputInfo;
    AUDIO_PATH_INFO PathInfo;

    AUDIO_API_TRACE(printf("\r\n@@@ ===msAPI_AUD_InitAudioSystem===@@@"));

    SystemInfo.miu=0;
    UNUSED(ThrTbl);

//======================================
// Set system info
//======================================
    #if (TV_SYSTEM == TV_PAL)
        SystemInfo.tv_system=TV_PAL;
    #elif(TV_SYSTEM == TV_NTSC)
        SystemInfo.tv_system=TV_NTSC;
    #else
        SystemInfo.tv_system=TV_CHINA;
    #endif

    #ifdef ATSC_SYSTEM
        SystemInfo.dtv_system=1;  // For ATSC
    #else
        SystemInfo.dtv_system=0;  // For DVB
    #endif

    #if (AUDIO_SYSTEM_SEL == AUDIO_SYSTEM_BTSC)
        SystemInfo.au_system_sel=AUDIO_SYSTEM_BTSC;
    #elif(AUDIO_SYSTEM_SEL == AUDIO_SYSTEM_A2)
        SystemInfo.au_system_sel=AUDIO_SYSTEM_A2;
    #endif
    MApi_AUDIO_SetSystemInfo(&SystemInfo);

//======================================
// Set output info
//======================================

    OutputInfo.SpeakerOut=AUDIO_OUTPUT_MAIN_SPEAKER;
    OutputInfo.HpOut=AUDIO_OUTPUT_HP;
    OutputInfo.ScartOut=AUDIO_OUTPUT_SIFOUT;
    OutputInfo.MonitorOut=AUDIO_OUTPUT_LINEOUT;
    MApi_AUDIO_SetOutputInfo(&OutputInfo);

//======================================
// Set path info
//======================================
    PathInfo.SpeakerOut=AUDIO_PATH_MAIN_SPEAKER;
    PathInfo.HpOut=AUDIO_PATH_HP;
    PathInfo.ScartOut=AUDIO_PATH_SCART1;
    PathInfo.MonitorOut=AUDIO_PATH_LINEOUT;
    PathInfo.SpdifOut=AUDIO_PATH_SPDIF;
    MApi_AUDIO_SetPathInfo(&PathInfo);


//======================================
#if((FRONTEND_IF_DEMODE_TYPE==MSTAR_VIF)||(FRONTEND_IF_DEMODE_TYPE==MSTAR_VIF_MSB1210)||(FRONTEND_IF_DEMODE_TYPE==MSTAR_INTERN_VIF))
    MApi_AUDIO_SIF_SendCmd(MSAPI_AUD_SIF_CMD_SET_ADC_FROM_VIF_PATH, TRUE, 0);
#else
    MApi_AUDIO_SIF_SendCmd(MSAPI_AUD_SIF_CMD_SET_ADC_FROM_VIF_PATH, FALSE, 0);
#endif

#if (CHIP_FAMILY_TYPE == CHIP_FAMILY_NASA)
#if ENABLE_VD_PACH_IN_CHINA
    if(G_FACTORY_SETTING.stVDSetting.AUDIO_HIDEV==1)
    {
        MApi_AUDIO_SIF_SendCmd(MSAPI_AUD_SIF_CMD_ENABLE_HIDEV, TRUE, NULL);
        MApi_AUDIO_SIF_SendCmd(MSAPI_AUD_SIF_CMD_SET_HIDEV_FILTER_BW_LEVEL, MSAPI_AUD_SIF_HIDEV_FILTER_BW_L1, NULL);
    }
    else if(G_FACTORY_SETTING.stVDSetting.AUDIO_HIDEV==2)
    {
        MApi_AUDIO_SIF_SendCmd(MSAPI_AUD_SIF_CMD_ENABLE_HIDEV, TRUE, NULL);
        MApi_AUDIO_SIF_SendCmd(MSAPI_AUD_SIF_CMD_SET_HIDEV_FILTER_BW_LEVEL, MSAPI_AUD_SIF_HIDEV_FILTER_BW_L2, NULL);
    }
    else if(G_FACTORY_SETTING.stVDSetting.AUDIO_HIDEV==3)
    {
        MApi_AUDIO_SIF_SendCmd(MSAPI_AUD_SIF_CMD_ENABLE_HIDEV, TRUE, NULL);
        MApi_AUDIO_SIF_SendCmd(MSAPI_AUD_SIF_CMD_SET_HIDEV_FILTER_BW_LEVEL, MSAPI_AUD_SIF_HIDEV_FILTER_BW_L3, NULL);
    }
    else
#endif
    {
        MApi_AUDIO_SIF_SendCmd(MSAPI_AUD_SIF_CMD_ENABLE_HIDEV, FALSE, NULL);
    }
#endif

    MW_AUD_SetMadAddress();
    MApi_AUDIO_Initialize();

#if (TV_SYSTEM == TV_PAL)
    MApi_AUDIO_SIF_SendCmd(MSAPI_AUD_SIF_CMD_DETECT_MAIN_STD_ONLY, TRUE, 0);
#endif

#if (MTS_NICAM_UNSTABLE)
    g_CarrierStableCnt = 0;
    g_NICAMEnable = 1;
#endif
//    m_eAudioStreamType = astNOT_VALID;

    m_eAudioSource = E_AUDIOSOURCE_INVALID;
    m_eAudioStandard = E_AUDIOSTANDARD_NOTSTANDARD;
    m_eAudioStatus = E_STATE_AUDIO_NO_CARRIER;
    m_eAudioMode = E_AUDIOMODE_INVALID;
    m_eAudioDSPSystem = E_AUDIO_DSP_INVALID;
    m_bIsAudioModeChanged = FALSE;

    m_bMHEGApMute = FALSE;
    m_bPermanentAudioMute = FALSE;
    m_bMomentAudioMute = FALSE;
    m_bByUserAudioMute = FALSE;
    m_bBySyncAudioMute = FALSE;
    m_bByVChipAudioMute = FALSE;
    m_bByBlockAudioMute = FALSE;
    m_bInternal1AudioMute = FALSE;
    m_bInternal2AudioMute = FALSE;
    m_bInternal3AudioMute = FALSE;
    m_bInternal4AudioMute = FALSE;
    m_bByDuringLimitedTimeAudioMute = FALSE;
    m_bCIAudioMute = FALSE;
    m_bMuteByHdmiAvMute = FALSE;
    m_bMuteByUiFunc = FALSE;


    m_dwStartedTimeOfMute = 0;
    m_wLimitedTimeOfMute = 0;
    m_previous_wLimitedTimeOfMute = 0;

    m_bIsSRSWOWEnabled = FALSE;


    MDrv_AUDIO_SetNormalPath(AUDIO_PATH_SIFOUT, AUDIO_SOURCE_ATV, AUDIO_OUTPUT_SIFOUT);

    m_wAudioDownCountTimer = 0;
    m_wAtvAudioCheckCount = 0;
    m_cAudioVolumePercentage = 0;

  #if (SOUNDMODE == SOUNDMODE_EQ)
    MApi_AUDIO_EnableTone(FALSE);
  #else
    MApi_AUDIO_EnableTone(TRUE);
  #endif

#if (ENABLE_CHANNEL_CHANGE_MUTE_ON_OFF_DELAY)
    m_bByPassDelay = FALSE;
#endif

#if ENABLE_ATV_CHINA_APP
    MApi_AUDIO_SIF_SendCmd(MSAPI_AUD_SIF_CMD_ENABLE_HIDEV, TRUE,0);
    MApi_AUDIO_SIF_SendCmd(MSAPI_AUD_SIF_CMD_SET_HIDEV_FILTER_BW_LEVEL, MSAPI_AUD_SIF_HIDEV_FILTER_BW_L1,0);
#endif

#if  ( (CHIP_FAMILY_TYPE == CHIP_FAMILY_NIKON)  \
     ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MILAN)  \
     ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MULAN)  \
     ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_EDEN)   \
     ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_NASA)   \
     ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MELODY)   \
     ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_EULER)  \
     ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MAYA) )

    if (OutputInfo.SpeakerOut != AUDIO_I2S_OUTPUT)
      MApi_AUDIO_SetMute(AUDIO_PATH_MAIN, FALSE);  // Clear Mute in SRC path

#endif

//========== For customer setting============
#if ((CHIP_FAMILY_TYPE == CHIP_FAMILY_A7) || \
     (CHIP_FAMILY_TYPE == CHIP_FAMILY_EMERALD) || \
     (CHIP_FAMILY_TYPE == CHIP_FAMILY_NUGGET))
    MApp_Aud_AutoVolume_Init();
    MApi_AUDIO_SetAvcMode(2);         // AVC= MStar mode
    MApi_AUDIO_SetAvcAT(3);           // Set AVC attack time to 1sec
    MApi_AUDIO_SetAvcRT(1);           // Set AVC release time to 2sec
    MApi_AUDIO_SetAvcThreshold(0x20); // -16 dBFS
    MApi_AUDIO_SetSurroundXA(0);
    MApi_AUDIO_SetSurroundXB(3);
    MApi_AUDIO_SetSurroundXK(0);
    MApi_AUDIO_SetSurroundLPFGain(2);

    MDrv_AUDIO_SetPowerDownWait(TRUE);
  #if ENABLE_NO_AUDIO_INPUT_AUTO_MUTE
    //@param1 is decided by board's performance , different board may use different value
    //for 523B_D01 board this value is suggested 0x90
    MApi_AUDIO_SetCommAudioInfo(Audio_Comm_infoType_setNR_Threshold,0x90,0);
  #endif
  #if (SUPPORT_PEQ_TOOL)
      msAPI_AUD_SetPEQ(0, 120, 10, 0, 16);
      msAPI_AUD_SetPEQ(1, 120, 10, 0, 16);
      msAPI_AUD_SetPEQ(2, 120, 10, 0, 16);
  #if (PEQ_BANDS == 5)
      msAPI_AUD_SetPEQ(3, 120, 10, 0, 16);
      msAPI_AUD_SetPEQ(4, 120, 10, 0, 16);
  #endif
    MApi_AUDIO_EnablePEQ(FALSE);
    msAPI_Timer_Delayms(1);
    MApi_AUDIO_EnablePEQ(TRUE);
  #endif
    MApi_AUDIO_ADVSOUND_ProcessEnable(SRS_TSHD);

#else  //EULER
    MApi_AUDIO_SetAvcMode(2);         // AVC= MStar mode
    MApi_AUDIO_SetAvcAT(3);           // Set AVC attack time to 1sec
    MApi_AUDIO_SetAvcRT(1);           // Set AVC release time to 2sec
    MApi_AUDIO_SetAvcThreshold(0x20); // -16 dBFS
    MApi_SND_ProcessEnable(Sound_ENABL_Type_DRC, DISABLE); // DRC
    MApi_SND_SetParam1(Sound_SET_PARAM_Drc_Threshold, 0x10, 0); // -8 dBFS
    MApi_AUDIO_SetSurroundXA(0);
    MApi_AUDIO_SetSurroundXB(3);
    MApi_AUDIO_SetSurroundXK(0);
    MApi_AUDIO_SetSurroundLPFGain(2);

    MDrv_AUDIO_SetPowerDownWait(TRUE);

  #if (SUPPORT_PEQ_TOOL)
    msAPI_AUD_SetPEQ(0, 120, 10, 0, 16);
    msAPI_AUD_SetPEQ(1, 120, 10, 0, 16);
    msAPI_AUD_SetPEQ(2, 120, 10, 0, 16);
   #if (PEQ_BANDS == 5)
    msAPI_AUD_SetPEQ(3, 120, 10, 0, 16);
    msAPI_AUD_SetPEQ(4, 120, 10, 0, 16);
   #endif
  #endif // #if (SUPPORT_PEQ_TOOL)

#if ENABLE_VD_PACH_IN_CHINA
    //Enable Audio NR
    MApi_AUDIO_SetCommAudioInfo(Audio_Comm_infoType_setNR_Threshold, G_FACTORY_SETTING.stVDSetting.AUDIO_NR,0X00);//should finetune
    //modify for complie error
//    MApi_AUDIO_SetCommAudioInfo(Audio_Comm_infoType_setNR_Threshold, 0x90,0X00);//should finetune

#endif
    MApi_AUDIO_SetAC3PInfo(Audio_AC3P_DTV_AVSYNC_OFFSET, 0x2DB4, 0);

  //  MApi_AUDIO_SOUND_SetParam(Sound_SET_Type_SetDCOffet, &DCOffet);//should finetune

#if ENABLE_DOLBY_BULLETIN24
    msAPI_DolbyBulletin24_Init();
#endif
//CAL_TIME_FUNC_END();
#endif
}


/******************************************************************************/
/// API for Audio::
/// Adjust audio by specific factor
/// @param eFactor  \b IN adjust factor
/// @param wParam1  \b param1
/// @param wParam2  \b param2
/******************************************************************************/
void msAPI_AUD_AdjustAudioFactor2(ADJUST_TVAVFACTOR eFactor, WORD wParam1, WORD wParam2)
{
    /* Used to check the mute flag, and deside if we should start mute process
        or not.
    */
    U8 bMuteProcess = FALSE;

#if (AU_BRINGUP == 1)
    return;
#endif

    //printf("msAPI_AUD_AdjustAudioFactor2(%X, %X, %X)\n", eFactor, wParam1, wParam2);

    switch (eFactor)
    {
    case E_ADJUST_CHANGE_AUDIOSOURCE: // APP Used
        msAPI_AUD_SetAudioSource((AUDIOSOURCE_TYPE)wParam1);
        m_eAudioSource = (AUDIOSOURCE_TYPE)wParam1;
      #ifndef ATSC_SYSTEM//ATSC_FIX_C
        msAPI_ATV_GetAudioMode((AUDIOSOURCE_TYPE)wParam1, &m_eAudioMode);
      #endif
        MApi_AUDIO_SIF_SetSoundMode(m_eAudioMode);
        break;

    case E_ADJUST_AUDIOMUTE:
        /* This switch statment can avoid the unnecessary delay time */
        switch(( (AUDIOMUTETYPE) wParam1 ))
        {
            case E_AUDIO_PERMANENT_MUTEOFF:
                if ( m_bPermanentAudioMute != FALSE )
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_PERMANENT_MUTEON:
                if ( m_bPermanentAudioMute != TRUE)
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_MOMENT_MUTEOFF:
                if ( m_bMomentAudioMute != FALSE )
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_MOMENT_MUTEON:
                if ( m_bMomentAudioMute != TRUE )
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_BYUSER_MUTEOFF:
                if ( m_bByUserAudioMute != FALSE )
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_BYUSER_MUTEON:
                if ( m_bByUserAudioMute != TRUE)
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_BYSYNC_MUTEOFF:
                if (m_bBySyncAudioMute != FALSE)
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_BYSYNC_MUTEON:
                if (m_bBySyncAudioMute != TRUE)
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_BYVCHIP_MUTEOFF:
                if (m_bByVChipAudioMute != FALSE)
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_BYVCHIP_MUTEON:
                if (m_bByVChipAudioMute != TRUE)
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_BYBLOCK_MUTEOFF:
                if (m_bByBlockAudioMute != FALSE)
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_BYBLOCK_MUTEON:
                if (m_bByBlockAudioMute != TRUE)
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_INTERNAL_1_MUTEOFF:
                if (m_bInternal1AudioMute != FALSE)
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_INTERNAL_1_MUTEON:
                if (m_bInternal1AudioMute != TRUE)
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_INTERNAL_2_MUTEOFF:
                if (m_bInternal2AudioMute != FALSE)
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_INTERNAL_2_MUTEON:
                if (m_bInternal2AudioMute != TRUE)
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_INTERNAL_3_MUTEOFF:
                if (m_bInternal3AudioMute != FALSE)
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_INTERNAL_3_MUTEON:
                if (m_bInternal3AudioMute != TRUE)
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_INTERNAL_4_MUTEOFF:
                if (m_bInternal4AudioMute != FALSE)
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_INTERNAL_4_MUTEON:
                if (m_bInternal4AudioMute != TRUE)
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_DURING_LIMITED_TIME_MUTEOFF:
                if (m_bByDuringLimitedTimeAudioMute != FALSE)
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_DURING_LIMITED_TIME_MUTEON:
                if ( m_bByDuringLimitedTimeAudioMute != TRUE )
                {
                    bMuteProcess = TRUE;
                }
                break;

            // MHEG AP Mute Off
            case E_AUDIO_MHEGAP_MUTEOFF:
                if (m_bMHEGApMute != FALSE)
                {
                    bMuteProcess = TRUE;
                }
                break;

            // MHEG AP Mute On
            case E_AUDIO_MHEGAP_MUTEON:
                if (m_bMHEGApMute != TRUE)
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_CI_MUTEOFF:
                if (m_bCIAudioMute != FALSE)
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_CI_MUTEON:
                if (m_bCIAudioMute != TRUE)
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_HDMI_AVMUTE_MUTEOFF:
                if (m_bMuteByHdmiAvMute != FALSE)
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_HDMI_AVMUTE_MUTEON:
                if (m_bMuteByHdmiAvMute != TRUE)
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_UI_FUNC_MUTEOFF:
                if (m_bMuteByUiFunc != FALSE)
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_UI_FUNC_MUTEON:
                if (m_bMuteByUiFunc != TRUE)
                {
                    bMuteProcess = TRUE;
                }
                break;

        #if ENABLE_ATSC_TTS
            case E_AUDIO_TTS_Background_MUTEOFF:
                if ( m_bTTSBackgroundAudioMute != FALSE )
                {
                    bMuteProcess = TRUE;
                }
                break;

            case E_AUDIO_TTS_Background_MUTEON:
                if ( m_bTTSBackgroundAudioMute != TRUE )
                {
                    bMuteProcess = TRUE;
                }
                break;
        #endif

            default:
                  break;
        }

        if ( bMuteProcess )
        {
        #if (ENABLE_CHANNEL_CHANGE_MUTE_ON_OFF_DELAY)
            if ((wParam1%2)==0)   // Mute off
            {
                if(!m_bByPassDelay) //fix laggardly issue of playing movie; MHEG Audio File Playback also needs no time delay when mute on/off
                {
                    msAPI_Timer_Delayms(DELAY_FOR_LEAVING_MUTE);
                }
            }

            SetAudioMute((AUDIOMUTETYPE) wParam1, (AUDIOMUTESOURCE_TYPE) wParam2);

            if ((wParam1%2)==1)  // Mute on
            {
                if(!m_bByPassDelay) //fix laggardly issue of playing movie; MHEG Audio File Playback also needs no time delay when mute on/off
                {
                    msAPI_Timer_Delayms(DELAY_FOR_ENTERING_MUTE);
                }
            }
        #else

            SetAudioMute((AUDIOMUTETYPE) wParam1, (AUDIOMUTESOURCE_TYPE) wParam2);

        #endif
        }
        break;

    case E_ADJUST_AUDIOMUTE_DURING_LIMITED_TIME:
        SetAudioMuteDuringLimitedTime(wParam1, (AUDIOMUTESOURCE_TYPE) wParam2);
        break;

    case E_ADJUST_VOLUME:
        if( wParam1 <= 100 )
            m_cAudioVolumePercentage = (BYTE)wParam1;

    #if 1
        if( msAPI_AUD_IsAudioMuted() )
    #else
        if( m_bPermanentAudioMute == TRUE ||
            m_bMomentAudioMute == TRUE ||
            m_bByUserAudioMute == TRUE ||
            m_bBySyncAudioMute == TRUE ||
            m_bByVChipAudioMute == TRUE ||
            m_bByBlockAudioMute == TRUE ||
            m_bInternal1AudioMute == TRUE ||
            m_bInternal2AudioMute == TRUE ||
            m_bInternal3AudioMute == TRUE ||
            m_bInternal4AudioMute == TRUE ||
            m_bByDuringLimitedTimeAudioMute == TRUE
         || m_bMuteByHdmiAvMute
         || m_bMuteByUiFunc
          )
    #endif
        {
            return;
        }
        AUDIO_API_TRACE(printf("\r\n@@@ ===MApp_Audio_AdjustMainVolume : %d===@@@",m_cAudioVolumePercentage));
        MApp_Audio_AdjustMainVolume(m_cAudioVolumePercentage);

        break;

    case E_ADJUST_CHANGE_AUDIOMODE: //APP used
        AUDIO_API_TRACE(printf("\r\n@@@ ===msAPI_AUD_ChangeAudioMode===@@@"));
        msAPI_AUD_ChangeAudioMode();
    #ifndef ATSC_SYSTEM//ATSC_FIX_C
        if( (m_eAudioSource == E_AUDIOSOURCE_ATV) && (msAPI_AVD_IsAutoAVActive(E_AUTOAV_SOURCE_2) == TRUE) )
            msAPI_ATV_SetAudioMode(E_AUDIOSOURCE_SCART2, m_eAudioMode);
        else if( (m_eAudioSource == E_AUDIOSOURCE_ATV) && (msAPI_AVD_IsAutoAVActive(E_AUTOAV_SOURCE_1) == TRUE) )
            msAPI_ATV_SetAudioMode(E_AUDIOSOURCE_SCART1, m_eAudioMode);
        else
            msAPI_ATV_SetAudioMode(m_eAudioSource, m_eAudioMode);
    #endif
        break;

     default:
        break;
    }
}

/******************************************************************************/
/// API for Audio::
/// Check audio is muted now
/// @return true or false
/******************************************************************************/
BOOLEAN msAPI_AUD_IsAudioMuted(void)
{
    if (  m_bPermanentAudioMute
       || m_bMomentAudioMute
       || m_bByUserAudioMute
       || m_bBySyncAudioMute
       || m_bByVChipAudioMute
       || m_bByBlockAudioMute
       || m_bInternal1AudioMute
       || m_bInternal2AudioMute
       || m_bInternal3AudioMute
       || m_bInternal4AudioMute
       || m_bByDuringLimitedTimeAudioMute
       || m_bMHEGApMute
       || m_bCIAudioMute
       || m_bMuteByHdmiAvMute
       || m_bMuteByUiFunc
       )
    {
        return TRUE;
    }

    return FALSE;
}

void msAPI_AUD_PrintMuteClient(void)
{
    if( msAPI_AUD_IsAudioMuted() )
    {
        /*printf("\n\033[37;1m AudioMute:");
        if( m_bPermanentAudioMute ) printf(" Permanent,");
        if( m_bMomentAudioMute ) printf(" Moment,");
        if( m_bByUserAudioMute ) printf(" User,");
        if( m_bBySyncAudioMute ) printf(" Sync,");
        if( m_bByVChipAudioMute ) printf(" VChip,");
        if( m_bByBlockAudioMute ) printf(" Block,");

        if( m_bInternal1AudioMute ) printf(" Inter1,");
        if( m_bInternal2AudioMute ) printf(" Inter2,");
        if( m_bInternal3AudioMute ) printf(" Inter3,");
        if( m_bInternal4AudioMute ) printf(" Inter4,");

        if( m_bByDuringLimitedTimeAudioMute ) printf(" Time,");
        if( m_bMHEGApMute ) printf(" MHEG,");
        if( m_bCIAudioMute ) printf(" CI,");

        if( m_bMuteByHdmiAvMute ) printf(" HdmiAv,");
        if( m_bMuteByUiFunc ) printf(" UiFunc,");

    #if ENABLE_ATSC_TTS
        if( m_bTTSBackgroundAudioMute ) printf(" TTS,");
    #endif

        printf("\033[0m \n");*/
    }
}

/******************************************************************************/
/// API for Audio::
/// Check audio is muted by user or not
/// @return true or false
/******************************************************************************/
BOOLEAN msAPI_AUD_IsAudioMutedByUser(void)
{
    if (m_bByUserAudioMute == FALSE)
        return FALSE;

    return TRUE;
}

/******************************************************************************/
/// API for Audio::
/// Set audio mute during time limit
/// @param w1ms \b IN Limit time of mute
/// @param eAudioMuteSource \b IN the audio source type
/******************************************************************************/
static void SetAudioMuteDuringLimitedTime(WORD w1ms, AUDIOMUTESOURCE_TYPE eAudioMuteSource)
{
    int remain_previous_w1ms = m_previous_wLimitedTimeOfMute - msAPI_Timer_DiffTimeFromNow(m_dwStartedTimeOfMute);

    if( (m_wLimitedTimeOfMute != 0) && ((int)w1ms < remain_previous_w1ms) )
    {
        return;
    }

    SetAudioMute(E_AUDIO_DURING_LIMITED_TIME_MUTEON, eAudioMuteSource);

    m_wLimitedTimeOfMute = w1ms;
    m_dwStartedTimeOfMute = msAPI_Timer_GetTime0();
    m_previous_wLimitedTimeOfMute = w1ms;
}

/******************************************************************************/
/// API for Audio::
/// Check the audio mute time is expiration or not.
/******************************************************************************/
void msAPI_AUD_CheckExpirationOfAudioMute(void)
{
    if( m_wLimitedTimeOfMute == 0 )
        return;

    if(msAPI_Timer_DiffTimeFromNow(m_dwStartedTimeOfMute) > m_wLimitedTimeOfMute)
    {
        SetAudioMute(E_AUDIO_DURING_LIMITED_TIME_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
        m_wLimitedTimeOfMute = 0;
        m_dwStartedTimeOfMute = 0;
        m_previous_wLimitedTimeOfMute = 0;
    }
}

/******************************************************************************/
/// API for Audio::
/// The main function of setting audio mute
/// @param eAudioMuteType \b IN The mute type
/// @param eAudioMuteSource \b IN The input source that needs to be mute
/******************************************************************************/
static void SetAudioMute(AUDIOMUTETYPE eAudioMuteType, AUDIOMUTESOURCE_TYPE eAudioMuteSource)
{
    if ( (eAudioMuteSource != E_AUDIOMUTESOURCE_ACTIVESOURCE)
       &&(eAudioMuteSource !=(AUDIOMUTESOURCE_TYPE) m_eAudioSource) )
        return;

    MS_BOOL spkrMute, scartMute, spdifMute, bMixGame1Mute=0;
    AUDIO_PATH_GROUP_TYPE Audio_pathgroup_status;
    Audio_pathgroup_status = MDrv_AUDIO_GetPathGroup();

    switch(eAudioMuteType)
    {
        case E_AUDIO_MHEGAP_MUTEOFF:
            m_bMHEGApMute = FALSE;
            break;
        case E_AUDIO_MHEGAP_MUTEON:
            m_bMHEGApMute = TRUE;
            break;
        case E_AUDIO_PERMANENT_MUTEOFF:
            m_bPermanentAudioMute = FALSE;
            break;
        case E_AUDIO_PERMANENT_MUTEON:
            m_bPermanentAudioMute = TRUE;
            break;
        case E_AUDIO_MOMENT_MUTEOFF:
            m_bMomentAudioMute = FALSE;
            break;
        case E_AUDIO_MOMENT_MUTEON:
            m_bMomentAudioMute = TRUE;
            break;
        case E_AUDIO_BYUSER_MUTEOFF:
            m_bByUserAudioMute = FALSE;
            break;
        case E_AUDIO_BYUSER_MUTEON:
            m_bByUserAudioMute = TRUE;
            break;
        case E_AUDIO_BYSYNC_MUTEOFF:
            m_bBySyncAudioMute = FALSE;
            break;
        case E_AUDIO_BYSYNC_MUTEON:
            m_bBySyncAudioMute = TRUE;
            break;
        case E_AUDIO_BYVCHIP_MUTEOFF:
            m_bByVChipAudioMute = FALSE;
            break;
        case E_AUDIO_BYVCHIP_MUTEON:
            m_bByVChipAudioMute = TRUE;
            break;
        case E_AUDIO_BYBLOCK_MUTEOFF:
            m_bByBlockAudioMute = FALSE;
            break;
        case E_AUDIO_BYBLOCK_MUTEON:
            m_bByBlockAudioMute = TRUE;
            break;
        case E_AUDIO_INTERNAL_1_MUTEOFF:
            m_bInternal1AudioMute = FALSE;
            break;
        case E_AUDIO_INTERNAL_1_MUTEON:
            m_bInternal1AudioMute = TRUE;
            break;
        case E_AUDIO_INTERNAL_2_MUTEOFF:
            m_bInternal2AudioMute = FALSE;
            break;
        case E_AUDIO_INTERNAL_2_MUTEON:
            m_bInternal2AudioMute = TRUE;
            break;
        case E_AUDIO_INTERNAL_3_MUTEOFF:
            m_bInternal3AudioMute = FALSE;
            break;
        case E_AUDIO_INTERNAL_3_MUTEON:
            m_bInternal3AudioMute = TRUE;
            break;
        case E_AUDIO_INTERNAL_4_MUTEOFF:
            m_bInternal4AudioMute = FALSE;
            break;
        case E_AUDIO_INTERNAL_4_MUTEON:
            m_bInternal4AudioMute = TRUE;
            break;
        case E_AUDIO_DURING_LIMITED_TIME_MUTEOFF:
            m_bByDuringLimitedTimeAudioMute = FALSE;
            break;
        case E_AUDIO_DURING_LIMITED_TIME_MUTEON:
            m_bByDuringLimitedTimeAudioMute = TRUE;
            break;
        case E_AUDIO_CI_MUTEOFF:
            m_bCIAudioMute = FALSE;
            break;
        case E_AUDIO_CI_MUTEON:
            m_bCIAudioMute = TRUE;
            break;

        case E_AUDIO_HDMI_AVMUTE_MUTEOFF:
            m_bMuteByHdmiAvMute = FALSE;
            break;
        case E_AUDIO_HDMI_AVMUTE_MUTEON:
            m_bMuteByHdmiAvMute = TRUE;
            break;

        case E_AUDIO_UI_FUNC_MUTEOFF:
            m_bMuteByUiFunc = FALSE;
            break;
        case E_AUDIO_UI_FUNC_MUTEON:
            m_bMuteByUiFunc = TRUE;
            break;

    #if ENABLE_ATSC_TTS
        case E_AUDIO_TTS_Background_MUTEOFF:
            m_bTTSBackgroundAudioMute = FALSE;
            break;

        case E_AUDIO_TTS_Background_MUTEON:
            m_bTTSBackgroundAudioMute = TRUE;
            break;
    #endif

        default:
            return;
    }

#if 0
    printf("audio mute status: p:%d,", m_bPermanentAudioMute);
    printf("m:%d,",m_bMomentAudioMute);
    printf("u:%d,",m_bByUserAudioMute);
    printf("s:%d,",m_bBySyncAudioMute);
    printf("b:%d,",m_bByBlockAudioMute);
    printf("v:%d,",m_bByVChipAudioMute);
    printf("i1:%d,",m_bInternal1AudioMute);
    printf("i2:%d,",m_bInternal2AudioMute);
    printf("i3:%d,",m_bInternal3AudioMute);
    printf("i4:%d,",m_bInternal4AudioMute);
    printf("t:%d,",m_bByDuringLimitedTimeAudioMute);
    printf("mhg:%d,", m_bMHEGApMute);
    printf("CI:%d\n",m_bCIAudioMute);
#endif

    if( Audio_pathgroup_status == AUDIO_PATH_GROUP_2)
    {
        spkrMute =  //m_bPermanentAudioMute|
                    m_bMomentAudioMute|
                    m_bByUserAudioMute|
                    m_bBySyncAudioMute|
                    //m_bByBlockAudioMute|
                    //m_bByVChipAudioMute|
                    m_bInternal1AudioMute|
                    //m_bInternal2AudioMute|
                    m_bInternal3AudioMute|
                    m_bInternal4AudioMute|
                    m_bByDuringLimitedTimeAudioMute|
                    m_bMHEGApMute|
                    m_bMuteByHdmiAvMute|
                    m_bMuteByUiFunc;
    }
    else
    {
        spkrMute =  m_bPermanentAudioMute|
                    m_bMomentAudioMute|
                    m_bByUserAudioMute|
                    m_bBySyncAudioMute|
                    m_bByBlockAudioMute|
                    m_bByVChipAudioMute|
                    m_bInternal1AudioMute|
                    m_bInternal2AudioMute|
                    m_bInternal3AudioMute|
                    m_bInternal4AudioMute|
                    m_bByDuringLimitedTimeAudioMute|
                    m_bMHEGApMute|
                    m_bMuteByHdmiAvMute|
                    m_bMuteByUiFunc;
    }

    bMixGame1Mute = m_bPermanentAudioMute|
                    m_bInternal2AudioMute|
                    m_bBySyncAudioMute|
                #if ENABLE_ATSC_TTS
                    m_bTTSBackgroundAudioMute |
                #endif
                    m_bByBlockAudioMute;

    scartMute = m_bPermanentAudioMute|
                m_bMomentAudioMute|
                m_bBySyncAudioMute|
                m_bByBlockAudioMute|
                m_bByVChipAudioMute|
                m_bInternal1AudioMute|
                m_bInternal2AudioMute|
                m_bInternal3AudioMute|
                m_bInternal4AudioMute|
                m_bCIAudioMute|
                m_bByDuringLimitedTimeAudioMute|
                m_bMHEGApMute|
                m_bMuteByHdmiAvMute|
                m_bMuteByUiFunc;

    spdifMute = m_bPermanentAudioMute|
                m_bMomentAudioMute|
                m_bBySyncAudioMute|
                m_bByBlockAudioMute|
                m_bByVChipAudioMute|
                m_bInternal1AudioMute|
                m_bInternal2AudioMute|
                m_bInternal3AudioMute|
                m_bInternal4AudioMute|
                m_bByDuringLimitedTimeAudioMute|
                m_bMHEGApMute|
                m_bMuteByHdmiAvMute|
                m_bMuteByUiFunc;

  #if ENABLE_EWS
    if(bEwsAudioMuteControl == TRUE)
        spkrMute = FALSE;
  #endif

    if(spkrMute == TRUE)
    {
        MW_AUD_SetSoundMute(SOUND_MUTE_TV, E_MUTE_ON);
    }
    else
    {
        Audio_Amplifier_ON();
        MApp_Audio_AdjustMainVolume(m_cAudioVolumePercentage);
        MW_AUD_SetSoundMute(SOUND_MUTE_TV, E_MUTE_OFF);
    }

    if(scartMute == TRUE)
    {
        MW_AUD_SetSoundMute(SOUND_MUTE_SCART, E_MUTE_ON);
        MW_AUD_SetSoundMute(SOUND_MUTE_SCART2, E_MUTE_ON);
    }
    else
    {
        MW_AUD_SetSoundMute(SOUND_MUTE_SCART, E_MUTE_OFF);
        MW_AUD_SetSoundMute(SOUND_MUTE_SCART2, E_MUTE_OFF);
    }

    if(spdifMute == TRUE)
    {
        MW_AUD_SetSoundMute(SOUND_MUTE_SPDIF, E_MUTE_ON);
    }
    else
    {
        MW_AUD_SetSoundMute(SOUND_MUTE_SPDIF, E_MUTE_OFF);
    }

    if( Audio_pathgroup_status == AUDIO_PATH_GROUP_2)
    {
        if(bMixGame1Mute == TRUE)
        {
            MApi_AUDIO_SetMixModeMute(E_AUDIO_INFO_GAME_IN, GAME1_VOL, TRUE);
        }
        else
        {
            MApi_AUDIO_SetMixModeMute(E_AUDIO_INFO_GAME_IN, GAME1_VOL, FALSE);
        }
    }
}

#if (ENABLE_CHANNEL_CHANGE_MUTE_ON_OFF_DELAY)
void msAPI_AUD_SetByPassDelayFlag(BOOLEAN flag)
{
    m_bByPassDelay = flag;
}
#endif

/******************************************************************************/
/// API for Audio::
/// Switch the audio decoder system.
/// @return the audio standard
/******************************************************************************/
void msAPI_AUD_SwitchAudioDSPSystem(AUDIO_DSP_SYSTEM eAudioDSPSystem)
{
    AUDIO_API_TRACE(printf("\r\n@@@ ===msAPI_AUD_SwitchAudioDSPSystem : 0x%X===@@@",(int)eAudioDSPSystem));

    if( m_eAudioDSPSystem == eAudioDSPSystem)
    {
        if (eAudioDSPSystem == E_AUDIO_DSP_SIF)
        {
            MDrv_AUDIO_TriggerSifPLL();  // Audio Strange setting
        }
        return;
    }

    switch(eAudioDSPSystem)
    {
    case E_AUDIO_DSP_AC3:
        MApi_AUDIO_SetCommand(MSAPI_AUD_DVB_DECCMD_STOP);
        m_eAudioDSPSystem = E_AUDIO_DSP_AC3;
        MApi_AUDIO_SetSystem(MSAPI_AUD_DVB_AC3);//MDrv_MAD_SetSystem(AU_DVB_SYS_AC3);
        break;

    case E_AUDIO_DSP_AC3_AD:
        m_eAudioDSPSystem = E_AUDIO_DSP_AC3_AD;
        MApi_AUDIO_SetSystem(MSAPI_AUD_DVB2_AC3);//MDrv_MAD2_SetSystem(AU_DVB2_SYS_AC3_AD);  // Separate DVB2(AD) decoder from DVB
        break;

    case E_AUDIO_DSP_AC3P:
            MApi_AUDIO_SetCommand(MSAPI_AUD_DVB_DECCMD_STOP);
        m_eAudioDSPSystem = E_AUDIO_DSP_AC3P;
        MApi_AUDIO_SetSystem(MSAPI_AUD_DVB_AC3P);//MDrv_MAD_SetSystem(AU_DVB_SYS_AC3P);
        break;

    case E_AUDIO_DSP_AC3P_AD:
        m_eAudioDSPSystem = E_AUDIO_DSP_AC3P_AD;
        MApi_AUDIO_SetSystem(MSAPI_AUD_DVB2_AC3P);//MDrv_MAD2_SetSystem(AU_DVB2_SYS_AC3P_AD);
        break;

    case E_AUDIO_DSP_SIF:
        m_eAudioDSPSystem = E_AUDIO_DSP_SIF;
        MApi_AUDIO_SIF_SendCmd(MSAPI_AUD_SIF_CMD_SET_STOP, 0,0);// stop play
      #if (SIF_IS_PAL_SYSTEM)
        MApi_AUDIO_SetSystem(MSAPI_AUD_ATV_PAL);
      #else
        MApi_AUDIO_SetSystem(MSAPI_AUD_ATV_BTSC);
      #endif
        MApi_AUDIO_SIF_SetThreshold(AuSifInitThreshold);


     #if (SIF_IS_PAL_SYSTEM)
      #if((FRONTEND_IF_DEMODE_TYPE==MSTAR_VIF)||(FRONTEND_IF_DEMODE_TYPE==MSTAR_VIF_MSB1210)||(FRONTEND_IF_DEMODE_TYPE==MSTAR_INTERN_VIF))
        MApi_AUDIO_SIF_SetPrescale(SET_PRESCALE_A2_FM,3); //kochien for VIF
        MApi_AUDIO_SIF_SetPrescale(SET_PRESCALE_NICAM,3);
        MApi_AUDIO_SIF_SetPrescale(SET_PRESCALE_AM,7);
        MApi_AUDIO_SIF_SetPrescale(SET_PRESCALE_HIDEV,3);
      #else  // MSTAR_INTERN_VIF & NONE_VIF
        MApi_AUDIO_SIF_SetPrescale(SET_PRESCALE_A2_FM,6);
        MApi_AUDIO_SIF_SetPrescale(SET_PRESCALE_AM,9);
        MApi_AUDIO_SIF_SetPrescale(SET_PRESCALE_NICAM,6);
        MApi_AUDIO_SIF_SetPrescale(SET_PRESCALE_HIDEV,6);
      #endif
     #else
        MApi_AUDIO_SIF_SetPrescale(SET_PRESCALE_BTSC,0);
        MApi_AUDIO_SIF_SetPrescale(SET_PRESCALE_BTSC_MONO,0);
        MApi_AUDIO_SIF_SetPrescale(SET_PRESCALE_BTSC_STEREO,0);
        MApi_AUDIO_SIF_SetPrescale(SET_PRESCALE_BTSC_SAP,0);
     #endif

        MDrv_AUDIO_TriggerSifPLL();
        MApi_AUDIO_SIF_SendCmd(MSAPI_AUD_SIF_CMD_SET_PLAY, 0,0);
        break;

    case E_AUDIO_DSP_AACP:
        MApi_AUDIO_SetCommand(MSAPI_AUD_DVB_DECCMD_STOP);
        m_eAudioDSPSystem = E_AUDIO_DSP_AACP;
        MApi_AUDIO_SetSystem(MSAPI_AUD_DVB_AAC);//MDrv_MAD_SetSystem(AU_DVB_SYS_AAC);
        break;

    case E_AUDIO_DSP_MPEG_AD:
        m_eAudioDSPSystem = E_AUDIO_DSP_MPEG_AD;
        MApi_AUDIO_SetSystem(MSAPI_AUD_DVB2_MPEG);//MDrv_MAD2_SetSystem(AU_DVB2_SYS_MPEG_AD);  // Separate DVB2(AD) decoder from DVB
        break;

    case E_AUDIO_DSP_AACP_AD:
        m_eAudioDSPSystem = E_AUDIO_DSP_AACP_AD;
        MApi_AUDIO_SetSystem(MSAPI_AUD_DVB2_AAC);//MDrv_MAD2_SetSystem(AU_DVB2_SYS_AAC_AD);  // Separate DVB2(AD) decoder from DVB
        break;

    case E_AUDIO_DSP_MPEG:
    default:
        MApi_AUDIO_SetCommand(MSAPI_AUD_DVB_DECCMD_STOP);
        m_eAudioDSPSystem = E_AUDIO_DSP_MPEG;
        MApi_AUDIO_SetSystem(MSAPI_AUD_DVB_MPEG);//MDrv_MAD_SetSystem(AU_DVB_SYS_MPEG);
        break;
    }
}

/******************************************************************************/
/// API for Audio::
/// This routine is used to report decoder channel mode information.
/// @return the audio standard
/******************************************************************************/
AUDIO_DEC_ChannelMOD_Type msAPI_AUD_DECODER_GetChannelMode(AUDIOSTREAM_TYPE_ eAudioStreamType)
{
    AUDIO_DEC_ChannelMOD_Type DecChMod_Status;

    long long ChMod_Status_tmp;

    if (MApi_AUDIO_IsMadLock())
    {
        if ((eAudioStreamType == E_AUDIOSTREAM_AC3_) || (eAudioStreamType == E_AUDIOSTREAM_AC3P_))
        {   // DD, DDP
            ChMod_Status_tmp = MApi_AUDIO_GetCommAudioInfo(Audio_Comm_infoType_ADEC1_acmod);
            if (ChMod_Status_tmp == AUD_CH_MODE_DUAL_MONO)
            {
                DecChMod_Status = AUDIO_DEC_ACMODE_DUALMONO;
            }
            else if (ChMod_Status_tmp == AUD_CH_MODE_MONO)
            {
                DecChMod_Status = AUDIO_DEC_ACMODE_MONO;
            }
            else if (ChMod_Status_tmp == AUD_CH_MODE_STEREO)
            {
                DecChMod_Status = AUDIO_DEC_ACMODE_STEREO;
            }
            else if ((ChMod_Status_tmp > AUD_CH_MODE_STEREO) && (ChMod_Status_tmp <= 0x7))
            {
                DecChMod_Status = AUDIO_DEC_ACMODE_MULTICH;
            }
            else
            {
                DecChMod_Status = AUDIO_DEC_ACMODE_NOTREADY;
            }
        }
        else if (eAudioStreamType == E_AUDIOSTREAM_MPEG_)
        {   // MPEG Audio

            ChMod_Status_tmp = MApi_AUDIO_GetCommAudioInfo(Audio_Comm_infoType_ChannelMode);
            if (ChMod_Status_tmp == AUD_CH_MODE_DUAL_MONO)
            {
                DecChMod_Status = AUDIO_DEC_ACMODE_MONO;
            }
            else if (ChMod_Status_tmp == AUD_CH_MODE_MONO)
            {
                DecChMod_Status = AUDIO_DEC_ACMODE_MONO;
            }
            else if (ChMod_Status_tmp == AUD_CH_MODE_STEREO)
            {
                DecChMod_Status = AUDIO_DEC_ACMODE_STEREO;
            }
            else
            {
                DecChMod_Status = AUDIO_DEC_ACMODE_NOTREADY;
            }
       }
       else
       {
            DecChMod_Status = AUDIO_DEC_ACMODE_NOTREADY;
       }
    }
    else
    {
        DecChMod_Status = AUDIO_DEC_ACMODE_NOTREADY;
    }

    return(DecChMod_Status);
}

/******************************************************************************/
/// API for Audio::
/// Set decoder output to Stereo/LL/RR/Mixed LR
/// @return the audio standard
/******************************************************************************/
void msAPI_AUD_DECODER_SetOutputMode(En_DVB_soundModeType_ mode)
{
    m_Audio_currSoundMode = mode;
    MApi_AUDIO_SetCommAudioInfo(Audio_Comm_infoType_SoundMode, (MS_U32)mode, 0);
}

/******************************************************************************/
/// API for Audio::
/// Get decoder current output to Stereo/LL/RR/Mixed LR mode
/// @return the audio standard
/******************************************************************************/
En_DVB_soundModeType_ msAPI_AUD_DECODER_GetCurrOutputMode(void)
{
    return(m_Audio_currSoundMode);
}

/******************************************************************************/
/// API for Audio::
/// Get Decoder(MPEG/AC3/AC3P/HEAAC) Lock Status
/// @return \b  1: lock
///             0: unlock
/******************************************************************************/
BOOLEAN msAPI_AUD_DECODER_GetMAD_LOCK(void)
{
    #if (CHIP_FAMILY_TYPE==CHIP_FAMILY_EDEN)
        return(MApi_AUDIO_GetMAD_LOCK());
    #else
        return(MApi_AUDIO_IsMadLock());
    #endif
}

/******************************************************************************/
/// API for Audio::
/// Get Decoder(MPEG/AC3) PCM Buffer Level Status
/// @return \b  PCM Buffer Level value
/******************************************************************************/
MS_U32 msAPI_AUD_DECODER_GetMAD_PCMBufLevel(AUDIOSTREAM_TYPE_ eAudioStreamType)
{
    if (eAudioStreamType == E_AUDIOSTREAM_AC3_)
    {
      #if ENABLE_ATSC
        return (MApi_AUDIO_GetCommAudioInfo(Audio_Comm_infoType_ADEC1_pcmBuf_currLevel));
      #else
        return(MApi_AUDIO_GetAC3Info(Audio_AC3_infoType_PCMBufLevel));
      #endif
    }
    else
    {
        return(MApi_AUDIO_GetMpegInfo(Audio_MPEG_infoType_PCMBufLev));
    }
}

/******************************************************************************/
/// API for Audio::
/// Get MAD DEC/SE/ADV base address
/// @return the audio base address
/******************************************************************************/
MS_U32 msAPI_AUD_GetDspMadBaseAddr(MS_U8 u8Index)
{
    return (MDrv_AUDIO_GetDspMadBaseAddr(u8Index));
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
///
///           AUDIO_ATV RELATIONAL API FUNCTION
///
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

/******************************************************************************/
/// API for Audio::
/// Get the present audio standard.
/// @return the audio standard
/******************************************************************************/
AUDIOSTANDARD_TYPE msAPI_AUD_GetAudioStandard(void)
{
    if(E_AUDIOSTANDARD_NOTSTANDARD == MApi_AUDIO_SIF_ConvertToBasicAudioStandard(m_eAudioStandard))
    {
    #ifdef ATSC_SYSTEM //ATSC_FIX_C
        return E_AUDIOSTANDARD_NOTSTANDARD;
    #else
      #if (TV_SYSTEM == TV_NTSC)
        #if (AUDIO_SYSTEM_SEL == AUDIO_SYSTEM_BTSC)
            return E_AUDIOSTANDARD_M_BTSC;
        #elif (AUDIO_SYSTEM_SEL == AUDIO_SYSTEM_A2)
            return E_AUDIOSTANDARD_M_A2;
        #endif
      #else
        //return msAPI_ATV_GetAudioStandard(msAPI_ATV_GetCurrentProgramNumber());

        //Use "msAPI_ATV_GetCurrentProgramNumber()" to refer the audio standard of previous channel is wrong at manual tuning.
        //Suggest to assign default audio standard. 20100321EL
        #if ( ENABLE_DTMB_CHINA_APP || ENABLE_ATV_CHINA_APP )
            return E_AUDIOSTANDARD_DK;
        #else
            return E_AUDIOSTANDARD_DK;//E_AUDIOSTANDARD_BG;
        #endif
      #endif
    #endif
    }

    return m_eAudioStandard;
}


/******************************************************************************/
/// API for Audio::
/// chec if audio stand is detected
/// @return true/ false
/******************************************************************************/

BOOLEAN msAPI_AUD_IsAudioDetected(void)
{
    if(E_AUDIOSTANDARD_NOTSTANDARD == MApi_AUDIO_SIF_ConvertToBasicAudioStandard(m_eAudioStandard))
        return FALSE;
    else
        return TRUE;

}


/******************************************************************************/
/// API for Audio::
/// Set the audio standard.
/// @param eStandard \b IN The audio standard
/******************************************************************************/
void msAPI_AUD_SetAudioStandard(AUDIOSTANDARD_TYPE eStandard)
{
#if (TV_SYSTEM == TV_NTSC)
    eStandard = E_AUDIOSTANDARD_M_BTSC;
    m_eAudioStandard = eStandard;
#else
    m_eAudioStandard = MApi_AUDIO_SIF_ConvertToBasicAudioStandard(eStandard);
#endif

    if( E_AUDIOSTANDARD_NOTSTANDARD == m_eAudioStandard )
    {
    #ifndef ATSC_SYSTEM //ATSC_FIX_C
        eStandard = msAPI_ATV_GetAudioStandard(msAPI_ATV_GetCurrentProgramNumber());
    #endif

        if(eStandard == E_AUDIOSTANDARD_NOTSTANDARD)
        {
        #if ( ENABLE_DTMB_CHINA_APP || ENABLE_ATV_CHINA_APP )
                eStandard = E_AUDIOSTANDARD_DK;
        #else
          #if (TV_SYSTEM == TV_NTSC)
            #if (AUDIO_SYSTEM_SEL == AUDIO_SYSTEM_BTSC)
                eStandard = E_AUDIOSTANDARD_M_BTSC;
            #elif (AUDIO_SYSTEM_SEL == AUDIO_SYSTEM_A2)
                eStandard = E_AUDIOSTANDARD_M_A2;
            #endif
          #else
                eStandard = E_AUDIOSTANDARD_DK;//E_AUDIOSTANDARD_BG;
          #endif
        #endif
        }
    }

#if (MTS_NICAM_UNSTABLE)
    g_NICAMEnable = 1;
    g_CarrierStableCnt = 0;
#endif

    SetAudioMuteDuringLimitedTime(DELAY_FOR_ENTERING_MUTE, E_AUDIOMUTESOURCE_ACTIVESOURCE);
    MApi_AUDIO_SIF_SendCmd(MSAPI_AUD_SIF_STANDARD_RESET, NULL, NULL);
    g_A2ModeInvalidCnt = 0;

    if(m_eAudioStandard == E_AUDIOSTANDARD_L)
        MApi_AUDIO_SIF_SetPALType(AU_SIF_PAL_NICAM);
    else
        MApi_AUDIO_SIF_SetPALType(AU_SIF_PAL_MONO);

    MApi_AUDIO_SIF_SetStandard(m_eAudioStandard);
    MApi_AUDIO_SIF_SetSoundMode(m_eAudioMode);
    m_eAudioStatus = E_STATE_AUDIO_NO_CARRIER;

    //if( (m_eAudioSource == E_AUDIOSOURCE_ATV) && (msAPI_AVD_IsAutoAVActive(E_AUTOAV_SOURCE_ALL) == FALSE) )
}

#if(VIF_TUNER_TYPE==1)
/******************************************************************************/
/// API for Audio::
/// Set the audio standard.
/// @param eStandard \b IN The audio standard
/******************************************************************************/
void msAPI_AUD_ChangeProgSetAudioStandard(AUDIOSTANDARD_TYPE eStandard)
{
#if (TV_SYSTEM == TV_NTSC)
    m_eAudioStandard = eStandard;
#else
    m_eAudioStandard = MApi_AUDIO_SIF_ConvertToBasicAudioStandard(eStandard);
#endif
}
#endif

/******************************************************************************/
/// API for Audio::
/// Force to set the audio standard.
/// @param eStandard \b IN The audio standard
/******************************************************************************/
void msAPI_AUD_ForceAudioStandard(AUDIOSTANDARD_TYPE eStandard)
{
  #ifndef ATSC_SYSTEM//ATSC_FIX_C
    AUDIOMODE_TYPE eAudioMode;
  #endif

    SetAudioMute(E_AUDIO_INTERNAL_1_MUTEON, E_AUDIOMUTESOURCE_ATV);
    msAPI_AUD_SetAudioStandard(eStandard);

  #ifndef ATSC_SYSTEM//ATSC_FIX_C
    msAPI_ATV_GetAudioMode(E_AUDIOSOURCE_ATV, &eAudioMode);
  #endif

    msAPI_Timer_Delayms(DELAY_FOR_ENTERING_MUTE);
    SetAudioMute(E_AUDIO_INTERNAL_1_MUTEOFF, E_AUDIOMUTESOURCE_ATV);
}

/******************************************************************************/
/// API for Audio::
/// Get the result of audio standard after auto standard detection called.
/// @return the audio standard type
/******************************************************************************/
#if (TV_SYSTEM == TV_NTSC)
AUDIOSTANDARD_TYPE msAPI_AUD_GetResultOfAutoStandardDetection(void)
{
#if (AUDIO_SYSTEM_SEL == AUDIO_SYSTEM_BTSC)
    m_eAudioStandard = E_AUDIOSTANDARD_M_BTSC;
#elif (AUDIO_SYSTEM_SEL == AUDIO_SYSTEM_A2)
    m_eAudioStandard = E_AUDIOSTANDARD_M_A2;
#endif

    return m_eAudioStandard;
}
#else
AUDIOSTANDARD_TYPE msAPI_AUD_GetResultOfAutoStandardDetection(void)
{
    if(m_eAudioStandard != E_AUDIOSTANDARD_L)
    {
        m_eAudioStandard = MApi_AUDIO_SIF_GetResultOfAutoStandardDetection();

        // Get Audio Status
        MApi_AUDIO_SIF_GetAudioStatus(&m_eAudioStatus);

/*
        if( E_AUDIOSTANDARD_NOTSTANDARD == MApi_AUDIO_SIF_ConvertToBasicAudioStandard(m_eAudioStandard) )
        {
            if(m_eAudioStandard == E_AUDIOSTANDARD_NOTSTANDARD)
                m_eAudioStandard = E_AUDIOSTANDARD_BG;
        }
*/
        if ( IS_SYSTEM_L_ENABLED == TRUE )
        {
            if( E_AUDIOSTANDARD_M == MApi_AUDIO_SIF_ConvertToBasicAudioStandard(m_eAudioStandard) )
            {
                if( m_eAudioStandard == E_AUDIOSTANDARD_NOTSTANDARD ||
                    m_eAudioStandard == E_AUDIOSTANDARD_M )
                {
                #if ( ENABLE_DTMB_CHINA_APP || ENABLE_ATV_CHINA_APP )
                    m_eAudioStandard = E_AUDIOSTANDARD_DK;
                #else
                    m_eAudioStandard = E_AUDIOSTANDARD_DK;//E_AUDIOSTANDARD_BG;
                #endif
                }
            }
        }

        MApi_AUDIO_SIF_SendCmd(MSAPI_AUD_SIF_STANDARD_RESET, 0, 0);
        if( E_AUDIOSTANDARD_NOTSTANDARD == MApi_AUDIO_SIF_ConvertToBasicAudioStandard(m_eAudioStandard) )
        {
          #if ( ENABLE_DTMB_CHINA_APP || ENABLE_ATV_CHINA_APP )
            MApi_AUDIO_SIF_SetStandard(E_AUDIOSTANDARD_DK);
          #else
            MApi_AUDIO_SIF_SetStandard(E_AUDIOSTANDARD_DK);//(E_AUDIOSTANDARD_BG);
          #endif
        }
        else
            MApi_AUDIO_SIF_SetStandard(m_eAudioStandard);

    }

    return m_eAudioStandard;
}
#endif

/******************************************************************************/
/// API for Audio::
/// Get the detected TV audio mode
/// @return the audio standard type
/******************************************************************************/
void msAPI_AUD_ForceAudioMode(AUDIOMODE_TYPE eAudioMode)
{
    if( (m_eAudioSource != E_AUDIOSOURCE_ATV) || ((m_eAudioSource == E_AUDIOSOURCE_ATV) && (TRUE == msAPI_AVD_IsAutoAVActive(E_AUTOAV_SOURCE_ALL))) )
    {
        switch(eAudioMode)
        {
        case E_AUDIOMODE_LEFT_RIGHT:
            m_eAudioMode = E_AUDIOMODE_LEFT_RIGHT;
            break;

        case E_AUDIOMODE_LEFT_LEFT:
            m_eAudioMode = E_AUDIOMODE_LEFT_LEFT;
            break;

        case E_AUDIOMODE_RIGHT_RIGHT:
            m_eAudioMode = E_AUDIOMODE_RIGHT_RIGHT;
            break;

        default:
            m_eAudioMode = E_AUDIOMODE_LEFT_RIGHT;
            break;
        }
        MApi_AUDIO_SIF_SetSoundMode(m_eAudioMode);
        return;
    }

    m_eAudioMode = eAudioMode;

    m_bIsAudioModeChanged = TRUE;

    MApi_AUDIO_SIF_SetSoundMode(m_eAudioMode);
}

/******************************************************************************/
/// API for Audio::
/// Change the audio mode
/// @return the value after changing
/******************************************************************************/
AUDIOMODE_TYPE msAPI_AUD_ChangeAudioMode(void)
{
    if( (m_eAudioSource != E_AUDIOSOURCE_ATV) || ((m_eAudioSource == E_AUDIOSOURCE_ATV) && (TRUE == msAPI_AVD_IsAutoAVActive(E_AUTOAV_SOURCE_ALL))) )
    {
        switch(m_eAudioMode)
        {
        case E_AUDIOMODE_LEFT_RIGHT:
            m_eAudioMode = E_AUDIOMODE_LEFT_LEFT;
            break;

        case E_AUDIOMODE_LEFT_LEFT:
            m_eAudioMode = E_AUDIOMODE_RIGHT_RIGHT;
            break;

        case E_AUDIOMODE_RIGHT_RIGHT:
            m_eAudioMode = E_AUDIOMODE_LEFT_RIGHT;
            break;

        default:
            m_eAudioMode = E_AUDIOMODE_LEFT_RIGHT;
            break;
        }

        MApi_AUDIO_SIF_SetSoundMode(m_eAudioMode);
        return m_eAudioMode;
    }

#if (MTS_NICAM_UNSTABLE)
    g_NICAMEnable = 1;
    g_CarrierStableCnt = 0;
#endif

    switch(m_eAudioMode)
    {
    case E_AUDIOMODE_MONO:
        m_eAudioMode = E_AUDIOMODE_FORCED_MONO;
        break;

    case E_AUDIOMODE_G_STEREO:
        m_eAudioMode = E_AUDIOMODE_FORCED_MONO;
        break;

    case E_AUDIOMODE_K_STEREO:
        m_eAudioMode = E_AUDIOMODE_FORCED_MONO;
        break;

    case E_AUDIOMODE_MONO_SAP:
        m_eAudioMode = E_AUDIOMODE_FORCED_MONO;
        break;

    case E_AUDIOMODE_STEREO_SAP:
        m_eAudioMode = E_AUDIOMODE_K_STEREO;
        break;

    case E_AUDIOMODE_DUAL_A:
        m_eAudioMode = E_AUDIOMODE_DUAL_B;
        break;

    case E_AUDIOMODE_DUAL_B:
        m_eAudioMode = E_AUDIOMODE_DUAL_AB;
        break;

    case E_AUDIOMODE_DUAL_AB:
        m_eAudioMode = E_AUDIOMODE_DUAL_A;
        break;

    case E_AUDIOMODE_NICAM_MONO:
        m_eAudioMode = E_AUDIOMODE_FORCED_MONO;
        break;

    case E_AUDIOMODE_NICAM_STEREO:
        m_eAudioMode = E_AUDIOMODE_FORCED_MONO;
        break;

    case E_AUDIOMODE_NICAM_DUAL_A:
        m_eAudioMode = E_AUDIOMODE_NICAM_DUAL_B;
        break;

    case E_AUDIOMODE_NICAM_DUAL_B:
        m_eAudioMode = E_AUDIOMODE_NICAM_DUAL_AB;
        break;

    case E_AUDIOMODE_NICAM_DUAL_AB:
        m_eAudioMode = E_AUDIOMODE_FORCED_MONO;
        break;

    case E_AUDIOMODE_FORCED_MONO:
        m_eAudioMode = (AUDIOMODE_TYPE)MApi_AUDIO_SIF_GetSoundMode();
        if( m_eAudioMode == E_AUDIOMODE_INVALID )
        {
            m_eAudioMode = E_AUDIOMODE_FORCED_MONO;
            return m_eAudioMode;
        }
        break;

    default:
        m_eAudioMode = E_AUDIOMODE_MONO;
        break;
    }

    printf("\n***Hisense m_eAudioMode =%d\n",m_eAudioMode);
    SetAudioMute(E_AUDIO_INTERNAL_1_MUTEON, E_AUDIOMUTESOURCE_ATV);
    MApi_AUDIO_SIF_SetSoundMode(m_eAudioMode);
    msAPI_Timer_Delayms(DELAY_FOR_ENTERING_MUTE);
    SetAudioMute(E_AUDIO_INTERNAL_1_MUTEOFF, E_AUDIOMUTESOURCE_ATV);

    return m_eAudioMode;
}

/******************************************************************************/
/// API for Audio::
/// Check audio mode changed or not
/// @return true and false
/******************************************************************************/
BOOLEAN msAPI_AUD_IsAudioModeChanged(void)
{
    if ( m_bIsAudioModeChanged == FALSE )
        return FALSE;

    m_bIsAudioModeChanged = FALSE;

    return TRUE;
}

/******************************************************************************/
/// API for Audio::
/// Check audio standard
/******************************************************************************/
#ifndef ATSC_SYSTEM
#if (ENABLE_SBTVD_BRAZIL_APP)
static void CheckATVAudioMode_Brazil(void)
{
    AUDIOMODE_TYPE eDetectedAudioMode;
    EN_DUAL_AUDIO_SELECTION eSaveAudioMode;

    eDetectedAudioMode = (AUDIOMODE_TYPE)MApi_AUDIO_SIF_GetSoundMode();

    if( eDetectedAudioMode == E_AUDIOMODE_INVALID )
        return;

    if( (m_eAudioMode == eDetectedAudioMode&&!bForceCheckAudioMode )||
        (m_eAudioMode == eDetectedAudioMode&&eDetectedAudioMode==E_AUDIOMODE_K_STEREO))
        return;

    if( ((m_eAudioMode == E_AUDIOMODE_DUAL_A) || (m_eAudioMode == E_AUDIOMODE_DUAL_B) || (m_eAudioMode == E_AUDIOMODE_DUAL_AB)) &&
        ((eDetectedAudioMode == E_AUDIOMODE_DUAL_A) || (eDetectedAudioMode == E_AUDIOMODE_DUAL_B) || (eDetectedAudioMode == E_AUDIOMODE_DUAL_AB)) )
    {
        return;
    }

  #if 1
    if(bForceCheckAudioMode)
    {
      //  printf("\r\n m_eAudioMode=%bu",m_eAudioMode);
       // printf("\r\n eDetectedAudioMode=%bu",eDetectedAudioMode);
        if(eDetectedAudioMode==E_AUDIOMODE_MONO_SAP)
        {
            printf("\r\n Mono Sap to Mono");
            eDetectedAudioMode=E_AUDIOMODE_FORCED_MONO;
        }
        else if(eDetectedAudioMode==E_AUDIOMODE_STEREO_SAP)
        {
            printf("\r\n Stereo Sap  to Stereo");
            eDetectedAudioMode=E_AUDIOMODE_K_STEREO;
        }
        else if(m_eAudioMode==E_AUDIOMODE_FORCED_MONO&&eDetectedAudioMode==E_AUDIOMODE_STEREO_SAP)
        {
            printf("\r\n Force Mono to Stereo");
            eDetectedAudioMode=E_AUDIOMODE_K_STEREO;
        }
        bForceCheckAudioMode=FALSE;
    }
    else
    {
        if((m_eAudioMode == E_AUDIOMODE_FORCED_MONO||m_eAudioMode == E_AUDIOMODE_K_STEREO||m_eAudioMode == E_AUDIOMODE_STEREO_SAP||m_eAudioMode==E_AUDIOMODE_MONO)&&
      (eDetectedAudioMode == E_AUDIOMODE_FORCED_MONO||eDetectedAudioMode == E_AUDIOMODE_K_STEREO||eDetectedAudioMode == E_AUDIOMODE_STEREO_SAP||eDetectedAudioMode == E_AUDIOMODE_MONO_SAP))
        {
            return;
        }
    }
  #endif

    if( ((m_eAudioMode == E_AUDIOMODE_NICAM_DUAL_A) || (m_eAudioMode == E_AUDIOMODE_NICAM_DUAL_B) || (m_eAudioMode == E_AUDIOMODE_NICAM_DUAL_AB)) &&
        ((eDetectedAudioMode == E_AUDIOMODE_NICAM_DUAL_A) || (eDetectedAudioMode == E_AUDIOMODE_NICAM_DUAL_B) || (eDetectedAudioMode == E_AUDIOMODE_NICAM_DUAL_AB)) )
    {
        return;
    }

  #if 0
    if( m_eAudioMode == E_AUDIOMODE_FORCED_MONO && eDetectedAudioMode != E_AUDIOMODE_DUAL_A )
    {
        return;
    }
  #endif

  #if 0
    if( (eDetectedAudioMode == E_AUDIOMODE_DUAL_A) || (eDetectedAudioMode == E_AUDIOMODE_NICAM_DUAL_A) )
    {
        printf("msAPI_ATV_WasForeignLanguageSelected=%bd\n",msAPI_ATV_WasForeignLanguageSelected());

        if( TRUE == msAPI_ATV_WasForeignLanguageSelected() )
        {
            printf("eDetectedAudioMode2=%bd,%bd\n",eDetectedAudioMode,E_AUDIOMODE_DUAL_A);

            eDetectedAudioMode = (eDetectedAudioMode == E_AUDIOMODE_DUAL_A) ? E_AUDIOMODE_DUAL_B : E_AUDIOMODE_NICAM_DUAL_B;
        }
    }
  #endif

    if( (eDetectedAudioMode == E_AUDIOMODE_DUAL_A) || (eDetectedAudioMode == E_AUDIOMODE_NICAM_DUAL_A) )
    {
        eSaveAudioMode = (EN_DUAL_AUDIO_SELECTION)msAPI_ATV_GetDualAudioSelected();
        if(eSaveAudioMode == E_DUAL_AUDIO_A)
        {
            eDetectedAudioMode = (eDetectedAudioMode == E_AUDIOMODE_DUAL_A) ? E_AUDIOMODE_DUAL_A : E_AUDIOMODE_NICAM_DUAL_A;
        }
        else if(eSaveAudioMode == E_DUAL_AUDIO_B)
        {
            eDetectedAudioMode = (eDetectedAudioMode == E_AUDIOMODE_DUAL_A) ? E_AUDIOMODE_DUAL_B : E_AUDIOMODE_NICAM_DUAL_B;
        }
        else //E_DUAL_AUDIO_AB
        {
            eDetectedAudioMode = (eDetectedAudioMode == E_AUDIOMODE_DUAL_A) ? E_AUDIOMODE_DUAL_AB : E_AUDIOMODE_NICAM_DUAL_AB;
        }
    }

  #ifndef ATSC_SYSTEM//ATSC_FIX_C
    if( TRUE == msAPI_Tuner_IsCurrentChannelAndSavedChannelSame() )
    {
        msAPI_ATV_SetAudioMode(E_AUDIOSOURCE_ATV, eDetectedAudioMode);
    }
  #endif

    if(m_eAudioMode==eDetectedAudioMode)
        return ;

    m_eAudioMode = eDetectedAudioMode;

    m_bIsAudioModeChanged = TRUE;

    SetAudioMute(E_AUDIO_INTERNAL_1_MUTEON,E_AUDIOMUTESOURCE_ATV);
    MsOS_DelayTask(DELAY_FOR_ENTERING_MUTE);
    MApi_AUDIO_SIF_SetSoundMode(m_eAudioMode);
    MsOS_DelayTask(DELAY_FOR_LEAVING_MUTE);
    SetAudioMute(E_AUDIO_INTERNAL_1_MUTEOFF,E_AUDIOMUTESOURCE_ATV);

  #if 1//def ZUI
    //ZUI_TODO:
  #else
    MApp_UiMenu_UpdateAudioModeUI();
  #endif
}
#endif

#define DEBUG_CHECK_AUD_STD(x)  //x
static void CheckAudioStandard(void)
{
    AUDIOSTATUS eCurrentAudioStatus;

  #if(AUDIO_SYSTEM_SEL == AUDIO_SYSTEM_BTSC)
    return;
  #endif

  #if (ENABLE_SBTVD_BRAZIL_APP==0)
    MS_BOOL AudioStatusIsA2 = FALSE;
    MS_U8 max_a2_mode_invalid_cnt = 0x20;
  #endif


    if( (m_eAudioSource != E_AUDIOSOURCE_ATV) || ((m_eAudioSource == E_AUDIOSOURCE_ATV) && (msAPI_AVD_IsAutoAVActive(E_AUTOAV_SOURCE_ALL) == TRUE)) )
        return;

#if (ENABLE_SBTVD_BRAZIL_APP)
{
    BYTE ucValue;
    static BYTE PreucVaue;

    m_eAudioStandard = E_AUDIOSTANDARD_M_BTSC;

    CheckATVAudioMode_Brazil(); //just for remove make warning

    ucValue = MApi_AUDIO_SIF_GetSoundMode();
    if(PreucVaue != ucValue)
    {
        PreucVaue = ucValue;
        printf("GetSoundMode=%d\n",ucValue);
        return;
    }

    eCurrentAudioStatus = E_STATE_AUDIO_NO_CARRIER;

    if(ucValue & 0x01)
        eCurrentAudioStatus |= E_STATE_AUDIO_PRIMARY_CARRIER;
    if(ucValue & 0x02)
        eCurrentAudioStatus |= E_STATE_AUDIO_STEREO;
    if(ucValue & 0x04)
        eCurrentAudioStatus |= E_STATE_AUDIO_BILINGUAL;

    if( m_eAudioStatus != eCurrentAudioStatus )
    {
        m_eAudioStatus = eCurrentAudioStatus;
    }
}
#else

    if( TRUE != MApi_AUDIO_SIF_GetAudioStatus(&eCurrentAudioStatus) )
        return;

    CheckATVAudioMode(); //just for remove make warning

    if( m_eAudioStatus != eCurrentAudioStatus )
    {
        m_eAudioStatus = eCurrentAudioStatus;
        msAPI_Timer_Delayms(5);

        if( TRUE != MApi_AUDIO_SIF_GetAudioStatus(&eCurrentAudioStatus) )
            return;

        if( m_eAudioStatus != eCurrentAudioStatus )     //Check twice for speed up detection, C.P.Chen 2007/12/06
        {
            m_eAudioStatus = eCurrentAudioStatus;
            return;
        }
    }

    if (g_A2ModeInvalidCnt >= max_a2_mode_invalid_cnt)
    {
        if( ((m_eAudioStatus & (E_STATE_AUDIO_PRIMARY_CARRIER|E_STATE_AUDIO_PILOT)) == (E_STATE_AUDIO_PRIMARY_CARRIER|E_STATE_AUDIO_PILOT))
           && ((m_eAudioStatus & E_STATE_AUDIO_STEREO) || (m_eAudioStatus & E_STATE_AUDIO_BILINGUAL)))
            AudioStatusIsA2 = TRUE;
    }
    else
    {
        if( (m_eAudioStatus & (E_STATE_AUDIO_PRIMARY_CARRIER|E_STATE_AUDIO_PILOT)) == (E_STATE_AUDIO_PRIMARY_CARRIER|E_STATE_AUDIO_PILOT) )
            AudioStatusIsA2 = TRUE;
    }

  #if (TV_SYSTEM == TV_PAL)

    if( m_eAudioStandard == E_AUDIOSTANDARD_L)    // need touch.
    {
        if( ((m_eAudioStatus & (E_STATE_AUDIO_PRIMARY_CARRIER|E_STATE_AUDIO_NICAM)) == (E_STATE_AUDIO_PRIMARY_CARRIER|E_STATE_AUDIO_NICAM)) ||
            ((m_eAudioStatus & E_STATE_AUDIO_PRIMARY_CARRIER) == E_STATE_AUDIO_PRIMARY_CARRIER) )
        {
            CheckATVAudioMode();
        }
        return;
    }

    if( (m_eAudioStatus & (E_STATE_AUDIO_PRIMARY_CARRIER|E_STATE_AUDIO_NICAM)) == (E_STATE_AUDIO_PRIMARY_CARRIER|E_STATE_AUDIO_NICAM) )
    {
        g_A2ModeInvalidCnt = 0;
        #if (MTS_NICAM_UNSTABLE)
        if(g_NICAMEnable == 0)
            {
            return;
            }
        #endif

        if( FALSE == MApi_AUDIO_SIF_IsPALType(AU_SIF_PAL_NICAM) )
        {
            switch(m_eAudioStandard)
            {
            case E_AUDIOSTANDARD_BG:
            case E_AUDIOSTANDARD_BG_A2:
                m_eAudioStandard = E_AUDIOSTANDARD_BG_NICAM;
                break;
            case E_AUDIOSTANDARD_DK:
            case E_AUDIOSTANDARD_DK1_A2:
                m_eAudioStandard = E_AUDIOSTANDARD_DK_NICAM;
                break;
            default:
                break;
            }
            //SetAudioMuteDuringLimitedTime(500, E_AUDIOMUTESOURCE_ACTIVESOURCE); //C.P.Chen 2007/12/06
            MApi_AUDIO_SIF_SetPALType(AU_SIF_PAL_NICAM);
            MApi_AUDIO_SIF_SetStandard(m_eAudioStandard);
            DEBUG_CHECK_AUD_STD(printf("Aud_set_std(0x%X)\n", m_eAudioStandard););

            // We do not want to change audio standard of eeprom when one channel search is running or manual change.
            //if( TRUE == msAPI_Tuner_IsCurrentChannelAndSavedChannelSame() )
            //{
            //    PRINT_CURRENT_LINE();
            //    msAPI_ATV_SetAudioStandard(msAPI_ATV_GetCurrentProgramNumber(), m_eAudioStandard);
            //}

            m_wAudioDownCountTimer = (5);
            return;
        }

        CheckATVAudioMode();
    }
    else if(AudioStatusIsA2 == TRUE)
    {   //Reload A2 while Pilot detected. C.P.Chen
        if( FALSE == MApi_AUDIO_SIF_IsPALType(AU_SIF_PAL_A2) )
        {
            if((m_eAudioStatus&E_STATE_AUDIO_DK2) == E_STATE_AUDIO_DK2)
                m_eAudioStandard = E_AUDIOSTANDARD_DK2_A2;
            else if((m_eAudioStatus&E_STATE_AUDIO_DK3) == E_STATE_AUDIO_DK3)
                m_eAudioStandard = E_AUDIOSTANDARD_DK3_A2;

            MApi_AUDIO_SIF_SetStandard(m_eAudioStandard);
            DEBUG_CHECK_AUD_STD(printf("Aud_set_std(0x%X)\n", m_eAudioStandard););
            //SetAudioMuteDuringLimitedTime(800, E_AUDIOMUTESOURCE_ACTIVESOURCE);  //C.P.Chen 2007/12/06
            g_A2ModeInvalidCnt = 0;
            MApi_AUDIO_SIF_SetPALType(AU_SIF_PAL_A2);

            // We do not want to change audio standard of eeprom when one channel search is running or manual change.
            //if( TRUE == msAPI_Tuner_IsCurrentChannelAndSavedChannelSame() )
            //{
            //    PRINT_CURRENT_LINE();
            //  msAPI_ATV_SetAudioStandard(msAPI_ATV_GetCurrentProgramNumber(), m_eAudioStandard);
            //}
            m_wAudioDownCountTimer = (5);
            return;
        }
        else if((m_eAudioStatus & (E_STATE_AUDIO_STEREO|E_STATE_AUDIO_BILINGUAL)) == 0 )
        {
            g_A2ModeInvalidCnt++;
        }
        else // STEREO or DUAL exist
        {
            g_A2ModeInvalidCnt = 0;
        }

        CheckATVAudioMode();
    }
    else if( (m_eAudioStatus & E_STATE_AUDIO_PRIMARY_CARRIER) == E_STATE_AUDIO_PRIMARY_CARRIER )
    {

        CheckATVAudioMode();

        msAPI_Tuner_UpdateMediumAndChannelNumber();

        #if (MTS_NICAM_UNSTABLE)
        if( TRUE == MApi_AUDIO_SIF_IsPALType(AU_SIF_PAL_NICAM) )
            {
            if (g_CarrierStableCnt <= 30)
                {
                g_CarrierStableCnt++;
                return;
                }
            g_CarrierStableCnt = 0;
            g_NICAMEnable = 0;
            }
        #endif

        switch(m_eAudioStandard)
        {
        case E_AUDIOSTANDARD_BG_NICAM:
            MApi_AUDIO_SIF_SetStandard(E_AUDIOSTANDARD_BG_A2);
            m_eAudioStandard = E_AUDIOSTANDARD_BG_A2;
            break;
        case E_AUDIOSTANDARD_DK_NICAM:
            MApi_AUDIO_SIF_SetStandard(E_AUDIOSTANDARD_DK1_A2);
            m_eAudioStandard = E_AUDIOSTANDARD_DK1_A2;
            break;
        default:
            break;
        }

        if( FALSE == MApi_AUDIO_SIF_IsPALType(AU_SIF_PAL_MONO) )
        {
            //SetAudioMuteDuringLimitedTime(100, E_AUDIOMUTESOURCE_ACTIVESOURCE); //C.P.Chen 2007/12/06
            MApi_AUDIO_SIF_SetPALType(AU_SIF_PAL_MONO);

            // We do not want to change audio standard of eeprom when one channel search is running or manual change.
            //if( TRUE == msAPI_Tuner_IsCurrentChannelAndSavedChannelSame() )
            //{
            //    PRINT_CURRENT_LINE();
            //    msAPI_ATV_SetAudioStandard(msAPI_ATV_GetCurrentProgramNumber(), MApi_AUDIO_SIF_ConvertToBasicAudioStandard(m_eAudioStandard));
            //}
        }
    }
    else
    {
    #if 0
        if( TRUE == m_bIsRealtimeAudioDetectionEnabled )
        {
            if( FALSE == MApi_AUDIO_SIF_IsPALType(AU_SIF_PAL_MONO) )
            {
                SetAudioMuteDuringLimitedTime(150, E_AUDIOMUTESOURCE_ACTIVESOURCE); //C.P.Chen 2007/12/06
                MApi_AUDIO_SIF_SetPALType(AU_SIF_PAL_MONO);
            }

            switch( MApi_AUDIO_SIF_ConvertToBasicAudioStandard(m_eAudioStandard) )
            {
            case E_AUDIOSTANDARD_BG:
                m_eAudioStandard = E_AUDIOSTANDARD_I;
                break;
            case E_AUDIOSTANDARD_I:
                m_eAudioStandard = E_AUDIOSTANDARD_DK;
                break;
            case E_AUDIOSTANDARD_DK:
                if ( IS_SYSTEM_L_ENABLED == TRUE )
                {
                    m_eAudioStandard = E_AUDIOSTANDARD_BG;
                }
                else
                {
                    if( TRUE == IsVideoStandard60Hz(msAPI_AVD_GetVideoStandard()) )
                        m_eAudioStandard = E_AUDIOSTANDARD_M;
                    else
                        m_eAudioStandard = E_AUDIOSTANDARD_BG;
                }
                break;
            case E_AUDIOSTANDARD_M:
                m_eAudioStandard = E_AUDIOSTANDARD_BG;
                break;
            default:
                m_eAudioStandard = E_AUDIOSTANDARD_BG;
                break;
            }
            MApi_AUDIO_SIF_SetStandard(m_eAudioStandard);
            msAPI_Tuner_SetIF();
        }
    #endif
    }
  #endif
#endif
}


#if ENABLE_ATV_AUDIOCHECK_IN_OTHER_SRC

#if (ENABLE_SBTVD_BRAZIL_APP==0)
static void CheckATVAudioMode_OtherSource(void)
{
    AUDIOMODE_TYPE eDetectedAudioMode, m_eAudioMode_ATV;
    EN_DUAL_AUDIO_SELECTION eSaveAudioMode;


    msAPI_ATV_GetAudioMode(E_AUDIOSOURCE_ATV, &m_eAudioMode_ATV);

    if( TRUE == MApi_AUDIO_SIF_IsPALType(AU_SIF_PAL_MONO) )
    {
        eDetectedAudioMode = E_AUDIOMODE_MONO;
    }
    else
    {
        eDetectedAudioMode = (AUDIOMODE_TYPE)MApi_AUDIO_SIF_GetSoundMode();
    }

    if( eDetectedAudioMode == E_AUDIOMODE_INVALID )
        return;

    if( m_eAudioMode_ATV == eDetectedAudioMode )
    {
        MApi_AUDIO_SIF_SetSoundMode(m_eAudioMode_ATV);
        return;
    }

    if( ((m_eAudioMode_ATV == E_AUDIOMODE_DUAL_A) || (m_eAudioMode_ATV == E_AUDIOMODE_DUAL_B) || (m_eAudioMode_ATV == E_AUDIOMODE_DUAL_AB)) &&
        ((eDetectedAudioMode == E_AUDIOMODE_DUAL_A) || (eDetectedAudioMode == E_AUDIOMODE_DUAL_B) || (eDetectedAudioMode == E_AUDIOMODE_DUAL_AB)) )
    {
        MApi_AUDIO_SIF_SetSoundMode(m_eAudioMode_ATV);
        return;
    }

    if( ((m_eAudioMode_ATV == E_AUDIOMODE_NICAM_DUAL_A) || (m_eAudioMode_ATV == E_AUDIOMODE_NICAM_DUAL_B) || (m_eAudioMode_ATV == E_AUDIOMODE_NICAM_DUAL_AB)) &&
        ((eDetectedAudioMode == E_AUDIOMODE_NICAM_DUAL_A) || (eDetectedAudioMode == E_AUDIOMODE_NICAM_DUAL_B) || (eDetectedAudioMode == E_AUDIOMODE_NICAM_DUAL_AB)) )
    {
        MApi_AUDIO_SIF_SetSoundMode(m_eAudioMode_ATV);
        return;
    }

    if( m_eAudioMode_ATV == E_AUDIOMODE_FORCED_MONO && eDetectedAudioMode != E_AUDIOMODE_DUAL_A )
    {
        MApi_AUDIO_SIF_SetSoundMode(m_eAudioMode_ATV);
        return;
    }

    if( (eDetectedAudioMode == E_AUDIOMODE_DUAL_A) || (eDetectedAudioMode == E_AUDIOMODE_NICAM_DUAL_A) )
    {
        eSaveAudioMode = (EN_DUAL_AUDIO_SELECTION)msAPI_ATV_GetDualAudioSelected();
        if(eSaveAudioMode == E_DUAL_AUDIO_A)
        {
            eDetectedAudioMode = (eDetectedAudioMode == E_AUDIOMODE_DUAL_A) ? E_AUDIOMODE_DUAL_A : E_AUDIOMODE_NICAM_DUAL_A;
        }
        else if(eSaveAudioMode == E_DUAL_AUDIO_B)
        {
            eDetectedAudioMode = (eDetectedAudioMode == E_AUDIOMODE_DUAL_A) ? E_AUDIOMODE_DUAL_B : E_AUDIOMODE_NICAM_DUAL_B;
        }
        else //E_DUAL_AUDIO_AB
        {
            eDetectedAudioMode = (eDetectedAudioMode == E_AUDIOMODE_DUAL_A) ? E_AUDIOMODE_DUAL_AB : E_AUDIOMODE_NICAM_DUAL_AB;
        }
    }

    //if( TRUE == msAPI_Tuner_IsCurrentChannelAndSavedChannelSame() )
    //{
    //    msAPI_ATV_SetAudioMode(E_AUDIOSOURCE_ATV, eDetectedAudioMode);
    //}

    m_eAudioMode_ATV = eDetectedAudioMode;

    m_bIsAudioModeChanged = TRUE;

    MApi_AUDIO_SIF_SetSoundMode(m_eAudioMode_ATV);
}
#endif

//for CheckAudioStandard in other source except DTV and ATV.
static void CheckAudioStandard_OtherSource(void)
{
    AUDIOSTATUS eCurrentAudioStatus;
#if (ENABLE_SBTVD_BRAZIL_APP==0)
    MS_BOOL AudioStatusIsA2 = FALSE;
    MS_U8 max_a2_mode_invalid_cnt = 0x20;
#endif
    if(m_eAudioSource == E_AUDIOSOURCE_ATV)
        return;
//    printf("Into CheckAudioStandard_OtherSource\n");

  #if (ENABLE_SBTVD_BRAZIL_APP)
    {
        BYTE ucValue;
        static BYTE PreucVaue;

        m_eAudioStandard = E_AUDIOSTANDARD_M_BTSC;

        CheckATVAudioMode_Brazil(); //just for remove make warning

        ucValue = MApi_AUDIO_SIF_GetSoundMode();
        if(PreucVaue != ucValue)
        {
            PreucVaue = ucValue;
            //printf("GetSoundMode=%d\n",ucValue);
            return;
        }

        eCurrentAudioStatus = E_STATE_AUDIO_NO_CARRIER;

        if(ucValue & 0x01)
            eCurrentAudioStatus |= E_STATE_AUDIO_PRIMARY_CARRIER;
        if(ucValue & 0x02)
            eCurrentAudioStatus |= E_STATE_AUDIO_STEREO;
        if(ucValue & 0x04)
            eCurrentAudioStatus |= E_STATE_AUDIO_BILINGUAL;

        if( m_eAudioStatus != eCurrentAudioStatus )
        {
            m_eAudioStatus = eCurrentAudioStatus;
        }
    }
  #else // #if (ENABLE_SBTVD_BRAZIL_APP)
    {
        if( TRUE != MApi_AUDIO_SIF_GetAudioStatus(&eCurrentAudioStatus) )
            return;

        CheckATVAudioMode_OtherSource(); //just for remove make warning

        if( m_eAudioStatus != eCurrentAudioStatus )
        {
            m_eAudioStatus = eCurrentAudioStatus;
            msAPI_Timer_Delayms(5);

            if( TRUE != MApi_AUDIO_SIF_GetAudioStatus(&eCurrentAudioStatus) )
                return;

            if( m_eAudioStatus != eCurrentAudioStatus )     //Check twice for speed up detection, C.P.Chen 2007/12/06
            {
                m_eAudioStatus = eCurrentAudioStatus;
                return;
            }
        }

        if (g_A2ModeInvalidCnt >= max_a2_mode_invalid_cnt)
        {
            if( ((m_eAudioStatus & (E_STATE_AUDIO_PRIMARY_CARRIER|E_STATE_AUDIO_PILOT)) == (E_STATE_AUDIO_PRIMARY_CARRIER|E_STATE_AUDIO_PILOT))
               && ((m_eAudioStatus & E_STATE_AUDIO_STEREO) || (m_eAudioStatus & E_STATE_AUDIO_BILINGUAL)))
                AudioStatusIsA2 = TRUE;
        }
        else
        {
            if( (m_eAudioStatus & (E_STATE_AUDIO_PRIMARY_CARRIER|E_STATE_AUDIO_PILOT)) == (E_STATE_AUDIO_PRIMARY_CARRIER|E_STATE_AUDIO_PILOT) )
                AudioStatusIsA2 = TRUE;
        }

    #if (TV_SYSTEM == TV_PAL)

        if( m_eAudioStandard == E_AUDIOSTANDARD_L)    // need touch.
        {
            if( ((m_eAudioStatus & (E_STATE_AUDIO_PRIMARY_CARRIER|E_STATE_AUDIO_NICAM)) == (E_STATE_AUDIO_PRIMARY_CARRIER|E_STATE_AUDIO_NICAM)) ||
                ((m_eAudioStatus & E_STATE_AUDIO_PRIMARY_CARRIER) == E_STATE_AUDIO_PRIMARY_CARRIER) )
            {
                CheckATVAudioMode_OtherSource();
            }
            return;
        }

        if( (m_eAudioStatus & (E_STATE_AUDIO_PRIMARY_CARRIER|E_STATE_AUDIO_NICAM)) == (E_STATE_AUDIO_PRIMARY_CARRIER|E_STATE_AUDIO_NICAM) )
        {
            g_A2ModeInvalidCnt = 0;
        #if (MTS_NICAM_UNSTABLE)
            if(g_NICAMEnable == 0)
            {
                return;
            }
        #endif

            if( FALSE == MApi_AUDIO_SIF_IsPALType(AU_SIF_PAL_NICAM) )
            {
                switch(m_eAudioStandard)
                {
                    case E_AUDIOSTANDARD_BG:
                    case E_AUDIOSTANDARD_BG_A2:
                        m_eAudioStandard = E_AUDIOSTANDARD_BG_NICAM;
                        break;
                    case E_AUDIOSTANDARD_DK:
                    case E_AUDIOSTANDARD_DK1_A2:
                        m_eAudioStandard = E_AUDIOSTANDARD_DK_NICAM;
                        break;
                    default:
                        break;
                }
                //SetAudioMuteDuringLimitedTime(500, E_AUDIOMUTESOURCE_ACTIVESOURCE); //C.P.Chen 2007/12/06
                MApi_AUDIO_SIF_SetPALType(AU_SIF_PAL_NICAM);
                MApi_AUDIO_SIF_SetStandard(m_eAudioStandard);
                DEBUG_CHECK_AUD_STD(printf("Aud_set_std(0x%X)\n", m_eAudioStandard););

                // We do not want to change audio standard of eeprom when one channel search is running or manual change.
                //if( TRUE == msAPI_Tuner_IsCurrentChannelAndSavedChannelSame() )
                //{
                //    PRINT_CURRENT_LINE();
                //    msAPI_ATV_SetAudioStandard(msAPI_ATV_GetCurrentProgramNumber(), m_eAudioStandard);
                //}

                m_wAtvAudioCheckCount = (5);
                return;
            }

            CheckATVAudioMode_OtherSource();
        }
        else if(AudioStatusIsA2 == TRUE)
        {   //Reload A2 while Pilot detected. C.P.Chen
            if( FALSE == MApi_AUDIO_SIF_IsPALType(AU_SIF_PAL_A2) )
            {
                if((m_eAudioStatus&E_STATE_AUDIO_DK2) == E_STATE_AUDIO_DK2)
                    m_eAudioStandard = E_AUDIOSTANDARD_DK2_A2;
                else if((m_eAudioStatus&E_STATE_AUDIO_DK3) == E_STATE_AUDIO_DK3)
                    m_eAudioStandard = E_AUDIOSTANDARD_DK3_A2;

                MApi_AUDIO_SIF_SetStandard(m_eAudioStandard);
                //SetAudioMuteDuringLimitedTime(800, E_AUDIOMUTESOURCE_ACTIVESOURCE);  //C.P.Chen 2007/12/06
                g_A2ModeInvalidCnt = 0;
                MApi_AUDIO_SIF_SetPALType(AU_SIF_PAL_A2);

                // We do not want to change audio standard of eeprom when one channel search is running or manual change.
                //if( TRUE == msAPI_Tuner_IsCurrentChannelAndSavedChannelSame() )
                //{
                //    PRINT_CURRENT_LINE();
                //    msAPI_ATV_SetAudioStandard(msAPI_ATV_GetCurrentProgramNumber(), m_eAudioStandard);
                //}

                m_wAtvAudioCheckCount = (5);
                return;
            }
            else if((m_eAudioStatus & (E_STATE_AUDIO_STEREO|E_STATE_AUDIO_BILINGUAL)) == 0 )
            {
                g_A2ModeInvalidCnt++;
            }
            else // STEREO or DUAL exist
            {
                g_A2ModeInvalidCnt = 0;
            }

            CheckATVAudioMode_OtherSource();
        }
        else if( (m_eAudioStatus & E_STATE_AUDIO_PRIMARY_CARRIER) == E_STATE_AUDIO_PRIMARY_CARRIER )
        {

            CheckATVAudioMode_OtherSource();

            msAPI_Tuner_UpdateMediumAndChannelNumber();

        #if (MTS_NICAM_UNSTABLE)
            if( TRUE == MApi_AUDIO_SIF_IsPALType(AU_SIF_PAL_NICAM) )
            {
                if (g_CarrierStableCnt <= 30)
                {
                    g_CarrierStableCnt++;
                    return;
                }
                g_CarrierStableCnt = 0;
                g_NICAMEnable = 0;
            }
        #endif

            switch(m_eAudioStandard)
            {
                case E_AUDIOSTANDARD_BG_NICAM:
                    MApi_AUDIO_SIF_SetStandard(E_AUDIOSTANDARD_BG_A2);
                    m_eAudioStandard = E_AUDIOSTANDARD_BG_A2;
                    break;
                case E_AUDIOSTANDARD_DK_NICAM:
                    MApi_AUDIO_SIF_SetStandard(E_AUDIOSTANDARD_DK1_A2);
                    m_eAudioStandard = E_AUDIOSTANDARD_DK1_A2;
                    break;
                default:
                    break;
            }

            if( FALSE == MApi_AUDIO_SIF_IsPALType(AU_SIF_PAL_MONO) )
            {
                //SetAudioMuteDuringLimitedTime(100, E_AUDIOMUTESOURCE_ACTIVESOURCE); //C.P.Chen 2007/12/06
                MApi_AUDIO_SIF_SetPALType(AU_SIF_PAL_MONO);

                // We do not want to change audio standard of eeprom when one channel search is running or manual change.
                //if( TRUE == msAPI_Tuner_IsCurrentChannelAndSavedChannelSame() )
                //{
                //    PRINT_CURRENT_LINE();
                //    msAPI_ATV_SetAudioStandard(msAPI_ATV_GetCurrentProgramNumber(), MApi_AUDIO_SIF_ConvertToBasicAudioStandard(m_eAudioStandard));
                //}
            }
        }
        else
        {
        }
    #endif // #if (TV_SYSTEM == TV_PAL)
    }
  #endif // #if (ENABLE_SBTVD_BRAZIL_APP)
}
#endif
#endif

/******************************************************************************/
/// API for Audio::
/// Check ATV audio mode
/******************************************************************************/
#ifndef ATSC_SYSTEM
#if (ENABLE_SBTVD_BRAZIL_APP==0)
#define DEBUG_AUD_MODE(x)   //x

static void CheckATVAudioMode(void)
{
    static U32 _s_u32TaskLastTime = 0;
    AUDIOMODE_TYPE eDetectedAudioMode;
    EN_DUAL_AUDIO_SELECTION eSaveAudioMode;

#if (ENABLE_SBTVD_BRAZIL_APP)
    eDetectedAudioMode = E_AUDIOMODE_INVALID;
    return; //just for remove make warning
#endif


    if( msAPI_Timer_DiffTime_2(_s_u32TaskLastTime, MsOS_GetSystemTime()) < 50 )
        return;

    _s_u32TaskLastTime = MsOS_GetSystemTime();

    DEBUG_AUD_MODE(printf("CheckATVAudioMode() at %u\n", MsOS_GetSystemTime()););

    if( TRUE == MApi_AUDIO_SIF_IsPALType(AU_SIF_PAL_MONO) )
    {
        eDetectedAudioMode = E_AUDIOMODE_MONO;
    }
    else
    {
        eDetectedAudioMode = (AUDIOMODE_TYPE)MApi_AUDIO_SIF_GetSoundMode();
        DEBUG_AUD_MODE(printf(" eDetectedAudioMode=0x%X\n", eDetectedAudioMode););
    }

    if( eDetectedAudioMode == E_AUDIOMODE_INVALID )
        return;

    DEBUG_AUD_MODE(printf(" m_eAudioMode=0x%X\n", m_eAudioMode););

    if( m_eAudioMode == eDetectedAudioMode )
    {
        MApi_AUDIO_SIF_SetSoundMode(m_eAudioMode);
        return;
    }

    if( ((m_eAudioMode == E_AUDIOMODE_DUAL_A) || (m_eAudioMode == E_AUDIOMODE_DUAL_B) || (m_eAudioMode == E_AUDIOMODE_DUAL_AB)) &&
        ((eDetectedAudioMode == E_AUDIOMODE_DUAL_A) || (eDetectedAudioMode == E_AUDIOMODE_DUAL_B) || (eDetectedAudioMode == E_AUDIOMODE_DUAL_AB)) )
    {
        MApi_AUDIO_SIF_SetSoundMode(m_eAudioMode);
        return;
    }

    if( ((m_eAudioMode == E_AUDIOMODE_NICAM_DUAL_A) || (m_eAudioMode == E_AUDIOMODE_NICAM_DUAL_B) || (m_eAudioMode == E_AUDIOMODE_NICAM_DUAL_AB)) &&
        ((eDetectedAudioMode == E_AUDIOMODE_NICAM_DUAL_A) || (eDetectedAudioMode == E_AUDIOMODE_NICAM_DUAL_B) || (eDetectedAudioMode == E_AUDIOMODE_NICAM_DUAL_AB)) )
    {
        MApi_AUDIO_SIF_SetSoundMode(m_eAudioMode);
        return;
    }

    if( m_eAudioMode == E_AUDIOMODE_FORCED_MONO && eDetectedAudioMode != E_AUDIOMODE_DUAL_A )
    {
        MApi_AUDIO_SIF_SetSoundMode(m_eAudioMode);
        return;
    }

    if( (eDetectedAudioMode == E_AUDIOMODE_DUAL_A) || (eDetectedAudioMode == E_AUDIOMODE_NICAM_DUAL_A) )
    {
        eSaveAudioMode = (EN_DUAL_AUDIO_SELECTION)msAPI_ATV_GetDualAudioSelected();
        if(eSaveAudioMode == E_DUAL_AUDIO_A)
        {
            eDetectedAudioMode = (eDetectedAudioMode == E_AUDIOMODE_DUAL_A) ? E_AUDIOMODE_DUAL_A : E_AUDIOMODE_NICAM_DUAL_A;
        }
        else if(eSaveAudioMode == E_DUAL_AUDIO_B)
        {
            eDetectedAudioMode = (eDetectedAudioMode == E_AUDIOMODE_DUAL_A) ? E_AUDIOMODE_DUAL_B : E_AUDIOMODE_NICAM_DUAL_B;
        }
        else //E_DUAL_AUDIO_AB
        {
            eDetectedAudioMode = (eDetectedAudioMode == E_AUDIOMODE_DUAL_A) ? E_AUDIOMODE_DUAL_AB : E_AUDIOMODE_NICAM_DUAL_AB;
        }
    }

/* this will cause write flash many times,
    if( TRUE == msAPI_Tuner_IsCurrentChannelAndSavedChannelSame() )
    {
        PRINT_CURRENT_LINE();
        msAPI_ATV_SetAudioMode(E_AUDIOSOURCE_ATV, eDetectedAudioMode);
    }
*/
    printf("AudioMode: 0x%X => 0x%X\n", m_eAudioMode, eDetectedAudioMode);

    m_eAudioMode = eDetectedAudioMode;

    m_bIsAudioModeChanged = TRUE;

    MApi_AUDIO_SIF_SetSoundMode(m_eAudioMode);
}
#endif
#endif

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
///
///         AUDIO_HDMI RELATIONAL API FUNCTION
///
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

//*************************************************************************
//Function name:    msAPI_AUD_HDMI_SetNonpcm
//  [doxygen]
/// This function setting HDMI non-PCM or PCM relational register
//*************************************************************************
void msAPI_AUD_HDMI_SetNonpcm(BYTE nonPCM_en)
{
    WORD time_cnt;

    AUDIO_API_TRACE(printf("\r\n@@@ ===msAPI_AUD_HDMI_SetNonpcm : %d===@@@",(int)nonPCM_en));

    if (nonPCM_en)
    {
        MApi_AUDIO_SetCommand( MSAPI_AUD_DVB_DECCMD_STOP);
        MApi_AUDIO_SetSystem( MSAPI_AUD_DVB2_AC3 );
        //msAPI_AUD_SwitchAudioDSPSystem(E_AUDIO_DSP_AC3_AD);
        printf("API-nonPCM\r\n");
        MDrv_AUDIO_SetNormalPath(AUDIO_PATH_MAIN, AUDIO_DSP2_DVB_INPUT, AUDIO_OUTPUT_MAIN_SPEAKER);
        MDrv_AUDIO_SetNormalPath(AUDIO_PATH_LINEOUT, AUDIO_DSP2_DVB_INPUT, AUDIO_OUTPUT_LINEOUT);
        MApi_AUDIO_HDMI_RX_SetNonpcm(TRUE);

        for (time_cnt=0; time_cnt< 800; time_cnt++)
        {
            msAPI_Timer_Delayms(1);
        }
        if (MApi_AUDIO_HDMI_RX_GetNonPCM() == HDMI_RX_DD)
        {   // Dolby mod
            printf("API non-PCM Dolby mod\r\n");
            MApi_AUDIO_SPDIF_SetMode(MSAPI_AUD_SPDIF_NONPCM);
            MApi_AUDIO_SetCommand(MSAPI_AUD_DVB_DECCMD_PLAY);
        }
        else
        {   // Other mod (ie DTS ...)
            printf("API non-PCM DTS mod\r\n");
            MApi_AUDIO_SPDIF_SetMode(MSAPI_AUD_SPDIF_NONPCM);
            MApi_AUDIO_SetCommand( MSAPI_AUD_DVB_DECCMD_STOP );
        }
    }
    else
    {
        printf("API-PCM\r\n");
        MApi_AUDIO_HDMI_RX_SetNonpcm(FALSE);
        MDrv_AUDIO_SetNormalPath(AUDIO_PATH_MAIN, AUDIO_HDMI_INPUT, AUDIO_OUTPUT_MAIN_SPEAKER);
        MDrv_AUDIO_SetNormalPath(AUDIO_PATH_LINEOUT, AUDIO_HDMI_INPUT, AUDIO_OUTPUT_LINEOUT);
        MApi_AUDIO_SetCommand( MSAPI_AUD_DVB_DECCMD_STOP );
        MApi_AUDIO_SPDIF_SetMode(MSAPI_AUD_SPDIF_PCM);
    }
}

//*************************************************************************
//Function name:    msAPI_AUD_HDMI_SetDownSample
//  [doxygen]
/// This function HDMI Set DownSample
//*************************************************************************
void msAPI_AUD_HDMI_SetDownSample(void)
{
    MS_U16 AUD_HDMI_Sample;
    AUD_HDMI_Sample = MApi_AUDIO_HDMI_GetSynthFreq();
  //  AUDIO_API_TRACE(printf("\r\n@@@ ===msAPI_AUD_HDMI_SetDownSample %d===@@@",(int)AUD_HDMI_Sample));
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
///
///         AUDIO_SPDIF RELATIONAL API FUNCTION
///
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------------------------------
/// @brief \b Function \b Name: SPDIF_SetSCMS()
/// @brief \b Function \b Description: Audio SPDIF Set SCMS for CI+
/// @param <IN>        \b       : C_bit_en,L_bit_en
///                    \b [C,L] : [1,0] - Copy Freely
///                    \b [C,L] : [0,1] - Copy No More
///                    \b [C,L] : [0,0] - Copy Once
///                    \b [C,L] : [0,1] - Copy Never
/// @param <OUT>       \b NONE  :
/// @param <GLOBAL>    \b NONE  :
//---------------------------------------------------------------------------
void msAPI_AUD_SPDIF_SetSCMS(AUDIO_SPDIF_SCMS_MODE_ scms_mode)
{
    AUDIO_API_TRACE(printf("\r\n@@@ ===msAPI_AUD_SPDIF_SetSCMS %d===@@@",(int)scms_mode));
    switch(scms_mode)
    {
        case SPDIF_SCMS_CopyOnce_:
            MApi_AUDIO_SPDIF_SetSCMS(0, 0);
            break;

        case SPDIF_SCMS_CopyNoMore_:
        case SPDIF_SCMS_CopyNever_:
            MApi_AUDIO_SPDIF_SetSCMS(0, 1);
            break;

        case SPDIF_SCMS_CopyFreely_:
            MApi_AUDIO_SPDIF_SetSCMS(1, 0);
            break;

        default:
            MApi_AUDIO_SPDIF_SetSCMS(0, 0);
            break;
    }
}

//---------------------------------------------------------------------------
/// @brief \b Function \b Name: SPDIF_GetSCMS()
/// @brief \b Function \b Description: Audio SPDIF Get SCMS for CI+
/// @param <IN>        \b NONE  :
/// @param <OUT>       \c       : SCMS[0] = C bit status, SCMS[1] = L bit status
/// @param <GLOBAL>    \b NONE  :
//---------------------------------------------------------------------------
AUDIO_SPDIF_SCMS_MODE msAPI_AUD_SPDIF_GetSCMS(void)
{
    AUDIO_SPDIF_SCMS_MODE  m_SCMS_status;

    m_SCMS_status = (AUDIO_SPDIF_SCMS_MODE)MApi_AUDIO_SPDIF_GetSCMS();
    return(m_SCMS_status);
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
///
///         AUDIO_SOUND RELATIONAL API FUNCTION
///
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

//=========================================================
//******************************************************************************
//  [Function Name]:
//      msAPI_AUD_SetAudioSource
//  [Description]:
//      re-load the audio decoder here
//  [Arguments]:
//*******************************************************************************
void msAPI_AUD_SetAudioSource(AUDIOSOURCE_TYPE eSource)
{
 //=====================================================================
 // Just re-load the audio decoder here.
 //=====================================================================
    AUDIO_API_TRACE(printf("\r\n@@@ ===msAPI_AUD_SetAudioSource 0x%X===@@@",(int)eSource));
    switch(eSource)
    {
        case E_AUDIOSOURCE_MPEG:
            msAPI_AUD_SwitchAudioDSPSystem(E_AUDIO_DSP_MPEG);
            break;

        case E_AUDIOSOURCE_AC3:
            msAPI_AUD_SwitchAudioDSPSystem(E_AUDIO_DSP_AC3);
            break;

        case E_AUDIOSOURCE_ATV:
            msAPI_AUD_SwitchAudioDSPSystem(E_AUDIO_DSP_SIF);
            break;

        case E_AUDIOSOURCE_HDMI:
        case E_AUDIOSOURCE_HDMI2:
        case E_AUDIOSOURCE_HDMI3:
            msAPI_AUD_SwitchAudioDSPSystem(E_AUDIO_DSP_AC3);
            break;

        default:
            msAPI_AUD_SwitchAudioDSPSystem(E_AUDIO_DSP_SIF);
                break;
    }
}


//=============================================================
// AUDIO_Miscellany FUNCTION
//=============================================================
void msAPI_AUD_I2S_Amp_Reset(void)
{
    //Dont remove it, prepare for furture
#if (DIGITAL_I2S_SELECT != AUDIO_I2S_NONE)
    drvAudio_AMP_Init();
#endif
}

void msAPI_AUD_I2S_Amp_UnReset(void)
{
    //Dont remove it, prepare for furture
}

void msAPI_AUD_SW_Reset(void)
{
    //Dont remove it, prepare for furture
}

//=============================================================
// AUDIO MW functions
//=============================================================

////////////////////////////////////////////////////////////////////////////////
/// @brief \b Function \b Name: MW_AUD_AudioProcessor()
/// @brief \b Function \b Description: Audio handler
/// @param <IN>        \b NONE    :
/// @param <OUT>       \b NONE    :
/// @param <RET>       \b  NONE    :
/// @param <GLOBAL>    \b NONE    :
////////////////////////////////////////////////////////////////////////////////
void MW_AUD_AudioProcessor(void)
{
    if ( (m_eAudioSource != E_AUDIOSOURCE_ATV &&
          m_eAudioSource != E_AUDIOSOURCE_CVBS1 &&
          m_eAudioSource != E_AUDIOSOURCE_CVBS2 &&
          m_eAudioSource != E_AUDIOSOURCE_SVIDEO1 &&
          m_eAudioSource != E_AUDIOSOURCE_SVIDEO2 &&
          m_eAudioSource != E_AUDIOSOURCE_SCART1 &&
          m_eAudioSource != E_AUDIOSOURCE_SCART2)
    #if HDMI_DVI_AUDIO_MODE_CONFIG
       ||(IsHDMIInUse())
    #endif
       )
    {
        return;
    }

    msAPI_AUD_CheckExpirationOfAudioMute();

       // Check the tuning module

#if(TV_SYSTEM != TV_NTSC)
    if ( msAPI_Tuner_IsTuningProcessorBusy() == TRUE )
    {
        return;
    }
#endif

    if(m_wAudioDownCountTimer > 0)
    {
        m_wAudioDownCountTimer--;
        return;
    }

    m_wAudioDownCountTimer = 5;

    if(m_bBySyncAudioMute== FALSE && IsVDHasSignal()==TRUE )
    {
    #if(ENABLE_AUDIO_AUTO_DETECT)
        CheckAudioStandard();
    #endif//(ENABLE_AUDIO_AUTO_DETECT)
    }
    else if( (m_bBySyncAudioMute == TRUE) &&
            (IsVDHasSignal() == TRUE) )
    {
    #if(MS_BOARD_TYPE_SEL != BD_MSD309PX_HIS)
        // Ensure  audio sync with the video,move it to MApp_ScreenMuteMonitor
        msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYSYNC_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
    #endif
    }
    else if( (m_bBySyncAudioMute == FALSE) &&
             (IsVDHasSignal()  == FALSE) )
    {
        msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYSYNC_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
    }
}
#if ENABLE_ATV_AUDIOCHECK_IN_OTHER_SRC
//=============================================================
// AUDIO MW functions
//=============================================================

////////////////////////////////////////////////////////////////////////////////
/// @brief \b Function \b Name: MW_ATV_AudioProcessor()
/// @brief \b Function \b Description: Audio Process when source is not TV.
/// @param <IN>        \b NONE    :
/// @param <OUT>       \b NONE    :
/// @param <RET>       \b  NONE    :
/// @param <GLOBAL>    \b NONE    :
////////////////////////////////////////////////////////////////////////////////
void Mapi_ATV_AudioProcessor(void)
{
    if( m_eAudioSource <= E_AUDIOSOURCE_ATV ||
        m_eAudioSource >= E_AUDIOSOURCE_INVALID)
    {
//        printf("return from Mapi_ATV_AudioProcessor\n");
        return;
    }
//    printf("into Mapi_ATV_AudioProcessor\n");
    if(m_wAtvAudioCheckCount > 0)
    {
        m_wAtvAudioCheckCount--;
        return;
    }

    m_wAtvAudioCheckCount = 5;

//    if( IsVDHasSignal()==TRUE )
    {
    #if(ENABLE_AUDIO_AUTO_DETECT)
        CheckAudioStandard_OtherSource();
    #endif//(ENABLE_AUDIO_AUTO_DETECT)
    }
}
#endif
////////////////////////////////////////////////////////////////////////////////
/// @brief \b Function \b Name: MW_AUD_SetMadAddress()
/// @brief \b Function \b Description: Get audio bin file
/// @param <IN>        \b NONE    :
/// @param <OUT>       \b NONE    :
/// @param <RET>       \b  NONE    :
/// @param <GLOBAL>    \b NONE    :
////////////////////////////////////////////////////////////////////////////////
#if( AUDIO_CPU_IS_R2 )
MS_BOOL msAPI_Audio_LoadCpuCode(MS_U8 u8CpuIdx, MS_U32 u32CpuMemAddr, MS_U32 u32CpuMemSize );
#endif
void MW_AUD_SetMadAddress(void)
{

#if((ENABLE_AUDIO_DSP_BIN==FALSE) || (AUDIO_CPU_IS_R2))
    MDrv_AUDIO_SetDspBaseAddr(DSP_MAD, 0 , ((MAD_BASE_BUFFER_MEMORY_TYPE & MIU1) ? (MAD_BASE_BUFFER_ADR | MIU_INTERVAL) : (MAD_BASE_BUFFER_ADR)));

#else
    BININFO BinInfo;
    BOOLEAN bResult;

    BinInfo.B_ID = BIN_ID_CODE_AUDIO_DSP;

    msAPI_MIU_Get_BinInfo(&BinInfo, &bResult);
    if (bResult  == PASS )
    {
        MApi_AUDIO_SetCommAudioInfo(Audio_Comm_infoType_CompressBin_LoadCode, FALSE, 0);
        MDrv_AUDIO_SetDspBaseAddr(DSP_MAD, BinInfo.B_FAddr, ((MAD_BASE_BUFFER_MEMORY_TYPE & MIU1) ? (MAD_BASE_BUFFER_ADR | MIU_INTERVAL) : (MAD_BASE_BUFFER_ADR)));
    }
    else
        printf("[Audio] no Audio dsp bin on flash!!\n", 0);

#endif

#if (ENABLE_AUDIO_DEC_R2_BIN==TRUE)
    {
        BININFO BinInfo;
        BOOLEAN bResult;

        BinInfo.B_ID = BIN_ID_CODE_AUDIO_DEC_R2;
        msAPI_MIU_Get_BinInfo(&BinInfo, &bResult);

        if (bResult == PASS )
        {
            MApi_AUDIO_SetCommAudioInfo(Audio_Comm_infoType_CompressBin_LoadCode, FALSE, (MS_U32) msAPI_Audio_LoadCpuCode);
            MDrv_AUDIO_SetDspBaseAddr(DSP_ADV, BinInfo.B_FAddr, ((MAD_BASE_BUFFER_MEMORY_TYPE & MIU1) ? (MAD_BASE_BUFFER_ADR | MIU_INTERVAL) : (MAD_BASE_BUFFER_ADR)));
        }
        else
        {
            printf("[Audio] no Audio DEC R2 bin on flash!!\n", 0);
        }
    }
#endif

}

////////////////////////////////////////////////////////////////////////////////
/// @brief \b Function \b Name: MApi_AUDIO_SetNormalPath()
/// @brief \b Function \b Description: This routine is used to set the topalogy for Audio Input .
/// @param <IN>        \b path    : Audio DSP channel
/// @param <IN>        \b input    : Audio input type
/// @param <IN>        \b output: Audio output type
/// @param <OUT>       \b NONE    :
/// @param <RET>       \b NONE    :
/// @param <GLOBAL>    \b NONE    :
////////////////////////////////////////////////////////////////////////////////
void MApi_AUDIO_SetNormalPath(AUDIO_PATH_TYPE path, AUDIO_INPUT_TYPE input, AUDIO_OUTPUT_TYPE output)
{
    MDrv_AUDIO_SetNormalPath(path, input, output);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief \b Function \b Name: MW_AUD_SetSoundMute()
/// @brief \b Function \b Description: This routine is used to set all kind of audio  .
/// @param <IN>        \b eSoundMuteSource    : mute source type
/// @param <IN>        \b eOnOff    : mute or unmute
/// @param <OUT>       \b NONE    :
/// @param <RET>       \b NONE    :
/// @param <GLOBAL>    \b NONE    :
////////////////////////////////////////////////////////////////////////////////
void MW_AUD_SetSoundMute(SOUND_MUTE_SOURCE eSoundMuteSource, SOUND_MUTE_TYPE eOnOff)
{
    AUDIO_API_TRACE(printf("\r\n@@@ ===MW_AUD_SetSoundMute : 0x%X , %d===@@@",(int)eSoundMuteSource, (int)eOnOff));
    switch(eSoundMuteSource)
    {
        case SOUND_MUTE_TV:
            MApi_AUDIO_SetMute(AUDIO_PATH_MAIN_SPEAKER, eOnOff);
            MApi_AUDIO_SetMute(AUDIO_PATH_HP, eOnOff);
            break;

        case SOUND_MUTE_SPEAKER:
            MApi_AUDIO_SetMute(AUDIO_PATH_MAIN_SPEAKER, eOnOff);
            break;

        case SOUND_MUTE_HP:
            MApi_AUDIO_SetMute(AUDIO_PATH_HP, eOnOff);
            break;

        case SOUND_MUTE_SCART:
        #if SCART_ALWAYS_OUTPUT_ATV
            if(IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
             MApi_AUDIO_SetMute(AUDIO_PATH_SIFOUT, eOnOff);
            else
            {
                //fixed scart out pop sound when switch source
                if(g_u8switchsourceprocessing==TRUE)
                {
                     MApi_AUDIO_SetMute(AUDIO_PATH_SIFOUT, eOnOff);
                }
                else
                {
                     MApi_AUDIO_SetMute(AUDIO_PATH_SIFOUT, E_MUTE_OFF);
                }
            }
        #else
             MApi_AUDIO_SetMute(AUDIO_PATH_SIFOUT, eOnOff);
        #endif
            break;

        case SOUND_MUTE_MONITOR_OUT:
        case SOUND_MUTE_SCART2:
            MApi_AUDIO_SetMute(AUDIO_PATH_LINEOUT, eOnOff);
            break;

        case SOUND_MUTE_SPDIF:
            MApi_AUDIO_SetMute(AUDIO_PATH_SPDIF, eOnOff);
            break;

        case SOUND_MUTE_ALL_EXCEPT_SCART:
            MApi_AUDIO_SetMute(AUDIO_PATH_MAIN_SPEAKER, eOnOff);
            MApi_AUDIO_SetMute(AUDIO_PATH_HP, eOnOff);
            //MApi_AUDIO_SetMute(AUDIO_PATH_LINEOUT, eOnOff);  //line out is for scart 2
            MApi_AUDIO_SetMute(AUDIO_PATH_SPDIF, eOnOff);
            break;

        case SOUND_MUTE_ALL:
            MApi_AUDIO_SetMute(AUDIO_PATH_MAIN_SPEAKER, eOnOff);
            MApi_AUDIO_SetMute(AUDIO_PATH_HP, eOnOff);
            MApi_AUDIO_SetMute(AUDIO_PATH_LINEOUT, eOnOff);
            MApi_AUDIO_SetMute(AUDIO_PATH_SIFOUT, eOnOff);
            MApi_AUDIO_SetMute(AUDIO_PATH_SPDIF, eOnOff);
            break;

        case SOUND_MUTE_AMP:
            break;

        default:
            break;
    }
}

////////////////////////////////////////////////////////////////////////////////
/// @brief \b Function \b Description: This routine is used to set PEQ Coefficient.
/// @param <IN>        \b Band  : 0~7
///                                  \b Gain:0~240, -12dB~+12dB
///                                  \b Fo = Foh*100 + Fol (Hz)
///                                  \Q: 10~160, corresponding to 1~16
/// @param <OUT>       \b NONE    :
/// @param <RET>       \b  NONE    :
/// @param <GLOBAL>    \b NONE
////////////////////////////////////////////////////////////////////////////////
void msAPI_AUD_SetPEQ(MS_U8 Band, MS_U8 Gain, MS_U8 Foh, MS_U8 Fol, MS_U8 QValue)
{
    float coef;
    float G, fc, Q;
    float fb,d,v0,H0,aBC,fm,fz,kb,fs;

    AUDIO_PEQ_COEF PEQCoef;
    MS_BOOL error_config = FALSE;
    PEQCoef.type        = AUDIO_COEF_PREVER_PEQ;
    PEQCoef.enable      = TRUE;
    PEQCoef.precision   = AUDIO_SINGLE_PRECISION;
    PEQCoef.scale = 1;

    if(Gain > 240)
    {
        printf("%s err! PEQ Gain should be 0~240\n", __FUNCTION__);
        error_config = TRUE;
    }

    if(Fol > 99)
    {
        printf("%s err! PEQ Fol should be 0~99\n", __FUNCTION__);
        error_config = TRUE;
    }

    if((Foh== 0) && (Fol < 50))
    {
         printf("%s err! PEQ Fo should be > 50\n", __FUNCTION__);
        error_config = TRUE;
    }

    if((QValue < 5) || (QValue > 160))
    {
        printf("%s err! PEQ QValue should be 5~160\n", __FUNCTION__);
        error_config = TRUE;
    }

    if(error_config == TRUE)
        return;

    PEQCoef.band = Band;
    fc = (float)(((int)Foh) * 100 + (int)Fol);

    for(PEQCoef.sfs = 0; PEQCoef.sfs <= 1; PEQCoef.sfs++)
    {
        if(PEQCoef.sfs == 0)
        {
            fs = 32000;
        }
        else
        {
            fs = 48000;
        }
        Q = ((float)QValue) / 10;

        G = ((float)(Gain - 120)) / 10;

        fc = (float)(((int)Foh) * 100 + (int)Fol);

        fb = fc / Q;
        d = - cos( 2 * 3.1415926 * fc / fs);
        v0 = powf(10.0, (G / 20.0));

        H0 = v0 -1;
        aBC=0;
        fm=0;
        fz=1;
        kb = tan ( 3.1415926 * fb / fs);

        if (G >=0)
        {
            fz = kb - 1;
            fm = kb + 1;
        }
        else
        {
            fz = kb - v0;
            fm = kb + v0;
        }

        aBC = fz / fm ;
        coef = 1 + (1 + aBC) * H0 / 2;
        PEQCoef.a0 = (long)(coef * 4194304);
        coef = d * (1 - aBC);
        PEQCoef.a1 = (long)(coef * 4194304);
        coef = -aBC - (1 + aBC) * H0 /2;
        PEQCoef.a2 = (long)(coef * 4194304);
        coef = d * (1 - aBC);
        PEQCoef.b1 = (long)(-coef * 4194304);
        coef = -aBC;
        PEQCoef.b2 = (long)(-coef * 4194304);


        AUD_DEBUG(printf("PEQ:%d %d %d %d\n",Gain,Foh,Fol,QValue));
        AUD_DEBUG(printf("a0:%lx, ",PEQCoef.a0));
        AUD_DEBUG(printf("a1:%lx, ",PEQCoef.a1));
        AUD_DEBUG(printf("a2:%lx, ",PEQCoef.a2));
        AUD_DEBUG(printf("b1:%lx, ",PEQCoef.b1));
        AUD_DEBUG(printf("b2:%lx, ",PEQCoef.b2));
        AUD_DEBUG(printf("\n"));
        MApi_AUDIO_EnablePEQ(TRUE);
        MApi_AUDIO_SetPEQCoef(&PEQCoef);
    }
}

#if 1//(CHIP_FAMILY_TYPE != CHIP_FAMILY_EDEN)
////////////////////////////////////////////////////////////////////////////////
/// @brief \b Function \b Description: This routine is used to set PEQ Coefficient.
/// @param <IN>        \b Band  : 0~7
///                    \b Gain  : -240~240
///                    \b Fo    : 10~16000(Hz)
///                    \b QValue: 1~160  (0.1~16)
///                    \b Enable: 1:enable, 0:disable
///                    \b Precision : 1:double, 0:single
/// @param <OUT>       \b NONE :
/// @param <RET>       \b NONE :
/// @param <GLOBAL>    \b NONE
////////////////////////////////////////////////////////////////////////////////
BOOLEAN msAPI_AUD_SetPEQBand(MS_U8 Band, MS_S16 Gain, MS_U16 Fo, MS_U8 QValue, MS_BOOL Enable, AUDIO_PRECISION_TYPE Precision)
{
    float coef[5];
    float v0,dem;
    float G,fc,Q;

    float k;
    float kpow2;
    AUDIO_PEQ_COEF PEQCoef;
    float maxCoef;
    int i;

    PEQCoef.scale = 0;
    PEQCoef.type = AUDIO_COEF_PEQ;
    PEQCoef.enable = Enable;
    PEQCoef.precision = Precision;
    if(QValue < 1 || QValue > 160)
    {
        return FALSE;
    }
    if(Fo < 10 || Fo > 16000)
    {
        return FALSE;
    }
    if(Gain < -240 || Gain > 240 )
    {
        return FALSE;
    }

    PEQCoef.band = Band;
    fc = (float)Fo;

    for(PEQCoef.sfs=0; PEQCoef.sfs<=1; PEQCoef.sfs++)
    {
        if(PEQCoef.sfs)
        {
            AUD_DEBUG(printf("48k: %x\r\n",1));
            k = tan((3.1415926*fc)/48000);
        }
        else
        {
            AUD_DEBUG(printf("32k: %x\r\n",0));
            k = tan((3.1415926*fc)/32000);
        }

        Q = ((float)QValue)/10.0;
        G = ((float)Gain)/10.0;

        kpow2 = k*k;

        AUD_DEBUG(printf("Gain: %d\r\n",(int)Gain));
        AUD_DEBUG(printf("fc: %d\r\n",(int)fc));
        AUD_DEBUG(printf("Q: %d\r\n",(int)Q));

        v0 = powf (10.0, fabs(G/20.0));

        if (G >= 0)
        {
            //Peak,boost
            dem = 1 + k/Q + kpow2;
            coef[0] = (1 + v0*k/Q + kpow2)/dem;
            coef[1] = 2*(kpow2-1)/dem;
            coef[2] = (1 - v0*k/Q + kpow2)/dem;
            coef[3] = 2*(kpow2-1)/dem;
            coef[4] = (1 - k/Q + kpow2)/dem;

            maxCoef = (float)fabs((double)coef[0]);
            for(i=1; i<5; i++)
            {
                if((float)fabs((double)coef[i]) > maxCoef)
                {
                    maxCoef = (float)fabs((double)coef[i]);
                }
            }

            if(maxCoef <= 1)
            {
                if(fc < 200)
                    PEQCoef.scale = 0;
                else
                    PEQCoef.scale = 1;
            }
            else if(maxCoef <= 2)
            {
                PEQCoef.scale = 1;
            }
            else if(maxCoef <= 4)
            {
                PEQCoef.scale = 2;
            }
            else if(maxCoef <= 8)
            {
                PEQCoef.scale = 3;
            }
            else if(maxCoef <= 16)
            {
                PEQCoef.scale = 4;
            }
            else if(maxCoef <= 32)
            {
                PEQCoef.scale = 5;
            }

            PEQCoef.a0 = (coef[0] * 8388608/(int)pow(2,(double)PEQCoef.scale));
            PEQCoef.a1 = (coef[1] * 8388608/(int)pow(2,(double)PEQCoef.scale));
            PEQCoef.a2 = (coef[2] * 8388608/(int)pow(2,(double) PEQCoef.scale));
            PEQCoef.b1 = (-coef[3] * 8388608/(int)pow(2,(double)PEQCoef.scale));
            PEQCoef.b2 = (-coef[4] * 8388608/(int)pow(2,(double) PEQCoef.scale));
        }
        else
        {
            //peak,cut

            dem = 1 + v0*k/Q + kpow2;
            coef[0] = (1 + k/Q + kpow2)/dem;
            coef[1] = 2*(kpow2-1)/dem;
            coef[2] = (1 - k/Q + kpow2)/dem;
            coef[3] = 2*(kpow2-1)/dem;
            coef[4] = (1 - v0*k/Q + kpow2)/dem;

            maxCoef = (float)fabs((double)coef[0]);
            for(i=1; i<5; i++)
            {
                if((float)fabs((double)coef[i]) > maxCoef)
                {
                    maxCoef = (float)fabs((double)coef[i]);
                }
            }

            if(maxCoef <= 1)
            {
                if(fc < 200)
                    PEQCoef.scale = 0;
                else
                    PEQCoef.scale = 1;
            }
            else if(maxCoef <= 2)
            {
                PEQCoef.scale = 1;
            }
            else if(maxCoef <= 4)
            {
                PEQCoef.scale = 2;
            }
            else if(maxCoef <= 8)
            {
                PEQCoef.scale = 3;
            }
            else if(maxCoef <= 16)
            {
                PEQCoef.scale = 4;
            }
            else if(maxCoef <= 32)
            {
                PEQCoef.scale = 5;
            }

            PEQCoef.a0 = (coef[0] * 8388608/(int)pow(2, PEQCoef.scale));
            PEQCoef.a1 = (coef[1] * 8388608/(int)pow(2, PEQCoef.scale));
            PEQCoef.a2 = (coef[2] * 8388608/(int)pow(2, PEQCoef.scale));
            PEQCoef.b1 = (-coef[3] * 8388608/(int)pow(2, PEQCoef.scale));
            PEQCoef.b2 = (-coef[4] * 8388608/(int)pow(2, PEQCoef.scale));
        }
        MApi_AUDIO_SetPEQCoef(&PEQCoef);

        AUD_DEBUG(printf("msAPI a0 = %x", (MS_U8)(PEQCoef.a0>>16)));
        AUD_DEBUG(printf(" %x", (MS_U8)(PEQCoef.a0>>8)));
        AUD_DEBUG(printf(" %x\r\n", (MS_U8)PEQCoef.a0));

        AUD_DEBUG(printf("a1 = %x", (MS_U8)(PEQCoef.a1>>16)));
        AUD_DEBUG(printf(" %x", (MS_U8)(PEQCoef.a1>>8)));
        AUD_DEBUG(printf(" %x\r\n", (MS_U8)PEQCoef.a1));

        AUD_DEBUG(printf("a2 = %x", (MS_U8)(PEQCoef.a2>>16)));
        AUD_DEBUG(printf(" %x", (MS_U8)(PEQCoef.a2>>8)));
        AUD_DEBUG(printf(" %x\r\n", (MS_U8)PEQCoef.a2));

        AUD_DEBUG(printf("b1 = %x", (MS_U8)(PEQCoef.b1>>16)));
        AUD_DEBUG(printf(" %x", (MS_U8)(PEQCoef.b1>>8)));
        AUD_DEBUG(printf(" %x\r\n", (MS_U8)PEQCoef.b1));

        AUD_DEBUG(printf("b2 = %x", (MS_U8)(PEQCoef.b2>>16)));
        AUD_DEBUG(printf(" %x", (MS_U8)(PEQCoef.b2>>8)));
        AUD_DEBUG(printf(" %x\r\n", (MS_U8)PEQCoef.b2));

        AUD_DEBUG(printf("scale = %x\r\n", (MS_U8)PEQCoef.scale));
    }
    return TRUE;
}

//-------------------------------------------------------------------------------------------------
/// @brief \b Function \b Description: This routine is used to set HLPF Coefficient.
/// @param <IN>
///                    \b type: 0:LPF 1:HPF
///                    \b Fo: 10~16000 (Hz)
///                    \b Qvalue: 50~90 (0.5~0.9)
/// @param <OUT>       \b NONE:
/// @param <RET>       \b NONE:
/// @param <GLOBAL>    \b NONE
//-------------------------------------------------------------------------------------------------
BOOLEAN msAPI_AUD_SetHLPF(MS_U8 type, MS_U16 Fo, MS_U8 QValue)
{
    float coef[5];
    float dem;
    float fc,Q;
    float k;
    float kpow2;
    AUDIO_PEQ_COEF PEQCoef;

    if(QValue < 50 || QValue > 90)
    {
        return FALSE;
    }
    if(Fo < 10 || Fo > 16000)
    {
        return FALSE;
    }

    PEQCoef.type = AUDIO_COEF_HPF;
    fc = (float)Fo;
    for(PEQCoef.sfs=0; PEQCoef.sfs<=1; PEQCoef.sfs++)
    {
        if(PEQCoef.sfs)
        {
            AUD_DEBUG(printf("48k: %x\r\n",1));
            k = tan((3.1415926*fc)/48000);
        }
        else
        {
            AUD_DEBUG(printf("32k: %x\r\n",0));
            k = tan((3.1415926*fc)/32000);
        }

        //Q = 1/sqrt(2);
        Q = ((float)QValue)/100.0 ;
        kpow2 = k*k;

        if (type == 0)
        {
            //lpf
            dem = 1 + k/Q + kpow2;
            coef[0] = kpow2/dem;
            coef[1] = 2*kpow2/dem;
            coef[2] = kpow2/dem;
            coef[3] = 2*(kpow2-1)/dem;
            coef[4] = (1 - k/Q + kpow2)/dem;

            PEQCoef.a0 = (coef[0] * 8388608/2);
            PEQCoef.a1 = (coef[1] * 8388608/2);
            PEQCoef.a2 = (coef[2] * 8388608/2);
            PEQCoef.b1 = (-coef[3] * 8388608/2);
            PEQCoef.b2 = (-coef[4] * 8388608/2);
        }
        else
        {
            //hpf
            dem = 1 + k/Q + kpow2;
            coef[0] = 1/dem;
            coef[1] = -2/dem;
            coef[2] = 1/dem;
            coef[3] = 2*(kpow2-1)/dem;
            coef[4] = (1 - k/Q + kpow2)/dem;

            PEQCoef.a0 = (coef[0] * 8388608/2);
            PEQCoef.a1 = (coef[1] * 8388608/2);
            PEQCoef.a2 = (coef[2] * 8388608/2);
            PEQCoef.b1 = (-coef[3] * 8388608/2);
            PEQCoef.b2 = (-coef[4] * 8388608/2);
        }

        MApi_AUDIO_SetPEQCoef(&PEQCoef);

        AUD_DEBUG(printf("msAPI a0 = %x", (MS_U8)(PEQCoef.a0>>16)));
        AUD_DEBUG(printf(" %x", (MS_U8)(PEQCoef.a0>>8)));
        AUD_DEBUG(printf(" %x\r\n", (MS_U8)PEQCoef.a0));

        AUD_DEBUG(printf("a1 = %x", (MS_U8)(PEQCoef.a1>>16)));
        AUD_DEBUG(printf(" %x", (MS_U8)(PEQCoef.a1>>8)));
        AUD_DEBUG(printf(" %x\r\n", (MS_U8)PEQCoef.a1));

        AUD_DEBUG(printf("a2 = %x", (MS_U8)(PEQCoef.a2>>16)));
        AUD_DEBUG(printf(" %x", (MS_U8)(PEQCoef.a2>>8)));
        AUD_DEBUG(printf(" %x\r\n", (MS_U8)PEQCoef.a2));

        AUD_DEBUG(printf("b1 = %x", (MS_U8)(PEQCoef.b1>>16)));
        AUD_DEBUG(printf(" %x", (MS_U8)(PEQCoef.b1>>8)));
        AUD_DEBUG(printf(" %x\r\n", (MS_U8)PEQCoef.b1));

        AUD_DEBUG(printf("b2 = %x", (MS_U8)(PEQCoef.b2>>16)));
        AUD_DEBUG(printf(" %x", (MS_U8)(PEQCoef.b2>>8)));
        AUD_DEBUG(printf(" %x\r\n", (MS_U8)PEQCoef.b2));
    }
    return TRUE;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief \b Function \b Description: This routine is used to set TONE Coefficient.
/// @param <IN>        \b type: 0:Bass 1:Treble
///                    \b Gain  : -200~200 (-20dB~20dB)
///                    \b Fc: 10 ~ 16000(Hz)
///                    \b Qvalue: 50~90 (0.5~0.9)
/// @param <OUT>       \b NONE  :
/// @param <RET>       \b NONE :
/// @param <GLOBAL>    \b NONE
////////////////////////////////////////////////////////////////////////////////
BOOLEAN msAPI_AUD_SetTONE(MS_U8 Type, MS_S16 Gain, MS_U16 Fo, MS_U8 QValue)
{
    float coef[5];
    float v0,dem,dem1,dem2;
    float G,fc,Q;

    float k;
    float kpow2,sqrtv0;
    AUDIO_PEQ_COEF PEQCoef;
    float maxCoef;
    int i;
    PEQCoef.scale = 0;  //CID 162294  Uninitialized scalar variable

    if(QValue < 50 || QValue > 90)
    {
        return FALSE;
    }
    if(Fo < 10 || Fo > 16000)
    {
        return FALSE;
    }
    if(Gain < -200 || Gain > 200 )
    {
        return FALSE;
    }

    fc = (float)Fo;

    if(Type == 0) //bass
    {
        PEQCoef.type = AUDIO_COEF_BASS;
        for(PEQCoef.sfs=0; PEQCoef.sfs<=1; PEQCoef.sfs++)
        {
            if(PEQCoef.sfs)
            {
                AUD_DEBUG(printf("48k: %x\r\n",1));
                k = tan((3.1415926*fc)/48000);
            }
            else
            {
                AUD_DEBUG(printf("32k: %x\r\n",0));
                k = tan((3.1415926*fc)/32000);
            }

            Q = ((float)QValue)/100.0;
            G = ((float)Gain)/10.0;
            fc = (float)Fo;

            kpow2 = k*k;

            AUD_DEBUG(printf("Gain: %d\r\n",(int)Gain));
            AUD_DEBUG(printf("fc: %d\r\n",(int)fc));
            AUD_DEBUG(printf("Q: %d\r\n",(int)Q));

            v0 = powf (10.0, fabs(G/20.0));
            sqrtv0 = sqrt(v0);

            if (G >= 0)
            {
                //bass,boost
                dem = 1 + k/Q + kpow2;
                coef[0] = (1+sqrtv0*k/Q + v0*kpow2)/dem;
                PEQCoef.a0 = (coef[0] * 4194304);
                coef[0] = (2 *(v0*kpow2 - 1))/dem;
                PEQCoef.a1 = (coef[0] * 4194304);
                coef[0] = (1 - sqrtv0*k/Q + v0*kpow2)/dem;
                PEQCoef.a2 = (coef[0] * 4194304);
                coef[0] = 2*(kpow2 - 1)/dem;
                PEQCoef.b1 = (-coef[0] * 4194304);
                coef[0] = (1 - k/Q + kpow2)/dem;
                PEQCoef.b2 = (-coef[0] * 4194304);
            }
            else
            {
                //bass,cut
                dem = 1 + sqrtv0*k/Q + v0*kpow2;
                coef[0] = (1 + k/Q + kpow2) / dem;
                PEQCoef.a0 = (coef[0] * 4194304);
                coef[0] = (2 * (kpow2 - 1) ) / dem;
                PEQCoef.a1 = (coef[0] * 4194304);
                coef[0] = (1 - k/Q + kpow2) / dem;
                PEQCoef.a2 = (coef[0] * 4194304);
                coef[0] = (2 * (v0*kpow2 - 1) ) / dem;
                PEQCoef.b1 = (-coef[0] * 4194304);
                coef[0] = (1 - sqrtv0*k/Q + v0*kpow2) / dem;
                PEQCoef.b2 = (-coef[0] * 4194304);
            }

            MApi_AUDIO_SetPEQCoef(&PEQCoef);

            AUD_DEBUG(printf("msAPI a0 = %x", (MS_U8)(PEQCoef.a0>>16)));
            AUD_DEBUG(printf(" %x", (MS_U8)(PEQCoef.a0>>8)));
            AUD_DEBUG(printf(" %x\r\n", (MS_U8)PEQCoef.a0));

            AUD_DEBUG(printf("a1 = %x", (MS_U8)(PEQCoef.a1>>16)));
            AUD_DEBUG(printf(" %x", (MS_U8)(PEQCoef.a1>>8)));
            AUD_DEBUG(printf(" %x\r\n", (MS_U8)PEQCoef.a1));

            AUD_DEBUG(printf("a2 = %x", (MS_U8)(PEQCoef.a2>>16)));
            AUD_DEBUG(printf(" %x", (MS_U8)(PEQCoef.a2>>8)));
            AUD_DEBUG(printf(" %x\r\n", (MS_U8)PEQCoef.a2));

            AUD_DEBUG(printf("b1 = %x", (MS_U8)(PEQCoef.b1>>16)));
            AUD_DEBUG(printf(" %x", (MS_U8)(PEQCoef.b1>>8)));
            AUD_DEBUG(printf(" %x\r\n", (MS_U8)PEQCoef.b1));

            AUD_DEBUG(printf("b2 = %x", (MS_U8)(PEQCoef.b2>>16)));
            AUD_DEBUG(printf(" %x", (MS_U8)(PEQCoef.b2>>8)));
            AUD_DEBUG(printf(" %x\r\n", (MS_U8)PEQCoef.b2));
        }
    }
    else //Treble
    {
        PEQCoef.type = AUDIO_COEF_TREBLE;
        for(PEQCoef.sfs=0; PEQCoef.sfs<=1; PEQCoef.sfs++)
        {
            if(PEQCoef.sfs)
            {
                AUD_DEBUG(printf("48k: %x\r\n",1));
                k = tan((3.1415926*fc)/48000);
            }
            else
            {
                AUD_DEBUG(printf("32k: %x\r\n",0));
                k = tan((3.1415926*fc)/32000);
            }

            Q = ((float)QValue)/100.0;
            G = ((float)Gain)/10.0;
            fc = (float)Fo;

            kpow2 = k*k;
            AUD_DEBUG(printf("Gain: %d\r\n",(int)Gain));
            AUD_DEBUG(printf("fc: %d\r\n",(int)fc));
            AUD_DEBUG(printf("Q: %d\r\n",(int)Q));

            v0 = powf (10.0, fabs(G/20.0));
            sqrtv0 = sqrt(v0);

            if (G >= 0)
            {
                //treble,boost
                dem = 1 + k/Q + kpow2;
                coef[0] = (v0 + sqrtv0*k/Q + kpow2) / dem;
                coef[1] = (2 * (kpow2 - v0) ) / dem;
                coef[2] = (v0 - sqrtv0*k/Q + kpow2) / dem;
                coef[3] = (2 * (kpow2 - 1) ) / dem;
                coef[4] = (1 - k/Q + kpow2) / dem;
            }
            else
            {
                //treble,cut
                dem1 = v0 + sqrtv0*k/Q + kpow2;
                dem2 = 1 + k/(sqrtv0*Q) + (kpow2)/v0;
                coef[0] = (1 + k/Q + kpow2) / dem1;
                coef[1] = (2 * (kpow2 - 1) ) / dem1;
                coef[2] = (1 - k/Q + kpow2) / dem1;
                coef[3] = (2 * ((kpow2)/v0 - 1) ) / dem2;
                coef[4] = (1 - k/(sqrtv0*Q) + (kpow2)/v0) / dem2;
            }

            maxCoef = (float)fabs((double)coef[0]);
            for(i=1; i<5; i++)
            {
                if((float)fabs((double)coef[i]) > maxCoef)
                {
                    maxCoef = (float)fabs((double)coef[i]);
                }
            }

            if(maxCoef <= 1)
            {
                if(fc < 200)
                    PEQCoef.scale = 0;
                else
                    PEQCoef.scale = 1;
            }
            else if(maxCoef <= 2)
            {
                PEQCoef.scale = 1;
            }
            else if(maxCoef <= 4)
            {
                PEQCoef.scale = 2;
            }
            else if(maxCoef <= 8)
            {
                PEQCoef.scale = 3;
            }
            else if(maxCoef <= 16)
            {
                PEQCoef.scale = 4;
            }
            else if(maxCoef <= 32)
            {
                PEQCoef.scale = 5;
            }

            PEQCoef.a0 = (long)(coef[0] * 8388608/pow(2, PEQCoef.scale));
            PEQCoef.a1 = (long)(coef[1] * 8388608/pow(2, PEQCoef.scale));
            PEQCoef.a2 = (long)(coef[2] * 8388608/pow(2, PEQCoef.scale));
            PEQCoef.b1 = (long)(-coef[3] * 8388608/pow(2, PEQCoef.scale));
            PEQCoef.b2 = (long)(-coef[4] * 8388608/pow(2, PEQCoef.scale));

            MApi_AUDIO_SetPEQCoef(&PEQCoef);

            AUD_DEBUG(printf("msAPI a0 = %x", (MS_U8)(PEQCoef.a0>>16)));
            AUD_DEBUG(printf(" %x", (MS_U8)(PEQCoef.a0>>8)));
            AUD_DEBUG(printf(" %x\r\n", (MS_U8)PEQCoef.a0));

            AUD_DEBUG(printf("a1 = %x", (MS_U8)(PEQCoef.a1>>16)));
            AUD_DEBUG(printf(" %x", (MS_U8)(PEQCoef.a1>>8)));
            AUD_DEBUG(printf(" %x\r\n", (MS_U8)PEQCoef.a1));

            AUD_DEBUG(printf("a2 = %x", (MS_U8)(PEQCoef.a2>>16)));
            AUD_DEBUG(printf(" %x", (MS_U8)(PEQCoef.a2>>8)));
            AUD_DEBUG(printf(" %x\r\n", (MS_U8)PEQCoef.a2));

            AUD_DEBUG(printf("b1 = %x", (MS_U8)(PEQCoef.b1>>16)));
            AUD_DEBUG(printf(" %x", (MS_U8)(PEQCoef.b1>>8)));
            AUD_DEBUG(printf(" %x\r\n", (MS_U8)PEQCoef.b1));

            AUD_DEBUG(printf("b2 = %x", (MS_U8)(PEQCoef.b2>>16)));
            AUD_DEBUG(printf(" %x", (MS_U8)(PEQCoef.b2>>8)));
            AUD_DEBUG(printf(" %x\r\n", (MS_U8)PEQCoef.b2));
        }
    }
    return TRUE;
}
#endif

void msApi_AUD_SIF_Shift(En_AUD_VIF_Type type)
{
    MApi_AUDIO_SIF_Shift(type);
    MApi_AUDIO_SIF_SetThreshold(AuSifInitThreshold);

    #if (SIF_IS_PAL_SYSTEM)
        #if((FRONTEND_IF_DEMODE_TYPE==MSTAR_VIF)||(FRONTEND_IF_DEMODE_TYPE==MSTAR_VIF_MSB1210)||(FRONTEND_IF_DEMODE_TYPE==MSTAR_INTERN_VIF))
        MApi_AUDIO_SIF_SetPrescale(SET_PRESCALE_A2_FM,3); //kochien for VIF
        MApi_AUDIO_SIF_SetPrescale(SET_PRESCALE_NICAM,3);
        MApi_AUDIO_SIF_SetPrescale(SET_PRESCALE_AM,7);
        MApi_AUDIO_SIF_SetPrescale(SET_PRESCALE_HIDEV,3);
        #else  // MSTAR_INTERN_VIF & NONE_VIF
        MApi_AUDIO_SIF_SetPrescale(SET_PRESCALE_A2_FM,6);
        MApi_AUDIO_SIF_SetPrescale(SET_PRESCALE_AM,9);
        MApi_AUDIO_SIF_SetPrescale(SET_PRESCALE_NICAM,6);
        MApi_AUDIO_SIF_SetPrescale(SET_PRESCALE_HIDEV,6);
        #endif
    #else
        MApi_AUDIO_SIF_SetPrescale(SET_PRESCALE_BTSC,0);
        MApi_AUDIO_SIF_SetPrescale(SET_PRESCALE_BTSC_MONO,0);
        MApi_AUDIO_SIF_SetPrescale(SET_PRESCALE_BTSC_STEREO,0);
        MApi_AUDIO_SIF_SetPrescale(SET_PRESCALE_BTSC_SAP,0);
    #endif
}

#if( AUDIO_CPU_IS_R2 )
#define DEBUG_AUDIO_LOAD_CODE(x)  //x
extern U8 g_MsDecomp_u8Debug;
extern U8 g_MsDecomp_u8CheckTempSize;
extern U32 g_MsDecomp_u32TempSize;

MS_BOOL msAPI_Audio_LoadCpuCode(MS_U8 u8CpuIdx, MS_U32 u32CpuMemAddr, MS_U32 u32CpuMemSize )
{
    // Dest buffer
    U32 u32DestMemAddr = u32CpuMemAddr;
    U32 u32DestMemAddr_VA_Cached = MsOS_PA2KSEG0(u32DestMemAddr);

    // Src buffer
    U32 u32R2BinFileMemAddr;
    U32 u32R2BinFileMemAddr_VA;

    // Tmp buf for decomp
#if( !ENABLE_DECOMP7_USE_HK_MEMORY )
    U8 au8DecompTmpBuf[0x4000];
#endif

    BOOLEAN bResult;
    BININFO stBinInfo;
    U32 u32BinFileFlashAddr;
    U32 u32BinFileFlashSize;
    U32 u32BinFileRealSize;
    U32 u32OriginalFileSize = 0;

    U8 i;
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START(););


    DEBUG_AUDIO_LOAD_CODE( printf("msAPI_Audio_LoadCpuCode(cpu=0x%X,addr=0x%X,size=0x%X)\n", u8CpuIdx, u32CpuMemAddr, u32CpuMemSize); );


    if( u8CpuIdx > 0 )
    {
        printf("\n!!ERROR!! u8CpuIdx=%x is invalid!\n", u8CpuIdx);
        return FALSE;
    }

    stBinInfo.B_ID = BIN_ID_CODE_AUDIO_DEC_R2;

    // Get bin info
    MDrv_Sys_Get_BinInfo(&stBinInfo, &bResult);
    if ( bResult == PASS )
    {
        u32BinFileFlashAddr = stBinInfo.B_FAddr;
        u32BinFileFlashSize = stBinInfo.B_Len;
        u32BinFileRealSize = u32BinFileFlashSize;
    }
    else
    {
        printf("\n!!ERROR!! Can't get audio bin info!\n");
        return FALSE;
    }

    DEBUG_AUDIO_LOAD_CODE( printf("u32BinFileFlashAddr=0x%X\n", u32BinFileFlashAddr); );
    DEBUG_AUDIO_LOAD_CODE( printf("u32BinFileFlashSize=0x%X\n", u32BinFileFlashSize); );
    DEBUG_AUDIO_LOAD_CODE( printf("stBinInfo->B_IsComp=0x%X\n", stBinInfo.B_IsComp); );

    DEBUG_AUDIO_LOAD_CODE( printf("u32DestMemAddr=0x%X\n", u32DestMemAddr); );
    DEBUG_AUDIO_LOAD_CODE( printf("u32DestMemAddr_VA_Cached=0x%X\n", u32DestMemAddr_VA_Cached); );

    // Check compress mode
    if( (MS_COMPRESS7 == stBinInfo.B_IsComp)
      ||(MS_COMPRESS == stBinInfo.B_IsComp)
      )
    {
        // Cal bin file mem addr
        u32R2BinFileMemAddr = u32DestMemAddr + u32CpuMemSize - u32BinFileFlashSize;
        u32R2BinFileMemAddr_VA = MsOS_PA2KSEG0(u32R2BinFileMemAddr);

        DEBUG_AUDIO_LOAD_CODE( printf("u32R2BinFileMemAddr=0x%X\n", u32R2BinFileMemAddr); );
        DEBUG_AUDIO_LOAD_CODE( printf("u32R2BinFileMemAddr_VA=0x%X\n", u32R2BinFileMemAddr_VA); );

        // Copy bin file from flash to dram
        MApi_BDMA_CopyFromResource(u32BinFileFlashAddr, u32R2BinFileMemAddr_VA, u32BinFileFlashSize);

        //search compressed file real length
        for( i=3; i<12; i++)
        {
            if ( *((U8 *)(u32R2BinFileMemAddr_VA+u32BinFileRealSize-i)) == 0xEF )
            {
                if ( *((U8 *)(u32R2BinFileMemAddr_VA+u32BinFileRealSize-i-1)) == 0xBE )
                    u32BinFileRealSize -= (i+1);
            }
        }

        DEBUG_AUDIO_LOAD_CODE( printf("u32BinFileRealSize=%u(0x%X)\n", u32BinFileRealSize,u32BinFileRealSize); );

        if( (MS_COMPRESS7 == stBinInfo.B_IsComp) )
        {
            // Get original file size
            for (i = 0; i < 8; i++)
            {
                u32OriginalFileSize += ( (U32)((U8 *)u32R2BinFileMemAddr_VA)[5 + i] << (i << 3) );
                //printf("(%u)u32OriginalFileSize=%u(0x%X)\n", i, u32OriginalFileSize, u32OriginalFileSize);
            }

            DEBUG_AUDIO_LOAD_CODE( printf("u32OriginalFileSize=%u(0x%X)\n", u32OriginalFileSize,u32OriginalFileSize); );

            // Check bin file size and original size
            DEBUG_AUDIO_LOAD_CODE( printf("Src+Dst size=0x%X, %uK\n", u32BinFileFlashSize+u32OriginalFileSize,
                                                                (u32BinFileFlashSize+u32OriginalFileSize+1023)/1024); );
            // Src buf  + Dest Buf must small then u32CpuMemSize
            if( (u32BinFileFlashSize+u32OriginalFileSize) > u32CpuMemSize )
            {
                printf("\nError: Src+Dest buf size=0x%X, > %u\n", u32BinFileFlashSize+u32OriginalFileSize, u32CpuMemSize);
                return FALSE;
            }

            // Do decompress:
            //  Src =u32R2BinFileMemAddr_VA
            //  Dest = u32R2CodeMemAddr_VA_Cached
            if( FALSE == DoMsDecompression7(
                            (U8 *)u32R2BinFileMemAddr_VA,//(U8 *)(u32DecVA & NON_CACHEABLE_TO_CACHEABLE_MASK),
                            (U8 *)u32DestMemAddr_VA_Cached,//(U8 *)(u32DstVA & NON_CACHEABLE_TO_CACHEABLE_MASK),
                        #if( ENABLE_DECOMP7_USE_HK_MEMORY )
                            g_au8Decomp7TmpBuf,
                        #else
                            au8DecompTmpBuf,
                        #endif
                            u32BinFileRealSize )
              )
            {
                printf("\nError: DoMsDecompression7 fail!\n");
                return FALSE;
            }

        }
        else // MS_COMPRESS
        {

#if 0 //(CHIP_FAMILY_TYPE == CHIP_FAMILY_MAYA)

            U8 *au8DecompTmpBuf1 = NULL;
            au8DecompTmpBuf1 = (U8*)MsOS_PA2KSEG0(((AUDIO_DSPBIN_DECOMPRESS_TEMP_BUFFER_ADR & MIU1) ? (AUDIO_DSPBIN_DECOMPRESS_TEMP_BUFFER_ADR | MIU_INTERVAL) : (AUDIO_DSPBIN_DECOMPRESS_TEMP_BUFFER_ADR)));

            memcpy(&u32OriginalFileSize, (void*)(u32R2BinFileMemAddr_VA+u32BinFileRealSize-4), 4);
            DEBUG_AUDIO_LOAD_CODE( printf("u32OriginalFileSize=%u(0x%X)\n", u32OriginalFileSize,u32OriginalFileSize); );

            // Check bin file size and original size
            DEBUG_AUDIO_LOAD_CODE( printf("Src+Dst size=0x%X, %uK\n", u32BinFileFlashSize+u32OriginalFileSize,
                                                                (u32BinFileFlashSize+u32OriginalFileSize+1023)/1024); );
            // Src buf  + Dest Buf must small then u32CpuMemSize
            if( (u32BinFileFlashSize+u32OriginalFileSize) > u32CpuMemSize )
            {
                printf("\nError: Src+Dest buf size=0x%X, > %u\n", u32BinFileFlashSize+u32OriginalFileSize, u32CpuMemSize);
                return FALSE;
            }

            g_MsDecomp_u8Debug = 0;
            g_MsDecomp_u8CheckTempSize = 1;
            g_MsDecomp_u32TempSize = AUDIO_DSPBIN_DECOMPRESS_TEMP_BUFFER_LEN;

            if( FALSE == DoMsDecompression(
                            (U8 *)u32R2BinFileMemAddr_VA,//(U8 *)(u32DecVA & NON_CACHEABLE_TO_CACHEABLE_MASK),
                            (U8 *)u32DestMemAddr_VA_Cached,//(U8 *)(u32DstVA & NON_CACHEABLE_TO_CACHEABLE_MASK),
                            au8DecompTmpBuf1,
                            u32BinFileRealSize )
              )
            {
                printf("\nError: DoMsDecompression fail!\n");
                return FALSE;
            }

#else

            printf("\n!!ERROR!! Can't use this compress mode!\n");
            return FALSE;
#endif

        }

        // Flush memory~
        MsOS_Dcache_Flush( (MS_U32)(u32DestMemAddr_VA_Cached), ALIGN_16(u32OriginalFileSize) );
        MsOS_FlushMemory();

    #if 0 // Use CRC check if ok
        {
            U32 u32CRC_Flash;
            U32 u32CRC_Dram;

            u32CRC_Flash = MDrv_BDMA_CRC32( 0x190000, u32OriginalFileSize,
                            BDMA_CRC32_POLY, 0xFFFFFFFF, E_BDMA_SRCDEV_FLASH,FALSE);

            u32CRC_Dram = MDrv_BDMA_CRC32( u32DestMemAddr, u32OriginalFileSize,
                            BDMA_CRC32_POLY, 0xFFFFFFFF, E_BDMA_SRCDEV_MIU0,FALSE);

            printf("u32CRC_Flash=0x%X\n", u32CRC_Flash);

            printf("u32CRC_Dram =0x%X\n", u32CRC_Dram);
        }
    #endif

    }
    else if( 0 == stBinInfo.B_IsComp ) // No compress
    {
        MApi_BDMA_CopyFromResource(u32BinFileFlashAddr, MsOS_PA2KSEG1(u32DestMemAddr), u32BinFileFlashSize);
        //MDrv_SERFLASH_CopyHnd(u32BinFileFlashAddr, u32DestMemAddr, u32BinFileFlashSize, E_SPIDMA_DEV_MIU0, SPIDMA_OPCFG_DEF);
    }

    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END(););

    return TRUE;
}
#endif

#if (ENABLE_DOLBY_BULLETIN24)
#define DBG_BULLETIN24(x)   //x
#define SAD_LEN 3   //length of short audio descriptor is 3 bytes
static DolbyBulletinEDIDType _enCurrentEDIDType = DolbyBulletin_EDID_Type1;
//static U8 _u8SAD_AC3[SAD_LEN] = 0;
//static U8 _u8SAD_AAC[SAD_LEN] = 0;
//static U8 _u8SAD_DTS[SAD_LEN] = 0;
static U8 _u8SAD_DDP[SAD_LEN] = {0};
static BOOLEAN _IsDDP_SAD_Exist(void)
{
    if (_u8SAD_DDP[0] != 0)
    {
        return TRUE;
    }
    return FALSE;
}
static void _Store_DDP_SAD(U8* pu8SAD)
{
    DBG_BULLETIN24(printf("%s()\n", __FUNCTION__));
    memset(_u8SAD_DDP, 0x00, SAD_LEN);
    memcpy((void*)_u8SAD_DDP, (void*)pu8SAD, SAD_LEN);
}
static void _Remove_DDP_SAD(void)
{
    DBG_BULLETIN24(printf("%s()\n", __FUNCTION__));
    memset(_u8SAD_DDP, 0x00, SAD_LEN);
}
void msAPI_DolbyBulletin24_process_EDID(void)
{
    if (_enCurrentEDIDType == DolbyBulletin_EDID_Type2)
    {
        if ((DB_HDMI_SETTING.g_bHdmiCecMode == ENABLE)
            && (DB_HDMI_SETTING.g_enHDMIARC == ENABLE)
            && (stGenSetting.g_SysSetting.fSPDIFMODE == 1)
            )
        {
            if (_IsDDP_SAD_Exist() == FALSE)
            {
                //restore to Type1
                _enCurrentEDIDType = DolbyBulletin_EDID_Type1;
                MApi_XC_UpdateEDID(FALSE, _u8SAD_DDP);
            }
        }
        else
        {
            //restore to Type1
            _enCurrentEDIDType = DolbyBulletin_EDID_Type1;
            MApi_XC_UpdateEDID(FALSE, _u8SAD_DDP);
        }
    }
    else
    {
        if ((DB_HDMI_SETTING.g_bHdmiCecMode == ENABLE)
            && (DB_HDMI_SETTING.g_enHDMIARC == ENABLE)
            && (stGenSetting.g_SysSetting.fSPDIFMODE == 1)
            )
        {
            if (_IsDDP_SAD_Exist())
            {
                //set to Type2
                _enCurrentEDIDType = DolbyBulletin_EDID_Type2;
                MApi_XC_UpdateEDID(TRUE, _u8SAD_DDP);
            }
        }
    }
}
void msAPI_DolbyBulletin24_Init(void)
{
    Digital_Out_Device_Capability_t stSAD;
    DBG_BULLETIN24(printf("%s()\n", __FUNCTION__));
    memset((void*)&stSAD, 0x00, sizeof(Digital_Out_Device_Capability_t));
    MApi_AUDIO_DigitalOut_SetDeviceCapability(DIGITAL_HDMI_ARC_OUTPUT, CODEC_DD, &stSAD);
    MApi_AUDIO_DigitalOut_SetDeviceCapability(DIGITAL_HDMI_ARC_OUTPUT, CODEC_AAC, &stSAD);
    MApi_AUDIO_DigitalOut_SetDeviceCapability(DIGITAL_HDMI_ARC_OUTPUT, CODEC_DTS, &stSAD);
    stSAD.support_codec = 2;    //set DDP to unsupport in default since lots of old amplifier may not response to CEC: E_MSG_SAC_REPORT_SHORT_AUDIO_DESCRIPTOR
    MApi_AUDIO_DigitalOut_SetDeviceCapability(DIGITAL_HDMI_ARC_OUTPUT, CODEC_DDP, &stSAD);

}
void msAPI_DolbyBulletin24_receive_SAD(U8* pu8SAD, U8 u8Len)
{
    U8 idx;
    DBG_BULLETIN24(printf("%s()\n", __FUNCTION__));
    for (idx = 0; idx < u8Len; idx+=SAD_LEN)
    {
        DBG_BULLETIN24(printf("[%02x][%02x][%02x]\n", pu8SAD[idx], pu8SAD[idx+1], pu8SAD[idx+2]));
        Digital_Out_Device_Capability_t stSAD;
        AUDIO_FORMAT_CODE eCodec = (pu8SAD[idx]&0x78)>>3;

        memset(&stSAD, 0, sizeof(Digital_Out_Device_Capability_t));
        stSAD.support_codec = 1;    // 1: support
        stSAD.support_ch = pu8SAD[idx]&0x07;
        stSAD.support_samplerate = pu8SAD[idx+1]&0x7F;
        stSAD.support_SAD_byte3 = pu8SAD[idx+2];
        MApi_AUDIO_DigitalOut_SetDeviceCapability(DIGITAL_HDMI_ARC_OUTPUT, eCodec,&stSAD);

        if (eCodec == CODEC_DDP)
        {
            _Store_DDP_SAD(&pu8SAD[idx]);
            break;
        }
    }
    msAPI_DolbyBulletin24_process_EDID();
}

void msAPI_DolbyBulletin24_remove_SAD(void)
{
    Digital_Out_Device_Capability_t stSAD;
    DBG_BULLETIN24(printf("%s()\n", __FUNCTION__));
    _Remove_DDP_SAD();
    msAPI_DolbyBulletin24_process_EDID();

    memset((void*)&stSAD, 0x00, sizeof(Digital_Out_Device_Capability_t));
    MApi_AUDIO_DigitalOut_SetDeviceCapability(DIGITAL_HDMI_ARC_OUTPUT, CODEC_DD, &stSAD);
    MApi_AUDIO_DigitalOut_SetDeviceCapability(DIGITAL_HDMI_ARC_OUTPUT, CODEC_AAC, &stSAD);
    MApi_AUDIO_DigitalOut_SetDeviceCapability(DIGITAL_HDMI_ARC_OUTPUT, CODEC_DTS, &stSAD);
    MApi_AUDIO_DigitalOut_SetDeviceCapability(DIGITAL_HDMI_ARC_OUTPUT, CODEC_DDP, &stSAD);
}


#endif

#ifdef BENCH_CODE_USAGE
////////////////////////////////////////////////////////////////////////////////
/// @brief \b Function \b Description: This routine is used to Audio_Bench_Test.
/// @param <IN>       \b NONE  :
/// @param <OUT>       \b NONE  :
/// @param <RET>       \b NONE :
////////////////////////////////////////////////////////////////////////////////
void msAPI_AUD_Bench_Check_Main(void)
{
    printf("\033[1;32m [%s] [ CHECK START ]\033[0m \n",__FUNCTION__);

    MS_BOOL bRet = TRUE;
    MS_U8   Bench_Audio_Test_Stage = 0;

    if (bRet == TRUE)
    {
        Bench_Audio_Test_Stage++;
        bRet = msAPI_AUD_Bench_Check_Counter();
    }

    if (bRet == FALSE)
    {
        printf("\033[1;31m [%s] [ CHECK NG NG NG !!! ] [ NG Stage = %u]\033[0m \n", __FUNCTION__,Bench_Audio_Test_Stage);
        while(1);
    }
    else
    {
        printf("\033[1;32m [%s] [ CHECK OK OK OK !!! ]\033[0m \n",__FUNCTION__);
    }
}

BOOLEAN msAPI_AUD_Bench_Check_Counter(void)
{
    MS_U8  u8BenchCurrentDecWhile, u8BenchCurrentDecTimer, u8BenchCurrentSeWhile, u8BenchCurrentSeISR;
    MS_U8  u8BenchCheckTimes = 15;
    MS_U8  u8BenchCheckCount = 0;
    MS_U32 u32Delay_Counter = 0;

    static MS_U8  u8BenchLastDecWhile = 1;
    static MS_U8  u8BenchLastDecTimer = 1;
    static MS_U8  u8BenchLastSeWhile = 1;
    static MS_U8  u8BenchLastSeISR = 1;
    static MS_U8  u8BenchDecWhileFailCount = 0;
    static MS_U8  u8BenchDecTimerFailCount = 0;
    static MS_U8  u8BenchSeWhileFailCount = 0;
    static MS_U8  u8BenchSeISRFailCount = 0;

    do
    {
        MsOS_DelayTask(10); // check counter per 10 ms
        u8BenchCheckCount++;

        if((u8BenchSeWhileFailCount >= 7) || (u8BenchSeISRFailCount >= 7)||(u8BenchDecWhileFailCount>=7)||(u8BenchDecTimerFailCount>=7))
        {
            u32Delay_Counter = u8BenchLastDecWhile + u8BenchLastDecTimer + u8BenchLastSeWhile + u8BenchLastSeISR;
            MsOS_DelayTaskUs(u32Delay_Counter);
        }

        u8BenchCurrentDecWhile =  MDrv_AUDIO_ReadDspCounter(DSP_DEC_MAIN_COUNTER);
        u8BenchCurrentDecTimer = MDrv_AUDIO_ReadDspCounter(DSP_DEC_TIMER_COUNTER);
        u8BenchCurrentSeWhile = MDrv_AUDIO_ReadDspCounter(DSP_SE_MAIN_COUNTER);
        u8BenchCurrentSeISR = MDrv_AUDIO_ReadDspCounter(DSP_SE_ISR_COUNTER);

        // Checking Decoder DSP counter
        if ( u8BenchCurrentDecWhile - u8BenchLastDecWhile == 0 )
        {
            u8BenchDecWhileFailCount++;
        }
        else
        {
            u8BenchDecWhileFailCount=0;
        }

        if ( u8BenchCurrentDecTimer - u8BenchLastDecTimer == 0 )
        {
            u8BenchDecTimerFailCount++;
        }
        else
        {
            u8BenchDecTimerFailCount = 0;
        }

        if ( u8BenchCurrentSeWhile - u8BenchLastSeWhile == 0 )
        {
            u8BenchSeWhileFailCount++;
        }
        else
        {
            u8BenchSeWhileFailCount = 0;
        }

        if ( u8BenchCurrentSeISR - u8BenchLastSeISR == 0 )
        {
            u8BenchSeISRFailCount++;
        }
        else
        {
            u8BenchSeISRFailCount = 0;
        }

        if(((u8BenchSeWhileFailCount+u8BenchSeISRFailCount)==3)||((u8BenchDecWhileFailCount+u8BenchDecTimerFailCount)==3))
        {
            MsOS_DelayTask(1);    //Fix counter mis-detection problem
        }
        else if(((u8BenchSeWhileFailCount+u8BenchSeISRFailCount)==7)||((u8BenchDecWhileFailCount+u8BenchDecTimerFailCount)==7))
        {
            MsOS_DelayTask(1);
        }

        if ( (u8BenchSeWhileFailCount >= 10) || (u8BenchSeISRFailCount >= 10) )
        {
            return FALSE;
        }
        else if ((u8BenchDecWhileFailCount>=10)||(u8BenchDecTimerFailCount>=10))//Checking if rebooting Decoder DSP
        {
            return FALSE;
        }

        // save status
        u8BenchLastDecWhile = u8BenchCurrentDecWhile;
        u8BenchLastDecTimer = u8BenchCurrentDecTimer;
        u8BenchLastSeWhile = u8BenchCurrentSeWhile;
        u8BenchLastSeISR = u8BenchCurrentSeISR;
    }while(u8BenchCheckCount < u8BenchCheckTimes);

    return TRUE;

}
#endif

#undef _MSAPI_AUDIO_C_

