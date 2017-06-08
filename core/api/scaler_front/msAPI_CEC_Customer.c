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

//-------------------------------------------------------------------------------------------------
//  Local Defines
//-------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------
//  Local Structures
//-------------------------------------------------------------------------------------------------
#define IF_NO_OSD_NAME_USE_DEFAULT_NAME     TRUE

/*
Logical Device             Default Displayed name
-------------------------------------------------
1  Recording Device1       Recorder1
2  Recording Device2       Recorder2
3  Tuner1                  Tuner1
4  Playback Device1        Player1
5  Audio System            Audio System
6  Tuner2                  Tuner2
7  Tuner3                  Tuner3
8  Playback Device2        Player2
9  Recording Device3       Recorder3
10 Tuner4                  Tuner4
11 Playback Device3        Player3
12 Reserved                Device1
13 Reserved                Device2
14 Specific Use            Device3
15 Unregistered            Not displayed
*/

#if IF_NO_OSD_NAME_USE_DEFAULT_NAME
const MS_U8 code gStrCECDeviceTypeEng[E_LA_MAX+1][MAX_CEC_DEVICE_OSD_NAME]=
{
    {'T', 'V', '\0'},
    {'R', 'e', 'c', 'o', 'r', 'd', 'e', 'r', '1', '\0'},
    {'R', 'e', 'c', 'o', 'r', 'd', 'e', 'r', '2', '\0'},
    {'T', 'u', 'n', 'e', 'r', '1', '\0'},
    {'P', 'l', 'a', 'y', 'e', 'r', '1', '\0'},
    {'A', 'u', 'd', 'i', 'o', ' ', 's', 'y', 's', 't', 'e', 'm','\0'},
    {'T', 'u', 'n', 'e', 'r', '2', '\0'},
    {'T', 'u', 'n', 'e', 'r', '3', '\0'},
    {'P', 'l', 'a', 'y', 'e', 'r', '2', '\0'},
    {'R', 'e', 'c', 'o', 'r', 'd', 'e', 'r', '3', '\0'},
    {'T', 'u', 'n', 'e', 'r', '4', '\0'},
    {'P', 'l', 'a', 'y', 'e', 'r', '3', '\0'},
    {'D', 'e', 'v', 'i', 'c', 'e', '1', '\0'},
    {'D', 'e', 'v', 'i', 'c', 'e', '2', '\0'},
    {'D', 'e', 'v', 'i', 'c', 'e', '3', '\0'},
    {'B', 'r', 'o', 'a', 'd', 'c', 'a', 's', 't', '\0'},
};

const MS_U8 code gStrCECDeviceTypeFre[E_LA_MAX+1][MAX_CEC_DEVICE_OSD_NAME]=
{
    {'T', 'V', '\0'},
    {'E', 'n', 'r', 'e', 'g', 'i', 's', 't', 'r', 'e', 'u', 'r', '1', '\0'},
    {'E', 'n', 'r', 'e', 'g', 'i', 's', 't', 'r', 'e', 'u', 'r', '2', '\0'},
    {'S', 'y', 'n', 't', 'o', 'n', 'i', 's', 'e', 'u', 'r', '1', '\0'},
    {'L', 'e', 'c', 't', 'e', 'u', 'r', '1', '\0'},
    {'S', 'y', 's', 't', 0xE8, 'm', 'e', ' ', 'a', 'u', 'd', 'i', 'o', '\0'},
    {'S', 'y', 'n', 't', 'o', 'n', 'i', 's', 'e', 'u', 'r', '2', '\0'},
    {'S', 'y', 'n', 't', 'o', 'n', 'i', 's', 'e', 'u', 'r', '3', '\0'},
    {'L', 'e', 'c', 't', 'e', 'u', 'r', '2', '\0'},
    {'E', 'n', 'r', 'e', 'g', 'i', 's', 't', 'r', 'e', 'u', 'r', '3', '\0'},
    {'S', 'y', 'n', 't', 'o', 'n', 'i', 's', 'e', 'u', 'r', '4', '\0'},
    {'L', 'e', 'c', 't', 'e', 'u', 'r', '3', '\0'},
    {'P', 0xE9, 'r', 'i', 'p', 'h', 0xE9, 'r', 'i', 'q', 'u', 'e', '1', '\0'},
    {'P', 0xE9, 'r', 'i', 'p', 'h', 0xE9, 'r', 'i', 'q', 'u', 'e', '2', '\0'},
    {'P', 0xE9, 'r', 'i', 'p', 'h', 0xE9, 'r', 'i', 'q', 'u', 'e', '3', '\0'},
    {'B', 'r', 'o', 'a', 'd', 'c', 'a', 's', 't', '\0'},
};

const MS_U8 code gStrCECDeviceTypeEsp[E_LA_MAX+1][MAX_CEC_DEVICE_OSD_NAME]=
{
    {'T', 'V', '\0'},
    {'G', 'r', 'a', 'b', 'a', 'd', 'o', 'r', 'a', '1', '\0'},
    {'G', 'r', 'a', 'b', 'a', 'd', 'o', 'r', 'a', '2', '\0'},
    {'S', 'i', 'n', 't', 'o', 'n', 'i', 'z', 'a', 'd', 'o', 'r', '1', '\0'},
    {'R', 'e', 'p', 'r', 'o', 'd', 'u', 'c', 't', 'o', 'r', '1', '\0'},
    {'S', 'i', 's', 't', 'e', 'm', 'a', ' ', 'd', 'e', ' ', 'a', 'u', 'd', 'i', 'o', '\0'},
    {'S', 'i', 'n', 't', 'o', 'n', 'i', 'z', 'a', 'd', 'o', 'r', '2', '\0'},
    {'S', 'i', 'n', 't', 'o', 'n', 'i', 'z', 'a', 'd', 'o', 'r', '3', '\0'},
    {'R', 'e', 'p', 'r', 'o', 'd', 'u', 'c', 't', 'o', 'r', '2', '\0'},
    {'G', 'r', 'a', 'b', 'a', 'd', 'o', 'r', 'a', '3', '\0'},
    {'S', 'i', 'n', 't', 'o', 'n', 'i', 'z', 'a', 'd', 'o', 'r', '4', '\0'},
    {'R', 'e', 'p', 'r', 'o', 'd', 'u', 'c', 't', 'o', 'r', '3', '\0'},
    {'D', 'i', 's', 'p', 'o', 's', 'i', 't', 'i', 'v', 'o', '1', '\0'},
    {'D', 'i', 's', 'p', 'o', 's', 'i', 't', 'i', 'v', 'o', '2', '\0'},
    {'D', 'i', 's', 'p', 'o', 's', 'i', 't', 'i', 'v', 'o', '3', '\0'},
    {'B', 'r', 'o', 'a', 'd', 'c', 'a', 's', 't', '\0'},
};
#endif

//-------------------------------------------------------------------------------------------------
//  Local Variables
//-------------------------------------------------------------------------------------------------
static void msAPI_CEC_LoadDefaultDeviceName(EN_LANGUAGE pLanguage)
{
    switch (pLanguage)
    {
        default:
        case LANGUAGE_ENGLISH:
            memcpy(_stMsApiCecInfoList.u8CecDeviceName, gStrCECDeviceTypeEng, sizeof(gStrCECDeviceTypeEng));
            break;

        case LANGUAGE_FRENCH:
            memcpy(_stMsApiCecInfoList.u8CecDeviceName, gStrCECDeviceTypeFre, sizeof(gStrCECDeviceTypeFre));
            break;

        case LANGUAGE_SPANISH:
            memcpy(_stMsApiCecInfoList.u8CecDeviceName, gStrCECDeviceTypeEsp, sizeof(gStrCECDeviceTypeEsp));
            break;
    }
}

BOOLEAN msAPI_CEC_IsRCPassThroughBypass(void)
{
    CEC_DPRINTF("msAPI_CEC_IsRCPassThroughBypass(0x%x) \n", _eActiveOSD);

    if (  _eActiveOSD == E_OSD_MAIN_MENU
       || _eActiveOSD == E_OSD_INPUT_SOURCE
       || _eActiveOSD == E_OSD_MESSAGE_BOX
       || _eActiveOSD == E_OSD_FACTORY_MENU
       )
    {
        return TRUE;
    }

    return FALSE;
}

static BOOLEAN msAPI_CEC_IsCECKey(U8 bKey)
{
    switch (bKey)
    {
        case KEY_PLAY:
        case KEY_PAUSE:
        case KEY_STOP:
        case KEY_FF:
        case KEY_REWIND:
        case KEY_NEXT:
        case KEY_PREVIOUS:
        case KEY_UP:
        case KEY_DOWN:
        case KEY_LEFT:
        case KEY_RIGHT:
        case KEY_SELECT:
        case KEY_VOLUME_MINUS:
        case KEY_VOLUME_PLUS:
        case KEY_MUTE:
            return TRUE;

        default:
            return FALSE;
    }
}


MS_U8 msAPI_CEC_DeviceRecognition(void)
{
    MS_BOOL bCecDevicesExisted[E_LA_MAX];
    MS_U8   u8DeviceExistCount = 0;

    memset(bCecDevicesExisted, FALSE, sizeof(bCecDevicesExisted));

    u8DeviceExistCount = msAPI_CEC_DeviceRecognition1_Ping(bCecDevicesExisted);

    msAPI_CEC_DeviceRecognition_GivePhysicalAddress(bCecDevicesExisted);

    msAPI_CEC_DeviceRecognition_GiveDevicePowerStatus(bCecDevicesExisted);

    return u8DeviceExistCount;
}

