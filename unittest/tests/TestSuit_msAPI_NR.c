#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/scaler_back/msAPI_NR.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/scaler_back/msAPI_NR.c");

CPPTEST_TEST_SUITE(TestSuit_msAPI_NR);
CPPTEST_TEST(TestSuit_msAPI_NR_test_msAPI_DynamicNR_Handler_Motion_Luma);
CPPTEST_TEST(TestSuit_msAPI_NR_test_msAPI_DynamicNR_Init);
CPPTEST_TEST(TestSuit_msAPI_NR_test_msAPI_DynamicNR_Init_if_not);
CPPTEST_TEST(TestSuit_msAPI_NR_test_msAPI_DynamicNR_SetNRTbl);
CPPTEST_TEST_SUITE_END();
        

void TestSuit_msAPI_NR_test_msAPI_DynamicNR_Handler_Motion_Luma();
void TestSuit_msAPI_NR_test_msAPI_DynamicNR_Init();
void TestSuit_msAPI_NR_test_msAPI_DynamicNR_Init_if_not();
void TestSuit_msAPI_NR_test_msAPI_DynamicNR_SetNRTbl();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuit_msAPI_NR);

void TestSuit_msAPI_NR_setUp()
{
}

void TestSuit_msAPI_NR_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DynamicNR_Handler_Motion_Luma */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_DynamicNR_Handler_Motion_Luma(MS_DYNAMIC_NR_PARAM *) */
void TestSuit_msAPI_NR_test_msAPI_DynamicNR_Handler_Motion_Luma()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstDymaicNRParam) */ 
    MS_DYNAMIC_NR_PARAM * _pstDymaicNRParam  = 0 ;
    MS_DYNAMIC_NR_PARAM pstDymaicNRParam;
    memset(&pstDymaicNRParam, 0, sizeof(MS_DYNAMIC_NR_PARAM));
    _pstDymaicNRParam = &pstDymaicNRParam;
    _pstDymaicNRParam->bMotionEn = 1;
    _pstDymaicNRParam->bLumaEn = 1;
    /* Initializing global variable g_u8PreMotionLvl */ 
    {
         g_u8PreMotionLvl  = 0;
    }
    /* Initializing global variable g_u8PreAverageLuma */ 
    {
         g_u8PreAverageLuma  = 0;
    }
    /* Initializing global variable g_u8PreMotion */ 
    {
         g_u8PreMotion  = 0;
    }
    /* Initializing global variable g_u8PreLumaLvl */ 
    {
         g_u8PreLumaLvl  = 0;
    }
    /* Initializing global variable g_u16PreSNROffset */ 
    {
         g_u16PreSNROffset  = 0u;
    }
    /* Initializing global variable g_stDynamicNR_MISC_Luma */ 
    {
         g_stDynamicNR_MISC_Luma.u8CoringOffset  = 0;
         g_stDynamicNR_MISC_Luma.u8SNROffset  = 0;
    }
    {
        /* Tested function call */
        msAPI_DynamicNR_Handler_Motion_Luma(_pstDymaicNRParam);
        /* Post-condition check */

        CPPTEST_ASSERT_EQUAL(_pstDymaicNRParam->bMotionEn, 1);
        CPPTEST_ASSERT_EQUAL(_pstDymaicNRParam->bLumaEn, 1);

    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DynamicNR_Handler_Motion_Luma */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DynamicNR_Init */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_DynamicNR_Init(INPUT_SOURCE_TYPE_t) */
void TestSuit_msAPI_NR_test_msAPI_DynamicNR_Init()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enInputSourceType) */ 
    INPUT_SOURCE_TYPE_t _enInputSourceType  = INPUT_SOURCE_VGA;

    /* Initializing global variable g_stDynamicNR_MISC_Noise */ 
    {
         g_stDynamicNR_MISC_Noise.u8CoringOffset  = 0;
         g_stDynamicNR_MISC_Noise.u8SharpnessOffset  = 0;
         g_stDynamicNR_MISC_Noise.u8NM_V  = 0;
         g_stDynamicNR_MISC_Noise.u8NM_H_0  = 0;
         g_stDynamicNR_MISC_Noise.u8NM_H_1  = 0;
         g_stDynamicNR_MISC_Noise.u8SC_Coring  = 0;
         g_stDynamicNR_MISC_Noise.u8GNR_0  = 0;
         g_stDynamicNR_MISC_Noise.u8GNR_1  = 0;
         g_stDynamicNR_MISC_Noise.u8SpikeNR_0  = 0;
         g_stDynamicNR_MISC_Noise.u8SpikeNR_1  = 0;
         g_stDynamicNR_MISC_Noise.u8CP  = 0;
         g_stDynamicNR_MISC_Noise.u8DP  = 0;
         g_stDynamicNR_MISC_Noise.u8AGC_Gain_Offset  = 0;
         g_stDynamicNR_MISC_Noise.u8Gray_Guard_En  = 0;
         g_stDynamicNR_MISC_Noise.u8Gray_Guard_Gain  = 0;
    }
    /* Initializing global variable g_u16PreSharpOffset */ 
    {
         g_u16PreSharpOffset  = 0u;
    }
    /* Initializing global variable g_u16PreSC_Coring */ 
    {
         g_u16PreSC_Coring  = 0u;
    }
    /* Initializing global variable g_u16PreGNR_0 */ 
    {
         g_u16PreGNR_0  = 0u;
    }
    /* Initializing global variable g_u16PreSpikeNR_1 */ 
    {
         g_u16PreSpikeNR_1  = 0u;
    }
    /* Initializing global variable g_u16PreGrayGuard_Gain */ 
    {
         g_u16PreGrayGuard_Gain  = 0u;
    }
    /* Initializing global variable g_u8PreNoiseMag */ 
    {
         g_u8PreNoiseMag  = 0;
    }
    /* Initializing global variable g_u8PreAverageLuma */ 
    {
         g_u8PreAverageLuma  = 0;
    }
    /* Initializing global variable g_u8PreMotion */ 
    {
         g_u8PreMotion  = 0;
    }
    /* Initializing global variable g_u16PreSNROffset */ 
    {
         g_u16PreSNROffset  = 0u;
    }
    /* Initializing global variable g_stDynamicNR_MISC_Luma */ 
    {
         g_stDynamicNR_MISC_Luma.u8CoringOffset  = 0;
         g_stDynamicNR_MISC_Luma.u8SNROffset  = 0;
    }
    {
        /* Tested function call */
        msAPI_DynamicNR_Init(_enInputSourceType);
        /* Post-condition check */

        CPPTEST_ASSERT_EQUAL(_enInputSourceType, INPUT_SOURCE_VGA);

    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DynamicNR_Init */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DynamicNR_Init_if_not */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_DynamicNR_Init(INPUT_SOURCE_TYPE_t) */
void TestSuit_msAPI_NR_test_msAPI_DynamicNR_Init_if_not()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enInputSourceType) */ 
    INPUT_SOURCE_TYPE_t _enInputSourceType  = INPUT_SOURCE_VGA;
    _enInputSourceType = INPUT_SOURCE_TV;
    /* Initializing global variable g_stDynamicNR_MISC_Noise */ 
    {
         g_stDynamicNR_MISC_Noise.u8CoringOffset  = 0;
         g_stDynamicNR_MISC_Noise.u8SharpnessOffset  = 0;
         g_stDynamicNR_MISC_Noise.u8NM_V  = 0;
         g_stDynamicNR_MISC_Noise.u8NM_H_0  = 0;
         g_stDynamicNR_MISC_Noise.u8NM_H_1  = 0;
         g_stDynamicNR_MISC_Noise.u8SC_Coring  = 0;
         g_stDynamicNR_MISC_Noise.u8GNR_0  = 0;
         g_stDynamicNR_MISC_Noise.u8GNR_1  = 0;
         g_stDynamicNR_MISC_Noise.u8SpikeNR_0  = 0;
         g_stDynamicNR_MISC_Noise.u8SpikeNR_1  = 0;
         g_stDynamicNR_MISC_Noise.u8CP  = 0;
         g_stDynamicNR_MISC_Noise.u8DP  = 0;
         g_stDynamicNR_MISC_Noise.u8AGC_Gain_Offset  = 0;
         g_stDynamicNR_MISC_Noise.u8Gray_Guard_En  = 0;
         g_stDynamicNR_MISC_Noise.u8Gray_Guard_Gain  = 0;
    }
    /* Initializing global variable g_u16PreSharpOffset */ 
    {
         g_u16PreSharpOffset  = 0u;
    }
    /* Initializing global variable g_u16PreSC_Coring */ 
    {
         g_u16PreSC_Coring  = 0u;
    }
    /* Initializing global variable g_u16PreGNR_0 */ 
    {
         g_u16PreGNR_0  = 0u;
    }
    /* Initializing global variable g_u16PreSpikeNR_1 */ 
    {
         g_u16PreSpikeNR_1  = 0u;
    }
    /* Initializing global variable g_u16PreGrayGuard_Gain */ 
    {
         g_u16PreGrayGuard_Gain  = 0u;
    }
    /* Initializing global variable g_u8PreNoiseMag */ 
    {
         g_u8PreNoiseMag  = 0;
    }
    /* Initializing global variable g_u8PreAverageLuma */ 
    {
         g_u8PreAverageLuma  = 0;
    }
    /* Initializing global variable g_u8PreMotion */ 
    {
         g_u8PreMotion  = 0;
    }
    /* Initializing global variable g_u16PreSNROffset */ 
    {
         g_u16PreSNROffset  = 0u;
    }
    /* Initializing global variable g_stDynamicNR_MISC_Luma */ 
    {
         g_stDynamicNR_MISC_Luma.u8CoringOffset  = 0;
         g_stDynamicNR_MISC_Luma.u8SNROffset  = 0;
    }
    {
        /* Tested function call */
        msAPI_DynamicNR_Init(_enInputSourceType);
        /* Post-condition check */

        CPPTEST_ASSERT_EQUAL(_enInputSourceType, INPUT_SOURCE_TV);

    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DynamicNR_Init_if_not */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DynamicNR_SetNRTbl */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_DynamicNR_SetNRTbl(U8 *) */
void TestSuit_msAPI_NR_test_msAPI_DynamicNR_SetNRTbl()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Table) */ 
    U8 * _pu8Table  = 0 ;
    U8 pu8Table;
    pu8Table = 0;
    _pu8Table = &pu8Table;
    {
        /* Tested function call */
        msAPI_DynamicNR_SetNRTbl(_pu8Table);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(*_pu8Table, 0);
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DynamicNR_SetNRTbl */
