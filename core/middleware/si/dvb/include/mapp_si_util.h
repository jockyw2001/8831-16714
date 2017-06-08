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

#ifndef MAPP_SI_UTIL_H
#define MAPP_SI_UTIL_H
#if(ENABLE_DTV)
#include "mapp_si.h"
#include "apiAUDIO.h"
/******************************************************************************/
/*                       Global Variable Declarations                         */
/******************************************************************************/
#ifdef MAPP_SI_UTIL_C
#define INTERFACE
#else
#define INTERFACE extern
#endif
INTERFACE MEMBER_SERVICETYPE msAPI_SI_ToCM_Service_Type(MEMBER_SI_SERVICETYPE btype);
INTERFACE MEMBER_SI_SERVICETYPE msAPI_SI_ToSI_Service_Type(MEMBER_SERVICETYPE btype);
INTERFACE U8 msAPI_SI_ToCM_Audio_Mode(U8 btype);
INTERFACE U8 msAPI_SI_ToCM_Audio_Type(U8 btype);
INTERFACE U8 msAPI_SI_ToCM_Video_Type(U8 btype);
INTERFACE U8 msAPI_SI_ToCM_Service_Priority(U8 bPriority);
INTERFACE EN_DELIVERY_SYS_TYPE msAPI_SI_ToCM_Delivery_Type(EN_SI_DELIVERY_SYS_TYPE btype);
#undef INTERFACE


#endif//#if(MAPP_SI_UTIL_H)
#endif

