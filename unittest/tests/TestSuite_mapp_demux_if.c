#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/dvb/mapp_demux_if.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/dvb/mapp_demux_if.c");

CPPTEST_TEST_SUITE(TestSuite_mapp_demux_if);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_CheckCRC32);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Close);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_CloseFilter);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_CopyData);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Cb_Status_case_MSAPI_DMX_FILTER_STATUS_OVERFLOW);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Cb_Status_case_MSAPI_DMX_FILTER_STATUS_SECAVAILABLE);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Cb_Status_case_MSAPI_DMX_FILTER_STATUS_OK);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Cb_Status_case_MSAPI_DMX_FILTER_STATUS_TIMEOUT);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Cb_Status_case_MSAPI_DMX_FILTER_STATUS_CRCINCORRECT);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Cb_Status_case_MSAPI_DMX_FILTER_STATUS_REQUESTMEET);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Cb_Status_case_MSAPI_DMX_FILTER_STATUS_COPYSECERR);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Cb_Status_case_MSAPI_DMX_FILTER_STATUS_ERROR);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Status_case_DMX_FILTER_STATUS_OK);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Status_case_DMX_FILTER_STATUS_ERROR);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Status_case_2);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_VIDEO);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_AUDIO);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_AUDIO2);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_SUBTITLE);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_TELETEXT);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_PES);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_SECTION_1K);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_SECTION_4K);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_SECTION_VERSION);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_SECTION_CRC);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_PCR);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_PACKET);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_PACKET_PUSI);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_PACKET_AF);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_OAD_MONITOR);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_OAD_DOWNLOAD);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_RECORD);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_SECTION_EIT);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_CSA_PACKET);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_SOURCE_TYPE_MASK);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_SOURCE_TYPE_LIVE);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_SOURCE_TYPE_FILE);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_100);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_SecMode_case_SI_DMX_SECT_MODE_CONTI);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_SecMode_case_SI_DMX_SECT_MODE_ONESHOT);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_SecMode_case_SI_DMX_SECT_MODE_CRCCHK);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_SecMode_case_SI_DMX_SECT_MODE_AUTO_ADDR);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_SecMode_case_100);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Pid);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Proc);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Reset);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_RestartFilter);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_SectionGet);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_SectionMonitor);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Start);
CPPTEST_TEST(TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Stop);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_CheckCRC32();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Close();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_CloseFilter();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_CopyData();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Cb_Status_case_MSAPI_DMX_FILTER_STATUS_OVERFLOW();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Cb_Status_case_MSAPI_DMX_FILTER_STATUS_SECAVAILABLE();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Cb_Status_case_MSAPI_DMX_FILTER_STATUS_OK();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Cb_Status_case_MSAPI_DMX_FILTER_STATUS_TIMEOUT();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Cb_Status_case_MSAPI_DMX_FILTER_STATUS_CRCINCORRECT();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Cb_Status_case_MSAPI_DMX_FILTER_STATUS_REQUESTMEET();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Cb_Status_case_MSAPI_DMX_FILTER_STATUS_COPYSECERR();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Cb_Status_case_MSAPI_DMX_FILTER_STATUS_ERROR();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Status_case_DMX_FILTER_STATUS_OK();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Status_case_DMX_FILTER_STATUS_ERROR();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Status_case_2();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_VIDEO();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_AUDIO();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_AUDIO2();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_SUBTITLE();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_TELETEXT();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_PES();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_SECTION_1K();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_SECTION_4K();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_SECTION_VERSION();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_SECTION_CRC();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_PCR();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_PACKET();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_PACKET_PUSI();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_PACKET_AF();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_OAD_MONITOR();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_OAD_DOWNLOAD();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_RECORD();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_SECTION_EIT();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_CSA_PACKET();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_SOURCE_TYPE_MASK();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_SOURCE_TYPE_LIVE();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_SOURCE_TYPE_FILE();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_100();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_SecMode_case_SI_DMX_SECT_MODE_CONTI();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_SecMode_case_SI_DMX_SECT_MODE_ONESHOT();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_SecMode_case_SI_DMX_SECT_MODE_CRCCHK();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_SecMode_case_SI_DMX_SECT_MODE_AUTO_ADDR();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_SecMode_case_100();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Pid();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Proc();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Reset();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_RestartFilter();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_SectionGet();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_SectionMonitor();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Start();
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Stop();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_mapp_demux_if);

void TestSuite_mapp_demux_if_setUp()
{
}

void TestSuite_mapp_demux_if_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_CheckCRC32 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_SI_Dmx_CheckCRC32(U8 *) */
extern BOOLEAN gbTest_msAPI_SI_Dmx_CheckCRC32_CallmsAPI_DMX_CheckCRC32;
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_CheckCRC32()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Section) */ 
    U8 * _pu8Section  = 0 ;
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_SI_Dmx_CheckCRC32(_pu8Section);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( gbTest_msAPI_SI_Dmx_CheckCRC32_CallmsAPI_DMX_CheckCRC32 ));
        CPPTEST_ASSERT_BOOL_EQUAL(0, ( _pu8Section ));
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_CheckCRC32 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Close */
/* CPPTEST_TEST_CASE_CONTEXT SI_DMX_FILTER_STATUS msAPI_SI_Dmx_Close(U8) */
extern BOOLEAN gbTest_msAPI_SI_Dmx_Close_CallmsAPI_DMX_Close;
extern BOOLEAN gbTest_msAPI_SI_Dmx_Close_CallmsAPI_SI_Dmx_Filter_Status;
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Close()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FltID) */ 
    U8 _u8FltID  = 0;
    {
        /* Tested function call */
        SI_DMX_FILTER_STATUS _return  = msAPI_SI_Dmx_Close(_u8FltID);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_msAPI_SI_Dmx_Close_CallmsAPI_DMX_Close);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_msAPI_SI_Dmx_Close_CallmsAPI_SI_Dmx_Filter_Status);
        CPPTEST_ASSERT_EQUAL( SI_DMX_FILTER_STATUS_OK, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Close */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_CloseFilter */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_SI_Dmx_CloseFilter(U8) */
extern BOOLEAN gbTest_msAPI_SI_Dmx_CloseFilter_CallmsAPI_DMX_CloseFilter;
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_CloseFilter()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FID) */ 
    U8 _u8FID  = 0;
    {
        /* Tested function call */
        msAPI_SI_Dmx_CloseFilter(_u8FID);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_msAPI_SI_Dmx_CloseFilter_CallmsAPI_DMX_CloseFilter);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_CloseFilter */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_CopyData */
/* CPPTEST_TEST_CASE_CONTEXT SI_DMX_FILTER_STATUS msAPI_SI_Dmx_CopyData(U8, U8 *, U32, U32 *, U32 *) */
extern BOOLEAN gbTest_msAPI_SI_Dmx_CopyData_CallmsAPI_DMX_CopyData;
extern BOOLEAN gbTest_msAPI_SI_Dmx_CopyData_CallmsAPI_SI_Dmx_Filter_Status;
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_CopyData()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8DmxId) */ 
    U8 _u8DmxId  = 0;
    /* Initializing argument 2 (pu8Buf) */ 
    U8 * _pu8Buf  = 0 ;
    /* Initializing argument 3 (u32BufSize) */ 
    U32 _u32BufSize  = 0ul;
    /* Initializing argument 4 (pu32ActualSize) */ 
    U32 * _pu32ActualSize  = 0 ;
    /* Initializing argument 5 (pu32RmnSize) */ 
    U32 * _pu32RmnSize  = 0 ;
    {
        /* Tested function call */
        SI_DMX_FILTER_STATUS _return  = msAPI_SI_Dmx_CopyData(_u8DmxId, _pu8Buf, _u32BufSize, _pu32ActualSize, _pu32RmnSize);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( SI_DMX_FILTER_STATUS_OK, ( _return ) );
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( gbTest_msAPI_SI_Dmx_CopyData_CallmsAPI_DMX_CopyData ));
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( gbTest_msAPI_SI_Dmx_CopyData_CallmsAPI_SI_Dmx_Filter_Status ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_CopyData */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Filter_Cb_Status */
/* CPPTEST_TEST_CASE_CONTEXT SI_DMX_FILTER_CB_STATUS msAPI_SI_Dmx_Filter_Cb_Status(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Cb_Status_case_MSAPI_DMX_FILTER_STATUS_SECAVAILABLE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8Event) */ 
    U32 _u8Event  = MSAPI_DMX_FILTER_STATUS_SECAVAILABLE;
    {
        /* Tested function call */
        SI_DMX_FILTER_CB_STATUS _return  = msAPI_SI_Dmx_Filter_Cb_Status(_u8Event);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( SI_DMX_FILTER_CB_STATUS_SECAVAILABLE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Filter_Cb_Status */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Filter_Cb_Status */
/* CPPTEST_TEST_CASE_CONTEXT SI_DMX_FILTER_CB_STATUS msAPI_SI_Dmx_Filter_Cb_Status(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Cb_Status_case_MSAPI_DMX_FILTER_STATUS_OVERFLOW()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8Event) */ 
    U32 _u8Event  = MSAPI_DMX_FILTER_STATUS_OVERFLOW;
    {
        /* Tested function call */
        SI_DMX_FILTER_CB_STATUS _return  = msAPI_SI_Dmx_Filter_Cb_Status(_u8Event);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( SI_DMX_FILTER_CB_STATUS_OVERFLOW, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Filter_Cb_Status */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Filter_Cb_Status */
/* CPPTEST_TEST_CASE_CONTEXT SI_DMX_FILTER_CB_STATUS msAPI_SI_Dmx_Filter_Cb_Status(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Cb_Status_case_MSAPI_DMX_FILTER_STATUS_OK()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8Event) */ 
    U32 _u8Event  = MSAPI_DMX_FILTER_STATUS_OK;
    {
        /* Tested function call */
        SI_DMX_FILTER_CB_STATUS _return  = msAPI_SI_Dmx_Filter_Cb_Status(_u8Event);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( SI_DMX_FILTER_CB_STATUS_OK, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Filter_Cb_Status */


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Filter_Cb_Status */
/* CPPTEST_TEST_CASE_CONTEXT SI_DMX_FILTER_CB_STATUS msAPI_SI_Dmx_Filter_Cb_Status(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Cb_Status_case_MSAPI_DMX_FILTER_STATUS_TIMEOUT()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8Event) */ 
    U32 _u8Event  = MSAPI_DMX_FILTER_STATUS_TIMEOUT;
    {
        /* Tested function call */
        SI_DMX_FILTER_CB_STATUS _return  = msAPI_SI_Dmx_Filter_Cb_Status(_u8Event);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( SI_DMX_FILTER_CB_STATUS_TIMEOUT, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Filter_Cb_Status */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Filter_Cb_Status */
/* CPPTEST_TEST_CASE_CONTEXT SI_DMX_FILTER_CB_STATUS msAPI_SI_Dmx_Filter_Cb_Status(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Cb_Status_case_MSAPI_DMX_FILTER_STATUS_CRCINCORRECT()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8Event) */ 
    U32 _u8Event  = MSAPI_DMX_FILTER_STATUS_CRCINCORRECT;
    {
        /* Tested function call */
        SI_DMX_FILTER_CB_STATUS _return  = msAPI_SI_Dmx_Filter_Cb_Status(_u8Event);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( SI_DMX_FILTER_CB_STATUS_CRCINCORRECT, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Filter_Cb_Status */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Filter_Cb_Status */
/* CPPTEST_TEST_CASE_CONTEXT SI_DMX_FILTER_CB_STATUS msAPI_SI_Dmx_Filter_Cb_Status(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Cb_Status_case_MSAPI_DMX_FILTER_STATUS_REQUESTMEET()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8Event) */ 
    U32 _u8Event  = MSAPI_DMX_FILTER_STATUS_REQUESTMEET;
    {
        /* Tested function call */
        SI_DMX_FILTER_CB_STATUS _return  = msAPI_SI_Dmx_Filter_Cb_Status(_u8Event);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( SI_DMX_FILTER_CB_STATUS_REQUESTMEET, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Filter_Cb_Status */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Filter_Cb_Status */
/* CPPTEST_TEST_CASE_CONTEXT SI_DMX_FILTER_CB_STATUS msAPI_SI_Dmx_Filter_Cb_Status(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Cb_Status_case_MSAPI_DMX_FILTER_STATUS_COPYSECERR()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8Event) */ 
    U32 _u8Event  = MSAPI_DMX_FILTER_STATUS_COPYSECERR;
    {
        /* Tested function call */
        SI_DMX_FILTER_CB_STATUS _return  = msAPI_SI_Dmx_Filter_Cb_Status(_u8Event);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( SI_DMX_FILTER_CB_STATUS_COPYSECERR, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Filter_Cb_Status */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Filter_Cb_Status */
/* CPPTEST_TEST_CASE_CONTEXT SI_DMX_FILTER_CB_STATUS msAPI_SI_Dmx_Filter_Cb_Status(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Cb_Status_case_MSAPI_DMX_FILTER_STATUS_ERROR()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8Event) */ 
    U32 _u8Event  = MSAPI_DMX_FILTER_STATUS_ERROR;
    {
        /* Tested function call */
        SI_DMX_FILTER_CB_STATUS _return  = msAPI_SI_Dmx_Filter_Cb_Status(_u8Event);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( SI_DMX_FILTER_CB_STATUS_ERROR, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Filter_Cb_Status */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Filter_Status */
/* CPPTEST_TEST_CASE_CONTEXT SI_DMX_FILTER_STATUS msAPI_SI_Dmx_Filter_Status(DMX_FILTER_STATUS) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Status_case_DMX_FILTER_STATUS_OK()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eStatus) */ 
    DMX_FILTER_STATUS _eStatus  = DMX_FILTER_STATUS_OK;
    {
        /* Tested function call */
        SI_DMX_FILTER_STATUS _return  = msAPI_SI_Dmx_Filter_Status(_eStatus);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( SI_DMX_FILTER_STATUS_OK, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Filter_Status */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Filter_Status */
/* CPPTEST_TEST_CASE_CONTEXT SI_DMX_FILTER_STATUS msAPI_SI_Dmx_Filter_Status(DMX_FILTER_STATUS) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Status_case_DMX_FILTER_STATUS_ERROR()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eStatus) */ 
    DMX_FILTER_STATUS _eStatus  = DMX_FILTER_STATUS_ERROR;
    {
        /* Tested function call */
        SI_DMX_FILTER_STATUS _return  = msAPI_SI_Dmx_Filter_Status(_eStatus);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( SI_DMX_FILTER_STATUS_ERROR, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Filter_Status */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Filter_Status */
/* CPPTEST_TEST_CASE_CONTEXT SI_DMX_FILTER_STATUS msAPI_SI_Dmx_Filter_Status(DMX_FILTER_STATUS) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Filter_Status_case_2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eStatus) */ 
    DMX_FILTER_STATUS _eStatus  = 2;
    {
        /* Tested function call */
        SI_DMX_FILTER_STATUS _return  = msAPI_SI_Dmx_Filter_Status(_eStatus);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( SI_DMX_FILTER_STATUS_ERROR, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Filter_Status */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_FilterType */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_FilterType(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_VIDEO()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FilterType) */ 
    U32 _u32FilterType  = SI_DMX_FILTER_TYPE_VIDEO;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_FilterType(_u32FilterType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MSAPI_DMX_FILTER_TYPE_VIDEO, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_FilterType */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_FilterType */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_FilterType(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_AUDIO()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FilterType) */ 
    U32 _u32FilterType  = SI_DMX_FILTER_TYPE_AUDIO;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_FilterType(_u32FilterType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MSAPI_DMX_FILTER_TYPE_AUDIO, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_FilterType */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_FilterType */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_FilterType(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_AUDIO2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FilterType) */ 
    U32 _u32FilterType  = SI_DMX_FILTER_TYPE_AUDIO2;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_FilterType(_u32FilterType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MSAPI_DMX_FILTER_TYPE_AUDIO2, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_FilterType */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_FilterType */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_FilterType(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_SUBTITLE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FilterType) */ 
    U32 _u32FilterType  = SI_DMX_FILTER_TYPE_SUBTITLE;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_FilterType(_u32FilterType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MSAPI_DMX_FILTER_TYPE_SUBTITLE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_FilterType */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_FilterType */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_FilterType(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_TELETEXT()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FilterType) */ 
    U32 _u32FilterType  = SI_DMX_FILTER_TYPE_TELETEXT;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_FilterType(_u32FilterType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MSAPI_DMX_FILTER_TYPE_TELETEXT, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_FilterType */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_FilterType */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_FilterType(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_PES()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FilterType) */ 
    U32 _u32FilterType  = SI_DMX_FILTER_TYPE_PES;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_FilterType(_u32FilterType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MSAPI_DMX_FILTER_TYPE_PES, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_FilterType */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_FilterType */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_FilterType(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_SECTION_1K()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FilterType) */ 
    U32 _u32FilterType  = SI_DMX_FILTER_TYPE_SECTION_1K;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_FilterType(_u32FilterType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MSAPI_DMX_FILTER_TYPE_SECTION_1K, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_FilterType */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_FilterType */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_FilterType(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_SECTION_4K()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FilterType) */ 
    U32 _u32FilterType  = SI_DMX_FILTER_TYPE_SECTION_4K;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_FilterType(_u32FilterType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MSAPI_DMX_FILTER_TYPE_SECTION_4K, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_FilterType */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_FilterType_0 */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_FilterType(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_SECTION_VERSION()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FilterType) */ 
    U32 _u32FilterType  = SI_DMX_FILTER_TYPE_SECTION_VERSION;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_FilterType(_u32FilterType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MSAPI_DMX_FILTER_TYPE_SECTION_VERSION, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_FilterType_0 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_FilterType */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_FilterType(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_SECTION_CRC()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FilterType) */ 
    U32 _u32FilterType  = SI_DMX_FILTER_TYPE_SECTION_CRC;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_FilterType(_u32FilterType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MSAPI_DMX_FILTER_TYPE_SECTION_CRC, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_FilterType */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_FilterType */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_FilterType(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_PCR()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FilterType) */ 
    U32 _u32FilterType  = SI_DMX_FILTER_TYPE_PCR;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_FilterType(_u32FilterType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MSAPI_DMX_FILTER_TYPE_PCR, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_FilterType */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_FilterType */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_FilterType(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_PACKET()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FilterType) */ 
    U32 _u32FilterType  = SI_DMX_FILTER_TYPE_PACKET;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_FilterType(_u32FilterType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MSAPI_DMX_FILTER_TYPE_PACKET, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_FilterType */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_FilterType */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_FilterType(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_PACKET_PUSI()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FilterType) */ 
    U32 _u32FilterType  = SI_DMX_FILTER_TYPE_PACKET_PUSI;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_FilterType(_u32FilterType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MSAPI_DMX_FILTER_TYPE_PACKET_PUSI, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_FilterType */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_FilterType */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_FilterType(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_PACKET_AF()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FilterType) */ 
    U32 _u32FilterType  = SI_DMX_FILTER_TYPE_PACKET_AF;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_FilterType(_u32FilterType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MSAPI_DMX_FILTER_TYPE_PACKET_AF, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_FilterType */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_FilterType */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_FilterType(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_OAD_MONITOR()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FilterType) */ 
    U32 _u32FilterType  = SI_DMX_FILTER_TYPE_OAD_MONITOR;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_FilterType(_u32FilterType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MSAPI_DMX_FILTER_TYPE_OAD_MONITOR, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_FilterType */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_FilterType */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_FilterType(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_OAD_DOWNLOAD()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FilterType) */ 
    U32 _u32FilterType  = SI_DMX_FILTER_TYPE_OAD_DOWNLOAD;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_FilterType(_u32FilterType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MSAPI_DMX_FILTER_TYPE_OAD_DOWNLOAD, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_FilterType */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_FilterType */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_FilterType(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_RECORD()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FilterType) */ 
    U32 _u32FilterType  = SI_DMX_FILTER_TYPE_RECORD;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_FilterType(_u32FilterType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MSAPI_DMX_FILTER_TYPE_RECORD, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_FilterType */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_FilterType */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_FilterType(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_SECTION_EIT()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FilterType) */ 
    U32 _u32FilterType  = SI_DMX_FILTER_TYPE_SECTION_EIT;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_FilterType(_u32FilterType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MSAPI_DMX_FILTER_TYPE_SECTION_EIT, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_FilterType */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_FilterType */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_FilterType(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_TYPE_CSA_PACKET()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FilterType) */ 
    U32 _u32FilterType  = SI_DMX_FILTER_TYPE_CSA_PACKET;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_FilterType(_u32FilterType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MSAPI_DMX_FILTER_TYPE_CSA_PACKET, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_FilterType */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_FilterType */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_FilterType(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_SOURCE_TYPE_MASK()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FilterType) */ 
    U32 _u32FilterType  = SI_DMX_FILTER_SOURCE_TYPE_MASK;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_FilterType(_u32FilterType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MSAPI_DMX_FILTER_SOURCE_TYPE_MASK, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_FilterType */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_FilterType */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_FilterType(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_SOURCE_TYPE_LIVE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FilterType) */ 
    U32 _u32FilterType  = SI_DMX_FILTER_SOURCE_TYPE_LIVE;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_FilterType(_u32FilterType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MSAPI_DMX_FILTER_SOURCE_TYPE_LIVE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_FilterType */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_FilterType */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_FilterType(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_SI_DMX_FILTER_SOURCE_TYPE_FILE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FilterType) */ 
    U32 _u32FilterType  = SI_DMX_FILTER_SOURCE_TYPE_FILE;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_FilterType(_u32FilterType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( MSAPI_DMX_FILTER_SOURCE_TYPE_FILE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_FilterType */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_FilterType */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_FilterType(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_FilterType_case_100()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FilterType) */ 
    U32 _u32FilterType  = 100ul;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_FilterType(_u32FilterType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( SI_DMX_FILTER_SOURCE_TYPE_ERROR, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_FilterType */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_SecMode */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_SecMode(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_SecMode_case_SI_DMX_SECT_MODE_CONTI()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32SecMode) */ 
    U32 _u32SecMode  = SI_DMX_SECT_MODE_CONTI;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_SecMode(_u32SecMode);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( DMX_SECT_MODE_CONTI, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_SecMode */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_SecMode */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_SecMode(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_SecMode_case_SI_DMX_SECT_MODE_ONESHOT()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32SecMode) */ 
    U32 _u32SecMode  = SI_DMX_SECT_MODE_ONESHOT;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_SecMode(_u32SecMode);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( DMX_SECT_MODE_CONTI, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_SecMode */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_SecMode */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_SecMode(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_SecMode_case_SI_DMX_SECT_MODE_CRCCHK()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32SecMode) */ 
    U32 _u32SecMode  = SI_DMX_SECT_MODE_CRCCHK;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_SecMode(_u32SecMode);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( DMX_SECT_MODE_CRCCHK, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_SecMode */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_SecMode */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_SecMode(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_SecMode_case_SI_DMX_SECT_MODE_AUTO_ADDR()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32SecMode) */ 
    U32 _u32SecMode  = SI_DMX_SECT_MODE_AUTO_ADDR;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_SecMode(_u32SecMode);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( DMX_SECT_MODE_AUTO_ADDR, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_SecMode */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Get_SecMode */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_SI_Dmx_Get_SecMode(U32) */
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Get_SecMode_case_100()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32SecMode) */ 
    U32 _u32SecMode  = 100ul;
    {
        /* Tested function call */
        U32 _return  = msAPI_SI_Dmx_Get_SecMode(_u32SecMode);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( DMX_SECT_MODE_ONESHOT, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Get_SecMode */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Pid */
/* CPPTEST_TEST_CASE_CONTEXT SI_DMX_FILTER_STATUS msAPI_SI_Dmx_Pid(U8, U16 *, BOOLEAN) */
extern BOOLEAN gbTest_msAPI_SI_Dmx_Pid_CallmsAPI_DMX_Pid;
extern BOOLEAN gbTest_msAPI_SI_Dmx_Pid_CallmsAPI_SI_Dmx_Filter_Status;
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Pid()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FltID) */ 
    U8 _u8FltID  = 0;
    /* Initializing argument 2 (pu16Pid) */ 
    U16 * _pu16Pid  = 0 ;
    /* Initializing argument 3 (bSet) */ 
    U8 _bSet  = 0;
    {
        /* Tested function call */
        SI_DMX_FILTER_STATUS _return  = msAPI_SI_Dmx_Pid(_u8FltID, _pu16Pid, _bSet);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( SI_DMX_FILTER_STATUS_OK, ( _return ) );
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE,	gbTest_msAPI_SI_Dmx_Pid_CallmsAPI_DMX_Pid);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE,	gbTest_msAPI_SI_Dmx_Pid_CallmsAPI_SI_Dmx_Filter_Status);
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Pid */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Proc */
/* CPPTEST_TEST_CASE_CONTEXT SI_DMX_FILTER_STATUS msAPI_SI_Dmx_Proc(U8) */
extern BOOLEAN gbTest_msAPI_SI_Dmx_Proc_CallmsAPI_DMX_Proc;
extern BOOLEAN gbTest_msAPI_SI_Dmx_Proc_CallmsAPI_SI_Dmx_Filter_Status;
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Proc()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8DmxId) */ 
    U8 _u8DmxId  = 0;
    {
        /* Tested function call */
        SI_DMX_FILTER_STATUS _return  = msAPI_SI_Dmx_Proc(_u8DmxId);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( SI_DMX_FILTER_STATUS_OK, ( _return ) );
        CPPTEST_ASSERT_EQUAL( TRUE, gbTest_msAPI_SI_Dmx_Proc_CallmsAPI_DMX_Proc );
        CPPTEST_ASSERT_EQUAL( TRUE, gbTest_msAPI_SI_Dmx_Proc_CallmsAPI_SI_Dmx_Filter_Status );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Proc */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Reset */
/* CPPTEST_TEST_CASE_CONTEXT SI_DMX_FILTER_STATUS msAPI_SI_Dmx_Reset(U8) */
extern BOOLEAN gbTest_msAPI_SI_Dmx_Reset_CallmsAPI_DMX_Reset;
extern BOOLEAN gbTest_msAPI_SI_Dmx_Reset_CallmsAPI_SI_Dmx_Filter_Status;
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Reset()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FltID) */ 
    U8 _u8FltID  = 0;
    {
        /* Tested function call */
        SI_DMX_FILTER_STATUS _return  = msAPI_SI_Dmx_Reset(_u8FltID);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( SI_DMX_FILTER_STATUS_OK, ( _return ) );
        CPPTEST_ASSERT_EQUAL( TRUE, gbTest_msAPI_SI_Dmx_Reset_CallmsAPI_DMX_Reset );
        CPPTEST_ASSERT_EQUAL( TRUE, gbTest_msAPI_SI_Dmx_Reset_CallmsAPI_SI_Dmx_Filter_Status );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Reset */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_RestartFilter */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_SI_Dmx_RestartFilter(U8) */
extern BOOLEAN gbTest_msAPI_SI_Dmx_RestartFilter_CallmsAPI_DMX_RestartFilter;
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_RestartFilter()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FID) */ 
    U8 _u8FID  = 0;
    {
        /* Tested function call */
        msAPI_SI_Dmx_RestartFilter(_u8FID);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_msAPI_SI_Dmx_RestartFilter_CallmsAPI_DMX_RestartFilter);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_RestartFilter */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_SectionGet */
/* CPPTEST_TEST_CASE_CONTEXT SI_DMX_FILTER_STATUS msAPI_SI_Dmx_SectionGet(SI_DMX_SECTIONGET_PARA *) */
extern BOOLEAN gbTest_msAPI_SI_Dmx_SectionGet_CallmsAPI_DMX_SectionGet;
extern BOOLEAN gbTest_msAPI_SI_Dmx_SectionGet_CallmsAPI_SI_Dmx_Filter_Status;
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_SectionGet()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstSectionGet) */ 
	SI_DMX_SECTIONGET_PARA pstSectionGet;
	memset(&pstSectionGet, 0, sizeof(SI_DMX_SECTIONGET_PARA));
    SI_DMX_SECTIONGET_PARA * _pstSectionGet  = &pstSectionGet ;
    {
        /* Tested function call */
        SI_DMX_FILTER_STATUS _return  = msAPI_SI_Dmx_SectionGet(_pstSectionGet);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( SI_DMX_FILTER_STATUS_OK, ( _return ) );
        CPPTEST_ASSERT_EQUAL(TRUE, gbTest_msAPI_SI_Dmx_SectionGet_CallmsAPI_DMX_SectionGet);
        CPPTEST_ASSERT_EQUAL(TRUE, gbTest_msAPI_SI_Dmx_SectionGet_CallmsAPI_SI_Dmx_Filter_Status);
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_SectionGet */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_SectionMonitor */
/* CPPTEST_TEST_CASE_CONTEXT SI_DMX_FILTER_STATUS msAPI_SI_Dmx_SectionMonitor(SI_DMX_SECTIONMONITOR_PARA *, BOOLEAN) */
extern BOOLEAN gbTest_msAPI_SI_Dmx_SectionMonitor_CallmsAPI_DMX_SectionMonitor;
extern BOOLEAN gbTest_msAPI_SI_Dmx_SectionMonitor_CallmsAPI_SI_Dmx_Filter_Status;
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_SectionMonitor()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstSectionMonitor) */ 
	MS_DMX_SECTIONMONITOR_PARA pstSectionMonitor;
	memset(&pstSectionMonitor, 0, sizeof(MS_DMX_SECTIONMONITOR_PARA));
    SI_DMX_SECTIONMONITOR_PARA * _pstSectionMonitor  = &pstSectionMonitor ;
    /* Initializing argument 2 (bFileIn) */ 
    U8 _bFileIn  = 0;
    {
        /* Tested function call */
        SI_DMX_FILTER_STATUS _return  = msAPI_SI_Dmx_SectionMonitor(_pstSectionMonitor, _bFileIn);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( SI_DMX_FILTER_STATUS_OK, ( _return ) );
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_msAPI_SI_Dmx_SectionMonitor_CallmsAPI_DMX_SectionMonitor);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_msAPI_SI_Dmx_SectionMonitor_CallmsAPI_SI_Dmx_Filter_Status);
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_SectionMonitor */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Start */
/* CPPTEST_TEST_CASE_CONTEXT SI_DMX_FILTER_STATUS msAPI_SI_Dmx_Start(U8) */
extern BOOLEAN gbTest_msAPI_SI_Dmx_Start_CallmsAPI_DMX_Start;
extern BOOLEAN gbTest_msAPI_SI_Dmx_Start_CallmsAPI_SI_Dmx_Filter_Status;
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Start()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FltID) */ 
    U8 _u8FltID  = 0;
    {
        /* Tested function call */
        SI_DMX_FILTER_STATUS _return  = msAPI_SI_Dmx_Start(_u8FltID);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( SI_DMX_FILTER_STATUS_OK, ( _return ) );
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_msAPI_SI_Dmx_Start_CallmsAPI_DMX_Start);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_msAPI_SI_Dmx_Start_CallmsAPI_SI_Dmx_Filter_Status);
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Start */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_SI_Dmx_Stop */
/* CPPTEST_TEST_CASE_CONTEXT SI_DMX_FILTER_STATUS msAPI_SI_Dmx_Stop(U8) */
extern BOOLEAN gbTest_msAPI_SI_Dmx_Stop_CallmsAPI_DMX_Stop;
extern BOOLEAN gbTest_msAPI_SI_Dmx_Stop_CallmsAPI_SI_Dmx_Filter_Status;
void TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Stop()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FltID) */ 
    U8 _u8FltID  = 0;
    {
        /* Tested function call */
        SI_DMX_FILTER_STATUS _return  = msAPI_SI_Dmx_Stop(_u8FltID);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( SI_DMX_FILTER_STATUS_OK, ( _return ) );
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_msAPI_SI_Dmx_Stop_CallmsAPI_DMX_Stop);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_msAPI_SI_Dmx_Stop_CallmsAPI_SI_Dmx_Filter_Status);
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_SI_Dmx_Stop */
