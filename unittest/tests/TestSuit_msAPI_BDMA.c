#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/msAPI_BDMA.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/msAPI_BDMA.c");

CPPTEST_TEST_SUITE(TestSuit_msAPI_BDMA);
CPPTEST_TEST(TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_MIU_FLASH2SDRAM);
CPPTEST_TEST(TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_MIU_SDRAM2SRAM);
CPPTEST_TEST(TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_MIU_SDRAM2SDRAM_I);
CPPTEST_TEST(TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_MIU_SDRAM2SDRAM);
CPPTEST_TEST(TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_MIU_SDRAM02SDRAM1);
CPPTEST_TEST(TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_MIU_SDRAM12SDRAM0);
CPPTEST_TEST(TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_MIU_SDRAM12SDRAM1);
CPPTEST_TEST(TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_MIU_FLASH2VDMCU);
CPPTEST_TEST(TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_default);
CPPTEST_TEST(TestSuit_msAPI_BDMA_test_MDrv_DMA_Copy_MIU_FLASH2SDRAM);
CPPTEST_TEST(TestSuit_msAPI_BDMA_test_MApi_BDMA_Copy_MIU_FLASH2VDMCU);
CPPTEST_TEST(TestSuit_msAPI_BDMA_test_MApi_BDMA_Copy_MIU_FLASH2SDRAM);
CPPTEST_TEST(TestSuit_msAPI_BDMA_test_MApi_BDMA_Copy_default);
CPPTEST_TEST(TestSuit_msAPI_BDMA_test_MApi_BDMA_XCopy_MCPY_LOADFONT);
CPPTEST_TEST(TestSuit_msAPI_BDMA_test_MApi_BDMA_XCopy_MCPY_LOADVDMCUFW);
CPPTEST_TEST(TestSuit_msAPI_BDMA_test_MApi_BDMA_XCopy_MCPY_LOADLOGO);
CPPTEST_TEST(TestSuit_msAPI_BDMA_test_MApi_BDMA_XCopy_MCPY_CCS);
CPPTEST_TEST(TestSuit_msAPI_BDMA_test_MApi_BDMA_XCopy_default);
CPPTEST_TEST(TestSuit_msAPI_BDMA_test_MDrv_DMA_LoadBin_LZSS_COMPRESS_ifno);
CPPTEST_TEST(TestSuit_msAPI_BDMA_test_MDrv_DMA_LoadBin_MS_COMPRESS_for_if_if);
CPPTEST_TEST(TestSuit_msAPI_BDMA_test_MDrv_DMA_LoadBin_default);
CPPTEST_TEST_SUITE_END();


void TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_MIU_FLASH2SDRAM();
void TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_MIU_SDRAM2SRAM();
void TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_MIU_SDRAM2SDRAM_I();
void TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_MIU_SDRAM2SDRAM();
void TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_MIU_SDRAM02SDRAM1();
void TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_MIU_SDRAM12SDRAM0();
void TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_MIU_SDRAM12SDRAM1();
void TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_MIU_FLASH2VDMCU();
void TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_default();
void TestSuit_msAPI_BDMA_test_MDrv_DMA_Copy_MIU_FLASH2SDRAM();
void TestSuit_msAPI_BDMA_test_MApi_BDMA_Copy_MIU_FLASH2VDMCU();
void TestSuit_msAPI_BDMA_test_MApi_BDMA_Copy_MIU_FLASH2SDRAM();
void TestSuit_msAPI_BDMA_test_MApi_BDMA_Copy_default();
void TestSuit_msAPI_BDMA_test_MApi_BDMA_XCopy_MCPY_LOADFONT();
void TestSuit_msAPI_BDMA_test_MApi_BDMA_XCopy_MCPY_LOADVDMCUFW();
void TestSuit_msAPI_BDMA_test_MApi_BDMA_XCopy_MCPY_LOADLOGO();
void TestSuit_msAPI_BDMA_test_MApi_BDMA_XCopy_MCPY_CCS();
void TestSuit_msAPI_BDMA_test_MApi_BDMA_XCopy_default();
void TestSuit_msAPI_BDMA_test_MDrv_DMA_LoadBin_LZSS_COMPRESS_ifno();
void TestSuit_msAPI_BDMA_test_MDrv_DMA_LoadBin_MS_COMPRESS_for_if_if();
void TestSuit_msAPI_BDMA_test_MDrv_DMA_LoadBin_default();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuit_msAPI_BDMA);

void TestSuit_msAPI_BDMA_setUp()
{
}

void TestSuit_msAPI_BDMA_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test__MApi_BDMA_Convert_Type_MIU_FLASH2SDRAM */
/* CPPTEST_TEST_CASE_CONTEXT BDMA_CpyType _MApi_BDMA_Convert_Type(MEMCOPYTYPE) */
void TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_MIU_FLASH2SDRAM()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eType) */
    MEMCOPYTYPE _eType  = MIU_FLASH2SDRAM;
    {
        /* Tested function call */
        BDMA_CpyType _return  = _MApi_BDMA_Convert_Type(_eType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_BDMA_FLASH2SDRAM, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApi_BDMA_Convert_Type_MIU_FLASH2SDRAM */

/* CPPTEST_TEST_CASE_BEGIN test__MApi_BDMA_Convert_Type_MIU_SDRAM2SRAM */
/* CPPTEST_TEST_CASE_CONTEXT BDMA_CpyType _MApi_BDMA_Convert_Type(MEMCOPYTYPE) */
void TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_MIU_SDRAM2SRAM()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eType) */
    MEMCOPYTYPE _eType  = MIU_SDRAM2SRAM;
    {
        /* Tested function call */
        BDMA_CpyType _return  = _MApi_BDMA_Convert_Type(_eType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_BDMA_SDRAM2SRAM1K_HK51, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApi_BDMA_Convert_Type_MIU_SDRAM2SRAM */

/* CPPTEST_TEST_CASE_BEGIN test__MApi_BDMA_Convert_Type_MIU_SDRAM2SDRAM_I */
/* CPPTEST_TEST_CASE_CONTEXT BDMA_CpyType _MApi_BDMA_Convert_Type(MEMCOPYTYPE) */
void TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_MIU_SDRAM2SDRAM_I()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eType) */
    MEMCOPYTYPE _eType  = MIU_SDRAM2SDRAM_I;
    {
        /* Tested function call */
        BDMA_CpyType _return  = _MApi_BDMA_Convert_Type(_eType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_BDMA_SDRAM2SDRAM, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApi_BDMA_Convert_Type_MIU_SDRAM2SDRAM_I */

/* CPPTEST_TEST_CASE_BEGIN test__MApi_BDMA_Convert_Type_MIU_SDRAM2SDRAM */
/* CPPTEST_TEST_CASE_CONTEXT BDMA_CpyType _MApi_BDMA_Convert_Type(MEMCOPYTYPE) */
void TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_MIU_SDRAM2SDRAM()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eType) */
    MEMCOPYTYPE _eType  = MIU_SDRAM2SDRAM;
    {
        /* Tested function call */
        BDMA_CpyType _return  = _MApi_BDMA_Convert_Type(_eType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_BDMA_SDRAM2SDRAM, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApi_BDMA_Convert_Type_MIU_SDRAM2SDRAM */

/* CPPTEST_TEST_CASE_BEGIN test__MApi_BDMA_Convert_Type_MIU_SDRAM02SDRAM1 */
/* CPPTEST_TEST_CASE_CONTEXT BDMA_CpyType _MApi_BDMA_Convert_Type(MEMCOPYTYPE) */
void TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_MIU_SDRAM02SDRAM1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eType) */
    MEMCOPYTYPE _eType  = MIU_SDRAM02SDRAM1;
    {
        /* Tested function call */
        BDMA_CpyType _return  = _MApi_BDMA_Convert_Type(_eType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_BDMA_SDRAM2SDRAM1, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApi_BDMA_Convert_Type_MIU_SDRAM02SDRAM1 */

/* CPPTEST_TEST_CASE_BEGIN test__MApi_BDMA_Convert_Type_MIU_SDRAM12SDRAM0 */
/* CPPTEST_TEST_CASE_CONTEXT BDMA_CpyType _MApi_BDMA_Convert_Type(MEMCOPYTYPE) */
void TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_MIU_SDRAM12SDRAM0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eType) */
    MEMCOPYTYPE _eType  = MIU_SDRAM12SDRAM0;
    {
        /* Tested function call */
        BDMA_CpyType _return  = _MApi_BDMA_Convert_Type(_eType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_BDMA_SDRAM12SDRAM, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApi_BDMA_Convert_Type_MIU_SDRAM12SDRAM0 */

/* CPPTEST_TEST_CASE_BEGIN test__MApi_BDMA_Convert_Type_MIU_SDRAM12SDRAM1 */
/* CPPTEST_TEST_CASE_CONTEXT BDMA_CpyType _MApi_BDMA_Convert_Type(MEMCOPYTYPE) */
void TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_MIU_SDRAM12SDRAM1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eType) */
    MEMCOPYTYPE _eType  = MIU_SDRAM12SDRAM1;
    {
        /* Tested function call */
        BDMA_CpyType _return  = _MApi_BDMA_Convert_Type(_eType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_BDMA_SDRAM12SDRAM1, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApi_BDMA_Convert_Type_MIU_SDRAM12SDRAM1 */

/* CPPTEST_TEST_CASE_BEGIN test__MApi_BDMA_Convert_Type_MIU_FLASH2VDMCU */
/* CPPTEST_TEST_CASE_CONTEXT BDMA_CpyType _MApi_BDMA_Convert_Type(MEMCOPYTYPE) */
void TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_MIU_FLASH2VDMCU()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eType) */
    MEMCOPYTYPE _eType  = MIU_FLASH2VDMCU;
    {
        /* Tested function call */
        BDMA_CpyType _return  = _MApi_BDMA_Convert_Type(_eType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_BDMA_FLASH2VDMCU, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApi_BDMA_Convert_Type_MIU_FLASH2VDMCU */

/* CPPTEST_TEST_CASE_BEGIN test__MApi_BDMA_Convert_Type_default */
/* CPPTEST_TEST_CASE_CONTEXT BDMA_CpyType _MApi_BDMA_Convert_Type(MEMCOPYTYPE) */
void TestSuit_msAPI_BDMA_test__MApi_BDMA_Convert_Type_default()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eType) */
    MEMCOPYTYPE _eType  = 0;
    {
        /* Tested function call */
        BDMA_CpyType _return  = _MApi_BDMA_Convert_Type(_eType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_BDMA_CPYTYPE_MAX, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test__MApi_BDMA_Convert_Type_default */


/* CPPTEST_TEST_CASE_BEGIN test_MDrv_DMA_Copy_MIU_FLASH2SDRAM */
/* CPPTEST_TEST_CASE_CONTEXT eRETCODE MDrv_DMA_Copy(U32, U32, U32, MEMCOPYTYPE) */
void TestSuit_msAPI_BDMA_test_MDrv_DMA_Copy_MIU_FLASH2SDRAM()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Srcaddr) */
    U32 _u32Srcaddr  = 0ul;
    /* Initializing argument 2 (u32Dstaddr) */
    U32 _u32Dstaddr  = 0ul;
    /* Initializing argument 3 (u32Len) */
    U32 _u32Len  = 0ul;
    /* Initializing argument 4 (eType) */
    MEMCOPYTYPE _eType  = MIU_FLASH2SDRAM;
    {
        /* Tested function call */
       eRETCODE _return ;// = MDrv_DMA_Copy(_u32Srcaddr, _u32Dstaddr, _u32Len, _eType);
        /* Post-condition check */
 //       CPPTEST_ASSERT_EQUAL( E_BDMA_OK, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_DMA_Copy_MIU_FLASH2SDRAM */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_BDMA_Copy_MIU_FLASH2VDMCU */
/* CPPTEST_TEST_CASE_CONTEXT BDMA_Result MApi_BDMA_Copy(MS_PHYADDR, MS_PHYADDR, U32, MEMCOPYTYPE) */
void TestSuit_msAPI_BDMA_test_MApi_BDMA_Copy_MIU_FLASH2VDMCU()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Srcaddr) */
    MS_PHYADDR _u32Srcaddr  = 0ul;
    /* Initializing argument 2 (u32Dstaddr) */
    MS_PHYADDR _u32Dstaddr  = 0ul;
    /* Initializing argument 3 (u32Len) */
    U32 _u32Len  = 0ul;
    /* Initializing argument 4 (eType) */
    MEMCOPYTYPE _eType  = MIU_FLASH2VDMCU;
    {
        /* Tested function call */
        BDMA_Result _return = MApi_BDMA_Copy(_u32Srcaddr, _u32Dstaddr, _u32Len, _eType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_BDMA_OK, ( _return ) )
    }
}

void TestSuit_msAPI_BDMA_test_MApi_BDMA_Copy_MIU_FLASH2SDRAM()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Srcaddr) */
    MS_PHYADDR _u32Srcaddr  = 0ul;
    /* Initializing argument 2 (u32Dstaddr) */
    MS_PHYADDR _u32Dstaddr  = 0ul;
    /* Initializing argument 3 (u32Len) */
    U32 _u32Len  = 0ul;
    /* Initializing argument 4 (eType) */
    MEMCOPYTYPE _eType  = MIU_FLASH2SDRAM;
    {
        /* Tested function call */
        BDMA_Result _return = MApi_BDMA_Copy(_u32Srcaddr, _u32Dstaddr, _u32Len, _eType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_BDMA_OK, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_BDMA_Copy_MIU_FLASH2VDMCU */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_BDMA_Copy_default */
/* CPPTEST_TEST_CASE_CONTEXT BDMA_Result MApi_BDMA_Copy(MS_PHYADDR, MS_PHYADDR, U32, MEMCOPYTYPE) */
void TestSuit_msAPI_BDMA_test_MApi_BDMA_Copy_default()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Srcaddr) */
    MS_PHYADDR _u32Srcaddr  = 0ul;
    /* Initializing argument 2 (u32Dstaddr) */
    MS_PHYADDR _u32Dstaddr  = 0ul;
    /* Initializing argument 3 (u32Len) */
    U32 _u32Len  = 0ul;
    /* Initializing argument 4 (eType) */
    MEMCOPYTYPE _eType  = 0;
    {
        /* Tested function call */
        BDMA_Result _return  = MApi_BDMA_Copy(_u32Srcaddr, _u32Dstaddr, _u32Len, _eType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_BDMA_OK, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_BDMA_Copy_default */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_BDMA_XCopy_MCPY_LOADFONT */
/* CPPTEST_TEST_CASE_CONTEXT BDMA_Result MApi_BDMA_XCopy(MCPY_TYPE, U32, U32, U32) */
void TestSuit_msAPI_BDMA_test_MApi_BDMA_XCopy_MCPY_LOADFONT()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eType) */
    MCPY_TYPE _eType  = MCPY_LOADFONT;
    /* Initializing argument 2 (u32Srcaddr) */
    U32 _u32Srcaddr  = 0ul;
    /* Initializing argument 3 (u32Dstaddr) */
    U32 _u32Dstaddr  = 0ul;
    /* Initializing argument 4 (u32Len) */
    U32 _u32Len  = 0ul;
    {
    }
    {
        /* Tested function call */
        BDMA_Result _return  = MApi_BDMA_XCopy(_eType, _u32Srcaddr, _u32Dstaddr, _u32Len);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_BDMA_OK, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_BDMA_XCopy_MCPY_LOADFONT */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_BDMA_Copy_MCPY_LOADVDMCUFW */
/* CPPTEST_TEST_CASE_CONTEXT BDMA_Result MApi_BDMA_Copy(MS_PHYADDR, MS_PHYADDR, U32, MEMCOPYTYPE) */
void TestSuit_msAPI_BDMA_test_MApi_BDMA_XCopy_MCPY_LOADVDMCUFW()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eType) */
    MCPY_TYPE _eType  = MCPY_LOADVDMCUFW;
    /* Initializing argument 2 (u32Srcaddr) */
    U32 _u32Srcaddr  = 0ul;
    /* Initializing argument 3 (u32Dstaddr) */
    U32 _u32Dstaddr  = 0ul;
    /* Initializing argument 4 (u32Len) */
    U32 _u32Len  = 0ul;
    {
    }
    {
        /* Tested function call */
        BDMA_Result _return  = MApi_BDMA_XCopy(_eType, _u32Srcaddr, _u32Dstaddr, _u32Len);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_BDMA_OK, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_BDMA_Copy_MCPY_LOADVDMCUFW */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_BDMA_Copy_MCPY_LOADLOGO */
/* CPPTEST_TEST_CASE_CONTEXT BDMA_Result MApi_BDMA_Copy(MS_PHYADDR, MS_PHYADDR, U32, MEMCOPYTYPE) */
void TestSuit_msAPI_BDMA_test_MApi_BDMA_XCopy_MCPY_LOADLOGO()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eType) */
    MCPY_TYPE _eType  = MCPY_LOADLOGO;
    /* Initializing argument 2 (u32Srcaddr) */
    U32 _u32Srcaddr  = 0ul;
    /* Initializing argument 3 (u32Dstaddr) */
    U32 _u32Dstaddr  = 0ul;
    /* Initializing argument 4 (u32Len) */
    U32 _u32Len  = 0ul;
    {
    }
    {
        /* Tested function call */
        BDMA_Result _return  = MApi_BDMA_XCopy(_eType, _u32Srcaddr, _u32Dstaddr, _u32Len);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_BDMA_OK, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_BDMA_Copy_MCPY_LOADLOGO */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_BDMA_Copy_MCPY_CCS */
/* CPPTEST_TEST_CASE_CONTEXT BDMA_Result MApi_BDMA_Copy(MS_PHYADDR, MS_PHYADDR, U32, MEMCOPYTYPE) */
void TestSuit_msAPI_BDMA_test_MApi_BDMA_XCopy_MCPY_CCS()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eType) */
    MCPY_TYPE _eType  = MCPY_CCS;
    /* Initializing argument 2 (u32Srcaddr) */
    U32 _u32Srcaddr  = 0ul;
    /* Initializing argument 3 (u32Dstaddr) */
    U32 _u32Dstaddr  = 0ul;
    /* Initializing argument 4 (u32Len) */
    U32 _u32Len  = 0ul;
    {
    }
    {
        /* Tested function call */
        BDMA_Result _return  = MApi_BDMA_XCopy(_eType, _u32Srcaddr, _u32Dstaddr, _u32Len);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_BDMA_OK, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_BDMA_Copy_MCPY_CCS */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_BDMA_XCopy_default */
/* CPPTEST_TEST_CASE_CONTEXT BDMA_Result MApi_BDMA_Copy(MS_PHYADDR, MS_PHYADDR, U32, MEMCOPYTYPE) */
void TestSuit_msAPI_BDMA_test_MApi_BDMA_XCopy_default()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Srcaddr) */
    MS_PHYADDR _u32Srcaddr  = 0ul;
    /* Initializing argument 2 (u32Dstaddr) */
    MS_PHYADDR _u32Dstaddr  = 0ul;
    /* Initializing argument 3 (u32Len) */
    U32 _u32Len  = 0ul;
    /* Initializing argument 4 (eType) */
    MEMCOPYTYPE _eType  = 0;
    {
        /* Tested function call */
        BDMA_Result _return  = MApi_BDMA_XCopy(_u32Srcaddr, _u32Dstaddr, _u32Len, _eType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_BDMA_OK, ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_BDMA_XCopy_default */


/* CPPTEST_TEST_CASE_BEGIN test_MDrv_DMA_LoadBin_LZSS_COMPRESS_ifno */
/* CPPTEST_TEST_CASE_CONTEXT eRETCODE MDrv_DMA_LoadBin(BININFO *, U32, U32, U32) */
void TestSuit_msAPI_BDMA_test_MDrv_DMA_LoadBin_LZSS_COMPRESS_ifno()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pBinInfo) */
	BININFO tmp;
    BININFO * _pBinInfo  = 0 ;
    _pBinInfo = &tmp;
    _pBinInfo->B_IsComp = LZSS_COMPRESS;
    /* Initializing argument 2 (u32DstVA) */
    U32 _u32DstVA  = 0ul;
    /* Initializing argument 3 (u32DecVA) */
    U32 _u32DecVA  = 0ul;
    /* Initializing argument 4 (u32TmpVA) */
    U32 _u32TmpVA  = 0ul;
    {
    }
    /* Initializing global variable DoDecompressionFunc */
    {
         DoDecompressionFunc  = 0 ;
    }
    {
        /* Tested function call */
        eRETCODE _return  = MDrv_DMA_LoadBin(_pBinInfo, _u32DstVA, _u32DecVA, _u32TmpVA);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( SUCCESS, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_DMA_LoadBin_LZSS_COMPRESS_ifno */


/* CPPTEST_TEST_CASE_BEGIN test_MDrv_DMA_LoadBin_MS_COMPRESS_for_if_if */
/* CPPTEST_TEST_CASE_CONTEXT eRETCODE MDrv_DMA_LoadBin(BININFO *, U32, U32, U32) */
void TestSuit_msAPI_BDMA_test_MDrv_DMA_LoadBin_MS_COMPRESS_for_if_if()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pBinInfo) */
    BININFO * _pBinInfo  = 0 ;
    BININFO tmp;
    _pBinInfo = &tmp;
    _pBinInfo->B_IsComp = MS_COMPRESS;
    /* Initializing argument 2 (u32DstVA) */
    U32 _u32DstVA  = 0ul;
    /* Initializing argument 3 (u32DecVA) */
    U32 _u32DecVA  = 0ul;
    /* Initializing argument 4 (u32TmpVA) */
    U32 _u32TmpVA  = 0ul;
    {
    }
    /* Initializing global variable DoDecompressionFunc */
    {
         DoDecompressionFunc  = 0 ;
    }
    {
        /* Tested function call */
        eRETCODE _return  = MDrv_DMA_LoadBin(_pBinInfo, _u32DstVA, _u32DecVA, _u32TmpVA);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( SUCCESS, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_DMA_LoadBin_MS_COMPRESS_for_if_if */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_DMA_LoadBin_default */
/* CPPTEST_TEST_CASE_CONTEXT eRETCODE MDrv_DMA_LoadBin(BININFO *, U32, U32, U32) */
void TestSuit_msAPI_BDMA_test_MDrv_DMA_LoadBin_default()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pBinInfo) */
    BININFO * _pBinInfo  = 0 ;
    BININFO tmp;
    _pBinInfo = &tmp;
    _pBinInfo->B_IsComp = SLZ_COMPRESS;
    /* Initializing argument 2 (u32DstVA) */
    U32 _u32DstVA  = 0ul;
    /* Initializing argument 3 (u32DecVA) */
    U32 _u32DecVA  = 0ul;
    /* Initializing argument 4 (u32TmpVA) */
    U32 _u32TmpVA  = 0ul;
    {
    }
    /* Initializing global variable DoDecompressionFunc */
    {
         DoDecompressionFunc  = 0 ;
    }
    {
        /* Tested function call */
        eRETCODE _return  = MDrv_DMA_LoadBin(_pBinInfo, _u32DstVA, _u32DecVA, _u32TmpVA);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( SUCCESS, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_DMA_LoadBin_default */
