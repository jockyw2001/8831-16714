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
#ifndef __API_FREQTABLECOMMON_H__
#define __API_FREQTABLECOMMON_H__

#include "SW_Config.h"
#define ROM   //should be erased in 32 bit MCU
/// Country
typedef enum
{
    E_COUNTRY_MIN,
    // ------------------------------------
    E_AUSTRALIA = E_COUNTRY_MIN,    /// 0   < Australia
    E_AUSTRIA,                      /// 1   < Austria
    E_BELGIUM,                      /// 2   < Belgium
    E_BULGARIA,                     /// 3   < Bulgaria
    E_CROATIA,                      /// 4   < Croatia
    E_CZECH,                        /// 5   < Czech
    E_DENMARK,                      /// 6   < Denmark
    E_FINLAND,                      /// 7   < Finland
    E_FRANCE,                       /// 8   < France
    E_GERMANY,                      /// 9   < Germany
    E_GREECE,                       /// 10  < Greece
    E_HUNGARY,                      /// 11  < Hungary
    E_ITALY,                        /// 12  < Italy
    E_IRELAND,                      /// 13  < Ireland////TODO, wait UI
    E_LUXEMBOURG,                   /// 14  < Luxembourg
    E_NETHERLANDS,                  /// 15  < Netherland
    E_NORWAY,                       /// 16  < Norway
    E_POLAND,                       /// 17  < Poland
    E_PORTUGAL,                     /// 18  < Portugal
    E_RUMANIA,                      /// 19  < Rumania
    E_RUSSIA,                       /// 20  < Russia
    E_SERBIA,                       /// 21  < Serbia
    E_SLOVENIA,                     /// 22  < Slovenia
    E_SPAIN,                        /// 23  < Spain
    E_SWEDEN,                       /// 24  < Sweden
    E_SWITZERLAND,                  /// 25  < Switzerland
    E_UK,                           /// 26  < UK
    E_UNITED_ARAB_EMIRATES,         /// 27  < United Arab Emirates
    E_NEWZEALAND,                   /// 28  < New Zealand
    E_CHINA,                        /// 29  < China
    E_ESTONIA,                      /// 30  < Estonia
    E_TURKEY,                       /// 31  < Turkey
    E_MOROCCO,                      /// 32  < Morocco
    E_TUNIS,                        /// 33  < Tunis
    E_ALGERIA,                      /// 34  < Algeria
    E_EGYPT,                        /// 35  < Egypt
    E_SOUTH_AFRICA,                 /// 36  < South Africa
    E_ISRAEL,                       /// 37  < Israel
    E_IRAN,                         /// 38  < Iran
    E_SLOVAKIA,                     /// 39  < Slovakia
    E_THAILAND,                     /// 40  < Thailand     
    E_VIETNAM,                      /// 41  < Vietnam     
    E_SINGAPORE,                    /// 42  < Sinapore     
    E_MALAYSIA,                     /// 43  < Malaysia     
    E_INDONESIA,                    /// 44  < Indonesia
    E_KUWAIT,                       /// 45  < Kuwait
    E_OMAN,                         /// 46  < Oman
    E_QATAR,                        /// 47  < Qatat
    E_SAUDI_ARABIA,                 /// 48  < Saudi Arabia

#if (ENABLE_DVB_TAIWAN_APP)
    E_TAIWAN,                       ///     < Taiwan
#endif

#if ENABLE_SBTVD_BRAZIL_APP
    E_BRAZIL,                       ///     < Brazil
#endif

    // ------------------------------------
    E_COUNTRY_NUM,
} MEMBER_COUNTRY;

#endif // __API_FREQTABLECOMMON_H__

