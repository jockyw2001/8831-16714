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

#define MAPP_EPGDB_A_C
////////////////////////////////////////////////////////////////////////////////
/// @file MApp_EpgDB_A.c
/// @author MStar Semiconductor Inc.
/// @brief initial settings and management functions of EPG database for APP layer
////////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
/*                              Header Files                                 */
/*****************************************************************************/
// C Library
#include <string.h>
#include <stdio.h>
#include "Board.h"

// Global Layer
#include "sysinfo.h"

// API Layer
#include "msAPI_MIU.h"
#include "msAPI_Timer.h"

// AP Layer
#include "MApp_GlobalVar.h"
#include "MApp_RestoreToDefault.h"
#include "MApp_ChannelProc_ATSC.h"
#include "MApp_Psip.h"
#include "MApp_EpgDB_ATSC.h"
#include "MApp_SaveData.h"
#include "MApp_DataBase_ATSC.h"


extern U32 g_u32StreamTime;
/*****************************************************************************/
/*                                 Macro                                     */
/*****************************************************************************/
// Debug message
#define EPGDB_LOADETT      0x01
#define EPGDB_SAVEETT      0x02
#define EPGDB_LOADEVENT     0x04
#define EPGDB_SAVEEVENT     0x08
#define EPGDB_LOADTITLE     0x10
#define EPGDB_SAVETITLE     0x20
#define EPGDB_CUREVENT      0x40
#define EPGDB_RESET         0x80

#define EPGDB_DEBUG         0x00

#if     (EPGDB_DEBUG)
#define EPGDB_DBG( flag, s )    { if (EPGDB_DEBUG & flag)   {printf s;} }
#else
#define EPGDB_DBG( flag, s )
#endif

#define GetEventAddress(x, y, z)    ((U32)(EVENTDB_EVENTBUF_START_ADR + ((U32)x)*MAX_TBL_NUM*MAX_EVENT_IN_TBL*sizeof(MS_EPG_EVENT)+((U32)y)*MAX_EVENT_IN_TBL*sizeof(MS_EPG_EVENT) + ((U32)z)*sizeof(MS_EPG_EVENT)))

/*****************************************************************************/
/*                             Local Variables                               */
/*****************************************************************************/
static MS_EPG_EVENT stCurrentEvent;
static BOOLEAN bEPGDB_Reset;

/*****************************************************************************/
/*                               Functions                                   */
/*****************************************************************************/
/***         Funtion to load/save event data and short descriptior         ***/
/*****************************************************************************/
void MApp_EpgDB_LoadEvent(U16 u16VchIdx, U8 u8EitIdx, U8 u8EventIdx, MS_EPG_EVENT *pDstEvent)
{
    U32 u32_src;
    u32_src = GetEventAddress(u16VchIdx, u8EitIdx, u8EventIdx);

    EPGDB_DBG(EPGDB_LOADEVENT, ("\r\n EPG >> LoadEvent: VchIdx = %u\t Src[0x%LX] --> Dst[0x%lX] len = 0x%X\n", u16VchIdx, u32_src, (U32)pDstEvent, (U16) sizeof(MS_EPG_EVENT)));

    memcpy((U8*)(pDstEvent),(U8*)(_PA2VA(u32_src)),(sizeof(MS_EPG_EVENT)));
}
/*****************************************************************************/
BOOLEAN MApp_EpgDB_SaveEvent(U16 u16VchIdx, U8 u8EitIdx, U8 u8EventIdx, MS_EPG_EVENT *pSrcEvent)
{
    U32 u32_dst;
    if(u16VchIdx >= EPG_VCH_IN_DB || u8EitIdx >= MAX_TBL_NUM || u8EventIdx >= MAX_EVENT_IN_TBL)
    {
        return FALSE;
    }

    u32_dst = GetEventAddress(u16VchIdx, u8EitIdx, u8EventIdx);

    EPGDB_DBG(EPGDB_SAVEEVENT, ("\r\n EPG >> SaveEvent: VchIdx = %u\t Src[0x%lX] --> Dst[0x%LX] len = 0x%X\n", u16VchIdx, (U32)pSrcEvent, u32_dst, (U16) sizeof(MS_EPG_EVENT)));

    memcpy((U8*)_PA2VA(u32_dst),(U8*)pSrcEvent,(sizeof(MS_EPG_EVENT)));
    return TRUE;
}


/*****************************************************************************/
BOOLEAN MApp_EpgDB_DeleteEvent(U16 u16VchIdx, U8 u8EitIdx, U8 u8EventIdx)
{
    //Delete one event need to move events which after deleted event location
    //EX: If Eit-0 have 5 events, delete 3th event need to move the 4, 5th event into the 3, 4th event's location
    U8 u8i = 0;
    MS_EPG_EVENT stTempEvent;
    MS_EPG_VCH_BUF  *pVch;
    pVch = &astEpgDbVchBuf[0];
    memset(&stTempEvent, 0, sizeof(MS_EPG_EVENT));

    //exception case:
    if(u16VchIdx >= EPG_VCH_IN_DB || u8EitIdx >= MAX_TBL_NUM || u8EventIdx >= MAX_EVENT_IN_TBL)
    {
        return FALSE;
    }

    for(u8i = u8EventIdx; u8i< (pVch->au8CntEvent_InTbl[u8EitIdx]); u8i++)
    {
        MApp_EpgDB_LoadEvent(u16VchIdx, u8EitIdx, u8i+1, &stTempEvent); //i+1
        MApp_EpgDB_SaveEvent(u16VchIdx, u8EitIdx, u8i, &stTempEvent);   //replace i
    }
    //add empty event at the end
    memset(&stTempEvent, 0, sizeof(MS_EPG_EVENT));

    MApp_EpgDB_SaveEvent(u16VchIdx, u8EitIdx, u8i, &stTempEvent);
    //EPGDB_DBG(EPGDB_LOADEVENT, ("\r\n EPG >> LoadEvent: VchIdx = %u\t Src[0x%LX] --> Dst[0x%lX] len = 0x%X\n", u16VchIdx, u32_src, (U32)pDstEvent, (U16) sizeof(MS_EPG_EVENT)));
    return TRUE;
}


/*****************************************************************************/
BOOLEAN MApp_EpgDB_InsertEvent(U16 u16VchIdx, U8 u8EitIdx, U8 u8EventIdx, MS_EPG_EVENT *pSrcEvent)
{
    //insert one event need to move events which after inserted event location
    //EX: If Eit-0 have 5 events, insert an event at 3th event location, need to move 3,4,5 event to 4, 5, location (original 5th event will be disappear)
    //exception case: the last event at the end will be discard
    U8 u8i = 0;
    MS_EPG_EVENT stPrevEvent;
    MS_EPG_VCH_BUF  *pVch;
    pVch = &astEpgDbVchBuf[0];
    memset(&stPrevEvent, 0, sizeof(MS_EPG_EVENT));

    //exception case:
    if(u16VchIdx >= EPG_VCH_IN_DB || u8EitIdx >= MAX_TBL_NUM || u8EventIdx >= MAX_EVENT_IN_TBL)
    {
        return FALSE;
    }

    for(u8i = (pVch->au8CntEvent_InTbl[u8EitIdx]-1); u8i>(u8EventIdx); u8i--)
    {
        MApp_EpgDB_LoadEvent(u16VchIdx, u8EitIdx, u8i, &stPrevEvent); //i
        MApp_EpgDB_SaveEvent(u16VchIdx, u8EitIdx, u8i+1, &stPrevEvent); //replace i+1
    }
    MApp_EpgDB_SaveEvent(u16VchIdx, u8EitIdx, u8EventIdx, pSrcEvent);
    pVch->au8CntEvent_InTbl[u8EitIdx]++;
    return TRUE;
}




/*****************************************************************************/
void  MApp_EpgDB_LoadEventTitle(U16 u16VchIdx, U32 u32srcaddr, MS_EPG_EVENT_TITILE* pSrcEventTitle)
{
    U8* temp;

    u32srcaddr = EPGSTR_EITTITLE_START_ADR + (U32)u16VchIdx * (MAX_EIT_TITLE_LEN_OF_STR_POOL) + u32srcaddr;
    temp = (U8*)_PA2VA(u32srcaddr);
    pSrcEventTitle->u16Title_length = (((U16)*temp) | (U16)((*(temp+1))<<8));

    memcpy((U8*)(pSrcEventTitle->pu8Title_content),(U8*)(_PA2VA(u32srcaddr+sizeof(pSrcEventTitle->u16Title_length))),pSrcEventTitle->u16Title_length);

    EPGDB_DBG(EPGDB_LOADTITLE, ("LoadEventTitle:u16VchIdx = %d, u32srcaddr= %d,pSrcEventTitle->u16Title_length = %d,(pSrcEventTitle->pu8Title_content) = %s\n\n", u16VchIdx, u32srcaddr,pSrcEventTitle->u16Title_length,(U8*)(pSrcEventTitle->pu8Title_content)));
}

/*****************************************************************************/
void MApp_EpgDB_SaveEventTitle(U16 u16VchIdx, U32 u32dstaddr, MS_EPG_EVENT_TITILE* pSrcEventTitle)
{
    u32dstaddr = EPGSTR_EITTITLE_START_ADR + (U32)u16VchIdx * (MAX_EIT_TITLE_LEN_OF_STR_POOL) + u32dstaddr;

    EPGDB_DBG(EPGDB_SAVETITLE, ("SaveEventTitle:u16VchIdx = %d, u32dstaddr= %d,(pSrcEventTitle->pu8Title_content) = %s\n\n", u16VchIdx, u32dstaddr,(U8*)(pSrcEventTitle->pu8Title_content)));

    memcpy((U8*)_PA2VA(u32dstaddr),(U8*)(&pSrcEventTitle->u16Title_length),sizeof(pSrcEventTitle->u16Title_length));
    memcpy((U8*)_PA2VA(u32dstaddr+sizeof(pSrcEventTitle->u16Title_length)),(U8*)(pSrcEventTitle->pu8Title_content),pSrcEventTitle->u16Title_length);
}

/*****************************************************************************/
void MApp_EpgDB_LoadEventETT(U16 u16VchIdx, U32 u32srcaddr, MS_EPG_EVENT_ETT* pSrcEventETT)
{
    U8* temp;

    u32srcaddr = EPGSTR_ETT_START_ADR + (U32)u16VchIdx * (MAX_ETT_LEN_OF_STR_POOL) + u32srcaddr;
    temp = (U8*)_PA2VA(u32srcaddr);
    pSrcEventETT->u16ETT_length = (((U16)*temp) | (U16)((*(temp+1))<<8));

    EPGDB_DBG(EPGDB_LOADETT, ("LoadEventETT:u16VchIdx = %d, u32srcaddr= %d\n\n", u16VchIdx, u32srcaddr));

    memcpy((U8*)(pSrcEventETT->pu8ETT_content),(U8*)(_PA2VA(u32srcaddr+sizeof(pSrcEventETT->u16ETT_length))),(U32)pSrcEventETT->u16ETT_length);
}

/*****************************************************************************/
void MApp_EpgDB_SaveEventETT(U16 u16VchIdx, U32 u32dstaddr, MS_EPG_EVENT_ETT* pSrcEventETT)
{
    u32dstaddr = EPGSTR_ETT_START_ADR + (U32)u16VchIdx * (MAX_ETT_LEN_OF_STR_POOL) + u32dstaddr;

    EPGDB_DBG(EPGDB_SAVEETT, ("SaveEventETT:u16VchIdx = %d, u32dstaddr= %d\n\n", u16VchIdx, u32dstaddr));

    memcpy((U8*)_PA2VA(u32dstaddr),(U8*)(&pSrcEventETT->u16ETT_length),sizeof(pSrcEventETT->u16ETT_length));
    memcpy((U8*)_PA2VA(u32dstaddr+sizeof(pSrcEventETT->u16ETT_length)),(U8*)(pSrcEventETT->pu8ETT_content),(U32)pSrcEventETT->u16ETT_length);
}

/***      Funtion to get current event and use in program information      ***/
BOOLEAN MApp_EpgDB_GetCurEvent(MS_EPG_EVENT *pDstEvent)
{
    U8              u8_loop_i,u8_loop_j;
    U8              u8_ui_vch;
    U32             u32StartTime;
    U32             u32EndTime;
    BOOL            bHasFindCureentEvent = FALSE;

    MS_EPG_EVENT    *pEvent;
    MS_EPG_VCH_BUF  *p_vch_buf;
    MS_EPG_EVENT_TITILE pSrcEventTitle;

//#if (EPG_THIS_CH == TRUE)
    u8_ui_vch = 0;
//#else
//  u8_ui_vch = stChSetting.astMainList[MApp_ChanProc_GetCurProgIndex()].u8VirChInfoIdx;
//#endif

    // Get service data
    // Get virtual channel data
    p_vch_buf   = &astEpgDbVchBuf[0];

    for(u8_loop_j = 0; u8_loop_j <MAX_TBL_NUM;u8_loop_j++)
    {
        if(p_vch_buf->au8CntEvent_InTbl[u8_loop_j]==0)//check each Table event exist.
            break;

        EPGDB_DBG(EPGDB_CUREVENT, ("[Table] = %d\n", u8_loop_j));

        // Find current event in current service channel
        for (u8_loop_i = 0; u8_loop_i < p_vch_buf->au8CntEvent_InTbl[u8_loop_j]; u8_loop_i++)
        {
            MApp_EpgDB_LoadEvent(u8_ui_vch, u8_loop_j, u8_loop_i, &stCurrentEvent);
            pEvent = &stCurrentEvent;
            u32StartTime = pEvent->start_time - DEFAULT_SYSTEM_TIME - u8GpsUtcOffset;
            u32EndTime = u32StartTime + EPG_EVENT_LENGTH(pEvent->length[0], pEvent->length[1], pEvent->length[2]);
            //printf("[EpgDB] Loop #%d >> g_u32StreamTime = %x, u32StartTime = %x, u32EndTime = %x\n", u8_loop_i, g_u32StreamTime, u32StartTime, u32EndTime);

            // Corresponding event >> Event end time > Page start time  AND Event start < Page end time
            if ((u32StartTime <= g_u32StreamTime) && (u32EndTime > g_u32StreamTime))
            {
                g_stUiEvent = stCurrentEvent;
                memcpy(pDstEvent, pEvent, sizeof(MS_EPG_EVENT));

                // New Event
                if ((stEpgETT.u16SourceID != stEpgDBInfo.au16SrcID[u8_ui_vch]) || ((stEpgETT.u16EventID >> 2) != pDstEvent->event_id))
                {
                    if (stEpgETT.u8FID != 0 && (stEpgETT.u8FID != MSAPI_DMX_INVALID_FLT_ID))
                    {
                        msAPI_DMX_CloseFilter(stEpgETT.u8FID);
                    }

                    stEpgDBInfo.fIsEttRxOk      = FALSE;
                    stEpgDBInfo.fIsEttTimeout   = FALSE;

                    stEpgETT.u16SourceID        = stEpgDBInfo.au16SrcID[u8_ui_vch];
                    stEpgETT.u16EventID         = (pDstEvent->event_id << 2)  | 0x02;
                    stEpgETT.u8Tbl              = 0;
                    stEpgETT.u8FID              = MSAPI_DMX_INVALID_FLT_ID;

                    // Set ETT Monitor
                    MApp_Dmx_ETT_Monitor(&stEpgETT);
                }

                // Load focus event title from sdram to Short, which starts with string length
                au8EpgUiBuf[0] =0;
                pSrcEventTitle.pu8Title_content = au8EpgUiBuf;
                MApp_EpgDB_LoadEventTitle(u8_ui_vch, pEvent->u16DbTitlePos, &pSrcEventTitle);
                au8EpgUiBuf[ pSrcEventTitle.u16Title_length ] = '\0';
                au8EpgUiBuf[ pSrcEventTitle.u16Title_length+1 ] = '\0';
                fSearchEventTitlefromEIT = TRUE;

                EPGDB_DBG(EPGDB_CUREVENT, ("[EpgDB] Find SrcIdx = %d, Source ID= %d, Event ID = %x >> %s, [0]=%bu, len=%u\r\n", u8_ui_vch, stEpgDBInfo.au16SrcID[u8_ui_vch],(U16)pEvent->event_id, &au8EpgUiBuf[0], au8EpgUiBuf[0], pSrcEventTitle.u16Title_length));
                bHasFindCureentEvent = TRUE;
                break;
            }
        }

        if(bHasFindCureentEvent == TRUE)
        {
            break;
        }
    }

    if(bHasFindCureentEvent == TRUE)
    {
        //check EIT rating
        if(stCurrentEvent.stRating.fRatingRxIsOK)  //have eit rating
        {
            return TRUE;
        }
        else
        {
            if(fSearchRatingfromPMT)
            {
                memcpy(&g_stUiEvent.stRating, &stPMTRatinginfo, sizeof(MS_EPG_RATING));
                 EPGDB_DBG(EPGDB_CUREVENT, ("[EpgDB] Get event from PMT %d, %d\r\n", g_stUiEvent.stRating.fRatingRxIsOK, g_stUiEvent.stRating.u8TVRatingForEntire));
            }
            return TRUE;
        }
    }

    if ((astEpgDbVchMask[u8_ui_vch].fIsInSDRAM != TRUE) && (GETBIT(stEpgDBInfo.u8EitIsReceiving, 0) != TRUE))//If No Eit table
    {
        if(fSearchRatingfromPMT)
        {
            memcpy(&g_stUiEvent.stRating, &stPMTRatinginfo, sizeof(MS_EPG_RATING));
             EPGDB_DBG(EPGDB_CUREVENT, ("[EpgDB] Get event from PMT %d, %d\r\n", g_stUiEvent.stRating.fRatingRxIsOK, g_stUiEvent.stRating.u8TVRatingForEntire));
        }
        return FALSE;
    }

     EPGDB_DBG(EPGDB_CUREVENT, ("[EpgDB] Not Find Match Event\n\n\n"));
    memset(pDstEvent, 0x00, sizeof(MS_EPG_EVENT));
    pDstEvent->event_id = INVALID_EVENT_ID;

    return FALSE;
}
/******************************************************************************/
/// Init EPG database.
/// 1. Set pointer to allocated xdata which is reserved for EPG database
/// 2. Set EIT and ETT Filter ID buffer array to invalid
/******************************************************************************/
void MApp_EpgDB_Init(void)
{
    U8  u8_loop_i;

    if ((EPGBUF_START_ADR + EPG_EVENTBUF_LEN + EPGSTR_EITTITLE_LEN+EPGSTR_ETT_LEN) > (EVENTDB_SDRAM_ADR+EVENTDB_SDRAM_LEN))
   {
      printf("EPG Event total size <<%lx>>\n", (U32)sizeof(MS_EPG_EVENT) *(U32)MAX_EVENT_IN_TBL *(U32)MAX_TBL_NUM);
      printf("EPG Event size <<%d>>\n", (U32)sizeof(MS_EPG_EVENT));
      printf("*******EPG Buffer (0x%lx) > EVENTDB_SDRAM_LEN(0x%lx)***********\n", (EPG_EVENTBUF_LEN + EPGSTR_EITTITLE_LEN+EPGSTR_ETT_LEN),EVENTDB_SDRAM_LEN);
      printf("*******EPG buffer size not enough!!!*********\n");
      //while(1);
   }

    // Initialize Filter ID, event counts in segment and Table Version Number
    for (u8_loop_i = 0; u8_loop_i < MAX_TBL_NUM; u8_loop_i++)
    {
        stEpgDBInfo.au8FID[u8_loop_i] = MSAPI_DMX_INVALID_FLT_ID;
        stEpgDBInfo.au8EttFID[u8_loop_i] = MSAPI_DMX_INVALID_FLT_ID;
    }
#if (EIT_VN_CHANGE_FOR_RRT==TRUE)
    stEpgDBInfo.u8FID_EitMonitorForRRT = MSAPI_DMX_INVALID_FLT_ID;
#endif

    stEpgETT.u8FID = MSAPI_DMX_INVALID_FLT_ID;
    bEPGDB_Reset = FALSE;
}

void MApp_EpgDB_ContentInit(MS_EPG_VCH_BUF* pVch)
{
    MS_EPG_EVENT_TITILE pSrcEventTitle;

    pVch->fIsFirstTime = TRUE;

    pVch->u32MinStartTime = 0xFFFFFFFF;

    // Copy Overflow text to DB
    pSrcEventTitle.u16Title_length = 0x08;
    strcpy((char *)(&pu8EpgString[0]), "Overflow");
    pSrcEventTitle.pu8Title_content = &pu8EpgString[0];
    MApp_EpgDB_SaveEventTitle(0, 0, &pSrcEventTitle);
    pVch->u16DBOffset += 10;
}
/******************************************************************************/
/// Reset EPG database related structures and variables
/// 1. Close all EIT filter and set all EIT/ETT filter ID to invalid
/// 2. Set astEpgDbVchBuf, astEpgDbVchMask, stEpgETT and stEpgDBInfo structure
///    to default value
/// 3. Store the source id of current physical channel to
///    stEpgDBInfo.au16SrcID[]
/******************************************************************************/
void MApp_EpgDB_Reset(void)
{
    U8 u8_loop_i;

    for (u8_loop_i = 0; u8_loop_i < MAX_TBL_NUM; u8_loop_i++)
    {
        if (stEpgDBInfo.au8FID[u8_loop_i] != MSAPI_DMX_INVALID_FLT_ID)
        {
            msAPI_DMX_CloseFilter(stEpgDBInfo.au8FID[u8_loop_i]);
        }
        if (stEpgDBInfo.au8EttFID[u8_loop_i] != MSAPI_DMX_INVALID_FLT_ID)
        {
            msAPI_DMX_CloseFilter(stEpgDBInfo.au8EttFID[u8_loop_i]);
        }
    }

#if (EIT_VN_CHANGE_FOR_RRT==TRUE)
    if (stEpgDBInfo.u8FID_EitMonitorForRRT != MSAPI_DMX_INVALID_FLT_ID)
    {
        msAPI_DMX_CloseFilter(stEpgDBInfo.u8FID_EitMonitorForRRT);
    }
#endif

    memset(astEpgDbVchBuf, 0x00, sizeof(astEpgDbVchBuf));
    memset(astEpgDbVchMask, 0x00, sizeof(astEpgDbVchMask));
    u8EITTimeOut = 0;
    u8ETTTimeOut = 0;
    bETTStarNextReceive = 0;bEpgEventSorted = FALSE;
    // Clear stEpgDBInfo except stEpgDBInfo.au16SrcID[]
    memset(&stEpgDBInfo, 0x00, OFFSETOF(MS_EPG_DB_INFO, au16SrcID));
    stEpgDBInfo.u8MgtVersionNumber = stMGT.version_number;

    // Initialize Filter ID, event counts in segment and Table Version Number
    for (u8_loop_i = 0; u8_loop_i < MAX_TBL_NUM; u8_loop_i++)
    {
        stEpgDBInfo.au8FID[u8_loop_i] = MSAPI_DMX_INVALID_FLT_ID;
        stEpgDBInfo.au8EttFID[u8_loop_i] = MSAPI_DMX_INVALID_FLT_ID;
    }

#if (EIT_VN_CHANGE_FOR_RRT==TRUE)
    stEpgDBInfo.u8FID_EitMonitorForRRT = MSAPI_DMX_INVALID_FLT_ID;
#endif

    if (stEpgETT.u8FID != MSAPI_DMX_INVALID_FLT_ID)
    {
        msAPI_DMX_CloseFilter(stEpgETT.u8FID);
        EPGDB_DBG(EPGDB_RESET, ("Reset >> Close ETT Fiter #%d\n", stEpgETT.u8FID));

        stEpgETT.u8FID = MSAPI_DMX_INVALID_FLT_ID;
    }

    stEpgETT.u16EventID = 0xFFFF;

    // Initialized Epg DB parameters
    stEpgDBInfo.u8CntSourceNum = stChSetting.astPhysicalCh[stChSetting.astMainList[MApp_ChanProc_GetCurProgIndex()].u8PhysicalChIdx].u8NumOfVirCh;

    if (stEpgDBInfo.u8CntSourceNum > MIN(EPG_VCH_IN_BUF, MAX_VC_PER_PHYSICAL))
    {
        stEpgDBInfo.u8CntSourceNum = MIN(EPG_VCH_IN_BUF, MAX_VC_PER_PHYSICAL);
    }
    g_bIsFastEtt = FALSE;
    bEPGDB_Reset = TRUE;
}

BOOLEAN MApp_EpgDB_GetResetStatus(void)
{
    return bEPGDB_Reset;
}

void MApp_EpgDB_SetResetStatus(BOOLEAN bReset)
{
    bEPGDB_Reset = bReset;
}


#if 0
U8 MApp_EpgDB_GetCurProgramEventIndex(void)
{
    U8 u8_loop_i;
    U8 u8_ui_vch;
    U32 u32StartTime;
    U32 u32EndTime;
    MS_EPG_EVENT    *pEvent;
    MS_EPG_VCH_BUF  *p_vch_buf;

    u8_ui_vch = 0;
    // Get service data
    // Get virtual channel data
    p_vch_buf   = &astEpgDbVchBuf[0];

    if ((astEpgDbVchMask[u8_ui_vch].fIsInSDRAM !=  TRUE) && (GETBIT(stEpgDBInfo.u8EitRxOK, 0) != TRUE))
    {
        return 0;
    }

    // Find current event in current service channel
    for (u8_loop_i = 0; u8_loop_i < p_vch_buf->au8CntEvent_InTbl[0]; u8_loop_i++)
    {
        MApp_EpgDB_LoadEvent(u8_ui_vch, 0, u8_loop_i, &stCurrentEvent);
        pEvent = &stCurrentEvent;
        u32StartTime = pEvent->start_time - DEFAULT_SYSTEM_TIME - u8GpsUtcOffset;
        u32EndTime = u32StartTime + EPG_EVENT_LENGTH(pEvent->length[0], pEvent->length[1], pEvent->length[2]);

        // Corresponding event >> Event end time > Page start time  AND Event start < Page end time
        if ((u32StartTime <= g_u32StreamTime) && (u32EndTime > g_u32StreamTime))
        {
            return u8_loop_i;
        }
    }
    return 0;
}
#endif

#undef MAPP_EPGDB_A_C
