#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/dvb/mapp_si_util.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/dvb/mapp_si_util.c");

CPPTEST_TEST_SUITE(TestSuite_mapp_si_util);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Service_Type_case_E_TYPE_RADIO);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Service_Type_case_E_SERVICETYPE_DATA);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Service_Type_case_E_TYPE_DTV);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToSI_Service_Type_case_E_SERVICETYPE_RADIO);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToSI_Service_Type_case_E_SERVICETYPE_DATA);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToSI_Service_Type_case_E_SERVICETYPE_DTV);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Mode_case_E_SI_AUDIOMODE_STEREO);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Mode_case_E_SI_AUDIOMODE_RR);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Mode_case_E_SI_AUDIOMODE_LL);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Type_case_E_SI_AUDIOSTREAM_AC3);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Type_case_E_SI_AUDIOSTREAM_MPEG4);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Type_case_E_SI_AUDIOSTREAM_AAC);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Type_case_E_SI_AUDIOSTREAM_AC3P);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Type_case_E_SI_AUDIOSTREAM_MPEG);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Type_case_E_SI_AUDIOSTREAM_DRA);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Type_case_E_SI_AUDIOSTREAM_INVALID);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Video_Type_case_E_SI_VIDEOTYPE_H264);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Video_Type_case_E_SI_VIDEOTYPE_AVS);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Video_Type_case_E_SI_VIDEOTYPE_VC1);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Video_Type_case_E_SI_VIDEOTYPE_MPEG);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Service_Priority_case_E_SI_SERVICETYPE_PRIORITY_HIGH);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Service_Priority_case_E_SI_SERVICETYPE_PRIORITY_MIDDLE);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Service_Priority_case_E_SI_SERVICETYPE_PRIORITY_LOW);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Service_Priority_case_E_SI_SERVICETYPE_PRIORITY_NONE);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Delivery_Type_case_E_SI_DELIVERY_SYS_SDSD);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Delivery_Type_case_E_SI_DELIVERY_SYS_TDSD);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Delivery_Type_case_E_SI_DELIVERY_SYS_CDSD);
CPPTEST_TEST(TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Delivery_Type_case_default);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Service_Type_case_E_TYPE_RADIO();
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Service_Type_case_E_SERVICETYPE_DATA();
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Service_Type_case_E_TYPE_DTV();
void TestSuite_mapp_si_util_test_msAPI_SI_ToSI_Service_Type_case_E_SERVICETYPE_RADIO();
void TestSuite_mapp_si_util_test_msAPI_SI_ToSI_Service_Type_case_E_SERVICETYPE_DATA();
void TestSuite_mapp_si_util_test_msAPI_SI_ToSI_Service_Type_case_E_SERVICETYPE_DTV();
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Mode_case_E_SI_AUDIOMODE_STEREO();
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Mode_case_E_SI_AUDIOMODE_RR();
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Mode_case_E_SI_AUDIOMODE_LL();
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Type_case_E_SI_AUDIOSTREAM_AC3();
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Type_case_E_SI_AUDIOSTREAM_MPEG4();
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Type_case_E_SI_AUDIOSTREAM_AAC();
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Type_case_E_SI_AUDIOSTREAM_AC3P();
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Type_case_E_SI_AUDIOSTREAM_MPEG();
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Type_case_E_SI_AUDIOSTREAM_DRA();
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Type_case_E_SI_AUDIOSTREAM_INVALID();
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Video_Type_case_E_SI_VIDEOTYPE_H264();
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Video_Type_case_E_SI_VIDEOTYPE_AVS();
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Video_Type_case_E_SI_VIDEOTYPE_VC1();
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Video_Type_case_E_SI_VIDEOTYPE_MPEG();
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Service_Priority_case_E_SI_SERVICETYPE_PRIORITY_HIGH();
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Service_Priority_case_E_SI_SERVICETYPE_PRIORITY_MIDDLE();
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Service_Priority_case_E_SI_SERVICETYPE_PRIORITY_LOW();
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Service_Priority_case_E_SI_SERVICETYPE_PRIORITY_NONE();
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Delivery_Type_case_E_SI_DELIVERY_SYS_SDSD();
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Delivery_Type_case_E_SI_DELIVERY_SYS_TDSD();
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Delivery_Type_case_E_SI_DELIVERY_SYS_CDSD();
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Delivery_Type_case_default();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_mapp_si_util);

void TestSuite_mapp_si_util_setUp()
{
}

void TestSuite_mapp_si_util_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToCM_Service_Type */
/* CPPTEST_TEST_CASE_CONTEXT MEMBER_SERVICETYPE msAPI_SI_ToCM_Service_Type(MEMBER_SI_SERVICETYPE) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Service_Type_case_E_TYPE_RADIO()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (btype) */ 
    MEMBER_SI_SERVICETYPE _btype  = E_TYPE_RADIO;
    {
        /* Tested function call */
        MEMBER_SERVICETYPE _return  = msAPI_SI_ToCM_Service_Type(_btype);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_SERVICETYPE_RADIO, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToCM_Service_Type */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToCM_Service_Type */
/* CPPTEST_TEST_CASE_CONTEXT MEMBER_SERVICETYPE msAPI_SI_ToCM_Service_Type(MEMBER_SI_SERVICETYPE) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Service_Type_case_E_SERVICETYPE_DATA()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (btype) */ 
    MEMBER_SI_SERVICETYPE _btype  = E_TYPE_DATA;
    {
        /* Tested function call */
        MEMBER_SERVICETYPE _return  = msAPI_SI_ToCM_Service_Type(_btype);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_SERVICETYPE_DATA, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToCM_Service_Type */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToCM_Service_Type */
/* CPPTEST_TEST_CASE_CONTEXT MEMBER_SERVICETYPE msAPI_SI_ToCM_Service_Type(MEMBER_SI_SERVICETYPE) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Service_Type_case_E_TYPE_DTV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (btype) */ 
    MEMBER_SI_SERVICETYPE _btype  = E_TYPE_DTV;
    {
        /* Tested function call */
        MEMBER_SERVICETYPE _return  = msAPI_SI_ToCM_Service_Type(_btype);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_SERVICETYPE_DTV, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToCM_Service_Type */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToSI_Service_Type */
/* CPPTEST_TEST_CASE_CONTEXT MEMBER_SI_SERVICETYPE msAPI_SI_ToSI_Service_Type(MEMBER_SERVICETYPE) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToSI_Service_Type_case_E_SERVICETYPE_RADIO()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (btype) */ 
    MEMBER_SERVICETYPE _btype  = E_SERVICETYPE_RADIO;
    {
        /* Tested function call */
        MEMBER_SI_SERVICETYPE _return  = msAPI_SI_ToSI_Service_Type(_btype);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_TYPE_RADIO, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToSI_Service_Type */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToSI_Service_Type */
/* CPPTEST_TEST_CASE_CONTEXT MEMBER_SI_SERVICETYPE msAPI_SI_ToSI_Service_Type(MEMBER_SERVICETYPE) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToSI_Service_Type_case_E_SERVICETYPE_DATA()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (btype) */ 
    MEMBER_SERVICETYPE _btype  = E_SERVICETYPE_DATA;
    {
        /* Tested function call */
        MEMBER_SI_SERVICETYPE _return  = msAPI_SI_ToSI_Service_Type(_btype);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_TYPE_DATA, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToSI_Service_Type */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToSI_Service_Type */
/* CPPTEST_TEST_CASE_CONTEXT MEMBER_SI_SERVICETYPE msAPI_SI_ToSI_Service_Type(MEMBER_SERVICETYPE) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToSI_Service_Type_case_E_SERVICETYPE_DTV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (btype) */ 
    MEMBER_SERVICETYPE _btype  = E_SERVICETYPE_DTV;
    {
        /* Tested function call */
        MEMBER_SI_SERVICETYPE _return  = msAPI_SI_ToSI_Service_Type(_btype);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_TYPE_DTV, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToSI_Service_Type */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToCM_Audio_Mode */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_SI_ToCM_Audio_Mode(U8) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Mode_case_E_SI_AUDIOMODE_STEREO()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (btype) */ 
    U8 _btype  = E_SI_AUDIOMODE_STEREO;
    {
        /* Tested function call */
        U8 _return  = msAPI_SI_ToCM_Audio_Mode(_btype);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("0", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToCM_Audio_Mode */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToCM_Audio_Mode */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_SI_ToCM_Audio_Mode(U8) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Mode_case_E_SI_AUDIOMODE_RR()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (btype) */ 
    U8 _btype  = E_SI_AUDIOMODE_RR;
    {
        /* Tested function call */
        U8 _return  = msAPI_SI_ToCM_Audio_Mode(_btype);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("1", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToCM_Audio_Mode */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToCM_Audio_Mode */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_SI_ToCM_Audio_Mode(U8) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Mode_case_E_SI_AUDIOMODE_LL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (btype) */ 
    U8 _btype  = E_SI_AUDIOMODE_LL;
    {
        /* Tested function call */
        U8 _return  = msAPI_SI_ToCM_Audio_Mode(_btype);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("2", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToCM_Audio_Mode */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToCM_Audio_Type */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_SI_ToCM_Audio_Type(U8) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Type_case_E_SI_AUDIOSTREAM_AC3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (btype) */ 
    U8 _btype  = E_SI_AUDIOSTREAM_AC3;
    {
        /* Tested function call */
        U8 _return  = msAPI_SI_ToCM_Audio_Type(_btype);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("E_AUDIOSTREAM_AC3", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToCM_Audio_Type */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToCM_Audio_Type */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_SI_ToCM_Audio_Type(U8) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Type_case_E_SI_AUDIOSTREAM_MPEG4()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (btype) */ 
    U8 _btype  = E_SI_AUDIOSTREAM_MPEG4;
    {
        /* Tested function call */
        U8 _return  = msAPI_SI_ToCM_Audio_Type(_btype);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("E_AUDIOSTREAM_MPEG4", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToCM_Audio_Type */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToCM_Audio_Type */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_SI_ToCM_Audio_Type(U8) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Type_case_E_SI_AUDIOSTREAM_AAC()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (btype) */ 
    U8 _btype  = E_SI_AUDIOSTREAM_AAC;
    {
        /* Tested function call */
        U8 _return  = msAPI_SI_ToCM_Audio_Type(_btype);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("E_AUDIOSTREAM_AAC", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToCM_Audio_Type */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToCM_Audio_Type */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_SI_ToCM_Audio_Type(U8) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Type_case_E_SI_AUDIOSTREAM_AC3P()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (btype) */ 
    U8 _btype  = E_SI_AUDIOSTREAM_AC3P;
    {
        /* Tested function call */
        U8 _return  = msAPI_SI_ToCM_Audio_Type(_btype);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("E_AUDIOSTREAM_AC3P", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToCM_Audio_Type */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToCM_Audio_Type */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_SI_ToCM_Audio_Type(U8) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Type_case_E_SI_AUDIOSTREAM_MPEG()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (btype) */ 
    U8 _btype  = E_SI_AUDIOSTREAM_MPEG;
    {
        /* Tested function call */
        U8 _return  = msAPI_SI_ToCM_Audio_Type(_btype);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("E_AUDIOSTREAM_MPEG", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToCM_Audio_Type */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToCM_Audio_Type */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_SI_ToCM_Audio_Type(U8) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Type_case_E_SI_AUDIOSTREAM_DRA()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (btype) */ 
    U8 _btype  = E_SI_AUDIOSTREAM_DRA;
    {
        /* Tested function call */
        U8 _return  = msAPI_SI_ToCM_Audio_Type(_btype);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("E_AUDIOSTREAM_DRA", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToCM_Audio_Type */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToCM_Audio_Type */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_SI_ToCM_Audio_Type(U8) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Audio_Type_case_E_SI_AUDIOSTREAM_INVALID()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (btype) */
    U8 _btype  = E_SI_AUDIOSTREAM_INVALID;
    {
        /* Tested function call */
        U8 _return  = msAPI_SI_ToCM_Audio_Type(_btype);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("E_AUDIOSTREAM_INVALID", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToCM_Audio_Type */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToCM_Video_Type */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_SI_ToCM_Video_Type(U8) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Video_Type_case_E_SI_VIDEOTYPE_H264()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (btype) */
    U8 _btype  = E_SI_VIDEOTYPE_H264;
    {
        /* Tested function call */
        U8 _return  = msAPI_SI_ToCM_Video_Type(_btype);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("E_VIDEOTYPE_H264", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToCM_Video_Type */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToCM_Video_Type */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_SI_ToCM_Video_Type(U8) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Video_Type_case_E_SI_VIDEOTYPE_AVS()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (btype) */
    U8 _btype  = E_SI_VIDEOTYPE_AVS;
    {
        /* Tested function call */
        U8 _return  = msAPI_SI_ToCM_Video_Type(_btype);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("E_VIDEOTYPE_AVS", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToCM_Video_Type */


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToCM_Video_Type */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_SI_ToCM_Video_Type(U8) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Video_Type_case_E_SI_VIDEOTYPE_VC1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (btype) */
    U8 _btype  = E_SI_VIDEOTYPE_VC1;
    {
        /* Tested function call */
        U8 _return  = msAPI_SI_ToCM_Video_Type(_btype);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("E_VIDEOTYPE_VC1", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToCM_Video_Type */


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToCM_Video_Type */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_SI_ToCM_Video_Type(U8) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Video_Type_case_E_SI_VIDEOTYPE_MPEG()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (btype) */ 
    U8 _btype  = E_SI_VIDEOTYPE_MPEG;
    {
        /* Tested function call */
        U8 _return  = msAPI_SI_ToCM_Video_Type(_btype);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("E_VIDEOTYPE_MPEG", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToCM_Video_Type */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToCM_Service_Priority */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_SI_ToCM_Service_Priority(U8) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Service_Priority_case_E_SI_SERVICETYPE_PRIORITY_HIGH()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bPriority) */ 
    U8 _bPriority  = E_SI_SERVICETYPE_PRIORITY_HIGH;
    {
        /* Tested function call */
        U8 _return  = msAPI_SI_ToCM_Service_Priority(_bPriority);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("E_SERVICETYPE_PRIORITY_HIGH", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToCM_Service_Priority */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToCM_Service_Priority */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_SI_ToCM_Service_Priority(U8) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Service_Priority_case_E_SI_SERVICETYPE_PRIORITY_MIDDLE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bPriority) */
    U8 _bPriority  = E_SI_SERVICETYPE_PRIORITY_MIDDLE;
    {
        /* Tested function call */
        U8 _return  = msAPI_SI_ToCM_Service_Priority(_bPriority);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("E_SERVICETYPE_PRIORITY_MIDDLE", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToCM_Service_Priority */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToCM_Service_Priority */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_SI_ToCM_Service_Priority(U8) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Service_Priority_case_E_SI_SERVICETYPE_PRIORITY_LOW()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bPriority) */
    U8 _bPriority  = E_SI_SERVICETYPE_PRIORITY_LOW;
    {
        /* Tested function call */
        U8 _return  = msAPI_SI_ToCM_Service_Priority(_bPriority);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("E_SERVICETYPE_PRIORITY_LOW", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToCM_Service_Priority */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToCM_Service_Priority */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_SI_ToCM_Service_Priority(U8) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Service_Priority_case_E_SI_SERVICETYPE_PRIORITY_NONE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bPriority) */
    U8 _bPriority  = E_SI_SERVICETYPE_PRIORITY_NONE;
    {
        /* Tested function call */
        U8 _return  = msAPI_SI_ToCM_Service_Priority(_bPriority);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("E_SERVICETYPE_PRIORITY_NONE", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToCM_Service_Priority */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToCM_Delivery_Type */
/* CPPTEST_TEST_CASE_CONTEXT EN_DELIVERY_SYS_TYPE msAPI_SI_ToCM_Delivery_Type(EN_SI_DELIVERY_SYS_TYPE) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Delivery_Type_case_E_SI_DELIVERY_SYS_SDSD()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (btype) */ 
    EN_SI_DELIVERY_SYS_TYPE _btype  = E_SI_DELIVERY_SYS_SDSD;
    {
        /* Tested function call */
        EN_DELIVERY_SYS_TYPE _return  = msAPI_SI_ToCM_Delivery_Type(_btype);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_DELIVERY_SYS_SDSD, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToCM_Delivery_Type */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToCM_Delivery_Type */
/* CPPTEST_TEST_CASE_CONTEXT EN_DELIVERY_SYS_TYPE msAPI_SI_ToCM_Delivery_Type(EN_SI_DELIVERY_SYS_TYPE) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Delivery_Type_case_E_SI_DELIVERY_SYS_TDSD()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (btype) */
    EN_SI_DELIVERY_SYS_TYPE _btype  = E_SI_DELIVERY_SYS_TDSD;
    {
        /* Tested function call */
        EN_DELIVERY_SYS_TYPE _return  = msAPI_SI_ToCM_Delivery_Type(_btype);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_DELIVERY_SYS_TDSD, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToCM_Delivery_Type */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToCM_Delivery_Type */
/* CPPTEST_TEST_CASE_CONTEXT EN_DELIVERY_SYS_TYPE msAPI_SI_ToCM_Delivery_Type(EN_SI_DELIVERY_SYS_TYPE) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Delivery_Type_case_E_SI_DELIVERY_SYS_CDSD()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (btype) */
    EN_SI_DELIVERY_SYS_TYPE _btype  = E_SI_DELIVERY_SYS_CDSD;
    {
        /* Tested function call */
        EN_DELIVERY_SYS_TYPE _return  = msAPI_SI_ToCM_Delivery_Type(_btype);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_DELIVERY_SYS_CDSD, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToCM_Delivery_Type */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_ToCM_Delivery_Type */
/* CPPTEST_TEST_CASE_CONTEXT EN_DELIVERY_SYS_TYPE msAPI_SI_ToCM_Delivery_Type(EN_SI_DELIVERY_SYS_TYPE) */
void TestSuite_mapp_si_util_test_msAPI_SI_ToCM_Delivery_Type_case_default()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (btype) */
    EN_SI_DELIVERY_SYS_TYPE _btype  = E_SI_DELIVERY_SYS_NONE;
    {
        /* Tested function call */
        EN_DELIVERY_SYS_TYPE _return  = msAPI_SI_ToCM_Delivery_Type(_btype);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_DELIVERY_SYS_NONE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_ToCM_Delivery_Type */
