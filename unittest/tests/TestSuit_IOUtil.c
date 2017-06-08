#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/IOUtil.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/IOUtil.c");

CPPTEST_TEST_SUITE(TestSuit_IOUtil);
CPPTEST_TEST(TestSuit_IOUtil_test_ByteSwapCopy_for);
CPPTEST_TEST(TestSuit_IOUtil_test_ByteCopy);
CPPTEST_TEST(TestSuit_IOUtil_test_ByteComp);
CPPTEST_TEST(TestSuit_IOUtil_test_ByteComp_same);
CPPTEST_TEST(TestSuit_IOUtil_test_msStrcat);
CPPTEST_TEST(TestSuit_IOUtil_test_msStrncpy);
CPPTEST_TEST(TestSuit_IOUtil_test_SplitPath);
CPPTEST_TEST(TestSuit_IOUtil_test_IsFullPath_yes);
CPPTEST_TEST(TestSuit_IOUtil_test_IsFullPath_no);
CPPTEST_TEST(TestSuit_IOUtil_test_UnicodeCmp);
CPPTEST_TEST(TestSuit_IOUtil_test_UnicodeCmp_TRUE);
CPPTEST_TEST(TestSuit_IOUtil_test_UnicodeCat);
CPPTEST_TEST(TestSuit_IOUtil_test_UnicodeLen);
CPPTEST_TEST(TestSuit_IOUtil_test_UnicodeChr);
CPPTEST_TEST(TestSuit_IOUtil_test_UnicodeCpy);
CPPTEST_TEST(TestSuit_IOUtil_test_UnicodeSplitPath);
CPPTEST_TEST(TestSuit_IOUtil_test_UnicodeIsFullPath);
CPPTEST_TEST(TestSuit_IOUtil_test_UnicodeIsFullPath_NO);
CPPTEST_TEST(TestSuit_IOUtil_test_UnicodetoASCII);
CPPTEST_TEST(TestSuit_IOUtil_test_ASCIItoUnicode);
CPPTEST_TEST(TestSuit_IOUtil_test_ASCIItoUnicode2);
CPPTEST_TEST(TestSuit_IOUtil_test_strupr2);
CPPTEST_TEST(TestSuit_IOUtil_test_UnicodeChr_retNULL);
CPPTEST_TEST(TestSuit_IOUtil_test_UnicodeChr_longStr);
CPPTEST_TEST(TestSuit_IOUtil_test_UnicodetoASCII_else);
CPPTEST_TEST(TestSuit_IOUtil_test_SplitPath_while);
CPPTEST_TEST_SUITE_END();
        

void TestSuit_IOUtil_test_ByteSwapCopy_for();
void TestSuit_IOUtil_test_ByteCopy();
void TestSuit_IOUtil_test_ByteComp();
void TestSuit_IOUtil_test_ByteComp_same();
void TestSuit_IOUtil_test_msStrcat();
void TestSuit_IOUtil_test_msStrncpy();
void TestSuit_IOUtil_test_SplitPath();
void TestSuit_IOUtil_test_IsFullPath_yes();
void TestSuit_IOUtil_test_IsFullPath_no();
void TestSuit_IOUtil_test_UnicodeCmp();
void TestSuit_IOUtil_test_UnicodeCmp_TRUE();
void TestSuit_IOUtil_test_UnicodeCat();
void TestSuit_IOUtil_test_UnicodeLen();
void TestSuit_IOUtil_test_UnicodeChr();
void TestSuit_IOUtil_test_UnicodeCpy();
void TestSuit_IOUtil_test_UnicodeSplitPath();
void TestSuit_IOUtil_test_UnicodeIsFullPath();
void TestSuit_IOUtil_test_UnicodeIsFullPath_NO();
void TestSuit_IOUtil_test_UnicodetoASCII();
void TestSuit_IOUtil_test_ASCIItoUnicode();
void TestSuit_IOUtil_test_ASCIItoUnicode2();
void TestSuit_IOUtil_test_strupr2();
void TestSuit_IOUtil_test_UnicodeChr_retNULL();
void TestSuit_IOUtil_test_UnicodeChr_longStr();
void TestSuit_IOUtil_test_UnicodetoASCII_else();
void TestSuit_IOUtil_test_SplitPath_while();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuit_IOUtil);

void TestSuit_IOUtil_setUp()
{
}

void TestSuit_IOUtil_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_ByteSwapCopy_for */
/* CPPTEST_TEST_CASE_CONTEXT void ByteSwapCopy(U8 *, U8 *, U16) */
void TestSuit_IOUtil_test_ByteSwapCopy_for()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8DesBuffer) */ 
	U8 _u8DesBuffer = 1;
    U8 * _pu8DesBuffer  = &_u8DesBuffer ;
    /* Initializing argument 2 (pu8SrcBuffer) */ 
    U8 _u8SrcBuffer = 2;
    U8 * _pu8SrcBuffer  = &_u8SrcBuffer ;
    /* Initializing argument 3 (TotalByte) */ 
    U16 _TotalByte  = 1u;
    {
        /* Tested function call */
        ByteSwapCopy(_pu8DesBuffer, _pu8SrcBuffer, _TotalByte);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 2, ( *_pu8DesBuffer ) );
        CPPTEST_POST_CONDITION_PTR("U8 * _pu8DesBuffer ", ( _pu8DesBuffer ));
        CPPTEST_POST_CONDITION_PTR("U8 * _pu8SrcBuffer ", ( _pu8SrcBuffer ));
    }
}
/* CPPTEST_TEST_CASE_END test_ByteSwapCopy_for */

/* CPPTEST_TEST_CASE_BEGIN test_ByteCopy */
/* CPPTEST_TEST_CASE_CONTEXT void ByteCopy(U8 *, U8 *, U16) */
void TestSuit_IOUtil_test_ByteCopy()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8DesBuffer) */ 
	U8 u8DesBuffer  = 1 ;
    U8 * _pu8DesBuffer  = &u8DesBuffer ;
    /* Initializing argument 2 (pu8SrcBuffer) */ 
    U8 u8SrcBuffer  = 2 ;
    U8 * _pu8SrcBuffer  = &u8SrcBuffer ;
    /* Initializing argument 3 (TotalByte) */ 
    U16 _TotalByte  = 1u;
    {
        /* Tested function call */
        ByteCopy(_pu8DesBuffer, _pu8SrcBuffer, _TotalByte);
        CPPTEST_ASSERT_EQUAL( 2, ( *_pu8DesBuffer ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_PTR("U8 * _pu8DesBuffer ", ( _pu8DesBuffer ));
        CPPTEST_POST_CONDITION_PTR("U8 * _pu8SrcBuffer ", ( _pu8SrcBuffer ));
    }
}
/* CPPTEST_TEST_CASE_END test_ByteCopy */

/* CPPTEST_TEST_CASE_BEGIN test_ByteComp */
/* CPPTEST_TEST_CASE_CONTEXT S8 ByteComp(U8 *, U8 *, U16) */
void TestSuit_IOUtil_test_ByteComp()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8DesBuffer) */ 
	U8 u8DesBuffer  = 1 ;
    U8 * _pu8DesBuffer  = &u8DesBuffer ;
    /* Initializing argument 2 (pu8SrcBuffer) */ 
    U8 u8SrcBuffer  = 2 ;
    U8 * _pu8SrcBuffer  = &u8SrcBuffer ;
    /* Initializing argument 3 (TotalByte) */ 
    U16 _TotalByte  = 1u;
    {
        /* Tested function call */
        S8 _return  = ByteComp(_pu8DesBuffer, _pu8SrcBuffer, _TotalByte);
        CPPTEST_ASSERT_EQUAL( -1, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_INTEGER("S8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("U8 * _pu8DesBuffer ", ( _pu8DesBuffer ));
        CPPTEST_POST_CONDITION_PTR("U8 * _pu8SrcBuffer ", ( _pu8SrcBuffer ));
    }
}
/* CPPTEST_TEST_CASE_END test_ByteComp */

/* CPPTEST_TEST_CASE_BEGIN test_ByteComp_same */
/* CPPTEST_TEST_CASE_CONTEXT S8 ByteComp(U8 *, U8 *, U16) */
void TestSuit_IOUtil_test_ByteComp_same()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8DesBuffer) */ 
	U8 u8DesBuffer  = 1 ;
    U8 * _pu8DesBuffer  = &u8DesBuffer ;
    /* Initializing argument 2 (pu8SrcBuffer) */ 
    U8 u8SrcBuffer  = 1 ;
    U8 * _pu8SrcBuffer  = &u8SrcBuffer ;
    /* Initializing argument 3 (TotalByte) */ 
    U16 _TotalByte  = 1u;
    {
        /* Tested function call */
        S8 _return  = ByteComp(_pu8DesBuffer, _pu8SrcBuffer, _TotalByte);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 0, ( _return ) );
        CPPTEST_POST_CONDITION_INTEGER("S8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("U8 * _pu8DesBuffer ", ( _pu8DesBuffer ));
        CPPTEST_POST_CONDITION_PTR("U8 * _pu8SrcBuffer ", ( _pu8SrcBuffer ));
    }
}
/* CPPTEST_TEST_CASE_END test_ByteComp_same */

/* CPPTEST_TEST_CASE_BEGIN test_msStrcat */
/* CPPTEST_TEST_CASE_CONTEXT char * msStrcat(char *, const char *) */
void TestSuit_IOUtil_test_msStrcat()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pDst) */ 
	char dst[5];
	int i;
	for(i=0;i<5;i++)
	{
		dst[i] = 0;
	}
    char * _pDst  =  dst;
    dst[0] = 'a';dst[1] = 'b';
    /* Initializing argument 2 (pSrc) */ 
    const char * _pSrc  = "cd" ;
    {
        /* Tested function call */
        char * _return  = msStrcat(_pDst, _pSrc);
        /* Post-condition check */
      //  CPPTEST_ASSERT_CSTR_EQUAL("abcd",(*_return));
        CPPTEST_ASSERT_EQUAL( 'a', ( *_return ) );
        CPPTEST_ASSERT_EQUAL( 'b', ( *(_return+1) ) );
        CPPTEST_ASSERT_EQUAL( 'c', ( *(_return+2) ) );
        CPPTEST_ASSERT_EQUAL( 'd', ( *(_return+3) ) );
        CPPTEST_POST_CONDITION_MEM_BUFFER("char * _return", ( _return ), sizeof(char));
        CPPTEST_POST_CONDITION_MEM_BUFFER("char * _pDst", ( _pDst ), sizeof(char));
    }
}
/* CPPTEST_TEST_CASE_END test_msStrcat */

/* CPPTEST_TEST_CASE_BEGIN test_msStrncpy */
/* CPPTEST_TEST_CASE_CONTEXT char * msStrncpy(char *, const char *, U16) */
void TestSuit_IOUtil_test_msStrncpy()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pDst) */ 
	char dst[3] = {'a'};
    char * _pDst  = dst ;
    /* Initializing argument 2 (pSrc) */ 
    char src[1] = "b";
    const char * _pSrc  = src ;
    /* Initializing argument 3 (u16Len) */ 
    U16 _u16Len  = 1u;
    {
        /* Tested function call */
        char * _return  = msStrncpy(_pDst, _pSrc, _u16Len);
        CPPTEST_ASSERT_EQUAL( 'b', ( *_pDst ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_MEM_BUFFER("char * _return", ( _return ), sizeof(char));
        CPPTEST_POST_CONDITION_MEM_BUFFER("char * _pDst", ( _pDst ), sizeof(char));
    }
}
/* CPPTEST_TEST_CASE_END test_msStrncpy */

/* CPPTEST_TEST_CASE_BEGIN test_SplitPath */
/* CPPTEST_TEST_CASE_CONTEXT void SplitPath(S8 *, S8 *, S8 *) */
void TestSuit_IOUtil_test_SplitPath()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ps8PathName) */ 
	S8 pathName[10] = {'a','b','c'};
    S8 * _ps8PathName  = pathName;
    /* Initializing argument 2 (ps8DirName) */ 
    S8 dirName[10] = {'d','e','f'};
    S8 * _ps8DirName  = dirName ;
    /* Initializing argument 3 (ps8FileName) */ 
    S8 fileName[10] = {'h','i','j'};
    S8 * _ps8FileName  = fileName ;
    {
        /* Tested function call */
        SplitPath(_ps8PathName, _ps8DirName, _ps8FileName);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 'a', ( *_ps8FileName ) );
    }
}
/* CPPTEST_TEST_CASE_END test_SplitPath */

/* CPPTEST_TEST_CASE_BEGIN test_IsFullPath_yes */
/* CPPTEST_TEST_CASE_CONTEXT U8 IsFullPath(S8 *) */
void TestSuit_IOUtil_test_IsFullPath_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ps8PathName) */ 
    S8 * _ps8PathName  = "abc";
    {
        /* Tested function call */
        U8 _return  = IsFullPath(_ps8PathName);
        CPPTEST_ASSERT_EQUAL( 0, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("S8 * _ps8PathName ", ( _ps8PathName ));
    }
}
/* CPPTEST_TEST_CASE_END test_IsFullPath_yes */

/* CPPTEST_TEST_CASE_BEGIN test_IsFullPath_no */
/* CPPTEST_TEST_CASE_CONTEXT U8 IsFullPath(S8 *) */
void TestSuit_IOUtil_test_IsFullPath_no()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ps8PathName) */ 
    S8 * _ps8PathName  = "\\abc" ;
    {
        /* Tested function call */
        U8 _return  = IsFullPath(_ps8PathName);
        CPPTEST_ASSERT_EQUAL( 1, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("S8 * _ps8PathName ", ( _ps8PathName ));
    }
}
/* CPPTEST_TEST_CASE_END test_IsFullPath_no */

/* CPPTEST_TEST_CASE_BEGIN test_UnicodeCmp */
/* CPPTEST_TEST_CASE_CONTEXT U8 UnicodeCmp(S8 *, S8 *) */
void TestSuit_IOUtil_test_UnicodeCmp()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ps8LongName1) */ 
	S8 s8LongName1[1] = {'a'};
    S8 * _ps8LongName1  = s8LongName1 ;
    /* Initializing argument 2 (ps8LongName2) */ 
    S8 s8LongName2[1] = {'b'};
    S8 * _ps8LongName2  = s8LongName2 ;
    {
        /* Tested function call */
        U8 _return  = UnicodeCmp(_ps8LongName1, _ps8LongName2);
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("S8 * _ps8LongName1 ", ( _ps8LongName1 ));
        CPPTEST_POST_CONDITION_PTR("S8 * _ps8LongName2 ", ( _ps8LongName2 ));
    }
}
/* CPPTEST_TEST_CASE_END test_UnicodeCmp */

/* CPPTEST_TEST_CASE_BEGIN test_UnicodeCmp_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT U8 UnicodeCmp(S8 *, S8 *) */
void TestSuit_IOUtil_test_UnicodeCmp_TRUE()
{
	S8 s8LongName1[4] = {'\0','a','\0','\0'};
    S8 * _ps8LongName1  = s8LongName1 ;
    /* Initializing argument 2 (ps8LongName2) */ 
    S8 s8LongName2[4] = {'\0','a','\0','\0'};
    S8 * _ps8LongName2  = s8LongName2 ;
    {
        /* Tested function call */
        U8 _return  = UnicodeCmp(_ps8LongName1, _ps8LongName2);
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("S8 * _ps8LongName1 ", ( _ps8LongName1 ));
        CPPTEST_POST_CONDITION_PTR("S8 * _ps8LongName2 ", ( _ps8LongName2 ));
    }
}
/* CPPTEST_TEST_CASE_END test_UnicodeCmp_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_UnicodeCat */
/* CPPTEST_TEST_CASE_CONTEXT void UnicodeCat(S8 *, S8 *) */
void TestSuit_IOUtil_test_UnicodeCat()
{
	S8 s8LongName1[6] = {'\0','a','\0','\0','\0','\0'};
    S8 * _ps8DesName  = s8LongName1 ;
    /* Initializing argument 2 (ps8LongName2) */
    S8 s8LongName2[6] = {'\0','b','\0','\0','\0','\0'};
    S8 * _ps8SrcName  = s8LongName2 ;
    {
        /* Tested function call */
        UnicodeCat(_ps8DesName, _ps8SrcName);
        CPPTEST_ASSERT_EQUAL( '\0', ( *(_ps8DesName+2) ) );
        CPPTEST_ASSERT_EQUAL( 'b', ( *(_ps8DesName+3) ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_PTR("S8 * _ps8DesName ", ( _ps8DesName ));
        CPPTEST_POST_CONDITION_PTR("S8 * _ps8SrcName ", ( _ps8SrcName ));
    }
}
/* CPPTEST_TEST_CASE_END test_UnicodeCat */

/* CPPTEST_TEST_CASE_BEGIN test_UnicodeLen */
/* CPPTEST_TEST_CASE_CONTEXT U8 UnicodeLen(S8 *) */
void TestSuit_IOUtil_test_UnicodeLen()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ps8PathName) */ 
	S8 s8LongName1[6] = {'\0','a','\0','\0','\0','\0'};
    S8 * _ps8PathName  = s8LongName1 ;
    {
        /* Tested function call */
        U8 _return  = UnicodeLen(_ps8PathName);
        CPPTEST_ASSERT_EQUAL( 1, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("S8 * _ps8PathName ", ( _ps8PathName ));
    }
}
/* CPPTEST_TEST_CASE_END test_UnicodeLen */

/* CPPTEST_TEST_CASE_BEGIN test_UnicodeChr */
/* CPPTEST_TEST_CASE_CONTEXT S8 * UnicodeChr(S8 *, S8) */
void TestSuit_IOUtil_test_UnicodeChr()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ps8PathName) */ 
	S8 s8LongName1[6] = {'\0','a','\0','b','\0','\0'};
    S8 * _ps8PathName  = s8LongName1 ;
    /* Initializing argument 2 (s8Chr) */ 
    S8 _s8Chr  = 'a';
    {
        /* Tested function call */
        S8 * _return  = UnicodeChr(_ps8PathName, _s8Chr);
        CPPTEST_ASSERT_EQUAL( 'a', ( *(_return+1) ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_PTR("S8 * _return ", ( _return ));
        CPPTEST_POST_CONDITION_PTR("S8 * _ps8PathName ", ( _ps8PathName ));
    }
}
/* CPPTEST_TEST_CASE_END test_UnicodeChr */

/* CPPTEST_TEST_CASE_BEGIN test_UnicodeCpy */
/* CPPTEST_TEST_CASE_CONTEXT void UnicodeCpy(S8 *, S8 *) */
void TestSuit_IOUtil_test_UnicodeCpy()
{


	S8 s8LongName1[6] = {'\0','a','\0','\0','\0','\0'};
    S8 * _ps8DesName  = s8LongName1 ;
    /* Initializing argument 2 (ps8LongName2) */
    S8 s8LongName2[6] = {'\0','b','\0','\0','\0','\0'};
    S8 * _ps8SrcName  = s8LongName2 ;
    {
        /* Tested function call */
        UnicodeCpy(_ps8DesName, _ps8SrcName);
        CPPTEST_ASSERT_EQUAL( 'b', ( *(_ps8DesName+1) ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_PTR("S8 * _ps8DesName ", ( _ps8DesName ));
        CPPTEST_POST_CONDITION_PTR("S8 * _ps8SrcName ", ( _ps8SrcName ));
    }
}
/* CPPTEST_TEST_CASE_END test_UnicodeCpy */

/* CPPTEST_TEST_CASE_BEGIN test_UnicodeSplitPath */
/* CPPTEST_TEST_CASE_CONTEXT void UnicodeSplitPath(S8 *, S8 *, S8 *) */
void TestSuit_IOUtil_test_UnicodeSplitPath()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ps8PathName) */ 
	S8 s8LongName1[8] = {'\0','\\','\0','\\','\0','a','\0','\0'};

    /* Initializing argument 2 (ps8LongName2) */
	S8 s8LongName2[8] = {'\0','\\','\0','\\','\0','a','\0','\0'};

	S8 s8LongName3[8] = {'\0','\\','\0','\\','\0','a','\0','\0'};

    S8 * _ps8PathName  = s8LongName1 ;
    /* Initializing argument 2 (ps8DirName) */ 
    S8 * _ps8DirName  = s8LongName2 ;
    /* Initializing argument 3 (ps8FileName) */ 
    S8 * _ps8FileName  = s8LongName3 ;
    {
        /* Tested function call */
        UnicodeSplitPath(_ps8PathName, _ps8DirName, _ps8FileName);
        CPPTEST_ASSERT_EQUAL( 'a', ( *(_ps8FileName+1) ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_PTR("S8 * _ps8PathName ", ( _ps8PathName ));
        CPPTEST_POST_CONDITION_PTR("S8 * _ps8DirName ", ( _ps8DirName ));
        CPPTEST_POST_CONDITION_PTR("S8 * _ps8FileName ", ( _ps8FileName ));
    }
}
/* CPPTEST_TEST_CASE_END test_UnicodeSplitPath */

/* CPPTEST_TEST_CASE_BEGIN test_UnicodeIsFullPath */
/* CPPTEST_TEST_CASE_CONTEXT U8 UnicodeIsFullPath(S8 *) */
void TestSuit_IOUtil_test_UnicodeIsFullPath()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ps8PathName) */ 
	S8 s8LongName1[8] = {'\0','\\','\0','\\','\0','\a','\0','\0'};
    S8 * _ps8PathName  = s8LongName1 ;
    {
        /* Tested function call */
        U8 _return  = UnicodeIsFullPath(_ps8PathName);
        CPPTEST_ASSERT_EQUAL( TRUE , ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("S8 * _ps8PathName ", ( _ps8PathName ));
    }
}
/* CPPTEST_TEST_CASE_END test_UnicodeIsFullPath */

/* CPPTEST_TEST_CASE_BEGIN test_UnicodeIsFullPath_NO */
/* CPPTEST_TEST_CASE_CONTEXT U8 UnicodeIsFullPath(S8 *) */
void TestSuit_IOUtil_test_UnicodeIsFullPath_NO()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ps8PathName) */ 
	S8 s8LongName1[8] = {'\0','\b','\0','\c','\0','\a','\0','\0'};
    S8 * _ps8PathName  = s8LongName1 ;
    {
        /* Tested function call */
        U8 _return  = UnicodeIsFullPath(_ps8PathName);
        CPPTEST_ASSERT_EQUAL( FALSE , ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("S8 * _ps8PathName ", ( _ps8PathName ));
    }
}
/* CPPTEST_TEST_CASE_END test_UnicodeIsFullPath_NO */

/* CPPTEST_TEST_CASE_BEGIN test_UnicodetoASCII */
/* CPPTEST_TEST_CASE_CONTEXT void UnicodetoASCII(S8 *) */
void TestSuit_IOUtil_test_UnicodetoASCII()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ps8FileName) */ 
	S8 s8LongName1[8] = {'\0','b','\0','c','\0','a','\0','\0'};
    S8 * _ps8FileName  = s8LongName1 ;
    {
        /* Tested function call */
        UnicodetoASCII(_ps8FileName);
        CPPTEST_ASSERT_EQUAL( 'b' , ( *_ps8FileName ) );

        /* Post-condition check */
        CPPTEST_POST_CONDITION_PTR("S8 * _ps8FileName ", ( _ps8FileName ));
    }
}
/* CPPTEST_TEST_CASE_END test_UnicodetoASCII */

/* CPPTEST_TEST_CASE_BEGIN test_ASCIItoUnicode */
/* CPPTEST_TEST_CASE_CONTEXT void ASCIItoUnicode(S8 *) */
void TestSuit_IOUtil_test_ASCIItoUnicode()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ps8FileName) */ 
	S8 s8LongName1[8] = {'a','b','c','\0','\0','\0','\0','\0'};
    S8 * _ps8FileName  = s8LongName1 ;
    {
        /* Tested function call */
       ASCIItoUnicode(_ps8FileName);
        CPPTEST_ASSERT_EQUAL( 'a' , ( *(_ps8FileName+1) ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_PTR("S8 * _ps8FileName ", ( _ps8FileName ));
    }
}
/* CPPTEST_TEST_CASE_END test_ASCIItoUnicode */

/* CPPTEST_TEST_CASE_BEGIN test_ASCIItoUnicode2 */
/* CPPTEST_TEST_CASE_CONTEXT void ASCIItoUnicode2(S8 *, U8) */
void TestSuit_IOUtil_test_ASCIItoUnicode2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ps8FileName) */ 
	S8 s8LongName1[8] = {'a','\0','\0','\0','\0','\0','\0','\0'};
    S8 * _ps8FileName  = s8LongName1 ;
    /* Initializing argument 2 (len) */ 
    U8 _len  = 1;
    {
        /* Tested function call */
        ASCIItoUnicode2(_ps8FileName, _len);
        CPPTEST_ASSERT_EQUAL( 'a' , ( *(_ps8FileName) ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_PTR("S8 * _ps8FileName ", ( _ps8FileName ));
    }
}
/* CPPTEST_TEST_CASE_END test_ASCIItoUnicode2 */

/* CPPTEST_TEST_CASE_BEGIN test_strupr2 */
/* CPPTEST_TEST_CASE_CONTEXT void strupr2(U8 *, U8) */
void TestSuit_IOUtil_test_strupr2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Str) */ 
	S8 s8LongName1[8] = {'a','\0','\0','\0','\0','\0','\0','\0'};
    U8 * _pu8Str  = s8LongName1 ;
    /* Initializing argument 2 (len) */ 
    U8 _len  = 1;
    {
        /* Tested function call */
        strupr2(_pu8Str, _len);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 'A' , ( *(_pu8Str) ) );
        CPPTEST_POST_CONDITION_PTR("U8 * _pu8Str ", ( _pu8Str ));
    }
}
/* CPPTEST_TEST_CASE_END test_strupr2 */

/* CPPTEST_TEST_CASE_BEGIN test_UnicodeChr_retNULL */
/* CPPTEST_TEST_CASE_CONTEXT S8 * UnicodeChr(S8 *, S8) */
void TestSuit_IOUtil_test_UnicodeChr_retNULL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ps8PathName) */ 
	S8 s8LongName1[8] = {'\0','\0','\0','\0','\0','\0','\0','\0'};
    S8 * _ps8PathName  = s8LongName1 ;
    /* Initializing argument 2 (s8Chr) */ 
    S8 _s8Chr  = 0;
    {
        /* Tested function call */
        S8 * _return  = UnicodeChr(_ps8PathName, _s8Chr);
        CPPTEST_ASSERT_EQUAL( '\0' , ( *(_ps8PathName) ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_PTR("S8 * _return ", ( _return ));
        CPPTEST_POST_CONDITION_PTR("S8 * _ps8PathName ", ( _ps8PathName ));
    }
}
/* CPPTEST_TEST_CASE_END test_UnicodeChr_retNULL */

/* CPPTEST_TEST_CASE_BEGIN test_UnicodeChr_longStr */
/* CPPTEST_TEST_CASE_CONTEXT S8 * UnicodeChr(S8 *, S8) */
void TestSuit_IOUtil_test_UnicodeChr_longStr()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ps8PathName) */ 
	S8 s8LongName1[8] = {'\0','a','\0','b','\0','\0','\0','\0'};
    S8 * _ps8PathName  = s8LongName1 ;
    /* Initializing argument 2 (s8Chr) */ 
    S8 _s8Chr  = 'b';
    {
        /* Tested function call */
        S8 * _return  = UnicodeChr(_ps8PathName, _s8Chr);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 'b' , ( *(_return+1) ) );
        CPPTEST_POST_CONDITION_PTR("S8 * _return ", ( _return ));
        CPPTEST_POST_CONDITION_PTR("S8 * _ps8PathName ", ( _ps8PathName ));
    }
}
/* CPPTEST_TEST_CASE_END test_UnicodeChr_longStr */

/* CPPTEST_TEST_CASE_BEGIN test_UnicodetoASCII_else */
/* CPPTEST_TEST_CASE_CONTEXT void UnicodetoASCII(S8 *) */
void TestSuit_IOUtil_test_UnicodetoASCII_else()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ps8FileName) */
	S8 s8LongName1[8] = {'a','b','\0','c','\0','a','\0','\0'};
    S8 * _ps8FileName  = s8LongName1 ;
    {
        /* Tested function call */
        UnicodetoASCII(_ps8FileName);
        CPPTEST_ASSERT_EQUAL( 'b' , ( *(_ps8FileName+1) ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_PTR("S8 * _ps8FileName ", ( _ps8FileName ));
    }
}
/* CPPTEST_TEST_CASE_END test_UnicodetoASCII_else */

/* CPPTEST_TEST_CASE_BEGIN test_SplitPath_while */
/* CPPTEST_TEST_CASE_CONTEXT void SplitPath(S8 *, S8 *, S8 *) */
void TestSuit_IOUtil_test_SplitPath_while()
{/*
    S8 * _ps8PathName  = 0 ;
    S8 * _ps8DirName  = 0 ;
    S8 * _ps8FileName  = 0 ;
    {
        SplitPath(_ps8PathName, _ps8DirName, _ps8FileName);
        CPPTEST_POST_CONDITION_PTR("S8 * _ps8PathName ", ( _ps8PathName ));
        CPPTEST_POST_CONDITION_PTR("S8 * _ps8DirName ", ( _ps8DirName ));
        CPPTEST_POST_CONDITION_PTR("S8 * _ps8FileName ", ( _ps8FileName ));
    }*/

    /* Pre-condition initialization */
    /* Initializing argument 1 (ps8PathName) */ 
	S8 pathName[10] = {'\\','\\','a','b','c'};
    S8 * _ps8PathName  = pathName;
    /* Initializing argument 2 (ps8DirName) */ 
    S8 dirName[10] = {'d','e','f'};
    S8 * _ps8DirName  = dirName ;
    /* Initializing argument 3 (ps8FileName) */ 
    S8 fileName[10] = {'h','i','j'};
    S8 * _ps8FileName  = fileName ;
    {
        /* Tested function call */
        SplitPath(_ps8PathName, _ps8DirName, _ps8FileName);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 'a', ( *_ps8FileName ) );
    }
}
/* CPPTEST_TEST_CASE_END test_SplitPath_while */
