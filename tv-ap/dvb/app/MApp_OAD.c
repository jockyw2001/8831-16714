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
#define _MAPP_OAD_C_

/******************************************************************************/
/*                              Header Files                                  */
/******************************************************************************/

// Global Layer
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Board.h"
#include "datatype.h"
#include "sysinfo.h"
#include "debug.h"

#if ENABLE_OAD
#include "msAPI_Bootloader.h"
#include "msAPI_oad_parser.h"
#include "msAPI_oad_process.h"
#include "msAPI_Timer.h"
#include "mapp_si.h"
#include "MApp_OAD.h"
#include "MApp_Scan.h"
#include "MApp_GlobalVar.h"
#include "MApp_Version.h"
#include "MApp_Key.h"
#include "imginfo.h"
#include "drvTVEncoder.h"
#include "MApp_TopStateMachine.h"
#include "SysInit.h"
#include "mapp_swupdate.h"
#include "MApp_InputSource.h"
#include "MApp_ChannelChange.h"
#include "MApp_USBDownload.h"
#include "MApp_TV.h"
#include "MApp_Standby.h"

//#include "mapp_si_private.h"
#include "apiXC.h"
#include "apiXC_Sys.h"
#include "MApp_ZUI_Main.h"
#include "ZUI_tables_h.inl"
#include "ZUI_exefunc.h"
#include "imginfo.h"
#include "msAPI_Ram.h"
#include "msAPI_Bootloader.h"
#include "msAPI_Tuner.h"
#include "msAPI_FreqTableDTV.h"
#include "msAPI_Tuner.h"
#include "msAPI_Global.h"
#include "MApp_GlobalFunction.h"
#include "drvSERFLASH.h"
#include "msAPI_FreqTableDTV.h"
#include "MApp_SaveData.h"
#include "MApp_ZUI_ACTautotuning.h"
#include "msAPI_MIU.h"
#include "MApp_SignalMonitor.h"
#include "msAPI_Flash.h"
#include "MApp_DataBase_Gen.h"
#if (BLOADER)
#include "MApp_BL_SI.h"
#include "MApp_BL_Demux.h"
#endif
#include "msAPI_DTVSystem.h"

/*------------------------------------------------------------------------------
| Define
*-----------------------------------------------------------------------------*/

#define DEBUG_OAD_SAVE(x)   //do{ PRINT_CURRENT_LINE(); x; } while(0)


#define MONITOR_DSI_TIME_OUT    120000//ms
#define MONITOR_DII_TIME_OUT    30000//ms
#define MONITOR_DDB_TIME_OUT    60000*60//ms
#define MONITOR_UNT_TIME_OUT    20000//ms
#define MONITOR_USER_TIME_OUT   60000 //30000//ms
#define MONITOR_SIGNAL_TIME_OUT 10000 //12000//ms
#define DATA_BC_ID_SSU          0x000A // DVB-SSU
#define DATA_BC_ID_UK_EC        0x0111 // UK Engineering Channel
#define DVB_OUI                 0x00015A
#define SSU_UPDATETYPE_STANDARD             0x01
#define SSU_UPDATETYPE_UNT_BROADCAST        0x02
#define SSU_UPDATETYPE_UNT_RETCHANNEL       0x03
#define MAX_DDB_MSGSIZE 4066
#define DOWNLOAD_BUFFER_ADR_OAD     (( DOWNLOAD_BUFFER_MEMORY_TYPE & MIU1) ? (DOWNLOAD_BUFFER_ADR | MIU_INTERVAL) : (DOWNLOAD_BUFFER_ADR))
#define DOWNLOAD_BUFFER_TYPE_OAD     (( DOWNLOAD_BUFFER_MEMORY_TYPE & MIU1) ? MIU_SDRAM12SDRAM0 : MIU_SDRAM2SDRAM)
#define DOWNLOAD_BUFFER_LEN_OAD      DOWNLOAD_BUFFER_LEN

#define VERSION_CHECK 1
#define FLASH_DIRECT_WRITE 0

#define MEMBER_OFFSET(struct_name, member_name) ( (U32) &(((struct_name *)0)->member_name) )                        // 16-bit Offset
#define EEPROM_OFFSET(member_name)              (RM_ADDR_DOWNLOAD+MEMBER_OFFSET(ST_DOWNLOAD_INFO, member_name))     // ST_DOWNLOAD_INFO member offset on EEPROM

#define SW_UPDATE_BLOCK_SIZE    0x10000    //SIZE_64KB
#define SW_UPDATE_ERASE_SIZE    0x800000
#define OAD_SCAN_WAIT_TABLE_TIME 20000  // 10 seconds
#define LOWER_VERSION_DOWNLOAD  0
#define HW_MODEL_VER_CHECK      1

#if (BLOADER)
#define MAPP_DMX_SET_PID(a,b)   MApp_BL_Dmx_SetFid(a,(EN_BL_FID)b)
#define MAPP_DMX_GET_PID(a)     MApp_BL_Dmx_GetFid((EN_BL_FID)a)
#define MAPP_DMX_GETSI_4K_SECBUFFER()     MApp_BL_Dmx_GetSI4KSectionBuffer()
#define OAD_MONITOR_FID      EN_BL_OAD_MONITOR_FID
#define OAD_DOWNLOAD_FID     EN_BL_OAD_DOWNLOAD_FID
#else
#define MAPP_DMX_SET_PID(a,b)   MApp_Dmx_SetFid(a,(EN_FID)b)
#define MAPP_DMX_GET_PID(a)   MApp_Dmx_GetFid((EN_FID)a)
#define MAPP_DMX_GETSI_4K_SECBUFFER()     MApp_Dmx_GetSI4KSectionBuffer()

#define OAD_MONITOR_FID      EN_OAD_MONITOR_FID
#define OAD_DOWNLOAD_FID     EN_OAD_DOWNLOAD_FID
#endif

#define SIMPLE  0
#define ENHANCE 1
#define DATA_CAROUSEL   0
#define OBJ_CAROUSEL    1
#define MAX_SIGNAL_COUNT    30
#define MAX_CAROUSEL_TYPE   2

typedef struct
{
    U16 u16TSID;
    U16 u16ONID;
    U16 u16SID;
    BOOLEAN bUsed;
}NIT_SIGNAL_DATA;

typedef struct
{
    NIT_SIGNAL_DATA stNitSignal[MAX_SIGNAL_COUNT];
    U8 u8SignalCount;
}OAD_NIT_SIGNAL;

typedef struct
{
    U16 u16OAD_PID;
    U16 u16SID;
    U8  u8UpdateType;
    U8  u8Association_tag;
    U8  u8Tag;
    BOOLEAN bUsed;
}PMT_SIGNAL_DATA;
typedef struct
{
    PMT_SIGNAL_DATA stPmtSignal[MAX_SIGNAL_COUNT];
    U8 u8SignalCount;
}OAD_PMT_SIGNAL;

// For NZ OAD start
typedef struct
{
    MS_U8 type; //0: PMT; 1: NIT, not used at present
    MS_U16 PID;
    MEMBER_SERVICETYPE bServiceType;
    MS_U16 wCurrentPosition;
    MS_U16 wOriginalNetwork_ID_OAD;
    MS_U16 wTransportStream_ID_OAD;
    MS_U16 wService_ID_OAD;
    EN_OAD_MONITOR_STATE enNextMonitorState;
    MS_U8 *reserved;
}ST_OAD_SIGNAL;

/*------------------------------------------------------------------------------
| Variable
*-----------------------------------------------------------------------------*/
static U16 wOad_PID;
static MS_TP_SETTING stTPSetting;
static U8 cRFChannelNumber;
static U16 wTransportStream_ID_OAD;
static U16 wOriginalNetwork_ID_OAD;
static U16 wService_ID_OAD;
static U32 _u32DL_StartTime;
static U32 _u32DL_EndTime;
static U8 _u8UpdateType;

static BOOLEAN _bDVB_OUI_Enable;
static BOOLEAN _bPowerOnCheck;
static BOOLEAN _bScheduleOnCheck;
static BOOLEAN _bOadScanCheck;
static BOOLEAN _bStandbyOffCheck;
#if (!BLOADER)
static BOOLEAN _bCheckScheduleMsg;
#endif
static BOOLEAN _bPMT_FoundSSU_DATA;
static BOOLEAN _bPMT_FoundSSU_OBJ;
static BOOLEAN _bNIT_Simple_LinkSSU;
static BOOLEAN _bNIT_DVB_LinkSSU;
static BOOLEAN _NIT_Ready;
static BOOLEAN _PMT_Ready;
static BOOLEAN _bOADRunning;
static BOOLEAN _bDisplayScheduleMsg;
static BOOLEAN _bCheck_NIT_First;
static BOOLEAN _bCheck_DSITimeOut;

static U16 wPrev_TSID;
static U16 wPrev_ONID;
static U16 wPrev_SID;
#if (!BLOADER)
static U32 u32WaitPmtSIDTimer;
#endif
static U16 _wLinkageSID;
static U16 _wOADPID;
#if (BLOADER)
static BOOLEAN _BL_PmtReady;
#endif
static MEMBER_SERVICETYPE ePrev_ServiceType;
static U16 u16Prev_Position;
//static U8 cOad_RF = INVALID_PHYSICAL_CHANNEL_NUMBER;
static U32 tvVersion,tsVersion;
U32 toSaveVersion=0x0;
static U8 versionNum = 0xff;
static U32 u32DownloadSize = 0x0;
static EN_OAD_MONITOR_STATE _enMonitorState;
static EN_OAD_DOWNLOAD_STATE _enDownloadState;
static EN_OAD_APP_STATE _enAppState;
static EN_OAD_SIGALPROCESS_STATE _enSignalState;
static UNT_DESCRIPTOR untDescriptor ;
static MEMBER_SERVICETYPE bServiceType;
static WORD wCurrentPosition;
static U16 u16StartBlock, u16EndBlock, u16BlockNo;
static U32 u32FlashStartAddr,u32FlashEndAddr;
static MS_TP_SETTING stOadTPSetting;
static U8 u8OadRFCh;
static U32 u32OadScanWaitTableTimer;
static EN_OAD_SCAN_STATE enOADScanState=STATE_OAD_SCAN_INIT;
static BOOLEAN bNITSignal_DSI;
#if (CUSTOMER_OUI==ENGEL_OUI)
static U32 u4swversion;
#endif
static BOOLEAN _bOAD_PowerOnScreen = FALSE;
static BOOLEAN _bOadScanWaitTimerCheck = FALSE;
#if (!BLOADER)
extern BOOLEAN bShowOadScanPage;
#endif
static MEMBER_SERVICETYPE ePrev_ServiceTypePower;
static U16 u16Prev_PositionPower;

extern pZUIDrawCB pZUIDrawPercentageCB;
extern void MApp_ZUI_OADSwUpdate_ProgressBar(U8 percent) ;

#if (BLOADER)
extern void MApp_BL_DisplaySystem(U8 u8Percent);
extern void MApp_BL_DisplaySystem_clear(void);
extern void MApp_BL_DisplaySystem_setStatus(S8 *status);
#endif //(BLOADER)
extern BOOLEAN _MApp_ZUI_API_WindowProcOnIdle(void);
extern void MApp_ZUI_ACT_ShowDownloadUI(void);
static BOOLEAN MApp_OAD_ChannelChange(U16 u16TSID, U16 u16ONID, U16 u16SID);
static void MApp_OAD_Reset( void );
static void MApp_OAD_SignalReset(void);
static EN_OAD_SIGALPROCESS_STATE _MApp_OAD_GetSignalState(void);
static void _MApp_OAD_SetSignalState(EN_OAD_SIGALPROCESS_STATE state);
static void MApp_OAD_AddNitSignal(NIT_SIGNAL_DATA *pstNitSignal);
static void MApp_OAD_AddPmtSignal(PMT_SIGNAL_DATA *pstPmtSignal);

static OAD_NIT_SIGNAL _stOadNitSignal;
static OAD_PMT_SIGNAL _stOadPmtSignal;
static BOOLEAN _bSignalForStandby = FALSE;
static ST_OAD_SIGNAL _stOADSignalForStandby;
// For NZ OAD end

/*------------------------------------------------------------------------------
| Functions
*-----------------------------------------------------------------------------*/
void MApp_OAD_SetPowerOnScreen(void)
{
    _bOAD_PowerOnScreen = TRUE;
}

BOOLEAN MApp_OAD_IsPowerOnScreen(void)
{
    return _bOAD_PowerOnScreen;
}

void MApp_OAD_Set_StandbyOffCheck(BOOLEAN bEnable)
{
    OAD_DEBUG(printf(">> MApp_OAD_Set_StandbyOffCheck\n"););
    _bStandbyOffCheck = bEnable;
    if(bEnable)
    {
    #if (!BLOADER)
        msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_INTERNAL_3_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
        msAPI_Timer_Delayms(20);
        MApi_PNL_SetBackLight(DISABLE);
    #endif
        _bDVB_OUI_Enable = TRUE;
        MApp_OAD_Init();
    }
}

BOOLEAN MApp_OAD_IsStandbyOffCheck(void)
{
    return _bStandbyOffCheck;
}
void MApp_OAD_Set_PowerOnCheck(BOOLEAN bEnable)
{
    if(IsDTVInUse()&& MApp_OAD_IsUserSelectOn())
    {
        if((msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO)+ \
            msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO)+ \
            msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO))>0)
        {
            OAD_DEBUG( printf(">> MApp_OAD_Set_PowerOnCheck\n") );
            if((!_bScheduleOnCheck) && bEnable)
            {
                _bPowerOnCheck = bEnable;
                _bDVB_OUI_Enable = TRUE;
            }
        }
    }
}

BOOLEAN MApp_OAD_IsPowerOnCheck(void)
{
    return _bPowerOnCheck;
}

void MApp_OAD_Set_ScheduleOnCheck(void)
{
    if(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW) && MApp_OAD_IsUserSelectOn() && msAPI_Power_IswakeupsourceRTC())
    {
        if((msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO)+ \
            msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO)+ \
            msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO))>0)
        {
            printf("\r\n >>>> [MApp_OAD_Set_ScheduleOnCheck, wakeup by RTC!!!]");
            _bScheduleOnCheck = TRUE;
            _bDVB_OUI_Enable = TRUE;
        }
    }
}

BOOLEAN MApp_OAD_IsScheduleOnCheck(void)
{
    return _bScheduleOnCheck;
}

void MApp_OAD_Set_OadScanCheck(void)
{
    OAD_DEBUG(printf(">> MApp_OAD_Set_OadScanCheck\n"));
    _bOadScanCheck = TRUE;
    _bDVB_OUI_Enable = TRUE;
    //MApp_OAD_Init();
}

BOOLEAN MApp_OAD_IsOadScanCheck(void)
{
    return _bOadScanCheck;
}

void MApp_OAD_Set_PMT_Ready(BOOLEAN bReady)
{
    _PMT_Ready = bReady;
}

void MApp_OAD_Set_NIT_Ready(BOOLEAN bReady)
{
    _NIT_Ready = bReady;
}

void MApp_OAD_Load_Setting(ST_DOWNLOAD_INFO* pOadSetting )
{
    memcpy( pOadSetting,
        (void *)_PA2VA(RAM_DISK_MEM_ADDR+RM_OAD_SETTING_START_ADDR),
        sizeof(ST_DOWNLOAD_INFO));

    //MApp_ReadDatabase(, (BYTE *)pOadSetting, sizeof(ST_DOWNLOAD_INFO) );
}

void MApp_OAD_Save_Setting(ST_DOWNLOAD_INFO* pOadSetting )
{
#if (BLOADER)
    memcpy( (void *)_PA2VA(RAM_DISK_MEM_ADDR+RM_OAD_SETTING_START_ADDR),
            pOadSetting,
            sizeof(ST_DOWNLOAD_INFO));
#else
    MApp_WriteDatabase(RM_OAD_SETTING_START_ADDR, (BYTE *)pOadSetting, sizeof(ST_DOWNLOAD_INFO) );
#endif
}

void MApp_OAD_SetInfo_ForBL(U16 u16PID, U32 u32Freq, U8 u8BandWidth)
{
    //printf("S pid: 0x%x, freq: %ld, bw: 0x%bx\n", u16PID, u32Freq, u8BandWidth);
    DEBUG_OAD_SAVE(printf("MApp_OAD_SetInfo_ForBL(u16PID=%u, u32Freq=%u)\n", u16PID, u32Freq););
    U8 u8Country = (U8)msAPI_CM_GetCountry();
#if (EEPROM_DB_STORAGE==EEPROM_SAVE_NONE)
   {
        static U32 savedVersion=0;
        ST_DOWNLOAD_INFO dl_info;
        {
            U16 u16PID_saved=0;
            U32 u32Freq_saved=0;
            U8 u8BandWidth_saved=0;
            U8 u8Country_Saved=0;

            MApp_OAD_GetInfo_BL(&u16PID_saved, &u32Freq_saved, &u8BandWidth_saved,&u8Country_Saved);
            if((u16PID == u16PID_saved) && (u32Freq == u32Freq_saved) && (u8BandWidth == u8BandWidth_saved) && (u8Country == u8Country_Saved))
            {
                return;
            }
        }
        if(VERSION_CHECK)
        {
            if(savedVersion >= toSaveVersion)
            {
                return;
            }
            savedVersion = toSaveVersion;
        }

        memset(&dl_info, 0, sizeof(dl_info));
        dl_info.u8DL_OAD_TSFreq1 = (U8)((u32Freq & 0xFF000000)>>24);
        dl_info.u8DL_OAD_TSFreq2 = (U8)((u32Freq & 0x00FF0000)>>16);
        dl_info.u8DL_OAD_TSFreq3 = (U8)((u32Freq & 0x0000FF00)>>8);
        dl_info.u8DL_OAD_TSFreq4 = (U8)((u32Freq & 0x000000FF)>>0);
        dl_info.u8DL_OAD_PID_High =  (U8)(u16PID >> 8);
        dl_info.u8DL_OAD_PID_Low =  (U8)(u16PID &0x00FF);
        dl_info.u8DL_OAD_BW = u8BandWidth;
        dl_info.u8DL_OAD_Country = (U8)msAPI_CM_GetCountry();

    #if( ENABLE_OAD_DATA_SAVE_TO_DB_CH )
        MApp_OAD_Save_Setting(&dl_info);
    #else
        MDrv_FLASH_WriteProtect_Disable_Range_Set(SYSTEM_BANK_SIZE * OAD_DB_BANK, SYSTEM_BANK_SIZE);
        U32 dst = (SYSTEM_BANK_SIZE * OAD_DB_BANK);
        OAD_DEBUG( printf("OAD_DB_BANK 0x%x\n", OAD_DB_BANK) );
        OAD_DEBUG( printf("dst 0x%x\n", dst) );

        MDrv_FLASH_AddressErase(dst, SYSTEM_BANK_SIZE, TRUE);
        MDrv_FLASH_Write(dst, sizeof(dl_info), (U8*)&dl_info);
        msAPI_Flash_Set_WriteProtect(ENABLE);
    #endif
    }
    OAD_DEBUG(printf("MApp_OAD_SetInfo_ForBL() ok\n"));
#else
    // OAD PID
    msAPI_rmWriteByte(EEPROM_OFFSET(u8DL_OAD_PID_High), (U8)(u16PID >> 8));
    msAPI_rmWriteByte(EEPROM_OFFSET(u8DL_OAD_PID_Low), (U8)(u16PID &0x00FF));

    // Phyical Frequency
    msAPI_rmWriteByte(EEPROM_OFFSET(u8DL_OAD_TSFreq1), (U8)((u32Freq & 0xFF000000)>>24));
    msAPI_rmWriteByte(EEPROM_OFFSET(u8DL_OAD_TSFreq2), (U8)((u32Freq & 0x00FF0000)>>16));
    msAPI_rmWriteByte(EEPROM_OFFSET(u8DL_OAD_TSFreq3), (U8)((u32Freq & 0x0000FF00)>>8));
    msAPI_rmWriteByte(EEPROM_OFFSET(u8DL_OAD_TSFreq4), (U8)(u32Freq & 0x000000FF));

    // DVB-T System Bandwidth
    msAPI_rmWriteByte(EEPROM_OFFSET(u8DL_OAD_BW), u8BandWidth);
#endif
}

void MApp_OAD_GetInfo_BL(U16* u16PID, U32* u32Freq, U8* u8BandWidth, U8* u8Country)
{
    DEBUG_OAD_SAVE(printf("MApp_OAD_GetInfo_BL()\n"););
#if (EEPROM_DB_STORAGE==EEPROM_SAVE_NONE)
    ST_DOWNLOAD_INFO dl_info;

    memset(&dl_info, 0, sizeof(dl_info));
#if( ENABLE_OAD_DATA_SAVE_TO_DB_CH )
    MApp_OAD_Load_Setting(&dl_info);
#else
    U32 dst = (SYSTEM_BANK_SIZE * OAD_DB_BANK);
    MDrv_FLASH_Read(dst, sizeof(dl_info), (U8*)&dl_info);
#endif
    *u32Freq = 0;
    *u32Freq |= ((U16)(dl_info.u8DL_OAD_TSFreq1) << 24);
    *u32Freq |= ((U16)(dl_info.u8DL_OAD_TSFreq2) << 16);
    *u32Freq |= ((U16)(dl_info.u8DL_OAD_TSFreq3) << 8);
    *u32Freq |= (U16)(dl_info.u8DL_OAD_TSFreq4);
    *u16PID = 0;
    *u16PID |= ((U16)(dl_info.u8DL_OAD_PID_High) << 8);
    *u16PID |= (U16)(dl_info.u8DL_OAD_PID_Low);
    *u8BandWidth = dl_info.u8DL_OAD_BW;
    *u8Country = dl_info.u8DL_OAD_Country;
#else
    U8 u8Temp;

    // OAD PID
    *u16PID = 0;
    msAPI_rmBurstReadBytes(EEPROM_OFFSET(u8DL_OAD_PID_High), &u8Temp, 1);
    *u16PID |= ((U16)(u8Temp) << 8);
    msAPI_rmBurstReadBytes(EEPROM_OFFSET(u8DL_OAD_PID_Low), &u8Temp, 1);
    *u16PID |= (U16)(u8Temp);

    // Phyical Frequency
    *u32Freq = 0;
    msAPI_rmBurstReadBytes(EEPROM_OFFSET(u8DL_OAD_TSFreq1), &u8Temp, 1);
    *u32Freq |= ((U32)(u8Temp)<<24);
    msAPI_rmBurstReadBytes(EEPROM_OFFSET(u8DL_OAD_TSFreq2), &u8Temp, 1);
    *u32Freq |= ((U32)(u8Temp)<<16);
    msAPI_rmBurstReadBytes(EEPROM_OFFSET(u8DL_OAD_TSFreq3), &u8Temp, 1);
    *u32Freq |= ((U32)(u8Temp)<<8);
    msAPI_rmBurstReadBytes(EEPROM_OFFSET(u8DL_OAD_TSFreq4), &u8Temp, 1);
    *u32Freq |= (U32)(u8Temp);


    // DVB-T System Bandwidth
    msAPI_rmBurstReadBytes(EEPROM_OFFSET(u8DL_OAD_BW), &u8Temp, 1);
    *u8BandWidth = u8Temp;
#endif
    //printf("G pid: 0x%x, freq: %ld, bw: 0x%bx\n", *u16PID, *u32Freq, *u8BandWidth);
}

void MApp_OAD_SetInfo(void)
{
    DEBUG_OAD_SAVE(printf("MApp_OAD_SetInfo()\n"););
#if (EEPROM_DB_STORAGE==EEPROM_SAVE_NONE)
    ST_DOWNLOAD_INFO dl_info;
    BOOL bUpdate = FALSE;

    memset(&dl_info, 0, sizeof(dl_info));
#if( ENABLE_OAD_DATA_SAVE_TO_DB_CH )
    MApp_OAD_Load_Setting(&dl_info);
#else
    U32 dst = (SYSTEM_BANK_SIZE * OAD_DB_BANK);
    OAD_DEBUG( printf("OAD_DB_BANK 0x%x\n", OAD_DB_BANK) );
    OAD_DEBUG( printf("dst 0x%x\n", dst) );
    MDrv_FLASH_Read(dst, sizeof(dl_info), (U8*)&dl_info);
#endif

    // monitor state
    if((EN_OAD_MONITOR_STATE)dl_info.u8DL_OAD_MonitorState != MApp_OAD_GetMonitorState())
    {
        dl_info.u8DL_OAD_MonitorState = MApp_OAD_GetMonitorState();
        bUpdate = TRUE;
    }
    // wOriginalNetwork_ID_OAD
    if(dl_info.u16DL_OAD_NID != wOriginalNetwork_ID_OAD)
    {
        dl_info.u16DL_OAD_NID = wOriginalNetwork_ID_OAD;
        bUpdate = TRUE;
    }

    // wTransportStream_ID_OAD
    if(dl_info.u16DL_OAD_TID != wTransportStream_ID_OAD)
    {
        dl_info.u16DL_OAD_TID = wTransportStream_ID_OAD;
        bUpdate = TRUE;
    }

    // wService_ID_OAD
    if(dl_info.u16DL_OAD_SID != wService_ID_OAD)
    {
        dl_info.u16DL_OAD_SID = wService_ID_OAD;
        bUpdate = TRUE;
    }

    // untDescriptor.untLocation.association_tag
    if(dl_info.u16DL_OAD_AssociationTag != untDescriptor.untLocation.association_tag)
    {
        dl_info.u16DL_OAD_AssociationTag = untDescriptor.untLocation.association_tag;
        bUpdate = TRUE;
    }
    // cOad_RF
    //dl_info.u8DL_OAD_TSFreq1 = cOad_RF;

    // auDLSchedule_time
    if(TRUE == memcmp(dl_info.auDLSchedule_time, untDescriptor.untSchedule, (sizeof(UNT_SCHEDULE)*MAX_SCHEDULE_COUNT)))
    {
        memcpy(dl_info.auDLSchedule_time, untDescriptor.untSchedule, (sizeof(UNT_SCHEDULE)*MAX_SCHEDULE_COUNT));
        bUpdate = TRUE;
    }

    // _u32DL_StartTime
    if(dl_info.u32DL_OAD_StartTime != _u32DL_StartTime)
    {
        dl_info.u32DL_OAD_StartTime = _u32DL_StartTime;
        bUpdate = TRUE;
    }
    // _u32DL_EndTime
    if(dl_info.u32DL_OAD_EndTime != _u32DL_EndTime)
    {
        dl_info.u32DL_OAD_EndTime = _u32DL_EndTime;
        bUpdate = TRUE;
    }
    if(dl_info.u8DL_OAD_ScheduleOn != (U8)_bScheduleOnCheck)
    {
        dl_info.u8DL_OAD_ScheduleOn = (U8)_bScheduleOnCheck;
        bUpdate = TRUE;
    }
    if(bUpdate == TRUE)
    {
    #if( ENABLE_OAD_DATA_SAVE_TO_DB_CH )
        MApp_OAD_Save_Setting(&dl_info);
    #else
        MDrv_FLASH_WriteProtect_Disable_Range_Set(SYSTEM_BANK_SIZE * OAD_DB_BANK, SYSTEM_BANK_SIZE); // MDrv_FLASH_WriteProtect(DISABLE); // <-@@@
        MDrv_FLASH_AddressErase(dst, SYSTEM_BANK_SIZE, TRUE);
        MDrv_FLASH_Write(dst, sizeof(dl_info), (U8*)&dl_info);
        msAPI_Flash_Set_WriteProtect(ENABLE);
    #endif
    }
    //OAD_DEBUG(printf("SetInfo=%x,%x,%x,%x,%x,%x,%x\n",MApp_OAD_GetMonitorState(),wOriginalNetwork_ID_OAD,wTransportStream_ID_OAD,wService_ID_OAD,untDescriptor.untSchedule.u32StartTime,untDescriptor.untSchedule.u32EndTime,untDescriptor.untLocation.association_tag)) ;
#else //(EEPROM_DB_STORAGE==EEPROM_SAVE_NONE)
    ST_DOWNLOAD_INFO dl_info;
    BOOL bUpdate = FALSE;

    memset(&dl_info, 0, sizeof(dl_info));

    // monitor state
    msAPI_rmBurstReadBytes(EEPROM_OFFSET(u8DL_OAD_MonitorState),(U8*)&dl_info.u8DL_OAD_MonitorState,1);
    // wOriginalNetwork_ID_OAD
    msAPI_rmBurstReadBytes(EEPROM_OFFSET(u16DL_OAD_NID), (U8*)&dl_info.u16DL_OAD_NID, 2);
    // wTransportStream_ID_OAD
    msAPI_rmBurstReadBytes(EEPROM_OFFSET(u16DL_OAD_TID), (U8*)&dl_info.u16DL_OAD_TID, 2);
    // wService_ID_OAD
    msAPI_rmBurstReadBytes(EEPROM_OFFSET(u16DL_OAD_SID), (U8*)&dl_info.u16DL_OAD_SID, 2);
    // untDescriptor.untLocation.association_tag
    msAPI_rmBurstReadBytes(EEPROM_OFFSET(u16DL_OAD_AssociationTag), (U8*)&dl_info.u16DL_OAD_AssociationTag,2);
    msAPI_rmBurstReadBytes(EEPROM_OFFSET(u8DL_OAD_TSFreq1),(U8*)&dl_info.u8DL_OAD_TSFreq1,1);
#if (BOOTLOADER_SYSTEM == 0)
    // auDLSchedule_time
    msAPI_rmBurstReadBytes(EEPROM_OFFSET(auDLSchedule_time), (U8*)dl_info.auDLSchedule_time,48);
#endif

    // monitor state
    if((dl_info.u8DL_OAD_MonitorState != MApp_OAD_GetMonitorState())
        || (dl_info.u16DL_OAD_NID != wOriginalNetwork_ID_OAD)
        || (dl_info.u16DL_OAD_TID != wTransportStream_ID_OAD)
        || (dl_info.u16DL_OAD_SID != wService_ID_OAD)
        || (dl_info.u16DL_OAD_AssociationTag != untDescriptor.untLocation.association_tag)
        || (TRUE == memcmp(dl_info.auDLSchedule_time, untDescriptor.untSchedule, (sizeof(UNT_SCHEDULE)*MAX_SCHEDULE_COUNT))))
    {
        msAPI_rmWriteByte(EEPROM_OFFSET(u8DL_OAD_MonitorState),MApp_OAD_GetMonitorState());

        // wOriginalNetwork_ID_OAD
        msAPI_rmBurstWriteBytes(EEPROM_OFFSET(u16DL_OAD_NID), (U8*)&wOriginalNetwork_ID_OAD, 2);

        // wTransportStream_ID_OAD
        msAPI_rmBurstWriteBytes(EEPROM_OFFSET(u16DL_OAD_TID), (U8*)&wTransportStream_ID_OAD, 2);

        // wService_ID_OAD
        msAPI_rmBurstWriteBytes(EEPROM_OFFSET(u16DL_OAD_SID), (U8*)&wService_ID_OAD, 2);

        // untDescriptor.untLocation.association_tag
        msAPI_rmBurstWriteBytes(EEPROM_OFFSET(u16DL_OAD_AssociationTag),(U8*)&untDescriptor.untLocation.association_tag,2);

        // cOad_RF
        //msAPI_rmWriteByte(EEPROM_OFFSET(u8DL_OAD_TSFreq1),cOad_RF);
#if (BOOTLOADER_SYSTEM == 0)
        // auDLSchedule_time
        msAPI_rmBurstWriteBytes(EEPROM_OFFSET(auDLSchedule_time), (U8*)untDescriptor.untSchedule, sizeof(UNT_SCHEDULE)*MAX_SCHEDULE_COUNT);
#endif
    }
    OAD_DEBUG(printf("SetInfo=%x,%x,%x,%x,%x,%x,%x\n",MApp_OAD_GetMonitorState(),wOriginalNetwork_ID_OAD,wTransportStream_ID_OAD,wService_ID_OAD,untDescriptor.untSchedule.u32StartTime,untDescriptor.untSchedule.u32EndTime,untDescriptor.untLocation.association_tag)) ;
#endif //(EEPROM_DB_STORAGE==EEPROM_SAVE_NONE)
}

void MApp_OAD_GetInfo(EN_OAD_EEPROM_STATE state)
{
    DEBUG_OAD_SAVE(printf("MApp_OAD_GetInfo(state=%u)\n", state););
#if (EEPROM_DB_STORAGE==EEPROM_SAVE_NONE)
    ST_DOWNLOAD_INFO dl_info;
    memset(&dl_info, 0, sizeof(dl_info));
#if( ENABLE_OAD_DATA_SAVE_TO_DB_CH )
    MApp_OAD_Load_Setting(&dl_info);
#else
    U32 dst = (SYSTEM_BANK_SIZE * OAD_DB_BANK);
    MDrv_FLASH_Read(dst, sizeof(dl_info), (U8*)&dl_info);
#endif
    if (state==EN_OAD_EEPROM_MONITOR)
    {
        // monitor state
        _enMonitorState = (EN_OAD_MONITOR_STATE)dl_info.u8DL_OAD_MonitorState;
    }
    else
    {
        // monitor state
        _enMonitorState = (EN_OAD_MONITOR_STATE)dl_info.u8DL_OAD_MonitorState;

        // wOriginalNetwork_ID_OAD
        wOriginalNetwork_ID_OAD = dl_info.u16DL_OAD_NID;

        // wTransportStream_ID_OAD
        wTransportStream_ID_OAD = dl_info.u16DL_OAD_TID;

        // wService_ID_OAD
        wService_ID_OAD = dl_info.u16DL_OAD_SID;

        // untDescriptor.untLocation.association_tag
        untDescriptor.untLocation.association_tag = dl_info.u16DL_OAD_AssociationTag;
        // _u32DL_StartTime
        _u32DL_StartTime = dl_info.u32DL_OAD_StartTime;
        // _u32DL_EndTime
        _u32DL_EndTime = dl_info.u32DL_OAD_EndTime;


        // cOad_RF
        //cOad_RF = dl_info.u8DL_OAD_TSFreq1;

        // auDLSchedule_time
        memcpy(untDescriptor.untSchedule, dl_info.auDLSchedule_time, (sizeof(UNT_SCHEDULE)*MAX_SCHEDULE_COUNT));
    }
#else //(EEPROM_DB_STORAGE==EEPROM_SAVE_NONE)
   if (state==EN_OAD_EEPROM_MONITOR)
   {
      // monitor state
      msAPI_rmBurstReadBytes(EEPROM_OFFSET(u8DL_OAD_MonitorState),(U8*)&_enMonitorState,1);
   }
   else
   {
      // wOriginalNetwork_ID_OAD
      msAPI_rmBurstReadBytes(EEPROM_OFFSET(u16DL_OAD_NID), (U8*)&wOriginalNetwork_ID_OAD, 2);

      // wTransportStream_ID_OAD
      msAPI_rmBurstReadBytes(EEPROM_OFFSET(u16DL_OAD_TID), (U8*)&wTransportStream_ID_OAD, 2);

     // wService_ID_OAD
     msAPI_rmBurstReadBytes(EEPROM_OFFSET(u16DL_OAD_SID), (U8*)&wService_ID_OAD, 2);

     // untDescriptor.untLocation.association_tag
     msAPI_rmBurstReadBytes(EEPROM_OFFSET(u16DL_OAD_AssociationTag), (U8*)&untDescriptor.untLocation.association_tag,2);

   //msAPI_rmBurstReadBytes(EEPROM_OFFSET(u8DL_OAD_TSFreq1),(U8*)&cOad_RF,1);
#if (BOOTLOADER_SYSTEM == 0)
   // auDLSchedule_time
   msAPI_rmBurstReadBytes(EEPROM_OFFSET(auDLSchedule_time), (U8*)untDescriptor.untSchedule,48);
#endif
   }
#endif //(EEPROM_DB_STORAGE==EEPROM_SAVE_NONE)
   //OAD_DEBUG(printf("GetInfo=%x,%x,%x,%x,%x,%x,%x\n",_enMonitorState,wOriginalNetwork_ID_OAD,wTransportStream_ID_OAD,wService_ID_OAD,untDescriptor.untSchedule.u32StartTime,untDescriptor.untSchedule.u32EndTime,untDescriptor.untLocation.association_tag)) ;
}

void MApp_OAD_ResetInfo(void)
{
    MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_PMT_DBID_RECEINING);//_enMonitorState = EN_OAD_MONITOR_STATE_PMT_DBID_RECEINING;
    wTransportStream_ID_OAD = INVALID_TS_ID;
    wOriginalNetwork_ID_OAD = INVALID_ON_ID;
    wService_ID_OAD = INVALID_SERVICE_ID;
    wOad_PID = INVALID_PID;
    memset(&untDescriptor,0, sizeof(UNT_DESCRIPTOR));
    _u32DL_StartTime = _u32DL_EndTime = 0;
    MApp_OAD_SetInfo();
}
static void MApp_OAD_Reset( void )
{
    MS_IMG_INFO TempImgInfo;

    wOad_PID = MSAPI_DMX_INVALID_PID;
    _enDownloadState= EN_OAD_DOWNLOAD_STATE_NONE;
    wPrev_TSID = INVALID_TS_ID;
    wPrev_ONID = INVALID_ON_ID;
    wPrev_SID = INVALID_SERVICE_ID;
    _bNIT_DVB_LinkSSU = FALSE;
    _bNIT_Simple_LinkSSU = FALSE;
    _bPMT_FoundSSU_DATA = FALSE;
    _bPMT_FoundSSU_OBJ = FALSE;
    _bCheck_NIT_First = TRUE;
    _PMT_Ready = FALSE;
    _NIT_Ready = FALSE;
    _bDisplayScheduleMsg = FALSE;
    _wLinkageSID = INVALID_SERVICE_ID;
    _wOADPID = INVALID_SERVICE_ID;
    versionNum = INVALID_VERSION_NUM;
#if (BLOADER)
    _BL_PmtReady = FALSE;
#endif

#if (!BLOADER)
    pZUIDrawPercentageCB = MApp_ZUI_OADSwUpdate_ProgressBar ;
#endif
    MAPP_DMX_SET_PID(MSAPI_DMX_INVALID_FLT_ID,OAD_MONITOR_FID);
    MAPP_DMX_SET_PID(MSAPI_DMX_INVALID_FLT_ID,OAD_DOWNLOAD_FID);
#if (!BLOADER)
    u32OadbufMonitorAddr = (U32)(((OADSEC_BUFFER_MEMORY_TYPE&MIU1)?OADSEC_BUFFER_ADR|MIU_INTERVAL:OADSEC_BUFFER_ADR)); //(_VA2PA((U32)demuxBuf.monitor)) ;
    u32OadbufDownloadAddr = (U32)(((OADSEC_BUFFER_MEMORY_TYPE&MIU1)?OADSEC_BUFFER_ADR|MIU_INTERVAL:OADSEC_BUFFER_ADR) + 0x4000);//(_VA2PA((U32)demuxBuf.download)) ;
    u32OadbufMonitorSize = DMX_BUF_SIZE_MONITOR;
    u32OadbufDownloadSize = DMX_BUF_SIZE_DOWNLOAD;
#endif //(!BLOADER)
    msAPI_OAD_ClearData();
    msAPI_OAD_SetOui((U8)(CUSTOMER_OUI>>16), (U8)(CUSTOMER_OUI>>8), (U8)(CUSTOMER_OUI));
#if (!BLOADER)
    msAPI_OAD_SetVersionCheck(MApp_OAD_VersonCheck) ;
#else //(!BLOADER)
    {
        extern BOOLEAN oad_VersonCheck(U16 type,U8 *pPrivateData);
        msAPI_OAD_SetVersionCheck(oad_VersonCheck) ;
    }
#endif //(!BLOADER)

    MApp_ImgInfo_GetAppInfo(&TempImgInfo) ;
    tvVersion = AP_SW_VERSION;
    MApp_OAD_GetInfo(EN_OAD_EEPROM_MONITOR) ;
    if ((MApp_OAD_GetMonitorState() == EN_OAD_MONITOR_STATE_UNT_WAIT_SCHEDULE) && (_bScheduleOnCheck || _bPowerOnCheck))
    {
        MApp_OAD_GetInfo(EN_OAD_EEPROM_OTHER);
        MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_PMT_DBID_RECEINING);
    }
    else
    {
        MApp_OAD_ResetInfo();
    }
    _bOADRunning = TRUE;
    OAD_DEBUG( printf("MApp_OAD_Reset: TV version=%x\n",tvVersion));
#if (BLOADER)
    enOADScanState = STATE_OAD_SCAN_INIT;
#endif //(BLOADER)
    // For NZ OAD start
    _bSignalForStandby = FALSE;
    memset(&_stOADSignalForStandby, 0, sizeof(_stOADSignalForStandby));
    // For NZ OAD end
}

void MApp_OAD_Init( void )
{
    OAD_DEBUG(printf(">> MApp_OAD_Init\n"));
    MApp_OAD_Reset();
    MApp_OAD_SignalReset();
    _enAppState= EN_OAD_APP_STATE_NONE;
    _enSignalState = STATE_OAD_SIGALPROCESS_EXIT;
    _bOadScanWaitTimerCheck = TRUE;

    _bCheck_DSITimeOut = 0;
}

#if (CUSTOMER_OUI==ENGEL_OUI)
BOOLEAN MApp_OAD_VersonCheck(U16 type,U8 *pPrivateData)
{
    UNUSED (type);
    UNUSED(*pPrivateData);
    tsVersion = u4swversion;
    toSaveVersion = tsVersion;

    return TRUE;
}
#else
BOOLEAN MApp_OAD_VersonCheck(U16 type,U8 *pPrivateData)
{
    U16  compatibilityLength,descriptorCount,model,version=0x0,i;
    U8  descriptorType, descriptorLength, specifierType, subDescriptorCount, subDescriptorType, subDescriptorLength;
    U32 specifierData;
    U16 u16Len = 0;
    BOOLEAN swPass=FALSE;
#if HW_MODEL_VER_CHECK
    BOOLEAN hwPass=FALSE;
#endif

    if (!VERSION_CHECK) return TRUE ;

    if (type==DATA_BC_ID_UK_EC) // MIS
    {
        U16 model_hw, version_hw;
        model_hw = GET_2BYTE(&pPrivateData[0]);
        version_hw = GET_2BYTE(&pPrivateData[2]);
        model = msAPI_OAD_GetMISVersionId() >> 16;
        version = msAPI_OAD_GetMISVersionId() & 0xff;
    #if HW_MODEL_VER_CHECK
        if ((model_hw == HW_MODEL)&&(version_hw == HW_VERSION))
    #endif //HW_MODEL_VER_CHECK
        {
        #if (LOWER_VERSION_DOWNLOAD)
            if ((model == AP_SW_MODEL)&&(version != AP_SW_VERSION))
        #else
            if ((model == AP_SW_MODEL)&&(version > AP_SW_VERSION))
        #endif //LOWER_VERSION_DOWNLOAD)
            {
                tsVersion = (U32)version;
                toSaveVersion = tsVersion;
                return TRUE ;
            }
        }
        return FALSE ;
    }
    else if (type==DATA_BC_ID_SSU) // GroupCompatibility()
    {
        compatibilityLength = GET_2BYTE(pPrivateData);
        pPrivateData += 2;

        if ( compatibilityLength < 2 )
        {
            OAD_ASSERT( printf("Error> msAPI_OAD_ProcessDSI : compatibilityLength = 0x%x\n", compatibilityLength) );
            return FALSE ;
        }

        u16Len = 0;
        while(u16Len < compatibilityLength)
        {
            descriptorCount = GET_2BYTE(pPrivateData); pPrivateData += 2;
            u16Len += 2;
            OAD_DEBUG( printf("descriptorCount = %u\n", descriptorCount) );

            for ( i = 0; i < descriptorCount; i ++ )
            {
                descriptorType  = *pPrivateData++;
                descriptorLength= *pPrivateData++;

                switch ( descriptorType )
                {
                    case 0x02: //System Software descriptor
                    {
                        specifierType = *pPrivateData++;
                        specifierData = GET_3BYTE( pPrivateData ); pPrivateData += 3;
                        model = GET_2BYTE(pPrivateData); pPrivateData += 2;
                        version = GET_2BYTE(pPrivateData); pPrivateData += 2;
                        subDescriptorCount = *pPrivateData++;

                        tsVersion = (U32)version;
                        OAD_DEBUG( printf("TS sw version=0x%X\n",tsVersion));

                    #if (LOWER_VERSION_DOWNLOAD)
                        if ((specifierType==0x01)&&(model == AP_SW_MODEL)&&(version != AP_SW_VERSION)&&(specifierData==CUSTOMER_OUI))
                    #else
                        if ((specifierType==0x01)&&(model == AP_SW_MODEL)&&(version > AP_SW_VERSION)&&(specifierData==CUSTOMER_OUI))
                    #endif //LOWER_VERSION_DOWNLOAD)
                        {
                            swPass = TRUE;
                        }
                    #if 0  //Enable this #if when Teracom may put s/w model & s/w version in subDescriptors.
                        else if ((subDescriptorCount > 0)&&(specifierType==0x01)&&(model == 0xFFFF)&&(version == 0xFFFF)&&(specifierData==DVB_OUI))
                        {
                            subDescriptorType = *pPrivateData++;
                            subDescriptorLength = *pPrivateData++;
                            if (subDescriptorType == 0x02)
                            {
                                //parse subDescriptor for s/w model & s/w version.
                                specifierType = *pPrivateData++;
                                specifierData = GET_3BYTE( pPrivateData ); pPrivateData += 3;
                                model = GET_2BYTE(pPrivateData); pPrivateData += 2;
                                version = GET_2BYTE(pPrivateData); pPrivateData += 2;
                                subDescriptorCount = *pPrivateData++;
                                tsVersion = (U32)version;
                                OAD_DEBUG( printf("TS sw version =0x%X in subDescriptor.\n",tsVersion));
                            #if (LOWER_VERSION_DOWNLOAD)
                                if ((specifierType==0x01)&&(model == AP_SW_MODEL)&&(version != AP_SW_VERSION)&&(specifierData==CUSTOMER_OUI))
                            #else
                                if ((specifierType==0x01)&&(model == AP_SW_MODEL)&&(version > AP_SW_VERSION)&&(specifierData==CUSTOMER_OUI))
                            #endif //LOWER_VERSION_DOWNLOAD)
                                {
                                    swPass = TRUE;
                                }
                                pPrivateData += (subDescriptorLength-9) ;
                                break;
                            }
                        }
                    #endif
                        else
                        {
                            //return FALSE ;
                        }
                        pPrivateData += (descriptorLength-9) ;
                        //OAD_DEBUG( printf("[OTA] specifierType = 0x%02bx, specifierData = 0x%08lx\n", specifierType, specifierData) );
                        break;
                    }
                    case 0x01: //System Hardware descriptor
                    #if HW_MODEL_VER_CHECK
                        specifierType = *pPrivateData++;
                        specifierData = GET_3BYTE( pPrivateData ); pPrivateData += 3;
                        model = GET_2BYTE(pPrivateData); pPrivateData += 2;
                        version = GET_2BYTE(pPrivateData); pPrivateData += 2;
                        subDescriptorCount = *pPrivateData++;
                        //tsVersion = (U32)version;
                        OAD_DEBUG( printf("TS hw : model=0x%X, version=0x%X\n",model,version));
                        if ((specifierType==0x01)&&(model == HW_MODEL)&&(version == HW_VERSION)&&(specifierData==CUSTOMER_OUI))
                        {
                            OAD_DEBUG(printf("System hardware descriptor is correct\n"));
                            hwPass = TRUE;
                        }
                        else if ((subDescriptorCount > 0)&&(specifierType==0x01)&&(model == 0xFFFF)&&(version == 0xFFFF)&&(specifierData==DVB_OUI)) //It's according to Teracom document
                        {
                            subDescriptorType = *pPrivateData++;
                            subDescriptorLength = *pPrivateData++;
                            if (subDescriptorType == 0x01)
                            {
                                //parse subDescriptor for h/w model & h/w version.
                                specifierType = *pPrivateData++;
                                specifierData = GET_3BYTE( pPrivateData ); pPrivateData += 3;
                                model = GET_2BYTE(pPrivateData); pPrivateData += 2;
                                version = GET_2BYTE(pPrivateData); pPrivateData += 2;
                                subDescriptorCount = *pPrivateData++;
                                //tsVersion = (U32)version;
                                OAD_DEBUG( printf("TS Sub hw model=0x%X, version =0x%X in subDescriptor.\n",model,version));
                                if ((specifierType==0x01)&&(model == HW_MODEL)&&(version == HW_VERSION)&&(specifierData==CUSTOMER_OUI))
                                {
                                    OAD_DEBUG(printf("Sub System hardware descriptor is correct"));
                                    hwPass = TRUE;
                                }
                                pPrivateData += (subDescriptorLength-9) ;
                                break;
                            }
                        }
                        else
                        {
                            //return FALSE ;
                        }
                        pPrivateData += (descriptorLength-9) ;
                        //OAD_DEBUG( printf("[OTA] specifierType = 0x%02bx, specifierData = 0x%08lx\n", specifierType, specifierData) );
                        break;
                    #endif
                    default:
                    {
                        pPrivateData += descriptorLength;
                        OAD_DEBUG( printf("[OTA] descriptorType = 0x%02bx\n", descriptorType) );
                        break;
                    }
                }

                if(i%2 == 1)
                {
                #if HW_MODEL_VER_CHECK
                    if((swPass == TRUE) && (hwPass == TRUE))
                #else //HW_MODEL_VER_CHECK
                    if(swPass == TRUE)
                #endif //HW_MODEL_VER_CHECK
                    {
                        toSaveVersion = (U32)version;
                        return TRUE ;
                    }
                }
                u16Len += (2+descriptorLength);
            }// End of for
        }
    }
    return FALSE ;
}
#endif


static void MApp_OAD_AddNitSignal(NIT_SIGNAL_DATA *pstNitSignal)
{
    U8 i;
    BOOLEAN bAddSignal = TRUE;

    if((pstNitSignal->u16SID == INVALID_SERVICE_ID) || (pstNitSignal->u16ONID == INVALID_ON_ID))
    {
        return;
    }

    for(i=0;i<MAX_SIGNAL_COUNT;i++)
    {
        if((_stOadNitSignal.stNitSignal[i].u16TSID == pstNitSignal->u16TSID)
            && (_stOadNitSignal.stNitSignal[i].u16ONID == pstNitSignal->u16ONID)
            && (_stOadNitSignal.stNitSignal[i].u16SID == pstNitSignal->u16SID))
        {
            bAddSignal = FALSE;
            break;
        }
    }
    if(bAddSignal == TRUE)
    {
        for(i=0;i<MAX_SIGNAL_COUNT;i++)
        {
            if((_stOadNitSignal.stNitSignal[i].u16TSID == INVALID_TS_ID)
                && (_stOadNitSignal.stNitSignal[i].u16ONID == INVALID_ON_ID)
                && (_stOadNitSignal.stNitSignal[i].u16SID == INVALID_SERVICE_ID))
            {
                memcpy(&_stOadNitSignal.stNitSignal[i], pstNitSignal, sizeof(NIT_SIGNAL_DATA));
                _stOadNitSignal.u8SignalCount++;
                OAD_DEBUG(printf("add nit signal:> TSID %x, ONID %x, SID %x\n",_stOadNitSignal.stNitSignal[i].u16TSID,_stOadNitSignal.stNitSignal[i].u16ONID,_stOadNitSignal.stNitSignal[i].u16SID));
                break;
            }
        }
        if(MApp_OAD_IsPowerOnCheck())
        {
            ePrev_ServiceTypePower = msAPI_CM_GetCurrentServiceType();
            u16Prev_PositionPower = msAPI_CM_GetCurrentPosition(msAPI_CM_GetCurrentServiceType());
        }
    }
}

static void MApp_OAD_AddPmtSignal(PMT_SIGNAL_DATA *pstPmtSignal)
{
    U8 i;
    BOOLEAN bAddSignal = TRUE;
    if((pstPmtSignal->u16OAD_PID == 0) || (pstPmtSignal->u16OAD_PID == INVALID_PID))
    {
        return;
    }

    if((pstPmtSignal->u8UpdateType >= SSU_UPDATETYPE_UNT_RETCHANNEL) || (pstPmtSignal->u8UpdateType == 0))
    {
        return;
    }
    for(i=0;i<MAX_SIGNAL_COUNT;i++)
    {
        if((_stOadPmtSignal.stPmtSignal[i].u16OAD_PID == pstPmtSignal->u16OAD_PID)&&(_stOadPmtSignal.stPmtSignal[i].u8Tag == pstPmtSignal->u8Tag))
        {
            bAddSignal = FALSE;
            break;
        }
    }
    if(bAddSignal == TRUE)
    {
        for(i=0;i<MAX_SIGNAL_COUNT;i++)
        {
            if(_stOadPmtSignal.stPmtSignal[i].u16OAD_PID == INVALID_PID)
            {
                memcpy(&_stOadPmtSignal.stPmtSignal[i], pstPmtSignal, sizeof(PMT_SIGNAL_DATA));
                OAD_DEBUG(printf("add pmt signal :> SID 0x%x, OAD PID  0x%x\n",_stOadPmtSignal.stPmtSignal[i].u16SID,_stOadPmtSignal.stPmtSignal[i].u16OAD_PID));
                _stOadPmtSignal.u8SignalCount++;
                break;
            }
        }
    }

}

static void MApp_OAD_SignalReset(void)
{
    U8 j;
    memset(&_stOadNitSignal, 0, sizeof(OAD_NIT_SIGNAL));
    memset(&_stOadPmtSignal, 0, sizeof(OAD_PMT_SIGNAL));
    for(j=0; j<MAX_SIGNAL_COUNT; j++)
    {
        _stOadNitSignal.stNitSignal[j].u16TSID = INVALID_TS_ID;
        _stOadNitSignal.stNitSignal[j].u16ONID = INVALID_ON_ID;
        _stOadNitSignal.stNitSignal[j].u16SID = INVALID_SERVICE_ID;

        _stOadPmtSignal.stPmtSignal[j].u16OAD_PID = INVALID_PID;
        _stOadPmtSignal.stPmtSignal[j].u16SID = INVALID_SERVICE_ID;
    }
}

void MApp_OAD_SetPmtSignal( WORD wPid, WORD wBDid,BYTE *pSelector ,U8 selectorType, U16 wService_ID)
{
    //MEMBER_SERVICETYPE bServiceType;
    //WORD wCurrentPosition;
    U32 ouiData=0;
    U8 updateType=0 ;
    PMT_SIGNAL_DATA stPmtSignal;
#if (CUSTOMER_OUI==ENGEL_OUI)
    U8 u1SelectorLength=0;
    U16 u2manucode=0;
    U8 u1modelfamily;
    U8 u1familymember;
    U32 u4OTAmodelMSB;
    U32 u4OTAmodelLSB;
#endif
    EN_OAD_MONITOR_STATE mState = MApp_OAD_GetMonitorState() ;
    stPmtSignal.u16OAD_PID = INVALID_PID;
    stPmtSignal.u16SID = INVALID_SERVICE_ID;
    stPmtSignal.u8UpdateType = 0;
    stPmtSignal.u8Association_tag = 0;
    stPmtSignal.u8Tag = 0;
    stPmtSignal.bUsed = FALSE;
    if ((selectorType==TAG_DBID) && (mState==EN_OAD_MONITOR_STATE_PMT_DBID_RECEINING))
    {
       if (wBDid==DATA_BC_ID_UK_EC)
       {
            stPmtSignal.u16OAD_PID = wPid;
            stPmtSignal.u16SID = wService_ID;
            stPmtSignal.u8UpdateType = 0;
            stPmtSignal.u8Tag = TAG_DBID;
            MApp_OAD_AddPmtSignal(&stPmtSignal);
            _bPMT_FoundSSU_OBJ = TRUE;
            //MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_DSI_INIT) ;
       }
       else if (wBDid==DATA_BC_ID_SSU) // section 7.1 table 4
       {
            ouiData = (pSelector[1]<<16)|(pSelector[2]<<8)|(pSelector[3]) ; //printf("ouiData=%x\n",ouiData) ;
            updateType = pSelector[4]&0x0f ; //printf("updateType=%x\n",updateType) ;
            OAD_DEBUG( printf("OUI  0x%x, updateType  %d\n",ouiData,updateType) );
            if ((ouiData==CUSTOMER_OUI) || (ouiData==DVB_OUI && updateType==SSU_UPDATETYPE_STANDARD) || (ouiData==DVB_OUI && _bDVB_OUI_Enable))
            {
                stPmtSignal.u16OAD_PID = wPid;
                stPmtSignal.u16SID = wService_ID;
                stPmtSignal.u8UpdateType = updateType;
                stPmtSignal.u8Tag = TAG_DBID;
                    if(ouiData==CUSTOMER_OUI)
                        _wOADPID = stPmtSignal.u16OAD_PID;
                MApp_OAD_AddPmtSignal(&stPmtSignal);
                _bPMT_FoundSSU_DATA = TRUE;
                OAD_DEBUG( printf("MApp_OAD_SetPmtSignal: _bPMT_FoundSSU_DATA   %d\n",_bPMT_FoundSSU_DATA) );

#if (CUSTOMER_OUI==ENGEL_OUI)
                u1SelectorLength = (pSelector[6]);
                u1familymember= (pSelector[18]);
                u4swversion= GET_3BYTE(&pSelector[19]);
                u2manucode = GET_2BYTE(&pSelector[7]);
                u4OTAmodelMSB = GET_4BYTE(&pSelector[9]);
                u4OTAmodelLSB = GET_4BYTE(&pSelector[13]);
                u1modelfamily= (pSelector[17]);

                if((u2manucode==ENGEL_MANUFACTURER_CODE)&&(u1modelfamily==ENGEL_MODEL_FAMILY)&&(u4OTAmodelMSB==ENGEL_OTA_MODEL_NAME_MSB)&&(u4OTAmodelLSB==ENGEL_OTA_MODEL_NAME_LSB))
                {
                    if((u1familymember==ENGEL_FAMILY_MEMBER)||(u1familymember==0xff))
                    {
                        if(u4swversion>AP_SW_VERSION)
                        {
                            if (updateType==SSU_UPDATETYPE_STANDARD)
                            {
                               MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_DSI_INIT) ;
                               MApp_OAD_SetCurrIdx(pstCurTPsetting.u32Frequency, &signal);
                            }
                            else if ((updateType==SSU_UPDATETYPE_UNT_BROADCAST)||(updateType==SSU_UPDATETYPE_UNT_RETCHANNEL))
                            {
                               MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_UNT_INIT) ;
                               MApp_OAD_SetCurrIdx(pstCurTPsetting.u32Frequency, &signal);
                            }
                        }
                    }
                }
#else

#endif
            }
        }
    }
    if ((selectorType==TAG_SID)&&((mState==EN_OAD_MONITOR_STATE_PMT_SID_RECEINING) || (mState==EN_OAD_MONITOR_STATE_PMT_DBID_RECEINING)))
    {
        //if (*pSelector==untDescriptor.untLocation.association_tag)
        {
            stPmtSignal.u16OAD_PID = wPid;
            stPmtSignal.u16SID = wService_ID;
            stPmtSignal.u8UpdateType = SSU_UPDATETYPE_UNT_BROADCAST;
            stPmtSignal.u8Association_tag = pSelector[0];
            stPmtSignal.u8Tag = TAG_SID;
            MApp_OAD_AddPmtSignal(&stPmtSignal);
        }
    }
}

void MApp_OAD_SetNitSignal( WORD wTSId, WORD wONId, WORD wServiceId, BYTE *pSelector)
{
    U8 u8Offset=0;
    U8 u8DataLen=0;
    U8 u8SelectByteLen=0;
    NIT_SIGNAL_DATA stNitSignal;

    u8DataLen = pSelector[0];
    u8Offset = 0;
    OAD_DEBUG(printf("\r\n %s, (%x),(%x),(%x)\n",__FUNCTION__,wTSId,wONId,wServiceId));
    if(MApp_OAD_GetMonitorState()!= EN_OAD_MONITOR_STATE_PMT_DBID_RECEINING)
    {
        return;
    }
    if (OSD_COUNTRY_SETTING == OSD_COUNTRY_NEWZEALAND || (IS_NORDIC_COUNTRY(OSD_COUNTRY_SETTING)))
    {
        ePrev_ServiceType = msAPI_CM_GetCurrentServiceType();
        u16Prev_Position = msAPI_CM_GetCurrentPosition(msAPI_CM_GetCurrentServiceType());
    }

    if(u8DataLen < 4)
    {
        OAD_DEBUG(printf("NIT : SSU error \n")) ;
    }
    else
    {
        while((u8DataLen-u8Offset)>0)
        {
            //Check whether OUI is matched.
            OAD_DEBUG( printf("... oui data   %x %x  %x\n",pSelector[u8Offset+1],pSelector[u8Offset+2],pSelector[u8Offset+3]) );
            if(pSelector[u8Offset+1] == ((U8)(CUSTOMER_OUI>>16)) && pSelector[u8Offset+2] == ((U8)(CUSTOMER_OUI>>8)) && pSelector[u8Offset+3] == ((U8)(CUSTOMER_OUI)))
            {
                u8SelectByteLen = pSelector[u8Offset+4];

                //Check whether model and version is matched.
#if HW_MODEL_VER_CHECK
#if (LOWER_VERSION_DOWNLOAD)
                if((u8SelectByteLen >= 8) &&
                   (GET_2BYTE(&pSelector[u8Offset+5]) == HW_MODEL) &&
                   (GET_2BYTE(&pSelector[u8Offset+7]) == HW_VERSION) &&
                   (GET_2BYTE(&pSelector[u8Offset+9]) == AP_SW_MODEL) &&
                   (GET_2BYTE(&pSelector[u8Offset+11]) != AP_SW_VERSION))
#else //!(LOWER_VERSION_DOWNLOAD)
                if((u8SelectByteLen >= 8) &&
                   (GET_2BYTE(&pSelector[u8Offset+5]) == HW_MODEL) &&
                   (GET_2BYTE(&pSelector[u8Offset+7]) == HW_VERSION) &&
                   (GET_2BYTE(&pSelector[u8Offset+9]) == AP_SW_MODEL) &&
                   (GET_2BYTE(&pSelector[u8Offset+11]) > AP_SW_VERSION))
#endif //!(LOWER_VERSION_DOWNLOAD)
#else //(!HW_MODEL_VER_CHECK)
#if (LOWER_VERSION_DOWNLOAD)
                if((u8SelectByteLen >= 4) && GET_2BYTE(&pSelector[u8Offset+5])==AP_SW_MODEL && GET_2BYTE(&pSelector[u8Offset+7]) != AP_SW_VERSION)
#else
                if((u8SelectByteLen >= 4) && GET_2BYTE(&pSelector[u8Offset+5])==AP_SW_MODEL && GET_2BYTE(&pSelector[u8Offset+7]) > AP_SW_VERSION)
#endif
#endif //(!HW_MODEL_VER_CHECK)
                {
#if ENABLE_SDT_OTHER_MONITOR
                    if(INVALID_PHYSICAL_CHANNEL_NUMBER != msAPI_CM_GetPhysicalChannelNumberByID(wONId, wTSId))
#endif
                    {
                        memset(&stNitSignal, 0, sizeof(NIT_SIGNAL_DATA));
                        stNitSignal.u16TSID = wTSId;
                        stNitSignal.u16ONID = wONId;
                        stNitSignal.u16SID = wServiceId;
                        MApp_OAD_AddNitSignal(&stNitSignal);
                        OAD_DEBUG( printf("SetNITSignal : SSU ok => _bNIT_Simple_LinkSSU: %d  is found.\n", _bNIT_Simple_LinkSSU) );
                    }
                    break;
                }
            }
            else if(pSelector[u8Offset+1] == ((U8)(DVB_OUI>>16)) && pSelector[u8Offset+2] == ((U8)(DVB_OUI>>8)) && pSelector[u8Offset+3] == ((U8)(DVB_OUI)))
            {
                OAD_DEBUG( printf("111.... _bDVB_OUI_Enable   %d, %d(%d)\n",_bDVB_OUI_Enable,OSD_COUNTRY_SETTING,OSD_COUNTRY_UK) );
                if(OSD_COUNTRY_SETTING != OSD_COUNTRY_UK && _bDVB_OUI_Enable) //do nothing for UK DTG OAD test
                {
                    memset(&stNitSignal, 0, sizeof(NIT_SIGNAL_DATA));
                    stNitSignal.u16TSID = wTSId;
                    stNitSignal.u16ONID = wONId;
                    stNitSignal.u16SID = wServiceId;
                    MApp_OAD_AddNitSignal(&stNitSignal);
                    _bNIT_DVB_LinkSSU = TRUE;

                    OAD_DEBUG( printf("SetNITSignal : SSU ok => _bNIT_DVB_LinkSSU:  %d is found.\n", _bNIT_DVB_LinkSSU) );
                }
                break;
            }
            else
            {
                u8SelectByteLen = pSelector[u8Offset+4];
            }
            u8Offset+=(4+u8SelectByteLen);
        }
    }
}

void MApp_OAD_SetMonitorState( EN_OAD_MONITOR_STATE state )
{
    OAD_DEBUG( printf(" SetMonitorState :>>   %d\n",state) );
    _enMonitorState = state;
}

EN_OAD_MONITOR_STATE MApp_OAD_GetMonitorState( void )
{
    return _enMonitorState;
}

void MApp_OAD_SetDownloadState( EN_OAD_DOWNLOAD_STATE state )
{
    OAD_DEBUG( printf(" SetDownloadState :>>   %d\n",state) );
    _enDownloadState = state;
}

EN_OAD_DOWNLOAD_STATE MApp_OAD_GetDownloadState( void )
{
    return _enDownloadState;
}

void MApp_OAD_PowerOnScreen(void)
{
    if(_bOAD_PowerOnScreen == TRUE)
    {
        MApp_OAD_PanelPowerOn();
        _bOAD_PowerOnScreen = FALSE;
    }
}

void MApp_OAD_SetAppState( EN_OAD_APP_STATE state )
{
    OAD_DEBUG( printf(" SetAppState :>>   %d\n",state) );
    _enAppState = state;
}

EN_OAD_APP_STATE MApp_OAD_GetAppState( void )
{
    return _enAppState;
}
EN_OAD_SCAN_STATE MApp_OAD_GetScanState( void )
{
    return enOADScanState;
}
void MApp_OAD_SetScanState( EN_OAD_SCAN_STATE state )
{
    OAD_DEBUG( printf(" SetScanState :>>  %d\n",state) );
    enOADScanState = state;
}

static EN_OAD_SIGALPROCESS_STATE _MApp_OAD_GetSignalState(void)
{
    return _enSignalState;
}

static void _MApp_OAD_SetSignalState(EN_OAD_SIGALPROCESS_STATE state)
{
    OAD_DEBUG( printf(" SetSignalState :>>  %d\n",state) );
    _enSignalState = state;
}

void MApp_OAD_Signal_Process(void)
{
    EN_OAD_SIGALPROCESS_STATE eSignalState;
    EN_OAD_MONITOR_STATE eMonitorState;
    static U32 u32SignalProcessTimer = 0;
    MEMBER_SERVICETYPE eGotServiceType;
    WORD u16GotPosition;
    U8 i;

    eSignalState = _MApp_OAD_GetSignalState();
    switch(eSignalState)
    {
        case STATE_OAD_SIGALPROCESS_INIT:
        {
            _bCheck_NIT_First = TRUE;
            u32SignalProcessTimer = 0;
            _MApp_OAD_SetSignalState(STATE_OAD_SIGALPROCESS_RUN);
            break;
        }

        case STATE_OAD_SIGALPROCESS_RUN:
        {
            eMonitorState = MApp_OAD_GetMonitorState();
            switch(eMonitorState)
            {
                case EN_OAD_MONITOR_STATE_STOP:
                {
                    break;
                }
                case EN_OAD_MONITOR_STATE_PMT_DBID_RECEINING:
                {
                    if((_stOadNitSignal.u8SignalCount == 0) && (_stOadPmtSignal.u8SignalCount == 0))
                    {
                        MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_STOP);
                        break;
                    }
                    if(_bCheck_NIT_First)
                    {
                        for(i=0; i<_stOadNitSignal.u8SignalCount; i++)
                        {
                            if(_stOadNitSignal.stNitSignal[i].bUsed == FALSE)
                            {
                                _stOadNitSignal.stNitSignal[i].bUsed = TRUE;
                                if(TRUE == msAPI_CM_GetServiceTypeAndPositionWithIDs( _stOadNitSignal.stNitSignal[i].u16TSID, _stOadNitSignal.stNitSignal[i].u16ONID, _stOadNitSignal.stNitSignal[i].u16SID, 1, &eGotServiceType, &u16GotPosition, TRUE))
                                {
                                    wTransportStream_ID_OAD = _stOadNitSignal.stNitSignal[i].u16TSID;
                                    _wLinkageSID = wService_ID_OAD = _stOadNitSignal.stNitSignal[i].u16SID;
                                    wOriginalNetwork_ID_OAD = _stOadNitSignal.stNitSignal[i].u16ONID;

                                    MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_NIT_SIGNAL);
                                    #if (ENABLE_UPDATE_MULTIPLEX_VIA_NIT)
                                    MApp_SI_EnableNetworkCheck(FALSE);
                                    #endif
                                    break;
                                }

                            }
                        }
                        _bCheck_NIT_First = FALSE;
                        _PMT_Ready=FALSE;
                    }
                    else
                    {
                        if(_PMT_Ready == FALSE)
                        {
                            if(u32SignalProcessTimer == 0)
                            {
                                u32SignalProcessTimer = msAPI_Timer_GetTime0();
                            }
                            if((u32SignalProcessTimer > 0)&&(msAPI_Timer_DiffTimeFromNow(u32SignalProcessTimer) < (MONITOR_SIGNAL_TIME_OUT/4)))
                            {
                                break;
                            }
                        }
                        u32SignalProcessTimer = 0;
                        printf("\r\n >>[u8SignalCount] = %d\n",_stOadPmtSignal.u8SignalCount);
                        for(i=0; i<_stOadPmtSignal.u8SignalCount; i++)
                        {
                            printf("\r\n >>[i] = %d,_wLinkageSID = %x,u16SID = %x,bUsed = %d,u8Association_tag = %d,u8UpdateType(%d),u8Tag(%d),u16OAD_PID(0x%x),_wOADPID(0x%x)\n",
                                i,_wLinkageSID,_stOadPmtSignal.stPmtSignal[i].u16SID,_stOadPmtSignal.stPmtSignal[i].bUsed,_stOadPmtSignal.stPmtSignal[i].u8Association_tag,
                                _stOadPmtSignal.stPmtSignal[i].u8UpdateType,_stOadPmtSignal.stPmtSignal[i].u8Tag,_stOadPmtSignal.stPmtSignal[i].u16OAD_PID,_wOADPID);

                            if(((_wLinkageSID == INVALID_SERVICE_ID) || ((_stOadPmtSignal.stPmtSignal[i].u16SID == _wLinkageSID)&&((_wOADPID == INVALID_SERVICE_ID) || (_stOadPmtSignal.stPmtSignal[i].u16OAD_PID == _wOADPID))))
                                && (_stOadPmtSignal.stPmtSignal[i].bUsed == FALSE)
                                &&(_stOadPmtSignal.stPmtSignal[i].u8Association_tag == 0)
                                &&(_stOadPmtSignal.stPmtSignal[i].u8Tag == TAG_DBID))
                            {
                                _stOadPmtSignal.stPmtSignal[i].bUsed = TRUE;
                                if (_bOadScanCheck)
                                {
                                    wService_ID_OAD = _stOadPmtSignal.stPmtSignal[i].u16SID;
                                    OAD_DEBUG( printf("MApp_OAD_Monitor: u8OadRFCh = %d, wService_ID_OAD = 0x%X\n", u8OadRFCh, wService_ID_OAD) );
                                    if (FALSE == msAPI_CM_GetServiceTypeAndPositionWithPCN(u8OadRFCh, wService_ID_OAD, &bServiceType, &wCurrentPosition))
                                    {
                                        OAD_DEBUG( printf("MApp_OAD_Monitor: WARNING!!! The found SSU service doesn't exist in channel database.\n") );
                                    }
                                    else
                                    {
                                        wOriginalNetwork_ID_OAD  = msAPI_CM_GetON_ID( bServiceType, wCurrentPosition);
                                        wTransportStream_ID_OAD = msAPI_CM_GetTS_ID( bServiceType, wCurrentPosition);
                                    }
                                }
                                else
                                {
                                    bServiceType = msAPI_CM_GetCurrentServiceType();
                                    wCurrentPosition = msAPI_CM_GetCurrentPosition(bServiceType);
                                    wOriginalNetwork_ID_OAD  = msAPI_CM_GetON_ID( bServiceType, wCurrentPosition);
                                    wTransportStream_ID_OAD = msAPI_CM_GetTS_ID( bServiceType, wCurrentPosition);
                                    wService_ID_OAD = _stOadPmtSignal.stPmtSignal[i].u16SID;
                                }
                                OAD_DEBUG( printf("MApp_OAD_Monitor[%d]: tsid=0x%X, onid=0x%X, sid=0x%X\n", __LINE__, wTransportStream_ID_OAD, wOriginalNetwork_ID_OAD, wService_ID_OAD) );

                                if(_stOadPmtSignal.stPmtSignal[i].u8UpdateType == SSU_UPDATETYPE_UNT_BROADCAST)
                                {
                                    wOad_PID = _stOadPmtSignal.stPmtSignal[i].u16OAD_PID;
                                    _u8UpdateType = _stOadPmtSignal.stPmtSignal[i].u8UpdateType;
                                    MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_UNT_INIT);
                                #if (ENABLE_UPDATE_MULTIPLEX_VIA_NIT)
                                    MApp_SI_EnableNetworkCheck(FALSE);
                                #endif
                                }
                                else if(_stOadPmtSignal.stPmtSignal[i].u8UpdateType == SSU_UPDATETYPE_STANDARD)
                                {
                                    wOad_PID = _stOadPmtSignal.stPmtSignal[i].u16OAD_PID;
                                    _u8UpdateType = _stOadPmtSignal.stPmtSignal[i].u8UpdateType;
                                    MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_DSI_INIT);
                                #if (ENABLE_UPDATE_MULTIPLEX_VIA_NIT)
                                    MApp_SI_EnableNetworkCheck(FALSE);
                                #endif
                                }
                                else if(_stOadPmtSignal.stPmtSignal[i].u8UpdateType == 0)
                                {
                                    wOad_PID = _stOadPmtSignal.stPmtSignal[i].u16OAD_PID;
                                    _u8UpdateType = _stOadPmtSignal.stPmtSignal[i].u8UpdateType;
                                    MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_DSI_INIT);
                                #if (ENABLE_UPDATE_MULTIPLEX_VIA_NIT)
                                    MApp_SI_EnableNetworkCheck(FALSE);
                                #endif
                                }
                                bServiceType = msAPI_CM_GetCurrentServiceType();
                                wCurrentPosition = msAPI_CM_GetCurrentPosition(bServiceType);
                                cRFChannelNumber = msAPI_CM_GetPhysicalChannelNumber(bServiceType, wCurrentPosition);
                                msAPI_DFT_GetTSSetting(cRFChannelNumber, &stTPSetting);
                                MApp_OAD_SetInfo_ForBL(wOad_PID, stTPSetting.u32Frequency, stTPSetting.enBandWidth);
                                OAD_DEBUG( printf(">>> wOad_PID   0x%x\n",wOad_PID) );
                                break;
                            }

                        }
                        if(i >= _stOadPmtSignal.u8SignalCount)
                        {
                            if((_wLinkageSID == INVALID_SERVICE_ID))
                            {
                                MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_STOP);
                            }
                            else
                            {
                                if((wPrev_TSID != INVALID_TS_ID) && (wPrev_ONID != INVALID_ON_ID) && (wPrev_SID != INVALID_SERVICE_ID))
                                {
                                    MApp_OAD_ChannelChange(wPrev_TSID, wPrev_ONID, wPrev_SID);
                                }
                                MApp_OAD_Reset();
                            }
                        }

                    }
                }
                break;

                case EN_OAD_MONITOR_STATE_PMT_SID_RECEINING:
                {
                    if(_PMT_Ready == FALSE)
                    {
                        if(u32SignalProcessTimer == 0)
                        {
                            u32SignalProcessTimer = msAPI_Timer_GetTime0();
                        }
                        if((u32SignalProcessTimer > 0)&&(msAPI_Timer_DiffTimeFromNow(u32SignalProcessTimer) < (MONITOR_SIGNAL_TIME_OUT/4)))
                        {
                            break;
                        }
                    }
                    u32SignalProcessTimer = 0;

                    for(i=0; i<_stOadPmtSignal.u8SignalCount; i++)
                    {
                        if((_stOadPmtSignal.stPmtSignal[i].u8Association_tag == untDescriptor.untLocation.association_tag)
                            && (_stOadPmtSignal.stPmtSignal[i].bUsed == FALSE)
                            && (_stOadPmtSignal.stPmtSignal[i].u8Tag == TAG_SID))
                        {
                            wOad_PID = _stOadPmtSignal.stPmtSignal[i].u16OAD_PID;
                            _u8UpdateType = _stOadPmtSignal.stPmtSignal[i].u8UpdateType;
                            MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_DSI_INIT);
#if (ENABLE_UPDATE_MULTIPLEX_VIA_NIT)
                            MApp_SI_EnableNetworkCheck(FALSE);
#endif
                            break;
                        }
                    }
                    if(i >= _stOadPmtSignal.u8SignalCount)
                    {
                        MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_STOP);
                    }
                    _PMT_Ready = FALSE;


                    break;
                }

                default:
                    break;
            }
            break;
        }
        case STATE_OAD_SIGALPROCESS_EXIT:
        {
            if(u32SignalProcessTimer == 0)
            {
                u32SignalProcessTimer = msAPI_Timer_GetTime0();
            }
#if (BLOADER)
            if(((u32SignalProcessTimer > 0)&&(msAPI_Timer_DiffTimeFromNow(u32SignalProcessTimer) > MONITOR_SIGNAL_TIME_OUT)) ||(_BL_PmtReady))
#else
            if(((u32SignalProcessTimer > 0)&&(msAPI_Timer_DiffTimeFromNow(u32SignalProcessTimer) > MONITOR_SIGNAL_TIME_OUT))
                ||(_PMT_Ready && (_NIT_Ready || _bOadScanCheck || (OSD_COUNTRY_SETTING == OSD_COUNTRY_UK))))
#endif
            {
                if((_stOadNitSignal.u8SignalCount > 0) || (_stOadPmtSignal.u8SignalCount > 0))
                {
                    _MApp_OAD_SetSignalState(STATE_OAD_SIGALPROCESS_INIT);
                }
                else
                {
                    _PMT_Ready = _NIT_Ready = FALSE;
                    if(MApp_OAD_IsPowerOnCheck() || MApp_OAD_IsScheduleOnCheck() || MApp_OAD_IsStandbyOffCheck())
                    {
                        _bDVB_OUI_Enable = FALSE;
                        printf("\r\n [PowerOn: %d],[ScheduleOn: %d],[StandbyOn: %d]\n",
                        MApp_OAD_IsPowerOnCheck(),MApp_OAD_IsScheduleOnCheck(),MApp_OAD_IsStandbyOffCheck());
                        MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_STOP);
                    }
                    else if(MApp_OAD_IsOadScanCheck())
                    {
                        if(_bOadScanWaitTimerCheck)
                            {
                            _bOadScanWaitTimerCheck = FALSE;
                            u32SignalProcessTimer = 0;
                            }
                        else
                            MApp_OAD_SetScanState(STATE_OAD_SCAN_NEXT_CHANNEL);
                    }
                }
                u32SignalProcessTimer = 0;
            }
            break;
        }
    }

}

void MApp_OAD_Monitor( void )
{
    static UINT32 u32DsmccTimer, u32CreateFilterTimer = 0, u32CheckTOTTimer = 0;
    EN_OAD_MONITOR_STATE eState;
    UINT8 *pu8Buf = NULL;

    MApp_OAD_Signal_Process();

    eState = MApp_OAD_GetMonitorState();
    //OAD_DEBUG( printf(" &&&& eState_Monitor = %d\n", (U8)eState) );
    switch( eState )
    {
        case EN_OAD_MONITOR_STATE_DSI_INIT:
        {
            msAPI_OAD_DeleteSectionFilter(MApp_Dmx_GetFid(EN_OAD_MONITOR_FID));
            if((u32CreateFilterTimer) && msAPI_Timer_DiffTimeFromNow(u32CreateFilterTimer) <= 50)
            {
                break;
            }
            u32CreateFilterTimer = 0;
            if(msAPI_OAD_CreateSectionFilter( MSAPI_DMX_FILTER_TYPE_OAD_MONITOR,OAD_CONTROL_SECTION_TYPE,OAD_DSMCC_MSGID_DSI,wOad_PID,MAPP_DMX_GET_PID(OAD_MONITOR_FID), INVALID_VERSION_NUM) == TRUE)
            {
                MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_DSI_RECEIVING);
                u32DsmccTimer = msAPI_Timer_GetTime0();
                u32CreateFilterTimer = 0;
            }
            else
            {
                u32CreateFilterTimer = msAPI_Timer_GetTime0();
                OAD_DEBUG( printf("Error> msAPI_OAD_CreateSectionFilter(OAD_CONTROL_SECTION_TYPE) : Invalid FID\n") );
            }

            break ;
        }

        case EN_OAD_MONITOR_STATE_DSI_RECEIVING :
        case EN_OAD_MONITOR_STATE_DSI_SIGNAL:
        case EN_OAD_MONITOR_STATE_NIT_DSI_SIGNAL:
        {
            pu8Buf = msAPI_OAD_PollingSectionFilter(*MAPP_DMX_GET_PID(OAD_MONITOR_FID), MAPP_DMX_GETSI_4K_SECBUFFER());

            if(pu8Buf)
            {
                if (OAD_SUCCEED==msAPI_OAD_ProcessDSI(pu8Buf))
                {
                    u32DsmccTimer = msAPI_Timer_GetTime0();
                    if (EN_OAD_MONITOR_STATE_DSI_RECEIVING==MApp_OAD_GetMonitorState())
                    {
                        versionNum = msAPI_OAD_GetDsiVersionNum() ;
                        MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_DII_INIT);
                    }
                    else if (EN_OAD_MONITOR_STATE_DSI_SIGNAL==MApp_OAD_GetMonitorState()
                        || EN_OAD_MONITOR_STATE_NIT_DSI_SIGNAL==MApp_OAD_GetMonitorState())
                    {
                        if (versionNum!=msAPI_OAD_GetDsiVersionNum())
                        {
                            OAD_DEBUG( printf("versionNum error !!!\n") );
                            MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_STOP);
                        }
                    }
                }
                else
                {
                }
            }

            if (msAPI_Timer_DiffTimeFromNow(u32DsmccTimer) > MONITOR_DSI_TIME_OUT)
            {
                OAD_DEBUG( printf("Error> Exit DSI\n") );
            #if ENABLE_NZ_FREEVIEW
                #if (ENABLE_RIKS_TV)
                #if (!BLOADER)
                if(bShowOadScanPage == TRUE)
                {
                    MApp_OAD_SetMonitorState( EN_OAD_MONITOR_STATE_RECEIVING_TIMEOUT);
                }
                else
                #endif
                {
                    MApp_OAD_SetMonitorState( EN_OAD_MONITOR_STATE_STOP);
                    _bCheck_DSITimeOut = TRUE;
                }
                #else
                    MApp_OAD_SetAppState(EN_OAD_APP_STATE_STOP);
                #endif
            #else
                MApp_OAD_SetMonitorState( EN_OAD_MONITOR_STATE_RECEIVING_TIMEOUT);
            #endif
            }
            break;
        }

        case EN_OAD_MONITOR_STATE_DII_INIT:
        {
            msAPI_OAD_DeleteSectionFilter(MApp_Dmx_GetFid(EN_OAD_MONITOR_FID));
            if((u32CreateFilterTimer) && msAPI_Timer_DiffTimeFromNow(u32CreateFilterTimer) <= 50)
            {
                break;
            }
            u32CreateFilterTimer = 0;
            if(msAPI_OAD_CreateSectionFilter( MSAPI_DMX_FILTER_TYPE_OAD_MONITOR,OAD_CONTROL_SECTION_TYPE,OAD_DSMCC_MSGID_DII,wOad_PID,MApp_Dmx_GetFid(EN_OAD_MONITOR_FID), INVALID_VERSION_NUM) == TRUE)
            {
               MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_DII_RECEIVING) ;
               u32DsmccTimer = msAPI_Timer_GetTime0();
               u32CreateFilterTimer = 0;
            }
            else
            {
               u32CreateFilterTimer = msAPI_Timer_GetTime0();
            }
            break;
        }
        case EN_OAD_MONITOR_STATE_DII_RECEIVING:
        {
            pu8Buf = msAPI_OAD_PollingSectionFilter(*MAPP_DMX_GET_PID(OAD_MONITOR_FID), MAPP_DMX_GETSI_4K_SECBUFFER());

            if(pu8Buf)
            {
                if (OAD_SUCCEED==msAPI_OAD_ProcessDII(pu8Buf))
                {
                    MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_DII_READY);
                }
            }
            if (msAPI_Timer_DiffTimeFromNow(u32DsmccTimer) > MONITOR_DII_TIME_OUT)
            {
                OAD_DEBUG( printf("Error> Timeout to receive DII\n") );
                MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_RECEIVING_TIMEOUT);
            }

            break;
        }
        case EN_OAD_MONITOR_STATE_DII_READY:
        {
            // Delete filter of DII after DII is received.
            msAPI_OAD_DeleteSectionFilter(MApp_Dmx_GetFid(EN_OAD_MONITOR_FID));
            if((u32CreateFilterTimer) && msAPI_Timer_DiffTimeFromNow(u32CreateFilterTimer) <= 50)
            {
                break;
            }

            // Create filter to continuously monitor DSI.
            if(msAPI_OAD_CreateSectionFilter( MSAPI_DMX_FILTER_TYPE_OAD_MONITOR,OAD_CONTROL_SECTION_TYPE,OAD_DSMCC_MSGID_DSI,wOad_PID,MApp_Dmx_GetFid(EN_OAD_MONITOR_FID), versionNum) == TRUE)
            {
                if(_bPowerOnCheck || _bStandbyOffCheck)
                {
                    OAD_DEBUG( printf(" %s    %u\n",__FUNCTION__,__LINE__) );
                    MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_EXIT);
                }
                else
                {
                    if(bNITSignal_DSI)
                    {
                        MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_NIT_DSI_SIGNAL);
                        bNITSignal_DSI = FALSE;
                    }
                    else
                    {

                        if(_bScheduleOnCheck)
                        {
                           MApp_OAD_SetDownloadState(EN_OAD_DOWNLOAD_STATE_DDB_INIT);
                        }
                        else
                        {
                            if(MApp_OAD_IsOadScanCheck())
                            {
                                MApp_OAD_SetScanState(STATE_OAD_SCAN_SSU_FOUND_OR_SCHEDULE);
                            }
                        }
                        MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_DSI_SIGNAL);
                    }
                }
                u32DsmccTimer = msAPI_Timer_GetTime0();
                u32CreateFilterTimer = 0;
            }
            else
            {
                u32CreateFilterTimer = msAPI_Timer_GetTime0();
                OAD_DEBUG( printf("Error> msAPI_OAD_CreateSectionFilter(OAD_CONTROL_SECTION_TYPE) : Invalid FID\n") );
            }

            break;
        }

        case EN_OAD_MONITOR_STATE_UNT_INIT:
        {
            msAPI_OAD_DeleteSectionFilter(MApp_Dmx_GetFid(EN_OAD_MONITOR_FID));
            if((u32CreateFilterTimer) && msAPI_Timer_DiffTimeFromNow(u32CreateFilterTimer) <= 50)
            {
                break;
            }
            u32CreateFilterTimer = 0;
            if(msAPI_OAD_CreateSectionFilter( MSAPI_DMX_FILTER_TYPE_OAD_MONITOR,OAD_UNT_SECTION_TYPE,0,wOad_PID,MAPP_DMX_GET_PID(OAD_MONITOR_FID), INVALID_VERSION_NUM) == TRUE)
            {
                MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_UNT_RECEIVING);
                u32DsmccTimer = msAPI_Timer_GetTime0();
            }
            else
            {
                //MApp_OAD_SetMonitorState( EN_OAD_MONITOR_STATE_EXIT);
                u32CreateFilterTimer = msAPI_Timer_GetTime0();
                OAD_DEBUG( printf("Error> msAPI_OAD_CreateSectionFilter(OAD_CONTROL_SECTION_TYPE) : Invalid FID\n") );
            }

            break ;
        }

        case EN_OAD_MONITOR_STATE_UNT_RECEIVING :
        {
            pu8Buf = msAPI_OAD_PollingSectionFilter(*MAPP_DMX_GET_PID(OAD_MONITOR_FID),MAPP_DMX_GETSI_4K_SECBUFFER());

            if (pu8Buf)
            {
                if (OAD_SUCCEED==msAPI_OAD_ProcessUNT(pu8Buf,&untDescriptor))
                {
                   MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_UNT_CHECK_SCHEDULE);
                   _u32DL_StartTime = _u32DL_EndTime = 0;
                    bServiceType = msAPI_CM_GetCurrentServiceType();
                    wCurrentPosition = msAPI_CM_GetCurrentPosition(bServiceType);
                    // Set Current Physical Channel
                    cRFChannelNumber = msAPI_CM_GetPhysicalChannelNumber(bServiceType, wCurrentPosition);
                    // Get Current Frequency & BandWidth
                    msAPI_DFT_GetTSSetting(cRFChannelNumber, &stTPSetting);
                    MApp_OAD_SetInfo_ForBL(wOad_PID, stTPSetting.u32Frequency, stTPSetting.enBandWidth);
                }
                else
                {
                }
            }

            if (msAPI_Timer_DiffTimeFromNow(u32DsmccTimer) > MONITOR_UNT_TIME_OUT)
            {
                OAD_DEBUG( printf("Error> Exit UNT RECEIVING \n") );
                MApp_OAD_SetMonitorState( EN_OAD_MONITOR_STATE_RECEIVING_TIMEOUT);
            }
            break;
        }
        case EN_OAD_MONITOR_STATE_PMT_DBID_RECEINING_BY_NIT:
        {
            //MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_PMT_DBID_RECEINING);
            //bNITSignal_DSI = TRUE;
            break;
        }

#if (!BLOADER)
        case EN_OAD_MONITOR_STATE_UNT_CHECK_SCHEDULE:
        case EN_OAD_MONITOR_STATE_UNT_WAIT_SCHEDULE:
        {
            if(MApp_SI_IS_GotTDTOrTOT() == FALSE)
            {
                if(u32CheckTOTTimer == 0)
                    u32CheckTOTTimer = msAPI_Timer_GetTime0();

                if (u32CheckTOTTimer > 0 && msAPI_Timer_DiffTimeFromNow(u32CheckTOTTimer) > MONITOR_USER_TIME_OUT )
                {
                    u32CheckTOTTimer = 0;
                    if(_bStandbyOffCheck || _bScheduleOnCheck)
                    {
                        MApp_OAD_SetMonitorState( EN_OAD_MONITOR_STATE_NONE);
                    }
                    else
                    {
                        MApp_OAD_ChannelChange(wPrev_TSID, wPrev_ONID, wPrev_SID);
                        OAD_DEBUG( printf(" %s    %u\n",__FUNCTION__,__LINE__) );
                        MApp_OAD_SetMonitorState( EN_OAD_MONITOR_STATE_STOP);
                    }
                }
                break;
            }
            else
            {
                if(eState == EN_OAD_MONITOR_STATE_UNT_CHECK_SCHEDULE && _bOadScanCheck)
                {
                    if(u32CheckTOTTimer == 0)
                    {
                        u32CheckTOTTimer = msAPI_Timer_GetTime0();
                    }
                    if(u32CheckTOTTimer > 0 && msAPI_Timer_DiffTimeFromNow(u32CheckTOTTimer) < (MONITOR_USER_TIME_OUT / 3))
                    {
                        break;
                    }
                }
                if(u32CheckTOTTimer > 0)
                    u32CheckTOTTimer = 0;
            }
            if (MApp_OAD_IsUntSchedule())
            {
                if(_bStandbyOffCheck)
                {
                    MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_NONE);
                }
                else if(_bOadScanCheck)
                {
                    //MApp_SI_Force_PMT_Parse();
                    MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_PMT_SID_RECEINING);
                    _PMT_Ready = FALSE;
                    u32WaitPmtSIDTimer = 0;
                }
                else
                {
                    if (OSD_COUNTRY_SETTING == OSD_COUNTRY_NEWZEALAND || (IS_NORDIC_COUNTRY(OSD_COUNTRY_SETTING)))
                    {
                        ePrev_ServiceType = msAPI_CM_GetCurrentServiceType();
                        u16Prev_Position = msAPI_CM_GetCurrentPosition(msAPI_CM_GetCurrentServiceType());
                    }
                    if(TRUE == MApp_OAD_ChannelChange(wTransportStream_ID_OAD, wOriginalNetwork_ID_OAD, wService_ID_OAD))
                    {
                        MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_PMT_SID_RECEINING);
                        _PMT_Ready = FALSE;
                        u32WaitPmtSIDTimer = 0;
                    }
                    else
                    {
                        OAD_DEBUG( printf(" %s    %u\n",__FUNCTION__,__LINE__) );
                        MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_STOP);
                    }
                }
            }
            else
            {
                if(_u32DL_StartTime == 0 || _u32DL_EndTime == 0)
                {
                    _bCheckScheduleMsg = FALSE;
                    OAD_DEBUG( printf(" %s    %u\n",__FUNCTION__,__LINE__) );
                    MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_STOP);
                    break;
                }

                if(MApp_OAD_GetMonitorState() == EN_OAD_MONITOR_STATE_UNT_CHECK_SCHEDULE)
                {
                    MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_UNT_SCHEDULE_NOT);
                }
                else
                {
                    if(_bScheduleOnCheck)
                    {
                        _bScheduleOnCheck = FALSE;
                        MApp_OAD_SetInfo();
                        MApp_Standby_Init();
                    }
                    else if (_bStandbyOffCheck)
                    {
                        _bStandbyOffCheck = FALSE;
                        MApp_OAD_SetInfo();
                        MApp_Standby_Init();
                    }
                    else
                    {
                        if(_bCheckScheduleMsg)
                        {
                            _bCheckScheduleMsg = FALSE;
                            bNITSignal_DSI = TRUE;
                            _bDisplayScheduleMsg = TRUE;
                        }
                    }
                }
            }
            break ;
        }

        case EN_OAD_MONITOR_STATE_UNT_SCHEDULE_NOT:
        {
            MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_UNT_WAIT_SCHEDULE);
            if(_bStandbyOffCheck || _bScheduleOnCheck)
            {
                if(_bStandbyOffCheck)
                    _bStandbyOffCheck = FALSE;
                if(_bScheduleOnCheck)
                {
                    _bScheduleOnCheck = FALSE;
                }

                MApp_OAD_SetInfo();
                OAD_DEBUG(printf(" EN_OAD_STANDBY_OFF >>>  %s   %u\n",__FUNCTION__,__LINE__));
                MApp_OAD_ChannelChange(wPrev_TSID, wPrev_ONID, wPrev_SID);
                MApp_Standby_Init();
            }
            else
            {
                if(_bPowerOnCheck)
                {
                    OAD_DEBUG(printf(" EN_OAD_PANEL_ON_AND_RESTART >>>  %s   %u\n",__FUNCTION__,__LINE__));
                    _bPowerOnCheck = FALSE;
                    MApp_OAD_ChannelChange(wPrev_TSID, wPrev_ONID, wPrev_SID);
                    MApp_OAD_SetPowerOnScreen();
                    _bCheckScheduleMsg = TRUE;
                }
                if(MApp_OAD_IsOadScanCheck())
                {
                    MApp_OAD_SetScanState(STATE_OAD_SCAN_SSU_FOUND_OR_SCHEDULE);
                    _bCheckScheduleMsg = TRUE;
                }
                else
                {
                    OAD_DEBUG(printf(">>> m_bCheckScheduleMsg :>  TRUE\n"));
                    MApp_OAD_ChannelChange(wPrev_TSID, wPrev_ONID, wPrev_SID);
                    _bCheckScheduleMsg = TRUE;
                }
                MApp_OAD_SetInfo();
            }
            break;
        }

        case EN_OAD_MONITOR_STATE_PMT_SID_RECEINING:
        break;
#endif
        case EN_OAD_MONITOR_STATE_NIT_SIGNAL:
        {
            if(MApp_OAD_IsStandbyOffCheck() || MApp_OAD_IsScheduleOnCheck() || MApp_OAD_IsPowerOnCheck())
            {
                OAD_DEBUG( printf(" EN_OAD_CHANNELCHANGE >>>  %s   %u\n",__FUNCTION__,__LINE__) );
                if(TRUE == MApp_OAD_ChannelChange(wTransportStream_ID_OAD, wOriginalNetwork_ID_OAD, wService_ID_OAD))
                {
                    MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_PMT_DBID_RECEINING);
                    bNITSignal_DSI = TRUE;
                    _PMT_Ready = FALSE;
                }
                else
                {
                    MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_STOP);
                }
            }
            break;
        }
        case EN_OAD_MONITOR_STATE_RECEIVING_TIMEOUT:
        {
            MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_PMT_DBID_RECEINING);
            wService_ID_OAD = INVALID_SERVICE_ID;
            wOad_PID = INVALID_PID;
            break;
        }

        case EN_OAD_MONITOR_STATE_EXIT:
        case EN_OAD_MONITOR_STATE_STOP:
        {
            U8 j;
            msAPI_OAD_DeleteSectionFilter(MApp_Dmx_GetFid(EN_OAD_MONITOR_FID));
            msAPI_OAD_DeleteSectionFilter(MApp_Dmx_GetFid(EN_OAD_DOWNLOAD_FID));

            u32CheckTOTTimer = 0;

            //MApp_OAD_ResetInfo();
            if(_bStandbyOffCheck || _bScheduleOnCheck)
            {
                if(_bStandbyOffCheck)
                    _bStandbyOffCheck = FALSE;
                if(_bScheduleOnCheck)
                {
                    _bScheduleOnCheck = FALSE;
                    MApp_OAD_SetInfo();
                }
                MApp_OAD_ChannelChange(wPrev_TSID, wPrev_ONID, wPrev_SID);
                MApp_OAD_Init();
                #if (!BLOADER)
                MApp_Standby_Init();
                #endif
            }
            else
            {
                OAD_DEBUG( printf("_bPowerOnCheck >> %d\n",_bPowerOnCheck) );
                if(_bPowerOnCheck)
                {
                    _bPowerOnCheck = FALSE;
                    MApp_SI_Force_NIT_Parse();
                    OAD_DEBUG( printf(" EN_OAD_CHANNELCHANGE >>>  %s   %u\n",__FUNCTION__,__LINE__) );
                    MApp_OAD_ChannelChange(wPrev_TSID, wPrev_ONID, wPrev_SID);
                    MApp_OAD_SetPowerOnScreen();
                }
                else if(_bOadScanCheck)
                {
                    MApp_OAD_SetScanState(STATE_OAD_SCAN_NEXT_CHANNEL);
                }
                else if(MApp_OAD_GetSignalForStandby() && (OSD_COUNTRY_SETTING == OSD_COUNTRY_NEWZEALAND))
                {
                    MApp_OAD_ResetInfo();
                    MApp_OAD_ChannelChange(wPrev_TSID, wPrev_ONID, wPrev_SID);
                    #if (!BLOADER)
                    MApp_Standby_Init();
                    #endif
                }
                else
                {
                    OAD_DEBUG( printf(" EN_OAD_CHANNELCHANGE >>>  %s   %u\n",__FUNCTION__,__LINE__) );
                    MApp_OAD_ChannelChange(wPrev_TSID, wPrev_ONID, wPrev_SID);
                }
                if(eState == EN_OAD_MONITOR_STATE_STOP)
                {
                    _bDVB_OUI_Enable = FALSE;
                    MApp_OAD_Init();
                }
                else
                {
                    for(j=0; j<MAX_SIGNAL_COUNT; j++)
                    {
                        if((_stOadNitSignal.stNitSignal[j].u16TSID == wTransportStream_ID_OAD)
                            &&(_stOadNitSignal.stNitSignal[j].u16ONID == wOriginalNetwork_ID_OAD)
                            &&(_stOadNitSignal.stNitSignal[j].u16SID == wService_ID_OAD))
                        {
                            _stOadNitSignal.stNitSignal[j].bUsed = FALSE;
                        }
                        if(_stOadPmtSignal.stPmtSignal[j].u16SID == wService_ID_OAD)
                        {
                            _stOadPmtSignal.stPmtSignal[j].bUsed = FALSE;
                        }
                    }
                    MApp_OAD_Reset();
                }
                bNITSignal_DSI = FALSE;
                //MApp_OAD_SetInfo();
            }
        #if (ENABLE_UPDATE_MULTIPLEX_VIA_NIT)
            MApp_SI_EnableNetworkCheck(TRUE);
        #endif
            break ;
        }

        case EN_OAD_MONITOR_STATE_NONE:
        {
            if(_bOADRunning)
            {
                _bOADRunning = FALSE;
                msAPI_OAD_DeleteSectionFilter(MApp_Dmx_GetFid(EN_OAD_MONITOR_FID));
                msAPI_OAD_DeleteSectionFilter(MApp_Dmx_GetFid(EN_OAD_DOWNLOAD_FID));

                u32CheckTOTTimer = 0;
                if(_bStandbyOffCheck || _bScheduleOnCheck)
                {
                    if(_bStandbyOffCheck)
                        _bStandbyOffCheck = FALSE;
                    if(_bScheduleOnCheck)
                    {
                        _bScheduleOnCheck = FALSE;
                        //MApp_OAD_SetInfo();
                    }
                    MApp_OAD_ChannelChange(wPrev_TSID, wPrev_ONID, wPrev_SID);
                    MApp_OAD_ResetInfo();
                    #if (!BLOADER)
                    MApp_Standby_Init();
                    #endif
                }
                else if(_bOadScanCheck)
                {
                    MApp_OAD_SetScanState(STATE_OAD_SCAN_NEXT_CHANNEL);
                    MApp_OAD_ResetInfo();
                }
                else
                {
                    if(_bPowerOnCheck)
                    {
                        _bPowerOnCheck = FALSE;
                        //MApp_OAD_SetInfo();
                        MApp_OAD_ChannelChange(wPrev_TSID, wPrev_ONID, wPrev_SID);
                        MApp_OAD_SetPowerOnScreen();
                    }
                    else
                    {
                        MApp_OAD_ChannelChange(wPrev_TSID, wPrev_ONID, wPrev_SID);
                        _bDVB_OUI_Enable = FALSE;
                    }
                    bNITSignal_DSI = FALSE;
                    MApp_OAD_SetInfo();
                }
        #if (ENABLE_UPDATE_MULTIPLEX_VIA_NIT)
            MApp_SI_EnableNetworkCheck(TRUE);
        #endif
            }
            break;
        }

        case EN_OAD_MONITOR_STATE_UNT_SIGNAL:
        case EN_OAD_MONITOR_STATE_UNT_LINKAGE_SSU_FOUND:
        case EN_OAD_MONITOR_STATE_PMT_DBID_RECEINING:
        case EN_OAD_MONITOR_STATE_WAIT_PMT_RECEINING:
        default:
        {
            break;
        }
    }
}

void MApp_OAD_Download( void )
{
    static U32 u32DsmccTimer=0 ;
    U8 *pu8Buf = NULL;
    U16 blockID=0,msgLen=0,msgType=0 ;
    U32 msgAddr = 0 ;
    OAD_STATUS_REPORT_TYPE ddbStatus ;

    //OAD_DEBUG( printf("eState_Download = %d\n", (U8)MApp_OAD_GetDownloadState()) );

    switch (MApp_OAD_GetDownloadState())
    {
        case EN_OAD_DOWNLOAD_STATE_FLASH_ERASEINIT:
        {
            u32FlashStartAddr = 0 ;
            u32FlashEndAddr = u32FlashStartAddr + SW_UPDATE_ERASE_SIZE - 1;
            u16StartBlock = u32FlashStartAddr/SW_UPDATE_BLOCK_SIZE;
            u16EndBlock = u32FlashEndAddr/SW_UPDATE_BLOCK_SIZE;
            u16BlockNo  = u16StartBlock;
            MDrv_FLASH_WriteProtect(DISABLE) ;
            MApp_OAD_SetDownloadState(EN_OAD_DOWNLOAD_STATE_FLASH_ERASING) ;
            break;
        }
        case EN_OAD_DOWNLOAD_STATE_FLASH_ERASING:
        {
            if (u16BlockNo++ <= u16EndBlock)
            {
                OAD_DEBUG(printf("erase=%d\n",u16BlockNo));
                MDrv_FLASH_AddressErase(u16BlockNo*SW_UPDATE_BLOCK_SIZE, SW_UPDATE_BLOCK_SIZE, TRUE);
            }
            else
            {
                MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_DII_INIT) ;
            }
            break;
        }

        case EN_OAD_DOWNLOAD_STATE_DDB_INIT:
        {
            if(msAPI_OAD_CreateSectionFilter( MSAPI_DMX_FILTER_TYPE_OAD_DOWNLOAD,OAD_DATA_SECTION_TYPE ,OAD_DSMCC_MSGID_DDB,wOad_PID,MAPP_DMX_GET_PID(OAD_DOWNLOAD_FID), INVALID_VERSION_NUM) == TRUE)
            {
                MApp_OAD_SetDownloadState(EN_OAD_DOWNLOAD_STATE_DDB_RECEIVING) ;
                u32DownloadSize = 0x0;
                u32DsmccTimer = msAPI_Timer_GetTime0();
            #if (BLOADER)
                MApp_BL_DisplaySystem_clear(); //clear screen
                MApp_BL_DisplaySystem_setStatus((S8*)"DOWNLOAD");
                MApp_BL_DisplaySystem(0);
            #endif //(BLOADER)
            }
            else
            {

            }

            break;
        }
        case EN_OAD_DOWNLOAD_STATE_DDB_RECEIVING:
        {
            pu8Buf = msAPI_OAD_PollingSectionFilter(*MAPP_DMX_GET_PID(OAD_DOWNLOAD_FID),MAPP_DMX_GETSI_4K_SECBUFFER());

            if(pu8Buf)
            {
                ddbStatus = msAPI_OAD_ProcessDDB(pu8Buf,&blockID,&msgLen,&msgAddr,&msgType) ;

                if ((ddbStatus != OAD_FAIL)&&(msgLen))
                {
                    if (msgType==OAD_MODE_OBJCAR)
                    {
                        if (blockID==0)
                        {
                        #if FLASH_DIRECT_WRITE
                            MDrv_FLASH_Write(u32FlashStartAddr, msgLen, (U8*)msgAddr ) ;
                        #else
                            memcpy((U8*)MsOS_PA2KSEG1(DOWNLOAD_BUFFER_ADR_OAD),(U8*)msgAddr,(U32)msgLen) ;
                        #endif
                        }
                        else
                        {
                        #if FLASH_DIRECT_WRITE
                            MDrv_FLASH_Write(u32FlashStartAddr+(blockID*msAPI_OAD_GetBlockSize())-BIOP_HEADER_LEN, msgLen, (U8*)msgAddr ) ;
                        #else
                            memcpy((U8*)MsOS_PA2KSEG1(DOWNLOAD_BUFFER_ADR_OAD+(blockID*msAPI_OAD_GetBlockSize())-BIOP_HEADER_LEN),(U8*)msgAddr,(U32)msgLen) ;
                        #endif
                        }

                    }
                    else if (msgType==OAD_MODE_DATACAR)
                    {
                    #if FLASH_DIRECT_WRITE
                        MDrv_FLASH_Write(u32FlashStartAddr+(blockID*msAPI_OAD_GetBlockSize()), msgLen, (U8*)msgAddr ) ;
                    #else
                        memcpy((U8*)MsOS_PA2KSEG1(DOWNLOAD_BUFFER_ADR_OAD+(blockID*msAPI_OAD_GetBlockSize())),(U8*)msgAddr,(U32)msgLen) ;
                    #endif
                    }
                    u32DownloadSize += msgLen ;
                    printf(".>>> (OAD downloading) %ld\n",u32DownloadSize);
                }

                if (ddbStatus == OAD_COMPLETE)
                {
                #if OAD_TEST
                #if FLASH_DIRECT_WRITE
                #if 0
                    MDrv_Sys_SetWatchDogTimer(0);
                    MDrv_Sys_EnableWatchDog();
                    while(1); // reset
                #else
                    msAPI_BLoader_Reboot();
                #endif
                #else
                    MApp_SwUpdate_Start( SW_UPDATE_MODE_PARTIAL_OAD,FALSE, FALSE, FALSE,DOWNLOAD_BUFFER_ADR_OAD,u32DownloadSize,DOWNLOAD_BUFFER_TYPE_OAD, FALSE);
                #endif // #if FLASH_DIRECT_WRITE
                #else // #if FLASH_DIRECT_WRITE
                    MApp_OAD_SetDownloadState(EN_OAD_DOWNLOAD_STATE_DDB_COMPLETED) ;
                #endif // #if OAD_TEST

                #if FLASH_DIRECT_WRITE
                    MDrv_FLASH_WriteProtect(ENABLE) ;
                #endif
                #if (BLOADER)
                    MApp_BL_DisplaySystem_clear(); //clear screen
                    MApp_BL_DisplaySystem_setStatus((S8*)"Software Update(OAD)");
                    MApp_BL_DisplaySystem(0);
                    if (MApp_SwUpdate_Start( SW_UPDATE_MODE_PARTIAL_OAD,FALSE, FALSE, FALSE,DOWNLOAD_BUFFER_ADR_OAD,u32DownloadSize,DOWNLOAD_BUFFER_TYPE_OAD, FALSE))
                    {
                        return;
                    }
                #endif //(BLOADER)
                }
                #if (BLOADER)
                {
                    static U8 u8PrevPersentage=0;
                    U8 u8Percentage = MApp_OAD_GetProgress();
                    if (u8Percentage > 100)
                        u8Percentage = 100;
                    if(u8PrevPersentage != u8Percentage)
                    {
                        u8PrevPersentage = u8Percentage;
                        MApp_BL_DisplaySystem(u8Percentage);
                        //printf("u8Percentage: %u, at %d\n", u8Percentage, __LINE__);
                    }
                }
                #endif //(BLOADER)
            }

            if (msAPI_Timer_DiffTimeFromNow(u32DsmccTimer) > MONITOR_DDB_TIME_OUT)
            {
                OAD_ASSERT( printf("Error> Exit DDB\n") );
                MApp_OAD_SetDownloadState(EN_OAD_DOWNLOAD_STATE_STOP) ;
            }
            break ;

        }
        case EN_OAD_DOWNLOAD_STATE_STOP:
        {
            msAPI_OAD_DeleteSectionFilter(MAPP_DMX_GET_PID(OAD_DOWNLOAD_FID));
            MApp_OAD_SetDownloadState(EN_OAD_DOWNLOAD_STATE_NONE);
            OAD_DEBUG( printf(" %s    %u\n",__FUNCTION__,__LINE__) );
            MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_STOP);
        }
        break;
        case EN_OAD_DOWNLOAD_STATE_DDB_COMPLETED:
        case EN_OAD_DOWNLOAD_STATE_NONE:
        case EN_OAD_DOWNLOAD_STATE_WAIT:
        default:
        {
            break;
        }
    }
}


BOOLEAN MApp_OAD_IsDownloadAvailable(void)
{
    EN_OAD_MONITOR_STATE mState = MApp_OAD_GetMonitorState() ;
    if(MApp_OAD_IsUserSelectOn() &&
        (FALSE == MApp_OAD_IsStandbyOffCheck()) &&
        //(FALSE == MApp_OAD_IsScheduleOnCheck()) &&
        (FALSE == MApp_OAD_IsOadScanCheck()) &&
        (FALSE == MApp_OAD_IsPowerOnCheck()))
    {
        if((mState==EN_OAD_MONITOR_STATE_NIT_DSI_SIGNAL)|| \
            (mState==EN_OAD_MONITOR_STATE_DSI_SIGNAL)|| \
            (mState==EN_OAD_MONITOR_STATE_NIT_SIGNAL) || \
            (mState==EN_OAD_MONITOR_STATE_UNT_WAIT_SCHEDULE && _bDisplayScheduleMsg))
        {
            //MApp_OAD_SetAppState(EN_OAD_APP_STATE_INIT);
            return TRUE;
        }
    }
    return FALSE;
}

BOOLEAN MApp_OAD_IsDownloadCompleted(void)
{
    EN_OAD_DOWNLOAD_STATE dState = MApp_OAD_GetDownloadState() ;

    return (dState==EN_OAD_DOWNLOAD_STATE_DDB_COMPLETED)?TRUE:FALSE;
}

BOOLEAN MApp_OAD_IsDownloading(void)
{
    EN_OAD_DOWNLOAD_STATE dState = MApp_OAD_GetDownloadState() ;

    return ((dState!=EN_OAD_DOWNLOAD_STATE_NONE)) ? TRUE : FALSE ;
}

BOOLEAN MApp_OAD_IsUntSchedule(void)
{
    U32 u32currentTime;
    U32 u32CurDayTime,u32StartDayTime,u32EndDayTime;
    U32 u32StartTime=0, u32EndTime=0;
    U8 i;
    ST_TIME stCurTime,stStartTime,stEndTime;
    U32 u32Duration, u32Period, u32Temp;
    U32 u32TmpStartTime=0, u32TmpEndTime=0;

    if(MApp_SI_IS_GotTDTOrTOT() == FALSE)
    {
        return FALSE;
    }
    for(i=0; i<MAX_SCHEDULE_COUNT; i++)
    {
        if(untDescriptor.untSchedule[i].u32StartTime == 0 && untDescriptor.untSchedule[i].u32EndTime == 0)
        {
            continue;
        }
        u32currentTime = msAPI_Timer_GetSystemTime();

        if(untDescriptor.untSchedule[i].u8PeriodFlag)
        {
            if(untDescriptor.untSchedule[i].u8DurationUnit == 1)
            {
                u32Duration = (untDescriptor.untSchedule[i].u8Duration) * SECONDS_PER_MIN;
            }
            else if(untDescriptor.untSchedule[i].u8DurationUnit == 2)
            {
                u32Duration = (untDescriptor.untSchedule[i].u8Duration) * SECONDS_PER_HOUR;
            }
            else if(untDescriptor.untSchedule[i].u8DurationUnit == 3)
            {
                u32Duration = (untDescriptor.untSchedule[i].u8Duration) * SECONDS_PER_DAY;
            }
            else
            {
                u32Duration = (untDescriptor.untSchedule[i].u8Duration);
            }

            if(untDescriptor.untSchedule[i].u8PeriodUnit == 1)
            {
                u32Period = (untDescriptor.untSchedule[i].u8Period) * SECONDS_PER_MIN;
            }
            else if(untDescriptor.untSchedule[i].u8PeriodUnit == 2)
            {
                u32Period = (untDescriptor.untSchedule[i].u8Period) * SECONDS_PER_HOUR;
            }
            else if(untDescriptor.untSchedule[i].u8PeriodUnit == 3)
            {
                u32Period = (untDescriptor.untSchedule[i].u8Period) * SECONDS_PER_DAY;
            }
            else
            {
                u32Period = (untDescriptor.untSchedule[i].u8Period);
            }

            if((u32currentTime < untDescriptor.untSchedule[i].u32StartTime)||
                (u32currentTime > untDescriptor.untSchedule[i].u32EndTime))
            {
                u32TmpStartTime = u32TmpEndTime = 0;
            }
            else
            {
                u32Temp = (u32currentTime - untDescriptor.untSchedule[i].u32StartTime) % u32Period;
                u32TmpStartTime = (u32currentTime - u32Temp)+ u32Period;
                if(u32TmpStartTime < untDescriptor.untSchedule[i].u32EndTime)
                    u32TmpEndTime = u32TmpStartTime + u32Duration;
                else
                    u32TmpStartTime = u32TmpEndTime = 0;
                if(u32TmpStartTime > 0 && u32TmpEndTime > 0)
                {
                    if(u32Temp < u32Duration)
                    {
                        if(untDescriptor.untSchedule[i].u8FinalAvail)
                        {
                            memset(&untDescriptor.untSchedule[i],0, sizeof(UNT_SCHEDULE));
                        }
                        _u32DL_StartTime = _u32DL_EndTime = 0;
                        MApp_ConvertSeconds2StTime ( u32currentTime, &stCurTime );
                        OAD_DEBUG( printf("1..System time %04d:%02d:%02d  %02d:%02d:%02d\n",stCurTime.u16Year,stCurTime.u8Month,stCurTime.u8Day,stCurTime.u8Hour,stCurTime.u8Min,stCurTime.u8Sec) );
                        MApp_ConvertSeconds2StTime (u32TmpStartTime, &stStartTime );
                        OAD_DEBUG( printf("1..Schedule start time %04d:%02d:%02d  %02d:%02d:%02d\n",stStartTime.u16Year,stStartTime.u8Month,stStartTime.u8Day,stStartTime.u8Hour,stStartTime.u8Min,stStartTime.u8Sec) );
                        MApp_ConvertSeconds2StTime (u32TmpEndTime, &stEndTime );
                        OAD_DEBUG( printf("1..Schedule end time %04d:%02d:%02d  %02d:%02d:%02d\n",stEndTime.u16Year,stEndTime.u8Month,stEndTime.u8Day,stEndTime.u8Hour,stEndTime.u8Min,stEndTime.u8Sec) );

                        return TRUE;
                    }
                    if(_u32DL_StartTime == 0 && _u32DL_EndTime == 0)
                    {
                        _u32DL_StartTime = u32TmpStartTime;
                        _u32DL_EndTime = u32TmpEndTime;
                        MApp_ConvertSeconds2StTime ( u32currentTime, &stCurTime );
                        OAD_DEBUG( printf("2..System time %04d:%02d:%02d  %02d:%02d:%02d\n",stCurTime.u16Year,stCurTime.u8Month,stCurTime.u8Day,stCurTime.u8Hour,stCurTime.u8Min,stCurTime.u8Sec) );
                        MApp_ConvertSeconds2StTime ( _u32DL_StartTime, &stCurTime );
                        OAD_DEBUG( printf("2..Start time %04d:%02d:%02d  %02d:%02d:%02d\n",stCurTime.u16Year,stCurTime.u8Month,stCurTime.u8Day,stCurTime.u8Hour,stCurTime.u8Min,stCurTime.u8Sec) );
                        MApp_ConvertSeconds2StTime ( _u32DL_EndTime, &stCurTime );
                        OAD_DEBUG( printf("2..End time %04d:%02d:%02d  %02d:%02d:%02d\n",stCurTime.u16Year,stCurTime.u8Month,stCurTime.u8Day,stCurTime.u8Hour,stCurTime.u8Min,stCurTime.u8Sec) );

                    }
                    else
                    {
                        if(u32TmpStartTime < _u32DL_StartTime && u32TmpEndTime < _u32DL_StartTime)
                        {
                            _u32DL_StartTime = u32TmpStartTime;
                            _u32DL_EndTime = u32TmpEndTime;
                            MApp_ConvertSeconds2StTime ( u32currentTime, &stCurTime );
                            OAD_DEBUG( printf("2..System time %04d:%02d:%02d  %02d:%02d:%02d\n",stCurTime.u16Year,stCurTime.u8Month,stCurTime.u8Day,stCurTime.u8Hour,stCurTime.u8Min,stCurTime.u8Sec) );
                            MApp_ConvertSeconds2StTime ( _u32DL_StartTime, &stCurTime );
                            OAD_DEBUG( printf("2..Start time %04d:%02d:%02d  %02d:%02d:%02d\n",stCurTime.u16Year,stCurTime.u8Month,stCurTime.u8Day,stCurTime.u8Hour,stCurTime.u8Min,stCurTime.u8Sec) );
                            MApp_ConvertSeconds2StTime ( _u32DL_EndTime, &stCurTime );
                            OAD_DEBUG( printf("2..End time %04d:%02d:%02d  %02d:%02d:%02d\n",stCurTime.u16Year,stCurTime.u8Month,stCurTime.u8Day,stCurTime.u8Hour,stCurTime.u8Min,stCurTime.u8Sec) );
                        }
                    }
                }
            }

        }
        else
        {
            if(untDescriptor.untSchedule[i].u32StartTime == 0 && untDescriptor.untSchedule[i].u32EndTime == 0)
            {
                continue;
            }
            u32CurDayTime = u32currentTime % SECONDS_PER_DAY;
            u32StartDayTime = untDescriptor.untSchedule[i].u32StartTime % SECONDS_PER_DAY;
            u32EndDayTime = untDescriptor.untSchedule[i].u32EndTime % SECONDS_PER_DAY;

            if((u32currentTime>untDescriptor.untSchedule[i].u32StartTime)&&(u32currentTime<untDescriptor.untSchedule[i].u32EndTime))
            {
                if(u32CurDayTime >= u32StartDayTime && u32CurDayTime < u32EndDayTime)
                {
                    _u32DL_StartTime = u32currentTime;
                    _u32DL_EndTime = u32currentTime + (u32EndDayTime - u32CurDayTime);

                    return TRUE;
                }
                else if(u32CurDayTime < u32StartDayTime)
                {
                    u32StartTime = u32currentTime + (u32StartDayTime-u32CurDayTime);
                    u32EndTime = u32currentTime + (u32EndDayTime-u32CurDayTime);
                    if(_u32DL_StartTime == 0 || _u32DL_StartTime > u32StartTime)
                    {
                        _u32DL_StartTime = u32StartTime;
                        _u32DL_EndTime = u32EndTime;
                    }
                }
                else if(u32CurDayTime > u32EndDayTime)
                {
                    u32StartTime = u32currentTime + (SECONDS_PER_DAY - u32CurDayTime)+ u32StartDayTime;
                    u32EndTime = u32currentTime + (SECONDS_PER_DAY - u32CurDayTime)+u32EndDayTime;
                    if(_u32DL_StartTime == 0 || _u32DL_StartTime > u32StartTime)
                    {
                        _u32DL_StartTime = u32StartTime;
                        _u32DL_EndTime = u32EndTime;
                    }
                }
            }
            else
            {
                _u32DL_StartTime = _u32DL_EndTime = 0;
            }
        }
    }

    return FALSE;
}

BOOLEAN MApp_OAD_IsUserSelectOn(void)
{
    return stGenSetting.g_SysSetting.fSoftwareUpdate ;
}

void MApp_OAD_StartDownload(void)
{
    switch(MApp_OAD_GetMonitorState())
    {
        case EN_OAD_MONITOR_STATE_DSI_SIGNAL:
        case EN_OAD_MONITOR_STATE_NIT_DSI_SIGNAL:
        {
            MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_DII_INIT) ;
            break ;
        }
        case EN_OAD_MONITOR_STATE_NIT_SIGNAL:
        {
            MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_PMT_DBID_RECEINING) ;
            break;
        }
        default:
        {
            break;
        }
    }
}

void MApp_OAD_StopDownload(void)
{
    MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_STOP) ;
    MApp_OAD_SetDownloadState(EN_OAD_DOWNLOAD_STATE_STOP) ;
}

void MApp_OAD_GetVersion(U32 *tvVER,U32 *tsVER)
{
    *tvVER = tvVersion ;
    *tsVER = tsVersion ;
}

void MApp_OAD_GetService(U16 *netID,U16 *tsID,U16 *serviceID,MEMBER_SERVICETYPE *type,WORD *position)
{
    *netID = wOriginalNetwork_ID_OAD ;
    *tsID = wTransportStream_ID_OAD ;
    *serviceID = wService_ID_OAD ;
    *type = bServiceType ;
    *position = wCurrentPosition ;
}

U8 MApp_OAD_GetProgress(void)
{
    return msAPI_OAD_GetProgress() ;
}

U32 MApp_OAD_GetScheduleStart(void)
{
    return (MApp_OAD_GetMonitorState()== EN_OAD_MONITOR_STATE_UNT_WAIT_SCHEDULE)
          ? _u32DL_StartTime:0;
}

U32 MApp_OAD_GetScheduleEnd(void)
{
    return (MApp_OAD_GetMonitorState()== EN_OAD_MONITOR_STATE_UNT_WAIT_SCHEDULE)
          ? _u32DL_EndTime:0;
}

WORD MApp_OAD_GetServiceLcn(void)
{
    MEMBER_SERVICETYPE eGotServiceType;
    U16 u16GotPosition ;
    U8 bResult ;

    bResult = msAPI_CM_GetServiceTypeAndPositionWithIDs(  wTransportStream_ID_OAD, wOriginalNetwork_ID_OAD, wService_ID_OAD, 1,&eGotServiceType, &u16GotPosition, TRUE);

    if(bResult)
    {
        return msAPI_CM_GetLogicalChannelNumber(eGotServiceType,u16GotPosition);
    }
    else
    {
        return INVALID_LOGICAL_CHANNEL_NUMBER;
    }
}


void MApp_OAD_AppTest(void)
{
    if (stGenSetting.g_SysSetting.fSoftwareUpdate==0) return ;

    if (MApp_OAD_GetDownloadState()!=EN_OAD_DOWNLOAD_STATE_NONE) return ;

    switch(MApp_OAD_GetMonitorState())
    {
        case EN_OAD_MONITOR_STATE_DSI_SIGNAL:
        case EN_OAD_MONITOR_STATE_NIT_DSI_SIGNAL:
        {
            #if FLASH_DIRECT_WRITE
            MApp_OAD_SetDownloadState(EN_OAD_DOWNLOAD_STATE_FLASH_ERASEINIT) ;
            #else
            MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_DII_INIT) ;
            #endif
            break ;
        }
        case EN_OAD_MONITOR_STATE_NIT_SIGNAL:
        {
            if( !IsDTVInUse() )
            {
                MApp_Dmx_CloseAllFilters();

            #if 1 // 20150908
                //UI_INPUT_SOURCE_TYPE = SYS_DEFAULT_DTV_UI_INPUTSOURCE;
                MApp_InputSrc_Set_UiInputSrcType(SYS_DEFAULT_DTV_UI_INPUTSOURCE);
            #else
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_DTV;
            #endif

                MApp_InputSource_SwitchSource( UI_INPUT_SOURCE_TYPE ,MAIN_WINDOW);
            }

            MApp_TopStateMachine_SetTopState(STATE_TOP_DIGITALINPUTS) ;
            MApp_ChannelChange_ChangeSpeciChannel(wService_ID_OAD, wOriginalNetwork_ID_OAD, wTransportStream_ID_OAD, TYPE_CHANNEL_CHANGE_SER_ID,TRUE) ;

            MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_PMT_DBID_RECEINING) ;
            break;
        }
#if (!BLOADER)
        case EN_OAD_MONITOR_STATE_UNT_SIGNAL:
        {
            if (MApp_OAD_IsUntSchedule())
            {
                MApp_SI_Force_PMT_Parse() ; // tune to the target srevice first
                MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_PMT_SID_RECEINING) ;
            }
            break ;
        }
#endif
        case EN_OAD_MONITOR_STATE_PMT_DBID_RECEINING:
        case EN_OAD_MONITOR_STATE_PMT_SID_RECEINING:
        case EN_OAD_MONITOR_STATE_NONE:
        default:
        {
            break;
        }
    }
}

#if(!BLOADER)
EN_RET MApp_OAD_AppMain(void)
{
    EN_RET enRetVal =EXIT_NULL;
    static UINT32 u32SignalTimer;

    //OAD_DEBUG(printf("@@@@ eState_OAD_Main = %d\n", MApp_OAD_GetAppState()));

    switch(MApp_OAD_GetAppState())
    {
        case EN_OAD_APP_STATE_INIT:
        {
        #if (!BLOADER)
            MApp_ZUI_ACT_StartupOSD(E_OSD_OAD); // show Signal UI - DSI or UNT or UNT
        #endif
            MApp_OAD_SetAppState(EN_OAD_APP_STATE_WAIT_USER) ;
            u32SignalTimer = msAPI_Timer_GetTime0();
            break ;
        }
        case EN_OAD_APP_STATE_WAIT_USER:
        {
            MApp_ZUI_ProcessKey(u8KeyCode);
            u8KeyCode = KEY_NULL;
            if (msAPI_Timer_DiffTimeFromNow(u32SignalTimer) > MONITOR_USER_TIME_OUT)
            {
                if(OSD_COUNTRY_SETTING == OSD_COUNTRY_NEWZEALAND || OSD_COUNTRY_SETTING == OSD_COUNTRY_NORWAY)
                {
                    MApp_ZUI_ProcessKey(KEY_LEFT);
                }
                else
                {
                    MApp_OAD_SetAppState(EN_OAD_APP_STATE_STOP);
                }
            }
            else if (MApp_OAD_GetMonitorState()==EN_OAD_MONITOR_STATE_NIT_DSI_SIGNAL)
            {
                extern BOOLEAN fEnableSignalMonitor;
                MApp_OAD_SetDownloadState(EN_OAD_DOWNLOAD_STATE_DDB_INIT) ;
                MApp_OAD_SetAppState(EN_OAD_APP_STATE_DOWNLOADING);
                MApp_ChannelChange_DisableChannel(TRUE, MAIN_WINDOW);
            #if (!BLOADER)
                MApp_Dmx_SetMonitorStatus(TRUE, EN_MONITOR_TABLE_ALL);
            #endif
                fEnableSignalMonitor=TRUE;
            }
            break;
        }
        case EN_OAD_APP_STATE_YES:
        {
            if (MApp_OAD_GetMonitorState()==EN_OAD_MONITOR_STATE_DSI_SIGNAL)
            {
                extern BOOLEAN fEnableSignalMonitor;
                #if FLASH_DIRECT_WRITE
                MApp_OAD_SetDownloadState(EN_OAD_DOWNLOAD_STATE_FLASH_ERASEINIT) ;
                #else
                MApp_OAD_SetDownloadState(EN_OAD_DOWNLOAD_STATE_DDB_INIT) ;
                #endif
                MApp_OAD_SetAppState(EN_OAD_APP_STATE_DOWNLOADING) ;
                OAD_DEBUG( printf("MApp_OAD_AppMain[%d]: MApp_OAD_ChannelChange to the service with ts_id=0x%X, on_id=0x%X, sid=0x%X.\n", __LINE__, wTransportStream_ID_OAD, wOriginalNetwork_ID_OAD, wService_ID_OAD) );
                MApp_OAD_ChannelChange(wTransportStream_ID_OAD, wOriginalNetwork_ID_OAD, wService_ID_OAD);
                bServiceType = msAPI_CM_GetCurrentServiceType();
                wCurrentPosition = msAPI_CM_GetCurrentPosition(bServiceType);
                cRFChannelNumber = msAPI_CM_GetPhysicalChannelNumber(bServiceType, wCurrentPosition);
                msAPI_DFT_GetTSSetting(cRFChannelNumber, &stTPSetting);
                MApp_OAD_SetInfo_ForBL(wOad_PID, stTPSetting.u32Frequency, stTPSetting.enBandWidth);
                MApp_ChannelChange_DisableChannel(TRUE, MAIN_WINDOW);
            #if (!BLOADER)
                MApp_Dmx_SetMonitorStatus(TRUE, EN_MONITOR_TABLE_ALL);
            #endif
                MApp_ZUI_ACT_ShowDownloadUI();
                fEnableSignalMonitor=TRUE;
                MApp_ZUI_API_ShowWindow(HWND_OAD_BTN_YES,SW_HIDE);
                MApp_ZUI_API_ShowWindow(HWND_OAD_BTN_NO,SW_HIDE);
            }
            else if (MApp_OAD_GetMonitorState()==EN_OAD_MONITOR_STATE_NIT_SIGNAL)
            {
                MApp_OAD_SetAppState(EN_OAD_APP_STATE_EXIT) ;
                bNITSignal_DSI = TRUE;
                MApp_OAD_ChannelChange(wTransportStream_ID_OAD, wOriginalNetwork_ID_OAD, wService_ID_OAD);
                _PMT_Ready = FALSE;
                MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_PMT_DBID_RECEINING);
            }
            else if (MApp_OAD_GetMonitorState()==EN_OAD_MONITOR_STATE_UNT_SIGNAL)
            {
                MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_UNT_WAIT_SCHEDULE) ;
                MApp_OAD_SetAppState(EN_OAD_APP_STATE_EXIT) ;
            }
            else if(_bDisplayScheduleMsg && MApp_OAD_GetMonitorState()==EN_OAD_MONITOR_STATE_UNT_WAIT_SCHEDULE)
            {
                MApp_OAD_ChannelChange(wPrev_TSID, wPrev_ONID, wPrev_SID);
                MApp_OAD_SetAppState(EN_OAD_APP_STATE_EXIT);
            }
        #if (!BLOADER)
            if(OSD_COUNTRY_SETTING != OSD_COUNTRY_NEWZEALAND && MApp_OAD_GetMonitorState() != EN_OAD_MONITOR_STATE_DSI_SIGNAL)
            {
                MApp_ZUI_ACT_ShutdownOSD();
            }
        #endif
            break ;
        }
        case EN_OAD_APP_STATE_NO:
        case EN_OAD_APP_STATE_STOP:
        {
            // For NZ OAD start
            {
                if(OSD_COUNTRY_SETTING == OSD_COUNTRY_NEWZEALAND)
                {
                    EN_OAD_MONITOR_STATE enMonState = MApp_OAD_GetMonitorState();
                    if((MApp_OAD_IsDownloading() == FALSE)
                        && ((enMonState == EN_OAD_MONITOR_STATE_DSI_SIGNAL)
                        || (enMonState == EN_OAD_MONITOR_STATE_NIT_SIGNAL)))
                    {
                        _bSignalForStandby = TRUE;
                        _stOADSignalForStandby.enNextMonitorState = enMonState;
                        _stOADSignalForStandby.PID = wOad_PID;
                        _stOADSignalForStandby.bServiceType = bServiceType;
                        _stOADSignalForStandby.wCurrentPosition = wCurrentPosition;
                        _stOADSignalForStandby.wOriginalNetwork_ID_OAD = wOriginalNetwork_ID_OAD;
                        _stOADSignalForStandby.wTransportStream_ID_OAD = wTransportStream_ID_OAD;
                        _stOADSignalForStandby.wService_ID_OAD = wService_ID_OAD;
                    }
                    else
                    {
                        // do nothing
                    }
                }
            }
            // For NZ OAD end
            extern BOOLEAN fEnableSignalMonitor;
            BOOLEAN bDownloading = MApp_OAD_IsDownloading();
            OAD_DEBUG( printf(" %s    %u\n",__FUNCTION__,__LINE__) );
        #if 1 // user stop oad
            MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_NONE);
        #else
            if(OSD_COUNTRY_SETTING == OSD_COUNTRY_NEWZEALAND)
            {
                MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_NONE) ;
            }
            else
            {
                MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_STOP) ;
            }
        #endif
            if(bDownloading)
            {
                fEnableSignalMonitor=FALSE;
            #if (!BLOADER)
                MApp_Dmx_SetMonitorStatus(FALSE, EN_MONITOR_TABLE_ALL);
            #endif
                MApp_ChannelChange_EnableChannel(MAIN_WINDOW);
            }
            else
            {
                //MApp_OAD_ChannelChange(wPrev_TSID, wPrev_ONID, wPrev_SID);
            }
            MApp_OAD_SetDownloadState(EN_OAD_DOWNLOAD_STATE_NONE) ;
            MApp_OAD_SetAppState(EN_OAD_APP_STATE_EXIT) ;
        #if (!BLOADER)
            MApp_ZUI_ACT_ShutdownOSD();
        #endif
            break;
        }
        case EN_OAD_APP_STATE_UPGRADING:
        {
            //check CRC32 of TMMYU4020.bin
            if(0x0 != MDrv_BDMA_CRC32(DOWNLOAD_BUFFER_ADR_OAD, u32DownloadSize, BDMA_CRC32_POLY, BDMA_CRC_SEED_0, E_BDMA_SRCDEV_MIU0, FALSE))
            {
                OAD_DEBUG( printf("Error> CRC32 Integrity Check failed !!\n") );
                if (pZUIDrawPercentageCB != NULL)
                    pZUIDrawPercentageCB(0xFE); //CRC Error
                break ;
            }
            else
            {
                OAD_DEBUG( printf("CRC32Integrity Check pass !!\n") );
            }
            // For NZ OAD start
            if(OSD_COUNTRY_SETTING == OSD_COUNTRY_NEWZEALAND)
            {
                if(MApp_OAD_GetSignalForStandby() == TRUE)
                {
                    stGenSetting.stMiscSetting.bDCOnOff = EN_POWER_DC_OFF;
                    MApp_DB_GEN_SaveData_RightNow();
                }
            }
            // For NZ OAD end
            MApp_SwUpdate_Start( SW_UPDATE_MODE_PARTIAL_OAD,FALSE, FALSE, FALSE,DOWNLOAD_BUFFER_ADR_OAD,u32DownloadSize,DOWNLOAD_BUFFER_TYPE_OAD, FALSE);
            break ;
        }

        case EN_OAD_APP_STATE_EXIT:
        {
            OAD_DEBUG( printf(" %s    %u\n",__FUNCTION__,__LINE__) );
            if(_bDisplayScheduleMsg)
            {
                _bDisplayScheduleMsg = FALSE;
            }
            if(OSD_COUNTRY_SETTING == OSD_COUNTRY_NORWAY)
            {
                //printf("\r\n >>> exit oad (%x,%x,%x)\n",wPrev_TSID, wPrev_ONID, wPrev_SID);
                //MApp_OAD_ChannelChange(wPrev_TSID, wPrev_ONID, wPrev_SID);
            }
            enRetVal = EXIT_CLOSE;
            MApp_OAD_SetAppState(EN_OAD_APP_STATE_NONE);
            break ;
        }
        case EN_OAD_APP_STATE_DOWNLOADING:
        {
            MApp_ZUI_ProcessKey(u8KeyCode);
            MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_OAD_PAINTPROGRESS);//update data;
            if (OSD_COUNTRY_SETTING == OSD_COUNTRY_NEWZEALAND || (IS_NORDIC_COUNTRY(OSD_COUNTRY_SETTING)))
            {
                if((MApp_OAD_GetProgress()==0)&&( FALSE != IsServiceTypeValid(ePrev_ServiceType) && msAPI_CM_GetCurrentServiceType() != ePrev_ServiceType))
                {
                    OAD_DEBUG(printf(">>> downning save(%d,%d)\n",ePrev_ServiceType, u16Prev_Position));
                    #if 0 // if use this, will RemoveProgram MSOAD-DC2,MSTAR SSU
                    //msAPI_CM_SetCurrentServiceType(ePrev_ServiceType);
                    //msAPI_CM_SetCurrentPosition( ePrev_ServiceType, u16Prev_Position);
                    #else
                    stGenSetting.stTvSetting.eCurrentServiceType = ePrev_ServiceType;
                    stGenSetting.stTvSetting.u16DTVRFChannelOrder = u16Prev_Position;
                    #endif
                    MApp_DB_GEN_SaveData_RightNow();
                }
                else if((MApp_OAD_GetProgress()==0)&&(FALSE != IsServiceTypeValid(ePrev_ServiceTypePower) && msAPI_CM_GetCurrentServiceType() != ePrev_ServiceTypePower))
                {
                    stGenSetting.stTvSetting.eCurrentServiceType = ePrev_ServiceTypePower;
                    stGenSetting.stTvSetting.u16DTVRFChannelOrder = u16Prev_PositionPower;
                    MApp_DB_GEN_SaveData_RightNow();
                }
            }

            if((MApp_OAD_IsScheduleOnCheck() || MApp_OAD_GetSignalForStandby()) && u8KeyCode == KEY_POWER)
            {
                u8KeyCode = KEY_NULL;
                _bScheduleOnCheck = FALSE;
                MApp_OAD_SetAppState(EN_OAD_APP_STATE_STOP);
                MApp_ZUI_ACT_ShutdownOSD();
            #if ENABLE_EPGTIMER_RECORDER_TURNOFFPANEL
                MApp_SetActiveStandbyMode(FALSE);
            #endif
                break;
            }
            if (MApp_OAD_IsDownloadCompleted())
            {
            #if FLASH_DIRECT_WRITE
                msAPI_BLoader_Reboot();
            #else
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_OAD_GOTOUPGRADE);
                MApp_OAD_SetAppState(EN_OAD_APP_STATE_UPGRADING) ;
            #endif
            }
            else if (!MApp_OAD_IsDownloading())
            {
                MApp_OAD_SetAppState(EN_OAD_APP_STATE_STOP) ;
            }

            break ;
        }
        case EN_OAD_APP_STATE_NONE:
            if(_bCheck_DSITimeOut)
            {
                OAD_DEBUG( printf(" %s      %u,_bCheck_DSITimeOut\n",__FUNCTION__,__LINE__) );
                _bCheck_DSITimeOut = FALSE;
                MApp_OAD_SetAppState(EN_OAD_APP_STATE_EXIT) ;
                #if (!BLOADER)
                MApp_ZUI_ACT_ShutdownOSD();
                #endif
            }
        default:
        {
            break;
        }
    }
    return enRetVal ;
}
#endif

#if (BLOADER)
EN_OAD_SCAN_STATE MApp_OAD_Scan( U8* percentage )
{
    BOOLEAN ScanResult;
    switch( enOADScanState )
    {
        case STATE_OAD_SCAN_INIT:
            msAPI_Tuner_Set_DemodPower( ENABLE );
            u8OadRFCh = msAPI_DFT_GetFirstPhysicalChannelNumber();
            msAPI_DFT_GetTSSetting( u8OadRFCh, &stOadTPSetting);
            enOADScanState = STATE_OAD_SCAN_SEARCH_RF_CHANNEL;
            break;

        case STATE_OAD_SCAN_NEXT_CHANNEL:
            {
                u8OadRFCh = msAPI_DFT_GetNextPhysicalChannelNumber(u8OadRFCh);
                if( u8OadRFCh == INVALID_PHYSICAL_CHANNEL_NUMBER/*u8MaxRFCh*/ )
                {
                    //printf("Invalid Phy Ch\n");
                    enOADScanState = STATE_OAD_SCAN_END;
                    break;
                }

                enOADScanState = STATE_OAD_SCAN_SEARCH_RF_CHANNEL;
                msAPI_DFT_GetTSSetting( u8OadRFCh, &stOadTPSetting);
                *percentage = msAPI_DFT_GetPercentWithPhysicalChannelNumber(u8OadRFCh);

                if (*percentage==100)
                {
                #if (!BLOADER)
                    MApp_ZUI_ACT_ShutdownOSD();
                    MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
                #endif
                #if (ENABLE_OAD) //wait to do
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_NO_OAD_AVAILABLE);
                #endif
                #if (!BLOADER)
                    _MApp_ZUI_API_WindowProcOnIdle();
                #endif
                    msAPI_Timer_Delayms(1500);
                    enOADScanState = STATE_OAD_SCAN_END; // kk 0319-2 bug
                }
                //printf("Rf %d, percent %d\n",u8OadRFCh,*percentage);
                break;
            }

        case STATE_OAD_SCAN_SEARCH_RF_CHANNEL:
            //wNetworkID = INVALID_ON_ID;
            if ( MApp_DVB_Scan(&stOadTPSetting, &ScanResult) == FALSE )
            {
                break;
            }

            if ( ScanResult == FE_LOCK )
            {
                //printf("FF lock, go to patpmt monitor state\n");

                enOADScanState = STATE_OAD_SCAN_PATPMT_MONITOR;
                u32OadScanWaitTableTimer = msAPI_Timer_GetTime0();
                MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_PMT_DBID_RECEINING);
                MApp_BL_SI_ParseStateInit();
            }
            else
            {
                //printf("Not lock, go to next\n");
                enOADScanState = STATE_OAD_SCAN_NEXT_CHANNEL;
            }

            break;

        case STATE_OAD_SCAN_PATPMT_MONITOR:
            if (MApp_BL_SI_Table_Monitor())
            {
                _BL_PmtReady = TRUE;
                if(_stOadPmtSignal.u8SignalCount > 0)
                {
                    while(1)
                    {
                        EN_OAD_MONITOR_STATE curr_state = MApp_OAD_GetMonitorState();
                        if((curr_state == EN_OAD_MONITOR_STATE_STOP) ||
                            (curr_state == EN_OAD_MONITOR_STATE_NONE))
                        {
                            MApp_BL_SI_DisableTableMonitor();
                            MApp_OAD_Monitor(); //do oad init
                            enOADScanState = STATE_OAD_SCAN_NEXT_CHANNEL;
                            break;
                        }
                        MApp_OAD_Monitor();
                        MsOS_DelayTask(25);
                        if(curr_state == EN_OAD_MONITOR_STATE_DSI_SIGNAL) //done
                        {
                            MApp_OAD_Download();
                        }
                    }
                }
                else
                {
                    MApp_BL_SI_DisableTableMonitor();
                    enOADScanState = STATE_OAD_SCAN_NEXT_CHANNEL;
                }
                MApp_OAD_SignalReset();
                _BL_PmtReady = FALSE;
            }
            else
            {
                if (msAPI_Timer_DiffTimeFromNow(u32OadScanWaitTableTimer) >= OAD_SCAN_WAIT_TABLE_TIME)
                {
                    MApp_BL_SI_DisableTableMonitor();
                    enOADScanState = STATE_OAD_SCAN_NEXT_CHANNEL;
                }
            }
            break;
        default:
            break;
    }
    if(enOADScanState == STATE_OAD_SCAN_END)
    {
        MApp_BL_SI_DisableTableMonitor();
    }
    return enOADScanState;
}
#if 0
EN_OAD_SCAN_STATE MApp_OAD_Scan( U8* percentage )
{
    BOOLEAN ScanResult;
    switch( enOADScanState )
    {
        case STATE_OAD_SCAN_INIT:
            msAPI_Tuner_Set_DemodPower( ENABLE );

            MApp_Dmx_GetScanTableStateInit();

            if ( MApp_DTV_Scan_Init() == TRUE )
            {
                u8OadRFCh = msAPI_DFT_GetFirstPhysicalChannelNumber();
                #if (BLOADER)
                msAPI_DFT_GetTSSetting( u8OadRFCh, &stOadTPSetting);
                #endif //(BLOADER)
                enOADScanState = STATE_OAD_SCAN_SEARCH_RF_CHANNEL;
            }
            else
            {
                /* allocate memory failure, maybe need to display warning msg. here */
                enOADScanState = STATE_OAD_SCAN_END;
            }
            break;

        case STATE_OAD_SCAN_NEXT_CHANNEL:
            {
            u8OadRFCh = msAPI_DFT_GetNextPhysicalChannelNumber(u8OadRFCh);
                if( u8OadRFCh == INVALID_PHYSICAL_CHANNEL_NUMBER/*u8MaxRFCh*/ )
                {
                    //printf("Invalid Phy Ch\n");
                    enOADScanState = STATE_OAD_SCAN_END;
                    break;
                }

                enOADScanState = STATE_OAD_SCAN_SEARCH_RF_CHANNEL;
                msAPI_DFT_GetTSSetting( u8OadRFCh, &stOadTPSetting);
                *percentage = msAPI_DFT_GetPercentWithPhysicalChannelNumber(u8OadRFCh);

                if (*percentage>100)
                {
                    enOADScanState = STATE_OAD_SCAN_END; // kk 0319-2 bug
                }
                //printf("Rf %d, percent %d\n",u8OadRFCh,*percentage);
                break;
            }

        case STATE_OAD_SCAN_SEARCH_RF_CHANNEL:
            //wNetworkID = INVALID_ON_ID;
            if ( MApp_DVB_Scan(&stOadTPSetting, &ScanResult) == FALSE )
            {
                break;
            }

            if ( ScanResult == FE_LOCK )
            {
                //printf("FF lock, go to patpmt monitor state\n");
                enOADScanState = STATE_OAD_SCAN_PATPMT_MONITOR;
            }
            else
            {
                //printf("Not lock, go to next\n");
                enOADScanState = STATE_OAD_SCAN_NEXT_CHANNEL;
            }

            break;

        case STATE_OAD_SCAN_PATPMT_MONITOR:
            //printf("STATE_OAD_SCAN_PATPMT_MONITOR\n");
            u32OadScanWaitTableTimer = msAPI_Timer_GetTime0();
            MApp_Dmx_SetOADScanMode(TRUE);
            MApp_SI_Table_Monitor();
            enOADScanState = STATE_OAD_SCAN_WAIT_PATPMT_MONITOR;
            break;

        case STATE_OAD_SCAN_WAIT_PATPMT_MONITOR:
            #if (BLOADER)
            MApp_Dmx_SetOADScanMode(TRUE);
            #endif //(BLOADER)
            MApp_SI_Table_Monitor();
            if(!MApp_Dmx_GetOADScanMode() || msAPI_Timer_DiffTimeFromNow(u32OadScanWaitTableTimer) >= OAD_SCAN_WAIT_TABLE_TIME)
            {
                MApp_Dmx_SetOADScanMode(FALSE);
                #if (BLOADER)
                MApp_Dmx_GetScanTableStateInit();
                #endif //(BLOADER)
                enOADScanState = STATE_OAD_SCAN_NEXT_CHANNEL;
                break;
            }

            if(MApp_OAD_GetMonitorState() == EN_OAD_MONITOR_STATE_DSI_INIT)
            {
                #if (BLOADER)
                while(1)
                {
                    EN_OAD_MONITOR_STATE curr_state = MApp_OAD_GetMonitorState();
                    if((curr_state == EN_OAD_MONITOR_STATE_STOP) ||
                        (curr_state == EN_OAD_MONITOR_STATE_NONE))
                    {
                        break;
                    }
                    MApp_OAD_Monitor();
                    MsOS_DelayTask(25);
                    if(curr_state == EN_OAD_MONITOR_STATE_DSI_SIGNAL) //done
                    {
                        MApp_Dmx_SetOADScanMode(FALSE);
                        enOADScanState = STATE_OAD_SCAN_END;
                        break;
                    }
                }
                #else //(BLOADER)
                // Found OAD information, stop tuning.
                //printf("Found OAD Information\n");
                MApp_Dmx_SetOADScanMode(FALSE);
                enOADScanState = STATE_OAD_SCAN_END;
                #endif //(BLOADER)
            }
            break;
            default:
                break;
    }
    if(enOADScanState == STATE_OAD_SCAN_END)
    {
        MApp_Dmx_SetOADScanMode(FALSE);
        MApp_DTV_Scan_End(FALSE);

        #if (!BLOADER)
        if ( !IsSrcTypeDTV( SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW) ) )
        {
            msAPI_Tuner_Set_DemodPower(DISABLE);
        }
        #endif //(!BLOADER)
    }
    return enOADScanState;
}
#endif
#else
static void MApp_OAD_Scan_ProcessUserInput( void )
{
    switch ( u8KeyCode )
    {
        case KEY_POWER:
        case DSC_KEY_PWROFF:
        {
           u8KeyCode = KEY_POWER;
           MApp_ZUI_ProcessKey(u8KeyCode);
        }
        break;

        case KEY_EXIT:
        case KEY_MENU:
        {
            u8KeyCode = KEY_EXIT;
            MApp_OAD_SetScanState(STATE_OAD_SCAN_EXIT);
            MApp_ZUI_ProcessKey(u8KeyCode);
        }
        break;

        default:
            break;
    }
    u8KeyCode = KEY_NULL;
}

EN_RET MApp_OAD_Scan( U8* percentage )
{
    BOOLEAN ScanResult;
    EN_RET bReturnVal = EXIT_NULL;
    BOOLEAN bFound_SSU = FALSE;

    MApp_OAD_Scan_ProcessUserInput();
    switch( enOADScanState )
    {
        case STATE_OAD_SCAN_INIT:
            OAD_DEBUG( printf("STATE_OAD_SCAN_INIT\n") );
            *percentage = 0;
            MApp_Scan_State_Init();
            MApp_Dmx_GetScanTableStateInit();
            bFound_SSU = FALSE;
            if ( MApp_DTV_Scan_Init() == TRUE )
            {
                g_enScanType = SCAN_TYPE_AUTO;
                if(msAPI_CM_GetCountry() == E_NORWAY || msAPI_CM_GetCountry() == E_SWEDEN)
                {
                    msAPI_DFT_SetBandwidth(stGenSetting.stScanMenuSetting.u8BandWidth);
                }
                u8OadRFCh = msAPI_DFT_GetFirstPhysicalChannelNumber();
                msAPI_DFT_GetTSSetting( u8OadRFCh, &stOadTPSetting);
                MApp_OAD_SetScanState(STATE_OAD_SCAN_SEARCH_RF_CHANNEL);
            }
            else
            {
                /* allocate memory failure, maybe need to display warning msg. here */
                MApp_OAD_SetScanState(STATE_OAD_SCAN_END);
            }
            MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_REPAINT_OAD_SCAN);
            break;

        case STATE_OAD_SCAN_NEXT_CHANNEL:
            {
                u8OadRFCh = msAPI_DFT_GetNextPhysicalChannelNumber(u8OadRFCh);
                OAD_DEBUG(printf("u8OadRFCh  %bu\n",u8OadRFCh));
                if(u8OadRFCh == INVALID_PHYSICAL_CHANNEL_NUMBER/*u8MaxRFCh*/ )
                {
                    MApp_OAD_SetScanState(STATE_OAD_SCAN_END);
                    OAD_DEBUG( printf("No found SSU\n") );
                #if (!BLOADER)
                    MApp_ZUI_ACT_ShutdownOSD();
                    MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
                #endif
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_NO_OAD_AVAILABLE);
                    break;
                }
                MApp_OAD_SetScanState(STATE_OAD_SCAN_SEARCH_RF_CHANNEL);
                msAPI_DFT_GetTSSetting( u8OadRFCh, &stOadTPSetting);
                *percentage = msAPI_DFT_GetPercentWithPhysicalChannelNumber(u8OadRFCh);

                if (*percentage==100)
                {
                #if (!BLOADER)
                    MApp_ZUI_ACT_ShutdownOSD();
                    MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
                #endif
                    MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_NO_OAD_AVAILABLE);
                    MApp_OAD_SetScanState(STATE_OAD_SCAN_END);
                }
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_REPAINT_OAD_SCAN);
                MApp_OAD_Init();
                break;
            }

        case STATE_OAD_SCAN_SEARCH_RF_CHANNEL:
            //wNetworkID = INVALID_ON_ID;
            if ( MApp_DVB_Scan(&stOadTPSetting, &ScanResult) == FALSE )
            {
                break;
            }

            if ( ScanResult == FE_LOCK )
            {
                MApp_OAD_SetScanState(STATE_OAD_SCAN_PATPMT_MONITOR);
            }
            else
            {
                MApp_OAD_SetScanState(STATE_OAD_SCAN_NEXT_CHANNEL);
            }

            break;

        case STATE_OAD_SCAN_PATPMT_MONITOR:
            MApp_Dmx_DisableTableMonitor();
            MApp_SI_ResetPATMonitor();
            MApp_Dmx_SetOADScanMode(TRUE);
            _bDVB_OUI_Enable = TRUE;
            _bCheck_NIT_First = FALSE;
            _PMT_Ready = FALSE;
            //u32OadScanWaitTableTimer = msAPI_Timer_GetTime0();
            MApp_OAD_SetScanState(STATE_OAD_SCAN_WAIT_OAD_MONITOR);
            break;

        case STATE_OAD_SCAN_WAIT_PATPMT_MONITOR:
            MApp_SI_Table_Monitor();
            if(!MApp_Dmx_GetOADScanMode() || msAPI_Timer_DiffTimeFromNow(u32OadScanWaitTableTimer) >= (OAD_SCAN_WAIT_TABLE_TIME/2))
            {
                MApp_Dmx_SetOADScanMode(FALSE);
                MApp_OAD_SetScanState(STATE_OAD_SCAN_NEXT_CHANNEL);
            }
            if(MApp_OAD_GetMonitorState() == EN_OAD_MONITOR_STATE_DSI_INIT)
            {
                MApp_OAD_SetScanState(STATE_OAD_SCAN_WAIT_OAD_MONITOR);
                u32OadScanWaitTableTimer = 0;
            }
            break;
        case STATE_OAD_SCAN_WAIT_OAD_MONITOR:
            {
            #if 0
                if(MApp_OAD_GetMonitorState()== EN_OAD_MONITOR_STATE_PMT_SID_RECEINING)
                {
                    enOADScanState = STATE_OAD_SCAN_PATPMT_MONITOR;
                    u32OadScanWaitTableTimer = msAPI_Timer_GetTime0();
                    break;
                }
            #endif
                if((MApp_OAD_GetMonitorState()== EN_OAD_MONITOR_STATE_PMT_SID_RECEINING)
                    || (MApp_OAD_GetMonitorState()==EN_OAD_MONITOR_STATE_PMT_DBID_RECEINING)
                    || (MApp_OAD_GetMonitorState()==EN_OAD_MONITOR_STATE_UNT_CHECK_SCHEDULE))
                {
                    MApp_SI_Table_Monitor();
                }
                MApp_OAD_Monitor();
            }
            break;
        case STATE_OAD_SCAN_SSU_FOUND_OR_SCHEDULE:
            {
                if((MApp_OAD_GetMonitorState() == EN_OAD_MONITOR_STATE_DSI_SIGNAL) ||
                    (MApp_OAD_GetMonitorState()== EN_OAD_MONITOR_STATE_UNT_WAIT_SCHEDULE))
                {
                    enOADScanState=STATE_OAD_SCAN_END;
                    bFound_SSU = TRUE;
                    OAD_DEBUG( printf("MApp_OAD_Scan: found new version or schedule at RF=%d.\n", u8OadRFCh) );
                }
            }
            break;
        case STATE_OAD_SCAN_EXIT:
            {
                MApp_OAD_SetScanState(STATE_OAD_SCAN_END);
            }
            break;
        default:
            break;
    }
    if(enOADScanState == STATE_OAD_SCAN_END)
    {
        bReturnVal=EXIT_GOTO_CHANNELCHANGE;
        MApp_DTV_Scan_End(FALSE);
        MApp_Dmx_SetOADScanMode(FALSE);
        g_enScanType = (EN_SCAN_TYPE) stGenSetting.stScanMenuSetting.u8ScanType;
        _bOadScanCheck = FALSE;
        bShowOadScanPage = FALSE;
        msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_INTERNAL_2_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);

        if(bFound_SSU == TRUE)
        {
            if((msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO)+ msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO)+msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO))>0)
            {
                if(MApp_OAD_GetMonitorState()== EN_OAD_MONITOR_STATE_UNT_WAIT_SCHEDULE)
                {
                    _bDisplayScheduleMsg = TRUE;
                    //printf("\r\n -> MApp_OAD_Scan[%d]: Switch back to the previous service with ts_id=0x%X, on_id=0x%X, sid=0x%X.\n", __LINE__, wPrev_TSID, wPrev_ONID, wPrev_SID);
                    // Switch back to the previous service which is viewed by user before OAD Scan starts.
                    MApp_OAD_ChannelChange(wPrev_TSID, wPrev_ONID, wPrev_SID);
                }
            }
            else
            {
                if(MApp_OAD_GetMonitorState()== EN_OAD_MONITOR_STATE_UNT_WAIT_SCHEDULE)
                {
                    MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_STOP);
                }
            }
            MApp_OAD_SetAppState(EN_OAD_APP_STATE_INIT);
        }
        else
        {
            MApp_OAD_SetMonitorState(EN_OAD_MONITOR_STATE_STOP);
        }
        u8OadRFCh = msAPI_DFT_GetFirstPhysicalChannelNumber();

        MApp_OAD_SetScanState(STATE_OAD_SCAN_INIT);
    }
    return bReturnVal;
}

#endif

BOOLEAN MApp_OAD_GetSignalForStandby(void)//david123
{
    return _bSignalForStandby;
}

void MApp_OAD_StandbyUpdate()
{
// For NZ OAD start
    if(OSD_COUNTRY_SETTING == OSD_COUNTRY_NEWZEALAND)
    {
        if(_bSignalForStandby == TRUE)
        {
            MApp_OAD_SetMonitorState(_stOADSignalForStandby.enNextMonitorState);
            wOad_PID = _stOADSignalForStandby.PID;
            bServiceType = _stOADSignalForStandby.bServiceType;
            wCurrentPosition = _stOADSignalForStandby.wCurrentPosition;
            wOriginalNetwork_ID_OAD = _stOADSignalForStandby.wOriginalNetwork_ID_OAD;
            wTransportStream_ID_OAD = _stOADSignalForStandby.wTransportStream_ID_OAD;
            wService_ID_OAD = _stOADSignalForStandby.wService_ID_OAD;
            OAD_DEBUG( printf("MApp_OAD_StandbyUpdate[%d]: tsid=0x%X, onid=0x%X, sid=0x%X.\n", __LINE__, wTransportStream_ID_OAD, wOriginalNetwork_ID_OAD, wService_ID_OAD) );
            MApp_OAD_SetAppState(EN_OAD_APP_STATE_YES);
        }
    }
// For NZ OAD end
}

void MApp_OAD_StandbyReceivePowerKey()
{
// For NZ OAD start
    if(OSD_COUNTRY_SETTING == OSD_COUNTRY_NEWZEALAND)
    {
        printf("System reset!\n");
        MDrv_Sys_WholeChipReset();
    }
// For NZ OAD end
}

static BOOLEAN MApp_OAD_ChannelChange(U16 u16TSID, U16 u16ONID, U16 u16SID)
{
#if (!BLOADER)
    MEMBER_SERVICETYPE eGotServiceType;
    WORD u16GotPosition;

    if((msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO)+ msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO)+msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO))>0)
    {
        if(TRUE == msAPI_CM_GetServiceTypeAndPositionWithIDs( u16TSID, u16ONID, u16SID, 1, &eGotServiceType, &u16GotPosition, TRUE))
        {
            if(eGotServiceType != msAPI_CM_GetCurrentServiceType() || u16GotPosition != msAPI_CM_GetCurrentPosition(msAPI_CM_GetCurrentServiceType()))
            {
                wPrev_TSID = msAPI_CM_GetTS_ID(msAPI_CM_GetCurrentServiceType(), msAPI_CM_GetCurrentPosition(msAPI_CM_GetCurrentServiceType()));
                wPrev_ONID = msAPI_CM_GetON_ID(msAPI_CM_GetCurrentServiceType(), msAPI_CM_GetCurrentPosition(msAPI_CM_GetCurrentServiceType()));
                wPrev_SID = msAPI_CM_GetService_ID(msAPI_CM_GetCurrentServiceType(), msAPI_CM_GetCurrentPosition(msAPI_CM_GetCurrentServiceType()));

                msAPI_CM_SetCurrentServiceType(eGotServiceType);
                msAPI_CM_SetCurrentPosition( eGotServiceType, u16GotPosition);
            }
            printf("\r\n >>>>>>> MApp_OAD_ChannelChange[%d]: tsid=0x%X, onid=0x%X, sid=0x%X.\n", __LINE__, u16TSID, u16ONID, u16SID);
            MApp_ChannelChange_DisableChannel(TRUE, MAIN_WINDOW);
            MApp_ChannelChange_EnableChannel(MAIN_WINDOW);
            return TRUE;
        }
    }

    return FALSE;
#else
    UNUSED(u16TSID);
    UNUSED(u16ONID);
    UNUSED(u16SID);
    return TRUE;
#endif
}


#if  1
LPTSTR MApp_OAD_GetOadRfChannel(void)
{
#if ENABLE_DTV
    if(IsDTVInUse())
    {
        U8 RFChannelName[4];
        U8 u8_idx;
        LPTSTR str = CHAR_BUFFER;
        str[0] = 0;
        u8_idx = 0;

        if(MApp_TopStateMachine_GetTopState() == STATE_TOP_DTV_SCAN)
        {
        #if ENABLE_DVBC
          #if 1//ENABLE_T_C_COMBO
            if(!IsDVBCInUse())
            {
                if(TRUE == msAPI_DFT_GetPhysicalChannelName(u8OadRFCh, RFChannelName,4))
                {
                    str[u8_idx++] = (U16)RFChannelName[0];
                    str[u8_idx++] = (U16)RFChannelName[1];
                    str[u8_idx++] = (U16)RFChannelName[2];
                    str[u8_idx++] = (U16)RFChannelName[3];
                    str[u8_idx++] = 0;
                }
            }
            else
          #endif
            {
            #if !ENABLE_SCAN_ONELINE_MSG
                printf("tTPSetting.u32Frequency = %ld\n", stTPSetting.u32Frequency);
            #endif
                U32 tmp_integer = stTPSetting.u32Frequency / 1000;
                U32 tmp_fraction = stTPSetting.u32Frequency % 1000;

                str[u8_idx++] = ((tmp_integer/100) == 0) ? ' ' : '0'+(tmp_integer/100);
                str[u8_idx++] = '0'+((tmp_integer%100)/10);
                str[u8_idx++] = '0'+(tmp_integer%10);
                str[u8_idx++] = '.';
                str[u8_idx++] = '0'+(tmp_fraction/100);
                str[u8_idx++] = 0;

            }
        #else
            if(TRUE == msAPI_DFT_GetPhysicalChannelName(u8OadRFCh, RFChannelName,4))
            {
                str[u8_idx++] = (U16)RFChannelName[0];
                str[u8_idx++] = (U16)RFChannelName[1];
                str[u8_idx++] = (U16)RFChannelName[2];
                str[u8_idx++] = (U16)RFChannelName[3];
                str[u8_idx++] = 0;

            }
        #endif
         }
         return CHAR_BUFFER;
    }
    else
#endif
    {
        CHAR_BUFFER[0]=0;
        return CHAR_BUFFER;
    }
}

#else
U8 MApp_OAD_GetOadRfChannel(void)
{
    return u8OadRFCh;
}
#endif



#else
//static code U8 u8Dummy;
#endif //ENABLE_OAD

#undef _MAPP_OAD_C_
