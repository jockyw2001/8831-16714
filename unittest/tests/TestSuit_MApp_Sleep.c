#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app/MApp_Sleep.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app/MApp_Sleep.c");

CPPTEST_TEST_SUITE(TestSuit_MApp_Sleep);
CPPTEST_TEST(TestSuit_MApp_Sleep_test_MApp_Sleep_SetAutoOn_OffTime_IF_TRUE);
CPPTEST_TEST(TestSuit_MApp_Sleep_test_MApp_Sleep_SetAutoOn_OffTime_IF_FALSE);
CPPTEST_TEST(TestSuit_MApp_Sleep_test_MApp_GetAutoSleep_Time_SwitchCase_test_STATE_AUTOSLEEP_4HR);
CPPTEST_TEST(TestSuit_MApp_Sleep_test_MApp_GetAutoSleep_Time_SwitchCase_test_STATE_AUTOSLEEP_6HR);
CPPTEST_TEST(TestSuit_MApp_Sleep_test_MApp_GetAutoSleep_Time_SwitchCase_test_STATE_AUTOSLEEP_8HR);
CPPTEST_TEST(TestSuit_MApp_Sleep_test_MApp_GetAutoSleep_Time_SwitchCase_test_STATE_AUTOSLEEP_NEVER);
CPPTEST_TEST_SUITE_END();
        

void TestSuit_MApp_Sleep_test_MApp_Sleep_SetAutoOn_OffTime_IF_TRUE();
void TestSuit_MApp_Sleep_test_MApp_Sleep_SetAutoOn_OffTime_IF_FALSE();
void TestSuit_MApp_Sleep_test_MApp_GetAutoSleep_Time_SwitchCase_test_STATE_AUTOSLEEP_4HR();
void TestSuit_MApp_Sleep_test_MApp_GetAutoSleep_Time_SwitchCase_test_STATE_AUTOSLEEP_6HR();
void TestSuit_MApp_Sleep_test_MApp_GetAutoSleep_Time_SwitchCase_test_STATE_AUTOSLEEP_8HR();
void TestSuit_MApp_Sleep_test_MApp_GetAutoSleep_Time_SwitchCase_test_STATE_AUTOSLEEP_NEVER();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuit_MApp_Sleep);

void TestSuit_MApp_Sleep_setUp()
{
}

void TestSuit_MApp_Sleep_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_Sleep_SetAutoOn_OffTime_IF_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Sleep_SetAutoOn_OffTime(BOOLEAN) */
void TestSuit_MApp_Sleep_test_MApp_Sleep_SetAutoOn_OffTime_IF_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bEnable) */ 
    U8 _bEnable  = TRUE;
    /* Initializing global variable benableAutoOn_OffTimer */ 
    {
         benableAutoOn_OffTimer  = FALSE;
    }
    /* Initializing global variable u32AutoOnTime */ 
    {
         u32AutoOnTime  = 0ul;
    }
    {
        /* Tested function call */
        MApp_Sleep_SetAutoOn_OffTime(_bEnable);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(TRUE,(benableAutoOn_OffTimer));
        CPPTEST_ASSERT_UINTEGER_EQUAL(50,(u32AutoOnTime));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Sleep_SetAutoOn_OffTime_IF_TRUE */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_Sleep_SetAutoOn_OffTime_IF_FALSE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Sleep_SetAutoOn_OffTime(BOOLEAN) */
void TestSuit_MApp_Sleep_test_MApp_Sleep_SetAutoOn_OffTime_IF_FALSE()
{
	/* Pre-condition initialization */
	/* Initializing argument 1 (bEnable) */
	U8 _bEnable  = FALSE;
	/* Initializing global variable benableAutoOn_OffTimer */
	{
		 benableAutoOn_OffTimer  = TRUE;
	}
	/* Initializing global variable u32AutoOnTime */
	{
		 u32AutoOnTime  = 0ul;
	}
	{
		/* Tested function call */
		MApp_Sleep_SetAutoOn_OffTime(_bEnable);
		/* Post-condition check */
		CPPTEST_ASSERT_UINTEGER_EQUAL(FALSE,(benableAutoOn_OffTimer));

	}
}
/* CPPTEST_TEST_CASE_END test_MApp_Sleep_SetAutoOn_OffTime_IF_FALSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetAutoSleep_Time_SwitchCase_test_STATE_AUTOSLEEP_4HR */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_GetAutoSleep_Time(void) */
void TestSuit_MApp_Sleep_test_MApp_GetAutoSleep_Time_SwitchCase_test_STATE_AUTOSLEEP_4HR()
{
    /* Pre-condition initialization */
    /* Initializing global variable enAutoSleepTimeState */ 
    {
        /* Tested function call */
        U32 _return  = MApp_GetAutoSleep_Time();
        /* Post-condition check */
        CPPTEST_ASSERT_DOUBLES_EQUAL( (60000*60*4) , (_return), 0) ;
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_GetAutoSleep_Time_SwitchCase_test_STATE_AUTOSLEEP_4HR */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetAutoSleep_Time_SwitchCase_test_STATE_AUTOSLEEP_6HR */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_GetAutoSleep_Time(void) */
void TestSuit_MApp_Sleep_test_MApp_GetAutoSleep_Time_SwitchCase_test_STATE_AUTOSLEEP_6HR()
{
    /* Pre-condition initialization */
    /* Initializing global variable enAutoSleepTimeState */ 
	{
	    /* Tested function call */
	    U32 _return  = MApp_GetAutoSleep_Time();
	    /* Post-condition check */
	    CPPTEST_ASSERT_DOUBLES_EQUAL( (60000*60*6) , (_return), 0) ;
	}
}
/* CPPTEST_TEST_CASE_END test_MApp_GetAutoSleep_Time_SwitchCase_test_STATE_AUTOSLEEP_6HR */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetAutoSleep_Time_SwitchCase_test_STATE_AUTOSLEEP_8HR */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_GetAutoSleep_Time(void) */
void TestSuit_MApp_Sleep_test_MApp_GetAutoSleep_Time_SwitchCase_test_STATE_AUTOSLEEP_8HR()
{
    /* Pre-condition initialization */
    /* Initializing global variable enAutoSleepTimeState */ 
	{
	    /* Tested function call */
	    U32 _return  = MApp_GetAutoSleep_Time();
	    /* Post-condition check */
	    CPPTEST_ASSERT_DOUBLES_EQUAL( (60000*60*8) , (_return), 0) ;
	}
}
/* CPPTEST_TEST_CASE_END test_MApp_GetAutoSleep_Time_SwitchCase_test_STATE_AUTOSLEEP_8HR */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetAutoSleep_Time_SwitchCase_test_STATE_AUTOSLEEP_NEVER */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_GetAutoSleep_Time(void) */
void TestSuit_MApp_Sleep_test_MApp_GetAutoSleep_Time_SwitchCase_test_STATE_AUTOSLEEP_NEVER()
{
    /* Pre-condition initialization */
    /* Initializing global variable enAutoSleepTimeState */ 
    {
        /* Tested function call */
        U32 _return  = MApp_GetAutoSleep_Time();
        /* Post-condition check */
        CPPTEST_ASSERT_DOUBLES_EQUAL( 0xFFFF , (_return), 0) ;
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_GetAutoSleep_Time_SwitchCase_test_STATE_AUTOSLEEP_NEVER */
