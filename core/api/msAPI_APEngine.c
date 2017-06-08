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

////////////////////////////////////////////////////////////////////////////////
//
/// @file msAPI_APEngine.h
/// @brief API for AP Engine
/// @author MStar Semiconductor, Inc.
//
////////////////////////////////////////////////////////////////////////////////
#define _MSAPI_APENGINE_C_
#if (ENABLE_CAPE || OBA2)
/******************************************************************************/
/*                            Header Files                                    */
/* ****************************************************************************/
#include <string.h>
#include "drvGlobal.h"

#include "datatype.h"
#include "Board.h"
#include "debug.h"
#include "MsCommon.h"

#include "apiXC.h"
#include "apiXC_Adc.h"
#include "apiXC_Sys.h"
#include "apiAUDIO.h"
#include "drvISR.h"
#include "drvCPU.h"
#include "msAPI_CPU.h"
#include "apiGOP.h"
#include "msAPI_MMap.h"
#include "apiGOP.h"
#include "msAPI_APEngine.h"
#include "msAPI_Music.h"
#include "msAPI_audio.h"
#include "msAPI_MIU.h"
#include "msAPI_Timer.h"
#include "ms_decompress.h"
#include "MApp_InputSource.h"
#include "MApp_GlobalVar.h"
#include "msAPI_Video.h"
#include "MApp_MVDMode.h"
#include "MApp_PCMode.h"
#include "MApp_Scaler.h"
#include "MApp_XC_PQ.h"


#include "drvMIU.h"

#include "sysinfo.h"


#ifdef SUPPORT_AP_BIN_IN_FLASH_2
#include "InfoBlock.h"
#endif

#include "msAPI_MPEG_Subtitle.h"
#include "MsOS.h"

#if ENABLE_DMP
#include "mapp_mplayer.h"
#endif
#if ((OBA2 == 1) && (ENABLE_BABAO_PLAYER == ENABLE))
#include "msAPI_Nplayer.h"
#endif

#include "mapp_videoplayer.h"
#include "msAPI_MailBox.h"
#include "debug.h"


#define APENGINE_MAILBOX_SEND(_class,_index,_type,_count,_p1,_p2,_p3,_p4,_p5,_p6,_p7,_p8,_p9,_p10) _APEngine_SendMailboxMsg((U8)_class,(U8)_index,(MBX_MSG_Type)_type,(U8)_count,(U8) _p1,(U8) _p2,(U8) _p3,(U8) _p4,(U8) _p5,(U8) _p6,(U8) _p7,(U8) _p8,(U8) _p9,(U8) _p10)

#define ALIVE_CHECK_INTERVAL  5000        //ms

static BOOLEAN _bCAPEFinalizeIsDone, _bCAPEInitializeIsDone;
static U32 _u32CAPEAliveCount;

#if ENABLE_MPLAYER_PLUGIN
static U32 _u32RomFsSize = 0;
#endif

#if 0//ENABLE_DRM
extern BOOLEAN bDrmRegCode;
extern BOOLEAN bDrmFileFormat;
extern BOOLEAN bDrmActivationFile;
extern BOOLEAN bDrmAuthorization;
extern BOOLEAN bDrmRentalStatus;

extern BOOLEAN g_bDrmRental;
extern U8 g_u8DrmUseLimit;
extern U8 g_u8DrmUseCount;

extern U8 g_DRMRegCode[];
extern U8 g_DRMDeactivationCode[];

#endif


static void _APEngine_SendMailboxMsg(U8 _class, U8 _index, MBX_MSG_Type _type, U8 _count,
                                        U8 _p1, U8 _p2, U8 _p3, U8 _p4, U8 _p5, U8 _p6, U8 _p7, U8 _p8, U8 _p9, U8 _p10)
{
    MBX_Msg m5_mbxMsg;
    MBX_Result mbxResult;

    m5_mbxMsg.u8MsgClass            = _class;
    m5_mbxMsg.u8Index               = _index;
    m5_mbxMsg.u8ParameterCount      = _count;
    m5_mbxMsg.eMsgType              = _type;
    m5_mbxMsg.u8Parameters[0]       = _p1;
    m5_mbxMsg.u8Parameters[1]       = _p2;
    m5_mbxMsg.u8Parameters[2]       = _p3;
    m5_mbxMsg.u8Parameters[3]       = _p4;
    m5_mbxMsg.u8Parameters[4]       = _p5;
    m5_mbxMsg.u8Parameters[5]       = _p6;
    m5_mbxMsg.u8Parameters[6]       = _p7;
    m5_mbxMsg.u8Parameters[7]       = _p8;
    m5_mbxMsg.u8Parameters[8]       = _p9;
    m5_mbxMsg.u8Parameters[9]       = _p10;

    do
    {
        mbxResult = MSApi_MBX_SendMsg(&m5_mbxMsg);
        switch(mbxResult)
        {
            case E_MBX_ERR_PEER_CPU_BUSY:
            case E_MBX_ERR_PEER_CPU_NOTREADY:
            case E_MBX_ERR_PEER_CPU_NOT_ALIVE:
                //Error Handling here...
                break;
            case E_MBX_ERR_PEER_CPU_OVERFLOW:
                //MsOS_DelayTask(1);
                break;
            default:
                break;
        }
    }while(E_MBX_SUCCESS != mbxResult);
}


static void _APEngine_GWIN_Create(MBX_Msg MB_Message)
{
    //[0]:gefmt
    //[12]:width
    //[34]:height
    //[5678]:addr
    U8 u8FbId, u8GwinId;
    U8 gefmt;
    U16 width, height;
    U32 addr;

    gefmt = MB_Message.u8Parameters[0];
    width = ReadU16BE(&MB_Message.u8Parameters[1]);
    height = ReadU16BE(&MB_Message.u8Parameters[3]);
    addr = ReadU32BE(&MB_Message.u8Parameters[5]);

    MApi_GOP_GWIN_SwitchGOP(E_GOP_APP);
    u8GwinId = MApi_GOP_GWIN_CreateWin(32, 32, GFX_FMT_YUV422);
    u8FbId = MApi_GOP_GWIN_GetFBfromGWIN(u8GwinId);
    MApi_GOP_GWIN_DestroyFB(u8FbId);
    u8FbId = MApi_GOP_GWIN_GetFreeFBID();
    MApi_GOP_GWIN_CreateFBbyStaticAddr(u8FbId, 0, 0, width, height, gefmt, addr);
    MApi_GOP_GWIN_MapFB2Win(u8FbId, u8GwinId);
    MApi_GOP_GWIN_SetWinDispPosition(u8GwinId, 200, 200);
    MApi_GOP_GWIN_SetBlending(u8GwinId, FALSE, 63);
    MApi_GOP_GWIN_Enable(u8GwinId, TRUE);
    MApi_GOP_GWIN_SwitchGOP(E_GOP_OSD);

    // send response to aeon
    //==> Send mail.
    APENGINE_MAILBOX_SEND(E_MBX_CLASS_CAPE
    /*Index*/           ,MB_CAPE_GWIN_CREATE_RES
    /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
    /*ParameterCount*/  ,1
    /*p1*/              ,u8GwinId
    /*p2*/              ,0
    /*p3*/              ,0
    /*p4*/              ,0
    /*p5*/              ,0
    /*p6*/              ,0
    /*p7*/              ,0
    /*p8*/              ,0
    /*p9*/              ,0
    /*p10*/             ,0);

}

static void _APEngine_GWIN_Enable(MBX_Msg MB_Message)
{
    //[0]:gwinid
    //[1]:1=enable, 0=disable
    U8 u8GwinId, enable;
    u8GwinId = MB_Message.u8Parameters[0];
    enable = MB_Message.u8Parameters[1];

    MApi_GOP_GWIN_SwitchGOP(E_GOP_APP);
    MApi_GOP_GWIN_Enable(u8GwinId, enable);
    MApi_GOP_GWIN_SwitchGOP(E_GOP_OSD);

    // send response to aeon
    //==> Send mail.
    APENGINE_MAILBOX_SEND(E_MBX_CLASS_CAPE
    /*Index*/           ,MB_CAPE_GWIN_ENABLE_RES
    /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
    /*ParameterCount*/  ,1
    /*p1*/              ,0
    /*p2*/              ,0
    /*p3*/              ,0
    /*p4*/              ,0
    /*p5*/              ,0
    /*p6*/              ,0
    /*p7*/              ,0
    /*p8*/              ,0
    /*p9*/              ,0
    /*p10*/             ,0);
}

static void _APEngine_GWIN_Move(MBX_Msg MB_Message)
{
    //[0]:gwinid
    //[12]:x
    //[34]:y
    U8 u8GwinId;
    U16 x, y;

    u8GwinId = MB_Message.u8Parameters[0];
    x = ReadU16BE(&MB_Message.u8Parameters[1]);
    y = ReadU16BE(&MB_Message.u8Parameters[3]);

    MApi_GOP_GWIN_SwitchGOP(E_GOP_APP);
    MApi_GOP_GWIN_SetWinPosition(u8GwinId, x, y);
    MApi_GOP_GWIN_SwitchGOP(E_GOP_OSD);

    // send response to aeon
    //==> Send mail.
    APENGINE_MAILBOX_SEND(E_MBX_CLASS_CAPE
    /*Index*/           ,MB_CAPE_GWIN_MOVE_RES
    /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
    /*ParameterCount*/  ,1
    /*p1*/              ,0
    /*p2*/              ,0
    /*p3*/              ,0
    /*p4*/              ,0
    /*p5*/              ,0
    /*p6*/              ,0
    /*p7*/              ,0
    /*p8*/              ,0
    /*p9*/              ,0
    /*p10*/             ,0);
}

static void _APEngine_GWIN_Destroy(MBX_Msg MB_Message)
{
    //[0]:gwinid
    U8 u8GwinId;
    u8GwinId = MB_Message.u8Parameters[2];

    MApi_GOP_GWIN_SwitchGOP(E_GOP_APP);
    MApi_GOP_GWIN_ReleaseWin(u8GwinId);
    MApi_GOP_GWIN_SwitchGOP(E_GOP_OSD);

    // send response to aeon
    //==> Send mail.
    APENGINE_MAILBOX_SEND(E_MBX_CLASS_CAPE
    /*Index*/           ,MB_CAPE_GWIN_DESTROY_RES
    /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
    /*ParameterCount*/  ,1
    /*p1*/              ,0
    /*p2*/              ,0
    /*p3*/              ,0
    /*p4*/              ,0
    /*p5*/              ,0
    /*p6*/              ,0
    /*p7*/              ,0
    /*p8*/              ,0
    /*p9*/              ,0
    /*p10*/             ,0);
}

static void _APEngine_VOP_Init(MBX_Msg MB_Message)
{
    //[01]:width
    //[23]:height
    //[4567]:addr
    U16 u16Width, u16Height;
    U32 u32BuffAddr;
    MVOP_VidStat stMvopVidSt;

    u16Width = ReadU16BE(&MB_Message.u8Parameters[0]);
    u16Height = ReadU16BE(&MB_Message.u8Parameters[2]);
    u32BuffAddr = ReadU32BE(&MB_Message.u8Parameters[4]);

    U16 u16DisplayX, u16DisplayY, u16DisplayWidth, u16DisplayHeight;
    u16DisplayX = 0;
    u16DisplayY = 0;
    u16DisplayWidth = u16Width;
    u16DisplayHeight = u16Height;

    gstVidStatus.u32FrameRate = 60000;

//    msAPI_VID_VOPInit();
    MDrv_MVOP_Init();
//    msAPI_VID_SetVOPClk(TRUE);

    {
        MVOP_InputCfg dc_param;
        #if 0
        MS_SYS_INFO enMsSysInfo;
        #endif

        // Enable Blue Screen
        msAPI_Scaler_SetBlueScreen(ENABLE, E_XC_FREE_RUN_COLOR_BLACK, DEFAULT_SCREEN_UNMUTE_TIME, MAIN_WINDOW);

        MApi_XC_GenerateBlackVideo(ENABLE, MAIN_WINDOW);

//        msAPI_VID_VOPInit();
        MDrv_MVOP_Init();

    //Refine: When we enter MM or Internet APs, input source type already be set to INPUT_SOURCE_STORAGE and
    //          msAPI_Scaler_SetSourceType() was called. So, we don't need to set source type again.
#if 0
         // set Scaler input source
        SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW) = INPUT_SOURCE_STORAGE;
        enMsSysInfo.enDataInputSourceType = DATA_INPUT_SOURCE_STORAGE;
        enMsSysInfo.enInputSourceType = INPUT_SOURCE_STORAGE;
        enMsSysInfo.enAspectRatio = VIDEOSCREEN_NORMAL;
        msAPI_Scaler_SetSourceType(enMsSysInfo.enInputSourceType,OUTPUT_SCALER_MAIN_WINDOW);
#endif

        // set mvop parameters
        //=========JPEG TETS==========
        dc_param.u16HSize = u16Width;
        dc_param.u16VSize = u16Height;
        dc_param.u32YOffset = u32BuffAddr;
        dc_param.u32UVOffset = dc_param.u32YOffset+ 8; //No Use, in MDrv_VOP_Input_Mode, it will be reset
        dc_param.bSD = 1;
        dc_param.bYUV422 = 1;
        dc_param.bProgressive = 1;
        dc_param.bUV7bit = 0;
        dc_param.bDramRdContd = 1;
        dc_param.bField = 0;
        dc_param.b422pack = 1;
        dc_param.u16StripSize = dc_param.u16HSize;
        MDrv_MVOP_SetInputCfg(MVOP_INPUT_DRAM, &dc_param);

        gstVidStatus.u16HorSize = dc_param.u16HSize;
        gstVidStatus.u16VerSize = dc_param.u16VSize;
        gstVidStatus.u8AspectRate = ASP_4TO3;   //ASP_16TO9;
        gstVidStatus.u8Interlace = 0;
    }

    U32 u32Width, u32Height;
    u32Width = (U32)gstVidStatus.u16HorSize;
    u32Height = (U32)gstVidStatus.u16VerSize;

    memset(&stMvopVidSt, 0, sizeof(MVOP_VidStat));
    stMvopVidSt.u16HorSize   = gstVidStatus.u16HorSize;
    stMvopVidSt.u16VerSize   = gstVidStatus.u16VerSize;
    stMvopVidSt.u16FrameRate = gstVidStatus.u32FrameRate;
    stMvopVidSt.u8AspectRate = gstVidStatus.u8AspectRate;
    stMvopVidSt.u8Interlace  = gstVidStatus.u8Interlace;
    MDrv_MVOP_SetOutputCfg(&stMvopVidSt, FALSE);

    {
        U16 displayX, displayY, displayHSize, displayVSize;
        MS_WINDOW_TYPE tDstWin;
        S32 s32QuotientDiff, s32RemainderDiff;

        // set scaling aspect to program
        // [071017 Andy] set to original aspect
        stSystemInfo[MAIN_WINDOW].enAspectRatio = VIDEOSCREEN_ORIGIN;

        #if 0
        if(enVDPlayerFlgs & E_VDPLAYER_FLG_PREVIEW)
        {
            u16DisplayX = MOVIE_PREVIEW_X;
            u16DisplayY = MOVIE_PREVIEW_Y;
            u16DisplayWidth = MOVIE_PREVIEW_WIDTH;
            u16DisplayHeight = MOVIE_PREVIEW_HEIGHT;
        }
        #endif

        // Set to the original aspect ratio
        s32QuotientDiff = ((((U32)u16DisplayWidth * 32) / (U32)u16DisplayHeight) - (((U32)u16Width * 32) / (U32)u16Height));
        s32RemainderDiff = ((((U32)u16DisplayWidth * 32) % (U32)u16DisplayHeight) - (((U32)u16Width * 32) % (U32)u16Height));
        // Set to the original aspect ratio
        if ((s32QuotientDiff > 0)
                || ((s32QuotientDiff == 0) && (s32RemainderDiff > 0)))
        {
            // Height major
            displayHSize = (U16)(((U32)u16DisplayHeight * 32 / (U32)u16Height) *
                                  (U32)u16Width / 32) & 0xFFFE;
            displayX = u16DisplayX + (u16DisplayWidth - displayHSize) / 2;
            displayY = u16DisplayY;
            displayVSize = u16DisplayHeight;
        }
        else
        {
            // Width major
            displayVSize = (U16)(((U32)u16DisplayWidth * 32 / (U32)u16Width) *
                                  (U32)u16Height / 32) & 0xFFFE;
            displayY = u16DisplayY + (u16DisplayHeight - displayVSize) / 2;
            displayX = u16DisplayX;
            displayHSize = u16DisplayWidth;
        }

        {
            tDstWin.x = displayX;
            tDstWin.y = displayY;
            tDstWin.width = displayHSize;
            tDstWin.height = displayVSize;

            MApp_Scaler_EnableOverScan(FALSE);
            MApp_Scaler_SetWindow(NULL, NULL, &tDstWin, stSystemInfo[MAIN_WINDOW].enAspectRatio,
                                                   SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), MAIN_WINDOW);
        }

        //switch MIU to 0
        MDrv_MVOP_MiuSwitch(0);

        MDrv_MVOP_Enable(TRUE);
//        msAPI_VID_SetVOPClk(ENABLE);

        MApp_Picture_Setting_SetColor(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), MAIN_WINDOW);
        msAPI_Scaler_SetBlueScreen(ENABLE, E_XC_FREE_RUN_COLOR_BLACK, DEFAULT_SCREEN_UNMUTE_TIME, MAIN_WINDOW);
    }

    // send response to aeon
    //==> Send mail.
    APENGINE_MAILBOX_SEND(E_MBX_CLASS_CAPE
    /*Index*/           ,MB_CAPE_VOP_INIT_RES
    /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
    /*ParameterCount*/  ,1
    /*p1*/              ,0
    /*p2*/              ,0
    /*p3*/              ,0
    /*p4*/              ,0
    /*p5*/              ,0
    /*p6*/              ,0
    /*p7*/              ,0
    /*p8*/              ,0
    /*p9*/              ,0
    /*p10*/             ,0);
}

static void _APEngine_VOP_SetBlueScreen(MBX_Msg MB_Message)
{
    //[0]:1=enable, 0=disable
    U8 enable;
    enable = MB_Message.u8Parameters[0];

    msAPI_Scaler_SetBlueScreen(enable, E_XC_FREE_RUN_COLOR_BLACK, DEFAULT_SCREEN_UNMUTE_TIME, MAIN_WINDOW);

    // send response to aeon
    //==> Send mail.
    APENGINE_MAILBOX_SEND(E_MBX_CLASS_CAPE
    /*Index*/           ,MB_CAPE_VOP_SETBLUESCREEN_RES
    /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
    /*ParameterCount*/  ,1
    /*p1*/              ,0
    /*p2*/              ,0
    /*p3*/              ,0
    /*p4*/              ,0
    /*p5*/              ,0
    /*p6*/              ,0
    /*p7*/              ,0
    /*p8*/              ,0
    /*p9*/              ,0
    /*p10*/             ,0);
}

static void _APEngine_VOP_Move(MBX_Msg MB_Message)
{
    //[01]:x
    //[23]:y
    //[45]:w
    //[67]:h
    U16 x, y, w, h;
    MS_WINDOW_TYPE tDstWin;

    x = ReadU16BE(&MB_Message.u8Parameters[0]);
    y = ReadU16BE(&MB_Message.u8Parameters[2]);
    w = ReadU16BE(&MB_Message.u8Parameters[4]);
    h = ReadU16BE(&MB_Message.u8Parameters[6]);

    tDstWin.x = x;
    tDstWin.y = y;
    tDstWin.width = w;
    tDstWin.height = h;
    MApp_Scaler_SetWindow(NULL, NULL, &tDstWin, stSystemInfo[MAIN_WINDOW].enAspectRatio, SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), MAIN_WINDOW);

    // send response to aeon
    //==> Send mail.
    APENGINE_MAILBOX_SEND(E_MBX_CLASS_CAPE
    /*Index*/           ,MB_CAPE_VOP_MOVE_RES
    /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
    /*ParameterCount*/  ,1
    /*p1*/              ,0
    /*p2*/              ,0
    /*p3*/              ,0
    /*p4*/              ,0
    /*p5*/              ,0
    /*p6*/              ,0
    /*p7*/              ,0
    /*p8*/              ,0
    /*p9*/              ,0
    /*p10*/             ,0);
}

static void _APEngine_VOP_Destroy(MBX_Msg MB_Message)
{
    UNUSED(MB_Message);

    // send response to aeon
    //==> Send mail.
    APENGINE_MAILBOX_SEND(E_MBX_CLASS_CAPE
    /*Index*/           ,MB_CAPE_VOP_DESTROY_RES
    /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
    /*ParameterCount*/  ,1
    /*p1*/              ,0
    /*p2*/              ,0
    /*p3*/              ,0
    /*p4*/              ,0
    /*p5*/              ,0
    /*p6*/              ,0
    /*p7*/              ,0
    /*p8*/              ,0
    /*p9*/              ,0
    /*p10*/             ,0);
}

#if ENABLE_DMP
static void _APEngine_Audio_ReloadCode(En_DVB_decSystemType enDecSystem)
{
    BOOLEAN bUserMute = msAPI_AUD_IsAudioMutedByUser();

    MApp_InputSource_ChangeAudioSource( stSystemInfo[MAIN_WINDOW].enInputSourceType );
    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYUSER_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);

    MApi_AUDIO_SetCommand(MSAPI_AUD_DVB_DECCMD_STOP);

    MApi_AUDIO_SetSystem(MSAPI_AUD_DVB_NONE);
    MApi_AUDIO_SetSystem(enDecSystem);
    if ( enDecSystem == MSAPI_AUD_DVB_MP3 )
    {
        MApi_AUDIO_SetSystem(MSAPI_AUD_DVB2_MP3);
        MApi_AUDIO_SetADOutputMode(AD_OUT_BOTH);//MDrv_MAD_SetAdMixMode(MAIN_MIX_AD, MIX_ON);
    }
    if (!bUserMute)
        msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYUSER_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);

    //force unmute ... the mute might be triggerrd from SIF which we can hardly
    // determine which type it is...
    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_PERMANENT_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);

    msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, stGenSetting.g_SoundSetting.Volume, 0);

}
static void _APEngine_Audio_Init(MBX_Msg MB_Message)
{
    //[0]:system
    //[12]:sample rate
    //[34]:bits per sample
    //[5]:channel number
    En_DVB_decSystemType enDecSystem = (En_DVB_decSystemType) MB_Message.u8Parameters[0];
    if ( enDecSystem == MSAPI_AUD_DVB_XPCM )
    {
        U16 u16SampleRate;
        U16 u16BitsPerSample;
        U8 u8CannelNumber;

        u16SampleRate = ReadU16BE(&MB_Message.u8Parameters[1]);
        u16BitsPerSample  = ReadU16BE(&MB_Message.u8Parameters[3]);
        u8CannelNumber = MB_Message.u8Parameters[5];

        //MDrv_MAD_XPCM_setParam(1, u8CannelNumber-1, u16SampleRate, u16BitsPerSample, 0, 0);
        MApi_AUDIO_XPCM_Param(LPCM, u8CannelNumber-1, u16SampleRate, u16BitsPerSample, 0, 0);
    }
    _APEngine_Audio_ReloadCode(enDecSystem);

    //fire mbx to send response to co-processor
    //==> Send mail.
    APENGINE_MAILBOX_SEND(E_MBX_CLASS_CAPE
    /*Index*/           ,MB_CAPE_AUDIO_INIT_RES
    /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
    /*ParameterCount*/  ,1
    /*p1*/              ,0
    /*p2*/              ,0
    /*p3*/              ,0
    /*p4*/              ,0
    /*p5*/              ,0
    /*p6*/              ,0
    /*p7*/              ,0
    /*p8*/              ,0
    /*p9*/              ,0
    /*p10*/             ,0);

    //MApi_AUDIO_SetCommand(MSAPI_AUD_DVB_DECCMD_PLAYFILE);
}
#endif

static void _APEngine_I8_Set(MBX_Msg MB_Message)
{

    U32 *pMsInitDataInRAM = NULL;

    U32 gs32ProtocolParameterBuffer = ReadU32BE( &MB_Message.u8Parameters[2]);

    U16 StartIndex = ReadU16BE(&MB_Message.u8Parameters[6]);
    U16 ColorCount = ReadU16BE(&MB_Message.u8Parameters[8]);

    pMsInitDataInRAM = (U32 *) KSEG02KSEG1(gs32ProtocolParameterBuffer);


    GOP_PaletteEntry * pPalArray = (GOP_PaletteEntry *) pMsInitDataInRAM;

    MApi_GOP_GWIN_2GSetPaletteOpt(pPalArray,StartIndex,StartIndex+ColorCount-1);
    //printf("SET=%d %d=====\n",StartIndex,ColorCount);
    // send response to aeon
    //==> Send mail.
    APENGINE_MAILBOX_SEND(E_MBX_CLASS_CAPE
    /*Index*/           ,MB_CAPE_I8_SET_RES
    /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
    /*ParameterCount*/  ,1
    /*p1*/              ,0
    /*p2*/              ,0
    /*p3*/              ,0
    /*p4*/              ,0
    /*p5*/              ,0
    /*p6*/              ,0
    /*p7*/              ,0
    /*p8*/              ,0
    /*p9*/              ,0
    /*p10*/             ,0);
    //printf("send SET RES \n");
}

static void _APEngine_I8_Get(MBX_Msg MB_Message)
{

    U32 *pMsInitDataInRAM = NULL;
    U32 i;

    U32 gs32ProtocolParameterBuffer = ReadU32BE( &MB_Message.u8Parameters[2]);
    pMsInitDataInRAM = (U32 *) KSEG02KSEG1(gs32ProtocolParameterBuffer);

    U16 StartIndex = ReadU16BE(&MB_Message.u8Parameters[6]);
    U16 ColorCount = ReadU16BE(&MB_Message.u8Parameters[8]);

    U32 *pPalArray = pMsInitDataInRAM;
    //printf("GET=====%d %d=====\n",StartIndex,ColorCount);
    for(i = 0;i<ColorCount;i++)
    {
        MApi_GOP_GWIN_2GReadPalette(StartIndex+i, (U32*)(pPalArray+i));
    }
    // send response to aeon
    //==> Send mail.
    APENGINE_MAILBOX_SEND(E_MBX_CLASS_CAPE
    /*Index*/           ,MB_CAPE_I8_GET_RES
    /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
    /*ParameterCount*/  ,1
    /*p1*/              ,0
    /*p2*/              ,0
    /*p3*/              ,0
    /*p4*/              ,0
    /*p5*/              ,0
    /*p6*/              ,0
    /*p7*/              ,0
    /*p8*/              ,0
    /*p9*/              ,0
    /*p10*/             ,0);
    // printf("send GET RES \n");
}

static void _APEngine_APP_Finalize_Done(MBX_Msg MB_Message)
{
    UNUSED(MB_Message);
    _bCAPEFinalizeIsDone= TRUE;
}

void msAPI_APEngine_APP_Finalize_Init(void)
{
    _bCAPEFinalizeIsDone= FALSE;
}

BOOLEAN msAPI_APEngine_APP_Finalize_Check(void)
{
    return _bCAPEFinalizeIsDone;
}

static void _APEngine_APP_Initialize_Done(MBX_Msg MB_Message)
{
    UNUSED(MB_Message);
    _bCAPEInitializeIsDone = TRUE;
    _u32CAPEAliveCount = msAPI_Timer_GetTime0();
}

BOOLEAN msAPI_APEngine_APP_Initialize_Check(void)
{
    return _bCAPEInitializeIsDone;
}

static void _APEngine_APP_Alive_Record(MBX_Msg MB_Message)
{
    UNUSED(MB_Message);
    _u32CAPEAliveCount = msAPI_Timer_GetTime0();
    //printf("got signal in %d\n", _u32CAPEAliveCount);
}

BOOLEAN msAPI_APEngine_APP_Alive_Check(void)
{
    if(msAPI_APEngine_APP_Initialize_Check())
    {
        if(msAPI_Timer_DiffTimeFromNow(_u32CAPEAliveCount) > ALIVE_CHECK_INTERVAL)
        {
            return FALSE;
        }
    }

    return TRUE;
}

static void _APEngine_File_Len_Info(MBX_Msg MB_Message)
{
    //get file info
    BININFO BinInfo;
    BinInfo.B_ID = ReadU32BE(&MB_Message.u8Parameters[0]);

    BOOLEAN bResult;
    MDrv_Sys_Get_BinInfo(&BinInfo, &bResult);
    if ( bResult != PASS )
    {
        printf( "Fail to find AEON binary on flash.\n" );
        return;
    }

    //fire mbx to send response to co-processor
    //==> Send mail.
    APENGINE_MAILBOX_SEND(E_MBX_CLASS_CAPE
    /*Index*/           ,MB_CAPE_FILE_LEN_RES
    /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
    /*ParameterCount*/  ,4
    /*p1*/              ,(U8)((BinInfo.B_Len & 0xFF000000) >> 24)
    /*p2*/              ,(U8)((BinInfo.B_Len & 0x00FF0000) >> 16)
    /*p3*/              ,(U8)((BinInfo.B_Len & 0x0000FF00) >> 8)
    /*p4*/              ,(U8)((BinInfo.B_Len & 0x000000FF))
    /*p5*/              ,0
    /*p6*/              ,0
    /*p7*/              ,0
    /*p8*/              ,0
    /*p9*/              ,0
    /*p10*/             ,0);
}

static void _APEngine_File_Copy2Dram(MBX_Msg MB_Message)
{
    //copy data
    BININFO BinInfo;
    BinInfo.B_ID = ReadU32BE(&MB_Message.u8Parameters[0]);

    BOOLEAN bResult;
    MDrv_Sys_Get_BinInfo(&BinInfo, &bResult);
    if ( bResult != PASS)
    {
        printf( "Fail to find AEON binary on flash.\n" );
        return;
    }

    U32 u32StartAddr = ReadU32BE(&MB_Message.u8Parameters[4]);

    //U8 u8MIUProtectAeon_ID[2];
    //u8MIUProtectAeon_ID[0] = MIU_CLI_AEON_RW;
    //u8MIUProtectAeon_ID[1] = 0;
    //MDrv_MIU_Protect(2, u8MIUProtectAeon_ID, u32StartAddr, u32StartAddr+BinInfo.B_Len-1, DISABLE);
    if( TRUE != MDrv_SERFLASH_CopyHnd(BinInfo.B_FAddr, u32StartAddr, (BinInfo.B_Len+0x07)&~0x07, E_SPIDMA_DEV_MIU0, SPIDMA_OPCFG_DEF) )
    {
        //printf( "Font bin is copyed failed\n" );
    }

    //fire mbx to send response to co-processor
    //==> Send mail.
    APENGINE_MAILBOX_SEND(E_MBX_CLASS_CAPE
    /*Index*/           ,MB_CAPE_FILE_COPY_RES
    /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
    /*ParameterCount*/  ,1
    /*p1*/              ,1
    /*p2*/              ,0
    /*p3*/              ,0
    /*p4*/              ,0
    /*p5*/              ,0
    /*p6*/              ,0
    /*p7*/              ,0
    /*p8*/              ,0
    /*p9*/              ,0
    /*p10*/             ,0);
}

void msAPI_APEngine_ProcessMailBox(void)
{
    MBX_Msg MB_Message;
    if( E_MBX_SUCCESS == MSApi_MBX_RecvMsg(E_MBX_CLASS_CAPE, &MB_Message, 0, MBX_CHECK_NORMAL_MSG) )
    {
        if ( E_MBX_CLASS_CAPE == MB_Message.u8MsgClass ) //command class
        {
            switch (MB_Message.u8Index)
            {
                case MB_CAPE_GWIN_CREATE_REQ:
                    _APEngine_GWIN_Create(MB_Message);
                    break;

                case MB_CAPE_GWIN_ENABLE_REQ:
                    _APEngine_GWIN_Enable(MB_Message);
                    break;

                case MB_CAPE_GWIN_MOVE_REQ:
                    _APEngine_GWIN_Move(MB_Message);
                    break;

                case MB_CAPE_GWIN_DESTROY_REQ:
                    _APEngine_GWIN_Destroy(MB_Message);
                    break;

                case MB_CAPE_VOP_INIT_REQ:
                    _APEngine_VOP_Init(MB_Message);
                    break;

                case MB_CAPE_VOP_SETBLUESCREEN_REQ:
                    _APEngine_VOP_SetBlueScreen(MB_Message);
                    break;

                case MB_CAPE_VOP_MOVE_REQ:
                    _APEngine_VOP_Move(MB_Message);
                    break;

                case MB_CAPE_VOP_DESTROY_REQ:
                    _APEngine_VOP_Destroy(MB_Message);
                    break;

#if ENABLE_DMP
                case MB_CAPE_AUDIO_INIT_REQ:
                    _APEngine_Audio_Init(MB_Message);
                    break;
#endif
                case MB_CAPE_I8_SET_REQ:
                    _APEngine_I8_Set(MB_Message);
                    break;

                case MB_CAPE_I8_GET_REQ:
                    _APEngine_I8_Get(MB_Message);
                    break;

                case MB_CAPE_APP_FINALIZED_SIG:
                     //printf("======= received MB_CAPE_APP_FINALIZE_REQ===========\n");
                     _APEngine_APP_Finalize_Done(MB_Message);
                     break;

                case MB_CAPE_APP_ALIVE_SIG:
                     //printf("======= CAPE is ALIVE===========\n");
                     _APEngine_APP_Alive_Record(MB_Message);
                     break;

                case MB_CAPE_APP_INITIALIZED_SIG:
                     //printf("======= received MB_CAPE_APP_INITIALIZE_REQ===========\n");
                     _APEngine_APP_Initialize_Done(MB_Message);
                     break;


                case MB_CAPE_FILE_LEN_REQ:
                     _APEngine_File_Len_Info(MB_Message);
                     break;

                case MB_CAPE_FILE_COPY_REQ:
                     _APEngine_File_Copy2Dram(MB_Message);
                     break;

                default:
                    break;
            }
        }
        else
        {
            //assert
            __ASSERT(FALSE);
        }
    }
}

/******************************************************************************/
///- This API is for transmitting IR key to CAPE
/// @param u8Key \b IN: IR Key to transmit
/// @param Status \b IN: status for Aeon
/******************************************************************************/
void msAPI_APEngine_TransmitKey(U8 u8Key)
{
#if OBA2
    msAPI_APEngine_Obama_TransmitKey(u8Key);
#else
    //==> Send mail.
    APENGINE_MAILBOX_SEND(E_MBX_CLASS_INPUT
    /*Index*/           ,MB_INPUT_CMD_IR
    /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
    /*ParameterCount*/  ,1
    /*p1*/              ,u8Key
    /*p2*/              ,0
    /*p3*/              ,0
    /*p4*/              ,0
    /*p5*/              ,0
    /*p6*/              ,0
    /*p7*/              ,0
    /*p8*/              ,0
    /*p9*/              ,0
    /*p10*/             ,0);
#endif
}

/******************************************************************************/
///- This API is for transmitting IR key to CAPE
/// @param u8Key \b IN: IR Key to transmit
/// @param Status \b IN: status for Aeon
/******************************************************************************/
void msAPI_APEngine_TransmitJoystick(U16 u16State)
{
    //==> Send mail.
    APENGINE_MAILBOX_SEND(E_MBX_CLASS_INPUT
    /*Index*/           ,MB_INPUT_CMD_JOYSTICK
    /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
    /*ParameterCount*/  ,2
    /*p1*/              ,u16State & 0xff
    /*p2*/              ,u16State >> 8
    /*p3*/              ,0
    /*p4*/              ,0
    /*p5*/              ,0
    /*p6*/              ,0
    /*p7*/              ,0
    /*p8*/              ,0
    /*p9*/              ,0
    /*p10*/             ,0);
}


//For CAPE combined-bin
/******************************************************************************/
//The header fields(total 512 bytes):
    //[01234]:magic number
    //[5]:APP type(0: APP, 1: GAME)
    //[678]:APP file entension(APP, NES, SMC, etc.)
    //[9abcdef]:APP note
    //[0123]>>1:CRC value
    //[4567]>>1:romfs length
    //[89ab]>>1:executable length
    //[cdef]>>1:compressed bin length
    //32 bytes reserved
    //448 bytes version check
/******************************************************************************/
BOOLEAN msAPI_APEngine_AppIsHeaderValid(U8 u8Type, U8 *pHeader, U16 u16HeaderLen)
{
    if ( u16HeaderLen != APP_HEADER_LENGTH )
    {
        return FALSE;
    }

    // check type
    U8 u8HeaderType = pHeader[5];
    if ( (u8Type != APP_DONT_CARE) && (u8HeaderType != u8Type) )
    {
        printf("APEngine: Bin file type error!\n");
        return FALSE;
    }

    // check magic number
    if( pHeader[0] != 0x09 ||
        pHeader[1] != 0x58 ||
        pHeader[2] != 0x33 ||
        pHeader[3] != 0x69 ||
        pHeader[4] != 0x00
    )
    {
        printf("APEngine: %02x %02x %02x %02x %02x magic number error\n!!", pHeader[0], pHeader[1], pHeader[2], pHeader[3], pHeader[4]);
        return FALSE;
    }

    return TRUE;

}

BOOLEAN msAPI_APEngine_AppIsContentValid(U8 *pContent, U32 u32ContentLen)
{
    // parsing APP header
    if ( u32ContentLen < APP_HEADER_LENGTH )
    {
        return FALSE;
    }

    U8 *pHeader = (U8*) (pContent + u32ContentLen - APP_HEADER_LENGTH);

    // check crc
    U32 u32CRC = ReadU32BE(&pHeader[16]);
    U32 u32BinFileLen = ReadU32BE(&pHeader[28]);

    // compute HW crc
    U32 u32CRCResult = MDrv_BDMA_CRC32((U32)pContent, u32BinFileLen , BDMA_CRC32_POLY, BDMA_CRC_SEED_0, E_BDMA_SRCDEV_MIU0, FALSE);

    if (u32CRCResult != u32CRC)
    {
        printf(" HW CRC error: u32CRCResult=0x%08lx, u32CRC=0x%08lx\n", u32CRCResult, u32CRC);
        // start SW crc patch check
        {
            U8  u8bit;
            U32 u32Remainder = u32CRCResult;
            U32 u32Width = 32;
            U32 u32Topbit = (1 <<(u32Width-1) );

            u32Remainder ^= pContent[u32BinFileLen-1] << (u32Width - 8);

            for (u8bit = 8; u8bit > 0; --u8bit)
            {

                if (u32Remainder & u32Topbit)
                {
                    u32Remainder = (u32Remainder << 1) ^ BDMA_CRC32_POLY;
                }
                else
                {
                    u32Remainder = (u32Remainder << 1);
                }
            }
            u32CRCResult = u32Remainder ^ BDMA_CRC_SEED_0;
        }

        if (u32CRCResult != u32CRC)
        {
            printf(" SW CRC error: u32CRCResult=0x%08lx, u32CRC=0x%08lx\n", u32CRCResult, u32CRC);
            return FALSE;
        }
    }

    return TRUE;
}

BOOLEAN msAPI_APEngine_GetExtension(U8 *pExtension, U8 u8ExtLen, U8 *pHeader, U16 u16HeaderLen)
{
    if ( u16HeaderLen != APP_HEADER_LENGTH )
    {
        return FALSE;
    }

    if (u8ExtLen < 4)
    {
        return FALSE;
    }

    strncpy((char*)pExtension, (char*)&pHeader[6], 3);
    return TRUE;
}

#if ENABLE_MPLAYER_PLUGIN
static BOOLEAN _APEngine_SendRomFsSize(void)
{
    U8 u8Info[4];

    u8Info[0] = (U8)((_u32RomFsSize)     &0xFF);
    u8Info[1] = (U8)((_u32RomFsSize>>8)  &0xFF);
    u8Info[2] = (U8)((_u32RomFsSize>>16) &0xFF);
    u8Info[3] = (U8)((_u32RomFsSize>>24) &0xFF);
    if( E_MBX_SUCCESS != MSApi_MBX_SetInformation(&u8Info[0], 4) )
    {
        return FALSE;
    }

    return TRUE;
}
#endif

#if ENABLE_MPLAYER_PLUGIN
static BOOLEAN _APEngine_InitMBX(void)
{
    if(E_MBX_SUCCESS != MSApi_MBX_RegisterMSG(E_MBX_CLASS_CAPE, MAX_MBX_QUEUE_SIZE/8))
    {
        if(E_MBX_SUCCESS != MSApi_MBX_UnRegisterMSG(E_MBX_CLASS_CAPE))
        {
            return FALSE;
        }
        else
        {
            if(E_MBX_SUCCESS != MSApi_MBX_RegisterMSG(E_MBX_CLASS_CAPE, MAX_MBX_QUEUE_SIZE/8))
            {
                return FALSE;
            }
        }
    }
    return TRUE;
}

BOOLEAN msAPI_APEngine_AppRun(U32 u32AppBinaryAddr, U32 u32Len, U32 u32BEON_ADR, U32 u32BEON_LEN)
{
    U8 *pHeader = (U8*)(_PA2VA(u32AppBinaryAddr) + u32Len - APP_HEADER_LENGTH);

    // decompress
    U32 ResBinLen = ReadU32BE(&pHeader[20]);
    U32 AppBinLen = ReadU32BE(&pHeader[24]);

    if ( AppBinLen > u32BEON_LEN )
    {
        printf("app too large to fit: app=%08lx, cape=%08lx\n", AppBinLen, u32BEON_LEN);
        return FALSE;
    }
    if ( ResBinLen > CAPE_BUFFER_LEN )
    {
        printf("resource too large to fit: res=%08lx, cape=%08lx\n", ResBinLen, (U32)CAPE_BUFFER_LEN);
        return FALSE;
    }
    if (ms_DecompressInit((U8*)_PA2VA(((CAPE_BUFFER_MEMORY_TYPE & MIU1) ? (CAPE_BUFFER_ADR | MIU_INTERVAL) : (CAPE_BUFFER_ADR)))) == FALSE)
    {
        printf("decompress fail!\n");
        return FALSE;
    }
    ms_Decompress((U8*)_PA2VA(u32AppBinaryAddr), u32Len-APP_HEADER_LENGTH);
    ms_DecompressDeInit();

    // init romfs size
    _u32RomFsSize = 0;

    MsOS_DisableInterrupt(E_INT_FIQ_AEON_TO_BEON);
    MsOS_DisableInterrupt(E_INT_FIQ_BEON_TO_AEON);
#if defined(MIPS_CHAKRA) || defined(__AEONR2__)
    MDrv_COPRO_Disable();
#else
#if OBA2==0
    MDrv_COPRO_Disable();
#endif
#endif

    U8 u8MIUProtectAeon_ID[2];
    u8MIUProtectAeon_ID[0] = MIU_CLIENT_MHEG5_ICACHE_RW;
    u8MIUProtectAeon_ID[1] = 0;

    //MDrv_WriteByte(0x33DE , 0x02); // for aeon judgement

    MDrv_MIU_Protect(2, &u8MIUProtectAeon_ID[0], u32BEON_ADR, u32BEON_ADR+ALIGNED_VALUE(AppBinLen, 8)-1, DISABLE);
    U32 BinAddr = _PA2VA((CAPE_BUFFER_MEMORY_TYPE & MIU1) ? (CAPE_BUFFER_ADR | MIU_INTERVAL) : (CAPE_BUFFER_ADR))+ResBinLen ;
    MDrv_BDMA_CopyHnd(BinAddr, u32BEON_ADR, ALIGNED_VALUE(AppBinLen,8), E_BDMA_SDRAM2SDRAM, BDMA_OPCFG_DEF);

    {
        // error check, temporarily
        U32 *u32Ptr = (U32*)_PA2VA(u32BEON_ADR);
        if ( (*u32Ptr)==0xFFFFFFFF )
        {
            printf("MDrv_BDMA_CopyHnd to 0x%08lx[len=%lu] failed\n", _PA2VA(u32BEON_ADR), (U32)GE_ALIGNED_VALUE(AppBinLen,8));
        }
    }

    _u32RomFsSize = ALIGNED_VALUE(ResBinLen, 8);

#if defined(MIPS_CHAKRA) || defined(__AEONR2__)
    msAPI_COPRO_Init_ByAddr(u32BEON_ADR, u32BEON_LEN);
#else
#if OBA2
#else
    msAPI_COPRO_Init_ByAddr(u32BEON_ADR, u32BEON_LEN);
#endif
#endif

    if( !_APEngine_InitMBX() )
    {
        printf("mailbox error\n");
        return FALSE;
    }

    if( !msAPI_MMap_SendMMapAddr_CAPE() )
    {
        printf("send mmap information error\n");
        return FALSE;
    }
    if( !_APEngine_SendRomFsSize() )
    {
        printf("send romfs error\n");
        return FALSE;
    }

    return TRUE;

}

BOOLEAN msAPI_APEngine_AppRunByBinID(U16 u16BinID, U32 u32BEON_ADR, U32 u32BEON_LEN)
{
    BININFO BinInfo;
    U8 *pHeader;
    BinInfo.B_ID = u16BinID;
    BOOLEAN bResult;

    MDrv_Sys_Get_BinInfo(&BinInfo, &bResult);
    if ( bResult != PASS)
    {
        printf("Fail to find binary on flash.\n");
        return FALSE;
    }

    // init romfs size
    _u32RomFsSize = 0;

    ///-Note: BinIDPackFiles.py would pad '8' bytes in the end of file.
    U32 u32ContentSize = ALIGNED_VALUE(BinInfo.B_Len,8) - 8;

    U32 u32TmpAddr = (_PA2VA((CAPE_BUFFER_MEMORY_TYPE & MIU1) ? (CAPE_BUFFER_ADR | MIU_INTERVAL) : (CAPE_BUFFER_ADR)) + CAPE_BUFFER_LEN - BinInfo.B_Len) & ~(8-1); //8 bytes alignment

    ///-Copy firmware code from flash to SDRAM
#ifdef SUPPORT_AP_BIN_IN_FLASH_2
    InfoBlock_Flash_2_Checking_Start(&BinInfo);
#endif

    MDrv_SERFLASH_CopyHnd(BinInfo.B_FAddr, u32TmpAddr, ALIGNED_VALUE(BinInfo.B_Len,8), E_SPIDMA_DEV_MIU0, SPIDMA_OPCFG_DEF);

#ifdef SUPPORT_AP_BIN_IN_FLASH_2
    InfoBlock_Flash_2_Checking_End(&BinInfo);
#endif

    pHeader = (U8*) _PA2VA((u32TmpAddr + u32ContentSize - APP_HEADER_LENGTH));
    if (msAPI_APEngine_AppIsHeaderValid(APP_DONT_CARE, pHeader, APP_HEADER_LENGTH))
    {
        if (msAPI_APEngine_AppIsContentValid((U8*)u32TmpAddr,  u32ContentSize))
        {
            if (!msAPI_APEngine_AppRun(u32TmpAddr, u32ContentSize, u32BEON_ADR, u32BEON_LEN))
            {
                return FALSE;
            }
        }
        else
        {
            printf("Invalid Contents.\n");
            return FALSE;
        }
    }
    else
    {
        MsOS_DisableInterrupt(E_INT_FIQ_AEON_TO_BEON);
        MsOS_DisableInterrupt(E_INT_FIQ_BEON_TO_AEON);
#if defined(MIPS_CHAKRA) || defined(__AEONR2__)
        MDrv_COPRO_Disable();
#else
#if OBA2
#else
        MDrv_COPRO_Disable();
#endif
#endif

        U8 u8MIUProtectAeon_ID[2];
        u8MIUProtectAeon_ID[0] = MIU_CLIENT_MHEG5_ICACHE_RW;
        u8MIUProtectAeon_ID[1] = 0;

        MDrv_WriteByte(0x33DE , 0x02); // for aeon judgement

      #if 0
        printf( "AEON code flash:0x%08LX --> DRAM:0x%08LX, length=0x%08LX->0x%08LX\n",
        BinInfo.B_FAddr, u32BEON_ADR, BinInfo.B_Len, GE_ALIGNED_VALUE(BinInfo.B_Len,8));
      #else // Modified it by coverity_0487
        printf( "AEON code flash:0x%08lx --> DRAM:0x%08lx, length=0x%08lx->0x%08lx\n",
        BinInfo.B_FAddr, u32BEON_ADR, BinInfo.B_Len, GE_ALIGNED_VALUE(BinInfo.B_Len,8));
      #endif
        MDrv_MIU_Protect(2, &u8MIUProtectAeon_ID[0], u32BEON_ADR, u32BEON_ADR+ALIGNED_VALUE(BinInfo.B_Len,8)-1, DISABLE);

    #ifdef ENABLE_KTV
        msAPI_Timer_Delayms(200);
    #endif

        ///-Copy firmware code from flash to SDRAM
        MDrv_SERFLASH_CopyHnd(BinInfo.B_FAddr, u32BEON_ADR, GE_ALIGNED_VALUE(BinInfo.B_Len,8), E_SPIDMA_DEV_MIU0, SPIDMA_OPCFG_DEF);
        {
            // error check, temporarily
            U32 *u32Ptr = (U32*)u32BEON_ADR;
            if ( (*u32Ptr)==0xFFFFFFFF )
            {
                printf("MDrv_SERFLASH_CopyHnd to 0x%08lx[len=%lu] failed\n", u32BEON_ADR, (U32)GE_ALIGNED_VALUE(BinInfo.B_Len,8));
            }
        }

        msAPI_COPRO_Init_ByAddr(u32BEON_ADR, u32BEON_LEN);
        msAPI_MMap_SendMMapAddr_CAPE();
        _APEngine_SendRomFsSize();
    }

    return TRUE;

}
#endif

#if OBA2
#include <sched.h>
#include <sys/time.h>
#include <signal.h>
#include <pthread.h>

extern void MAdp_APMNG_SetRegisterCallback(AppRegCallback pRegCB);
extern void MAdp_APMNG_SetExeCallback(AppExeCallback pExeCB);

#if (OBA2 == 1)
//-------------------------------------------------------------------------------------------------
// Macros (OBA2)
//-------------------------------------------------------------------------------------------------

#define SVD_USING_MIU1             0x80000000 //use bit31 to inform co-processor use MIU1

//For music init
#define INIT_VOLUME stGenSetting.g_SoundSetting.Volume
#define AUDIO_SPDIF_ENABLE  0
#if (ENABLE_SUBTITLE && ENABLE_SBTVD_BRAZIL_APP == 0 && OBA2 == 0)
#define ENABLE_SUBTITLE_TS  1
#else
#define ENABLE_SUBTITLE_TS  0
#endif
#define  Remove_enumVDPlayerAckFlags(val, flag) \
   do{(val) = (enumVDPlayerAckFlags)(((U16)(val))&~(U16)(flag));}while(0)
/******************************************************/
/* Enum (OBA2)                                        */
/******************************************************/

typedef enum
{
    E_ACKFLG_NULL = 0,
    E_ACKFLG_WAIT_INIT = BIT0,
    E_ACKFLG_WAIT_GET_DRM_REG_CODE = BIT1,
    E_ACKFLG_WAIT_CHECK_DRM_AUTHORIZATION = BIT2,
    E_ACKFLG_WAIT_QUERY_DRM_RENTAL_STATUS = BIT3,
    E_ACKFLG_WAIT_STOP = BIT4,
    E_ACKFLG_WAIT_GET_SUBTITLE_STATE = BIT5,
    E_ACKFLG_WAIT_GET_DRM_REG_CODE_2 = BIT6,
    E_ACKFLG_WAIT_GET_DRM_DEACTIVATION_CODE = BIT7,
    E_ACKFLG_WAIT_PLAY = BIT8,
    E_ACKFLG_WAIT_REPEAT_AB = BIT9,
} enumVDPlayerAckFlags;
#endif
//-------------------------------------------------------------------------------------------------
// Local Variables (OBA2)
//-------------------------------------------------------------------------------------------------

static pid_t pre_avtivated_ap;
static BOOLEAN bMuteFlag = 0;
static BOOLEAN bAPRegisting = 0;
#if 0 // removed: (OBA2 == 1)
static enumVDPlayerAckFlags enVDPlayerAckFlags = E_ACKFLG_NULL;
static VDPLAYER_VIDEO_TYPE enVDPlayerVideoType;
static EN_RET enVDPlayerRet = EXIT_NULL;
static VIDEO_PLAYER_PLAYING_TYPE enVideoPlayerPlayingType=VIDEO_PLAYER_PLAYING_TYPE_MPEG4;
static enumVDPlayerFlags  enVDPlayerFlgs=E_VDPLAYER_FLG_SHOWVIDEO;

static U8 u8VDPlayerInitResult = 0;
// RM used
static U16 u16CodecNum = 0;
static U16 u16Samples_channel = 0;

static U16 u16CannelsA[5] ={0,0,0,0,0};
static U16 u16RegionsA[5] = {0,0,0,0,0};
static U16 u16cplStartA[5] ={0,0,0,0,0};
static U16 u16cplQbitsA[5] = {0,0,0,0,0};
static U16 u16FrameSizeA[5] = {0,0,0,0,0};
static U32 u32VDPlayerLoopWdtTimer = 0;
static U32 u32VdplayerShareMemAddr;

static BOOLEAN bVDPlayerPreview=FALSE;
//static BOOLEAN bCoprocessorEnable = FALSE;
static BOOLEAN bPlaying = FALSE;
static BOOLEAN bResume = FALSE;
static BOOLEAN bPause = FALSE;
static BOOLEAN bStop = FALSE;
static BOOLEAN bInit = FALSE;
static BOOLEAN bSendMetadata = FALSE;
static U32 u32VDPlayerUpdateTimer = 0;
static U32 u32InitDisplayX = 0;
static U32 u32InitDisplayY = 0;
static U32 u32InitDisplayWidth = 0;
static U32 u32InitDisplayHeight = 0;

#endif
//-------------------------------------------------------------------------------------------------
// Function Implementation (OBA2)
//-------------------------------------------------------------------------------------------------

static void _msAPI_APEngine_Obama_VOP_Init(U16 u16Width, U16 u16Height, U32 u32BuffAddr, U16 u16DisplayWidth, U16 u16DisplayHeight)
{
    MVOP_VidStat stMvopVidSt;
    U16 u16DisplayX, u16DisplayY;
    u16DisplayX = 0;
    u16DisplayY = 0;
#ifdef CHIP_S7LD
    gstVidStatus.u32FrameRate = 30000;
#else
    gstVidStatus.u32FrameRate =60000;
#endif

    MDrv_MVOP_Init();
    {
        MVOP_InputCfg dc_param;
        #if 0
        MS_SYS_INFO enMsSysInfo;
        #endif

        // Enable Blue Screen
        msAPI_Scaler_SetBlueScreen(ENABLE, E_XC_FREE_RUN_COLOR_BLACK, DEFAULT_SCREEN_UNMUTE_TIME, MAIN_WINDOW);

        MApi_XC_GenerateBlackVideo(ENABLE, MAIN_WINDOW);

        MDrv_MVOP_Init();

    //Refine: When we enter MM or Internet APs, input source type already be set to INPUT_SOURCE_STORAGE and
    //          msAPI_Scaler_SetSourceType() was called. So, we don't need to set source type again.
#if 0
         // set Scaler input source
        SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW) = INPUT_SOURCE_STORAGE;
        enMsSysInfo.enDataInputSourceType = DATA_INPUT_SOURCE_STORAGE;
        enMsSysInfo.enInputSourceType = INPUT_SOURCE_STORAGE;
        enMsSysInfo.enAspectRatio = VIDEOSCREEN_NORMAL;
        msAPI_Scaler_SetSourceType(enMsSysInfo.enInputSourceType,OUTPUT_SCALER_MAIN_WINDOW);
#endif
        // set mvop parameters
        //=========JPEG TETS==========
        dc_param.u16HSize = u16Width;
        dc_param.u16VSize = u16Height;
        dc_param.u32YOffset = u32BuffAddr;
        dc_param.u32UVOffset = u32BuffAddr+8;//No Use, in MDrv_VOP_Input_Mode, it will be reset
        dc_param.bSD = 1;
        dc_param.bYUV422 = 1;
        dc_param.bProgressive = 1;
        dc_param.bUV7bit = 0;
        dc_param.bDramRdContd = 1;
        dc_param.bField = 0;
        dc_param.b422pack = 1;
        dc_param.u16StripSize = dc_param.u16HSize;
        MDrv_MVOP_SetInputCfg(MVOP_INPUT_DRAM, &dc_param);

        gstVidStatus.u16HorSize = dc_param.u16HSize;
        gstVidStatus.u16VerSize = dc_param.u16VSize;
        gstVidStatus.u8AspectRate = ASP_4TO3;   //ASP_16TO9;
        gstVidStatus.u8Interlace = 0;
    }

    U32 u32Width, u32Height;
    u32Width = (U32)gstVidStatus.u16HorSize;
    u32Height = (U32)gstVidStatus.u16VerSize;

    memset(&stMvopVidSt, 0, sizeof(MVOP_VidStat));
    stMvopVidSt.u16HorSize   = gstVidStatus.u16HorSize;
    stMvopVidSt.u16VerSize   = gstVidStatus.u16VerSize;
    stMvopVidSt.u16FrameRate = gstVidStatus.u32FrameRate;
    stMvopVidSt.u8AspectRate = gstVidStatus.u8AspectRate;
    stMvopVidSt.u8Interlace  = gstVidStatus.u8Interlace;
    MDrv_MVOP_SetOutputCfg(&stMvopVidSt, FALSE);

    {
        U16 displayX, displayY, displayHSize, displayVSize;
        MS_WINDOW_TYPE tDstWin,tCropWin;
        S32 s32QuotientDiff, s32RemainderDiff;

        // set scaling aspect to program
        // [071017 Andy] set to original aspect
        stSystemInfo[MAIN_WINDOW].enAspectRatio = VIDEOSCREEN_ORIGIN;

        #if 0
        if(enVDPlayerFlgs & E_VDPLAYER_FLG_PREVIEW)
        {
            u16DisplayX = MOVIE_PREVIEW_X;
            u16DisplayY = MOVIE_PREVIEW_Y;
            u16DisplayWidth = MOVIE_PREVIEW_WIDTH;
            u16DisplayHeight = MOVIE_PREVIEW_HEIGHT;
        }
        #endif

        // Set to the original aspect ratio
        s32QuotientDiff = ((((U32)u16DisplayWidth * 32) / (U32)u16DisplayHeight) - (((U32)u16Width * 32) / (U32)u16Height));
        s32RemainderDiff = ((((U32)u16DisplayWidth * 32) % (U32)u16DisplayHeight) - (((U32)u16Width * 32) % (U32)u16Height));
        // Set to the original aspect ratio
        if ((s32QuotientDiff > 0)
                || ((s32QuotientDiff == 0) && (s32RemainderDiff > 0)))
        {
            // Height major
            displayHSize = (U16)(((U32)u16DisplayHeight * 32 / (U32)u16Height) *
                                  (U32)u16Width / 32) & 0xFFFE;
            displayX = u16DisplayX + (u16DisplayWidth - displayHSize) / 2;
            displayY = u16DisplayY;
            displayVSize = u16DisplayHeight;
        }
        else
        {
            // Width major
            displayVSize = (U16)(((U32)u16DisplayWidth * 32 / (U32)u16Width) *
                                  (U32)u16Height / 32) & 0xFFFE;
            displayY = u16DisplayY + (u16DisplayHeight - displayVSize) / 2;
            displayX = u16DisplayX;
            displayHSize = u16DisplayWidth;
        }

        {

            tCropWin.x = displayX;
            tCropWin.y = displayY;
            tCropWin.width = displayHSize;
            tCropWin.height = displayVSize;

            tDstWin.x = displayX;
            tDstWin.y = displayY;
            tDstWin.width = displayHSize;
            tDstWin.height = displayVSize;

            MApp_Scaler_EnableOverScan(FALSE);
            MApp_Scaler_SetWindow(NULL, &tCropWin, &tDstWin, stSystemInfo[MAIN_WINDOW].enAspectRatio,
                                                   SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), MAIN_WINDOW);
        }

        //switch MIU to 0
        MDrv_MVOP_MiuSwitch(0);

        MDrv_MVOP_Enable(TRUE);

        MApp_Picture_Setting_SetColor(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), MAIN_WINDOW);
        msAPI_Scaler_SetBlueScreen(ENABLE, E_XC_FREE_RUN_COLOR_BLACK, DEFAULT_SCREEN_UNMUTE_TIME, MAIN_WINDOW);
    }

}
static void _msAPI_APEngine_Obama_VOP_SetBlueScreen(U8 enable)
{
    msAPI_Scaler_SetBlueScreen(enable, E_XC_FREE_RUN_COLOR_BLACK, DEFAULT_SCREEN_UNMUTE_TIME, MAIN_WINDOW);
}

static void _msAPI_APEngine_Obama_VOP_Move(U16 x,U16 y,U16 w,U16 h, U16 dw)
{
    MS_WINDOW_TYPE tDstWin,tCropWin;
    tCropWin.x = x;
    tCropWin.y = y;
    tCropWin.width = dw;
    tCropWin.height = h;

    tDstWin.x = x;
    tDstWin.y = y;
    tDstWin.width = w;
    tDstWin.height = h;

    MApp_Scaler_SetWindow(NULL, &tCropWin, &tDstWin, stSystemInfo[MAIN_WINDOW].enAspectRatio, SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), MAIN_WINDOW);
}

static void _msAPI_APEngine_Obama_VOP_Destroy(void)
{
    MDrv_MVOP_Enable( FALSE );
    #if (ENABLE_MIU_1 == ENABLE)
    //switch MIU to 1
    MDrv_MVOP_MiuSwitch(1);
    #endif
}

#if 0 // removed: (OBA2 == 1)
U32 _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(U16 idx_ptr)
{
    U32 idx_data;
    U32 addr = (u32VdplayerShareMemAddr) + (idx_ptr << 2);
    idx_data = *(U32 *)_PA2VA(addr) ;

    //return U32_SWAP(idx_data);
    return idx_data;
}

U32 _msAPI_APEngine_Obama_VDPlayer_GetInfo(EN_VDPLAYER_INFO enInfo)
{
    switch(enInfo)
    {
        case E_VDPLAYER_INFO_TOTAL_TIME:
            return _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_TOTAL_TIME);
        case E_VDPLAYER_INFO_CUR_TIME:
            return _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_CURRENT_TIME);
        case E_VDPLAYER_INFO_FRM_PER_SEC:
            return _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_FRAME_RATE);
        case E_VDPLAYER_INFO_DEMUX_H_SIZE:
            return _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_DEMUX_WIDTH);
        case E_VDPLAYER_INFO_DEMUX_V_SIZE:
            return _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_DEMUX_HEIGHT);
        case E_VDPLAYER_INFO_H_SIZE:
            {
                U32 u32Width = _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_WIDTH);
                if(u32Width > (gstVidStatus.u16CropLeft + gstVidStatus.u16CropRight)
                    && (gstVidStatus.u16CropLeft + gstVidStatus.u16CropRight) > 0)
                {
                    u32Width -= (gstVidStatus.u16CropLeft + gstVidStatus.u16CropRight);
                }
                return u32Width;
            }
        case E_VDPLAYER_INFO_V_SIZE:
            {
                U32 u32Height = _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_HEIGHT);
                if(u32Height > (gstVidStatus.u16CropTop + gstVidStatus.u16CropBottom)
                    && (gstVidStatus.u16CropTop + gstVidStatus.u16CropBottom) > 0)
                {
                    u32Height -= (gstVidStatus.u16CropTop + gstVidStatus.u16CropBottom);
                }
                return u32Height;
            }
        case E_VDPLAYER_INFO_NB_AUDIO_TRACK:
            return _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_TOTAL_ADUIO_TRACK);
        case E_VDPLAYER_INFO_AUDIO_TRACK_ID:
            return _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_CURRENT_AUDIO_TRACK_ID);
        case E_VDPLAYER_INFO_NB_SUBTITLE_TRACK:
            return _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_TOTAL_SUBTITLE);
        case E_VDPLAYER_INFO_SUBTITLE_TRACK_ID:
            return _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_CURRENT_SUBTITLE_TRACK_ID);
        case E_VDPLAYER_INFO_CURRENT_SUBTITLE_TEXT:
            return _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_CURRENT_SUBTITLE_TEXT);
        case E_VDPLAYER_INFO_CURRENT_SUBTITLE_TAGCOUNT:
            return _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_CURRENT_SUBTITLE_TAGCOUNT);
        case E_VDPLAYER_INFO_CURRENT_SUBTITLE_ISUNICODE:
            return _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_CURRENT_SUBTITLE_ISUNICODE);
        case E_VDPLAYER_INFO_ERROR_INFO:
            return _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_ERROR_INFO);
        case E_VDPLAYER_INFO_MAX_FB_SPEED:
            return _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_MAX_FAST_BACKWARD_SPEED);
        case E_VDPLAYER_INFO_PAR_H_SIZE:
            return _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_PAR_WIDTH);
        case E_VDPLAYER_INFO_PAR_V_SIZE:
            return _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_PAR_HEIGHT);
        case E_VDPLAYER_INFO_NB_PROGRAM:
            return _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_TS_PROGRAM_NUM);
        case E_VDPLAYER_INFO_PROGRAM_ID:
            return _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_TS_CUR_PROGRAM_IDX);
        case E_VDPLAYER_INFO_Audio_Request_Size:
            return _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_AUDIO_REQUEST_SIZE);
        default:
            return 0;
    }
}

void _msAPI_APEngine_Obama_VDPlayer_AdjustRatioByPAR(U16 u16Hsize, U16 u16Vsize, U32 u32PAR_H, U32 u32PAR_V, U16* u16TargetH, U16* u16TargetV )
{
    U16 _u16TargetH, _u16TargetV, u16OriginalRatio, u16Temp;

    if ((u32PAR_H == 0xffffffff)
            && (u32PAR_V == 0xffffffff))
    {
        u32PAR_H = u32PAR_V = 1;
    }

    _u16TargetH = u16Hsize;
    _u16TargetV = u16Vsize;
    //printf(" par H : %lu  par V : %lu \n", u32PAR_H , u32PAR_V);
    if ( u32PAR_H > 0 &&  u32PAR_V > 0 )
    {
        /*
            If the source contain PAR information, the ratio of displaywindow have to be re-calculate again.
            The final displaywindow ratio should be equal to ( ( Hcap * Par_width ) / ( Vcap * Par_height ) )

            The algorithm : Change the current aspect ratio to ( ( Hcap * Par_width ) / ( Vcap * Par_height ) ) by using "decrease size"
                            If original ratio ( Hcap / Vcap )  <  target ratio ( ( Hcap * Par_width ) / ( Vcap * Par_height ) )
                               Decrease V size to meet target ratio
                            else
                               Decrease H size to meet target ratio.
        */
        u16OriginalRatio = ( (U32) _u16TargetH * 1000 ) /  ( (U32) _u16TargetV );

        u16Temp = ( (U32) _u16TargetH * u32PAR_H * 1000 ) / ( (U32) _u16TargetV * u32PAR_V );

        // Compare the ratio.
        if ( u16OriginalRatio > u16Temp ) //
        {
            _u16TargetH = ( ( (U32)_u16TargetH * u32PAR_H * 1000 ) / ( u32PAR_V ) ) / 1000;
        }
        else
        {
            _u16TargetV = ( ( (U32)_u16TargetV * u32PAR_V * 1000 ) / ( u32PAR_H ) ) / 1000;
        }

    }

    *u16TargetH = _u16TargetH;
    *u16TargetV = _u16TargetV;

}

void _msAPI_APEngine_Obama_VDPlayer_CalCropDisplayWin(MS_WINDOW_TYPE *ptCropWin, MS_WINDOW_TYPE *ptDstWin, VDPLAYER_ZOOM_FACT eZoom)
{
    U8 u8numerator = 1;
    U8 u8denominator = 1;
    U16 u16HSize = 0;
    U16 u16HStart = 0;
    U16 u16VSize = 0;
    U16 u16VStart = 0;
    U16 u16modifiedH,u16modifiedV,u16Temp;

    U16 u16Width = 0;
    U16 u16Height = 0;

    switch (eZoom)
    {
    case VDPLAYER_ZOOM_FACT_1_DIV_4:
    case VDPLAYER_ZOOM_FACT_1_DIV_2:
    case VDPLAYER_ZOOM_FACT_NORMAL:
        u8numerator = 1;
        u8denominator = 1;
        break;
    case VDPLAYER_ZOOM_FACT_2X:
        u8numerator = 5;
        u8denominator = 7;
        break;
    case VDPLAYER_ZOOM_FACT_4X:
        u8numerator = 1;
        u8denominator = 2;
        break;
    case VDPLAYER_ZOOM_FACT_8X:
        u8numerator = 5;
        u8denominator = 14;
        break;
    default:
        break;
    }

    u16Width = (U16)_msAPI_APEngine_Obama_VDPlayer_GetInfo(E_VDPLAYER_INFO_H_SIZE);
    u16Height = (U16)_msAPI_APEngine_Obama_VDPlayer_GetInfo(E_VDPLAYER_INFO_V_SIZE);
    //printf("\n u16Width=%x ,  u16Height=%x ", u16Width, u16Height);

    // Get source ratio by PAR
    _msAPI_APEngine_Obama_VDPlayer_AdjustRatioByPAR(u16Width , u16Height,
                                   _msAPI_APEngine_Obama_VDPlayer_GetInfo(E_VDPLAYER_INFO_PAR_H_SIZE) ,
                                   _msAPI_APEngine_Obama_VDPlayer_GetInfo(E_VDPLAYER_INFO_PAR_V_SIZE),
                                   &u16modifiedH, &u16modifiedV);
    //printf("\n u16modifiedH=%x ,  u16modifiedV=%x ", u16modifiedH, u16modifiedV);

#if 0
    if ((u8numerator == 1) && (u8denominator == 1))
    {
        u16HSize = u16Width;
        u16VSize = u16Height;
        u16HStart = 0;
        u16VStart = 0;
    }
    else
    {
        u16HSize = ((u16Width*u8numerator)/u8denominator);
        u16HSize = (u16HSize>>1)<<1;
        u16VSize = ((u16Height*u8numerator)/u8denominator);
        u16VSize = ((u16VSize>>1)<<1);

        u16HStart = (((u16Width*(u8denominator - u8numerator))/u8denominator)>>2)<<1;
        u16VStart = (((u16Height*(u8denominator - u8numerator))/u8denominator)>>2)<<1;
    }

    tCropWin.x = u16HStart;
    tCropWin.y = u16VStart;
    tCropWin.width = u16HSize;
    tCropWin.height = u16VSize;
#else
    if ((u8numerator == 1) && (u8denominator == 1))
    {
        u16HSize = u16modifiedH;
        u16VSize = u16modifiedV;
        u16HStart = 0;
        u16VStart = 0;
    }
    else
    {
        u16HSize = ((u16modifiedH*u8numerator)/u8denominator);
        u16HSize = (u16HSize>>1)<<1;
        u16VSize = ((u16modifiedV*u8numerator)/u8denominator);
        u16VSize = ((u16VSize>>1)<<1);

        u16HStart = (((u16modifiedH*(u8denominator - u8numerator))/u8denominator)>>2)<<1;
        u16VStart = (((u16modifiedV*(u8denominator - u8numerator))/u8denominator)>>2)<<1;
    }

    //tCropWin.x = u16HStart;
    //tCropWin.y = u16VStart;
    //tCropWin.width = u16HSize;
    //tCropWin.height = u16VSize;

    // Mapping crop ratio into really source ratio.
    ptCropWin->width = ( (U32)u16Width * (U32)u16HSize ) / ( (U32) u16modifiedH );
    ptCropWin->height = ( (U32)u16Height * (U32)u16VSize ) / ( (U32) u16modifiedV );

    // Boundary check
    if ( u16Width >= ptCropWin->width )
        ptCropWin->x = ( u16Width - ptCropWin->width ) / 2 ;
    // Boundary check
    if ( u16Height >= ptCropWin->height )
        ptCropWin->y = ( u16Height - ptCropWin->height ) / 2;

    ptCropWin->x = (ptCropWin->x >> 1) << 1;
#endif

    // Stretch source to panel size and keep it ratio.
    ptDstWin->width = u16modifiedH;
    ptDstWin->height = u16modifiedV;

    ptDstWin->x = ptDstWin->y = 0;

    u16Temp = ( (U32)ptDstWin->width * 1000) / ptDstWin->height ;

    if ( u16Temp  >=  ( ( (U32)g_IPanel.Width() * 1000 )/ g_IPanel.Height())  )
    {
        // Keep width information
        ptDstWin->height = ( (U32)ptDstWin->height * g_IPanel.Width() ) / ptDstWin->width;
        // Boundary check
        if ( ptDstWin->height < g_IPanel.Height() )
            ptDstWin->y += ( g_IPanel.Height()   -  ptDstWin->height ) / 2 ;
        ptDstWin->width = g_IPanel.Width();
    }
    else
    {
        ptDstWin->width = ( (U32)ptDstWin->width * g_IPanel.Height() ) / ptDstWin->height;
        // Boundary check
        if ( g_IPanel.Width() > ptDstWin->width )
            ptDstWin->x += ( g_IPanel.Width()   -   ptDstWin->width ) / 2 ;
        ptDstWin->height = g_IPanel.Height();
        // 2 Alignment
        ptDstWin->x = (ptDstWin->x >> 1) << 1;
    }

    switch (eZoom)
    {
    case VDPLAYER_ZOOM_FACT_1_DIV_4:
        u16HSize = ((ptDstWin->width * 1 / 2) >> 1) << 1;
        u16VSize = ((ptDstWin->height * 1 / 2) >> 1) << 1;
        u16HStart = (g_IPanel.Width() - u16HSize) >> 1;
        u16VStart = (g_IPanel.Height() - u16VSize) >> 1;
        //msAPI_Scaler_SetCustomerDisplayWindow(TRUE, u16HStart, u16VStart, u16HSize, u16VSize);
        ptDstWin->x = u16HStart;
        ptDstWin->y = u16VStart;
        ptDstWin->width = u16HSize;
        ptDstWin->height = u16VSize;
        break;

    case VDPLAYER_ZOOM_FACT_1_DIV_2:
        u16HSize = ((ptDstWin->width * 5 / 7) >> 1) << 1;
        u16VSize = ((ptDstWin->height * 5 / 7) >> 1) << 1;
        u16HStart = (g_IPanel.Width() - u16HSize) >> 1;
        u16VStart = (g_IPanel.Height() - u16VSize) >> 1;
        //msAPI_Scaler_SetCustomerDisplayWindow(TRUE, u16HStart, u16VStart, u16HSize, u16VSize);
        ptDstWin->x = u16HStart;
        ptDstWin->y = u16VStart;
        ptDstWin->width = u16HSize;
        ptDstWin->height = u16VSize;
        break;

    default:
        break;
    }
}


void _msAPI_APEngine_Obama_VDPlayer_ScaleVideo(VDPLAYER_ZOOM_FACT eZoom)
{
    BOOLEAN b_Freezeflag = FALSE;
    BOOLEAN bMVopEnabled;

    MS_WINDOW_TYPE tCropWin, tDstWin;

    if ((enVDPlayerRet != EXIT_VDPLAYER_DECODING)
            || (MDrv_MVOP_GetIsEnable(&bMVopEnabled) != E_MVOP_OK)
            || (bMVopEnabled != TRUE))
    {
        return;
    }

    if(MApi_XC_IsFreezeImg(MAIN_WINDOW))
    {
        b_Freezeflag = TRUE;
        MApi_XC_FreezeImg(DISABLE, MAIN_WINDOW);
    }

    msAPI_Scaler_SetBlueScreen(ENABLE, E_XC_FREE_RUN_COLOR_BLACK, DEFAULT_SCREEN_UNMUTE_TIME, MAIN_WINDOW);

    memset(&tCropWin, 0, sizeof(tCropWin));
    memset(&tDstWin, 0, sizeof(tDstWin));
    _msAPI_APEngine_Obama_VDPlayer_CalCropDisplayWin(&tCropWin, &tDstWin, eZoom);

    MApp_Scaler_SetWindow(NULL,  &tCropWin, &tDstWin, stSystemInfo[MAIN_WINDOW].enAspectRatio,
                                               SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), MAIN_WINDOW); //?? aspect ration??

    //MDrv_Scaler_SetOPClkGating(bOPClkGating); // Restore original OP clock gating.

    MApp_Picture_Setting_SetColor(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), MAIN_WINDOW);
    msAPI_Scaler_SetBlueScreen(DISABLE, E_XC_FREE_RUN_COLOR_BLACK, DEFAULT_SCREEN_UNMUTE_TIME, MAIN_WINDOW);
    msAPI_Timer_Delayms(100);

    if(b_Freezeflag)
    {
        b_Freezeflag = FALSE;
        MApi_XC_FreezeImg(ENABLE, MAIN_WINDOW);
    }
}


void _msAPI_APEngine_Obama_VDPlayer_ClearShareMem(void)
{
    U32 addr, addr1;

    for(addr=0;addr<E_SHAREMEM_NUM;addr++)
    {
        addr1 = u32VdplayerShareMemAddr+(addr << 2);
        *(U32 *)_PA2VA(addr1) = 0;
    }

    //MsOS_Sync();
    MsOS_FlushMemory();
}

void _msAPI_APEngine_Obama_VDPlayer_SetupDisplayPath(U8 u8VideoType,
        U16 u16Width, U16 u16Height,  //--> VDPlayerInfo.u16Width, VDPlayerInfo.u16Height
        U16 u16DisplayX, U16 u16DisplayY, // --> u16VDPlayerDisplayInfoX, u16VDPlayerDisplayInfoY
        U16 u16DisplayWidth, U16 u16DisplayHeight, U32 u32BuffAddr, // --> u16VDPlayerDisplayInfoWidth, u16VDPlayerDisplayInfoHeight
        U8 u8TSStream, BOOLEAN bFullScreen)
{
#if VDPLAYER_MVOP_REAL_FRAMERATE
    MVOP_VidStat stMvopVidSt;
    memset(&stMvopVidSt, 0, sizeof(MVOP_VidStat));
    gstVidStatus.u16FrameRate = _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_FRAME_RATE);
    gstVidStatus.u8Interlace = _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_INTERLACE);
    gstVidStatus.u16HorSize =  _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_WIDTH);
    gstVidStatus.u16VerSize = _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_HEIGHT);

    // printf("%dx%d %d%s\n", gstVidStatus.u16HorSize, gstVidStatus.u16VerSize, gstVidStatus.u16FrameRate,
    //     (gstVidStatus.u8Interlace)? "i":"p");

    u16Width =  gstVidStatus.u16HorSize;
    u16Height = gstVidStatus.u16VerSize;

//    msAPI_VID_VOPInit();
    MDrv_MVOP_Init();

//    msAPI_VID_SetVOPClk(TRUE);

#if 1//(ENABLE_MIU_1 == 0)
    if (u8TSStream)
    {
        /// Disable it for program change
        MApi_XC_EnableFrameBufferLess(DISABLE);
    }
#endif  //(ENABLE_MIU_1 == 0)

    enVDPlayerVideoType = (VDPLAYER_VIDEO_TYPE)u8VideoType;

    /*
    if ((u8VideoType == VIDEO_MPEG4)||(u8VideoType == VIDEO_MPG))
    {
        MDrv_VOP_Input_Mode( VOPINPUT_HARDWIRE, NULL );
    }
    else
    */
    if (u8VideoType == VIDEO_RM)
    {
        if (((U32)u16Width*(U32)u16Height >= 1440UL*1080UL) || (gstVidStatus.u8Interlace == TRUE))
            gstVidStatus.u16FrameRate = 30000;
        else
            gstVidStatus.u16FrameRate = 60000;
    }
    else
    if (u8VideoType == VIDEO_MJPEG)
    {
        MVOP_InputCfg dc_param;
        //MS_SYS_INFO enMsSysInfo;

        // Enable Blue Screen
        msAPI_Scaler_SetBlueScreen(ENABLE, E_XC_FREE_RUN_COLOR_BLACK, DEFAULT_SCREEN_UNMUTE_TIME, MAIN_WINDOW);

        MApi_XC_GenerateBlackVideo(ENABLE, MAIN_WINDOW);

//        msAPI_VID_VOPInit();
        MDrv_MVOP_Init();

    //Refine: When we enter MM, input source type already be set to INPUT_SOURCE_STORAGE and
    //          msAPI_Scaler_SetSourceType() was called. So, we don't need to set source type again.
#if 0
         // set Scaler input source
        SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW) = INPUT_SOURCE_STORAGE;
        g_enDataInputSourceType[MAIN_WINDOW] = DATA_INPUT_SOURCE_STORAGE;
        enMsSysInfo.enInputSourceType = INPUT_SOURCE_STORAGE;
        enMsSysInfo.enAspectRatio = VIDEOSCREEN_NORMAL;
        msAPI_Scaler_SetSourceType(enMsSysInfo.enInputSourceType);
#endif
        // set mvop parameters
        MDrv_MVOP_EnableBlackBG();
        //=========JPEG TETS==========
        dc_param.u16HSize = u16Width;
        dc_param.u16VSize = u16Height;
        dc_param.u32YOffset = u32BuffAddr;
        dc_param.u32UVOffset = dc_param.u32YOffset+ 8; //No Use, in MDrv_VOP_Input_Mode, it will be reset
        dc_param.bSD = 1;
        dc_param.bYUV422 = 1;
        dc_param.bProgressive = 1;
        dc_param.bUV7bit = 0;
        dc_param.bDramRdContd = 1;
        dc_param.bField = 0;
        dc_param.b422pack = 1;
        dc_param.u16StripSize = dc_param.u16HSize;
        MDrv_MVOP_SetInputCfg(MVOP_INPUT_DRAM, &dc_param);

        gstVidStatus.u8AspectRate = ASP_4TO3;   //ASP_16TO9;
    }

#if (ENABLE_MIU_1 == 0)
    if ((enVDPlayerFlgs & E_VDPLAYER_FLG_PREVIEW) != E_VDPLAYER_FLG_PREVIEW)
    {
        if(_msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_MVD_FRAMEBUFFER_MODE) == (U32)ENABLE_FBL_MODE)
        {
            MApi_XC_EnableFrameBufferLess(ENABLE);
        }
    }

    if (MApi_XC_IsCurrentFrameBufferLessMode()) //Bright@20080905 FBL
    {
/*
        if((gstVidStatus.u16FrameRate > 24500)&&(gstVidStatus.u16FrameRate < 25500))//if(gstVidStatus.u16FrameRate > 25000)
            gstVidStatus.u16FrameRate = 25000;
        else
            gstVidStatus.u16FrameRate = 30000;
*/
        if((gstVidStatus.u16FrameRate > 24500)&&(gstVidStatus.u16FrameRate <= 25000))
        {
            //stVidStatus.u16FrameRate = 25000;
        }
        else if((gstVidStatus.u16FrameRate > 49500)&&(gstVidStatus.u16FrameRate <= 50000))
        {
            gstVidStatus.u16FrameRate=gstVidStatus.u16FrameRate/2; //25
        }
        else if((gstVidStatus.u16FrameRate > 23500)&&(gstVidStatus.u16FrameRate <= 24000) )
        {
            gstVidStatus.u16FrameRate = (U32)gstVidStatus.u16FrameRate*5/4; //30
        }
        else if((gstVidStatus.u16FrameRate > 29500)&&(gstVidStatus.u16FrameRate <= 30000))
        {
            //~30
        }
        else
        {
            gstVidStatus.u16FrameRate = 30000;
        }

        if (gstVidStatus.u8Interlace == FALSE)   // progressive
        {
            gstVidStatus.u16FrameRate *= 2;
        }
    }
#endif  // #if (ENABLE_MIU_1 == 0)

#else //VDPLAYER_MVOP_REAL_FRAMERATE

    U32 u32Width = 0, u32Height = 0;
    MVOP_VidStat stMvopVidSt;

    gstVidStatus.u16FrameRate = 60000;

    u16Width =  _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_WIDTH);
    u16Height = _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_HEIGHT);

    MDrv_MVOP_Init();
#if (ENABLE_MIU_1 == 0)
    if(u8TSStream)
    {
        /// Disable it for program change
        MApi_XC_EnableFrameBufferLess(DISABLE);
    }
#endif //(ENABLE_MIU_1 == 0)
    enVDPlayerVideoType = (VDPLAYER_VIDEO_TYPE)u8VideoType;

    if (u8VideoType == VIDEO_H264)
    {
        if(u8TSStream)
        {
            gstVidStatus.u16FrameRate = _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_FRAME_RATE);
        }
        gstVidStatus.u16HorSize =  u16Width;
        gstVidStatus.u16VerSize = u16Height;
        gstVidStatus.u8Interlace = _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_INTERLACE);
    }
    else
    if ((u8VideoType == VIDEO_MPEG4)||(u8VideoType == VIDEO_MPG))
    {
        if(u8TSStream)
        {
            gstVidStatus.u16FrameRate = _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_FRAME_RATE);
        }
        gstVidStatus.u16HorSize =  u16Width;
        gstVidStatus.u16VerSize = u16Height;
        gstVidStatus.u8Interlace = _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_INTERLACE);
        MDrv_MVOP_SetInputCfg(MVOP_INPUT_MVD, NULL);
    }
    else
    if (u8VideoType == VIDEO_RM)
    {
        gstVidStatus.u16HorSize =  u16Width;
        gstVidStatus.u16VerSize = u16Height;
        gstVidStatus.u8Interlace = _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_INTERLACE);
    }
    else
    if (u8VideoType == VIDEO_MJPEG)
    {
        MVOP_InputCfg dc_param;
        #if 0
        MS_SYS_INFO enMsSysInfo;
        #endif

        // Enable Blue Screen
        msAPI_Scaler_SetBlueScreen(ENABLE, E_XC_FREE_RUN_COLOR_BLACK, DEFAULT_SCREEN_UNMUTE_TIME, MAIN_WINDOW);

        MApi_XC_GenerateBlackVideo(ENABLE, MAIN_WINDOW);

//        msAPI_VID_VOPInit();
        MDrv_MVOP_Init();

    //Refine: When we enter MM, input source type already be set to INPUT_SOURCE_STORAGE and
    //          msAPI_Scaler_SetSourceType() was called. So, we don't need to set source type again.
#if 0
         // set Scaler input source
        SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW) = INPUT_SOURCE_STORAGE;
        enMsSysInfo.enDataInputSourceType = DATA_INPUT_SOURCE_STORAGE;
        enMsSysInfo.enInputSourceType = INPUT_SOURCE_STORAGE;
        enMsSysInfo.enAspectRatio = VIDEOSCREEN_NORMAL;
        msAPI_Scaler_SetSourceType(enMsSysInfo.enInputSourceType,OUTPUT_SCALER_MAIN_WINDOW);
#endif

        // set mvop parameters
        MDrv_MVOP_EnableBlackBG();
        //=========JPEG TETS==========
        dc_param.u16HSize = u16Width;
        dc_param.u16VSize = u16Height;
        dc_param.u32YOffset = u32BuffAddr;
        dc_param.u32UVOffset = dc_param.u32YOffset+ 8; //No Use, in MDrv_VOP_Input_Mode, it will be reset
        dc_param.bSD = 1;
        dc_param.bYUV422 = 1;
        dc_param.bProgressive = 1;
        dc_param.bUV7bit = 0;
        dc_param.bDramRdContd = 1;
        dc_param.bField = 0;
        dc_param.b422pack = 1;
        dc_param.u16StripSize = dc_param.u16HSize;
        MDrv_MVOP_SetInputCfg(MVOP_INPUT_DRAM, &dc_param);

        gstVidStatus.u16HorSize = dc_param.u16HSize;
        gstVidStatus.u16VerSize = dc_param.u16VSize;
        gstVidStatus.u8AspectRate = ASP_4TO3;   //ASP_16TO9;
        gstVidStatus.u8Interlace = 0;
    }

    u32Width = (U32)gstVidStatus.u16HorSize;
    u32Height = (U32)gstVidStatus.u16VerSize;

#if (ENABLE_MIU_1 == 0)
    if ((enVDPlayerFlgs & E_VDPLAYER_FLG_PREVIEW) != E_VDPLAYER_FLG_PREVIEW)
    {
        if(_msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_MVD_FRAMEBUFFER_MODE)
            == (U32)ENABLE_FBL_MODE)
        {
            MApi_XC_EnableFrameBufferLess(ENABLE);
            //printf("*** Enable FBL ***\n");
        }
    }

    if(!MApi_XC_IsCurrentFrameBufferLessMode()) //Bright@20080905 FBL
    {
        if(!u8TSStream)/// Use real sample rate for TS.
        {
            if ((u32Width*u32Height >= 1440UL*1080UL) || (gstVidStatus.u8Interlace == TRUE))
            {
                gstVidStatus.u16FrameRate = 30000;
            }
            else
            {
                gstVidStatus.u16FrameRate = 60000;
            }
        }
    }
    else
    {
        gstVidStatus.u16FrameRate = _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_FRAME_RATE);
        printf("fr= %d, i= %d\n", gstVidStatus.u16FrameRate, gstVidStatus.u8Interlace));
        if((gstVidStatus.u16FrameRate > 24500)&&(gstVidStatus.u16FrameRate < 25500)//if(gstVidStatus.u16FrameRate > 25000)
            gstVidStatus.u16FrameRate = 25000;
        else
            gstVidStatus.u16FrameRate = 30000;

        if (gstVidStatus.u8Interlace == FALSE)   // progressive
        {
            gstVidStatus.u16FrameRate *= 2;
        }
    }
#else   //DTV
    if(!u8TSStream)/// Use real sample rate for TS.
    {
        if ((u32Width*u32Height >= 1440UL*1080UL) || (gstVidStatus.u8Interlace == TRUE))
        {
            gstVidStatus.u16FrameRate = 30000;
        }
        else
        {
            gstVidStatus.u16FrameRate = 60000;
        }
    }
#endif //(ENABLE_MIU_1 == 0)

#if (VDPLAYER_VERIFY_SCALER_FPGA)
    // For scaler FPGA testing.
    if( gstVidStatus.u8Interlace )
        gstVidStatus.u16FrameRate = 10000;
    else
        gstVidStatus.u16FrameRate = 20000;
#endif//(VDPLAYER_VERIFY_SCALER_FPGA)

#endif //VDPLAYER_MVOP_REAL_FRAMERATE

    memset(&stMvopVidSt, 0, sizeof(stMvopVidSt));
    stMvopVidSt.u16HorSize   = gstVidStatus.u16HorSize;
    stMvopVidSt.u16VerSize   = gstVidStatus.u16VerSize;
    stMvopVidSt.u16FrameRate = gstVidStatus.u16FrameRate;
    stMvopVidSt.u8AspectRate = gstVidStatus.u8AspectRate;
    stMvopVidSt.u8Interlace  = gstVidStatus.u8Interlace;
    MDrv_MVOP_SetOutputCfg(&stMvopVidSt, FALSE);

    // Crop Info
    gstVidStatus.u16CropRight = _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_VIDEO_CROP_RIGHT);
    gstVidStatus.u16CropLeft = _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_VIDEO_CROP_LEFT);
    gstVidStatus.u16CropBottom = _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_VIDEO_CROP_BOTTOM);
    gstVidStatus.u16CropTop = _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_VIDEO_CROP_TOP);

    MDrv_MVOP_Enable(FALSE);

    switch (u8VideoType)
    {
        case VIDEO_MPEG4:
        case VIDEO_MPG:
        case VIDEO_VC1:
            MDrv_MVOP_SetInputCfg(MVOP_INPUT_MVD, NULL);
            break;

        case VIDEO_H264:
        case VIDEO_AVS:
            MDrv_MVOP_SetInputCfg(MVOP_INPUT_H264, NULL);
            break;

        case VIDEO_RM:
            MDrv_MVOP_SetInputCfg(MVOP_INPUT_RVD, NULL);
            break;

        case VIDEO_MJPEG:
#if (CHIP_FAMILY_TYPE == CHIP_FAMILY_U3)
            UNUSED(u16DisplayX);
            UNUSED(u16DisplayY);
            UNUSED(u16DisplayWidth);
            UNUSED(u16DisplayHeight);
            UNUSED(u32BuffAddr);

            MDrv_MVOP_SetInputCfg(MVOP_INPUT_JPD, NULL);
            break;

#else // #if (CHIP_FAMILY_TYPE == CHIP_FAMILY_U3)
            {
                U16 displayX, displayY, displayHSize, displayVSize;
                MS_WINDOW_TYPE tDstWin;
                S32 s32QuotientDiff, s32RemainderDiff;

                // set scaling aspect to program
                // [071017 Andy] set to original aspect
                stSystemInfo[MAIN_WINDOW].enAspectRatio = VIDEOSCREEN_ORIGIN;

                if(enVDPlayerFlgs & E_VDPLAYER_FLG_PREVIEW)
                {
                    u16DisplayX = MOVIE_PREVIEW_X;
                    u16DisplayY = MOVIE_PREVIEW_Y;
                    u16DisplayWidth = MOVIE_PREVIEW_WIDTH;
                    u16DisplayHeight = MOVIE_PREVIEW_HEIGHT;
                }

                // Set to the original aspect ratio
                s32QuotientDiff = ((((U32)u16DisplayWidth * 32) / (U32)u16DisplayHeight) - (((U32)u16Width * 32) / (U32)u16Height));
                s32RemainderDiff = ((((U32)u16DisplayWidth * 32) % (U32)u16DisplayHeight) - (((U32)u16Width * 32) % (U32)u16Height));
                // Set to the original aspect ratio
                if ((s32QuotientDiff > 0)
                        || ((s32QuotientDiff == 0) && (s32RemainderDiff > 0)))
                {
                    // Height major
                    displayHSize = (U16)(((U32)u16DisplayHeight * 32 / (U32)u16Height) *
                                          (U32)u16Width / 32) & 0xFFFE;
                    displayX = u16DisplayX + (u16DisplayWidth - displayHSize) / 2;
                    displayY = u16DisplayY;
                    displayVSize = u16DisplayHeight;
                }
                else
                {
                    // Width major
                    displayVSize = (U16)(((U32)u16DisplayWidth * 32 / (U32)u16Width) *
                                          (U32)u16Height / 32) & 0xFFFE;
                    displayY = u16DisplayY + (u16DisplayHeight - displayVSize) / 2;
                    displayX = u16DisplayX;
                    displayHSize = u16DisplayWidth;
                }

                {
                    tDstWin.x = displayX;
                    tDstWin.y = displayY;
                    tDstWin.width = displayHSize;
                    tDstWin.height = displayVSize;

                    MApp_Scaler_EnableOverScan(FALSE);
                    MApp_Scaler_SetWindow(NULL, NULL, &tDstWin, stSystemInfo[MAIN_WINDOW].enAspectRatio,
                                                           SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), MAIN_WINDOW);
                }

                //switch MIU to 0
                MDrv_MVOP_MiuSwitch(0);

                MDrv_MVOP_Enable(TRUE);
            }

            return;
#endif // #if (CHIP_FAMILY_TYPE == CHIP_FAMILY_U3)

        default:
            break;
    }

    MDrv_MVOP_Enable(TRUE);

    if (enVDPlayerFlgs & E_VDPLAYER_FLG_PREVIEW)
    {
        MS_WINDOW_TYPE tDstWin = {MOVIE_PREVIEW_X, MOVIE_PREVIEW_Y, MOVIE_PREVIEW_WIDTH, MOVIE_PREVIEW_HEIGHT};

#if (MEMORY_MAP <= MMAP_64MB)   //ATV_MM 64M
        //assign smaller buffer for scaler.
        MApi_XC_SetFrameBufferAddress(SCALER_DNR_BUF_PREV_ADR, SCALER_DNR_BUF_PREV_LEN);
#endif
        MApp_Scaler_EnableOverScan(FALSE);
        MApp_Scaler_SetWindow(NULL, NULL, &tDstWin, VIDEOSCREEN_FULL, SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), MAIN_WINDOW);
    }
    else
    {
        MApp_Scaler_EnableOverScan(FALSE);
        if (MApi_XC_IsCurrentFrameBufferLessMode())
        {
            if(bFullScreen)
            {
                MApp_Scaler_SetWindow(NULL, NULL, NULL,
                   stSystemInfo[MAIN_WINDOW].enAspectRatio, SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), MAIN_WINDOW);
            }
            else
            {
                MS_WINDOW_TYPE tDstWin = {u16DisplayX, u16DisplayY, u16DisplayWidth, u16DisplayHeight};
                MApp_Scaler_SetWindow(NULL, NULL, &tDstWin, stSystemInfo[MAIN_WINDOW].enAspectRatio, SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), MAIN_WINDOW);
            }
        }
        else
        {
            if(bFullScreen)
            {
                _msAPI_APEngine_Obama_VDPlayer_ScaleVideo(VDPLAYER_ZOOM_FACT_NORMAL);            //MApp_Scaler_SetTimingAndWindow( stSystemInfo.enAspectRatio);
            }
            else
            {
                MS_WINDOW_TYPE tDstWin = {u16DisplayX, u16DisplayY, u16DisplayWidth, u16DisplayHeight};
                MApp_Scaler_SetWindow(NULL, NULL, &tDstWin, stSystemInfo[MAIN_WINDOW].enAspectRatio, SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), MAIN_WINDOW);
            }
        }
    }

}


static void _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(U16 idx_ptr, U32 idx_data, U32 u32VdShareMemAddr)
{
    U32 addr = (u32VdShareMemAddr) + (idx_ptr << 2);
    if(u32VdShareMemAddr!=0)
    {
        //*(U32 *)addr = U32_SWAP(idx_data);
        *(U32 *)_PA2VA(addr) = idx_data;

        //MsOS_Sync();
        MsOS_FlushMemory();
    }
    else
    {
        printf("error! u32VdplayerShareMemAddr=NULL\n");
    }
}

static void _msAPI_APEngine_Obama_VDPlayer_ScreenDisplaySetting( U8 type , U8 value, U16 delay)
{
    switch(type)
    {
    case E_SCREEN_SETTINGS_SCALER_BLUESCREEN:
        if( value == FALSE ){
            MApp_Picture_Setting_SetColor(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), MAIN_WINDOW);
            msAPI_Scaler_SetBlueScreen( DISABLE,E_XC_FREE_RUN_COLOR_BLACK,  delay, MAIN_WINDOW);
        }
        else if( value == TRUE ){
            msAPI_Scaler_SetBlueScreen( ENABLE,E_XC_FREE_RUN_COLOR_BLACK, DEFAULT_SCREEN_UNMUTE_TIME, MAIN_WINDOW);
        }
        break;
    case E_SCREEN_SETTINGS_SCALER_FREEZESCREEN:
        if( value == FALSE )
        MApi_XC_FreezeImg(FALSE, MAIN_WINDOW);
        else if( value == TRUE )
        MApi_XC_FreezeImg(TRUE, MAIN_WINDOW);
        break;
    case E_SCREEN_SETTINGS_SCALER_ACE_PATCHTRICKMODE:
        if( value == FALSE )
        MApi_XC_Sys_PQ_PatchFastPlayback(MAIN_WINDOW, FALSE, FALSE);
        else if( value == TRUE )
        MApi_XC_Sys_PQ_PatchFastPlayback(MAIN_WINDOW, TRUE, FALSE);
        break;
    case E_SCREEN_SETTINGS_SCALER_ACE_FILMMODE:
//[TODO] enable it later
//        if( value == FALSE )
//        msAPI_ACE_RestoreFilmMode();
//        else if( value == TRUE )
//        msAPI_ACE_DisableFilmMode();
        break;
    case E_SCREEN_SETTINGS_NONE:
    default:
        break;
    }

}

/*
//-------------------------------------------------------------------------------------------------
///
/// APP functions
/// Processed by Aeon. And need to wait Ack message
///
//-------------------------------------------------------------------------------------------------
BOOLEAN _msAPI_APEngine_Obama_VDPlayer_SetPlayPosition(U32 timeInMs)
{
    if( g_VideoPlayerPlayingType>=VIDEO_PLAYER_PLAYING_TYPE_NUM )
    {
        return FALSE;
    }

    if (msAPI_MailBox_WaitReady())
    {
        MailBoxPara.u8CmdClass      = E_MBX_CLASS_VDPLAYER_FS;
        MailBoxPara.u8CmdIdx        = MB_VDPLAYER_SET_PLAYER_POSITION;
        MailBoxPara.ParamCnt        = 4;
        MailBoxPara.CMDType         = MB_CMD_TYPE_DEFAULT;
        MailBoxPara.u8Param[0] = (U8)((timeInMs&0xFF000000)>>24);
        MailBoxPara.u8Param[1] = (U8)((timeInMs&0x00FF0000)>>16);
        MailBoxPara.u8Param[2] = (U8)((timeInMs&0x0000FF00)>>8);
        MailBoxPara.u8Param[3] = (U8)((timeInMs&0x000000FF));
        msAPI_MailBox_SendMsg();
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}
*/

BOOLEAN _msAPI_APEngine_Obama_VDPlayer_SetTrickMode(EN_PLAY_MODE enPlayMode, EN_PLAY_SPEED enPlaySpeed)
{
    // send response to aeon
    //==> Send mail.
    APENGINE_MAILBOX_SEND(E_MBX_CLASS_VDPLAYER_FS
    /*Index*/           ,MB_VDPLAYER_SET_TRICK_MODE
    /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
    /*ParameterCount*/  ,2
    /*p1*/              ,(U8)(enPlayMode)
    /*p2*/              ,(U8)(enPlaySpeed)
    /*p3*/              ,0
    /*p4*/              ,0
    /*p5*/              ,0
    /*p6*/              ,0
    /*p7*/              ,0
    /*p8*/              ,0
    /*p9*/              ,0
    /*p10*/             ,0);

    return TRUE;
}

BOOLEAN _msAPI_APEngine_Obama_VDPlayer_SendMSG(unsigned char * pu8InData, unsigned short u16InDataSize, unsigned char * pu8OutData, unsigned short u16OutDataSize)
{
    pid_t cur_activated_ap;

    cur_activated_ap = MAdp_APMNG_GetActivatedAppPid();
    if(cur_activated_ap != 0)
    {
        //printf("Send Zodiac Message to pid: %d\n", cur_activated_ap);
        //printf("channel idx=%d\n",MAdp_MSGCH_GetChannelIndex("ZODIAC_VDPLAYER"));
        if (MAdp_MSGCH_Communicate(cur_activated_ap, MAdp_MSGCH_GetChannelIndex("ZODIAC_VDPLAYER"), pu8InData, u16InDataSize, pu8OutData, u16OutDataSize))
        {
            return TRUE;
        }
    }

    return FALSE;
}

void _msAPI_APEngine_Obama_VDPlayer_MailBoxHandler(void)
{
    U8 u8Count;
    U8 u8Index;
    //U8 u8MailBox[12];
    U32 tmpvar = 0;
    U8 u8FileHdl = 0;

    //static U32 spuqueueaddr;
    //static U16 spuqueuesize;
    MBX_MSGQ_Status Mstatus;
    MBX_Msg MB_Message;

    //u8Count = msAPI_MailBox_GetMsgCount(Q_VDPLAYER);
    MSApi_MBX_GetMsgQueueStatus(E_MBX_CLASS_VDPLAYER, &Mstatus);
    u8Count=(U8)Mstatus.u32NormalMsgCount;

    for(u8Index=0;u8Index<u8Count;u8Index++)
    {
        if(MSApi_MBX_RecvMsg(E_MBX_CLASS_VDPLAYER, &MB_Message, 0,MBX_CHECK_NORMAL_MSG)==E_MBX_SUCCESS)
        //if (msAPI_MailBox_GetMsg(Q_VDPLAYER, &u8MailBox[0]) == MB_GET_MSG_OK)
        {
            //MailBox MB;
            //MailBox* pMB = NULL;

// Fix compiling warning.
#if 0
            pMB = (MailBox*)&u8MailBox[0];
#else
            //memcpy(&MB, &u8MailBox[0], 12);
            //pMB = (MailBox *)&MB;
#endif
            if (MB_Message.u8MsgClass == E_MBX_CLASS_VDPLAYER)
            {
                U8 i;

                U8 pu8InData[10] = {0};
                U8 pu8OutData[10] = {0};

                MAdp_MSGCH_Init();

                printf("MB_Message.u8Index=%d\n",MB_Message.u8Index);
                switch(MB_Message.u8Index)
                {
                    // MB_VDPLAYER_RET_STATE_WAIT ----------------------------------------------
                    case MB_VDPLAYER_STATE_RET_WAIT:
                        enVDPlayerRet = EXIT_VDPLAYER_WAIT;
                        pu8InData[0] = E_OBAMA_ZODIAC_MSG_FILE_END;
                        if (!_msAPI_APEngine_Obama_VDPlayer_SendMSG((U8*)pu8InData, sizeof(pu8InData), (U8*)pu8OutData, sizeof(pu8OutData)))
                        {
                            printf("[D-Bus] Send Error\n");
                        }
                        break;

                    // MB_VDPLAYER_RET_STATE_EXIT ----------------------------------------------
                    case MB_VDPLAYER_STATE_RET_EXIT:
                        enVDPlayerRet = EXIT_VDPLAYER_EXIT;
                        pu8InData[0] = E_OBAMA_ZODIAC_MSG_FILE_END;
                        if (!_msAPI_APEngine_Obama_VDPlayer_SendMSG((U8*)pu8InData, sizeof(pu8InData), (U8*)pu8OutData, sizeof(pu8OutData)))
                        {
                            printf("[D-Bus] Send Error\n");
                        }
                        break;

                    // MB_VDPLAYER_FILE_OPEN ----------------------------------------------
                    case MB_VDPLAYER_FILE_OPEN:
                        pu8InData[0] = E_OBAMA_ZODIAC_MSG_FILE_INIT;
                        if (!_msAPI_APEngine_Obama_VDPlayer_SendMSG((U8*)pu8InData, sizeof(pu8InData), (U8*)pu8OutData, sizeof(pu8OutData)))
                        {
                            printf("[D-Bus] Send Error\n");
                        }
                        //==> Send mail.
                        APENGINE_MAILBOX_SEND(E_MBX_CLASS_VDPLAYER
                        /*Index*/           ,MB_VDPLAYER_ACK_51ToAEON
                        /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
                        /*ParameterCount*/  ,10
                        /*p1*/              ,MB_VDPLAYER_FILE_OPEN
                        /*p2*/              ,pu8OutData[0]
                        /*p3*/              ,pu8OutData[1]
                        /*p4*/              ,pu8OutData[2]
                        /*p5*/              ,pu8OutData[3]
                        /*p6*/              ,pu8OutData[4]
                        /*p7*/              ,pu8OutData[5]
                        /*p8*/              ,pu8OutData[6]
                        /*p9*/              ,pu8OutData[7]
                        /*p10*/             ,pu8OutData[8]);
                        break;

                    // MB_VDPLAYER_FILE_READ ----------------------------------------------
                    case MB_VDPLAYER_FILE_READ:
                        pu8InData[0] = E_OBAMA_ZODIAC_MSG_FILE_READ;
                        pu8InData[1] = MB_Message.u8Parameters[0];
                        pu8InData[2] = MB_Message.u8Parameters[1];
                        pu8InData[3] = MB_Message.u8Parameters[2];
                        pu8InData[4] = MB_Message.u8Parameters[3];
                        pu8InData[5] = MB_Message.u8Parameters[4];
                        pu8InData[6] = MB_Message.u8Parameters[5];
                        pu8InData[7] = MB_Message.u8Parameters[6];
                        pu8InData[8] = MB_Message.u8Parameters[7];
                        pu8InData[9] = MB_Message.u8Parameters[8]; // file handle
                        if (!_msAPI_APEngine_Obama_VDPlayer_SendMSG((U8*)pu8InData, sizeof(pu8InData), (U8*)pu8OutData, sizeof(pu8OutData)))
                        {
                            printf("[D-Bus] Send Error\n");
                        }

                        /*
                        for(i=0; i<4; i++)
                        {
                            u32Addr = (u32Addr<<8) | MB_Message.u8Parameters[i];
                        }
                        u32Addr = (u32Addr & 0x7FFFFFFF);
                        // u32Addr = (u32Addr & 0x1FFFFFFF) | 0x80000000;

                        for(i=4; i<8; i++)
                        {
                            u32Size = (u32Size<<8) | MB_Message.u8Parameters[i];
                        }
                        u8FileHdl = MB_Message.u8Parameters[8];
                        printf("u32Addr=%d\n",u32Addr);

                        read_size = msAPI_FCtrl_FileRead(u8FileHdl, u32Addr, u32Size);
                        // __asm__ volatile ("l.msync;");
                        */
                        //==> Send mail.
                        APENGINE_MAILBOX_SEND(E_MBX_CLASS_VDPLAYER
                        /*Index*/           ,MB_VDPLAYER_ACK_51ToAEON
                        /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
                        /*ParameterCount*/  ,6
                        /*p1*/              ,MB_VDPLAYER_FILE_READ
                        /*p2*/              ,(U8)pu8OutData[0]
                        /*p3*/              ,(U8)pu8OutData[1]
                        /*p4*/              ,(U8)pu8OutData[2]
                        /*p5*/              ,(U8)pu8OutData[3]
                        /*p6*/              ,(U8)pu8OutData[4]
                        /*p7*/              ,0
                        /*p8*/              ,0
                        /*p9*/              ,0
                        /*p10*/             ,0);
                        break;

                    case MB_VDPLAYER_FILE_READ_NONBLOCKING:
                        /*
                        for(i=0; i<4; i++)
                        {
                            u32Addr = (u32Addr<<8) | MB_Message.u8Parameters[i];
                        }
                        u32Addr = (u32Addr & 0x7FFFFFFF);
                        // u32Addr = (u32Addr & 0x1FFFFFFF) | 0x80000000;

                        for(i=4; i<8; i++)
                        {
                            u32Size = (u32Size<<8) | MB_Message.u8Parameters[i];
                        }

                        u8FileHdl = MB_Message.u8Parameters[8];
                        read_size = msAPI_FCtrl_FileRead(u8FileHdl, u32Addr, u32Size);
                        // __asm__ volatile ("l.msync;");
                        */

                        //DBG_INFO("Send Zodiac Message to pid: %d\n", cur_activated_ap);'
                        pu8InData[0] = E_OBAMA_ZODIAC_MSG_FILE_READ;
                        pu8InData[1] = MB_Message.u8Parameters[0];
                        pu8InData[2] = MB_Message.u8Parameters[1];
                        pu8InData[3] = MB_Message.u8Parameters[2];
                        pu8InData[4] = MB_Message.u8Parameters[3];
                        pu8InData[5] = MB_Message.u8Parameters[4];
                        pu8InData[6] = MB_Message.u8Parameters[5];
                        pu8InData[7] = MB_Message.u8Parameters[6];
                        pu8InData[8] = MB_Message.u8Parameters[7];
                        pu8InData[9] = MB_Message.u8Parameters[8]; // file handle
                        if (!_msAPI_APEngine_Obama_VDPlayer_SendMSG((U8*)pu8InData, sizeof(pu8InData), (U8*)pu8OutData, sizeof(pu8OutData)))
                        {
                            printf("[D-Bus] Send Error\n");
                        }

                        //==> Send mail.
                        APENGINE_MAILBOX_SEND(E_MBX_CLASS_VDPLAYER_FS
                        /*Index*/           ,MB_VDPLAYER_FILE_READ_NONBLOCKING_DONE
                        /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
                        /*ParameterCount*/  ,5
                        /*p1*/              ,pu8OutData[0]
                        /*p2*/              ,pu8OutData[1]
                        /*p3*/              ,pu8OutData[2]
                        /*p4*/              ,pu8OutData[3]
                        /*p5*/              ,pu8OutData[4]
                        /*p6*/              ,0
                        /*p7*/              ,0
                        /*p8*/              ,0
                        /*p9*/              ,0
                        /*p10*/             ,0);
                        break;

                    // MB_VDPLAYER_FILE_SEEK ----------------------------------------------
                    case MB_VDPLAYER_FILE_SEEK:
                        /*
                        for(i=4; i<8; i++)
                        {
                            u32Offset = (u32Offset<<8) | MB_Message.u8Parameters[i];
                        }
                        u8FileHdl = MB_Message.u8Parameters[8];
                        msAPI_FCtrl_FileSeek(u8FileHdl, u32Offset, FILE_SEEK_SET);
                        */

                        //DBG_INFO("Send Zodiac Message to pid: %d\n", cur_activated_ap);'
                        pu8InData[0] = E_OBAMA_ZODIAC_MSG_FILE_SEEK;
                        pu8InData[1] = MB_Message.u8Parameters[0];
                        pu8InData[2] = MB_Message.u8Parameters[1];
                        pu8InData[3] = MB_Message.u8Parameters[2];
                        pu8InData[4] = MB_Message.u8Parameters[3];
                        pu8InData[5] = MB_Message.u8Parameters[4];
                        pu8InData[6] = MB_Message.u8Parameters[5];
                        pu8InData[7] = MB_Message.u8Parameters[6];
                        pu8InData[8] = MB_Message.u8Parameters[7];
                        pu8InData[9] = MB_Message.u8Parameters[8]; // file handle
                        if (!_msAPI_APEngine_Obama_VDPlayer_SendMSG((U8*)pu8InData, sizeof(pu8InData), (U8*)pu8OutData, sizeof(pu8OutData)))
                        {
                            printf("[D-Bus] Send Error\n");
                        }

                        u8FileHdl = pu8OutData[0];

                        //==> Send mail.
                        APENGINE_MAILBOX_SEND(E_MBX_CLASS_VDPLAYER
                        /*Index*/           ,MB_VDPLAYER_ACK_51ToAEON
                        /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
                        /*ParameterCount*/  ,2
                        /*p1*/              ,MB_VDPLAYER_FILE_SEEK
                        /*p2*/              ,u8FileHdl
                        /*p3*/              ,0
                        /*p4*/              ,0
                        /*p5*/              ,0
                        /*p6*/              ,0
                        /*p7*/              ,0
                        /*p8*/              ,0
                        /*p9*/              ,0
                        /*p10*/             ,0);
                        break;

                    // MB_VDPLAYER_FILE_SEEK_NONBLOCKING ----------------------------------------------
                    case MB_VDPLAYER_FILE_SEEK_NONBLOCKING:
                        //DBG_INFO("Send Zodiac Message to pid: %d\n", cur_activated_ap);'
                        pu8InData[0] = E_OBAMA_ZODIAC_MSG_FILE_SEEK;
                        pu8InData[1] = MB_Message.u8Parameters[0];
                        pu8InData[2] = MB_Message.u8Parameters[1];
                        pu8InData[3] = MB_Message.u8Parameters[2];
                        pu8InData[4] = MB_Message.u8Parameters[3];
                        pu8InData[5] = MB_Message.u8Parameters[4];
                        pu8InData[6] = MB_Message.u8Parameters[5];
                        pu8InData[7] = MB_Message.u8Parameters[6];
                        pu8InData[8] = MB_Message.u8Parameters[7];
                        pu8InData[9] = MB_Message.u8Parameters[8]; // file handle

                        if (!_msAPI_APEngine_Obama_VDPlayer_SendMSG((U8*)pu8InData, sizeof(pu8InData), (U8*)pu8OutData, sizeof(pu8OutData)))
                        {
                            printf("[D-Bus] Send Error\n");
                        }
                        u8FileHdl = pu8OutData[0];
                        /*
                        for(i=4; i<8; i++)
                        {
                            u32Offset = (u32Offset<<8) | MB_Message.u8Parameters[i];
                        }
                        u8FileHdl = MB_Message.u8Parameters[8];
                        msAPI_FCtrl_FileSeek(u8FileHdl, u32Offset, FILE_SEEK_SET);
                        */
                        //==> Send mail.
                        APENGINE_MAILBOX_SEND(E_MBX_CLASS_VDPLAYER_FS
                        /*Index*/           ,MB_VDPLAYER_FILE_SEEK_NONBLOCKING_DONE
                        /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
                        /*ParameterCount*/  ,1
                        /*p1*/              ,u8FileHdl
                        /*p2*/              ,0
                        /*p3*/              ,0
                        /*p4*/              ,0
                        /*p5*/              ,0
                        /*p6*/              ,0
                        /*p7*/              ,0
                        /*p8*/              ,0
                        /*p9*/              ,0
                        /*p10*/             ,0);
                        break;

#if 0
#ifdef _VDPLAYER_DUMP_RAW_
                    // MB_VDPLAYER_FILE_DUMP_RAW ----------------------------------------------
                    case MB_VDPLAYER_FILE_DUMP_RAW:
                        {
                            U32 u32Buffer = VDPLAYER_DUMP_RAW_ADR;

                            U8 idx = MB_Message.u8Parameters[0];
                            for(i=1; i<5; i++)
                            {
                                u32Size = (u32Size<<8) | MB_Message.u8Parameters[i];
                            }
                            //printf ("src %lX, dst %lX, size %lX\n", VDEC_FRAMEBUFFER_ADR + u32Size*idx, u32Buffer, u32Size);
                            msAPI_MIU_Copy(VDEC_FRAMEBUFFER_ADR + u32Size*idx, u32Buffer, u32Size, MIU_SDRAM12SDRAM0);
                            msAPI_FCtrl_FileWrite(VDPlayer_dump_id, u32Buffer, u32Size);

                            if (msAPI_MailBox_WaitReady())
                            {
                                MailBoxPara.u8CmdClass      = MB_CLASS_VDPLAYER;
                                MailBoxPara.u8CmdIdx        = MB_VDPLAYER_ACK_51ToAEON;
                                MailBoxPara.ParamCnt        = 1;
                                MailBoxPara.CMDType         = MB_CMD_TYPE_DEFAULT;
                                MailBoxPara.u8Param[0]      = MB_VDPLAYER_FILE_DUMP_RAW;
                                msAPI_MailBox_SendMsg();
                            }
                        }
                        break;
#endif // _VDPLAYER_DUMP_RAW_

                    // MB_VDPLAYER_FILE_CLOSE ----------------------------------------------
                    case MB_VDPLAYER_FILE_CLOSE:
                        u8FileHdl = MB_Message.u8Parameters[0];
                        MApp_VDPlayer_ReleaseFileHandle(u8FileHdl);

                        if(VDPlayer_file_id!=INVALID_FILE_HANDLE)
                        {
                            msAPI_FCtrl_FileClose(VDPlayer_file_id);
                            VDPlayer_file_id = INVALID_FILE_HANDLE;
                        }

                        if(VDPlayer_Subtitle_file_id!=INVALID_FILE_HANDLE)
                        {
                            msAPI_FCtrl_FileClose(VDPlayer_Subtitle_file_id);
                            VDPlayer_Subtitle_file_id = INVALID_FILE_HANDLE;
                        }

#ifdef _VDPLAYER_DUMP_RAW_
                        if(VDPlayer_dump_id!=INVALID_FILE_HANDLE)
                        {
                            msAPI_FCtrl_FileClose(VDPlayer_dump_id);
                            VDPlayer_dump_id = INVALID_FILE_HANDLE;
                        }
#endif // _VDPLAYER_DUMP_RAW_
                        break;

#if 0
                    // MB_VDPLAYER_VIDEO_INIT ----------------------------------------------
                    case MB_VDPLAYER_VIDEO_INIT:
                        if(enVideoPlayerPlayingType==VIDEO_PLAYER_PLAYING_TYPE_MPEG4)
                        {
                            if(MB_Message.u8Parameters[0] == VIDEO_MPEG4)
                            {
                                if (msAPI_VID_MVDInit() == FALSE)
                                {
                                    MailBoxPara.u8Param[1] = FALSE;
                                }
                                else
                                {
                                    MailBoxPara.u8Param[1] = TRUE;
                                }
                            }

                            if(MB_Message.u8Parameters[0] == VIDEO_H264)
                            {
                                msAPI_VID_AVCH264Init();
                                msAPI_VID_AVCH264Reset();

                                MailBoxPara.u8Param[1] = TRUE;
                            }
                        }
                        else if(enVideoPlayerPlayingType==VIDEO_PLAYER_PLAYING_TYPE_MPEG2)
                        {
                            U8 u8Ret = msAPI_VID_MVDInit();

                            MailBoxPara.u8Param[1] = u8Ret;
                        }
                        else if(enVideoPlayerPlayingType==VIDEO_PLAYER_PLAYING_TYPE_RM)
                        {
                            // RVD load code at Co-processor
                        }

                        if (msAPI_MailBox_WaitReady())
                        {
                            MailBoxPara.u8CmdClass      = MB_CLASS_VDPLAYER;
                            MailBoxPara.u8CmdIdx        = MB_VDPLAYER_ACK_51ToAEON;
                            MailBoxPara.ParamCnt        = 2;
                            MailBoxPara.CMDType         = MB_CMD_TYPE_DEFAULT;
                            MailBoxPara.u8Param[0] = MB_VDPLAYER_VIDEO_INIT;

                            msAPI_MailBox_SendMsg();
                        }
                        break;
#endif
#endif
                    // MB_VDPLAYER_AUDIO_START ----------------------------------------------
                    case MB_VDPLAYER_AUDIO_START:
                        if( (MB_Message.u8Parameters[0] == 1))
                        {
                            /// Enable Audio parser to play TS-stream
                            MApi_AUDIO_SetCommand(MSAPI_AUD_DVB_DECCMD_PLAYFILETSP);
                        }
                        else
                        {
                            msAPI_Music_StartDecode();
                        }

                        //==> Send mail.
                        APENGINE_MAILBOX_SEND(E_MBX_CLASS_VDPLAYER
                        /*Index*/           ,MB_VDPLAYER_ACK_51ToAEON
                        /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
                        /*ParameterCount*/  ,1
                        /*p1*/              ,MB_VDPLAYER_AUDIO_INIT
                        /*p2*/              ,0
                        /*p3*/              ,0
                        /*p4*/              ,0
                        /*p5*/              ,0
                        /*p6*/              ,0
                        /*p7*/              ,0
                        /*p8*/              ,0
                        /*p9*/              ,0
                        /*p10*/             ,0);
                        break;

                    // MB_VDPLAYER_AUDIO_INIT ----------------------------------------------
                    case MB_VDPLAYER_AUDIO_INIT:
                        tmpvar = _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_AUDIO_CODEC_ID);
                        switch (tmpvar)
                        {
                            case E_VDP_CODEC_ID_DTS:
#if 1//AUDIO_SPDIF_ENABLE
                                //printf("AudioInit: E_VDP_CODEC_ID_DTS\n");
                               msAPI_Music_Init(MSAPI_AUD_DVB_DTS, INIT_VOLUME);
                               MApi_AUDIO_SPDIF_SetMode(MSAPI_AUD_SPDIF_NONPCM);
                               MApi_AUDIO_SetCommand(MSAPI_AUD_DVB_DECCMD_FREE_RUN);
#endif
                               break;

                            case E_VDP_CODEC_ID_MP3:
                                msAPI_Music_Init(MSAPI_AUD_DVB_MP3, INIT_VOLUME);
#if 1
                                if( _msAPI_APEngine_Obama_VDPlayer_GetInfo(E_VDPLAYER_INFO_Audio_Request_Size) == 0x02)
                                    MApi_AUDIO_SetMpegInfo(Audio_MPEG_infoType_MMFileSize, FILE_SIZE_2KB, 0);
                                else
                                    MApi_AUDIO_SetMpegInfo(Audio_MPEG_infoType_MMFileSize, FILE_SIZE_4KB, 0);
#endif
#if  AUDIO_SPDIF_ENABLE
                                MApi_AUDIO_SPDIF_SetMode(MSAPI_AUD_SPDIF_PCM);
#endif
                                MApi_AUDIO_SetCommand(MSAPI_AUD_DVB_DECCMD_FREE_RUN);
                                break;
                            case E_VDP_CODEC_ID_MP2:
                                msAPI_Music_Init(MSAPI_AUD_DVB_MPEG, INIT_VOLUME);
#if 1
                                 if( _msAPI_APEngine_Obama_VDPlayer_GetInfo(E_VDPLAYER_INFO_Audio_Request_Size) == 0x02)
                                    MApi_AUDIO_SetMpegInfo(Audio_MPEG_infoType_MMFileSize, FILE_SIZE_2KB, 0);
                                 else
                                    MApi_AUDIO_SetMpegInfo(Audio_MPEG_infoType_MMFileSize, FILE_SIZE_4KB, 0);
#endif
#if  AUDIO_SPDIF_ENABLE
                                MApi_AUDIO_SPDIF_SetMode(MSAPI_AUD_SPDIF_PCM);
#endif
                                MApi_AUDIO_SetCommand(MSAPI_AUD_DVB_DECCMD_FREE_RUN);
                                break;
                            case E_VDP_CODEC_ID_AC3:
                            case E_VDP_CODEC_ID_EAC3:

                                msAPI_Music_Init(MSAPI_AUD_DVB_AC3P, INIT_VOLUME);
#if 1
                                if(_msAPI_APEngine_Obama_VDPlayer_GetInfo(E_VDPLAYER_INFO_Audio_Request_Size))
                                {
                                    msAPI_Music_StopDecode();
                                    MApi_AUDIO_SetAC3PInfo(Audio_AC3P_infoType_MMFileSize, FILE_SIZE_16KB, 0);
                                }

#endif
#if  AUDIO_SPDIF_ENABLE
                                MApi_AUDIO_SPDIF_SetMode(MSAPI_AUD_SPDIF_NONPCM);
#endif
                                MApi_AUDIO_SetCommand(MSAPI_AUD_DVB_DECCMD_FREE_RUN);
                                break;
                            case E_VDP_CODEC_ID_AAC:
                            case E_VDP_CODEC_ID_MPEG4AAC:
                                msAPI_Music_Init(MSAPI_AUD_DVB_AAC, INIT_VOLUME);
                                tmpvar  = (((U32)MB_Message.u8Parameters[1]<<24)&0xFF000000) |
                                                (((U32)MB_Message.u8Parameters[2]<<16)&0x00FF0000) |
                                                (((U32)MB_Message.u8Parameters[3]<<8)&0x0000FF00) |
                                                (((U32)MB_Message.u8Parameters[4])&0x000000FF);
                                MDrv_AUDIO_WriteDecMailBox(4,(U16)tmpvar + 1);
                                tmpvar  = (((U32)MB_Message.u8Parameters[5]<<24)&0xFF000000) |
                                                (((U32)MB_Message.u8Parameters[6]<<16)&0x00FF0000) |
                                                (((U32)MB_Message.u8Parameters[7]<<8)&0x0000FF00) |
                                                (((U32)MB_Message.u8Parameters[8])&0x000000FF);
                                MDrv_AUDIO_WriteDecMailBox(5, 0);
#if  AUDIO_SPDIF_ENABLE
                                MApi_AUDIO_SPDIF_SetMode(MSAPI_AUD_SPDIF_PCM);
#endif
                                MApi_AUDIO_SetCommand(MSAPI_AUD_DVB_DECCMD_FREE_RUN);
                                break;

                            case E_VDP_CODEC_ID_PCM_S16LE:
                            case E_VDP_CODEC_ID_PCM_S16BE:
                            case E_VDP_CODEC_ID_PCM_U16LE:
                            case E_VDP_CODEC_ID_PCM_U16BE:
                            case E_VDP_CODEC_ID_PCM_S8:
                            case E_VDP_CODEC_ID_PCM_U8:
                            case E_VDP_CODEC_ID_PCM_MULAW:
                            case E_VDP_CODEC_ID_PCM_ALAW:
                                {
                                    U16 u16SampleRate;
                                    U16 u16BitsPerSample;
                                    U8 u8CannelNumber;

                                    u16SampleRate  = (((U16)MB_Message.u8Parameters[1]<<8)&0xFF00) |
                                                                (((U16)MB_Message.u8Parameters[2])&0x00FF);

                                    u16BitsPerSample  = (((U16)MB_Message.u8Parameters[3]<<8)&0xFF00) |
                                                                    (((U16)MB_Message.u8Parameters[4])&0x00FF);

                                    u8CannelNumber  = ((U16)(MB_Message.u8Parameters[5])&0x00FF);

                                    if (tmpvar == E_VDP_CODEC_ID_PCM_U16BE)
                                    {
                                        tmpvar = 0xFF;
                                    }
                                    else
                                    {
                                        tmpvar = 0;
                                    }

                                    MApi_AUDIO_XPCM_Param(LPCM, u8CannelNumber - 1, u16SampleRate, u16BitsPerSample,0, tmpvar);
                                    msAPI_Music_Init(MSAPI_AUD_DVB_XPCM, INIT_VOLUME);
                                }
                                break;

                            case E_VDP_CODEC_ID_ADPCM_IMA_QT:
                            case E_VDP_CODEC_ID_ADPCM_IMA_WAV:
                            case E_VDP_CODEC_ID_ADPCM_IMA_DK3:
                            case E_VDP_CODEC_ID_ADPCM_IMA_DK4:
                            case E_VDP_CODEC_ID_ADPCM_IMA_WS:
                            case E_VDP_CODEC_ID_ADPCM_IMA_SMJPEG:
                            case E_VDP_CODEC_ID_ADPCM_MS:
                            case E_VDP_CODEC_ID_ADPCM_4XM:
                            case E_VDP_CODEC_ID_ADPCM_XA:
                            case E_VDP_CODEC_ID_ADPCM_ADX:
                            case E_VDP_CODEC_ID_ADPCM_EA:
                            case E_VDP_CODEC_ID_ADPCM_G726:
                                {
                                    U16 u16SampleRate;
                                    U16 u16BitsPerSample;
                                    U8 u8CannelNumber;
                                    U16 u16BlockSize;
                                    U16 u16SamplePerBlock;

                                    u16SampleRate  = (((U16)MB_Message.u8Parameters[1]<<8)&0xFF00) |
                                                                (((U16)MB_Message.u8Parameters[2])&0x00FF);

                                    u16BitsPerSample  = (((U16)MB_Message.u8Parameters[3]<<8)&0xFF00) |
                                                                    (((U16)MB_Message.u8Parameters[4])&0x00FF);

                                    u8CannelNumber  = ((MB_Message.u8Parameters[5])&0x00FF);

                                    u16BlockSize  = (((U16)MB_Message.u8Parameters[6]<<8)&0xFF00) |
                                                                (((U16)MB_Message.u8Parameters[7])&0x00FF);

                                    u16SamplePerBlock  = (((U16)MB_Message.u8Parameters[8]<<8)&0xFF00) |
                                                                (((U16)MB_Message.u8Parameters[9])&0x00FF);

                                    if (tmpvar == E_VDP_CODEC_ID_ADPCM_MS)
                                    {
                                        tmpvar = MS_ADPCM;//2;
                                    }
                                    else
                                    {
                                        tmpvar = IMA_ADPCM;//17;
                                    }
                                    MApi_AUDIO_XPCM_Param((XPCM_TYPE)tmpvar, u8CannelNumber - 1, u16SampleRate, u16BitsPerSample,u16BlockSize, u16SamplePerBlock);
                                    msAPI_Music_Init(MSAPI_AUD_DVB_XPCM, INIT_VOLUME);
                                }
                                break;

                            case E_VDP_CODEC_ID_RAAC:
                            case E_VDP_CODEC_ID_RACP:
                            {
                                U16 u16Index;

                                for(i=1; i<5; i++)
                                {
                                    tmpvar = (tmpvar<<8) | MB_Message.u8Parameters[i];
                                }
                                printf("SampleRate: %lu\n", tmpvar);
                                u16Index = M4AParser_GetSampleRateIndex(tmpvar) ;
                                printf("SampleRate Index: %u\n", u16Index);

                                for(i=5; i<9; i++)
                                {
                                    tmpvar = (tmpvar<<8) | MB_Message.u8Parameters[i];
                                }
                                printf("AAC Stream Type: 0x%lx\n", tmpvar);

                                //MDrv_AUDIO_WriteDecMailBox(4, u16Index); // Index = 5 : 44100

                                //MDrv_AUDIO_WriteDecMailBox(3, 0x0);

                                msAPI_Music_Init(MSAPI_AUD_DVB_AAC, INIT_VOLUME);  // Initail AAC
                                //jyliu.0710, msAPI_Mp3_Init() will clear audio mailbox
                                MDrv_AUDIO_WriteDecMailBox(4, u16Index); // Index = 5 : 44100
                                MDrv_AUDIO_WriteDecMailBox(3, 0x0);

                                MDrv_AUDIO_WriteDecMailBox(5,0);
                            }
                            break;

                            case E_VDP_CODEC_ID_COOK:
                            {
                                U16 u16SampleRate;

                                printf("Share Memory Address :%lu\n",u32VdplayerShareMemAddr);
                                u16CodecNum=_msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_RM_LBR_NUM_CODECID);
                                u16Samples_channel=_msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_RM_LBR_SAMPLE_CHANNEL);
                                u16SampleRate=_msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_RM_LBR_SAMPLE_RATE);
                                for(i=0;u16CodecNum>i;i++ )
                                {
                                    u16CannelsA[i]=_msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_RM_LBR_NUM_CHANNEL+i);
                                    u16RegionsA[i]=_msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_RM_LBR_NUM_REGIONS+i);
                                    u16cplStartA[i]=_msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_RM_LBR_NUM_CPLSTART+i);
                                    u16cplQbitsA[i]=_msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_RM_LBR_NUM_CPLQBITS+i);
                                    u16FrameSizeA[i]=_msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_RM_LBR_FRAMESIZE+i);
                                }

                                printf("u16CodecNum %u\n",u16CodecNum);
                                printf("u16Samples_channel %u\n",u16Samples_channel);
                                printf("u16SampleRate %u\n",u16SampleRate);
                                for(i=0;u16CodecNum>i;i++ )
                                {

                                    printf("u16CannelsA[%d] %u\n",i,u16CannelsA[i]);
                                    printf("u16RegionsA[%d] %u\n",i,u16RegionsA[i]);
                                    printf("u16cplStartA[%d] %u\n",i,u16cplStartA[i]);
                                    printf("u16cplQbitsA[%d] %u\n",i,u16cplQbitsA[i]);
                                    printf("u16FrameSizeA[%d] %u\n",i,u16FrameSizeA[i]);
                                }
                                msAPI_Music_Init(MSAPI_AUD_DVB_RA8LBR, INIT_VOLUME);
                                MApi_AUDIO_RA8_Param(u16CodecNum, u16Samples_channel, u16SampleRate, &u16CannelsA[0], &u16RegionsA[0], &u16cplStartA[0], &u16cplQbitsA[0], &u16FrameSizeA[0]);

                                MDrv_AUDIO_WriteDecMailBox(5, 0x00);
                            }
                            break;
                        }

                        if (enVideoPlayerPlayingType==VIDEO_PLAYER_PLAYING_TYPE_MPEG2)
                        {
                            //==> Send mail.
                            APENGINE_MAILBOX_SEND(E_MBX_CLASS_VDPLAYER
                            /*Index*/           ,MB_VDPLAYER_ACK_51ToAEON
                            /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
                            /*ParameterCount*/  ,1
                            /*p1*/              ,MB_VDPLAYER_AUDIO_INIT
                            /*p2*/              ,0
                            /*p3*/              ,0
                            /*p4*/              ,0
                            /*p5*/              ,0
                            /*p6*/              ,0
                            /*p7*/              ,0
                            /*p8*/              ,0
                            /*p9*/              ,0
                            /*p10*/             ,0);
                        }
                        break;

                        // MB_VDPLAYER_ACK_AEONTo51 ----------------------------------------------
                        case MB_VDPLAYER_ACK_AEONTo51:
                            printf("MB_Message.u8Parameters[0]=%d\n",MB_Message.u8Parameters[0]);
                            switch(MB_Message.u8Parameters[0])
                            {
                                case MB_VDPLAYER_INIT:
                                    u8VDPlayerInitResult = MB_Message.u8Parameters[1];
                                    //printf("u8VDPlayerInitResult=%u\n",(U8)MB_Message.u8Parameters[1]);
                                    Remove_enumVDPlayerAckFlags(enVDPlayerAckFlags, E_ACKFLG_WAIT_INIT);
#if ENABLE_WMDRMPD
                                    u32WMDRMPDShareMemAddr = 0; //_msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_WMDRMPD_SHAREMEM);
                                    printf("WMDRMPD share memory addr = %08x\n", u32WMDRMPDShareMemAddr);
#if 0
                                    // For test only.
                                    if (MApp_VDPlayer_WMDRMPD_IsProtected())
                                    {
                                        if (!MApp_VDPlayer_WMDRMPD_GetLicense())
                                        {
                                            printf("GetLicense fail\n");
                                        }
                                    }
#endif
#endif
                                    break;

                                case MB_VDPLAYER_STOP:
                                    enVDPlayerVideoType = (VDPLAYER_VIDEO_TYPE)MB_Message.u8Parameters[1];
                                    enVDPlayerAckFlags &=(enumVDPlayerAckFlags) ~E_ACKFLG_WAIT_STOP;
                                    break;

                                case MB_VDPLAYER_PLAY:
                                    enVDPlayerAckFlags &=(enumVDPlayerAckFlags) ~E_ACKFLG_WAIT_PLAY;
                                    break;

                                case MB_VDPLAYER_SET_SUBTITLE_TRACKID:
                                    Remove_enumVDPlayerAckFlags(enVDPlayerAckFlags, E_ACKFLG_WAIT_INIT);
                                    u8VDPlayerInitResult = MB_Message.u8Parameters[1];
                                    break;
#if 0//ENABLE_DRM
                                case MB_VDPLAYER_GET_DRM_REG_CODE:
                                    bDrmRegCode = MB_Message.u8Parameters[1];

                                    g_DRMRegCode[0] = MB_Message.u8Parameters[2];
                                    g_DRMRegCode[1] = MB_Message.u8Parameters[3];
                                    g_DRMRegCode[2] = MB_Message.u8Parameters[4];
                                    g_DRMRegCode[3] = MB_Message.u8Parameters[5];
                                    g_DRMRegCode[4] = MB_Message.u8Parameters[6];
                                    g_DRMRegCode[5] = MB_Message.u8Parameters[7];
                                    g_DRMRegCode[6] = MB_Message.u8Parameters[8];
                                    g_DRMRegCode[7] = MB_Message.u8Parameters[9];

                                    Remove_enumVDPlayerAckFlags(enVDPlayerAckFlags, E_ACKFLG_WAIT_GET_DRM_REG_CODE);

                                    break;

                                case MB_VDPLAYER_GET_DRM_REG_CODE_2:
                                    g_DRMRegCode[8] = MB_Message.u8Parameters[1];
                                    g_DRMRegCode[9] = MB_Message.u8Parameters[2];

                                    Remove_enumVDPlayerAckFlags(enVDPlayerAckFlags, E_ACKFLG_WAIT_GET_DRM_REG_CODE_2);

                                    break;

                                case MB_VDPLAYER_GET_DRM_DEACTIVATION_CODE:
                                    //bDrmRegCode =  MB_Message.u8Parameters[1];
                                    g_DRMDeactivationCode[0] = MB_Message.u8Parameters[2];
                                    g_DRMDeactivationCode[1] = MB_Message.u8Parameters[3];
                                    g_DRMDeactivationCode[2] = MB_Message.u8Parameters[4];
                                    g_DRMDeactivationCode[3] = MB_Message.u8Parameters[5];
                                    g_DRMDeactivationCode[4] = MB_Message.u8Parameters[6];
                                    g_DRMDeactivationCode[5] = MB_Message.u8Parameters[7];
                                    g_DRMDeactivationCode[6] = MB_Message.u8Parameters[8];
                                    g_DRMDeactivationCode[7] = MB_Message.u8Parameters[9];

                                    Remove_enumVDPlayerAckFlags(enVDPlayerAckFlags, E_ACKFLG_WAIT_GET_DRM_DEACTIVATION_CODE);

                                    break;

                                case MB_VDPLAYER_CHECK_DRM_AUTHORIZATION:
                                    bDrmAuthorization   = MB_Message.u8Parameters[1];
                                    bDrmFileFormat      = MB_Message.u8Parameters[2];
                                    bDrmActivationFile  = MB_Message.u8Parameters[3];

                                    Remove_enumVDPlayerAckFlags(enVDPlayerAckFlags, E_ACKFLG_WAIT_CHECK_DRM_AUTHORIZATION);

                                    break;

                                case MB_VDPLAYER_QUERY_DRM_RENTAL_STATUS:
                                    bDrmRentalStatus = MB_Message.u8Parameters[0];

                                    g_bDrmRental    = MB_Message.u8Parameters[1];
                                    g_u8DrmUseLimit = MB_Message.u8Parameters[2];
                                    g_u8DrmUseCount = MB_Message.u8Parameters[3];

                                    Remove_enumVDPlayerAckFlags(enVDPlayerAckFlags, E_ACKFLG_WAIT_QUERY_DRM_RENTAL_STATUS);

                                    break;
#endif
/* // for testing
                                case MB_VDPLAYER_GET_SUBTITLE_STATE:
                                    u32GetSubtitleStateBuf = (((U32)MB_Message.u8Parameters[1]<<16)&0xFF0000) | (((U32)MB_Message.u8Parameters[2]<<8)&0xFF00)| (((U32)MB_Message.u8Parameters[3])&0xFF);

                                    Remove_enumVDPlayerAckFlags(enVDPlayerAckFlags, E_ACKFLG_WAIT_GET_SUBTITLE_STATE);

                                    break;
*/
                                case MB_VDPLAYER_REPEAT_AB:
                                   Remove_enumVDPlayerAckFlags(enVDPlayerAckFlags, E_ACKFLG_WAIT_REPEAT_AB);
                                   break;
                            }
                        break;
                        // MB_VDPLAYER_SETUP_DISPLAY ----------------------------------------------
                        case MB_VDPLAYER_SETUP_DISPLAY:
                            {
                                U32 u32VdplayerBuffY0 = 0;
                                U8  u8TSStream = 0;

                                if(MB_Message.u8Parameters[0] == VIDEO_MJPEG)
                                {
                                    u32VdplayerBuffY0  = (((U32)MB_Message.u8Parameters[5]<<24)&0xFF000000) |
                                                                (((U32)MB_Message.u8Parameters[6]<<16)&0x00FF0000) |
                                                                (((U32)MB_Message.u8Parameters[7]<<8)&0x0000FF00) |
                                                                (((U32)MB_Message.u8Parameters[8])&0x000000FF);
                                }
                                else if(MB_Message.u8Parameters[0] == VIDEO_H264 || MB_Message.u8Parameters[0] == VIDEO_MPG)
                                {
                                    u8TSStream = MB_Message.u8Parameters[5];
                                }
                                if(u32InitDisplayHeight == 0 || u32InitDisplayWidth == 0)
                                {
                                    _msAPI_APEngine_Obama_VDPlayer_SetupDisplayPath(MB_Message.u8Parameters[0],
                                        ((U16)(MB_Message.u8Parameters[1]<<8)&0xFF00)|(MB_Message.u8Parameters[2]&0x00FF),
                                        ((U16)(MB_Message.u8Parameters[3]<<8)&0xFF00)|(MB_Message.u8Parameters[4]&0x00FF),
                                        0,0,
                                        PANEL_WIDTH,PANEL_HEIGHT, u32VdplayerBuffY0,u8TSStream, TRUE);
                                }
                                else
                                {
                                    _msAPI_APEngine_Obama_VDPlayer_SetupDisplayPath(MB_Message.u8Parameters[0],
                                        ((U16)(MB_Message.u8Parameters[1]<<8)&0xFF00)|(MB_Message.u8Parameters[2]&0x00FF),
                                        ((U16)(MB_Message.u8Parameters[3]<<8)&0xFF00)|(MB_Message.u8Parameters[4]&0x00FF),
                                        u32InitDisplayX,u32InitDisplayY,
                                        u32InitDisplayWidth,u32InitDisplayHeight, u32VdplayerBuffY0,u8TSStream, FALSE);
                                }
                            }
                            //==> Send mail.
                            APENGINE_MAILBOX_SEND(E_MBX_CLASS_VDPLAYER
                            /*Index*/           ,MB_VDPLAYER_ACK_51ToAEON
                            /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
                            /*ParameterCount*/  ,1
                            /*p1*/              ,MB_VDPLAYER_SETUP_DISPLAY
                            /*p2*/              ,0
                            /*p3*/              ,0
                            /*p4*/              ,0
                            /*p5*/              ,0
                            /*p6*/              ,0
                            /*p7*/              ,0
                            /*p8*/              ,0
                            /*p9*/              ,0
                            /*p10*/             ,0);
                            //MApp_UiMediaPlayer_Notify(E_MPLAYER_NOTIFY_SETUP_DISPLAY, NULL);
                            break;

                        // MB_VDPLAYER_SET_DISPLAY_INFO ----------------------------------------------
                        case MB_VDPLAYER_SET_DISPLAY_INFO:
                            if (gstVidStatus.u16FrameRate < 10000)
                            {
                                //float point exception?
                                //U16 delay = 2200 / (gstVidStatus.u16FrameRate / 1000);
                                //_msAPI_APEngine_Obama_VDPlayer_ScreenDisplaySetting( MB_Message.u8Parameters[0] , MB_Message.u8Parameters[1], delay );
                                _msAPI_APEngine_Obama_VDPlayer_ScreenDisplaySetting( MB_Message.u8Parameters[0] , MB_Message.u8Parameters[1], DEFAULT_SCREEN_UNMUTE_TIME );
                            }
                            else
                            {
                                _msAPI_APEngine_Obama_VDPlayer_ScreenDisplaySetting( MB_Message.u8Parameters[0] , MB_Message.u8Parameters[1],  DEFAULT_SCREEN_UNMUTE_TIME );
                            }
                            break;

                        // MB_VDPLAYER_CLOSE_DISPLAY ----------------------------------------------
                        case MB_VDPLAYER_CLOSE_DISPLAY:
                            {
                                msAPI_Scaler_SetBlueScreen( ENABLE, E_XC_FREE_RUN_COLOR_BLACK, DEFAULT_SCREEN_UNMUTE_TIME, MAIN_WINDOW);
                                MApi_XC_GenerateBlackVideo(ENABLE, MAIN_WINDOW);

                                MDrv_MVOP_Enable(FALSE);

                                if (MB_Message.u8Parameters[0] == VIDEO_MJPEG)
                                {
                                    #if (ENABLE_MIU_1 == ENABLE)
                                    MDrv_MVOP_MiuSwitch(1);
                                    #endif
                                }
                            }
                        break;
#if 0
                        // MB_VDPLAYER_MPEG_SUBTITLE_SETHEADERINFO ----------------------------------------------
                        case MB_VDPLAYER_MPEG_SUBTITLE_SETHEADERINFO:
                            {
                                U32 numb;
                                U32 addr;

                                //printf("Subtitle set header information: sbtype:%d; videotype:%d\n", (U16)MB_Message.u8Parameters[0] , (U16)MB_Message.u8Parameters[1]);
                                u32subtitletype = _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_SUBTITLE_CODEC_ID);
                                switch ( u32subtitletype)
                                {
                                    case E_VDP_CODEC_ID_SUBTITLE_IMAGE_VOBSUB:
                                        numb = MB_Message.u8Parameters[2];
                                        addr = COMBU32(MB_Message.u8Parameters[3], MB_Message.u8Parameters[4], MB_Message.u8Parameters[5], MB_Message.u8Parameters[6]);

                                        if (numb && addr)
                                        {
                                            U8  n;
                                            U32 buf[16];

                                            memset(buf, 0, sizeof(buf));
                                            msAPI_MIU_Copy(addr, (U32) buf, 64, MIU_SDRAM2SDRAM);

                                            for (n = 0; n < numb; n++)
                                            {
                                                *(buf + n) = (*(buf + n));
                                            }

                                            msAPI_MpegSP_SetPalette(buf,  numb);
                                        }
                                        break;


                                    case E_VDP_CODEC_ID_SUBTITLE_TEXT_SRT:
                                    case E_VDP_CODEC_ID_SUBTITLE_TEXT_UTF8:
                                    case E_VDP_CODEC_ID_SUBTITLE_TEXT_ASS:
                                    case E_VDP_CODEC_ID_SUBTITLE_TEXT_SSA:
                                    case E_VDP_CODEC_ID_SUBTITLE_TEXT_USF:
                                    case E_VDP_CODEC_ID_SUBTITLE_TEXT_3GPP:
                                        break;

                                    default:
                                        break;
                                }
                                break;
                            }

                        // MB_VDPLAYER_SPUQUEUE_PUSH ----------------------------------------------
                        case MB_VDPLAYER_SPUQUEUE_PUSH:
                        {
                            if (enVideoPlayerPlayingType == VIDEO_PLAYER_PLAYING_TYPE_MPEG2)
                            {
                                U32 adr = COMBU32(MB_Message.u8Parameters[0], MB_Message.u8Parameters[1], MB_Message.u8Parameters[2], MB_Message.u8Parameters[3]);

                                U16 len = COMBU16(MB_Message.u8Parameters[4], MB_Message.u8Parameters[5]);

                                U32 pts = COMBU32(MB_Message.u8Parameters[6], MB_Message.u8Parameters[7], MB_Message.u8Parameters[8], MB_Message.u8Parameters[9]);

                                msAPI_VDPlayer_SubtitlePushQueue(E_VDP_CODEC_ID_SUBTITLE_IMAGE_VOBSUB, adr, len, pts, 0);

                                break;
                            }
#if (ENABLE_SUBTITLE_TS)
                            else if(enVideoPlayerPlayingType == VIDEO_PLAYER_PLAYING_TYPE_TS)
                            {
#if (ENABLE_DTV || OBA2)
                                U32 u32SdramAddr=0;
                                U16 u16PesLen=0;
                                U32 u32PTS=0;

                                //(printf("\tMB_VDPLAYER_SPUQUEUE_PUSH\n"));

                                u32SdramAddr = COMBU32(MB_Message.u8Parameters[0], MB_Message.u8Parameters[1], MB_Message.u8Parameters[2], MB_Message.u8Parameters[3]);
                                u16PesLen = COMBU16(MB_Message.u8Parameters[4], MB_Message.u8Parameters[5]);
                                u32PTS = COMBU32(MB_Message.u8Parameters[6], MB_Message.u8Parameters[7], MB_Message.u8Parameters[8], MB_Message.u8Parameters[9]);
                                msAPI_Subtitle_Queue_Push(_PA2VA(u32SdramAddr), u16PesLen, u32PTS);

                                if (msAPI_MailBox_WaitReady())
                                {
                                    MailBoxPara.u8CmdClass      = MB_CLASS_VDPLAYER;
                                    MailBoxPara.u8CmdIdx        = MB_VDPLAYER_ACK_51ToAEON;
                                    MailBoxPara.ParamCnt        = 1;
                                    MailBoxPara.CMDType         = MB_CMD_TYPE_DEFAULT;
                                    MailBoxPara.u8Param[0]      = MB_VDPLAYER_SPUQUEUE_PUSH;
                                    msAPI_MailBox_SendMsg();
                                }
#endif //#if (ENABLE_DTV)
                                break;
                            }
#endif
                            else
                            {
                                U32 u32PTS1;
                                U32 u32PTS2;

                                u32subtitletype = _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_SUBTITLE_CODEC_ID);
                                switch (u32subtitletype)
                                {
                                    case E_VDP_CODEC_ID_SUBTITLE_IMAGE_VOBSUB:
                                        spuqueuesize = (((U16) MB_Message.u8Parameters[2] << 8) & 0xFF00) | (((U16)MB_Message.u8Parameters[3])&0x00FF);
                                        u32PTS1 = (((U32)MB_Message.u8Parameters[4]<<24)&0xFF000000) |
                                                    (((U32)MB_Message.u8Parameters[5]<<16)&0x00FF0000) |
                                                    (((U32)MB_Message.u8Parameters[6]<<8)&0x0000FF00) |
                                                    (((U32)MB_Message.u8Parameters[7])&0x000000FF);

                                        msAPI_VDPlayer_SubtitlePushQueue((EN_VDP_CODECID)u32subtitletype, spuqueueaddr, (U32)spuqueuesize, u32PTS1, 0);

                                        //u8subtitletype = MB_Message.u8Parameters[0];
                                        break;

                                    case E_VDP_CODEC_ID_SUBTITLE_IMAGE_BMP:    //divx
                                        {
                                            U16 len = COMBU16(MB_Message.u8Parameters[2], MB_Message.u8Parameters[3]);
                                            U32 adr = COMBU32(MB_Message.u8Parameters[4], MB_Message.u8Parameters[5], MB_Message.u8Parameters[6], MB_Message.u8Parameters[7]);

                                            msAPI_VDPlayer_SubtitlePushQueue((EN_VDP_CODECID)u32subtitletype, adr, len, 0, 0);

                                            //u8subtitletype = MB_Message.u8Parameters[0];
                                            break;
                                        }
                                        /*switch (MB_Message.u8Parameters[1])
                                        {
                                            case E_SUBTITLE_VIDEO_TYPE_MPEG4:
                                            case E_SUBTITLE_VIDEO_TYPE_MKV:                                                 //VOBSUB format
                                                u32PTS1 = (((U32)MB_Message.u8Parameters[4]<<24)&0xFF000000) |
                                                            (((U32)MB_Message.u8Parameters[5]<<16)&0x00FF0000) |
                                                            (((U32)MB_Message.u8Parameters[6]<<8)&0x0000FF00) |
                                                            (((U32)MB_Message.u8Parameters[7])&0x000000FF);

                                                msAPI_VDPlayer_SubtitlePushQueue(MB_Message.u8Parameters[0], MB_Message.u8Parameters[1], spuqueueaddr, (U32)spuqueuesize, u32PTS1, 0);

                                                break;

                                            case E_SUBTITLE_VIDEO_TYPE_DIVX:
                                            case E_SUBTITLE_VIDEO_TYPE_XVID: //AVI format
                                            {
                                                U16 len = COMBU16(MB_Message.u8Parameters[2], MB_Message.u8Parameters[3]);
                                                U32 adr = COMBU32(MB_Message.u8Parameters[4], MB_Message.u8Parameters[5], MB_Message.u8Parameters[6], MB_Message.u8Parameters[7]);

                                                msAPI_VDPlayer_SubtitlePushQueue(MB_Message.u8Parameters[0], MB_Message.u8Parameters[1], adr, len, 0, 0);

                                                break;
                                            }

                                            default:
                                                break;
                                        }*/


                                    case E_VDP_CODEC_ID_SUBTITLE_TEXT_SRT:
                                    case E_VDP_CODEC_ID_SUBTITLE_TEXT_UTF8:
                                    case E_VDP_CODEC_ID_SUBTITLE_TEXT_ASS:
                                    case E_VDP_CODEC_ID_SUBTITLE_TEXT_SSA:
                                    case E_VDP_CODEC_ID_SUBTITLE_TEXT_USF:
                                    case E_VDP_CODEC_ID_SUBTITLE_TEXT_3GPP:
                                        //need to implement in vdplayer...timothy.h
                                        u32PTS1 = (((U32)MB_Message.u8Parameters[2]<<24)&0xFF000000) |
                                                                    (((U32)MB_Message.u8Parameters[3]<<16)&0x00FF0000) |
                                                                    (((U32)MB_Message.u8Parameters[4]<<8)&0x0000FF00) |
                                                                    (((U32)MB_Message.u8Parameters[5])&0x000000FF);
                                        u32PTS2 = (((U32)MB_Message.u8Parameters[6]<<8)&0x0000FF00) | (((U32)MB_Message.u8Parameters[7])&0x000000FF);
                                        u32PTS2 += u32PTS1;

                                        msAPI_VDPlayer_SubtitlePushQueue( (EN_VDP_CODECID)u32subtitletype, /*MB_Message.u8Parameters[1],*/ spuqueueaddr,spuqueuesize, u32PTS1  , u32PTS2 );

                                        break;

                                    default:// unknow format
                                        break;
                                }

                                spuqueueaddr=0;
                                spuqueuesize=0;

                                break;
                            }
                        }

                        // MB_VDPLAYER_SPUQUEUE_GET_DRAM_ADDR_TO_AEON ----------------------------------------------
                        case MB_VDPLAYER_SPUQUEUE_GET_DRAM_ADDR_TO_AEON:
#if (ENABLE_SUBTITLE_TS)
                            if (enVideoPlayerPlayingType == VIDEO_PLAYER_PLAYING_TYPE_TS)
                            {
#if (ENABLE_DTV || OBA2)
                                /// provide subtitle decoder PES Queue buffer.
                                if (msAPI_MailBox_WaitReady())
                                {
                                    U32 u32SDRAMAddress = msAPI_Subtitle_Queue_GetSDRAMAddress(0);
                                    u32SDRAMAddress = _VA2PA(u32SDRAMAddress);

                                    VDPLAYER_DBG(printf("\tsubtitle queue buffer addr:0x%x  len:0x%x\n",u32SDRAMAddress,SBTL_QUEUE_LEN));

                                    MailBoxPara.u8CmdClass      = MB_CLASS_VDPLAYER;
                                    MailBoxPara.u8CmdIdx        = MB_VDPLAYER_ACK_51ToAEON;
                                    MailBoxPara.ParamCnt        = 10;
                                    MailBoxPara.CMDType         = MB_CMD_TYPE_DEFAULT;
                                    MailBoxPara.u8Param[0]      = MB_VDPLAYER_SPUQUEUE_GET_DRAM_ADDR_TO_AEON;

                                    MailBoxPara.u8Param[1]      = GetByte3(u32SDRAMAddress);//(U8)((u32SDRAMAddress&0xFF000000)>>24);
                                    MailBoxPara.u8Param[2]      = GetByte2(u32SDRAMAddress);//(U8)((u32SDRAMAddress&0x00FF0000)>>16);
                                    MailBoxPara.u8Param[3]      = GetByte1(u32SDRAMAddress);//(U8)((u32SDRAMAddress&0x0000FF00)>>8);
                                    MailBoxPara.u8Param[4]      = GetByte0(u32SDRAMAddress);//(U8)(u32SDRAMAddress&0x000000FF);

                                    MailBoxPara.u8Param[5]      = GetByte3(SBTL_QUEUE_LEN);//(U8)((SBTL_QUEUE_LEN&0xFF000000)>>24);
                                    MailBoxPara.u8Param[6]      = GetByte2(SBTL_QUEUE_LEN);//(U8)((SBTL_QUEUE_LEN&0x00FF0000)>>16);
                                    MailBoxPara.u8Param[7]      = GetByte1(SBTL_QUEUE_LEN);//(U8)((SBTL_QUEUE_LEN&0x0000FF00)>>8);
                                    MailBoxPara.u8Param[8]      = GetByte0(SBTL_QUEUE_LEN);//(U8)(SBTL_QUEUE_LEN&0x000000FF);

                                    MailBoxPara.u8Param[9]      = (U8)EN_VDP_FILE_FORMAT_TS;

                                    msAPI_MailBox_SendMsg();
                                }
#endif
                                break;
                            }
                            else
#endif
                        {
                                U32 sb_type = _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_SUBTITLE_CODEC_ID);

                            switch (sb_type)
                            {
                                case E_VDP_CODEC_ID_SUBTITLE_IMAGE_BMP:
                                case E_VDP_CODEC_ID_SUBTITLE_IMAGE_VOBSUB:
                                    {
                                        U16 len = COMBU16(MB_Message.u8Parameters[2], MB_Message.u8Parameters[3]);

                                        U32 adr = msAPI_MpegSP_SpuQueue_GetSDRAMAddress(len);

                                        if (msAPI_MailBox_WaitReady())
                                        {
                                            MailBoxPara.u8CmdClass  = MB_CLASS_VDPLAYER;
                                            MailBoxPara.u8CmdIdx    = MB_VDPLAYER_ACK_51ToAEON;
                                            MailBoxPara.ParamCnt    = 5;
                                            MailBoxPara.CMDType     = MB_CMD_TYPE_DEFAULT;
                                            MailBoxPara.u8Param[0]  = MB_VDPLAYER_SPUQUEUE_GET_DRAM_ADDR_TO_AEON;
                                            MailBoxPara.u8Param[1]  = GetByte3(adr);
                                            MailBoxPara.u8Param[2]  = GetByte2(adr);
                                            MailBoxPara.u8Param[3]  = GetByte1(adr);
                                            MailBoxPara.u8Param[4]  = GetByte0(adr);

                                            msAPI_MailBox_SendMsg();
                                        }
                                        spuqueueaddr = adr;
                                        spuqueuesize = len;
                                    }
                                    break;

                                case E_VDP_CODEC_ID_SUBTITLE_TEXT_SRT:
                                case E_VDP_CODEC_ID_SUBTITLE_TEXT_UTF8:
                                case E_VDP_CODEC_ID_SUBTITLE_TEXT_ASS:
                                case E_VDP_CODEC_ID_SUBTITLE_TEXT_SSA:
                                case E_VDP_CODEC_ID_SUBTITLE_TEXT_USF:
                                case E_VDP_CODEC_ID_SUBTITLE_TEXT_3GPP:
                                    spuqueueaddr= (((U32)u16tagposition)<<8) + MP4_SUBTITLE_BUFFER_ADR;
                                    spuqueuesize=0x100;

                                    if (msAPI_MailBox_WaitReady())
                                    {
                                        MailBoxPara.u8CmdClass      = MB_CLASS_VDPLAYER;
                                        MailBoxPara.u8CmdIdx        = MB_VDPLAYER_ACK_51ToAEON;
                                        MailBoxPara.ParamCnt        = 5;
                                        MailBoxPara.CMDType         = MB_CMD_TYPE_DEFAULT;
                                        MailBoxPara.u8Param[0] = MB_VDPLAYER_SPUQUEUE_GET_DRAM_ADDR_TO_AEON;
                                        MailBoxPara.u8Param[1]      = (U8)((spuqueueaddr&0xFF000000)>>24);
                                        MailBoxPara.u8Param[2]      = (U8)((spuqueueaddr&0x00FF0000)>>16);
                                        MailBoxPara.u8Param[3]      = (U8)((spuqueueaddr&0x0000FF00)>>8);
                                        MailBoxPara.u8Param[4]      = (U8)(spuqueueaddr&0x000000FF);
                                        msAPI_MailBox_SendMsg();
                                    }
                                    break;

                                default:
                                    break;
                            }

                            break;
                        }

                        // MB_VDPLAYER_MPEG_SET_SUBTITLE_SHOW ----------------------------------------------
                        case MB_VDPLAYER_MPEG_SET_SUBTITLE_SHOW:
                        {
                            U32 sb_type = _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_SUBTITLE_CODEC_ID);
#if (ENABLE_SUBTITLE_TS)

                            if(enVideoPlayerPlayingType == VIDEO_PLAYER_PLAYING_TYPE_TS)
                            {
#if (ENABLE_DTV || OBA2)
                                //(printf("\tMB_VDPLAYER_MPEG_SET_SUBTITLE_SHOW:%d \n",MB_Message.u8Parameters[2]));
                                // set display status by player
                                u8DVBTSSubtitleServiceNum = _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_TOTAL_SUBTITLE);
                                _bSubtitleShow_MW = MB_Message.u8Parameters[2];

                                if (!(_bSubtitleShow_MW && _bSubtitleShow_User && u8DVBTSSubtitleServiceNum>0))
                                {
                                    //(printf("\tsubtitle unshow\n"));
                                    if(MApp_TS_Subtitle_Get_SubtitleOSDState())
                                    {
                                        MApp_TS_Subtitle_Switch2IP();
                                        MApp_TS_Subtitle_Exit();
                                        MApp_TS_Subtitle_Switch2OP();
                                    }
                                }
#endif //#if (ENABLE_DTV)
                                break;
                            }
#endif
                            switch (sb_type)
                            {
                                case E_VDP_CODEC_ID_SUBTITLE_IMAGE_BMP:
                                case E_VDP_CODEC_ID_SUBTITLE_IMAGE_VOBSUB:
                                    if (MB_Message.u8Parameters[2] == TRUE)
                                    {
                                        msAPI_MpegSP_Show();
                                    }
                                    else
                                    {
                                        msAPI_MpegSP_Unshow();
                                    }
/*
                                    if (msAPI_MailBox_WaitReady())
                                    {
                                        MailBoxPara.u8CmdClass  = MB_CLASS_VDPLAYER;
                                        MailBoxPara.u8CmdIdx    = MB_VDPLAYER_ACK_51ToAEON;
                                        MailBoxPara.ParamCnt    = 1;
                                        MailBoxPara.CMDType     = MB_CMD_TYPE_DEFAULT;
                                        MailBoxPara.u8Param[0]  = MB_VDPLAYER_MPEG_SET_SUBTITLE_SHOW;
                                        msAPI_MailBox_SendMsg();
                                    }
*/
                                    break;

                                case E_VDP_CODEC_ID_SUBTITLE_TEXT_SRT:
                                case E_VDP_CODEC_ID_SUBTITLE_TEXT_UTF8:
                                case E_VDP_CODEC_ID_SUBTITLE_TEXT_ASS:
                                case E_VDP_CODEC_ID_SUBTITLE_TEXT_SSA:
                                case E_VDP_CODEC_ID_SUBTITLE_TEXT_USF:
                                case E_VDP_CODEC_ID_SUBTITLE_TEXT_3GPP:
                                    // need to check timothy.h
                                    if (MB_Message.u8Parameters[2] == TRUE)
                                    {
                                        _Mapp_VDPlayer_SetShareMemData(E_SHAREMEM_CURRENT_SUBTITLE_TAGCOUNT,(U32)(( MP4_SUBTITLE_BUFFER_LEN >> 8)-u16subtitletagcounter));
                                    }
                                    else
                                    {
                                        _Mapp_VDPlayer_SetShareMemData(E_SHAREMEM_CURRENT_SUBTITLE_TAGCOUNT, 0 );
                                    }
/*
                                    if (msAPI_MailBox_WaitReady())
                                    {
                                        MailBoxPara.u8CmdClass  = MB_CLASS_VDPLAYER;
                                        MailBoxPara.u8CmdIdx    = MB_VDPLAYER_ACK_51ToAEON;
                                        MailBoxPara.ParamCnt    = 1;
                                        MailBoxPara.CMDType     = MB_CMD_TYPE_DEFAULT;
                                        MailBoxPara.u8Param[0]  = MB_VDPLAYER_MPEG_SET_SUBTITLE_SHOW;
                                        msAPI_MailBox_SendMsg();
                                    }
*/
                                    break;

                                default:
                                    break;
                            }

                            break;
                        }


                        // MB_VDPLAYER_MPEG_SUBTITLE_RESET ----------------------------------------------
                        case MB_VDPLAYER_MPEG_SUBTITLE_RESET:
                            if (msAPI_MailBox_WaitReady())
                            {
                                MailBoxPara.u8CmdClass  = MB_CLASS_VDPLAYER;
                                MailBoxPara.u8CmdIdx    = MB_VDPLAYER_ACK_51ToAEON;
                                MailBoxPara.ParamCnt    = 1;
                                MailBoxPara.CMDType     = MB_CMD_TYPE_DEFAULT;
                                MailBoxPara.u8Param[0]  = MB_VDPLAYER_MPEG_SUBTITLE_RESET;
                                msAPI_MailBox_SendMsg();
                            }
                            break;
#if (ENABLE_SUBTITLE_TS)
#if (ENABLE_DTV || OBA2)
                        case MB_VDPLAYER_SET_SUBTITLE_TRACKID:
                            //(printf("\tMB_VDPLAYER_SET_SUBTITLE_TRACKID \n"));
                            {
                                U16 u16CPageID,u16APageID;
                                u16CPageID = COMBU16(MB_Message.u8Parameters[0], MB_Message.u8Parameters[1]);
                                u16APageID = COMBU16(MB_Message.u8Parameters[2], MB_Message.u8Parameters[3]);
                                msAPI_Subtitle_Init_Queue(_PA2VA(((SUBTITLE_MEMORY_TYPE & MIU1) ? (SUBTITLE_ADR | MIU_INTERVAL) : (SUBTITLE_ADR))), SUBTITLE_LEN);
                                msAPI_Subtitle_SetPageIDs(u16CPageID, u16APageID);

                                if(MApp_TS_Subtitle_Get_SubtitleOSDState())
                                {
                                    // if subtitle on, clear GWIN buffer of GOP.
                                    printf("\t_bSubtitleOn\n");
                                    MApp_TS_Subtitle_Switch2IP();
                                    MApp_TS_Subtitle_Exit();       // clear old track subtitle
                                    MApp_TS_Subtitle_Switch2OP();
                                }
                            }
                            break;

#endif //#if (ENABLE_DTV)
#endif

                        // MB_VDPLAYER_MPEG_SUBTITLE_INIT_DEINIT ----------------------------------------------
                        case MB_VDPLAYER_MPEG_SUBTITLE_INIT_DEINIT:
                        {
                            U8 u8Cmd = MB_Message.u8Parameters[0];
                            U32 u32Sb_type;
#if (ENABLE_SUBTITLE_TS)
                            if (u8Cmd == E_SUBTITLE_INIT_COMMAND_INIT && enVideoPlayerPlayingType == VIDEO_PLAYER_PLAYING_TYPE_TS)
                            {
#if (ENABLE_DTV || OBA2)
                                //(printf("\tTS subtitle init \n"));
                                //(printf("\tMB_VDPLAYER_MPEG_SUBTITLE_INIT_DEINIT \n"));
                                //(printf("\tSubtitle Init Queue,SUBTITLE_ADR:0x%x, SUBTITLE_LEN:0x%x\n",SUBTITLE_ADR, SUBTITLE_LEN));
                                //(printf("\tTSP subtitle buffer addr:0x%x, len:0x%x\n",u32SubtitleAddr,u32SubtitleSize));

                                u32Sb_type  = _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_SUBTITLE_CODEC_ID);
                                msAPI_Subtitle_Init_Queue(_PA2VA(((SUBTITLE_MEMORY_TYPE & MIU1) ? (SUBTITLE_ADR | MIU_INTERVAL) : (SUBTITLE_ADR))), SUBTITLE_LEN);

                                /// provide TSP section monitor PES buffer
                                if (msAPI_MailBox_WaitReady())
                                {

                                    MailBoxPara.u8CmdClass      = MB_CLASS_VDPLAYER;
                                    MailBoxPara.u8CmdIdx        = MB_VDPLAYER_ACK_51ToAEON;
                                    MailBoxPara.ParamCnt        = 10;
                                    MailBoxPara.CMDType         = MB_CMD_TYPE_DEFAULT;
                                    MailBoxPara.u8Param[0]      = MB_VDPLAYER_MPEG_SUBTITLE_INIT_DEINIT;

                                    MailBoxPara.u8Param[1]      = GetByte3(u32SubtitleAddr);// for demux PES buffer
                                    MailBoxPara.u8Param[2]      = GetByte2(u32SubtitleAddr);
                                    MailBoxPara.u8Param[3]      = GetByte1(u32SubtitleAddr);
                                    MailBoxPara.u8Param[4]      = GetByte0(u32SubtitleAddr);

                                    MailBoxPara.u8Param[5]      = GetByte3(u32SubtitleSize);
                                    MailBoxPara.u8Param[6]      = GetByte2(u32SubtitleSize);
                                    MailBoxPara.u8Param[7]      = GetByte1(u32SubtitleSize);
                                    MailBoxPara.u8Param[8]      = GetByte0(u32SubtitleSize);

                                    MailBoxPara.u8Param[9]      = (U8)EN_VDP_FILE_FORMAT_TS;

                                    msAPI_MailBox_SendMsg();
                                }

                                //Control Subtitle
                                _bSubtitleShow_MW = ENABLE;
                                u32subtitletype = u32Sb_type;
                                u8IsSubtitleBusy = FALSE;
                                u8IssubtitleInit = TRUE;

                                VDPLAYER_DBG(printf( " [Aeon OS] TS subtitle init success \n"));
#endif  //#if (ENABLE_DTV)
                                break;
                            }
                            else if (u8Cmd == E_SUBTITLE_INIT_COMMAND_DEINIT && enVideoPlayerPlayingType == VIDEO_PLAYER_PLAYING_TYPE_TS)
                            {
#if (ENABLE_DTV)
                                //printf("\tE_SUBTITLE_INIT_COMMAND_DEINIT\n");
                                if(MApp_TS_Subtitle_Get_SubtitleOSDState())
                                {
                                    MApp_TS_Subtitle_Switch2IP();
                                    MApp_TS_Subtitle_Exit();
                                    MApp_TS_Subtitle_Switch2OP();
                                }

                                u8IssubtitleInit = FALSE;
                                _bSubtitleShow_MW   = DISABLE;      // control by MW.

#endif  //#if (ENABLE_DTV)
                                break;
                            }
#endif

                            if (u8Cmd == E_SUBTITLE_INIT_COMMAND_INIT)
                            {
                                u32Sb_type  = _msAPI_APEngine_Obama_VDPlayer_GetShareMemData(E_SHAREMEM_SUBTITLE_CODEC_ID);

                                switch( u32Sb_type )
                                {
                                    case E_VDP_CODEC_ID_SUBTITLE_IMAGE_VOBSUB:
                                    case E_VDP_CODEC_ID_SUBTITLE_IMAGE_BMP:
                                        if (!msAPI_MpegSP_Init())
                                        {
                                            VDPLAYER_DBG(printf("subtitle picture init failed\n"));

                                            return;
                                        }

                                        u8IssubtitleInit = TRUE;

                                        if (enVideoPlayerPlayingType == VIDEO_PLAYER_PLAYING_TYPE_MPEG2)
                                        {
                                            u32subtitletype = E_VDP_CODEC_ID_SUBTITLE_IMAGE_VOBSUB;
                                        }
                                        else
                                        {
                                            U16 w, h;

                                            w = COMBU16(MB_Message.u8Parameters[5], MB_Message.u8Parameters[6]);
                                            h = COMBU16(MB_Message.u8Parameters[7], MB_Message.u8Parameters[8]);

                                            msAPI_MpegSP_SetSubtitleDimension(w, h);

                                            u32subtitletype = u32Sb_type;
                                        }
                                        _Mapp_VDPlayer_SetShareMemData(E_SHAREMEM_CURRENT_SUBTITLE_TAGCOUNT,MAX_SPU_QUEUE_SIZE);
                                        break;
                                    case E_VDP_CODEC_ID_SUBTITLE_TEXT_SRT:
                                    case E_VDP_CODEC_ID_SUBTITLE_TEXT_UTF8:
                                    case E_VDP_CODEC_ID_SUBTITLE_TEXT_SSA:
                                    case E_VDP_CODEC_ID_SUBTITLE_TEXT_ASS:
                                    case E_VDP_CODEC_ID_SUBTITLE_TEXT_USF:
                                    case E_VDP_CODEC_ID_SUBTITLE_TEXT_3GPP:
                                        u16tagposition=0;
                                        u16subtitletagcounter=0;
                                        MApp_MPlayer_SubtitleInit();
                                        _Mapp_VDPlayer_SetShareMemData(E_SHAREMEM_CURRENT_SUBTITLE_TAGCOUNT, MP4_SUBTITLE_BUFFER_LEN >> 8);
                                        spuqueueaddr= (((U32)u16tagposition)<<8) + MP4_SUBTITLE_BUFFER_ADR;
                                        //spulen=MP4_SUBTITLE_BUFFER_LEN;
                                        break;
                                    default:// unknow format
                                        break;
                                }

                                if (msAPI_MailBox_WaitReady())
                                {
                                    MailBoxPara.u8CmdClass      = MB_CLASS_VDPLAYER;
                                    MailBoxPara.u8CmdIdx        = MB_VDPLAYER_ACK_51ToAEON;
                                    MailBoxPara.ParamCnt        = 1;
                                    MailBoxPara.CMDType         = MB_CMD_TYPE_DEFAULT;
                                    MailBoxPara.u8Param[0]      = MB_VDPLAYER_MPEG_SUBTITLE_INIT_DEINIT;
                                    /*
                                    MailBoxPara.u8Param[1]      = MB_Message.u8Parameters[2];//u8subtitletype;
                                    MailBoxPara.u8Param[2]      = (U8)((spuqueueaddr&0xFF000000)>>24);
                                    MailBoxPara.u8Param[3]      = (U8)((spuqueueaddr&0x00FF0000)>>16);
                                    MailBoxPara.u8Param[4]      = (U8)((spuqueueaddr&0x0000FF00)>>8);
                                    MailBoxPara.u8Param[5]      = (U8)(spuqueueaddr&0x000000FF);
                                    */

                                    msAPI_MailBox_SendMsg();

                                    VDPLAYER_DBG(printf( " [Aeon OS] subtitle init success \n"));
                                }
#if (ENABLE_SUBTITLE_AutoShow)
                                if((MB_Message.u8Parameters[3]==TRUE)&&(enVideoPlayerPlayingType == VIDEO_PLAYER_PLAYING_TYPE_MPEG2))
                                {
                                    msAPI_MpegSP_Show();
                                }
#endif
                                u8IsSubtitleBusy        = FALSE;
                            }
                            else if (u8Cmd == E_SUBTITLE_INIT_COMMAND_DEINIT)
                            {
                                //if (MB_Message.u8Parameters[1] == TRUE)
                                {
                                    msAPI_MpegSP_Dinit();
                                }

                                //if (MB_Message.u8Parameters[2] == TRUE)
                                {
                                    u16tagposition=0;
                                    u16subtitletagcounter=0;
                                    MApp_MPlayer_SubtitleInit();
                                    _Mapp_VDPlayer_SetShareMemData(E_SHAREMEM_CURRENT_SUBTITLE_TAGCOUNT,0);
                                }

                                u8IssubtitleInit        = FALSE;
                                u32subtitletype          = 0;
                                u8IsSubtitleBusy        = FALSE;
                                u8IsSubtitleInitfinish  = FALSE;
                                u32GetSubtitleStateBuf  = 0;
                            }
                            else
                            {
                                u8IsSubtitleInitfinish = TRUE;
                            }


#if 0
                            if (enVideoPlayerPlayingType == VIDEO_PLAYER_PLAYING_TYPE_MPEG2)
                            {
                                if (cmd == E_SUBTITLE_INIT_COMMAND_INIT)
                                {
                                    msAPI_MpegSP_Init();

                                    u8IssubtitleInit    = TRUE;
                                    u32subtitletype      = E_VDP_CODEC_ID_SUBTITLE_IMAGE_VOBSUB;
                                }
                                else
                                {
                                    msAPI_MpegSP_Dinit();
                                    u8IssubtitleInit = FALSE;
                                }

                                break;
                            }
                            else
                            {
                                if (cmd == E_SUBTITLE_INIT_COMMAND_INIT)
                                {
                                    U32 spulen = 0;

                                    if (sb_type != E_VDP_CODEC_ID_NONE)
                                    {
                                        switch (MB_Message.u8Parameters[1])
                                        {
                                            case E_VDP_CODEC_ID_SUBTITLE_IMAGE_VOBSUB:
                                            case E_VDP_CODEC_ID_SUBTITLE_IMAGE_BMP:
                                                if (msAPI_MpegSP_Init())
                                                {
                                                    U16 w, h;

                                                    w = COMBU16(MB_Message.u8Parameters[4], MB_Message.u8Parameters[5]);
                                                    h = COMBU16(MB_Message.u8Parameters[6], MB_Message.u8Parameters[7]);

                                                    msAPI_MpegSP_SetSubtitleDimension(w, h);

                                                    u32subtitletype      = MB_Message.u8Parameters[1];
                                                    u8IssubtitleInit    = TRUE;
                                                }
                                                else
                                                {
                                                    printf("subtitle picture init failed\n");
                                                }
                                                break;

                                            default:
                                                break;
                                        }
                                    }

                                    else if (MB_Message.u8Parameters[2] != E_VDP_CODEC_ID_NONE)
                                    {
                                        switch(  MB_Message.u8Parameters[2] )
                                        {
                                            case E_VDP_CODEC_ID_SUBTITLE_IMAGE_VOBSUB:
                                            case E_VDP_CODEC_ID_SUBTITLE_IMAGE_BMP:
                                                break;
                                            case E_VDP_CODEC_ID_SUBTITLE_TEXT_SRT:
                                            case E_VDP_CODEC_ID_SUBTITLE_TEXT_SSA:
                                            case E_VDP_CODEC_ID_SUBTITLE_TEXT_USF:
                                            case E_VDP_CODEC_ID_SUBTITLE_TEXT_3GPP:
                                                u16tagposition=0;
                                                u16subtitletagcounter=0;
                                                MApp_MPlayer_SubtitleInit();
                                                spuqueueaddr= (((U32)u16tagposition)<<8) + MP4_SUBTITLE_BUFFER_ADR;
                                                spulen=MP4_SUBTITLE_BUFFER_LEN;
                                                break;
                                            default:// unknow format
                                                break;
                                        }

                                        if (msAPI_MailBox_WaitReady())
                                        {
                                            MailBoxPara.u8CmdClass      = MB_CLASS_VDPLAYER;
                                            MailBoxPara.u8CmdIdx        = MB_VDPLAYER_ACK_51ToAEON;
                                            MailBoxPara.ParamCnt        = 10;
                                            MailBoxPara.CMDType         = MB_CMD_TYPE_DEFAULT;
                                            MailBoxPara.u8Param[0]      = MB_VDPLAYER_MPEG_SUBTITLE_INIT_DEINIT;
                                            MailBoxPara.u8Param[1]      = MB_Message.u8Parameters[2];//u8subtitletype;
                                            MailBoxPara.u8Param[2]      = (U8)((spuqueueaddr&0xFF000000)>>24);
                                            MailBoxPara.u8Param[3]      = (U8)((spuqueueaddr&0x00FF0000)>>16);
                                            MailBoxPara.u8Param[4]      = (U8)((spuqueueaddr&0x0000FF00)>>8);
                                            MailBoxPara.u8Param[5]      = (U8)(spuqueueaddr&0x000000FF);
                                            MailBoxPara.u8Param[6]      = (U8)((spulen&0xFF000000)>>24);
                                            MailBoxPara.u8Param[7]      = (U8)((spulen&0x00FF0000)>>16);
                                            MailBoxPara.u8Param[8]      = (U8)((spulen&0x0000FF00)>>8);
                                            MailBoxPara.u8Param[9]      = (U8)(spulen&0x000000FF);

                                            msAPI_MailBox_SendMsg();

                                            printf("[Aeon 51] init text type: %d ; addr: 0x%lx ",  (U16)MB_Message.u8Parameters[1] ,  spuqueueaddr);
                                        }
                                    }
                                    else if( MB_Message.u8Parameters[3] == TRUE)
                                    {
                                        if( spuqueueaddr > 0 )
                                        {
                                            printf( " [Aeon OS] subtitle init success \n");
                                            u8IssubtitleInit=TRUE;
                                        }
                                    }
                                }
                                else if (MB_Message.u8Parameters[0] == E_SUBTITLE_INIT_COMMAND_DEINIT)
                                {
                                    if (MB_Message.u8Parameters[1] == TRUE)
                                    {
                                        msAPI_MpegSP_Dinit();
                                    }

                                    if (MB_Message.u8Parameters[2] == TRUE)
                                    {
                                        u16tagposition=0;
                                        u16subtitletagcounter=0;
                                        MApp_MPlayer_SubtitleInit();
                                    }

                                    u8IssubtitleInit        = FALSE;
                                    u32subtitletype          = 0;
                                    u8IsSubtitleBusy        = FALSE;
                                    u8IsSubtitleInitfinish  = FALSE;
                                    u32GetSubtitleStateBuf  = 0;
                                }
                                else if (MB_Message.u8Parameters[0] == E_SUBTITLE_INIT_COMMAND_INIT_FINISH)
                                {
                                    u8IsSubtitleInitfinish = TRUE;
                                }
                            }

#endif
                            break;
                        }


                    case MB_VDPLAYER_MPEG_SUBTITLE_FILEPROCESS:
                        switch(   MB_Message.u8Parameters[0]  )
                        {
                            case MB_VDPLAYER_FILE_READ:
                                {
                                    U32 destaddr=0;
                                    U16 size=0;
                                    U16 read_size1=0;
                                    destaddr= (((U32)MB_Message.u8Parameters[1]<<24)&0xFF000000) |
                                                                (((U32)MB_Message.u8Parameters[2]<<16)&0x00FF0000) |
                                                                (((U32)MB_Message.u8Parameters[3]<<8)&0x0000FF00) |
                                                                (((U32)MB_Message.u8Parameters[4])&0x000000FF);
                                    size=(((U16)MB_Message.u8Parameters[5]<<8)&0xFF00) | (((U16)MB_Message.u8Parameters[6])&0x00FF);
                                    read_size1 = msAPI_FCtrl_FileRead(VDPlayer_Subtitle_file_id, destaddr, (U32)size);

                                    if (msAPI_MailBox_WaitReady())
                                    {
                                        MailBoxPara.u8CmdClass      = MB_CLASS_VDPLAYER_FS;
                                        MailBoxPara.u8CmdIdx        = MB_VDPLAYER_MPEG_SUBTITLE_FILEPROCESS;
                                        MailBoxPara.ParamCnt        = 3;
                                        MailBoxPara.CMDType         = MB_CMD_TYPE_DEFAULT;
                                        MailBoxPara.u8Param[0] = MB_VDPLAYER_FILE_READ;
                                        MailBoxPara.u8Param[1]      = (U8)((read_size1&0xFF00)>>8);
                                        MailBoxPara.u8Param[2]      = (U8)(read_size1&0x00FF);
                                        msAPI_MailBox_SendMsg();
                                    }
                                    //printf( " [Aeon 51] file process:player handle %d ; subtitle handle %d ;file read left: 0x%x\n" , (U16)VDPlayer_file_id , (U16)VDPlayer_Subtitle_file_id, read_size1 );
                                }
                                break;
                            case MB_VDPLAYER_FILE_SEEK:
                                {
                                    U8 rst=0;
                                    U32 offset=0;
                                    for(i=6; i<10; i++)
                                    {
                                        u32Offset = (u32Offset<<8) | MB_Message.u8Parameters[i];
                                    }
                                    rst = msAPI_FCtrl_FileSeek(VDPlayer_Subtitle_file_id, offset, FILE_SEEK_SET);
                                    if (msAPI_MailBox_WaitReady())
                                    {
                                        MailBoxPara.u8CmdClass      = MB_CLASS_VDPLAYER_FS;
                                        MailBoxPara.u8CmdIdx        = MB_VDPLAYER_MPEG_SUBTITLE_FILEPROCESS;
                                        MailBoxPara.ParamCnt        = 2;
                                        MailBoxPara.CMDType         = MB_CMD_TYPE_DEFAULT;
                                        MailBoxPara.u8Param[0] = MB_VDPLAYER_FILE_SEEK;
                                        MailBoxPara.u8Param[1] = rst;
                                        msAPI_MailBox_SendMsg();
                                    }
                                    //printf( " [Aeon 51] file process:player handle %d ; subtitle handle %d ; file seek result: %d\n"  , (U16)VDPlayer_file_id , (U16)VDPlayer_Subtitle_file_id, (U16)rst );
                                }
                                break;

                            case MB_VDPLAYER_FILE_READ_NONBLOCKING :
                                {
                                    U8 rst=0;
                                    //U8 queuecount=0;
                                    //U32 destaddr=0;
                                    //U16 subsize=0;
                                    U16 read_size1=0;
                                    U32 offset=0;
                                    if( MB_Message.u8Parameters[2] == MB_VDPLAYER_FILE_SEEK )
                                    {
                                    //seek
                                        /*for(i=6; i<10; i++)
                                        {
                                            offset = (offset<<8) | MB_Message.u8Parameters[i];
                                        }
                                        rst = msAPI_FCtrl_FileSeek(VDPlayer_Subtitle_file_id, offset, FILE_SEEK_SET);
                                        */
                                        printf("MB_Message.u8Parameters[6]=%d\n",MB_Message.u8Parameters[6]);
                                        printf("MB_Message.u8Parameters[7]=%d\n",MB_Message.u8Parameters[7]);
                                        printf("MB_Message.u8Parameters[8]=%d\n",MB_Message.u8Parameters[8]);
                                        printf("MB_Message.u8Parameters[9]=%d\n",MB_Message.u8Parameters[9]);

                                        cur_activated_ap = MAdp_APMNG_GetActivatedAppPid();
                                        if(cur_activated_ap != 0)  // chakra is running
                                        {
                                            //DBG_INFO("Send Zodiac Message to pid: %d\n", cur_activated_ap);'
                                            pu8InData[0] = E_OBAMA_ZODIAC_MSG_FILE_READ_NONBLOCKING_SEEK;
                                            pu8InData[1] = MB_Message.u8Parameters[6];
                                            pu8InData[2] = MB_Message.u8Parameters[7];
                                            pu8InData[3] = MB_Message.u8Parameters[8];
                                            pu8InData[4] = MB_Message.u8Parameters[9];

                                            //if (MAdp_MSGCH_SendSignal(cur_activated_ap, MAdp_MSGCH_GetChannelIndex("ZODIAC_VDPLAYER"), (U8*)&pu8InData, sizeof(pu8InData)))
                                            if (!MAdp_MSGCH_Communicate(cur_activated_ap, MAdp_MSGCH_GetChannelIndex("ZODIAC_VDPLAYER"), (U8*)&pu8InData, sizeof(pu8InData), (U8*)&pu8OutData, sizeof(pu8OutData)))
                                            {
                                                printf("[D-Bus] Send Error\n");

                                            }
                                        }
                                        if (msAPI_MailBox_WaitReady())
                                        {
                                            MailBoxPara.u8CmdClass      = MB_CLASS_VDPLAYER;
                                            MailBoxPara.u8CmdIdx        = MB_VDPLAYER_ACK_51ToAEON;
                                            MailBoxPara.ParamCnt        = 2;
                                            MailBoxPara.CMDType         = MB_CMD_TYPE_DEFAULT;
                                            MailBoxPara.u8Param[0]      = MB_VDPLAYER_MPEG_SUBTITLE_FILEPROCESS;
                                            MailBoxPara.u8Param[1]      = MB_VDPLAYER_FILE_READ_NONBLOCKING;
                                            msAPI_MailBox_SendMsg();
                                        }
                                    }
                                //read
                                    else if( MB_Message.u8Parameters[2] == MB_VDPLAYER_FILE_READ)
                                    {
                                        /*
                                        subsize=(((U16)MB_Message.u8Parameters[7]<<8)&0xFF00) | (((U16)MB_Message.u8Parameters[8])&0x00FF);
                                        destaddr=(((U32)MB_Message.u8Parameters[3]<<24)&0xFF000000) |
                                                                    (((U32)MB_Message.u8Parameters[4]<<16)&0x00FF0000) |
                                                                    (((U32)MB_Message.u8Parameters[5]<<8)&0x0000FF00) |
                                                                    (((U32)MB_Message.u8Parameters[6])&0x000000FF);
                                        read_size1 = msAPI_FCtrl_FileRead(VDPlayer_Subtitle_file_id, destaddr, (U32)subsize);
                                        */
                                        cur_activated_ap = MAdp_APMNG_GetActivatedAppPid();
                                        if(cur_activated_ap != 0)  // chakra is running
                                        {
                                            //DBG_INFO("Send Zodiac Message to pid: %d\n", cur_activated_ap);'
                                            pu8InData[0] = E_OBAMA_ZODIAC_MSG_FILE_READ_NONBLOCKING;
                                            pu8InData[1] = MB_Message.u8Parameters[3];
                                            pu8InData[2] = MB_Message.u8Parameters[4];
                                            pu8InData[3] = MB_Message.u8Parameters[5];
                                            pu8InData[4] = MB_Message.u8Parameters[6];
                                            pu8InData[5] = MB_Message.u8Parameters[7];
                                            pu8InData[6] = MB_Message.u8Parameters[8];
                                            //if (MAdp_MSGCH_SendSignal(cur_activated_ap, MAdp_MSGCH_GetChannelIndex("ZODIAC_VDPLAYER"), (U8*)&pu8InData, sizeof(pu8InData)))
                                            if (!MAdp_MSGCH_Communicate(cur_activated_ap, MAdp_MSGCH_GetChannelIndex("ZODIAC_VDPLAYER"), (U8*)&pu8InData, sizeof(pu8InData), (U8*)&pu8OutData, sizeof(pu8OutData)))
                                            {
                                                printf("[D-Bus] Send Error\n");

                                            }
                                        }
                                        if (msAPI_MailBox_WaitReady())
                                        {
                                            MailBoxPara.u8CmdClass      = MB_CLASS_VDPLAYER_FS;
                                            MailBoxPara.u8CmdIdx        = MB_VDPLAYER_MPEG_SUBTITLE_FILEPROCESS;
                                            MailBoxPara.ParamCnt        = 3;
                                            MailBoxPara.CMDType         = MB_CMD_TYPE_DEFAULT;
                                            MailBoxPara.u8Param[0]      = MB_VDPLAYER_FILE_READ_NONBLOCKING;
                                            MailBoxPara.u8Param[1]      = pu8OutData[0];
                                            MailBoxPara.u8Param[2]      = pu8OutData[1];
                                            msAPI_MailBox_SendMsg();
                                        }
                                    }
                                    //printf( " [Aeon 51] file process:player handle %d ; subtitle handle %d ;file read left: 0x%x\n" , (U16)VDPlayer_file_id , (U16)VDPlayer_Subtitle_file_id, read_size1 );
                                }
                                break;
                            default:
                                break;
                        }
                        break;

                    case MB_VDPLAYER_MPEG_SUBTITLE_GETQUEUEINFO:
                        {
                            U8 queuecount = msAPI_MpegSP_SpuQueue_GetCount();

                            if (msAPI_MailBox_WaitReady())
                            {
                                MailBoxPara.u8CmdClass  = MB_CLASS_VDPLAYER;
                                MailBoxPara.u8CmdIdx    = MB_VDPLAYER_ACK_51ToAEON;
                                MailBoxPara.ParamCnt    = 2;
                                MailBoxPara.CMDType     = MB_CMD_TYPE_DEFAULT;
                                MailBoxPara.u8Param[0]  = MB_VDPLAYER_MPEG_SUBTITLE_GETQUEUEINFO;
                                MailBoxPara.u8Param[1]  = queuecount;

                                msAPI_MailBox_SendMsg();
                            }
                        }
                        break;
//****************************************************************************************
#endif
                }

                // Update u32VDPlayerLoopWdtTimer if receive Mailbox in init process, used for Init timeout checking
                if(enVDPlayerAckFlags&E_ACKFLG_WAIT_INIT)
                    u32VDPlayerLoopWdtTimer = msAPI_Timer_GetTime0();

            }
        }
        else
        {
            //printf("No Message\n");
        }
    }
}


static void _msAPI_APEngine_Obama_VDPlayer_Init(void)
{
    MBX_Result mbxResult;
    extern unsigned char Customer_info[];
    extern unsigned char Customer_hash[];
    bPlaying = FALSE;
    bResume = FALSE;
    bPause = FALSE;
    bStop = FALSE;
    bInit = FALSE;
    bSendMetadata = FALSE;

    //Init MailBox:
    //mbxResult = MSApi_MBX_Init();
    //if(E_MBX_SUCCESS != mbxResult)
    //{
    //    //Error Handling here...
    //    return;
    //}

    //Register Class:
    MSApi_MBX_UnRegisterMSG(E_MBX_CLASS_VDPLAYER);

    mbxResult = MSApi_MBX_RegisterMSG(E_MBX_CLASS_VDPLAYER, MM_COMMON_MBX_QUEUESIZE);
    if(E_MBX_SUCCESS != mbxResult)
    {
        //Error Handling here...
        printf("E_MBX_CLASS_VDPLAYER - MBX register msg error\n");
        return;
    }
    //MSApi_MBX_Enable(TRUE);

#if (ENABLE_MIU_1 == 0)
    MApi_XC_EnableFrameBufferLess(DISABLE);
#endif

#if (MEMORY_MAP <= MMAP_64MB )   //ATV_MM 64M
    // In signal memory model, MM will adjust scaler framebuffer for memory utilization.
    // We must restore the framebuffer setting to default here.
    #ifdef MSOS_TYPE_LINUX //OBA2
        MApi_XC_SetFrameBufferAddress(MApp_SystemGetTypeMem_adr(SCALER_DNR_BUF), MApp_SystemGetTypeMem_length(SCALER_DNR_BUF), MAIN_WINDOW);
    #else
        MApi_XC_SetFrameBufferAddress(((SCALER_DNR_BUF_MEMORY_TYPE & MIU1) ? (SCALER_DNR_BUF_ADR | MIU_INTERVAL) : (SCALER_DNR_BUF_ADR)), SCALER_DNR_BUF_LEN, MAIN_WINDOW);
    #endif
#endif


    //Clear Command in Queue
    U8 u8Count;
    U8 i;
    MBX_MSGQ_Status Mstatus;
    MBX_Msg MB_Message;
    MSApi_MBX_GetMsgQueueStatus(E_MBX_CLASS_VDPLAYER, &Mstatus);
    u8Count=(U8)Mstatus.u32NormalMsgCount;
    for (i=0; i<u8Count; i++)
    {
        MSApi_MBX_RecvMsg(E_MBX_CLASS_VDPLAYER, &MB_Message, 0,MBX_CHECK_NORMAL_MSG);
    }
#if ENABLE_SELECT_UART
    MApp_VDPlayer_UartSwitch(SELECT_UART_PORT);
#else
    MApp_VDPlayer_UartSwitch(E_UART_SWITCH_TO_COPROCESSOR);
#endif
    u32VdplayerShareMemAddr = VDPLAYER_SHAREMEM_ADDR;

    for (i = 0; i < E_SHAREMEM_NUM; i++)
    {
        _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(i, 0, u32VdplayerShareMemAddr);
    }

    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_NUM, E_SHAREMEM_MAGICKEY, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_PREVIEW_MODE, bVDPlayerPreview, u32VdplayerShareMemAddr);

    //streaming mode
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_NETWORKSTREAM_MODE, (U32)ENABLE, u32VdplayerShareMemAddr);

#if (ENABLE_MIU_1)
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_DATA_BUFF_ADDR, VDPLAYER_AEON_DATABUFF_ADDR, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_BITSREAM_BUFF_ADDR, ((VDPLAYER_BITSTREAM_BUFF_MEMORY_TYPE & MIU1) ? (VDPLAYER_BITSTREAM_BUFF_ADR | MIU_INTERVAL) : (VDPLAYER_BITSTREAM_BUFF_ADR)), u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_SUBTITLE_BITSREAM_BUFF_ADDR,
        ((VDPLAYER_SUBTITLE_BITSTREAM_BUFF_MEMORY_TYPE & MIU1) ? (VDPLAYER_SUBTITLE_BITSTREAM_BUFF_ADR | MIU_INTERVAL) : (VDPLAYER_SUBTITLE_BITSTREAM_BUFF_ADR)), u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_MAD_BUFF_ADDR, ((MAD_BASE_BUFFER_MEMORY_TYPE & MIU1) ? (MAD_SE_BUFFER_ADR | MIU_INTERVAL) : (MAD_SE_BUFFER_ADR)), u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_MVD3_FW_ADDR, ((VDEC_AEON_MEMORY_TYPE & MIU1) ? (VDEC_AEON_ADR | MIU_INTERVAL) : (VDEC_AEON_ADR))|SVD_USING_MIU1, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_MVD_FRAMEBUFFER_ADR, ((VDEC_FRAMEBUFFER_MEMORY_TYPE & MIU1) ? (VDEC_FRAMEBUFFER_ADR | MIU_INTERVAL) : (VDEC_FRAMEBUFFER_ADR))|SVD_USING_MIU1, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_MVD_FRAMEBUFFER_ADR_SD, ((VDEC_FRAMEBUFFER_MEMORY_TYPE & MIU1) ? (VDEC_FRAMEBUFFER_ADR | MIU_INTERVAL) : (VDEC_FRAMEBUFFER_ADR))|SVD_USING_MIU1, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_MVD_BITSTREAM_ADR, ((VDEC_BITSTREAM_MEMORY_TYPE & MIU1) ? (VDEC_BITSTREAM_ADR | MIU_INTERVAL) : (VDEC_BITSTREAM_ADR))|SVD_USING_MIU1, u32VdplayerShareMemAddr);
#else
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_DATA_BUFF_ADDR, VDPLAYER_AEON_DATABUFF_ADDR, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_BITSREAM_BUFF_ADDR, VDPLAYER_BITSTREAM_BUFF_ADR, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_SUBTITLE_BITSREAM_BUFF_ADDR, VDPLAYER_SUBTITLE_BITSTREAM_BUFF_ADR, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_MAD_BUFF_ADDR, MAD_BASE_BUFFER_ADR, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_MVD3_FW_ADDR, VDEC_AEON_ADR, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_MVD_FRAMEBUFFER_ADR, VDEC_FRAMEBUFFER_ADR, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_MVD_FRAMEBUFFER_ADR_SD, VDEC_FRAMEBUFFER_ADR, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_MVD_BITSTREAM_ADR, VDEC_BITSTREAM_ADR, u32VdplayerShareMemAddr); //share same sapce with VDPLAYER_BITSTREAM_BUFF_ADR??
#endif
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_DATA_BUFF_LEN, VDPLAYER_AEON_DATABUFF_SIZE, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_BITSREAM_BUFF_LEN, VDPLAYER_BITSTREAM_BUFF_LEN, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_SUBTITLE_BITSREAM_BUFF_LEN, VDPLAYER_SUBTITLE_BITSTREAM_BUFF_LEN, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_MAD_BUFF_LEN, MAD_BASE_BUFFER_LEN, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_MVD3_FW_LEN, VDEC_AEON_LEN, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_MVD_FRAMEBUFFER_LEN, VDEC_FRAMEBUFFER_LEN, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_MVD_BITSTREAM_LEN, VDEC_BITSTREAM_LEN, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_TSP_FW_ADDR, /*SECBUF_START_ADR*/u32SecbufAddr, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_TSP_FW_LEN, /*SECBUF_START_LEN*/u32SecbufSize, u32VdplayerShareMemAddr);

// If memory = 64MB, reSetting the VDEC_FRAMEBUFFER_LEN/VDEC_BITSTREAM_ADR/VDEC_BITSTREAM_LEN
#if (ENABLE_MIU_1 == 0)
    if(bVDPlayerPreview)
    {
        _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_MVD_FRAMEBUFFER_MODE_CHECKING, (U32)DISABLE, u32VdplayerShareMemAddr); //enable FBL checking
    }
    else
    {
        _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_MVD_FBL_MODE_THRESHOLD, (U32)ENABLE_FBL_MODE_THRESHOLD, u32VdplayerShareMemAddr); //set FBL threshold
        _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_MVD_FRAMEBUFFER_MODE_CHECKING, (U32)ENABLE, u32VdplayerShareMemAddr); //enable FBL checking
    }
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_FBL_FORCE_PROGRESS,(U32)DISABLE, u32VdplayerShareMemAddr);             //disable force progress mode
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_MVD_FRAMEBUFFER_LEN, VDEC_FRAMEBUFFER_LEN, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_MVD_BITSTREAM_ADR_SD, VDEC_BITSTREAM_SD_ADR, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_MVD_FRAMEBUFFER_LEN_SD, VDEC_FRAMEBUFFER_SD_LEN, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_MVD_BITSTREAM_LEN_SD, VDEC_BITSTREAM_SD_LEN, u32VdplayerShareMemAddr);
#else
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_MVD_FRAMEBUFFER_MODE_CHECKING, (U32)DISABLE, u32VdplayerShareMemAddr); //disable FBL checking
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_FBL_FORCE_PROGRESS,(U32)DISABLE, u32VdplayerShareMemAddr);             //disable force progress mode
#endif

    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_RESUME_PLAY_SEEKPOS_LOW, 0, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_RESUME_PLAY_SEEKPOS_HIGH, 0, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_RESUME_PLAY_SEEKPTS, 0, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_RESUME_AUDIO_TRACK_ID, 0, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_RESUME_SUBTITLE_TRACK_ID, 0, u32VdplayerShareMemAddr);
    _msAPI_APEngine_Obama_VDPlayer_SetShareMemData(E_SHAREMEM_RESUME_PROGRAM_IDX, 0, u32VdplayerShareMemAddr);

    for(i = 0; i < E_SHAREMEM_CUSTOMER_INFO_SIZE; i++)
    {
        U32 u32Info;
        u32Info = Customer_info[i*4] + (Customer_info[i*4 + 1] << 8) +
            (Customer_info[i*4 + 2] << 16) + (Customer_info[i*4 + 3] << 24);
        _msAPI_APEngine_Obama_VDPlayer_SetShareMemData((EN_VDP_SHAREMEMORY)(E_SHAREMEM_CUSTOMER_INFO + i), u32Info, u32VdplayerShareMemAddr);
    }

    for(i = 0; i < E_SHAREMEM_CUSTOMER_HASH_SIZE; i++)
    {
        U32 u32Hash;
        u32Hash = Customer_hash[i*4] + (Customer_hash[i*4 + 1] << 8) +
            (Customer_hash[i*4 + 2] << 16) + (Customer_hash[i*4 + 3] << 24);
        _msAPI_APEngine_Obama_VDPlayer_SetShareMemData((EN_VDP_SHAREMEMORY)(E_SHAREMEM_CUSTOMER_HASH + i), u32Hash, u32VdplayerShareMemAddr);
    }
#if 0//ENABLE_DRM
    MApp_VDPlayer_LoadDRMMemory();
#endif

#if ENABLE_WMDRMPD
    u32WMDRMPDShareMemAddr = 0x0;
#endif
    msAPI_Scaler_SetBlueScreen( ENABLE, E_XC_FREE_RUN_COLOR_BLACK, DEFAULT_SCREEN_UNMUTE_TIME, MAIN_WINDOW);
    msAPI_Scaler_SetScreenMute(E_SCREEN_MUTE_TEMPORARY, ENABLE, 300, MAIN_WINDOW); // DELAY_FOR_STABLE_CHANNELCHANGE);
    MDrv_MVOP_Enable(FALSE);
#if 1
    enVDPlayerAckFlags |= E_ACKFLG_WAIT_INIT;
    /*if (msAPI_MailBox_WaitReady())
    {
        MailBoxPara.u8CmdClass      = MB_CLASS_VDPLAYER_FS;
        MailBoxPara.u8CmdIdx        = MB_VDPLAYER_STOP;
        MailBoxPara.ParamCnt        = 0;
        MailBoxPara.CMDType         = MB_CMD_TYPE_DEFAULT;
        msAPI_MailBox_SendMsg();
    }
    MsOS_DelayTask(1000);*/
    //==> Send mail.
    APENGINE_MAILBOX_SEND(E_MBX_CLASS_VDPLAYER_FS
    /*Index*/           ,MB_VDPLAYER_INIT
    /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
    /*ParameterCount*/  ,4
    /*p1*/              ,(U8)(u32VdplayerShareMemAddr>>24)
    /*p2*/              ,(U8)(u32VdplayerShareMemAddr>>16)
    /*p3*/              ,(U8)(u32VdplayerShareMemAddr>>8)
    /*p4*/              ,(U8)(u32VdplayerShareMemAddr&0x000000FF)
    /*p5*/              ,0
    /*p6*/              ,0
    /*p7*/              ,0
    /*p8*/              ,0
    /*p9*/              ,0
    /*p10*/             ,0);
#else
    if (msAPI_MailBox_WaitReady())
    {
        MailBoxPara.u8CmdClass      = MB_CLASS_VDPLAYER_FS;
        MailBoxPara.u8CmdIdx        = MB_VDPLAYER_SET_PREVIEW_MODE;
        MailBoxPara.ParamCnt        = 0;
        MailBoxPara.CMDType         = MB_CMD_TYPE_DEFAULT;
        msAPI_MailBox_SendMsg();
    }
#endif
    // Waiting for Aeon Video Player initialization done

    //u32VDPlayerLoopWdtTimer = msAPI_Timer_GetTime0();
    u8VDPlayerInitResult = FALSE;
    enVDPlayerRet = EXIT_VDPLAYER_DECODING;
#if 0
    do
    {
        _msAPI_APEngine_Obama_VDPlayer_MailBoxHandler();
    }
    while((enVDPlayerAckFlags&E_ACKFLG_WAIT_INIT) &&
                (msAPI_Timer_DiffTimeFromNow(u32VDPlayerLoopWdtTimer)<u32VDPlayer_init_timeout));

    // if init failed, close file and disable VOP
    if(u8VDPlayerInitResult == FALSE)
    {
        _MApp_VDPlayer_Exit();
    }
    else
    {
#if (VDPLAYER_CHECK_COPROCESSOR_STATUS)
        // If init successed, start to check AEON status
        u32VDPlayerLoopWdtTimer = msAPI_Timer_GetTime0();
#endif
    }
#endif

//#if (ENABLE_INETRNAL_SUBTITLE == 0)
    //disable internal subtitle parsing
//    MApp_VDPlayer_SetSubtitleShow(E_SUBTITLE_STATE_COMMAND_DISABLE_ALL_SUBTITLE);
//#endif


#if ENABLE_SELECT_UART
    MApp_VDPlayer_UartSwitch(SELECT_UART_PORT);
#else
    MApp_VDPlayer_UartSwitch(E_UART_SWITCH_TO_HK);
#endif
}

BOOLEAN _msAPI_APEngine_Obama_VDPlayer_Pause(void)
{
    if (enVideoPlayerPlayingType>=VIDEO_PLAYER_PLAYING_TYPE_NUM)
    {
        return FALSE;
    }

    //==> Send mail.
    APENGINE_MAILBOX_SEND(E_MBX_CLASS_VDPLAYER_FS
    /*Index*/           ,MB_VDPLAYER_PAUSE
    /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
    /*ParameterCount*/  ,0
    /*p1*/              ,0
    /*p2*/              ,0
    /*p3*/              ,0
    /*p4*/              ,0
    /*p5*/              ,0
    /*p6*/              ,0
    /*p7*/              ,0
    /*p8*/              ,0
    /*p9*/              ,0
    /*p10*/             ,0);

    return TRUE;
}

BOOLEAN _msAPI_APEngine_Obama_VDPlayer_Resume(void)
{
    //==> Send mail.
    APENGINE_MAILBOX_SEND(E_MBX_CLASS_VDPLAYER_FS
    /*Index*/           ,MB_VDPLAYER_RESUME
    /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
    /*ParameterCount*/  ,0
    /*p1*/              ,0
    /*p2*/              ,0
    /*p3*/              ,0
    /*p4*/              ,0
    /*p5*/              ,0
    /*p6*/              ,0
    /*p7*/              ,0
    /*p8*/              ,0
    /*p9*/              ,0
    /*p10*/             ,0);

    return TRUE;
}

BOOLEAN _msAPI_APEngine_Obama_VDPlayer_Play(void)
{
    U32 m_u32PlayTimer;

    if (enVideoPlayerPlayingType>=VIDEO_PLAYER_PLAYING_TYPE_NUM)
    {
        return FALSE;
    }

#if 0//ENABLE_DRM
    if (enVideoPlayerPlayingType==VIDEO_PLAYER_PLAYING_TYPE_MPEG4)
    {
        if(MApp_VDPlayer_CheckDRMAutuorization() == TRUE)
            MApp_VDPlayer_SaveDRMMemory();
    }
#endif
    enVDPlayerAckFlags |= E_ACKFLG_WAIT_PLAY;
    //==> Send mail.
    APENGINE_MAILBOX_SEND(E_MBX_CLASS_VDPLAYER_FS
    /*Index*/           ,MB_VDPLAYER_PLAY
    /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
    /*ParameterCount*/  ,0
    /*p1*/              ,0
    /*p2*/              ,0
    /*p3*/              ,0
    /*p4*/              ,0
    /*p5*/              ,0
    /*p6*/              ,0
    /*p7*/              ,0
    /*p8*/              ,0
    /*p9*/              ,0
    /*p10*/             ,0);
#ifdef ENABLE_KTV
// KTV disable audio,so can't get message of removing E_ACKFLG_WAIT_PLAY
    if( g_InputSourceType == VIDEO_PLAYER_INPUT_SOURCE_KTV)
        enVDPlayerAckFlags &= (enumVDPlayerAckFlags)(~E_ACKFLG_WAIT_PLAY);
#endif

    m_u32PlayTimer = msAPI_Timer_GetTime0();
    while(enVDPlayerAckFlags&E_ACKFLG_WAIT_PLAY)
    {
       if (msAPI_Timer_DiffTimeFromNow(m_u32PlayTimer) > 10000)
       {
           return FALSE;
       }
       _msAPI_APEngine_Obama_VDPlayer_MailBoxHandler();
    }


    return TRUE;
}

void _msAPI_APEngine_Obama_VDPlayer_Stop(void)
{
    U32 m_u32StopTimer;

    //no need to un-freeze when ENABLE_MOVIE_PREVIEW_ALL_AND_1ST_FRAME is enabled
    if(!bVDPlayerPreview)
    {
        //fix PAUSE -> other play mode display abnormal.
        MApi_XC_FreezeImg(FALSE, MAIN_WINDOW);
    }

#if (ENABLE_MIU_1 == 0)
    //fix photo display abnormal after played TS.ts
    MApi_XC_EnableFrameBufferLess(DISABLE);
#endif

#if (MEMORY_MAP <= MMAP_64MB )   //ATV_MM 64M
    // In signal memory model, MM will adjust scaler framebuffer for memory utilization.
    // We must restore the framebuffer setting to default here.
    #ifdef MSOS_TYPE_LINUX //OBA2
        MApi_XC_SetFrameBufferAddress(MApp_SystemGetTypeMem_adr(SCALER_DNR_BUF), MApp_SystemGetTypeMem_length(SCALER_DNR_BUF), MAIN_WINDOW);
    #else
        MApi_XC_SetFrameBufferAddress(((SCALER_DNR_BUF_MEMORY_TYPE & MIU1) ? (SCALER_DNR_BUF_ADR | MIU_INTERVAL) : (SCALER_DNR_BUF_ADR)), SCALER_DNR_BUF_LEN, MAIN_WINDOW);
    #endif
#endif

    //if(bCoprocessorEnable==FALSE)
    //    return;

    enVDPlayerAckFlags |= E_ACKFLG_WAIT_STOP;
    //==> Send mail.
    APENGINE_MAILBOX_SEND(E_MBX_CLASS_VDPLAYER_FS
    /*Index*/           ,MB_VDPLAYER_STOP
    /*MsgType*/         ,E_MBX_MSG_TYPE_NORMAL
    /*ParameterCount*/  ,0
    /*p1*/              ,0
    /*p2*/              ,0
    /*p3*/              ,0
    /*p4*/              ,0
    /*p5*/              ,0
    /*p6*/              ,0
    /*p7*/              ,0
    /*p8*/              ,0
    /*p9*/              ,0
    /*p10*/             ,0);

    m_u32StopTimer = msAPI_Timer_GetTime0();
    while(enVDPlayerAckFlags&E_ACKFLG_WAIT_STOP)
    {
       if (msAPI_Timer_DiffTimeFromNow(m_u32StopTimer) > 2000)
       {
    #ifdef ENABLE_KTV
        if( g_InputSourceType != VIDEO_PLAYER_INPUT_SOURCE_KTV)
    #endif
        {
           #if defined(MIPS_CHAKRA) || defined(MSOS_TYPE_LINUX) || defined(__AEONR2__)
           msAPI_COPRO_Init(BIN_ID_CODE_VDPLAYER,((AEON_MEM_MEMORY_TYPE & MIU1) ? (AEON_MEM_ADR | MIU_INTERVAL) : (AEON_MEM_ADR)),AEON_MEM_LEN);
           #else
#if OBA2==0
           msAPI_COPRO_Init(BIN_ID_CODE_VDPLAYER,((BEON_MEM_MEMORY_TYPE & MIU1) ? (BEON_MEM_ADR | MIU_INTERVAL) : ( BEON_MEM_ADR)),BEON_MEM_LEN);
#endif
           #endif
           msAPI_Timer_Delayms(20);
           printf("Aeon abnormal, reset it\n");
        }
           break;
       }
       _msAPI_APEngine_Obama_VDPlayer_MailBoxHandler();
    }

    //MDrv_COPRO_Disable();
/*
    if(VDPlayer_file_id!=INVALID_FILE_HANDLE)
    {
        msAPI_FCtrl_FileClose(VDPlayer_file_id);
        VDPlayer_file_id = INVALID_FILE_HANDLE;
    }

    if(VDPlayer_Subtitle_file_id!=INVALID_FILE_HANDLE)
    {
        msAPI_FCtrl_FileClose(VDPlayer_Subtitle_file_id);
        VDPlayer_Subtitle_file_id = INVALID_FILE_HANDLE;
    }

    MApp_VDPlayer_FileHandleAssignTblInit();

#ifdef _VDPLAYER_DUMP_RAW_
    if(VDPlayer_dump_id!=INVALID_FILE_HANDLE)
    {
        msAPI_FCtrl_FileClose(VDPlayer_dump_id);
        VDPlayer_dump_id = INVALID_FILE_HANDLE;
    }
#endif // _VDPLAYER_DUMP_RAW_
*/

#if (ENABLE_SUBTITLE_TS)
#if (OBA2)
    if (enVideoPlayerPlayingType == VIDEO_PLAYER_PLAYING_TYPE_TS)
    {
        printf("\tMApp_VDPlayer_Stop\n");
        if(MApp_TS_Subtitle_Get_SubtitleOSDState())
        {
            MApp_TS_Subtitle_Switch2IP();
            MApp_TS_Subtitle_Exit();
            MApp_TS_Subtitle_Switch2OP();
        }

        u8DVBTSSubtitleServiceNum = 0;
        _bSubtitleShow_User = ENABLE;      // control by user.
        _bSubtitleShow_MW   = ENABLE;      // control by MW.
    }
#endif
#endif

    msAPI_MpegSP_Dinit();
    MDrv_MVOP_Enable(FALSE);

    if (enVDPlayerVideoType == VIDEO_MJPEG)
    {
        #if (ENABLE_MIU_1 == ENABLE)
        MDrv_MVOP_MiuSwitch(1);
        #endif
    }

/*#if ENABLE_WMDRMPD
    if (MApp_VDPlayer_WMDRMPD_IsProtected())
    {
        MApp_WMDRMPD_Finalize();
    }
#endif
*/
#if ENABLE_SELECT_UART
    MApp_VDPlayer_UartSwitch(SELECT_UART_PORT);
#else
    MApp_VDPlayer_UartSwitch(E_UART_SWITCH_TO_HK);
#endif
}


// Internal used if AEON hang up or abort initialization preview
void _msAPI_APEngine_Obama_VDPlayer_Exit(void)
{
    u32InitDisplayX = 0;
    u32InitDisplayY = 0;
    u32InitDisplayWidth = 0;
    u32InitDisplayHeight = 0;
    bPlaying = FALSE;
    bResume = FALSE;
    bPause = FALSE;
    bStop = FALSE;
    bInit = FALSE;
    bSendMetadata = FALSE;
    _msAPI_APEngine_Obama_VDPlayer_ClearShareMem();

    //bCoprocessorEnable = FALSE;
#if (ENABLE_MIU_1 == 0)
    MApi_XC_EnableFrameBufferLess(DISABLE);
#endif
#if (MEMORY_MAP <= MMAP_64MB )   //ATV_MM 64M
    // In signal memory model, MM will adjust scaler framebuffer for memory utilization.
    // We must restore the framebuffer setting to default here.
    #ifdef MSOS_TYPE_LINUX //OBA2
        MApi_XC_SetFrameBufferAddress(MApp_SystemGetTypeMem_adr(SCALER_DNR_BUF), MApp_SystemGetTypeMem_length(SCALER_DNR_BUF), MAIN_WINDOW);
    #else
        MApi_XC_SetFrameBufferAddress(((SCALER_DNR_BUF_MEMORY_TYPE & MIU1) ? (SCALER_DNR_BUF_ADR | MIU_INTERVAL) : (SCALER_DNR_BUF_ADR)), SCALER_DNR_BUF_LEN, MAIN_WINDOW);
    #endif
#endif
/*
#if (ENABLE_SUBTITLE_TS)
#if (OBA2)
    if (enVideoPlayerPlayingType == VIDEO_PLAYER_PLAYING_TYPE_TS)
    {
        //printf("\t_MApp_VDPlayer_Exit\n");
        if(MApp_TS_Subtitle_Get_SubtitleOSDState())
        {
            MApp_TS_Subtitle_Switch2IP();
            MApp_TS_Subtitle_Exit();
            MApp_TS_Subtitle_Switch2OP();
        }
        u8DVBTSSubtitleServiceNum = 0;
        _bSubtitleShow_User = ENABLE;      // control by user.
        _bSubtitleShow_MW   = ENABLE;      // control by MW.
    }
#endif
#endif

    msAPI_MpegSP_Dinit();
*/
    msAPI_Scaler_SetBlueScreen(ENABLE, E_XC_FREE_RUN_COLOR_BLACK, DEFAULT_SCREEN_UNMUTE_TIME, MAIN_WINDOW);
    MApi_XC_GenerateBlackVideo(ENABLE, MAIN_WINDOW);
    MDrv_MVOP_Enable(FALSE);

    if (enVDPlayerVideoType == VIDEO_MJPEG)
    {
        #if (ENABLE_MIU_1 == ENABLE)
        MDrv_MVOP_MiuSwitch(1);
        #endif
    }
/*
    if(VDPlayer_file_id!=INVALID_FILE_HANDLE)
    {
        msAPI_FCtrl_FileClose(VDPlayer_file_id);
        VDPlayer_file_id = INVALID_FILE_HANDLE;
    }

    if(VDPlayer_Subtitle_file_id!=INVALID_FILE_HANDLE)
    {
        msAPI_FCtrl_FileClose(VDPlayer_Subtitle_file_id);
        VDPlayer_Subtitle_file_id = INVALID_FILE_HANDLE;
    }

#ifdef _VDPLAYER_DUMP_RAW_
    if(VDPlayer_dump_id!=INVALID_FILE_HANDLE)
    {
        msAPI_FCtrl_FileClose(VDPlayer_dump_id);
        VDPlayer_dump_id = INVALID_FILE_HANDLE;
    }
#endif // _VDPLAYER_DUMP_RAW_

    if (MApp_MPlayer_QueryMoviePlayMode() == E_MPLAYER_MOVIE_PAUSE)
    {
        MApi_XC_FreezeImg(FALSE, MAIN_WINDOW);
    }
*/

    //Release MBX:
    MSApi_MBX_UnRegisterMSG(E_MBX_CLASS_VDPLAYER);
    //MSApi_MBX_Enable(FALSE);
    //MSApi_MBX_DeInit();

#if ENABLE_SELECT_UART
    MApp_VDPlayer_UartSwitch(SELECT_UART_PORT);
#else
    MApp_VDPlayer_UartSwitch(E_UART_SWITCH_TO_HK);
#endif
}
#endif

void msAPI_APEngine_Obama_Init(IRCallback irCB)
{
    // Init MAdp_SYS
    MAdp_SYS_Init();
    // Set it as the Nexus
    MAdp_SYS_SetNexus(TRUE);
    MAdp_SYS_SetNexusPID(getpid());

    // read the applications information
    MAdp_APMNG_Init();
    // Set the app.conf file
    MAdp_APMNG_SetCofigFile("/conf/app.conf");

    // Set the callback function for app executing
    MAdp_APMNG_SetExeCallback(msAPI_APEngine_Obama_ExecuteApp);

    pre_avtivated_ap = 0;

    if (MAdp_IR_IsEnableDaemon())
    {
        // execute ir daemon
        MAdp_APMNG_ExecuteApp("IR_DAEMON");
        // Init MAdp_IR
        MAdp_IR_Init();
        // Set IR callback function
        MAdp_IR_Set_Callback(irCB);
    }
    else
    {
        // Init MAdp_IR
        MAdp_IR_Init();
        // Set it as the master IR
        MAdp_IR_SetMasterPid(getpid());
        // Set IR callback function
        MAdp_IR_Set_Callback(irCB);
        // Set the key delay time
        MAdp_IR_SetDelayTime(800,100);
    }
    // init for zodiac d-bus
    MAdp_MSGCH_Init();
    MAdp_MSGCH_SetCallBack(MAdp_MSGCH_GetChannelIndex("ZODIAC"), msAPI_APEngine_Obama_Zodiac_ReceiveMsg);
#if (OBA2 == 1)
    /* removed: MAdp_MSGCH_SetCallBack(MAdp_MSGCH_GetChannelIndex("ZODIAC_VDPLAYER"), msAPI_APEngine_Obama_Zodiac_VDPlayer_ReceiveMsg);*/
    MAdp_MSGCH_SetCallBack(MAdp_MSGCH_GetChannelIndex("INPUT_SOURCE"), msAPI_APEngine_Obama_Zodiac_InputSource_ReceiveMsg);

#endif

#if ((OBA2 == 1) && (ENABLE_BABAO_PLAYER == ENABLE))
    msAPI_NPlayer_IPCInit();
#endif

}
#if (OBA2 == 1)
/* removed:
void msAPI_APEngine_Obama_Zodiac_VDPlayer_ProcessMailBox(void)
{
    if(!(enVDPlayerAckFlags&E_ACKFLG_WAIT_INIT) )
    {
        if(bPlaying)
        {
            _msAPI_APEngine_Obama_VDPlayer_Play();
            bPlaying = FALSE;
        }
        else if(bResume)
        {
            MApi_XC_FreezeImg(FALSE, MAIN_WINDOW);
            _msAPI_APEngine_Obama_VDPlayer_Resume();
            _msAPI_APEngine_Obama_VDPlayer_MailBoxHandler();
            _msAPI_APEngine_Obama_VDPlayer_SetTrickMode(MODE_NORMAL_PLAY, PLAY_SPEEDx1);
            bResume = FALSE;
            bInit = TRUE;
        }
        else if(bPause)
        {
            MApi_XC_FreezeImg(TRUE, MAIN_WINDOW);
            _msAPI_APEngine_Obama_VDPlayer_Pause();
            _msAPI_APEngine_Obama_VDPlayer_MailBoxHandler();
            bPause = FALSE;
            bInit = FALSE;
        }
        else if(bStop)
        {
            MApi_XC_FreezeImg(FALSE, MAIN_WINDOW);
            _msAPI_APEngine_Obama_VDPlayer_Stop();
            bStop = FALSE;
            bInit = FALSE;
        }
        else if(bSendMetadata)
        {
            //send metadata (resolution)
            U8 pu8InData[13];
            U32 u32HRes;
            U32 u32VRes;
            U32 u32TotalTime;
            //H Resolution
            u32HRes = _msAPI_APEngine_Obama_VDPlayer_GetInfo(E_VDPLAYER_INFO_DEMUX_H_SIZE);
            pu8InData[0] = E_OBAMA_ZODIAC_MSG_VIDEO_INFO;
            pu8InData[1] = (U8)((u32HRes&0xFF000000) >> 24);
            pu8InData[2] = (U8)((u32HRes&0x00FF0000) >> 16);
            pu8InData[3] = (U8)((u32HRes&0x0000FF00) >> 8);
            pu8InData[4] = (U8)(u32HRes&0x000000FF);
            //printf("u32HRes=%u\n",u32HRes);

            //V Resolution
            u32VRes = _msAPI_APEngine_Obama_VDPlayer_GetInfo(E_VDPLAYER_INFO_DEMUX_V_SIZE);
            pu8InData[5] = (U8)((u32VRes&0xFF000000) >> 24);
            pu8InData[6] = (U8)((u32VRes&0x00FF0000) >> 16);
            pu8InData[7] = (U8)((u32VRes&0x0000FF00) >> 8);
            pu8InData[8] = (U8)(u32VRes&0x000000FF);
            //printf("u32VRes=%u\n",u32VRes);

            //Total Time
            u32TotalTime = _msAPI_APEngine_Obama_VDPlayer_GetInfo(E_VDPLAYER_INFO_TOTAL_TIME);
            pu8InData[9] = (U8)((u32TotalTime&0xFF000000) >> 24);
            pu8InData[10] = (U8)((u32TotalTime&0x00FF0000) >> 16);
            pu8InData[11] = (U8)((u32TotalTime&0x0000FF00) >> 8);
            pu8InData[12] = (U8)(u32TotalTime&0x000000FF);
            //printf("u32TotalTime=%u\n",u32TotalTime);

            if (!_msAPI_APEngine_Obama_VDPlayer_SendMSG((U8*)pu8InData, sizeof(pu8InData), 0, 0))
            {
                printf("[D-Bus] Send Error\n");
            }
            bSendMetadata = FALSE;

        }
        else if(bInit)
        {
            MsOS_DelayTask(40); // force delay

            if((msAPI_Timer_GetTime0() - u32VDPlayerUpdateTimer) > 1000)
            {

                U8 pu8InData[5];
                pu8InData[0] = E_OBAMA_ZODIAC_MSG_SET_CURRENT_TIME;
                U32 u32CurrentTime = _msAPI_APEngine_Obama_VDPlayer_GetInfo(E_VDPLAYER_INFO_CUR_TIME);
                pu8InData[1] = (U8)((u32CurrentTime & 0xFF000000) >> 24);
                pu8InData[2] = (U8)((u32CurrentTime & 0x00FF0000) >> 16);
                pu8InData[3] = (U8)((u32CurrentTime & 0x0000FF00) >> 8);
                pu8InData[4] = (U8)(u32CurrentTime & 0x000000FF);

                if (_msAPI_APEngine_Obama_VDPlayer_SendMSG((U8*)pu8InData, sizeof(pu8InData), 0, 0))
                {
                    u32VDPlayerUpdateTimer = msAPI_Timer_GetTime0();
                }
            }

            _msAPI_APEngine_Obama_VDPlayer_MailBoxHandler();
        }
        return;
    }

    u32VDPlayerLoopWdtTimer = msAPI_Timer_GetTime0();
    do
    {
        _msAPI_APEngine_Obama_VDPlayer_MailBoxHandler();
    }
    while(enVDPlayerAckFlags&E_ACKFLG_WAIT_INIT && (msAPI_Timer_DiffTimeFromNow(u32VDPlayerLoopWdtTimer)<VDPLAYER_INIT_TIMEOUT));

    // if init failed, close file and disable VOP
    if(u8VDPlayerInitResult == FALSE)
    {
        //send init failed
        U8 pu8InData[1];
        pu8InData[0] = E_OBAMA_ZODIAC_MSG_INIT_ERROR;
        if (!_msAPI_APEngine_Obama_VDPlayer_SendMSG((U8*)pu8InData, sizeof(pu8InData), 0, 0))
        {
            printf("[D-Bus] Send Error\n");
        }

        Remove_enumVDPlayerAckFlags(enVDPlayerAckFlags, E_ACKFLG_WAIT_INIT);
        _msAPI_APEngine_Obama_VDPlayer_Exit();
    }
    else
    {
        bInit = TRUE;
        bSendMetadata = TRUE;
#if (VDPLAYER_CHECK_COPROCESSOR_STATUS)
        // If init successed, start to check AEON status
        u32VDPlayerLoopWdtTimer = msAPI_Timer_GetTime0();
#endif
    }
}

bool msAPI_APEngine_Obama_Zodiac_VDPlayer_ReceiveMsg(unsigned char * pu8Msg, unsigned short u16DataSize, unsigned char * pu8OutData, unsigned short u16OutDataSize)
{
    printf("msAPI_APEngine_Obama_Zodiac_VDPlayer_ReceiveMsg\n");
    bool bResult = false;

    if(u16DataSize <= 0)
    {
        return FALSE;
    }
    if(u16OutDataSize <= 0)
    {
        //do nothing
    }
    pu8OutData++; // for fix compile warning

    switch (pu8Msg[0])
    {
        case E_OBAMA_ZODIAC_MSG_TYPE_VDPLAYER_INIT:
            MApp_MPlayer_InitializeKernel();
            MApp_MPlayer_SetRepeatMode(E_MPLAYER_REPEAT_ALL);
            MApp_MPlayer_EnableNotify(E_MPLAYER_NOTIFY_ALL, TRUE);
            msAPI_COPRO_Init(BIN_ID_CODE_VDPLAYER,((AEON_MEM_MEMORY_TYPE & MIU1) ? (AEON_MEM_ADR | MIU_INTERVAL) : (AEON_MEM_ADR)),AEON_MEM_LEN);
            _msAPI_APEngine_Obama_VDPlayer_Init();
            bResult = TRUE;
            break;
        case E_OBAMA_ZODIAC_MSG_TYPE_VDPLAYER_STOP:
            printf("E_OBAMA_ZODIAC_MSG_TYPE_VDPLAYER_STOP\n");
            bStop = TRUE;
            bResult = TRUE;
            break;
        case E_OBAMA_ZODIAC_MSG_TYPE_VDPLAYER_PAUSE:
            printf("E_OBAMA_ZODIAC_MSG_TYPE_VDPLAYER_PAUSE\n");
            bPause = TRUE;
            bResult = TRUE;
            break;
        case E_OBAMA_ZODIAC_MSG_TYPE_VDPLAYER_RESUME:
            printf("E_OBAMA_ZODIAC_MSG_TYPE_VDPLAYER_RESUME\n");
            bResume = TRUE;
            bResult = TRUE;
            break;
        case E_OBAMA_ZODIAC_MSG_TYPE_VDPLAYER_EXIT:
            printf("E_OBAMA_ZODIAC_MSG_TYPE_VDPLAYER_EXIT\n");
            _msAPI_APEngine_Obama_VDPlayer_Exit();
            bPlaying = FALSE;
            bResume = FALSE;
            bPause = FALSE;
            bStop = FALSE;
            bInit = FALSE;
            bSendMetadata = FALSE;
            bResult = TRUE;
            break;
        case E_OBAMA_ZODIAC_MSG_TYPE_VDPLAYER_PLAY:
            bPlaying = TRUE;
            bResult = TRUE;
            break;
        case E_OBAMA_ZODIAC_MSG_TYPE_VDPLAYER_INIT_DISPLAY_SETUP:
        {
            U8 i;
            for(i = 1; i < 5; i++)
                u32InitDisplayX = (u32InitDisplayX << 8) | pu8Msg[i];
            for(i = 5; i < 9; i++)
                u32InitDisplayY = (u32InitDisplayY << 8) | pu8Msg[i];
            for(i = 9; i < 13; i++)
                u32InitDisplayWidth = (u32InitDisplayWidth << 8) | pu8Msg[i];
            for(i = 13; i < 17; i++)
                u32InitDisplayHeight = (u32InitDisplayHeight << 8) | pu8Msg[i];
            bResult = TRUE;
            break;
        }
        case E_OBAMA_ZODIAC_MSG_TYPE_VDPLAYER_SET_PLAY_MODE:
            if((U8)pu8Msg[1] <= MODE_FAST_BACKWARD
                && (U8)pu8Msg[2] <= PLAY_SPEED_MAX && (U8)pu8Msg[2] >= PLAY_SPEEDx1)
            {
                _msAPI_APEngine_Obama_VDPlayer_SetTrickMode((EN_PLAY_MODE)pu8Msg[1], (EN_PLAY_SPEED)pu8Msg[2]);
            }
            bResult = TRUE;
            break;
        default:
            printf("E_OBAMA_ZODIAC_VDPLAYER_MSG_TYPE (%u) not support\n",(U8)pu8Msg[0]);
            break;
    }
    return bResult;
}
*/

bool msAPI_APEngine_Obama_Zodiac_InputSource_ReceiveMsg(unsigned char * pu8Msg, unsigned short u16DataSize, unsigned char * pu8OutData, unsigned short u16OutDataSize)
{
    printf("msAPI_APEngine_Obama_Zodiac_InputSource_ReceiveMsg\n");
    bool bResult = false;

    if(u16DataSize <= 0)
    {
        return bResult;
    }
    if(u16OutDataSize <= 0)
    {
        //do nothing
    }
    pu8OutData++; // for fix compile warning

    switch (pu8Msg[0])
    {
        case E_OBAMA_ZODIAC_INTPUTSOURCE_CHANGE_AUDIO_TO_AP:
            //if(UI_INPUT_SOURCE_TYPE == UI_INPUT_SOURCE_ATV)
            if(IsDigitalSourceInUse() || IsAnalogSourceInUse())
            {
                MApp_InputSource_RecordSource(UI_INPUT_SOURCE_TYPE);
                MApp_InputSource_ChangeAudioSource(INPUT_SOURCE_STORAGE);
                MDrv_AUDIO_Close();
                {
                    MApi_AUDIO_SetADOutputMode(AD_OUT_BOTH);
                    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_PERMANENT_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                }
            }
            bResult = TRUE;
            break;
        case E_OBAMA_ZODIAC_INTPUTSOURCE_CHANGE_AV_TO_AP:
            //if(UI_INPUT_SOURCE_TYPE == UI_INPUT_SOURCE_ATV)
            if(IsDigitalSourceInUse() || IsAnalogSourceInUse())
            {
                MApp_InputSource_RecordSource(UI_INPUT_SOURCE_TYPE);
                UI_INPUT_SOURCE_TYPE = UI_INPUT_SOURCE_DMP;

                #ifndef ATSC_SYSTEM
                MApp_InputSource_ChangeInputSource(MAIN_WINDOW);
                #endif
                {
                    MApi_AUDIO_SetADOutputMode(AD_OUT_BOTH);
                    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_PERMANENT_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                }
            }
            bResult = TRUE;
            break;
        case E_OBAMA_ZODIAC_INTPUTSOURCE_CHANGE_AUDIO_TO_ATV:
            //if(UI_INPUT_SOURCE_TYPE == UI_INPUT_SOURCE_ATV)
            if(IsDigitalSourceInUse() || IsAnalogSourceInUse())
            {
                MDrv_AUDIO_Open();
                E_UI_INPUT_SOURCE recordUIInputSource = MApp_InputSource_GetRecordSource();
                INPUT_SOURCE_TYPE_t recordInputSource = MApp_InputSource_GetInputSourceType(recordUIInputSource);
                MApp_InputSource_ChangeAudioSource(recordInputSource);
                {
                    MApi_AUDIO_SetADOutputMode(AD_OUT_BOTH);
                    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_PERMANENT_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                }
            }
            bResult = TRUE;
            break;
        case E_OBAMA_ZODIAC_INTPUTSOURCE_CHANGE_AV_TO_ATV:
            //if(UI_INPUT_SOURCE_TYPE == UI_INPUT_SOURCE_ATV)
            if(IsDigitalSourceInUse() || IsAnalogSourceInUse())
            {
                MDrv_AUDIO_Open();
                MApp_InputSource_RestoreSource();
            }
            bResult = TRUE;
            break;

        case E_OBAMA_ZODIAC_INTPUTSOURCE_CHANGE_AV_TO_KTVAP:
           #ifdef AUDIO_SOURCE_KTV
                MApi_AUDIO_SetSystem(MSAPI_AUD_DVB2_KTV);
                MApi_AUDIO_SetSourceInfo(E_AUDIO_INFO_KTV_IN);
                msAPI_AUD_AdjustAudioFactor(E_ADJUST_CHANGE_AUDIOSOURCE, E_AUDIOSOURCE_MPEG, 0);
                MApi_AUDIO_InputSwitch(AUDIO_SOURCE_KTV, E_AUDIO_GROUP_MAIN);
           #endif

            bResult = TRUE;
            break;

        default:
            printf("E_OBAMA_ZODIAC_INTPUTSOURCE_MSG_TYPE (%u) not support\n",(U8)pu8Msg[0]);
            break;
    }
    return bResult;
}

#endif

//msg channel callback function
bool msAPI_APEngine_Obama_Zodiac_ReceiveMsg(unsigned char * pu8Msg, unsigned short u16DataSize, unsigned char * pu8OutData, unsigned short u16OutDataSize)
{
    //unsigned char * pu8Temp;
    //pid_t pid;
    //APP_KEY_DISPATCH_TYPE enType;
    bool bResult = false;

    if(u16DataSize <= 0)
    {
        return FALSE;
    }
    if(u16OutDataSize <= 0)
    {
        //do nothing
    }


    switch (pu8Msg[0])
    {
        case E_OBAMA_ZODIAC_MSG_TYPE_DIRECTOUTPUT_CREATE:
            if (getpid() == MAdp_SYS_GetNexusPID())
            {
                U16 u16Width;
                U16 u16Height;
                U32 u32BuffAddr;
                U16 u16DisplayWidth;
                U16 u16DisplayHeight;
                memcpy(&u16Width, &pu8Msg[1], sizeof(U16));
                memcpy(&u16Height, &pu8Msg[3], sizeof(U16));
                memcpy(&u32BuffAddr, &pu8Msg[5], sizeof(U32));
                memcpy(&u16DisplayWidth,&pu8Msg[9], sizeof(U16));
                memcpy(&u16DisplayHeight,&pu8Msg[11], sizeof(U16));
                //printf("w=%d,h=%d,dw=%d,dh=%d,buffAddr=%d\n",u16Width,u16Height,u16DisplayWidth,u16DisplayHeight,u32BuffAddr);
                printf("###EDDIE: u16Width=0x%x u16Height=0x%x u32BuffAddr=0x%x u16DisplayWidth=0x%x  u16DisplayHeight=0x%x \n",
                   u16Width,u16Height,u32BuffAddr,u16DisplayWidth,u16DisplayHeight);
                _msAPI_APEngine_Obama_VOP_Init(u16Width,u16Height,u32BuffAddr,u16DisplayWidth,u16DisplayHeight);
                bResult = TRUE;
            }
            break;
        case E_OBAMA_ZODIAC_MSG_TYPE_DIRECTOUTPUT_SHOW:
            if (getpid() == MAdp_SYS_GetNexusPID())
            {
                _msAPI_APEngine_Obama_VOP_SetBlueScreen(FALSE);
                bResult = TRUE;
            }
            break;
        case E_OBAMA_ZODIAC_MSG_TYPE_DIRECTOUTPUT_HIDE:
            if (getpid() == MAdp_SYS_GetNexusPID())
            {
                _msAPI_APEngine_Obama_VOP_SetBlueScreen(TRUE);
                bResult = TRUE;
            }
            break;
        case E_OBAMA_ZODIAC_MSG_TYPE_DIRECTOUTPUT_MOVE:
            if (getpid() == MAdp_SYS_GetNexusPID())
            {
                U16 u16X;
                U16 u16Y;
                U16 u16Width;
                U16 u16Height;
                U16 u16DisplayWidth;
                memcpy(&u16X, &pu8Msg[1], sizeof(U16));
                memcpy(&u16Y, &pu8Msg[3], sizeof(U16));
                memcpy(&u16Width, &pu8Msg[5], sizeof(U16));
                memcpy(&u16Height, &pu8Msg[7], sizeof(U16));
                memcpy(&u16DisplayWidth, &pu8Msg[9], sizeof(U16));
                _msAPI_APEngine_Obama_VOP_Move(u16X,u16Y,u16Width,u16Height,u16DisplayWidth);
                bResult = TRUE;
            }
            break;
        case E_OBAMA_ZODIAC_MSG_TYPE_DIRECTOUTPUT_DESTROY:
            if (getpid() == MAdp_SYS_GetNexusPID())
            {
                _msAPI_APEngine_Obama_VOP_Destroy();
                bResult = TRUE;
            }
            break;
        case E_OBAMA_ZODIAC_MSG_TYPE_MEDIA_MUTE:
            if(pu8Msg[1] == TRUE)
            {
                msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYUSER_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
            }
            else
            {
                msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYUSER_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
            }
            break;
        case E_OBAMA_ZODIAC_MSG_TYPE_IS_CHIPTYPE_T3:

#if  (CHIP_FAMILY_TYPE == CHIP_FAMILY_S7 ) //============T3 only=============
            pu8OutData[0] = 1;
#else
            pu8OutData[0] = 0;
#endif
            bResult = TRUE;
            break;

		case E_OBAMA_ZODIAC_MSG_TYPE_SWITCH_KTV:
			MApp_InputSource_ChangeAudioSource(INPUT_SOURCE_KTV);
			break;

        default:
            printf("No such kind of zodiac msg type\n");
            break;
    }

    pu8OutData++; // avoid compile warning

    return bResult;
}

BOOLEAN msAPI_APEngine_Obama_ExecuteAppByIndex(U8 u8Index)
{
    APP_INFO stAppInfo;
    if (MAdp_APMNG_GetApInfoByIndex(u8Index, &stAppInfo))
    {
        return msAPI_APEngine_Obama_ExecuteApp(stAppInfo.name);
    }

    return FALSE;
}

BOOLEAN msAPI_APEngine_Obama_StopAppByIndex(U8 u8Index)
{
    APP_INFO stAppInfo;
    if (MAdp_APMNG_GetApInfoByIndex(u8Index, &stAppInfo))
    {
        return msAPI_APEngine_Obama_StopApp(stAppInfo.name);
    }

    return FALSE;
}

BOOLEAN msAPI_APEngine_Obama_ExecuteApp(char * pu8AppName)
{
    APP_INFO stAppInfo;
    pid_t cur_activated_ap;
    BOOLEAN bResult = FALSE;

    if (MAdp_APMNG_GetApInfoByName(pu8AppName, &stAppInfo))
    {
        // stop lower priority app
        MAdp_APMNG_TerminateLowerPriority(stAppInfo.u8Priority);

        // suspend current activated app
        cur_activated_ap = MAdp_APMNG_GetActivatedAppPid();
        if (cur_activated_ap != 0)
        {
            if (MAdp_APMNG_SuspendAppByPid(cur_activated_ap))
            {
                pre_avtivated_ap = cur_activated_ap;
            }
        }

        // execute the app
        printf("MAdp_APMNG_ExecuteApp(%s)\n", pu8AppName);
        bResult = MAdp_APMNG_ExecuteApp(pu8AppName);
        bMuteFlag = stAppInfo.bMute;
        bAPRegisting = TRUE;

        if (stAppInfo.bAudio)
            MDrv_AUDIO_Close();
    }

    return bResult;
}

BOOLEAN msAPI_APEngine_Obama_ExecuteApp2(char * pu8AppName, char * pu8args)
{
    APP_INFO stAppInfo;
    pid_t cur_activated_ap;
    BOOLEAN bResult = FALSE;

    if (MAdp_APMNG_GetApInfoByName(pu8AppName, &stAppInfo))
    {
        // stop lower priority app
        MAdp_APMNG_TerminateLowerPriority(stAppInfo.u8Priority);

        // suspend current activated app
        cur_activated_ap = MAdp_APMNG_GetActivatedAppPid();
        if (cur_activated_ap != 0)
        {
            if (MAdp_APMNG_SuspendAppByPid(cur_activated_ap))
            {
                pre_avtivated_ap = cur_activated_ap;
            }
        }

        char *pAppName = NULL;
        unsigned int u16NameLen = strlen(pu8AppName)+ strlen(pu8args)+2;
        pAppName = malloc(u16NameLen);
        if (pAppName == NULL)
        {
            ASSERT(pAppName);
            return FALSE;
        }
        snprintf(pAppName, u16NameLen ,"%s %s", pu8AppName, pu8args);
        printf("MAdp_APMNG_ExecuteApp(%s)\n", pAppName);
        // execute the app
        bResult = MAdp_APMNG_ExecuteApp(pAppName);
        free(pAppName);
        bMuteFlag = stAppInfo.bMute;
        bAPRegisting = TRUE;

        if (stAppInfo.bAudio)
            MDrv_AUDIO_Close();
    }

    return bResult;
}




BOOLEAN msAPI_APEngine_Obama_MuteFlag(void)
{
    BOOLEAN bRetValue;

    bRetValue = bMuteFlag;
    bMuteFlag = 0;
    return bRetValue;
}

BOOLEAN msAPI_APEngine_Obama_ApRegstingFlag(void)
{
    BOOLEAN bRetValue;

    bRetValue = bAPRegisting;
    return bRetValue;
}

void msAPI_APEngine_Obama_StopApRegsting(void)
{
    bAPRegisting=0;
}


BOOLEAN msAPI_APEngine_Obama_StopApp(char * pu8AppName)
{
    BOOLEAN bResult = FALSE;
    if (MAdp_APMNG_TerminateApp(pu8AppName))
    {
        // resuem the previous app
        if (pre_avtivated_ap != 0)
        {
            if (MAdp_APMNG_ResumeAppByPid(pre_avtivated_ap))
                pre_avtivated_ap = 0;

            bResult = TRUE;
        }
    }

    return bResult;
}

BOOLEAN msAPI_APEngine_Obama_StopCurrentApp(void)
{
    BOOLEAN bResult = FALSE;
    pid_t pid;
    pid = MAdp_APMNG_GetActivatedAppPid();
    if (MAdp_APMNG_TerminateAppByPid(pid))
    {
        // resuem the previous app
        if (pre_avtivated_ap != 0)
        {
            if (MAdp_APMNG_ResumeAppByPid(pre_avtivated_ap))
                pre_avtivated_ap = 0;

            bResult = TRUE;
        }
    }

    return bResult;
}

void msAPI_APEngine_Obama_TransmitKey(U8 u8Key)
{
    // send key to the current activated app

    pid_t cur_activated_ap;
    cur_activated_ap = MAdp_APMNG_GetActivatedAppPid();
    if(cur_activated_ap != 0)  // application is running
    {
        printf("Send key code to pid: %d\n", cur_activated_ap);
        MAdp_IR_SendKey(u8Key, 0, cur_activated_ap);
    }
}

E_OBAMA_APP_TYPE msAPI_APEngine_Obama_CurrentAppType(void)
{
    E_OBAMA_APP_TYPE enApType = E_OBAMA_APP_TYPE_TV_NONE;
    APP_KEY_DISPATCH_TYPE enKeyType;
    enKeyType = MAdp_APMNG_GetCurrentKeyType();

    switch (enKeyType)
    {
        case KEY_DISPATCH_NONE:
            enApType = E_OBAMA_APP_TYPE_TV_NONE;
            break;
        case KEY_DISPATCH_APP:
            enApType = E_OBAMA_APP_TYPE_ISOLATED_APP;
            break;
        case KEY_DISPATCH_TV_APP:
            enApType = E_OBAMA_APP_TYPE_TV_APP;
            break;
    }

    return enApType;
}
#endif
#endif //#if (ENABLE_CAPE || OBA2)
#undef _MSAPI_APENGINE_C_

