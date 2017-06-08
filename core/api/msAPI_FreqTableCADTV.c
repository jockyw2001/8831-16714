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
#include "Board.h"

#if ENABLE_DTV

//****************************************************************************
//                          Header
//****************************************************************************
#include <string.h>
#include "datatype.h"
#include "MsCommon.h"
#include "msAPI_FreqTableCommon.h"

#if ENABLE_DVBC
#include "msAPI_FreqTableCADTV.h"

//****************************************************************************
//                          Definition
//****************************************************************************
#define DVBC_MAX_NIT_FREQ_NUM       50

//****************************************************************************
//                          Structure
//****************************************************************************
typedef struct
{
    U32 *pu32FreqTbl;
    U8 u8FreqTblSize;
    U8 u8CurrentFreqIndex;
}DVBC_BUILTIN_FREQ_TBL_INFO;

typedef struct
{
    U32 u32NewFreqTbl[DVBC_MAX_NIT_FREQ_NUM];
    U8 u8NewFreqTblSize;
    U8 u8NewFreqIndex;
}DVBC_NIT_FREQ_TBL_INFO;

//****************************************************************************
//                          Local variables
//****************************************************************************

/*sibelm_12082009 | Scan Modification: Channel Install modification according to Nordic spec v2.1*/
const U32 Ch_Freq_Nordic[]=
{
/*sibelm_22082009 | Denmark Field Test: 156MHz is added to Nordic Table*/
	114000,	122000,	130000,	138000,
	146000,	154000,	156000,  162000,
	170000,	178000,	186000,	194000,
	202000,	210000,   218000,	226000,
	234000,	242000,	250000,	258000,
	266000,	274000,	282000,	290000,
	298000,	306000,	314000,	322000,
	330000,	338000,	346000,	354000,
	362000,	370000,	378000,	386000,
	394000,	402000,	410000,	418000,
	426000,	434000,	442000,	450000,
	458000,	466000,	474000,	482000,
	490000,	498000,	506000,	514000,
	522000,	530000,	538000,	546000,
	554000,	562000,	570000,	578000,
	586000,	594000,	602000,	610000,
	618000,	626000,	634000,	642000,
	650000,	658000,	666000,	674000,
	682000,	690000,	698000,	706000,
	714000,	722000,	730000,	738000,
	746000,	754000,	762000,	770000,
	778000,	786000,	794000,	802000,
	810000,	818000,	826000,	834000,
	842000,	850000,	858000, NULL,
};


const U32 Ch_Freq_Switzerland[]=
{
//MidBand
     107500,     114000,	   114500,     121500,
     122000,     128500,     130000,     135500,
     138000,     142500,     146000,     149500,
     154000,	156500,     162000,      163500,
     170000,	170500,     177500,      178000,
     184500,     186000,     191500,     194000,
     198500,     202000, 	   205500,     210000,
     212500,     218000,     219500,     226000,
     226500,
//Superband
     233500,    234000,     240500,      242000,
     247500,    250000,	  254500,	     258000,
     261500,    266000,     268500,      274000,
     275500,    282000,     282500,      289500,
     290000,    296500,	  298000,

//Hyperband
     306000,     314000,     322000,     330000,
     338000,     346000,     354000,     362000,
     370000,     378000,     386000,     394000,
     402000,     410000,     418000,     426000,
     434000,     442000,     450000,     458000,
     466000,
//Band IV
     474000,     482000,     490000,     498000,
     506000,     514000,     522000,     530000,
     538000,     546000,     554000,     562000,
     570000,     578000,
//Band V
     586000,     594000,     602000,     610000,
     618000,     626000,     634000,     642000,
     650000,     658000,     666000,     674000,
     682000,     690000,     698000,     706000,
     714000,     722000,     730000,     738000,
     746000,     754000,     762000,     770000,
     778000,     786000,     794000,     802000,
     810000,     818000,     826000,     834000,
     842000,     850000,     858000,        NULL,
};

const U32 Ch_Freq_Turkey[] =
{
/*
    For testing
    121000,    482000,    490000,    498000,
    506000,    514000,    522000,    458000,
*/
//Midband
     107500,      113000,     114000,     121000,
     122000,	 128500,     130000,     135500,
     138000,      142500,     146000,     149500,
     154000,      156500,     162000,     163500,
     170000,	 170500,
//Band III
     177500,     178000,	   184500,     186000,
     191500,     194000,	   198500,     202000,
     205500,     210000,	   212500,     218000,
     219500,     226000,     226500,     227000,
//Superband
     233500,     234000,     240500,     242000,
     247500,     250000,	   254500,     258000,
     261500,     266000,     268500,     274000,
     275500,     282000,     282500,     289500,
     290000,     296500,     298000,
//Hyperband
     306000,     314000,     322000,     330000,
     338000,     346000,     354000,     362000,
     370000,     378000,     386000,     394000,
     402000,     410000,     418000,     426000,
     434000,     442000,     450000,     458000,
     466000,
//Band IV
     474000,     482000,     490000,     498000,
     506000,     514000,     522000,     530000,
     538000,     546000,     554000,     562000,
     570000,     578000,
//Band V
     586000,     594000,     602000,     610000,
     618000,     626000,     634000,     642000,
     650000,     658000,     666000,     674000,
     682000,     690000,     698000,     706000,
     714000,     722000,     730000,     738000,
     746000,     754000,     762000,     770000,
     778000,     786000,     794000,     802000,
     810000,     818000,     826000,     834000,
     842000,     850000,     858000,        NULL,

};

const U32 Ch_Freq_China[] =
{
//Z1~Z7
     115000,     123000,     131000,     139000,
     147000,     155000,     163000,
//DS6~DS12
     171000,     179000,     187000,     195000,
     203000,     211000,     219000,
//Z8~Z37
     227000,     235000,     243000,     251000,
     259000,     267000,     275000,     283000,
     291000,     299000,     307000,     315000,
     323000,     331000,     339000,     347000,
     355000,     363000,     371000,     379000,
     387000,     395000,     403000,     411000,
     419000,     427000,     435000,     443000,
     451000,     459000,
//ZZ
     466000,
//DS13~DS24
     474000,     482000,     490000,     498000,
     506000,     514000,     522000,     530000,
     538000,     546000,     554000,     562000,
//Z38~Z42
     570000,     578000,     586000,     594000,
     602000,
//DS25~DS56
     610000,     618000,     626000,     634000,
     642000,     650000,     658000,     666000,
     674000,     682000,     690000,     698000,
     706000,     714000,     722000,     730000,
     738000,     746000,     754000,     762000,
     770000,     778000,     786000,     794000,
     802000,     810000,     818000,     826000,
     834000,     842000,     850000,     858000,
     NULL,

};

//****************************************************************************
//                          Global variables
//****************************************************************************
DVBC_BUILTIN_FREQ_TBL_INFO stDVBCBuiltInFreqTbl;
DVBC_NIT_FREQ_TBL_INFO stDVBCNitFreqTbl;
//****************************************************************************
//                          Private function prototype
//****************************************************************************

//****************************************************************************
//                          Private functions
//****************************************************************************


//****************************************************************************
//                          Global functions
//****************************************************************************
void msAPI_DCFT_SelectBuiltInFreqTableforCountry(EN_OSD_COUNTRY_SETTING eCountry)
{
    switch(eCountry)
    {
        case OSD_COUNTRY_BELGIUM:
        case OSD_COUNTRY_CROATIA:
        case OSD_COUNTRY_ESTONIA:
        case OSD_COUNTRY_SLOVENIA:
        case OSD_COUNTRY_SPAIN:
        case OSD_COUNTRY_FINLAND:
        case OSD_COUNTRY_SWEDEN:
        case OSD_COUNTRY_DENMARK:
        case OSD_COUNTRY_NORWAY:
        {
            stDVBCBuiltInFreqTbl.pu32FreqTbl= (U32 *)Ch_Freq_Nordic;
            stDVBCBuiltInFreqTbl.u8FreqTblSize=sizeof(Ch_Freq_Nordic)/sizeof(U32);
            stDVBCBuiltInFreqTbl.u8CurrentFreqIndex = 0;
        }
        break;

        case OSD_COUNTRY_SWITZERLAND:
        {
            stDVBCBuiltInFreqTbl.pu32FreqTbl = (U32 *)Ch_Freq_Switzerland;
            stDVBCBuiltInFreqTbl.u8FreqTblSize=sizeof(Ch_Freq_Switzerland)/sizeof(U32);
            stDVBCBuiltInFreqTbl.u8CurrentFreqIndex = 0;
        }
        break;

        case OSD_COUNTRY_TURKEY:
        case OSD_COUNTRY_GERMANY:
        {
            stDVBCBuiltInFreqTbl.pu32FreqTbl = (U32 *)Ch_Freq_Turkey;
            stDVBCBuiltInFreqTbl.u8FreqTblSize=sizeof(Ch_Freq_Turkey)/sizeof(U32);
            stDVBCBuiltInFreqTbl.u8CurrentFreqIndex = 0;
        }
        break;

        case OSD_COUNTRY_CHINA:
        {
            stDVBCBuiltInFreqTbl.pu32FreqTbl = (U32 *)Ch_Freq_China;
            stDVBCBuiltInFreqTbl.u8FreqTblSize=sizeof(Ch_Freq_China)/sizeof(U32);
            stDVBCBuiltInFreqTbl.u8CurrentFreqIndex = 0;
        }
        break;

        default:
            stDVBCBuiltInFreqTbl.pu32FreqTbl = (U32 *)Ch_Freq_Turkey;
            stDVBCBuiltInFreqTbl.u8FreqTblSize=sizeof(Ch_Freq_Turkey)/sizeof(U32);
            stDVBCBuiltInFreqTbl.u8CurrentFreqIndex = 0;
        break;
    }
}

U32 msAPI_DCFT_GetBuiltInNextFreq(U32 u32Freq)
{
    U8 u8i;
    if ((NULL == stDVBCBuiltInFreqTbl.pu32FreqTbl) ||(0 == stDVBCBuiltInFreqTbl.u8FreqTblSize))
    {
        return NULL;
    }

    if (u32Freq)
    {
        for (u8i=0;u8i<stDVBCBuiltInFreqTbl.u8FreqTblSize;u8i++)
        {
            if (NULL == stDVBCBuiltInFreqTbl.pu32FreqTbl[u8i])
                return NULL;
            if (stDVBCBuiltInFreqTbl.pu32FreqTbl[u8i]>u32Freq)
            {
                stDVBCBuiltInFreqTbl.u8CurrentFreqIndex = u8i+1;
                return stDVBCBuiltInFreqTbl.pu32FreqTbl[u8i];
            }
        }
    }
    else
    {
        if ((stDVBCBuiltInFreqTbl.u8CurrentFreqIndex+1)<stDVBCBuiltInFreqTbl.u8FreqTblSize)
        {
            return stDVBCBuiltInFreqTbl.pu32FreqTbl[stDVBCBuiltInFreqTbl.u8CurrentFreqIndex++];
        }
    }
    return NULL;
}

BOOLEAN msAPI_DCFT_IsThisFreqInBuiltinFreqTbl(U32 u32Freq)
{
    U8 u8i;

    if ((NULL == stDVBCBuiltInFreqTbl.pu32FreqTbl) ||(0 == stDVBCBuiltInFreqTbl.u8FreqTblSize))
    {
        return FALSE;
    }

    for(u8i=0;u8i<stDVBCBuiltInFreqTbl.u8FreqTblSize;u8i++)
    {
        if (NULL == stDVBCBuiltInFreqTbl.pu32FreqTbl[u8i])
        {
            return FALSE;
        }
        if (stDVBCBuiltInFreqTbl.pu32FreqTbl[u8i] == u32Freq)
        {
            return TRUE;
        }
    }
    return FALSE;
}

void msAPI_DCFT_ResetNITNewFreqTbl(void)
{
    memset(&stDVBCNitFreqTbl, 0 , sizeof(DVBC_NIT_FREQ_TBL_INFO));
}

void msAPI_DCFT_SetFreqToNITNewFreqTbl(U32 u32Freq)
{
    if ((stDVBCNitFreqTbl.u8NewFreqTblSize) < DVBC_MAX_NIT_FREQ_NUM)
    {
        stDVBCNitFreqTbl.u32NewFreqTbl[stDVBCNitFreqTbl.u8NewFreqTblSize++] = u32Freq;
    }
}

U32 msAPI_DCFT_GetNITNextFreq(void)
{
    if (0 == stDVBCNitFreqTbl.u8NewFreqTblSize)
    {
        return NULL;
    }
    if ((stDVBCNitFreqTbl.u8NewFreqIndex)<stDVBCNitFreqTbl.u8NewFreqTblSize)
    {
        return stDVBCNitFreqTbl.u32NewFreqTbl[stDVBCNitFreqTbl.u8NewFreqIndex++];
    }
    else
    {
        return NULL;
    }
}

U8 msAPI_DCFT_CalculatePercentTbl(void)
{
    U8 OutputVal = 0;
    if(stDVBCBuiltInFreqTbl.u8CurrentFreqIndex > stDVBCBuiltInFreqTbl.u8FreqTblSize)
        OutputVal = (((stDVBCBuiltInFreqTbl.u8CurrentFreqIndex + stDVBCNitFreqTbl.u8NewFreqIndex) *100) /
        (stDVBCBuiltInFreqTbl.u8FreqTblSize +stDVBCNitFreqTbl.u8NewFreqTblSize));
    else
        OutputVal = ((stDVBCBuiltInFreqTbl.u8CurrentFreqIndex* 100) /
        (stDVBCBuiltInFreqTbl.u8FreqTblSize +stDVBCNitFreqTbl.u8NewFreqTblSize));
    #if 0
    printf("#########################################\n");
    printf("#### stDVBCBuiltInFreqTbl.u8CurrentFreqIndex = %d\n",stDVBCBuiltInFreqTbl.u8CurrentFreqIndex);
    printf("#### stDVBCNitFreqTbl.u8NewFreqIndex = %d\n",stDVBCNitFreqTbl.u8NewFreqIndex);
    printf("#### stDVBCBuiltInFreqTbl.u8FreqTblSize = %d\n",stDVBCBuiltInFreqTbl.u8FreqTblSize);
    printf("#### stDVBCNitFreqTbl.u8NewFreqTblSize = %d\n",stDVBCNitFreqTbl.u8NewFreqTblSize);
    printf("####  OutputVal = %d\n", OutputVal);
    #endif
    return OutputVal;
}

#endif
#endif

