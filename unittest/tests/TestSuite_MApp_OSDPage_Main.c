#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app/MApp_OSDPage_Main.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app/MApp_OSDPage_Main.c");

CPPTEST_TEST_SUITE(TestSuite_MApp_OSDPage_Main);
CPPTEST_TEST(TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_INIT);
CPPTEST_TEST(TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_WAIT);
CPPTEST_TEST(TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_CHANGE_PAGE);
CPPTEST_TEST(TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_CLEAN_UP);
CPPTEST_TEST(TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_GOTO_DMP);
CPPTEST_TEST(TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_GOTO_MAIN_MENU);
CPPTEST_TEST(TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_GOTO_INPUT_SOURCE);
CPPTEST_TEST(TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_GOTO_STANDBY);
CPPTEST_TEST(TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_EXIT);
CPPTEST_TEST(TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_default);
CPPTEST_TEST(TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_SetState);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_INIT();
void TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_WAIT();
void TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_CHANGE_PAGE();
void TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_CLEAN_UP();
void TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_GOTO_DMP();
void TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_GOTO_MAIN_MENU();
void TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_GOTO_INPUT_SOURCE();
void TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_GOTO_STANDBY();
void TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_EXIT();
void TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_default();
void TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_SetState();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_MApp_OSDPage_Main);

void TestSuite_MApp_OSDPage_Main_setUp()
{
}

void TestSuite_MApp_OSDPage_Main_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_OSDPage_Main_STATE_OSDPAGE_INIT */
/* CPPTEST_TEST_CASE_CONTEXT EN_RET MApp_OSDPage_Main(void) */
void TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_INIT()
{
    /* Pre-condition initialization */
    /* Initializing global variable enOSDPageState */ 
    {
         enOSDPageState  = STATE_OSDPAGE_INIT;
    }
    /* Initializing global variable enOSDPage */ 
    {
         enOSDPage  = E_OSD_EMPTY;
    }
    /* Initializing global variable u8KeyCode */ 
    {
         u8KeyCode  = 0;
    }
    {
        /* Tested function call */
        EN_RET _return  = MApp_OSDPage_Main();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EXIT_NULL, ( _return ) );
        CPPTEST_ASSERT_EQUAL( STATE_OSDPAGE_WAIT, ( enOSDPageState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_OSDPage_Main_STATE_OSDPAGE_INIT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_OSDPage_Main_STATE_OSDPAGE_WAIT */
/* CPPTEST_TEST_CASE_CONTEXT EN_RET MApp_OSDPage_Main(void) */
void TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_WAIT()
{
    /* Pre-condition initialization */
    /* Initializing global variable enOSDPageState */ 
    {
         enOSDPageState  = STATE_OSDPAGE_WAIT;
    }
    /* Initializing global variable enOSDPage */ 
    {
         enOSDPage  = E_OSD_EMPTY;
    }
    /* Initializing global variable u8KeyCode */ 
    {
         u8KeyCode  = 0;
    }
    {
        /* Tested function call */
        EN_RET _return  = MApp_OSDPage_Main();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EXIT_NULL, ( _return ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(KEY_NULL, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_OSDPage_Main_STATE_OSDPAGE_WAIT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_OSDPage_Main_STATE_OSDPAGE_CHANGE_PAGE */
/* CPPTEST_TEST_CASE_CONTEXT EN_RET MApp_OSDPage_Main(void) */
void TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_CHANGE_PAGE()
{
    /* Pre-condition initialization */
    /* Initializing global variable enOSDPageState */ 
    {
         enOSDPageState  = STATE_OSDPAGE_CHANGE_PAGE;
    }
    /* Initializing global variable enOSDPage */ 
    {
         enOSDPage  = E_OSD_EMPTY;
    }
    /* Initializing global variable u8KeyCode */ 
    {
         u8KeyCode  = 0;
    }
    {
        /* Tested function call */
        EN_RET _return  = MApp_OSDPage_Main();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EXIT_NULL, _return );
        CPPTEST_ASSERT_EQUAL( STATE_OSDPAGE_INIT, enOSDPageState );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_OSDPage_Main_STATE_OSDPAGE_CHANGE_PAGE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_OSDPage_Main_STATE_OSDPAGE_CLEAN_UP */
/* CPPTEST_TEST_CASE_CONTEXT EN_RET MApp_OSDPage_Main(void) */
void TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_CLEAN_UP()
{
    /* Pre-condition initialization */
    /* Initializing global variable enOSDPageState */ 
    {
         enOSDPageState  = STATE_OSDPAGE_CLEAN_UP;
    }
    /* Initializing global variable enOSDPage */ 
    {
         enOSDPage  = E_OSD_EMPTY;
    }
    /* Initializing global variable u8KeyCode */ 
    {
         u8KeyCode  = 0;
    }
    {
        /* Tested function call */
        EN_RET _return  = MApp_OSDPage_Main();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EXIT_CLOSE, ( _return ) );
        CPPTEST_ASSERT_EQUAL( STATE_OSDPAGE_INIT, ( enOSDPageState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_OSDPage_Main_STATE_OSDPAGE_CLEAN_UP */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_OSDPage_Main_STATE_OSDPAGE_GOTO_DMP */
/* CPPTEST_TEST_CASE_CONTEXT EN_RET MApp_OSDPage_Main(void) */
void TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_GOTO_DMP()
{
    /* Pre-condition initialization */
    /* Initializing global variable enOSDPageState */ 
    {
         enOSDPageState  = STATE_OSDPAGE_GOTO_DMP;
    }
    /* Initializing global variable enOSDPage */ 
    {
         enOSDPage  = E_OSD_EMPTY;
    }
    /* Initializing global variable u8KeyCode */ 
    {
         u8KeyCode  = 0;
    }
    {
        /* Tested function call */
        EN_RET _return  = MApp_OSDPage_Main();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EXIT_GOTO_DMP, ( _return ) );
        CPPTEST_ASSERT_EQUAL( STATE_OSDPAGE_INIT, ( enOSDPageState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_OSDPage_Main_STATE_OSDPAGE_GOTO_DMP */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_OSDPage_Main_STATE_OSDPAGE_GOTO_MAIN_MENU */
/* CPPTEST_TEST_CASE_CONTEXT EN_RET MApp_OSDPage_Main(void) */
void TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_GOTO_MAIN_MENU()
{
    /* Pre-condition initialization */
    /* Initializing global variable enOSDPageState */ 
    {
         enOSDPageState  = STATE_OSDPAGE_GOTO_MAIN_MENU;
    }
    /* Initializing global variable enOSDPage */ 
    {
         enOSDPage  = E_OSD_EMPTY;
    }
    /* Initializing global variable u8KeyCode */ 
    {
         u8KeyCode  = 0;
    }
    {
        /* Tested function call */
        EN_RET _return  = MApp_OSDPage_Main();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EXIT_GOTO_MENU, ( _return ) );
        CPPTEST_ASSERT_EQUAL( STATE_OSDPAGE_INIT, ( enOSDPageState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_OSDPage_Main_STATE_OSDPAGE_GOTO_MAIN_MENU */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_OSDPage_Main_STATE_OSDPAGE_GOTO_INPUT_SOURCE */
/* CPPTEST_TEST_CASE_CONTEXT EN_RET MApp_OSDPage_Main(void) */
void TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_GOTO_INPUT_SOURCE()
{
    /* Pre-condition initialization */
    /* Initializing global variable enOSDPageState */ 
    {
         enOSDPageState  = STATE_OSDPAGE_GOTO_INPUT_SOURCE;
    }
    /* Initializing global variable enOSDPage */ 
    {
         enOSDPage  = E_OSD_EMPTY;
    }
    /* Initializing global variable u8KeyCode */ 
    {
         u8KeyCode  = 0;
    }
    {
        /* Tested function call */
        EN_RET _return  = MApp_OSDPage_Main();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EXIT_GOTO_INPUTSOURCE, ( _return ) );
        CPPTEST_ASSERT_EQUAL( STATE_OSDPAGE_INIT, ( enOSDPageState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_OSDPage_Main_STATE_OSDPAGE_GOTO_INPUT_SOURCE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_OSDPage_Main_STATE_OSDPAGE_GOTO_STANDBY */
/* CPPTEST_TEST_CASE_CONTEXT EN_RET MApp_OSDPage_Main(void) */
void TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_GOTO_STANDBY()
{
    /* Pre-condition initialization */
    /* Initializing global variable enOSDPageState */ 
    {
         enOSDPageState  = STATE_OSDPAGE_GOTO_STANDBY;
    }
    /* Initializing global variable enOSDPage */ 
    {
         enOSDPage  = E_OSD_EMPTY;
    }
    /* Initializing global variable u8KeyCode */ 
    {
         u8KeyCode  = KEY_POWER;
    }
    {
        /* Tested function call */
        EN_RET _return  = MApp_OSDPage_Main();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EXIT_GOTO_STANDBY, ( _return ) );
        CPPTEST_ASSERT_EQUAL(KEY_POWER, ( u8KeyCode ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_OSDPage_Main_STATE_OSDPAGE_GOTO_STANDBY */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_OSDPage_Main_STATE_OSDPAGE_EXIT */
/* CPPTEST_TEST_CASE_CONTEXT EN_RET MApp_OSDPage_Main(void) */
void TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_STATE_OSDPAGE_EXIT()
{
    /* Pre-condition initialization */
    /* Initializing global variable enOSDPageState */ 
    {
         enOSDPageState  = STATE_OSDPAGE_EXIT;
    }
    /* Initializing global variable enOSDPage */ 
    {
         enOSDPage  = E_OSD_EMPTY;
    }
    /* Initializing global variable u8KeyCode */ 
    {
         u8KeyCode  = 0;
    }
    {
        /* Tested function call */
        EN_RET _return  = MApp_OSDPage_Main();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EXIT_CLOSE, ( _return ) );
        CPPTEST_ASSERT_EQUAL( STATE_OSDPAGE_INIT, ( enOSDPageState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_OSDPage_Main_STATE_OSDPAGE_EXIT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_OSDPage_Main_default */
/* CPPTEST_TEST_CASE_CONTEXT EN_RET MApp_OSDPage_Main(void) */
void TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_Main_default()
{
    /* Pre-condition initialization */
    /* Initializing global variable enOSDPageState */ 
    {
         enOSDPageState  = 20;
    }
    /* Initializing global variable enOSDPage */ 
    {
         enOSDPage  = E_OSD_EMPTY;
    }
    /* Initializing global variable u8KeyCode */ 
    {
         u8KeyCode  = 0;
    }
    {
        /* Tested function call */
        EN_RET _return  = MApp_OSDPage_Main();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EXIT_NULL, ( _return ) );
        CPPTEST_ASSERT_EQUAL( STATE_OSDPAGE_WAIT, ( enOSDPageState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_OSDPage_Main_default */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_OSDPage_SetState */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_OSDPage_SetState(EN_OSDPAGE_STATE) */
void TestSuite_MApp_OSDPage_Main_test_MApp_OSDPage_SetState()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enState) */ 
    EN_OSDPAGE_STATE _enState  = STATE_OSDPAGE_INIT;
    /* Initializing global variable enOSDPageState */ 
    {
         enOSDPageState  = STATE_OSDPAGE_INIT;
    }
    {
        /* Tested function call */
        MApp_OSDPage_SetState(_enState);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _enState, ( enOSDPageState ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_OSDPage_SetState */
