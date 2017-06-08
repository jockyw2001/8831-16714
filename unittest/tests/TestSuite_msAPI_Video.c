#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/msAPI_Video.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/msAPI_Video.c");

CPPTEST_TEST_SUITE(TestSuite_msAPI_Video);
CPPTEST_TEST(TestSuite_msAPI_Video_test_msAPI_VID_IsNeedFrameBufferLessMode_Yes);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_msAPI_Video_test_msAPI_VID_IsNeedFrameBufferLessMode_Yes();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_msAPI_Video);

void TestSuite_msAPI_Video_setUp()
{
}

void TestSuite_msAPI_Video_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_VID_IsNeedFrameBufferLessMode_Yes */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_VID_IsNeedFrameBufferLessMode(VDEC_DispInfo *) */
void TestSuite_msAPI_Video_test_msAPI_VID_IsNeedFrameBufferLessMode_Yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstVidStatus) */ 
    VDEC_DispInfo  stVidStatus;

    /* Initializing global variable geVDEC_CodecType */ 
    {
         geVDEC_CodecType  = E_VDEC_CODEC_TYPE_H264;
    }

    { // fbl mode
        stVidStatus.u16HorSize = 1280;
        stVidStatus.u16VerSize = 720;

        /* Tested function call */
        BOOLEAN _return  = msAPI_VID_IsNeedFrameBufferLessMode(&stVidStatus);

        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 0, ( _return ) )
    }

    { // fbl mode
        stVidStatus.u16HorSize = 1920;
        stVidStatus.u16VerSize = 1080;

        /* Tested function call */
        BOOLEAN _return  = msAPI_VID_IsNeedFrameBufferLessMode(&stVidStatus);

        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
        //CPPTEST_ASSERT_EQUAL( 0, ( _return ) )
    }

}
/* CPPTEST_TEST_CASE_END test_msAPI_VID_IsNeedFrameBufferLessMode_Yes */
