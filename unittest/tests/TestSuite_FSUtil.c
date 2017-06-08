#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/n51fs/FSUtil.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/n51fs/FSUtil.c");

CPPTEST_TEST_SUITE(TestSuite_FSUtil);
CPPTEST_TEST(TestSuite_FSUtil_test_LL_greater);
CPPTEST_TEST(TestSuite_FSUtil_test_LL_greater_or_equal);
CPPTEST_TEST(TestSuite_FSUtil_test_LL_equal);
CPPTEST_TEST(TestSuite_FSUtil_test_LL_iszero);
CPPTEST_TEST(TestSuite_FSUtil_test_LL_subtractLong);
CPPTEST_TEST(TestSuite_FSUtil_test_LL_subtract);
CPPTEST_TEST(TestSuite_FSUtil_test_LL_addLong);
CPPTEST_TEST(TestSuite_FSUtil_test_LL_add_signed);
CPPTEST_TEST(TestSuite_FSUtil_test_LL_add);
CPPTEST_TEST(TestSuite_FSUtil_test_FS_Log2);
CPPTEST_TEST(TestSuite_FSUtil_test_FS_IsPowerOf2);
CPPTEST_TEST(TestSuite_FSUtil_test_LL_assign);
CPPTEST_TEST(TestSuite_FSUtil_test_FS_strequal_U);
CPPTEST_TEST(TestSuite_FSUtil_test_FS_ASCII2Unicode);
CPPTEST_TEST(TestSuite_FSUtil_test_FS_Unicode2ASCII);
CPPTEST_TEST(TestSuite_FSUtil_test_FS_strupr2);
CPPTEST_TEST(TestSuite_FSUtil_test_FS_ByteSwapCopy);
CPPTEST_TEST(TestSuite_FSUtil_test_FS_strlen_U);
CPPTEST_TEST(TestSuite_FSUtil_test_LL_rshift);
CPPTEST_TEST(TestSuite_FSUtil_test_LL_multU32);
CPPTEST_TEST(TestSuite_FSUtil_test_LL_LongMultU32);
CPPTEST_TEST(TestSuite_FSUtil_test_LL_LongDivU32);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_FSUtil_test_LL_greater();
void TestSuite_FSUtil_test_LL_greater_or_equal();
void TestSuite_FSUtil_test_LL_equal();
void TestSuite_FSUtil_test_LL_iszero();
void TestSuite_FSUtil_test_LL_subtractLong();
void TestSuite_FSUtil_test_LL_subtract();
void TestSuite_FSUtil_test_LL_addLong();
void TestSuite_FSUtil_test_LL_add_signed();
void TestSuite_FSUtil_test_LL_add();
void TestSuite_FSUtil_test_FS_Log2();
void TestSuite_FSUtil_test_FS_IsPowerOf2();
void TestSuite_FSUtil_test_LL_assign();
void TestSuite_FSUtil_test_FS_strequal_U();
void TestSuite_FSUtil_test_FS_ASCII2Unicode();
void TestSuite_FSUtil_test_FS_Unicode2ASCII();
void TestSuite_FSUtil_test_FS_strupr2();
void TestSuite_FSUtil_test_FS_ByteSwapCopy();
void TestSuite_FSUtil_test_FS_strlen_U();
void TestSuite_FSUtil_test_LL_rshift();
void TestSuite_FSUtil_test_LL_multU32();
void TestSuite_FSUtil_test_LL_LongMultU32();
void TestSuite_FSUtil_test_LL_LongDivU32();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_FSUtil);

void TestSuite_FSUtil_setUp()
{
}

void TestSuite_FSUtil_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_LL_greater */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN LL_greater(LongLong *, LongLong *) */
void TestSuite_FSUtil_test_LL_greater()
{
    /* Pre-condition initialization */
	LongLong pX1 = {1,1};
	LongLong pY1 = {1,1};
    /* Initializing argument 1 (pX) */ 
    LongLong * _pX1  = &pX1 ;
    /* Initializing argument 2 (pY) */ 
    LongLong * _pY1  = &pY1 ;

	LongLong pX2 = {1,1};
	LongLong pY2 = {2,2};
    /* Initializing argument 1 (pX) */
    LongLong * _pX2  = &pX2 ;
    /* Initializing argument 2 (pY) */
    LongLong * _pY2  = &pY2 ;
    {
        /* Tested function call */
        BOOLEAN _return1  = LL_greater(_pX1, _pY1);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL((_pX1->Lo > _pY1->Lo), (_return1));

        /* Tested function call */
        BOOLEAN _return2  = LL_greater(_pX2, _pY2);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL((_pX2->Hi > _pY2->Hi), (_return2));
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("LongLong * _pX ", ( _pX ));
        //CPPTEST_POST_CONDITION_PTR("LongLong * _pY ", ( _pY ));
    }
}
/* CPPTEST_TEST_CASE_END test_LL_greater */

/* CPPTEST_TEST_CASE_BEGIN test_LL_greater_or_equal */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN LL_greater_or_equal(LongLong *, LongLong *) */
void TestSuite_FSUtil_test_LL_greater_or_equal()
{
    /* Pre-condition initialization */
	LongLong pX1 = {1,1};
	LongLong pY1 = {1,1};
    /* Initializing argument 1 (pX1) */
	LongLong * _pX1  = &pX1 ;
    /* Initializing argument 2 (pY1) */
	LongLong * _pY1  = &pY1 ;

	LongLong pX2 = {1,1};
	LongLong pY2 = {2,2};
	/* Initializing argument 1 (pX2) */
	LongLong * _pX2  = &pX2 ;
	/* Initializing argument 2 (pY2) */
	LongLong * _pY2  = &pY2 ;

    {
        /* Tested function call */
        BOOLEAN _return1  = LL_greater_or_equal(_pX1, _pY1);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL((_pX1->Lo >= _pY1->Lo), (_return1));

        /* Tested function call */
        BOOLEAN _return2  = LL_greater_or_equal(_pX2, _pY2);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL((_pX2->Hi > _pY2->Hi), (_return2));
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("LongLong * _pX ", ( _pX ));
        //CPPTEST_POST_CONDITION_PTR("LongLong * _pY ", ( _pY ));
    }
}
/* CPPTEST_TEST_CASE_END test_LL_greater_or_equal */

/* CPPTEST_TEST_CASE_BEGIN test_LL_equal */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN LL_equal(LongLong *, LongLong *) */
void TestSuite_FSUtil_test_LL_equal()
{
    /* Pre-condition initialization */
	LongLong pX = {1,1};
	LongLong pY = {1,1};
    /* Initializing argument 1 (pX) */ 
    LongLong * _pX  = &pX ;
    /* Initializing argument 2 (pY) */ 
    LongLong * _pY  = &pY ;
    {
        /* Tested function call */
        BOOLEAN _return  = LL_equal(_pX, _pY);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(((_pX->Lo==_pY->Lo) && (_pX->Hi==_pY->Hi)), (_return));
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("LongLong * _pX ", ( _pX ));
        //CPPTEST_POST_CONDITION_PTR("LongLong * _pY ", ( _pY ));
    }
}
/* CPPTEST_TEST_CASE_END test_LL_equal */

/* CPPTEST_TEST_CASE_BEGIN test_LL_iszero */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN LL_iszero(LongLong *) */
void TestSuite_FSUtil_test_LL_iszero()
{
    /* Pre-condition initialization */
	LongLong pX = {1,1};
    /* Initializing argument 1 (pX) */ 
    LongLong * _pX  = &pX ;
    {
        /* Tested function call */
        BOOLEAN _return  = LL_iszero(_pX);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(((_pX->Hi | _pX->Lo) == 0), (_return));
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("LongLong * _pX ", ( _pX ));
    }
}
/* CPPTEST_TEST_CASE_END test_LL_iszero */

/* CPPTEST_TEST_CASE_BEGIN test_LL_subtractLong */
/* CPPTEST_TEST_CASE_CONTEXT LongLong LL_subtractLong(LongLong *, LongLong *) */
void TestSuite_FSUtil_test_LL_subtractLong()
{
    /* Pre-condition initialization */
	LongLong pX = {2,1};
	LongLong pY = {1,2};
    /* Initializing argument 1 (pX) */ 
    LongLong * _pX  = &pX ;
    /* Initializing argument 2 (pY) */ 
    LongLong * _pY  = &pY ;
    {
        /* Tested function call */
        LongLong _return  = LL_subtractLong(_pX, _pY);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0,( _return.Hi ));
        CPPTEST_ASSERT_EQUAL(((_pX->Lo)-(_pY->Lo)),( _return.Lo ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Hi", ( _return.Hi ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Lo", ( _return.Lo ));
        //CPPTEST_POST_CONDITION_PTR("LongLong * _pX ", ( _pX ));
        //CPPTEST_POST_CONDITION_PTR("LongLong * _pY ", ( _pY ));
    }
}
/* CPPTEST_TEST_CASE_END test_LL_subtractLong */

/* CPPTEST_TEST_CASE_BEGIN test_LL_subtract */
/* CPPTEST_TEST_CASE_CONTEXT LongLong LL_subtract(LongLong *, U32) */
void TestSuite_FSUtil_test_LL_subtract()
{
    /* Pre-condition initialization */
	LongLong pLongLong = {2,1};
    /* Initializing argument 1 (pLongLong) */ 
    LongLong * _pLongLong  = &pLongLong ;
    /* Initializing argument 2 (val) */ 
    U32 _val  = 2;
    {
        /* Tested function call */
        LongLong _return  = LL_subtract(_pLongLong, _val);
        CPPTEST_ASSERT_EQUAL(1,( _return.Hi ));
        CPPTEST_ASSERT_EQUAL(((_pLongLong->Lo)-_val),( _return.Lo ));
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Hi", ( _return.Hi ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Lo", ( _return.Lo ));
        //CPPTEST_POST_CONDITION_PTR("LongLong * _pLongLong ", ( _pLongLong ));
    }
}
/* CPPTEST_TEST_CASE_END test_LL_subtract */

/* CPPTEST_TEST_CASE_BEGIN test_LL_addLong */
/* CPPTEST_TEST_CASE_CONTEXT LongLong LL_addLong(LongLong *, LongLong *) */
void TestSuite_FSUtil_test_LL_addLong()
{
    /* Pre-condition initialization */
	LongLong pX = {1,4294967295};
	LongLong pY = {2,2};
    /* Initializing argument 1 (pX) */ 
    LongLong * _pX  = &pX ;
    /* Initializing argument 2 (pY) */ 
    LongLong * _pY  = &pY ;
    {
        /* Tested function call */
        LongLong _return  = LL_addLong(_pX, _pY);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(3,( _return.Hi ));
        CPPTEST_ASSERT_EQUAL(4294967297,( _return.Lo ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Hi", ( _return.Hi ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Lo", ( _return.Lo ));
        //CPPTEST_POST_CONDITION_PTR("LongLong * _pX ", ( _pX ));
        //CPPTEST_POST_CONDITION_PTR("LongLong * _pY ", ( _pY ));
    }
}
/* CPPTEST_TEST_CASE_END test_LL_addLong */
extern BOOLEAN btest_LL_add_signed_CallLL_add;
extern BOOLEAN btest_LL_add_signed_CallLL_subtract;
/* CPPTEST_TEST_CASE_BEGIN test_LL_add_signed */
/* CPPTEST_TEST_CASE_CONTEXT LongLong LL_add_signed(LongLong *, S32) */
void TestSuite_FSUtil_test_LL_add_signed()
{
    /* Pre-condition initialization */
	LongLong pLongLong1 = {1,1};
    /* Initializing argument 1 (pLongLong) */ 
    LongLong * _pLongLong1  = &pLongLong1;
    /* Initializing argument 2 (val) */ 
    S32 _val1  = 1L;

    LongLong pLongLong2 = {1,1};
    /* Initializing argument 1 (pLongLong) */
    LongLong * _pLongLong2  = &pLongLong2;
    /* Initializing argument 2 (val) */
    S32 _val2  = -1L;
    {
        /* Tested function call */
        LongLong _return1  = LL_add_signed(_pLongLong1, _val1);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE,btest_LL_add_signed_CallLL_add);
        CPPTEST_ASSERT_EQUAL(1,( _return1.Hi ));
        CPPTEST_ASSERT_EQUAL(1,( _return1.Lo ));

        LongLong _return2  = LL_add_signed(_pLongLong2, _val2);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE,btest_LL_add_signed_CallLL_subtract);
        CPPTEST_ASSERT_EQUAL(2,( _return2.Hi ));
        CPPTEST_ASSERT_EQUAL(2,( _return2.Lo ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Hi", ( _return.Hi ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Lo", ( _return.Lo ));
        //CPPTEST_POST_CONDITION_PTR("LongLong * _pLongLong ", ( _pLongLong ));
    }
}
/* CPPTEST_TEST_CASE_END test_LL_add_signed */

/* CPPTEST_TEST_CASE_BEGIN test_LL_add */
/* CPPTEST_TEST_CASE_CONTEXT LongLong LL_add(LongLong *, U32) */
void TestSuite_FSUtil_test_LL_add()
{
    /* Pre-condition initialization */
	LongLong pLongLong = {1,4294967295};
    /* Initializing argument 1 (pLongLong) */ 
    LongLong * _pLongLong  = &pLongLong ;
    /* Initializing argument 2 (val) */ 
    U32 _val  = 2ul;
    {
        /* Tested function call */
        LongLong _return  = LL_add(_pLongLong, _val);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(1,( _return.Hi ));
        CPPTEST_ASSERT_EQUAL((_pLongLong->Lo)+_val,( _return.Lo ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Hi", ( _return.Hi ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Lo", ( _return.Lo ));
        //CPPTEST_POST_CONDITION_PTR("LongLong * _pLongLong ", ( _pLongLong ));
    }
}
/* CPPTEST_TEST_CASE_END test_LL_add */

/* CPPTEST_TEST_CASE_BEGIN test_FS_Log2 */
/* CPPTEST_TEST_CASE_CONTEXT S32 FS_Log2(S32) */
void TestSuite_FSUtil_test_FS_Log2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (val) */ 
    S32 _val  = 3L;
    {
        /* Tested function call */
        S32 _return  = FS_Log2(_val);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(2, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_FS_Log2 */

/* CPPTEST_TEST_CASE_BEGIN test_FS_IsPowerOf2 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FS_IsPowerOf2(U32) */
void TestSuite_FSUtil_test_FS_IsPowerOf2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (num) */ 
    U32 _num1  = 0ul;
    U32 _num2  = 1ul;
    U32 _num3  = 3ul;
    {
        /* Tested function call */
        BOOLEAN _return1  = FS_IsPowerOf2(_num1);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return1);

        BOOLEAN _return2  = FS_IsPowerOf2(_num2);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, _return2);

        BOOLEAN _return3  = FS_IsPowerOf2(_num3);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return3);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_FS_IsPowerOf2 */

/* CPPTEST_TEST_CASE_BEGIN test_LL_assign */
/* CPPTEST_TEST_CASE_CONTEXT void LL_assign(LongLong *, U32) */
void TestSuite_FSUtil_test_LL_assign()
{
    /* Pre-condition initialization */
	LongLong pX = {1,1};
    /* Initializing argument 1 (pX) */ 
    LongLong * _pX  = &pX ;
    /* Initializing argument 2 (val) */ 
    U32 _val  = 2ul;
    {
        /* Tested function call */
        LL_assign(_pX, _val);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0,_pX->Hi);
        CPPTEST_ASSERT_EQUAL(2,_pX->Lo);
        //CPPTEST_POST_CONDITION_PTR("LongLong * _pX ", ( _pX ));
    }
}
/* CPPTEST_TEST_CASE_END test_LL_assign */

/* CPPTEST_TEST_CASE_BEGIN test_FS_strequal_U */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FS_strequal_U(U16 *, U16 *) */
void TestSuite_FSUtil_test_FS_strequal_U()
{
    /* Pre-condition initialization */
	U16 LongName1_1 = 0;
	U16 LongName2_1 = 0;
    /* Initializing argument 1 (pu16LongName1) */ 
    U16 * _pu16LongName1_1  = &LongName1_1;
    /* Initializing argument 2 (pu16LongName2) */ 
    U16 * _pu16LongName2_1  = &LongName2_1;

	U16 LongName1_2 = 0;
	U16 LongName2_2 = 1;
    /* Initializing argument 1 (pu16LongName1) */
    U16 * _pu16LongName1_2  = &LongName1_2;
    /* Initializing argument 2 (pu16LongName2) */
    U16 * _pu16LongName2_2  = &LongName2_2;

	U16 LongName1_3[65535];
	U16 LongName2_3[65535];
	U16 i = 0;
    /* Initializing argument 1 (pu16LongName1) */
    U16 * _pu16LongName1_3  = &LongName1_3;
    /* Initializing argument 2 (pu16LongName2) */
    U16 * _pu16LongName2_3  = &LongName2_3;
    for(i = 0;i < 65535;i++)
    {
    	LongName1_3[i] = 1;
    	LongName2_3[i] = 1;
    }
    {
    	/* Tested function call */
    	BOOLEAN _return1  = FS_strequal_U(_pu16LongName1_1, _pu16LongName2_1);
    	/* Post-condition check */
    	CPPTEST_ASSERT_BOOL_EQUAL(TRUE, _return1);

        /* Tested function call */
        BOOLEAN _return2  = FS_strequal_U(_pu16LongName1_2, _pu16LongName2_2);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return2);

        /* Tested function call */
        BOOLEAN _return3  = FS_strequal_U(_pu16LongName1_3, _pu16LongName2_3);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return3);
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("U16 * _pu16LongName1 ", ( _pu16LongName1 ));
        //CPPTEST_POST_CONDITION_PTR("U16 * _pu16LongName2 ", ( _pu16LongName2 ));
    }
}
/* CPPTEST_TEST_CASE_END test_FS_strequal_U */

/* CPPTEST_TEST_CASE_BEGIN test_FS_ASCII2Unicode */
/* CPPTEST_TEST_CASE_CONTEXT void FS_ASCII2Unicode(U8 *) */
void TestSuite_FSUtil_test_FS_ASCII2Unicode()
{
    /* Pre-condition initialization */
	U8 FileName[40] = {1,2,3,4,5,6,7,8,9,0};
	U8 meger[40] = {1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0};
    /* Initializing argument 1 (pu8FileName) */ 
    U8 * _pu8FileName  = &FileName ;
    {
        /* Tested function call */
        FS_ASCII2Unicode(_pu8FileName);
        /* Post-condition check */
        CPPTEST_ASSERT_CSTR_EQUAL(FileName,meger);
        //CPPTEST_POST_CONDITION_PTR("U8 * _pu8FileName ", ( _pu8FileName ));

    }
}
/* CPPTEST_TEST_CASE_END test_FS_ASCII2Unicode */

/* CPPTEST_TEST_CASE_BEGIN test_FS_Unicode2ASCII */
/* CPPTEST_TEST_CASE_CONTEXT void FS_Unicode2ASCII(U16 *) */
void TestSuite_FSUtil_test_FS_Unicode2ASCII()
{
    /* Pre-condition initialization */
	U8 FileName[40] = {1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0};
	U8 meger[40] = {1,2,3,4,5,6,7,8,9,0};
    /* Initializing argument 1 (pu16FileName) */ 
    U16 * _pu16FileName  = &FileName ;
    {
        /* Tested function call */
        FS_Unicode2ASCII(_pu16FileName);
        /* Post-condition check */
        CPPTEST_ASSERT_CSTR_EQUAL(FileName,meger);
    }
}
/* CPPTEST_TEST_CASE_END test_FS_Unicode2ASCII */

/* CPPTEST_TEST_CASE_BEGIN test_FS_strupr2 */
/* CPPTEST_TEST_CASE_CONTEXT void FS_strupr2(U8 *, U8) */
void TestSuite_FSUtil_test_FS_strupr2()
{
    /* Pre-condition initialization */
	U8 str[40] = "abcdefghijkABC";
	U8 meger[40] = "ABCDEFGHIJKABC";
    /* Initializing argument 1 (pu8Str) */ 
    U8 * _pu8Str  = str ;
    /* Initializing argument 2 (len) */ 
    U8 _len  = 12;
    {
        /* Tested function call */
        FS_strupr2(_pu8Str, _len);
        /* Post-condition check */
        CPPTEST_ASSERT_CSTR_EQUAL(str,meger);
    }
}
/* CPPTEST_TEST_CASE_END test_FS_strupr2 */

/* CPPTEST_TEST_CASE_BEGIN test_FS_ByteSwapCopy */
/* CPPTEST_TEST_CASE_CONTEXT void FS_ByteSwapCopy(U8 *, U8 *, U16) */
void TestSuite_FSUtil_test_FS_ByteSwapCopy()
{
    /* Pre-condition initialization */
	U8 Desbuf[20] = "";
	U8 Srcbuf[20] = "abcdefghijklmn";
	U8 meger[20] = "nmlkjihgfedcba";
    /* Initializing argument 1 (pu8DesBuffer) */ 
    U8 * _pu8DesBuffer  = Desbuf ;
    /* Initializing argument 2 (pu8SrcBuffer) */ 
    U8 * _pu8SrcBuffer  = Srcbuf ;
    /* Initializing argument 3 (TotalByte) */ 
    U16 _TotalByte  = 14u;
    {
        /* Tested function call */
        FS_ByteSwapCopy(_pu8DesBuffer, _pu8SrcBuffer, _TotalByte);
        /* Post-condition check */
        CPPTEST_ASSERT_CSTR_EQUAL(Desbuf,meger);
        //CPPTEST_POST_CONDITION_PTR("U8 * _pu8DesBuffer ", ( _pu8DesBuffer ));
        //CPPTEST_POST_CONDITION_PTR("U8 * _pu8SrcBuffer ", ( _pu8SrcBuffer ));
    }
}
/* CPPTEST_TEST_CASE_END test_FS_ByteSwapCopy */

/* CPPTEST_TEST_CASE_BEGIN test_FS_strlen_U */
/* CPPTEST_TEST_CASE_CONTEXT U8 FS_strlen_U(U16 *) */
void TestSuite_FSUtil_test_FS_strlen_U()
{
    /* Pre-condition initialization */
	U16 String1[20] ={1,2,3,4,5,6,7,8,9,0};
    /* Initializing argument 1 (pu16String) */
    U16 * _pu16String1  = String1 ;

    /* Pre-condition initialization */
    U16 String2[256] ={0};
    U16 i = 0;
    /* Initializing argument 1 (pu16String) */ 
    U16 * _pu16String2  = String2 ;
    for (i=0;i<256;i++)
    {
    	String2[i]=1;
    }
    {
        /* Tested function call */
        U8 _return1  = FS_strlen_U(_pu16String1);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(9,_return1);

        /* Tested function call */
        U8 _return2  = FS_strlen_U(_pu16String2);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0,_return2);
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_PTR("U16 * _pu16String ", ( _pu16String ));
    }
}
/* CPPTEST_TEST_CASE_END test_FS_strlen_U */

/* CPPTEST_TEST_CASE_BEGIN test_LL_rshift */
/* CPPTEST_TEST_CASE_CONTEXT LongLong LL_rshift(LongLong *, U8) */
void TestSuite_FSUtil_test_LL_rshift()
{
    /* Pre-condition initialization */
	LongLong pX1 = {1,1};
    /* Initializing argument 1 (pX) */ 
    LongLong * _pX1  = &pX1 ;
    /* Initializing argument 2 (count) */ 
    U8 _count1  = 0;

    LongLong pX2 = {2,2};
    /* Initializing argument 1 (pX) */
    LongLong * _pX2  = &pX2 ;
    /* Initializing argument 2 (count) */
    U8 _count2  = 1;

    LongLong pX3 = {3,3};
    /* Initializing argument 1 (pX) */
    LongLong * _pX3  = &pX3 ;
    /* Initializing argument 2 (count) */
    U8 _count3  = 32;

    {
        /* Tested function call */
        LongLong _return1  = LL_rshift(_pX1, _count1);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(1,( _return1.Hi ));
        CPPTEST_ASSERT_EQUAL(1,( _return1.Lo ));

        /* Tested function call */
        LongLong _return2  = LL_rshift(_pX2, _count2);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(1,( _return2.Hi ));
        CPPTEST_ASSERT_EQUAL(1,( _return2.Lo ));

        /* Tested function call */
        LongLong _return3  = LL_rshift(_pX3, _count3);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0,( _return3.Hi ));
        CPPTEST_ASSERT_EQUAL(3,( _return3.Lo ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Hi", ( _return.Hi ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Lo", ( _return.Lo ));
        //CPPTEST_POST_CONDITION_PTR("LongLong * _pX ", ( _pX ));
    }
}
/* CPPTEST_TEST_CASE_END test_LL_rshift */

/* CPPTEST_TEST_CASE_BEGIN test_LL_multU32 */
/* CPPTEST_TEST_CASE_CONTEXT LongLong LL_multU32(U32, U32) */
void TestSuite_FSUtil_test_LL_multU32()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (x) */ 
    U32 _x  = 1ul;
    /* Initializing argument 2 (y) */ 
    U32 _y  = 1ul;
    {
        /* Tested function call */
        LongLong _return  = LL_multU32(_x, _y);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0, ( _return.Hi ));
        CPPTEST_ASSERT_EQUAL(1, ( _return.Lo ));
    }
}
/* CPPTEST_TEST_CASE_END test_LL_multU32 */

/* CPPTEST_TEST_CASE_BEGIN test_LL_LongMultU32 */
/* CPPTEST_TEST_CASE_CONTEXT LongLong LL_LongMultU32(LongLong *, U32) */
void TestSuite_FSUtil_test_LL_LongMultU32()
{
    /* Pre-condition initialization */
	LongLong pLongLong = {1,1};
    /* Initializing argument 1 (pLongLong) */ 
    LongLong * _pLongLong  = &pLongLong ;
    /* Initializing argument 2 (y) */ 
    U32 _y  = 1ul;
    {
        /* Tested function call */
        LongLong _return  = LL_LongMultU32(_pLongLong, _y);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(2, ( _return.Hi ));
        CPPTEST_ASSERT_EQUAL(1, ( _return.Lo ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Hi", ( _return.Hi ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Lo", ( _return.Lo ));
        //CPPTEST_POST_CONDITION_PTR("LongLong * _pLongLong ", ( _pLongLong ));
    }
}
/* CPPTEST_TEST_CASE_END test_LL_LongMultU32 */

/* CPPTEST_TEST_CASE_BEGIN test_LL_LongDivU32 */
/* CPPTEST_TEST_CASE_CONTEXT LongLong LL_LongDivU32(LongLong *, U32) */
void TestSuite_FSUtil_test_LL_LongDivU32()
{
    /* Pre-condition initialization */
	LongLong _x1 = {2,2};
    /* Initializing argument 1 (x) */
    LongLong * _px1  = &_x1 ;
    /* Initializing argument 2 (y) */
    U32 _y1  = 2ul;

    LongLong _x2 = {3,3};
    /* Initializing argument 1 (x) */ 
    LongLong * _px2  = &_x2 ;
    /* Initializing argument 2 (y) */ 
    U32 _y2  = 2ul;

    LongLong _x3 = {3,3};
    /* Initializing argument 1 (x) */
    LongLong * _px3  = &_x3 ;
    /* Initializing argument 2 (y) */
    U32 _y3  = 65536ul;
    {
        /* Tested function call */
        LongLong _return1  = LL_LongDivU32(_px1, _y1);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(1, ( _return1.Hi ));
        CPPTEST_ASSERT_EQUAL(1, ( _return1.Lo ));

        LongLong _return2  = LL_LongDivU32(_px2, _y2);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(1, ( _return2.Hi ));
        //CPPTEST_ASSERT_EQUAL(2147483649, ( _return2.Lo ));

        //LongLong _return3  = LL_LongDivU32(_px3, _y3);
        /* Post-condition check */
        //CPPTEST_ASSERT_EQUAL(1, ( _return3.Hi ));
        //CPPTEST_ASSERT_EQUAL(1, ( _return3.Lo ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Hi", ( _return.Hi ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Lo", ( _return.Lo ));
        //CPPTEST_POST_CONDITION_PTR("LongLong * _x ", ( _x ));
    }
}
/* CPPTEST_TEST_CASE_END test_LL_LongDivU32 */
