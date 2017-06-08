#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/scaler_front/msAPI_Mode.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/scaler_front/msAPI_Mode.c");

CPPTEST_TEST_SUITE(TestSuite_msAPI_Mode);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_GetScale100Value_yes);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_GetScale100Value_no);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_GetScale60Value_yes);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_GetScale60Value_no);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_GetScale64Value_yes);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_GetScale64Value_no);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_N100toReallyValue_wValue_is_0);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_N100toReallyValue_need_add_1);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_N100toReallyValue_neednot_add_1);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_msAPI_Mode_GetPcClockValue);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_msAPI_Mode_GetPcPhaseValue);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_BackLight_AdjustValue_lessthan_Ponit1_but_Y1_Greaterthan_Y0);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_BackLight_AdjustValue_Lessthan_Ponit1_but_Y1_Lessthan_Y0);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_BackLight_AdjustValue_lessthan_Ponit2_but_Y1_Greaterthan_Y0);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_BackLight_AdjustValue_lessthan_Ponit2_but_Y1_Lessthan_Y0);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_BackLight_Other_but_Y1_Greaterthan_Y0);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_BackLight_Other_but_Y1_Lessthan_Y0);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_AdjustValue_lessthan_Ponit1_but_Y1_Greaterthan_Y0);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_AdjustValue_Lessthan_Ponit1_but_Y1_Lessthan_Y0);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_AdjustValue_lessthan_Ponit2_but_Y1_Greaterthan_Y0);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_AdjustValue_lessthan_Ponit2_but_Y1_Lessthan_Y0);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_Other_but_Y1_Greaterthan_Y0);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_Other_but_Y1_Lessthan_Y0);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_GetColorTemperatureScale100Value_wValueTo_GreaterThan_wValueFrom);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_GetColorTemperatureScale100Value_wValueTo_LessThan_wValueFrom);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_GetColorTemperatureScale100Value_wValueTo_Equal_wValueFrom_u8ScaleValueFromIsZero);
CPPTEST_TEST(TestSuite_msAPI_Mode_test_GetColorTemperatureScale100Value_wValueTo_Equal_wValueFrom_u8ScaleValueFromIs100);
CPPTEST_TEST_SUITE_END();

void TestSuite_msAPI_Mode_test_GetScale100Value_yes();
void TestSuite_msAPI_Mode_test_GetScale100Value_no();
void TestSuite_msAPI_Mode_test_GetScale60Value_yes();
void TestSuite_msAPI_Mode_test_GetScale60Value_no();
void TestSuite_msAPI_Mode_test_GetScale64Value_yes();
void TestSuite_msAPI_Mode_test_GetScale64Value_no();
void TestSuite_msAPI_Mode_test_N100toReallyValue_wValue_is_0();
void TestSuite_msAPI_Mode_test_N100toReallyValue_need_add_1();
void TestSuite_msAPI_Mode_test_N100toReallyValue_neednot_add_1();
void TestSuite_msAPI_Mode_test_msAPI_Mode_GetPcClockValue();
void TestSuite_msAPI_Mode_test_msAPI_Mode_GetPcPhaseValue();
void TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_BackLight_AdjustValue_lessthan_Ponit1_but_Y1_Greaterthan_Y0();
void TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_BackLight_AdjustValue_Lessthan_Ponit1_but_Y1_Lessthan_Y0();
void TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_BackLight_AdjustValue_lessthan_Ponit2_but_Y1_Greaterthan_Y0();
void TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_BackLight_AdjustValue_lessthan_Ponit2_but_Y1_Lessthan_Y0();
void TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_BackLight_Other_but_Y1_Greaterthan_Y0();
void TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_BackLight_Other_but_Y1_Lessthan_Y0();
void TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_AdjustValue_lessthan_Ponit1_but_Y1_Greaterthan_Y0();
void TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_AdjustValue_Lessthan_Ponit1_but_Y1_Lessthan_Y0();
void TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_AdjustValue_lessthan_Ponit2_but_Y1_Greaterthan_Y0();
void TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_AdjustValue_lessthan_Ponit2_but_Y1_Lessthan_Y0();
void TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_Other_but_Y1_Greaterthan_Y0();
void TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_Other_but_Y1_Lessthan_Y0();
void TestSuite_msAPI_Mode_test_GetColorTemperatureScale100Value_wValueTo_GreaterThan_wValueFrom();
void TestSuite_msAPI_Mode_test_GetColorTemperatureScale100Value_wValueTo_LessThan_wValueFrom();
void TestSuite_msAPI_Mode_test_GetColorTemperatureScale100Value_wValueTo_Equal_wValueFrom_u8ScaleValueFromIsZero();
void TestSuite_msAPI_Mode_test_GetColorTemperatureScale100Value_wValueTo_Equal_wValueFrom_u8ScaleValueFromIs100();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_msAPI_Mode);

void TestSuite_msAPI_Mode_setUp()
{
}

void TestSuite_msAPI_Mode_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_GetScale100Value */
/* CPPTEST_TEST_CASE_CONTEXT U8 GetScale100Value(U16, U16, U16) */
void TestSuite_msAPI_Mode_test_GetScale100Value_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wValue) */ 
    U16 _wValue  = 1000u;
    /* Initializing argument 2 (wMinValue) */ 
    U16 _wMinValue  = 0u;
    /* Initializing argument 3 (wMaxValue) */ 
    U16 _wMaxValue  = 100u;
    {
        /* Tested function call */
        U8 _return  = GetScale100Value(_wValue, _wMinValue, _wMaxValue);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(100, _return);
        // CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_GetScale100Value */

/* CPPTEST_TEST_CASE_BEGIN test_GetScale100Value */
/* CPPTEST_TEST_CASE_CONTEXT U8 GetScale100Value(U16, U16, U16) */
void TestSuite_msAPI_Mode_test_GetScale100Value_no()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wValue) */ 
    U16 _wValue  = 10u;
    /* Initializing argument 2 (wMinValue) */ 
    U16 _wMinValue  = 0u;
    /* Initializing argument 3 (wMaxValue) */ 
    U16 _wMaxValue  = 100u;
    {
        /* Tested function call */
        U8 _return  = GetScale100Value(_wValue, _wMinValue, _wMaxValue);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(10, _return);
        // CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_GetScale100Value */

/* CPPTEST_TEST_CASE_BEGIN test_GetScale60Value */
/* CPPTEST_TEST_CASE_CONTEXT U8 GetScale60Value(U16, U16, U16) */
void TestSuite_msAPI_Mode_test_GetScale60Value_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wValue) */ 
    U16 _wValue  = 1000u;
    /* Initializing argument 2 (wMinValue) */ 
    U16 _wMinValue  = 0u;
    /* Initializing argument 3 (wMaxValue) */ 
    U16 _wMaxValue  = 60u;
    {
        /* Tested function call */
        U8 _return  = GetScale60Value(_wValue, _wMinValue, _wMaxValue);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(60, _return);
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_GetScale60Value */

/* CPPTEST_TEST_CASE_BEGIN test_GetScale60Value */
/* CPPTEST_TEST_CASE_CONTEXT U8 GetScale60Value(U16, U16, U16) */
void TestSuite_msAPI_Mode_test_GetScale60Value_no()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wValue) */ 
    U16 _wValue  = 10u;
    /* Initializing argument 2 (wMinValue) */ 
    U16 _wMinValue  = 0u;
    /* Initializing argument 3 (wMaxValue) */ 
    U16 _wMaxValue  = 60u;
    {
        /* Tested function call */
        U8 _return  = GetScale60Value(_wValue, _wMinValue, _wMaxValue);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(10, _return);
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_GetScale60Value */

/* CPPTEST_TEST_CASE_BEGIN test_GetScale64Value */
/* CPPTEST_TEST_CASE_CONTEXT U8 GetScale64Value(U16, U16, U16) */
void TestSuite_msAPI_Mode_test_GetScale64Value_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wValue) */ 
    U16 _wValue  = 1000u;
    /* Initializing argument 2 (wMinValue) */ 
    U16 _wMinValue  = 0u;
    /* Initializing argument 3 (wMaxValue) */ 
    U16 _wMaxValue  = 64u;
    {
        /* Tested function call */
        U8 _return  = GetScale64Value(_wValue, _wMinValue, _wMaxValue);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(64, _return);
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_GetScale64Value */

/* CPPTEST_TEST_CASE_BEGIN test_GetScale64Value */
/* CPPTEST_TEST_CASE_CONTEXT U8 GetScale64Value(U16, U16, U16) */
void TestSuite_msAPI_Mode_test_GetScale64Value_no()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wValue) */ 
    U16 _wValue  = 10u;
    /* Initializing argument 2 (wMinValue) */ 
    U16 _wMinValue  = 0u;
    /* Initializing argument 3 (wMaxValue) */ 
    U16 _wMaxValue  = 64u;
    {
        /* Tested function call */
        U8 _return  = GetScale64Value(_wValue, _wMinValue, _wMaxValue);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(10, _return);
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_GetScale64Value */

/* CPPTEST_TEST_CASE_BEGIN test_N100toReallyValue */
/* CPPTEST_TEST_CASE_CONTEXT U16 N100toReallyValue(U16, U16, U16) */
void TestSuite_msAPI_Mode_test_N100toReallyValue_wValue_is_0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wValue) */ 
    U16 _wValue  = 0u;
    /* Initializing argument 2 (wMinValue) */ 
    U16 _wMinValue  = 0u;
    /* Initializing argument 3 (wMaxValue) */ 
    U16 _wMaxValue  = 0u;
    {
        /* Tested function call */
        U16 _return  = N100toReallyValue(_wValue, _wMinValue, _wMaxValue);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0, _return);
        //CPPTEST_POST_CONDITION_UINTEGER("U16 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N100toReallyValue */

/* CPPTEST_TEST_CASE_BEGIN test_N100toReallyValue */
/* CPPTEST_TEST_CASE_CONTEXT U16 N100toReallyValue(U16, U16, U16) */
void TestSuite_msAPI_Mode_test_N100toReallyValue_need_add_1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wValue) */ 
    U16 _wValue  = 17u;
    /* Initializing argument 2 (wMinValue) */ 
    U16 _wMinValue  = 0u;
    /* Initializing argument 3 (wMaxValue) */ 
    U16 _wMaxValue  = 75u;
    {
        /* Tested function call */
        U16 _return  = N100toReallyValue(_wValue, _wMinValue, _wMaxValue);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(13, _return);
        //CPPTEST_POST_CONDITION_UINTEGER("U16 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N100toReallyValue */

/* CPPTEST_TEST_CASE_BEGIN test_N100toReallyValue */
/* CPPTEST_TEST_CASE_CONTEXT U16 N100toReallyValue(U16, U16, U16) */
void TestSuite_msAPI_Mode_test_N100toReallyValue_neednot_add_1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wValue) */ 
    U16 _wValue  = 12u;
    /* Initializing argument 2 (wMinValue) */ 
    U16 _wMinValue  = 0u;
    /* Initializing argument 3 (wMaxValue) */ 
    U16 _wMaxValue  = 75u;
    {
        /* Tested function call */
        U16 _return  = N100toReallyValue(_wValue, _wMinValue, _wMaxValue);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(9, _return);
        //CPPTEST_POST_CONDITION_UINTEGER("U16 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N100toReallyValue */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Mode_GetPcClockValue */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_Mode_GetPcClockValue(SCALER_WIN, U16) */
extern BOOLEAN bTest_msAPI_Mode_GetPcClockValue_CallGetScale100Value;
void TestSuite_msAPI_Mode_test_msAPI_Mode_GetPcClockValue()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */ 
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    /* Initializing argument 2 (u16Value) */ 
    U16 _u16Value  = 1u;
    {
        /* Tested function call */
        U8 _return  = msAPI_Mode_GetPcClockValue(_eWindow, _u16Value);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, bTest_msAPI_Mode_GetPcClockValue_CallGetScale100Value);
        // CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Mode_GetPcClockValue */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Mode_GetPcPhaseValue */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_Mode_GetPcPhaseValue(U16) */
extern BOOLEAN bTest_msAPI_Mode_GetPcPhaseValue_CallGetScale100Value;
void TestSuite_msAPI_Mode_test_msAPI_Mode_GetPcPhaseValue()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16value) */ 
    U16 _u16value  = 1u;
    {
        /* Tested function call */
        U8 _return  = msAPI_Mode_GetPcPhaseValue(_u16value);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, bTest_msAPI_Mode_GetPcPhaseValue_CallGetScale100Value);
        // CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Mode_GetPcPhaseValue */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CalNonLinearCurve_BackLight */
/* CPPTEST_TEST_CASE_CONTEXT U16 msAPI_CalNonLinearCurve_BackLight(BYTE, T_MS_NONLINEAR_CURVE_16 *) */
void TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_BackLight_AdjustValue_lessthan_Ponit1_but_Y1_Greaterthan_Y0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (AdjustValue) */ 
    BYTE _AdjustValue  = 9;

    /* Initializing argument 2 (stNonLinearCurve) */ 
    T_MS_NONLINEAR_CURVE_16 * _stNonLinearCurve = NULL;
    T_MS_NONLINEAR_CURVE_16 stTest;
    memset(&stTest,0,sizeof(T_MS_NONLINEAR_CURVE_16));
    _stNonLinearCurve = &stTest;

    _stNonLinearCurve->stPoint0.ucY = 10;
    _stNonLinearCurve->stPoint1.ucY = 20;
    _stNonLinearCurve->stPoint0.ucX = 5;
    _stNonLinearCurve->stPoint1.ucX = 10;
    _stNonLinearCurve->stPoint2.ucX = 0;
    {
        /* Tested function call */
        U16 _return  = msAPI_CalNonLinearCurve_BackLight(_AdjustValue, _stNonLinearCurve);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(18, _return);
        //CPPTEST_POST_CONDITION_UINTEGER("U16 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("T_MS_NONLINEAR_CURVE_16 * _stNonLinearCurve ", ( _stNonLinearCurve ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CalNonLinearCurve_BackLight */


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CalNonLinearCurve_BackLight */
/* CPPTEST_TEST_CASE_CONTEXT U16 msAPI_CalNonLinearCurve_BackLight(BYTE, T_MS_NONLINEAR_CURVE_16 *) */
void TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_BackLight_AdjustValue_Lessthan_Ponit1_but_Y1_Lessthan_Y0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (AdjustValue) */ 
    BYTE _AdjustValue  = 6;
    /* Initializing argument 2 (stNonLinearCurve) */ 
    T_MS_NONLINEAR_CURVE_16 * _stNonLinearCurve  = 0 ;
    T_MS_NONLINEAR_CURVE_16 stTest;
    memset(&stTest,0,sizeof(T_MS_NONLINEAR_CURVE_16));
    _stNonLinearCurve = &stTest;

    _stNonLinearCurve->stPoint0.ucY = 20;
    _stNonLinearCurve->stPoint1.ucY = 10;
    _stNonLinearCurve->stPoint0.ucX = 4;
    _stNonLinearCurve->stPoint1.ucX = 8;
    _stNonLinearCurve->stPoint2.ucX = 0;
    {
        /* Tested function call */
        U16 _return  = msAPI_CalNonLinearCurve_BackLight(_AdjustValue, _stNonLinearCurve);
        /* Post-condition check */

        CPPTEST_ASSERT_EQUAL(15, _return);

        //CPPTEST_POST_CONDITION_UINTEGER("U16 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("T_MS_NONLINEAR_CURVE_16 * _stNonLinearCurve ", ( _stNonLinearCurve ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CalNonLinearCurve_BackLight */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CalNonLinearCurve_BackLight */
/* CPPTEST_TEST_CASE_CONTEXT U16 msAPI_CalNonLinearCurve_BackLight(BYTE, T_MS_NONLINEAR_CURVE_16 *) */
void TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_BackLight_AdjustValue_lessthan_Ponit2_but_Y1_Greaterthan_Y0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (AdjustValue) */ 
    BYTE _AdjustValue  = 6;
    /* Initializing argument 2 (stNonLinearCurve) */ 
    T_MS_NONLINEAR_CURVE_16 * _stNonLinearCurve  = 0 ;
    T_MS_NONLINEAR_CURVE_16 stTest;
    memset(&stTest,0,sizeof(T_MS_NONLINEAR_CURVE_16));
    _stNonLinearCurve = &stTest;

    _stNonLinearCurve->stPoint1.ucY = 10;
    _stNonLinearCurve->stPoint2.ucY = 20;
    _stNonLinearCurve->stPoint1.ucX = 4;
    _stNonLinearCurve->stPoint2.ucX = 9;

    {
        /* Tested function call */
        U16 _return  = msAPI_CalNonLinearCurve_BackLight(_AdjustValue, _stNonLinearCurve);
        /* Post-condition check */

        CPPTEST_ASSERT_EQUAL(14, _return);

        //CPPTEST_POST_CONDITION_UINTEGER("U16 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("T_MS_NONLINEAR_CURVE_16 * _stNonLinearCurve ", ( _stNonLinearCurve ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CalNonLinearCurve_BackLight */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CalNonLinearCurve_BackLight */
/* CPPTEST_TEST_CASE_CONTEXT U16 msAPI_CalNonLinearCurve_BackLight(BYTE, T_MS_NONLINEAR_CURVE_16 *) */
void TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_BackLight_AdjustValue_lessthan_Ponit2_but_Y1_Lessthan_Y0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (AdjustValue) */ 
    BYTE _AdjustValue  = 6;
    /* Initializing argument 2 (stNonLinearCurve) */ 
    T_MS_NONLINEAR_CURVE_16 * _stNonLinearCurve  = 0 ;
    T_MS_NONLINEAR_CURVE_16 stTest;
    memset(&stTest,0,sizeof(T_MS_NONLINEAR_CURVE_16));
    _stNonLinearCurve = &stTest;

    _stNonLinearCurve->stPoint1.ucY = 20;
    _stNonLinearCurve->stPoint2.ucY = 10;
    _stNonLinearCurve->stPoint1.ucX = 4;
    _stNonLinearCurve->stPoint2.ucX = 9;

    {
        /* Tested function call */
        U16 _return  = msAPI_CalNonLinearCurve_BackLight(_AdjustValue, _stNonLinearCurve);
        /* Post-condition check */

        CPPTEST_ASSERT_EQUAL(16, _return);

        //CPPTEST_POST_CONDITION_UINTEGER("U16 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("T_MS_NONLINEAR_CURVE_16 * _stNonLinearCurve ", ( _stNonLinearCurve ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CalNonLinearCurve_BackLight */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CalNonLinearCurve_BackLight */
/* CPPTEST_TEST_CASE_CONTEXT U16 msAPI_CalNonLinearCurve_BackLight(BYTE, T_MS_NONLINEAR_CURVE_16 *) */
void TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_BackLight_Other_but_Y1_Greaterthan_Y0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (AdjustValue) */ 
    BYTE _AdjustValue  = 11;
    /* Initializing argument 2 (stNonLinearCurve) */ 
    T_MS_NONLINEAR_CURVE_16 * _stNonLinearCurve  = 0 ;
    T_MS_NONLINEAR_CURVE_16 stTest;
    memset(&stTest,0,sizeof(T_MS_NONLINEAR_CURVE_16));
    _stNonLinearCurve = &stTest;

    _stNonLinearCurve->stPoint2.ucY = 10;
    _stNonLinearCurve->stPoint3.ucY = 20;
    _stNonLinearCurve->stPoint2.ucX = 9;
    _stNonLinearCurve->stPoint3.ucX = 10;
    _stNonLinearCurve->stPoint1.ucX = 4;
    {
        /* Tested function call */
        U16 _return  = msAPI_CalNonLinearCurve_BackLight(_AdjustValue, _stNonLinearCurve);
        /* Post-condition check */

        CPPTEST_ASSERT_EQUAL(30, _return);

        //CPPTEST_POST_CONDITION_UINTEGER("U16 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("T_MS_NONLINEAR_CURVE_16 * _stNonLinearCurve ", ( _stNonLinearCurve ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CalNonLinearCurve_BackLight */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CalNonLinearCurve_BackLight */
/* CPPTEST_TEST_CASE_CONTEXT U16 msAPI_CalNonLinearCurve_BackLight(BYTE, T_MS_NONLINEAR_CURVE_16 *) */
void TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_BackLight_Other_but_Y1_Lessthan_Y0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (AdjustValue) */ 
    BYTE _AdjustValue  = 11;
    /* Initializing argument 2 (stNonLinearCurve) */ 
    T_MS_NONLINEAR_CURVE_16 * _stNonLinearCurve  = 0 ;
    T_MS_NONLINEAR_CURVE_16 stTest;
    memset(&stTest,0,sizeof(T_MS_NONLINEAR_CURVE_16));
    _stNonLinearCurve = &stTest;

    _stNonLinearCurve->stPoint2.ucY = 20;
    _stNonLinearCurve->stPoint3.ucY = 10;
    _stNonLinearCurve->stPoint2.ucX = 9;
    _stNonLinearCurve->stPoint3.ucX = 12;
    _stNonLinearCurve->stPoint1.ucX = 4;
    {
        /* Tested function call */
        U16 _return  = msAPI_CalNonLinearCurve_BackLight(_AdjustValue, _stNonLinearCurve);
        /* Post-condition check */

        CPPTEST_ASSERT_EQUAL(13, _return);

        //CPPTEST_POST_CONDITION_UINTEGER("U16 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("T_MS_NONLINEAR_CURVE_16 * _stNonLinearCurve ", ( _stNonLinearCurve ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CalNonLinearCurve_BackLight */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CalNonLinearCurve */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_CalNonLinearCurve(BYTE, T_MS_NONLINEAR_CURVE *) */
void TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_AdjustValue_lessthan_Ponit1_but_Y1_Greaterthan_Y0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (AdjustValue) */ 
    BYTE _AdjustValue  = 9;

    /* Initializing argument 2 (stNonLinearCurve) */ 
    T_MS_NONLINEAR_CURVE * _stNonLinearCurve = NULL;
    T_MS_NONLINEAR_CURVE stTest;
    memset(&stTest,0,sizeof(T_MS_NONLINEAR_CURVE));
    _stNonLinearCurve = &stTest;

    _stNonLinearCurve->stPoint0.ucY = 10;
    _stNonLinearCurve->stPoint1.ucY = 20;
    _stNonLinearCurve->stPoint0.ucX = 5;
    _stNonLinearCurve->stPoint1.ucX = 10;
    _stNonLinearCurve->stPoint2.ucX = 0;
    {
        /* Tested function call */
        U8 _return  = msAPI_CalNonLinearCurve(_AdjustValue, _stNonLinearCurve);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(18, _return);
        //CPPTEST_POST_CONDITION_UINTEGER("U16 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("T_MS_NONLINEAR_CURVE_16 * _stNonLinearCurve ", ( _stNonLinearCurve ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CalNonLinearCurve */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CalNonLinearCurve */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_CalNonLinearCurve(BYTE, T_MS_NONLINEAR_CURVE *) */
void TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_AdjustValue_Lessthan_Ponit1_but_Y1_Lessthan_Y0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (AdjustValue) */ 
    BYTE _AdjustValue  = 6;
    /* Initializing argument 2 (stNonLinearCurve) */ 
    T_MS_NONLINEAR_CURVE * _stNonLinearCurve  = 0 ;
    T_MS_NONLINEAR_CURVE stTest;
    memset(&stTest,0,sizeof(T_MS_NONLINEAR_CURVE));
    _stNonLinearCurve = &stTest;

    _stNonLinearCurve->stPoint0.ucY = 20;
    _stNonLinearCurve->stPoint1.ucY = 10;
    _stNonLinearCurve->stPoint0.ucX = 4;
    _stNonLinearCurve->stPoint1.ucX = 8;
    _stNonLinearCurve->stPoint2.ucX = 0;
    {
        /* Tested function call */
        U16 _return  = msAPI_CalNonLinearCurve(_AdjustValue, _stNonLinearCurve);
        /* Post-condition check */

        CPPTEST_ASSERT_EQUAL(15, _return);

        //CPPTEST_POST_CONDITION_UINTEGER("U16 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("T_MS_NONLINEAR_CURVE_16 * _stNonLinearCurve ", ( _stNonLinearCurve ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CalNonLinearCurve */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CalNonLinearCurve */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_CalNonLinearCurve(BYTE, T_MS_NONLINEAR_CURVE *) */
void TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_AdjustValue_lessthan_Ponit2_but_Y1_Greaterthan_Y0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (AdjustValue) */ 
    BYTE _AdjustValue  = 6;
    /* Initializing argument 2 (stNonLinearCurve) */ 
    T_MS_NONLINEAR_CURVE * _stNonLinearCurve  = 0 ;
    T_MS_NONLINEAR_CURVE stTest;
    memset(&stTest,0,sizeof(T_MS_NONLINEAR_CURVE));
    _stNonLinearCurve = &stTest;

    _stNonLinearCurve->stPoint1.ucY = 10;
    _stNonLinearCurve->stPoint2.ucY = 20;
    _stNonLinearCurve->stPoint1.ucX = 4;
    _stNonLinearCurve->stPoint2.ucX = 9;

    {
        /* Tested function call */
        U16 _return  = msAPI_CalNonLinearCurve(_AdjustValue, _stNonLinearCurve);
        /* Post-condition check */

        CPPTEST_ASSERT_EQUAL(14, _return);

        //CPPTEST_POST_CONDITION_UINTEGER("U16 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("T_MS_NONLINEAR_CURVE_16 * _stNonLinearCurve ", ( _stNonLinearCurve ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CalNonLinearCurve */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CalNonLinearCurve */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_CalNonLinearCurve(BYTE, T_MS_NONLINEAR_CURVE *) */
void TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_AdjustValue_lessthan_Ponit2_but_Y1_Lessthan_Y0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (AdjustValue) */ 
    BYTE _AdjustValue  = 6;
    /* Initializing argument 2 (stNonLinearCurve) */ 
    T_MS_NONLINEAR_CURVE * _stNonLinearCurve  = 0 ;
    T_MS_NONLINEAR_CURVE stTest;
    memset(&stTest,0,sizeof(T_MS_NONLINEAR_CURVE));
    _stNonLinearCurve = &stTest;

    _stNonLinearCurve->stPoint1.ucY = 20;
    _stNonLinearCurve->stPoint2.ucY = 10;
    _stNonLinearCurve->stPoint1.ucX = 4;
    _stNonLinearCurve->stPoint2.ucX = 9;

    {
        /* Tested function call */
        U16 _return  = msAPI_CalNonLinearCurve(_AdjustValue, _stNonLinearCurve);
        /* Post-condition check */

        CPPTEST_ASSERT_EQUAL(16, _return);

        //CPPTEST_POST_CONDITION_UINTEGER("U16 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("T_MS_NONLINEAR_CURVE_16 * _stNonLinearCurve ", ( _stNonLinearCurve ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CalNonLinearCurve */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CalNonLinearCurve */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_CalNonLinearCurve(BYTE, T_MS_NONLINEAR_CURVE *) */
void TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_Other_but_Y1_Greaterthan_Y0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (AdjustValue) */ 
    BYTE _AdjustValue  = 11;
    /* Initializing argument 2 (stNonLinearCurve) */ 
    T_MS_NONLINEAR_CURVE * _stNonLinearCurve  = 0 ;
    T_MS_NONLINEAR_CURVE stTest;
    memset(&stTest,0,sizeof(T_MS_NONLINEAR_CURVE));
    _stNonLinearCurve = &stTest;

    _stNonLinearCurve->stPoint2.ucY = 10;
    _stNonLinearCurve->stPoint3.ucY = 20;
    _stNonLinearCurve->stPoint2.ucX = 9;
    _stNonLinearCurve->stPoint3.ucX = 10;
    _stNonLinearCurve->stPoint1.ucX = 4;
    {
        /* Tested function call */
        U16 _return  = msAPI_CalNonLinearCurve(_AdjustValue, _stNonLinearCurve);
        /* Post-condition check */

        CPPTEST_ASSERT_EQUAL(30, _return);

        //CPPTEST_POST_CONDITION_UINTEGER("U16 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("T_MS_NONLINEAR_CURVE_16 * _stNonLinearCurve ", ( _stNonLinearCurve ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CalNonLinearCurve */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CalNonLinearCurve */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_CalNonLinearCurve(BYTE, T_MS_NONLINEAR_CURVE *) */
void TestSuite_msAPI_Mode_test_msAPI_CalNonLinearCurve_Other_but_Y1_Lessthan_Y0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (AdjustValue) */ 
    BYTE _AdjustValue  = 11;
    /* Initializing argument 2 (stNonLinearCurve) */ 
    T_MS_NONLINEAR_CURVE * _stNonLinearCurve  = 0 ;
    T_MS_NONLINEAR_CURVE stTest;
    memset(&stTest,0,sizeof(T_MS_NONLINEAR_CURVE));
    _stNonLinearCurve = &stTest;

    _stNonLinearCurve->stPoint2.ucY = 20;
    _stNonLinearCurve->stPoint3.ucY = 10;
    _stNonLinearCurve->stPoint2.ucX = 9;
    _stNonLinearCurve->stPoint3.ucX = 12;
    _stNonLinearCurve->stPoint1.ucX = 4;
    {
        /* Tested function call */
        U8 _return  = msAPI_CalNonLinearCurve(_AdjustValue, _stNonLinearCurve);
        /* Post-condition check */

        CPPTEST_ASSERT_EQUAL(13, _return);

        //CPPTEST_POST_CONDITION_UINTEGER("U16 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("T_MS_NONLINEAR_CURVE_16 * _stNonLinearCurve ", ( _stNonLinearCurve ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CalNonLinearCurve */

/* CPPTEST_TEST_CASE_BEGIN test_GetColorTemperatureScale100Value */
/* CPPTEST_TEST_CASE_CONTEXT U8 GetColorTemperatureScale100Value(U16, U16, U16, U16, U8, BOOLEAN *) */
extern BOOLEAN bTest_GetColorTemperatureScale100Value_CallGetScale100Value_From;
extern BOOLEAN bTest_GetColorTemperatureScale100Value_CallGetScale100Value_To;
void TestSuite_msAPI_Mode_test_GetColorTemperatureScale100Value_wValueTo_GreaterThan_wValueFrom()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wValueFrom) */ 
    U16 _wValueFrom  = 10u;
    /* Initializing argument 2 (wValueTo) */ 
    U16 _wValueTo  = 20u;
    /* Initializing argument 3 (wMinValue) */ 
    U16 _wMinValue  = 0u;
    /* Initializing argument 4 (wMaxValue) */ 
    U16 _wMaxValue  = 100u;
    /* Initializing argument 5 (wOrgScaleValue) */ 
    U8 _wOrgScaleValue  = 5;
    /* Initializing argument 6 (bIsNeed2ResetValue) */ 
    BOOLEAN bTest = FALSE;
    BOOLEAN * _bIsNeed2ResetValue  = NULL;
    _bIsNeed2ResetValue  = &bTest ;
    {
        /* Tested function call */
        U8 _return  = GetColorTemperatureScale100Value(_wValueFrom, _wValueTo, _wMinValue, _wMaxValue, _wOrgScaleValue, _bIsNeed2ResetValue);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, bTest_GetColorTemperatureScale100Value_CallGetScale100Value_From);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, bTest_GetColorTemperatureScale100Value_CallGetScale100Value_To);
        CPPTEST_ASSERT_EQUAL(6,_return);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, bTest);
        // CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        // CPPTEST_POST_CONDITION_PTR("BOOLEAN * _bIsNeed2ResetValue ", ( _bIsNeed2ResetValue ));
    }
}
/* CPPTEST_TEST_CASE_END test_GetColorTemperatureScale100Value */

/* CPPTEST_TEST_CASE_BEGIN test_GetColorTemperatureScale100Value */
/* CPPTEST_TEST_CASE_CONTEXT U8 GetColorTemperatureScale100Value(U16, U16, U16, U16, U8, BOOLEAN *) */
void TestSuite_msAPI_Mode_test_GetColorTemperatureScale100Value_wValueTo_LessThan_wValueFrom()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wValueFrom) */ 
    U16 _wValueFrom  = 20u;
    /* Initializing argument 2 (wValueTo) */ 
    U16 _wValueTo  = 10u;
    /* Initializing argument 3 (wMinValue) */ 
    U16 _wMinValue  = 0u;
    /* Initializing argument 4 (wMaxValue) */ 
    U16 _wMaxValue  = 100u;
    /* Initializing argument 5 (wOrgScaleValue) */ 
    U8 _wOrgScaleValue  = 5;
    /* Initializing argument 6 (bIsNeed2ResetValue) */ 
    BOOLEAN bTest = FALSE;
    BOOLEAN * _bIsNeed2ResetValue  = NULL;
    _bIsNeed2ResetValue  = &bTest ;
    {
        /* Tested function call */
        U8 _return  = GetColorTemperatureScale100Value(_wValueFrom, _wValueTo, _wMinValue, _wMaxValue, _wOrgScaleValue, _bIsNeed2ResetValue);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, bTest_GetColorTemperatureScale100Value_CallGetScale100Value_From);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, bTest_GetColorTemperatureScale100Value_CallGetScale100Value_To);
        CPPTEST_ASSERT_EQUAL(4,_return);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, bTest);
        // CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        // CPPTEST_POST_CONDITION_PTR("BOOLEAN * _bIsNeed2ResetValue ", ( _bIsNeed2ResetValue ));
    }
}
/* CPPTEST_TEST_CASE_END test_GetColorTemperatureScale100Value */

/* CPPTEST_TEST_CASE_BEGIN test_GetColorTemperatureScale100Value */
/* CPPTEST_TEST_CASE_CONTEXT U8 GetColorTemperatureScale100Value(U16, U16, U16, U16, U8, BOOLEAN *) */
void TestSuite_msAPI_Mode_test_GetColorTemperatureScale100Value_wValueTo_Equal_wValueFrom_u8ScaleValueFromIsZero()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wValueFrom) */ 
    U16 _wValueFrom  = 0u;
    /* Initializing argument 2 (wValueTo) */ 
    U16 _wValueTo  = 0u;
    /* Initializing argument 3 (wMinValue) */ 
    U16 _wMinValue  = 0u;
    /* Initializing argument 4 (wMaxValue) */ 
    U16 _wMaxValue  = 100u;
    /* Initializing argument 5 (wOrgScaleValue) */ 
    U8 _wOrgScaleValue  = 5;
    /* Initializing argument 6 (bIsNeed2ResetValue) */ 
    BOOLEAN bTest = FALSE;
    BOOLEAN * _bIsNeed2ResetValue  = NULL;
    _bIsNeed2ResetValue  = &bTest ;
    {
        /* Tested function call */
        U8 _return  = GetColorTemperatureScale100Value(_wValueFrom, _wValueTo, _wMinValue, _wMaxValue, _wOrgScaleValue, _bIsNeed2ResetValue);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, bTest_GetColorTemperatureScale100Value_CallGetScale100Value_From);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, bTest_GetColorTemperatureScale100Value_CallGetScale100Value_To);
        CPPTEST_ASSERT_EQUAL(4,_return);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, bTest);
        // CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        // CPPTEST_POST_CONDITION_PTR("BOOLEAN * _bIsNeed2ResetValue ", ( _bIsNeed2ResetValue ));
    }
}
/* CPPTEST_TEST_CASE_END test_GetColorTemperatureScale100Value */

/* CPPTEST_TEST_CASE_BEGIN test_GetColorTemperatureScale100Value */
/* CPPTEST_TEST_CASE_CONTEXT U8 GetColorTemperatureScale100Value(U16, U16, U16, U16, U8, BOOLEAN *) */
void TestSuite_msAPI_Mode_test_GetColorTemperatureScale100Value_wValueTo_Equal_wValueFrom_u8ScaleValueFromIs100()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wValueFrom) */ 
    U16 _wValueFrom  = 100u;
    /* Initializing argument 2 (wValueTo) */ 
    U16 _wValueTo  = 100u;
    /* Initializing argument 3 (wMinValue) */ 
    U16 _wMinValue  = 0u;
    /* Initializing argument 4 (wMaxValue) */ 
    U16 _wMaxValue  = 100u;
    /* Initializing argument 5 (wOrgScaleValue) */ 
    U8 _wOrgScaleValue  = 5;
    /* Initializing argument 6 (bIsNeed2ResetValue) */ 
    BOOLEAN bTest = FALSE;
    BOOLEAN * _bIsNeed2ResetValue  = NULL;
    _bIsNeed2ResetValue  = &bTest ;
    {
        /* Tested function call */
        U8 _return  = GetColorTemperatureScale100Value(_wValueFrom, _wValueTo, _wMinValue, _wMaxValue, _wOrgScaleValue, _bIsNeed2ResetValue);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, bTest_GetColorTemperatureScale100Value_CallGetScale100Value_From);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, bTest_GetColorTemperatureScale100Value_CallGetScale100Value_To);
        CPPTEST_ASSERT_EQUAL(6,_return);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, bTest);
        // CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        // CPPTEST_POST_CONDITION_PTR("BOOLEAN * _bIsNeed2ResetValue ", ( _bIsNeed2ResetValue ));
    }
}
/* CPPTEST_TEST_CASE_END test_GetColorTemperatureScale100Value */
