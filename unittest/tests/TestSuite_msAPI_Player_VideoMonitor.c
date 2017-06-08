#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/msAPI_Player.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/msAPI_Player.c");

CPPTEST_TEST_SUITE(TestSuite_msAPI_Player_VideoMonitor);
CPPTEST_TEST(TestSuite_msAPI_Player_VideoMonitor_test_msAPI_Player_VideoMonitor_bReCalculate_TRUE);
CPPTEST_TEST(TestSuite_msAPI_Player_VideoMonitor_test_msAPI_Player_VideoMonitor_bReCalculate_FALSE_m_u32GOPTimes500);
CPPTEST_TEST(TestSuite_msAPI_Player_VideoMonitor_test_msAPI_Player_VideoMonitor_bReCalculate_FALSE_m_u32GOPTimes1000);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_msAPI_Player_VideoMonitor_test_msAPI_Player_VideoMonitor_bReCalculate_TRUE();
void TestSuite_msAPI_Player_VideoMonitor_test_msAPI_Player_VideoMonitor_bReCalculate_FALSE_m_u32GOPTimes500();
void TestSuite_msAPI_Player_VideoMonitor_test_msAPI_Player_VideoMonitor_bReCalculate_FALSE_m_u32GOPTimes1000();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_msAPI_Player_VideoMonitor);

void TestSuite_msAPI_Player_VideoMonitor_setUp()
{
}

void TestSuite_msAPI_Player_VideoMonitor_tearDown()
{
}



/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Player_VideoMonitor_bReCalculate_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_Player_VideoMonitor(BOOLEAN) */
void TestSuite_msAPI_Player_VideoMonitor_test_msAPI_Player_VideoMonitor_bReCalculate_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bReCalculate) */ 
    U8 _bReCalculate  = TRUE;
    /* Initializing global variable m_u32GOPTimes */ 
    {
         m_u32GOPTimes  = 0;
    }
    /* Initializing global variable m_u32GOPtotal */ 
    {
         m_u32GOPtotal  = 0;
    }
    /* Initializing global variable m_u32GOPSize */ 
    {
         m_u32GOPSize  = 0;
    }
    {
        /* Tested function call */
        msAPI_Player_VideoMonitor(_bReCalculate);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( m_u32GOPTimes ));
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( m_u32GOPtotal ));
        CPPTEST_ASSERT_UINTEGER_EQUAL(16, ( m_u32GOPSize ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Player_VideoMonitor_bReCalculate_TRUE */


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Player_VideoMonitor_bReCalculate_FALSE_m_u32GOPTimes500 */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_Player_VideoMonitor(BOOLEAN) */
void TestSuite_msAPI_Player_VideoMonitor_test_msAPI_Player_VideoMonitor_bReCalculate_FALSE_m_u32GOPTimes500()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bReCalculate) */ 
    U8 _bReCalculate  = FALSE;
    /* Initializing global variable m_u32GOPTimes */ 
    {
         m_u32GOPTimes  = 500;
    }
    /* Initializing global variable m_u32GOPtotal */ 
    {
         m_u32GOPtotal  = 0;
    }
    /* Initializing global variable m_u32GOPSize */ 
    {
         m_u32GOPSize  = 0;
    }
    {
        /* Tested function call */
        msAPI_Player_VideoMonitor(_bReCalculate);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(500, ( m_u32GOPTimes ));
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( m_u32GOPtotal ));
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( m_u32GOPSize ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Player_VideoMonitor_bReCalculate_FALSE_m_u32GOPTimes500 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Player_VideoMonitor_bReCalculate_FALSE_m_u32GOPTimes1000 */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_Player_VideoMonitor(BOOLEAN) */
void TestSuite_msAPI_Player_VideoMonitor_test_msAPI_Player_VideoMonitor_bReCalculate_FALSE_m_u32GOPTimes1000()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bReCalculate) */ 
    U8 _bReCalculate  = FALSE;
    /* Initializing global variable m_u32GOPTimes */ 
    {
         m_u32GOPTimes  = 1000;
    }
    /* Initializing global variable m_u32GOPtotal */ 
    {
         m_u32GOPtotal  = 0;
    }
    /* Initializing global variable m_u32GOPSize */ 
    {
         m_u32GOPSize  = 0;
    }
    {
        /* Tested function call */
        msAPI_Player_VideoMonitor(_bReCalculate);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1000, ( m_u32GOPTimes ));
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( m_u32GOPtotal ));
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( m_u32GOPSize ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Player_VideoMonitor_bReCalculate_FALSE_m_u32GOPTimes1000 */
