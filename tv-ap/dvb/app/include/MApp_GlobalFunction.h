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

#ifndef MAPP_GLOBAL_FUNCTION_H
#define MAPP_GLOBAL_FUNCTION_H

#include "datatype.h"
#include "MApp_GlobalSettingSt.h"
#include "msAPI_DTVSystem.h"

#if (ENABLE_DTV)
#include "mapp_si.h"
#endif

#include "msAPI_Power.h"
#include "msAPI_OSD.h"

/********************************************************************************/
/*                     struct                    */
/* ******************************************************************************/

#if(ENABLE_CEC)
typedef struct
{
    U8 au8LangCode[3];
    EN_LANGUAGE enLangIndex;
} ST_MENU_LANG_ISO639;
#endif


/********************************************************************************/
/*                     Macro                    */
/* ******************************************************************************/
#define SECONDS_PER_HALF_MIN    30L
#define SECONDS_PER_MIN         60L
#define SECONDS_PER_HOUR        3600L
#define SECONDS_PER_HALF_HOUR   1800L
#define SECONDS_PER_DAY         86400L
#define SECONDS_PER_30DAYS      (30*SECONDS_PER_DAY)
#define MINS_PER_HOUR           60
#define HOURS_PER_DAY           24

#define XDATA_WIN1_SIZE         0x1000

#define OSD_COUNTRY_SETTING     MApp_GetOSDCountrySetting()

#define MAX_ISO639CODE_LENGTH              3

#if (ENABLE_ATSC)
//-----------------------------------------------------------
// new feature (sorted)
//====EPG
#if ENABLE_ATSC_EPG_UI
#define EPG_DISCARD_EVENTS_BEFORE_YESTERDAY  DISABLE
#define EPG_DROP_DUPLICATE_EVENT             DISABLE
#define EPG_SORT_EVENT_FOR_ALL_EITTABLE      DISABLE
#endif

#endif // #if (ENABLE_ATSC)


#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"



//*************************************************************************
//          Function prototypes
//*************************************************************************
#ifdef MAPP_GLOBAL_FUNCTION_C
#define INTERFACE
#else
#define INTERFACE extern
#endif


#if (KEEP_UNUSED_FUNC == 1)
INTERFACE U16 msAPI_OSD_u16Strlen ( U16 *pu16Str );
//INTERFACE void msAPI_OSD_u16Strcpy ( U16 *pu16Dest, U16 *pu16Src );
INTERFACE S8 msAPI_OSD_u16Strcmp ( U16 *u16strA, U16 *u16strB );
#endif
INTERFACE U8 MApp_GetNoOfDigit ( U32 u32Data );
INTERFACE void MApp_UlongToU16String ( U32 ulValue, U16 *pArrOutput, S8 NoOfDigit );
INTERFACE void MApp_UlongToU8String ( U32 ulValue, U8 *pArrOutput, S8 NoOfDigit );
INTERFACE void MApp_U8StringToU16String ( U8 *pu8Str, U16 *pu16Str, U8 u8Strlen );

#if(ENABLE_ATSC)
INTERFACE void MApp_UlongToString ( U32 ulValue, U8 *bArrOutput, S8 NoOfDigit );
INTERFACE void MApp_U16StringToU8String ( U16 *pu16Str, U8 *pu8Str, U8 u8Strlen );
INTERFACE U16 MApp_UiMenu_u16Strlen(U16 *pu16Str);
#endif

INTERFACE U32 MApp_U8StringToUlong(U8* InputStr, U8 len);

INTERFACE U8 MApp_GetNoOfHexDigit ( U32 u32Data );
INTERFACE void MApp_HexUlongToU16String ( U32 ulValue, U16 *pArrOutput, S8 NoOfDigit );
INTERFACE void MApp_HexUlongToU8String ( U32 ulValue, U8 *pArrOutput, S8 NoOfDigit );


INTERFACE U8 MApp_GetLeap ( U16 u16year );
INTERFACE void MApp_SetToDefaultSystemTime ( ST_TIME *pstTime );
//INTERFACE void MApp_MJDUTC2Date(U8 *pau8TDTData, ST_TIME *pstTime);
//INTERFACE U32 MApp_MJDUTC2Seconds ( U8 *pau8TDTData );
INTERFACE U32 MApp_ConvertDate2Seconds ( ST_TIME *pstDate );
INTERFACE U32 MApp_ConvertStTime2Seconds ( ST_TIME *pstTime );
INTERFACE void MApp_ConvertSeconds2StTime ( U32 u32SystemTime, ST_TIME *pstTime);
void MApp_Time_PrintTimeAndST_Time(U32 u32Time);

INTERFACE S32 MApp_GetTimeZoneOffset ( U8 u8TimeZone );
INTERFACE U32 MApp_GetLocalSystemTime (void);
INTERFACE void MApp_SetLocalSystemTime (U32 u32LocalSystemTime);
INTERFACE U32 MApp_GetLocalWakeUpTime (void);
INTERFACE void MApp_SetLocalWakeUpTime (U32 u32LocalWakeUpTime);

INTERFACE U8 MApp_CalSummerTimeOffset(U8 *L_MJDUTC);
INTERFACE void MApp_CalDefaultTimeOffest(void);
INTERFACE U8 MApp_GetDaysOfThisMonth ( U16 u16Year, U8 u8Month );
INTERFACE U8 MApp_GetDayOfWeek(U16 u16Year, U8 u8Month, U8 u8Day);

INTERFACE BOOLEAN MApp_IsSrcHasSignal(SCALER_WIN eWindow);
INTERFACE U32 MApp_MJD2Sec(U8 *pu8MJD);
INTERFACE U32 MApp_MJDUTC2Seconds(U8 *pau8TDTData);
INTERFACE void MApp_Seconds2MJDUTC ( U32 u32TotalSeconds, U8 *pau8TDTData );
INTERFACE U32 MApp_UTC2Seconds ( U8 *pau8TDTData );
INTERFACE void MApp_Seconds2UTC ( U32 u32TotalSeconds, U8 *pau8TDTData );
INTERFACE EN_OSD_COUNTRY_SETTING MApp_GetOSDCountrySetting(void);
INTERFACE void MApp_SetOSDCountrySetting(EN_OSD_COUNTRY_SETTING eCountry, BOOLEAN bSave);

INTERFACE void MApp_SetOnTimer(MENU_OnTimer eOnTimerDate);
INTERFACE MENU_OnTimer MApp_GetOnTimer(void);
INTERFACE void MApp_SetDayOfWeek(DAYOFWEEK eDayOfWeek);
#ifdef sNewAudioMuteStyle
INTERFACE void MApp_Audio_MuteOnOff(BOOL bMute);
INTERFACE void MApp_Audio_MuteOnOff_ByEarPhone(BOOL bMute);
#endif
INTERFACE EN_LANGUAGE MApp_GetMenuLanguage(void);
INTERFACE EN_LANGUAGE MApp_GetMenuLanguage_DTG(void);
INTERFACE EN_MENU_TIMEZONE MApp_GetTimeZone_DTG(void);
INTERFACE EN_LANGUAGE MApp_GetAudioLangMenuLanguage_DTG(void);
INTERFACE EN_LANGUAGE MApp_GetSubLangMenuLanguage_DTG(void);
INTERFACE void MApp_SetMenuLanguage(EN_LANGUAGE eLanguage);
INTERFACE void MApp_SetTimeZone(EN_MENU_TIMEZONE eTimezone);
INTERFACE void MApp_SetAudioLangMenuLanguage(EN_LANGUAGE eLanguage);
INTERFACE void MApp_SetSubLangMenuLanguage(EN_LANGUAGE eLanguage);
INTERFACE U8 MApp_ASCII2INT(U8 buf);
#if ENABLE_CI
INTERFACE void MApp_SetCIDebugLevelInit(void);
#endif
INTERFACE void MApp_AddDay2StTime ( U16 u16DaysToAdd, ST_TIME *pstTime );
#if ENABLE_DTV
INTERFACE BOOLEAN MApp_UiMenuFunc_IsSystemClockSet(void);
INTERFACE EN_SI_Clock_TimeZone MApp_GetSIClockTimeZone(EN_MENU_Clock_TimeZone eClockTimeZone);
INTERFACE EN_SI_TIMEZONE MApp_GetSITimeZone(EN_MENU_TIMEZONE eTimeZone);
INTERFACE EN_SI_LANGUAGE MApp_GetSILanguage(EN_LANGUAGE eLanguage);
INTERFACE void MApp_SetSILanguage(EN_LANGUAGE eLanguage);
INTERFACE EN_LANGUAGE MApp_GetLanguageBySILanguage(EN_SI_LANGUAGE eLanguage);
#endif

#if (ENABLE_NONLINEAR_CURVE)
INTERFACE U8 MApp_NonLinearCalculate(P_MS_USER_NONLINEAR_CURVE pNonLinearCurve, U8 AdjustValue);
INTERFACE P_MS_USER_NONLINEAR_CURVE MApp_GetNonLinearCurve(EN_MS_NONLINEAR_CURVE eNonLinearCurveIndex);
#endif

#if ENABLE_DTV
INTERFACE EN_SI_COUNTRY_SETTING MApp_GetSICountry(EN_OSD_COUNTRY_SETTING eOSDCountrySetting);
#endif
#if ENABLE_CEC
INTERFACE BOOL MApp_GetOSDLangCodeFromIndex(EN_LANGUAGE eLanguage, U8 *pBuf);
#endif

INTERFACE BOOLEAN MApp_IsImageFrozen(void);
INTERFACE void MApp_SetImageFrozen(BOOLEAN bFrozen);

BOOL MApp_IsInputSrcUseAVD(BOOL bWindow );
BOOL MApp_IsInputSrcUseHDMIPort(BOOL bWindow );

void MApp_Fatal_Error(char *msg, const char *func);


#if(ENABLE_ATSC)
INTERFACE U16 MApp_GetAudioSoundTrackPID ( U8 u8CurrentSelect );
INTERFACE void MApp_ReMapAudioLanguage(void);
INTERFACE U16 MApp_SetPreferAudioSoundTrackPID(U8 u8Enable);
INTERFACE U16 MApp_SetPreferAudioSoundTrackPIDNew(void);
INTERFACE U16 MApp_GetAudioStreamType ( void );
INTERFACE void MApp_SetChChangeState(BOOLEAN bChProcess);
INTERFACE BOOLEAN MApp_GetChChangeState(void);
INTERFACE void MApp_ConvertLocalTime2Date ( S32 s32SystemTime, ST_TIME *pstDate );

#if 1//def LOCK_USE_BLACK_VIDEO
INTERFACE void MApp_MuteAvByLock(E_SCREEN_MUTE_STATUS e8ScreenMute, BOOLEAN bMuteEnable);
#else
INTERFACE void MApp_MuteAvByLock(BOOLEAN bEnableMute);
#endif

#endif // (ENABLE_ATSC)

#if(ENABLE_ATSC)
BOOL MApp_Is_InAutoScan_ATSC(void);
#endif
BOOL MApp_Is_InAutoScan_ATV(void);
BOOL MApp_Is_InAutoScan_DTV(void);

BOOL MApp_Is_InFactoryMode(void);

//-----------------------------------------------------------------------------------
#if( ENABLE_DTV )
DMX_FILTER_STATUS MApp_Demux_Stop_Filter_Audio(void);
DMX_FILTER_STATUS MApp_Demux_Start_Filter_Audio(U16 u16Pid);

DMX_FILTER_STATUS MApp_Demux_Stop_Filter_AudioDesc(void);
DMX_FILTER_STATUS MApp_Demux_Start_Filter_AudioDesc(U16 u16Pid);
#endif

#if(SENSOR_CHIP!=NOT_SUPPORT_LIGHT_SENSOR)
#if(SENSOR_CHIP==TSL2571_SENSOR)
#define	TSL2571_DEVICE_ADDRESS					0x52
//#define TSL2571_COMMAND									0x80
#define TSL2571_ENABLE									0x80
#define TSL2571_ATIME										0x81
#define TSL2571_WTIME										0x83
#define TSL2571_AILTL										0x84
#define TSL2571_AILTH										0x85
#define TSL2571_AIHTL										0x86
#define TSL2571_AIHTH										0x87
#define TSL2571_PERS										0x8C
#define TSL2571_CONFIG									0x8D
#define TSL2571_CONTROL									0x8F
#define TSL2571_ID											0x92
#define TSL2571_STATUS									0x93
#define TSL2571_C0DATA									0x94
#define TSL2571_C0DATAH									0x95
#define TSL2571_C1DATA									0x96
#define TSL2571_C1DATAH									0x97
#endif
INTERFACE void LightSensorChip_Init(void);
INTERFACE BOOLEAN LightSensorChip_CheckDevice(void);
INTERFACE U16 LightSensorChip_GetADC(void);
INTERFACE BOOLEAN LightSensor_Init(void);
INTERFACE BOOLEAN CheckLS_Change(U8 sCheckTick);
INTERFACE U16 MApp_UiMenuFunc_FactoryGetLSNiceADCReso(void);	
INTERFACE U16 MApp_UiMenuFunc_FactoryGetLSNiceAdjustStepMin(void);
INTERFACE U16 MApp_UiMenuFunc_FactoryGetLSNiceAdjustStepMax(void);
INTERFACE U16 MApp_UiMenuFunc_FactoryGetLSNiceLimitMin(void);	
INTERFACE U16 MApp_UiMenuFunc_FactoryGetLSNiceLimitMax(void);	
#endif
//====================================================================
#undef INTERFACE
#endif
