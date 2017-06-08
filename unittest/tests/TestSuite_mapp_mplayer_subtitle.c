#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/multimedia/mapp_mplayer_subtitle.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/multimedia/mapp_mplayer_subtitle.c");

CPPTEST_TEST_SUITE(TestSuite_mapp_mplayer_subtitle);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_nupr_Uppercase);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_nupr_Lowercase);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_nupr_Unicode_Uppercase);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_nupr_Unicode_Lowercase);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_ScanDigit_Input_String_123);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_ScanMilliSecond_Input_String_123);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_ScanMilliSecond_Input_String_12);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_ScanHex_Input_String_3aB);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_SetSubtitleTrackID_TrackID_Lower_than_TrackNum);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_SetSubtitleTrackID_TrackID_Greater_than_TrackNum);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_SubtitleInit);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_SetInternalSubtitle_true);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_ScanfIdxPos_Input_String_0x1234);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_GetInfo_E_MPLAYER_EXT_SUBTITLE_INFO_NB_TRACK);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_ScanfIdxPos_return_FALSE);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_GetInfo_E_MPLAYER_EXT_SUBTITLE_INFO_TRACK_ID);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_GetInfo_E_MPLAYER_EXT_SUBTITLE_INFO_SUBTITLE_TYPE);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_GetInfo_E_MPLAYER_EXT_SUBTITLE_INFO_SUBTITLE_CODING_TYPE);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_GetSubtitleInByTrackID_true);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_GetSubtitleInByTrackID_false);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_GetInfo_default);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVDScanfTime_true);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVDScanfFrameRate_true);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVDScanfFrameRate_false);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVDScanfTime_false);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TMPlayerScanfTime_Input_String_003a003a032c13d);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TMPlayerScanfTime_Input_String_003a003a032c23d);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXTScanfTime_input_string_013a023a032e004);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_ScanfTime_Input_String_03a003a002e002c03a003a032e00);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_ChangeSubtitleTrack_case1);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_ChangeSubtitleTrack_case2);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_QueryCurSubtitleTrackIdx_external_subtitle);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_CurSubtitleIsUnicode_TRUE);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_CurSubtitleIsUnicode_FALSE);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_DisableMovieSubtitle_external_TRUE);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_DisableMovieSubtitle_Not_External_TRUE);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_RefreshTextSubtitleTag_case1);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_Subtitle_Parser_TRUE);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_SubtitleParser_Main_E_MPLAYER_SUBTITLE_SRT);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_Subtitle_BinarySearchBuffByCurTime_u32TimeOver);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_Subtitle_BinarySearchBuffByCurTime_u23TimeLower);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SRT_Parser_ASCII);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SRT_Parser_UNICODE);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SSA_Parser_ASCII);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SSA_Parser_UNICODE);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_SetSubtitleAdvanceSteps_Set_Steps_1);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SRT_ParseOneSubtitle_ASCII);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SRT_ParseOneSubtitle_UNICODE);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SSA_ParseOneSubtitle_ASCII);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SSA_ParseOneSubtitle_UNICODE);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVD_Parser_ASCII);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVD_Parser_UNICODE);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_Parser_ASCII);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_Parser_UNICODE);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_Parser_ASCII_NoClassName);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_Parser_UNICODE_NoClassName);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVD_ParseOneSubtitle_ASCII);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVD_ParseOneSubtitle_UNICODE);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_ParseOneSubtitle_ASCII);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_ParseOneSubtitle_UNICODE);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_Parser_ASCII);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_Parser_UNICODE);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_ParseOneSubtitle_ASCII);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_ParseOneSubtitle_UNICODE);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_ParseOneSubtitle_ASCII_Ver10);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_ParseOneSubtitle_UNICODE_Ver10);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TMPlayer_Parser_ASCII);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TMPlayer_Parser_UNICODE);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TMPlayer_ParseOneSubtitle_ASCII);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TMPlayer_ParseOneSubtitle_UNICODE);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_DvdSubtitleSystem_Parser_ASCII);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_DvdSubtitleSystem_Parser_UNICODE);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_DvdSubtitleSystem_ParseOneSubtitle_ASCII);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_DvdSubtitleSystem_ParseOneSubtitle_UNICODE);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SUBIDX_Parser_ASCII);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SUBIDX_Parser_UNICODE);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SUBIDX_ParseOneSubtitle_ASCII);
CPPTEST_TEST(TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SUBIDX_ParseOneSubtitle_UNICODE);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_nupr_Uppercase();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_nupr_Lowercase();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_nupr_Unicode_Uppercase();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_nupr_Unicode_Lowercase();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_ScanDigit_Input_String_123();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_ScanMilliSecond_Input_String_123();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_ScanMilliSecond_Input_String_12();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_ScanHex_Input_String_3aB();
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_SetSubtitleTrackID_TrackID_Lower_than_TrackNum();
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_SetSubtitleTrackID_TrackID_Greater_than_TrackNum();
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_SubtitleInit();
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_SetInternalSubtitle_true();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_ScanfIdxPos_Input_String_0x1234();
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_GetInfo_E_MPLAYER_EXT_SUBTITLE_INFO_NB_TRACK();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_ScanfIdxPos_return_FALSE();
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_GetInfo_E_MPLAYER_EXT_SUBTITLE_INFO_TRACK_ID();
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_GetInfo_E_MPLAYER_EXT_SUBTITLE_INFO_SUBTITLE_TYPE();
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_GetInfo_E_MPLAYER_EXT_SUBTITLE_INFO_SUBTITLE_CODING_TYPE();
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_GetSubtitleInByTrackID_true();
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_GetSubtitleInByTrackID_false();
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_GetInfo_default();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVDScanfTime_true();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVDScanfFrameRate_true();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVDScanfFrameRate_false();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVDScanfTime_false();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TMPlayerScanfTime_Input_String_003a003a032c13d();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TMPlayerScanfTime_Input_String_003a003a032c23d();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXTScanfTime_input_string_013a023a032e004();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_ScanfTime_Input_String_03a003a002e002c03a003a032e00();
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_ChangeSubtitleTrack_case1();
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_ChangeSubtitleTrack_case2();
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_QueryCurSubtitleTrackIdx_external_subtitle();
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_CurSubtitleIsUnicode_TRUE();
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_CurSubtitleIsUnicode_FALSE();
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_DisableMovieSubtitle_external_TRUE();
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_DisableMovieSubtitle_Not_External_TRUE();
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_RefreshTextSubtitleTag_case1();
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_Subtitle_Parser_TRUE();
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_SubtitleParser_Main_E_MPLAYER_SUBTITLE_SRT();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_Subtitle_BinarySearchBuffByCurTime_u32TimeOver();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_Subtitle_BinarySearchBuffByCurTime_u23TimeLower();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SRT_Parser_ASCII();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SRT_Parser_UNICODE();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SSA_Parser_ASCII();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SSA_Parser_UNICODE();
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_SetSubtitleAdvanceSteps_Set_Steps_1();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SRT_ParseOneSubtitle_ASCII();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SRT_ParseOneSubtitle_UNICODE();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SSA_ParseOneSubtitle_ASCII();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SSA_ParseOneSubtitle_UNICODE();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVD_Parser_ASCII();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVD_Parser_UNICODE();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_Parser_ASCII();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_Parser_UNICODE();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_Parser_ASCII_NoClassName();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_Parser_UNICODE_NoClassName();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVD_ParseOneSubtitle_ASCII();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVD_ParseOneSubtitle_UNICODE();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_ParseOneSubtitle_ASCII();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_ParseOneSubtitle_UNICODE();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_Parser_ASCII();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_Parser_UNICODE();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_ParseOneSubtitle_ASCII();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_ParseOneSubtitle_UNICODE();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_ParseOneSubtitle_ASCII_Ver10();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_ParseOneSubtitle_UNICODE_Ver10();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TMPlayer_Parser_ASCII();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TMPlayer_Parser_UNICODE();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TMPlayer_ParseOneSubtitle_ASCII();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TMPlayer_ParseOneSubtitle_UNICODE();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_DvdSubtitleSystem_Parser_ASCII();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_DvdSubtitleSystem_Parser_UNICODE();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_DvdSubtitleSystem_ParseOneSubtitle_ASCII();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_DvdSubtitleSystem_ParseOneSubtitle_UNICODE();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SUBIDX_Parser_ASCII();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SUBIDX_Parser_UNICODE();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SUBIDX_ParseOneSubtitle_ASCII();
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SUBIDX_ParseOneSubtitle_UNICODE();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_mapp_mplayer_subtitle);

void TestSuite_mapp_mplayer_subtitle_setUp()
{
}

void TestSuite_mapp_mplayer_subtitle_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_nupr_Uppercase */
/* CPPTEST_TEST_CASE_CONTEXT void _MApp_MPlayer_nupr(U8 *, U16) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_nupr_Uppercase()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Data) */
    U8 _pu8Data_0  = 'A';
    U8 * _pu8Data  = & _pu8Data_0;
    /* Initializing argument 2 (u16Len) */
    U16 _u16Len  = 1u;
    {
        /* Tested function call */
        _MApp_MPlayer_nupr(_pu8Data, _u16Len);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL('A', ( *_pu8Data ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_nupr_Uppercase */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_nupr_Lowercase */
/* CPPTEST_TEST_CASE_CONTEXT void _MApp_MPlayer_nupr(U8 *, U16) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_nupr_Lowercase()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Data) */
    U8 _pu8Data_1  = 'a';
    U8 * _pu8Data  = & _pu8Data_1;
    /* Initializing argument 2 (u16Len) */
    U16 _u16Len  = 1u;
    {
        /* Tested function call */
        _MApp_MPlayer_nupr(_pu8Data, _u16Len);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL('A', ( *_pu8Data ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_nupr_Lowercase */


/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_nupr_Unicode_Uppercase */
/* CPPTEST_TEST_CASE_CONTEXT void _MApp_MPlayer_nupr_Unicode(U8 *, U16) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_nupr_Unicode_Uppercase()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Data) */
    U8 _pu8Data_3[2]  = {'A',0};;
    U8 * _pu8Data  = & _pu8Data_3;
    /* Initializing argument 2 (u16Len) */
    U16 _u16Len  = 2;
    {
        /* Tested function call */
        _MApp_MPlayer_nupr_Unicode(_pu8Data, _u16Len);
        /* Post-condition check */
        CPPTEST_ASSERT_CSTR_EQUAL("A", ( _pu8Data ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_nupr_Unicode_Uppercase */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_nupr_Unicode_Lowercase */
/* CPPTEST_TEST_CASE_CONTEXT void _MApp_MPlayer_nupr_Unicode(U8 *, U16) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_nupr_Unicode_Lowercase()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Data) */
    U8 _pu8Data_4[2]  = {'a',0};
    U8 * _pu8Data  = & _pu8Data_4;
    /* Initializing argument 2 (u16Len) */
    U16 _u16Len  = 2;
    {
        /* Tested function call */
        _MApp_MPlayer_nupr_Unicode(_pu8Data, _u16Len);
        /* Post-condition check */
        CPPTEST_ASSERT_CSTR_EQUAL("A", ( _pu8Data ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_nupr_Unicode_Lowercase */


/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_ScanDigit_Input_U8_String_123 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_ScanDigit_Input_String_123 */
/* CPPTEST_TEST_CASE_CONTEXT U16 _MApp_MPlayer_ScanDigit(U8 *, U32 *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_ScanDigit_Input_String_123()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Data) */
    U8 _pu8Data_7[4]  = {'1', '2', '3', 0};
    U8 * _pu8Data  = & _pu8Data_7;
    /* Initializing argument 2 (pu32Val) */
    U32 _pu32Val_8  = 0ul;
    U32 * _pu32Val  = & _pu32Val_8;
    {
        /* Tested function call */
        U16 _return  = _MApp_MPlayer_ScanDigit(_pu8Data, _pu32Val);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(3, ( _return ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(123, ( *_pu32Val ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_ScanDigit_Input_String_123 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_ScanMilliSecond_Input_String_123 */
/* CPPTEST_TEST_CASE_CONTEXT U16 _MApp_MPlayer_ScanMilliSecond(U8 *, U32 *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_ScanMilliSecond_Input_String_123()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Data) */
    U8 _pu8Data_0[4]  = {'1', '2', '3', 0};
    U8 * _pu8Data  = & _pu8Data_0[0];
    /* Initializing argument 2 (pu32Val) */
    U32 _pu32Val_1  = 0ul;
    U32 * _pu32Val  = & _pu32Val_1;
    {
        /* Tested function call */
        U16 _return  = _MApp_MPlayer_ScanMilliSecond(_pu8Data, _pu32Val);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(3, ( _return ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(123, ( *_pu32Val ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_ScanMilliSecond_Input_String_123 */


/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_ScanMilliSecond_Input_String_12 */
/* CPPTEST_TEST_CASE_CONTEXT U16 _MApp_MPlayer_ScanMilliSecond(U8 *, U32 *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_ScanMilliSecond_Input_String_12()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Data) */
    U8 _pu8Data_4[4]  = {'1', '2', 0};
    U8 * _pu8Data  = & _pu8Data_4[0];
    /* Initializing argument 2 (pu32Val) */
    U32 _pu32Val_5  = 0ul;
    U32 * _pu32Val  = & _pu32Val_5;
    {
        /* Tested function call */
        U16 _return  = _MApp_MPlayer_ScanMilliSecond(_pu8Data, _pu32Val);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(2, ( _return ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(120, ( *_pu32Val ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_ScanMilliSecond_Input_String_12 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_ScanHex_Input_String_3aB */
/* CPPTEST_TEST_CASE_CONTEXT U16 _MApp_MPlayer_ScanHex(U8 *, U32 *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_ScanHex_Input_String_3aB()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Data) */
    U8 _pu8Data_6[4]  = {'3', 'a', 'B', 0};
    U8 * _pu8Data  = & _pu8Data_6;
    /* Initializing argument 2 (pu32Val) */
    U32 _pu32Val_7  = 0ul;
    U32 * _pu32Val  = & _pu32Val_7;
    {
        /* Tested function call */
        U16 _return  = _MApp_MPlayer_ScanHex(_pu8Data, _pu32Val);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(3, ( _return ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(0x3AB, ( *_pu32Val ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_ScanHex_Input_String_3aB */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_SetSubtitleTrackID_TrackID_Lower_than_TrackNum */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_MPlayer_SetSubtitleTrackID(U8) */
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_SetSubtitleTrackID_TrackID_Lower_than_TrackNum()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8TrackId) */
    U8 _u8TrackId  = 1;
    /* Initializing global variable m_u8SubtitleTrackNum */
    {
         m_u8SubtitleTrackNum  = 2;
    }
    /* Initializing global variable m_u8CurTrackIdx */
    {
         m_u8CurTrackIdx  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_MPlayer_SetSubtitleTrackID(_u8TrackId);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( m_u8CurTrackIdx ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_SetSubtitleTrackID_TrackID_Lower_than_TrackNum */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_SetSubtitleTrackID_TrackID_Greater_than_TrackNum */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_MPlayer_SetSubtitleTrackID(U8) */
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_SetSubtitleTrackID_TrackID_Greater_than_TrackNum()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8TrackId) */
    U8 _u8TrackId  = 2;
    /* Initializing global variable m_u8SubtitleTrackNum */
    {
         m_u8SubtitleTrackNum  = 2;
    }
    /* Initializing global variable m_u8CurTrackIdx */
    {
         m_u8CurTrackIdx  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_MPlayer_SetSubtitleTrackID(_u8TrackId);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_SetSubtitleTrackID_TrackID_Greater_than_TrackNum */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_SubtitleInit */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_MPlayer_SubtitleInit(void) */
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_SubtitleInit()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_u32MicroDVDFrameRate */
    {
         m_u32MicroDVDFrameRate  = 0ul;
    }
    /* Initializing global variable m_u16SubtitleTagCount */
    {
         m_u16SubtitleTagCount  = 0u;
    }
    /* Initializing global variable m_u8SubtitleTrackNum */
    {
         m_u8SubtitleTrackNum  = 0;
    }
    /* Initializing global variable m_u32SubtitleDelaySteps */
    {
         m_u32SubtitleDelaySteps  = 0ul;
    }
    /* Initializing global variable m_u32SubtitleAdvanceSteps */
    {
         m_u32SubtitleAdvanceSteps  = 0ul;
    }
    /* Initializing global variable m_u8CurTrackIdx */
    {
         m_u8CurTrackIdx  = 0;
    }
    /* Initializing global variable m_bIsUnicode */
    {
         m_bIsUnicode  = 0;
    }
    /* Initializing global variable m_eType */
    {
         m_eType  = E_MPLAYER_SUBTITLE_SRT;
    }
    {
        /* Tested function call */
        MApp_MPlayer_SubtitleInit();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_MPLAYER_SUBTITLE_INVALID, ( m_eType ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_SubtitleInit */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_SetInternalSubtitle_true */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_MPlayer_SetInternalSubtitle(BOOLEAN) */
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_SetInternalSubtitle_true()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bEnable) */
    U8 _bEnable  = 1;
    /* Initializing global variable m_bInternalSubtitle */
    {
         m_bInternalSubtitle  = 0;
    }
    {
        /* Tested function call */
        MApp_MPlayer_SetInternalSubtitle(_bEnable);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( m_bInternalSubtitle ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_SetInternalSubtitle_true */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_ScanfIdxPos_Input_String_0x1234 */
/* CPPTEST_TEST_CASE_CONTEXT U32 _MApp_MPlayer_ScanfIdxPos(U8 *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_ScanfIdxPos_Input_String_0x1234()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Data) */
    U8 _pu8Data_8  = 0;
    U8 * _pu8Data  = & _pu8Data_8;
    {
        /* Tested function call */
        U32 _return  = _MApp_MPlayer_ScanfIdxPos(_pu8Data);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0x1234, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_ScanfIdxPos_Input_String_0x1234 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_GetInfo_E_MPLAYER_EXT_SUBTITLE_INFO_NB_TRACK */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_MPlayer_GetInfo(enumExtSutitleInfo) */
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_GetInfo_E_MPLAYER_EXT_SUBTITLE_INFO_NB_TRACK()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eInfo) */
    enumExtSutitleInfo _eInfo  = E_MPLAYER_EXT_SUBTITLE_INFO_NB_TRACK;
    /* Initializing global variable m_u8SubtitleTrackNum */
    {
         m_u8SubtitleTrackNum  = 1;
    }
    /* Initializing global variable m_u8CurTrackIdx */
    {
         m_u8CurTrackIdx  = 0;
    }
    {
        /* Tested function call */
        U32 _return  = MApp_MPlayer_GetInfo(_eInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_GetInfo_E_MPLAYER_EXT_SUBTITLE_INFO_NB_TRACK */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_ScanfIdxPos_return_FALSE */
/* CPPTEST_TEST_CASE_CONTEXT U32 _MApp_MPlayer_ScanfIdxPos(U8 *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_ScanfIdxPos_return_FALSE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Data) */
    U8 _pu8Data_9  = 0;
    U8 * _pu8Data  = & _pu8Data_9;
    {
        /* Tested function call */
        U32 _return  = _MApp_MPlayer_ScanfIdxPos(_pu8Data);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0ul, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_ScanfIdxPos_return_FALSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_GetInfo_E_MPLAYER_EXT_SUBTITLE_INFO_TRACK_ID */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_MPlayer_GetInfo(enumExtSutitleInfo) */
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_GetInfo_E_MPLAYER_EXT_SUBTITLE_INFO_TRACK_ID()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eInfo) */
    enumExtSutitleInfo _eInfo  = E_MPLAYER_EXT_SUBTITLE_INFO_TRACK_ID;
    /* Initializing global variable m_u8SubtitleTrackNum */
    {
         m_u8SubtitleTrackNum  = 0;
    }
    /* Initializing global variable m_u8CurTrackIdx */
    {
         m_u8CurTrackIdx  = 1;
    }
    {
        /* Tested function call */
        U32 _return  = MApp_MPlayer_GetInfo(_eInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1ul, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_GetInfo_E_MPLAYER_EXT_SUBTITLE_INFO_TRACK_ID */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_GetInfo_E_MPLAYER_EXT_SUBTITLE_INFO_SUBTITLE_TYPE */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_MPlayer_GetInfo(enumExtSutitleInfo) */
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_GetInfo_E_MPLAYER_EXT_SUBTITLE_INFO_SUBTITLE_TYPE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eInfo) */
    enumExtSutitleInfo _eInfo  = E_MPLAYER_EXT_SUBTITLE_INFO_SUBTITLE_TYPE;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].eSubtitleType = E_MPLAYER_SUBTITLE_SMI;
    /* Initializing global variable m_u8SubtitleTrackNum */
    {
         m_u8SubtitleTrackNum  = 0;
    }
    /* Initializing global variable m_u8CurTrackIdx */
    {
         m_u8CurTrackIdx  = 0;
    }
    {
        /* Tested function call */
        U32 _return  = MApp_MPlayer_GetInfo(_eInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(E_MPLAYER_SUBTITLE_SMI, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_GetInfo_E_MPLAYER_EXT_SUBTITLE_INFO_SUBTITLE_TYPE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_GetInfo_E_MPLAYER_EXT_SUBTITLE_INFO_SUBTITLE_CODING_TYPE */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_MPlayer_GetInfo(enumExtSutitleInfo) */
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_GetInfo_E_MPLAYER_EXT_SUBTITLE_INFO_SUBTITLE_CODING_TYPE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eInfo) */
    enumExtSutitleInfo _eInfo  = E_MPLAYER_EXT_SUBTITLE_INFO_SUBTITLE_CODING_TYPE;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].eSubtitleCodingType = E_MPLAYER_SUBTITLE_CODING_UNICODE;
    /* Initializing global variable m_u8SubtitleTrackNum */
    {
         m_u8SubtitleTrackNum  = 0;
    }
    /* Initializing global variable m_u8CurTrackIdx */
    {
         m_u8CurTrackIdx  = 0;
    }
    {
        /* Tested function call */
        U32 _return  = MApp_MPlayer_GetInfo(_eInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(E_MPLAYER_SUBTITLE_CODING_UNICODE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_GetInfo_E_MPLAYER_EXT_SUBTITLE_INFO_SUBTITLE_CODING_TYPE */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_GetSubtitleInByTrackID_true */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_MPlayer_GetSubtitleInByTrackID(U8, MPlayerSubtitleInfo *) */
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_GetSubtitleInByTrackID_true()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8TrackId) */
    U8 _u8TrackId  = 0;
    /* Initializing argument 2 (pInfo) */
    MPlayerSubtitleInfo _pInfo_0 ;
    MPlayerSubtitleInfo * _pInfo  = & _pInfo_0;
    /* Initializing global variable m_u8SubtitleTrackNum */
    {
         m_u8SubtitleTrackNum  = 1;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_MPlayer_GetSubtitleInByTrackID(_u8TrackId, _pInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_GetSubtitleInByTrackID_true */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_GetSubtitleInByTrackID_false */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_MPlayer_GetSubtitleInByTrackID(U8, MPlayerSubtitleInfo *) */
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_GetSubtitleInByTrackID_false()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8TrackId) */
    U8 _u8TrackId  = 0;
    /* Initializing argument 2 (pInfo) */
    MPlayerSubtitleInfo _pInfo_1 ;
    MPlayerSubtitleInfo * _pInfo  = & _pInfo_1;
    /* Initializing global variable m_u8SubtitleTrackNum */
    {
         m_u8SubtitleTrackNum  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_MPlayer_GetSubtitleInByTrackID(_u8TrackId, _pInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_GetSubtitleInByTrackID_false */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_GetInfo_default */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_MPlayer_GetInfo(enumExtSutitleInfo) */
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_GetInfo_default()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eInfo) */
    enumExtSutitleInfo _eInfo  = -1;
    /* Initializing global variable m_u8SubtitleTrackNum */
    {
         m_u8SubtitleTrackNum  = 0;
    }
    /* Initializing global variable m_u8CurTrackIdx */
    {
         m_u8CurTrackIdx  = 0;
    }
    {
        /* Tested function call */
        U32 _return  = MApp_MPlayer_GetInfo(_eInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0ul, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_GetInfo_default */


/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_MicroDVDScanfTime_true */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_MicroDVDScanfTime(U8 *, U32 *, U32 *, U32 *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVDScanfTime_true()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Data) */
    U8 _pu8Data_6[]  = {'{','1','}','{','1','}'};
    U8 * _pu8Data  = & _pu8Data_6;
    /* Initializing argument 2 (pu32Index) */
    U32 _pu32Index_7  = 0ul;
    U32 * _pu32Index  = & _pu32Index_7;
    /* Initializing argument 3 (pu32Start) */
    U32 _pu32Start_8  = 0ul;
    U32 * _pu32Start  = & _pu32Start_8;
    /* Initializing argument 4 (pu32End) */
    U32 _pu32End_9  = 0ul;
    U32 * _pu32End  = & _pu32End_9;
    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_MPlayer_MicroDVDScanfTime(_pu8Data, _pu32Index, _pu32Start, _pu32End);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( *_pu32Start ));
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( *_pu32End ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_MicroDVDScanfTime_true */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_MicroDVDScanfFrameRate_true */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_MicroDVDScanfFrameRate(U8 *, U32 *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVDScanfFrameRate_true()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Data) */
    U8 _pu8Data_10[]  = {'2','5','.','0','0'};
    U8 * _pu8Data  = & _pu8Data_10;
    /* Initializing argument 2 (pu32FrameRate) */
    U32 _pu32FrameRate_11  = 0ul;
    U32 * _pu32FrameRate  = & _pu32FrameRate_11;
    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_MPlayer_MicroDVDScanfFrameRate(_pu8Data, _pu32FrameRate);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(25000, ( *_pu32FrameRate ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_MicroDVDScanfFrameRate_true */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_MicroDVDScanfFrameRate_false */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_MicroDVDScanfFrameRate(U8 *, U32 *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVDScanfFrameRate_false()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Data) */
    U8 _pu8Data_12  = 0;
    U8 * _pu8Data  = & _pu8Data_12;
    /* Initializing argument 2 (pu32FrameRate) */
    U32 _pu32FrameRate_13  = 0ul;
    U32 * _pu32FrameRate  = & _pu32FrameRate_13;
    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_MPlayer_MicroDVDScanfFrameRate(_pu8Data, _pu32FrameRate);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_MicroDVDScanfFrameRate_false */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_MicroDVDScanfTime_false */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_MicroDVDScanfTime(U8 *, U32 *, U32 *, U32 *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVDScanfTime_false()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Data) */
    U8 _pu8Data_14[] = {'{'};
    U8 * _pu8Data  = & _pu8Data_14;
    /* Initializing argument 2 (pu32Index) */
    U32 _pu32Index_15  = 0ul;
    U32 * _pu32Index  = & _pu32Index_15;
    /* Initializing argument 3 (pu32Start) */
    U32 _pu32Start_16  = 0ul;
    U32 * _pu32Start  = & _pu32Start_16;
    /* Initializing argument 4 (pu32End) */
    U32 _pu32End_17  = 0ul;
    U32 * _pu32End  = & _pu32End_17;
    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_MPlayer_MicroDVDScanfTime(_pu8Data, _pu32Index, _pu32Start, _pu32End);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_MicroDVDScanfTime_false */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_TMPlayerScanfTime_Input_String_003a003a032c13d */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_MPlayer_TMPlayerScanfTime(U8 *, U32 *, U32 *, U32 *, U8) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TMPlayerScanfTime_Input_String_003a003a032c13d()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Data) */
    U8 _pu8Data_0[]  = {'0','0',':','0','0',':','0','3',',','1','='};
    U8 * _pu8Data  = & _pu8Data_0;
    /* Initializing argument 2 (pu32Hour1) */
    U32 _pu32Hour1_1  = 0ul;
    U32 * _pu32Hour1  = & _pu32Hour1_1;
    /* Initializing argument 3 (pu32Min1) */
    U32 _pu32Min1_2  = 0ul;
    U32 * _pu32Min1  = & _pu32Min1_2;
    /* Initializing argument 4 (pu32Second1) */
    U32 _pu32Second1_3  = 0ul;
    U32 * _pu32Second1  = & _pu32Second1_3;
    /* Initializing argument 5 (u8Line) */
    U8 _u8Line  = 1;
    {
        /* Tested function call */
        U8 _return  = _MApp_MPlayer_TMPlayerScanfTime(_pu8Data, _pu32Hour1, _pu32Min1, _pu32Second1, _u8Line);
        /* Post-condition check */
         CPPTEST_ASSERT_UINTEGER_EQUAL(3, ( _pu32Second1_3 ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_TMPlayerScanfTime_Input_String_003a003a032c13d */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_TMPlayerScanfTime_Input_String_003a003a032c23d */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_MPlayer_TMPlayerScanfTime(U8 *, U32 *, U32 *, U32 *, U8) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TMPlayerScanfTime_Input_String_003a003a032c23d()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Data) */
    U8 _pu8Data_4[]  = {'0','0',':','0','0',':','0','3',',','2','='};
    U8 * _pu8Data  = & _pu8Data_4;
    /* Initializing argument 2 (pu32Hour1) */
    U32 _pu32Hour1_5  = 0ul;
    U32 * _pu32Hour1  = & _pu32Hour1_5;
    /* Initializing argument 3 (pu32Min1) */
    U32 _pu32Min1_6  = 0ul;
    U32 * _pu32Min1  = & _pu32Min1_6;
    /* Initializing argument 4 (pu32Second1) */
    U32 _pu32Second1_7  = 0ul;
    U32 * _pu32Second1  = & _pu32Second1_7;
    /* Initializing argument 5 (u8Line) */
    U8 _u8Line  = 0;
    {
        /* Tested function call */
        U8 _return  = _MApp_MPlayer_TMPlayerScanfTime(_pu8Data, _pu32Hour1, _pu32Min1, _pu32Second1, _u8Line);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(3, ( _pu32Second1_7 ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_TMPlayerScanfTime_Input_String_003a003a032c23d */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_TTXTScanfTime_input_string_013a023a032e004 */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_MPlayer_TTXTScanfTime(U8 *, U32 *, U32 *, U32 *, U32 *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXTScanfTime_input_string_013a023a032e004()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Data) */
    U8 _pu8Data_0[]  = {'0','1',':','0','2',':','0','3',',','0','0','4'};
    U8 * _pu8Data  = & _pu8Data_0;
    /* Initializing argument 2 (pu32Hour1) */
    U32 _pu32Hour1_1  = 0ul;
    U32 * _pu32Hour1  = & _pu32Hour1_1;
    /* Initializing argument 3 (pu32Min1) */
    U32 _pu32Min1_2  = 0ul;
    U32 * _pu32Min1  = & _pu32Min1_2;
    /* Initializing argument 4 (pu32Second1) */
    U32 _pu32Second1_3  = 0ul;
    U32 * _pu32Second1  = & _pu32Second1_3;
    /* Initializing argument 5 (pu32ms1) */
    U32 _pu32ms1_4  = 0ul;
    U32 * _pu32ms1  = & _pu32ms1_4;
    {
        /* Tested function call */
        U8 _return  = _MApp_MPlayer_TTXTScanfTime(_pu8Data, _pu32Hour1, _pu32Min1, _pu32Second1, _pu32ms1);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(3, ( _pu32Second1_3 ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_TTXTScanfTime_input_string_013a023a032e004 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_ScanfTime_Input_String_03a003a002e002c03a003a032e00 */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_MPlayer_ScanfTime(U8 *, U32 *, U32 *, U32 *, U32 *, U32 *, U32 *, U32 *, U32 *, U8 *, U8, U8) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_ScanfTime_Input_String_03a003a002e002c03a003a032e00()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Data) */
    U8 _pu8Data_5[]  = "0:00:00.00,0:00:03.00";
    U8 * _pu8Data  = & _pu8Data_5;
    /* Initializing argument 2 (pu32Hour1) */
    U32 _pu32Hour1_6  = 0ul;
    U32 * _pu32Hour1  = & _pu32Hour1_6;
    /* Initializing argument 3 (pu32Min1) */
    U32 _pu32Min1_7  = 0ul;
    U32 * _pu32Min1  = & _pu32Min1_7;
    /* Initializing argument 4 (pu32Second1) */
    U32 _pu32Second1_8  = 0ul;
    U32 * _pu32Second1  = & _pu32Second1_8;
    /* Initializing argument 5 (pu32ms1) */
    U32 _pu32ms1_9  = 0ul;
    U32 * _pu32ms1  = & _pu32ms1_9;
    /* Initializing argument 6 (pu32Hour2) */
    U32 _pu32Hour2_10  = 0ul;
    U32 * _pu32Hour2  = & _pu32Hour2_10;
    /* Initializing argument 7 (pu32Min2) */
    U32 _pu32Min2_11  = 0ul;
    U32 * _pu32Min2  = & _pu32Min2_11;
    /* Initializing argument 8 (pu32Second2) */
    U32 _pu32Second2_12  = 0ul;
    U32 * _pu32Second2  = & _pu32Second2_12;
    /* Initializing argument 9 (pu32ms2) */
    U32 _pu32ms2_13  = 0ul;
    U32 * _pu32ms2  = & _pu32ms2_13;
    /* Initializing argument 10 (pu8Dividor) */
    U8 _pu8Dividor_14[]  = ",";
    U8 * _pu8Dividor  = & _pu8Dividor_14;
    /* Initializing argument 11 (u8Dot) */
    U8 _u8Dot  = '.';
    /* Initializing argument 12 (u8TimeStampNum) */
    U8 _u8TimeStampNum  = 2;
    {
        /* Tested function call */
        U8 _return  = _MApp_MPlayer_ScanfTime(_pu8Data, _pu32Hour1, _pu32Min1, _pu32Second1, _pu32ms1, _pu32Hour2, _pu32Min2, _pu32Second2, _pu32ms2, _pu8Dividor, _u8Dot, _u8TimeStampNum);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(3, ( _pu32Second2_12 ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_ScanfTime_Input_String_03a003a002e002c03a003a032e00 */



/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_ChangeSubtitleTrack_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_MPlayer_ChangeSubtitleTrack(U8) */
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_ChangeSubtitleTrack_case1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8TrackId) */
    U8 _u8TrackId  = 0;
    /* Initializing global variable m_u8CurTrackIdx */
    {
         m_u8CurTrackIdx  = 0;
    }
    /* Initializing global variable m_Subtitle_Tag */
    {
         m_Subtitle_Tag.u32TimeStart  = 0ul;
         m_Subtitle_Tag.u32TimeEnd  = 0ul;
         m_Subtitle_Tag.u32SubtitlePos  = 0ul;
    }
    /* Initializing global variable m_eSubtitleCodingType */
    {
         m_eSubtitleCodingType  = E_MPLAYER_SUBTITLE_CODING_ASC;
    }
    /* Initializing global variable m_u32NextExternalSubtitleStartTime */
    {
         m_u32NextExternalSubtitleStartTime  = 0ul;
    }
    /* Initializing global variable u32VDPlayerStreamHandleIdx_ExternalSubtitleSUB */
    {
         u32VDPlayerStreamHandleIdx_ExternalSubtitleSUB  = 0ul;
    }
    /* Initializing global variable m_u16ExternalSubtitleIdx */
    {
         m_u16ExternalSubtitleIdx  = 0u;
    }
    /* Initializing global variable m_eExternalSubtitleType */
    {
         m_eExternalSubtitleType  = E_MPLAYER_SUBTITLE_SRT;
    }
    /* Initializing global variable eSubtitleFlag */
    {
         eSubtitleFlag  = E_SUBTITLE_FLG_SUBTITLE_EXTERNAL;
    }
    /* Initializing global variable m_u8SubtitleTrackNum */
    {
         m_u8SubtitleTrackNum  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_MPlayer_ChangeSubtitleTrack(_u8TrackId);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_ChangeSubtitleTrack_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_ChangeSubtitleTrack_case2 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_MPlayer_ChangeSubtitleTrack(U8) */
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_ChangeSubtitleTrack_case2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8TrackId) */
    U8 _u8TrackId  = 0;
    /* Initializing global variable m_u8CurTrackIdx */
    {
         m_u8CurTrackIdx  = 0;
    }
    /* Initializing global variable m_Subtitle_Tag */
    {
         m_Subtitle_Tag.u32TimeStart  = 0ul;
         m_Subtitle_Tag.u32TimeEnd  = 0ul;
         m_Subtitle_Tag.u32SubtitlePos  = 0ul;
    }
    /* Initializing global variable m_eSubtitleCodingType */
    {
         m_eSubtitleCodingType  = E_MPLAYER_SUBTITLE_CODING_ASC;
    }
    /* Initializing global variable m_u32NextExternalSubtitleStartTime */
    {
         m_u32NextExternalSubtitleStartTime  = 0ul;
    }
    /* Initializing global variable u32VDPlayerStreamHandleIdx_ExternalSubtitleSUB */
    {
         u32VDPlayerStreamHandleIdx_ExternalSubtitleSUB  = 0ul;
    }
    /* Initializing global variable m_u16ExternalSubtitleIdx */
    {
         m_u16ExternalSubtitleIdx  = 0u;
    }
    /* Initializing global variable m_eExternalSubtitleType */
    {
         m_eExternalSubtitleType  = E_MPLAYER_SUBTITLE_SRT;
    }
    /* Initializing global variable eSubtitleFlag */
    {
         eSubtitleFlag  = E_SUBTITLE_FLG_INTL_SUBTITLE_FIRST;
    }
    /* Initializing global variable m_u8SubtitleTrackNum */
    {
         m_u8SubtitleTrackNum  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_MPlayer_ChangeSubtitleTrack(_u8TrackId);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_ChangeSubtitleTrack_case2 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_QueryCurSubtitleTrackIdx_external_subtitle */
/* CPPTEST_TEST_CASE_CONTEXT U16 MApp_MPlayer_QueryCurSubtitleTrackIdx(void) */
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_QueryCurSubtitleTrackIdx_external_subtitle()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_u8CurTrackIdx */
    {
         m_u8CurTrackIdx  = 1;
    }
    /* Initializing global variable eSubtitleFlag */
    {
         eSubtitleFlag  = E_SUBTITLE_FLG_SUBTITLE_EXTERNAL;
    }
    /* Initializing global variable m_u8SubtitleTrackNum */
    {
         m_u8SubtitleTrackNum  = 0;
    }
    {
        /* Tested function call */
        U16 _return  = MApp_MPlayer_QueryCurSubtitleTrackIdx();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_QueryCurSubtitleTrackIdx_external_subtitle */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_CurSubtitleIsUnicode_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_MPlayer_CurSubtitleIsUnicode(void) */
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_CurSubtitleIsUnicode_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing global variable _geNotifyAP */
    {
         _geNotifyAP  = E_SUBTITLE_NOTIFY_AP_UNICODE;
    }
    /* Initializing global variable m_eSubtitleCodingType */
    {
         m_eSubtitleCodingType  = E_MPLAYER_SUBTITLE_CODING_ASC;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_MPlayer_CurSubtitleIsUnicode();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_CurSubtitleIsUnicode_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_CurSubtitleIsUnicode_FALSE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_MPlayer_CurSubtitleIsUnicode(void) */
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_CurSubtitleIsUnicode_FALSE()
{
    /* Pre-condition initialization */
    /* Initializing global variable _geNotifyAP */
    {
         _geNotifyAP  = E_SUBTITLE_NOTIFY_AP_NULL;
    }
    /* Initializing global variable m_eSubtitleCodingType */
    {
         m_eSubtitleCodingType  = E_MPLAYER_SUBTITLE_CODING_ASC;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_MPlayer_CurSubtitleIsUnicode();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_CurSubtitleIsUnicode_FALSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_DisableMovieSubtitle_external_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_MPlayer_DisableMovieSubtitle(void) */
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_DisableMovieSubtitle_external_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing global variable eSubtitleFlag */
    {
         eSubtitleFlag  = E_SUBTITLE_FLG_SUBTITLE_EXTERNAL| E_SUBTITLE_FLG_SUBTITLE_SHOWN;
    }
    /* Initializing global variable _geNotifyAP */
    {
         _geNotifyAP  = E_SUBTITLE_NOTIFY_AP_NULL;
    }
    /* Initializing global variable m_eExternalSubtitleType */
    {
         m_eExternalSubtitleType  = E_MPLAYER_SUBTITLE_SRT;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_MPlayer_DisableMovieSubtitle();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_DisableMovieSubtitle_external_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_DisableMovieSubtitle_Not_External_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_MPlayer_DisableMovieSubtitle(void) */
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_DisableMovieSubtitle_Not_External_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing global variable eSubtitleFlag */
    {
         eSubtitleFlag  = E_SUBTITLE_FLG_INTL_SUBTITLE_FIRST;
    }
    /* Initializing global variable _gfnSubtitle */
    {
         _gfnSubtitle  = 0 ;
    }
    /* Initializing global variable _geNotifyAP */
    {
         _geNotifyAP  = E_SUBTITLE_NOTIFY_AP_NULL;
    }
    /* Initializing global variable m_eExternalSubtitleType */
    {
         m_eExternalSubtitleType  = E_MPLAYER_SUBTITLE_SRT;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_MPlayer_DisableMovieSubtitle();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_DisableMovieSubtitle_Not_External_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_RefreshTextSubtitleTag_case1 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_MPlayer_RefreshTextSubtitleTag(U32) */
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_RefreshTextSubtitleTag_case1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Time) */
    U32 _u32Time  = 1ul;
    /* Initializing global variable m_u32PreMovieTimer */
    {
         m_u32PreMovieTimer  = 1ul;
    }
    /* Initializing global variable m_s32PreSubtitleIdx */
    {
         m_s32PreSubtitleIdx  = 1L;
    }
    /* Initializing global variable m_s32DeadSubtitleIdx */
    {
         m_s32DeadSubtitleIdx  = 0L;
    }
    /* Initializing global variable m_u16SubtitleEndPos */
    {
         m_u16SubtitleEndPos  = 1u;
    }
    /* Initializing global variable m_u16SubtitleTagCnt */
    {
         m_u16SubtitleTagCnt  = 2u;
    }

    {
        /* Tested function call */
        MApp_MPlayer_RefreshTextSubtitleTag(_u32Time);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( m_u16SubtitleTagCnt ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_RefreshTextSubtitleTag_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_Subtitle_Parser_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_MPlayer_Subtitle_Parser(enumMPlayerSubtitleType *, U32, enumMplayerSubtitleCoding *) */
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_Subtitle_Parser_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (peType) */
    enumMPlayerSubtitleType _peType_0  = E_MPLAYER_SUBTITLE_SRT;
    enumMPlayerSubtitleType * _peType  = & _peType_0;
    /* Initializing argument 2 (u32FileSize) */
    U32 _u32FileSize  = 1ul;
    /* Initializing argument 3 (pCodingType) */
    enumMplayerSubtitleCoding _pCodingType_1  = E_MPLAYER_SUBTITLE_CODING_ASC;
    enumMplayerSubtitleCoding * _pCodingType  = & _pCodingType_1;
    /* Initializing global variable m_u16SubtitleTagCount */
    {
         m_u16SubtitleTagCount  = 0u;
    }
    /* Initializing global variable m_u32CurSubtitleFilePos */
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable FileEntrySubtitle */
    {
         FileEntrySubtitle.EntryType  = ENTRY_TYPE_FILE;
         FileEntrySubtitle.EntryFileLength  = 0ul;
         FileEntrySubtitle.EntrySeconds  = 0ul;
         FileEntrySubtitle.EnvironmentID  = 0;
         FileEntrySubtitle.FileSystemID  = 0;
         FileEntrySubtitle.EntryAttrib  = 0;
    }
    /* Initializing global variable m_u8SubtitleTrackNum */
    {
         m_u8SubtitleTrackNum  = 1;
    }
    /* Initializing global variable m_u32MicroDVDFrameRate */
    {
         m_u32MicroDVDFrameRate  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_MPlayer_Subtitle_Parser(_peType, _u32FileSize, _pCodingType);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1u, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_Subtitle_Parser_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_SubtitleParser_Main_E_MPLAYER_SUBTITLE_SRT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_MPlayer_SubtitleParser_Main(U32) */
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_SubtitleParser_Main_E_MPLAYER_SUBTITLE_SRT()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Time) */
    U32 _u32Time  = 0ul;
    /* Initializing global variable m_u32PreMovieTimer */
    {
         m_u32PreMovieTimer  = 0ul;
    }
    /* Initializing global variable m_s32PreSubtitleIdx */
    {
         m_s32PreSubtitleIdx  = 0L;
    }
    /* Initializing global variable m_s32DeadSubtitleIdx */
    {
         m_s32DeadSubtitleIdx  = 0L;
    }
    /* Initializing global variable m_u16SubtitleEndPos */
    {
         m_u16SubtitleEndPos  = 0u;
    }
    /* Initializing global variable m_u16SubtitleTagCnt */
    {
         m_u16SubtitleTagCnt  = 15u;
    }
    /* Initializing global variable m_u8ExternalSubtitleFileHandle */
    {
         m_u8ExternalSubtitleFileHandle  = 0;
    }
    /* Initializing global variable m_bIsReadBufferEmpty */
    {
         m_bIsReadBufferEmpty  = 0;
    }
    /* Initializing global variable m_u16SubtitleTagCount */
    {
         m_u16SubtitleTagCount  = 0u;
    }
    /* Initializing global variable m_u32CurSubtitleFilePos */
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable m_u32SubtitleBufParsed */
    {
         m_u32SubtitleBufParsed  = 0ul;
    }
    /* Initializing global variable m_u8SubtitleTrackNum */
    {
         m_u8SubtitleTrackNum  = 1;
    }
    /* Initializing global variable m_u8CurTrackIdx */
    {
         m_u8CurTrackIdx  = 0;
    }
    /* Initializing global variable m_u32MicroDVDFrameRate */
    {
         m_u32MicroDVDFrameRate  = 0ul;
    }

    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].eSubtitleType = E_MPLAYER_SUBTITLE_SRT;
    m_astExternalTextSubtitleTag[0].u32TimeEnd = 2;
    m_astExternalTextSubtitleTag[1].u32TimeEnd = 3;

    {
        /* Tested function call */
        MApp_MPlayer_SubtitleParser_Main(_u32Time);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(16, ( m_u16SubtitleTagCnt ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_SubtitleParser_Main_E_MPLAYER_SUBTITLE_SRT */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_Subtitle_BinarySearchBuffByCurTime_u32TimeOver */
/* CPPTEST_TEST_CASE_CONTEXT U16 _MApp_MPlayer_Subtitle_BinarySearchBuffByCurTime(U32) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_Subtitle_BinarySearchBuffByCurTime_u32TimeOver()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Time) */
    U32 _u32Time  = 0;
    /* Initializing global variable m_u8CurTrackIdx */
    {
         m_u8CurTrackIdx  = 0;
    }

    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].u16SubtitleTagStart=0;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].u16SubtitleTagEnd =1;

    {
        /* Tested function call */
        U16 _return  = _MApp_MPlayer_Subtitle_BinarySearchBuffByCurTime(_u32Time);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_Subtitle_BinarySearchBuffByCurTime_u32TimeOver */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_Subtitle_BinarySearchBuffByCurTime_u23TimeLower */
/* CPPTEST_TEST_CASE_CONTEXT U16 _MApp_MPlayer_Subtitle_BinarySearchBuffByCurTime(U32) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_Subtitle_BinarySearchBuffByCurTime_u23TimeLower()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Time) */
    U32 _u32Time  = 5ul;
    /* Initializing global variable m_u8CurTrackIdx */
    {
         m_u8CurTrackIdx  = 0;
    }
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].u16SubtitleTagStart=0;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].u16SubtitleTagEnd =2;
    {
        /* Tested function call */
        U16 _return  = _MApp_MPlayer_Subtitle_BinarySearchBuffByCurTime(_u32Time);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(2u, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_Subtitle_BinarySearchBuffByCurTime_u23TimeLower */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_SRT_Parser_ASCII */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_SRT_Parser(U32, enumMplayerSubtitleCoding *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SRT_Parser_ASCII()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FileSize) */
    U32 _u32FileSize  = 39ul;
    /* Initializing argument 2 (pCodingType) */
    enumMplayerSubtitleCoding _pCodingType_0  = E_MPLAYER_SUBTITLE_CODING_ASC;
    enumMplayerSubtitleCoding * _pCodingType  = & _pCodingType_0;
    /* Initializing global variable m_u16SubtitleTagCount */
    {
         m_u16SubtitleTagCount  = 0u;
    }
    /* Initializing global variable m_u32CurSubtitleFilePos */
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */
    {
         m_u8FileNo  = 0;
    }
    /* Initializing global variable FileEntrySubtitle */
    {
         FileEntrySubtitle.EntryType  = ENTRY_TYPE_FILE;
         FileEntrySubtitle.EntryFileLength  = 0ul;
         FileEntrySubtitle.EntrySeconds  = 0ul;
         FileEntrySubtitle.EnvironmentID  = 0;
         FileEntrySubtitle.FileSystemID  = 0;
         FileEntrySubtitle.EntryAttrib  = 0;
    }
    /* Initializing global variable m_u8SubtitleTrackNum */
    {
         m_u8SubtitleTrackNum  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_MPlayer_SRT_Parser(_u32FileSize, _pCodingType);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1u, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_SRT_Parser_ASCII */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_SRT_Parser_UNICODE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_SRT_Parser(U32, enumMplayerSubtitleCoding *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SRT_Parser_UNICODE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FileSize) */
    U32 _u32FileSize  = 78;
    /* Initializing argument 2 (pCodingType) */
    enumMplayerSubtitleCoding _pCodingType_0  = E_MPLAYER_SUBTITLE_CODING_ASC;
    enumMplayerSubtitleCoding * _pCodingType  = & _pCodingType_0;
    /* Initializing global variable m_u16SubtitleTagCount */
    {
         m_u16SubtitleTagCount  = 0u;
    }
    /* Initializing global variable m_u32CurSubtitleFilePos */
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable m_u8SubtitleTrackNum */
    {
         m_u8SubtitleTrackNum  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_MPlayer_SRT_Parser(_u32FileSize, _pCodingType);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_SRT_Parser_UNICODE */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_SSA_Parser_ASCII */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_SSA_Parser(U32, enumMplayerSubtitleCoding *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SSA_Parser_ASCII()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FileSize) */
    U32 _u32FileSize  = 70ul;
    /* Initializing argument 2 (pCodingType) */
    enumMplayerSubtitleCoding _pCodingType_1  = E_MPLAYER_SUBTITLE_CODING_ASC;
    enumMplayerSubtitleCoding * _pCodingType  = & _pCodingType_1;
    /* Initializing global variable m_u16SubtitleTagCount */
    {
         m_u16SubtitleTagCount  = 0u;
    }
    /* Initializing global variable m_u32CurSubtitleFilePos */
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable m_u8SubtitleTrackNum */
    {
         m_u8SubtitleTrackNum  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_MPlayer_SSA_Parser(_u32FileSize, _pCodingType);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_SSA_Parser_ASCII */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_SSA_Parser_UNICODE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_SSA_Parser(U32, enumMplayerSubtitleCoding *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SSA_Parser_UNICODE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FileSize) */
    U32 _u32FileSize  = 144ul;
    /* Initializing argument 2 (pCodingType) */
    enumMplayerSubtitleCoding _pCodingType_2  = E_MPLAYER_SUBTITLE_CODING_ASC;
    enumMplayerSubtitleCoding * _pCodingType  = & _pCodingType_2;
    /* Initializing global variable m_u16SubtitleTagCount */
    {
         m_u16SubtitleTagCount  = 0u;
    }
    /* Initializing global variable m_u32CurSubtitleFilePos */
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable m_u8SubtitleTrackNum */
    {
         m_u8SubtitleTrackNum  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_MPlayer_SSA_Parser(_u32FileSize, _pCodingType);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_SSA_Parser_UNICODE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_SetSubtitleAdvanceSteps_Set_Steps_1 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_MPlayer_SetSubtitleAdvanceSteps(U32) */
void TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_SetSubtitleAdvanceSteps_Set_Steps_1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Steps) */
    U32 _u32Steps  = 1ul;
    /* Initializing global variable m_u32SubtitleDelaySteps */
    {
         m_u32SubtitleDelaySteps  = 0ul;
    }
    /* Initializing global variable m_u32SubtitleAdvanceSteps */
    {
         m_u32SubtitleAdvanceSteps  = 0ul;
    }
    {
        /* Tested function call */
        MApp_MPlayer_SetSubtitleAdvanceSteps(_u32Steps);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1ul, ( m_u32SubtitleAdvanceSteps ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_SetSubtitleAdvanceSteps_Set_Steps_1 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_SRT_ParseOneSubtitle_ASCII */
/* CPPTEST_TEST_CASE_CONTEXT EN_PARSE_ONE_SUBTITLE_RET _MApp_MPlayer_SRT_ParseOneSubtitle(MPlayer_Subtitle_Tag *, U32) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SRT_ParseOneSubtitle_ASCII()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pSubtitleTag) */ 
    MPlayer_Subtitle_Tag _pSubtitleTag_0 ;
    MPlayer_Subtitle_Tag * _pSubtitleTag  = & _pSubtitleTag_0;
    /* Initializing argument 2 (u32SubtitlePhyAddr) */ 
    U32 _u32SubtitlePhyAddr  = 0ul;
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable m_u8CurTrackIdx */ 
    {
         m_u8CurTrackIdx  = 0;
    }
    /* Initializing global variable m_u32SubtitleBufParsed */ 
    {
         m_u32SubtitleBufParsed  = 0ul;
    }
    U8 u8BuffTemp[8]={0};
    _u32SubtitlePhyAddr = &u8BuffTemp[0];
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].eSubtitleCodingType = E_MPLAYER_SUBTITLE_CODING_ASC;
    {
        /* Tested function call */
        EN_PARSE_ONE_SUBTITLE_RET _return  = _MApp_MPlayer_SRT_ParseOneSubtitle(_pSubtitleTag, _u32SubtitlePhyAddr);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_PARSE_ONE_SUBTITLE_DONE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_SRT_ParseOneSubtitle_ASCII */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_SRT_ParseOneSubtitle_UNICODE */
/* CPPTEST_TEST_CASE_CONTEXT EN_PARSE_ONE_SUBTITLE_RET _MApp_MPlayer_SRT_ParseOneSubtitle(MPlayer_Subtitle_Tag *, U32) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SRT_ParseOneSubtitle_UNICODE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pSubtitleTag) */ 
    MPlayer_Subtitle_Tag _pSubtitleTag_1 ;
    MPlayer_Subtitle_Tag * _pSubtitleTag  = & _pSubtitleTag_1;
    /* Initializing argument 2 (u32SubtitlePhyAddr) */ 
    U32 _u32SubtitlePhyAddr  = 0ul;
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable m_u8CurTrackIdx */ 
    {
         m_u8CurTrackIdx  = 0;
    }
    /* Initializing global variable m_u32SubtitleBufParsed */ 
    {
         m_u32SubtitleBufParsed  = 0ul;
    }
    U8 u8BuffTemp[8]={0};
    _u32SubtitlePhyAddr = &u8BuffTemp[0];
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].eSubtitleCodingType = E_MPLAYER_SUBTITLE_CODING_UNICODE;
    {
        /* Tested function call */
        EN_PARSE_ONE_SUBTITLE_RET _return  = _MApp_MPlayer_SRT_ParseOneSubtitle(_pSubtitleTag, _u32SubtitlePhyAddr);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_PARSE_ONE_SUBTITLE_DONE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_SRT_ParseOneSubtitle_UNICODE */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_SSA_ParseOneSubtitle_ASCII */
/* CPPTEST_TEST_CASE_CONTEXT EN_PARSE_ONE_SUBTITLE_RET _MApp_MPlayer_SSA_ParseOneSubtitle(MPlayer_Subtitle_Tag *, U32) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SSA_ParseOneSubtitle_ASCII()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pSubtitleTag) */ 
    MPlayer_Subtitle_Tag _pSubtitleTag_2 ;
    MPlayer_Subtitle_Tag * _pSubtitleTag  = & _pSubtitleTag_2;
    /* Initializing argument 2 (u32SubtitlePhyAddr) */ 
    U32 _u32SubtitlePhyAddr  = 0ul;
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable m_u8CurTrackIdx */ 
    {
         m_u8CurTrackIdx  = 0;
    }
    /* Initializing global variable m_u32SubtitleBufParsed */ 
    {
         m_u32SubtitleBufParsed  = 0ul;
    }
    U8 u8BuffTemp[8]={0};
    _u32SubtitlePhyAddr = &u8BuffTemp[0];
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].eSubtitleCodingType = E_MPLAYER_SUBTITLE_CODING_ASC;
    {
        /* Tested function call */
        EN_PARSE_ONE_SUBTITLE_RET _return  = _MApp_MPlayer_SSA_ParseOneSubtitle(_pSubtitleTag, _u32SubtitlePhyAddr);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_PARSE_ONE_SUBTITLE_DONE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_SSA_ParseOneSubtitle_ASCII */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_SSA_ParseOneSubtitle_UNICODE */
/* CPPTEST_TEST_CASE_CONTEXT EN_PARSE_ONE_SUBTITLE_RET _MApp_MPlayer_SSA_ParseOneSubtitle(MPlayer_Subtitle_Tag *, U32) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SSA_ParseOneSubtitle_UNICODE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pSubtitleTag) */ 
    MPlayer_Subtitle_Tag _pSubtitleTag_3 ;
    MPlayer_Subtitle_Tag * _pSubtitleTag  = & _pSubtitleTag_3;
    /* Initializing argument 2 (u32SubtitlePhyAddr) */ 
    U32 _u32SubtitlePhyAddr  = 0ul;
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable m_u8CurTrackIdx */ 
    {
         m_u8CurTrackIdx  = 0;
    }
    /* Initializing global variable m_u32SubtitleBufParsed */ 
    {
         m_u32SubtitleBufParsed  = 0ul;
    }
    U8 u8BuffTemp[8]={0};
    _u32SubtitlePhyAddr = &u8BuffTemp[0];
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].eSubtitleCodingType = E_MPLAYER_SUBTITLE_CODING_UNICODE;
    {
        /* Tested function call */
        EN_PARSE_ONE_SUBTITLE_RET _return  = _MApp_MPlayer_SSA_ParseOneSubtitle(_pSubtitleTag, _u32SubtitlePhyAddr);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_PARSE_ONE_SUBTITLE_DONE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_SSA_ParseOneSubtitle_UNICODE */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_MicroDVD_Parser_ASCII */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_MicroDVD_Parser(U32, enumMplayerSubtitleCoding *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVD_Parser_ASCII()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FileSize) */ 
    U32 _u32FileSize  = 25ul;
    /* Initializing argument 2 (pCodingType) */ 
    enumMplayerSubtitleCoding _pCodingType_4  = E_MPLAYER_SUBTITLE_CODING_ASC;
    enumMplayerSubtitleCoding * _pCodingType  = & _pCodingType_4;
    /* Initializing global variable m_u16SubtitleTagCount */ 
    {
         m_u16SubtitleTagCount  = 0u;
    }
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable FileEntrySubtitle */ 
    {
         FileEntrySubtitle.EntryType  = ENTRY_TYPE_FILE;
         FileEntrySubtitle.EntryFileLength  = 0ul;
         FileEntrySubtitle.EntrySeconds  = 0ul;
         FileEntrySubtitle.EnvironmentID  = 0;
         FileEntrySubtitle.FileSystemID  = 0;
         FileEntrySubtitle.EntryAttrib  = 0;
    }
    /* Initializing global variable m_u8SubtitleTrackNum */ 
    {
         m_u8SubtitleTrackNum  = 0;
    }
    /* Initializing global variable m_u32MicroDVDFrameRate */ 
    {
         m_u32MicroDVDFrameRate  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_MPlayer_MicroDVD_Parser(_u32FileSize, _pCodingType);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_MicroDVD_Parser_ASCII */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_MicroDVD_Parser_UNICODE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_MicroDVD_Parser(U32, enumMplayerSubtitleCoding *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVD_Parser_UNICODE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FileSize) */ 
    U32 _u32FileSize  = 52ul;
    /* Initializing argument 2 (pCodingType) */ 
    enumMplayerSubtitleCoding _pCodingType_5  = E_MPLAYER_SUBTITLE_CODING_ASC;
    enumMplayerSubtitleCoding * _pCodingType  = & _pCodingType_5;
    /* Initializing global variable m_u16SubtitleTagCount */ 
    {
         m_u16SubtitleTagCount  = 0u;
    }
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable FileEntrySubtitle */ 
    {
         FileEntrySubtitle.EntryType  = ENTRY_TYPE_FILE;
         FileEntrySubtitle.EntryFileLength  = 0ul;
         FileEntrySubtitle.EntrySeconds  = 0ul;
         FileEntrySubtitle.EnvironmentID  = 0;
         FileEntrySubtitle.FileSystemID  = 0;
         FileEntrySubtitle.EntryAttrib  = 0;
    }
    /* Initializing global variable m_u8SubtitleTrackNum */ 
    {
         m_u8SubtitleTrackNum  = 0;
    }
    /* Initializing global variable m_u32MicroDVDFrameRate */ 
    {
         m_u32MicroDVDFrameRate  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_MPlayer_MicroDVD_Parser(_u32FileSize, _pCodingType);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_MicroDVD_Parser_UNICODE */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_SMI_Parser_ASCII */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_SMI_Parser(U32, enumMplayerSubtitleCoding *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_Parser_ASCII()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FileSize) */ 
    U32 _u32FileSize  = 175ul;
    /* Initializing argument 2 (pCodingType) */ 
    enumMplayerSubtitleCoding _pCodingType_6  = E_MPLAYER_SUBTITLE_CODING_ASC;
    enumMplayerSubtitleCoding * _pCodingType  = & _pCodingType_6;
    /* Initializing global variable m_u16SubtitleTagCount */ 
    {
         m_u16SubtitleTagCount  = 0u;
    }
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable FileEntrySubtitle */ 
    {
         FileEntrySubtitle.EntryType  = ENTRY_TYPE_FILE;
         FileEntrySubtitle.EntryFileLength  = 0ul;
         FileEntrySubtitle.EntrySeconds  = 0ul;
         FileEntrySubtitle.EnvironmentID  = 0;
         FileEntrySubtitle.FileSystemID  = 0;
         FileEntrySubtitle.EntryAttrib  = 0;
    }
    /* Initializing global variable m_u8SubtitleTrackNum */ 
    {
         m_u8SubtitleTrackNum  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_MPlayer_SMI_Parser(_u32FileSize, _pCodingType);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_SMI_Parser_ASCII */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_SMI_Parser_UNICODE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_SMI_Parser(U32, enumMplayerSubtitleCoding *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_Parser_UNICODE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FileSize) */ 
    U32 _u32FileSize  = 352ul;
    /* Initializing argument 2 (pCodingType) */ 
    enumMplayerSubtitleCoding _pCodingType_7  = E_MPLAYER_SUBTITLE_CODING_ASC;
    enumMplayerSubtitleCoding * _pCodingType  = & _pCodingType_7;
    /* Initializing global variable m_u16SubtitleTagCount */ 
    {
         m_u16SubtitleTagCount  = 0u;
    }
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable FileEntrySubtitle */ 
    {
         FileEntrySubtitle.EntryType  = ENTRY_TYPE_FILE;
         FileEntrySubtitle.EntryFileLength  = 0ul;
         FileEntrySubtitle.EntrySeconds  = 0ul;
         FileEntrySubtitle.EnvironmentID  = 0;
         FileEntrySubtitle.FileSystemID  = 0;
         FileEntrySubtitle.EntryAttrib  = 0;
    }
    /* Initializing global variable m_u8SubtitleTrackNum */ 
    {
         m_u8SubtitleTrackNum  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_MPlayer_SMI_Parser(_u32FileSize, _pCodingType);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_SMI_Parser_UNICODE */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_SMI_Parser_ASCII_NoClassName */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_SMI_Parser(U32, enumMplayerSubtitleCoding *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_Parser_ASCII_NoClassName()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FileSize) */ 
    U32 _u32FileSize  = 118ul;
    /* Initializing argument 2 (pCodingType) */ 
    enumMplayerSubtitleCoding _pCodingType_8  = E_MPLAYER_SUBTITLE_CODING_ASC;
    enumMplayerSubtitleCoding * _pCodingType  = & _pCodingType_8;
    /* Initializing global variable m_u16SubtitleTagCount */ 
    {
         m_u16SubtitleTagCount  = 0u;
    }
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable FileEntrySubtitle */ 
    {
         FileEntrySubtitle.EntryType  = ENTRY_TYPE_FILE;
         FileEntrySubtitle.EntryFileLength  = 0ul;
         FileEntrySubtitle.EntrySeconds  = 0ul;
         FileEntrySubtitle.EnvironmentID  = 0;
         FileEntrySubtitle.FileSystemID  = 0;
         FileEntrySubtitle.EntryAttrib  = 0;
    }
    /* Initializing global variable m_u8SubtitleTrackNum */ 
    {
         m_u8SubtitleTrackNum  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_MPlayer_SMI_Parser(_u32FileSize, _pCodingType);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_SMI_Parser_ASCII_NoClassName */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_SMI_Parser_UNICODE_NoClassName */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_SMI_Parser(U32, enumMplayerSubtitleCoding *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_Parser_UNICODE_NoClassName()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FileSize) */ 
    U32 _u32FileSize  = 238ul;
    /* Initializing argument 2 (pCodingType) */ 
    enumMplayerSubtitleCoding _pCodingType_9  = E_MPLAYER_SUBTITLE_CODING_ASC;
    enumMplayerSubtitleCoding * _pCodingType  = & _pCodingType_9;
    /* Initializing global variable m_u16SubtitleTagCount */ 
    {
         m_u16SubtitleTagCount  = 0u;
    }
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable FileEntrySubtitle */ 
    {
         FileEntrySubtitle.EntryType  = ENTRY_TYPE_FILE;
         FileEntrySubtitle.EntryFileLength  = 0ul;
         FileEntrySubtitle.EntrySeconds  = 0ul;
         FileEntrySubtitle.EnvironmentID  = 0;
         FileEntrySubtitle.FileSystemID  = 0;
         FileEntrySubtitle.EntryAttrib  = 0;
    }
    /* Initializing global variable m_u8SubtitleTrackNum */ 
    {
         m_u8SubtitleTrackNum  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_MPlayer_SMI_Parser(_u32FileSize, _pCodingType);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_SMI_Parser_UNICODE_NoClassName */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_MicroDVD_ParseOneSubtitle_ASCII */
/* CPPTEST_TEST_CASE_CONTEXT EN_PARSE_ONE_SUBTITLE_RET _MApp_MPlayer_MicroDVD_ParseOneSubtitle(MPlayer_Subtitle_Tag *, U32) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVD_ParseOneSubtitle_ASCII()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pSubtitleTag) */ 
    MPlayer_Subtitle_Tag _pSubtitleTag_10 ;
    MPlayer_Subtitle_Tag * _pSubtitleTag  = & _pSubtitleTag_10;
    /* Initializing argument 2 (u32SubtitlePhyAddr) */ 
    U32 _u32SubtitlePhyAddr  = 0ul;
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable m_u8CurTrackIdx */ 
    {
         m_u8CurTrackIdx  = 0;
    }
    /* Initializing global variable m_u32SubtitleBufParsed */ 
    {
         m_u32SubtitleBufParsed  = 0ul;
    }
    /* Initializing global variable m_u32MicroDVDFrameRate */ 
    {
         m_u32MicroDVDFrameRate  = 1ul;
    }
    U8 u8BuffTemp[8]={0};
    _u32SubtitlePhyAddr = &u8BuffTemp[0];
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].eSubtitleCodingType = E_MPLAYER_SUBTITLE_CODING_ASC;
    {
        /* Tested function call */
        EN_PARSE_ONE_SUBTITLE_RET _return  = _MApp_MPlayer_MicroDVD_ParseOneSubtitle(_pSubtitleTag, _u32SubtitlePhyAddr);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_PARSE_ONE_SUBTITLE_DONE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_MicroDVD_ParseOneSubtitle_ASCII */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_MicroDVD_ParseOneSubtitle_UNICODE */
/* CPPTEST_TEST_CASE_CONTEXT EN_PARSE_ONE_SUBTITLE_RET _MApp_MPlayer_MicroDVD_ParseOneSubtitle(MPlayer_Subtitle_Tag *, U32) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVD_ParseOneSubtitle_UNICODE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pSubtitleTag) */ 
    MPlayer_Subtitle_Tag _pSubtitleTag_11 ;
    MPlayer_Subtitle_Tag * _pSubtitleTag  = & _pSubtitleTag_11;
    /* Initializing argument 2 (u32SubtitlePhyAddr) */ 
    U32 _u32SubtitlePhyAddr  = 0ul;
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable m_u8CurTrackIdx */ 
    {
         m_u8CurTrackIdx  = 0;
    }
    /* Initializing global variable m_u32SubtitleBufParsed */ 
    {
         m_u32SubtitleBufParsed  = 0ul;
    }
    /* Initializing global variable m_u32MicroDVDFrameRate */ 
    {
         m_u32MicroDVDFrameRate  = 0ul;
    }
    U8 u8BuffTemp[8]={0};
    _u32SubtitlePhyAddr = &u8BuffTemp[0];
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].eSubtitleCodingType = E_MPLAYER_SUBTITLE_CODING_UNICODE;
    {
        /* Tested function call */
        EN_PARSE_ONE_SUBTITLE_RET _return  = _MApp_MPlayer_MicroDVD_ParseOneSubtitle(_pSubtitleTag, _u32SubtitlePhyAddr);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_PARSE_ONE_SUBTITLE_DONE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_MicroDVD_ParseOneSubtitle_UNICODE */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_SMI_ParseOneSubtitle_ASCII */
/* CPPTEST_TEST_CASE_CONTEXT EN_PARSE_ONE_SUBTITLE_RET _MApp_MPlayer_SMI_ParseOneSubtitle(MPlayer_Subtitle_Tag *, U32) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_ParseOneSubtitle_ASCII()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pSubtitleTag) */ 
    MPlayer_Subtitle_Tag _pSubtitleTag_0 ;
    MPlayer_Subtitle_Tag * _pSubtitleTag  = & _pSubtitleTag_0;
    /* Initializing argument 2 (u32SubtitlePhyAddr) */ 
    U32 _u32SubtitlePhyAddr  = 0ul;
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable m_u8CurTrackIdx */ 
    {
         m_u8CurTrackIdx  = 0;
    }
    /* Initializing global variable m_u32SubtitleBufParsed */ 
    {
         m_u32SubtitleBufParsed  = 0ul;
    }
    U8 u8BuffTemp[8]={0};
    _u32SubtitlePhyAddr = &u8BuffTemp[0];
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].eSubtitleCodingType = E_MPLAYER_SUBTITLE_CODING_ASC;

    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIClass.u8ClassName[0] = 0x55;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIClass.u8ClassName[1] = 0x4e;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIClass.u8ClassName[2] = 0x4B;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIClass.u8ClassName[3] = 0x4E;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIClass.u8ClassName[4] = 0x4F;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIClass.u8ClassName[5] = 0x57;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIClass.u8ClassName[6] = 0x4E;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIClass.u8ClassName[7] = 0x43;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIClass.u8ClassName[8] = 0x43;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIClass.u8Lang[0] = 0x0;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIClass.u8ClassLen = 9;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIClass.bPClass = TRUE;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIFinalSubtitle.u32TimeStart = 5000;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIFinalSubtitle.u32SubtitlefilePos = 170;

    {
        /* Tested function call */
        EN_PARSE_ONE_SUBTITLE_RET _return  = _MApp_MPlayer_SMI_ParseOneSubtitle(_pSubtitleTag, _u32SubtitlePhyAddr);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_PARSE_ONE_SUBTITLE_DONE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_SMI_ParseOneSubtitle_ASCII */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_SMI_ParseOneSubtitle_UNICODE */
/* CPPTEST_TEST_CASE_CONTEXT EN_PARSE_ONE_SUBTITLE_RET _MApp_MPlayer_SMI_ParseOneSubtitle(MPlayer_Subtitle_Tag *, U32) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_ParseOneSubtitle_UNICODE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pSubtitleTag) */ 
    MPlayer_Subtitle_Tag _pSubtitleTag_1 ;
    MPlayer_Subtitle_Tag * _pSubtitleTag  = & _pSubtitleTag_1;
    /* Initializing argument 2 (u32SubtitlePhyAddr) */ 
    U32 _u32SubtitlePhyAddr  = 0ul;
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable m_u8CurTrackIdx */ 
    {
         m_u8CurTrackIdx  = 0;
    }
    /* Initializing global variable m_u32SubtitleBufParsed */ 
    {
         m_u32SubtitleBufParsed  = 0ul;
    }
    U8 u8BuffTemp[8]={0};
    _u32SubtitlePhyAddr = &u8BuffTemp[0];
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].eSubtitleCodingType = E_MPLAYER_SUBTITLE_CODING_UNICODE;

    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIClass.u8ClassName[0] = 0x55;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIClass.u8ClassName[1] = 0x4e;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIClass.u8ClassName[2] = 0x4B;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIClass.u8ClassName[3] = 0x4E;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIClass.u8ClassName[4] = 0x4F;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIClass.u8ClassName[5] = 0x57;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIClass.u8ClassName[6] = 0x4E;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIClass.u8ClassName[7] = 0x43;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIClass.u8ClassName[8] = 0x43;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIClass.u8Lang[0] = 0x0;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIClass.u8ClassLen = 9;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIClass.bPClass = TRUE;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIFinalSubtitle.u32TimeStart = 5000;
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].stSMIFinalSubtitle.u32SubtitlefilePos = 342;
    {
        /* Tested function call */
        EN_PARSE_ONE_SUBTITLE_RET _return  = _MApp_MPlayer_SMI_ParseOneSubtitle(_pSubtitleTag, _u32SubtitlePhyAddr);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_PARSE_ONE_SUBTITLE_DONE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_SMI_ParseOneSubtitle_UNICODE */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_TTXT_Parser_ASCII */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_TTXT_Parser(U32, enumMplayerSubtitleCoding *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_Parser_ASCII()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FileSize) */ 
    U32 _u32FileSize  = 109;
    /* Initializing argument 2 (pCodingType) */ 
    enumMplayerSubtitleCoding _pCodingType_0  = E_MPLAYER_SUBTITLE_CODING_ASC;
    enumMplayerSubtitleCoding * _pCodingType  = & _pCodingType_0;
    /* Initializing global variable m_u16SubtitleTagCount */ 
    {
         m_u16SubtitleTagCount  = 0u;
    }
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable FileEntrySubtitle */ 
    {
         FileEntrySubtitle.EntryType  = ENTRY_TYPE_FILE;
         FileEntrySubtitle.EntryFileLength  = 0ul;
         FileEntrySubtitle.EntrySeconds  = 0ul;
         FileEntrySubtitle.EnvironmentID  = 0;
         FileEntrySubtitle.FileSystemID  = 0;
         FileEntrySubtitle.EntryAttrib  = 0;
    }
    /* Initializing global variable m_u8SubtitleTrackNum */ 
    {
         m_u8SubtitleTrackNum  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_MPlayer_TTXT_Parser(_u32FileSize, _pCodingType);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_TTXT_Parser_ASCII */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_TTXT_Parser_UNICODE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_TTXT_Parser(U32, enumMplayerSubtitleCoding *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_Parser_UNICODE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FileSize) */ 
    U32 _u32FileSize  = 220;
    /* Initializing argument 2 (pCodingType) */ 
    enumMplayerSubtitleCoding _pCodingType_0  = E_MPLAYER_SUBTITLE_CODING_ASC;
    enumMplayerSubtitleCoding * _pCodingType  = & _pCodingType_0;
    /* Initializing global variable m_u16SubtitleTagCount */ 
    {
         m_u16SubtitleTagCount  = 0u;
    }
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable FileEntrySubtitle */ 
    {
         FileEntrySubtitle.EntryType  = ENTRY_TYPE_FILE;
         FileEntrySubtitle.EntryFileLength  = 0ul;
         FileEntrySubtitle.EntrySeconds  = 0ul;
         FileEntrySubtitle.EnvironmentID  = 0;
         FileEntrySubtitle.FileSystemID  = 0;
         FileEntrySubtitle.EntryAttrib  = 0;
    }
    /* Initializing global variable m_u8SubtitleTrackNum */ 
    {
         m_u8SubtitleTrackNum  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_MPlayer_TTXT_Parser(_u32FileSize, _pCodingType);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_TTXT_Parser_UNICODE */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_TTXT_ParseOneSubtitle_ASCII */
/* CPPTEST_TEST_CASE_CONTEXT EN_PARSE_ONE_SUBTITLE_RET _MApp_MPlayer_TTXT_ParseOneSubtitle(MPlayer_Subtitle_Tag *, U32) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_ParseOneSubtitle_ASCII()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pSubtitleTag) */ 
    MPlayer_Subtitle_Tag _pSubtitleTag_1 ;
    MPlayer_Subtitle_Tag * _pSubtitleTag  = & _pSubtitleTag_1;
    /* Initializing argument 2 (u32SubtitlePhyAddr) */ 
    U32 _u32SubtitlePhyAddr  = 0ul;
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable m_u8CurTrackIdx */ 
    {
         m_u8CurTrackIdx  = 0;
    }
    /* Initializing global variable m_u32SubtitleBufParsed */ 
    {
         m_u32SubtitleBufParsed  = 0ul;
    }
    U8 u8BuffTemp[8]={0};
    _u32SubtitlePhyAddr = &u8BuffTemp[0];
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].eSubtitleCodingType = E_MPLAYER_SUBTITLE_CODING_ASC;
    {
        /* Tested function call */
        EN_PARSE_ONE_SUBTITLE_RET _return  = _MApp_MPlayer_TTXT_ParseOneSubtitle(_pSubtitleTag, _u32SubtitlePhyAddr);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_PARSE_ONE_SUBTITLE_DONE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_TTXT_ParseOneSubtitle_ASCII */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_TTXT_ParseOneSubtitle_UNICODE */
/* CPPTEST_TEST_CASE_CONTEXT EN_PARSE_ONE_SUBTITLE_RET _MApp_MPlayer_TTXT_ParseOneSubtitle(MPlayer_Subtitle_Tag *, U32) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_ParseOneSubtitle_UNICODE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pSubtitleTag) */ 
    MPlayer_Subtitle_Tag _pSubtitleTag_2 ;
    MPlayer_Subtitle_Tag * _pSubtitleTag  = & _pSubtitleTag_2;
    /* Initializing argument 2 (u32SubtitlePhyAddr) */ 
    U32 _u32SubtitlePhyAddr  = 0ul;
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable m_u8CurTrackIdx */ 
    {
         m_u8CurTrackIdx  = 0;
    }
    /* Initializing global variable m_u32SubtitleBufParsed */ 
    {
         m_u32SubtitleBufParsed  = 0ul;
    }
    U8 u8BuffTemp[8]={0};
    _u32SubtitlePhyAddr = &u8BuffTemp[0];
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].eSubtitleCodingType = E_MPLAYER_SUBTITLE_CODING_UNICODE;
    {
        /* Tested function call */
        EN_PARSE_ONE_SUBTITLE_RET _return  = _MApp_MPlayer_TTXT_ParseOneSubtitle(_pSubtitleTag, _u32SubtitlePhyAddr);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_PARSE_ONE_SUBTITLE_DONE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_TTXT_ParseOneSubtitle_UNICODE */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_TTXT_ParseOneSubtitle_ASCII_Ver10 */
/* CPPTEST_TEST_CASE_CONTEXT EN_PARSE_ONE_SUBTITLE_RET _MApp_MPlayer_TTXT_ParseOneSubtitle(MPlayer_Subtitle_Tag *, U32) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_ParseOneSubtitle_ASCII_Ver10()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pSubtitleTag) */ 
    MPlayer_Subtitle_Tag _pSubtitleTag_3 ;
    MPlayer_Subtitle_Tag * _pSubtitleTag  = & _pSubtitleTag_3;
    /* Initializing argument 2 (u32SubtitlePhyAddr) */ 
    U32 _u32SubtitlePhyAddr  = 0ul;
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable m_u8CurTrackIdx */ 
    {
         m_u8CurTrackIdx  = 0;
    }
    /* Initializing global variable m_u32SubtitleBufParsed */ 
    {
         m_u32SubtitleBufParsed  = 0ul;
    }
    U8 u8BuffTemp[8]={0};
    _u32SubtitlePhyAddr = &u8BuffTemp[0];
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].eSubtitleCodingType = E_MPLAYER_SUBTITLE_CODING_ASC;
    {
        /* Tested function call */
        EN_PARSE_ONE_SUBTITLE_RET _return  = _MApp_MPlayer_TTXT_ParseOneSubtitle(_pSubtitleTag, _u32SubtitlePhyAddr);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_PARSE_ONE_SUBTITLE_DONE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_TTXT_ParseOneSubtitle_ASCII_Ver10 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_TTXT_ParseOneSubtitle_UNICODE_Ver10 */
/* CPPTEST_TEST_CASE_CONTEXT EN_PARSE_ONE_SUBTITLE_RET _MApp_MPlayer_TTXT_ParseOneSubtitle(MPlayer_Subtitle_Tag *, U32) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_ParseOneSubtitle_UNICODE_Ver10()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pSubtitleTag) */ 
    MPlayer_Subtitle_Tag _pSubtitleTag_4 ;
    MPlayer_Subtitle_Tag * _pSubtitleTag  = & _pSubtitleTag_4;
    /* Initializing argument 2 (u32SubtitlePhyAddr) */ 
    U32 _u32SubtitlePhyAddr  = 0ul;
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable m_u8CurTrackIdx */ 
    {
         m_u8CurTrackIdx  = 0;
    }
    /* Initializing global variable m_u32SubtitleBufParsed */ 
    {
         m_u32SubtitleBufParsed  = 0ul;
    }
    U8 u8BuffTemp[8]={0};
    _u32SubtitlePhyAddr = &u8BuffTemp[0];
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].eSubtitleCodingType = E_MPLAYER_SUBTITLE_CODING_UNICODE;
    {
        /* Tested function call */
        EN_PARSE_ONE_SUBTITLE_RET _return  = _MApp_MPlayer_TTXT_ParseOneSubtitle(_pSubtitleTag, _u32SubtitlePhyAddr);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_PARSE_ONE_SUBTITLE_DONE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_TTXT_ParseOneSubtitle_UNICODE_Ver10 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_TMPlayer_Parser_ASCII */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_TMPlayer_Parser(U32, enumMplayerSubtitleCoding *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TMPlayer_Parser_ASCII()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FileSize) */ 
    U32 _u32FileSize  = 97;
    /* Initializing argument 2 (pCodingType) */ 
    enumMplayerSubtitleCoding _pCodingType_5  = E_MPLAYER_SUBTITLE_CODING_ASC;
    enumMplayerSubtitleCoding * _pCodingType  = & _pCodingType_5;
    /* Initializing global variable m_u16SubtitleTagCount */ 
    {
         m_u16SubtitleTagCount  = 0u;
    }
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 0;
    }
    /* Initializing global variable FileEntrySubtitle */ 
    {
         FileEntrySubtitle.EntryType  = ENTRY_TYPE_FILE;
         FileEntrySubtitle.EntryFileLength  = 0ul;
         FileEntrySubtitle.EntrySeconds  = 0ul;
         FileEntrySubtitle.EnvironmentID  = 0;
         FileEntrySubtitle.FileSystemID  = 0;
         FileEntrySubtitle.EntryAttrib  = 0;
    }
    /* Initializing global variable m_u8SubtitleTrackNum */ 
    {
         m_u8SubtitleTrackNum  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_MPlayer_TMPlayer_Parser(_u32FileSize, _pCodingType);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_TMPlayer_Parser_ASCII */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_TMPlayer_Parser_UNICODE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_TMPlayer_Parser(U32, enumMplayerSubtitleCoding *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TMPlayer_Parser_UNICODE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FileSize) */ 
    U32 _u32FileSize  = 196;
    /* Initializing argument 2 (pCodingType) */ 
    enumMplayerSubtitleCoding _pCodingType_6  = E_MPLAYER_SUBTITLE_CODING_ASC;
    enumMplayerSubtitleCoding * _pCodingType  = & _pCodingType_6;
    /* Initializing global variable m_u16SubtitleTagCount */ 
    {
         m_u16SubtitleTagCount  = 0u;
    }
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable FileEntrySubtitle */ 
    {
         FileEntrySubtitle.EntryType  = ENTRY_TYPE_FILE;
         FileEntrySubtitle.EntryFileLength  = 0ul;
         FileEntrySubtitle.EntrySeconds  = 0ul;
         FileEntrySubtitle.EnvironmentID  = 0;
         FileEntrySubtitle.FileSystemID  = 0;
         FileEntrySubtitle.EntryAttrib  = 0;
    }
    /* Initializing global variable m_u8SubtitleTrackNum */ 
    {
         m_u8SubtitleTrackNum  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_MPlayer_TMPlayer_Parser(_u32FileSize, _pCodingType);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_TMPlayer_Parser_UNICODE */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_TMPlayer_ParseOneSubtitle_ASCII */
/* CPPTEST_TEST_CASE_CONTEXT EN_PARSE_ONE_SUBTITLE_RET _MApp_MPlayer_TMPlayer_ParseOneSubtitle(MPlayer_Subtitle_Tag *, U32) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TMPlayer_ParseOneSubtitle_ASCII()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pSubtitleTag) */ 
    MPlayer_Subtitle_Tag _pSubtitleTag_7 ;
    MPlayer_Subtitle_Tag * _pSubtitleTag  = & _pSubtitleTag_7;
    /* Initializing argument 2 (u32SubtitlePhyAddr) */ 
    U32 _u32SubtitlePhyAddr  = 0ul;
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable m_u8CurTrackIdx */ 
    {
         m_u8CurTrackIdx  = 0;
    }
    /* Initializing global variable m_u32SubtitleBufParsed */ 
    {
         m_u32SubtitleBufParsed  = 0ul;
    }
    U8 u8BuffTemp[8]={0};
    _u32SubtitlePhyAddr = &u8BuffTemp[0];
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].eSubtitleCodingType = E_MPLAYER_SUBTITLE_CODING_ASC;
    {
        /* Tested function call */
        EN_PARSE_ONE_SUBTITLE_RET _return  = _MApp_MPlayer_TMPlayer_ParseOneSubtitle(_pSubtitleTag, _u32SubtitlePhyAddr);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_PARSE_ONE_SUBTITLE_DONE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_TMPlayer_ParseOneSubtitle_ASCII */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_TMPlayer_ParseOneSubtitle_UNICODE */
/* CPPTEST_TEST_CASE_CONTEXT EN_PARSE_ONE_SUBTITLE_RET _MApp_MPlayer_TMPlayer_ParseOneSubtitle(MPlayer_Subtitle_Tag *, U32) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TMPlayer_ParseOneSubtitle_UNICODE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pSubtitleTag) */ 
    MPlayer_Subtitle_Tag _pSubtitleTag_8 ;
    MPlayer_Subtitle_Tag * _pSubtitleTag  = & _pSubtitleTag_8;
    /* Initializing argument 2 (u32SubtitlePhyAddr) */ 
    U32 _u32SubtitlePhyAddr  = 0ul;
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable m_u8CurTrackIdx */ 
    {
         m_u8CurTrackIdx  = 0;
    }
    /* Initializing global variable m_u32SubtitleBufParsed */ 
    {
         m_u32SubtitleBufParsed  = 0ul;
    }
    U8 u8BuffTemp[8]={0};
    _u32SubtitlePhyAddr = &u8BuffTemp[0];
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].eSubtitleCodingType = E_MPLAYER_SUBTITLE_CODING_UNICODE;
    {
        /* Tested function call */
        EN_PARSE_ONE_SUBTITLE_RET _return  = _MApp_MPlayer_TMPlayer_ParseOneSubtitle(_pSubtitleTag, _u32SubtitlePhyAddr);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_PARSE_ONE_SUBTITLE_DONE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_TMPlayer_ParseOneSubtitle_UNICODE */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_DvdSubtitleSystem_Parser_ASCII */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_DvdSubtitleSystem_Parser(U32, enumMplayerSubtitleCoding *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_DvdSubtitleSystem_Parser_ASCII()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FileSize) */ 
    U32 _u32FileSize  = 54;
    /* Initializing argument 2 (pCodingType) */ 
    enumMplayerSubtitleCoding _pCodingType_0  = E_MPLAYER_SUBTITLE_CODING_ASC;
    enumMplayerSubtitleCoding * _pCodingType  = & _pCodingType_0;
    /* Initializing global variable FileEntrySubtitle */ 
    {
         FileEntrySubtitle.EntryType  = ENTRY_TYPE_FILE;
         FileEntrySubtitle.EntryFileLength  = 0ul;
         FileEntrySubtitle.EntrySeconds  = 0ul;
         FileEntrySubtitle.EnvironmentID  = 0;
         FileEntrySubtitle.FileSystemID  = 0;
         FileEntrySubtitle.EntryAttrib  = 0;
    }
    /* Initializing global variable m_u16SubtitleTagCount */ 
    {
         m_u16SubtitleTagCount  = 0u;
    }
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable m_u8SubtitleTrackNum */ 
    {
         m_u8SubtitleTrackNum  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_MPlayer_DvdSubtitleSystem_Parser(_u32FileSize, _pCodingType);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_DvdSubtitleSystem_Parser_ASCII */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_DvdSubtitleSystem_Parser_UNICODE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_DvdSubtitleSystem_Parser(U32, enumMplayerSubtitleCoding *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_DvdSubtitleSystem_Parser_UNICODE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FileSize) */ 
    U32 _u32FileSize  = 110;
    /* Initializing argument 2 (pCodingType) */ 
    enumMplayerSubtitleCoding _pCodingType_1  = E_MPLAYER_SUBTITLE_CODING_ASC;
    enumMplayerSubtitleCoding * _pCodingType  = & _pCodingType_1;
    /* Initializing global variable FileEntrySubtitle */ 
    {
         FileEntrySubtitle.EntryType  = ENTRY_TYPE_FILE;
         FileEntrySubtitle.EntryFileLength  = 0ul;
         FileEntrySubtitle.EntrySeconds  = 0ul;
         FileEntrySubtitle.EnvironmentID  = 0;
         FileEntrySubtitle.FileSystemID  = 0;
         FileEntrySubtitle.EntryAttrib  = 0;
    }
    /* Initializing global variable m_u16SubtitleTagCount */ 
    {
         m_u16SubtitleTagCount  = 0u;
    }
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable m_u8SubtitleTrackNum */ 
    {
         m_u8SubtitleTrackNum  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_MPlayer_DvdSubtitleSystem_Parser(_u32FileSize, _pCodingType);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_DvdSubtitleSystem_Parser_UNICODE */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_DvdSubtitleSystem_ParseOneSubtitle_ASCII */
/* CPPTEST_TEST_CASE_CONTEXT EN_PARSE_ONE_SUBTITLE_RET _MApp_MPlayer_DvdSubtitleSystem_ParseOneSubtitle(MPlayer_Subtitle_Tag *, U32) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_DvdSubtitleSystem_ParseOneSubtitle_ASCII()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pSubtitleTag) */ 
    MPlayer_Subtitle_Tag _pSubtitleTag_0 ;
    MPlayer_Subtitle_Tag * _pSubtitleTag  = & _pSubtitleTag_0;
    /* Initializing argument 2 (u32SubtitlePhyAddr) */ 
    U32 _u32SubtitlePhyAddr  = 0ul;
    /* Initializing global variable m_u32SubtitleBufParsed */ 
    {
         m_u32SubtitleBufParsed  = 0ul;
    }
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable m_u8CurTrackIdx */ 
    {
         m_u8CurTrackIdx  = 0;
    }
    U8 u8BuffTemp[8]={0};
    _u32SubtitlePhyAddr = &u8BuffTemp[0];
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].eSubtitleCodingType = E_MPLAYER_SUBTITLE_CODING_ASC;
    {
        /* Tested function call */
        EN_PARSE_ONE_SUBTITLE_RET _return  = _MApp_MPlayer_DvdSubtitleSystem_ParseOneSubtitle(_pSubtitleTag, _u32SubtitlePhyAddr);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_PARSE_ONE_SUBTITLE_DONE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_DvdSubtitleSystem_ParseOneSubtitle_ASCII */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_DvdSubtitleSystem_ParseOneSubtitle_UNICODE */
/* CPPTEST_TEST_CASE_CONTEXT EN_PARSE_ONE_SUBTITLE_RET _MApp_MPlayer_DvdSubtitleSystem_ParseOneSubtitle(MPlayer_Subtitle_Tag *, U32) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_DvdSubtitleSystem_ParseOneSubtitle_UNICODE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pSubtitleTag) */ 
    MPlayer_Subtitle_Tag _pSubtitleTag_1 ;
    MPlayer_Subtitle_Tag * _pSubtitleTag  = & _pSubtitleTag_1;
    /* Initializing argument 2 (u32SubtitlePhyAddr) */ 
    U32 _u32SubtitlePhyAddr  = 0ul;
    /* Initializing global variable m_u32SubtitleBufParsed */ 
    {
         m_u32SubtitleBufParsed  = 0ul;
    }
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable m_u8CurTrackIdx */ 
    {
         m_u8CurTrackIdx  = 0;
    }
    U8 u8BuffTemp[8]={0};
    _u32SubtitlePhyAddr = &u8BuffTemp[0];
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].eSubtitleCodingType = E_MPLAYER_SUBTITLE_CODING_UNICODE;
    {
        /* Tested function call */
        EN_PARSE_ONE_SUBTITLE_RET _return  = _MApp_MPlayer_DvdSubtitleSystem_ParseOneSubtitle(_pSubtitleTag, _u32SubtitlePhyAddr);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_PARSE_ONE_SUBTITLE_DONE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_DvdSubtitleSystem_ParseOneSubtitle_UNICODE */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_SUBIDX_Parser_ASCII */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_SUBIDX_Parser(U32, enumMplayerSubtitleCoding *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SUBIDX_Parser_ASCII()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FileSize) */ 
    U32 _u32FileSize  = 263ul;
    /* Initializing argument 2 (pCodingType) */ 
    enumMplayerSubtitleCoding _pCodingType_0  = E_MPLAYER_SUBTITLE_CODING_ASC;
    enumMplayerSubtitleCoding * _pCodingType  = & _pCodingType_0;
    /* Initializing global variable FileEntrySubtitle */ 
    {
         FileEntrySubtitle.EntryType  = ENTRY_TYPE_FILE;
         FileEntrySubtitle.EntryFileLength  = 0ul;
         FileEntrySubtitle.EntrySeconds  = 0ul;
         FileEntrySubtitle.EnvironmentID  = 0;
         FileEntrySubtitle.FileSystemID  = 0;
         FileEntrySubtitle.EntryAttrib  = 0;
    }
    /* Initializing global variable m_u16SubtitleTagCount */ 
    {
         m_u16SubtitleTagCount  = 0u;
    }
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable m_u8SubtitleTrackNum */ 
    {
         m_u8SubtitleTrackNum  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_MPlayer_SUBIDX_Parser(_u32FileSize, _pCodingType);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_SUBIDX_Parser_ASCII */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_SUBIDX_Parser_UNICODE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_SUBIDX_Parser(U32, enumMplayerSubtitleCoding *) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SUBIDX_Parser_UNICODE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FileSize) */ 
    U32 _u32FileSize  = 528;
    /* Initializing argument 2 (pCodingType) */ 
    enumMplayerSubtitleCoding _pCodingType_1  = E_MPLAYER_SUBTITLE_CODING_ASC;
    enumMplayerSubtitleCoding * _pCodingType  = & _pCodingType_1;
    /* Initializing global variable FileEntrySubtitle */ 
    {
         FileEntrySubtitle.EntryType  = ENTRY_TYPE_FILE;
         FileEntrySubtitle.EntryFileLength  = 0ul;
         FileEntrySubtitle.EntrySeconds  = 0ul;
         FileEntrySubtitle.EnvironmentID  = 0;
         FileEntrySubtitle.FileSystemID  = 0;
         FileEntrySubtitle.EntryAttrib  = 0;
    }
    /* Initializing global variable m_u16SubtitleTagCount */ 
    {
         m_u16SubtitleTagCount  = 0u;
    }
    /* Initializing global variable m_u32CurSubtitleFilePos */ 
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */ 
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable m_u8SubtitleTrackNum */ 
    {
         m_u8SubtitleTrackNum  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_MPlayer_SUBIDX_Parser(_u32FileSize, _pCodingType);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_SUBIDX_Parser_UNICODE */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_SUBIDX_ParseOneSubtitle_ASCII */
/* CPPTEST_TEST_CASE_CONTEXT EN_PARSE_ONE_SUBTITLE_RET _MApp_MPlayer_SUBIDX_ParseOneSubtitle(MPlayer_Subtitle_Tag *, U32) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SUBIDX_ParseOneSubtitle_ASCII()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pSubtitleTag) */
    MPlayer_Subtitle_Tag _pSubtitleTag_2 ;
    MPlayer_Subtitle_Tag * _pSubtitleTag  = & _pSubtitleTag_2;
    /* Initializing argument 2 (u32SubtitlePhyAddr) */
    U32 _u32SubtitlePhyAddr  = 0ul;
    /* Initializing global variable m_u32SubtitleBufParsed */
    {
         m_u32SubtitleBufParsed  = 0ul;
    }
    /* Initializing global variable m_u16SubtitleTagCount */
    {
         m_u16SubtitleTagCount  = 0u;
    }
    /* Initializing global variable m_u32CurSubtitleFilePos */
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable m_u8CurTrackIdx */
    {
         m_u8CurTrackIdx  = 0;
    }
    U8 u8BuffTemp[8]={0};
    _u32SubtitlePhyAddr = &u8BuffTemp[0];
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].eSubtitleCodingType = E_MPLAYER_SUBTITLE_CODING_ASC;
    m_u8SubtitleTrackNum =0;
    m_MPlayerSubtitleInfo[m_u8SubtitleTrackNum].stSUBIDXInfo.u32TrackStartFilePos = 140;
    {
        /* Tested function call */
        EN_PARSE_ONE_SUBTITLE_RET _return  = _MApp_MPlayer_SUBIDX_ParseOneSubtitle(_pSubtitleTag, _u32SubtitlePhyAddr);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_PARSE_ONE_SUBTITLE_DONE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_SUBIDX_ParseOneSubtitle_ASCII */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_SUBIDX_ParseOneSubtitle_UNICODE */
/* CPPTEST_TEST_CASE_CONTEXT EN_PARSE_ONE_SUBTITLE_RET _MApp_MPlayer_SUBIDX_ParseOneSubtitle(MPlayer_Subtitle_Tag *, U32) */
void TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SUBIDX_ParseOneSubtitle_UNICODE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pSubtitleTag) */
    MPlayer_Subtitle_Tag _pSubtitleTag_4 ;
    MPlayer_Subtitle_Tag * _pSubtitleTag  = & _pSubtitleTag_4;
    /* Initializing argument 2 (u32SubtitlePhyAddr) */
    U32 _u32SubtitlePhyAddr  = 0ul;
    /* Initializing global variable m_u32SubtitleBufParsed */
    {
         m_u32SubtitleBufParsed  = 0ul;
    }
    /* Initializing global variable m_u16SubtitleTagCount */
    {
         m_u16SubtitleTagCount  = 0u;
    }
    /* Initializing global variable m_u32CurSubtitleFilePos */
    {
         m_u32CurSubtitleFilePos  = 0ul;
    }
    /* Initializing global variable m_u8FileNo */
    {
         m_u8FileNo  = 1;
    }
    /* Initializing global variable m_u8CurTrackIdx */
    {
         m_u8CurTrackIdx  = 0;
    }
    U8 u8BuffTemp[8]={0};
    _u32SubtitlePhyAddr = &u8BuffTemp[0];
    m_MPlayerSubtitleInfo[m_u8CurTrackIdx].eSubtitleCodingType = E_MPLAYER_SUBTITLE_CODING_UNICODE;
    m_u8SubtitleTrackNum =0;
    m_MPlayerSubtitleInfo[m_u8SubtitleTrackNum].stSUBIDXInfo.u32TrackStartFilePos = 282;
    {
        /* Tested function call */
        EN_PARSE_ONE_SUBTITLE_RET _return  = _MApp_MPlayer_SUBIDX_ParseOneSubtitle(_pSubtitleTag, _u32SubtitlePhyAddr);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_PARSE_ONE_SUBTITLE_DONE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_SUBIDX_ParseOneSubtitle_UNICODE */
