#include "cpptest.h"
#include "mapp_mplayer.h"

CPPTEST_CONTEXT("/UTProject/multimedia/mapp_mplayer.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/multimedia/mapp_mplayer.c");

CPPTEST_TEST_SUITE(TestSuite_mapp_mplayer);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_IsMusicRecording_true);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentPlayingList_Photo);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentPlayingList_Music);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentPlayingList_Movie);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryBGMPlayingList);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentFileIndex_u16CurFileIdx_equals_INVALID_INDEX);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentFileIndex_INDEX_CURRENT_DIRECTORY);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentFileIndex_INDEX_CURRENT_PAGE_case1);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentFileIndex_INDEX_CURRENT_PAGE_case2);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentFileIndex_INDEX_CURRENT_PAGE_case3);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryTotalPages);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCurrentExternalSubtitleAvailable_Is_RET_OK);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCurrentExternalSubtitleAvailable_Is_RET_FAIL);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCurrentExternalSubtitleAvailable_Is_RET_OK);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCurrentExternalSubtitleAvailable_Is_RET_FAIL);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryPlayMode);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentMediaSubType);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMusic_FLAC);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMusic_WMA);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMusic_AAC);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMusic_WAV);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMusic_MP3);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMusic_default);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_GetNotifyRtn);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMovie_FALSE_PHOTO);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMovie_FALSE_MUSIC);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMovie_TRUE_MOVIE);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_ToLower_Uppercase);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_ToLower_Lowercase);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_GetPlayListAddressByMediaType_TYPE_INVALID);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_GetPlayListAddressByMediaType_NULL);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_GetPlayListAddressByMediaType_TYPE_PHOTO);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_GetPlayListAddressByMediaType_TYPE_MUSIC);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_GetPlayListAddressByMediaType_TYPE_MOVIE);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_GetPlayListAddressByMediaType_TYPE_TEXT);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_IsMedia_File_ByExtName_TYPE_INVALID);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MAPP_MPlayer_GetMusicTotalFileNum);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_ReCalcMPlayerPlayingIdx_PHOTO_AddToList_Belowcase);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_ReCalcMPlayerPlayingIdx_PHOTO_AddToList_Abovecase);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_ReCalcMPlayerPlayingIdx_PHOTO_AddToList_Amongcase);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_ReCalcMPlayerPlayingIdx_PHOTO_RemoveFromList_Belowcase);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_ReCalcMPlayerPlayingIdx_PHOTO_RemoveFromList_Abovecase);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_ReCalcMPlayerPlayingIdx_PHOTO_RemoveFromList_Amongcase_StartIdx_Equals_zero);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_ReCalcMPlayerPlayingIdx_PHOTO_RemoveFromList_Amongcase_EndIdx_Equals_SelectedFileNum_minus_one);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_ReCalcMPlayerPlayingIdx_PHOTO_RemoveFromList_Amongcase_Other);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_ToUpper_Uppercase);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_ToUpper_Lowercase);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPLayer_GetSubtitleTypeByFileExtName_TYPE_INVALID);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPLayer_GetSubtitleTypeByFileExtName_TYPE_SRT);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_PlayAgain);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_SetCurrentFile_CURRENT_PAGE_FAIL);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_SetCurrentFile_CURRENT_DIRECTORY_FAIL);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_SetCurrentFile_CURRENT_DIRECTORY_OK);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_SetCurrentFile_TYPE_NUM_FAIL);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_EnterCopyMode);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_ExitCopyMode);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryIsCopyMode);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_StopCopy);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryPasteFileStatus);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryPasteFileStatus_Return_zero);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCopying_TRUE);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCopying_FALSE);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentSelectedCopyingFileIndex);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_StopDelete);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_DeleteNext_FALSE_worng_selected_file_number);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_DeleteNext_FALSE_no_selected_file);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_DeleteNext_TRUE);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_IsDeleting_TRUE);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_IsDeleting_FALSE);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentSelectedDeletingFileIndex);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryDeleteFileStatus_In_delete_play);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryDeleteFileStatus_Not_in_delete_play);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurMovieAudioLanguage_en);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurMovieSubtitleLanguage_External);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurMovieSubtitleLanguage_Interal);
CPPTEST_TEST(TestSuite_mapp_mplayer_test__MApp_MPlayer_SubtitleTask_External_Text);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_GetPlayListFileInfo_Music);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_Stop_Music_E_MPLAYER_RET_OK);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_Stop_Movie_E_MPLAYER_RET_OK);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_PlayPrevFile_Music_E_MPLAYER_RET_OK);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_PlayPrevFile_Movie_E_MPLAYER_RET_OK);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_SetCurrentPlayingList_Music_u16PLIndex_Over20u16PlayListNum);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_PlayMusic_E_MPLAYER_PLAY_ONE_DIRECTORY_E_MPLAYER_RET_OK);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_PlayMusic_NotMusic_m_u16SelectedFileNum_0_E_MPLAYER_RET_FAIL);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_PlayMusic_NotMusic_m_u16SelectedFileNum_1_E_MPLAYER_RET_FAIL);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_GetFileEntryByPlaylistIndex_TRUE);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCurSubtitleText_TRUE);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCurSubtitleExternal_TRUE);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCurSubtitleText_FALSE);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_PrevPage_CurPageIdx_equal_zero);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_PrevPage_FilePerPage_equal_zero);
CPPTEST_TEST(TestSuite_mapp_mplayer_test_MApp_MPlayer_PrevPage_FilePerPage_not_equal_zero);
CPPTEST_TEST_SUITE_END();

void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsMusicRecording_true();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentPlayingList_Photo();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentPlayingList_Music();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentPlayingList_Movie();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryBGMPlayingList();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentFileIndex_u16CurFileIdx_equals_INVALID_INDEX();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentFileIndex_INDEX_CURRENT_DIRECTORY();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentFileIndex_INDEX_CURRENT_PAGE_case1();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentFileIndex_INDEX_CURRENT_PAGE_case2();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentFileIndex_INDEX_CURRENT_PAGE_case3();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryTotalPages();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCurrentExternalSubtitleAvailable_Is_RET_OK();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCurrentExternalSubtitleAvailable_Is_RET_FAIL();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCurrentLRCLyricAvailable_Is_RET_OK();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCurrentLRCLyricAvailable_Is_RET_FAIL();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryPlayMode();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentMediaSubType();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMusic_FLAC();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMusic_WMA();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMusic_AAC();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMusic_WAV();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMusic_MP3();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMusic_default();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_GetNotifyRtn();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMovie_FALSE_PHOTO();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMovie_FALSE_MUSIC();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMovie_TRUE_MOVIE();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_ToLower_Uppercase();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_ToLower_Lowercase();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_GetPlayListAddressByMediaType_TYPE_INVALID();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_GetPlayListAddressByMediaType_NULL();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_GetPlayListAddressByMediaType_TYPE_PHOTO();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_GetPlayListAddressByMediaType_TYPE_MUSIC();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_GetPlayListAddressByMediaType_TYPE_MOVIE();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_GetPlayListAddressByMediaType_TYPE_TEXT();
void TestSuite_mapp_mplayer_test_MApp_IsMedia_File_ByExtName_TYPE_INVALID();
void TestSuite_mapp_mplayer_test_MAPP_MPlayer_GetMusicTotalFileNum();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_ReCalcMPlayerPlayingIdx_PHOTO_AddToList_Belowcase();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_ReCalcMPlayerPlayingIdx_PHOTO_AddToList_Abovecase();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_ReCalcMPlayerPlayingIdx_PHOTO_AddToList_Amongcase();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_ReCalcMPlayerPlayingIdx_PHOTO_RemoveFromList_Belowcase();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_ReCalcMPlayerPlayingIdx_PHOTO_RemoveFromList_Abovecase();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_ReCalcMPlayerPlayingIdx_PHOTO_RemoveFromList_Amongcase_StartIdx_Equals_zero();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_ReCalcMPlayerPlayingIdx_PHOTO_RemoveFromList_Amongcase_EndIdx_Equals_SelectedFileNum_minus_one();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_ReCalcMPlayerPlayingIdx_PHOTO_RemoveFromList_Amongcase_Other();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_ToUpper_Uppercase();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_ToUpper_Lowercase();
void TestSuite_mapp_mplayer_test_MApp_MPLayer_GetSubtitleTypeByFileExtName_TYPE_INVALID();
void TestSuite_mapp_mplayer_test_MApp_MPLayer_GetSubtitleTypeByFileExtName_TYPE_SRT();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_PlayAgain();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_SetCurrentFile_CURRENT_PAGE_FAIL();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_SetCurrentFile_CURRENT_DIRECTORY_FAIL();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_SetCurrentFile_CURRENT_DIRECTORY_OK();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_SetCurrentFile_TYPE_NUM_FAIL();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_EnterCopyMode();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_ExitCopyMode();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryIsCopyMode();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_StopCopy();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryPasteFileStatus();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryPasteFileStatus_Return_zero();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCopying_TRUE();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCopying_FALSE();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentSelectedCopyingFileIndex();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_StopDelete();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_DeleteNext_FALSE_worng_selected_file_number();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_DeleteNext_FALSE_no_selected_file();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_DeleteNext_TRUE();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsDeleting_TRUE();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsDeleting_FALSE();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentSelectedDeletingFileIndex();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryDeleteFileStatus_In_delete_play();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryDeleteFileStatus_Not_in_delete_play();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurMovieAudioLanguage_en();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurMovieSubtitleLanguage_External();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurMovieSubtitleLanguage_Interal();
void TestSuite_mapp_mplayer_test__MApp_MPlayer_SubtitleTask_External_Text();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_GetPlayListFileInfo_Music();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_Stop_Music_E_MPLAYER_RET_OK();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_Stop_Movie_E_MPLAYER_RET_OK();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_PlayPrevFile_Music_E_MPLAYER_RET_OK();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_PlayPrevFile_Movie_E_MPLAYER_RET_OK();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_SetCurrentPlayingList_Music_u16PLIndex_Over20u16PlayListNum();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_PlayMusic_E_MPLAYER_PLAY_ONE_DIRECTORY_E_MPLAYER_RET_OK();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_PlayMusic_NotMusic_m_u16SelectedFileNum_0_E_MPLAYER_RET_FAIL();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_PlayMusic_NotMusic_m_u16SelectedFileNum_1_E_MPLAYER_RET_FAIL();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_GetFileEntryByPlaylistIndex_TRUE();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCurSubtitleText_TRUE();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCurSubtitleExternal_TRUE();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCurSubtitleText_FALSE();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_PrevPage_CurPageIdx_equal_zero();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_PrevPage_FilePerPage_equal_zero();
void TestSuite_mapp_mplayer_test_MApp_MPlayer_PrevPage_FilePerPage_not_equal_zero();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_mapp_mplayer);

void TestSuite_mapp_mplayer_setUp()
{
}

void TestSuite_mapp_mplayer_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_IsMusicRecording_true */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_MPlayer_IsMusicRecording(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsMusicRecording_true()
{
    /* Pre-condition initialization */
    /* Initializing global variable bMusicRecording */
    {
         bMusicRecording  = 1;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_MPlayer_IsMusicRecording();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_IsMusicRecording_true */

/* CPPTEST_TEST_CASE_CONTEXT U16 MApp_MPlayer_QueryCurrentPlayingList(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentPlayingList_Photo()
{
     m_u32PhotoCurrentDisplayedIdx  = 0ul;
     m_eMediaType  = E_MPLAYER_TYPE_PHOTO;
     {
        U16 _return  = MApp_MPlayer_QueryCurrentPlayingList();
        CPPTEST_ASSERT_UINTEGER_EQUAL(m_u32PhotoCurrentDisplayedIdx, ( _return ) );
     }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentPlayingList_Music()
{
     m_MPlayerInfo[E_MPLAYER_BACKGROUND_PLAYER].u16PlayingIdx = 1;
     m_eMediaType  = E_MPLAYER_TYPE_MUSIC;
     {
        U16 _return  = MApp_MPlayer_QueryCurrentPlayingList();
        CPPTEST_ASSERT_UINTEGER_EQUAL(m_MPlayerInfo[E_MPLAYER_BACKGROUND_PLAYER].u16PlayingIdx, ( _return ) );
     }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentPlayingList_Movie()
{
     m_MPlayerInfo[E_MPLAYER_FOREGROUND_PLAYER].u16PlayingIdx = 1;
     m_eMediaType  = E_MPLAYER_TYPE_MOVIE;
    {
       U16 _return  = MApp_MPlayer_QueryCurrentPlayingList();
       CPPTEST_ASSERT_UINTEGER_EQUAL(m_MPlayerInfo[E_MPLAYER_FOREGROUND_PLAYER].u16PlayingIdx, ( _return ) );
    }
}

/* CPPTEST_TEST_CASE_CONTEXT U16 MMApp_MPlayer_QueryBGMPlayingList(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryBGMPlayingList()
{
     m_MPlayerInfo[E_MPLAYER_BACKGROUND_PLAYER].u16PlayingIdx = 2;
    {
       U16 _return  = MApp_MPlayer_QueryBGMPlayingList();
       CPPTEST_ASSERT_UINTEGER_EQUAL(m_MPlayerInfo[E_MPLAYER_BACKGROUND_PLAYER].u16PlayingIdx, ( _return ) );
    }
}

/* CPPTEST_TEST_CASE_CONTEXT U16 MApp_MPlayer_QueryCurrentFileIndex(enumMPlayerFileIndexBegin eBegin) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentFileIndex_u16CurFileIdx_equals_INVALID_INDEX()
{
    m_u16CurFileIdx = MPLAYER_INVALID_INDEX;
    {
       U16 _return  = MApp_MPlayer_QueryCurrentFileIndex(E_MPLAYER_INDEX_CURRENT_DIRECTORY);
       CPPTEST_ASSERT_UINTEGER_EQUAL(MPLAYER_INVALID_INDEX, ( _return ) );
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentFileIndex_INDEX_CURRENT_DIRECTORY()
{
    m_u16CurFileIdx = 2;
    {
       U16 _return  = MApp_MPlayer_QueryCurrentFileIndex(E_MPLAYER_INDEX_CURRENT_DIRECTORY);
       CPPTEST_ASSERT_UINTEGER_EQUAL(m_u16CurFileIdx, ( _return ) );
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentFileIndex_INDEX_CURRENT_PAGE_case1()
{
    //m_u16CurFileIdx < m_u16CurPage1stFileIdx
    m_u16CurFileIdx = 2;
    m_u16CurPage1stFileIdx = 100;
    {
       U16 _return  = MApp_MPlayer_QueryCurrentFileIndex(E_MPLAYER_INDEX_CURRENT_PAGE);
       CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentFileIndex_INDEX_CURRENT_PAGE_case2()
{
    //m_u16CurFileIdx == m_u16CurPage1stFileIdx
    m_u16CurFileIdx = 100;
    m_u16CurPage1stFileIdx = 100;
    {
       U16 _return  = MApp_MPlayer_QueryCurrentFileIndex(E_MPLAYER_INDEX_CURRENT_PAGE);
       CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentFileIndex_INDEX_CURRENT_PAGE_case3()
{
    //m_u16CurFileIdx > m_u16CurPage1stFileIdx
    m_u16CurFileIdx = 101;
    m_u16CurPage1stFileIdx = 100;
    {
       U16 _return  = MApp_MPlayer_QueryCurrentFileIndex(E_MPLAYER_INDEX_CURRENT_PAGE);
       CPPTEST_ASSERT_UINTEGER_EQUAL((m_u16CurFileIdx-m_u16CurPage1stFileIdx), ( _return ) );
    }
}

/* CPPTEST_TEST_CASE_CONTEXT U16 MApp_MPlayer_QueryTotalPages(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryTotalPages()
{
    m_u16TotalPageNum = 10;
    {
       U16 _return  = MApp_MPlayer_QueryTotalPages();
       CPPTEST_ASSERT_UINTEGER_EQUAL(m_u16TotalPageNum, ( _return ) );
    }
}

/* CPPTEST_TEST_CASE_CONTEXT enumMPlayerRet MApp_MPlayer_IsCurrentExternalSubtitleAvailable(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCurrentExternalSubtitleAvailable_Is_RET_OK()
{
    m_MPlayerInfo[E_MPLAYER_FOREGROUND_PLAYER].eKnlFlag1 |= E_MPLAYER_KNL_FLG1_SUBTITLE_EXTERNAL;
    {
       enumMPlayerRet _return  = MApp_MPlayer_IsCurrentExternalSubtitleAvailable();
       CPPTEST_ASSERT_UINTEGER_EQUAL(E_MPLAYER_RET_OK, ( _return ) );
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCurrentExternalSubtitleAvailable_Is_RET_FAIL()
{
    m_MPlayerInfo[E_MPLAYER_FOREGROUND_PLAYER].eKnlFlag1 &= (enumMPlayerKnlFlags1)~E_MPLAYER_KNL_FLG1_SUBTITLE_EXTERNAL;
    {
       enumMPlayerRet _return  = MApp_MPlayer_IsCurrentExternalSubtitleAvailable();
       CPPTEST_ASSERT_UINTEGER_EQUAL(E_MPLAYER_RET_FAIL, ( _return ) );
    }
}

/* CPPTEST_TEST_CASE_CONTEXT enumMPlayerRet MApp_MPlayer_IsCurrentExternalSubtitleAvailable(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCurrentLRCLyricAvailable_Is_RET_OK()
{
    m_MPlayerInfo[E_MPLAYER_FOREGROUND_PLAYER].eKnlFlag1 |= E_MPLAYER_KNL_FLG1_LYRIC_VALID;
    {
       enumMPlayerRet _return  = MApp_MPlayer_IsCurrentLRCLyricAvailable();
       CPPTEST_ASSERT_UINTEGER_EQUAL(E_MPLAYER_RET_OK, ( _return ) );
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCurrentLRCLyricAvailable_Is_RET_FAIL()
{
    m_MPlayerInfo[E_MPLAYER_FOREGROUND_PLAYER].eKnlFlag1 &= (enumMPlayerKnlFlags1)~E_MPLAYER_KNL_FLG1_LYRIC_VALID;
    {
       enumMPlayerRet _return  = MApp_MPlayer_IsCurrentLRCLyricAvailable();
       CPPTEST_ASSERT_UINTEGER_EQUAL(E_MPLAYER_RET_FAIL, ( _return ) );
    }
}

/* CPPTEST_TEST_CASE_CONTEXT enumMPlayerPlayMode MApp_MPlayer_QueryPlayMode(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryPlayMode()
{
    m_ePlayMode = E_MPLAYER_PLAY_SELECTED;
    {
       enumMPlayerPlayMode _return  = MApp_MPlayer_QueryPlayMode();
       CPPTEST_ASSERT_UINTEGER_EQUAL(E_MPLAYER_PLAY_SELECTED, ( _return ) );
    }
}

/* CPPTEST_TEST_CASE_CONTEXT enumMPlayerMediaSubType MApp_MPlayer_QueryCurrentMediaSubType(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentMediaSubType()
{
	m_MPlayerInfo[E_MPLAYER_FOREGROUND_PLAYER].eMediaSubType = E_MPLAYER_SUBTYPE_JPG;
    {
       enumMPlayerPlayMode _return  = MApp_MPlayer_QueryCurrentMediaSubType();
       CPPTEST_ASSERT_UINTEGER_EQUAL(E_MPLAYER_SUBTYPE_JPG, ( _return ) );
    }
}

/* CPPTEST_TEST_CASE_CONTEXT enumMPlayerPhotoPlayMode MApp_MPlayer_QueryPhotoPlayMode(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryPhotoPlayMode_Is_PHOTO_PAUSE()
{
    m_MPlayerInfo[E_MPLAYER_FOREGROUND_PLAYER].eMediaPlayingStatus |= E_MPLAYER_PHOTO_STATE_PAUSE;
    {
       enumMPlayerPhotoPlayMode _return  = MApp_MPlayer_QueryPhotoPlayMode();
       CPPTEST_ASSERT_UINTEGER_EQUAL(E_MPLAYER_PHOTO_PAUSE, ( _return ) );
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryPhotoPlayMode_Is_PHOTO_NORMAL()
{
    m_MPlayerInfo[E_MPLAYER_FOREGROUND_PLAYER].eMediaPlayingStatus &= (enumMediaPlayingStatus)~ E_MPLAYER_PHOTO_STATE_PAUSE;
    {
       enumMPlayerPhotoPlayMode _return  = MApp_MPlayer_QueryPhotoPlayMode();
       CPPTEST_ASSERT_UINTEGER_EQUAL(E_MPLAYER_PHOTO_NORMAL, ( _return ) );
    }
}

/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_IsSupportedMusic(enumMPlayerMediaSubType eMediaSubType) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMusic_FLAC()
{
    enumMPlayerMediaSubType eMediaSubType = E_MPLAYER_SUBTYPE_FLAC;
    {
       BOOLEAN _return  = _MApp_MPlayer_IsSupportedMusic(eMediaSubType);
       CPPTEST_ASSERT_UINTEGER_EQUAL(TRUE, ( _return ) );
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMusic_WMA()
{
    enumMPlayerMediaSubType eMediaSubType = E_MPLAYER_SUBTYPE_WMA;
    {
       BOOLEAN _return  = _MApp_MPlayer_IsSupportedMusic(eMediaSubType);
       CPPTEST_ASSERT_UINTEGER_EQUAL(TRUE, ( _return ) );
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMusic_AAC()
{
    enumMPlayerMediaSubType eMediaSubType = E_MPLAYER_SUBTYPE_AAC;
    {
       BOOLEAN _return  = _MApp_MPlayer_IsSupportedMusic(eMediaSubType);
       CPPTEST_ASSERT_UINTEGER_EQUAL(TRUE, ( _return ) );
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMusic_WAV()
{
    enumMPlayerMediaSubType eMediaSubType = E_MPLAYER_SUBTYPE_WAV;
    {
       BOOLEAN _return  = _MApp_MPlayer_IsSupportedMusic(eMediaSubType);
       CPPTEST_ASSERT_UINTEGER_EQUAL(TRUE, ( _return ) );
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMusic_MP3()
{
    enumMPlayerMediaSubType eMediaSubType = E_MPLAYER_SUBTYPE_MP3;
    {
       BOOLEAN _return  = _MApp_MPlayer_IsSupportedMusic(eMediaSubType);
       CPPTEST_ASSERT_UINTEGER_EQUAL(TRUE, ( _return ) );
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMusic_default()
{
    enumMPlayerMediaSubType eMediaSubType = E_MPLAYER_SUBTYPE_JPG;
    {
       BOOLEAN _return  = _MApp_MPlayer_IsSupportedMusic(eMediaSubType);
       CPPTEST_ASSERT_UINTEGER_EQUAL(FALSE, ( _return ) );
    }
}

/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_GetNotifyRtn(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_GetNotifyRtn()
{
    m_bNotifyRtn = TRUE;
    {
       BOOLEAN _return  = _MApp_MPlayer_GetNotifyRtn();
       CPPTEST_ASSERT_UINTEGER_EQUAL(TRUE, ( _return ) );
    }
}

/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_IsSupportedMovie(enumMPlayerMediaSubType eMediaSubType) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMovie_FALSE_PHOTO()
{
    enumMPlayerMediaSubType eMediaSubType = E_MPLAYER_SUBTYPE_JPG;
    {
       BOOLEAN _return  = _MApp_MPlayer_IsSupportedMovie(eMediaSubType);
       CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ) );
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMovie_FALSE_MUSIC()
{
    enumMPlayerMediaSubType eMediaSubType = E_MPLAYER_SUBTYPE_MP3;
    {
       BOOLEAN _return  = _MApp_MPlayer_IsSupportedMovie(eMediaSubType);
       CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ) );
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsSupportedMovie_TRUE_MOVIE()
{
    enumMPlayerMediaSubType eMediaSubType = E_MPLAYER_SUBTYPE_TS;
    {
       BOOLEAN _return  = _MApp_MPlayer_IsSupportedMovie(eMediaSubType);
       CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
    }
}

/* CPPTEST_TEST_CASE_CONTEXT int _MApp_MPlayer_ToLower(U16 c) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_ToLower_Uppercase()
{
    U16 letter = 'A';
    {
       U16 _return  = _MApp_MPlayer_ToLower(letter);
       CPPTEST_ASSERT_EQUAL('a', ( _return ) );
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_ToLower_Lowercase()
{
    U16 letter = 'a';
    {
       U16 _return  = _MApp_MPlayer_ToLower(letter);
       CPPTEST_ASSERT_EQUAL('a', ( _return ) );
    }
}

/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_GetPlayListAddressByMediaType(enumMPlayerMediaType eMediaType, U32 *pu32XdataWindowBase) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_GetPlayListAddressByMediaType_TYPE_INVALID()
{
    enumMPlayerMediaType eMediaType = E_MPLAYER_TYPE_INVALID;
    U32 _pu32XdataWindowBase;
    {
       BOOLEAN _return  = _MApp_MPlayer_GetPlayListAddressByMediaType(eMediaType,&_pu32XdataWindowBase);
       CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ) );
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_GetPlayListAddressByMediaType_NULL()
{
    enumMPlayerMediaType eMediaType = E_MPLAYER_TYPE_PHOTO;
    {
       BOOLEAN _return  = _MApp_MPlayer_GetPlayListAddressByMediaType(eMediaType,NULL);
       CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ) );
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_GetPlayListAddressByMediaType_TYPE_PHOTO()
{
    enumMPlayerMediaType eMediaType = E_MPLAYER_TYPE_PHOTO;
    U32 _pu32XdataWindowBase;
    {
       BOOLEAN _return  = _MApp_MPlayer_GetPlayListAddressByMediaType(eMediaType,&_pu32XdataWindowBase);
       CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
       if(MPLAYER_PHOTO_PLAYLIST_MEMORY_TYPE & MIU1)
       {
           CPPTEST_ASSERT_EQUAL((MPLAYER_PHOTO_PLAYLIST_ADR | MIU_INTERVAL),_pu32XdataWindowBase);
       }
       else
       {
           CPPTEST_ASSERT_EQUAL((MPLAYER_PHOTO_PLAYLIST_ADR),_pu32XdataWindowBase);
       }
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_GetPlayListAddressByMediaType_TYPE_MUSIC()
{
    enumMPlayerMediaType eMediaType = E_MPLAYER_TYPE_MUSIC;
    U32 _pu32XdataWindowBase;
    {
       BOOLEAN _return  = _MApp_MPlayer_GetPlayListAddressByMediaType(eMediaType,&_pu32XdataWindowBase);
       CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
       if(MPLAYER_MUSIC_PLAYLIST_MEMORY_TYPE & MIU1)
       {
           CPPTEST_ASSERT_EQUAL((MPLAYER_MUSIC_PLAYLIST_ADR | MIU_INTERVAL),_pu32XdataWindowBase);
       }
       else
       {
           CPPTEST_ASSERT_EQUAL((MPLAYER_MUSIC_PLAYLIST_ADR),_pu32XdataWindowBase);
       }
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_GetPlayListAddressByMediaType_TYPE_MOVIE()
{
    enumMPlayerMediaType eMediaType = E_MPLAYER_TYPE_MOVIE;
    U32 _pu32XdataWindowBase;
    {
       BOOLEAN _return  = _MApp_MPlayer_GetPlayListAddressByMediaType(eMediaType,&_pu32XdataWindowBase);
       CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
       if(MPLAYER_MOVIE_PLAYLIST_MEMORY_TYPE & MIU1)
       {
           CPPTEST_ASSERT_EQUAL((MPLAYER_MOVIE_PLAYLIST_ADR | MIU_INTERVAL),_pu32XdataWindowBase);
       }
       else
       {
           CPPTEST_ASSERT_EQUAL((MPLAYER_MOVIE_PLAYLIST_ADR),_pu32XdataWindowBase);
       }
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_GetPlayListAddressByMediaType_TYPE_TEXT()
{
    enumMPlayerMediaType eMediaType = E_MPLAYER_TYPE_TEXT;
    U32 _pu32XdataWindowBase;
    {
       BOOLEAN _return  = _MApp_MPlayer_GetPlayListAddressByMediaType(eMediaType,&_pu32XdataWindowBase);
       CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
       if(MPLAYER_TEXT_PLAYLIST_MEMORY_TYPE & MIU1)
       {
           CPPTEST_ASSERT_EQUAL((MPLAYER_TEXT_PLAYLIST_ADR | MIU_INTERVAL),_pu32XdataWindowBase);
       }
       else
       {
           CPPTEST_ASSERT_EQUAL((MPLAYER_TEXT_PLAYLIST_ADR),_pu32XdataWindowBase);
       }
    }
}

/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_IsMedia_File_ByExtName(enumMPlayerMediaSubType eType, U8 *pu8ExtName) */
void TestSuite_mapp_mplayer_test_MApp_IsMedia_File_ByExtName_TYPE_INVALID()
{
    enumMPlayerMediaSubType eType = E_MPLAYER_SUBTYPE_INVALID;
    U8 pu8ExtName[4]={'j','p','g',' '};
    {
       BOOLEAN _return  = _MApp_IsMedia_File_ByExtName(eType,&pu8ExtName);
       CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ) );
    }
}

/* CPPTEST_TEST_CASE_CONTEXT U16 MAPP_MPlayer_GetMusicTotalFileNum(void) */
void TestSuite_mapp_mplayer_test_MAPP_MPlayer_GetMusicTotalFileNum()
{
    m_u16RealMusicFileNum = 5;
    {
       U16 _return  = MAPP_MPlayer_GetMusicTotalFileNum();
       CPPTEST_ASSERT_EQUAL(m_u16RealMusicFileNum, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_CONTEXT _MApp_MPlayer_ReCalcMPlayerPlayingIdx(enumMPlayerMediaType eMediaType, BOOLEAN bAddToList, U16 u16StartIdx, U16 u16EndIdx)*/
void TestSuite_mapp_mplayer_test_MApp_MPlayer_ReCalcMPlayerPlayingIdx_PHOTO_AddToList_Belowcase()
{
    enumMPlayerMediaType eMediaType = E_MPLAYER_TYPE_PHOTO;
    enumMPlayerIdx eMPlayerIdx = E_MPLAYER_FOREGROUND_PLAYER;
    BOOLEAN bAddToList = TRUE;
    U16 u16StartIdx = 2;
    U16 u16EndIdx = 10;
    m_MPlayerInfo[eMPlayerIdx].eKnlFlag1 |= E_MPLAYER_KNL_FLG1_PHOTO_PLAY;
    m_MPlayerInfo[eMPlayerIdx].u16PlayingIdx = 1;
    m_MPlayerInfo[eMPlayerIdx].eMediaType = eMediaType;
    {
        U16 u16PlayingIdx = m_MPlayerInfo[eMPlayerIdx].u16PlayingIdx;
       _MApp_MPlayer_ReCalcMPlayerPlayingIdx(eMediaType, bAddToList, u16StartIdx, u16EndIdx);
       CPPTEST_ASSERT_EQUAL(u16PlayingIdx, m_MPlayerInfo[eMPlayerIdx].u16PlayingIdx);
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_ReCalcMPlayerPlayingIdx_PHOTO_AddToList_Abovecase()
{
    enumMPlayerMediaType eMediaType = E_MPLAYER_TYPE_PHOTO;
    enumMPlayerIdx eMPlayerIdx = E_MPLAYER_FOREGROUND_PLAYER;
    BOOLEAN bAddToList = TRUE;
    U16 u16StartIdx = 2;
    U16 u16EndIdx = 10;
    m_MPlayerInfo[eMPlayerIdx].eKnlFlag1 |= E_MPLAYER_KNL_FLG1_PHOTO_PLAY;
    m_MPlayerInfo[eMPlayerIdx].u16PlayingIdx = 11;
    m_MPlayerInfo[eMPlayerIdx].eMediaType = eMediaType;
    {
        U16 u16PlayingIdx = m_MPlayerInfo[eMPlayerIdx].u16PlayingIdx + (u16EndIdx - u16StartIdx + 1);
       _MApp_MPlayer_ReCalcMPlayerPlayingIdx(eMediaType, bAddToList, u16StartIdx, u16EndIdx);
       CPPTEST_ASSERT_EQUAL(u16PlayingIdx, m_MPlayerInfo[eMPlayerIdx].u16PlayingIdx);
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_ReCalcMPlayerPlayingIdx_PHOTO_AddToList_Amongcase()
{
    enumMPlayerMediaType eMediaType = E_MPLAYER_TYPE_PHOTO;
    enumMPlayerIdx eMPlayerIdx = E_MPLAYER_FOREGROUND_PLAYER;
    BOOLEAN bAddToList = TRUE;
    U16 u16StartIdx = 2;
    U16 u16EndIdx = 10;
    m_MPlayerInfo[eMPlayerIdx].eKnlFlag1 |= E_MPLAYER_KNL_FLG1_PHOTO_PLAY;
    m_MPlayerInfo[eMPlayerIdx].u16PlayingIdx = 5;
    m_MPlayerInfo[eMPlayerIdx].eMediaType = eMediaType;
    {
        U16 u16PlayingIdx = m_MPlayerInfo[eMPlayerIdx].u16PlayingIdx;
       _MApp_MPlayer_ReCalcMPlayerPlayingIdx(eMediaType, bAddToList, u16StartIdx, u16EndIdx);
       CPPTEST_ASSERT_EQUAL(u16PlayingIdx, m_MPlayerInfo[eMPlayerIdx].u16PlayingIdx);
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_ReCalcMPlayerPlayingIdx_PHOTO_RemoveFromList_Belowcase()
{
    enumMPlayerMediaType eMediaType = E_MPLAYER_TYPE_PHOTO;
    enumMPlayerIdx eMPlayerIdx = E_MPLAYER_FOREGROUND_PLAYER;
    BOOLEAN bAddToList = FALSE;
    U16 u16StartIdx = 2;
    U16 u16EndIdx = 10;
    m_MPlayerInfo[eMPlayerIdx].eKnlFlag1 |= E_MPLAYER_KNL_FLG1_PHOTO_PLAY;
    m_MPlayerInfo[eMPlayerIdx].u16PlayingIdx = 1;
    m_MPlayerInfo[eMPlayerIdx].eMediaType = eMediaType;
    {
        U16 u16PlayingIdx = m_MPlayerInfo[eMPlayerIdx].u16PlayingIdx;
       _MApp_MPlayer_ReCalcMPlayerPlayingIdx(eMediaType, bAddToList, u16StartIdx, u16EndIdx);
       CPPTEST_ASSERT_EQUAL(u16PlayingIdx, m_MPlayerInfo[eMPlayerIdx].u16PlayingIdx);
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_ReCalcMPlayerPlayingIdx_PHOTO_RemoveFromList_Abovecase()
{
    enumMPlayerMediaType eMediaType = E_MPLAYER_TYPE_PHOTO;
    enumMPlayerIdx eMPlayerIdx = E_MPLAYER_FOREGROUND_PLAYER;
    BOOLEAN bAddToList = FALSE;
    U16 u16StartIdx = 2;
    U16 u16EndIdx = 10;
    m_MPlayerInfo[eMPlayerIdx].eKnlFlag1 |= E_MPLAYER_KNL_FLG1_PHOTO_PLAY;
    m_MPlayerInfo[eMPlayerIdx].u16PlayingIdx = 11;
    m_MPlayerInfo[eMPlayerIdx].eMediaType = eMediaType;
    {
        U16 u16PlayingIdx = m_MPlayerInfo[eMPlayerIdx].u16PlayingIdx - (u16EndIdx - u16StartIdx + 1);
       _MApp_MPlayer_ReCalcMPlayerPlayingIdx(eMediaType, bAddToList, u16StartIdx, u16EndIdx);
       CPPTEST_ASSERT_EQUAL(u16PlayingIdx, m_MPlayerInfo[eMPlayerIdx].u16PlayingIdx);
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_ReCalcMPlayerPlayingIdx_PHOTO_RemoveFromList_Amongcase_StartIdx_Equals_zero()
{
    enumMPlayerMediaType eMediaType = E_MPLAYER_TYPE_PHOTO;
    enumMPlayerIdx eMPlayerIdx = E_MPLAYER_FOREGROUND_PLAYER;
    BOOLEAN bAddToList = FALSE;
    U16 u16StartIdx = 0;
    U16 u16EndIdx = 10;
    m_MPlayerInfo[eMPlayerIdx].eKnlFlag1 |= E_MPLAYER_KNL_FLG1_PHOTO_PLAY;
    m_MPlayerInfo[eMPlayerIdx].u16PlayingIdx = 5;
    m_MPlayerInfo[eMPlayerIdx].eMediaType = eMediaType;
    {
        U16 u16PlayingIdx = m_MPlayerInfo[eMPlayerIdx].u16PlayingIdx;
       _MApp_MPlayer_ReCalcMPlayerPlayingIdx(eMediaType, bAddToList, u16StartIdx, u16EndIdx);
       CPPTEST_ASSERT_EQUAL(u16PlayingIdx, m_MPlayerInfo[eMPlayerIdx].u16PlayingIdx);
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_ReCalcMPlayerPlayingIdx_PHOTO_RemoveFromList_Amongcase_EndIdx_Equals_SelectedFileNum_minus_one()
{
    enumMPlayerMediaType eMediaType = E_MPLAYER_TYPE_PHOTO;
    enumMPlayerIdx eMPlayerIdx = E_MPLAYER_FOREGROUND_PLAYER;
    BOOLEAN bAddToList = FALSE;
    U16 u16StartIdx = 2;
    U16 u16EndIdx = 10;
    m_MPlayerInfo[eMPlayerIdx].eKnlFlag1 |= E_MPLAYER_KNL_FLG1_PHOTO_PLAY;
    m_MPlayerInfo[eMPlayerIdx].u16PlayingIdx = 5;
    m_MPlayerInfo[eMPlayerIdx].eMediaType = eMediaType;
    m_eMediaType = eMediaType;
    m_u16SelectedFileNum[m_eMediaType] = u16EndIdx+1;
    {
        U16 u16PlayingIdx = u16EndIdx;
       _MApp_MPlayer_ReCalcMPlayerPlayingIdx(eMediaType, bAddToList, u16StartIdx, u16EndIdx);
       CPPTEST_ASSERT_EQUAL(u16PlayingIdx, m_MPlayerInfo[eMPlayerIdx].u16PlayingIdx);
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_ReCalcMPlayerPlayingIdx_PHOTO_RemoveFromList_Amongcase_Other()
{
    enumMPlayerMediaType eMediaType = E_MPLAYER_TYPE_PHOTO;
    enumMPlayerIdx eMPlayerIdx = E_MPLAYER_FOREGROUND_PLAYER;
    BOOLEAN bAddToList = FALSE;
    U16 u16StartIdx = 2;
    U16 u16EndIdx = 10;
    m_MPlayerInfo[eMPlayerIdx].eKnlFlag1 |= E_MPLAYER_KNL_FLG1_PHOTO_PLAY;
    m_MPlayerInfo[eMPlayerIdx].u16PlayingIdx = 5;
    m_MPlayerInfo[eMPlayerIdx].eMediaType = eMediaType;
    m_eMediaType = eMediaType;
    m_u16SelectedFileNum[m_eMediaType] = 0;
    {
        U16 u16PlayingIdx = u16StartIdx;
       _MApp_MPlayer_ReCalcMPlayerPlayingIdx(eMediaType, bAddToList, u16StartIdx, u16EndIdx);
       CPPTEST_ASSERT_EQUAL(u16PlayingIdx, m_MPlayerInfo[eMPlayerIdx].u16PlayingIdx);
    }
}

/* CPPTEST_TEST_CASE_CONTEXT void _MApp_MPlayer_ToUpper(U8 *pu8Data, U16 u16Len) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_ToUpper_Uppercase()
{
    U8 pu8ExtName[4]={'A','B','C','D'};
    {
       _MApp_MPlayer_ToUpper(&pu8ExtName,sizeof(pu8ExtName));
       CPPTEST_ASSERT_EQUAL('A', pu8ExtName[0]);
       CPPTEST_ASSERT_EQUAL('B', pu8ExtName[1]);
       CPPTEST_ASSERT_EQUAL('C', pu8ExtName[2]);
       CPPTEST_ASSERT_EQUAL('D', pu8ExtName[3]);
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_ToUpper_Lowercase()
{
    U8 pu8ExtName[4]={'a','b','c','d'};
    {
       _MApp_MPlayer_ToUpper(&pu8ExtName,sizeof(pu8ExtName));
       CPPTEST_ASSERT_EQUAL('A', pu8ExtName[0]);
       CPPTEST_ASSERT_EQUAL('B', pu8ExtName[1]);
       CPPTEST_ASSERT_EQUAL('C', pu8ExtName[2]);
       CPPTEST_ASSERT_EQUAL('D', pu8ExtName[3]);
    }
}

/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPLayer_GetSubtitleTypeByFileExtName(enumMPlayerSubtitleType *peType, U8* pExtFileName) */
void TestSuite_mapp_mplayer_test_MApp_MPLayer_GetSubtitleTypeByFileExtName_TYPE_INVALID()
{
    enumMPlayerSubtitleType eType = E_MPLAYER_SUBTITLE_INVALID;
    U8 pu8ExtName[4]={'j','p','g',' '};
    {
       BOOLEAN _return  = _MApp_MPLayer_GetSubtitleTypeByFileExtName(&eType,&pu8ExtName);
       CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ) );
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPLayer_GetSubtitleTypeByFileExtName_TYPE_SRT()
{
    enumMPlayerSubtitleType eType = E_MPLAYER_SUBTITLE_INVALID;
    U8 pu8ExtName[4]={'s','r','t',' '};
    {
       BOOLEAN _return  = _MApp_MPLayer_GetSubtitleTypeByFileExtName(&eType,&pu8ExtName);
       CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
       CPPTEST_ASSERT_EQUAL(E_MPLAYER_SUBTITLE_SRT, eType);
    }
}

/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_PlayAgain(enumMPlayerIdx eMPlayerIdx) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_PlayAgain()
{
    enumMPlayerIdx eMPlayerIdx = E_MPLAYER_FOREGROUND_PLAYER;
    {
        BOOLEAN _return  = _MApp_MPlayer_PlayAgain(eMPlayerIdx);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, (m_MPlayerInfo[eMPlayerIdx].eKnlFlag1 & E_MPLAYER_KNL_FLG1_FILE_INIT));
    }
}

/* CPPTEST_TEST_CASE_CONTEXT enumMPlayerRet MApp_MPlayer_SetCurrentFile(enumMPlayerFileIndexBegin eBegin, U16 u16FileIdx)*/
void TestSuite_mapp_mplayer_test_MApp_MPlayer_SetCurrentFile_CURRENT_PAGE_FAIL()
{
    enumMPlayerFileIndexBegin eBegin = E_MPLAYER_INDEX_CURRENT_PAGE;
    U16 u16FileIdx = 3;
    m_u16CurFileIdx = 5;
    {
        U16 u16CurIdx = m_u16CurFileIdx;
        enumMPlayerRet _return  = MApp_MPlayer_SetCurrentFile(eBegin, u16FileIdx);
        CPPTEST_ASSERT_EQUAL(E_MPLAYER_RET_FAIL, ( _return ));
        CPPTEST_ASSERT_EQUAL(u16CurIdx, m_u16CurFileIdx);
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_SetCurrentFile_CURRENT_DIRECTORY_FAIL()
{
    enumMPlayerFileIndexBegin eBegin = E_MPLAYER_INDEX_CURRENT_DIRECTORY;
    U16 u16FileIdx = 10;
    m_u16TotalFileNum = 5;
    m_u16CurFileIdx = 4;
    {
        U16 u16CurIdx = m_u16CurFileIdx;
        enumMPlayerRet _return  = MApp_MPlayer_SetCurrentFile(eBegin, u16FileIdx);
        CPPTEST_ASSERT_EQUAL(E_MPLAYER_RET_FAIL, ( _return ));
        CPPTEST_ASSERT_EQUAL(u16CurIdx, m_u16CurFileIdx);
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_SetCurrentFile_CURRENT_DIRECTORY_OK()
{
    enumMPlayerFileIndexBegin eBegin = E_MPLAYER_INDEX_CURRENT_DIRECTORY;
    U16 u16FileIdx = 4;
    m_u16TotalFileNum = 5;
    m_u16CurFileIdx = 3;
    {
        enumMPlayerRet _return  = MApp_MPlayer_SetCurrentFile(eBegin, u16FileIdx);
        CPPTEST_ASSERT_EQUAL(E_MPLAYER_RET_OK, ( _return ));
        CPPTEST_ASSERT_EQUAL(m_u16CurFileIdx, u16FileIdx);
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_SetCurrentFile_TYPE_NUM_FAIL()
{
    enumMPlayerFileIndexBegin eBegin = E_MPLAYER_INDEX_TYPE_NUM;
    U16 u16FileIdx = 10;
    m_u16TotalFileNum = 5;
    m_u16CurFileIdx = 4;
    {
        U16 u16CurIdx = m_u16CurFileIdx;
        enumMPlayerRet _return  = MApp_MPlayer_SetCurrentFile(eBegin, u16FileIdx);
        CPPTEST_ASSERT_EQUAL(E_MPLAYER_RET_FAIL, ( _return ));
        CPPTEST_ASSERT_EQUAL(u16CurIdx, m_u16CurFileIdx);
    }
}

/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_MPlayer_EnterCopyMode(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_EnterCopyMode()
{
    {
        BOOLEAN _return  = MApp_MPlayer_EnterCopyMode();
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, m_bIsCopyMode);
    }
}

/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_MPlayer_ExitCopyMode(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_ExitCopyMode()
{
    {
        BOOLEAN _return  = MApp_MPlayer_ExitCopyMode();
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, m_bIsCopyMode);
    }
}

/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_MPlayer_QueryIsCopyMode(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryIsCopyMode()
{
    m_bIsCopyMode = TRUE;
    {
        BOOLEAN _return  = MApp_MPlayer_QueryIsCopyMode();
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
    }
}

/* CPPTEST_TEST_CASE_CONTEXT void MApp_MPlayer_StopCopy(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_StopCopy()
{
    {
        MApp_MPlayer_StopCopy();
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, m_bUserBreakCopy );
    }
}

/* CPPTEST_TEST_CASE_CONTEXT U16 MApp_MPlayer_QueryPasteFileStatus(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryPasteFileStatus()
{
    m_eMPlayerKnlFlags |= E_MPLAYER_KNL_FLG_COPY_PLAY;
    m_u32TotalCopiedPercentage = 60;
    {
        U32 _return = MApp_MPlayer_QueryPasteFileStatus();
        CPPTEST_ASSERT_EQUAL(_return, m_u32TotalCopiedPercentage );
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryPasteFileStatus_Return_zero()
{
    m_eMPlayerKnlFlags &= (enumMPlayerKnlFlags)~E_MPLAYER_KNL_FLG_COPY_PLAY;
    m_u32TotalCopiedPercentage = 60;
    {
        U32 _return = MApp_MPlayer_QueryPasteFileStatus();
        CPPTEST_ASSERT_EQUAL(_return, 0 );
    }
}
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_MPlayer_IsCopying(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCopying_TRUE()
{
    m_eMPlayerKnlFlags |= E_MPLAYER_KNL_FLG_COPY_PLAY;
    {
        U32 _return = MApp_MPlayer_IsCopying();
        CPPTEST_ASSERT_BOOL_EQUAL(_return, TRUE );
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCopying_FALSE()
{
    m_eMPlayerKnlFlags &= (enumMPlayerKnlFlags)~E_MPLAYER_KNL_FLG_COPY_PLAY;
    {
        U32 _return = MApp_MPlayer_IsCopying();
        CPPTEST_ASSERT_BOOL_EQUAL(_return, FALSE );
    }
}

/* CPPTEST_TEST_CASE_CONTEXT U16 MApp_MPlayer_QueryCurrentSelectedCopyingFileIndex(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentSelectedCopyingFileIndex()
{
    u16CurrentCopyIndex =10;;
    {
        U16 _return = MApp_MPlayer_QueryCurrentSelectedCopyingFileIndex();
        CPPTEST_ASSERT_EQUAL(_return, u16CurrentCopyIndex );
    }
}

/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_MPlayer_StopDelete(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_StopDelete()
{
    {
        BOOLEAN _return  = MApp_MPlayer_StopDelete();
        CPPTEST_ASSERT_BOOL_EQUAL(_return, TRUE );
        CPPTEST_ASSERT_BOOL_EQUAL(m_bUserBreakDelete,TRUE);
    }
}

/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_DeleteNext(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_DeleteNext_FALSE_worng_selected_file_number()
{
    m_eMediaType = E_MPLAYER_TYPE_PHOTO;
    m_u16SelectedFileNum[m_eMediaType] = NUM_OF_MAX_SELECTED_FILE+1;
    {
        BOOLEAN _return  = _MApp_MPlayer_DeleteNext();
        CPPTEST_ASSERT_BOOL_EQUAL(_return, FALSE);
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_DeleteNext_FALSE_no_selected_file()
{
    m_eMediaType = E_MPLAYER_TYPE_PHOTO;
    m_u16SelectedFileNum[m_eMediaType] = 0;
    {
        BOOLEAN _return  = _MApp_MPlayer_DeleteNext();
        CPPTEST_ASSERT_BOOL_EQUAL(_return, FALSE);
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_DeleteNext_TRUE()
{
    m_eMediaType = E_MPLAYER_TYPE_PHOTO;
    m_u16SelectedFileNum[m_eMediaType] = 10;
    {
        BOOLEAN _return  = _MApp_MPlayer_DeleteNext();
        CPPTEST_ASSERT_BOOL_EQUAL(_return, TRUE);
        CPPTEST_ASSERT_BOOL_EQUAL(_return, (m_eMPlayerKnlFlags & E_MPLAYER_KNL_FLG_DELETE_INIT));
        CPPTEST_ASSERT_EQUAL( 0, m_u16CurDeletePlaylistIdx);
    }
}

/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_MPlayer_IsDeleting(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsDeleting_TRUE()
{
    m_eMPlayerKnlFlags |= E_MPLAYER_KNL_FLG_DELETE_PLAY;
    {
        BOOLEAN _return  = MApp_MPlayer_IsDeleting();
        CPPTEST_ASSERT_BOOL_EQUAL(_return, TRUE);
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsDeleting_FALSE()
{
    m_eMPlayerKnlFlags &= (enumMPlayerKnlFlags)~E_MPLAYER_KNL_FLG_DELETE_PLAY;
    {
        BOOLEAN _return  = MApp_MPlayer_IsDeleting();
        CPPTEST_ASSERT_BOOL_EQUAL(_return, FALSE);
    }
}

/* CPPTEST_TEST_CASE_CONTEXT U16 MApp_MPlayer_QueryCurrentSelectedDeletingFileIndex(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurrentSelectedDeletingFileIndex()
{
    m_u16CurDeletePlaylistIdx = 10;
    {
        U16 _return  = MApp_MPlayer_QueryCurrentSelectedDeletingFileIndex();
        CPPTEST_ASSERT_EQUAL(m_u16CurDeletePlaylistIdx, _return);
    }
}

/* CPPTEST_TEST_CASE_CONTEXT U16 MApp_MPlayer_QueryDeleteFileStatus(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryDeleteFileStatus_In_delete_play()
{
    m_u32TotalDeletedPercentage = 20;
    m_eMPlayerKnlFlags |= E_MPLAYER_KNL_FLG_DELETE_PLAY;
    {
        U16 _return  = MApp_MPlayer_QueryDeleteFileStatus();
        CPPTEST_ASSERT_EQUAL(m_u32TotalDeletedPercentage, _return);
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryDeleteFileStatus_Not_in_delete_play()
{
    m_u32TotalDeletedPercentage = 20;
    m_eMPlayerKnlFlags &= (enumMPlayerKnlFlags)~E_MPLAYER_KNL_FLG_DELETE_PLAY;
    {
        U16 _return  = MApp_MPlayer_QueryDeleteFileStatus();
        CPPTEST_ASSERT_EQUAL(0, _return);
    }
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_QueryCurMovieAudioLanguage_en */
/* CPPTEST_TEST_CASE_CONTEXT enumMPlayerLanguage MApp_MPlayer_QueryCurMovieAudioLanguage(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurMovieAudioLanguage_en()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        enumMPlayerLanguage _return  = MApp_MPlayer_QueryCurMovieAudioLanguage();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_MPLAYER_LANGUAGE_ENGLISH, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_QueryCurMovieAudioLanguage_en */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_QueryCurMovieSubtitleLanguage_External */
/* CPPTEST_TEST_CASE_CONTEXT enumMPlayerLanguage MApp_MPlayer_QueryCurMovieSubtitleLanguage(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurMovieSubtitleLanguage_External()
{
	m_MPlayerInfo[E_MPLAYER_FOREGROUND_PLAYER].eKnlFlag1 = E_MPLAYER_KNL_FLG1_SUBTITLE_EXTERNAL;

    /* Pre-condition initialization */
    {
        /* Tested function call */
        enumMPlayerLanguage _return  = MApp_MPlayer_QueryCurMovieSubtitleLanguage();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_MPLAYER_LANGUAGE_ENGLISH, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_QueryCurMovieSubtitleLanguage_External */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_QueryCurMovieSubtitleLanguage_Interal */
/* CPPTEST_TEST_CASE_CONTEXT enumMPlayerLanguage MApp_MPlayer_QueryCurMovieSubtitleLanguage(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurMovieSubtitleLanguage_Interal()
{
	m_MPlayerInfo[E_MPLAYER_FOREGROUND_PLAYER].eKnlFlag1 = 0;

    /* Pre-condition initialization */
    {
        /* Tested function call */
        enumMPlayerLanguage _return  = MApp_MPlayer_QueryCurMovieSubtitleLanguage();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_MPLAYER_LANGUAGE_ENGLISH, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_QueryCurMovieSubtitleLanguage_Interal */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_MPlayer_SubtitleTask_External_Text */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_MPlayer_SubtitleTask(U32) */
void TestSuite_mapp_mplayer_test__MApp_MPlayer_SubtitleTask_External_Text()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32CurTime) */ 
    U32 _u32CurTime  = 1ul;
    /* Initializing global variable m_bIsSubtitleTaskAlive */ 
    {
         m_bIsSubtitleTaskAlive  = TRUE;
    }
    /* Initializing global variable m_enRepeatABMode */ 
    {
         m_enRepeatABMode  = E_MPLAYER_MOVIE_SET_REPEAT_AB_NONE;
    }
    /* Initializing global variable m_eExternalSubtitleType */ 
    {
         m_eExternalSubtitleType  = E_MPLAYER_SUBTITLE_SRT;
    }
    /* Initializing global variable m_u64NotifyEnableFlags */ 
    {
         m_u64NotifyEnableFlags  = 0ul;
    }
    /* Initializing global variable m_u32LyricSubtitleCurTime */ 
    {
         m_u32LyricSubtitleCurTime  = 0ul;
    }
    /* Initializing global variable m_u32CurSubtitlePos */ 
    {
         m_u32CurSubtitlePos  = 0ul;
    }
    /* Initializing global variable m_enSubtitleCharsetType */ 
    {
         m_enSubtitleCharsetType  = SUBTITLE_CHARSET_DEFAULT;
    }
    /* Initializing global variable m_bNotifyRtn */ 
    {
         m_bNotifyRtn  = 0;
    }
    /* Initializing global variable m_u8AliveSubtitleNum */ 
    {
         m_u8AliveSubtitleNum  = 2;
    }
    /* Initializing global variable m_bNewRepeatABLoop */ 
    {
         m_bNewRepeatABLoop  = 0;
    }
    /* Initializing global variable m_s32SubtitleTimeShift */ 
    {
         m_s32SubtitleTimeShift  = 0L;
    }
    /* Initializing global variable m_Subtitle_Tag */ 
    {
         m_Subtitle_Tag.u32TimeStart  = 0ul;
         m_Subtitle_Tag.u32TimeEnd  = 0ul;
         m_Subtitle_Tag.u32SubtitlePos  = 0ul;
    }
    m_MPlayerInfo[E_MPLAYER_FOREGROUND_PLAYER].eKnlFlag1 = E_MPLAYER_KNL_FLG1_SUBTITLE_VALID | E_MPLAYER_KNL_FLG1_SUBTITLE_ENABLE | E_MPLAYER_KNL_FLG1_SUBTITLE_EXTERNAL | E_MPLAYER_KNL_FLG1_SUBTITLE_TEXT |E_MPLAYER_KNL_FLG1_SUBTITLE_SHOWN;

    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_MPlayer_SubtitleTask(_u32CurTime);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(_return, TRUE);
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_MPlayer_SubtitleTask_External_Text */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_GetPlayListFileInfo_Music */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_MPlayer_GetPlayListFileInfo(U16, MPlayerFileInfo *) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_GetPlayListFileInfo_Music()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16PlayingIdx) */ 
    U16 _u16PlayingIdx  = 0u;
    /* Initializing argument 2 (pInfo) */ 
    MPlayerFileInfo _pInfo_2 ;
    MPlayerFileInfo * _pInfo  = & _pInfo_2;
    /* Initializing global variable m_u8UserBrowserHandle */ 
    {
         m_u8UserBrowserHandle  = 0;
    }
    /* Initializing global variable m_u16CurDriveIdx */ 
    {
         m_u16CurDriveIdx  = 1u;
    }
    /* Initializing global variable m_eMediaType */ 
    {
         m_eMediaType  = E_MPLAYER_TYPE_MUSIC;
    }
    m_u16SelectedFileNum[m_eMediaType] = 2;
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_MPlayer_GetPlayListFileInfo(_u16PlayingIdx, _pInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(_return, TRUE);
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_GetPlayListFileInfo_Music */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_Stop_Music_E_MPLAYER_RET_OK */
/* CPPTEST_TEST_CASE_CONTEXT enumMPlayerRet MApp_MPlayer_Stop(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_Stop_Music_E_MPLAYER_RET_OK()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_bPlayNext */ 
    {
         m_bPlayNext  = 0;
    }
    /* Initializing global variable m_eEmbeddedPhotoState */ 
    {
         m_eEmbeddedPhotoState  = E_EMBEDDED_PHOTO_WAIT;
    }
    /* Initializing global variable m_eMusicPlayMode */ 
    {
         m_eMusicPlayMode  = E_MPLAYER_MUSIC_NORMAL;
    }
    /* Initializing global variable m_u16PreFileIdx */ 
    {
         m_u16PreFileIdx  = 0u;
    }
    /* Initializing global variable m_u32EmbeddedPhoto_FileHandle */ 
    {
         m_u32EmbeddedPhoto_FileHandle  = 0ul;
    }
    /* Initializing global variable m_u8ExternalSubtitleFileHandle */ 
    {
         m_u8ExternalSubtitleFileHandle  = 0;
    }
    /* Initializing global variable m_u16TotalFileNum */ 
    {
         m_u16TotalFileNum  = 0u;
    }
    /* Initializing global variable m_u16FilesPerPage */ 
    {
         m_u16FilesPerPage  = 0u;
    }
    /* Initializing global variable m_u16TotalPageNum */ 
    {
         m_u16TotalPageNum  = 0u;
    }
    /* Initializing global variable m_eMediaType */ 
    {
         m_eMediaType  = E_MPLAYER_TYPE_MUSIC;
    }
    {
        /* Tested function call */
        enumMPlayerRet _return  = MApp_MPlayer_Stop();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_MPLAYER_RET_OK, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_Stop_Music_E_MPLAYER_RET_OK */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_Stop_Movie_E_MPLAYER_RET_OK */
/* CPPTEST_TEST_CASE_CONTEXT enumMPlayerRet MApp_MPlayer_Stop(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_Stop_Movie_E_MPLAYER_RET_OK()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_bPlayNext */ 
    {
         m_bPlayNext  = 0;
    }
    /* Initializing global variable m_eEmbeddedPhotoState */ 
    {
         m_eEmbeddedPhotoState  = E_EMBEDDED_PHOTO_WAIT;
    }
    /* Initializing global variable m_eMusicPlayMode */ 
    {
         m_eMusicPlayMode  = E_MPLAYER_MUSIC_NORMAL;
    }
    /* Initializing global variable m_u16PreFileIdx */ 
    {
         m_u16PreFileIdx  = 0u;
    }
    /* Initializing global variable m_u32EmbeddedPhoto_FileHandle */ 
    {
         m_u32EmbeddedPhoto_FileHandle  = 0ul;
    }
    /* Initializing global variable m_u8ExternalSubtitleFileHandle */ 
    {
         m_u8ExternalSubtitleFileHandle  = 0;
    }
    /* Initializing global variable m_u16TotalFileNum */ 
    {
         m_u16TotalFileNum  = 0u;
    }
    /* Initializing global variable m_u16FilesPerPage */ 
    {
         m_u16FilesPerPage  = 0u;
    }
    /* Initializing global variable m_u16TotalPageNum */ 
    {
         m_u16TotalPageNum  = 0u;
    }
    /* Initializing global variable m_eMediaType */ 
    {
         m_eMediaType  = E_MPLAYER_TYPE_MOVIE;
    }
    m_MPlayerInfo[E_MPLAYER_FOREGROUND_PLAYER].eMediaSubType = E_MPLAYER_SUBTYPE_TS;
    m_MPlayerInfo[E_MPLAYER_FOREGROUND_PLAYER].eKnlFlag1 = E_MPLAYER_KNL_FLG1_SUBTITLE_VALID;
    {
        /* Tested function call */
        enumMPlayerRet _return  = MApp_MPlayer_Stop();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_MPLAYER_RET_OK, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_Stop_Movie_E_MPLAYER_RET_OK */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_PlayPrevFile_Music_E_MPLAYER_RET_OK */
/* CPPTEST_TEST_CASE_CONTEXT enumMPlayerRet MApp_MPlayer_PlayPrevFile(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_PlayPrevFile_Music_E_MPLAYER_RET_OK()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_ePhotoValidOrNot */ 
    {
         m_ePhotoValidOrNot  = E_MPLAYER_PHOTO_WAIT;
    }
    /* Initializing global variable m_bPlayNext */ 
    {
         m_bPlayNext  = 0;
    }
    /* Initializing global variable m_s16VideoShiftY */ 
    {
         m_s16VideoShiftY  = 0;
    }
    /* Initializing global variable m_eMusicPlayMode */ 
    {
         m_eMusicPlayMode  = E_MPLAYER_MUSIC_NORMAL;
    }
    /* Initializing global variable m_u8ExternalSubtitleFileHandle */ 
    {
         m_u8ExternalSubtitleFileHandle  = 0;
    }
    /* Initializing global variable m_u32PhotoCurrentDisplayedIdx */ 
    {
         m_u32PhotoCurrentDisplayedIdx  = 0ul;
    }
    /* Initializing global variable m_s32Photo_LastDecodeIdx */ 
    {
         m_s32Photo_LastDecodeIdx  = 0L;
    }
    /* Initializing global variable m_s32Photo_LastDecodeFailIdx */ 
    {
         m_s32Photo_LastDecodeFailIdx  = 0L;
    }
    /* Initializing global variable m_u32Photo_PlayPrevDecodeFailCount */ 
    {
         m_u32Photo_PlayPrevDecodeFailCount  = 0ul;
    }
    /* Initializing global variable m_u8DecodedPics */ 
    {
         m_u8DecodedPics  = 0;
    }
    /* Initializing global variable m_u16CurLyricPos */ 
    {
         m_u16CurLyricPos  = 0u;
    }
    /* Initializing global variable bMusicRecording */ 
    {
         bMusicRecording  = 0;
    }
    /* Initializing global variable bPauseToNextFlag */ 
    {
         bPauseToNextFlag  = 0;
    }
    /* Initializing global variable m_u64NotifyEnableFlags */ 
    {
         m_u64NotifyEnableFlags  = 0ul;
    }
    /* Initializing global variable m_eMovieMainExit */ 
    {
         m_eMovieMainExit  = EXIT_NULL;
    }
    /* Initializing global variable m_u32LyricSubtitleCurTime */ 
    {
         m_u32LyricSubtitleCurTime  = 0ul;
    }
    /* Initializing global variable m_u32PlayCheckTime */ 
    {
         m_u32PlayCheckTime  = 0ul;
    }
    /* Initializing global variable m_eMoviePlayMode */ 
    {
         m_eMoviePlayMode  = E_MPLAYER_MOVIE_NORMAL;
    }
    /* Initializing global variable g_bPlayPrev */ 
    {
         g_bPlayPrev  = 0;
    }
    /* Initializing global variable m_u32CurSubtitlePos */ 
    {
         m_u32CurSubtitlePos  = 0ul;
    }
    /* Initializing global variable m_u16TotalFileNum */ 
    {
         m_u16TotalFileNum  = 0u;
    }
    /* Initializing global variable m_u16CurPage1stFileIdx */ 
    {
         m_u16CurPage1stFileIdx  = 0u;
    }
    /* Initializing global variable m_u16TotalMusicFileNum */ 
    {
         m_u16TotalMusicFileNum  = 0u;
    }
    /* Initializing global variable m_eZoom */ 
    {
         m_eZoom  = E_MPLAYER_ZOOM_1_DIV4;
    }
    /* Initializing global variable m_s16VideoShiftX */ 
    {
         m_s16VideoShiftX  = 0;
    }
    /* Initializing global variable m_u16CurDirectoryDepth */ 
    {
         m_u16CurDirectoryDepth  = 0u;
    }
    /* Initializing global variable m_eMediaType */ 
    {
         m_eMediaType  = E_MPLAYER_TYPE_MUSIC;
    }
    /* Initializing global variable g_bOutputMMAliveMessage */ 
    {
         g_bOutputMMAliveMessage  = 0;
    }
    /* Initializing global variable m_bNotifyRtn */ 
    {
         m_bNotifyRtn  = 0;
    }
    m_MPlayerInfo[E_MPLAYER_FOREGROUND_PLAYER].eMediaSubType = E_MPLAYER_SUBTYPE_MP3;
    {
        /* Tested function call */
        enumMPlayerRet _return  = MApp_MPlayer_PlayPrevFile();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_MPLAYER_RET_OK, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_PlayPrevFile_Music_E_MPLAYER_RET_OK */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_PlayPrevFile_Movie_E_MPLAYER_RET_OK */
/* CPPTEST_TEST_CASE_CONTEXT enumMPlayerRet MApp_MPlayer_PlayPrevFile(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_PlayPrevFile_Movie_E_MPLAYER_RET_OK()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_ePhotoValidOrNot */ 
    {
         m_ePhotoValidOrNot  = E_MPLAYER_PHOTO_WAIT;
    }
    /* Initializing global variable m_bPlayNext */ 
    {
         m_bPlayNext  = 0;
    }
    /* Initializing global variable m_s16VideoShiftY */ 
    {
         m_s16VideoShiftY  = 0;
    }
    /* Initializing global variable m_eMusicPlayMode */ 
    {
         m_eMusicPlayMode  = E_MPLAYER_MUSIC_NORMAL;
    }
    /* Initializing global variable m_u8ExternalSubtitleFileHandle */ 
    {
         m_u8ExternalSubtitleFileHandle  = 0;
    }
    /* Initializing global variable m_u32PhotoCurrentDisplayedIdx */ 
    {
         m_u32PhotoCurrentDisplayedIdx  = 0ul;
    }
    /* Initializing global variable m_s32Photo_LastDecodeIdx */ 
    {
         m_s32Photo_LastDecodeIdx  = 0L;
    }
    /* Initializing global variable m_s32Photo_LastDecodeFailIdx */ 
    {
         m_s32Photo_LastDecodeFailIdx  = 0L;
    }
    /* Initializing global variable m_u32Photo_PlayPrevDecodeFailCount */ 
    {
         m_u32Photo_PlayPrevDecodeFailCount  = 0ul;
    }
    /* Initializing global variable m_u8DecodedPics */ 
    {
         m_u8DecodedPics  = 0;
    }
    /* Initializing global variable m_u16CurLyricPos */ 
    {
         m_u16CurLyricPos  = 0u;
    }
    /* Initializing global variable bMusicRecording */ 
    {
         bMusicRecording  = 0;
    }
    /* Initializing global variable bPauseToNextFlag */ 
    {
         bPauseToNextFlag  = 0;
    }
    /* Initializing global variable m_u64NotifyEnableFlags */ 
    {
         m_u64NotifyEnableFlags  = 0ul;
    }
    /* Initializing global variable m_eMovieMainExit */ 
    {
         m_eMovieMainExit  = EXIT_NULL;
    }
    /* Initializing global variable m_u32LyricSubtitleCurTime */ 
    {
         m_u32LyricSubtitleCurTime  = 0ul;
    }
    /* Initializing global variable m_u32PlayCheckTime */ 
    {
         m_u32PlayCheckTime  = 0ul;
    }
    /* Initializing global variable m_eMoviePlayMode */ 
    {
         m_eMoviePlayMode  = E_MPLAYER_MOVIE_NORMAL;
    }
    /* Initializing global variable g_bPlayPrev */ 
    {
         g_bPlayPrev  = 0;
    }
    /* Initializing global variable m_u32CurSubtitlePos */ 
    {
         m_u32CurSubtitlePos  = 0ul;
    }
    /* Initializing global variable m_u16TotalFileNum */ 
    {
         m_u16TotalFileNum  = 0u;
    }
    /* Initializing global variable m_u16CurPage1stFileIdx */ 
    {
         m_u16CurPage1stFileIdx  = 0u;
    }
    /* Initializing global variable m_u16TotalMusicFileNum */ 
    {
         m_u16TotalMusicFileNum  = 0u;
    }
    /* Initializing global variable m_eZoom */ 
    {
         m_eZoom  = E_MPLAYER_ZOOM_1_DIV4;
    }
    /* Initializing global variable m_s16VideoShiftX */ 
    {
         m_s16VideoShiftX  = 0;
    }
    /* Initializing global variable m_u16CurDirectoryDepth */ 
    {
         m_u16CurDirectoryDepth  = 0u;
    }
    /* Initializing global variable m_eMediaType */ 
    {
         m_eMediaType  = E_MPLAYER_TYPE_MOVIE;
    }
    /* Initializing global variable g_bOutputMMAliveMessage */ 
    {
         g_bOutputMMAliveMessage  = 0;
    }
    /* Initializing global variable m_bNotifyRtn */ 
    {
         m_bNotifyRtn  = 0;
    }
    m_MPlayerInfo[E_MPLAYER_FOREGROUND_PLAYER].eMediaSubType = E_MPLAYER_SUBTYPE_TS;
    {
        /* Tested function call */
        enumMPlayerRet _return  = MApp_MPlayer_PlayPrevFile();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_MPLAYER_RET_OK, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_PlayPrevFile_Movie_E_MPLAYER_RET_OK */



/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_SetCurrentPlayingList_Music_u16PLIndex_Over20u16PlayListNum */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_MPlayer_SetCurrentPlayingList(U16) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_SetCurrentPlayingList_Music_u16PLIndex_Over20u16PlayListNum()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16PLIndex) */ 
    U16 _u16PLIndex  = 2u;
    enumMPlayerIdx ePlayerIdx = E_MPLAYER_BACKGROUND_PLAYER;
    /* Initializing global variable m_eMediaType */ 
    {
         m_eMediaType  = E_MPLAYER_TYPE_MUSIC;
    }
    m_u16SelectedFileNum[m_eMediaType] = 1;
    {
        /* Tested function call */
        MApp_MPlayer_SetCurrentPlayingList(_u16PLIndex);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( m_u16SelectedFileNum[m_eMediaType]-1, ( m_MPlayerInfo[ePlayerIdx].u16PlayingIdx ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_SetCurrentPlayingList_Music_u16PLIndex_Over20u16PlayListNum */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_PlayMusic_E_MPLAYER_PLAY_ONE_DIRECTORY_E_MPLAYER_RET_OK */
/* CPPTEST_TEST_CASE_CONTEXT enumMPlayerRet MApp_MPlayer_PlayMusic(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_PlayMusic_E_MPLAYER_PLAY_ONE_DIRECTORY_E_MPLAYER_RET_OK()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_eEmbeddedPhotoState */ 
    {
         m_eEmbeddedPhotoState  = E_EMBEDDED_PHOTO_WAIT;
    }
    /* Initializing global variable m_eMusicPlayMode */ 
    {
         m_eMusicPlayMode  = E_MPLAYER_MUSIC_NORMAL;
    }
    /* Initializing global variable m_u16PreFileIdx */ 
    {
         m_u16PreFileIdx  = 0u;
    }
    /* Initializing global variable m_u32EmbeddedPhoto_FileHandle */ 
    {
         m_u32EmbeddedPhoto_FileHandle  = 0ul;
    }
    /* Initializing global variable m_u16CurMusicDirectoryNumber */ 
    {
         m_u16CurMusicDirectoryNumber  = 0u;
    }
    /* Initializing global variable m_u32PhotoCurrentDisplayedIdx */ 
    {
         m_u32PhotoCurrentDisplayedIdx  = 0ul;
    }
    /* Initializing global variable m_s32Photo_LastDecodeIdx */ 
    {
         m_s32Photo_LastDecodeIdx  = 0L;
    }
    /* Initializing global variable m_s32Photo_LastDecodeFailIdx */ 
    {
         m_s32Photo_LastDecodeFailIdx  = 0L;
    }
    /* Initializing global variable m_u32Photo_PlayPrevDecodeFailCount */ 
    {
         m_u32Photo_PlayPrevDecodeFailCount  = 0ul;
    }
    /* Initializing global variable m_u8DecodedPics */ 
    {
         m_u8DecodedPics  = 0;
    }
    /* Initializing global variable m_u16CurLyricPos */ 
    {
         m_u16CurLyricPos  = 0u;
    }
    /* Initializing global variable bMusicRecording */ 
    {
         bMusicRecording  = 0;
    }
    /* Initializing global variable m_ePlayMode */ 
    {
         m_ePlayMode  = E_MPLAYER_PLAY_ONE_DIRECTORY;
    }
    /* Initializing global variable m_u64NotifyEnableFlags */ 
    {
         m_u64NotifyEnableFlags  = 0ul;
    }
    /* Initializing global variable m_u32LyricSubtitleCurTime */ 
    {
         m_u32LyricSubtitleCurTime  = 0ul;
    }
    /* Initializing global variable m_u32PlayCheckTime */ 
    {
         m_u32PlayCheckTime  = 0ul;
    }
    /* Initializing global variable g_bPlayPrev */ 
    {
         g_bPlayPrev  = 0;
    }
    /* Initializing global variable m_u32CurSubtitlePos */ 
    {
         m_u32CurSubtitlePos  = 0ul;
    }
    /* Initializing global variable m_u16TotalFileNum */ 
    {
         m_u16TotalFileNum  = 0u;
    }
    /* Initializing global variable m_u16RealMusicFileNum */ 
    {
         m_u16RealMusicFileNum  = 0u;
    }
    /* Initializing global variable m_u16CurFileIdx */ 
    {
         m_u16CurFileIdx  = 0u;
    }
    /* Initializing global variable m_u16CurPage1stFileIdx */ 
    {
         m_u16CurPage1stFileIdx  = 0u;
    }
    /* Initializing global variable m_u16TotalMusicFileNum */ 
    {
         m_u16TotalMusicFileNum  = 0u;
    }
    /* Initializing global variable m_u16CurDriveIdx */ 
    {
         m_u16CurDriveIdx  = 0u;
    }
    /* Initializing global variable m_u16TotalBGMFileNum */ 
    {
         m_u16TotalBGMFileNum  = 0u;
    }
    /* Initializing global variable m_u16CurDirectoryDepth */ 
    {
         m_u16CurDirectoryDepth  = 0u;
    }
    /* Initializing global variable m_eMediaType */ 
    {
         m_eMediaType  = E_MPLAYER_TYPE_MUSIC;
    }
    /* Initializing global variable g_bOutputMMAliveMessage */ 
    {
         g_bOutputMMAliveMessage  = 0;
    }
    /* Initializing global variable m_bNotifyRtn */ 
    {
         m_bNotifyRtn  = 0;
    }
    /* Initializing global variable m_eMusicPreviewState */ 
    {
         m_eMusicPreviewState  = E_MUSIC_PREVIEW_NONE;
    }
    /* Initializing global variable m_photoInfo */ 
    {
         m_photoInfo.u16Width  = 0u;
         m_photoInfo.u16Height  = 0u;
         m_photoInfo.u32FileSize  = 0ul;
         m_photoInfo.eFlags  = E_MPLAYER_JPEG_FLAG_JPEG;
         m_photoInfo.eOrientation  = E_MPLAYER_JPEG_ORIENT_ORIGINAL;
         m_photoInfo.bHasDateTime  = 0;
         m_photoInfo.u32Year  = 0ul;
         m_photoInfo.u32Month  = 0ul;
         m_photoInfo.u32Day  = 0ul;
         m_photoInfo.u32Hour  = 0ul;
         m_photoInfo.u32Minute  = 0ul;
         m_photoInfo.u32Second  = 0ul;
         m_photoInfo.u32ExifWidth  = 0ul;
         m_photoInfo.u32ExifHeight  = 0ul;
         m_photoInfo.u32FlashMode  = 0ul;
         m_photoInfo.u32ISOSpeed  = 0ul;
    }
    {
        /* Tested function call */
        enumMPlayerRet _return  = MApp_MPlayer_PlayMusic();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_MPLAYER_RET_OK, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_PlayMusic_E_MPLAYER_PLAY_ONE_DIRECTORY_E_MPLAYER_RET_OK */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_PlayMusic_NotMusic_m_u16SelectedFileNum_0_E_MPLAYER_RET_FAIL */
/* CPPTEST_TEST_CASE_CONTEXT enumMPlayerRet MApp_MPlayer_PlayMusic(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_PlayMusic_NotMusic_m_u16SelectedFileNum_0_E_MPLAYER_RET_FAIL()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_eEmbeddedPhotoState */ 
    {
         m_eEmbeddedPhotoState  = E_EMBEDDED_PHOTO_WAIT;
    }
    /* Initializing global variable m_eMusicPlayMode */ 
    {
         m_eMusicPlayMode  = E_MPLAYER_MUSIC_NORMAL;
    }
    /* Initializing global variable m_u16PreFileIdx */ 
    {
         m_u16PreFileIdx  = 0u;
    }
    /* Initializing global variable m_u32EmbeddedPhoto_FileHandle */ 
    {
         m_u32EmbeddedPhoto_FileHandle  = 0ul;
    }
    /* Initializing global variable m_u16CurMusicDirectoryNumber */ 
    {
         m_u16CurMusicDirectoryNumber  = 0u;
    }
    /* Initializing global variable m_u32PhotoCurrentDisplayedIdx */ 
    {
         m_u32PhotoCurrentDisplayedIdx  = 0ul;
    }
    /* Initializing global variable m_s32Photo_LastDecodeIdx */ 
    {
         m_s32Photo_LastDecodeIdx  = 0L;
    }
    /* Initializing global variable m_s32Photo_LastDecodeFailIdx */ 
    {
         m_s32Photo_LastDecodeFailIdx  = 0L;
    }
    /* Initializing global variable m_u32Photo_PlayPrevDecodeFailCount */ 
    {
         m_u32Photo_PlayPrevDecodeFailCount  = 0ul;
    }
    /* Initializing global variable m_u8DecodedPics */ 
    {
         m_u8DecodedPics  = 0;
    }
    /* Initializing global variable m_u16CurLyricPos */ 
    {
         m_u16CurLyricPos  = 0u;
    }
    /* Initializing global variable bMusicRecording */ 
    {
         bMusicRecording  = 0;
    }
    /* Initializing global variable m_ePlayMode */ 
    {
         m_ePlayMode  = E_MPLAYER_PLAY_ONE;
    }
    /* Initializing global variable m_u64NotifyEnableFlags */ 
    {
         m_u64NotifyEnableFlags  = 0ul;
    }
    /* Initializing global variable m_u32LyricSubtitleCurTime */ 
    {
         m_u32LyricSubtitleCurTime  = 0ul;
    }
    /* Initializing global variable m_u32PlayCheckTime */ 
    {
         m_u32PlayCheckTime  = 0ul;
    }
    /* Initializing global variable g_bPlayPrev */ 
    {
         g_bPlayPrev  = 0;
    }
    /* Initializing global variable m_u32CurSubtitlePos */ 
    {
         m_u32CurSubtitlePos  = 0ul;
    }
    /* Initializing global variable m_u16TotalFileNum */ 
    {
         m_u16TotalFileNum  = 0u;
    }
    /* Initializing global variable m_u16RealMusicFileNum */ 
    {
         m_u16RealMusicFileNum  = 0u;
    }
    /* Initializing global variable m_u16CurFileIdx */ 
    {
         m_u16CurFileIdx  = 0u;
    }
    /* Initializing global variable m_u16CurPage1stFileIdx */ 
    {
         m_u16CurPage1stFileIdx  = 0u;
    }
    /* Initializing global variable m_u16TotalMusicFileNum */ 
    {
         m_u16TotalMusicFileNum  = 0u;
    }
    /* Initializing global variable m_u16CurDriveIdx */ 
    {
         m_u16CurDriveIdx  = 0u;
    }
    /* Initializing global variable m_u16TotalBGMFileNum */ 
    {
         m_u16TotalBGMFileNum  = 0u;
    }
    /* Initializing global variable m_u16CurDirectoryDepth */ 
    {
         m_u16CurDirectoryDepth  = 0u;
    }
    /* Initializing global variable m_eMediaType */ 
    {
         m_eMediaType  = E_MPLAYER_TYPE_PHOTO;
    }
    /* Initializing global variable g_bOutputMMAliveMessage */ 
    {
         g_bOutputMMAliveMessage  = 0;
    }
    /* Initializing global variable m_bNotifyRtn */ 
    {
         m_bNotifyRtn  = 0;
    }
    /* Initializing global variable m_eMusicPreviewState */ 
    {
         m_eMusicPreviewState  = E_MUSIC_PREVIEW_NONE;
    }
    /* Initializing global variable m_photoInfo */ 
    {
         m_photoInfo.u16Width  = 0u;
         m_photoInfo.u16Height  = 0u;
         m_photoInfo.u32FileSize  = 0ul;
         m_photoInfo.eFlags  = E_MPLAYER_JPEG_FLAG_JPEG;
         m_photoInfo.eOrientation  = E_MPLAYER_JPEG_ORIENT_ORIGINAL;
         m_photoInfo.bHasDateTime  = 0;
         m_photoInfo.u32Year  = 0ul;
         m_photoInfo.u32Month  = 0ul;
         m_photoInfo.u32Day  = 0ul;
         m_photoInfo.u32Hour  = 0ul;
         m_photoInfo.u32Minute  = 0ul;
         m_photoInfo.u32Second  = 0ul;
         m_photoInfo.u32ExifWidth  = 0ul;
         m_photoInfo.u32ExifHeight  = 0ul;
         m_photoInfo.u32FlashMode  = 0ul;
         m_photoInfo.u32ISOSpeed  = 0ul;
    }
    m_u16SelectedFileNum[E_MPLAYER_TYPE_MUSIC] = 0;
    {
        /* Tested function call */
        enumMPlayerRet _return  = MApp_MPlayer_PlayMusic();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_MPLAYER_RET_FAIL, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_PlayMusic_NotMusic_m_u16SelectedFileNum_0_E_MPLAYER_RET_FAIL */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_PlayMusic_NotMusic_m_u16SelectedFileNum_1_E_MPLAYER_RET_FAIL */
/* CPPTEST_TEST_CASE_CONTEXT enumMPlayerRet MApp_MPlayer_PlayMusic(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_PlayMusic_NotMusic_m_u16SelectedFileNum_1_E_MPLAYER_RET_FAIL()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_eEmbeddedPhotoState */ 
    {
         m_eEmbeddedPhotoState  = E_EMBEDDED_PHOTO_WAIT;
    }
    /* Initializing global variable m_eMusicPlayMode */ 
    {
         m_eMusicPlayMode  = E_MPLAYER_MUSIC_NORMAL;
    }
    /* Initializing global variable m_u16PreFileIdx */ 
    {
         m_u16PreFileIdx  = 0u;
    }
    /* Initializing global variable m_u32EmbeddedPhoto_FileHandle */ 
    {
         m_u32EmbeddedPhoto_FileHandle  = 0ul;
    }
    /* Initializing global variable m_u16CurMusicDirectoryNumber */ 
    {
         m_u16CurMusicDirectoryNumber  = 0u;
    }
    /* Initializing global variable m_u32PhotoCurrentDisplayedIdx */ 
    {
         m_u32PhotoCurrentDisplayedIdx  = 0ul;
    }
    /* Initializing global variable m_s32Photo_LastDecodeIdx */ 
    {
         m_s32Photo_LastDecodeIdx  = 0L;
    }
    /* Initializing global variable m_s32Photo_LastDecodeFailIdx */ 
    {
         m_s32Photo_LastDecodeFailIdx  = 0L;
    }
    /* Initializing global variable m_u32Photo_PlayPrevDecodeFailCount */ 
    {
         m_u32Photo_PlayPrevDecodeFailCount  = 0ul;
    }
    /* Initializing global variable m_u8DecodedPics */ 
    {
         m_u8DecodedPics  = 0;
    }
    /* Initializing global variable m_u16CurLyricPos */ 
    {
         m_u16CurLyricPos  = 0u;
    }
    /* Initializing global variable bMusicRecording */ 
    {
         bMusicRecording  = 0;
    }
    /* Initializing global variable m_ePlayMode */ 
    {
         m_ePlayMode  = E_MPLAYER_PLAY_ONE;
    }
    /* Initializing global variable m_u64NotifyEnableFlags */ 
    {
         m_u64NotifyEnableFlags  = 0ul;
    }
    /* Initializing global variable m_u32LyricSubtitleCurTime */ 
    {
         m_u32LyricSubtitleCurTime  = 0ul;
    }
    /* Initializing global variable m_u32PlayCheckTime */ 
    {
         m_u32PlayCheckTime  = 0ul;
    }
    /* Initializing global variable g_bPlayPrev */ 
    {
         g_bPlayPrev  = 0;
    }
    /* Initializing global variable m_u32CurSubtitlePos */ 
    {
         m_u32CurSubtitlePos  = 0ul;
    }
    /* Initializing global variable m_u16TotalFileNum */ 
    {
         m_u16TotalFileNum  = 0u;
    }
    /* Initializing global variable m_u16RealMusicFileNum */ 
    {
         m_u16RealMusicFileNum  = 0u;
    }
    /* Initializing global variable m_u16CurFileIdx */ 
    {
         m_u16CurFileIdx  = 0u;
    }
    /* Initializing global variable m_u16CurPage1stFileIdx */ 
    {
         m_u16CurPage1stFileIdx  = 0u;
    }
    /* Initializing global variable m_u16TotalMusicFileNum */ 
    {
         m_u16TotalMusicFileNum  = 0u;
    }
    /* Initializing global variable m_u16CurDriveIdx */ 
    {
         m_u16CurDriveIdx  = 0u;
    }
    /* Initializing global variable m_u16TotalBGMFileNum */ 
    {
         m_u16TotalBGMFileNum  = 0u;
    }
    /* Initializing global variable m_u16CurDirectoryDepth */ 
    {
         m_u16CurDirectoryDepth  = 0u;
    }
    /* Initializing global variable m_eMediaType */ 
    {
         m_eMediaType  = E_MPLAYER_TYPE_PHOTO;
    }
    /* Initializing global variable g_bOutputMMAliveMessage */ 
    {
         g_bOutputMMAliveMessage  = 0;
    }
    /* Initializing global variable m_bNotifyRtn */ 
    {
         m_bNotifyRtn  = 0;
    }
    /* Initializing global variable m_eMusicPreviewState */ 
    {
         m_eMusicPreviewState  = E_MUSIC_PREVIEW_NONE;
    }
    /* Initializing global variable m_photoInfo */ 
    {
         m_photoInfo.u16Width  = 0u;
         m_photoInfo.u16Height  = 0u;
         m_photoInfo.u32FileSize  = 0ul;
         m_photoInfo.eFlags  = E_MPLAYER_JPEG_FLAG_JPEG;
         m_photoInfo.eOrientation  = E_MPLAYER_JPEG_ORIENT_ORIGINAL;
         m_photoInfo.bHasDateTime  = 0;
         m_photoInfo.u32Year  = 0ul;
         m_photoInfo.u32Month  = 0ul;
         m_photoInfo.u32Day  = 0ul;
         m_photoInfo.u32Hour  = 0ul;
         m_photoInfo.u32Minute  = 0ul;
         m_photoInfo.u32Second  = 0ul;
         m_photoInfo.u32ExifWidth  = 0ul;
         m_photoInfo.u32ExifHeight  = 0ul;
         m_photoInfo.u32FlashMode  = 0ul;
         m_photoInfo.u32ISOSpeed  = 0ul;
    }
    m_u16SelectedFileNum[E_MPLAYER_TYPE_MUSIC]=1;
    {
        /* Tested function call */
        enumMPlayerRet _return  = MApp_MPlayer_PlayMusic();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_MPLAYER_RET_FAIL, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_PlayMusic_NotMusic_m_u16SelectedFileNum_1_E_MPLAYER_RET_FAIL */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_GetFileEntryByPlaylistIndex_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_MPlayer_GetFileEntryByPlaylistIndex(U16, enumMPlayerMediaType, FileEntry *) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_GetFileEntryByPlaylistIndex_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16FileIdx) */ 
    U16 _u16FileIdx  = 0u;
    /* Initializing argument 2 (eMediaType) */ 
    enumMPlayerMediaType eMediaType  = E_MPLAYER_TYPE_PHOTO;
    /* Initializing argument 3 (pFileEntry) */ 
    FileEntry _pFileEntry_11 ;
    FileEntry * _pFileEntry  = & _pFileEntry_11;

    m_u16SelectedFileNum[eMediaType] = 1;

    {
        /* Tested function call */
        BOOLEAN _return  = MApp_MPlayer_GetFileEntryByPlaylistIndex(_u16FileIdx, eMediaType, _pFileEntry);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_GetFileEntryByPlaylistIndex_TRUE */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_IsCurSubtitleText_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_MPlayer_IsCurSubtitleText(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCurSubtitleText_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_eExternalSubtitleType */ 
    {
         m_eExternalSubtitleType  = E_MPLAYER_SUBTITLE_SRT;
    }
     m_MPlayerInfo[E_MPLAYER_FOREGROUND_PLAYER].eKnlFlag1 = E_MPLAYER_KNL_FLG1_SUBTITLE_EXTERNAL;
     m_eExternalSubtitleType = E_MPLAYER_SUBTITLE_ASS;
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_MPlayer_IsCurSubtitleText();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_IsCurSubtitleText_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_IsCurSubtitleExternal_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_MPlayer_IsCurSubtitleExternal(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCurSubtitleExternal_TRUE()
{
    /* Pre-condition initialization */
    {
    	m_MPlayerInfo[E_MPLAYER_FOREGROUND_PLAYER].eKnlFlag1 = E_MPLAYER_KNL_FLG1_SUBTITLE_EXTERNAL;
        /* Tested function call */
        BOOLEAN _return  = MApp_MPlayer_IsCurSubtitleExternal();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_IsCurSubtitleExternal_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_MPlayer_IsCurSubtitleText_FALSE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_MPlayer_IsCurSubtitleText(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_IsCurSubtitleText_FALSE()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_eExternalSubtitleType */ 
    {
         m_eExternalSubtitleType  = E_MPLAYER_SUBTITLE_SRT;
    }
    m_MPlayerInfo[E_MPLAYER_FOREGROUND_PLAYER].eKnlFlag1 = E_MPLAYER_KNL_FLG1_SUBTITLE_EXTERNAL;
    m_eExternalSubtitleType = E_MPLAYER_SUBTITLE_SUBIDX;
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_MPlayer_IsCurSubtitleText();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_MPlayer_IsCurSubtitleText_FALSE */

/* CPPTEST_TEST_CASE_CONTEXT enumMPlayerRet MApp_MPlayer_PrevPage(void) */
void TestSuite_mapp_mplayer_test_MApp_MPlayer_PrevPage_CurPageIdx_equal_zero()
{
    m_u16CurPageIdx = 0;
    {
        enumMPlayerRet _return  = MApp_MPlayer_PrevPage();
        CPPTEST_ASSERT_EQUAL(E_MPLAYER_RET_FAIL, _return);
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_PrevPage_FilePerPage_equal_zero()
{
    m_u16CurPageIdx = 1;
    m_u16FilesPerPage = 0;
    {
        enumMPlayerRet _return  = MApp_MPlayer_PrevPage();
        CPPTEST_ASSERT_EQUAL(E_MPLAYER_RET_FAIL, _return);
    }
}
void TestSuite_mapp_mplayer_test_MApp_MPlayer_PrevPage_FilePerPage_not_equal_zero()
{
    m_u16CurPageIdx = 1;
    m_u16FilesPerPage = 10;
    m_u16CurPage1stFileIdx = 12;
    U16 u16FileIdx = m_u16CurPage1stFileIdx - m_u16FilesPerPage;
    {
        enumMPlayerRet _return  = MApp_MPlayer_PrevPage();
        CPPTEST_ASSERT_EQUAL(E_MPLAYER_RET_OK, _return);
        CPPTEST_ASSERT_EQUAL(u16FileIdx, m_u16CurPage1stFileIdx);
    }
}
