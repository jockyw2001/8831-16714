#include "cpptest.h"

#include "MsTypes.h"
#include "MsIRQ.h"

/*
 * core_msAPI_Memory_stub.c
 *
 *  Created on: 9 Oct 2013
 *      Author: muters
 */

EXTERN_C_LINKAGE MS_BOOL MsOS_FreeMemory (void *pAddress, MS_S32 s32PoolId);
EXTERN_C_LINKAGE MS_BOOL CppTest_Auto_Stub_MsOS_FreeMemory(void *pAddress, MS_S32 s32PoolId)
{
	if(CppTest_IsCurrentTestCase("TestSuites_msAPI_Memory_test_msAPI_Memory_Free_0"))
	{
		return FALSE;
	}

	if(CppTest_IsCurrentTestCase("TestSuites_msAPI_Memory_test_msAPI_Memory_Free_1"))
	{
		return TRUE;
	}
	return TRUE;
}
