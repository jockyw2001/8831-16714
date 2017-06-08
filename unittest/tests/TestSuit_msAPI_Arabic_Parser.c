#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/Arabic_Parser/msAPI_Arabic_Parser.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/Arabic_Parser/msAPI_Arabic_Parser.c");

CPPTEST_TEST_SUITE(TestSuit_msAPI_Arabic_Parser);
CPPTEST_TEST(TestSuit_msAPI_Arabic_Parser_test_isTashkeelChar_true);
CPPTEST_TEST(TestSuit_msAPI_Arabic_Parser_test_isTashkeelChar_false);
CPPTEST_TEST(TestSuit_msAPI_Arabic_Parser_test_isTashkeelChar_MaxBoundary);
CPPTEST_TEST(TestSuit_msAPI_Arabic_Parser_test_isTashkeelChar_MinBoundary);
CPPTEST_TEST(TestSuit_msAPI_Arabic_Parser_test_isTashkeelChar_zero);
CPPTEST_TEST_SUITE_END();
        

void TestSuit_msAPI_Arabic_Parser_test_isTashkeelChar_true();
void TestSuit_msAPI_Arabic_Parser_test_isTashkeelChar_false();
void TestSuit_msAPI_Arabic_Parser_test_isTashkeelChar_MaxBoundary();
void TestSuit_msAPI_Arabic_Parser_test_isTashkeelChar_MinBoundary();
void TestSuit_msAPI_Arabic_Parser_test_isTashkeelChar_zero();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuit_msAPI_Arabic_Parser);

void TestSuit_msAPI_Arabic_Parser_setUp()
{
}

void TestSuit_msAPI_Arabic_Parser_tearDown()
{
}



/* CPPTEST_TEST_CASE_BEGIN test_isTashkeelChar_true */
/* CPPTEST_TEST_CASE_CONTEXT S32 isTashkeelChar(U16) */
void TestSuit_msAPI_Arabic_Parser_test_isTashkeelChar_true()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ch) */ 
    U16 _ch  = 0x0650u;
    {
        /* Tested function call */
        S32 _return  = isTashkeelChar(_ch);
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(1, (_return));
    }
}
/* CPPTEST_TEST_CASE_END test_isTashkeelChar_true */

/* CPPTEST_TEST_CASE_BEGIN test_isTashkeelChar_false */
/* CPPTEST_TEST_CASE_CONTEXT S32 isTashkeelChar(U16) */
void TestSuit_msAPI_Arabic_Parser_test_isTashkeelChar_false()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ch) */ 
    U16 _ch  = 0x0700;
    {
        /* Tested function call */
        S32 _return  = isTashkeelChar(_ch);
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(0, (_return));
    }
}
/* CPPTEST_TEST_CASE_END test_isTashkeelChar_false */

/* CPPTEST_TEST_CASE_BEGIN test_isTashkeelChar_MaxBoundary */
/* CPPTEST_TEST_CASE_CONTEXT S32 isTashkeelChar(U16) */
void TestSuit_msAPI_Arabic_Parser_test_isTashkeelChar_MaxBoundary()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ch) */ 
    U16 _ch  = 0x0652u;
    {
        /* Tested function call */
        S32 _return  = isTashkeelChar(_ch);
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(1, (_return));
    }
}
/* CPPTEST_TEST_CASE_END test_isTashkeelChar_MaxBoundary */

/* CPPTEST_TEST_CASE_BEGIN test_isTashkeelChar_MinBoundary */
/* CPPTEST_TEST_CASE_CONTEXT S32 isTashkeelChar(U16) */
void TestSuit_msAPI_Arabic_Parser_test_isTashkeelChar_MinBoundary()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ch) */ 
    U16 _ch  = 0x064Bu;
    {
        /* Tested function call */
        S32 _return  = isTashkeelChar(_ch);
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(1, (_return));
    }
}
/* CPPTEST_TEST_CASE_END test_isTashkeelChar_MinBoundary */

/* CPPTEST_TEST_CASE_BEGIN test_isTashkeelChar_zero */
/* CPPTEST_TEST_CASE_CONTEXT S32 isTashkeelChar(U16) */
void TestSuit_msAPI_Arabic_Parser_test_isTashkeelChar_zero()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ch) */ 
    U16 _ch  = 0u;
    {
        /* Tested function call */
        S32 _return  = isTashkeelChar(_ch);
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(0, (_return));
    }
}
/* CPPTEST_TEST_CASE_END test_isTashkeelChar_zero */
