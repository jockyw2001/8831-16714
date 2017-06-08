#include "cpptest.h"
#include "Datatype.h"

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
#include "MApp_PCMode.h"
#include "apiXC_PCMonitor.h"
#include "mapp_mplayer.h"
#include "apiXC_Adc.h"

/** User stub definition for function: void MApp_MPlayer_StopCopy(void) */
EXTERN_C_LINKAGE void MApp_MPlayer_StopCopy () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_MPlayer_StopCopy (void) 
{
}

/** User stub definition for function: BOOLEAN MApp_ADC_HW_SaveGainOffset(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_ADC_HW_SaveGainOffset () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_ADC_HW_SaveGainOffset (void) 
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN MApp_MPlayer_EnterCopyMode(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_MPlayer_EnterCopyMode () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_MPlayer_EnterCopyMode (void) 
{
    return (unsigned char)0;
}

/** User stub definition for function: U16 MApp_MPlayer_QueryCurrentSelectedCopyingFileIndex(void) */
EXTERN_C_LINKAGE U16 MApp_MPlayer_QueryCurrentSelectedCopyingFileIndex () ;
EXTERN_C_LINKAGE U16 CppTest_Stub_MApp_MPlayer_QueryCurrentSelectedCopyingFileIndex (void) 
{
    return (unsigned short)0;
}

/** User stub definition for function: MS_U32 MApi_XC_PCMonitor_Get_VFreqx1K(SCALER_WIN) */
EXTERN_C_LINKAGE MS_U32 MApi_XC_PCMonitor_Get_VFreqx1K (SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE MS_U32 CppTest_Stub_MApi_XC_PCMonitor_Get_VFreqx1K (SCALER_WIN eWindow) 
{
    return 0UL;
}

/** User stub definition for function: BOOLEAN MApp_MPlayer_IsCopying(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_MPlayer_IsCopying () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_MPlayer_IsCopying (void) 
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN MApp_MPlayer_QueryIsCopyMode(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_MPlayer_QueryIsCopyMode () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_MPlayer_QueryIsCopyMode (void) 
{
    return (unsigned char)0;
}

/** User stub definition for function: U16 MApp_MPlayer_QueryPasteFileStatus(void) */
EXTERN_C_LINKAGE U16 MApp_MPlayer_QueryPasteFileStatus () ;
EXTERN_C_LINKAGE U16 CppTest_Stub_MApp_MPlayer_QueryPasteFileStatus (void) 
{
    return (unsigned short)0;
}

/** User stub definition for function: BOOLEAN MApp_MPlayer_ExitCopyMode(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_MPlayer_ExitCopyMode () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_MPlayer_ExitCopyMode (void) 
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MApi_XC_ADC_EnableHWCalibration(MS_BOOL) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_ADC_EnableHWCalibration (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_ADC_EnableHWCalibration (MS_BOOL bEnable) 
{
    return (unsigned char)0;
}
