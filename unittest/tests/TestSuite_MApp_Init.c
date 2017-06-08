#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app/MApp_Init.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app/MApp_Init.c");

CPPTEST_TEST_SUITE(TestSuite_MApp_Init);
CPPTEST_TEST(TestSuite_MApp_Init_test_MApp_Init_FlashVariable);
CPPTEST_TEST_SUITE_END();


void TestSuite_MApp_Init_test_MApp_Init_FlashVariable();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_MApp_Init);

void TestSuite_MApp_Init_setUp()
{
}

void TestSuite_MApp_Init_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_Init_FlashVariable */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Init_FlashVariable(void) */
void TestSuite_MApp_Init_test_MApp_Init_FlashVariable()
{
    /* Pre-condition initialization */
    {
    }
    /* Initializing global variable g_bOpenGenstStoreDBG */
    {
         g_bOpenGenstStoreDBG  = 0;
    }
    /* Initializing global variable g_MEMCOPYTYPE */
    {
         g_MEMCOPYTYPE  = MIU_FLASH2SDRAM;
    }
    {
        /* Tested function call */
        MApp_Init_FlashVariable();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 0, ( g_bOpenGenstStoreDBG ) );
        CPPTEST_ASSERT_EQUAL( MIU_FLASH2SDRAM, ( g_MEMCOPYTYPE ) );

        //CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( RM_GEN_USAGE < QUICK_DB_GENST_SIZE ));
        //CPPTEST_ASSERT_BOOL_EQUAL(0, ( RM_GEN_USAGE < QUICK_DB_GENST_SIZE ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Init_FlashVariable */
