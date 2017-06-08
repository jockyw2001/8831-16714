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
/// file    msAPI_CEC.c
/// @author MStar Semiconductor Inc.
/// @brief  HDMI CEC API Interface
///////////////////////////////////////////////////////////////////////////////////////////////////


//-------------------------------------------------------------------------------------------------
//  Include Files
//-------------------------------------------------------------------------------------------------
#include "Board.h"			//Ray CEC 2017.04.05: Include this as we direct compile this file
#include "datatype.h"
#include "MsCommon.h"
#include <string.h>
#include "stdio.h"

#if ENABLE_CEC

#define _MSAPICEC_C_
#include "drvGlobal.h"
#include "apiXC.h"
#include "apiXC_Adc.h"
#include "MApp_GlobalSettingSt.h"
#include "msAPI_OSD.h"
#include "apiCEC.h"
#include "msAPI_CEC.h"
#include "msIR.h"
#include "MApp_Key.h"
#include "apiPNL.h"
#include "Panel.h"
#include "MApp_GlobalVar.h"
#include "MApp_InputSource.h"
#include "MApp_ZUI_Main.h"
#include "ZUI_exefunc.h"
#include "msAPI_Tuning.h"
#include "drvPM.h"
#include "MApp_Audio.h"
#include "MApp_ZUI_ACTglobal.h"
#include "msAPI_audio.h"
#ifdef ENABLE_DMP
#include "mapp_mplayer.h"
#include "MApp_TopStateMachine.h"
#include "MApp_ChannelChange.h"
#endif
#include "msAPI_Timer.h"
#include "drvGPIO.h"

#include "MApp_GlobalFunction.h"

#include "msAPI_CEC_StateMachine.h"
#include "MApp_ZUI_ACTcoexistWin.h"
#include "MApp_ZUI_ACTinputsource.h"

#include "ZUI_tables_h.inl"
#if ENABLE_PVR
#include "MApp_PVR.h"
#endif

#if ENABLE_DMP
#include "MApp_DMP_Main.h"
#endif

//-------------------------------------------------------------------------------------------------
//  Local Defines
//-------------------------------------------------------------------------------------------------

#define CEC_PORT1   0x10    //HDMI 1
#define CEC_PORT2   0x20    //HDMI 2
#define CEC_PORT3   0x30    //HDMI 3
#define CEC_PORT4   0x40    //HDMI 4


#define CEC_DEBUG                           FALSE//TRUE//FALSE
#if CEC_DEBUG
    #define CEC_MSG(x)                      x
    #define CEC_DPUTSTR(str)                printf(str)
    #define CEC_DPRINTF(str, x)             printf(str, x)
    #define CEC_ERROR_DEBUG(str, x)         printf(str, x)
    #define CEC_POSTMSG_DEBUG(x)            x
    #define CEC_POSTMSG_ERROR_DEBUG(x)      x
    #define CEC_POLLING_MSG_DBG(x)          x
#else
    #define CEC_MSG(x)                      //x
    #define CEC_DPUTSTR(str)                //printf(str)
    #define CEC_DPRINTF(str, x)             //printf(str, x)
    #define CEC_ERROR_DEBUG(str, x)         //printf(str, x)
    #define CEC_POSTMSG_DEBUG(x)            //x
    #define CEC_POSTMSG_ERROR_DEBUG(x)      //x
    #define CEC_POLLING_MSG_DBG(x)          //x
#endif



// CEC function catalog
#define ONE_TOUCH_PLAY_SUPPORT                  1 // TV, CEC switches
#define ROUTING_CONTROL_SUPPORT                 1 // TV, CEC switches
#define STANDBY_COMMAND_SUPPORT                 1 // All
#define ONE_TOUCH_RECORD_SUPPORT                0 // Recording devices
#define TIMER_PROGRAMMER_SUPPORT                0 //
#define SYSTEM_INFORMATION_SUPPORT              1 // All
#define DECK_CONTROL_SUPPORT                    1
#define TUNER_CONTROL_SUPPORT                   0
#define VENDOR_SPECIFIC_SUPPORT                 1 // All
#define OSD_DISPLAY_SUPPORT                     0
#define DEVICE_OSD_NAME_TRANSFER_SUPPORT        1 //anvi cec
#define DEVICE_MENU_CONTROL_SUPPORT             1
#define REMOTE_CONTROL_PASSTHROUGH_SUPPORT      1
#define POWER_STATUS_SUPPORT                    1 // All except CEC switches
#define SYSTEM_AUDIO_CONTROL_SUPPORT            1
#define GENERAL_PROTOCAL_SUPPORT                1 // All
#define AUDIO_RETURN_CHANNEL_SUPPORT            1

//-------------------------------------------------------------------------------------------------
//  Local Structures
//-------------------------------------------------------------------------------------------------

static MS_U8 u8VendorID_MST[3]    = {0x4D, 0x53, 0x54};

//-------------------------------------------------------------------------------------------------
//  Global Variables
//-------------------------------------------------------------------------------------------------

CECWAKEUPCMD gCecWakeupCmd;
//-------------------------------------------------------------------------------------------------
//  Local Variables
//-------------------------------------------------------------------------------------------------

static BOOLEAN gCECInitDone = FALSE;

static CECMSGQUEUE  _stCecMsgQueue;

static MSAPI_CEC_INFO_LIST _stMsApiCecInfoList;

static EN_CEC_POLLING_STATUS _bStartPolling = STATUS_POLLING_IDLE;
static U32 _u32CecDeviceMonitorTimer = 0;

BOOLEAN g_bCecForceImmediatelyPolling = FALSE;

#if DECK_CONTROL_SUPPORT
MsCEC_MSG_DC_DECK_STATUS_PARM gCECDeckStatus = (MsCEC_MSG_DC_DECK_STATUS_PARM) 0xFF;
#endif

BOOLEAN bDuringChannelChange = 0;

// TO DO.  are all of those variables necessary?
BOOLEAN gCECRecordEnable = FALSE;
BOOLEAN gCECUserControlEnable;
//MS_U8 gCECOSDStr[40];
BOOLEAN gCECQueryPowerFlag = FALSE;

#define StartReportPowerOnConunt    10
MS_U8 u8ReportCECPowerStatusCount = 0;
MS_BOOL bCECReportPowerStatusAtBootingUp = TRUE;

static U8 u8CECAmpControlVolume = 0;
static BOOLEAN bSystemAudioMode = FALSE;

static BOOLEAN gIsCECAmpARCOn = FALSE;
static MS_U8 ARCAudioVolume = 0;
static BOOLEAN ARCAMPIsMute = FALSE;
#define CEC_ARC_PA (0x1000*ARC_SUPPORT_PORT)    //correct physical address for ARC port
//-------------------------------------------------------------------------------------------------
//  External Variables
//-------------------------------------------------------------------------------------------------

extern E_OSD_ID _eActiveOSD;

//-------------------------------------------------------------------------------------------------
//  external Functions
//-------------------------------------------------------------------------------------------------

#if defined(MIPS_CHAKRA)
extern void MsOS_DelayTask(U32 u32milisec);
#endif

extern BOOLEAN MApp_UiMenu_IsCountDownWinShow(void);

#if 1   // drv layer in utopia
extern void MDrv_CEC_Init(MS_U32 u32XTAL_CLK_Hz);
extern void MDrv_CEC_ConfigWakeupInfoVendorID(MS_U8* u8CecVendorID);
extern void MDrv_CEC_SetRetryCount(MS_U8 u8RetryCount);
#endif

//-------------------------------------------------------------------------------------------------
//  Local Functions prototype
//-------------------------------------------------------------------------------------------------
static void msAPI_CEC_RemoveDevice(MsCEC_DEVICELA enDevice);
MS_U8 msAPI_CEC_DeviceRecognition1_Ping(MS_BOOL bCecDevices1[E_LA_MAX]);
void msAPI_CEC_DeviceRecognition_GivePhysicalAddress(MS_BOOL bCecDevices2[E_LA_MAX]);
void msAPI_CEC_DeviceRecognition_GiveDevicePowerStatus(MS_BOOL bCecDevices2[E_LA_MAX]);
//-------------------------------------------------------------------------------------------------
//  external Files
//-------------------------------------------------------------------------------------------------

#include "msAPI_CEC_StateMachine.c"
#include "msAPI_CEC_PostMsg.c"
#include "msAPI_CEC_Customer.c"

//-------------------------------------------------------------------------------------------------
//  Local Functions
//-------------------------------------------------------------------------------------------------
void msAPI_CEC_GetDeviceInfo(void)
{
    U8 i= 0, j= 0;

    for (i= E_LA_TV; i< E_LA_MAX; i++)
    {
        if(msAPI_CEC_IsDeviceExist((MsCEC_DEVICELA)i))
        {
            g_stMenuCecDeviceList.aenDeviceLA[j]= (MsCEC_DEVICELA)i;
            strcpy((char *)g_stMenuCecDeviceList.au8CecDeviceName[j] ,(char *)msAPI_CEC_GetDeviceName((MsCEC_DEVICELA)i));
            g_stMenuCecDeviceList.u8CECDeviceNum++;
            g_stMenuCecDeviceList.wPhyAddr[j]= msAPI_CEC_GetDeviceIdx_PhyAddr((MsCEC_DEVICELA)i);
            j++;
        }
    }
}

U8 msAPI_CEC_QueryAudioStatusValue(void)
{
    return u8CECAmpControlVolume;
}

void msAPI_CEC_SetSystemAudioMode(BOOLEAN bMode)
{
    bSystemAudioMode = bMode;
}

BOOLEAN msAPI_CEC_QuerySystemAudioMode(void)
{
    return bSystemAudioMode;
}

void msAPI_CEC_SaveAmpControlVolume(U8 _u8CECAmpControlVolume)
{
    u8CECAmpControlVolume = _u8CECAmpControlVolume;
}

U8 msAPI_CEC_QueryAmpVolumeValue(void)
{
    return (msAPI_CEC_QueryAudioStatusValue()& 0x7F);
}

BOOLEAN msAPI_CEC_IsAudioSystemKeyValid(void)
{
    /*
    Audio system key valid condition as below

    1) TV speaker = CEC
    2) CEC switch = ON
    3) Already connect an audio device
    4) System audio mode = ON
    */
    if(stGenSetting.g_SoundSetting.TVspeakerMode == TVspeaker_Mode_ExtAmp
        && DB_HDMI_SETTING.g_bHdmiCecMode == ENABLE
        && msAPI_CEC_IsDeviceExist(E_LA_AUDIO_SYS) == TRUE
        && (msAPI_CEC_QuerySystemAudioMode() == TRUE)
    )
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//**************************************************************************
//  [Function Name]:
//                   MApp_CEC_ARC_GetARCAudioVolume()
//  [Description]
//                  Get ARC AudioVolume
//  [Arguments]:
//
//  [Return]:
//               MS_U8
//**************************************************************************

MS_U8 MApp_CEC_ARC_GetARCAudioVolume(void)  //anvi22
{
    return ARCAudioVolume;
}

//**************************************************************************
//  [Function Name]:
//                   MApp_CEC_ARC_SetAmpMute()
//  [Description]
//                   Set ARC Amp mute status
//  [Arguments]:
//
//  [Return]:
//               void
//**************************************************************************

void  MApp_CEC_ARC_SetAmpMute(BOOLEAN isMute)  //anvi22
{
    ARCAMPIsMute = isMute;
}

//**************************************************************************
//  [Function Name]:
//                   MApp_CEC_ARC_AmpIsMute()
//  [Description]
//                  Get ARC Amp mute status
//  [Arguments]:
//
//  [Return]:
//               BOOLEAN
//**************************************************************************

BOOLEAN MApp_CEC_ARC_GetAmpMute(void)  //anvi22
{
    return ARCAMPIsMute;
}

//**************************************************************************
//  [Function Name]:
//                   MsAPI_IsCECByPass()
//  [Description]
//                   Bypass CEC Cmd
//  [Arguments]:
//                   none
//  [Return]:
//                   none
//@20090212 by hansen.chen
//**************************************************************************
BOOLEAN msAPI_CEC_IsByPass(void)
{
    if (  msAPI_Tuner_IsTuningProcessorBusy()
       || (MApp_ZUI_GetActiveOSD() == E_OSD_AUTO_TUNING)    //by pass atuo tunning tv
      #if ENABLE_ATSC
       || (MApp_TopStateMachine_GetTopState() == STATE_TOP_SCAN)
      #endif
       )
    {
        return TRUE;
    }

#if ENABLE_PVR
    enPVRState PVRState = MApp_PVR_StateMachineGet();

    if (  (PVRState == E_PVR_STATE_TIMESHIFT)
       || (PVRState == E_PVR_STATE_RECORD)
       || (PVRState == E_PVR_STATE_PLAYBACK)
       || (PVRState == E_PVR_STATE_RECORDnPLAYBACK)
       )
    {
        return TRUE;
    }
#endif

    if (bDuringChannelChange)
    {
        return TRUE;
    }

    return FALSE;
}

//***************************************************************************************
void msAPI_CEC_SetDeviceName(MS_U8 u8Device, MS_U8* pName, MS_BOOL bIsDefault)
{
    if (bIsDefault)
    {
        msAPI_CEC_LoadDefaultDeviceName(stGenSetting.g_SysSetting.Language);
    }
    else
    {
        U8 len = strlen((char *)pName); // Mantis 0894728 fixed
        _stMsApiCecInfoList.u8CecDeviceName[u8Device][len] = 0;
        strncpy((char *)_stMsApiCecInfoList.u8CecDeviceName[u8Device], (char *)pName, len);
    }
}

//***************************************************************************************
MS_BOOL msAPI_CEC_IsDeviceExist(MsCEC_DEVICELA enDevice)
{
    return _stMsApiCecInfoList.bCecDevicesExisted[enDevice];
}

//***************************************************************************************

MS_U8 msAPI_CEC_GetDeviceTotalNum(void)
{
    return _stMsApiCecInfoList.u8CecDeviceCount;
}

//***************************************************************************************

MS_U8* msAPI_CEC_GetDeviceName(MS_U8 u8Device)
{
    return (MS_U8*)_stMsApiCecInfoList.u8CecDeviceName[u8Device];
}


//***************************************************************************************

MS_U8* msAPI_CEC_GetDeviceVendorID(MS_U8 u8Device)
{
    return (MS_U8*) _stMsApiCecInfoList.u8CecVendorID[u8Device];
}

void msAPI_CEC_SetDeviceVendorID(MS_U8 u8Device, MS_U8* pName)
{
    _stMsApiCecInfoList.u8CecVendorID[u8Device][0] = pName[0];
    _stMsApiCecInfoList.u8CecVendorID[u8Device][1] = pName[1];
    _stMsApiCecInfoList.u8CecVendorID[u8Device][2] = pName[2];

  #if 0
    printf(" <Device Vendor ID> 0x%x: ", u8Device );
    printf(" = 0x%x,", _stMsApiCecInfoList.u8CecVendorID[u8Device][0]);
    printf(" 0x%x,",   _stMsApiCecInfoList.u8CecVendorID[u8Device][1]);
    printf(" 0x%x \n", _stMsApiCecInfoList.u8CecVendorID[u8Device][2]);
  #endif
}

//***************************************************************************************

//**************************************************************************
//  [Function Name]: msAPI_CEC_CheckDeviceIdx_PhyAddr
//
//  [Description]: It used to get the index of the  physical addrress we search
//
//  [Arguments]: physical addrress
//
//  [Return]: index of  physical addrress searched. otherwise, return E_LA_UNREGISTERED
//
//**************************************************************************
MsCEC_DEVICELA msAPI_CEC_CheckDeviceIdx_PhyAddr(MS_U16 u16PhyAddr)
{
    MsCEC_DEVICELA i = E_LA_TV;

    for (i= E_LA_TV; i< E_LA_UNREGISTERED; i++)
    {
        if( _stMsApiCecInfoList.u16PhysicalAddress[i] == u16PhyAddr)
        {
            return i;
        }
    }

    return E_LA_UNREGISTERED;
}

MS_U16 msAPI_CEC_GetDeviceIdx_PhyAddr(MS_U8 u8Idx)
{
    return _stMsApiCecInfoList.u16PhysicalAddress[u8Idx];
}

void msAPI_CEC_SetDeviceIdx_PhyAddr(MS_U8 u8Idx, MS_U16 u16PhyAddr)
{
    MsCEC_DEVICELA eDivIdx= msAPI_CEC_CheckDeviceIdx_PhyAddr(u16PhyAddr);

    if (  (eDivIdx != E_LA_UNREGISTERED) && (eDivIdx != u8Idx)
        && ((u16PhyAddr & 0xFF00) != (u16PhyAddr & 0xF000))
       )
    {
        msAPI_CEC_RemoveDevice(eDivIdx);
    }

    _stMsApiCecInfoList.u16PhysicalAddress[u8Idx] = u16PhyAddr;

}

//***************************************************************************************

static void msAPI_CEC_SetDeviceType(MS_U8 u8Idx, MsCEC_DEVICE_TYPE enDeviceType)
{
    _stMsApiCecInfoList.enDeviceType[u8Idx] = enDeviceType;
}

//***************************************************************************************

void msAPI_CEC_SetActiveDevice(MsCEC_DEVICELA enDevice)
{
    //printf(" >> msAPI_CEC_SetActiveDevice(0x%x) \n", enDevice);

    _stMsApiCecInfoList.enActiveDeviceLA = (MsCEC_DEVICELA) (enDevice & 0x0F);
}

MsCEC_DEVICELA msAPI_CEC_GetActiveDevice(void)
{
    return _stMsApiCecInfoList.enActiveDeviceLA;
}

//***************************************************************************************

void MApp_CEC_SetMyPhyAddr(INPUT_SOURCE_TYPE_t pre_srctype, INPUT_SOURCE_TYPE_t cur_srctype)
{
    if ( gCECInitDone == FALSE)
    {
        //printf("!!! CEC HW not Init yet !!! \n");
        return;
    }

    if (DB_HDMI_SETTING.g_bHdmiCecMode == DISABLE)
    {
        return;
    }

    if (IsSrcTypeHDMI(pre_srctype) && !IsSrcTypeHDMI(cur_srctype))
    {
        //VL++
        //_stCecApiInfo.ActivePhysicalAddress[0] = 0x00 ;
        //_stCecApiInfo.ActivePhysicalAddress[1] = 0x00 ;
    }
}

//***************************************************************************************

void msAPI_CEC_SetActivePhyAddr(MS_U16 u16ActPhyAddr)
{
    MsCEC_DEVICELA iActLA = msAPI_CEC_GetActiveDevice();

    _stMsApiCecInfoList.u16PhysicalAddress[iActLA] = u16ActPhyAddr;

    //printf(" Active Device 0x%x:", iActLA);
    //printf(" 0x%x \n", _stMsApiCecInfoList.u16PhysicalAddress[iActLA]);
}

U16 msAPI_CEC_GetActivePhyAddr(void)
{
    MsCEC_DEVICELA iActLA = msAPI_CEC_GetActiveDevice();

    return _stMsApiCecInfoList.u16PhysicalAddress[iActLA];
}

//***************************************************************************************

void msAPI_CEC_SetPowerStatus(MsCEC_DEVICELA enDevice, MsCEC_MSG_POWER_STATUS_PARM enPowerStatus)
{
    _stMsApiCecInfoList.enPowerStatus[enDevice] = enPowerStatus;

    CEC_DPRINTF(" Set enDevice 0x%x,", enDevice);
    CEC_DPUTSTR(" POWER_STATUS:");
    CEC_DPRINTF(" %s \n",
            (enPowerStatus == E_MSG_PWRSTA_ON)?          "ON"
            :(enPowerStatus == E_MSG_PWRSTA_STANDBY)?    "STANDBY"
            :(enPowerStatus == E_MSG_PWRSTA_STANDBY2ON)? "STANDBY2ON"
            :(enPowerStatus == E_MSG_PWRSTA_ON2STANDBY)? "ON2STANDBY"
            :"");
}

MsCEC_MSG_POWER_STATUS_PARM msAPI_CEC_GetPowerStatus(MsCEC_DEVICELA enDevice)
{
    MsCEC_MSG_POWER_STATUS_PARM enPowerStatus = _stMsApiCecInfoList.enPowerStatus[enDevice];

    CEC_DPRINTF(" enDevice 0x%x,", enDevice);
    CEC_DPUTSTR(" POWER_STATUS:");
    CEC_DPRINTF(" %s \n",
            (enPowerStatus == E_MSG_PWRSTA_ON)?          "ON"
            :(enPowerStatus == E_MSG_PWRSTA_STANDBY)?    "STANDBY"
            :(enPowerStatus == E_MSG_PWRSTA_STANDBY2ON)? "STANDBY2ON"
            :(enPowerStatus == E_MSG_PWRSTA_ON2STANDBY)? "ON2STANDBY"
            :"XXXXXXX");

    return enPowerStatus;
}

//***************************************************************************************

void msAPI_CEC_SetCecVersion(MsCEC_DEVICELA enDevice, MS_U8 u8Version)
{
    _stMsApiCecInfoList.u8CECVersion[enDevice] = u8Version;

    CEC_MSG(printf(" CEC Version of 0x%x is ", enDevice));

    switch (u8Version)
    {
        case CEC_VERSION_11:
            CEC_DPUTSTR(" CEC Ver 1.1 \n");
            break;
        case CEC_VERSION_12:
            CEC_DPUTSTR(" CEC Ver 1.2 \n");
            break;
        case CEC_VERSION_12a:
            CEC_DPUTSTR(" CEC Ver 1.2a \n");
            break;
        case CEC_VERSION_13:
            CEC_DPUTSTR(" CEC Ver 1.3 \n");
           break;
        case CEC_VERSION_13a:
            CEC_DPUTSTR(" CEC Ver 1.3a \n");
            break;
        case CEC_VERSION_14:
            CEC_DPUTSTR(" CEC Ver 1.4 \n");
            break;
        default:
            CEC_DPUTSTR(" Unknow CEC Ver \n");
           break;
    }
}

MS_U8 msAPI_CEC_GetCecVersion(MsCEC_DEVICELA enDevice)
{
    return _stMsApiCecInfoList.u8CECVersion[enDevice];
}

//***************************************************************************************

void MApp_CEC_ERROR_CODE_String(CEC_ERROR_CODE enCode)
{
    switch (enCode)
    {
        case E_CEC_FEATURE_ABORT:
            printf(" E_CEC_FEATURE_ABORT ");
            break;

        case E_CEC_RX_SUCCESS:
            printf(" E_CEC_RX_SUCCESS ");
            break;

        case E_CEC_TX_SUCCESS:
            printf(" E_CEC_TX_SUCCESS ");
            break;

        case E_CEC_RF:
            printf(" E_CEC_RF ");
            break;

        case E_CEC_LOST_ABT:
            printf(" E_CEC_LOST_ABT ");
            break;

        case E_CEC_BIT_SHORT:
            printf(" E_CEC_BIT_SHORT ");
            break;

        case E_CEC_BIT_LONG:
            printf(" E_CEC_BIT_LONG ");
            break;

        case E_CEC_NACK:
            printf(" E_CEC_NACK ");
            break;

        case E_CEC_SYSTEM_BUSY:
            printf(" E_CEC_SYSTEM_BUSY ");
            break;

        default:
            break;
    }
}

//***************************************************************************************

void MApp_CEC_RequestARCAction(U8 action)
{
    MsCEC_DEVICELA DeviceIdex=E_LA_TV;

    DeviceIdex = MApi_CEC_GetActiveLogicalAddress();

    if(DeviceIdex<=RESERVED_2)
    {
        if(action == CEC_ARC_REQUEST_INITIATION)
        {
            msAPI_CEC_PostMsg_RequestARCInitiation(POSTMSG, E_LA_AUDIO_SYS);
        }
        else if(action == CEC_ARC_REQUEST_TERMINATION)
        {
            MApp_CEC_ARC_TX_Control(FALSE);
						#ifdef sNewAudioMuteStyle
						msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, stGenSetting.g_SoundSetting.Volume, 0);
						#else
						MUTE_Off();
						#endif

            msAPI_CEC_PostMsg_RequestARCTermination(POSTMSG, E_LA_AUDIO_SYS);
        }
    }
}

//***************************************************************************************


void MApp_CEC_InputSourceSwitchHDMI(E_UI_INPUT_SOURCE CecUIInputSource)
{
    if ( 1
      #if (INPUT_HDMI_VIDEO_COUNT >= 1)
       && (CecUIInputSource != UI_INPUT_SOURCE_HDMI)
      #endif
      #if (INPUT_HDMI_VIDEO_COUNT >= 2)
       && (CecUIInputSource != UI_INPUT_SOURCE_HDMI2)
      #endif
      #if (INPUT_HDMI_VIDEO_COUNT >= 3)
       && (CecUIInputSource != UI_INPUT_SOURCE_HDMI3)
      #endif
      #if (INPUT_HDMI_VIDEO_COUNT >= 4)
       && (CecUIInputSource != UI_INPUT_SOURCE_HDMI4)
      #endif
       )
    {
        return;
    }

  #ifdef ENABLE_DMP
    if(IsStorageInUse())
    {
        MApp_MPlayer_StopPreview();
        MApp_MPlayer_Stop();
        MApp_MPlayer_ExitMediaPlayer();
    }
  #endif

    MApp_ZUI_ACT_ShutdownOSD();

    MApp_ZUI_ACT_InputSourceSwitch(CecUIInputSource);

  #ifdef ENABLE_DMP
    MApp_ChannelChange_VariableInit();
    MApp_TopStateMachine_SetTopState(STATE_TOP_ANALOG_SHOW_BANNER);
  #endif
}

void msAPI_CEC_DeviceChange(MsCEC_DEVICELA enChangedDevice)
{
    WORD u16ChangedPhyAddr, u16CurrentPhyAddr;
    MS_U8 u8Value;

    #if(CEC_STATE_MACHINE== FALSE)
        MS_U8 au8TxBuf[2];
    #endif

    u16CurrentPhyAddr = msAPI_CEC_GetActivePhyAddr();

    //VL++
    u16ChangedPhyAddr = msAPI_CEC_GetDeviceIdx_PhyAddr(enChangedDevice);
    u8Value = (u16ChangedPhyAddr & 0xF000) >> 12;

    CEC_MSG(printf(">> msAPI_CEC_DeviceChange 0x%x: ", enChangedDevice));
    CEC_MSG(printf(" [0x%x] \n", u16ChangedPhyAddr));
    /*
    CEC compliance test 11.1.2-1: froce to change source if it's not in HDMI
    */
    if (IsHDMIInUse() == FALSE)
    {
        E_UI_INPUT_SOURCE eUiInputSource = UI_INPUT_SOURCE_NONE;

        switch (u8Value)
        {
            case 0x01:
                if (UI_INPUT_SOURCE_TYPE != UI_INPUT_SOURCE_HDMI)
                {
                    eUiInputSource = UI_INPUT_SOURCE_HDMI;
                }
                break;

          #if (INPUT_HDMI_VIDEO_COUNT >= 2)
            case 0x02:
                if (UI_INPUT_SOURCE_TYPE != UI_INPUT_SOURCE_HDMI2)
                {
                    eUiInputSource = UI_INPUT_SOURCE_HDMI2;
                }
                break;
          #endif

          #if (INPUT_HDMI_VIDEO_COUNT >= 3)
            case 0x03:
                if (UI_INPUT_SOURCE_TYPE != UI_INPUT_SOURCE_HDMI3)
                {
                    eUiInputSource = UI_INPUT_SOURCE_HDMI3;
                }
            break;
          #endif

          #if (INPUT_HDMI_VIDEO_COUNT >= 4)
            case 0x04:
                if (UI_INPUT_SOURCE_TYPE != UI_INPUT_SOURCE_HDMI4)
                {
                    eUiInputSource = UI_INPUT_SOURCE_HDMI4;
                }
            break;
          #endif
        }

        if (eUiInputSource != UI_INPUT_SOURCE_NONE)
        {
            MApp_CEC_InputSourceSwitchHDMI(eUiInputSource);
        }
    }

    msAPI_CEC_SetActiveDevice(enChangedDevice);
    msAPI_CEC_SetActivePhyAddr(u16ChangedPhyAddr);

#if CEC_STATE_MACHINE
    msAPI_CEC_TrigCecState_7(u16CurrentPhyAddr, u16ChangedPhyAddr, enChangedDevice);
#else
    if (u16ChangedPhyAddr != 0xFFFF)
    {
        au8TxBuf[0] = u16ChangedPhyAddr >> 8;
        au8TxBuf[1] = u16ChangedPhyAddr & 0xFF;

        msAPI_CEC_PostMsg_SetStreamPath(DIRECTMSG, au8TxBuf);
    }
#endif
}

//**************************************************************************
// For CEC usage - sending routing change or active source when switching source
// - Routing change: HDMI -> HDMI, non-HDMI -> HDMI
// - Active source   : HDMI -> non-HDMI

void msAPI_CEC_RoutingControl_SourceChange(INPUT_SOURCE_TYPE_t pre_srctype, INPUT_SOURCE_TYPE_t cur_srctype)
{
    U8 orig_phyaddress[2], new_phyaddress[2];

    if ( gCECInitDone == FALSE)
    {
        //printf("!!! CEC HW not Init yet !!! \n");
        return;
    }

    if (DB_HDMI_SETTING.g_bHdmiCecMode == DISABLE)
    {
       return;
    }

    MApp_CEC_SetMyPhyAddr(pre_srctype, cur_srctype);

    if ( IsSrcTypeHDMI(pre_srctype) && (!IsSrcTypeHDMI(cur_srctype)) )
    {
        MS_U8 au8TxBuf[2];

        au8TxBuf[0] = 0x00;
        au8TxBuf[1] = 0x00;

        msAPI_CEC_PostMsg_ActiveSource(DIRECTMSG, au8TxBuf);
    }
    else if ( (IsSrcTypeHDMI(pre_srctype) && IsSrcTypeHDMI(cur_srctype))
           || (!IsSrcTypeHDMI(pre_srctype) && IsSrcTypeHDMI(cur_srctype)) )
    {
        switch (pre_srctype)
        {
            case INPUT_SOURCE_HDMI:
                orig_phyaddress[0] = CEC_PORT1;
                break;

          #if (INPUT_HDMI_VIDEO_COUNT >= 2)
            case INPUT_SOURCE_HDMI2:
                orig_phyaddress[0] = CEC_PORT2;
                break;
          #endif

          #if (INPUT_HDMI_VIDEO_COUNT >= 3)
            case INPUT_SOURCE_HDMI3:
                orig_phyaddress[0] = CEC_PORT3;
                break;
          #endif

          #if (INPUT_HDMI_VIDEO_COUNT >= 4)
            case INPUT_SOURCE_HDMI4:
                orig_phyaddress[0] = CEC_PORT4;
                break;
          #endif

            default:
                if(!IsSrcTypeHDMI(pre_srctype)) // switch to the internal TV sources
                    orig_phyaddress[0] = 0x00;
                break;
        }
        orig_phyaddress[1] = 0x00;

        switch (cur_srctype)
        {
            case INPUT_SOURCE_HDMI:
                new_phyaddress[0] = CEC_PORT1;
                break;

          #if (INPUT_HDMI_VIDEO_COUNT >= 2)
            case INPUT_SOURCE_HDMI2:
                new_phyaddress[0] = CEC_PORT2;
                break;
          #endif

          #if (INPUT_HDMI_VIDEO_COUNT >= 3)
            case INPUT_SOURCE_HDMI3:
                new_phyaddress[0] = CEC_PORT3;
                break;
          #endif

          #if (INPUT_HDMI_VIDEO_COUNT >= 4)
            case INPUT_SOURCE_HDMI4:
                new_phyaddress[0] = CEC_PORT4;
                break;
          #endif

            default:
                break;
        }
        new_phyaddress[1] = 0x00;

    #if CEC_STATE_MACHINE
        msAPI_CEC_TrigCecState_6_3_3_2(orig_phyaddress, new_phyaddress);
    #else
        msAPI_CEC_PostMsg_RoutingChange(DIRECTMSG, orig_phyaddress, new_phyaddress);

        msAPI_CEC_PostMsg_SetStreamPath(DIRECTMSG, new_phyaddress);
    #endif
    }
}

//**************************************************************************

static void msAPI_CEC_CheckActiveDevice(void)
{
    MS_BOOL bCheck = FALSE;
    MsCEC_DEVICELA i, enActLA;

    enActLA = msAPI_CEC_GetActiveDevice();

    if (  ( enActLA == E_LA_TV)
       || ( msAPI_CEC_IsDeviceExist(enActLA) == FALSE )
       )
    {
        bCheck = TRUE;
    }

    if ( bCheck )
    {
        if ( msAPI_CEC_GetDeviceTotalNum() == 0)
        {
            msAPI_CEC_SetActiveDevice(E_LA_TV);
        }
        else if ( msAPI_CEC_GetDeviceTotalNum() == 1)
        {
            for (i=E_LA_TV; i<E_LA_UNREGISTERED; i++)
            {
                if ( msAPI_CEC_IsDeviceExist(i) == TRUE )
                {
                    msAPI_CEC_SetActiveDevice(i);
                }
            }
        }
        else
        {
            U8 u8HSB = 0x10;

          #if (INPUT_HDMI_VIDEO_COUNT >= 1)
           if (UI_INPUT_SOURCE_TYPE == UI_INPUT_SOURCE_HDMI)
            {
                u8HSB = 0x10;
            }
          #endif

          #if (INPUT_HDMI_VIDEO_COUNT >= 2)
           if (UI_INPUT_SOURCE_TYPE == UI_INPUT_SOURCE_HDMI2)
            {
                u8HSB = 0x20;
            }
          #endif

          #if (INPUT_HDMI_VIDEO_COUNT >= 3)
           if (UI_INPUT_SOURCE_TYPE == UI_INPUT_SOURCE_HDMI3)
            {
                u8HSB = 0x30;
            }
          #endif

          #if (INPUT_HDMI_VIDEO_COUNT >= 4)
           if (UI_INPUT_SOURCE_TYPE == UI_INPUT_SOURCE_HDMI4)
            {
                u8HSB = 0x40;
            }
          #endif

            // 1. check if any device is match with child position [x,0.0.0]
            for (i=E_LA_RECORDER1; i<E_LA_UNREGISTERED; i++)
            {
                if ( (msAPI_CEC_GetDeviceIdx_PhyAddr(i) & 0xFF00) == (u8HSB << 8) )
                {
                    msAPI_CEC_SetActiveDevice(i);
                }
            }

            if ( msAPI_CEC_GetActiveDevice() == E_LA_TV )
            {
                for (i=E_LA_RECORDER1; i<E_LA_UNREGISTERED; i++)
                {
                    if ( (msAPI_CEC_GetDeviceIdx_PhyAddr(i) & 0xF000) == (u8HSB << 8) )
                    {
                        msAPI_CEC_SetActiveDevice(i);
                    }
                }
            }
        }
    }

    CEC_DPRINTF("\n *** Active 0x%x *** \n", msAPI_CEC_GetActiveDevice() );
}

void msAPI_CEC_ReportDevice(void)
{
#if CEC_DEBUG
    MsCEC_DEVICELA i;
    MS_U8 u8Num = msAPI_CEC_GetDeviceTotalNum();

    if (u8Num > 0)
    {
        printf("\n ***** Device List View ***** \n");
        printf(" [%2d], ", u8Num);
        printf(" Active 0x%x \n", msAPI_CEC_GetActiveDevice() );
        if (msAPI_CEC_GetActiveDevice() >= E_LA_UNREGISTERED)
        {
            msAPI_CEC_SetActiveDevice(E_LA_TV);
            printf(" Active 0x%x \n", msAPI_CEC_GetActiveDevice() );
        }

        for (i=E_LA_TV; i<E_LA_UNREGISTERED; i++)
        {
            if ( msAPI_CEC_IsDeviceExist(i) == TRUE )
            {
                printf(" PhyAddr of hDevice 0x%x is", i );
                printf(" [0x%04x] \n", msAPI_CEC_GetDeviceIdx_PhyAddr((MS_U8)i));
            }
        }
        printf(" **************************** \n");
    }
#endif
}
static void msAPI_CEC_AddDevice(MsCEC_DEVICELA enDevice)
{
    if (enDevice < E_LA_UNREGISTERED)
    {
        if (msAPI_CEC_IsDeviceExist(enDevice) == FALSE)
        {
            _stMsApiCecInfoList.bCecDevicesExisted[enDevice] = TRUE;

            _stMsApiCecInfoList.u8CecDeviceCount++;

            msAPI_CEC_PostMsg_GivePhysicalAddress(DIRECTMSG, enDevice);

            if (enDevice == E_LA_AUDIO_SYS)
            {
                if (DB_HDMI_SETTING.g_enHDMIARC == TRUE)
                {
                    msAPI_CEC_PostMsg_RequestARCInitiation(DIRECTMSG, E_LA_AUDIO_SYS);
#if (ENABLE_DOLBY_BULLETIN24)
                    msAPI_CEC_PostMsg_RequestShortAudioDescriptor(POSTMSG, E_LA_AUDIO_SYS);
#endif
                }
            }

            CEC_DPRINTF("[Add New Device] 0x%x \n", (MS_U8)enDevice );
        }

        msAPI_CEC_ReportDevice();
    }
}

static void msAPI_CEC_RemoveDevice(MsCEC_DEVICELA enDevice)
{
    MS_U8 txbuf[3] = {0x00, 0x00, 0x00};

    if (msAPI_CEC_IsDeviceExist(enDevice) == TRUE)
    {
        _stMsApiCecInfoList.bCecDevicesExisted[enDevice] = FALSE;

        msAPI_CEC_SetDeviceIdx_PhyAddr(enDevice, 0x00);

        msAPI_CEC_SetDeviceName(enDevice, NULL, TRUE);

        msAPI_CEC_SetDeviceVendorID(enDevice, txbuf);

        msAPI_CEC_SetCecVersion(enDevice, 0xFF);

        msAPI_CEC_SetDeviceType(enDevice, E_DEVICE_TYPE_TV);

        _stMsApiCecInfoList.u8CecDeviceCount--;

        CEC_DPRINTF("[Remove Device] %bx ", (MS_U8) enDevice);

        if ( _stMsApiCecInfoList.u8CecDeviceCount > 0)
        {
            msAPI_CEC_ReportDevice();
        }
        else
        {
            msAPI_CEC_SetActiveDevice(E_LA_TV);
        }

#if (ENABLE_DOLBY_BULLETIN24)
        if (enDevice == E_LA_AUDIO_SYS)
        {
            msAPI_DolbyBulletin24_remove_SAD();
        }
#endif
    }
}

//***************************************************************************************

void msAPI_CEC_SetTvPowerStatusAfterBootUp(void)
{
    while (u8ReportCECPowerStatusCount < (U8)StartReportPowerOnConunt)
    {
        u8ReportCECPowerStatusCount++;

        if (u8ReportCECPowerStatusCount == (U8)StartReportPowerOnConunt)
        {
            msAPI_CEC_SetPowerStatus(E_LA_TV, E_MSG_PWRSTA_ON);
            bCECReportPowerStatusAtBootingUp = FALSE;
        }
    }
}

//***************************************************************************************

void msAPI_CEC_ForceImmediatelyPolling(void)
{
    g_bCecForceImmediatelyPolling = TRUE;

    msAPI_CEC_InitCecStructure();
}

//***************************************************************************************

void msAPI_CEC_PollingDevice(void)
{
    CEC_ERROR_CODE  res = E_CEC_FEATURE_ABORT;
    MsCEC_DEVICELA i = E_LA_TV;

    static MsCEC_DEVICELA _enDeviceIdex;
    static MS_BOOL CecDevicesExisted[15];

#if IMMEDIATELY_POLLING
    if ( g_bCecForceImmediatelyPolling )
    {
        CEC_POLLING_MSG_DBG(printf("\r\n[I] Start Polling CEC Device \n"));

        g_bCecForceImmediatelyPolling = FALSE;

        _bStartPolling = I_POLLING_START_PING;
        _enDeviceIdex = E_LA_TV;

        for (i=E_LA_TV; i<E_LA_UNREGISTERED; i++)
        {
            CecDevicesExisted[i] = FALSE;
        }

        _u32CecDeviceMonitorTimer = msAPI_Timer_GetTime0();
    }
#endif

#if BACKGROUND_POLLING
    if (  (_bStartPolling == STATUS_POLLING_IDLE)
       && (msAPI_Timer_DiffTimeFromNow(_u32CecDeviceMonitorTimer) > B_MONITOR_CEC_DEVICE_PERIOD)
       )
    {
        CEC_POLLING_MSG_DBG(printf("\r\n[B] Start Polling CEC Device \n"));

        _bStartPolling = B_POLLING_START_PING;
        _enDeviceIdex = E_LA_TV;

        for (i=E_LA_TV; i<E_LA_UNREGISTERED; i++)
        {
            CecDevicesExisted[i] = FALSE;
        }

        _u32CecDeviceMonitorTimer = msAPI_Timer_GetTime0();
    }

    /*
    *************************************************************************
    background polling start
    *************************************************************************
    */
    if (_bStartPolling == B_POLLING_START_PING)
    {
        if (msAPI_Timer_DiffTimeFromNow(_u32CecDeviceMonitorTimer) > B_CEC_POLLING_START_PING_PERIOD)
        {
            CEC_POLLING_MSG_DBG(printf("[B] Polling CEC Device 0x%x", _enDeviceIdex));

            res = msAPI_CEC_PingDevice(_enDeviceIdex);

            if (res & E_CEC_TX_SUCCESS)
            {
                CecDevicesExisted[_enDeviceIdex] = TRUE;

//                CEC_POLLING_MSG_DBG(printf(" - ADD  phyaddr= %x \n", msAPI_CEC_GetDeviceIdx_PhyAddr(_enDeviceIdex) ));
                CEC_POLLING_MSG_DBG(printf(" - ADD \n" ));
            }
            else if(res & E_CEC_SYSTEM_BUSY)
            {
                CEC_POLLING_MSG_DBG(printf("\n  E_CEC_SYSTEM_BUSY \n"));
            }
            else
            {
                CecDevicesExisted[_enDeviceIdex] = FALSE;
                CEC_POLLING_MSG_DBG(printf(" \n"));
            }

            if (_enDeviceIdex >= E_LA_FREE_USE)
            {
                _enDeviceIdex = E_LA_TV;
                for (i=E_LA_TV; i<E_LA_UNREGISTERED; i++)
                {
                    if (CecDevicesExisted[i] == TRUE)
                    {
                        _enDeviceIdex = i;
                        break;
                    }
                }

                if (_enDeviceIdex != E_LA_TV)
                {
                    _bStartPolling = B_POLLING_GIVE_PHYSICAL_ADDRESS;

                    CEC_POLLING_MSG_DBG(printf("[B] Start <Give Physical Address>[%d] \n", _enDeviceIdex));
                }
                else
                {
                    _enDeviceIdex = E_LA_TV;
                    _bStartPolling = STATUS_POLLING_IDLE;

                    CEC_POLLING_MSG_DBG(printf("[B] Connect No CEC Device \n"));
                }
            }
            else
            {
                _enDeviceIdex++;
            }

            _u32CecDeviceMonitorTimer = msAPI_Timer_GetTime0();
        }
    }

    if (_bStartPolling == B_POLLING_GIVE_PHYSICAL_ADDRESS)
    {
        if (msAPI_Timer_DiffTimeFromNow(_u32CecDeviceMonitorTimer) > B_CEC_GIVE_PHYSICAL_ADDRESS_PERIOD)
        {
            CEC_POLLING_MSG_DBG(printf("[B] Reporting Physical Address 0x%x \n", _enDeviceIdex));

//            msAPI_CEC_PostMsg_GivePhysicalAddress(DIRECTMSG, _enDeviceIdex);  //remove it because it will cause lots of message

            if (_enDeviceIdex < E_LA_UNREGISTERED)
                _enDeviceIdex++;

            while (  (_enDeviceIdex < E_LA_UNREGISTERED)
                  && (CecDevicesExisted[_enDeviceIdex] == FALSE) )
            {
                 _enDeviceIdex++;
            }

            if (_enDeviceIdex >= E_LA_UNREGISTERED)
            {
                CEC_POLLING_MSG_DBG(printf("[B] Done_ \n"));

                _enDeviceIdex = E_LA_TV;
                _bStartPolling = STATUS_POLLING_IDLE;
            }

            _u32CecDeviceMonitorTimer = msAPI_Timer_GetTime0();
        }
    }
    /*
    *************************************************************************
    background polling end
    *************************************************************************
    */
#endif

#if IMMEDIATELY_POLLING
    /*
    *************************************************************************
    immediately polling start
    *************************************************************************
    */
    if (_bStartPolling == I_POLLING_START_PING)
    {
        if (msAPI_Timer_DiffTimeFromNow(_u32CecDeviceMonitorTimer) > I_CEC_POLLING_START_PING_PERIOD)
        {
            res = E_CEC_FEATURE_ABORT;

            CEC_POLLING_MSG_DBG(printf("[I] Polling CEC Device 0x%x ", _enDeviceIdex));

            res = msAPI_CEC_PingDevice(_enDeviceIdex);

            if (res & E_CEC_TX_SUCCESS)
            {
                CecDevicesExisted[_enDeviceIdex] = TRUE;

                CEC_POLLING_MSG_DBG(printf(" - ADD \n"));
            }
            else if(res & E_CEC_SYSTEM_BUSY )
            {
                CEC_MSG(printf("\n  E_CEC_SYSTEM_BUSY \n"));
            }
            else
            {
                CecDevicesExisted[_enDeviceIdex] = FALSE;

                CEC_POLLING_MSG_DBG(printf(" \n"));
            }

            if (_enDeviceIdex >= E_LA_FREE_USE)
            {
                _enDeviceIdex = E_LA_TV;
                for (i=E_LA_TV; i<E_LA_UNREGISTERED; i++)
                {
                    if (CecDevicesExisted[i] == TRUE)
                    {
                        _enDeviceIdex = i;
                        break;
                    }
                }

                if (_enDeviceIdex != E_LA_TV)
                {
                    _bStartPolling = I_POLLING_GIVE_PHYSICAL_ADDRESS;

                    CEC_POLLING_MSG_DBG(printf("[I] Start <Give Physical Address>[%d] \n", _enDeviceIdex));
                }
                else
                {
                    _enDeviceIdex = E_LA_TV;
                    _bStartPolling = STATUS_POLLING_IDLE;

                    CEC_POLLING_MSG_DBG(printf("[I] Connect No CEC Device \n"));
                }
            }
            else
            {
                _enDeviceIdex++;
            }

            _u32CecDeviceMonitorTimer = msAPI_Timer_GetTime0();
        }
    }

    if (_bStartPolling == I_POLLING_GIVE_PHYSICAL_ADDRESS)
    {
        if (msAPI_Timer_DiffTimeFromNow(_u32CecDeviceMonitorTimer) > I_CEC_GIVE_PHYSICAL_ADDRESS_PERIOD)
        {
            CEC_POLLING_MSG_DBG(printf("[I] Reporting Physical Address 0x%x \n", _enDeviceIdex));

            msAPI_CEC_PostMsg_GivePhysicalAddress(DIRECTMSG, _enDeviceIdex);

            if (_enDeviceIdex < E_LA_UNREGISTERED)
                _enDeviceIdex++;

            while (  (_enDeviceIdex < E_LA_UNREGISTERED)
                  && (CecDevicesExisted[_enDeviceIdex] == FALSE) )
            {
                _enDeviceIdex++;
            }

            if (_enDeviceIdex >= E_LA_UNREGISTERED)
            {
                if ( IsHDMIInUse() )
                {
                    _enDeviceIdex = E_LA_TV;

                    for (i=E_LA_TV; i<E_LA_UNREGISTERED; i++)
                    {
                        if (CecDevicesExisted[i] == TRUE)
                        {
                            _enDeviceIdex = i;
                            break;
                        }
                    }

                    _bStartPolling = I_POLLING_REPORT_POWER_STATUS;
                    CEC_POLLING_MSG_DBG(printf("[I] Start <Give Device Power Status>[%d] \n", _enDeviceIdex));
                }
                else
                {
                    CEC_POLLING_MSG_DBG(printf("[I] Done \n"));

                    _enDeviceIdex = E_LA_TV;
                    _bStartPolling = STATUS_POLLING_IDLE;
                }
            }

            _u32CecDeviceMonitorTimer = msAPI_Timer_GetTime0();
        }
    }

    if (_bStartPolling == I_POLLING_REPORT_POWER_STATUS)
    {
        if (msAPI_Timer_DiffTimeFromNow(_u32CecDeviceMonitorTimer) > I_CEC_REPORT_POWER_STATUS_PERIOD)
        {
            CEC_POLLING_MSG_DBG(printf("[I] Reporting Power Status 0x%x \n", _enDeviceIdex));

            msAPI_CEC_PostMsg_GiveDevicePowerStatus(POSTMSG, _enDeviceIdex);

            if (_enDeviceIdex < E_LA_UNREGISTERED)
                _enDeviceIdex++;

            while (  (_enDeviceIdex < E_LA_UNREGISTERED)
                  && (CecDevicesExisted[_enDeviceIdex] == FALSE) )
            {
                 _enDeviceIdex++;
            }

            _u32CecDeviceMonitorTimer = msAPI_Timer_GetTime0();

            if (_enDeviceIdex >= E_LA_UNREGISTERED)
            {
                CEC_POLLING_MSG_DBG(printf("[I] Done \n"));

                _enDeviceIdex = E_LA_TV;
                _bStartPolling = STATUS_POLLING_IDLE;

                _u32CecDeviceMonitorTimer += B_MONITOR_CEC_DEVICE_PERIOD;
            }
        }
    }
    /*
    *************************************************************************
    immediately polling end
    *************************************************************************
    */
#endif

}


static void msAPI_CEC_HandleFeatureAbort(MsCEC_DEVICELA enDeviceFA, MsCEC_DEVICELA enDeviceDstFA,
                                         MS_U8 u8opCode, MS_U8 u8reason)
{
    CEC_DPRINTF("UnSupport opCode =%bx \n", u8opCode);
    CEC_DPRINTF("UnSupport reason =%bx \n", u8reason);

    switch (u8opCode)      //CEC1.3a Table 7 ~ 27
    {
      #if SYSTEM_AUDIO_CONTROL_SUPPORT
        case E_MSG_SAC_GIVE_AUDIO_STATUS:
        {
        }
        break;

        case  E_MSG_ARC_REQUEST_ARC_INITIATION:
        {
            if(enDeviceFA== E_LA_AUDIO_SYS)
            {
                CEC_MSG(printf("\n Amp ARC OFF!\n"));
                gIsCECAmpARCOn = FALSE;

                printf(" speak open [%s,%s,%d]\n\n", __FUNCTION__,__FILE__,__LINE__);
                MApp_CEC_ARC_TX_Control(FALSE);

								#ifdef sNewAudioMuteStyle
								msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, stGenSetting.g_SoundSetting.Volume, 0);
								#else
								MUTE_Off();
								#endif
            }
        }
        break;
      #endif


      #if DEVICE_OSD_NAME_TRANSFER_SUPPORT
        case E_MSG_OSDNT_GIVE_OSD_NAME:
        {
            if (msAPI_CEC_IsDeviceExist(enDeviceFA) == TRUE )
                msAPI_CEC_SetDeviceName(enDeviceFA, NULL, TRUE);
        }
        break;
      #endif

#if (ENABLE_DOLBY_BULLETIN24)
        case E_MSG_SAC_REQUEST_SHORT_AUDIO_DESCRIPTOR:
        {
            msAPI_DolbyBulletin24_remove_SAD();
        }
        break;
#endif

      #if VENDOR_SPECIFIC_SUPPORT
        case E_MSG_VS_GIVE_DEVICE_VENDOR_ID:
        {
        }
        break;
      #endif

        default:
            break;
    }

    UNUSED(enDeviceDstFA);
    UNUSED(u8reason);
}


//**************************************************************************
//  [Function Name]:
//                   MsAPI_CECProcessCmd()
//  [Description]
//                   It used to parse CEC command
//  [Arguments]:
//
//  [Return]:
//
//**************************************************************************
void msAPI_CEC_ProcessCmd(void)
{
    MS_U8 header, len;
    MS_U8 para0 = 0, para1 = 0, para2 = 0, para3 = 0;
    MsCEC_MSGLIST opcode;
    MsCEC_DEVICELA enDevice, enDeviceDst;
    MS_U8 u8Fifoidx;
#if  CEC_DEBUG
    MS_U8 i;
#endif
    BOOLEAN bCheckFrameOK = TRUE;
    MS_U32 u32StartTime, u32CheckTime;

    if (MApi_CEC_GetMsgCnt() == 0 ) return;  //no received message to process

    u32StartTime = msAPI_Timer_GetTime0();

    header = MApi_CEC_GetRxData( MApi_CEC_GetFifoIdx(), 0);
    opcode = (MsCEC_MSGLIST)  MApi_CEC_GetRxData( MApi_CEC_GetFifoIdx(), 1);

    len = MApi_CEC_GetCmdLen();

    if (len>2)  para0  = MApi_CEC_GetRxData( MApi_CEC_GetFifoIdx(), 2);
    if (len>3)  para1  = MApi_CEC_GetRxData( MApi_CEC_GetFifoIdx(), 3);
    if (len>4)  para2  = MApi_CEC_GetRxData( MApi_CEC_GetFifoIdx(), 4);
    if (len>5)  para3  = MApi_CEC_GetRxData( MApi_CEC_GetFifoIdx(), 5);

    enDevice    = (MsCEC_DEVICELA)((header & 0xF0)>>4);
    enDeviceDst = (MsCEC_DEVICELA) (header & 0x0F);
#if  CEC_DEBUG
    printf("\n\33[1;31m ======= [CEC] =======\33[0m \n");

    printf(" header      = 0x%bx \n", header);
    printf(" opcode      = 0x%bx \n", opcode);

    for (i=2; i<len; i++)
    {
        printf(" para%2d      =", (i-2));
        printf(" 0x%bx \n", MApi_CEC_GetRxData( MApi_CEC_GetFifoIdx(), i));
    }
    printf(" enDevice    = 0x%bx \n", enDevice);
    printf(" enDeviceDst = 0x%bx \n", enDeviceDst);
    printf(" ========================= \n");
#endif

    // Check Frame first
    switch (opcode)      //CEC1.3a Table 7 ~ 27
    {
    //----- One Touch Play ---------------
    #if ONE_TOUCH_PLAY_SUPPORT
        case E_MSG_OTP_IMAGE_VIEW_ON:     //if in standby, firstly power on
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 2) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_OTP_IMAGE_VIEW_ON(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_OTP_TEXT_VIEW_ON:      //if in standby, firstly power on
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 2) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_OTP_TEXT_VIEW_ON(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;
    #endif
    //----- One Touch Play end ---------------


    //----- One Touch Play --------------
    //----- Routing Control --------------
    #if (ONE_TOUCH_PLAY_SUPPORT || ROUTING_CONTROL_SUPPORT)
        case E_MSG_ACTIVE_SOURCE:             //broadcast, if addressed, ignored
            if (MApi_CEC_CheckFrame(E_TRANS_BROADCAST_MSG, 4) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_ACTIVE_SOURCE(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;
    #endif // #if (ONE_TOUCH_PLAY_SUPPORT || ROUTING_CONTROL_SUPPORT)
    //----- One Touch Play end --------------
    //----- Routing Control end --------------


    //----- Routing Control --------------
    #if (ROUTING_CONTROL_SUPPORT)
        case E_MSG_RC_INACTIVE_SOURCE:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 4) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_RC_INACTIVE_SOURCE(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_RC_REQ_ACTIVE_SOURCE:
            if (MApi_CEC_CheckFrame(E_TRANS_BROADCAST_MSG, 2) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_RC_REQUEST_ACTIVE_SOURCE(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_RC_ROUTING_CHANGE:
            if (MApi_CEC_CheckFrame(E_TRANS_BROADCAST_MSG, 6) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_RC_ROUTING_CHANGE(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_RC_ROUTING_INFO:
            if (MApi_CEC_CheckFrame(E_TRANS_BROADCAST_MSG, 4) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_RC_ROUTING_INFO(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_RC_SET_STREM_PATH:
            if (MApi_CEC_CheckFrame(E_TRANS_BROADCAST_MSG, 4) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_RC_SET_STREM_PATH(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;
    #endif // #if (ROUTING_CONTROL_SUPPORT)
    //----- Routing Control end --------------


    //----- Standby Command --------------
    #if STANDBY_COMMAND_SUPPORT
        case E_MSG_STANDBY:
            if (MApi_CEC_CheckFrame(E_TRANS_BOTHTYPE_MSG, 2) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_STANDBY(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;
    #endif // #if STANDBY_COMMAND_SUPPORT
    //----- Standby Command end --------------


    //----- One Touch Record--------------
    #if ONE_TOUCH_RECORD_SUPPORT
        case E_MSG_OTR_RECORD_ON:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 2) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_OTR_RECORD_ON(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_OTR_RECORD_OFF:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 3) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_OTR_RECORD_OFF(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_OTR_RECORD_STATUS:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 3) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_OTR_RECORD_STATUS(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        // Initiate a recording using the <Record On> message, or send a <Feature Abort> [¡§Cannot provide source¡¨]
        // if the presently displayed source is not recordable.
        case E_MSG_OTR_RECORD_TV_SCREEN:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 2) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_OTR_RECORD_TV_SCREEN(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;
    #endif // #if ONE_TOUCH_RECORD_SUPPORT
    //----- One Touch Record end --------------


    //----- Timer programmer -------------
    #if TIMER_PROGRAMMER_SUPPORT
        case E_MSG_TP_CLEAR_ANALOGUE_TIMER:
            //TO DO
            if(0)// (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, ) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_TP_CLEAR_ANALOGUE_TIMER(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_TP_CLEAR_DIGITAL_TIMER:
            //TO DO
            if(0)// (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, ) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_TP_CLEAR_DIGITAL_TIMER(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_TP_CLEAR_EXTERNAL_TIMER:
            //TO DO
            if(0)// (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, ) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_TP_CLEAR_EXTERNAL_TIMER(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_TP_SET_ANALOGUE_TIMER:
            //TO DO
            if(0)// (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, ) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_TP_SET_ANALOGUE_TIMER(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_TP_SET_DIGITAL_TIMER:
            //TO DO
            if(0)// (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, ) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_TP_SET_DIGITAL_TIMER(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_TP_SET_EXTERNAL_TIMER:
            //TO DO
            if(0)// (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, ) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_TP_SET_EXTERNAL_TIMER(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_TP_SET_TIMER_PROGRAM_TITLE:
            //TO DO
            if(0)// (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, ) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_TP_SET_TIMER_PROGRAM_TITLE(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_TP_TIMER_CLEARD_STATUS:
            //TO DO
            if(0)// (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, ) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_TP_TIMER_CLEARD_STATUS(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_TP_TIMER_STATUS:
            //TO DO
            if(0)// (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, ) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_TP_TIMER_STATUS(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;
    #endif
    //----- Timer programmer end -------------


    //----- System Information -----------
    //----- Vendor Specific -----------
    #if (SYSTEM_INFORMATION_SUPPORT | VENDOR_SPECIFIC_SUPPORT)
        case E_MSG_SI_CEC_VERSION:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 3) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_SI_CEC_VERSION(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_SI_GET_CEC_VERSION:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 2) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_SI_GET_CEC_VERSION(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;
    #endif // #if (SYSTEM_INFORMATION_SUPPORT | VENDOR_SPECIFIC_SUPPORT)
    //----- System Information end -----------
    //----- Vendor Specific end -----------



    //----- System Information -----------
    #if SYSTEM_INFORMATION_SUPPORT
        case E_MSG_SI_GIVE_PHYSICAL_ADDRESS:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 2) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_SI_GIVE_PHYSICAL_ADDRESS(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_SI_REPORT_PHYSICAL_ADDRESS:
            if (MApi_CEC_CheckFrame(E_TRANS_BROADCAST_MSG, 5) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_SI_REPORT_PHYSICAL_ADDRESS(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_SI_GET_MENU_LANGUAGE:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 2) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_SI_GET_MENU_LANGUAGE(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_SI_SET_MENU_LANGUAGE:
            //TO DO
            if(0)// (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, ) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_SI_SET_MENU_LANGUAGE(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            printf("[CEC] E_MSG_SI_SET_MENU_LANGUAGE(0x%x) \n", opcode);
            printf(" len   = 0x%x \n", len);
            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n");
            break;

//        case E_MSG_SI_POLLING_MESSAGE:
//                break;
    #endif // #if SYSTEM_INFORMATION_SUPPORT
    //----- System Information end -----------


    //----- Deck Control Feature----------
    #if DECK_CONTROL_SUPPORT
        case E_MSG_DC_DECK_CONTROL:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 3) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_DC_DECK_CONTROL(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_DC_DECK_STATUS:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 3) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_DC_DECK_STATUS(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_DC_GIVE_DECK_STATUS:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 3) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_DC_GIVE_DECK_STATUS(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_DC_PLAY:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 3) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_DC_PLAY(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;
    #endif // #if DECK_CONTROL_SUPPORT
    //----- Deck Control Feature end -----------


    #if TUNER_CONTROL_SUPPORT
    //----- Tuner Control ----------------
        case E_MSG_TC_GIVE_TUNER_DEVICE_STATUS:
            if (0)// (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, ) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_TC_GIVE_TUNER_DEVICE_STATUS(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_TC_SEL_ANALOGUE_SERVICE:
            if (0)// (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, ) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_TC_SEL_ANALOGUE_SERVICE(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_TC_SELECT_DIGITAL_SERVICE:
            if (0)// (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, ) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_TC_SELECT_DIGITAL_SERVICE(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_TC_TUNER_DEVICE_STATUS:
            if (0)// (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, ) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_TC_TUNER_DEVICE_STATUS(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_TC_TUNER_STEP_DECREMENT:
            if (0)// (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, ) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_TC_TUNER_STEP_DECREMENT(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_TC_TUNER_STEP_INCREMENT:
            if (0)// (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, ) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_TC_TUNER_STEP_INCREMENT(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;
    #endif // #if TUNER_CONTROL_SUPPORT
    //----- Tuner Control end -----------


    #if VENDOR_SPECIFIC_SUPPORT
    //---------Vendor Specific -----------
        case E_MSG_VS_DEVICE_VENDOR_ID: // 0x87
            if (MApi_CEC_CheckFrame(E_TRANS_BROADCAST_MSG, 3) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_VS_DEVICE_VENDOR_ID(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_VS_GIVE_DEVICE_VENDOR_ID:   // 0x8C
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 2) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_VS_GIVE_DEVICE_VENDOR_ID(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_VS_VENDOR_COMMAND:
            if (0)// (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, ) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_VS_VENDOR_COMMAND(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_VS_VENDOR_COMMAND_WITH_ID:
            if (0)// ((MApi_CEC_CheckFrame(E_TRANS_BOTHTYPE_MSG, ) == 0) && (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, ) == 0) )
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_VS_VENDOR_COMMAND_WITH_ID(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_VS_VENDOR_REMOTE_BUTTON_DOWN:
            if (0)// ((MApi_CEC_CheckFrame(E_TRANS_BOTHTYPE_MSG, ) == 0) && (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, ) == 0) )
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_VS_VENDOR_REMOTE_BUTTON_DOWN(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_VS_VENDOR_REMOTE_BUTTON_UP:
            if (0)// ((MApi_CEC_CheckFrame(E_TRANS_BOTHTYPE_MSG, ) == 0) && (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, ) == 0) )
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_VS_VENDOR_REMOTE_BUTTON_UP(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;
    #endif // #if VENDOR_SPECIFIC_SUPPORT
    //----- Vendor Specific end -----------


    #if OSD_DISPLAY_SUPPORT
    //----- OSD Display ------------------
        case E_MSG_SET_OSD_STRING:
            if (0)// (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, ) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_SET_OSD_STRING(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;
    #endif // #if OSD_DISPLAY_SUPPORT
    //----- OSD Display end -----------


    #if DEVICE_OSD_NAME_TRANSFER_SUPPORT
    //----- Device OSD Name Transfer  ----
        case E_MSG_OSDNT_GIVE_OSD_NAME:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 2) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_OSDNT_GIVE_OSD_NAME(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_OSDNT_SET_OSD_NAME:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 3) == 0)    // at least 3 frames
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_OSDNT_SET_OSD_NAME(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

    #endif // #if DEVICE_OSD_NAME_TRANSFER_SUPPORT
    //----- Device OSD Name Transfer end -----------


    #if DEVICE_MENU_CONTROL_SUPPORT
    //----- Device Menu Control ----------
        case E_MSG_DMC_MENU_REQUEST:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 3) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_DMC_MENU_REQUEST(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_DMC_MENU_STATUS:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 3) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_DMC_MENU_STATUS(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;
    #endif // #if DEVICE_MENU_CONTROL_SUPPORT
    //----- Device Menu Control end -----------


    //----- Remote Control Passthrough ---
    //----- UI Message -------------------
    #if (DEVICE_MENU_CONTROL_SUPPORT || REMOTE_CONTROL_PASSTHROUGH_SUPPORT)
        case E_MSG_DMC_USER_CONTROL_PRESSED:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 3) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_DMC_USER_CONTROL_PRESSED(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_DMC_USER_CONTROL_RELEASED:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 2) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_DMC_USER_CONTROL_RELEASED(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;
    #endif // #if (DEVICE_MENU_CONTROL_SUPPORT || REMOTE_CONTROL_PASSTHROUGH_SUPPORT)
    //----- Remote Control Passthrough end -----------
    //----- UI Message end -----------


    //----- Power Status Support -----
    #if POWER_STATUS_SUPPORT
        case E_MSG_PS_GIVE_DEVICE_POWER_STATUS:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 2) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_PS_GIVE_DEVICE_POWER_STATUS(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

      case E_MSG_PS_REPORT_POWER_STATUS:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 3) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_PS_REPORT_POWER_STATUS(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;
    #endif // #if POWER_STATUS_SUPPORT
    //----- Power Status Support end ---------


    //----- System Audio Control ---------
    #if SYSTEM_AUDIO_CONTROL_SUPPORT
        case E_MSG_SAC_GIVE_AUDIO_STATUS:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 2) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_SAC_GIVE_AUDIO_STATUS(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            printf("[CEC] E_MSG_SAC_GIVE_AUDIO_STATUS(0x%x) \n", opcode);
            printf(" len   = 0x%x \n", len);
            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n");
            break;

        case E_MSG_SAC_GIVE_SYSTEM_AUDIO_MODE_STATUS:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 2) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_SAC_GIVE_SYSTEM_AUDIO_MODE_STATUS(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            printf("[CEC] E_MSG_SAC_GIVE_SYSTEM_AUDIO_MODE_STATUS(0x%x) \n", opcode);
            printf(" len   = 0x%x \n", len);
            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n");
            break;

        case E_MSG_SAC_REPORT_AUDIO_STATUS:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 3) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_SAC_REPORT_AUDIO_STATUS(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_SAC_SET_SYSTEM_AUDIO_MODE:
            // support Directly addressed and Broadcast both
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 3) == 0)
            {
                if (MApi_CEC_CheckFrame(E_TRANS_BROADCAST_MSG, 3) == 0)
                {
                    CEC_ERROR_DEBUG("[CEC] E_MSG_SAC_SET_SYSTEM_AUDIO_MODE(0x%x) Frame Fail \n", opcode);
                    bCheckFrameOK = FALSE;
                }
            }
            break;

        case E_MSG_SAC_SYSTEM_AUDIO_MODE_REQUEST:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 4) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_SAC_SYSTEM_AUDIO_MODE_REQUEST(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            printf("[CEC] E_MSG_SAC_SYSTEM_AUDIO_MODE_REQUEST(0x%x) \n", opcode);
            printf(" len   = 0x%x \n", len);
            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n");
            break;

        case E_MSG_SAC_SYSTEM_AUDIO_MODE_STATUS:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 3) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_SAC_SYSTEM_AUDIO_MODE_STATUS(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_SAC_SET_AUDIO_RATE:
            if (0)//MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, ) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_SAC_SET_AUDIO_RATE(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            printf("[CEC] E_MSG_SAC_SET_AUDIO_RATE(0x%x) \n", opcode);
            printf(" len   = 0x%x \n", len);
            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n");
            break;
    #endif // #if SYSTEM_AUDIO_CONTROL_SUPPORT
    //----- System Audio Control end ---------

    //----- Audio Return Channel Support ---------
    #if AUDIO_RETURN_CHANNEL_SUPPORT
        case E_MSG_ARC_INITIATE_ARC:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 2) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_ARC_INITIATE_ARC(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_ARC_REPORT_ARC_INITIATED:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 2) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_ARC_REPORT_ARC_INITIATED(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_ARC_REPORT_ARC_TERMINATED:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 2) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_ARC_REPORT_ARC_TERMINATED(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_ARC_REQUEST_ARC_INITIATION:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 2) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_ARC_REQUEST_ARC_INITIATION(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_ARC_REQUEST_ARC_TERMINATION:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 2) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_ARC_REQUEST_ARC_TERMINATION(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        case E_MSG_ARC_TERMINATE_ARC:
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 2) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_ARC_TERMINATE_ARC(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;
    #endif // #if AUDIO_RETURN_CHANNEL_SUPPORT
    //----- Audio Return Channel Support end ---------
#if (ENABLE_DOLBY_BULLETIN24)
        case E_MSG_SAC_REPORT_SHORT_AUDIO_DESCRIPTOR:
            if ((MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 5) == 0)
                ||(MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 8) == 0)
                ||(MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 11) == 0)
                ||(MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 14) == 0)
                )
            {
                break;
            }
            CEC_ERROR_DEBUG("[CEC] E_MSG_SAC_REPORT_SHORT_AUDIO_DESCRIPTOR(0x%x) Frame Fail \n", opcode);
            bCheckFrameOK = FALSE;
            break;
#endif
    //----- General Protocal Message -----
    #if GENERAL_PROTOCAL_SUPPORT
        //----- Feature Abort ----------------
        case E_MSG_FEATURE_ABORT:     //[DA],
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 4) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_FEATURE_ABORT(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;

        //----- Abort Message ----------------
        case E_MSG_ABORT_MESSAGE: //same as default, for testing
            if (MApi_CEC_CheckFrame(E_TRANS_DIRECT_MSG, 2) == 0)
            {
                CEC_ERROR_DEBUG("[CEC] E_MSG_ABORT_MESSAGE(0x%x) Frame Fail \n", opcode);
                bCheckFrameOK = FALSE;
            }
            break;
    #endif // #if GENERAL_PROTOCAL_SUPPORT
    //----- General Protocal Message end -----


        default:    //not support opcode
            CEC_ERROR_DEBUG("[CEC] Not Support opCode(0x%x) \n", opcode);
            if ( (header & 0x0F) != 0x0F ) //broadcast will not respond feature abort
            {
                msAPI_CEC_PostMsg_FeatureAbort(DIRECTMSG, enDevice, opcode, E_MSG_AR_UNRECOGNIZE_OPCDE);
            }
            break;
    }

    //***********************************************************************************

    // Frame Check OK
    if (bCheckFrameOK)
    {
        if (msAPI_CEC_IsDeviceExist(enDevice) == FALSE )
        {
            if (E_MSG_ABORT_MESSAGE !=  opcode )
            {
                msAPI_CEC_AddDevice(enDevice);
            }
        }

        u32CheckTime = msAPI_Timer_DiffTimeFromNow(u32StartTime);
        //printf("[TIME] CEC_ProcessCmd: %ld\n", u32CheckTime);

        switch (opcode)      //CEC1.3a Table 7 ~ 27
        {
        //----- One Touch Play ---------------
        #if ONE_TOUCH_PLAY_SUPPORT
            case E_MSG_OTP_IMAGE_VIEW_ON:     //if in standby, firstly power on
            {
                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_OTP_IMAGE_VIEW_ON(0x%x) \n", opcode);

                msAPI_CEC_SetActiveDevice(enDevice);

                // <Image View On>: Shoud not change TV menu or PIP status.
                break;
            }

            case E_MSG_OTP_TEXT_VIEW_ON:      //if in standby, firstly power on
            {
                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_OTP_TEXT_VIEW_ON(0x%x) \n", opcode);

                msAPI_CEC_SetActiveDevice(enDevice);  // anvi cec

                // <Text View On>: Should remove PIPs and menus form the screen.
                u8KeyCode = KEY_EXIT;

              #if ENABLE_ATSC
                if (!msAPI_CEC_IsByPass())
                {
                    MApp_ClosedCaption_Exit();
                    MApp_ZUI_ACT_ShutdownOSD();
                  #if ENABLE_DMP
                    if( IsStorageInUse())
                    {
                        MApp_DMP_Exit();
                    }
                  #endif
                }
              #endif
                break;
            }
        #endif // #if ONE_TOUCH_PLAY_SUPPORT
        //----- One Touch Play end ---------------

        //----- One Touch Play --------------
        //----- Routing Control --------------
        #if (ONE_TOUCH_PLAY_SUPPORT || ROUTING_CONTROL_SUPPORT)
            case E_MSG_ACTIVE_SOURCE:
            {
                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_ACTIVE_SOURCE(0x%x) \n", opcode);

                if (msAPI_CEC_IsByPass())
                {
                    CEC_DPUTSTR("Active source cmd is cec-by-pass\n");
                    break;
                }

                msAPI_CEC_SetPowerStatus(enDevice, E_MSG_PWRSTA_ON);

                msAPI_CEC_SetActiveDevice(enDevice);  // anvi cec start
                msAPI_CEC_SetActivePhyAddr((para0<<8|para1));

              #if ( INPUT_HDMI_VIDEO_COUNT )
                if(HIGHNIBBLE(para0) == 0x1)         //switch to HDMI1 input
                {
                    if (UI_INPUT_SOURCE_TYPE != UI_INPUT_SOURCE_HDMI)
                    {
                        CEC_DPUTSTR(" switch into HDMI1 \n");
                        MApp_CEC_InputSourceSwitchHDMI(UI_INPUT_SOURCE_HDMI);
                    }
                }
              #endif // #if ( INPUT_HDMI_VIDEO_COUNT )
              #if ( INPUT_HDMI_VIDEO_COUNT >= 2 )
                else if(HIGHNIBBLE(para0) == 0x2)    //switch to HDMI2 input
                {
                    if(UI_INPUT_SOURCE_TYPE != UI_INPUT_SOURCE_HDMI2)
                    {
                        CEC_DPUTSTR(" switch into HDMI2 \n");
                        MApp_CEC_InputSourceSwitchHDMI(UI_INPUT_SOURCE_HDMI2);
                    }
                }
              #endif // #if ( INPUT_HDMI_VIDEO_COUNT >= 2 )
              #if( INPUT_HDMI_VIDEO_COUNT >= 3 )
                else if(HIGHNIBBLE(para0) == 0x3)    //switch to HDMI3 input
                {
                    if(UI_INPUT_SOURCE_TYPE != UI_INPUT_SOURCE_HDMI3)
                    {
                        CEC_DPUTSTR(" switch into HDMI3 \n");
                        MApp_CEC_InputSourceSwitchHDMI(UI_INPUT_SOURCE_HDMI3);
                    }
                }
              #endif // #if( INPUT_HDMI_VIDEO_COUNT >= 3 )
              #if( INPUT_HDMI_VIDEO_COUNT >= 4 )
                else if(HIGHNIBBLE(para0) == 0x4)    //switch to HDMI3 input
                {
                    if(UI_INPUT_SOURCE_TYPE != UI_INPUT_SOURCE_HDMI4)
                    {
                        CEC_DPUTSTR(" switch into HDMI4 \n");
                        MApp_CEC_InputSourceSwitchHDMI(UI_INPUT_SOURCE_HDMI4);
                    }
                }
              #endif // #if( INPUT_HDMI_VIDEO_COUNT >= 4 )

            #if DEVICE_OSD_NAME_TRANSFER_SUPPORT
                if ( (enDevice != E_LA_BROADCAST) )
                {
                    msAPI_CEC_PostMsg_GiveOSDName(DIRECTMSG, enDevice);
                }
            #endif

                /*
                CEC compliance test 11.1.15-1: sends a correctly formateed <System Audio Mode Request> message.
                */
                if (stGenSetting.g_SoundSetting.TVspeakerMode == TVspeaker_Mode_ExtAmp)
                {
                    if ( msAPI_CEC_IsDeviceExist(E_LA_AUDIO_SYS) )
                    {
                        if ( (msAPI_CEC_GetDeviceIdx_PhyAddr(E_LA_AUDIO_SYS) & 0xF000) == ((para0<<8) & 0xF000 ) )
                            msAPI_CEC_PostMsg_SystemAudioModeReq(DIRECTMSG, (MS_U16)((para0<<8)|para1));
                    }
                }

            #if 0   // don't know the reason to do the following
                if ((enDevice != E_LA_AUDIO_SYS)&&(!gCECUserControlEnable))
                {
                    msAPI_CEC_PostMsg_MenuRequest(DIRECTMSG, enDevice, E_MSG_MENU_REQ_QUERY);
                }
            #endif

                break;
            }
        #endif // #if (ONE_TOUCH_PLAY_SUPPORT || ROUTING_CONTROL_SUPPORT)
        //----- One Touch Play end --------------
        //----- Routing Control end --------------


        //----- Routing Control --------------
        #if (ROUTING_CONTROL_SUPPORT)
            case E_MSG_RC_INACTIVE_SOURCE:
            {
                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_RC_INACTIVE_SOURCE(0x%x) \n", opcode);

                //broadcast, addressed, no para
                //cec anvi
                //VL++
                //_stCecApiInfo.ActivePhysicalAddress[0] = 0x0 ;
                //_stCecApiInfo.ActivePhysicalAddress[1] = 0x0 ;
                CEC_DPRINTF(" =E_MSG_RC_INACTIVE_SOURCE=, PHY= 0x%bx \n", para0);
                CEC_DPRINTF(" 0x%bx\r\n", para1);
                break;
            }

            case E_MSG_RC_REQ_ACTIVE_SOURCE:
            {
                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_RC_REQ_ACTIVE_SOURCE(0x%x) \n", opcode);

                if ( !IsHDMIInUse() )
                {
                    MS_U8 au8TxBuf[2];

                    au8TxBuf[0] = 0x00;
                    au8TxBuf[1] = 0x00;

                    msAPI_CEC_PostMsg_ActiveSource(POSTMSG, au8TxBuf);
                }
                break;
            }

            case E_MSG_RC_ROUTING_CHANGE:
            {
                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_RC_ROUTING_CHANGE(0x%x) \n", opcode);

                if ( !IsHDMIInUse() && (enDevice != E_LA_TV) )
                {
                    MS_U8 au8TxBuf[2];

                    au8TxBuf[0] = 0x00;
                    au8TxBuf[1] = 0x00;

                    msAPI_CEC_PostMsg_ActiveSource(POSTMSG, au8TxBuf);
                }

                break;
            }

            case E_MSG_RC_ROUTING_INFO:
            {
                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_RC_ROUTING_INFO(0x%x) \n", opcode);

                if (msAPI_CEC_IsDeviceExist(enDevice) == TRUE)
                {
                    MS_U8 au8TxBuf[2];

                    au8TxBuf[0] = para0;
                    au8TxBuf[1] = para1;

                    CEC_DPRINTF(" PhyAddr of hDevice 0x%x is changing \n", enDevice );
                    CEC_DPRINTF(" from [0x%x]", msAPI_CEC_GetDeviceIdx_PhyAddr(enDevice) );
                    msAPI_CEC_SetDeviceIdx_PhyAddr(enDevice, (para0<<8|para1));
                    CEC_DPRINTF(" to [0x%x] \n", msAPI_CEC_GetDeviceIdx_PhyAddr(enDevice) );

                    //VL++ fix CTS 9.4-2
                    msAPI_CEC_PostMsg_RoutingInformation(DIRECTMSG, au8TxBuf);
                }

                break;
            }

          #if 0 // not supported yet.
            case E_MSG_RC_SET_STREM_PATH:
            {
                CEC_DPRINTF("[CEC] E_MSG_RC_SET_STREM_PATH(0x%x) not Support \n", opcode);

                break;
            }
          #endif
        #endif // #if (ROUTING_CONTROL_SUPPORT)
        //----- Routing Control end --------------


        //----- Standby Command --------------
        #if STANDBY_COMMAND_SUPPORT
            case E_MSG_STANDBY:
            {
                MsCEC_MSG_POWER_STATUS_PARM enPowerStatus;

                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_STANDBY(0x%x) \n", opcode);

                enPowerStatus = msAPI_CEC_GetPowerStatus(E_LA_TV);

                /*
                CEC compliance test 11.1.3-2: responds to broadcast <Standby> messages.
                CEC compliance test 11.1.3-3: responds to directed <Standby> messages.
                */
                if ( enPowerStatus == E_MSG_PWRSTA_ON )    //when power on, not standby
                {
                    CEC_DPUTSTR(" =Standby= \n");
                    u8KeyCode = KEY_POWER;
                }
                break;
            }
        #endif // #if STANDBY_COMMAND_SUPPORT
        //----- Standby Command end --------------


        //----- One Touch Record--------------
        #if ONE_TOUCH_RECORD_SUPPORT
          #if 0 // not supported yet.
            case E_MSG_OTR_RECORD_ON:
            {
                CEC_DPRINTF("[CEC] E_MSG_OTR_RECORD_ON(0x%x) \n", opcode);
                break;
            }

            case E_MSG_OTR_RECORD_OFF:
            {
                CEC_DPRINTF("[CEC] E_MSG_OTR_RECORD_OFF(0x%x) \n", opcode);
                break;
            }
          #endif

            case E_MSG_OTR_RECORD_STATUS:
            {
                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_OTR_RECORD_STATUS(0x%x) \n", opcode);
                CEC_DPRINTF(" = RECORD_STATUS %bd = \n", para0);

                switch(para0)
                {
                    case E_MSG_RECORD_INFO_RECORDING_OWN_SOURCE:  // Recording currently selected source
                    case E_MSG_RECORD_INFO_RECORDING_DIGITAL_SERVICE:  // Recording Digital Service
                        gCECRecordEnable = TRUE;
                        CEC_DPRINTF(" CEC recording source is = %bx \n", para0);
                        break;

                    case E_MSG_RECORD_INFO_NO_RECORDING_DIGITAL_SERVICE:  // unable to record Digital Service, no suitable tuner.
                #if(HDMI_CEC_VERSION == CEC_VERSION_13a)
                    case E_MSG_RECORD_INFO_NO_RECORDING_ANALOGUE_SERVICE:  // unable to record Analogue Service, no suitable tuner.
                    case E_MSG_RECORD_INFO_NO_RECORDING_REQ_SERVICE:  // unable to select required service, Has suitable tuner, but the requested parameters are invalid or out of range for that tuner.
                    case E_MSG_RECORD_INFO_NO_RECORDING_INVALID_EXTERNAL_PLUG_NUMBER:  // invalid External plug number
                    case E_MSG_RECORD_INFO_NO_RECORDING_INVALID_EXTERNAL_PHYSICAL_ADDRESS:  // invalid External Physical Address
                    case E_MSG_RECORD_INFO_NO_RECORDING_CA_NOT_SUPPORT:  // CA system not supported
                    case E_MSG_RECORD_INFO_NO_RECORDING_CA_NO:  // No or Insufficient CA Entitlements
                    case E_MSG_RECORD_INFO_NO_RECORDING_COPY_NEVER:  // Not allowed to copy source, source is ¡§copy never¡¨.
                    case E_MSG_RECORD_INFO_NO_RECORDING_NO_FURTHER_COPY:  // No further copies allowed
                    case E_MSG_RECORD_INFO_NO_RECORDING_NOT_ENOUGH_SPACE:  // not enough space available
                    case E_MSG_RECORD_INFO_NO_RECORDING_PARENTAL_LOCK:  // Parental Lock On
                #endif
                    case E_MSG_RECORD_INFO_NO_RECORDING_NO_MEDIA:  // no media
                    case E_MSG_RECORD_INFO_NO_RECORDING_MEDIA_PROTECTED:  // media protected
                    case E_MSG_RECORD_INFO_NO_RECORDING_NO_SOURCE:  // no source signal
                    case E_MSG_RECORD_INFO_NO_RECORDING_OTHER_REASON:  // No recording ¡V other reason
                        gCECRecordEnable= FALSE;
                        CEC_DPRINTF(" CEC no recording, error code is = %bx \n", para0);
                        break;

                    case E_MSG_RECORD_INFO_NO_RECORDING_ALREADY_RECORDING:  // already recording
                        gCECRecordEnable= TRUE;
                        CEC_DPRINTF(" CEC already recording, error code is = %bx \n", para0);
                        break;

                    case E_MSG_RECORD_INFO_NO_RECORDING_PLAYING:  // Playing
                        gCECRecordEnable= FALSE;
                        CEC_DPRINTF(" CEC no recording, error code is = %bx \n", para0);
                        break;

                    case E_MSG_RECORD_INFO_NO_RECORDING_MEDIA_PROBLEM:  // media problem
                        gCECRecordEnable= FALSE;
                        CEC_DPRINTF(" CEC no recording, error code is = %bx \n", para0);
                        break;

                #if(HDMI_CEC_VERSION == CEC_VERSION_13a)
                    case E_MSG_RECORD_INFO_RECORDING_TERMINATED_NORMALLY:  // Recording terminated normally, can optionally be sent in response to a <Record Off> message.
                    case E_MSG_RECORD_INFO_RECORDING_ALREADY_TERMINATED:  // Recording has already terminated, can optionally be sent in response to a <Record Off> message.
                        gCECRecordEnable= FALSE;
                        CEC_DPRINTF(" CEC recording terminated status is = %bx \n", para0);
                        break;
                #endif

                    default:
                        CEC_DPRINTF(" CEC recording unknow state = %bx \n", para0);
                        break;
                }

                break;
            }

            // Initiate a recording using the <Record On> message, or send a <Feature Abort> [¡§Cannot provide source¡¨]
            // if the presently displayed source is not recordable.
            case E_MSG_OTR_RECORD_TV_SCREEN:
            {
                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_OTR_RECORD_TV_SCREEN(0x%x) \n", opcode);

                MsAPI_CEC_Msg_RecordOn(MApi_CEC_GetActiveLogicalAddress(), E_MSG_RECORD_TYPE_OWN_SOURCE);

                break;
            }
        #endif // #if ONE_TOUCH_RECORD_SUPPORT
        //----- One Touch Record end --------------


        //----- Timer programmer -------------
        #if TIMER_PROGRAMMER_SUPPORT
            case E_MSG_TP_CLEAR_ANALOG_TIMER:
            case E_MSG_TP_CLEAR_ANALOGUE_TIMER:
            case E_MSG_TP_CLEAR_EXTERNAL_TIMER:
            case E_MSG_TP_SET_ANALOGUE_TIMER:
            case E_MSG_TP_SET_DIGITAL_TIMER:
            case E_MSG_TP_SET_EXTERNAL_TIMER:
            case E_MSG_TP_SET_TIMER_PROGRAM_TITLE:
            case E_MSG_TP_TIMER_CLEARD_STATUS:
            case E_MSG_TP_TIMER_STATUS:
                break;
        #endif // #if TIMER_PROGRAMMER_SUPPORT
        //----- Timer programmer end -------------


        //----- System Information -----------
        //----- Vendor Specific -----------
        #if (SYSTEM_INFORMATION_SUPPORT | VENDOR_SPECIFIC_SUPPORT)
            case E_MSG_SI_CEC_VERSION:
            {
                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_SI_CEC_VERSION(0x%x) \n", opcode);

                msAPI_CEC_SetCecVersion(enDevice, para0);
                break;
            }

            case E_MSG_SI_GET_CEC_VERSION:
            {
                //MS_U8 u8Version;
                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_SI_GET_CEC_VERSION(0x%x) \n", opcode);

                msAPI_CEC_PostMsg_CECVersion(DIRECTMSG, enDevice, _stMsApiCecInfoList.u8CECVersion[E_LA_TV]);
                break;
            }
        #endif // #if (SYSTEM_INFORMATION_SUPPORT | VENDOR_SPECIFIC_SUPPORT)
        //----- System Information end -----------
        //----- Vendor Specific end -----------


        //----- System Information -----------
        #if SYSTEM_INFORMATION_SUPPORT
            case E_MSG_SI_GIVE_PHYSICAL_ADDRESS:
            {
                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_SI_GIVE_PHYSICAL_ADDRESS(0x%x) \n", opcode);

                msAPI_CEC_PostMsg_ReportPhysicalAddress(DIRECTMSG);
                break;
            }

            case E_MSG_SI_REPORT_PHYSICAL_ADDRESS:
            {
                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_SI_REPORT_PHYSICAL_ADDRESS(0x%x) \n", opcode);

                msAPI_CEC_SetDeviceIdx_PhyAddr(enDevice, (U16)((para0<<8) | para1));
                msAPI_CEC_SetDeviceType(enDevice, (MsCEC_DEVICE_TYPE)para2);

//                MApi_CEC_SetActivePhysicalAddress(para0, para1);
//                CEC_DPRINTF(" SetActivePhysicalAddress : 0x%x \n", (para0<<8|para1));

//                MApi_CEC_SetActiveDeviceType((MsCEC_DEVICE_TYPE) para2);
//                CEC_DPRINTF(" SetActiveDeviceType : 0x%x \n", para2);

                if ( (enDevice != E_LA_BROADCAST))
                {
                  #if VENDOR_SPECIFIC_SUPPORT
                    msAPI_CEC_PostMsg_GiveDeviceVendorID(DIRECTMSG, enDevice);
                  #endif

                  #if (SYSTEM_INFORMATION_SUPPORT | VENDOR_SPECIFIC_SUPPORT)
                    msAPI_CEC_PostMsg_GetCECVersion(DIRECTMSG, enDevice);
                  #endif

                  #if DEVICE_OSD_NAME_TRANSFER_SUPPORT
                    msAPI_CEC_PostMsg_GiveOSDName(DIRECTMSG, enDevice);
                  #endif
                }

            #if 0
                if ( ( (UI_INPUT_SOURCE_TYPE == UI_INPUT_SOURCE_HDMI) && (HIGHNIBBLE(para0)  == 0x01) )
                  #if( INPUT_HDMI_VIDEO_COUNT >= 2 )
                   ||( (UI_INPUT_SOURCE_TYPE == UI_INPUT_SOURCE_HDMI2) && (HIGHNIBBLE(para0)  == 0x02))
                  #endif
                  #if( INPUT_HDMI_VIDEO_COUNT >= 3 )
                   ||( (UI_INPUT_SOURCE_TYPE == UI_INPUT_SOURCE_HDMI3) && (HIGHNIBBLE(para0)  == 0x03))
                  #endif
                  #if( INPUT_HDMI_VIDEO_COUNT >= 4 )
                   ||( (UI_INPUT_SOURCE_TYPE == UI_INPUT_SOURCE_HDMI4) && (HIGHNIBBLE(para0)  == 0x04))
                  #endif
                   )
                {
                    MS_U8 au8TxBuf[2];

                    au8TxBuf[0] = para0;
                    au8TxBuf[1] = para1;

                    msAPI_CEC_PostMsg_SetStreamPath(DIRECTMSG, au8TxBuf);
                }

                if ( (enDevice != E_LA_AUDIO_SYS) && (!gCECUserControlEnable) )
                {
                    msAPI_CEC_PostMsg_MenuRequest(DIRECTMSG, enDevice, E_MSG_MENU_REQ_QUERY)
                }
            #endif

                /*
                CEC compliance test 11.1.15-4: issues a <Give System Audio Mode Status> message to the amplifier.
                */
                if ( (enDevice == E_LA_AUDIO_SYS)
                   &&(stGenSetting.g_SoundSetting.TVspeakerMode == TVspeaker_Mode_ExtAmp)
                   )
                {
                    msAPI_CEC_PostMsg_GiveSystemAudioModeStatus(POSTMSG, E_LA_AUDIO_SYS);
                }


                /*
                CEC compliance test 11.1.15-5: respond with <System Audio Mode Request> message to the amplifier.
                */
				if ((enDevice == E_LA_AUDIO_SYS) && (stGenSetting.stHDMISetting.g_enHDMIARC==DISABLE))
				{
					msAPI_CEC_PostMsgToQueue(E_LA_AUDIO_SYS, E_MSG_SAC_SYSTEM_AUDIO_MODE_REQUEST, 0, 0);
				}


                msAPI_CEC_ReportDevice();
                msAPI_CEC_CheckActiveDevice();
                break;
            }

            case E_MSG_SI_GET_MENU_LANGUAGE:
            {
                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_SI_GET_MENU_LANGUAGE(0x%x) \n", opcode);

                /*
                   fixed 11.1.6-5 Ensure that the DUT responds correctly to a <Get Menu Language> message
                   with a different version number to that it holds, coming from various logical addresses
                   including the unregistered address.
                */

            EN_LANGUAGE eLanguage;
            U8 u8CecLangCode[MAX_ISO639CODE_LENGTH] = { 0 };

            eLanguage = MApp_GetMenuLanguage();

            if ( MApp_GetOSDLangCodeFromIndex(eLanguage, u8CecLangCode)==TRUE)
            {
                msAPI_CEC_PostMsg_SetMenuLang(DIRECTMSG, u8CecLangCode);
            }


                break;
            }

            case E_MSG_SI_SET_MENU_LANGUAGE:
            {
                break;
            }

          #if 0 // not supported yet.
            case E_MSG_SI_POLLING_MESSAGE:
                    break;
          #endif
        #endif // #if SYSTEM_INFORMATION_SUPPORT
        //----- System Information end -----------


        //----- Deck Control Feature----------
        #if DECK_CONTROL_SUPPORT
            case E_MSG_DC_DECK_STATUS:
            {
                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_DC_DECK_STATUS(0x%x) \n", opcode);

                gCECDeckStatus = (MsCEC_MSG_DC_DECK_STATUS_PARM) para0;

                break;
            }

          #if 0 // not supported yet.
            case E_MSG_DC_DECK_CONTROL:
            case E_MSG_DC_GIVE_DECK_STATUS:
            case E_MSG_DC_PLAY:
            {
                break;
            }
          #endif
        #endif
        //----- Deck Control end -----------


        //----- Tuner Control ----------------
        #if TUNER_CONTROL_SUPPORT
            case E_MSG_TC_GIVE_TUNER_DEVICE_STATUS:
            case E_MSG_TC_SEL_ANALOGUE_SERVICE:
            case E_MSG_TC_SELECT_DIGITAL_SERVICE:
            case E_MSG_TC_TUNER_DEVICE_STATUS:
            case E_MSG_TC_TUNER_STEP_DECREMENT:
            case E_MSG_TC_TUNER_STEP_INCREMENT:
            {
                break;
            }
        #endif
        //----- Tuner Control end -----------


        //---------Vendor Specific -----------
        #if VENDOR_SPECIFIC_SUPPORT
            case E_MSG_VS_DEVICE_VENDOR_ID:
            {
                MS_U8 txbuf[3];

                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_VS_DEVICE_VENDOR_ID(0x%x) \n", opcode);

                txbuf[0] = para0;
                txbuf[1] = para1;
                txbuf[2] = para2;

                msAPI_CEC_SetDeviceVendorID(enDevice, txbuf);
                break;
            }

            case E_MSG_VS_GIVE_DEVICE_VENDOR_ID:
            {
                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_VS_GIVE_VENDOR_ID(0x%x) \n", opcode);

                msAPI_CEC_PostMsg_DeviceVendorID(DIRECTMSG, enDeviceDst);
                break;
            }

            case E_MSG_VS_VENDOR_COMMAND:
            case E_MSG_VS_VENDOR_COMMAND_WITH_ID:
            case E_MSG_VS_VENDOR_REMOTE_BUTTON_DOWN:
            case E_MSG_VS_VENDOR_REMOTE_BUTTON_UP:
            {
                break;
            }
        #endif // #if VENDOR_SPECIFIC_SUPPORT
        //----- Vendor Specific end -----------


        //----- OSD Display ------------------
        #if OSD_DISPLAY_SUPPORT
            case E_MSG_SET_OSD_STRING:
            {
                break;
            }
        #endif
        //----- OSD Display end -----------


        //----- Device OSD Name Transfer  ----
        #if DEVICE_OSD_NAME_TRANSFER_SUPPORT
            case E_MSG_OSDNT_GIVE_OSD_NAME:
            {
//                CEC_DPRINTF("*CEC*:E_MSG_OSDNT_GIVE_OSD_NAME(0x%x) \n", opcode);
                break;
            }

            case E_MSG_OSDNT_SET_OSD_NAME:
            {
                U8 u8NameLen, au8StringBuffer[13];

                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_OSDNT_SET_OSD_NAME(0x%x) \n", opcode);

                memset(&au8StringBuffer, 0x00, 13);

                if(len> 2 && para0!=0)
                {
                    for(u8NameLen=0;u8NameLen<(len-2);u8NameLen++)
                    {
                        au8StringBuffer[u8NameLen] = MApi_CEC_GetRxData( MApi_CEC_GetFifoIdx(), u8NameLen+2);
                    }
                    au8StringBuffer[u8NameLen]= '\0';

                    //printf(" %s \n", au8StringBuffer);

                    msAPI_CEC_SetDeviceName(enDevice, (U8*)&au8StringBuffer, FALSE);
                }
                else
                {
                    msAPI_CEC_SetDeviceName(enDevice, NULL, TRUE);
                }

                break;
            }
        #endif // #if DEVICE_OSD_NAME_TRANSFER_SUPPORT
        //----- Device OSD Name Transfer end -----------


        //----- Device Menu Control ----------
        #if DEVICE_MENU_CONTROL_SUPPORT
//            case E_MSG_DMC_MENU_REQUEST:
//                break;

            case E_MSG_DMC_MENU_STATUS:
            {
                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_DMC_MENU_STATUS(0x%x) \n", opcode);
            #if 1
                /*
                   CEC Table 27 Message dependencies when receiving a message
                   If device does not <Feature Abort> "Unrecognized opcode" with <Menu Request>
                   It shall not <Feature Abort> "Unrecognized opcode" with
                    <User Control Pressed> and <User Control Released>
                */
                gCECUserControlEnable = TRUE;
            #else
                switch(para0)
                {
                    case E_MSG_MENU_ACTIVATED:
                        gCECUserControlEnable = TRUE;
                        break;
                    case E_MSG_MENU_DEACTIVATED:
                        gCECUserControlEnable = FALSE;
                        break;
                }
            #endif
                break;
            }
        #endif
        //----- Device Menu Control end -----------


        //----- Remote Control Passthrough ---
        //----- UI Message -------------------
        #if (DEVICE_MENU_CONTROL_SUPPORT || REMOTE_CONTROL_PASSTHROUGH_SUPPORT)
            case E_MSG_DMC_USER_CONTROL_PRESSED:
            {
                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_DMC_USER_CONTROL_PRESSED(0x%x) \n", opcode);

                CEC_DPRINTF(" = UI_Press (0x%x) = \n", para0);

                switch(para0)   //UI command
                {
                    case E_MSG_UI_SUB_PICTURE:  //PIP
                      #if (IR_TYPE_SEL != IR_TYPE_CUS21SH)
                        IR_CODE = IRKEY_PICTURE;
                        g_bIrDetect = TRUE;
                      #endif
                        break;

                    case E_MSG_UI_LEFT:
                        IR_CODE = IRKEY_LEFT;
                        g_bIrDetect = TRUE;
                        break;

                    case E_MSG_UI_UP:
                        IR_CODE = IRKEY_UP;
                        g_bIrDetect = TRUE;
                        break;

                    case E_MSG_UI_ROOTMENU:
                        IR_CODE = IRKEY_MENU;
                        g_bIrDetect = TRUE;
                        break;

                    case E_MSG_UI_DOWN:
                        IR_CODE = IRKEY_DOWN;
                        g_bIrDetect = TRUE;
                        break;

                    case E_MSG_UI_RIGHT:
                        IR_CODE = IRKEY_RIGHT;
                        g_bIrDetect = TRUE;
                        break;

                    case E_MSG_UI_SELECT:
                        IR_CODE = IRKEY_INPUT_SOURCE;
                        g_bIrDetect = TRUE;
                        break;

                    case E_MSG_UI_POWER:
                    case E_MSG_UI_POWER_ON_FUN:               //Panasonic DVD-S53 think only as power on
                        CEC_DPRINTF(" =E_MSG_UI_POWER= %bd \n", MApi_CEC_GetPowerStatus());
                        if(MApi_CEC_GetPowerStatus() == E_MSG_PWRSTA_STANDBY)
                        {
                            IR_CODE = IRKEY_POWER;
                            g_bIrDetect = TRUE;
                        }
                        break;

                    case E_MSG_UI_NUMBER_0:
                        IR_CODE = IRKEY_NUM_0;
                        g_bIrDetect = TRUE;
                        break;

                    case E_MSG_UI_NUMBER_1:
                        IR_CODE = IRKEY_NUM_1;
                        g_bIrDetect = TRUE;
                        break;

                    case E_MSG_UI_NUMBER_2:
                        IR_CODE = IRKEY_NUM_2;
                        g_bIrDetect = TRUE;
                        break;

                    case E_MSG_UI_NUMBER_3:
                        IR_CODE = IRKEY_NUM_3;
                        g_bIrDetect = TRUE;
                        break;

                    case E_MSG_UI_NUMBER_4:
                        IR_CODE = IRKEY_NUM_4;
                        g_bIrDetect = TRUE;
                        break;

                    case E_MSG_UI_NUMBER_5:
                        IR_CODE = IRKEY_NUM_5;
                        g_bIrDetect = TRUE;
                        break;

                    case E_MSG_UI_NUMBER_6:
                        IR_CODE = IRKEY_NUM_6;
                        g_bIrDetect = TRUE;
                        break;

                    case E_MSG_UI_NUMBER_7:
                        IR_CODE = IRKEY_NUM_7;
                        g_bIrDetect = TRUE;
                        break;

                    case E_MSG_UI_NUMBER_8:
                        IR_CODE = IRKEY_NUM_8;
                        g_bIrDetect = TRUE;
                        break;

                    case E_MSG_UI_NUMBER_9:
                        IR_CODE = IRKEY_NUM_9;
                        g_bIrDetect = TRUE;
                        break;

                    case E_MSG_UI_DISPLAY_INFO:
                        IR_CODE = IRKEY_INFO;
                        g_bIrDetect = TRUE;
                        break;

                    case E_MSG_UI_MUTE:
                        IR_CODE = IRKEY_MUTE;
                        g_bIrDetect = TRUE;
                        break;

                    case E_MSG_UI_VOLUME_UP:
                        IR_CODE = IRKEY_VOLUME_PLUS;
                        g_bIrDetect = TRUE;
                        break;

                    case E_MSG_UI_VOLUME_DOWN:
                        IR_CODE = IRKEY_VOLUME_MINUS;
                        g_bIrDetect = TRUE;
                        break;

                    case E_MSG_UI_CHANNEL_UP:
                        IR_CODE = IRKEY_CHANNEL_PLUS;
                        g_bIrDetect = TRUE;
                        break;

                    case E_MSG_UI_CHANNEL_DOWN:
                        IR_CODE = IRKEY_CHANNEL_MINUS;
                        g_bIrDetect = TRUE;
                        break;

                    default:    //UI command, no support parameter,need abort a reason, REFUSED reason, or ignore
                        IR_CODE = IRKEY_DUMY;
                        g_bIrDetect = TRUE;
                        msAPI_CEC_PostMsg_FeatureAbort(DIRECTMSG, MApi_CEC_GetActiveLogicalAddress(), opcode, E_MSG_AR_REFUSED);
                        break;
                }

                break;
            }

            case E_MSG_DMC_USER_CONTROL_RELEASED:
                    break;
        #endif // #if (DEVICE_MENU_CONTROL_SUPPORT || REMOTE_CONTROL_PASSTHROUGH_SUPPORT)
        //----- Remote Control Passthrough end -----------
        //----- UI Message end -----------


        //----- Power Status Support -----
        #if POWER_STATUS_SUPPORT
            case E_MSG_PS_GIVE_DEVICE_POWER_STATUS:
            {
                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_PS_GIVE_DEVICE_POWER_STATUS(0x%x) \n", opcode);

                msAPI_CEC_PostMsg_ReportPowerStatus(DIRECTMSG, enDevice, msAPI_CEC_GetPowerStatus(E_LA_TV));
                break;
            }

            case E_MSG_PS_REPORT_POWER_STATUS:
            {
                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_PS_REPORT_POWER_STATUS(0x%x) \n", opcode);

                msAPI_CEC_SetPowerStatus(enDevice, (MsCEC_MSG_POWER_STATUS_PARM) para0);

                if (gCECQueryPowerFlag)
                {
                    IR_CODE = IRKEY_POWER;
                    g_bIrDetect = TRUE;
                }
                break;
            }
        #endif // #if POWER_STATUS_SUPPORT
        //----- Power Status Support end ---------


        //----- System Audio Control ---------
        #if SYSTEM_AUDIO_CONTROL_SUPPORT
            case E_MSG_SAC_GIVE_AUDIO_STATUS:
            case E_MSG_SAC_GIVE_SYSTEM_AUDIO_MODE_STATUS:
                break;

            case E_MSG_SAC_REPORT_AUDIO_STATUS:
            {
                MS_U8 u8AudioMute;
                MS_U8 u8AudioVolumeLevel;

                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_SAC_REPORT_AUDIO_STATUS(0x%x) \n", opcode);

                u8AudioMute        = para0 & 0x80;
                u8AudioVolumeLevel = para0 & 0x7F;
                CEC_DPRINTF(" Aduio Mute %s,", (u8AudioMute)?("On"):("Off"));
                CEC_DPRINTF(" Volume level: %d% \n", u8AudioVolumeLevel);
                ARCAudioVolume = u8AudioVolumeLevel;
                ARCAMPIsMute = (u8AudioMute)?TRUE:FALSE;

                if (stGenSetting.g_SoundSetting.TVspeakerMode != TVspeaker_Mode_ExtAmp)
                {
                    CEC_DPUTSTR(" Ignored \n"); // ignored message
                    break;
                }

                if (u8KeyCode == KEY_NULL)
                {
                    u8KeyCode = KEY_VOLUME_MINUS;   //assign a key in order to draw volume OSD, mantis: 0794921
                }
                msAPI_CEC_SaveAmpControlVolume(para0);
                break;
            }

            case E_MSG_SAC_SET_SYSTEM_AUDIO_MODE:
            {
                BOOLEAN bAudioMode;

                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_SAC_SET_SYSTEM_AUDIO_MODE(0x%x) \n", opcode);

                bAudioMode = (para0 & 0x01);
                CEC_DPRINTF(" Sys. Aduio Status: %s \n", (bAudioMode)?("On"):("Off"));

                if (stGenSetting.g_SoundSetting.TVspeakerMode != TVspeaker_Mode_ExtAmp)
                {
                    if (enDeviceDst == E_LA_BROADCAST)
                    {
                        if (bAudioMode == 1)
                        {
                            // Terminate System Audio Mode because "Speaker Mode" is not "ExtAmp"
                            msAPI_CEC_PostMsg_SystemAudioModeRequestTerminationRequest(POSTMSG);
                        }
                        CEC_DPUTSTR(" Ignored \n"); // ignored message
                    }
                    else
                    {
                        //msAPI_CEC_PostMsg_FeatureAbort(DIRECTMSG, E_LA_AUDIO_SYS, opcode, E_MSG_AR_REFUSED);    //CED 13.15.2, Reply Amp <Feature Abort> for <Set System Audio Mode> ["On"], Amp will abandons the feature
                        CEC_DPUTSTR(" Not in correct mode to respond \n");
                    }
                    break;
                }

                if (bAudioMode)//Amp
                {
                    if(msAPI_AUD_IsAudioMutedByUser()==FALSE)
                    {
                        msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYUSER_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                    }
                }
                else//TV
                {
                    if(msAPI_AUD_IsAudioMutedByUser()==TRUE)
                    {
                        msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYUSER_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                    }
                }

                if(bAudioMode != msAPI_CEC_QuerySystemAudioMode())
                {
                    msAPI_CEC_PostMsg_GiveAudioStatus(POSTMSG, E_LA_AUDIO_SYS);
                }

                msAPI_CEC_SetSystemAudioMode(bAudioMode);
                break;
            }

          #if 0 // not supported yet.
            case E_MSG_SAC_SYSTEM_AUDIO_MODE_REQUEST:
            {
                CEC_DPRINTF("[CEC] E_MSG_SAC_SYSTEM_AUDIO_MODE_REQUEST(0x%x) \n", opcode);
                break;
            }
          #endif

            case E_MSG_SAC_SYSTEM_AUDIO_MODE_STATUS:
            {
                BOOLEAN bAudioMode;

                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_SAC_SYSTEM_AUDIO_MODE_STATUS(0x%x) \n", opcode);

                bAudioMode = (para0 & 0x01);
                CEC_DPRINTF(" Sys. Aduio Status: %s \n", (bAudioMode)?("On"):("Off"));

                if (stGenSetting.g_SoundSetting.TVspeakerMode != TVspeaker_Mode_ExtAmp)
                {
                    CEC_DPUTSTR(" Not in correct mode to respond \n");
                    break;
                }

                msAPI_CEC_SetSystemAudioMode(bAudioMode);

                if (bAudioMode)   //Amp
                {
                    if(msAPI_AUD_IsAudioMutedByUser()==FALSE)
                    {
                        msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYUSER_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                    }
                }
                else//TV
                {
                    if(msAPI_AUD_IsAudioMutedByUser()==TRUE)
                    {
                        msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYUSER_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                    }
                }

                break;
            }

          #if 0 // not supported yet.
            case E_MSG_SAC_SET_AUDIO_RATE:
            {
                CEC_DPRINTF("[CEC] E_MSG_SAC_SET_AUDIO_RATE(0x%x) \n", opcode);
                break;
            }
          #endif
        #endif // #if SYSTEM_AUDIO_CONTROL_SUPPORT
        //----- System Audio Control end ---------


        //----- Audio Return Channel Support ---------
        #if AUDIO_RETURN_CHANNEL_SUPPORT
            case E_MSG_ARC_INITIATE_ARC:
            {
                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_ARC_INITIATE_ARC(0x%x) \n", opcode);

                if ((DB_HDMI_SETTING.g_enHDMIARC == DISABLE)
                    || (msAPI_CEC_GetDeviceIdx_PhyAddr(E_LA_AUDIO_SYS) != CEC_ARC_PA)     //CTS 11.1.17-5/6, only support in ARC port
                    )
                    break;

                gIsCECAmpARCOn = TRUE;

                MApp_CEC_ARC_TX_Control(TRUE);
								#ifdef sNewAudioMuteStyle
								msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, 0, 0);
								#else
    		        MUTE_On();
		            #endif
                msAPI_CEC_PostMsg_ReportARCInitiated(DIRECTMSG, enDevice);
                break;
            }

            case E_MSG_ARC_TERMINATE_ARC:
            {
                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_ARC_TERMINATE_ARC(0x%x) \n", opcode);

                //if (DB_HDMI_SETTING.g_enHDMIARC == DISABLE)
                    //break;

                //Power off ARC
                //ARC_CTRL_OFF();
                CEC_DPRINTF(" Address() = %bx \n", (U16)msAPI_CEC_GetActiveDevice());

                MApp_CEC_ARC_TX_Control(FALSE);
								#ifdef sNewAudioMuteStyle
								msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, stGenSetting.g_SoundSetting.Volume, 0);
								#else
								MUTE_Off();
								#endif

                if (DB_HDMI_SETTING.g_enHDMIARC == ENABLE)
                {
                    DB_HDMI_SETTING.g_enHDMIARC =DISABLE;
                }

                msAPI_CEC_PostMsg_ReportARCTerminated(DIRECTMSG, enDevice);

                break;
            }
        #endif // #if AUDIO_RETURN_CHANNEL_SUPPORT
        //----- Audio Return Channel Support end ---------
#if (ENABLE_DOLBY_BULLETIN24)
            case E_MSG_SAC_REPORT_SHORT_AUDIO_DESCRIPTOR:
            {
#define MAX_SAD_LEN 12
                U8 u8SADBuffer[MAX_SAD_LEN];

                memset(u8SADBuffer, 0x00, MAX_SAD_LEN);

                if(len> 2 && para0!=0)
                {
                    U8 idx = 0;
                    for(idx=2;idx<len;idx++)
                    {
                        u8SADBuffer[idx-2] = MApi_CEC_GetRxData( MApi_CEC_GetFifoIdx(), idx);
                    }
                    msAPI_DolbyBulletin24_receive_SAD(u8SADBuffer, (len-2));
                }
            }
            break;
#endif

        //----- General Protocal Message -----
        #if GENERAL_PROTOCAL_SUPPORT
            //----- Feature Abort ----------------
            case E_MSG_FEATURE_ABORT:     //[DA],
            {
                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_FEATURE_ABORT(0x%x) \n", opcode);

                msAPI_CEC_HandleFeatureAbort(enDevice, enDeviceDst, para0, para1);
                break;
            }

            //----- Abort Message ----------------
            case E_MSG_ABORT_MESSAGE: //same as default, for testing
            {
                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] E_MSG_ABORT_MESSAGE(0x%x) \n", opcode);

              #if 0 // no need, should be updated in CEC library
                /*
                CEC compliance test 9.7-1: waits for at least 5 bit periods
                                           before transmitting a new message.
                5 bit periods are about 12.0ms.
                */
                MsOS_DelayTask(5);
              #endif

                msAPI_CEC_PostMsg_FeatureAbort(DIRECTMSG, enDevice, opcode, E_MSG_AR_REFUSED);
                break;
            }
        #endif // #if GENERAL_PROTOCAL_SUPPORT
        //----- General Protocal Message end -----

            default:    //not support opcode
            {
                CEC_DPRINTF("%lu ", __LINE__);
                CEC_DPRINTF("[CEC] Not Support opCode(0x%x) \n", opcode);

            #if (DEVICE_OSD_NAME_TRANSFER_SUPPORT==0)
                //Fixed 9.5-1 Fail SYSTEM: The DUT shall not respond with <Feature Abort>.
                if(opcode == E_MSG_OSDNT_SET_OSD_NAME || opcode == E_MSG_OSDNT_GIVE_OSD_NAME)
                {
                    break;
                }
            #endif

                msAPI_CEC_PostMsg_FeatureAbort(DIRECTMSG, enDevice, opcode, E_MSG_AR_UNRECOGNIZE_OPCDE);

                break;
            }
        }//switch end

      #if CEC_STATE_MACHINE
        CEC_State_header = header;
        CEC_State_opcode = opcode;
      #endif
    }

    u8Fifoidx = MApi_CEC_GetFifoIdx();

    if((u8Fifoidx+1)>=CEC_FIFO_CNT)
        MApi_CEC_SetFifoIdx(0);
    else
        MApi_CEC_SetFifoIdx(u8Fifoidx+1);

    MApi_CEC_SetMsgCnt(MApi_CEC_GetMsgCnt() - 1);

    CEC_DPUTSTR(" ---------- \n");

}

void msAPI_CEC_ProcessTxMsg(void)
{
    static CECMSG _stCecMsg;
    static BOOLEAN _bCecTxChkStatus = FALSE;

    if (msAPI_CEC_GetMsgInQueue(&_stCecMsg))
    {
        CEC_ERROR_CODE res;

        res = msAPI_CEC_PostMsg(_stCecMsg.enDevice, _stCecMsg.enOpcode, _stCecMsg.au8Operand, _stCecMsg.u8Len);

        _bCecTxChkStatus = TRUE;

      #if 0 // can't just add/remove device, will cause some CEC compliance test fail.
        if (res & E_CEC_TX_SUCCESS)
        {
            msAPI_CEC_AddDevice(_stCecMsg.enDevice);
        }
        else
        {
          #if CEC_DEBUG
            printf("TxMsg 0x%x ", _stCecMsg.enDevice);
            printf("with opCode 0x%x Fail \n", _stCecMsg.enOpcode);
          #endif

            msAPI_CEC_RemoveDevice(_stCecMsg.enDevice);
        }
      #endif
    }
    else
    {
        msAPI_CEC_PollingDevice();
    }
}

MS_U8 msAPI_CEC_DeviceRecognition1_Ping(MS_BOOL bCecDevices1[E_LA_MAX])
{
    MsCEC_DEVICELA i = E_LA_TV;
    MS_U8 res = 0;
    MS_U8 u8DeviceCount = 0;

    for (i=E_LA_TV; i<E_LA_UNREGISTERED; i++)
    {
        res = msAPI_CEC_PingDevice(i);

        if (res & E_CEC_TX_SUCCESS)
        {
            bCecDevices1[i] = TRUE;
            u8DeviceCount++;
        }
    }

#if CEC_DEBUG
    printf("\r\n >> msAPI_CEC_DeviceRecognition1 (%d) \n", u8DeviceCount);

    for (i=E_LA_TV; i<E_LA_UNREGISTERED; i++)
    {
        if ( bCecDevices1[i] == TRUE )
        {
            printf(" Ping [0x%x] OK \n", i);
        }
    }
    printf("\n");
#endif

    return u8DeviceCount;
}

void msAPI_CEC_DeviceRecognition_GivePhysicalAddress(MS_BOOL bCecDevices2[E_LA_MAX])
{
    MsCEC_DEVICELA i = E_LA_TV;

#if CEC_DEBUG
    printf("\r\n >> msAPI_CEC_DeviceRecognition_GivePhysicalAddress \n");
#endif

    for (i=E_LA_TV; i<E_LA_UNREGISTERED; i++)
    {
        if ( bCecDevices2[i] == TRUE )
        {
            msAPI_CEC_PostMsg_GivePhysicalAddress(DIRECTMSG, i);
        }
    }
}

void msAPI_CEC_DeviceRecognition_GiveDevicePowerStatus(MS_BOOL bCecDevices2[E_LA_MAX])
{
    MsCEC_DEVICELA i = E_LA_TV;

#if CEC_DEBUG
    printf("\r\n >> msAPI_CEC_DeviceRecognition_GiveDevicePowerStatus \n");
#endif

    for (i=E_LA_TV; i<E_LA_UNREGISTERED; i++)
    {
        if ( bCecDevices2[i] == TRUE )
        {
            msAPI_CEC_PostMsg_GiveDevicePowerStatus(DIRECTMSG, i);
        }
    }
}

void msAPI_CEC_InitCecStructure(void)
{
    MsCEC_DEVICELA _enDeviceIdex = E_LA_TV;

    memset(&_stMsApiCecInfoList, 0, sizeof(MSAPI_CEC_INFO_LIST));

    _stMsApiCecInfoList.u8CecDeviceCount = 0;
    _stMsApiCecInfoList.enActiveDeviceLA = E_LA_TV;

#if IF_NO_OSD_NAME_USE_DEFAULT_NAME
    msAPI_CEC_LoadDefaultDeviceName(stGenSetting.g_SysSetting.Language);
#else
    for (_enDeviceIdex=E_LA_TV; _enDeviceIdex<E_LA_UNREGISTERED; _enDeviceIdex++)
    {
        memset(_stMsApiCecInfoList.u8CecDeviceName[_enDeviceIdex], 0x00, MAX_CEC_DEVICE_OSD_NAME);
    }
#endif

    for (_enDeviceIdex=E_LA_TV; _enDeviceIdex<E_LA_UNREGISTERED; _enDeviceIdex++)
    {
        _stMsApiCecInfoList.bCecDevicesExisted[_enDeviceIdex] = FALSE;

        _stMsApiCecInfoList.u16PhysicalAddress[_enDeviceIdex] = 0x0000;

        _stMsApiCecInfoList.u8CecVendorID[_enDeviceIdex][0] = 0x00;
        _stMsApiCecInfoList.u8CecVendorID[_enDeviceIdex][1] = 0x00;
        _stMsApiCecInfoList.u8CecVendorID[_enDeviceIdex][2] = 0x00;

        _stMsApiCecInfoList.u8CECVersion[_enDeviceIdex] = 0xFF;

        _stMsApiCecInfoList.enDeviceType[_enDeviceIdex] = E_DEVICE_TYPE_TV;
    }

    for (_enDeviceIdex=E_LA_RECORDER1; _enDeviceIdex<E_LA_MAX; _enDeviceIdex++)
    {
        _stMsApiCecInfoList.enPowerStatus[_enDeviceIdex] = E_MSG_PWRSTA_UNKNOW;
    }
}

void msAPI_CEC_InitVariable(void)
{
    gCECRecordEnable = FALSE;
    gCECUserControlEnable = FALSE;
    gCECQueryPowerFlag = FALSE;

    g_bCecForceImmediatelyPolling = FALSE;
    _bStartPolling = STATUS_POLLING_IDLE;
    _u32CecDeviceMonitorTimer = msAPI_Timer_GetTime0();

    msAPI_CEC_InitCecStructure();

    bCECReportPowerStatusAtBootingUp = TRUE;
    if ( bCECReportPowerStatusAtBootingUp )
    {
        /*
        If TV receives <Give Device Power Status> while it shifts to Power-on state, it shall be sent
        <Report Power Status>[¡§In transition Standby to On¡¨] for directly address.
        */
        _stMsApiCecInfoList.enPowerStatus[E_LA_TV] = E_MSG_PWRSTA_STANDBY2ON;
    }
    else
    {
        _stMsApiCecInfoList.enPowerStatus[E_LA_TV] = E_MSG_PWRSTA_ON;
    }

    memcpy(&_stMsApiCecInfoList.u8CecVendorID[E_LA_TV], &u8VendorID_MST, sizeof(u8VendorID_MST)/sizeof(MS_U8));
    MDrv_CEC_ConfigWakeupInfoVendorID(_stMsApiCecInfoList.u8CecVendorID[E_LA_TV]);

    _stMsApiCecInfoList.u8CECVersion[E_LA_TV] = HDMI_CEC_VERSION;

    if (  (DB_HDMI_SETTING.g_bHdmiCecDeviceControl == ENABLE)
       || (stGenSetting.g_SoundSetting.TVspeakerMode == TVspeaker_Mode_ExtAmp)
       )
    {
        gCECUserControlEnable = TRUE;
    }
    else
    {
        gCECUserControlEnable = FALSE;
    }

    gCECInitDone = TRUE;
}

//**************************************************************************
//  [Function Name]:
//                   MsAPI_CecInit()
//  [Description]
//                  CEC initial sequence
//  [Arguments]:
//
//  [Return]:
//
//**************************************************************************
void msAPI_CEC_Init(void)
{
    MDrv_CEC_SetRetryCount(CEC_RETRY_TIME);
    MDrv_CEC_Init(MST_XTAL_CLOCK_HZ);
    msAPI_CEC_InitVariable();
    msAPI_CEC_SetActiveDevice(E_LA_TV);
    msAPI_CEC_EmptyMsgQueue();
    msAPI_CEC_DeviceRecognition();
    MApp_Aud_SetTVSpeaker();    //CEC 13.15.2, Amplifier comes out of standby if receive <System Audio Mode Request>[PA]
    _u32CecDeviceMonitorTimer = msAPI_Timer_GetTime0();
}

//**************************************************************************
//  [Function Name]:
//                   MApp_CEC_ARC_TX_Control()
//  [Description]
//                   CEC ARC TX output enable/disable
//  [Arguments]:
//                   0: disable / else: enable
//  [Return]:
//                   void
//**************************************************************************
void MApp_CEC_ARC_TX_Control(BOOLEAN bEn)
{
    MDrv_HDMI_ARC_PINControl(INPUT_PORT_DVI0, bEn, FALSE);
}

//**************************************************************************
//  [Function Name]:
//                   msApp_CEC_ARC_Handler()
//  [Description]
//                  CEC ARC connect judge and show menu info
//  [Arguments]:
//
//  [Return]:
//               bool
//**************************************************************************
BOOLEAN MApp_CEC_ARC_Is_Connect(void)  //anvi22
{
    BOOLEAN ret = FALSE;

    if (  msAPI_CEC_IsDeviceExist(E_LA_AUDIO_SYS) == TRUE
       && (DB_HDMI_SETTING.g_enHDMIARC == TRUE)
       && (stGenSetting.g_SoundSetting.TVspeakerMode == TVspeaker_Mode_ExtAmp)
       && (gIsCECAmpARCOn == TRUE)
       )
    {
        ret = TRUE;
    }

    return ret;
}


//**************************************************************************
//  [Function Name]:
//                   msApp_CEC_ARC_Handler()
//  [Description]
//                  CEC ARC connect judge and show menu info
//  [Arguments]:
//
//  [Return]:
//               bool
//**************************************************************************

BOOLEAN msApp_CEC_ARC_Handler(void)
{
    static BOOLEAN ARCConnectMenuIsShow =FALSE;
    static BOOLEAN ARCDisconnectMenuIsShow =FALSE;
    static BOOLEAN _bPreARCConnectedStatus = FALSE;
    BOOLEAN bNeedToUpdate = FALSE;

    if (DB_HDMI_SETTING.g_bHdmiCecMode == FALSE)
    {
        return FALSE;
    }

    if (_bPreARCConnectedStatus != MApp_CEC_ARC_Is_Connect())
    {
        bNeedToUpdate = TRUE;
    }
    _bPreARCConnectedStatus = MApp_CEC_ARC_Is_Connect();

    if(bNeedToUpdate)
    {
        if (MApp_CEC_ARC_Is_Connect() == TRUE)
        {
            if (bNeedToUpdate)
            {
                MApp_CEC_ARC_TX_Control(TRUE);
								#ifdef sNewAudioMuteStyle
								msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, 0, 0);
								#else
    		        MUTE_On();
		            #endif
            }

            if(ARCConnectMenuIsShow == FALSE)
            {
                MApp_UiMenu_ARCDeviceStatusWin_Show(TRUE);
                ARCConnectMenuIsShow = TRUE;
                ARCDisconnectMenuIsShow = FALSE;
            }
        }
        else
        {
            if (bNeedToUpdate)
            {
                MApp_CEC_ARC_TX_Control(FALSE);
								#ifdef sNewAudioMuteStyle
								msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, stGenSetting.g_SoundSetting.Volume, 0);
								#else
								MUTE_Off();
								#endif
            }

            if(ARCDisconnectMenuIsShow == FALSE && ARCConnectMenuIsShow ==TRUE)
            {
                if (  DB_HDMI_SETTING.g_enHDMIARC == TRUE
                   && msAPI_CEC_IsDeviceExist(E_LA_AUDIO_SYS)== FALSE )
                {
                        MApp_UiMenu_ARCDeviceStatusWin_Show(FALSE);
                    ARCConnectMenuIsShow = FALSE;
                    ARCDisconnectMenuIsShow = TRUE;
                }
            }
        }
    }
    return TRUE;
}

MS_U8 msAPI_CEC_AMPHanlder(void)
{
    CEC_ERROR_CODE  res = E_CEC_FEATURE_ABORT;
    static U32 _u32AudioSysMonitorTimer =0;
    static U32 _u32AudioSysPostMsgTimer = 0;
    //static U8 _CountCheck =0;

    if ((DB_HDMI_SETTING.g_enHDMIARC == TRUE) && (stGenSetting.g_SoundSetting.TVspeakerMode == TVspeaker_Mode_ExtAmp))// anvi
    {
        if (msAPI_Timer_DiffTimeFromNow(_u32AudioSysMonitorTimer) > B_MONITOR_CEC_AUDIO_SYS_PERIOD)
        {
            res = msAPI_CEC_PingDevice(E_LA_AUDIO_SYS);

            if (  (res != E_CEC_TX_SUCCESS)
               && (res != E_CEC_SYSTEM_BUSY)
               )
            {
                //CEC_MSG(printf("\n E_LA_AUDIO_SYS Is Not Exsit \n"));
                if (msAPI_CEC_IsDeviceExist(E_LA_AUDIO_SYS) == TRUE)
                {
                    MApp_CEC_ARC_TX_Control(FALSE);
										#ifdef sNewAudioMuteStyle
										msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, stGenSetting.g_SoundSetting.Volume, 0);
										#else
										MUTE_Off();
										#endif
                    if(msAPI_AUD_IsAudioMutedByUser()==TRUE)
                    {
                        msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYUSER_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                    }
                }
                msAPI_CEC_RemoveDevice(E_LA_AUDIO_SYS);
            }

            if (res == E_CEC_TX_SUCCESS)
            {
                if (msAPI_CEC_IsDeviceExist(E_LA_AUDIO_SYS) == FALSE)
                {
                    msAPI_CEC_AddDevice(E_LA_AUDIO_SYS);
                }
                _u32AudioSysPostMsgTimer = msAPI_Timer_GetTime0();
            }

            _u32AudioSysMonitorTimer = msAPI_Timer_GetTime0();
        }
    }

    return TRUE;
}

//**************************************************************************
//  [Function Name]:
//                   msAPI_CEC_Handler_ForBootUp()
//  [Description]
//                   CEC handler
//  [Arguments]:
//
//  [Return]:
//
//**************************************************************************

void msAPI_CEC_Handler_ForBootUp(MS_U8 u8CecDevicesCount)
{
    U8 i;

    if ( gCECInitDone == FALSE)
    {
        //printf("!!! CEC HW not Init yet !!! \n");
        return;
    }

    if (DB_HDMI_SETTING.g_bHdmiCecMode == DISABLE)
    {
        //printf("CEC function OFF!\n");
        return;
    }

    for (i=0; i<(u8CecDevicesCount+1); i++)
    {
      #if (!ENABLE_CEC_INT) // if not enable CEC interrupt, use sw polling to instead of
        MApi_CEC_ChkRxBuf();
      #endif

        msAPI_CEC_ProcessCmd();
    }
}

//**************************************************************************
//  [Function Name]:
//                   MsAPI_CecCecHandler()
//  [Description]
//                   CEC handler
//  [Arguments]:
//
//  [Return]:
//
//**************************************************************************
void msAPI_CEC_Handler(void)
{
    if ( gCECInitDone == FALSE)
    {
        //printf("!!! CEC HW not Init yet !!! \n");
        return;
    }

    if (DB_HDMI_SETTING.g_bHdmiCecMode == DISABLE)
    {
        //printf("CEC function OFF!\n");
        return;
    }
    else
    {
        msApp_CEC_ARC_Handler();
    }

    msAPI_CEC_ProcessTxMsg();

    msAPI_CEC_AMPHanlder();

  #if (!ENABLE_CEC_INT) // if not enable CEC interrupt, use sw polling to instead of
    MApi_CEC_ChkRxBuf();
  #endif

    msAPI_CEC_ProcessCmd();

  #if CEC_STATE_MACHINE
    MApp_CecStateMachine();
  #endif


    if ( bCECReportPowerStatusAtBootingUp )
    {
        msAPI_CEC_SetTvPowerStatusAfterBootUp();
    }
}

//**************************************************************************
//  [Function Name]:
//                   msAPI_CEC_IrdaKeyProcess()
//  [Description]
//                   CEC IRDA key process
//  [Arguments]:
//                   keycode: irda key code
//  [Return]:
//                   return CEC key parse is enable or not
BOOLEAN msAPI_CEC_IrdaKeyProcess(U8 keycode)
{
    BOOLEAN user_ctrl_flag = FALSE;
    MsCEC_DEVICELA enActiveDevice = E_LA_UNREGISTERED;

    if ( gCECInitDone == FALSE)
    {
        //printf("\r\n CEC Irda Key - HW not Init \n");
        return FALSE;
    }

    if (DB_HDMI_SETTING.g_bHdmiCecMode != ENABLE)
    {
        //printf("\r\n CEC Irda Key - g_bHdmiCecMode Disable \n");
        return FALSE;
    }

    CEC_DPRINTF("\r\n CEC Irda Key(0x%bx) \n", keycode);

    if (keycode == KEY_POWER)
    {
        if ( !MApp_UiMenu_IsCountDownWinShow() )    // don't power off DVD when countdown win showing
        {
            msAPI_CEC_PostMsg_Standby(DIRECTMSG);
        }

        MsOS_DelayTask(100);
        return FALSE;
    }

    if ( msAPI_CEC_IsCECKey(keycode) == FALSE )
    {
        CEC_DPRINTF(" CEC Key return 2 (0x%x) \n", keycode);
        return FALSE;
    }

    enActiveDevice = msAPI_CEC_GetActiveDevice();
    CEC_DPRINTF(" Active Logical Address = 0x%x \n", enActiveDevice);

    switch (keycode )
    {
    #if 0
        case KEY_0:      //IRKEY_0
            user_ctrl_flag = TRUE;
            msAPI_CEC_PostMsg_UserCtrlPressed(gCECUserControlEnable, enActiveDevice, E_MSG_UI_NUMBER_0);
            break;
        case KEY_1:      //IRKEY_1
            user_ctrl_flag = TRUE;
            msAPI_CEC_PostMsg_UserCtrlPressed(gCECUserControlEnable, enActiveDevice, E_MSG_UI_NUMBER_1);
            break;
        case KEY_2:      //IRKEY_2
            user_ctrl_flag = TRUE;
            msAPI_CEC_PostMsg_UserCtrlPressed(gCECUserControlEnable, enActiveDevice, E_MSG_UI_NUMBER_2);
            break;
        case KEY_3:      //IRKEY_3
            user_ctrl_flag = TRUE;
            msAPI_CEC_PostMsg_UserCtrlPressed(gCECUserControlEnable, enActiveDevice, E_MSG_UI_NUMBER_3);
            break;
        case KEY_4:      //IRKEY_4
            user_ctrl_flag = TRUE;
            msAPI_CEC_PostMsg_UserCtrlPressed(gCECUserControlEnable, enActiveDevice, E_MSG_UI_NUMBER_4);
            break;
        case KEY_5:      //IRKEY_5
            user_ctrl_flag = TRUE;
            msAPI_CEC_PostMsg_UserCtrlPressed(gCECUserControlEnable, enActiveDevice, E_MSG_UI_NUMBER_5);
            break;
        case KEY_6:      //IRKEY_6
            user_ctrl_flag = TRUE;
            msAPI_CEC_PostMsg_UserCtrlPressed(gCECUserControlEnable, enActiveDevice, E_MSG_UI_NUMBER_6);
            break;
        case KEY_7:      //IRKEY_7
            user_ctrl_flag = TRUE;
            msAPI_CEC_PostMsg_UserCtrlPressed(gCECUserControlEnable, enActiveDevice, E_MSG_UI_NUMBER_7);
            break;
        case KEY_8:      //IRKEY_8
            user_ctrl_flag = TRUE;
            msAPI_CEC_PostMsg_UserCtrlPressed(gCECUserControlEnable, enActiveDevice, E_MSG_UI_NUMBER_8);
            break;
        case KEY_9:      //IRKEY_9
            user_ctrl_flag = TRUE;
            msAPI_CEC_PostMsg_UserCtrlPressed(gCECUserControlEnable, enActiveDevice, E_MSG_UI_NUMBER_9);
            break;
    #endif

        case KEY_UP: // Keypad_UP
            if ( msAPI_CEC_IsRCPassThroughBypass() )
            {
                return FALSE;
            }

            user_ctrl_flag = TRUE;
            CEC_DPUTSTR(" E_MSG_UI_UP \n");
            msAPI_CEC_PostMsg_UserCtrlPressed(DIRECTMSG, gCECUserControlEnable,
                                              enActiveDevice, E_MSG_UI_UP);

            break;

        case KEY_DOWN: // Keypad_DOWN
            if ( msAPI_CEC_IsRCPassThroughBypass() )
            {
                return FALSE;
            }

            user_ctrl_flag = TRUE;
            CEC_DPUTSTR(" E_MSG_UI_DOWN \n");
            msAPI_CEC_PostMsg_UserCtrlPressed(DIRECTMSG, gCECUserControlEnable,
                                              enActiveDevice, E_MSG_UI_DOWN);
            break;

        case KEY_LEFT: // Keypad_LEFT
            if ( msAPI_CEC_IsRCPassThroughBypass() )
            {
                return FALSE;
            }

            user_ctrl_flag = TRUE;
            CEC_DPUTSTR(" E_MSG_UI_LEFT \n");
            msAPI_CEC_PostMsg_UserCtrlPressed(DIRECTMSG, gCECUserControlEnable,
                                              enActiveDevice, E_MSG_UI_LEFT);
            break;

        case KEY_RIGHT: // Keypad_RIGHT
            if ( msAPI_CEC_IsRCPassThroughBypass() )
            {
                return FALSE;
            }

            user_ctrl_flag = TRUE;
            CEC_DPUTSTR(" E_MSG_UI_RIGHT \n");
            msAPI_CEC_PostMsg_UserCtrlPressed(DIRECTMSG, gCECUserControlEnable,
                                              enActiveDevice, E_MSG_UI_RIGHT);
            break;

        case KEY_SELECT: // keypad_Enter
            if ( msAPI_CEC_IsRCPassThroughBypass() )
            {
                return FALSE;
            }

            user_ctrl_flag = TRUE;
            CEC_DPUTSTR(" E_MSG_UI_SELECT \n");
            msAPI_CEC_PostMsg_UserCtrlPressed(DIRECTMSG, gCECUserControlEnable,
                                              enActiveDevice, E_MSG_UI_SELECT);
            break;

        case KEY_PLAY: // Keypad_Play
            user_ctrl_flag = TRUE;
            CEC_DPUTSTR(" E_MSG_UI_PLAY \n");
            msAPI_CEC_PostMsg_UserCtrlPressed(DIRECTMSG, gCECUserControlEnable, enActiveDevice, E_MSG_UI_PLAY);
            break;

        case KEY_PAUSE:
            user_ctrl_flag = TRUE;
            CEC_DPUTSTR(" E_MSG_UI_PAUSE \n");
            msAPI_CEC_PostMsg_UserCtrlPressed(DIRECTMSG, gCECUserControlEnable, enActiveDevice, E_MSG_UI_PAUSE);
            break;

        case KEY_STOP: // Keypad_Stop
            if(gCECRecordEnable) // record on
            {
                gCECRecordEnable = FALSE;
                msAPI_CEC_PostMsg_RecordOff(DIRECTMSG, enActiveDevice);
            }
            else
            {
                user_ctrl_flag = TRUE;
                CEC_DPUTSTR(" E_MSG_UI_STOP \n");
                msAPI_CEC_PostMsg_UserCtrlPressed(DIRECTMSG, gCECUserControlEnable, enActiveDevice, E_MSG_UI_STOP);
            }
            break;

        case KEY_EPG: // Keypad_Open , disk Eject
            msAPI_CEC_PostMsg_DeckCtrl(DIRECTMSG, enActiveDevice, E_MSG_DCM_CMD_EJECT);
            break;

        case KEY_EXIT: // Keypad_Exit
            user_ctrl_flag = TRUE;
            CEC_DPUTSTR(" E_MSG_UI_EXIT \n");
            msAPI_CEC_PostMsg_UserCtrlPressed(DIRECTMSG, gCECUserControlEnable, enActiveDevice, E_MSG_UI_EXIT);
            break;

        case KEY_RECORD:
            //if(!gCECRecordEnable) // record on
                gCECRecordEnable = TRUE;
                msAPI_CEC_PostMsg_RecordOn(DIRECTMSG, enActiveDevice, E_MSG_RECORD_TYPE_OWN_SOURCE);
            //else // record off
            //    msAPI_CEC_PostMsg_RecordOff(DIRECTMSG, enActiveDevice);
            //gCECRecordEnable = ~gCECRecordEnable;
            break;

        case KEY_INFO:  // check CEC version
            user_ctrl_flag = TRUE;
            msAPI_CEC_PostMsg_GetCECVersion(DIRECTMSG, enActiveDevice);
            break;

        case KEY_MUTE:      //IRKEY_MUTE
            if (MApp_CEC_ARC_Is_Connect() == TRUE)
            {
                user_ctrl_flag = FALSE;
                msAPI_CEC_PostMsg_UserCtrlPressed(DIRECTMSG, TRUE, E_LA_AUDIO_SYS, E_MSG_UI_MUTE);
                MApp_ARC_KeyProc_Mute();
            }
            else if(msAPI_CEC_IsAudioSystemKeyValid())
            {
                user_ctrl_flag = TRUE;
                msAPI_CEC_PostMsg_UserCtrlPressed(DIRECTMSG, TRUE, E_LA_AUDIO_SYS, E_MSG_UI_MUTE);
            }
            else
            {
                CEC_DPUTSTR(" TV MUTE MENU \n");
                MApp_CEC_ARC_TX_Control(FALSE);
								#ifdef sNewAudioMuteStyle
								msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, stGenSetting.g_SoundSetting.Volume, 0);
								#else
								MUTE_Off();
								#endif
                return FALSE;
            }
            break;

        case KEY_VOLUME_PLUS:      //IRKEY_VOL_UP
            if (MApp_CEC_ARC_Is_Connect() == TRUE)
            {
                user_ctrl_flag = FALSE;
                msAPI_CEC_PostMsg_UserCtrlPressed(DIRECTMSG, TRUE, E_LA_AUDIO_SYS, E_MSG_UI_VOLUME_UP);
            }
            else if(msAPI_CEC_IsAudioSystemKeyValid())
            {
                user_ctrl_flag = TRUE;
                msAPI_CEC_PostMsg_UserCtrlPressed(DIRECTMSG, TRUE, E_LA_AUDIO_SYS, E_MSG_UI_VOLUME_UP);
            }
            else
            {
                CEC_DPUTSTR(" TV VOLUME PLUS MENU \n");
                MApp_CEC_ARC_TX_Control(FALSE);
								#ifdef sNewAudioMuteStyle
								msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, stGenSetting.g_SoundSetting.Volume, 0);
								#else
								MUTE_Off();
								#endif
            }
            break;

        case KEY_VOLUME_MINUS:      //IRKEY_VOL_DOWM
            if (MApp_CEC_ARC_Is_Connect() == TRUE)
            {
                user_ctrl_flag = FALSE;
                msAPI_CEC_PostMsg_UserCtrlPressed(DIRECTMSG, TRUE, E_LA_AUDIO_SYS, E_MSG_UI_VOLUME_DOWN);
            }
            else if(msAPI_CEC_IsAudioSystemKeyValid())
            {
                user_ctrl_flag = TRUE;
                msAPI_CEC_PostMsg_UserCtrlPressed(DIRECTMSG, TRUE, E_LA_AUDIO_SYS, E_MSG_UI_VOLUME_DOWN);
            }
            else
            {
                CEC_DPUTSTR(" TV VOLUME MINUS MENU \n");
                MApp_CEC_ARC_TX_Control(FALSE);
								#ifdef sNewAudioMuteStyle
								msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, stGenSetting.g_SoundSetting.Volume, 0);
								#else
								MUTE_Off();
								#endif
            }
            break;

        case KEY_BLUE:  // Blue
            user_ctrl_flag = TRUE;
            msAPI_CEC_PostMsg_UserCtrlPressed(DIRECTMSG, gCECUserControlEnable, enActiveDevice, E_MSG_UI_F1_BLUE);
            break;

        case KEY_RED:  // Red
            user_ctrl_flag = TRUE;
            msAPI_CEC_PostMsg_UserCtrlPressed(DIRECTMSG, gCECUserControlEnable, enActiveDevice, E_MSG_UI_F2_RED);
            break;

        case KEY_GREEN:  // Green
            user_ctrl_flag = TRUE;
            msAPI_CEC_PostMsg_UserCtrlPressed(DIRECTMSG, gCECUserControlEnable, enActiveDevice, E_MSG_UI_F3_GREEN);
            break;

        case KEY_YELLOW:  // Yellow
            user_ctrl_flag = TRUE;
            msAPI_CEC_PostMsg_UserCtrlPressed(DIRECTMSG, gCECUserControlEnable, enActiveDevice, E_MSG_UI_F4_YELLOW);
            break;

        case KEY_FF:
            user_ctrl_flag = TRUE;
            CEC_DPUTSTR(" E_MSG_UI_FAST_FORWARD \n");
            msAPI_CEC_PostMsg_UserCtrlPressed(DIRECTMSG, gCECUserControlEnable, enActiveDevice, E_MSG_UI_FAST_FORWARD);
            break;

        case KEY_REWIND:
            user_ctrl_flag = TRUE;
            CEC_DPUTSTR(" E_MSG_UI_REWIND \n");
            msAPI_CEC_PostMsg_UserCtrlPressed(DIRECTMSG, gCECUserControlEnable, enActiveDevice, E_MSG_UI_REWIND);
            break;

        case KEY_NEXT:
            user_ctrl_flag = TRUE;
            CEC_DPUTSTR(" E_MSG_UI_FORWARD \n");
            msAPI_CEC_PostMsg_UserCtrlPressed(DIRECTMSG, gCECUserControlEnable, enActiveDevice, E_MSG_UI_FORWARD);
            break;

        case KEY_PREVIOUS:
            user_ctrl_flag = TRUE;
            CEC_DPUTSTR(" E_MSG_UI_BACKWARD \n");
            msAPI_CEC_PostMsg_UserCtrlPressed(DIRECTMSG, gCECUserControlEnable, enActiveDevice, E_MSG_UI_BACKWARD);
            break;

        default:
            return FALSE;
    }

    if (user_ctrl_flag && !gCECUserControlEnable) // if menu status is deactived, remote control key should handle locally, not send CEC message out
    {
        return FALSE;
    }
    else
    {
        u8KeyCode = KEY_NULL;
        return TRUE;
    }
}

void  msAPI_CEC_CheckWakeUpPort(void)
{
    if ( gCECInitDone == FALSE)
    {
        //printf("!!! CEC HW not Init yet !!! \n");
        return;
    }

    if(!DB_HDMI_SETTING.g_bHdmiCecMode)
    {
        return;
    }

    if(msAPI_Power_IswakeupsourceCEC())
    {
        msAPI_CEC_PostMsg_RequestActiveSource(DIRECTMSG);
    }
}

BOOLEAN msAPI_CEC_CheckWakeupByOneTouchPlayCommand(void)
{

#if(PM_RUNS_IN == PM_RUNS_IN_FLASH)
    // TO DO
    return FALSE;

#else //PM51
    U8 u8Length;

    u8Length = ((MDrv_ReadByte(REG_CEC_RX_LENGTH)) & 0x0F);
    CEC_DPRINTF("\r\n >> CEC_Check OneTouchPlay [%d] \n", u8Length);

    if(u8Length == 1)
    {
        CEC_DPRINTF("REG_CEC_DEVICE = %x\r\n",MDrv_ReadByte(REG_CEC_DEVICE));
        CEC_DPRINTF("REG_CEC_OPCODE = %x\r\n",MDrv_ReadByte(REG_CEC_OPCODE));

        gCecWakeupCmd.enDevice = (MsCEC_DEVICELA) (((MDrv_ReadByte(REG_CEC_DEVICE)) & 0xF0)>>4);
        gCecWakeupCmd.opcode = (MsCEC_MSGLIST) MDrv_ReadByte(REG_CEC_OPCODE);

        CEC_DPRINTF(" enDevice = 0x%x \n", gCecWakeupCmd.enDevice);
        CEC_DPRINTF(" opcode   = 0x%x \n", gCecWakeupCmd.opcode);

    #if ONE_TOUCH_PLAY_SUPPORT
        if (  (gCecWakeupCmd.opcode == E_MSG_OTP_IMAGE_VIEW_ON)
           || (gCecWakeupCmd.opcode == E_MSG_OTP_TEXT_VIEW_ON)
           )
        {
            return TRUE;
        }
    #endif
    }
    return FALSE;

#endif//end PM51
}



#else
U8 code gCEcdummy; // Add a dummy variable for complier link
#endif // ENABLE_CEC

