#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/multimedia/mapp_photo_display.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/multimedia/mapp_photo_display.c");

CPPTEST_TEST_SUITE(TestSuite_mapp_photo_display);
CPPTEST_TEST(TestSuite_mapp_photo_display_test__MApp_Photo_Display_ColorFmtTransfer_case1);
CPPTEST_TEST(TestSuite_mapp_photo_display_test__MApp_Photo_SetScalarVOP2Display);
CPPTEST_TEST(TestSuite_mapp_photo_display_test_MApp_Photo_Zooming);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_mapp_photo_display_test__MApp_Photo_Display_ColorFmtTransfer_case1();
void TestSuite_mapp_photo_display_test__MApp_Photo_SetScalarVOP2Display();
void TestSuite_mapp_photo_display_test_MApp_Photo_Zooming();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_mapp_photo_display);

void TestSuite_mapp_photo_display_setUp()
{
}

void TestSuite_mapp_photo_display_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test__MApp_Photo_Display_ColorFmtTransfer_case1 */
/* CPPTEST_TEST_CASE_CONTEXT void _MApp_Photo_Display_ColorFmtTransfer(U16, U16, U32, GFX_Buffer_Format, U32, GFX_Buffer_Format) */
void TestSuite_mapp_photo_display_test__MApp_Photo_Display_ColorFmtTransfer_case1()
{
    U16 _u16Width  = 0u;
    U16 _u16Height  = 0u;
    U32 _u32SrcBuffAddr  = 0ul;
    GFX_Buffer_Format _eSrcFmt  = GFX_FMT_YUV422;
    U32 _u32DstBuffAddr  = 0ul;
    GFX_Buffer_Format _enDstFmt  = GFX_FMT_ARGB8888;
    _MApp_Photo_Display_ColorFmtTransfer(_u16Width, _u16Height, _u32SrcBuffAddr, _eSrcFmt, _u32DstBuffAddr, _enDstFmt);



}
/* CPPTEST_TEST_CASE_END test__MApp_Photo_Display_ColorFmtTransfer_case1 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_Photo_SetScalarVOP2Display */
/* CPPTEST_TEST_CASE_CONTEXT void _MApp_Photo_SetScalarVOP2Display(U16, U16, U16, U16, U16, U16, U16, U16, U32, U16, U16) */
void TestSuite_mapp_photo_display_test__MApp_Photo_SetScalarVOP2Display()
{
	stu32DisplayedFrameIndex = 0;
	bMPODisplayEnabled = 1;

	U16 _u16InputX = 0;
	U16 _u16InputY = 0;
	U16 _u16InputWidth = 0;
	U16 _u16InputHeight = 0;
	U16 _u16OutputX = 0;
	U16 _u16OutputY = 0;
	U16 _u16OutputWidth = 0;
	U16 _u16OutputHeight = 0;
	U32 _u32SrcAddr = 0;
	U16 _u16SrcWidth = 0;
	U16 _u16SrcHeight = 0;

	_MApp_Photo_SetScalarVOP2Display(_u16InputX, _u16InputY, _u16InputWidth, _u16InputHeight, _u16OutputX, _u16OutputY, _u16OutputWidth, _u16OutputHeight, _u32SrcAddr, _u16SrcWidth, _u16SrcHeight);

	CPPTEST_ASSERT_INTEGER_EQUAL(0, ( gstVidStatus.u16CropBottom ));
	CPPTEST_ASSERT_INTEGER_EQUAL(0, ( gstVidStatus.u16CropTop ));
	CPPTEST_ASSERT_INTEGER_EQUAL(0, ( gstVidStatus.u16CropRight ));
	CPPTEST_ASSERT_INTEGER_EQUAL(0, ( gstVidStatus.u16CropLeft ));
	CPPTEST_ASSERT_INTEGER_EQUAL(0, ( gstVidStatus.u16CropTop ));
	CPPTEST_ASSERT_INTEGER_EQUAL(0, ( gstVidStatus.u16CropTop ));
}
/* CPPTEST_TEST_CASE_END test__MApp_Photo_SetScalarVOP2Display */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_Photo_Zooming */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Photo_AdjustSrcWinSize(void) */
void TestSuite_mapp_photo_display_test_MApp_Photo_Zooming()
{
	EN_PHOTO_ZOOMING _zoominfo = EN_PHOTO_ZOOM_1_4;

	m_enZooming = EN_PHOTO_ZOOM_1_8;
	m_enRotation = EN_PHOTO_ROTATE_360;

	BOOLEAN _return = MApp_Photo_Zooming(_zoominfo);

	CPPTEST_ASSERT_INTEGER_EQUAL(EN_PHOTO_ZOOM_1_8, ( m_enZooming ));
	CPPTEST_ASSERT_INTEGER_EQUAL(0, ( _return ));
}
/* CPPTEST_TEST_CASE_END test_MApp_Photo_Zooming */
