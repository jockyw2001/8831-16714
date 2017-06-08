#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/n51fs/N51FS_Index.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/n51fs/N51FS_Index.c");

CPPTEST_TEST_SUITE(TestSuite_N51FS_Index);
CPPTEST_TEST(TestSuite_N51FS_Index_test_ConvStr2Int);
CPPTEST_TEST(TestSuite_N51FS_Index_test_ReOrderIndexEntry);
CPPTEST_TEST(TestSuite_N51FS_Index_test_cde_ten);
CPPTEST_TEST(TestSuite_N51FS_Index_test_cde_ten_0);
CPPTEST_TEST(TestSuite_N51FS_Index_test_str_cmp);
CPPTEST_TEST(TestSuite_N51FS_Index_test_str_cmp_0);
CPPTEST_TEST(TestSuite_N51FS_Index_test_str_cmp_1);
CPPTEST_TEST(TestSuite_N51FS_Index_test_ConvertN51FSTimeTo1980BasedSeconds);
CPPTEST_TEST(TestSuite_N51FS_Index_test_N51FS_Delete_GetSubNodeVCN);
CPPTEST_TEST(TestSuite_N51FS_Index_test_N51FS_Delete_Combine);
CPPTEST_TEST(TestSuite_N51FS_Index_test_N51FS_Delete_Combine_left);
CPPTEST_TEST(TestSuite_N51FS_Index_test_N51FS_Delete_Combine_enter);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_N51FS_Index_test_ConvStr2Int();
void TestSuite_N51FS_Index_test_ReOrderIndexEntry();
void TestSuite_N51FS_Index_test_cde_ten();
void TestSuite_N51FS_Index_test_cde_ten_0();
void TestSuite_N51FS_Index_test_str_cmp();
void TestSuite_N51FS_Index_test_str_cmp_0();
void TestSuite_N51FS_Index_test_str_cmp_1();
void TestSuite_N51FS_Index_test_ConvertN51FSTimeTo1980BasedSeconds();
void TestSuite_N51FS_Index_test_N51FS_Delete_GetSubNodeVCN();
void TestSuite_N51FS_Index_test_N51FS_Delete_Combine();
void TestSuite_N51FS_Index_test_N51FS_Delete_Combine_left();
void TestSuite_N51FS_Index_test_N51FS_Delete_Combine_enter();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_N51FS_Index);

void TestSuite_N51FS_Index_setUp()
{
}

void TestSuite_N51FS_Index_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_ConvStr2Int */
/* CPPTEST_TEST_CASE_CONTEXT int ConvStr2Int(char *) */
void TestSuite_N51FS_Index_test_ConvStr2Int()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (a) */ 
	//char pt[]
    char * _a  = "123" ;
    {
        /* Tested function call */
        int _return  = ConvStr2Int(_a);
        /* Post-condition check */
         CPPTEST_ASSERT_EQUAL(123,_return);

        // CPPTEST_POST_CONDITION_INTEGER(" _return", ( _return ));
      //  CPPTEST_POST_CONDITION_MEM_BUFFER("char * _a", ( _a ), sizeof(char));
    }
}
/* CPPTEST_TEST_CASE_END test_ConvStr2Int */

/* CPPTEST_TEST_CASE_BEGIN test_ReOrderIndexEntry */
/* CPPTEST_TEST_CASE_CONTEXT void ReOrderIndexEntry(IndexEntryHead *) */
void TestSuite_N51FS_Index_test_ReOrderIndexEntry()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pBuff) */ 
	IndexEntryHead  Buff ;
	IndexEntryHead * _pBuff ;
	Buff.EntryFlag = 0x1;
	Buff.EntrySize =8;
	/*Buff.SubNodeVCN = 0x1233;
	Buff.SubNodeVCN_H = 0x5677;
	Buff.MFTReference = 0x1234;
	Buff.MFTReference_H = 0x5678;*/




    _pBuff = &Buff;
    {
        /* Tested function call */
        ReOrderIndexEntry(&Buff);

        //CPPTEST_ASSERT_EQUAL(0x1234,Buff.SubNodeVCN);

        //CPPTEST_ASSERT_EQUAL(0x5678,Buff.SubNodeVCN_H);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_PTR("IndexEntryHead * _pBuff ", ( _pBuff ));
       // CPPTEST_ASSERT_Q
    }
}
/* CPPTEST_TEST_CASE_END test_ReOrderIndexEntry */

/* CPPTEST_TEST_CASE_BEGIN test_cde_ten */
/* CPPTEST_TEST_CASE_CONTEXT void cde_ten(char *) */
void TestSuite_N51FS_Index_test_cde_ten()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (p) */ 
	char testp[7]={'0','0','0','0',1,2,3,4};

    char * _p  = testp ;
    //testp = _p;
    {
        /* Tested function call */
        cde_ten(_p);

        /* Post-condition check */
        CPPTEST_POST_CONDITION_MEM_BUFFER("char * _p", ( _p ), sizeof(char));
    }
}
/* CPPTEST_TEST_CASE_END test_cde_ten */

/* CPPTEST_TEST_CASE_BEGIN test_cde_ten_0 */
/* CPPTEST_TEST_CASE_CONTEXT void cde_ten(char *) */
void TestSuite_N51FS_Index_test_cde_ten_0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (p) */ 
	char testp[4]={'\0',2,3,4};
    char * _p  = 0;
    _p = testp;
    {
        /* Tested function call */
        cde_ten(_p);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_MEM_BUFFER("char * _p", ( _p ), sizeof(char));
    }
}
/* CPPTEST_TEST_CASE_END test_cde_ten_0 */

/* CPPTEST_TEST_CASE_BEGIN test_str_cmp */
/* CPPTEST_TEST_CASE_CONTEXT int str_cmp(char *, char *) */
void TestSuite_N51FS_Index_test_str_cmp()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (p) */ 
    char * _p  = "123" ;
    /* Initializing argument 2 (q) */ 
    char * _q  = "234" ;
    {
        /* Tested function call */
        int _return  = str_cmp(_p, _q);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_INTEGER(" _return", ( _return ));
        CPPTEST_POST_CONDITION_MEM_BUFFER("char * _p", ( _p ), sizeof(char));
        CPPTEST_POST_CONDITION_MEM_BUFFER("char * _q", ( _q ), sizeof(char));
    }
}
/* CPPTEST_TEST_CASE_END test_str_cmp */

/* CPPTEST_TEST_CASE_BEGIN test_str_cmp_0 */
/* CPPTEST_TEST_CASE_CONTEXT int str_cmp(char *, char *) */
void TestSuite_N51FS_Index_test_str_cmp_0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (p) */ 
    char * _p  = "1234" ;
    /* Initializing argument 2 (q) */ 
    char * _q  = "345" ;
    {
        /* Tested function call */
        int _return  = str_cmp(_p, _q);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_INTEGER(" _return", ( _return ));
        CPPTEST_POST_CONDITION_MEM_BUFFER("char * _p", ( _p ), sizeof(char));
        CPPTEST_POST_CONDITION_MEM_BUFFER("char * _q", ( _q ), sizeof(char));
    }
}
/* CPPTEST_TEST_CASE_END test_str_cmp_0 */

/* CPPTEST_TEST_CASE_BEGIN test_str_cmp_1 */
/* CPPTEST_TEST_CASE_CONTEXT int str_cmp(char *, char *) */
void TestSuite_N51FS_Index_test_str_cmp_1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (p) */ 
    char * _p  = "234" ;
    /* Initializing argument 2 (q) */ 
    char * _q  = "1234" ;
    {
        /* Tested function call */
        int _return  = str_cmp(_p, _q);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_INTEGER(" _return", ( _return ));
        CPPTEST_POST_CONDITION_MEM_BUFFER("char * _p", ( _p ), sizeof(char));
        CPPTEST_POST_CONDITION_MEM_BUFFER("char * _q", ( _q ), sizeof(char));
    }
}
/* CPPTEST_TEST_CASE_END test_str_cmp_1 */

/* CPPTEST_TEST_CASE_BEGIN test_ConvertN51FSTimeTo1980BasedSeconds */
/* CPPTEST_TEST_CASE_CONTEXT U32 ConvertN51FSTimeTo1980BasedSeconds(U32, U32) */
BOOLEAN gbTest_ConvertN51FSTimeTo1980BasedSeconds_CallLL_subtractLong =FALSE ;
void TestSuite_N51FS_Index_test_ConvertN51FSTimeTo1980BasedSeconds()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (Hi) */ 
    U32 _Hi  = 0ul;
    /* Initializing argument 2 (Lo) */ 
    U32 _Lo  = 1ul;
    {
        /* Tested function call */
        U32 _return  = ConvertN51FSTimeTo1980BasedSeconds(_Hi, _Lo);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_ConvertN51FSTimeTo1980BasedSeconds_CallLL_subtractLong);
    }
}
/* CPPTEST_TEST_CASE_END test_ConvertN51FSTimeTo1980BasedSeconds */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_Delete_GetSubNodeVCN */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_Delete_GetSubNodeVCN(U8 *) */
BOOLEAN gbTest_N51FS_Delete_GetSubNodeVCN_CallmsAPI_FS_GetAddr=FALSE;
void TestSuite_N51FS_Index_test_N51FS_Delete_GetSubNodeVCN()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8SubNodeVCN) */ 
    U8 _u8SubNodeVCN[100]  = {0 };
    IndexHeader test;
    /* Initializing global variable pIndexHeader */ 
    {
    	pIndexHeader  = &test;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_Delete_GetSubNodeVCN(_u8SubNodeVCN);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("U8 * _u8SubNodeVCN ", ( _u8SubNodeVCN ));
        CPPTEST_POST_CONDITION_PTR("IndexHeader * pIndexHeader ", ( pIndexHeader ));
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_N51FS_Delete_GetSubNodeVCN_CallmsAPI_FS_GetAddr);
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_Delete_GetSubNodeVCN */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_Delete_Combine */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_Delete_Combine(U8) */
void TestSuite_N51FS_Index_test_N51FS_Delete_Combine()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fsid) */ 
    U8 _fsid  = 0;
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_2 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_2  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_1 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_1  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_0  = 0ul;
    }
    /* Initializing global variable pIndexHeader */ 
    {
         pIndexHeader  = 0 ;
    }
    IndexHeader indexHeader;
    indexHeader.indexEntry.EntryFlag = INDEX_ENTRY_FLAG_BIT_NODE;
    pIndexHeader =&indexHeader;
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_Delete_Combine(_fsid);
        /* Post-condition check */

        CPPTEST_ASSERT_BOOL_EQUAL(TRUE,_return);
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_Delete_Combine */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_Delete_Combine_left */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_Delete_Combine(U8) */
void TestSuite_N51FS_Index_test_N51FS_Delete_Combine_left()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fsid) */ 
    U8 _fsid  = 0;
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_2 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_2  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_1 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_1  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_0  = 0ul;
    }
    /* Initializing global variable pIndexHeader */ 
    {
         pIndexHeader  = 0 ;
    }

    IndexHeader indexHeader;
    indexHeader.indexEntry.EntryFlag = INDEX_ENTRY_FLAG_BIT_END;
    pIndexHeader =&indexHeader;


    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_Delete_Combine(_fsid);
        /* Post-condition check */

        CPPTEST_ASSERT_BOOL_EQUAL(TRUE,_return);
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_Delete_Combine_left */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_Delete_Combine_enter */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_Delete_Combine(U8) */
void TestSuite_N51FS_Index_test_N51FS_Delete_Combine_enter()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fsid) */ 
    U8 _fsid  = 0;
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_2 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_2  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_1 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_1  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_0  = 0ul;
    }
    /* Initializing global variable pIndexHeader */ 
    {
         pIndexHeader  = 0 ;
    }
    IndexHeader indexHeader;
    /*  indexHeader.indexEntry.EntryFlag = INDEX_ENTRY_FLAG_BIT_END;
    indexHeader.u8SubNodVCN[0] =0;
    indexHeader.u32CurrentRecordBytePosition =5000;
    indexHeader.indexEntry.EntrySize =70;
    indexHeader.u32OffsetToIndexRootAttr=10;
    indexHeader.u32OffsetToIndexRootHeader =10;
    indexHeader.u32RunListAddr =N51FS_TEMP_4K_BACKUP_BUFFER_0;
    indexHeader.u16OffsetToRunList =80;//*/
   // indexHeader.u32CurrentRecordBytePosition


    memset(&indexHeader, 0, sizeof(IndexHeader));
    indexHeader.indexEntry.EntryFlag = INDEX_ENTRY_FLAG_BIT_END;
    indexHeader.indexEntry.EntrySize =50;

 //   indexHeader.
    pIndexHeader =&indexHeader;


    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_Delete_Combine(_fsid);
        /* Post-condition check */

        CPPTEST_ASSERT_BOOL_EQUAL(TRUE,_return);
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_Delete_Combine_enter */
