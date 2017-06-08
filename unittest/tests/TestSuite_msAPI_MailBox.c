#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/msAPI_MailBox.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/msAPI_MailBox.c");

CPPTEST_TEST_SUITE(TestSuite_msAPI_MailBox);
CPPTEST_TEST(TestSuite_msAPI_MailBox_test_MSApi_MBX_SendMsg_NULL);
CPPTEST_TEST(TestSuite_msAPI_MailBox_test_MSApi_MBX_SendMsg_ReturnTrue);
CPPTEST_TEST(TestSuite_msAPI_MailBox_test_MSApi_MBX_SendMsg_Mock);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_msAPI_MailBox_test_MSApi_MBX_SendMsg_NULL();
void TestSuite_msAPI_MailBox_test_MSApi_MBX_SendMsg_ReturnTrue();
void TestSuite_msAPI_MailBox_test_MSApi_MBX_SendMsg_Mock();

CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_msAPI_MailBox);

void TestSuite_msAPI_MailBox_setUp()
{
}

void TestSuite_msAPI_MailBox_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MSApi_MBX_SendMsg */
/* CPPTEST_TEST_CASE_CONTEXT MBX_Result MSApi_MBX_SendMsg(MBX_Msg *) */
void TestSuite_msAPI_MailBox_test_MSApi_MBX_SendMsg_NULL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pMsg) */ 
    MBX_Msg * _pMsg  = NULL ;
    {
        /* Tested function call */
        MBX_Result _return  = MSApi_MBX_SendMsg(_pMsg);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_MBX_ERR_INVALID_PARAM, ( _return ) );
        //CPPTEST_POST_CONDITION_PTR("MBX_Msg * _pMsg ", ( _pMsg ));
    }
}

void TestSuite_msAPI_MailBox_test_MSApi_MBX_SendMsg_ReturnTrue()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pMsg) */
	MBX_Msg objMsg;
    MBX_Msg * _pMsg  = &objMsg ;
    {
        /* Tested function call */
        MBX_Result _return  = MSApi_MBX_SendMsg(_pMsg);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_MBX_SUCCESS, ( _return ) );
        //CPPTEST_POST_CONDITION_PTR("MBX_Msg * _pMsg ", ( _pMsg ));
    }
}

extern MS_BOOL g_CppTest_Stub_MDrv_MBX_SendMsg_blnResult;
void TestSuite_msAPI_MailBox_test_MSApi_MBX_SendMsg_Mock()
{
    /* Pre-condition initialization */
	g_CppTest_Stub_MDrv_MBX_SendMsg_blnResult = FALSE;

    /* Initializing argument 1 (pMsg) */
	MBX_Msg objMsg;
    MBX_Msg * _pMsg  = &objMsg ;
    {
        /* Tested function call */
        MBX_Result _return  = MSApi_MBX_SendMsg(_pMsg);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( g_CppTest_Stub_MDrv_MBX_SendMsg_blnResult ) );
        //CPPTEST_POST_CONDITION_PTR("MBX_Msg * _pMsg ", ( _pMsg ));
    }
}
/* CPPTEST_TEST_CASE_END test_MSApi_MBX_SendMsg */
