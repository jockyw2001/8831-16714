#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/msAPI_VD.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/msAPI_VD.c");

CPPTEST_TEST_SUITE(TestSuite_msAPI_VD);
CPPTEST_TEST(TestSuite_msAPI_VD_test_msAPI_AVD_GetCaptureWindow_InternalVD);
CPPTEST_TEST(TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_ARC_INVALID);
CPPTEST_TEST(TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_14x9_FULL_CENTER);
CPPTEST_TEST(TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_16x9_ANAMORPHIC);
CPPTEST_TEST(TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_Default);
CPPTEST_TEST(TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_4x3_FULL);
CPPTEST_TEST(TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_14x9_LETTERBOX_CENTER);
CPPTEST_TEST(TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_14x9_LETTERBOX_TOP);
CPPTEST_TEST(TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_16x9_LETTERBOX_CENTER);
CPPTEST_TEST(TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_16x9_LETTERBOX_TOP);
CPPTEST_TEST(TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_ABOVE16x9_LETTERBOX_CENTER);
CPPTEST_TEST_SUITE_END();

void TestSuite_msAPI_VD_test_msAPI_AVD_GetCaptureWindow_InternalVD();
void TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_ARC_INVALID();
void TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_14x9_FULL_CENTER();
void TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_16x9_ANAMORPHIC();
void TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_Default();
void TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_4x3_FULL();
void TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_14x9_LETTERBOX_CENTER();
void TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_14x9_LETTERBOX_TOP();
void TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_16x9_LETTERBOX_CENTER();
void TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_16x9_LETTERBOX_TOP();
void TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_ABOVE16x9_LETTERBOX_CENTER();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_msAPI_VD);

void TestSuite_msAPI_VD_setUp()
{
}

void TestSuite_msAPI_VD_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_AVD_GetCaptureWindow_InternalVD */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_AVD_GetCaptureWindow(MS_WINDOW_TYPE *, EN_VD_SIGNALTYPE, MS_BOOL) */
void TestSuite_msAPI_VD_test_msAPI_AVD_GetCaptureWindow_InternalVD()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (stCapWin) */ 
    MS_WINDOW_TYPE  _stCapWin;
    /* Initializing argument 2 (enVideoSystem) */ 
    EN_VD_SIGNALTYPE _enVideoSystem  = SIG_NTSC;
    /* Initializing argument 3 (IsUseExtVD) */ 
    MS_BOOL _IsUseExtVD  = 0;


    // Check VideoCaptureWinTbl size
    CPPTEST_ASSERT_EQUAL(SIG_NUMS, ( sizeof(VideoCaptureWinTbl)/sizeof(MS_WINDOW_TYPE) ) );

    { // NTSC
    	_enVideoSystem  = SIG_NTSC;
        /* Tested function call */
        msAPI_AVD_GetCaptureWindow(&_stCapWin, _enVideoSystem, _IsUseExtVD);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(480, (_stCapWin.height) );
    }

    { // PAL
    	_enVideoSystem  = SIG_PAL;
        /* Tested function call */
        msAPI_AVD_GetCaptureWindow(&_stCapWin, _enVideoSystem, _IsUseExtVD);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(576, (_stCapWin.height) );
    }

    { // SECAM
    	_enVideoSystem  = SIG_SECAM;
        /* Tested function call */
        msAPI_AVD_GetCaptureWindow(&_stCapWin, _enVideoSystem, _IsUseExtVD);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(576, (_stCapWin.height) );
    }

    { // NTSC_443
    	_enVideoSystem  = SIG_NTSC_443;
        /* Tested function call */
        msAPI_AVD_GetCaptureWindow(&_stCapWin, _enVideoSystem, _IsUseExtVD);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(480, (_stCapWin.height) );
    }

    { // PAL_M
    	_enVideoSystem  = SIG_PAL_M;
        /* Tested function call */
        msAPI_AVD_GetCaptureWindow(&_stCapWin, _enVideoSystem, _IsUseExtVD);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(480, (_stCapWin.height) );
    }

    { // PAL_NC
    	_enVideoSystem  = SIG_PAL_NC;
        /* Tested function call */
        msAPI_AVD_GetCaptureWindow(&_stCapWin, _enVideoSystem, _IsUseExtVD);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(576, (_stCapWin.height) );
    }

}
/* CPPTEST_TEST_CASE_END test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_Default */


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_4x3_FULL */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsVDHasSignal(void) */
void TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_4x3_FULL()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_eCurrentVideoStandard */ 
    {
         m_eCurrentVideoStandard  = E_VIDEOSTANDARD_PAL_BGHI;
         ASPECT_RATIO_TYPE eAspectRatioCode = ARC4x3_FULL;
    }
    {
        /* Tested function call */
        ASPECT_RATIO_TYPE _return  = msAPI_AVD_GetAspectRatioCodeOfWSS();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( ARC4x3_FULL, ( _return ))
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_4x3_FULL */


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_14x9_LETTERBOX_CENTER */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsVDHasSignal(void) */
void TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_14x9_LETTERBOX_CENTER()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_eCurrentVideoStandard */ 
    {
         m_eCurrentVideoStandard  = E_VIDEOSTANDARD_PAL_BGHI;
         ASPECT_RATIO_TYPE eAspectRatioCode = ARC4x3_FULL;
    }
    {
        /* Tested function call */
        ASPECT_RATIO_TYPE _return  = msAPI_AVD_GetAspectRatioCodeOfWSS();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( ARC14x9_LETTERBOX_CENTER, ( _return ))
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_14x9_LETTERBOX_CENTER */


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_14x9_LETTERBOX_TOP */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsVDHasSignal(void) */
void TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_14x9_LETTERBOX_TOP()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_eCurrentVideoStandard */ 
    {
         m_eCurrentVideoStandard  = E_VIDEOSTANDARD_PAL_BGHI;
         ASPECT_RATIO_TYPE eAspectRatioCode = ARC4x3_FULL;
    }
    {
        /* Tested function call */
        ASPECT_RATIO_TYPE _return  = msAPI_AVD_GetAspectRatioCodeOfWSS();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( ARC14x9_LETTERBOX_TOP, ( _return ))
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_14x9_LETTERBOX_TOP */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_16x9_LETTERBOX_CENTER */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsVDHasSignal(void) */
void TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_16x9_LETTERBOX_CENTER()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_eCurrentVideoStandard */ 
    {
         m_eCurrentVideoStandard  = E_VIDEOSTANDARD_PAL_BGHI;
         ASPECT_RATIO_TYPE eAspectRatioCode = ARC4x3_FULL;
    }
    {
        /* Tested function call */
        ASPECT_RATIO_TYPE _return  = msAPI_AVD_GetAspectRatioCodeOfWSS();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( ARC16x9_LETTERBOX_CENTER, ( _return ))
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_16x9_LETTERBOX_CENTER */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_16x9_LETTERBOX_TOP */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsVDHasSignal(void) */
void TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_16x9_LETTERBOX_TOP()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_eCurrentVideoStandard */ 
    {
         m_eCurrentVideoStandard  = E_VIDEOSTANDARD_PAL_BGHI;
         ASPECT_RATIO_TYPE eAspectRatioCode = ARC4x3_FULL;
    }
    {
        /* Tested function call */
        ASPECT_RATIO_TYPE _return  = msAPI_AVD_GetAspectRatioCodeOfWSS();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( ARC16x9_LETTERBOX_TOP, ( _return ))
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_16x9_LETTERBOX_TOP */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_ABOVE16x9_LETTERBOX_CENTER */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsVDHasSignal(void) */
void TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_ABOVE16x9_LETTERBOX_CENTER()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_eCurrentVideoStandard */ 
    {
         m_eCurrentVideoStandard  = E_VIDEOSTANDARD_PAL_BGHI;
         ASPECT_RATIO_TYPE eAspectRatioCode = ARC4x3_FULL;
    }
    {
        /* Tested function call */
        ASPECT_RATIO_TYPE _return  = msAPI_AVD_GetAspectRatioCodeOfWSS();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( ARC_ABOVE16x9_LETTERBOX_CENTER, ( _return ))
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_AVD_GetCaptureWindow_InternalVD */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_AVD_GetAspectRatioCodeOfWSS_ARC_INVALID */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsVDHasSignal(void) */
void TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_ARC_INVALID()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_eCurrentVideoStandard */ 
    {
        m_eCurrentVideoStandard  = E_VIDEOSTANDARD_PAL_BGHI;
        ASPECT_RATIO_TYPE eAspectRatioCode = ARC4x3_FULL;
    }
    {
        /* Tested function call */
        ASPECT_RATIO_TYPE _return  = msAPI_AVD_GetAspectRatioCodeOfWSS();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( ARC_INVALID, ( _return ))
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_AVD_GetAspectRatioCodeOfWSS_ARC_INVALID */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_14x9_FULL_CENTER */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsVDHasSignal(void) */
void TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_14x9_FULL_CENTER()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_eCurrentVideoStandard */ 
    {
        m_eCurrentVideoStandard  = E_VIDEOSTANDARD_PAL_BGHI;
        ASPECT_RATIO_TYPE eAspectRatioCode = ARC4x3_FULL;
    }
    {
        /* Tested function call */
        ASPECT_RATIO_TYPE _return  = msAPI_AVD_GetAspectRatioCodeOfWSS();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( ARC14x9_FULL_CENTER, ( _return ))
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_14x9_FULL_CENTER */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_16x9_ANAMORPHIC */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsVDHasSignal(void) */
void TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_16x9_ANAMORPHIC()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_eCurrentVideoStandard */ 
    {
        m_eCurrentVideoStandard  = E_VIDEOSTANDARD_PAL_BGHI;
        ASPECT_RATIO_TYPE eAspectRatioCode = ARC4x3_FULL;
    }
    {
        /* Tested function call */
        ASPECT_RATIO_TYPE _return  = msAPI_AVD_GetAspectRatioCodeOfWSS();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( ARC16x9_ANAMORPHIC, ( _return ))
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_16x9_ANAMORPHIC */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_Default */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsVDHasSignal(void) */
void TestSuite_msAPI_VD_test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_Default()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_eCurrentVideoStandard */ 
    {
        m_eCurrentVideoStandard  = E_VIDEOSTANDARD_PAL_BGHI;
        ASPECT_RATIO_TYPE eAspectRatioCode = ARC4x3_FULL;
    }
    {
        /* Tested function call */
        ASPECT_RATIO_TYPE _return  = msAPI_AVD_GetAspectRatioCodeOfWSS();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( ARC_INVALID, ( _return ))
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_AVD_GetAspectRatioCodeOfWSS_case_WSS_ABOVE16x9_LETTERBOX_CENTER */
