#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app/MApp_Audio.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app/MApp_Audio.c");

CPPTEST_TEST_SUITE(TestSuite_MApp_Audio);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Audio_AdjustAVCThreshold_Threshold_1);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Audio_AdjustAVCThreshold_threshold_2);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Audio_AdjustAVCThreshold_out_of_bound);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Audio_AdjustPreScale_MPEG_AC3);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Audio_AdjustPreScale_HDMI);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Audio_AdjustPreScale_ATV);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Audio_AdjustPreScale_CVBS_SCART);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Audio_AdjustPreScale_PC_DVI);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Aud_AutoVolume_Init_success);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Aud_Banlace_Init_success);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Aud_PEQ_Init_success);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Aud_SetSurroundMode_OFF);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Aud_SetSurroundMode_SURROUNDMAX);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Aud_SetSurroundMode_SRS);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Aud_SetSurroundMode_VDS);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Aud_SetSurroundMode_VSPK);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Aud_SetSurroundMode_BBE);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Aud_SetTVSpeaker_speaker_on);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Aud_SetTVSpeaker_speaker_off);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Aud_SetTVSpeaker_speaker_amp);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Audio_AdjustMainVolume_volume_larger_100);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Audio_AdjustMainVolume_volume_equal_0);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Audio_SetMtsMode_success);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Audio_GetNextAvailableMtsMode_success);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Audio_AdjustSoundMode_success);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Audio_SearchAdAudio_success);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Audio_SearchAdAudio_AD_disable);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Audio_OpSearchAdAudio_ad_disable);
CPPTEST_TEST(TestSuite_MApp_Audio_test_MApp_Audio_OpSearchAdAudio_ad_enable);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_MApp_Audio_test_MApp_Audio_AdjustAVCThreshold_Threshold_1();
void TestSuite_MApp_Audio_test_MApp_Audio_AdjustAVCThreshold_threshold_2();
void TestSuite_MApp_Audio_test_MApp_Audio_AdjustAVCThreshold_out_of_bound();
void TestSuite_MApp_Audio_test_MApp_Audio_AdjustPreScale_MPEG_AC3();
void TestSuite_MApp_Audio_test_MApp_Audio_AdjustPreScale_HDMI();
void TestSuite_MApp_Audio_test_MApp_Audio_AdjustPreScale_ATV();
void TestSuite_MApp_Audio_test_MApp_Audio_AdjustPreScale_CVBS_SCART();
void TestSuite_MApp_Audio_test_MApp_Audio_AdjustPreScale_PC_DVI();
void TestSuite_MApp_Audio_test_MApp_Aud_AutoVolume_Init_success();
void TestSuite_MApp_Audio_test_MApp_Aud_Banlace_Init_success();
void TestSuite_MApp_Audio_test_MApp_Aud_PEQ_Init_success();
void TestSuite_MApp_Audio_test_MApp_Aud_SetSurroundMode_OFF();
void TestSuite_MApp_Audio_test_MApp_Aud_SetSurroundMode_SURROUNDMAX();
void TestSuite_MApp_Audio_test_MApp_Aud_SetSurroundMode_SRS();
void TestSuite_MApp_Audio_test_MApp_Aud_SetSurroundMode_VDS();
void TestSuite_MApp_Audio_test_MApp_Aud_SetSurroundMode_VSPK();
void TestSuite_MApp_Audio_test_MApp_Aud_SetSurroundMode_BBE();
void TestSuite_MApp_Audio_test_MApp_Aud_SetTVSpeaker_speaker_on();
void TestSuite_MApp_Audio_test_MApp_Aud_SetTVSpeaker_speaker_off();
void TestSuite_MApp_Audio_test_MApp_Aud_SetTVSpeaker_speaker_amp();
void TestSuite_MApp_Audio_test_MApp_Audio_AdjustMainVolume_volume_larger_100();
void TestSuite_MApp_Audio_test_MApp_Audio_AdjustMainVolume_volume_equal_0();
void TestSuite_MApp_Audio_test_MApp_Audio_SetMtsMode_success();
void TestSuite_MApp_Audio_test_MApp_Audio_GetNextAvailableMtsMode_success();
void TestSuite_MApp_Audio_test_MApp_Audio_AdjustSoundMode_success();
void TestSuite_MApp_Audio_test_MApp_Audio_SearchAdAudio_success();
void TestSuite_MApp_Audio_test_MApp_Audio_SearchAdAudio_AD_disable();
void TestSuite_MApp_Audio_test_MApp_Audio_OpSearchAdAudio_ad_disable();
void TestSuite_MApp_Audio_test_MApp_Audio_OpSearchAdAudio_ad_enable();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_MApp_Audio);

void TestSuite_MApp_Audio_setUp()
{
}

void TestSuite_MApp_Audio_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_Audio_AdjustAVCThreshold_Threshold_1 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Audio_AdjustAVCThreshold(U8) */
void TestSuite_MApp_Audio_test_MApp_Audio_AdjustAVCThreshold_Threshold_1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (InputSource) */ 
    U8 _InputSource  = E_AUDIOSOURCE_MPEG;
    {
        /* Tested function call */
        MApp_Audio_AdjustAVCThreshold(_InputSource);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Audio_AdjustAVCThreshold_Threshold_1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Audio_AdjustAVCThreshold_threshold_2 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Audio_AdjustAVCThreshold(U8) */
void TestSuite_MApp_Audio_test_MApp_Audio_AdjustAVCThreshold_threshold_2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (InputSource) */ 
    U8 _InputSource  = E_AUDIOSOURCE_SCART1;
    {
        /* Tested function call */
        MApp_Audio_AdjustAVCThreshold(_InputSource);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Audio_AdjustAVCThreshold_threshold_2 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Audio_AdjustAVCThreshold_out_of_bound */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Audio_AdjustAVCThreshold(U8) */
void TestSuite_MApp_Audio_test_MApp_Audio_AdjustAVCThreshold_out_of_bound()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (InputSource) */ 
    U8 _InputSource  = 100;
    {
        /* Tested function call */
        MApp_Audio_AdjustAVCThreshold(_InputSource);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Audio_AdjustAVCThreshold_out_of_bound */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Audio_AdjustPreScale_MPEG_AC3 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Audio_AdjustPreScale(U8) */
void TestSuite_MApp_Audio_test_MApp_Audio_AdjustPreScale_MPEG_AC3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (InputSource) */ 
    U8 _InputSource  = E_AUDIOSOURCE_MPEG;
    {
        /* Tested function call */
        MApp_Audio_AdjustPreScale(_InputSource);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Audio_AdjustPreScale_MPEG_AC3 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Audio_AdjustPreScale_HDMI */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Audio_AdjustPreScale(U8) */
void TestSuite_MApp_Audio_test_MApp_Audio_AdjustPreScale_HDMI()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (InputSource) */ 
    U8 _InputSource  = E_AUDIOSOURCE_HDMI;
    {
        /* Tested function call */
        MApp_Audio_AdjustPreScale(_InputSource);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Audio_AdjustPreScale_HDMI */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Audio_AdjustPreScale_ATV */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Audio_AdjustPreScale(U8) */
void TestSuite_MApp_Audio_test_MApp_Audio_AdjustPreScale_ATV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (InputSource) */ 
    U8 _InputSource  = E_AUDIOSOURCE_ATV;
    {
        /* Tested function call */
        MApp_Audio_AdjustPreScale(_InputSource);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Audio_AdjustPreScale_ATV */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Audio_AdjustPreScale_CVBS_SCART */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Audio_AdjustPreScale(U8) */
void TestSuite_MApp_Audio_test_MApp_Audio_AdjustPreScale_CVBS_SCART()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (InputSource) */ 
    U8 _InputSource  = E_AUDIOSOURCE_CVBS1;
    {
        /* Tested function call */
        MApp_Audio_AdjustPreScale(_InputSource);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Audio_AdjustPreScale_CVBS_SCART */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Audio_AdjustPreScale_PC_DVI */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Audio_AdjustPreScale(U8) */
void TestSuite_MApp_Audio_test_MApp_Audio_AdjustPreScale_PC_DVI()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (InputSource) */ 
    U8 _InputSource  = E_AUDIOSOURCE_PC;
    {
        /* Tested function call */
        MApp_Audio_AdjustPreScale(_InputSource);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Audio_AdjustPreScale_PC_DVI */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Aud_AutoVolume_Init_success */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Aud_AutoVolume_Init(void) */
void TestSuite_MApp_Audio_test_MApp_Aud_AutoVolume_Init_success()
{
    /* Pre-condition initialization */
    /* Initializing global variable stGenSetting */ 
    {
    	stGenSetting.g_SysSetting.fAutoVolume = 1;
    }
    {
        /* Tested function call */
        MApp_Aud_AutoVolume_Init();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Aud_AutoVolume_Init_success */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Aud_Banlace_Init_success */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Aud_Banlace_Init(void) */
void TestSuite_MApp_Audio_test_MApp_Aud_Banlace_Init_success()
{
    /* Pre-condition initialization */
    /* Initializing global variable stGenSetting */ 
    {
    	stGenSetting.g_SoundSetting.Balance = 50;
    }
    {
        /* Tested function call */
        MApp_Aud_Banlace_Init();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Aud_Banlace_Init_success */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_Aud_PEQ_Init_success */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Aud_PEQ_Init(void) */
void TestSuite_MApp_Audio_test_MApp_Aud_PEQ_Init_success()
{
    /* Pre-condition initialization */
    /* Initializing global variable stGenSetting */ 
    {
    	ST_AUDIO_PEQ.u8_PEQOnOff = 1;
    }
    {
        /* Tested function call */
        MApp_Aud_PEQ_Init();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Aud_PEQ_Init_success */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Aud_SetSurroundMode_OFF */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Aud_SetSurroundMode(U8) */
void TestSuite_MApp_Audio_test_MApp_Aud_SetSurroundMode_OFF()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8SurroundMode) */ 
    U8 _u8SurroundMode  = SURROUND_SYSTEM_OFF;
    {
        /* Tested function call */
        MApp_Aud_SetSurroundMode(_u8SurroundMode);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Aud_SetSurroundMode_OFF */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Aud_SetSurroundMode_SURROUNDMAX */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Aud_SetSurroundMode(U8) */
void TestSuite_MApp_Audio_test_MApp_Aud_SetSurroundMode_SURROUNDMAX()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8SurroundMode) */ 
    U8 _u8SurroundMode  = SURROUND_SYSTEM_SURROUNDMAX;
    {
        /* Tested function call */
        MApp_Aud_SetSurroundMode(_u8SurroundMode);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Aud_SetSurroundMode_SURROUNDMAX */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Aud_SetSurroundMode_SRS */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Aud_SetSurroundMode(U8) */
void TestSuite_MApp_Audio_test_MApp_Aud_SetSurroundMode_SRS()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8SurroundMode) */ 
    U8 _u8SurroundMode  = SURROUND_SYSTEM_SRS;
    {
        /* Tested function call */
        MApp_Aud_SetSurroundMode(_u8SurroundMode);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Aud_SetSurroundMode_SRS */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Aud_SetSurroundMode_VDS */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Aud_SetSurroundMode(U8) */
void TestSuite_MApp_Audio_test_MApp_Aud_SetSurroundMode_VDS()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8SurroundMode) */ 
    U8 _u8SurroundMode  = SURROUND_SYSTEM_VDS;
    {
        /* Tested function call */
        MApp_Aud_SetSurroundMode(_u8SurroundMode);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Aud_SetSurroundMode_VDS */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Aud_SetSurroundMode_VSPK */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Aud_SetSurroundMode(U8) */
void TestSuite_MApp_Audio_test_MApp_Aud_SetSurroundMode_VSPK()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8SurroundMode) */ 
    U8 _u8SurroundMode  = SURROUND_SYSTEM_VSPK;
    {
        /* Tested function call */
        MApp_Aud_SetSurroundMode(_u8SurroundMode);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Aud_SetSurroundMode_VSPK */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Aud_SetSurroundMode_BBE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Aud_SetSurroundMode(U8) */
void TestSuite_MApp_Audio_test_MApp_Aud_SetSurroundMode_BBE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8SurroundMode) */ 
    U8 _u8SurroundMode  = SURROUND_SYSTEM_BBE;
    {
        /* Tested function call */
        MApp_Aud_SetSurroundMode(_u8SurroundMode);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Aud_SetSurroundMode_BBE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Aud_SetTVSpeaker_speaker_on */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Aud_SetTVSpeaker(void) */
void TestSuite_MApp_Audio_test_MApp_Aud_SetTVSpeaker_speaker_on()
{
    /* Pre-condition initialization */
    /* Initializing global variable stGenSetting */ 
    {
    	stGenSetting.g_SoundSetting.TVspeakerMode = TVspeaker_Mode_IntSpeaker;
    }
    {
        /* Tested function call */
        MApp_Aud_SetTVSpeaker();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Aud_SetTVSpeaker_speaker_on */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Aud_SetTVSpeaker_speaker_off */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Aud_SetTVSpeaker(void) */
void TestSuite_MApp_Audio_test_MApp_Aud_SetTVSpeaker_speaker_off()
{
    /* Pre-condition initialization */
    /* Initializing global variable stGenSetting */ 
    {
    	stGenSetting.g_SoundSetting.TVspeakerMode = TVspeaker_Mode_ExtAmp;//TVspeaker_Mode_Off;
    }
    {
        /* Tested function call */
        MApp_Aud_SetTVSpeaker();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Aud_SetTVSpeaker_speaker_off */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Aud_SetTVSpeaker_speaker_amp */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Aud_SetTVSpeaker(void) */
void TestSuite_MApp_Audio_test_MApp_Aud_SetTVSpeaker_speaker_amp()
{
    /* Pre-condition initialization */
    /* Initializing global variable stGenSetting */ 
    {
    	stGenSetting.g_SoundSetting.TVspeakerMode = TVspeaker_Mode_ExtAmp;
    }
    {
        /* Tested function call */
        MApp_Aud_SetTVSpeaker();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Aud_SetTVSpeaker_speaker_amp */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Audio_AdjustMainVolume_volume_larger_100 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Audio_AdjustMainVolume(BYTE) */
void TestSuite_MApp_Audio_test_MApp_Audio_AdjustMainVolume_volume_larger_100()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (VolumePercent) */ 
    BYTE _VolumePercent  = 200;
    {
        /* Tested function call */
        MApp_Audio_AdjustMainVolume(_VolumePercent);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Audio_AdjustMainVolume_volume_larger_100 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Audio_AdjustMainVolume_volume_equal_0 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Audio_AdjustMainVolume(BYTE) */
void TestSuite_MApp_Audio_test_MApp_Audio_AdjustMainVolume_volume_equal_0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (VolumePercent) */ 
    BYTE _VolumePercent  = 0;
    {
        /* Tested function call */
        MApp_Audio_AdjustMainVolume(_VolumePercent);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Audio_AdjustMainVolume_volume_equal_0 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Audio_SetMtsMode_success */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Audio_SetMtsMode(void) */
void TestSuite_MApp_Audio_test_MApp_Audio_SetMtsMode_success()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_Audio_SetMtsMode();
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Audio_SetMtsMode_success */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Audio_GetNextAvailableMtsMode_success */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Audio_GetNextAvailableMtsMode(void) */
void TestSuite_MApp_Audio_test_MApp_Audio_GetNextAvailableMtsMode_success()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_Audio_GetNextAvailableMtsMode();
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Audio_GetNextAvailableMtsMode_success */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Audio_AdjustSoundMode_success */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Audio_AdjustSoundMode(void) */
void TestSuite_MApp_Audio_test_MApp_Audio_AdjustSoundMode_success()
{
    /* Pre-condition initialization */
    /* Initializing global variable stGenSetting */ 
    {

    }
    {
        /* Tested function call */
        MApp_Audio_AdjustSoundMode();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Audio_AdjustSoundMode_success */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Audio_SearchAdAudio_success */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Audio_SearchAdAudio(void) */
void TestSuite_MApp_Audio_test_MApp_Audio_SearchAdAudio_success()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_u8AudLangSelected */ 
    {
         g_u8AudLangSelected  = 0;
    }
    /* Initializing global variable stGenSetting */ 
    {
		stGenSetting.g_SoundSetting.bEnableAD = TRUE;
    }
    /* Initializing global variable g_u8AdAudSelected */ 
    {
         g_u8AdAudSelected  = 0;
    }
    {
        /* Tested function call */
        MApp_Audio_SearchAdAudio();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 g_u8AudLangSelected", ( g_u8AudLangSelected ));
        //CPPTEST_POST_CONDITION_UINTEGER("U8 g_u8AdAudSelected", ( g_u8AdAudSelected ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Audio_SearchAdAudio_success */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Audio_SearchAdAudio_AD_disable */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Audio_SearchAdAudio(void) */
void TestSuite_MApp_Audio_test_MApp_Audio_SearchAdAudio_AD_disable()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_u8AudLangSelected */ 
    {
         g_u8AudLangSelected  = 0;
    }
    /* Initializing global variable stGenSetting */ 
    {
		stGenSetting.g_SoundSetting.bEnableAD = FALSE;
    }
    /* Initializing global variable g_u8AdAudSelected */ 
    {
         g_u8AdAudSelected  = 0;
    }
    {
        /* Tested function call */
        MApp_Audio_SearchAdAudio();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Audio_SearchAdAudio_AD_disable */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Audio_OpSearchAdAudio_ad_disable */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Audio_OpSearchAdAudio(void) */
void TestSuite_MApp_Audio_test_MApp_Audio_OpSearchAdAudio_ad_disable()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_u8AudLangSelected */ 
    {
         g_u8AudLangSelected  = 0;
    }
    /* Initializing global variable stGenSetting */ 
    {
		stGenSetting.g_SoundSetting.bEnableAD = FALSE;
    }
    /* Initializing global variable g_u8AdAudSelected */ 
    {
         g_u8AdAudSelected  = 0;
    }
    {
        /* Tested function call */
        MApp_Audio_OpSearchAdAudio();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 g_u8AudLangSelected", ( g_u8AudLangSelected ));
        //CPPTEST_POST_CONDITION_UINTEGER("U8 g_u8AdAudSelected", ( g_u8AdAudSelected ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Audio_OpSearchAdAudio_ad_disable */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Audio_OpSearchAdAudio_ad_enable */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Audio_OpSearchAdAudio(void) */
void TestSuite_MApp_Audio_test_MApp_Audio_OpSearchAdAudio_ad_enable()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_u8AudLangSelected */ 
    {
         g_u8AudLangSelected  = 0;
    }
    /* Initializing global variable stGenSetting */ 
    {
	stGenSetting.g_SoundSetting.bEnableAD = TRUE;
    }
    /* Initializing global variable g_u8AdAudSelected */ 
    {
         g_u8AdAudSelected  = 0;
    }
    {
        /* Tested function call */
        MApp_Audio_OpSearchAdAudio();
        /* Post-condition check */
        //PPTEST_POST_CONDITION_UINTEGER("U8 g_u8AudLangSelected", ( g_u8AudLangSelected ));
        //CPPTEST_POST_CONDITION_UINTEGER("U8 g_u8AdAudSelected", ( g_u8AdAudSelected ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Audio_OpSearchAdAudio_ad_enable */
