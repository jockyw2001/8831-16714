#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app/MApp_IR.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app/MApp_IR.c");

CPPTEST_TEST_SUITE(TestSuite_MApp_IR);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_CEC_CheckRepeatKey_KEY_SELECT);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_CEC_CheckRepeatKey_KEY_YELLOW);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_CEC_CheckRepeatKey_default);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_CEC_CheckRepeatKey_KEY_VOLUME_PLUS_bSystemAudioMode_IsTrue);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_CEC_CheckRepeatKey_KEY_VOLUME_PLUS_bSystemAudioMode_IsFalse);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_CEC_CheckRepeatKey_KEY_VOLUME_MINUS_bSystemAudioMode_IsTrue);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_CEC_CheckRepeatKey_KEY_VOLUME_MINUS_bSystemAudioMode_IsFalse);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_CheckKeyStatus_msAPI_GetKeyPad_OK);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_CheckKeyStatus_msAPI_GetIRKey_OK);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_CheckKeyStatus_mbir_empty);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_CheckKeyStatus_else);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_SetKeyRepeatState_DISABLE);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_SetKeyRepeatState_KEY_UP);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_SetKeyRepeatState_KEY_DOWN);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_SetKeyRepeatState_KEY_LEFT);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_SetKeyRepeatState_KEY_RIGHT);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_Key_Initial_Status);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_GetCurrentKeyType);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_KeyIsReapeatStatus_if);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_KeyIsReapeatStatus_else);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_FillMBIR);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ClearMBIR);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_SetMBIRFlag);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_GetMBIRFlag);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_GetMBIR);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_return_g_bAutobuildDebug);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_return_g_DisableIr);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_DEFAULT);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_HOME);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_POWER);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_EXIT);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_UP);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CHANNEL_RETURN);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_DOWN);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_RIGHT);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_LEFT);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_SELECT);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_BACK);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_0);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_1);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_2);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_3);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_4);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_5);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_6);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_7);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_8);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_9);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CHANNEL_FAV_LIST);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_MUTE);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_FREEZE);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_INFO);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_AUDIO);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_MTS);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_ZOOM);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_RED);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_GREEN);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_YELLOW);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_BLUE);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_RED2);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_GREEN2);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_SUBTITLE);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_UPDATE);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_TTX_MODE);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_MIX);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CLOCK);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_TTX);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_SIZE);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_HOLD);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_INDEX);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CHANNEL_LIST);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_SLEEP);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_DASH);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_TV_INPUT);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_BACKWARD);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_FORWARD);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_PAGE_UP);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_PAGE_DOWN);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_PREVIOUS);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NEXT);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CC);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_MENU);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_ADJUST);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_KEY_DISABLE_KEYPAD);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_REVEAL);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_RECORD);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_STOP);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_PLAY);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_PAUSE);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_SUBPAGE);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_DTV);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_TV);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_SCART);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_HDMI);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_AV);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_PC);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_COMPONENT);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_SV);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_isKeypadSourceKeyCanSelect_success);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_isKeypadUPLR_TRUE);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_isKeypadUPLR_FALSE);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_if_case_DEFAULT);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_if_case_KEY_SUBCODE);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_if_case_KEY_FF);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_if_case_KEY_REWIND);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_if_case_KEY_PREVIOUS);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_if_case_KEY_NEXT);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_EPG);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_PICTURE);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CHANNEL_PLUS_if);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CHANNEL_PLUS_else);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CHANNEL_MINUS_if);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CHANNEL_MINUS_else);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_VOLUME_PLUS_if);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_VOLUME_PLUS_else);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_VOLUME_MINUS_if);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_VOLUME_MINUS_else);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_INPUT_SOURCE_if);
CPPTEST_TEST(TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_INPUT_SOURCE_else);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_MApp_IR_test_MApp_CEC_CheckRepeatKey_KEY_SELECT();
void TestSuite_MApp_IR_test_MApp_CEC_CheckRepeatKey_KEY_YELLOW();
void TestSuite_MApp_IR_test_MApp_CEC_CheckRepeatKey_default();
void TestSuite_MApp_IR_test_MApp_CEC_CheckRepeatKey_KEY_VOLUME_PLUS_bSystemAudioMode_IsTrue();
void TestSuite_MApp_IR_test_MApp_CEC_CheckRepeatKey_KEY_VOLUME_PLUS_bSystemAudioMode_IsFalse();
void TestSuite_MApp_IR_test_MApp_CEC_CheckRepeatKey_KEY_VOLUME_MINUS_bSystemAudioMode_IsTrue();
void TestSuite_MApp_IR_test_MApp_CEC_CheckRepeatKey_KEY_VOLUME_MINUS_bSystemAudioMode_IsFalse();
void TestSuite_MApp_IR_test_MApp_CheckKeyStatus_msAPI_GetKeyPad_OK();
void TestSuite_MApp_IR_test_MApp_CheckKeyStatus_msAPI_GetIRKey_OK();
void TestSuite_MApp_IR_test_MApp_CheckKeyStatus_mbir_empty();
void TestSuite_MApp_IR_test_MApp_CheckKeyStatus_else();
void TestSuite_MApp_IR_test_MApp_SetKeyRepeatState_DISABLE();
void TestSuite_MApp_IR_test_MApp_SetKeyRepeatState_KEY_UP();
void TestSuite_MApp_IR_test_MApp_SetKeyRepeatState_KEY_DOWN();
void TestSuite_MApp_IR_test_MApp_SetKeyRepeatState_KEY_LEFT();
void TestSuite_MApp_IR_test_MApp_SetKeyRepeatState_KEY_RIGHT();
void TestSuite_MApp_IR_test_MApp_Key_Initial_Status();
void TestSuite_MApp_IR_test_MApp_GetCurrentKeyType();
void TestSuite_MApp_IR_test_MApp_KeyIsReapeatStatus_if();
void TestSuite_MApp_IR_test_MApp_KeyIsReapeatStatus_else();
void TestSuite_MApp_IR_test_MApp_FillMBIR();
void TestSuite_MApp_IR_test_MApp_ClearMBIR();
void TestSuite_MApp_IR_test_MApp_SetMBIRFlag();
void TestSuite_MApp_IR_test_MApp_GetMBIRFlag();
void TestSuite_MApp_IR_test_MApp_GetMBIR();
void TestSuite_MApp_IR_test_MApp_ParseKey_return_g_bAutobuildDebug();
void TestSuite_MApp_IR_test_MApp_ParseKey_return_g_DisableIr();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_DEFAULT();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_HOME();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_POWER();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_EXIT();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_UP();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CHANNEL_RETURN();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_DOWN();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_RIGHT();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_LEFT();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_SELECT();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_BACK();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_0();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_1();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_2();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_3();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_4();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_5();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_6();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_7();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_8();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_9();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CHANNEL_FAV_LIST();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_MUTE();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_FREEZE();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_INFO();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_AUDIO();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_MTS();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_ZOOM();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_RED();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_GREEN();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_YELLOW();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_BLUE();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_RED2();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_GREEN2();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_SUBTITLE();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_UPDATE();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_TTX_MODE();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_MIX();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CLOCK();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_TTX();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_SIZE();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_HOLD();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_INDEX();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CHANNEL_LIST();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_SLEEP();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_DASH();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_TV_INPUT();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_BACKWARD();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_FORWARD();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_PAGE_UP();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_PAGE_DOWN();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_PREVIOUS();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NEXT();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CC();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_MENU();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_ADJUST();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_KEY_DISABLE_KEYPAD();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_REVEAL();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_RECORD();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_STOP();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_PLAY();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_PAUSE();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_SUBPAGE();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_DTV();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_TV();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_SCART();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_HDMI();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_AV();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_PC();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_COMPONENT();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_SV();
void TestSuite_MApp_IR_test_MApp_isKeypadSourceKeyCanSelect_success();
void TestSuite_MApp_IR_test_MApp_isKeypadUPLR_TRUE();
void TestSuite_MApp_IR_test_MApp_isKeypadUPLR_FALSE();
void TestSuite_MApp_IR_test_MApp_ParseKey_if_case_DEFAULT();
void TestSuite_MApp_IR_test_MApp_ParseKey_if_case_KEY_SUBCODE();
void TestSuite_MApp_IR_test_MApp_ParseKey_if_case_KEY_FF();
void TestSuite_MApp_IR_test_MApp_ParseKey_if_case_KEY_REWIND();
void TestSuite_MApp_IR_test_MApp_ParseKey_if_case_KEY_PREVIOUS();
void TestSuite_MApp_IR_test_MApp_ParseKey_if_case_KEY_NEXT();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_EPG();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_PICTURE();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CHANNEL_PLUS_if();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CHANNEL_PLUS_else();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CHANNEL_MINUS_if();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CHANNEL_MINUS_else();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_VOLUME_PLUS_if();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_VOLUME_PLUS_else();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_VOLUME_MINUS_if();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_VOLUME_MINUS_else();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_INPUT_SOURCE_if();
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_INPUT_SOURCE_else();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_MApp_IR);

void TestSuite_MApp_IR_setUp()
{
}

void TestSuite_MApp_IR_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_CEC_CheckRepeatKey_KEY_SELECT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_CEC_CheckRepeatKey(void) */
void TestSuite_MApp_IR_test_MApp_CEC_CheckRepeatKey_KEY_SELECT()
{
    /* Pre-condition initialization */
    /* Initializing global variable stKeyStatus */ 
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = 0;
    }
    /* Initializing global variable u8KeyCode */ 
    {
         u8KeyCode  = KEY_SELECT;
    }
    {
        /* Tested function call */
        MApp_CEC_CheckRepeatKey();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( stKeyStatus.RepeatEnable ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CEC_CheckRepeatKey_KEY_SELECT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CEC_CheckRepeatKey_KEY_YELLOW */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_CEC_CheckRepeatKey(void) */
void TestSuite_MApp_IR_test_MApp_CEC_CheckRepeatKey_KEY_YELLOW()
{
    /* Pre-condition initialization */
    /* Initializing global variable stKeyStatus */ 
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = 0;
    }
    /* Initializing global variable u8KeyCode */ 
    {
         u8KeyCode  = KEY_YELLOW;
    }
    {
        /* Tested function call */
        MApp_CEC_CheckRepeatKey();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( stKeyStatus.RepeatEnable ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CEC_CheckRepeatKey_KEY_YELLOW */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CEC_CheckRepeatKey_default */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_CEC_CheckRepeatKey(void) */
void TestSuite_MApp_IR_test_MApp_CEC_CheckRepeatKey_default()
{
    /* Pre-condition initialization */
    /* Initializing global variable stKeyStatus */ 
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = 0;
    }
    /* Initializing global variable u8KeyCode */ 
    {
         u8KeyCode  = KEY_EXIT;
    }
    {
        /* Tested function call */
        MApp_CEC_CheckRepeatKey();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( stKeyStatus.RepeatEnable ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CEC_CheckRepeatKey_default */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CEC_CheckRepeatKey_KEY_VOLUME_PLUS_bSystemAudioMode_IsTrue */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_CEC_CheckRepeatKey(void) */
void TestSuite_MApp_IR_test_MApp_CEC_CheckRepeatKey_KEY_VOLUME_PLUS_bSystemAudioMode_IsTrue()
{
    /* Pre-condition initialization */
    /* Initializing global variable stKeyStatus */ 
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = 0;
    }
    /* Initializing global variable u8KeyCode */ 
    {
         u8KeyCode  = KEY_VOLUME_PLUS;
    }
    {
        /* Tested function call */
        MApp_CEC_CheckRepeatKey();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( stKeyStatus.RepeatEnable ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CEC_CheckRepeatKey_KEY_VOLUME_PLUS_bSystemAudioMode_IsTrue */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CEC_CheckRepeatKey_KEY_VOLUME_PLUS_bSystemAudioMode_IsFalse */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_CEC_CheckRepeatKey(void) */
void TestSuite_MApp_IR_test_MApp_CEC_CheckRepeatKey_KEY_VOLUME_PLUS_bSystemAudioMode_IsFalse()
{
    /* Pre-condition initialization */
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = 0;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_VOLUME_PLUS;
    }
    {
        /* Tested function call */
        MApp_CEC_CheckRepeatKey();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( stKeyStatus.RepeatEnable ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CEC_CheckRepeatKey_KEY_VOLUME_PLUS_bSystemAudioMode_IsFalse */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CEC_CheckRepeatKey_KEY_VOLUME_MINUS_bSystemAudioMode_IsTrue */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_CEC_CheckRepeatKey(void) */
void TestSuite_MApp_IR_test_MApp_CEC_CheckRepeatKey_KEY_VOLUME_MINUS_bSystemAudioMode_IsTrue()
{
    /* Pre-condition initialization */
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = 0;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_VOLUME_MINUS;
    }
    {
        /* Tested function call */
        MApp_CEC_CheckRepeatKey();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( stKeyStatus.RepeatEnable ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CEC_CheckRepeatKey_KEY_VOLUME_MINUS_bSystemAudioMode_IsTrue */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CEC_CheckRepeatKey_KEY_VOLUME_MINUS_bSystemAudioMode_IsFalse */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_CEC_CheckRepeatKey(void) */
void TestSuite_MApp_IR_test_MApp_CEC_CheckRepeatKey_KEY_VOLUME_MINUS_bSystemAudioMode_IsFalse()
{
    /* Pre-condition initialization */
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = 0;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_VOLUME_MINUS;
    }
    {
        /* Tested function call */
        MApp_CEC_CheckRepeatKey();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( stKeyStatus.RepeatEnable ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CEC_CheckRepeatKey_KEY_VOLUME_MINUS_bSystemAudioMode_IsFalse */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_CheckKeyStatus_msAPI_GetKeyPad_OK */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_CheckKeyStatus(void) */
void TestSuite_MApp_IR_test_MApp_CheckKeyStatus_msAPI_GetKeyPad_OK()
{
    /* Pre-condition initialization */
    U8 key;
    U8 KeyRepeatStatus;
    /* Initializing global variable mbir */ 
    {
         mbir.empty  = 0;
         mbir.keydata  = 0u;
         mbir.repeat  = 0;
         mbir.flag  = 0;
    }
    /* Initializing global variable stKeyStatus */ 
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = 0;
    }
    {
        /* Tested function call */
        MApp_CheckKeyStatus();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( stKeyStatus.keydown ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(KeyRepeatStatus, ( stKeyStatus.keyrepeat ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(KEY_TYPE_KEYPAD, ( stKeyStatus.keytype ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(key, ( stKeyStatus.keydata ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CheckKeyStatus_msAPI_GetKeyPad_OK */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CheckKeyStatus_msAPI_GetIRKey_OK */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_CheckKeyStatus(void) */
void TestSuite_MApp_IR_test_MApp_CheckKeyStatus_msAPI_GetIRKey_OK()
{
    /* Pre-condition initialization */
	U8 key;
	U8 KeyRepeatStatus;
    /* Initializing global variable mbir */ 
    {
         mbir.empty  = 0;
         mbir.keydata  = 0u;
         mbir.repeat  = 0;
         mbir.flag  = 0;
    }
    /* Initializing global variable stKeyStatus */ 
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = 0;
    }
    {
        /* Tested function call */
        MApp_CheckKeyStatus();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( stKeyStatus.keydown ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(KeyRepeatStatus, ( stKeyStatus.keyrepeat ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(KEY_TYPE_IR, ( stKeyStatus.keytype ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(key, ( stKeyStatus.keydata ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CheckKeyStatus_msAPI_GetIRKey_OK */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CheckKeyStatus_mbir_empty */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_CheckKeyStatus(void) */
void TestSuite_MApp_IR_test_MApp_CheckKeyStatus_mbir_empty()
{
    /* Pre-condition initialization */
	U8 key;
	U8 KeyRepeatStatus;
    /* Initializing global variable mbir */ 
    {
         mbir.empty  = 1;
         mbir.keydata  = 0u;
         mbir.repeat  = 0;
         mbir.flag  = 0;
    }
    /* Initializing global variable stKeyStatus */ 
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = 0;
    }
    {
        /* Tested function call */
        MApp_CheckKeyStatus();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( stKeyStatus.keydown ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( stKeyStatus.keyrepeat ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(KEY_NULL, ( stKeyStatus.keydata ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CheckKeyStatus_mbir_empty */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CheckKeyStatus_else */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_CheckKeyStatus(void) */
void TestSuite_MApp_IR_test_MApp_CheckKeyStatus_else()
{
    /* Pre-condition initialization */
	U8 key;
	U8 KeyRepeatStatus;
    /* Initializing global variable mbir */ 
    {
         mbir.empty  = 0;
         mbir.keydata  = 0u;
         mbir.repeat  = 0;
         mbir.flag  = 0;
    }
    /* Initializing global variable stKeyStatus */ 
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = 0;
    }
    {
        /* Tested function call */
        MApp_CheckKeyStatus();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( mbir.empty ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( stKeyStatus.keydown ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(mbir.repeat, ( stKeyStatus.keyrepeat ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(KEY_TYPE_IR, ( stKeyStatus.keytype ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL((U8)mbir.keydata, ( stKeyStatus.keydata ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CheckKeyStatus_else */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_SetKeyRepeatState_DISABLE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_SetKeyRepeatState(U8) */
void TestSuite_MApp_IR_test_MApp_SetKeyRepeatState_DISABLE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8KeyData) */ 
    U8 _u8KeyData  = KEY_0;
    /* Initializing global variable u8KeyRepeatState */ 
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_SetKeyRepeatState(_u8KeyData);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(OSD_REPEAT_DISABLE, ( u8KeyRepeatState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_SetKeyRepeatState_DISABLE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_SetKeyRepeatState_KEY_UP */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_SetKeyRepeatState(U8) */
void TestSuite_MApp_IR_test_MApp_SetKeyRepeatState_KEY_UP()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8KeyData) */ 
    U8 _u8KeyData  = KEY_UP;
    /* Initializing global variable u8KeyRepeatState */ 
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_SetKeyRepeatState(_u8KeyData);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(OSD_REPEAT_ENABLE, ( u8KeyRepeatState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_SetKeyRepeatState_KEY_UP */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_SetKeyRepeatState_KEY_DOWN */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_SetKeyRepeatState(U8) */
void TestSuite_MApp_IR_test_MApp_SetKeyRepeatState_KEY_DOWN()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8KeyData) */ 
    U8 _u8KeyData  = KEY_DOWN;
    /* Initializing global variable u8KeyRepeatState */ 
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_SetKeyRepeatState(_u8KeyData);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(OSD_REPEAT_ENABLE, ( u8KeyRepeatState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_SetKeyRepeatState_KEY_DOWN */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_SetKeyRepeatState_KEY_LEFT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_SetKeyRepeatState(U8) */
void TestSuite_MApp_IR_test_MApp_SetKeyRepeatState_KEY_LEFT()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8KeyData) */ 
    U8 _u8KeyData  = KEY_LEFT;
    /* Initializing global variable u8KeyRepeatState */ 
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_SetKeyRepeatState(_u8KeyData);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(OSD_REPEAT_ENABLE, ( u8KeyRepeatState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_SetKeyRepeatState_KEY_LEFT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_SetKeyRepeatState_KEY_RIGHT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_SetKeyRepeatState(U8) */
void TestSuite_MApp_IR_test_MApp_SetKeyRepeatState_KEY_RIGHT()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8KeyData) */ 
    U8 _u8KeyData  = KEY_RIGHT;
    /* Initializing global variable u8KeyRepeatState */ 
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_SetKeyRepeatState(_u8KeyData);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(OSD_REPEAT_ENABLE, ( u8KeyRepeatState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_SetKeyRepeatState_KEY_RIGHT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Key_Initial_Status */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Key_Initial_Status(void) */
void TestSuite_MApp_IR_test_MApp_Key_Initial_Status()
{
    /* Pre-condition initialization */
    /* Initializing global variable stKeyStatus */ 
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = 0;
    }
    {
        /* Tested function call */
        MApp_Key_Initial_Status();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( stKeyStatus.KeyFilterPower ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Key_Initial_Status */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetCurrentKeyType */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_GetCurrentKeyType(void) */
void TestSuite_MApp_IR_test_MApp_GetCurrentKeyType()
{
    /* Pre-condition initialization */
    /* Initializing global variable stKeyStatus */ 
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 1;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_GetCurrentKeyType();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 1, ( stKeyStatus.keytype ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_GetCurrentKeyType */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_KeyIsReapeatStatus_if */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_KeyIsReapeatStatus(void) */
void TestSuite_MApp_IR_test_MApp_KeyIsReapeatStatus_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable stKeyStatus */ 
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = TRUE;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_KeyIsReapeatStatus();
        /* Post-condition check */
        //CPPTEST_ASSERT_EQUAL( 1, ( stKeyStatus.keytype ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_KeyIsReapeatStatus_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_KeyIsReapeatStatus_else */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_KeyIsReapeatStatus(void) */
void TestSuite_MApp_IR_test_MApp_KeyIsReapeatStatus_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = FALSE;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_KeyIsReapeatStatus();
        /* Post-condition check */
        //CPPTEST_ASSERT_EQUAL( 1, ( stKeyStatus.keytype ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_KeyIsReapeatStatus_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_FillMBIR */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_FillMBIR(U8, U8) */
void TestSuite_MApp_IR_test_MApp_FillMBIR()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (keycode) */ 
    U8 _keycode  = 0x60;
    /* Initializing argument 2 (repeat) */ 
    U8 _repeat  = 1;
    /* Initializing global variable mbir */ 
    {
         mbir.empty  = 0;
         mbir.keydata  = 0u;
         mbir.repeat  = 0;
         mbir.flag  = 0;
    }
    {
        /* Tested function call */
        MApp_FillMBIR(_keycode, _repeat);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( mbir.empty ) );
        CPPTEST_ASSERT_EQUAL( _keycode, ( mbir.keydata ) );
        CPPTEST_ASSERT_EQUAL( _repeat, ( mbir.repeat ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_FillMBIR */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ClearMBIR */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ClearMBIR(void) */
void TestSuite_MApp_IR_test_MApp_ClearMBIR()
{
    /* Pre-condition initialization */
    /* Initializing global variable mbir */ 
    {
         mbir.empty  = 0;
         mbir.keydata  = 0u;
         mbir.repeat  = 0;
         mbir.flag  = 0;
    }
    {
        /* Tested function call */
        MApp_ClearMBIR();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( mbir.empty ) );
        CPPTEST_ASSERT_EQUAL( 0xFFFF, ( mbir.keydata ) );
        CPPTEST_ASSERT_EQUAL( FALSE, ( mbir.repeat ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ClearMBIR */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_SetMBIRFlag */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_SetMBIRFlag(U8) */
void TestSuite_MApp_IR_test_MApp_SetMBIRFlag()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (val) */ 
    U8 _val  = 1;
    /* Initializing global variable mbir */ 
    {
         mbir.empty  = 0;
         mbir.keydata  = 0u;
         mbir.repeat  = 0;
         mbir.flag  = 0;
    }
    {
        /* Tested function call */
        MApp_SetMBIRFlag(_val);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 1, ( mbir.flag ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_SetMBIRFlag */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetMBIRFlag */
/* CPPTEST_TEST_CASE_CONTEXT U8 MApp_GetMBIRFlag(void) */
void TestSuite_MApp_IR_test_MApp_GetMBIRFlag()
{
    /* Pre-condition initialization */
    /* Initializing global variable mbir */ 
    {
         mbir.empty  = 0;
         mbir.keydata  = 0u;
         mbir.repeat  = 0;
         mbir.flag  = 0;
    }
    {
        /* Tested function call */
        U8 _return  = MApp_GetMBIRFlag();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_GetMBIRFlag */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetMBIR */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_GetMBIR(ST_MBIR *) */
void TestSuite_MApp_IR_test_MApp_GetMBIR()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pMBIR) */ 
    ST_MBIR * _pMBIR  = 0 ;
    /* Initializing global variable mbir */ 
    {
         mbir.empty  = 0;
         mbir.keydata  = 0u;
         mbir.repeat  = 0;
         mbir.flag  = 0;
    }
    {
        /* Tested function call */
        MApp_GetMBIR(_pMBIR);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_GetMBIR */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_return_g_bAutobuildDebug */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_return_g_bAutobuildDebug()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 1;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = 0;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_return_g_bAutobuildDebug */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_return_g_DisableIr */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_return_g_DisableIr()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 1;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
         //g_DisableIr  = 1;
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = 0;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_return_g_DisableIr */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */ 
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */ 
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */ 
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = 0xFF;
    }
    /* Initializing global variable u8KeyCode */ 
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */ 
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_HOME */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_HOME()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_HOME;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_HOME, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_HOME */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_POWER */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_POWER()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_POWER;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_POWER, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_POWER */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_EXIT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_EXIT()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_EXIT;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_EXIT, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_EXIT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_EPG */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_EPG()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_EPG;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_EPG, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_EPG */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_UP */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_UP()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_UP;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_UP, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_UP */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_CHANNEL_RETURN */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CHANNEL_RETURN()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_CHANNEL_RETURN;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_CHANNEL_RETURN, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_CHANNEL_RETURN */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_DOWN */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_DOWN()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_DOWN;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_DOWN, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_DOWN */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_RIGHT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_RIGHT()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_RIGHT;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_RIGHT, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_RIGHT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_LEFT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_LEFT()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_LEFT;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_LEFT, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_LEFT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_SELECT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_SELECT()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_SELECT;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_SELECT, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_SELECT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_BACK */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_BACK()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_BACK;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_BACK, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_BACK */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_NUM_0 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_0()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_NUM_0;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_0, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_NUM_0 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_NUM_1 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_1()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_NUM_1;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_1, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_NUM_1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_NUM_2 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_2()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_NUM_2;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_2, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_NUM_2 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_NUM_3 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_3()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_NUM_3;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_3, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_NUM_3 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_NUM_4 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_4()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_NUM_4;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_4, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_NUM_4 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_NUM_5 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_5()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_NUM_5;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_5, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_NUM_5 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_NUM_6 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_6()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_NUM_6;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_6, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_NUM_6 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_NUM_7 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_7()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_NUM_7;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_7, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_NUM_7 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_NUM_8 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_8()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_NUM_8;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_8, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_NUM_8 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_NUM_9 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NUM_9()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_NUM_9;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_9, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_NUM_9 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_CHANNEL_FAV_LIST */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CHANNEL_FAV_LIST()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_CHANNEL_FAV_LIST;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_CHANNEL_FAV_LIST, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_CHANNEL_FAV_LIST */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_MUTE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_MUTE()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_MUTE;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_MUTE, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_MUTE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_FREEZE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_FREEZE()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_FREEZE;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_FREEZE, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_FREEZE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_INFO */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_INFO()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_INFO;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_INFO, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_INFO */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_AUDIO */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_AUDIO()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_AUDIO;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_AUDIO, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_AUDIO */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_MTS */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_MTS()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_MTS;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_MTS, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_MTS */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_ZOOM */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_ZOOM()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_ZOOM;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_ZOOM, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_ZOOM */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_RED */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_RED()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_RED;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_RED, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_RED */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_GREEN */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_GREEN()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_GREEN;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_GREEN, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_GREEN */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_YELLOW */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_YELLOW()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_YELLOW;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_YELLOW, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_YELLOW */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_BLUE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_BLUE()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_BLUE;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_BLUE, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_BLUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_RED2 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_RED2()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_RED2;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_RED, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_RED2 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_GREEN2 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_GREEN2()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_GREEN2;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_GREEN, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_GREEN2 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_SUBTITLE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_SUBTITLE()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_SUBTITLE;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_SUBTITLE, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_SUBTITLE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_UPDATE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_UPDATE()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_UPDATE;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_UPDATE, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_UPDATE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_TTX_MODE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_TTX_MODE()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_TTX_MODE;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_TTX_MODE, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_TTX_MODE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_MIX */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_MIX()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_MIX;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_MIX, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_MIX */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_CLOCK */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CLOCK()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_CLOCK;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_CLOCK, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_CLOCK */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_TTX */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_TTX()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_TTX;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_TTX, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_TTX */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_SIZE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_SIZE()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_SIZE;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_SIZE, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_SIZE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_HOLD */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_HOLD()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_HOLD;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_HOLD, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_HOLD */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_INDEX */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_INDEX()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_INDEX;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_INDEX, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_INDEX */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_CHANNEL_LIST */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CHANNEL_LIST()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_CHANNEL_LIST;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_CHANNEL_LIST, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_CHANNEL_LIST */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_SLEEP */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_SLEEP()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_SLEEP;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_SLEEP, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_SLEEP */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_DASH */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_DASH()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_DASH;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_DASH, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_DASH */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_TV_INPUT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_TV_INPUT()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
         #if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_TV_INPUT;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_TV_INPUT, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_TV_INPUT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_BACKWARD */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_BACKWARD()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_BACKWARD;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_PREVIOUS, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_BACKWARD */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_FORWARD */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_FORWARD()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_FORWARD;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_NEXT, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_FORWARD */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_PAGE_UP */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_PAGE_UP()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_PAGE_UP;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_PAGE_UP, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_PAGE_UP */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_PAGE_DOWN */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_PAGE_DOWN()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_PAGE_DOWN;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_PAGE_DOWN, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_PAGE_DOWN */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_PREVIOUS */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_PREVIOUS()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_PREVIOUS;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_FF, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_PREVIOUS */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_NEXT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_NEXT()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_NEXT;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_REWIND, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_NEXT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_CC */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CC()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_CC;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_CC, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_CC */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_MENU */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_MENU()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_MENU;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_MENU, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_MENU */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_ADJUST */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_ADJUST()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_ADJUST;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_ADJUST, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_ADJUST */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_KEY_DISABLE_KEYPAD */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_KEY_DISABLE_KEYPAD()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_KEY_DISABLE_KEYPAD;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_DISABLE_KEYPAD, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_KEY_DISABLE_KEYPAD */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_REVEAL */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_REVEAL()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_REVEAL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_REVEAL, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_REVEAL */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_RECORD */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_RECORD()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_RECORD;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_RECORD, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_RECORD */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_STOP */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_STOP()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_STOP;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_STOP, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_STOP */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_PLAY */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_PLAY()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_PLAY;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_PLAY, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_PLAY */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_PAUSE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_PAUSE()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_PAUSE;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_PAUSE, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_PAUSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_SUBPAGE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_SUBPAGE()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_SUBPAGE;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_SUBPAGE, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_SUBPAGE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_DTV */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_DTV()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_DTV;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_DTV, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_DTV */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_TV */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_TV()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_TV;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_TV, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_TV */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_SCART */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_SCART()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_SCART;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_SCART, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_SCART */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_HDMI */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_HDMI()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_HDMI;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_HDMI, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_HDMI */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_AV */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_AV()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_AV;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_AV, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_AV */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_PC */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_PC()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_PC;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_PC, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_PC */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_COMPONENT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_COMPONENT()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_COMPONENT;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_COMPONENT, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_COMPONENT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_SV */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_SV()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_SV;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_SV, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_SV */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_isKeypadSourceKeyCanSelect_success */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_isKeypadSourceKeyCanSelect(void) */
void TestSuite_MApp_IR_test_MApp_isKeypadSourceKeyCanSelect_success()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_isKeypadSourceKeyCanSelect();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FALSE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_isKeypadSourceKeyCanSelect_success */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_isKeypadUPLR_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_isKeypadUPLR(void) */
void TestSuite_MApp_IR_test_MApp_isKeypadUPLR_TRUE()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_isKeypadUPLR();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_isKeypadUPLR_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_isKeypadUPLR_FALSE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_isKeypadUPLR(void) */
void TestSuite_MApp_IR_test_MApp_isKeypadUPLR_FALSE()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_isKeypadUPLR();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FALSE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_isKeypadUPLR_FALSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_if_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_if_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */ 
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */ 
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */ 
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = KEY_NULL;
    }
    /* Initializing global variable u8KeyCode */ 
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */ 
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_if_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_if_case_KEY_SUBCODE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_if_case_KEY_SUBCODE()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = KEY_SUBCODE;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_SUBTITLE, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_if_case_KEY_SUBCODE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_if_case_KEY_FF */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_if_case_KEY_FF()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = KEY_FF;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_NEXT, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_if_case_KEY_FF */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_if_case_KEY_REWIND */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_if_case_KEY_REWIND()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = KEY_REWIND;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_PREVIOUS, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_if_case_KEY_REWIND */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_if_case_KEY_PREVIOUS */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_if_case_KEY_PREVIOUS()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = KEY_PREVIOUS;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_REWIND, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_if_case_KEY_PREVIOUS */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_if_case_KEY_NEXT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_if_case_KEY_NEXT()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = KEY_NEXT;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_FF, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_if_case_KEY_NEXT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_PICTURE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_PICTURE()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */ 
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */ 
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */ 
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_PICTURE;
    }
    /* Initializing global variable u8KeyCode */ 
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */ 
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_PICTURE, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_PICTURE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_CHANNEL_PLUS_if */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CHANNEL_PLUS_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */ 
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */ 
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */ 
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = KEY_TYPE_KEYPAD;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_CHANNEL_PLUS;
    }
    /* Initializing global variable u8KeyCode */ 
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */ 
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_UP, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_CHANNEL_PLUS_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_CHANNEL_PLUS_else */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CHANNEL_PLUS_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */ 
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */ 
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */ 
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_CHANNEL_PLUS;
    }
    /* Initializing global variable u8KeyCode */ 
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */ 
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_CHANNEL_PLUS, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_CHANNEL_PLUS_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_CHANNEL_MINUS_if */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CHANNEL_MINUS_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = KEY_TYPE_KEYPAD;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_CHANNEL_MINUS;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_DOWN, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_CHANNEL_MINUS_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_CHANNEL_MINUS_else */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CHANNEL_MINUS_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_CHANNEL_MINUS;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_CHANNEL_MINUS, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_CHANNEL_MINUS_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_VOLUME_PLUS_if */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_VOLUME_PLUS_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = KEY_TYPE_KEYPAD;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_VOLUME_PLUS;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_RIGHT, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_VOLUME_PLUS_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_VOLUME_PLUS_else */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_VOLUME_PLUS_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_VOLUME_PLUS;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_VOLUME_PLUS, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_VOLUME_PLUS_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_VOLUME_MINUS_if */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_VOLUME_MINUS_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = KEY_TYPE_KEYPAD;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_VOLUME_MINUS;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_LEFT, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_VOLUME_MINUS_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_VOLUME_MINUS_else */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_VOLUME_MINUS_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = 0;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_VOLUME_MINUS;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_VOLUME_MINUS, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_VOLUME_MINUS_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_INPUT_SOURCE_if */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_INPUT_SOURCE_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */ 
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */ 
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */ 
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = KEY_TYPE_KEYPAD;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_INPUT_SOURCE;
    }
    /* Initializing global variable u8KeyCode */ 
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */ 
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_INPUT_SOURCE, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_INPUT_SOURCE_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_ParseKey_else_case_IRKEY_INPUT_SOURCE_else */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_ParseKey(void) */
void TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_INPUT_SOURCE_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bAutobuildDebug */ 
    {
#if ENABLE_AUTOTEST
         g_bAutobuildDebug  = 0;
#endif
    }
    /* Initializing global variable g_DisableIr */ 
    {
#if(ENABLE_MMS)
         g_DisableIr  = 0;
#endif
    }
    /* Initializing global variable stKeyStatus */ 
    {
         stKeyStatus.keydown  = 0;
         stKeyStatus.keyrepeat  = 0;
         stKeyStatus.RepeatEnable  = 0;
         stKeyStatus.keytype  = KEY_TYPE_IR;
         stKeyStatus.KeyFilterPower  = 0;
         stKeyStatus.Reserved  = 0;
         stKeyStatus.keydata  = IRKEY_INPUT_SOURCE;
    }
    /* Initializing global variable u8KeyCode */ 
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable u8KeyRepeatState */ 
    {
         u8KeyRepeatState  = 0;
    }
    {
        /* Tested function call */
        MApp_ParseKey();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_INPUT_SOURCE, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_ParseKey_else_case_IRKEY_INPUT_SOURCE_else */
