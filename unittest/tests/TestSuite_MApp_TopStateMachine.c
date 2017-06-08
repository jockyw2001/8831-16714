#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app/MApp_TopStateMachine.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app/MApp_TopStateMachine.c");

CPPTEST_TEST_SUITE(TestSuite_MApp_TopStateMachine);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_GetTopStateName_CHANNELCHANGE);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_GetTopStateName_DIGITALINPUTS);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_GetTopStateName_INPUTSOURCE);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_DEFAULT_MHL_Cbus_Not_Connect);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_DEFAULT_MHL_Cbus_Connect_FlagIsTRUE);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_DEFAULT_MHL_Cbus_Connect_FlagIsFALSEandZUIGoing);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_DEFAULT_MHL_Cbus_Connect_FlagIsFALSEandZUINotGoing);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_TTX);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ANALOG_SHOW_BANNER_case_EXIT_CLOSE);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ANALOG_SHOW_BANNER_case_DEFAULT);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_CHANNELCHANGE_case_EXIT_CLOSE);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_CHANNELCHANGE_case_DEFAULT);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsTRUE_case_EXIT_GOTO_CHANNELCHANGE);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsTRUE_case_DEFAULT);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_DEFAULT);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_EXIT_GOTO_PREVIOUS);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_EXIT_GOTO_CHANNELCHANGE);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_EXIT_GOTO_TV);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_EXIT_GOTO_STANDBY);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_DEFAULT);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_GOTO_PREVIOUS);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_GOTO_CHANNELCHANGE);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_GOTO_WAIT);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_GOTO_STANDBY);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_DEFAULT);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_STANDBY);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_CHANNELCHANGE);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_TV);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_PREVIOUS);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_DTV_SCAN);
#if(ENABLE_SBTVD_BRAZIL_APP)
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_CATV_SCAN);
#endif
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_DEFAULT);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_USB);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_OAD);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_MENU);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_INSTALLGUIDE);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_STANDBY);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_CHANNELCHANGE);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_EPG);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_INPUTSOURCE);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_OSDPAGE);
#if ENABLE_CI
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_MMI);
#endif
#if ENABLE_DMP
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_DMP);
#endif
#if (ENABLE_UPDATE_MULTIPLEX_VIA_NIT)
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_SCAN_NEW_MUX);
#endif
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_PVR_case_DEFAULT);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_PVR_case_EXIT_CLOSE);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_PVR_case_EXIT_GOTO_STANDBY);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_PVR_case_EXIT_GOTO_MENU);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_DEFAULT);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_EXIT_CLOSE);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_EXIT_GOTO_STANDBY);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_EXIT_GOTO_MENU);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_EXIT_GOTO_DTVSCAN);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_DEFAULT);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_EXIT_CLOSE);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_EXIT_GOTO_STANDBY);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_EXIT_GOTO_MENU);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_EXIT_GOTO_ATVSCAN);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_DEFAULT);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_CLOSE);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_CHANNELCHANGE);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_MENU);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_EPG);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_INPUTSOURCE);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_STANDBY);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_DMP);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_DEFAULT);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_CLOSE);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_GOTO_STANDBY);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_GOTO_SCAN);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_GOTO_EPG);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_GOTO_CHANNELCHANGE);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_EPG_case_DEFAULT);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_EPG_case_EXIT_CLOSE);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_EPG_case_EXIT_GOTO_MENU);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_EPG_case_EXIT_GOTO_STANDBY);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_DEFAULT);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_CLOSE_if);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_CLOSE_else);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_STANDBY);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_DMP);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_OSDPAGE);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_MENU);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_INFO);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OAD_case_DEFAULT);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OAD_case_EXIT_CLOSE);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_STANDBY);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_DEFAULT);
#if 1
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_CLOSE_if);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_CLOSE_else);
#endif
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_STANDBY);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_EPG);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_DTV_MANUALTUNING);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_ATV_MANUALTUNING);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_CHANNELCHANGE);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_MMI);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_DMP);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_PVR_CHECK_FS);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_OSDPAGE);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_INPUTSOURCE);
CPPTEST_TEST(TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_INFO);
CPPTEST_TEST_SUITE_END();


void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_GetTopStateName_CHANNELCHANGE();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_GetTopStateName_DIGITALINPUTS();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_GetTopStateName_INPUTSOURCE();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_DEFAULT_MHL_Cbus_Not_Connect();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_DEFAULT_MHL_Cbus_Connect_FlagIsTRUE();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_DEFAULT_MHL_Cbus_Connect_FlagIsFALSEandZUIGoing();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_DEFAULT_MHL_Cbus_Connect_FlagIsFALSEandZUINotGoing();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_TTX();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ANALOG_SHOW_BANNER_case_EXIT_CLOSE();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ANALOG_SHOW_BANNER_case_DEFAULT();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_CHANNELCHANGE_case_EXIT_CLOSE();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_CHANNELCHANGE_case_DEFAULT();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsTRUE_case_EXIT_GOTO_CHANNELCHANGE();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsTRUE_case_DEFAULT();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_DEFAULT();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_EXIT_GOTO_PREVIOUS();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_EXIT_GOTO_CHANNELCHANGE();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_EXIT_GOTO_TV();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_EXIT_GOTO_STANDBY();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_DEFAULT();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_GOTO_PREVIOUS();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_GOTO_CHANNELCHANGE();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_GOTO_WAIT();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_GOTO_STANDBY();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_DEFAULT();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_STANDBY();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_CHANNELCHANGE();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_TV();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_PREVIOUS();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_DTV_SCAN();
#if(ENABLE_SBTVD_BRAZIL_APP)
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_CATV_SCAN();
#endif
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_DEFAULT();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_USB();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_OAD();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_MENU();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_INSTALLGUIDE();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_STANDBY();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_CHANNELCHANGE();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_EPG();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_INPUTSOURCE();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_OSDPAGE();
#if ENABLE_CI
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_MMI();
#endif
#if ENABLE_DMP
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_DMP();
#endif
#if (ENABLE_UPDATE_MULTIPLEX_VIA_NIT)
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_SCAN_NEW_MUX();
#endif
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_PVR_case_DEFAULT();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_PVR_case_EXIT_CLOSE();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_PVR_case_EXIT_GOTO_STANDBY();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_PVR_case_EXIT_GOTO_MENU();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_DEFAULT();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_EXIT_CLOSE();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_EXIT_GOTO_STANDBY();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_EXIT_GOTO_MENU();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_EXIT_GOTO_DTVSCAN();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_DEFAULT();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_EXIT_CLOSE();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_EXIT_GOTO_STANDBY();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_EXIT_GOTO_MENU();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_EXIT_GOTO_ATVSCAN();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_DEFAULT();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_CLOSE();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_CHANNELCHANGE();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_MENU();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_EPG();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_INPUTSOURCE();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_STANDBY();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_DMP();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_DEFAULT();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_CLOSE();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_GOTO_STANDBY();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_GOTO_SCAN();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_GOTO_EPG();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_GOTO_CHANNELCHANGE();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_EPG_case_DEFAULT();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_EPG_case_EXIT_CLOSE();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_EPG_case_EXIT_GOTO_MENU();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_EPG_case_EXIT_GOTO_STANDBY();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_DEFAULT();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_CLOSE_if();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_CLOSE_else();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_STANDBY();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_DMP();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_OSDPAGE();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_MENU();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_INFO();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OAD_case_DEFAULT();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OAD_case_EXIT_CLOSE();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_STANDBY();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_DEFAULT();
#if 1
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_CLOSE_if();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_CLOSE_else();
#endif
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_STANDBY();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_EPG();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_DTV_MANUALTUNING();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_ATV_MANUALTUNING();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_CHANNELCHANGE();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_MMI();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_DMP();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_PVR_CHECK_FS();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_OSDPAGE();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_INPUTSOURCE();
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_INFO();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_MApp_TopStateMachine);

void TestSuite_MApp_TopStateMachine_setUp()
{
}

void TestSuite_MApp_TopStateMachine_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_GetTopStateName_CHANNELCHANGE */
/* CPPTEST_TEST_CASE_CONTEXT char * MApp_TopStateMachine_GetTopStateName(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_GetTopStateName_CHANNELCHANGE()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_CHANNELCHANGE;
    }
    {
        /* Tested function call */
        char * _return  = MApp_TopStateMachine_GetTopStateName();
        /* Post-condition check */
        CPPTEST_ASSERT_CSTR_EQUAL( "CHANNELCHANGE", ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_GetTopStateName_CHANNELCHANGE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_GetTopStateName_DIGITALINPUTS */
/* CPPTEST_TEST_CASE_CONTEXT char * MApp_TopStateMachine_GetTopStateName(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_GetTopStateName_DIGITALINPUTS()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_DIGITALINPUTS;
    }
    {
        /* Tested function call */
        char * _return  = MApp_TopStateMachine_GetTopStateName();
        /* Post-condition check */
        CPPTEST_ASSERT_CSTR_EQUAL( "DIGITALINPUTS", ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_GetTopStateName_DIGITALINPUTS */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_GetTopStateName_INPUTSOURCE */
/* CPPTEST_TEST_CASE_CONTEXT char * MApp_TopStateMachine_GetTopStateName(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_GetTopStateName_INPUTSOURCE()
{
    /* Pre-condition initialization */
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_INPUTSOURCE;
    }
    {
        /* Tested function call */
        char * _return  = MApp_TopStateMachine_GetTopStateName();
        /* Post-condition check */
        CPPTEST_ASSERT_CSTR_EQUAL( "INPUTSOURCE", ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_GetTopStateName_INPUTSOURCE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_DEFAULT_MHL_Cbus_Not_Connect */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_DEFAULT_MHL_Cbus_Not_Connect()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = 100;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DIGITALINPUTS, ( enTopState ) );
        CPPTEST_ASSERT_BOOL_EQUAL( 0, ( bMHLOSDFlag ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_DEFAULT_MHL_Cbus_Not_Connect */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_DEFAULT_MHL_Cbus_Connect_FlagIsTRUE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_DEFAULT_MHL_Cbus_Connect_FlagIsTRUE()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 1;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = 100;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DIGITALINPUTS, ( enTopState ) );
        CPPTEST_ASSERT_BOOL_EQUAL( 1, ( bMHLOSDFlag ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_DEFAULT_MHL_Cbus_Connect_FlagIsTRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_DEFAULT_MHL_Cbus_Connect_FlagIsFALSEandZUIGoing */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_DEFAULT_MHL_Cbus_Connect_FlagIsFALSEandZUIGoing()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = 100;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DIGITALINPUTS, ( enTopState ) );
        CPPTEST_ASSERT_BOOL_EQUAL( 1, ( bMHLOSDFlag ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_DEFAULT_MHL_Cbus_Connect_FlagIsFALSEandZUIGoing */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_DEFAULT_MHL_Cbus_Connect_FlagIsFALSEandZUINotGoing */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_DEFAULT_MHL_Cbus_Connect_FlagIsFALSEandZUINotGoing()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = 100;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DIGITALINPUTS, ( enTopState ) );
        CPPTEST_ASSERT_BOOL_EQUAL( 0, ( bMHLOSDFlag ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_DEFAULT_MHL_Cbus_Connect_FlagIsFALSEandZUINotGoing */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_TTX */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_TTX()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_TTX;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_TTX, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_TTX */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_ANALOG_SHOW_BANNER_case_EXIT_CLOSE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ANALOG_SHOW_BANNER_case_EXIT_CLOSE()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_ANALOG_SHOW_BANNER;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DIGITALINPUTS, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_ANALOG_SHOW_BANNER_case_EXIT_CLOSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_ANALOG_SHOW_BANNER_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ANALOG_SHOW_BANNER_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_ANALOG_SHOW_BANNER;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_ANALOG_SHOW_BANNER, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_ANALOG_SHOW_BANNER_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_CHANNELCHANGE_case_EXIT_CLOSE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_CHANNELCHANGE_case_EXIT_CLOSE()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
	  #if ENABLE_CEC
        CPPTEST_ASSERT_EQUAL( 0, ( bDuringChannelChange ) );
	  #endif
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DIGITALINPUTS, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_CHANNELCHANGE_case_EXIT_CLOSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_CHANNELCHANGE_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_CHANNELCHANGE_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
	  #if ENABLE_CEC
        CPPTEST_ASSERT_EQUAL( 1, ( bDuringChannelChange ) );
	  #endif
        CPPTEST_ASSERT_EQUAL( STATE_TOP_CHANNELCHANGE, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_CHANNELCHANGE_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsTRUE_case_EXIT_GOTO_CHANNELCHANGE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsTRUE_case_EXIT_GOTO_CHANNELCHANGE()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_DTV_SCAN;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = TRUE;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_ONLY;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_CHANNELCHANGE, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsTRUE_case_EXIT_GOTO_CHANNELCHANGE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsTRUE_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsTRUE_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_DTV_SCAN;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = TRUE;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_ONLY;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DTV_SCAN, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsTRUE_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_DTV_SCAN;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = FALSE;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_ONLY;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DTV_SCAN, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_EXIT_GOTO_PREVIOUS */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_EXIT_GOTO_PREVIOUS()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_DTV_SCAN;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = FALSE;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_ONLY;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( enTopStateBeforeScan, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_EXIT_GOTO_PREVIOUS */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_EXIT_GOTO_CHANNELCHANGE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_EXIT_GOTO_CHANNELCHANGE()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_DTV_SCAN;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = FALSE;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_ONLY;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_CHANNELCHANGE, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_EXIT_GOTO_CHANNELCHANGE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_EXIT_GOTO_TV */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_EXIT_GOTO_TV()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_DTV_SCAN;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = FALSE;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_ONLY;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( enTopStateBeforeScan, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_EXIT_GOTO_TV */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_EXIT_GOTO_STANDBY */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_EXIT_GOTO_STANDBY()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_DTV_SCAN;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = FALSE;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_ONLY;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_STANDBY, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_EXIT_GOTO_STANDBY */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_SCAN_NEW_MUX;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_SCAN_NEW_MUX, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_GOTO_PREVIOUS */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_GOTO_PREVIOUS()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_SCAN_NEW_MUX;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( enTopStateBeforeScan, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_GOTO_PREVIOUS */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_GOTO_CHANNELCHANGE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_GOTO_CHANNELCHANGE()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_SCAN_NEW_MUX;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_CHANNELCHANGE, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_GOTO_CHANNELCHANGE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_GOTO_WAIT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_GOTO_WAIT()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_SCAN_NEW_MUX;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DIGITALINPUTS, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_GOTO_WAIT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_GOTO_STANDBY */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_GOTO_STANDBY()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_SCAN_NEW_MUX;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_STANDBY, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_GOTO_STANDBY */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_ATV_SCAN;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_ATV_ONLY;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_ATV_SCAN, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_STANDBY */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_STANDBY()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_ATV_SCAN;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_ATV_ONLY;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_STANDBY, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_STANDBY */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_CHANNELCHANGE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_CHANNELCHANGE()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_ATV_SCAN;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_ATV_ONLY;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_CHANNELCHANGE, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_CHANNELCHANGE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_TV */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_TV()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_ATV_SCAN;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_ATV_ONLY;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DIGITALINPUTS, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_TV */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_PREVIOUS */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_PREVIOUS()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_ATV_SCAN;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_ATV_ONLY;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( enTopStateBeforeScan, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_PREVIOUS */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_DTV_SCAN */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_DTV_SCAN()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_ATV_SCAN;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_ATV_ONLY;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DTV_SCAN, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_DTV_SCAN */

#if(ENABLE_SBTVD_BRAZIL_APP)
/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_CATV_SCAN */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_CATV_SCAN()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_ATV_SCAN;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_ATV_ONLY;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_CATV_SCAN, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_CATV_SCAN */
#endif

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_DIGITALINPUTS;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DIGITALINPUTS, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_USB */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_USB()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_DIGITALINPUTS;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_USB_DOWNLOAD, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_USB */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_OAD */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_OAD()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_DIGITALINPUTS;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_OAD, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_OAD */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_MENU */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_MENU()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_DIGITALINPUTS;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_MENU, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_MENU */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_INSTALLGUIDE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_INSTALLGUIDE()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_DIGITALINPUTS;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_INSTALLGUIDE, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_INSTALLGUIDE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_STANDBY */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_STANDBY()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_DIGITALINPUTS;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_STANDBY, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_STANDBY */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_CHANNELCHANGE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_CHANNELCHANGE()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_DIGITALINPUTS;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_CHANNELCHANGE, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_CHANNELCHANGE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_EPG */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_EPG()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_DIGITALINPUTS;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_EPG, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_EPG */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_INPUTSOURCE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_INPUTSOURCE()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_DIGITALINPUTS;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_INPUTSOURCE, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_INPUTSOURCE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_OSDPAGE22 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_OSDPAGE()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_DIGITALINPUTS;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_OSDPAGE, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_OSDPAGE */

#if ENABLE_CI
/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_MMI */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_MMI()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_DIGITALINPUTS;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_MMI, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_MMI */
#endif

#if ENABLE_DMP
/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_DMP */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_DMP()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_DIGITALINPUTS;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DMP, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_DMP */
#endif

#if (ENABLE_UPDATE_MULTIPLEX_VIA_NIT)
/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_SCAN_NEW_MUX */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_SCAN_NEW_MUX()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_DIGITALINPUTS;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_SCAN_NEW_MUX, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_SCAN_NEW_MUX */
#endif

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_PVR_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_PVR_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_PVR;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_PVR, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_PVR_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_PVR_case_EXIT_CLOSE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_PVR_case_EXIT_CLOSE()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_PVR;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DIGITALINPUTS, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_PVR_case_EXIT_CLOSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_PVR_case_EXIT_GOTO_STANDBY */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_PVR_case_EXIT_GOTO_STANDBY()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_PVR;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_STANDBY, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_PVR_case_EXIT_GOTO_STANDBY */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_PVR_case_EXIT_GOTO_MENU */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_PVR_case_EXIT_GOTO_MENU()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_PVR;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_MENU, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_PVR_case_EXIT_GOTO_MENU */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_DTV_MANUAL_TUNING;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DTV_MANUAL_TUNING, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_EXIT_CLOSE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_EXIT_CLOSE()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_DTV_MANUAL_TUNING;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DIGITALINPUTS, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_EXIT_CLOSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_EXIT_GOTO_STANDBY */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_EXIT_GOTO_STANDBY()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_DTV_MANUAL_TUNING;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_STANDBY, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_EXIT_GOTO_STANDBY */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_EXIT_GOTO_MENU */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_EXIT_GOTO_MENU()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_DTV_MANUAL_TUNING;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_MENU, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_EXIT_GOTO_MENU */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_EXIT_GOTO_DTVSCAN */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_EXIT_GOTO_DTVSCAN()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_DTV_MANUAL_TUNING;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DTV_SCAN, ( enTopState ) );
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DTV_MANUAL_TUNING, ( enTopStateBeforeScan ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_EXIT_GOTO_DTVSCAN */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_ATV_MANUAL_TUNING;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_ATV_MANUAL_TUNING, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_EXIT_CLOSE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_EXIT_CLOSE()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_ATV_MANUAL_TUNING;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DIGITALINPUTS, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_EXIT_CLOSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_EXIT_GOTO_STANDBY */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_EXIT_GOTO_STANDBY()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_ATV_MANUAL_TUNING;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_STANDBY, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_EXIT_GOTO_STANDBY */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_EXIT_GOTO_MENU */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_EXIT_GOTO_MENU()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_ATV_MANUAL_TUNING;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_MENU, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_EXIT_GOTO_MENU */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_EXIT_GOTO_DTVSCAN */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_EXIT_GOTO_ATVSCAN()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_ATV_MANUAL_TUNING;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_ATV_SCAN, ( enTopState ) );
        CPPTEST_ASSERT_EQUAL( STATE_TOP_ATV_MANUAL_TUNING, ( enTopStateBeforeScan ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_EXIT_GOTO_ATVSCAN */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_OSDPAGE;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_OSDPAGE, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_CLOSE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_CLOSE()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_OSDPAGE;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DIGITALINPUTS, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_CLOSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_CHANNELCHANGE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_CHANNELCHANGE()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_OSDPAGE;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_CHANNELCHANGE, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_CHANNELCHANGE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_MENU */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_MENU()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_OSDPAGE;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_MENU, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_MENU */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_EPG */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_EPG()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_OSDPAGE;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_EPG, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_EPG */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_INPUTSOURCE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_INPUTSOURCE()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_OSDPAGE;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_INPUTSOURCE, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_INPUTSOURCE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_STANDBY */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_STANDBY()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_OSDPAGE;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_STANDBY, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_STANDBY */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_DMP */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_DMP()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_OSDPAGE;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DMP, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_DMP */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_INSTALLGUIDE;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_INSTALLGUIDE, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_CLOSE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_CLOSE()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_INSTALLGUIDE;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DIGITALINPUTS, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_CLOSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_GOTO_STANDBY */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_GOTO_STANDBY()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_INSTALLGUIDE;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_STANDBY, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_GOTO_STANDBY */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_GOTO_SCAN */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_GOTO_SCAN()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_INSTALLGUIDE;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DIGITALINPUTS, ( enTopStateBeforeScan ) );
        CPPTEST_ASSERT_EQUAL( STATE_TOP_ATV_SCAN, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_GOTO_SCAN */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_GOTO_EPG */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_GOTO_EPG()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_INSTALLGUIDE;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_EPG, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_GOTO_EPG */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_GOTO_CHANNELCHANGE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_GOTO_CHANNELCHANGE()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_INSTALLGUIDE;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_CHANNELCHANGE, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_GOTO_CHANNELCHANGE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_EPG_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_EPG_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_EPG;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_EPG, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_EPG_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_EPG_case_EXIT_CLOSE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_EPG_case_EXIT_CLOSE()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_EPG;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DIGITALINPUTS, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_EPG_case_EXIT_CLOSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_EPG_case_EXIT_GOTO_MENU */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_EPG_case_EXIT_GOTO_MENU()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_EPG;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_MENU, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_EPG_case_EXIT_GOTO_MENU */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_EPG_case_EXIT_GOTO_STANDBY */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_EPG_case_EXIT_GOTO_STANDBY()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_EPG;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_STANDBY, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_EPG_case_EXIT_GOTO_STANDBY */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_INPUTSOURCE;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_INPUTSOURCE, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_case_EXIT_CLOSE_if */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_CLOSE_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_INPUTSOURCE;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DIGITALINPUTS, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_case_EXIT_CLOSE_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_CLOSE_else */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_CLOSE_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_INPUTSOURCE;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DIGITALINPUTS, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_CLOSE_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_STANDBY */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_STANDBY()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_INPUTSOURCE;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_STANDBY, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_STANDBY */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_DMP */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_DMP()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_INPUTSOURCE;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DMP, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_DMP */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_OSDPAGE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_OSDPAGE()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_INPUTSOURCE;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_OSDPAGE, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_OSDPAGE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_MENU */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_MENU()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_INPUTSOURCE;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_MENU, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_MENU */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_INFO */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_INFO()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_INPUTSOURCE;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_ANALOG_SHOW_BANNER, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_INFO */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_OAD_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OAD_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_OAD;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_OAD, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_OAD_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_OAD_case_EXIT_CLOSE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OAD_case_EXIT_CLOSE()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_OAD;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DIGITALINPUTS, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_OAD_case_EXIT_CLOSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_STANDBY */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_STANDBY()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_STANDBY;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_STANDBY, ( enTopState ) );
        CPPTEST_ASSERT_EQUAL( EN_POWER_DC_OFF, ( stGenSetting.stMiscSetting.bDCOnOff ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_STANDBY */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_MENU;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_MENU, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_DEFAULT */

#if 1
/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_CLOSE_if */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_CLOSE_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_MENU;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DIGITALINPUTS, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_CLOSE_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_CLOSE_else */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_CLOSE_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_MENU;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DIGITALINPUTS, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_CLOSE_else */
#endif

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_STANDBY */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_STANDBY()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_MENU;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_STANDBY, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_STANDBY */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_EPG */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_EPG()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_MENU;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_EPG, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_EPG */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_DTV_MANUALTUNING */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_DTV_MANUALTUNING()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_MENU;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DTV_MANUAL_TUNING, ( enTopState ) );
        CPPTEST_ASSERT_EQUAL( 0, ( g_CurSignalStrength ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_DTV_MANUALTUNING */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_ATV_MANUALTUNING */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_ATV_MANUALTUNING()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_MENU;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_ATV_MANUAL_TUNING, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_ATV_MANUALTUNING */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_CHANNELCHANGE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_CHANNELCHANGE()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_MENU;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_CHANNELCHANGE, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_CHANNELCHANGE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_MMI */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_MMI()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_MENU;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_MMI, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_MMI */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_DMP */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_DMP()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_MENU;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_DMP, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_DMP */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_PVR_CHECK_FS */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_PVR_CHECK_FS()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_MENU;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_PVR, ( enTopState ) );
        CPPTEST_ASSERT_EQUAL( STATE_PVR_CHECK_FS_INIT, ( enPvrState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_PVR_CHECK_FS */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_OSDPAGE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_OSDPAGE()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_MENU;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_OSDPAGE, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_OSDPAGE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_INPUTSOURCE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_INPUTSOURCE()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_MENU;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_INPUTSOURCE, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_INPUTSOURCE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_INFO */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_TopStateMachine(void) */
void TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_INFO()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32MHLOSDTime */
    {
         gU32MHLOSDTime  = 0ul;
    }
    /* Initializing global variable bMHLOSDFlag */
    {
         bMHLOSDFlag  = 0;
    }
    /* Initializing global variable bDuringChannelChange */
    {
         bDuringChannelChange  = 0;
    }
    /* Initializing global variable enTopState */
    {
         enTopState  = STATE_TOP_MENU;
    }
    /* Initializing global variable bShowOadScanPage */
    {
         bShowOadScanPage  = 0;
    }
    /* Initializing global variable u8OADpercentage */
    {
         u8OADpercentage  = 0;
    }
    /* Initializing global variable enTopStateBeforeScan */
    {
         enTopStateBeforeScan  = STATE_TOP_CHANNELCHANGE;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable eTuneType */
    {
         eTuneType  = OSD_TUNE_TYPE_DTV_PLUS_ATV;
    }
    /* Initializing global variable g_CurSignalStrength */
    {
         g_CurSignalStrength  = 0u;
    }
    /* Initializing global variable enPvrState */
    {
         enPvrState  = STATE_PVR_NULL;
    }
    {
        /* Tested function call */
        MApp_TopStateMachine();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( STATE_TOP_ANALOG_SHOW_BANNER, ( enTopState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_INFO */
