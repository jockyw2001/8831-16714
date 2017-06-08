#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/emerald1/msIR.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/emerald1/msIR.c");

CPPTEST_TEST_SUITE(TestSuite_msIR);
#if (IR_MODE_SEL != IR_TYPE_SWDECODE_SHA_MODE)
CPPTEST_TEST(TestSuite_msIR_test_MDrv_IR_IsIRkeyEnabled_case_IRKEY_P_CHECK);
CPPTEST_TEST(TestSuite_msIR_test_MDrv_IR_IsIRkeyEnabled_case_IRKEY_S_CHECK);
CPPTEST_TEST(TestSuite_msIR_test_MDrv_IR_IsIRkeyEnabled_case_IRKEY_ADJUST);
#endif
CPPTEST_TEST(TestSuite_msIR_test_MDrv_IR_IsIRkeyEnabled_case_IRKEY_POWER);
CPPTEST_TEST(TestSuite_msIR_test_MDrv_IR_IsIRkeyEnabled_case_default);
CPPTEST_TEST(TestSuite_msIR_test_msIR_SwitchToFullDecodeMode_pass);
CPPTEST_TEST(TestSuite_msIR_test_msIR_SwitchToSWMode_pass);
CPPTEST_TEST(TestSuite_msIR_test_msIR_ResetSoftWareModeVariables);
CPPTEST_TEST_SUITE_END();
        
#if (IR_MODE_SEL != IR_TYPE_SWDECODE_SHA_MODE)
void TestSuite_msIR_test_MDrv_IR_IsIRkeyEnabled_case_IRKEY_P_CHECK();
void TestSuite_msIR_test_MDrv_IR_IsIRkeyEnabled_case_IRKEY_S_CHECK();
void TestSuite_msIR_test_MDrv_IR_IsIRkeyEnabled_case_IRKEY_ADJUST();
#endif
void TestSuite_msIR_test_MDrv_IR_IsIRkeyEnabled_case_IRKEY_POWER();
void TestSuite_msIR_test_MDrv_IR_IsIRkeyEnabled_case_default();
void TestSuite_msIR_test_msIR_SwitchToFullDecodeMode_pass();
void TestSuite_msIR_test_msIR_SwitchToSWMode_pass();
void TestSuite_msIR_test_msIR_ResetSoftWareModeVariables();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_msIR);

void TestSuite_msIR_setUp()
{
}

void TestSuite_msIR_tearDown()
{
}

#if (IR_MODE_SEL != IR_TYPE_SWDECODE_SHA_MODE)
/* CPPTEST_TEST_CASE_BEGIN test_MDrv_IR_IsIRkeyEnabled_case_IRKEY_P_CHECK */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MDrv_IR_IsIRkeyEnabled(U8) */
void TestSuite_msIR_test_MDrv_IR_IsIRkeyEnabled_case_IRKEY_P_CHECK()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8IRkey) */ 
    U8 _u8IRkey  = IRKEY_P_CHECK;
    {
        /* Tested function call */
        BOOLEAN _return  = MDrv_IR_IsIRkeyEnabled(_u8IRkey);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_IR_IsIRkeyEnabled_case_IRKEY_P_CHECK */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_IR_IsIRkeyEnabled_case_IRKEY_S_CHECK */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MDrv_IR_IsIRkeyEnabled(U8) */
void TestSuite_msIR_test_MDrv_IR_IsIRkeyEnabled_case_IRKEY_S_CHECK()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8IRkey) */ 
    U8 _u8IRkey  = IRKEY_S_CHECK;
    {
        /* Tested function call */
        BOOLEAN _return  = MDrv_IR_IsIRkeyEnabled(_u8IRkey);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_IR_IsIRkeyEnabled_case_IRKEY_S_CHECK */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_IR_IsIRkeyEnabled_case_IRKEY_ADJUST */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MDrv_IR_IsIRkeyEnabled(U8) */
void TestSuite_msIR_test_MDrv_IR_IsIRkeyEnabled_case_IRKEY_ADJUST()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8IRkey) */ 
    U8 _u8IRkey  = IRKEY_ADJUST;
    {
        /* Tested function call */
        BOOLEAN _return  = MDrv_IR_IsIRkeyEnabled(_u8IRkey);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_IR_IsIRkeyEnabled_case_IRKEY_ADJUST */
#endif //(IR_MODE_SEL != IR_TYPE_SWDECODE_SHA_MODE)


/* CPPTEST_TEST_CASE_BEGIN test_MDrv_IR_IsIRkeyEnabled_case_IRKEY_POWER */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MDrv_IR_IsIRkeyEnabled(U8) */
void TestSuite_msIR_test_MDrv_IR_IsIRkeyEnabled_case_IRKEY_POWER()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8IRkey) */ 
    U8 _u8IRkey  = IRKEY_POWER;
    {
        /* Tested function call */
        BOOLEAN _return  = MDrv_IR_IsIRkeyEnabled(_u8IRkey);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_IR_IsIRkeyEnabled_case_IRKEY_POWER */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_IR_IsIRkeyEnabled_case_default */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MDrv_IR_IsIRkeyEnabled(U8) */
void TestSuite_msIR_test_MDrv_IR_IsIRkeyEnabled_case_default()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8IRkey) */ 
    U8 _u8IRkey  = IRKEY_SELECT;
    {
        /* Tested function call */
        BOOLEAN _return  = MDrv_IR_IsIRkeyEnabled(_u8IRkey);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_IR_IsIRkeyEnabled_case_default */

/* CPPTEST_TEST_CASE_BEGIN test_msIR_SwitchToFullDecodeMode_pass */
/* CPPTEST_TEST_CASE_CONTEXT void msIR_SwitchToFullDecodeMode(void) */
void TestSuite_msIR_test_msIR_SwitchToFullDecodeMode_pass()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        msIR_SwitchToFullDecodeMode();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_msIR_SwitchToFullDecodeMode_pass */

/* CPPTEST_TEST_CASE_BEGIN test_msIR_SwitchToSWMode_pass */
/* CPPTEST_TEST_CASE_CONTEXT void msIR_SwitchToSWMode(void) */
void TestSuite_msIR_test_msIR_SwitchToSWMode_pass()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        msIR_SwitchToSWMode();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_msIR_SwitchToSWMode_pass */


/* CPPTEST_TEST_CASE_BEGIN test_msIR_ResetSoftWareModeVariables */
/* CPPTEST_TEST_CASE_CONTEXT void msIR_ResetSoftWareModeVariables(void) */
void TestSuite_msIR_test_msIR_ResetSoftWareModeVariables()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_ucIrRepeatSkipCnt */ 
    {
         g_ucIrRepeatSkipCnt  = 0;
    }
    /* Initializing global variable g_ucIrByteIndex */ 
    {
         g_ucIrByteIndex  = 0;
    }
    /* Initializing global variable g_ucIrPulseCntIndex */ 
    {
         g_ucIrPulseCntIndex  = 0;
    }
    /* Initializing global variable g_bIrStartReceived */ 
    {
         g_bIrStartReceived  = 0;
    }
    /* Initializing global variable g_bIrDetect */ 
    {
         g_bIrDetect  = 0;
    }
    /* Initializing global variable g_bIrRepeat */ 
    {
         g_bIrRepeat  = 0;
    }
    {
        /* Tested function call */
        msIR_ResetSoftWareModeVariables();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(IR_REPEAT_SKIP_COUNT, ( g_ucIrRepeatSkipCnt ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( g_ucIrByteIndex ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( g_ucIrPulseCntIndex ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( g_bIrStartReceived ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( g_bIrDetect ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( g_bIrRepeat ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msIR_ResetSoftWareModeVariables */
