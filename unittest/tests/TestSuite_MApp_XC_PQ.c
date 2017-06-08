#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app/MApp_XC_PQ.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app/MApp_XC_PQ.c");

CPPTEST_TEST_SUITE(TestSuite_MApp_XC_PQ);
CPPTEST_TEST(TestSuite_MApp_XC_PQ_test_MApp_Picture_ColorCtrl_CheckColorRange);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_MApp_XC_PQ_test_MApp_Picture_ColorCtrl_CheckColorRange();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_MApp_XC_PQ);

void TestSuite_MApp_XC_PQ_setUp()
{
}

void TestSuite_MApp_XC_PQ_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_Picture_ColorCtrl_CheckColorRange */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Picture_ColorCtrl(INPUT_SOURCE_TYPE_t, SCALER_WIN) */
void TestSuite_MApp_XC_PQ_test_MApp_Picture_ColorCtrl_CheckColorRange()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enInputSourceType) */ 
    INPUT_SOURCE_TYPE_t _enInputSourceType  = INPUT_SOURCE_DVI;
    /* Initializing argument 2 (eWindow) */ 
    SCALER_WIN _eWindow  = MAIN_WINDOW;

    /* Initializing global variable stGenSetting */ 
    stGenSetting.g_stPipSetting.bPipEnable = 0;

    { // HDMI - 16~235
    	_enInputSourceType  = INPUT_SOURCE_HDMI;
        /* Tested function call */
        MApp_Picture_ColorCtrl(_enInputSourceType, _eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_COLOR_RANGE_16_235, ( stGenSetting.g_SysSetting.enAUTOCOLORRANGE ) )
    }

    { // DVI
    	_enInputSourceType  = INPUT_SOURCE_DVI;
        /* Tested function call */
        MApp_Picture_ColorCtrl(_enInputSourceType, _eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_COLOR_RANGE_0_255, ( stGenSetting.g_SysSetting.enAUTOCOLORRANGE ) )
    }

}
/* CPPTEST_TEST_CASE_END test_MApp_Picture_ColorCtrl_CheckColorRange */
