#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/msAPI_DataStreamIO.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/msAPI_DataStreamIO.c");

CPPTEST_TEST_SUITE(TestSuit_msAPI_DataStreamIO);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Open_Logic0);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Open_Logic1);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Open_Logic2);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Open_Logic3);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Close_Logic0);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Close_Logic1);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Close_Logic2);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Read_Logic0);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Read_Logic1);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Read_Logic2);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Seek_Logic0_case_E_DATA_STREAM_SEEK_SET);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Seek_Logic1_case_E_DATA_STREAM_SEEK_CUR);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Seek_Logic3);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Seek_LongLong_Logic0_E_DATA_STREAM_SEEK_SET);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Seek_LongLong_case_E_DATA_STREAM_SEEK_CUR);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Seek_LongLong_Logic2);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Tell_Logic0);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Tell_Logic1);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Tell_Logic2);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Tell_LongLong_Logic0);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Tell_LongLong_Logic1);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Tell_LongLong_Logic2);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Length_Logic0);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Length_Logic1);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Length_Logic2);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Length_LongLong_Logic0);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Length_LongLong_Logic1);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Length_LongLong_Logic2);
CPPTEST_TEST(TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_OptionRegistation_Logic0);
CPPTEST_TEST_SUITE_END();
        

void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Open_Logic0();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Open_Logic1();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Open_Logic2();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Open_Logic3();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Close_Logic0();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Close_Logic1();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Close_Logic2();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Read_Logic0();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Read_Logic1();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Read_Logic2();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Seek_Logic0_case_E_DATA_STREAM_SEEK_SET();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Seek_Logic1_case_E_DATA_STREAM_SEEK_CUR();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Seek_Logic3();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Seek_LongLong_Logic0_E_DATA_STREAM_SEEK_SET();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Seek_LongLong_case_E_DATA_STREAM_SEEK_CUR();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Seek_LongLong_Logic2();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Tell_Logic0();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Tell_Logic1();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Tell_Logic2();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Tell_LongLong_Logic0();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Tell_LongLong_Logic1();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Tell_LongLong_Logic2();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Length_Logic0();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Length_Logic1();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Length_Logic2();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Length_LongLong_Logic0();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Length_LongLong_Logic1();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Length_LongLong_Logic2();
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_OptionRegistation_Logic0();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuit_msAPI_DataStreamIO);

BOOLEAN TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_pfnInit(void)
{
    return TRUE;
}

BOOLEAN TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_pfnFinalize(void)
{
    return TRUE;
}

void TestSuit_msAPI_DataStreamIO_setUp()
{
}

void TestSuit_msAPI_DataStreamIO_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Open_Logic0 */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_DataStreamIO_Open(void *, U8, E_DATA_STREAM_TYPE) */
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Open_Logic0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pPrivate) */ 
    void * _pPrivate  = 0 ;
    /* Initializing argument 2 (u8Mode) */ 
    U8 _u8Mode  = 0;
    /* Initializing argument 3 (eType) */ 
    E_DATA_STREAM_TYPE _eType  = E_DATA_STREAM_TYPE_NUM;
    /* Initializing global variable _gpStreamIOFunc */ 
    {
         msAPI_DataStreamIO_OptionRegistation(NULL, E_DATA_STREAM_MODE_BASIC);
    }
    {
        /* Tested function call */
        U32 _return  = msAPI_DataStreamIO_Open(_pPrivate, _u8Mode, _eType);
        CPPTEST_ASSERT_EQUAL(FALSE,_return);
        /* Post-condition check */
        // CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
        // CPPTEST_POST_CONDITION_PTR("void * _pPrivate ", ( _pPrivate ));
        // CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Open_Logic0 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Open_Logic1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_DataStreamIO_Open(void *, U8, E_DATA_STREAM_TYPE) */
extern BOOLEAN bTest_msAPI_DataStreamIO_Open_CallmsAPI_FCtrl_FileOpen;
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Open_Logic1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pPrivate) */ 
    void * _pPrivate  = NULL ;
    /* Initializing argument 2 (u8Mode) */ 
    U8 _u8Mode  = 0;
    /* Initializing argument 3 (eType) */ 
    E_DATA_STREAM_TYPE _eType  = E_DATA_STREAM_TYPE_IGNORE;
    /* Initializing global variable _gpStreamIOFunc */ 
    {
        msAPI_DataStreamIO_OptionRegistation(NULL, E_DATA_STREAM_MODE_BASIC);
    }
    {
        /* Tested function call */
        U32 _return  = msAPI_DataStreamIO_Open(_pPrivate, _u8Mode, _eType);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, bTest_msAPI_DataStreamIO_Open_CallmsAPI_FCtrl_FileOpen);
        CPPTEST_ASSERT_EQUAL(0, _return);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("void * _pPrivate ", ( _pPrivate ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Open_Logic1 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Open_Logic2 */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_DataStreamIO_Open(void *, U8, E_DATA_STREAM_TYPE) */

U32 TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Open_Logic2_TestOnly(void *pPrivate, U8 u8Mode, E_DATA_STREAM_TYPE eType)
{
    U32 u32Hdl = INVALID_DATA_STREAM_HDL;

    return 1;
}
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Open_Logic2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pPrivate) */ 
    void * _pPrivate  = 0 ;
    U32 _u32Hdl  = 0;//STREAMIO_FILEHANDLE_BASE;
    /* Initializing argument 2 (u8Mode) */ 
    U8 _u8Mode  = 0;
    /* Initializing argument 3 (eType) */ 
    E_DATA_STREAM_TYPE _eType  = E_DATA_STREAM_TYPE_IGNORE;
    
    /* Initializing global variable _gpStreamIOFunc */ 
    {
        msAPI_DataStreamIO_OptionRegistation(NULL, E_DATA_STREAM_MODE_BASIC);
    }
    {
        /* Tested function call */
        U32 _return  = msAPI_DataStreamIO_Open(_pPrivate, _u8Mode, _eType);
        CPPTEST_ASSERT_EQUAL(1, _return);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("void * _pPrivate ", ( _pPrivate ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Open_Logic2 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Open_Logic3 */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_DataStreamIO_Open(void *, U8, E_DATA_STREAM_TYPE) */

void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Open_Logic3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pPrivate) */ 
    void * _pPrivate  = 0 ;
    /* Initializing argument 2 (u8Mode) */ 
    U8 _u8Mode  = 0;
    /* Initializing argument 3 (eType) */ 
    E_DATA_STREAM_TYPE _eType  = E_DATA_STREAM_TYPE_IGNORE;
    /* Initializing global variable _gpStreamIOFunc */ 
    {
    	msAPI_DataStreamIO_OptionRegistation(NULL, E_DATA_STREAM_MODE_BASIC);
    }
    {
        /* Tested function call */
        U32 _return  = msAPI_DataStreamIO_Open(_pPrivate, _u8Mode, _eType);
        CPPTEST_ASSERT_EQUAL(INVALID_DATA_STREAM_HDL, _return);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("void * _pPrivate ", ( _pPrivate ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Open_Logic3 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Close_Logic0 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_DataStreamIO_Close(U32) */
extern BOOLEAN bTest_msAPI_DataStreamIO_Close_CallmsAPI_FCtrl_FileClose;
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Close_Logic0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = INVALID_FILE_HANDLE;
    /* Initializing global variable _gpStreamIOFunc */ 
    {
        msAPI_DataStreamIO_OptionRegistation(NULL, E_DATA_STREAM_MODE_BASIC);
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_DataStreamIO_Close(_u32Hdl);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, bTest_msAPI_DataStreamIO_Close_CallmsAPI_FCtrl_FileClose);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Close_Logic0 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Close_Logic1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_DataStreamIO_Close(U32) */
BOOLEAN TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Close_Logic1_TestOnly(U32 u32Hdl)
{
    return TRUE;
}
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Close_Logic1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = 0 ;//STREAMIO_FILEHANDLE_BASE;
    FN_DATA_STRM_IO gpStreamIOFunc;
    gpStreamIOFunc.pfnInit = TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_pfnInit;
    gpStreamIOFunc.pfnFinalize = TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_pfnFinalize;
    gpStreamIOFunc.pfnClose = TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Close_Logic1_TestOnly;
    /* Initializing global variable _gpStreamIOFunc */ 
    {
        msAPI_DataStreamIO_OptionRegistation(&gpStreamIOFunc, E_DATA_STREAM_MODE_BASIC);
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_DataStreamIO_Close(_u32Hdl);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, _return);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Close_Logic1 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Close_Logic2 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_DataStreamIO_Close(U32) */
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Close_Logic2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = 0ul;
    
    /* Initializing global variable _gpStreamIOFunc */ 
    {
        msAPI_DataStreamIO_OptionRegistation(NULL, E_DATA_STREAM_MODE_BASIC);
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_DataStreamIO_Close(_u32Hdl);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Close_Logic2 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Read_Logic0 */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_DataStreamIO_Read(U32, void *, U32) */
extern BOOLEAN bTest_msAPI_DataStreamIO_Read_CallmsAPI_FCtrl_FileRead;
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Read_Logic0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = 0ul;
    /* Initializing argument 2 (pBuffAddr) */ 
    void * _pBuffAddr  = 0 ;
    /* Initializing argument 3 (u32Length) */ 
    U32 _u32Length  = 0ul;
    /* Initializing global variable _gpStreamIOFunc */ 
    {
        msAPI_DataStreamIO_OptionRegistation(NULL, E_DATA_STREAM_MODE_BASIC);
    }
    {
        /* Tested function call */
        U32 _return  = msAPI_DataStreamIO_Read(_u32Hdl, _pBuffAddr, _u32Length);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, bTest_msAPI_DataStreamIO_Read_CallmsAPI_FCtrl_FileRead);
        CPPTEST_ASSERT_EQUAL(0, _return);
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("void * _pBuffAddr ", ( _pBuffAddr ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Read_Logic0 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Read_Logic1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_DataStreamIO_Read(U32, void *, U32) */
U32 TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Read_Logic1_TestOnly(U32 u32Hdl, void *pBuffAddr, U32 u32Length)
{
    return 0;
}
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Read_Logic1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = 0ul;
    /* Initializing argument 2 (pBuffAddr) */ 
    void * _pBuffAddr  = 0 ;
    /* Initializing argument 3 (u32Length) */ 
    U32 _u32Length  = 0ul;
    FN_DATA_STRM_IO gpStreamIOFunc;
    gpStreamIOFunc.pfnInit = TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_pfnInit;
    gpStreamIOFunc.pfnFinalize = TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_pfnFinalize;
    gpStreamIOFunc.pfnRead = TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Read_Logic1_TestOnly;
    /* Initializing global variable _gpStreamIOFunc */ 
    {
        msAPI_DataStreamIO_OptionRegistation(&gpStreamIOFunc, E_DATA_STREAM_MODE_BASIC);
    }
    {
        /* Tested function call */
        U32 _return  = msAPI_DataStreamIO_Read(_u32Hdl, _pBuffAddr, _u32Length);
        CPPTEST_ASSERT_EQUAL(0, _return);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("void * _pBuffAddr ", ( _pBuffAddr ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Read_Logic1 */


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Read_Logic2 */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_DataStreamIO_Read(U32, void *, U32) */
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Read_Logic2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = 0ul;
    /* Initializing argument 2 (pBuffAddr) */ 
    void * _pBuffAddr  = 0 ;
    /* Initializing argument 3 (u32Length) */ 
    U32 _u32Length  = 0ul;
    /* Initializing global variable _gpStreamIOFunc */ 
    {
        msAPI_DataStreamIO_OptionRegistation(NULL, E_DATA_STREAM_MODE_BASIC);
    }
    {
        /* Tested function call */
        U32 _return  = msAPI_DataStreamIO_Read(_u32Hdl, _pBuffAddr, _u32Length);
        CPPTEST_ASSERT_EQUAL(0, _return);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("void * _pBuffAddr ", ( _pBuffAddr ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Read_Logic2 */


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Seek_Logic0_case_E_DATA_STREAM_SEEK_SET */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_DataStreamIO_Seek(U32, U32, E_DATA_STREAM_SEEK_OPTION) */
extern BOOLEAN bTest_msAPI_DataStreamIO_Seek_CallmsAPI_FCtrl_FileSeek;
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Seek_Logic0_case_E_DATA_STREAM_SEEK_SET()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = 0ul;
    /* Initializing argument 2 (u32Pos) */ 
    U32 _u32Pos  = 0ul;
    /* Initializing argument 3 (eOption) */ 
    EN_FILE_SEEK_OPTION eFileSeekOpt;
    E_DATA_STREAM_SEEK_OPTION _eOption  = E_DATA_STREAM_SEEK_SET;
    /* Initializing global variable _gpStreamIOFunc */ 
    {
        msAPI_DataStreamIO_OptionRegistation(NULL, E_DATA_STREAM_MODE_BASIC);
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_DataStreamIO_Seek(_u32Hdl, _u32Pos, _eOption);
        CPPTEST_ASSERT_EQUAL(FILE_SEEK_SET, eFileSeekOpt);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, bTest_msAPI_DataStreamIO_Seek_CallmsAPI_FCtrl_FileSeek);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Seek_Logic0_case_E_DATA_STREAM_SEEK_SET */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Seek_Logic1_case_E_DATA_STREAM_SEEK_CUR */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_DataStreamIO_Seek(U32, U32, E_DATA_STREAM_SEEK_OPTION) */
U32 TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Seek_Logic1_case_E_DATA_STREAM_SEEK_CUR_TestOnly(U32 u32Hdl, LongLong u64Pos, E_DATA_STREAM_SEEK_OPTION eOption)
{
    return FALSE;
}
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Seek_Logic1_case_E_DATA_STREAM_SEEK_CUR()
{
	/* Pre-condition initialization */
        /* Initializing argument 1 (u32Hdl) */
        U32 _u32Hdl  = 0ul;
        /* Initializing argument 2 (u32Pos) */
        U32 _u32Pos  = 0ul;
        /* Initializing argument 3 (eOption) */
        EN_FILE_SEEK_OPTION eFileSeekOpt;
        E_DATA_STREAM_SEEK_OPTION _eOption = E_DATA_STREAM_SEEK_CUR;
        FN_DATA_STRM_IO gpStreamIOFunc;
        gpStreamIOFunc.pfnInit = TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_pfnInit;
        gpStreamIOFunc.pfnFinalize = TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_pfnFinalize;
        gpStreamIOFunc.pfnSeek = TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Seek_Logic1_case_E_DATA_STREAM_SEEK_CUR_TestOnly;
        /* Initializing global variable _gpStreamIOFunc */
        {
            msAPI_DataStreamIO_OptionRegistation(&gpStreamIOFunc, E_DATA_STREAM_MODE_BASIC);
        }
        {
            /* Tested function call */
            BOOLEAN _return  = msAPI_DataStreamIO_Seek(_u32Hdl, _u32Pos, _eOption);
            //CPPTEST_ASSERT_EQUAL(FILE_SEEK_CUR, eFileSeekOpt);
            CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
            /* Post-condition check */
            //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
            //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
        }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Seek_Logic1_case_E_DATA_STREAM_SEEK_CUR */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Seek_Logic3 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_DataStreamIO_Seek(U32, U32, E_DATA_STREAM_SEEK_OPTION) */
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Seek_Logic3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = 0ul;
    /* Initializing argument 2 (u32Pos) */ 
    U32 _u32Pos  = 0ul;
    /* Initializing argument 3 (eOption) */ 
    E_DATA_STREAM_SEEK_OPTION _eOption  = E_DATA_STREAM_SEEK_SET;
    /* Initializing global variable _gpStreamIOFunc */ 
    {
        msAPI_DataStreamIO_OptionRegistation(NULL, E_DATA_STREAM_MODE_BASIC);
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_DataStreamIO_Seek(_u32Hdl, _u32Pos, _eOption);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Seek_Logic3 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Seek_LongLong_Logic0_E_DATA_STREAM_SEEK_SET */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_DataStreamIO_Seek_LongLong(U32, LongLong, E_DATA_STREAM_SEEK_OPTION) */
extern BOOLEAN msAPI_DataStreamIO_Seek_LongLong_CallmsAPI_FCtrl_FileSeek;
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Seek_LongLong_Logic0_E_DATA_STREAM_SEEK_SET()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = 0ul;
    /* Initializing argument 2 (u64Pos) */ 
    LongLong _u64Pos ;
    /* Initializing argument 3 (eOption) */ 
    EN_FILE_SEEK_OPTION eFileSeekOpt;
    E_DATA_STREAM_SEEK_OPTION _eOption  = E_DATA_STREAM_SEEK_SET;
    /* Initializing global variable _gpStreamIOFunc */ 
    {
        msAPI_DataStreamIO_OptionRegistation(NULL, E_DATA_STREAM_MODE_BASIC);
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_DataStreamIO_Seek_LongLong(_u32Hdl, _u64Pos, _eOption);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FILE_SEEK_SET, eFileSeekOpt);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, msAPI_DataStreamIO_Seek_LongLong_CallmsAPI_FCtrl_FileSeek);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Seek_LongLong_Logic0_E_DATA_STREAM_SEEK_SET */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Seek_LongLong_case_E_DATA_STREAM_SEEK_CUR */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_DataStreamIO_Seek_LongLong(U32, LongLong, E_DATA_STREAM_SEEK_OPTION) */
U32 TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Seek_LongLong_case_E_DATA_STREAM_SEEK_CUR_TestOnly(U32 u32Hdl, LongLong u64Pos, E_DATA_STREAM_SEEK_OPTION eOption)
{
    return FALSE;
}
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Seek_LongLong_case_E_DATA_STREAM_SEEK_CUR()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = 0ul;
    /* Initializing argument 2 (u64Pos) */ 
    LongLong _u64Pos ;
    EN_FILE_SEEK_OPTION eFileSeekOpt;
    E_DATA_STREAM_SEEK_OPTION _eOption = E_DATA_STREAM_SEEK_CUR;
    FN_DATA_STRM_IO gpStreamIOFunc;
    gpStreamIOFunc.pfnInit = TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_pfnInit;
    gpStreamIOFunc.pfnFinalize = TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_pfnFinalize;
    gpStreamIOFunc.pfnSeek = TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Seek_LongLong_case_E_DATA_STREAM_SEEK_CUR_TestOnly;
    /* Initializing global variable _gpStreamIOFunc */
    {
        msAPI_DataStreamIO_OptionRegistation(&gpStreamIOFunc, E_DATA_STREAM_MODE_BASIC);
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_DataStreamIO_Seek_LongLong(_u32Hdl, _u64Pos, _eOption);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Seek_LongLong_case_E_DATA_STREAM_SEEK_CUR */


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Seek_LongLong_Logic2 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_DataStreamIO_Seek_LongLong(U32, LongLong, E_DATA_STREAM_SEEK_OPTION) */
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Seek_LongLong_Logic2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = 0ul;
    /* Initializing argument 2 (u64Pos) */ 
    LongLong _u64Pos ;
    E_DATA_STREAM_SEEK_OPTION _eOption  = E_DATA_STREAM_SEEK_SET;
    /* Initializing global variable _gpStreamIOFunc */ 
    {
    	msAPI_DataStreamIO_OptionRegistation(NULL, E_DATA_STREAM_MODE_BASIC);
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_DataStreamIO_Seek_LongLong(_u32Hdl, _u64Pos, _eOption);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Seek_LongLong_Logic2 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Tell_Logic0 */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_DataStreamIO_Tell(U32) */
extern BOOLEAN msAPI_DataStreamIO_Tell_Logic0_CallmsAPI_FCtrl_FileTell;
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Tell_Logic0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = 0ul;
    /* Initializing global variable _gpStreamIOFunc */ 
    {
    	msAPI_DataStreamIO_OptionRegistation(NULL, E_DATA_STREAM_MODE_BASIC);
    }
    {
        /* Tested function call */
        U32 _return  = msAPI_DataStreamIO_Tell(_u32Hdl);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, msAPI_DataStreamIO_Tell_Logic0_CallmsAPI_FCtrl_FileTell);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Tell_Logic0 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Tell_Logic1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_DataStreamIO_Tell(U32) */

U32 TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Tell_Logic1_TestOnly(U8 u8HandleNo)
{
    return 3;
}
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Tell_Logic1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = 0 ; //STREAMIO_FILEHANDLE_BASE;
    FN_DATA_STRM_IO gpStreamIOFunc;
    gpStreamIOFunc.pfnInit = TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_pfnInit;
    gpStreamIOFunc.pfnFinalize = TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_pfnFinalize;
    gpStreamIOFunc.pfnTell = TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Tell_Logic1_TestOnly;
    /* Initializing global variable _gpStreamIOFunc */
    {
        msAPI_DataStreamIO_OptionRegistation(&gpStreamIOFunc, E_DATA_STREAM_MODE_BASIC);
    }
    {
        /* Tested function call */
        U32 _return  = msAPI_DataStreamIO_Tell(_u32Hdl);
        CPPTEST_ASSERT_EQUAL(3, _return);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Tell_Logic1 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Tell_Logic2 */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_DataStreamIO_Tell(U32) */
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Tell_Logic2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = 0 ; //STREAMIO_FILEHANDLE_BASE;
    /* Initializing global variable _gpStreamIOFunc */ 
    {
        msAPI_DataStreamIO_OptionRegistation(NULL, E_DATA_STREAM_MODE_BASIC);
    }
    {
        /* Tested function call */
        U32 _return  = msAPI_DataStreamIO_Tell(_u32Hdl);
        CPPTEST_ASSERT_EQUAL(0xFFFFFFFF, _return);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Tell_Logic2 */


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Tell_LongLong_Logic0 */
/* CPPTEST_TEST_CASE_CONTEXT LongLong msAPI_DataStreamIO_Tell_LongLong(U32) */
extern BOOLEAN msAPI_DataStreamIO_Tell_LongLong_CallmsAPI_FCtrl_FileTell_LongLong;
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Tell_LongLong_Logic0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = INVALID_FILE_HANDLE;
    /* Initializing global variable _gpStreamIOFunc */ 
    {
        msAPI_DataStreamIO_OptionRegistation(NULL, E_DATA_STREAM_MODE_BASIC);
    }
    {
        /* Tested function call */
        LongLong _return  = msAPI_DataStreamIO_Tell_LongLong(_u32Hdl);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, msAPI_DataStreamIO_Tell_LongLong_CallmsAPI_FCtrl_FileTell_LongLong);
        //CPPTEST_ASSERT_EQUAL(0, _return);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Hi", ( _return.Hi ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Lo", ( _return.Lo ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Tell_LongLong_Logic0 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Tell_LongLong_Logic1 */
/* CPPTEST_TEST_CASE_CONTEXT LongLong msAPI_DataStreamIO_Tell_LongLong(U32) */
LongLong TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Tell_LongLong_Logic1_TestOnly(U8 u8HandleNo)
{
	LongLong u64Obj;
	u64Obj.Hi = 0;
	u64Obj.Lo = 0;
    return u64Obj;
}
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Tell_LongLong_Logic1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = 0ul;
    FN_DATA_STRM_IO gpStreamIOFunc;
    gpStreamIOFunc.pfnInit = TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_pfnInit;
    gpStreamIOFunc.pfnFinalize = TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_pfnFinalize;
    gpStreamIOFunc.pfnTell = TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Tell_LongLong_Logic1_TestOnly;
    /* Initializing global variable _gpStreamIOFunc */ 
    {
        msAPI_DataStreamIO_OptionRegistation(&gpStreamIOFunc, E_DATA_STREAM_MODE_BASIC);
    }
    {
        /* Tested function call */
        LongLong _return  = msAPI_DataStreamIO_Tell_LongLong(_u32Hdl);
        CPPTEST_ASSERT_EQUAL(0, _return.Hi);
        CPPTEST_ASSERT_EQUAL(0, _return.Lo);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Hi", ( _return.Hi ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Lo", ( _return.Lo ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Tell_LongLong_Logic1 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Tell_LongLong_Logic2 */
/* CPPTEST_TEST_CASE_CONTEXT LongLong msAPI_DataStreamIO_Tell_LongLong(U32) */
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Tell_LongLong_Logic2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = 0 ; //STREAMIO_FILEHANDLE_BASE;
    /* Initializing global variable _gpStreamIOFunc */ 
    {
    	msAPI_DataStreamIO_OptionRegistation(NULL, E_DATA_STREAM_MODE_BASIC);
    }
    {
        /* Tested function call */
        LongLong _return  = msAPI_DataStreamIO_Tell_LongLong(_u32Hdl);
        CPPTEST_ASSERT_EQUAL(0xFFFFFFFF, _return.Hi);
        CPPTEST_ASSERT_EQUAL(0xFFFFFFFF, _return.Lo);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Hi", ( _return.Hi ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Lo", ( _return.Lo ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Tell_LongLong_Logic2 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Length_Logic0 */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_DataStreamIO_Length(U32) */
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Length_Logic0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = 0ul;
    /* Initializing global variable _gpStreamIOFunc */ 
    {
        msAPI_DataStreamIO_OptionRegistation(NULL, E_DATA_STREAM_MODE_BASIC);
    }
    {
        /* Tested function call */
        U32 _return  = msAPI_DataStreamIO_Length(_u32Hdl);
        CPPTEST_ASSERT_EQUAL(100, _return);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Length_Logic0 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Length_Logic1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_DataStreamIO_Length(U32) */

LongLong TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Length_Logic1_TestOnly(U32 u32Hdl)
{
	LongLong u64Objtemp;
	u64Objtemp.Hi = 0;
	u64Objtemp.Lo = 0;
    return u64Objtemp;
}

void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Length_Logic1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = 0 ; //STREAMIO_FILEHANDLE_BASE;
    FN_DATA_STRM_IO gpStreamIOFunc;
    gpStreamIOFunc.pfnInit = TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_pfnInit;
    gpStreamIOFunc.pfnFinalize = TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_pfnFinalize;
    gpStreamIOFunc.pfnLength = TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Length_Logic1_TestOnly;
    /* Initializing global variable _gpStreamIOFunc */ 
    {
        msAPI_DataStreamIO_OptionRegistation(&gpStreamIOFunc, E_DATA_STREAM_MODE_BASIC);
    }
    {
        /* Tested function call */
        U32 _return  = msAPI_DataStreamIO_Length(_u32Hdl);
        CPPTEST_ASSERT_EQUAL(0, _return);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Length_Logic1 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Length_Logic2 */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_DataStreamIO_Length(U32) */
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Length_Logic2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = 0 ; //STREAMIO_FILEHANDLE_BASE;
     /* Initializing global variable _gpStreamIOFunc */
     {
         msAPI_DataStreamIO_OptionRegistation(NULL, E_DATA_STREAM_MODE_BASIC);
     }
    {
        /* Tested function call */
        U32 _return  = msAPI_DataStreamIO_Length(_u32Hdl);
        CPPTEST_ASSERT_EQUAL(0, _return);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Length_Logic2 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Length_LongLong_Logic0 */
/* CPPTEST_TEST_CASE_CONTEXT LongLong msAPI_DataStreamIO_Length_LongLong(U32) */
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Length_LongLong_Logic0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = 0ul;
    /* Initializing global variable _gpStreamIOFunc */ 
    {
        msAPI_DataStreamIO_OptionRegistation(NULL, E_DATA_STREAM_MODE_BASIC);
    }
    {
        /* Tested function call */
        LongLong _return  = msAPI_DataStreamIO_Length_LongLong(_u32Hdl);
        CPPTEST_ASSERT_EQUAL(0, _return.Hi);
        CPPTEST_ASSERT_EQUAL(0, _return.Lo);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Hi", ( _return.Hi ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Lo", ( _return.Lo ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Length_LongLong_Logic0 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Length_LongLong_Logic1 */
/* CPPTEST_TEST_CASE_CONTEXT LongLong msAPI_DataStreamIO_Length_LongLong(U32) */
LongLong TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Length_LongLong_Logic1_TestOnly(U32 u32Hdl)
{
	LongLong u64Objtemp1;
	u64Objtemp1.Hi = 0;
	u64Objtemp1.Lo = 0;
    return u64Objtemp1;
}

void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Length_LongLong_Logic1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = 0 ; //STREAMIO_FILEHANDLE_BASE;
    /* Initializing global variable _gpStreamIOFunc */ 
    FN_DATA_STRM_IO gpStreamIOFunc;
    gpStreamIOFunc.pfnInit = TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_pfnInit;
    gpStreamIOFunc.pfnFinalize = TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_pfnFinalize;
    gpStreamIOFunc.pfnLength = TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Length_LongLong_Logic1_TestOnly;
    /* Initializing global variable _gpStreamIOFunc */
    {
        msAPI_DataStreamIO_OptionRegistation(&gpStreamIOFunc, E_DATA_STREAM_MODE_BASIC);
    }
    {
        /* Tested function call */
        LongLong _return  = msAPI_DataStreamIO_Length_LongLong(_u32Hdl);
        CPPTEST_ASSERT_EQUAL(0, _return.Hi);
        CPPTEST_ASSERT_EQUAL(0, _return.Lo);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Hi", ( _return.Hi ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Lo", ( _return.Lo ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Length_LongLong_Logic1 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_Length_LongLong_Logic2 */
/* CPPTEST_TEST_CASE_CONTEXT LongLong msAPI_DataStreamIO_Length_LongLong(U32) */
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Length_LongLong_Logic2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = 0 ; //STREAMIO_FILEHANDLE_BASE;
     /* Initializing global variable _gpStreamIOFunc */
     {
         msAPI_DataStreamIO_OptionRegistation(NULL, E_DATA_STREAM_MODE_BASIC);
     }
    {
        /* Tested function call */
        LongLong _return  = msAPI_DataStreamIO_Length_LongLong(_u32Hdl);
        CPPTEST_ASSERT_EQUAL(0, _return.Hi);
        CPPTEST_ASSERT_EQUAL(0, _return.Lo);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Hi", ( _return.Hi ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Lo", ( _return.Lo ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_Length_LongLong_Logic2 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_OptionRegistation_Logic0 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_DataStreamIO_OptionRegistation(FN_DATA_STRM_IO *) */
void TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_OptionRegistation_Logic0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pfnIO) */ 
    FN_DATA_STRM_IO * _pfnIO  = 0 ;
    U8 _u8Mode  = 0;
    /* Initializing global variable _gpStreamIOFunc */ 
    {
        msAPI_DataStreamIO_OptionRegistation(NULL, E_DATA_STREAM_MODE_BASIC);
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_DataStreamIO_OptionRegistation(_pfnIO,_u8Mode);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, _return);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _pfnIO ", ( _pfnIO ));
        //CPPTEST_POST_CONDITION_PTR("FN_DATA_STRM_IO * _gpStreamIOFunc ", ( _gpStreamIOFunc ));
        //CPPTEST_POST_CONDITION_PTR("U32 (* _gStreamIOFunc.pfnOpen )(void *, U8, E_DATA_STREAM_TYPE)", ( _gStreamIOFunc.pfnOpen ));
        //CPPTEST_POST_CONDITION_PTR("BOOLEAN (* _gStreamIOFunc.pfnClose )(U32)", ( _gStreamIOFunc.pfnClose ));
        //CPPTEST_POST_CONDITION_PTR("U32 (* _gStreamIOFunc.pfnRead )(U32, void *, U32)", ( _gStreamIOFunc.pfnRead ));
        //CPPTEST_POST_CONDITION_PTR("BOOLEAN (* _gStreamIOFunc.pfnSeek )(U32, LongLong, E_DATA_STREAM_SEEK_OPTION)", ( _gStreamIOFunc.pfnSeek ));
        //CPPTEST_POST_CONDITION_PTR("LongLong (* _gStreamIOFunc.pfnTell )(U32)", ( _gStreamIOFunc.pfnTell ));
        //CPPTEST_POST_CONDITION_PTR("LongLong (* _gStreamIOFunc.pfnLength )(U32)", ( _gStreamIOFunc.pfnLength ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_OptionRegistation_Logic0 */
