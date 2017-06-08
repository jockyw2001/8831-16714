#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app/MApp_Record.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app/MApp_Record.c");

CPPTEST_TEST_SUITE(TestSuite_MApp_Record);
CPPTEST_TEST(TestSuite_MApp_Record_test_MApp_Record_RecordAllDisable);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_MApp_Record_test_MApp_Record_RecordAllDisable();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_MApp_Record);

void TestSuite_MApp_Record_setUp()
{
}

void TestSuite_MApp_Record_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_Record_RecordAllDisable */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Record_RecordAllDisable(void) */
void TestSuite_MApp_Record_test_MApp_Record_RecordAllDisable()
{
    /* Pre-condition initialization */
    /* Initializing global variable _bRecordAll */ 
    {
         _bRecordAll  = 0;
    }
    /* Initializing global variable _enRecordState */ 
    {
         _enRecordState  = E_RECORD_STATE_WAIT;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_Record_RecordAllDisable();
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _bRecordAll ));

    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Record_RecordAllDisable */
/* CPPTEST_TEST_CASE_BEGIN test_MApp_Record_RecordAllEnable */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Record_RecordAllEnable(void) */
void TestSuite_MApp_Record_test_MApp_Record_RecordAllEnable()
{
    /* Pre-condition initialization */
    /* Initializing global variable _bRecordAll */ 
    {
         _bRecordAll  = 1;
    }
    /* Initializing global variable _enRecordState */ 
    {
         _enRecordState  = E_RECORD_STATE_WAIT;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_Record_RecordAllEnable();
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _bRecordAll ));

    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Record_RecordAllEnable */
