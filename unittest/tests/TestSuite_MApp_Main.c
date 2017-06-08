#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app/MApp_Main.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app/MApp_Main.c");

CPPTEST_TEST_SUITE(TestSuite_MApp_Main);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_PowerOn_Stage_Debug_isDecodeCommand_True);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_PowerOn_Stage_Debug_isg_bDebugProgStopFlag_FALSE);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_PowerOn_Stage_Debug_isg_bDebugProgStopFlag_TRUE);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_While_Loop_State_case_DEFAULT);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_INITIATION);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_LOAD_APP);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_POST_INIT);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_UART_PAUSE_if);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_UART_PAUSE_else);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_MULTITASKS);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_TOPSTATEMACHINE);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_INTERMEDIATE_MINI_DUMP);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_INTERMEDIATE_SYSTEM_POLLING);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_IDLE);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_INITIATION);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_01);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_02);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_03);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_04);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_05);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_06);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_07);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_08);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_09);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_10);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_11);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_12);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_13);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_14);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_15);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_16);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_17);
CPPTEST_TEST(TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_DONE);
CPPTEST_TEST_SUITE_END();


void TestSuite_MApp_Main_test_MApp_PowerOn_Stage_Debug_isDecodeCommand_True();
void TestSuite_MApp_Main_test_MApp_PowerOn_Stage_Debug_isg_bDebugProgStopFlag_FALSE();
void TestSuite_MApp_Main_test_MApp_PowerOn_Stage_Debug_isg_bDebugProgStopFlag_TRUE();
void TestSuite_MApp_Main_test_MApp_While_Loop_State_case_DEFAULT();
void TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_INITIATION();
void TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_LOAD_APP();
void TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_POST_INIT();
void TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_UART_PAUSE_if();
void TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_UART_PAUSE_else();
void TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_MULTITASKS();
void TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_TOPSTATEMACHINE();
void TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_INTERMEDIATE_MINI_DUMP();
void TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_INTERMEDIATE_SYSTEM_POLLING();
void TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_IDLE();
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_INITIATION();
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_01();
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_02();
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_03();
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_04();
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_05();
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_06();
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_07();
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_08();
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_09();
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_10();
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_11();
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_12();
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_13();
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_14();
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_15();
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_16();
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_17();
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_DONE();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_MApp_Main);

void TestSuite_MApp_Main_setUp()
{
}

void TestSuite_MApp_Main_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_PowerOn_Stage_Debug_isDecodeCommand_True */
/* CPPTEST_TEST_CASE_CONTEXT MS_BOOL MApp_PowerOn_Stage_Debug(void) */
void TestSuite_MApp_Main_test_MApp_PowerOn_Stage_Debug_isDecodeCommand_True()
{
        MS_BOOL _return  = MApp_PowerOn_Stage_Debug();
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
}
/* CPPTEST_TEST_CASE_END test_MApp_PowerOn_Stage_Debug_isDecodeCommand_True */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PowerOn_Stage_Debug_isg_bDebugProgStopFlag_FALSE */
/* CPPTEST_TEST_CASE_CONTEXT MS_BOOL MApp_PowerOn_Stage_Debug(void) */
void TestSuite_MApp_Main_test_MApp_PowerOn_Stage_Debug_isg_bDebugProgStopFlag_FALSE()
{
         g_bDebugProgStopFlag  = 0;
         MS_BOOL _return  = MApp_PowerOn_Stage_Debug();
         CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
}
/* CPPTEST_TEST_CASE_END test_MApp_PowerOn_Stage_Debug_isg_bDebugProgStopFlag_FALSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PowerOn_Stage_Debug_isg_bDebugProgStopFlag_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT MS_BOOL MApp_PowerOn_Stage_Debug(void) */
void TestSuite_MApp_Main_test_MApp_PowerOn_Stage_Debug_isg_bDebugProgStopFlag_TRUE()
{
         g_bDebugProgStopFlag  = 1;
         MS_BOOL _return  = MApp_PowerOn_Stage_Debug();
         CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
}
/* CPPTEST_TEST_CASE_END test_MApp_PowerOn_Stage_Debug_isg_bDebugProgStopFlag_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_While_Loop_State_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_While_Loop_State(void) */
void TestSuite_MApp_Main_test_MApp_While_Loop_State_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bDebugProgStopFlag */
    {
         g_bDebugProgStopFlag  = 0;
    }
    /* Initializing global variable enWhileLoop_Sub_State */
    {
         enWhileLoop_Sub_State  = EN_WHILE_LOOP_DONE;
    }
    {
        /* Tested function call */
        MApp_While_Loop_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_WHILE_LOOP_DONE, ( enWhileLoop_Sub_State ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_While_Loop_State_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_While_Loop_State_case_EN_WHILE_LOOP_INITIATION */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_While_Loop_State(void) */
void TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_INITIATION()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bDebugProgStopFlag */
    {
         g_bDebugProgStopFlag  = 0;
    }
    /* Initializing global variable enWhileLoop_Sub_State */
    {
         enWhileLoop_Sub_State  = EN_WHILE_LOOP_INITIATION;
    }
    {
        /* Tested function call */
        MApp_While_Loop_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_WHILE_LOOP_LOAD_APP, ( enWhileLoop_Sub_State ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_While_Loop_State_case_EN_WHILE_LOOP_INITIATION */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_While_Loop_State_case_EN_WHILE_LOOP_LOAD_APP */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_While_Loop_State(void) */
void TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_LOAD_APP()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bDebugProgStopFlag */
    {
         g_bDebugProgStopFlag  = 0;
    }
    /* Initializing global variable enWhileLoop_Sub_State */
    {
         enWhileLoop_Sub_State  = EN_WHILE_LOOP_LOAD_APP;
    }
    {
        /* Tested function call */
        MApp_While_Loop_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_WHILE_LOOP_POST_INIT, ( enWhileLoop_Sub_State ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_While_Loop_State_case_EN_WHILE_LOOP_LOAD_APP */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_While_Loop_State_case_EN_WHILE_LOOP_POST_INIT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_While_Loop_State(void) */
void TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_POST_INIT()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bDebugProgStopFlag */
    {
         g_bDebugProgStopFlag  = 0;
    }
    /* Initializing global variable enWhileLoop_Sub_State */
    {
         enWhileLoop_Sub_State  = EN_WHILE_LOOP_POST_INIT;
    }
    {
        /* Tested function call */
        MApp_While_Loop_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_WHILE_LOOP_UART_PAUSE, ( enWhileLoop_Sub_State ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_While_Loop_State_case_EN_WHILE_LOOP_POST_INIT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_While_Loop_State_case_EN_WHILE_LOOP_UART_PAUSE_if */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_While_Loop_State(void) */
void TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_UART_PAUSE_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bDebugProgStopFlag */
    {
         g_bDebugProgStopFlag  = 0;
    }
    /* Initializing global variable enWhileLoop_Sub_State */
    {
         enWhileLoop_Sub_State  = EN_WHILE_LOOP_UART_PAUSE;
    }
    {
        /* Tested function call */
        MApp_While_Loop_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_WHILE_LOOP_UART_PAUSE, ( enWhileLoop_Sub_State ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_While_Loop_State_case_EN_WHILE_LOOP_UART_PAUSE_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_While_Loop_State_case_EN_WHILE_LOOP_UART_PAUSE_else */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_While_Loop_State(void) */
void TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_UART_PAUSE_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bDebugProgStopFlag */
    {
         g_bDebugProgStopFlag  = 0;
    }
    /* Initializing global variable enWhileLoop_Sub_State */
    {
         enWhileLoop_Sub_State  = EN_WHILE_LOOP_UART_PAUSE;
    }
    {
        /* Tested function call */
        MApp_While_Loop_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_WHILE_LOOP_MULTITASKS, ( enWhileLoop_Sub_State ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_While_Loop_State_case_EN_WHILE_LOOP_UART_PAUSE_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_While_Loop_State_case_EN_WHILE_LOOP_MULTITASKS */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_While_Loop_State(void) */
void TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_MULTITASKS()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bDebugProgStopFlag */
    {
         g_bDebugProgStopFlag  = 0;
    }
    /* Initializing global variable enWhileLoop_Sub_State */
    {
         enWhileLoop_Sub_State  = EN_WHILE_LOOP_MULTITASKS;
    }
    {
        /* Tested function call */
        MApp_While_Loop_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_WHILE_LOOP_TOPSTATEMACHINE, ( enWhileLoop_Sub_State ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_While_Loop_State_case_EN_WHILE_LOOP_MULTITASKS */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_While_Loop_State_case_EN_WHILE_LOOP_TOPSTATEMACHINE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_While_Loop_State(void) */
void TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_TOPSTATEMACHINE()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bDebugProgStopFlag */
    {
         g_bDebugProgStopFlag  = 0;
    }
    /* Initializing global variable enWhileLoop_Sub_State */
    {
         enWhileLoop_Sub_State  = EN_WHILE_LOOP_TOPSTATEMACHINE;
    }
    {
        /* Tested function call */
        MApp_While_Loop_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_WHILE_LOOP_INTERMEDIATE_MINI_DUMP, ( enWhileLoop_Sub_State ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_While_Loop_State_case_EN_WHILE_LOOP_TOPSTATEMACHINE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_While_Loop_State_case_EN_WHILE_LOOP_INTERMEDIATE_MINI_DUMP */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_While_Loop_State(void) */
void TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_INTERMEDIATE_MINI_DUMP()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bDebugProgStopFlag */
    {
         g_bDebugProgStopFlag  = 0;
    }
    /* Initializing global variable enWhileLoop_Sub_State */
    {
         enWhileLoop_Sub_State  = EN_WHILE_LOOP_INTERMEDIATE_MINI_DUMP;
    }
    {
        /* Tested function call */
        MApp_While_Loop_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_WHILE_LOOP_INTERMEDIATE_SYSTEM_POLLING, ( enWhileLoop_Sub_State ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_While_Loop_State_case_EN_WHILE_LOOP_INTERMEDIATE_MINI_DUMP */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_While_Loop_State_case_EN_WHILE_LOOP_INTERMEDIATE_SYSTEM_POLLING */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_While_Loop_State(void) */
void TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_INTERMEDIATE_SYSTEM_POLLING()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bDebugProgStopFlag */
    {
         g_bDebugProgStopFlag  = 0;
    }
    /* Initializing global variable enWhileLoop_Sub_State */
    {
         enWhileLoop_Sub_State  = EN_WHILE_LOOP_INTERMEDIATE_SYSTEM_POLLING;
    }
    {
        /* Tested function call */
        MApp_While_Loop_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_WHILE_LOOP_IDLE, ( enWhileLoop_Sub_State ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_While_Loop_State_case_EN_WHILE_LOOP_INTERMEDIATE_SYSTEM_POLLING */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_While_Loop_State_case_EN_WHILE_LOOP_IDLE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_While_Loop_State(void) */
void TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_IDLE()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_bDebugProgStopFlag */
    {
         g_bDebugProgStopFlag  = 0;
    }
    /* Initializing global variable enWhileLoop_Sub_State */
    {
         enWhileLoop_Sub_State  = EN_WHILE_LOOP_IDLE;
    }
    {
        /* Tested function call */
        MApp_While_Loop_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_WHILE_LOOP_INITIATION, ( enWhileLoop_Sub_State ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_While_Loop_State_case_EN_WHILE_LOOP_IDLE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PreInit_State_case_EN_PRE_INIT_INITIATION */
/* CPPTEST_TEST_CASE_CONTEXT MS_BOOL MApp_PreInit_State(void) */
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_INITIATION()
{
    /* Pre-condition initialization */
    /* Initializing global variable enPreInit_Sub_State */ 
    {
         enPreInit_Sub_State  = EN_PRE_INIT_INITIATION;
    }
    {
        /* Tested function call */
        MS_BOOL _return  = MApp_PreInit_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( PRE_INIT_ONGOING, ( _return ) )
        CPPTEST_ASSERT_EQUAL( EN_PRE_INIT_STAGE_01, ( enPreInit_Sub_State ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PreInit_State_case_EN_PRE_INIT_INITIATION */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_01 */
/* CPPTEST_TEST_CASE_CONTEXT MS_BOOL MApp_PreInit_State(void) */
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_01()
{
    /* Pre-condition initialization */
    /* Initializing global variable enPreInit_Sub_State */
    {
         enPreInit_Sub_State  = EN_PRE_INIT_STAGE_01;
    }
    {
        /* Tested function call */
        MS_BOOL _return  = MApp_PreInit_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( PRE_INIT_ONGOING, ( _return ) )
        CPPTEST_ASSERT_EQUAL( EN_PRE_INIT_STAGE_02, ( enPreInit_Sub_State ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_01 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_02 */
/* CPPTEST_TEST_CASE_CONTEXT MS_BOOL MApp_PreInit_State(void) */
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_02()
{
    /* Pre-condition initialization */
    /* Initializing global variable enPreInit_Sub_State */
    {
         enPreInit_Sub_State  = EN_PRE_INIT_STAGE_02;
    }
    {
        /* Tested function call */
        MS_BOOL _return  = MApp_PreInit_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( PRE_INIT_ONGOING, ( _return ) )
        CPPTEST_ASSERT_EQUAL( EN_PRE_INIT_STAGE_03, ( enPreInit_Sub_State ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_02 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_03 */
/* CPPTEST_TEST_CASE_CONTEXT MS_BOOL MApp_PreInit_State(void) */
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_03()
{
    /* Pre-condition initialization */
    /* Initializing global variable enPreInit_Sub_State */
    {
         enPreInit_Sub_State  = EN_PRE_INIT_STAGE_03;
    }
    {
        /* Tested function call */
        MS_BOOL _return  = MApp_PreInit_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( PRE_INIT_ONGOING, ( _return ) )
        CPPTEST_ASSERT_EQUAL( EN_PRE_INIT_STAGE_04, ( enPreInit_Sub_State ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_03 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_04 */
/* CPPTEST_TEST_CASE_CONTEXT MS_BOOL MApp_PreInit_State(void) */
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_04()
{
    /* Pre-condition initialization */
    /* Initializing global variable enPreInit_Sub_State */
    {
         enPreInit_Sub_State  = EN_PRE_INIT_STAGE_04;
    }
    {
        /* Tested function call */
        MS_BOOL _return  = MApp_PreInit_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( PRE_INIT_ONGOING, ( _return ) )
        CPPTEST_ASSERT_EQUAL( EN_PRE_INIT_STAGE_05, ( enPreInit_Sub_State ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_04 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_05 */
/* CPPTEST_TEST_CASE_CONTEXT MS_BOOL MApp_PreInit_State(void) */
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_05()
{
    /* Pre-condition initialization */
    /* Initializing global variable enPreInit_Sub_State */
    {
         enPreInit_Sub_State  = EN_PRE_INIT_STAGE_05;
    }
    {
        /* Tested function call */
        MS_BOOL _return  = MApp_PreInit_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( PRE_INIT_ONGOING, ( _return ) )
        CPPTEST_ASSERT_EQUAL( EN_PRE_INIT_STAGE_06, ( enPreInit_Sub_State ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_05 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_06 */
/* CPPTEST_TEST_CASE_CONTEXT MS_BOOL MApp_PreInit_State(void) */
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_06()
{
    /* Pre-condition initialization */
    /* Initializing global variable enPreInit_Sub_State */
    {
         enPreInit_Sub_State  = EN_PRE_INIT_STAGE_06;
    }
    {
        /* Tested function call */
        MS_BOOL _return  = MApp_PreInit_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( PRE_INIT_ONGOING, ( _return ) )
        CPPTEST_ASSERT_EQUAL( EN_PRE_INIT_STAGE_07, ( enPreInit_Sub_State ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_06 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_07 */
/* CPPTEST_TEST_CASE_CONTEXT MS_BOOL MApp_PreInit_State(void) */
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_07()
{
    /* Pre-condition initialization */
    /* Initializing global variable enPreInit_Sub_State */
    {
         enPreInit_Sub_State  = EN_PRE_INIT_STAGE_07;
    }
    {
        /* Tested function call */
        MS_BOOL _return  = MApp_PreInit_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( PRE_INIT_ONGOING, ( _return ) )
        CPPTEST_ASSERT_EQUAL( EN_PRE_INIT_STAGE_08, ( enPreInit_Sub_State ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_07 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_08 */
/* CPPTEST_TEST_CASE_CONTEXT MS_BOOL MApp_PreInit_State(void) */
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_08()
{
    /* Pre-condition initialization */
    /* Initializing global variable enPreInit_Sub_State */
    {
         enPreInit_Sub_State  = EN_PRE_INIT_STAGE_08;
    }
    {
        /* Tested function call */
        MS_BOOL _return  = MApp_PreInit_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( PRE_INIT_ONGOING, ( _return ) )
        CPPTEST_ASSERT_EQUAL( EN_PRE_INIT_STAGE_09, ( enPreInit_Sub_State ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_08 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_09 */
/* CPPTEST_TEST_CASE_CONTEXT MS_BOOL MApp_PreInit_State(void) */
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_09()
{
    /* Pre-condition initialization */
    /* Initializing global variable enPreInit_Sub_State */
    {
         enPreInit_Sub_State  = EN_PRE_INIT_STAGE_09;
    }
    {
        /* Tested function call */
        MS_BOOL _return  = MApp_PreInit_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( PRE_INIT_ONGOING, ( _return ) )
        CPPTEST_ASSERT_EQUAL( EN_PRE_INIT_STAGE_10, ( enPreInit_Sub_State ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_09 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_10 */
/* CPPTEST_TEST_CASE_CONTEXT MS_BOOL MApp_PreInit_State(void) */
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_10()
{
    /* Pre-condition initialization */
    /* Initializing global variable enPreInit_Sub_State */
    {
         enPreInit_Sub_State  = EN_PRE_INIT_STAGE_10;
    }
    {
        /* Tested function call */
        MS_BOOL _return  = MApp_PreInit_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( PRE_INIT_ONGOING, ( _return ) )
        CPPTEST_ASSERT_EQUAL( EN_PRE_INIT_STAGE_11, ( enPreInit_Sub_State ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_10 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_11 */
/* CPPTEST_TEST_CASE_CONTEXT MS_BOOL MApp_PreInit_State(void) */
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_11()
{
    /* Pre-condition initialization */
    /* Initializing global variable enPreInit_Sub_State */
    {
         enPreInit_Sub_State  = EN_PRE_INIT_STAGE_11;
    }
    {
        /* Tested function call */
        MS_BOOL _return  = MApp_PreInit_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( PRE_INIT_ONGOING, ( _return ) )
        CPPTEST_ASSERT_EQUAL( EN_PRE_INIT_STAGE_12, ( enPreInit_Sub_State ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_11 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_12 */
/* CPPTEST_TEST_CASE_CONTEXT MS_BOOL MApp_PreInit_State(void) */
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_12()
{
    /* Pre-condition initialization */
    /* Initializing global variable enPreInit_Sub_State */
    {
         enPreInit_Sub_State  = EN_PRE_INIT_STAGE_12;
    }
    {
        /* Tested function call */
        MS_BOOL _return  = MApp_PreInit_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( PRE_INIT_ONGOING, ( _return ) )
        CPPTEST_ASSERT_EQUAL( EN_PRE_INIT_STAGE_13, ( enPreInit_Sub_State ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_12 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_13 */
/* CPPTEST_TEST_CASE_CONTEXT MS_BOOL MApp_PreInit_State(void) */
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_13()
{
    /* Pre-condition initialization */
    /* Initializing global variable enPreInit_Sub_State */
    {
         enPreInit_Sub_State  = EN_PRE_INIT_STAGE_13;
    }
    {
        /* Tested function call */
        MS_BOOL _return  = MApp_PreInit_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( PRE_INIT_ONGOING, ( _return ) )
        CPPTEST_ASSERT_EQUAL( EN_PRE_INIT_STAGE_14, ( enPreInit_Sub_State ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_13 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_14 */
/* CPPTEST_TEST_CASE_CONTEXT MS_BOOL MApp_PreInit_State(void) */
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_14()
{
    /* Pre-condition initialization */
    /* Initializing global variable enPreInit_Sub_State */
    {
         enPreInit_Sub_State  = EN_PRE_INIT_STAGE_14;
    }
    {
        /* Tested function call */
        MS_BOOL _return  = MApp_PreInit_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( PRE_INIT_ONGOING, ( _return ) )
        CPPTEST_ASSERT_EQUAL( EN_PRE_INIT_STAGE_15, ( enPreInit_Sub_State ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_14 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_15 */
/* CPPTEST_TEST_CASE_CONTEXT MS_BOOL MApp_PreInit_State(void) */
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_15()
{
    /* Pre-condition initialization */
    /* Initializing global variable enPreInit_Sub_State */
    {
         enPreInit_Sub_State  = EN_PRE_INIT_STAGE_15;
    }
    {
        /* Tested function call */
        MS_BOOL _return  = MApp_PreInit_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( PRE_INIT_ONGOING, ( _return ) )
        CPPTEST_ASSERT_EQUAL( EN_PRE_INIT_STAGE_16, ( enPreInit_Sub_State ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_15 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_16 */
/* CPPTEST_TEST_CASE_CONTEXT MS_BOOL MApp_PreInit_State(void) */
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_16()
{
    /* Pre-condition initialization */
    /* Initializing global variable enPreInit_Sub_State */
    {
         enPreInit_Sub_State  = EN_PRE_INIT_STAGE_16;
    }
    {
        /* Tested function call */
        MS_BOOL _return  = MApp_PreInit_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( PRE_INIT_ONGOING, ( _return ) )
        CPPTEST_ASSERT_EQUAL( EN_PRE_INIT_STAGE_17, ( enPreInit_Sub_State ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_16 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_17 */
/* CPPTEST_TEST_CASE_CONTEXT MS_BOOL MApp_PreInit_State(void) */
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_17()
{
    /* Pre-condition initialization */
    /* Initializing global variable enPreInit_Sub_State */
    {
         enPreInit_Sub_State  = EN_PRE_INIT_STAGE_17;
    }
    {
        /* Tested function call */
        MS_BOOL _return  = MApp_PreInit_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( PRE_INIT_ONGOING, ( _return ) )
        CPPTEST_ASSERT_EQUAL( EN_PRE_INIT_STAGE_18, ( enPreInit_Sub_State ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_17 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_DONE */
/* CPPTEST_TEST_CASE_CONTEXT MS_BOOL MApp_PreInit_State(void) */
void TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_DONE()
{
    /* Pre-condition initialization */
    /* Initializing global variable enPreInit_Sub_State */
    {
         enPreInit_Sub_State  = EN_PRE_INIT_STAGE_DONE;
    }
    {
        /* Tested function call */
        MS_BOOL _return  = MApp_PreInit_State();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( PRE_INIT_DONE, ( _return ) )
        CPPTEST_ASSERT_EQUAL( EN_PRE_INIT_STAGE_DONE, ( enPreInit_Sub_State ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_DONE */