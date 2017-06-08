#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/scaler_front/apiXC_Cus.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/scaler_front/apiXC_Cus.c");

CPPTEST_TEST_SUITE(TestSuite_apiXC_Cus);
CPPTEST_TEST(TestSuite_apiXC_Cus_test_mvideo_sc_is_interlace_Dtv_True);
CPPTEST_TEST(TestSuite_apiXC_Cus_test_MApi_XC_GetTotalModeCount__);
CPPTEST_TEST(TestSuite_apiXC_Cus_test_MApi_XC_GetVerticalFrequency__);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_apiXC_Cus_test_mvideo_sc_is_interlace_Dtv_True();
void TestSuite_apiXC_Cus_test_MApi_XC_GetTotalModeCount__();
void TestSuite_apiXC_Cus_test_MApi_XC_GetVerticalFrequency__();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_apiXC_Cus);

void TestSuite_apiXC_Cus_setUp()
{
}

void TestSuite_apiXC_Cus_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_mvideo_sc_is_interlace_Dtv_True */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN mvideo_sc_is_interlace(void) */
void TestSuite_apiXC_Cus_test_mvideo_sc_is_interlace_Dtv_True()
{
    /* Pre-condition initialization */

    { // dtv
    	SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW) = INPUT_SOURCE_DTV;
        /* Tested function call */
        BOOLEAN _return  = mvideo_sc_is_interlace();
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }
    { // mm
    	SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW) = INPUT_SOURCE_STORAGE;
        /* Tested function call */
        BOOLEAN _return  = mvideo_sc_is_interlace();
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }
    { // ATV
     	SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW) = INPUT_SOURCE_TV;
         /* Tested function call */
         BOOLEAN _return  = mvideo_sc_is_interlace();
         /* Post-condition check */
         CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
     }
    { // VD
     	SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW) = INPUT_SOURCE_CVBS;
         /* Tested function call */
         BOOLEAN _return  = mvideo_sc_is_interlace();
         /* Post-condition check */
         CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
     }

    { // PC
     	SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW) = INPUT_SOURCE_VGA;
         /* Tested function call */
         BOOLEAN _return  = mvideo_sc_is_interlace();
         /* Post-condition check */
         CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
     }

}
/* CPPTEST_TEST_CASE_END test_mvideo_sc_is_interlace_Dtv_True */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_GetTotalModeCount__ */
/* CPPTEST_TEST_CASE_CONTEXT MS_U8 MApi_XC_GetTotalModeCount(void) */
void TestSuite_apiXC_Cus_test_MApi_XC_GetTotalModeCount__()
{
    /* Pre-condition initialization */

    { // Check astStandardModeTable[] array size == MD_STD_MODE_MAX_INDEX
        /* Tested function call */
        MS_U8 _return  = MApi_XC_GetTotalModeCount();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( (MD_STD_MODE_MAX_INDEX), ( _return ));
        CPPTEST_ASSERT_EQUAL( (sizeof(astStandardModeTable)/sizeof(MS_PCADC_MODETABLE_TYPE_EX)), ( _return ));

        // Check u16DefaultAdcPhase[] array size == MD_STD_MODE_MAX_INDEX
        CPPTEST_ASSERT_EQUAL( (sizeof(u16DefaultAdcPhase)/sizeof(MS_U16)), ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_GetTotalModeCount__ */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_GetVerticalFrequency__ */
/* CPPTEST_TEST_CASE_CONTEXT MS_U16 MApi_XC_GetVerticalFrequency(MS_U8) */
void TestSuite_apiXC_Cus_test_MApi_XC_GetVerticalFrequency__()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8ModeIdx) */ 
    MS_U8 _u8ModeIdx  = 0;
    {
    	_u8ModeIdx  = MD_1920x1080_60P;
        /* Tested function call */
        MS_U16 _return  = MApi_XC_GetVerticalFrequency(_u8ModeIdx);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(600, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_GetVerticalFrequency__ */
