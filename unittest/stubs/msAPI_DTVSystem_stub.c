#include "cpptest.h"


#include "datatype.h"
#include "msAPI_DTVSystem.h"

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

/** User stub definition for function: BOOLEAN IsServiceTypeValid(MEMBER_SERVICETYPE) */
EXTERN_C_LINKAGE BOOLEAN IsServiceTypeValid (MEMBER_SERVICETYPE bServiceType) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_IsServiceTypeValid (MEMBER_SERVICETYPE bServiceType) 
{
    if(CppTest_IsCurrentTestCase("TestSuite_msAPI_DTVSystem_test_msAPI_CM_CountProgram_ServiceTypeInvalid")) {
        return FALSE;
    }
    else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_DTVSystem_test_msAPI_CM_CountProgram_Visible_Only")) {
        return TRUE;
    }
    else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_DTVSystem_test_msAPI_CM_CountProgram_Not_Visible_Also")) {
        return TRUE;
    }
    else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_DTVSystem_test_msAPI_CM_CountProgram_All")) {
        return TRUE;
    }
    else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_DTVSystem_test_msAPI_CM_CountProgram_Other")) {
        return TRUE;
    }
    return FALSE;
}

/** User stub definition for function: WORD msAPI_DTV_GetProgramCount(MEMBER_SERVICETYPE, COUNT_PROGRAM_OPTION) */
EXTERN_C_LINKAGE WORD msAPI_DTV_GetProgramCount(MEMBER_SERVICETYPE bServiceType, COUNT_PROGRAM_OPTION eCountOption);
EXTERN_C_LINKAGE WORD CppTest_Stub_msAPI_DTV_GetProgramCount (MEMBER_SERVICETYPE bServiceType, COUNT_PROGRAM_OPTION eCountOption)
{
    if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_GET_DTV_CHANNEL_LIST_ER") ||
       CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_DTV_SIGNAL_ER2") ||
       CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_DTV_SIGNAL_ER3"))
    {
        return 0;
    }
    else if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_GET_DTV_CHANNEL_LIST_OK") ||
            CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_DTV_SIGNAL_ER1") ||
            CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_DTV_SIGNAL_OK"))
    {
        if(bServiceType==E_SERVICETYPE_DTV)
            return 5;
        else if(bServiceType==E_SERVICETYPE_RADIO)
            return 4;
        else if(bServiceType==E_SERVICETYPE_DATA)
            return 3;
    }
    else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_DTVSystem_test_msAPI_CM_CountProgram_Visible_Only"))
    {
        return 35;
    }
    else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_DTVSystem_test_msAPI_CM_CountProgram_Not_Visible_Also"))
    {
        return 45;
    }
    else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_DTVSystem_test_msAPI_CM_CountProgram_All"))
    {
        return 55;
    }
    else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_DTVSystem_test_msAPI_CM_CountProgram_Other"))
    {
        return 5;
    }
}
