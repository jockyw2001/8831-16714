#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/dvb/mapp_si_if.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/dvb/mapp_si_if.c");

CPPTEST_TEST_SUITE(TestSuite_mapp_si_if);
/*
CPPTEST_TEST(TestSuite_mapp_si_if_test_msAPI_SI_SaveServiceListInfo);
CPPTEST_TEST(TestSuite_mapp_si_if_test_MApp_SI_GetCurrentServiceListID);
CPPTEST_TEST(TestSuite_mapp_si_if_test_msAPI_SI_GetExistServiceListInfo);*/

CPPTEST_TEST_SUITE_END();
        
/*
void TestSuite_mapp_si_if_test_msAPI_SI_SaveServiceListInfo();
void TestSuite_mapp_si_if_test_MApp_SI_GetCurrentServiceListID();
void TestSuite_mapp_si_if_test_msAPI_SI_GetExistServiceListInfo();*/

CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_mapp_si_if);

void TestSuite_mapp_si_if_setUp()
{
}

void TestSuite_mapp_si_if_tearDown()
{
}

#define ENABLE_ASTRA_HD_UT_IF  0


#if(ENABLE_ASTRA_HD_UT_IF)
/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_SaveServiceListInfo */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_SI_SaveServiceListInfo(const U8 *, U16, BOOLEAN) */
void TestSuite_mapp_si_if_test_msAPI_SI_SaveServiceListInfo()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Dest) */ 
	U8 pu8Dest[MAX_SERVICE_LIST_NAME] = {0};
    const U8 * _pu8Dest  = pu8Dest ;
    /* Initializing argument 2 (u16ServiceListID) */ 
    U16 _u16ServiceListID  = 1u;
    /* Initializing argument 3 (bListInFlag) */ 
    U8 _bListInFlag  = 1;
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_SI_SaveServiceListInfo(_pu8Dest, _u16ServiceListID, _bListInFlag);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_SaveServiceListInfo */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_SI_GetCurrentServiceListID */
/* CPPTEST_TEST_CASE_CONTEXT U16 MApp_SI_GetCurrentServiceListID(void) */
void TestSuite_mapp_si_if_test_MApp_SI_GetCurrentServiceListID()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
    	U16 u16ServiceListID = 0u;
        U16 _return  = MApp_SI_GetCurrentServiceListID();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL( u16ServiceListID,( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_SI_GetCurrentServiceListID */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_GetExistServiceListInfo */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_SI_GetExistServiceListInfo(const U16, BOOLEAN) */
void TestSuite_mapp_si_if_test_msAPI_SI_GetExistServiceListInfo()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16ServiceListID) */ 
    U16 _u16ServiceListID  = 1u;
    /* Initializing argument 2 (bListInFlag) */ 
    U8 _bListInFlag  = 1;
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_SI_GetExistServiceListInfo(_u16ServiceListID, _bListInFlag);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_GetExistServiceListInfo */
#endif 


