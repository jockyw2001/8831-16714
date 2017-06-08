#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/msAPI_Flash.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/msAPI_Flash.c");

CPPTEST_TEST_SUITE(msAPI_Flash_Test);
CPPTEST_TEST(msAPI_Flash_Test_test_MApp_Printf_Flash_Variable);
CPPTEST_TEST_SUITE_END();


void msAPI_Flash_Test_test_MApp_Printf_Flash_Variable();
CPPTEST_TEST_SUITE_REGISTRATION(msAPI_Flash_Test);

void msAPI_Flash_Test_setUp()
{
}

void msAPI_Flash_Test_tearDown()
{
}
/* CPPTEST_TEST_CASE_END test_msAPI_Flash_CheckFlash_QuickGenSettingIdxEQU_QUICK_DB_GENST_INVALID_IDX */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Printf_Flash_Variable */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Printf_Flash_Variable(void) */
void msAPI_Flash_Test_test_MApp_Printf_Flash_Variable()
{
    /* Pre-condition initialization */
    {
    }
    /* Initializing global variable g_MEMCOPYTYPE */
    {
         g_MEMCOPYTYPE  = MIU_FLASH2SDRAM;
    }
    /* Initializing global variable g_bOpenGenstStoreDBG */
    {
         g_bOpenGenstStoreDBG  = 0;
    }
    {
        /* Tested function call */
        MApp_Printf_Flash_Variable();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MIU_FLASH2SDRAM, ( g_MEMCOPYTYPE ) )
        CPPTEST_POST_CONDITION_UINTEGER("U8 g_bOpenGenstStoreDBG", ( g_bOpenGenstStoreDBG ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Printf_Flash_Variable */



