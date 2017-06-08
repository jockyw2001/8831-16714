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
#define  MSAPI_DEMUX_C

////////////////////////////////////////////////////////////////////////////////
///
/// @file msAPI_demux.c
/// @author MStar Semiconductor Inc.
/// @brief Demux API wrapper
///
////////////////////////////////////////////////////////////////////////////////


/******************************************************************************/
/*                              Header Files                                  */
/******************************************************************************/
// C Library
//#include <stdlib.h>
#include <string.h>
//#include <stdio.h>
// Global
#include "MsCommon.h"
#include "sysinfo.h"
#include "debug.h"
// Driver Layer
#include "SysInit.h"

#include "msAPI_MMap.h"

// API Layer
#include "msAPI_Timer.h"
#include "msAPI_demux.h"
#if (ENABLE_TTX ==1)
#include "msAPI_TTX.h"
#endif

#if ENABLE_CI
#include "msAPI_CI.h"
#endif
// MW Layer


/******************************************************************************/
/*                                   Define                                   */
/******************************************************************************/


/******************************************************************************/
/*                                   Macro                                    */
/******************************************************************************/
#if (ENABLE_NEW_DMX_INTERFACE)
#define DMX_DB(y)   //y
#endif


#if(CSA_ENABLE == 1)
#include "msAPI_MailBox.h"
typedef enum
{
    MB_CSA_FILTER_START,
    MB_CSA_FILTER_STOP,
    MB_CSA_FILTER_SET_EVEN_KEY,
    MB_CSA_FILTER_SET_ODD_KEY,
    MB_CSA_SEC_READ_ADDRESS,
    MB_CSA_SEC_WRITE_ADDRESS,
    MB_CSA_FILTER_STOP_FINISH,
    MB_CSA_FILTER_SUCCESS,
} MB_CSA_CLASS;
U8 even_key[8] = {0x92, 0xFB, 0x05, 0x92, 0xEA, 0x32, 0xE7, 0x03};
U8 odd_key[8] = {0x92, 0xFB, 0x05, 0x92, 0xEA, 0x32, 0xE7, 0x03};
#define E_MBX_CLASS_CSA E_MBX_CLASS_LZSS
#define CSA_MSA_QUEUE_SIZE 10
static BOOLEAN _bCSA_Filter_ON=FALSE;
static BOOLEAN _bCSA_ON=FALSE;
static U8 _u8FilterGroup=0;
static U32 _u32SecWriteAddress,_u32SecReadAddress,_u32SecStartAddress,_u32SecEndAddress;
static void _HandleCSAMSG(MBX_Msg *pMsg, MS_BOOL *pbAddToQueue);
#endif

#define DEMUX_SUBTITLE_OFFSET  0x10000

/******************************************************************************/
/*                                   Enum                                     */
/******************************************************************************/


/******************************************************************************/
/*                                 Global Var                                 */
/******************************************************************************/


/******************************************************************************/
/*                                 Local Var                                  */
/******************************************************************************/


/******************************************************************************/
/*                                 Functions                                  */
/******************************************************************************/
#if (MSB123x_T2MI_DJB_RST_EN == 1)
extern BOOLEAN MSB123x_DJB_RST(void);
#endif
//------------------------------------------------------------------------------
/// Demux EIT parsing function for parsing EIT P/F table of current service channel
/// @param  pu8Section \b IN received section data
/// @return None
//------------------------------------------------------------------------------

#if (ENABLE_NEW_DMX_INTERFACE)

extern U32 u32Sec1KFilterBufferSize;
extern U32 u32Sec4KFilterBufferSize;
extern U32 u32Sec4KEitFilterBufferSize;
typedef struct MApp_Dmx_Ts_Filter
{
    U8 u8FltID;
    U8 bUsed;
    U16 u16TimeoutMilliSec;
    U32 u32TimerEnd;
    void (*pfNotify)(U8 u8FID, DMX_EVENT enEvent);
    U32 u32SectionFltType;
} _MApp_Dmx_Ts_Filter;
static _MApp_Dmx_Ts_Filter _DmxTsFilter[MSAPI_DMX_MAX_FILTER_NUMBER];
static U8 _u8PATFliterID=DMX_DMXID_NULL;//add for PAT status check
static DMX_FILTER_STATUS _MApp_Dmx_HaveFreeFilter(void)
{
    U8 i,u8UsedFilter=0;;
    for (i = 0; i < MSAPI_DMX_MAX_FILTER_NUMBER; i++)
    {
        if (_DmxTsFilter[i].bUsed)
        {
            u8UsedFilter++;
        }
    }
    if(u8UsedFilter >= MSAPI_DMX_USABLE_FILTER_NUMBER)
    {
        //printf("no free filter max %d\n",MSAPI_DMX_USABLE_FILTER_NUMBER);
        return DMX_FILTER_STATUS_ERROR;
    }
    return DMX_FILTER_STATUS_OK;
}

DMX_FILTER_STATUS msAPI_DMX_Close(U8 u8FltID)
{
    U8 i;
    for (i = 0; i < MSAPI_DMX_MAX_FILTER_NUMBER; i++)
    {
        if (_DmxTsFilter[i].bUsed && _DmxTsFilter[i].u8FltID == u8FltID)
        {
            _DmxTsFilter[i].bUsed=FALSE;
            _DmxTsFilter[i].pfNotify=NULL;
#if(CSA_ENABLE == 1)
            if(u8FltID == CSA_FILTER_ID)
            {
                MBX_Result mbxResult;
                MBX_Msg mbxMsg;
                MBX_MSGQ_Status MsgQueueStatus;
                U32 u32CurrentMsgNumber = 0;
                U8 wait=0;
                mbxMsg.eMsgType=E_MBX_MSG_TYPE_NORMAL;
                mbxMsg.u8MsgClass=E_MBX_CLASS_CSA;
                mbxMsg.u8Index=MB_CSA_FILTER_STOP;
                mbxMsg.u8ParameterCount=0;
                mbxResult = MSApi_MBX_SendMsg(&mbxMsg);
                if(mbxResult != E_MBX_SUCCESS)
                {
                    printf("%s...%d error\n",__FUNCTION__,__LINE__);
                }
                while(wait++ < 100)
                {
                    msAPI_Timer_Delayms(1);
                    mbxResult = MSApi_MBX_GetMsgQueueStatus(E_MBX_CLASS_CSA, &MsgQueueStatus);
                    if(MsgQueueStatus.status & MBX_STATUS_QUEUE_HAS_INSTANT_MSG)
                        u32CurrentMsgNumber = MsgQueueStatus.u32InstantMsgCount;
                    else if(MsgQueueStatus.status & MBX_STATUS_QUEUE_HAS_NORMAL_MSG)
                        u32CurrentMsgNumber = MsgQueueStatus.u32NormalMsgCount;
                    if(u32CurrentMsgNumber>0)
                    {
                        if(MSApi_MBX_RecvMsg(E_MBX_CLASS_CSA, &mbxMsg, 0, MBX_CHECK_NORMAL_MSG) == E_MBX_SUCCESS)
                        {
                            if(((U8)mbxMsg.u8Index) == MB_CSA_FILTER_STOP_FINISH)
                            {
                                printf("close CSA success--\n");
                                break;
                            }
                        }
                    }
                }
                if(wait>=100)printf("%s ..%d close CSA filter failed\n",__FUNCTION__,__LINE__);
                MSApi_MBX_UnRegisterMSG(E_MBX_CLASS_CSA);
                _bCSA_Filter_ON=FALSE;
                return DMX_FILTER_STATUS_OK;
            }
#endif
            if(_u8PATFliterID == u8FltID)//add for PAT status check
            {
                _u8PATFliterID = DMX_DMXID_NULL;
            }
            MApi_DMX_Close(u8FltID);
            //printf("msAPI_DMX_Close %d\n",u8FltID);
            #if ENABLE_CI && ENABLE_CI_PLUS
            msAPI_CI_CC_SetFID(u8FltID, FALSE);
            #endif
            return DMX_FILTER_STATUS_OK;
        }
    }
    return DMX_FILTER_STATUS_ERROR;
}


DMX_FILTER_STATUS msAPI_DMX_Stop(U8 u8FltID)
{
    U8 i;

#if(CSA_ENABLE == 1)
    if(u8FltID == CSA_FILTER_ID)
    {
        return DMX_FILTER_STATUS_OK;
    }
#endif
    for (i = 0; i < MSAPI_DMX_MAX_FILTER_NUMBER; i++)
    {
        if (_DmxTsFilter[i].bUsed && _DmxTsFilter[i].u8FltID == u8FltID)
        {
            MApi_DMX_Stop(u8FltID);
            //printf("MApi_DMX_Stop %d\n",u8FltID);
            return DMX_FILTER_STATUS_OK;
        }
    }
    return DMX_FILTER_STATUS_ERROR;
}

DMX_FILTER_STATUS msAPI_DMX_Reset(U8 u8FltID)
{
    U8 i;
    for (i = 0; i < MSAPI_DMX_MAX_FILTER_NUMBER; i++)
    {
        if (_DmxTsFilter[i].bUsed && _DmxTsFilter[i].u8FltID == u8FltID)
        {
            MApi_DMX_SectReset(u8FltID);
            return DMX_FILTER_STATUS_OK;
        }
    }
    return DMX_FILTER_STATUS_ERROR;
}
DMX_FILTER_STATUS msAPI_DMX_Start(U8 u8FltID)
{
    U8 i;
    for (i = 0; i < MSAPI_DMX_MAX_FILTER_NUMBER; i++)
    {
        if (_DmxTsFilter[i].bUsed && _DmxTsFilter[i].u8FltID == u8FltID)
        {
            MApi_DMX_Start(u8FltID);
            if(_DmxTsFilter[i].u16TimeoutMilliSec != MSAPI_DMX_TIMEOUT_INFINITE)
            {
                _DmxTsFilter[i].u32TimerEnd=msAPI_Timer_GetTime0()+_DmxTsFilter[i].u16TimeoutMilliSec;
                //printf("msAPI_DMX_Start fid %d %d %d\n",u8FltID,msAPI_Timer_GetTime0(),_DmxTsFilter[i].u32TimerEnd);
            }
            //printf("msAPI_DMX_Start fid %d %d %d\n",u8FltID,msAPI_Timer_GetTime0(),_DmxTsFilter[i].u32TimerEnd);
            return DMX_FILTER_STATUS_OK;
        }
    }
    return DMX_FILTER_STATUS_ERROR;
}
DMX_FILTER_STATUS msAPI_DMX_Pid(U8 u8FltID, U16* pu16Pid, BOOL bSet)
{
    U8 i;
    for (i = 0; i < MSAPI_DMX_MAX_FILTER_NUMBER; i++)
    {
        if (_DmxTsFilter[i].bUsed && _DmxTsFilter[i].u8FltID == u8FltID)
        {
            MApi_DMX_Pid(u8FltID,pu16Pid,bSet);
            //printf("msAPI_DMX_Pid fid %d %d\n",u8FltID,*pu16Pid);
            return DMX_FILTER_STATUS_OK;
        }
    }
    return DMX_FILTER_STATUS_ERROR;
}
DMX_FILTER_STATUS msAPI_DMX_Proc(U8 u8DmxId)
{
    U8 i,u8Index;
    DMX_FILTER_STATUS eResult=DMX_FILTER_STATUS_ERROR;
    DMX_EVENT eEvent = DMX_EVENT_DATA_READY;
    static U8 u8StartFltIndex = 0;
    if(MSAPI_DMX_INVALID_FLT_ID != u8DmxId)
    {
        eResult=MApi_DMX_Proc(u8DmxId, &eEvent);
    }
    else
    {
        for(i=u8StartFltIndex;i<MSAPI_DMX_MAX_FILTER_NUMBER+u8StartFltIndex;i++)
        {
            if (i < MSAPI_DMX_MAX_FILTER_NUMBER)
            {
                u8Index = i;
            }
            else
            {
                u8Index = i - MSAPI_DMX_MAX_FILTER_NUMBER;
            }
            if(_DmxTsFilter[u8Index].bUsed &&_DmxTsFilter[u8Index].pfNotify &&
               _DmxTsFilter[u8Index].u32SectionFltType!= MSAPI_DMX_FILTER_TYPE_OAD_MONITOR &&
               _DmxTsFilter[u8Index].u32SectionFltType!= MSAPI_DMX_FILTER_TYPE_OAD_DOWNLOAD )
            {
                u8DmxId = _DmxTsFilter[u8Index].u8FltID;
#if(CSA_ENABLE == 1)
                if(u8DmxId == CSA_FILTER_ID)
                {
                    if(_u32SecWriteAddress != _u32SecReadAddress)
                    {
                        //printf("read %x write %x\n",_u32SecReadAddress,_u32SecWriteAddress);
                        eResult=DMX_FILTER_STATUS_OK;
                        eEvent=DMX_EVENT_DATA_READY;
                    }
                }
                else
#endif
                {
                    eResult=MApi_DMX_Proc(u8DmxId, &eEvent);
                }
                //printf("msAPI_DMX_Pid %d (%d) result %d\n",u8Index,u8DmxId,eResult);
                if(eResult == DMX_FILTER_STATUS_OK)
                {
                    u8StartFltIndex=u8Index+1;
                    break;
                }
            }
        }
    }
    if(eResult == DMX_FILTER_STATUS_OK)
    {
        for(i=0;i<MSAPI_DMX_MAX_FILTER_NUMBER;i++)
        {
            if(_DmxTsFilter[i].bUsed && (_DmxTsFilter[i].u8FltID == u8DmxId))
            {
                if(_DmxTsFilter[i].u16TimeoutMilliSec != MSAPI_DMX_TIMEOUT_INFINITE)
                {
                    _DmxTsFilter[i].u32TimerEnd=msAPI_Timer_GetTime0()+_DmxTsFilter[i].u16TimeoutMilliSec;
                }
                if(_DmxTsFilter[i].pfNotify)
                {
                    _DmxTsFilter[i].pfNotify(_DmxTsFilter[i].u8FltID, eEvent);
                }
                break;
            }
        }
    }
    if(eResult != DMX_FILTER_STATUS_OK)
    {
        for(i=0;i<(MSAPI_DMX_SEC1K_FILTER_NUMBER+MSAPI_DMX_SEC4K_FILTER_NUMBER+MSAPI_DMX_SEC4K_EIT_FILTER_NUMBER);i++)
        {
            if(_DmxTsFilter[i].bUsed && (_DmxTsFilter[i].u16TimeoutMilliSec != MSAPI_DMX_TIMEOUT_INFINITE))
            {
                if ((msAPI_Timer_GetTime0() > _DmxTsFilter[i].u32TimerEnd) &&
                    ((msAPI_Timer_GetTime0()- _DmxTsFilter[i].u32TimerEnd) < 0xF0000000))
                {
                    //U16 u16Pid;
                    //MApi_DMX_Pid(_DmxTsFilter[i].u8FltID,&u16Pid,FALSE);
                    //printf("time out fid %d pid %d %d\n",_DmxTsFilter[i].u8FltID,u16Pid,_DmxTsFilter[i].u32TimerEnd);
                    if(_DmxTsFilter[i].pfNotify)
                    {
                        _DmxTsFilter[i].pfNotify(_DmxTsFilter[i].u8FltID,(DMX_EVENT)MSAPI_DMX_FILTER_STATUS_TIMEOUT);
                    }
                    break;
                }
                else if(_u8PATFliterID == _DmxTsFilter[i].u8FltID)//add for PAT status check
                {
                    if ((msAPI_Timer_GetTime0()+1000) > _DmxTsFilter[i].u32TimerEnd)//1 second check
                    {
                        _u8PATFliterID = DMX_DMXID_NULL;//only do one time
                        //send MSB123x_T2MI_DJB_RST_EN
					#if (MSB123x_T2MI_DJB_RST_EN == 1)
						if ( MSB123x_DJB_RST() == FALSE)
						{
							printf("MSB123x_DJB_RST fail....\n");
						}
					#endif
                    }
                }
            }
        }
    }
    return eResult;
}
DMX_FILTER_STATUS msAPI_DMX_StartFilter(U16 u16Pid, U32 u32FltType, U8 *pu8FID)
{
    U8 i;
    DMX_FILTER_TYPE enFtTypeNew=DMX_FILTER_TYPE_VIDEO;
    DMX_Flt_info FltInfo;
    DMX_FILTER_TYPE eFilterType= DMX_FILTER_SOURCE_TYPE_LIVE;

    //printf("msAPI_DMX_StartFilter(pid=0x%X, u32FltType=0x%X, *pu8FID=%u )\n",u16Pid, u32FltType, *pu8FID);

    if (pu8FID == NULL)
    {
        return DMX_FILTER_STATUS_ERROR;
    }

    if (u16Pid >= MSAPI_DMX_INVALID_PID)
    {
        return DMX_FILTER_STATUS_ERROR;
    }
    if((u32FltType & MSAPI_DMX_FILTER_SOURCE_TYPE_MASK) == MSAPI_DMX_FILTER_SOURCE_TYPE_FILE)
    {
        eFilterType=DMX_FILTER_SOURCE_TYPE_FILE;
    }
    u32FltType=(u32FltType&~MSAPI_DMX_FILTER_SOURCE_TYPE_MASK);
    if ((u32FltType == MSAPI_DMX_FILTER_TYPE_PES            ) ||
        (u32FltType == MSAPI_DMX_FILTER_TYPE_SUBTITLE       ) ||
        (u32FltType == MSAPI_DMX_FILTER_TYPE_SECTION_1K     ) ||
        (u32FltType == MSAPI_DMX_FILTER_TYPE_SECTION_4K     ) ||
        (u32FltType == MSAPI_DMX_FILTER_TYPE_SECTION_VERSION) ||
        (u32FltType == MSAPI_DMX_FILTER_TYPE_SECTION_CRC    ) ||
        (u32FltType == MSAPI_DMX_FILTER_TYPE_OAD_MONITOR)     ||
        (u32FltType == MSAPI_DMX_FILTER_TYPE_OAD_DOWNLOAD) ||
        (u32FltType == MSAPI_DMX_FILTER_TYPE_SECTION_EIT))
    {
        return DMX_FILTER_STATUS_ERROR;
    }

    msAPI_DMX_Stop(*pu8FID);


    memset(&FltInfo,0,sizeof(DMX_Flt_info));
    if(u32FltType == MSAPI_DMX_FILTER_TYPE_AUDIO)
    {
        enFtTypeNew=DMX_FILTER_TYPE_AUDIO;
    }
    else if(u32FltType == MSAPI_DMX_FILTER_TYPE_AUDIO2)
    {
        enFtTypeNew=DMX_FILTER_TYPE_AUDIO2;
    }
#if ENABLE_TTX
    else if(u32FltType == MSAPI_DMX_FILTER_TYPE_TELETEXT)
    {
        FltInfo.Info.SectInfo.SectBufAddr = msAPI_TTX_GetVBIStartAddress();
        FltInfo.Info.SectInfo.SectBufSize = msAPI_TTX_GetVBI_BufferSize();
        FltInfo.Info.SectInfo.SectMode=DMX_SECT_MODE_CONTI|DMX_SECT_MODE_AUTO_ADDR;
        enFtTypeNew=DMX_FILTER_TYPE_TELETEXT;
    }
#endif
    else if(u32FltType == MSAPI_DMX_FILTER_TYPE_PCR)
    {
        enFtTypeNew=DMX_FILTER_TYPE_PCR;
    }
    else if(u32FltType == MSAPI_DMX_FILTER_TYPE_VIDEO)
    {
        enFtTypeNew=DMX_FILTER_TYPE_VIDEO;
    }
    else
    {
        printf("\nError: u32FltType=0x%X, at %s %d\n", u32FltType, __FILE__, (int)__LINE__);
    }


    /*[02]OPEN a filter ===============================================================*/
    if (*pu8FID == MSAPI_DMX_INVALID_FLT_ID)        // not open yet
    {
        if(DMX_FILTER_STATUS_OK != _MApp_Dmx_HaveFreeFilter())
        {
            return DMX_FILTER_STATUS_ERROR;
        }
        if(DMX_FILTER_STATUS_OK != MApi_DMX_Open(enFtTypeNew | eFilterType, pu8FID))
        {
            return DMX_FILTER_STATUS_ERROR;
        }
        for(i=(MSAPI_DMX_SEC1K_FILTER_NUMBER+MSAPI_DMX_SEC4K_FILTER_NUMBER+MSAPI_DMX_SEC4K_EIT_FILTER_NUMBER);i<MSAPI_DMX_MAX_FILTER_NUMBER;i++)
        {
            if(_DmxTsFilter[i].bUsed == FALSE)
            {
                _DmxTsFilter[i].bUsed=TRUE;
                _DmxTsFilter[i].u16TimeoutMilliSec=MSAPI_DMX_TIMEOUT_INFINITE;
                _DmxTsFilter[i].u8FltID=*pu8FID;
			#if 0//no need when use utopia
                if(u32FltType == MSAPI_DMX_FILTER_TYPE_PCR)
                {
                    FltInfo.Info.SectInfo.SectBufAddr =((SECBUF_START_MEMORY_TYPE & MIU1) ? ((SECBUF_START_ADR) | MIU_INTERVAL) : (SECBUF_START_ADR/*8 byte for PCR use*/));
                    FltInfo.Info.SectInfo.SectBufSize=0;//8 byte for PCR use
                }
			#endif
                break;
            }
        }

    }
    FltInfo.Info.SectInfo.SectBufAddr &= 0xFFFFFFF0;
    FltInfo.Info.SectInfo.SectBufSize &= 0xFFFFFFF0;

//printf("enFltType %d %d fid %d notify %x\n",enFltType,enFtTypeNew,*pu8FID,FltInfo.Info.SectInfo.pNotify);

    MApi_DMX_Info(*pu8FID,&FltInfo,&enFtTypeNew,TRUE);

    /*[03]SET the filter ==============================================================*/
    msAPI_DMX_Pid(*pu8FID, &u16Pid,TRUE);

    #if ENABLE_CI && ENABLE_CI_PLUS
    if( (DMX_FILTER_TYPE_VIDEO == enFtTypeNew) || (DMX_FILTER_TYPE_AUDIO == enFtTypeNew) || (DMX_FILTER_TYPE_AUDIO2 == enFtTypeNew) || (DMX_FILTER_TYPE_PCR == enFtTypeNew) || (DMX_FILTER_TYPE_TELETEXT == enFtTypeNew))
    msAPI_CI_CC_SetFID(*pu8FID, TRUE);
    #endif

    /*[05]START the filter ============================================================*/
    msAPI_DMX_Start(*pu8FID);

    return DMX_FILTER_STATUS_OK;
}

DMX_FILTER_STATUS msAPI_DMX_Open(MS_DMX_SECTIONMONITOR_PARA * pstSectionMonitor, U32 *u32StartAddress, U32 *u32Size)
{
    DMX_FILTER_TYPE FilterType=DMX_FILTER_TYPE_SECTION;
    U32 u32BufferSize=MSAPI_DMX_SECTION_1K;
    U8 i;
    DMX_FILTER_TYPE eFilterType=DMX_FILTER_SOURCE_TYPE_LIVE;
#ifdef DISABLE_DMX
    return DMX_FILTER_STATUS_ERROR;
#endif
    if (pstSectionMonitor->pu8FID == NULL)
    {
        return DMX_FILTER_STATUS_ERROR;
    }

    if (pstSectionMonitor->pfNotify == NULL)
    {
        //return MAPI_DMX_FILTER_STATUS_ERROR;
    }
    if((pstSectionMonitor->u32SectionFltType & MSAPI_DMX_FILTER_SOURCE_TYPE_MASK) == MSAPI_DMX_FILTER_SOURCE_TYPE_FILE)
    {
        eFilterType=DMX_FILTER_SOURCE_TYPE_FILE;
    }
    pstSectionMonitor->u32SectionFltType=(pstSectionMonitor->u32SectionFltType&~MSAPI_DMX_FILTER_SOURCE_TYPE_MASK);
#if(CSA_ENABLE == 1)
    if( pstSectionMonitor->u32SectionFltType ==  MSAPI_DMX_FILTER_TYPE_CSA_PACKET)
    {
        MBX_Result mbxResult;
        MBX_Msg mbxMsg;
        U8 wait=0;
        MBX_MSGQ_Status MsgQueueStatus;
        U32 u32CurrentMsgNumber = 0;
        if(_bCSA_Filter_ON)
        {
            //printf("error %s...%d \n",__FUNCTION__,__LINE__);
            return DMX_FILTER_STATUS_ERROR;
        }
        *(pstSectionMonitor->pu8FID) = MSAPI_DMX_INVALID_FLT_ID;
        for(i=(MSAPI_DMX_SEC1K_FILTER_NUMBER+MSAPI_DMX_SEC4K_FILTER_NUMBER);i<(MSAPI_DMX_SEC1K_FILTER_NUMBER+MSAPI_DMX_SEC4K_FILTER_NUMBER+MSAPI_DMX_SEC4K_EIT_FILTER_NUMBER);i++)
        {
            if(_DmxTsFilter[i].bUsed == FALSE)
            {
                _DmxTsFilter[i].bUsed=TRUE;
                _DmxTsFilter[i].u16TimeoutMilliSec=pstSectionMonitor->u16TimeoutMilliSec;
                _DmxTsFilter[i].pfNotify=pstSectionMonitor->pfNotify;
                _DmxTsFilter[i].u8FltID=CSA_FILTER_ID;
                _DmxTsFilter[i].u32SectionFltType = pstSectionMonitor->u32SectionFltType ;
                if(pstSectionMonitor->u16TimeoutMilliSec != MSAPI_DMX_TIMEOUT_INFINITE)
                {
                    _DmxTsFilter[i].u32TimerEnd=msAPI_Timer_GetTime0()+pstSectionMonitor->u16TimeoutMilliSec;
                }
                *u32StartAddress=((SECBUF_START_MEMORY_TYPE & MIU1) ? (SECBUF_START_ADR | MIU_INTERVAL) : (SECBUF_START_ADR))+MSAPI_DMX_SEC1K_FILTER_NUMBER*u32Sec1KFilterBufferSize+
                            (MSAPI_DMX_SEC4K_FILTER_NUMBER*u32Sec4KFilterBufferSize)+
                            ((i-(MSAPI_DMX_SEC1K_FILTER_NUMBER+MSAPI_DMX_SEC4K_FILTER_NUMBER))*u32Sec4KEitFilterBufferSize);
                *u32Size=u32Sec4KEitFilterBufferSize;
                break;
            }
        }
        if(i>=(MSAPI_DMX_SEC1K_FILTER_NUMBER+MSAPI_DMX_SEC4K_FILTER_NUMBER+MSAPI_DMX_SEC4K_EIT_FILTER_NUMBER))
        {
            printf("!!!!!!no free filter for CSA\n");
            return DMX_FILTER_STATUS_ERROR;
        }
        mbxResult = MSApi_MBX_RegisterMSGWithCallBack(E_MBX_CLASS_CSA, CSA_MSA_QUEUE_SIZE, _HandleCSAMSG);
        if(E_MBX_SUCCESS != mbxResult)
        {
			_DmxTsFilter[i].bUsed=FALSE;
            printf("!!!!!!MBX register msg error\n");
            return DMX_FILTER_STATUS_ERROR;
        }

        mbxMsg.eMsgType=E_MBX_MSG_TYPE_NORMAL;
        mbxMsg.u8MsgClass=E_MBX_CLASS_CSA;
        mbxMsg.u8Index=MB_CSA_FILTER_SET_EVEN_KEY;
        mbxMsg.u8ParameterCount=8;
        mbxMsg.u8Parameters[0]=even_key[0];
        mbxMsg.u8Parameters[1]=even_key[1];
        mbxMsg.u8Parameters[2]=even_key[2];
        mbxMsg.u8Parameters[3]=even_key[3];
        mbxMsg.u8Parameters[4]=even_key[4];
        mbxMsg.u8Parameters[5]=even_key[5];
        mbxMsg.u8Parameters[6]=even_key[6];
        mbxMsg.u8Parameters[7]=even_key[7];

	    mbxResult = MSApi_MBX_SendMsg(&mbxMsg);

        mbxMsg.eMsgType=E_MBX_MSG_TYPE_NORMAL;
        mbxMsg.u8MsgClass=E_MBX_CLASS_CSA;
        mbxMsg.u8Index=MB_CSA_FILTER_SET_ODD_KEY;
        mbxMsg.u8ParameterCount=8;
        mbxMsg.u8Parameters[0]=odd_key[0];
        mbxMsg.u8Parameters[1]=odd_key[1];
        mbxMsg.u8Parameters[2]=odd_key[2];
        mbxMsg.u8Parameters[3]=odd_key[3];
        mbxMsg.u8Parameters[4]=odd_key[4];
        mbxMsg.u8Parameters[5]=odd_key[5];
        mbxMsg.u8Parameters[6]=odd_key[6];
        mbxMsg.u8Parameters[7]=odd_key[7];

	    mbxResult = MSApi_MBX_SendMsg(&mbxMsg);


        mbxMsg.eMsgType=E_MBX_MSG_TYPE_NORMAL;
        mbxMsg.u8MsgClass=E_MBX_CLASS_CSA;
        mbxMsg.u8Index=MB_CSA_FILTER_START;
        mbxMsg.u8ParameterCount=9;
        mbxMsg.u8Parameters[0]=((pstSectionMonitor->u16PID)>>8)&0xFF;
        mbxMsg.u8Parameters[1]=(pstSectionMonitor->u16PID)&0xFF;
        mbxMsg.u8Parameters[2]=(*u32StartAddress)>>24;
        mbxMsg.u8Parameters[3]=(*u32StartAddress>>16)&0xFF;
        mbxMsg.u8Parameters[4]=(*u32StartAddress>>8)&0xFF;
        mbxMsg.u8Parameters[5]=(*u32StartAddress)&0xFF;
        mbxMsg.u8Parameters[6]=(*u32Size>>8)&0xFF;
        mbxMsg.u8Parameters[7]=(*u32Size)&0xFF;
        mbxMsg.u8Parameters[8]=_u8FilterGroup;

	    mbxResult = MSApi_MBX_SendMsg(&mbxMsg);

        if(E_MBX_SUCCESS != mbxResult)
        {
            _DmxTsFilter[i].bUsed=FALSE;
            printf("!!!!!!MBX send msg error\n");
            return DMX_FILTER_STATUS_ERROR;
        }

        while(wait++ < 100)
        {
            msAPI_Timer_Delayms(1);
            mbxResult = MSApi_MBX_GetMsgQueueStatus(E_MBX_CLASS_CSA, &MsgQueueStatus);
            if(MsgQueueStatus.status & MBX_STATUS_QUEUE_HAS_INSTANT_MSG)
                u32CurrentMsgNumber = MsgQueueStatus.u32InstantMsgCount;
            else if(MsgQueueStatus.status & MBX_STATUS_QUEUE_HAS_NORMAL_MSG)
                u32CurrentMsgNumber = MsgQueueStatus.u32NormalMsgCount;
            if(u32CurrentMsgNumber>0)
            {
                if(MSApi_MBX_RecvMsg(E_MBX_CLASS_CSA, &mbxMsg, 0, MBX_CHECK_NORMAL_MSG) == E_MBX_SUCCESS)
                {
                    if(((U8)mbxMsg.u8Index) == MB_CSA_FILTER_SUCCESS)
                    {
                        printf("open CSA success--\n");
                        break;
                    }
                }
            }
        }
        if(wait>=100)
        {
            _DmxTsFilter[i].bUsed=FALSE;
            printf("!!!!!!open CSA filter error\n");
            return DMX_FILTER_STATUS_ERROR;
        }
        _u32SecStartAddress=_u32SecWriteAddress=_u32SecReadAddress=*u32StartAddress;
        _u32SecEndAddress=_u32SecStartAddress+*u32Size;

        *(pstSectionMonitor->pu8FID)=CSA_FILTER_ID;
        _bCSA_Filter_ON=TRUE;
        return DMX_FILTER_STATUS_OK;
    }
#endif
    if ((pstSectionMonitor->u32SectionFltType != MSAPI_DMX_FILTER_TYPE_SECTION_1K     ) &&
        (pstSectionMonitor->u32SectionFltType != MSAPI_DMX_FILTER_TYPE_SECTION_4K            ) &&
        (pstSectionMonitor->u32SectionFltType != MSAPI_DMX_FILTER_TYPE_OAD_MONITOR) &&
        (pstSectionMonitor->u32SectionFltType != MSAPI_DMX_FILTER_TYPE_OAD_DOWNLOAD) &&
        (pstSectionMonitor->u32SectionFltType != MSAPI_DMX_FILTER_TYPE_SUBTITLE       )&&
        (pstSectionMonitor->u32SectionFltType != MSAPI_DMX_FILTER_TYPE_SECTION_EIT       ))
    {
        return DMX_FILTER_STATUS_ERROR;
    }
    if(pstSectionMonitor->u32SectionFltType == MSAPI_DMX_FILTER_TYPE_SUBTITLE)
    {
        FilterType = DMX_FILTER_TYPE_PES;
    }
    /*[02]OPEN a filter ===============================================================*/
    if(DMX_FILTER_STATUS_OK != _MApp_Dmx_HaveFreeFilter())
    {
        return DMX_FILTER_STATUS_ERROR;
    }
    if(DMX_FILTER_STATUS_ERROR == MApi_DMX_Open(FilterType | eFilterType, pstSectionMonitor->pu8FID) )
    {
        *(pstSectionMonitor->pu8FID) = MSAPI_DMX_INVALID_FLT_ID;
        return DMX_FILTER_STATUS_ERROR;
    }
    //printf("MApi_DMX_Open %d\n",*(pstSectionMonitor->pu8FID));
    if(pstSectionMonitor->u32SectionFltType == MSAPI_DMX_FILTER_TYPE_SECTION_4K)
    {
        u32BufferSize=MSAPI_DMX_SECTION_4K;
    }
    //printf("MApi_DMX_Open %d\n",*(pstSectionMonitor->pu8FID));
    if(pstSectionMonitor->u32SectionFltType == MSAPI_DMX_FILTER_TYPE_OAD_MONITOR)
    {
        for(i=(MSAPI_DMX_SEC1K_FILTER_NUMBER+MSAPI_DMX_SEC4K_FILTER_NUMBER+MSAPI_DMX_SEC4K_EIT_FILTER_NUMBER);i<MSAPI_DMX_MAX_FILTER_NUMBER;i++)
        {
            if(_DmxTsFilter[i].bUsed == FALSE)
            {
                _DmxTsFilter[i].bUsed=TRUE;
                _DmxTsFilter[i].u16TimeoutMilliSec=pstSectionMonitor->u16TimeoutMilliSec;
                _DmxTsFilter[i].pfNotify=pstSectionMonitor->pfNotify;
                _DmxTsFilter[i].u8FltID=*(pstSectionMonitor->pu8FID);
                _DmxTsFilter[i].u32SectionFltType = pstSectionMonitor->u32SectionFltType ;
                if(pstSectionMonitor->u16TimeoutMilliSec != MSAPI_DMX_TIMEOUT_INFINITE)
                {
                    _DmxTsFilter[i].u32TimerEnd=msAPI_Timer_GetTime0()+pstSectionMonitor->u16TimeoutMilliSec;
                }
                *u32StartAddress=u32OadbufMonitorAddr;
                *u32Size=u32OadbufMonitorSize;

                return DMX_FILTER_STATUS_OK;
            }
        }
    }
    if(pstSectionMonitor->u32SectionFltType == MSAPI_DMX_FILTER_TYPE_OAD_DOWNLOAD)
    {
        for(i=(MSAPI_DMX_SEC1K_FILTER_NUMBER+MSAPI_DMX_SEC4K_FILTER_NUMBER+MSAPI_DMX_SEC4K_EIT_FILTER_NUMBER);i<MSAPI_DMX_MAX_FILTER_NUMBER;i++)
        {
            if(_DmxTsFilter[i].bUsed == FALSE)
            {
                _DmxTsFilter[i].bUsed=TRUE;
                _DmxTsFilter[i].u16TimeoutMilliSec=pstSectionMonitor->u16TimeoutMilliSec;
                _DmxTsFilter[i].pfNotify=pstSectionMonitor->pfNotify;
                _DmxTsFilter[i].u8FltID=*(pstSectionMonitor->pu8FID);
                _DmxTsFilter[i].u32SectionFltType = pstSectionMonitor->u32SectionFltType ;
                if(pstSectionMonitor->u16TimeoutMilliSec != MSAPI_DMX_TIMEOUT_INFINITE)
                {
                    _DmxTsFilter[i].u32TimerEnd=msAPI_Timer_GetTime0()+pstSectionMonitor->u16TimeoutMilliSec;
                }
                *u32StartAddress=u32OadbufDownloadAddr;
                *u32Size=u32OadbufDownloadSize;

                return DMX_FILTER_STATUS_OK;
            }
        }
    }
    else if(pstSectionMonitor->u32SectionFltType == MSAPI_DMX_FILTER_TYPE_SUBTITLE)
    {
    #if (BLOADER)
        return DMX_FILTER_STATUS_ERROR;
    #else
        for(i=(MSAPI_DMX_SEC1K_FILTER_NUMBER+MSAPI_DMX_SEC4K_FILTER_NUMBER+MSAPI_DMX_SEC4K_EIT_FILTER_NUMBER);i<MSAPI_DMX_MAX_FILTER_NUMBER;i++)
        {
            if(_DmxTsFilter[i].bUsed == FALSE)
            {
                _DmxTsFilter[i].bUsed=TRUE;
                _DmxTsFilter[i].u16TimeoutMilliSec=pstSectionMonitor->u16TimeoutMilliSec;
                _DmxTsFilter[i].pfNotify=pstSectionMonitor->pfNotify;
                _DmxTsFilter[i].u8FltID=*(pstSectionMonitor->pu8FID);
                _DmxTsFilter[i].u32SectionFltType = pstSectionMonitor->u32SectionFltType ;
                if(pstSectionMonitor->u16TimeoutMilliSec != MSAPI_DMX_TIMEOUT_INFINITE)
                {
                    _DmxTsFilter[i].u32TimerEnd=msAPI_Timer_GetTime0()+pstSectionMonitor->u16TimeoutMilliSec;
                }

            #if(ENABLE_API_MMAP_GET_BUF) // Use MMAP API
                U32 u32SubtitleBufAddr = 0, u32SubtitleBufSize = 0;
                if( FALSE == msAPI_MMAP_Get_BufInfo(E_BUFID_SUBTITLE, &u32SubtitleBufAddr, &u32SubtitleBufSize ) )
                {
                    return DMX_FILTER_STATUS_ERROR;
                }
                *u32StartAddress = u32SubtitleBufAddr;
                *u32Size = DEMUX_SUBTITLE_OFFSET;
            #else
                *u32StartAddress = u32SubtitleAddr;
                *u32Size = u32SubtitleSize;
            #endif

                //printf("sub open %x\n",_DmxTsFilter[i].u8FltID);
                return DMX_FILTER_STATUS_OK;
            }
        }
    #endif
    }
    else if (u32BufferSize == MSAPI_DMX_SECTION_4K)
    {
        for(i=MSAPI_DMX_SEC1K_FILTER_NUMBER;i<(MSAPI_DMX_SEC1K_FILTER_NUMBER+MSAPI_DMX_SEC4K_FILTER_NUMBER);i++)
        {
            if(_DmxTsFilter[i].bUsed == FALSE)
            {
                _DmxTsFilter[i].bUsed=TRUE;
                _DmxTsFilter[i].u16TimeoutMilliSec=pstSectionMonitor->u16TimeoutMilliSec;
                _DmxTsFilter[i].pfNotify=pstSectionMonitor->pfNotify;
                _DmxTsFilter[i].u8FltID=*(pstSectionMonitor->pu8FID);
                _DmxTsFilter[i].u32SectionFltType = pstSectionMonitor->u32SectionFltType ;
                if(pstSectionMonitor->u16TimeoutMilliSec != MSAPI_DMX_TIMEOUT_INFINITE)
                {
                    _DmxTsFilter[i].u32TimerEnd=msAPI_Timer_GetTime0()+pstSectionMonitor->u16TimeoutMilliSec;
                }
                //printf("msAPI_DMX_Open %d\n",_DmxTsFilter[i].u8FltID);
                *u32StartAddress=((SECBUF_START_MEMORY_TYPE & MIU1) ? (SECBUF_START_ADR | MIU_INTERVAL) : (SECBUF_START_ADR))+MSAPI_DMX_SEC1K_FILTER_NUMBER*u32Sec1KFilterBufferSize+((i-MSAPI_DMX_SEC1K_FILTER_NUMBER)*u32Sec4KFilterBufferSize);
                *u32Size=u32Sec4KFilterBufferSize;
                return DMX_FILTER_STATUS_OK;
            }
        }
    }
    else if (pstSectionMonitor->u32SectionFltType == MSAPI_DMX_FILTER_TYPE_SECTION_EIT)
    {
        for(i=(MSAPI_DMX_SEC1K_FILTER_NUMBER+MSAPI_DMX_SEC4K_FILTER_NUMBER);i<(MSAPI_DMX_SEC1K_FILTER_NUMBER+MSAPI_DMX_SEC4K_FILTER_NUMBER+MSAPI_DMX_SEC4K_EIT_FILTER_NUMBER);i++)
        {
            if(_DmxTsFilter[i].bUsed == FALSE)
            {
                _DmxTsFilter[i].bUsed=TRUE;
                _DmxTsFilter[i].u16TimeoutMilliSec=pstSectionMonitor->u16TimeoutMilliSec;
                _DmxTsFilter[i].pfNotify=pstSectionMonitor->pfNotify;
                _DmxTsFilter[i].u8FltID=*(pstSectionMonitor->pu8FID);
                _DmxTsFilter[i].u32SectionFltType = pstSectionMonitor->u32SectionFltType ;
                if(pstSectionMonitor->u16TimeoutMilliSec != MSAPI_DMX_TIMEOUT_INFINITE)
                {
                    _DmxTsFilter[i].u32TimerEnd=msAPI_Timer_GetTime0()+pstSectionMonitor->u16TimeoutMilliSec;
                }
                //printf("msAPI_DMX_Open %d\n",_DmxTsFilter[i].u8FltID);
                *u32StartAddress=((SECBUF_START_MEMORY_TYPE & MIU1) ? (SECBUF_START_ADR | MIU_INTERVAL) : (SECBUF_START_ADR))+MSAPI_DMX_SEC1K_FILTER_NUMBER*u32Sec1KFilterBufferSize+
                            (MSAPI_DMX_SEC4K_FILTER_NUMBER*u32Sec4KFilterBufferSize)+
                            ((i-(MSAPI_DMX_SEC1K_FILTER_NUMBER+MSAPI_DMX_SEC4K_FILTER_NUMBER))*u32Sec4KEitFilterBufferSize);
                *u32Size=u32Sec4KEitFilterBufferSize;
                return DMX_FILTER_STATUS_OK;
            }
        }
    }
    else
    {
        for (i = 0; i < MSAPI_DMX_SEC1K_FILTER_NUMBER; i++)
        {
            if (_DmxTsFilter[i].bUsed == FALSE)
            {
                _DmxTsFilter[i].bUsed=TRUE;
                _DmxTsFilter[i].u16TimeoutMilliSec=pstSectionMonitor->u16TimeoutMilliSec;
                _DmxTsFilter[i].pfNotify=pstSectionMonitor->pfNotify;
                _DmxTsFilter[i].u8FltID=*(pstSectionMonitor->pu8FID);
                _DmxTsFilter[i].u32SectionFltType = pstSectionMonitor->u32SectionFltType ;
                if(pstSectionMonitor->u16TimeoutMilliSec != MSAPI_DMX_TIMEOUT_INFINITE)
                {
                    _DmxTsFilter[i].u32TimerEnd=msAPI_Timer_GetTime0()+pstSectionMonitor->u16TimeoutMilliSec;
                }
				#if 1//no need when use utopia
                *u32StartAddress=((SECBUF_START_MEMORY_TYPE & MIU1) ? ((SECBUF_START_ADR) | MIU_INTERVAL) : (SECBUF_START_ADR))+i*u32Sec1KFilterBufferSize;
                *u32Size=u32Sec1KFilterBufferSize;//8 byte for PCR use
				#else
                *u32StartAddress=((SECBUF_START_MEMORY_TYPE & MIU1) ? ((SECBUF_START_ADR+(i==0?8:0)/*8 byte for PCR use*/) | MIU_INTERVAL) : (SECBUF_START_ADR+(i==0?8:0)/*8 byte for PCR use*/))+i*u32Sec1KFilterBufferSize;
                *u32Size=u32Sec1KFilterBufferSize-(i==0?8:0);//8 byte for PCR use
				#endif
                //printf("msAPI_DMX_Open %d\n",_DmxTsFilter[i].u8FltID);
                return DMX_FILTER_STATUS_OK;
            }
        }
    }
    MApi_DMX_Close(*(pstSectionMonitor->pu8FID));
#if ENABLE_CI && ENABLE_CI_PLUS
    if(MSAPI_DMX_FILTER_TYPE_SUBTITLE==pstSectionMonitor->u32SectionFltType)
        msAPI_CI_CC_SetFID(*(pstSectionMonitor->pu8FID),FALSE);
#endif
    *(pstSectionMonitor->pu8FID) = MSAPI_DMX_INVALID_FLT_ID;
    return DMX_FILTER_STATUS_ERROR;
}


DMX_FILTER_STATUS msAPI_DMX_SectionMonitor(MS_DMX_SECTIONMONITOR_PARA * pstSectionMonitor, BOOL bFileIn)
{
    DMX_Flt_info FltInfo;
    DMX_FILTER_TYPE FilterType=DMX_FILTER_TYPE_SECTION;
#if(CSA_ENABLE == 1)
    U32 u32FilterType=pstSectionMonitor->u32SectionFltType;
#endif
    if(bFileIn)
    {
        pstSectionMonitor->u32SectionFltType|=MSAPI_DMX_FILTER_SOURCE_TYPE_FILE;
    }
    if(DMX_FILTER_STATUS_ERROR == msAPI_DMX_Open(pstSectionMonitor,&FltInfo.Info.SectInfo.SectBufAddr,&FltInfo.Info.SectInfo.SectBufSize))
    {
        return DMX_FILTER_STATUS_ERROR;
    }
#if(CSA_ENABLE == 1)
    if(MSAPI_DMX_FILTER_TYPE_CSA_PACKET == u32FilterType)
    {
        if(*(pstSectionMonitor->pu8FID) == CSA_FILTER_ID)
        {
            return DMX_FILTER_STATUS_OK;
        }
        return DMX_FILTER_STATUS_ERROR;
    }
#endif
#if 0
    printf("msAPI_DMX_Open fid %d pid %d buff start %x size %x\n",*(pstSectionMonitor->pu8FID),pstSectionMonitor->u16PID,
    FltInfo.Info.SectInfo.SectBufAddr, FltInfo.Info.SectInfo.SectBufSize);
#endif
    FltInfo.Info.SectInfo.SectMode  = pstSectionMonitor->SectMode;
    FltInfo.Info.SectInfo.Event     = DMX_EVENT_DATA_READY | DMX_EVENT_BUF_OVERFLOW|DMX_EVENT_CB_POLL;
    FltInfo.Info.SectInfo.pNotify   = (DMX_NotifyCb)pstSectionMonitor->pfNotify;

    // printf("msAPI_DMX_SectionMonitor notify...%x\n",FltInfo.Info.SectInfo.pNotify);
    FltInfo.Info.SectInfo.SectBufAddr &= 0xFFFFFFF0;
    FltInfo.Info.SectInfo.SectBufSize &= 0xFFFFFFF0;
    MApi_DMX_Info(*(pstSectionMonitor->pu8FID), &FltInfo, &FilterType, TRUE);
    MApi_DMX_Pid(*(pstSectionMonitor->pu8FID), &pstSectionMonitor->u16PID, TRUE);
#if ENABLE_CI && ENABLE_CI_PLUS
    if(MSAPI_DMX_FILTER_TYPE_SUBTITLE==pstSectionMonitor->u32SectionFltType)
        msAPI_CI_CC_SetFID(*(pstSectionMonitor->pu8FID),TRUE);
#endif
    MApi_DMX_SectPatternSet(*(pstSectionMonitor->pu8FID), pstSectionMonitor->au8MatchByte, pstSectionMonitor->au8MaskByte, pstSectionMonitor->au8NotMatchByte, MSAPI_DMX_MATCH_PATTERN_LENGTH);

    /*[04]RESET the filter ============================================================*/
    MApi_DMX_SectReset(*(pstSectionMonitor->pu8FID));

    /*[05]START the filter ============================================================*/
    MApi_DMX_Start(*(pstSectionMonitor->pu8FID));
    if(pstSectionMonitor->u16PID == 0)//add for PAT status check
    {
        _u8PATFliterID = *(pstSectionMonitor->pu8FID);
    }
    return DMX_FILTER_STATUS_OK;
}



DMX_FILTER_STATUS msAPI_DMX_SectionGet(MS_DMX_SECTIONGET_PARA * pstSectionGet)
{
    U8 i;
    U8 u8FID;
    DMX_Flt_info FltInfo;
    DMX_FILTER_TYPE FilterType = DMX_FILTER_TYPE_SECTION;
    DMX_FILTER_STATUS enFilterStatus = DMX_FILTER_STATUS_ERROR;
    U32 time;
    DMX_EVENT eEvent = DMX_EVENT_DATA_READY;

    /*[01]error conditions ============================================================*/

#ifdef DISABLE_DMX
    return DMX_FILTER_STATUS_ERROR;
#endif

    if (pstSectionGet->pu8Section == NULL)
    {
        return DMX_FILTER_STATUS_ERROR;
    }

    if ((pstSectionGet->u32SectionFltType != MSAPI_DMX_FILTER_TYPE_SECTION_1K     ) &&
        (pstSectionGet->u32SectionFltType != MSAPI_DMX_FILTER_TYPE_SECTION_4K            ))
    {
        return DMX_FILTER_STATUS_ERROR;
    }

    /*[02]OPEN a filter ===============================================================*/
    if(DMX_FILTER_STATUS_OK != _MApp_Dmx_HaveFreeFilter())
    {
        return DMX_FILTER_STATUS_ERROR;
    }

    if (DMX_FILTER_STATUS_ERROR == MApi_DMX_Open(FilterType | DMX_FILTER_SOURCE_TYPE_LIVE, &u8FID) )
    {
        return DMX_FILTER_STATUS_ERROR;
    }

    // Move code from msAPI_DMX_Open and need to call msAPI_DMX_Close after used
    if (pstSectionGet->u32SectionFltType == MSAPI_DMX_FILTER_TYPE_SECTION_4K)
    {
        for(i=MSAPI_DMX_SEC1K_FILTER_NUMBER;i<(MSAPI_DMX_SEC1K_FILTER_NUMBER+MSAPI_DMX_SEC4K_FILTER_NUMBER);i++)
        {
            if(_DmxTsFilter[i].bUsed == FALSE)
            {
                _DmxTsFilter[i].bUsed               = TRUE;
                _DmxTsFilter[i].u16TimeoutMilliSec  = pstSectionGet->u16TimeoutMilliSec;    // unused code
                _DmxTsFilter[i].pfNotify            = NULL;                                 // unused code
                _DmxTsFilter[i].u8FltID             = u8FID;

                if(pstSectionGet->u16TimeoutMilliSec != MSAPI_DMX_TIMEOUT_INFINITE)         // unused code
                {
                    _DmxTsFilter[i].u32TimerEnd     = msAPI_Timer_GetTime0()+pstSectionGet->u16TimeoutMilliSec;
                }
                FltInfo.Info.SectInfo.SectBufAddr   = ((SECBUF_START_MEMORY_TYPE & MIU1) ? (SECBUF_START_ADR | MIU_INTERVAL) : (SECBUF_START_ADR))+MSAPI_DMX_SEC1K_FILTER_NUMBER*u32Sec1KFilterBufferSize+((i-MSAPI_DMX_SEC1K_FILTER_NUMBER)*u32Sec4KFilterBufferSize);
                FltInfo.Info.SectInfo.SectBufSize   = u32Sec4KFilterBufferSize;
                break;
            }
        }
    }
    else
    {
        for (i = 0; i < MSAPI_DMX_SEC1K_FILTER_NUMBER; i++)
        {
            if (_DmxTsFilter[i].bUsed == FALSE)
            {
                _DmxTsFilter[i].bUsed               = TRUE;
                _DmxTsFilter[i].u16TimeoutMilliSec  = pstSectionGet->u16TimeoutMilliSec;    // unused code
                _DmxTsFilter[i].pfNotify            = NULL;                                 // unused code
                _DmxTsFilter[i].u8FltID             = u8FID;

                if(pstSectionGet->u16TimeoutMilliSec != MSAPI_DMX_TIMEOUT_INFINITE)         // unused code
                {
                    _DmxTsFilter[i].u32TimerEnd     = msAPI_Timer_GetTime0()+pstSectionGet->u16TimeoutMilliSec;
                }
                FltInfo.Info.SectInfo.SectBufAddr   = ((SECBUF_START_MEMORY_TYPE & MIU1) ? (SECBUF_START_ADR | MIU_INTERVAL) : (SECBUF_START_ADR))+i*u32Sec1KFilterBufferSize;
                FltInfo.Info.SectInfo.SectBufSize   = u32Sec1KFilterBufferSize;
                break;
            }
        }
    }

    DMX_DB(printf("msAPI_DMX_SectionGet fid %d start %x size %x\n",u8FID,FltInfo.Info.SectInfo.SectBufAddr,FltInfo.Info.SectInfo.SectBufSize););

    /*[03]SET the filter ==============================================================*/
    FltInfo.Info.SectInfo.SectMode  = DMX_SECT_MODE_ONESHOT|DMX_SECT_MODE_CRCCHK;
    FltInfo.Info.SectInfo.Event     = DMX_EVENT_DATA_READY | DMX_EVENT_BUF_OVERFLOW|DMX_EVENT_CB_POLL;
    FltInfo.Info.SectInfo.pNotify   = NULL;
    //printf("msAPI_DMX_SectionGet notify...%x\n",FltInfo.Info.SectInfo.pNotify);
    FltInfo.Info.SectInfo.SectBufAddr &= 0xFFFFFFF0;
    FltInfo.Info.SectInfo.SectBufSize &= 0xFFFFFFF0;
    MApi_DMX_Info(u8FID, &FltInfo, &FilterType, TRUE);
    //printf("msAPI_DMX_SectionGet fid %d start %x size %x\n",u8FID,FltInfo.Info.SectInfo.SectBufAddr,FltInfo.Info.SectInfo.SectBufSize);
    MApi_DMX_Pid(u8FID, &pstSectionGet->u16PID, TRUE);
    MApi_DMX_SectPatternSet(u8FID, pstSectionGet->au8MatchByte, pstSectionGet->au8MaskByte, pstSectionGet->au8NotMatchByte, MSAPI_DMX_MATCH_PATTERN_LENGTH);

    /*[04]RESET the filter ============================================================*/
    MApi_DMX_SectReset(u8FID);

    /*[05]START the filter ============================================================*/
    MApi_DMX_Start(u8FID);

    time= msAPI_Timer_GetTime0();
    while(((enFilterStatus=MApi_DMX_Proc((MS_U8)u8FID, &eEvent)) != DMX_FILTER_STATUS_OK) && (msAPI_Timer_DiffTimeFromNow(time) < pstSectionGet->u16TimeoutMilliSec));
    if (enFilterStatus==DMX_FILTER_STATUS_OK)
    {
        U32 u32ActualSize = 0,u32RmnSize;
        if (DMX_EVENT_DATA_READY == eEvent)
        {
            if(MApi_DMX_CopyData(u8FID, pstSectionGet->pu8Section, FltInfo.Info.SectInfo.SectBufSize, &u32ActualSize, &u32RmnSize,NULL) != DMX_FILTER_STATUS_OK)
            {
                enFilterStatus=DMX_FILTER_STATUS_ERROR;
            }
        }
        else
            enFilterStatus = DMX_FILTER_STATUS_ERROR;
    }


    /*[07]STOP the SECTION filter =====================================================*/
    MApi_DMX_Stop(u8FID);

    /*[08]CLOSE the SECTION filter ====================================================*/
    msAPI_DMX_Close(u8FID);
#if (ENABLE_DEMUX_SW_CRC_CHECK)
    if(enFilterStatus == DMX_FILTER_STATUS_OK)
    {
        if(msAPI_DMX_CheckCRC32(pstSectionGet->pu8Section)== FALSE)
        {
            printf("crc error %s %d \n",__FUNCTION__,__LINE__);
        }
    }
#endif
    return enFilterStatus;
}

#if (ENABLE_DEMUX_SW_CRC_CHECK)
#define CRC_TABLE_NUM 256
static unsigned long drv_crc32_table[CRC_TABLE_NUM];

int MApp_Crc_GetCrc32(unsigned char *buffer, unsigned long length)
{
    unsigned long ulCRC = 0xFFFFFFFF;

    while (length--)
    {
        ulCRC = (ulCRC << 8) ^ drv_crc32_table[((ulCRC >> 24) & 0xFF) ^ *buffer++];
    }

    return (ulCRC);
}
static void _msAPI_DMX_Init_CRC_Table(void)
{
    int i,j;
    //printf("crc32\n");
    //MApi_DMX_SetDbgLevel(DMX_DBG_ERR);
    for(i=0;i<CRC_TABLE_NUM;i++)
    {
        drv_crc32_table[i]=i<<24;
        for(j=0;j<8;j++)
        {
            if((drv_crc32_table[i]&0x80000000L) == 0)
                drv_crc32_table[i]=(drv_crc32_table[i]<<1);
            else
                drv_crc32_table[i]=(drv_crc32_table[i]<<1)^0x04C11DB7;
        }
        //printf("0x%08x,\n",drv_crc32_table[i]);
    }
    //printf("\n");
}
#endif

BOOL msAPI_DMX_CheckCRC32(U8* pu8Section)
{
#if (ENABLE_DEMUX_SW_CRC_CHECK)

    U16 u16SecLenInByte;
    static BOOLEAN bfirst=0;
    if(bfirst==0)
    {
        bfirst=1;
        _msAPI_DMX_Init_CRC_Table();
    }
    /*[01]get section length from buffer ==============================================*/
    u16SecLenInByte  = ((*(pu8Section+1) & 0x0f) << 8);
    u16SecLenInByte |= ((*(pu8Section+2) & 0xff) << 0);
    if (u16SecLenInByte <= 4)
    {
        return FALSE;
    }
    u16SecLenInByte = u16SecLenInByte + 3; // plus before section length fields

    /*[02]use hardware crc engine to compare ==========================================*/
    if (!MApp_Crc_GetCrc32(pu8Section, u16SecLenInByte))    //<---return 0 means CRC correct
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
#else
    pu8Section = pu8Section;
    return TRUE;
#endif
}
#endif

//****************************************************************************
/// close SI/PSI filter
/// @param u8FID \b IN: filter ID
/// @return none
//****************************************************************************
void msAPI_DMX_CloseFilter(U8 u8FID)
{
    /* stop section filter */
    msAPI_DMX_Stop(u8FID);

    /* close section filter */
    msAPI_DMX_Close(u8FID);
}
//****************************************************************************
/// restart SI/PSI filter
/// @param u8FID \b IN: filter ID
/// @return none
//****************************************************************************
void msAPI_DMX_RestartFilter(U8 u8FID)
{
#if(CSA_ENABLE == 1)
    if(u8FID == CSA_FILTER_ID)
    {
        return;
    }
#endif

    /* stop section filter */
    msAPI_DMX_Stop(u8FID);

    /* reset fifo */
    msAPI_DMX_Reset(u8FID);

    /* start section filter */
    msAPI_DMX_Start(u8FID);
}

DMX_FILTER_STATUS msAPI_DMX_CopyData(MS_U8 u8DmxId, MS_U8* pu8Buf, MS_U32 u32BufSize, MS_U32* pu32ActualSize, MS_U32* pu32RmnSize, DMX_CheckCb pfCheckCB)
{
#if(CSA_ENABLE == 1)
    if(u8DmxId == CSA_FILTER_ID)
    {
        U16 secLen;
        U32 u32ReadAddress;
        MBX_Result mbxResult;
        MBX_Msg mbxMsg;
        if(_u32SecWriteAddress == _u32SecReadAddress)return DMX_FILTER_STATUS_ERROR;
        //printf("read %x write %x start %x end %x\n",_u32SecReadAddress,_u32SecWriteAddress,
        //    _u32SecStartAddress,_u32SecEndAddress);
        if((_u32SecReadAddress+3)>_u32SecEndAddress)
        {

            memcpy(pu8Buf,(void*)MsOS_PA2KSEG1(_u32SecReadAddress),_u32SecEndAddress-_u32SecReadAddress);
            memcpy(&pu8Buf[_u32SecEndAddress-_u32SecReadAddress],(void*)MsOS_PA2KSEG1(_u32SecStartAddress),3-(_u32SecEndAddress-_u32SecReadAddress));
            secLen=((pu8Buf[1]&0xf)<<8)+pu8Buf[2]+3;
            memcpy(&pu8Buf[_u32SecEndAddress-_u32SecReadAddress],(void*)MsOS_PA2KSEG1(_u32SecStartAddress),secLen-(_u32SecEndAddress-_u32SecReadAddress));
            u32ReadAddress=_u32SecStartAddress+secLen-(_u32SecEndAddress-_u32SecReadAddress);
        }
        else
        {
            memcpy(pu8Buf,(void*)MsOS_PA2KSEG1(_u32SecReadAddress),3);
            secLen=((pu8Buf[1]&0xf)<<8)+pu8Buf[2]+3;
            if((_u32SecReadAddress+secLen)>_u32SecEndAddress)
            {
                memcpy(pu8Buf,(void*)MsOS_PA2KSEG1(_u32SecReadAddress),_u32SecEndAddress-_u32SecReadAddress);
                memcpy(&pu8Buf[_u32SecEndAddress-_u32SecReadAddress],(void*)MsOS_PA2KSEG1(_u32SecStartAddress),secLen-(_u32SecEndAddress-_u32SecReadAddress));
                u32ReadAddress=_u32SecStartAddress+secLen-(_u32SecEndAddress-_u32SecReadAddress);
            }
            else
            {
                memcpy(pu8Buf,(void*)MsOS_PA2KSEG1(_u32SecReadAddress),secLen);
                u32ReadAddress=_u32SecReadAddress+secLen;
                if(u32ReadAddress == _u32SecEndAddress)u32ReadAddress=_u32SecStartAddress;
            }
        }
        _u32SecReadAddress=u32ReadAddress;
        printf("len %x  read %x write %x start %x end %x\n",secLen,_u32SecReadAddress,_u32SecWriteAddress,
            _u32SecStartAddress,_u32SecEndAddress);
        mbxMsg.eMsgType=E_MBX_MSG_TYPE_NORMAL;
        mbxMsg.u8MsgClass=E_MBX_CLASS_CSA;
        mbxMsg.u8Index=MB_CSA_SEC_READ_ADDRESS;
        mbxMsg.u8ParameterCount=4;
        mbxMsg.u8Parameters[0]=u32ReadAddress>>24;
        mbxMsg.u8Parameters[1]=(u32ReadAddress>>16)&0xFF;
        mbxMsg.u8Parameters[2]=(u32ReadAddress>>8)&0xFF;
        mbxMsg.u8Parameters[3]=(u32ReadAddress)&0xFF;
	    mbxResult = MSApi_MBX_SendMsg(&mbxMsg);
        if(E_MBX_SUCCESS != mbxResult)
        {
            printf("!!!!!!MBX send read address msg error\n");
        }
        return DMX_FILTER_STATUS_OK;
    }
#endif
    return MApi_DMX_CopyData(u8DmxId,pu8Buf,u32BufSize,pu32ActualSize,pu32RmnSize,pfCheckCB);
}
BOOLEAN msAPI_DMX_IsCSA_ON(void)
{
#if(CSA_ENABLE == 1)
    return _bCSA_ON;
#else
    return FALSE;
#endif
}
#if(CSA_ENABLE == 1)
static void _HandleCSAMSG(MBX_Msg *pMsg, MS_BOOL *pbAddToQueue)
{
    if(MB_CSA_SEC_WRITE_ADDRESS == pMsg->u8Index)
    {
        _u32SecWriteAddress=((pMsg->u8Parameters[0]<<24)|(pMsg->u8Parameters[1]<<16)|(pMsg->u8Parameters[2]<<8)|(pMsg->u8Parameters[3]));
        *pbAddToQueue = FALSE;
    }
    else
    {
        *pbAddToQueue = TRUE;
    }
}


void msAPI_DMX_CSA_Enable(BOOLEAN bEnable, U8 u8FilterGroup)
{
    _bCSA_ON=bEnable;
    _u8FilterGroup=u8FilterGroup;
}
#endif

#if (ENABLE_ATSC)
//
//MApi_DMX_Get_TsScmbSts(u8VdFid, &u8Scramble) / MApi_DMX_Get_PesScmbSts(u8VdFid, &u8Scramble)
//u8Scramble: [7:4] ts or pes packet count.
//                 : [3:0] ts or pes scrambling packet count.
//
#define    DMX_SC_DBG(y)   //y
#define    SCRAMBLE_CHECK_COUNT    200
#define    NON_SCRAMBLE_CHECK_COUNT    200 // unit:2ms, 400ms
#define    NON_TS_SCRAMBLE_CHECK_COUNT    100 // unit:2ms, 200ms
#define    TS_SCRAMBLE_THRESHOLD    0x07 // 3 ts packets
#define    PES_SCRAMBLE_THRESHOLD    0x07 // 3 pes packets

MSAPI_DMX_SCRAMBLING_SOURCE msAPI_DMX_ScramblingGet(U16 u16VideoPID, U16 u16AudioPID, U16 u16TimeoutMilliSec, BOOLEAN bEnPesScramble)
{
	U8 i;
    U8 u8VdFid=0xFF, u8AuFid=0xFF;
    U8 u8VideoTsScram=0, u8AudioTsScram=0, u8VideoTsNonScram=0, u8AudioTsNonScram=0;
    U8 u8VideoPesScram=0, u8AudioPesScram=0, u8VideoPesNonScram=0, u8AudioPesNonScram=0;
    U8 u8Scramble, u8TsNonScramCount;
    U32 u32TimerEnd=MSAPI_DMX_TIMEOUT_INFINITE;
    DMX_Flt_info FltInfo;
    MS_DMX_SECTIONGET_PARA stSectionGet;
    MSAPI_DMX_SCRAMBLING_SOURCE enScramSrc=MSAPI_DMX_SCRAMBLING_SOURCE_NONE;
    DMX_FILTER_TYPE enFtTypeNew= DMX_FILTER_TYPE_PACKET;
    MSAPI_DMX_FILTER_STATUS  enSecFltStatus = MSAPI_DMX_FILTER_STATUS_ERROR;
    //U32 u32Time1;

    /*OPEN a filter ===============================================================*/
    if(MApi_DMX_Open(enFtTypeNew, &u8VdFid) == DMX_FILTER_STATUS_ERROR)
    {
        printf("\r\n MApi_DMX_Open Err");
    }
    if(MApi_DMX_Open(enFtTypeNew, &u8AuFid) == DMX_FILTER_STATUS_ERROR)
    {
        printf("\r\n MApi_DMX_Open Err");
    }

#if (ENABLE_TVSCAN_DEBUGINFO)
    (printf("\r\n [msAPI_DMX_ScramblingGet] u16VideoPID=%x, u16AudioPID=%x, PesScramble=%bx, VdFit=%bx, AuFit=%bx\r\n", u16VideoPID, u16AudioPID, bEnPesScramble, u8VdFid, u8AuFid));
#endif

    memset(stSectionGet.au8MatchByte, 0x00, MSAPI_DMX_MATCH_PATTERN_LENGTH);
    memset(stSectionGet.au8MaskByte, 0x00, MSAPI_DMX_MATCH_PATTERN_LENGTH);
    memset(stSectionGet.au8NotMatchByte, 0x00, MSAPI_DMX_MATCH_PATTERN_LENGTH);
    stSectionGet.au8MatchByte[0] = 0x47;
    stSectionGet.au8MatchByte[1] = 0x40;
    stSectionGet.au8MaskByte[0]=0xFF;
    stSectionGet.au8MaskByte[1]=0x40;

    memset(&FltInfo,0,sizeof(FltInfo));

	for(i=MSAPI_DMX_SEC1K_FILTER_NUMBER;i<(MSAPI_DMX_SEC1K_FILTER_NUMBER+MSAPI_DMX_SEC4K_FILTER_NUMBER);i++)
	{
		if(_DmxTsFilter[i].bUsed == FALSE)
		{
			_DmxTsFilter[i].bUsed				= TRUE;
			_DmxTsFilter[i].pfNotify			= NULL; 								// unused code
			_DmxTsFilter[i].u8FltID 			= u8VdFid;

			FltInfo.Info.SectInfo.SectMode = DMX_SECT_MODE_PESSCMCHK;
			FltInfo.Info.SectInfo.Event = DMX_EVENT_DATA_READY | DMX_EVENT_BUF_OVERFLOW | DMX_EVENT_CB_POLL;
			FltInfo.Info.SectInfo.SectBufAddr	= ((SECBUF_START_MEMORY_TYPE & MIU1) ? (SECBUF_START_ADR | MIU_INTERVAL) : (SECBUF_START_ADR))+MSAPI_DMX_SEC1K_FILTER_NUMBER*u32Sec1KFilterBufferSize+((i-MSAPI_DMX_SEC1K_FILTER_NUMBER)*u32Sec4KFilterBufferSize);
			FltInfo.Info.SectInfo.SectBufSize	= u32Sec4KFilterBufferSize;
			break;
		}
	}

	/*
    FltInfo.Info.SectInfo.SectBufAddr   = ((SECBUF_START_ADR))+MSAPI_DMX_SEC1K_FILTER_NUMBER*u32Sec1KFilterBufferSize+((u8VdFid)*u32Sec4KFilterBufferSize);
    FltInfo.Info.SectInfo.SectBufSize   = u32Sec4KFilterBufferSize;
    FltInfo.Info.SectInfo.SectMode = DMX_SECT_MODE_PESSCMCHK;
    FltInfo.Info.SectInfo.Event = DMX_EVENT_DATA_READY | DMX_EVENT_BUF_OVERFLOW | DMX_EVENT_CB_POLL;
    FltInfo.Info.SectInfo.pNotify = NULL;
    */
    if(MApi_DMX_Info(u8VdFid,&FltInfo,&enFtTypeNew,TRUE) == DMX_FILTER_STATUS_ERROR)
    {
        printf("Failed to MApi_DMX_Info\n");
    }
    //FltInfo.Info.SectInfo.SectBufAddr   = ((SECBUF_START_ADR))+MSAPI_DMX_SEC1K_FILTER_NUMBER*u32Sec1KFilterBufferSize+((u8AuFid)*u32Sec4KFilterBufferSize);

	for(i=MSAPI_DMX_SEC1K_FILTER_NUMBER;i<(MSAPI_DMX_SEC1K_FILTER_NUMBER+MSAPI_DMX_SEC4K_FILTER_NUMBER);i++)
	{
		if(_DmxTsFilter[i].bUsed == FALSE)
		{
			_DmxTsFilter[i].bUsed				= TRUE;
			_DmxTsFilter[i].pfNotify			= NULL; 								// unused code
			_DmxTsFilter[i].u8FltID 			= u8AuFid;

			FltInfo.Info.SectInfo.SectMode = DMX_SECT_MODE_PESSCMCHK;
			FltInfo.Info.SectInfo.Event = DMX_EVENT_DATA_READY | DMX_EVENT_BUF_OVERFLOW | DMX_EVENT_CB_POLL;
			FltInfo.Info.SectInfo.SectBufAddr	= ((SECBUF_START_MEMORY_TYPE & MIU1) ? (SECBUF_START_ADR | MIU_INTERVAL) : (SECBUF_START_ADR))+MSAPI_DMX_SEC1K_FILTER_NUMBER*u32Sec1KFilterBufferSize+((i-MSAPI_DMX_SEC1K_FILTER_NUMBER)*u32Sec4KFilterBufferSize);
			FltInfo.Info.SectInfo.SectBufSize	= u32Sec4KFilterBufferSize;
			break;
		}
	}

    if(MApi_DMX_Info(u8AuFid,&FltInfo,&enFtTypeNew,TRUE) == DMX_FILTER_STATUS_ERROR)
    {
        printf("Failed to MApi_DMX_Info\n");
    }

    /*SET the filter ==============================================================*/
    if(MApi_DMX_Pid(u8VdFid, &u16VideoPID, TRUE) == DMX_FILTER_STATUS_ERROR)
    {
        printf("Failed to MApi_DMX_Pid\n");
    }
    if(MApi_DMX_Pid(u8AuFid, &u16AudioPID, TRUE) == DMX_FILTER_STATUS_ERROR)
    {
        printf("Failed to MApi_DMX_Pid\n");
    }

    /*SET Pattern ==============================================================*/
    if(MApi_DMX_SectPatternSet(u8VdFid, stSectionGet.au8MatchByte, stSectionGet.au8MaskByte, stSectionGet.au8NotMatchByte, MSAPI_DMX_MATCH_PATTERN_LENGTH) == DMX_FILTER_STATUS_ERROR)
    {
        printf("Failed to MApi_DMX_SectPatternSet\n");
    }
    if(MApi_DMX_SectPatternSet(u8AuFid, stSectionGet.au8MatchByte, stSectionGet.au8MaskByte, stSectionGet.au8NotMatchByte, MSAPI_DMX_MATCH_PATTERN_LENGTH) == DMX_FILTER_STATUS_ERROR)
    {
        printf("Failed to MApi_DMX_SectPatternSet\n");
    }

    /*RESET the filter ============================================================*/
    if(MApi_DMX_SectReset(u8VdFid) == DMX_FILTER_STATUS_ERROR)
    {
        printf("Failed to MApi_DMX_SectReset\n");
    }
    if(MApi_DMX_SectReset(u8AuFid) == DMX_FILTER_STATUS_ERROR)
    {
        printf("Failed to MApi_DMX_SectReset\n");
    }

    /*START the filter ============================================================*/
    if(MApi_DMX_Start(u8VdFid) == DMX_FILTER_STATUS_ERROR)
    {
        printf("Failed to MApi_DMX_Start\n");
    }
    if(MApi_DMX_Start(u8AuFid) == DMX_FILTER_STATUS_ERROR)
    {
        printf("Failed to MApi_DMX_Start\n");
    }

    if(u16TimeoutMilliSec != MSAPI_DMX_TIMEOUT_INFINITE)
    {
        u32TimerEnd = msAPI_Timer_GetTime0() + u16TimeoutMilliSec;
    }

    //u32Time1 = msAPI_Timer_GetTime0();

    if (bEnPesScramble)
    {
        //about 400ms
        u8TsNonScramCount = NON_SCRAMBLE_CHECK_COUNT;
    }
    else
    {
        //about 200ms
        u8TsNonScramCount = NON_TS_SCRAMBLE_CHECK_COUNT;
    }

    while (TRUE)
    {
        //check timout
        if(u16TimeoutMilliSec != MSAPI_DMX_TIMEOUT_INFINITE)
        {
            if(msAPI_Timer_GetTime0() > u32TimerEnd)
            {
                DMX_SC_DBG(printf("Filter Timeout: Cur=%u, End=%ld\n", (unsigned int)MsOS_GetSystemTime(), u32TimerEnd));
                u32TimerEnd = msAPI_Timer_GetTime0() + u16TimeoutMilliSec;
                enSecFltStatus = MSAPI_DMX_FILTER_STATUS_TIMEOUT;
            }
            else
            {
                //[1] check TS scrambling flag
                if (MApi_DMX_Get_TsScmbSts(u8VdFid, &u8Scramble) == DMX_FILTER_STATUS_ERROR)
                {
                    DMX_SC_DBG(printf("Failed to MApi_DMX_Get_TsScmbSts V\n"));
                    u8VideoTsNonScram = 0;
                    u8VideoTsScram = 0;
                }
                else
                {
                    //printf("u8Scramble = 0x%bx\r\n", u8Scramble);
                    if (u16VideoPID == 0)
                    {
                        u8VideoTsNonScram = NON_SCRAMBLE_CHECK_COUNT;
                        u8VideoTsScram = 0;
                    }
                    else if ((u8Scramble&0x0F) >= TS_SCRAMBLE_THRESHOLD)
                    {
                        u8VideoTsScram = SCRAMBLE_CHECK_COUNT;
                        u8VideoTsNonScram = 0;
                    }
                    else
                    {
                        u8VideoTsNonScram++;
                        u8VideoTsScram = 0;
                        if ((u8Scramble == 0) && (u8VideoTsNonScram >= u8TsNonScramCount))
                        {
                            u8VideoTsScram = SCRAMBLE_CHECK_COUNT;
                            u8VideoTsNonScram = 0;
                        }
                    }
                }

                if ((MApi_DMX_Get_TsScmbSts(u8AuFid, &u8Scramble) == DMX_FILTER_STATUS_ERROR))
                {
                    DMX_SC_DBG(printf("Failed to MApi_DMX_Get_TsScmbSts A\n"));
                    u8AudioTsNonScram = 0;
                    u8AudioTsScram = 0;
                }
                else
                {
                    //printf("u8Scramble = 0x%bx\n", u8Scramble);
                    if (u16AudioPID == 0)
                    {
                        u8AudioTsNonScram = NON_SCRAMBLE_CHECK_COUNT;
                        u8AudioTsScram = 0;
                    }
                    else if ((u8Scramble&0x0F) >= TS_SCRAMBLE_THRESHOLD)
                    {
                        u8AudioTsScram = SCRAMBLE_CHECK_COUNT;
                        u8AudioTsNonScram = 0;
                    }
                    else
                    {
                        u8AudioTsNonScram++;
                        u8AudioTsScram = 0;
                        if ((u8Scramble == 0) && (u8AudioTsNonScram >= u8TsNonScramCount))
                        {
                            u8AudioTsScram = SCRAMBLE_CHECK_COUNT;
                            u8AudioTsNonScram = 0;
                        }
                    }
                }

                //[2] check PES scrambling flag
                if (bEnPesScramble)
                {
                    if (MApi_DMX_Get_PesScmbSts(u8VdFid, &u8Scramble) == DMX_FILTER_STATUS_ERROR)
                    {
                        DMX_SC_DBG(printf("Failed to MApi_DMX_Get_PesScmbSts V\n"));
                        u8VideoPesScram = 0;
                        u8VideoPesNonScram =0;
                    }
                    else
                    {
                        //printf("u8Scramble = 0x%bx\n", u8Scramble);
                        if (u16VideoPID == 0)
                        {
                            u8VideoPesNonScram = NON_SCRAMBLE_CHECK_COUNT;
                            u8VideoPesScram = 0;
                        }
                        else if ((u8Scramble&0x0F) >= PES_SCRAMBLE_THRESHOLD)
                        {
                            u8VideoPesScram = SCRAMBLE_CHECK_COUNT;
                            u8VideoPesNonScram = 0;
                        }
                        else
                        {
                            u8VideoPesNonScram++;
                            u8VideoPesScram = 0;
                            if ((u8Scramble == 0) && (u8VideoPesNonScram >= NON_SCRAMBLE_CHECK_COUNT))
                            {
                                u8VideoPesScram = SCRAMBLE_CHECK_COUNT;
                                u8VideoPesNonScram = 0;
                            }
                        }
                    }

                    if (MApi_DMX_Get_PesScmbSts(u8AuFid, &u8Scramble) == DMX_FILTER_STATUS_ERROR)
                    {
                        DMX_SC_DBG(printf("Failed to MApi_DMX_Get_PesScmbSts A\n"));
                        u8AudioPesScram = 0;
                        u8AudioPesNonScram =0;
                    }
                    else
                    {
                        //printf("u8Scramble = 0x%bx\n", u8Scramble);
                        if (u16AudioPID == 0)
                        {
                            u8AudioPesNonScram = NON_SCRAMBLE_CHECK_COUNT;
                            u8AudioPesScram = 0;
                        }
                        else if ((u8Scramble&0x0F) >= PES_SCRAMBLE_THRESHOLD)
                        {
                            u8AudioPesScram = SCRAMBLE_CHECK_COUNT;
                            u8AudioPesNonScram = 0;
                        }
                        else
                        {
                            u8AudioPesNonScram++;
                            u8AudioPesScram = 0;
                            if ((u8Scramble == 0) && (u8AudioPesNonScram >= NON_SCRAMBLE_CHECK_COUNT))
                            {
                                u8AudioPesScram = SCRAMBLE_CHECK_COUNT;
                                u8AudioPesNonScram = 0;
                            }
                        }
                    }
                }


                //check leave condition
                if (bEnPesScramble)
                {
                    //check TS scrambling condition
                    if ((u8VideoTsNonScram >= NON_SCRAMBLE_CHECK_COUNT) && (u8AudioTsNonScram >= NON_SCRAMBLE_CHECK_COUNT)
                        && !((u8VideoPesScram >= SCRAMBLE_CHECK_COUNT) || (u8AudioPesScram >= SCRAMBLE_CHECK_COUNT)))
                    {
                        enScramSrc = MSAPI_DMX_SCRAMBLING_SOURCE_NONE;
                        break;
                    }
                    else if ((u8VideoTsScram >= SCRAMBLE_CHECK_COUNT) || (u8AudioTsScram >= SCRAMBLE_CHECK_COUNT))
                    {
                        if ((u8VideoTsScram >= SCRAMBLE_CHECK_COUNT) && (u8AudioTsScram >= SCRAMBLE_CHECK_COUNT))
                        {
                            enScramSrc = (MSAPI_DMX_SCRAMBLING_SOURCE_TS_VIDEO | MSAPI_DMX_SCRAMBLING_SOURCE_TS_AUDIO);
                            break;
                        }
                        else if ((u8VideoTsScram >= SCRAMBLE_CHECK_COUNT) && (u8AudioTsNonScram >= NON_SCRAMBLE_CHECK_COUNT))
                        {
                            enScramSrc = MSAPI_DMX_SCRAMBLING_SOURCE_TS_VIDEO;
                            break;
                        }
                        else if ((u8VideoTsNonScram >= NON_SCRAMBLE_CHECK_COUNT) && (u8AudioTsScram >= SCRAMBLE_CHECK_COUNT))
                        {
                            enScramSrc = MSAPI_DMX_SCRAMBLING_SOURCE_TS_AUDIO;
                            break;
                        }
                    }

                    //check PES scrambling condition
                    if ((u8VideoPesNonScram >= NON_SCRAMBLE_CHECK_COUNT) && (u8AudioPesNonScram >= NON_SCRAMBLE_CHECK_COUNT)
                        && !((u8VideoTsScram >= SCRAMBLE_CHECK_COUNT) || (u8AudioTsScram >= SCRAMBLE_CHECK_COUNT)))
                    {
                        enScramSrc = MSAPI_DMX_SCRAMBLING_SOURCE_NONE;
                        break;
                    }
                    else if ((u8VideoPesScram >= SCRAMBLE_CHECK_COUNT) || (u8AudioPesScram >= SCRAMBLE_CHECK_COUNT))
                    {
                        if ((u8VideoPesScram >= SCRAMBLE_CHECK_COUNT) && (u8AudioPesScram >= SCRAMBLE_CHECK_COUNT))
                        {
                            enScramSrc = (MSAPI_DMX_SCRAMBLING_SOURCE_PES_VIDEO | MSAPI_DMX_SCRAMBLING_SOURCE_PES_AUDIO);
                            break;
                        }
                        else if ((u8VideoPesScram >= SCRAMBLE_CHECK_COUNT) && (u8AudioPesNonScram >= NON_SCRAMBLE_CHECK_COUNT))
                        {
                            enScramSrc = MSAPI_DMX_SCRAMBLING_SOURCE_PES_VIDEO;
                            break;
                        }
                        else if ((u8VideoPesNonScram >= NON_SCRAMBLE_CHECK_COUNT) && (u8AudioPesScram >= SCRAMBLE_CHECK_COUNT))
                        {
                            enScramSrc = MSAPI_DMX_SCRAMBLING_SOURCE_PES_AUDIO;
                            break;
                        }
                    }
                }
                else
                {
                    //check TS scrambling condition
                    if ((u8VideoTsNonScram >= NON_TS_SCRAMBLE_CHECK_COUNT) && (u8AudioTsNonScram >= NON_TS_SCRAMBLE_CHECK_COUNT))
                    {
                        enScramSrc = MSAPI_DMX_SCRAMBLING_SOURCE_NONE;
                        break;
                    }
                    else if ((u8VideoTsScram >= SCRAMBLE_CHECK_COUNT) || (u8AudioTsScram >= SCRAMBLE_CHECK_COUNT))
                    {
                        if ((u8VideoTsScram >= SCRAMBLE_CHECK_COUNT) && (u8AudioTsScram >= SCRAMBLE_CHECK_COUNT))
                        {
                            enScramSrc = (MSAPI_DMX_SCRAMBLING_SOURCE_TS_VIDEO | MSAPI_DMX_SCRAMBLING_SOURCE_TS_AUDIO);
                            break;
                        }
                        else if ((u8VideoTsScram >= SCRAMBLE_CHECK_COUNT) && (u8AudioTsNonScram >= NON_TS_SCRAMBLE_CHECK_COUNT))
                        {
                            enScramSrc = MSAPI_DMX_SCRAMBLING_SOURCE_TS_VIDEO;
                            break;
                        }
                        else if ((u8VideoTsNonScram >= NON_TS_SCRAMBLE_CHECK_COUNT) && (u8AudioTsScram >= SCRAMBLE_CHECK_COUNT))
                        {
                            enScramSrc = MSAPI_DMX_SCRAMBLING_SOURCE_TS_AUDIO;
                            break;
                        }
                    }
                }

                msAPI_Timer_Delayms(1);
            }
        }

        /*timeout ===============================================================*/
        if (enSecFltStatus == MSAPI_DMX_FILTER_STATUS_TIMEOUT)
        {
            DMX_SC_DBG(printf("MSAPI_DMX_SCRAMBLING_SOURCE_TIMEOUT !!!\n"));
            enScramSrc = MSAPI_DMX_SCRAMBLING_SOURCE_TIMEOUT;

            if (u8VideoTsScram >= SCRAMBLE_CHECK_COUNT)
            {
                enScramSrc |= MSAPI_DMX_SCRAMBLING_SOURCE_TS_VIDEO;
            }
            if (u8AudioTsScram >= SCRAMBLE_CHECK_COUNT)
            {
                enScramSrc |= MSAPI_DMX_SCRAMBLING_SOURCE_TS_AUDIO;
            }

            if (bEnPesScramble)
            {
                if (u8VideoPesScram >= SCRAMBLE_CHECK_COUNT)
                {
                    enScramSrc |= MSAPI_DMX_SCRAMBLING_SOURCE_PES_VIDEO;
                }
                if (u8AudioPesNonScram >= SCRAMBLE_CHECK_COUNT)
                {
                    enScramSrc |= MSAPI_DMX_SCRAMBLING_SOURCE_PES_AUDIO;
                }
            }
            break;
        }
    }

    //printf("> time = [%lu] \r\n", msAPI_Timer_DiffTimeFromNow(u32Time1));

    /*STOP the filter =============================================================*/
    for (i = 0; i < MSAPI_DMX_MAX_FILTER_NUMBER; i++)
    {
        if (_DmxTsFilter[i].bUsed && _DmxTsFilter[i].u8FltID == u8VdFid)
        {
            _DmxTsFilter[i].bUsed=FALSE;
            _DmxTsFilter[i].pfNotify=NULL;
            MApi_DMX_Stop(u8VdFid);
			MApi_DMX_Close(u8VdFid);
        }
        if (_DmxTsFilter[i].bUsed && _DmxTsFilter[i].u8FltID == u8AuFid)
        {
            _DmxTsFilter[i].bUsed=FALSE;
            _DmxTsFilter[i].pfNotify=NULL;
            MApi_DMX_Stop(u8AuFid);
			MApi_DMX_Close(u8AuFid);
        }
    }

    printf(">>> enScramSrc=%d\r\n", enScramSrc);

    return enScramSrc;
}

#endif

