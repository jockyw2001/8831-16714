#include "cpptest.h"
/*
 * core_api_N51FS_Index.c
 *
 *  Created on: 11 Oct 2013
 *      Author: muters
 */

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "stdio.h"

#include "MsTypes.h"
#include "MsCommon.h"
#include "datatype.h"
#include "debug.h"

#include "drvpower_if.h"
#include "msAPI_FCtrl.h"
#include "msAPI_N51FS.h"
#include "msAPI_FAT.h"
#include "msAPI_MSDCtrl.h"
#include "msAPI_FSEnv.h"
#include "msAPI_Timer.h"
#include "msAPI_FSCommon.h"



EXTERN_C_LINKAGE_START
extern BOOLEAN btest_LL_add_signed_CallLL_add = FALSE;
EXTERN_C_LINKAGE_END

EXTERN_C_LINKAGE LongLong LL_add(LongLong* pLongLong,U32 val);
EXTERN_C_LINKAGE LongLong CppTest_Stub_LL_add(LongLong* pLongLong,U32 val)
{
	LongLong retval = {1,1};

	if(CppTest_IsCurrentTestCase("TestSuite_FSUtil_test_LL_add_signed"))
	{
		//if(val >= 0)
		//{
			btest_LL_add_signed_CallLL_add = TRUE;
		//}
	}
	return retval;
}

EXTERN_C_LINKAGE_START
extern BOOLEAN btest_LL_add_signed_CallLL_subtract = FALSE;
EXTERN_C_LINKAGE_END

EXTERN_C_LINKAGE LongLong LL_subtract(LongLong* pLongLong,U32 val);
EXTERN_C_LINKAGE LongLong CppTest_Stub_LL_subtract(LongLong* pLongLong,U32 val)
{
	LongLong retval = {2,2};

	if(CppTest_IsCurrentTestCase("TestSuite_FSUtil_test_LL_add_signed"))
	{
		//if(val >= 0)
		//{
			btest_LL_add_signed_CallLL_subtract = TRUE;
		//}
	}
	return retval;
}

EXTERN_C_LINKAGE LongLong LL_multU32(U32 x, U32 y);
EXTERN_C_LINKAGE LongLong CppTest_Stub_LL_multU32(U32 x, U32 y)
{
	LongLong retval = {1,1};
	return retval;
}
