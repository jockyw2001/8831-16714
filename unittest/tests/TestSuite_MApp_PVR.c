#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app/MApp_PVR.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app/MApp_PVR.c");

CPPTEST_TEST_SUITE(TestSuite_MApp_PVR);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_DiskFormatGetCreateFilePercentage);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_DiskFormatGetPercentage_if);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_DiskFormatGetPercentage_else);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_DiskGetAvailableSizeMB_if);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_DiskGetAvailableSizeMB_else);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_DiskCheckSpeed);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_StateMachineInput);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_StateMachineGet);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_StatusGet);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_RecordAudioAddServices);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_RecordSubtitleAddServices);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_PlaybackAdAudioSelectLanguage_if);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_PlaybackAdAudioSelectLanguage_elseif);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_PlaybackAdAudioStopLanguage_if);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_PlaybackAdAudioStopLanguage_elseif);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_PlaybackAudioSelectLanguage_if);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_PlaybackAudioSelectLanguage_elseif);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_PlaybackAudioStopLanguage_if);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_PlaybackAudioStopLanguage_elseif);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_PlaybackSubtitleLoadServices_if);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_PlaybackSubtitleLoadServices_elseif);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_PlaybackSubtitleLoadMenu_if);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_PlaybackSubtitleLoadMenu_elseif);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_PlaybackGetTTXSubtitleNum_if);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_PlaybackGetTTXSubtitleNum_elseif);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_DiskSetSpeed_Yes);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_DiskSetSpeed_No);
CPPTEST_TEST(TestSuite_MApp_PVR_test_MApp_PVR_DiskGetSpeed_If1);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_MApp_PVR_test_MApp_PVR_DiskFormatGetCreateFilePercentage();
void TestSuite_MApp_PVR_test_MApp_PVR_DiskFormatGetPercentage_if();
void TestSuite_MApp_PVR_test_MApp_PVR_DiskFormatGetPercentage_else();
void TestSuite_MApp_PVR_test_MApp_PVR_DiskGetAvailableSizeMB_if();
void TestSuite_MApp_PVR_test_MApp_PVR_DiskGetAvailableSizeMB_else();
void TestSuite_MApp_PVR_test_MApp_PVR_DiskCheckSpeed();
void TestSuite_MApp_PVR_test_MApp_PVR_StateMachineInput();
void TestSuite_MApp_PVR_test_MApp_PVR_StateMachineGet();
void TestSuite_MApp_PVR_test_MApp_PVR_StatusGet();
void TestSuite_MApp_PVR_test_MApp_PVR_RecordAudioAddServices();
void TestSuite_MApp_PVR_test_MApp_PVR_RecordSubtitleAddServices();
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackAdAudioSelectLanguage_if();
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackAdAudioSelectLanguage_elseif();
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackAdAudioStopLanguage_if();
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackAdAudioStopLanguage_elseif();
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackAudioSelectLanguage_if();
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackAudioSelectLanguage_elseif();
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackAudioStopLanguage_if();
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackAudioStopLanguage_elseif();
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackSubtitleLoadServices_if();
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackSubtitleLoadServices_elseif();
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackSubtitleLoadMenu_if();
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackSubtitleLoadMenu_elseif();
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackGetTTXSubtitleNum_if();
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackGetTTXSubtitleNum_elseif();
void TestSuite_MApp_PVR_test_MApp_PVR_DiskSetSpeed_Yes();
void TestSuite_MApp_PVR_test_MApp_PVR_DiskSetSpeed_No();
void TestSuite_MApp_PVR_test_MApp_PVR_DiskGetSpeed_If1();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_MApp_PVR);

void TestSuite_MApp_PVR_setUp()
{
}

void TestSuite_MApp_PVR_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_DiskFormatGetCreateFilePercentage */
/* CPPTEST_TEST_CASE_CONTEXT U8 MApp_PVR_DiskFormatGetCreateFilePercentage(void) */
void TestSuite_MApp_PVR_test_MApp_PVR_DiskFormatGetCreateFilePercentage()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        U8 _return  = MApp_PVR_DiskFormatGetCreateFilePercentage();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_DiskFormatGetCreateFilePercentage */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_DiskFormatGetPercentage_if */
/* CPPTEST_TEST_CASE_CONTEXT U8 MApp_PVR_DiskFormatGetPercentage(void) */
void TestSuite_MApp_PVR_test_MApp_PVR_DiskFormatGetPercentage_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable _u32WriteSectorCount */ 
    {
         _u32WriteSectorCount  = 0ul;
    }
    {
        /* Tested function call */
        U8 _return  = MApp_PVR_DiskFormatGetPercentage();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_DiskFormatGetPercentage_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_DiskFormatGetPercentage_else */
/* CPPTEST_TEST_CASE_CONTEXT U8 MApp_PVR_DiskFormatGetPercentage(void) */
void TestSuite_MApp_PVR_test_MApp_PVR_DiskFormatGetPercentage_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable _u32WriteSectorCount */ 
    {
         _u32WriteSectorCount  = 0ul;
    }
    {
        /* Tested function call */
        U8 _return  = MApp_PVR_DiskFormatGetPercentage();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_DiskFormatGetPercentage_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_DiskGetAvailableSizeMB_if */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_PVR_DiskGetAvailableSizeMB(void) */
void TestSuite_MApp_PVR_test_MApp_PVR_DiskGetAvailableSizeMB_if()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        U32 _return  = MApp_PVR_DiskGetAvailableSizeMB();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_DiskGetAvailableSizeMB_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_DiskGetAvailableSizeMB_else */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_PVR_DiskGetAvailableSizeMB(void) */
void TestSuite_MApp_PVR_test_MApp_PVR_DiskGetAvailableSizeMB_else()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        U32 _return  = MApp_PVR_DiskGetAvailableSizeMB();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_DiskGetAvailableSizeMB_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_DiskCheckSpeed */
/* CPPTEST_TEST_CASE_CONTEXT U16 MApp_PVR_DiskCheckSpeed(void) */
void TestSuite_MApp_PVR_test_MApp_PVR_DiskCheckSpeed()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        U16 _return  = MApp_PVR_DiskCheckSpeed();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_DiskCheckSpeed */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_StateMachineInput */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_PVR_StateMachineInput(enPVRInput, U32) */
void TestSuite_MApp_PVR_test_MApp_PVR_StateMachineInput()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSMInput) */ 
    enPVRInput _enSMInput  = E_PVR_INPUT_NONE;
    /* Initializing argument 2 (u32ExtParameter) */ 
    U32 _u32ExtParameter  = 0ul;
    /* Initializing global variable _enPVRStatus */ 
    {
         _enPVRStatus  = E_PVR_API_STATUS_OK;
    }
    /* Initializing global variable _u32PVRExtPara */ 
    {
         _u32PVRExtPara  = 0ul;
    }
    /* Initializing global variable bIsURIBlock */ 
    {
         bIsURIBlock  = 0;
    }
    /* Initializing global variable _enPVRInput */ 
    {
         _enPVRInput  = E_PVR_INPUT_NONE;
    }
    /* Initializing global variable _u8USBResetCounter */ 
    {
         _u8USBResetCounter  = 0;
    }
    /* Initializing global variable _enPVRState */ 
    {
         _enPVRState  = E_PVR_STATE_IDLE;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 0;
    }
    {
        /* Tested function call */
        MApp_PVR_StateMachineInput(_enSMInput, _u32ExtParameter);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _enSMInput, ( _enPVRInput ) );
        CPPTEST_ASSERT_EQUAL( _u32ExtParameter, ( _u32PVRExtPara ) );
        CPPTEST_ASSERT_EQUAL( E_PVR_INPUT_NONE, ( _enPVRInput ) );
        CPPTEST_ASSERT_EQUAL( 0, ( _u32PVRExtPara ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_StateMachineInput */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_StateMachineGet */
/* CPPTEST_TEST_CASE_CONTEXT enPVRState MApp_PVR_StateMachineGet(void) */
void TestSuite_MApp_PVR_test_MApp_PVR_StateMachineGet()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enPVRState */ 
    {
         _enPVRState  = E_PVR_STATE_IDLE;
    }
    {
        /* Tested function call */
        enPVRState _return  = MApp_PVR_StateMachineGet();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _enPVRState, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_StateMachineGet */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_StatusGet */
/* CPPTEST_TEST_CASE_CONTEXT enPvrApiStatus MApp_PVR_StatusGet(void) */
void TestSuite_MApp_PVR_test_MApp_PVR_StatusGet()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enPVRStatus */ 
    {
         _enPVRStatus  = E_PVR_API_STATUS_OK;
    }
    {
        /* Tested function call */
        enPvrApiStatus _return  = MApp_PVR_StatusGet();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _enPVRStatus, ( _return ) )
        CPPTEST_ASSERT_EQUAL( E_PVR_API_STATUS_OK, ( _enPVRStatus ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_StatusGet */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_RecordAudioAddServices */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_PVR_RecordAudioAddServices(U8, U8, U8) */
void TestSuite_MApp_PVR_test_MApp_PVR_RecordAudioAddServices()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8PathNum) */ 
    U8 _u8PathNum  = 0;
    /* Initializing argument 2 (u8Idx) */ 
    U8 _u8Idx  = 0;
    /* Initializing argument 3 (u8Num) */ 
    U8 _u8Num  = 0;
    {
        /* Tested function call */
        MApp_PVR_RecordAudioAddServices(_u8PathNum, _u8Idx, _u8Num);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_RecordAudioAddServices */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_RecordSubtitleAddServices */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_PVR_RecordSubtitleAddServices(U8, U8, U8, DVB_SUBTITLE_SERVICE *) */
void TestSuite_MApp_PVR_test_MApp_PVR_RecordSubtitleAddServices()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8PathNum) */ 
    U8 _u8PathNum  = 0;
    /* Initializing argument 2 (u8Idx) */ 
    U8 _u8Idx  = 0;
    /* Initializing argument 3 (u8Num) */ 
    U8 _u8Num  = 0;
    /* Initializing argument 4 (pSubtitleServices) */ 
    DVB_SUBTITLE_SERVICE * _pSubtitleServices  = 0 ;
    {
        /* Tested function call */
        MApp_PVR_RecordSubtitleAddServices(_u8PathNum, _u8Idx, _u8Num, _pSubtitleServices);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_PTR("DVB_SUBTITLE_SERVICE * _pSubtitleServices ", ( _pSubtitleServices ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_RecordSubtitleAddServices */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_PlaybackAdAudioSelectLanguage_if */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_PVR_PlaybackAdAudioSelectLanguage(U8) */
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackAdAudioSelectLanguage_if()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8AudSelectedIndex) */ 
    U8 _u8AudSelectedIndex  = 0;
    /* Initializing global variable _enPVRState */ 
    {
         _enPVRState  = E_PVR_STATE_PLAYBACK;
    }
    {
        /* Tested function call */
    	MApp_PVR_PlaybackAdAudioSelectLanguage(_u8AudSelectedIndex);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_PlaybackAdAudioSelectLanguage_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_PlaybackAdAudioSelectLanguage_elseif */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_PVR_PlaybackAdAudioSelectLanguage(U8) */
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackAdAudioSelectLanguage_elseif()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8AudSelectedIndex) */ 
    U8 _u8AudSelectedIndex  = 0;
    /* Initializing global variable _enPVRState */ 
    {
         _enPVRState  = E_PVR_STATE_TIMESHIFT;
    }
    {
        /* Tested function call */
        MApp_PVR_PlaybackAdAudioSelectLanguage(_u8AudSelectedIndex);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_PlaybackAdAudioSelectLanguage_elseif */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_PlaybackAdAudioStopLanguage_if */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_PVR_PlaybackAdAudioStopLanguage(U8) */
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackAdAudioStopLanguage_if()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8AudSelectedIndex) */ 
    U8 _u8AudSelectedIndex  = 0;
    /* Initializing global variable _enPVRState */ 
    {
         _enPVRState  = E_PVR_STATE_PLAYBACK;
    }
    {
        /* Tested function call */
        MApp_PVR_PlaybackAdAudioStopLanguage(_u8AudSelectedIndex);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_PlaybackAdAudioStopLanguage_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_PlaybackAdAudioStopLanguage_elseif */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_PVR_PlaybackAdAudioStopLanguage(U8) */
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackAdAudioStopLanguage_elseif()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8AudSelectedIndex) */ 
    U8 _u8AudSelectedIndex  = 0;
    /* Initializing global variable _enPVRState */ 
    {
         _enPVRState  = E_PVR_STATE_TIMESHIFT;
    }
    {
        /* Tested function call */
        MApp_PVR_PlaybackAdAudioStopLanguage(_u8AudSelectedIndex);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_PlaybackAdAudioStopLanguage_elseif */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_PlaybackAudioSelectLanguage_if */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_PVR_PlaybackAudioSelectLanguage(U8) */
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackAudioSelectLanguage_if()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8AudSelectedIndex) */
    U8 _u8AudSelectedIndex  = 0;
    /* Initializing global variable _enPVRState */
    {
         _enPVRState  = E_PVR_STATE_PLAYBACK;
    }
    {
        /* Tested function call */
    	MApp_PVR_PlaybackAudioSelectLanguage(_u8AudSelectedIndex);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_PlaybackAudioSelectLanguage_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_PlaybackAudioSelectLanguage_elseif */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_PVR_PlaybackAudioSelectLanguage(U8) */
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackAudioSelectLanguage_elseif()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8AudSelectedIndex) */
    U8 _u8AudSelectedIndex  = 0;
    /* Initializing global variable _enPVRState */
    {
         _enPVRState  = E_PVR_STATE_TIMESHIFT;
    }
    {
        /* Tested function call */
        MApp_PVR_PlaybackAudioSelectLanguage(_u8AudSelectedIndex);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_PlaybackAudioSelectLanguage_elseif */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_PlaybackAudioStopLanguage_if */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_PVR_PlaybackAudioStopLanguage(U8) */
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackAudioStopLanguage_if()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8AudSelectedIndex) */
    U8 _u8AudSelectedIndex  = 0;
    /* Initializing global variable _enPVRState */
    {
         _enPVRState  = E_PVR_STATE_PLAYBACK;
    }
    {
        /* Tested function call */
        MApp_PVR_PlaybackAudioStopLanguage(_u8AudSelectedIndex);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_PlaybackAudioStopLanguage_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_PlaybackAudioStopLanguage_elseif */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_PVR_PlaybackAudioStopLanguage(U8) */
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackAudioStopLanguage_elseif()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8AudSelectedIndex) */
    U8 _u8AudSelectedIndex  = 0;
    /* Initializing global variable _enPVRState */
    {
         _enPVRState  = E_PVR_STATE_TIMESHIFT;
    }
    {
        /* Tested function call */
        MApp_PVR_PlaybackAudioStopLanguage(_u8AudSelectedIndex);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_PlaybackAudioStopLanguage_elseif */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_PlaybackSubtitleLoadServices_if */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_PVR_PlaybackSubtitleLoadServices(U8 *, U8 *, DVB_SUBTITLE_SERVICE *) */
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackSubtitleLoadServices_if()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8SelIdx) */ 
    U8 _pu8SelIdx;
    /* Initializing argument 2 (pu8Num) */ 
    U8 _pu8Num ;
    /* Initializing argument 3 (pSubtitleServices) */ 
    DVB_SUBTITLE_SERVICE _pSubtitleServices;
    {
        /* Tested function call */
        MApp_PVR_PlaybackSubtitleLoadServices(&_pu8SelIdx, &_pu8Num, &_pSubtitleServices);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_PlaybackSubtitleLoadServices_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_PlaybackSubtitleLoadServices_elseif */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_PVR_PlaybackSubtitleLoadServices(U8 *, U8 *, DVB_SUBTITLE_SERVICE *) */
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackSubtitleLoadServices_elseif()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8SelIdx) */ 
    U8 _pu8SelIdx;
    /* Initializing argument 2 (pu8Num) */ 
    U8 _pu8Num ;
    /* Initializing argument 3 (pSubtitleServices) */ 
    DVB_SUBTITLE_SERVICE _pSubtitleServices;
    {
        /* Tested function call */
        MApp_PVR_PlaybackSubtitleLoadServices(&_pu8SelIdx, &_pu8Num, &_pSubtitleServices);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_PlaybackSubtitleLoadServices_elseif */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_PlaybackSubtitleLoadMenu_if */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_PVR_PlaybackSubtitleLoadMenu(U8 *, U8 *, SUBTITLE_MENU *, U8 *, U8 *) */
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackSubtitleLoadMenu_if()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8SelIdx) */ 
    U8 _pu8SelIdx;
    /* Initializing argument 2 (pu8Num) */ 
    U8 _pu8Num;
    /* Initializing argument 3 (pSubtitleServices) */ 
    SUBTITLE_MENU _pSubtitleServices;
    /* Initializing argument 4 (pu8fEnableSubtitle) */ 
    U8 _pu8fEnableSubtitle;
    /* Initializing argument 5 (pu8fEnableTTXSubtitle) */ 
    U8 _pu8fEnableTTXSubtitle;
    {
        /* Tested function call */
        MApp_PVR_PlaybackSubtitleLoadMenu(&_pu8SelIdx, &_pu8Num, &_pSubtitleServices, &_pu8fEnableSubtitle, &_pu8fEnableTTXSubtitle);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_PlaybackSubtitleLoadMenu_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_PlaybackSubtitleLoadMenu_elseif */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_PVR_PlaybackSubtitleLoadMenu(U8 *, U8 *, SUBTITLE_MENU *, U8 *, U8 *) */
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackSubtitleLoadMenu_elseif()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8SelIdx) */ 
    U8 _pu8SelIdx;
    /* Initializing argument 2 (pu8Num) */ 
    U8 _pu8Num;
    /* Initializing argument 3 (pSubtitleServices) */ 
    SUBTITLE_MENU _pSubtitleServices;
    /* Initializing argument 4 (pu8fEnableSubtitle) */ 
    U8 _pu8fEnableSubtitle;
    /* Initializing argument 5 (pu8fEnableTTXSubtitle) */ 
    U8 _pu8fEnableTTXSubtitle;
    {
        /* Tested function call */
        MApp_PVR_PlaybackSubtitleLoadMenu(&_pu8SelIdx, &_pu8Num, &_pSubtitleServices, &_pu8fEnableSubtitle, &_pu8fEnableTTXSubtitle);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_PlaybackSubtitleLoadMenu_elseif */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_PlaybackGetTTXSubtitleNum_if */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_PVR_PlaybackGetTTXSubtitleNum(U8 *) */
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackGetTTXSubtitleNum_if()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Num) */ 
    U8 _pu8Num  = 0 ;
    {
        /* Tested function call */
        MApp_PVR_PlaybackGetTTXSubtitleNum(&_pu8Num);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_PlaybackGetTTXSubtitleNum_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_PlaybackGetTTXSubtitleNum_elseif */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_PVR_PlaybackGetTTXSubtitleNum(U8 *) */
void TestSuite_MApp_PVR_test_MApp_PVR_PlaybackGetTTXSubtitleNum_elseif()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Num) */ 
    U8 _pu8Num  = 0 ;
    {
        /* Tested function call */
        MApp_PVR_PlaybackGetTTXSubtitleNum(&_pu8Num);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_PlaybackGetTTXSubtitleNum_elseif */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_DiskSetSpeed_Yes */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_PVR_DiskSetSpeed(U16) */
void TestSuite_MApp_PVR_test_MApp_PVR_DiskSetSpeed_Yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (newSpeed) */ 
    U16 _newSpeed  = 0u;
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_PVR_DiskSetSpeed(_newSpeed);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_DiskSetSpeed_Yes */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_DiskSetSpeed_No */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_PVR_DiskSetSpeed(U16) */
void TestSuite_MApp_PVR_test_MApp_PVR_DiskSetSpeed_No()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (newSpeed) */ 
    U16 _newSpeed  = 0u;
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_PVR_DiskSetSpeed(_newSpeed);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_DiskSetSpeed_No */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PVR_DiskGetSpeed_If1 */
/* CPPTEST_TEST_CASE_CONTEXT U16 MApp_PVR_DiskGetSpeed(void) */
void TestSuite_MApp_PVR_test_MApp_PVR_DiskGetSpeed_If1()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        U16 _return  = MApp_PVR_DiskGetSpeed();
        /* Post-condition check */

    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PVR_DiskGetSpeed_If1 */

