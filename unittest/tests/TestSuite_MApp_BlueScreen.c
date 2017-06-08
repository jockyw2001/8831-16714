#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app/MApp_BlueScreen.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app/MApp_BlueScreen.c");

CPPTEST_TEST_SUITE(TestSuite_MApp_BlueScreen);
CPPTEST_TEST(TestSuite_MApp_BlueScreen_test_MApp_BlueScreen_ShowString);
CPPTEST_TEST(TestSuite_MApp_BlueScreen_test_MApp_BlueScreen_Init);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_MApp_BlueScreen_test_MApp_BlueScreen_ShowString();
void TestSuite_MApp_BlueScreen_test_MApp_BlueScreen_Init();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_MApp_BlueScreen);

void TestSuite_MApp_BlueScreen_setUp()
{
}

void TestSuite_MApp_BlueScreen_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_BlueScreen_ShowString */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_BlueScreen_ShowString(U16, U16, U32, U8 *) */
void TestSuite_MApp_BlueScreen_test_MApp_BlueScreen_ShowString()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (sX) */ 
    U16 _sX  = 10u;
    /* Initializing argument 2 (sY) */ 
    U16 _sY  = 20u;
    /* Initializing argument 3 (sColor) */ 
    U32 _sColor  = 30ul;
    /* Initializing argument 4 (pString) */ 
    U8 * _pString  = "Test";
    /* Initializing global variable clrBtn1 */ 
    {
         clrBtn1.x  = 0u;
         clrBtn1.y  = 0u;
         clrBtn1.width  = 0u;
         clrBtn1.height  = 0u;
         clrBtn1.radius  = 0u;
         clrBtn1.f_clr  = 0ul;
         clrBtn1.t_clr  = 0ul;
         clrBtn1.b_clr  = 0ul;
         clrBtn1.g_clr  = 0ul;
         clrBtn1.u8Gradient  = 0;
         clrBtn1.bStringIndexWidth  = CHAR_IDX_1BYTE;
         clrBtn1.enTextAlign  = EN_ALIGNMENT_DEFAULT;
         clrBtn1.fHighLight  = 0;
         clrBtn1.bFrameWidth  = 0;
    }
    {
        /* Tested function call */
        MApp_BlueScreen_ShowString(_sX, _sY, _sColor, _pString);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(_sX, ( clrBtn1.x ));
        CPPTEST_ASSERT_EQUAL(_sY, ( clrBtn1.y ));
        CPPTEST_ASSERT_EQUAL(UI_OSD_PANE_W, ( clrBtn1.width ));
        CPPTEST_ASSERT_EQUAL(28, ( clrBtn1.height ));
        CPPTEST_ASSERT_EQUAL(_sColor, ( clrBtn1.t_clr ));
        CPPTEST_ASSERT_EQUAL(EN_ALIGNMENT_LEFT, ( clrBtn1.enTextAlign ));
        CPPTEST_ASSERT_EQUAL(CHAR_IDX_2BYTE, ( clrBtn1.bStringIndexWidth ));
        CPPTEST_ASSERT_EQUAL(GEFONT_FLAG_VARWIDTH|GEFONT_FLAG_GAP, ( clrBtn1.Fontfmt.flag ));
        CPPTEST_ASSERT_EQUAL(1, ( clrBtn1.Fontfmt.ifont_gap ));
        CPPTEST_ASSERT_EQUAL(0, ( clrBtn1.bFrameWidth ));
        CPPTEST_ASSERT_EQUAL(FALSE, ( clrBtn1.fHighLight ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_BlueScreen_ShowString */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_BlueScreen_Init */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_BlueScreen_Init(void) */
void TestSuite_MApp_BlueScreen_test_MApp_BlueScreen_Init()
{
    /* Pre-condition initialization */
    /* Initializing global variable clrBtn1 */ 
    {
         clrBtn1.x  = 0u;
         clrBtn1.y  = 0u;
         clrBtn1.width  = 0u;
         clrBtn1.height  = 0u;
         clrBtn1.radius  = 0u;
         clrBtn1.f_clr  = 0ul;
         clrBtn1.t_clr  = 0ul;
         clrBtn1.b_clr  = 0ul;
         clrBtn1.g_clr  = 0ul;
         clrBtn1.u8Gradient  = 0;
         clrBtn1.bStringIndexWidth  = CHAR_IDX_1BYTE;
         clrBtn1.enTextAlign  = EN_ALIGNMENT_DEFAULT;
         clrBtn1.fHighLight  = 0;
         clrBtn1.bFrameWidth  = 0;
    }
    {
        /* Tested function call */
        MApp_BlueScreen_Init();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0, ( clrBtn1.x ));
        CPPTEST_ASSERT_EQUAL(0, ( clrBtn1.y ));
        CPPTEST_ASSERT_EQUAL(UI_OSD_PANE_H, ( clrBtn1.height ));
        CPPTEST_ASSERT_EQUAL(0xFF, ( clrBtn1.b_clr ));
        CPPTEST_ASSERT_EQUAL(0xFF00, ( clrBtn1.f_clr ));
        CPPTEST_ASSERT_EQUAL(CONSTANT_COLOR, ( clrBtn1.u8Gradient ));
        CPPTEST_ASSERT_EQUAL(0, ( clrBtn1.bFrameWidth ));
        CPPTEST_ASSERT_EQUAL(FALSE, ( clrBtn1.fHighLight ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_BlueScreen_Init */
