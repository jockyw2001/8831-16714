#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/msAPI_OSD_Resource.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/msAPI_OSD_Resource.c");

CPPTEST_TEST_SUITE(TestSuite_msAPI_OSD_Resoutce);
CPPTEST_TEST(TestSuite_msAPI_OSD_Resoutce_test_LoadCodemap);
CPPTEST_TEST(TestSuite_msAPI_OSD_Resoutce_test_MDrv_GE_GetFontInfo);
CPPTEST_TEST(TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_FreeBitmap);
CPPTEST_TEST(TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_FreeFont);
CPPTEST_TEST(TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_GetBBox_X);
CPPTEST_TEST(TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_GetBitmapInfo);
CPPTEST_TEST(TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_GetBitmapInfoGFX);
CPPTEST_TEST(TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_GetFontHeight);
CPPTEST_TEST(TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_GetFontInfo);
CPPTEST_TEST(TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_GetFontInfoGFX);
CPPTEST_TEST(TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_GetGlyphDispInfo);
CPPTEST_TEST(TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_LoadBitmap);
CPPTEST_TEST(TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_LoadFont);
CPPTEST_TEST(TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_SetFBFmt);
CPPTEST_TEST(TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_UnicodeToIndex);
CPPTEST_TEST_SUITE_END();


void TestSuite_msAPI_OSD_Resoutce_test_LoadCodemap();
void TestSuite_msAPI_OSD_Resoutce_test_MDrv_GE_GetFontInfo();
void TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_FreeBitmap();
void TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_FreeFont();
void TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_GetBBox_X();
void TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_GetBitmapInfo();
void TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_GetBitmapInfoGFX();
void TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_GetFontHeight();
void TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_GetFontInfo();
void TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_GetFontInfoGFX();
void TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_GetGlyphDispInfo();
void TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_LoadBitmap();
void TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_LoadFont();
void TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_SetFBFmt();
void TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_UnicodeToIndex();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_msAPI_OSD_Resoutce);

void TestSuite_msAPI_OSD_Resoutce_setUp()
{
}

void TestSuite_msAPI_OSD_Resoutce_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_LoadCodemap */
/* CPPTEST_TEST_CASE_CONTEXT void LoadCodemap(CHAR_CODEMAP_BLOCK *, U8 *) */
void TestSuite_msAPI_OSD_Resoutce_test_LoadCodemap()
{
    /* Pre-condition initialization */
	U8 u8Addr[6] = {1,1,1,1,1,1};
	CHAR_CODEMAP_BLOCK pCodeBlock = {0,0,0};
    /* Initializing argument 1 (pCodemapBlock) */
    CHAR_CODEMAP_BLOCK * _pCodemapBlock  = &pCodeBlock ;
    /* Initializing argument 2 (u32Addr) */
    U8 * _u32Addr  = u8Addr ;
    {
        /* Tested function call */
        LoadCodemap(_pCodemapBlock, _u32Addr);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(257,_pCodemapBlock->u16StartCode);
        CPPTEST_ASSERT_EQUAL(257,_pCodemapBlock->u16EndCode);
        CPPTEST_ASSERT_EQUAL(257,_pCodemapBlock->u16StartIndex);
        //CPPTEST_POST_CONDITION_PTR("CHAR_CODEMAP_BLOCK * _pCodemapBlock ", ( _pCodemapBlock ));
        //CPPTEST_POST_CONDITION_PTR("U8 * _u32Addr ", ( _u32Addr ));
    }
}
/* CPPTEST_TEST_CASE_END test_LoadCodemap */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_GE_GetFontInfo */
/* CPPTEST_TEST_CASE_CONTEXT OSDSRC_Result MDrv_GE_GetFontInfo(FONTHANDLE, FONT_INFO *) */
void TestSuite_msAPI_OSD_Resoutce_test_MDrv_GE_GetFontInfo()
{
    /* Pre-condition initialization */
	FONT_INFO pinfo = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    /* Initializing argument 1 (handle) */
    S8 _handle1  = 0;
    S8 _handle2  = -1;
    /* Initializing argument 2 (pinfo) */
    FONT_INFO * _pinfo  = &pinfo ;
    /* Initializing global variable _enResGroup */
    {
         _enResGroup  = E_RES_GROUP_1ST;
    }
    {
        /* Tested function call */
        OSDSRC_Result _return1  = MDrv_GE_GetFontInfo(_handle1, _pinfo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0, ( _return1 ) );
        //CPPTEST_POST_CONDITION_PTR("FONT_INFO * _pinfo ", ( _pinfo ));
        //CPPTEST_ASSERT_EQUAL( E_RES_GROUP_1ST, ( _enResGroup ) )
        OSDSRC_Result _return2  = MDrv_GE_GetFontInfo(_handle2, _pinfo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(6, ( _return2 ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_GE_GetFontInfo */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_OSD_RESOURCE_FreeBitmap */
/* CPPTEST_TEST_CASE_CONTEXT OSDSRC_Result msAPI_OSD_RESOURCE_FreeBitmap(BMPHANDLE) */
void TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_FreeBitmap()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (handle) */
    S16 _handle1  = 0;
    S16 _handle2  = -1;
    /* Initializing global variable _enResGroup */
    {
         _enResGroup  = E_RES_GROUP_1ST;
    }
    {
        /* Tested function call */
        OSDSRC_Result _return1  = msAPI_OSD_RESOURCE_FreeBitmap(_handle1);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 0, ( _return1 ) );

        OSDSRC_Result _return2  = msAPI_OSD_RESOURCE_FreeBitmap(_handle2);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 6, ( _return2 ) );
        //CPPTEST_ASSERT_EQUAL( E_RES_GROUP_1ST, ( _enResGroup ) )
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_OSD_RESOURCE_FreeBitmap */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_OSD_RESOURCE_FreeFont */
/* CPPTEST_TEST_CASE_CONTEXT OSDSRC_Result msAPI_OSD_RESOURCE_FreeFont(FONTHANDLE) */
void TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_FreeFont()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (handle) */
    S8 _handle1  = 0;
    S8 _handle2  = -1;
    /* Initializing global variable _enResGroup */
    {
         _enResGroup  = E_RES_GROUP_1ST;
    }
    {
        /* Tested function call */
        OSDSRC_Result _return1  = msAPI_OSD_RESOURCE_FreeFont(_handle1);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0, ( _return1) );

        OSDSRC_Result _return2  = msAPI_OSD_RESOURCE_FreeFont(_handle2);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(6, ( _return2) );
        //CPPTEST_ASSERT_EQUAL( E_RES_GROUP_1ST, ( _enResGroup ) )
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_OSD_RESOURCE_FreeFont */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_OSD_RESOURCE_GetBBox_X */
/* CPPTEST_TEST_CASE_CONTEXT OSDSRC_Result msAPI_OSD_RESOURCE_GetBBox_X(FONTHANDLE, MS_U16, OSDSRC_GLYPH_BBOX_X *) */
void TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_GetBBox_X()
{
    /* Pre-condition initialization */
	OSDSRC_GLYPH_BBOX_X pGlyphBBox_X = {0};
    /* Initializing argument 1 (handle) */
    S8 _handle1  = 0;
    S8 _handle2  = 1;
    /* Initializing argument 2 (u16Unicode) */
    MS_U16 _u16Unicode  = 0u;
    /* Initializing argument 3 (pGlyphBBox_X) */
    OSDSRC_GLYPH_BBOX_X * _pGlyphBBox_X  = &pGlyphBBox_X ;
    /* Initializing global variable _enResGroup */
    {
         _enResGroup  = E_RES_GROUP_1ST;
    }
    /* Initializing global variable g_au16CodemapBlock */
    {
         g_au16CodemapBlock.u16StartCode  = 1u;
         g_au16CodemapBlock.u16EndCode  = 10u;
         g_au16CodemapBlock.u16StartIndex  = 1u;
    }
    {
        /* Tested function call */
        OSDSRC_Result _return1  = msAPI_OSD_RESOURCE_GetBBox_X(_handle1, _u16Unicode, _pGlyphBBox_X);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 0, ( _return1 ) );
        CPPTEST_ASSERT_EQUAL( 0, ( _pGlyphBBox_X->u8Width ) );
        CPPTEST_ASSERT_EQUAL( 0, ( _pGlyphBBox_X->u8X0 ) );

        //OSDSRC_Result _return2  = msAPI_OSD_RESOURCE_GetBBox_X(_handle2, _u16Unicode, _pGlyphBBox_X);
        /* Post-condition check */
        //CPPTEST_ASSERT_EQUAL( 0, ( _return2 ) );
        //CPPTEST_ASSERT_EQUAL( 0, ( _pGlyphBBox_X->u8Width ) );
        //CPPTEST_ASSERT_EQUAL( 0, ( _pGlyphBBox_X->u8X0 ) );
        //CPPTEST_POST_CONDITION_PTR("OSDSRC_GLYPH_BBOX_X * _pGlyphBBox_X ", ( _pGlyphBBox_X ));
        //CPPTEST_ASSERT_EQUAL( E_RES_GROUP_1ST, ( _enResGroup ) )
        //CPPTEST_POST_CONDITION_UINTEGER("U16 g_au16CodemapBlock.u16StartCode", ( g_au16CodemapBlock.u16StartCode ));
        //CPPTEST_POST_CONDITION_UINTEGER("U16 g_au16CodemapBlock.u16EndCode", ( g_au16CodemapBlock.u16EndCode ));
        //CPPTEST_POST_CONDITION_UINTEGER("U16 g_au16CodemapBlock.u16StartIndex", ( g_au16CodemapBlock.u16StartIndex ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_OSD_RESOURCE_GetBBox_X */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_OSD_RESOURCE_GetBitmapInfo */
/* CPPTEST_TEST_CASE_CONTEXT OSDSRC_Result msAPI_OSD_RESOURCE_GetBitmapInfo(BMPHANDLE, OSD_RESOURCE_BITMAP_INFO *) */
void TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_GetBitmapInfo()
{
    /* Pre-condition initialization */
	OSD_RESOURCE_BITMAP_INFO pinfo = {0,0,0,0,0,0,0};
    /* Initializing argument 1 (handle) */
    S16 _handle1  = 0;
    S16 _handle2  = -1;
    /* Initializing argument 2 (pinfo) */
    OSD_RESOURCE_BITMAP_INFO * _pinfo  = &pinfo ;
    /* Initializing global variable _enResGroup */
    {
         _enResGroup  = E_RES_GROUP_1ST;
    }
    {
        /* Tested function call */
        OSDSRC_Result _return1  = msAPI_OSD_RESOURCE_GetBitmapInfo(_handle1, _pinfo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 0, ( _return1 ) );

        OSDSRC_Result _return2  = msAPI_OSD_RESOURCE_GetBitmapInfo(_handle2, _pinfo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 6, ( _return2 ) );
        //CPPTEST_POST_CONDITION_PTR("OSD_RESOURCE_BITMAP_INFO * _pinfo ", ( _pinfo ));
        //CPPTEST_ASSERT_EQUAL( E_RES_GROUP_1ST, ( _enResGroup ) )
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_OSD_RESOURCE_GetBitmapInfo */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_OSD_RESOURCE_GetBitmapInfoGFX */
/* CPPTEST_TEST_CASE_CONTEXT MS_U32 msAPI_OSD_RESOURCE_GetBitmapInfoGFX(BMPHANDLE, GFX_BitmapInfo *) */
void TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_GetBitmapInfoGFX()
{
    /* Pre-condition initialization */
	GFX_BitmapInfo pinfo = {0};
    /* Initializing argument 1 (handle) */
    S16 _handle1  = 0;
    S16 _handle2  = -1;
    /* Initializing argument 2 (pinfo) */
    GFX_BitmapInfo * _pinfo  = &pinfo ;
    /* Initializing global variable _enResGroup */
    {
         _enResGroup  = E_RES_GROUP_1ST;
    }
    {
        /* Tested function call */
        MS_U32 _return1  = msAPI_OSD_RESOURCE_GetBitmapInfoGFX(_handle1, _pinfo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0, ( _return1 ));

        MS_U32 _return2  = msAPI_OSD_RESOURCE_GetBitmapInfoGFX(_handle2, _pinfo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(6, ( _return2 ));
        //CPPTEST_POST_CONDITION_PTR("GFX_BitmapInfo * _pinfo ", ( _pinfo ));
        //CPPTEST_ASSERT_EQUAL( E_RES_GROUP_1ST, ( _enResGroup ) )
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_OSD_RESOURCE_GetBitmapInfoGFX */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_OSD_RESOURCE_GetFontHeight */
/* CPPTEST_TEST_CASE_CONTEXT U16 msAPI_OSD_RESOURCE_GetFontHeight(FONTHANDLE) */
void TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_GetFontHeight()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (font_handle) */
    S8 _font_handle1  = -1;
    S8 _font_handle2  = 0;
    /* Initializing global variable _enResGroup */
    {
         _enResGroup  = E_RES_GROUP_1ST;
    }
    {
        /* Tested function call */
        U16 _return1  = msAPI_OSD_RESOURCE_GetFontHeight(_font_handle1);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0, ( _return1 ));

        U16 _return2  = msAPI_OSD_RESOURCE_GetFontHeight(_font_handle2);
        //CPPTEST_ASSERT_EQUAL( E_RES_GROUP_1ST, ( _enResGroup ) )
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_OSD_RESOURCE_GetFontHeight */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_OSD_RESOURCE_GetFontInfo */
/* CPPTEST_TEST_CASE_CONTEXT OSDSRC_Result msAPI_OSD_RESOURCE_GetFontInfo(FONTHANDLE, OSD_RESOURCE_FONT_INFO *) */
void TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_GetFontInfo()
{
    /* Pre-condition initialization */
	OSD_RESOURCE_FONT_INFO pinfo = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    /* Initializing argument 1 (handle) */
    S8 _handle1  = 0;
    S8 _handle2  = -1;
    /* Initializing argument 2 (pinfo) */
    OSD_RESOURCE_FONT_INFO * _pinfo  = &pinfo ;
    /* Initializing global variable _enResGroup */
    {
         _enResGroup  = E_RES_GROUP_1ST;
    }
    {
        /* Tested function call */
        OSDSRC_Result _return1  = msAPI_OSD_RESOURCE_GetFontInfo(_handle1, _pinfo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0, ( _return1 ) );

        OSDSRC_Result _return2  = msAPI_OSD_RESOURCE_GetFontInfo(_handle2, _pinfo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(5, ( _return2 ) );
        //CPPTEST_POST_CONDITION_PTR("OSD_RESOURCE_FONT_INFO * _pinfo ", ( _pinfo ));
        //CPPTEST_ASSERT_EQUAL( E_RES_GROUP_1ST, ( _enResGroup ) )
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_OSD_RESOURCE_GetFontInfo */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_OSD_RESOURCE_GetFontInfoGFX */
/* CPPTEST_TEST_CASE_CONTEXT MS_U32 msAPI_OSD_RESOURCE_GetFontInfoGFX(FONTHANDLE, GFX_FontInfo *) */
void TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_GetFontInfoGFX()
{
    /* Pre-condition initialization */
	GFX_FontInfo pinfo = {0};
    /* Initializing argument 1 (handle) */
    S8 _handle1  = 0;
    S8 _handle2  = -1;
    /* Initializing argument 2 (pinfo) */
    GFX_FontInfo * _pinfo  = &pinfo ;
    /* Initializing global variable _enResGroup */
    {
         _enResGroup  = E_RES_GROUP_1ST;
    }
    {
        /* Tested function call */
        MS_U32 _return1  = msAPI_OSD_RESOURCE_GetFontInfoGFX(_handle1, _pinfo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0, ( _return1 ));

        MS_U32 _return2  = msAPI_OSD_RESOURCE_GetFontInfoGFX(_handle2, _pinfo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(5, ( _return2 ));
        //CPPTEST_POST_CONDITION_PTR("GFX_FontInfo * _pinfo ", ( _pinfo ));
        //CPPTEST_ASSERT_EQUAL( E_RES_GROUP_1ST, ( _enResGroup ) )
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_OSD_RESOURCE_GetFontInfoGFX */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_OSD_RESOURCE_GetGlyphDispInfo */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_OSD_RESOURCE_GetGlyphDispInfo(FONTHANDLE, U16, OSDSRC_GLYPH_DISP_INFO *) */
void TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_GetGlyphDispInfo()
{
    /* Pre-condition initialization */
	OSDSRC_GLYPH_DISP_INFO pGlyphDispInfo = {0};
    /* Initializing argument 1 (handle) */
    S8 _handle1  = 0;
    S8 _handle2  = 1;
    /* Initializing argument 2 (u16Unicode) */
    U16 _u16Unicode  = 0u;
    /* Initializing argument 3 (pGlyphDispInfo) */
    OSDSRC_GLYPH_DISP_INFO * _pGlyphDispInfo  = &pGlyphDispInfo;
    /* Initializing global variable _enResGroup */
    {
         _enResGroup  = E_RES_GROUP_1ST;
    }
    /* Initializing global variable g_au16CodemapBlock */
    {
         g_au16CodemapBlock.u16StartCode  = 0u;
         g_au16CodemapBlock.u16EndCode  = 0u;
         g_au16CodemapBlock.u16StartIndex  = 0u;
    }
    {
        /* Tested function call */
        msAPI_OSD_RESOURCE_GetGlyphDispInfo(_handle1, _u16Unicode, _pGlyphDispInfo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 0, ( _pGlyphDispInfo->u8Width ) );
        CPPTEST_ASSERT_EQUAL( 0, ( _pGlyphDispInfo->u8X0 ) );
        CPPTEST_ASSERT_EQUAL( 0, ( _pGlyphDispInfo->overlap_info.s8Xoffset) );
        CPPTEST_ASSERT_EQUAL( 0, ( _pGlyphDispInfo->overlap_info.s8Yoffset) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_OSD_RESOURCE_GetGlyphDispInfo */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_OSD_RESOURCE_LoadBitmap */
/* CPPTEST_TEST_CASE_CONTEXT BMPHANDLE msAPI_OSD_RESOURCE_LoadBitmap(MS_U32, MS_U32, MS_U32, MS_U32, BMP_Buffer_Format) */
void TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_LoadBitmap()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (addr) */
    MS_U32 _addr1  = 7ul;
    MS_U32 _addr2  = 8ul;
    /* Initializing argument 2 (len) */
    MS_U32 _len  = 0ul;
    /* Initializing argument 3 (width) */
    MS_U32 _width  = 0ul;
    /* Initializing argument 4 (height) */
    MS_U32 _height  = 0ul;
    /* Initializing argument 5 (fmt) */
    BMP_Buffer_Format _fmt1  = 0;
    BMP_Buffer_Format _fmt2  = 15;
    BMP_Buffer_Format _fmt3  = 4;
    BMP_Buffer_Format _fmt4  = 8;
    /* Initializing global variable _enResGroup */
    {
         _enResGroup  = E_RES_GROUP_1ST;
    }
    {
        /* Tested function call */
        BMPHANDLE _return1  = msAPI_OSD_RESOURCE_LoadBitmap(_addr2, _len, _width, _height, _fmt1);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(-1, ( _return1));

        BMPHANDLE _return2  = msAPI_OSD_RESOURCE_LoadBitmap(_addr1, _len, _width, _height, _fmt1);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(-1, ( _return2 ));

        BMPHANDLE _return3  = msAPI_OSD_RESOURCE_LoadBitmap(_addr2, _len, _width, _height, _fmt2);
        /* Post-condition check */
        //CPPTEST_ASSERT_EQUAL(1, ( _return3 ));
        BMPHANDLE _return4  = msAPI_OSD_RESOURCE_LoadBitmap(_addr2, _len, _width, _height, _fmt3);
        //CPPTEST_ASSERT_EQUAL(1, ( _return4 ));
        BMPHANDLE _return5  = msAPI_OSD_RESOURCE_LoadBitmap(_addr2, _len, _width, _height, _fmt4);
        //CPPTEST_ASSERT_EQUAL(1, ( _return5 ));
        //CPPTEST_ASSERT_EQUAL( E_RES_GROUP_1ST, ( _enResGroup ) );
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_OSD_RESOURCE_LoadBitmap */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_OSD_RESOURCE_LoadFont */
/* CPPTEST_TEST_CASE_CONTEXT FONTHANDLE msAPI_OSD_RESOURCE_LoadFont(MS_U32, MS_U32, MS_U32, MS_U32, MS_U16, MS_U16, MS_U8, MS_U8, MS_U8, MS_U16, MS_U32, MEMTYPE) */
void TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_LoadFont()
{
	/* Pre-condition initialization */
    /* Initializing argument 1 (start_addr) */
    MS_U32 _start_addr  = 10ul;
    /* Initializing argument 2 (glyph_addr) */
    MS_U32 _glyph_addr  = 10ul;
    /* Initializing argument 3 (bbox_addr) */
    MS_U32 _bbox_addr  = 10ul;
    /* Initializing argument 4 (codemap_addr) */
    MS_U32 _codemap_addr  = 10ul;
    /* Initializing argument 5 (u16char_num) */
    MS_U16 _u16char_num  = 10u;
    /* Initializing argument 6 (codemap_block_num) */
    MS_U16 _codemap_block_num  = 10u;
    /* Initializing argument 7 (width) */
    MS_U8 _width  = 10;
    /* Initializing argument 8 (height) */
    MS_U8 _height  = 10;
    /* Initializing argument 9 (bpp) */
    MS_U8 _bpp1  = 1;
    MS_U8 _bpp2  = 2;
    MS_U8 _bpp3  = 3;
    MS_U8 _bpp4  = 4;
    /* Initializing argument 10 (char_glyph_bytes) */
    MS_U16 _char_glyph_bytes1  = 10u;
    MS_U16 _char_glyph_bytes2  = 0u;
    /* Initializing argument 11 (pitch) */
    MS_U32 _pitch  = 10ul;
    /* Initializing argument 12 (memory_type) */
    MEMTYPE _memory_type  = MIU_FLASH;
    /* Initializing global variable _enResGroup */
    {
         _enResGroup  = E_RES_GROUP_1ST;
    }
    /* Initializing global variable GEFontTable */
    {
         GEFontTable.start_addr  = 0ul;
         GEFontTable.glyph_addr  = 0ul;
         GEFontTable.codemap_addr  = 0ul;
         GEFontTable.char_num  = 0u;
         GEFontTable.codemap_block_num  = 0u;
         GEFontTable.width  = 0;
         GEFontTable.pitch  = 0;
         GEFontTable.hw_pitch  = 0;
         GEFontTable.height  = 0;
         GEFontTable.bpp  = 0;
         GEFontTable.bbox_addr  = 0ul;
         GEFontTable.char_glyph_bytes  = 0u;
         GEFontTable.memory_type  = 0;
         GEFontTable.fmt  = BMP_FMT_I1;
         GEFontTable.inUsed  = 0ul;
    }
    /* Initializing global variable font_count */
    {
         font_count  = 0;
    }
    {
        /* Tested function call */
        FONTHANDLE _return1  = msAPI_OSD_RESOURCE_LoadFont(_start_addr, _glyph_addr, _bbox_addr, _codemap_addr, _u16char_num, _codemap_block_num, _width, _height, _bpp1, _char_glyph_bytes1, _pitch, _memory_type);
        /* Post-condition check */
        //CPPTEST_ASSERT_EQUAL(1, ( _return1 ));
        //CPPTEST_ASSERT_EQUAL( E_RES_GROUP_1ST, ( _enResGroup ) )
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.start_addr ));
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.glyph_addr ));
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.codemap_addr ));
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.char_num ));
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.codemap_block_num ));
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.width ));
        CPPTEST_ASSERT_EQUAL(1, ( GEFontTable.pitch ));
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.hw_pitch ));
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.height ));
        CPPTEST_ASSERT_EQUAL(1, ( GEFontTable.bpp ));
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.bbox_addr ));
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.char_glyph_bytes ));
        CPPTEST_ASSERT_EQUAL(0, ( GEFontTable.memory_type ));
        //CPPTEST_ASSERT_EQUAL( 0, ( GEFontTable.fmt ) )
        CPPTEST_ASSERT_EQUAL(1, ( GEFontTable.inUsed ));
        //CPPTEST_ASSERT_EQUAL(10, ( font_count ));


        FONTHANDLE _return2  = msAPI_OSD_RESOURCE_LoadFont(_start_addr, _glyph_addr, _bbox_addr, _codemap_addr, _u16char_num, _codemap_block_num, _width, _height, _bpp2, _char_glyph_bytes1, _pitch, _memory_type);
        /* Post-condition check */
		//CPPTEST_ASSERT_EQUAL(2, ( _return2 ));
		//CPPTEST_ASSERT_EQUAL( E_RES_GROUP_1ST, ( _enResGroup ) )
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.start_addr ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.glyph_addr ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.codemap_addr ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.char_num ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.codemap_block_num ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.width ));
		CPPTEST_ASSERT_EQUAL(2, ( GEFontTable.pitch ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.hw_pitch ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.height ));
		CPPTEST_ASSERT_EQUAL(2, ( GEFontTable.bpp ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.bbox_addr ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.char_glyph_bytes ));
		CPPTEST_ASSERT_EQUAL(0, ( GEFontTable.memory_type ));
		//CPPTEST_ASSERT_EQUAL( 1, ( GEFontTable.fmt ) )
		CPPTEST_ASSERT_EQUAL(1, ( GEFontTable.inUsed ));
		//CPPTEST_ASSERT_EQUAL(10, ( font_count ));

		FONTHANDLE _return3  = msAPI_OSD_RESOURCE_LoadFont(_start_addr, _glyph_addr, _bbox_addr, _codemap_addr, _u16char_num, _codemap_block_num, _width, _height, _bpp3, _char_glyph_bytes1, _pitch, _memory_type);
		/* Post-condition check */
		//CPPTEST_ASSERT_EQUAL(3, ( _return3 ));
		//CPPTEST_ASSERT_EQUAL( E_RES_GROUP_1ST, ( _enResGroup ) )
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.start_addr ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.glyph_addr ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.codemap_addr ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.char_num ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.codemap_block_num ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.width ));
		CPPTEST_ASSERT_EQUAL(1, ( GEFontTable.pitch ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.hw_pitch ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.height ));
		CPPTEST_ASSERT_EQUAL(3, ( GEFontTable.bpp ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.bbox_addr ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.char_glyph_bytes ));
		CPPTEST_ASSERT_EQUAL(0, ( GEFontTable.memory_type ));
		//CPPTEST_ASSERT_EQUAL( 1, ( GEFontTable.fmt ) )
		CPPTEST_ASSERT_EQUAL(1, ( GEFontTable.inUsed ));
		//CPPTEST_ASSERT_EQUAL(10, ( font_count ));

		FONTHANDLE _return4  = msAPI_OSD_RESOURCE_LoadFont(_start_addr, _glyph_addr, _bbox_addr, _codemap_addr, _u16char_num, _codemap_block_num, _width, _height, _bpp4, _char_glyph_bytes1, _pitch, _memory_type);
		/* Post-condition check */
		//CPPTEST_ASSERT_EQUAL(4, ( _return4));
		//CPPTEST_ASSERT_EQUAL( E_RES_GROUP_1ST, ( _enResGroup ) )
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.start_addr ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.glyph_addr ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.codemap_addr ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.char_num ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.codemap_block_num ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.width ));
		CPPTEST_ASSERT_EQUAL(4, ( GEFontTable.pitch ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.hw_pitch ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.height ));
		CPPTEST_ASSERT_EQUAL(4, ( GEFontTable.bpp ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.bbox_addr ));
		CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.char_glyph_bytes ));
		CPPTEST_ASSERT_EQUAL(0, ( GEFontTable.memory_type ));
		//CPPTEST_ASSERT_EQUAL( 2, ( GEFontTable.fmt ) )
		CPPTEST_ASSERT_EQUAL(1, ( GEFontTable.inUsed ));
		//CPPTEST_ASSERT_EQUAL(10, ( font_count ));

        FONTHANDLE _return5  = msAPI_OSD_RESOURCE_LoadFont(_start_addr, _glyph_addr, _bbox_addr, _codemap_addr, _u16char_num, _codemap_block_num, _width, _height, _bpp1, _char_glyph_bytes2, _pitch, _memory_type);
        /* Post-condition check */
        //CPPTEST_ASSERT_EQUAL(5, ( _return5 ));
        //CPPTEST_ASSERT_EQUAL( E_RES_GROUP_1ST, ( _enResGroup ) )
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.start_addr ));
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.glyph_addr ));
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.codemap_addr ));
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.char_num ));
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.codemap_block_num ));
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.width ));
        CPPTEST_ASSERT_EQUAL(1, ( GEFontTable.pitch ));
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.hw_pitch ));
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.height ));
        CPPTEST_ASSERT_EQUAL(1, ( GEFontTable.bpp ));
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.bbox_addr ));
        CPPTEST_ASSERT_EQUAL(100, ( GEFontTable.char_glyph_bytes ));
        CPPTEST_ASSERT_EQUAL(0, ( GEFontTable.memory_type ));
        //CPPTEST_ASSERT_EQUAL( 0, ( GEFontTable.fmt ) )
        CPPTEST_ASSERT_EQUAL(1, ( GEFontTable.inUsed ));
        //CPPTEST_ASSERT_EQUAL(10, ( font_count ));

        FONTHANDLE _return6  = msAPI_OSD_RESOURCE_LoadFont(_start_addr, _glyph_addr, _bbox_addr, _codemap_addr, _u16char_num, _codemap_block_num, _width, _height, _bpp3, _char_glyph_bytes2, _pitch, _memory_type);
        /* Post-condition check */
        //CPPTEST_ASSERT_EQUAL(6, ( _return1 ));
        //CPPTEST_ASSERT_EQUAL( E_RES_GROUP_1ST, ( _enResGroup ) )
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.start_addr ));
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.glyph_addr ));
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.codemap_addr ));
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.char_num ));
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.codemap_block_num ));
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.width ));
        CPPTEST_ASSERT_EQUAL(1, ( GEFontTable.pitch ));
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.hw_pitch ));
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.height ));
        CPPTEST_ASSERT_EQUAL(3, ( GEFontTable.bpp ));
        CPPTEST_ASSERT_EQUAL(10, ( GEFontTable.bbox_addr ));
        CPPTEST_ASSERT_EQUAL(300, ( GEFontTable.char_glyph_bytes ));
        CPPTEST_ASSERT_EQUAL(0, ( GEFontTable.memory_type ));
        //CPPTEST_ASSERT_EQUAL( 0, ( GEFontTable.fmt ) )
        CPPTEST_ASSERT_EQUAL(1, ( GEFontTable.inUsed ));
        //CPPTEST_ASSERT_EQUAL(10, ( font_count ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_OSD_RESOURCE_LoadFont */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_OSD_RESOURCE_SetFBFmt */
/* CPPTEST_TEST_CASE_CONTEXT MS_U32 msAPI_OSD_RESOURCE_SetFBFmt(MS_U16, MS_U32, MS_U16) */
void TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_SetFBFmt()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pitch) */
    MS_U16 _pitch  = 0u;
    /* Initializing argument 2 (addr) */
    MS_U32 _addr  = 0ul;
    /* Initializing argument 3 (fmt) */
    MS_U16 _fmt  = 0u;
    {
        /* Tested function call */
        MS_U32 _return  = msAPI_OSD_RESOURCE_SetFBFmt(_pitch, _addr, _fmt);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_OSD_RESOURCE_SetFBFmt */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_OSD_RESOURCE_UnicodeToIndex */
/* CPPTEST_TEST_CASE_CONTEXT U16 msAPI_OSD_RESOURCE_UnicodeToIndex(FONTHANDLE, MS_U16) */
void TestSuite_msAPI_OSD_Resoutce_test_msAPI_OSD_RESOURCE_UnicodeToIndex()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (handle) */
    S8 _handle  = 1;
    /* Initializing argument 2 (u16Unicode) */
    MS_U16 _u16Unicode  = 1u;
    /* Initializing global variable _enResGroup */
    {
         _enResGroup  = E_RES_GROUP_1ST;
    }
    /* Initializing global variable g_au16CodemapBlock */
    {
         g_au16CodemapBlock.u16StartCode  = 10u;
         g_au16CodemapBlock.u16EndCode  = 20u;
         g_au16CodemapBlock.u16StartIndex  = 10u;
    }
    {
        /* Tested function call */
        U16 _return  = msAPI_OSD_RESOURCE_UnicodeToIndex(_handle, _u16Unicode);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 1, ( _return ) );
        //CPPTEST_POST_CONDITION_UINTEGER("U16 _return", ( _return ));
        //CPPTEST_ASSERT_EQUAL( E_RES_GROUP_1ST, ( _enResGroup ) )
        //CPPTEST_POST_CONDITION_UINTEGER("U16 g_au16CodemapBlock.u16StartCode", ( g_au16CodemapBlock.u16StartCode ));
        //CPPTEST_POST_CONDITION_UINTEGER("U16 g_au16CodemapBlock.u16EndCode", ( g_au16CodemapBlock.u16EndCode ));
        //CPPTEST_POST_CONDITION_UINTEGER("U16 g_au16CodemapBlock.u16StartIndex", ( g_au16CodemapBlock.u16StartIndex ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_OSD_RESOURCE_UnicodeToIndex */
