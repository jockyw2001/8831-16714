#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app/MAPP_ChannelChange.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app/MAPP_ChannelChange.c");

CPPTEST_TEST_SUITE(TestSuite_MApp_ChannelChange);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_DEFAULT);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_MPEG);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AC3);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AC3P);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_MPEG4);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AAC);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_MPEG_AD);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AC3_AD);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AC3P_AD);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AACP_AD);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_DRA);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_ShowAnalogBanner_case_DEFAULT);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_ShowAnalogBanner_case_STATE_CHANNELCHANGE_INIT_if);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_ShowAnalogBanner_case_STATE_CHANNELCHANGE_INIT_else);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_ShowAnalogBanner_case_STATE_CHANNELCHANGE_DISPLAY);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_ShowEventInfoBanner);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_GoBackDataMode_if);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_GoBackDataMode_else);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelPosition_Restore);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_CheckBlockChannelPW);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_DEFAULT);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_DTV_if);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_DTV_else);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_ATV_if);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_ATV_else);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_AV_if);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_AV_else);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_if_if);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_if_else);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_else_if1);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_else_if2);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_else);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_VariableInit);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_KeyRepeatDelay_if);
CPPTEST_TEST(TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_KeyRepeatDelay_else);
CPPTEST_TEST_SUITE_END();


void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_DEFAULT();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_MPEG();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AC3();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AC3P();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_MPEG4();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AAC();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_MPEG_AD();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AC3_AD();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AC3P_AD();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AACP_AD();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_DRA();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_ShowAnalogBanner_case_DEFAULT();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_ShowAnalogBanner_case_STATE_CHANNELCHANGE_INIT_if();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_ShowAnalogBanner_case_STATE_CHANNELCHANGE_INIT_else();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_ShowAnalogBanner_case_STATE_CHANNELCHANGE_DISPLAY();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_ShowEventInfoBanner();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_GoBackDataMode_if();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_GoBackDataMode_else();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelPosition_Restore();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_CheckBlockChannelPW();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_DEFAULT();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_DTV_if();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_DTV_else();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_ATV_if();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_ATV_else();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_AV_if();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_AV_else();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_if_if();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_if_else();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_else_if1();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_else_if2();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_else();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_VariableInit();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_KeyRepeatDelay_if();
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_KeyRepeatDelay_else();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_MApp_ChannelChange);

void TestSuite_MApp_ChannelChange_setUp()
{
}

void TestSuite_MApp_ChannelChange_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_Set_Audio_Decoder_System_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ChannelChange_Set_Audio_Decoder_System(WORD) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wAudType) */
    WORD _wAudType  = E_AUDIOSTREAM_INVALID;
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.g_SysSetting.fSPDIFMODE = 0;
    }
    {
        /* Tested function call */
        MApp_ChannelChange_Set_Audio_Decoder_System(_wAudType);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_Set_Audio_Decoder_System_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_MPEG */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ChannelChange_Set_Audio_Decoder_System(WORD) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_MPEG()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wAudType) */
    WORD _wAudType  = E_AUDIOSTREAM_MPEG;
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.g_SysSetting.fSPDIFMODE = 0;
    }
    {
        /* Tested function call */
        MApp_ChannelChange_Set_Audio_Decoder_System(_wAudType);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_MPEG */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AC3 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ChannelChange_Set_Audio_Decoder_System(WORD) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AC3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wAudType) */
    WORD _wAudType  = E_AUDIOSTREAM_AC3;
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.g_SysSetting.fSPDIFMODE = 0;
    }
    {
        /* Tested function call */
        MApp_ChannelChange_Set_Audio_Decoder_System(_wAudType);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AC3 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AC3P */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ChannelChange_Set_Audio_Decoder_System(WORD) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AC3P()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wAudType) */
    WORD _wAudType  = E_AUDIOSTREAM_AC3P;
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.g_SysSetting.fSPDIFMODE = 1;
    }
    {
        /* Tested function call */
        MApp_ChannelChange_Set_Audio_Decoder_System(_wAudType);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AC3P */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_MPEG4 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ChannelChange_Set_Audio_Decoder_System(WORD) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_MPEG4()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wAudType) */
    WORD _wAudType  = E_AUDIOSTREAM_MPEG4;
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.g_SysSetting.fSPDIFMODE = 0;
    }
    {
        /* Tested function call */
        MApp_ChannelChange_Set_Audio_Decoder_System(_wAudType);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_MPEG4 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AAC */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ChannelChange_Set_Audio_Decoder_System(WORD) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AAC()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wAudType) */
    WORD _wAudType  = E_AUDIOSTREAM_AAC;
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.g_SysSetting.fSPDIFMODE = 1;
    }
    {
        /* Tested function call */
        MApp_ChannelChange_Set_Audio_Decoder_System(_wAudType);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AAC */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_MPEG_AD */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ChannelChange_Set_Audio_Decoder_System(WORD) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_MPEG_AD()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wAudType) */
    WORD _wAudType  = E_AUDIOSTREAM_MPEG_AD;
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.g_SysSetting.fSPDIFMODE = 0;
    }
    {
        /* Tested function call */
        MApp_ChannelChange_Set_Audio_Decoder_System(_wAudType);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_MPEG_AD */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AC3_AD */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ChannelChange_Set_Audio_Decoder_System(WORD) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AC3_AD()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wAudType) */
    WORD _wAudType  = E_AUDIOSTREAM_AC3_AD;
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.g_SysSetting.fSPDIFMODE = 0;
    }
    {
        /* Tested function call */
        MApp_ChannelChange_Set_Audio_Decoder_System(_wAudType);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AC3_AD */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AC3P_AD */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ChannelChange_Set_Audio_Decoder_System(WORD) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AC3P_AD()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wAudType) */
    WORD _wAudType  = E_AUDIOSTREAM_AC3P_AD;
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.g_SysSetting.fSPDIFMODE = 0;
    }
    {
        /* Tested function call */
        MApp_ChannelChange_Set_Audio_Decoder_System(_wAudType);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AC3P_AD */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AACP_AD */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ChannelChange_Set_Audio_Decoder_System(WORD) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AACP_AD()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wAudType) */
    WORD _wAudType  = E_AUDIOSTREAM_AACP_AD;
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.g_SysSetting.fSPDIFMODE = 0;
    }
    {
        /* Tested function call */
        MApp_ChannelChange_Set_Audio_Decoder_System(_wAudType);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_AACP_AD */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_DRA */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ChannelChange_Set_Audio_Decoder_System(WORD) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_DRA()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wAudType) */
    WORD _wAudType  = E_AUDIOSTREAM_DRA;
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.g_SysSetting.fSPDIFMODE = 0;
    }
    {
        /* Tested function call */
        MApp_ChannelChange_Set_Audio_Decoder_System(_wAudType);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_Set_Audio_Decoder_System_case_E_AUDIOSTREAM_DRA */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_ShowAnalogBanner_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT EN_RET MApp_ChannelChange_ShowAnalogBanner(void) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_ShowAnalogBanner_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bRealTimeMonitorOnly */
    {
         g_bRealTimeMonitorOnly  = 0;
    }
    /* Initializing global variable enChannelChangeRetVal */
    {
         enChannelChangeRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable enChannelChangeState */
    {
         enChannelChangeState  = STATE_CHANNELCHANGE_EXIT;
    }
    /* Initializing global variable u32ChannelChangeTimer */
    {
         u32ChannelChangeTimer  = 0ul;
    }
    {
        /* Tested function call */
        EN_RET _return  = MApp_ChannelChange_ShowAnalogBanner();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(EXIT_NULL, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_ShowAnalogBanner_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_ShowAnalogBanner_case_STATE_CHANNELCHANGE_INIT_if */
/* CPPTEST_TEST_CASE_CONTEXT EN_RET MApp_ChannelChange_ShowAnalogBanner(void) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_ShowAnalogBanner_case_STATE_CHANNELCHANGE_INIT_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bRealTimeMonitorOnly */
    {
         g_bRealTimeMonitorOnly  = 0;
    }
    /* Initializing global variable enChannelChangeRetVal */
    {
         enChannelChangeRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable enChannelChangeState */
    {
         enChannelChangeState  = STATE_CHANNELCHANGE_INIT;
    }
    /* Initializing global variable u32ChannelChangeTimer */
    {
         u32ChannelChangeTimer  = 0ul;
    }
    {
        /* Tested function call */
        EN_RET _return  = MApp_ChannelChange_ShowAnalogBanner();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(EXIT_NULL, ( _return ));
        CPPTEST_ASSERT_EQUAL(STATE_CHANNELCHANGE_DISPLAY, ( enChannelChangeState ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_ShowAnalogBanner_case_STATE_CHANNELCHANGE_INIT_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_ShowAnalogBanner_case_STATE_CHANNELCHANGE_INIT_else */
/* CPPTEST_TEST_CASE_CONTEXT EN_RET MApp_ChannelChange_ShowAnalogBanner(void) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_ShowAnalogBanner_case_STATE_CHANNELCHANGE_INIT_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bRealTimeMonitorOnly */
    {
         g_bRealTimeMonitorOnly  = 0;
    }
    /* Initializing global variable enChannelChangeRetVal */
    {
         enChannelChangeRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable enChannelChangeState */
    {
         enChannelChangeState  = STATE_CHANNELCHANGE_INIT;
    }
    /* Initializing global variable u32ChannelChangeTimer */
    {
         u32ChannelChangeTimer  = 0ul;
    }
    {
        /* Tested function call */
        EN_RET _return  = MApp_ChannelChange_ShowAnalogBanner();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(EXIT_NULL, ( _return ));
        CPPTEST_ASSERT_EQUAL(STATE_CHANNELCHANGE_DISPLAY, ( enChannelChangeState ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_ShowAnalogBanner_case_STATE_CHANNELCHANGE_INIT_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_ShowAnalogBanner_case_STATE_CHANNELCHANGE_DISPLAY */
/* CPPTEST_TEST_CASE_CONTEXT EN_RET MApp_ChannelChange_ShowAnalogBanner(void) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_ShowAnalogBanner_case_STATE_CHANNELCHANGE_DISPLAY()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bRealTimeMonitorOnly */
    {
         g_bRealTimeMonitorOnly  = 0;
    }
    /* Initializing global variable enChannelChangeRetVal */
    {
         enChannelChangeRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_MENU;
    }
    /* Initializing global variable enChannelChangeState */
    {
         enChannelChangeState  = STATE_CHANNELCHANGE_DISPLAY;
    }
    /* Initializing global variable u32ChannelChangeTimer */
    {
         u32ChannelChangeTimer  = 0ul;
    }
    {
        /* Tested function call */
        EN_RET _return  = MApp_ChannelChange_ShowAnalogBanner();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(EXIT_CLOSE, ( _return ));
        CPPTEST_ASSERT_EQUAL(STATE_CHANNELCHANGE_INIT, ( enChannelChangeState ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_ShowAnalogBanner_case_STATE_CHANNELCHANGE_DISPLAY */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_ShowEventInfoBanner */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ChannelChange_ShowEventInfoBanner(void) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_ShowEventInfoBanner()
{
    /* Pre-condition initialization */
    /* Initializing global variable enChannelChangeState */
    {
         enChannelChangeState  = STATE_CHANNELCHANGE_INIT;
    }
    {
        /* Tested function call */
        MApp_ChannelChange_ShowEventInfoBanner();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_CHANNELCHANGE_DISPLAY, ( enChannelChangeState ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_ShowEventInfoBanner */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_GoBackDataMode_if */
/* CPPTEST_TEST_CASE_CONTEXT EN_RET MApp_ChannelChange_GoBackDataMode(void) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_GoBackDataMode_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable u32AC3CheckTimer */
    {
         u32AC3CheckTimer  = 0ul;
    }
    /* Initializing global variable bEnableAC3Check */
    {
         bEnableAC3Check  = 0;
    }
    /* Initializing global variable u8AC3CheckTimes */
    {
         u8AC3CheckTimes  = 0;
    }
    /* Initializing global variable g_u16Current_PCRPID */
    {
         g_u16Current_PCRPID  = 0u;
    }
    /* Initializing global variable g_u16Current_PVR_VideoPID */
    {
         g_u16Current_PVR_VideoPID  = 0u;
    }
    /* Initializing global variable g_u16Current_PVR_AudioPID */
    {
         g_u16Current_PVR_AudioPID  = 0u;
    }
    /* Initializing global variable g_wCurrent_AudioType */
    {
         g_wCurrent_AudioType  = 0u;
    }
    /* Initializing global variable g_eCurrent_PVR_VideoType */
    {
         g_eCurrent_PVR_VideoType  = E_VDEC_CODEC_TYPE_NONE;
    }
    /* Initializing global variable g_u16Current_AudioDescriptorPID */
    {
         g_u16Current_AudioDescriptorPID  = 0u;
    }
    /* Initializing global variable bH264FirstTimeCheck */
    {
         bH264FirstTimeCheck  = 0;
    }
    /* Initializing global variable g_u8AdAudSelected */
    {
         g_u8AdAudSelected  = 0;
    }
    /* Initializing global variable gCurValidSubtitleIndex */
    {
         gCurValidSubtitleIndex  = 0ul;
    }
    /* Initializing global variable bStopMonitorBlock */
    {
         bStopMonitorBlock  = 0;
    }
    /* Initializing global variable g_u16MHEG5_VideoPID */
    {
         g_u16MHEG5_VideoPID  = 0u;
    }
    /* Initializing global variable g_eCurrent_VideoType */
    {
         g_eCurrent_VideoType  = E_VDEC_CODEC_TYPE_NONE;
    }
    /* Initializing global variable enChannelChangeRetVal */
    {
         enChannelChangeRetVal  = EXIT_NULL;
    }
    /* Initializing global variable g_eCurrentRealServiceType */
    {
         g_eCurrentRealServiceType  = E_SERVICETYPE_ATV;
    }
    /* Initializing global variable g_wCurrentRadioRealServicePosition */
    {
         g_wCurrentRadioRealServicePosition  = 0u;
    }
    /* Initializing global variable g_wCurrentRadioUserServicePosition */
    {
         g_wCurrentRadioUserServicePosition  = 0u;
    }
    /* Initializing global variable g_wCurrentDataRealServicePosition */
    {
         g_wCurrentDataRealServicePosition  = 0u;
    }
    /* Initializing global variable g_wCurrentDataUserServicePosition */
    {
         g_wCurrentDataUserServicePosition  = 0u;
    }
    /* Initializing global variable g_wCurrentTVRealServicePosition */
    {
         g_wCurrentTVRealServicePosition  = 0u;
    }
    /* Initializing global variable g_wCurrentTVUserServicePosition */
    {
         g_wCurrentTVUserServicePosition  = 0u;
    }
    /* Initializing global variable g_u16CurrentServiceID */
    {
         g_u16CurrentServiceID  = 0u;
    }
    /* Initializing global variable g_wCurrentTS_ID */
    {
         g_wCurrentTS_ID  = 0u;
    }
    /* Initializing global variable g_wCurrent_ONID */
    {
         g_wCurrent_ONID  = 0u;
    }
    /* Initializing global variable bParentalPWPassCheck */
    {
         bParentalPWPassCheck  = 0;
    }
    /* Initializing global variable bCheckBlockPW */
    {
         bCheckBlockPW  = 0;
    }
    /* Initializing global variable bCheckParentalPW */
    {
         bCheckParentalPW  = 0;
    }
    /* Initializing global variable g_u8AudLangSelected */
    {
         g_u8AudLangSelected  = 0;
    }
    /* Initializing global variable g_bMHEG5Service */
    {
         g_bMHEG5Service  = 0;
    }
    /* Initializing global variable g_eCodecType */
    {
         g_eCodecType  = E_VDEC_CODEC_TYPE_NONE;
    }
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable gbBootTimeFinish */
    {
#if (ENABLE_AUTOTEST || ENABLE_BOOTTIME)
         gbBootTimeFinish  = 0;
#endif
    }
    /* Initializing global variable gU32TmpTime */
    {
#if (ENABLE_AUTOTEST || ENABLE_BOOTTIME || ENABLE_CHCHANGETIME )
         gU32TmpTime  = 0ul;
#endif
    }
    /* Initializing global variable gU32BootTime */
    {
#if (ENABLE_AUTOTEST || ENABLE_BOOTTIME)
         gU32BootTime  = 0ul;
#endif
    }
    /* Initializing global variable fEnableMvdTimingMonitor */
    {
         fEnableMvdTimingMonitor  = 0;
    }
    /* Initializing global variable g_u16MHEG5_AudioPID */
    {
         g_u16MHEG5_AudioPID  = 0u;
    }
    /* Initializing global variable g_u16Current_AudioType */
    {
         g_u16Current_AudioType  = 0u;
    }
#if 0
    /* Initializing global variable u16AudioPID */
    {
         u16AudioPID  = 0u;
    }
    /* Initializing global variable u16AudioType */
    {
         u16AudioType  = 0u;
    }
#endif
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable g_bIsImageFrozen */
    {
         g_bIsImageFrozen  = 0;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable fWaitforMSGBoxFading */
    {
         fWaitforMSGBoxFading  = 0;
    }
    /* Initializing global variable fEnableSignalMonitor */
    {
         fEnableSignalMonitor  = 0;
    }
    /* Initializing global variable g_MHEG5Video */
    {
         g_MHEG5Video.bFullScreen  = 0;
         g_MHEG5Video.bPrevFullScreen  = 0;
         g_MHEG5Video.bIFrame  = 0;
         g_MHEG5Video.bHaveVideo  = 0;
         g_MHEG5Video.bARCChange  = 0;
         g_MHEG5Video.bARCAdj_V  = 0;
         g_MHEG5Video.bARCAdj_H  = 0;
         g_MHEG5Video.bVideoActionNotRdy  = 0;
         g_MHEG5Video.bRecodeMVDDONE  = 0;
         g_MHEG5Video.u8VideoFlag  = 0;
         g_MHEG5Video.u8PrevVideoFlag  = 0;
         g_MHEG5Video.u8VideoFlag2  = 0;
         g_MHEG5Video.u8ARC_Control  = 0;
         g_MHEG5Video.active_status  = 0;
         g_MHEG5Video.KEEP_STATUS  = 0;
         g_MHEG5Video.PrevKEEP_STATUS  = 0;
         g_MHEG5Video.u8VCapStartPatchOffset  = 0;
         g_MHEG5Video.eWAM  = EN_MHEG5_WAM_Min;
         g_MHEG5Video.Pre_eWAM  = EN_MHEG5_WAM_Min;
         g_MHEG5Video.eSceneAspectRatio  = EN_MHEG5_SceneAspectRatio_Min;
         g_MHEG5Video.eSceneAspectRatio_FromTransitionTo  = EN_MHEG5_SceneAspectRatio_Min;
         g_MHEG5Video.Pre_eSceneAspectRatio  = EN_MHEG5_SceneAspectRatio_Min;
    }
    /* Initializing global variable g_u16Current_VideoPID */
    {
         g_u16Current_VideoPID  = INVALID_SERVICE_ID;
    }
    /* Initializing global variable g_u16Current_AudioPID */
    {
         g_u16Current_AudioPID  = 0u;
    }
    /* Initializing global variable g_u16Current_ServicePosition */
    {
         g_u16Current_ServicePosition  = 0u;
    }
    /* Initializing global variable g_PIDfromMHEG5 */
    {
         g_PIDfromMHEG5  = 0;
    }
    /* Initializing global variable _bBackDataProgram */
    {
         _bBackDataProgram  = 0;
    }
    /* Initializing global variable u32ChkTry2ChgMpeg2Time */
    {
         u32ChkTry2ChgMpeg2Time  = 0ul;
    }
    /* Initializing global variable enFrotEndLockStatus */
    {
         enFrotEndLockStatus  = FRONTEND_UNKNOWN;
    }
    /* Initializing global variable enMVDVideoStatus */
    {
         enMVDVideoStatus  = MVD_UNKNOWN_VIDEO;
    }
    /* Initializing global variable enChannelChangeState */
    {
         enChannelChangeState  = STATE_CHANNELCHANGE_INIT;
    }
    /* Initializing global variable g_eCurrentUserServiceType */
    {
         g_eCurrentUserServiceType  = E_SERVICETYPE_ATV;
    }
    /* Initializing global variable u32ChannelChangeTimer */
    {
         u32ChannelChangeTimer  = 0ul;
    }
    {
        /* Tested function call */
        EN_RET _return  = MApp_ChannelChange_GoBackDataMode();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_GoBackDataMode_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_GoBackDataMode_else */
/* CPPTEST_TEST_CASE_CONTEXT EN_RET MApp_ChannelChange_GoBackDataMode(void) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_GoBackDataMode_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable u32AC3CheckTimer */
    {
         u32AC3CheckTimer  = 0ul;
    }
    /* Initializing global variable bEnableAC3Check */
    {
         bEnableAC3Check  = 0;
    }
    /* Initializing global variable u8AC3CheckTimes */
    {
         u8AC3CheckTimes  = 0;
    }
    /* Initializing global variable g_u16Current_PCRPID */
    {
         g_u16Current_PCRPID  = 0u;
    }
    /* Initializing global variable g_u16Current_PVR_VideoPID */
    {
         g_u16Current_PVR_VideoPID  = 0u;
    }
    /* Initializing global variable g_u16Current_PVR_AudioPID */
    {
         g_u16Current_PVR_AudioPID  = 0u;
    }
    /* Initializing global variable g_wCurrent_AudioType */
    {
         g_wCurrent_AudioType  = 0u;
    }
    /* Initializing global variable g_eCurrent_PVR_VideoType */
    {
         g_eCurrent_PVR_VideoType  = E_VDEC_CODEC_TYPE_NONE;
    }
    /* Initializing global variable g_u16Current_AudioDescriptorPID */
    {
         g_u16Current_AudioDescriptorPID  = 0u;
    }
    /* Initializing global variable bH264FirstTimeCheck */
    {
         bH264FirstTimeCheck  = 0;
    }
    /* Initializing global variable g_u8AdAudSelected */
    {
         g_u8AdAudSelected  = 0;
    }
    /* Initializing global variable gCurValidSubtitleIndex */
    {
         gCurValidSubtitleIndex  = 0ul;
    }
    /* Initializing global variable bStopMonitorBlock */
    {
         bStopMonitorBlock  = 0;
    }
    /* Initializing global variable g_u16MHEG5_VideoPID */
    {
         g_u16MHEG5_VideoPID  = 0u;
    }
    /* Initializing global variable g_eCurrent_VideoType */
    {
         g_eCurrent_VideoType  = E_VDEC_CODEC_TYPE_NONE;
    }
    /* Initializing global variable enChannelChangeRetVal */
    {
         enChannelChangeRetVal  = EXIT_NULL;
    }
    /* Initializing global variable g_eCurrentRealServiceType */
    {
         g_eCurrentRealServiceType  = E_SERVICETYPE_ATV;
    }
    /* Initializing global variable g_wCurrentRadioRealServicePosition */
    {
         g_wCurrentRadioRealServicePosition  = 0u;
    }
    /* Initializing global variable g_wCurrentRadioUserServicePosition */
    {
         g_wCurrentRadioUserServicePosition  = 0u;
    }
    /* Initializing global variable g_wCurrentDataRealServicePosition */
    {
         g_wCurrentDataRealServicePosition  = 0u;
    }
    /* Initializing global variable g_wCurrentDataUserServicePosition */
    {
         g_wCurrentDataUserServicePosition  = 0u;
    }
    /* Initializing global variable g_wCurrentTVRealServicePosition */
    {
         g_wCurrentTVRealServicePosition  = 0u;
    }
    /* Initializing global variable g_wCurrentTVUserServicePosition */
    {
         g_wCurrentTVUserServicePosition  = 0u;
    }
    /* Initializing global variable g_u16CurrentServiceID */
    {
         g_u16CurrentServiceID  = 0u;
    }
    /* Initializing global variable g_wCurrentTS_ID */
    {
         g_wCurrentTS_ID  = 0u;
    }
    /* Initializing global variable g_wCurrent_ONID */
    {
         g_wCurrent_ONID  = 0u;
    }
    /* Initializing global variable bParentalPWPassCheck */
    {
         bParentalPWPassCheck  = 0;
    }
    /* Initializing global variable bCheckBlockPW */
    {
         bCheckBlockPW  = 0;
    }
    /* Initializing global variable bCheckParentalPW */
    {
         bCheckParentalPW  = 0;
    }
    /* Initializing global variable g_u8AudLangSelected */
    {
         g_u8AudLangSelected  = 0;
    }
    /* Initializing global variable g_bMHEG5Service */
    {
         g_bMHEG5Service  = 0;
    }
    /* Initializing global variable g_eCodecType */
    {
         g_eCodecType  = E_VDEC_CODEC_TYPE_NONE;
    }
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable gbBootTimeFinish */
    {
#if (ENABLE_AUTOTEST || ENABLE_BOOTTIME)
         gbBootTimeFinish  = 0;
#endif
    }
    /* Initializing global variable gU32TmpTime */
    {
#if (ENABLE_AUTOTEST || ENABLE_BOOTTIME || ENABLE_CHCHANGETIME )
         gU32TmpTime  = 0ul;
#endif
    }
    /* Initializing global variable gU32BootTime */
    {
#if (ENABLE_AUTOTEST || ENABLE_BOOTTIME)
         gU32BootTime  = 0ul;
#endif
    }
    /* Initializing global variable fEnableMvdTimingMonitor */
    {
         fEnableMvdTimingMonitor  = 0;
    }
    /* Initializing global variable g_u16MHEG5_AudioPID */
    {
         g_u16MHEG5_AudioPID  = 0u;
    }
    /* Initializing global variable g_u16Current_AudioType */
    {
         g_u16Current_AudioType  = 0u;
    }
#if 0
    /* Initializing global variable u16AudioPID */
    {
         u16AudioPID  = 0u;
    }
    /* Initializing global variable u16AudioType */
    {
         u16AudioType  = 0u;
    }
#endif
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable g_bIsImageFrozen */
    {
         g_bIsImageFrozen  = 0;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable fWaitforMSGBoxFading */
    {
         fWaitforMSGBoxFading  = 0;
    }
    /* Initializing global variable fEnableSignalMonitor */
    {
         fEnableSignalMonitor  = 0;
    }
    /* Initializing global variable g_MHEG5Video */
    {
         g_MHEG5Video.bFullScreen  = 0;
         g_MHEG5Video.bPrevFullScreen  = 0;
         g_MHEG5Video.bIFrame  = 0;
         g_MHEG5Video.bHaveVideo  = 0;
         g_MHEG5Video.bARCChange  = 0;
         g_MHEG5Video.bARCAdj_V  = 0;
         g_MHEG5Video.bARCAdj_H  = 0;
         g_MHEG5Video.bVideoActionNotRdy  = 0;
         g_MHEG5Video.bRecodeMVDDONE  = 0;
         g_MHEG5Video.u8VideoFlag  = 0;
         g_MHEG5Video.u8PrevVideoFlag  = 0;
         g_MHEG5Video.u8VideoFlag2  = 0;
         g_MHEG5Video.u8ARC_Control  = 0;
         g_MHEG5Video.active_status  = 0;
         g_MHEG5Video.KEEP_STATUS  = 0;
         g_MHEG5Video.PrevKEEP_STATUS  = 0;
         g_MHEG5Video.u8VCapStartPatchOffset  = 0;
         g_MHEG5Video.eWAM  = EN_MHEG5_WAM_Min;
         g_MHEG5Video.Pre_eWAM  = EN_MHEG5_WAM_Min;
         g_MHEG5Video.eSceneAspectRatio  = EN_MHEG5_SceneAspectRatio_Min;
         g_MHEG5Video.eSceneAspectRatio_FromTransitionTo  = EN_MHEG5_SceneAspectRatio_Min;
         g_MHEG5Video.Pre_eSceneAspectRatio  = EN_MHEG5_SceneAspectRatio_Min;
    }
    /* Initializing global variable g_u16Current_VideoPID */
    {
         g_u16Current_VideoPID  = INVALID_PID;
    }
    /* Initializing global variable g_u16Current_AudioPID */
    {
         g_u16Current_AudioPID  = 0u;
    }
    /* Initializing global variable g_u16Current_ServicePosition */
    {
         g_u16Current_ServicePosition  = 0u;
    }
    /* Initializing global variable g_PIDfromMHEG5 */
    {
         g_PIDfromMHEG5  = 0;
    }
    /* Initializing global variable _bBackDataProgram */
    {
         _bBackDataProgram  = 0;
    }
    /* Initializing global variable u32ChkTry2ChgMpeg2Time */
    {
         u32ChkTry2ChgMpeg2Time  = 0ul;
    }
    /* Initializing global variable enFrotEndLockStatus */
    {
         enFrotEndLockStatus  = FRONTEND_UNKNOWN;
    }
    /* Initializing global variable enMVDVideoStatus */
    {
         enMVDVideoStatus  = MVD_UNKNOWN_VIDEO;
    }
    /* Initializing global variable enChannelChangeState */
    {
         enChannelChangeState  = STATE_CHANNELCHANGE_INIT;
    }
    /* Initializing global variable g_eCurrentUserServiceType */
    {
         g_eCurrentUserServiceType  = E_SERVICETYPE_ATV;
    }
    /* Initializing global variable u32ChannelChangeTimer */
    {
         u32ChannelChangeTimer  = 0ul;
    }
    {
        /* Tested function call */
        EN_RET _return  = MApp_ChannelChange_GoBackDataMode();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_GoBackDataMode_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelPosition_Restore */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ChannelPosition_Restore(void) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelPosition_Restore()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_eCurrentRealServiceType */
    {
         g_eCurrentRealServiceType  = E_SERVICETYPE_ATV;
    }
    /* Initializing global variable g_wCurrentRadioRealServicePosition */
    {
         g_wCurrentRadioRealServicePosition  = 0u;
    }
    /* Initializing global variable g_wCurrentRadioUserServicePosition */
    {
         g_wCurrentRadioUserServicePosition  = 0u;
    }
    /* Initializing global variable g_wCurrentDataRealServicePosition */
    {
         g_wCurrentDataRealServicePosition  = 0u;
    }
    /* Initializing global variable g_wCurrentDataUserServicePosition */
    {
         g_wCurrentDataUserServicePosition  = 0u;
    }
    /* Initializing global variable g_wCurrentTVRealServicePosition */
    {
         g_wCurrentTVRealServicePosition  = 0u;
    }
    /* Initializing global variable g_wCurrentTVUserServicePosition */
    {
         g_wCurrentTVUserServicePosition  = 0u;
    }
    /* Initializing global variable g_eCurrentUserServiceType */
    {
         g_eCurrentUserServiceType  = E_SERVICETYPE_ATV;
    }
    {
        /* Tested function call */
        MApp_ChannelPosition_Restore();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelPosition_Restore */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_CheckBlockChannelPW */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ChannelChange_CheckBlockChannelPW(void) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_CheckBlockChannelPW()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        MApp_ChannelChange_CheckBlockChannelPW();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_CheckBlockChannelPW */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_DetectSignalStatus_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT EN_DETECT_SIGNAL_STATE MApp_ChannelChange_DetectSignalStatus(E_UI_INPUT_SOURCE) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (input_type) */
    E_UI_INPUT_SOURCE _input_type  = UI_INPUT_SOURCE_NUM;
    /* Initializing global variable g_bPCSignalMonitor */
    {
         g_bPCSignalMonitor  = 0;
    }
    /* Initializing global variable g_u8PCSignalMonitorCounter */
    {
         g_u8PCSignalMonitorCounter  = 0;
    }
    {
        /* Tested function call */
        EN_DETECT_SIGNAL_STATE _return  = MApp_ChannelChange_DetectSignalStatus(_input_type);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_DETECT_SIGNAL_ERROR, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_DetectSignalStatus_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_DTV_if */
/* CPPTEST_TEST_CASE_CONTEXT EN_DETECT_SIGNAL_STATE MApp_ChannelChange_DetectSignalStatus(E_UI_INPUT_SOURCE) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_DTV_if()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (input_type) */
    E_UI_INPUT_SOURCE _input_type  = UI_INPUT_SOURCE_DTV;
    /* Initializing global variable g_bPCSignalMonitor */
    {
         g_bPCSignalMonitor  = 0;
    }
    /* Initializing global variable g_u8PCSignalMonitorCounter */
    {
         g_u8PCSignalMonitorCounter  = 0;
    }
    {
        /* Tested function call */
        EN_DETECT_SIGNAL_STATE _return  = MApp_ChannelChange_DetectSignalStatus(_input_type);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_DETECT_SIGNAL_NOSIGNAL, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_DTV_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_DTV_else */
/* CPPTEST_TEST_CASE_CONTEXT EN_DETECT_SIGNAL_STATE MApp_ChannelChange_DetectSignalStatus(E_UI_INPUT_SOURCE) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_DTV_else()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (input_type) */
    E_UI_INPUT_SOURCE _input_type  = UI_INPUT_SOURCE_DTV;
    /* Initializing global variable g_bPCSignalMonitor */
    {
         g_bPCSignalMonitor  = 0;
    }
    /* Initializing global variable g_u8PCSignalMonitorCounter */
    {
         g_u8PCSignalMonitorCounter  = 0;
    }
    {
        /* Tested function call */
        EN_DETECT_SIGNAL_STATE _return  = MApp_ChannelChange_DetectSignalStatus(_input_type);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_DETECT_SIGNAL_OK, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_DTV_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_ATV_if */
/* CPPTEST_TEST_CASE_CONTEXT EN_DETECT_SIGNAL_STATE MApp_ChannelChange_DetectSignalStatus(E_UI_INPUT_SOURCE) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_ATV_if()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (input_type) */
    E_UI_INPUT_SOURCE _input_type  = UI_INPUT_SOURCE_ATV;
    /* Initializing global variable g_bPCSignalMonitor */
    {
         g_bPCSignalMonitor  = 0;
    }
    /* Initializing global variable g_u8PCSignalMonitorCounter */
    {
         g_u8PCSignalMonitorCounter  = 0;
    }
    {
        /* Tested function call */
        EN_DETECT_SIGNAL_STATE _return  = MApp_ChannelChange_DetectSignalStatus(_input_type);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_DETECT_SIGNAL_NOSIGNAL, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_ATV_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_ATV_else */
/* CPPTEST_TEST_CASE_CONTEXT EN_DETECT_SIGNAL_STATE MApp_ChannelChange_DetectSignalStatus(E_UI_INPUT_SOURCE) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_ATV_else()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (input_type) */
    E_UI_INPUT_SOURCE _input_type  = UI_INPUT_SOURCE_ATV;
    /* Initializing global variable g_bPCSignalMonitor */
    {
         g_bPCSignalMonitor  = 0;
    }
    /* Initializing global variable g_u8PCSignalMonitorCounter */
    {
         g_u8PCSignalMonitorCounter  = 0;
    }
    {
        /* Tested function call */
        EN_DETECT_SIGNAL_STATE _return  = MApp_ChannelChange_DetectSignalStatus(_input_type);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_DETECT_SIGNAL_OK, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_ATV_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_AV_if */
/* CPPTEST_TEST_CASE_CONTEXT EN_DETECT_SIGNAL_STATE MApp_ChannelChange_DetectSignalStatus(E_UI_INPUT_SOURCE) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_AV_if()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (input_type) */
    E_UI_INPUT_SOURCE _input_type  = UI_INPUT_SOURCE_AV;
    /* Initializing global variable g_bPCSignalMonitor */
    {
         g_bPCSignalMonitor  = 0;
    }
    /* Initializing global variable g_u8PCSignalMonitorCounter */
    {
         g_u8PCSignalMonitorCounter  = 0;
    }
    {
        /* Tested function call */
        EN_DETECT_SIGNAL_STATE _return  = MApp_ChannelChange_DetectSignalStatus(_input_type);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_DETECT_SIGNAL_NOSIGNAL, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_AV_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_AV_else */
/* CPPTEST_TEST_CASE_CONTEXT EN_DETECT_SIGNAL_STATE MApp_ChannelChange_DetectSignalStatus(E_UI_INPUT_SOURCE) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_AV_else()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (input_type) */
    E_UI_INPUT_SOURCE _input_type  = UI_INPUT_SOURCE_AV;
    /* Initializing global variable g_bPCSignalMonitor */
    {
         g_bPCSignalMonitor  = 0;
    }
    /* Initializing global variable g_u8PCSignalMonitorCounter */
    {
         g_u8PCSignalMonitorCounter  = 0;
    }
    {
        /* Tested function call */
        EN_DETECT_SIGNAL_STATE _return  = MApp_ChannelChange_DetectSignalStatus(_input_type);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_DETECT_SIGNAL_OK, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_AV_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_if_if */
/* CPPTEST_TEST_CASE_CONTEXT EN_DETECT_SIGNAL_STATE MApp_ChannelChange_DetectSignalStatus(E_UI_INPUT_SOURCE) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_if_if()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (input_type) */
    E_UI_INPUT_SOURCE _input_type  = UI_INPUT_SOURCE_RGB;
    /* Initializing global variable g_bPCSignalMonitor */
    {
         g_bPCSignalMonitor  = 1;
    }
    /* Initializing global variable g_u8PCSignalMonitorCounter */
    {
         g_u8PCSignalMonitorCounter  = 9;
         //U8 _u8Test = g_u8PCSignalMonitorCounter+1;
    }
    {
        /* Tested function call */
        EN_DETECT_SIGNAL_STATE _return  = MApp_ChannelChange_DetectSignalStatus(_input_type);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_DETECT_SIGNAL_INPROGRESS_NOSIGNAL, ( _return ) );
        CPPTEST_ASSERT_EQUAL( FALSE, ( g_bPCSignalMonitor ) );
        //CPPTEST_ASSERT_EQUAL( _u8Test, ( g_u8PCSignalMonitorCounter ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_if_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_if_else */
/* CPPTEST_TEST_CASE_CONTEXT EN_DETECT_SIGNAL_STATE MApp_ChannelChange_DetectSignalStatus(E_UI_INPUT_SOURCE) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_if_else()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (input_type) */
    E_UI_INPUT_SOURCE _input_type  = UI_INPUT_SOURCE_RGB;
    /* Initializing global variable g_bPCSignalMonitor */
    {
         g_bPCSignalMonitor  = 1;
    }
    /* Initializing global variable g_u8PCSignalMonitorCounter */
    {
         g_u8PCSignalMonitorCounter  = 10;
    }
    {
        /* Tested function call */
        EN_DETECT_SIGNAL_STATE _return  = MApp_ChannelChange_DetectSignalStatus(_input_type);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_DETECT_SIGNAL_NOSIGNAL, ( _return ) );
        CPPTEST_ASSERT_EQUAL( FALSE, ( g_bPCSignalMonitor ) );
        CPPTEST_ASSERT_EQUAL( 0, ( g_u8PCSignalMonitorCounter ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_if_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_else_if1 */
/* CPPTEST_TEST_CASE_CONTEXT EN_DETECT_SIGNAL_STATE MApp_ChannelChange_DetectSignalStatus(E_UI_INPUT_SOURCE) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_else_if1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (input_type) */
    E_UI_INPUT_SOURCE _input_type  = UI_INPUT_SOURCE_RGB;
    /* Initializing global variable g_bPCSignalMonitor */
    {
         g_bPCSignalMonitor  = 1;
    }
    /* Initializing global variable g_u8PCSignalMonitorCounter */
    {
         g_u8PCSignalMonitorCounter  = 0;
    }
    {
        /* Tested function call */
        EN_DETECT_SIGNAL_STATE _return  = MApp_ChannelChange_DetectSignalStatus(_input_type);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_DETECT_SIGNAL_PC_UNSUPPORT_MODE, ( _return ) );
        CPPTEST_ASSERT_EQUAL( FALSE, ( g_bPCSignalMonitor ) );
        CPPTEST_ASSERT_EQUAL( 0, ( g_u8PCSignalMonitorCounter ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_else_if1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_else_if2 */
/* CPPTEST_TEST_CASE_CONTEXT EN_DETECT_SIGNAL_STATE MApp_ChannelChange_DetectSignalStatus(E_UI_INPUT_SOURCE) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_else_if2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (input_type) */
    E_UI_INPUT_SOURCE _input_type  = UI_INPUT_SOURCE_RGB;
    /* Initializing global variable g_bPCSignalMonitor */
    {
         g_bPCSignalMonitor  = 0;
    }
    /* Initializing global variable g_u8PCSignalMonitorCounter */
    {
         g_u8PCSignalMonitorCounter  = 0;
    }
    {
        /* Tested function call */
        EN_DETECT_SIGNAL_STATE _return  = MApp_ChannelChange_DetectSignalStatus(_input_type);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_DETECT_SIGNAL_INPROGRESS_NOSIGNAL, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_else_if2 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_else */
/* CPPTEST_TEST_CASE_CONTEXT EN_DETECT_SIGNAL_STATE MApp_ChannelChange_DetectSignalStatus(E_UI_INPUT_SOURCE) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_else()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (input_type) */
    E_UI_INPUT_SOURCE _input_type  = UI_INPUT_SOURCE_RGB;
    /* Initializing global variable g_bPCSignalMonitor */
    {
         g_bPCSignalMonitor  = 1;
    }
    /* Initializing global variable g_u8PCSignalMonitorCounter */
    {
         g_u8PCSignalMonitorCounter  = 9;
    }
    {
        /* Tested function call */
        EN_DETECT_SIGNAL_STATE _return  = MApp_ChannelChange_DetectSignalStatus(_input_type);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_DETECT_SIGNAL_OK, ( _return ) );
        CPPTEST_ASSERT_EQUAL( FALSE, ( g_bPCSignalMonitor ) );
        CPPTEST_ASSERT_EQUAL( 0, ( g_u8PCSignalMonitorCounter ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_VariableInit */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ChannelChange_VariableInit(void) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_VariableInit()
{
    /* Pre-condition initialization */
    /* Initializing global variable enChannelChangeState */
    {
         enChannelChangeState  = STATE_CHANNELCHANGE_INIT;
    }
    /* Initializing global variable g_eCurrentUserServiceType */
    {
         g_eCurrentUserServiceType  = E_SERVICETYPE_ATV;
    }
    {
        /* Tested function call */
        MApp_ChannelChange_VariableInit();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_CHANNELCHANGE_INIT, ( enChannelChangeState ) )
        CPPTEST_ASSERT_EQUAL( E_SERVICETYPE_INVALID, ( g_eCurrentUserServiceType ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_VariableInit */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_KeyRepeatDelay_if */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_ChannelChange_KeyRepeatDelay(void) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_KeyRepeatDelay_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u32ChannelChangeTimer */
    {
         u32ChannelChangeTimer  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_ChannelChange_KeyRepeatDelay();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) );
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_KeyRepeatDelay_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ChannelChange_KeyRepeatDelay_else */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_ChannelChange_KeyRepeatDelay(void) */
void TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_KeyRepeatDelay_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u32ChannelChangeTimer */
    {
         u32ChannelChangeTimer  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_ChannelChange_KeyRepeatDelay();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ChannelChange_KeyRepeatDelay_else */
