#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/msAPI_MHEG5.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/msAPI_MHEG5.c");

CPPTEST_TEST_SUITE(TestSuite_msAPI_MHEG5);
CPPTEST_TEST(TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_E_MHEG_CI_OFF);
CPPTEST_TEST(TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_u8SSM_Equal_0);
CPPTEST_TEST(TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_u8SSM_Equal_2_bSMG_IsFalse);
CPPTEST_TEST(TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_u8SSM_Equal_2_bSMG_IsTrue);
CPPTEST_TEST(TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_u8SSM_Equal_1_fEnableSubtitle_IsTrue_u8SubtitleMenuNum_equal_1);
CPPTEST_TEST(TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_u8SSM_Equal_1_Others);
#if MHEG5_WITH_SUBTITLE
CPPTEST_TEST(TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_0);
CPPTEST_TEST(TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_0_u8MheGSubtitleControl_0_isFullScreen_0);
CPPTEST_TEST(TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_0_u8MheGSubtitleControl_0_isFullScreen_1);
CPPTEST_TEST(TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_0_u8MheGSubtitleControl_1_isFullScreen_0);
CPPTEST_TEST(TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_0_u8MheGSubtitleControl_1_isFullScreen_1);
CPPTEST_TEST(TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_1_u8MheGSubtitleControl_0_isFullScreen_0);
CPPTEST_TEST(TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_1_u8MheGSubtitleControl_0_isFullScreen_1);
CPPTEST_TEST(TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_1_u8MheGSubtitleControl_1_isFullScreen_0);
CPPTEST_TEST(TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_1_u8MheGSubtitleControl_1_isFullScreen_1);
#endif
CPPTEST_TEST_SUITE_END();


void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_E_MHEG_CI_OFF();
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_u8SSM_Equal_0();
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_u8SSM_Equal_2_bSMG_IsFalse();
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_u8SSM_Equal_2_bSMG_IsTrue();
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_u8SSM_Equal_1_fEnableSubtitle_IsTrue_u8SubtitleMenuNum_equal_1();
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_u8SSM_Equal_1_Others();
#if MHEG5_WITH_SUBTITLE
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_0();
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_0_u8MheGSubtitleControl_0_isFullScreen_0();
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_0_u8MheGSubtitleControl_0_isFullScreen_1();
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_0_u8MheGSubtitleControl_1_isFullScreen_0();
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_0_u8MheGSubtitleControl_1_isFullScreen_1();
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_1_u8MheGSubtitleControl_0_isFullScreen_0();
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_1_u8MheGSubtitleControl_0_isFullScreen_1();
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_1_u8MheGSubtitleControl_1_isFullScreen_0();
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_1_u8MheGSubtitleControl_1_isFullScreen_1();
#endif
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_msAPI_MHEG5);

void TestSuite_msAPI_MHEG5_setUp()
{
}

void TestSuite_msAPI_MHEG5_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_E_MHEG_CI_OFF */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_MHEG5_GoMHEGWhenSubtitleOn(void) */
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_E_MHEG_CI_OFF()
{
    /* Pre-condition initialization */
    /* Initializing global variable u8SSM */
    {
         u8SSM  = 0;
    }
    /* Initializing global variable bSMG */
    {
         bSMG  = 0;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable u8SubtitleMenuNum */
    {
         u8SubtitleMenuNum  = 0;
    }
    /* Initializing global variable bCIMHEGRun */
    {
         bCIMHEGRun  = E_MHEG_CI_OFF;
    }
    {
        /* Tested function call */
        U8 _return  = msAPI_MHEG5_GoMHEGWhenSubtitleOn();
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_E_MHEG_CI_OFF */


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_u8SSM_Equal_0 */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_MHEG5_GoMHEGWhenSubtitleOn(void) */
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_u8SSM_Equal_0()
{
    /* Pre-condition initialization */
    /* Initializing global variable u8SSM */
    {
         u8SSM  = 0;
    }
    /* Initializing global variable bSMG */
    {
         bSMG  = 0;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable u8SubtitleMenuNum */
    {
         u8SubtitleMenuNum  = 0;
    }
    /* Initializing global variable bCIMHEGRun */
    {
         bCIMHEGRun  = E_MHEG_CI_RUNNING;
    }
    {
        /* Tested function call */
        U8 _return  = msAPI_MHEG5_GoMHEGWhenSubtitleOn();
        CPPTEST_ASSERT_UINTEGER_EQUAL(2, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_u8SSM_Equal_0 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_u8SSM_Equal_2_bSMG_IsFalse */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_MHEG5_GoMHEGWhenSubtitleOn(void) */
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_u8SSM_Equal_2_bSMG_IsFalse()
{
    /* Pre-condition initialization */
    /* Initializing global variable u8SSM */
    {
         u8SSM  = 2;
    }
    /* Initializing global variable bSMG */
    {
         bSMG  = 0;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable u8SubtitleMenuNum */
    {
         u8SubtitleMenuNum  = 0;
    }
    /* Initializing global variable bCIMHEGRun */
    {
         bCIMHEGRun  = E_MHEG_CI_OFF;
    }
    {
        /* Tested function call */
        U8 _return  = msAPI_MHEG5_GoMHEGWhenSubtitleOn();
        CPPTEST_ASSERT_UINTEGER_EQUAL(2, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_u8SSM_Equal_2_bSMG_IsFalse */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_u8SSM_Equal_2_bSMG_IsTrue */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_MHEG5_GoMHEGWhenSubtitleOn(void) */
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_u8SSM_Equal_2_bSMG_IsTrue()
{
    /* Pre-condition initialization */
    /* Initializing global variable u8SSM */
    {
         u8SSM  = 2;
    }
    /* Initializing global variable bSMG */
    {
         bSMG  = 1;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable u8SubtitleMenuNum */
    {
         u8SubtitleMenuNum  = 0;
    }
    /* Initializing global variable bCIMHEGRun */
    {
         bCIMHEGRun  = E_MHEG_CI_OFF;
    }
    {
        /* Tested function call */
        U8 _return  = msAPI_MHEG5_GoMHEGWhenSubtitleOn();
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_u8SSM_Equal_2_bSMG_IsTrue */


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_u8SSM_Equal_1_fEnableSubtitle_IsTrue_u8SubtitleMenuNum_equal_1 */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_MHEG5_GoMHEGWhenSubtitleOn(void) */
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_u8SSM_Equal_1_fEnableSubtitle_IsTrue_u8SubtitleMenuNum_equal_1()
{
    /* Pre-condition initialization */
    /* Initializing global variable u8SSM */
    {
         u8SSM  = 1;
    }
    /* Initializing global variable bSMG */
    {
         bSMG  = 0;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.g_SysSetting.fEnableSubTitle = 1;
    }
    /* Initializing global variable u8SubtitleMenuNum */
    {
         u8SubtitleMenuNum  = 1;
    }
    /* Initializing global variable bCIMHEGRun */
    {
         bCIMHEGRun  = E_MHEG_CI_OFF;
    }
    {
        /* Tested function call */
        U8 _return  = msAPI_MHEG5_GoMHEGWhenSubtitleOn();
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_u8SSM_Equal_1_fEnableSubtitle_IsTrue_u8SubtitleMenuNum_equal_1 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_u8SSM_Equal_1_Others */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_MHEG5_GoMHEGWhenSubtitleOn(void) */
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_u8SSM_Equal_1_Others()
{
    /* Pre-condition initialization */
    /* Initializing global variable u8SSM */
    {
         u8SSM  = 1;
    }
    /* Initializing global variable bSMG */
    {
         bSMG  = 0;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.g_SysSetting.fEnableSubTitle = 0;
    }
    /* Initializing global variable u8SubtitleMenuNum */
    {
         u8SubtitleMenuNum  = 0;
    }
    /* Initializing global variable bCIMHEGRun */
    {
         bCIMHEGRun  = E_MHEG_CI_OFF;
    }
    {
        /* Tested function call */
        U8 _return  = msAPI_MHEG5_GoMHEGWhenSubtitleOn();
        CPPTEST_ASSERT_UINTEGER_EQUAL(2, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_u8SSM_Equal_1_Others */

#if MHEG5_WITH_SUBTITLE
/* CPPTEST_TEST_CASE_BEGIN test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_0 */
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_0()
{
    g_MHEG5Video.bIFrame = 1;
    u8MHEGSubtitleControl = 1;

    U8 _return  = msAPI_MHEG5_GetSubtitleMode();
    CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );

}
/* CPPTEST_TEST_CASE_END test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_0 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_0_u8MheGSubtitleControl_0_isFullScreen_0 */
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_0_u8MheGSubtitleControl_0_isFullScreen_0()
{
    g_MHEG5Video.bIFrame = 0;
    u8MHEGSubtitleControl = 0;

    U8 _return  = msAPI_MHEG5_GetSubtitleMode();
    CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
}
/* CPPTEST_TEST_CASE_END test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_0_u8MheGSubtitleControl_0_isFullScreen_0 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_0_u8MheGSubtitleControl_0_isFullScreen_1 */
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_0_u8MheGSubtitleControl_0_isFullScreen_1()
{
    g_MHEG5Video.bIFrame = 0;
    u8MHEGSubtitleControl = 0;

    U8 _return  = msAPI_MHEG5_GetSubtitleMode();
    CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
}
/* CPPTEST_TEST_CASE_END test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_0_u8MheGSubtitleControl_0_isFullScreen_1 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_0_u8MheGSubtitleControl_1_isFullScreen_0 */
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_0_u8MheGSubtitleControl_1_isFullScreen_0()
{
    g_MHEG5Video.bIFrame = 0;
    u8MHEGSubtitleControl = 1;

    U8 _return  = msAPI_MHEG5_GetSubtitleMode();
    CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
}
/* CPPTEST_TEST_CASE_END test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_0_u8MheGSubtitleControl_1_isFullScreen_0 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_0_u8MheGSubtitleControl_1_isFullScreen_1 */
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_0_u8MheGSubtitleControl_1_isFullScreen_1()
{
    g_MHEG5Video.bIFrame = 0;
    u8MHEGSubtitleControl = 1;

    U8 _return  = msAPI_MHEG5_GetSubtitleMode();
    CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
}
/* CPPTEST_TEST_CASE_END test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_0_u8MheGSubtitleControl_1_isFullScreen_1 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_1_u8MheGSubtitleControl_0_isFullScreen_0 */
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_1_u8MheGSubtitleControl_0_isFullScreen_0()
{
    g_MHEG5Video.bIFrame = 1;
    u8MHEGSubtitleControl = 0;

    U8 _return  = msAPI_MHEG5_GetSubtitleMode();
    CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
}
/* CPPTEST_TEST_CASE_END test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_1_u8MheGSubtitleControl_0_isFullScreen_0 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_1_u8MheGSubtitleControl_0_isFullScreen_1 */
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_1_u8MheGSubtitleControl_0_isFullScreen_1()
{
    g_MHEG5Video.bIFrame = 1;
    u8MHEGSubtitleControl = 0;

    U8 _return  = msAPI_MHEG5_GetSubtitleMode();
    CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
}
/* CPPTEST_TEST_CASE_END test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_0_u8MheGSubtitleControl_0_isFullScreen_0 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_1_u8MheGSubtitleControl_1_isFullScreen_0 */
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_1_u8MheGSubtitleControl_1_isFullScreen_0()
{
    g_MHEG5Video.bIFrame = 1;
    u8MHEGSubtitleControl = 1;

    U8 _return  = msAPI_MHEG5_GetSubtitleMode();
    CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
}
/* CPPTEST_TEST_CASE_END test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_1_u8MheGSubtitleControl_1_isFullScreen_0 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_1_u8MheGSubtitleControl_1_isFullScreen_1 */
void TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_1_u8MheGSubtitleControl_1_isFullScreen_1()
{
    g_MHEG5Video.bIFrame = 1;
    u8MHEGSubtitleControl = 1;

    U8 _return  = msAPI_MHEG5_GetSubtitleMode();
    CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
}
/* CPPTEST_TEST_CASE_END test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_1_u8MheGSubtitleControl_1_isFullScreen_1 */
#endif

