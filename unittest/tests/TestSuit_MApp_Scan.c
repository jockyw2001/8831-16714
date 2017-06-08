#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app/MApp_Scan.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app/MApp_Scan.c");

CPPTEST_TEST_SUITE(TestSuit_MApp_Scan);
CPPTEST_TEST(TestSuit_MApp_Scan_test_MApp_Scan_ProcessUserInput_CASE_POWERKEY);
CPPTEST_TEST(TestSuit_MApp_Scan_test_MApp_Scan_ProcessUserInput_CASE_KEYEXIT_step1);
CPPTEST_TEST(TestSuit_MApp_Scan_test_MApp_Scan_ProcessUserInput_CASE_KEYEXIT_step2);
CPPTEST_TEST(TestSuit_MApp_Scan_test_MApp_Scan_ProcessUserInput_CASE_POWERKEY_CASE_KEYSELECT);
CPPTEST_TEST(TestSuit_MApp_Scan_test_MApp_Scan_ProcessUserInput_CASE_KEYUP);
CPPTEST_TEST(TestSuit_MApp_Scan_test_MApp_DTV_Scan_Init_g_enScanType_NO_EQUAL_SCAN_TYPE_NUM);
CPPTEST_TEST(TestSuit_MApp_Scan_test_MApp_DTV_Scan_Init_COUNTRY_NORWAY);
CPPTEST_TEST(TestSuit_MApp_Scan_test_MApp_Scan_AddOneDTVPchVchs_logic0);
CPPTEST_TEST(TestSuit_MApp_Scan_test_MApp_Scan_AddOneDTVPchVchs_logic1);
CPPTEST_TEST_SUITE_END();

void TestSuit_MApp_Scan_test_MApp_Scan_ProcessUserInput_CASE_POWERKEY();
void TestSuit_MApp_Scan_test_MApp_Scan_ProcessUserInput_CASE_KEYEXIT_step1v();
void TestSuit_MApp_Scan_test_MApp_Scan_ProcessUserInput_CASE_KEYEXIT_step2();
void TestSuit_MApp_Scan_test_MApp_Scan_ProcessUserInput_CASE_POWERKEY_CASE_KEYSELECT();
void TestSuit_MApp_Scan_test_MApp_Scan_ProcessUserInput_CASE_KEYUP();
void TestSuit_MApp_Scan_test_MApp_DTV_Scan_Init_g_enScanType_NO_EQUAL_SCAN_TYPE_NUM();
void TestSuit_MApp_Scan_test_MApp_DTV_Scan_Init_COUNTRY_NORWAY();
void TestSuit_MApp_Scan_test_MApp_Scan_AddOneDTVPchVchs_logic0();
void TestSuit_MApp_Scan_test_MApp_Scan_AddOneDTVPchVchs_logic1();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuit_MApp_Scan);

void TestSuit_MApp_Scan_setUp()
{
}

void TestSuit_MApp_Scan_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_Scan_ProcessUserInput */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Scan_ProcessUserInput(void) */
void TestSuit_MApp_Scan_test_MApp_Scan_ProcessUserInput_CASE_POWERKEY()
{
    /* Pre-condition initialization */
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_POWER;
    }
    /* Initializing global variable enScanState */
    {
         enScanState  = STATE_SCAN_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
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
    /* Initializing global variable enPreScanState */
    {
         enPreScanState  = STATE_SCAN_INIT;
    }
    {
        /* Tested function call */
        MApp_Scan_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(STATE_SCAN_GOTO_STANDBY,enScanState);
     /*   CPPTEST_POST_CONDITION_UINTEGER("U8 u8KeyCode", ( u8KeyCode ));
        CPPTEST_ASSERT_EQUAL( STATE_SCAN_INIT, ( enScanState ) )
        CPPTEST_POST_CONDITION_UINTEGER("U8 stGenSetting.u8VersionCheck", ( stGenSetting.u8VersionCheck ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 stGenSetting.stMiscSetting.bRunInstallationGuide", ( stGenSetting.stMiscSetting.bRunInstallationGuide ));
        CPPTEST_ASSERT_EQUAL( EN_POWER_DC_ON, ( stGenSetting.stMiscSetting.bDCOnOff ) )
        CPPTEST_POST_CONDITION_UINTEGER("U8 stGenSetting.u8VersionCheckCom", ( stGenSetting.u8VersionCheckCom ));
        CPPTEST_ASSERT_EQUAL( OSD_TUNE_TYPE_DTV_PLUS_ATV, ( eTuneType ) )
        CPPTEST_POST_CONDITION_UINTEGER("U8 fEndHalt", ( fEndHalt ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 fReturnToPrevious", ( fReturnToPrevious ));
        CPPTEST_ASSERT_EQUAL( STATE_SCAN_INIT, ( enPreScanState ) ) */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Scan_ProcessUserInput */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Scan_ProcessUserInput_CASE_KEYEXIT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Scan_ProcessUserInput(void) */
void TestSuit_MApp_Scan_test_MApp_Scan_ProcessUserInput_CASE_KEYEXIT_step1()
{
    /* Pre-condition initialization */
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_EXIT;
    }
    /* Initializing global variable enScanState */
    {
         enScanState  = STATE_SCAN_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.stScanMenuSetting.u8ScanType == SCAN_TYPE_AUTO;
    }
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
    /* Initializing global variable enPreScanState */
    {
         enPreScanState  = STATE_SCAN_INIT;
    }
    {
        /* Tested function call */
        MApp_Scan_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(KEY_NULL,u8KeyCode);
     /*   CPPTEST_POST_CONDITION_UINTEGER("U8 u8KeyCode", ( u8KeyCode ));
        CPPTEST_ASSERT_EQUAL( STATE_SCAN_INIT, ( enScanState ) )
        CPPTEST_POST_CONDITION_UINTEGER("U8 stGenSetting.u8VersionCheck", ( stGenSetting.u8VersionCheck ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 stGenSetting.stMiscSetting.bRunInstallationGuide", ( stGenSetting.stMiscSetting.bRunInstallationGuide ));
        CPPTEST_ASSERT_EQUAL( EN_POWER_DC_ON, ( stGenSetting.stMiscSetting.bDCOnOff ) )
        CPPTEST_POST_CONDITION_UINTEGER("U8 stGenSetting.u8VersionCheckCom", ( stGenSetting.u8VersionCheckCom ));
        CPPTEST_ASSERT_EQUAL( OSD_TUNE_TYPE_DTV_PLUS_ATV, ( eTuneType ) )
        CPPTEST_POST_CONDITION_UINTEGER("U8 fEndHalt", ( fEndHalt ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 fReturnToPrevious", ( fReturnToPrevious ));
        CPPTEST_ASSERT_EQUAL( STATE_SCAN_INIT, ( enPreScanState ) )*/
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Scan_ProcessUserInput_CASE_KEYEXIT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Scan_ProcessUserInput_CASE_KEYEXIT_step2 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Scan_ProcessUserInput(void) */
void TestSuit_MApp_Scan_test_MApp_Scan_ProcessUserInput_CASE_KEYEXIT_step2()
{
    /* Pre-condition initialization */
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_EXIT;
    }
    /* Initializing global variable enScanState */
    {
         enScanState  = STATE_SCAN_END;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.stScanMenuSetting.u8ScanType == SCAN_TYPE_AUTO;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_ONLY;
    }
    /* Initializing global variable fEndHalt */
    {
         fEndHalt  = 0;
    }
    /* Initializing global variable fReturnToPrevious */
    {
         fReturnToPrevious  = 0;
    }
    /* Initializing global variable enPreScanState */
    {
         enPreScanState  = STATE_SCAN_END;
    }
    {
        /* Tested function call */
        MApp_Scan_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FALSE,fEndHalt);
        CPPTEST_ASSERT_EQUAL(FALSE,fReturnToPrevious);
        CPPTEST_ASSERT_EQUAL(STATE_SCAN_PAUSE,enScanState);
     /*   CPPTEST_POST_CONDITION_UINTEGER("U8 u8KeyCode", ( u8KeyCode ));
        CPPTEST_ASSERT_EQUAL( STATE_SCAN_INIT, ( enScanState ) )
        CPPTEST_POST_CONDITION_UINTEGER("U8 stGenSetting.u8VersionCheck", ( stGenSetting.u8VersionCheck ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 stGenSetting.stMiscSetting.bRunInstallationGuide", ( stGenSetting.stMiscSetting.bRunInstallationGuide ));
        CPPTEST_ASSERT_EQUAL( EN_POWER_DC_ON, ( stGenSetting.stMiscSetting.bDCOnOff ) )
        CPPTEST_POST_CONDITION_UINTEGER("U8 stGenSetting.u8VersionCheckCom", ( stGenSetting.u8VersionCheckCom ));
        CPPTEST_ASSERT_EQUAL( OSD_TUNE_TYPE_DTV_PLUS_ATV, ( eTuneType ) )
        CPPTEST_POST_CONDITION_UINTEGER("U8 fEndHalt", ( fEndHalt ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 fReturnToPrevious", ( fReturnToPrevious ));
        CPPTEST_ASSERT_EQUAL( STATE_SCAN_INIT, ( enPreScanState ) )
        */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Scan_ProcessUserInput_CASE_KEYEXIT_step2 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Scan_ProcessUserInput */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Scan_ProcessUserInput(void) */
void TestSuit_MApp_Scan_test_MApp_Scan_ProcessUserInput_CASE_POWERKEY_CASE_KEYSELECT()
{
    /* Pre-condition initialization */
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_SELECT;
    }
    /* Initializing global variable enScanState */
    {
         enScanState  = STATE_SCAN_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.stScanMenuSetting.u8ScanType = SCAN_TYPE_AUTO;
    }
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
    /* Initializing global variable enPreScanState */
    {
         enPreScanState  = STATE_SCAN_INIT;
    }
    {
        /* Tested function call */
        MApp_Scan_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(KEY_NULL,u8KeyCode);
       /* CPPTEST_POST_CONDITION_UINTEGER("U8 u8KeyCode", ( u8KeyCode ));
        CPPTEST_ASSERT_EQUAL( STATE_SCAN_INIT, ( enScanState ) )
        CPPTEST_POST_CONDITION_UINTEGER("U8 stGenSetting.u8VersionCheck", ( stGenSetting.u8VersionCheck ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 stGenSetting.stMiscSetting.bRunInstallationGuide", ( stGenSetting.stMiscSetting.bRunInstallationGuide ));
        CPPTEST_ASSERT_EQUAL( EN_POWER_DC_ON, ( stGenSetting.stMiscSetting.bDCOnOff ) )
        CPPTEST_POST_CONDITION_UINTEGER("U8 stGenSetting.u8VersionCheckCom", ( stGenSetting.u8VersionCheckCom ));
        CPPTEST_ASSERT_EQUAL( OSD_TUNE_TYPE_DTV_PLUS_ATV, ( eTuneType ) )
        CPPTEST_POST_CONDITION_UINTEGER("U8 fEndHalt", ( fEndHalt ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 fReturnToPrevious", ( fReturnToPrevious ));
        CPPTEST_ASSERT_EQUAL( STATE_SCAN_INIT, ( enPreScanState ) )
        */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Scan_ProcessUserInput */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Scan_ProcessUserInput_CASE_KEYUP */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Scan_ProcessUserInput(void) */
void TestSuit_MApp_Scan_test_MApp_Scan_ProcessUserInput_CASE_KEYUP()
{
    /* Pre-condition initialization */
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_UP;
    }
    /* Initializing global variable enScanState */
    {
         enScanState  = STATE_SCAN_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.stScanMenuSetting.u8ScanType = SCAN_TYPE_AUTO;
    }
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
    /* Initializing global variable enPreScanState */
    {
         enPreScanState  = STATE_SCAN_INIT;
    }
    {
        /* Tested function call */
        MApp_Scan_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(KEY_NULL,u8KeyCode);
       /*CPPTEST_POST_CONDITION_UINTEGER("U8 u8KeyCode", ( u8KeyCode ));
        CPPTEST_ASSERT_EQUAL( STATE_SCAN_INIT, ( enScanState ) )
        CPPTEST_POST_CONDITION_UINTEGER("U8 stGenSetting.u8VersionCheck", ( stGenSetting.u8VersionCheck ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 stGenSetting.stMiscSetting.bRunInstallationGuide", ( stGenSetting.stMiscSetting.bRunInstallationGuide ));
        CPPTEST_ASSERT_EQUAL( EN_POWER_DC_ON, ( stGenSetting.stMiscSetting.bDCOnOff ) )
        CPPTEST_POST_CONDITION_UINTEGER("U8 stGenSetting.u8VersionCheckCom", ( stGenSetting.u8VersionCheckCom ));
        CPPTEST_ASSERT_EQUAL( OSD_TUNE_TYPE_DTV_PLUS_ATV, ( eTuneType ) )
        CPPTEST_POST_CONDITION_UINTEGER("U8 fEndHalt", ( fEndHalt ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 fReturnToPrevious", ( fReturnToPrevious ));
        CPPTEST_ASSERT_EQUAL( STATE_SCAN_INIT, ( enPreScanState ) )*/
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Scan_ProcessUserInput_CASE_KEYUP */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_DTV_Scan_Init_g_enScanType_NO_EQUAL_SCAN_TYPE_NUM */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_DTV_Scan_Init(void) */
void TestSuit_MApp_Scan_test_MApp_DTV_Scan_Init_g_enScanType_NO_EQUAL_SCAN_TYPE_NUM()
{
    /* Pre-condition initialization */
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable u8RFCh */
    {
         u8RFCh  = 0;
    }
    /* Initializing global variable g_enChType */
    {
         g_enChType  = CH_TYPE_DTV;
    }
    /* Initializing global variable bSetTargetRegion */
    {
         bSetTargetRegion  = 0;
    }
    /* Initializing global variable u8NumOfVchFound */
    {
         u8NumOfVchFound  = 0;
    }
    /* Initializing global variable u8ScanPercentageNum */
    {
         u8ScanPercentageNum  = 0;
    }
    /* Initializing global variable u16NumOfSrvAdd */
    {
         u16NumOfSrvAdd  = 0u;
    }
    /* Initializing global variable g_enScanType */
    {
         g_enScanType  = SCAN_TYPE_AUTO;
    }
    /* Initializing global variable u8MuxTotal */
    {
         u8MuxTotal  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_DTV_Scan_Init();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0,u8MuxTotal);
       /* CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 stGenSetting.u8VersionCheck", ( stGenSetting.u8VersionCheck ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 stGenSetting.stMiscSetting.bRunInstallationGuide", ( stGenSetting.stMiscSetting.bRunInstallationGuide ));
        CPPTEST_ASSERT_EQUAL( EN_POWER_DC_ON, ( stGenSetting.stMiscSetting.bDCOnOff ) )
        CPPTEST_POST_CONDITION_UINTEGER("U8 stGenSetting.u8VersionCheckCom", ( stGenSetting.u8VersionCheckCom ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 u8RFCh", ( u8RFCh ));
        CPPTEST_ASSERT_EQUAL( CH_TYPE_DTV, ( g_enChType ) )
        CPPTEST_POST_CONDITION_UINTEGER("U8 bSetTargetRegion", ( bSetTargetRegion ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 u8NumOfVchFound", ( u8NumOfVchFound ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 u8ScanPercentageNum", ( u8ScanPercentageNum ));
        CPPTEST_POST_CONDITION_UINTEGER("U16 u16NumOfSrvAdd", ( u16NumOfSrvAdd ));
        CPPTEST_ASSERT_EQUAL( SCAN_TYPE_AUTO, ( g_enScanType ) )
        CPPTEST_POST_CONDITION_UINTEGER("U8 u8MuxTotal", ( u8MuxTotal ));
        */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_DTV_Scan_Init_g_enScanType_NO_EQUAL_SCAN_TYPE_NUM */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_DTV_Scan_Init_COUNTRY_NORWAY */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_DTV_Scan_Init(void) */
void TestSuit_MApp_Scan_test_MApp_DTV_Scan_Init_COUNTRY_NORWAY()
{
    /* Pre-condition initialization */
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable u8RFCh */
    {
         u8RFCh  = 0;
    }
    /* Initializing global variable g_enChType */
    {
         g_enChType  = CH_TYPE_DTV;
    }
    /* Initializing global variable bSetTargetRegion */
    {
         bSetTargetRegion  = 0;
    }
    /* Initializing global variable u8NumOfVchFound */
    {
         u8NumOfVchFound  = 0;
    }
    /* Initializing global variable u8ScanPercentageNum */
    {
         u8ScanPercentageNum  = 0;
    }
    /* Initializing global variable u16NumOfSrvAdd */
    {
         u16NumOfSrvAdd  = 0u;
    }
    /* Initializing global variable g_enScanType */
    {
         g_enScanType  = SCAN_TYPE_AUTO;
    }
    /* Initializing global variable u8MuxTotal */
    {
         u8MuxTotal  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_DTV_Scan_Init();
        /* Post-condition check */
     /*   CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 stGenSetting.u8VersionCheck", ( stGenSetting.u8VersionCheck ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 stGenSetting.stMiscSetting.bRunInstallationGuide", ( stGenSetting.stMiscSetting.bRunInstallationGuide ));
        CPPTEST_ASSERT_EQUAL( EN_POWER_DC_ON, ( stGenSetting.stMiscSetting.bDCOnOff ) )
        CPPTEST_POST_CONDITION_UINTEGER("U8 stGenSetting.u8VersionCheckCom", ( stGenSetting.u8VersionCheckCom ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 u8RFCh", ( u8RFCh ));
        CPPTEST_ASSERT_EQUAL( CH_TYPE_DTV, ( g_enChType ) )
        CPPTEST_POST_CONDITION_UINTEGER("U8 bSetTargetRegion", ( bSetTargetRegion ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 u8NumOfVchFound", ( u8NumOfVchFound ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 u8ScanPercentageNum", ( u8ScanPercentageNum ));
        CPPTEST_POST_CONDITION_UINTEGER("U16 u16NumOfSrvAdd", ( u16NumOfSrvAdd ));
        CPPTEST_ASSERT_EQUAL( SCAN_TYPE_AUTO, ( g_enScanType ) )
        CPPTEST_POST_CONDITION_UINTEGER("U8 u8MuxTotal", ( u8MuxTotal ));
        */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_DTV_Scan_Init_COUNTRY_NORWAY */




/* CPPTEST_TEST_CASE_BEGIN test_MApp_Scan_AddOneDTVPchVchs_logic0 */
/* CPPTEST_TEST_CASE_CONTEXT U8 MApp_Scan_AddOneDTVPchVchs(U16, SI_SHORT_DTV_CHANNEL_INFO *, U8, BOOLEAN, BOOLEAN *) */
void TestSuit_MApp_Scan_test_MApp_Scan_AddOneDTVPchVchs_logic0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16PhysicalChIdx) */
    U16 _u16PhysicalChIdx  = 0u;
    /* Initializing argument 2 (pastVirtualCh) */
    SI_SHORT_DTV_CHANNEL_INFO temp = {0};
    SI_SHORT_DTV_CHANNEL_INFO * _pastVirtualCh  = &temp ;
    /* Initializing argument 3 (u8NumOfVch) */
    U8 _u8NumOfVch  = 1;
    /* Initializing argument 4 (bCheckServiceInfo) */
    U8 _bCheckServiceInfo  = 0;
    /* Initializing argument 5 (bDBfull) */
    BOOLEAN * _bDBfull  = 0 ;
    /* Initializing global variable _bFrequency_change */
    {
         _bFrequency_change  = 0;
    }
    /* Initializing global variable u16ScanDataChNum */
    {
         u16ScanDataChNum  = 0u;
    }
    /* Initializing global variable u16ScanRadioChNum */
    {
         u16ScanRadioChNum  = 0u;
    }
    /* Initializing global variable u16ScanDtvChNum */
    {
         u16ScanDtvChNum  = 0u;
    }
    /* Initializing global variable g_enScanType */
    {
         g_enScanType  = SCAN_TYPE_AUTO;
    }
    /* Initializing global variable _cOriginal_ChRF */
    {
         _cOriginal_ChRF  = 0;
    }
    /* Initializing global variable enLossSignalState */
    {
         enLossSignalState  = LOSS_SIGNAL_INIT;
    }
    {
        /* Tested function call */
        U8 _return  = MApp_Scan_AddOneDTVPchVchs(_u16PhysicalChIdx, _pastVirtualCh, _u8NumOfVch, _bCheckServiceInfo, _bDBfull);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0,_return);
       /* CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("SI_SHORT_DTV_CHANNEL_INFO * _pastVirtualCh ", ( _pastVirtualCh ));
        CPPTEST_POST_CONDITION_PTR("BOOLEAN * _bDBfull ", ( _bDBfull ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 _bFrequency_change", ( _bFrequency_change ));
        CPPTEST_POST_CONDITION_UINTEGER("U16 u16ScanDataChNum", ( u16ScanDataChNum ));
        CPPTEST_POST_CONDITION_UINTEGER("U16 u16ScanRadioChNum", ( u16ScanRadioChNum ));
        CPPTEST_POST_CONDITION_UINTEGER("U16 u16ScanDtvChNum", ( u16ScanDtvChNum ));
        CPPTEST_ASSERT_EQUAL( SCAN_TYPE_AUTO, ( g_enScanType ) )
        CPPTEST_POST_CONDITION_UINTEGER("BYTE _cOriginal_ChRF", ( _cOriginal_ChRF ));
        CPPTEST_ASSERT_EQUAL( LOSS_SIGNAL_INIT, ( enLossSignalState ) )*/
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Scan_AddOneDTVPchVchs_logic0 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Scan_AddOneDTVPchVchs_logic1 */
/* CPPTEST_TEST_CASE_CONTEXT U8 MApp_Scan_AddOneDTVPchVchs(U16, SI_SHORT_DTV_CHANNEL_INFO *, U8, BOOLEAN, BOOLEAN *) */
void TestSuit_MApp_Scan_test_MApp_Scan_AddOneDTVPchVchs_logic1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16PhysicalChIdx) */
    U16 _u16PhysicalChIdx  = 0u;
    /* Initializing argument 2 (pastVirtualCh) */
    SI_SHORT_DTV_CHANNEL_INFO temp = {0};
    SI_SHORT_DTV_CHANNEL_INFO * _pastVirtualCh  = &temp ;
    /* Initializing argument 3 (u8NumOfVch) */
    U8 _u8NumOfVch  = 1;
    /* Initializing argument 4 (bCheckServiceInfo) */
    U8 _bCheckServiceInfo  = 0;
    /* Initializing argument 5 (bDBfull) */
    BOOLEAN * _bDBfull  = 0 ;
  //  BYTE cLossSignalRF = INVALID_PHYSICAL_CHANNEL_NUMBER;
    /* Initializing global variable _bFrequency_change */
    {
         _bFrequency_change  = 0;
    }
    /* Initializing global variable u16ScanDataChNum */
    {
         u16ScanDataChNum  = 0u;
    }
    /* Initializing global variable u16ScanRadioChNum */
    {
         u16ScanRadioChNum  = 0u;
    }
    /* Initializing global variable u16ScanDtvChNum */
    {
         u16ScanDtvChNum  = 0u;
    }
    /* Initializing global variable g_enScanType */
    {
         g_enScanType  = SCAN_TYPE_AUTO;
    }
    /* Initializing global variable _cOriginal_ChRF */
    {
         _cOriginal_ChRF  = 0;
    }
    /* Initializing global variable enLossSignalState */
    {
         enLossSignalState  = LOSS_SIGNAL_INIT;


    }
    {
        /* Tested function call */
        U8 _return  = MApp_Scan_AddOneDTVPchVchs(_u16PhysicalChIdx, _pastVirtualCh, _u8NumOfVch, _bCheckServiceInfo, _bDBfull);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0,_return);
       /* CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("SI_SHORT_DTV_CHANNEL_INFO * _pastVirtualCh ", ( _pastVirtualCh ));
        CPPTEST_POST_CONDITION_PTR("BOOLEAN * _bDBfull ", ( _bDBfull ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 _bFrequency_change", ( _bFrequency_change ));
        CPPTEST_POST_CONDITION_UINTEGER("U16 u16ScanDataChNum", ( u16ScanDataChNum ));
        CPPTEST_POST_CONDITION_UINTEGER("U16 u16ScanRadioChNum", ( u16ScanRadioChNum ));
        CPPTEST_POST_CONDITION_UINTEGER("U16 u16ScanDtvChNum", ( u16ScanDtvChNum ));
        CPPTEST_ASSERT_EQUAL( SCAN_TYPE_AUTO, ( g_enScanType ) )
        CPPTEST_POST_CONDITION_UINTEGER("BYTE _cOriginal_ChRF", ( _cOriginal_ChRF ));
        CPPTEST_ASSERT_EQUAL( LOSS_SIGNAL_INIT, ( enLossSignalState ) ) */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Scan_AddOneDTVPchVchs_logic1 */
