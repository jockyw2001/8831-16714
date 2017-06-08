#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app/MApp_PIP.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app/MApp_PIP.c");

CPPTEST_TEST_SUITE(TestSuite_MApp_PIP);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_VGA);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_TV);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS2);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS3);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS4);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS5);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS6);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS7);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS8);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS_MAX);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_SVIDEO);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_SVIDEO2);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_SVIDEO3);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_SVIDEO4);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_SVIDEO_MAX);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_YPBPR);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_YPBPR2);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_YPBPR3);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_YPBPR_MAX);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_SCART);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_SCART2);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_SCART_MAX);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_HDMI);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_HDMI2);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_HDMI3);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_HDMI4);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_HDMI_MAX);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_DTV);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_Storage);
CPPTEST_TEST(TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_Storage2);
CPPTEST_TEST(TestSuite_MApp_PIP_test_MApp_InputSource_PIP_IsSrcCompatible_ture_false);
CPPTEST_TEST_SUITE_END();


void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_VGA();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_TV();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS2();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS3();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS4();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS5();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS6();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS7();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS8();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS_MAX();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_SVIDEO();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_SVIDEO2();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_SVIDEO3();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_SVIDEO4();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_SVIDEO_MAX();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_YPBPR();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_YPBPR2();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_YPBPR3();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_YPBPR_MAX();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_SCART();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_SCART2();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_SCART_MAX();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_HDMI();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_HDMI2();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_HDMI3();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_HDMI4();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_HDMI_MAX();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_DTV();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_Storage();
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_Storage2();
void TestSuite_MApp_PIP_test_MApp_InputSource_PIP_IsSrcCompatible_ture_false();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_MApp_PIP);

void TestSuite_MApp_PIP_setUp()
{
}

void TestSuite_MApp_PIP_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_VGA */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_VGA()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_VGA;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(6, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_VGA */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_TV */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_TV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_TV;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_TV */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_CVBS */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_CVBS;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(2, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_CVBS */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_CVBS2 */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_CVBS2;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(2, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_CVBS2 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_CVBS3 */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_CVBS3;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(2, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_CVBS3 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_CVBS4 */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS4()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_CVBS4;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(2, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_CVBS4 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_CVBS5 */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS5()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_CVBS5;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(2, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_CVBS5 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_CVBS6 */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS6()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_CVBS6;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(2, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_CVBS6 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_CVBS7 */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS7()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_CVBS7;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(2, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_CVBS7 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_CVBS8 */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS8()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_CVBS8;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(2, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_CVBS8 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_CVBS_MAX */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_CVBS_MAX()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_CVBS_MAX;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(255, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_CVBS_MAX */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_SVIDEO */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_SVIDEO()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_SVIDEO;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(4, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_SVIDEO */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_SVIDEO2 */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_SVIDEO2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_SVIDEO2;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(4, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_SVIDEO2 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_SVIDEO3 */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_SVIDEO3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_SVIDEO3;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(4, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_SVIDEO3 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_SVIDEO4 */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_SVIDEO4()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_SVIDEO4;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(4, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_SVIDEO4 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_SVIDEO_MAX */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_SVIDEO_MAX()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_SVIDEO_MAX;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(255, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_SVIDEO_MAX */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_YPBPR */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_YPBPR()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_YPBPR;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(5, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_YPBPR */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_YPBPR2 */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_YPBPR2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_YPBPR2;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(5, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_YPBPR2 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_YPBPR3 */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_YPBPR3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_YPBPR3;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(5, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_YPBPR3 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_YPBPR_MAX */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_YPBPR_MAX()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_YPBPR_MAX;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(255, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_YPBPR_MAX */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_SCART */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_SCART()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_SCART;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(3, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_SCART */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_SCART2 */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_SCART2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_SCART2;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(3, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_SCART2 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_SCART_MAX */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_SCART_MAX()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_SCART_MAX;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(255, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_SCART_MAX */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_HDMI */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_HDMI()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_HDMI;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(7, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_HDMI */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_HDMI2 */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_HDMI2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_HDMI2;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(7, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_HDMI2 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_HDMI3 */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_HDMI3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_HDMI3;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(7, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_HDMI3 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_HDMI4 */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_HDMI4()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_HDMI4;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(7, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_HDMI4 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_HDMI_MAX */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_HDMI_MAX()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_HDMI_MAX;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(255, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_HDMI_MAX */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_DTV */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_DTV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_DTV;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_DTV */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_Storage */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_Storage()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_STORAGE;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(8, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_Storage */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_InputSource_PIP_GetCompatibleNum_Storage2 */
/* CPPTEST_TEST_CASE_CONTEXT U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test__MApp_InputSource_PIP_GetCompatibleNum_Storage2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_STORAGE2;
    {
        /* Tested function call */
        U8 _return  = _MApp_InputSource_PIP_GetCompatibleNum(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(8, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_InputSource_PIP_GetCompatibleNum_Storage2 */



/* CPPTEST_TEST_CASE_BEGIN test_MApp_InputSource_PIP_IsSrcCompatible_ture_false */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_InputSource_PIP_IsSrcCompatible(INPUT_SOURCE_TYPE_t, INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test_MApp_InputSource_PIP_IsSrcCompatible_ture_false()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrcMain) */
    INPUT_SOURCE_TYPE_t _enSrcMain  = INPUT_SOURCE_VGA;
    /* Initializing argument 2 (enSrcSub) */
    INPUT_SOURCE_TYPE_t _enSrcSub  = INPUT_SOURCE_VGA;

    CPPTEST_ASSERT_EQUAL(0, ( PIP_DTVMAIN_DTVSUB_SUPPORT ));
    CPPTEST_ASSERT_EQUAL(0, ( PIP_CVBSMAIN_CVBSSUB_SUPPORT ));
    CPPTEST_ASSERT_EQUAL(0, ( PIP_COMPONENTMAIN_COMPONENTSUB_SUPPORT ));
    CPPTEST_ASSERT_EQUAL(0, ( PIP_SVMAIN_SVSUB_SUPPORT ));
    CPPTEST_ASSERT_EQUAL(0, ( PIP_VGAMAIN_VGASUB_SUPPORT ));
    CPPTEST_ASSERT_EQUAL(0, ( PIP_HDMIMAIN_HDMISUB_SUPPORT ));
    CPPTEST_ASSERT_EQUAL(0, ( PIP_DMPMAIN_DMPSUB_SUPPORT ));

    {
    	_enSrcMain  = INPUT_SOURCE_DTV;
    	_enSrcSub  = INPUT_SOURCE_HDMI;
        /* Tested function call */
        BOOLEAN _return  = MApp_InputSource_PIP_IsSrcCompatible(_enSrcMain, _enSrcSub);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(PIP_DTVMAIN_HDMISUB_SUPPORT, ( _return ));
    }
    {
    	_enSrcMain  = INPUT_SOURCE_DTV;
    	_enSrcSub  = INPUT_SOURCE_VGA;
        /* Tested function call */
        BOOLEAN _return  = MApp_InputSource_PIP_IsSrcCompatible(_enSrcMain, _enSrcSub);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(PIP_DTVMAIN_VGASUB_SUPPORT, ( _return ));
    }
    {
    	_enSrcMain  = INPUT_SOURCE_TV;
    	_enSrcSub  = INPUT_SOURCE_HDMI;
        /* Tested function call */
        BOOLEAN _return  = MApp_InputSource_PIP_IsSrcCompatible(_enSrcMain, _enSrcSub);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(PIP_ATVMAIN_HDMISUB_SUPPORT, ( _return ));
    }
    {
    	_enSrcMain  = INPUT_SOURCE_HDMI;
    	_enSrcSub  = INPUT_SOURCE_YPBPR;
        /* Tested function call */
        BOOLEAN _return  = MApp_InputSource_PIP_IsSrcCompatible(_enSrcMain, _enSrcSub);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(PIP_HDMIMAIN_COMPONENTSUB_SUPPORT, ( _return ));
    }

    {
    	_enSrcMain  = INPUT_SOURCE_DTV;
    	_enSrcSub  = INPUT_SOURCE_STORAGE;
        /* Tested function call */
        BOOLEAN _return  = MApp_InputSource_PIP_IsSrcCompatible(_enSrcMain, _enSrcSub);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(0, ( _return ));
    }

}
/* CPPTEST_TEST_CASE_END test_MApp_InputSource_PIP_IsSrcCompatible_ture_false */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS */
/* CPPTEST_TEST_CASE_CONTEXT INPUT_SOURCE_TYPE_t MApp_InputSource_PIP_Get1stCompatibleSrc(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_CVBS;
    {
        /* Tested function call */
        INPUT_SOURCE_TYPE_t _return  = MApp_InputSource_PIP_Get1stCompatibleSrc(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( INPUT_SOURCE_YPBPR, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS2 */
/* CPPTEST_TEST_CASE_CONTEXT INPUT_SOURCE_TYPE_t MApp_InputSource_PIP_Get1stCompatibleSrc(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_CVBS2;
    {
        /* Tested function call */
        INPUT_SOURCE_TYPE_t _return  = MApp_InputSource_PIP_Get1stCompatibleSrc(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( INPUT_SOURCE_YPBPR, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS2 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS3 */
/* CPPTEST_TEST_CASE_CONTEXT INPUT_SOURCE_TYPE_t MApp_InputSource_PIP_Get1stCompatibleSrc(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_CVBS3;
    {
        /* Tested function call */
        INPUT_SOURCE_TYPE_t _return  = MApp_InputSource_PIP_Get1stCompatibleSrc(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( INPUT_SOURCE_YPBPR, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS3 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS4 */
/* CPPTEST_TEST_CASE_CONTEXT INPUT_SOURCE_TYPE_t MApp_InputSource_PIP_Get1stCompatibleSrc(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS4()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_CVBS4;
    {
        /* Tested function call */
        INPUT_SOURCE_TYPE_t _return  = MApp_InputSource_PIP_Get1stCompatibleSrc(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( INPUT_SOURCE_YPBPR, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS4 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS5 */
/* CPPTEST_TEST_CASE_CONTEXT INPUT_SOURCE_TYPE_t MApp_InputSource_PIP_Get1stCompatibleSrc(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS5()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_CVBS5;
    {
        /* Tested function call */
        INPUT_SOURCE_TYPE_t _return  = MApp_InputSource_PIP_Get1stCompatibleSrc(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( INPUT_SOURCE_YPBPR, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS5 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS6 */
/* CPPTEST_TEST_CASE_CONTEXT INPUT_SOURCE_TYPE_t MApp_InputSource_PIP_Get1stCompatibleSrc(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS6()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_CVBS6;
    {
        /* Tested function call */
        INPUT_SOURCE_TYPE_t _return  = MApp_InputSource_PIP_Get1stCompatibleSrc(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( INPUT_SOURCE_YPBPR, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS6 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS7 */
/* CPPTEST_TEST_CASE_CONTEXT INPUT_SOURCE_TYPE_t MApp_InputSource_PIP_Get1stCompatibleSrc(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS7()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_CVBS7;
    {
        /* Tested function call */
        INPUT_SOURCE_TYPE_t _return  = MApp_InputSource_PIP_Get1stCompatibleSrc(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( INPUT_SOURCE_YPBPR, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS7 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS8 */
/* CPPTEST_TEST_CASE_CONTEXT INPUT_SOURCE_TYPE_t MApp_InputSource_PIP_Get1stCompatibleSrc(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS8()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_CVBS8;
    {
        /* Tested function call */
        INPUT_SOURCE_TYPE_t _return  = MApp_InputSource_PIP_Get1stCompatibleSrc(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( INPUT_SOURCE_YPBPR, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS8 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_InputSource_PIP_Get1stCompatibleSrc_SCART */
/* CPPTEST_TEST_CASE_CONTEXT INPUT_SOURCE_TYPE_t MApp_InputSource_PIP_Get1stCompatibleSrc(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_SCART()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_SCART;
    {
        /* Tested function call */
        INPUT_SOURCE_TYPE_t _return  = MApp_InputSource_PIP_Get1stCompatibleSrc(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( INPUT_SOURCE_HDMI, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_InputSource_PIP_Get1stCompatibleSrc_SCART */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_InputSource_PIP_Get1stCompatibleSrc_SCART2 */
/* CPPTEST_TEST_CASE_CONTEXT INPUT_SOURCE_TYPE_t MApp_InputSource_PIP_Get1stCompatibleSrc(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_SCART2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_SCART2;
    {
        /* Tested function call */
        INPUT_SOURCE_TYPE_t _return  = MApp_InputSource_PIP_Get1stCompatibleSrc(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( INPUT_SOURCE_HDMI, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_InputSource_PIP_Get1stCompatibleSrc_SCART2 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_InputSource_PIP_Get1stCompatibleSrc_SVIDEO */
/* CPPTEST_TEST_CASE_CONTEXT INPUT_SOURCE_TYPE_t MApp_InputSource_PIP_Get1stCompatibleSrc(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_SVIDEO()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_SVIDEO;
    {
        /* Tested function call */
        INPUT_SOURCE_TYPE_t _return  = MApp_InputSource_PIP_Get1stCompatibleSrc(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( INPUT_SOURCE_HDMI, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_InputSource_PIP_Get1stCompatibleSrc_SVIDEO */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_InputSource_PIP_Get1stCompatibleSrc_SVIDEO2 */
/* CPPTEST_TEST_CASE_CONTEXT INPUT_SOURCE_TYPE_t MApp_InputSource_PIP_Get1stCompatibleSrc(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_SVIDEO2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_SVIDEO2;
    {
        /* Tested function call */
        INPUT_SOURCE_TYPE_t _return  = MApp_InputSource_PIP_Get1stCompatibleSrc(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( INPUT_SOURCE_HDMI, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_InputSource_PIP_Get1stCompatibleSrc_SVIDEO2 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_InputSource_PIP_Get1stCompatibleSrc_SVIDEO3 */
/* CPPTEST_TEST_CASE_CONTEXT INPUT_SOURCE_TYPE_t MApp_InputSource_PIP_Get1stCompatibleSrc(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_SVIDEO3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_SVIDEO3;
    {
        /* Tested function call */
        INPUT_SOURCE_TYPE_t _return  = MApp_InputSource_PIP_Get1stCompatibleSrc(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( INPUT_SOURCE_HDMI, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_InputSource_PIP_Get1stCompatibleSrc_SVIDEO3 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_InputSource_PIP_Get1stCompatibleSrc_SVIDEO4 */
/* CPPTEST_TEST_CASE_CONTEXT INPUT_SOURCE_TYPE_t MApp_InputSource_PIP_Get1stCompatibleSrc(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_SVIDEO4()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_SVIDEO4;
    {
        /* Tested function call */
        INPUT_SOURCE_TYPE_t _return  = MApp_InputSource_PIP_Get1stCompatibleSrc(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( INPUT_SOURCE_HDMI, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_InputSource_PIP_Get1stCompatibleSrc_SVIDEO4 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_InputSource_PIP_Get1stCompatibleSrc_YPBPR */
/* CPPTEST_TEST_CASE_CONTEXT INPUT_SOURCE_TYPE_t MApp_InputSource_PIP_Get1stCompatibleSrc(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_YPBPR()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_YPBPR;
    {
        /* Tested function call */
        INPUT_SOURCE_TYPE_t _return  = MApp_InputSource_PIP_Get1stCompatibleSrc(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( INPUT_SOURCE_DTV, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_InputSource_PIP_Get1stCompatibleSrc_YPBPR */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_InputSource_PIP_Get1stCompatibleSrc_YPBPR2 */
/* CPPTEST_TEST_CASE_CONTEXT INPUT_SOURCE_TYPE_t MApp_InputSource_PIP_Get1stCompatibleSrc(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_YPBPR2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_YPBPR2;
    {
        /* Tested function call */
        INPUT_SOURCE_TYPE_t _return  = MApp_InputSource_PIP_Get1stCompatibleSrc(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( INPUT_SOURCE_DTV, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_InputSource_PIP_Get1stCompatibleSrc_YPBPR2 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_InputSource_PIP_Get1stCompatibleSrc_YPBPR3 */
/* CPPTEST_TEST_CASE_CONTEXT INPUT_SOURCE_TYPE_t MApp_InputSource_PIP_Get1stCompatibleSrc(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_YPBPR3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_YPBPR3;
    {
        /* Tested function call */
        INPUT_SOURCE_TYPE_t _return  = MApp_InputSource_PIP_Get1stCompatibleSrc(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( INPUT_SOURCE_DTV, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_InputSource_PIP_Get1stCompatibleSrc_YPBPR3 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_InputSource_PIP_Get1stCompatibleSrc_VGA */
/* CPPTEST_TEST_CASE_CONTEXT INPUT_SOURCE_TYPE_t MApp_InputSource_PIP_Get1stCompatibleSrc(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_VGA()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_VGA;
    {
        /* Tested function call */
        INPUT_SOURCE_TYPE_t _return  = MApp_InputSource_PIP_Get1stCompatibleSrc(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( INPUT_SOURCE_DTV, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_InputSource_PIP_Get1stCompatibleSrc_VGA */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_InputSource_PIP_Get1stCompatibleSrc_HDMI */
/* CPPTEST_TEST_CASE_CONTEXT INPUT_SOURCE_TYPE_t MApp_InputSource_PIP_Get1stCompatibleSrc(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_HDMI()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_HDMI;
    {
        /* Tested function call */
        INPUT_SOURCE_TYPE_t _return  = MApp_InputSource_PIP_Get1stCompatibleSrc(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( INPUT_SOURCE_DTV, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_InputSource_PIP_Get1stCompatibleSrc_HDMI */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_InputSource_PIP_Get1stCompatibleSrc_HDMI2 */
/* CPPTEST_TEST_CASE_CONTEXT INPUT_SOURCE_TYPE_t MApp_InputSource_PIP_Get1stCompatibleSrc(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_HDMI2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_HDMI2;
    {
        /* Tested function call */
        INPUT_SOURCE_TYPE_t _return  = MApp_InputSource_PIP_Get1stCompatibleSrc(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( INPUT_SOURCE_DTV, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_InputSource_PIP_Get1stCompatibleSrc_HDMI2 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_InputSource_PIP_Get1stCompatibleSrc_HDMI3 */
/* CPPTEST_TEST_CASE_CONTEXT INPUT_SOURCE_TYPE_t MApp_InputSource_PIP_Get1stCompatibleSrc(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_HDMI3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_HDMI3;
    {
        /* Tested function call */
        INPUT_SOURCE_TYPE_t _return  = MApp_InputSource_PIP_Get1stCompatibleSrc(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( INPUT_SOURCE_DTV, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_InputSource_PIP_Get1stCompatibleSrc_HDMI3 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_InputSource_PIP_Get1stCompatibleSrc_HDMI4 */
/* CPPTEST_TEST_CASE_CONTEXT INPUT_SOURCE_TYPE_t MApp_InputSource_PIP_Get1stCompatibleSrc(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_HDMI4()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_HDMI4;
    {
        /* Tested function call */
        INPUT_SOURCE_TYPE_t _return  = MApp_InputSource_PIP_Get1stCompatibleSrc(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( INPUT_SOURCE_DTV, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_InputSource_PIP_Get1stCompatibleSrc_HDMI4 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_InputSource_PIP_Get1stCompatibleSrc_Storage */
/* CPPTEST_TEST_CASE_CONTEXT INPUT_SOURCE_TYPE_t MApp_InputSource_PIP_Get1stCompatibleSrc(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_Storage()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_STORAGE;
    {
        /* Tested function call */
        INPUT_SOURCE_TYPE_t _return  = MApp_InputSource_PIP_Get1stCompatibleSrc(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( INPUT_SOURCE_YPBPR, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_InputSource_PIP_Get1stCompatibleSrc_Storage */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_InputSource_PIP_Get1stCompatibleSrc_Storage2 */
/* CPPTEST_TEST_CASE_CONTEXT INPUT_SOURCE_TYPE_t MApp_InputSource_PIP_Get1stCompatibleSrc(INPUT_SOURCE_TYPE_t) */
void TestSuite_MApp_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_Storage2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enSrc) */
    INPUT_SOURCE_TYPE_t _enSrc  = INPUT_SOURCE_STORAGE2;
    {
        /* Tested function call */
        INPUT_SOURCE_TYPE_t _return  = MApp_InputSource_PIP_Get1stCompatibleSrc(_enSrc);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( INPUT_SOURCE_YPBPR, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_InputSource_PIP_Get1stCompatibleSrc_Storage2 */