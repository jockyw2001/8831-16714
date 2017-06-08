#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/multimedia/mapp_txt.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/multimedia/mapp_txt.c");

CPPTEST_TEST_SUITE(TestSuite_mapp_txt);
CPPTEST_TEST(TestSuite_mapp_txt_test_IsNormalASCChar_case1);
CPPTEST_TEST_SUITE_END();


void TestSuite_mapp_txt_test_IsNormalASCChar_case1();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_mapp_txt);

void TestSuite_mapp_txt_setUp()
{
}

void TestSuite_mapp_txt_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_IsNormalASCChar_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsNormalASCChar(char) */
void TestSuite_mapp_txt_test_IsNormalASCChar_case1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (chWord) */
    char _chWord  = 'a';
    BOOLEAN _return;
    {
        /* Tested function call */
        _return  = IsNormalASCChar(_chWord);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }

    _chWord  = '1';
    {
        /* Tested function call */
        _return  = IsNormalASCChar(_chWord);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }

    _chWord  = 'A';
    {
        /* Tested function call */
        _return  = IsNormalASCChar(_chWord);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }

    _chWord  = 'Z';
    {
        /* Tested function call */
        _return  = IsNormalASCChar(_chWord);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }

    _chWord  = 'z';
    {
        /* Tested function call */
        _return  = IsNormalASCChar(_chWord);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_IsNormalASCChar_case1 */
