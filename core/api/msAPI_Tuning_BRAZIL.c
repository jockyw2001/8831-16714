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
#include "msAPI_ATVSystem.h"
#include "msAPI_Timer.h"
#if ( ENABLE_DVB_TAIWAN_APP || ENABLE_SBTVD_BRAZIL_APP || (TV_SYSTEM == TV_NTSC) )
#include "MApp_GlobalSettingSt.h"
#endif

//------------------------------------------------------
//
//------------------------------------------------------

#define AUTO_TUNING_DEBUG                   // enable (define) or disable (undefine) debug code
#define AUTO_SCAN_TIME_PRINT        1

#if defined(AUTO_TUNING_DEBUG)
    #define AUTO_TUNING_PRINT(x)    //x
#else
    #define AUTO_TUNING_PRINT(x)
#endif

U8 _u8NumberOfChBeGot_WhileAutoScan;

U8 msAPI_Tuner_GetNumberOfChBeFound_WhileAutoScan(void)
{
    return _u8NumberOfChBeGot_WhileAutoScan;
}

void msAPI_Reset_Tuner_GetNumberOfChBeFound_WhileAutoScan(void)
{
     _u8NumberOfChBeGot_WhileAutoScan=0;
}

#if 0
static TUNING_STATUS _GetTuningStatus(void)
{
    AFC eFreqDev;

    eFreqDev = MDrv_IFDM_GetFreqDev();
    AUTO_TUNING_PRINT(printf("AFCWIN=%bx\n",eFreqDev));

    if ( eFreqDev == E_AFC_OUT_OF_AFCWIN )
    {
        return E_TUNING_STATUS_OUT_OF_AFCWIN;
    }
    // else if ( eFreqDev <= E_AFC_MINUS_12p5KHz || eFreqDev >= E_AFC_PLUS_12p5KHz )
    else if ( eFreqDev <= E_AFC_GOOD_MINUS_VALUE || eFreqDev >= E_AFC_GOOD_PLUS_VALUE )
    {
        return E_TUNING_STATUS_GOOD;
    }
    else if ( eFreqDev <= E_AFC_MINUS_162p5KHz )
    {
        return E_TUNING_STATUS_UNDER;
    }
    else if ( eFreqDev >= E_AFC_PLUS_162p5KHz )
    {
        return E_TUNING_STATUS_OVER;
    }
    else if ( eFreqDev <= E_AFC_BELOW_MINUS_187p5KHz )
    {
        return E_TUNING_STATUS_UNDER_MORE;
    }
    else if ( eFreqDev >= E_AFC_ABOVE_PLUS_187p5KHz )
    {
        return E_TUNING_STATUS_OVER_MORE;
    }
    else
    {
        /* ASSERT */
    }
    return E_TUNING_STATUS_GOOD;
}
#endif


void msAPI_Tuning_GetStationName(void) //move to tuning.c
{
    if ( _u16UpdateStationNameTimer >= 1 )
    {
        _u16UpdateStationNameTimer--;

        if ( _u16UpdateStationNameTimer == 1 )
        {
        #if ENABLE_TTX
            if ( TRUE != msAPI_TTX_GetStationNameFromTeletext(_sCurrentStationName, MAX_STATION_NAME, NULL) )
        #endif
            {
                msAPI_Tuner_ConvertMediumAndChannelNumberToString(_eMedium, _u8ChannelNumber, _sCurrentStationName);
            }

            _u16UpdateStationNameTimer = 0;
        }
    }
}

static void _msAPI_Tuning_AutoFineTuning(AFC eFreqDev)
{
#if((FRONTEND_TUNER_TYPE == SHARP_VA1G5BF2009_TUNER) || (FRONTEND_TUNER_TYPE == SHARP_VA1E1BF1402_TUNER) || (FRONTEND_TUNER_TYPE == NUTUNE_FK1602_TUNER)\
    || (FRONTEND_TUNER_TYPE == SAMSUNG_DTVS70CVH073A_TUNER))

    if ( DIFFERENCE(_u16RealtimeAFTBaseTunerPLL,_u16TunerPLL) <= TUNER_PLL_PLUS_1MHz && msAPI_AVD_IsSyncLocked() == TRUE )
    {
        switch ( eFreqDev )
        {
            case E_AFC_PLUS_62p5KHz:
            case E_AFC_PLUS_112p5KHz:
                    _SetTunerPLL( PLLSTEP(-1));
                    break;

            case E_AFC_MINUS_62p5KHz:
            case E_AFC_MINUS_112p5KHz:
                    _SetTunerPLL( PLLSTEP(1));
                    break;
            default:
                    break;
        }
    }
    else
    {
        _SetTunerPLL(_u16RealtimeAFTBaseTunerPLL);
        msAPI_Tuner_SetIF();
    }
    return;

#else
    U8 i;

    #if(FRONTEND_TUNER_TYPE == NXP_FQD1136_TUNER)

    if ( eFreqDev == E_AFC_GOOD )
        return;

    if ( DIFFERENCE(_u16RealtimeAFTBaseTunerPLL,_u16TunerPLL) <= TUNER_PLL_PLUS_2MHz && msAPI_AVD_IsSyncLocked() == TRUE )
    {
        for ( i = 0; i <= TUNER_PLL_PLUS_4MHz ; i++ )
        {
            switch ( eFreqDev )
            {
                case E_AFC_BELOW_MINUS_125pKHz: _SetTunerPLL( PLLSTEP(2));  break;
                case E_AFC_MINUS_62p5KHz:       _SetTunerPLL( PLLSTEP(1));  break;
                case E_AFC_PLUS_62p5KHz:        _SetTunerPLL( PLLSTEP(-1)); break;
                case E_AFC_ABOVE_PLUS_125pKHz:  _SetTunerPLL( PLLSTEP(-2)); break;
                	 default:
                     _SetTunerPLL(_u16RealtimeAFTBaseTunerPLL);
                     msAPI_Tuner_SetIF();
                     return;
            }


    #else

    if ( eFreqDev == E_AFC_MINUS_12p5KHz || eFreqDev == E_AFC_PLUS_12p5KHz )
        return;

    if ( DIFFERENCE(_u16RealtimeAFTBaseTunerPLL,_u16TunerPLL) <= TUNER_PLL_PLUS_2MHz && msAPI_AVD_IsSyncLocked() == TRUE )
    {
        debugTuningPrint("Real Time AFT: 0x%x\n", eFreqDev);

        for ( i = 0; i <= TUNER_PLL_PLUS_4MHz ; i++ )
        {
            switch ( eFreqDev )
            {
                case E_AFC_BELOW_MINUS_187p5KHz:    _SetTunerPLL( PLLSTEP(8));  break;
                case E_AFC_MINUS_162p5KHz:  _SetTunerPLL( PLLSTEP(5));  break;
                case E_AFC_MINUS_137p5KHz:  _SetTunerPLL( PLLSTEP(4));  break;
                case E_AFC_MINUS_112p5KHz:  _SetTunerPLL( PLLSTEP(3));  break;
                case E_AFC_MINUS_87p5KHz:   _SetTunerPLL( PLLSTEP(3));  break;
                case E_AFC_MINUS_62p5KHz:   _SetTunerPLL( PLLSTEP(2));  break;
                case E_AFC_MINUS_37p5KHz:   _SetTunerPLL( PLLSTEP(1));  break;
                case E_AFC_MINUS_12p5KHz:   return;
                case E_AFC_PLUS_12p5KHz:    return;
                case E_AFC_PLUS_37p5KHz:    _SetTunerPLL( PLLSTEP(-1)); break;
                case E_AFC_PLUS_62p5KHz:    _SetTunerPLL( PLLSTEP(-2)); break;
                case E_AFC_PLUS_87p5KHz:    _SetTunerPLL( PLLSTEP(-3)); break;
                case E_AFC_PLUS_112p5KHz:   _SetTunerPLL( PLLSTEP(-3)); break;
                case E_AFC_PLUS_137p5KHz:   _SetTunerPLL( PLLSTEP(-4)); break;
                case E_AFC_PLUS_162p5KHz:   _SetTunerPLL( PLLSTEP(-5)); break;
                case E_AFC_ABOVE_PLUS_187p5KHz: _SetTunerPLL( PLLSTEP(-8)); break;
                default:
                    _SetTunerPLL(_u16RealtimeAFTBaseTunerPLL);
                    msAPI_Tuner_SetIF();
                    return;
            }
    #endif //end of (FRONTEND_TUNER_TYPE...

            if ( DIFFERENCE(_u16RealtimeAFTBaseTunerPLL,_u16TunerPLL) > TUNER_PLL_PLUS_2MHz )
            {
                if ( _IsLPrime() == TRUE )
                {
                    if ( _u16TunerPLL < _u16RealtimeAFTBaseTunerPLL )
                        _SetTunerPLL( _u16RealtimeAFTBaseTunerPLL + TUNER_PLL_PLUS_2MHz );
                    else
                        _SetTunerPLL( _u16RealtimeAFTBaseTunerPLL + TUNER_PLL_MINUS_2MHz );
                }
                else
                {
                    debugTuningPrint("One Channel AFT in Real Time\n", 0);
                    _SetTunerPLL(_u16RealtimeAFTBaseTunerPLL);
                    msAPI_Tuner_SetIF();
                    _OneChannelAFT();
                    return;
                }
            }

            eFreqDev = MDrv_IFDM_GetFreqDev();
        }
    }
    else
    {
        if ( ((_u16AFTIdleTimer % (19 * 18)) == 0) ||
             (msAPI_AVD_IsSyncLocked() == TRUE) )
        {
            debugTuningPrint("One Channel AFT in Real Time\n", 0);

            _SetTunerPLL(_u16RealtimeAFTBaseTunerPLL);
            msAPI_Tuner_SetIF();
            _OneChannelAFT();
        }
        else
        {
            if ( TUNER_PLL_PLUS_1MHz < DIFFERENCE(_u16RealtimeAFTBaseTunerPLL,_u16TunerPLL) )
            {
                if ( _u16RealtimeAFTBaseTunerPLL > _u16TunerPLL )
                    _SetTunerPLL( _u16TunerPLL + TUNER_PLL_PLUS_1MHz );
                else
                    _SetTunerPLL( _u16TunerPLL + TUNER_PLL_MINUS_1MHz );
            }
            else
            {
                if ( _u16RealtimeAFTBaseTunerPLL > _u16TunerPLL )
                    _SetTunerPLL( _u16RealtimeAFTBaseTunerPLL + TUNER_PLL_PLUS_2p25MHz );
                else
                    _SetTunerPLL( _u16RealtimeAFTBaseTunerPLL + TUNER_PLL_MINUS_2p25MHz );
            }
        }
    }
#endif
}

/******************************************************************************/
///- This API is called by MApp_ATVProc_Handler to keep tuning work.
/// @param eState \b IN: AFT_EXT_STEP_PERIODIC - This enum is called by ATVProc_Handler(). Don't call any other place except ATVProc_Handler().
///                  IN: AFT_EXT_STEP_SEARCHALL - This enum will start auto-tuning from VHF low to UHF max.
///                  IN: AFT_EXT_STEP_SEARCH_STOP - This enum will stop searching.
/******************************************************************************/

void msAPI_Tuner_TuningProcessor(eAFTSTEP eState)
{
    static AUTO_SEARCH_TYPE eAutoSearchType;
    static U8 u8VideoStableCount;
    static U8 u8ScanOffsetCnt;
    static U8 u8StatusTemp;
    static U8 u8StartFrom;
    static U16 u16PreviosTunerPLL;
    static BOOLEAN bFirstDetect;

    static BOOLEAN bIsSignalExist;

    if ( eState != AFT_EXT_STEP_PERIODIC )
    {
        if ( _eCurrentTuningState == AFT_IDLE && eState == AFT_EXT_STEP_SEARCHSTOP )
        {
            return;
        }

        if (eState == AFT_TUNING_SUSPEND)
        {
            _IsTuningSuspend = TRUE;
            return;
        }
        else if (eState == AFT_TUNING_RESUME)
        {
            _IsTuningSuspend = FALSE;
            return;
        }

        _eCurrentTuningState = eState;
        _u16TuningWaitTimer = 0;
        _IsTuningSuspend = FALSE;

    }

    if ( _eCurrentTuningState != AFT_IDLE )
    {
        if ( _IsTunerStable() == FALSE )
            return;
    }

    if (_IsTuningSuspend == TRUE)
        return;


    #if 0
    {
        static eAFTSTEP _ePreTuningState;
        static U32 u32TuningStateTime;

        if ( _eCurrentTuningState != _ePreTuningState )
        {
            printf("TUN_STATE: 0x%BX -> 0x%BX (%lu)\n",
                                      _ePreTuningState,
                                      _eCurrentTuningState,
                                      msAPI_Timer_DiffTimeFromNow(u32TuningStateTime));

            _ePreTuningState = _eCurrentTuningState;
            u32TuningStateTime = msAPI_Timer_GetTime0();
        }
    }
    #endif



    switch ( _eCurrentTuningState )
    {
        default:    break;

        case AFT_IDLE:

                _u16AFTIdleTimer++;
                if ( _u16AFTIdleTimer >= 0xFFF0 )
                    _u16AFTIdleTimer = 1;

                if ( (_u16AFTIdleTimer % 19) == 0 )
                {
                    if ( E_INPUT_SOURCE_ATV != msAPI_AVD_GetVideoSource()
                         || ( E_INPUT_SOURCE_ATV == msAPI_AVD_GetVideoSource() && TRUE == msAPI_AVD_IsAutoAVActive(E_AUTOAV_SOURCE_ALL) )
                         || IS_RT_AFT_ENABLED == FALSE
                         || FALSE == _bIsAFTNeeded)
                    {
                        return;
                    }
                    _msAPI_Tuning_AutoFineTuning(MDrv_IFDM_GetFreqDev());
                }
                return;

        case AFT_EXT_STEP_SEARCHALL:

                msAPI_Timer_Delayms(DELAY_FOR_ENTERING_MUTE);
                msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE,E_AUDIO_INTERNAL_2_MUTEON,E_AUDIOMUTESOURCE_ATV);

                eAutoSearchType = E_AUTO_SEARCH_TYPE_ALLWAYUP;

                msAPI_ATV_InitProgramPLLData();

                u8StartFrom = msAPI_ATV_GetChannelMin()-1;
                msAPI_ATV_SetCurrentProgramNumber(u8StartFrom);

                _SetTunerPLL( msAPI_ATV_MapChanToFreq(u8StartFrom+1) );
                _bIsAFTNeeded = TRUE;

                msAPI_AVD_TurnOffAutoAV();
                //jpts msAPI_AUD_SetAudioStandard((AUDIOSTANDARD_TYPE)E_AUDIOSTANDARD_M_BTSC);
                msAPI_Tuner_SetIF();
                msAPI_AVD_SetHsyncDetectionForTuning(TRUE);

                bFirstDetect = FALSE;
                _u8NumberOfChBeGot_WhileAutoScan = 0;
                u8StatusTemp = 0;
                u8ScanOffsetCnt = 1;
                u8VideoStableCount = 0;
                _eCurrentTuningState = AFT_CHECKSYNC;

                break;

        case AFT_CHECKSYNC:

                bIsSignalExist = FALSE;
                u8VideoStableCount++;

                u8StatusTemp <<= 1;
                u8StatusTemp |= msAPI_AVD_IsSyncLocked();

                if(u8VideoStableCount > 3)
                {
                    if((u8StatusTemp & 0x03) == 0x03)
                    {
                        msAPI_AVD_StartAutoStandardDetection();
                        _eCurrentTuningState = AFT_TUNING;
                        u8ScanOffsetCnt = 1;
                        u8VideoStableCount = 0;
                        u16PreviosTunerPLL = _u16TunerPLL;
                        u8StatusTemp = 0xff;
                    }
                    else
                    {
                        u8VideoStableCount = 0;
                        u8StatusTemp = 0x00;

                        if(u8ScanOffsetCnt <= 1)
                        {
                            u16PreviosTunerPLL = _u16TunerPLL;
                            u8ScanOffsetCnt++;
                        }
                        else if(u8ScanOffsetCnt > 5)
                        {
                            u8ScanOffsetCnt = 1;
                            _u16TunerPLL = u16PreviosTunerPLL;
                            msAPI_AVD_SetVideoStandard(E_VIDEOSTANDARD_PAL_M);
                            _eCurrentTuningState = AFT_MEMORIZEPRDATA;
                        }
                        else
                        {
                            if(u8ScanOffsetCnt%2)
                                _SetTunerPLL(u16PreviosTunerPLL -((u8ScanOffsetCnt/2)*8));
                            else
                                _SetTunerPLL(u16PreviosTunerPLL +((u8ScanOffsetCnt/2)*8));

                            u8ScanOffsetCnt++;

                            _u16TuningWaitTimer = 5;
                        }

                    }
                }
                break;

        case AFT_TUNING:

                u8StatusTemp = MDrv_IFDM_GetFreqDev();

                if( u8StatusTemp != E_AFC_OUT_OF_AFCWIN)
                {
                    if((u8StatusTemp <= E_AFC_MINUS_62p5KHz) || (u8StatusTemp >= E_AFC_PLUS_62p5KHz))
                    {
                        u8VideoStableCount = 0;
                        _eCurrentTuningState = AFT_DETECTVIDEO;
                        break;
                    }
                }

                u8VideoStableCount++;

                if(u8VideoStableCount < (TUNER_PLL_PLUS_0p75MHz*2))
                {
                    if ( DIFFERENCE(u16PreviosTunerPLL,_u16TunerPLL) <= TUNER_PLL_PLUS_0p75MHz /*&& msAPI_VD_IsSyncDetected() == TRUE */)
                    {
                        if(u8StatusTemp >= E_AFC_ABOVE_PLUS_187p5KHz)
                            _SetTunerPLL( PLLSTEP(-1));
                        else
                            _SetTunerPLL( PLLSTEP( 1));

                        _u16TuningWaitTimer = 1;
                    }
                    else
                    {
                        if(_u16TunerPLL > u16PreviosTunerPLL)
                            _SetTunerPLL(u16PreviosTunerPLL - TUNER_PLL_PLUS_0p75MHz);
                        else
                            _SetTunerPLL(u16PreviosTunerPLL + TUNER_PLL_PLUS_0p75MHz);

                        _u16TuningWaitTimer = 5;
                    }
                }
                else
                {
                    _bIsOneProgramDetected = FALSE;
                    bIsSignalExist = FALSE;
                    u8VideoStableCount = 0;
                    _eCurrentTuningState = AFT_MEMORIZEPRDATA;
                }
                break;

        case AFT_DETECTVIDEO:

                msAPI_AVD_GetResultOfAutoStandardDetection();
                _bIsOneProgramDetected = TRUE;
                bIsSignalExist = TRUE;
                u8VideoStableCount = 0;
                _u8NumberOfChBeGot_WhileAutoScan++;
                _eCurrentTuningState = AFT_MEMORIZEPRDATA;
                msAPI_Tuner_PrintTVAVSourceInformation();
                break;

        case AFT_MEMORIZEPRDATA:


                if(bIsSignalExist)
                {
                    msAPI_ATV_SetProgramPLLData(msAPI_ATV_GetCurrentProgramNumber(), _u16TunerPLL);

                    if(bFirstDetect == FALSE)
                    {
                        bFirstDetect = TRUE;
                        u8StartFrom = msAPI_ATV_GetCurrentProgramNumber();
                    }
                }

                msAPI_ATV_SkipProgram(msAPI_ATV_GetCurrentProgramNumber(), (!bIsSignalExist));
            #if (CM_MULTI_FAVORITE)
                msAPI_ATV_SetFavoriteProgram(msAPI_ATV_GetCurrentProgramNumber(), FALSE, E_FAVORITE_TYPE_ALL);
            #else
                msAPI_ATV_SetFavoriteProgram(msAPI_ATV_GetCurrentProgramNumber(), FALSE);
            #endif
                msAPI_ATV_LockProgram(msAPI_ATV_GetCurrentProgramNumber(), FALSE);
                msAPI_ATV_NeedAFT(msAPI_ATV_GetCurrentProgramNumber(),TRUE/*(!bIsSignalExist)*/);
                msAPI_ATV_SetSearchedProgram(msAPI_ATV_GetCurrentProgramNumber(),bIsSignalExist);
                msAPI_ATV_SetVideoStandardOfProgram(msAPI_ATV_GetCurrentProgramNumber(), msAPI_AVD_GetVideoStandard());
                _eCurrentTuningState = AFT_INCREASEPRNUMBER;

                break;

        case AFT_INCREASEPRNUMBER:

                if (TRUE != msAPI_ATV_IncCurrentProgramNumber())
                {
                    _eCurrentTuningState = AFT_COMPLETE;
                }
                else
                {
                    _SetTunerPLL( msAPI_ATV_MapChanToFreq(msAPI_ATV_GetCurrentProgramNumber()+1)/*-TUNER_PLL_PLUS_3MHz*/ );
                    _eCurrentTuningState = AFT_CHECKSYNC;
                    _u16TuningWaitTimer = WAIT_150ms;
                    msAPI_Tuner_SetIF();
                }

                if ( _u16TunerPLL >= UHF_MAX_PLL )
                {
                    _eCurrentTuningState = AFT_COMPLETE;
                    _u16TuningWaitTimer = 0;
                    _bChangeProgram = FALSE;
                }
                break;

        case AFT_COMPLETE:

                if(_u8NumberOfChBeGot_WhileAutoScan == 0)
                {
                    msAPI_ATV_SkipProgram(msAPI_ATV_GetChannelMin(),TRUE);
                }

                _eCurrentTuningState = AFT_IDLE;
                msAPI_AVD_SuppressAutoAV();

                //msAPI_ATV_SortProgram(u8StartFrom, msAPI_ATV_GetCurrentProgramNumber());

                msAPI_ATV_SetCurrentProgramNumber(u8StartFrom);

              #if ( ENABLE_DVB_TAIWAN_APP || ENABLE_SBTVD_BRAZIL_APP || (TV_SYSTEM == TV_NTSC) )
                if(stGenSetting.stScanMenuSetting.u8ScanType == SCAN_TYPE_AUTO)
                {
                }
                else
                {
                    if ( _bChangeProgram == TRUE )
                    {
                        msAPI_Tuner_ChangeProgram();
                    }
                    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE,E_AUDIO_INTERNAL_2_MUTEOFF,E_AUDIOMUTESOURCE_ATV);
                }
              #else

                if ( _bChangeProgram == TRUE )
                {
                    msAPI_Tuner_ChangeProgram();
                }

                msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE,E_AUDIO_INTERNAL_2_MUTEOFF,E_AUDIOMUTESOURCE_ATV);
              #endif
                //msAPI_VD_ClearSyncCheckCounter();
                msAPI_AVD_ClearAspectRatio();

                //msAPI_AVD_IsVideoFormatChanged();
                msAPI_AVD_SetIsVideoFormatChangedAsFalse();//20100330EL

                eAutoSearchType = E_AUTO_SEARCH_TYPE_STOPED;
                msAPI_AVD_SetHsyncDetectionForTuning(FALSE);
                return;

        case AFT_EXT_STEP_SEARCHSTOP:

                msAPI_Timer_Delayms(100);

                _eCurrentTuningState = AFT_IDLE;
                eAutoSearchType = E_AUTO_SEARCH_TYPE_STOPED;
                msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE,E_AUDIO_INTERNAL_2_MUTEOFF,E_AUDIOMUTESOURCE_ATV);
                //msAPI_VD_ClearSyncCheckCounter();
                msAPI_AVD_ClearAspectRatio();

                _bIsAFTNeeded = FALSE;
                msAPI_Tuner_SetRealtimeAFTBaseTunerPLL(_u16TunerPLL);
                msAPI_AVD_SuppressAutoAV();
                msAPI_AVD_SetHsyncDetectionForTuning(FALSE);
                break;

    }
}

U8 msAPI_Tuner_GetTuningProcessPercent(void)
{
    U8 u8Percent;
    U8 u8MAXCH;
    U8 u8MINCH;
    U8 u8CurrCH;

    if ( _eCurrentTuningState == AFT_IDLE || _eCurrentTuningState == AFT_EXT_STEP_SEARCHALL )
    {
        return 0;
    }

    u8Percent = 0;
    u8MAXCH = msAPI_ATV_GetChannelMax();
    u8MINCH = msAPI_ATV_GetChannelMin();
    u8CurrCH = msAPI_ATV_GetCurrentProgramNumber();
    if(u8CurrCH< u8MINCH)
    {
        return 0;
    }

    if ( (u8MAXCH - u8MINCH) )
    {
        u8Percent = (U8)(((u8CurrCH+1 - u8MINCH))*100 / (u8MAXCH - u8MINCH));
    }
    return u8Percent;
}

