#include "cpptest.h"
/*
 * core_api_OSD_stub.c
 *
 *  Created on: 15 Nov 2013
 *      Author: muters
 */
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "stdio.h"
#include "datatype.h"
#include "MsTypes.h"

EXTERN_C_LINKAGE U32 getColorByHight_(U16 u16H);
EXTERN_C_LINKAGE U32 CppTest_Stub_getColorByHight_(U16 u16H)
{
	return 0;
}


EXTERN_C_LINKAGE void setGradientInfo_(U32 bc, U32 gc, U16 h);
EXTERN_C_LINKAGE void CppTest_Stub_setGradientInfo_(U32 bc, U32 gc, U16 h)
{
	return 0;
}

EXTERN_C_LINKAGE U16 msAPI_OSD_RESOURCE_UnicodeToIndex(FONTHANDLE handle, MS_U16 u16Unicode);
EXTERN_C_LINKAGE U16 CppTest_Stub_msAPI_OSD_RESOURCE_UnicodeToIndex(FONTHANDLE handle, MS_U16 u16Unicode)
{
	if(handle == 0)
	{
		return 0xFFFF;
	}
	else
	{
		return 1;
	}
}
