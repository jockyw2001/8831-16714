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
#define MAPP_TTSCONTROLHANDLER_C
////////////////////////////////////////////////////////////////////////////////
/// @file MApp_TTSControlHandler.c
/// @author MStar Semiconductor Inc.
/// @brief Idle mode handler for APP layer
////////////////////////////////////////////////////////////////////////////////

/******************************************************************************/
/*                            Header Files                                    */
/******************************************************************************/
#include <stdlib.h>
#include <string.h>
#include "Board.h"

#if ENABLE_ATSC_TTS

#include "MsCommon.h"
#include "Utl.h"
#include "libTTS.h"
#include "tts.h"
#include "Panel.h"
#include "MApp_TopStateMachine.h"
#include "MApp_GlobalVar.h"
#include "MApp_GlobalSettingSt.h"
#include "MApp_TTSControlHandler.h"
#include "msAPI_VD.h"
#include "msAPI_Timer.h"
#include "apiAUDIO.h"
#include "MApp_Audio.h"
#include "msAPI_OSD.h"
#include "MApp_ZUI_Main.h"
#include "MApp_VChip.h"
#include "MApp_ZUI_APIcommon.h"
#include "MApp_ZUI_APIstrings.h"
#include "MApp_ZUI_APIwindow.h"
#include "MApp_ZUI_ACTglobal.h"
#include "MApp_GlobalFunction.h"
#include "MApp_ZUI_ACTmainpage.h"
#include "OSDcp_String_EnumIndex.h"
#include "msAPI_audio.h"
#include "drvWDT.h"
#include "MApp_IR.h"

static EN_RET enTTSRetVal;
static EN_TTS_STATE enTTSState;
static U8 u8TextIDNumber;
static U8 u8TextWriteNumber;
static U8 u8AudioReadNumber;
static U32 u32AudioStartAddr;
static U32 u32TTSPlayStartTime;
static U32 u32TTSSetTextStartTime;
static U32 u32SayLen;
//static BOOLEAN bTTSIsOn;
//static BOOLEAN bTTSIsSay;
//static BOOLEAN bLongTextIn;
static U32 u32Full_20ms_audio_slices;
static U32 u32Tail_partial_audio_slice_bytes;
static U32 u8SayIndex;
static U8* pu8waveout;
static U32 u32TTSReadPoniter;
static U32 u32TTSWritePoniter;
static U32 u32TTSResetPoniter;
static U32 u32TTSCount;
#if (TTS_CHECK_OUTPUT_TIME)
U32 u32DeArr[100] = {0};
U16 u16DeArrCount;
#endif

static U16 u16LastHWND;

BOOLEANS     TTSFlag;
#define     bTTSIsOn            TTSFlag.bBOOL_0
#define     bTTSIsSay           TTSFlag.bBOOL_1
#define     bLongTextIn         TTSFlag.bBOOL_2
#define     bTTSIsDone          TTSFlag.bBOOL_3
#define     bTVIsMuted          TTSFlag.bBOOL_4
#define     g_bForcedelayFlag   TTSFlag.bBOOL_5
#define     bTTSOffSpeak        TTSFlag.bBOOL_6


#define TTS_BUFFER_NUMBER (5)

#define TTS_AUDIO_BUFFER_MAX_SIZE   (0x40000) //409600 //400KB

#define TTS_SPEAK_DELAY_TIME (120) //ms

#if TTS_IS_ON_HK
static U8 textBuffer[TTS_STRING_BUFFER_LENGTH];
#else
U8* volatile textBuffer = (U8*)(TTS_TEXT_MEM_ADR|BIT31);
#endif
#if (TTS_IS_ON_HK == 0)
static U8 u8textNum = 0;
#endif
static stTTSMBXData stTTSData[TTS_BUFFER_NUMBER];

static U8 u8DBVal = 0x0; //range from 0x00 to 0x7E , gain: +12db to   -114db

#define TTS_DBG(x)  //x



long MApp_TTS_UNI_2_UTF8(U8 *pDest, const U16*pSrc, long destLen, long sourceLen)
{
   long i = 0;
   long size_d = 0;

   if (pSrc == NULL)
   {
      return -1;
   }
   while(i < sourceLen)
   {
       if(pSrc[i] < 0x80)
       {
           if(pDest)
           {
              if(destLen<1)
                  break;
              pDest[0] = (U8)pSrc[i];
              destLen--;
              pDest++;
           }
           size_d++;
       }
      else  if(pSrc[i] < 0x800)
      {  //two byte  110x-xxxx 10xx-xxxx
           if(pDest)
           {
              if(destLen<2)
                  break;
              pDest[0] = (U8)((pSrc[i]>>6)&0x1F)|0xC0;
              pDest[1] = (U8)(pSrc[i]&0x3F)|0x80;
              destLen -= 2;
              pDest += 2;
           }
           size_d += 2;
      }
      else
      {  //three byte  1110-xxxx 10xx-xxxx 10xx-xxxx
           if(pDest)
           {
              if(destLen<3)
                  break;
              pDest[0] = (U8)((pSrc[i]>>12)&0x0F)|0xE0;
              pDest[1] = (U8)((pSrc[i]>>6)&0x3F)|0x80;
              pDest[2] = (U8)(pSrc[i]&0x3F)|0x80;
              destLen -= 3;
              pDest += 3;
           }
           size_d += 3;
      }
      i++;
   }

   return size_d;
}


static void MApp_TTS_ProcessUserInput(void)
{
    MApp_ProcessUserInput();

    if (u8KeyCode != KEY_NULL)
    {
        enTTSState = STATE_TTS_FINISH;
    }
}

void MApp_TTSControlHandler_Init(void)
{
    enTTSState = STATE_TTS_INIT;
    u8TextIDNumber = 0;
    u8TextWriteNumber = 0;
    u8AudioReadNumber = 0;
    u32AudioStartAddr = TTS_MEM_SYNTHESIS_AUDIO_ADR;

    u32SayLen = 0;

    bTTSIsOn = 0;
    u16LastHWND = 0;
    bLongTextIn = FALSE;
    u32Full_20ms_audio_slices = 0;
    u32Tail_partial_audio_slice_bytes = 0;
    u8SayIndex = 0;
    pu8waveout = NULL;

    u8DBVal = 0x0C;
    memset(textBuffer, 0x0, TTS_STRING_BUFFER_LENGTH);
    memset(stTTSData, 0x0, sizeof(stTTSData));
    memset((void *)(u32AudioStartAddr), 0x0, TTS_MEM_SYNTHESIS_AUDIO_LEN);

    u32TTSPlayStartTime = 0;
    u32TTSSetTextStartTime = 0;

    u32TTSReadPoniter = 0;
    u32TTSWritePoniter = 0;
    u32TTSResetPoniter = 0;
    bTTSIsDone = FALSE;
    bTTSIsSay = FALSE;
    bTVIsMuted = FALSE;
    bTTSOffSpeak = FALSE;
    u32TTSCount = 0;
}


void MApp_TTSControlHandler_Reset(void)
{
    u8TextIDNumber = 0;
    u8TextWriteNumber = 0;
    u8AudioReadNumber = 0;
#if TTS_IS_ON_HK
    u32AudioStartAddr = _PA2VA(TTS_MEM_SYNTHESIS_AUDIO_ADR);
#else
    u32AudioStartAddr = (TTS_MEM_SYNTHESIS_AUDIO_ADR|BIT31);
    u8textNum = 0;
#endif

    u32SayLen = 0;

    bTTSIsOn = 0;

    u8DBVal = 0x0C;
    bLongTextIn = FALSE;
    u32TTSPlayStartTime = 0;
    u32TTSSetTextStartTime = 0;
    u32Full_20ms_audio_slices = 0;
    u32Tail_partial_audio_slice_bytes = 0;
    u8SayIndex = 0;
    pu8waveout = NULL;

    u32TTSReadPoniter = 0;
    u32TTSWritePoniter = 0;
    u32TTSResetPoniter = 0;
    bTTSIsDone = FALSE;
    bTTSIsSay = FALSE;
    u32TTSCount = 0;
    if (stGenSetting.g_SysSetting.bTTSOn == TRUE)
    {
        bTTSOffSpeak = FALSE;
    }
    memset(textBuffer, 0x0, TTS_STRING_BUFFER_LENGTH);
    memset(stTTSData, 0x0, sizeof(stTTSData));
    memset((void *)(u32AudioStartAddr), 0x0, TTS_MEM_SYNTHESIS_AUDIO_LEN);
}

void MApp_TTSControlSetInputStringID(U16 u16ID)
{
    TTS_DBG(printf("MApp_TTSControlSetInputStringID=%d\n", u16ID));

    stTTSData[u8TextIDNumber].enTTSCmd = MB_TTS_ENGINE_SET_TEXT_CMD;
    stTTSData[u8TextIDNumber].enTextType = TYPE_TEXT_STRING_ID;
    stTTSData[u8TextIDNumber].u8Data1 = (U8)((u16ID & 0xFF00) >> 8);
    stTTSData[u8TextIDNumber].u8Data2 = (U8)(u16ID & 0x00FF);

    if (++u8TextIDNumber >= TTS_BUFFER_NUMBER)
        u8TextIDNumber=0;

    enTTSState = STATE_TTS_TEXT_ID_IN;

    u32TTSSetTextStartTime = msAPI_Timer_GetTime0();
}

void MApp_TTSControlSetInputHWndID(U16 u16ID)
{
    TTS_DBG(printf("MApp_TTSControlSetInputHWndID=%d\n", u16ID));

    stTTSData[u8TextIDNumber].enTTSCmd = MB_TTS_ENGINE_SET_TEXT_CMD;
    stTTSData[u8TextIDNumber].enTextType = TYPE_TEXT_HWND_ID;
    stTTSData[u8TextIDNumber].u8Data1 = (U8)((u16ID & 0xFF00) >> 8);
    stTTSData[u8TextIDNumber].u8Data2 = (U8)(u16ID & 0x00FF);

    if (++u8TextIDNumber >= TTS_BUFFER_NUMBER)
        u8TextIDNumber=0;

    enTTSState = STATE_TTS_TEXT_ID_IN;

    u32TTSSetTextStartTime = msAPI_Timer_GetTime0();
}

void MApp_TTSControlSetInputText(U16* str, U16 len)
{
    if ((len <= TTS_TEXT_BUF_LEN) && (str != NULL))
    {
        enTTSState = STATE_TTS_TEXT_IN;
#if (TTS_IS_ON_HK == 0)
        u32TTSPlayStartTime = msAPI_Timer_GetTime0();
        while (TTS_MBXReadByte(TTS_MBX_CMDID_IDX) != MB_TTS_ENGINE_CMD_NONE)
        {
            if(msAPI_Timer_DiffTimeFromNow(u32TTSPlayStartTime) >= TTS_ENGINE_ACK_TIME)
            {
                break;
            }
        }
#endif
        memset(textBuffer+u8TextWriteNumber*TTS_TEXT_BUF_LEN, 0x0, TTS_TEXT_BUF_LEN);
        MApp_TTS_UNI_2_UTF8((textBuffer+u8TextWriteNumber*TTS_TEXT_BUF_LEN), (U16*)str, TTS_TEXT_BUF_LEN, len);

        TTS_DBG(printf("\033[42;30m TTS input text=%s len=%d u8TextWriteNumber=%d\033[0m\n", (textBuffer+u8TextWriteNumber*TTS_TEXT_BUF_LEN), len, u8TextWriteNumber));
        MApp_TTSControlSetLanguage(stGenSetting.g_SysSetting.Language);
#if (TTS_IS_ON_HK == 0)
        u32TTSPlayStartTime = msAPI_Timer_GetTime0();
        while (TTS_MBXReadByte(TTS_MBX_CMDID_IDX) != MB_TTS_ENGINE_CMD_NONE)
        {
            if(msAPI_Timer_DiffTimeFromNow(u32TTSPlayStartTime) >= TTS_ENGINE_ACK_TIME)
            {
                break;
            }
        }
#endif

        if (++u8TextWriteNumber >= TTS_BUFFER_NUMBER)
            u8TextWriteNumber=0;
    }
    else if ((len > TTS_TEXT_BUF_LEN) && (str != NULL))
    {
        MApp_TTSControlHandler_Reset();
        MApp_TTS_UNI_2_UTF8(textBuffer, (U16*)str, TTS_STRING_BUFFER_LENGTH, len);
        enTTSState = STATE_TTS_LONG_TEXT_IN;
    }
}


U8 MApp_TTSControlSplitLongText(U8* str, U16 len)
{
    if (len == 0)
        return 0;

    U16 i = len-1;
    if (str != NULL)
    {
        if (*(str+len-1) > 0x20)
        {
            while(*(str+i) > 0x20)
            {
                if (i >0)
                    i--;
                else
                    break;

                if (*(str+i) <= 0x20)
                    break;
            }
        }
    }

    return i;
}
void MApp_TTSControlSayLongText(void)
{
#if (TTS_IS_ON_HK == 0)
    u32TTSPlayStartTime = msAPI_Timer_GetTime0();
    while (TTS_MBXReadByte(TTS_MBX_TYPE_IDX) != MB_TTS_ENGINE_SET_SAY_ACK )
    {
        if(msAPI_Timer_DiffTimeFromNow(u32TTSPlayStartTime) >= TTS_ENGINE_ACK_TIME)
        {
            bLongTextIn = FALSE;

            break;
        }
    }
    TTS_DBG(printf("02msAPI_Timer_GetTime0()=%ld\n",msAPI_Timer_GetTime0()));

#endif
     bLongTextIn = TRUE;

}

void MApp_TTSControlSetTextAndSay(U16* str, U16 len)
{
    if (stGenSetting.g_SysSetting.bTTSOn == FALSE)
    {
        MApp_TTSControlHandler_Reset();
        return;
    }

    bTTSIsSay = TRUE;

    u8TextWriteNumber = 0;
    u8AudioReadNumber = 0;
#if (TTS_IS_ON_HK == 0)
    u32TTSPlayStartTime = msAPI_Timer_GetTime0();
    while (TTS_MBXReadByte(TTS_MBX_CMDID_IDX) != MB_TTS_ENGINE_CMD_NONE)
    {
        if(msAPI_Timer_DiffTimeFromNow(u32TTSPlayStartTime) >= TTS_ENGINE_ACK_TIME)
        {
            break;
        }
    }
#endif
    memset(textBuffer, 0x0, TTS_STRING_BUFFER_LENGTH);
    MApp_TTS_UNI_2_UTF8(textBuffer, (U16*)str, TTS_STRING_BUFFER_LENGTH, len);

    TTS_DBG(printf("\033[42;30m TTS text&say=%s len=%d u8TextWriteNumber=%d\033[0m\n", textBuffer, len, u8TextWriteNumber));
    MApp_TTSControlSetLanguage(stGenSetting.g_SysSetting.Language);

#if (TTS_IS_ON_HK == 0)
        u32TTSPlayStartTime = msAPI_Timer_GetTime0();
        while (TTS_MBXReadByte(TTS_MBX_CMDID_IDX) != MB_TTS_ENGINE_CMD_NONE)
        {
            if(msAPI_Timer_DiffTimeFromNow(u32TTSPlayStartTime) >= TTS_ENGINE_ACK_TIME)
            {
                break;
            }
        }
#endif
    MApp_TTSAudioPlayInit();
    u32TTSCount = 0;

    while(genTTSNext(&u32TTSCount) == TTS_RET_OK)
    {
        MApp_TTS_ProcessUserInput();
        if (enTTSState == STATE_TTS_FINISH)
            goto EXIT_SPEAK;
    }

    if (u32TTSCount > 0)
    {
        u32Full_20ms_audio_slices = u32TTSCount/STEREO_20MS_DATA_BYTES;
        u32Tail_partial_audio_slice_bytes = u32TTSCount%STEREO_20MS_DATA_BYTES;
        u8SayIndex = 0;
        u32TTSPlayStartTime = msAPI_Timer_GetTime0();
        while(u8SayIndex < u32Full_20ms_audio_slices)
        {
            if(msAPI_Timer_DiffTimeFromNow(u32TTSPlayStartTime) >= TTS_AUDIO_PLAY_DELAYMS)
            {
                u8SayIndex++;
                u32TTSPlayStartTime = msAPI_Timer_GetTime0();
                MApi_AUDIO_DmaReader_WritePCM((void *)(pu8waveout+u8SayIndex*STEREO_20MS_DATA_BYTES), STEREO_20MS_DATA_BYTES);
            }
        }
        if(u32Tail_partial_audio_slice_bytes > 0)
        {
            msAPI_Timer_Delayms(TTS_ADUIO_PLAY_REMAINS_DELAYMS);
            MApi_AUDIO_DmaReader_WritePCM((void *)(pu8waveout+u32Full_20ms_audio_slices*STEREO_20MS_DATA_BYTES), u32Tail_partial_audio_slice_bytes);
        }

    }

EXIT_SPEAK:
    enTTSState = STATE_TTS_FINISH;
    MApi_AUDIO_SetCommAudioInfo(Audio_Comm_infoType_DMAReader_Command, 0, 0);
    MApp_TTSControlHandler_Reset();

    if (STATE_TOP_SCAN != MApp_TopStateMachine_GetTopState())
    {
    #if TTS_MUTE_BGM
        if (!(IsATVInUse() && !IsVDHasSignal()))
        {
            msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_TTS_Background_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
            //MApi_AUDIO_SetMixModeMute(E_AUDIO_INFO_GAME_IN, GAME1_VOL, FALSE);
        }
    #else
        MApi_AUDIO_SetMixModeVolume(E_AUDIO_INFO_GAME_IN, GAME1_VOL, u8DBVal, 0);
    #endif
    }
    enTTSRetVal = EXIT_TTS_EXIT;

    bTTSIsSay = FALSE;
}

BOOLEAN MApp_TTSControlIsTextIn(void)
{
    if ((enTTSState ==STATE_TTS_TEXT_IN) || (enTTSState == STATE_TTS_LONG_TEXT_IN))
        return TRUE;
    else
        return FALSE;
}

void MApp_TTSControlSetOn(BOOLEAN bOnOff)
{
	bTTSIsOn = bOnOff;
}

U8 MApp_TTSControlIsOn(void)
{
	return bTTSIsOn;
}

U8* MApp_TTSControlGetInputText(void)
{
	return NULL;
}
/*
void MApp_TTSControlSayText(U8* text, U16 text_len, U8* waveout, U32 waveout_len)
{

}
*/

void MApp_TTSControlSay(U8* text, U16 text_len, U8* waveout, U32 waveout_len)
{
#if TTS_IS_ON_HK
    int result = say((unsigned char*) text, (unsigned int)text_len, (unsigned char*)waveout, (unsigned int)waveout_len);

    if (result == TTS_RET_OK)
    {
        pu8waveout = waveout;
    }
    else
    {
        enTTSState = STATE_TTS_FINISH;
    }

#else // run on SecureR2
    TTS_DBG(printf("TTS MApp_TTSControlSay %s  u8AudioReadNumber=%d u8TextWriteNumber=%d waveout=0x%lx\n", text, u8AudioReadNumber, u8TextWriteNumber,(U32)waveout));

    TTS_MBXWriteByte(TTS_MBX_CMDID_IDX, MB_TTS_ENGINE_SAY_CMD);
    TTS_MBXWriteByte(TTS_MBX_DATA1_IDX, (U8)(((U32)text & 0xFF000000) >> 24));
    TTS_MBXWriteByte(TTS_MBX_DATA2_IDX, (U8)(((U32)text & 0x00FF0000) >> 16));
    TTS_MBXWriteByte(TTS_MBX_DATA3_IDX, (U8)(((U32)text & 0x0000FF00) >> 8));
    TTS_MBXWriteByte(TTS_MBX_DATA4_IDX, (U8)((U32)text & 0x000000FF));

    TTS_MBXWriteByte(TTS_MBX_DATA5_IDX, (U8)(((U32)waveout & 0xFF000000) >> 24));
    TTS_MBXWriteByte(TTS_MBX_DATA6_IDX, (U8)(((U32)waveout & 0x00FF0000) >> 16));
    TTS_MBXWriteByte(TTS_MBX_DATA7_IDX, (U8)(((U32)waveout & 0x0000FF00) >> 8));
    TTS_MBXWriteByte(TTS_MBX_DATA8_IDX, (U8)((U32)waveout & 0x000000FF));

#endif
}

void MApp_TTSAudioPlayInit(void)
{

    pu8waveout = (U8*)u32AudioStartAddr;

    if (bLongTextIn)
    {
        MApp_TTSControlSay(textBuffer, TTS_STRING_BUFFER_LENGTH, (U8*)pu8waveout, TTS_MEM_SYNTHESIS_AUDIO_LEN);
    }
    else
    {
        MApp_TTSControlSay((textBuffer+u8AudioReadNumber*TTS_TEXT_BUF_LEN), TTS_TEXT_BUF_LEN, (U8*)pu8waveout, TTS_MEM_SYNTHESIS_AUDIO_LEN);
    }


    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_TTS_Background_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
    //MApi_AUDIO_SetMixModeMute(E_AUDIO_INFO_GAME_IN, PCM_VOL, FALSE);

    if (*(textBuffer+u8AudioReadNumber*TTS_TEXT_BUF_LEN) != 0x0)
    {
        MApi_AUDIO_SetSourceInfo(E_AUDIO_INFO_GAME_IN);

        if (STATE_TOP_SCAN != MApp_TopStateMachine_GetTopState())
        {
        #if TTS_MUTE_BGM
            if (!(IsATVInUse() && !IsVDHasSignal()))
            {
                msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_TTS_Background_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                //MApi_AUDIO_SetMixModeMute(E_AUDIO_INFO_GAME_IN, GAME1_VOL, TRUE);
            }
        #else
            MApi_AUDIO_SetMixModeVolume(E_AUDIO_INFO_GAME_IN, GAME1_VOL, 0x20, 0);
        #endif
        }
        MApi_AUDIO_DmaReader_Init(SAMPLE_RATE_16000);
        MApi_AUDIO_SetCommAudioInfo(Audio_Comm_infoType_DMAReader_Command, 1, 0);
        u32TTSPlayStartTime = msAPI_Timer_GetTime0();
        u8SayIndex = 0;
        bTTSIsDone =  FALSE;

        enTTSState = STATE_TTS_AUDIO_PLAY;
        memset((textBuffer+u8AudioReadNumber*TTS_TEXT_BUF_LEN), 0x0, TTS_TEXT_BUF_LEN);
    }
    else
    {
        enTTSState = STATE_TTS_FINISH;
    }

#if (TTS_IS_ON_HK == 0)
    TTS_MBXWriteByte(TTS_MBX_TYPE_IDX, MB_TTS_ENGINE_CMD_NONE);
#endif

}


void MApp_TTSAudioPlay(void)
{
    if ((STATE_TTS_AUDIO_PLAY != enTTSState) || (bTTSIsSay))
    {
        return;
    }

    S16 s16Ret = TTS_RET_DONE;
    BOOLEAN bTTSGen = TRUE;

    if (u32TTSReadPoniter > u32TTSWritePoniter)
    {
        if ((u32TTSReadPoniter - u32TTSWritePoniter)  <= (STEREO_20MS_DATA_BYTES*TTS_GEN_BLOCK_NUMBER))
        {
            bTTSGen = FALSE;
        }
    }
    else if (u32TTSReadPoniter < u32TTSWritePoniter)
    {
            if ((u32TTSWritePoniter - u32TTSReadPoniter)  >= (STEREO_20MS_DATA_BYTES*TTS_GEN_BLOCK_NUMBER))
            {
                bTTSGen = FALSE;
            }
    }

    if (!bTTSIsDone)
    {
        if (bTTSGen)
        {
            s16Ret = genTTSNext(&u32TTSCount);
            if (s16Ret == TTS_RET_OK)
            {
                u32TTSWritePoniter = u32TTSCount;
                u32TTSCount = 0;
            }
        }
    }

    if ((s16Ret != TTS_RET_OK) && (bTTSGen))
    {
         bTTSIsDone = TRUE;
    }
#if (TTS_CHECK_OUTPUT_TIME)
    U32 u32t1 = 0;
    u32t1 = MDrv_TIMER_GetUs(E_TIMER_1);
#endif
    if ( (u32TTSReadPoniter < u32TTSWritePoniter))
    {
        U32 u32TTSLen = u32TTSWritePoniter - u32TTSReadPoniter;
        U32 u32AudSize = MApi_AUDIO_GetCommAudioInfo(Audio_Comm_infoType_DMAReader_BufferLevel);
        u32AudSize = AUDIO_DSP_BUFFER_SIZE - u32AudSize;
        if (u32AudSize >STEREO_20MS_DATA_BYTES)
        {
           if (u32TTSLen < STEREO_20MS_DATA_BYTES)
           {
                MApi_AUDIO_DmaReader_WritePCM((void *)((pu8waveout)+u32TTSReadPoniter), u32TTSLen);

                u32TTSReadPoniter += u32TTSLen;
            }
            else
            {
                MApi_AUDIO_DmaReader_WritePCM((void *)((pu8waveout)+u32TTSReadPoniter), STEREO_20MS_DATA_BYTES);
                u32TTSReadPoniter += STEREO_20MS_DATA_BYTES;
            }
        }
    }
    else if ( (u32TTSReadPoniter > u32TTSWritePoniter))
    {
        U32 u32TTSLen = TTS_MEM_SYNTHESIS_AUDIO_LEN - u32TTSReadPoniter;
        U32 u32AudSize = MApi_AUDIO_GetCommAudioInfo(Audio_Comm_infoType_DMAReader_BufferLevel);
        u32AudSize = AUDIO_DSP_BUFFER_SIZE - u32AudSize;
        if (u32AudSize >STEREO_20MS_DATA_BYTES)
        {
            if (u32TTSLen < STEREO_20MS_DATA_BYTES)
            {
                MApi_AUDIO_DmaReader_WritePCM((void *)((pu8waveout)+u32TTSReadPoniter), u32TTSLen);
                u32TTSReadPoniter += u32TTSLen;

                U32 u32Remained = STEREO_20MS_DATA_BYTES - u32TTSLen;
                if (u32Remained > 0)
                {
                    u32TTSReadPoniter = 0;
                    MApi_AUDIO_DmaReader_WritePCM((void *)((pu8waveout)+u32TTSReadPoniter), u32Remained);
                    u32TTSReadPoniter += u32Remained;
                }
          }
          else
          {
                MApi_AUDIO_DmaReader_WritePCM((void *)((pu8waveout)+u32TTSReadPoniter), STEREO_20MS_DATA_BYTES);
                u32TTSReadPoniter += STEREO_20MS_DATA_BYTES;
          }
        }
    }
    TTS_DBG(printf("w=%d r=%d ret=%d\n", u32TTSWritePoniter, u32TTSReadPoniter, s16Ret));
    if ((s16Ret != TTS_RET_OK) && (u32TTSReadPoniter == u32TTSWritePoniter))
    {
        if (++u8AudioReadNumber >= TTS_BUFFER_NUMBER)
        {
            u8AudioReadNumber = 0;
        }

        if (bLongTextIn)
        {
            u8AudioReadNumber = 0;
            bLongTextIn = FALSE;
        }

        enTTSState = STATE_TTS_AUDIO_PLAY_INIT;
        u32TTSReadPoniter = 0;
        u32TTSWritePoniter = 0;

    }
    else
    {
        if ((u32TTSReadPoniter == TTS_MEM_SYNTHESIS_AUDIO_LEN) && (u32TTSWritePoniter != u32TTSReadPoniter))
        {
            u32TTSReadPoniter = 0;
        }
    }
#if (TTS_CHECK_OUTPUT_TIME)
   if (u16DeArrCount < 100)
   {
        u32DeArr[u16DeArrCount++] = MDrv_TIMER_GetUs(E_TIMER_1) - u32t1;
   }
#endif
}

void MApp_TTSContorlStopAndFlush(void)
{
}

void MApp_TTSControlGetCapabilities(void)
{
}

EN_LANGUAGE MApp_TTSControlGetLanguage(void)
{
#if TTS_IS_ON_HK
	return (EN_LANGUAGE)get_language();
#else
    return LANGUAGE_ENGLISH;
#endif
}

U16 MApp_TTSControlGetPitch(void)
{
#if TTS_IS_ON_HK
	return (U16)get_pitch();
#else
    return 0;
#endif
}

void MApp_TTSControlGetRate(void)
{
}

void MApp_TTSControlSetLanguage(EN_LANGUAGE lang)
{
    TTS_DBG(printf("MApp_TTSControlSetLanguage(lang)=%ld\n",lang));
#if (TTS_IS_ON_HK == 1)
    switch (lang)
    {
        case LANGUAGE_FRENCH:
            set_language(TTS_LANGUAGE_FRENCH);
            break;
        case LANGUAGE_SPANISH:
            set_language(TTS_LANGUAGE_SPANISH);
            break;
        #ifdef sTriviewSupportOSDLanguage
        case LANGUAGE_GERMAN:
        		set_language(TTS_LANGUAGE_GERMAN);
        		break;
        case LANGUAGE_ITALIAN:
        		set_language(TTS_LANGUAGE_ITALIAN);
        		break;
        case LANGUAGE_PORTUGUESE:
        		set_language(TTS_LANGUAGE_PORTUGUESE);
        		break;
        case LANGUAGE_RUSSIAN:
        		set_language(TTS_LANGUAGE_RUSSIAN);
        		break;        		        		        		       
        case LANGUAGE_CHINESE:
            set_language(TTS_LANGUAGE_CHINESE);
            break;        
        #endif    
        case LANGUAGE_ENGLISH:
        default:
            set_language(TTS_LANGUAGE_ENGLISH);
            break;
    }
#else
    TTS_MBXWriteByte(TTS_MBX_DATA1_IDX, (U8)lang);
    TTS_MBXWriteByte(TTS_MBX_CMDID_IDX, MB_TTS_ENGINE_SET_LANG_CMD);
    u32TTSPlayStartTime = msAPI_Timer_GetTime0();
    while (TTS_MBXReadByte(TTS_MBX_CMDID_IDX) != MB_TTS_ENGINE_CMD_NONE)
    {
        if(msAPI_Timer_DiffTimeFromNow(u32TTSPlayStartTime) >= TTS_ENGINE_ACK_TIME)
        {
            break;
        }
    }
#endif
}

void MApp_TTSControlSetPitch(U16 u16Pitch)
{
#if TTS_IS_ON_HK
	set_pitch(u16Pitch);
#endif
}


////////////////////////////////////////////////////////////////////////////////
/// @param u8Vol1      \b : MSB 7-bit register value of 10-bit u8Volume
///                         range from 0x00 to 0x7E , gain: +12db to   -114db (-1 db per step)
////////////////////////////////////////////////////////////////////////////////
void MApp_TTSControlSetBGMVolume(U8 val)
{
    u8DBVal = val;
}

void MApp_TTSAudioPlayRemainder(void)
{
    if (enTTSState != STATE_TTS_FINISH)
    {
        return;
    }

    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_TTS_Background_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
    //MApi_AUDIO_SetMixModeMute(E_AUDIO_INFO_GAME_IN, PCM_VOL, TRUE);

    while (u32TTSReadPoniter != u32TTSWritePoniter)
    {
        TTS_DBG(printf("tts play remainder\n"));
        if ((u32TTSReadPoniter < u32TTSWritePoniter))
        {
            U32 u32TTSLen = u32TTSWritePoniter - u32TTSReadPoniter;
            U32 u32AudSize = MApi_AUDIO_GetCommAudioInfo(Audio_Comm_infoType_DMAReader_BufferLevel);
            u32AudSize = AUDIO_DSP_BUFFER_SIZE - u32AudSize;
            if (u32AudSize >STEREO_20MS_DATA_BYTES)
            {
               if (u32TTSLen < STEREO_20MS_DATA_BYTES)
               {
                    MApi_AUDIO_DmaReader_WritePCM((void *)((pu8waveout)+u32TTSReadPoniter), u32TTSLen);
                    memset((void *)((pu8waveout)+u32TTSReadPoniter), 0x0, u32TTSLen);

                    u32TTSReadPoniter += u32TTSLen;
                }
                else
                {
                    MApi_AUDIO_DmaReader_WritePCM((void *)((pu8waveout)+u32TTSReadPoniter), STEREO_20MS_DATA_BYTES);
                    memset((void *)((pu8waveout)+u32TTSReadPoniter), 0x0, STEREO_20MS_DATA_BYTES);
                    u32TTSReadPoniter += STEREO_20MS_DATA_BYTES;
                }
            }
        }
        else if ( (u32TTSReadPoniter > u32TTSWritePoniter))
        {
            U32 u32TTSLen = TTS_MEM_SYNTHESIS_AUDIO_LEN - u32TTSReadPoniter;
            U32 u32AudSize = MApi_AUDIO_GetCommAudioInfo(Audio_Comm_infoType_DMAReader_BufferLevel);
            u32AudSize = AUDIO_DSP_BUFFER_SIZE - u32AudSize;
            if (u32AudSize >STEREO_20MS_DATA_BYTES)
            {
                if (u32TTSLen < STEREO_20MS_DATA_BYTES)
                {
                    MApi_AUDIO_DmaReader_WritePCM((void *)((pu8waveout)+u32TTSReadPoniter), u32TTSLen);
                    memset((void *)((pu8waveout)+u32TTSReadPoniter), 0x0, u32TTSLen);
                    u32TTSReadPoniter += u32TTSLen;

                    U32 u32Remained = STEREO_20MS_DATA_BYTES - u32TTSLen;
                    if (u32Remained > 0)
                    {
                        u32TTSReadPoniter = 0;
                        MApi_AUDIO_DmaReader_WritePCM((void *)((pu8waveout)+u32TTSReadPoniter), u32Remained);
                        memset((void *)((pu8waveout)+u32TTSReadPoniter), 0x0, u32Remained);
                        u32TTSReadPoniter += u32Remained;
                    }
              }
              else
              {
                    MApi_AUDIO_DmaReader_WritePCM((void *)((pu8waveout)+u32TTSReadPoniter), STEREO_20MS_DATA_BYTES);
                    memset((void *)((pu8waveout)+u32TTSReadPoniter), 0x0, STEREO_20MS_DATA_BYTES);
                    u32TTSReadPoniter += STEREO_20MS_DATA_BYTES;
              }
            }
        }

        if ((u32TTSReadPoniter == TTS_MEM_SYNTHESIS_AUDIO_LEN) && (u32TTSWritePoniter != u32TTSReadPoniter))
        {
            u32TTSReadPoniter = 0;
        }
    }
}

EN_RET MApp_TTSControlHandler_Main(void)
{
    enTTSRetVal = EXIT_TTS_NULL;

    MApp_TTS_ProcessUserInput();
    if (stGenSetting.g_SysSetting.bTTSOn == FALSE)
    {
        if (g_mainpage_common == EN_COMMON_OPTION_TTS_PAGE)
        {
            if (!bTTSOffSpeak)
            {
                enTTSState = enTTSState;
            }
            else
            {
                enTTSState = STATE_TTS_FINISH;
            }
        }
        else
        {
            enTTSState = STATE_TTS_FINISH;
        }
    }

    switch(enTTSState)
    {
        case STATE_TTS_INIT:
            break;

        case STATE_TTS_TEXT_ID_IN:
        {
            TTS_DBG(printf("STATE_TTS_TEXT_ID_IN\n"));

            if(msAPI_Timer_DiffTimeFromNow(u32TTSSetTextStartTime) >= TTS_SPEAK_DELAY_TIME)
            {
                TTS_DBG(printf("msAPI_Timer_DiffTimeFromNow=%d\n", msAPI_Timer_DiffTimeFromNow(u32TTSSetTextStartTime)));
                U8 u8i = 0;

                for (u8i = 0; u8i <TTS_BUFFER_NUMBER; u8i++)
                {
                    if (stTTSData[u8i].enTTSCmd == MB_TTS_ENGINE_SET_TEXT_CMD)
                    {
                        TTS_DBG(printf("stTTSData[%d].enTextType=%d\n", u8i, stTTSData[u8i].enTextType));
                        switch (stTTSData[u8i].enTextType)
                        {
                            case TYPE_TEXT_STRING_ID:
                            {
                                U16 u16StrID =  (U16)(stTTSData[u8i].u8Data1 << 8 | stTTSData[u8i].u8Data2);
                                U16 u16BufLen;
                                u16BufLen = MApp_UiMenu_u16Strlen(MApp_ZUI_API_GetString(u16StrID));
                                MApp_TTSControlSetInputText(MApp_ZUI_API_GetString(u16StrID), u16BufLen);

                            }
                            break;

                            case TYPE_TEXT_HWND_ID:
                            {
                                U16 u16HWndID =  (U16)(stTTSData[u8i].u8Data1 << 8 | stTTSData[u8i].u8Data2);
                                U16 u16BufLen = 0;

                                if (E_OSD_AUDIO_VOLUME == MApp_ZUI_GetActiveOSD())
                                {
                                    if (HWND_VOLUME_CONFIG_TEXT == u16HWndID)
                                    {
                                        MApp_TTSControlSetInputText(MApp_ZUI_API_GetString(en_str_Volume), MApp_UiMenu_u16Strlen(MApp_ZUI_API_GetString(en_str_Volume)));
                                    }
                                }

                                if (E_OSD_EPG  != MApp_ZUI_GetActiveOSD())
                                {
                                    LPTSTR pStr = MApp_ZUI_ACT_GetDynamicText((HWND)u16HWndID);

                                    if ((E_OSD_AUDIO_VOLUME == MApp_ZUI_GetActiveOSD()) &&
                                    (HWND_VOLUME_CONFIG_TEXT == u16HWndID))
                                    {
                                        u16BufLen = MApp_UiMenu_u16Strlen(pStr);
                                        char pData[TTS_TEXT_BUF_LEN] = {0};
                                        if (u16BufLen > 0)
                                        {
                                            U8* pVol = malloc(u16BufLen);
                                            if (pVol != NULL)
                                            {
                                                MApp_U16StringToU8String(pStr, pVol, u16BufLen);
                                                U16 u16TmpLen = strlen(TTS_SPEAK_NUMBER_CARDINAL)+u16BufLen+strlen(TTS_SPEAK_TAG_END);
                                                snprintf(pData,u16TmpLen, "%s%s%s", TTS_SPEAK_NUMBER_CARDINAL, (char*)pVol, TTS_SPEAK_TAG_END);
                                                LPTSTR pStr2 = MApp_ZUI_API_StringBuffU8toU16(CHAR_BUFFER, (U8*)pData, sizeof(pData));
                                                MApp_TTSControlSetInputText(pStr2, sizeof(pData));

                                                free(pVol);
                                            }
                                        }
                                    }
                                    else
                                    {
                                        u16BufLen = MApp_UiMenu_u16Strlen(pStr);
                                        MApp_TTSControlSetInputText(pStr, u16BufLen);
                                    }
                                }
                                else //E_OSD_EPG
                                {
                                    if (u16LastHWND != MApp_ZUI_API_GetLastSuccessor(MApp_ZUI_API_GetParent(u16HWndID)))
                                    {
                                        LPTSTR pStr = MApp_ZUI_ACT_GetDynamicText((HWND)u16HWndID);
                                        u16BufLen = MApp_UiMenu_u16Strlen(pStr);
                                        MApp_TTSControlSetInputText(pStr, u16BufLen);
                                            u16LastHWND = u16HWndID;
                                        }
                                    }
                                }
                            break;

                            default:
                                enTTSState = STATE_TTS_FINISH;
                            break;
                        }
                    }
                }
            }
        }
        break;

        case STATE_TTS_TEXT_IN:
        {
            TTS_DBG(printf("STATE_TTS_TEXT_IN\n"));
            if (bTTSIsOn == TRUE)// && ((stSystemInfo[0].u8PanelPowerStatus & PANEL_POWER_BLUESCREEN) != PANEL_POWER_BLUESCREEN))
            {
            #if (TTS_IS_ON_HK == 0)
                U8 u8Ret = TTS_MBXReadByte(TTS_MBX_CMDID_IDX);
                TTS_DBG(printf("u8Ret=%d\n",u8Ret));

                if (u8Ret == MB_TTS_ENGINE_CMD_NONE)
             #endif
                    enTTSState = STATE_TTS_AUDIO_PLAY_INIT;
            }
        }
        break;

        case STATE_TTS_AUDIO_PLAY_INIT:
        {
            TTS_DBG(printf("STATE_TTS_AUDIO_PLAY_INIT\n"));
            if (MApi_AUDIO_GetCommAudioInfo(Audio_Comm_infoType_DMAReader_BufferLevel) == 0)
            {
                MApp_TTSAudioPlayInit();
            }
        }
        break;

        case STATE_TTS_LONG_TEXT_IN:
        {
            TTS_DBG(printf("STATE_TTS_LONG_TEXT_IN\n"));
            enTTSState = STATE_TTS_LONG_TEXT_AUDIO_PLAY;
        }
        break;

        case STATE_TTS_AUDIO_PLAY:
        {
            TTS_DBG(printf("STATE_TTS_AUDIO_PLAY\n"));

            MApp_TTS_ProcessUserInput();
            if ( enTTSState == STATE_TTS_AUDIO_PLAY)
            {
                MApp_TTSAudioPlay();
            }

        }
        break;

        case STATE_TTS_LONG_TEXT_AUDIO_PLAY:
        {
            TTS_DBG(printf("STATE_TTS_LONG_TEXT_AUDIO_PLAY\n"));
            MApp_TTSControlSayLongText();
            if (bLongTextIn == TRUE)
            {
                enTTSState = STATE_TTS_AUDIO_PLAY_INIT;
            }
        }
        break;

        case STATE_TTS_FINISH:
        {
            TTS_DBG(printf("STATE_TTS_FINISH\n"));
            MApp_TTSAudioPlayRemainder();
            MApp_TTSControlHandler_Reset();
            if ((MApp_VChip_GetCurVChipBlockStatus()) || (g_bInputBlocked))
            {
               // msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYBLOCK_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
            }

        #if TTS_MUTE_BGM
            if (!(IsATVInUse() && !IsVDHasSignal()))
            {
                msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_TTS_Background_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                //MApi_AUDIO_SetMixModeMute(E_AUDIO_INFO_GAME_IN, GAME1_VOL, FALSE);
            }
        #else
            MApi_AUDIO_SetMixModeVolume(E_AUDIO_INFO_GAME_IN, GAME1_VOL, u8DBVal, 0);
        #endif
            MApi_AUDIO_SetCommAudioInfo(Audio_Comm_infoType_DMAReader_Command, 0, 0);

            if (stGenSetting.g_SysSetting.bTTSOn == FALSE)
            {
                if (g_mainpage_common == EN_COMMON_OPTION_TTS_PAGE)
                {
                    if (!bTTSOffSpeak)
                    {
                        bTTSOffSpeak = TRUE;
                    }
                }
            }

            enTTSRetVal = EXIT_TTS_EXIT;
        }
        break;

        default:
            enTTSRetVal = EXIT_TTS_EXIT;
            break;
    }

    return enTTSRetVal;
}
#endif

