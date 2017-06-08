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

////////////////////////////////////////////////////////////////////////////////
//
/// @file msAPI_ChProc.h
/// This file includes MStar Channel processing Application interface
/// @brief API for Channel Process
/// @author MStar Semiconductor, Inc.
///
////////////////////////////////////////////////////////////////////////////////
#include "Board.h"
#include "datatype.h"
#include "MsCommon.h"
#include "Utl.h"
#include "apiXC.h"
#include "apiXC_Adc.h"
#include "msAPI_ATVSystem.h"
#include "msAPI_ChProc.h"
#include "msAPI_DTVSystem.h"
#include "MApp_ATVProc.h"
#include "msAPI_audio.h"
#include "msAPI_VD.h"
#include "msAPI_Tuning.h"
#include "msAPI_Timer.h"
#include "MApp_GlobalFunction.h"

#if ENABLE_SBTVD_BRAZIL_CM_APP
#define MAX_ATV_DTV  MAX_ATVPROGRAM + MAX_DTVPROGRAM
#define INVALID_POSITION  0xFFFF


typedef struct
{
    MEMBER_SERVICETYPE eServicetype;
    U16 wPosition;
    union
    {
        ST_LCN stLCN;
        U16 u16LCN;
    };
}ORIDINAL_LIST;
#endif

//****************************************************************************
// Private attributes of this file.
//****************************************************************************
#if ENABLE_SBTVD_BRAZIL_CM_APP
static ORIDINAL_LIST aOridinalList[MAX_ATV_DTV];
static WORD wMAX_OridinalCount;
#endif
//****************************************************************************
// Private functions of this file.
//****************************************************************************

//static BYTE _AlignDecimalToLeft(BYTE *pcBuffer, WORD wNumber);
//static BOOLEAN _IsAlignedDecimalSame(BYTE *pcBuffer1, BYTE *pcBuffer2, BYTE cLength);
static WORD _GetNextFavoriteOrdinalOfUnitedTV(WORD wBaseOrdinal, BOOLEAN bIncludeSkipped);
static WORD _GetPrevFavoriteOrdinalOfUnitedTV(WORD wBaseOrdinal, BOOLEAN bIncludeSkipped);

#if ENABLE_SBTVD_BRAZIL_CM_APP
static BOOLEAN SwapOridinal(WORD wFromOrder, WORD wToOrder);
static void Set_MAXOridinal(WORD u16Max_Ori);
static WORD Get_MAXOridinal(void);
//static WORD msAPI_CHPROC_CM_GetOrdinal_Brazil(MEMBER_SERVICETYPE bServiceType,WORD wPosition);
//static void msAPI_CHPROC_CM_GetOrdinal_SerType_Position_Brazil(WORD wOridinal,MEMBER_SERVICETYPE * pbServiceType,WORD * pwPosition);
#endif
//****************************************************************************
// Start of public implementation
//****************************************************************************

/******************************************************************************/
/// -This function will get Current Ordinal
/// @param bServiceType \b IN: Service type
/// - @see MEMBER_SERVICETYPE
/// @param eBoundary \b IN: Boundary
/// - @see E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY
/// @return WORD: Current ordinal
/******************************************************************************/
WORD msAPI_CHPROC_CM_GetCurrentOrdinal(MEMBER_SERVICETYPE bServiceType, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY eBoundary)
{
    #if ENABLE_SBTVD_BRAZIL_CM_APP
    WORD wCurPosition;
    #endif
#if (!ENABLE_DVB)
    UNUSED(eBoundary);
#endif
    switch(bServiceType)
    {
#if (ENABLE_DVB)
    case E_SERVICETYPE_RADIO:
    case E_SERVICETYPE_DTV:
#if NORDIG_FUNC //for Nordig Spec v2.0
    case E_SERVICETYPE_DATA:
#endif
        return msAPI_CM_GetCurrentPosition(bServiceType);
#endif
    case E_SERVICETYPE_ATV:
        return (WORD)msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetCurrentProgramNumber());

    case E_SERVICETYPE_UNITED_TV:
        #if ENABLE_SBTVD_BRAZIL_CM_APP
        if(ANT_CATV == msAPI_ATV_GetCurrentAntenna())
        {
            return (WORD)msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetCurrentProgramNumber());
        }
        #endif
#if (ENABLE_DVB)
	#if(ENABLE_S2)
        if(TRUE == IsDTVInUse() || TRUE == IsS2InUse())
	#else
        if( TRUE == IsDTVInUse() )
	#endif
        {
            if(IS_LCN_RANK_COUNTRY(OSD_COUNTRY_SETTING))
            {
                WORD wPosition;
                MEMBER_SERVICETYPE eServiceType;
                eServiceType = msAPI_CM_GetCurrentServiceType();
                wPosition = msAPI_CM_GetCurrentPosition(eServiceType);
                return msAPI_CM_GetListPositionbyPosition(wPosition,eServiceType);
            }

            if(msAPI_CM_GetCurrentServiceType()==E_SERVICETYPE_RADIO)
            {
                if(0==msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary))
                    return INVALID_ORDINAL;

                #if ENABLE_SBTVD_BRAZIL_CM_APP
                wCurPosition = msAPI_CM_GetCurrentPosition(E_SERVICETYPE_RADIO);
                return msAPI_CHPROC_CM_GetOrdinal_Brazil(E_SERVICETYPE_RADIO,wCurPosition);
                #else // ENABLE_SBTVD_BRAZIL_CM_APP
                return msAPI_CM_GetCurrentPosition(E_SERVICETYPE_RADIO) + msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary);
                #endif
            }
            #if NORDIG_FUNC //for Nordig Spec v2.0
            else if(msAPI_CM_GetCurrentServiceType()==E_SERVICETYPE_DATA)
            {
                if(0==msAPI_CM_CountProgram(E_SERVICETYPE_DATA, eBoundary))
                    return INVALID_ORDINAL;

                return msAPI_CM_GetCurrentPosition(E_SERVICETYPE_DATA) + msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary);
            }
            #endif
            else
            {
                if(0==msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary))
                    return INVALID_ORDINAL;

                #if ENABLE_SBTVD_BRAZIL_CM_APP
                wCurPosition = msAPI_CM_GetCurrentPosition(E_SERVICETYPE_DTV);
                return msAPI_CHPROC_CM_GetOrdinal_Brazil(E_SERVICETYPE_DTV,wCurPosition);
                #else
                return msAPI_CM_GetCurrentPosition(E_SERVICETYPE_DTV);
                #endif
            }
        }
        else
#endif
        if( TRUE == IsATVInUse() )
        {
            #if NORDIG_FUNC //for Nordig Spec v2.0
            return (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_DATA, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary) + msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetCurrentProgramNumber()));
            #else
            #if ENABLE_SBTVD_BRAZIL_CM_APP
            wCurPosition = msAPI_ATV_GetCurrentProgramNumber();
            return msAPI_CHPROC_CM_GetOrdinal_Brazil(E_SERVICETYPE_ATV,wCurPosition);
            #else
#if (ENABLE_DVB)
            return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary) + msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetCurrentProgramNumber());
#else
            return msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetCurrentProgramNumber());
#endif


            #endif
            #endif
        }
        break;

    default:
        break;
    }

    return INVALID_ORDINAL;
}

/******************************************************************************/
/// -This function will set Current Ordinal
/// @param bServiceType \b IN: Service type
/// - @see MEMBER_SERVICETYPE
/// @param wOrdinal \b IN: Current ordinal
/// @param eBoundary \b IN: Boundary
/// - @see E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY
/// @return FUNCTION_RESULT: Function execution result
/******************************************************************************/
BOOLEAN msAPI_CHPROC_CM_SetCurrentOrdinal(MEMBER_SERVICETYPE bServiceType, WORD wOrdinal, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY eBoundary)
{
    #if ENABLE_SBTVD_BRAZIL_CM_APP
    if(ANT_CATV == msAPI_ATV_GetCurrentAntenna())
        bServiceType = E_SERVICETYPE_ATV;
    #endif
#if (!ENABLE_DVB)
    UNUSED(eBoundary);
#endif
    switch(bServiceType)
    {
#if (ENABLE_DVB)
    case E_SERVICETYPE_RADIO:
    case E_SERVICETYPE_DTV:
    #if NORDIG_FUNC //for Nordig Spec v2.0
    case E_SERVICETYPE_DATA:
    #endif
        if( wOrdinal < msAPI_CM_CountProgram(bServiceType, eBoundary) )
        {
            msAPI_CM_SetCurrentServiceType(bServiceType);
            msAPI_CM_SetCurrentPosition(bServiceType, wOrdinal);
            return TRUE;
        }
        break;
#endif
    case E_SERVICETYPE_ATV:
        msAPI_ATV_SetCurrentProgramNumber(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wOrdinal));
        msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE_DURING_LIMITED_TIME, DELAY_FOR_STABLE_SIF, E_AUDIOMUTESOURCE_ATV);
        //BY 20090406 msAPI_VD_AdjustVideoFactor(E_ADJUST_VIDEOMUTE_DURING_LIMITED_TIME, DELAY_FOR_STABLE_TUNER);
        msAPI_AVD_TurnOffAutoAV();
        msAPI_Tuner_ChangeProgram();
        //msAPI_VD_ClearSyncCheckCounter();
        msAPI_AVD_ClearAspectRatio();

        return TRUE;

    case E_SERVICETYPE_UNITED_TV:  // Service Type Check..
        #if ENABLE_SBTVD_BRAZIL_CM_APP
        {
            MEMBER_SERVICETYPE  eServiceType;
            WORD   wPosition;
            BYTE   bPosition = INVALID_ATV_PROGRAM_NUMBER;

            msAPI_CHPROC_CM_GetOrdinal_SerType_Position_Brazil(wOrdinal,(MEMBER_SERVICETYPE *)&eServiceType, (WORD *)&wPosition);
            if(eServiceType == E_SERVICETYPE_ATV)
                bPosition = (wPosition >> 8);

            switch(eServiceType)
            {
                case E_SERVICETYPE_RADIO:
                case E_SERVICETYPE_DTV:
                //case E_SERVICETYPE_DATA:

                    msAPI_CM_SetCurrentServiceType(eServiceType);
                    msAPI_CM_SetCurrentPosition(eServiceType, wPosition);
                    break;
                case E_SERVICETYPE_ATV:
                default:
                    msAPI_ATV_SetCurrentProgramNumber(bPosition);
                    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE_DURING_LIMITED_TIME, DELAY_FOR_STABLE_SIF, E_AUDIOMUTESOURCE_ATV);

                    msAPI_AVD_TurnOffAutoAV();
                    msAPI_Tuner_ChangeProgram();
                    //msAPI_VD_ClearSyncCheckCounter();
                    msAPI_AVD_ClearAspectRatio();
                    break;
            }

            return TRUE;
        }
        #else // ENABLE_SBTVD_BRAZIL_CM_APP
#if (ENABLE_DVB)
    #if NORDIG_FUNC
        if((IS_LCN_RANK_COUNTRY(OSD_COUNTRY_SETTING))&&( wOrdinal < (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)+ msAPI_CM_CountProgram(E_SERVICETYPE_DATA, eBoundary)) ))
    #else
        if((IS_LCN_RANK_COUNTRY(OSD_COUNTRY_SETTING))&&( wOrdinal < (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)) ))
    #endif
        {
            WORD wPoistion;
            MEMBER_SERVICETYPE eServicetype = E_SERVICETYPE_INVALID;
            wPoistion = msAPI_CM_GetPositionbyListPosition(wOrdinal,&eServicetype);
            msAPI_CM_SetCurrentServiceType(eServicetype);
            msAPI_CM_SetCurrentPosition(eServicetype, wPoistion);
            return TRUE;
        }

        if( wOrdinal < msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) )
        {
            msAPI_CM_SetCurrentServiceType(E_SERVICETYPE_DTV);
            msAPI_CM_SetCurrentPosition(E_SERVICETYPE_DTV, wOrdinal);
            return TRUE;
        }
        else if( wOrdinal < (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)) )
        {
            msAPI_CM_SetCurrentServiceType(E_SERVICETYPE_RADIO);
            msAPI_CM_SetCurrentPosition(E_SERVICETYPE_RADIO, (wOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)));
            return TRUE;
        }
        #if NORDIG_FUNC //for Nordig Spec v2.0
        else if( wOrdinal < (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)+ msAPI_CM_CountProgram(E_SERVICETYPE_DATA, eBoundary)) )
        {
            msAPI_CM_SetCurrentServiceType(E_SERVICETYPE_DATA);
            msAPI_CM_SetCurrentPosition(E_SERVICETYPE_DATA, (wOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)- msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)));
            return TRUE;
        }
        #endif
        else
#endif
        {
            #if NORDIG_FUNC //for Nordig Spec v2.0
            msAPI_ATV_SetCurrentProgramNumber(msAPI_ATV_ConvertOrdinalNumberToProgramNumber((wOrdinal-msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) - msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary) - msAPI_CM_CountProgram(E_SERVICETYPE_DATA, eBoundary))));
            #else
#if (ENABLE_DVB)
            msAPI_ATV_SetCurrentProgramNumber(msAPI_ATV_ConvertOrdinalNumberToProgramNumber((wOrdinal-msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) - msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary))));
#else
            msAPI_ATV_SetCurrentProgramNumber(msAPI_ATV_ConvertOrdinalNumberToProgramNumber((wOrdinal)));
#endif
            #endif
            msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE_DURING_LIMITED_TIME, DELAY_FOR_STABLE_SIF, E_AUDIOMUTESOURCE_ATV);
            //BY 20090406 msAPI_VD_AdjustVideoFactor(E_ADJUST_VIDEOMUTE_DURING_LIMITED_TIME, DELAY_FOR_STABLE_TUNER);
            msAPI_AVD_TurnOffAutoAV();
            msAPI_Tuner_ChangeProgram();
            //msAPI_VD_ClearSyncCheckCounter();
            msAPI_AVD_ClearAspectRatio();

            return TRUE;
        }
        #endif // ENABLE_SBTVD_BRAZIL_CM_APP
        break;

    default:
        break;
    }

    return FALSE;
}
/******************************************************************************/
/// -This function will set Move 2 Ordinal
/// @param bServiceType \b IN: Service type
/// - @see MEMBER_SERVICETYPE
/// @param wOrdinal \b IN: Current ordinal
/// @param eBoundary \b IN: Boundary
/// - @see E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY
/// @return FUNCTION_RESULT: Function execution result
/******************************************************************************/
BOOLEAN msAPI_CHPROC_CM_SetMove2CurrentOrdinal(MEMBER_SERVICETYPE bServiceType, WORD wOrdinal, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY eBoundary)
{
#if (!ENABLE_DVB)
    UNUSED(eBoundary);
#endif
    switch(bServiceType)
    {
#if (ENABLE_DVB)
    case E_SERVICETYPE_RADIO:
    case E_SERVICETYPE_DTV:
    #if NORDIG_FUNC //for Nordig Spec v2.0
    case E_SERVICETYPE_DATA:
    #endif
        if( wOrdinal < msAPI_CM_CountProgram(bServiceType, eBoundary) )
        {
            msAPI_CM_SetCurrentServiceType(bServiceType);
            msAPI_CM_SetCurrentPosition(bServiceType, wOrdinal);
            return TRUE;
        }
        break;
#endif
    case E_SERVICETYPE_ATV:
        msAPI_ATV_SetCurrentProgramNumber((BYTE)wOrdinal);
        return TRUE;

    case E_SERVICETYPE_UNITED_TV:  // Service Type Check..
#if (ENABLE_DVB)
        if( wOrdinal < msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) )
        {
            msAPI_CM_SetCurrentServiceType(E_SERVICETYPE_DTV);
            msAPI_CM_SetCurrentPosition(E_SERVICETYPE_DTV, wOrdinal);
            return TRUE;
        }
        else if( wOrdinal < (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)) )
        {
            msAPI_CM_SetCurrentServiceType(E_SERVICETYPE_RADIO);
            msAPI_CM_SetCurrentPosition(E_SERVICETYPE_RADIO, (wOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary))); //CL191492    ,TRUE);
            return TRUE;
        }
        #if NORDIG_FUNC //for Nordig Spec v2.0
        else if( wOrdinal < (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_DATA, eBoundary)) )
        {
            msAPI_CM_SetCurrentServiceType(E_SERVICETYPE_DATA);
            msAPI_CM_SetCurrentPosition(E_SERVICETYPE_DATA, (wOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) - msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)));
            return TRUE;
        }
        #endif
        else
#endif
        {
            #if NORDIG_FUNC //for Nordig Spec v2.0
            msAPI_ATV_SetCurrentProgramNumber(msAPI_ATV_ConvertOrdinalNumberToProgramNumber((wOrdinal-msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) - msAPI_CM_CountProgram(E_SERVICETYPE_DATA, eBoundary) - msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary))));
            #else
#if (ENABLE_DVB)
            msAPI_ATV_SetCurrentProgramNumber(msAPI_ATV_ConvertOrdinalNumberToProgramNumber((wOrdinal-msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) - msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary))));
#else
            msAPI_ATV_SetCurrentProgramNumber(msAPI_ATV_ConvertOrdinalNumberToProgramNumber((wOrdinal)));
#endif

            #endif
            return TRUE;
        }
        break;

    default:
        break;
    }

    return FALSE;
}
/******************************************************************************/
/// -This function will count program
/// @param bServiceType \b IN: Service type
/// - @see MEMBER_SERVICETYPE
/// @param eBoundary \b IN: Boundary
/// - @see E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY
/// @return WORD: program count
/******************************************************************************/
WORD msAPI_CHPROC_CM_CountProgram(MEMBER_SERVICETYPE bServiceType, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY eBoundary)
{
    UNUSED(eBoundary);

    switch(bServiceType)
    {
#if (ENABLE_DVB)
    case E_SERVICETYPE_RADIO:
    case E_SERVICETYPE_DTV:
  #if NORDIG_FUNC //for Nordig Spec v2.0
    case E_SERVICETYPE_DATA:
  #endif
        return msAPI_CM_CountProgram(bServiceType, eBoundary);
#endif

    case E_SERVICETYPE_ATV:
        return (WORD)msAPI_ATV_GetActiveProgramCount();

    case E_SERVICETYPE_UNITED_TV:
    {
#if 1
        U16 u16SvcDtvCount = 0;
        U16 u16SvcRadioCount = 0;
        U16 u16SvcDataCount = 0;
        U16 u16AtvCount = msAPI_ATV_GetActiveProgramCount();
        U16 u16UNITED_TV_Count = 0;

    #if(ENABLE_DVB)
        u16SvcDtvCount = msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary);
        u16SvcRadioCount = msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary);
      #if NORDIG_FUNC //for Nordig Spec v2.0
        u16SvcDataCount = msAPI_CM_CountProgram(E_SERVICETYPE_DATA, eBoundary);
      #endif
    #endif

        u16UNITED_TV_Count = u16SvcDtvCount + u16SvcRadioCount + u16SvcDataCount;

      #if ENABLE_S2
        if( !IsS2InUse() )
      #endif
        {
            u16UNITED_TV_Count += u16AtvCount;
        }

        return u16UNITED_TV_Count;
#else

    #if NORDIG_FUNC //for Nordig Spec v2.0
        #if ENABLE_S2
            if (IsS2InUse())
                return (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)+msAPI_CM_CountProgram(E_SERVICETYPE_DATA, eBoundary)+msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary));
            else
        #endif
                return (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)+msAPI_CM_CountProgram(E_SERVICETYPE_DATA, eBoundary)+msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)+msAPI_ATV_GetActiveProgramCount());
    #else
      #if (ENABLE_DVB)
        #if ENABLE_S2
            if (IsS2InUse())
                return (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)+msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary));
            else
        #endif
            return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)+msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)+msAPI_ATV_GetActiveProgramCount();
      #else
            return msAPI_ATV_GetActiveProgramCount();
      #endif
    #endif
#endif

    }
        break;


    default:
        printf("\nWarning: Unsupported bServiceType=%u!\n", bServiceType);
        break;
    }

    return 0;
}

/******************************************************************************/
/// -This function will get next ordinal
/// @param bServiceType \b IN: Service type
/// - @see MEMBER_SERVICETYPE
/// @param wBaseOrdinal \b IN: base ordinal
/// @param bIncludeSkipped \b IN: Include skipped program or not
/// - TRUE: Include skipped program
/// - FALSE: Don't include
/// @return WORD: program count
/******************************************************************************/
WORD msAPI_CHPROC_CM_GetNextOrdinal(MEMBER_SERVICETYPE bServiceType, WORD wBaseOrdinal, BOOLEAN bIncludeSkipped)
{
#if ENABLE_SBTVD_BRAZIL_CM_APP
    U16 u16MaxOridinal = Get_MAXOridinal();
    U16 i, u16TotalPgmCount;
    BOOLEAN bSkipCh;

    u16TotalPgmCount = msAPI_CHPROC_CM_CountProgram(bServiceType, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
    for(i=0; i<u16TotalPgmCount; i++)
    {
        if(wBaseOrdinal < (u16MaxOridinal-1))
            wBaseOrdinal++;
        else
            wBaseOrdinal = 0;

        if(bIncludeSkipped == TRUE)
        {
            return wBaseOrdinal;
        }
        else
        {
            bSkipCh = FALSE;
            if(msAPI_CHPROC_CM_GetAttributeOfOrdinal(bServiceType, wBaseOrdinal, (BYTE *)&bSkipCh, E_SERVICE_ATTR_SKIPPED, E_PROGACESS_INCLUDE_VISIBLE_ONLY) == TRUE)
            {
                if(bSkipCh == FALSE)
                    return wBaseOrdinal;
            }
        }
    }
#else
#if (ENABLE_DVB)
    WORD wProgramPosition=0;
#endif
    BYTE cProgramNumber=0;

    switch(bServiceType)
    {
#if (ENABLE_DVB)
    case E_SERVICETYPE_RADIO:
    case E_SERVICETYPE_DTV:
    #if NORDIG_FUNC //for Nordig Spec v2.0
    case E_SERVICETYPE_DATA:
    #endif
                #if NORDIG_FUNC //for Nordig spec v2.0
                wProgramPosition = msAPI_CM_GetNextProgramPosition(bServiceType, wBaseOrdinal, bIncludeSkipped,E_ALL_LIST,(MEMBER_SERVICETYPE *)NULL);
                #else
                wProgramPosition = msAPI_CM_GetNextProgramPosition(bServiceType, wBaseOrdinal, bIncludeSkipped,(CHANNEL_LIST_TYPE)bServiceType,(MEMBER_SERVICETYPE *)NULL);
                #endif
        if( (wProgramPosition == INVALID_PROGRAM_POSITION) ||
            (wProgramPosition <= wBaseOrdinal) )
        {
            return INVALID_ORDINAL;
        }
        else
        {
            return wProgramPosition;
        }
        break;
#endif
    case E_SERVICETYPE_ATV:
        cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetNextProgramNumber(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wBaseOrdinal), bIncludeSkipped));
        if( (cProgramNumber == INVALID_ATV_PROGRAM_NUMBER) ||
            (cProgramNumber <= (BYTE)wBaseOrdinal) )
        {
            return INVALID_ORDINAL;
        }
        else
        {
            return (WORD) cProgramNumber;
        }
        break;

    default:
        break;

    }
#endif
    return INVALID_ORDINAL;
}

/******************************************************************************/
/// -This function will get previous ordinal
/// @param bServiceType \b IN: Service type
/// - @see MEMBER_SERVICETYPE
/// @param wBaseOrdinal \b IN: base ordinal
/// @param bIncludeSkipped \b IN: Include skipped program or not
/// - TRUE: Include skipped program
/// - FALSE: Don't include
/// @return WORD: program count
/******************************************************************************/
WORD msAPI_CHPROC_CM_GetPrevOrdinal(MEMBER_SERVICETYPE bServiceType, WORD wBaseOrdinal, BOOLEAN bIncludeSkipped)
{
#if ENABLE_SBTVD_BRAZIL_CM_APP
    U16 u16MaxOridinal = Get_MAXOridinal();
    U16 i, u16TotalPgmCount;
    BOOLEAN bSkipCh;

    u16TotalPgmCount = msAPI_CHPROC_CM_CountProgram(bServiceType, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
    for(i=0; i<u16TotalPgmCount; i++)
    {
        if(wBaseOrdinal > 0)
            wBaseOrdinal--;
        else
            wBaseOrdinal = u16MaxOridinal-1;

        if(bIncludeSkipped == TRUE)
        {
            return wBaseOrdinal;
        }
        else
        {
            bSkipCh = FALSE;
            if(msAPI_CHPROC_CM_GetAttributeOfOrdinal(bServiceType, wBaseOrdinal, (BYTE *)&bSkipCh, E_SERVICE_ATTR_SKIPPED, E_PROGACESS_INCLUDE_VISIBLE_ONLY) == TRUE)
            {
                if(bSkipCh == FALSE)
                    return wBaseOrdinal;
            }
        }
    }
#else
    #if (ENABLE_DVB)
        WORD wProgramPosition;
    #endif
        BYTE cProgramNumber;
        switch(bServiceType)
        {
        #if (ENABLE_DVB)
        case E_SERVICETYPE_RADIO:
        case E_SERVICETYPE_DTV:
        #if NORDIG_FUNC //for Nordig Spec v2.0
        case E_SERVICETYPE_DATA:
        #endif
                    #if NORDIG_FUNC //for Nordig Spec v2.0
                    wProgramPosition = msAPI_CM_GetPrevProgramPosition(bServiceType, wBaseOrdinal, bIncludeSkipped, E_ALL_LIST, NULL);
                    #else
                    wProgramPosition = msAPI_CM_GetPrevProgramPosition(bServiceType, wBaseOrdinal, bIncludeSkipped, (CHANNEL_LIST_TYPE)bServiceType, NULL);
                    #endif
            if( (wProgramPosition == INVALID_PROGRAM_POSITION) ||
                (wProgramPosition >= wBaseOrdinal) )
            {
                return INVALID_ORDINAL;
            }
            else
            {
                return wProgramPosition;
            }
            break;
        #endif
        case E_SERVICETYPE_ATV:
            cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetPrevProgramNumber((BYTE)wBaseOrdinal, bIncludeSkipped));
            if( (cProgramNumber == INVALID_ATV_PROGRAM_NUMBER) ||
                (cProgramNumber >= (BYTE)wBaseOrdinal) )
            {
                return INVALID_ORDINAL;
            }
            else
            {
                return (WORD) cProgramNumber;
            }
            break;

        default:
            break;
        }
#endif
    return INVALID_ORDINAL;
}

/******************************************************************************/
/// -This function will count favorite program
/// @param bServiceType \b IN: Service type
/// - @see MEMBER_SERVICETYPE
/// @return WORD: favorite program count
/******************************************************************************/
WORD msAPI_CHPROC_CM_CountFavoriteProgram(MEMBER_SERVICETYPE bServiceType)  // ^
{
    switch(bServiceType)
    {
#if (ENABLE_DVB)
    case E_SERVICETYPE_RADIO:
    case E_SERVICETYPE_DTV:
    #if NORDIG_FUNC //for Nordig Spec v2.0
    case E_SERVICETYPE_DATA:
    #endif
        return msAPI_CM_CountFavoriteProgram(bServiceType);
#endif

    case E_SERVICETYPE_ATV:
        return (WORD) msAPI_ATV_GetTotalFavoriteProgramCount();

    case E_SERVICETYPE_UNITED_TV:
      #if NORDIG_FUNC //for Nordig Spec v2.0
        return msAPI_CM_CountFavoriteProgram(E_SERVICETYPE_DTV) + msAPI_ATV_GetTotalFavoriteProgramCount() + msAPI_CM_CountFavoriteProgram(E_SERVICETYPE_DATA) + msAPI_CM_CountFavoriteProgram(E_SERVICETYPE_RADIO);
      #else
#if (ENABLE_DVB)
        return msAPI_CM_CountFavoriteProgram(E_SERVICETYPE_DTV) + msAPI_ATV_GetTotalFavoriteProgramCount() + msAPI_CM_CountFavoriteProgram(E_SERVICETYPE_RADIO);
#else
        return msAPI_ATV_GetTotalFavoriteProgramCount();
#endif

                #endif

    default:
        break;

    }

    return 0;
}

/******************************************************************************/
/// -This function will get first favorite ordinal
/// @param bServiceType \b IN: Service type
/// - @see MEMBER_SERVICETYPE
/// @param bIncludeSkipped \b IN: Include skipped program or not
/// - TRUE: Include skipped program
/// - FALSE: Don't include
/// @return WORD: First favorite program ordinal
/******************************************************************************/
WORD msAPI_CHPROC_CM_GetFirstFavoriteOrdinal(MEMBER_SERVICETYPE bServiceType, BOOLEAN bIncludeSkipped)  // ^
{
#if (ENABLE_DVB)
    WORD wProgramPosition = 0;
#endif
    BYTE cProgramNumber = 0;
#if (!ENABLE_DVB)
    UNUSED(bIncludeSkipped);
#endif
    switch(bServiceType)
    {
#if (ENABLE_DVB)
    case E_SERVICETYPE_RADIO:
    case E_SERVICETYPE_DTV:
    #if NORDIG_FUNC //for Nordig Spec v2.0
    case E_SERVICETYPE_DATA:
    #endif
        wProgramPosition = msAPI_CM_GetFirstFavoriteProgramPosition(bServiceType, bIncludeSkipped);
        if( wProgramPosition != INVALID_PROGRAM_POSITION )
        {
            return wProgramPosition;
        }
        break;
#endif
    case E_SERVICETYPE_ATV:
        cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetFirstFavoriteProgramNumber());
        if( cProgramNumber != INVALID_ATV_PROGRAM_NUMBER )
        {
            return (WORD) cProgramNumber;
        }
        break;

    case E_SERVICETYPE_UNITED_TV:
        #if ENABLE_SBTVD_BRAZIL_CM_APP
        if(ANT_AIR == msAPI_ATV_GetCurrentAntenna())
        {
            U16 u16Loop;


            for(u16Loop=0;u16Loop<Get_MAXOridinal();u16Loop++)
            {
                if(aOridinalList[u16Loop].eServicetype == E_SERVICETYPE_ATV)
                {
                    if(TRUE == msAPI_ATV_IsProgramFavorite(aOridinalList[u16Loop].wPosition >> 8))
                        return  u16Loop;
                }
                else
                {
                    if(TRUE == msAPI_CM_GetProgramAttribute(aOridinalList[u16Loop].eServicetype,aOridinalList[u16Loop].wPosition,E_ATTRIBUTE_IS_FAVORITE))
                        return  u16Loop;
               }
        }
        }
        else
        #endif
#if (!ENABLE_DVB)
        cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetFirstFavoriteProgramNumber());
        if( cProgramNumber == INVALID_ATV_PROGRAM_NUMBER )
        {
            return INVALID_ORDINAL;
        }
        else
        {
            return cProgramNumber;
        }
#else
        wProgramPosition = msAPI_CM_GetFirstFavoriteProgramPosition(E_SERVICETYPE_DTV, bIncludeSkipped);
        if( wProgramPosition == INVALID_PROGRAM_POSITION )
        {
            #if NORDIG_FUNC //for Nordig Spec v2.0
            wProgramPosition = msAPI_CM_GetFirstFavoriteProgramPosition(E_SERVICETYPE_RADIO, bIncludeSkipped);
            if( wProgramPosition == INVALID_PROGRAM_POSITION )
            {
                wProgramPosition = msAPI_CM_GetFirstFavoriteProgramPosition(E_SERVICETYPE_DATA, bIncludeSkipped);
                if( wProgramPosition == INVALID_PROGRAM_POSITION )
                {
                    cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetFirstFavoriteProgramNumber());
                    if( cProgramNumber == INVALID_ATV_PROGRAM_NUMBER )
                    {
                        return INVALID_ORDINAL;
                    }
                    else
                    {
                        return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + cProgramNumber;
                    }
                }
                else
                {
                    return wProgramPosition + msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY)+msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
                }
            }
            else
            {
                return wProgramPosition + msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
            }
            #else
            wProgramPosition = msAPI_CM_GetFirstFavoriteProgramPosition(E_SERVICETYPE_RADIO, bIncludeSkipped);
            if( wProgramPosition == INVALID_PROGRAM_POSITION )
            {
                cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetFirstFavoriteProgramNumber());
                if( cProgramNumber == INVALID_ATV_PROGRAM_NUMBER )
                {
                    return INVALID_ORDINAL;
                }
                else
                {
                    return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + cProgramNumber;
                }
            }
            else
            {
                return wProgramPosition + msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
            }
            #endif
        }
        else
        {
            return wProgramPosition;
        }
#endif
        break;
    default:
        break;
    }

    return INVALID_ORDINAL;
}

/******************************************************************************/
/// -This function will get last favorite ordinal
/// @param bServiceType \b IN: Service type
/// - @see MEMBER_SERVICETYPE
/// @param bIncludeSkipped \b IN: Include skipped program or not
/// - TRUE: Include skipped program
/// - FALSE: Don't include
/// @return WORD: Last  favorite program ordinal
/******************************************************************************/
WORD msAPI_CHPROC_CM_GetLastFavoriteOrdinal(MEMBER_SERVICETYPE bServiceType, BOOLEAN bIncludeSkipped)  // ^
{
#if (ENABLE_DVB)
    WORD wProgramPosition=0;
#endif
    BYTE cProgramNumber=0;
#if (!ENABLE_DVB)
    UNUSED(bIncludeSkipped);
#endif
    switch(bServiceType)
    {
#if (ENABLE_DVB)
    case E_SERVICETYPE_RADIO:
    case E_SERVICETYPE_DTV:
    #if NORDIG_FUNC //for Nordig Spec v2.0
    case E_SERVICETYPE_DATA:
    #endif
        wProgramPosition = msAPI_CM_GetLastFavoriteProgramPosition(E_SERVICETYPE_DTV, bIncludeSkipped);
        if( wProgramPosition != INVALID_PROGRAM_POSITION )
        {
            return wProgramPosition;
        }
        break;
#endif
    case E_SERVICETYPE_ATV:
        cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetLastFavoriteProgramNumber());
        if( cProgramNumber != INVALID_ATV_PROGRAM_NUMBER )
        {
            return (WORD) cProgramNumber;
        }
        break;

    case E_SERVICETYPE_UNITED_TV:
#if (!ENABLE_DVB)
        cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetLastFavoriteProgramNumber());
        if( cProgramNumber == INVALID_ATV_PROGRAM_NUMBER )
        {
            return INVALID_ORDINAL;
        }
        else
        {
            return  cProgramNumber;
        }
#else
        cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetLastFavoriteProgramNumber());
        if( cProgramNumber == INVALID_ATV_PROGRAM_NUMBER )
        {
            wProgramPosition = msAPI_CM_GetLastFavoriteProgramPosition(E_SERVICETYPE_DTV, bIncludeSkipped);
            if( wProgramPosition == INVALID_PROGRAM_POSITION )
            {
                #if NORDIG_FUNC //for Nordig Spec v2.0
                wProgramPosition = msAPI_CM_GetLastFavoriteProgramPosition(E_SERVICETYPE_RADIO, bIncludeSkipped);
                if( wProgramPosition == INVALID_PROGRAM_POSITION )
                {
                    wProgramPosition = msAPI_CM_GetLastFavoriteProgramPosition(E_SERVICETYPE_DATA, bIncludeSkipped);
                    if( wProgramPosition == INVALID_PROGRAM_POSITION )
                    {
                        return INVALID_ORDINAL;
                    }
                    else
                    {
                        return wProgramPosition + msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
                    }
                }
                else
                {
                        return wProgramPosition + msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
                }
                #else
                wProgramPosition = msAPI_CM_GetLastFavoriteProgramPosition(E_SERVICETYPE_RADIO, bIncludeSkipped);
                if( wProgramPosition == INVALID_PROGRAM_POSITION )
                {
                    return INVALID_ORDINAL;
                }
                else
                {
                    return wProgramPosition + msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
                }
                #endif
                return INVALID_ORDINAL;
            }
            else
            {
                return wProgramPosition;
            }
        }
        else
        {
            #if NORDIG_FUNC //for Nordig Spec v2.0
            return  msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + cProgramNumber;
            #else
            return  msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + cProgramNumber;
            #endif
        }
#endif
        break;
    default:
        break;
    }

    return INVALID_ORDINAL;
}

/******************************************************************************/
/// -This function will get next favorite ordinal
/// @param bServiceType \b IN: Service type
/// - @see MEMBER_SERVICETYPE
/// @param wBaseOrdinal \b IN: Base ordinal
/// @param bIncludeSkipped \b IN: Include skipped program or not
/// - TRUE: Include skipped program
/// - FALSE: Don't include
/// @return WORD: Next favorite program ordinal
/******************************************************************************/
WORD msAPI_CHPROC_CM_GetNextFavoriteOrdinal(MEMBER_SERVICETYPE bServiceType, WORD wBaseOrdinal, BOOLEAN bIncludeSkipped)
{
#if (ENABLE_DVB)
    WORD wProgramPosition=0;
#endif
    BYTE cProgramNumber=0;

    switch(bServiceType)
    {
#if (ENABLE_DVB)
    case E_SERVICETYPE_RADIO:
    case E_SERVICETYPE_DTV:
    #if NORDIG_FUNC //for Nordig Spec v2.0
    case E_SERVICETYPE_DATA:
    #endif
        wProgramPosition = msAPI_CM_GetNextFavoriteProgramPosition(bServiceType, wBaseOrdinal, bIncludeSkipped);
        if( (wProgramPosition == INVALID_PROGRAM_POSITION) ||
            (wProgramPosition <= wBaseOrdinal) )
        {
            return INVALID_ORDINAL;
        }
        else
        {
            return wProgramPosition;
        }
        break;
#endif
    case E_SERVICETYPE_ATV:
        #if ENABLE_SBTVD_BRAZIL_CM_APP
        cProgramNumber = msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wBaseOrdinal);
        cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetNextFavoriteProgramNumber((BYTE)cProgramNumber));
        if( (cProgramNumber == INVALID_ATV_PROGRAM_NUMBER) ||
            (cProgramNumber <= (BYTE) wBaseOrdinal) )
        {
            return INVALID_ORDINAL;
        }
        else
        {
            return (WORD) cProgramNumber;
        }
        #else
        cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetNextFavoriteProgramNumber((BYTE)wBaseOrdinal));
        if( (cProgramNumber == INVALID_ATV_PROGRAM_NUMBER) ||
            (cProgramNumber <= (BYTE) wBaseOrdinal) )
        {
            return INVALID_ORDINAL;
        }
        else
        {
            return (WORD) cProgramNumber;
        }
        #endif
        break;

    case E_SERVICETYPE_UNITED_TV:
        return _GetNextFavoriteOrdinalOfUnitedTV(wBaseOrdinal, bIncludeSkipped);

    default:
        break;
    }

    return INVALID_ORDINAL;
}

/******************************************************************************/
/// -This function will get previous favorite ordinal
/// @param bServiceType \b IN: Service type
/// - @see MEMBER_SERVICETYPE
/// @param bIncludeSkipped \b IN: Include skipped program or not
/// - TRUE: Include skipped program
/// - FALSE: Don't include
/// @return WORD: Previous favorite program ordinal
/******************************************************************************/
WORD msAPI_CHPROC_CM_GetPrevFavoriteOrdinal(MEMBER_SERVICETYPE bServiceType, WORD wBaseOrdinal, BOOLEAN bIncludeSkipped)
{
#if (ENABLE_DVB)
    WORD wProgramPosition=0;
#endif
    BYTE cProgramNumber=0;

    switch(bServiceType)
    {
#if (ENABLE_DVB)
    case E_SERVICETYPE_RADIO:
    case E_SERVICETYPE_DTV:
    #if NORDIG_FUNC //for Nordig Spec v2.0
    case E_SERVICETYPE_DATA:
    #endif
        wProgramPosition = msAPI_CM_GetPrevFavoriteProgramPosition(bServiceType, wBaseOrdinal, bIncludeSkipped);
        if( (wProgramPosition == INVALID_PROGRAM_POSITION) ||
            (wProgramPosition >= wBaseOrdinal) )
        {
            return INVALID_ORDINAL;
        }
        else
        {
            return wProgramPosition;
        }
        break;
#endif
    case E_SERVICETYPE_ATV:
        #if ENABLE_SBTVD_BRAZIL_CM_APP
        cProgramNumber = msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wBaseOrdinal);
        cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetPreviousFavoriteProgramNumber((BYTE)cProgramNumber));
        if( (cProgramNumber == INVALID_ATV_PROGRAM_NUMBER) ||
            (cProgramNumber <= (BYTE) wBaseOrdinal) )
        {
            return INVALID_ORDINAL;
        }
        else
        {
            return (WORD) cProgramNumber;
        }
        #else
        cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetPreviousFavoriteProgramNumber((BYTE)wBaseOrdinal));
        if( (cProgramNumber == INVALID_ATV_PROGRAM_NUMBER) ||
            (cProgramNumber >= (BYTE)wBaseOrdinal) )
        {
            return INVALID_ORDINAL;
    }
        else
        {
            return (WORD) cProgramNumber;
        }
        #endif
        break;

    case E_SERVICETYPE_UNITED_TV:
        return _GetPrevFavoriteOrdinalOfUnitedTV(wBaseOrdinal, bIncludeSkipped);

    default:
        break;
    }

    return INVALID_ORDINAL;
}
#if 0
/******************************************************************************/
/// -This function will get Similar ordinal
/// @param bServiceType \b IN: Service type
/// - @see MEMBER_SERVICETYPE
/// @param wPressedNumber \b IN: Pressed Number
/// @param pwOrdinal \b IN: Ordinal
/// @param cSizeOfBuffer \b IN: Size Of Buffer
/// @return WORD: Similar program ordinal
/******************************************************************************/
WORD msAPI_CHPROC_CM_GetSimilarOrdinals(MEMBER_SERVICETYPE bServiceType, WORD wPressedNumber, WORD * pwOrdinal, BYTE cSizeOfBuffer)
{
    WORD wProgramCount,wLoop,wTempOrdinal;
    WORD wOrdinal,wOrdina2,wMinOrdinal = 0,wMinOrder,wCompareOrdinal=0;
    WORD wServiceNumber = 0;
    BYTE acServiceNumber[4];
    BYTE acPressedNumber[4];
    BYTE cLength;
    BYTE cCursor;
    BYTE bVisibleFlag;
    BYTE bNumericSelection;

    cCursor = 0;

    cLength = _AlignDecimalToLeft(acPressedNumber, wPressedNumber);

    if( 0 < cLength )
    {
        wProgramCount = msAPI_CHPROC_CM_CountProgram(bServiceType, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO);

        for(wOrdinal=0; wOrdinal < wProgramCount; wOrdinal++)
        {
            // Exclude Empty or Skiped Program
            if(TRUE == msAPI_CHPROC_CM_GetAttributeOfOrdinal(bServiceType, wOrdinal, (BYTE *)&wServiceNumber, E_SERVICE_ATTR_NUMBER, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO))
            {
                if(TRUE == msAPI_CHPROC_CM_GetAttributeOfOrdinal(bServiceType, wOrdinal, &bVisibleFlag, E_SERVICE_ATTR_VISIBLE, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO)
                    && TRUE == msAPI_CHPROC_CM_GetAttributeOfOrdinal(bServiceType, wOrdinal, &bNumericSelection, E_SERVICE_ATTR_NUMERIC, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO))
                {
                    if(FALSE == bVisibleFlag && FALSE == bNumericSelection)
                        continue;
                }

                if(wServiceNumber >= wPressedNumber)
                {
                    _AlignDecimalToLeft(acServiceNumber, wServiceNumber);
                    if( TRUE == _IsAlignedDecimalSame(acPressedNumber, acServiceNumber, cLength) )
                    {
                        pwOrdinal[cCursor] = wOrdinal;
                        cCursor++;
                        if( cSizeOfBuffer <= cCursor )
                        break;
                    }
                }
            }
        }
    }

    // Sorting
    for(wOrdinal=0; wOrdinal < cCursor; wOrdinal++)
    {
        msAPI_CHPROC_CM_GetAttributeOfOrdinal(bServiceType, pwOrdinal[wOrdinal], (BYTE *)&wMinOrdinal, E_SERVICE_ATTR_NUMBER, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO);
        wMinOrder = wOrdinal;
        for(wOrdina2=wOrdinal+1; wOrdina2 < cCursor; wOrdina2++)
        {
            msAPI_CHPROC_CM_GetAttributeOfOrdinal(bServiceType, pwOrdinal[wOrdina2], (BYTE *)&wCompareOrdinal, E_SERVICE_ATTR_NUMBER, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO);
            if(wCompareOrdinal < wMinOrdinal)
            {
                wMinOrdinal = wCompareOrdinal;
                wMinOrder = wOrdina2;
            }
            else if(wMinOrdinal == wCompareOrdinal)
            {

                if(pwOrdinal[wOrdina2] < msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO))
                {
                    wMinOrdinal = wCompareOrdinal;
                    wMinOrder = wOrdina2;
                }
            }
        }

        if(wMinOrder != wOrdinal)
        {
            wTempOrdinal = pwOrdinal[wMinOrder];
            if(wMinOrder > wOrdinal)
            {
                for(wLoop=wMinOrder; wLoop > wOrdinal; wLoop--)
                    pwOrdinal[wLoop] = pwOrdinal[wLoop-1];
            }
            else
            {
                for(wLoop=wMinOrder; wLoop < wOrdinal; wLoop++)
                    pwOrdinal[wLoop] = pwOrdinal[wLoop+1];
            }
            pwOrdinal[wOrdinal] = wTempOrdinal;
        }
    }
    return cCursor;
}
#endif
/******************************************************************************/
/// -This function will get Matched ordinal
/// @param bServiceType \b IN: Service type
/// - @see MEMBER_SERVICETYPE
/// @param wPressedNumber \b IN: Pressed Number
/// @return WORD: Matched program ordinal
/******************************************************************************/
WORD msAPI_CHPROC_CM_GetMatchedOrdinals(MEMBER_SERVICETYPE bServiceType, WORD wPressedNumber)
{
    WORD wOrdinal;
    U16 u16DtvCount=0,u16RadioCount=0,u16AtvCount;
    #if NORDIG_FUNC //for Nordig Spec v2.0
    U16 u16DataCount=0;
    #endif
    U16 u16SearchFrom, u16SearchTo;
    U16 u16Number = 0;
#if (ENABLE_DVB)
    u16DtvCount = msAPI_CHPROC_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO);
    u16RadioCount = msAPI_CHPROC_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO);
    #if NORDIG_FUNC //for Nordig Spec v2.0
    u16DataCount = msAPI_CHPROC_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO);
    #endif
#endif
    u16AtvCount = msAPI_CHPROC_CM_CountProgram(E_SERVICETYPE_ATV, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO);

  #if ENABLE_SBTVD_BRAZIL_CM_APP
    {
        WORD wGotOridinal = 0;

        if(ANT_AIR == msAPI_ATV_GetCurrentAntenna())
        {
            wOrdinal=u16DtvCount =u16RadioCount=u16AtvCount=0;

          #if NORDIG_FUNC //for Nordig Spec v2.0
            u16DataCount=0;
          #endif
            u16SearchFrom=u16SearchTo=u16Number=0;

            if(bServiceType == msAPI_CHPROC_CM_GetServiceTypeByLCN_Brazil(wPressedNumber,(WORD *) &wGotOridinal))
                return wGotOridinal;
        }
        else
        {
            wPressedNumber--;
            for (wOrdinal = 0; wOrdinal <= msAPI_ATV_GetActiveProgramCount(); wOrdinal++)
            {
                msAPI_CHPROC_CM_GetAttributeOfOrdinal(bServiceType, wOrdinal, (BYTE*)&u16Number, E_SERVICE_ATTR_NUMBER, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO);

                if (u16Number == wPressedNumber)
                    return wOrdinal;
            }
        }
    }
  #else
    #if(ENABLE_DVB)
    if((IS_LCN_RANK_COUNTRY(OSD_COUNTRY_SETTING))&&((bServiceType == E_SERVICETYPE_DTV)||(bServiceType == E_SERVICETYPE_RADIO)||(bServiceType == E_SERVICETYPE_DATA)))
    {
        u16SearchFrom = 0;
        #if NORDIG_FUNC //for Nordig Spec v2.0
        u16SearchTo = u16DtvCount + u16RadioCount + u16DataCount;
        #else
        u16SearchTo = u16DtvCount + u16RadioCount;
        #endif
    }
    else
    #endif
        if(bServiceType == E_SERVICETYPE_DTV)
        {
            u16SearchFrom = 0;
            u16SearchTo = u16DtvCount;
        }
        else if(bServiceType == E_SERVICETYPE_RADIO)
        {
            u16SearchFrom = u16DtvCount;
            u16SearchTo = u16DtvCount + u16RadioCount;
        }
    #if NORDIG_FUNC //for Nordig Spec v2.0
        else if(bServiceType == E_SERVICETYPE_DATA)
        {
            u16SearchFrom = u16DtvCount + u16RadioCount;
            u16SearchTo = u16DtvCount + u16RadioCount + u16DataCount;
        }
    #endif
        else if(bServiceType == E_SERVICETYPE_ATV)
        {
            #if NORDIG_FUNC //for Nordig Spec v2.0
            u16SearchFrom = u16DtvCount + u16DataCount + u16RadioCount;
            u16SearchTo = u16DtvCount + u16DataCount + u16RadioCount + u16AtvCount;
            #else
            u16SearchFrom = u16DtvCount + u16RadioCount;
            u16SearchTo = u16DtvCount + u16RadioCount + u16AtvCount;
            #endif
        }
        else // bServiceType == E_SERVICETYPE_UNITED_TV
        {
            u16SearchFrom = 0;
            #if NORDIG_FUNC //for Nordig Spec v2.0
            u16SearchTo = u16DtvCount + u16DataCount + u16RadioCount + u16AtvCount;
            #else
            u16SearchTo = u16DtvCount + u16RadioCount + u16AtvCount;
            #endif
        }

    if(u16SearchFrom == u16SearchTo ) //channel number equal zero
        return INVALID_ORDINAL;
    else
        u16SearchTo--;

    if(bServiceType == E_SERVICETYPE_ATV)
        wPressedNumber--;
    for (wOrdinal = u16SearchFrom; wOrdinal <= u16SearchTo; wOrdinal++)
    {
#if(ENABLE_DVB)

        if(IS_LCN_RANK_COUNTRY(OSD_COUNTRY_SETTING))
        {
            msAPI_CHPROC_CM_GetAttributeOfOrdinal(E_SERVICETYPE_UNITED_TV, wOrdinal-u16SearchFrom, (BYTE*)&u16Number, E_SERVICE_ATTR_NUMBER, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO);
        }
        else
#endif
        {
            msAPI_CHPROC_CM_GetAttributeOfOrdinal(bServiceType, wOrdinal-u16SearchFrom, (BYTE*)&u16Number, E_SERVICE_ATTR_NUMBER, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO);
        }
        if (u16Number == wPressedNumber)
        {
            return wOrdinal;
        }
    }
  #endif
    return INVALID_ORDINAL;
}
/*
// Sequencial search from DTV, Radio to ATV
WORD msAPI_CHPROC_CM_GetMatchedOrdinals(MEMBER_SERVICETYPE bServiceType, WORD wPressedNumber)
{
    WORD wProgramCount;
    WORD wOrdinal;
    WORD wServiceNumber;
    BYTE bVisibleFlag;
    BYTE bNumericSelection;
    MEMBER_SERVICETYPE eServiceType;

    wProgramCount = msAPI_CHPROC_CM_CountProgram(bServiceType, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO);
    for (wOrdinal=0; wOrdinal<wProgramCount; wOrdinal++)
    {
        if (E_RESULT_SUCCESS == msAPI_CHPROC_CM_GetAttributeOfOrdinal(bServiceType, wOrdinal, (BYTE *)&wServiceNumber, E_SERVICE_ATTR_NUMBER, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO))
        {
            if(E_RESULT_SUCCESS == msAPI_CHPROC_CM_GetAttributeOfOrdinal(bServiceType, wOrdinal, &bVisibleFlag, E_SERVICE_ATTR_VISIBLE, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO)
                && E_RESULT_SUCCESS == msAPI_CHPROC_CM_GetAttributeOfOrdinal(bServiceType, wOrdinal, &bNumericSelection, E_SERVICE_ATTR_NUMERIC, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO))
            {
                if(FALSE == bVisibleFlag && FALSE == bNumericSelection)
                    continue;
            }

            if(E_RESULT_SUCCESS == msAPI_CHPROC_CM_GetAttributeOfOrdinal(bServiceType, wOrdinal, (BYTE *)&eServiceType, E_SERVICE_ATTR_TYPE, E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO))
            {
                if(eServiceType == E_SERVICETYPE_ATV)
                   wServiceNumber++;
            }

            if (wServiceNumber == wPressedNumber)
            {
                return wOrdinal;
            }
        }
    }

    return INVALID_ORDINAL;
}*/

U16 msAPI_CHPROC_CM_Get_ProgramCount_UNITED_TV(E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY eBoundary)
{
    U16 u16ProgCount = 0;

    eBoundary=eBoundary;

#if (ENABLE_DVB)
    u16ProgCount = msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary);

  #if NORDIG_FUNC //for Nordig Spec v2.0
    u16ProgCount += msAPI_CM_CountProgram(E_SERVICETYPE_DATA, eBoundary);
  #endif
#endif

    return u16ProgCount;
}

/******************************************************************************/
/// -This function will get Attribute Of ordinal
/// @param bServiceType \b IN: Service type
/// - @see MEMBER_SERVICETYPE
/// @param pwOrdinal \b IN: Ordinal
/// @param pcBuffer \b IN: pointer to Buffer for return
/// @param eAttributeMember \b IN: Attribute Member
/// - @see SERVICE_ATTRIBUTE_MEMBER
/// @param eBoundary \b IN: Boundary
/// - @see E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY
/// @return FUNCTION_RESULT: Function execution result
/******************************************************************************/
BOOLEAN msAPI_CHPROC_CM_GetAttributeOfOrdinal(MEMBER_SERVICETYPE bServiceType, WORD wOrdinal, BYTE * pcBuffer, SERVICE_ATTRIBUTE_MEMBER eAttributeMember, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY eBoundary)
{
    BYTE cProgramNumber=0;
    WORD wTempBuf = 0;
    MEMBER_SERVICETYPE eServiceType;
#if (ENABLE_DVB)
    WORD wLCN=0;
#endif
#if 1//(!ENABLE_DVB)
    UNUSED(eBoundary);
#endif

#if(!ENABLE_SBTVD_BRAZIL_CM_APP)
 #if (ENABLE_DVB)
    U16 u16DtvProgCount = msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary);
    U16 u16DtvProgCount_Audio = msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary);
 #endif

 #if (ENABLE_DVB&&NORDIG_FUNC) //for Nordig Spec v2.0
    U16 u16DtvProgCount_Data = msAPI_CM_CountProgram(E_SERVICETYPE_DATA, eBoundary);
 #endif
#endif

    switch(eAttributeMember)
    {
    case E_SERVICE_ATTR_TYPE:
        switch(bServiceType)
        {
    #if (ENABLE_DVB)
        case E_SERVICETYPE_RADIO:
        case E_SERVICETYPE_DTV:
      #if NORDIG_FUNC //for Nordig Spec v2.0
        case E_SERVICETYPE_DATA:
      #endif
    #endif
        case E_SERVICETYPE_ATV:
        case E_SERVICETYPE_UNITED_TV:
            if (bServiceType != E_SERVICETYPE_UNITED_TV)
            {
                eServiceType = bServiceType;
            }
            else
            {

      #if ENABLE_SBTVD_BRAZIL_CM_APP
                if(ANT_CATV == msAPI_ATV_GetCurrentAntenna())
                    eServiceType = E_SERVICETYPE_ATV;
                else
                    eServiceType = aOridinalList[wOrdinal].eServicetype;

      #else //ENABLE_SBTVD_BRAZIL_CM_APP

        #if (ENABLE_DVB)
                if( wOrdinal < u16DtvProgCount )
                {
                    eServiceType = E_SERVICETYPE_DTV;
                }
                else if( wOrdinal < (u16DtvProgCount + u16DtvProgCount_Audio) )
                {
                    eServiceType = E_SERVICETYPE_RADIO;
                }
              #if NORDIG_FUNC //for Nordig Spec v2.0
                else if( wOrdinal < (u16DtvProgCount + u16DtvProgCount_Audio + u16DtvProgCount_Data) )
                {
                    eServiceType = E_SERVICETYPE_DATA;
                }
              #endif
                else
        #endif
                {
                    eServiceType = E_SERVICETYPE_ATV;
                }
        #endif // ENABLE_SBTVD_BRAZIL_CM_APP

            }

        #if (ENABLE_DVB)
            if((IS_LCN_RANK_COUNTRY(OSD_COUNTRY_SETTING))&&(eServiceType != E_SERVICETYPE_ATV))
            {
                msAPI_CM_GetPositionbyListPosition(wOrdinal,&eServiceType);
            }
        #endif

            memcpy(pcBuffer,&eServiceType,sizeof(MEMBER_SERVICETYPE));
            return TRUE;
        default:
            break;
        }
        break;

    case E_SERVICE_ATTR_NUMBER:
        switch(bServiceType)
        {
    #if (ENABLE_DVB)
        case E_SERVICETYPE_RADIO:
        case E_SERVICETYPE_DTV:
      #if NORDIG_FUNC //for Nordig Spec v2.0
        case E_SERVICETYPE_DATA:
      #endif
            wLCN = msAPI_CM_GetLogicalChannelNumber(bServiceType, wOrdinal);
            if( wLCN != INVALID_LOGICAL_CHANNEL_NUMBER )
            {
                memcpy(pcBuffer,&wLCN,sizeof(WORD));
                return TRUE;
            }
            break;
    #endif

        case E_SERVICETYPE_ATV:
        #if ENABLE_SBTVD_BRAZIL_APP
            if( wOrdinal < msAPI_ATV_GetChannelMax())
        #elif ( ENABLE_DVB_TAIWAN_APP )
            if( wOrdinal < msAPI_ATV_GetChannelMax())
        #else
            if( wOrdinal < MAX_ATVPROGRAM )
        #endif
            {
                    cProgramNumber = msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wOrdinal);

                if( TRUE == msAPI_ATV_IsProgramNumberActive(cProgramNumber) )
                {
                    wTempBuf = cProgramNumber;
                    memcpy(pcBuffer,&wTempBuf,sizeof(WORD));
                    return TRUE;
                }
            }
            break;

        case E_SERVICETYPE_UNITED_TV:
    #if ENABLE_SBTVD_BRAZIL_CM_APP
            if(ANT_AIR == msAPI_ATV_GetCurrentAntenna())
            {
                if(aOridinalList[wOrdinal].eServicetype == E_SERVICETYPE_ATV)
                    wLCN = (aOridinalList[wOrdinal].u16LCN>>8);
                else
                    wLCN = aOridinalList[wOrdinal].u16LCN;
                if( wLCN != INVALID_LOGICAL_CHANNEL_NUMBER   )
                {
                    memcpy(pcBuffer,&wLCN,sizeof(WORD));
                    return TRUE;
                }

            }
            else if( wOrdinal < msAPI_ATV_GetChannelMax())
            {
                cProgramNumber = msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wOrdinal);

                if( TRUE == msAPI_ATV_IsProgramNumberActive(cProgramNumber) )
                {
                    wTempBuf = (WORD)cProgramNumber;
                    memcpy(pcBuffer,&wTempBuf,sizeof(WORD));
                    return TRUE;
                }
            }
    #else // ENABLE_SBTVD_BRAZIL_CM_APP
      #if (ENABLE_DVB)

            if((IS_LCN_RANK_COUNTRY(OSD_COUNTRY_SETTING))&&( wOrdinal < (msAPI_CHPROC_CM_Get_ProgramCount_UNITED_TV(eBoundary)) ))
            {
                wLCN = msAPI_CM_GetLogicalChannelNumberbyListPosition(wOrdinal);
                if( wLCN != INVALID_LOGICAL_CHANNEL_NUMBER )
                {
                    memcpy(pcBuffer,&wLCN,sizeof(WORD));
                    return TRUE;
                }
                return FALSE;
            }
            if( wOrdinal < msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) )
            {
                wLCN = msAPI_CM_GetLogicalChannelNumber(E_SERVICETYPE_DTV, wOrdinal);
                if( wLCN != INVALID_LOGICAL_CHANNEL_NUMBER   )
                {
                    memcpy(pcBuffer,&wLCN,sizeof(WORD));
                    return TRUE;
                }
            }
            else if( wOrdinal < (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)) )
            {
                wLCN = msAPI_CM_GetLogicalChannelNumber(E_SERVICETYPE_RADIO, (wOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)));
                if( wLCN != INVALID_LOGICAL_CHANNEL_NUMBER   )
                {
                    memcpy(pcBuffer,&wLCN,sizeof(WORD));
                    return TRUE;
                }
            }
          #if NORDIG_FUNC //for Nordig Spec v2.0
            else if( wOrdinal < (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_DATA, eBoundary)) )
            {
                wLCN = msAPI_CM_GetLogicalChannelNumber(E_SERVICETYPE_DATA, (wOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) - msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)));
                if( wLCN != INVALID_LOGICAL_CHANNEL_NUMBER   )
                {
                    memcpy(pcBuffer,&wLCN,sizeof(WORD));
                    return TRUE;
                }
            }
          #endif
            else
    #endif
            {
                // Exclude Empty or Skiped Program
              #if NORDIG_FUNC //for Nordig Spec v2.0
                cProgramNumber = msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wOrdinal-msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)-msAPI_CM_CountProgram(E_SERVICETYPE_DATA, eBoundary)-msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary));
              #else
        #if (ENABLE_DVB)
                cProgramNumber = msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wOrdinal-msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)-msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary));
        #else
                cProgramNumber = msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wOrdinal);
        #endif
              #endif
                if( TRUE == msAPI_ATV_IsProgramNumberActive(cProgramNumber) )
                {
                    wTempBuf = (WORD)cProgramNumber;
                    memcpy(pcBuffer,&wTempBuf,sizeof(WORD));
                    return TRUE;
                }
            }
    #endif // ENABLE_SBTVD_BRAZIL_CM_APP
        default:
            break;
        }
        break;

    case E_SERVICE_ATTR_NAME:
        switch(bServiceType)
        {
#if (ENABLE_DVB)
        case E_SERVICETYPE_RADIO:
        case E_SERVICETYPE_DTV:
        #if NORDIG_FUNC //for Nordig Spec v2.0
        case E_SERVICETYPE_DATA:
        #endif
            if( wOrdinal < msAPI_CM_CountProgram(bServiceType, eBoundary) )
                return msAPI_CM_GetServiceName(bServiceType, wOrdinal, pcBuffer);
            break;
#endif
        case E_SERVICETYPE_ATV:
        #if ENABLE_SBTVD_BRAZIL_APP
            if( wOrdinal < msAPI_ATV_GetChannelMax())
        #elif ( ENABLE_DVB_TAIWAN_APP )
            if( wOrdinal < msAPI_ATV_GetChannelMax())
        #else
            if( wOrdinal < MAX_ATVPROGRAM )
        #endif
                return msAPI_ATV_GetStationName(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wOrdinal), pcBuffer);
            break;

        case E_SERVICETYPE_UNITED_TV:
            #if ENABLE_SBTVD_BRAZIL_CM_APP
            switch(aOridinalList[wOrdinal].eServicetype)
            {
                case E_SERVICETYPE_DTV:
                case E_SERVICETYPE_RADIO:
                case E_SERVICETYPE_DATA:
                    msAPI_CM_GetServiceName(aOridinalList[wOrdinal].eServicetype,aOridinalList[wOrdinal].wPosition, pcBuffer);
                break;

                case E_SERVICETYPE_ATV:
                default:
                    return msAPI_ATV_GetStationName(aOridinalList[wOrdinal].wPosition >> 8, pcBuffer);
            }

            #else // ENABLE_SBTVD_BRAZIL_CM_APP
        #if (ENABLE_DVB)
            if( wOrdinal < msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) )
            {
                return msAPI_CM_GetServiceName(E_SERVICETYPE_DTV, wOrdinal, pcBuffer);
            }
            else if( wOrdinal < (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)) )
            {
                return msAPI_CM_GetServiceName(E_SERVICETYPE_RADIO, (wOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)), pcBuffer);
            }
          #if NORDIG_FUNC //for Nordig Spec v2.0
            else if( wOrdinal < (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_DATA, eBoundary)) )
            {
                return msAPI_CM_GetServiceName(E_SERVICETYPE_DATA, (wOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) - msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)), pcBuffer);
            }
          #endif
            else
        #endif
            {
                #if NORDIG_FUNC //for Nordig Spec v2.0
                return msAPI_ATV_GetStationName(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wOrdinal-msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)-msAPI_CM_CountProgram(E_SERVICETYPE_DATA, eBoundary)-msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)), pcBuffer);
                #else
            #if (ENABLE_DVB)
                return msAPI_ATV_GetStationName(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wOrdinal-msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)-msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)), pcBuffer);
            #else
                return msAPI_ATV_GetStationName(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wOrdinal), pcBuffer);
            #endif
                #endif
            }
            #endif // ENABLE_SBTVD_BRAZIL_CM_APP
            break;
        default:
            break;
        }
        break;

    case E_SERVICE_ATTR_SKIPPED:
        switch(bServiceType)
        {
    #if (ENABLE_DVB)
        case E_SERVICETYPE_RADIO:
        case E_SERVICETYPE_DTV:
        #if NORDIG_FUNC //for Nordig Spec v2.0
        case E_SERVICETYPE_DATA:
                #endif
            if( wOrdinal < msAPI_CM_CountProgram(bServiceType, eBoundary) )
            {
                *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(bServiceType, wOrdinal, E_ATTRIBUTE_IS_SKIPPED);
                return TRUE;
            }
            break;
    #endif

        case E_SERVICETYPE_ATV:
        #if ENABLE_SBTVD_BRAZIL_APP
            if( wOrdinal < msAPI_ATV_GetChannelMax())
        #elif ( ENABLE_DVB_TAIWAN_APP )
            if( wOrdinal < msAPI_ATV_GetChannelMax())
        #else
            if( wOrdinal < MAX_ATVPROGRAM )
        #endif
            {
                *(BOOLEAN *)pcBuffer = msAPI_ATV_IsProgramSkipped(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wOrdinal));
                return TRUE;
            }
            break;

        case E_SERVICETYPE_UNITED_TV:
            #if ENABLE_SBTVD_BRAZIL_CM_APP
            switch(aOridinalList[wOrdinal].eServicetype)
            {
                case E_SERVICETYPE_DTV:
                case E_SERVICETYPE_RADIO:
                case E_SERVICETYPE_DATA:
                    *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(aOridinalList[wOrdinal].eServicetype, aOridinalList[wOrdinal].wPosition, E_ATTRIBUTE_IS_SKIPPED);
                break;

                case E_SERVICETYPE_ATV:
                default:
                    *(BOOLEAN *)pcBuffer =  msAPI_ATV_IsProgramSkipped(aOridinalList[wOrdinal].wPosition >> 8);
            }
            #else
        #if (ENABLE_DVB)
            if(IS_LCN_RANK_COUNTRY(OSD_COUNTRY_SETTING))
            {
                WORD wPosition;

                wPosition = msAPI_CM_GetPositionbyListPosition(wOrdinal,&eServiceType);
                *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(eServiceType, wPosition, E_ATTRIBUTE_IS_SKIPPED);
                return TRUE;
            }

            if( wOrdinal < msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) )
            {
                *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(E_SERVICETYPE_DTV, wOrdinal, E_ATTRIBUTE_IS_SKIPPED);
            }
            else if( wOrdinal < (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)) )
            {
                *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(E_SERVICETYPE_RADIO, (wOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)), E_ATTRIBUTE_IS_SKIPPED);
            }
          #if NORDIG_FUNC //for Nordig Spec v2.0
            else if( wOrdinal < (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_DATA, eBoundary)) )
            {
                *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(E_SERVICETYPE_DATA, (wOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)- msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)), E_ATTRIBUTE_IS_SKIPPED);
            }
          #endif
            else
        #endif
            {
              #if NORDIG_FUNC //for Nordig Spec v2.0
                *(BOOLEAN *)pcBuffer = msAPI_ATV_IsProgramSkipped(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wOrdinal-msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)-msAPI_CM_CountProgram(E_SERVICETYPE_DATA, eBoundary)-msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)));
              #else
            #if (ENABLE_DVB)
                *(BOOLEAN *)pcBuffer = msAPI_ATV_IsProgramSkipped(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wOrdinal-msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)-msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)));
            #else
                *(BOOLEAN *)pcBuffer = msAPI_ATV_IsProgramSkipped(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wOrdinal));
            #endif
              #endif
            }
            #endif // ENABLE_SBTVD_BRAZIL_CM_APP
            return TRUE;
        default:
            break;
        }
        break;

    case E_SERVICE_ATTR_FAVORITE:
        switch(bServiceType)
        {
#if (ENABLE_DVB)
        case E_SERVICETYPE_RADIO:
        case E_SERVICETYPE_DTV:
      #if NORDIG_FUNC //for Nordig Spec v2.0
        case E_SERVICETYPE_DATA:
      #endif
            if( wOrdinal < msAPI_CM_CountProgram(bServiceType, eBoundary) )
            {
        #if ENABLE_S2_CHANNEL_FAV_NEWSTYLE
				*(BOOLEAN *)pcBuffer = (msAPI_CM_GetProgramAttribute(bServiceType, wOrdinal, E_ATTRIBUTE_IS_FAVORITE1)
										||msAPI_CM_GetProgramAttribute(bServiceType, wOrdinal, E_ATTRIBUTE_IS_FAVORITE2)
										||msAPI_CM_GetProgramAttribute(bServiceType, wOrdinal, E_ATTRIBUTE_IS_FAVORITE3)
										||msAPI_CM_GetProgramAttribute(bServiceType, wOrdinal, E_ATTRIBUTE_IS_FAVORITE4));
        #else
                *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(bServiceType, wOrdinal, E_ATTRIBUTE_IS_FAVORITE);
        #endif
                return TRUE;
            }
            break;
#endif

        case E_SERVICETYPE_ATV:
        #if ENABLE_SBTVD_BRAZIL_APP
            if( wOrdinal < msAPI_ATV_GetChannelMax())
        #elif ( ENABLE_DVB_TAIWAN_APP )
            if( wOrdinal < msAPI_ATV_GetChannelMax())
        #else
            if( wOrdinal < MAX_ATVPROGRAM )
        #endif
            {
                *(BOOLEAN *)pcBuffer = msAPI_ATV_IsProgramFavorite(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wOrdinal));
                return TRUE;
            }
            break;

        case E_SERVICETYPE_UNITED_TV:
   #if ENABLE_SBTVD_BRAZIL_CM_APP
            switch(aOridinalList[wOrdinal].eServicetype)
            {
                case E_SERVICETYPE_DTV:
                case E_SERVICETYPE_RADIO:
                case E_SERVICETYPE_DATA:
                    *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(aOridinalList[wOrdinal].eServicetype, aOridinalList[wOrdinal].wPosition, E_ATTRIBUTE_IS_FAVORITE);
                break;

                case E_SERVICETYPE_ATV:
                default:
                    *(BOOLEAN *)pcBuffer = msAPI_ATV_IsProgramFavorite(aOridinalList[wOrdinal].wPosition >> 8 );
            }
   #else // ENABLE_SBTVD_BRAZIL_CM_APP
    #if (ENABLE_DVB)
            if( wOrdinal < msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) )
            {
            #if ENABLE_S2_CHANNEL_FAV_NEWSTYLE
                *(BOOLEAN *)pcBuffer = (msAPI_CM_GetProgramAttribute(E_SERVICETYPE_DTV, wOrdinal, E_ATTRIBUTE_IS_FAVORITE1)
										||msAPI_CM_GetProgramAttribute(E_SERVICETYPE_DTV, wOrdinal, E_ATTRIBUTE_IS_FAVORITE2)
										||msAPI_CM_GetProgramAttribute(E_SERVICETYPE_DTV, wOrdinal, E_ATTRIBUTE_IS_FAVORITE3)
										||msAPI_CM_GetProgramAttribute(E_SERVICETYPE_DTV, wOrdinal, E_ATTRIBUTE_IS_FAVORITE4));
            #else
                *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(E_SERVICETYPE_DTV, wOrdinal, E_ATTRIBUTE_IS_FAVORITE);
            #endif
            }
            else if( wOrdinal < (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)))
            {
            #if ENABLE_S2_CHANNEL_FAV_NEWSTYLE
                *(BOOLEAN *)pcBuffer = (msAPI_CM_GetProgramAttribute(E_SERVICETYPE_RADIO, (wOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)), E_ATTRIBUTE_IS_FAVORITE1)
                							||msAPI_CM_GetProgramAttribute(E_SERVICETYPE_RADIO, (wOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)), E_ATTRIBUTE_IS_FAVORITE2)
                							||msAPI_CM_GetProgramAttribute(E_SERVICETYPE_RADIO, (wOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)), E_ATTRIBUTE_IS_FAVORITE3)
                							||msAPI_CM_GetProgramAttribute(E_SERVICETYPE_RADIO, (wOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)), E_ATTRIBUTE_IS_FAVORITE4));
            #else
                *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(E_SERVICETYPE_RADIO, (wOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)), E_ATTRIBUTE_IS_FAVORITE);
            #endif
            }
            #if NORDIG_FUNC //for Nordig Spec v2.0
            else if( wOrdinal < (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_DATA, eBoundary)))
            {
        #if ENABLE_S2_CHANNEL_FAV_NEWSTYLE
                *(BOOLEAN *)pcBuffer = (msAPI_CM_GetProgramAttribute(E_SERVICETYPE_DATA, (wOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) - msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)), E_ATTRIBUTE_IS_FAVORITE1)
                                    ||msAPI_CM_GetProgramAttribute(E_SERVICETYPE_DATA, (wOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) - msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)), E_ATTRIBUTE_IS_FAVORITE2)
                                    ||msAPI_CM_GetProgramAttribute(E_SERVICETYPE_DATA, (wOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) - msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)), E_ATTRIBUTE_IS_FAVORITE3)
                                    ||msAPI_CM_GetProgramAttribute(E_SERVICETYPE_DATA, (wOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) - msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)), E_ATTRIBUTE_IS_FAVORITE4));
        #else
                *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(E_SERVICETYPE_DATA, (wOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) - msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)), E_ATTRIBUTE_IS_FAVORITE);
        #endif
            }
            #endif
            else
    #endif
            {
              #if NORDIG_FUNC //for Nordig Spec v2.0
                *(BOOLEAN *)pcBuffer = msAPI_ATV_IsProgramFavorite(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wOrdinal-msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)-msAPI_CM_CountProgram(E_SERVICETYPE_DATA, eBoundary)-msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)));
              #else
            #if (ENABLE_DVB)
                *(BOOLEAN *)pcBuffer = msAPI_ATV_IsProgramFavorite(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wOrdinal-msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)-msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)));
            #else
                *(BOOLEAN *)pcBuffer = msAPI_ATV_IsProgramFavorite(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wOrdinal));
            #endif
               #endif
            }
   #endif // ENABLE_SBTVD_BRAZIL_CM_APP
            return TRUE;
        default:
            break;

        }
        break;

    case E_SERVICE_ATTR_LOCKED:
        switch(bServiceType)
        {
    #if (ENABLE_DVB)
        case E_SERVICETYPE_RADIO:
        case E_SERVICETYPE_DTV:
        #if NORDIG_FUNC //for Nordig Spec v2.0
        case E_SERVICETYPE_DATA:
        #endif
            if( wOrdinal < msAPI_CM_CountProgram(bServiceType, eBoundary) )
            {
                *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(bServiceType, wOrdinal, E_ATTRIBUTE_IS_LOCKED);
                return TRUE;
            }
            break;
    #endif

        case E_SERVICETYPE_ATV:
        #if ENABLE_SBTVD_BRAZIL_APP
            if( wOrdinal < msAPI_ATV_GetChannelMax())
        #elif ( ENABLE_DVB_TAIWAN_APP )
            if( wOrdinal < msAPI_ATV_GetChannelMax())
        #else
            if( wOrdinal < MAX_ATVPROGRAM )
        #endif
            {
                *(BOOLEAN *)pcBuffer = msAPI_ATV_IsProgramLocked(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wOrdinal));
                return TRUE;
            }
            break;

        case E_SERVICETYPE_UNITED_TV:
  #if ENABLE_SBTVD_BRAZIL_CM_APP
            switch(aOridinalList[wOrdinal].eServicetype)
            {
                case E_SERVICETYPE_DTV:
                case E_SERVICETYPE_RADIO:
                case E_SERVICETYPE_DATA:
                    *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(aOridinalList[wOrdinal].eServicetype, aOridinalList[wOrdinal].wPosition, E_ATTRIBUTE_IS_LOCKED);
                break;

                case E_SERVICETYPE_ATV:
                default:
                    *(BOOLEAN *)pcBuffer = msAPI_ATV_IsProgramLocked(aOridinalList[wOrdinal].wPosition >> 8);
            }
   #else // ENABLE_SBTVD_BRAZIL_CM_APP
        #if (ENABLE_DVB)
            if(IS_LCN_RANK_COUNTRY(OSD_COUNTRY_SETTING))
            {
                WORD wPosition;

                wPosition = msAPI_CM_GetPositionbyListPosition(wOrdinal,&eServiceType);
                *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(eServiceType, wPosition, E_ATTRIBUTE_IS_LOCKED);
                return TRUE;
            }

            if( wOrdinal < msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) )
            {
                *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(E_SERVICETYPE_DTV, wOrdinal, E_ATTRIBUTE_IS_LOCKED);
            }
            else if( wOrdinal < (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)) )
            {
                *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(E_SERVICETYPE_RADIO, (wOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)), E_ATTRIBUTE_IS_LOCKED);
            }
          #if NORDIG_FUNC //for Nordig Spec v2.0
            else if( wOrdinal < (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_DATA, eBoundary)) )
            {
                *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(E_SERVICETYPE_DATA, (wOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) - msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)), E_ATTRIBUTE_IS_LOCKED);
            }
          #endif
            else
        #endif
            {
            #if NORDIG_FUNC //for Nordig Spec v2.0
                *(BOOLEAN *)pcBuffer = msAPI_ATV_IsProgramLocked(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wOrdinal-msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)-msAPI_CM_CountProgram(E_SERVICETYPE_DATA, eBoundary)-msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)));
            #else
              #if (ENABLE_DVB)
                *(BOOLEAN *)pcBuffer = msAPI_ATV_IsProgramLocked(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wOrdinal-msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)-msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)));
              #else
                *(BOOLEAN *)pcBuffer = msAPI_ATV_IsProgramLocked(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wOrdinal));
              #endif
            #endif
            }
   #endif // ENABLE_SBTVD_BRAZIL_CM_APP
            return TRUE;
        default:
            break;
        }
        break;

    case E_SERVICE_ATTR_VISIBLE :
        switch(bServiceType)
        {
#if ENABLE_S2_PREDIT_SWITCH_LIST
		case E_SERVICETYPE_ATV:
			*(BOOLEAN *)pcBuffer = TRUE;
			return TRUE;
#endif

#if (ENABLE_DVB)
        case E_SERVICETYPE_RADIO:
        case E_SERVICETYPE_DTV:
        #if NORDIG_FUNC //for Nordig Spec v2.0
        case E_SERVICETYPE_DATA:
        #endif
            if( wOrdinal < msAPI_CM_CountProgram(bServiceType, eBoundary) )
            {
                *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(bServiceType, wOrdinal, E_ATTRIBUTE_IS_VISIBLE);
                return TRUE;
            }
            break;
#endif

        case E_SERVICETYPE_UNITED_TV:
    #if ENABLE_SBTVD_BRAZIL_CM_APP
            switch(aOridinalList[wOrdinal].eServicetype)
            {
                case E_SERVICETYPE_DTV:
                case E_SERVICETYPE_RADIO:
                case E_SERVICETYPE_DATA:
                    *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(aOridinalList[wOrdinal].eServicetype, aOridinalList[wOrdinal].wPosition, E_ATTRIBUTE_IS_VISIBLE);
                default:
                    *(BOOLEAN *)pcBuffer = TRUE;
            }
    #else // ENABLE_SBTVD_BRAZIL_CM_APP
        #if (ENABLE_DVB)
            if( wOrdinal < msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) )
            {
                *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(E_SERVICETYPE_DTV, wOrdinal, E_ATTRIBUTE_IS_VISIBLE);
            }
            else if( wOrdinal < (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)) )
            {
                *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(E_SERVICETYPE_RADIO, (wOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)), E_ATTRIBUTE_IS_VISIBLE);
            }
          #if NORDIG_FUNC //for Nordig Spec v2.0
            else if( wOrdinal < (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_DATA, eBoundary)) )
            {
                *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(E_SERVICETYPE_DATA, (wOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)-msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)), E_ATTRIBUTE_IS_VISIBLE);
            }
          #endif
            else
        #endif
            {
                *(BOOLEAN *)pcBuffer = TRUE;
            }
    #endif // ENABLE_SBTVD_BRAZIL_CM_APP
            return TRUE;
        default:
            break;
        }
        break;

    case E_SERVICE_ATTR_NUMERIC :
        switch(bServiceType)
        {
#if (ENABLE_DVB)
        case E_SERVICETYPE_RADIO:
        case E_SERVICETYPE_DTV:
      #if NORDIG_FUNC //for Nordig Spec v2.0
        case E_SERVICETYPE_DATA:
      #endif
            if( wOrdinal < msAPI_CM_CountProgram(bServiceType, eBoundary) )
            {
                *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(bServiceType, wOrdinal, E_ATTRIBUTE_IS_NUMERIC_SELECTION);
                return TRUE;
            }
            break;
#endif

        case E_SERVICETYPE_UNITED_TV:
    #if ENABLE_SBTVD_BRAZIL_CM_APP
            switch(aOridinalList[wOrdinal].eServicetype)
            {
                case E_SERVICETYPE_DTV:
                case E_SERVICETYPE_RADIO:
                case E_SERVICETYPE_DATA:
                    *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(aOridinalList[wOrdinal].eServicetype, aOridinalList[wOrdinal].wPosition, E_ATTRIBUTE_IS_NUMERIC_SELECTION);
                    break;
                default:
                    *(BOOLEAN *)pcBuffer = TRUE;
                    break;
            }
    #else // ENABLE_SBTVD_BRAZIL_CM_APP
        #if( ENABLE_DVB ) //(ENABLE_DTV)
            if( wOrdinal < msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) )
            {
                *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(E_SERVICETYPE_DTV, wOrdinal, E_ATTRIBUTE_IS_NUMERIC_SELECTION);
            }
            else if( wOrdinal < (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)) )
            {
                *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(E_SERVICETYPE_RADIO, (wOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)), E_ATTRIBUTE_IS_NUMERIC_SELECTION);
            }
          #if NORDIG_FUNC //for Nordig Spec v2.0
            else if( wOrdinal < (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary) + msAPI_CM_CountProgram(E_SERVICETYPE_DATA, eBoundary)) )
            {
                *(BOOLEAN *)pcBuffer = msAPI_CM_GetProgramAttribute(E_SERVICETYPE_DATA, (wOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, eBoundary)-msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, eBoundary)), E_ATTRIBUTE_IS_NUMERIC_SELECTION);
            }
          #endif
            else
        #endif
            {
                *(BOOLEAN *)pcBuffer = TRUE;
            }
    #endif
            return TRUE;

        default:
            break;
        }
        break;

    default:
        return FALSE;
    }

    return FALSE;
}
#if 0
//****************************************************************************
// Start of private implementation
//****************************************************************************
static BYTE _AlignDecimalToLeft(BYTE *pcBuffer, WORD wNumber)
{
    WORD wDecreasedNumber;
    BYTE cCursor;
    WORD wMultipleOf10;

    wDecreasedNumber = wNumber;
    cCursor = 0;

    for( wMultipleOf10 = 1000; wMultipleOf10 > 0; wMultipleOf10 /= 10 )
    {
        if( 0 != (wNumber / wMultipleOf10) || 0 == wNumber )
        {
            pcBuffer[cCursor] = (wDecreasedNumber / wMultipleOf10);
            cCursor++;
            wDecreasedNumber %= wMultipleOf10;
        }
    }

    return cCursor;
}

static BOOLEAN _IsAlignedDecimalSame(BYTE *pcBuffer1, BYTE *pcBuffer2, BYTE cLength)
{
    BYTE i;

    for(i=0; i < cLength; i++)
    {
        if( pcBuffer1[i] != pcBuffer2[i] )
            return FALSE;
    }

    return TRUE;
}
#endif

#if( ENABLE_DVB&&NORDIG_FUNC )//for Nordig Spec v2.0
static WORD _GetNextFavoriteOrdinalOfUnitedTV(WORD wBaseOrdinal, BOOLEAN bIncludeSkipped)
{
    WORD wProgramPosition=0;
    BYTE cProgramNumber=0;

    if( wBaseOrdinal < msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) )
    {
        wProgramPosition = msAPI_CM_GetNextFavoriteProgramPosition(E_SERVICETYPE_DTV, wBaseOrdinal, bIncludeSkipped);
        if( (wProgramPosition == INVALID_PROGRAM_POSITION) ||
            (wProgramPosition <= wBaseOrdinal) )
        {
            wProgramPosition = msAPI_CM_GetFirstFavoriteProgramPosition(E_SERVICETYPE_RADIO, bIncludeSkipped);
            if( wProgramPosition == INVALID_PROGRAM_POSITION)
            {
                wProgramPosition = msAPI_CM_GetFirstFavoriteProgramPosition(E_SERVICETYPE_DATA, bIncludeSkipped);
                if( wProgramPosition == INVALID_PROGRAM_POSITION)
                {
                    cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetFirstFavoriteProgramNumber());
                    if( cProgramNumber == INVALID_ATV_PROGRAM_NUMBER )
                    {
                        wProgramPosition = msAPI_CM_GetFirstFavoriteProgramPosition(E_SERVICETYPE_DTV, bIncludeSkipped);
                        if( wProgramPosition == INVALID_PROGRAM_POSITION )
                        {
                            return INVALID_ORDINAL;
                        }
                        else
                        {
                            return wProgramPosition;
                        }
                    }
                    else
                    {
                        return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_VISIBLE_ONLY)+ msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + cProgramNumber;
                    }
                }
                else
                {
                    return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY)+wProgramPosition;
                }
            }
            else
            {
                return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + wProgramPosition;
            }
        }
        else
        {
            return wProgramPosition;
        }
    }
    else if( wBaseOrdinal < (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY)) )    // 070626 DHShin
    {
        wProgramPosition = msAPI_CM_GetNextFavoriteProgramPosition(E_SERVICETYPE_RADIO, (wBaseOrdinal-msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY)), bIncludeSkipped);
        if( (wProgramPosition == INVALID_PROGRAM_POSITION) ||
            (wProgramPosition <= (wBaseOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY))) )
        {
            wProgramPosition = msAPI_CM_GetFirstFavoriteProgramPosition(E_SERVICETYPE_DATA, bIncludeSkipped);
            if( wProgramPosition == INVALID_PROGRAM_POSITION )
            {
                cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetFirstFavoriteProgramNumber());
                if( cProgramNumber == INVALID_ATV_PROGRAM_NUMBER )
                {
                    wProgramPosition = msAPI_CM_GetFirstFavoriteProgramPosition(E_SERVICETYPE_DTV, bIncludeSkipped);
                    if( wProgramPosition == INVALID_PROGRAM_POSITION )
                    {
                        wProgramPosition = msAPI_CM_GetFirstFavoriteProgramPosition(E_SERVICETYPE_RADIO, bIncludeSkipped);
                        if( wProgramPosition == INVALID_PROGRAM_POSITION )
                        {
                            return INVALID_ORDINAL;
                        }
                        else
                        {
                            return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) +wProgramPosition;
                        }
                    }
                    else
                    {
                        return wProgramPosition;
                    }
                }
                else
                {
                    return cProgramNumber + msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_VISIBLE_ONLY)+msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
                }
            }
            else
            {
                return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + wProgramPosition;
            }
        }
        else
        {
            return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + wProgramPosition;
        }
    }
    else if( wBaseOrdinal < (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_VISIBLE_ONLY)+msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY)) )    // 070626 DHShin
    {
        wProgramPosition = msAPI_CM_GetNextFavoriteProgramPosition(E_SERVICETYPE_DATA, (wBaseOrdinal-msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY)-msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY)), bIncludeSkipped);
        if( (wProgramPosition == INVALID_PROGRAM_POSITION) ||
            (wProgramPosition <= (wBaseOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY)-msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY))) )
        {
            cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetFirstFavoriteProgramNumber());
            if( cProgramNumber == INVALID_ATV_PROGRAM_NUMBER )
            {
                wProgramPosition = msAPI_CM_GetFirstFavoriteProgramPosition(E_SERVICETYPE_DTV, bIncludeSkipped);
                if( wProgramPosition == INVALID_PROGRAM_POSITION )
                {
                    wProgramPosition = msAPI_CM_GetFirstFavoriteProgramPosition(E_SERVICETYPE_RADIO, bIncludeSkipped);
                    if( wProgramPosition == INVALID_PROGRAM_POSITION )
                    {
                        wProgramPosition = msAPI_CM_GetFirstFavoriteProgramPosition(E_SERVICETYPE_DATA, bIncludeSkipped);
                        if( wProgramPosition == INVALID_PROGRAM_POSITION )
                        {
                            return INVALID_ORDINAL;
                        }
                        else
                        {
                            return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY)+wProgramPosition;
                        }
                    }
                    else
                    {
                        return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY)+wProgramPosition;
                    }
                }
                else
                {
                    return wProgramPosition;
                }
            }
            else
            {
                return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY)+msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_VISIBLE_ONLY)+msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY)+cProgramNumber;
            }
        }
        else
        {
            return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY)+wProgramPosition;
        }
    }
    else
    {
        cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetNextFavoriteProgramNumber(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wBaseOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) - msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_VISIBLE_ONLY)-msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY))));
        if( (cProgramNumber == INVALID_ATV_PROGRAM_NUMBER) ||
            (cProgramNumber <= (BYTE)(wBaseOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) - msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_VISIBLE_ONLY)-msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY))) )
        {
            wProgramPosition = msAPI_CM_GetFirstFavoriteProgramPosition(E_SERVICETYPE_DTV, bIncludeSkipped);
            if( wProgramPosition == INVALID_PROGRAM_POSITION )
            {
                wProgramPosition = msAPI_CM_GetFirstFavoriteProgramPosition(E_SERVICETYPE_RADIO, bIncludeSkipped);
                if( wProgramPosition == INVALID_PROGRAM_POSITION )
                {
                    wProgramPosition = msAPI_CM_GetFirstFavoriteProgramPosition(E_SERVICETYPE_DATA, bIncludeSkipped);
                    if( cProgramNumber == INVALID_ATV_PROGRAM_NUMBER )
                    {
                        cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetFirstFavoriteProgramNumber());
                        if( cProgramNumber == INVALID_ATV_PROGRAM_NUMBER )
                        {
                            return INVALID_ORDINAL;
                        }
                        else
                        {
                            return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_VISIBLE_ONLY)+msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + cProgramNumber;
                        }
                    }
                    else
                    {
                        return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY)+cProgramNumber;
                    }
                }
                else
                {
                    return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) +cProgramNumber;
                }
            }
            else
            {
                return wProgramPosition;
            }
        }
        else
        {
            return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_VISIBLE_ONLY)+msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + cProgramNumber;
        }
    }
    return INVALID_ORDINAL;
}
#else
static WORD _GetNextFavoriteOrdinalOfUnitedTV(WORD wBaseOrdinal, BOOLEAN bIncludeSkipped)
{
#if (ENABLE_DVB)
    WORD wProgramPosition=0;
#endif
    BYTE cProgramNumber=0;
#if (!ENABLE_DVB)
    UNUSED(bIncludeSkipped);
#endif
    #if ENABLE_SBTVD_BRAZIL_CM_APP
    if(ANT_AIR == msAPI_ATV_GetCurrentAntenna())
    {
        U16 u16Loop;

        bIncludeSkipped = bIncludeSkipped;

        for(u16Loop=wBaseOrdinal+1;u16Loop<Get_MAXOridinal();u16Loop++)
        {
            if(aOridinalList[u16Loop].eServicetype == E_SERVICETYPE_ATV)
            {
                if(TRUE == msAPI_ATV_IsProgramFavorite(aOridinalList[u16Loop].wPosition >> 8))
                    return  u16Loop;
            }
            else
            {
                if(TRUE == msAPI_CM_GetProgramAttribute(aOridinalList[u16Loop].eServicetype,aOridinalList[u16Loop].wPosition,E_ATTRIBUTE_IS_FAVORITE))
                    return  u16Loop;
            }
        }
    }
    else
    #endif // ENABLE_SBTVD_BRAZIL_CM_APP
#if (ENABLE_DVB)
    if( wBaseOrdinal < msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) )
    {
        wProgramPosition = msAPI_CM_GetNextFavoriteProgramPosition(E_SERVICETYPE_DTV, wBaseOrdinal, bIncludeSkipped);
        if( (wProgramPosition == INVALID_PROGRAM_POSITION) ||
            (wProgramPosition <= wBaseOrdinal) )
        {
            wProgramPosition = msAPI_CM_GetFirstFavoriteProgramPosition(E_SERVICETYPE_RADIO, bIncludeSkipped);
            if( wProgramPosition == INVALID_PROGRAM_POSITION)
            {
                cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetFirstFavoriteProgramNumber());
                if( cProgramNumber == INVALID_ATV_PROGRAM_NUMBER )
                {
                    wProgramPosition = msAPI_CM_GetFirstFavoriteProgramPosition(E_SERVICETYPE_DTV, bIncludeSkipped);
                    if( wProgramPosition == INVALID_PROGRAM_POSITION )
                    {
                        return INVALID_ORDINAL;
                    }
                    else
                    {
                        return wProgramPosition;
                    }
                }
                else
                {
                    return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + cProgramNumber;
                }
            }
            else
            {
                return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + wProgramPosition;
            }
        }
        else
        {
            return wProgramPosition;
        }
    }
    else if( wBaseOrdinal < (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY)) )    // 070626 DHShin
    {
        wProgramPosition = msAPI_CM_GetNextFavoriteProgramPosition(E_SERVICETYPE_RADIO, (wBaseOrdinal-msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY)), bIncludeSkipped);
        if( (wProgramPosition == INVALID_PROGRAM_POSITION) ||
            (wProgramPosition <= (wBaseOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY))) )
        {
            cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetFirstFavoriteProgramNumber());
            if( cProgramNumber == INVALID_ATV_PROGRAM_NUMBER )
            {
                cProgramNumber = msAPI_CM_GetFirstFavoriteProgramPosition(E_SERVICETYPE_DTV, bIncludeSkipped);
                if( cProgramNumber == 0xFF )
                {
                    cProgramNumber = msAPI_CM_GetFirstFavoriteProgramPosition(E_SERVICETYPE_RADIO, bIncludeSkipped);
                    if( cProgramNumber == 0xFF )
                    {
                        return INVALID_ORDINAL;
                    }
                    else
                    {
                        return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + wProgramPosition;
                    }
                }
                else
                {
                    return cProgramNumber;
                }
            }
            else
            {
                return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + cProgramNumber;
            }
        }
        else
        {
            return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + wProgramPosition;
        }
    }
    else
#endif
    {
#if (ENABLE_DVB)
        cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetNextFavoriteProgramNumber(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wBaseOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) - msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY))));
#else
        cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetNextFavoriteProgramNumber(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wBaseOrdinal )));
#endif
        if( (cProgramNumber == INVALID_ATV_PROGRAM_NUMBER) ||
            (cProgramNumber <= (BYTE)(wBaseOrdinal
#if (ENABLE_DVB)
            - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) - msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY)
#endif
            )) )
        {
#if (!ENABLE_DVB)
            cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetFirstFavoriteProgramNumber());
            if( cProgramNumber == INVALID_ATV_PROGRAM_NUMBER )
            {
                return INVALID_ORDINAL;
            }
            else
            {
                return cProgramNumber;
            }
#else
            wProgramPosition = msAPI_CM_GetFirstFavoriteProgramPosition(E_SERVICETYPE_DTV, bIncludeSkipped);
            if( wProgramPosition == INVALID_PROGRAM_POSITION )
            {
                wProgramPosition = msAPI_CM_GetFirstFavoriteProgramPosition(E_SERVICETYPE_RADIO, bIncludeSkipped);
                if( cProgramNumber == 0xFF )
                {
                    cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetFirstFavoriteProgramNumber());
                    if( cProgramNumber == INVALID_ATV_PROGRAM_NUMBER )
                    {
                        return INVALID_ORDINAL;
                    }
                    else
                    {
                        return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + cProgramNumber;
                    }
                }
                else
                {
                    return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + cProgramNumber;
                }
            }
            else
            {
                return wProgramPosition;
            }
#endif
        }
        else
        {
#if (ENABLE_DVB)
            return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + cProgramNumber;
#else
            return cProgramNumber;
#endif
        }
    }
    return INVALID_ORDINAL;
}
#endif
#if NORDIG_FUNC //for Nordig Spec v2.0

static WORD _GetPrevFavoriteOrdinalOfUnitedTV(WORD wBaseOrdinal, BOOLEAN bIncludeSkipped)
{
    WORD wProgramPosition=0;
    BYTE cProgramNumber=INVALID_ATV_PROGRAM_NUMBER;


    if( wBaseOrdinal < msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) )
    {
        wProgramPosition = msAPI_CM_GetPrevFavoriteProgramPosition(E_SERVICETYPE_DTV, wBaseOrdinal, bIncludeSkipped);
        if( (wProgramPosition == INVALID_PROGRAM_POSITION) ||
            (wProgramPosition >= wBaseOrdinal) )
        {
            cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetLastFavoriteProgramNumber());
            if( cProgramNumber == INVALID_ATV_PROGRAM_NUMBER )
            {
                wProgramPosition = msAPI_CM_GetPrevFavoriteProgramPosition(E_SERVICETYPE_DATA, msAPI_CM_GetFirstProgramPosition(E_SERVICETYPE_DATA, bIncludeSkipped), bIncludeSkipped);
                if( wProgramPosition == INVALID_PROGRAM_POSITION )
                {
                    wProgramPosition = msAPI_CM_GetPrevFavoriteProgramPosition(E_SERVICETYPE_RADIO, msAPI_CM_GetFirstProgramPosition(E_SERVICETYPE_RADIO, bIncludeSkipped), bIncludeSkipped);
                    if( wProgramPosition == INVALID_PROGRAM_POSITION )
                    {
                        wProgramPosition = msAPI_CM_GetFirstFavoriteProgramPosition(E_SERVICETYPE_DTV, bIncludeSkipped);
                        if(wProgramPosition == INVALID_PROGRAM_POSITION)
                        {
                            return INVALID_ORDINAL;
                        }
                        else
                        {
                            return wProgramPosition;
                        }
                    }
                    else
                    {
                        return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + wProgramPosition;
                    }
                }
                else
                {
                    return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + wProgramPosition;
                }
            }
            else
            {
                return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + cProgramNumber;
            }
        }
        else
        {
            return wProgramPosition;
        }
    }
    else if( wBaseOrdinal < (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY)) )
    {
        wProgramPosition = msAPI_CM_GetPrevFavoriteProgramPosition(E_SERVICETYPE_RADIO, (wBaseOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY)), bIncludeSkipped);
        if( (wProgramPosition == INVALID_PROGRAM_POSITION) ||
            (wProgramPosition >= (wBaseOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY))) )
        {
            wProgramPosition = msAPI_CM_GetPrevFavoriteProgramPosition(E_SERVICETYPE_DTV, msAPI_CM_GetFirstProgramPosition(E_SERVICETYPE_DTV, bIncludeSkipped), bIncludeSkipped);
            if(wProgramPosition == INVALID_PROGRAM_POSITION )
            {
                cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetLastFavoriteProgramNumber());
                if( cProgramNumber == INVALID_ATV_PROGRAM_NUMBER )
                {
                    wProgramPosition = msAPI_CM_GetPrevFavoriteProgramPosition(E_SERVICETYPE_DATA, (wBaseOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY)-msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY)), bIncludeSkipped);
                    if( wProgramPosition == INVALID_PROGRAM_POSITION )
                    {
                        wProgramPosition = msAPI_CM_GetPrevFavoriteProgramPosition(E_SERVICETYPE_RADIO, (wBaseOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY)), bIncludeSkipped);
                        if( wProgramPosition == INVALID_PROGRAM_POSITION )
                        {
                            return INVALID_ORDINAL;
                        }
                        else
                        {
                            return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + wProgramPosition;
                        }
                    }
                    else
                    {
                        return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + wProgramPosition;
                    }
                }
                else
                {
                    return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY)+ msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_VISIBLE_ONLY)+msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + cProgramNumber;
                }
            }
            else
            {
                return wProgramPosition;
            }
        }
        else
        {
            return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + wProgramPosition;
        }
    }
    else if( wBaseOrdinal < (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_VISIBLE_ONLY)) )
    {
        wProgramPosition = msAPI_CM_GetPrevFavoriteProgramPosition(E_SERVICETYPE_DATA, (wBaseOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY)-msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY)), bIncludeSkipped);
        if( (wProgramPosition == INVALID_PROGRAM_POSITION) ||
            (wProgramPosition >= (wBaseOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) - msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY))) )
        {
            wProgramPosition = msAPI_CM_GetPrevFavoriteProgramPosition(E_SERVICETYPE_RADIO, wBaseOrdinal-msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY), bIncludeSkipped);
            if(wProgramPosition == INVALID_PROGRAM_POSITION )
            {
                wProgramPosition = msAPI_CM_GetPrevFavoriteProgramPosition(E_SERVICETYPE_DTV, msAPI_CM_GetFirstProgramPosition(E_SERVICETYPE_DTV, bIncludeSkipped), bIncludeSkipped);
                if(wProgramPosition == INVALID_PROGRAM_POSITION )
                {
                    cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetLastFavoriteProgramNumber());
                    if( cProgramNumber == INVALID_ATV_PROGRAM_NUMBER )
                    {
                        wProgramPosition = msAPI_CM_GetPrevFavoriteProgramPosition(E_SERVICETYPE_DATA, (wBaseOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY)-msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY)), bIncludeSkipped);
                        if( wProgramPosition == INVALID_PROGRAM_POSITION )
                        {
                            return INVALID_ORDINAL;
                        }
                        else
                        {
                            return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + wProgramPosition;
                        }
                    }
                    else
                    {
                        return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY)   + msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + cProgramNumber;
                    }
                }
                else
                {
                    return wProgramPosition;
                }
            }
            else
            {
                return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + cProgramNumber;
            }
        }
        else
        {
            return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + wProgramPosition;
        }
    }
    else
    {
        cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetPreviousFavoriteProgramNumber(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wBaseOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) - msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_VISIBLE_ONLY) - msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY))));
        if( (cProgramNumber == INVALID_ATV_PROGRAM_NUMBER) ||
            (cProgramNumber >= (BYTE)(wBaseOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) - msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY)- msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_VISIBLE_ONLY))) )
        {
            wProgramPosition = msAPI_CM_GetLastFavoriteProgramPosition(E_SERVICETYPE_DATA, bIncludeSkipped);
            if( wProgramPosition == INVALID_PROGRAM_POSITION )
            {
                wProgramPosition = msAPI_CM_GetLastFavoriteProgramPosition(E_SERVICETYPE_RADIO, bIncludeSkipped);
                if( wProgramPosition == INVALID_PROGRAM_POSITION )
                {
                    wProgramPosition = msAPI_CM_GetLastFavoriteProgramPosition(E_SERVICETYPE_DTV, bIncludeSkipped);
                    if( wProgramPosition == INVALID_PROGRAM_POSITION )
                    {
                        cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetPreviousFavoriteProgramNumber(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wBaseOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) - msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_VISIBLE_ONLY) - msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY))));
                        if(cProgramNumber == INVALID_ATV_PROGRAM_NUMBER)
                        {
                            return INVALID_ORDINAL;
                        }
                        else
                        {
                            return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + cProgramNumber;
                        }
                    }
                    else
                    {
                        return wProgramPosition;
                    }

                }
                else
                {
                    return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + wProgramPosition;
                }
            }
            else
            {
                return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + wProgramPosition;
            }
        }
        else
        {
            return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + cProgramNumber;
        }
    }
    return INVALID_ORDINAL;
}
#else
static WORD _GetPrevFavoriteOrdinalOfUnitedTV(WORD wBaseOrdinal, BOOLEAN bIncludeSkipped)
{
    WORD wProgramPosition;
    BYTE cProgramNumber;
#if (!ENABLE_DVB)
    UNUSED(bIncludeSkipped);
#endif
    #if ENABLE_SBTVD_BRAZIL_CM_APP
    if(ANT_AIR == msAPI_ATV_GetCurrentAntenna())
    {
        U16 u16Loop;

        bIncludeSkipped = bIncludeSkipped;

        for(u16Loop = wBaseOrdinal-1; u16Loop > 0   ;u16Loop--)
        {
            if(aOridinalList[u16Loop].eServicetype == E_SERVICETYPE_ATV)
            {
                if(TRUE == msAPI_ATV_IsProgramFavorite(aOridinalList[u16Loop].wPosition >> 8))
                    return  u16Loop;
            }
            else
            {
                if(TRUE == msAPI_CM_GetProgramAttribute(aOridinalList[u16Loop].eServicetype,aOridinalList[u16Loop].wPosition,E_ATTRIBUTE_IS_FAVORITE))
                    return  u16Loop;
            }
        }
    }
    #endif // ENABLE_SBTVD_BRAZIL_CM_APP
#if (ENABLE_DVB)
    if( wBaseOrdinal < msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) )
    {
        wProgramPosition = msAPI_CM_GetPrevFavoriteProgramPosition(E_SERVICETYPE_DTV, wBaseOrdinal, bIncludeSkipped);
        if( (wProgramPosition == INVALID_PROGRAM_POSITION) ||
            (wProgramPosition >= wBaseOrdinal) )
        {
            cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetLastFavoriteProgramNumber());
            if( cProgramNumber == INVALID_ATV_PROGRAM_NUMBER )
            {
                wProgramPosition = msAPI_CM_GetPrevFavoriteProgramPosition(E_SERVICETYPE_RADIO, msAPI_CM_GetFirstProgramPosition(E_SERVICETYPE_RADIO, bIncludeSkipped), bIncludeSkipped);
                if( wProgramPosition == INVALID_PROGRAM_POSITION )
                {
                    wProgramPosition = msAPI_CM_GetFirstFavoriteProgramPosition(E_SERVICETYPE_DTV, bIncludeSkipped);
                    if(wProgramPosition == INVALID_PROGRAM_POSITION)
                    {
                        return INVALID_ORDINAL;
                    }
                    else
                    {
                        return cProgramNumber;
                    }
                }
                else
                {
                    return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + wProgramPosition;
                }
            }
            else
            {
                return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + cProgramNumber;
            }
        }
        else
        {
            return wProgramPosition;
        }
    }
    else if( wBaseOrdinal < (msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY)) )
    {
        wProgramPosition = msAPI_CM_GetPrevFavoriteProgramPosition(E_SERVICETYPE_RADIO, (wBaseOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY)), bIncludeSkipped);
        if( (wProgramPosition == INVALID_PROGRAM_POSITION) ||
            (wProgramPosition >= (wBaseOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY))) )
        {
            wProgramPosition = msAPI_CM_GetPrevFavoriteProgramPosition(E_SERVICETYPE_DTV, msAPI_CM_GetFirstProgramPosition(E_SERVICETYPE_DTV, bIncludeSkipped), bIncludeSkipped);
            if(wProgramPosition == INVALID_PROGRAM_POSITION )
            {
                cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetLastFavoriteProgramNumber());
                if( cProgramNumber == INVALID_ATV_PROGRAM_NUMBER )
                {
                    wProgramPosition = msAPI_CM_GetPrevFavoriteProgramPosition(E_SERVICETYPE_RADIO, (wBaseOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY)), bIncludeSkipped);
                    if( wProgramPosition == INVALID_PROGRAM_POSITION )
                    {
                        return INVALID_ORDINAL;
                    }
                    else
                    {
                        return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + wProgramPosition;
                    }
                }
                else
                {
                    return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY)   + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + cProgramNumber;
                }
            }
            else
            {
                return wProgramPosition;
            }
        }
        else
        {
            return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + wProgramPosition;
        }
    }
    else
#endif
    {
#if (ENABLE_DVB)
        cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetPreviousFavoriteProgramNumber(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wBaseOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) - msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY))));
#else
        cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetPreviousFavoriteProgramNumber(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wBaseOrdinal )));
#endif
        if( (cProgramNumber == INVALID_ATV_PROGRAM_NUMBER) ||
            (cProgramNumber >= (BYTE)(wBaseOrdinal
#if (ENABLE_DVB)
            - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) - msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY)
#endif
            )) )
        {
#if (!ENABLE_DVB)
            wProgramPosition = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(0);
            if( cProgramNumber == INVALID_ATV_PROGRAM_NUMBER )
            {
                cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetPreviousFavoriteProgramNumber(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wBaseOrdinal  )));
                if(cProgramNumber == INVALID_ATV_PROGRAM_NUMBER)
                {
                    return INVALID_ORDINAL;
                }
                else
                {
                    return  cProgramNumber;
                }
            }
            else
            {
                return cProgramNumber;
            }
#else
            wProgramPosition = msAPI_CM_GetLastFavoriteProgramPosition(E_SERVICETYPE_RADIO, bIncludeSkipped);
            if( wProgramPosition == INVALID_PROGRAM_POSITION )
            {
                wProgramPosition = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_CM_GetLastFavoriteProgramPosition(E_SERVICETYPE_DTV, bIncludeSkipped));
                if( cProgramNumber == INVALID_ATV_PROGRAM_NUMBER )
                {
                    cProgramNumber = msAPI_ATV_ConvertProgramNumberToOrdinalNumber(msAPI_ATV_GetPreviousFavoriteProgramNumber(msAPI_ATV_ConvertOrdinalNumberToProgramNumber(wBaseOrdinal - msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) - msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY))));
                    if(cProgramNumber == INVALID_ATV_PROGRAM_NUMBER)
                    {
                        return INVALID_ORDINAL;
                    }
                    else
                    {
                        return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + cProgramNumber;
                    }
                }
                else
                {
                    return cProgramNumber;
                }
            }
            else
            {
                return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + wProgramPosition;
            }
#endif
        }
        else
        {
#if (ENABLE_DVB)
            return msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY) + cProgramNumber;
#else
            return cProgramNumber;
#endif
        }
    }
    return INVALID_ORDINAL;
}

#if ENABLE_SBTVD_BRAZIL_CM_APP
/******************************************************************************/
/// -This function will reset ordinalList
/// @param \b IN:
/// - None
/// @return
/// - None
/******************************************************************************/
void msAPI_CHPROC_CM_ResetOridial(void)
{
    U16 u16Loop;
    for(u16Loop=0;u16Loop< MAX_ATV_DTV ;u16Loop++)
    {
        aOridinalList[u16Loop].eServicetype = E_SERVICETYPE_INVALID;
        aOridinalList[u16Loop].u16LCN = INVALID_LOGICAL_CHANNEL_NUMBER;
        aOridinalList[u16Loop].wPosition = INVALID_POSITION;
    }
}
void msAPI_CHPROC_CM_InitOridial(void)
{
    U16 u16_DTVcount,u16_RADIOcount,u16Loop,u16Loop_1,u16ListIndex,u16MAX_Count;
    U8  u8_ATVcount, U8ATV_Index, u8DTV_Index;
    WORD wMinOrder,wMinLCN,wCurrentLCN;
    BYTE bMinPHY,bCurrentPhy;

    u8_ATVcount = msAPI_ATV_GetActiveProgramCount();
    u16_DTVcount = msAPI_CM_CountProgram(E_SERVICETYPE_DTV,E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO);
    u16_RADIOcount = msAPI_CM_CountProgram(E_SERVICETYPE_RADIO,E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO);

    if(u8_ATVcount > MAX_ATVPROGRAM || u16_DTVcount > MAX_DTVPROGRAM || u16_RADIOcount > MAX_DTVPROGRAM)
    {
        __ASSERT(0);
    }

    //printf("\n Isaac u8_ATVcount= %bu   %u  %u \n",u8_ATVcount,u16_DTVcount,u16_RADIOcount);
    if(!(u8_ATVcount | u16_DTVcount | u16_RADIOcount))
        return;

    U8ATV_Index = u8DTV_Index = 0;
    u16ListIndex =0;

    for(u16Loop=0;u16Loop< MAX_ATV_DTV ;u16Loop++)
    {
        aOridinalList[u16Loop].eServicetype = E_SERVICETYPE_INVALID;
        aOridinalList[u16Loop].u16LCN = INVALID_LOGICAL_CHANNEL_NUMBER;
        aOridinalList[u16Loop].wPosition = INVALID_POSITION;
    }

    u16MAX_Count = MAX(MAX(u8_ATVcount,u16_DTVcount),u16_RADIOcount);

    for(u16Loop=0;u16Loop< u16MAX_Count ;u16Loop++)
    {
        if(u8_ATVcount && (u16Loop < u8_ATVcount))
        {
            aOridinalList[u16Loop].eServicetype = E_SERVICETYPE_ATV;
            if(!u16Loop)
                aOridinalList[u16Loop].u16LCN = (U16)(msAPI_ATV_GetFirstProgramNumber(FALSE)<< 8);
            else
                aOridinalList[u16Loop].u16LCN = (U16)(msAPI_ATV_GetNextProgramNumber(aOridinalList[u16Loop-1].u16LCN >> 8,TRUE)<< 8);
            aOridinalList[u16Loop].wPosition = aOridinalList[u16Loop].u16LCN; //INVALID_POSITION;
        }

        if(u16_DTVcount && ( u16Loop < u16_DTVcount))
        {
            aOridinalList[u16Loop+u8_ATVcount].eServicetype = E_SERVICETYPE_DTV;
            aOridinalList[u16Loop+u8_ATVcount].u16LCN = msAPI_CM_GetLogicalChannelNumber(E_SERVICETYPE_DTV,u16Loop);
            aOridinalList[u16Loop+u8_ATVcount].wPosition = u16Loop;
        }

        if(u16_RADIOcount && (u16Loop < u16_RADIOcount))
        {
            aOridinalList[u16Loop+u8_ATVcount+u16_DTVcount].eServicetype = E_SERVICETYPE_RADIO;
            aOridinalList[u16Loop+u8_ATVcount+u16_DTVcount].u16LCN = msAPI_CM_GetLogicalChannelNumber(E_SERVICETYPE_RADIO,u16Loop);
            aOridinalList[u16Loop+u8_ATVcount+u16_DTVcount].wPosition = u16Loop;
        }
    }

    u16MAX_Count = u8_ATVcount+u16_DTVcount+u16_RADIOcount;
    Set_MAXOridinal(u16MAX_Count);

    /*for(u16Loop_1=0; u16Loop_1 < u16MAX_Count; u16Loop_1++)
        printf("\n Isaac Before u16Loop= %u eServicetype=%bu  u16LCN= %u  wPosition= %u  PHY= %bu \n",u16Loop_1,aOridinalList[u16Loop_1].eServicetype,aOridinalList[u16Loop_1].u16LCN,aOridinalList[u16Loop_1].wPosition,aOridinalList[u16Loop_1].stLCN.bPhysicalChannel);
    */
    for(u16Loop= 0;u16Loop < u16MAX_Count;u16Loop++)
    {
        wMinOrder = u16Loop;
        if(aOridinalList[u16Loop].eServicetype == E_SERVICETYPE_ATV)
            wMinLCN = aOridinalList[u16Loop].u16LCN + 0x100;
        else
            wMinLCN = aOridinalList[u16Loop].u16LCN;
        bMinPHY = aOridinalList[u16Loop].stLCN.bPhysicalChannel;

        for(u16Loop_1=u16Loop+1; u16Loop_1 < u16MAX_Count; u16Loop_1++)
        {
            if(aOridinalList[u16Loop_1].eServicetype == E_SERVICETYPE_ATV)
                wCurrentLCN = aOridinalList[u16Loop_1].u16LCN + 0x100;
            else
                wCurrentLCN = aOridinalList[u16Loop_1].u16LCN;
            bCurrentPhy = aOridinalList[u16Loop_1].stLCN.bPhysicalChannel;

            if(wMinLCN > wCurrentLCN)
            {
                wMinLCN =  wCurrentLCN;
                wMinOrder =  u16Loop_1;
            }
            else if(wMinLCN == wCurrentLCN)
            {
                if(msAPI_CM_GetPhysicalChannelNumber(aOridinalList[u16Loop].eServicetype,aOridinalList[u16Loop].wPosition)
                    >msAPI_CM_GetPhysicalChannelNumber(aOridinalList[u16Loop_1].eServicetype,aOridinalList[u16Loop].wPosition))
                {
                    wMinLCN =  wCurrentLCN;
                    wMinOrder =  u16Loop_1;
                }
            }
        }

        if( wMinOrder != u16Loop )
        {
            #if ( WATCH_DOG == ENABLE )
            msAPI_Timer_ResetWDT();
            #endif

            SwapOridinal(wMinOrder, u16Loop);
        }
    }
    /*
    for(u16Loop_1=0; u16Loop_1 < u16MAX_Count; u16Loop_1++)
        printf("\n Isaac After u16Loop= %u eServicetype=%bu  u16LCN= %u  wPosition= %u \n",u16Loop_1,aOridinalList[u16Loop_1].eServicetype,aOridinalList[u16Loop_1].u16LCN,aOridinalList[u16Loop_1].wPosition);
    */
}

static BOOLEAN SwapOridinal(WORD wFromOrder, WORD wToOrder)
{
    ORIDINAL_LIST stOridinal;

    if(wFromOrder == wToOrder)
    {
        return TRUE;
    }

    stOridinal = aOridinalList[wFromOrder];
    aOridinalList[wFromOrder] = aOridinalList[wToOrder];
    aOridinalList[wToOrder] = stOridinal;

    return TRUE;
}

static void Set_MAXOridinal(WORD wMax_Ori)
{
    if(wMax_Ori > MAX_ATV_DTV)
    {
        __ASSERT(0);
    }

    wMAX_OridinalCount = wMax_Ori;
}

static WORD Get_MAXOridinal(void)
{
    if(wMAX_OridinalCount > MAX_ATV_DTV)
    {
        __ASSERT(0);
    }

    return wMAX_OridinalCount;
}


WORD msAPI_CHPROC_CM_GetOrdinal_Brazil(MEMBER_SERVICETYPE bServiceType,WORD wPosition)
{
    U16 u16Max_Ori,u16Loop;

    u16Max_Ori = Get_MAXOridinal();

    if(bServiceType == E_SERVICETYPE_ATV )
        wPosition = (U16)(wPosition << 8);

    for(u16Loop=0;u16Loop<u16Max_Ori;u16Loop++)
    {
         if(aOridinalList[u16Loop].eServicetype == bServiceType &&
            aOridinalList[u16Loop].wPosition == wPosition )
         return  u16Loop;
    }
    return INVALID_POSITION;
}

MEMBER_SERVICETYPE msAPI_CHPROC_CM_GetServiceTypeByLCN_Brazil(WORD wLCN,WORD * wOridinal)
{
    U16 u16Max_Ori,u16Loop;
    //MEMBER_SERVICETYPE bServiceType;

    if(ANT_CATV == msAPI_ATV_GetCurrentAntenna())
    {
        return E_SERVICETYPE_ATV;
    }

    u16Max_Ori = Get_MAXOridinal();

    for(u16Loop=0;u16Loop<u16Max_Ori;u16Loop++)
    {
         if( aOridinalList[u16Loop].u16LCN == wLCN )
         {
            *wOridinal = u16Loop;
            return  aOridinalList[u16Loop].eServicetype;
         }
    }

    if(u16Loop == u16Max_Ori)
    {
        wLCN = (U16)((wLCN -1) << 8);

        for(u16Loop=0;u16Loop<u16Max_Ori;u16Loop++)
        {
             if( aOridinalList[u16Loop].u16LCN == wLCN )
             {
                *wOridinal = u16Loop;
                return  aOridinalList[u16Loop].eServicetype;
             }
        }
    }

    UNUSED(*wOridinal);

    return E_SERVICETYPE_INVALID;
}



BOOLEAN msAPI_CHPROC_CM_GetOrdinal_SerType_Position_Brazil(WORD wOridinal,MEMBER_SERVICETYPE * pbServiceType,WORD * pwPosition)
{
    //*pbServiceType = E_SERVICETYPE_INVALID;
    *pbServiceType = aOridinalList[wOridinal].eServicetype;
    *pwPosition =    aOridinalList[wOridinal].wPosition;

    if(*pbServiceType == E_SERVICETYPE_INVALID)
        return FALSE;
    else
        return TRUE;
}
#endif // ENABLE_SBTVD_BRAZIL_CM_APP

#endif
#if(ENABLE_S2_FIND_PROGRAM_BYNAME)
WORD msAPI_CHPROC_CM_CountFindProgramByName(MEMBER_SERVICETYPE bServiceType,BYTE *bProgramName)
{
    switch(bServiceType)
    {
    case E_SERVICETYPE_RADIO:
    case E_SERVICETYPE_DTV:
    case E_SERVICETYPE_DATA:
    case E_SERVICETYPE_UNITED_TV:
        return msAPI_CM_CountFindProgramByName(bServiceType,bProgramName);
    //case E_SERVICETYPE_UNITED_TV:
        //return msAPI_CM_CountFindProgramByName(E_SERVICETYPE_DTV,bProgramName) +  msAPI_CM_CountFindProgramByName(E_SERVICETYPE_DATA,bProgramName) + msAPI_CM_CountFindProgramByName(E_SERVICETYPE_RADIO,bProgramName);
    default:
        break;

    }

    return 0;
}

WORD msAPI_CHPROC_CM_GetPrevFindProgramByNameOrdinal(MEMBER_SERVICETYPE bServiceType, WORD wBaseOrdinal, BOOLEAN bIncludeSkipped,BYTE *bProgramName)
{
    WORD wProgramPosition=0;
    switch(bServiceType)
    {
    case E_SERVICETYPE_RADIO:
    case E_SERVICETYPE_DTV:
    case E_SERVICETYPE_DATA:
    case E_SERVICETYPE_UNITED_TV:

        wProgramPosition = msAPI_CM_GetPrevFindProgramByNamePosition(bServiceType, wBaseOrdinal, bIncludeSkipped,bProgramName);
        if( (wProgramPosition == INVALID_PROGRAM_POSITION) ||
            (wProgramPosition >= wBaseOrdinal) )
        {
            return INVALID_ORDINAL;
        }
        else
        {
            return wProgramPosition;
        }
        break;
    default:
        break;
    }
    return INVALID_ORDINAL;
}

WORD msAPI_CHPROC_CM_GetNextFindProgramByNameOrdinal(MEMBER_SERVICETYPE bServiceType, WORD wBaseOrdinal, BOOLEAN bIncludeSkipped,BYTE *bProgramName)
{
    WORD wProgramPosition=0;
    switch(bServiceType)
    {
    case E_SERVICETYPE_RADIO:
    case E_SERVICETYPE_DTV:
    case E_SERVICETYPE_DATA:
    case E_SERVICETYPE_UNITED_TV:

        wProgramPosition = msAPI_CM_GetNextFindProgramByNamePosition(bServiceType, wBaseOrdinal, bIncludeSkipped,bProgramName);
        if( (wProgramPosition == INVALID_PROGRAM_POSITION) ||
            (wProgramPosition <= wBaseOrdinal) )
        {
            return INVALID_ORDINAL;
        }
        else
        {
            return wProgramPosition;
        }
        break;
    default:
        break;
    }
    return INVALID_ORDINAL;
}
#endif
