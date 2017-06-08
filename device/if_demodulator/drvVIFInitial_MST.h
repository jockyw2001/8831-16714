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
// Copyright (c) 2008-2009 MStar Semiconductor, Inc.
// All rights reserved.
//
// Unless otherwise stipulated in writing, any and all information contained
// herein regardless in any format shall remain the sole proprietary of
// MStar Semiconductor Inc. and be kept in strict confidence
// ("MStar Confidential Information") by the recipient.
// Any unauthorized act including without limitation unauthorized disclosure,
// copying, use, reproduction, sale, distribution, modification, disassembling,
// reverse engineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
////////////////////////////////////////////////////////////////////////////////
#ifndef _DRVVIFINITIAL_MST_H_
#define _DRVVIFINITIAL_MST_H_

#if  (CHIP_FAMILY_TYPE == CHIP_FAMILY_S7)         // T3
#include "drvVIFInitial_MST_T3.h"

#elif (CHIP_FAMILY_TYPE == CHIP_FAMILY_S7LD)   // T4
#include "drvVIFInitial_MST_T4.h"

#elif (CHIP_FAMILY_TYPE == CHIP_FAMILY_S7LA)   // T7
#include "drvVIFInitial_MST_T7.h"

#elif (CHIP_FAMILY_TYPE == CHIP_FAMILY_S7J)     // Janus
#include "drvVIFInitial_MST_Janus.h"

#elif (CHIP_FAMILY_TYPE == CHIP_FAMILY_M10)     // Maria10
#include "drvVIFInitial_MST_Maria10.h"
#elif (CHIP_FAMILY_TYPE == CHIP_FAMILY_EULER)     // Euler
#include "drvVIFInitial_MST_Euler.h"

#elif (CHIP_FAMILY_TYPE == CHIP_FAMILY_EDEN)     // eden
#include "drvVIFInitial_MST_Eden.h"

#elif (CHIP_FAMILY_TYPE == CHIP_FAMILY_NASA)     // nasa
#include "drvVIFInitial_MST_Nasa.h"

#elif (CHIP_FAMILY_TYPE == CHIP_FAMILY_S8)

    #if ((MS_BOARD_TYPE_SEL == BD_MST105B_D01A_S_T12) ||(MS_BOARD_TYPE_SEL == BD_MST105C_D01A_S_T12) || (MS_BOARD_TYPE_SEL == BD_MST105D_D01A_S_T12) || (MS_BOARD_TYPE_SEL == BD_MST116A_D01A_S_T12))
#include "drvVIFInitial_MST_T12.h"              // T12
    #else
#include "drvVIFInitial_MST_T8.h"               // T8
    #endif
#elif (CHIP_FAMILY_TYPE == CHIP_FAMILY_J2)
#include "drvVIFInitial_MST_J2.h"              // J2
#elif (CHIP_FAMILY_TYPE == CHIP_FAMILY_S7L)     // T9 //T13
#include "drvVIFInitial_MST_T9.h"
#elif (CHIP_FAMILY_TYPE == CHIP_FAMILY_J2)     // J2
#include "drvVIFInitial_MST_J2.h"
#elif (CHIP_FAMILY_TYPE == CHIP_FAMILY_A1)     // A1
#include "drvVIFInitial_MST_A1.h"
#elif (CHIP_FAMILY_TYPE == CHIP_FAMILY_A5)     // A1
#include "drvVIFInitial_MST_A5.h"
#elif (CHIP_FAMILY_TYPE == CHIP_FAMILY_A6)     // A6
#include "drvVIFInitial_MST_A6.h"
#elif (CHIP_FAMILY_TYPE == CHIP_FAMILY_A7)     // A7
#include "drvVIFInitial_MST_A7.h"
#elif (CHIP_FAMILY_TYPE == CHIP_FAMILY_EMERALD)   // Emerald
#include "drvVIFInitial_MST_EMERALD.h"
#elif (CHIP_FAMILY_TYPE == CHIP_FAMILY_NUGGET)   // Nugget
#include "drvVIFInitial_MST_NUGGET.h"
#elif (CHIP_FAMILY_TYPE == CHIP_FAMILY_NIKON)    // Nikon
#include "drvVIFInitial_MST_NIKON.h"
#elif (CHIP_FAMILY_TYPE == CHIP_FAMILY_MILAN)    // Milan
#include "drvVIFInitial_MST_MILAN.h"
#elif (CHIP_FAMILY_TYPE == CHIP_FAMILY_MULAN)    // Mulan
#include "drvVIFInitial_MST_MULAN.h"

#elif (CHIP_FAMILY_TYPE == CHIP_FAMILY_MAYA)    // Maya
#include "drvVIFInitial_MST_MAYA.h"
#elif (CHIP_FAMILY_TYPE == CHIP_FAMILY_WHISKY)    // Whisky
#include "drvVIFInitial_MST_WHISKY.h"
#elif (CHIP_FAMILY_TYPE == CHIP_FAMILY_MELODY)    // Melody
#include "drvVIFInitial_MST_MELODY.h"

#else
#error // no chip define.
#endif

#endif //_DRVVIFINITIAL_MST_H_

