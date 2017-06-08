#include "cpptest.h"

#include "mapp_videoplayer.h"

CPPTEST_CONTEXT("/UTProject/multimedia/mapp_videoplayer.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/multimedia/mapp_videoplayer.c");

CPPTEST_TEST_SUITE(TestSuite_mapp_videoplayer);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MAPP_VDPlayer_SetPIPDisplayWindow_eWindow_not_MAIN_WINDOW);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MAPP_VDPlayer_SetPIPDisplayWindow_pstDispWin_NULL_m_eVDPlayerFlgs_not_E_VDPLAYER_FLG_PREVIEW);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MAPP_VDPlayer_SetPIPDisplayWindow_MApi_XC_IsCurrentFrameBufferLessMode_return_TRUE);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MAPP_VDPlayer_SetPIPDisplayWindow_m_eVDPlayerFlgs_E_VDPLAYER_FLG_PREVIEW);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_AdjustRatioByPAR_case1);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_BeginPreview_TRUE);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Stop__gbEnableInternalSubtitle_TRUE);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Play_return_TRUE);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_CheckAndGenDRMData_TRUE);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_GetDRMRegistrationCode_TRUE);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Deactivate_TRUE);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_QueryDRMRentalStatus_TRUE);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_CheckDRMAutuorization_TRUE);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_CheckDRMActivationFile_TRUE);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_GetDRMDeactivationCode_TRUE);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_msAPI_VDPlayer_Demuxer_CalVideoFrameTime_case1);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Init_TRUE);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Init_Abort_TRUE);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetAudioTrackID_TRUE);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetSubtitleTrackID_return_FALSE);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetStep_return_FALSE);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetStep_return_TRUE);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetRepeatAB_return_FALSE);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetRepeatAB_return_TRUE);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetTrickMode_return_FALSE);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetTrickMode_return_TRUE);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetPlayPosition_return_TRUE);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetSubtitleTrackID_return_TRUE);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SubtitleTimeShift_return_TRUE);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test__MApp_VDPlayer_CheckPreviewAbortKey_return_TRUE);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_ClearDRMMemory_return_TRUE);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_ClearVDPlayerAckFlags);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetbDrmRentalStatus);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetbDrmAuthorization);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetbDrmActivationFile);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_msAPI_VDPlayer_Setu8VDPlayerInitResult);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Setu8VDPlayerSetAudioTrackResult);
CPPTEST_TEST(TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Setu8VDPlayerStepPlayResult);

CPPTEST_TEST_SUITE_END();


void TestSuite_mapp_videoplayer_test_MAPP_VDPlayer_SetPIPDisplayWindow_eWindow_not_MAIN_WINDOW();
void TestSuite_mapp_videoplayer_test_MAPP_VDPlayer_SetPIPDisplayWindow_pstDispWin_NULL_m_eVDPlayerFlgs_not_E_VDPLAYER_FLG_PREVIEW();
void TestSuite_mapp_videoplayer_test_MAPP_VDPlayer_SetPIPDisplayWindow_MApi_XC_IsCurrentFrameBufferLessMode_return_TRUE();
void TestSuite_mapp_videoplayer_test_MAPP_VDPlayer_SetPIPDisplayWindow_m_eVDPlayerFlgs_E_VDPLAYER_FLG_PREVIEW();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_AdjustRatioByPAR_case1();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_BeginPreview_TRUE();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Stop__gbEnableInternalSubtitle_TRUE();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Play_return_TRUE();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_CheckAndGenDRMData_TRUE();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_GetDRMRegistrationCode_TRUE();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Deactivate_TRUE();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_QueryDRMRentalStatus_TRUE();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_CheckDRMAutuorization_TRUE();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_CheckDRMActivationFile_TRUE();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_GetDRMDeactivationCode_TRUE();
void TestSuite_mapp_videoplayer_test_msAPI_VDPlayer_Demuxer_CalVideoFrameTime_case1();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Init_TRUE();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Init_Abort_TRUE();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetAudioTrackID_TRUE();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetSubtitleTrackID_return_FALSE();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetStep_return_FALSE();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetStep_return_TRUE();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetRepeatAB_return_FALSE();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetRepeatAB_return_TRUE();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetTrickMode_return_FALSE();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetTrickMode_return_TRUE();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetPlayPosition_return_TRUE();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetSubtitleTrackID_return_TRUE();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SubtitleTimeShift_return_TRUE();
void TestSuite_mapp_videoplayer_test__MApp_VDPlayer_CheckPreviewAbortKey_return_TRUE();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_ClearDRMMemory_return_TRUE();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_ClearVDPlayerAckFlags();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetbDrmRentalStatus();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetbDrmAuthorization();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetbDrmActivationFile();
void TestSuite_mapp_videoplayer_test_msAPI_VDPlayer_Setu8VDPlayerInitResult();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Setu8VDPlayerSetAudioTrackResult();
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Setu8VDPlayerStepPlayResult();

CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_mapp_videoplayer);

void TestSuite_mapp_videoplayer_setUp()
{
}

void TestSuite_mapp_videoplayer_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MAPP_VDPlayer_SetPIPDisplayWindow_eWindow_not_MAIN_WINDOW */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MAPP_VDPlayer_SetPIPDisplayWindow(SCALER_WIN, MS_WINDOW_TYPE *) */
void TestSuite_mapp_videoplayer_test_MAPP_VDPlayer_SetPIPDisplayWindow_eWindow_not_MAIN_WINDOW()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */
    SCALER_WIN _eWindow  = SUB_WINDOW;
    /* Initializing argument 2 (pstDispWin) */
    MS_WINDOW_TYPE * _pstDispWin  = 0 ;

    {
        /* Tested function call */
        BOOLEAN _return  = MAPP_VDPlayer_SetPIPDisplayWindow(_eWindow, _pstDispWin);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MAPP_VDPlayer_SetPIPDisplayWindow_eWindow_not_MAIN_WINDOW */

/* CPPTEST_TEST_CASE_BEGIN test_MAPP_VDPlayer_SetPIPDisplayWindow_pstDispWin_NULL_m_eVDPlayerFlgs_not_E_VDPLAYER_FLG_PREVIEW */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MAPP_VDPlayer_SetPIPDisplayWindow(SCALER_WIN, MS_WINDOW_TYPE *) */
void TestSuite_mapp_videoplayer_test_MAPP_VDPlayer_SetPIPDisplayWindow_pstDispWin_NULL_m_eVDPlayerFlgs_not_E_VDPLAYER_FLG_PREVIEW()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    /* Initializing argument 2 (pstDispWin) */
    MS_WINDOW_TYPE * _pstDispWin  = 0 ;
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
    /* Initializing global variable m_eVDPlayerFlgs */
    {
         m_eVDPlayerFlgs  = E_VDPLAYER_FLG_NONE;
    }
    /* Initializing global variable _gu16PreviewX */
    {
         _gu16PreviewX  = 0u;
    }
    /* Initializing global variable _gu16PreviewY */
    {
         _gu16PreviewY  = 0u;
    }
    /* Initializing global variable _gu16PreviewWidth */
    {
         _gu16PreviewWidth  = 0u;
    }
    /* Initializing global variable _gu16PreviewHeight */
    {
         _gu16PreviewHeight  = 0u;
    }
    /* Initializing global variable u32VdplayerShareMemAddr */
    {
         u32VdplayerShareMemAddr  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MAPP_VDPlayer_SetPIPDisplayWindow(_eWindow, _pstDispWin);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MAPP_VDPlayer_SetPIPDisplayWindow_pstDispWin_NULL_m_eVDPlayerFlgs_not_E_VDPLAYER_FLG_PREVIEW */

/* CPPTEST_TEST_CASE_BEGIN test_MAPP_VDPlayer_SetPIPDisplayWindow_MApi_XC_IsCurrentFrameBufferLessMode_return_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MAPP_VDPlayer_SetPIPDisplayWindow(SCALER_WIN, MS_WINDOW_TYPE *) */
void TestSuite_mapp_videoplayer_test_MAPP_VDPlayer_SetPIPDisplayWindow_MApi_XC_IsCurrentFrameBufferLessMode_return_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    /* Initializing argument 2 (pstDispWin) */
    MS_WINDOW_TYPE * _pstDispWin  = 0 ;
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
    /* Initializing global variable m_eVDPlayerFlgs */
    {
         m_eVDPlayerFlgs  = E_VDPLAYER_FLG_NONE;
    }
    /* Initializing global variable _gu16PreviewX */
    {
         _gu16PreviewX  = 0u;
    }
    /* Initializing global variable _gu16PreviewY */
    {
         _gu16PreviewY  = 0u;
    }
    /* Initializing global variable _gu16PreviewWidth */
    {
         _gu16PreviewWidth  = 0u;
    }
    /* Initializing global variable _gu16PreviewHeight */
    {
         _gu16PreviewHeight  = 0u;
    }
    /* Initializing global variable u32VdplayerShareMemAddr */
    {
         u32VdplayerShareMemAddr  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MAPP_VDPlayer_SetPIPDisplayWindow(_eWindow, _pstDispWin);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MAPP_VDPlayer_SetPIPDisplayWindow_MApi_XC_IsCurrentFrameBufferLessMode_return_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MAPP_VDPlayer_SetPIPDisplayWindow_m_eVDPlayerFlgs_E_VDPLAYER_FLG_PREVIEW */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MAPP_VDPlayer_SetPIPDisplayWindow(SCALER_WIN, MS_WINDOW_TYPE *) */
void TestSuite_mapp_videoplayer_test_MAPP_VDPlayer_SetPIPDisplayWindow_m_eVDPlayerFlgs_E_VDPLAYER_FLG_PREVIEW()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    /* Initializing argument 2 (pstDispWin) */
    MS_WINDOW_TYPE * _pstDispWin  = 0 ;
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
    /* Initializing global variable m_eVDPlayerFlgs */
    {
         m_eVDPlayerFlgs  = E_VDPLAYER_FLG_PREVIEW;
    }
    /* Initializing global variable _gu16PreviewX */
    {
         _gu16PreviewX  = 0u;
    }
    /* Initializing global variable _gu16PreviewY */
    {
         _gu16PreviewY  = 0u;
    }
    /* Initializing global variable _gu16PreviewWidth */
    {
         _gu16PreviewWidth  = 0u;
    }
    /* Initializing global variable _gu16PreviewHeight */
    {
         _gu16PreviewHeight  = 0u;
    }
    /* Initializing global variable u32VdplayerShareMemAddr */
    {
         u32VdplayerShareMemAddr  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MAPP_VDPlayer_SetPIPDisplayWindow(_eWindow, _pstDispWin);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MAPP_VDPlayer_SetPIPDisplayWindow_m_eVDPlayerFlgs_E_VDPLAYER_FLG_PREVIEW */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_VDPlayer_AdjustRatioByPAR_case1 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_VDPlayer_AdjustRatioByPAR(U32, U32, U32, U32, U32 *, U32 *) */
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_AdjustRatioByPAR_case1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hsize) */
    U32 _u32Hsize  = 20;
    /* Initializing argument 2 (u32Vsize) */
    U32 _u32Vsize  = 20;
    /* Initializing argument 3 (u32DAR_H) */
    U32 _u32DAR_H  = 2ul;
    /* Initializing argument 4 (u32DAR_V) */
    U32 _u32DAR_V  = 1;
    /* Initializing argument 5 (u32TargetH) */
    U32 _u32TargetH_0  = 0ul;
    U32 * _u32TargetH  = & _u32TargetH_0;
    /* Initializing argument 6 (u32TargetV) */
    U32 _u32TargetV_1  = 0ul;
    U32 * _u32TargetV  = & _u32TargetV_1;

    MS_WINDOW_TYPE stDisplayWin = {0, 0, PANEL_WIDTH, PANEL_HEIGHT};

    {
        /* Tested function call */
        MApp_VDPlayer_AdjustRatioByPAR(_u32Hsize, _u32Vsize, _u32DAR_H, _u32DAR_V, _u32TargetH, _u32TargetV,stDisplayWin );
        printf("%d %d", _u32TargetH_0, _u32TargetV_1);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1920, ( _u32TargetH_0 ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(960, ( _u32TargetV_1 ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VDPlayer_AdjustRatioByPAR_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VDPlayer_BeginPreview_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_VDPlayer_BeginPreview(void) */
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_BeginPreview_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_bVDPlayerPreview */
    {
         m_bVDPlayerPreview  = 0;
    }
    /* Initializing global variable m_eVDPlayerFlgs */
    {
         m_eVDPlayerFlgs  = E_VDPLAYER_FLG_NONE;
    }
    {
        /* Tested function call */
        MApp_VDPlayer_BeginPreview();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( m_bVDPlayerPreview ) );
        CPPTEST_ASSERT_EQUAL( E_VDPLAYER_FLG_PREVIEW, ( m_eVDPlayerFlgs ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VDPlayer_BeginPreview_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VDPlayer_Stop__gbEnableInternalSubtitle_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_VDPlayer_Stop(void) */
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Stop__gbEnableInternalSubtitle_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing global variable _gbCoprocessorEnable */
    {
         _gbCoprocessorEnable  = 1;
    }
    /* Initializing global variable _geBMStreamMode */
    {
         _geBMStreamMode  = E_BM_STREAM_MODE_NORMAL;
    }
    /* Initializing global variable m_bVDPlayerThumbnail */
    {
         m_bVDPlayerThumbnail  = 0;
    }
    /* Initializing global variable m_u8LastMemoryCheck */
    {
         m_u8LastMemoryCheck  = 1;
    }
    /* Initializing global variable m_s32PreSubtitleTagIdx */
    {
         m_s32PreSubtitleTagIdx  = 0L;
    }
    /* Initializing global variable m_u32PreMovieRefreshTextTimer */
    {
         m_u32PreMovieRefreshTextTimer  = 0ul;
    }
    /* Initializing global variable bDrmAuthorization */
    {
         bDrmAuthorization  = 0;
    }
    /* Initializing global variable bDrmFileFormat */
    {
         bDrmFileFormat  = 0;
    }
    /* Initializing global variable bDrmActivationFile */
    {
         bDrmActivationFile  = 0;
    }
    /* Initializing global variable bDrmRentalStatus */
    {
         bDrmRentalStatus  = 0;
    }
    /* Initializing global variable g_bDrmRental */
    {
         g_bDrmRental  = 0;
    }
    /* Initializing global variable g_u8DrmUseLimit */
    {
         g_u8DrmUseLimit  = 0;
    }
    /* Initializing global variable g_u8DrmUseCount */
    {
         g_u8DrmUseCount  = 0;
    }
    /* Initializing global variable u8VDPlayerSetTrickModeResult */
    {
         u8VDPlayerSetTrickModeResult  = 0;
    }
    /* Initializing global variable u8VDPlayerStepPlayResult */
    {
         u8VDPlayerStepPlayResult  = 0;
    }
    /* Initializing global variable _u32SeamlessTimer */
    {
         _u32SeamlessTimer  = 0ul;
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
    /* Initializing global variable u32subtitletype */
    {
         u32subtitletype  = E_VDP_CODEC_ID_SUBTITLE_IMAGE_BMP_TS;
    }
    /* Initializing global variable u16CPageID */
    {
         u16CPageID  = 0u;
    }
    /* Initializing global variable m_bSuspendInternalSubtitle2Queue */
    {
         m_bSuspendInternalSubtitle2Queue  = 0;
    }
    /* Initializing global variable _bSubtitleShow_MW */
    {
         _bSubtitleShow_MW  = 0;
    }
    /* Initializing global variable _bSubtitleShow_User */
    {
         _bSubtitleShow_User  = 0;
    }
    /* Initializing global variable u8InternalST_Num */
    {
         u8InternalST_Num  = 0;
    }
    /* Initializing global variable u16SubtitleTagCnt */
    {
         u16SubtitleTagCnt  = 0u;
    }
    /* Initializing global variable u8IsSubtitleBusy */
    {
         u8IsSubtitleBusy  = 0;
    }
    /* Initializing global variable u8IssubtitleInit */
    {
         u8IssubtitleInit  = 0;
    }
    /* Initializing global variable u8IsSubtitleInitfinish */
    {
         u8IsSubtitleInitfinish  = 0;
    }
    /* Initializing global variable u16tagposition */
    {
         u16tagposition  = 0u;
    }
    /* Initializing global variable u32GetSubtitleStateBuf */
    {
         u32GetSubtitleStateBuf  = 0ul;
    }
    /* Initializing global variable g_bReplay */
    {
         g_bReplay  = 0;
    }
    /* Initializing global variable g_bUnsupportAudio */
    {
         g_bUnsupportAudio  = 0;
    }
    /* Initializing global variable u32VDPlayerLoopWdtTimer */
    {
         u32VDPlayerLoopWdtTimer  = 0ul;
    }
    /* Initializing global variable g_stDemuxer */
    {
         g_stDemuxer.u32Video_IdxSize  = 0ul;
         g_stDemuxer.u32KeyIdxPeriod  = 0ul;
         g_stDemuxer.u32AudioKeyIdxPeriod  = 0ul;
         g_stDemuxer.u32lastVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u32FirstVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u8KeyIdxSize  = 0;
         g_stDemuxer.u8AudioKeyIdxSize  = 0;
         g_stDemuxer.u8ThumbNailMode  = 0;
         g_stDemuxer.bEnableCalcByBitRate  = 0;
         g_stDemuxer.bEnableAudioHandler  = 0;
    }
    /* Initializing global variable g_bIsTSRadioOnly */
    {
         g_bIsTSRadioOnly  = 0;
    }
    /* Initializing global variable g_enVDPlayerVideoType */
    {
         g_enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable g_bForceToFB */
    {
         g_bForceToFB  = 0;
    }
    /* Initializing global variable m_eVDPlayerFlgs */
    {
         m_eVDPlayerFlgs  = E_VDPLAYER_FLG_NONE;
    }
    /* Initializing global variable _gu16PreviewX */
    {
         _gu16PreviewX  = 0u;
    }
    /* Initializing global variable _gu16PreviewY */
    {
         _gu16PreviewY  = 0u;
    }
    /* Initializing global variable _gu16PreviewWidth */
    {
         _gu16PreviewWidth  = 0u;
    }
    /* Initializing global variable _gu16PreviewHeight */
    {
         _gu16PreviewHeight  = 0u;
    }
    /* Initializing global variable m_bFLG_PREVIEW */
    {
         m_bFLG_PREVIEW  = 0;
    }
    /* Initializing global variable g_DstWin */
    {
         g_DstWin.x  = 0u;
         g_DstWin.y  = 0u;
         g_DstWin.width  = 0u;
         g_DstWin.height  = 0u;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable m_eVDPlayerAckFlags */
    {
         m_eVDPlayerAckFlags  = E_ACKFLG_WAIT_STOP;
    }
    /* Initializing global variable bDrmRegCode */
    {
         bDrmRegCode  = 0;
    }
    /* Initializing global variable _gbContinueBlockRead */
    {
         _gbContinueBlockRead  = 0;
    }
    /* Initializing global variable enVDPlayerRet */
    {
         enVDPlayerRet  = EXIT_NULL;
    }
    /* Initializing global variable g_bNonBlockingRead */
    {
         g_bNonBlockingRead  = 0;
    }
    /* Initializing global variable _bStreamSeeked */
    {
         _bStreamSeeked  = 0;
    }
    /* Initializing global variable _gu32BlockReadTimer */
    {
         _gu32BlockReadTimer  = 0ul;
    }
    /* Initializing global variable _gbEnableInternalSubtitle */
    {
         _gbEnableInternalSubtitle  = 0;
    }
    /* Initializing global variable _gu32ResidualReadSize */
    {
         _gu32ResidualReadSize  = 0ul;
    }
    /* Initializing global variable _gu32gStreamHdl */
    {
         _gu32gStreamHdl  = 0ul;
    }
    /* Initializing global variable _gu32BuffAddr */
    {
         _gu32BuffAddr  = 0ul;
    }
    /* Initializing global variable g_bNonBlockingSeek */
    {
         g_bNonBlockingSeek  = 0;
    }
    /* Initializing global variable g_b2ndRunPreviewMute */
    {
         g_b2ndRunPreviewMute  = 0;
    }
    /* Initializing global variable u16APageID */
    {
         u16APageID  = 0u;
    }
    /* Initializing global variable u16CodecNum */
    {
         u16CodecNum  = 0u;
    }
    /* Initializing global variable u16Samples_channel */
    {
         u16Samples_channel  = 0u;
    }
    /* Initializing global variable u8VDPlayerInitResult */
    {
         u8VDPlayerInitResult  = 0;
    }
    /* Initializing global variable u8VDPlayerSetAudioTrackResult */
    {
         u8VDPlayerSetAudioTrackResult  = 0;
    }
    /* Initializing global variable u8VDPlayerTsSetProgramResult */
    {
         u8VDPlayerTsSetProgramResult  = 0;
    }
    /* Initializing global variable _bEnableSeamlessPlaying */
    {
         _bEnableSeamlessPlaying  = 0;
    }
    /* Initializing global variable u32VdplayerShareMemAddr */
    {
         u32VdplayerShareMemAddr  = 0ul;
    }
    /* Initializing global variable enVDPlayerVideoType */
    {
         enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    u32StreamHandleIdx[0] = 0;
    {
        /* Tested function call */
        MApp_VDPlayer_Stop();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _gbEnableInternalSubtitle ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VDPlayer_Stop__gbEnableInternalSubtitle_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VDPlayer_Play_return_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_VDPlayer_Play(void) */

static EN_VDPLAYER_FORCE_STOP_RESULT myFunc(EN_VDPLAYER_FORCE_STOP eType)
{
	return E_VDPLAYER_USER_EXIT;
}
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Play_return_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing global variable _gbCoprocessorEnable */
    {
         _gbCoprocessorEnable  = 0;
    }
    /* Initializing global variable bMovieAbort */
    {
         bMovieAbort  = 0;
    }
    /* Initializing global variable _geBMStreamMode */
    {
         _geBMStreamMode  = E_BM_STREAM_MODE_NORMAL;
    }
    /* Initializing global variable m_bVDPlayerThumbnail */
    {
         m_bVDPlayerThumbnail  = 0;
    }
    /* Initializing global variable m_u8LastMemoryCheck */
    {
         m_u8LastMemoryCheck  = 0;
    }
    /* Initializing global variable u8VDPlayerPlayTimeOut */
    {
         u8VDPlayerPlayTimeOut  = 0ul;
    }
    /* Initializing global variable m_s32PreSubtitleTagIdx */
    {
         m_s32PreSubtitleTagIdx  = 0L;
    }
    /* Initializing global variable m_u32PreMovieRefreshTextTimer */
    {
         m_u32PreMovieRefreshTextTimer  = 0ul;
    }
    /* Initializing global variable bDrmAuthorization */
    {
         bDrmAuthorization  = 0;
    }
    /* Initializing global variable bDrmFileFormat */
    {
         bDrmFileFormat  = 1;
    }
    /* Initializing global variable bDrmActivationFile */
    {
         bDrmActivationFile  = 0;
    }
    /* Initializing global variable bDrmRentalStatus */
    {
         bDrmRentalStatus  = 0;
    }
    /* Initializing global variable g_bDrmRental */
    {
         g_bDrmRental  = 0;
    }
    /* Initializing global variable g_u8DrmUseLimit */
    {
         g_u8DrmUseLimit  = 0;
    }
    /* Initializing global variable g_u8DrmUseCount */
    {
         g_u8DrmUseCount  = 0;
    }
    /* Initializing global variable u8VDPlayerSetTrickModeResult */
    {
         u8VDPlayerSetTrickModeResult  = 0;
    }
    /* Initializing global variable u8VDPlayerStepPlayResult */
    {
         u8VDPlayerStepPlayResult  = 0;
    }
    /* Initializing global variable _u32SeamlessTimer */
    {
         _u32SeamlessTimer  = 0ul;
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
    /* Initializing global variable u32subtitletype */
    {
         u32subtitletype  = 0ul;
    }
    /* Initializing global variable u16CPageID */
    {
         u16CPageID  = 0u;
    }
    /* Initializing global variable m_bSuspendInternalSubtitle2Queue */
    {
         m_bSuspendInternalSubtitle2Queue  = 0;
    }
    /* Initializing global variable _bSubtitleShow_MW */
    {
         _bSubtitleShow_MW  = 0;
    }
    /* Initializing global variable _bSubtitleShow_User */
    {
         _bSubtitleShow_User  = 0;
    }
    /* Initializing global variable u8InternalST_Num */
    {
         u8InternalST_Num  = 0;
    }
    /* Initializing global variable u16SubtitleTagCnt */
    {
         u16SubtitleTagCnt  = 0u;
    }
    /* Initializing global variable u8IsSubtitleBusy */
    {
         u8IsSubtitleBusy  = 0;
    }
    /* Initializing global variable u8IssubtitleInit */
    {
         u8IssubtitleInit  = 0;
    }
    /* Initializing global variable u8IsSubtitleInitfinish */
    {
         u8IsSubtitleInitfinish  = 0;
    }
    /* Initializing global variable u16tagposition */
    {
         u16tagposition  = 0u;
    }
    /* Initializing global variable u32GetSubtitleStateBuf */
    {
         u32GetSubtitleStateBuf  = 0ul;
    }
    /* Initializing global variable g_bReplay */
    {
         g_bReplay  = 0;
    }
    /* Initializing global variable g_bUnsupportAudio */
    {
         g_bUnsupportAudio  = 0;
    }
    /* Initializing global variable u32VDPlayerLoopWdtTimer */
    {
         u32VDPlayerLoopWdtTimer  = 0ul;
    }
    /* Initializing global variable g_stDemuxer */
    {
         g_stDemuxer.u32Video_IdxSize  = 0ul;
         g_stDemuxer.u32KeyIdxPeriod  = 0ul;
         g_stDemuxer.u32AudioKeyIdxPeriod  = 0ul;
         g_stDemuxer.u32lastVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u32FirstVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u8KeyIdxSize  = 0;
         g_stDemuxer.u8AudioKeyIdxSize  = 0;
         g_stDemuxer.u8ThumbNailMode  = 0;
         g_stDemuxer.bEnableCalcByBitRate  = 0;
         g_stDemuxer.bEnableAudioHandler  = 0;
    }
    /* Initializing global variable g_bIsTSRadioOnly */
    {
         g_bIsTSRadioOnly  = 0;
    }
    /* Initializing global variable g_enVDPlayerVideoType */
    {
         g_enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable g_bForceToFB */
    {
         g_bForceToFB  = 0;
    }
    /* Initializing global variable m_eVDPlayerFlgs */
    {
         m_eVDPlayerFlgs  = E_VDPLAYER_FLG_NONE;
    }
    /* Initializing global variable _gu16PreviewX */
    {
         _gu16PreviewX  = 0u;
    }
    /* Initializing global variable _gu16PreviewY */
    {
         _gu16PreviewY  = 0u;
    }
    /* Initializing global variable _gu16PreviewWidth */
    {
         _gu16PreviewWidth  = 0u;
    }
    /* Initializing global variable _gu16PreviewHeight */
    {
         _gu16PreviewHeight  = 0u;
    }
    /* Initializing global variable m_bFLG_PREVIEW */
    {
         m_bFLG_PREVIEW  = 0;
    }
    /* Initializing global variable g_DstWin */
    {
         g_DstWin.x  = 0u;
         g_DstWin.y  = 0u;
         g_DstWin.width  = 0u;
         g_DstWin.height  = 0u;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable m_eVDPlayerAckFlags */
    {
         m_eVDPlayerAckFlags  = 0;
    }
    /* Initializing global variable bDrmRegCode */
    {
         bDrmRegCode  = 0;
    }
    /* Initializing global variable _gbContinueBlockRead */
    {
         _gbContinueBlockRead  = 0;
    }
    /* Initializing global variable enVDPlayerRet */
    {
         enVDPlayerRet  = EXIT_NULL;
    }
    /* Initializing global variable g_bNonBlockingRead */
    {
         g_bNonBlockingRead  = 0;
    }
    /* Initializing global variable _bStreamSeeked */
    {
         _bStreamSeeked  = 0;
    }
    /* Initializing global variable _gu32BlockReadTimer */
    {
         _gu32BlockReadTimer  = 0ul;
    }
    /* Initializing global variable _gbEnableInternalSubtitle */
    {
         _gbEnableInternalSubtitle  = 0;
    }
    /* Initializing global variable _gu32ResidualReadSize */
    {
         _gu32ResidualReadSize  = 0ul;
    }
    /* Initializing global variable _gu32gStreamHdl */
    {
         _gu32gStreamHdl  = 0ul;
    }
    /* Initializing global variable _gu32BuffAddr */
    {
         _gu32BuffAddr  = 0ul;
    }
    /* Initializing global variable g_bNonBlockingSeek */
    {
         g_bNonBlockingSeek  = 0;
    }
    /* Initializing global variable g_b2ndRunPreviewMute */
    {
         g_b2ndRunPreviewMute  = 0;
    }
    /* Initializing global variable u16APageID */
    {
         u16APageID  = 0u;
    }
    /* Initializing global variable u16CodecNum */
    {
         u16CodecNum  = 0u;
    }
    /* Initializing global variable u16Samples_channel */
    {
         u16Samples_channel  = 0u;
    }
    /* Initializing global variable u8VDPlayerInitResult */
    {
         u8VDPlayerInitResult  = 0;
    }
    /* Initializing global variable u8VDPlayerSetAudioTrackResult */
    {
         u8VDPlayerSetAudioTrackResult  = 0;
    }
    /* Initializing global variable u8VDPlayerTsSetProgramResult */
    {
         u8VDPlayerTsSetProgramResult  = 0;
    }
    /* Initializing global variable _gpfnForceStopCallBack */
    {
         _gpfnForceStopCallBack  = 0 ;
    }
    /* Initializing global variable _bEnableSeamlessPlaying */
    {
         _bEnableSeamlessPlaying  = 0;
    }
    /* Initializing global variable u32VdplayerShareMemAddr */
    {
         u32VdplayerShareMemAddr  = 0ul;
    }
    /* Initializing global variable enVDPlayerVideoType */
    {
         enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }

    {
    	_gpfnForceStopCallBack = (pfnForceStopCallBack)(myFunc);

    	/* Tested function call */
        BOOLEAN _return  = MApp_VDPlayer_Play();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VDPlayer_Play_return_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VDPlayer_CheckAndGenDRMData_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_VDPlayer_CheckAndGenDRMData(void) */
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_CheckAndGenDRMData_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_s32PreSubtitleTagIdx */
    {
         m_s32PreSubtitleTagIdx  = 0L;
    }
    /* Initializing global variable m_u32PreMovieRefreshTextTimer */
    {
         m_u32PreMovieRefreshTextTimer  = 0ul;
    }
    /* Initializing global variable bDrmAuthorization */
    {
         bDrmAuthorization  = 0;
    }
    /* Initializing global variable bDrmFileFormat */
    {
         bDrmFileFormat  = 0;
    }
    /* Initializing global variable bDrmActivationFile */
    {
         bDrmActivationFile  = 0;
    }
    /* Initializing global variable bDrmRentalStatus */
    {
         bDrmRentalStatus  = 0;
    }
    /* Initializing global variable g_bDrmRental */
    {
         g_bDrmRental  = 0;
    }
    /* Initializing global variable g_u8DrmUseLimit */
    {
         g_u8DrmUseLimit  = 0;
    }
    /* Initializing global variable g_u8DrmUseCount */
    {
         g_u8DrmUseCount  = 0;
    }
    /* Initializing global variable u8VDPlayerSetTrickModeResult */
    {
         u8VDPlayerSetTrickModeResult  = 0;
    }
    /* Initializing global variable u8VDPlayerStepPlayResult */
    {
         u8VDPlayerStepPlayResult  = 0;
    }
    /* Initializing global variable _u32SeamlessTimer */
    {
         _u32SeamlessTimer  = 0ul;
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
    /* Initializing global variable u32subtitletype */
    {
         u32subtitletype  = 0ul;
    }
    /* Initializing global variable u16CPageID */
    {
         u16CPageID  = 0u;
    }
    /* Initializing global variable m_bSuspendInternalSubtitle2Queue */
    {
         m_bSuspendInternalSubtitle2Queue  = 0;
    }
    /* Initializing global variable _bSubtitleShow_MW */
    {
         _bSubtitleShow_MW  = 0;
    }
    /* Initializing global variable _bSubtitleShow_User */
    {
         _bSubtitleShow_User  = 0;
    }
    /* Initializing global variable u8InternalST_Num */
    {
         u8InternalST_Num  = 0;
    }
    /* Initializing global variable u16SubtitleTagCnt */
    {
         u16SubtitleTagCnt  = 0u;
    }
    /* Initializing global variable u8IsSubtitleBusy */
    {
         u8IsSubtitleBusy  = 0;
    }
    /* Initializing global variable u8IssubtitleInit */
    {
         u8IssubtitleInit  = 0;
    }
    /* Initializing global variable u8IsSubtitleInitfinish */
    {
         u8IsSubtitleInitfinish  = 0;
    }
    /* Initializing global variable u16tagposition */
    {
         u16tagposition  = 0u;
    }
    /* Initializing global variable u32GetSubtitleStateBuf */
    {
         u32GetSubtitleStateBuf  = 0ul;
    }
    /* Initializing global variable g_bReplay */
    {
         g_bReplay  = 0;
    }
    /* Initializing global variable g_bUnsupportAudio */
    {
         g_bUnsupportAudio  = 0;
    }
    /* Initializing global variable u32VDPlayerLoopWdtTimer */
    {
         u32VDPlayerLoopWdtTimer  = 0ul;
    }
    /* Initializing global variable g_stDemuxer */
    {
         g_stDemuxer.u32Video_IdxSize  = 0ul;
         g_stDemuxer.u32KeyIdxPeriod  = 0ul;
         g_stDemuxer.u32AudioKeyIdxPeriod  = 0ul;
         g_stDemuxer.u32lastVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u32FirstVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u8KeyIdxSize  = 0;
         g_stDemuxer.u8AudioKeyIdxSize  = 0;
         g_stDemuxer.u8ThumbNailMode  = 0;
         g_stDemuxer.bEnableCalcByBitRate  = 0;
         g_stDemuxer.bEnableAudioHandler  = 0;
    }
    /* Initializing global variable g_bIsTSRadioOnly */
    {
         g_bIsTSRadioOnly  = 0;
    }
    /* Initializing global variable g_enVDPlayerVideoType */
    {
         g_enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable g_bForceToFB */
    {
         g_bForceToFB  = 0;
    }
    /* Initializing global variable m_eVDPlayerFlgs */
    {
         m_eVDPlayerFlgs  = E_VDPLAYER_FLG_NONE;
    }
    /* Initializing global variable _gu16PreviewX */
    {
         _gu16PreviewX  = 0u;
    }
    /* Initializing global variable _gu16PreviewY */
    {
         _gu16PreviewY  = 0u;
    }
    /* Initializing global variable _gu16PreviewWidth */
    {
         _gu16PreviewWidth  = 0u;
    }
    /* Initializing global variable _gu16PreviewHeight */
    {
         _gu16PreviewHeight  = 0u;
    }
    /* Initializing global variable m_bFLG_PREVIEW */
    {
         m_bFLG_PREVIEW  = 0;
    }
    /* Initializing global variable g_DstWin */
    {
         g_DstWin.x  = 0u;
         g_DstWin.y  = 0u;
         g_DstWin.width  = 0u;
         g_DstWin.height  = 0u;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable m_eVDPlayerAckFlags */
    {
         m_eVDPlayerAckFlags  = E_ACKFLG_NULL;
    }
    /* Initializing global variable bDrmRegCode */
    {
         bDrmRegCode  = 0;
    }
    /* Initializing global variable g_bIsResumePlay */
    {
         g_bIsResumePlay  = 0;
    }
    /* Initializing global variable _gbContinueBlockRead */
    {
         _gbContinueBlockRead  = 0;
    }
    /* Initializing global variable enVDPlayerRet */
    {
         enVDPlayerRet  = EXIT_NULL;
    }
    /* Initializing global variable g_bNonBlockingRead */
    {
         g_bNonBlockingRead  = 0;
    }
    /* Initializing global variable _bStreamSeeked */
    {
         _bStreamSeeked  = 0;
    }
    /* Initializing global variable _gu32BlockReadTimer */
    {
         _gu32BlockReadTimer  = 0ul;
    }
    /* Initializing global variable _gbEnableInternalSubtitle */
    {
         _gbEnableInternalSubtitle  = 0;
    }
    /* Initializing global variable _gu32ResidualReadSize */
    {
         _gu32ResidualReadSize  = 0ul;
    }
    /* Initializing global variable _gu32gStreamHdl */
    {
         _gu32gStreamHdl  = 0ul;
    }
    /* Initializing global variable _gu32BuffAddr */
    {
         _gu32BuffAddr  = 0ul;
    }
    /* Initializing global variable g_bNonBlockingSeek */
    {
         g_bNonBlockingSeek  = 0;
    }
    /* Initializing global variable g_b2ndRunPreviewMute */
    {
         g_b2ndRunPreviewMute  = 0;
    }
    /* Initializing global variable u16APageID */
    {
         u16APageID  = 0u;
    }
    /* Initializing global variable u16CodecNum */
    {
         u16CodecNum  = 0u;
    }
    /* Initializing global variable u16Samples_channel */
    {
         u16Samples_channel  = 0u;
    }
    /* Initializing global variable u8VDPlayerInitResult */
    {
         u8VDPlayerInitResult  = 0;
    }
    /* Initializing global variable u8VDPlayerSetAudioTrackResult */
    {
         u8VDPlayerSetAudioTrackResult  = 0;
    }
    /* Initializing global variable u8VDPlayerTsSetProgramResult */
    {
         u8VDPlayerTsSetProgramResult  = 0;
    }
    /* Initializing global variable _bEnableSeamlessPlaying */
    {
         _bEnableSeamlessPlaying  = 0;
    }
    /* Initializing global variable u32VdplayerShareMemAddr */
    {
         u32VdplayerShareMemAddr  = 0ul;
    }
    /* Initializing global variable next */
    {
         next  = 0ul;
    }
    /* Initializing global variable enVDPlayerVideoType */
    {
         enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_VDPlayer_CheckAndGenDRMData();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VDPlayer_CheckAndGenDRMData_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VDPlayer_GetDRMRegistrationCode_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_VDPlayer_GetDRMRegistrationCode(U32) */


void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_ClearVDPlayerAckFlags(void)
{
	enumVDPlayerAckFlags _return = E_ACKFLG_NULL;
	m_eVDPlayerAckFlags = E_ACKFLG_NULL;

	_return  = m_eVDPlayerAckFlags;
	/* Post-condition check */
    CPPTEST_ASSERT_UINTEGER_EQUAL(E_ACKFLG_NULL, ( _return ) );
}


void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetbDrmRentalStatus(void)
{
	BOOLEAN _return ;
	bDrmRentalStatus = 1;

	_return  = m_eVDPlayerAckFlags;
		/* Post-condition check */
    CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
}

void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_GetDRMRegistrationCode_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (drmCodeAddr) */
    U32 _drmCodeAddr  = 0ul;
    /* Initializing global variable m_s32PreSubtitleTagIdx */
    {
         m_s32PreSubtitleTagIdx  = 0L;
    }
    /* Initializing global variable m_u32PreMovieRefreshTextTimer */
    {
         m_u32PreMovieRefreshTextTimer  = 0ul;
    }
    /* Initializing global variable bDrmAuthorization */
    {
         bDrmAuthorization  = 0;
    }
    /* Initializing global variable bDrmFileFormat */
    {
         bDrmFileFormat  = 0;
    }
    /* Initializing global variable bDrmActivationFile */
    {
         bDrmActivationFile  = 0;
    }
    /* Initializing global variable bDrmRentalStatus */
    {
         bDrmRentalStatus  = 0;
    }
    /* Initializing global variable g_bDrmRental */
    {
         g_bDrmRental  = 0;
    }
    /* Initializing global variable g_u8DrmUseLimit */
    {
         g_u8DrmUseLimit  = 0;
    }
    /* Initializing global variable g_u8DrmUseCount */
    {
         g_u8DrmUseCount  = 0;
    }
    /* Initializing global variable u8VDPlayerSetTrickModeResult */
    {
         u8VDPlayerSetTrickModeResult  = 0;
    }
    /* Initializing global variable u8VDPlayerStepPlayResult */
    {
         u8VDPlayerStepPlayResult  = 0;
    }
    /* Initializing global variable _u32SeamlessTimer */
    {
         _u32SeamlessTimer  = 0ul;
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
    /* Initializing global variable u32subtitletype */
    {
         u32subtitletype  = 0ul;
    }
    /* Initializing global variable u16CPageID */
    {
         u16CPageID  = 0u;
    }
    /* Initializing global variable m_bSuspendInternalSubtitle2Queue */
    {
         m_bSuspendInternalSubtitle2Queue  = 0;
    }
    /* Initializing global variable _bSubtitleShow_MW */
    {
         _bSubtitleShow_MW  = 0;
    }
    /* Initializing global variable _bSubtitleShow_User */
    {
         _bSubtitleShow_User  = 0;
    }
    /* Initializing global variable u8InternalST_Num */
    {
         u8InternalST_Num  = 0;
    }
    /* Initializing global variable u16SubtitleTagCnt */
    {
         u16SubtitleTagCnt  = 0u;
    }
    /* Initializing global variable u8IsSubtitleBusy */
    {
         u8IsSubtitleBusy  = 0;
    }
    /* Initializing global variable u8IssubtitleInit */
    {
         u8IssubtitleInit  = 0;
    }
    /* Initializing global variable u8IsSubtitleInitfinish */
    {
         u8IsSubtitleInitfinish  = 0;
    }
    /* Initializing global variable u16tagposition */
    {
         u16tagposition  = 0u;
    }
    /* Initializing global variable u32GetSubtitleStateBuf */
    {
         u32GetSubtitleStateBuf  = 0ul;
    }
    /* Initializing global variable g_bReplay */
    {
         g_bReplay  = 0;
    }
    /* Initializing global variable g_bUnsupportAudio */
    {
         g_bUnsupportAudio  = 0;
    }
    /* Initializing global variable u32VDPlayerLoopWdtTimer */
    {
         u32VDPlayerLoopWdtTimer  = 0ul;
    }
    /* Initializing global variable g_stDemuxer */
    {
         g_stDemuxer.u32Video_IdxSize  = 0ul;
         g_stDemuxer.u32KeyIdxPeriod  = 0ul;
         g_stDemuxer.u32AudioKeyIdxPeriod  = 0ul;
         g_stDemuxer.u32lastVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u32FirstVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u8KeyIdxSize  = 0;
         g_stDemuxer.u8AudioKeyIdxSize  = 0;
         g_stDemuxer.u8ThumbNailMode  = 0;
         g_stDemuxer.bEnableCalcByBitRate  = 0;
         g_stDemuxer.bEnableAudioHandler  = 0;
    }
    /* Initializing global variable g_bIsTSRadioOnly */
    {
         g_bIsTSRadioOnly  = 0;
    }
    /* Initializing global variable g_enVDPlayerVideoType */
    {
         g_enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable g_bForceToFB */
    {
         g_bForceToFB  = 0;
    }
    /* Initializing global variable m_eVDPlayerFlgs */
    {
         m_eVDPlayerFlgs  = E_VDPLAYER_FLG_NONE;
    }
    /* Initializing global variable _gu16PreviewX */
    {
         _gu16PreviewX  = 0u;
    }
    /* Initializing global variable _gu16PreviewY */
    {
         _gu16PreviewY  = 0u;
    }
    /* Initializing global variable _gu16PreviewWidth */
    {
         _gu16PreviewWidth  = 0u;
    }
    /* Initializing global variable _gu16PreviewHeight */
    {
         _gu16PreviewHeight  = 0u;
    }
    /* Initializing global variable m_bFLG_PREVIEW */
    {
         m_bFLG_PREVIEW  = 0;
    }
    /* Initializing global variable g_DstWin */
    {
         g_DstWin.x  = 0u;
         g_DstWin.y  = 0u;
         g_DstWin.width  = 0u;
         g_DstWin.height  = 0u;
    }
    /* Initializing global variable g_bIsResumePlay */
    {
         g_bIsResumePlay  = 0;
    }
    /* Initializing global variable _gbContinueBlockRead */
    {
         _gbContinueBlockRead  = 0;
    }
    /* Initializing global variable enVDPlayerRet */
    {
         enVDPlayerRet  = EXIT_NULL;
    }
    /* Initializing global variable g_bNonBlockingRead */
    {
         g_bNonBlockingRead  = 0;
    }
    /* Initializing global variable _bStreamSeeked */
    {
         _bStreamSeeked  = 0;
    }
    /* Initializing global variable _gu32BlockReadTimer */
    {
         _gu32BlockReadTimer  = 0ul;
    }
    /* Initializing global variable _gbEnableInternalSubtitle */
    {
         _gbEnableInternalSubtitle  = 0;
    }
    /* Initializing global variable _gu32ResidualReadSize */
    {
         _gu32ResidualReadSize  = 0ul;
    }
    /* Initializing global variable _gu32gStreamHdl */
    {
         _gu32gStreamHdl  = 0ul;
    }
    /* Initializing global variable _gu32BuffAddr */
    {
         _gu32BuffAddr  = 0ul;
    }
    /* Initializing global variable g_bNonBlockingSeek */
    {
         g_bNonBlockingSeek  = 0;
    }
    /* Initializing global variable g_b2ndRunPreviewMute */
    {
         g_b2ndRunPreviewMute  = 0;
    }
    /* Initializing global variable u16APageID */
    {
         u16APageID  = 0u;
    }
    /* Initializing global variable u16CodecNum */
    {
         u16CodecNum  = 0u;
    }
    /* Initializing global variable u16Samples_channel */
    {
         u16Samples_channel  = 0u;
    }
    /* Initializing global variable u8VDPlayerInitResult */
    {
         u8VDPlayerInitResult  = 0;
    }
    /* Initializing global variable u8VDPlayerSetAudioTrackResult */
    {
         u8VDPlayerSetAudioTrackResult  = 0;
    }
    /* Initializing global variable u8VDPlayerTsSetProgramResult */
    {
         u8VDPlayerTsSetProgramResult  = 0;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable m_eVDPlayerAckFlags */
    {
         m_eVDPlayerAckFlags  = E_ACKFLG_NULL;
    }
    /* Initializing global variable bDrmRegCode */
    {
         bDrmRegCode  = 0;
    }
    /* Initializing global variable next */
    {
         next  = 0ul;
    }
    /* Initializing global variable enVDPlayerVideoType */
    {
         enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable _bEnableSeamlessPlaying */
    {
         _bEnableSeamlessPlaying  = 0;
    }
    /* Initializing global variable u32VdplayerShareMemAddr */
    {
         u32VdplayerShareMemAddr  = 0ul;
    }
    U8 au8Buff[10]={0};
    _drmCodeAddr = &au8Buff[0];
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_VDPlayer_GetDRMRegistrationCode(_drmCodeAddr);
        /* Post-condition check */

    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VDPlayer_GetDRMRegistrationCode_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VDPlayer_Deactivate_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_VDPlayer_Deactivate(void) */
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Deactivate_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_s32PreSubtitleTagIdx */
    {
         m_s32PreSubtitleTagIdx  = 0L;
    }
    /* Initializing global variable m_u32PreMovieRefreshTextTimer */
    {
         m_u32PreMovieRefreshTextTimer  = 0ul;
    }
    /* Initializing global variable bDrmAuthorization */
    {
         bDrmAuthorization  = 0;
    }
    /* Initializing global variable bDrmFileFormat */
    {
         bDrmFileFormat  = 0;
    }
    /* Initializing global variable bDrmActivationFile */
    {
         bDrmActivationFile  = 0;
    }
    /* Initializing global variable bDrmRentalStatus */
    {
         bDrmRentalStatus  = 0;
    }
    /* Initializing global variable g_bDrmRental */
    {
         g_bDrmRental  = 0;
    }
    /* Initializing global variable g_u8DrmUseLimit */
    {
         g_u8DrmUseLimit  = 0;
    }
    /* Initializing global variable g_u8DrmUseCount */
    {
         g_u8DrmUseCount  = 0;
    }
    /* Initializing global variable u8VDPlayerSetTrickModeResult */
    {
         u8VDPlayerSetTrickModeResult  = 0;
    }
    /* Initializing global variable u8VDPlayerStepPlayResult */
    {
         u8VDPlayerStepPlayResult  = 0;
    }
    /* Initializing global variable _u32SeamlessTimer */
    {
         _u32SeamlessTimer  = 0ul;
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
    /* Initializing global variable u32subtitletype */
    {
         u32subtitletype  = 0ul;
    }
    /* Initializing global variable u16CPageID */
    {
         u16CPageID  = 0u;
    }
    /* Initializing global variable m_bSuspendInternalSubtitle2Queue */
    {
         m_bSuspendInternalSubtitle2Queue  = 0;
    }
    /* Initializing global variable _bSubtitleShow_MW */
    {
         _bSubtitleShow_MW  = 0;
    }
    /* Initializing global variable _bSubtitleShow_User */
    {
         _bSubtitleShow_User  = 0;
    }
    /* Initializing global variable u8InternalST_Num */
    {
         u8InternalST_Num  = 0;
    }
    /* Initializing global variable u16SubtitleTagCnt */
    {
         u16SubtitleTagCnt  = 0u;
    }
    /* Initializing global variable u8IsSubtitleBusy */
    {
         u8IsSubtitleBusy  = 0;
    }
    /* Initializing global variable u8IssubtitleInit */
    {
         u8IssubtitleInit  = 0;
    }
    /* Initializing global variable u8IsSubtitleInitfinish */
    {
         u8IsSubtitleInitfinish  = 0;
    }
    /* Initializing global variable u16tagposition */
    {
         u16tagposition  = 0u;
    }
    /* Initializing global variable u32GetSubtitleStateBuf */
    {
         u32GetSubtitleStateBuf  = 0ul;
    }
    /* Initializing global variable g_bReplay */
    {
         g_bReplay  = 0;
    }
    /* Initializing global variable g_bUnsupportAudio */
    {
         g_bUnsupportAudio  = 0;
    }
    /* Initializing global variable u32VDPlayerLoopWdtTimer */
    {
         u32VDPlayerLoopWdtTimer  = 0ul;
    }
    /* Initializing global variable g_stDemuxer */
    {
         g_stDemuxer.u32Video_IdxSize  = 0ul;
         g_stDemuxer.u32KeyIdxPeriod  = 0ul;
         g_stDemuxer.u32AudioKeyIdxPeriod  = 0ul;
         g_stDemuxer.u32lastVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u32FirstVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u8KeyIdxSize  = 0;
         g_stDemuxer.u8AudioKeyIdxSize  = 0;
         g_stDemuxer.u8ThumbNailMode  = 0;
         g_stDemuxer.bEnableCalcByBitRate  = 0;
         g_stDemuxer.bEnableAudioHandler  = 0;
    }
    /* Initializing global variable g_bIsTSRadioOnly */
    {
         g_bIsTSRadioOnly  = 0;
    }
    /* Initializing global variable g_enVDPlayerVideoType */
    {
         g_enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable g_bForceToFB */
    {
         g_bForceToFB  = 0;
    }
    /* Initializing global variable m_eVDPlayerFlgs */
    {
         m_eVDPlayerFlgs  = E_VDPLAYER_FLG_NONE;
    }
    /* Initializing global variable _gu16PreviewX */
    {
         _gu16PreviewX  = 0u;
    }
    /* Initializing global variable _gu16PreviewY */
    {
         _gu16PreviewY  = 0u;
    }
    /* Initializing global variable _gu16PreviewWidth */
    {
         _gu16PreviewWidth  = 0u;
    }
    /* Initializing global variable _gu16PreviewHeight */
    {
         _gu16PreviewHeight  = 0u;
    }
    /* Initializing global variable m_bFLG_PREVIEW */
    {
         m_bFLG_PREVIEW  = 0;
    }
    /* Initializing global variable g_DstWin */
    {
         g_DstWin.x  = 0u;
         g_DstWin.y  = 0u;
         g_DstWin.width  = 0u;
         g_DstWin.height  = 0u;
    }
    /* Initializing global variable g_bIsResumePlay */
    {
         g_bIsResumePlay  = 0;
    }
    /* Initializing global variable _gbContinueBlockRead */
    {
         _gbContinueBlockRead  = 0;
    }
    /* Initializing global variable enVDPlayerRet */
    {
         enVDPlayerRet  = EXIT_NULL;
    }
    /* Initializing global variable g_bNonBlockingRead */
    {
         g_bNonBlockingRead  = 0;
    }
    /* Initializing global variable _bStreamSeeked */
    {
         _bStreamSeeked  = 0;
    }
    /* Initializing global variable _gu32BlockReadTimer */
    {
         _gu32BlockReadTimer  = 0ul;
    }
    /* Initializing global variable _gbEnableInternalSubtitle */
    {
         _gbEnableInternalSubtitle  = 0;
    }
    /* Initializing global variable _gu32ResidualReadSize */
    {
         _gu32ResidualReadSize  = 0ul;
    }
    /* Initializing global variable _gu32gStreamHdl */
    {
         _gu32gStreamHdl  = 0ul;
    }
    /* Initializing global variable _gu32BuffAddr */
    {
         _gu32BuffAddr  = 0ul;
    }
    /* Initializing global variable g_bNonBlockingSeek */
    {
         g_bNonBlockingSeek  = 0;
    }
    /* Initializing global variable g_b2ndRunPreviewMute */
    {
         g_b2ndRunPreviewMute  = 0;
    }
    /* Initializing global variable u16APageID */
    {
         u16APageID  = 0u;
    }
    /* Initializing global variable u16CodecNum */
    {
         u16CodecNum  = 0u;
    }
    /* Initializing global variable u16Samples_channel */
    {
         u16Samples_channel  = 0u;
    }
    /* Initializing global variable u8VDPlayerInitResult */
    {
         u8VDPlayerInitResult  = 0;
    }
    /* Initializing global variable u8VDPlayerSetAudioTrackResult */
    {
         u8VDPlayerSetAudioTrackResult  = 0;
    }
    /* Initializing global variable u8VDPlayerTsSetProgramResult */
    {
         u8VDPlayerTsSetProgramResult  = 0;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.g_VDplayerDRMInfo.bIsActivated = 1;
    }
    /* Initializing global variable m_eVDPlayerAckFlags */
    {
         m_eVDPlayerAckFlags  = E_ACKFLG_NULL;
    }
    /* Initializing global variable bDrmRegCode */
    {
         bDrmRegCode  = 0;
    }
    /* Initializing global variable next */
    {
         next  = 0ul;
    }
    /* Initializing global variable enVDPlayerVideoType */
    {
         enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable _bEnableSeamlessPlaying */
    {
         _bEnableSeamlessPlaying  = 0;
    }
    /* Initializing global variable u32VdplayerShareMemAddr */
    {
         u32VdplayerShareMemAddr  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_VDPlayer_Deactivate();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VDPlayer_Deactivate_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VDPlayer_QueryDRMRentalStatus_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_VDPlayer_QueryDRMRentalStatus(BOOLEAN *, U8 *, U8 *) */
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_QueryDRMRentalStatus_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (isRental) */
    BOOLEAN * _isRental  = 0 ;
    /* Initializing argument 2 (useLimit) */
    U8 * _useLimit  = 0 ;
    /* Initializing argument 3 (useCount) */
    U8 * _useCount  = 0 ;
    /* Initializing global variable m_s32PreSubtitleTagIdx */
    {
         m_s32PreSubtitleTagIdx  = 0L;
    }
    /* Initializing global variable m_u32PreMovieRefreshTextTimer */
    {
         m_u32PreMovieRefreshTextTimer  = 0ul;
    }
    /* Initializing global variable bDrmAuthorization */
    {
         bDrmAuthorization  = 0;
    }
    /* Initializing global variable bDrmFileFormat */
    {
         bDrmFileFormat  = 0;
    }
    /* Initializing global variable bDrmActivationFile */
    {
         bDrmActivationFile  = 0;
    }
    /* Initializing global variable bDrmRentalStatus */
    {
         bDrmRentalStatus  = 0;
    }
    /* Initializing global variable g_bDrmRental */
    {
         g_bDrmRental  = 0;
    }
    /* Initializing global variable g_u8DrmUseLimit */
    {
         g_u8DrmUseLimit  = 0;
    }
    /* Initializing global variable g_u8DrmUseCount */
    {
         g_u8DrmUseCount  = 0;
    }
    /* Initializing global variable u8VDPlayerSetTrickModeResult */
    {
         u8VDPlayerSetTrickModeResult  = 0;
    }
    /* Initializing global variable u8VDPlayerStepPlayResult */
    {
         u8VDPlayerStepPlayResult  = 0;
    }
    /* Initializing global variable _u32SeamlessTimer */
    {
         _u32SeamlessTimer  = 0ul;
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
    /* Initializing global variable u32subtitletype */
    {
         u32subtitletype  = 0ul;
    }
    /* Initializing global variable u16CPageID */
    {
         u16CPageID  = 0u;
    }
    /* Initializing global variable m_bSuspendInternalSubtitle2Queue */
    {
         m_bSuspendInternalSubtitle2Queue  = 0;
    }
    /* Initializing global variable _bSubtitleShow_MW */
    {
         _bSubtitleShow_MW  = 0;
    }
    /* Initializing global variable _bSubtitleShow_User */
    {
         _bSubtitleShow_User  = 0;
    }
    /* Initializing global variable u8InternalST_Num */
    {
         u8InternalST_Num  = 0;
    }
    /* Initializing global variable u16SubtitleTagCnt */
    {
         u16SubtitleTagCnt  = 0u;
    }
    /* Initializing global variable u8IsSubtitleBusy */
    {
         u8IsSubtitleBusy  = 0;
    }
    /* Initializing global variable u8IssubtitleInit */
    {
         u8IssubtitleInit  = 0;
    }
    /* Initializing global variable u8IsSubtitleInitfinish */
    {
         u8IsSubtitleInitfinish  = 0;
    }
    /* Initializing global variable u16tagposition */
    {
         u16tagposition  = 0u;
    }
    /* Initializing global variable u32GetSubtitleStateBuf */
    {
         u32GetSubtitleStateBuf  = 0ul;
    }
    /* Initializing global variable g_bReplay */
    {
         g_bReplay  = 0;
    }
    /* Initializing global variable g_bUnsupportAudio */
    {
         g_bUnsupportAudio  = 0;
    }
    /* Initializing global variable u32VDPlayerLoopWdtTimer */
    {
         u32VDPlayerLoopWdtTimer  = 0ul;
    }
    /* Initializing global variable g_stDemuxer */
    {
         g_stDemuxer.u32Video_IdxSize  = 0ul;
         g_stDemuxer.u32KeyIdxPeriod  = 0ul;
         g_stDemuxer.u32AudioKeyIdxPeriod  = 0ul;
         g_stDemuxer.u32lastVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u32FirstVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u8KeyIdxSize  = 0;
         g_stDemuxer.u8AudioKeyIdxSize  = 0;
         g_stDemuxer.u8ThumbNailMode  = 0;
         g_stDemuxer.bEnableCalcByBitRate  = 0;
         g_stDemuxer.bEnableAudioHandler  = 0;
    }
    /* Initializing global variable g_bIsTSRadioOnly */
    {
         g_bIsTSRadioOnly  = 0;
    }
    /* Initializing global variable g_enVDPlayerVideoType */
    {
         g_enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable g_bForceToFB */
    {
         g_bForceToFB  = 0;
    }
    /* Initializing global variable m_eVDPlayerFlgs */
    {
         m_eVDPlayerFlgs  = E_VDPLAYER_FLG_NONE;
    }
    /* Initializing global variable _gu16PreviewX */
    {
         _gu16PreviewX  = 0u;
    }
    /* Initializing global variable _gu16PreviewY */
    {
         _gu16PreviewY  = 0u;
    }
    /* Initializing global variable _gu16PreviewWidth */
    {
         _gu16PreviewWidth  = 0u;
    }
    /* Initializing global variable _gu16PreviewHeight */
    {
         _gu16PreviewHeight  = 0u;
    }
    /* Initializing global variable m_bFLG_PREVIEW */
    {
         m_bFLG_PREVIEW  = 0;
    }
    /* Initializing global variable g_DstWin */
    {
         g_DstWin.x  = 0u;
         g_DstWin.y  = 0u;
         g_DstWin.width  = 0u;
         g_DstWin.height  = 0u;
    }
    /* Initializing global variable _gbContinueBlockRead */
    {
         _gbContinueBlockRead  = 0;
    }
    /* Initializing global variable enVDPlayerRet */
    {
         enVDPlayerRet  = EXIT_NULL;
    }
    /* Initializing global variable g_bNonBlockingRead */
    {
         g_bNonBlockingRead  = 0;
    }
    /* Initializing global variable _bStreamSeeked */
    {
         _bStreamSeeked  = 0;
    }
    /* Initializing global variable _gu32BlockReadTimer */
    {
         _gu32BlockReadTimer  = 0ul;
    }
    /* Initializing global variable _gbEnableInternalSubtitle */
    {
         _gbEnableInternalSubtitle  = 0;
    }
    /* Initializing global variable _gu32ResidualReadSize */
    {
         _gu32ResidualReadSize  = 0ul;
    }
    /* Initializing global variable _gu32gStreamHdl */
    {
         _gu32gStreamHdl  = 0ul;
    }
    /* Initializing global variable _gu32BuffAddr */
    {
         _gu32BuffAddr  = 0ul;
    }
    /* Initializing global variable g_bNonBlockingSeek */
    {
         g_bNonBlockingSeek  = 0;
    }
    /* Initializing global variable g_b2ndRunPreviewMute */
    {
         g_b2ndRunPreviewMute  = 0;
    }
    /* Initializing global variable u16APageID */
    {
         u16APageID  = 0u;
    }
    /* Initializing global variable u16CodecNum */
    {
         u16CodecNum  = 0u;
    }
    /* Initializing global variable u16Samples_channel */
    {
         u16Samples_channel  = 0u;
    }
    /* Initializing global variable u8VDPlayerInitResult */
    {
         u8VDPlayerInitResult  = 0;
    }
    /* Initializing global variable u8VDPlayerSetAudioTrackResult */
    {
         u8VDPlayerSetAudioTrackResult  = 0;
    }
    /* Initializing global variable u8VDPlayerTsSetProgramResult */
    {
         u8VDPlayerTsSetProgramResult  = 0;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable m_eVDPlayerAckFlags */
    {
         m_eVDPlayerAckFlags  = E_ACKFLG_NULL;
    }
    /* Initializing global variable bDrmRegCode */
    {
         bDrmRegCode  = 0;
    }
    /* Initializing global variable enVDPlayerVideoType */
    {
         enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable _bEnableSeamlessPlaying */
    {
         _bEnableSeamlessPlaying  = 0;
    }
    /* Initializing global variable u32VdplayerShareMemAddr */
    {
         u32VdplayerShareMemAddr  = 0ul;
    }
    BOOLEAN isRental;
    U8 useLimit,useCount;
    _isRental = &isRental;
    _useLimit = &useLimit;
    _useCount = &useCount;
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_VDPlayer_QueryDRMRentalStatus(_isRental, _useLimit, _useCount);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VDPlayer_QueryDRMRentalStatus_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VDPlayer_CheckDRMAutuorization_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_VDPlayer_CheckDRMAutuorization(void) */

void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetbDrmAuthorization()
{
	BOOLEAN _return ;
	bDrmAuthorization = 1;

	_return  = bDrmAuthorization;
	/* Post-condition check */
	CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ) );
}

void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_CheckDRMAutuorization_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_s32PreSubtitleTagIdx */
    {
         m_s32PreSubtitleTagIdx  = 0L;
    }
    /* Initializing global variable m_u32PreMovieRefreshTextTimer */
    {
         m_u32PreMovieRefreshTextTimer  = 0ul;
    }
    /* Initializing global variable bDrmAuthorization */
    {
         bDrmAuthorization  = 0;
    }
    /* Initializing global variable bDrmFileFormat */
    {
         bDrmFileFormat  = 0;
    }
    /* Initializing global variable bDrmActivationFile */
    {
         bDrmActivationFile  = 0;
    }
    /* Initializing global variable bDrmRentalStatus */
    {
         bDrmRentalStatus  = 0;
    }
    /* Initializing global variable g_bDrmRental */
    {
         g_bDrmRental  = 0;
    }
    /* Initializing global variable g_u8DrmUseLimit */
    {
         g_u8DrmUseLimit  = 0;
    }
    /* Initializing global variable g_u8DrmUseCount */
    {
         g_u8DrmUseCount  = 0;
    }
    /* Initializing global variable u8VDPlayerSetTrickModeResult */
    {
         u8VDPlayerSetTrickModeResult  = 0;
    }
    /* Initializing global variable u8VDPlayerStepPlayResult */
    {
         u8VDPlayerStepPlayResult  = 0;
    }
    /* Initializing global variable _u32SeamlessTimer */
    {
         _u32SeamlessTimer  = 0ul;
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
    /* Initializing global variable u32subtitletype */
    {
         u32subtitletype  = 0ul;
    }
    /* Initializing global variable u16CPageID */
    {
         u16CPageID  = 0u;
    }
    /* Initializing global variable m_bSuspendInternalSubtitle2Queue */
    {
         m_bSuspendInternalSubtitle2Queue  = 0;
    }
    /* Initializing global variable _bSubtitleShow_MW */
    {
         _bSubtitleShow_MW  = 0;
    }
    /* Initializing global variable _bSubtitleShow_User */
    {
         _bSubtitleShow_User  = 0;
    }
    /* Initializing global variable u8InternalST_Num */
    {
         u8InternalST_Num  = 0;
    }
    /* Initializing global variable u16SubtitleTagCnt */
    {
         u16SubtitleTagCnt  = 0u;
    }
    /* Initializing global variable u8IsSubtitleBusy */
    {
         u8IsSubtitleBusy  = 0;
    }
    /* Initializing global variable u8IssubtitleInit */
    {
         u8IssubtitleInit  = 0;
    }
    /* Initializing global variable u8IsSubtitleInitfinish */
    {
         u8IsSubtitleInitfinish  = 0;
    }
    /* Initializing global variable u16tagposition */
    {
         u16tagposition  = 0u;
    }
    /* Initializing global variable u32GetSubtitleStateBuf */
    {
         u32GetSubtitleStateBuf  = 0ul;
    }
    /* Initializing global variable g_bReplay */
    {
         g_bReplay  = 0;
    }
    /* Initializing global variable g_bUnsupportAudio */
    {
         g_bUnsupportAudio  = 0;
    }
    /* Initializing global variable u32VDPlayerLoopWdtTimer */
    {
         u32VDPlayerLoopWdtTimer  = 0ul;
    }
    /* Initializing global variable g_stDemuxer */
    {
         g_stDemuxer.u32Video_IdxSize  = 0ul;
         g_stDemuxer.u32KeyIdxPeriod  = 0ul;
         g_stDemuxer.u32AudioKeyIdxPeriod  = 0ul;
         g_stDemuxer.u32lastVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u32FirstVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u8KeyIdxSize  = 0;
         g_stDemuxer.u8AudioKeyIdxSize  = 0;
         g_stDemuxer.u8ThumbNailMode  = 0;
         g_stDemuxer.bEnableCalcByBitRate  = 0;
         g_stDemuxer.bEnableAudioHandler  = 0;
    }
    /* Initializing global variable g_bIsTSRadioOnly */
    {
         g_bIsTSRadioOnly  = 0;
    }
    /* Initializing global variable g_enVDPlayerVideoType */
    {
         g_enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable g_bForceToFB */
    {
         g_bForceToFB  = 0;
    }
    /* Initializing global variable m_eVDPlayerFlgs */
    {
         m_eVDPlayerFlgs  = E_VDPLAYER_FLG_NONE;
    }
    /* Initializing global variable _gu16PreviewX */
    {
         _gu16PreviewX  = 0u;
    }
    /* Initializing global variable _gu16PreviewY */
    {
         _gu16PreviewY  = 0u;
    }
    /* Initializing global variable _gu16PreviewWidth */
    {
         _gu16PreviewWidth  = 0u;
    }
    /* Initializing global variable _gu16PreviewHeight */
    {
         _gu16PreviewHeight  = 0u;
    }
    /* Initializing global variable m_bFLG_PREVIEW */
    {
         m_bFLG_PREVIEW  = 0;
    }
    /* Initializing global variable g_DstWin */
    {
         g_DstWin.x  = 0u;
         g_DstWin.y  = 0u;
         g_DstWin.width  = 0u;
         g_DstWin.height  = 0u;
    }
    /* Initializing global variable _gbContinueBlockRead */
    {
         _gbContinueBlockRead  = 0;
    }
    /* Initializing global variable enVDPlayerRet */
    {
         enVDPlayerRet  = EXIT_NULL;
    }
    /* Initializing global variable g_bNonBlockingRead */
    {
         g_bNonBlockingRead  = 0;
    }
    /* Initializing global variable _bStreamSeeked */
    {
         _bStreamSeeked  = 0;
    }
    /* Initializing global variable _gu32BlockReadTimer */
    {
         _gu32BlockReadTimer  = 0ul;
    }
    /* Initializing global variable _gbEnableInternalSubtitle */
    {
         _gbEnableInternalSubtitle  = 0;
    }
    /* Initializing global variable _gu32ResidualReadSize */
    {
         _gu32ResidualReadSize  = 0ul;
    }
    /* Initializing global variable _gu32gStreamHdl */
    {
         _gu32gStreamHdl  = 0ul;
    }
    /* Initializing global variable _gu32BuffAddr */
    {
         _gu32BuffAddr  = 0ul;
    }
    /* Initializing global variable g_bNonBlockingSeek */
    {
         g_bNonBlockingSeek  = 0;
    }
    /* Initializing global variable g_b2ndRunPreviewMute */
    {
         g_b2ndRunPreviewMute  = 0;
    }
    /* Initializing global variable u16APageID */
    {
         u16APageID  = 0u;
    }
    /* Initializing global variable u16CodecNum */
    {
         u16CodecNum  = 0u;
    }
    /* Initializing global variable u16Samples_channel */
    {
         u16Samples_channel  = 0u;
    }
    /* Initializing global variable u8VDPlayerInitResult */
    {
         u8VDPlayerInitResult  = 0;
    }
    /* Initializing global variable u8VDPlayerSetAudioTrackResult */
    {
         u8VDPlayerSetAudioTrackResult  = 0;
    }
    /* Initializing global variable u8VDPlayerTsSetProgramResult */
    {
         u8VDPlayerTsSetProgramResult  = 0;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable m_eVDPlayerAckFlags */
    {
         m_eVDPlayerAckFlags  = E_ACKFLG_NULL;
    }
    /* Initializing global variable bDrmRegCode */
    {
         bDrmRegCode  = 0;
    }
    /* Initializing global variable enVDPlayerVideoType */
    {
         enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable _bEnableSeamlessPlaying */
    {
         _bEnableSeamlessPlaying  = 0;
    }
    /* Initializing global variable u32VdplayerShareMemAddr */
    {
         u32VdplayerShareMemAddr  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_VDPlayer_CheckDRMAutuorization();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VDPlayer_CheckDRMAutuorization_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VDPlayer_CheckDRMActivationFile_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_VDPlayer_CheckDRMActivationFile(void) */
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetbDrmActivationFile()
{
	BOOLEAN _return ;

	bDrmActivationFile =1;

	_return  = bDrmActivationFile;
	/* Post-condition check */
	CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ) );
}
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_CheckDRMActivationFile_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_s32PreSubtitleTagIdx */
    {
         m_s32PreSubtitleTagIdx  = 0L;
    }
    /* Initializing global variable m_u32PreMovieRefreshTextTimer */
    {
         m_u32PreMovieRefreshTextTimer  = 0ul;
    }
    /* Initializing global variable bDrmAuthorization */
    {
         bDrmAuthorization  = 0;
    }
    /* Initializing global variable bDrmFileFormat */
    {
         bDrmFileFormat  = 0;
    }
    /* Initializing global variable bDrmActivationFile */
    {
         bDrmActivationFile  = 0;
    }
    /* Initializing global variable bDrmRentalStatus */
    {
         bDrmRentalStatus  = 0;
    }
    /* Initializing global variable g_bDrmRental */
    {
         g_bDrmRental  = 0;
    }
    /* Initializing global variable g_u8DrmUseLimit */
    {
         g_u8DrmUseLimit  = 0;
    }
    /* Initializing global variable g_u8DrmUseCount */
    {
         g_u8DrmUseCount  = 0;
    }
    /* Initializing global variable u8VDPlayerSetTrickModeResult */
    {
         u8VDPlayerSetTrickModeResult  = 0;
    }
    /* Initializing global variable u8VDPlayerStepPlayResult */
    {
         u8VDPlayerStepPlayResult  = 0;
    }
    /* Initializing global variable _u32SeamlessTimer */
    {
         _u32SeamlessTimer  = 0ul;
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
    /* Initializing global variable u32subtitletype */
    {
         u32subtitletype  = 0ul;
    }
    /* Initializing global variable u16CPageID */
    {
         u16CPageID  = 0u;
    }
    /* Initializing global variable m_bSuspendInternalSubtitle2Queue */
    {
         m_bSuspendInternalSubtitle2Queue  = 0;
    }
    /* Initializing global variable _bSubtitleShow_MW */
    {
         _bSubtitleShow_MW  = 0;
    }
    /* Initializing global variable _bSubtitleShow_User */
    {
         _bSubtitleShow_User  = 0;
    }
    /* Initializing global variable u8InternalST_Num */
    {
         u8InternalST_Num  = 0;
    }
    /* Initializing global variable u16SubtitleTagCnt */
    {
         u16SubtitleTagCnt  = 0u;
    }
    /* Initializing global variable u8IsSubtitleBusy */
    {
         u8IsSubtitleBusy  = 0;
    }
    /* Initializing global variable u8IssubtitleInit */
    {
         u8IssubtitleInit  = 0;
    }
    /* Initializing global variable u8IsSubtitleInitfinish */
    {
         u8IsSubtitleInitfinish  = 0;
    }
    /* Initializing global variable u16tagposition */
    {
         u16tagposition  = 0u;
    }
    /* Initializing global variable u32GetSubtitleStateBuf */
    {
         u32GetSubtitleStateBuf  = 0ul;
    }
    /* Initializing global variable g_bReplay */
    {
         g_bReplay  = 0;
    }
    /* Initializing global variable g_bUnsupportAudio */
    {
         g_bUnsupportAudio  = 0;
    }
    /* Initializing global variable u32VDPlayerLoopWdtTimer */
    {
         u32VDPlayerLoopWdtTimer  = 0ul;
    }
    /* Initializing global variable g_stDemuxer */
    {
         g_stDemuxer.u32Video_IdxSize  = 0ul;
         g_stDemuxer.u32KeyIdxPeriod  = 0ul;
         g_stDemuxer.u32AudioKeyIdxPeriod  = 0ul;
         g_stDemuxer.u32lastVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u32FirstVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u8KeyIdxSize  = 0;
         g_stDemuxer.u8AudioKeyIdxSize  = 0;
         g_stDemuxer.u8ThumbNailMode  = 0;
         g_stDemuxer.bEnableCalcByBitRate  = 0;
         g_stDemuxer.bEnableAudioHandler  = 0;
    }
    /* Initializing global variable g_bIsTSRadioOnly */
    {
         g_bIsTSRadioOnly  = 0;
    }
    /* Initializing global variable g_enVDPlayerVideoType */
    {
         g_enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable g_bForceToFB */
    {
         g_bForceToFB  = 0;
    }
    /* Initializing global variable m_eVDPlayerFlgs */
    {
         m_eVDPlayerFlgs  = E_VDPLAYER_FLG_NONE;
    }
    /* Initializing global variable _gu16PreviewX */
    {
         _gu16PreviewX  = 0u;
    }
    /* Initializing global variable _gu16PreviewY */
    {
         _gu16PreviewY  = 0u;
    }
    /* Initializing global variable _gu16PreviewWidth */
    {
         _gu16PreviewWidth  = 0u;
    }
    /* Initializing global variable _gu16PreviewHeight */
    {
         _gu16PreviewHeight  = 0u;
    }
    /* Initializing global variable m_bFLG_PREVIEW */
    {
         m_bFLG_PREVIEW  = 0;
    }
    /* Initializing global variable g_DstWin */
    {
         g_DstWin.x  = 0u;
         g_DstWin.y  = 0u;
         g_DstWin.width  = 0u;
         g_DstWin.height  = 0u;
    }
    /* Initializing global variable _gbContinueBlockRead */
    {
         _gbContinueBlockRead  = 0;
    }
    /* Initializing global variable enVDPlayerRet */
    {
         enVDPlayerRet  = EXIT_NULL;
    }
    /* Initializing global variable g_bNonBlockingRead */
    {
         g_bNonBlockingRead  = 0;
    }
    /* Initializing global variable _bStreamSeeked */
    {
         _bStreamSeeked  = 0;
    }
    /* Initializing global variable _gu32BlockReadTimer */
    {
         _gu32BlockReadTimer  = 0ul;
    }
    /* Initializing global variable _gbEnableInternalSubtitle */
    {
         _gbEnableInternalSubtitle  = 0;
    }
    /* Initializing global variable _gu32ResidualReadSize */
    {
         _gu32ResidualReadSize  = 0ul;
    }
    /* Initializing global variable _gu32gStreamHdl */
    {
         _gu32gStreamHdl  = 0ul;
    }
    /* Initializing global variable _gu32BuffAddr */
    {
         _gu32BuffAddr  = 0ul;
    }
    /* Initializing global variable g_bNonBlockingSeek */
    {
         g_bNonBlockingSeek  = 0;
    }
    /* Initializing global variable g_b2ndRunPreviewMute */
    {
         g_b2ndRunPreviewMute  = 0;
    }
    /* Initializing global variable u16APageID */
    {
         u16APageID  = 0u;
    }
    /* Initializing global variable u16CodecNum */
    {
         u16CodecNum  = 0u;
    }
    /* Initializing global variable u16Samples_channel */
    {
         u16Samples_channel  = 0u;
    }
    /* Initializing global variable u8VDPlayerInitResult */
    {
         u8VDPlayerInitResult  = 0;
    }
    /* Initializing global variable u8VDPlayerSetAudioTrackResult */
    {
         u8VDPlayerSetAudioTrackResult  = 0;
    }
    /* Initializing global variable u8VDPlayerTsSetProgramResult */
    {
         u8VDPlayerTsSetProgramResult  = 0;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable m_eVDPlayerAckFlags */
    {
         m_eVDPlayerAckFlags  = E_ACKFLG_NULL;
    }
    /* Initializing global variable bDrmRegCode */
    {
         bDrmRegCode  = 0;
    }
    /* Initializing global variable enVDPlayerVideoType */
    {
         enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable _bEnableSeamlessPlaying */
    {
         _bEnableSeamlessPlaying  = 0;
    }
    /* Initializing global variable u32VdplayerShareMemAddr */
    {
         u32VdplayerShareMemAddr  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_VDPlayer_CheckDRMActivationFile();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VDPlayer_CheckDRMActivationFile_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VDPlayer_GetDRMDeactivationCode_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_VDPlayer_GetDRMDeactivationCode(U32) */
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_GetDRMDeactivationCode_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (drmCodeAddr) */
    U32 _drmCodeAddr  = 0ul;
    /* Initializing global variable m_s32PreSubtitleTagIdx */
    {
         m_s32PreSubtitleTagIdx  = 0L;
    }
    /* Initializing global variable m_u32PreMovieRefreshTextTimer */
    {
         m_u32PreMovieRefreshTextTimer  = 0ul;
    }
    /* Initializing global variable bDrmAuthorization */
    {
         bDrmAuthorization  = 0;
    }
    /* Initializing global variable bDrmFileFormat */
    {
         bDrmFileFormat  = 0;
    }
    /* Initializing global variable bDrmActivationFile */
    {
         bDrmActivationFile  = 0;
    }
    /* Initializing global variable bDrmRentalStatus */
    {
         bDrmRentalStatus  = 0;
    }
    /* Initializing global variable g_bDrmRental */
    {
         g_bDrmRental  = 0;
    }
    /* Initializing global variable g_u8DrmUseLimit */
    {
         g_u8DrmUseLimit  = 0;
    }
    /* Initializing global variable g_u8DrmUseCount */
    {
         g_u8DrmUseCount  = 0;
    }
    /* Initializing global variable u8VDPlayerSetTrickModeResult */
    {
         u8VDPlayerSetTrickModeResult  = 0;
    }
    /* Initializing global variable u8VDPlayerStepPlayResult */
    {
         u8VDPlayerStepPlayResult  = 0;
    }
    /* Initializing global variable _u32SeamlessTimer */
    {
         _u32SeamlessTimer  = 0ul;
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
    /* Initializing global variable u32subtitletype */
    {
         u32subtitletype  = 0ul;
    }
    /* Initializing global variable u16CPageID */
    {
         u16CPageID  = 0u;
    }
    /* Initializing global variable m_bSuspendInternalSubtitle2Queue */
    {
         m_bSuspendInternalSubtitle2Queue  = 0;
    }
    /* Initializing global variable _bSubtitleShow_MW */
    {
         _bSubtitleShow_MW  = 0;
    }
    /* Initializing global variable _bSubtitleShow_User */
    {
         _bSubtitleShow_User  = 0;
    }
    /* Initializing global variable u8InternalST_Num */
    {
         u8InternalST_Num  = 0;
    }
    /* Initializing global variable u16SubtitleTagCnt */
    {
         u16SubtitleTagCnt  = 0u;
    }
    /* Initializing global variable u8IsSubtitleBusy */
    {
         u8IsSubtitleBusy  = 0;
    }
    /* Initializing global variable u8IssubtitleInit */
    {
         u8IssubtitleInit  = 0;
    }
    /* Initializing global variable u8IsSubtitleInitfinish */
    {
         u8IsSubtitleInitfinish  = 0;
    }
    /* Initializing global variable u16tagposition */
    {
         u16tagposition  = 0u;
    }
    /* Initializing global variable u32GetSubtitleStateBuf */
    {
         u32GetSubtitleStateBuf  = 0ul;
    }
    /* Initializing global variable g_bReplay */
    {
         g_bReplay  = 0;
    }
    /* Initializing global variable g_bUnsupportAudio */
    {
         g_bUnsupportAudio  = 0;
    }
    /* Initializing global variable u32VDPlayerLoopWdtTimer */
    {
         u32VDPlayerLoopWdtTimer  = 0ul;
    }
    /* Initializing global variable g_stDemuxer */
    {
         g_stDemuxer.u32Video_IdxSize  = 0ul;
         g_stDemuxer.u32KeyIdxPeriod  = 0ul;
         g_stDemuxer.u32AudioKeyIdxPeriod  = 0ul;
         g_stDemuxer.u32lastVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u32FirstVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u8KeyIdxSize  = 0;
         g_stDemuxer.u8AudioKeyIdxSize  = 0;
         g_stDemuxer.u8ThumbNailMode  = 0;
         g_stDemuxer.bEnableCalcByBitRate  = 0;
         g_stDemuxer.bEnableAudioHandler  = 0;
    }
    /* Initializing global variable g_bIsTSRadioOnly */
    {
         g_bIsTSRadioOnly  = 0;
    }
    /* Initializing global variable g_enVDPlayerVideoType */
    {
         g_enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable g_bForceToFB */
    {
         g_bForceToFB  = 0;
    }
    /* Initializing global variable m_eVDPlayerFlgs */
    {
         m_eVDPlayerFlgs  = E_VDPLAYER_FLG_NONE;
    }
    /* Initializing global variable _gu16PreviewX */
    {
         _gu16PreviewX  = 0u;
    }
    /* Initializing global variable _gu16PreviewY */
    {
         _gu16PreviewY  = 0u;
    }
    /* Initializing global variable _gu16PreviewWidth */
    {
         _gu16PreviewWidth  = 0u;
    }
    /* Initializing global variable _gu16PreviewHeight */
    {
         _gu16PreviewHeight  = 0u;
    }
    /* Initializing global variable m_bFLG_PREVIEW */
    {
         m_bFLG_PREVIEW  = 0;
    }
    /* Initializing global variable g_DstWin */
    {
         g_DstWin.x  = 0u;
         g_DstWin.y  = 0u;
         g_DstWin.width  = 0u;
         g_DstWin.height  = 0u;
    }
    /* Initializing global variable g_bIsResumePlay */
    {
         g_bIsResumePlay  = 0;
    }
    /* Initializing global variable _gbContinueBlockRead */
    {
         _gbContinueBlockRead  = 0;
    }
    /* Initializing global variable enVDPlayerRet */
    {
         enVDPlayerRet  = EXIT_NULL;
    }
    /* Initializing global variable g_bNonBlockingRead */
    {
         g_bNonBlockingRead  = 0;
    }
    /* Initializing global variable _bStreamSeeked */
    {
         _bStreamSeeked  = 0;
    }
    /* Initializing global variable _gu32BlockReadTimer */
    {
         _gu32BlockReadTimer  = 0ul;
    }
    /* Initializing global variable _gbEnableInternalSubtitle */
    {
         _gbEnableInternalSubtitle  = 0;
    }
    /* Initializing global variable _gu32ResidualReadSize */
    {
         _gu32ResidualReadSize  = 0ul;
    }
    /* Initializing global variable _gu32gStreamHdl */
    {
         _gu32gStreamHdl  = 0ul;
    }
    /* Initializing global variable _gu32BuffAddr */
    {
         _gu32BuffAddr  = 0ul;
    }
    /* Initializing global variable g_bNonBlockingSeek */
    {
         g_bNonBlockingSeek  = 0;
    }
    /* Initializing global variable g_b2ndRunPreviewMute */
    {
         g_b2ndRunPreviewMute  = 0;
    }
    /* Initializing global variable u16APageID */
    {
         u16APageID  = 0u;
    }
    /* Initializing global variable u16CodecNum */
    {
         u16CodecNum  = 0u;
    }
    /* Initializing global variable u16Samples_channel */
    {
         u16Samples_channel  = 0u;
    }
    /* Initializing global variable u8VDPlayerInitResult */
    {
         u8VDPlayerInitResult  = 0;
    }
    /* Initializing global variable u8VDPlayerSetAudioTrackResult */
    {
         u8VDPlayerSetAudioTrackResult  = 0;
    }
    /* Initializing global variable u8VDPlayerTsSetProgramResult */
    {
         u8VDPlayerTsSetProgramResult  = 0;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable m_eVDPlayerAckFlags */
    {
         m_eVDPlayerAckFlags  = E_ACKFLG_NULL;
    }
    /* Initializing global variable bDrmRegCode */
    {
         bDrmRegCode  = 0;
    }
    /* Initializing global variable enVDPlayerVideoType */
    {
         enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable _bEnableSeamlessPlaying */
    {
         _bEnableSeamlessPlaying  = 0;
    }
    /* Initializing global variable u32VdplayerShareMemAddr */
    {
         u32VdplayerShareMemAddr  = 0ul;
    }
    U8 au8Buff[8] = {0};
    _drmCodeAddr = &au8Buff[0];
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_VDPlayer_GetDRMDeactivationCode(_drmCodeAddr);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VDPlayer_GetDRMDeactivationCode_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_VDPlayer_Demuxer_CalVideoFrameTime_case1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_VDPlayer_Demuxer_CalVideoFrameTime(U32) */
void TestSuite_mapp_videoplayer_test_msAPI_VDPlayer_Demuxer_CalVideoFrameTime_case1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FrmIdx) */
    U32 _u32FrmIdx  = 0ul;
    /* Initializing global variable g_stDemuxer */
    {
         g_stDemuxer.u32Video_IdxSize  = 0ul;
         g_stDemuxer.u32KeyIdxPeriod  = 0ul;
         g_stDemuxer.u32AudioKeyIdxPeriod  = 0ul;
         g_stDemuxer.u32lastVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u32FirstVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u8KeyIdxSize  = 0;
         g_stDemuxer.u8AudioKeyIdxSize  = 0;
         g_stDemuxer.u8ThumbNailMode  = 0;
         g_stDemuxer.bEnableCalcByBitRate  = 0;
         g_stDemuxer.bEnableAudioHandler  = 0;
    }
    g_stDemuxer.stBitsContent.Container.stAVI.VideoTracks[0].u32FrameRate =1;
    g_stDemuxer.stBitsContent.Container.stAVI.VideoTracks[0].u32FrameRateBase =1;
    {
        /* Tested function call */
        U32 _return  = msAPI_VDPlayer_Demuxer_CalVideoFrameTime(_u32FrmIdx);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_VDPlayer_Demuxer_CalVideoFrameTime_case1 */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_VDPlayer_Init_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_VDPlayer_Init(VIDEO_PLAYER_INPUT_SOURCE_TYPE, VIDEO_PLAYER_PLAYING_TYPE, FileEntry *) */
void TestSuite_mapp_videoplayer_test_msAPI_VDPlayer_Setu8VDPlayerInitResult(void)
{
	u8VDPlayerInitResult=1;
}
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Init_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eInSrcType) */
    VIDEO_PLAYER_INPUT_SOURCE_TYPE _eInSrcType  = VIDEO_PLAYER_INPUT_SOURCE_MM;
    /* Initializing argument 2 (eType) */
    VIDEO_PLAYER_PLAYING_TYPE _eType  = VIDEO_PLAYER_PLAYING_TYPE_MPEG4;
    /* Initializing argument 3 (pFileEntry) */
    FileEntry _pFileEntry_0 ;
    FileEntry * _pFileEntry  = & _pFileEntry_0;
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable DRMinfo */
    {
         DRMinfo.u8DrmRentalStatus  = 0;
         DRMinfo.u8DrmFileFormat  = 0;
         DRMinfo.u8DrmAuthorization  = 0;
         DRMinfo.u32VDPlayerErrCode  = 0ul;
         DRMinfo.u32DrmRentalCode  = 0ul;
         DRMinfo.u32DrmRentalFile  = 0ul;
         DRMinfo.u32DrmRentalLimit  = 0ul;
         DRMinfo.u32DrmRentalUseCount  = 0ul;
    }
    /* Initializing global variable _gpfnForceStopCallBack */
    {
         _gpfnForceStopCallBack  = 0 ;
    }
    /* Initializing global variable g_WMDRMPrivateReady */
    {
         g_WMDRMPrivateReady  = 0;
    }
    /* Initializing global variable g_InputSourceType */
    {
         g_InputSourceType  = VIDEO_PLAYER_INPUT_SOURCE_MM;
    }
    /* Initializing global variable g_VideoPlayerPlayingType */
    {
         g_VideoPlayerPlayingType  = VIDEO_PLAYER_PLAYING_TYPE_MPEG4;
    }
    /* Initializing global variable _gbCoprocessorEnable */
    {
         _gbCoprocessorEnable  = 0;
    }
    /* Initializing global variable m_bEnableNewMMAudioMode */
    {
         m_bEnableNewMMAudioMode  = 0;
    }
    /* Initializing global variable m_bVDPlayerProbeHeaderOnly */
    {
         m_bVDPlayerProbeHeaderOnly  = 0;
    }
    /* Initializing global variable u32SecbufAddr */
    {
         u32SecbufAddr  = 0ul;
    }
    /* Initializing global variable u32SecbufSize */
    {
         u32SecbufSize  = 0ul;
    }
    /* Initializing global variable m_s32PreSubtitleTagIdx */
    {
         m_s32PreSubtitleTagIdx  = 0L;
    }
    /* Initializing global variable m_u32PreMovieRefreshTextTimer */
    {
         m_u32PreMovieRefreshTextTimer  = 0ul;
    }
    /* Initializing global variable bMovieAbort */
    {
         bMovieAbort  = 0;
    }
    /* Initializing global variable m_bVDPlayerPreview */
    {
         m_bVDPlayerPreview  = 0;
    }
    /* Initializing global variable m_bVDPlayerThumbnail */
    {
         m_bVDPlayerThumbnail  = 0;
    }
    /* Initializing global variable _geBMStreamMode */
    {
         _geBMStreamMode  = E_BM_STREAM_MODE_NORMAL;
    }
    /* Initializing global variable m_u8LastMemoryCheck */
    {
         m_u8LastMemoryCheck  = 0;
    }
    /* Initializing global variable bDrmAuthorization */
    {
         bDrmAuthorization  = 0;
    }
    /* Initializing global variable bDrmFileFormat */
    {
         bDrmFileFormat  = 0;
    }
    /* Initializing global variable bDrmActivationFile */
    {
         bDrmActivationFile  = 0;
    }
    /* Initializing global variable bDrmRentalStatus */
    {
         bDrmRentalStatus  = 0;
    }
    /* Initializing global variable g_bDrmRental */
    {
         g_bDrmRental  = 0;
    }
    /* Initializing global variable g_u8DrmUseLimit */
    {
         g_u8DrmUseLimit  = 0;
    }
    /* Initializing global variable g_u8DrmUseCount */
    {
         g_u8DrmUseCount  = 0;
    }
    /* Initializing global variable u8VDPlayerSetTrickModeResult */
    {
         u8VDPlayerSetTrickModeResult  = 0;
    }
    /* Initializing global variable u8VDPlayerStepPlayResult */
    {
         u8VDPlayerStepPlayResult  = 0;
    }
    /* Initializing global variable _u32SeamlessTimer */
    {
         _u32SeamlessTimer  = 0ul;
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
    /* Initializing global variable u32subtitletype */
    {
         u32subtitletype  = 0ul;
    }
    /* Initializing global variable u16CPageID */
    {
         u16CPageID  = 0u;
    }
    /* Initializing global variable m_bSuspendInternalSubtitle2Queue */
    {
         m_bSuspendInternalSubtitle2Queue  = 0;
    }
    /* Initializing global variable _bSubtitleShow_MW */
    {
         _bSubtitleShow_MW  = 0;
    }
    /* Initializing global variable _bSubtitleShow_User */
    {
         _bSubtitleShow_User  = 0;
    }
    /* Initializing global variable u8InternalST_Num */
    {
         u8InternalST_Num  = 0;
    }
    /* Initializing global variable u16SubtitleTagCnt */
    {
         u16SubtitleTagCnt  = 0u;
    }
    /* Initializing global variable u8IsSubtitleBusy */
    {
         u8IsSubtitleBusy  = 0;
    }
    /* Initializing global variable u8IssubtitleInit */
    {
         u8IssubtitleInit  = 0;
    }
    /* Initializing global variable u8IsSubtitleInitfinish */
    {
         u8IsSubtitleInitfinish  = 0;
    }
    /* Initializing global variable u16tagposition */
    {
         u16tagposition  = 0u;
    }
    /* Initializing global variable u32GetSubtitleStateBuf */
    {
         u32GetSubtitleStateBuf  = 0ul;
    }
    /* Initializing global variable g_bReplay */
    {
         g_bReplay  = 0;
    }
    /* Initializing global variable g_bUnsupportAudio */
    {
         g_bUnsupportAudio  = 0;
    }
    /* Initializing global variable u32VDPlayerLoopWdtTimer */
    {
         u32VDPlayerLoopWdtTimer  = 0ul;
    }
    /* Initializing global variable g_stDemuxer */
    {
         g_stDemuxer.u32Video_IdxSize  = 0ul;
         g_stDemuxer.u32KeyIdxPeriod  = 0ul;
         g_stDemuxer.u32AudioKeyIdxPeriod  = 0ul;
         g_stDemuxer.u32lastVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u32FirstVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u8KeyIdxSize  = 0;
         g_stDemuxer.u8AudioKeyIdxSize  = 0;
         g_stDemuxer.u8ThumbNailMode  = 0;
         g_stDemuxer.bEnableCalcByBitRate  = 0;
         g_stDemuxer.bEnableAudioHandler  = 0;
    }
    /* Initializing global variable g_bIsTSRadioOnly */
    {
         g_bIsTSRadioOnly  = 0;
    }
    /* Initializing global variable g_enVDPlayerVideoType */
    {
         g_enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable g_bForceToFB */
    {
         g_bForceToFB  = 0;
    }
    /* Initializing global variable m_eVDPlayerFlgs */
    {
         m_eVDPlayerFlgs  = E_VDPLAYER_FLG_NONE;
    }
    /* Initializing global variable _gu16PreviewX */
    {
         _gu16PreviewX  = 0u;
    }
    /* Initializing global variable _gu16PreviewY */
    {
         _gu16PreviewY  = 0u;
    }
    /* Initializing global variable _gu16PreviewWidth */
    {
         _gu16PreviewWidth  = 0u;
    }
    /* Initializing global variable _gu16PreviewHeight */
    {
         _gu16PreviewHeight  = 0u;
    }
    /* Initializing global variable m_bFLG_PREVIEW */
    {
         m_bFLG_PREVIEW  = 0;
    }
    /* Initializing global variable g_DstWin */
    {
         g_DstWin.x  = 0u;
         g_DstWin.y  = 0u;
         g_DstWin.width  = 0u;
         g_DstWin.height  = 0u;
    }
    /* Initializing global variable g_bIsResumePlay */
    {
         g_bIsResumePlay  = 0;
    }
    /* Initializing global variable _gbContinueBlockRead */
    {
         _gbContinueBlockRead  = 0;
    }
    /* Initializing global variable enVDPlayerRet */
    {
         enVDPlayerRet  = EXIT_NULL;
    }
    /* Initializing global variable g_bNonBlockingRead */
    {
         g_bNonBlockingRead  = 0;
    }
    /* Initializing global variable _bStreamSeeked */
    {
         _bStreamSeeked  = 0;
    }
    /* Initializing global variable _gu32BlockReadTimer */
    {
         _gu32BlockReadTimer  = 0ul;
    }
    /* Initializing global variable _gbEnableInternalSubtitle */
    {
         _gbEnableInternalSubtitle  = 0;
    }
    /* Initializing global variable _gu32ResidualReadSize */
    {
         _gu32ResidualReadSize  = 0ul;
    }
    /* Initializing global variable _gu32gStreamHdl */
    {
         _gu32gStreamHdl  = 0ul;
    }
    /* Initializing global variable _gu32BuffAddr */
    {
         _gu32BuffAddr  = 0ul;
    }
    /* Initializing global variable g_bNonBlockingSeek */
    {
         g_bNonBlockingSeek  = 0;
    }
    /* Initializing global variable g_b2ndRunPreviewMute */
    {
         g_b2ndRunPreviewMute  = 0;
    }
    /* Initializing global variable u16APageID */
    {
         u16APageID  = 0u;
    }
    /* Initializing global variable u16CodecNum */
    {
         u16CodecNum  = 0u;
    }
    /* Initializing global variable u16Samples_channel */
    {
         u16Samples_channel  = 0u;
    }
    /* Initializing global variable u8VDPlayerInitResult */
    {
         u8VDPlayerInitResult  = 0;
    }
    /* Initializing global variable u8VDPlayerSetAudioTrackResult */
    {
         u8VDPlayerSetAudioTrackResult  = 0;
    }
    /* Initializing global variable u8VDPlayerTsSetProgramResult */
    {
         u8VDPlayerTsSetProgramResult  = 0;
    }
    /* Initializing global variable u32VDPlayerAudioSupportedFormat */
    {
         u32VDPlayerAudioSupportedFormat  = 0ul;
    }
    /* Initializing global variable _bEnableVideoOnly */
    {
         _bEnableVideoOnly  = 0;
    }
    /* Initializing global variable m_u8LastMemorySearchHit */
    {
         m_u8LastMemorySearchHit  = 0;
    }
    /* Initializing global variable m_u32VideoSyncDelayMsTime */
    {
         m_u32VideoSyncDelayMsTime  = 0ul;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable m_eVDPlayerAckFlags */
    {
         m_eVDPlayerAckFlags  = E_ACKFLG_NULL;
    }
    /* Initializing global variable bDrmRegCode */
    {
         bDrmRegCode  = 0;
    }
    /* Initializing global variable enVDPlayerVideoType */
    {
         enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable _bEnableSeamlessPlaying */
    {
         _bEnableSeamlessPlaying  = 0;
    }
    /* Initializing global variable u32VdplayerShareMemAddr */
    {
         u32VdplayerShareMemAddr  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_VDPlayer_Init(_eInSrcType, _eType, _pFileEntry);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VDPlayer_Init_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VDPlayer_Init_Abort_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_VDPlayer_Init(VIDEO_PLAYER_INPUT_SOURCE_TYPE, VIDEO_PLAYER_PLAYING_TYPE, FileEntry *) */
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Init_Abort_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eInSrcType) */
    VIDEO_PLAYER_INPUT_SOURCE_TYPE _eInSrcType  = VIDEO_PLAYER_INPUT_SOURCE_MM;
    /* Initializing argument 2 (eType) */
    VIDEO_PLAYER_PLAYING_TYPE _eType  = VIDEO_PLAYER_PLAYING_TYPE_MPEG4;
    /* Initializing argument 3 (pFileEntry) */
    FileEntry _pFileEntry_1 ;
    FileEntry * _pFileEntry  = & _pFileEntry_1;
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable DRMinfo */
    {
         DRMinfo.u8DrmRentalStatus  = 0;
         DRMinfo.u8DrmFileFormat  = 0;
         DRMinfo.u8DrmAuthorization  = 0;
         DRMinfo.u32VDPlayerErrCode  = 0ul;
         DRMinfo.u32DrmRentalCode  = 0ul;
         DRMinfo.u32DrmRentalFile  = 0ul;
         DRMinfo.u32DrmRentalLimit  = 0ul;
         DRMinfo.u32DrmRentalUseCount  = 0ul;
    }
    /* Initializing global variable _gpfnForceStopCallBack */
    {
         _gpfnForceStopCallBack  = 0 ;
    }
    /* Initializing global variable g_WMDRMPrivateReady */
    {
         g_WMDRMPrivateReady  = 0;
    }
    /* Initializing global variable g_InputSourceType */
    {
         g_InputSourceType  = VIDEO_PLAYER_INPUT_SOURCE_MM;
    }
    /* Initializing global variable g_VideoPlayerPlayingType */
    {
         g_VideoPlayerPlayingType  = VIDEO_PLAYER_PLAYING_TYPE_MPEG4;
    }
    /* Initializing global variable _gbCoprocessorEnable */
    {
         _gbCoprocessorEnable  = 0;
    }
    /* Initializing global variable m_bEnableNewMMAudioMode */
    {
         m_bEnableNewMMAudioMode  = 0;
    }
    /* Initializing global variable m_bVDPlayerProbeHeaderOnly */
    {
         m_bVDPlayerProbeHeaderOnly  = 0;
    }
    /* Initializing global variable u32SecbufAddr */
    {
         u32SecbufAddr  = 0ul;
    }
    /* Initializing global variable u32SecbufSize */
    {
         u32SecbufSize  = 0ul;
    }
    /* Initializing global variable m_s32PreSubtitleTagIdx */
    {
         m_s32PreSubtitleTagIdx  = 0L;
    }
    /* Initializing global variable m_u32PreMovieRefreshTextTimer */
    {
         m_u32PreMovieRefreshTextTimer  = 0ul;
    }
    /* Initializing global variable bMovieAbort */
    {
         bMovieAbort  = 0;
    }
    /* Initializing global variable m_bVDPlayerPreview */
    {
         m_bVDPlayerPreview  = 0;
    }
    /* Initializing global variable m_bVDPlayerThumbnail */
    {
         m_bVDPlayerThumbnail  = 0;
    }
    /* Initializing global variable _geBMStreamMode */
    {
         _geBMStreamMode  = E_BM_STREAM_MODE_NORMAL;
    }
    /* Initializing global variable m_u8LastMemoryCheck */
    {
         m_u8LastMemoryCheck  = 0;
    }
    /* Initializing global variable bDrmAuthorization */
    {
         bDrmAuthorization  = 0;
    }
    /* Initializing global variable bDrmFileFormat */
    {
         bDrmFileFormat  = 0;
    }
    /* Initializing global variable bDrmActivationFile */
    {
         bDrmActivationFile  = 0;
    }
    /* Initializing global variable bDrmRentalStatus */
    {
         bDrmRentalStatus  = 0;
    }
    /* Initializing global variable g_bDrmRental */
    {
         g_bDrmRental  = 0;
    }
    /* Initializing global variable g_u8DrmUseLimit */
    {
         g_u8DrmUseLimit  = 0;
    }
    /* Initializing global variable g_u8DrmUseCount */
    {
         g_u8DrmUseCount  = 0;
    }
    /* Initializing global variable u8VDPlayerSetTrickModeResult */
    {
         u8VDPlayerSetTrickModeResult  = 0;
    }
    /* Initializing global variable u8VDPlayerStepPlayResult */
    {
         u8VDPlayerStepPlayResult  = 0;
    }
    /* Initializing global variable _u32SeamlessTimer */
    {
         _u32SeamlessTimer  = 0ul;
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
    /* Initializing global variable u32subtitletype */
    {
         u32subtitletype  = 0ul;
    }
    /* Initializing global variable u16CPageID */
    {
         u16CPageID  = 0u;
    }
    /* Initializing global variable m_bSuspendInternalSubtitle2Queue */
    {
         m_bSuspendInternalSubtitle2Queue  = 0;
    }
    /* Initializing global variable _bSubtitleShow_MW */
    {
         _bSubtitleShow_MW  = 0;
    }
    /* Initializing global variable _bSubtitleShow_User */
    {
         _bSubtitleShow_User  = 0;
    }
    /* Initializing global variable u8InternalST_Num */
    {
         u8InternalST_Num  = 0;
    }
    /* Initializing global variable u16SubtitleTagCnt */
    {
         u16SubtitleTagCnt  = 0u;
    }
    /* Initializing global variable u8IsSubtitleBusy */
    {
         u8IsSubtitleBusy  = 0;
    }
    /* Initializing global variable u8IssubtitleInit */
    {
         u8IssubtitleInit  = 0;
    }
    /* Initializing global variable u8IsSubtitleInitfinish */
    {
         u8IsSubtitleInitfinish  = 0;
    }
    /* Initializing global variable u16tagposition */
    {
         u16tagposition  = 0u;
    }
    /* Initializing global variable u32GetSubtitleStateBuf */
    {
         u32GetSubtitleStateBuf  = 0ul;
    }
    /* Initializing global variable g_bReplay */
    {
         g_bReplay  = 0;
    }
    /* Initializing global variable g_bUnsupportAudio */
    {
         g_bUnsupportAudio  = 0;
    }
    /* Initializing global variable u32VDPlayerLoopWdtTimer */
    {
         u32VDPlayerLoopWdtTimer  = 0ul;
    }
    /* Initializing global variable g_stDemuxer */
    {
         g_stDemuxer.u32Video_IdxSize  = 0ul;
         g_stDemuxer.u32KeyIdxPeriod  = 0ul;
         g_stDemuxer.u32AudioKeyIdxPeriod  = 0ul;
         g_stDemuxer.u32lastVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u32FirstVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u8KeyIdxSize  = 0;
         g_stDemuxer.u8AudioKeyIdxSize  = 0;
         g_stDemuxer.u8ThumbNailMode  = 0;
         g_stDemuxer.bEnableCalcByBitRate  = 0;
         g_stDemuxer.bEnableAudioHandler  = 0;
    }
    /* Initializing global variable g_bIsTSRadioOnly */
    {
         g_bIsTSRadioOnly  = 0;
    }
    /* Initializing global variable g_enVDPlayerVideoType */
    {
         g_enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable g_bForceToFB */
    {
         g_bForceToFB  = 0;
    }
    /* Initializing global variable m_eVDPlayerFlgs */
    {
         m_eVDPlayerFlgs  = E_VDPLAYER_FLG_NONE;
    }
    /* Initializing global variable _gu16PreviewX */
    {
         _gu16PreviewX  = 0u;
    }
    /* Initializing global variable _gu16PreviewY */
    {
         _gu16PreviewY  = 0u;
    }
    /* Initializing global variable _gu16PreviewWidth */
    {
         _gu16PreviewWidth  = 0u;
    }
    /* Initializing global variable _gu16PreviewHeight */
    {
         _gu16PreviewHeight  = 0u;
    }
    /* Initializing global variable m_bFLG_PREVIEW */
    {
         m_bFLG_PREVIEW  = 0;
    }
    /* Initializing global variable g_DstWin */
    {
         g_DstWin.x  = 0u;
         g_DstWin.y  = 0u;
         g_DstWin.width  = 0u;
         g_DstWin.height  = 0u;
    }
    /* Initializing global variable g_bIsResumePlay */
    {
         g_bIsResumePlay  = 0;
    }
    /* Initializing global variable _gbContinueBlockRead */
    {
         _gbContinueBlockRead  = 0;
    }
    /* Initializing global variable enVDPlayerRet */
    {
         enVDPlayerRet  = EXIT_NULL;
    }
    /* Initializing global variable g_bNonBlockingRead */
    {
         g_bNonBlockingRead  = 0;
    }
    /* Initializing global variable _bStreamSeeked */
    {
         _bStreamSeeked  = 0;
    }
    /* Initializing global variable _gu32BlockReadTimer */
    {
         _gu32BlockReadTimer  = 0ul;
    }
    /* Initializing global variable _gbEnableInternalSubtitle */
    {
         _gbEnableInternalSubtitle  = 0;
    }
    /* Initializing global variable _gu32ResidualReadSize */
    {
         _gu32ResidualReadSize  = 0ul;
    }
    /* Initializing global variable _gu32gStreamHdl */
    {
         _gu32gStreamHdl  = 0ul;
    }
    /* Initializing global variable _gu32BuffAddr */
    {
         _gu32BuffAddr  = 0ul;
    }
    /* Initializing global variable g_bNonBlockingSeek */
    {
         g_bNonBlockingSeek  = 0;
    }
    /* Initializing global variable g_b2ndRunPreviewMute */
    {
         g_b2ndRunPreviewMute  = 0;
    }
    /* Initializing global variable u16APageID */
    {
         u16APageID  = 0u;
    }
    /* Initializing global variable u16CodecNum */
    {
         u16CodecNum  = 0u;
    }
    /* Initializing global variable u16Samples_channel */
    {
         u16Samples_channel  = 0u;
    }
    /* Initializing global variable u8VDPlayerInitResult */
    {
         u8VDPlayerInitResult  = 0;
    }
    /* Initializing global variable u8VDPlayerSetAudioTrackResult */
    {
         u8VDPlayerSetAudioTrackResult  = 0;
    }
    /* Initializing global variable u8VDPlayerTsSetProgramResult */
    {
         u8VDPlayerTsSetProgramResult  = 0;
    }
    /* Initializing global variable u32VDPlayerAudioSupportedFormat */
    {
         u32VDPlayerAudioSupportedFormat  = 0ul;
    }
    /* Initializing global variable _bEnableVideoOnly */
    {
         _bEnableVideoOnly  = 0;
    }
    /* Initializing global variable m_u8LastMemorySearchHit */
    {
         m_u8LastMemorySearchHit  = 0;
    }
    /* Initializing global variable m_u32VideoSyncDelayMsTime */
    {
         m_u32VideoSyncDelayMsTime  = 0ul;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable m_eVDPlayerAckFlags */
    {
         m_eVDPlayerAckFlags  = E_ACKFLG_NULL;
    }
    /* Initializing global variable bDrmRegCode */
    {
         bDrmRegCode  = 0;
    }
    /* Initializing global variable enVDPlayerVideoType */
    {
         enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable _bEnableSeamlessPlaying */
    {
         _bEnableSeamlessPlaying  = 0;
    }
    /* Initializing global variable u32VdplayerShareMemAddr */
    {
         u32VdplayerShareMemAddr  = 0ul;
    }
    _gpfnForceStopCallBack = (pfnForceStopCallBack)(myFunc);
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_VDPlayer_Init(_eInSrcType, _eType, _pFileEntry);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VDPlayer_Init_Abort_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VDPlayer_SetAudioTrackID_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_VDPlayer_SetAudioTrackID(U8) */
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Setu8VDPlayerSetAudioTrackResult(void)
{
	U8 _return ;

	u8VDPlayerSetAudioTrackResult=1;

	_return  = u8VDPlayerSetAudioTrackResult;
	/* Post-condition check */
	CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
}

void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetAudioTrackID_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8TrackId) */
    U8 _u8TrackId  = 0;
    /* Initializing global variable m_s32PreSubtitleTagIdx */
    {
         m_s32PreSubtitleTagIdx  = 0L;
    }
    /* Initializing global variable m_u32PreMovieRefreshTextTimer */
    {
         m_u32PreMovieRefreshTextTimer  = 0ul;
    }
    /* Initializing global variable bDrmAuthorization */
    {
         bDrmAuthorization  = 0;
    }
    /* Initializing global variable bDrmFileFormat */
    {
         bDrmFileFormat  = 0;
    }
    /* Initializing global variable bDrmActivationFile */
    {
         bDrmActivationFile  = 0;
    }
    /* Initializing global variable bDrmRentalStatus */
    {
         bDrmRentalStatus  = 0;
    }
    /* Initializing global variable g_bDrmRental */
    {
         g_bDrmRental  = 0;
    }
    /* Initializing global variable g_u8DrmUseLimit */
    {
         g_u8DrmUseLimit  = 0;
    }
    /* Initializing global variable g_u8DrmUseCount */
    {
         g_u8DrmUseCount  = 0;
    }
    /* Initializing global variable u8VDPlayerSetTrickModeResult */
    {
         u8VDPlayerSetTrickModeResult  = 0;
    }
    /* Initializing global variable u8VDPlayerStepPlayResult */
    {
         u8VDPlayerStepPlayResult  = 0;
    }
    /* Initializing global variable _u32SeamlessTimer */
    {
         _u32SeamlessTimer  = 0ul;
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
    /* Initializing global variable u32subtitletype */
    {
         u32subtitletype  = 0ul;
    }
    /* Initializing global variable u16CPageID */
    {
         u16CPageID  = 0u;
    }
    /* Initializing global variable m_bSuspendInternalSubtitle2Queue */
    {
         m_bSuspendInternalSubtitle2Queue  = 0;
    }
    /* Initializing global variable _bSubtitleShow_MW */
    {
         _bSubtitleShow_MW  = 0;
    }
    /* Initializing global variable _bSubtitleShow_User */
    {
         _bSubtitleShow_User  = 0;
    }
    /* Initializing global variable u8InternalST_Num */
    {
         u8InternalST_Num  = 0;
    }
    /* Initializing global variable u16SubtitleTagCnt */
    {
         u16SubtitleTagCnt  = 0u;
    }
    /* Initializing global variable u8IsSubtitleBusy */
    {
         u8IsSubtitleBusy  = 0;
    }
    /* Initializing global variable u8IssubtitleInit */
    {
         u8IssubtitleInit  = 0;
    }
    /* Initializing global variable u8IsSubtitleInitfinish */
    {
         u8IsSubtitleInitfinish  = 0;
    }
    /* Initializing global variable u16tagposition */
    {
         u16tagposition  = 0u;
    }
    /* Initializing global variable u32GetSubtitleStateBuf */
    {
         u32GetSubtitleStateBuf  = 0ul;
    }
    /* Initializing global variable g_bReplay */
    {
         g_bReplay  = 0;
    }
    /* Initializing global variable g_bUnsupportAudio */
    {
         g_bUnsupportAudio  = 0;
    }
    /* Initializing global variable u32VDPlayerLoopWdtTimer */
    {
         u32VDPlayerLoopWdtTimer  = 0ul;
    }
    /* Initializing global variable g_stDemuxer */
    {
         g_stDemuxer.u32Video_IdxSize  = 0ul;
         g_stDemuxer.u32KeyIdxPeriod  = 0ul;
         g_stDemuxer.u32AudioKeyIdxPeriod  = 0ul;
         g_stDemuxer.u32lastVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u32FirstVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u8KeyIdxSize  = 0;
         g_stDemuxer.u8AudioKeyIdxSize  = 0;
         g_stDemuxer.u8ThumbNailMode  = 0;
         g_stDemuxer.bEnableCalcByBitRate  = 0;
         g_stDemuxer.bEnableAudioHandler  = 0;
    }
    /* Initializing global variable g_bIsTSRadioOnly */
    {
         g_bIsTSRadioOnly  = 0;
    }
    /* Initializing global variable g_enVDPlayerVideoType */
    {
         g_enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable g_bForceToFB */
    {
         g_bForceToFB  = 0;
    }
    /* Initializing global variable m_eVDPlayerFlgs */
    {
         m_eVDPlayerFlgs  = E_VDPLAYER_FLG_NONE;
    }
    /* Initializing global variable _gu16PreviewX */
    {
         _gu16PreviewX  = 0u;
    }
    /* Initializing global variable _gu16PreviewY */
    {
         _gu16PreviewY  = 0u;
    }
    /* Initializing global variable _gu16PreviewWidth */
    {
         _gu16PreviewWidth  = 0u;
    }
    /* Initializing global variable _gu16PreviewHeight */
    {
         _gu16PreviewHeight  = 0u;
    }
    /* Initializing global variable m_bFLG_PREVIEW */
    {
         m_bFLG_PREVIEW  = 0;
    }
    /* Initializing global variable g_DstWin */
    {
         g_DstWin.x  = 0u;
         g_DstWin.y  = 0u;
         g_DstWin.width  = 0u;
         g_DstWin.height  = 0u;
    }
    /* Initializing global variable _gbContinueBlockRead */
    {
         _gbContinueBlockRead  = 0;
    }
    /* Initializing global variable enVDPlayerRet */
    {
         enVDPlayerRet  = EXIT_NULL;
    }
    /* Initializing global variable g_bNonBlockingRead */
    {
         g_bNonBlockingRead  = 0;
    }
    /* Initializing global variable _bStreamSeeked */
    {
         _bStreamSeeked  = 0;
    }
    /* Initializing global variable _gu32BlockReadTimer */
    {
         _gu32BlockReadTimer  = 0ul;
    }
    /* Initializing global variable _gbEnableInternalSubtitle */
    {
         _gbEnableInternalSubtitle  = 0;
    }
    /* Initializing global variable _gu32ResidualReadSize */
    {
         _gu32ResidualReadSize  = 0ul;
    }
    /* Initializing global variable _gu32gStreamHdl */
    {
         _gu32gStreamHdl  = 0ul;
    }
    /* Initializing global variable _gu32BuffAddr */
    {
         _gu32BuffAddr  = 0ul;
    }
    /* Initializing global variable g_bNonBlockingSeek */
    {
         g_bNonBlockingSeek  = 0;
    }
    /* Initializing global variable g_b2ndRunPreviewMute */
    {
         g_b2ndRunPreviewMute  = 0;
    }
    /* Initializing global variable u16APageID */
    {
         u16APageID  = 0u;
    }
    /* Initializing global variable u16CodecNum */
    {
         u16CodecNum  = 0u;
    }
    /* Initializing global variable u16Samples_channel */
    {
         u16Samples_channel  = 0u;
    }
    /* Initializing global variable u8VDPlayerInitResult */
    {
         u8VDPlayerInitResult  = 0;
    }
    /* Initializing global variable u8VDPlayerSetAudioTrackResult */
    {
         u8VDPlayerSetAudioTrackResult  = 0;
    }
    /* Initializing global variable u8VDPlayerTsSetProgramResult */
    {
         u8VDPlayerTsSetProgramResult  = 0;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable m_eVDPlayerAckFlags */
    {
         m_eVDPlayerAckFlags  = E_ACKFLG_NULL;
    }
    /* Initializing global variable bDrmRegCode */
    {
         bDrmRegCode  = 0;
    }
    /* Initializing global variable enVDPlayerVideoType */
    {
         enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable _bEnableSeamlessPlaying */
    {
         _bEnableSeamlessPlaying  = 0;
    }
    /* Initializing global variable u32VdplayerShareMemAddr */
    {
         u32VdplayerShareMemAddr  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_VDPlayer_SetAudioTrackID(_u8TrackId);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VDPlayer_SetAudioTrackID_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VDPlayer_SetSubtitleTrackID_return_FALSE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_VDPlayer_SetSubtitleTrackID(U8) */
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetSubtitleTrackID_return_FALSE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8TrackId) */
    U8 _u8TrackId  = 0;
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable _gbCoprocessorEnable */
    {
         _gbCoprocessorEnable  = 0;
    }
    /* Initializing global variable m_s32PreSubtitleTagIdx */
    {
         m_s32PreSubtitleTagIdx  = 0L;
    }
    /* Initializing global variable m_u32PreMovieRefreshTextTimer */
    {
         m_u32PreMovieRefreshTextTimer  = 0ul;
    }
    /* Initializing global variable bMovieAbort */
    {
         bMovieAbort  = 0;
    }
    /* Initializing global variable m_bVDPlayerPreview */
    {
         m_bVDPlayerPreview  = 0;
    }
    /* Initializing global variable m_bVDPlayerThumbnail */
    {
         m_bVDPlayerThumbnail  = 0;
    }
    /* Initializing global variable _geBMStreamMode */
    {
         _geBMStreamMode  = E_BM_STREAM_MODE_NORMAL;
    }
    /* Initializing global variable m_u8LastMemoryCheck */
    {
         m_u8LastMemoryCheck  = 0;
    }
    /* Initializing global variable bDrmAuthorization */
    {
         bDrmAuthorization  = 0;
    }
    /* Initializing global variable bDrmFileFormat */
    {
         bDrmFileFormat  = 0;
    }
    /* Initializing global variable bDrmActivationFile */
    {
         bDrmActivationFile  = 0;
    }
    /* Initializing global variable bDrmRentalStatus */
    {
         bDrmRentalStatus  = 0;
    }
    /* Initializing global variable g_bDrmRental */
    {
         g_bDrmRental  = 0;
    }
    /* Initializing global variable g_u8DrmUseLimit */
    {
         g_u8DrmUseLimit  = 0;
    }
    /* Initializing global variable g_u8DrmUseCount */
    {
         g_u8DrmUseCount  = 0;
    }
    /* Initializing global variable u8VDPlayerSetTrickModeResult */
    {
         u8VDPlayerSetTrickModeResult  = 0;
    }
    /* Initializing global variable u8VDPlayerStepPlayResult */
    {
         u8VDPlayerStepPlayResult  = 0;
    }
    /* Initializing global variable _u32SeamlessTimer */
    {
         _u32SeamlessTimer  = 0ul;
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
    /* Initializing global variable u32subtitletype */
    {
         u32subtitletype  = 0ul;
    }
    /* Initializing global variable u16CPageID */
    {
         u16CPageID  = 0u;
    }
    /* Initializing global variable m_bSuspendInternalSubtitle2Queue */
    {
         m_bSuspendInternalSubtitle2Queue  = 0;
    }
    /* Initializing global variable _bSubtitleShow_MW */
    {
         _bSubtitleShow_MW  = 0;
    }
    /* Initializing global variable _bSubtitleShow_User */
    {
         _bSubtitleShow_User  = 0;
    }
    /* Initializing global variable u8InternalST_Num */
    {
         u8InternalST_Num  = 0;
    }
    /* Initializing global variable u16SubtitleTagCnt */
    {
         u16SubtitleTagCnt  = 0u;
    }
    /* Initializing global variable u8IsSubtitleBusy */
    {
         u8IsSubtitleBusy  = 0;
    }
    /* Initializing global variable u8IssubtitleInit */
    {
         u8IssubtitleInit  = 0;
    }
    /* Initializing global variable u8IsSubtitleInitfinish */
    {
         u8IsSubtitleInitfinish  = 0;
    }
    /* Initializing global variable u16tagposition */
    {
         u16tagposition  = 0u;
    }
    /* Initializing global variable u32GetSubtitleStateBuf */
    {
         u32GetSubtitleStateBuf  = 0ul;
    }
    /* Initializing global variable g_bReplay */
    {
         g_bReplay  = 0;
    }
    /* Initializing global variable g_bUnsupportAudio */
    {
         g_bUnsupportAudio  = 0;
    }
    /* Initializing global variable u32VDPlayerLoopWdtTimer */
    {
         u32VDPlayerLoopWdtTimer  = 0ul;
    }
    /* Initializing global variable g_stDemuxer */
    {
         g_stDemuxer.u32Video_IdxSize  = 0ul;
         g_stDemuxer.u32KeyIdxPeriod  = 0ul;
         g_stDemuxer.u32AudioKeyIdxPeriod  = 0ul;
         g_stDemuxer.u32lastVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u32FirstVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u8KeyIdxSize  = 0;
         g_stDemuxer.u8AudioKeyIdxSize  = 0;
         g_stDemuxer.u8ThumbNailMode  = 0;
         g_stDemuxer.bEnableCalcByBitRate  = 0;
         g_stDemuxer.bEnableAudioHandler  = 0;
    }
    /* Initializing global variable g_bIsTSRadioOnly */
    {
         g_bIsTSRadioOnly  = 0;
    }
    /* Initializing global variable g_enVDPlayerVideoType */
    {
         g_enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable g_bForceToFB */
    {
         g_bForceToFB  = 0;
    }
    /* Initializing global variable m_eVDPlayerFlgs */
    {
         m_eVDPlayerFlgs  = E_VDPLAYER_FLG_NONE;
    }
    /* Initializing global variable _gu16PreviewX */
    {
         _gu16PreviewX  = 0u;
    }
    /* Initializing global variable _gu16PreviewY */
    {
         _gu16PreviewY  = 0u;
    }
    /* Initializing global variable _gu16PreviewWidth */
    {
         _gu16PreviewWidth  = 0u;
    }
    /* Initializing global variable _gu16PreviewHeight */
    {
         _gu16PreviewHeight  = 0u;
    }
    /* Initializing global variable m_bFLG_PREVIEW */
    {
         m_bFLG_PREVIEW  = 0;
    }
    /* Initializing global variable g_DstWin */
    {
         g_DstWin.x  = 0u;
         g_DstWin.y  = 0u;
         g_DstWin.width  = 0u;
         g_DstWin.height  = 0u;
    }
    /* Initializing global variable _gbContinueBlockRead */
    {
         _gbContinueBlockRead  = 0;
    }
    /* Initializing global variable enVDPlayerRet */
    {
         enVDPlayerRet  = EXIT_NULL;
    }
    /* Initializing global variable g_bNonBlockingRead */
    {
         g_bNonBlockingRead  = 0;
    }
    /* Initializing global variable _bStreamSeeked */
    {
         _bStreamSeeked  = 0;
    }
    /* Initializing global variable _gu32BlockReadTimer */
    {
         _gu32BlockReadTimer  = 0ul;
    }
    /* Initializing global variable _gbEnableInternalSubtitle */
    {
         _gbEnableInternalSubtitle  = 0;
    }
    /* Initializing global variable _gu32ResidualReadSize */
    {
         _gu32ResidualReadSize  = 0ul;
    }
    /* Initializing global variable _gu32gStreamHdl */
    {
         _gu32gStreamHdl  = 0ul;
    }
    /* Initializing global variable _gu32BuffAddr */
    {
         _gu32BuffAddr  = 0ul;
    }
    /* Initializing global variable g_bNonBlockingSeek */
    {
         g_bNonBlockingSeek  = 0;
    }
    /* Initializing global variable g_b2ndRunPreviewMute */
    {
         g_b2ndRunPreviewMute  = 0;
    }
    /* Initializing global variable u16APageID */
    {
         u16APageID  = 0u;
    }
    /* Initializing global variable u16CodecNum */
    {
         u16CodecNum  = 0u;
    }
    /* Initializing global variable u16Samples_channel */
    {
         u16Samples_channel  = 0u;
    }
    /* Initializing global variable u8VDPlayerInitResult */
    {
         u8VDPlayerInitResult  = 0;
    }
    /* Initializing global variable u8VDPlayerSetAudioTrackResult */
    {
         u8VDPlayerSetAudioTrackResult  = 0;
    }
    /* Initializing global variable u8VDPlayerTsSetProgramResult */
    {
         u8VDPlayerTsSetProgramResult  = 0;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable m_eVDPlayerAckFlags */
    {
         m_eVDPlayerAckFlags  = E_ACKFLG_NULL;
    }
    /* Initializing global variable bDrmRegCode */
    {
         bDrmRegCode  = 0;
    }
    /* Initializing global variable enVDPlayerVideoType */
    {
         enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable _bEnableSeamlessPlaying */
    {
         _bEnableSeamlessPlaying  = 0;
    }
    /* Initializing global variable u32VdplayerShareMemAddr */
    {
         u32VdplayerShareMemAddr  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_VDPlayer_SetSubtitleTrackID(_u8TrackId);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VDPlayer_SetSubtitleTrackID_return_FALSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VDPlayer_SetStep_return_FALSE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_VDPlayer_SetStep(void) */
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetStep_return_FALSE()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_s32PreSubtitleTagIdx */
    {
         m_s32PreSubtitleTagIdx  = 0L;
    }
    /* Initializing global variable m_u32PreMovieRefreshTextTimer */
    {
         m_u32PreMovieRefreshTextTimer  = 0ul;
    }
    /* Initializing global variable bDrmAuthorization */
    {
         bDrmAuthorization  = 0;
    }
    /* Initializing global variable bDrmFileFormat */
    {
         bDrmFileFormat  = 0;
    }
    /* Initializing global variable bDrmActivationFile */
    {
         bDrmActivationFile  = 0;
    }
    /* Initializing global variable bDrmRentalStatus */
    {
         bDrmRentalStatus  = 0;
    }
    /* Initializing global variable g_bDrmRental */
    {
         g_bDrmRental  = 0;
    }
    /* Initializing global variable g_u8DrmUseLimit */
    {
         g_u8DrmUseLimit  = 0;
    }
    /* Initializing global variable g_u8DrmUseCount */
    {
         g_u8DrmUseCount  = 0;
    }
    /* Initializing global variable u8VDPlayerSetTrickModeResult */
    {
         u8VDPlayerSetTrickModeResult  = 0;
    }
    /* Initializing global variable u8VDPlayerStepPlayResult */
    {
         u8VDPlayerStepPlayResult  = 0;
    }
    /* Initializing global variable _u32SeamlessTimer */
    {
         _u32SeamlessTimer  = 0ul;
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
    /* Initializing global variable u32subtitletype */
    {
         u32subtitletype  = 0ul;
    }
    /* Initializing global variable u16CPageID */
    {
         u16CPageID  = 0u;
    }
    /* Initializing global variable m_bSuspendInternalSubtitle2Queue */
    {
         m_bSuspendInternalSubtitle2Queue  = 0;
    }
    /* Initializing global variable _bSubtitleShow_MW */
    {
         _bSubtitleShow_MW  = 0;
    }
    /* Initializing global variable _bSubtitleShow_User */
    {
         _bSubtitleShow_User  = 0;
    }
    /* Initializing global variable u8InternalST_Num */
    {
         u8InternalST_Num  = 0;
    }
    /* Initializing global variable u16SubtitleTagCnt */
    {
         u16SubtitleTagCnt  = 0u;
    }
    /* Initializing global variable u8IsSubtitleBusy */
    {
         u8IsSubtitleBusy  = 0;
    }
    /* Initializing global variable u8IssubtitleInit */
    {
         u8IssubtitleInit  = 0;
    }
    /* Initializing global variable u8IsSubtitleInitfinish */
    {
         u8IsSubtitleInitfinish  = 0;
    }
    /* Initializing global variable u16tagposition */
    {
         u16tagposition  = 0u;
    }
    /* Initializing global variable u32GetSubtitleStateBuf */
    {
         u32GetSubtitleStateBuf  = 0ul;
    }
    /* Initializing global variable g_bReplay */
    {
         g_bReplay  = 0;
    }
    /* Initializing global variable g_bUnsupportAudio */
    {
         g_bUnsupportAudio  = 0;
    }
    /* Initializing global variable u32VDPlayerLoopWdtTimer */
    {
         u32VDPlayerLoopWdtTimer  = 0ul;
    }
    /* Initializing global variable g_stDemuxer */
    {
         g_stDemuxer.u32Video_IdxSize  = 0ul;
         g_stDemuxer.u32KeyIdxPeriod  = 0ul;
         g_stDemuxer.u32AudioKeyIdxPeriod  = 0ul;
         g_stDemuxer.u32lastVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u32FirstVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u8KeyIdxSize  = 0;
         g_stDemuxer.u8AudioKeyIdxSize  = 0;
         g_stDemuxer.u8ThumbNailMode  = 0;
         g_stDemuxer.bEnableCalcByBitRate  = 0;
         g_stDemuxer.bEnableAudioHandler  = 0;
    }
    /* Initializing global variable g_bIsTSRadioOnly */
    {
         g_bIsTSRadioOnly  = 0;
    }
    /* Initializing global variable g_enVDPlayerVideoType */
    {
         g_enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable g_bForceToFB */
    {
         g_bForceToFB  = 0;
    }
    /* Initializing global variable m_eVDPlayerFlgs */
    {
         m_eVDPlayerFlgs  = E_VDPLAYER_FLG_NONE;
    }
    /* Initializing global variable _gu16PreviewX */
    {
         _gu16PreviewX  = 0u;
    }
    /* Initializing global variable _gu16PreviewY */
    {
         _gu16PreviewY  = 0u;
    }
    /* Initializing global variable _gu16PreviewWidth */
    {
         _gu16PreviewWidth  = 0u;
    }
    /* Initializing global variable _gu16PreviewHeight */
    {
         _gu16PreviewHeight  = 0u;
    }
    /* Initializing global variable m_bFLG_PREVIEW */
    {
         m_bFLG_PREVIEW  = 0;
    }
    /* Initializing global variable g_DstWin */
    {
         g_DstWin.x  = 0u;
         g_DstWin.y  = 0u;
         g_DstWin.width  = 0u;
         g_DstWin.height  = 0u;
    }
    /* Initializing global variable _gbContinueBlockRead */
    {
         _gbContinueBlockRead  = 0;
    }
    /* Initializing global variable enVDPlayerRet */
    {
         enVDPlayerRet  = EXIT_NULL;
    }
    /* Initializing global variable g_bNonBlockingRead */
    {
         g_bNonBlockingRead  = 0;
    }
    /* Initializing global variable _bStreamSeeked */
    {
         _bStreamSeeked  = 0;
    }
    /* Initializing global variable _gu32BlockReadTimer */
    {
         _gu32BlockReadTimer  = 0ul;
    }
    /* Initializing global variable _gbEnableInternalSubtitle */
    {
         _gbEnableInternalSubtitle  = 0;
    }
    /* Initializing global variable _gu32ResidualReadSize */
    {
         _gu32ResidualReadSize  = 0ul;
    }
    /* Initializing global variable _gu32gStreamHdl */
    {
         _gu32gStreamHdl  = 0ul;
    }
    /* Initializing global variable _gu32BuffAddr */
    {
         _gu32BuffAddr  = 0ul;
    }
    /* Initializing global variable g_bNonBlockingSeek */
    {
         g_bNonBlockingSeek  = 0;
    }
    /* Initializing global variable g_b2ndRunPreviewMute */
    {
         g_b2ndRunPreviewMute  = 0;
    }
    /* Initializing global variable u16APageID */
    {
         u16APageID  = 0u;
    }
    /* Initializing global variable u16CodecNum */
    {
         u16CodecNum  = 0u;
    }
    /* Initializing global variable u16Samples_channel */
    {
         u16Samples_channel  = 0u;
    }
    /* Initializing global variable u8VDPlayerInitResult */
    {
         u8VDPlayerInitResult  = 0;
    }
    /* Initializing global variable u8VDPlayerSetAudioTrackResult */
    {
         u8VDPlayerSetAudioTrackResult  = 0;
    }
    /* Initializing global variable u8VDPlayerTsSetProgramResult */
    {
         u8VDPlayerTsSetProgramResult  = 0;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable m_eVDPlayerAckFlags */
    {
         m_eVDPlayerAckFlags  = E_ACKFLG_NULL;
    }
    /* Initializing global variable bDrmRegCode */
    {
         bDrmRegCode  = 0;
    }
    /* Initializing global variable enVDPlayerVideoType */
    {
         enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable _bEnableSeamlessPlaying */
    {
         _bEnableSeamlessPlaying  = 0;
    }
    /* Initializing global variable u32VdplayerShareMemAddr */
    {
         u32VdplayerShareMemAddr  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_VDPlayer_SetStep();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VDPlayer_SetStep_return_FALSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VDPlayer_SetStep_return_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_VDPlayer_SetStep(void) */
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Setu8VDPlayerStepPlayResult(void)
{
	U8 _return ;

	u8VDPlayerStepPlayResult=1;

	_return  = u8VDPlayerStepPlayResult;
	/* Post-condition check */
	CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
}
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetStep_return_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_s32PreSubtitleTagIdx */
    {
         m_s32PreSubtitleTagIdx  = 0L;
    }
    /* Initializing global variable m_u32PreMovieRefreshTextTimer */
    {
         m_u32PreMovieRefreshTextTimer  = 0ul;
    }
    /* Initializing global variable bDrmAuthorization */
    {
         bDrmAuthorization  = 0;
    }
    /* Initializing global variable bDrmFileFormat */
    {
         bDrmFileFormat  = 0;
    }
    /* Initializing global variable bDrmActivationFile */
    {
         bDrmActivationFile  = 0;
    }
    /* Initializing global variable bDrmRentalStatus */
    {
         bDrmRentalStatus  = 0;
    }
    /* Initializing global variable g_bDrmRental */
    {
         g_bDrmRental  = 0;
    }
    /* Initializing global variable g_u8DrmUseLimit */
    {
         g_u8DrmUseLimit  = 0;
    }
    /* Initializing global variable g_u8DrmUseCount */
    {
         g_u8DrmUseCount  = 0;
    }
    /* Initializing global variable u8VDPlayerSetTrickModeResult */
    {
         u8VDPlayerSetTrickModeResult  = 0;
    }
    /* Initializing global variable u8VDPlayerStepPlayResult */
    {
         u8VDPlayerStepPlayResult  = 0;
    }
    /* Initializing global variable _u32SeamlessTimer */
    {
         _u32SeamlessTimer  = 0ul;
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
    /* Initializing global variable u32subtitletype */
    {
         u32subtitletype  = 0ul;
    }
    /* Initializing global variable u16CPageID */
    {
         u16CPageID  = 0u;
    }
    /* Initializing global variable m_bSuspendInternalSubtitle2Queue */
    {
         m_bSuspendInternalSubtitle2Queue  = 0;
    }
    /* Initializing global variable _bSubtitleShow_MW */
    {
         _bSubtitleShow_MW  = 0;
    }
    /* Initializing global variable _bSubtitleShow_User */
    {
         _bSubtitleShow_User  = 0;
    }
    /* Initializing global variable u8InternalST_Num */
    {
         u8InternalST_Num  = 0;
    }
    /* Initializing global variable u16SubtitleTagCnt */
    {
         u16SubtitleTagCnt  = 0u;
    }
    /* Initializing global variable u8IsSubtitleBusy */
    {
         u8IsSubtitleBusy  = 0;
    }
    /* Initializing global variable u8IssubtitleInit */
    {
         u8IssubtitleInit  = 0;
    }
    /* Initializing global variable u8IsSubtitleInitfinish */
    {
         u8IsSubtitleInitfinish  = 0;
    }
    /* Initializing global variable u16tagposition */
    {
         u16tagposition  = 0u;
    }
    /* Initializing global variable u32GetSubtitleStateBuf */
    {
         u32GetSubtitleStateBuf  = 0ul;
    }
    /* Initializing global variable g_bReplay */
    {
         g_bReplay  = 0;
    }
    /* Initializing global variable g_bUnsupportAudio */
    {
         g_bUnsupportAudio  = 0;
    }
    /* Initializing global variable u32VDPlayerLoopWdtTimer */
    {
         u32VDPlayerLoopWdtTimer  = 0ul;
    }
    /* Initializing global variable g_stDemuxer */
    {
         g_stDemuxer.u32Video_IdxSize  = 0ul;
         g_stDemuxer.u32KeyIdxPeriod  = 0ul;
         g_stDemuxer.u32AudioKeyIdxPeriod  = 0ul;
         g_stDemuxer.u32lastVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u32FirstVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u8KeyIdxSize  = 0;
         g_stDemuxer.u8AudioKeyIdxSize  = 0;
         g_stDemuxer.u8ThumbNailMode  = 0;
         g_stDemuxer.bEnableCalcByBitRate  = 0;
         g_stDemuxer.bEnableAudioHandler  = 0;
    }
    /* Initializing global variable g_bIsTSRadioOnly */
    {
         g_bIsTSRadioOnly  = 0;
    }
    /* Initializing global variable g_enVDPlayerVideoType */
    {
         g_enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable g_bForceToFB */
    {
         g_bForceToFB  = 0;
    }
    /* Initializing global variable m_eVDPlayerFlgs */
    {
         m_eVDPlayerFlgs  = E_VDPLAYER_FLG_NONE;
    }
    /* Initializing global variable _gu16PreviewX */
    {
         _gu16PreviewX  = 0u;
    }
    /* Initializing global variable _gu16PreviewY */
    {
         _gu16PreviewY  = 0u;
    }
    /* Initializing global variable _gu16PreviewWidth */
    {
         _gu16PreviewWidth  = 0u;
    }
    /* Initializing global variable _gu16PreviewHeight */
    {
         _gu16PreviewHeight  = 0u;
    }
    /* Initializing global variable m_bFLG_PREVIEW */
    {
         m_bFLG_PREVIEW  = 0;
    }
    /* Initializing global variable g_DstWin */
    {
         g_DstWin.x  = 0u;
         g_DstWin.y  = 0u;
         g_DstWin.width  = 0u;
         g_DstWin.height  = 0u;
    }
    /* Initializing global variable _gbContinueBlockRead */
    {
         _gbContinueBlockRead  = 0;
    }
    /* Initializing global variable enVDPlayerRet */
    {
         enVDPlayerRet  = EXIT_NULL;
    }
    /* Initializing global variable g_bNonBlockingRead */
    {
         g_bNonBlockingRead  = 0;
    }
    /* Initializing global variable _bStreamSeeked */
    {
         _bStreamSeeked  = 0;
    }
    /* Initializing global variable _gu32BlockReadTimer */
    {
         _gu32BlockReadTimer  = 0ul;
    }
    /* Initializing global variable _gbEnableInternalSubtitle */
    {
         _gbEnableInternalSubtitle  = 0;
    }
    /* Initializing global variable _gu32ResidualReadSize */
    {
         _gu32ResidualReadSize  = 0ul;
    }
    /* Initializing global variable _gu32gStreamHdl */
    {
         _gu32gStreamHdl  = 0ul;
    }
    /* Initializing global variable _gu32BuffAddr */
    {
         _gu32BuffAddr  = 0ul;
    }
    /* Initializing global variable g_bNonBlockingSeek */
    {
         g_bNonBlockingSeek  = 0;
    }
    /* Initializing global variable g_b2ndRunPreviewMute */
    {
         g_b2ndRunPreviewMute  = 0;
    }
    /* Initializing global variable u16APageID */
    {
         u16APageID  = 0u;
    }
    /* Initializing global variable u16CodecNum */
    {
         u16CodecNum  = 0u;
    }
    /* Initializing global variable u16Samples_channel */
    {
         u16Samples_channel  = 0u;
    }
    /* Initializing global variable u8VDPlayerInitResult */
    {
         u8VDPlayerInitResult  = 0;
    }
    /* Initializing global variable u8VDPlayerSetAudioTrackResult */
    {
         u8VDPlayerSetAudioTrackResult  = 0;
    }
    /* Initializing global variable u8VDPlayerTsSetProgramResult */
    {
         u8VDPlayerTsSetProgramResult  = 0;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable m_eVDPlayerAckFlags */
    {
         m_eVDPlayerAckFlags  = E_ACKFLG_NULL;
    }
    /* Initializing global variable bDrmRegCode */
    {
         bDrmRegCode  = 0;
    }
    /* Initializing global variable enVDPlayerVideoType */
    {
         enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable _bEnableSeamlessPlaying */
    {
         _bEnableSeamlessPlaying  = 0;
    }
    /* Initializing global variable u32VdplayerShareMemAddr */
    {
         u32VdplayerShareMemAddr  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_VDPlayer_SetStep();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VDPlayer_SetStep_return_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VDPlayer_SetRepeatAB_return_FALSE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_VDPlayer_SetRepeatAB(EN_SET_REPEATAB) */
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetRepeatAB_return_FALSE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enAction) */
    EN_SET_REPEATAB _enAction  = SET_REPEAT_AB_NONE;
    /* Initializing global variable m_s32PreSubtitleTagIdx */
    {
         m_s32PreSubtitleTagIdx  = 0L;
    }
    /* Initializing global variable m_u32PreMovieRefreshTextTimer */
    {
         m_u32PreMovieRefreshTextTimer  = 0ul;
    }
    /* Initializing global variable bDrmAuthorization */
    {
         bDrmAuthorization  = 0;
    }
    /* Initializing global variable bDrmFileFormat */
    {
         bDrmFileFormat  = 0;
    }
    /* Initializing global variable bDrmActivationFile */
    {
         bDrmActivationFile  = 0;
    }
    /* Initializing global variable bDrmRentalStatus */
    {
         bDrmRentalStatus  = 0;
    }
    /* Initializing global variable g_bDrmRental */
    {
         g_bDrmRental  = 0;
    }
    /* Initializing global variable g_u8DrmUseLimit */
    {
         g_u8DrmUseLimit  = 0;
    }
    /* Initializing global variable g_u8DrmUseCount */
    {
         g_u8DrmUseCount  = 0;
    }
    /* Initializing global variable u8VDPlayerSetTrickModeResult */
    {
         u8VDPlayerSetTrickModeResult  = 0;
    }
    /* Initializing global variable u8VDPlayerStepPlayResult */
    {
         u8VDPlayerStepPlayResult  = 0;
    }
    /* Initializing global variable _u32SeamlessTimer */
    {
         _u32SeamlessTimer  = 0ul;
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
    /* Initializing global variable u32subtitletype */
    {
         u32subtitletype  = 0ul;
    }
    /* Initializing global variable u16CPageID */
    {
         u16CPageID  = 0u;
    }
    /* Initializing global variable m_bSuspendInternalSubtitle2Queue */
    {
         m_bSuspendInternalSubtitle2Queue  = 0;
    }
    /* Initializing global variable _bSubtitleShow_MW */
    {
         _bSubtitleShow_MW  = 0;
    }
    /* Initializing global variable _bSubtitleShow_User */
    {
         _bSubtitleShow_User  = 0;
    }
    /* Initializing global variable u8InternalST_Num */
    {
         u8InternalST_Num  = 0;
    }
    /* Initializing global variable u16SubtitleTagCnt */
    {
         u16SubtitleTagCnt  = 0u;
    }
    /* Initializing global variable u8IsSubtitleBusy */
    {
         u8IsSubtitleBusy  = 0;
    }
    /* Initializing global variable u8IssubtitleInit */
    {
         u8IssubtitleInit  = 0;
    }
    /* Initializing global variable u8IsSubtitleInitfinish */
    {
         u8IsSubtitleInitfinish  = 0;
    }
    /* Initializing global variable u16tagposition */
    {
         u16tagposition  = 0u;
    }
    /* Initializing global variable u32GetSubtitleStateBuf */
    {
         u32GetSubtitleStateBuf  = 0ul;
    }
    /* Initializing global variable g_bReplay */
    {
         g_bReplay  = 0;
    }
    /* Initializing global variable g_bUnsupportAudio */
    {
         g_bUnsupportAudio  = 0;
    }
    /* Initializing global variable u32VDPlayerLoopWdtTimer */
    {
         u32VDPlayerLoopWdtTimer  = 0ul;
    }
    /* Initializing global variable g_stDemuxer */
    {
         g_stDemuxer.u32Video_IdxSize  = 0ul;
         g_stDemuxer.u32KeyIdxPeriod  = 0ul;
         g_stDemuxer.u32AudioKeyIdxPeriod  = 0ul;
         g_stDemuxer.u32lastVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u32FirstVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u8KeyIdxSize  = 0;
         g_stDemuxer.u8AudioKeyIdxSize  = 0;
         g_stDemuxer.u8ThumbNailMode  = 0;
         g_stDemuxer.bEnableCalcByBitRate  = 0;
         g_stDemuxer.bEnableAudioHandler  = 0;
    }
    /* Initializing global variable g_bIsTSRadioOnly */
    {
         g_bIsTSRadioOnly  = 0;
    }
    /* Initializing global variable g_enVDPlayerVideoType */
    {
         g_enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable g_bForceToFB */
    {
         g_bForceToFB  = 0;
    }
    /* Initializing global variable m_eVDPlayerFlgs */
    {
         m_eVDPlayerFlgs  = E_VDPLAYER_FLG_NONE;
    }
    /* Initializing global variable _gu16PreviewX */
    {
         _gu16PreviewX  = 0u;
    }
    /* Initializing global variable _gu16PreviewY */
    {
         _gu16PreviewY  = 0u;
    }
    /* Initializing global variable _gu16PreviewWidth */
    {
         _gu16PreviewWidth  = 0u;
    }
    /* Initializing global variable _gu16PreviewHeight */
    {
         _gu16PreviewHeight  = 0u;
    }
    /* Initializing global variable m_bFLG_PREVIEW */
    {
         m_bFLG_PREVIEW  = 0;
    }
    /* Initializing global variable g_DstWin */
    {
         g_DstWin.x  = 0u;
         g_DstWin.y  = 0u;
         g_DstWin.width  = 0u;
         g_DstWin.height  = 0u;
    }
    /* Initializing global variable _gbContinueBlockRead */
    {
         _gbContinueBlockRead  = 0;
    }
    /* Initializing global variable enVDPlayerRet */
    {
         enVDPlayerRet  = EXIT_VDPLAYER_EXIT;
    }
    /* Initializing global variable g_bNonBlockingRead */
    {
         g_bNonBlockingRead  = 0;
    }
    /* Initializing global variable _bStreamSeeked */
    {
         _bStreamSeeked  = 0;
    }
    /* Initializing global variable _gu32BlockReadTimer */
    {
         _gu32BlockReadTimer  = 0ul;
    }
    /* Initializing global variable _gbEnableInternalSubtitle */
    {
         _gbEnableInternalSubtitle  = 0;
    }
    /* Initializing global variable _gu32ResidualReadSize */
    {
         _gu32ResidualReadSize  = 0ul;
    }
    /* Initializing global variable _gu32gStreamHdl */
    {
         _gu32gStreamHdl  = 0ul;
    }
    /* Initializing global variable _gu32BuffAddr */
    {
         _gu32BuffAddr  = 0ul;
    }
    /* Initializing global variable g_bNonBlockingSeek */
    {
         g_bNonBlockingSeek  = 0;
    }
    /* Initializing global variable g_b2ndRunPreviewMute */
    {
         g_b2ndRunPreviewMute  = 0;
    }
    /* Initializing global variable u16APageID */
    {
         u16APageID  = 0u;
    }
    /* Initializing global variable u16CodecNum */
    {
         u16CodecNum  = 0u;
    }
    /* Initializing global variable u16Samples_channel */
    {
         u16Samples_channel  = 0u;
    }
    /* Initializing global variable u8VDPlayerInitResult */
    {
         u8VDPlayerInitResult  = 0;
    }
    /* Initializing global variable u8VDPlayerSetAudioTrackResult */
    {
         u8VDPlayerSetAudioTrackResult  = 0;
    }
    /* Initializing global variable u8VDPlayerTsSetProgramResult */
    {
         u8VDPlayerTsSetProgramResult  = 0;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable m_eVDPlayerAckFlags */
    {
         m_eVDPlayerAckFlags  = E_ACKFLG_NULL;
    }
    /* Initializing global variable bDrmRegCode */
    {
         bDrmRegCode  = 0;
    }
    /* Initializing global variable enVDPlayerVideoType */
    {
         enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable _bEnableSeamlessPlaying */
    {
         _bEnableSeamlessPlaying  = 0;
    }
    /* Initializing global variable u32VdplayerShareMemAddr */
    {
         u32VdplayerShareMemAddr  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_VDPlayer_SetRepeatAB(_enAction);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VDPlayer_SetRepeatAB_return_FALSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VDPlayer_SetRepeatAB_return_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_VDPlayer_SetRepeatAB(EN_SET_REPEATAB) */
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetRepeatAB_return_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enAction) */
    EN_SET_REPEATAB _enAction  = SET_REPEAT_AB_NONE;
    /* Initializing global variable m_s32PreSubtitleTagIdx */
    {
         m_s32PreSubtitleTagIdx  = 0L;
    }
    /* Initializing global variable m_u32PreMovieRefreshTextTimer */
    {
         m_u32PreMovieRefreshTextTimer  = 0ul;
    }
    /* Initializing global variable bDrmAuthorization */
    {
         bDrmAuthorization  = 0;
    }
    /* Initializing global variable bDrmFileFormat */
    {
         bDrmFileFormat  = 0;
    }
    /* Initializing global variable bDrmActivationFile */
    {
         bDrmActivationFile  = 0;
    }
    /* Initializing global variable bDrmRentalStatus */
    {
         bDrmRentalStatus  = 0;
    }
    /* Initializing global variable g_bDrmRental */
    {
         g_bDrmRental  = 0;
    }
    /* Initializing global variable g_u8DrmUseLimit */
    {
         g_u8DrmUseLimit  = 0;
    }
    /* Initializing global variable g_u8DrmUseCount */
    {
         g_u8DrmUseCount  = 0;
    }
    /* Initializing global variable u8VDPlayerSetTrickModeResult */
    {
         u8VDPlayerSetTrickModeResult  = 0;
    }
    /* Initializing global variable u8VDPlayerStepPlayResult */
    {
         u8VDPlayerStepPlayResult  = 0;
    }
    /* Initializing global variable _u32SeamlessTimer */
    {
         _u32SeamlessTimer  = 0ul;
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
    /* Initializing global variable u32subtitletype */
    {
         u32subtitletype  = 0ul;
    }
    /* Initializing global variable u16CPageID */
    {
         u16CPageID  = 0u;
    }
    /* Initializing global variable m_bSuspendInternalSubtitle2Queue */
    {
         m_bSuspendInternalSubtitle2Queue  = 0;
    }
    /* Initializing global variable _bSubtitleShow_MW */
    {
         _bSubtitleShow_MW  = 0;
    }
    /* Initializing global variable _bSubtitleShow_User */
    {
         _bSubtitleShow_User  = 0;
    }
    /* Initializing global variable u8InternalST_Num */
    {
         u8InternalST_Num  = 0;
    }
    /* Initializing global variable u16SubtitleTagCnt */
    {
         u16SubtitleTagCnt  = 0u;
    }
    /* Initializing global variable u8IsSubtitleBusy */
    {
         u8IsSubtitleBusy  = 0;
    }
    /* Initializing global variable u8IssubtitleInit */
    {
         u8IssubtitleInit  = 0;
    }
    /* Initializing global variable u8IsSubtitleInitfinish */
    {
         u8IsSubtitleInitfinish  = 0;
    }
    /* Initializing global variable u16tagposition */
    {
         u16tagposition  = 0u;
    }
    /* Initializing global variable u32GetSubtitleStateBuf */
    {
         u32GetSubtitleStateBuf  = 0ul;
    }
    /* Initializing global variable g_bReplay */
    {
         g_bReplay  = 0;
    }
    /* Initializing global variable g_bUnsupportAudio */
    {
         g_bUnsupportAudio  = 0;
    }
    /* Initializing global variable u32VDPlayerLoopWdtTimer */
    {
         u32VDPlayerLoopWdtTimer  = 0ul;
    }
    /* Initializing global variable g_stDemuxer */
    {
         g_stDemuxer.u32Video_IdxSize  = 0ul;
         g_stDemuxer.u32KeyIdxPeriod  = 0ul;
         g_stDemuxer.u32AudioKeyIdxPeriod  = 0ul;
         g_stDemuxer.u32lastVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u32FirstVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u8KeyIdxSize  = 0;
         g_stDemuxer.u8AudioKeyIdxSize  = 0;
         g_stDemuxer.u8ThumbNailMode  = 0;
         g_stDemuxer.bEnableCalcByBitRate  = 0;
         g_stDemuxer.bEnableAudioHandler  = 0;
    }
    /* Initializing global variable g_bIsTSRadioOnly */
    {
         g_bIsTSRadioOnly  = 0;
    }
    /* Initializing global variable g_enVDPlayerVideoType */
    {
         g_enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable g_bForceToFB */
    {
         g_bForceToFB  = 0;
    }
    /* Initializing global variable m_eVDPlayerFlgs */
    {
         m_eVDPlayerFlgs  = E_VDPLAYER_FLG_NONE;
    }
    /* Initializing global variable _gu16PreviewX */
    {
         _gu16PreviewX  = 0u;
    }
    /* Initializing global variable _gu16PreviewY */
    {
         _gu16PreviewY  = 0u;
    }
    /* Initializing global variable _gu16PreviewWidth */
    {
         _gu16PreviewWidth  = 0u;
    }
    /* Initializing global variable _gu16PreviewHeight */
    {
         _gu16PreviewHeight  = 0u;
    }
    /* Initializing global variable m_bFLG_PREVIEW */
    {
         m_bFLG_PREVIEW  = 0;
    }
    /* Initializing global variable g_DstWin */
    {
         g_DstWin.x  = 0u;
         g_DstWin.y  = 0u;
         g_DstWin.width  = 0u;
         g_DstWin.height  = 0u;
    }
    /* Initializing global variable _gbContinueBlockRead */
    {
         _gbContinueBlockRead  = 0;
    }
    /* Initializing global variable enVDPlayerRet */
    {
         enVDPlayerRet  = EXIT_NULL;
    }
    /* Initializing global variable g_bNonBlockingRead */
    {
         g_bNonBlockingRead  = 0;
    }
    /* Initializing global variable _bStreamSeeked */
    {
         _bStreamSeeked  = 0;
    }
    /* Initializing global variable _gu32BlockReadTimer */
    {
         _gu32BlockReadTimer  = 0ul;
    }
    /* Initializing global variable _gbEnableInternalSubtitle */
    {
         _gbEnableInternalSubtitle  = 0;
    }
    /* Initializing global variable _gu32ResidualReadSize */
    {
         _gu32ResidualReadSize  = 0ul;
    }
    /* Initializing global variable _gu32gStreamHdl */
    {
         _gu32gStreamHdl  = 0ul;
    }
    /* Initializing global variable _gu32BuffAddr */
    {
         _gu32BuffAddr  = 0ul;
    }
    /* Initializing global variable g_bNonBlockingSeek */
    {
         g_bNonBlockingSeek  = 0;
    }
    /* Initializing global variable g_b2ndRunPreviewMute */
    {
         g_b2ndRunPreviewMute  = 0;
    }
    /* Initializing global variable u16APageID */
    {
         u16APageID  = 0u;
    }
    /* Initializing global variable u16CodecNum */
    {
         u16CodecNum  = 0u;
    }
    /* Initializing global variable u16Samples_channel */
    {
         u16Samples_channel  = 0u;
    }
    /* Initializing global variable u8VDPlayerInitResult */
    {
         u8VDPlayerInitResult  = 0;
    }
    /* Initializing global variable u8VDPlayerSetAudioTrackResult */
    {
         u8VDPlayerSetAudioTrackResult  = 0;
    }
    /* Initializing global variable u8VDPlayerTsSetProgramResult */
    {
         u8VDPlayerTsSetProgramResult  = 0;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable m_eVDPlayerAckFlags */
    {
         m_eVDPlayerAckFlags  = E_ACKFLG_NULL;
    }
    /* Initializing global variable bDrmRegCode */
    {
         bDrmRegCode  = 0;
    }
    /* Initializing global variable enVDPlayerVideoType */
    {
         enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable _bEnableSeamlessPlaying */
    {
         _bEnableSeamlessPlaying  = 0;
    }
    /* Initializing global variable u32VdplayerShareMemAddr */
    {
         u32VdplayerShareMemAddr  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_VDPlayer_SetRepeatAB(_enAction);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );

    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VDPlayer_SetRepeatAB_return_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VDPlayer_SetTrickMode_return_FALSE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_VDPlayer_SetTrickMode(EN_VDP_PLAY_MODE, EN_VDP_PLAY_SPEED) */
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetTrickMode_return_FALSE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enPlayMode) */
    EN_VDP_PLAY_MODE _enPlayMode  = E_VDP_PLAY_MODE_NORMAL_PLAY;
    /* Initializing argument 2 (enPlaySpeed) */
    EN_VDP_PLAY_SPEED _enPlaySpeed  = E_VDP_PLAY_SPEED_X1;
    /* Initializing global variable m_s32PreSubtitleTagIdx */
    {
         m_s32PreSubtitleTagIdx  = 0L;
    }
    /* Initializing global variable m_u32PreMovieRefreshTextTimer */
    {
         m_u32PreMovieRefreshTextTimer  = 0ul;
    }
    /* Initializing global variable bDrmAuthorization */
    {
         bDrmAuthorization  = 0;
    }
    /* Initializing global variable bDrmFileFormat */
    {
         bDrmFileFormat  = 0;
    }
    /* Initializing global variable bDrmActivationFile */
    {
         bDrmActivationFile  = 0;
    }
    /* Initializing global variable bDrmRentalStatus */
    {
         bDrmRentalStatus  = 0;
    }
    /* Initializing global variable g_bDrmRental */
    {
         g_bDrmRental  = 0;
    }
    /* Initializing global variable g_u8DrmUseLimit */
    {
         g_u8DrmUseLimit  = 0;
    }
    /* Initializing global variable g_u8DrmUseCount */
    {
         g_u8DrmUseCount  = 0;
    }
    /* Initializing global variable u8VDPlayerSetTrickModeResult */
    {
         u8VDPlayerSetTrickModeResult  = 0;
    }
    /* Initializing global variable u8VDPlayerStepPlayResult */
    {
         u8VDPlayerStepPlayResult  = 0;
    }
    /* Initializing global variable _u32SeamlessTimer */
    {
         _u32SeamlessTimer  = 0ul;
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
    /* Initializing global variable u32subtitletype */
    {
         u32subtitletype  = 0ul;
    }
    /* Initializing global variable u16CPageID */
    {
         u16CPageID  = 0u;
    }
    /* Initializing global variable m_bSuspendInternalSubtitle2Queue */
    {
         m_bSuspendInternalSubtitle2Queue  = 0;
    }
    /* Initializing global variable _bSubtitleShow_MW */
    {
         _bSubtitleShow_MW  = 0;
    }
    /* Initializing global variable _bSubtitleShow_User */
    {
         _bSubtitleShow_User  = 0;
    }
    /* Initializing global variable u8InternalST_Num */
    {
         u8InternalST_Num  = 0;
    }
    /* Initializing global variable u16SubtitleTagCnt */
    {
         u16SubtitleTagCnt  = 0u;
    }
    /* Initializing global variable u8IsSubtitleBusy */
    {
         u8IsSubtitleBusy  = 0;
    }
    /* Initializing global variable u8IssubtitleInit */
    {
         u8IssubtitleInit  = 0;
    }
    /* Initializing global variable u8IsSubtitleInitfinish */
    {
         u8IsSubtitleInitfinish  = 0;
    }
    /* Initializing global variable u16tagposition */
    {
         u16tagposition  = 0u;
    }
    /* Initializing global variable u32GetSubtitleStateBuf */
    {
         u32GetSubtitleStateBuf  = 0ul;
    }
    /* Initializing global variable g_bReplay */
    {
         g_bReplay  = 0;
    }
    /* Initializing global variable g_bUnsupportAudio */
    {
         g_bUnsupportAudio  = 0;
    }
    /* Initializing global variable u32VDPlayerLoopWdtTimer */
    {
         u32VDPlayerLoopWdtTimer  = 0ul;
    }
    /* Initializing global variable g_stDemuxer */
    {
         g_stDemuxer.u32Video_IdxSize  = 0ul;
         g_stDemuxer.u32KeyIdxPeriod  = 0ul;
         g_stDemuxer.u32AudioKeyIdxPeriod  = 0ul;
         g_stDemuxer.u32lastVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u32FirstVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u8KeyIdxSize  = 0;
         g_stDemuxer.u8AudioKeyIdxSize  = 0;
         g_stDemuxer.u8ThumbNailMode  = 0;
         g_stDemuxer.bEnableCalcByBitRate  = 0;
         g_stDemuxer.bEnableAudioHandler  = 0;
    }
    /* Initializing global variable g_bIsTSRadioOnly */
    {
         g_bIsTSRadioOnly  = 0;
    }
    /* Initializing global variable g_enVDPlayerVideoType */
    {
         g_enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable g_bForceToFB */
    {
         g_bForceToFB  = 0;
    }
    /* Initializing global variable m_eVDPlayerFlgs */
    {
         m_eVDPlayerFlgs  = E_VDPLAYER_FLG_NONE;
    }
    /* Initializing global variable _gu16PreviewX */
    {
         _gu16PreviewX  = 0u;
    }
    /* Initializing global variable _gu16PreviewY */
    {
         _gu16PreviewY  = 0u;
    }
    /* Initializing global variable _gu16PreviewWidth */
    {
         _gu16PreviewWidth  = 0u;
    }
    /* Initializing global variable _gu16PreviewHeight */
    {
         _gu16PreviewHeight  = 0u;
    }
    /* Initializing global variable m_bFLG_PREVIEW */
    {
         m_bFLG_PREVIEW  = 0;
    }
    /* Initializing global variable g_DstWin */
    {
         g_DstWin.x  = 0u;
         g_DstWin.y  = 0u;
         g_DstWin.width  = 0u;
         g_DstWin.height  = 0u;
    }
    /* Initializing global variable _gbContinueBlockRead */
    {
         _gbContinueBlockRead  = 0;
    }
    /* Initializing global variable enVDPlayerRet */
    {
         enVDPlayerRet  = EXIT_NULL;
    }
    /* Initializing global variable g_bNonBlockingRead */
    {
         g_bNonBlockingRead  = 0;
    }
    /* Initializing global variable _bStreamSeeked */
    {
         _bStreamSeeked  = 0;
    }
    /* Initializing global variable _gu32BlockReadTimer */
    {
         _gu32BlockReadTimer  = 0ul;
    }
    /* Initializing global variable _gbEnableInternalSubtitle */
    {
         _gbEnableInternalSubtitle  = 0;
    }
    /* Initializing global variable _gu32ResidualReadSize */
    {
         _gu32ResidualReadSize  = 0ul;
    }
    /* Initializing global variable _gu32gStreamHdl */
    {
         _gu32gStreamHdl  = 0ul;
    }
    /* Initializing global variable _gu32BuffAddr */
    {
         _gu32BuffAddr  = 0ul;
    }
    /* Initializing global variable g_bNonBlockingSeek */
    {
         g_bNonBlockingSeek  = 0;
    }
    /* Initializing global variable g_b2ndRunPreviewMute */
    {
         g_b2ndRunPreviewMute  = 0;
    }
    /* Initializing global variable u16APageID */
    {
         u16APageID  = 0u;
    }
    /* Initializing global variable u16CodecNum */
    {
         u16CodecNum  = 0u;
    }
    /* Initializing global variable u16Samples_channel */
    {
         u16Samples_channel  = 0u;
    }
    /* Initializing global variable u8VDPlayerInitResult */
    {
         u8VDPlayerInitResult  = 0;
    }
    /* Initializing global variable u8VDPlayerSetAudioTrackResult */
    {
         u8VDPlayerSetAudioTrackResult  = 0;
    }
    /* Initializing global variable u8VDPlayerTsSetProgramResult */
    {
         u8VDPlayerTsSetProgramResult  = 0;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable m_eVDPlayerAckFlags */
    {
         m_eVDPlayerAckFlags  = E_ACKFLG_NULL;
    }
    /* Initializing global variable bDrmRegCode */
    {
         bDrmRegCode  = 0;
    }
    /* Initializing global variable enVDPlayerVideoType */
    {
         enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable _bEnableSeamlessPlaying */
    {
         _bEnableSeamlessPlaying  = 0;
    }
    /* Initializing global variable u32VdplayerShareMemAddr */
    {
         u32VdplayerShareMemAddr  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_VDPlayer_SetTrickMode(_enPlayMode, _enPlaySpeed);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VDPlayer_SetTrickMode_return_FALSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VDPlayer_SetTrickMode_return_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_VDPlayer_SetTrickMode(EN_VDP_PLAY_MODE, EN_VDP_PLAY_SPEED) */

void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetTrickMode_return_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enPlayMode) */
    EN_VDP_PLAY_MODE _enPlayMode  = E_VDP_PLAY_MODE_NORMAL_PLAY;
    /* Initializing argument 2 (enPlaySpeed) */
    EN_VDP_PLAY_SPEED _enPlaySpeed  = E_VDP_PLAY_SPEED_X1;
    /* Initializing global variable m_s32PreSubtitleTagIdx */
    {
         m_s32PreSubtitleTagIdx  = 0L;
    }
    /* Initializing global variable m_u32PreMovieRefreshTextTimer */
    {
         m_u32PreMovieRefreshTextTimer  = 0ul;
    }
    /* Initializing global variable bDrmAuthorization */
    {
         bDrmAuthorization  = 0;
    }
    /* Initializing global variable bDrmFileFormat */
    {
         bDrmFileFormat  = 0;
    }
    /* Initializing global variable bDrmActivationFile */
    {
         bDrmActivationFile  = 0;
    }
    /* Initializing global variable bDrmRentalStatus */
    {
         bDrmRentalStatus  = 0;
    }
    /* Initializing global variable g_bDrmRental */
    {
         g_bDrmRental  = 0;
    }
    /* Initializing global variable g_u8DrmUseLimit */
    {
         g_u8DrmUseLimit  = 0;
    }
    /* Initializing global variable g_u8DrmUseCount */
    {
         g_u8DrmUseCount  = 0;
    }
    /* Initializing global variable u8VDPlayerSetTrickModeResult */
    {
         u8VDPlayerSetTrickModeResult  = 0;
    }
    /* Initializing global variable u8VDPlayerStepPlayResult */
    {
         u8VDPlayerStepPlayResult  = 0;
    }
    /* Initializing global variable _u32SeamlessTimer */
    {
         _u32SeamlessTimer  = 0ul;
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
    /* Initializing global variable u32subtitletype */
    {
         u32subtitletype  = 0ul;
    }
    /* Initializing global variable u16CPageID */
    {
         u16CPageID  = 0u;
    }
    /* Initializing global variable m_bSuspendInternalSubtitle2Queue */
    {
         m_bSuspendInternalSubtitle2Queue  = 0;
    }
    /* Initializing global variable _bSubtitleShow_MW */
    {
         _bSubtitleShow_MW  = 0;
    }
    /* Initializing global variable _bSubtitleShow_User */
    {
         _bSubtitleShow_User  = 0;
    }
    /* Initializing global variable u8InternalST_Num */
    {
         u8InternalST_Num  = 0;
    }
    /* Initializing global variable u16SubtitleTagCnt */
    {
         u16SubtitleTagCnt  = 0u;
    }
    /* Initializing global variable u8IsSubtitleBusy */
    {
         u8IsSubtitleBusy  = 0;
    }
    /* Initializing global variable u8IssubtitleInit */
    {
         u8IssubtitleInit  = 0;
    }
    /* Initializing global variable u8IsSubtitleInitfinish */
    {
         u8IsSubtitleInitfinish  = 0;
    }
    /* Initializing global variable u16tagposition */
    {
         u16tagposition  = 0u;
    }
    /* Initializing global variable u32GetSubtitleStateBuf */
    {
         u32GetSubtitleStateBuf  = 0ul;
    }
    /* Initializing global variable g_bReplay */
    {
         g_bReplay  = 0;
    }
    /* Initializing global variable g_bUnsupportAudio */
    {
         g_bUnsupportAudio  = 0;
    }
    /* Initializing global variable u32VDPlayerLoopWdtTimer */
    {
         u32VDPlayerLoopWdtTimer  = 0ul;
    }
    /* Initializing global variable g_stDemuxer */
    {
         g_stDemuxer.u32Video_IdxSize  = 0ul;
         g_stDemuxer.u32KeyIdxPeriod  = 0ul;
         g_stDemuxer.u32AudioKeyIdxPeriod  = 0ul;
         g_stDemuxer.u32lastVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u32FirstVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u8KeyIdxSize  = 0;
         g_stDemuxer.u8AudioKeyIdxSize  = 0;
         g_stDemuxer.u8ThumbNailMode  = 0;
         g_stDemuxer.bEnableCalcByBitRate  = 0;
         g_stDemuxer.bEnableAudioHandler  = 0;
    }
    /* Initializing global variable g_bIsTSRadioOnly */
    {
         g_bIsTSRadioOnly  = 0;
    }
    /* Initializing global variable g_enVDPlayerVideoType */
    {
         g_enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable g_bForceToFB */
    {
         g_bForceToFB  = 0;
    }
    /* Initializing global variable m_eVDPlayerFlgs */
    {
         m_eVDPlayerFlgs  = E_VDPLAYER_FLG_NONE;
    }
    /* Initializing global variable _gu16PreviewX */
    {
         _gu16PreviewX  = 0u;
    }
    /* Initializing global variable _gu16PreviewY */
    {
         _gu16PreviewY  = 0u;
    }
    /* Initializing global variable _gu16PreviewWidth */
    {
         _gu16PreviewWidth  = 0u;
    }
    /* Initializing global variable _gu16PreviewHeight */
    {
         _gu16PreviewHeight  = 0u;
    }
    /* Initializing global variable m_bFLG_PREVIEW */
    {
         m_bFLG_PREVIEW  = 0;
    }
    /* Initializing global variable g_DstWin */
    {
         g_DstWin.x  = 0u;
         g_DstWin.y  = 0u;
         g_DstWin.width  = 0u;
         g_DstWin.height  = 0u;
    }
    /* Initializing global variable _gbContinueBlockRead */
    {
         _gbContinueBlockRead  = 0;
    }
    /* Initializing global variable enVDPlayerRet */
    {
         enVDPlayerRet  = EXIT_NULL;
    }
    /* Initializing global variable g_bNonBlockingRead */
    {
         g_bNonBlockingRead  = 0;
    }
    /* Initializing global variable _bStreamSeeked */
    {
         _bStreamSeeked  = 0;
    }
    /* Initializing global variable _gu32BlockReadTimer */
    {
         _gu32BlockReadTimer  = 0ul;
    }
    /* Initializing global variable _gbEnableInternalSubtitle */
    {
         _gbEnableInternalSubtitle  = 0;
    }
    /* Initializing global variable _gu32ResidualReadSize */
    {
         _gu32ResidualReadSize  = 0ul;
    }
    /* Initializing global variable _gu32gStreamHdl */
    {
         _gu32gStreamHdl  = 0ul;
    }
    /* Initializing global variable _gu32BuffAddr */
    {
         _gu32BuffAddr  = 0ul;
    }
    /* Initializing global variable g_bNonBlockingSeek */
    {
         g_bNonBlockingSeek  = 0;
    }
    /* Initializing global variable g_b2ndRunPreviewMute */
    {
         g_b2ndRunPreviewMute  = 0;
    }
    /* Initializing global variable u16APageID */
    {
         u16APageID  = 0u;
    }
    /* Initializing global variable u16CodecNum */
    {
         u16CodecNum  = 0u;
    }
    /* Initializing global variable u16Samples_channel */
    {
         u16Samples_channel  = 0u;
    }
    /* Initializing global variable u8VDPlayerInitResult */
    {
         u8VDPlayerInitResult  = 0;
    }
    /* Initializing global variable u8VDPlayerSetAudioTrackResult */
    {
         u8VDPlayerSetAudioTrackResult  = 0;
    }
    /* Initializing global variable u8VDPlayerTsSetProgramResult */
    {
         u8VDPlayerTsSetProgramResult  = 0;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable m_eVDPlayerAckFlags */
    {
         m_eVDPlayerAckFlags  = E_ACKFLG_NULL;
    }
    /* Initializing global variable bDrmRegCode */
    {
         bDrmRegCode  = 0;
    }
    /* Initializing global variable enVDPlayerVideoType */
    {
         enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable _bEnableSeamlessPlaying */
    {
         _bEnableSeamlessPlaying  = 0;
    }
    /* Initializing global variable u32VdplayerShareMemAddr */
    {
         u32VdplayerShareMemAddr  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_VDPlayer_SetTrickMode(_enPlayMode, _enPlaySpeed);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VDPlayer_SetTrickMode_return_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VDPlayer_SetPlayPosition_return_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_VDPlayer_SetPlayPosition(U32) */
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetPlayPosition_return_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (timeInMs) */
    U32 _timeInMs  = 0ul;
    /* Initializing global variable m_s32PreSubtitleTagIdx */
    {
         m_s32PreSubtitleTagIdx  = 0L;
    }
    /* Initializing global variable m_u32PreMovieRefreshTextTimer */
    {
         m_u32PreMovieRefreshTextTimer  = 0ul;
    }
    /* Initializing global variable bDrmAuthorization */
    {
         bDrmAuthorization  = 0;
    }
    /* Initializing global variable bDrmFileFormat */
    {
         bDrmFileFormat  = 0;
    }
    /* Initializing global variable bDrmActivationFile */
    {
         bDrmActivationFile  = 0;
    }
    /* Initializing global variable bDrmRentalStatus */
    {
         bDrmRentalStatus  = 0;
    }
    /* Initializing global variable g_bDrmRental */
    {
         g_bDrmRental  = 0;
    }
    /* Initializing global variable g_u8DrmUseLimit */
    {
         g_u8DrmUseLimit  = 0;
    }
    /* Initializing global variable g_u8DrmUseCount */
    {
         g_u8DrmUseCount  = 0;
    }
    /* Initializing global variable u8VDPlayerSetTrickModeResult */
    {
         u8VDPlayerSetTrickModeResult  = 0;
    }
    /* Initializing global variable u8VDPlayerStepPlayResult */
    {
         u8VDPlayerStepPlayResult  = 0;
    }
    /* Initializing global variable _u32SeamlessTimer */
    {
         _u32SeamlessTimer  = 0ul;
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
    /* Initializing global variable u32subtitletype */
    {
         u32subtitletype  = 0ul;
    }
    /* Initializing global variable u16CPageID */
    {
         u16CPageID  = 0u;
    }
    /* Initializing global variable m_bSuspendInternalSubtitle2Queue */
    {
         m_bSuspendInternalSubtitle2Queue  = 0;
    }
    /* Initializing global variable _bSubtitleShow_MW */
    {
         _bSubtitleShow_MW  = 0;
    }
    /* Initializing global variable _bSubtitleShow_User */
    {
         _bSubtitleShow_User  = 0;
    }
    /* Initializing global variable u8InternalST_Num */
    {
         u8InternalST_Num  = 0;
    }
    /* Initializing global variable u16SubtitleTagCnt */
    {
         u16SubtitleTagCnt  = 0u;
    }
    /* Initializing global variable u8IsSubtitleBusy */
    {
         u8IsSubtitleBusy  = 0;
    }
    /* Initializing global variable u8IssubtitleInit */
    {
         u8IssubtitleInit  = 0;
    }
    /* Initializing global variable u8IsSubtitleInitfinish */
    {
         u8IsSubtitleInitfinish  = 0;
    }
    /* Initializing global variable u16tagposition */
    {
         u16tagposition  = 0u;
    }
    /* Initializing global variable u32GetSubtitleStateBuf */
    {
         u32GetSubtitleStateBuf  = 0ul;
    }
    /* Initializing global variable g_bReplay */
    {
         g_bReplay  = 0;
    }
    /* Initializing global variable g_bUnsupportAudio */
    {
         g_bUnsupportAudio  = 0;
    }
    /* Initializing global variable u32VDPlayerLoopWdtTimer */
    {
         u32VDPlayerLoopWdtTimer  = 0ul;
    }
    /* Initializing global variable g_stDemuxer */
    {
         g_stDemuxer.u32Video_IdxSize  = 0ul;
         g_stDemuxer.u32KeyIdxPeriod  = 0ul;
         g_stDemuxer.u32AudioKeyIdxPeriod  = 0ul;
         g_stDemuxer.u32lastVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u32FirstVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u8KeyIdxSize  = 0;
         g_stDemuxer.u8AudioKeyIdxSize  = 0;
         g_stDemuxer.u8ThumbNailMode  = 0;
         g_stDemuxer.bEnableCalcByBitRate  = 0;
         g_stDemuxer.bEnableAudioHandler  = 0;
    }
    /* Initializing global variable g_bIsTSRadioOnly */
    {
         g_bIsTSRadioOnly  = 0;
    }
    /* Initializing global variable g_enVDPlayerVideoType */
    {
         g_enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable g_bForceToFB */
    {
         g_bForceToFB  = 0;
    }
    /* Initializing global variable m_eVDPlayerFlgs */
    {
         m_eVDPlayerFlgs  = E_VDPLAYER_FLG_NONE;
    }
    /* Initializing global variable _gu16PreviewX */
    {
         _gu16PreviewX  = 0u;
    }
    /* Initializing global variable _gu16PreviewY */
    {
         _gu16PreviewY  = 0u;
    }
    /* Initializing global variable _gu16PreviewWidth */
    {
         _gu16PreviewWidth  = 0u;
    }
    /* Initializing global variable _gu16PreviewHeight */
    {
         _gu16PreviewHeight  = 0u;
    }
    /* Initializing global variable m_bFLG_PREVIEW */
    {
         m_bFLG_PREVIEW  = 0;
    }
    /* Initializing global variable g_DstWin */
    {
         g_DstWin.x  = 0u;
         g_DstWin.y  = 0u;
         g_DstWin.width  = 0u;
         g_DstWin.height  = 0u;
    }
    /* Initializing global variable _gbContinueBlockRead */
    {
         _gbContinueBlockRead  = 0;
    }
    /* Initializing global variable enVDPlayerRet */
    {
         enVDPlayerRet  = EXIT_NULL;
    }
    /* Initializing global variable g_bNonBlockingRead */
    {
         g_bNonBlockingRead  = 0;
    }
    /* Initializing global variable _bStreamSeeked */
    {
         _bStreamSeeked  = 0;
    }
    /* Initializing global variable _gu32BlockReadTimer */
    {
         _gu32BlockReadTimer  = 0ul;
    }
    /* Initializing global variable _gbEnableInternalSubtitle */
    {
         _gbEnableInternalSubtitle  = 0;
    }
    /* Initializing global variable _gu32ResidualReadSize */
    {
         _gu32ResidualReadSize  = 0ul;
    }
    /* Initializing global variable _gu32gStreamHdl */
    {
         _gu32gStreamHdl  = 0ul;
    }
    /* Initializing global variable _gu32BuffAddr */
    {
         _gu32BuffAddr  = 0ul;
    }
    /* Initializing global variable g_bNonBlockingSeek */
    {
         g_bNonBlockingSeek  = 0;
    }
    /* Initializing global variable g_b2ndRunPreviewMute */
    {
         g_b2ndRunPreviewMute  = 0;
    }
    /* Initializing global variable u16APageID */
    {
         u16APageID  = 0u;
    }
    /* Initializing global variable u16CodecNum */
    {
         u16CodecNum  = 0u;
    }
    /* Initializing global variable u16Samples_channel */
    {
         u16Samples_channel  = 0u;
    }
    /* Initializing global variable u8VDPlayerInitResult */
    {
         u8VDPlayerInitResult  = 0;
    }
    /* Initializing global variable u8VDPlayerSetAudioTrackResult */
    {
         u8VDPlayerSetAudioTrackResult  = 0;
    }
    /* Initializing global variable u8VDPlayerTsSetProgramResult */
    {
         u8VDPlayerTsSetProgramResult  = 0;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable m_eVDPlayerAckFlags */
    {
         m_eVDPlayerAckFlags  = E_ACKFLG_NULL;
    }
    /* Initializing global variable bDrmRegCode */
    {
         bDrmRegCode  = 0;
    }
    /* Initializing global variable enVDPlayerVideoType */
    {
         enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable _bEnableSeamlessPlaying */
    {
         _bEnableSeamlessPlaying  = 0;
    }
    /* Initializing global variable u32VdplayerShareMemAddr */
    {
         u32VdplayerShareMemAddr  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_VDPlayer_SetPlayPosition(_timeInMs);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VDPlayer_SetPlayPosition_return_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VDPlayer_SetSubtitleTrackID_return_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_VDPlayer_SetSubtitleTrackID(U8) */
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetSubtitleTrackID_return_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8TrackId) */
    U8 _u8TrackId  = 0;
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable _gbCoprocessorEnable */
    {
         _gbCoprocessorEnable  = 0;
    }
    /* Initializing global variable m_s32PreSubtitleTagIdx */
    {
         m_s32PreSubtitleTagIdx  = 0L;
    }
    /* Initializing global variable m_u32PreMovieRefreshTextTimer */
    {
         m_u32PreMovieRefreshTextTimer  = 0ul;
    }
    /* Initializing global variable bMovieAbort */
    {
         bMovieAbort  = 0;
    }
    /* Initializing global variable m_bVDPlayerPreview */
    {
         m_bVDPlayerPreview  = 0;
    }
    /* Initializing global variable m_bVDPlayerThumbnail */
    {
         m_bVDPlayerThumbnail  = 0;
    }
    /* Initializing global variable _geBMStreamMode */
    {
         _geBMStreamMode  = E_BM_STREAM_MODE_NORMAL;
    }
    /* Initializing global variable m_u8LastMemoryCheck */
    {
         m_u8LastMemoryCheck  = 0;
    }
    /* Initializing global variable bDrmAuthorization */
    {
         bDrmAuthorization  = 0;
    }
    /* Initializing global variable bDrmFileFormat */
    {
         bDrmFileFormat  = 0;
    }
    /* Initializing global variable bDrmActivationFile */
    {
         bDrmActivationFile  = 0;
    }
    /* Initializing global variable bDrmRentalStatus */
    {
         bDrmRentalStatus  = 0;
    }
    /* Initializing global variable g_bDrmRental */
    {
         g_bDrmRental  = 0;
    }
    /* Initializing global variable g_u8DrmUseLimit */
    {
         g_u8DrmUseLimit  = 0;
    }
    /* Initializing global variable g_u8DrmUseCount */
    {
         g_u8DrmUseCount  = 0;
    }
    /* Initializing global variable u8VDPlayerSetTrickModeResult */
    {
         u8VDPlayerSetTrickModeResult  = 0;
    }
    /* Initializing global variable u8VDPlayerStepPlayResult */
    {
         u8VDPlayerStepPlayResult  = 0;
    }
    /* Initializing global variable _u32SeamlessTimer */
    {
         _u32SeamlessTimer  = 0ul;
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
    /* Initializing global variable u32subtitletype */
    {
         u32subtitletype  = 1ul;
    }
    /* Initializing global variable u16CPageID */
    {
         u16CPageID  = 0u;
    }
    /* Initializing global variable m_bSuspendInternalSubtitle2Queue */
    {
         m_bSuspendInternalSubtitle2Queue  = 0;
    }
    /* Initializing global variable _bSubtitleShow_MW */
    {
         _bSubtitleShow_MW  = 0;
    }
    /* Initializing global variable _bSubtitleShow_User */
    {
         _bSubtitleShow_User  = 0;
    }
    /* Initializing global variable u8InternalST_Num */
    {
         u8InternalST_Num  = 0;
    }
    /* Initializing global variable u16SubtitleTagCnt */
    {
         u16SubtitleTagCnt  = 0u;
    }
    /* Initializing global variable u8IsSubtitleBusy */
    {
         u8IsSubtitleBusy  = 0;
    }
    /* Initializing global variable u8IssubtitleInit */
    {
         u8IssubtitleInit  = 0;
    }
    /* Initializing global variable u8IsSubtitleInitfinish */
    {
         u8IsSubtitleInitfinish  = 0;
    }
    /* Initializing global variable u16tagposition */
    {
         u16tagposition  = 0u;
    }
    /* Initializing global variable u32GetSubtitleStateBuf */
    {
         u32GetSubtitleStateBuf  = 0ul;
    }
    /* Initializing global variable g_bReplay */
    {
         g_bReplay  = 0;
    }
    /* Initializing global variable g_bUnsupportAudio */
    {
         g_bUnsupportAudio  = 0;
    }
    /* Initializing global variable u32VDPlayerLoopWdtTimer */
    {
         u32VDPlayerLoopWdtTimer  = 0ul;
    }
    /* Initializing global variable g_stDemuxer */
    {
         g_stDemuxer.u32Video_IdxSize  = 0ul;
         g_stDemuxer.u32KeyIdxPeriod  = 0ul;
         g_stDemuxer.u32AudioKeyIdxPeriod  = 0ul;
         g_stDemuxer.u32lastVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u32FirstVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u8KeyIdxSize  = 0;
         g_stDemuxer.u8AudioKeyIdxSize  = 0;
         g_stDemuxer.u8ThumbNailMode  = 0;
         g_stDemuxer.bEnableCalcByBitRate  = 0;
         g_stDemuxer.bEnableAudioHandler  = 0;
    }
    /* Initializing global variable g_bIsTSRadioOnly */
    {
         g_bIsTSRadioOnly  = 0;
    }
    /* Initializing global variable g_enVDPlayerVideoType */
    {
         g_enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable g_bForceToFB */
    {
         g_bForceToFB  = 0;
    }
    /* Initializing global variable m_eVDPlayerFlgs */
    {
         m_eVDPlayerFlgs  = E_VDPLAYER_FLG_NONE;
    }
    /* Initializing global variable _gu16PreviewX */
    {
         _gu16PreviewX  = 0u;
    }
    /* Initializing global variable _gu16PreviewY */
    {
         _gu16PreviewY  = 0u;
    }
    /* Initializing global variable _gu16PreviewWidth */
    {
         _gu16PreviewWidth  = 0u;
    }
    /* Initializing global variable _gu16PreviewHeight */
    {
         _gu16PreviewHeight  = 0u;
    }
    /* Initializing global variable m_bFLG_PREVIEW */
    {
         m_bFLG_PREVIEW  = 0;
    }
    /* Initializing global variable g_DstWin */
    {
         g_DstWin.x  = 0u;
         g_DstWin.y  = 0u;
         g_DstWin.width  = 0u;
         g_DstWin.height  = 0u;
    }
    /* Initializing global variable _gbContinueBlockRead */
    {
         _gbContinueBlockRead  = 0;
    }
    /* Initializing global variable enVDPlayerRet */
    {
         enVDPlayerRet  = EXIT_NULL;
    }
    /* Initializing global variable g_bNonBlockingRead */
    {
         g_bNonBlockingRead  = 0;
    }
    /* Initializing global variable _bStreamSeeked */
    {
         _bStreamSeeked  = 0;
    }
    /* Initializing global variable _gu32BlockReadTimer */
    {
         _gu32BlockReadTimer  = 0ul;
    }
    /* Initializing global variable _gbEnableInternalSubtitle */
    {
         _gbEnableInternalSubtitle  = 0;
    }
    /* Initializing global variable _gu32ResidualReadSize */
    {
         _gu32ResidualReadSize  = 0ul;
    }
    /* Initializing global variable _gu32gStreamHdl */
    {
         _gu32gStreamHdl  = 0ul;
    }
    /* Initializing global variable _gu32BuffAddr */
    {
         _gu32BuffAddr  = 0ul;
    }
    /* Initializing global variable g_bNonBlockingSeek */
    {
         g_bNonBlockingSeek  = 0;
    }
    /* Initializing global variable g_b2ndRunPreviewMute */
    {
         g_b2ndRunPreviewMute  = 0;
    }
    /* Initializing global variable u16APageID */
    {
         u16APageID  = 0u;
    }
    /* Initializing global variable u16CodecNum */
    {
         u16CodecNum  = 0u;
    }
    /* Initializing global variable u16Samples_channel */
    {
         u16Samples_channel  = 0u;
    }
    /* Initializing global variable u8VDPlayerInitResult */
    {
         u8VDPlayerInitResult  = 0;
    }
    /* Initializing global variable u8VDPlayerSetAudioTrackResult */
    {
         u8VDPlayerSetAudioTrackResult  = 0;
    }
    /* Initializing global variable u8VDPlayerTsSetProgramResult */
    {
         u8VDPlayerTsSetProgramResult  = 0;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable m_eVDPlayerAckFlags */
    {
         m_eVDPlayerAckFlags  = E_ACKFLG_NULL;
    }
    /* Initializing global variable bDrmRegCode */
    {
         bDrmRegCode  = 0;
    }
    /* Initializing global variable enVDPlayerVideoType */
    {
         enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable _bEnableSeamlessPlaying */
    {
         _bEnableSeamlessPlaying  = 0;
    }
    /* Initializing global variable u32VdplayerShareMemAddr */
    {
         u32VdplayerShareMemAddr  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_VDPlayer_SetSubtitleTrackID(_u8TrackId);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VDPlayer_SetSubtitleTrackID_return_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VDPlayer_SubtitleTimeShift_return_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_VDPlayer_SubtitleTimeShift(BOOLEAN, U16) */
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SubtitleTimeShift_return_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bDirection) */
    U8 _bDirection  = 0;
    /* Initializing argument 2 (u16TimeShift) */
    U16 _u16TimeShift  = 0u;
    /* Initializing global variable m_s32PreSubtitleTagIdx */
    {
         m_s32PreSubtitleTagIdx  = 0L;
    }
    /* Initializing global variable m_u32PreMovieRefreshTextTimer */
    {
         m_u32PreMovieRefreshTextTimer  = 0ul;
    }
    /* Initializing global variable bDrmAuthorization */
    {
         bDrmAuthorization  = 0;
    }
    /* Initializing global variable bDrmFileFormat */
    {
         bDrmFileFormat  = 0;
    }
    /* Initializing global variable bDrmActivationFile */
    {
         bDrmActivationFile  = 0;
    }
    /* Initializing global variable bDrmRentalStatus */
    {
         bDrmRentalStatus  = 0;
    }
    /* Initializing global variable g_bDrmRental */
    {
         g_bDrmRental  = 0;
    }
    /* Initializing global variable g_u8DrmUseLimit */
    {
         g_u8DrmUseLimit  = 0;
    }
    /* Initializing global variable g_u8DrmUseCount */
    {
         g_u8DrmUseCount  = 0;
    }
    /* Initializing global variable u8VDPlayerSetTrickModeResult */
    {
         u8VDPlayerSetTrickModeResult  = 0;
    }
    /* Initializing global variable u8VDPlayerStepPlayResult */
    {
         u8VDPlayerStepPlayResult  = 0;
    }
    /* Initializing global variable _u32SeamlessTimer */
    {
         _u32SeamlessTimer  = 0ul;
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
    /* Initializing global variable u32subtitletype */
    {
         u32subtitletype  = 0ul;
    }
    /* Initializing global variable u16CPageID */
    {
         u16CPageID  = 0u;
    }
    /* Initializing global variable m_bSuspendInternalSubtitle2Queue */
    {
         m_bSuspendInternalSubtitle2Queue  = 0;
    }
    /* Initializing global variable _bSubtitleShow_MW */
    {
         _bSubtitleShow_MW  = 0;
    }
    /* Initializing global variable _bSubtitleShow_User */
    {
         _bSubtitleShow_User  = 0;
    }
    /* Initializing global variable u8InternalST_Num */
    {
         u8InternalST_Num  = 0;
    }
    /* Initializing global variable u16SubtitleTagCnt */
    {
         u16SubtitleTagCnt  = 0u;
    }
    /* Initializing global variable u8IsSubtitleBusy */
    {
         u8IsSubtitleBusy  = 0;
    }
    /* Initializing global variable u8IssubtitleInit */
    {
         u8IssubtitleInit  = 0;
    }
    /* Initializing global variable u8IsSubtitleInitfinish */
    {
         u8IsSubtitleInitfinish  = 0;
    }
    /* Initializing global variable u16tagposition */
    {
         u16tagposition  = 0u;
    }
    /* Initializing global variable u32GetSubtitleStateBuf */
    {
         u32GetSubtitleStateBuf  = 0ul;
    }
    /* Initializing global variable g_bReplay */
    {
         g_bReplay  = 0;
    }
    /* Initializing global variable g_bUnsupportAudio */
    {
         g_bUnsupportAudio  = 0;
    }
    /* Initializing global variable u32VDPlayerLoopWdtTimer */
    {
         u32VDPlayerLoopWdtTimer  = 0ul;
    }
    /* Initializing global variable g_stDemuxer */
    {
         g_stDemuxer.u32Video_IdxSize  = 0ul;
         g_stDemuxer.u32KeyIdxPeriod  = 0ul;
         g_stDemuxer.u32AudioKeyIdxPeriod  = 0ul;
         g_stDemuxer.u32lastVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u32FirstVideoKeyFramePTS  = 0ul;
         g_stDemuxer.u8KeyIdxSize  = 0;
         g_stDemuxer.u8AudioKeyIdxSize  = 0;
         g_stDemuxer.u8ThumbNailMode  = 0;
         g_stDemuxer.bEnableCalcByBitRate  = 0;
         g_stDemuxer.bEnableAudioHandler  = 0;
    }
    /* Initializing global variable g_bIsTSRadioOnly */
    {
         g_bIsTSRadioOnly  = 0;
    }
    /* Initializing global variable g_enVDPlayerVideoType */
    {
         g_enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable g_bForceToFB */
    {
         g_bForceToFB  = 0;
    }
    /* Initializing global variable m_eVDPlayerFlgs */
    {
         m_eVDPlayerFlgs  = E_VDPLAYER_FLG_NONE;
    }
    /* Initializing global variable _gu16PreviewX */
    {
         _gu16PreviewX  = 0u;
    }
    /* Initializing global variable _gu16PreviewY */
    {
         _gu16PreviewY  = 0u;
    }
    /* Initializing global variable _gu16PreviewWidth */
    {
         _gu16PreviewWidth  = 0u;
    }
    /* Initializing global variable _gu16PreviewHeight */
    {
         _gu16PreviewHeight  = 0u;
    }
    /* Initializing global variable m_bFLG_PREVIEW */
    {
         m_bFLG_PREVIEW  = 0;
    }
    /* Initializing global variable g_DstWin */
    {
         g_DstWin.x  = 0u;
         g_DstWin.y  = 0u;
         g_DstWin.width  = 0u;
         g_DstWin.height  = 0u;
    }
    /* Initializing global variable _gbContinueBlockRead */
    {
         _gbContinueBlockRead  = 0;
    }
    /* Initializing global variable enVDPlayerRet */
    {
         enVDPlayerRet  = EXIT_NULL;
    }
    /* Initializing global variable g_bNonBlockingRead */
    {
         g_bNonBlockingRead  = 0;
    }
    /* Initializing global variable _bStreamSeeked */
    {
         _bStreamSeeked  = 0;
    }
    /* Initializing global variable _gu32BlockReadTimer */
    {
         _gu32BlockReadTimer  = 0ul;
    }
    /* Initializing global variable _gbEnableInternalSubtitle */
    {
         _gbEnableInternalSubtitle  = 0;
    }
    /* Initializing global variable _gu32ResidualReadSize */
    {
         _gu32ResidualReadSize  = 0ul;
    }
    /* Initializing global variable _gu32gStreamHdl */
    {
         _gu32gStreamHdl  = 0ul;
    }
    /* Initializing global variable _gu32BuffAddr */
    {
         _gu32BuffAddr  = 0ul;
    }
    /* Initializing global variable g_bNonBlockingSeek */
    {
         g_bNonBlockingSeek  = 0;
    }
    /* Initializing global variable g_b2ndRunPreviewMute */
    {
         g_b2ndRunPreviewMute  = 0;
    }
    /* Initializing global variable u16APageID */
    {
         u16APageID  = 0u;
    }
    /* Initializing global variable u16CodecNum */
    {
         u16CodecNum  = 0u;
    }
    /* Initializing global variable u16Samples_channel */
    {
         u16Samples_channel  = 0u;
    }
    /* Initializing global variable u8VDPlayerInitResult */
    {
         u8VDPlayerInitResult  = 0;
    }
    /* Initializing global variable u8VDPlayerSetAudioTrackResult */
    {
         u8VDPlayerSetAudioTrackResult  = 0;
    }
    /* Initializing global variable u8VDPlayerTsSetProgramResult */
    {
         u8VDPlayerTsSetProgramResult  = 0;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable m_eVDPlayerAckFlags */
    {
         m_eVDPlayerAckFlags  = E_ACKFLG_NULL;
    }
    /* Initializing global variable bDrmRegCode */
    {
         bDrmRegCode  = 0;
    }
    /* Initializing global variable enVDPlayerVideoType */
    {
         enVDPlayerVideoType  = E_VDPLAYER_VIDEO_UNKNOW;
    }
    /* Initializing global variable _bEnableSeamlessPlaying */
    {
         _bEnableSeamlessPlaying  = 0;
    }
    /* Initializing global variable u32VdplayerShareMemAddr */
    {
         u32VdplayerShareMemAddr  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_VDPlayer_SubtitleTimeShift(_bDirection, _u16TimeShift);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VDPlayer_SubtitleTimeShift_return_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_VDPlayer_CheckPreviewAbortKey_return_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_VDPlayer_CheckPreviewAbortKey(void) */
void TestSuite_mapp_videoplayer_test__MApp_VDPlayer_CheckPreviewAbortKey_return_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_UP;
    }
    /* Initializing global variable m_bVDPlayerPreview */
    {
	    m_bVDPlayerPreview=TRUE;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_VDPlayer_CheckPreviewAbortKey();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_VDPlayer_CheckPreviewAbortKey_return_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_VDPlayer_ClearDRMMemory_return_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_VDPlayer_ClearDRMMemory(void) */
void TestSuite_mapp_videoplayer_test_MApp_VDPlayer_ClearDRMMemory_return_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_VDPlayer_ClearDRMMemory();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_VDPlayer_ClearDRMMemory_return_TRUE */
