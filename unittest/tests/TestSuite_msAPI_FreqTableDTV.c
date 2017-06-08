#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/msAPI_FreqTableDTV.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/msAPI_FreqTableDTV.c");

CPPTEST_TEST_SUITE(TestSuite_msAPI_FreqTableDTV);
CPPTEST_TEST(TestSuite_msAPI_FreqTableDTV_test_GetVHFBandWidth_eCountry_Not_Norway);
CPPTEST_TEST(TestSuite_msAPI_FreqTableDTV_test_GetVHFBandWidth_eCountry_NORWAY_u8Terr_BandWidth_Equals_BAND_8MHz);
CPPTEST_TEST(TestSuite_msAPI_FreqTableDTV_test_GetVHFBandWidth_eCountry_NORWAY_u8Terr_BandWidth_Equals_BAND_7MHz);
CPPTEST_TEST(TestSuite_msAPI_FreqTableDTV_test_GetVHFBandWidth_eCountry_UK);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_msAPI_FreqTableDTV_test_GetVHFBandWidth_eCountry_Not_Norway();
void TestSuite_msAPI_FreqTableDTV_test_GetVHFBandWidth_eCountry_NORWAY_u8Terr_BandWidth_Equals_BAND_8MHz();
void TestSuite_msAPI_FreqTableDTV_test_GetVHFBandWidth_eCountry_NORWAY_u8Terr_BandWidth_Equals_BAND_7MHz();
void TestSuite_msAPI_FreqTableDTV_test_GetVHFBandWidth_eCountry_UK();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_msAPI_FreqTableDTV);

void TestSuite_msAPI_FreqTableDTV_setUp()
{
}

void TestSuite_msAPI_FreqTableDTV_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_GetVHFBandWidth_eCountry_Not_Norway */
/* CPPTEST_TEST_CASE_CONTEXT RF_CHANNEL_BANDWIDTH GetVHFBandWidth(MEMBER_COUNTRY) */
void TestSuite_msAPI_FreqTableDTV_test_GetVHFBandWidth_eCountry_Not_Norway()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eCountry) */ 
    MEMBER_COUNTRY _eCountry  = E_COUNTRY_MIN;
    /* Initializing global variable _u8Terr_BandWidth */ 
    {
         _u8Terr_BandWidth  = 0;
    }
    {
        /* Tested function call */
        RF_CHANNEL_BANDWIDTH _return  = GetVHFBandWidth(_eCountry);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_RF_CH_BAND_7MHz, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_GetVHFBandWidth_eCountry_Not_Norway */

/* CPPTEST_TEST_CASE_BEGIN test_GetVHFBandWidth_eCountry_NORWAY_u8Terr_BandWidth_Equals_BAND_8MHz */
/* CPPTEST_TEST_CASE_CONTEXT RF_CHANNEL_BANDWIDTH GetVHFBandWidth(MEMBER_COUNTRY) */
void TestSuite_msAPI_FreqTableDTV_test_GetVHFBandWidth_eCountry_NORWAY_u8Terr_BandWidth_Equals_BAND_8MHz()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eCountry) */ 
    MEMBER_COUNTRY _eCountry  = E_NORWAY;
    /* Initializing global variable _u8Terr_BandWidth */ 
    {
         _u8Terr_BandWidth  = E_RF_CH_BAND_8MHz;
    }
    {
        /* Tested function call */
        RF_CHANNEL_BANDWIDTH _return  = GetVHFBandWidth(_eCountry);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_RF_CH_BAND_8MHz, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_GetVHFBandWidth_eCountry_NORWAY_u8Terr_BandWidth_Equals_BAND_8MHz */

/* CPPTEST_TEST_CASE_BEGIN test_GetVHFBandWidth_eCountry_NORWAY_u8Terr_BandWidth_Equals_BAND_7MHz */
/* CPPTEST_TEST_CASE_CONTEXT RF_CHANNEL_BANDWIDTH GetVHFBandWidth(MEMBER_COUNTRY) */
void TestSuite_msAPI_FreqTableDTV_test_GetVHFBandWidth_eCountry_NORWAY_u8Terr_BandWidth_Equals_BAND_7MHz()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eCountry) */ 
    MEMBER_COUNTRY _eCountry  = E_NORWAY;
    /* Initializing global variable _u8Terr_BandWidth */ 
    {
         _u8Terr_BandWidth  = E_RF_CH_BAND_7MHz;
    }
    {
        /* Tested function call */
        RF_CHANNEL_BANDWIDTH _return  = GetVHFBandWidth(_eCountry);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_RF_CH_BAND_7MHz, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_GetVHFBandWidth_eCountry_NORWAY_u8Terr_BandWidth_Equals_BAND_7MHz */

/* CPPTEST_TEST_CASE_BEGIN test_GetVHFBandWidth_eCountry_UK */
/* CPPTEST_TEST_CASE_CONTEXT RF_CHANNEL_BANDWIDTH GetVHFBandWidth(MEMBER_COUNTRY) */
void TestSuite_msAPI_FreqTableDTV_test_GetVHFBandWidth_eCountry_UK()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eCountry) */ 
    MEMBER_COUNTRY _eCountry  = E_UK;
    /* Initializing global variable _u8Terr_BandWidth */ 
    {
         _u8Terr_BandWidth  = 0;
    }
    {
        /* Tested function call */
        RF_CHANNEL_BANDWIDTH _return  = GetVHFBandWidth(_eCountry);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_RF_CH_BAND_7MHz, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_GetVHFBandWidth_eCountry_UK */
