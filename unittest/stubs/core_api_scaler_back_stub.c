#include "cpptest.h"
/*
 * core_api_scaler_back_stub.c
 *
 *  Created on: 20 Dec 2013
 *      Author: muters
 */

#include "drvGlobal.h"

// Common Definition
#include "Board.h"
#include "datatype.h"
#include "MsCommon.h"

#include "apiXC.h"
#include "apiXC_Sys.h"
#include "msAPI_NR.h"
#include "apiXC_Ace.h"
#include "apiXC_Dlc.h"
#include "msAPI_VD.h"
#include "drvAVD.h"
#include "drvPQ.h"
#if (ENABLE_NEW_AUTO_NR)
#include "MApp_GlobalSettingSt.h"
#endif

EXTERN_C_LINKAGE void msAPI_DynamicNR_Motion(MS_DYNAMIC_NR_PARAM *pstDymaicNRParam);
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_DynamicNR_Motion(MS_DYNAMIC_NR_PARAM *pstDymaicNRParam)
{
}

EXTERN_C_LINKAGE void msAPI_DynamicNR_Luma(MS_DYNAMIC_NR_PARAM *pstDymaicNRParam);
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_DynamicNR_Luma(MS_DYNAMIC_NR_PARAM *pstDymaicNRParam)
{

}

EXTERN_C_LINKAGE void msAPI_DynamicNR_Init_Noise(U8 *pNRTbl, MS_DYNAMIC_NR_MISC_PARAM_NOISE *pstMisc);
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_DynamicNR_Init_Noise(U8 *pNRTbl, MS_DYNAMIC_NR_MISC_PARAM_NOISE *pstMisc)
{

}

EXTERN_C_LINKAGE void msAPI_DynamicNR_Init_Motion(U8 *pNRTbl);
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_DynamicNR_Init_Motion(U8 *pNRTbl)
{

}

EXTERN_C_LINKAGE void msAPI_DynamicNR_Init_Luma(MS_DYNAMIC_NR_MISC_PARAM_LUMA *pstMisc);
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_DynamicNR_Init_Luma(MS_DYNAMIC_NR_MISC_PARAM_LUMA *pstMisc)
{

}


