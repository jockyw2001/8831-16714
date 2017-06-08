#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/msAPI_Timer.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/msAPI_Timer.c");

CPPTEST_TEST_SUITE(TestSuite_msAPI_Timer);
CPPTEST_TEST(TestSuite_msAPI_Timer_test_msAPI_Timer_GetDownTimer0_Yes);
CPPTEST_TEST(TestSuite_msAPI_Timer_test_msAPI_Timer_GetDownTimer0_No);
CPPTEST_TEST(TestSuite_msAPI_Timer_test_msAPI_Timer_IsSystemTimeValid);
CPPTEST_TEST(TestSuite_msAPI_Timer_test_msAPI_Timer_SyncToPmRTC);
CPPTEST_TEST(TestSuite_msAPI_Timer_test_msAPI_Timer_DisableSystemTime);
CPPTEST_TEST(TestSuite_msAPI_Timer_test_msAPI_Timer_GetSystemTime);
CPPTEST_TEST(TestSuite_msAPI_Timer_test_msAPI_Timer_GetWakeupTime);
CPPTEST_TEST(TestSuite_msAPI_Timer_test_msAPI_Timer_GetOffsetTime);
CPPTEST_TEST(TestSuite_msAPI_Timer_test_msAPI_Timer_SetWakeupTime);
CPPTEST_TEST(TestSuite_msAPI_Timer_test_msAPI_Timer_DiffTime_Yes);
CPPTEST_TEST(TestSuite_msAPI_Timer_test_msAPI_Timer_DiffTime_No);
CPPTEST_TEST(TestSuite_msAPI_Timer_test_msAPI_Timer_DiffTimeFromNow);
CPPTEST_TEST(TestSuite_msAPI_Timer_test_msAPI_Timer_SetRTCWakeUpTime);
CPPTEST_TEST(TestSuite_msAPI_Timer_test_msAPI_Timer_GetRTCWakeUpTime);
CPPTEST_TEST(TestSuite_msAPI_Timer_test_msAPI_Timer_EnableRTCWakeUp);
CPPTEST_TEST(TestSuite_msAPI_Timer_test_msAPI_Timer_GetRTCSystemTime);
CPPTEST_TEST(TestSuite_msAPI_Timer_test_msAPI_Timer_SetSystemTime);
CPPTEST_TEST(TestSuite_msAPI_Timer_test_msAPI_Timer_SetTimeOfChange);
CPPTEST_TEST(TestSuite_msAPI_Timer_test_msAPI_Timer_SetNextTimeOffset);
CPPTEST_TEST(TestSuite_msAPI_Timer_test_msAPI_Timer_Load_OffsetTime);
CPPTEST_TEST(TestSuite_msAPI_Timer_test_msAPI_Timer_GetTime0);
CPPTEST_TEST(TestSuite_msAPI_Timer_test_msAPI_Timer_SetOffsetTime);
CPPTEST_TEST(TestSuite_msAPI_Timer_test_msAPI_Timer_SetDownTimer0);
CPPTEST_TEST_SUITE_END();


void TestSuite_msAPI_Timer_test_msAPI_Timer_GetDownTimer0_Yes();
void TestSuite_msAPI_Timer_test_msAPI_Timer_GetDownTimer0_No();
void TestSuite_msAPI_Timer_test_msAPI_Timer_IsSystemTimeValid();
void TestSuite_msAPI_Timer_test_msAPI_Timer_SyncToPmRTC();
void TestSuite_msAPI_Timer_test_msAPI_Timer_DisableSystemTime();
void TestSuite_msAPI_Timer_test_msAPI_Timer_GetSystemTime();
void TestSuite_msAPI_Timer_test_msAPI_Timer_GetWakeupTime();
void TestSuite_msAPI_Timer_test_msAPI_Timer_GetOffsetTime();
void TestSuite_msAPI_Timer_test_msAPI_Timer_SetWakeupTime();
void TestSuite_msAPI_Timer_test_msAPI_Timer_DiffTime_Yes();
void TestSuite_msAPI_Timer_test_msAPI_Timer_DiffTime_No();
void TestSuite_msAPI_Timer_test_msAPI_Timer_DiffTimeFromNow();
void TestSuite_msAPI_Timer_test_msAPI_Timer_SetRTCWakeUpTime();
void TestSuite_msAPI_Timer_test_msAPI_Timer_GetRTCWakeUpTime();
void TestSuite_msAPI_Timer_test_msAPI_Timer_EnableRTCWakeUp();
void TestSuite_msAPI_Timer_test_msAPI_Timer_GetRTCSystemTime();
void TestSuite_msAPI_Timer_test_msAPI_Timer_SetSystemTime();
void TestSuite_msAPI_Timer_test_msAPI_Timer_SetTimeOfChange();
void TestSuite_msAPI_Timer_test_msAPI_Timer_SetNextTimeOffset();
void TestSuite_msAPI_Timer_test_msAPI_Timer_Load_OffsetTime();
void TestSuite_msAPI_Timer_test_msAPI_Timer_GetTime0();
void TestSuite_msAPI_Timer_test_msAPI_Timer_SetOffsetTime();
void TestSuite_msAPI_Timer_test_msAPI_Timer_SetDownTimer0();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_msAPI_Timer);

void TestSuite_msAPI_Timer_setUp()
{
}

void TestSuite_msAPI_Timer_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Timer_GetDownTimer0 */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_Timer_GetDownTimer0(void) */
void TestSuite_msAPI_Timer_test_msAPI_Timer_GetDownTimer0_Yes()
{
    /* Pre-condition initialization */
    /* Initializing global variable _TimerTarget */
    {
         _TimerTarget  = 88ul;
    }
    {
        /* Tested function call */
        U32 _return  = msAPI_Timer_GetDownTimer0();
        CPPTEST_ASSERT_UINTEGER_EQUAL(0,(_return));
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
        //CPPTEST_POST_CONDITION_UINTEGER("MS_U32 _TimerTarget", ( _TimerTarget ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Timer_GetDownTimer0 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Timer_GetDownTimer0 */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_Timer_GetDownTimer0(void) */
void TestSuite_msAPI_Timer_test_msAPI_Timer_GetDownTimer0_No()
{
    /* Pre-condition initialization */
    /* Initializing global variable _TimerTarget */
    {
         _TimerTarget  = 88ul;
    }
    {
        /* Tested function call */
        U32 _return  = msAPI_Timer_GetDownTimer0();
        CPPTEST_ASSERT_UINTEGER_EQUAL(28,(_return));
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
        //CPPTEST_POST_CONDITION_UINTEGER("MS_U32 _TimerTarget", ( _TimerTarget ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Timer_GetDownTimer0 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Timer_IsSystemTimeValid */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_Timer_IsSystemTimeValid(void) */
void TestSuite_msAPI_Timer_test_msAPI_Timer_IsSystemTimeValid()
{
    /* Pre-condition initialization */
    /* Initializing global variable fSetSystemTime */
    {
         fSetSystemTime  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_Timer_IsSystemTimeValid();
        CPPTEST_ASSERT_BOOL_EQUAL(0,(_return));
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_UINTEGER("U8 fSetSystemTime", ( fSetSystemTime ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Timer_IsSystemTimeValid */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Timer_SyncToPmRTC */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_Timer_SyncToPmRTC(void) */
extern BOOL btest_msAPI_Timer_SyncToPmRTC;
void TestSuite_msAPI_Timer_test_msAPI_Timer_SyncToPmRTC()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        msAPI_Timer_SyncToPmRTC();
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE,(btest_msAPI_Timer_SyncToPmRTC));
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Timer_SyncToPmRTC */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Timer_DisableSystemTime */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_Timer_DisableSystemTime(void) */
void TestSuite_msAPI_Timer_test_msAPI_Timer_DisableSystemTime()
{
    /* Pre-condition initialization */
    /* Initializing global variable fSetSystemTime */
    {
         fSetSystemTime  = 0;
         gSystemTimeCount = 0;
    }
    {
        /* Tested function call */
        msAPI_Timer_DisableSystemTime();
        CPPTEST_ASSERT_UINTEGER_EQUAL(0,(fSetSystemTime));
        CPPTEST_ASSERT_UINTEGER_EQUAL(0,(gSystemTimeCount));
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 fSetSystemTime", ( fSetSystemTime ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Timer_DisableSystemTime */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Timer_GetSystemTime */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_Timer_GetSystemTime(void) */
void TestSuite_msAPI_Timer_test_msAPI_Timer_GetSystemTime()
{
    /* Pre-condition initialization */
    /* Initializing global variable gSystemTimeCount */
    {
           gSystemTimeCount = 0;
    }
    {
        /* Tested function call */
        U32 _return  = msAPI_Timer_GetSystemTime();
        CPPTEST_ASSERT_UINTEGER_EQUAL(0,(_return));
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Timer_GetSystemTime */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Timer_GetWakeupTime */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_Timer_GetWakeupTime(void) */
void TestSuite_msAPI_Timer_test_msAPI_Timer_GetWakeupTime()
{
    /* Pre-condition initialization */
    /* Initializing global variable gWakeupSystemTime */
    {
    	gWakeupSystemTime = 0;
    }
	{
        /* Tested function call */
        U32 _return  = msAPI_Timer_GetWakeupTime();
        CPPTEST_ASSERT_UINTEGER_EQUAL(0,(_return));
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Timer_GetWakeupTime */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Timer_GetOffsetTime */
/* CPPTEST_TEST_CASE_CONTEXT S32 msAPI_Timer_GetOffsetTime(void) */
void TestSuite_msAPI_Timer_test_msAPI_Timer_GetOffsetTime()
{
    /* Pre-condition initialization */
    /* Initializing global variable gU32TimeOfChange */
    {
           gSystemTimeCount = 2;
    }
    {
         gU32TimeOfChange  = 1ul;
    }
    /* Initializing global variable gS32NextTimeOffset */
    {
         gS32NextTimeOffset  = 5L;
    }
    {
        /* Tested function call */
        S32 _return  = msAPI_Timer_GetOffsetTime();
        CPPTEST_ASSERT_INTEGER_EQUAL(5,(_return));
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_INTEGER("S32 _return", ( _return ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 gU32TimeOfChange", ( gU32TimeOfChange ));
        //CPPTEST_POST_CONDITION_INTEGER("S32 gS32NextTimeOffset", ( gS32NextTimeOffset ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Timer_GetOffsetTime */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Timer_SetWakeupTime */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_Timer_SetWakeupTime(U32) */
void TestSuite_msAPI_Timer_test_msAPI_Timer_SetWakeupTime()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Time) */
    U32 _u32Time  = 0ul;
    {
        /* Tested function call */
        msAPI_Timer_SetWakeupTime(_u32Time);
        /* Post-condition check */
    }
    CPPTEST_ASSERT_UINTEGER_EQUAL(0,(gSystemTimeCount));
}
/* CPPTEST_TEST_CASE_END test_msAPI_Timer_SetWakeupTime */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Timer_DiffTime */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_Timer_DiffTime_Yes(U32, U32) */
void TestSuite_msAPI_Timer_test_msAPI_Timer_DiffTime_Yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Timer) */
    U32 _u32Timer  = 8ul;
    /* Initializing argument 2 (u32TaskTimer) */
    U32 _u32TaskTimer  = 18ul;
    {
        /* Tested function call */
        U32 _return  = msAPI_Timer_DiffTime(_u32Timer, _u32TaskTimer);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(10,(_return));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_Timer_DiffTime_No(U32, U32) */
void TestSuite_msAPI_Timer_test_msAPI_Timer_DiffTime_No()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Timer) */
    U32 _u32Timer  = 18ul;
    /* Initializing argument 2 (u32TaskTimer) */
    U32 _u32TaskTimer  = 8ul;
    {
        /* Tested function call */
        U32 _return  = msAPI_Timer_DiffTime(_u32Timer, _u32TaskTimer);
        CPPTEST_ASSERT_UINTEGER_EQUAL(10,(_return));
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Timer_DiffTime */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Timer_DiffTimeFromNow */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_Timer_DiffTimeFromNow(U32) */
void TestSuite_msAPI_Timer_test_msAPI_Timer_DiffTimeFromNow()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32TaskTimer) */
    U32 _u32TaskTimer  = 0ul;
    {
        /* Tested function call */
        U32 _return  = msAPI_Timer_DiffTimeFromNow(_u32TaskTimer);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(2013,(_return));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Timer_DiffTimeFromNow */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Timer_SetRTCWakeUpTime */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_Timer_SetRTCWakeUpTime(U32) */
extern BOOL btest_msAPI_Timer_SetRTCWakeUpTime;
void TestSuite_msAPI_Timer_test_msAPI_Timer_SetRTCWakeUpTime()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32SystemTime) */
    U32 _u32SystemTime  = 0ul;
    {
        /* Tested function call */
        msAPI_Timer_SetRTCWakeUpTime(_u32SystemTime);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE,(btest_msAPI_Timer_SetRTCWakeUpTime));
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Timer_SetRTCWakeUpTime */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Timer_GetRTCWakeUpTime */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_Timer_GetRTCWakeUpTime(void) */
void TestSuite_msAPI_Timer_test_msAPI_Timer_GetRTCWakeUpTime()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        U32 _return  = msAPI_Timer_GetRTCWakeUpTime();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(100,(_return));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Timer_GetRTCWakeUpTime */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Timer_EnableRTCWakeUp */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_Timer_EnableRTCWakeUp(BOOLEAN) */
extern BOOL btest_msAPI_Timer_EnableRTCWakeUp;
void TestSuite_msAPI_Timer_test_msAPI_Timer_EnableRTCWakeUp()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bEnable) */
    U8 _bEnable  = 0;
    {
        /* Tested function call */
        msAPI_Timer_EnableRTCWakeUp(_bEnable);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE,(btest_msAPI_Timer_EnableRTCWakeUp));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Timer_EnableRTCWakeUp */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Timer_GetRTCSystemTime */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_Timer_GetRTCSystemTime(void) */
void TestSuite_msAPI_Timer_test_msAPI_Timer_GetRTCSystemTime()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        U32 _return  = msAPI_Timer_GetRTCSystemTime();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(101,(_return));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Timer_GetRTCSystemTime */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Timer_SetSystemTime */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_Timer_SetSystemTime(U32) */
extern BOOL btest_msAPI_Timer_SetSystemTime;
void TestSuite_msAPI_Timer_test_msAPI_Timer_SetSystemTime()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32SystemTime) */
    U32 _u32SystemTime  = 0ul;
    {
        /* Tested function call */
        msAPI_Timer_SetSystemTime(_u32SystemTime);
        CPPTEST_ASSERT_UINTEGER_EQUAL(0,(gSystemTimeCount));
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE,(btest_msAPI_Timer_SetSystemTime));
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Timer_SetSystemTime */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Timer_SetTimeOfChange */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_Timer_SetTimeOfChange(U32) */
void TestSuite_msAPI_Timer_test_msAPI_Timer_SetTimeOfChange()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32TimeOfChg) */
    U32 _u32TimeOfChg  = 18ul;
    /* Initializing global variable gU32TimeOfChange */
    {
         gU32TimeOfChange  = 0ul;
    }
    {
        /* Tested function call */
        msAPI_Timer_SetTimeOfChange(_u32TimeOfChg);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(18,(gU32TimeOfChange));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 gU32TimeOfChange", ( gU32TimeOfChange ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Timer_SetTimeOfChange */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Timer_SetNextTimeOffset */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_Timer_SetNextTimeOffset(S32) */
void TestSuite_msAPI_Timer_test_msAPI_Timer_SetNextTimeOffset()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (s32OffsetTime) */
    S32 _s32OffsetTime  = 18L;
    /* Initializing global variable gS32NextTimeOffset */
    {
         gS32NextTimeOffset  = 0L;
    }
    {
        /* Tested function call */
        msAPI_Timer_SetNextTimeOffset(_s32OffsetTime);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(18,(gS32NextTimeOffset));
        //CPPTEST_POST_CONDITION_INTEGER("S32 gS32NextTimeOffset", ( gS32NextTimeOffset ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Timer_SetNextTimeOffset */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Timer_Load_OffsetTime */
/* CPPTEST_TEST_CASE_CONTEXT S32 msAPI_Timer_Load_OffsetTime(void) */
void TestSuite_msAPI_Timer_test_msAPI_Timer_Load_OffsetTime()
{
    /* Pre-condition initialization */
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.g_Time.s32Offset_Time = 18;
    }
    {
        /* Tested function call */
        S32 _return  = msAPI_Timer_Load_OffsetTime();
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(18,(gS32OffsetTime));
        CPPTEST_ASSERT_INTEGER_EQUAL(18,(_return));
        //CPPTEST_POST_CONDITION_INTEGER("S32 _return", ( _return ));
        //CPPTEST_POST_CONDITION_UINTEGER("U8 stGenSetting.u8VersionCheck", ( stGenSetting.u8VersionCheck ));
        //CPPTEST_ASSERT_EQUAL( EN_POWER_DC_ON, ( stGenSetting.stMiscSetting.bDCOnOff ) )
        //CPPTEST_POST_CONDITION_UINTEGER("U8 stGenSetting.u8VersionCheckCom", ( stGenSetting.u8VersionCheckCom ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Timer_Load_OffsetTime */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Timer_GetTime0 */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_Timer_GetTime0(void) */
void TestSuite_msAPI_Timer_test_msAPI_Timer_GetTime0()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        U32 _return  = msAPI_Timer_GetTime0();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1,(_return));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Timer_GetTime0 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Timer_SetOffsetTime */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_Timer_SetOffsetTime(S32) */
extern Bool btest_msAPI_Timer_SetOffsetTime;
void TestSuite_msAPI_Timer_test_msAPI_Timer_SetOffsetTime()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (s32OffsetTime) */
    S32 _s32OffsetTime  = 0L;
    /* Initializing global variable gU32TimeOfChange */
    {
         gU32TimeOfChange  = 0ul;
    }
    /* Initializing global variable gS32NextTimeOffset */
    {
         gS32NextTimeOffset  = 0L;
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
        msAPI_Timer_SetOffsetTime(_s32OffsetTime);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE,(btest_msAPI_Timer_SetOffsetTime));
        CPPTEST_ASSERT_INTEGER_EQUAL(0,(stGenSetting.g_Time.s32Offset_Time));
        CPPTEST_ASSERT_INTEGER_EQUAL(0,(gS32OffsetTime));
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 gU32TimeOfChange", ( gU32TimeOfChange ));
        //CPPTEST_POST_CONDITION_INTEGER("S32 gS32NextTimeOffset", ( gS32NextTimeOffset ));
        //CPPTEST_POST_CONDITION_UINTEGER("U8 stGenSetting.u8VersionCheck", ( stGenSetting.u8VersionCheck ));
        //CPPTEST_ASSERT_EQUAL( EN_POWER_DC_ON, ( stGenSetting.stMiscSetting.bDCOnOff ) )
        //CPPTEST_POST_CONDITION_UINTEGER("U8 stGenSetting.u8VersionCheckCom", ( stGenSetting.u8VersionCheckCom ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Timer_SetOffsetTime */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Timer_SetDownTimer0 */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_Timer_SetDownTimer0(U32) */
void TestSuite_msAPI_Timer_test_msAPI_Timer_SetDownTimer0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Timer) */
    U32 _u32Timer  = 0ul;
    /* Initializing global variable _TimerTarget */
    {
         _TimerTarget  = 0ul;
    }
    {
        /* Tested function call */
        msAPI_Timer_SetDownTimer0(_u32Timer);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(2,(_TimerTarget));
        //CPPTEST_POST_CONDITION_UINTEGER("MS_U32 _TimerTarget", ( _TimerTarget ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Timer_SetDownTimer0 */
