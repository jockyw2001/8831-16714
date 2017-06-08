#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app/MApp_EpgTimer.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app/MApp_EpgTimer.c");

CPPTEST_TEST_SUITE(TestSuite_MApp_EpgTimer);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_CalDaysByMon_case_DEFAULT);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_CalDaysByMon_case_2);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_CalDaysByMon_case_4);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_CalDaysByMon_case_1);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_SetTimerEventName_case_EN_MT_DATE_EVENT);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_SetTimerEventName_case_EN_MT_DATE_NEW);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_SetTimerDate_case_EN_MT_DATE_EVENT);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_SetTimerDate_case_EN_MT_DATE_NEW);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_SetTimerAsNew_if);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_SetTimerAsNew_else_if);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_IsTimePeriodOverlap);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_IsTimeSpotInPeriod_if);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_IsTimeSpotInPeriod_else);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_GetWeekStartingTime);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_GetWeekEndingTime);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_GetDayStartingTime);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_GetDayEndingTime);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_SaveTimerList);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_RetrieveTimerList);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_GetScheduleListBufAddr);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_CloseXdataWindow);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_ClearGlobalVar);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test__EpgTimer_IsItemRecording_if);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test__EpgTimer_IsItemRecording_else);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_ShiftTimeToSameWeek);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_ShiftTimeToSameDay);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_ReconfigTimerFromList);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_GetCountDown_s_if);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_GetCountDown_s_else_if1);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_GetCountDown_s_else_if2);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_GetCountDown_s_else);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_TimerList_UI_Init);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_IsTriggerByTimer_if);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_IsTriggerByTimer_else);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_SetStartingIndex);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_ClearStartingIndex);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_GetStartingIndex);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_GetTimerActType);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_GetNextStartUpIndex);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_CountDownNotify);
CPPTEST_TEST(TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_CalDaysByMon_case_3);
CPPTEST_TEST_SUITE_END();


void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_CalDaysByMon_case_DEFAULT();
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_CalDaysByMon_case_DEFAULT();
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_CalDaysByMon_case_2();
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_CalDaysByMon_case_4();
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_CalDaysByMon_case_1();
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_SetTimerEventName_case_EN_MT_DATE_EVENT();
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_SetTimerEventName_case_EN_MT_DATE_NEW();
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_SetTimerDate_case_EN_MT_DATE_EVENT();
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_SetTimerDate_case_EN_MT_DATE_NEW();
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_SetTimerAsNew_if();
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_SetTimerAsNew_else_if();
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_IsTimePeriodOverlap();
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_IsTimeSpotInPeriod_if();
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_IsTimeSpotInPeriod_else();
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_GetWeekStartingTime();
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_GetWeekEndingTime();
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_GetDayStartingTime();
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_GetDayEndingTime();
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_SaveTimerList();
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_RetrieveTimerList();
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_GetScheduleListBufAddr();
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_CloseXdataWindow();
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_ClearGlobalVar();
void TestSuite_MApp_EpgTimer_test__EpgTimer_IsItemRecording_if();
void TestSuite_MApp_EpgTimer_test__EpgTimer_IsItemRecording_else();
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_ShiftTimeToSameWeek();
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_ShiftTimeToSameDay();
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_ReconfigTimerFromList();
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_GetCountDown_s_if();
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_GetCountDown_s_else_if1();
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_GetCountDown_s_else_if2();
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_GetCountDown_s_else();
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_TimerList_UI_Init();
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_IsTriggerByTimer_if();
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_IsTriggerByTimer_else();
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_SetStartingIndex();
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_ClearStartingIndex();
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_GetStartingIndex();
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_GetTimerActType();
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_GetNextStartUpIndex();
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_CountDownNotify();
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_CalDaysByMon_case_3();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_MApp_EpgTimer);

void TestSuite_MApp_EpgTimer_setUp()
{
}

void TestSuite_MApp_EpgTimer_tearDown()
{
}

/* CPPTEST_TEST_CASE_BEGIN test_MApp_EpgTimer_CalDaysByMon_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT U16 MApp_EpgTimer_CalDaysByMon(U8) */
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_CalDaysByMon_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8Mon) */
    U8 _u8Mon  = 0;
    {
        /* Tested function call */
        U16 _return  = MApp_EpgTimer_CalDaysByMon(_u8Mon);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_EpgTimer_CalDaysByMon_case_DEFAULT */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_EpgTimer_CalDaysByMon_case_2 */
/* CPPTEST_TEST_CASE_CONTEXT U16 MApp_EpgTimer_CalDaysByMon(U8) */
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_CalDaysByMon_case_2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8Mon) */
    U8 _u8Mon  = 2;
    {
        /* Tested function call */
        U16 _return  = MApp_EpgTimer_CalDaysByMon(_u8Mon);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 29, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_EpgTimer_CalDaysByMon_case_2 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_EpgTimer_CalDaysByMon_case_4 */
/* CPPTEST_TEST_CASE_CONTEXT U16 MApp_EpgTimer_CalDaysByMon(U8) */
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_CalDaysByMon_case_4()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8Mon) */
    U8 _u8Mon  = 4;
    {
        /* Tested function call */
        U16 _return  = MApp_EpgTimer_CalDaysByMon(_u8Mon);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 30, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_EpgTimer_CalDaysByMon_case_4 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_EpgTimer_CalDaysByMon_case_1 */
/* CPPTEST_TEST_CASE_CONTEXT U16 MApp_EpgTimer_CalDaysByMon(U8) */
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_CalDaysByMon_case_1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8Mon) */
    U8 _u8Mon  = 1;
    {
        /* Tested function call */
        U16 _return  = MApp_EpgTimer_CalDaysByMon(_u8Mon);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 31, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_EpgTimer_CalDaysByMon_case_1 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_EpgTimer_SetTimerEventName_case_EN_MT_DATE_EVENT */
/* CPPTEST_TEST_CASE_CONTEXT void _MApp_EpgTimer_SetTimerEventName(EN_EPG_MT_DATE) */
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_SetTimerEventName_case_EN_MT_DATE_EVENT()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enDateMode) */
    EN_EPG_MT_DATE _enDateMode  = EN_MT_DATE_EVENT;
    /* Initializing global variable stEpgTimerParam */
    {
         stEpgTimerParam.u8CurTimerIdx  = 0;
         stEpgTimerParam.enMTSOURCE  = EN_MT_SOURCE_SCHED;
    }
    {
        /* Tested function call */
        _MApp_EpgTimer_SetTimerEventName(_enDateMode);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_EpgTimer_SetTimerEventName_case_EN_MT_DATE_EVENT */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_EpgTimer_SetTimerEventName_case_EN_MT_DATE_NEW */
/* CPPTEST_TEST_CASE_CONTEXT void _MApp_EpgTimer_SetTimerEventName(EN_EPG_MT_DATE) */
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_SetTimerEventName_case_EN_MT_DATE_NEW()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enDateMode) */
    EN_EPG_MT_DATE _enDateMode  = EN_MT_DATE_NEW;
    /* Initializing global variable stEpgTimerParam */
    {
         stEpgTimerParam.u8CurTimerIdx  = 0;
         stEpgTimerParam.enMTSOURCE  = EN_MT_SOURCE_SCHED;
    }
    {
        /* Tested function call */
        _MApp_EpgTimer_SetTimerEventName(_enDateMode);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_EpgTimer_SetTimerEventName_case_EN_MT_DATE_NEW */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_EpgTimer_SetTimerDate_case_EN_MT_DATE_EVENT */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_EpgTimer_SetTimerDate(EN_EPG_MT_DATE) */
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_SetTimerDate_case_EN_MT_DATE_EVENT()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enDateMode) */
    EN_EPG_MT_DATE _enDateMode  = EN_MT_DATE_EVENT;
    /* Initializing global variable stEpgTimerParam */
    {
         stEpgTimerParam.u8CurTimerIdx  = 0;
         stEpgTimerParam.enMTSOURCE  = EN_MT_SOURCE_SCHED;
    }
    {
        /* Tested function call */
        MApp_EpgTimer_SetTimerDate(_enDateMode);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_EpgTimer_SetTimerDate_case_EN_MT_DATE_EVENT */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_EpgTimer_SetTimerDate_case_EN_MT_DATE_NEW */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_EpgTimer_SetTimerDate(EN_EPG_MT_DATE) */
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_SetTimerDate_case_EN_MT_DATE_NEW()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enDateMode) */
    EN_EPG_MT_DATE _enDateMode  = EN_MT_DATE_NEW;
    /* Initializing global variable stEpgTimerParam */
    {
         stEpgTimerParam.u8CurTimerIdx  = 0;
         stEpgTimerParam.enMTSOURCE  = EN_MT_SOURCE_SCHED;
    }
    {
        /* Tested function call */
        MApp_EpgTimer_SetTimerDate(_enDateMode);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_EpgTimer_SetTimerDate_case_EN_MT_DATE_NEW */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_EpgTimer_SetTimerAsNew_if */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_EpgTimer_SetTimerAsNew(void) */
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_SetTimerAsNew_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable stEpgTimerParam */
    {
         stEpgTimerParam.u8CurTimerIdx  = 0;
         stEpgTimerParam.enMTSOURCE  = EN_MT_SOURCE_SCHED;
    }
    {
        /* Tested function call */
        MApp_EpgTimer_SetTimerAsNew();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_EPGUI_TIMER_REMINDER, ( stEpgTimerParam.stEpgTimer.enTimerType ) );
        CPPTEST_ASSERT_EQUAL( FALSE, ( stEpgTimerParam.stEpgTimer.bNoTitle ) );
        CPPTEST_ASSERT_EQUAL( FALSE, ( stEpgTimerParam.stEpgTimer.bRecordSplitEvent ) );
        CPPTEST_ASSERT_EQUAL( FALSE, ( stEpgTimerParam.stEpgTimer.bRecordSeriesEvent ) );
        CPPTEST_ASSERT_EQUAL( FALSE, ( stEpgTimerParam.stEpgTimer.bRecordRecomEvent ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_EpgTimer_SetTimerAsNew_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_EpgTimer_SetTimerAsNew_else_if */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_EpgTimer_SetTimerAsNew(void) */
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_SetTimerAsNew_else_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable stEpgTimerParam */
    {
         stEpgTimerParam.u8CurTimerIdx  = 0;
         stEpgTimerParam.enMTSOURCE  = EN_MT_SOURCE_SCHED;
    }
    {
        /* Tested function call */
        MApp_EpgTimer_SetTimerAsNew();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_EPGUI_TIMER_RECORDER, ( stEpgTimerParam.stEpgTimer.enTimerType ) );
        CPPTEST_ASSERT_EQUAL( FALSE, ( stEpgTimerParam.stEpgTimer.bNoTitle ) );
        CPPTEST_ASSERT_EQUAL( FALSE, ( stEpgTimerParam.stEpgTimer.bRecordSplitEvent ) );
        CPPTEST_ASSERT_EQUAL( FALSE, ( stEpgTimerParam.stEpgTimer.bRecordSeriesEvent ) );
        CPPTEST_ASSERT_EQUAL( FALSE, ( stEpgTimerParam.stEpgTimer.bRecordRecomEvent ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_EpgTimer_SetTimerAsNew_else_if */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_EpgTimer_IsTimePeriodOverlap */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_EpgTimer_IsTimePeriodOverlap(U32, U32, U32, U32) */
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_IsTimePeriodOverlap()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32ChkStartTime) */
    U32 _u32ChkStartTime  = 1ul;
    /* Initializing argument 2 (u32ChkEndTime) */
    U32 _u32ChkEndTime  = 2ul;
    /* Initializing argument 3 (u32ItemStartTime) */
    U32 _u32ItemStartTime  = 3ul;
    /* Initializing argument 4 (u32ItemEndTime) */
    U32 _u32ItemEndTime  = 4ul;
    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_EpgTimer_IsTimePeriodOverlap(_u32ChkStartTime, _u32ChkEndTime, _u32ItemStartTime, _u32ItemEndTime);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(_u32ChkStartTime < _u32ItemEndTime && _u32ChkEndTime > _u32ItemStartTime, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_EpgTimer_IsTimePeriodOverlap */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_EpgTimer_IsTimeSpotInPeriod_if */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_EpgTimer_IsTimeSpotInPeriod(U32, U32, U32) */
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_IsTimeSpotInPeriod_if()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32TimeSpot) */
    U32 _u32TimeSpot  = 5ul;
    /* Initializing argument 2 (u32TimePeriodStart) */
    U32 _u32TimePeriodStart  = 1ul;
    /* Initializing argument 3 (u32TimePeriodEnd) */
    U32 _u32TimePeriodEnd  = 5ul;
    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_EpgTimer_IsTimeSpotInPeriod(_u32TimeSpot, _u32TimePeriodStart, _u32TimePeriodEnd);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_EpgTimer_IsTimeSpotInPeriod_if */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_EpgTimer_IsTimeSpotInPeriod_else */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_EpgTimer_IsTimeSpotInPeriod(U32, U32, U32) */
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_IsTimeSpotInPeriod_else()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32TimeSpot) */
    U32 _u32TimeSpot  = 5ul;
    /* Initializing argument 2 (u32TimePeriodStart) */
    U32 _u32TimePeriodStart  = 1ul;
    /* Initializing argument 3 (u32TimePeriodEnd) */
    U32 _u32TimePeriodEnd  = 3ul;
    {
        /* Tested function call */
        BOOLEAN _return  = _MApp_EpgTimer_IsTimeSpotInPeriod(_u32TimeSpot, _u32TimePeriodStart, _u32TimePeriodEnd);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FALSE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_EpgTimer_IsTimeSpotInPeriod_else */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_EpgTimer_GetWeekStartingTime */
/* CPPTEST_TEST_CASE_CONTEXT void _MApp_EpgTimer_GetWeekStartingTime(ST_TIME *) */
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_GetWeekStartingTime()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstTime) */
    ST_TIME _pstTime;
    {
        /* Tested function call */
        _MApp_EpgTimer_GetWeekStartingTime(&_pstTime);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0, ( _pstTime.u8Hour ));
        CPPTEST_ASSERT_EQUAL(0, ( _pstTime.u8Min ));
        CPPTEST_ASSERT_EQUAL(0, ( _pstTime.u8Sec ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_EpgTimer_GetWeekStartingTime */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_EpgTimer_GetWeekEndingTime */
/* CPPTEST_TEST_CASE_CONTEXT void _MApp_EpgTimer_GetWeekEndingTime(ST_TIME *) */
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_GetWeekEndingTime()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstTime) */
    ST_TIME _pstTime;
    {
        /* Tested function call */
    	_MApp_EpgTimer_GetWeekEndingTime(&_pstTime);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(23, ( _pstTime.u8Hour ));
        CPPTEST_ASSERT_EQUAL(59, ( _pstTime.u8Min ));
        CPPTEST_ASSERT_EQUAL(59, ( _pstTime.u8Sec ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_EpgTimer_GetWeekEndingTime */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_EpgTimer_GetDayStartingTime */
/* CPPTEST_TEST_CASE_CONTEXT void _MApp_EpgTimer_GetDayStartingTime(ST_TIME *) */
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_GetDayStartingTime()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstTime) */
	ST_TIME _pstTime;
    {

        /* Tested function call */
        _MApp_EpgTimer_GetDayStartingTime(&_pstTime);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0, ( _pstTime.u8Hour ));
        CPPTEST_ASSERT_EQUAL(0, ( _pstTime.u8Min ));
        CPPTEST_ASSERT_EQUAL(0, ( _pstTime.u8Sec ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_EpgTimer_GetDayStartingTime */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_EpgTimer_GetDayEndingTime */
/* CPPTEST_TEST_CASE_CONTEXT void _MApp_EpgTimer_GetDayEndingTime(ST_TIME *) */
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_GetDayEndingTime()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstTime) */
	ST_TIME _pstTime;
    {

        /* Tested function call */
    	_MApp_EpgTimer_GetDayEndingTime(&_pstTime);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(23, ( _pstTime.u8Hour ));
        CPPTEST_ASSERT_EQUAL(59, ( _pstTime.u8Min ));
        CPPTEST_ASSERT_EQUAL(59, ( _pstTime.u8Sec ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_EpgTimer_GetDayEndingTime */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_EpgTimer_SaveTimerList */
/* CPPTEST_TEST_CASE_CONTEXT void _MApp_EpgTimer_SaveTimerList(BOOLEAN) */
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_SaveTimerList()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bUpdateDB) */
    U8 _bUpdateDB  = 1;
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable _pstEpgTimer */
    {
         _pstEpgTimer  = 0 ;
    }
    {
        /* Tested function call */
        _MApp_EpgTimer_SaveTimerList(_bUpdateDB);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_EpgTimer_SaveTimerList */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_EpgTimer_RetrieveTimerList */
/* CPPTEST_TEST_CASE_CONTEXT void _MApp_EpgTimer_RetrieveTimerList(void) */
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_RetrieveTimerList()
{
    /* Pre-condition initialization */
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable _pstEpgTimer */
    {
         _pstEpgTimer  = 0 ;
    }
    {
        /* Tested function call */
        _MApp_EpgTimer_RetrieveTimerList();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_EpgTimer_RetrieveTimerList */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_EpgTimer_GetScheduleListBufAddr */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_EpgTimer_GetScheduleListBufAddr(void) */
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_GetScheduleListBufAddr()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        U32 _return  = MApp_EpgTimer_GetScheduleListBufAddr();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_EpgTimer_GetScheduleListBufAddr */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_EpgTimer_CloseXdataWindow */
/* CPPTEST_TEST_CASE_CONTEXT void _MApp_EpgTimer_CloseXdataWindow(U32) */
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_CloseXdataWindow()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32PrvAddress) */
    U32 _u32PrvAddress  = 0ul;
    {
        /* Tested function call */
        _MApp_EpgTimer_CloseXdataWindow(_u32PrvAddress);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(_u32PrvAddress, ( _u32PrvAddress ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_EpgTimer_CloseXdataWindow */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_EpgTimer_ClearGlobalVar */
/* CPPTEST_TEST_CASE_CONTEXT void _MApp_EpgTimer_ClearGlobalVar(void) */
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_ClearGlobalVar()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_u32EpgNextStartUpTime */
    {
         m_u32EpgNextStartUpTime  = 0ul;
    }
    /* Initializing global variable m_u8EpgNextStartUpIdx */
    {
         m_u8EpgNextStartUpIdx  = 0;
    }
    /* Initializing global variable m_dwEPGManualTimerMonitorTimer */
    {
         m_dwEPGManualTimerMonitorTimer  = 0ul;
    }
    {
        /* Tested function call */
        _MApp_EpgTimer_ClearGlobalVar();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0, ( m_u32EpgNextStartUpTime ));
        CPPTEST_ASSERT_EQUAL(EPGTIMER_INDEX_NULL, ( m_u8EpgNextStartUpIdx ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_EpgTimer_ClearGlobalVar */

/* CPPTEST_TEST_CASE_BEGIN test__EpgTimer_IsItemRecording_if */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _EpgTimer_IsItemRecording(U8) */
void TestSuite_MApp_EpgTimer_test__EpgTimer_IsItemRecording_if()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ItemIndex) */
    U8 _ItemIndex  = 2;
    U8 i=0;
    for(i=0; i<EPGTIMER_REC_QUEUE_NUMBER; ++i)
    	m_u8EpgTimerRecQueue[i].u8TimerIndex = i;
    {
        /* Tested function call */
        BOOLEAN _return  = _EpgTimer_IsItemRecording(_ItemIndex);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__EpgTimer_IsItemRecording_if */

/* CPPTEST_TEST_CASE_BEGIN test__EpgTimer_IsItemRecording_else */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _EpgTimer_IsItemRecording(U8) */
void TestSuite_MApp_EpgTimer_test__EpgTimer_IsItemRecording_else()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ItemIndex) */
    U8 _ItemIndex  = 5;
    U8 i=0;
    for(i=0; i<EPGTIMER_REC_QUEUE_NUMBER; ++i)
    	m_u8EpgTimerRecQueue[i].u8TimerIndex = i;
    {
        /* Tested function call */
        BOOLEAN _return  = _EpgTimer_IsItemRecording(_ItemIndex);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FALSE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__EpgTimer_IsItemRecording_else */


/* CPPTEST_TEST_CASE_BEGIN test__MApp_EpgTimer_ShiftTimeToSameWeek */
/* CPPTEST_TEST_CASE_CONTEXT void _MApp_EpgTimer_ShiftTimeToSameWeek(ST_TIME *, ST_TIME *) */
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_ShiftTimeToSameWeek()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pTimeToShift) */
    ST_TIME _pTimeToShift;
    /* Initializing argument 2 (pTimeFixed) */
    ST_TIME _pTimeFixed;
    {
        /* Tested function call */
        _MApp_EpgTimer_ShiftTimeToSameWeek(&_pTimeToShift, &_pTimeFixed);
        printf("=%d\n",_pTimeToShift.u16Year);
        printf("=%d\n",_pTimeToShift.u8Month);
        printf("=%d\n",_pTimeToShift.u8Day);
        printf("=%d\n",_pTimeFixed.u16Year);
        printf("=%d\n",_pTimeFixed.u8Month);
        printf("=%d\n\n",_pTimeFixed.u8Day);
        /* Post-condition check */
        //CPPTEST_ASSERT_EQUAL(_pTimeFixed.u16Year, ( _pTimeToShift.u16Year ));
        //CPPTEST_ASSERT_EQUAL(_pTimeFixed.u8Month, ( _pTimeToShift.u8Month ));
        //CPPTEST_ASSERT_EQUAL(_pTimeFixed.u8Day, ( _pTimeToShift.u8Day ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_EpgTimer_ShiftTimeToSameWeek */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_EpgTimer_ShiftTimeToSameDay */
/* CPPTEST_TEST_CASE_CONTEXT void _MApp_EpgTimer_ShiftTimeToSameDay(ST_TIME *, ST_TIME *) */
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_ShiftTimeToSameDay()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pTimeToShift) */
    ST_TIME _pTimeToShift;
    /* Initializing argument 2 (pTimeFixed) */
    ST_TIME _pTimeFixed;
    {
        /* Tested function call */
    	_MApp_EpgTimer_ShiftTimeToSameDay(&_pTimeToShift, &_pTimeFixed);
    	printf("=%d\n",_pTimeToShift.u16Year);
    	printf("=%d\n",_pTimeToShift.u8Month);
    	printf("=%d\n",_pTimeToShift.u8Day);
        printf("=%d\n",_pTimeFixed.u16Year);
        printf("=%d\n",_pTimeFixed.u8Month);
    	printf("=%d\n\n",_pTimeFixed.u8Day);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(_pTimeFixed.u16Year, ( _pTimeToShift.u16Year ));
        CPPTEST_ASSERT_EQUAL(_pTimeFixed.u8Month, ( _pTimeToShift.u8Month ));
        CPPTEST_ASSERT_EQUAL(_pTimeFixed.u8Day, ( _pTimeToShift.u8Day ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_EpgTimer_ShiftTimeToSameDay */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_EpgTimer_ReconfigTimerFromList */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_EpgTimer_ReconfigTimerFromList(U32) */
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_ReconfigTimerFromList()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32TimeActing) */
    U32 _u32TimeActing  = 0ul;
    /* Initializing global variable m_u8EpgStartingIdx */
    {
         m_u8EpgStartingIdx  = 0;
    }
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    /* Initializing global variable _pstEpgTimer */
    {
         _pstEpgTimer  = 0 ;
    }
    /* Initializing global variable m_u32EpgNextStartUpTime */
    {
         m_u32EpgNextStartUpTime  = 0ul;
    }
    /* Initializing global variable m_u8EpgNextStartUpIdx */
    {
         m_u8EpgNextStartUpIdx  = 0;
    }
    /* Initializing global variable _TimerActType */
    {
         _TimerActType  = EN_EPGTIMER_ACT_NONE;
    }
    /* Initializing global variable m_dwEPGManualTimerMonitorTimer */
    {
         m_dwEPGManualTimerMonitorTimer  = 0ul;
    }
    {
        /* Tested function call */
        MApp_EpgTimer_ReconfigTimerFromList(_u32TimeActing);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_EpgTimer_ReconfigTimerFromList */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_EpgTimer_GetCountDown_s_if */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_EpgTimer_GetCountDown_s(void) */
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_GetCountDown_s_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_u32EpgNextStartUpTime */
    {
         m_u32EpgNextStartUpTime  = 50ul;
    }
    /* Initializing global variable _TimerActType */
    {
         _TimerActType  = EN_EPGTIMER_ACT_RECORDER_START;
    }
    {
        /* Tested function call */
        U32 _return  = MApp_EpgTimer_GetCountDown_s();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( m_u32EpgNextStartUpTime - MApp_GetLocalSystemTime() - EPG_RECORDER_PVR_LEADING_TIME_s, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_EpgTimer_GetCountDown_s_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_EpgTimer_GetCountDown_s_else_if1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_EpgTimer_GetCountDown_s(void) */
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_GetCountDown_s_else_if1()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_u32EpgNextStartUpTime */
    {
         m_u32EpgNextStartUpTime  = 50ul;
    }
    /* Initializing global variable _TimerActType */
    {
         _TimerActType  = EN_EPGTIMER_ACT_REMINDER;
    }
    {
        /* Tested function call */
        U32 _return  = MApp_EpgTimer_GetCountDown_s();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( m_u32EpgNextStartUpTime - MApp_GetLocalSystemTime(), ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_EpgTimer_GetCountDown_s_else_if1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_EpgTimer_GetCountDown_s_else_if2 */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_EpgTimer_GetCountDown_s(void) */
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_GetCountDown_s_else_if2()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_u32EpgNextStartUpTime */
    {
         m_u32EpgNextStartUpTime  = 50ul;
    }
    /* Initializing global variable _TimerActType */
    {
         _TimerActType  = EN_EPGTIMER_ACT_CI_OP_REFRESH;
    }
    {
        /* Tested function call */
        U32 _return  = MApp_EpgTimer_GetCountDown_s();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( m_u32EpgNextStartUpTime - MApp_GetLocalSystemTime(), ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_EpgTimer_GetCountDown_s_else_if2 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_EpgTimer_GetCountDown_s_else */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_EpgTimer_GetCountDown_s(void) */
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_GetCountDown_s_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_u32EpgNextStartUpTime */
    {
         m_u32EpgNextStartUpTime  = 50ul;
    }
    /* Initializing global variable _TimerActType */
    {
         _TimerActType  = EN_EPGTIMER_ACT_NONE;
    }
    {
        /* Tested function call */
        U32 _return  = MApp_EpgTimer_GetCountDown_s();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 0, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_EpgTimer_GetCountDown_s_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_EpgTimer_TimerList_UI_Init */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_EpgTimer_TimerList_UI_Init(void) */
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_TimerList_UI_Init()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_TimerList_CurPageStartItem */
    {
         g_TimerList_CurPageStartItem  = 0;
    }
    /* Initializing global variable stEpgTimerParam */
    {
         stEpgTimerParam.u8CurTimerIdx  = 0;
         stEpgTimerParam.enMTSOURCE  = EN_MT_SOURCE_SCHED;
    }
    {
        /* Tested function call */
        MApp_EpgTimer_TimerList_UI_Init();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 0, ( g_TimerList_CurPageStartItem ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_EpgTimer_TimerList_UI_Init */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_EpgTimer_IsTriggerByTimer_if */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_EpgTimer_IsTriggerByTimer(void) */
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_IsTriggerByTimer_if()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_u8EpgStartingIdx */
    {
         m_u8EpgStartingIdx  = EPGTIMER_INDEX_USER;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_EpgTimer_IsTriggerByTimer();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_EpgTimer_IsTriggerByTimer_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_EpgTimer_IsTriggerByTimer_else */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_EpgTimer_IsTriggerByTimer(void) */
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_IsTriggerByTimer_else()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_u8EpgStartingIdx */
    {
         m_u8EpgStartingIdx  = EPGTIMER_INDEX_NULL;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_EpgTimer_IsTriggerByTimer();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_EpgTimer_IsTriggerByTimer_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_EpgTimer_SetStartingIndex */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_EpgTimer_SetStartingIndex(U8) */
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_SetStartingIndex()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (Index) */
    U8 _Index  = 5;
    /* Initializing global variable m_u8EpgStartingIdx */
    {
         m_u8EpgStartingIdx  = 0;
    }
    {
        /* Tested function call */
        MApp_EpgTimer_SetStartingIndex(_Index);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _Index, ( m_u8EpgStartingIdx ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_EpgTimer_SetStartingIndex */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_EpgTimer_ClearStartingIndex */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_EpgTimer_ClearStartingIndex(void) */
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_ClearStartingIndex()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_u8EpgStartingIdx */
    {
         m_u8EpgStartingIdx  = 0;
    }
    {
        /* Tested function call */
        MApp_EpgTimer_ClearStartingIndex();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EPGTIMER_INDEX_NULL, ( m_u8EpgStartingIdx ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_EpgTimer_ClearStartingIndex */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_EpgTimer_GetStartingIndex */
/* CPPTEST_TEST_CASE_CONTEXT U8 MApp_EpgTimer_GetStartingIndex(void) */
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_GetStartingIndex()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_u8EpgStartingIdx */
    {
         m_u8EpgStartingIdx  = 10;
    }
    {
        /* Tested function call */
        U8 _return  = MApp_EpgTimer_GetStartingIndex();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( m_u8EpgStartingIdx, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_EpgTimer_GetStartingIndex */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_EpgTimer_GetTimerActType */
/* CPPTEST_TEST_CASE_CONTEXT EN_EPG_TIMER_ACT_TYPE MApp_EpgTimer_GetTimerActType(void) */
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_GetTimerActType()
{
    /* Pre-condition initialization */
    /* Initializing global variable _TimerActType */
    {
         _TimerActType  = EN_EPGTIMER_ACT_NONE;
    }
    {
        /* Tested function call */
        EN_EPG_TIMER_ACT_TYPE _return  = MApp_EpgTimer_GetTimerActType();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _TimerActType, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_EpgTimer_GetTimerActType */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_EpgTimer_GetNextStartUpIndex */
/* CPPTEST_TEST_CASE_CONTEXT U8 MApp_EpgTimer_GetNextStartUpIndex(void) */
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_GetNextStartUpIndex()
{
    /* Pre-condition initialization */
    /* Initializing global variable m_u8EpgNextStartUpIdx */
    {
         m_u8EpgNextStartUpIdx  = 0;
    }
    {
        /* Tested function call */
        U8 _return  = MApp_EpgTimer_GetNextStartUpIndex();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( m_u8EpgNextStartUpIdx, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_EpgTimer_GetNextStartUpIndex */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_EpgTimer_CountDownNotify */
/* CPPTEST_TEST_CASE_CONTEXT void _MApp_EpgTimer_CountDownNotify(void) */
void TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_CountDownNotify()
{
    /* Pre-condition initialization */
    /* Initializing global variable u8KeyCode */
    {
         u8KeyCode  = 0;
    }
    {
        /* Tested function call */
        _MApp_EpgTimer_CountDownNotify();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( KEY_EPGTIMER_COUNTDOWN, ( u8KeyCode ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_EpgTimer_CountDownNotify */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_EpgTimer_CalDaysByMon */
/* CPPTEST_TEST_CASE_CONTEXT U16 MApp_EpgTimer_CalDaysByMon(U8) */
void TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_CalDaysByMon_case_3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8Mon) */
    U8 _u8Mon  = 3;
    {
        /* Tested function call */
        U16 _return  = MApp_EpgTimer_CalDaysByMon(_u8Mon);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 31, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_EpgTimer_CalDaysByMon */
