#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app/MApp_AnalogInputs.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app/MApp_AnalogInputs.c");

CPPTEST_TEST_SUITE(TestSuite_MApp_AnalogInputs);
CPPTEST_TEST(TestSuite_MApp_AnalogInputs_test_MApp_AnalogInputs_FunctionNotAvailableCheck_IsTrue);
CPPTEST_TEST(TestSuite_MApp_AnalogInputs_test_MApp_AnalogInputs_FunctionNotAvailableCheck_IsFalse);
CPPTEST_TEST(TestSuite_MApp_AnalogInputs_test_MApp_AnalogInputs_Init_Init_success);
CPPTEST_TEST(TestSuite_MApp_AnalogInputs_test_MApp_Analog_NoSignal_ResetCount_is_success);
CPPTEST_TEST(TestSuite_MApp_AnalogInputs_test_MApp_AnalogInputs_Force2MonitorWindows_success);
CPPTEST_TEST(TestSuite_MApp_AnalogInputs_test_MApp_AnalogInputs_ResetTimer_success);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_MApp_AnalogInputs_test_MApp_AnalogInputs_FunctionNotAvailableCheck_IsTrue();
void TestSuite_MApp_AnalogInputs_test_MApp_AnalogInputs_FunctionNotAvailableCheck_IsFalse();
void TestSuite_MApp_AnalogInputs_test_MApp_AnalogInputs_Init_Init_success();
void TestSuite_MApp_AnalogInputs_test_MApp_Analog_NoSignal_ResetCount_is_success();
void TestSuite_MApp_AnalogInputs_test_MApp_AnalogInputs_Force2MonitorWindows_success();
void TestSuite_MApp_AnalogInputs_test_MApp_AnalogInputs_ResetTimer_success();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_MApp_AnalogInputs);

void TestSuite_MApp_AnalogInputs_setUp()
{
}

void TestSuite_MApp_AnalogInputs_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_AnalogInputs_FunctionNotAvailableCheck_IsTrue */
void TestSuite_MApp_AnalogInputs_test_MApp_AnalogInputs_FunctionNotAvailableCheck_IsTrue()
{
    /* Tested function call */
	BOOLEAN _return = MApp_AnalogInputs_FunctionNotAvailableCheck();
    /* Post-condition check */
	CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
}
/* CPPTEST_TEST_CASE_END test_MApp_AnalogInputs_FunctionNotAvailableCheck_IsTrue */



/* CPPTEST_TEST_CASE_BEGIN test_MApp_AnalogInputs_FunctionNotAvailableCheck_IsFalse */
void TestSuite_MApp_AnalogInputs_test_MApp_AnalogInputs_FunctionNotAvailableCheck_IsFalse()
{
    /* Tested function call */
	BOOLEAN _return = MApp_AnalogInputs_FunctionNotAvailableCheck();
    /* Post-condition check */
	CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
}
/* CPPTEST_TEST_CASE_END test_MApp_AnalogInputs_FunctionNotAvailableCheck_IsFalse */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_AnalogInputs_Init_Init_success */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_AnalogInputs_Init(SCALER_WIN) */
void TestSuite_MApp_AnalogInputs_test_MApp_AnalogInputs_Init_Init_success()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */ 
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    /* Initializing global variable u16IdleInputValue */ 
    {
         u16IdleInputValue  = 100;
    }
    {
        /* Tested function call */
        MApp_AnalogInputs_Init(_eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0, ( u16IdleInputValue ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_AnalogInputs_Init_Init_success */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Analog_NoSignal_ResetCount_is_success */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Analog_NoSignal_ResetCount(SCALER_WIN) */
void TestSuite_MApp_AnalogInputs_test_MApp_Analog_NoSignal_ResetCount_is_success()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */ 
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    su8NoSignalDisplayCNT[_eWindow] = 2;
    //DELAY_4SEC = 4000;
    {
        /* Tested function call */
        MApp_Analog_NoSignal_ResetCount(_eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(DELAY_4SEC, su8NoSignalDisplayCNT[_eWindow]);

    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Analog_NoSignal_ResetCount_is_success */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_AnalogInputs_Force2MonitorWindows_success */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_AnalogInputs_Force2MonitorWindows(SCALER_WIN) */
void TestSuite_MApp_AnalogInputs_test_MApp_AnalogInputs_Force2MonitorWindows_success()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */ 
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    U32  u32TempTimer = u32AnalogInputsModeWinTimer[_eWindow];
    {
        /* Tested function call */
        MApp_AnalogInputs_Force2MonitorWindows(_eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(u32TempTimer - TV_MODE_WINDOW_MONITOR_PERIOD, u32AnalogInputsModeWinTimer[_eWindow]);
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_AnalogInputs_Force2MonitorWindows_success */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_AnalogInputs_ResetTimer_success */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_AnalogInputs_ResetTimer(SCALER_WIN) */
void TestSuite_MApp_AnalogInputs_test_MApp_AnalogInputs_ResetTimer_success()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */ 
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    u32AnalogInputsModeWinTimer[_eWindow] = 500;
    {
        /* Tested function call */
        MApp_AnalogInputs_ResetTimer(_eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0, u32AnalogInputsModeWinTimer[_eWindow]);
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_AnalogInputs_ResetTimer_success */
