#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/msAPI_MHL.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/msAPI_MHL.c");

CPPTEST_TEST_SUITE(TestSuite_msAPI_MHL);
CPPTEST_TEST(TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRcpProcess_case_DEFAULT);
CPPTEST_TEST(TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRcpProcess_case_RCP_KEYID_SELECT);
CPPTEST_TEST(TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRcpProcess_case_RCP_KEYID_UP);
CPPTEST_TEST(TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRcpProcess_case_RCP_KEYID_DOWN);
CPPTEST_TEST(TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRcpProcess_case_RCP_KEYID_ROOT_MENU);
CPPTEST_TEST(TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRcpProcess_case_RCP_KEYID_EXIT);
CPPTEST_TEST(TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRapProcess_case_DEFAULT);
CPPTEST_TEST(TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRapProcess_case_MSC_RAP_POLL);
CPPTEST_TEST(TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRapProcess_case_MSC_RAP_CONTENT_ON);
CPPTEST_TEST(TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRapProcess_case_MSC_RAP_CONTENT_OFF);
CPPTEST_TEST_SUITE_END();


void TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRcpProcess_case_DEFAULT();
void TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRcpProcess_case_RCP_KEYID_SELECT();
void TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRcpProcess_case_RCP_KEYID_UP();
void TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRcpProcess_case_RCP_KEYID_DOWN();
void TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRcpProcess_case_RCP_KEYID_ROOT_MENU();
void TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRcpProcess_case_RCP_KEYID_EXIT();
void TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRapProcess_case_DEFAULT();
void TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRapProcess_case_MSC_RAP_POLL();
void TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRapProcess_case_MSC_RAP_CONTENT_ON();
void TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRapProcess_case_MSC_RAP_CONTENT_OFF();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_msAPI_MHL);

void TestSuite_msAPI_MHL_setUp()
{
}

void TestSuite_msAPI_MHL_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_MHL_CbusRcpProcess_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT MS_U8 msAPI_MHL_CbusRcpProcess(MS_U8) */
void TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRcpProcess_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (rcpCode) */
    MS_U8 _rcpCode  = RCP_KEYID_RESERVED;
    MS_U8 statusCode = MSC_RCP_NO_ERROR;
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    {
        /* Tested function call */
        MS_U8 _return  = msAPI_MHL_CbusRcpProcess(_rcpCode);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 0, ( u8KeyCode ) );
        CPPTEST_ASSERT_EQUAL( MSC_RCP_INEFFECTIVE_KEY_CODE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_MHL_CbusRcpProcess_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_MHL_CbusRcpProcess_case_RCP_KEYID_SELECT */
/* CPPTEST_TEST_CASE_CONTEXT MS_U8 msAPI_MHL_CbusRcpProcess(MS_U8) */
void TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRcpProcess_case_RCP_KEYID_SELECT()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (rcpCode) */
    MS_U8 _rcpCode  = RCP_KEYID_SELECT;
    MS_U8 statusCode = MSC_RCP_NO_ERROR;
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    {
        /* Tested function call */
        MS_U8 _return  = msAPI_MHL_CbusRcpProcess(_rcpCode);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_SELECT, ( u8KeyCode ) );
        CPPTEST_ASSERT_EQUAL( MSC_RCP_NO_ERROR, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_MHL_CbusRcpProcess_case_RCP_KEYID_SELECT */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_MHL_CbusRcpProcess_case_RCP_KEYID_UP */
/* CPPTEST_TEST_CASE_CONTEXT MS_U8 msAPI_MHL_CbusRcpProcess(MS_U8) */
void TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRcpProcess_case_RCP_KEYID_UP()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (rcpCode) */
    MS_U8 _rcpCode  = RCP_KEYID_UP;
    MS_U8 statusCode = MSC_RCP_NO_ERROR;
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    {
        /* Tested function call */
        MS_U8 _return  = msAPI_MHL_CbusRcpProcess(_rcpCode);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_UP, ( u8KeyCode ) );
        CPPTEST_ASSERT_EQUAL( MSC_RCP_NO_ERROR, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_MHL_CbusRcpProcess_case_RCP_KEYID_UP */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_MHL_CbusRcpProcess_case_RCP_KEYID_DOWN */
/* CPPTEST_TEST_CASE_CONTEXT MS_U8 msAPI_MHL_CbusRcpProcess(MS_U8) */
void TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRcpProcess_case_RCP_KEYID_DOWN()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (rcpCode) */
    MS_U8 _rcpCode  = RCP_KEYID_DOWN;
    MS_U8 statusCode = MSC_RCP_NO_ERROR;
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    {
        /* Tested function call */
        MS_U8 _return  = msAPI_MHL_CbusRcpProcess(_rcpCode);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_DOWN, ( u8KeyCode ) );
        CPPTEST_ASSERT_EQUAL( MSC_RCP_NO_ERROR, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_MHL_CbusRcpProcess_case_RCP_KEYID_DOWN */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_MHL_CbusRcpProcess_case_RCP_KEYID_ROOT_MENU */
/* CPPTEST_TEST_CASE_CONTEXT MS_U8 msAPI_MHL_CbusRcpProcess(MS_U8) */
void TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRcpProcess_case_RCP_KEYID_ROOT_MENU()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (rcpCode) */
    MS_U8 _rcpCode  = RCP_KEYID_ROOT_MENU;
    MS_U8 statusCode = MSC_RCP_NO_ERROR;
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    {
        /* Tested function call */
        MS_U8 _return  = msAPI_MHL_CbusRcpProcess(_rcpCode);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_MENU, ( u8KeyCode ) );
        CPPTEST_ASSERT_EQUAL( MSC_RCP_NO_ERROR, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_MHL_CbusRcpProcess_case_RCP_KEYID_ROOT_MENU */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_MHL_CbusRcpProcess_case_RCP_KEYID_EXIT */
/* CPPTEST_TEST_CASE_CONTEXT MS_U8 msAPI_MHL_CbusRcpProcess(MS_U8) */
void TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRcpProcess_case_RCP_KEYID_EXIT()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (rcpCode) */
    MS_U8 _rcpCode  = RCP_KEYID_EXIT;
    MS_U8 statusCode = MSC_RCP_NO_ERROR;
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    {
        /* Tested function call */
        MS_U8 _return  = msAPI_MHL_CbusRcpProcess(_rcpCode);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_EXIT, ( u8KeyCode ) );
        CPPTEST_ASSERT_EQUAL( MSC_RCP_NO_ERROR, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_MHL_CbusRcpProcess_case_RCP_KEYID_EXIT */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_MHL_CbusRapProcess_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT MS_U8 msAPI_MHL_CbusRapProcess(MS_U8) */
void TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRapProcess_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (rapCode) */
    MS_U8 _rapCode  = 0xFF;
    MS_U8 statusCode = MSC_RCP_NO_ERROR;
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        MS_U8 _return  = msAPI_MHL_CbusRapProcess(_rapCode);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MSC_RAP_UNRECOGNIZED_ACTION_CODE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_MHL_CbusRapProcess_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_MHL_CbusRapProcess_case_MSC_RAP_POLL */
/* CPPTEST_TEST_CASE_CONTEXT MS_U8 msAPI_MHL_CbusRapProcess(MS_U8) */
void TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRapProcess_case_MSC_RAP_POLL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (rapCode) */
    MS_U8 _rapCode  = MSC_RAP_POLL;
    MS_U8 statusCode = MSC_RCP_NO_ERROR;
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        MS_U8 _return  = msAPI_MHL_CbusRapProcess(_rapCode);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MSC_RCP_NO_ERROR, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_MHL_CbusRapProcess_case_MSC_RAP_POLL */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_MHL_CbusRapProcess_case_MSC_RAP_CONTENT_ON */
/* CPPTEST_TEST_CASE_CONTEXT MS_U8 msAPI_MHL_CbusRapProcess(MS_U8) */
void TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRapProcess_case_MSC_RAP_CONTENT_ON()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (rapCode) */
    MS_U8 _rapCode  = MSC_RAP_CONTENT_ON;
    MS_U8 statusCode = MSC_RCP_NO_ERROR;
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        MS_U8 _return  = msAPI_MHL_CbusRapProcess(_rapCode);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MSC_RCP_NO_ERROR, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_MHL_CbusRapProcess_case_MSC_RAP_CONTENT_ON */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_MHL_CbusRapProcess_case_MSC_RAP_CONTENT_OFF */
/* CPPTEST_TEST_CASE_CONTEXT MS_U8 msAPI_MHL_CbusRapProcess(MS_U8) */
void TestSuite_msAPI_MHL_test_msAPI_MHL_CbusRapProcess_case_MSC_RAP_CONTENT_OFF()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (rapCode) */
    MS_U8 _rapCode  = MSC_RAP_CONTENT_OFF;
    MS_U8 statusCode = MSC_RCP_NO_ERROR;
    UI_INPUT_SOURCE_TYPE = HDMI_PORT_FOR_MHL;
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        MS_U8 _return  = msAPI_MHL_CbusRapProcess(_rapCode);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MSC_RCP_NO_ERROR, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_MHL_CbusRapProcess_case_MSC_RAP_CONTENT_OFF */
