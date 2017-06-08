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
#define MAPP_BIG52UNICODE_A9AF_C

#include <stdio.h>
#include <string.h>
#include "Board.h"
#include "ctype.h"
#include "datatype.h"
#include "mapp_big52unicode.h"

#if (ENABLE_DMP)
#if (ENABLE_DTMB_CHINA_APP ||CHINESE_SIMP_FONT_ENABLE || ENABLE_DVB_TAIWAN_APP || ENABLE_SBTVD_BRAZIL_APP || CHINESE_BIG5_FONT_ENABLE || (TV_SYSTEM == TV_NTSC))

BIG5UnicodeTbl code au16BIG5Unicode_A9AF[] =
{
 {0xA940 ,0x5496},
 {0xA941 ,0x5478},
 {0xA942 ,0x5495},
 {0xA943 ,0x5480},
 {0xA944 ,0x547B},
 {0xA945 ,0x5477},
 {0xA946 ,0x5484},
 {0xA947 ,0x5492},
 {0xA948 ,0x5486},
 {0xA949 ,0x547C},
 {0xA94A ,0x5490},
 {0xA94B ,0x5471},
 {0xA94C ,0x5476},
 {0xA94D ,0x548C},
 {0xA94E ,0x549A},
 {0xA94F ,0x5462},
 {0xA950 ,0x5468},
 {0xA951 ,0x548B},
 {0xA952 ,0x547D},
 {0xA953 ,0x548E},
 {0xA954 ,0x56FA},
 {0xA955 ,0x5783},
 {0xA956 ,0x5777},
 {0xA957 ,0x576A},
 {0xA958 ,0x5769},
 {0xA959 ,0x5761},
 {0xA95A ,0x5766},
 {0xA95B ,0x5764},
 {0xA95C ,0x577C},
 {0xA95D ,0x591C},
 {0xA95E ,0x5949},
 {0xA95F ,0x5947},
 {0xA960 ,0x5948},
 {0xA961 ,0x5944},
 {0xA962 ,0x5954},
 {0xA963 ,0x59BE},
 {0xA964 ,0x59BB},
 {0xA965 ,0x59D4},
 {0xA966 ,0x59B9},
 {0xA967 ,0x59AE},
 {0xA968 ,0x59D1},
 {0xA969 ,0x59C6},
 {0xA96A ,0x59D0},
 {0xA96B ,0x59CD},
 {0xA96C ,0x59CB},
 {0xA96D ,0x59D3},
 {0xA96E ,0x59CA},
 {0xA96F ,0x59AF},
 {0xA970 ,0x59B3},
 {0xA971 ,0x59D2},
 {0xA972 ,0x59C5},
 {0xA973 ,0x5B5F},
 {0xA974 ,0x5B64},
 {0xA975 ,0x5B63},
 {0xA976 ,0x5B97},
 {0xA977 ,0x5B9A},
 {0xA978 ,0x5B98},
 {0xA979 ,0x5B9C},
 {0xA97A ,0x5B99},
 {0xA97B ,0x5B9B},
 {0xA97C ,0x5C1A},
 {0xA97D ,0x5C48},
 {0xA97E ,0x5C45},
 {0xA9A1 ,0x5C46},
 {0xA9A2 ,0x5CB7},
 {0xA9A3 ,0x5CA1},
 {0xA9A4 ,0x5CB8},
 {0xA9A5 ,0x5CA9},
 {0xA9A6 ,0x5CAB},
 {0xA9A7 ,0x5CB1},
 {0xA9A8 ,0x5CB3},
 {0xA9A9 ,0x5E18},
 {0xA9AA ,0x5E1A},
 {0xA9AB ,0x5E16},
 {0xA9AC ,0x5E15},
 {0xA9AD ,0x5E1B},
 {0xA9AE ,0x5E11},
 {0xA9AF ,0x5E78},
 {0xA9B0 ,0x5E9A},
 {0xA9B1 ,0x5E97},
 {0xA9B2 ,0x5E9C},
 {0xA9B3 ,0x5E95},
 {0xA9B4 ,0x5E96},
 {0xA9B5 ,0x5EF6},
 {0xA9B6 ,0x5F26},
 {0xA9B7 ,0x5F27},
 {0xA9B8 ,0x5F29},
 {0xA9B9 ,0x5F80},
 {0xA9BA ,0x5F81},
 {0xA9BB ,0x5F7F},
 {0xA9BC ,0x5F7C},
 {0xA9BD ,0x5FDD},
 {0xA9BE ,0x5FE0},
 {0xA9BF ,0x5FFD},
 {0xA9C0 ,0x5FF5},
 {0xA9C1 ,0x5FFF},
 {0xA9C2 ,0x600F},
 {0xA9C3 ,0x6014},
 {0xA9C4 ,0x602F},
 {0xA9C5 ,0x6035},
 {0xA9C6 ,0x6016},
 {0xA9C7 ,0x602A},
 {0xA9C8 ,0x6015},
 {0xA9C9 ,0x6021},
 {0xA9CA ,0x6027},
 {0xA9CB ,0x6029},
 {0xA9CC ,0x602B},
 {0xA9CD ,0x601B},
 {0xA9CE ,0x6216},
 {0xA9CF ,0x6215},
 {0xA9D0 ,0x623F},
 {0xA9D1 ,0x623E},
 {0xA9D2 ,0x6240},
 {0xA9D3 ,0x627F},
 {0xA9D4 ,0x62C9},
 {0xA9D5 ,0x62CC},
 {0xA9D6 ,0x62C4},
 {0xA9D7 ,0x62BF},
 {0xA9D8 ,0x62C2},
 {0xA9D9 ,0x62B9},
 {0xA9DA ,0x62D2},
 {0xA9DB ,0x62DB},
 {0xA9DC ,0x62AB},
 {0xA9DD ,0x62D3},
 {0xA9DE ,0x62D4},
 {0xA9DF ,0x62CB},
 {0xA9E0 ,0x62C8},
 {0xA9E1 ,0x62A8},
 {0xA9E2 ,0x62BD},
 {0xA9E3 ,0x62BC},
 {0xA9E4 ,0x62D0},
 {0xA9E5 ,0x62D9},
 {0xA9E6 ,0x62C7},
 {0xA9E7 ,0x62CD},
 {0xA9E8 ,0x62B5},
 {0xA9E9 ,0x62DA},
 {0xA9EA ,0x62B1},
 {0xA9EB ,0x62D8},
 {0xA9EC ,0x62D6},
 {0xA9ED ,0x62D7},
 {0xA9EE ,0x62C6},
 {0xA9EF ,0x62AC},
 {0xA9F0 ,0x62CE},
 {0xA9F1 ,0x653E},
 {0xA9F2 ,0x65A7},
 {0xA9F3 ,0x65BC},
 {0xA9F4 ,0x65FA},
 {0xA9F5 ,0x6614},
 {0xA9F6 ,0x6613},
 {0xA9F7 ,0x660C},
 {0xA9F8 ,0x6606},
 {0xA9F9 ,0x6602},
 {0xA9FA ,0x660E},
 {0xA9FB ,0x6600},
 {0xA9FC ,0x660F},
 {0xA9FD ,0x6615},
 {0xA9FE ,0x660A},
 {0xAA40 ,0x6607},
 {0xAA41 ,0x670D},
 {0xAA42 ,0x670B},
 {0xAA43 ,0x676D},
 {0xAA44 ,0x678B},
 {0xAA45 ,0x6795},
 {0xAA46 ,0x6771},
 {0xAA47 ,0x679C},
 {0xAA48 ,0x6773},
 {0xAA49 ,0x6777},
 {0xAA4A ,0x6787},
 {0xAA4B ,0x679D},
 {0xAA4C ,0x6797},
 {0xAA4D ,0x676F},
 {0xAA4E ,0x6770},
 {0xAA4F ,0x677F},
 {0xAA50 ,0x6789},
 {0xAA51 ,0x677E},
 {0xAA52 ,0x6790},
 {0xAA53 ,0x6775},
 {0xAA54 ,0x679A},
 {0xAA55 ,0x6793},
 {0xAA56 ,0x677C},
 {0xAA57 ,0x676A},
 {0xAA58 ,0x6772},
 {0xAA59 ,0x6B23},
 {0xAA5A ,0x6B66},
 {0xAA5B ,0x6B67},
 {0xAA5C ,0x6B7F},
 {0xAA5D ,0x6C13},
 {0xAA5E ,0x6C1B},
 {0xAA5F ,0x6CE3},
 {0xAA60 ,0x6CE8},
 {0xAA61 ,0x6CF3},
 {0xAA62 ,0x6CB1},
 {0xAA63 ,0x6CCC},
 {0xAA64 ,0x6CE5},
 {0xAA65 ,0x6CB3},
 {0xAA66 ,0x6CBD},
 {0xAA67 ,0x6CBE},
 {0xAA68 ,0x6CBC},
 {0xAA69 ,0x6CE2},
 {0xAA6A ,0x6CAB},
 {0xAA6B ,0x6CD5},
 {0xAA6C ,0x6CD3},
 {0xAA6D ,0x6CB8},
 {0xAA6E ,0x6CC4},
 {0xAA6F ,0x6CB9},
 {0xAA70 ,0x6CC1},
 {0xAA71 ,0x6CAE},
 {0xAA72 ,0x6CD7},
 {0xAA73 ,0x6CC5},
 {0xAA74 ,0x6CF1},
 {0xAA75 ,0x6CBF},
 {0xAA76 ,0x6CBB},
 {0xAA77 ,0x6CE1},
 {0xAA78 ,0x6CDB},
 {0xAA79 ,0x6CCA},
 {0xAA7A ,0x6CAC},
 {0xAA7B ,0x6CEF},
 {0xAA7C ,0x6CDC},
 {0xAA7D ,0x6CD6},
 {0xAA7E ,0x6CE0},
 {0xAAA1 ,0x7095},
 {0xAAA2 ,0x708E},
 {0xAAA3 ,0x7092},
 {0xAAA4 ,0x708A},
 {0xAAA5 ,0x7099},
 {0xAAA6 ,0x722C},
 {0xAAA7 ,0x722D},
 {0xAAA8 ,0x7238},
 {0xAAA9 ,0x7248},
 {0xAAAA ,0x7267},
 {0xAAAB ,0x7269},
 {0xAAAC ,0x72C0},
 {0xAAAD ,0x72CE},
 {0xAAAE ,0x72D9},
 {0xAAAF ,0x72D7},
 {0xAAB0 ,0x72D0},
 {0xAAB1 ,0x73A9},
 {0xAAB2 ,0x73A8},
 {0xAAB3 ,0x739F},
 {0xAAB4 ,0x73AB},
 {0xAAB5 ,0x73A5},
 {0xAAB6 ,0x753D},
 {0xAAB7 ,0x759D},
 {0xAAB8 ,0x7599},
 {0xAAB9 ,0x759A},
 {0xAABA ,0x7684},
 {0xAABB ,0x76C2},
 {0xAABC ,0x76F2},
 {0xAABD ,0x76F4},
 {0xAABE ,0x77E5},
 {0xAABF ,0x77FD},
 {0xAAC0 ,0x793E},
 {0xAAC1 ,0x7940},
 {0xAAC2 ,0x7941},
 {0xAAC3 ,0x79C9},
 {0xAAC4 ,0x79C8},
 {0xAAC5 ,0x7A7A},
 {0xAAC6 ,0x7A79},
 {0xAAC7 ,0x7AFA},
 {0xAAC8 ,0x7CFE},
 {0xAAC9 ,0x7F54},
 {0xAACA ,0x7F8C},
 {0xAACB ,0x7F8B},
 {0xAACC ,0x8005},
 {0xAACD ,0x80BA},
 {0xAACE ,0x80A5},
 {0xAACF ,0x80A2},
 {0xAAD0 ,0x80B1},
 {0xAAD1 ,0x80A1},
 {0xAAD2 ,0x80AB},
 {0xAAD3 ,0x80A9},
 {0xAAD4 ,0x80B4},
 {0xAAD5 ,0x80AA},
 {0xAAD6 ,0x80AF},
 {0xAAD7 ,0x81E5},
 {0xAAD8 ,0x81FE},
 {0xAAD9 ,0x820D},
 {0xAADA ,0x82B3},
 {0xAADB ,0x829D},
 {0xAADC ,0x8299},
 {0xAADD ,0x82AD},
 {0xAADE ,0x82BD},
 {0xAADF ,0x829F},
 {0xAAE0 ,0x82B9},
 {0xAAE1 ,0x82B1},
 {0xAAE2 ,0x82AC},
 {0xAAE3 ,0x82A5},
 {0xAAE4 ,0x82AF},
 {0xAAE5 ,0x82B8},
 {0xAAE6 ,0x82A3},
 {0xAAE7 ,0x82B0},
 {0xAAE8 ,0x82BE},
 {0xAAE9 ,0x82B7},
 {0xAAEA ,0x864E},
 {0xAAEB ,0x8671},
 {0xAAEC ,0x521D},
 {0xAAED ,0x8868},
 {0xAAEE ,0x8ECB},
 {0xAAEF ,0x8FCE},
 {0xAAF0 ,0x8FD4},
 {0xAAF1 ,0x8FD1},
 {0xAAF2 ,0x90B5},
 {0xAAF3 ,0x90B8},
 {0xAAF4 ,0x90B1},
 {0xAAF5 ,0x90B6},
 {0xAAF6 ,0x91C7},
 {0xAAF7 ,0x91D1},
 {0xAAF8 ,0x9577},
 {0xAAF9 ,0x9580},
 {0xAAFA ,0x961C},
 {0xAAFB ,0x9640},
 {0xAAFC ,0x963F},
 {0xAAFD ,0x963B},
 {0xAAFE ,0x9644},
 {0xAB40 ,0x9642},
 {0xAB41 ,0x96B9},
 {0xAB42 ,0x96E8},
 {0xAB43 ,0x9752},
 {0xAB44 ,0x975E},
 {0xAB45 ,0x4E9F},
 {0xAB46 ,0x4EAD},
 {0xAB47 ,0x4EAE},
 {0xAB48 ,0x4FE1},
 {0xAB49 ,0x4FB5},
 {0xAB4A ,0x4FAF},
 {0xAB4B ,0x4FBF},
 {0xAB4C ,0x4FE0},
 {0xAB4D ,0x4FD1},
 {0xAB4E ,0x4FCF},
 {0xAB4F ,0x4FDD},
 {0xAB50 ,0x4FC3},
 {0xAB51 ,0x4FB6},
 {0xAB52 ,0x4FD8},
 {0xAB53 ,0x4FDF},
 {0xAB54 ,0x4FCA},
 {0xAB55 ,0x4FD7},
 {0xAB56 ,0x4FAE},
 {0xAB57 ,0x4FD0},
 {0xAB58 ,0x4FC4},
 {0xAB59 ,0x4FC2},
 {0xAB5A ,0x4FDA},
 {0xAB5B ,0x4FCE},
 {0xAB5C ,0x4FDE},
 {0xAB5D ,0x4FB7},
 {0xAB5E ,0x5157},
 {0xAB5F ,0x5192},
 {0xAB60 ,0x5191},
 {0xAB61 ,0x51A0},
 {0xAB62 ,0x524E},
 {0xAB63 ,0x5243},
 {0xAB64 ,0x524A},
 {0xAB65 ,0x524D},
 {0xAB66 ,0x524C},
 {0xAB67 ,0x524B},
 {0xAB68 ,0x5247},
 {0xAB69 ,0x52C7},
 {0xAB6A ,0x52C9},
 {0xAB6B ,0x52C3},
 {0xAB6C ,0x52C1},
 {0xAB6D ,0x530D},
 {0xAB6E ,0x5357},
 {0xAB6F ,0x537B},
 {0xAB70 ,0x539A},
 {0xAB71 ,0x53DB},
 {0xAB72 ,0x54AC},
 {0xAB73 ,0x54C0},
 {0xAB74 ,0x54A8},
 {0xAB75 ,0x54CE},
 {0xAB76 ,0x54C9},
 {0xAB77 ,0x54B8},
 {0xAB78 ,0x54A6},
 {0xAB79 ,0x54B3},
 {0xAB7A ,0x54C7},
 {0xAB7B ,0x54C2},
 {0xAB7C ,0x54BD},
 {0xAB7D ,0x54AA},
 {0xAB7E ,0x54C1},
 {0xABA1 ,0x54C4},
 {0xABA2 ,0x54C8},
 {0xABA3 ,0x54AF},
 {0xABA4 ,0x54AB},
 {0xABA5 ,0x54B1},
 {0xABA6 ,0x54BB},
 {0xABA7 ,0x54A9},
 {0xABA8 ,0x54A7},
 {0xABA9 ,0x54BF},
 {0xABAA ,0x56FF},
 {0xABAB ,0x5782},
 {0xABAC ,0x578B},
 {0xABAD ,0x57A0},
 {0xABAE ,0x57A3},
 {0xABAF ,0x57A2},
 {0xABB0 ,0x57CE},
 {0xABB1 ,0x57AE},
 {0xABB2 ,0x5793},
 {0xABB3 ,0x5955},
 {0xABB4 ,0x5951},
 {0xABB5 ,0x594F},
 {0xABB6 ,0x594E},
 {0xABB7 ,0x5950},
 {0xABB8 ,0x59DC},
 {0xABB9 ,0x59D8},
 {0xABBA ,0x59FF},
 {0xABBB ,0x59E3},
 {0xABBC ,0x59E8},
 {0xABBD ,0x5A03},
 {0xABBE ,0x59E5},
 {0xABBF ,0x59EA},
 {0xABC0 ,0x59DA},
 {0xABC1 ,0x59E6},
 {0xABC2 ,0x5A01},
 {0xABC3 ,0x59FB},
 {0xABC4 ,0x5B69},
 {0xABC5 ,0x5BA3},
 {0xABC6 ,0x5BA6},
 {0xABC7 ,0x5BA4},
 {0xABC8 ,0x5BA2},
 {0xABC9 ,0x5BA5},
 {0xABCA ,0x5C01},
 {0xABCB ,0x5C4E},
 {0xABCC ,0x5C4F},
 {0xABCD ,0x5C4D},
 {0xABCE ,0x5C4B},
 {0xABCF ,0x5CD9},
 {0xABD0 ,0x5CD2},
 {0xABD1 ,0x5DF7},
 {0xABD2 ,0x5E1D},
 {0xABD3 ,0x5E25},
 {0xABD4 ,0x5E1F},
 {0xABD5 ,0x5E7D},
 {0xABD6 ,0x5EA0},
 {0xABD7 ,0x5EA6},
 {0xABD8 ,0x5EFA},
 {0xABD9 ,0x5F08},
 {0xABDA ,0x5F2D},
 {0xABDB ,0x5F65},
 {0xABDC ,0x5F88},
 {0xABDD ,0x5F85},
 {0xABDE ,0x5F8A},
 {0xABDF ,0x5F8B},
 {0xABE0 ,0x5F87},
 {0xABE1 ,0x5F8C},
 {0xABE2 ,0x5F89},
 {0xABE3 ,0x6012},
 {0xABE4 ,0x601D},
 {0xABE5 ,0x6020},
 {0xABE6 ,0x6025},
 {0xABE7 ,0x600E},
 {0xABE8 ,0x6028},
 {0xABE9 ,0x604D},
 {0xABEA ,0x6070},
 {0xABEB ,0x6068},
 {0xABEC ,0x6062},
 {0xABED ,0x6046},
 {0xABEE ,0x6043},
 {0xABEF ,0x606C},
 {0xABF0 ,0x606B},
 {0xABF1 ,0x606A},
 {0xABF2 ,0x6064},
 {0xABF3 ,0x6241},
 {0xABF4 ,0x62DC},
 {0xABF5 ,0x6316},
 {0xABF6 ,0x6309},
 {0xABF7 ,0x62FC},
 {0xABF8 ,0x62ED},
 {0xABF9 ,0x6301},
 {0xABFA ,0x62EE},
 {0xABFB ,0x62FD},
 {0xABFC ,0x6307},
 {0xABFD ,0x62F1},
 {0xABFE ,0x62F7},
 {0xAC40 ,0x62EF},
 {0xAC41 ,0x62EC},
 {0xAC42 ,0x62FE},
 {0xAC43 ,0x62F4},
 {0xAC44 ,0x6311},
 {0xAC45 ,0x6302},
 {0xAC46 ,0x653F},
 {0xAC47 ,0x6545},
 {0xAC48 ,0x65AB},
 {0xAC49 ,0x65BD},
 {0xAC4A ,0x65E2},
 {0xAC4B ,0x6625},
 {0xAC4C ,0x662D},
 {0xAC4D ,0x6620},
 {0xAC4E ,0x6627},
 {0xAC4F ,0x662F},
 {0xAC50 ,0x661F},
 {0xAC51 ,0x6628},
 {0xAC52 ,0x6631},
 {0xAC53 ,0x6624},
 {0xAC54 ,0x66F7},
 {0xAC55 ,0x67FF},
 {0xAC56 ,0x67D3},
 {0xAC57 ,0x67F1},
 {0xAC58 ,0x67D4},
 {0xAC59 ,0x67D0},
 {0xAC5A ,0x67EC},
 {0xAC5B ,0x67B6},
 {0xAC5C ,0x67AF},
 {0xAC5D ,0x67F5},
 {0xAC5E ,0x67E9},
 {0xAC5F ,0x67EF},
 {0xAC60 ,0x67C4},
 {0xAC61 ,0x67D1},
 {0xAC62 ,0x67B4},
 {0xAC63 ,0x67DA},
 {0xAC64 ,0x67E5},
 {0xAC65 ,0x67B8},
 {0xAC66 ,0x67CF},
 {0xAC67 ,0x67DE},
 {0xAC68 ,0x67F3},
 {0xAC69 ,0x67B0},
 {0xAC6A ,0x67D9},
 {0xAC6B ,0x67E2},
 {0xAC6C ,0x67DD},
 {0xAC6D ,0x67D2},
 {0xAC6E ,0x6B6A},
 {0xAC6F ,0x6B83},
 {0xAC70 ,0x6B86},
 {0xAC71 ,0x6BB5},
 {0xAC72 ,0x6BD2},
 {0xAC73 ,0x6BD7},
 {0xAC74 ,0x6C1F},
 {0xAC75 ,0x6CC9},
 {0xAC76 ,0x6D0B},
 {0xAC77 ,0x6D32},
 {0xAC78 ,0x6D2A},
 {0xAC79 ,0x6D41},
 {0xAC7A ,0x6D25},
 {0xAC7B ,0x6D0C},
 {0xAC7C ,0x6D31},
 {0xAC7D ,0x6D1E},
 {0xAC7E ,0x6D17},
 {0xACA1 ,0x6D3B},
 {0xACA2 ,0x6D3D},
 {0xACA3 ,0x6D3E},
 {0xACA4 ,0x6D36},
 {0xACA5 ,0x6D1B},
 {0xACA6 ,0x6CF5},
 {0xACA7 ,0x6D39},
 {0xACA8 ,0x6D27},
 {0xACA9 ,0x6D38},
 {0xACAA ,0x6D29},
 {0xACAB ,0x6D2E},
 {0xACAC ,0x6D35},
 {0xACAD ,0x6D0E},
 {0xACAE ,0x6D2B},
 {0xACAF ,0x70AB},
 {0xACB0 ,0x70BA},
 {0xACB1 ,0x70B3},
 {0xACB2 ,0x70AC},
 {0xACB3 ,0x70AF},
 {0xACB4 ,0x70AD},
 {0xACB5 ,0x70B8},
 {0xACB6 ,0x70AE},
 {0xACB7 ,0x70A4},
 {0xACB8 ,0x7230},
 {0xACB9 ,0x7272},
 {0xACBA ,0x726F},
 {0xACBB ,0x7274},
 {0xACBC ,0x72E9},
 {0xACBD ,0x72E0},
 {0xACBE ,0x72E1},
 {0xACBF ,0x73B7},
 {0xACC0 ,0x73CA},
 {0xACC1 ,0x73BB},
 {0xACC2 ,0x73B2},
 {0xACC3 ,0x73CD},
 {0xACC4 ,0x73C0},
 {0xACC5 ,0x73B3},
 {0xACC6 ,0x751A},
 {0xACC7 ,0x752D},
 {0xACC8 ,0x754F},
 {0xACC9 ,0x754C},
 {0xACCA ,0x754E},
 {0xACCB ,0x754B},
 {0xACCC ,0x75AB},
 {0xACCD ,0x75A4},
 {0xACCE ,0x75A5},
 {0xACCF ,0x75A2},
 {0xACD0 ,0x75A3},
 {0xACD1 ,0x7678},
 {0xACD2 ,0x7686},
 {0xACD3 ,0x7687},
 {0xACD4 ,0x7688},
 {0xACD5 ,0x76C8},
 {0xACD6 ,0x76C6},
 {0xACD7 ,0x76C3},
 {0xACD8 ,0x76C5},
 {0xACD9 ,0x7701},
 {0xACDA ,0x76F9},
 {0xACDB ,0x76F8},
 {0xACDC ,0x7709},
 {0xACDD ,0x770B},
 {0xACDE ,0x76FE},
 {0xACDF ,0x76FC},
 {0xACE0 ,0x7707},
 {0xACE1 ,0x77DC},
 {0xACE2 ,0x7802},
 {0xACE3 ,0x7814},
 {0xACE4 ,0x780C},
 {0xACE5 ,0x780D},
 {0xACE6 ,0x7946},
 {0xACE7 ,0x7949},
 {0xACE8 ,0x7948},
 {0xACE9 ,0x7947},
 {0xACEA ,0x79B9},
 {0xACEB ,0x79BA},
 {0xACEC ,0x79D1},
 {0xACED ,0x79D2},
 {0xACEE ,0x79CB},
 {0xACEF ,0x7A7F},
 {0xACF0 ,0x7A81},
 {0xACF1 ,0x7AFF},
 {0xACF2 ,0x7AFD},
 {0xACF3 ,0x7C7D},
 {0xACF4 ,0x7D02},
 {0xACF5 ,0x7D05},
 {0xACF6 ,0x7D00},
 {0xACF7 ,0x7D09},
 {0xACF8 ,0x7D07},
 {0xACF9 ,0x7D04},
 {0xACFA ,0x7D06},
 {0xACFB ,0x7F38},
 {0xACFC ,0x7F8E},
 {0xACFD ,0x7FBF},
 {0xACFE ,0x8004},
 {0xAD40 ,0x8010},
 {0xAD41 ,0x800D},
 {0xAD42 ,0x8011},
 {0xAD43 ,0x8036},
 {0xAD44 ,0x80D6},
 {0xAD45 ,0x80E5},
 {0xAD46 ,0x80DA},
 {0xAD47 ,0x80C3},
 {0xAD48 ,0x80C4},
 {0xAD49 ,0x80CC},
 {0xAD4A ,0x80E1},
 {0xAD4B ,0x80DB},
 {0xAD4C ,0x80CE},
 {0xAD4D ,0x80DE},
 {0xAD4E ,0x80E4},
 {0xAD4F ,0x80DD},
 {0xAD50 ,0x81F4},
 {0xAD51 ,0x8222},
 {0xAD52 ,0x82E7},
 {0xAD53 ,0x8303},
 {0xAD54 ,0x8305},
 {0xAD55 ,0x82E3},
 {0xAD56 ,0x82DB},
 {0xAD57 ,0x82E6},
 {0xAD58 ,0x8304},
 {0xAD59 ,0x82E5},
 {0xAD5A ,0x8302},
 {0xAD5B ,0x8309},
 {0xAD5C ,0x82D2},
 {0xAD5D ,0x82D7},
 {0xAD5E ,0x82F1},
 {0xAD5F ,0x8301},
 {0xAD60 ,0x82DC},
 {0xAD61 ,0x82D4},
 {0xAD62 ,0x82D1},
 {0xAD63 ,0x82DE},
 {0xAD64 ,0x82D3},
 {0xAD65 ,0x82DF},
 {0xAD66 ,0x82EF},
 {0xAD67 ,0x8306},
 {0xAD68 ,0x8650},
 {0xAD69 ,0x8679},
 {0xAD6A ,0x867B},
 {0xAD6B ,0x867A},
 {0xAD6C ,0x884D},
 {0xAD6D ,0x886B},
 {0xAD6E ,0x8981},
 {0xAD6F ,0x89D4},
 {0xAD70 ,0x8A08},
 {0xAD71 ,0x8A02},
 {0xAD72 ,0x8A03},
 {0xAD73 ,0x8C9E},
 {0xAD74 ,0x8CA0},
 {0xAD75 ,0x8D74},
 {0xAD76 ,0x8D73},
 {0xAD77 ,0x8DB4},
 {0xAD78 ,0x8ECD},
 {0xAD79 ,0x8ECC},
 {0xAD7A ,0x8FF0},
 {0xAD7B ,0x8FE6},
 {0xAD7C ,0x8FE2},
 {0xAD7D ,0x8FEA},
 {0xAD7E ,0x8FE5},
 {0xADA1 ,0x8FED},
 {0xADA2 ,0x8FEB},
 {0xADA3 ,0x8FE4},
 {0xADA4 ,0x8FE8},
 {0xADA5 ,0x90CA},
 {0xADA6 ,0x90CE},
 {0xADA7 ,0x90C1},
 {0xADA8 ,0x90C3},
 {0xADA9 ,0x914B},
 {0xADAA ,0x914A},
 {0xADAB ,0x91CD},
 {0xADAC ,0x9582},
 {0xADAD ,0x9650},
 {0xADAE ,0x964B},
 {0xADAF ,0x964C},
 {0xADB0 ,0x964D},
 {0xADB1 ,0x9762},
 {0xADB2 ,0x9769},
 {0xADB3 ,0x97CB},
 {0xADB4 ,0x97ED},
 {0xADB5 ,0x97F3},
 {0xADB6 ,0x9801},
 {0xADB7 ,0x98A8},
 {0xADB8 ,0x98DB},
 {0xADB9 ,0x98DF},
 {0xADBA ,0x9996},
 {0xADBB ,0x9999},
 {0xADBC ,0x4E58},
 {0xADBD ,0x4EB3},
 {0xADBE ,0x500C},
 {0xADBF ,0x500D},
 {0xADC0 ,0x5023},
 {0xADC1 ,0x4FEF},
 {0xADC2 ,0x5026},
 {0xADC3 ,0x5025},
 {0xADC4 ,0x4FF8},
 {0xADC5 ,0x5029},
 {0xADC6 ,0x5016},
 {0xADC7 ,0x5006},
 {0xADC8 ,0x503C},
 {0xADC9 ,0x501F},
 {0xADCA ,0x501A},
 {0xADCB ,0x5012},
 {0xADCC ,0x5011},
 {0xADCD ,0x4FFA},
 {0xADCE ,0x5000},
 {0xADCF ,0x5014},
 {0xADD0 ,0x5028},
 {0xADD1 ,0x4FF1},
 {0xADD2 ,0x5021},
 {0xADD3 ,0x500B},
 {0xADD4 ,0x5019},
 {0xADD5 ,0x5018},
 {0xADD6 ,0x4FF3},
 {0xADD7 ,0x4FEE},
 {0xADD8 ,0x502D},
 {0xADD9 ,0x502A},
 {0xADDA ,0x4FFE},
 {0xADDB ,0x502B},
 {0xADDC ,0x5009},
 {0xADDD ,0x517C},
 {0xADDE ,0x51A4},
 {0xADDF ,0x51A5},
 {0xADE0 ,0x51A2},
 {0xADE1 ,0x51CD},
 {0xADE2 ,0x51CC},
 {0xADE3 ,0x51C6},
 {0xADE4 ,0x51CB},
 {0xADE5 ,0x5256},
 {0xADE6 ,0x525C},
 {0xADE7 ,0x5254},
 {0xADE8 ,0x525B},
 {0xADE9 ,0x525D},
 {0xADEA ,0x532A},
 {0xADEB ,0x537F},
 {0xADEC ,0x539F},
 {0xADED ,0x539D},
 {0xADEE ,0x53DF},
 {0xADEF ,0x54E8},
 {0xADF0 ,0x5510},
 {0xADF1 ,0x5501},
 {0xADF2 ,0x5537},
 {0xADF3 ,0x54FC},
 {0xADF4 ,0x54E5},
 {0xADF5 ,0x54F2},
 {0xADF6 ,0x5506},
 {0xADF7 ,0x54FA},
 {0xADF8 ,0x5514},
 {0xADF9 ,0x54E9},
 {0xADFA ,0x54ED},
 {0xADFB ,0x54E1},
 {0xADFC ,0x5509},
 {0xADFD ,0x54EE},
 {0xADFE ,0x54EA},
 {0xAE40 ,0x54E6},
 {0xAE41 ,0x5527},
 {0xAE42 ,0x5507},
 {0xAE43 ,0x54FD},
 {0xAE44 ,0x550F},
 {0xAE45 ,0x5703},
 {0xAE46 ,0x5704},
 {0xAE47 ,0x57C2},
 {0xAE48 ,0x57D4},
 {0xAE49 ,0x57CB},
 {0xAE4A ,0x57C3},
 {0xAE4B ,0x5809},
 {0xAE4C ,0x590F},
 {0xAE4D ,0x5957},
 {0xAE4E ,0x5958},
 {0xAE4F ,0x595A},
 {0xAE50 ,0x5A11},
 {0xAE51 ,0x5A18},
 {0xAE52 ,0x5A1C},
 {0xAE53 ,0x5A1F},
 {0xAE54 ,0x5A1B},
 {0xAE55 ,0x5A13},
 {0xAE56 ,0x59EC},
 {0xAE57 ,0x5A20},
 {0xAE58 ,0x5A23},
 {0xAE59 ,0x5A29},
 {0xAE5A ,0x5A25},
 {0xAE5B ,0x5A0C},
 {0xAE5C ,0x5A09},
 {0xAE5D ,0x5B6B},
 {0xAE5E ,0x5C58},
 {0xAE5F ,0x5BB0},
 {0xAE60 ,0x5BB3},
 {0xAE61 ,0x5BB6},
 {0xAE62 ,0x5BB4},
 {0xAE63 ,0x5BAE},
 {0xAE64 ,0x5BB5},
 {0xAE65 ,0x5BB9},
 {0xAE66 ,0x5BB8},
 {0xAE67 ,0x5C04},
 {0xAE68 ,0x5C51},
 {0xAE69 ,0x5C55},
 {0xAE6A ,0x5C50},
 {0xAE6B ,0x5CED},
 {0xAE6C ,0x5CFD},
 {0xAE6D ,0x5CFB},
 {0xAE6E ,0x5CEA},
 {0xAE6F ,0x5CE8},
 {0xAE70 ,0x5CF0},
 {0xAE71 ,0x5CF6},
 {0xAE72 ,0x5D01},
 {0xAE73 ,0x5CF4},
 {0xAE74 ,0x5DEE},
 {0xAE75 ,0x5E2D},
 {0xAE76 ,0x5E2B},
 {0xAE77 ,0x5EAB},
 {0xAE78 ,0x5EAD},
 {0xAE79 ,0x5EA7},
 {0xAE7A ,0x5F31},
 {0xAE7B ,0x5F92},
 {0xAE7C ,0x5F91},
 {0xAE7D ,0x5F90},
 {0xAE7E ,0x6059},
 {0xAEA1 ,0x6063},
 {0xAEA2 ,0x6065},
 {0xAEA3 ,0x6050},
 {0xAEA4 ,0x6055},
 {0xAEA5 ,0x606D},
 {0xAEA6 ,0x6069},
 {0xAEA7 ,0x606F},
 {0xAEA8 ,0x6084},
 {0xAEA9 ,0x609F},
 {0xAEAA ,0x609A},
 {0xAEAB ,0x608D},
 {0xAEAC ,0x6094},
 {0xAEAD ,0x608C},
 {0xAEAE ,0x6085},
 {0xAEAF ,0x6096},
 {0xAEB0 ,0x6247},
 {0xAEB1 ,0x62F3},
 {0xAEB2 ,0x6308},
 {0xAEB3 ,0x62FF},
 {0xAEB4 ,0x634E},
 {0xAEB5 ,0x633E},
 {0xAEB6 ,0x632F},
 {0xAEB7 ,0x6355},
 {0xAEB8 ,0x6342},
 {0xAEB9 ,0x6346},
 {0xAEBA ,0x634F},
 {0xAEBB ,0x6349},
 {0xAEBC ,0x633A},
 {0xAEBD ,0x6350},
 {0xAEBE ,0x633D},
 {0xAEBF ,0x632A},
 {0xAEC0 ,0x632B},
 {0xAEC1 ,0x6328},
 {0xAEC2 ,0x634D},
 {0xAEC3 ,0x634C},
 {0xAEC4 ,0x6548},
 {0xAEC5 ,0x6549},
 {0xAEC6 ,0x6599},
 {0xAEC7 ,0x65C1},
 {0xAEC8 ,0x65C5},
 {0xAEC9 ,0x6642},
 {0xAECA ,0x6649},
 {0xAECB ,0x664F},
 {0xAECC ,0x6643},
 {0xAECD ,0x6652},
 {0xAECE ,0x664C},
 {0xAECF ,0x6645},
 {0xAED0 ,0x6641},
 {0xAED1 ,0x66F8},
 {0xAED2 ,0x6714},
 {0xAED3 ,0x6715},
 {0xAED4 ,0x6717},
 {0xAED5 ,0x6821},
 {0xAED6 ,0x6838},
 {0xAED7 ,0x6848},
 {0xAED8 ,0x6846},
 {0xAED9 ,0x6853},
 {0xAEDA ,0x6839},
 {0xAEDB ,0x6842},
 {0xAEDC ,0x6854},
 {0xAEDD ,0x6829},
 {0xAEDE ,0x68B3},
 {0xAEDF ,0x6817},
 {0xAEE0 ,0x684C},
 {0xAEE1 ,0x6851},
 {0xAEE2 ,0x683D},
 {0xAEE3 ,0x67F4},
 {0xAEE4 ,0x6850},
 {0xAEE5 ,0x6840},
 {0xAEE6 ,0x683C},
 {0xAEE7 ,0x6843},
 {0xAEE8 ,0x682A},
 {0xAEE9 ,0x6845},
 {0xAEEA ,0x6813},
 {0xAEEB ,0x6818},
 {0xAEEC ,0x6841},
 {0xAEED ,0x6B8A},
 {0xAEEE ,0x6B89},
 {0xAEEF ,0x6BB7},
 {0xAEF0 ,0x6C23},
 {0xAEF1 ,0x6C27},
 {0xAEF2 ,0x6C28},
 {0xAEF3 ,0x6C26},
 {0xAEF4 ,0x6C24},
 {0xAEF5 ,0x6CF0},
 {0xAEF6 ,0x6D6A},
 {0xAEF7 ,0x6D95},
 {0xAEF8 ,0x6D88},
 {0xAEF9 ,0x6D87},
 {0xAEFA ,0x6D66},
 {0xAEFB ,0x6D78},
 {0xAEFC ,0x6D77},
 {0xAEFD ,0x6D59},
 {0xAEFE ,0x6D93},
 {0xAF40 ,0x6D6C},
 {0xAF41 ,0x6D89},
 {0xAF42 ,0x6D6E},
 {0xAF43 ,0x6D5A},
 {0xAF44 ,0x6D74},
 {0xAF45 ,0x6D69},
 {0xAF46 ,0x6D8C},
 {0xAF47 ,0x6D8A},
 {0xAF48 ,0x6D79},
 {0xAF49 ,0x6D85},
 {0xAF4A ,0x6D65},
 {0xAF4B ,0x6D94},
 {0xAF4C ,0x70CA},
 {0xAF4D ,0x70D8},
 {0xAF4E ,0x70E4},
 {0xAF4F ,0x70D9},
 {0xAF50 ,0x70C8},
 {0xAF51 ,0x70CF},
 {0xAF52 ,0x7239},
 {0xAF53 ,0x7279},
 {0xAF54 ,0x72FC},
 {0xAF55 ,0x72F9},
 {0xAF56 ,0x72FD},
 {0xAF57 ,0x72F8},
 {0xAF58 ,0x72F7},
 {0xAF59 ,0x7386},
 {0xAF5A ,0x73ED},
 {0xAF5B ,0x7409},
 {0xAF5C ,0x73EE},
 {0xAF5D ,0x73E0},
 {0xAF5E ,0x73EA},
 {0xAF5F ,0x73DE},
 {0xAF60 ,0x7554},
 {0xAF61 ,0x755D},
 {0xAF62 ,0x755C},
 {0xAF63 ,0x755A},
 {0xAF64 ,0x7559},
 {0xAF65 ,0x75BE},
 {0xAF66 ,0x75C5},
 {0xAF67 ,0x75C7},
 {0xAF68 ,0x75B2},
 {0xAF69 ,0x75B3},
 {0xAF6A ,0x75BD},
 {0xAF6B ,0x75BC},
 {0xAF6C ,0x75B9},
 {0xAF6D ,0x75C2},
 {0xAF6E ,0x75B8},
 {0xAF6F ,0x768B},
 {0xAF70 ,0x76B0},
 {0xAF71 ,0x76CA},
 {0xAF72 ,0x76CD},
 {0xAF73 ,0x76CE},
 {0xAF74 ,0x7729},
 {0xAF75 ,0x771F},
 {0xAF76 ,0x7720},
 {0xAF77 ,0x7728},
 {0xAF78 ,0x77E9},
 {0xAF79 ,0x7830},
 {0xAF7A ,0x7827},
 {0xAF7B ,0x7838},
 {0xAF7C ,0x781D},
 {0xAF7D ,0x7834},
 {0xAF7E ,0x7837},
 {0xAFA1 ,0x7825},
 {0xAFA2 ,0x782D},
 {0xAFA3 ,0x7820},
 {0xAFA4 ,0x781F},
 {0xAFA5 ,0x7832},
 {0xAFA6 ,0x7955},
 {0xAFA7 ,0x7950},
 {0xAFA8 ,0x7960},
 {0xAFA9 ,0x795F},
 {0xAFAA ,0x7956},
 {0xAFAB ,0x795E},
 {0xAFAC ,0x795D},
 {0xAFAD ,0x7957},
 {0xAFAE ,0x795A},
 {0xAFAF ,0x79E4},
 {0xAFB0 ,0x79E3},
 {0xAFB1 ,0x79E7},
 {0xAFB2 ,0x79DF},
 {0xAFB3 ,0x79E6},
 {0xAFB4 ,0x79E9},
 {0xAFB5 ,0x79D8},
 {0xAFB6 ,0x7A84},
 {0xAFB7 ,0x7A88},
 {0xAFB8 ,0x7AD9},
 {0xAFB9 ,0x7B06},
 {0xAFBA ,0x7B11},
 {0xAFBB ,0x7C89},
 {0xAFBC ,0x7D21},
 {0xAFBD ,0x7D17},
 {0xAFBE ,0x7D0B},
 {0xAFBF ,0x7D0A},
 {0xAFC0 ,0x7D20},
 {0xAFC1 ,0x7D22},
 {0xAFC2 ,0x7D14},
 {0xAFC3 ,0x7D10},
 {0xAFC4 ,0x7D15},
 {0xAFC5 ,0x7D1A},
 {0xAFC6 ,0x7D1C},
 {0xAFC7 ,0x7D0D},
 {0xAFC8 ,0x7D19},
 {0xAFC9 ,0x7D1B},
 {0xAFCA ,0x7F3A},
 {0xAFCB ,0x7F5F},
 {0xAFCC ,0x7F94},
 {0xAFCD ,0x7FC5},
 {0xAFCE ,0x7FC1},
 {0xAFCF ,0x8006},
 {0xAFD0 ,0x8018},
 {0xAFD1 ,0x8015},
 {0xAFD2 ,0x8019},
 {0xAFD3 ,0x8017},
 {0xAFD4 ,0x803D},
 {0xAFD5 ,0x803F},
 {0xAFD6 ,0x80F1},
 {0xAFD7 ,0x8102},
 {0xAFD8 ,0x80F0},
 {0xAFD9 ,0x8105},
 {0xAFDA ,0x80ED},
 {0xAFDB ,0x80F4},
 {0xAFDC ,0x8106},
 {0xAFDD ,0x80F8},
 {0xAFDE ,0x80F3},
 {0xAFDF ,0x8108},
 {0xAFE0 ,0x80FD},
 {0xAFE1 ,0x810A},
 {0xAFE2 ,0x80FC},
 {0xAFE3 ,0x80EF},
 {0xAFE4 ,0x81ED},
 {0xAFE5 ,0x81EC},
 {0xAFE6 ,0x8200},
 {0xAFE7 ,0x8210},
 {0xAFE8 ,0x822A},
 {0xAFE9 ,0x822B},
 {0xAFEA ,0x8228},
 {0xAFEB ,0x822C},
 {0xAFEC ,0x82BB},
 {0xAFED ,0x832B},
 {0xAFEE ,0x8352},
 {0xAFEF ,0x8354},
 {0xAFF0 ,0x834A},
 {0xAFF1 ,0x8338},
 {0xAFF2 ,0x8350},
 {0xAFF3 ,0x8349},
 {0xAFF4 ,0x8335},
 {0xAFF5 ,0x8334},
 {0xAFF6 ,0x834F},
 {0xAFF7 ,0x8332},
 {0xAFF8 ,0x8339},
 {0xAFF9 ,0x8336},
 {0xAFFA ,0x8317},
 {0xAFFB ,0x8340},
 {0xAFFC ,0x8331},
 {0xAFFD ,0x8328},
 {0xAFFE ,0x8343},
};

U16 MApp_Big52Unicode_A9AF(U16 u16Big5Code)
{
    S16 s16Start = 0;
    S16 s16End = sizeof(au16BIG5Unicode_A9AF)/sizeof(BIG5UnicodeTbl);
    S16 s16Pos;
    BOOLEAN bContinue = TRUE;
    U16 u16Unicode = INVALID_UNICODE;

        while(bContinue)
        {
            s16Pos = (s16Start + s16End) / 2;
            if(u16Big5Code > au16BIG5Unicode_A9AF[s16Pos].u16Big5code)
            {
                s16Start = s16Pos + 1;
                if(s16Start > s16End)
                {
                    bContinue = FALSE;
                }
            }
            else if(u16Big5Code < au16BIG5Unicode_A9AF[s16Pos].u16Big5code)
            {
                s16End = s16Pos - 1;
                if(s16Start > s16End)
                {
                    bContinue = FALSE;
                }
            }
            else
            {
                u16Unicode = au16BIG5Unicode_A9AF[s16Pos].u16Unicode;
                bContinue = FALSE;
            }
        }

    return u16Unicode;
}

#else
code U16 TempBIG5Unicode_A9AF[]={1};
#endif  // #if (ENABLE_DVB_TAIWAN_APP ||CHINESE_BIG5_FONT_ENABLE)
#endif  //#if (ENABLE_DMP)

#undef MAPP_BIG52UNICODE_A9AF_C

