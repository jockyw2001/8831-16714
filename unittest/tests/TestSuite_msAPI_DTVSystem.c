#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/msAPI_DTVSystem.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/msAPI_DTVSystem.c");

CPPTEST_TEST_SUITE(TestSuite_msAPI_DTVSystem);
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_IsVersionValid_Default_Version);
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_IsVersionValid_cVersion_31);
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_IsVersionValid_cVersion_32);
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_IsVersionValid_cVersion_1);
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_LessThen_0x0001);
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_Equals_0x0001);
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_Equals_0x0005);
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_Equals_0x0010);
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_Equals_0x0200);
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_Equals_0x1FFF);
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_GreaterThen_0x1FFF);
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_IsVideoPIDValid_wVideo_PID_LessThen_0x000F);
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_IsVideoPIDValid_wVideo_PID_Equals_0x000F);
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_IsVideoPIDValid_wVideo_PID_Equals_0x1000);
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_IsVideoPIDValid_wVideo_PID_Equals_0x1FFF);
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_IsVideoPIDValid_wVideo_PID_GreaterThan_0x1FFF);
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_Equals_0x0002);
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_Equals_0x000F);
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_IsVideoPIDValid_wVideo_PID_Equals_0x0010);
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_IsVideoPIDValid_wVideo_PID_Equals_0x1FFE);
/*
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_msAPI_CM_SaveServiceListInfo_if);
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_msAPI_CM_GetCurrentServiceListID);
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_msAPI_CM_GetExistServiceListInfo);*/
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_msAPI_CM_CountProgram_ServiceTypeInvalid);
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_msAPI_CM_CountProgram_Visible_Only);
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_msAPI_CM_CountProgram_Not_Visible_Also);
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_msAPI_CM_CountProgram_All);
CPPTEST_TEST(TestSuite_msAPI_DTVSystem_test_msAPI_CM_CountProgram_Other);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_msAPI_DTVSystem_test_IsVersionValid_Default_Version();
void TestSuite_msAPI_DTVSystem_test_IsVersionValid_cVersion_31();
void TestSuite_msAPI_DTVSystem_test_IsVersionValid_cVersion_32();
void TestSuite_msAPI_DTVSystem_test_IsVersionValid_cVersion_1();
void TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_LessThen_0x0001();
void TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_Equals_0x0001();
void TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_Equals_0x0005();
void TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_Equals_0x0010();
void TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_Equals_0x0200();
void TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_Equals_0x1FFF();
void TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_GreaterThen_0x1FFF();
void TestSuite_msAPI_DTVSystem_test_IsVideoPIDValid_wVideo_PID_LessThen_0x000F();
void TestSuite_msAPI_DTVSystem_test_IsVideoPIDValid_wVideo_PID_Equals_0x000F();
void TestSuite_msAPI_DTVSystem_test_IsVideoPIDValid_wVideo_PID_Equals_0x1000();
void TestSuite_msAPI_DTVSystem_test_IsVideoPIDValid_wVideo_PID_Equals_0x1FFF();
void TestSuite_msAPI_DTVSystem_test_IsVideoPIDValid_wVideo_PID_GreaterThan_0x1FFF();
void TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_Equals_0x0002();
void TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_Equals_0x000F();
void TestSuite_msAPI_DTVSystem_test_IsVideoPIDValid_wVideo_PID_Equals_0x0010();
void TestSuite_msAPI_DTVSystem_test_IsVideoPIDValid_wVideo_PID_Equals_0x1FFE();
/*
void TestSuite_msAPI_DTVSystem_test_msAPI_CM_SaveServiceListInfo_if();
void TestSuite_msAPI_DTVSystem_test_msAPI_CM_GetCurrentServiceListID();
void TestSuite_msAPI_DTVSystem_test_msAPI_CM_GetExistServiceListInfo();*/
void TestSuite_msAPI_DTVSystem_test_msAPI_CM_CountProgram_ServiceTypeInvalid();
void TestSuite_msAPI_DTVSystem_test_msAPI_CM_CountProgram_Visible_Only();
void TestSuite_msAPI_DTVSystem_test_msAPI_CM_CountProgram_Not_Visible_Also();
void TestSuite_msAPI_DTVSystem_test_msAPI_CM_CountProgram_All();
void TestSuite_msAPI_DTVSystem_test_msAPI_CM_CountProgram_Other();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_msAPI_DTVSystem);

void TestSuite_msAPI_DTVSystem_setUp()
{
}

void TestSuite_msAPI_DTVSystem_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_IsVersionValid_Default_Version */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsVersionValid(BYTE) */
void TestSuite_msAPI_DTVSystem_test_IsVersionValid_Default_Version()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (cVersion) */ 
    BYTE _cVersion  = 0xFF;
    {
        /* Tested function call */
        BOOLEAN _return  = IsVersionValid(_cVersion);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_IsVersionValid_Default_Version */

/* CPPTEST_TEST_CASE_BEGIN test_IsVersionValid_cVersion_31 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsVersionValid(BYTE) */
void TestSuite_msAPI_DTVSystem_test_IsVersionValid_cVersion_31()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (cVersion) */ 
    BYTE _cVersion  = 31;
    {
        /* Tested function call */
        BOOLEAN _return  = IsVersionValid(_cVersion);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_IsVersionValid_cVersion_31 */

/* CPPTEST_TEST_CASE_BEGIN test_IsVersionValid_cVersion_1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsVersionValid(BYTE) */
void TestSuite_msAPI_DTVSystem_test_IsVersionValid_cVersion_1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (cVersion) */
    BYTE _cVersion  = 1;
    {
        /* Tested function call */
        BOOLEAN _return  = IsVersionValid(_cVersion);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_IsVersionValid_cVersion_1 */

/* CPPTEST_TEST_CASE_BEGIN test_IsVersionValid_cVersion_32 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsVersionValid(BYTE) */
void TestSuite_msAPI_DTVSystem_test_IsVersionValid_cVersion_32()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (cVersion) */
    BYTE _cVersion  = 32;
    {
        /* Tested function call */
        BOOLEAN _return  = IsVersionValid(_cVersion);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_IsVersionValid_cVersion_32 */


/* CPPTEST_TEST_CASE_BEGIN test_IsPCR_PIDValid_wPCR_PID_LessThen_0x0001 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsPCR_PIDValid(WORD) */
void TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_LessThen_0x0001()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wPCR_PID) */ 
    WORD _wPCR_PID  = 0u;
    {
        /* Tested function call */
        BOOLEAN _return  = IsPCR_PIDValid(_wPCR_PID);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_IsPCR_PIDValid_wPCR_PID_LessThen_0x0001 */

/* CPPTEST_TEST_CASE_BEGIN test_IsPCR_PIDValid_wPCR_PID_Equals_0x0001 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsPCR_PIDValid(WORD) */
void TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_Equals_0x0001()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wPCR_PID) */ 
    WORD _wPCR_PID  = 0x0001;
    {
        /* Tested function call */
        BOOLEAN _return  = IsPCR_PIDValid(_wPCR_PID);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_IsPCR_PIDValid_wPCR_PID_Equals_0x0001 */

/* CPPTEST_TEST_CASE_BEGIN test_IsPCR_PIDValid_wPCR_PID_Equals_0x0005 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsPCR_PIDValid(WORD) */
void TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_Equals_0x0005()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wPCR_PID) */ 
    WORD _wPCR_PID  = 0x0005;
    {
        /* Tested function call */
        BOOLEAN _return  = IsPCR_PIDValid(_wPCR_PID);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_IsPCR_PIDValid_wPCR_PID_Equals_0x0005 */

/* CPPTEST_TEST_CASE_BEGIN test_IsPCR_PIDValid_wPCR_PID_Equals_0x0010 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsPCR_PIDValid(WORD) */
void TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_Equals_0x0010()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wPCR_PID) */ 
    WORD _wPCR_PID  = 0x0010;
    {
        /* Tested function call */
        BOOLEAN _return  = IsPCR_PIDValid(_wPCR_PID);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_IsPCR_PIDValid_wPCR_PID_Equals_0x0010 */

/* CPPTEST_TEST_CASE_BEGIN test_IsPCR_PIDValid_wPCR_PID_Equals_0x0200 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsPCR_PIDValid(WORD) */
void TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_Equals_0x0200()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wPCR_PID) */ 
    WORD _wPCR_PID  = 0x0200;
    {
        /* Tested function call */
        BOOLEAN _return  = IsPCR_PIDValid(_wPCR_PID);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_IsPCR_PIDValid_wPCR_PID_Equals_0x0200 */

/* CPPTEST_TEST_CASE_BEGIN test_IsPCR_PIDValid_wPCR_PID_Equals_0x1FFF */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsPCR_PIDValid(WORD) */
void TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_Equals_0x1FFF()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wPCR_PID) */ 
    WORD _wPCR_PID  = 0x1FFF;
    {
        /* Tested function call */
        BOOLEAN _return  = IsPCR_PIDValid(_wPCR_PID);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_IsPCR_PIDValid_wPCR_PID_Equals_0x1FFF */

/* CPPTEST_TEST_CASE_BEGIN test_IsPCR_PIDValid_wPCR_PID_GreaterThen_0x1FFF */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsPCR_PIDValid(WORD) */
void TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_GreaterThen_0x1FFF()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wPCR_PID) */ 
    WORD _wPCR_PID  = 0x2000;
    {
        /* Tested function call */
        BOOLEAN _return  = IsPCR_PIDValid(_wPCR_PID);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_IsPCR_PIDValid_wPCR_PID_GreaterThen_0x1FFF */

/* CPPTEST_TEST_CASE_BEGIN test_IsVideoPIDValid_wVideo_PID_LessThen_0x000F */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsVideoPIDValid(WORD) */
void TestSuite_msAPI_DTVSystem_test_IsVideoPIDValid_wVideo_PID_LessThen_0x000F()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wVideo_PID) */ 
    WORD _wVideo_PID  = 0x0001;
    {
        /* Tested function call */
        BOOLEAN _return  = IsVideoPIDValid(_wVideo_PID);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_IsVideoPIDValid_wVideo_PID_LessThen_0x000F */

/* CPPTEST_TEST_CASE_BEGIN test_IsVideoPIDValid_wVideo_PID_Equals_0x000F */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsVideoPIDValid(WORD) */
void TestSuite_msAPI_DTVSystem_test_IsVideoPIDValid_wVideo_PID_Equals_0x000F()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wVideo_PID) */ 
    WORD _wVideo_PID  = 0x000F;
    {
        /* Tested function call */
        BOOLEAN _return  = IsVideoPIDValid(_wVideo_PID);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_IsVideoPIDValid_wVideo_PID_Equals_0x000F */

/* CPPTEST_TEST_CASE_BEGIN test_IsVideoPIDValid_wVideo_PID_Equals_0x1000 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsVideoPIDValid(WORD) */
void TestSuite_msAPI_DTVSystem_test_IsVideoPIDValid_wVideo_PID_Equals_0x1000()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wVideo_PID) */ 
    WORD _wVideo_PID  = 0x1000;
    {
        /* Tested function call */
        BOOLEAN _return  = IsVideoPIDValid(_wVideo_PID);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_IsVideoPIDValid_wVideo_PID_Equals_0x1000 */

/* CPPTEST_TEST_CASE_BEGIN test_IsVideoPIDValid_wVideo_PID_Equals_0x1FFF */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsVideoPIDValid(WORD) */
void TestSuite_msAPI_DTVSystem_test_IsVideoPIDValid_wVideo_PID_Equals_0x1FFF()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wVideo_PID) */ 
    WORD _wVideo_PID  = 0x1FFF;
    {
        /* Tested function call */
        BOOLEAN _return  = IsVideoPIDValid(_wVideo_PID);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_IsVideoPIDValid_wVideo_PID_Equals_0x1FFF */

/* CPPTEST_TEST_CASE_BEGIN test_IsVideoPIDValid_wVideo_PID_GreaterThan_0x1FFF */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsVideoPIDValid(WORD) */
void TestSuite_msAPI_DTVSystem_test_IsVideoPIDValid_wVideo_PID_GreaterThan_0x1FFF()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wVideo_PID) */ 
    WORD _wVideo_PID  = 0x2000;
    {
        /* Tested function call */
        BOOLEAN _return  = IsVideoPIDValid(_wVideo_PID);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_IsVideoPIDValid_wVideo_PID_GreaterThan_0x1FFF */

/* CPPTEST_TEST_CASE_BEGIN test_IsPCR_PIDValid_wPCR_PID_Equals_0x0002 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsPCR_PIDValid(WORD) */
void TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_Equals_0x0002()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wPCR_PID) */ 
    WORD _wPCR_PID  = 0x0002;
    {
        /* Tested function call */
        BOOLEAN _return  = IsPCR_PIDValid(_wPCR_PID);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_IsPCR_PIDValid_wPCR_PID_Equals_0x0002 */

/* CPPTEST_TEST_CASE_BEGIN test_IsPCR_PIDValid_wPCR_PID_Equals_0x000F */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsPCR_PIDValid(WORD) */
void TestSuite_msAPI_DTVSystem_test_IsPCR_PIDValid_wPCR_PID_Equals_0x000F()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wPCR_PID) */ 
    WORD _wPCR_PID  = 0x000F;
    {
        /* Tested function call */
        BOOLEAN _return  = IsPCR_PIDValid(_wPCR_PID);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_IsPCR_PIDValid_wPCR_PID_Equals_0x000F */

/* CPPTEST_TEST_CASE_BEGIN test_IsVideoPIDValid_wVideo_PID_Equals_0x0010 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsVideoPIDValid(WORD) */
void TestSuite_msAPI_DTVSystem_test_IsVideoPIDValid_wVideo_PID_Equals_0x0010()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wVideo_PID) */ 
    WORD _wVideo_PID  = 0x0010;
    {
        /* Tested function call */
        BOOLEAN _return  = IsVideoPIDValid(_wVideo_PID);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_IsVideoPIDValid_wVideo_PID_Equals_0x0010 */

/* CPPTEST_TEST_CASE_BEGIN test_IsVideoPIDValid_wVideo_PID_Equals_0x1FFE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN IsVideoPIDValid(WORD) */
void TestSuite_msAPI_DTVSystem_test_IsVideoPIDValid_wVideo_PID_Equals_0x1FFE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wVideo_PID) */ 
    WORD _wVideo_PID  = 0x1FFE;
    {
        /* Tested function call */
        BOOLEAN _return  = IsVideoPIDValid(_wVideo_PID);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_IsVideoPIDValid_wVideo_PID_Equals_0x1FFE */

#define ENABLE_ASTRA_HD_UT 0

#if(ENABLE_ASTRA_HD_UT)

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CM_SaveServiceListInfo_if */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_CM_SaveServiceListInfo(const U8 *, U16, BOOLEAN) */
void TestSuite_msAPI_DTVSystem_test_msAPI_CM_SaveServiceListInfo_if()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Dest) */ 
	U8 pu8Dest[MAX_SERVICE_LIST_NAME] = {0};
    const U8 * _pu8Dest  = pu8Dest ;
    /* Initializing argument 2 (u16ServiceListID) */ 
    U16 _u16ServiceListID  = 1u;
    /* Initializing argument 3 (bListInFlag) */ 
    U8 _bListInFlag  = 1;
    {
        /* Tested function call */
    	BOOLEAN _return0 = msAPI_CM_ResetServiceListInfoData(_bListInFlag);
        BOOLEAN _return1  = msAPI_CM_SaveServiceListInfo(_pu8Dest,_u16ServiceListID,_bListInFlag);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return0 ));
        CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return1 ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CM_SaveServiceListInfo_if */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CM_GetCurrentServiceListID */
/* CPPTEST_TEST_CASE_CONTEXT U16 msAPI_CM_GetCurrentServiceListID(void) */
void TestSuite_msAPI_DTVSystem_test_msAPI_CM_GetCurrentServiceListID()
{
    /* Pre-condition initialization */
	U16 u16ServiceListID = 0u;
    {
        /* Tested function call */
        U16 _return  = msAPI_CM_GetCurrentServiceListID();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL( u16ServiceListID,( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CM_GetCurrentServiceListID */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CM_GetExistServiceListInfo */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_CM_GetExistServiceListInfo(const U16, BOOLEAN) */
void TestSuite_msAPI_DTVSystem_test_msAPI_CM_GetExistServiceListInfo()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16ServiceListID) */ 
    U16 _u16ServiceListID  = 0u;
    /* Initializing argument 2 (bListInFlag) */ 
    U8 _bListInFlag  = 1;
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_CM_GetExistServiceListInfo(_u16ServiceListID, _bListInFlag);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(0,( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CM_GetExistServiceListInfo */
#endif



/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CM_CountProgram_ServiceTypeInvalid */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CM_CountProgram(MEMBER_SERVICETYPE, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY) */
void TestSuite_msAPI_DTVSystem_test_msAPI_CM_CountProgram_ServiceTypeInvalid()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_ATV;
    /* Initializing argument 2 (eBoundary) */ 
    E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY _eBoundary  = 0x00; //E_PROGACESS_INCLUDE_VISIBLE_ONLY;
    {
        /* Tested function call */
        WORD _return  = msAPI_CM_CountProgram(_bServiceType, _eBoundary);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CM_CountProgram_ServiceTypeInvalid */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CM_CountProgram_Visible_Only */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CM_CountProgram(MEMBER_SERVICETYPE, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY) */
void TestSuite_msAPI_DTVSystem_test_msAPI_CM_CountProgram_Visible_Only()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_ATV;
    /* Initializing argument 2 (eBoundary) */ 
    E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY _eBoundary  = 0x00; //E_PROGACESS_INCLUDE_VISIBLE_ONLY;
    {
        /* Tested function call */
        WORD _return  = msAPI_CM_CountProgram(_bServiceType, _eBoundary);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(35, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CM_CountProgram_Visible_Only */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CM_CountProgram_Not_Visible_Also */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CM_CountProgram(MEMBER_SERVICETYPE, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY) */
void TestSuite_msAPI_DTVSystem_test_msAPI_CM_CountProgram_Not_Visible_Also()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_ATV;
    /* Initializing argument 2 (eBoundary) */ 
    E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY _eBoundary  = 0x01; //E_PROGACESS_INCLUDE_NOT_VISIBLE_ALSO;
    {
        /* Tested function call */
        WORD _return  = msAPI_CM_CountProgram(_bServiceType, _eBoundary);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(45, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CM_CountProgram_Not_Visible_Also */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CM_CountProgram_All */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CM_CountProgram(MEMBER_SERVICETYPE, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY) */
void TestSuite_msAPI_DTVSystem_test_msAPI_CM_CountProgram_All()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_ATV;
    /* Initializing argument 2 (eBoundary) */ 
    E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY _eBoundary  = 0x02; //E_PROGACESS_INCLUDE_ALL;
    {
        /* Tested function call */
        WORD _return  = msAPI_CM_CountProgram(_bServiceType, _eBoundary);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(55, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CM_CountProgram_All */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CM_CountProgram_Other */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CM_CountProgram(MEMBER_SERVICETYPE, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY) */
void TestSuite_msAPI_DTVSystem_test_msAPI_CM_CountProgram_Other()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_ATV;
    /* Initializing argument 2 (eBoundary) */ 
    E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY _eBoundary  = 0xFF;
    {
        /* Tested function call */
        WORD _return  = msAPI_CM_CountProgram(_bServiceType, _eBoundary);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CM_CountProgram_Other */
