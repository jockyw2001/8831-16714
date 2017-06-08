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
// (MStar Confidential Information!¡L) by the recipient.
// Any unauthorized act including without limitation unauthorized disclosure,
// copying, use, reproduction, sale, distribution, modification, disassembling,
// reverse engineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _MSAPI_APENGINE_H_
#define _MSAPI_APENGINE_H_

#undef INTERFACE

#ifdef _MSAPI_MHEG5_C_
#define INTERFACE
#else
#define INTERFACE extern
#endif

#define ALIGNED_VALUE(value, align)  ( ((value) + ((align)-1)) & ~((align)-1) )
#define APP_HEADER_LENGTH  512
#if 1
#ifdef __aeon__

//-------------------------------------------------------------------------------------------------
//  In order to keep the compatiblity of the source code from Venus,
//  keep these memory address translation for a while.
//  They will be removed in the future.
//-------------------------------------------------------------------------------------------------
#define CACHED_BASE            ((void *)0x00000000)
#define UNCACHED_BASE       ((void *)0x80000000)

#define CACHED_SIZE         ((void *)0x20000000)
#define UNCACHED_SIZE        ((void *)0x20000000)
//  0xA0000000~0xA000FFFF belongs to RIU
//  0xA1000000~           belongs to SPI

//cached/unchched segment
#define KSEG0_BASE        CACHED_BASE
#define KSEG1_BASE        UNCACHED_BASE
#define KSEG0_SIZE        CACHED_SIZE
#define KSEG1_SIZE        UNCACHED_SIZE

//cached <-> uncached
#define KSEG02KSEG1(addr)  ((void *)((U32)(addr)|0x80000000))
#define KSEG12KSEG0(addr)  ((void *)((U32)(addr)&~0x80000000))

//virtual <-> physical
#define VA2PA(addr)         ((void *)(((U32)addr) & 0x1fffffff))
#define PA2KSEG0(addr)         ((void *)(((U32)addr) | 0x00000000))
#define PA2KSEG1(addr)         ((void *)(((U32)addr) | 0x80000000))
#endif

#if defined(__mips__)

//cached/unchched segment
#define KSEG0_BASE                ((void *)0x80000000)
#define KSEG1_BASE                ((void *)0xa0000000)
#define KSEG0_SIZE                0x20000000
#define KSEG1_SIZE                0x20000000

//cached addr <-> unchched addr
#define KSEG02KSEG1(addr)       ((void *)((MS_U32)(addr)|0x20000000))  //cached -> unchched
#define KSEG12KSEG0(addr)       ((void *)((MS_U32)(addr)&~0x20000000)) //unchched -> cached

//virtual addr <-> physical addr
#define VA2PA(addr)             ((void *)(((MS_U32)addr) & 0x1fffffff)) //virtual -> physical
#define PA2KSEG0(addr)             ((void *)(((MS_U32)addr) | 0x80000000)) //physical -> cached
#define PA2KSEG1(addr)             ((void *)(((MS_U32)addr) | 0xa0000000)) //physical -> unchched
#endif
#endif

typedef enum
{
    APP_APPLICATION = 0x00,
    APP_GAME = 0x01,

    APP_DONT_CARE = 0xFF,
}APP_TYPE;

//-------------------------------
// MB_CLASS_CAPE
//-------------------------------
typedef enum
{
    //HK51 => AEON
    MB_CAPE_INIT_RES                 = 0x00,
    MB_CAPE_GWIN_CREATE_RES          = 0x10,
    MB_CAPE_GWIN_ENABLE_RES          = 0x11,
    MB_CAPE_GWIN_MOVE_RES            = 0x12,
    MB_CAPE_GWIN_DESTROY_RES         = 0x13,
    MB_CAPE_VOP_INIT_RES             = 0x14,
    MB_CAPE_VOP_SETBLUESCREEN_RES    = 0x15,
    MB_CAPE_VOP_MOVE_RES             = 0x16,
    MB_CAPE_VOP_DESTROY_RES          = 0x17,
    MB_CAPE_I8_SET_RES               = 0x20,
    MB_CAPE_I8_GET_RES               = 0x21,
    MB_CAPE_FILE_LEN_RES             = 0x30,
    MB_CAPE_FILE_COPY_RES            = 0x31,
    #ifdef ENABLE_BIKEIR
    MB_CAPE_INIT_BIKEIR_RES          = 0x40,
    #endif
    MB_CAPE_AUDIO_INIT_RES           = 0x50,

    //AEON => HK51
    MB_CAPE_INIT_REQ                 = 0x80,
    MB_CAPE_GWIN_CREATE_REQ          = 0x90,
    MB_CAPE_GWIN_ENABLE_REQ          = 0x91,
    MB_CAPE_GWIN_MOVE_REQ            = 0x92,
    MB_CAPE_GWIN_DESTROY_REQ         = 0x93,
    MB_CAPE_VOP_INIT_REQ             = 0x94,
    MB_CAPE_VOP_SETBLUESCREEN_REQ    = 0x95,
    MB_CAPE_VOP_MOVE_REQ             = 0x96,
    MB_CAPE_VOP_DESTROY_REQ          = 0x97,
    MB_CAPE_AUDIO_INIT_REQ           = 0xA0,
    MB_CAPE_I8_SET_REQ               = 0xB0,
    MB_CAPE_I8_GET_REQ               = 0xB1,
    MB_CAPE_APP_FINALIZED_SIG        = 0xC0,
    MB_CAPE_APP_ALIVE_SIG            = 0xC1,
    MB_CAPE_APP_INITIALIZED_SIG      = 0xC2,
    MB_CAPE_FILE_LEN_REQ             = 0xD0,
    MB_CAPE_FILE_COPY_REQ            = 0xD1,
    #ifdef ENABLE_BIKEIR
    MB_CAPE_INIT_BIKEIR_REQ          = 0xD2,
    #endif
    MB_CAPE_NET_IP_INFO              = 0xE0,
    MB_CAPE_NET_MASK_INFO            = 0xE1,
    MB_CAPE_NET_GATEWAY_INFO         = 0xE2,
    MB_CAPE_NET_DNS_INFO             = 0xE3,

} MB_CAPE_CLASS;

INTERFACE void msAPI_APEngine_ProcessMailBox(void);
INTERFACE void msAPI_APEngine_TransmitKey(U8 u8Key);
INTERFACE void msAPI_APEngine_TransmitJoystick(U16 u16State);
INTERFACE void msAPI_APEngine_APP_Finalize_Init(void);
INTERFACE BOOLEAN msAPI_APEngine_APP_Initialize_Check(void);
INTERFACE BOOLEAN msAPI_APEngine_APP_Alive_Check(void);
INTERFACE BOOLEAN msAPI_APEngine_APP_Finalize_Check(void);
INTERFACE BOOLEAN msAPI_APEngine_AppIsHeaderValid(U8 u8Type, U8 *pHeader, U16 u16HeaderLen);
INTERFACE BOOLEAN msAPI_APEngine_AppIsContentValid(U8 *pContent, U32 u32ContentLen);
INTERFACE BOOLEAN msAPI_APEngine_GetExtension(U8 *pExtension, U8 u8ExtLen, U8 *pHeader, U16 u16HeaderLen);
INTERFACE BOOLEAN msAPI_APEngine_AppRun(U32 u32AppBinaryAddr, U32 u32Len, U32 u32BEON_ADR, U32 u32BEON_LEN);
INTERFACE BOOLEAN msAPI_APEngine_AppRunByBinID(U16 u16BinID, U32 u32BEON_ADR, U32 u32BEON_LEN);

#if OBA2
#include "madp.h"

#if (OBA2 && defined(GADGET))
#define GADGETAP_NAME "GADGET"
#endif

typedef enum
{
    E_OBAMA_APP_TYPE_TV_NONE,
    E_OBAMA_APP_TYPE_ISOLATED_APP,
    E_OBAMA_APP_TYPE_TV_APP,
}E_OBAMA_APP_TYPE;

typedef enum
{
    E_OBAMA_ZODIAC_MSG_TYPE_DIRECTOUTPUT_CREATE,
    E_OBAMA_ZODIAC_MSG_TYPE_DIRECTOUTPUT_SHOW,
    E_OBAMA_ZODIAC_MSG_TYPE_DIRECTOUTPUT_HIDE,
    E_OBAMA_ZODIAC_MSG_TYPE_DIRECTOUTPUT_MOVE,
    E_OBAMA_ZODIAC_MSG_TYPE_DIRECTOUTPUT_DESTROY,
    E_OBAMA_ZODIAC_MSG_TYPE_MEDIA_MUTE,
    E_OBAMA_ZODIAC_MSG_TYPE_IS_CHIPTYPE_T3,
    E_OBAMA_ZODIAC_MSG_TYPE_SWITCH_KTV,
}E_OBAMA_ZODIAC_MSG_TYPE;

/* removed:
typedef enum
{
    //zodiac to chakra
    E_OBAMA_ZODIAC_MSG_TYPE_VDPLAYER_INIT,
    E_OBAMA_ZODIAC_MSG_TYPE_VDPLAYER_EXIT,
    E_OBAMA_ZODIAC_MSG_TYPE_VDPLAYER_STOP,
    E_OBAMA_ZODIAC_MSG_TYPE_VDPLAYER_PAUSE,
    E_OBAMA_ZODIAC_MSG_TYPE_VDPLAYER_RESUME,
    E_OBAMA_ZODIAC_MSG_TYPE_VDPLAYER_PLAY,
    E_OBAMA_ZODIAC_MSG_TYPE_VDPLAYER_INIT_DISPLAY_SETUP,
    E_OBAMA_ZODIAC_MSG_TYPE_VDPLAYER_SET_PLAY_MODE,
    //chakra to zodiac
    E_OBAMA_ZODIAC_MSG_GET_FILE_HANDLE,
    E_OBAMA_ZODIAC_MSG_FILE_INIT,
    E_OBAMA_ZODIAC_MSG_FILE_READ,
    E_OBAMA_ZODIAC_MSG_FILE_SEEK,
    E_OBAMA_ZODIAC_MSG_FILE_CLOSE,
    E_OBAMA_ZODIAC_MSG_FILE_END,
    E_OBAMA_ZODIAC_MSG_VIDEO_INFO,
    E_OBAMA_ZODIAC_MSG_INIT_ERROR,
    E_OBAMA_ZODIAC_MSG_SET_CURRENT_TIME,
}E_OBAMA_ZODIAC_VDPLAYER_MSG_TYPE;
*/

typedef enum
{
    E_OBAMA_ZODIAC_INTPUTSOURCE_CHANGE_AUDIO_TO_AP,       ///< change audio to ap
    E_OBAMA_ZODIAC_INTPUTSOURCE_CHANGE_AV_TO_AP,       ///< change audio/video to ap
    E_OBAMA_ZODIAC_INTPUTSOURCE_CHANGE_AUDIO_TO_ATV,       ///< change audio to atv
    E_OBAMA_ZODIAC_INTPUTSOURCE_CHANGE_AV_TO_ATV,       ///< change audio/video to ap
    E_OBAMA_ZODIAC_INTPUTSOURCE_CHANGE_AV_TO_KTVAP,       ///< change audio/video to KTV
} E_OBAMA_ZODIAC_INPUTSOURCE_CHANGE_MESSAGE;

INTERFACE void msAPI_APEngine_Obama_Init(IRCallback irCB);
INTERFACE bool msAPI_APEngine_Obama_Zodiac_ReceiveMsg(unsigned char * pu8Msg, unsigned short u16DataSize, unsigned char * pu8OutData, unsigned short u16OutDataSize);
// removed: INTERFACE void msAPI_APEngine_Obama_Zodiac_VDPlayer_ProcessMailBox(void);
// removed: INTERFACE bool msAPI_APEngine_Obama_Zodiac_VDPlayer_ReceiveMsg(unsigned char * pu8Msg, unsigned short u16DataSize, unsigned char * pu8OutData, unsigned short u16OutDataSize);
INTERFACE BOOLEAN msAPI_APEngine_Obama_Zodiac_InputSource_ReceiveMsg(unsigned char * pu8Msg, unsigned short u16DataSize, unsigned char * pu8OutData, unsigned short u16OutDataSize);
INTERFACE BOOLEAN msAPI_APEngine_Obama_ExecuteAppByIndex(U8 u8Index);
INTERFACE BOOLEAN msAPI_APEngine_Obama_StopAppByIndex(U8 u8Index);
INTERFACE BOOLEAN msAPI_APEngine_Obama_ExecuteApp(char * pu8AppName);
INTERFACE BOOLEAN msAPI_APEngine_Obama_ExecuteApp2(char * pu8AppName, char * args);
INTERFACE BOOLEAN msAPI_APEngine_Obama_StopApp(char * pu8AppName);
INTERFACE BOOLEAN msAPI_APEngine_Obama_StopCurrentApp(void);
INTERFACE void msAPI_APEngine_Obama_TransmitKey(U8 u8Key);
INTERFACE E_OBAMA_APP_TYPE msAPI_APEngine_Obama_CurrentAppType(void);
INTERFACE BOOLEAN msAPI_APEngine_Obama_MuteFlag(void);
INTERFACE BOOLEAN msAPI_APEngine_Obama_ApRegstingFlag(void);
INTERFACE void msAPI_APEngine_Obama_StopApRegsting(void);

#endif

#undef INTERFACE

#endif  // _MSAPI_APENGINE_H_

