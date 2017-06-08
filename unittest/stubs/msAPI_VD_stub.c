#include "cpptest.h"

/**
 * This file contains user stub definitions.
 *
 * To create a user stub:
 * 1. Open stub template list:
 *    - Eclipse IDE: type 'stub' and press <Ctrl> <Space>
 *    - Microsoft Visual Studio IDE: use context menu C++test->Insert Snippet...
 * 2. Choose the stub template from the list.
 * 3. #include the header file where the function you want to stub is originally 
 *    declared as well as any supporting header files as necessary.
 * 4. Fill out the stub signature to match that of the original function, 
 *    while keeping the CppTest_Stub prefix when it applies.
 *    Note: for C++ operators, use appropriate stub names - e.g.:
 *        CppTest_Stub_operator_new    for operator new
 *        CppTest_Stub_operator_delete for operator delete
 *        CppTest_Stub_operator_plus   for operator +
 *    Refer to C++test User's Guide for a complete list of stub names for operators. 
 * 5. Fill out the body of the stub according to intent.
 *
 * Available C++test API functions (see C++test Users Guide for details):
 *     void CppTest_Assert(bool test, const char * message)
 *     void CppTest_Break()
 *     const char* CppTest_GetCurrentTestCaseName()
 *     const char* CppTest_GetCurrentTestSuiteName()
 *     bool CppTest_IsCurrentTestCase(const char* testCaseName)
 */

/** 
 * Header files where the stubbed functions are originally declared.
 * Verify #include directives and add any additional header files as necessary.
 */
#include "msAPI_TTX.h"

/** User stub definition for function: MS_U8 msAPI_TTX_GetWssStatus(void) */
EXTERN_C_LINKAGE MS_U8 msAPI_TTX_GetWssStatus () ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_msAPI_TTX_GetWssStatus (void) 
{
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_ARC_INVALID"))
	{
		return (unsigned short)FALSE;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_VD_TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_4x3_FULL"))
	{
		return (unsigned short)TRUE;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_16x9_ANAMORPHIC"))
	{
		return (unsigned short)TRUE;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_Default"))
	{
		return (unsigned short)TRUE;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_4x3_FULL"))
	{
		return (unsigned short)TRUE;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_14x9_LETTERBOX_TOP"))
	{
		return (unsigned short)TRUE;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_16x9_LETTERBOX_CENTER"))
	{
		return (unsigned short)TRUE;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_16x9_LETTERBOX_TOP"))
	{
		return (unsigned short)TRUE;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_ABOVE16x9_LETTERBOX_CENTER"))
	{
		return (unsigned short)TRUE;
	}
}

/** User stub definition for function: MS_U16 msAPI_TTX_ReadWssWord(void) */
EXTERN_C_LINKAGE MS_U16 msAPI_TTX_ReadWssWord () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_msAPI_TTX_ReadWssWord (void) 
{
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_4x3_FULL"))
	{
		return (unsigned short)0x08;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_14x9_LETTERBOX_CENTER"))
	{
		return (unsigned short)0x01;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_14x9_LETTERBOX_TOP"))
	{
		return (unsigned short)0x02;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_16x9_LETTERBOX_CENTER"))
	{
		return (unsigned short)0x0B;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_16x9_LETTERBOX_TOP"))
	{
		return (unsigned short)0x04;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_ABOVE16x9_LETTERBOX_CENTER"))
	{
		return (unsigned short)0x0D;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_14x9_FULL_CENTER"))
	{
		return (unsigned short)0x0E;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_16x9_ANAMORPHIC"))
	{
		return (unsigned short)0x07;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_Default"))
	{
		return (unsigned short)FALSE;
	}
}
