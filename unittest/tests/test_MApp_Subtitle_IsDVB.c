#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app1/MApp_Subtitle.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app1/MApp_Subtitle.c");

CPPTEST_TEST_SUITE(test_MApp_Subtitle_IsDVB);

CPPTEST_TEST_DS(test_MApp_Subtitle_IsDVB_test_MApp_Subtitle_IsDVB_u8type_IF_lager_SUBTITLING_TYPE_NORMAL_NO, CPPTEST_DS("test_MApp_Subtitle_IsDVB_u8type_IF_lager_SUBTITLING_TYPE_NORMAL_NO"));
CPPTEST_TEST(test_MApp_Subtitle_IsDVB_test_MApp_Subtitle_IsDVB_IF_equal_SUBTITLING_TYPE_NORMAL_NO);
CPPTEST_TEST(test_MApp_Subtitle_IsDVB_test_MApp_Subtitle_IsDVB_IF_smaller_SUBTITLING_TYPE_NORMAL_NO);
CPPTEST_TEST_SUITE_END();
        

void test_MApp_Subtitle_IsDVB_test_MApp_Subtitle_IsDVB_u8type_IF_lager_SUBTITLING_TYPE_NORMAL_NO();
void test_MApp_Subtitle_IsDVB_test_MApp_Subtitle_IsDVB_IF_equal_SUBTITLING_TYPE_NORMAL_NO();
void test_MApp_Subtitle_IsDVB_test_MApp_Subtitle_IsDVB_IF_smaller_SUBTITLING_TYPE_NORMAL_NO();
CPPTEST_TEST_SUITE_REGISTRATION(test_MApp_Subtitle_IsDVB);

void test_MApp_Subtitle_IsDVB_setUp()
{
}

void test_MApp_Subtitle_IsDVB_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_Subtitle_IsDVB_u8type_IF_lager_SUBTITLING_TYPE_NORMAL_NO */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Subtitle_IsDVB(SUBTITLING_TYPE) */
void test_MApp_Subtitle_IsDVB_test_MApp_Subtitle_IsDVB_u8type_IF_lager_SUBTITLING_TYPE_NORMAL_NO()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8type) */ 
    SUBTITLING_TYPE _u8type  = SUBTITLING_TYPE_NORMAL_NO+1;
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_Subtitle_IsDVB(_u8type);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(CPPTEST_DS_GET_UINTEGER("[OUT]._return"), ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Subtitle_IsDVB_u8type_IF_lager_SUBTITLING_TYPE_NORMAL_NO */



/* CPPTEST_TEST_CASE_BEGIN test_MApp_Subtitle_IsDVB_IF_equal_SUBTITLING_TYPE_NORMAL_NO */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Subtitle_IsDVB(SUBTITLING_TYPE) */
void test_MApp_Subtitle_IsDVB_test_MApp_Subtitle_IsDVB_IF_equal_SUBTITLING_TYPE_NORMAL_NO()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8type) */ 
    SUBTITLING_TYPE _u8type  = SUBTITLING_TYPE_NORMAL_NO;
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_Subtitle_IsDVB(_u8type);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Subtitle_IsDVB_IF_equal_SUBTITLING_TYPE_NORMAL_NO */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Subtitle_IsDVB_IF_smaller_SUBTITLING_TYPE_NORMAL_NO */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Subtitle_IsDVB(SUBTITLING_TYPE) */
void test_MApp_Subtitle_IsDVB_test_MApp_Subtitle_IsDVB_IF_smaller_SUBTITLING_TYPE_NORMAL_NO()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8type) */ 
    SUBTITLING_TYPE _u8type  = SUBTITLING_TYPE_NORMAL_NO-1;
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_Subtitle_IsDVB(_u8type);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Subtitle_IsDVB_IF_smaller_SUBTITLING_TYPE_NORMAL_NO */
