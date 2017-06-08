#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/mms/drvMmsDisp.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/mms/drvMmsDisp.c");

CPPTEST_TEST_SUITE(TestSuit_drvMmsDisp);
CPPTEST_TEST(TestSuit_drvMmsDisp_test_MMS_Help);
CPPTEST_TEST(TestSuit_drvMmsDisp_test_MDrv_LogoPrint);
CPPTEST_TEST(TestSuit_drvMmsDisp_test_MDrv_MainPagePrint);
CPPTEST_TEST_SUITE_END();
        

void TestSuit_drvMmsDisp_test_MMS_Help();
void TestSuit_drvMmsDisp_test_MDrv_LogoPrint();
void TestSuit_drvMmsDisp_test_MDrv_MainPagePrint();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuit_drvMmsDisp);

void TestSuit_drvMmsDisp_setUp()
{
}

void TestSuit_drvMmsDisp_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MMS_Help */
/* CPPTEST_TEST_CASE_CONTEXT void MMS_Help(void) */
void TestSuit_drvMmsDisp_test_MMS_Help()
{
    /* Pre-condition initialization */
    {
#if(ENABLE_MMS)
        /* Tested function call */
        MMS_Help();
        /* Post-condition check */
#endif
    }
}
/* CPPTEST_TEST_CASE_END test_MMS_Help */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_LogoPrint */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_LogoPrint(void) */
void TestSuit_drvMmsDisp_test_MDrv_LogoPrint()
{
    /* Pre-condition initialization */
    {
#if(ENABLE_MMS)
        /* Tested function call */
        MDrv_LogoPrint();
        /* Post-condition check */
#endif
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_LogoPrint */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_MainPagePrint */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_MainPagePrint(void) */
void TestSuit_drvMmsDisp_test_MDrv_MainPagePrint()
{
    /* Pre-condition initialization */
    {
#if(ENABLE_MMS)
        /* Tested function call */
        MDrv_MainPagePrint();
        /* Post-condition check */
#endif
    }
}

/* CPPTEST_TEST_CASE_END test_MDrv_MainPagePrint */
