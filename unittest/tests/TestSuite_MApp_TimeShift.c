#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app/MApp_TimeShift.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app/MApp_TimeShift.c");

CPPTEST_TEST_SUITE(TestSuite_MApp_TimeShift);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_ABLoop_Off);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_ABLoop_SetA);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_ABLoop_SetB);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_IfPause_if);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_IfPause_else);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_IfFastForward_if);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_IfFastForward_else);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_IfFastBackward_if);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_IfFastBackward_else);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_AdAudioSelectLanguage);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_AdAudioStopLanguage);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_AudioSelectLanguage);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_AudioStopLanguage);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_Subtitle_LoadServices);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_Subtitle_LoadMenu);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_TTXSubtitle_GetNum);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_AudioGetLanguageSelection);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_AudioGetLanguageTotal);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_AudioGetLanguageInfo);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_AudioGetStreamInfo_if);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_AudioGetStreamInfo_else);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetPlaybackSpeed_if);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetPlaybackSpeed_else);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetPlaybackTimeSec_if);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetPlaybackTimeSec_else);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetRecordValidPeriodSec_if);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetRecordValidPeriodSec_else);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetRecordEndTimeSec_if);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetRecordEndTimeSec_else);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetRecordStartTimeSec_if1);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetRecordStartTimeSec_if2);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetRecordStartTimeSec_else);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_PlaybackClose_if);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_PlaybackClose_else);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_PlaybackDisable_if);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_PlaybackDisable_else);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_StateMachineGet);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_Playback_StateMachineGet);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_StatusGet);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_RecordStopDiv_if);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_RecordStopDiv_else);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_IsRecordStoping_if);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_IsRecordStoping_else);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_DelTsFileName_if);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_DelTsFileName_else);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_RecordOpen_if1);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_RecordOpen_if2);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_RecordOpen_if3);
CPPTEST_TEST(TestSuite_MApp_TimeShift_test_MApp_TimeShift_RecordOpen_else3);
CPPTEST_TEST_SUITE_END();


void TestSuite_MApp_TimeShift_test_MApp_TimeShift_ABLoop_Off();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_ABLoop_SetA();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_ABLoop_SetB();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_IfPause_if();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_IfPause_else();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_IfFastForward_if();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_IfFastForward_else();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_IfFastBackward_if();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_IfFastBackward_else();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_AdAudioSelectLanguage();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_AdAudioStopLanguage();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_AudioSelectLanguage();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_AudioStopLanguage();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_Subtitle_LoadServices();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_Subtitle_LoadMenu();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_TTXSubtitle_GetNum();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_AudioGetLanguageSelection();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_AudioGetLanguageTotal();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_AudioGetLanguageInfo();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_AudioGetStreamInfo_if();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_AudioGetStreamInfo_else();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetPlaybackSpeed_if();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetPlaybackSpeed_else();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetPlaybackTimeSec_if();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetPlaybackTimeSec_elseif();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetPlaybackTimeSec_else();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetRecordValidPeriodSec_if();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetRecordValidPeriodSec_else();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetRecordEndTimeSec_if();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetRecordEndTimeSec_else();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetRecordStartTimeSec_if1();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetRecordStartTimeSec_if2();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetRecordStartTimeSec_else();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_PlaybackClose_if();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_PlaybackClose_else();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_PlaybackDisable_if();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_PlaybackDisable_else();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_StateMachineGet();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_Playback_StateMachineGet();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_StatusGet();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_RecordStopDiv_if();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_RecordStopDiv_else();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_IsRecordStoping_if();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_IsRecordStoping_else();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_DelTsFileName_if();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_DelTsFileName_else();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_RecordOpen_if1();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_RecordOpen_if2();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_RecordOpen_if3();
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_RecordOpen_else3();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_MApp_TimeShift);

void TestSuite_MApp_TimeShift_setUp()
{
}

void TestSuite_MApp_TimeShift_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_ABLoop_Off */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TimeShift_ABLoop_Off(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_ABLoop_Off()
{
    /* Pre-condition initialization */
    /* Initializing global variable _pstPvrPlaybackPath */
    {
    	int iTest = 10;
         _pstPvrPlaybackPath  = &iTest ;
    }
    /* Initializing global variable _enTimeShiftState */
    {
         _enTimeShiftState  = E_TIMESHIFT_STATE_RECORDING;
    }
    {
        /* Tested function call */
        MApp_TimeShift_ABLoop_Off();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _pstPvrPlaybackPath->bABLoopSwitch ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_ABLoop_Off */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_ABLoop_SetA */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TimeShift_ABLoop_SetA(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_ABLoop_SetA()
{
    /* Pre-condition initialization */
    /* Initializing global variable _pstPvrPlaybackPath */
    {
		int iTest = 10;
		_pstPvrPlaybackPath  = &iTest ;
        _pstPvrPlaybackPath->u32FilePositionKB = 15;
    }
    /* Initializing global variable _enTimeShiftState */
    {
         _enTimeShiftState  = E_TIMESHIFT_STATE_RECORDING;
    }
    {
        /* Tested function call */
        MApp_TimeShift_ABLoop_SetA();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_ABLoop_SetA */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_ABLoop_SetB */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TimeShift_ABLoop_SetB(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_ABLoop_SetB()
{
    /* Pre-condition initialization */
    /* Initializing global variable _pstPvrPlaybackPath */
    {
    	int iTest = 10;
    	_pstPvrPlaybackPath  = &iTest ;
    }
    /* Initializing global variable _enTimeShiftState */
    {
         _enTimeShiftState  = E_TIMESHIFT_STATE_RECORDING;
    }
    {
        /* Tested function call */
        MApp_TimeShift_ABLoop_SetB();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _pstPvrPlaybackPath->bABLoopSwitch ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_ABLoop_SetB */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_IfPause_if */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TimeShift_IfPause(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_IfPause_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftPlaybackState */
    {
         _enTimeShiftPlaybackState  = E_TIMESHIFT_PLAYBACK_STATE_DISABLE;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TimeShift_IfPause();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_IfPause_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_IfPause_else */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TimeShift_IfPause(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_IfPause_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftPlaybackState */
    {
         _enTimeShiftPlaybackState  = E_TIMESHIFT_PLAYBACK_STATE_RUNNING;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TimeShift_IfPause();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_IfPause_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_IfFastForward_if */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TimeShift_IfFastForward(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_IfFastForward_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftPlaybackState */
    {
         _enTimeShiftPlaybackState  = E_TIMESHIFT_PLAYBACK_STATE_FASTFORWARD;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TimeShift_IfFastForward();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_IfFastForward_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_IfFastForward_else */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TimeShift_IfFastForward(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_IfFastForward_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftPlaybackState */
    {
         _enTimeShiftPlaybackState  = E_TIMESHIFT_PLAYBACK_STATE_DISABLE;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TimeShift_IfFastForward();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_IfFastForward_else */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_IfFastBackward_if */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TimeShift_IfFastBackward(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_IfFastBackward_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftPlaybackState */
    {
         _enTimeShiftPlaybackState  = E_TIMESHIFT_PLAYBACK_STATE_FASTBACKWARD;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TimeShift_IfFastBackward();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_IfFastBackward_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_IfFastBackward_else */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TimeShift_IfFastBackward(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_IfFastBackward_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftPlaybackState */
    {
         _enTimeShiftPlaybackState  = E_TIMESHIFT_PLAYBACK_STATE_DISABLE;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TimeShift_IfFastBackward();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_IfFastBackward_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_AdAudioSelectLanguage */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TimeShift_AdAudioSelectLanguage(U8) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_AdAudioSelectLanguage()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8AudSelectedIndex) */
    U8 _u8AudSelectedIndex  = 0;
    /* Initializing global variable _pstPvrPlaybackPath */
    {
    	int iTest1 = 10;
         _pstPvrPlaybackPath  = &iTest1 ;
    }
    /* Initializing global variable _pstPvrRecordPath */
    {
    	int iTest2 = 10;
         _pstPvrRecordPath  = &iTest2 ;
    }
    {
        /* Tested function call */
        MApp_TimeShift_AdAudioSelectLanguage(_u8AudSelectedIndex);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_AdAudioSelectLanguage */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_AdAudioStopLanguage */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TimeShift_AdAudioStopLanguage(U8) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_AdAudioStopLanguage()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8AudSelectedIndex) */
    U8 _u8AudSelectedIndex  = 0;
    /* Initializing global variable _pstPvrPlaybackPath */
    {
    	int iTest1 = 10;
         _pstPvrPlaybackPath  = &iTest1 ;
    }
    /* Initializing global variable _pstPvrRecordPath */
    {
    	int iTest2 = 10;
         _pstPvrRecordPath  = &iTest2 ;
    }
    {
        /* Tested function call */
        MApp_TimeShift_AdAudioStopLanguage(_u8AudSelectedIndex);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_AdAudioStopLanguage */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_AudioSelectLanguage */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TimeShift_AudioSelectLanguage(U8) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_AudioSelectLanguage()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8AudSelectedIndex) */
    U8 _u8AudSelectedIndex  = 0;
    /* Initializing global variable _pstPvrPlaybackPath */
    {
    	int iTest1 = 10;
         _pstPvrPlaybackPath  = &iTest1 ;
    }
    /* Initializing global variable _pstPvrRecordPath */
    {
    	int iTest2 = 10;
         _pstPvrRecordPath  = &iTest2 ;
    }
    {
        /* Tested function call */
        MApp_TimeShift_AudioSelectLanguage(_u8AudSelectedIndex);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_AudioSelectLanguage */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_AudioStopLanguage */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TimeShift_AudioStopLanguage(U8) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_AudioStopLanguage()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8AudSelectedIndex) */
    U8 _u8AudSelectedIndex  = 0;
    /* Initializing global variable _pstPvrPlaybackPath */
    {
    	int iTest1 = 10;
         _pstPvrPlaybackPath  = &iTest1 ;
    }
    /* Initializing global variable _pstPvrRecordPath */
    {
    	int iTest2 = 10;
         _pstPvrRecordPath  = &iTest2 ;
    }
    {
        /* Tested function call */
        MApp_TimeShift_AudioStopLanguage(_u8AudSelectedIndex);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_AudioStopLanguage */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_Subtitle_LoadServices */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TimeShift_Subtitle_LoadServices(U8 *, U8 *, DVB_SUBTITLE_SERVICE *) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_Subtitle_LoadServices()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8SelIdx) */
    U8 _pu8SelIdx;
    /* Initializing argument 2 (pu8Num) */
    U8 _pu8Num;
    /* Initializing argument 3 (options) */
    DVB_SUBTITLE_SERVICE _options ;
    /* Initializing global variable _pstPvrRecordPath */
    {
    	int iTest1 = 10;
         _pstPvrRecordPath  = &iTest1 ;
         _pstPvrRecordPath->u8DVBSubtitleServiceNum = 1;
         _pstPvrRecordPath->u8SubtitleMenuSelectedIdx = 2;
    }
    {
        /* Tested function call */
        MApp_TimeShift_Subtitle_LoadServices(&_pu8SelIdx, &_pu8Num, &_options);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _pstPvrRecordPath->u8DVBSubtitleServiceNum, ( _pu8Num ) )
        CPPTEST_ASSERT_EQUAL( _pstPvrRecordPath->u8SubtitleMenuSelectedIdx, ( _pu8SelIdx ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_Subtitle_LoadServices */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_Subtitle_LoadMenu */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TimeShift_Subtitle_LoadMenu(U8 *, U8 *, SUBTITLE_MENU *, U8 *, U8 *) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_Subtitle_LoadMenu()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8SelIdx) */
    U8 _pu8SelIdx;
    /* Initializing argument 2 (pu8Num) */
    U8 _pu8Num;
    /* Initializing argument 3 (options) */
    SUBTITLE_MENU _options;
    /* Initializing argument 4 (pu8fEnableSubtitle) */
    U8 _pu8fEnableSubtitle;
    /* Initializing argument 5 (pu8fEnableTTXSubtitle) */
    U8 _pu8fEnableTTXSubtitle;
    /* Initializing global variable _pstPvrRecordPath */
    {
    	int iTest1 = 10;
         _pstPvrRecordPath  = &iTest1 ;
         _pstPvrRecordPath->u8SubtitleMenuNum = 1;
         _pstPvrRecordPath->u8SubtitleMenuSelectedIdx = 2;
         _pstPvrRecordPath->u8EnableSubtitle = 3;
         _pstPvrRecordPath->u8EnableTTXSubtitle = 4;
    }
    {
        /* Tested function call */
        MApp_TimeShift_Subtitle_LoadMenu(&_pu8SelIdx, &_pu8Num, &_options, &_pu8fEnableSubtitle, &_pu8fEnableTTXSubtitle);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _pstPvrRecordPath->u8SubtitleMenuNum, ( _pu8Num ) )
        CPPTEST_ASSERT_EQUAL( _pstPvrRecordPath->u8SubtitleMenuSelectedIdx, ( _pu8SelIdx ) )
        CPPTEST_ASSERT_EQUAL( _pstPvrRecordPath->u8EnableSubtitle, ( _pu8fEnableSubtitle ) )
        CPPTEST_ASSERT_EQUAL( _pstPvrRecordPath->u8EnableTTXSubtitle, ( _pu8fEnableTTXSubtitle ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_Subtitle_LoadMenu */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_TTXSubtitle_GetNum */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TimeShift_TTXSubtitle_GetNum(U8 *) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_TTXSubtitle_GetNum()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Num) */
    U8 _pu8Num;
    /* Initializing global variable _pstPvrRecordPath */
    {
    	int iTest1 = 10;
         _pstPvrRecordPath  = &iTest1 ;
         _pstPvrRecordPath->u8TTXSubtitleServiceNum = 5;
    }
    {
        /* Tested function call */
        MApp_TimeShift_TTXSubtitle_GetNum(&_pu8Num);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _pstPvrRecordPath->u8TTXSubtitleServiceNum, ( _pu8Num ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_TTXSubtitle_GetNum */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_AudioGetLanguageSelection */
/* CPPTEST_TEST_CASE_CONTEXT U8 MApp_TimeShift_AudioGetLanguageSelection(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_AudioGetLanguageSelection()
{
    /* Pre-condition initialization */
    /* Initializing global variable _pstPvrRecordPath */
    {
    	int iTest1 = 10;
         _pstPvrRecordPath  = &iTest1 ;
         _pstPvrRecordPath->u8audioLangSel = 5;
    }
    {
        /* Tested function call */
        U8 _return  = MApp_TimeShift_AudioGetLanguageSelection();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _pstPvrRecordPath->u8audioLangSel, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_AudioGetLanguageSelection */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_AudioGetLanguageTotal */
/* CPPTEST_TEST_CASE_CONTEXT U8 MApp_TimeShift_AudioGetLanguageTotal(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_AudioGetLanguageTotal()
{
    /* Pre-condition initialization */
    /* Initializing global variable _pstPvrRecordPath */
    {
    	int iTest1 = 10;
         _pstPvrRecordPath  = &iTest1 ;
         _pstPvrRecordPath->u8audioLangTotal = 5;
    }
    {
        /* Tested function call */
        U8 _return  = MApp_TimeShift_AudioGetLanguageTotal();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _pstPvrRecordPath->u8audioLangTotal, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_AudioGetLanguageTotal */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_AudioGetLanguageInfo */
/* CPPTEST_TEST_CASE_CONTEXT BYTE MApp_TimeShift_AudioGetLanguageInfo(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_AudioGetLanguageInfo()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_u8AudLangSelected */
    {
         g_u8AudLangSelected  = 0;
    }
    /* Initializing global variable _pstPvrRecordPath */
    {
    	int iTest1 = 10;
         _pstPvrRecordPath  = &iTest1 ;
         _pstPvrRecordPath->PVRAudioInfo[g_u8AudLangSelected].aISOLangInfo[0].bISOLanguageInfo = 1;
    }
    {
        /* Tested function call */
        BYTE _return  = MApp_TimeShift_AudioGetLanguageInfo();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _pstPvrRecordPath->PVRAudioInfo[g_u8AudLangSelected].aISOLangInfo[0].bISOLanguageInfo, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_AudioGetLanguageInfo */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_AudioGetStreamInfo_if */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TimeShift_AudioGetStreamInfo(AUD_INFO *, U8) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_AudioGetStreamInfo_if()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstAudioStreamInfo) */
    AUD_INFO _pstAudioStreamInfo;
    /* Initializing argument 2 (u8Idx) */
    U8 _u8Idx  = 2;
    /* Initializing global variable _pstPvrRecordPath */
    {
    	int iTest1 = 10;
         _pstPvrRecordPath  = &iTest1 ;
         _pstPvrRecordPath->u8audioLangTotal = 3;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TimeShift_AudioGetStreamInfo(&_pstAudioStreamInfo, _u8Idx);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_AudioGetStreamInfo_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_AudioGetStreamInfo_else */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TimeShift_AudioGetStreamInfo(AUD_INFO *, U8) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_AudioGetStreamInfo_else()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstAudioStreamInfo) */
    AUD_INFO _pstAudioStreamInfo;
    /* Initializing argument 2 (u8Idx) */
    U8 _u8Idx  = 4;
    /* Initializing global variable _pstPvrRecordPath */
    {
    	int iTest1 = 10;
         _pstPvrRecordPath  = &iTest1 ;
         _pstPvrRecordPath->u8audioLangTotal = 3;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TimeShift_AudioGetStreamInfo(&_pstAudioStreamInfo, _u8Idx);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_AudioGetStreamInfo_else */



/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_GetPlaybackSpeed_if */
/* CPPTEST_TEST_CASE_CONTEXT enPlaySpeed MApp_TimeShift_GetPlaybackSpeed(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetPlaybackSpeed_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftPlaybackSpeed */
    {
         _enTimeShiftPlaybackSpeed  = E_PLAY_SPEED_1X;
    }
    /* Initializing global variable _enTimeShiftState */
    {
         _enTimeShiftState  = E_TIMESHIFT_STATE_WAIT;
    }
    {
        /* Tested function call */
        enPlaySpeed _return  = MApp_TimeShift_GetPlaybackSpeed();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_PLAY_SPEED_1X, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_GetPlaybackSpeed_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_GetPlaybackSpeed_else */
/* CPPTEST_TEST_CASE_CONTEXT enPlaySpeed MApp_TimeShift_GetPlaybackSpeed(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetPlaybackSpeed_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftPlaybackSpeed */
    {
         _enTimeShiftPlaybackSpeed  = E_PLAY_SPEED_1X;
    }
    /* Initializing global variable _enTimeShiftState */
    {
         _enTimeShiftState  = E_TIMESHIFT_STATE_RECORDINGnPLAYBACKING;
    }
    {
        /* Tested function call */
        enPlaySpeed _return  = MApp_TimeShift_GetPlaybackSpeed();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _enTimeShiftPlaybackSpeed, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_GetPlaybackSpeed_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_GetPlaybackTimeSec_if */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_TimeShift_GetPlaybackTimeSec(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetPlaybackTimeSec_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable _pstPvrPlaybackPath */
    {
    	int iTest1 = 10;
    	_pstPvrPlaybackPath  = &iTest1 ;
    }
    /* Initializing global variable _enTimeShiftState */
    {
         _enTimeShiftState  = E_TIMESHIFT_STATE_WAIT;
    }

    {
        /* Tested function call */
    	U32 _return  = MApp_TimeShift_GetPlaybackTimeSec();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(50, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_GetPlaybackTimeSec_if */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_GetPlaybackTimeSec_else */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_TimeShift_GetPlaybackTimeSec(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetPlaybackTimeSec_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable _pstPvrPlaybackPath */
    {
    	int iTest1 = 10;
    	_pstPvrPlaybackPath  = &iTest1 ;
    }
    /* Initializing global variable _enTimeShiftState */
    {
         _enTimeShiftState  = E_TIMESHIFT_STATE_RECORDINGnPLAYBACKING;
    }

    {
        /* Tested function call */
        U32 _return  = MApp_TimeShift_GetPlaybackTimeSec();
        /* Post-condition check */
        printf("TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetPlaybackTimeSec_else _return = %d\n", _return);
        CPPTEST_ASSERT_EQUAL( 40, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_GetPlaybackTimeSec_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_GetRecordValidPeriodSec_if */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_TimeShift_GetRecordValidPeriodSec(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetRecordValidPeriodSec_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftState */
    {
         _enTimeShiftState  = E_TIMESHIFT_STATE_WAIT;
    }
    /* Initializing global variable _pstPvrRecordPath */
    {
    	int iTest1 = 10;
         _pstPvrRecordPath  = &iTest1 ;
         _pstPvrRecordPath->u32FileValidPeriod = 20;
    }
    {
        /* Tested function call */
        U32 _return  = MApp_TimeShift_GetRecordValidPeriodSec();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 0, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_GetRecordValidPeriodSec_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_GetRecordValidPeriodSec_else */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_TimeShift_GetRecordValidPeriodSec(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetRecordValidPeriodSec_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftState */
    {
         _enTimeShiftState  = E_TIMESHIFT_STATE_RECORDING;
    }
    /* Initializing global variable _pstPvrRecordPath */
    {
    	int iTest1 = 10;
         _pstPvrRecordPath  = &iTest1 ;
         _pstPvrRecordPath->u32FileValidPeriod = 20;
    }
    {
        /* Tested function call */
        U32 _return  = MApp_TimeShift_GetRecordValidPeriodSec();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _pstPvrRecordPath->u32FileValidPeriod/10, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_GetRecordValidPeriodSec_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_GetRecordEndTimeSec_if */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_TimeShift_GetRecordEndTimeSec(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetRecordEndTimeSec_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftState */
    {
         _enTimeShiftState  = E_TIMESHIFT_STATE_WAIT;
    }
    /* Initializing global variable _pstPvrRecordPath */
    {
         _pstPvrRecordPath  = 0 ;
    }
    {
        /* Tested function call */
        U32 _return  = MApp_TimeShift_GetRecordEndTimeSec();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 0, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_GetRecordEndTimeSec_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_GetRecordEndTimeSec_else */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_TimeShift_GetRecordEndTimeSec(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetRecordEndTimeSec_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftState */
    {
         _enTimeShiftState  = E_TIMESHIFT_STATE_RECORDING;
    }
    /* Initializing global variable _pstPvrRecordPath */
    {
    	int iTest1 = 10;
         _pstPvrRecordPath  = &iTest1 ;
         _pstPvrRecordPath->u32RecordedTime = 20;
         _pstPvrRecordPath->u32RecordedPeriod = 20;
         _pstPvrRecordPath->u32PausedPeriod = 20;
    }
    {
        /* Tested function call */
        U32 _return  = MApp_TimeShift_GetRecordEndTimeSec();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _pstPvrRecordPath->u32RecordedTime/1000 + _pstPvrRecordPath->u32RecordedPeriod/10 - _pstPvrRecordPath->u32PausedPeriod/10, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_GetRecordEndTimeSec_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_GetRecordStartTimeSec_if1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_TimeShift_GetRecordStartTimeSec(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetRecordStartTimeSec_if1()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftState */
    {
         _enTimeShiftState  = E_TIMESHIFT_STATE_WAIT;
    }
    /* Initializing global variable _pstPvrRecordPath */
    {
         _pstPvrRecordPath  = 0 ;
    }
    {
        /* Tested function call */
        U32 _return  = MApp_TimeShift_GetRecordStartTimeSec();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 0, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_GetRecordStartTimeSec_if1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_GetRecordStartTimeSec_if2 */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_TimeShift_GetRecordStartTimeSec(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetRecordStartTimeSec_if2()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftState */
    {
         _enTimeShiftState  = E_TIMESHIFT_STATE_RECORDING;
    }
    /* Initializing global variable _pstPvrRecordPath */
    {
    	int iTest1 = 10;
         _pstPvrRecordPath  = &iTest1 ;
         _pstPvrRecordPath->u32RecordedPeriod = 30;
         _pstPvrRecordPath->u32PausedPeriod = 20;
         _pstPvrRecordPath->u32FileValidPeriod = 20;
    }
    {
        /* Tested function call */
        U32 _return  = MApp_TimeShift_GetRecordStartTimeSec();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _pstPvrRecordPath->u32RecordedTime/1000, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_GetRecordStartTimeSec_if2 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_GetRecordStartTimeSec_else */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_TimeShift_GetRecordStartTimeSec(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetRecordStartTimeSec_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftState */
    {
         _enTimeShiftState  = E_TIMESHIFT_STATE_RECORDING;
    }
    /* Initializing global variable _pstPvrRecordPath */
    {
    	int iTest1 = 10;
         _pstPvrRecordPath  = &iTest1 ;
         _pstPvrRecordPath->u32RecordedPeriod = 200;
         _pstPvrRecordPath->u32PausedPeriod = 20;
         _pstPvrRecordPath->u32FileValidPeriod = 20;
    }
    {
        /* Tested function call */
        U32 _return  = MApp_TimeShift_GetRecordStartTimeSec();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _pstPvrRecordPath->u32RecordedTime/1000  + _pstPvrRecordPath->u32RecordedPeriod/10  -_pstPvrRecordPath->u32PausedPeriod/10    -_pstPvrRecordPath->u32FileValidPeriod/10, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_GetRecordStartTimeSec_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_PlaybackClose_if */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TimeShift_PlaybackClose(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_PlaybackClose_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftPlaybackState */
    {
         _enTimeShiftPlaybackState  = E_TIMESHIFT_PLAYBACK_STATE_OPEN;
    }
    /* Initializing global variable _pstPvrPlaybackPath */
    {
         _pstPvrPlaybackPath  = 0 ;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TimeShift_PlaybackClose();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_PlaybackClose_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_PlaybackClose_else */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TimeShift_PlaybackClose(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_PlaybackClose_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftPlaybackState */
    {
         _enTimeShiftPlaybackState  = E_TIMESHIFT_PLAYBACK_STATE_STOP;
    }
    /* Initializing global variable _pstPvrPlaybackPath */
    {
		int iTest1 = 10;
		_pstPvrPlaybackPath  = &iTest1 ;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TimeShift_PlaybackClose();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_TIMESHIFT_PLAYBACK_STATE_DISABLE, ( _enTimeShiftPlaybackState ) )
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_PlaybackClose_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_PlaybackDisable_if */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TimeShift_PlaybackDisable(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_PlaybackDisable_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable _enTimeShiftPlaybackSpeed */
    {
         _enTimeShiftPlaybackSpeed  = E_PLAY_SPEED_1X;
    }
    /* Initializing global variable g_u16Current_PVR_AudioPID */
    {
         g_u16Current_PVR_AudioPID  = 0u;
    }
    /* Initializing global variable _enTimeShiftPlaybackState */
    {
         _enTimeShiftPlaybackState  = E_TIMESHIFT_PLAYBACK_STATE_DISABLE;
    }
    /* Initializing global variable _pstPvrPlaybackPath */
    {
         _pstPvrPlaybackPath  = 0 ;
    }
    /* Initializing global variable g_u16Current_AudioDescriptorPID */
    {
         g_u16Current_AudioDescriptorPID  = 0u;
    }
    /* Initializing global variable g_u16Current_PCRPID */
    {
         g_u16Current_PCRPID  = 0u;
    }
    /* Initializing global variable g_u16Current_PVR_VideoPID */
    {
         g_u16Current_PVR_VideoPID  = 0u;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TimeShift_PlaybackDisable();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_TIMESHIFT_PLAYBACK_STATE_DISABLE, ( _enTimeShiftPlaybackState ) )
        CPPTEST_ASSERT_EQUAL( E_PLAY_SPEED_1X, ( _enTimeShiftPlaybackSpeed ) )
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_PlaybackDisable_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_PlaybackDisable_else */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TimeShift_PlaybackDisable(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_PlaybackDisable_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable _enTimeShiftPlaybackSpeed */
    {
         _enTimeShiftPlaybackSpeed  = E_PLAY_SPEED_1X;
    }
    /* Initializing global variable g_u16Current_PVR_AudioPID */
    {
         g_u16Current_PVR_AudioPID  = 0u;
    }
    /* Initializing global variable _enTimeShiftPlaybackState */
    {
         _enTimeShiftPlaybackState  = E_TIMESHIFT_PLAYBACK_STATE_OPEN;
    }
    /* Initializing global variable _pstPvrPlaybackPath */
    {
         _pstPvrPlaybackPath  = 0 ;
    }
    /* Initializing global variable g_u16Current_AudioDescriptorPID */
    {
         g_u16Current_AudioDescriptorPID  = 0u;
    }
    /* Initializing global variable g_u16Current_PCRPID */
    {
         g_u16Current_PCRPID  = 0u;
    }
    /* Initializing global variable g_u16Current_PVR_VideoPID */
    {
         g_u16Current_PVR_VideoPID  = 0u;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TimeShift_PlaybackDisable();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_TIMESHIFT_PLAYBACK_STATE_STOP, ( _enTimeShiftPlaybackState ) )
        CPPTEST_ASSERT_EQUAL( E_PLAY_SPEED_1X, ( _enTimeShiftPlaybackSpeed ) )
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_PlaybackDisable_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_StateMachineGet */
/* CPPTEST_TEST_CASE_CONTEXT enTimeShiftState MApp_TimeShift_StateMachineGet(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_StateMachineGet()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftState */
    {
         _enTimeShiftState  = E_TIMESHIFT_STATE_WAIT;
    }
    {
        /* Tested function call */
        enTimeShiftState _return  = MApp_TimeShift_StateMachineGet();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _enTimeShiftState, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_StateMachineGet */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_Playback_StateMachineGet */
/* CPPTEST_TEST_CASE_CONTEXT enTimeShiftPlaybackState MApp_TimeShift_Playback_StateMachineGet(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_Playback_StateMachineGet()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftPlaybackState */
    {
         _enTimeShiftPlaybackState  = E_TIMESHIFT_PLAYBACK_STATE_DISABLE;
    }
    {
        /* Tested function call */
        enTimeShiftPlaybackState _return  = MApp_TimeShift_Playback_StateMachineGet();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _enTimeShiftPlaybackState, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_Playback_StateMachineGet */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_StatusGet */
/* CPPTEST_TEST_CASE_CONTEXT enPvrApiStatus MApp_TimeShift_StatusGet(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_StatusGet()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftStatus */
    {
         _enTimeShiftStatus  = E_PVR_API_STATUS_ERROR;
    }
    {
        /* Tested function call */
        enPvrApiStatus _return  = MApp_TimeShift_StatusGet();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_PVR_API_STATUS_ERROR, ( _return ) )
        CPPTEST_ASSERT_EQUAL( E_PVR_API_STATUS_OK, ( _enTimeShiftStatus ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_StatusGet */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_RecordStopDiv_if */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_TimeShift_RecordStopDiv(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_RecordStopDiv_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable _pstPvrRecordPath */
    {
    	int iTest1 = 10;
    	_pstPvrRecordPath  = &iTest1 ;
    	_pstPvrRecordPath->u32RecordedTime  = 100 ;
    }
    /* Initializing global variable _enTimeShiftRecordState */
    {
         _enTimeShiftRecordState  = E_TIMESHIFT_RECORD_STATE_STOP;
    }
    {
        /* Tested function call */
        U32 _return  = MApp_TimeShift_RecordStopDiv();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 0, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_RecordStopDiv_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_RecordStopDiv_else */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_TimeShift_RecordStopDiv(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_RecordStopDiv_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable _pstPvrRecordPath */
    {
    	int iTest1 = 10;
    	_pstPvrRecordPath  = &iTest1 ;
    	_pstPvrRecordPath->u32RecordedTime  = 100 ;
    }
    /* Initializing global variable _enTimeShiftRecordState */
    {
         _enTimeShiftRecordState  = E_TIMESHIFT_RECORD_STATE_DISABLE;
    }
    {
        /* Tested function call */
        U32 _return  = MApp_TimeShift_RecordStopDiv();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 0, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_RecordStopDiv_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_IsRecordStoping_if */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TimeShift_IsRecordStoping(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_IsRecordStoping_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftRecordState */
    {
         _enTimeShiftRecordState  = E_TIMESHIFT_RECORD_STATE_STOP;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TimeShift_IsRecordStoping();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_IsRecordStoping_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_IsRecordStoping_else */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TimeShift_IsRecordStoping(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_IsRecordStoping_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftRecordState */
    {
         _enTimeShiftRecordState  = E_TIMESHIFT_RECORD_STATE_DISABLE;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TimeShift_IsRecordStoping();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_IsRecordStoping_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_DelTsFileName_if */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TimeShift_DelTsFileName(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_DelTsFileName_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftRecordState */
    {
         _enTimeShiftRecordState  = E_TIMESHIFT_RECORD_STATE_DISABLE;
    }
    {
        /* Tested function call */
        MApp_TimeShift_DelTsFileName();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_TIMESHIFT_RECORD_STATE_DISABLE, ( _enTimeShiftRecordState ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_DelTsFileName_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_DelTsFileName_else */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TimeShift_DelTsFileName(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_DelTsFileName_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftRecordState */
    {
         _enTimeShiftRecordState  = E_TIMESHIFT_RECORD_STATE_DISABLE;
    }
    {
        /* Tested function call */
        MApp_TimeShift_DelTsFileName();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_TIMESHIFT_RECORD_STATE_DISABLE, ( _enTimeShiftRecordState ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_DelTsFileName_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_RecordOpen_if1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TimeShift_RecordOpen(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_RecordOpen_if1()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftStatus */
    {
         _enTimeShiftStatus  = E_PVR_API_STATUS_OK;
    }
    /* Initializing global variable _pstPvrRecordPath */
    {
         _pstPvrRecordPath  = 0 ;
    }
    /* Initializing global variable _enTimeShiftRecordState */
    {
         _enTimeShiftRecordState  = E_TIMESHIFT_RECORD_STATE_OPEN;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TimeShift_RecordOpen();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_RecordOpen_if1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_RecordOpen_if2 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TimeShift_RecordOpen(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_RecordOpen_if2()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftStatus */
    {
         _enTimeShiftStatus  = E_PVR_API_STATUS_OK;
    }
    /* Initializing global variable _pstPvrRecordPath */
    {
         _pstPvrRecordPath  = 0 ;
    }
    /* Initializing global variable _enTimeShiftRecordState */
    {
         _enTimeShiftRecordState  = E_TIMESHIFT_RECORD_STATE_DISABLE;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TimeShift_RecordOpen();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_PVR_API_STATUS_NO_DISK_SPACE, ( _enTimeShiftStatus ) )
        CPPTEST_ASSERT_EQUAL( E_TIMESHIFT_RECORD_STATE_DISABLE, ( _enTimeShiftRecordState ) )
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_RecordOpen_if2 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_RecordOpen_if3 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TimeShift_RecordOpen(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_RecordOpen_if3()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftStatus */
    {
         _enTimeShiftStatus  = E_PVR_API_STATUS_OK;
    }
    /* Initializing global variable _pstPvrRecordPath */
    {
         _pstPvrRecordPath  = 0 ;
    }
    /* Initializing global variable _enTimeShiftRecordState */
    {
         _enTimeShiftRecordState  = E_TIMESHIFT_RECORD_STATE_DISABLE;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TimeShift_RecordOpen();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_TIMESHIFT_RECORD_STATE_OPEN, ( _enTimeShiftRecordState ) )
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_RecordOpen_if3 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TimeShift_RecordOpen_else3 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TimeShift_RecordOpen(void) */
void TestSuite_MApp_TimeShift_test_MApp_TimeShift_RecordOpen_else3()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enTimeShiftStatus */
    {
         _enTimeShiftStatus  = E_PVR_API_STATUS_OK;
    }
    /* Initializing global variable _pstPvrRecordPath */
    {
         _pstPvrRecordPath  = 0 ;
    }
    /* Initializing global variable _enTimeShiftRecordState */
    {
         _enTimeShiftRecordState  = E_TIMESHIFT_RECORD_STATE_DISABLE;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TimeShift_RecordOpen();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_TIMESHIFT_RECORD_STATE_DISABLE, ( _enTimeShiftRecordState ) )
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TimeShift_RecordOpen_else3 */
