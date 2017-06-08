#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/msAPI_Memory.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/msAPI_Memory.c");

CPPTEST_TEST_SUITE(TestSuites_msAPI_Memory);
CPPTEST_TEST(TestSuites_msAPI_Memory_test_msAPI_Memory_Free_0);
CPPTEST_TEST(TestSuites_msAPI_Memory_test_msAPI_Memory_Free_1);
CPPTEST_TEST_SUITE_END();
        

void TestSuites_msAPI_Memory_test_msAPI_Memory_Free_0();
void TestSuites_msAPI_Memory_test_msAPI_Memory_Free_1();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuites_msAPI_Memory);

void TestSuites_msAPI_Memory_setUp()
{
}

void TestSuites_msAPI_Memory_tearDown()
{
}

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Memory_Free */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_Memory_Free(void *, EN_BUFFER_ID) */
void TestSuites_msAPI_Memory_test_msAPI_Memory_Free_0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pFree) */
    void * _pFree  = NULL ;
    /* Initializing argument 2 (enBufID) */
    EN_BUFFER_ID _enBufID  = BUF_ID_DESCRIPTOR;
    {
        /* Tested function call */
        U8 _return  = msAPI_Memory_Free(_pFree, _enBufID);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("void * _pFree ", ( _pFree ));
        CPPTEST_ASSERT_EQUAL(0, (_return));
    }
}

void TestSuites_msAPI_Memory_test_msAPI_Memory_Free_1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pFree) */
    void * _pFree  = NULL;
    /* Initializing argument 2 (enBufID) */
    EN_BUFFER_ID _enBufID  = BUF_ID_DESCRIPTOR;
    {
        /* Tested function call */
        U8 _return  = msAPI_Memory_Free(_pFree, _enBufID);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("void * _pFree ", ( _pFree ));
        CPPTEST_ASSERT_EQUAL(1, (_return));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Memory_Free */
