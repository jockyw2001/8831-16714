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

#ifndef MAPP_DEMUX_H
#define MAPP_DEMUX_H

#if(ENABLE_DTV)
//#include "msAPI_demux.h"

//#define ENABLE_ASTRA_HD   1
#ifndef ENABLE_ASTRA_HD
#define ENABLE_ASTRA_HD   0
#endif

#ifndef ASTRA_HD_ENABLE
    #define ASTRA_HD_ENABLE ENABLE_ASTRA_HD
#endif

/******************************************************************************/
/*                                 Macro                                      */
/******************************************************************************/

#define INVALID_VERSION_NUM         0xFF
#define PARENTAL_RATE_SHIFT 3

#define DMX_MAX_MUX_NUMBER          40
/*****************************************************************************/
/*                         Functions                                         */
/*****************************************************************************/
// demux helper functions
#define TSGetBitFromU8(ptr, bitn)           (((*(U8 *)ptr) >> bitn) & 0x01)
#define TSGetBitsFromU8(ptr, lsb, mask)     (((*(U8 *)ptr) >> lsb) & mask)
//#define TSGetU16(ptr)                       (*((U16 *)ptr))
#define TSGetU16(ptr)                       ((((U8 *)ptr)[0] << 8) + ((U8 *)ptr)[1])
#define TSGetBitsFromU16(ptr, lsb, mask)    ((TSGetU16(ptr) >> lsb) & mask)
//#define TSGetU32(ptr)                       (*((U32 *)ptr))
#define TSGetU32(ptr)                       ((((U8 *)ptr)[0] << 24) + (((U8 *)ptr)[1] << 16) + (((U8 *)ptr)[2] << 8) + (((U8 *)ptr)[3] << 0))
#define TSGetBitsFromU32(ptr, lsb, mask)    ((TSGetU32(ptr) >> lsb) & mask)

/******************************************************************************/
/*                                 Enum                                       */
/******************************************************************************/

/* PID definition */
typedef enum
{
    // MPEG-2 PID
    PID_PAT         = 0x0000,
    PID_CAT         = 0x0001,
    PID_TSDT        = 0x0002,
  //PID_reserved    = 0x0003 ~ 0x000F

    // PSIP PID [ATSC only]
    PID_BASE        = 0x1FFB,           // todo: remove?

    // DVB-T SI PID
    PID_NIT         = 0x0010,           // NIT / ST
    PID_SDT_BAT     = 0x0011,           // SDT / BAT / ST
    PID_EIT_CIT     = 0x0012,           // EIT / SE / CIT (TS 102 323 [36])
    PID_RST         = 0x0013,           // RST / ST
    PID_TDT_TOT     = 0x0014,           // TDT / TOT / ST
  //PID_NSYNC       = 0x0015,
  //PID_RNT         = 0x0016,           // RNT (TS 102 323 [36] TV Anytime over DVB)
  //PID_INBAND_SGNL = 0x001c,           // inband signaling
  //PID_MEASUREMENT = 0x001d,           // measurement
    PID_DIT         = 0x001e,
    PID_SIT         = 0x001f,

} EN_PSIP_PID;


/* PSIP Table */
typedef enum
{
    EN_MONITOR_TABLE_ALL,
    EN_MONITOR_PAT,
    EN_MONITOR_PMT,
    EN_MONITOR_PMT_OTHER,
    EN_MONITOR_SDT,
    EN_MONITOR_SDT_OTHER,
    EN_MONITOR_NIT,
    EN_MONITOR_PF_EIT,
    EN_MONITOR_PF_EIT_ALL,
    EN_MONITOR_TDT,
    EN_MONITOR_TOT,
    EN_MONITOR_CI_TUNE,

#if (ASTRA_HD_ENABLE)
    EN_MONITOR_SGT,
#endif  //#if (ASTRA_HD_ENABLE)

} EN_MONITOR_TABLE;

/* A/V/PCR/TTX/SUBT */
typedef enum
{
    EN_AUDIO_FID,
    EN_VIDEO_FID,
    EN_PCR_FID,
    EN_AD_FID,
    EN_TTX_FID,
    EN_PES_FID,
    EN_OAD_MONITOR_FID,
    EN_OAD_DOWNLOAD_FID
} EN_FID;


typedef enum
{
    DMX_QUICK_INSTALL_RET_STATE_NONE,
    DMX_QUICK_INSTALL_RET_STATE_UPDATE_CHLIST,
    DMX_QUICK_INSTALL_RET_STATE_REMOVE_MISSING_MUX,
    DMX_QUICK_INSTALL_RET_STATE_END
}DMX_DVBC_QUICK_INSTALL_RET_STATE;
/*****************************************************************************/
/*                              Structures                                   */
/*****************************************************************************/
typedef struct
{
    U32 bUpdateMuxOnly:             1;
    U32 bParseNITOther:             1;
    U32 bNetworkIDFilterEn:           1;
    U32 bNetworkID:                     16;
    U32 bEnableNITQuickScan:            11;
    U32 reserved:                       12;
}SCAN_TABLE_CONFIG;

typedef struct
{
    void (*pfNotify_OAD_Init)(void);
}MS_DMX_NOTIFY;
/******************************************************************************/
/*                       Global Variable Declarations                         */
/******************************************************************************/
#ifdef MAPP_DEMUX_C
#define INTERFACE
#else
#define INTERFACE extern
#endif

//INTERFACE U16       u8TTXFid;
/******************************************************************************/
/*                       Global Function Prototypes                           */
/******************************************************************************/
//(1) system interface
INTERFACE void MApp_Dmx_EnableTableMonitor(void);
INTERFACE void MApp_Dmx_DisableTableMonitor(void);
INTERFACE void MApp_Dmx_EnableFileInMonitor(void);
INTERFACE void MApp_Dmx_DisableFileInMonitor(void);
INTERFACE void MApp_Dmx_CloseAllFilters(void);


INTERFACE BOOLEAN MApp_Dmx_GetMonitorStatus(EN_MONITOR_TABLE eTable);
INTERFACE void MApp_Dmx_SetMonitorStatus(BOOLEAN bStatus, EN_MONITOR_TABLE eTable);
//(4) EPG functions
INTERFACE U8 MApp_Dmx_EIT_Get_CurPfVer(void);
INTERFACE void MApp_Dmx_EIT_Set_CurPfVer(U8 u8EitCurPfVer);
INTERFACE void MApp_Dmx_EIT_Set_PfMonitor_Status(BOOLEAN bEitPfMonitor);
INTERFACE void MApp_Dmx_EIT_Init_ChangeLanguage(void);
INTERFACE void MApp_Dmx_EIT_Proc(U32 u32PollingMs);


//(5) SUBTITLE functions
INTERFACE void MApp_Dmx_PES_Monitor(U16 u16PID, void *pfNotify, BOOLEAN bFileIn);
INTERFACE void MApp_Dmx_PES_Stop(void);
INTERFACE void MApp_Dmx_PES_Restart(void);

//(6) Fid function
INTERFACE U8 *MApp_Dmx_GetFid(EN_FID eFid);
INTERFACE void MApp_Dmx_SetFid(U8 u8Fid, EN_FID eFid);

//(7) Misc
#if ENABLE_SDT_OTHER_MONITOR
INTERFACE void MApp_Dmx_Disable_Reset_Filter(void);
#endif
INTERFACE void MApp_Dmx_SetReset_EventInfo_status(BOOLEAN bStatus);
INTERFACE BOOLEAN MApp_Dmx_GetScanTables(SCAN_TABLE_CONFIG *stScanConfig, U8 *u8FoundNum);
#if(ASTRA_HD_ENABLE)
INTERFACE BOOLEAN MApp_Dmx_AstraHD_GetScanTables(SCAN_TABLE_CONFIG *stScanConfig, U8 *u8FoundNum);
#endif  // #if(ASTRA_HD_ENABLE)
INTERFACE BOOLEAN MApp_Dmx_GetSDTScanTables(U16 u16TSID, BOOLEAN* bGotSDT, U32 u32WaitTime);
#if 1//ENABLE_DVBC
INTERFACE BOOLEAN MApp_Dmx_GetAllNetwork(U32 u32TimeOut);
INTERFACE void MApp_Dmx_Enable_NIT_Other(BOOLEAN bEnable);
#endif
INTERFACE void MApp_Dmx_GetScanTableStateInit(void);
INTERFACE void MApp_Dmx_DVBC_QuickInstallStateInit(void);
INTERFACE void MApp_Dmx_DVBC_QuickInstallGetTsIDs(U16 *pu16TsIDs, U8 *pu8TsIdCount, U8 u8MaxPoolLen);
INTERFACE DMX_DVBC_QUICK_INSTALL_RET_STATE MApp_Dmx_DVBC_QuickInstallScanTables(void);
INTERFACE U8 * MApp_Dmx_GetSI4KSectionBuffer(void);
INTERFACE void MApp_Dmx_Init_OAD(MS_DMX_NOTIFY* psNotify);
INTERFACE void MApp_Dmx_SetCITuneServiceId(U16 u16ServiceId);
INTERFACE U16 MApp_Dmx_GetCITuneServiceId(void);
#if ENABLE_OAD
INTERFACE BOOLEAN MApp_Dmx_Get_IsAllPmtReady(void);
INTERFACE void MApp_Dmx_ResetAllPmtReady(void);
#endif
#undef INTERFACE
#endif//#if(ENABLE_DTV)
#endif
