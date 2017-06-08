#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/msAPI_OSD2.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/msAPI_OSD2.c");

CPPTEST_TEST_SUITE(TestSuite_msAPI_OSD2);
CPPTEST_TEST(TestSuite_msAPI_OSD2_test_setGradientInfo_);
CPPTEST_TEST(TestSuite_msAPI_OSD2_test_getColorByHight_);
CPPTEST_TEST(TestSuite_msAPI_OSD2_test_msAPI_OSD_CopyRegion);
CPPTEST_TEST(TestSuite_msAPI_OSD2_test_msAPI_OSD_DrawGradientRoundBlock);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_msAPI_OSD2_test_setGradientInfo_();
void TestSuite_msAPI_OSD2_test_getColorByHight_();
void TestSuite_msAPI_OSD2_test_msAPI_OSD_CopyRegion();
void TestSuite_msAPI_OSD2_test_msAPI_OSD_DrawGradientRoundBlock();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_msAPI_OSD2);

void TestSuite_msAPI_OSD2_setUp()
{
}

void TestSuite_msAPI_OSD2_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_setGradientInfo_ */
/* CPPTEST_TEST_CASE_CONTEXT void setGradientInfo_(U32, U32, U16) */
void TestSuite_msAPI_OSD2_test_setGradientInfo_()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bc) */ 
    U32 _bc  = 1ul;
    /* Initializing argument 2 (gc) */ 
    U32 _gc  = 1ul;
    /* Initializing argument 3 (h) */ 
    U16 _h  = 1u;
    /* Initializing global variable s32OR */ 
    {
         s32OR  = 0L;
    }
    /* Initializing global variable s32OG */ 
    {
         s32OG  = 0L;
    }
    /* Initializing global variable s32OB */ 
    {
         s32OB  = 0L;
    }
    /* Initializing global variable s32DR */ 
    {
         s32DR  = 0L;
    }
    /* Initializing global variable s32DG */ 
    {
         s32DG  = 0L;
    }
    /* Initializing global variable s32DB */ 
    {
         s32DB  = 0L;
    }
    /* Initializing global variable u16GrdHight */ 
    {
         u16GrdHight  = 0u;
    }
    {
        /* Tested function call */
        setGradientInfo_(_bc, _gc, _h);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0, ( s32OR ));
        CPPTEST_ASSERT_EQUAL(0, ( s32OG ));
        CPPTEST_ASSERT_EQUAL(1, ( s32OB ));
        CPPTEST_ASSERT_EQUAL(0, ( s32DR ));
        CPPTEST_ASSERT_EQUAL(0, ( s32DG ));
        CPPTEST_ASSERT_EQUAL(0, ( s32DB ));
        CPPTEST_ASSERT_EQUAL(1, ( u16GrdHight ));
    }
}
/* CPPTEST_TEST_CASE_END test_setGradientInfo_ */

/* CPPTEST_TEST_CASE_BEGIN test_getColorByHight_ */
/* CPPTEST_TEST_CASE_CONTEXT U32 getColorByHight_(U16) */
void TestSuite_msAPI_OSD2_test_getColorByHight_()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16H) */ 
    U16 _u16H  = 1u;
    /* Initializing global variable s32OR */ 
    {
         s32OR  = 0L;
    }
    /* Initializing global variable s32OG */ 
    {
         s32OG  = 0L;
    }
    /* Initializing global variable s32OB */ 
    {
         s32OB  = 0L;
    }
    /* Initializing global variable s32DR */ 
    {
         s32DR  = 0L;
    }
    /* Initializing global variable s32DG */ 
    {
         s32DG  = 0L;
    }
    /* Initializing global variable s32DB */ 
    {
         s32DB  = 0L;
    }
    /* Initializing global variable u16GrdHight */ 
    {
         u16GrdHight  = 1u;
    }
    {
        /* Tested function call */
        U32 _return  = getColorByHight_(_u16H);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0xFF000000, ( _return ));
        CPPTEST_ASSERT_EQUAL(0, ( s32OR ));
        CPPTEST_ASSERT_EQUAL(0, ( s32OG ));
        CPPTEST_ASSERT_EQUAL(0, ( s32OB ));
        CPPTEST_ASSERT_EQUAL(0, ( s32DR ));
        CPPTEST_ASSERT_EQUAL(0, ( s32DG ));
        CPPTEST_ASSERT_EQUAL(0, ( s32DB ));
        CPPTEST_ASSERT_EQUAL(1, ( u16GrdHight ));
    }
}
/* CPPTEST_TEST_CASE_END test_getColorByHight_ */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_OSD_CopyRegion */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_OSD_CopyRegion(MSAPI_OSDRegion *, MSAPI_OSDRegion *) */
void TestSuite_msAPI_OSD2_test_msAPI_OSD_CopyRegion()
{
    /* Pre-condition initialization */
	MSAPI_OSDRegion src = {1,1,1,1,1};
	MSAPI_OSDRegion dst = {1,1,1,1,1};
    /* Initializing argument 1 (src) */ 
    MSAPI_OSDRegion * _src  = &src ;
    /* Initializing argument 2 (dst) */ 
    MSAPI_OSDRegion * _dst  = &dst ;
    {
        /* Tested function call */
        U8 _return  = msAPI_OSD_CopyRegion(_src, _dst);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0, ( _return ));
        //CPPTEST_POST_CONDITION_PTR("MSAPI_OSDRegion * _src ", ( _src ));
        //CPPTEST_POST_CONDITION_PTR("MSAPI_OSDRegion * _dst ", ( _dst ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_OSD_CopyRegion */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_OSD_DrawGradientRoundBlock */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_OSD_DrawGradientRoundBlock(OSDClrBtn *) */
void TestSuite_msAPI_OSD2_test_msAPI_OSD_DrawGradientRoundBlock()
{
    /* Pre-condition initialization */
	OSDClrBtn clrBtn = {1,1,2,2,1,1,1,1,1,1,0,0,0,1};
    /* Initializing argument 1 (pclrBtn) */ 
    OSDClrBtn * _pclrBtn  = &clrBtn ;
    /* Initializing global variable s32OR */ 
    {
         s32OR  = 0L;
    }
    /* Initializing global variable s32OG */ 
    {
         s32OG  = 0L;
    }
    /* Initializing global variable s32OB */ 
    {
         s32OB  = 0L;
    }
    /* Initializing global variable s32DR */ 
    {
         s32DR  = 0L;
    }
    /* Initializing global variable s32DG */ 
    {
         s32DG  = 0L;
    }
    /* Initializing global variable s32DB */ 
    {
         s32DB  = 0L;
    }
    /* Initializing global variable u16GrdHight */ 
    {
         u16GrdHight  = 0u;
    }
    /* Initializing global variable u16Temp5 */ 
    {
         u16Temp5  = 0u;
    }
    /* Initializing global variable y */ 
    {
         y  = 0u;
    }
    /* Initializing global variable x */ 
    {
         x  = 0u;
    }
    /* Initializing global variable u16Temp1 */ 
    {
         u16Temp1  = 0u;
    }
    /* Initializing global variable u16Temp2 */ 
    {
         u16Temp2  = 0u;
    }
    /* Initializing global variable u16Temp3 */ 
    {
         u16Temp3  = 0u;
    }
    /* Initializing global variable u16Temp4 */ 
    {
         u16Temp4  = 0u;
    }
    /* Initializing global variable last_y */ 
    {
         last_y  = 0u;
    }
    {
        /* Tested function call */
        msAPI_OSD_DrawGradientRoundBlock(_pclrBtn);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_PTR("OSDClrBtn * _pclrBtn ", ( _pclrBtn ));
        CPPTEST_ASSERT_EQUAL(0, ( s32OR ));
        CPPTEST_ASSERT_EQUAL(0, ( s32OG ));
        CPPTEST_ASSERT_EQUAL(0, ( s32OB ));
        CPPTEST_ASSERT_EQUAL(0, ( s32DR ));
        CPPTEST_ASSERT_EQUAL(0, ( s32DG ));
        CPPTEST_ASSERT_EQUAL(0, ( s32DB ));
        CPPTEST_ASSERT_EQUAL(0, ( u16GrdHight ));
        //CPPTEST_ASSERT_EQUAL(4, ( u16Temp5 ));
        //CPPTEST_ASSERT_EQUAL(1, ( y ));
        //CPPTEST_ASSERT_EQUAL(1, ( x ));
        CPPTEST_ASSERT_EQUAL(1, ( u16Temp1 ));
        CPPTEST_ASSERT_EQUAL(1, ( u16Temp2 ));
        CPPTEST_ASSERT_EQUAL(2, ( u16Temp3 ));
        CPPTEST_ASSERT_EQUAL(2, ( u16Temp4 ));
        //CPPTEST_ASSERT_EQUAL(1, ( last_y ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_OSD_DrawGradientRoundBlock */
