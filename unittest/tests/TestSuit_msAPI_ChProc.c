#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/msAPI_ChProc.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/msAPI_ChProc.c");

CPPTEST_TEST_SUITE(TestSuit_msAPI_ChProc);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetCurrentOrdinal_E_SERVICETYPE_UNITED_TV_ifyes_ifyes);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetCurrentOrdinal_E_SERVICETYPE_RADIO_ifyes);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_RADIO_if);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_ifno);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_ATV);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV_elif1);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV_elif2);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV_else);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV_break);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_default);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_CountProgram_E_SERVICETYPE_DTV);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_CountProgram_E_SERVICETYPE_ATV);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_CountProgram_E_SERVICETYPE_UNITED_TV);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_CountProgram_default);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetNextOrdinal_E_SERVICETYPE_DTV);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetNextOrdinal_E_SERVICETYPE_ATV);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetPrevOrdinal_E_SERVICETYPE_DTV_ifyes);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetPrevOrdinal_E_SERVICETYPE_ATV);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_CountFavoriteProgram_E_SERVICETYPE_DTV);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_CountFavoriteProgram_default);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetFirstFavoriteOrdinal_E_SERVICETYPE_DTV);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetFirstFavoriteOrdinal_E_SERVICETYPE_UNITED_TV);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetFirstFavoriteOrdinal_E_SERVICETYPE_UNITED_ATV);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetFirstFavoriteOrdinal_default);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetLastFavoriteOrdinal_E_SERVICETYPE_DTV);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetLastFavoriteOrdinal_E_SERVICETYPE_ATV);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetLastFavoriteOrdinal_E_SERVICETYPE_UNITED_TV);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetLastFavoriteOrdinal_default);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetNextFavoriteOrdinal_E_SERVICETYPE_DTV);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetNextFavoriteOrdinal_E_SERVICETYPE_ATV);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetNextFavoriteOrdinal_E_SERVICETYPE_UNITED_TV);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetNextFavoriteOrdinal_default);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetPrevFavoriteOrdinal_E_SERVICETYPE_DTV);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetPrevFavoriteOrdinal_E_SERVICETYPE_ATV);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetPrevFavoriteOrdinal_E_SERVICETYPE_UNITED_TV);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetPrevFavoriteOrdinal_default);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetMatchedOrdinals_ifE_SERVICETYPE_ATV);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test__GetPrevFavoriteOrdinalOfUnitedTV_ifyes);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test__GetPrevFavoriteOrdinalOfUnitedTV_elif2);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test__GetPrevFavoriteOrdinalOfUnitedTV_elif3);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test__GetPrevFavoriteOrdinalOfUnitedTV_else);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test__GetNextFavoriteOrdinalOfUnitedTV_ifyes);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test__GetNextFavoriteOrdinalOfUnitedTV_elif1);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test__GetNextFavoriteOrdinalOfUnitedTV_elif2);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test__GetNextFavoriteOrdinalOfUnitedTV_else);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetAttributeOfOrdinal_E_SERVICE_ATTR_TYPE__E_SERVICETYPE_UNITED_TV_ifyes);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetAttributeOfOrdinal_E_SERVICE_ATTR_NUMBER__E_SERVICETYPE_DTV);
CPPTEST_TEST(TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetAttributeOfOrdinal_E_SERVICE_ATTR_NUMBER__E_SERVICETYPE_ATV);
CPPTEST_TEST_SUITE_END();
        

void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetCurrentOrdinal_E_SERVICETYPE_UNITED_TV_ifyes_ifyes();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetCurrentOrdinal_E_SERVICETYPE_RADIO_ifyes();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_RADIO_if();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_ifno();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_ATV();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV_elif1();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV_elif2();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV_else();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV_break();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_default();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_CountProgram_E_SERVICETYPE_DTV();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_CountProgram_E_SERVICETYPE_ATV();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_CountProgram_E_SERVICETYPE_UNITED_TV();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_CountProgram_default();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetNextOrdinal_E_SERVICETYPE_DTV();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetNextOrdinal_E_SERVICETYPE_ATV();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetPrevOrdinal_E_SERVICETYPE_DTV_ifyes();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetPrevOrdinal_E_SERVICETYPE_ATV();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_CountFavoriteProgram_E_SERVICETYPE_DTV();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_CountFavoriteProgram_default();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetFirstFavoriteOrdinal_E_SERVICETYPE_DTV();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetFirstFavoriteOrdinal_E_SERVICETYPE_UNITED_TV();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetFirstFavoriteOrdinal_E_SERVICETYPE_UNITED_ATV();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetFirstFavoriteOrdinal_default();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetLastFavoriteOrdinal_E_SERVICETYPE_DTV();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetLastFavoriteOrdinal_E_SERVICETYPE_ATV();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetLastFavoriteOrdinal_E_SERVICETYPE_UNITED_TV();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetLastFavoriteOrdinal_default();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetNextFavoriteOrdinal_E_SERVICETYPE_DTV();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetNextFavoriteOrdinal_E_SERVICETYPE_ATV();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetNextFavoriteOrdinal_E_SERVICETYPE_UNITED_TV();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetNextFavoriteOrdinal_default();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetPrevFavoriteOrdinal_E_SERVICETYPE_DTV();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetPrevFavoriteOrdinal_E_SERVICETYPE_ATV();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetPrevFavoriteOrdinal_E_SERVICETYPE_UNITED_TV();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetPrevFavoriteOrdinal_default();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetMatchedOrdinals_ifE_SERVICETYPE_ATV();
void TestSuit_msAPI_ChProc_test__GetPrevFavoriteOrdinalOfUnitedTV_ifyes();
void TestSuit_msAPI_ChProc_test__GetPrevFavoriteOrdinalOfUnitedTV_elif2();
void TestSuit_msAPI_ChProc_test__GetPrevFavoriteOrdinalOfUnitedTV_elif3();
void TestSuit_msAPI_ChProc_test__GetPrevFavoriteOrdinalOfUnitedTV_else();
void TestSuit_msAPI_ChProc_test__GetNextFavoriteOrdinalOfUnitedTV_ifyes();
void TestSuit_msAPI_ChProc_test__GetNextFavoriteOrdinalOfUnitedTV_elif1();
void TestSuit_msAPI_ChProc_test__GetNextFavoriteOrdinalOfUnitedTV_elif2();
void TestSuit_msAPI_ChProc_test__GetNextFavoriteOrdinalOfUnitedTV_else();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetAttributeOfOrdinal_E_SERVICE_ATTR_TYPE__E_SERVICETYPE_UNITED_TV_ifyes();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetAttributeOfOrdinal_E_SERVICE_ATTR_NUMBER__E_SERVICETYPE_DTV();
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetAttributeOfOrdinal_E_SERVICE_ATTR_NUMBER__E_SERVICETYPE_ATV();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuit_msAPI_ChProc);

void TestSuit_msAPI_ChProc_setUp()
{
}

void TestSuit_msAPI_ChProc_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_GetCurrentOrdinal_E_SERVICETYPE_UNITED_TV_ifyes_ifyes */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_GetCurrentOrdinal(MEMBER_SERVICETYPE, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetCurrentOrdinal_E_SERVICETYPE_UNITED_TV_ifyes_ifyes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_UNITED_TV;
    /* Initializing argument 2 (eBoundary) */ 
    E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY _eBoundary  = E_PROGACESS_INCLUDE_VISIBLE_ONLY;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_GetCurrentOrdinal(_bServiceType, _eBoundary);
        CPPTEST_ASSERT_EQUAL(INVALID_ORDINAL,(_return));
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_GetCurrentOrdinal_E_SERVICETYPE_UNITED_TV_ifyes_ifyes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_SetCurrentOrdinal_E_SERVICETYPE_RADIO_ifyes */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_CHPROC_CM_SetCurrentOrdinal(MEMBER_SERVICETYPE, WORD, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetCurrentOrdinal_E_SERVICETYPE_RADIO_ifyes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_ATV;
    /* Initializing argument 2 (wOrdinal) */ 
    WORD _wOrdinal  = 0u;
    /* Initializing argument 3 (eBoundary) */ 
    E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY _eBoundary  = E_PROGACESS_INCLUDE_VISIBLE_ONLY;
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_CHPROC_CM_SetCurrentOrdinal(_bServiceType, _wOrdinal, _eBoundary);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_SetCurrentOrdinal_E_SERVICETYPE_RADIO_ifyes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_RADIO_if */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_CHPROC_CM_SetMove2CurrentOrdinal(MEMBER_SERVICETYPE, WORD, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_RADIO_if()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_ATV;
    /* Initializing argument 2 (wOrdinal) */ 
    WORD _wOrdinal  = 0u;
    /* Initializing argument 3 (eBoundary) */ 
    E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY _eBoundary  = E_PROGACESS_INCLUDE_VISIBLE_ONLY;
    {
    	_bServiceType = E_SERVICETYPE_DTV;
        /* Tested function call */
        BOOLEAN _return  = msAPI_CHPROC_CM_SetMove2CurrentOrdinal(_bServiceType, _wOrdinal, _eBoundary);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL( TRUE, ( _return ) );
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_RADIO_if */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_ifno */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_CHPROC_CM_SetMove2CurrentOrdinal(MEMBER_SERVICETYPE, WORD, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_ifno()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_ATV;
    /* Initializing argument 2 (wOrdinal) */ 
    WORD _wOrdinal  = 2;
    /* Initializing argument 3 (eBoundary) */ 
    E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY _eBoundary  = E_PROGACESS_INCLUDE_VISIBLE_ONLY;
    {
        /* Tested function call */
    	_bServiceType  = E_SERVICETYPE_DTV;
        BOOLEAN _return  = msAPI_CHPROC_CM_SetMove2CurrentOrdinal(_bServiceType, _wOrdinal, _eBoundary);
        CPPTEST_ASSERT_BOOL_EQUAL( FALSE, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_ifno */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_ATV */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_CHPROC_CM_SetMove2CurrentOrdinal(MEMBER_SERVICETYPE, WORD, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_ATV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_ATV;
    /* Initializing argument 2 (wOrdinal) */ 
    WORD _wOrdinal  = 0u;
    /* Initializing argument 3 (eBoundary) */ 
    E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY _eBoundary  = E_PROGACESS_INCLUDE_VISIBLE_ONLY;
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_CHPROC_CM_SetMove2CurrentOrdinal(_bServiceType, _wOrdinal, _eBoundary);
        CPPTEST_ASSERT_BOOL_EQUAL( TRUE, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_ATV */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_CHPROC_CM_SetMove2CurrentOrdinal(MEMBER_SERVICETYPE, WORD, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_UNITED_TV;
    /* Initializing argument 2 (wOrdinal) */ 
    WORD _wOrdinal  = 0u;
    /* Initializing argument 3 (eBoundary) */ 
    E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY _eBoundary  = E_PROGACESS_INCLUDE_VISIBLE_ONLY;
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_CHPROC_CM_SetMove2CurrentOrdinal(_bServiceType, _wOrdinal, _eBoundary);
        CPPTEST_ASSERT_BOOL_EQUAL( TRUE, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV_elif1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_CHPROC_CM_SetMove2CurrentOrdinal(MEMBER_SERVICETYPE, WORD, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV_elif1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_UNITED_TV;
    /* Initializing argument 2 (wOrdinal) */ 
    WORD _wOrdinal  = 1u;
    /* Initializing argument 3 (eBoundary) */ 
    E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY _eBoundary  = E_PROGACESS_INCLUDE_VISIBLE_ONLY;
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_CHPROC_CM_SetMove2CurrentOrdinal(_bServiceType, _wOrdinal, _eBoundary);
        CPPTEST_ASSERT_BOOL_EQUAL( TRUE, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV_elif1 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV_elif2 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_CHPROC_CM_SetMove2CurrentOrdinal(MEMBER_SERVICETYPE, WORD, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV_elif2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_UNITED_TV;
    /* Initializing argument 2 (wOrdinal) */ 
    WORD _wOrdinal  = 2u;
    /* Initializing argument 3 (eBoundary) */ 
    E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY _eBoundary  = E_PROGACESS_INCLUDE_VISIBLE_ONLY;
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_CHPROC_CM_SetMove2CurrentOrdinal(_bServiceType, _wOrdinal, _eBoundary);
        CPPTEST_ASSERT_BOOL_EQUAL( TRUE, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV_elif2 */


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV_else */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_CHPROC_CM_SetMove2CurrentOrdinal(MEMBER_SERVICETYPE, WORD, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV_else()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_UNITED_TV;
    /* Initializing argument 2 (wOrdinal) */ 
    WORD _wOrdinal  = 3u;
    /* Initializing argument 3 (eBoundary) */ 
    E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY _eBoundary  = E_PROGACESS_INCLUDE_VISIBLE_ONLY;
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_CHPROC_CM_SetMove2CurrentOrdinal(_bServiceType, _wOrdinal, _eBoundary);
        CPPTEST_ASSERT_BOOL_EQUAL( TRUE, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV_else */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV_break */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_CHPROC_CM_SetMove2CurrentOrdinal(MEMBER_SERVICETYPE, WORD, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV_break()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_UNITED_TV;
    /* Initializing argument 2 (wOrdinal) */ 
    WORD _wOrdinal  = 4u;
    /* Initializing argument 3 (eBoundary) */ 
    E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY _eBoundary  = E_PROGACESS_INCLUDE_VISIBLE_ONLY;
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_CHPROC_CM_SetMove2CurrentOrdinal(_bServiceType, _wOrdinal, _eBoundary);
        CPPTEST_ASSERT_BOOL_EQUAL( TRUE, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV_break */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_default */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_CHPROC_CM_SetMove2CurrentOrdinal(MEMBER_SERVICETYPE, WORD, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_default()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_INVALID;
    /* Initializing argument 2 (wOrdinal) */ 
    WORD _wOrdinal  = 0u;
    /* Initializing argument 3 (eBoundary) */ 
    E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY _eBoundary  = E_PROGACESS_INCLUDE_VISIBLE_ONLY;
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_CHPROC_CM_SetMove2CurrentOrdinal(_bServiceType, _wOrdinal, _eBoundary);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_default */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_CountProgram_E_SERVICETYPE_DTV */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_CountProgram(MEMBER_SERVICETYPE, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_CountProgram_E_SERVICETYPE_DTV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_DTV;
    /* Initializing argument 2 (eBoundary) */ 
    E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY _eBoundary  = E_PROGACESS_INCLUDE_VISIBLE_ONLY;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_CountProgram(_bServiceType, _eBoundary);
        CPPTEST_ASSERT_BOOL_EQUAL( 1, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_CountProgram_E_SERVICETYPE_DTV */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_CountProgram_E_SERVICETYPE_ATV */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_CountProgram(MEMBER_SERVICETYPE, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_CountProgram_E_SERVICETYPE_ATV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_ATV;
    /* Initializing argument 2 (eBoundary) */ 
    E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY _eBoundary  = E_PROGACESS_INCLUDE_VISIBLE_ONLY;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_CountProgram(_bServiceType, _eBoundary);
        CPPTEST_ASSERT_BOOL_EQUAL( 0, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_CountProgram_E_SERVICETYPE_ATV */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_CountProgram_E_SERVICETYPE_UNITED_TV */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_CountProgram(MEMBER_SERVICETYPE, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_CountProgram_E_SERVICETYPE_UNITED_TV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_UNITED_TV;
    /* Initializing argument 2 (eBoundary) */ 
    E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY _eBoundary  = E_PROGACESS_INCLUDE_VISIBLE_ONLY;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_CountProgram(_bServiceType, _eBoundary);
        CPPTEST_ASSERT_BOOL_EQUAL( 4, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_CountProgram_E_SERVICETYPE_UNITED_TV */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_CountProgram_default */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_CountProgram(MEMBER_SERVICETYPE, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_CountProgram_default()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_INVALID;
    /* Initializing argument 2 (eBoundary) */ 
    E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY _eBoundary  = E_PROGACESS_INCLUDE_VISIBLE_ONLY;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_CountProgram(_bServiceType, _eBoundary);
        CPPTEST_ASSERT_BOOL_EQUAL( 0, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_CountProgram_default */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_GetNextOrdinal_E_SERVICETYPE_DTV */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_GetNextOrdinal(MEMBER_SERVICETYPE, WORD, BOOLEAN) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetNextOrdinal_E_SERVICETYPE_DTV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_DTV;
    /* Initializing argument 2 (wBaseOrdinal) */ 
    WORD _wBaseOrdinal  = 0u;
    /* Initializing argument 3 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_GetNextOrdinal(_bServiceType, _wBaseOrdinal, _bIncludeSkipped);
        CPPTEST_ASSERT_BOOL_EQUAL( INVALID_ORDINAL, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_GetNextOrdinal_E_SERVICETYPE_DTV */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_GetNextOrdinal_E_SERVICETYPE_ATV */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_GetNextOrdinal(MEMBER_SERVICETYPE, WORD, BOOLEAN) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetNextOrdinal_E_SERVICETYPE_ATV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_ATV;
    /* Initializing argument 2 (wBaseOrdinal) */ 
    WORD _wBaseOrdinal  = 0u;
    /* Initializing argument 3 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_GetNextOrdinal(_bServiceType, _wBaseOrdinal, _bIncludeSkipped);
        CPPTEST_ASSERT_BOOL_EQUAL( INVALID_ORDINAL, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_GetNextOrdinal_E_SERVICETYPE_ATV */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_GetPrevOrdinal_E_SERVICETYPE_DTV_ifyes */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_GetPrevOrdinal(MEMBER_SERVICETYPE, WORD, BOOLEAN) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetPrevOrdinal_E_SERVICETYPE_DTV_ifyes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_DTV;
    /* Initializing argument 2 (wBaseOrdinal) */ 
    WORD _wBaseOrdinal  = 0u;
    /* Initializing argument 3 (bIncludeSkipped) */
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_GetPrevOrdinal(_bServiceType, _wBaseOrdinal, _bIncludeSkipped);
        CPPTEST_ASSERT_BOOL_EQUAL( INVALID_ORDINAL, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_GetPrevOrdinal_E_SERVICETYPE_DTV_ifyes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_GetPrevOrdinal_E_SERVICETYPE_ATV */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_GetPrevOrdinal(MEMBER_SERVICETYPE, WORD, BOOLEAN) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetPrevOrdinal_E_SERVICETYPE_ATV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_ATV;
    /* Initializing argument 2 (wBaseOrdinal) */ 
    WORD _wBaseOrdinal  = 0u;
    /* Initializing argument 3 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_GetPrevOrdinal(_bServiceType, _wBaseOrdinal, _bIncludeSkipped);
        CPPTEST_ASSERT_BOOL_EQUAL( INVALID_ORDINAL, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_GetPrevOrdinal_E_SERVICETYPE_ATV */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_CountFavoriteProgram_E_SERVICETYPE_DTV */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_CountFavoriteProgram(MEMBER_SERVICETYPE) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_CountFavoriteProgram_E_SERVICETYPE_DTV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_ATV;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_CountFavoriteProgram(_bServiceType);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_CountFavoriteProgram_E_SERVICETYPE_DTV */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_CountFavoriteProgram_default */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_CountFavoriteProgram(MEMBER_SERVICETYPE) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_CountFavoriteProgram_default()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_INVALID;// E_SERVICETYPE_INVALID
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_CountFavoriteProgram(_bServiceType);
        CPPTEST_ASSERT_BOOL_EQUAL( FALSE, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_CountFavoriteProgram_default */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_GetFirstFavoriteOrdinal_E_SERVICETYPE_DTV */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_GetFirstFavoriteOrdinal(MEMBER_SERVICETYPE, BOOLEAN) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetFirstFavoriteOrdinal_E_SERVICETYPE_DTV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_DTV;
    /* Initializing argument 2 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_GetFirstFavoriteOrdinal(_bServiceType, _bIncludeSkipped);
        CPPTEST_ASSERT_BOOL_EQUAL( 0, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_GetFirstFavoriteOrdinal_E_SERVICETYPE_DTV */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_GetFirstFavoriteOrdinal_E_SERVICETYPE_UNITED_TV */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_GetFirstFavoriteOrdinal(MEMBER_SERVICETYPE, BOOLEAN) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetFirstFavoriteOrdinal_E_SERVICETYPE_UNITED_TV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_UNITED_TV;
    /* Initializing argument 2 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 1;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_GetFirstFavoriteOrdinal(_bServiceType, _bIncludeSkipped);
        CPPTEST_ASSERT_BOOL_EQUAL( 0, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_GetFirstFavoriteOrdinal_E_SERVICETYPE_UNITED_TV */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_GetFirstFavoriteOrdinal_E_SERVICETYPE_UNITED_ATV */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_GetFirstFavoriteOrdinal(MEMBER_SERVICETYPE, BOOLEAN) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetFirstFavoriteOrdinal_E_SERVICETYPE_UNITED_ATV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_ATV;
    /* Initializing argument 2 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_GetFirstFavoriteOrdinal(_bServiceType, _bIncludeSkipped);
        CPPTEST_ASSERT_BOOL_EQUAL( 0, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_GetFirstFavoriteOrdinal_E_SERVICETYPE_UNITED_ATV */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_GetFirstFavoriteOrdinal_default */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_GetFirstFavoriteOrdinal(MEMBER_SERVICETYPE, BOOLEAN) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetFirstFavoriteOrdinal_default()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_INVALID;
    /* Initializing argument 2 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_GetFirstFavoriteOrdinal(_bServiceType, _bIncludeSkipped);
        CPPTEST_ASSERT_BOOL_EQUAL( INVALID_ORDINAL, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_GetFirstFavoriteOrdinal_default */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_GetLastFavoriteOrdinal_E_SERVICETYPE_DTV */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_GetLastFavoriteOrdinal(MEMBER_SERVICETYPE, BOOLEAN) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetLastFavoriteOrdinal_E_SERVICETYPE_DTV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_DTV;
    /* Initializing argument 2 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_GetLastFavoriteOrdinal(_bServiceType, _bIncludeSkipped);
        CPPTEST_ASSERT_BOOL_EQUAL( 0, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_GetLastFavoriteOrdinal_E_SERVICETYPE_DTV */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_GetLastFavoriteOrdinal_E_SERVICETYPE_ATV */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_GetLastFavoriteOrdinal(MEMBER_SERVICETYPE, BOOLEAN) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetLastFavoriteOrdinal_E_SERVICETYPE_ATV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_ATV;
    /* Initializing argument 2 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_GetLastFavoriteOrdinal(_bServiceType, _bIncludeSkipped);
        CPPTEST_ASSERT_BOOL_EQUAL( 0, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_GetLastFavoriteOrdinal_E_SERVICETYPE_ATV */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_GetLastFavoriteOrdinal_E_SERVICETYPE_UNITED_TV */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_GetLastFavoriteOrdinal(MEMBER_SERVICETYPE, BOOLEAN) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetLastFavoriteOrdinal_E_SERVICETYPE_UNITED_TV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_UNITED_TV;
    /* Initializing argument 2 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_GetLastFavoriteOrdinal(_bServiceType, _bIncludeSkipped);
        CPPTEST_ASSERT_BOOL_EQUAL( 0xFFFF, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_GetLastFavoriteOrdinal_E_SERVICETYPE_UNITED_TV */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_GetLastFavoriteOrdinal_default */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_GetLastFavoriteOrdinal(MEMBER_SERVICETYPE, BOOLEAN) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetLastFavoriteOrdinal_default()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_INVALID;
    /* Initializing argument 2 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_GetLastFavoriteOrdinal(_bServiceType, _bIncludeSkipped);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL( INVALID_ORDINAL, ( _return ) );

        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_GetLastFavoriteOrdinal_default */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_GetNextFavoriteOrdinal_E_SERVICETYPE_DTV */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_GetNextFavoriteOrdinal(MEMBER_SERVICETYPE, WORD, BOOLEAN) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetNextFavoriteOrdinal_E_SERVICETYPE_DTV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_DTV;
    /* Initializing argument 2 (wBaseOrdinal) */ 
    WORD _wBaseOrdinal  = 0u;
    /* Initializing argument 3 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_GetNextFavoriteOrdinal(_bServiceType, _wBaseOrdinal, _bIncludeSkipped);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL( INVALID_ORDINAL, ( _return ) );
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_GetNextFavoriteOrdinal_E_SERVICETYPE_DTV */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_GetNextFavoriteOrdinal_E_SERVICETYPE_ATV */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_GetNextFavoriteOrdinal(MEMBER_SERVICETYPE, WORD, BOOLEAN) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetNextFavoriteOrdinal_E_SERVICETYPE_ATV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_ATV;
    /* Initializing argument 2 (wBaseOrdinal) */ 
    WORD _wBaseOrdinal  = 0u;
    /* Initializing argument 3 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_GetNextFavoriteOrdinal(_bServiceType, _wBaseOrdinal, _bIncludeSkipped);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL( INVALID_ORDINAL, ( _return ) );
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_GetNextFavoriteOrdinal_E_SERVICETYPE_ATV */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_GetNextFavoriteOrdinal_E_SERVICETYPE_UNITED_TV */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_GetNextFavoriteOrdinal(MEMBER_SERVICETYPE, WORD, BOOLEAN) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetNextFavoriteOrdinal_E_SERVICETYPE_UNITED_TV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_UNITED_TV;
    /* Initializing argument 2 (wBaseOrdinal) */ 
    WORD _wBaseOrdinal  = 0u;
    /* Initializing argument 3 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_GetNextFavoriteOrdinal(_bServiceType, _wBaseOrdinal, _bIncludeSkipped);
        CPPTEST_ASSERT_BOOL_EQUAL( 0, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_GetNextFavoriteOrdinal_E_SERVICETYPE_UNITED_TV */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_GetNextFavoriteOrdinal_default */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_GetNextFavoriteOrdinal(MEMBER_SERVICETYPE, WORD, BOOLEAN) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetNextFavoriteOrdinal_default()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_INVALID;
    /* Initializing argument 2 (wBaseOrdinal) */ 
    WORD _wBaseOrdinal  = 0u;
    /* Initializing argument 3 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_GetNextFavoriteOrdinal(_bServiceType, _wBaseOrdinal, _bIncludeSkipped);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_GetNextFavoriteOrdinal_default */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_GetPrevFavoriteOrdinal_E_SERVICETYPE_DTV */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_GetPrevFavoriteOrdinal(MEMBER_SERVICETYPE, WORD, BOOLEAN) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetPrevFavoriteOrdinal_E_SERVICETYPE_DTV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_DTV;
    /* Initializing argument 2 (wBaseOrdinal) */ 
    WORD _wBaseOrdinal  = 0u;
    /* Initializing argument 3 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_GetPrevFavoriteOrdinal(_bServiceType, _wBaseOrdinal, _bIncludeSkipped);
        CPPTEST_ASSERT_BOOL_EQUAL( INVALID_ORDINAL, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_GetPrevFavoriteOrdinal_E_SERVICETYPE_DTV */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_GetPrevFavoriteOrdinal_E_SERVICETYPE_ATV */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_GetPrevFavoriteOrdinal(MEMBER_SERVICETYPE, WORD, BOOLEAN) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetPrevFavoriteOrdinal_E_SERVICETYPE_ATV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_ATV;
    /* Initializing argument 2 (wBaseOrdinal) */ 
    WORD _wBaseOrdinal  = 0u;
    /* Initializing argument 3 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_GetPrevFavoriteOrdinal(_bServiceType, _wBaseOrdinal, _bIncludeSkipped);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL( INVALID_ORDINAL, ( _return ) );
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_GetPrevFavoriteOrdinal_E_SERVICETYPE_ATV */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_GetPrevFavoriteOrdinal_E_SERVICETYPE_UNITED_TV */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_GetPrevFavoriteOrdinal(MEMBER_SERVICETYPE, WORD, BOOLEAN) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetPrevFavoriteOrdinal_E_SERVICETYPE_UNITED_TV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_UNITED_TV;
    /* Initializing argument 2 (wBaseOrdinal) */ 
    WORD _wBaseOrdinal  = 0u;
    /* Initializing argument 3 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_GetPrevFavoriteOrdinal(_bServiceType, _wBaseOrdinal, _bIncludeSkipped);
        CPPTEST_ASSERT_BOOL_EQUAL( 0, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_GetPrevFavoriteOrdinal_E_SERVICETYPE_UNITED_TV */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_GetPrevFavoriteOrdinal_default */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_GetPrevFavoriteOrdinal(MEMBER_SERVICETYPE, WORD, BOOLEAN) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetPrevFavoriteOrdinal_default()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_INVALID;
    /* Initializing argument 2 (wBaseOrdinal) */ 
    WORD _wBaseOrdinal  = 0u;
    /* Initializing argument 3 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_GetPrevFavoriteOrdinal(_bServiceType, _wBaseOrdinal, _bIncludeSkipped);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL( INVALID_ORDINAL, ( _return ) );
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_GetPrevFavoriteOrdinal_default */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_GetMatchedOrdinals_ifE_SERVICETYPE_ATV */
/* CPPTEST_TEST_CASE_CONTEXT WORD msAPI_CHPROC_CM_GetMatchedOrdinals(MEMBER_SERVICETYPE, WORD) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetMatchedOrdinals_ifE_SERVICETYPE_ATV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_ATV;
    /* Initializing argument 2 (wPressedNumber) */ 
    WORD _wPressedNumber  = 0u;
    {
        /* Tested function call */
        WORD _return  = msAPI_CHPROC_CM_GetMatchedOrdinals(_bServiceType, _wPressedNumber);
        CPPTEST_ASSERT_BOOL_EQUAL( INVALID_ORDINAL, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_GetMatchedOrdinals_ifE_SERVICETYPE_ATV */

/* CPPTEST_TEST_CASE_BEGIN test__GetPrevFavoriteOrdinalOfUnitedTV_ifyes */
/* CPPTEST_TEST_CASE_CONTEXT WORD _GetPrevFavoriteOrdinalOfUnitedTV(WORD, BOOLEAN) */
void TestSuit_msAPI_ChProc_test__GetPrevFavoriteOrdinalOfUnitedTV_ifyes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wBaseOrdinal) */ 
    WORD _wBaseOrdinal  = 0u;
    /* Initializing argument 2 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = _GetPrevFavoriteOrdinalOfUnitedTV(_wBaseOrdinal, _bIncludeSkipped);
        CPPTEST_ASSERT_BOOL_EQUAL( INVALID_ORDINAL, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__GetPrevFavoriteOrdinalOfUnitedTV_ifyes */

/* CPPTEST_TEST_CASE_BEGIN test__GetPrevFavoriteOrdinalOfUnitedTV_elif2 */
/* CPPTEST_TEST_CASE_CONTEXT WORD _GetPrevFavoriteOrdinalOfUnitedTV(WORD, BOOLEAN) */
void TestSuit_msAPI_ChProc_test__GetPrevFavoriteOrdinalOfUnitedTV_elif2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wBaseOrdinal) */ 
    WORD _wBaseOrdinal  = 1u;
    /* Initializing argument 2 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = _GetPrevFavoriteOrdinalOfUnitedTV(_wBaseOrdinal, _bIncludeSkipped);
        CPPTEST_ASSERT_BOOL_EQUAL( INVALID_ORDINAL, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__GetPrevFavoriteOrdinalOfUnitedTV_elif2 */

/* CPPTEST_TEST_CASE_BEGIN test__GetPrevFavoriteOrdinalOfUnitedTV_elif3 */
/* CPPTEST_TEST_CASE_CONTEXT WORD _GetPrevFavoriteOrdinalOfUnitedTV(WORD, BOOLEAN) */
void TestSuit_msAPI_ChProc_test__GetPrevFavoriteOrdinalOfUnitedTV_elif3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wBaseOrdinal) */ 
    WORD _wBaseOrdinal  = 2u;
    /* Initializing argument 2 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = _GetPrevFavoriteOrdinalOfUnitedTV(_wBaseOrdinal, _bIncludeSkipped);
        CPPTEST_ASSERT_BOOL_EQUAL( INVALID_ORDINAL, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__GetPrevFavoriteOrdinalOfUnitedTV_elif3 */

/* CPPTEST_TEST_CASE_BEGIN test__GetPrevFavoriteOrdinalOfUnitedTV_else */
/* CPPTEST_TEST_CASE_CONTEXT WORD _GetPrevFavoriteOrdinalOfUnitedTV(WORD, BOOLEAN) */
void TestSuit_msAPI_ChProc_test__GetPrevFavoriteOrdinalOfUnitedTV_else()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wBaseOrdinal) */ 
    WORD _wBaseOrdinal  = 10u;
    /* Initializing argument 2 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = _GetPrevFavoriteOrdinalOfUnitedTV(_wBaseOrdinal, _bIncludeSkipped);
        CPPTEST_ASSERT_BOOL_EQUAL( INVALID_ORDINAL, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__GetPrevFavoriteOrdinalOfUnitedTV_else */

/* CPPTEST_TEST_CASE_BEGIN test__GetNextFavoriteOrdinalOfUnitedTV_ifyes */
/* CPPTEST_TEST_CASE_CONTEXT WORD _GetNextFavoriteOrdinalOfUnitedTV(WORD, BOOLEAN) */
void TestSuit_msAPI_ChProc_test__GetNextFavoriteOrdinalOfUnitedTV_ifyes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wBaseOrdinal) */ 
    WORD _wBaseOrdinal  = 0u;
    /* Initializing argument 2 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = _GetNextFavoriteOrdinalOfUnitedTV(_wBaseOrdinal, _bIncludeSkipped);
        CPPTEST_ASSERT_BOOL_EQUAL( INVALID_ORDINAL, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__GetNextFavoriteOrdinalOfUnitedTV_ifyes */

/* CPPTEST_TEST_CASE_BEGIN test__GetNextFavoriteOrdinalOfUnitedTV_elif1 */
/* CPPTEST_TEST_CASE_CONTEXT WORD _GetNextFavoriteOrdinalOfUnitedTV(WORD, BOOLEAN) */
void TestSuit_msAPI_ChProc_test__GetNextFavoriteOrdinalOfUnitedTV_elif1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wBaseOrdinal) */ 
    WORD _wBaseOrdinal  = 1u;
    /* Initializing argument 2 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = _GetNextFavoriteOrdinalOfUnitedTV(_wBaseOrdinal, _bIncludeSkipped);
        CPPTEST_ASSERT_BOOL_EQUAL( INVALID_ORDINAL, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__GetNextFavoriteOrdinalOfUnitedTV_elif1 */

/* CPPTEST_TEST_CASE_BEGIN test__GetNextFavoriteOrdinalOfUnitedTV_elif2 */
/* CPPTEST_TEST_CASE_CONTEXT WORD _GetNextFavoriteOrdinalOfUnitedTV(WORD, BOOLEAN) */
void TestSuit_msAPI_ChProc_test__GetNextFavoriteOrdinalOfUnitedTV_elif2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wBaseOrdinal) */ 
    WORD _wBaseOrdinal  = 2u;
    /* Initializing argument 2 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = _GetNextFavoriteOrdinalOfUnitedTV(_wBaseOrdinal, _bIncludeSkipped);
        CPPTEST_ASSERT_BOOL_EQUAL( INVALID_ORDINAL, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__GetNextFavoriteOrdinalOfUnitedTV_elif2 */

/* CPPTEST_TEST_CASE_BEGIN test__GetNextFavoriteOrdinalOfUnitedTV_else */
/* CPPTEST_TEST_CASE_CONTEXT WORD _GetNextFavoriteOrdinalOfUnitedTV(WORD, BOOLEAN) */
void TestSuit_msAPI_ChProc_test__GetNextFavoriteOrdinalOfUnitedTV_else()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (wBaseOrdinal) */ 
    WORD _wBaseOrdinal  = 10u;
    /* Initializing argument 2 (bIncludeSkipped) */ 
    U8 _bIncludeSkipped  = 0;
    {
        /* Tested function call */
        WORD _return  = _GetNextFavoriteOrdinalOfUnitedTV(_wBaseOrdinal, _bIncludeSkipped);
        CPPTEST_ASSERT_BOOL_EQUAL( INVALID_ORDINAL, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("WORD _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test__GetNextFavoriteOrdinalOfUnitedTV_else */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_GetAttributeOfOrdinal_E_SERVICE_ATTR_TYPE__E_SERVICETYPE_UNITED_TV_ifyes */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_CHPROC_CM_GetAttributeOfOrdinal(MEMBER_SERVICETYPE, WORD, BYTE *, SERVICE_ATTRIBUTE_MEMBER, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetAttributeOfOrdinal_E_SERVICE_ATTR_TYPE__E_SERVICETYPE_UNITED_TV_ifyes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_ATV;
    /* Initializing argument 2 (wOrdinal) */ 
    WORD _wOrdinal  = 0u;
    /* Initializing argument 3 (pcBuffer) */ 
    BYTE byte;
    BYTE * _pcBuffer  = &byte ;
    /* Initializing argument 4 (eAttributeMember) */ 
    SERVICE_ATTRIBUTE_MEMBER _eAttributeMember  = E_SERVICE_ATTR_TYPE;
    /* Initializing argument 5 (eBoundary) */ 
    E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY _eBoundary  = E_PROGACESS_INCLUDE_VISIBLE_ONLY;
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_CHPROC_CM_GetAttributeOfOrdinal(_bServiceType, _wOrdinal, _pcBuffer, _eAttributeMember, _eBoundary);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL( TRUE, ( _return ) );
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("BYTE * _pcBuffer ", ( _pcBuffer ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_GetAttributeOfOrdinal_E_SERVICE_ATTR_TYPE__E_SERVICETYPE_UNITED_TV_ifyes */



/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_GetAttributeOfOrdinal_E_SERVICE_ATTR_NUMBER__E_SERVICETYPE_DTV */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_CHPROC_CM_GetAttributeOfOrdinal(MEMBER_SERVICETYPE, WORD, BYTE *, SERVICE_ATTRIBUTE_MEMBER, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetAttributeOfOrdinal_E_SERVICE_ATTR_NUMBER__E_SERVICETYPE_DTV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_DTV;
    /* Initializing argument 2 (wOrdinal) */ 
    WORD _wOrdinal  = 0u;
    /* Initializing argument 3 (pcBuffer) */ 
    BYTE byte;
    BYTE * _pcBuffer  = &byte ;
    /* Initializing argument 4 (eAttributeMember) */ 
    SERVICE_ATTRIBUTE_MEMBER _eAttributeMember  = E_SERVICE_ATTR_NUMBER;
    /* Initializing argument 5 (eBoundary) */ 
    E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY _eBoundary  = E_PROGACESS_INCLUDE_VISIBLE_ONLY;
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_CHPROC_CM_GetAttributeOfOrdinal(_bServiceType, _wOrdinal, _pcBuffer, _eAttributeMember, _eBoundary);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL( TRUE, ( _return ) );
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("BYTE * _pcBuffer ", ( _pcBuffer ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_GetAttributeOfOrdinal_E_SERVICE_ATTR_NUMBER__E_SERVICETYPE_DTV */


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_CHPROC_CM_GetAttributeOfOrdinal_E_SERVICE_ATTR_NUMBER__E_SERVICETYPE_ATV */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_CHPROC_CM_GetAttributeOfOrdinal(MEMBER_SERVICETYPE, WORD, BYTE *, SERVICE_ATTRIBUTE_MEMBER, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY) */
void TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetAttributeOfOrdinal_E_SERVICE_ATTR_NUMBER__E_SERVICETYPE_ATV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bServiceType) */ 
    MEMBER_SERVICETYPE _bServiceType  = E_SERVICETYPE_ATV;
    /* Initializing argument 2 (wOrdinal) */ 
    WORD _wOrdinal  = 0u;
    /* Initializing argument 3 (pcBuffer) */ 
    BYTE byte;
    BYTE * _pcBuffer  = &byte ;
    /* Initializing argument 4 (eAttributeMember) */ 
    SERVICE_ATTRIBUTE_MEMBER _eAttributeMember  = E_SERVICE_ATTR_NUMBER;
    /* Initializing argument 5 (eBoundary) */ 
    E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY _eBoundary  = E_PROGACESS_INCLUDE_VISIBLE_ONLY;
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_CHPROC_CM_GetAttributeOfOrdinal(_bServiceType, _wOrdinal, _pcBuffer, _eAttributeMember, _eBoundary);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL( TRUE, ( _return ) );
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("BYTE * _pcBuffer ", ( _pcBuffer ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_CHPROC_CM_GetAttributeOfOrdinal_E_SERVICE_ATTR_NUMBER__E_SERVICETYPE_ATV */
