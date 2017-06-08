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
// (��MStar Confidential Information��) by the recipient.
// Any unauthorized act including without limitation unauthorized disclosure,
// copying, use, reproduction, sale, distribution, modification, disassembling,
// reverse engineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef IR_FORMAT_H
#define IR_FORMAT_H

//*************************************************************************
// Customer IR Specification parameter define (Please modify them by IR SPEC)
//*************************************************************************
#define IR_MODE_SEL             IR_TYPE_FULLDECODE_MODE
#define IR_CHANNEL_USE_AS_UPDOWN   0
#define IR_VOLUME_USE_AS_LEFTRIGHT      0
// IR Header code define
//#define IR_HEADER_CODE0         0x40//0x01//0x80    // Custom 0     //0x04
//#define IR_HEADER_CODE1         0xBF//0xFE//0x7F    // Custom 1     //0xFB
#define IR_HEADER_CODE0         0x30//0x01//0x80    // Custom 0     //0x04
#define IR_HEADER_CODE1         0xCF//0xFE//0x7F    // Custom 1     //0xFB

// IR Timing define
#define IR_HEADER_CODE_TIME     9000    // us
#define IR_OFF_CODE_TIME        4500    // us
#define IR_OFF_CODE_RP_TIME     2500    // us
#define IR_LOGI_01H_TIME        560     // us
//#define IR_LOGI_0_TIME          1120    // us
//#define IR_LOGI_1_TIME          2240    // us
#define IR_LOGI_0_TIME          1125    // us
#define IR_LOGI_1_TIME          2250    // us
#define IR_TIMEOUT_CYC          140000  // us

#define IR_HEADER_CODE_TIME_UB  20
#define IR_HEADER_CODE_TIME_LB  -20
#define IR_OFF_CODE_TIME_UB  20
#define IR_OFF_CODE_TIME_LB  -20
#define IR_OFF_CODE_RP_TIME_UB  20
#define IR_OFF_CODE_RP_TIME_LB  -20
#define IR_LOGI_01H_TIME_UB  35
#define IR_LOGI_01H_TIME_LB  -30
#define IR_LOGI_0_TIME_UB  20
#define IR_LOGI_0_TIME_LB  -20
#define IR_LOGI_1_TIME_UB  20
#define IR_LOGI_1_TIME_LB  -20
// IR Format define
#define IRKEY_DUMY              0xFF
#define IRDA_KEY_MAPPING_POWER  IRKEY_POWER

#define IR_LEADER_CODE_CHECKING_OPTION 0xBF
#define ENABLE_IR_MSTAR_SOURCE_HOTKEY   0
typedef enum _IrCommandType
{
    IRKEY_TV_ANTENNA        = 0x13,//IRKEY_DUMY,
#if (ENABLE_DMP == DISABLE)
    IRKEY_TV_RADIO          = IRKEY_DUMY-1,//same as IRKEY_PAGE_UP
#endif
    IRKEY_CHANNEL_LIST      = IRKEY_DUMY-2, //Ray IRC 2017.02.06: Disable ch list key //0x18,//IRKEY_DUMY-2,
    IRKEY_CHANNEL_FAV_LIST  = IRKEY_DUMY-3, //Ray IRC 2017.01.24 Avoid same value as num key 1  0x0D,//IRKEY_DUMY-3,
    IRKEY_CHANNEL_RETURN    = 0x40,//IRKEY_DUMY-4,
    IRKEY_CHANNEL_PLUS      = 0x1B,//IRKEY_DUMY-5,
    IRKEY_CHANNEL_MINUS     = IRKEY_DUMY-6, //Ray IRC 2017.01.24 Avoid same value as num key 7 0x1F,//IRKEY_DUMY-6,

    IRKEY_AUDIO             = 0x5A,//IRKEY_DUMY-7,
    IRKEY_VOLUME_PLUS       = 0x11, //Ray IRC 2017.01.24 0x0A,//IRKEY_DUMY-8,//0x09,//IRKEY_DUMY-8,
    IRKEY_VOLUME_MINUS      = 0x14, //Ray IRC 2017.01.24 0x0C,//IRKEY_DUMY-9,//0x01,//IRKEY_DUMY-9,

    IRKEY_UP                = 0x19,//0x05,
    IRKEY_POWER             = 0x17,//0x04,
    IRKEY_EXIT              = 0x1C,//0x00,
    IRKEY_MENU              = 0x59,//0x08,
    IRKEY_DOWN              = 0x08,//0x06,
    IRKEY_LEFT              = 0x15,//0x01,//IRKEY_DUMY-9,//0x01,
    IRKEY_SELECT            = 0x1A,//IRKEY_DUMY-10,
    IRKEY_RIGHT             = 0x12,//0x09,//IRKEY_DUMY-8,//0x09,

    //Ray IRC 2017.01.24: Change the digits to DV remote code
    IRKEY_NUM_0             = 0x07, //0x00,//IRKEY_DUMY-11,
    IRKEY_NUM_1             = 0x0D, //0x0E, //Ray IRC 2017.01.24 0x01,//IRKEY_DUMY-12,
    IRKEY_NUM_2             = 0x0E, //0x02,//IRKEY_DUMY-13,
    IRKEY_NUM_3             = 0x0F, //0x03,//IRKEY_DUMY-14,
    IRKEY_NUM_4             = 0x16, //0x04,//IRKEY_DUMY-15,
    IRKEY_NUM_5             = 0x1D, //0x05,//IRKEY_DUMY-16,
    IRKEY_NUM_6             = 0x1E, //IRKEY_DUMY-17,
    IRKEY_NUM_7             = 0x1F, //0x07,//IRKEY_DUMY-18,
    IRKEY_NUM_8             = 0x04, //IRKEY_DUMY-19,
    IRKEY_NUM_9             = 0x05, //0x09,//IRKEY_DUMY-20,

    IRKEY_MUTE              = 0x0C,  //Ray IRC 2017.01.24 0x10,
    IRKEY_FREEZE            = IRKEY_DUMY-21,
#if ENABLE_DMP
    IRKEY_PAGE_UP           = IRKEY_DUMY-22,
#endif
    IRKEY_PAGE_DOWN         = IRKEY_DUMY-23,
    IRKEY_CLOCK             = IRKEY_DUMY-24,

    IRKEY_INFO              = IRKEY_DUMY-25,  //Ray IRC 2017.01.24 Avoid cash with SELECT key ,//IRKEY_DUMY-25,
    IRKEY_RED               = IRKEY_DUMY-26,
    IRKEY_GREEN             = IRKEY_DUMY-27,
    IRKEY_YELLOW            = IRKEY_DUMY-28,
    IRKEY_BLUE              = IRKEY_DUMY-29,
    IRKEY_MTS               = IRKEY_DUMY-30,	//Ray IRC 2017.02.06: Disable MTS key   //0x58,//IRKEY_DUMY-30,
    IRKEY_NINE_LATTICE      = IRKEY_DUMY-31,
    IRKEY_TTX               = IRKEY_DUMY-32,
    IRKEY_CC                = IRKEY_DUMY-33,
    IRKEY_INPUT_SOURCE      = 0x06,//IRKEY_DUMY-34,
    IRKEY_CRADRD            = IRKEY_DUMY-35,
    IRKEY_PICTURE           = IRKEY_DUMY-36, //Ray IRC 2017.01.24 Avoid the same as VOL plus key  0x11,//IRKEY_DUMY-36,
    IRKEY_ZOOM              = 0x45,//IRKEY_DUMY-37,

    IRKEY_DASH              = IRKEY_DUMY-42,  // no us
    IRKEY_BACKWARD          = 0x4C,//IRKEY_DUMY-43,  // no us
    IRKEY_FORWARD           = 0x4D,//IRKEY_DUMY-44, // no use
    IRKEY_PLAY              = 0x58,	//Ray IRC 2017.02.06: add DV play code //IRKEY_DUMY-45, // no use
    IRKEY_RECORD            = IRKEY_DUMY-46, // no use
    IRKEY_STOP              = 0x18,     //Ray IRC 2017.02.06: add DV stop code //0x54,//IRKEY_DUMY-47, // no use
    IRKEY_PAUSE             = 0x5D,	//Ray IRC 2017.02.06: add DV pause code //IRKEY_DUMY-48, // no use
    IRKEY_MEMORY_RECALL     = IRKEY_DUMY-49, // no use

    IRKEY_AV                = IRKEY_DUMY-83,
    IRKEY_HDMI              = IRKEY_DUMY-82,
    IRKEY_SCART             = IRKEY_DUMY-38,
    IRKEY_PC                = IRKEY_DUMY-81,
    IRKEY_DTV               = IRKEY_DUMY-39,
    IRKEY_TV                = IRKEY_DUMY-40,
    IRKEY_COMPONENT  				= IRKEY_DUMY-80,        
    IRKEY_SV                = IRKEY_DUMY-41,

    IRKEY_SLEEP             = IRKEY_DUMY-50, //0x42,//IRKEY_DUMY-50, // no use	//MingYuan
    IRKEY_EPG               = IRKEY_DUMY-51,	//Ray IRC 2017.02.06: Disable EPG key  //0x5D,//IRKEY_DUMY-51, // no use

    IRKEY_P_CHECK           = IRKEY_DUMY-52, // no use
    IRKEY_S_CHECK           = IRKEY_DUMY-53, // no use

    IRKEY_MIX               = IRKEY_DUMY-54, // no use
    IRKEY_INDEX             = IRKEY_DUMY-55, // no use
    IRKEY_HOLD              = IRKEY_DUMY-56, // no use

    IRKEY_PREVIOUS          = 0x4B,//IRKEY_DUMY-57, // no use
    IRKEY_NEXT              = 0x4A,//IRKEY_DUMY-58, // no use
  //IRKEY_BRIGHTNESS_PLUS   = 0x0E,
  //IRKEY_BRIGHTNESS_MINUS  = 0x12,

    IRKEY_POWERONLY         = IRKEY_DUMY-59, // no use

    IRKEY_TTX_MODE          = IRKEY_DUMY-60, // no use
    IRKEY_RED2              = IRKEY_DUMY-61, // no use
    IRKEY_GREEN2            = IRKEY_DUMY-62, // no use
    IRKEY_UPDATE            = IRKEY_DUMY-63, // no use
    IRKEY_SUBTITLE          = IRKEY_DUMY-64, // no use
//  IRKEY_SUBCODE           = 0x53,
    IRKEY_TIME              = IRKEY_DUMY-65, // no use

    IRKEY_SIZE              = IRKEY_DUMY-66, // no use
    IRKEY_REVEAL            = IRKEY_DUMY-67, // no use
    IRKEY_RETURN            = IRKEY_DUMY-68, // no use
    IRKEY_ADJUST            = IRKEY_DUMY-69, // no use
    IRKEY_TV_INPUT          = IRKEY_DUMY-70, // no use
    IRKEY_KEY_DISABLE_KEYPAD = IRKEY_DUMY-71, // no use
    IRKEY_BACK              = IRKEY_DUMY-72, // no use
    IRKEY_SUBPAGE   =   IRKEY_DUMY-73, // no use

    IRKEY_SUBCODE       = IRKEY_DUMY-74, // no use
    IRKEY_PHOTO           = IRKEY_DUMY-75, // no use
    IRKEY_MINU             = IRKEY_DUMY-76, // no use
    IRKEY_GUIDE            = IRKEY_DUMY-77, // no use
    IRKEY_HOME              = IRKEY_DUMY-78, // no use
    IRKEY_USB              = 0x5F,//IRKEY_DUMY-79,
    IRKEY_USB_DOWNLOAD	   = 0x61,	//Ray IRC 2017.01.24: USB firmware download key (HDSDI1 key)

}IrCommandType;
//*************************************************************************

//*************************************************************************
// IR system parameter define for H/W setting (Please don't modify them)
//*************************************************************************
#define IR_CKDIV_NUM             ((BIU_CLOCK + 500000UL) / 1000000UL)
#define IR_CKDIV_NUM_BOOT        13

#define IR_CLK_BOOT             (BIU_CLOCK_BOOT / 1000000.0)
#define IR_CLK                  (BIU_CLOCK / 1000000.0)
#define irGetMinCnt_BOOT(time, tolerance) (((double)time*((double)IR_CLK_BOOT)/(IR_CKDIV_NUM_BOOT+1))*((double)1-tolerance))
#define irGetMaxCnt_BOOT(time, tolerance) (((double)time*((double)IR_CLK_BOOT)/(IR_CKDIV_NUM_BOOT+1))*((double)1+tolerance))
#define irGetMinCnt(time, tolerance) (((double)time*((double)IR_CLK)/(IR_CKDIV_NUM+1))*((double)1-tolerance))
#define irGetMaxCnt(time, tolerance) (((double)time*((double)IR_CLK)/(IR_CKDIV_NUM+1))*((double)1+tolerance))

#define irGetCnt_BOOT(time) (((double)time*((double)IR_CLK_BOOT)/(IR_CKDIV_NUM_BOOT+1))+0x300000UL)
#define irGetCnt(time) (((double)time*((double)IR_CLK)/(IR_CKDIV_NUM+1))+0x300000UL)

// 12Mhz
#define IR_RP_TIMEOUT_BOOT      irGetCnt_BOOT(IR_TIMEOUT_CYC)
#define IR_HDC_UPB_BOOT         irGetMaxCnt_BOOT(IR_HEADER_CODE_TIME, 0.2)
#define IR_HDC_LOB_BOOT         irGetMinCnt_BOOT(IR_HEADER_CODE_TIME, 0.2)
#define IR_OFC_UPB_BOOT         irGetMaxCnt_BOOT(IR_OFF_CODE_TIME, 0.2)
#define IR_OFC_LOB_BOOT         irGetMinCnt_BOOT(IR_OFF_CODE_TIME, 0.2)
#define IR_OFC_RP_UPB_BOOT      irGetMaxCnt_BOOT(IR_OFF_CODE_RP_TIME, 0.2)
#define IR_OFC_RP_LOB_BOOT      irGetMinCnt_BOOT(IR_OFF_CODE_RP_TIME, 0.2)
#define IR_LG01H_UPB_BOOT       irGetMaxCnt_BOOT(IR_LOGI_01H_TIME, 0.35)
#define IR_LG01H_LOB_BOOT       irGetMinCnt_BOOT(IR_LOGI_01H_TIME, 0.3)
#define IR_LG0_UPB_BOOT         irGetMaxCnt_BOOT(IR_LOGI_0_TIME, 0.2)
#define IR_LG0_LOB_BOOT         irGetMinCnt_BOOT(IR_LOGI_0_TIME, 0.2)
#define IR_LG1_UPB_BOOT         irGetMaxCnt_BOOT(IR_LOGI_1_TIME, 0.2)
#define IR_LG1_LOB_BOOT         irGetMinCnt_BOOT(IR_LOGI_1_TIME, 0.2)

// 90Mhz
#define IR_RP_TIMEOUT           irGetCnt(IR_TIMEOUT_CYC)
#define IR_HDC_UPB              irGetMaxCnt(IR_HEADER_CODE_TIME, 0.2)
#define IR_HDC_LOB              irGetMinCnt(IR_HEADER_CODE_TIME, 0.2)
#define IR_OFC_UPB              irGetMaxCnt(IR_OFF_CODE_TIME, 0.2)
#define IR_OFC_LOB              irGetMinCnt(IR_OFF_CODE_TIME, 0.2)
#define IR_OFC_RP_UPB           irGetMaxCnt(IR_OFF_CODE_RP_TIME, 0.2)
#define IR_OFC_RP_LOB           irGetMinCnt(IR_OFF_CODE_RP_TIME, 0.2)
#define IR_LG01H_UPB            irGetMaxCnt(IR_LOGI_01H_TIME, 0.35)
#define IR_LG01H_LOB            irGetMinCnt(IR_LOGI_01H_TIME, 0.3)
#define IR_LG0_UPB              irGetMaxCnt(IR_LOGI_0_TIME, 0.2)
#define IR_LG0_LOB              irGetMinCnt(IR_LOGI_0_TIME, 0.2)
#define IR_LG1_UPB              irGetMaxCnt(IR_LOGI_1_TIME, 0.2)
#define IR_LG1_LOB              irGetMinCnt(IR_LOGI_1_TIME, 0.2)

// Power off mode
#define PM_IR_TH_VAL            (PM_TH0_VAL & 0x0F)
// PM_IR_TH_GRID specify the time (in us) for each threshold bit.
// So PM_IR_TH_GRID = (1/12M) * (2^14) * 1000000 = (2^14) / 12
#define PM_IR_TH_GRID           (16384/IR_CLK_BOOT)
#define PM_IR_HEADER_CODE_TIME  (IR_HEADER_CODE_TIME-(0x0F-PM_IR_TH_VAL)*PM_IR_TH_GRID)
#define PM_IR_HDC_UPB_BOOT      irGetMaxCnt_BOOT(PM_IR_HEADER_CODE_TIME, 0.6)
#define PM_IR_HDC_LOB_BOOT      irGetMinCnt_BOOT(PM_IR_HEADER_CODE_TIME, 0.6)
//*************************************************************************

#define IR_NEC_HEADER_CNT_LB        12200
#define IR_NEC_HEADER_CNT_UB        17550
#define IR_NEC_REPEATE_CNT_LB       8050
#define IR_NEC_REPEATE_CNT_UB       12200
#define IR_NEC_LOGIC0_CNT_LB        800
#define IR_NEC_LOGIC0_CNT_UB        1400
#define IR_NEC_LOGIC1_CNT_LB        1600
#define IR_NEC_LOGIC1_CNT_UB        2500
#define IR_NEC_REPEATE_TIMEOUT_CNT  150

//********************************
//
//  IR Wakeup keys for standby mode
//
//********************************
#define IR_WAKEUP_KEY0              IRKEY_POWER //configured by application
#define IR_WAKEUP_KEY1              IRKEY_POWER //configured by application
#define IR_WAKEUP_KEY2              IRKEY_POWER //configured by application
#define IR_WAKEUP_KEY3              IRKEY_POWER //configured by application
//********************************
//
//  Factory OSD password key
//
//********************************
#define	IR_FACTORY_OSD_NUM							 6
#define IR_FACTORY_OSD_KEY0              1
#define IR_FACTORY_OSD_KEY1              2
#define IR_FACTORY_OSD_KEY2              3
#define IR_FACTORY_OSD_KEY3              5
#define IR_FACTORY_OSD_KEY4              8
#define IR_FACTORY_OSD_KEY5              0
//********************************
//
//  Support 2nd NEC Full Decode
//
//********************************
// 2nd IR Header code define
#define IR_2ND_NEC_DECODE_EN        DISABLE
#define IR_HEADER_CODE_2ND0         0xFF    // 2nd Custom 0
#define IR_HEADER_CODE_2ND1         0xFF    // 2nd Custom 1

#endif
