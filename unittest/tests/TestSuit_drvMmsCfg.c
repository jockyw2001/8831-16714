#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/mms/cfg/drvMmsCfg.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/mms/cfg/drvMmsCfg.c");

CPPTEST_TEST_SUITE(TestSuit_drvMmsCfg);
CPPTEST_TEST(TestSuit_drvMmsCfg_test_CfgLevel0Decode);
CPPTEST_TEST(TestSuit_drvMmsCfg_test_CfgLevel1Decode_if_CFG_FUN_MAX);
CPPTEST_TEST(TestSuit_drvMmsCfg_test_CfgLevel2Decode);
CPPTEST_TEST(TestSuit_drvMmsCfg_test_CfgLevel3Decode);
CPPTEST_TEST(TestSuit_drvMmsCfg_test_CfgLevel4Decode);
CPPTEST_TEST(TestSuit_drvMmsCfg_test_Cfgevel5Decode);
CPPTEST_TEST(TestSuit_drvMmsCfg_test_MCfg_BoardDbg2PrePage);
CPPTEST_TEST(TestSuit_drvMmsCfg_test_MCfg_BoardDbgDecode);
CPPTEST_TEST(TestSuit_drvMmsCfg_test_MCfg_ChipDbgDecode);
CPPTEST_TEST(TestSuit_drvMmsCfg_test_MCfg_SWDbgDecode);
CPPTEST_TEST(TestSuit_drvMmsCfg_test_MDrv_CfgGotoBoardMainPage);
CPPTEST_TEST(TestSuit_drvMmsCfg_test_MDrv_CfgGotoBoardMainPagePrint);
CPPTEST_TEST(TestSuit_drvMmsCfg_test_MDrv_CfgGotoCfgMainPage);
CPPTEST_TEST(TestSuit_drvMmsCfg_test_MDrv_CfgGotoChipMainPagePrint);
CPPTEST_TEST(TestSuit_drvMmsCfg_test_MDrv_CfgGotoPrePage);
CPPTEST_TEST(TestSuit_drvMmsCfg_test_MDrv_CfgGotoPrePagePrint);
CPPTEST_TEST(TestSuit_drvMmsCfg_test_MDrv_CfgGotoSWMainPage);
CPPTEST_TEST(TestSuit_drvMmsCfg_test_MDrv_CfgGotoSWMainPagePrint);
CPPTEST_TEST(TestSuit_drvMmsCfg_test_MDrv_CfgMainPagePrint);
CPPTEST_TEST(TestSuit_drvMmsCfg_test_MDrv_Cfg_ChipMenuPrint);
CPPTEST_TEST(TestSuit_drvMmsCfg_test_MDrv_Cfg_SWMenuPrint);
CPPTEST_TEST(TestSuit_drvMmsCfg_test_MDrv_Cfg_SetType);
CPPTEST_TEST_SUITE_END();


void TestSuit_drvMmsCfg_test_CfgLevel0Decode();
void TestSuit_drvMmsCfg_test_CfgLevel1Decode_if_CFG_FUN_MAX();
void TestSuit_drvMmsCfg_test_CfgLevel2Decode();
void TestSuit_drvMmsCfg_test_CfgLevel3Decode();
void TestSuit_drvMmsCfg_test_CfgLevel4Decode();
void TestSuit_drvMmsCfg_test_Cfgevel5Decode();
void TestSuit_drvMmsCfg_test_MCfg_BoardDbg2PrePage();
void TestSuit_drvMmsCfg_test_MCfg_BoardDbgDecode();
void TestSuit_drvMmsCfg_test_MCfg_ChipDbgDecode();
void TestSuit_drvMmsCfg_test_MCfg_SWDbgDecode();
void TestSuit_drvMmsCfg_test_MDrv_CfgGotoBoardMainPage();
void TestSuit_drvMmsCfg_test_MDrv_CfgGotoBoardMainPagePrint();
void TestSuit_drvMmsCfg_test_MDrv_CfgGotoCfgMainPage();
void TestSuit_drvMmsCfg_test_MDrv_CfgGotoChipMainPagePrint();
void TestSuit_drvMmsCfg_test_MDrv_CfgGotoPrePage();
void TestSuit_drvMmsCfg_test_MDrv_CfgGotoPrePagePrint();
void TestSuit_drvMmsCfg_test_MDrv_CfgGotoSWMainPage();
void TestSuit_drvMmsCfg_test_MDrv_CfgGotoSWMainPagePrint();
void TestSuit_drvMmsCfg_test_MDrv_CfgMainPagePrint();
void TestSuit_drvMmsCfg_test_MDrv_Cfg_ChipMenuPrint();
void TestSuit_drvMmsCfg_test_MDrv_Cfg_SWMenuPrint();
void TestSuit_drvMmsCfg_test_MDrv_Cfg_SetType();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuit_drvMmsCfg);

void TestSuit_drvMmsCfg_setUp()
{
}

void TestSuit_drvMmsCfg_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_CfgLevel0Decode */
/* CPPTEST_TEST_CASE_CONTEXT void CfgLevel0Decode(void) */
void TestSuit_drvMmsCfg_test_CfgLevel0Decode()
{
#if(ENABLE_MMS)
    /* Pre-condition initialization */
    /* Initializing global variable g_UartCommand */
    {
         g_UartCommand.Index  = 0;
         UART_MENU_CMD0  = 'c';
         UART_MENU_CMD1  = 'f';
         UART_MENU_CMD2  = 'g';
    }
    /* Initializing global variable CfgMenuLevel */
    {

         CfgMenuLevel  = 0;

    }
    {
        /* Tested function call */
        CfgLevel0Decode();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(1, ( CfgMenuLevel ));
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_CfgLevel0Decode */

/* CPPTEST_TEST_CASE_BEGIN test_CfgLevel1Decode_if_CFG_FUN_MAX */
/* CPPTEST_TEST_CASE_CONTEXT void CfgLevel1Decode(void) */
void TestSuit_drvMmsCfg_test_CfgLevel1Decode_if_CFG_FUN_MAX()
{
#if(ENABLE_MMS)
    /* Pre-condition initialization */
    /* Initializing global variable g_UartCommand */
    {
         g_UartCommand.Index  = 0;
         UART_MENU_CMD0  = 48;
         UART_MENU_CMD1  = 48;
         UART_MENU_CMD2  = 80;
    }
    /* Initializing global variable CfgMenuLevel */
    {
         CfgMenuLevel  = 1;
    }
    {
        /* Tested function call */
        CfgLevel1Decode();
        /* Post-condition check */
        // CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( g_CppTest_Stub_MDrv_CfgMainPagePrint_blnResult ));
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_CfgLevel1Decode_if_CFG_FUN_MAX */

/* CPPTEST_TEST_CASE_BEGIN test_CfgLevel2Decode */
/* CPPTEST_TEST_CASE_CONTEXT void CfgLevel2Decode(void) */
void TestSuit_drvMmsCfg_test_CfgLevel2Decode()
{
#if(ENABLE_MMS)
    /* Pre-condition initialization */
    /* Initializing global variable g_UartCommand */
    {
         g_UartCommand.Index  = 0;
         UART_MENU_CMD0  = 48;
         UART_MENU_CMD1  = 48;
         UART_MENU_CMD2  = 80;
    }
    /* Initializing global variable CfgMenuLevel */
    {
         CfgMenuLevel  = 0;
    }
    /* Initializing global variable cfg_level */
    {
         cfg_level  = 0u;
    }
    /* Initializing global variable cfg_type */
    {
         cfg_type  = BOARD;
    }
    {
        /* Tested function call */
        CfgLevel2Decode();
        /* Post-condition check */
        // CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
        // CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
        // CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_type", ( cfg_type ));
    }

    /* Initializing global variable cfg_type */
    {
        cfg_type  = CHIP;
    }
    {
        /* Tested function call */
        CfgLevel2Decode();
        /* Post-condition check */
        // CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
        // CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
        // CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_type", ( cfg_type ));
    }


    /* Initializing global variable cfg_type */
    {
        cfg_type  = SW;
    }
    {
        /* Tested function call */
        CfgLevel2Decode();
        /* Post-condition check */
        // CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
        // CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
        // CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_type", ( cfg_type ));
    }



    /* Pre-condition initialization */
    /* Initializing global variable g_UartCommand */
    {
         g_UartCommand.Index  = 0;
         UART_MENU_CMD0  = 48;
         UART_MENU_CMD1  = 48;
         UART_MENU_CMD2  = 48;
    }
    /* Initializing global variable cfg_type */
    {
         cfg_type  = BOARD;
    }
    {
        /* Tested function call */
        CfgLevel2Decode();
        /* Post-condition check */
        // CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
        // CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
        // CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_type", ( cfg_type ));
    }

    /* Initializing global variable cfg_type */
    {
        cfg_type  = CHIP;
    }
    {
        /* Tested function call */
        CfgLevel2Decode();
        /* Post-condition check */
        // CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
        // CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
        // CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_type", ( cfg_type ));
    }

    /* Initializing global variable cfg_type */
    {
        cfg_type  = SW;
    }
    {
        /* Tested function call */
        CfgLevel2Decode();
        /* Post-condition check */
        // CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
        // CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
        // CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_type", ( cfg_type ));
    }

    /* Initializing global variable cfg_type */
    {
        cfg_type  = 0;
    }
    {
        /* Tested function call */
        CfgLevel2Decode();
        /* Post-condition check */
        // CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
        // CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
        // CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_type", ( cfg_type ));
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_CfgLevel2Decode */

/* CPPTEST_TEST_CASE_BEGIN test_CfgLevel3Decode */
/* CPPTEST_TEST_CASE_CONTEXT void CfgLevel3Decode(void) */
void TestSuit_drvMmsCfg_test_CfgLevel3Decode()
{
#if(ENABLE_MMS)
    /* Pre-condition initialization */
    /* Initializing global variable g_UartCommand */
    {
         g_UartCommand.Index  = 0;
         UART_MENU_CMD0  = 48;
         UART_MENU_CMD1  = 48;
         UART_MENU_CMD2  = 80;
    }
    /* Initializing global variable CfgMenuLevel */
    {
         CfgMenuLevel  = 0;
    }
    {
        /* Tested function call */
        CfgLevel3Decode();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
    }

    /* Initializing global variable CfgMenuLevel */
    {
         CfgMenuLevel  = 1;
    }
    {
        /* Tested function call */
        CfgLevel3Decode();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
    }


    /* Pre-condition initialization */
    /* Initializing global variable g_UartCommand */
    {
         g_UartCommand.Index  = 0;
         UART_MENU_CMD0  = 48;
         UART_MENU_CMD1  = 48;
         UART_MENU_CMD2  = 48;
    }
    /* Initializing global variable CfgMenuLevel */
    {
         CfgMenuLevel  = 0;
    }
    {
        /* Tested function call */
        CfgLevel3Decode();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
    }

    /* Initializing global variable CfgMenuLevel */
    {
         CfgMenuLevel  = 1;
    }
    {
        /* Tested function call */
        CfgLevel3Decode();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_CfgLevel3Decode */

/* CPPTEST_TEST_CASE_BEGIN test_CfgLevel4Decode */
/* CPPTEST_TEST_CASE_CONTEXT void CfgLevel4Decode(void) */
void TestSuit_drvMmsCfg_test_CfgLevel4Decode()
{
#if(ENABLE_MMS)
    /* Pre-condition initialization */
    /* Initializing global variable g_UartCommand */
    {
         g_UartCommand.Index  = 0;
         UART_MENU_CMD0  = 48;
         UART_MENU_CMD1  = 48;
         UART_MENU_CMD2  = 80;
    }
    /* Initializing global variable CfgMenuLevel */
    {
         CfgMenuLevel  = 0;
    }
    {
        /* Tested function call */
        CfgLevel4Decode();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
    }
    /* Initializing global variable CfgMenuLevel */
    {
         CfgMenuLevel  = 1;
    }
    {
        /* Tested function call */
        CfgLevel4Decode();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
    }


    /* Pre-condition initialization */
    /* Initializing global variable g_UartCommand */
    {
         g_UartCommand.Index  = 0;
         UART_MENU_CMD0  = 48;
         UART_MENU_CMD1  = 48;
         UART_MENU_CMD2  = 60;
    }
    /* Initializing global variable CfgMenuLevel */
    {
         CfgMenuLevel  = 0;
    }
    {
        /* Tested function call */
        CfgLevel4Decode();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
    }


    /* Pre-condition initialization */
    /* Initializing global variable g_UartCommand */
    {
         g_UartCommand.Index  = 0;
         UART_MENU_CMD0  = 48;
         UART_MENU_CMD1  = 48;
         UART_MENU_CMD2  = 48;
    }
    /* Initializing global variable CfgMenuLevel */
    {
         CfgMenuLevel  = 0;
    }
    {
        /* Tested function call */
        CfgLevel4Decode();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
    }



    /* Pre-condition initialization */
    /* Initializing global variable g_UartCommand */
    {
         g_UartCommand.Index  = 0;
         UART_MENU_CMD0  = 48;
         UART_MENU_CMD1  = 48;
         UART_MENU_CMD2  = 48;
    }
    /* Initializing global variable CfgMenuLevel */
    {
         CfgMenuLevel  = 1;
    }
    {
        /* Tested function call */
        CfgLevel4Decode();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_CfgLevel4Decode */

/* CPPTEST_TEST_CASE_BEGIN test_Cfgevel5Decode */
/* CPPTEST_TEST_CASE_CONTEXT void Cfgevel5Decode(void) */
void TestSuit_drvMmsCfg_test_Cfgevel5Decode()
{
#if(ENABLE_MMS)
    /* Pre-condition initialization */
    /* Initializing global variable g_UartCommand */
    {
         g_UartCommand.Index  = 0;
         UART_MENU_CMD0  = 48;
         UART_MENU_CMD1  = 48;
         UART_MENU_CMD2  = 80;
    }
    /* Initializing global variable CfgMenuLevel */
    {
         CfgMenuLevel  = 0;
    }
    {
        /* Tested function call */
    	    Cfgevel5Decode();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
    }
    /* Initializing global variable CfgMenuLevel */
    {
         CfgMenuLevel  = 1;
    }
    {
        /* Tested function call */
	    Cfgevel5Decode();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
    }


    /* Pre-condition initialization */
    /* Initializing global variable g_UartCommand */
    {
         g_UartCommand.Index  = 0;
         UART_MENU_CMD0  = 48;
         UART_MENU_CMD1  = 48;
         UART_MENU_CMD2  = 60;
    }
    /* Initializing global variable CfgMenuLevel */
    {
         CfgMenuLevel  = 0;
    }
    {
        /* Tested function call */
	    Cfgevel5Decode();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
    }


    /* Pre-condition initialization */
    /* Initializing global variable g_UartCommand */
    {
         g_UartCommand.Index  = 0;
         UART_MENU_CMD0  = 48;
         UART_MENU_CMD1  = 48;
         UART_MENU_CMD2  = 48;
    }
    /* Initializing global variable CfgMenuLevel */
    {
         CfgMenuLevel  = 0;
    }
    {
        /* Tested function call */
	    Cfgevel5Decode();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
    }



    /* Pre-condition initialization */
    /* Initializing global variable g_UartCommand */
    {
         g_UartCommand.Index  = 0;
         UART_MENU_CMD0  = 48;
         UART_MENU_CMD1  = 48;
         UART_MENU_CMD2  = 48;
    }
    /* Initializing global variable CfgMenuLevel */
    {
         CfgMenuLevel  = 1;
    }
    {
        /* Tested function call */
	    Cfgevel5Decode();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_Cfgevel5Decode */


/* CPPTEST_TEST_CASE_BEGIN test_MCfg_BoardDbg2PrePage */
/* CPPTEST_TEST_CASE_CONTEXT void MCfg_BoardDbg2PrePage(void) */
void TestSuit_drvMmsCfg_test_MCfg_BoardDbg2PrePage()
{
#if(ENABLE_MMS)
    /* Pre-condition initialization */
    /* Initializing global variable CfgMenuLevel */
    {
         CfgMenuLevel  = 0;
    }
    {
        /* Tested function call */
        MCfg_BoardDbg2PrePage();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
    }


    /* Pre-condition initialization */
    /* Initializing global variable CfgMenuLevel */
    {
         CfgMenuLevel  = 3;
    }
    {
        /* Tested function call */
        MCfg_BoardDbg2PrePage();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MCfg_BoardDbg2PrePage */

/* CPPTEST_TEST_CASE_BEGIN test_MCfg_BoardDbgDecode */
/* CPPTEST_TEST_CASE_CONTEXT void MCfg_BoardDbgDecode(void) */
void TestSuit_drvMmsCfg_test_MCfg_BoardDbgDecode()
{
#if(ENABLE_MMS)
    /* Pre-condition initialization */
    /* Initializing global variable CfgMenuLevel */
    {
         CfgMenuLevel  = 0;
    }
    /* Initializing global variable cfg_level */
    {
         cfg_level  = 0u;
    }
    /* Initializing global variable cfg_type */
    {
         cfg_type  = 0u;
    }
    {
        /* Tested function call */
        MCfg_BoardDbgDecode();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
        //CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
        //CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_type", ( cfg_type ));
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MCfg_BoardDbgDecode */

/* CPPTEST_TEST_CASE_BEGIN test_MCfg_ChipDbgDecode */
/* CPPTEST_TEST_CASE_CONTEXT void MCfg_ChipDbgDecode(void) */
void TestSuit_drvMmsCfg_test_MCfg_ChipDbgDecode()
{
#if(ENABLE_MMS)
    /* Pre-condition initialization */
    /* Initializing global variable CfgMenuLevel */
    {
         CfgMenuLevel  = 0;
    }
    /* Initializing global variable cfg_level */
    {
         cfg_level  = 0u;
    }
    /* Initializing global variable cfg_type */
    {
         cfg_type  = 0u;
    }
    {
        /* Tested function call */
        MCfg_ChipDbgDecode();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
        //CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
        //CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_type", ( cfg_type ));
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MCfg_ChipDbgDecode */

/* CPPTEST_TEST_CASE_BEGIN test_MCfg_SWDbgDecode */
/* CPPTEST_TEST_CASE_CONTEXT void MCfg_SWDbgDecode(void) */
void TestSuit_drvMmsCfg_test_MCfg_SWDbgDecode()
{
#if(ENABLE_MMS)
    /* Pre-condition initialization */
    /* Initializing global variable CfgMenuLevel */
    {
         CfgMenuLevel  = 0;
    }
    /* Initializing global variable cfg_level */
    {
         cfg_level  = 0u;
    }
    /* Initializing global variable cfg_type */
    {
         cfg_type  = 0u;
    }
    {
        /* Tested function call */
        MCfg_SWDbgDecode();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
        //CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
        //CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_type", ( cfg_type ));
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MCfg_SWDbgDecode */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_CfgGotoBoardMainPage */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_CfgGotoBoardMainPage(void) */
void TestSuit_drvMmsCfg_test_MDrv_CfgGotoBoardMainPage()
{
#if(ENABLE_MMS)
    /* Pre-condition initialization */
    /* Initializing global variable cfg_level */
    {
         cfg_level  = 0u;
    }
    {
        /* Tested function call */
        MDrv_CfgGotoBoardMainPage();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MDrv_CfgGotoBoardMainPage */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_CfgGotoBoardMainPagePrint */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_CfgGotoBoardMainPagePrint(void) */
void TestSuit_drvMmsCfg_test_MDrv_CfgGotoBoardMainPagePrint()
{
#if(ENABLE_MMS)
    /* Pre-condition initialization */
    {
        /* Tested function call */
        MDrv_CfgGotoBoardMainPagePrint();
        /* Post-condition check */
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MDrv_CfgGotoBoardMainPagePrint */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_CfgGotoCfgMainPage */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_CfgGotoCfgMainPage(void) */
void TestSuit_drvMmsCfg_test_MDrv_CfgGotoCfgMainPage()
{
#if(ENABLE_MMS)
    /* Pre-condition initialization */
    /* Initializing global variable CfgMenuLevel */
    {
         CfgMenuLevel  = 0;
    }
    /* Initializing global variable cfg_level */
    {
         cfg_level  = 0u;
    }
    /* Initializing global variable cfg_type */
    {
         cfg_type  = 0u;
    }
    {
        /* Tested function call */
        MDrv_CfgGotoCfgMainPage();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_INTEGER(" CfgMenuLevel", ( CfgMenuLevel ));
        //CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
        //CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_type", ( cfg_type ));
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MDrv_CfgGotoCfgMainPage */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_CfgGotoChipMainPagePrint */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_CfgGotoChipMainPagePrint(void) */
void TestSuit_drvMmsCfg_test_MDrv_CfgGotoChipMainPagePrint()
{
#if(ENABLE_MMS)
    /* Pre-condition initialization */
    {
        /* Tested function call */
        MDrv_CfgGotoChipMainPagePrint();
        /* Post-condition check */
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MDrv_CfgGotoChipMainPagePrint */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_CfgGotoPrePage */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_CfgGotoPrePage(void) */
void TestSuit_drvMmsCfg_test_MDrv_CfgGotoPrePage()
{
#if(ENABLE_MMS)
    /* Pre-condition initialization */
    /* Initializing global variable cfg_level */
    {
         cfg_level  = 0u;
    }
    {
        /* Tested function call */
        MDrv_CfgGotoPrePage();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
    }


    /* Pre-condition initialization */
    /* Initializing global variable cfg_level */
    {
         cfg_level  = 2;
    }
    {
        /* Tested function call */
        MDrv_CfgGotoPrePage();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MDrv_CfgGotoPrePage */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_CfgGotoPrePagePrint */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_CfgGotoPrePagePrint(void) */
void TestSuit_drvMmsCfg_test_MDrv_CfgGotoPrePagePrint()
{
#if(ENABLE_MMS)
    /* Pre-condition initialization */
    {
        /* Tested function call */
        MDrv_CfgGotoPrePagePrint();
        /* Post-condition check */
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MDrv_CfgGotoPrePagePrint */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_CfgGotoSWMainPage */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_CfgGotoSWMainPage(void) */
void TestSuit_drvMmsCfg_test_MDrv_CfgGotoSWMainPage()
{
#if(ENABLE_MMS)
    /* Pre-condition initialization */
    /* Initializing global variable cfg_level */
    {
         cfg_level  = 0u;
    }
    {
        /* Tested function call */
        MDrv_CfgGotoSWMainPage();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MDrv_CfgGotoSWMainPage */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_CfgGotoSWMainPagePrint */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_CfgGotoSWMainPagePrint(void) */
void TestSuit_drvMmsCfg_test_MDrv_CfgGotoSWMainPagePrint()
{
#if(ENABLE_MMS)
    /* Pre-condition initialization */
    {
        /* Tested function call */
        MDrv_CfgGotoSWMainPagePrint();
        /* Post-condition check */
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MDrv_CfgGotoSWMainPagePrint */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_CfgMainPagePrint */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_CfgMainPagePrint(void) */
void TestSuit_drvMmsCfg_test_MDrv_CfgMainPagePrint()
{
#if(ENABLE_MMS)
    /* Pre-condition initialization */
    {
        /* Tested function call */
        MDrv_CfgMainPagePrint();
        /* Post-condition check */
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MDrv_CfgMainPagePrint */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_Cfg_ChipMenuPrint */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_Cfg_ChipMenuPrint(void) */
void TestSuit_drvMmsCfg_test_MDrv_Cfg_ChipMenuPrint()
{
#if(ENABLE_MMS)
    /* Pre-condition initialization */
    /* Initializing global variable cfg_level */
    {
         cfg_level  = 0u;
    }
    {
        /* Tested function call */
        MDrv_Cfg_ChipMenuPrint();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
    }


    /* Pre-condition initialization */
    /* Initializing global variable cfg_level */
    {
         cfg_level  = 1;
    }
    {
        /* Tested function call */
        MDrv_Cfg_ChipMenuPrint();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
    }


    /* Pre-condition initialization */
    /* Initializing global variable cfg_level */
    {
         cfg_level  = 3;
    }
    {
        /* Tested function call */
        MDrv_Cfg_ChipMenuPrint();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
    }


    /* Pre-condition initialization */
    /* Initializing global variable cfg_level */
    {
         cfg_level  = 10;
    }
    {
        /* Tested function call */
        MDrv_Cfg_ChipMenuPrint();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
    }


    /* Pre-condition initialization */
    /* Initializing global variable cfg_level */
    {
         cfg_level  = 20;
    }
    {
        /* Tested function call */
        MDrv_Cfg_ChipMenuPrint();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
    }


    /* Pre-condition initialization */
    /* Initializing global variable cfg_level */
    {
         cfg_level  = 100;
    }
    {
        /* Tested function call */
        MDrv_Cfg_ChipMenuPrint();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
    }

    /* Pre-condition initialization */
    /* Initializing global variable cfg_level */
    {
         cfg_level  = 200;
    }
    {
        /* Tested function call */
        MDrv_Cfg_ChipMenuPrint();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MDrv_Cfg_ChipMenuPrint */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_Cfg_SWMenuPrint */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_Cfg_SWMenuPrint(void) */
void TestSuit_drvMmsCfg_test_MDrv_Cfg_SWMenuPrint()
{
#if(ENABLE_MMS)
    /* Pre-condition initialization */
    /* Initializing global variable cfg_level */
    {
         cfg_level  = 0u;
    }
    {
        /* Tested function call */
        MDrv_Cfg_SWMenuPrint();
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
    }


    /* Pre-condition initialization */
    /* Initializing global variable cfg_level */
    {
         cfg_level  = 3;
    }
    {
        /* Tested function call */
        MDrv_Cfg_SWMenuPrint();
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
    }


    /* Pre-condition initialization */
    /* Initializing global variable cfg_level */
    {
         cfg_level  = 10;
    }
    {
        /* Tested function call */
        MDrv_Cfg_SWMenuPrint();
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
    }


    /* Pre-condition initialization */
    /* Initializing global variable cfg_level */
    {
         cfg_level  = 100;
    }
    {
        /* Tested function call */
        MDrv_Cfg_SWMenuPrint();
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
    }


    /* Pre-condition initialization */
    /* Initializing global variable cfg_level */
    {
         cfg_level  = 200;
    }
    {
        /* Tested function call */
        MDrv_Cfg_SWMenuPrint();
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
    }

    /* Pre-condition initialization */
    /* Initializing global variable cfg_level */
    {
         cfg_level  = 255;
    }
    {
        /* Tested function call */
        MDrv_Cfg_SWMenuPrint();
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
    }

    /* Pre-condition initialization */
    /* Initializing global variable cfg_level */
    {
         cfg_level  = 50;
    }
    {
        /* Tested function call */
        MDrv_Cfg_SWMenuPrint();
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U16 cfg_level", ( cfg_level ));
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MDrv_Cfg_SWMenuPrint */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_Cfg_SetType */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_Cfg_SetType(CFG_TYPE_T) */
void TestSuit_drvMmsCfg_test_MDrv_Cfg_SetType()
{
#if(ENABLE_MMS)
    /* Pre-condition initialization */
    /* Initializing argument 1 (type) */
    CFG_TYPE_T _type  = BOARD;
    /* Initializing global variable cfg_type */
    {
         cfg_type  = 0u;
    }
    {
        /* Tested function call */
        MDrv_Cfg_SetType(_type);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(BOARD, ( cfg_type ));
    }


    /* Pre-condition initialization */
    /* Initializing argument 1 (type) */
     _type  = CHIP;
    /* Initializing global variable cfg_type */
    {
         cfg_type  = 0u;
    }
    {
        /* Tested function call */
        MDrv_Cfg_SetType(_type);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(CHIP, ( cfg_type ));
    }


    /* Pre-condition initialization */
    /* Initializing argument 1 (type) */
     _type  = SW;
    /* Initializing global variable cfg_type */
    {
         cfg_type  = 0u;
    }
    {
        /* Tested function call */
        MDrv_Cfg_SetType(_type);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(SW, ( cfg_type ));
    }
#endif
}

/* CPPTEST_TEST_CASE_END test_MDrv_Cfg_SetType */
