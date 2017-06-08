#include "cpptest.h"
/*
 * core_api_n51fs_stub.c
 *
 *  Created on: 11 Oct 2013
 *      Author: muters
 */
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "stdio.h"
#include "datatype.h"
#include "msAPI_FSEnv.h"
#include "msAPI_FSCommon.h"

EXTERN_C_LINKAGE U8 msAPI_FS_GetLeap ( U16 u16year );
EXTERN_C_LINKAGE U8 CppTest_Stub_msAPI_FS_GetLeap ( U16 u16year )
{
  if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FSEnv_test_msAPI_FS_ConvertStTime2Seconds_step1") )
  {

	  return 1;
  }
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FSEnv_test_msAPI_FS_ConvertStTime2Seconds_step2") )
  {
	  return 2;
  }
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FSEnv_test_msAPI_FS_GetDaysOfThisMonth_Month_between1and12") )
  {
	  return 2;
  }
}

EXTERN_C_LINKAGE U8 msAPI_FS_GetDaysOfThisMonth ( U16 u16Year, U8 u8Month );
EXTERN_C_LINKAGE  U8 CppTest_Stub_msAPI_FS_GetDaysOfThisMonth ( U16 u16Year, U8 u8Month )
{
  return 1;
}

EXTERN_C_LINKAGE void msAPI_FS_ConvertSeconds2StTime ( U32 u32SystemTime, FS_TIME *pstTime );
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_FS_ConvertSeconds2StTime ( U32 u32SystemTime, FS_TIME *pstTime )
{
	pstTime->u16Year = 1980;
	pstTime->u8Day = 1;
	pstTime->u8Hour = 1;
	pstTime->u8Min = 1;
	pstTime->u8Month = 1;
	pstTime->u8Sec = 0;
}


