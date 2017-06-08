#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app/MApp_ATV_Scan.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app/MApp_ATV_Scan.c");

CPPTEST_TEST_SUITE(TestSuite_MApp_ATV_Scan);
CPPTEST_TEST(TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_POWER);
CPPTEST_TEST(TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_DSC_KEY_PWROFF);
CPPTEST_TEST(TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_EXIT_SCAN_TYPE_AUTO_STATE_ATV_SCAN_PAUSE);
CPPTEST_TEST(TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_EXIT_SCAN_TYPE_AUTO_OSD_TUNE_TYPE_ATV_ONLY);
CPPTEST_TEST(TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_EXIT_SCAN_TYPE_MANUAL);
CPPTEST_TEST(TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_MENU_SCAN_TYPE_AUTO_STATE_ATV_SCAN_PAUSE);
CPPTEST_TEST(TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_MENU_SCAN_TYPE_AUTO_OSD_TUNE_TYPE_ATV_ONLY);
CPPTEST_TEST(TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_MENU_SCAN_TYPE_MANUAL);
CPPTEST_TEST(TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_SELECT);
CPPTEST_TEST(TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_LEFT_SCAN_TYPE_AUTO);
CPPTEST_TEST(TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_LEFT_SCAN_TYPE_MANUAL);
CPPTEST_TEST(TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_RIGHT_SCAN_TYPE_AUTO);
CPPTEST_TEST(TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_RIGHT_SCAN_TYPE_MANUAL);
CPPTEST_TEST(TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_OTHER);
CPPTEST_TEST(TestSuite_MApp_ATV_Scan_test_MApp_ATV_SetATVScanState);
CPPTEST_TEST(TestSuite_MApp_ATV_Scan_test_MApp_ATV_ExitATVScanPauseState);
CPPTEST_TEST(TestSuite_MApp_ATV_Scan_test_MApp_ATV_ExitATVScanPause2Menu);
CPPTEST_TEST(TestSuite_MApp_ATV_Scan_test_MApp_ATV_ExitATVScanPause2ScanEnd);
CPPTEST_TEST(TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ScanState);
CPPTEST_TEST(TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_End);
CPPTEST_TEST_SUITE_END();


void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_POWER();
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_DSC_KEY_PWROFF();
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_EXIT_SCAN_TYPE_AUTO_STATE_ATV_SCAN_PAUSE();
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_EXIT_SCAN_TYPE_AUTO_OSD_TUNE_TYPE_ATV_ONLY();
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_EXIT_SCAN_TYPE_MANUAL();
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_MENU_SCAN_TYPE_AUTO_STATE_ATV_SCAN_PAUSE();
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_MENU_SCAN_TYPE_AUTO_OSD_TUNE_TYPE_ATV_ONLY();
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_MENU_SCAN_TYPE_MANUAL();
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_SELECT();
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_LEFT_SCAN_TYPE_AUTO();
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_LEFT_SCAN_TYPE_MANUAL();
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_RIGHT_SCAN_TYPE_AUTO();
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_RIGHT_SCAN_TYPE_MANUAL();
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_OTHER();
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_SetATVScanState();
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_ExitATVScanPauseState();
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_ExitATVScanPause2Menu();
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_ExitATVScanPause2ScanEnd();
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ScanState();
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_End();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_MApp_ATV_Scan);

void TestSuite_MApp_ATV_Scan_setUp()
{
}

void TestSuite_MApp_ATV_Scan_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATV_Scan_ProcessUserInput_case_KEY_POWER */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ATV_Scan_ProcessUserInput(void) */
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_POWER()
{
    /* Pre-condition initialization */
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable fEndHalt */
    {
         fEndHalt  = 0;
    }
    /* Initializing global variable fReturnToPrevious */
    {
         fReturnToPrevious  = 0;
    }
    /* Initializing global variable enPreATVScanState */
    {
         enPreATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_POWER;
    }
    /* Initializing global variable enATVScanState */
    {
         enATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        MApp_ATV_Scan_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(KEY_NULL, ( u8KeyCode ) );
        CPPTEST_ASSERT_EQUAL( STATE_ATV_SCAN_GOTO_STANDBY, ( enATVScanState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATV_Scan_ProcessUserInput_case_KEY_POWER */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATV_Scan_ProcessUserInput_case_DSC_KEY_PWROFF */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ATV_Scan_ProcessUserInput(void) */
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_DSC_KEY_PWROFF()
{
    /* Pre-condition initialization */
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable fEndHalt */
    {
         fEndHalt  = 0;
    }
    /* Initializing global variable fReturnToPrevious */
    {
         fReturnToPrevious  = 0;
    }
    /* Initializing global variable enPreATVScanState */
    {
         enPreATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = DSC_KEY_PWROFF;
    }
    /* Initializing global variable enATVScanState */
    {
         enATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        MApp_ATV_Scan_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(KEY_NULL, ( u8KeyCode ) );
        CPPTEST_ASSERT_EQUAL( STATE_ATV_SCAN_GOTO_STANDBY, ( enATVScanState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATV_Scan_ProcessUserInput_case_DSC_KEY_PWROFF */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATV_Scan_ProcessUserInput_case_KEY_EXIT_SCAN_TYPE_AUTO_STATE_ATV_SCAN_PAUSE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ATV_Scan_ProcessUserInput(void) */
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_EXIT_SCAN_TYPE_AUTO_STATE_ATV_SCAN_PAUSE()
{
    /* Pre-condition initialization */
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable fEndHalt */
    {
         fEndHalt  = 0;
    }
    /* Initializing global variable fReturnToPrevious */
    {
         fReturnToPrevious  = 0;
    }
    /* Initializing global variable enPreATVScanState */
    {
         enPreATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_EXIT;
    }
    /* Initializing global variable enATVScanState */
    {
         enATVScanState  = STATE_ATV_SCAN_PAUSE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.stScanMenuSetting.u8ScanType = SCAN_TYPE_AUTO;
    }
    {
        /* Tested function call */
        MApp_ATV_Scan_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(KEY_NULL, ( u8KeyCode ) );
        CPPTEST_ASSERT_EQUAL( STATE_ATV_SCAN_PAUSE, ( enATVScanState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATV_Scan_ProcessUserInput_case_KEY_EXIT_SCAN_TYPE_AUTO_STATE_ATV_SCAN_PAUSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATV_Scan_ProcessUserInput_case_KEY_EXIT_SCAN_TYPE_AUTO_OSD_TUNE_TYPE_ATV_ONLY */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ATV_Scan_ProcessUserInput(void) */
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_EXIT_SCAN_TYPE_AUTO_OSD_TUNE_TYPE_ATV_ONLY()
{
    /* Pre-condition initialization */
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_ATV_ONLY;
    }
    /* Initializing global variable fEndHalt */
    {
         fEndHalt  = 0;
    }
    /* Initializing global variable fReturnToPrevious */
    {
         fReturnToPrevious  = 0;
    }
    /* Initializing global variable enPreATVScanState */
    {
         enPreATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_EXIT;
    }
    /* Initializing global variable enATVScanState */
    {
         enATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.stScanMenuSetting.u8ScanType = SCAN_TYPE_AUTO;
    }
    {
        /* Tested function call */
        MApp_ATV_Scan_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( OSD_TUNE_TYPE_ATV_ONLY, ( eTuneType ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(FALSE, ( fEndHalt ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(FALSE, ( fReturnToPrevious ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(KEY_NULL, ( u8KeyCode ) );
        CPPTEST_ASSERT_EQUAL( STATE_ATV_SCAN_PAUSE, ( enATVScanState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATV_Scan_ProcessUserInput_case_KEY_EXIT_SCAN_TYPE_AUTO_OSD_TUNE_TYPE_ATV_ONLY */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATV_Scan_ProcessUserInput_case_KEY_EXIT_SCAN_TYPE_MANUAL */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ATV_Scan_ProcessUserInput(void) */
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_EXIT_SCAN_TYPE_MANUAL()
{
    /* Pre-condition initialization */
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable fEndHalt */
    {
         fEndHalt  = 0;
    }
    /* Initializing global variable fReturnToPrevious */
    {
         fReturnToPrevious  = 0;
    }
    /* Initializing global variable enPreATVScanState */
    {
         enPreATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_EXIT;
    }
    /* Initializing global variable enATVScanState */
    {
         enATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.stScanMenuSetting.u8ScanType = SCAN_TYPE_MANUAL;
    }
    {
        /* Tested function call */
        MApp_ATV_Scan_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( OSD_TUNE_TYPE_DTV_PLUS_ATV, ( eTuneType ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(FALSE, ( fEndHalt ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(FALSE, ( fReturnToPrevious ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(KEY_NULL, ( u8KeyCode ) );
        CPPTEST_ASSERT_EQUAL( STATE_ATV_SCAN_END, ( enATVScanState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATV_Scan_ProcessUserInput_case_KEY_EXIT_SCAN_TYPE_MANUAL */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATV_Scan_ProcessUserInput_case_KEY_MENU_SCAN_TYPE_AUTO_STATE_ATV_SCAN_PAUSE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ATV_Scan_ProcessUserInput(void) */
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_MENU_SCAN_TYPE_AUTO_STATE_ATV_SCAN_PAUSE()
{
    /* Pre-condition initialization */
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable fEndHalt */
    {
         fEndHalt  = 0;
    }
    /* Initializing global variable fReturnToPrevious */
    {
         fReturnToPrevious  = 0;
    }
    /* Initializing global variable enPreATVScanState */
    {
         enPreATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_MENU;
    }
    /* Initializing global variable enATVScanState */
    {
         enATVScanState  = STATE_ATV_SCAN_PAUSE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.stScanMenuSetting.u8ScanType = SCAN_TYPE_AUTO;
    }
    {
        /* Tested function call */
        MApp_ATV_Scan_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(KEY_NULL, ( u8KeyCode ) );
        CPPTEST_ASSERT_EQUAL( STATE_ATV_SCAN_PAUSE, ( enATVScanState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATV_Scan_ProcessUserInput_case_KEY_EXIT_SCAN_TYPE_AUTO_STATE_ATV_SCAN_PAUSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATV_Scan_ProcessUserInput_case_KEY_EXIT_SCAN_TYPE_AUTO_OSD_TUNE_TYPE_ATV_ONLY */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ATV_Scan_ProcessUserInput(void) */
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_MENU_SCAN_TYPE_AUTO_OSD_TUNE_TYPE_ATV_ONLY()
{
    /* Pre-condition initialization */
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_ATV_ONLY;
    }
    /* Initializing global variable fEndHalt */
    {
         fEndHalt  = 0;
    }
    /* Initializing global variable fReturnToPrevious */
    {
         fReturnToPrevious  = 0;
    }
    /* Initializing global variable enPreATVScanState */
    {
         enPreATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_MENU;
    }
    /* Initializing global variable enATVScanState */
    {
         enATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.stScanMenuSetting.u8ScanType = SCAN_TYPE_AUTO;
    }
    {
        /* Tested function call */
        MApp_ATV_Scan_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( OSD_TUNE_TYPE_ATV_ONLY, ( eTuneType ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(FALSE, ( fEndHalt ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(FALSE, ( fReturnToPrevious ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(KEY_NULL, ( u8KeyCode ) );
        CPPTEST_ASSERT_EQUAL( STATE_ATV_SCAN_PAUSE, ( enATVScanState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATV_Scan_ProcessUserInput_case_KEY_MENU_SCAN_TYPE_AUTO_OSD_TUNE_TYPE_ATV_ONLY */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATV_Scan_ProcessUserInput_case_KEY_MENU_SCAN_TYPE_MANUAL */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ATV_Scan_ProcessUserInput(void) */
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_MENU_SCAN_TYPE_MANUAL()
{
    /* Pre-condition initialization */
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable fEndHalt */
    {
         fEndHalt  = 0;
    }
    /* Initializing global variable fReturnToPrevious */
    {
         fReturnToPrevious  = 0;
    }
    /* Initializing global variable enPreATVScanState */
    {
         enPreATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_MENU;
    }
    /* Initializing global variable enATVScanState */
    {
         enATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.stScanMenuSetting.u8ScanType = SCAN_TYPE_MANUAL;
    }
    {
        /* Tested function call */
        MApp_ATV_Scan_ProcessUserInput();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATV_Scan_ProcessUserInput_case_KEY_EXIT_SCAN_TYPE_MANUAL */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATV_Scan_ProcessUserInput_case_KEY_SELECT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ATV_Scan_ProcessUserInput(void) */
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_SELECT()
{
    /* Pre-condition initialization */
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable fEndHalt */
    {
         fEndHalt  = 0;
    }
    /* Initializing global variable fReturnToPrevious */
    {
         fReturnToPrevious  = 0;
    }
    /* Initializing global variable enPreATVScanState */
    {
         enPreATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_SELECT;
    }
    /* Initializing global variable enATVScanState */
    {
         enATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.stScanMenuSetting.u8ScanType = SCAN_TYPE_AUTO;
    }
    {
        /* Tested function call */
        MApp_ATV_Scan_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(KEY_NULL, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATV_Scan_ProcessUserInput_case_KEY_SELECT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATV_Scan_ProcessUserInput_case_KEY_LEFT_SCAN_TYPE_AUTO */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ATV_Scan_ProcessUserInput(void) */
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_LEFT_SCAN_TYPE_AUTO()
{
    /* Pre-condition initialization */
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable fEndHalt */
    {
         fEndHalt  = 0;
    }
    /* Initializing global variable fReturnToPrevious */
    {
         fReturnToPrevious  = 0;
    }
    /* Initializing global variable enPreATVScanState */
    {
         enPreATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_LEFT;
    }
    /* Initializing global variable enATVScanState */
    {
         enATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.stScanMenuSetting.u8ScanType = SCAN_TYPE_AUTO;
    }
    {
        /* Tested function call */
        MApp_ATV_Scan_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(KEY_NULL, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATV_Scan_ProcessUserInput_case_KEY_LEFT_SCAN_TYPE_AUTO */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATV_Scan_ProcessUserInput_case_KEY_LEFT_SCAN_TYPE_MANUAL */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ATV_Scan_ProcessUserInput(void) */
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_LEFT_SCAN_TYPE_MANUAL()
{
    /* Pre-condition initialization */
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable fEndHalt */
    {
         fEndHalt  = 0;
    }
    /* Initializing global variable fReturnToPrevious */
    {
         fReturnToPrevious  = 0;
    }
    /* Initializing global variable enPreATVScanState */
    {
         enPreATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_LEFT;
    }
    /* Initializing global variable enATVScanState */
    {
         enATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.stScanMenuSetting.u8ScanType = SCAN_TYPE_MANUAL;
         stGenSetting.stScanMenuSetting.u8ATVManScanDir = ATV_MAN_SCAN_UP;
    }
    {
        /* Tested function call */
        MApp_ATV_Scan_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(KEY_NULL, ( u8KeyCode ) );
        CPPTEST_ASSERT_EQUAL( STATE_ATV_SCAN_END, ( enATVScanState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATV_Scan_ProcessUserInput_case_KEY_LEFT_SCAN_TYPE_MANUAL */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATV_Scan_ProcessUserInput_case_KEY_RIGHT_SCAN_TYPE_AUTO */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ATV_Scan_ProcessUserInput(void) */
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_RIGHT_SCAN_TYPE_AUTO()
{
    /* Pre-condition initialization */
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable fEndHalt */
    {
         fEndHalt  = 0;
    }
    /* Initializing global variable fReturnToPrevious */
    {
         fReturnToPrevious  = 0;
    }
    /* Initializing global variable enPreATVScanState */
    {
         enPreATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_RIGHT;
    }
    /* Initializing global variable enATVScanState */
    {
         enATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.stScanMenuSetting.u8ScanType = SCAN_TYPE_AUTO;
    }
    {
        /* Tested function call */
        MApp_ATV_Scan_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(KEY_NULL, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATV_Scan_ProcessUserInput_case_KEY_LEFT_SCAN_TYPE_AUTO */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATV_Scan_ProcessUserInput_case_KEY_RIGHT_SCAN_TYPE_MANUAL */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ATV_Scan_ProcessUserInput(void) */
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_RIGHT_SCAN_TYPE_MANUAL()
{
    /* Pre-condition initialization */
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable fEndHalt */
    {
         fEndHalt  = 0;
    }
    /* Initializing global variable fReturnToPrevious */
    {
         fReturnToPrevious  = 0;
    }
    /* Initializing global variable enPreATVScanState */
    {
         enPreATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_RIGHT;
    }
    /* Initializing global variable enATVScanState */
    {
         enATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.stScanMenuSetting.u8ScanType = SCAN_TYPE_MANUAL;
         stGenSetting.stScanMenuSetting.u8ATVManScanDir = ATV_MAN_SCAN_DOWN;
    }
    {
        /* Tested function call */
        MApp_ATV_Scan_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(KEY_NULL, ( u8KeyCode ) );
        CPPTEST_ASSERT_EQUAL( STATE_ATV_SCAN_END, ( enATVScanState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATV_Scan_ProcessUserInput_case_KEY_LEFT_SCAN_TYPE_MANUAL */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATV_Scan_ProcessUserInput_case_KEY_OTHER */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ATV_Scan_ProcessUserInput(void) */
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_OTHER()
{
    /* Pre-condition initialization */
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable fEndHalt */
    {
         fEndHalt  = 0;
    }
    /* Initializing global variable fReturnToPrevious */
    {
         fReturnToPrevious  = 0;
    }
    /* Initializing global variable enPreATVScanState */
    {
         enPreATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_RED;
    }
    /* Initializing global variable enATVScanState */
    {
         enATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        MApp_ATV_Scan_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(KEY_NULL, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATV_Scan_ProcessUserInput_case_KEY_OTHER */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATV_SetATVScanState */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ATV_SetATVScanState(EN_ATV_SCAN_STATE) */
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_SetATVScanState()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (atvScanState) */
    EN_ATV_SCAN_STATE _atvScanState  = STATE_ATV_SCAN_INIT;
    /* Initializing global variable enATVScanState */
    {
         enATVScanState  = STATE_ATV_SCAN_INIT;
    }
    {
        /* Tested function call */
        MApp_ATV_SetATVScanState(_atvScanState);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATV_SetATVScanState */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATV_ExitATVScanPauseState */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ATV_ExitATVScanPauseState(void) */
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_ExitATVScanPauseState()
{
    /* Pre-condition initialization */
    /* Initializing global variable fEndHalt */
    {
         fEndHalt  = 0;
    }
    /* Initializing global variable fReturnToPrevious */
    {
         fReturnToPrevious  = 0;
    }
    /* Initializing global variable enPreATVScanState */
    {
         enPreATVScanState  = STATE_ATV_SCAN_INIT;
    }
    /* Initializing global variable enATVScanState */
    {
         enATVScanState  = STATE_ATV_SCAN_INIT;
    }
    {
        /* Tested function call */
        MApp_ATV_ExitATVScanPauseState();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( fEndHalt ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( fReturnToPrevious ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATV_ExitATVScanPauseState */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATV_ExitATVScanPause2Menu */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ATV_ExitATVScanPause2Menu(void) */
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_ExitATVScanPause2Menu()
{
    /* Pre-condition initialization */
    /* Initializing global variable fEndHalt */
    {
         fEndHalt  = 0;
    }
    /* Initializing global variable fReturnToPrevious */
    {
         fReturnToPrevious  = 0;
    }
    /* Initializing global variable enPreATVScanState */
    {
         enPreATVScanState  = STATE_ATV_SCAN_INIT;
    }
    {
        /* Tested function call */
        MApp_ATV_ExitATVScanPause2Menu();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( fEndHalt ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( fReturnToPrevious ) );
        CPPTEST_ASSERT_EQUAL( STATE_ATV_SCAN_EXIT_2_MAIN_MENU, ( enPreATVScanState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATV_ExitATVScanPause2Menu */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATV_ExitATVScanPause2ScanEnd */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ATV_ExitATVScanPause2ScanEnd(void) */
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_ExitATVScanPause2ScanEnd()
{
    /* Pre-condition initialization */
    /* Initializing global variable fEndHalt */
    {
         fEndHalt  = 0;
    }
    /* Initializing global variable fReturnToPrevious */
    {
         fReturnToPrevious  = 0;
    }
    /* Initializing global variable enPreATVScanState */
    {
         enPreATVScanState  = STATE_ATV_SCAN_INIT;
    }
    {
        /* Tested function call */
        MApp_ATV_ExitATVScanPause2ScanEnd();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( fEndHalt ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( fReturnToPrevious ) );
        CPPTEST_ASSERT_EQUAL( STATE_ATV_SCAN_END, ( enPreATVScanState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATV_ExitATVScanPause2ScanEnd */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATV_Scan_ScanState */
/* CPPTEST_TEST_CASE_CONTEXT EN_ATV_SCAN_STATE MApp_ATV_Scan_ScanState(void) */
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ScanState()
{
    /* Pre-condition initialization */
    /* Initializing global variable enATVScanState */
    {
         enATVScanState  = STATE_ATV_SCAN_INIT;
    }
    {
        /* Tested function call */
        EN_ATV_SCAN_STATE _return  = MApp_ATV_Scan_ScanState();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_ATV_SCAN_INIT, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATV_Scan_ScanState */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATV_Scan_End */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ATV_Scan_End(void) */
void TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_End()
{
    /* Pre-condition initialization */
    /* Initializing global variable gbTVAutoScanChannelEnable */
    {
         gbTVAutoScanChannelEnable  = 0;
    }
    {
        /* Tested function call */
        MApp_ATV_Scan_End();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( gbTVAutoScanChannelEnable ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATV_Scan_End */
