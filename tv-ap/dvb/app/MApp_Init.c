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

#define MAPP_INIT_C

//------------------------------------------------------------------------------
//                            Header Files
//------------------------------------------------------------------------------
#include <string.h>
#include <stdio.h>
#include "util_checkversion.h"
#include "Board.h"
#include "datatype.h"
#include "debug.h"
#include "MsTypes.h"
#include "drvBDMA.h"

// Common Definition
#include "datatype.h"

#include "MsIRQ.h"
#include "MsOS.h"

#include "apiGOP.h"
#include "apiXC.h"
#include "apiXC_Adc.h"
#include "apiXC_Sys.h"
#include "apiXC_ModeParse.h"
#include "apiXC_Cus.h"
#include "apiAUDIO.h"

#include "apiPNL.h"
#include "Panel.h"

#ifdef SCART_OUT_NEW_METHOD
#include "drvTVEncoder.h"
#endif

#include "drvPM.h"
#include "drvGPIO.h"
#include "apiXC_Ace.h"
#include "msAPI_Power.h"
#include "msAPI_Memory.h"
#include "msAPI_MIU.h"
#include "msAPI_DrvInit.h"
#include "msAPI_Video.h"
#include "msAPI_IR.h"
#include "msAPI_Ram.h"
#include "apiGOP.h"
#include "msAPI_OSD.h"
#include "msAPI_Tuner.h"
#include "msAPI_Timer.h"
#include "apiXC_Dlc.h"
#include "msAPI_OCP.h"
#include "msAPI_DTVSystem.h"
#include "msAPI_ATVSystem.h"
#include "msAPI_ChProc.h"
#include "msAPI_Flash.h"
#include "msAPI_audio.h"
#include "msAPI_Font.h"

#include "msAPI_MSDCtrl.h"
#include "msAPI_FCtrl.h"
#include "msAPI_FSEnv.h"
#include "msAPI_DCC.h"
#include "msAPI_FS_SysInfo.h"

#if (VECTOR_FONT_ENABLE) && (COPRO_MVF_ENABLE)
#include "msAPI_CPU.h"
#endif

#include "drvSYS.h"
#include "MApp_Font.h"
#include "MApp_RestoreToDefault.h"
#include "MApp_MultiTasks.h"
#include "MApp_TopStateMachine.h"
#include "MApp_Font.h"
#include "MApp_GlobalVar.h"
#include "MApp_GlobalSettingSt.h"
#include "MApp_GlobalFunction.h"
#include "MApp_Key.h"
#include "MApp_IR.h"
#include "MApp_Bitmap.h"
#include "MApp_Init.h"
#include "MApp_SignalMonitor.h"
#include "MApp_InputSource.h"

#if ENABLE_EPGTIMER_RECORDER_TURNOFFPANEL
#include "MApp_TV.h"
#endif

#include "MApp_PCMode.h"
#include "MApp_Audio.h"
#include "MApp_Logo.h"

#if (ENABLE_SUBTITLE)
#include "MApp_Subtitle.h"
#endif

#include "MApp_Scaler.h"
#include "MApp_SaveData.h"
#include "MApp_MVDMode.h"
#include "MApp_DataBase.h"
#include "MApp_UiEpg.h"

#if (ENABLE_DVB)
#include "MApp_Dvb_SI.h"
#endif

#if(ENABLE_ATSC)
#include "MApp_Psip.h"
#include "MApp_VChip.h"
#endif

#if (ENABLE_DTV_EPG)
#include "mapp_epgdb_public.h"
#include "mapp_eit.h"
#endif

#if ENABLE_EPGTIMER_RECORDER_TURNOFFPANEL
#include "MApp_TV.h"
#endif

#include "MApp_Scan.h"
#include "MApp_UiMenuDef.h"
#include "MApp_Sleep.h"
#include "OSDcp_readbin.h"
#include "OSDcp_loadfont.h"
#include "MApp_EpgTimer.h"
#include "MApp_ChannelChange.h"
#include "MApp_VDMode.h"
#include "MApp_ATVProc.h"
#include "MApp_BlockSys.h"
#include "MApp_ZUI_Main.h"
#include "MApp_LoadFontInit.h"
#if (ENABLE_ATSC)
#include "MApp_ChannelProc_ATSC.h"
#endif
#if DISPLAY_LOGO
#include "MApp_Logo.h"
#endif
#include "IF_Demodulator.h"

#if ((ENABLE_DVB_T2) && (FRONTEND_DEMOD_DVBT_TYPE == MSTAR_MSB124X_DVBT))
#include "demodulator_T2.h"
#endif

#include "MApp_UiMediaPlayer_Define.h"

#include "MApp_XC_Sys.h"
#include "MApp_USBDownload.h"

#if ((BRAZIL_CC )|| (ATSC_CC == ATV_CC))
//#include "msAPI_vbi.h"
#include "mapp_closedcaption.h"
#endif

#if ENABLE_CEC
#include "msAPI_CEC.h"
#include "apiCEC.h"
#endif

#if ENABLE_DMP
#include "mapp_mplayer.h"
#include "MApp_UiMediaPlayer.h"
#include "MApp_InputSource.h"
#include "mapp_videoplayer.h"
#endif

#if ENABLE_OAD
#include "imginfo.h"
#include "MApp_OAD.h"
#endif //ENABLE_OAD

#if ENABLE_CI
#include "msAPI_CI.h"
#include "MApp_CIMMI.h"
#endif

#include "GPIO.h"

#include "HdmiSwitch.h"

#if ENABLE_PVR
    #include "MApp_UiPvr.h"
    #include "msAPI_PVRFileSystem.h"
 #if (ENABLE_PVR_AESDMA)
  #ifdef PVR_UTOPIA
    #include "drvAESDMA.h"
  #endif
 #endif
#endif
#include "msAPI_Global.h"


#if (ENABLE_TTX)
#include "msAPI_TTX.h"
#include "mapp_ttx.h"
#endif

#if(ENABLE_DTV)
#include "MApp_SI_Parse.h"
#endif

#if (ENABLE_UPDATE_MULTIPLEX_VIA_NIT)
#include "MApp_TV.h"
#endif
#include "mapp_photo_display.h"

#if MHEG5_ENABLE
#include "msAPI_MHEG5.h"
#endif


#ifdef ENABLE_SELECT_NONESEARCH_CH
#include "MApp_TV.h"
#endif

#if ENABLE_MFC_6M20
#include "drvUrsaMFCAPI.h"
#endif
#if ENABLE_MFC_6M30
#include "drvUrsa6M30.h"
#endif
#if(ENABLE_6M40_4KX2K_PROCESS)
#include "drvUrsa6M40.h"
#endif

#if ENABLE_UPGRADE_CIPLUSKEY_BY_USB
extern BOOLEAN b_isWriteCIkey;
extern BOOLEAN b_isCIkeyFileExit;
#endif


#if (CHAKRA3_AUTO_TEST)
#include "MApp_AutoTest.h"
#endif

#if (ENABLE_PIP)
#include "MApp_PIP.h"
#endif

#if(ENABLE_S2)
 #if(DISH_TYPE != DISH_NONE)
    #include "drvDish.h"
 #endif
/*
#if ( FRONTEND_DEMOD_S2_TYPE  == EMBEDDED_DVBS_DEMOD)
#include "INTERN_DVBS.h"
#endif */
#endif

#include "msAPI_Demod.h"

#if ENABLE_KEY_LOGGER
#include "MApp_KeyLogger.h"
#endif

#if (NO_SIGNAL_AUTO_SHUTDOWN )
#include "MApp_NoSignal_AutoSleep.h"
#endif

#if ENABLE_ATSC_TTS
#include "tts.h"
#include "MApp_TTSControlHandler.h"
#endif
//------------------------------------------------------------------------------

#if (ENABLE_MSTV_UART_DEBUG && ENABLE_MMS)
#include "drvMmsDbg_if.h"
extern void MDrv_Cfg_ActInit(void);
extern void MDrv_Cfg_UserActInit(void);
#endif

//------------------------------------------------------------------------------

//#include "MApp_Customer_Info.h"
extern unsigned char code CID_Buf[];
extern unsigned char code IP_Cntrol_Mapping_1[8];
extern unsigned char code IP_Cntrol_Mapping_2[8];
extern unsigned char code IP_Cntrol_Mapping_3[8];
extern unsigned char code IP_Cntrol_Mapping_4[8];

unsigned char Customer_info[49];
#define DEBUG_CUSTOMER_INFO_ENABLE 0
#if ENABLE_CI
#define CI_INIT_DETECT_COUNT  3
#endif

#if ENABLE_AUTOTEST
extern BOOLEAN g_bAutobuildDebug;
#endif

#define MK_U32(B0, B1, B2, B3) ((((U32)(B3))<<24) |(((U32)(B2))<<16)|(((U32)(B1))<<8)|((U32)(B0)))

#ifndef GOP_TEST_CODE
    #define GOP_TEST_CODE       0
#endif

//------------------------------------------------------------------------------
//                               Debug
//------------------------------------------------------------------------------
#define INIT_DBINFO(x)  //x
#define PWR_DBG(y)      //y
#define BREAK_DEBUG(deay_ms)    {\
                                    U32 u32TimeBefore;\
                                    u32TimeBefore = msAPI_Timer_GetTime0();\
                                    printf("%d\n",u32TimeBefore);\
                                    while(1)\
                                    {\
                                        if ((msAPI_Timer_GetTime0() - u32TimeBefore > deay_ms))\
                                            break;\
                                        msAPI_Timer_ResetWDT();\
                                    }\
                                }


#if USER_DEBUG && BUILD_SYSDEBUG
extern void userdebug(void);
#define USERDBG(x)      x
#else
#define USERDBG(x)
#endif

/********************************************************************************/
/*                                Static                                        */
/********************************************************************************/
extern U32 u32ProtectOffTimer;

#if (ENABLE_DTV)
extern U16             u16ReminderSrv;
extern U8               u8ReminderPcn;
#if ENABLE_EPGTIMER_RECORDER_TURNOFFPANEL
extern BOOLEAN     g_bTimerTypeRecord;
#endif

#if ENABLE_CI_PLUS
extern BOOLEAN     g_bTimeTypeOpRefresh;
#endif
#endif

extern void ttf_sbrk_SetMemPoolSize(unsigned long u32Size);
extern void *ttf_sbrk(unsigned int size);

extern void hash_sbrk_SetMemPoolSize(unsigned long u32Size);
extern void *hash_sbrk(unsigned int size);
#if(ENABLE_POWERON_VIDEO)
extern void msAPI_Pan_Task(void);
#endif
U8  u8Switch2Scart;
U8  u8IsAutoSleep_Skip_Logo;
U32 gSystemStartTimeForRemider;
U32 gSystemStartTimeForRecorder;
S32 volatile gS32OffsetTime;

#if (ENABLE_POWERON_MUSIC)
static U32 u32PowerOnMusicStartTime = 0;
static BOOL bPowerOnMusicExist = FALSE;
#endif
/*
   // Auth & Encryt Keys.
   // if customer use it's own credentiel ci+ key,may open this fucntion,otherwise make this fucntion
 U8 gu8aAesXcbcKey[16] =
{
    0x09, 0x28, 0x48, 0x92, 0x49, 0x09, 0x82, 0x39, 0x66, 0x83, 0x09, 0x82, 0x39, 0x68, 0x36, 0x21
};
 U8 gu8aAesCbcKey[16] =
{
    0x0F, 0x1E, 0x2D, 0x3C, 0x4B, 0x5A, 0x69, 0x78, 0x87, 0x96, 0xA5, 0xB4, 0xC3, 0xD2, 0xE1, 0xF0
};
 U8 gu8aAesCbcIV[16] =
{
    0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF
};
*/

#if(ENABLE_DTV)
static void _MApp_DTVInit(void);
#endif

/********************************************************************************/
/*                               Functions                                      */
/********************************************************************************/
void MApp_Init_CustomerInfo(void)
{
    unsigned char * pu8Temp;
    U8 i,u8Data;
    U8 u8ASCII_Mapping[16] = {'0','1','2','3','4','5','6','7','8','9','A',
        'B','C','D','E','F'};

#if (DEBUG_CUSTOMER_INFO_ENABLE)
        printf("****** Customer_info:Before ******");
        for (i=0;i<48;i++)
        {
            if (i%8 ==0)
                printf("\n");
            printf("0x%bx,",Customer_info[i]);

        }

        printf("\n abcdef => 0x%bx,0x%bx,0x%bx,0x%bx,0x%bx,0x%bx,",'a','b','c','d','e','f');
        printf("\n ABCDEF => 0x%bx,0x%bx,0x%bx,0x%bx,0x%bx,0x%bx,",'A','B','C','D','E','F');
        printf("\n\n");
#endif

    pu8Temp = &CID_Buf[6];//(Byte6,7: Customer ID)(Byte8,9: Model ID)(Byte1011: Chip ID)

    //<1>.To Prepare the Customer-ID + Model-ID + Chip-ID
          for (i=0;i<3;i++)
          { //Get hight byte
            u8Data = ((*(pu8Temp+1))>> 4);
            Customer_info[0+i*4] = u8ASCII_Mapping[u8Data];
            u8Data = (*(pu8Temp+1) & 0x0F);
            Customer_info[1+i*4] =  u8ASCII_Mapping[u8Data];
            //Get Low byte
            u8Data = ((*(pu8Temp))>>4) ;
            Customer_info[2+i*4] = u8ASCII_Mapping[u8Data];
            u8Data = (*(pu8Temp) & 0x0F);
            Customer_info[3+i*4] = u8ASCII_Mapping[u8Data];
            pu8Temp +=2;
          }
          for (i=0;i<4;i++)
            Customer_info[12+i] = 0x30;

    //<2>.To prepare the Customer IP
          pu8Temp = &IP_Cntrol_Mapping_1[0];
          memcpy(&Customer_info[16], pu8Temp, 8);
          pu8Temp = &IP_Cntrol_Mapping_2[0];
          memcpy(&Customer_info[16+8], pu8Temp, 8);
          pu8Temp = &IP_Cntrol_Mapping_3[0];
          memcpy(&Customer_info[16+16], pu8Temp, 8);
          pu8Temp = &IP_Cntrol_Mapping_4[0];
          memcpy(&Customer_info[16+24], pu8Temp, 8);

#if (DEBUG_CUSTOMER_INFO_ENABLE)
        printf("****** Customer_info ******");
        for (i=0;i<48;i++)
        {
            if (i%8 ==0)
                printf("\n");
            printf("0x%bx,",Customer_info[i]);

        }
#endif
        Customer_info[48] = 0;  //Important, string end symbol
}

void MApp_Preparation(void)
{
    MApp_Key_Initial_Status();
}

void MApp_Init_UIVariable(void)
{
    EN_OSD_COUNTRY_SETTING eCountry;


 #if (ENABLE_DTV)
    #if ENABLE_SBTVD_BRAZIL_APP
     eCountry = (EN_OSD_COUNTRY_SETTING)E_BRAZIL,                       ///< Brazil
   #else
     //eCountry = (EN_OSD_COUNTRY_SETTING)msAPI_CM_GetCountry();
     eCountry = (EN_OSD_COUNTRY_SETTING)stGenSetting.stTvSetting.eCountry;
   #endif
 #else
    eCountry = OSD_COUNTRY_UK;
 #endif

    MApp_SetOSDCountrySetting(eCountry, FALSE);

  #if EAR_PHONE_POLLING
    PreEarphoneState = EAR_PHONE_NULL;
  #endif
    u32InfoOSD_Duration = 5000L;

    u32MonitorOsdTimer = 0;

    bNextEvent = FALSE;
  #if (MHEG5_ENABLE)
    enCheckMHEGLoadingStatus = EN_MHEG5_MONITOR;
  #endif

    enIndicateTimerSource = TS_TYPE_NONE;
    memset(&stLMGenSetting.stMB, 0, sizeof(L_MENU_VIDEO_B_VAR));
    memset(&stLMGenSetting.stMFactory_Adjust, 0, sizeof(L_MENU_FACTORY_ADJUST_VAR));

  #if ENABLE_DTV
    SET_OSD_MENU_LANGUAGE(GET_OSD_MENU_LANGUAGE());
  #endif
}
extern U32 volatile gSystemTimeCount;
static void MApp_Init_TimeSetting(void)
{
    ST_TIME _stTime;
    U32 u32PMSystemTime = 0;

    if(bfirstACBoot == TRUE)//--------------AC Power On
    {
        u32PMSystemTime = msAPI_Timer_GetSystemTime();
        stGenSetting.g_Time.NVRAM_g_u8TimeInfo_Flag = 0;
    }
    else//----------------------------------DC Power On
    {
        u32PMSystemTime = msAPI_Timer_GetRTCSystemTime(); //restore system time from RTC
        g_u8TimeInfo_Flag = stGenSetting.g_Time.NVRAM_g_u8TimeInfo_Flag;
    }

    msAPI_Timer_Load_OffsetTime(); // must after EEPROM or FLASH init

    gSystemTimeCount=u32PMSystemTime;
    gSystemTimeCount_TCON = 0;

    /* init offset time */
    stLMGenSetting.stMD.enD4_SleepTimer = STATE_SLEEP_TOTAL;


    MApp_Sleep_ReleaseSleepTimer();


    u32ProtectOffTimer = 0;

    MApp_SetOnTimer((MENU_OnTimer)stGenSetting.g_Time.cOnTimerFlag);

    if(stGenSetting.g_Time.cOnTimerFlag != EN_Time_OnTimer_Off)
    {
        MApp_ConvertSeconds2StTime(MApp_GetLocalSystemTime(),&_stTime);
        _stTime.u8Hour = (U8)stGenSetting.g_Time.u16OnTimer_Info_Hour;
        _stTime.u8Min = (U8)stGenSetting.g_Time.u16OnTimer_Info_Min;
        _stTime.u8Sec = 0;
        //MApp_SetLocalWakeUpTime(MApp_ConvertStTime2Seconds(&_stTime));
    }
    //once mode on need reset flag
    if(stGenSetting.g_Time.cOffTimerFlag == EN_Time_OffTimer_Once)
    {
        stGenSetting.g_Time.cOffTimerFlag = EN_Time_OffTimer_Off;
    }

    MApp_Sleep_SetOffTime(TRUE); //set timer

    stGenSetting.g_Time.wTimeDataCS = MApp_CalCheckSum_SkipFirst2Byte((BYTE *)&(stGenSetting.g_Time), SIZE_TIME_DATA );
}


#if 0
static void MApp_Init_AcOnVariable(void)
{
    // printf("MApp_Init_AcOnVariable");
    fWakeUpByOnTimer = FALSE;
    gSystemTimeCount = 630720000;
    gS32OffsetTime = 0;
    gWakeupSystemTime = 0xFFFFFFFF;
    g_u8TimeInfo_Flag = 0;
    AEONRun=0;
    BEONRun=0;
    u8Switch2Scart = 0;
    u8IsAutoSleep_Skip_Logo=FALSE;

    gSystemStartTimeForRemider = 0;
    gSystemStartTimeForRecorder = 0;
    enManualTimerSystemBootType = EN_EPGUI_TIMER_NULL;
    //m_bIsWarmStandByMode = FALSE;
    u8IsAutoSleep_Skip_Logo=FALSE;
    MDrv_Power_Set_PDMode(STANDBY_MODE);
}
#endif

static void MApp_Init_PrintDataBaseMsg(void)
{
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /* database usage status */
    INIT_DBINFO(printf("General Usage :    start   size\n"));
    INIT_DBINFO(printf("BOOTLOADER         0x%04X  0x%04X\n", (U16)RM_BOOTLOADER_ADDR, (U16)RM_SIZE_BOOTLOADER));
    INIT_DBINFO(printf("TIMER_MANUAL_EVENT 0x%04X  0x%04X\n", (U16)RM_TIMER_MANUAL_EVENT_START_ADR, (U16)RM_SIZE_MANUAL_TIMER_EVENT));
    INIT_DBINFO(printf("TIMER_CHECKSUM     0x%04X  0x%04X\n", (U16)RM_TIMER_CHECKSUM_START_ADR, (U16)RM_SIZE_TIMER_CHECKSUM));
    INIT_DBINFO(printf("TV_COMMON_DATA     0x%04X  0x%04X\n", (U16)RM_TV_COMMON_DATA_START_ADR, (U16)RM_SIZE_TV_COMMON_DATA));
    INIT_DBINFO(printf("=> (RM_GEN_USAGE) = %lu\n", (U32)((U32)RM_GEN_USAGE )));

    INIT_DBINFO(printf("DB Usage :         start   size\n"));
    INIT_DBINFO(printf("DTV_CHSET          0x%04X  0x%04X\n", (U16)RM_DTV_CHSET_START_ADDR, (U16)RM_DTV_CHSET_SIZE));
    INIT_DBINFO(printf("ATV_CHSET          0x%04X  0x%04X\n", (U16)RM_ATV_CHSET_START_ADDR, (U16)RM_ATV_CHSET_SIZE));

#if ( ENABLE_DVB_TAIWAN_APP || ENABLE_SBTVD_BRAZIL_APP || (TV_SYSTEM == TV_NTSC) )
    INIT_DBINFO(printf("CATV_CHSET         0x%04X  0x%04X\n", (U16)RM_CATV_CHSET_START_ADDR, (U16)RM_CATV_CHSET_SIZE));
#endif

#if( DB_PC_MODE_SAVE_TO_DB_GEN == 0 )
    INIT_DBINFO(printf("MODE_SETTING       0x%04X  0x%04X\n", (U16)RM_MODE_SETTING_START_ADR, (U16)RM_SIZE_MODE_SETTING));
#endif

    INIT_DBINFO(printf("=> RM_64K_USAGE = %lu\n", (U32)RM_64K_USAGE));

    INIT_DBINFO(printf("Others : \n"));
    INIT_DBINFO(printf("sizeof(DTV_CHANNEL_INFO)    = %u\n", (U16)sizeof(DTV_CHANNEL_INFO)));
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

BOOLEAN MApp_Init_CheckOnTimeSetting(void)
{
    ST_TIME _stTime;
    DAYOFWEEK _Today = SUN;

   MApp_ConvertSeconds2StTime(MApp_GetLocalSystemTime(),&_stTime);
//printf("stGenSetting.g_Time.u16OnTimer_Info_Hour=%d\n",stGenSetting.g_Time.u16OnTimer_Info_Hour);
//printf("stGenSetting.g_Time.u16OnTimer_Info_Min=%d\n",stGenSetting.g_Time.u16OnTimer_Info_Min);

//printf("_stTime.u8Hour=%d\n", _stTime.u8Hour);
//printf("_stTime.u8Min=%d\n", _stTime.u8Min);
   _Today = (DAYOFWEEK)MApp_GetDayOfWeek(_stTime.u16Year, _stTime.u8Month, _stTime.u8Day);
   if( _stTime.u8Hour != (U8)stGenSetting.g_Time.u16OnTimer_Info_Hour ||
        _stTime.u8Min != (U8)stGenSetting.g_Time.u16OnTimer_Info_Min)
        return FALSE;

    switch(stGenSetting.g_Time.cOnTimerFlag)
    {
        default :
        case EN_Time_OnTimer_Off:
        return FALSE;

        case EN_Time_OnTimer_Once:
        case EN_Time_OnTimer_Everyday:
            return TRUE;

        case EN_Time_OnTimer_Mon2Fri:
            switch(_Today)
            {
                case SUN:
                case SAT:
        return FALSE;
                default:
                    return TRUE;
            }
            break;

        case EN_Time_OnTimer_Mon2Sat:
            switch(_Today)
            {
                case SUN:
        return FALSE;
                default:
                    return TRUE;
            }
            break;

        case EN_Time_OnTimer_Sat2Sun:
            switch(_Today)
            {
                case MON:
                case TUE:
                case WED:
                case THU:
                case FRI:
        return FALSE;
                default:
                    return TRUE;
            }
            break;

        case EN_Time_OnTimer_Sun:
            switch(_Today)
            {
                case SUN:
                    return TRUE;
                default:
        return FALSE;
    }
            break;
    }
}

static void MApp_Init_CheckOnTimer(void)
{
#if ENABLE_DTV_EPG //ENABLE_DTV
#if ENABLE_PVR
    EN_EPG_TIMER_ACT_TYPE actType = MApp_EpgTimer_GetTimerActType();

    if( actType == EN_EPGTIMER_ACT_REMINDER ||
        actType == EN_EPGTIMER_ACT_RECORDER_START
    #if ENABLE_CI_PLUS
        ||actType == EN_EPGTIMER_ACT_CI_OP_REFRESH
    #endif
        )
    {
        if(stGenSetting.g_Time.cOnTimerFlag == EN_Time_OnTimer_Once)
        {
            stGenSetting.g_Time.cOnTimerFlag = EN_Time_OnTimer_Off;
        }
        MApp_Sleep_SetAutoOn_OffTime(DISABLE);
        INIT_DBINFO(printf("WakeUpByEPG!!!\n"));
        return;
    }
#endif
#endif

    if(MApp_Init_CheckOnTimeSetting() == TRUE)
    {
        INIT_DBINFO(printf("WakeUpByOnTimer!!!\n"));

#if( ENABLE_DTV )
        // Before src switch, IsS2InUse() & IsDVBCInUse() not correct in msAPI_DTV_Comm_Get_DBSel()
    #if (ENABLE_S2)
        if(stGenSetting.g_Time.cOnTimerSourceFlag == EN_Time_OnTimer_Source_S2)
        {
            msAPI_DTV_Comm_Set_ForceDBSel(ENABLE, E_DTV_DB_SEL_DVBS);
        }
        else
    #endif
    #if (ENABLE_DVBC && DVB_T_C_DIFF_DB)
        if(stGenSetting.g_Time.cOnTimerSourceFlag == EN_Time_OnTimer_Source_DVBC)
        {
            msAPI_DTV_Comm_Set_ForceDBSel(ENABLE, E_DTV_DB_SEL_DVBC);
        }
        else
    #endif
        {
            msAPI_DTV_Comm_Set_ForceDBSel(ENABLE, E_DTV_DB_SEL_DVBT);
        }
#endif

        //reset on timer when on timer mode is once
        if(stGenSetting.g_Time.cOnTimerFlag == EN_Time_OnTimer_Once)
        {
            stGenSetting.g_Time.cOnTimerFlag = EN_Time_OnTimer_Off;
            MApp_SetOnTimer((MENU_OnTimer)stGenSetting.g_Time.cOnTimerFlag);
            gWakeupSystemTime = 0xFFFFFFFF;
        }

        // on timer
        switch(stGenSetting.g_Time.cOnTimerSourceFlag)
        {
        #if (!ENABLE_ATSC)
            case EN_Time_OnTimer_Source_ATV:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_ATV;
                msAPI_CHPROC_CM_SetCurrentOrdinal(E_SERVICETYPE_ATV, stGenSetting.g_Time.cOnTimerChannel, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
                break;
        #endif

        #if (ENABLE_DTV)
          #if (ENABLE_ATSC)
            case EN_Time_OnTimer_Source_ATSC:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_ATSC;
                stGenSetting.g_SysSetting.u16MainListLastWatched[ANT_TYPE] = stGenSetting.g_Time.cOnTimerChannel;
                MApp_ChanProc_ResetAllIndex(stGenSetting.g_SysSetting.u16MainListLastWatched[ANT_TYPE]);
                MApp_ChanProc_RefreshChannelBuffer(MAIN_LIST);
                break;
          #endif

            #if (ENABLE_DVBT)
            case EN_Time_OnTimer_Source_DVBT:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_DVBT;
                #if ENABLE_SBTVD_BRAZIL_CM_APP//mantis :0267732 for on time function power on crash.
                msAPI_ATV_SetCurrentAntenna(ANT_AIR);
                #endif

                msAPI_CHPROC_CM_SetCurrentOrdinal(E_SERVICETYPE_DTV, stGenSetting.g_Time.cOnTimerChannel, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
                break;
            #endif

            #if (ENABLE_DVBC)
            case EN_Time_OnTimer_Source_DVBC:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_DVBC;
                #if ENABLE_SBTVD_BRAZIL_CM_APP//mantis :0267732 for on time function power on crash.
                msAPI_ATV_SetCurrentAntenna(ANT_AIR);
                #endif

                msAPI_CHPROC_CM_SetCurrentOrdinal(E_SERVICETYPE_DTV, stGenSetting.g_Time.cOnTimerChannel, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
                break;
            #endif
            #if (ENABLE_DTMB)
            case EN_Time_OnTimer_Source_DTMB:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_DTMB;
                #if ENABLE_SBTVD_BRAZIL_CM_APP//mantis :0267732 for on time function power on crash.
                msAPI_ATV_SetCurrentAntenna(ANT_AIR);
                #endif

                msAPI_CHPROC_CM_SetCurrentOrdinal(E_SERVICETYPE_DTV, stGenSetting.g_Time.cOnTimerChannel, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
                break;
    #endif
            #if (ENABLE_ISDBT)
            case EN_Time_OnTimer_Source_ISDBT:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_ISDBT;
                #if ENABLE_SBTVD_BRAZIL_CM_APP//mantis :0267732 for on time function power on crash.
                msAPI_ATV_SetCurrentAntenna(ANT_AIR);
                #endif

                msAPI_CHPROC_CM_SetCurrentOrdinal(E_SERVICETYPE_DTV, stGenSetting.g_Time.cOnTimerChannel, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
                break;
            #endif

            #if(ENABLE_S2)
            case EN_Time_OnTimer_Source_S2://RYAN s2 bug 200
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_S2;
                MApp_InputSource_SwitchSource(UI_INPUT_SOURCE_TYPE, MAIN_WINDOW);
                msAPI_CHPROC_CM_SetCurrentOrdinal(E_SERVICETYPE_DTV, stGenSetting.g_Time.cOnTimerChannel, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
                break;
            #endif


            #if 0//(ENABLE_ATSC)
            case EN_Time_OnTimer_Source_ATSC_RADIO:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_ATSC;
                msAPI_CHPROC_CM_SetCurrentOrdinal(E_SERVICETYPE_RADIO, stGenSetting.g_Time.cOnTimerChannel, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
                break;
            #endif

            #if (ENABLE_DVBT)
            case EN_Time_OnTimer_Source_DVBT_RADIO:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_DVBT;
                msAPI_CHPROC_CM_SetCurrentOrdinal(E_SERVICETYPE_RADIO, stGenSetting.g_Time.cOnTimerChannel, E_PROGACESS_INCLUDE_VISIBLE_ONLY);

                break;
            #endif

            #if (ENABLE_DVBC)
            case EN_Time_OnTimer_Source_DVBC_RADIO:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_DVBC;
                msAPI_CHPROC_CM_SetCurrentOrdinal(E_SERVICETYPE_RADIO, stGenSetting.g_Time.cOnTimerChannel, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
                break;
            #endif
            #if (ENABLE_DTMB)
            case EN_Time_OnTimer_Source_DTMB_RADIO:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_DTMB;
                msAPI_CHPROC_CM_SetCurrentOrdinal(E_SERVICETYPE_RADIO, stGenSetting.g_Time.cOnTimerChannel, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
                break;
            #endif
            #if (ENABLE_ISDBT)
            case EN_Time_OnTimer_Source_ISDBT_RADIO:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_ISDBT;
                msAPI_CHPROC_CM_SetCurrentOrdinal(E_SERVICETYPE_RADIO, stGenSetting.g_Time.cOnTimerChannel, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
                break;
            #endif

            #if(ENABLE_S2)
            case EN_Time_OnTimer_Source_S2_RADIO://RYAN s2 bug 200
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_S2;
                msAPI_CHPROC_CM_SetCurrentOrdinal(E_SERVICETYPE_RADIO, stGenSetting.g_Time.cOnTimerChannel, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
                break;
            #endif


            #if NORDIG_FUNC //for Nordig Spec v2.0

            #if 0//(ENABLE_ATSC)
            case EN_Time_OnTimer_Source_ATSC_DATA:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_ATSC;
                msAPI_CHPROC_CM_SetCurrentOrdinal(E_SERVICETYPE_DATA, stGenSetting.g_Time.cOnTimerChannel, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
                break;
            #endif

            #if (ENABLE_DVBT)
            case EN_Time_OnTimer_Source_DVBT_DATA:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_DVBT;
                msAPI_CHPROC_CM_SetCurrentOrdinal(E_SERVICETYPE_DATA, stGenSetting.g_Time.cOnTimerChannel, E_PROGACESS_INCLUDE_VISIBLE_ONLY);

                break;
            #endif

            #if (ENABLE_DVBC)
            case EN_Time_OnTimer_Source_DVBC_DATA:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_DVBC;
                msAPI_CHPROC_CM_SetCurrentOrdinal(E_SERVICETYPE_DATA, stGenSetting.g_Time.cOnTimerChannel, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
                break;
            #endif
            #if (ENABLE_DTMB)
            case EN_Time_OnTimer_Source_DTMB_DATA:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_DTMB;
                msAPI_CHPROC_CM_SetCurrentOrdinal(E_SERVICETYPE_DATA, stGenSetting.g_Time.cOnTimerChannel, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
                break;
            #endif
            #if (ENABLE_ISDBT)
            case EN_Time_OnTimer_Source_ISDBT_DATA:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_ISDBT;
                msAPI_CHPROC_CM_SetCurrentOrdinal(E_SERVICETYPE_DATA, stGenSetting.g_Time.cOnTimerChannel, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
                break;
            #endif

        #if(ENABLE_S2)
            case EN_Time_OnTimer_Source_S2_DATA://RYAN s2 bug 200
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_S2;
                msAPI_CHPROC_CM_SetCurrentOrdinal(E_SERVICETYPE_DATA, stGenSetting.g_Time.cOnTimerChannel, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
                break;
        #endif
            #endif

      #endif
            #if (INPUT_SCART_VIDEO_COUNT >= 1)
            case EN_Time_OnTimer_Source_SCART:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_SCART;
                break;
            #endif

            #if (INPUT_SCART_VIDEO_COUNT >= 2)
            case EN_Time_OnTimer_Source_SCART2:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_SCART2;
                break;
            #endif

            #if (INPUT_YPBPR_VIDEO_COUNT>=1)
            case EN_Time_OnTimer_Source_COMPONENT:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_COMPONENT;
                break;
            #endif

            #if (INPUT_YPBPR_VIDEO_COUNT >= 2)
            case EN_Time_OnTimer_Source_COMPONENT2:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_COMPONENT2;
                break;
            #endif

            case EN_Time_OnTimer_Source_RGB:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_RGB;
                break;

            #if (INPUT_HDMI_VIDEO_COUNT >= 1)
            case EN_Time_OnTimer_Source_HDMI:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_HDMI;
                break;
            #endif

            #if (INPUT_HDMI_VIDEO_COUNT >= 2)
            case EN_Time_OnTimer_Source_HDMI2:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_HDMI2;
                break;
            #endif

            #if (INPUT_HDMI_VIDEO_COUNT >= 3)
            case EN_Time_OnTimer_Source_HDMI3:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_HDMI3;
                break;
            #endif

            #if (INPUT_HDMI_VIDEO_COUNT >= 4)
            case EN_Time_OnTimer_Source_HDMI4:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_HDMI4;
                break;
            #endif

            #if (INPUT_AV_VIDEO_COUNT >= 1)
            case EN_Time_OnTimer_Source_AV:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_AV;
                break;
            #endif

            #if (INPUT_AV_VIDEO_COUNT >= 2)
            case EN_Time_OnTimer_Source_AV2:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_AV2;
                break;
            #endif

            #if (INPUT_AV_VIDEO_COUNT >= 3)
            case EN_Time_OnTimer_Source_AV3:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_AV3;
                break;
            #endif

            #if (INPUT_SV_VIDEO_COUNT >= 1)
            case EN_Time_OnTimer_Source_SVIDEO:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_SVIDEO;
                break;
            #endif

            #if (INPUT_SV_VIDEO_COUNT >= 2)
            case EN_Time_OnTimer_Source_SVIDEO2:
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_SVIDEO2;
                break;
            #endif

            #if ENABLE_DMP
                case EN_Time_OnTimer_Source_MPLAYER:
                    UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_DMP;
                    break;
               // case EN_Time_OnTimer_Source_DLNA: //must
              //      UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_DLNA;
               //     break;
            #endif

            default:
                break;
        }
#if( ENABLE_DTV )
        msAPI_DTV_Comm_Set_ForceDBSel(DISABLE, E_DTV_DB_NUM);
#endif

        stGenSetting.g_SoundSetting.Volume = stGenSetting.g_Time.cOnTimerVolume;
        msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, stGenSetting.g_SoundSetting.Volume, 0);

        MApp_SaveSoundSetting();
        MApp_SaveSysSetting();

        if( stGenSetting.g_Time.cAutoSleepFlag == EN_Time_AutoOff_On)
        {
            MApp_Sleep_SetAutoOn_OffTime(ENABLE);
        }
        else
        {
            MApp_Sleep_SetAutoOn_OffTime(DISABLE);
        }
    }
  #if (ENABLE_DTV)
    else if(msAPI_Power_IswakeupsourceRTC())
    {
    #if(ENABLE_DTV_EPG)
        if(MApp_EpgTimer_CheckOnTimeReminder())
        {
            MEMBER_SERVICETYPE srvType = E_SERVICETYPE_INVALID;
            U16 srvPos = INVALID_SERVICE_ID;

        #if 0//(ENABLE_S2_EPG_REMINDER)
#if ENABLE_PVR
                MS_EPG_TIMER* m_pstEpgTimer = MApp_Get_EPG_Timer_pstEpgTimer();
                if(m_pstEpgTimer->u8SrcIsDtvS2 == 1)
                {
                    UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_S2;
                    msAPI_InputSrcType_SetType(MAIN_WINDOW, EN_SYS_INPUT_SOURCE_TYPE_S2);
                }
                else
#endif
                {
            UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_DTV;
                    msAPI_InputSrcType_SetType(MAIN_WINDOW, EN_SYS_INPUT_SOURCE_TYPE_DTV);
                }
        #else
            //UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_DTV;
            MS_EPG_TIMER* m_pstEpgTimer = MApp_Get_EPG_Timer_pstEpgTimer();
            MApp_InputSrc_Set_UiInputSrcType((E_UI_INPUT_SOURCE)m_pstEpgTimer->u8UiSrcType);
        #endif

            msAPI_CM_GetServiceTypeAndPositionWithPCN(u8ReminderPcn, u16ReminderSrv, &srvType, &srvPos);
            msAPI_CM_SetCurrentServiceType(srvType);
            msAPI_CM_SetCurrentPosition(srvType, srvPos);
        }
    #endif
    }
  #endif
}

#if ENABLE_CI
#if ENABLE_UPGRADE_CIPLUSKEY_BY_USB
static BOOL MApp_Detect_CIKey(void)
{
	U8 u8aTempBuf[2] = { 0x00 };
	U16 u16CredentialsLength = 0;

	msAPI_Flash_Read( CIPLUS_KEY_BANK*FLASH_BLOCK_SIZE + 12, 2, u8aTempBuf );
	u16CredentialsLength = (U16)u8aTempBuf[0] << 8 | (U16)u8aTempBuf[1];
	if((u16CredentialsLength > 0)&&(u16CredentialsLength < 0xFFFF))
		return TRUE;
	else
		return FALSE;
}
#endif

static void MApp_Init_CI(void)
{
    msAPI_CI_SetPMTBufAddr(_PA2VA((CI_PMT_BUFFER_MEMORY_TYPE & MIU1) ? (CI_PMT_BUFFER_ADR | MIU_INTERVAL) : (CI_PMT_BUFFER_ADR)));
    msAPI_CI_SetMMIBufAddr(_PA2VA((MMI_TEXTSTRING_MEMORY_TYPE & MIU1) ? (MMI_TEXTSTRING_ADR | MIU_INTERVAL) : (MMI_TEXTSTRING_ADR)));
#if (ENABLE_CI_PLUS)
    msAPI_CI_Initial( TRUE );   // TRUE: CI+ Supported
#else
    msAPI_CI_Initial( FALSE );  // FALSE: CI VI Only
#endif
    msAPI_CI_InstallCallback_CI_Event(MApp_CI_Event_Cb);
#if (ENABLE_CI_PLUS)
    /* Set up CI+ Credentials Setting.
       If using default CI+ Test Keys, please keep marking line.
       If using outside (from Flash) CI+ Production Keys, please unmark this line.
    */
#if ENABLE_UPGRADE_CIPLUSKEY_BY_USB
	if(MApp_Detect_CIKey())
		msAPI_CI_CC_SetCredentialsType(TRUE, TRUE);
#endif
#endif
	msAPI_CI_Set_TXRX_Interval(0,40,1);
    msAPI_CI_ConfigResource(EN_CI_FUNCTION_LSC, FALSE );

#if (ENABLE_CI_PLUS)
    msAPI_CI_ConfigResourceDefaultSetting(EN_CI_VERSION_CI_PLUS, EN_CI_PLUS_VERSION_1_3, TRUE);
#else
    msAPI_CI_ConfigResourceDefaultSetting(EN_CI_VERSION_CI, EN_CI_PLUS_IVALID_VERSION, TRUE);
#endif

#if ENABLE_CI
    MApp_SetCIDebugLevelInit();
#endif
    /* For CI/CI+ Debuging. */
    //msAPI_CI_SetDebugLevel(EN_CI_FUNCTION_DEFAULT, 1);
    //msAPI_CI_SetDebugLevel(EN_CI_FUNCTION_CC, 1);
}
#endif

extern void UART_Clear(void);

#if ENABLE_SHOW_PHASE_FACTORY
void MApp_ReadDDRPhase(void)
 {
      //read miu0 DQS0 and DQS1 for factory show
      g_u16Miu0_Dqs0 = MDrv_Read2Byte(0x103390);
      g_u16Miu0_Dqs1 =MDrv_Read2Byte(0x103392);
      MS_DEBUG_MSG(printf("g_u16Miu0_Dqs0~~~~~________-0x=%x\n",g_u16Miu0_Dqs0));
      MS_DEBUG_MSG(printf("g_u16Miu0_Dqs1~~~~~_________0x=%x\n",g_u16Miu0_Dqs1));
  #if(ENABLE_MIU_1)
      //read miu1 DQS0 and DQS1 for factory show
      g_u16Miu1_Dqs0 = MDrv_Read2Byte(0x10051C);
      g_u16Miu1_Dqs1 =MDrv_Read2Byte(0x10051E);
      MS_DEBUG_MSG(printf("g_u16Miu1_Dqs0~~~~~=%bx\n",g_u16Miu1_Dqs0));
      MS_DEBUG_MSG(printf("g_u16Miu1_Dqs1~~~~~=%bx\n",g_u16Miu1_Dqs0));
   #endif
  }
#endif

void MApp_setupMemory(void)
{
#if( CONTROL_DNR_BUF_RULE_2015 )

    MApi_XC_SetupFrameBuffer();

#else

    // Initialize XC DNR Address
#if( DTV_USE_FBL == 0 )
    if( IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)) )
    {
    #if( defined(SCALER_DNR_BUF_DTV_ADR) && (SCALER_DNR_BUF_DTV_LEN > 0) )
         MApi_XC_SetFrameBufferAddress(((SCALER_DNR_BUF_DTV_MEMORY_TYPE& MIU1) ? (SCALER_DNR_BUF_DTV_ADR| MIU_INTERVAL) : (SCALER_DNR_BUF_DTV_ADR)), SCALER_DNR_BUF_DTV_LEN, MAIN_WINDOW);
    #else
         MApi_XC_SetFrameBufferAddress(((SCALER_DNR_BUF_MEMORY_TYPE & MIU1) ? (SCALER_DNR_BUF_ADR | MIU_INTERVAL) : (SCALER_DNR_BUF_ADR)), SCALER_DNR_BUF_LEN, MAIN_WINDOW);
    #endif
    }
    else
#endif
    {
        MApi_XC_SetFrameBufferAddress(((SCALER_DNR_BUF_MEMORY_TYPE & MIU1) ? (SCALER_DNR_BUF_ADR | MIU_INTERVAL) : (SCALER_DNR_BUF_ADR)), SCALER_DNR_BUF_LEN, MAIN_WINDOW);
    #if ENABLE_3D_PROCESS
        MApi_XC_SetFrameBufferAddress(((SCALER_DNR_BUF_MEMORY_TYPE & MIU1) ? (SCALER_DNR_BUF_ADR | MIU_INTERVAL) : (SCALER_DNR_BUF_ADR)), SCALER_DNR_BUF_LEN, SUB_WINDOW);
    #endif
    }

#if (ENABLE_PIP)
    #ifdef SCALER_DNR_SUB_BUF_ADR
        MApi_XC_SetFrameBufferAddress(((SCALER_DNR_SUB_BUF_MEMORY_TYPE & MIU1) ? (SCALER_DNR_SUB_BUF_ADR | MIU_INTERVAL) : (SCALER_DNR_SUB_BUF_ADR)), SCALER_DNR_SUB_BUF_LEN, SUB_WINDOW);
    #endif
#endif

#endif
}

void MApp_Gop_init(void)
{
    U8 u8GopId = 0;

#if ((UI_SKIN_SEL ==  UI_SKIN_1366X768X4444)   \
    || (UI_SKIN_SEL ==  UI_SKIN_1366X768X565)    \
    || (UI_SKIN_SEL ==  UI_SKIN_1366X768X8888)   \
    )
    {
        if(g_IPanel.Width() >= 1366 && g_IPanel.Height() >= 768)
        {
            for (u8GopId = 0;u8GopId<=1;u8GopId++)
            {
                MApi_GOP_GWIN_SwitchGOP(u8GopId);
                MApi_GOP_GWIN_Set_STRETCHWIN(u8GopId, E_GOP_DST_OP0,0, 0, ZUI_ALIGNED_VALUE(1366,8), 768);
                MApi_GOP_GWIN_Set_HSCALE(TRUE,ZUI_ALIGNED_VALUE(1366,8),PANEL_WIDTH);
                MApi_GOP_GWIN_Set_VSCALE(TRUE, 768, PANEL_HEIGHT);
            }

        #if ENABLE_ZUI_BACKGROUND_PINK_PATCH //issue: some OSD pictures have one pixel high pink frames
            MApi_GOP_GWIN_Set_TranspColorStretchMode(E_GOP_TRANSPCOLOR_STRCH_DUPLICATE);
        #else
            MApi_GOP_GWIN_Set_TranspColorStretchMode(E_GOP_TRANSPCOLOR_STRCH_ASNORMAL);//issue:UI char have some black point.
        #endif

        #if ((FIXED_MIRROR_HD_PANEL_UI_LOSE == ENABLE) && (MirrorEnable == ENABLE))
            if((g_IPanel.Width()<=1366&&g_IPanel.Height()<=768)&&MApp_Image_GetMirror())
            {
                MApi_GOP_GWIN_Set_HStretchMode(E_GOP_HSTRCH_DUPLICATE);
                MApi_GOP_GWIN_Set_VStretchMode(E_GOP_VSTRCH_DUPLICATE);
            }
        #endif
        }
        else
        {
           //Unsupported resolution
           MS_DEBUG_MSG(printf("[Unsupported Resolution: %d x %d\n]",g_IPanel.Width(),g_IPanel.Height()));
        }
    }
#endif

#if (UI_SKIN_SEL ==  UI_SKIN_960X540X565 || UI_SKIN_SEL == UI_SKIN_960X540XI8)
    {
        if(g_IPanel.Width() >= 960 && g_IPanel.Height() >= 540)
        {
            for (u8GopId = 0;u8GopId<=1;u8GopId++)
            {
                MApi_GOP_GWIN_SwitchGOP(u8GopId);
                MApi_GOP_GWIN_Set_STRETCHWIN(u8GopId, E_GOP_DST_OP0,0, 0, 960,540);
                MApi_GOP_GWIN_Set_HSCALE(TRUE,960,PANEL_WIDTH);
                MApi_GOP_GWIN_Set_VSCALE(TRUE, 540, PANEL_HEIGHT);
            }

        #if ENABLE_ZUI_BACKGROUND_PINK_PATCH //issue: some OSD pictures have one pixel high pink frames
            MApi_GOP_GWIN_Set_TranspColorStretchMode(E_GOP_TRANSPCOLOR_STRCH_DUPLICATE);
        #else
            MApi_GOP_GWIN_Set_TranspColorStretchMode(E_GOP_TRANSPCOLOR_STRCH_ASNORMAL);//issue:UI char have some black point.
        #endif

        #if ((FIXED_MIRROR_HD_PANEL_UI_LOSE == ENABLE) && (MirrorEnable == ENABLE))
            if((g_IPanel.Width()<=960&&g_IPanel.Height()<=540)&&MApp_Image_GetMirror())
            {
                MApi_GOP_GWIN_Set_HStretchMode(E_GOP_HSTRCH_DUPLICATE);
                MApi_GOP_GWIN_Set_VStretchMode(E_GOP_VSTRCH_DUPLICATE);
            }
        #endif
        }
        else
        {
           //Unsupported resolution
           MS_DEBUG_MSG(printf("[Unsupported Resolution: %d x %d\n]",g_IPanel.Width(),g_IPanel.Height()));
        }
    }
#endif

#if (UI_SKIN_SEL ==  UI_SKIN_1920X1080X565)
    {
        if(g_IPanel.Width() >= 1920 && g_IPanel.Height() >= 1080)
        {
            for (u8GopId = 0;u8GopId<=1;u8GopId++)
            {
                MApi_GOP_GWIN_SwitchGOP(u8GopId);
                MApi_GOP_GWIN_Set_STRETCHWIN(u8GopId, E_GOP_DST_OP0,0, 0, 1920,1080);
                MApi_GOP_GWIN_Set_HSCALE(TRUE,1920,PANEL_WIDTH);
                MApi_GOP_GWIN_Set_VSCALE(TRUE, 1080, PANEL_HEIGHT);
            }

        #if ENABLE_ZUI_BACKGROUND_PINK_PATCH //issue: some OSD pictures have one pixel high pink frames
            MApi_GOP_GWIN_Set_TranspColorStretchMode(E_GOP_TRANSPCOLOR_STRCH_DUPLICATE);
        #else
            MApi_GOP_GWIN_Set_TranspColorStretchMode(E_GOP_TRANSPCOLOR_STRCH_ASNORMAL);//issue:UI char have some black point.
        #endif

        #if ((FIXED_MIRROR_HD_PANEL_UI_LOSE == ENABLE) && (MirrorEnable == ENABLE))
            if((g_IPanel.Width()<=1920&&g_IPanel.Height()<=1080)&&MApp_Image_GetMirror())
            {
                MApi_GOP_GWIN_Set_HStretchMode(E_GOP_HSTRCH_DUPLICATE);
                MApi_GOP_GWIN_Set_VStretchMode(E_GOP_VSTRCH_DUPLICATE);
            }
        #endif
        }
        else
        {
           //Unsupported resolution
           MS_DEBUG_MSG(printf("[Unsupported Resolution: %d x %d\n]",g_IPanel.Width(),g_IPanel.Height()));
        }
    }
#endif

#if ( DISPLAY_LOGO == 0 )
    GOP_InitInfo pGopInit;

    pGopInit.u16PanelWidth = g_IPanel.Width();
    pGopInit.u16PanelHeight = g_IPanel.Height();
    pGopInit.u16PanelHStr = g_IPanel.HStart();
    pGopInit.u32GOPRBAdr = ((GOP_GWIN_RB_MEMORY_TYPE & MIU1) ? (GOP_GWIN_RB_ADR | MIU_INTERVAL) : (GOP_GWIN_RB_ADR));
    pGopInit.u32GOPRBLen = 0x003F4800;
    pGopInit.u32GOPRegdmaAdr = ((GOP_REGDMABASE_MEMORY_TYPE & MIU1) ? (GOP_REGDMABASE_ADR | MIU_INTERVAL) : (GOP_REGDMABASE_ADR));
    pGopInit.u32GOPRegdmaLen = GOP_REGDMABASE_LEN;
    pGopInit.bEnableVsyncIntFlip = FALSE;

    MApi_GOP_InitByGOP(&pGopInit, 0);
    MApi_GOP_GWIN_SetGOPDst(0, E_GOP_DST_OP0);
#endif
}
/***************************************************************************************/

void MApp_Power_On_Init_Standby2On(void)
{
#if ( ENABLE_AUTOTEST || ENABLE_BOOTTIME )
    gbBootTimeFinish = FALSE;
    gU32BootTime = msAPI_Timer_GetTime0();
    printf(" start of main\n");
#endif

#if (ENABLE_CHCHANGETIME)
    gbKeyPress = FALSE;
#endif


#if( CHAKRA3_AUTO_TEST )
    g_AT_bPowerOnFinished = FALSE;
    MApp_AT_SendEvent(E_AT_EVENT_BOOT_TIME_START, (void*)MsOS_GetSystemTime());
#endif


#if ENABLE_SELECT_UART
    MApp_VDPlayer_UartSwitch(SELECT_UART_PORT);
#endif


#if (ENABLE_AUTOTEST || ENABLE_BOOTTIME)
    gU32BootStepTime = msAPI_Timer_GetTime0();
#endif

#if ( ENABLE_INDIA_OSD )
    hash_sbrk_SetMemPoolSize((1024*48));//default:32KB
    //Initial TTF cache memory management system
    hash_sbrk(0);

    //Set TTF memory pool size
    ttf_sbrk_SetMemPoolSize(1024*(700-48));
    //Initial TTF memory management system
    ttf_sbrk(0);
#else
    hash_sbrk_SetMemPoolSize(1024);//default:32KB
    //Initial TTF cache memory management system
    hash_sbrk(0);

    //Set TTF memory pool size
    ttf_sbrk_SetMemPoolSize(1024);
    //Initial TTF memory management system
    ttf_sbrk(0);
#endif
}

void MApp_PreInit_CheckAndModifyPowerOnOffFlag(void)
{
    //PRINT_CURRENT_LINE();
    //printf("1.stGenSetting.stMiscSetting.bDCOnOff=%u\n", stGenSetting.stMiscSetting.bDCOnOff);

#if ENABLE_OAD
    if( MApp_OAD_IsScheduleOnCheck() )
    {
        printf("Is Schedule On\n");
        if ( EN_POWER_AC_BOOT == msAPI_Power_QueryPowerOnMode() )
        {
            if (stGenSetting.stMiscSetting.bDCOnOff == EN_POWER_DC_OFF) // go to standby
            {
                //msAPI_Power_PowerDown_EXEC();
            }
        }
    }
    else
#endif
    {
        if( EN_POWER_AC_BOOT == msAPI_Power_QueryPowerOnMode() ) // AC on
        {
            printf("AC on\n");

            //G_FACTORY_SETTING.stFacMiscSetting.u8PowerOnMode = POWERON_MODE_SAVE;

    #if ENABLE_DESIGN_POWER_ON_MODE
            if(G_FACTORY_SETTING.stFacMiscSetting.u8PowerOnMode == POWERON_MODE_ON)
            {
                printf("Force Power On\n");
                stGenSetting.stMiscSetting.bDCOnOff = EN_POWER_DC_ON;
            }
            else if(G_FACTORY_SETTING.stFacMiscSetting.u8PowerOnMode == POWERON_MODE_OFF)
            {
                stGenSetting.stMiscSetting.bDCOnOff = EN_POWER_DC_OFF;
                printf("Force Power Off\n");
            }
            else // last status
            {
                // Keep last status
                printf("Use DB setting: stMiscSetting.bDCOnOff=%u\n", stGenSetting.stMiscSetting.bDCOnOff);
            }
    #else
            stGenSetting.stMiscSetting.bDCOnOff = EN_POWER_DC_ON;
    #endif
        }
        else // DC on
        {
            printf("DC on\n");
            // do nothing...
            stGenSetting.stMiscSetting.bDCOnOff = EN_POWER_DC_ON;
        }
    }

    //printf("2.stGenSetting.stMiscSetting.bDCOnOff=%u\n", stGenSetting.stMiscSetting.bDCOnOff);
}

#if ENABLE_TTX
void MApp_PreInit_TTX_And_TurnOfTTX(void)
{
    // !!!!! Must be carefully memory overlay issue!!!!!
    // After msAPI_TTX_InitSystem(), it will use memory
    // After msAPI_TTX_Stop(),  TTX buf can use by other
    // !!!!!

    msAPI_TTX_InitSystem();
    //stGenSetting.g_SysSetting.fEnableTTXSubTitle = FALSE;

    msAPI_TTX_VBIAcquireEnable(FALSE);

    // Turn off TTX in power on init, Turn on at change source
    msAPI_TTX_Stop();
}
#endif

void MApp_PreInit_Autotest_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

#if (CHAKRA3_AUTO_TEST)
    MApp_AT_Init();
#endif
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_GlobalVariable_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

#if (ENABLE_BOOTTIME)
    gU32CompressTotalStepTime = 0;
#endif

    //printf("====> Time: %s\n", __TIME__);

    //init OCP var  20091124EL
    _bOCPFromMem = FALSE;
#if ENABLE_S2
    Dvbs2_Default_Scan = 0;
#endif

    bfirstACBoot = FALSE;
    stSystemInfo[MAIN_WINDOW].enInputSourceType = INPUT_SOURCE_NONE;

#if (ENABLE_UPGRADE_CIPLUSKEY_BY_USB)
    b_isWriteCIkey = FALSE;
    b_isCIkeyFileExit = TRUE;
#endif

#if (ENABLE_PIP)
    if(IsPIPSupported())
    {
        stSystemInfo[SUB_WINDOW].enInputSourceType = INPUT_SOURCE_NONE;
    }
#endif

#if ENABLE_3D_PROCESS
    g_HdmiInput3DFormat = E_XC_3D_INPUT_MODE_NONE;
    g_HdmiInput3DFormatStatus = E_XC_3D_INPUT_MODE_NONE;
#endif

#if FIXED_SCART_OUT_GARBAGE_SWITCH_AR
    g_u8switchAspectFlag = 0;
#endif

#if FIXED_3D_SWITCH_PIC_MODE_GARBAGE
    g_u8switchPicModeFlag = 0;
#endif

#if HDMI_DVI_AUDIO_MODE_CONFIG
    g_HdmiAudioModeChanged = FALSE;
#endif
   #if ENABLE_S2
    Test_Dvbs2 = FALSE;
   #endif
#if ENABLE_EPGTIMER_RECORDER_TURNOFFPANEL
    g_bTimerTypeRecord = FALSE;
#endif

#if ENABLE_CI_PLUS
    g_bTimeTypeOpRefresh = FALSE;
    bPowerOnEnterOPMode = TRUE;
#endif

#if PVR_AND_TTX_DIFF_WITH_MHEG5
    g_enTurnOnTTX = TTX_MHEG5_NUM;
#endif

#if (ENABLE_HDMI_4K_2K)
    g_HdmiInput4Kx2KFormat= FALSE;
#endif

    g_bPvrChgSrcInitFs = 0;

#if( ENABLE_BOOTTIME )
    g_BootTime_u8Flag = 0;
#endif
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_PowerSettingVariable_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

    // check AC/DC on, and wakeup device
    msAPI_PowerSetting_Init();

    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());
}

void MApp_PreInit_FlashVariable_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

#if 1//GENSETTING_STORE_USE_NEW_METHOD
    MApp_Init_FlashVariable();
#endif
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_Chip_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

    /* initialize all device drivers */
    msAPI_ChipInit();
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_Audio(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

		#ifdef sNewAudioMuteStyle
		msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, 0, 0);
		#else
    MUTE_On(); // 0 ms
    #endif
    //Refine power on sequence for earphone & DAC pop noise issue
    msAPI_AUD_PreInitAudio();

    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_CustomerInfo(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

    /* To set Vendor ID to the Mailbox register */
    MApp_Init_CustomerInfo();

    // MDrv_Sys_Set_CIDInfo(&CID_Buf[6]);
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_Panel_SetInverter(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

    MApi_PNL_SetInverter(DISABLE);
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_ReadDDRPhase(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

#if ENABLE_SHOW_PHASE_FACTORY
    MApp_ReadDDRPhase();
#endif
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_Driver_Step1_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());


    msAPI_DrvInitStep1();

    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_Interrupt_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

    // work around code, currently if the VBI address (From start to end) is beyond 0xFFFF, there'll be problem
    // Temp solution, makes VBI start to end is in same U16 area (0 ~ 0xFFFF)
    msAPI_Interrupt_Init(); // 0 ms
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_DateBase_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());


    // Check data base
    MApp_DB_Check();

    // Init flash write protect
    msAPI_Flash_Init();
    msAPI_Flash_Init_WriteProtect();

    // EEPROM restore or init global setting
#if (EEPROM_DB_STORAGE!=EEPROM_SAVE_NONE)
    MApp_CheckEEPROM();
#endif

    // Flash restore or init global setting
    // When the Flash is normal, please first read (UserData & Channel Data)
#if (EEPROM_DB_STORAGE != EEPROM_SAVE_ALL)
    MApp_CheckFlash();
#endif

#if ENABLE_OAD
	if((msAPI_Timer_GetRTCWakeUpTime() <= msAPI_Timer_GetRTCSystemTime()) &&
		MApp_OAD_IsUserSelectOn() &&
		SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW) &&
		(msAPI_Timer_GetRTCWakeUpTime()!=0xFFFFFFFF))
	{
		if(msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO)
	#if NORDIG_FUNC
		|| msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO)
	#endif
		|| msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO))
		{
			MApp_OAD_Set_ScheduleOnCheck();
		}
	}
#endif

    // Check and modify power on/off flag
    MApp_PreInit_CheckAndModifyPowerOnOffFlag();

    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_ATVProc_Audio_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

    if( stGenSetting.stMiscSetting.bDCOnOff == EN_POWER_DC_OFF )
    {
        printf("Skip State-ATVProc_Init_Audio\n");
        return;
    }


    MApp_ATVProc_Initialize_Audio();    // use 1596ms

    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_Audio_Setting_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());


    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_PERMANENT_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
    msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, stGenSetting.g_SoundSetting.Volume, 0);

    if( stGenSetting.stMiscSetting.bDCOnOff == EN_POWER_DC_OFF )
    {
        printf("Skip State-AUD_Setting\n");
        return;
    }

    //Audio_Amplifier_ON();

    /* Set the sound mode */
    MApp_Audio_AdjustSoundMode();

    /* Set the surround mode */
    MApp_Aud_SetSurroundMode(stGenSetting.g_SoundSetting.SurroundSoundMode);

    MApp_Aud_Banlace_Init();

#if 0//(CHIP_FAMILY_TYPE == CHIP_FAMILY_A7)
    MApp_Aud_AudioDelay_Init();
#endif

    /* init audio after Audio switch*/
    msAPI_AUD_I2S_Amp_Reset(); // 0 ms

//////////////////////////////////////////////////////////

#if ( (ENABLE_DMP) && (ENABLE_POWERON_MUSIC) )
		#ifdef sNewAudioMuteStyle
		msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, stGenSetting.g_SoundSetting.Volume, 0);
		#else
		MUTE_Off();
		#endif

    MApp_InputSource_ChangeAudioSource(INPUT_SOURCE_STORAGE);   // use 142ms


    MApp_Music_StateInit(BIN_ID_MELODY_ON);     // use 192ms
    bPowerOnMusicExist = MApp_Music_PowerON_Melody_Decode_OneTime();
    u32PowerOnMusicStartTime = msAPI_Timer_GetTime0();
#endif

    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_Font_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

    if( stGenSetting.stMiscSetting.bDCOnOff == EN_POWER_DC_OFF )
    {
        printf("Skip State-FontInit\n");
        return;
    }


#if (VECTOR_FONT_ENABLE) && (COPRO_MVF_ENABLE)
    msAPI_COPRO_Init(BIN_ID_CODE_AEON_MVF,((AEON_MEM_MEMORY_TYPE & MIU1) ? (AEON_MEM_ADR | MIU_INTERVAL) : (AEON_MEM_ADR)),AEON_MEM_LEN);
#endif

    MApp_LoadFontInit();    // use 232ms

    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_Driver_Step2_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());


    msAPI_DrvInitStep2();   // use 267ms

    MApp_ADC_HW_SaveGainOffset();

    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_EnableSkip3D_LRFlag_SetHWLVDS_LRFlag(void)
{
#if (ENABLE_3D_PROCESS &&( ENABLE_MFC_6M30 || ENABLE_6M40_4KX2K_PROCESS || ENABLE_6M50_4KX2K_PROCESS) && CONFIG_3D_HWLVDSLRFLAG )
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

    MApi_XC_3D_Enable_Skip_Default_LR_Flag(ENABLE);
    PNL_Set3D_HWLVDSLRFlag();
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());
#endif

}

void MApp_PreInit_DNR_Memory_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

    //Init Main and Sub DNR memory address
    MApp_setupMemory();
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_System_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

    MDrv_SYS_Init();

    //MApi_Mod_Calibration_Setting(0, 0);//test ...it must be called before g_IPanel.Enable
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_Panel_Enable(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

#if ENABLE_TCON
    g_bTCONPowerOnFlag = TRUE;
#endif

    //Disable Output CLK
    MApi_PNL_En(FALSE); // 0 ms

#if ENABLE_TCON
    g_bTCONPowerOnFlag = FALSE;
#endif
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_EnableDCC_DDC2BI_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());


    //Set GOP Stop to wait VSync
    MApi_GOP_GWIN_SetForceWrite(ENABLE); // 0 ms

    msAPI_PowerON_EXEC(); // 0 ms

#if ENABLE_DCC
    msAPI_DCC_EnableDCC();
#endif

#if ENABLE_DDCCI
    msAPI_DDC2BI_Init(); // 0 ms
#endif

    //MApp_LoadFontInit();

    /* Initialize 8K bytes memory pool */
    msAPI_Memory_Init(); // 0 ms


    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_DataBase_Checking(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Start of Load & Check general setting and database
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /* database usage status */
    MApp_Init_PrintDataBaseMsg(); // 0 ms

    ////////////////////////////////////////////////////////////////
    // Check DC or AC on to decide right now should boot or sleep //
    //printf("1.stGenSetting.stMiscSetting.bDCOnOff=%u\n", stGenSetting.stMiscSetting.bDCOnOff);
/* Move to DB_Init()
#if ENABLE_OAD
	if(MApp_OAD_IsScheduleOnCheck())
	{
		if ( EN_POWER_AC_BOOT == msAPI_Power_QueryPowerOnMode() )
		{
		    if (stGenSetting.stMiscSetting.bDCOnOff == EN_POWER_DC_OFF) // go to standby
		    {
		        msAPI_Power_PowerDown_EXEC();
		    }
		}
	}
    else
#endif
    {
        if( EN_POWER_AC_BOOT == msAPI_Power_QueryPowerOnMode() ) // AC on
        {
            printf("AC on\n");
        #if ENABLE_DESIGN_POWER_ON_MODE
            if(G_FACTORY_SETTING.stFacMiscSetting.u8PowerOnMode == POWERON_MODE_ON)
            {
                printf("Force Power On\n");
                stGenSetting.stMiscSetting.bDCOnOff = EN_POWER_DC_ON;
            }
            else if(G_FACTORY_SETTING.stFacMiscSetting.u8PowerOnMode == POWERON_MODE_OFF)
            {
                stGenSetting.stMiscSetting.bDCOnOff = EN_POWER_DC_OFF;
                printf("Force Power Off\n");
            }
            else // last status
            {
                // Keep last status
                printf("Use DB setting: stMiscSetting.bDCOnOff=%u\n", stGenSetting.stMiscSetting.bDCOnOff);
            }
        #else
            stGenSetting.stMiscSetting.bDCOnOff = EN_POWER_DC_ON;
        #endif
        }
        else // DC on
        {
            printf("DC on\n");
            // do nothing...
            stGenSetting.stMiscSetting.bDCOnOff = EN_POWER_DC_ON;
        }
    }
*/

    //printf("2. stGenSetting.stMiscSetting.bDCOnOff=%u\n", stGenSetting.stMiscSetting.bDCOnOff);

    if( stGenSetting.stMiscSetting.bDCOnOff == EN_POWER_DC_OFF ) // go to standby
    {
        //MApp_DB_SaveNowGenSetting();
        MApp_DB_GEN_SaveData_RightNow();

        printf("\r\n !!!!! should go to standby !!!!! \n");
        msAPI_Power_PowerDown_EXEC();
        MDrv_Sys_StopCpu(1);
    }
    else
    {
    }

    ////////////////////////////////////////////////////////////////

    /// if cold boot and want to enter UI menu screen page, there is no default data for it, need to initialize here ///
    MApp_DB_LoadModeSetting(MAIN_WINDOW, 0); // 0 ms

#if (ENABLE_PIP)
    if(IsPIPSupported())
    {
        MApp_DB_LoadModeSetting(SUB_WINDOW, 0); // 0 ms
    }
#endif

    if(g_PcadcModeSetting[MAIN_WINDOW].u16HorizontalStart == 0 || g_PcadcModeSetting[MAIN_WINDOW].u16VerticalStart == 0)
    {
        MApp_DB_LoadDefaultTable(MAIN_WINDOW, 0); // 0 ms

    #if (ENABLE_PIP)
        if(IsPIPSupported())
        {
            MApp_DB_LoadDefaultTable(SUB_WINDOW, 0); // 0 ms
        }
    #endif
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // End of Load & Check general setting and database
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_SSC_Setting_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());


    // Should be put after loading DB

    SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) = EN_SCREENSAVER_NULL;

#if (ENABLE_PIP)
    if(IsPIPSupported())
    {
        SYS_SCREEN_SAVER_TYPE(SUB_WINDOW) = EN_SCREENSAVER_NULL;
    }
#endif

#if ENABLE_SSC
    msAPI_MIU_SetSsc( stGenSetting.g_SSCSetting.MIUSscSpanKHzx10,
                      stGenSetting.g_SSCSetting.MIUSscStepPercentagex100,
                      stGenSetting.g_SSCSetting.SscMIUEnable );

  #if ((ENABLE_LVDSTORGB_CONVERTER == ENABLE)||CHAKRA3_AUTO_TEST)
    g_IPanel.SetSSC( SSC_SPAN_PERIOD, SSC_STEP_PERCENT, DISABLE );
  #else
    g_IPanel.SetSSC( stGenSetting.g_SSCSetting.LVDSSscSpanKHzx10,
                     stGenSetting.g_SSCSetting.LVDSSscStepPercentagex100,
                     stGenSetting.g_SSCSetting.SscLVDSEnale);
  #endif
    MApi_PNL_Control_Out_Swing(stGenSetting.g_SSCSetting.LVDSSwing);//add LVDSSwing Funciton
#endif // #if ENABLE_SSC

#if (ENABLE_MFC_6M20||ENABLE_MFC_6M30||ENABLE_6M40_4KX2K_PROCESS)  //
    MApp_UsbDownload_USB_UpDate_SetHKPort();
#endif


    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_TTX_Init(void)
{
    /* Initial teletext */
#if ENABLE_TTX
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

    //msAPI_TTX_InitSystem();
    MApp_PreInit_TTX_And_TurnOfTTX();

    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

#endif  // #if ENABLE_TTX
}

void MApp_PreInit_Image_SetMirror(void)
{
#if (MirrorEnable == ENABLE)
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

    MApp_Image_SetMirror();

    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());
#endif

#ifdef ENABLE_SELECT_NONESEARCH_CH
    u16ChannelReturn_Num1 = IVALID_TV_RETURN_NUM;
    u16ChannelReturn_Num2 = IVALID_TV_RETURN_NUM;
#endif

#if (ENABLE_DTV_CHCEK_USB_DELAY_2S)
    g_u8DTVCheckUSBFlag = DTV_CHECK_USB_ENABLE;
#endif
    //Ray ORI 2017.06.02: Init image orientation
    dv_ImageOrientationInit();
}

void MApp_PreInit_UI_InputSource_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());
    
    //printf("MingYuan PreSource UI_INPUT_SOURCE_TYPE = %d\n",UI_INPUT_SOURCE_TYPE);
    //printf("MingYuan PreSource UI_PREV_INPUT_SOURCE_TYPE = %d\n",UI_PREV_INPUT_SOURCE_TYPE);

	#ifdef sDMPSourcePreIssue
	   #if ENABLE_DMP
		 if((UI_INPUT_SOURCE_TYPE == UI_INPUT_SOURCE_DMP)&&(UI_PREV_INPUT_SOURCE_TYPE==UI_INPUT_SOURCE_TYPE))
		 {
		 	 UI_PREV_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_RGB;
		 }
		 #endif
	#else    
		#if ENABLE_DMP
    if(UI_INPUT_SOURCE_TYPE == UI_INPUT_SOURCE_DMP)
    {
        if(UI_PREV_INPUT_SOURCE_TYPE == UI_INPUT_SOURCE_DMP)
        {
        #if(ENABLE_DTV == FALSE)
            UI_PREV_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_ATV;
        #else
            #if ENABLE_ATSC
                UI_PREV_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_ATSC;
            #elif ENABLE_DVBT
                UI_PREV_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_DVBT;
            #elif ENABLE_DVBS
                UI_PREV_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_S2;
            #elif ENABLE_DVBC
                UI_PREV_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_DVBC;
            #elif ENABLE_DTMB
                UI_PREV_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_DTMB;
            #elif ENABLE_ISDBT
                UI_PREV_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_ISDBT;
            #endif
        #endif
        }

        UI_INPUT_SOURCE_TYPE = UI_PREV_INPUT_SOURCE_TYPE;
    }
		#endif
    UI_PREV_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_TYPE;
	#endif
#if 0
#if (ENABLE_DTV == FALSE)
    if( UI_INPUT_SOURCE_TYPE == UI_INPUT_SOURCE_DTV)
    {
        UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_ATV;
    }
#endif
#endif

    g_enChType = (EN_CH_TYPE)UI_INPUT_SOURCE_TYPE;

    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

    //printf("MingYuan PreSource 2 UI_INPUT_SOURCE_TYPE = %d\n",UI_INPUT_SOURCE_TYPE);
    //printf("MingYuan PreSource 2 UI_PREV_INPUT_SOURCE_TYPE = %d\n",UI_PREV_INPUT_SOURCE_TYPE);
}

void MApp_PreInit_Flag_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

    // Set flag initial value
    fEnableSignalMonitor        = FALSE;    // Enable signal
    bEnableAC3Check             = FALSE;    // for check scramble(ac3 not exist.)
    u8PollingStereo             = 0;
    g_bRealTimeMonitorOnly      = FALSE;
    u32ScartSwitchDuration      = 0;
    g_bIsImageFrozen            = FALSE;

    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_CI_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

#if (ENABLE_DTV)
#if ENABLE_CI

	/* CI_Init: Detect CICAM and then Switch TS Interface to Serial/Parallel Mode. */
	//msAPI_CI_EnablePerformanceMonitor(msAPI_Timer_DiffTimeFromNow(gU32BootTime));
	MApp_Init_CI(); // It's important to INIT CI LIB HERE irrespective of which the input source is!

	// Speed up CI.
	if (FALSE == msAPI_CI_CardDetect())
	{
		U8 i;
		for (i = 0; i < CI_INIT_DETECT_COUNT; i++)
		{
			if (msAPI_CI_Polling())
			{
				break;
			}
		}
	}

  #if 0 // No Need set path here
	if (!msAPI_CI_CardDetect())
	{
	#if ENABLE_CI_PLUS
	  #if (!TS_SERIAL_OUTPUT_IF_CI_REMOVED)
		msAPI_Tuner_Serial_Control(TRUE,FALSE);
		msAPI_Tuner_SetByPassMode(TRUE, FALSE);
	  #else
		msAPI_Tuner_Serial_Control(FALSE,FALSE);
	  #endif
	#else
		msAPI_Tuner_Serial_Control(FALSE,FALSE);
	#endif

	}
	else
	{
	#if ENABLE_CI_PLUS
	  #if (!TS_SERIAL_OUTPUT_IF_CI_REMOVED)
		msAPI_Tuner_Serial_Control(TRUE,FALSE);
		msAPI_Tuner_SetByPassMode(FALSE, FALSE);
	  #else
		msAPI_Tuner_Serial_Control(FALSE,FALSE);
	  #endif
	#else
		MApp_CI_Switch_TS(FALSE);
	#endif
	}
  #endif
#else // #if ENABLE_CI

	/*{
	#if ENABLE_CI_PLUS
	  #if (!TS_SERIAL_OUTPUT_IF_CI_REMOVED)
		msAPI_Tuner_Serial_Control(TRUE,FALSE);
	  #else
		msAPI_Tuner_Serial_Control(FALSE,FALSE);
	  #endif
	#else
		msAPI_Tuner_Serial_Control(FALSE,FALSE);
	#endif
        }*/

#endif // #if ENABLE_CI
#endif // #if (ENABLE_DTV)

    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());
}

void MApp_PreInit_HDMISwitch_PS321_Init(void)
{
    /* init ps321 */
#if(HDMI_SWITCH_SELECT == HDMI_SWITCH_PS321)
  DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

  #if(INPUT_HDMI_VIDEO_COUNT > 0)
    HdmiSwitch_PS321_Init();
  #endif
  DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

#endif // #if(HDMI_SWITCH_SELECT == HDMI_SWITCH_PS321)
}

// For some special demod need init driver first!
void MApp_PreInit_InitDemodDriver(void)
{
#if ((ENABLE_DVB_T2) && (FRONTEND_DEMOD_DVBT_TYPE == MSTAR_MSB124X_DVBT))
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

    mdev_CofdmInit();

    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

#endif
}

void MApp_PreInit_Tuner_And_Demod_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

#if 1//(ENABLE_POST_INIT==FALSE)
  #if ENABLE_CEC
    ARC_CTRL_ON();

    // Why???
    //if(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW) != INPUT_SOURCE_HDMI)
    {
        //MApi_XC_Sys_SetHPD(ENABLE, INPUT_PORT_DVI1);
        //  MApi_XC_Sys_SetHPD_ALL(ENABLE);//HPD have been pull high when HDMI inital,need't do it again .Reduce boot time.
    }
  #endif
#endif

#if (ENABLE_DTV)

    MApp_PreInit_InitDemodDriver();

  #if (ENABLE_DVBC )//TODO need add DVB-C case
    //msAPI_Tuner_SwitchSource((EN_DVB_TYPE)stGenSetting.stScanMenuSetting.u8DVBCTvConnectionType, FALSE);
    msAPI_Tuner_Set_DvbType((EN_DVB_TYPE)stGenSetting.stScanMenuSetting.u8DVBCTvConnectionType);
    MApp_DVBType_SetPrevType((EN_DVB_TYPE)stGenSetting.stScanMenuSetting.u8DVBCTvConnectionType);
  #endif

    PRINT_AUTOTEST_CHECKPT_TIME("start Tuner init");

    //msAPI_Tuner_Initialization_BySource();

    //fixed load devCOFDM_Init twice error
  #if 0//( (DTV_SYSTEM_SEL != DTV_SYSTEM_SBTVD) && (DTV_SYSTEM_SEL != DTV_SYSTEM_DTMB)&& (FRONTEND_DEMOD_TYPE!= MSTAR_MSB124X_DVBT))
    //msAPI_Tuner_InitExternDemod();
  #endif

#if(ENABLE_S2)
 #if(DISH_NONE != DISH_TYPE) //( FRONTEND_DEMOD_S2_TYPE  == EMBEDDED_DVBS_DEMOD)
    MDrv_Dish_Init();
 #endif
#endif //#if ENABLE_S2
#endif // #if ENABLE_DTV

DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_Time_Setting_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

    MApp_Init_TimeSetting(); // 0 ms
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_EPGTimer_Data_Init(void)
{
	#if (ENABLE_DTV_EPG)
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

	_MApp_EpgTimer_Initdata();

    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

	#endif
}

void MApp_PreInit_CheckOnTimer_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

    MApp_Init_CheckOnTimer(); // 0 ms
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_Logo_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());


#if (DISPLAY_LOGO)
#if(ENABLE_MPLAYER_CAPTURE_LOGO)
	u8IsAutoSleep_Skip_Logo=!stGenSetting.g_SysSetting.UsrLogo;
#endif
	if (  (u8IsAutoSleep_Skip_Logo == FALSE)
	#if ENABLE_EPGTIMER_RECORDER_TURNOFFPANEL
		&& (g_bTimerTypeRecord == FALSE)
	#endif
	#if ENABLE_CI_PLUS
		&& (g_bTimeTypeOpRefresh == FALSE)
	#endif
	#if ENABLE_OAD
		&&(MApp_OAD_IsScheduleOnCheck() == FALSE)
	#endif
		)
    {
        if ( MApp_Logo_Load() ) // use 30ms
        {
            MApi_PNL_En(TRUE); // use 9ms

            MApp_PreInitPanelTiming(); // use 40ms

            MApp_Logo_Display(TRUE); // use 197ms

            //fixed logo blink a little when show logo
            MApi_PNL_SetBackLight(BACKLITE_INIT_SETTING); // use 200ms
        }
        else
        {
            MApi_PNL_En(TRUE);

            MApp_PreInitPanelTiming();

            MApi_PNL_SetBackLight(BACKLITE_INIT_SETTING);
        }
    }
#else
    /* If system enable DISABLE_LOGO, MApp_Scaler_SetWindow will be involved when logo shown. */
    MApp_Scaler_SetWindow(NULL, NULL, NULL, stSystemInfo[MAIN_WINDOW].enAspectRatio, SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), MAIN_WINDOW);
#endif


    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_ATVProc_Others_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());


#if ENABLE_TCON
    MApi_TCON_PNL_POWER_ENABLE();
#endif

    /* init audio */
    //msAPI_AUD_I2S_Amp_Reset(); // 0 ms,move down !

    MApp_ATVProc_Initialize_Others();


   DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_OCP_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());


    /*Initialize the OCP address then prepare the bitmap binary*/
    msAPI_OCP_Init(); // 0 ms

#if ENABLE_SZ_FACTORY_OVER_SCAN_FUNCTION
    G_OVERSCAN_HRatio=0;
    G_OVERSCAN_HPOSITION=0;
    G_OVERSCAN_VRatio=0;
    G_OVERSCAN_VPOSITION=0;
#endif

    msAPI_OCP_PrepareBitmapBinary();    // use 35ms

    msAPI_OCP_LoadBitmap(Osdcp_bmpHandle);  // use 31ms

    msAPI_OCP_PrepareStringBinary();    // use 97ms

    /* Initialize ir key value */
    u8KeyCode = KEY_NULL;

    /* Initialize channel move index*/
    g_u16ChannelOrinigalIndex = -1;

#if SCART_ALWAYS_OUTPUT_ATV
    g_u8switchsourceprocessing = FALSE;
#endif


    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_Environment_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

#if( ENABLE_SCRIPT_EXECUTE)
    msUS_EventInit();
#endif

#if ENABLE_OFFLINE_SIGNAL_DETECTION
    MApp_OffLineInit();
#endif
#if (INPUT_SCART_VIDEO_COUNT >= 1)
    //Scart plug-in, enable to switch to scart
    if (u8Switch2Scart == 1)
    {
        UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_SCART;
    }

    u8Switch2Scart = 0;
#endif

    MApp_Init_UIVariable();
    bIsInsideDTVManualScanMenu = FALSE;

#if (DISPLAY_LOGO)
    if (  (u8IsAutoSleep_Skip_Logo == TRUE)
      #if ENABLE_EPGTIMER_RECORDER_TURNOFFPANEL
       || (g_bTimerTypeRecord == TRUE)
      #endif
      #if ENABLE_CI_PLUS
       || (g_bTimeTypeOpRefresh == TRUE)
      #endif
       )
    {
        MApi_PNL_En(TRUE);
        MApp_PreInitPanelTiming();
    }
#else
    MApi_PNL_En(TRUE); // 0 ms
    MApp_PreInitPanelTiming();
#endif

    //Set GOP Start to wait VSync
    MApi_GOP_GWIN_SetForceWrite(DISABLE); // 0 ms

#if (ENABLE_CI_PLUS)
    msAPI_OP_OpCacheInit();
#endif

#if ENABLE_OAD
    MApp_OAD_Init();    // use 31ms
    /* Initial OAD Flag */
    bFoundOAD = FALSE;
    bNitFoundInvalidOAD=FALSE;
#endif //ENABLE_OAD


#if (GOP_TEST_CODE == 1)
    msAPI_GOP_TEST(0xFFFFFFFF);
#endif

    enFrotEndLockStatus = FRONTEND_UNKNOWN;
    enMVDVideoStatus = MVD_UNKNOWN_VIDEO;
    g_bPCSignalMonitor = FALSE;
    g_u8PCSignalMonitorCounter = 0;
    MApp_Scan_State_Init();

    MApp_DataInitVariable();

    MApp_SignalMonitor_Init();

#if ENABLE_EWS
    MApp_SI_SetLocationCode(stGenSetting.stMiscSetting.u8EWSLocationCode);
#endif

    MApp_ChannelChange_VariableInit();

    // 5V Antenna Monitor
    AdjustAntenna5VMonitor((EN_MENU_5V_AntennaPower)stGenSetting.g_SysSetting.f5VAntennaPower);

    UART_Clear();

    MApp_ZUI_Init();    // use 38ms


#if (ENABLE_CEC)
    msAPI_CEC_Init();   // use 1160ms
  #if(ENABLE_SW_CEC_WAKEUP)
    msAPI_CEC_CheckWakeUpPort();
  #endif
#endif


#if (ENABLE_ARC_CHANGE_SPDIF)
    MApp_CEC_ARC_TX_Control(TRUE);
#endif

#if ENABLE_ATSC
  #if(ATSC_CC == DTV_CC)
    MApp_CC_Initialize();
  #endif
#endif

    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());
}

void MApp_PreInit_Display_Step1_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

#if 0//(ENABLE_POST_INIT==TRUE)
    if (  (UI_INPUT_SOURCE_TYPE == UI_INPUT_SOURCE_HDMI)
      #if (INPUT_HDMI_VIDEO_COUNT >= 2)
       || (UI_INPUT_SOURCE_TYPE == UI_INPUT_SOURCE_HDMI2)
       #if (INPUT_HDMI_VIDEO_COUNT >= 3)
       || (UI_INPUT_SOURCE_TYPE == UI_INPUT_SOURCE_HDMI3)
       #endif
      #endif
       )
    {
        MApi_XC_HDMI_PostInit();
        MApp_PostInitDone();
    }
#endif

#if (DISPLAY_LOGO)
    if (u8IsAutoSleep_Skip_Logo == TRUE)
    {
        u8IsAutoSleep_Skip_Logo = FALSE;
        MApi_PNL_SetBackLight(BACKLITE_INIT_SETTING);
    }
    else
    {
    #if (ENABLE_POWERON_MUSIC)
        U32 u32FunctionEnteredTime = msAPI_Timer_GetTime0();
        printf("\nMusic played %d ms, still %d ms remaining\n", msAPI_Timer_DiffTimeFromNow(u32PowerOnMusicStartTime), POWERON_MUSIC_MIN_HOLD_ON_TIME-msAPI_Timer_DiffTimeFromNow(u32PowerOnMusicStartTime));
        while((bPowerOnMusicExist) && (msAPI_Timer_DiffTimeFromNow(u32PowerOnMusicStartTime)<POWERON_MUSIC_MIN_HOLD_ON_TIME))
        {
            if(msAPI_Timer_DiffTimeFromNow(u32FunctionEnteredTime)>20000)
            {
                //Time out
                break;
            }
        }
        MApp_Music_StopDecode();    // use 187ms

				#ifdef sNewAudioMuteStyle
				msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, 0, 0);
				#else
        MUTE_On();
        #endif
        //Recover to default audio request size setting
        //Because some APP seems doesn't send correct request size by itself
        MApi_AUDIO_SetMpegInfo(Audio_MPEG_infoType_MMFileSize, FILE_SIZE_2KB, 0);
    #endif
        MApp_Logo_Display(FALSE);
    }
#else
    MApi_PNL_SetBackLight(BACKLITE_INIT_SETTING);   //DISABLE);
#endif // #if (DISPLAY_LOGO)

#if (ENABLE_DTV)
    // This function must be before inputsource switch
    _MApp_DTVInit();    // use 50ms
#endif


#if ENABLE_EPGTIMER_RECORDER_TURNOFFPANEL
	if (  (g_bTimerTypeRecord == TRUE)
	#if ENABLE_CI_PLUS
		|| (g_bTimeTypeOpRefresh == TRUE)
	#endif
	#if ENABLE_OAD
		||MApp_OAD_IsScheduleOnCheck()
	#endif
		)
	{
		MApp_SetActiveStandbyMode(TRUE);
	}
#endif

#if( ENABLE_DIP_PWS)
    {
        MS_SYS_INFO pSysInfo;
        E_DATA_INPUT_SOURCE pDataInputSource;
        E_PWS_DIGITALIP_API_SouceInfo ePWSInputSource;

        MApp_Load_Input_Source_Setting();
        MApp_InputSource_SetSystemmInfo( UI_INPUT_SOURCE_TYPE, &pSysInfo , &pDataInputSource);

        //printf("###EDDIE:pSysInfo->enInputSourceType=0x%x \n",pSysInfo.enInputSourceType);

        ePWSInputSource=msAPI_SysInputSource2PWSInputSource(pSysInfo.enInputSourceType);
        MApi_DigitalIP_PWS_Init(ePWSInputSource);
    }
#endif

#if(ENABLE_POWERON_VIDEO)
    printf("msAPI_Pan_Task() Start Time:%d\n",msAPI_Timer_GetTime0());
    msAPI_Pan_Task();
    printf("msAPI_Pan_Task() End Time:%d\n",msAPI_Timer_GetTime0());
#endif

#if (XC_BRINGUP)
    UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_RGB;
#endif


    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());
}

void MApp_PreInit_Source_Change_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());
    //printf("MingYuan Presource MApp_PreInit_Source_Change_Init\n");

#if 1 //(DISPLAY_LOGO == FALSE)
    /* Source switch is called already when LOGO disable. */
    if(IsHDMIInUse() && msAPI_Power_IswakeupsourceCEC())    // use 543ms
    {
    #if (INPUT_HDMI_VIDEO_COUNT <= 1)
        MApp_InputSource_SwitchSource(UI_INPUT_SOURCE_HDMI, MAIN_WINDOW);
    #elif (INPUT_HDMI_VIDEO_COUNT <= 2)
        MApp_InputSource_SwitchSource(UI_INPUT_SOURCE_HDMI2, MAIN_WINDOW);
    #elif (INPUT_HDMI_VIDEO_COUNT <= 3)
        MApp_InputSource_SwitchSource(UI_INPUT_SOURCE_HDMI3, MAIN_WINDOW);
    #else
        MApp_InputSource_SwitchSource(UI_INPUT_SOURCE_HDMI4, MAIN_WINDOW);
    #endif
    }
    else
    {
        MApp_InputSource_SwitchSource(UI_INPUT_SOURCE_TYPE, MAIN_WINDOW);
    }
#endif

    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_Display_Step2_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

#if (ENABLE_PIP)
    if(IsPIPSupported())
    {
        MApi_XC_SetBorderFormat( stGenSetting.g_stPipSetting.u8BorderWidth, stGenSetting.g_stPipSetting.u8BorderWidth<<4, stGenSetting.g_stPipSetting.u8BorderWidth, stGenSetting.g_stPipSetting.u8BorderWidth<<4, 0xFC, SUB_WINDOW );
        if((MApp_Get_PIPMode() == EN_PIP_MODE_PIP) &&
            stGenSetting.g_stPipSetting.bBolderEnable)
        {
            MApi_XC_EnableBorder(stGenSetting.g_stPipSetting.bBolderEnable, SUB_WINDOW);
        }
    }

    if(MApp_Get_PIPMode() != EN_PIP_MODE_OFF)
    {
        if(stGenSetting.g_stPipSetting.enSubInputSourceType == UI_INPUT_SOURCE_NONE)
        {
            stGenSetting.g_stPipSetting.enPipMode = EN_PIP_MODE_OFF;
            stGenSetting.g_stPipSetting.enSubInputSourceType = MApp_InputSource_GetUIInputSourceType(MApp_InputSource_PIP_Get1stCompatibleSrc(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)));
        }
        else if(!MApp_InputSource_PIP_IsSrcCompatible(MApp_InputSource_GetInputSourceType(UI_INPUT_SOURCE_TYPE), MApp_InputSource_GetInputSourceType(stGenSetting.g_stPipSetting.enSubInputSourceType)))
        {
            //If sub src is not compatible with main src, find the first compatible src for sub window.
            stGenSetting.g_stPipSetting.enSubInputSourceType = MApp_InputSource_GetUIInputSourceType(MApp_InputSource_PIP_Get1stCompatibleSrc(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)));
        }


        MApp_InputSource_SwitchSource(stGenSetting.g_stPipSetting.enSubInputSourceType, SUB_WINDOW);

    }
    else
#endif // #if (ENABLE_PIP)
    {
        stSystemInfo[SUB_WINDOW].enInputSourceType = INPUT_SOURCE_NONE;
    }


#if (INPUT_SCART_VIDEO_COUNT >= 1)
    msAPI_GPIO_IsSourceJustConnected(INPUT_SOURCE_SCART);
    msAPI_GPIO_IsSourceJustDisConnected(INPUT_SOURCE_SCART);
#endif

#if (INPUT_SCART_VIDEO_COUNT >= 2)
    msAPI_GPIO_IsSourceJustConnected(INPUT_SOURCE_SCART2);
    msAPI_GPIO_IsSourceJustDisConnected(INPUT_SOURCE_SCART2);
#endif

#ifdef SCART_OUT_NEW_METHOD
    MDrv_VE_Init_SCART_OUT_MODE();
#endif

		#ifdef sNewAudioMuteStyle
		msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, stGenSetting.g_SoundSetting.Volume, 0);
		#else
		MUTE_Off();
		#endif

    switch (ST_VIDEO.eAspectRatio)
    {
        case EN_AspectRatio_JustScan:
        case EN_AspectRatio_Point_to_Point:
            //MApp_Scaler_EnableOverScan(DISABLE);
            break;

        case EN_AspectRatio_Zoom1:
        case EN_AspectRatio_Zoom2:
            MApp_Scaler_ResetZoomFactor(ST_VIDEO.eAspectRatio);
            //MApp_Scaler_EnableOverScan(ENABLE);
            break;

        default:
            //MApp_Scaler_EnableOverScan(ENABLE);
            break;
    }

    MApi_AUDIO_SPDIF_HWEN(TRUE);
    u8HDMIchkflag = 0;

    msAPI_FS_Init();

#if ENABLE_KEY_LOGGER
    MApp_KeyLogger_Init();
#endif

#if(ENABLE_UART_MSG_TO_USB)
    msDebug_UartToUSB_Init();
    if(g_stFactorySetting.stFacMiscSetting.eFactoryUSBLog== EN_FACTORY_USB_LOG_ON)
    {
        msDebug_UartToUSB_Set_Enable(TRUE);
    }
#endif

#if( ENABLE_SCRIPT_EXECUTE)
    msUS_EventInit();
    if(g_stFactorySetting.stFacMiscSetting.eFactoryExecuteScript== EN_FACTORY_EXECUTE_SCRIPT_ON)
    {
        msUS_ExecuteScript_Task();
        if(msUS_CheckEventPoolEmpty())
        {
            msUS_ScriptExecute(EN_SCRIPT_EVENT_INIT);
        }
    }
#endif

#if (ENABLE_DTV_EPG)
    stEpgTimerParam.stEpgTimer.enTimerType = EN_EPGUI_TIMER_REMINDER;
#endif

#if ENABLE_PVR
    msAPI_PVRFS_SetMemory(((BULK_FILE_SYSTEM_MEMORY_TYPE & MIU1) ? (BULK_FILE_SYSTEM_ADR | MIU_INTERVAL) : (BULK_FILE_SYSTEM_ADR)),BULK_FILE_SYSTEM_LEN);
    msAPI_PVRFS_SetDiskDriveIndex(0);
    msAPI_PVRFS_SetDeviceIndex(0);
    MApp_UiPvr_Init();
#endif

    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_PreInit_Others_Init(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

#if 0//FIXED_480I_50HZ_CVBS_OUT_GARBAGE
    MS_BOOL bVSizeMinIs576 = TRUE;
    MVOP_Handle stMvopHd = { E_MVOP_MODULE_MAIN };
#endif

    MApp_Gop_init();
#if ENABLE_ATSC_TTS
#if TTS_IS_ON_HK
    tts_init();
#endif
    MApp_TTSControlHandler_Init();
#endif

#if ((BRAZIL_CC )|| (ATSC_CC == ATV_CC))
/* // edit by jany
    msAPI_VBI_Init();
    MApp_CC_ResetExistInfo();
    MApp_CC_SetPeriodTime(0);     //0:check only once   x: check always
*/
    MApp_CC_Initialize();
#endif

#if MHEG5_ENABLE
    msAPI_MHEG5_SetBaseYear(DEFAULT_YEAR);
#endif

#ifdef OPEN_VERSION_DBG
 #if (OPEN_VERSION_DBG==ENABLE)

    MApp_AllVersion_Init();
    MApp_CountMax();
    MApp_CheckAllVersion();

 #endif // #if (OPEN_VERSION_DBG==ENABLE)
#endif // #ifdef OPEN_VERSION_DBG

#if (VECTOR_FONT_ENABLE) && (COPRO_MVF_ENABLE)
    msAPI_Font_MVF_WaitForGenerateBitmaps();
#endif

#if (ENABLE_BOOTTIME)
  #if (ENABLE_MAINPAGE_EFFECT)
    stGenSetting.g_SysSetting.fEnableOsdAnimation = EN_OSD_EFFECT_ROTATION_ONLY;
  #endif
    //stGenSetting.g_SysSetting.SystemSettingCS = MApp_SysSetting_CalChecksum();
    MApp_SysSetting_UpdateChecksum();
#endif

#if ENABLE_PVR
  #if (ENABLE_PVR_AESDMA)
   #ifdef PVR_UTOPIA
    MDrv_AESDMA_Init(0, 0, 1);
   #endif
  #endif
#endif

#if ENABLE_OAD
	if(OSD_COUNTRY_SETTING != OSD_COUNTRY_NEWZEALAND)
	{
	    MApp_OAD_Set_PowerOnCheck(TRUE);
	}
#endif

#ifdef MHEG5_BIG5_FONT_ENABLE
    msAPI_MHEG5_LoadBig5Font();
#endif

#if(ENABLE_S2_CHCHANGE_NOT_SAVE_DTAR)
    u32Enable_Change_Timer =0;
#endif

#if ENABLE_3D_PROCESS
    DB_3D_SETTING.en3DType = EN_3D_BYPASS;
    DB_3D_SETTING.en3DTo2DType= EN_3D_TO_2D_OFF;
#endif


#if 0//FIXED_480I_50HZ_CVBS_OUT_GARBAGE
    MDrv_MVOP_SetCommand(&stMvopHd, E_MVOP_CMD_SET_VSIZE_MIN, &bVSizeMinIs576);
#endif

    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}

void MApp_Power_On_Init_On(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START());

#if (ENABLE_AUTOTEST || ENABLE_BOOTTIME)
  #if (ENABLE_BOOTTIME==DISABLE)
    if (g_bAutobuildDebug == TRUE)
  #endif
    {
        gU32TmpTime = msAPI_Timer_DiffTimeFromNow(gU32BootStepTime);
        printf("[TIME] MApp_PreInit = %ld\n", gU32TmpTime);
    }
#endif

#if MHEG5_ENABLE
    if (IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
    {
        // Initial Beon for DTV
        msAPI_MHEG5_Bean_Init();
    }
#endif


#if(ENABLE_MSTV_UART_DEBUG)
    dbgVersionMessage();
#endif


    USERDBG(userdebug());

#if ENABLE_ATSC
  #if ENABLE_WIZARD_MODE
    if ( !stGenSetting.g_SysSetting.fFinishWizardMode )
    {
        MApp_TopStateMachine_SetTopState(STATE_TOP_DIGITALINPUTS);
    }
    else if ( IsAnyTVSourceInUse() )
  #else
    if ( IsAnyTVSourceInUse() )
  #endif
    {
        MApp_TopStateMachine_SetTopState(STATE_TOP_CHANNELCHANGE);
    }
    else
    {
        MApp_TopStateMachine_SetTopState(STATE_TOP_ANALOG_SHOW_BANNER);
    }
#else
    if( stGenSetting.stMiscSetting.bRunInstallationGuide )
    {
        MApp_TopStateMachine_SetTopState(STATE_TOP_INSTALLGUIDE);
    }
#if(ENABLE_PIP)
    else if ( IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW))
            ||(IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW)) && ((MApp_Get_PIPMode() != EN_PIP_MODE_OFF)))
            ||IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW))
            ||(IsSrcTypeATV(SYS_INPUT_SOURCE_TYPE(SUB_WINDOW))&& ((MApp_Get_PIPMode() != EN_PIP_MODE_OFF))))
#else
    else if ( IsAnyTVSourceInUse() )
#endif
    {
        MApp_TopStateMachine_SetTopState(STATE_TOP_CHANNELCHANGE);
    }
    else
    {
        MApp_TopStateMachine_SetTopState(STATE_TOP_ANALOG_SHOW_BANNER);
    }
#endif
    MApp_Preparation();


#if ENABLE_SBTVD_BRAZIL_CM_APP
    if(ANT_CATV == msAPI_ATV_GetCurrentAntenna())
    {
        msAPI_ATV_SetCurrentAntenna(ANT_AIR);

        if ( msAPI_ATV_GetActiveProgramCount()
           ||msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO)
           ||msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO))
        {
            msAPI_CHPROC_CM_InitOridial();
        }

        msAPI_ATV_SetCurrentAntenna(ANT_CATV);
    }
    else
    {
        if ( msAPI_ATV_GetActiveProgramCount()
           ||msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO)
           ||msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO)
           )
        {
            msAPI_CHPROC_CM_InitOridial();
        }
    }
#endif
DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END());

}


#if 0//(ENABLE_POST_INIT)

static BOOLEAN bPostInit= FALSE;
static BOOLEAN bStartPostInit= FALSE;
#define  POST_CHECK_COUNT 15000

void MApp_StartPostInit(void)
{
    bStartPostInit = TRUE;

    //printf("\n>> MApp_StartPostInit \n");
}

void MApp_PostInitDone(void)
{
    bPostInit = TRUE;
    //printf(" set bPostInit Done \n");
}

BOOLEAN MApp_Get_PostInit_Status(void)
{
    //printf("\r\n bPostInit->%d", bPostInit);
    return bPostInit;
}

void MApp_PostInit(void)
{
    static MS_U16 mainLoopCount=0;

    if (bPostInit)
        return;

#if 0
    if(mainLoopCount==1)
    {

        if( stGenSetting.stMiscSetting.bRunInstallationGuide )
        {
          //run InstallationGuide after font init.
        }
        else if ( IsAnyTVSourceInUse() )
        {
            printf("\r\n TV in USE, STATE_TOP_CHANNELCHANGE");
            MApp_TopStateMachine_SetTopState(STATE_TOP_CHANNELCHANGE);
        }
        else
        {
            //show banner afer font init
            g_bRealTimeMonitorOnly = TRUE;
            MApp_TopStateMachine_SetTopState(STATE_TOP_ANALOG_SHOW_BANNER);
        }



    }
#endif

    if((mainLoopCount <POST_CHECK_COUNT)&&(bStartPostInit==FALSE))
    {
        mainLoopCount++;
        return;
    }

    //printf("\n MApp_PostInit-START (%d) ", mainLoopCount);

    //MApp_LoadFontInit();
    //msAPI_OCP_PrepareBitmapBinary();
    //msAPI_OCP_LoadBitmap(Osdcp_bmpHandle);
    //msAPI_OCP_PrepareStringBinary();

    if (IsHDMIInUse() == FALSE)
    {
        MApi_XC_HDMI_PostInit();

    #if ENABLE_CEC
        ARC_CTRL_ON();

        // Why???
        /*if(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW) != INPUT_SOURCE_HDMI)
        {
            //printf("\r\n SYS_INPUT_SOURCE= %d", SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW));
            //printf("\r\n @@debug POST INIT-2 ARC_CTRL_ON");
            MApi_XC_Sys_SetHPD(ENABLE, INPUT_PORT_DVI1);
        }*/
    #endif

    #if ( ENABLE_CEC && ENABLE_SW_CEC_WAKEUP)
        msAPI_CEC_CheckWakeUpPort();
    #endif

    }

#if 0   // by Kenny.Tseng's suggestion, removed
    if( stGenSetting.stMiscSetting.bRunInstallationGuide )
    {
      MApp_TopStateMachine_SetTopState(STATE_TOP_INSTALLGUIDE);
    }
    else if ( IsAnyTVSourceInUse() )
    {
        //MApp_TopStateMachine_SetTopState(STATE_TOP_CHANNELCHANGE);

    }
  #ifdef ENABLE_DMP
    else if (IsStorageInUse())
    {
    }
  #endif
    else
    {
       MApp_TopStateMachine_SetTopState(STATE_TOP_ANALOG_SHOW_BANNER);
    }
#endif
    //printf("\r\n MApp_PostInit-END");

    bPostInit = TRUE;
}
#endif

#if(ENABLE_DTV)
#if(ENABLE_ATSC)
void MApp_Init_Demux(void)
{
    /* Init demux related variables, FID */
    u8GpsUtcOffset = 0;
    u8PcrFid = MSAPI_DMX_INVALID_FLT_ID;    // PCR
    u8AudFid = MSAPI_DMX_INVALID_FLT_ID;    // Audio PES
#if (ENABLE_ATSC_AD_FUNC)
    u8AudFid2= MSAPI_DMX_INVALID_FLT_ID;    // Audio PES
#endif
    u8VidFid = MSAPI_DMX_INVALID_FLT_ID;    // Video PES
    u8SttFid = MSAPI_DMX_INVALID_FLT_ID;    // STT
    u8MgtFid = MSAPI_DMX_INVALID_FLT_ID;    // MGT
    u8VctFid = MSAPI_DMX_INVALID_FLT_ID;    // VCT
    u8PatFid = MSAPI_DMX_INVALID_FLT_ID;    // PAT
    u8PmtFid = MSAPI_DMX_INVALID_FLT_ID;    // PMT
    u8RRTFid = MSAPI_DMX_INVALID_FLT_ID;    // RRT
    u8EasFid = MSAPI_DMX_INVALID_FLT_ID;    // EAS

    /* Init PSIP monitor flag */
    fEnablePatMonitor       = FALSE;    // PAT
    fEnablePmtMonitor       = FALSE;    // PMT
    fEnableSttMonitor       = FALSE;    // STT
    fEnableMgtMonitor       = FALSE;    // MGT
    fEnableVctMonitor       = FALSE;    // VCT
    fEnableRRTMonitor       = FALSE;    // RRT
    fEnableEasMonitor       = FALSE;    // EAS


    //sync method from T7 by zhiqiang.liu 2011-12-2 for deading loop while Searching some DTV in AIR
    fEnableTableMonitor     = FALSE;



    /* Set flag initial value */
    fTableVersionChanged    = FALSE;    // Version changed
    fVChipPassWordEntered   = FALSE;    // VChip password entered
    fEnableSignalCheck      = FALSE;    // Enable signal
    fTableAudioStreamTypeChange = FALSE;

    /* Init epg database */
    MApp_EpgDB_Init();
    MApp_EpgDB_Reset();
}
#endif // #if(ENABLE_ATSC)

#if (ENABLE_DTV_EPG && ENABLE_DVB)
#define DEBUG_INIT_EPG(x)   //x
BOOL MApp_PreInit_DVB_EPG(void)
{
    DEBUG_INIT_EPG( printf("MApp_PreInit_DVB_EPG()\n"); );


    DTV_CM_INIT_PARAMETER sDTVNotify;

//  #if (ENABLE_SBTVD_BRAZIL_APP==0)
    MS_EIT_INIT_PARAMETER sEITInitParameter;
//  #endif


    /*Clear EPG Timer before loading DataBase*/
    MApp_EpgTimer_InitTimerSettings(FALSE);



//  #if (ENABLE_SBTVD_BRAZIL_APP==0)
    memset(&sEITInitParameter,0,sizeof(MS_EIT_INIT_PARAMETER));
//  #endif


// #if (ENABLE_SBTVD_BRAZIL_APP==0)
    sEITInitParameter.u32PF_BufferAddress =_PA2VA(((EIT_PF_STRING_BUF_MEMORY_TYPE&MIU1)?EIT_PF_STRING_BUF_ADR|MIU_INTERVAL:EIT_PF_STRING_BUF_ADR));
    sEITInitParameter.pfNotify_EIT_Cur_PF=MApp_SI_Parse_EIT;
  #if SUPPORT_PVR_CRID
    if(EVENTDB_SDRAM_LEN>=0x0000840000)
    {
        sEITInitParameter.bEnablePVR_CRID=TRUE;
    }
  #endif
  #if ENABLE_SCHE_EXT
    sEITInitParameter.bEnableScheduleExtendEvent=TRUE;
  #endif
    MApp_EIT_Init(&sEITInitParameter);
// #endif // #if (ENABLE_SBTVD_BRAZIL_APP==0)

    memset(&sDTVNotify,0,sizeof(sDTVNotify));
    sDTVNotify.pfNotify_CM_MoveProgram=MApp_Epg_MoveSrvBuffer;
    sDTVNotify.pfNotify_CM_SwapProgram=MApp_Epg_SwapProgram;
    sDTVNotify.pfNotify_SrvPriorityHandler=MApp_Epg_SrvPriorityHandler;
    sDTVNotify.pfNotify_CM_RemoveProgram=MApp_Epg_RemoveProgram;
    msAPI_CM_Init_EPG(&sDTVNotify);

    MApp_EIT_All_Sche_ResetFilter();

    {
        U32 u32EventDbMIUAddrGap = ( (EVENTDB_SDRAM_MEMORY_TYPE&MIU1) ? MIU_INTERVAL : 0x0000000 );
        U32 u32EventDbAddr       = EVENTDB_SDRAM_ADR + u32EventDbMIUAddrGap;
        U32 u32ExtDbMIUAddrGap;//   = ( (EPGEXTDB_SDRAM_MEMORY_TYPE&MIU1) ? MIU_INTERVAL : 0x0000000 );
        U32 u32ExtDbAddr;//         = EPGEXTDB_SDRAM_ADR + u32ExtDbMIUAddrGap;

    #if ENABLE_SCHE_EXT
        u32ExtDbMIUAddrGap   = ( (EPGEXTDB_SDRAM_MEMORY_TYPE&MIU1) ? MIU_INTERVAL : 0x0000000 );
        u32ExtDbAddr         = EPGEXTDB_SDRAM_ADR + u32ExtDbMIUAddrGap;
    #else
        u32ExtDbMIUAddrGap=u32ExtDbAddr=0;
    #endif

    #if SUPPORT_PVR_CRID
        if(EVENTDB_SDRAM_LEN>=0x0000840000)
        {
            MAPP_EPG_SetFunctionFlag(eEN_PVR_CRID);
        }
    #endif

    #if ENABLE_SCHE_EXT
        MAPP_EPG_SetFunctionFlag(eEN_SCHE_EXT);
    #endif

  #if 0//def SUPPORT_FRANCE_H264_BY_1DDR//T4 1DDR H264 project has only 3800KB Event DB buffer, event number need reduce to 11200(Original is 16000)
   {
           MW_EN_EPG_DB_PARAM_CONFIG config;
           config.u32MaxNumOfEventInEPGDB = 11200;
           config.u32MaxNumOfEventInSrv = 512;
           MApp_EPGDB_ParamConfig(&config);
   }
  #endif

        MApp_EPGDB_Setup(MAX_DTVPROGRAM, _PA2VA(u32EventDbAddr), EVENTDB_SDRAM_LEN, _PA2VA(u32ExtDbAddr), EPGEXTDB_SDRAM_LEN);

        MApp_Epg_Init();
    }


    return TRUE;
}
#endif

#if(ENABLE_DVB)
#define DEBUG_INIT_SI(x) //x
void MApp_PreInit_InitSILib(void)
{
    MS_SI_INIT_PARAMETER sSIParameter;

    MApp_SI_Check_LibStructureSize();

    memset(&sSIParameter,0,sizeof(MS_SI_INIT_PARAMETER));

    sSIParameter.u8MaxServiceOneMux=MAX_VC_PER_PHYSICAL;
    sSIParameter.u32SIBufferStartAddress = _PA2VA(((SI_MONITOR_DB_MEMORY_TYPE & MIU1) ? (SI_MONITOR_DB_ADR | MIU_INTERVAL) : (SI_MONITOR_DB_ADR)));
    sSIParameter.u32SIBufferSize = SI_MONITOR_DB_LEN;
    sSIParameter.u32SINameBufferAddress = _PA2VA(((SRV_NAME_BUF_MEMORY_TYPE & MIU1) ? (SRV_NAME_BUF_ADR | MIU_INTERVAL) : (SRV_NAME_BUF_ADR)));

    DEBUG_INIT_SI(printf("sSIParameter.u8MaxServiceOneMux=%u\n", sSIParameter.u8MaxServiceOneMux););
    DEBUG_INIT_SI(printf("sSIParameter.u32SIBufferStartAddress=0x%X\n", sSIParameter.u32SIBufferStartAddress););
    DEBUG_INIT_SI(printf("sSIParameter.u32SIBufferSize=0x%X\n", sSIParameter.u32SIBufferSize););
    DEBUG_INIT_SI(printf("sSIParameter.u32SINameBufferAddress=0x%X\n", sSIParameter.u32SINameBufferAddress););
    DEBUG_INIT_SI(printf("SRV_NAME_BUF_LEN=0x%X\n", SRV_NAME_BUF_LEN););

    //printf("(SI_MAX_VC_PER_PHYSICAL*SI_MAX_SERVICE_NAME) %x %x\n",(SI_MAX_VC_PER_PHYSICAL*SI_MAX_SERVICE_NAME)
    //    ,SRV_NAME_BUF_LEN);
    // daniel_test
#if 0 // Check at build time
  #if( (SI_MAX_VC_PER_PHYSICAL*SI_MAX_SERVICE_NAME) > SRV_NAME_BUF_LEN )
    #error
  #endif
#endif
    if( (SI_MAX_VC_PER_PHYSICAL*SI_MAX_SERVICE_NAME) > SRV_NAME_BUF_LEN )
    {
        printf("\nWarning: (SI_MAX_VC_PER_PHYSICAL*SI_MAX_SERVICE_NAME) > SRV_NAME_BUF_LEN !\n");

    #if 1
        int i;

        for( i=0; i < 3; i++)
        {
            PRINT_CURRENT_LINE();
            //ASSERT(0);
        }
        printf("SI_MAX_VC_PER_PHYSICAL=%u\n", SI_MAX_VC_PER_PHYSICAL);
        printf(" SI_MAX_SERVICE_NAME=%u\n", SI_MAX_SERVICE_NAME);
        printf(" SI_MAX_VC_PER_PHYSICAL*SI_MAX_SERVICE_NAME=%u\n", SI_MAX_VC_PER_PHYSICAL*SI_MAX_SERVICE_NAME);
        printf(" SRV_NAME_BUF_LEN=%u\n", SRV_NAME_BUF_LEN);
    #endif
    }


#if(ENABLE_SBTVD_BRAZIL_APP)
    sSIParameter.u32NITScanTimeOut=4000;
#else
    sSIParameter.u32NITScanTimeOut=30000;
#endif


  #if (ENABLE_SBTVD_BRAZIL_APP == 0)
    sSIParameter.eSI_Type=SI_PARSER_DVB;
  #else
    sSIParameter.eSI_Type=SI_PARSER_ISDB_ABNT;
    sSIParameter.bDisableOneSegProgFilter=0;
  #endif

    sSIParameter.bSkipUnsupportService = FALSE;


  #if (ENABLE_DTV_EPG && ENABLE_DVB)
    //sSIParameter.bEnableEPG=TRUE;
    sSIParameter.bEnableEPG = MApp_PreInit_DVB_EPG();
  #endif

//  #if (ENABLE_SBTVD_BRAZIL_APP == 0)
    sSIParameter.pfNotify_PMT = MApp_SI_Parse_PMT;
//  #endif
  #if 1//ENABLE_TS_FILEIN
    sSIParameter.pfNotify_FileIn_PMT = MApp_SI_FileIn_Parse_PMT;
  #endif

  #if ENABLE_OAD
    MS_DMX_NOTIFY sDmxNotify;
    sDmxNotify.pfNotify_OAD_Init=MApp_OAD_Init;
    MApp_Dmx_Init_OAD(&sDmxNotify);
    sSIParameter.pfNotify_NIT = MApp_SI_Parse_NIT;
  #endif

  #if ENABLE_CI
    sSIParameter.pfNotify_SDT = MApp_SI_Parse_SDT;
  #endif

#if 1
    sSIParameter.enProgUpdateType=EN_SI_UPDATE_TYPE_SDT_PAT_COMBO;
  #if ENABLE_EWS
	sSIParameter.bEnablePATCRCcheck=TRUE;
  #endif
#endif


    MApp_SI_Init(&sSIParameter);

#if ENABLE_SAVE_MULTILINGUAL_SERVICE_NAME
    MApp_SI_SetSaveMultiLingualServiceNameNumber(MAX_MULTI_LINGUAL_SERVICE_NAME);
#endif

}
#endif

static void _MApp_DTVInit(void)
{
    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_START(););

#if( ENABLE_DVB )
    MApp_PreInit_InitSILib();

  #if (ENABLE_UPDATE_MULTIPLEX_VIA_NIT)
    if(IsDTVInUse() && (OSD_COUNTRY_SETTING == OSD_COUNTRY_NORWAY || OSD_COUNTRY_SETTING == OSD_COUNTRY_NEWZEALAND))
    {
    #if (LOSS_SIGNAL_ALTERNATIVE_ENABLE)
        MApp_TV_SetCheckAlternativeFlag(TRUE);
    #endif
        MApp_SI_SetCheckFreqChange(TRUE);
    }
  #endif

#endif


#if(ENABLE_ATSC)

    msAPI_DTVSystem_ATSC_Init();

    MApp_Init_Demux();

  #if ENABLE_ATSC_TTS
    MApp_TTSControlHandler_Init();
  #endif

#endif


    DEBUG_BOOT_TIME(DEBUG_FUNC_TIME_END(););
}

#endif // #if(ENABLE_DTV)

#if 1//GENSETTING_STORE_USE_NEW_METHOD
void MApp_Init_FlashVariable(void)
{
    g_MEMCOPYTYPE                           = MIU_FLASH2SDRAM;

    g_bFlashWriteProtectMethodUseM12        = ENABLE_FLASH_WRITE_PROTECT_METHOD_M12;


#if 0//( ENABLE_DATA_BASE_GEN_USE_2014 )

#else

    g_bOpenGenstStoreDBG                    = 0;//Open DBG Message

#endif

#if 0
    printf("RM_SERVICETYPE_LAST_START_ADR=0x%X\n", RM_SERVICETYPE_LAST_START_ADR);
    printf(" RM_SIZE_SERVICETYPE_LAST_DATA=0x%X\n", RM_SIZE_SERVICETYPE_LAST_DATA);

    //printf("RM_ATV_LAST_START_ADR=0x%X\n", RM_ATV_LAST_START_ADR);
    //printf(" RM_SIZE_ATV_LAST_DATA=0x%X\n", RM_SIZE_ATV_LAST_DATA);

    printf("RM_ADDR_DOWNLOAD=0x%X\n", RM_ADDR_DOWNLOAD);
    printf("RM_SIZE_GENSET=0x%X\n", RM_SIZE_GENSET);
#endif

}
#endif

#ifdef BENCH_CODE_USAGE
void MApp_Bench_AudioTest(void)
{
    msAPI_AUD_Bench_Check_Main();
}
#endif

//******************************************************************************

#undef MAPP_INIT_C
