#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app/MApp_XC_Sys.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app/MApp_XC_Sys.c");

CPPTEST_TEST_SUITE(TestSuit_MApp_XC_Sys);
CPPTEST_TEST(TestSuit_MApp_XC_Sys_test_msAPI_Picture_isCurrentAFDVaild_Yes);
CPPTEST_TEST(TestSuit_MApp_XC_Sys_test_msAPI_Picture_isCurrentAFDVaild_No);
CPPTEST_TEST(TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic0);
CPPTEST_TEST(TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic1);
CPPTEST_TEST(TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic2);
CPPTEST_TEST(TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic3);
CPPTEST_TEST(TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic4);
CPPTEST_TEST(TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic5);
CPPTEST_TEST(TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic6);
CPPTEST_TEST(TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic7);
CPPTEST_TEST(TestSuit_MApp_XC_Sys_test__msAPI_Picture_CalculateSAR_Logic0);
CPPTEST_TEST(TestSuit_MApp_XC_Sys_test__msAPI_Picture_CalculateSAR_Logic1);
CPPTEST_TEST(TestSuit_MApp_XC_Sys_test__msAPI_Picture_CalculateSAR_Logic2);
CPPTEST_TEST(TestSuit_MApp_XC_Sys_test__msAPI_Picture_CalculateSAR_Logic3);
CPPTEST_TEST(TestSuit_MApp_XC_Sys_test__msAPI_Picture_CalculateSAR_Logic4);
CPPTEST_TEST(TestSuit_MApp_XC_Sys_test__msAPI_Picture_CalculateSAR_Logic5);
CPPTEST_TEST(TestSuit_MApp_XC_Sys_test_msAPI_Picture_CalculateAFDWindow);
CPPTEST_TEST(TestSuit_MApp_XC_Sys_test_MApp_Image_SetMirror);
CPPTEST_TEST_SUITE_END();


void TestSuit_MApp_XC_Sys_test_msAPI_Picture_isCurrentAFDVaild_Yes();
void TestSuit_MApp_XC_Sys_test_msAPI_Picture_isCurrentAFDVaild_No();
void TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic0();
void TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic1();
void TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic2();
void TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic3();
void TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic4();
void TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic5();
void TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic6();
void TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic7();
void TestSuit_MApp_XC_Sys_test__msAPI_Picture_CalculateSAR_Logic0();
void TestSuit_MApp_XC_Sys_test__msAPI_Picture_CalculateSAR_Logic1();
void TestSuit_MApp_XC_Sys_test__msAPI_Picture_CalculateSAR_Logic2();
void TestSuit_MApp_XC_Sys_test__msAPI_Picture_CalculateSAR_Logic3();
void TestSuit_MApp_XC_Sys_test__msAPI_Picture_CalculateSAR_Logic4();
void TestSuit_MApp_XC_Sys_test__msAPI_Picture_CalculateSAR_Logic5();
void TestSuit_MApp_XC_Sys_test_msAPI_Picture_CalculateAFDWindow();
void TestSuit_MApp_XC_Sys_test_MApp_Image_SetMirror();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuit_MApp_XC_Sys);
void TestSuit_MApp_XC_Sys_setUp()
{
}

void TestSuit_MApp_XC_Sys_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Picture_isCurrentAFDVaild_Yes */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_Picture_isCurrentAFDVaild(U8) */
void TestSuit_MApp_XC_Sys_test_msAPI_Picture_isCurrentAFDVaild_Yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (tmpAFD) */ 
    U8 _tmpAFD  = 1;
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_Picture_isCurrentAFDVaild(_tmpAFD);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER(TRUE, (_return ));
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE,  _return );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Picture_isCurrentAFDVaild_Yes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Picture_isCurrentAFDVaild_No */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_Picture_isCurrentAFDVaild(U8) */
void TestSuit_MApp_XC_Sys_test_msAPI_Picture_isCurrentAFDVaild_No()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (tmpAFD) */ 
    U8 _tmpAFD  = 0;
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_Picture_isCurrentAFDVaild(_tmpAFD);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER(FALSE, (_return ));
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE,  _return );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Picture_isCurrentAFDVaild_No */


/* CPPTEST_TEST_CASE_BEGIN test__msAPI_Picture_Adjust_AFDSourceWindow_Logic0 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _msAPI_Picture_Adjust_AFDSourceWindow(SRC_RATIO_INFO *, MS_WINDOW_TYPE *, MS_WINDOW_TYPE *) */
extern U8  u8Test_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic0_Call_msAPI_Picture_AdjustWidth_CutByHeight;
void TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstSrcRatioInfo) */ 
    SRC_RATIO_INFO * _pstSrcRatioInfo  = 0 ;
    SRC_RATIO_INFO stSrcRatioInfo;
    _pstSrcRatioInfo = &stSrcRatioInfo;

    /* Initializing argument 2 (pstCropWin) */ 
    MS_WINDOW_TYPE * _pstCropWin  = 0 ;
    MS_WINDOW_TYPE stCropWin;
    _pstCropWin = &stCropWin;

    /* Initializing argument 3 (pstDstWin) */ 
    MS_WINDOW_TYPE * _pstDstWin  = 0 ;
    MS_WINDOW_TYPE stDstWin;
    _pstDstWin = &stDstWin;


    _pstSrcRatioInfo->u8AFD = E_MVD_AFD_FULL_FRAME;
    _pstSrcRatioInfo->u8AspectRate = MVD_ASP_4TO3;
    {
        /* Tested function call */
        BOOLEAN _return  = _msAPI_Picture_Adjust_AFDSourceWindow(_pstSrcRatioInfo, _pstCropWin, _pstDstWin);
        CPPTEST_ASSERT_EQUAL(1, u8Test_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic0_Call_msAPI_Picture_AdjustWidth_CutByHeight);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE,  _return );
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("SRC_RATIO_INFO * _pstSrcRatioInfo ", ( _pstSrcRatioInfo ));
        //CPPTEST_POST_CONDITION_PTR("MS_WINDOW_TYPE * _pstCropWin ", ( _pstCropWin ));
        //CPPTEST_POST_CONDITION_PTR("MS_WINDOW_TYPE * _pstDstWin ", ( _pstDstWin ));
    }
}
/* CPPTEST_TEST_CASE_END test__msAPI_Picture_Adjust_AFDSourceWindow_Logic0 */


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Picture_Adjust_AFDSourceWindow_Logic1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _msAPI_Picture_Adjust_AFDSourceWindow(SRC_RATIO_INFO *, MS_WINDOW_TYPE *, MS_WINDOW_TYPE *) */
void TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstSrcRatioInfo) */ 
    SRC_RATIO_INFO * _pstSrcRatioInfo  = 0 ;
    SRC_RATIO_INFO stSrcRatioInfo;
    _pstSrcRatioInfo = &stSrcRatioInfo;

    /* Initializing argument 2 (pstCropWin) */ 
    MS_WINDOW_TYPE * _pstCropWin  = 0 ;
    MS_WINDOW_TYPE stCropWin;
    _pstCropWin = &stCropWin;

    /* Initializing argument 3 (pstDstWin) */ 
    MS_WINDOW_TYPE * _pstDstWin  = 0 ;
    MS_WINDOW_TYPE stDstWin;
    _pstDstWin = &stDstWin;


    _pstSrcRatioInfo->u8AFD = E_MVD_AFD_CENTRE_4x3;
    _pstSrcRatioInfo->u8AspectRate = MVD_ASP_4TO3;
    {
        /* Tested function call */
        BOOLEAN _return  = _msAPI_Picture_Adjust_AFDSourceWindow(_pstSrcRatioInfo, _pstCropWin, _pstDstWin);
        CPPTEST_ASSERT_EQUAL(2, u8Test_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic0_Call_msAPI_Picture_AdjustWidth_CutByHeight);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE,  _return );
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("SRC_RATIO_INFO * _pstSrcRatioInfo ", ( _pstSrcRatioInfo ));
        //CPPTEST_POST_CONDITION_PTR("MS_WINDOW_TYPE * _pstCropWin ", ( _pstCropWin ));
        //CPPTEST_POST_CONDITION_PTR("MS_WINDOW_TYPE * _pstDstWin ", ( _pstDstWin ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Picture_Adjust_AFDSourceWindow_Logic1 */


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Picture_Adjust_AFDSourceWindow_Logic2 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _msAPI_Picture_Adjust_AFDSourceWindow(SRC_RATIO_INFO *, MS_WINDOW_TYPE *, MS_WINDOW_TYPE *) */
void TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstSrcRatioInfo) */ 
    SRC_RATIO_INFO * _pstSrcRatioInfo  = 0 ;
    SRC_RATIO_INFO stSrcRatioInfo;
    _pstSrcRatioInfo = &stSrcRatioInfo;

    /* Initializing argument 2 (pstCropWin) */ 
    MS_WINDOW_TYPE * _pstCropWin  = 0 ;
    MS_WINDOW_TYPE stCropWin;
    _pstCropWin = &stCropWin;

    /* Initializing argument 3 (pstDstWin) */ 
    MS_WINDOW_TYPE * _pstDstWin  = 0 ;
    MS_WINDOW_TYPE stDstWin;
    _pstDstWin = &stDstWin;


    _pstSrcRatioInfo->u8AFD = E_MVD_AFD_CENTRE_16X9;
    _pstSrcRatioInfo->u8AspectRate = MVD_ASP_4TO3;
    {
        /* Tested function call */
        BOOLEAN _return  = _msAPI_Picture_Adjust_AFDSourceWindow(_pstSrcRatioInfo, _pstCropWin, _pstDstWin);
        CPPTEST_ASSERT_EQUAL(3, u8Test_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic0_Call_msAPI_Picture_AdjustWidth_CutByHeight);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE,  _return );
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("SRC_RATIO_INFO * _pstSrcRatioInfo ", ( _pstSrcRatioInfo ));
        //CPPTEST_POST_CONDITION_PTR("MS_WINDOW_TYPE * _pstCropWin ", ( _pstCropWin ));
        //CPPTEST_POST_CONDITION_PTR("MS_WINDOW_TYPE * _pstDstWin ", ( _pstDstWin ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Picture_Adjust_AFDSourceWindow_Logic2 */



/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Picture_Adjust_AFDSourceWindow_Logic3 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _msAPI_Picture_Adjust_AFDSourceWindow(SRC_RATIO_INFO *, MS_WINDOW_TYPE *, MS_WINDOW_TYPE *) */
void TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstSrcRatioInfo) */ 
    SRC_RATIO_INFO * _pstSrcRatioInfo  = 0 ;
    SRC_RATIO_INFO stSrcRatioInfo;
    _pstSrcRatioInfo = &stSrcRatioInfo;

    /* Initializing argument 2 (pstCropWin) */ 
    MS_WINDOW_TYPE * _pstCropWin  = 0 ;
    MS_WINDOW_TYPE stCropWin;
    _pstCropWin = &stCropWin;

    /* Initializing argument 3 (pstDstWin) */ 
    MS_WINDOW_TYPE * _pstDstWin  = 0 ;
    MS_WINDOW_TYPE stDstWin;
    _pstDstWin = &stDstWin;


    _pstSrcRatioInfo->u8AFD = E_MVD_AFD_CENTRE_16X9;
    _pstSrcRatioInfo->u8AspectRate = MVD_ASP_4TO3;
    {
        /* Tested function call */
        BOOLEAN _return  = _msAPI_Picture_Adjust_AFDSourceWindow(_pstSrcRatioInfo, _pstCropWin, _pstDstWin);
        CPPTEST_ASSERT_EQUAL(4, u8Test_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic0_Call_msAPI_Picture_AdjustWidth_CutByHeight);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE,  _return );
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("SRC_RATIO_INFO * _pstSrcRatioInfo ", ( _pstSrcRatioInfo ));
        //CPPTEST_POST_CONDITION_PTR("MS_WINDOW_TYPE * _pstCropWin ", ( _pstCropWin ));
        //CPPTEST_POST_CONDITION_PTR("MS_WINDOW_TYPE * _pstDstWin ", ( _pstDstWin ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Picture_Adjust_AFDSourceWindow_Logic3 */


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Picture_Adjust_AFDSourceWindow_Logic4 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _msAPI_Picture_Adjust_AFDSourceWindow(SRC_RATIO_INFO *, MS_WINDOW_TYPE *, MS_WINDOW_TYPE *) */
void TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic4()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstSrcRatioInfo) */ 
    SRC_RATIO_INFO * _pstSrcRatioInfo  = 0 ;
    SRC_RATIO_INFO stSrcRatioInfo;
    _pstSrcRatioInfo = &stSrcRatioInfo;

    /* Initializing argument 2 (pstCropWin) */ 
    MS_WINDOW_TYPE * _pstCropWin  = 0 ;
    MS_WINDOW_TYPE stCropWin;
    _pstCropWin = &stCropWin;

    /* Initializing argument 3 (pstDstWin) */ 
    MS_WINDOW_TYPE * _pstDstWin  = 0 ;
    MS_WINDOW_TYPE stDstWin;
    _pstDstWin = &stDstWin;


    _pstSrcRatioInfo->u8AFD = E_MVD_AFD_CENTRE_14X9;
    _pstSrcRatioInfo->u8AspectRate = MVD_ASP_4TO3;
    {
        /* Tested function call */
        BOOLEAN _return  = _msAPI_Picture_Adjust_AFDSourceWindow(_pstSrcRatioInfo, _pstCropWin, _pstDstWin);
        CPPTEST_ASSERT_EQUAL(5, u8Test_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic0_Call_msAPI_Picture_AdjustWidth_CutByHeight);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE,  _return );
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("SRC_RATIO_INFO * _pstSrcRatioInfo ", ( _pstSrcRatioInfo ));
        //CPPTEST_POST_CONDITION_PTR("MS_WINDOW_TYPE * _pstCropWin ", ( _pstCropWin ));
        //CPPTEST_POST_CONDITION_PTR("MS_WINDOW_TYPE * _pstDstWin ", ( _pstDstWin ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Picture_Adjust_AFDSourceWindow_Logic4 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Picture_Adjust_AFDSourceWindow_Logic5 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _msAPI_Picture_Adjust_AFDSourceWindow(SRC_RATIO_INFO *, MS_WINDOW_TYPE *, MS_WINDOW_TYPE *) */
void TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic5()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstSrcRatioInfo) */ 
    SRC_RATIO_INFO * _pstSrcRatioInfo  = 0 ;
    SRC_RATIO_INFO stSrcRatioInfo;
    _pstSrcRatioInfo = &stSrcRatioInfo;

    /* Initializing argument 2 (pstCropWin) */ 
    MS_WINDOW_TYPE * _pstCropWin  = 0 ;
    MS_WINDOW_TYPE stCropWin;
    _pstCropWin = &stCropWin;

    /* Initializing argument 3 (pstDstWin) */ 
    MS_WINDOW_TYPE * _pstDstWin  = 0 ;
    MS_WINDOW_TYPE stDstWin;
    _pstDstWin = &stDstWin;


    _pstSrcRatioInfo->u8AFD = E_MVD_AFD_CENTRE_4X3_14X9;
    _pstSrcRatioInfo->u8AspectRate = MVD_ASP_16TO9;
    {
        /* Tested function call */
        BOOLEAN _return  = _msAPI_Picture_Adjust_AFDSourceWindow(_pstSrcRatioInfo, _pstCropWin, _pstDstWin);
        CPPTEST_ASSERT_EQUAL(6, u8Test_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic0_Call_msAPI_Picture_AdjustWidth_CutByHeight);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE,  _return );
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("SRC_RATIO_INFO * _pstSrcRatioInfo ", ( _pstSrcRatioInfo ));
        //CPPTEST_POST_CONDITION_PTR("MS_WINDOW_TYPE * _pstCropWin ", ( _pstCropWin ));
        //CPPTEST_POST_CONDITION_PTR("MS_WINDOW_TYPE * _pstDstWin ", ( _pstDstWin ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Picture_Adjust_AFDSourceWindow_Logic5 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Picture_Adjust_AFDSourceWindow_Logic6 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _msAPI_Picture_Adjust_AFDSourceWindow(SRC_RATIO_INFO *, MS_WINDOW_TYPE *, MS_WINDOW_TYPE *) */
void TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic6()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstSrcRatioInfo) */ 
    SRC_RATIO_INFO * _pstSrcRatioInfo  = 0 ;
    SRC_RATIO_INFO stSrcRatioInfo;
    _pstSrcRatioInfo = &stSrcRatioInfo;

    /* Initializing argument 2 (pstCropWin) */ 
    MS_WINDOW_TYPE * _pstCropWin  = 0 ;
    MS_WINDOW_TYPE stCropWin;
    _pstCropWin = &stCropWin;

    /* Initializing argument 3 (pstDstWin) */ 
    MS_WINDOW_TYPE * _pstDstWin  = 0 ;
    MS_WINDOW_TYPE stDstWin;
    _pstDstWin = &stDstWin;


    _pstSrcRatioInfo->u8AFD = E_MVD_AFD_CENTRE_16X9_14X9;
    _pstSrcRatioInfo->u8AspectRate = MVD_ASP_4TO3;
    {
        /* Tested function call */
        BOOLEAN _return  = _msAPI_Picture_Adjust_AFDSourceWindow(_pstSrcRatioInfo, _pstCropWin, _pstDstWin);
        CPPTEST_ASSERT_EQUAL(7, u8Test_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic0_Call_msAPI_Picture_AdjustWidth_CutByHeight);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE,  _return );
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("SRC_RATIO_INFO * _pstSrcRatioInfo ", ( _pstSrcRatioInfo ));
        //CPPTEST_POST_CONDITION_PTR("MS_WINDOW_TYPE * _pstCropWin ", ( _pstCropWin ));
        //CPPTEST_POST_CONDITION_PTR("MS_WINDOW_TYPE * _pstDstWin ", ( _pstDstWin ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Picture_Adjust_AFDSourceWindow_Logic6 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Picture_Adjust_AFDSourceWindow_Logic7 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _msAPI_Picture_Adjust_AFDSourceWindow(SRC_RATIO_INFO *, MS_WINDOW_TYPE *, MS_WINDOW_TYPE *) */
void TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic7()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstSrcRatioInfo) */ 
    SRC_RATIO_INFO * _pstSrcRatioInfo  = 0 ;
    SRC_RATIO_INFO stSrcRatioInfo;
    _pstSrcRatioInfo = &stSrcRatioInfo;

    /* Initializing argument 2 (pstCropWin) */ 
    MS_WINDOW_TYPE * _pstCropWin  = 0 ;
    MS_WINDOW_TYPE stCropWin;
    _pstCropWin = &stCropWin;

    /* Initializing argument 3 (pstDstWin) */ 
    MS_WINDOW_TYPE * _pstDstWin  = 0 ;
    MS_WINDOW_TYPE stDstWin;
    _pstDstWin = &stDstWin;


    _pstSrcRatioInfo->u8AFD = E_MVD_AFD_CENTRE_16X9_4X3;
    _pstSrcRatioInfo->u8AspectRate = MVD_ASP_4TO3;
    {
        /* Tested function call */
        BOOLEAN _return  = _msAPI_Picture_Adjust_AFDSourceWindow(_pstSrcRatioInfo, _pstCropWin, _pstDstWin);
        CPPTEST_ASSERT_EQUAL(8, u8Test_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic0_Call_msAPI_Picture_AdjustWidth_CutByHeight);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE,  _return );
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("SRC_RATIO_INFO * _pstSrcRatioInfo ", ( _pstSrcRatioInfo ));
        //CPPTEST_POST_CONDITION_PTR("MS_WINDOW_TYPE * _pstCropWin ", ( _pstCropWin ));
        //CPPTEST_POST_CONDITION_PTR("MS_WINDOW_TYPE * _pstDstWin ", ( _pstDstWin ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Picture_Adjust_AFDSourceWindow_Logic7 */


/* CPPTEST_TEST_CASE_BEGIN test__msAPI_Picture_CalculateSAR_Logic0 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _msAPI_Picture_CalculateSAR(SRC_RATIO_INFO *, VDEC_CodecType) */
void TestSuit_MApp_XC_Sys_test__msAPI_Picture_CalculateSAR_Logic0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstSrcRatioInfo) */ 
    SRC_RATIO_INFO * _pstSrcRatioInfo  = 0 ;
    SRC_RATIO_INFO stSrcRatioInfo;
    _pstSrcRatioInfo = &stSrcRatioInfo;
    /* Initializing argument 2 (codecType) */ 
    VDEC_CodecType _codecType  = E_VDEC_CODEC_TYPE_MPEG2;
    _pstSrcRatioInfo->u8AspectRate = MVD_ASP_4TO3;
    {
        /* Tested function call */
        BOOLEAN _return  = _msAPI_Picture_CalculateSAR(_pstSrcRatioInfo, _codecType);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE,  _return );
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("SRC_RATIO_INFO * _pstSrcRatioInfo ", ( _pstSrcRatioInfo ));
    }
}
/* CPPTEST_TEST_CASE_END test__msAPI_Picture_CalculateSAR_Logic0 */

/* CPPTEST_TEST_CASE_BEGIN test__msAPI_Picture_CalculateSAR_Logic1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _msAPI_Picture_CalculateSAR(SRC_RATIO_INFO *, VDEC_CodecType) */
void TestSuit_MApp_XC_Sys_test__msAPI_Picture_CalculateSAR_Logic1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstSrcRatioInfo) */ 
    SRC_RATIO_INFO * _pstSrcRatioInfo  = 0 ;
    SRC_RATIO_INFO stSrcRatioInfo;
    _pstSrcRatioInfo = &stSrcRatioInfo;
    /* Initializing argument 2 (codecType) */ 
    VDEC_CodecType _codecType  = E_VDEC_CODEC_TYPE_MPEG2;
    _pstSrcRatioInfo->u8AspectRate = MVD_ASP_16TO9;
    {
        /* Tested function call */
        BOOLEAN _return  = _msAPI_Picture_CalculateSAR(_pstSrcRatioInfo, _codecType);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE,  _return );
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("SRC_RATIO_INFO * _pstSrcRatioInfo ", ( _pstSrcRatioInfo ));
    }
}
/* CPPTEST_TEST_CASE_END test__msAPI_Picture_CalculateSAR_Logic1 */

/* CPPTEST_TEST_CASE_BEGIN test__msAPI_Picture_CalculateSAR_Logic2 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _msAPI_Picture_CalculateSAR(SRC_RATIO_INFO *, VDEC_CodecType) */
void TestSuit_MApp_XC_Sys_test__msAPI_Picture_CalculateSAR_Logic2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstSrcRatioInfo) */ 
    SRC_RATIO_INFO * _pstSrcRatioInfo  = 0 ;
    SRC_RATIO_INFO stSrcRatioInfo;
    _pstSrcRatioInfo = &stSrcRatioInfo;
    /* Initializing argument 2 (codecType) */ 
    VDEC_CodecType _codecType  = E_VDEC_CODEC_TYPE_MPEG2;
    _pstSrcRatioInfo->u8AspectRate = MVD_ASP_16TO9;
    _pstSrcRatioInfo->u16VideoWidth = 16;
    _pstSrcRatioInfo->u16VideoHeight = 9;
    {
        /* Tested function call */
        BOOLEAN _return  = _msAPI_Picture_CalculateSAR(_pstSrcRatioInfo, _codecType);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE,  _return );
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("SRC_RATIO_INFO * _pstSrcRatioInfo ", ( _pstSrcRatioInfo ));
    }
}
/* CPPTEST_TEST_CASE_END test__msAPI_Picture_CalculateSAR_Logic2 */

/* CPPTEST_TEST_CASE_BEGIN test__msAPI_Picture_CalculateSAR_Logic3 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _msAPI_Picture_CalculateSAR(SRC_RATIO_INFO *, VDEC_CodecType) */
void TestSuit_MApp_XC_Sys_test__msAPI_Picture_CalculateSAR_Logic3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstSrcRatioInfo) */ 
    SRC_RATIO_INFO * _pstSrcRatioInfo  = 0 ;
    SRC_RATIO_INFO stSrcRatioInfo;
    _pstSrcRatioInfo = &stSrcRatioInfo;
    /* Initializing argument 2 (codecType) */ 
    VDEC_CodecType _codecType  = E_VDEC_CODEC_TYPE_MPEG2;
    _pstSrcRatioInfo->u8AspectRate = MVD_ASP_16TO9;
    _pstSrcRatioInfo->u16VideoWidth = 5;
    _pstSrcRatioInfo->u16VideoHeight = 4;
    {
        /* Tested function call */
        BOOLEAN _return  = _msAPI_Picture_CalculateSAR(_pstSrcRatioInfo, _codecType);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE,  _return );
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("SRC_RATIO_INFO * _pstSrcRatioInfo ", ( _pstSrcRatioInfo ));
    }
}
/* CPPTEST_TEST_CASE_END test__msAPI_Picture_CalculateSAR_Logic3 */

/* CPPTEST_TEST_CASE_BEGIN test__msAPI_Picture_CalculateSAR_Logic4 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _msAPI_Picture_CalculateSAR(SRC_RATIO_INFO *, VDEC_CodecType) */
void TestSuit_MApp_XC_Sys_test__msAPI_Picture_CalculateSAR_Logic4()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstSrcRatioInfo) */ 
    SRC_RATIO_INFO * _pstSrcRatioInfo  = 0 ;
    SRC_RATIO_INFO stSrcRatioInfo;
    _pstSrcRatioInfo = &stSrcRatioInfo;
    /* Initializing argument 2 (codecType) */ 
    VDEC_CodecType _codecType  = E_VDEC_CODEC_TYPE_H264;
    _pstSrcRatioInfo->u8AspectRate = 0xFF;

    {
        /* Tested function call */
        BOOLEAN _return  = _msAPI_Picture_CalculateSAR(_pstSrcRatioInfo, _codecType);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE,  _return );
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("SRC_RATIO_INFO * _pstSrcRatioInfo ", ( _pstSrcRatioInfo ));
    }
}
/* CPPTEST_TEST_CASE_END test__msAPI_Picture_CalculateSAR_Logic4 */

/* CPPTEST_TEST_CASE_BEGIN test__msAPI_Picture_CalculateSAR_Logic5 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _msAPI_Picture_CalculateSAR(SRC_RATIO_INFO *, VDEC_CodecType) */
void TestSuit_MApp_XC_Sys_test__msAPI_Picture_CalculateSAR_Logic5()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstSrcRatioInfo) */ 
    SRC_RATIO_INFO * _pstSrcRatioInfo  = 0 ;
    SRC_RATIO_INFO stSrcRatioInfo;
    _pstSrcRatioInfo = &stSrcRatioInfo;
    /* Initializing argument 2 (codecType) */ 
    VDEC_CodecType _codecType  = E_VDEC_CODEC_TYPE_H264;
    _pstSrcRatioInfo->u8AspectRate = 1;

    {
        /* Tested function call */
        BOOLEAN _return  = _msAPI_Picture_CalculateSAR(_pstSrcRatioInfo, _codecType);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE,  _return );
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("SRC_RATIO_INFO * _pstSrcRatioInfo ", ( _pstSrcRatioInfo ));
    }
}
/* CPPTEST_TEST_CASE_END test__msAPI_Picture_CalculateSAR_Logic5 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Picture_CalculateAFDWindow */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_Picture_CalculateAFDWindow(XC_SETWIN_INFO *, EN_ASPECT_RATIO_TYPE, MS_WINDOW_TYPE *, MS_WINDOW_TYPE *, SRC_RATIO_INFO *) */
BOOLEAN  bTest_MApp_XC_Sys_test_msAPI_Picture_CalculateAFDWindow_Call_msAPI_Picture_CalculateSAR;
void TestSuit_MApp_XC_Sys_test_msAPI_Picture_CalculateAFDWindow()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstXC_SetWin_Info) */ 
	MS_WINDOW_TYPE tCropWin,tDstWin;
    XC_SETWIN_INFO * _pstXC_SetWin_Info  = 0 ;
    /* Initializing argument 2 (enVideoScreen) */ 
    EN_ASPECT_RATIO_TYPE _enVideoScreen  = VIDEOSCREEN_MIN;
    /* Initializing argument 3 (pstCropWin) */ 
    MS_WINDOW_TYPE * _pstCropWin  = 0 ;
    MS_WINDOW_TYPE pstCropWin;
    _pstCropWin = &pstCropWin;
    /* Initializing argument 4 (pstDstWin) */ 
    MS_WINDOW_TYPE * _pstDstWin  = 0 ;
    MS_WINDOW_TYPE pstDstWin;
    _pstDstWin = &pstDstWin;
    /* Initializing argument 5 (pstSrcRatioInfo) */ 
    SRC_RATIO_INFO * _pstSrcRatioInfo  = 0 ;
    {
    	tDstWin.width = 720;
    	_pstDstWin->width = 1920;
        /* Tested function call */
        msAPI_Picture_CalculateAFDWindow(_pstXC_SetWin_Info, _enVideoScreen, _pstCropWin, _pstDstWin, _pstSrcRatioInfo);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE,  bTest_MApp_XC_Sys_test_msAPI_Picture_CalculateAFDWindow_Call_msAPI_Picture_CalculateSAR );
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_PTR("XC_SETWIN_INFO * _pstXC_SetWin_Info ", ( _pstXC_SetWin_Info ));
        //CPPTEST_POST_CONDITION_PTR("MS_WINDOW_TYPE * _pstCropWin ", ( _pstCropWin ));
        //CPPTEST_POST_CONDITION_PTR("MS_WINDOW_TYPE * _pstDstWin ", ( _pstDstWin ));
        //CPPTEST_POST_CONDITION_PTR("SRC_RATIO_INFO * _pstSrcRatioInfo ", ( _pstSrcRatioInfo ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Picture_CalculateAFDWindow */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Image_SetMirror */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Image_SetMirror(void) */
void TestSuit_MApp_XC_Sys_test_MApp_Image_SetMirror()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        MApp_Image_SetMirror();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Image_SetMirror */
