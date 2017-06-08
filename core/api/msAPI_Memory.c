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
/// @file msAPI_Memory.h
/// This file includes MStar application interface for memory access.
/// @brief API for memory buffer pool management
/// @author MStar Semiconductor, Inc.
//
////////////////////////////////////////////////////////////////////////////////

#define MSAPI_MEMORY_C

/******************************************************************************/
/*                           Header Files                                     */
/******************************************************************************/

#include <stdio.h>
#include <string.h>
#include "msAPI_Memory.h"
#include "debug.h"

#if 1//ndef MSOS_TYPE_LINUX

/********************************************************************************/
/*                               Functions                                      */
/********************************************************************************/

/******************************************************************************/
/// API for Init memory buffer pool at system boot-up
/******************************************************************************/
void msAPI_Memory_Init(void)
{
    return;
}

/******************************************************************************/
/// API for Allocate memory
/// @param u16Number_of_bytes \b IN: number of bytes to be allocated
/// @param enBufID \b IN: buffer ID
/// @return void *:
///- NULL: FAIL
///- XDATA_DRAM_START_ADDR ~ (XDATA_DRAM_START_ADDR+MEMALLOC_POOL_SIZE): SUCCESS
/******************************************************************************/
void * msAPI_Memory_Allocate(U32 u32Number_of_bytes, EN_BUFFER_ID enBufID)
{
    void * pMemory = NULL;

    pMemory = MsOS_AllocateMemory(u32Number_of_bytes, (MS_U32)enBufID);

    if( pMemory == NULL )
    {
        msDebug_FatalErrorHandler(FATAL_ERR_ID_MEMORY_ALLOC_FAILED, enBufID);
    }

    return pMemory;
}

/******************************************************************************/
/// API for CAllocate memory
/// @param u16Number_of_bytes \b IN: number of bytes to be allocated
/// @param enBufID \b IN: buffer ID
/// @return void *:
///- NULL: FAIL
///- XDATA_DRAM_START_ADDR ~ (XDATA_DRAM_START_ADDR+MEMALLOC_POOL_SIZE): SUCCESS
/******************************************************************************/
void * msAPI_Memory_CAllocate(U16 u16Number_of_Units, U16 u16Number_of_bytes,EN_BUFFER_ID enBufID)
{
    void *ptr = MsOS_AllocateMemory((MS_U32)(u16Number_of_Units*u16Number_of_bytes), (MS_U32)enBufID);

    if( ptr == NULL )
    {
        msDebug_FatalErrorHandler(FATAL_ERR_ID_MEMORY_ALLOC_FAILED, enBufID);
    }
    else //if ( ptr != NULL )
    {
        memset(ptr, 0x00, (MS_U32)(u16Number_of_Units*u16Number_of_bytes));
    }

    return ptr;
}

/******************************************************************************/
/// API for Free allocated memory
/// @param *pFree \b IN: pointer to be released
/// @param enBufID \b IN: buffer ID to be released
/******************************************************************************/
U8 msAPI_Memory_Free(void *pFree, EN_BUFFER_ID enBufID)
{
    BOOLEAN bResult;

    bResult = MsOS_FreeMemory(pFree, (MS_U32)enBufID);

    if (bResult == TRUE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void *msAPI_Memory_ReAllocate(void *pAlloc, U16 newsize, EN_BUFFER_ID enBufID)
{
    return MsOS_ReallocateMemory(pAlloc, (MS_S32)newsize, (MS_S32)enBufID);
}

#else // MSOS_TYPE_LINUX
#include <stdlib.h>

void msAPI_Memory_Init(void)
{

}
inline void * msAPI_Memory_Allocate(U16 u16Number_of_bytes,EN_BUFFER_ID enBufID)
{
    UNUSED(enBufID);
    return malloc(u16Number_of_bytes);
}

void *msAPI_Memory_ReAllocate(void *pAlloc, U16 newsize, EN_BUFFER_ID enBufID)
{
    UNUSED(enBufID);
    if(pAlloc!=NULL)
    {
        return realloc(pAlloc, newsize);
    }
    else
    {
        return NULL;
    }
}

inline U8 msAPI_Memory_Free(void *pFree, EN_BUFFER_ID enBufID)
{
    UNUSED(enBufID);
    if(pFree!=NULL)
    {
        free(pFree);
    }
    return 1;
}

#endif //MSOS_TYPE_LINUX


//void msAPI_Aeon_Disable(void)
//{
//}

#undef MSAPI_MEMORY_C

