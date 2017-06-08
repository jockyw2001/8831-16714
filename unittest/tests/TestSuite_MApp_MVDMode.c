#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app/MApp_MVDMode.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app/MApp_MVDMode.c");

CPPTEST_TEST_SUITE(TestSuite_MApp_MVDMode);
CPPTEST_TEST(TestSuite_MApp_MVDMode_test_MApp_MVD_VariableInit);
CPPTEST_TEST(TestSuite_MApp_MVDMode_test_MApp_VID_VariableInit_IS_HVD_CODEC);
CPPTEST_TEST(TestSuite_MApp_MVDMode_test_MApp_VID_VariableInit_NOT_HVD_CODEC);
CPPTEST_TEST(TestSuite_MApp_MVDMode_test_MApp_AVCH264_PrepareTimingChange);
CPPTEST_TEST(TestSuite_MApp_MVDMode_test_MApp_MVD_PrepareTimingChange);
CPPTEST_TEST(TestSuite_MApp_MVDMode_test_MApp_VID_PrepareTimingChange_IS_HVD_CODEC);
CPPTEST_TEST(TestSuite_MApp_MVDMode_test_MApp_VID_PrepareTimingChange_NOT_HVD_CODEC);
CPPTEST_TEST(TestSuite_MApp_MVDMode_test_MApp_VID_SetMode_IS_HVD_CODEC);
CPPTEST_TEST(TestSuite_MApp_MVDMode_test_MApp_VID_SetMode_NOT_HVD_CODEC);
CPPTEST_TEST(TestSuite_MApp_MVDMode_test_MApp_MVD_IsAspectRatioWide_TRUE);
CPPTEST_TEST(TestSuite_MApp_MVDMode_test_MApp_MVD_IsAspectRatioWide_FALSE);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_MApp_MVDMode_test_MApp_MVD_VariableInit();
void TestSuite_MApp_MVDMode_test_MApp_VID_VariableInit_IS_HVD_CODEC();
void TestSuite_MApp_MVDMode_test_MApp_VID_VariableInit_NOT_HVD_CODEC();
void TestSuite_MApp_MVDMode_test_MApp_AVCH264_PrepareTimingChange();
void TestSuite_MApp_MVDMode_test_MApp_MVD_PrepareTimingChange();
void TestSuite_MApp_MVDMode_test_MApp_VID_PrepareTimingChange_IS_HVD_CODEC();
void TestSuite_MApp_MVDMode_test_MApp_VID_PrepareTimingChange_NOT_HVD_CODEC();
void TestSuite_MApp_MVDMode_test_MApp_VID_SetMode_IS_HVD_CODEC();
void TestSuite_MApp_MVDMode_test_MApp_VID_SetMode_NOT_HVD_CODEC();
void TestSuite_MApp_MVDMode_test_MApp_MVD_IsAspectRatioWide_TRUE();
void TestSuite_MApp_MVDMode_test_MApp_MVD_IsAspectRatioWide_FALSE();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_MApp_MVDMode);

void TestSuite_MApp_MVDMode_setUp()
{
}

void TestSuite_MApp_MVDMode_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_MVD_VariableInit */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_MVD_VariableInit(void) */
void TestSuite_MApp_MVDMode_test_MApp_MVD_VariableInit()
{
    /* Pre-condition initialization */
    /* Initializing global variable enMVDVideoStatus */ 
    {
         enMVDVideoStatus  = MVD_UNKNOWN_VIDEO;
    }
    /* Initializing global variable u8MVDTimingStableCount */ 
    {
         u8MVDTimingStableCount  = 0;
    }
    /* Initializing global variable u8MVDDecodeCount */ 
    {
         u8MVDDecodeCount  = 0;
    }
    /* Initializing global variable bMVDDoSetMode */ 
    {
         bMVDDoSetMode  = 0;
    }
    /* Initializing global variable bPrepareChange */ 
    {
         bPrepareChange  = 0;
    }
    /* Initializing global variable bFirstTimeCheck */ 
    {
         bFirstTimeCheck  = 0;
    }
    /* Initializing global variable fCurMVDValidFlag */ 
    {
         fCurMVDValidFlag  = 0;
    }
    /* Initializing global variable sbIsAspectRatioWide */ 
    {
         sbIsAspectRatioWide  = 0;
    }
    /* Initializing global variable gstVidStatus */ 
    {
         gstVidStatus.u16HorSize  = 0u;
         gstVidStatus.u16VerSize  = 0u;
         gstVidStatus.u32FrameRate  = 0ul;
         gstVidStatus.u8Interlace  = 0;
         gstVidStatus.u8AFD  = 0;
         gstVidStatus.u16SarWidth  = 0u;
         gstVidStatus.u16SarHeight  = 0u;
         gstVidStatus.u16CropRight  = 0u;
         gstVidStatus.u16CropLeft  = 0u;
         gstVidStatus.u16CropBottom  = 0u;
         gstVidStatus.u16CropTop  = 0u;
         gstVidStatus.u16Pitch  = 0u;
         gstVidStatus.u16PTSInterval  = 0u;
         gstVidStatus.u8MPEG1  = 0;
         gstVidStatus.u8PlayMode  = 0;
         gstVidStatus.u8FrcMode  = 0;
         gstVidStatus.u8AspectRate  = 0;
         gstVidStatus.bWithChroma  = 0;
         gstVidStatus.bColorInXVYCC  = 0;
         gstVidStatus.u32DynScalingAddr  = 0ul;
         gstVidStatus.u32DynScalingSize  = 0ul;
         gstVidStatus.u8DynScalingDepth  = 0;
         gstVidStatus.bEnableMIUSel  = 0;
         gstVidStatus.u32AspectWidth  = 0ul;
         gstVidStatus.u32AspectHeight  = 0ul;
    }
    /* Initializing global variable bMVDTimingChange */ 
    {
         bMVDTimingChange  = 0;
    }
    /* Initializing global variable bFastTimingCheck */ 
    {
         bFastTimingCheck  = 0;
    }
    /* Initializing global variable gstPreVidStatus */ 
    {
         gstPreVidStatus.u16HorSize  = 0u;
         gstPreVidStatus.u16VerSize  = 0u;
         gstPreVidStatus.u32FrameRate  = 0ul;
         gstPreVidStatus.u8Interlace  = 0;
         gstPreVidStatus.u8AFD  = 0;
         gstPreVidStatus.u16SarWidth  = 0u;
         gstPreVidStatus.u16SarHeight  = 0u;
         gstPreVidStatus.u16CropRight  = 0u;
         gstPreVidStatus.u16CropLeft  = 0u;
         gstPreVidStatus.u16CropBottom  = 0u;
         gstPreVidStatus.u16CropTop  = 0u;
         gstPreVidStatus.u16Pitch  = 0u;
         gstPreVidStatus.u16PTSInterval  = 0u;
         gstPreVidStatus.u8MPEG1  = 0;
         gstPreVidStatus.u8PlayMode  = 0;
         gstPreVidStatus.u8FrcMode  = 0;
         gstPreVidStatus.u8AspectRate  = 0;
         gstPreVidStatus.bWithChroma  = 0;
         gstPreVidStatus.bColorInXVYCC  = 0;
         gstPreVidStatus.u32DynScalingAddr  = 0ul;
         gstPreVidStatus.u32DynScalingSize  = 0ul;
         gstPreVidStatus.u8DynScalingDepth  = 0;
         gstPreVidStatus.bEnableMIUSel  = 0;
         gstPreVidStatus.u32AspectWidth  = 0ul;
         gstPreVidStatus.u32AspectHeight  = 0ul;
    }
    /* Initializing global variable u32MonitorMVDValidTimer */ 
    {
         u32MonitorMVDValidTimer  = 0ul;
    }
    /* Initializing global variable u32FFReadyTimer */ 
    {
         u32FFReadyTimer  = 0ul;
    }
    {
        /* Tested function call */
        MApp_MVD_VariableInit();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MVD_UNKNOWN_VIDEO, ( enMVDVideoStatus ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( u8MVDTimingStableCount ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( u8MVDDecodeCount ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( bMVDDoSetMode ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( bPrepareChange ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( bFirstTimeCheck ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( fCurMVDValidFlag ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( sbIsAspectRatioWide ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( bMVDTimingChange ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( bFastTimingCheck ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MVD_VariableInit */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VID_VariableInit_IS_HVD_CODEC */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_VID_VariableInit(void) */
void TestSuite_MApp_MVDMode_test_MApp_VID_VariableInit_IS_HVD_CODEC()
{
    /* Pre-condition initialization */
    /* Initializing global variable u32PicCounterTimer */ 
    {
         u32PicCounterTimer  = 0ul;
    }
    /* Initializing global variable PictureCounter */ 
    {
         PictureCounter  = 0ul;
    }
    /* Initializing global variable BadPictureCounter */ 
    {
         BadPictureCounter  = 0;
    }
    /* Initializing global variable g_bSetModeDone */ 
    {
         g_bSetModeDone  = 0;
    }
    /* Initializing global variable g_eCodecType */ 
    {
         g_eCodecType  = E_VDEC_CODEC_TYPE_H264;
    }
    {
        /* Tested function call */
        MApp_VID_VariableInit();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0ul, ( PictureCounter ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( BadPictureCounter ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( g_bSetModeDone ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VID_VariableInit_IS_HVD_CODEC */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VID_VariableInit_NOT_HVD_CODEC */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_VID_VariableInit(void) */
void TestSuite_MApp_MVDMode_test_MApp_VID_VariableInit_NOT_HVD_CODEC()
{
    /* Pre-condition initialization */
    /* Initializing global variable u32PicCounterTimer */ 
    {
         u32PicCounterTimer  = 0ul;
    }
    /* Initializing global variable PictureCounter */ 
    {
         PictureCounter  = 0ul;
    }
    /* Initializing global variable BadPictureCounter */ 
    {
         BadPictureCounter  = 0;
    }
    /* Initializing global variable g_bSetModeDone */ 
    {
         g_bSetModeDone  = 0;
    }
    /* Initializing global variable g_eCodecType */ 
    {
         g_eCodecType  = E_VDEC_CODEC_TYPE_MPEG2;
    }
    {
        /* Tested function call */
        MApp_VID_VariableInit();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0ul, ( PictureCounter ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( BadPictureCounter ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( g_bSetModeDone ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VID_VariableInit_NOT_HVD_CODEC */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_AVCH264_PrepareTimingChange */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_AVCH264_PrepareTimingChange(SCALER_WIN) */
void TestSuite_MApp_MVDMode_test_MApp_AVCH264_PrepareTimingChange()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */ 
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    {
        /* Tested function call */
        MApp_AVCH264_PrepareTimingChange(_eWindow);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_AVCH264_PrepareTimingChange */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MVD_PrepareTimingChange */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_MVD_PrepareTimingChange(SCALER_WIN) */
void TestSuite_MApp_MVDMode_test_MApp_MVD_PrepareTimingChange()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */ 
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    {
        /* Tested function call */
        MApp_MVD_PrepareTimingChange(_eWindow);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MVD_PrepareTimingChange */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VID_PrepareTimingChange_IS_HVD_CODEC */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_VID_PrepareTimingChange(SCALER_WIN) */
void TestSuite_MApp_MVDMode_test_MApp_VID_PrepareTimingChange_IS_HVD_CODEC()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */ 
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    {
        /* Tested function call */
        MApp_VID_PrepareTimingChange(_eWindow);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VID_PrepareTimingChange_IS_HVD_CODEC */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VID_PrepareTimingChange_NOT_HVD_CODEC */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_VID_PrepareTimingChange(SCALER_WIN) */
void TestSuite_MApp_MVDMode_test_MApp_VID_PrepareTimingChange_NOT_HVD_CODEC()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */ 
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    {
        /* Tested function call */
        MApp_VID_PrepareTimingChange(_eWindow);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VID_PrepareTimingChange_NOT_HVD_CODEC */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VID_SetMode_IS_HVD_CODEC */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_VID_SetMode(SCALER_WIN) */
void TestSuite_MApp_MVDMode_test_MApp_VID_SetMode_IS_HVD_CODEC()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */ 
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    /* Initializing global variable u32MvdPicCountTimer */ 
    {
         u32MvdPicCountTimer  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_VID_SetMode(_eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VID_SetMode_IS_HVD_CODEC */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VID_SetMode_NOT_HVD_CODEC */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_VID_SetMode(SCALER_WIN) */
void TestSuite_MApp_MVDMode_test_MApp_VID_SetMode_NOT_HVD_CODEC()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */ 
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    /* Initializing global variable u32MvdPicCountTimer */
    {
         u32MvdPicCountTimer  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_VID_SetMode(_eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VID_SetMode_NOT_HVD_CODEC */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_MVD_IsAspectRatioWide_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_MVD_IsAspectRatioWide(void) */
void TestSuite_MApp_MVDMode_test_MApp_MVD_IsAspectRatioWide_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing global variable sbIsAspectRatioWide */ 
    {
         sbIsAspectRatioWide  = 1;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_MVD_IsAspectRatioWide();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MVD_IsAspectRatioWide_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MVD_IsAspectRatioWide_FALSE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_MVD_IsAspectRatioWide(void) */
void TestSuite_MApp_MVDMode_test_MApp_MVD_IsAspectRatioWide_FALSE()
{
    /* Pre-condition initialization */
    /* Initializing global variable sbIsAspectRatioWide */ 
    {
         sbIsAspectRatioWide  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_MVD_IsAspectRatioWide();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MVD_IsAspectRatioWide_FALSE */
