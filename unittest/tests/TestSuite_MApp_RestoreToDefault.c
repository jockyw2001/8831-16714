#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app/MApp_RestoreToDefault.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app/MApp_RestoreToDefault.c");

CPPTEST_TEST_SUITE(TestSuite_MApp_RestoreToDefault);
CPPTEST_TEST(TestSuite_MApp_RestoreToDefault_test_MApp_DataBase_VersionCheck_false);
CPPTEST_TEST_SUITE_END();


void TestSuite_MApp_RestoreToDefault_test_MApp_DataBase_VersionCheck_false();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_MApp_RestoreToDefault);

void TestSuite_MApp_RestoreToDefault_setUp()
{
}

void TestSuite_MApp_RestoreToDefault_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_DataBase_VersionCheck_false */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_DataBase_VersionCheck(void) */
void TestSuite_MApp_RestoreToDefault_test_MApp_DataBase_VersionCheck_false()
{
    /* Pre-condition initialization */

    { // TRUE
         /* Initializing global variable stGenSetting */
    	stGenSetting.u8VersionCheck  = DEFAULT_DATABASE_VERSION;
    	stGenSetting.u8VersionCheckCom  = DEFAULT_DATABASE_VERSION_COM;

     	/* Tested function call */
        //BOOLEAN _return  = MApp_DB_GEN_VersionCheck();
        /* Post-condition check */
        //CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }

    { // FALSE
        /* Initializing global variable stGenSetting */
    	stGenSetting.u8VersionCheck  = DEFAULT_DATABASE_VERSION + 1;
        stGenSetting.u8VersionCheckCom  = DEFAULT_DATABASE_VERSION_COM;

    	/* Tested function call */
        //BOOLEAN _return  = MApp_DB_GEN_VersionCheck();
        /* Post-condition check */
        //CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
    }

    { // FALSE
         /* Initializing global variable stGenSetting */
     	stGenSetting.u8VersionCheck  = DEFAULT_DATABASE_VERSION;
     	stGenSetting.u8VersionCheckCom  = DEFAULT_DATABASE_VERSION_COM + 1;

     	/* Tested function call */
     	//BOOLEAN _return  = MApp_DB_GEN_VersionCheck();
        /* Post-condition check */
        //CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
     }
}
/* CPPTEST_TEST_CASE_END test_MApp_DataBase_VersionCheck_false */
