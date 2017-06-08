#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app/MApp_USBDownload.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app/MApp_USBDownload.c");

CPPTEST_TEST_SUITE(TestSuite_MApp_USBDownload);
CPPTEST_TEST(TestSuite_MApp_USBDownload_test_MApp_UsbClearWatchDog);
CPPTEST_TEST(TestSuite_MApp_USBDownload_test_MApp_UsbSetWatchDogTimer);
CPPTEST_TEST(TestSuite_MApp_USBDownload_test_MApp_UsbBDMA_Copy);
CPPTEST_TEST(TestSuite_MApp_USBDownload_test_MApp_UsbPA2VA);
CPPTEST_TEST(TestSuite_MApp_USBDownload_test_MApp_UsbVA2PA);
CPPTEST_TEST(TestSuite_MApp_USBDownload_test_MApp_UsbEnableWatchDog);
CPPTEST_TEST(TestSuite_MApp_USBDownload_test_MApp_UsbDownload_Init);
CPPTEST_TEST(TestSuite_MApp_USBDownload_test_MApp_UsbDownload_Init_DetectSize_fail);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_MApp_USBDownload_test_MApp_UsbClearWatchDog();
void TestSuite_MApp_USBDownload_test_MApp_UsbSetWatchDogTimer();
void TestSuite_MApp_USBDownload_test_MApp_UsbBDMA_Copy();
void TestSuite_MApp_USBDownload_test_MApp_UsbPA2VA();
void TestSuite_MApp_USBDownload_test_MApp_UsbVA2PA();
void TestSuite_MApp_USBDownload_test_MApp_UsbEnableWatchDog();
void TestSuite_MApp_USBDownload_test_MApp_UsbDownload_Init();
void TestSuite_MApp_USBDownload_test_MApp_UsbDownload_Init_DetectSize_fail();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_MApp_USBDownload);

void TestSuite_MApp_USBDownload_setUp()
{
}

void TestSuite_MApp_USBDownload_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_UsbClearWatchDog */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_UsbClearWatchDog(void) */
void TestSuite_MApp_USBDownload_test_MApp_UsbClearWatchDog()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        //MApp_UsbClearWatchDog();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_UsbClearWatchDog */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_UsbSetWatchDogTimer */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_UsbSetWatchDogTimer(U8) */
void TestSuite_MApp_USBDownload_test_MApp_UsbSetWatchDogTimer()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8sec) */ 
    U8 _u8sec  = 10;
    {
        /* Tested function call */
        MApp_UsbSetWatchDogTimer(_u8sec);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_UsbSetWatchDogTimer */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_UsbBDMA_Copy */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_UsbBDMA_Copy(U32, U32, U32, U8) */
void TestSuite_MApp_USBDownload_test_MApp_UsbBDMA_Copy()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Srcaddr) */ 
    U32 _u32Srcaddr  = 0ul;
    /* Initializing argument 2 (u32Dstaddr) */ 
    U32 _u32Dstaddr  = 0ul;
    /* Initializing argument 3 (u32Len) */ 
    U32 _u32Len  = 0ul;
    /* Initializing argument 4 (eType) */ 
    U8 _eType  = 0;
    {
        /* Tested function call */
        MApp_UsbBDMA_Copy(_u32Srcaddr, _u32Dstaddr, _u32Len, _eType);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_UsbBDMA_Copy */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_UsbPA2VA */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_UsbPA2VA(U32) */
void TestSuite_MApp_USBDownload_test_MApp_UsbPA2VA()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32x) */ 
    U32 _u32x  = 0ul;
    {
        /* Tested function call */
        U32 _return  = MApp_UsbPA2VA(_u32x);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_UsbPA2VA */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_UsbVA2PA */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_UsbVA2PA(U32) */
void TestSuite_MApp_USBDownload_test_MApp_UsbVA2PA()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32x) */ 
    U32 _u32x  = 0ul;
    {
        /* Tested function call */
        U32 _return  = MApp_UsbVA2PA(_u32x);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0ul, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_UsbVA2PA */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_UsbEnableWatchDog */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_UsbEnableWatchDog(void) */
void TestSuite_MApp_USBDownload_test_MApp_UsbEnableWatchDog()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        MApp_UsbEnableWatchDog();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_UsbEnableWatchDog */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_UsbDownload_Init */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_UsbDownload_Init(U8, pZUIDrawCB) */
void TestSuite_MApp_USBDownload_test_MApp_UsbDownload_Init()
{
    /* Pre-condition initialization */
	//U32 u32FlashSize = 0;
    /* Initializing argument 1 (u8PortNo) */ 
    U8 _u8PortNo  = 0;
    /* Initializing argument 2 (ZUIDrawPercentage) */ 
    pZUIDrawCB _ZUIDrawPercentage  = 0 ;
    {
        /* Tested function call */
        MApp_UsbDownload_Init(_u8PortNo, _ZUIDrawPercentage);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_UsbDownload_Init */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_UsbDownload_Init_DetectSize_fail */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_UsbDownload_Init(U8, pZUIDrawCB) */
void TestSuite_MApp_USBDownload_test_MApp_UsbDownload_Init_DetectSize_fail()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8PortNo) */ 
    U8 _u8PortNo  = 0;
    /* Initializing argument 2 (ZUIDrawPercentage) */ 
    pZUIDrawCB _ZUIDrawPercentage  = 0 ;
    {
        /* Tested function call */
        MApp_UsbDownload_Init(_u8PortNo, _ZUIDrawPercentage);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_UsbDownload_Init_DetectSize_fail */

