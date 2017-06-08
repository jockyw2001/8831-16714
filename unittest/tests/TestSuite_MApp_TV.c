#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app/MApp_TV.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app/MApp_TV.c");

CPPTEST_TEST_SUITE(TestSuite_MApp_TV);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsTrue);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsFalse_enMVDVideoStatus_Equal_MVD_GOOD_VIDEO_Mapi_AUDIO_IsMadLock_1);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsFalse_enMVDVideoStatus_Equal_MVD_GOOD_VIDEO_Mapi_AUDIO_IsMadLock_0);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsFalse_enMVDVideoStatus_Not_Equal_MVD_GOOD_VIDEO_Mapi_AUDIO_IsMadLock_1);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsFalse_enMVDVideoStatus_Not_Equal_MVD_GOOD_VIDEO_Mapi_AUDIO_IsMadLock_0);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_IsProgramRunning_bRunning_IsTrue);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_SearchLastSubtileLang_if_1);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_SearchLastSubtileLang_if_2);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_GetActiveStandbyMode_if);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_GetActiveStandbyMode_else);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_SetActiveStandbyMode_if);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_SetActiveStandbyMode_else);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_Set_CheckParentalPWStatus);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_Get_CheckParentalPWStatus);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_GetCheckAlternativeFlag);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_ClearCIFlag);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_ExitAndGotoMenuState);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_Init);
CPPTEST_TEST(TestSuite_MApp_TV_test_Mapp_DTV_ProcessMTS);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_Initial_IdleCount);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_DEFAULT);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_CLOCK);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_CLOCK_chagnetoNULL);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_TTX);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_RED);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_GREEN);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_YELLOW);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_BLUE);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_BACK);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_UP);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_DOWN);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_LEFT);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_RIGHT);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_UPDATE);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_DSC_KEY_MULTI_PIP);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_TIME);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_HOLD);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_REVEAL);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_SIZE);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_TTX_MODE);
//CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_PIP);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_VOLUME_PLUS);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_VOLUME_MINUS);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_SUBTITLE_if);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_SUBTITLE_else);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_EXIT);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_DEFAULT);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_0);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_1);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_2);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_3);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_4);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_5);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_6);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_7);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_8);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_9);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_TTX);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_EXIT);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_INPUT_SOURCE);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_PAGE_UP);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_PAGE_DOWN);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_LEFT);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_RIGHT);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_RED);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_GREEN);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_YELLOW);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_BLUE);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_SIZE);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_MIX);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_INDEX);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_HOLD);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_UPDATE);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_REVEAL);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_CHANNEL_LIST);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_SUBTITLE);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_POWER);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_VOLUME_PLUS);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_VOLUME_MINUS);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_MUTE_if);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_MUTE_else);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_SetCheckAlternativeFlag);
CPPTEST_TEST(TestSuite_MApp_TV_test__MApp_TV_LossSignal_CheckOriginalRF);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if1);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if2);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if3);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOSIGNAL);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NODATABASE);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_AUDIOONLY);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_SCRAMBLE);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_SCRAMBLED_PROGRAM);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOT_RUNNING1);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOT_RUNNING2);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_BLOCKRATING);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_MApp_PVR_IsPlaybacking);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOCABLE);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOSYNC);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_UNSUPPORT_MODE);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOSYNC_VD);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NO_SHOW_PROGRAM1);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NO_SHOW_PROGRAM2);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_finalreturnfalse);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_TV_GetState);
CPPTEST_TEST(TestSuite_MApp_TV_test_MApp_Set_IdleInputValue_value);
CPPTEST_TEST_SUITE_END();


void TestSuite_MApp_TV_test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsTrue();
void TestSuite_MApp_TV_test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsFalse_enMVDVideoStatus_Equal_MVD_GOOD_VIDEO_Mapi_AUDIO_IsMadLock_1();
void TestSuite_MApp_TV_test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsFalse_enMVDVideoStatus_Equal_MVD_GOOD_VIDEO_Mapi_AUDIO_IsMadLock_0();
void TestSuite_MApp_TV_test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsFalse_enMVDVideoStatus_Not_Equal_MVD_GOOD_VIDEO_Mapi_AUDIO_IsMadLock_1();
void TestSuite_MApp_TV_test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsFalse_enMVDVideoStatus_Not_Equal_MVD_GOOD_VIDEO_Mapi_AUDIO_IsMadLock_0();
void TestSuite_MApp_TV_test_MApp_TV_IsProgramRunning_bRunning_IsTrue();
void TestSuite_MApp_TV_test_MApp_TV_SearchLastSubtileLang_if_1();
void TestSuite_MApp_TV_test_MApp_TV_SearchLastSubtileLang_if_2();
void TestSuite_MApp_TV_test_MApp_GetActiveStandbyMode_if();
void TestSuite_MApp_TV_test_MApp_GetActiveStandbyMode_else();
void TestSuite_MApp_TV_test_MApp_SetActiveStandbyMode_if();
void TestSuite_MApp_TV_test_MApp_SetActiveStandbyMode_else();
void TestSuite_MApp_TV_test_MApp_Set_CheckParentalPWStatus();
void TestSuite_MApp_TV_test_MApp_Get_CheckParentalPWStatus();
void TestSuite_MApp_TV_test_MApp_TV_GetCheckAlternativeFlag();
void TestSuite_MApp_TV_test_MApp_TV_ClearCIFlag();
void TestSuite_MApp_TV_test_MApp_TV_ExitAndGotoMenuState();
void TestSuite_MApp_TV_test_MApp_TV_Init();
void TestSuite_MApp_TV_test_Mapp_DTV_ProcessMTS();
void TestSuite_MApp_TV_test_MApp_TV_Initial_IdleCount();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_DEFAULT();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_CLOCK();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_CLOCK_chagnetoNULL();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_TTX();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_RED();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_RED();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_GREEN();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_YELLOW();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_BLUE();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_BACK();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_UP();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_DOWN();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_LEFT();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_RIGHT();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_UPDATE();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_DSC_KEY_MULTI_PIP();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_TIME();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_HOLD();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_REVEAL();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_SIZE();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_TTX_MODE();
//void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_PIP();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_VOLUME_PLUS();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_VOLUME_MINUS();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_SUBTITLE_if();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_SUBTITLE_else();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_EXIT();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_DEFAULT();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_0();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_1();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_2();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_3();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_4();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_5();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_6();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_7();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_8();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_9();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_TTX();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_EXIT();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_INPUT_SOURCE();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_PAGE_UP();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_PAGE_DOWN();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_LEFT();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_RIGHT();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_RED();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_GREEN();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_YELLOW();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_BLUE();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_SIZE();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_MIX();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_INDEX();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_HOLD();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_UPDATE();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_REVEAL();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_CHANNEL_LIST();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_SUBTITLE();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_POWER();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_VOLUME_PLUS();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_VOLUME_MINUS();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_MUTE_if();
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_MUTE_else();
void TestSuite_MApp_TV_test_MApp_TV_SetCheckAlternativeFlag();
void TestSuite_MApp_TV_test__MApp_TV_LossSignal_CheckOriginalRF();
void TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if1();
void TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if2();
void TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if3();
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOSIGNAL();
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NODATABASE();
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_AUDIOONLY();
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_SCRAMBLE();
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_SCRAMBLED_PROGRAM();
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOT_RUNNING1();
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOT_RUNNING2();
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_BLOCKRATING();
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_MApp_PVR_IsPlaybacking();
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOCABLE();
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOSYNC();
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_UNSUPPORT_MODE();
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOSYNC_VD();
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NO_SHOW_PROGRAM1();
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NO_SHOW_PROGRAM2();
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_finalreturnfalse();
void TestSuite_MApp_TV_test_MApp_TV_GetState();
void TestSuite_MApp_TV_test_MApp_Set_IdleInputValue_value();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_MApp_TV);

void TestSuite_MApp_TV_setUp()
{
}

void TestSuite_MApp_TV_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsTrue */
void TestSuite_MApp_TV_test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsTrue()
{
    /* Pre-condition initialization */
    /* Initializing global variable enMVDVideoStatus */
    {
    	enMVDVideoStatus = MVD_GOOD_VIDEO;
    }
    {
        /* Tested function call */
		BOOLEAN _return = MApp_TV_IsProgramRunning();
        /* Post-condition check */
		CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
    }

}
/* CPPTEST_TEST_CASE_END test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsTrue */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsFalse_enMVDVideoStatus_Equal_MVD_GOOD_VIDEO_Mapi_AUDIO_IsMadLock_1 */
void TestSuite_MApp_TV_test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsFalse_enMVDVideoStatus_Equal_MVD_GOOD_VIDEO_Mapi_AUDIO_IsMadLock_1()
{
    /* Pre-condition initialization */
    /* Initializing global variable enMVDVideoStatus */
    {
    	enMVDVideoStatus = MVD_GOOD_VIDEO;
    }
    {
        /* Tested function call */
		BOOLEAN _return = MApp_TV_IsProgramRunning();
        /* Post-condition check */
		CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsFalse_enMVDVideoStatus_Equal_MVD_GOOD_VIDEO_Mapi_AUDIO_IsMadLock_1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsFalse_enMVDVideoStatus_Equal_MVD_GOOD_VIDEO_Mapi_AUDIO_IsMadLock_0 */
void TestSuite_MApp_TV_test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsFalse_enMVDVideoStatus_Equal_MVD_GOOD_VIDEO_Mapi_AUDIO_IsMadLock_0()
{
    /* Pre-condition initialization */
    /* Initializing global variable enMVDVideoStatus */
    {
    	enMVDVideoStatus = MVD_GOOD_VIDEO;
    }
    {
        /* Tested function call */
		BOOLEAN _return = MApp_TV_IsProgramRunning();
        /* Post-condition check */
		CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsFalse_enMVDVideoStatus_Equal_MVD_GOOD_VIDEO_Mapi_AUDIO_IsMadLock_0 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsFalse_enMVDVideoStatus_Not_Equal_MVD_GOOD_VIDEO_Mapi_AUDIO_IsMadLock_1 */
void TestSuite_MApp_TV_test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsFalse_enMVDVideoStatus_Not_Equal_MVD_GOOD_VIDEO_Mapi_AUDIO_IsMadLock_1()
{
    /* Pre-condition initialization */
    /* Initializing global variable enMVDVideoStatus */
    {
    	enMVDVideoStatus = MVD_BAD_VIDEO;
    }
    {
        /* Tested function call */
		BOOLEAN _return = MApp_TV_IsProgramRunning();
        /* Post-condition check */
		CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsFalse_enMVDVideoStatus_Not_Equal_MVD_GOOD_VIDEO_Mapi_AUDIO_IsMadLock_1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsFalse_enMVDVideoStatus_Not_Equal_MVD_GOOD_VIDEO_Mapi_AUDIO_IsMadLock_0 */
void TestSuite_MApp_TV_test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsFalse_enMVDVideoStatus_Not_Equal_MVD_GOOD_VIDEO_Mapi_AUDIO_IsMadLock_0()
{
    /* Pre-condition initialization */
    /* Initializing global variable enMVDVideoStatus */
    {
    	enMVDVideoStatus = MVD_BAD_VIDEO;
    }
    {
        /* Tested function call */
		BOOLEAN _return = MApp_TV_IsProgramRunning();
        /* Post-condition check */
		CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsFalse_enMVDVideoStatus_Not_Equal_MVD_GOOD_VIDEO_Mapi_AUDIO_IsMadLock_0 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_IsProgramRunning_bRunning_IsTrue */
void TestSuite_MApp_TV_test_MApp_TV_IsProgramRunning_bRunning_IsTrue()
{
    /* Pre-condition initialization */
    /* Initializing global variable enMVDVideoStatus */
    {
    	enMVDVideoStatus = MVD_GOOD_VIDEO;
    }
    {
        /* Tested function call */
		BOOLEAN _return = MApp_TV_IsProgramRunning();
        /* Post-condition check */
		CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }

}
/* CPPTEST_TEST_CASE_END test_MApp_TV_IsProgramRunning_bRunning_IsTrue */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_SearchLastSubtileLang_if_1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TV_SearchLastSubtileLang(void) */
void TestSuite_MApp_TV_test_MApp_TV_SearchLastSubtileLang_if_1()
{
    /* Pre-condition initialization */
    /* Initializing global variable UI_Hotkey_Subtitle */
    {
         UI_Hotkey_Subtitle  = 0;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.g_SysSetting.fEnableSubTitle = FALSE;
    }
    /* Initializing global variable g_u8AudLangSelected */
    {
         g_u8AudLangSelected  = 0;
    }
    /* Initializing global variable u8SubtitleItemSelIdx */
    {
         u8SubtitleItemSelIdx  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TV_SearchLastSubtileLang();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 0, ( u8SubtitleItemSelIdx ) );
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_SearchLastSubtileLang_if_1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_SearchLastSubtileLang_if_2 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TV_SearchLastSubtileLang(void) */
void TestSuite_MApp_TV_test_MApp_TV_SearchLastSubtileLang_if_2()
{
    /* Pre-condition initialization */
    /* Initializing global variable UI_Hotkey_Subtitle */
    {
         UI_Hotkey_Subtitle  = FALSE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.g_SysSetting.fEnableSubTitle = TRUE;
         stGenSetting.g_SysSetting.fEnableTTXSubTitle = FALSE;
    }
    /* Initializing global variable g_u8AudLangSelected */
    {
         g_u8AudLangSelected  = 0;
    }
    /* Initializing global variable u8SubtitleItemSelIdx */
    {
         u8SubtitleItemSelIdx  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TV_SearchLastSubtileLang();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_SearchLastSubtileLang_if_2 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetActiveStandbyMode_if */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_GetActiveStandbyMode(void) */
void TestSuite_MApp_TV_test_MApp_GetActiveStandbyMode_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bTimerTypeRecord */
    {
         g_bTimerTypeRecord  = 1;
    }
    /* Initializing global variable g_bTimeTypeOpRefresh */
    {
         g_bTimeTypeOpRefresh  = 0;
    }
    /* Initializing global variable g_bTimerActiveStandbyMode */
    {
         g_bTimerActiveStandbyMode  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_GetActiveStandbyMode();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( g_bTimerActiveStandbyMode, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_GetActiveStandbyMode_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetActiveStandbyMode_else */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_GetActiveStandbyMode(void) */
void TestSuite_MApp_TV_test_MApp_GetActiveStandbyMode_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bTimerTypeRecord */
    {
         g_bTimerTypeRecord  = 0;
    }
    /* Initializing global variable g_bTimeTypeOpRefresh */
    {
         g_bTimeTypeOpRefresh  = 0;
    }
    /* Initializing global variable g_bTimerActiveStandbyMode */
    {
         g_bTimerActiveStandbyMode  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_GetActiveStandbyMode();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_GetActiveStandbyMode_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_SetActiveStandbyMode_if */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_SetActiveStandbyMode(BOOLEAN) */
void TestSuite_MApp_TV_test_MApp_SetActiveStandbyMode_if()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bActive) */
    U8 _bActive  = TRUE;
    /* Initializing global variable g_bTimerActiveStandbyMode */
    {
         g_bTimerActiveStandbyMode  = 0;
    }
    {
        /* Tested function call */
        MApp_SetActiveStandbyMode(_bActive);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_SetActiveStandbyMode_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_SetActiveStandbyMode_else */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_SetActiveStandbyMode(BOOLEAN) */
void TestSuite_MApp_TV_test_MApp_SetActiveStandbyMode_else()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bActive) */
    U8 _bActive  = FALSE;
    /* Initializing global variable g_bTimerActiveStandbyMode */
    {
         g_bTimerActiveStandbyMode  = 0;
    }
    {
        /* Tested function call */
        MApp_SetActiveStandbyMode(_bActive);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_SetActiveStandbyMode_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Set_CheckParentalPWStatus */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Set_CheckParentalPWStatus(BOOLEAN) */
void TestSuite_MApp_TV_test_MApp_Set_CheckParentalPWStatus()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bStatus) */
    U8 _bStatus  = 0;
    /* Initializing global variable bCheckParentalPW */
    {
         bCheckParentalPW  = 0;
    }
    {
        /* Tested function call */
        MApp_Set_CheckParentalPWStatus(_bStatus);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _bStatus, ( bCheckParentalPW ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Set_CheckParentalPWStatus */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Get_CheckParentalPWStatus */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Get_CheckParentalPWStatus(void) */
void TestSuite_MApp_TV_test_MApp_Get_CheckParentalPWStatus()
{
    /* Pre-condition initialization */
    /* Initializing global variable bCheckParentalPW */
    {
         bCheckParentalPW  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_Get_CheckParentalPWStatus();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( bCheckParentalPW, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Get_CheckParentalPWStatus */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_GetCheckAlternativeFlag */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TV_GetCheckAlternativeFlag(void) */
void TestSuite_MApp_TV_test_MApp_TV_GetCheckAlternativeFlag()
{
    /* Pre-condition initialization */
    /* Initializing global variable _bCheckAlternative */
    {
         _bCheckAlternative  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TV_GetCheckAlternativeFlag();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _bCheckAlternative, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_GetCheckAlternativeFlag */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_ClearCIFlag */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TV_ClearCIFlag(void) */
void TestSuite_MApp_TV_test_MApp_TV_ClearCIFlag()
{
    /* Pre-condition initialization */
    /* Initializing global variable enCheckMHEGLoadingStatus */
    {
         enCheckMHEGLoadingStatus  = EN_MHEG5_MONITOR;
    }
    {
        /* Tested function call */
        MApp_TV_ClearCIFlag();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_MHEG5_MONITOR, ( enCheckMHEGLoadingStatus ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_ClearCIFlag */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_ExitAndGotoMenuState */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TV_ExitAndGotoMenuState(void) */
void TestSuite_MApp_TV_test_MApp_TV_ExitAndGotoMenuState()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    {
        /* Tested function call */
        MApp_TV_ExitAndGotoMenuState();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TV_INIT, ( enTVState ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_ExitAndGotoMenuState */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_Init */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TV_Init(void) */
void TestSuite_MApp_TV_test_MApp_TV_Init()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    {
        /* Tested function call */
        MApp_TV_Init();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TV_WAIT, ( enTVState ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_Init */

/* CPPTEST_TEST_CASE_BEGIN test_Mapp_DTV_ProcessMTS */
/* CPPTEST_TEST_CASE_CONTEXT void Mapp_DTV_ProcessMTS(void) */
void TestSuite_MApp_TV_test_Mapp_DTV_ProcessMTS()
{
    /* Pre-condition initialization */
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable u32TVModeWinTimer */
    {
         u32TVModeWinTimer  = 0ul;
    }
    {
        /* Tested function call */
        Mapp_DTV_ProcessMTS();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ));
        CPPTEST_ASSERT_EQUAL( EXIT_GOTO_OSDPAGE, ( enTVRetVal ) )
        CPPTEST_ASSERT_EQUAL( STATE_TV_INIT, ( enTVState ) )
    }
}
/* CPPTEST_TEST_CASE_END test_Mapp_DTV_ProcessMTS */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_Initial_IdleCount */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TV_Initial_IdleCount(void) */
void TestSuite_MApp_TV_test_MApp_TV_Initial_IdleCount()
{
    /* Pre-condition initialization */
    /* Initializing global variable u32TVModeWinTimer */
    {
         u32TVModeWinTimer  = 0ul;
    }
    {
        /* Tested function call */
        MApp_TV_Initial_IdleCount();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_Initial_IdleCount */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_if_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_DISABLE_KEYPAD;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_DISABLE_KEYPAD, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_if_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_CLOCK */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_CLOCK()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_CLOCK;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_CLOCK, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_CLOCK */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_CLOCK_chagnetoNULL */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_CLOCK_chagnetoNULL()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_CLOCK;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_CLOCK_chagnetoNULL */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_TTX */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_TTX()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_TTX;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_TTX, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_TTX */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_RED */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_RED()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_RED;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_RED */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_GREEN */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_GREEN()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_GREEN;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_GREEN */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_YELLOW */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_YELLOW()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_YELLOW;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_YELLOW */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_BLUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_BLUE()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_BLUE;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_BLUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_BACK */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_BACK()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_BACK;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_BACK */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_UP */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_UP()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_UP;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_UP */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_DOWN */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_DOWN()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_DOWN;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_DOWN */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_LEFT */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_LEFT()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_LEFT;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_LEFT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_RIGHT */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_RIGHT()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_RIGHT;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_RIGHT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_UPDATE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_UPDATE()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_UPDATE;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_UPDATE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_if_case_DSC_KEY_MULTI_PIP */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_DSC_KEY_MULTI_PIP()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = DSC_KEY_MULTI_PIP;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_if_case_DSC_KEY_MULTI_PIP */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_TIME */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_TIME()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_TIME;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_TIME */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_HOLD */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_HOLD()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_HOLD;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_HOLD */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_REVEAL */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_REVEAL()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_REVEAL;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_REVEAL */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_SIZE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_SIZE()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_SIZE;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_SIZE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_TTX_MODE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_TTX_MODE()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_TTX_MODE;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_TTX_MODE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_PIP */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_PIP()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_PIP;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_PIP */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_VOLUME_PLUS */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_VOLUME_PLUS()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_VOLUME_PLUS;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_VOLUME_PLUS */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_VOLUME_MINUS */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_VOLUME_MINUS()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_VOLUME_MINUS;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) );
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_VOLUME_MINUS */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_SUBTITLE_if */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_SUBTITLE_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_SUBTITLE;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) );
        CPPTEST_ASSERT_EQUAL( KEY_SUBTITLE, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_SUBTITLE_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_SUBTITLE_else */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_SUBTITLE_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_SUBTITLE;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_SUBTITLE_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_EXIT */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_EXIT()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_EXIT;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_EXIT */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_DISABLE_KEYPAD;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_0 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_0()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_0;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_0 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_1()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_1;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_2 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_2()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_2;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_2 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_3 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_3()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_3;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_3 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_4 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_4()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_4;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_4 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_5 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_5()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_5;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_5 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_6 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_6()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_6;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_6 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_7 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_7()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_7;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_7 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_8 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_8()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_8;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_8 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_9 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_9()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_9;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_9 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_TTX */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_TTX()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_TTX;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_TTX */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_EXIT */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_EXIT()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_EXIT;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_EXIT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_INPUT_SOURCE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_INPUT_SOURCE()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_INPUT_SOURCE;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_INPUT_SOURCE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_PAGE_UP */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_PAGE_UP()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_PAGE_UP;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_PAGE_UP */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_PAGE_DOWN */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_PAGE_DOWN()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_PAGE_DOWN;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_PAGE_DOWN */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_LEFT */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_LEFT()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_LEFT;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_LEFT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_RIGHT */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_RIGHT()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_RIGHT;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_RIGHT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_RED */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_RED()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_RED;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_RED */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_GREEN */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_GREEN()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_GREEN;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_GREEN */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_YELLOW */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_YELLOW()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_YELLOW;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_YELLOW */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_BLUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_BLUE()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_BLUE;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_BLUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_SIZE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_SIZE()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_SIZE;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_SIZE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_MIX */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_MIX()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_MIX;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_MIX */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_INDEX */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_INDEX()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_INDEX;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_INDEX */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_HOLD */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_HOLD()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_HOLD;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_HOLD */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_UPDATE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_UPDATE()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_UPDATE;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_UPDATE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_REVEAL */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_REVEAL()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_REVEAL;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_REVEAL */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_CHANNEL_LIST */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_CHANNEL_LIST()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_CHANNEL_LIST;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_CHANNEL_LIST */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_SUBTITLE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_SUBTITLE()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_SUBTITLE;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_SUBTITLE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_POWER */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_POWER()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_POWER;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( STATE_TV_INIT, ( enTVState ) )
        CPPTEST_ASSERT_EQUAL( EXIT_GOTO_STANDBY, ( enTVRetVal ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_POWER */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_VOLUME_PLUS */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_VOLUME_PLUS()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_VOLUME_PLUS;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
		stGenSetting.g_SoundSetting.Volume = MAX_NUM_OF_VOL_LEVEL-1;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_VOLUME_PLUS */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_VOLUME_MINUS */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_VOLUME_MINUS()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_VOLUME_MINUS;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
    	stGenSetting.g_SoundSetting.Volume = 1;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_VOLUME_MINUS */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_MUTE_if */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_MUTE_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_MUTE;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_MUTE_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_MUTE_else */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TTX_Idle_ProcessUserInput(void) */
void TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_MUTE_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_MUTE;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TTX_Idle_ProcessUserInput();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( KEY_NULL, ( u8KeyCode ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_MUTE_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_SetCheckAlternativeFlag */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TV_SetCheckAlternativeFlag(BOOLEAN) */
void TestSuite_MApp_TV_test_MApp_TV_SetCheckAlternativeFlag()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bFlag) */
    U8 _bFlag  = 0;
    /* Initializing global variable _bCheckAlternative */
    {
         _bCheckAlternative  = 0;
    }
    {
        /* Tested function call */
        MApp_TV_SetCheckAlternativeFlag(_bFlag);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _bFlag, ( _bCheckAlternative ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_SetCheckAlternativeFlag */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_TV_LossSignal_CheckOriginalRF */
/* CPPTEST_TEST_CASE_CONTEXT void _MApp_TV_LossSignal_CheckOriginalRF(void) */
void TestSuite_MApp_TV_test__MApp_TV_LossSignal_CheckOriginalRF()
{
    /* Pre-condition initialization */
    /* Initializing global variable _bCheckAlternative */
    {
         _bCheckAlternative  = 1;
    }
    /* Initializing global variable enTVRetVal */
    {
         enTVRetVal  = EXIT_NULL;
    }
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = KEY_NULL;
    }
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    {
        /* Tested function call */
        _MApp_TV_LossSignal_CheckOriginalRF();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _bCheckAlternative ) )
        CPPTEST_ASSERT_EQUAL( STATE_TV_INIT, ( enTVState ) )
        CPPTEST_ASSERT_EQUAL( EXIT_GOTO_SCAN_NEW_MUX, ( enTVRetVal ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_TV_LossSignal_CheckOriginalRF */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_CheckLossSignal30Days_if1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TV_CheckLossSignal30Days(void) */
void TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if1()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TV_CheckLossSignal30Days();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_CheckLossSignal30Days_if1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_CheckLossSignal30Days_if2 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TV_CheckLossSignal30Days(void) */
void TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if2()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TV_CheckLossSignal30Days();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_CheckLossSignal30Days_if2 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_CheckLossSignal30Days_if3 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TV_CheckLossSignal30Days(void) */
void TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if3()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TV_CheckLossSignal30Days();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_CheckLossSignal30Days_if3 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOSIGNAL */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TV_ScreenSaverClear(SCALER_WIN) */
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOSIGNAL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    /* Initializing global variable enMVDVideoStatus */
    {
         enMVDVideoStatus  = MVD_UNKNOWN_VIDEO;
    }
    {
    	enCurScreenSaver[_eWindow] = EN_SCREENSAVER_NOSIGNAL;
    	stSystemInfo[_eWindow].enInputSourceType = INPUT_SOURCE_DTV;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TV_ScreenSaverClear(_eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOSIGNAL */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NODATABASE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TV_ScreenSaverClear(SCALER_WIN) */
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NODATABASE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    /* Initializing global variable enMVDVideoStatus */
    {
         enMVDVideoStatus  = MVD_UNKNOWN_VIDEO;
    }
    {
    	enCurScreenSaver[_eWindow] = EN_SCREENSAVER_NODATABASE;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TV_ScreenSaverClear(_eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NODATABASE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_AUDIOONLY */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TV_ScreenSaverClear(SCALER_WIN) */
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_AUDIOONLY()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    /* Initializing global variable enMVDVideoStatus */
    {
         enMVDVideoStatus  = MVD_UNKNOWN_VIDEO;
    }
    {
    	enCurScreenSaver[_eWindow] = EN_SCREENSAVER_AUDIOONLY;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TV_ScreenSaverClear(_eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_AUDIOONLY */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_SCRAMBLE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TV_ScreenSaverClear(SCALER_WIN) */
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_SCRAMBLE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    /* Initializing global variable enMVDVideoStatus */
    {
         enMVDVideoStatus  = MVD_UNKNOWN_VIDEO;
    }
    {
    	enCurScreenSaver[_eWindow] = EN_SCREENSAVER_SCRAMBLE;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TV_ScreenSaverClear(_eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_SCRAMBLE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_SCRAMBLED_PROGRAM */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TV_ScreenSaverClear(SCALER_WIN) */
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_SCRAMBLED_PROGRAM()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    /* Initializing global variable enMVDVideoStatus */
    {
         enMVDVideoStatus  = MVD_UNKNOWN_VIDEO;
    }
    {
    	enCurScreenSaver[_eWindow] = EN_SCREENSAVER_SCRAMBLED_PROGRAM;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TV_ScreenSaverClear(_eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_SCRAMBLED_PROGRAM */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOT_RUNNING1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TV_ScreenSaverClear(SCALER_WIN) */
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOT_RUNNING1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    /* Initializing global variable enMVDVideoStatus */
    {
         enMVDVideoStatus  = MVD_UNKNOWN_VIDEO;
    }
    {
    	enCurScreenSaver[_eWindow] = EN_SCREENSAVER_NOT_RUNNING1;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TV_ScreenSaverClear(_eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOT_RUNNING1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOT_RUNNING2 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TV_ScreenSaverClear(SCALER_WIN) */
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOT_RUNNING2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    /* Initializing global variable enMVDVideoStatus */
    {
         enMVDVideoStatus  = MVD_UNKNOWN_VIDEO;
    }
    {
    	enCurScreenSaver[_eWindow] = EN_SCREENSAVER_NOT_RUNNING2;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TV_ScreenSaverClear(_eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOT_RUNNING2 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_BLOCKRATING */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TV_ScreenSaverClear(SCALER_WIN) */
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_BLOCKRATING()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    /* Initializing global variable enMVDVideoStatus */
    {
         enMVDVideoStatus  = MVD_UNKNOWN_VIDEO;
    }
    {
    	enCurScreenSaver[_eWindow] = EN_SCREENSAVER_BLOCKRATING;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TV_ScreenSaverClear(_eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_BLOCKRATING */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_ScreenSaverClear_MApp_PVR_IsPlaybacking */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TV_ScreenSaverClear(SCALER_WIN) */
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_MApp_PVR_IsPlaybacking()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    /* Initializing global variable enMVDVideoStatus */
    {
         enMVDVideoStatus  = MVD_UNKNOWN_VIDEO;
    }
    {
    	enCurScreenSaver[_eWindow] = EN_SCREENSAVER_NOCABLE;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TV_ScreenSaverClear(_eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_ScreenSaverClear_MApp_PVR_IsPlaybacking */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOCABLE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TV_ScreenSaverClear(SCALER_WIN) */
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOCABLE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    /* Initializing global variable enMVDVideoStatus */
    {
         enMVDVideoStatus  = MVD_UNKNOWN_VIDEO;
    }
    {
    	enCurScreenSaver[_eWindow] = EN_SCREENSAVER_NOCABLE;
    	stSystemInfo[_eWindow].enInputSourceType = INPUT_SOURCE_HDMI;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TV_ScreenSaverClear(_eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOCABLE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOSYNC */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TV_ScreenSaverClear(SCALER_WIN) */
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOSYNC()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    /* Initializing global variable enMVDVideoStatus */
    {
         enMVDVideoStatus  = MVD_UNKNOWN_VIDEO;
    }
    {
    	enCurScreenSaver[_eWindow] = EN_SCREENSAVER_NOSYNC;
    	stSystemInfo[_eWindow].enInputSourceType = INPUT_SOURCE_HDMI;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TV_ScreenSaverClear(_eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOSYNC */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_UNSUPPORT_MODE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TV_ScreenSaverClear(SCALER_WIN) */
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_UNSUPPORT_MODE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    /* Initializing global variable enMVDVideoStatus */
    {
         enMVDVideoStatus  = MVD_UNKNOWN_VIDEO;
    }
    {
    	enCurScreenSaver[_eWindow] = EN_SCREENSAVER_UNSUPPORT_MODE;
    	stSystemInfo[_eWindow].enInputSourceType = INPUT_SOURCE_HDMI;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TV_ScreenSaverClear(_eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_UNSUPPORT_MODE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOSYNC_VD */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TV_ScreenSaverClear(SCALER_WIN) */
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOSYNC_VD()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    /* Initializing global variable enMVDVideoStatus */
    {
         enMVDVideoStatus  = MVD_UNKNOWN_VIDEO;
    }
    {
    	enCurScreenSaver[_eWindow] = EN_SCREENSAVER_NOSYNC_VD;
    	stSystemInfo[_eWindow].enInputSourceType = INPUT_SOURCE_DTV;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TV_ScreenSaverClear(_eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOSYNC_VD */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NO_SHOW_PROGRAM1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TV_ScreenSaverClear(SCALER_WIN) */
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NO_SHOW_PROGRAM1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    /* Initializing global variable enMVDVideoStatus */
    {
         enMVDVideoStatus  = MVD_UNKNOWN_VIDEO;
    }
    {
    	enCurScreenSaver[_eWindow] = EN_SCREENSAVER_NO_SHOW_PROGRAM;
    	stSystemInfo[_eWindow].enInputSourceType = INPUT_SOURCE_DTV;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TV_ScreenSaverClear(_eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NO_SHOW_PROGRAM1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NO_SHOW_PROGRAM2 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TV_ScreenSaverClear(SCALER_WIN) */
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NO_SHOW_PROGRAM2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    /* Initializing global variable enMVDVideoStatus */
    {
         enMVDVideoStatus  = MVD_UNKNOWN_VIDEO;
    }
    {
    	enCurScreenSaver[_eWindow] = EN_SCREENSAVER_NO_SHOW_PROGRAM;
    	stSystemInfo[_eWindow].enInputSourceType = INPUT_SOURCE_DVI;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TV_ScreenSaverClear(_eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NO_SHOW_PROGRAM2 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_ScreenSaverClear_finalreturnfalse */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_TV_ScreenSaverClear(SCALER_WIN) */
void TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_finalreturnfalse()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    /* Initializing global variable enMVDVideoStatus */
    {
         enMVDVideoStatus  = MVD_UNKNOWN_VIDEO;
    }
    {
    	enCurScreenSaver[_eWindow] = EN_SCREENSAVER_NOCABLE;
    	stSystemInfo[_eWindow].enInputSourceType = INPUT_SOURCE_DTV;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_TV_ScreenSaverClear(_eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_ScreenSaverClear_finalreturnfalse */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TV_GetState */
/* CPPTEST_TEST_CASE_CONTEXT EN_TV_STATE MApp_TV_GetState(void) */
void TestSuite_MApp_TV_test_MApp_TV_GetState()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTVState */
    {
         enTVState  = STATE_TV_INIT;
    }
    {
        /* Tested function call */
        EN_TV_STATE _return  = MApp_TV_GetState();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TV_INIT, ( _return ) )
        CPPTEST_ASSERT_EQUAL( STATE_TV_INIT, ( enTVState ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TV_GetState */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Set_IdleInputValue_value */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Set_IdleInputValue(U16) */
void TestSuite_MApp_TV_test_MApp_Set_IdleInputValue_value()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16NewInputVal) */ 
    U16 _u16NewInputVal  = 0u;
    /* Initializing global variable u16IdleInputValue */ 
    {
         u16IdleInputValue  = 0u;
    }
    {
        /* Tested function call */
        MApp_Set_IdleInputValue(_u16NewInputVal);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U16 u16IdleInputValue", ( u16IdleInputValue ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Set_IdleInputValue_value */
