#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/msAPI_ATVSystem.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/msAPI_ATVSystem.c");

CPPTEST_TEST_SUITE(TestSuite_msAPI_ATVSystem);
CPPTEST_TEST(TestSuite_msAPI_ATVSystem_test_msAPI_ATV_ResetATVDataManager);
CPPTEST_TEST(TestSuite_msAPI_ATVSystem_test__SwapPRTable_index_invalid);
CPPTEST_TEST_SUITE_END();


void TestSuite_msAPI_ATVSystem_test_msAPI_ATV_ResetATVDataManager();
void TestSuite_msAPI_ATVSystem_test__SwapPRTable_index_invalid();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_msAPI_ATVSystem);

void TestSuite_msAPI_ATVSystem_setUp()
{
}

void TestSuite_msAPI_ATVSystem_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_ATV_ResetATVDataManager */
void TestSuite_msAPI_ATVSystem_test_msAPI_ATV_ResetATVDataManager()
{
    //just stub code
	msAPI_ATV_ResetATVDataManager();
}
/* CPPTEST_TEST_CASE_END test_msAPI_ATV_ResetATVDataManager */

/* CPPTEST_TEST_CASE_BEGIN test__SwapPRTable_index_invalid */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _SwapPRTable(BYTE, BYTE) */
void TestSuite_msAPI_ATVSystem_test__SwapPRTable_index_invalid()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8Index1) */
    BYTE _u8Index1  = 0;
    /* Initializing argument 2 (u8Index2) */
    BYTE _u8Index2  = 0;
    {
    }

    { // index1 is wrong
    	_u8Index1 = MAX_ATVPROGRAM + 1;
    	_u8Index2 = 1;
        /* Tested function call */
        BOOLEAN _return  = _SwapPRTable(_u8Index1, _u8Index2);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
    }

    { // index2is wrong
    	_u8Index1 = 1;
    	_u8Index2 = MAX_ATVPROGRAM + 1;
        /* Tested function call */
        BOOLEAN _return  = _SwapPRTable(_u8Index1, _u8Index2);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
    }

}
/* CPPTEST_TEST_CASE_END test__SwapPRTable_index_invalid */
