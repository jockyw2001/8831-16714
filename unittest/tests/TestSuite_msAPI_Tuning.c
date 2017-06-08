#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/msAPI_Tuning.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/msAPI_Tuning.c");

CPPTEST_TEST_SUITE(TestSuite_msAPI_Tuning);
CPPTEST_TEST(TestSuite_msAPI_Tuning_test__GetBand);
CPPTEST_TEST(TestSuite_msAPI_Tuning_test__IsTunerStable_TC1);
CPPTEST_TEST(TestSuite_msAPI_Tuning_test__IsTunerStable_TC2);
CPPTEST_TEST(TestSuite_msAPI_Tuning_test__IsTunerStable_TC3);
CPPTEST_TEST(TestSuite_msAPI_Tuning_test__IsTunerStable_TC4);
CPPTEST_TEST(TestSuite_msAPI_Tuning_test__IsTunerStable_TC5);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_msAPI_Tuning_test__GetBand();
void TestSuite_msAPI_Tuning_test__IsTunerStable_TC1();
void TestSuite_msAPI_Tuning_test__IsTunerStable_TC2();
void TestSuite_msAPI_Tuning_test__IsTunerStable_TC3();
void TestSuite_msAPI_Tuning_test__IsTunerStable_TC4();
void TestSuite_msAPI_Tuning_test__IsTunerStable_TC5();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_msAPI_Tuning);

void TestSuite_msAPI_Tuning_setUp()
{
}

void TestSuite_msAPI_Tuning_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test__GetBand */
/* CPPTEST_TEST_CASE_CONTEXT RFBAND _GetBand(MS_U16) */
void TestSuite_msAPI_Tuning_test__GetBand()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16PLL) */ 
    //MS_U16 _u16PLL  = 9;
	MS_U16 _u16PLL  = VHF_HIGHMIN_PLL - 1;
    {
        /* Tested function call */
        RFBAND _return  = _GetBand(_u16PLL);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_RFBAND_VHF_LOW, ( _return ) )
    }

	_u16PLL  = VHF_HIGHMIN_PLL;
    {
        /* Tested function call */
        RFBAND _return  = _GetBand(_u16PLL);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_RFBAND_VHF_HIGH, ( _return ) )
    }

	_u16PLL  = UHF_MIN_PLL - 1;
    {
        /* Tested function call */
        RFBAND _return  = _GetBand(_u16PLL);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_RFBAND_VHF_HIGH, ( _return ) )
    }

	_u16PLL  = UHF_MIN_PLL;
    {
        /* Tested function call */
        RFBAND _return  = _GetBand(_u16PLL);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_RFBAND_UHF, ( _return ) )
    }

}
/* CPPTEST_TEST_CASE_END test__GetBand */


/* CPPTEST_TEST_CASE_BEGIN test__IsTunerStable_TC1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _IsTunerStable(void) */
void TestSuite_msAPI_Tuning_test__IsTunerStable_TC1()
{
    /* Pre-condition initialization */
    /* Initializing global variable _u16TuningWaitTimer */ 
    {
         _u16TuningWaitTimer  = 0u;
    }
    /* Initializing global variable _BOOLEANS */ 
    {
		_bIsSpeedUp = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = _IsTunerStable();
        /* Post-condition check */

        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__IsTunerStable_TC1 */

/* CPPTEST_TEST_CASE_BEGIN test__IsTunerStable_TC2 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _IsTunerStable(void) */
void TestSuite_msAPI_Tuning_test__IsTunerStable_TC2()
{
    /* Pre-condition initialization */
    /* Initializing global variable _u16TuningWaitTimer */ 
    {
         _u16TuningWaitTimer  = 23u;
    }
    /* Initializing global variable _BOOLEANS */ 
    {
		_bIsSpeedUp = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = _IsTunerStable();
        /* Post-condition check */

        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__IsTunerStable_TC2 */

/* CPPTEST_TEST_CASE_BEGIN test__IsTunerStable_TC3 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _IsTunerStable(void) */
void TestSuite_msAPI_Tuning_test__IsTunerStable_TC3()
{
    /* Pre-condition initialization */
    /* Initializing global variable _u16TuningWaitTimer */ 
    {
         _u16TuningWaitTimer  = 23u;
    }
    /* Initializing global variable _BOOLEANS */ 
    {
		_bIsSpeedUp = 1;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = _IsTunerStable();
        /* Post-condition check */

        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__IsTunerStable_TC3 */

/* CPPTEST_TEST_CASE_BEGIN test__IsTunerStable_TC4 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _IsTunerStable(void) */
void TestSuite_msAPI_Tuning_test__IsTunerStable_TC4()
{
    /* Pre-condition initialization */
    /* Initializing global variable _u16TuningWaitTimer */ 
    {
         _u16TuningWaitTimer  = 22u;
    }
    /* Initializing global variable _BOOLEANS */ 
    {
		_bIsSpeedUp = 1;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = _IsTunerStable();
        /* Post-condition check */

        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__IsTunerStable_TC4 */

/* CPPTEST_TEST_CASE_BEGIN test__IsTunerStable_TC5 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _IsTunerStable(void) */
void TestSuite_msAPI_Tuning_test__IsTunerStable_TC5()
{
    /* Pre-condition initialization */
    /* Initializing global variable _u16TuningWaitTimer */ 
    {
         _u16TuningWaitTimer  = 24u;
    }
    /* Initializing global variable _BOOLEANS */ 
    {
		_bIsSpeedUp = 1;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = _IsTunerStable();
        /* Post-condition check */

        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__IsTunerStable_TC5 */
