#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app/MApp_ATVProc.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app/MApp_ATVProc.c");

CPPTEST_TEST_SUITE(TestSuite_MApp_ATVProc);
CPPTEST_TEST(TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_BG);
CPPTEST_TEST(TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_BG_A2);
CPPTEST_TEST(TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_BG_NICAM);
CPPTEST_TEST(TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_I);
CPPTEST_TEST(TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_DK);
CPPTEST_TEST(TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_DK1_A2);
CPPTEST_TEST(TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_DK2_A2);
CPPTEST_TEST(TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_DK3_A2);
CPPTEST_TEST(TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_DK_NICAM);
CPPTEST_TEST(TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_L);
CPPTEST_TEST(TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_case_E_ENABLE_SYSTEM_L_ELSE);
CPPTEST_TEST(TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_case_E_ENABLE_RF_TABLE);
CPPTEST_TEST(TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_RT_AFT_ELSE);
CPPTEST_TEST(TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_CH_NAME);
CPPTEST_TEST(TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_TTX);
CPPTEST_TEST(TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_CARRIER_MUTE);
CPPTEST_TEST(TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_SAVING_DUAL);
CPPTEST_TEST(TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_HI_DEVIATION);
CPPTEST_TEST(TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_VOLUME_CURVE_SEL);
CPPTEST_TEST(TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_MONO_ONLY);
CPPTEST_TEST(TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_WSS);
CPPTEST_TEST(TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_default);
CPPTEST_TEST(TestSuite_MApp_ATVProc_test_MApp_ATVProc_Exit_IF_Success);
CPPTEST_TEST(TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_DEFAULT);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_BG();
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_BG_A2();
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_BG_NICAM();
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_I();
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_DK();
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_DK1_A2();
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_DK2_A2();
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_DK3_A2();
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_DK_NICAM();
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_L();
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_case_E_ENABLE_SYSTEM_L_ELSE();
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_case_E_ENABLE_RF_TABLE();
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_RT_AFT_ELSE();
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_CH_NAME();
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_TTX();
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_CARRIER_MUTE();
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_SAVING_DUAL();
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_HI_DEVIATION();
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_VOLUME_CURVE_SEL();
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_MONO_ONLY();
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_WSS();
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_default();
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_Exit_IF_Success();
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_DEFAULT();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_MApp_ATVProc);

void TestSuite_MApp_ATVProc_setUp()
{
}

void TestSuite_MApp_ATVProc_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATVProc_GetAudioSystem */
/* CPPTEST_TEST_CASE_CONTEXT EN_ATV_SYSTEM_TYPE MApp_ATVProc_GetAudioSystem(AUDIOSTANDARD_TYPE) */
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_BG()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eAudioStandard) */ 
    AUDIOSTANDARD_TYPE _eAudioStandard  = E_AUDIOSTANDARD_BG;
    {
        /* Tested function call */
        EN_ATV_SYSTEM_TYPE _return  = MApp_ATVProc_GetAudioSystem(_eAudioStandard);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_ATV_SystemType_BG, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATVProc_GetAudioSystem */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATVProc_GetAudioSystem_0 */
/* CPPTEST_TEST_CASE_CONTEXT EN_ATV_SYSTEM_TYPE MApp_ATVProc_GetAudioSystem(AUDIOSTANDARD_TYPE) */
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_BG_A2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eAudioStandard) */ 
    AUDIOSTANDARD_TYPE _eAudioStandard  = E_AUDIOSTANDARD_BG_A2;
    {
        /* Tested function call */
        EN_ATV_SYSTEM_TYPE _return  = MApp_ATVProc_GetAudioSystem(_eAudioStandard);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_ATV_SystemType_BG, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATVProc_GetAudioSystem_0 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATVProc_GetAudioSystem */
/* CPPTEST_TEST_CASE_CONTEXT EN_ATV_SYSTEM_TYPE MApp_ATVProc_GetAudioSystem(AUDIOSTANDARD_TYPE) */
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_BG_NICAM()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eAudioStandard) */ 
    AUDIOSTANDARD_TYPE _eAudioStandard  = E_AUDIOSTANDARD_BG_NICAM;
    {
        /* Tested function call */
        EN_ATV_SYSTEM_TYPE _return  = MApp_ATVProc_GetAudioSystem(_eAudioStandard);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_ATV_SystemType_BG, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATVProc_GetAudioSystem */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATVProc_GetAudioSystem */
/* CPPTEST_TEST_CASE_CONTEXT EN_ATV_SYSTEM_TYPE MApp_ATVProc_GetAudioSystem(AUDIOSTANDARD_TYPE) */
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_I()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eAudioStandard) */ 
    AUDIOSTANDARD_TYPE _eAudioStandard  = E_AUDIOSTANDARD_I;
    {
        /* Tested function call */
        EN_ATV_SYSTEM_TYPE _return  = MApp_ATVProc_GetAudioSystem(_eAudioStandard);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_ATV_SystemType_I, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATVProc_GetAudioSystem */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATVProc_GetAudioSystem */
/* CPPTEST_TEST_CASE_CONTEXT EN_ATV_SYSTEM_TYPE MApp_ATVProc_GetAudioSystem(AUDIOSTANDARD_TYPE) */
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_DK()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eAudioStandard) */ 
    AUDIOSTANDARD_TYPE _eAudioStandard  = E_AUDIOSTANDARD_DK;
    {
        /* Tested function call */
        EN_ATV_SYSTEM_TYPE _return  = MApp_ATVProc_GetAudioSystem(_eAudioStandard);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_ATV_SystemType_DK, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATVProc_GetAudioSystem */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATVProc_GetAudioSystem */
/* CPPTEST_TEST_CASE_CONTEXT EN_ATV_SYSTEM_TYPE MApp_ATVProc_GetAudioSystem(AUDIOSTANDARD_TYPE) */
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_DK1_A2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eAudioStandard) */ 
    AUDIOSTANDARD_TYPE _eAudioStandard  = E_AUDIOSTANDARD_DK1_A2;
    {
        /* Tested function call */
        EN_ATV_SYSTEM_TYPE _return  = MApp_ATVProc_GetAudioSystem(_eAudioStandard);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_ATV_SystemType_DK, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATVProc_GetAudioSystem */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATVProc_GetAudioSystem */
/* CPPTEST_TEST_CASE_CONTEXT EN_ATV_SYSTEM_TYPE MApp_ATVProc_GetAudioSystem(AUDIOSTANDARD_TYPE) */
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_DK2_A2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eAudioStandard) */ 
    AUDIOSTANDARD_TYPE _eAudioStandard  = E_AUDIOSTANDARD_DK2_A2;
    {
        /* Tested function call */
        EN_ATV_SYSTEM_TYPE _return  = MApp_ATVProc_GetAudioSystem(_eAudioStandard);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_ATV_SystemType_DK, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATVProc_GetAudioSystem */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATVProc_GetAudioSystem */
/* CPPTEST_TEST_CASE_CONTEXT EN_ATV_SYSTEM_TYPE MApp_ATVProc_GetAudioSystem(AUDIOSTANDARD_TYPE) */
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_DK3_A2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eAudioStandard) */ 
    AUDIOSTANDARD_TYPE _eAudioStandard  = E_AUDIOSTANDARD_DK3_A2;
    {
        /* Tested function call */
        EN_ATV_SYSTEM_TYPE _return  = MApp_ATVProc_GetAudioSystem(_eAudioStandard);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_ATV_SystemType_DK, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATVProc_GetAudioSystem */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATVProc_GetAudioSystem */
/* CPPTEST_TEST_CASE_CONTEXT EN_ATV_SYSTEM_TYPE MApp_ATVProc_GetAudioSystem(AUDIOSTANDARD_TYPE) */
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_DK_NICAM()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eAudioStandard) */ 
    AUDIOSTANDARD_TYPE _eAudioStandard  = E_AUDIOSTANDARD_DK_NICAM;
    {
        /* Tested function call */
        EN_ATV_SYSTEM_TYPE _return  = MApp_ATVProc_GetAudioSystem(_eAudioStandard);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_ATV_SystemType_DK, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATVProc_GetAudioSystem */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATVProc_GetAudioSystem */
/* CPPTEST_TEST_CASE_CONTEXT EN_ATV_SYSTEM_TYPE MApp_ATVProc_GetAudioSystem(AUDIOSTANDARD_TYPE) */
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_case_E_AUDIOSTANDARD_L()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eAudioStandard) */ 
    AUDIOSTANDARD_TYPE _eAudioStandard  = E_AUDIOSTANDARD_L;
    {
        /* Tested function call */
        EN_ATV_SYSTEM_TYPE _return  = MApp_ATVProc_GetAudioSystem(_eAudioStandard);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_ATV_SystemType_L, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATVProc_GetAudioSystem */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATVProc_GetAudioSystem_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT EN_ATV_SYSTEM_TYPE MApp_ATVProc_GetAudioSystem(AUDIOSTANDARD_TYPE) */
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_GetAudioSystem_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eAudioStandard) */
    AUDIOSTANDARD_TYPE _eAudioStandard  = E_AUDIOSTANDARD_NOTSTANDARD;
    {

        EN_ATV_SYSTEM_TYPE _return  = MApp_ATVProc_GetAudioSystem(_eAudioStandard);

     //   CPPTEST_ASSERT_EQUAL( E_AUDIOSTANDARD_NOTSTANDARD, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATVProc_GetAudioSystem_DEFAULT */
/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATVProc_IsThisATVOptionEnabled_case_E_ENABLE_SYSTEM_L_ELSE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_ATVProc_IsThisATVOptionEnabled(THISATV_OPTION) */
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_case_E_ENABLE_SYSTEM_L_ELSE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eOption) */ 
    THISATV_OPTION _eOption  = E_ENABLE_SYSTEM_L;


    {
        /* Tested function call */
        BOOLEAN _return  = MApp_ATVProc_IsThisATVOptionEnabled(_eOption);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL( TRUE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATVProc_IsThisATVOptionEnabled_case_E_ENABLE_SYSTEM_L_ELSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATVProc_IsThisATVOptionEnabled_case_E_ENABLE_RF_TABLE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_ATVProc_IsThisATVOptionEnabled(THISATV_OPTION) */
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_case_E_ENABLE_RF_TABLE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eOption) */ 
    THISATV_OPTION _eOption  = E_ENABLE_RF_TABLE;
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_ATVProc_IsThisATVOptionEnabled(_eOption);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL( FALSE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATVProc_IsThisATVOptionEnabled_case_E_ENABLE_RF_TABLE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_RT_AFT_ELSE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_ATVProc_IsThisATVOptionEnabled(THISATV_OPTION) */
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_RT_AFT_ELSE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eOption) */ 
    THISATV_OPTION _eOption  = E_ENABLE_RT_AFT;
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_ATVProc_IsThisATVOptionEnabled(_eOption);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL( TRUE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_RT_AFT_ELSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_CH_NAME */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_ATVProc_IsThisATVOptionEnabled(THISATV_OPTION) */
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_CH_NAME()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eOption) */ 
    THISATV_OPTION _eOption  = E_ENABLE_CH_NAME;
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_ATVProc_IsThisATVOptionEnabled(_eOption);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL( TRUE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_CH_NAME */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_TTX */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_ATVProc_IsThisATVOptionEnabled(THISATV_OPTION) */
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_TTX()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eOption) */ 
    THISATV_OPTION _eOption  = E_ENABLE_TTX;
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_ATVProc_IsThisATVOptionEnabled(_eOption);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL( TRUE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_TTX */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_CARRIER_MUTE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_ATVProc_IsThisATVOptionEnabled(THISATV_OPTION) */
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_CARRIER_MUTE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eOption) */ 
    THISATV_OPTION _eOption  = E_ENABLE_CARRIER_MUTE;
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_ATVProc_IsThisATVOptionEnabled(_eOption);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL( TRUE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_CARRIER_MUTE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_SAVING_DUAL */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_ATVProc_IsThisATVOptionEnabled(THISATV_OPTION) */
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_SAVING_DUAL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eOption) */ 
    THISATV_OPTION _eOption  = E_ENABLE_SAVING_DUAL;
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_ATVProc_IsThisATVOptionEnabled(_eOption);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL( TRUE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_SAVING_DUAL */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_HI_DEVIATION */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_ATVProc_IsThisATVOptionEnabled(THISATV_OPTION) */
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_HI_DEVIATION()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eOption) */ 
    THISATV_OPTION _eOption  = E_ENABLE_HI_DEVIATION;
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_ATVProc_IsThisATVOptionEnabled(_eOption);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL( FALSE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_HI_DEVIATION */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_VOLUME_CURVE_SEL */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_ATVProc_IsThisATVOptionEnabled(THISATV_OPTION) */
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_VOLUME_CURVE_SEL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eOption) */ 
    THISATV_OPTION _eOption  = E_ENABLE_VOLUME_CURVE_SEL;
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_ATVProc_IsThisATVOptionEnabled(_eOption);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL( FALSE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_VOLUME_CURVE_SEL */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_MONO_ONLY */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_ATVProc_IsThisATVOptionEnabled(THISATV_OPTION) */
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_MONO_ONLY()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eOption) */ 
    THISATV_OPTION _eOption  = E_ENABLE_MONO_ONLY;
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_ATVProc_IsThisATVOptionEnabled(_eOption);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL( FALSE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_MONO_ONLY */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_WSS */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_ATVProc_IsThisATVOptionEnabled(THISATV_OPTION) */
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_WSS()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eOption) */ 
    THISATV_OPTION _eOption  = E_ENABLE_WSS;
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_ATVProc_IsThisATVOptionEnabled(_eOption);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL( TRUE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATVProc_IsThisATVOptionEnabled_E_ENABLE_WSS */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATVProc_IsThisATVOptionEnabled_default */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_ATVProc_IsThisATVOptionEnabled(THISATV_OPTION) */
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_IsThisATVOptionEnabled_default()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eOption) */ 
	THISATV_OPTION _eOption = E_MAX_THISATV_OPTION;
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_ATVProc_IsThisATVOptionEnabled(_eOption);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL( FALSE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATVProc_IsThisATVOptionEnabled_default */



/* CPPTEST_TEST_CASE_BEGIN test_MApp_ATVProc_Exit_IF_Success */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ATVProc_Exit(void) */
void TestSuite_MApp_ATVProc_test_MApp_ATVProc_Exit_IF_Success()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        MApp_ATVProc_Exit();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ATVProc_Exit_IF_Success */



