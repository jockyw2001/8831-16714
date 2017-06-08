#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/multimedia/mapp_music.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/multimedia/mapp_music.c");

CPPTEST_TEST_SUITE(TestSuite_mapp_music);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_SetFileEntry_NULL);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_PCM_SetInfo_allzero);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_GetFfRewSpeed_FWMode_case0);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_GetFfRewSpeed_FWMode_case1);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_ProcessFfRew_FWMode_case0);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_ProcessFfRew_FWMode_case3);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_IsAAC_TRUE);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_IsAAC_FALSE);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_ReadDescrLength_esds);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_ExtractAtomName_case_notnull);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_GetSampleRate_case0);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_GetMdatSize_case0);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_DealPostfix_nIndex_case0);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_DealPostfix_nIndex_case1);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_DealPostfix_nIndex_case3);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_DealPostfix_nIndex_2);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_ExtractFix);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case0);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case1);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case2);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case3);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case4);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case5);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case6);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case7);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case8);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_casedefault);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_GetSampleRateIndex_dwValue_case0);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_GetSampleRateIndex_dwValue_case1);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_GetInfoString_enInfo_case1);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_GetInfoString_enInfo_case2);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_GetInfoString_enInfo_case3);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_GetInfoString_enfo_case4);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_GetInfoString_enInfo_case5);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_GetInfoString_enInfo_case6);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_GetInfoString_enInfo_case9);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_GetInfoStringLength_enInfo_caseMP3INFOALBUM);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_GetInfoStringLength_enInfo_caseMP3InfoTitle);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_GetInfoStringLength_enInfo_caseMP3InfoComment);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_GetInfoStringLength_enInfo_caseMP3InfoArtist);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_GetInfoStringLength_enInfo_caseMP3InfoYear);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_GetInfoStringLength_enInfo_caseDefault);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_GetFlacSampleIndex_u32KeyIndex_caseValid);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_GetFlacSampleIndex_u32KeyIndex_caseInvalid);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_CloseFile);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_AAC_Frame_Parsing_u32Mp3FileHandle_caseInvalid);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_AAC_Frame_Parsing_u32Mp3FileHandle_caseValid);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusicType_MP3_FAIL);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusicType_MP3_LAYER3);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusicType_AAC_m4a);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusic_AAC_AAC_TRUE);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusic_AAC_FALSE);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusic_FLAC_FALSE);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusic_FLAC_TRUE);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusicType_LOAS);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_Stop);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_OpenFile_enCurrentMusicType_MP3_FAIL);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_OpenFile_TRUE);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_SaveMp3_EraseFlash_FAIL);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_SaveMp3_EraseFlash_TRUE);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_SaveMp3_WriteFlash_TRUE);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusicType_MP3);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusic_AAC);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusicType_FLAC);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusicType_WAV);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusicType_PCM);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusicType_LOAS);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_LoadDspCodec);
CPPTEST_TEST(TestSuite_mapp_music_test__MApp_Music_ScanDigit);
CPPTEST_TEST(TestSuite_mapp_music_test__MApp_Music_ScanfLrCTime_case3);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_LRC_Lyrics_Parser_case1);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_Play);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_SearchFirstFrame_case1);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_CalculateMP3CBRDuration);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_ParseFlac_StreamInfo);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_ParseFlac_SeekTable_case1);
CPPTEST_TEST(TestSuite_mapp_music_test__MApp_Music_Flac_CollectInfo_case1);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_CollectInfo_case1);
CPPTEST_TEST(TestSuite_mapp_music_test__MApp_Music_Flac_DataInput_case1);
CPPTEST_TEST(TestSuite_mapp_music_test__MApp_Music_Wav_CollectInfo_case1);
CPPTEST_TEST(TestSuite_mapp_music_test__MApp_Music_Wav_DataInput);
CPPTEST_TEST(TestSuite_mapp_music_test__MApp_Music_PCM_CollectInfo_case1);
CPPTEST_TEST(TestSuite_mapp_music_test__MApp_Music_PCM_DataInput);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_UpdatePlayTime_case1);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_GetTotalTime_case1);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_GetCurrentTime_case1);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_GetCurrentTime_case2);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_GetCurrentTimeMs);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_ProcessFfRew_case4);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_ProcessFfRew_case5);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_TimeOutCheck_case1);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_Main_case1);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_Pause_case_TRUE);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_Resume);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_GetLyricTag);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_Get_AAC_Info_case1);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_Get_M4A_Info_case1);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_ReCalculateChunkIndex_case1);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_AddADTSHeaderForDSP_case1);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_WriteDSP_case1);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_SetCurrentFrameIndex_case1);
CPPTEST_TEST(TestSuite_mapp_music_test_M4aParser_GetOneStszEntryFromDRAM);
CPPTEST_TEST(TestSuite_mapp_music_test_M4AParser_SaveFrameLocation_case1);
CPPTEST_TEST(TestSuite_mapp_music_test__MApp_Music_MP3TimeOffset_case1);
CPPTEST_TEST(TestSuite_mapp_music_test__MApp_Music_AACTimeOffset_case1);
CPPTEST_TEST(TestSuite_mapp_music_test__MApp_Music_AACTimeOffset_case2);
CPPTEST_TEST(TestSuite_mapp_music_test__MApp_Music_WAVTimeOffset);
CPPTEST_TEST(TestSuite_mapp_music_test__MApp_Music_FLACTimeOffset_case1);
CPPTEST_TEST(TestSuite_mapp_music_test__MApp_Music_FLACTimeOffsetNoTable);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_ProcessTimeOffset);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_FastForwardBackward_case1);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_AAC_Probe_case1);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_M4A_Probe_case1);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_FLAC_Probe_case1);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_WAV_Probe_case1);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_MP3_Probe_case1);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_ProcessFfRew_case6);
CPPTEST_TEST(TestSuite_mapp_music_test_MApp_Music_CalculateMP3CBRDuration_ID3V2);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_mapp_music_test_MApp_Music_SetFileEntry_NULL();
void TestSuite_mapp_music_test_MApp_Music_PCM_SetInfo_allzero();
void TestSuite_mapp_music_test_MApp_Music_GetFfRewSpeed_FWMode_case0();
void TestSuite_mapp_music_test_MApp_Music_GetFfRewSpeed_FWMode_case1();
void TestSuite_mapp_music_test_MApp_Music_ProcessFfRew_FWMode_case0();
void TestSuite_mapp_music_test_MApp_Music_ProcessFfRew_FWMode_case3();
void TestSuite_mapp_music_test_MApp_Music_IsAAC_TRUE();
void TestSuite_mapp_music_test_MApp_Music_IsAAC_FALSE();
void TestSuite_mapp_music_test_M4AParser_ReadDescrLength_esds();
void TestSuite_mapp_music_test_M4AParser_ExtractAtomName_case_notnull();
void TestSuite_mapp_music_test_M4AParser_GetSampleRate_case0();
void TestSuite_mapp_music_test_M4AParser_GetMdatSize_case0();
void TestSuite_mapp_music_test_M4AParser_DealPostfix_nIndex_case0();
void TestSuite_mapp_music_test_M4AParser_DealPostfix_nIndex_case1();
void TestSuite_mapp_music_test_M4AParser_DealPostfix_nIndex_case3();
void TestSuite_mapp_music_test_M4AParser_DealPostfix_nIndex_2();
void TestSuite_mapp_music_test_M4AParser_ExtractFix();
void TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case0();
void TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case1();
void TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case2();
void TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case3();
void TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case4();
void TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case5();
void TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case6();
void TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case7();
void TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case8();
void TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_casedefault();
void TestSuite_mapp_music_test_M4AParser_GetSampleRateIndex_dwValue_case0();
void TestSuite_mapp_music_test_M4AParser_GetSampleRateIndex_dwValue_case1();
void TestSuite_mapp_music_test_MApp_Music_GetInfoString_enInfo_case1();
void TestSuite_mapp_music_test_MApp_Music_GetInfoString_enInfo_case2();
void TestSuite_mapp_music_test_MApp_Music_GetInfoString_enInfo_case3();
void TestSuite_mapp_music_test_MApp_Music_GetInfoString_enfo_case4();
void TestSuite_mapp_music_test_MApp_Music_GetInfoString_enInfo_case5();
void TestSuite_mapp_music_test_MApp_Music_GetInfoString_enInfo_case6();
void TestSuite_mapp_music_test_MApp_Music_GetInfoString_enInfo_case9();
void TestSuite_mapp_music_test_MApp_Music_GetInfoStringLength_enInfo_caseMP3INFOALBUM();
void TestSuite_mapp_music_test_MApp_Music_GetInfoStringLength_enInfo_caseMP3InfoTitle();
void TestSuite_mapp_music_test_MApp_Music_GetInfoStringLength_enInfo_caseMP3InfoComment();
void TestSuite_mapp_music_test_MApp_Music_GetInfoStringLength_enInfo_caseMP3InfoArtist();
void TestSuite_mapp_music_test_MApp_Music_GetInfoStringLength_enInfo_caseMP3InfoYear();
void TestSuite_mapp_music_test_MApp_Music_GetInfoStringLength_enInfo_caseDefault();
void TestSuite_mapp_music_test_MApp_Music_GetFlacSampleIndex_u32KeyIndex_caseValid();
void TestSuite_mapp_music_test_MApp_Music_GetFlacSampleIndex_u32KeyIndex_caseInvalid();
void TestSuite_mapp_music_test_MApp_Music_CloseFile();
void TestSuite_mapp_music_test_MApp_AAC_Frame_Parsing_u32Mp3FileHandle_caseInvalid();
void TestSuite_mapp_music_test_MApp_AAC_Frame_Parsing_u32Mp3FileHandle_caseValid();
void TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusicType_MP3_FAIL();
void TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusicType_MP3_LAYER3();
void TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusicType_AAC_m4a();
void TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusic_AAC_AAC_TRUE();
void TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusic_AAC_FALSE();
void TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusic_FLAC_FALSE();
void TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusic_FLAC_TRUE();
void TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusicType_LOAS();
void TestSuite_mapp_music_test_MApp_Music_Stop();
void TestSuite_mapp_music_test_MApp_Music_OpenFile_enCurrentMusicType_MP3_FAIL();
void TestSuite_mapp_music_test_MApp_Music_OpenFile_TRUE();
void TestSuite_mapp_music_test_MApp_SaveMp3_EraseFlash_FAIL();
void TestSuite_mapp_music_test_MApp_SaveMp3_EraseFlash_TRUE();
void TestSuite_mapp_music_test_MApp_SaveMp3_WriteFlash_TRUE();
void TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusicType_MP3();
void TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusic_AAC();
void TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusicType_FLAC();
void TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusicType_WAV();
void TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusicType_PCM();
void TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusicType_LOAS();
void TestSuite_mapp_music_test_MApp_Music_LoadDspCodec();
void TestSuite_mapp_music_test__MApp_Music_ScanDigit();
void TestSuite_mapp_music_test__MApp_Music_ScanfLrCTime_case3();
void TestSuite_mapp_music_test_MApp_Music_LRC_Lyrics_Parser_case1();
void TestSuite_mapp_music_test_MApp_Music_Play();
void TestSuite_mapp_music_test_MApp_Music_SearchFirstFrame_case1();
void TestSuite_mapp_music_test_MApp_Music_CalculateMP3CBRDuration();
void TestSuite_mapp_music_test_MApp_Music_ParseFlac_StreamInfo();
void TestSuite_mapp_music_test_MApp_Music_ParseFlac_SeekTable_case1();
void TestSuite_mapp_music_test__MApp_Music_Flac_CollectInfo_case1();
void TestSuite_mapp_music_test_MApp_Music_CollectInfo_case1();
void TestSuite_mapp_music_test__MApp_Music_Flac_DataInput_case1();
void TestSuite_mapp_music_test__MApp_Music_Wav_CollectInfo_case1();
void TestSuite_mapp_music_test__MApp_Music_Wav_DataInput();
void TestSuite_mapp_music_test__MApp_Music_PCM_CollectInfo_case1();
void TestSuite_mapp_music_test__MApp_Music_PCM_DataInput();
void TestSuite_mapp_music_test_MApp_Music_UpdatePlayTime_case1();
void TestSuite_mapp_music_test_MApp_Music_GetTotalTime_case1();
void TestSuite_mapp_music_test_MApp_Music_GetCurrentTime_case1();
void TestSuite_mapp_music_test_MApp_Music_GetCurrentTime_case2();
void TestSuite_mapp_music_test_MApp_Music_GetCurrentTimeMs();
void TestSuite_mapp_music_test_MApp_Music_ProcessFfRew_case4();
void TestSuite_mapp_music_test_MApp_Music_ProcessFfRew_case5();
void TestSuite_mapp_music_test_MApp_Music_TimeOutCheck_case1();
void TestSuite_mapp_music_test_MApp_Music_Main_case1();
void TestSuite_mapp_music_test_MApp_Music_Pause_case_TRUE();
void TestSuite_mapp_music_test_MApp_Music_Resume();
void TestSuite_mapp_music_test_MApp_Music_GetLyricTag();
void TestSuite_mapp_music_test_M4AParser_Get_AAC_Info_case1();
void TestSuite_mapp_music_test_M4AParser_Get_M4A_Info_case1();
void TestSuite_mapp_music_test_M4AParser_ReCalculateChunkIndex_case1();
void TestSuite_mapp_music_test_M4AParser_AddADTSHeaderForDSP_case1();
void TestSuite_mapp_music_test_M4AParser_WriteDSP_case1();
void TestSuite_mapp_music_test_M4AParser_SetCurrentFrameIndex_case1();
void TestSuite_mapp_music_test_M4aParser_GetOneStszEntryFromDRAM();
void TestSuite_mapp_music_test_M4AParser_SaveFrameLocation_case1();
void TestSuite_mapp_music_test__MApp_Music_MP3TimeOffset_case1();
void TestSuite_mapp_music_test__MApp_Music_AACTimeOffset_case1();
void TestSuite_mapp_music_test__MApp_Music_AACTimeOffset_case2();
void TestSuite_mapp_music_test__MApp_Music_WAVTimeOffset();
void TestSuite_mapp_music_test__MApp_Music_FLACTimeOffset_case1();
void TestSuite_mapp_music_test__MApp_Music_FLACTimeOffsetNoTable();
void TestSuite_mapp_music_test_MApp_Music_ProcessTimeOffset();
void TestSuite_mapp_music_test_MApp_Music_FastForwardBackward_case1();
void TestSuite_mapp_music_test_MApp_Music_AAC_Probe_case1();
void TestSuite_mapp_music_test_MApp_Music_M4A_Probe_case1();
void TestSuite_mapp_music_test_MApp_Music_FLAC_Probe_case1();
void TestSuite_mapp_music_test_MApp_Music_WAV_Probe_case1();
void TestSuite_mapp_music_test_MApp_Music_MP3_Probe_case1();
void TestSuite_mapp_music_test_MApp_Music_ProcessFfRew_case6();
void TestSuite_mapp_music_test_MApp_Music_CalculateMP3CBRDuration_ID3V2();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_mapp_music);

void TestSuite_mapp_music_setUp()
{
}

void TestSuite_mapp_music_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_SetFileEntry_NULL */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Music_SetFileEntry(FileEntry *) */
void TestSuite_mapp_music_test_MApp_Music_SetFileEntry_NULL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pEntry) */ 
    FileEntry * _pEntry  = 0 ;
    /* Initializing global variable m_pMp3FileEntry */ 
    {
         m_pMp3FileEntry  = 0 ;
    }
    {
        /* Tested function call */
        MApp_Music_SetFileEntry(_pEntry);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _pEntry,m_pMp3FileEntry);
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_SetFileEntry_NULL */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_PCM_SetInfo_allzero */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_PCM_SetInfo(U16, U16, U32, U16, BOOLEAN) */
void TestSuite_mapp_music_test_MApp_Music_PCM_SetInfo_allzero()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16FormatTag) */ 
    U16 _u16FormatTag  = 0u;
    /* Initializing argument 2 (u16Channels) */ 
    U16 _u16Channels  = 0u;
    /* Initializing argument 3 (u32SamplesPerSec) */ 
    U32 _u32SamplesPerSec  = 0ul;
    /* Initializing argument 4 (u16BitsPerSample) */ 
    U16 _u16BitsPerSample  = 0u;
    /* Initializing argument 5 (bBigEndian) */ 
    U8 _bBigEndian  = 0;
    /* Initializing global variable stPCMParam */ 
    {
         stPCMParam.u16FormatTag  = 0u;
         stPCMParam.u16Channels  = 0u;
         stPCMParam.u32SamplesPerSec  = 0ul;
         stPCMParam.u32AvgBytesPerSec  = 0ul;
         stPCMParam.u16BlockSize  = 0u;
         stPCMParam.u16BitsPerSample  = 0u;
         stPCMParam.bBigEndian  = 0;
         stPCMParam.bIsConfig  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_Music_PCM_SetInfo(_u16FormatTag, _u16Channels, _u32SamplesPerSec, _u16BitsPerSample, _bBigEndian);

        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 0,stPCMParam.u16FormatTag);
        CPPTEST_ASSERT_EQUAL( 0,stPCMParam.u16Channels);
        CPPTEST_ASSERT_EQUAL( 0,stPCMParam.u32SamplesPerSec);
        CPPTEST_ASSERT_EQUAL( 0,stPCMParam.u16BitsPerSample);
        CPPTEST_ASSERT_EQUAL( 0,stPCMParam.bBigEndian);
        CPPTEST_ASSERT_EQUAL( 0,stPCMParam.u32AvgBytesPerSec);
        CPPTEST_ASSERT_EQUAL( 0,stPCMParam.u16BlockSize);
        CPPTEST_ASSERT_EQUAL( 1,stPCMParam.bIsConfig);
        CPPTEST_ASSERT_EQUAL( TRUE,_return);
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_PCM_SetInfo_allzero */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_GetFfRewSpeed_FWMode_case0 */
/* CPPTEST_TEST_CASE_CONTEXT EN_MP3_SPEED MApp_Music_GetFfRewSpeed(void) */
void TestSuite_mapp_music_test_MApp_Music_GetFfRewSpeed_FWMode_case0()
{
    /* Pre-condition initialization */
    /* Initializing global variable u8MusicFFFWMode */ 
    {
         u8MusicFFFWMode  = 0;
    }
    /* Initializing global variable enMp3PlaySpeed */ 
    {
         enMp3PlaySpeed  = EN_MP3_SPEED_X1;
    }
    {
        /* Tested function call */
        EN_MP3_SPEED _return  = MApp_Music_GetFfRewSpeed();

        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_MP3_SPEED_X1, ( _return ) );
        CPPTEST_ASSERT_EQUAL( EN_MP3_SPEED_X1, ( enMp3PlaySpeed ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_GetFfRewSpeed_FWMode_case0 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_GetFfRewSpeed_FWMode_case1 */
/* CPPTEST_TEST_CASE_CONTEXT EN_MP3_SPEED MApp_Music_GetFfRewSpeed(void) */
void TestSuite_mapp_music_test_MApp_Music_GetFfRewSpeed_FWMode_case1()
{
    /* Pre-condition initialization */
    /* Initializing global variable u8MusicFFFWMode */ 
    {
         u8MusicFFFWMode  = 1;
    }
    /* Initializing global variable enMp3PlaySpeed */ 
    {
         enMp3PlaySpeed  = EN_MP3_SPEED_X1;
    }
    {
        /* Tested function call */
        EN_MP3_SPEED _return  = MApp_Music_GetFfRewSpeed();

        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_MP3_SPEED_X1, ( _return ) );
        CPPTEST_ASSERT_EQUAL( EN_MP3_SPEED_X1, ( enMp3PlaySpeed ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_GetFfRewSpeed_FWMode_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_ProcessFfRew_FWMode_case0 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Music_ProcessFfRew(void) */
void TestSuite_mapp_music_test_MApp_Music_ProcessFfRew_FWMode_case0()
{
    /* Pre-condition initialization */

  //test MP3_NORMAL_MODE
    /* Initializing global variable u8MusicFFFWMode */ 
    {
         u8MusicFFFWMode  = MP3_NORMAL_MODE;

        /* Tested function call */
        MApp_Music_ProcessFfRew();

        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MP3_NORMAL_MODE, u8MusicFFFWMode );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_ProcessFfRew_FWMode_case0 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_ProcessFfRew_FWMode_case3 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Music_ProcessFfRew(void) */
void TestSuite_mapp_music_test_MApp_Music_ProcessFfRew_FWMode_case3()
{
    /* Pre-condition initialization */

  //test wrong mode
    /* Initializing global variable u8MusicFFFWMode */ 
    {
         u8MusicFFFWMode  = 3;

        /* Tested function call */
        MApp_Music_ProcessFfRew();
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(3,u8MusicFFFWMode);
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_ProcessFfRew_FWMode_case3 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_IsAAC_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_IsAAC(void) */
void TestSuite_mapp_music_test_MApp_Music_IsAAC_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing global variable boxM4a */ 
    {
         boxM4a.bFoundmdat  = 0;

        /* Tested function call */
        BOOLEAN _return  = MApp_Music_IsAAC();
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE,  _return );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_IsAAC_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_IsAAC_FALSE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_IsAAC(void) */
void TestSuite_mapp_music_test_MApp_Music_IsAAC_FALSE()
{
    /* Pre-condition initialization */
    /* Initializing global variable boxM4a */ 
    {

         boxM4a.bFoundmdat  = 1;

        /* Tested function call */
        BOOLEAN _return  = MApp_Music_IsAAC();
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE,  _return );

    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_IsAAC_FALSE */



/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_ReadDescrLength_esds */
/* CPPTEST_TEST_CASE_CONTEXT U8 M4AParser_ReadDescrLength(const U8 *, U8 *) */
void TestSuite_mapp_music_test_M4AParser_ReadDescrLength_esds()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fileData) */ 
    U8 _fileData_0  = 0;
    const U8 * _fileData  = & _fileData_0;
    /* Initializing argument 2 (len) */ 
    U8 _len_1  = 0;
    U8 * _len  = & _len_1;

    /* Tested function call */
    U8 _return  = M4AParser_ReadDescrLength(_fileData, _len);
    /* Post-condition check */
    CPPTEST_ASSERT_INTEGER_EQUAL(1, _return);

}
/* CPPTEST_TEST_CASE_END test_M4AParser_ReadDescrLength_esds */

/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_ExtractAtomName_case_notnull */
/* CPPTEST_TEST_CASE_CONTEXT U8 * M4AParser_ExtractAtomName(const U8 *) */
void TestSuite_mapp_music_test_M4AParser_ExtractAtomName_case_notnull()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fileData) */ 
    U8 _fileData_2[4]  = {0x00,0x00,0x00,0x00};
    const U8 * _fileData  = & _fileData_2;

  /* Tested function call */
  U8 * _return  = M4AParser_ExtractAtomName(_fileData);
  /* Post-condition check */
  CPPTEST_ASSERT_MEM_BUFFER_EQUAL("\00\00\00\00" , ( _return ), 4);

}
/* CPPTEST_TEST_CASE_END test_M4AParser_ExtractAtomName_case_notnull */

/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_GetSampleRate_case0 */
/* CPPTEST_TEST_CASE_CONTEXT U32 M4AParser_GetSampleRate(const U8 *) */
void TestSuite_mapp_music_test_M4AParser_GetSampleRate_case0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (buffer) */ 
    U8 _buffer_3[2]  = {0,0};
    const U8 * _buffer  = & _buffer_3;

    /* Tested function call */
    U32 _return  = M4AParser_GetSampleRate(_buffer);
    /* Post-condition check */
    CPPTEST_ASSERT_INTEGER_EQUAL(0, _return);


}
/* CPPTEST_TEST_CASE_END test_M4AParser_GetSampleRate_case0 */

/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_GetMdatSize_case0 */
/* CPPTEST_TEST_CASE_CONTEXT U32 M4AParser_GetMdatSize(const U8 *) */
void TestSuite_mapp_music_test_M4AParser_GetMdatSize_case0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (buffer) */ 
    U8 _buffer_4[4]  = {0x01,0x01,0x01,0x01};
    const U8 * _buffer  = & _buffer_4;

  /* Tested function call */
  U32 _return  = M4AParser_GetMdatSize(_buffer);
  /* Post-condition check */
  CPPTEST_ASSERT_INTEGER_EQUAL(0x1010101, _return);

}
/* CPPTEST_TEST_CASE_END test_M4AParser_GetMdatSize_case0 */

/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_DealPostfix_nIndex_case0 */
/* CPPTEST_TEST_CASE_CONTEXT U32 M4AParser_DealPostfix(U32, const U8 *, const U8 *) */
void TestSuite_mapp_music_test_M4AParser_DealPostfix_nIndex_case0()
{
    /* Pre-condition initialization */

  //test case0
    /* Initializing argument 1 (nIndex) */ 
    U32 _nIndex  = 0ul;
    /* Initializing argument 2 (buffer) */ 
    U8 _buffer_5[2]  = {1,1};
    const U8 * _buffer  = & _buffer_5;
    /* Initializing argument 3 (fixbuffer) */ 
    U8 _fixbuffer_6[6]  = {1,1,1,1,1,1};
    const U8 * _fixbuffer  = & _fixbuffer_6;

  /* Tested function call */
  U32 _return  = M4AParser_DealPostfix(_nIndex, _buffer, _fixbuffer);
  /* Post-condition check */
  CPPTEST_ASSERT_INTEGER_EQUAL(0x1010100, _return);

}
/* CPPTEST_TEST_CASE_END test_M4AParser_DealPostfix_nIndex_case0 */

/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_DealPostfix_nIndex_case1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 M4AParser_DealPostfix(U32, const U8 *, const U8 *) */
void TestSuite_mapp_music_test_M4AParser_DealPostfix_nIndex_case1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (nIndex) */ 
    U32 _nIndex  = 1ul;
    /* Initializing argument 2 (buffer) */ 
    U8 _buffer_7[2]  = {1,1};
    const U8 * _buffer  = & _buffer_7;
    /* Initializing argument 3 (fixbuffer) */ 
    U8 _fixbuffer_8[6]  = {1,1,1,1,1,1};
    const U8 * _fixbuffer  = & _fixbuffer_8;

    /* Tested function call */
  U32 _return  = M4AParser_DealPostfix(_nIndex, _buffer, _fixbuffer);
  /* Post-condition check */
  CPPTEST_ASSERT_INTEGER_EQUAL(0x1010001, _return);
}
/* CPPTEST_TEST_CASE_END test_M4AParser_DealPostfix_nIndex_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_DealPostfix_nIndex_case3 */
/* CPPTEST_TEST_CASE_CONTEXT U32 M4AParser_DealPostfix(U32, const U8 *, const U8 *) */
void TestSuite_mapp_music_test_M4AParser_DealPostfix_nIndex_case3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (nIndex) */ 
    U32 _nIndex  = 3;
    /* Initializing argument 2 (buffer) */ 
    U8 _buffer_9[2]  = {1,1};
    const U8 * _buffer  = & _buffer_9;
    /* Initializing argument 3 (fixbuffer) */ 
    U8 _fixbuffer_10[6]  = {1,1,1,1,1,1};
    const U8 * _fixbuffer  = & _fixbuffer_10;

    /* Tested function call */
  U32 _return  = M4AParser_DealPostfix(_nIndex, _buffer, _fixbuffer);
  /* Post-condition check */
  CPPTEST_ASSERT_INTEGER_EQUAL(0, _return);
}
/* CPPTEST_TEST_CASE_END test_M4AParser_DealPostfix_nIndex_case3 */

/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_DealPostfix_nIndex_2 */
/* CPPTEST_TEST_CASE_CONTEXT U32 M4AParser_DealPostfix(U32, const U8 *, const U8 *) */
void TestSuite_mapp_music_test_M4AParser_DealPostfix_nIndex_2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (nIndex) */ 
    U32 _nIndex  = 2;
    /* Initializing argument 2 (buffer) */ 
    U8 _buffer_11[2]  = {1,1};
    const U8 * _buffer  = & _buffer_11;
    /* Initializing argument 3 (fixbuffer) */ 
    U8 _fixbuffer_12[6]  = {1,1,1,1,1,1};
    const U8 * _fixbuffer  = & _fixbuffer_12;

    /* Tested function call */
    U32 _return  = M4AParser_DealPostfix(_nIndex, _buffer, _fixbuffer);
    /* Post-condition check */
    CPPTEST_ASSERT_INTEGER_EQUAL(0x1000101, _return);
}
/* CPPTEST_TEST_CASE_END test_M4AParser_DealPostfix_nIndex_2 */

/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_ExtractFix */
/* CPPTEST_TEST_CASE_CONTEXT U8 * M4AParser_ExtractFix(U8 *) */
void TestSuite_mapp_music_test_M4AParser_ExtractFix()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fileData) */ 
    U8 _fileData_13[7];
    U8 * _fileData  = & _fileData_13;

  /* Tested function call */
  U8 * _return  = M4AParser_ExtractFix(_fileData);
  /* Post-condition check */
  CPPTEST_ASSERT_MEM_BUFFER_EQUAL("\00\00\00\00\00\00\00" , ( _return ), 7);

}
/* CPPTEST_TEST_CASE_END test_M4AParser_ExtractFix */

/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_DealPostfixstco_u32Index_case0 */
/* CPPTEST_TEST_CASE_CONTEXT U32 M4AParser_DealPostfixstco(U32, const char *, const char *) */
void TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case0()
{
    /* Pre-condition initialization */

  //test case 0

    /* Initializing argument 1 (u32Index) */ 
    U32 _u32Index  = 0ul;
    /* Initializing argument 2 (buffer) */ 
    char bufferTemp[8]={1,1,1,1,1,1,1,1};
    const char * _buffer  = &bufferTemp;
    /* Initializing argument 3 (fixbuffer) */ 
    const char * _fixbuffer  =&bufferTemp;

  /* Tested function call */
  U32 _return  = M4AParser_DealPostfixstco(_u32Index, _buffer, _fixbuffer);
  /* Post-condition check */
  CPPTEST_ASSERT_INTEGER_EQUAL(0x1010101, _return);

}
/* CPPTEST_TEST_CASE_END test_M4AParser_DealPostfixstco_u32Index_case0 */

/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_DealPostfixstco_u32Index_case1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 M4AParser_DealPostfixstco(U32, const char *, const char *) */
void TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Index) */ 
    U32 _u32Index  = 1ul;
    /* Initializing argument 2 (buffer) */ 
    char bufferTemp[8]={1,1,1,1,1,1,1,1};
    const char * _buffer  =&bufferTemp ;
    /* Initializing argument 3 (fixbuffer) */ 
    const char * _fixbuffer  = &bufferTemp ;

  /* Tested function call */
  U32 _return  = M4AParser_DealPostfixstco(_u32Index, _buffer, _fixbuffer);
  /* Post-condition check */
  CPPTEST_ASSERT_INTEGER_EQUAL(0x1010101, _return);

}
/* CPPTEST_TEST_CASE_END test_M4AParser_DealPostfixstco_u32Index_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_DealPostfixstco_u32Index_case2 */
/* CPPTEST_TEST_CASE_CONTEXT U32 M4AParser_DealPostfixstco(U32, const char *, const char *) */
void TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Index) */ 
    U32 _u32Index  = 2;
    /* Initializing argument 2 (buffer) */
    char bufferTemp[8]={1,1,1,1,1,1,1,1};
    const char * _buffer  = &bufferTemp ;
    /* Initializing argument 3 (fixbuffer) */ 
    const char * _fixbuffer  = &bufferTemp ;

  /* Tested function call */
  U32 _return  = M4AParser_DealPostfixstco(_u32Index, _buffer, _fixbuffer);
  /* Post-condition check */
  CPPTEST_ASSERT_INTEGER_EQUAL(0x1010101, _return);

}
/* CPPTEST_TEST_CASE_END test_M4AParser_DealPostfixstco_u32Index_case2 */

/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_DealPostfixstco_u32Index_case3 */
/* CPPTEST_TEST_CASE_CONTEXT U32 M4AParser_DealPostfixstco(U32, const char *, const char *) */
void TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Index) */ 
    U32 _u32Index  = 3;
    /* Initializing argument 2 (buffer) */ 
    char bufferTemp[8]={1,1,1,1,1,1,1,1};
    const char * _buffer  = &bufferTemp ;
    /* Initializing argument 3 (fixbuffer) */ 
    const char * _fixbuffer  = &bufferTemp ;

  /* Tested function call */
  U32 _return  = M4AParser_DealPostfixstco(_u32Index, _buffer, _fixbuffer);
  /* Post-condition check */
  CPPTEST_ASSERT_INTEGER_EQUAL(0x1010101, _return);

}
/* CPPTEST_TEST_CASE_END test_M4AParser_DealPostfixstco_u32Index_case3 */

/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_DealPostfixstco_u32Index_case4 */
/* CPPTEST_TEST_CASE_CONTEXT U32 M4AParser_DealPostfixstco(U32, const char *, const char *) */
void TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case4()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Index) */ 
    U32 _u32Index  = 4;
    /* Initializing argument 2 (buffer) */
    char bufferTemp[8]={1,1,1,1,1,1,1,1};
    const char * _buffer  = &bufferTemp ;
    /* Initializing argument 3 (fixbuffer) */ 
    const char * _fixbuffer  = &bufferTemp ;

  /* Tested function call */
  U32 _return  = M4AParser_DealPostfixstco(_u32Index, _buffer, _fixbuffer);
  /* Post-condition check */
  CPPTEST_ASSERT_INTEGER_EQUAL(0x1010101, _return);

}
/* CPPTEST_TEST_CASE_END test_M4AParser_DealPostfixstco_u32Index_case4 */

/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_DealPostfixstco_u32Index_case5 */
/* CPPTEST_TEST_CASE_CONTEXT U32 M4AParser_DealPostfixstco(U32, const char *, const char *) */
void TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case5()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Index) */ 
    U32 _u32Index  = 5;
    /* Initializing argument 2 (buffer) */ 
    char bufferTemp[8]={1,1,1,1,1,1,1,1};
    const char * _buffer  = &bufferTemp ;
    /* Initializing argument 3 (fixbuffer) */ 
    const char * _fixbuffer  = &bufferTemp ;

  /* Tested function call */
  U32 _return  = M4AParser_DealPostfixstco(_u32Index, _buffer, _fixbuffer);
  /* Post-condition check */
  CPPTEST_ASSERT_INTEGER_EQUAL(0x1010101, _return);

}
/* CPPTEST_TEST_CASE_END test_M4AParser_DealPostfixstco_u32Index_case5 */

/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_DealPostfixstco_u32Index_case6 */
/* CPPTEST_TEST_CASE_CONTEXT U32 M4AParser_DealPostfixstco(U32, const char *, const char *) */
void TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case6()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Index) */ 
    U32 _u32Index  = 6;
    /* Initializing argument 2 (buffer) */ 
    char bufferTemp[8]={1,1,1,1,1,1,1,1};
    const char * _buffer  = &bufferTemp ;
    /* Initializing argument 3 (fixbuffer) */ 
    const char * _fixbuffer  = &bufferTemp ;

  /* Tested function call */
  U32 _return  = M4AParser_DealPostfixstco(_u32Index, _buffer, _fixbuffer);
  /* Post-condition check */
  CPPTEST_ASSERT_INTEGER_EQUAL(0x1010101, _return);

}
/* CPPTEST_TEST_CASE_END test_M4AParser_DealPostfixstco_u32Index_case6 */

/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_DealPostfixstco_u32Index_case7 */
/* CPPTEST_TEST_CASE_CONTEXT U32 M4AParser_DealPostfixstco(U32, const char *, const char *) */
void TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case7()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Index) */ 
    U32 _u32Index  = 7;
    /* Initializing argument 2 (buffer) */ 
    char bufferTemp[8]={1,1,1,1,1,1,1,1};
    const char * _buffer  = &bufferTemp ;
    /* Initializing argument 3 (fixbuffer) */ 
    const char * _fixbuffer  = &bufferTemp ;

  /* Tested function call */
  U32 _return  = M4AParser_DealPostfixstco(_u32Index, _buffer, _fixbuffer);
  /* Post-condition check */
  CPPTEST_ASSERT_INTEGER_EQUAL(0x1010101, _return);

}
/* CPPTEST_TEST_CASE_END test_M4AParser_DealPostfixstco_u32Index_case7 */


/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_DealPostfixstco_u32Index_case8 */
/* CPPTEST_TEST_CASE_CONTEXT U32 M4AParser_DealPostfixstco(U32, const char *, const char *) */
void TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_case8()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Index) */ 
    U32 _u32Index  = 8;
    /* Initializing argument 2 (buffer) */ 
    char bufferTemp[8]={1,1,1,1,1,1,1,1};
    const char * _buffer  = &bufferTemp ;
    /* Initializing argument 3 (fixbuffer) */ 
    const char * _fixbuffer  = &bufferTemp ;

  /* Tested function call */
  U32 _return  = M4AParser_DealPostfixstco(_u32Index, _buffer, _fixbuffer);
  /* Post-condition check */
  CPPTEST_ASSERT_INTEGER_EQUAL(0x1010100, _return);

}
/* CPPTEST_TEST_CASE_END test_M4AParser_DealPostfixstco_u32Index_case8 */

/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_DealPostfixstco_u32Index_casedefault */
/* CPPTEST_TEST_CASE_CONTEXT U32 M4AParser_DealPostfixstco(U32, const char *, const char *) */
void TestSuite_mapp_music_test_M4AParser_DealPostfixstco_u32Index_casedefault()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Index) */ 
    U32 _u32Index  = 9;
    /* Initializing argument 2 (buffer) */ 
    char bufferTemp[8]={1,1,1,1,1,1,1,1};
    const char * _buffer  = &bufferTemp ;
    /* Initializing argument 3 (fixbuffer) */ 
    const char * _fixbuffer  = &bufferTemp ;

  /* Tested function call */
  U32 _return  = M4AParser_DealPostfixstco(_u32Index, _buffer, _fixbuffer);
  /* Post-condition check */
  CPPTEST_ASSERT_INTEGER_EQUAL(0, _return);

}
/* CPPTEST_TEST_CASE_END test_M4AParser_DealPostfixstco_u32Index_casedefault */

/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_GetSampleRateIndex_dwValue_case0 */
/* CPPTEST_TEST_CASE_CONTEXT U8 M4AParser_GetSampleRateIndex(U32) */
void TestSuite_mapp_music_test_M4AParser_GetSampleRateIndex_dwValue_case0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (dwValue) */ 
    U32 _dwValue  = 0ul;

  /* Tested function call */
  U8 _return  = M4AParser_GetSampleRateIndex(_dwValue);
  /* Post-condition check */
  CPPTEST_ASSERT_INTEGER_EQUAL(0, _return);

}
/* CPPTEST_TEST_CASE_END test_M4AParser_GetSampleRateIndex_dwValue_case0 */

/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_GetSampleRateIndex_dwValue_case1 */
/* CPPTEST_TEST_CASE_CONTEXT U8 M4AParser_GetSampleRateIndex(U32) */
void TestSuite_mapp_music_test_M4AParser_GetSampleRateIndex_dwValue_case1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (dwValue) */ 
    U32 _dwValue  = 1ul;

  /* Tested function call */
  U8 _return  = M4AParser_GetSampleRateIndex(_dwValue);
  /* Post-condition check */
  CPPTEST_ASSERT_INTEGER_EQUAL(255, _return);

}
/* CPPTEST_TEST_CASE_END test_M4AParser_GetSampleRateIndex_dwValue_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_GetInfoString_enInfo_case1 */
/* CPPTEST_TEST_CASE_CONTEXT U8 * MApp_Music_GetInfoString(EN_MP3_INFO) */
void TestSuite_mapp_music_test_MApp_Music_GetInfoString_enInfo_case1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enInfo) */ 
    EN_MP3_INFO _enInfo  = MP3_INFO_BITRATE;
    /* Initializing global variable stMp3Info */ 
   stMp3Info.u16BitRate  = 128u;

  /* Tested function call */
  U8 * _return  = MApp_Music_GetInfoString(_enInfo);
  /* Post-condition check */
  CPPTEST_ASSERT_MEM_BUFFER_EQUAL("\061 ", ( _return ),1);

}
/* CPPTEST_TEST_CASE_END test_MApp_Music_GetInfoString_enInfo_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_GetInfoString_enInfo_case2 */
/* CPPTEST_TEST_CASE_CONTEXT U8 * MApp_Music_GetInfoString(EN_MP3_INFO) */
void TestSuite_mapp_music_test_MApp_Music_GetInfoString_enInfo_case2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enInfo) */ 
    EN_MP3_INFO _enInfo  = MP3_INFO_SAMPLINGRATE;
    /* Initializing global variable stMp3Info */ 

   stMp3Info.u16SampleRate  = 44800u;
  /* Tested function call */
  U8 * _return  = MApp_Music_GetInfoString(_enInfo);
  /* Post-condition check */
  CPPTEST_ASSERT_MEM_BUFFER_EQUAL("\064", ( _return ),1);

}
/* CPPTEST_TEST_CASE_END test_MApp_Music_GetInfoString_enInfo_case2 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_GetInfoString_enInfo_case3 */
/* CPPTEST_TEST_CASE_CONTEXT U8 * MApp_Music_GetInfoString(EN_MP3_INFO) */
void TestSuite_mapp_music_test_MApp_Music_GetInfoString_enInfo_case3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enInfo) */ 
    EN_MP3_INFO _enInfo  = MP3_INFO_ALBUM;
    /* Initializing global variable stMp3Info */ 
    {
         //test ID3V2
         stMp3Info.bID3TagV1  = 0;
         stMp3Info.u16ID3TagV1Size  = 0u;
         stMp3Info.stID3v1.u8AlbumLength = 0;

         stMp3Info.bID3TagV2  = 1;
         stMp3Info.u32ID3TagV2Size  = 100ul;
         stMp3Info.stID3v2.u8AlbumLength = 8;

        /* Tested function call */
        U8 * _return  = MApp_Music_GetInfoString(_enInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_MEM_BUFFER_EQUAL((U8*)stMp3Info.stID3v2.album, ( _return ),1);
    }
    {
        //test ID3V1
        stMp3Info.bID3TagV1  = 1;
        stMp3Info.u16ID3TagV1Size  = 100u;
        stMp3Info.stID3v1.u8AlbumLength = 8;

        stMp3Info.bID3TagV2  = 0;
        stMp3Info.u32ID3TagV2Size  = 0ul;
        stMp3Info.stID3v2.u8AlbumLength = 0;

       /* Tested function call */
       U8 * _return  = MApp_Music_GetInfoString(_enInfo);
       /* Post-condition check */
       CPPTEST_ASSERT_MEM_BUFFER_EQUAL((U8*)stMp3Info.stID3v1.album, ( _return ),1);
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_GetInfoString_enInfo_case3 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_GetInfoString_enfo_case4 */
/* CPPTEST_TEST_CASE_CONTEXT U8 * MApp_Music_GetInfoString(EN_MP3_INFO) */
void TestSuite_mapp_music_test_MApp_Music_GetInfoString_enfo_case4()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enInfo) */ 
    EN_MP3_INFO _enInfo  = MP3_INFO_TITLE;
    /* Initializing global variable stMp3Info */ 
    {
        //test ID3V2
         stMp3Info.bID3TagV1  = 0;
         stMp3Info.u16ID3TagV1Size  = 0u;
         stMp3Info.stID3v1.u8TitleLength = 0;

         stMp3Info.bID3TagV2  = 1;
         stMp3Info.u32ID3TagV2Size  = 100ul;
         stMp3Info.stID3v2.u8TitleLength = 8;

        /* Tested function call */
        U8 * _return  = MApp_Music_GetInfoString(_enInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_MEM_BUFFER_EQUAL((U8*)stMp3Info.stID3v2.title, ( _return ),1);
    }
    {
        //test ID3V1
         stMp3Info.bID3TagV1  = 1;
         stMp3Info.u16ID3TagV1Size  = 100u;
         stMp3Info.stID3v1.u8TitleLength = 8;

         stMp3Info.bID3TagV2  = 0;
         stMp3Info.u32ID3TagV2Size  = 0;
         stMp3Info.stID3v2.u8TitleLength = 0;

        /* Tested function call */
        U8 * _return  = MApp_Music_GetInfoString(_enInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_MEM_BUFFER_EQUAL((U8*)stMp3Info.stID3v1.title, ( _return ),1);
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_GetInfoString_enfo_case4 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_GetInfoString_enInfo_case5 */
/* CPPTEST_TEST_CASE_CONTEXT U8 * MApp_Music_GetInfoString(EN_MP3_INFO) */
void TestSuite_mapp_music_test_MApp_Music_GetInfoString_enInfo_case5()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enInfo) */ 
    EN_MP3_INFO _enInfo  = MP3_INFO_ARTIST;
    /* Initializing global variable stMp3Info */ 
    {
        //test ID3V2
         stMp3Info.bID3TagV1  = 0;
         stMp3Info.u16ID3TagV1Size  = 0u;
         stMp3Info.stID3v1.u8ArtistLength = 0;

         stMp3Info.bID3TagV2  = 1;
         stMp3Info.u32ID3TagV2Size  = 100ul;
         stMp3Info.stID3v2.u8ArtistLength = 8;

        /* Tested function call */
        U8 * _return  = MApp_Music_GetInfoString(_enInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_MEM_BUFFER_EQUAL((U8*)stMp3Info.stID3v2.artist, ( _return ),1);
    }
    {
        //test ID3V1
         stMp3Info.bID3TagV1  = 1;
         stMp3Info.u16ID3TagV1Size  = 100u;
         stMp3Info.stID3v1.u8ArtistLength = 8;

         stMp3Info.bID3TagV2  = 0;
         stMp3Info.u32ID3TagV2Size  = 0ul;
         stMp3Info.stID3v2.u8ArtistLength = 0;

        /* Tested function call */
        U8 * _return  = MApp_Music_GetInfoString(_enInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_MEM_BUFFER_EQUAL((U8*)stMp3Info.stID3v1.artist, ( _return ),1);
    }


}
/* CPPTEST_TEST_CASE_END test_MApp_Music_GetInfoString_enInfo_case5 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_GetInfoString_enInfo_case6 */
/* CPPTEST_TEST_CASE_CONTEXT U8 * MApp_Music_GetInfoString(EN_MP3_INFO) */
void TestSuite_mapp_music_test_MApp_Music_GetInfoString_enInfo_case6()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enInfo) */ 
    EN_MP3_INFO _enInfo  = MP3_INFO_YEAR;
    /* Initializing global variable stMp3Info */ 
    {
      //test ID3V2
         stMp3Info.bID3TagV2  = 1;
         stMp3Info.bID3TagV1  = 0;

        /* Tested function call */
        U8 * _return  = MApp_Music_GetInfoString(_enInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_MEM_BUFFER_EQUAL(stMp3Info.stID3v2.year, ( _return ),1);
    }
    {
      //test ID3V1
         stMp3Info.bID3TagV2  = 0;
         stMp3Info.bID3TagV1  = 1;

        /* Tested function call */
        U8 * _return  = MApp_Music_GetInfoString(_enInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_MEM_BUFFER_EQUAL(stMp3Info.stID3v1.year, ( _return ),1);
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_GetInfoString_enInfo_case6 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_GetInfoString_enInfo_case9 */
/* CPPTEST_TEST_CASE_CONTEXT U8 * MApp_Music_GetInfoString(EN_MP3_INFO) */
void TestSuite_mapp_music_test_MApp_Music_GetInfoString_enInfo_case9()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enInfo) */ 
    EN_MP3_INFO _enInfo  = MP3_INFO_CHECK_FF_FB;


  /* Tested function call */
  U8 * _return  = MApp_Music_GetInfoString(_enInfo);
  /* Post-condition check */
  CPPTEST_ASSERT_MEM_BUFFER_EQUAL((U8*)&stMp3Info.bCheckFfFb, ( _return ),1);

}
/* CPPTEST_TEST_CASE_END test_MApp_Music_GetInfoString_enInfo_case9 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_GetInfoStringLength_enInfo_caseMP3INFOALBUM */
/* CPPTEST_TEST_CASE_CONTEXT U8 MApp_Music_GetInfoStringLength(EN_MP3_INFO) */
void TestSuite_mapp_music_test_MApp_Music_GetInfoStringLength_enInfo_caseMP3INFOALBUM()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enInfo) */ 
    EN_MP3_INFO _enInfo  = MP3_INFO_ALBUM;
    /* Initializing global variable stMp3Info */ 
    {
         stMp3Info.stID3v2.u8AlbumLength = 5;

        /* Tested function call */
        U8 _return  = MApp_Music_GetInfoStringLength(_enInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(5, ( _return ));
    }
    {
      stMp3Info.stID3v2.u8AlbumLength = 0;
    }
    {
        /* Tested function call */
        U8 _return  = MApp_Music_GetInfoStringLength(_enInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(32, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_GetInfoStringLength_enInfo_caseMP3INFOALBUM */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_GetInfoStringLength_enInfo_caseMP3InfoTitle */
/* CPPTEST_TEST_CASE_CONTEXT U8 MApp_Music_GetInfoStringLength(EN_MP3_INFO) */
void TestSuite_mapp_music_test_MApp_Music_GetInfoStringLength_enInfo_caseMP3InfoTitle()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enInfo) */ 
    EN_MP3_INFO _enInfo  = MP3_INFO_TITLE;
    /* Initializing global variable stMp3Info */ 
    {
      stMp3Info.stID3v2.u8TitleLength = 5;
    }
    {
        /* Tested function call */
        U8 _return  = MApp_Music_GetInfoStringLength(_enInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(5, ( _return ));
    }
    {
      stMp3Info.stID3v2.u8TitleLength = 0;
    }
    {
        /* Tested function call */
        U8 _return  = MApp_Music_GetInfoStringLength(_enInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(32, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_GetInfoStringLength_enInfo_caseMP3InfoTitle */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_GetInfoStringLength_enInfo_caseMP3InfoComment */
/* CPPTEST_TEST_CASE_CONTEXT U8 MApp_Music_GetInfoStringLength(EN_MP3_INFO) */
void TestSuite_mapp_music_test_MApp_Music_GetInfoStringLength_enInfo_caseMP3InfoComment()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enInfo) */ 
    EN_MP3_INFO _enInfo  = MP3_INFO_COMMENT;
    /* Initializing global variable stMp3Info */ 
    {
         stMp3Info.bID3TagV2  = 1;

        /* Tested function call */
        U8 _return  = MApp_Music_GetInfoStringLength(_enInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(MP3_INFO_LENGTH, ( _return ));
    }
    {
         stMp3Info.bID3TagV2  = 0;

        /* Tested function call */
        U8 _return  = MApp_Music_GetInfoStringLength(_enInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(32, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_GetInfoStringLength_enInfo_caseMP3InfoComment */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_GetInfoStringLength_enInfo_caseMP3InfoArtist */
/* CPPTEST_TEST_CASE_CONTEXT U8 MApp_Music_GetInfoStringLength(EN_MP3_INFO) */
void TestSuite_mapp_music_test_MApp_Music_GetInfoStringLength_enInfo_caseMP3InfoArtist()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enInfo) */ 
    EN_MP3_INFO _enInfo  = MP3_INFO_ARTIST;
    /* Initializing global variable stMp3Info */ 
    {
      stMp3Info.stID3v2.u8ArtistLength = 5;

        /* Tested function call */
        U8 _return  = MApp_Music_GetInfoStringLength(_enInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(stMp3Info.stID3v2.u8ArtistLength, ( _return ));
    }
    {
      stMp3Info.stID3v2.u8ArtistLength = 0;

        /* Tested function call */
        U8 _return  = MApp_Music_GetInfoStringLength(_enInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(32, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_GetInfoStringLength_enInfo_caseMP3InfoArtist */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_GetInfoStringLength_enInfo_caseMP3InfoYear */
/* CPPTEST_TEST_CASE_CONTEXT U8 MApp_Music_GetInfoStringLength(EN_MP3_INFO) */
void TestSuite_mapp_music_test_MApp_Music_GetInfoStringLength_enInfo_caseMP3InfoYear()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enInfo) */ 
    EN_MP3_INFO _enInfo  = MP3_INFO_YEAR;
    /* Initializing global variable stMp3Info */ 
    {
      stMp3Info.bID3TagV2 = 1;

        /* Tested function call */
        U8 _return  = MApp_Music_GetInfoStringLength(_enInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(MP3_INFO_YEAR_LENGTH, ( _return ));
    }
    {
      stMp3Info.bID3TagV2 = 0;
        /* Tested function call */
        U8 _return  = MApp_Music_GetInfoStringLength(_enInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(6, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_GetInfoStringLength_enInfo_caseMP3InfoYear */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_GetInfoStringLength_enInfo_caseDefault */
/* CPPTEST_TEST_CASE_CONTEXT U8 MApp_Music_GetInfoStringLength(EN_MP3_INFO) */
void TestSuite_mapp_music_test_MApp_Music_GetInfoStringLength_enInfo_caseDefault()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enInfo) */ 
    EN_MP3_INFO _enInfo  = 11;


  /* Tested function call */
  U8 _return  = MApp_Music_GetInfoStringLength(_enInfo);
  /* Post-condition check */
  CPPTEST_ASSERT_INTEGER_EQUAL(0, ( _return ));

}
/* CPPTEST_TEST_CASE_END test_MApp_Music_GetInfoStringLength_enInfo_caseDefault */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_GetFlacSampleIndex_u32KeyIndex_caseValid */
/* CPPTEST_TEST_CASE_CONTEXT U64 MApp_Music_GetFlacSampleIndex(U32) */
void TestSuite_mapp_music_test_MApp_Music_GetFlacSampleIndex_u32KeyIndex_caseValid()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32KeyIndex) */ 
    U32 _u32KeyIndex  = 0ul;
    ST_FLAC_SEEK_TABLE stFlacSeekTableTemp[1] = {1,1,1};
    /* Initializing global variable m_stFlacInfo */ 

   m_stFlacInfo.pstSeekTable = &stFlacSeekTableTemp;
   m_stFlacInfo.u32SeekEntryCount  = 1ul;


  /* Tested function call */
  U64 _return  = MApp_Music_GetFlacSampleIndex(_u32KeyIndex);
  /* Post-condition check */
  CPPTEST_ASSERT_INTEGER_EQUAL(1, ( _return ));

}
/* CPPTEST_TEST_CASE_END test_MApp_Music_GetFlacSampleIndex_u32KeyIndex_caseValid */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_GetFlacSampleIndex_u32KeyIndex_caseInvalid */
/* CPPTEST_TEST_CASE_CONTEXT U64 MApp_Music_GetFlacSampleIndex(U32) */
void TestSuite_mapp_music_test_MApp_Music_GetFlacSampleIndex_u32KeyIndex_caseInvalid()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32KeyIndex) */ 
    U32 _u32KeyIndex  = 1ul;
    m_stFlacInfo.u32SeekEntryCount = 0;

    ST_FLAC_SEEK_TABLE stFlacSeekTableTemp[1] = {1,1,1};
  m_stFlacInfo.pstSeekTable = &stFlacSeekTableTemp;

  /* Tested function call */
  U64 _return  = MApp_Music_GetFlacSampleIndex(_u32KeyIndex);
  /* Post-condition check */
  CPPTEST_ASSERT_INTEGER_EQUAL(0, ( _return ));

}
/* CPPTEST_TEST_CASE_END test_MApp_Music_GetFlacSampleIndex_u32KeyIndex_caseInvalid */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_CloseFile */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Music_CloseFile(void) */
void TestSuite_mapp_music_test_MApp_Music_CloseFile()
{
    /* Pre-condition initialization */
    /* Initializing global variable u32Mp3FileHandle */ 
    {
         u32Mp3FileHandle  = 0ul;
    }
    {
        /* Tested function call */
        MApp_Music_CloseFile();
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(INVALID_DATA_STREAM_HDL, ( u32Mp3FileHandle ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_CloseFile */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_AAC_Frame_Parsing_u32Mp3FileHandle_caseInvalid */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_AAC_Frame_Parsing(void) */
void TestSuite_mapp_music_test_MApp_AAC_Frame_Parsing_u32Mp3FileHandle_caseInvalid()
{

  /* Tested function call */
  BOOLEAN _return  = MApp_AAC_Frame_Parsing();
  /* Post-condition check */
  CPPTEST_ASSERT_INTEGER_EQUAL(INVALID_DATA_STREAM_HDL, ( u32Mp3FileHandle ));
  CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));


}
/* CPPTEST_TEST_CASE_END test_MApp_AAC_Frame_Parsing_u32Mp3FileHandle_caseInvalid */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_AAC_Frame_Parsing_u32Mp3FileHandle_caseValid */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_AAC_Frame_Parsing(void) */
void TestSuite_mapp_music_test_MApp_AAC_Frame_Parsing_u32Mp3FileHandle_caseValid()
{
  /* Tested function call */
  BOOLEAN _return  = MApp_AAC_Frame_Parsing();

  /* Post-condition check */
  CPPTEST_ASSERT_INTEGER_EQUAL(1, ( stMp3Info.bID3TagV2 ));
  CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
}
/* CPPTEST_TEST_CASE_END test_MApp_AAC_Frame_Parsing_u32Mp3FileHandle_caseValid */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_Initial_enCurrentMusicType_MP3_FAIL */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_Initial(void) */
void TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusicType_MP3_FAIL()
{
    /* Pre-condition initialization */

    /* Initializing global variable enCurrentMusicType */ 
    {
         enCurrentMusicType  = EN_MUSIC_MP3;

        /* Tested function call */
        BOOLEAN _return  = MApp_Music_Initial();
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_Initial_enCurrentMusicType_MP3_FAIL */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_Initial_enCurrentMusicType_MP3_LAYER3 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_Initial(void) */
void TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusicType_MP3_LAYER3()
{
    /* Pre-condition initialization */

         stMp3Info.enLayer  = EN_MP3_LAYER_3;
         enCurrentMusicType  = EN_MUSIC_MP3;

        /* Tested function call */
        BOOLEAN _return  = MApp_Music_Initial();
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
        CPPTEST_ASSERT_INTEGER_EQUAL(MSAPI_AUD_DVB_MP3,enCurrentDecSystem);


}
/* CPPTEST_TEST_CASE_END test_MApp_Music_Initial_enCurrentMusicType_MP3_LAYER3 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_Initial_enCurrentMusicType_AAC_m4a */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_Initial(void) */
void TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusicType_AAC_m4a()
{
    /* Pre-condition initialization */
  {
    _u32FrameArrayIndex = 1;
  }

    /* Initializing global variable enCurrentMusicType */ 
    {
         enCurrentMusicType  = EN_MUSIC_AAC;
    }
    /* Initializing global variable g_box */
    {
    g_box.u8object_type = 2;
    }

    /* Initializing global variable m_IsQtFormat */ 
    {
         m_IsQtFormat  = 0;
    }
    /* Initializing global variable m_bPlayQtFormat */ 
    {
         m_bPlayQtFormat  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_Music_Initial();
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
        CPPTEST_ASSERT_INTEGER_EQUAL(MSAPI_AUD_DVB_AAC,enCurrentDecSystem);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, (  _bM4aEnableFFFB ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_Initial_enCurrentMusicType_AAC_m4a */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_Initial_enCurrentMusic_AAC_AAC_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_Initial(void) */
void TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusic_AAC_AAC_TRUE()
{
    /* Pre-condition initialization */

    /* Initializing global variable enCurrentMusicType */ 
    {
         enCurrentMusicType  = EN_MUSIC_AAC;
    }

    {
        /* Tested function call */
        BOOLEAN _return  = MApp_Music_Initial();
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
        CPPTEST_ASSERT_INTEGER_EQUAL(MSAPI_AUD_DVB_AAC,enCurrentDecSystem);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, (  _bM4aEnableFFFB ));
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, (  stMp3Info.bCheckFfFb ));
        CPPTEST_ASSERT_INTEGER_EQUAL(0,_u32FrameArrayIndex);


    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_Initial_enCurrentMusic_AAC_AAC_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_Initial_enCurrentMusic_AAC_FALSE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_Initial(void) */
void TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusic_AAC_FALSE()
{
    /* Pre-condition initialization */
    /* Initializing global variable enCurrentMusicType */ 
    {
         enCurrentMusicType  = EN_MUSIC_AAC;
    }

    {
    /* Tested function call */
    BOOLEAN _return  = MApp_Music_Initial();
    /* Post-condition check */
    CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    CPPTEST_ASSERT_INTEGER_EQUAL(MSAPI_AUD_DVB_AAC,enCurrentDecSystem);
    CPPTEST_ASSERT_BOOL_EQUAL(FALSE, (  _bM4aEnableFFFB ));
    CPPTEST_ASSERT_BOOL_EQUAL(FALSE, (  stMp3Info.bCheckFfFb ));
    CPPTEST_ASSERT_INTEGER_EQUAL(0,_u32FrameArrayIndex);
    }

}
/* CPPTEST_TEST_CASE_END test_MApp_Music_Initial_enCurrentMusic_AAC_FALSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_Initial_enCurrentMusic_FLAC_FALSE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_Initial(void) */
void TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusic_FLAC_FALSE()
{
    /* Pre-condition initialization */

  ST_FLAC_SEEK_TABLE stSeekTableTemp = {1,1,1};
    /* Initializing global variable m_stFlacInfo */ 
  m_stFlacInfo.pstSeekTable  = &stSeekTableTemp ;

  enCurrentMusicType  = EN_MUSIC_FLAC;
  /* Tested function call */
  BOOLEAN _return  = MApp_Music_Initial();
  /* Post-condition check */
  CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
  CPPTEST_ASSERT_PTR_EQUAL(NULL,m_stFlacInfo.pstSeekTable);

}
/* CPPTEST_TEST_CASE_END test_MApp_Music_Initial_enCurrentMusic_FLAC_FALSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_Initial_enCurrentMusic_FLAC_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_Initial(void) */
void TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusic_FLAC_TRUE()
{
  enCurrentMusicType  = EN_MUSIC_FLAC;

  /* Tested function call */
  BOOLEAN _return  = MApp_Music_Initial();
  /* Post-condition check */
  CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
  CPPTEST_ASSERT_INTEGER_EQUAL(MSAPI_AUD_DVB_FLAC,enCurrentDecSystem);

}
/* CPPTEST_TEST_CASE_END test_MApp_Music_Initial_enCurrentMusic_FLAC_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_Initial_enCurrentMusicType_LOAS */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_Initial(void) */
void TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusicType_LOAS()
{
  enCurrentMusicType  = EN_MUSIC_LOAS;

  /* Tested function call */
  BOOLEAN _return  = MApp_Music_Initial();
  /* Post-condition check */
  CPPTEST_ASSERT_INTEGER_EQUAL(INVALID_DATA_STREAM_HDL,u32Mp3FileHandle);
  CPPTEST_ASSERT_INTEGER_EQUAL(MSAPI_AUD_DVB_AAC,enCurrentDecSystem);

}
/* CPPTEST_TEST_CASE_END test_MApp_Music_Initial_enCurrentMusicType_LOAS */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_Stop */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Music_Stop(void) */
void TestSuite_mapp_music_test_MApp_Music_Stop()
{

  ST_FLAC_SEEK_TABLE stSeekTableTemp = {1,1,1};
  m_stFlacInfo.pstSeekTable  = &stSeekTableTemp ;

  /* Tested function call */
  MApp_Music_Stop();

  CPPTEST_ASSERT_PTR_EQUAL(NULL,m_stFlacInfo.pstSeekTable);
  CPPTEST_ASSERT_INTEGER_EQUAL(MP3_NORMAL_MODE,u8MusicFFFWMode);
  CPPTEST_ASSERT_INTEGER_EQUAL(MP3_STATUS_STOP,enMp3PlayStatus);
  CPPTEST_ASSERT_INTEGER_EQUAL(STATE_MUSIC_STANDBY,enMusicState);
  CPPTEST_ASSERT_INTEGER_EQUAL(FALSE,_bMusicRecording);
  CPPTEST_ASSERT_INTEGER_EQUAL(0,_u32MusicRecordLength);
  CPPTEST_ASSERT_INTEGER_EQUAL(0,_u32MusicRecordStartTime);
  CPPTEST_ASSERT_INTEGER_EQUAL(FALSE,stPCMParam.bIsConfig);

}
/* CPPTEST_TEST_CASE_END test_MApp_Music_Stop */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_OpenFile_enCurrentMusicType_MP3_FAIL */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_Initial(void) */
void TestSuite_mapp_music_test_MApp_Music_OpenFile_enCurrentMusicType_MP3_FAIL()
{

  ST_FLAC_SEEK_TABLE stSeekTableTemp = {1,1,1};
  m_stFlacInfo.pstSeekTable  = &stSeekTableTemp ;

  enCurrentMusicType  = EN_MUSIC_MP3;

  /* Tested function call */
  BOOLEAN _return  = MApp_Music_OpenFile();
  /* Post-condition check */
  CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
  CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _bM4aJustOpened ));
  CPPTEST_ASSERT_PTR_EQUAL(NULL,m_stFlacInfo.pstSeekTable);

}
/* CPPTEST_TEST_CASE_END test_MApp_Music_OpenFile_enCurrentMusicType_MP3_FAIL */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_OpenFile_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_OpenFile(void) */
void TestSuite_mapp_music_test_MApp_Music_OpenFile_TRUE()
{
    //test MP3
  {
    enCurrentMusicType  = EN_MUSIC_MP3;

    /* Tested function call */
    BOOLEAN _return  = MApp_Music_OpenFile();
    /* Post-condition check */
    CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
  }

  //tes AAC
  {
    enCurrentMusicType  = EN_MUSIC_AAC;

    /* Tested function call */
    BOOLEAN _return  = MApp_Music_OpenFile();
    /* Post-condition check */
    CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
  }

  //test FLAC
  {
    enCurrentMusicType  = EN_MUSIC_FLAC;
    /* Tested function call */
    BOOLEAN _return  = MApp_Music_OpenFile();
    /* Post-condition check */
    CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
  }

  //test WAV
  {
    enCurrentMusicType  = EN_MUSIC_WAV;
    /* Tested function call */
    BOOLEAN _return  = MApp_Music_OpenFile();
    /* Post-condition check */
    CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
  }

  //test PCM
  {
    enCurrentMusicType  = EN_MUSIC_PCM;

    /* Tested function call */
    BOOLEAN _return  = MApp_Music_OpenFile();
    /* Post-condition check */
    CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
  }

  //test LOAS
  {
    enCurrentMusicType  = EN_MUSIC_LOAS;

    /* Tested function call */
    BOOLEAN _return  = MApp_Music_OpenFile();
    /* Post-condition check */
    CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
  }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_OpenFile_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_SaveMp3_EraseFlash_FAIL */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_SaveMp3_EraseFlash(U32, U32) */
void TestSuite_mapp_music_test_MApp_SaveMp3_EraseFlash_FAIL()
{
  U32 _u32FlashStartAddr  = 0ul;
  U32 _u32DataSize  = 0;
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_SaveMp3_EraseFlash(_u32FlashStartAddr, _u32DataSize);
        /* Post-condition check */

        CPPTEST_ASSERT_INTEGER_EQUAL(0,_u32DataSize);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
    }

    {
      _u32DataSize  = 1ul;
        /* Tested function call */
        BOOLEAN _return  = MApp_SaveMp3_EraseFlash(_u32FlashStartAddr, _u32DataSize);
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(1,_u32DataSize);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_SaveMp3_EraseFlash_FAIL */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_SaveMp3_EraseFlash_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_SaveMp3_EraseFlash(U32, U32) */
void TestSuite_mapp_music_test_MApp_SaveMp3_EraseFlash_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FlashStartAddr) */ 
    U32 _u32FlashStartAddr  = 0ul;
    /* Initializing argument 2 (u32DataSize) */ 
    U32 _u32DataSize  = 1ul;
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_SaveMp3_EraseFlash(_u32FlashStartAddr, _u32DataSize);
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(1,_u32DataSize);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_SaveMp3_EraseFlash_TRUE */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_SaveMp3_WriteFlash_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_SaveMp3_WriteFlash(U32, U32, U32) */
void TestSuite_mapp_music_test_MApp_SaveMp3_WriteFlash_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32SrcAddr) */ 
    U32 _u32SrcAddr  = 0ul;
    /* Initializing argument 2 (u32FlashAddr) */ 
    U32 _u32FlashAddr  = 0ul;
    /* Initializing argument 3 (u32DataSize) */ 
    U32 _u32DataSize  = 1ul;

  /* Tested function call */
  BOOLEAN _return  = MApp_SaveMp3_WriteFlash(_u32SrcAddr, _u32FlashAddr, _u32DataSize);
  /* Post-condition check */
  CPPTEST_ASSERT_BOOL_EQUAL(TRUE,_return);

}
/* CPPTEST_TEST_CASE_END test_MApp_SaveMp3_WriteFlash_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_Input_enCurrentMusicType_MP3 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Music_Input(void) */
void TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusicType_MP3()
{

  enCurrentMusicType  = EN_MUSIC_MP3;

  /* Tested function call */
  MApp_Music_Input();
  /* Post-condition check */
  CPPTEST_ASSERT_INTEGER_EQUAL(STATE_MUSIC_WAIT_DECODE_DONE,  enMusicState);

}
/* CPPTEST_TEST_CASE_END test_MApp_Music_Input_enCurrentMusicType_MP3 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_Input_enCurrentMusic_AAC */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Music_Input(void) */
void TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusic_AAC()
{
  u32Mp3FileBytesLeft  = 0ul;
  enCurrentMusicType  = EN_MUSIC_AAC;

  {
    boxM4a.bM4aHeader  = 1;
    MApp_Music_Input();
    CPPTEST_ASSERT_INTEGER_EQUAL(STATE_MUSIC_WAIT_DECODE_DONE,  enMusicState);
  }

  {
    boxM4a.bM4aHeader  = 0;
    MApp_Music_Input();
    CPPTEST_ASSERT_INTEGER_EQUAL(STATE_MUSIC_WAIT_DECODE_DONE,  enMusicState);
  }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_Input_enCurrentMusic_AAC */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_Input_enCurrentMusicType_FLAC */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Music_Input(void) */
void TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusicType_FLAC()
{
  stMp3Info.u32MusicDataBytesLeft  = 0ul;
  enCurrentMusicType  = EN_MUSIC_FLAC;
  MApp_Music_Input();
  CPPTEST_ASSERT_INTEGER_EQUAL(STATE_MUSIC_WAIT_DECODE_DONE,  enMusicState);

}
/* CPPTEST_TEST_CASE_END test_MApp_Music_Input_enCurrentMusicType_FLAC */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_Input_enCurrentMusicType_WAV */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Music_Input(void) */
void TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusicType_WAV()
{
  stMp3Info.u32MusicDataBytesLeft  = 0ul;
  enCurrentMusicType  = EN_MUSIC_WAV;

  /* Tested function call */
  MApp_Music_Input();
  CPPTEST_ASSERT_INTEGER_EQUAL(STATE_MUSIC_WAIT_DECODE_DONE,  enMusicState);
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_Input_enCurrentMusicType_WAV */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_Input_enCurrentMusicType_PCM */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Music_Input(void) */
void TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusicType_PCM()
{
  stMp3Info.u32MusicDataBytesLeft  = 0ul;
  enCurrentMusicType  = EN_MUSIC_PCM;

  MApp_Music_Input();
  CPPTEST_ASSERT_INTEGER_EQUAL(STATE_MUSIC_WAIT_DECODE_DONE,  enMusicState);
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_Input_enCurrentMusicType_PCM */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_Input_enCurrentMusicType_LOAS */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Music_Input(void) */
void TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusicType_LOAS()
{

  enCurrentMusicType  = EN_MUSIC_LOAS;

  MApp_Music_Input();
  CPPTEST_ASSERT_INTEGER_EQUAL(0, stMp3Info.u32MusicDataBytesLeft);
  CPPTEST_ASSERT_INTEGER_EQUAL(STATE_MUSIC_WAIT_DECODE_DONE,  enMusicState);

}
/* CPPTEST_TEST_CASE_END test_MApp_Music_Input_enCurrentMusicType_LOAS */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_LoadDspCodec */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_LoadDspCodec(En_DVB_decSystemType) */
void TestSuite_mapp_music_test_MApp_Music_LoadDspCodec()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enDecSystem) */ 
    En_DVB_decSystemType _enDecSystem  = MSAPI_AUD_DVB_INVALID;

   bReloadDsp  = 0;
  /* Tested function call */
  BOOLEAN _return  = MApp_Music_LoadDspCodec(_enDecSystem);

  CPPTEST_ASSERT_BOOL_EQUAL(TRUE,_return);
  CPPTEST_ASSERT_BOOL_EQUAL(TRUE,bReloadDsp);
  CPPTEST_ASSERT_INTEGER_EQUAL(_enDecSystem, enCurrentDecSystem);


}
/* CPPTEST_TEST_CASE_END test_MApp_Music_LoadDspCodec */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_Music_ScanDigit */
/* CPPTEST_TEST_CASE_CONTEXT S16 _MApp_Music_ScanDigit(U8 *, U32 *, BOOLEAN) */
void TestSuite_mapp_music_test__MApp_Music_ScanDigit()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Data) */ 
  U8 u8DataTemp[8] ={'1','2','3','4','5','6','7','8'};
    U8 * _pu8Data  = &u8DataTemp ;
    /* Initializing argument 2 (pu32Val) */
    U32 u32ValTemp = 0;
    U32 * _pu32Val  = &u32ValTemp ;
    /* Initializing argument 3 (bIsUnicode) */ 
    U8 _bIsUnicode  = 0;

  /* Tested function call */
  S16 _return  = _MApp_Music_ScanDigit(_pu8Data, _pu32Val, _bIsUnicode);
  CPPTEST_ASSERT_INTEGER_EQUAL(6, _return);

}
/* CPPTEST_TEST_CASE_END test__MApp_Music_ScanDigit */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_Music_ScanfLrCTime_case3 */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_Music_ScanfLrCTime(U8 *, U32 *, U32 *, U32 *, U32 *, BOOLEAN) */
void TestSuite_mapp_music_test__MApp_Music_ScanfLrCTime_case3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Data) */
  U8 u8DataTemp[12]={'0','1','2',':','4','5','.','7','8',']','10','11'};
    U8 * _pu8Data  = &u8DataTemp ;
    /* Initializing argument 2 (pu32Min) */
    U32 u32MinTemp = 0;
    U32 * _pu32Min  = &u32MinTemp ;
    /* Initializing argument 3 (pu32Sec) */
    U32 u32SecTemp = 0;
    U32 * _pu32Sec  = &u32SecTemp ;
    /* Initializing argument 4 (pu32Ms) */
    U32 u32MsTemp = 0;
    U32 * _pu32Ms  = &u32MsTemp ;
    /* Initializing argument 5 (pu32MsLen) */
    U32 u32MsLenTemp = 0;
    U32 * _pu32MsLen  = &u32MsLenTemp ;
    /* Initializing argument 6 (bIsUnicode) */ 
    U8 _bIsUnicode  = 1;
    {
        /* Tested function call */
        U8 _return  = _MApp_Music_ScanfLrCTime(_pu8Data, _pu32Min, _pu32Sec, _pu32Ms, _pu32MsLen, _bIsUnicode);
        CPPTEST_ASSERT_INTEGER_EQUAL(3, _return);
    }

    u8DataTemp[9] = '9';
    {
    U8 _return  = _MApp_Music_ScanfLrCTime(_pu8Data, _pu32Min, _pu32Sec, _pu32Ms, _pu32MsLen, _bIsUnicode);
    CPPTEST_ASSERT_INTEGER_EQUAL(0, _return);
    }

    u8DataTemp[6] = '6';
    {
    U8 _return  = _MApp_Music_ScanfLrCTime(_pu8Data, _pu32Min, _pu32Sec, _pu32Ms, _pu32MsLen, _bIsUnicode);
    CPPTEST_ASSERT_INTEGER_EQUAL(2, _return);
    }
    _bIsUnicode = 0;
    {
    U8 _return  = _MApp_Music_ScanfLrCTime(_pu8Data, _pu32Min, _pu32Sec, _pu32Ms, _pu32MsLen, _bIsUnicode);
    CPPTEST_ASSERT_INTEGER_EQUAL(0, _return);
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_Music_ScanfLrCTime_case3 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_LRC_Lyrics_Parser_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_LRC_Lyrics_Parser(U32) */
void TestSuite_mapp_music_test_MApp_Music_LRC_Lyrics_Parser_case1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FileSize) */ 
    U32 _u32FileSize  = 2000;
    /* Initializing global variable u16LyricTagCount */ 
    {
         u16LyricTagCount  = 3;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_Music_LRC_Lyrics_Parser(_u32FileSize);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE,_return);

    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_LRC_Lyrics_Parser_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_Play */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Music_Play(void) */
void TestSuite_mapp_music_test_MApp_Music_Play()
{
    //test STOP
    {
    enMp3PlayStatus  = MP3_STATUS_STOP;
    MApp_Music_Play();

    CPPTEST_ASSERT_INTEGER_EQUAL(STATE_MUSIC_INIT,enMusicState);
    CPPTEST_ASSERT_INTEGER_EQUAL(MP3_STATUS_PLAYING,enMp3PlayStatus);
    }

    //test PLAY
    {
    enMp3PlayStatus  = MP3_STATUS_PLAYING;
    MApp_Music_Play();

    CPPTEST_ASSERT_INTEGER_EQUAL(STATE_MUSIC_WAIT,enMusicState);
    CPPTEST_ASSERT_INTEGER_EQUAL(MP3_STATUS_STOP,enMp3PlayStatus);
    }

}
/* CPPTEST_TEST_CASE_END test_MApp_Music_Play */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_SearchFirstFrame_case1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_Music_SearchFirstFrame(U32, U32) */
void TestSuite_mapp_music_test_MApp_Music_SearchFirstFrame_case1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FileHandle) */ 
    U32 _u32FileHandle  = 0ul;
    /* Initializing argument 2 (u32ID3v2Offset) */ 
    U32 _u32ID3v2Offset  = 0ul;
    {
        /* Tested function call */
        U32 _return  = MApp_Music_SearchFirstFrame(_u32FileHandle, _u32ID3v2Offset);
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(MUSIC_CANNOT_FIND_1ST_FRAME, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_SearchFirstFrame_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_CalculateMP3CBRDuration */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_Music_CalculateMP3CBRDuration(ST_MP3_INFO *, U32) */
void TestSuite_mapp_music_test_MApp_Music_CalculateMP3CBRDuration()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pMp3Info) */ 
    ST_MP3_INFO _pMp3Info_14 ;

    _pMp3Info_14.u32FileSize = 0;
    ST_MP3_INFO * _pMp3Info  = & _pMp3Info_14;
    /* Initializing argument 2 (u32FileHandle) */ 
    U32 _u32FileHandle  = 0ul;
    {
        /* Tested function call */
        U32 _return  = MApp_Music_CalculateMP3CBRDuration(_pMp3Info, _u32FileHandle);
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_CalculateMP3CBRDuration */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_ParseFlac_StreamInfo */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_ParseFlac_StreamInfo(U32) */
void TestSuite_mapp_music_test_MApp_Music_ParseFlac_StreamInfo()
{

    U32 _u32Offset  = 0ul;

    //test true
    {
    u32Mp3FileHandle  = 0ul;
        BOOLEAN _return  = MApp_Music_ParseFlac_StreamInfo(_u32Offset);

        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));

    }

    //test false
    {
    u32Mp3FileHandle  = INVALID_DATA_STREAM_HDL;
    BOOLEAN _return  = MApp_Music_ParseFlac_StreamInfo(_u32Offset);

    CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_ParseFlac_StreamInfo */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_ParseFlac_SeekTable_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_ParseFlac_SeekTable(U32, U32) */
void TestSuite_mapp_music_test_MApp_Music_ParseFlac_SeekTable_case1()
{


    U32 _u32Offset  = 0ul;
    U32 _u32TableLen  = 0ul;

    //test true
    {
    ST_FLAC_INFO stFlacInfoTemp;
    m_stFlacInfo.pstSeekTable = &stFlacInfoTemp;
    u32Mp3FileHandle  = 0ul;

    BOOLEAN _return  = MApp_Music_ParseFlac_SeekTable(_u32Offset, _u32TableLen);
    CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }

    //test false
    {
    ST_FLAC_INFO stFlacInfoTemp;
    m_stFlacInfo.pstSeekTable = &stFlacInfoTemp;
    u32Mp3FileHandle = INVALID_DATA_STREAM_HDL;
    BOOLEAN _return  = MApp_Music_ParseFlac_SeekTable(_u32Offset, _u32TableLen);
    CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
    }

    //test true
    {
    m_stFlacInfo.pstSeekTable = NULL;
    _u32TableLen = 36;
    u32Mp3FileHandle  = 0ul;

    BOOLEAN _return  = MApp_Music_ParseFlac_SeekTable(_u32Offset, _u32TableLen);
    CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
   }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_ParseFlac_SeekTable_case1 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_Music_Flac_CollectInfo_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_Music_Flac_CollectInfo(void) */
void TestSuite_mapp_music_test__MApp_Music_Flac_CollectInfo_case1()
{
   //test length < 42

  ST_FLAC_INFO stFlacInfoTemp;
  m_stFlacInfo.pstSeekTable  = &stFlacInfoTemp;

  BOOLEAN _return  = _MApp_Music_Flac_CollectInfo();
  CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
}
/* CPPTEST_TEST_CASE_END test__MApp_Music_Flac_CollectInfo_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_CollectInfo_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_CollectInfo(ST_MP3_INFO *) */
void TestSuite_mapp_music_test_MApp_Music_CollectInfo_case1()
{

  ST_MP3_INFO Mp3InfoTemp;
    ST_MP3_INFO * _pMp3Info  = &Mp3InfoTemp ;

    BOOLEAN _return  = MApp_Music_CollectInfo(_pMp3Info);

  CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
  CPPTEST_ASSERT_INTEGER_EQUAL(INVALID_DATA_STREAM_HDL,u32Mp3FileHandle);
  CPPTEST_ASSERT_INTEGER_EQUAL(MP3_ID3_V1_LEN,_pMp3Info->u16ID3TagV1Size);
  CPPTEST_ASSERT_BOOL_EQUAL(TRUE,_pMp3Info->bID3TagV2);
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_CollectInfo_case1 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_Music_Flac_DataInput_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_Music_Flac_DataInput(U32, U32) */
void TestSuite_mapp_music_test__MApp_Music_Flac_DataInput_case1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (dwReqAddress) */ 
    U32 _dwReqAddress  = 0ul;
    /* Initializing argument 2 (u32ReqBytes) */ 
    U32 _u32ReqBytes  = 4ul;

    //test stMp3Info.u32MusicDataBytesLeft>= u32ReqBytes
    {
      stMp3Info.u32MusicDataBytesLeft = 4;
        BOOLEAN _return  = _MApp_Music_Flac_DataInput(_dwReqAddress, _u32ReqBytes);

        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
        CPPTEST_ASSERT_INTEGER_EQUAL(0, stMp3Info.u32MusicDataBytesLeft);
    }


    {
        stMp3Info.u32MusicDataBytesLeft = 3;
        BOOLEAN _return  = _MApp_Music_Flac_DataInput(_dwReqAddress, _u32ReqBytes);

        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
        CPPTEST_ASSERT_INTEGER_EQUAL(0, stMp3Info.u32MusicDataBytesLeft);
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_Music_Flac_DataInput_case1 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_Music_Wav_CollectInfo_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_Music_Wav_CollectInfo(void) */
void TestSuite_mapp_music_test__MApp_Music_Wav_CollectInfo_case1()
{
    /* Pre-condition initialization */

  stWavChunk.u32AvgBytesPerSec = 10;
  stWavChunk.u32SamplesPerSec = 9000;
    stWavChunk.u16FormatTag = (U16)WAVE_FORMAT_PCM;
    stWavChunk.u32HeaderSize = 0;
    stWavChunk.bIsDTS = 1;

    //test normal sample rate
    {
        BOOLEAN _return  = _MApp_Music_Wav_CollectInfo();

        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, stWavChunk.bIsDTS);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }

    stWavChunk.u32HeaderSize = 0;
    stWavChunk.u32SamplesPerSec = 4000;

    //test unsupport sample rate
    {
           BOOLEAN _return  = _MApp_Music_Wav_CollectInfo();

           CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
    }

}
/* CPPTEST_TEST_CASE_END test__MApp_Music_Wav_CollectInfo_case1 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_Music_Wav_DataInput */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_Music_Wav_DataInput(U32, U32) */
void TestSuite_mapp_music_test__MApp_Music_Wav_DataInput()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (dwReqAddress) */ 
    U32 _dwReqAddress  = 0ul;
    /* Initializing argument 2 (u32ReqBytes) */ 
    U32 _u32ReqBytes  = 4ul;
    /* Initializing global variable stMp3Info */
    {
      stMp3Info.u32MusicDataBytesLeft = 4;
        BOOLEAN _return  = _MApp_Music_Wav_DataInput(_dwReqAddress, _u32ReqBytes);

        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
        CPPTEST_ASSERT_INTEGER_EQUAL(0, stMp3Info.u32MusicDataBytesLeft);
    }
    {
      stMp3Info.u32MusicDataBytesLeft = 3;
        BOOLEAN _return  = _MApp_Music_Wav_DataInput(_dwReqAddress, _u32ReqBytes);

        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
        CPPTEST_ASSERT_INTEGER_EQUAL(0, stMp3Info.u32MusicDataBytesLeft);
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_Music_Wav_DataInput */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_Music_PCM_CollectInfo_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_Music_PCM_CollectInfo(void) */
void TestSuite_mapp_music_test__MApp_Music_PCM_CollectInfo_case1()
{
    /* Pre-condition initialization */
    /* Initializing global variable stPCMParam */ 
    {
         stPCMParam.u16FormatTag  = (U16)WAVE_FORMAT_PCM;
         stPCMParam.u16BitsPerSample  = 16u;
         stPCMParam.bIsConfig  = 1;
         stPCMParam.u32AvgBytesPerSec =24;
    }

    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_Music_PCM_CollectInfo();
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
        CPPTEST_ASSERT_INTEGER_EQUAL(INVALID_DATA_STREAM_HDL,u32Mp3FileHandle);
        CPPTEST_ASSERT_INTEGER_EQUAL(0,stMp3Info.u32Duration);
        CPPTEST_ASSERT_INTEGER_EQUAL(0,stMp3Info.u16BitRate);
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_Music_PCM_CollectInfo_case1 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_Music_PCM_DataInput */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_Music_PCM_DataInput(U32, U32) */
void TestSuite_mapp_music_test__MApp_Music_PCM_DataInput()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (dwReqAddress) */ 
    U32 _dwReqAddress  = 0ul;
    /* Initializing argument 2 (u32ReqBytes) */ 
    U32 _u32ReqBytes  = 4ul;

    /* Initializing global variable stMp3Info */
    {
         stMp3Info.u32MusicDataBytesLeft  = 4ul;
        BOOLEAN _return  = _MApp_Music_PCM_DataInput(_dwReqAddress, _u32ReqBytes);

        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
        CPPTEST_ASSERT_INTEGER_EQUAL(0, stMp3Info.u32MusicDataBytesLeft);
    }
    /* Initializing global variable stMp3Info */ 
    {
        stMp3Info.u32MusicDataBytesLeft  = 3ul;
        BOOLEAN _return  = _MApp_Music_PCM_DataInput(_dwReqAddress, _u32ReqBytes);

        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
        CPPTEST_ASSERT_INTEGER_EQUAL(0, stMp3Info.u32MusicDataBytesLeft);
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_Music_PCM_DataInput */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_UpdatePlayTime_case1 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Music_UpdatePlayTime(void) */
void TestSuite_mapp_music_test_MApp_Music_UpdatePlayTime_case1()
{
    /* Initializing global variable u32Mp3FileHandle */
    {
         u32Mp3FileHandle  = INVALID_DATA_STREAM_HDL;

        /* Tested function call */
        MApp_Music_UpdatePlayTime();
        CPPTEST_ASSERT_INTEGER_EQUAL(0,stMp3Info.u32CurrentPlayTime);

        /* Post-condition check */
    }

    {
         u32Mp3FileHandle  = 0;

      enMp3PlayStatus = MP3_STATUS_PLAYING;

       stMp3Info.u32CurrentPlayTime = 1;
         stMp3Info.enVersion  = EN_MP3_VERSION_2_5;
         stMp3Info.enLayer  = EN_MP3_LAYER_1;
         stMp3Info.u32Duration = 0;
         stMp3Info.u32ID3TagV2Size = 3;

        MApp_Music_UpdatePlayTime();
        CPPTEST_ASSERT_INTEGER_EQUAL(0,stMp3Info.u32CurrentPlayTime);
    }


    {
       stMp3Info.u32CurrentPlayTime = 1;
         stMp3Info.enVersion  = EN_MP3_VERSION_2_5;
         stMp3Info.enLayer  = EN_MP3_LAYER_1;
         stMp3Info.u32Duration = 0;
         stMp3Info.u32ID3TagV2Size = 0;

        MApp_Music_UpdatePlayTime();
        CPPTEST_ASSERT_INTEGER_EQUAL(0,stMp3Info.u32CurrentPlayTime);
    }


    {
      enMp3PlayStatus = MP3_STATUS_PAUSE;
      /* Tested function call */
      MApp_Music_UpdatePlayTime();
      CPPTEST_ASSERT_INTEGER_EQUAL(0,stMp3Info.u32CurrentPlayTime);

      enMp3PlayStatus = MP3_STATUS_PLAYING;
      stMp3Info.u32CurrentPlayTime = 0;
      /* Tested function call */
      MApp_Music_UpdatePlayTime();
      CPPTEST_ASSERT_INTEGER_EQUAL(0,stMp3Info.u32CurrentPlayTime);
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_UpdatePlayTime_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_GetTotalTime_case1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_Music_GetTotalTime(void) */
void TestSuite_mapp_music_test_MApp_Music_GetTotalTime_case1()
{
  //test MP3
    {
       enCurrentMusicType = EN_MUSIC_MP3;
       u32Mp3FileHandle = INVALID_DATA_STREAM_HDL;
         enMusicState  = STATE_MUSIC_INPUT;
         /* Tested function call */
         U32 _return  = MApp_Music_GetTotalTime();
         CPPTEST_ASSERT_INTEGER_EQUAL(0,_return);
    }

    //test AAC
    {
       enCurrentMusicType = EN_MUSIC_AAC;
       u32Mp3FileHandle = INVALID_DATA_STREAM_HDL;
         enMusicState  = STATE_MUSIC_INPUT;
         /* Tested function call */
         U32 _return  = MApp_Music_GetTotalTime();
         CPPTEST_ASSERT_INTEGER_EQUAL(0,_return);
    }

    //test wav
    {
       enCurrentMusicType = EN_MUSIC_WAV;
         /* Tested function call */
         U32 _return  = MApp_Music_GetTotalTime();
         CPPTEST_ASSERT_INTEGER_EQUAL(stMp3Info.u32Duration,_return);
    }

    //test PCM
    {
       enCurrentMusicType = EN_MUSIC_PCM;
         /* Tested function call */
         U32 _return  = MApp_Music_GetTotalTime();
         CPPTEST_ASSERT_INTEGER_EQUAL(stMp3Info.u32Duration,_return);
    }
    //test LOAS
    {
       enCurrentMusicType = EN_MUSIC_LOAS;
         /* Tested function call */
         U32 _return  = MApp_Music_GetTotalTime();
         CPPTEST_ASSERT_INTEGER_EQUAL(stMp3Info.u32Duration,_return);
    }
    //test FLAC
    {
       enCurrentMusicType = EN_MUSIC_FLAC;
         /* Tested function call */
         U32 _return  = MApp_Music_GetTotalTime();
         CPPTEST_ASSERT_INTEGER_EQUAL(stMp3Info.u32Duration,_return);
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_GetTotalTime_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_GetCurrentTime_case1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_Music_GetCurrentTime(void) */
void TestSuite_mapp_music_test_MApp_Music_GetCurrentTime_case1()
{
  //test MP3
  {
      enMusicState = STATE_MUSIC_INPUT;
      enCurrentMusicType = EN_MUSIC_MP3;
        /* Tested function call */
        U32 _return  = MApp_Music_GetCurrentTime();
        CPPTEST_ASSERT_INTEGER_EQUAL(0,_return);
    }

  //test AAC
  {
      enMusicState = STATE_MUSIC_INPUT;
      enCurrentMusicType = EN_MUSIC_AAC;
      u8MusicFFFWMode = MP3_NORMAL_MODE;
        /* Tested function call */
        U32 _return  = MApp_Music_GetCurrentTime();
        CPPTEST_ASSERT_INTEGER_EQUAL(0,_return);
    }

  //test WAV
  {
      enMusicState = STATE_MUSIC_INPUT;
      enCurrentMusicType = EN_MUSIC_WAV;
        /* Tested function call */
        U32 _return  = MApp_Music_GetCurrentTime();
        CPPTEST_ASSERT_INTEGER_EQUAL(0,_return);
    }

  //test PCM
  {
      enMusicState = STATE_MUSIC_INPUT;
      enCurrentMusicType = EN_MUSIC_PCM;
        /* Tested function call */
        U32 _return  = MApp_Music_GetCurrentTime();
        CPPTEST_ASSERT_INTEGER_EQUAL(0,_return);
    }

  //test LOAS
  {
      enMusicState = STATE_MUSIC_INPUT;
      enCurrentMusicType = EN_MUSIC_LOAS;
        /* Tested function call */
        U32 _return  = MApp_Music_GetCurrentTime();
        CPPTEST_ASSERT_INTEGER_EQUAL(0,_return);
    }

  //test FLAC
  {
      enMusicState = STATE_MUSIC_INPUT;
      enCurrentMusicType = EN_MUSIC_FLAC;
        /* Tested function call */
        U32 _return  = MApp_Music_GetCurrentTime();
        CPPTEST_ASSERT_INTEGER_EQUAL(0,_return);
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_GetCurrentTime_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_GetCurrentTime_case2 */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_Music_GetCurrentTime(void) */
void TestSuite_mapp_music_test_MApp_Music_GetCurrentTime_case2()
{
  //test M4A
  {
      enMusicState = STATE_MUSIC_INPUT;
      enCurrentMusicType = EN_MUSIC_AAC;
      boxM4a.bFoundstsz = 1;
      boxM4a.u32stscSize = 1;
      boxM4a.bFoundstsc = 1;
      _bM4aEnableFFFB = 0;
      _bM4aTimerbyDSP = 1;
        /* Tested function call */
        U32 _return  = MApp_Music_GetCurrentTime();
        CPPTEST_ASSERT_INTEGER_EQUAL(0,_return);
    }

  //test M4A
  {
      enMusicState = STATE_MUSIC_INPUT;
      enCurrentMusicType = EN_MUSIC_AAC;
      boxM4a.bFoundstsz = 0;
      boxM4a.u32stscSize = 0;
      boxM4a.bFoundstsc = 0;
      _bM4aEnableFFFB = 1;
      _bM4aTimerbyDSP = 0;
        /* Tested function call */
        U32 _return  = MApp_Music_GetCurrentTime();
        CPPTEST_ASSERT_INTEGER_EQUAL(0,_return);
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_GetCurrentTime_case2 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_GetCurrentTimeMs */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_Music_GetCurrentTimeMs(void) */
void TestSuite_mapp_music_test_MApp_Music_GetCurrentTimeMs()
{
  //test MP3
  {
    enCurrentMusicType = EN_MUSIC_MP3;
        /* Tested function call */
        U32 _return  = MApp_Music_GetCurrentTimeMs();
        CPPTEST_ASSERT_INTEGER_EQUAL(0,_return);
    }

  //test else
  {
      enCurrentMusicType = EN_MUSIC_AAC;
      /* Tested function call */
      U32 _return  = MApp_Music_GetCurrentTimeMs();
      CPPTEST_ASSERT_INTEGER_EQUAL(0,_return);
  }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_GetCurrentTimeMs */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_ProcessFfRew_case4 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Music_ProcessFfRew(void) */
void TestSuite_mapp_music_test_MApp_Music_ProcessFfRew_case4()
{
  //test MP3 FF
    /* Initializing global variable enCurrentMusicType */
    {
         enCurrentMusicType  = EN_MUSIC_MP3;
         stMp3Info.u32Duration = 30;
         stMp3Info.u32FileSize = 100;
         stMp3Info.u16BitRate = 128;
         u8MusicFFFWMode = MP3_FF_Mode;
         /* Tested function call */
         MApp_Music_ProcessFfRew();
         CPPTEST_ASSERT_INTEGER_EQUAL(0,stMp3Info.u32PlayTimer);

    }

  //test MP3 FF case2
    /* Initializing global variable enCurrentMusicType */
    {
         enCurrentMusicType  = EN_MUSIC_MP3;
         stMp3Info.u32Duration = 30;
         stMp3Info.u32FileSize = 100;
         stMp3Info.u16BitRate = 128;
         u8MusicFFFWMode = MP3_FF_Mode;
         stMp3Info.u8Flag = MP3_FLAG_VBR_XING;
         stMp3Info.u16TOCLength = 5;
         /* Tested function call */
         MApp_Music_ProcessFfRew();
         CPPTEST_ASSERT_INTEGER_EQUAL(0,stMp3Info.u32PlayTimer);

    }

  //test MP3 FB case2
    /* Initializing global variable enCurrentMusicType */
    {
         enCurrentMusicType  = EN_MUSIC_MP3;
         stMp3Info.u32Duration = 30;
         stMp3Info.u32FileSize = 100;
         stMp3Info.u16BitRate = 128;
         u8MusicFFFWMode = MP3_FW_Mode;
         stMp3Info.u8Flag = MP3_FLAG_VBR_XING;
         stMp3Info.u16TOCLength = 5;
         /* Tested function call */
         MApp_Music_ProcessFfRew();
         CPPTEST_ASSERT_INTEGER_EQUAL(0,stMp3Info.u32PlayTimer);
    }

    //test AAC FF
    /* Initializing global variable enCurrentMusicType */
    {
         enCurrentMusicType  = EN_MUSIC_AAC;
         boxM4a.bFoundmdat = 0;
         u8MusicFFFWMode = MP3_FF_Mode;
         /* Tested function call */
         MApp_Music_ProcessFfRew();

         CPPTEST_ASSERT_INTEGER_EQUAL(MP3_NORMAL_MODE,u8MusicFFFWMode);
         CPPTEST_ASSERT_INTEGER_EQUAL(STATE_MUSIC_WAIT,enMusicState);
    }

    //test AAC FB
    /* Initializing global variable enCurrentMusicType */
    {
         enCurrentMusicType  = EN_MUSIC_AAC;
         boxM4a.bFoundmdat = 0;
         u8MusicFFFWMode = MP3_FW_Mode;
         stMp3Info.u32CurrentPlayTime = 3;
         /* Tested function call */
         MApp_Music_ProcessFfRew();
         CPPTEST_ASSERT_INTEGER_EQUAL(0,stMp3Info.u32PlayTimer);

    }

    //test WAV FF case1
    /* Initializing global variable enCurrentMusicType */
    {
         enCurrentMusicType  = EN_MUSIC_WAV;
         stWavChunk.u32HeaderSize = 10;
         stMp3Info.u32Duration = 20;
         stMp3Info.u32CurrentPlayTime = 30000;
         u8MusicFFFWMode = MP3_FF_Mode;
         /* Tested function call */
         MApp_Music_ProcessFfRew();
         CPPTEST_ASSERT_INTEGER_EQUAL(20000,stMp3Info.u32CurrentPlayTime);

    }

    //test WAV FF case2
    /* Initializing global variable enCurrentMusicType */
    {
        enCurrentMusicType  = EN_MUSIC_WAV;
        stWavChunk.u32HeaderSize = 10;
        stMp3Info.u32Duration = 20;
        stMp3Info.u32CurrentPlayTime = 30;
        u8MusicFFFWMode = MP3_FF_Mode;
        /* Tested function call */
        MApp_Music_ProcessFfRew();
        CPPTEST_ASSERT_INTEGER_EQUAL(2030,stMp3Info.u32CurrentPlayTime);
    }

    //test WAV FB case1
    /* Initializing global variable enCurrentMusicType */
    {
         enCurrentMusicType  = EN_MUSIC_WAV;
         stWavChunk.u32HeaderSize = 10;
         stMp3Info.u32Duration = 20;
         stMp3Info.u32CurrentPlayTime = 30;
         u8MusicFFFWMode = MP3_FW_Mode;
         stWavChunk.u16FormatTag = (U16)WAVE_FORMAT_M_ADPCM;
         stWavChunk.u16BlockSize = 2;
         /* Tested function call */
         MApp_Music_ProcessFfRew();
         CPPTEST_ASSERT_INTEGER_EQUAL(0,stMp3Info.u32CurrentPlayTime);
    }

    //test WAV FB case2
    /* Initializing global variable enCurrentMusicType */
    {
        enCurrentMusicType  = EN_MUSIC_WAV;
        stWavChunk.u32HeaderSize = 10;
        stMp3Info.u32Duration = 20;
        stMp3Info.u32CurrentPlayTime = 30000;
        u8MusicFFFWMode = MP3_FW_Mode;
        stWavChunk.u16FormatTag = (U16)WAVE_FORMAT_M_ADPCM;
        stWavChunk.u16BlockSize = 2;
        /* Tested function call */
        MApp_Music_ProcessFfRew();
        CPPTEST_ASSERT_INTEGER_EQUAL(28000,stMp3Info.u32CurrentPlayTime);
    }

    //test PCM FF case1
    /* Initializing global variable enCurrentMusicType */
    {
         enCurrentMusicType  = EN_MUSIC_PCM;
         stMp3Info.u32Duration = 20;
         stMp3Info.u32CurrentPlayTime = 30000;
         u8MusicFFFWMode = MP3_FF_Mode;
         /* Tested function call */
         MApp_Music_ProcessFfRew();
         CPPTEST_ASSERT_INTEGER_EQUAL(stMp3Info.u32Duration * 1000,stMp3Info.u32CurrentPlayTime);
    }

    //test PCM FF case2
    /* Initializing global variable enCurrentMusicType */
    {
        enCurrentMusicType  = EN_MUSIC_PCM;
        stMp3Info.u32Duration = 20;
        stMp3Info.u32CurrentPlayTime = 30;
        u8MusicFFFWMode = MP3_FF_Mode;
        /* Tested function call */
        MApp_Music_ProcessFfRew();
        CPPTEST_ASSERT_INTEGER_EQUAL(2030,stMp3Info.u32CurrentPlayTime);
    }

    //test PCM FB case1
    /* Initializing global variable enCurrentMusicType */
    {
         enCurrentMusicType  =EN_MUSIC_PCM;
         stMp3Info.u32Duration = 20;
         stMp3Info.u32CurrentPlayTime = 30;
         u8MusicFFFWMode = MP3_FW_Mode;
         /* Tested function call */
         MApp_Music_ProcessFfRew();
         CPPTEST_ASSERT_INTEGER_EQUAL(0,stMp3Info.u32CurrentPlayTime);
    }

    //test PCM FB case2
    /* Initializing global variable enCurrentMusicType */
    {
        enCurrentMusicType  = EN_MUSIC_PCM;
        stMp3Info.u32Duration = 20;
        stMp3Info.u32CurrentPlayTime = 30000;
        u8MusicFFFWMode = MP3_FW_Mode;
        /* Tested function call */
        MApp_Music_ProcessFfRew();
        CPPTEST_ASSERT_INTEGER_EQUAL(28000,stMp3Info.u32CurrentPlayTime);
    }

    //test FLAC FF case1
    /* Initializing global variable enCurrentMusicType */
    {
         enCurrentMusicType  = EN_MUSIC_FLAC;
         stMp3Info.u32Duration = 20;
         stMp3Info.u32CurrentPlayTime = 30000;
         m_stFlacInfo.u32Duration = 20;
         u8MusicFFFWMode = MP3_FF_Mode;
         /* Tested function call */
         MApp_Music_ProcessFfRew();
         CPPTEST_ASSERT_INTEGER_EQUAL(20000,stMp3Info.u32CurrentPlayTime);
    }

    //test FLAC FF case2
    /* Initializing global variable enCurrentMusicType */
    {
        enCurrentMusicType  = EN_MUSIC_FLAC;
        stMp3Info.u32Duration = 20;
        m_stFlacInfo.u32Duration = 20;
        stMp3Info.u32CurrentPlayTime = 30;
        u8MusicFFFWMode = MP3_FF_Mode;
        /* Tested function call */
        MApp_Music_ProcessFfRew();
        CPPTEST_ASSERT_INTEGER_EQUAL(2030,stMp3Info.u32CurrentPlayTime);
    }

    //test FLAC FB case1
    /* Initializing global variable enCurrentMusicType */
    {
         enCurrentMusicType  =EN_MUSIC_FLAC;
         stMp3Info.u32Duration = 20;
         m_stFlacInfo.u32Duration = 20;
         stMp3Info.u32CurrentPlayTime = 30;
         u8MusicFFFWMode = MP3_FW_Mode;
         /* Tested function call */
         MApp_Music_ProcessFfRew();
         CPPTEST_ASSERT_INTEGER_EQUAL(0,stMp3Info.u32CurrentPlayTime);
    }

    //test FLAC FB case2
    /* Initializing global variable enCurrentMusicType */
    {
        enCurrentMusicType  = EN_MUSIC_FLAC;
        stMp3Info.u32Duration = 20;
        m_stFlacInfo.u32Duration = 20;
        stMp3Info.u32CurrentPlayTime = 30000;
        u8MusicFFFWMode = MP3_FW_Mode;
        /* Tested function call */
        MApp_Music_ProcessFfRew();
        CPPTEST_ASSERT_INTEGER_EQUAL(28000,stMp3Info.u32CurrentPlayTime);
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_ProcessFfRew_case4 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_ProcessFfRew_case5 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Music_ProcessFfRew(void) */
void TestSuite_mapp_music_test_MApp_Music_ProcessFfRew_case5()
{
    //test M4A FF case1
    /* Initializing global variable enCurrentMusicType */
    {
         enCurrentMusicType  = EN_MUSIC_AAC;
         boxM4a.bFoundmdat = 1;
         _bM4aEnableFFFB = 1;
         boxM4a.bFoundstsz = 1;
         boxM4a.bFoundstsc = 1;
         boxM4a.u32stscSize = 2;
         stMp3Info.u32CurrentPlayTime = 30000;
         stMp3Info.u32Duration = 20;

         u8MusicFFFWMode = MP3_FF_Mode;
         /* Tested function call */
         MApp_Music_ProcessFfRew();
         CPPTEST_ASSERT_INTEGER_EQUAL(20000,stMp3Info.u32CurrentPlayTime);
    }

    //test M4A FF case2
    /* Initializing global variable enCurrentMusicType */
    {
         enCurrentMusicType  = EN_MUSIC_AAC;
         boxM4a.bFoundmdat = 1;
         _bM4aEnableFFFB = 1;
         boxM4a.bFoundstsz = 0;
         boxM4a.bFoundstsc = 1;
         boxM4a.u32stscSize = 2;
         _u32M4aCurrentFrameIndex =3;
         enMp3PlayStatus = MP3_STATUS_PLAYING;
         stMp3Info.u32CurrentPlayTime = 30;
         stMp3Info.u32Duration = 20;

         u8MusicFFFWMode = MP3_FF_Mode;
         /* Tested function call */
         MApp_Music_ProcessFfRew();
         CPPTEST_ASSERT_INTEGER_EQUAL(30,stMp3Info.u32CurrentPlayTime);
    }

    //test M4A FB case1
    /* Initializing global variable enCurrentMusicType */
    {
         enCurrentMusicType  = EN_MUSIC_AAC;
         boxM4a.bFoundmdat = 1;
         _bM4aEnableFFFB = 1;
         boxM4a.bFoundstsz = 1;
         boxM4a.bFoundstsc = 1;
         boxM4a.u32stscSize = 2;
         u8MusicFFFWMode = MP3_FW_Mode;
         stMp3Info.u32CurrentPlayTime = 30;
         stMp3Info.u32Duration = 20;
         /* Tested function call */
         MApp_Music_ProcessFfRew();
         CPPTEST_ASSERT_INTEGER_EQUAL(0,stMp3Info.u32CurrentPlayTime);
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_ProcessFfRew_case5 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_TimeOutCheck_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_TimeOutCheck(void) */
void TestSuite_mapp_music_test_MApp_Music_TimeOutCheck_case1()
{
  u32TimeoutCheck_TimeMarker  = 0ul;
  u32TimeoutCheck_PreFilePosition  = 0ul;
  enTimeoutCheck_Mp3PrevState  = STATE_MUSIC_INIT;
  enMusicState  = STATE_MUSIC_INIT;
  enMp3PlayStatus  = MP3_STATUS_STOP;

  BOOLEAN _return  = MApp_Music_TimeOutCheck();

  CPPTEST_ASSERT_BOOL_EQUAL(FALSE,_return);
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_TimeOutCheck_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_Main_case1 */
/* CPPTEST_TEST_CASE_CONTEXT EN_RET MApp_Music_Main(EN_MUSIC_TYPE) */
void TestSuite_mapp_music_test_MApp_Music_Main_case1()
{
  //case STATE_MUSIC_STANDBY
    {
      EN_MUSIC_TYPE _enMusicType = EN_MUSIC_MP3;
        enMusicState  = STATE_MUSIC_STANDBY;
        /* Tested function call */
        EN_RET _return  = MApp_Music_Main(_enMusicType);

        CPPTEST_ASSERT_INTEGER_EQUAL(MP3_STATUS_STOP, enMp3PlayStatus);
        CPPTEST_ASSERT_INTEGER_EQUAL(EXIT_MP3_TRAN_STANDBY, enMp3RetVal);
        CPPTEST_ASSERT_INTEGER_EQUAL(EXIT_MP3_TRAN_STANDBY, _return);
    }

    //case STATE_MUSIC_INIT
    {
    EN_MUSIC_TYPE _enMusicType = EN_MUSIC_MP3;
      enMusicState  = STATE_MUSIC_INIT;
      /* Tested function call */
      EN_RET _return  = MApp_Music_Main(_enMusicType);
      CPPTEST_ASSERT_INTEGER_EQUAL(MP3_STATUS_PLAYING, enMp3PlayStatus);
    CPPTEST_ASSERT_INTEGER_EQUAL(EXIT_MP3_INIT, enMp3RetVal);
    CPPTEST_ASSERT_INTEGER_EQUAL(EXIT_MP3_INIT, _return);
    CPPTEST_ASSERT_INTEGER_EQUAL(EN_MUSIC_MP3, enCurrentMusicType);
    CPPTEST_ASSERT_INTEGER_EQUAL(STATE_MUSIC_EXIT, enMusicState);
    }

    //case STATE_MUSIC_OPEN_FILE
    {
    EN_MUSIC_TYPE _enMusicType = EN_MUSIC_MP3;
      enMusicState  = STATE_MUSIC_OPEN_FILE;
      /* Tested function call */
      EN_RET _return  = MApp_Music_Main(_enMusicType);

    CPPTEST_ASSERT_INTEGER_EQUAL(EXIT_MP3_DECODING, _return);
    CPPTEST_ASSERT_INTEGER_EQUAL(STATE_MUSIC_EXIT, enMusicState);
    }

    //case STATE_MUSIC_INPUT
    {
    EN_MUSIC_TYPE _enMusicType = EN_MUSIC_MP3;
      enMusicState  = STATE_MUSIC_INPUT;
      /* Tested function call */
      EN_RET _return  = MApp_Music_Main(_enMusicType);
      CPPTEST_ASSERT_INTEGER_EQUAL(EXIT_MP3_DECODING, _return);
    }

    //case STATE_MUSIC_WAIT_DECODE_DONE
    {
    EN_MUSIC_TYPE _enMusicType = EN_MUSIC_MP3;
      enMusicState  = STATE_MUSIC_WAIT_DECODE_DONE;
      /* Tested function call */
      EN_RET _return  = MApp_Music_Main(_enMusicType);
      CPPTEST_ASSERT_INTEGER_EQUAL(EXIT_MP3_DECODING, _return);
      CPPTEST_ASSERT_INTEGER_EQUAL(STATE_MUSIC_EXIT, enMusicState);
    }

    //case STATE_MUSIC_WAIT
    {
    EN_MUSIC_TYPE _enMusicType = EN_MUSIC_MP3;
      enMusicState  = STATE_MUSIC_WAIT;
      /* Tested function call */
      EN_RET _return  = MApp_Music_Main(_enMusicType);
      CPPTEST_ASSERT_INTEGER_EQUAL(EXIT_MP3_DECODING, _return);
    }

    //case STATE_MUSIC_SKIP_PLAY_NEXT
    {
    EN_MUSIC_TYPE _enMusicType = EN_MUSIC_MP3;
    enMusicState  = STATE_MUSIC_SKIP_PLAY_NEXT;
    /* Tested function call */
    EN_RET _return  = MApp_Music_Main(_enMusicType);

    CPPTEST_ASSERT_INTEGER_EQUAL(EXIT_MP3_WAIT, _return);
    CPPTEST_ASSERT_INTEGER_EQUAL(MP3_STATUS_STOP, enMp3PlayStatus);
    CPPTEST_ASSERT_INTEGER_EQUAL(EXIT_MP3_WAIT, enMp3RetVal);
    CPPTEST_ASSERT_INTEGER_EQUAL(STATE_MUSIC_EXIT, enMusicState);
    }

    //case STATE_MUSIC_SKIP_PLAY_PREV
    {
    EN_MUSIC_TYPE _enMusicType = EN_MUSIC_MP3;
    enMusicState  = STATE_MUSIC_SKIP_PLAY_PREV;
    /* Tested function call */
    EN_RET _return  = MApp_Music_Main(_enMusicType);

    CPPTEST_ASSERT_INTEGER_EQUAL(EXIT_MP3_WAIT_PLAY_PREV, _return);
    CPPTEST_ASSERT_INTEGER_EQUAL(MP3_STATUS_STOP, enMp3PlayStatus);
    CPPTEST_ASSERT_INTEGER_EQUAL(EXIT_MP3_WAIT_PLAY_PREV, enMp3RetVal);
    CPPTEST_ASSERT_INTEGER_EQUAL(STATE_MUSIC_EXIT, enMusicState);
    }

    //case STATE_MUSIC_EXIT
    {
    EN_MUSIC_TYPE _enMusicType = EN_MUSIC_MP3;
    enMusicState  = STATE_MUSIC_EXIT;
    /* Tested function call */
    EN_RET _return  = MApp_Music_Main(_enMusicType);

    CPPTEST_ASSERT_INTEGER_EQUAL(EXIT_MP3_EXIT, _return);
    CPPTEST_ASSERT_INTEGER_EQUAL(MP3_STATUS_STOP, enMp3PlayStatus);
    CPPTEST_ASSERT_INTEGER_EQUAL(EXIT_MP3_EXIT, enMp3RetVal);
    CPPTEST_ASSERT_INTEGER_EQUAL(STATE_MUSIC_STANDBY, enMusicState);
    }

    //case default
    {
    EN_MUSIC_TYPE _enMusicType = EN_MUSIC_MP3;
    enMusicState  = 20;
    /* Tested function call */
    EN_RET _return  = MApp_Music_Main(_enMusicType);

    CPPTEST_ASSERT_INTEGER_EQUAL(EXIT_MP3_EXIT, _return);
    CPPTEST_ASSERT_INTEGER_EQUAL(EXIT_MP3_EXIT, enMp3RetVal);
    CPPTEST_ASSERT_INTEGER_EQUAL(STATE_MUSIC_STANDBY, enMusicState);
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_Main_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_Pause_case_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_Pause(void) */
void TestSuite_mapp_music_test_MApp_Music_Pause_case_TRUE()
{
  u8MusicFFFWMode  = 0;
  enMp3PlayStatus  = MP3_STATUS_PLAYING;
  BOOLEAN _return  = MApp_Music_Pause();

  CPPTEST_ASSERT_BOOL_EQUAL(TRUE, _return);
  CPPTEST_ASSERT_INTEGER_EQUAL(MP3_STATUS_PAUSE, enMp3PlayStatus);
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_Pause_case_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_Resume */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Music_Resume(void) */
void TestSuite_mapp_music_test_MApp_Music_Resume()
{
  u8MusicFFFWMode  = 0;
  enMp3PlayStatus  = MP3_STATUS_PAUSE;
  MApp_Music_Resume();

  CPPTEST_ASSERT_INTEGER_EQUAL(MP3_STATUS_PLAYING, enMp3PlayStatus);
  CPPTEST_ASSERT_INTEGER_EQUAL(MP3_NORMAL_MODE, u8MusicFFFWMode);
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_Resume */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_GetLyricTag */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_GetLyricTag(Music_Lyric_Tag *, U32) */
void TestSuite_mapp_music_test_MApp_Music_GetLyricTag()
{
  Music_Lyric_Tag lyricTagTemp;
   // Music_Lyric_Tag * _pLyricTag  = &lyricTagTemp;
    U32 _u32Time  =10ul;
  u16LyricTagCount  = 1u;
  //BOOLEAN _return  = MApp_Music_GetLyricTag(_pLyricTag, _u32Time);
  BOOLEAN _return  = MApp_Music_GetLyricTag(&lyricTagTemp, _u32Time);

    CPPTEST_ASSERT_BOOL_EQUAL(TRUE, _return);
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_GetLyricTag */

/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_Get_AAC_Info_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN M4AParser_Get_AAC_Info(ST_MP3_INFO *) */
void TestSuite_mapp_music_test_M4AParser_Get_AAC_Info_case1()
{
  ST_MP3_INFO mp3InfoTemp;
  ST_MP3_INFO * _pMp3Info  = &mp3InfoTemp ;
  u32Mp3FileHandle  = 0ul;
  m_pMp3FileEntry  = 0 ;
  AACID3Jump  = 0ul;

  BOOLEAN _return  = M4AParser_Get_AAC_Info(_pMp3Info);

  CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
  CPPTEST_ASSERT_INTEGER_EQUAL(INVALID_DATA_STREAM_HDL, u32Mp3FileHandle);
}
/* CPPTEST_TEST_CASE_END test_M4AParser_Get_AAC_Info_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_Get_M4A_Info_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN M4AParser_Get_M4A_Info(BoxInfo *) */
void TestSuite_mapp_music_test_M4AParser_Get_M4A_Info_case1()
{
  BoxInfo boxInfoTemp;
    BoxInfo * _boxInfo  = &boxInfoTemp ;

    /* Initializing global variable g_box */ 
    {
      g_box.bFoundmdat = 1;
      g_box.dwmdatSize = 8192;

      g_box.bFoundstsz = 1;
      g_box.u32stszSize = 8192;
    }

    {
        /* Tested function call */
        BOOLEAN _return  = M4AParser_Get_M4A_Info(_boxInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);

    }
}
/* CPPTEST_TEST_CASE_END test_M4AParser_Get_M4A_Info_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_ReCalculateChunkIndex_case1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 M4AParser_ReCalculateChunkIndex(U32, U32 *) */
void TestSuite_mapp_music_test_M4AParser_ReCalculateChunkIndex_case1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32StszCurrentIndex) */ 
    U32 _u32StszCurrentIndex  = 0ul;
    /* Initializing argument 2 (pu32SampleIndex) */

    U32 u32SampleIndexTemp = 0;
    U32 * _pu32SampleIndex  = &u32SampleIndexTemp ;
    /* Initializing global variable boxM4a */ 
    {
      U32 u32TempArray[3] = {1,36,1};
//      boxM4a.stscInfo.u32EntryInfo[0][0] = 1;
//      boxM4a.stscInfo.u32EntryInfo[0][1] =36;
      boxM4a.stscInfo.pu32EntryInfo = &u32TempArray;

    }
    {
        /* Tested function call */
        U32 _return  = M4AParser_ReCalculateChunkIndex(_u32StszCurrentIndex, _pu32SampleIndex);
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(0, ( _return ));
        CPPTEST_ASSERT_INTEGER_EQUAL(0, ( boxM4a.dwstsdSampleRate ));
        CPPTEST_ASSERT_INTEGER_EQUAL(0, ( boxM4a.dwmdatLocation ));
        CPPTEST_ASSERT_INTEGER_EQUAL(0, ( boxM4a.dwmdatSize ));
        CPPTEST_ASSERT_INTEGER_EQUAL(36, ( boxM4a.u32stscSize ));
    }
}
/* CPPTEST_TEST_CASE_END test_M4AParser_ReCalculateChunkIndex_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_AddADTSHeaderForDSP_case1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 M4AParser_AddADTSHeaderForDSP(U32, U32) */
void TestSuite_mapp_music_test_M4AParser_AddADTSHeaderForDSP_case1()
{
    /* Pre-condition initialization */

    U32 _dwReqAddress  = 0ul;
    U32 _u32ReqBytes  = 32ul;

    _pu8ADTSHeader[0] = 0;
    _pu8ADTSHeader[1] = 0;
    _pu8ADTSHeader[2] = 0;
    _pu8ADTSHeader[3] = 0;
    _pu8ADTSHeader[4] = 0;
    _pu8ADTSHeader[5] = 0;
    _pu8ADTSHeader[6] = 0;
    _pu8ADTSHeader[7] = 1;


    _u32StszCurrentFrame = 16;
    _u32StszTotalFrame = 32;
    _u32ADTSWriteLeft = 0;

    boxM4a.u32stscSize = 16;
    boxM4a.u8channelConfiguration = 2;
    boxM4a.stscInfo.u32CurrentEntry = 0;

    U32 u32TempArray[3] = {1,1,16};
//    boxM4a.stscInfo.u32EntryInfo[0][2] = 16;
    boxM4a.stscInfo.pu32EntryInfo = &u32TempArray;
    boxM4a.u8SampleRateIndex = 1;

  /* Tested function call */
  U32 _return  = M4AParser_AddADTSHeaderForDSP(_dwReqAddress, _u32ReqBytes);
  /* Post-condition check */
  CPPTEST_ASSERT_INTEGER_EQUAL(0, ( _return ));
  CPPTEST_ASSERT_INTEGER_EQUAL(19, ( _u32StszCurrentFrame ));
  CPPTEST_ASSERT_INTEGER_EQUAL(32, ( _u32StszTotalFrame ));
  CPPTEST_ASSERT_INTEGER_EQUAL(2, ( boxM4a.u8channelConfiguration ));
  CPPTEST_ASSERT_INTEGER_EQUAL(1, ( boxM4a.u8SampleRateIndex ));

  CPPTEST_ASSERT_INTEGER_EQUAL(0xFF,_pu8ADTSHeader[0]);
  CPPTEST_ASSERT_INTEGER_EQUAL(0xF1,_pu8ADTSHeader[1]);
  CPPTEST_ASSERT_INTEGER_EQUAL(64,_pu8ADTSHeader[2]);
  CPPTEST_ASSERT_INTEGER_EQUAL(128,_pu8ADTSHeader[3]);
  CPPTEST_ASSERT_INTEGER_EQUAL(1,_pu8ADTSHeader[4]);
  CPPTEST_ASSERT_INTEGER_EQUAL(159,_pu8ADTSHeader[5]);
  CPPTEST_ASSERT_INTEGER_EQUAL(0xFC,_pu8ADTSHeader[6]);
  CPPTEST_ASSERT_INTEGER_EQUAL(0,_pu8ADTSHeader[7]);
}
/* CPPTEST_TEST_CASE_END test_M4AParser_AddADTSHeaderForDSP_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_WriteDSP_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN M4AParser_WriteDSP(U32, U32) */
void TestSuite_mapp_music_test_M4AParser_WriteDSP_case1()
{

  //test FF
  {
    U32  _u32ReqBytes = 4096;
    U32 _dwReqAddress = 0;

    _bM4aJustOpened = 1;

    bM4aRelocateFilePosition = 1;

    boxM4a.dwFileSize = 10;
    boxM4a.dwmdatLocation = 5;

    boxM4a.bFoundstsz = 1;
    boxM4a.bFoundstsc = 1;
    boxM4a.u32stscSize = 3;

    _u32StszCurrentFrame = 0;
    _u32M4aCurrentFrameIndex = 0;

        /* Tested function call */
        BOOLEAN _return  = M4AParser_WriteDSP(_dwReqAddress, _u32ReqBytes);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(true, ( _return ));
        CPPTEST_ASSERT_INTEGER_EQUAL(0, ( _bM4aJustOpened ));
        CPPTEST_ASSERT_INTEGER_EQUAL(0, ( u32Mp3FileBytesLeft ));
        CPPTEST_ASSERT_INTEGER_EQUAL(0, ( u32M4aReadLeft ));
        CPPTEST_ASSERT_INTEGER_EQUAL(0, ( _u32ADTSWriteLeft ));
        CPPTEST_ASSERT_INTEGER_EQUAL(5, ( boxM4a.dwmdatLocation ));
        CPPTEST_ASSERT_INTEGER_EQUAL(10, ( boxM4a.dwFileSize ));
  }

}
/* CPPTEST_TEST_CASE_END test_M4AParser_WriteDSP_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_SetCurrentFrameIndex_case1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 M4AParser_SetCurrentFrameIndex(void) */
void TestSuite_mapp_music_test_M4AParser_SetCurrentFrameIndex_case1()
{
  _u32FrameArrayIndex = 10;
  /* Tested function call */
  U32 _return  = M4AParser_SetCurrentFrameIndex();
  /* Post-condition check */
  CPPTEST_ASSERT_INTEGER_EQUAL(4, ( _return ));
}
/* CPPTEST_TEST_CASE_END test_M4AParser_SetCurrentFrameIndex_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_M4aParser_GetOneStszEntryFromDRAM */
/* CPPTEST_TEST_CASE_CONTEXT U32 M4aParser_GetOneStszEntryFromDRAM(U32) */
void TestSuite_mapp_music_test_M4aParser_GetOneStszEntryFromDRAM()
{

    U32 _u32Index  = 0ul;
   _bM4aJustOpened  = 1;

  /* Tested function call */
  U32 _return  = M4aParser_GetOneStszEntryFromDRAM(_u32Index);
  /* Post-condition check */
  CPPTEST_ASSERT_INTEGER_EQUAL(0, ( _return ));
  CPPTEST_ASSERT_INTEGER_EQUAL(1, ( _bM4aJustOpened ));
}
/* CPPTEST_TEST_CASE_END test_M4aParser_GetOneStszEntryFromDRAM */

/* CPPTEST_TEST_CASE_BEGIN test_M4AParser_SaveFrameLocation_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN M4AParser_SaveFrameLocation(void) */
void TestSuite_mapp_music_test_M4AParser_SaveFrameLocation_case1()
{

  boxM4a.bFoundstco = 1;
  boxM4a.u32stcoFrameLocation = 10;
  boxM4a.dwFileSize = 5000;
  boxM4a.u32stcoEntry = 12;
  boxM4a.bFoundstsz = 1;
  boxM4a.u32stszLocation = 0;
  boxM4a.u32stszSize = 10;
  boxM4a.bFoundstsc = 1;
  boxM4a.stscInfo.u32TotalEntry = 200;


  /* Tested function call */
  BOOLEAN _return  = M4AParser_SaveFrameLocation();
  /* Post-condition check */
  CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
//  CPPTEST_ASSERT_INTEGER_EQUAL(128, ( boxM4a.stscInfo.u32TotalEntry));

}
/* CPPTEST_TEST_CASE_END test_M4AParser_SaveFrameLocation_case1 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_Music_MP3TimeOffset_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_Music_MP3TimeOffset(U32) */
void TestSuite_mapp_music_test__MApp_Music_MP3TimeOffset_case1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32GotoTimeMs) */ 
    U32 _u32GotoTimeMs  = 0ul;

    stMp3Info.u8Flag = MP3_FLAG_VBR_XING;
    stMp3Info.u16TOCLength = 8;
    stMp3Info.u32Duration = 300;
    stMp3Info.u32ID3TagV2Size = 25;

  /* Tested function call */
  BOOLEAN _return  = _MApp_Music_MP3TimeOffset(_u32GotoTimeMs);
  /* Post-condition check */
  CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));

}
/* CPPTEST_TEST_CASE_END test__MApp_Music_MP3TimeOffset_case1 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_Music_AACTimeOffset_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_Music_AACTimeOffset(U32) */
void TestSuite_mapp_music_test__MApp_Music_AACTimeOffset_case1()
{
  //test AAC
  boxM4a.bFoundmdat = 0;
  stMp3Info.u32Duration = 300;
    U32 _u32GotoTimeMs  = 0ul;

  /* Tested function call */
  BOOLEAN _return  = _MApp_Music_AACTimeOffset(_u32GotoTimeMs);
  /* Post-condition check */
  CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
}
/* CPPTEST_TEST_CASE_END test__MApp_Music_AACTimeOffset_case1 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_Music_AACTimeOffset_case2 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_Music_AACTimeOffset(U32) */
void TestSuite_mapp_music_test__MApp_Music_AACTimeOffset_case2()
{
    //test M4A
    U32 _u32GotoTimeMs  = 0ul;

    boxM4a.bFoundmdat = 1;
    _bM4aEnableFFFB = 1;
    boxM4a.bFoundstsz = 1;
    boxM4a.bFoundstsc = 1;
    boxM4a.u32stscSize = 20;

    stMp3Info.u16SampleRate = 44800;

  /* Tested function call */
  BOOLEAN _return  = _MApp_Music_AACTimeOffset(_u32GotoTimeMs);
  /* Post-condition check */
  CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
}
/* CPPTEST_TEST_CASE_END test__MApp_Music_AACTimeOffset_case2 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_Music_WAVTimeOffset */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_Music_WAVTimeOffset(U32) */
void TestSuite_mapp_music_test__MApp_Music_WAVTimeOffset()
{
    U32 _u32GotoTimeMs  = 0ul;

    stWavChunk.u32AvgBytesPerSec =32;
    stWavChunk.u16FormatTag = (U16)WAVE_FORMAT_M_ADPCM;
    stWavChunk.u16BlockSize = 8;
    stWavChunk.u32HeaderSize = 44;

  /* Tested function call */
  BOOLEAN _return  = _MApp_Music_WAVTimeOffset(_u32GotoTimeMs);
  /* Post-condition check */
  CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
}
/* CPPTEST_TEST_CASE_END test__MApp_Music_WAVTimeOffset */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_Music_FLACTimeOffset_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_Music_FLACTimeOffset(U32) */
void TestSuite_mapp_music_test__MApp_Music_FLACTimeOffset_case1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32GotoTimeMs) */ 
    U32 _u32GotoTimeMs  = 5000ul;

    m_stFlacInfo.u32SampleRate = 44800;
    m_stFlacInfo.u32SeekEntryCount = 10;

    ST_FLAC_SEEK_TABLE stSeekTableTemp[10] = {0,0,100,
                                              10000,90,100,
                                              60000,300,100,
                                              100000,400,100,
                                              160000,800,100,
                                              220000,1000,100,
                                              300000,1200,100,
                                              330000,1500,100,
                                              360000,1800,100,
                                              380000,2000,100};


    m_stFlacInfo.pstSeekTable = &stSeekTableTemp;


  /* Tested function call */
  BOOLEAN _return  = _MApp_Music_FLACTimeOffset(_u32GotoTimeMs);
  /* Post-condition check */
  CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));


}
/* CPPTEST_TEST_CASE_END test__MApp_Music_FLACTimeOffset_case1 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_Music_FLACTimeOffsetNoTable */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_Music_FLACTimeOffsetNoTable(U32) */
void TestSuite_mapp_music_test__MApp_Music_FLACTimeOffsetNoTable()
{
    /* Initializing argument 1 (u32GotoTimeMs) */ 
    U32 _u32GotoTimeMs  = 0ul;

    m_stFlacInfo.u32Duration = 300;
    stMp3Info.u32FileSize = 20000;
    m_stFlacInfo.u32DataOffset = 0;

  /* Tested function call */
  BOOLEAN _return  = _MApp_Music_FLACTimeOffsetNoTable(_u32GotoTimeMs);
  /* Post-condition check */
  CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
}
/* CPPTEST_TEST_CASE_END test__MApp_Music_FLACTimeOffsetNoTable */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_ProcessTimeOffset */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_ProcessTimeOffset(U32) */
void TestSuite_mapp_music_test_MApp_Music_ProcessTimeOffset()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32GotoTimeMs) */ 
    U32 _u32GotoTimeMs  = 0ul;


    //test MP3
    {
      enMusicState = STATE_MUSIC_WAIT_DECODE_DONE;
      stMp3Info.u32Duration = 300;
      enCurrentMusicType = EN_MUSIC_MP3;

      BOOLEAN _return  = MApp_Music_ProcessTimeOffset(_u32GotoTimeMs);
      CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }

    //test AAC
    {
      enMusicState = STATE_MUSIC_WAIT_DECODE_DONE;
      stMp3Info.u32Duration = 300;
      enCurrentMusicType = EN_MUSIC_AAC;

      BOOLEAN _return  = MApp_Music_ProcessTimeOffset(_u32GotoTimeMs);
      CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }

    //test WAV
    {
      enMusicState = STATE_MUSIC_WAIT_DECODE_DONE;
      stMp3Info.u32Duration = 300;
      enCurrentMusicType = EN_MUSIC_WAV;

      BOOLEAN _return  = MApp_Music_ProcessTimeOffset(_u32GotoTimeMs);
      CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }

    //test FLAC
    {
      enMusicState = STATE_MUSIC_WAIT_DECODE_DONE;
      stMp3Info.u32Duration = 300;
      enCurrentMusicType = EN_MUSIC_FLAC;

      BOOLEAN _return  = MApp_Music_ProcessTimeOffset(_u32GotoTimeMs);
      CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }

}
/* CPPTEST_TEST_CASE_END test_MApp_Music_ProcessTimeOffset_0 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_FastForwardBackward_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_FastForwardBackward(BOOLEAN, EN_MP3_SPEED) */
void TestSuite_mapp_music_test_MApp_Music_FastForwardBackward_case1()
{

    U8 _bForward  = 1;
    EN_MP3_SPEED _eSpeed  = EN_MP3_SPEED_X1;
    enMusicState = STATE_MUSIC_WAIT_DECODE_DONE;

  BOOLEAN _return  = MApp_Music_FastForwardBackward(_bForward, _eSpeed);
  CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));

}
/* CPPTEST_TEST_CASE_END test_MApp_Music_FastForwardBackward_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_AAC_Probe_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_AAC_Probe(U32, ST_MUSIC_PROBE_INFO *, U32) */
void TestSuite_mapp_music_test_MApp_Music_AAC_Probe_case1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = 0ul;
    /* Initializing argument 2 (pstMusicProbeInfo) */ 
    ST_MUSIC_PROBE_INFO stMusicProbeInfoTemp;
    ST_MUSIC_PROBE_INFO * _pstMusicProbeInfo  = &stMusicProbeInfoTemp ;
    /* Initializing argument 3 (u32InfoAttr) */ 
    U32 _u32InfoAttr  = E_MUSIC_INFO_DURATION;

  /* Tested function call */
  BOOLEAN _return  = MApp_Music_AAC_Probe(_u32Hdl, _pstMusicProbeInfo, _u32InfoAttr);
  /* Post-condition check */
  CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));

}
/* CPPTEST_TEST_CASE_END test_MApp_Music_AAC_Probe_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_M4A_Probe_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_M4A_Probe(U32, ST_MUSIC_PROBE_INFO *, U32) */
void TestSuite_mapp_music_test_MApp_Music_M4A_Probe_case1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = 0ul;
    /* Initializing argument 2 (pstMusicProbeInfo) */ 
    ST_MUSIC_PROBE_INFO stMusicProbeInfoTemp;
    ST_MUSIC_PROBE_INFO * _pstMusicProbeInfo  = &stMusicProbeInfoTemp ;
    /* Initializing argument 3 (u32InfoAttr) */ 
    U32 _u32InfoAttr  = E_MUSIC_INFO_DURATION;

  /* Tested function call */
  BOOLEAN _return  = MApp_Music_M4A_Probe(_u32Hdl, _pstMusicProbeInfo, _u32InfoAttr);
  /* Post-condition check */
  CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));

}
/* CPPTEST_TEST_CASE_END test_MApp_Music_M4A_Probe_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_FLAC_Probe_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_FLAC_Probe(U32, ST_MUSIC_PROBE_INFO *, U32) */
void TestSuite_mapp_music_test_MApp_Music_FLAC_Probe_case1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = 0ul;
    /* Initializing argument 2 (pstMusicProbeInfo) */ 
    ST_MUSIC_PROBE_INFO stMusicProbeInfoTemp;
    ST_MUSIC_PROBE_INFO * _pstMusicProbeInfo  = &stMusicProbeInfoTemp ;
    /* Initializing argument 3 (u32InfoAttr) */ 
    U32 _u32InfoAttr  = E_MUSIC_INFO_DURATION;

  /* Tested function call */
  BOOLEAN _return  = MApp_Music_FLAC_Probe(_u32Hdl, _pstMusicProbeInfo, _u32InfoAttr);;

  //CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
  CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_FLAC_Probe_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_WAV_Probe_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_WAV_Probe(U32, ST_MUSIC_PROBE_INFO *, U32) */
void TestSuite_mapp_music_test_MApp_Music_WAV_Probe_case1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = 0ul;
    /* Initializing argument 2 (pstMusicProbeInfo) */ 
  ST_MUSIC_PROBE_INFO stMusicProbeInfoTemp;
  ST_MUSIC_PROBE_INFO * _pstMusicProbeInfo  = &stMusicProbeInfoTemp ;
  /* Initializing argument 3 (u32InfoAttr) */
  U32 _u32InfoAttr  = E_MUSIC_INFO_DURATION;

  /* Tested function call */
  BOOLEAN _return  = MApp_Music_WAV_Probe(_u32Hdl, _pstMusicProbeInfo, _u32InfoAttr);
  /* Post-condition check */
  CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_WAV_Probe_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_MP3_Probe_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Music_MP3_Probe(U32, ST_MUSIC_PROBE_INFO *, U32) */
void TestSuite_mapp_music_test_MApp_Music_MP3_Probe_case1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
  U32 _u32Hdl  = 0ul;
  /* Initializing argument 2 (pstMusicProbeInfo) */
  ST_MUSIC_PROBE_INFO stMusicProbeInfoTemp;
  ST_MUSIC_PROBE_INFO * _pstMusicProbeInfo  = &stMusicProbeInfoTemp ;
  /* Initializing argument 3 (u32InfoAttr) */
  U32 _u32InfoAttr  = E_MUSIC_INFO_DURATION;


  /* Tested function call */
  BOOLEAN _return  = MApp_Music_MP3_Probe(_u32Hdl, _pstMusicProbeInfo, _u32InfoAttr);
  /* Post-condition check */
  CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));

}
/* CPPTEST_TEST_CASE_END test_MApp_Music_MP3_Probe_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_ProcessFfRew_case6 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Music_ProcessFfRew(void) */
void TestSuite_mapp_music_test_MApp_Music_ProcessFfRew_case6()
{
    //test AC3 FF
    /* Initializing global variable enCurrentMusicType */
    {
         enCurrentMusicType  = EN_MUSIC_AC3;
         stMp3Info.u32FileSize = 30;
         stMp3Info.u32CurrentPlayTime = 30000;
         stMp3Info.u32Duration = 20;

         u8MusicFFFWMode = MP3_FF_Mode;
         /* Tested function call */
         MApp_Music_ProcessFfRew();
         CPPTEST_ASSERT_INTEGER_EQUAL(20000,stMp3Info.u32CurrentPlayTime);
    }

}
/* CPPTEST_TEST_CASE_END test_MApp_Music_ProcessFfRew_case6 */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_Music_CalculateMP3CBRDuration_ID3V2 */
/* CPPTEST_TEST_CASE_CONTEXT U32 M4AParser_AddADTSHeaderForDSP(U32, U32) */
void TestSuite_mapp_music_test_MApp_Music_CalculateMP3CBRDuration_ID3V2()
{
	/* Pre-condition initialization */
	    /* Initializing argument 1 (pMp3Info) */
	    ST_MP3_INFO _pMp3Info_14 ;

	    _pMp3Info_14.u32FileSize = 128+200;
	    _pMp3Info_14.bID3TagV1 = TRUE;
	    _pMp3Info_14.u16ID3TagV1Size = 128;
	    _pMp3Info_14.u32ID3TagV2Size = 0;
	    U32 u32FirstFrameOffset = MApp_Music_SearchFirstFrame(u32Mp3FileHandle, _pMp3Info_14.u32ID3TagV2Size);
	    _pMp3Info_14.u32ID3TagV2Size += u32FirstFrameOffset;
	    ST_MP3_INFO * _pMp3Info  = & _pMp3Info_14;

	    /* Initializing argument 2 (u32FileHandle) */
	    U32 _u32FileHandle  = 0ul;
	    {
	        /* Tested function call */
	        U32 _return  = MApp_Music_CalculateMP3CBRDuration(_pMp3Info, _u32FileHandle);
	        /* Post-condition check */
	        CPPTEST_ASSERT_INTEGER_EQUAL(0, ( _return ));
	    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Music_CalculateMP3CBRDuration_ID3V2 */
