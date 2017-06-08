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

#ifndef MAPP_EIT_H
#define MAPP_EIT_H

////////////////////////////////////////////////////////////////////////////////
///
/// @file mapp_eit.h
/// @author MStar Semiconductor Inc.
/// @brief EIT Parsing and management Functions
///
////////////////////////////////////////////////////////////////////////////////

/******************************************************************************/
/*                              Include files                                 */
/******************************************************************************/
#include "mapp_epgdb_public.h"

/******************************************************************************/
/*                                 Macro                                      */
/******************************************************************************/
#ifdef MAPP_EIT_C
#define INTERFACE
#else
#define INTERFACE extern
#endif

#ifndef _PA2VA
#define _PA2VA
#endif

#if (ENABLE_DTV_EPG)
// Features configuration
#define MONITOR_OTHER_EIT       TRUE    // enable to receive EIT OTHER
#define EIT_FOR_DTG_ONLY        TRUE    // enable handle a special case for DTG test

#define NOW                     0
#define NEXT                    1
#define MAX_PF_STRING_LENGTH         (4096*sizeof(U16))

/******************************************************************************/
/*                                 Enum                                       */
/******************************************************************************/
// Total 13 Bytes
typedef struct
{
    U8  u8VerNum;
    U8  u8SecNum;
    U8  u8SecNum_InSeg;
    U16 u16SecNum_InSrv;

    U8  u8SegNum_InSrv;
    U8  u8TblIdx;
    U16 u16SrvIdx;
    U32 u32CrcValue;
} MS_EIT_PARSE_PARAM;

typedef struct
{
    BYTE bDVB          : 1;
    BYTE bEBU          : 1;
    BYTE bReserved     : 6;
}Sub_VALID_INFO;

/******************************************************************************/
/*                                 Structure                                  */
/******************************************************************************/
// Total 530 Bytes
typedef struct EPG_PACKED
{
    U8  short_event_descriptor[MW_MAX_SHORT_EVENT_DESCRIPTOR_LEN];
    U8  extended_event_description[MW_MAX_EXTEND_EVENT_DESCRIPTOR_LEN];

    U8  start_time[5];
    U8  duration[3];

    U8  version_number;
    U8  u8Parental_Control;
#if  1//ENABLE_SBTVD_BRAZIL_APP
    U8  u8Parental_ObjectiveContent;
#endif
    U8  u8Content_nibble_level1 : 4;
    U8  u8Content_nibble_level2 : 4;
    U8  u8PreferredNameId;
    U32 u32PDSD_private_data_specifier;
    U8 guidance_descriptor[MW_MAX_GUIDANCE_DESCRIPTOR_LEN];
    U8 u8CMG_Data;
}MS_EIT_CUR_EVENT_PF;

typedef enum
{
    E_COMPONENT_MPEG_AUDIO       = 0x00,
    E_COMPONENT_AC3_AUDIO        = 0x01,
    E_COMPONENT_AAC_AUDIO        = 0x02,
    E_COMPONENT_DVB_SUBTITLE     = 0x03,
    E_COMPONENT_EBU_SUBTITLE     = 0x04,
    E_COMPONENT_UNSUPPORT        = 0xFF
} E_COMPONENT_TYPE;

typedef struct
{
    BOOL bEnableScheduleExtendEvent;
    BOOL bEnablePVR_CRID;
    U32 u32PF_BufferAddress;
    BOOL (*pfNotify_EIT_Cur_PF)(U8 *pu8Section);
} MS_EIT_INIT_PARAMETER;

/******************************************************************************/
/*                                 Variables                                  */
/******************************************************************************/



/******************************************************************************/
/*                              Function Prototypes                           */
/******************************************************************************/
/* Info Banner ********************************************************************************************/
INTERFACE void MApp_EIT_Init(MS_EIT_INIT_PARAMETER* psInitParameter);
INTERFACE BOOL MApp_EIT_GetPfString(U8 sec, U8 *pdest, U16 u16Shift, U16 u16Size );
INTERFACE BOOL MApp_EIT_Is_Cur_PF_Change(void);
INTERFACE void MApp_EIT_Reset_Cur_PF_Change(void);
INTERFACE void MApp_EIT_Cur_PF_Parse(U8 au8Sec[], U8* pu8FirstSectionNo, U8* pu8LastSectionNo, U8* ver);
INTERFACE U8   MApp_EIT_GetCurParentControl(void);
#if  ENABLE_SBTVD_BRAZIL_APP
INTERFACE U8   MApp_EIT_GetCurParentObjectiveContent(void);
#endif

/* EPG PF ********************************************************************************************/
INTERFACE BOOL MApp_EIT_All_PF_Parse(MS_EIT_PARSE_PARAM* pParse, MW_EN_EPG_PF_SRV_HDR* pPfSrvHdr, U8 au8Sec[]);

/* EPG Schedule ********************************************************************************************/
INTERFACE BOOL MApp_EIT_All_Sche_Parse(MS_EIT_PARSE_PARAM* pParse, MW_EN_EPG_SCHE_SRV_HDR* pSrvScheHdr, U8 pu8Sec4K[]);
INTERFACE void MApp_EIT_All_Sche_ResetFilter( void );




INTERFACE BOOLEAN MApp_EIT_GetCurPFInfo(MS_EIT_CUR_EVENT_PF* pEventInfo);
INTERFACE BOOLEAN MApp_EIT_IsCurPFInfoExist(void);


INTERFACE BOOLEAN MApp_EIT_ResetCurPFInfo(void);
INTERFACE U8 MApp_EIT_GetCurPreferredNameID(void);
INTERFACE BOOLEAN MApp_EIT_FreeCurPFInfo(void);
#endif  //(ENABLE_DTV_EPG)

#undef INTERFACE
#endif /* MAPP_EIT_H */

