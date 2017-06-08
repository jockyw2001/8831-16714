#include "cpptest.h"

#include "MsTypes.h"
#include "MsCommon.h"
#include "msAPI_MailBox.h"
#include "drvMBX.h"

/*
 * core_msAPI_MailBox_stub.c
 *
 *  Created on: 10 Oct 2013
 *      Author: muters
 */

MS_BOOL g_CppTest_Stub_MDrv_MBX_SendMsg_blnResult = FALSE;
EXTERN_C_LINKAGE MBX_Result  MDrv_MBX_SendMsg(MBX_Msg *pMsg);
EXTERN_C_LINKAGE MBX_Result  CppTest_Stub_MDrv_MBX_SendMsg(MBX_Msg *pMsg)
{
	g_CppTest_Stub_MDrv_MBX_SendMsg_blnResult = FALSE;
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_MailBox_test_MSApi_MBX_SendMsg_ReturnTrue"))
	{
		return E_MBX_SUCCESS;
	}

	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_MailBox_test_MSApi_MBX_SendMsg_Mock"))
	{
		if ((pMsg->eRoleID == E_MBX_ROLE_CP) && (pMsg->u8Ctrl == 0) && (pMsg->u8S0 == 0) && (pMsg->u8S1 == 0))
		{
			g_CppTest_Stub_MDrv_MBX_SendMsg_blnResult = TRUE;
		}
		return E_MBX_SUCCESS;
	}
	return E_MBX_SUCCESS;
}
